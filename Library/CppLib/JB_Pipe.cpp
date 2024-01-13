
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

static void pipe_close (int fd) {
	if (fd > 0)
		close(fd);
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


static bool pipe_dup2(int from, int to) { // so this kinda does what dup2 should do.
	if (to <= 0)
		return true;
	while (true) {
		int res = dup2(from, to);
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


bool JB_Str__Terminate(Array* strs) {
	int n = JB_Array_Size(strs);
	for_(n) {
		JB_String* A = (JB_String*)JB_Array_Value(strs, i);
		auto B = JB_Str_MakeC(A);
		require (B);
		if (B != A) {
			JB_Array_ValueSet(strs, i, B);
		}
	};
	return true;
}


bool JB_Proc__CreateArgs(JB_String** self, Array* R, const char** argv) {
	auto last = argv + MaxArgs - 1;
	int N = JB_Array_Size(R);
	if (argv+1+N >= last) {
		JB_ErrorHandleFile(*self, nil, E2BIG, "Too many arguments", "Creating shell-arguments");
		return false;
	}
	
	JB_String* self0 = JB_Str_MakeC(*self);
	require(self0 and JB_Str__Terminate(R));
	JB_SetRef(*self, self0);
	
	*argv++ = (const char*)JB_Str_Address(self0);
	for_(N) {
		*argv++ = ((const char*)JB_Str_Address((JB_StringC*)JB_Array_Value(R, i)));
	}
	*argv++ = 0;
    return true;
}


int JB_Kill(int PID) {
	return kill(PID, SIGKILL);
}


bool JB_Sh_StartProcess(ShellStream* self, JB_String* path, Array* Args, PicoComms* C, bool CaptureStdOut) {
// fcntl,Fork,execvp,Pipe,Dup2,Waitid,Errno,Close,Eintr // unix simplicity :)
	auto& Sh = *self;
	const char* argv[MaxArgs] = {};
	bool OK = JB_Proc__CreateArgs(&path, Args, argv);
	if (!OK) return false;
	
	Sh.ExitCode = -1;
	if (CaptureStdOut or Sh.Output)
		pipe(Sh.CaptureOut);
	pipe(Sh.StdErrPipe);
	if (Sh.Mode == 1) {	// 1 means... no block. So we wanna restore it.
		if (Sh.CaptureOut[RD])
			fcntl(Sh.CaptureOut[RD], F_SETFL, O_NONBLOCK);
		fcntl(Sh.StdErrPipe[RD], F_SETFL, O_NONBLOCK);
	}
	JB_PID_Register(&Sh);
	Sh.PID = PicoStartFork(C, 987);
	
	if (Sh.PID == 0) {
		pipe_dup2( STDOUT_FILENO, Sh.CaptureOut[WR] );
		pipe_close(Sh.CaptureOut[WR]);
		pipe_close(Sh.CaptureOut[RD]);
		
		pipe_dup2( STDERR_FILENO, Sh.StdErrPipe[WR] );
		pipe_close(Sh.StdErrPipe[WR]);
		pipe_close(Sh.StdErrPipe[RD]);
		execvp(argv[0], (char* const*)argv);
		_exit(errno); // in case execvp fails
		return false;
	}
	JB_FreeIfDead(path);
	if (Sh.PID > 0) {
		pipe_close(Sh.CaptureOut[WR]);
		pipe_close(Sh.StdErrPipe[WR]);
		return true;
	}
	JB_ErrorHandleFile(path, nil, errno, nil, "run");
	return false;
}


bool JB_Sh_UpdatePipes(ShellStream* self) {
	auto& Sh = *self;
	bool ContinueOut = JB_FS_AppendPipe(Sh.Output, Sh.CaptureOut[RD], Sh.Mode);
	// this will only return, once the app has finished... unless we are Streaming.
	// either way, if both return false, we can finish.
	bool ContinueErr = JB_FS_AppendPipe(Sh.ErrorOutput, Sh.StdErrPipe[RD], Sh.Mode);
	return (ContinueOut or ContinueErr);
}

void JB_Sh_ClosePipes(ShellStream* self) {
	for (int i = 0; i < 4; i++) {
		pipe_close(self->CaptureOut[i]);
		self->CaptureOut[i] = 0;
	}
	self->Mode = -1;
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


ShellStream* ShellStart(JB_String* self, Array* Args, FastString* FSOut, FastString* FSErrIn, bool StdOutFlowThru) {
	auto rz = JB_New(ShellStream);
	JB_Sh_Constructor(rz, self);
	rz->Output = JB_Incr(FSOut);
	rz->ErrorOutput = JB_Incr(JB_FS__FastNew(FSErrIn));
	bool OK = JB_Sh_StartProcess(rz, self, Args, 0, !StdOutFlowThru);
	if (!OK) {
		JB_SetRef(rz, 0);
	}
	return rz;
}


ivec2 JB_Str_Execute(JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn, bool StdOutFlowThru) {
	auto Sh = ShellStart(self, R, FSOut, FSErrIn, StdOutFlowThru);
	if (!Sh) {return ivec2{1,0};}
	
	JB_Sh_UpdatePipes(Sh);
	while (Sh->ExitCode==-1) {
		int Err = waitpid(Sh->PID,  &Sh->ExitCode,  0); // in case sigchld handler is overridden
		if (!(Err == -1 and errno == EINTR))
			break;
		JB_Date__Sleep(1);
		JB_Sh_UpdatePipes(Sh);
	}

	JB_Sh_UpdatePipes(Sh);
	JB_FEPDWEE_Finish(*Sh);

	auto ShErr = Sh->ErrorOutput;
	if (!FSErrIn and JB_FS_Length(ShErr)) {
		JB_Rec_NewErrorWithNode(JB_StdErr, nil, JB_FS_GetResult(ShErr), nil);
	}
	
	int Code = Sh->ExitCode;
	JB_FreeIfDead(Sh);
	int Signal = 0;
	int Exit = 0;
	if (WIFEXITED(Code)) {				// called exit()
		Exit = WEXITSTATUS(Code);
	}
	if (WIFSIGNALED(Code)) {			// died from a signal
		Signal = WTERMSIG(Code);		// usually its what we want, despite being mixed up
		JB_ErrorHandleFile(self, nil, Signal, "crashed", "running");
	} 
	return ivec2{Exit, Signal}; // ivec2 specifier needed for linux
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


static void Smooth_(ShellStream& Sh) {
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
		Smooth_(Sh);
		if (JB_Sh_UpdatePipes(self))
			return true;
		JB_FEPDWEE_Finish(Sh);
	}
	return false;
}



void JB_App__TurnInto(JB_String* self, Array* R) {
	const char* argv[MaxArgs + 1];
	JB_Proc__CreateArgs(&self, R, argv);
	execvp(argv[0], (char* const*)argv);
	exit(-1);	// in case execvp fails
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


