
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.hpp"
#include <execinfo.h>

extern "C" {
	JBClassPlace( ShellStream,    JB_Sh_Destructor,      JB_AsClass(JB_List),   0 );
}

#ifndef AS_LIBRARY
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <signal.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <pwd.h>
#include <sys/mman.h>
#include <string>
#include <iostream>

#if __linux__
	#include <sys/mman.h>
	#include <sys/sendfile.h>
	#include <linux/limits.h>
#endif

#define kOwnGroup		2
#define kStdOutPassThru 4
#define kStdOutSilence  8
#define kStdOutNil      12
#define kStdErrPassThru 16
#define kStdErrSilence  32
#define kStdErrNil      48



extern "C" {
const int RD = 0;   const int WR = 1;
ShellStream*		PSRoot;
std::atomic_int		SigChildOutStanding = 0x0000000 + 0000 -1*0; // FUCK UNIX
bool				CanASMBKPT = true;


void JB_App__SetASMBreak (bool b) {
	CanASMBKPT = b;
}


static void AddLostChild_ (int PID, int C) {
	ShellStream* F = (ShellStream*)JB_Ring_First(PSRoot);
	while (F) {
		if (F->PID == PID) {
			if (WIFSIGNALED(C))
				F->_Status = WTERMSIG(C)|128;
			  else
				F->_Status = WEXITSTATUS(C);
			return;
		}
		F = F->Next;
	}
}


void JB_SigChild (int signum) {
	SigChildOutStanding++;
}


int JB_Sh_Status (ShellStream* F) {
	while (SigChildOutStanding > 0) {
		while (true) {
			int ExitCode = 0;
			int PID = waitpid(-1, &ExitCode, WNOHANG);
			if (PID > 0) {
				AddLostChild_(PID, ExitCode);
				JB_Ring_ParentSet(F, nil);
			} else if (PID == 0 or errno != EINTR) {
				break;
			}
		}
		SigChildOutStanding--;
	}
	if (SigChildOutStanding < 0) // ?what?
		SigChildOutStanding = 0;
	return F->_Status;
}


void JB_KillChildrenOnExit () {
	ShellStream* F = PSRoot;
	while (F) {
		if (F->PID > 0 and F->KillOnExit)	// seems unused?
			kill(F->PID, SIGKILL);			// leave for now.
		F = F->Next;
	}
}
 
int JB_Sh_Kill (ShellStream* F, int Code) {
	F->_Status = Code;
	return JB_Kill(F->PID);
}

////*&(^!@^*& ^^^^^^^ PiD ^^^^^^^^
//// BATCHES LOST CONTROL

JB_StringC* JB_Err_SignalName (int Sig) {
	const char* S = "NormalExit";
	if (Sig) S = strsignal(Sig);
	return JB_StrC(S);
}

JB_StringC* JB_Err_Name (int Err) {
	return JB_StrC(strerror(Err));
}

int JB_Signal(int PID, int sig) {
	return kill(PID, sig);
}


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
	require0(JB_Str_Length(self));
	u8 CName[32];
	auto tmp = (const char*)JB_FastFileString(self, CName);
#if __APPLE__
	pthread_setname_np(tmp); // why?
#else
	pthread_setname_np(pthread_self(), tmp);
#endif
}


void JB_Flow__ReportStringData(u8* Addr, int Length, u8* Name, int NameLen);
#ifndef ARG_MAX
	#define ARG_MAX 128 * 1024
#endif
const char** JB_Proc__CreateArgs(JB_String* self, Array* R) {
	int N = JB_Array_Size(R);
	int Strs = JB_Str_Length(self) + 1;

	for_(N) 
		Strs += JB_Str_Length((JB_String*)JB_Array_Value(R, i)) + 1;

	if (Strs >= ARG_MAX-1) {
		JB_ErrorHandleFile(self, nil, E2BIG, "Arguments too long", "Creating shell-arguments");
		errno = E2BIG;
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
		self = nil;
		if (R)
			self = (JB_String*)JB_Array_Value(R, i);
	}
	PtrSpace++;
#ifndef AS_LIBRARY
	JB_Flow__ReportStringData((u8*)Orig2, (int)(ByteSpace-Orig2), (u8*)"pipe", 4);
#endif
	
	if ((char*)PtrSpace != Orig2) // ouch
		debugger;
    return Orig;
}


