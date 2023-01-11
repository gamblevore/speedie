
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.hpp"
#include <stdio.h>

#ifndef AS_LIBRARY
#include <unistd.h>
#include <syslog.h>
#include <execinfo.h>
#include <signal.h>
#include <fcntl.h>
#include <poll.h>

#include <string>
#include <iostream>


#define KillZombs 1

extern "C" {
const int RD = 0; const int WR = 1;
JBClassPlace( ShellStreamer,    JB_Sh_Destructor,      JB_AsClass(JB_Object),      0 );


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


const char** JB_BackTrace(void** space, int* size) {
    *size = backtrace( space, *size );
    return (const char**)backtrace_symbols( space, *size );
}


void JB_PrintStackTrace() {
    void*   array[32];
    int size = 32;
    auto  strings = JB_BackTrace(array, &size);

    for_(size)
        puts( strings[i] );
    
    puts("");
    free( strings );
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


static bool pipe_dup2(int to, int from) {
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
int JB_Pipe__Ignore (int Signal) {
	if (Signal == -1) {
		Signal = SIGINT;
		CanASMBKPT = false;
	}
	int rz = sigignore(Signal);	//(SIGINT)
	if (rz)
		rz = errno;
	debugger;
	return rz;
		// OK... 
}

const char* ArrayCStrOne_(JB_String* S, int& ugh) {
	if (!JB_Str_Length(S)) {return "";}
	if (JB_Str_IsC(S)) return (const char*)JB_Str_Address(S);
	debugger;
	JB_ErrorHandleFile(S, nil, EINVAL, "Speedie string not zero-terminated", "Executing shell-command");
	ugh = EINVAL;
	return 0;
}


int JB_ArrayPrepare_(JB_String* self, const char** argv, Array* R) {
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


int JB_Str_StartIPC(JB_String* self, JB_String* talk, Array* Args) {
	signal(SIGCHLD, JB_SigChild);
	const char* argv[MaxArgs] = {};
	const char* cmd = "prepare ipc";
	int Err = JB_ArrayPrepare_(self, argv, Args);
	if (!Err) {
		cmd = "access";
		Err = access(argv[0], X_OK | F_OK);
		if (!Err) {
			cmd = "fork";
			int PID = fork();
			if (PID > 0) {
				return PID;
			}
			Err = PID;
		}
	} 
	if (Err < 0) {
		JB_ErrorHandleFile(self, nil, errno, nil, cmd);
		return Err;
	}
	
	execvp(argv[0], 	(char* const*)argv);
	printf("execv(\"%s\") failed\n",  argv[0]);
	exit(-1);
}



static int JB_FEPDWEE_Call(ShellStreamer& Sh, const char** argv, bool NewStdOut) {
// Fork,Exec,Pipe,Dup2,Waitid,Errno,Eintr // unix simplicity :)
	//puts("1");
	if (NewStdOut or Sh.FSOut)
		pipe(Sh.CaptureOut);
	  else
		debugger;
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


static bool JB_FEPDWEE_Middle(ShellStreamer& Sh) {
	bool ContinueOut = JB_FS_AppendPipe(Sh.FSOut, Sh.CaptureOut[RD], Sh.Mode);
	// this will only return, once the app has finished... unless we are Streaming.
	// either way, if both return false, we can finish.
	bool ContinueErr = JB_FS_AppendPipe(Sh.FSErr, Sh.StdErrPipe[RD], Sh.Mode);
	return (ContinueOut or ContinueErr);
}


int JB_Str_System(JB_String* self) { // needz escape params manually...
    uint8 Buffer[1024];
    uint8* Result = JB_FastCString(self, Buffer);
    int ugh = system((const char*)Result);
    return WEXITSTATUS(ugh);
}


bool JB_FEPDWEE_Start(ShellStreamer* sh, Array* R, FastString* FSOut, FastString* FSErrIn, JB_String* self, bool KeepStdOut) {
	ShellStreamer& Sh = *sh;
	Sh.FSOut = FSOut;
	Sh.FSErr = JB_FS__FastNew(FSErrIn);

	const char* argv[MaxArgs + 1];
	Sh.Err = JB_ArrayPrepare_(self, argv, R);
	if (!Sh.Err)
		Sh.Err = JB_FEPDWEE_Call(Sh, argv, !KeepStdOut); // once this is called... we don't need argv anymore.
	if ( Sh.Err) {
		JB_ErrorHandleFile(self, nil, Sh.Err, nil, "call command-line tool");
		return false;
	}
	return true;
}

void JB_FEPDWEE_Finish(ShellStreamer& Sh) {
	Sh.Err = JB_SafeWait(Sh.PID); // this is jsut to get the... exit code.
	pipe_close(Sh.CaptureOut[RD]);
	pipe_close(Sh.StdErrPipe[RD]);
	Sh.Mode = -1;
}

int JB_FEPDWEE_Finish2(ShellStreamer& Sh, FastString* FSErrIn ) {
	JB_FEPDWEE_Finish(Sh);
	if (Sh.FSErr->Length and !FSErrIn) {
		JB_Rec_NewErrorWithNode(JB_StdErr, nil, JB_FS_GetResult(Sh.FSErr), nil);
	}
	JB_SetRef(Sh.FSErr, nil);
	return Sh.Err;
}

int JB_Str_Execute(JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn, bool KeepStdOut) {
	ShellStreamer Sh = {};
	if (!JB_FEPDWEE_Start(&Sh, R, FSOut, FSErrIn, self, KeepStdOut))
		return Sh.Err;
	JB_FEPDWEE_Middle(Sh);
	return JB_FEPDWEE_Finish2(Sh, FSErrIn);
}

void JB_Sh_Constructor(ShellStreamer* self) {
	*self = {}; self->Mode = 1;
}

ShellStreamer* JB_Sh__New(JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn) {
	auto Sh = JB_New(ShellStreamer);
	JB_Sh_Constructor(Sh);
	if (!JB_FEPDWEE_Start(Sh, R, FSOut, FSErrIn, self, FSOut==nil)) {
		JB_FreeIfDead(Sh);
		return 0;
	}
	JB_Incr(Sh->FSErr);
	JB_Incr(Sh->FSOut);
	return Sh;
}

void JB_Sh_Destructor(ShellStreamer* self) {
	ShellStreamer& Sh = *self;
	JB_FEPDWEE_Finish(Sh);
	JB_Decr(Sh.FSErr);
	JB_Decr(Sh.FSOut);
}

static void Smooth(ShellStreamer& Sh) { // or else certain apps will lock up.
	Date L = Sh.Last;
	Date C = JB_Date__Now();
	if (L) {
		Date D = C - L;
		if (D < 4*1024) {
			JB_Date__Sleep(4096);
		}
	}
	Sh.Last = C;
}

bool JB_Sh_Step(ShellStreamer* self) {
	ShellStreamer& Sh = *self;
	if (Sh.Mode < 0) // finished
		return false;
	Smooth(Sh);
	if (JB_FEPDWEE_Middle(Sh))
		return true;
	JB_FEPDWEE_Finish(Sh);
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

extern "C" void JB_PrintStackTrace() {
}

#endif


