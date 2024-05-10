
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


extern "C" {
JBClassPlace( ProcessOwner,   JB_PID_UnRegister,     JB_AsClass(JB_Object),      0 );
}


#ifndef AS_LIBRARY
#include <string>
#include <iostream>


extern "C" {
const int RD = 0; const int WR = 1;
JBClassPlace( ShellStream,    JB_Sh_Destructor,      JB_AsClass(ProcessOwner),   0 );


void JB_Rec__NewErrorWithNode (Message* node, JB_String* Desc, JB_Object* Source);
bool JB_Dup2 (int, int);


JB_String* JB_App__Readline() {
    std::string L;
    if (std::getline(std::cin, L))
        return JB_Str_CopyFromPtr((uint8*)L.c_str(), (int)L.length());
    return JB_Str__Error();
}

static void pipe_close (int& fd) {
	if (fd > 0) {
		close(fd);
		fd = -1;
	}
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


bool CanASMBKPT = true;
int JB_Pipe__IgnoreBreakPoints() {
	CanASMBKPT = false;
	int rz = sigignore(SIGINT);
	if (rz)
		rz = errno;
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


const char** JB_Proc__CreateArgs(JB_String* self, Array* R) {
	int N = JB_Array_Size(R);
	int Strs = JB_Str_Length(self) + 1;

	for_(N) 
		Strs += JB_Str_Length((JB_String*)JB_Array_Value(R, i)) + 1;

	if (Strs >= ARG_MAX-1) {
		JB_ErrorHandleFile(self, nil, E2BIG, "Arguments too long", "Creating shell-arguments");
		return 0;
	}

	int Ptrs = sizeof(void*) * (N+2);
	const char** PtrSpace = (const char**)calloc(Ptrs + Strs, 1);
	char* ByteSpace = ((char*)PtrSpace) + Ptrs;
	auto Orig = PtrSpace; char* Orig2 = ByteSpace;
	
	for_(N+1) {
		auto B = (const char*)JB_Str_Address(self);
		auto N = (int)JB_Str_Length(self);
		*PtrSpace++ = ByteSpace;
		memcpy(ByteSpace, B, N);
		ByteSpace += N+1;
		self = (JB_String*)JB_Array_Value(R, i);
	}
	PtrSpace++;
	
	if ((char*)PtrSpace != Orig2) // ouch
		debugger;
    return Orig;
}


int JB_Kill(int PID) {
	return kill(PID, SIGKILL);
}


extern "C" bool JB_Dup2(int from, int to) { // so this kinda does what dup2 should do.
	while (from > 0 and dup2(from, to) == -1) {
		int err = errno;
		if (err != EINTR and err != EBUSY)	
			return false;
	}
	return true;
}


static void Unblock (int fd) {
	if (fd < 0) return;
	int FL = fcntl(fd, F_GETFL, 0);
	if (FL!=-1)
		fcntl(fd, F_SETFL, FL | O_NONBLOCK);
}


static bool PIDDied_ (ShellStream* Sh) {
	return kill(Sh->PID, 0) != 0; // this kill function actually doesnt fucking work. FUCK UNIX!
								  // it is breaking it's own guidelines! As usual!
}


static void CheckStillAlive (ShellStream* Sh) {
	if (Sh->_Exit == -1 and PIDDied_(Sh)) {
		int Exit = 0;
		int PID = waitpid(-1, &Exit, WNOHANG);
		if (PID>0) {
			Sh->_Exit = Exit;
		} else {
			Sh->_Exit = 0;
		}
		
		Sh->_Status = 0;
		JB_PID_UnRegister(Sh); // actually the spdprocess checker does a lot more work than this.
	}
}


bool JB_Sh_StartProcess(ShellStream* self, JB_String* path, Array* Args, PicoComms* C, bool CaptureStdOut) {
// fcntl,Fork,execvp,Pipe,Dup2,Waitid,Errno,Close,Eintr,_exit // unix simplicity :)
	auto& Sh = *self; auto sh = self;
	auto argv = JB_Proc__CreateArgs(path, Args);
	if (!argv) return false;
	
	if (CaptureStdOut or Sh.Output)
		pipe(Sh.CaptureOut);
	pipe(Sh.CaptureErr);
	Unblock(Sh.CaptureErr[RD]); // should never block
	Unblock(Sh.CaptureOut[RD]); // even this blocking at all is kinda sus...
	
	JB_PID_Register(&Sh);
	int PID = PicoStartFork(C, true);
	bool OK = true;

	if (PID == 0) {
		JB_Dup2( Sh.CaptureOut[WR], STDOUT_FILENO );
		pipe_close(Sh.CaptureOut[WR]);
		pipe_close(Sh.CaptureOut[RD]);
		
		JB_Dup2( Sh.CaptureErr[WR], STDERR_FILENO );
		pipe_close(Sh.CaptureErr[WR]);
		pipe_close(Sh.CaptureErr[RD]);
		execvp(argv[0], (char* const*)argv);
		_exit(errno-!errno); // in case execvp fails
		return false;
	} else if (PID > 0) {
		sh->_Exit = -1;
		sh->_Status = 0;
		Sh.PID = PID;
		pipe_close(Sh.CaptureOut[WR]);
		pipe_close(Sh.CaptureErr[WR]);
		CheckStillAlive(sh);
	} else {
		OK = false;
		JB_ErrorHandleFile(path, nil, errno, nil, "run");
	}

	JB_FreeIfDead(path);
	free(argv);
	return OK;
}


int JB_Sh_UpdatePipes(ShellStream* self) {
	auto& Sh = *self;
	CheckStillAlive(self);
	int ContinueOut = JB_FS_AppendPipe(Sh.Output, Sh.CaptureOut[RD], 1);
	// this will only return, once the app has finished... unless we are Streaming.
	// either way, if both return false, we can finish.
	int ContinueErr = JB_FS_AppendPipe(Sh.ErrorOutput, Sh.CaptureErr[RD], 1);
	return ContinueOut | ContinueErr;
}


void JB_Sh_ClosePipes(ShellStream* self) {
	for (int i = 0; i < 4; i++) {
		pipe_close(self->CaptureOut[i]);
	}
	self->IsClosed = true;
}


int JB_Str_System(JB_String* self) { // needz escape params manually...
    uint8 Buffer[PATH_MAX];
    uint8* Result = JB_FastCString(self, Buffer, PATH_MAX);
    int ugh = system((const char*)Result);
    return WEXITSTATUS(ugh);
}


void JB_FEPDWEE_Finish(ShellStream& Sh) {
	pipe_close(Sh.CaptureOut[RD]);
	pipe_close(Sh.CaptureErr[RD]);
	Sh.IsClosed = true;
}


ShellStream* ShellStart(JB_String* self, Array* Args, FastString* FSOut, FastString* FSErrIn, bool StdOutFlowThru) {
	auto rz = JB_Sh_Constructor(0, self);
	rz->Output = JB_Incr(FSOut);
	rz->ErrorOutput = JB_Incr(JB_FS__FastNew(FSErrIn));
	rz->Params = JB_Incr(Args);
	bool OK = JB_Sh_StartProcess(rz, self, Args, 0, !StdOutFlowThru);
	if (!OK) {
		JB_SetRef(rz, 0);
	}
	return rz;
}


ivec2 JB_Str_Execute (JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn, bool StdOutFlowThru, Date TimeOut) {
	auto Sh = ShellStart(self, R, FSOut, FSErrIn, StdOutFlowThru);
	if (!Sh) return ivec2{1, 0};
	
	Date ExitAfter = 0;
	if (TimeOut > 0)
		ExitAfter = JB_Date__Now() + TimeOut;

	while (true) {
		bool DidAnything = JB_Sh_UpdatePipes(Sh) & 2;
		if (JB_PID_Exit(Sh) != -1  or  JB_PID_Status(Sh) != 0)
			break;
		if (TimeOut > 0) {
			auto Now = JB_Date__Now();
			if (DidAnything)
				ExitAfter = Now + TimeOut;
			  else if (Now >= ExitAfter)
				break;
		}
		JB_Date__Sleep(1);
	}

	JB_Sh_UpdatePipes(Sh);
	JB_FEPDWEE_Finish(*Sh);

	auto ShErr = Sh->ErrorOutput;
	if (!FSErrIn and JB_FS_Length(ShErr)) {
		JB_Rec__NewErrorWithNode(nil, JB_FS_GetResult(ShErr), nil);
	}
	
	int Signal = Sh->_Status;
	int Exit = Sh->_Exit;
	JB_FreeIfDead(Sh);
	if (Signal)			// died from a signal // usually its what we want, despite being mixed up
		JB_ErrorHandleFile(self, nil, Signal, "crashed", "running");
	return ivec2{Exit, Signal}; // ivec2 specifier needed for linux
}


ShellStream* JB_Sh__Stream(JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn) {
	return ShellStart(self, R, FSOut, FSErrIn, FSOut==nil);
}


///*(^&£^/ Shellstream vvvvv >>>>>>>

ShellStream* JB_Sh_Constructor(ShellStream* self, JB_String* Path) {
	JB_New2(ShellStream);
	*self = {};
	JB_PID_Constructor(self);
	for (int i = 0; i < 4; i++)
		self->CaptureOut[i] = -1;
	
	self->IsClosed = false;
	self->Path = JB_Incr(Path);
	return self;
}


void JB_Sh_Destructor(ShellStream* self) {
	ShellStream& Sh = *self;
	JB_FEPDWEE_Finish(Sh);
	JB_Decr(Sh.ErrorOutput);
	JB_Decr(Sh.Path);
	JB_Decr(Sh.Output);
	JB_Decr(Sh.Params);
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
	if (!Sh.IsClosed) {
		Smooth_(Sh);
		if (JB_Sh_UpdatePipes(self)&1)
			return true;
		JB_FEPDWEE_Finish(Sh);
	}
	return false;
}



void JB_App__TurnInto(JB_String* self, Array* R) {
	auto argv = JB_Proc__CreateArgs(JB_Str_MakeC(self), R);
	execvp(argv[0], (char* const*)argv);
	exit(-1);	// in case execvp fails
}



bool JB_IsTerminal(int FD) {
    return isatty(FD);
}

}

#else

extern "C" void JB_CrashTracer() {}

#endif

extern "C" const char** JB_App__BackTrace(void** space, int* size) {
    *size = backtrace( space, *size );
    return (const char**)backtrace_symbols( space, *size );
}