int JB_Kill(int PID) {
	if (PID <= 0)
		return -1;

	int ch_pg = getpgid(PID);
	int err = 0;
	if (getpgid(0) == ch_pg) // don't kill self!
		err = kill(PID, SIGKILL);
	  else
		err = killpg(ch_pg, SIGKILL); // better to kill entire group.
	return errno & err; // err will be -1 or 0
}


static bool Dup2_(int from, int to) { // so this kinda does what dup2 should do.
	while (from > 0 and dup2(from, to) == -1) {
		int err = errno;
		if (err != EINTR and err != EBUSY)	
			return false;
	}
	return true;
}


static void StartPico (PicoComms* M, int* Both) {
	if (M and (pipe(Both) == 0)) {
		int fd = Both[RD];
		int FL = fcntl(fd, F_GETFL, 0);
		if (FL>=0)
			fcntl(fd, F_SETFL, FL | O_NONBLOCK);
		PicoStartPipe(M, fd);
	}
}


static void CheckStillAlive (ShellStream* Sh) {
// kill() function unreliable. UNIX breaking it's own guidelines! As usual!
	require0 (Sh->_Status == -1  and  kill(Sh->PID, 0) != 0);
	if (JB_Sh_Status(Sh) < 0) // why?
		Sh->_Status = 0;
	JB_Ring_ParentSet(Sh, 0);
}


static void CloseAndDup (int Mode, int* Capture, int Mask, int Std_FileNo) {
	if (Mode&Mask) {
		close(Std_FileNo);
	} else {
		Dup2_( Capture[WR], Std_FileNo );
		pipe_close(Capture[WR]);
		pipe_close(Capture[RD]);
	}
}


int JB_Sh_StartProcess(ShellStream* S, PicoComms* C) {
// fcntl,Fork,execvp,Pipe,Dup2,Waitid,Errno,close,Eintr,_exit // far too much stuff in unix.
	auto argv = JB_Proc__CreateArgs(S->Path, S->Args);
	if (!argv) return E2BIG;
	
	int CaptureOut[2] = {-1,-1};
	int CaptureErr[2] = {-1,-1};
	StartPico(S->StdOut, CaptureOut);
	StartPico(S->StdErr, CaptureErr);
	
	int ChildID = PicoStartFork(C, true);
	if (ChildID == 0) {
		int Mode = S->Mode; // We are the child!
		if (Mode&2) {
			int p = getpid();
			setpgid(p, p);
		}
		
		CloseAndDup(Mode, CaptureOut, kStdOutSilence, STDOUT_FILENO);
		CloseAndDup(Mode, CaptureErr, kStdErrSilence, STDERR_FILENO);
		
		execvp(argv[0], (char* const*)argv);
		_exit(errno); // in case execvp fails
	}

	byte Result = 0;
	if (ChildID > 0) {
		auto X = PSRoot;
		if (!X) {
			PSRoot = X = JB_Sh_Constructor(0, JB_Str__Empty(), 0, -1);
		}
		JB_Ring_LastSet(X, S);
		S->_Status = -1;
		S->PID = ChildID;
		pipe_close(CaptureOut[WR]);
		pipe_close(CaptureErr[WR]);
		CheckStillAlive(S);
	} else {
		Result = errno;
		JB_ErrorHandleFile(S->Path, nil, Result, nil, "run");
	}

//	JB_FreeIfDead(path);
	free(argv);
	return Result;
}


ShellStream* JB_Sh__First() {
	return (ShellStream*)JB_Ring_First(PSRoot);
}


void JB_Sh_Close(ShellStream* self) {
	PicoClose(self->StdErr);
	PicoClose(self->StdOut);
}


static JB_String* ReadPico (PicoComms* C) {
	PicoMessage M = PicoGetCpp(C);
	if (M) {
		return JB_Str__Freeable((uint8*)M.Data, M.Length);
	}
	return JB_Str__Empty();
}

JB_String* JB_Sh_ReadStdErr (ShellStream* self) {
	return ReadPico(self->StdErr);
}

JB_String* JB_Sh_ReadStdOut (ShellStream* self) {
	return ReadPico(self->StdOut);
}


