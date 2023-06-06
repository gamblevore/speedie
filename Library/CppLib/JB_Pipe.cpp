
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.hpp"
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <execinfo.h>
#include <signal.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/wait.h>


extern "C" const char** JB_BackTrace(void** space, int* size) {
    *size = backtrace( space, *size );
    return (const char**)backtrace_symbols( space, *size );
}


#ifndef AS_LIBRARY
#include <string>
#include <iostream>
#define KillZombs 1


extern "C" {
const int RD = 0; const int WR = 1;
JBClassPlace( ShellStream,    JB_Sh_Destructor,      JB_AsClass(JB_Object),      0 );


void JB_Rec_NewErrorWithNode(JB_ErrorReceiver* self, Message* node, JB_String* Desc, JB_Object* Source);

const int MaxArgs = 256;
bool ChildClosed;
void JB_SigChild (int signum) {
	ChildClosed = true;
}
int JB_App__LostChild () {
    while (ChildClosed) {
		int pid = waitpid(-1, nil, WNOHANG);
		if (pid == 0)
			ChildClosed = 0;
		if (pid >= 0  or  errno != EINTR)
			return pid;
    }
    return -1;
}


JB_String* JB_App__Readline() {
    std::string L;
    if (std::getline(std::cin, L))
        return JB_Str_CopyFromPtr((uint8*)L.c_str(), (int)L.length());
    return 0;
}

static bool pipe_close (int fd) {
	if (fd <= 0) return true;
	while (close(fd) == -1)
		if (errno != EINTR)
			return false;
	return true;
}


void JB_App__AtExit (fn_app_deathaction b) {
	atexit(b);
}



typedef void* (*fn_pth_wrap2)(void* obj);

int JB_ThreadStart (fn_pth_wrap wrap, JB_Object* oof, bool join) {
	pthread_t thr = nil;
	int Err = pthread_create(&thr, nil, (fn_pth_wrap2)wrap, oof);

	if (!Err) {
		void* rz = 0;
		Err = join? pthread_join(thr, &rz) : pthread_detach(thr);
		if (!Err)
			return 0;
	}
	
	JB_ErrorHandleFile(nil, nil, Err, nil, "run pthread");
	return Err;
}


static bool pipe_dup2(int to, int from) { // so this kinda does what dup2 should do.
	if (to <= 0)
		return true;
	while (true) {
		int res = dup2(to, from);
		if (res != -1)
			return true;
		int err = errno;
		if (err != EINTR and err != EBUSY)	
			return false;
	}
}


int JB_SafeWait (int pid) {
	siginfo_t IWouldDoItSimpler = {};
	int WaitErr = 0;
	do {
		errno = 0;
		WaitErr = waitid(P_PID,  pid,  &IWouldDoItSimpler,  WEXITED|WSTOPPED);
	} while (WaitErr == -1 and errno == EINTR);
	if (!WaitErr)
		return IWouldDoItSimpler.si_status;
	return WaitErr;
}

bool CanASMBKPT = true;
int JB_Pipe__IgnoreBreakPoints() {
	CanASMBKPT = false;
	int rz = sigignore(SIGINT);
	if (rz)
		rz = errno;
	debugger;
	return rz;
}

const char* ArrayCStrOne_(JB_String* S, int& ugh) {
	if (!JB_Str_Length(S)) {return "";}
	if (JB_Str_IsC(S)) return (const char*)JB_Str_Address(S);
	JB_ErrorHandleFile(S, nil, EINVAL, "Speedie string not zero-terminated", "Executing shell-command");
	JB_Str_IsC(S); // for testing
	ugh = EINVAL;
	return 0;
}

void JB_Str__Terminate(Array* strs) {
	int n = JB_Array_Size(strs);
	for_(n) {
		JB_String* A = (JB_String*)JB_Array_Value(strs, i);
		JB_Array_ValueSet(strs, i, JB_Str_MakeC(A));
	};
}


int JB_ArrayPrepare_(JB_String* self, const char** argv, Array* R) {
	JB_Str__Terminate(R);
	errno	= 0;
	int Err = 0;
	auto last = argv + MaxArgs-1;
	*argv++ = ArrayCStrOne_(self, Err);
	
	int N = JB_Array_Size(R);
	if (argv+N >= last)
		return E2BIG;
	for_(N) {
		*argv++ = ArrayCStrOne_((JB_String*)JB_Array_Value(R, i), Err);
	}
	*argv++ = 0;
    return Err;
}


int JB_Kill(int PID) {
	int KillErr = kill(PID, SIGKILL);
	if (!KillErr)
		KillErr = JB_SafeWait(PID); // i could do better
	return KillErr;
}


const char* _StartProcess (JB_String* self, const char** argv, Array* Args, int* childpipe, int& PID) {
	if (!JB_Str_Length(self)) {
		return "received empty-path";
	}
	if (JB_ArrayPrepare_(self, argv, Args)) {
		return "prepare ipc";
	}
	int Err = access(argv[0], X_OK | F_OK);
	if (Err) return "access";

	if (childpipe) {
		if (pipe(childpipe)) return "pipe";
		fcntl(childpipe[0], F_SETFL, O_NONBLOCK);
	}

	signal(SIGCHLD, JB_SigChild);
	PID = fork();
	
	if (PID == -1)
		return "fork";
	if (PID) {		// parent
		if (childpipe)
			pipe_close(childpipe[1]);
		return 0;
	}
	
	// çhild
	if (childpipe) {
		pipe_dup2(childpipe[1], 1); // We can now capture stdout cleanly!
		pipe_close(childpipe[0]);
	}
	execvp(argv[0], 	(char* const*)argv);
	printf("execv(\"%s\") failed\n",  argv[0]);
	exit(-1);
}



int JB_Str_StartProcess (JB_String* self, Array* Args, JB_File** StdOut) {
	const char* argv[MaxArgs] = {};
    int Pipes[2] = {};
    int PID = 0;
	auto Err = _StartProcess(self, argv, Args, StdOut?Pipes:0, PID);
	if (Err) {
		JB_ErrorHandleFile(self, nil, errno, nil, Err); return -1;
	}
	if (StdOut) {
		JB_SetRef(*StdOut, JB_File__NewPipe(Pipes[0]));
	}
	return PID;
}


static int JB_FEPDWEE_Call(ShellStream& Sh, const char** argv, bool NewStdOut) {
// Fork,Exec,Pipe,Dup2,Waitid,Errno,Eintr // unix simplicity :)
	if (NewStdOut or Sh.Output)
		pipe(Sh.CaptureOut);
	pipe(Sh.StdErrPipe);
	if (Sh.Mode == 1) {	// 1 means... no block. So we wanna restore it.
		if (Sh.CaptureOut[RD])
			fcntl(Sh.CaptureOut[RD], F_SETFL, O_NONBLOCK);
		fcntl(Sh.StdErrPipe[RD], F_SETFL, O_NONBLOCK);
	}
	Sh.PID = fork();
	if (Sh.PID == -1) {
		return EPERM;
	}
	if (Sh.PID) {
		pipe_close(Sh.CaptureOut[WR]);
		pipe_close(Sh.StdErrPipe[WR]);
		return 0;
	}
	
	pipe_dup2( Sh.CaptureOut[WR], STDOUT_FILENO );
	pipe_close(Sh.CaptureOut[WR]);
	pipe_close(Sh.CaptureOut[RD]);
	
	pipe_dup2( Sh.StdErrPipe[WR], STDERR_FILENO );
	pipe_close(Sh.StdErrPipe[WR]);
	pipe_close(Sh.StdErrPipe[RD]);
	execvp(argv[0], (char* const*)argv);  _exit(errno); // in case execvp fails
}


static bool JB_FEPDWEE_Middle(ShellStream& Sh) {
	bool ContinueOut = JB_FS_AppendPipe(Sh.Output, Sh.CaptureOut[RD], Sh.Mode);
	// this will only return, once the app has finished... unless we are Streaming.
	// either way, if both return false, we can finish.
	bool ContinueErr = JB_FS_AppendPipe(Sh.StdErr, Sh.StdErrPipe[RD], Sh.Mode);
	return (ContinueOut or ContinueErr);
}


int JB_Str_System(JB_String* self) { // needz escape params manually...
    uint8 Buffer[1024];
    uint8* Result = JB_FastCString(self, Buffer);
    int ugh = system((const char*)Result);
    return WEXITSTATUS(ugh);
}


bool JB_FEPDWEE_Start(ShellStream* sh, Array* R, FastString* FSOut, FastString* FSErrIn, JB_String* self, bool KeepStdOut) {
	ShellStream& Sh = *sh;
	Sh.Output = FSOut;
	Sh.StdErr = JB_FS__FastNew(FSErrIn);

	const char* argv[MaxArgs + 1];
	Sh.Error = JB_ArrayPrepare_(self, argv, R);
	if (!Sh.Error)
		Sh.Error = JB_FEPDWEE_Call(Sh, argv, !KeepStdOut); // once this is called... we don't need argv anymore.
	if ( Sh.Error) {
		JB_ErrorHandleFile(self, nil, Sh.Error, nil, "call command-line tool");
		return false;
	}
	return true;
}

void JB_FEPDWEE_Finish(ShellStream& Sh) {
	Sh.Error = JB_SafeWait(Sh.PID); // this is jsut to get the... exit code.
	pipe_close(Sh.CaptureOut[RD]);
	pipe_close(Sh.StdErrPipe[RD]);
	Sh.Mode = -1;
}

int JB_FEPDWEE_Finish2(ShellStream& Sh, FastString* FSErrIn ) {
	JB_FEPDWEE_Finish(Sh);
	if (Sh.StdErr->Length and !FSErrIn) {
		JB_Rec_NewErrorWithNode(JB_StdErr, nil, JB_FS_GetResult(Sh.StdErr), nil);
	}
	return Sh.Error;
}

int JB_Str_Execute(JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn, bool KeepStdOut) {
// what if I just do this in terms of JB_Sh__New?
// like a busy-loop that calls .step until its finished
	ShellStream Sh = {};
	if (!JB_FEPDWEE_Start(&Sh, R, FSOut, FSErrIn, self, KeepStdOut))
		return Sh.Error;
	JB_FEPDWEE_Middle(Sh);
	return JB_FEPDWEE_Finish2(Sh, FSErrIn);
}

void JB_Sh_Constructor(ShellStream* self) {
	*self = {}; self->Mode = 1;
}

ShellStream* JB_Sh__New(JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn) {
	ShellStream Sh = {}; Sh.Mode = 1;
	require(JB_FEPDWEE_Start(&Sh, R, FSOut, FSErrIn, self, FSOut==nil));
	auto rz = JB_New(ShellStream);
	if (rz) {
		JB_Incr(Sh.StdErr);
		JB_Incr(Sh.Output);
		*rz = Sh;
	}
	return rz;
}

void JB_Sh_Destructor(ShellStream* self) {
	ShellStream& Sh = *self;
	JB_FEPDWEE_Finish(Sh);
	JB_Decr(Sh.StdErr);
	JB_Decr(Sh.Output);
}

static void Smooth(ShellStream& Sh) {
// or else certain apps will lock up.
// funnily enough, sleeping makes these apps run FASTER.
// probably by triggering the printf statements instead 
// of collecting them into one giant blob.
	Date L = Sh.LastRead;
	Date C = JB_Date__Now();
	if (L) {
		Date D = C - L;
		if (D < 4*1024) {
			JB_Date__Sleep(4096);
		}
	}
	Sh.LastRead = C;
}

bool JB_Sh_Step(ShellStream* self) {
	require (self);
	ShellStream& Sh = *self;
	if (Sh.Mode >= 0) {
		Smooth(Sh);
		if (JB_FEPDWEE_Middle(Sh))
			return true;
		JB_FEPDWEE_Finish(Sh);
	}
	return false;
}



int JB_App__TurnInto(JB_String* self, Array* R) {
	const char* argv[MaxArgs + 1];
	int Err			= JB_ArrayPrepare_(self, argv, R);
	if (!Err) {
		execvp(argv[0], (char* const*)argv); Err = errno;	// in case execvp fails
	}
	if (Err)
		JB_ErrorHandleFile(self, nil, Err, nil, "turninto");
	return Err;
}



bool JB_IsTerminal(int FD) {
    return isatty(FD);
}

}

#else

// stop linker errors.
extern "C" void Stub_JBPipe () {
    
}

extern "C" void JB_CrashTracer() {
}

#endif


