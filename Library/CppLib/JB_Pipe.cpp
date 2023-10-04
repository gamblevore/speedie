
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

#include <errno.h>
#include <sys/stat.h>

#include <pwd.h>
//#include <stdlib.h>
#include <sys/mman.h>


#if __linux__
	#include <sys/mman.h>
	#include <sys/sendfile.h>
	#include <linux/limits.h>
#endif


extern "C" const char** JB_BackTrace(void** space, int* size) {
    *size = backtrace( space, *size );
    return (const char**)backtrace_symbols( space, *size );
}



#ifndef AS_LIBRARY
#include <string>
#include <iostream>


extern "C" {
const int RD = 0; const int WR = 1;
JBClassPlace( ProcessOwner,   JB_PID_UnRegister,     JB_AsClass(JB_Object),      0 );
JBClassPlace( ShellStream,    JB_Sh_Destructor,      JB_AsClass(ProcessOwner),   0 );


void JB_Rec_NewErrorWithNode(JB_ErrorReceiver* self, Message* node, JB_String* Desc, JB_Object* Source);

const int MaxArgs = 256;

JB_String* JB_App__Readline() {
    std::string L;
    if (std::getline(std::cin, L))
        return JB_Str_CopyFromPtr((uint8*)L.c_str(), (int)L.length());
    return JB_Str__Error();
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


void JB_App__SetThreadName(JB_String* self) {
	require0(self);
	u8 CName[32];
	auto tmp = (const char*)JB_FastCString(self, CName, sizeof(CName));
	
	
#if __APPLE__
	pthread_setname_np(tmp); // why?
#else
	pthread_setname_np(pthread_self(), tmp);
#endif
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
	return kill(PID, SIGKILL);
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
	JB_PID_Register(&Sh);
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
	execvp(argv[0], (char* const*)argv);
	_exit(errno); // in case execvp fails
}


static bool JB_FEPDWEE_Middle(ShellStream& Sh) {
	bool ContinueOut = JB_FS_AppendPipe(Sh.Output, Sh.CaptureOut[RD], Sh.Mode);
	// this will only return, once the app has finished... unless we are Streaming.
	// either way, if both return false, we can finish.
	bool ContinueErr = JB_FS_AppendPipe(Sh.ErrorOutput, Sh.StdErrPipe[RD], Sh.Mode);
	return (ContinueOut or ContinueErr);
}


int JB_Str_System(JB_String* self) { // needz escape params manually...
    uint8 Buffer[PATH_MAX];
    uint8* Result = JB_FastCString(self, Buffer, PATH_MAX);
    int ugh = system((const char*)Result);
    return WEXITSTATUS(ugh);
}


void JB_FEPDWEE_Finish(ShellStream& Sh) {
	pipe_close(Sh.CaptureOut[RD]);
	pipe_close(Sh.StdErrPipe[RD]);
	Sh.Mode = -1;
}


ShellStream* ShellStart(JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn, bool KeepStdOut) {
	auto rz = JB_New(ShellStream);
	JB_Sh_Constructor(rz, self);
	auto& Sh = *rz;
	Sh.Output = JB_Incr(FSOut);
	Sh.ErrorOutput = JB_Incr(JB_FS__FastNew(FSErrIn));

	const char* argv[MaxArgs + 1];
	int Err = JB_ArrayPrepare_(self, argv, R);
	if (!Err) {
		Err = JB_FEPDWEE_Call(Sh, argv, !KeepStdOut); // once this is called... we don't need argv anymore.
	}
	if ( Err) {
		JB_ErrorHandleFile(self, nil, Sh.Exit, nil, "call command-line tool");
		JB_SetRef(rz, 0);
	}
	return rz;
}


int JB_Str_Execute(JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn, bool KeepStdOut) {
	auto Sh = ShellStart(self, R, FSOut, FSErrIn, KeepStdOut);
	if (!Sh) {return 1;}
	JB_FEPDWEE_Middle(*Sh);
	
	while (Sh->Exit==-1) {
		int Err = waitpid(Sh->PID,  &Sh->Exit,  0); // in case sigchld handler is overridden
		if (!(Err == -1 and errno == EINTR)) {
			break;
		}
		JB_Date__Sleep(1);
	}

	JB_FEPDWEE_Middle(*Sh);
	JB_FEPDWEE_Finish(*Sh);
	int Exit = Sh->Exit;
	if (Sh->ErrorOutput->Length and !FSErrIn) {
		JB_Rec_NewErrorWithNode(JB_StdErr, nil, JB_FS_GetResult(Sh->ErrorOutput), nil);
		if (!Exit)
			Exit = 1; // generic error code
	}
	JB_FreeIfDead(Sh);
	return Exit;
}


ShellStream* JB_Sh__Stream(JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn) {
	return ShellStart(self, R, FSOut, FSErrIn, FSOut==nil);
}


///*(^&£^/ Shellstream vvvvv >>>>>>>

void JB_Sh_Constructor(ShellStream* self, JB_String* Path) {
	*self = {};
	JB_PID_Constructor(self);
	self->Mode = 1;
	self->Path = JB_Incr(Path);
}




void JB_Sh_Destructor(ShellStream* self) {
	ShellStream& Sh = *self;
	JB_FEPDWEE_Finish(Sh);
	JB_Decr(Sh.ErrorOutput);
	JB_Decr(Sh.Path);
	JB_Decr(Sh.Output);
	JB_PID_Destructor(self);
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