int JB_Str_System(JB_String* self) { // needz escape params manually...
    uint8 Buffer[PATH_MAX];
    uint8* Result = JB_FastFileString(self, Buffer);
    int ugh = system((const char*)Result);
    return WEXITSTATUS(ugh);
}


bool JB_FS_AppendPico (FastString* Self, PicoComms* M) {
	return PicoAppend(M, (PicoAppenderFn)JB_FS_WriteAlloc_, Self);
}


int JB_Str_Execute (JB_String* self, Array* R, FastString* Out, FastString* ErrsIn, int Mode, Date TimeOut) {
	if (ErrsIn) Mode&=~kStdErrNil; else if (!(Mode&kStdErrNil)) Mode |= kStdErrPassThru;
	if (Out)  Mode&=~kStdOutNil; else if (!(Mode&kStdOutNil)) Mode |= kStdOutPassThru;
	auto Sh = JB_Sh_Constructor(0, self, R, Mode&~kStdErrPassThru);
	byte Error = JB_Sh_StartProcess(Sh, 0);
	if (Error) {
		JB_SetRef(Sh, 0);
		return Error;
	}
	
	auto Errs = ErrsIn;
	if (!Errs and ((Mode&kStdErrNil)==kStdErrPassThru))
		Errs = JB_FS_ConstructorSize(0, 0);
	
	Date ExitAfter = 0;
	if (TimeOut > 0)
		ExitAfter = JB_Date__Now() + TimeOut;

	while (TimeOut >= 0) {							// allow -1 time out which instantly exits...
		int ReadAny = JB_FS_AppendPico(Errs, Sh->StdErr);
		ReadAny |= JB_FS_AppendPico(Out, Sh->StdOut);
		if (!ReadAny and JB_Sh_Status(Sh) != -1)
			break;
		if (TimeOut > 0) {
			auto Now = JB_Date__Now();
			if (ReadAny)
				ExitAfter = Now + TimeOut;
			  else if (Now >= ExitAfter)
				break;
		}
		JB_Date__Sleep(1);
	}

	if (Errs and (Mode&kStdErrNil)==kStdErrPassThru) {
		void JB_Rec__Latchkum (Message* node, JB_String* Desc, JB_Object* Source);
		JB_Rec__Latchkum(nil, JB_FS_GetResult(Errs), nil);
	}
	int Exit = Sh->_Status;
	JB_Delete((FreeObject*)Sh);
	if (Exit>128)			// died from a signal. Perhaps a SEGFAULT.
		JB_ErrorHandleFile(self, nil, Exit, "crashed", "running");
	return Exit;
}


ShellStream* JB_Sh__Stream(JB_String* self, Array* Args, int Mode) {
// remove this?
	auto rz = JB_Sh_Constructor(0, self, Args, Mode);
	byte Error = JB_Sh_StartProcess(rz, 0);
	if (Error) {
		JB_SetRef(rz, 0);
	}
	return rz;
}


///*(^&£^/ Shellstream vvvvv >>>>>>>

ShellStream* JB_Sh_Constructor (ShellStream* self, JB_String* Path, Array* Args, byte Mode) {
	JB_New2(ShellStream);
	*self = {};
	self->Args = JB_Incr(Args);
	self->Path = JB_Incr(JB_Str_MakeC(Path));
	self->Mode = Mode;
	if (!(Mode&kStdOutNil))
		self->StdOut = PicoCreate("StdOut", 256*1024);
	if (!(Mode&kStdErrNil))
		self->StdErr = PicoCreate("StdErr", 16*1024);
	return self;
}


void JB_Sh_Destructor (ShellStream* self) {
	ShellStream& Sh = *self;
	PicoDestroy(Sh.StdOut);
	PicoDestroy(Sh.StdErr);
	JB_Decr(Sh.Path);
	JB_Decr(Sh.Args);
	JB_Ring_Destructor(self);
	if (!self->LeaveOrphaned)
#ifndef AS_LIBRARY
		JB_Kill(self->PID);
#endif
}


bool JB_App__TurnInto(JB_String* self, Array* R) {
	auto argv = JB_Proc__CreateArgs(JB_Str_MakeC(self), R);
	execvp(argv[0], (char* const*)argv); // may exit here. :)
	free(argv);
	JB_ErrorHandleFile(self, nil, errno, nil, "running");
	return false;
	
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

