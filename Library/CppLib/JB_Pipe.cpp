
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.hpp"

#ifndef AS_LIBRARY
#include <execinfo.h>
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
#include "PicoMsg.h"

#if __linux__
	#include <sys/mman.h>
	#include <sys/sendfile.h>
	#include <linux/limits.h>
#endif

#define kOwnGroup		2
#define kStdOutSilence  4
#define kStdOutPassThru 8
#define kStdOutNil      12
#define kStdErrSilence  16
#define kStdErrPassThru 32
#define kStdErrNil      48



extern "C" {
const int RD = 0;   const int WR = 1;
bool				CanASMBKPT = true;
JB_String* JB_Sh_Render(ShellStream* Self, FastString* Fs_in);
JBClassPlace( ShellStream,     JB_Sh_Destructor,  JB_AsClass(JB_Object),      JB_Sh_Render );

void JB_App__SetASMBreak (bool b) {
	CanASMBKPT = b;
}



// what if we get rid of the global object list?
// instead... collect "dead" IDs. So we don't just update things all over.

int JB_Sh_Status (ShellStream* F) {
	return PicoStatus(F->Pico);
}

 
int JB_Sh_Kill (ShellStream* F, int Code) {
	PicoProcStats S;
	PicoStatus(F->Pico, &S);
	PicoConfig* M = (PicoConfig*)F->Pico;
	M->PIDStatus = Code;
	return JB_Kill(S.PID);
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



void JB_App__SetThreadName(JB_String* self) {
	require0(JB_Str_Length(self));
	u8 CName[PATH_MAX];
	auto tmp = (const char*)JB_FastFileString(self, CName);
	CName[16] = 0; // in case its too long.
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


int JB_Kill (int PID) {
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


int JB_Sh_StartProcess (ShellStream* S) {
// moved all the horrible unix stuff over to pico :)
	auto argv = JB_Proc__CreateArgs(S->Path, S->Args);
	if (!argv) return E2BIG;
	int Mode = S->Mode;
	int ChildID = PicoExec(S->Pico, 0, argv, true, (Mode>>2)&3, (Mode>>4)&3);
	byte Result = 0;
	if (ChildID < 0) {
		Result = errno;
		JB_ErrorHandleFile(S->Path, nil, Result, nil, "run");
	}

	free(argv);
	return Result;
}


void JB_Sh_Close (ShellStream* self) {
//	PicoClose(self->StdErr);
//	PicoClose(self->StdOut);
}


static JB_String* ReadPico (PicoMessage M) {
	if (M)
		return JB_Str__Freeable((uint8*)M.Data, M.Length);
	return JB_Str__Empty();
}

JB_String* JB_Sh_ReadStdErr (ShellStream* self) {
	return ReadPico(PicoStdErr(self->Pico));
}

JB_String* JB_Sh_ReadStdOut (ShellStream* self) {
	return ReadPico(PicoStdOut(self->Pico));
}


int JB_Str_System(JB_String* self) { // needz escape params manually...
    uint8 Buffer[PATH_MAX];
    uint8* Result = JB_FastFileString(self, Buffer);
    int ugh = system((const char*)Result);
    return WEXITSTATUS(ugh);
}



int JB_Str_Execute (JB_String* self, Array* R, FastString* Out, FastString* ErrsIn, int Mode, Date TimeOut) {
	if (ErrsIn) Mode&=~kStdErrNil; else if (!(Mode&kStdErrNil)) Mode |= kStdErrPassThru;
	if (Out)  Mode&=~kStdOutNil; else if (!(Mode&kStdOutNil)) Mode |= kStdOutPassThru;
	auto Sh = JB_Sh_Constructor(0, self, R, Mode&~kStdErrPassThru);
	byte Error = JB_Sh_StartProcess(Sh);
	if (Error) {
		JB_SetRef(Sh, 0);
		return Error;
	}
	
	auto Errs = ErrsIn;
	if (!Errs and ((Mode&kStdErrNil)==kStdErrPassThru))
		Errs = JB_FS_ConstructorSize(0, 0); // we wanna collect errors, even if pass-thru
	
	Date ExitAfter = 0;
	if (TimeOut > 0)
		ExitAfter = JB_Date__Now() + TimeOut;

	while (TimeOut >= 0) {							// allow -1 time out which instantly exits...
		int ReadAny = 0;
		if (Errs)
			ReadAny = PicoStdErr(Sh->Pico, (PicoAppenderFn)JB_FS_WriteAlloc_, Errs).Length;
		if (Out)
			ReadAny += PicoStdOut(Sh->Pico, (PicoAppenderFn)JB_FS_WriteAlloc_, Out).Length;
		if (!ReadAny and JB_Sh_Status(Sh) >= 0)
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

	if (JB_FS_Length(Errs) and (Mode&kStdErrNil)==kStdErrPassThru) {
		// Do we want to pass through, or capture?
		// capture makes more sense. Leave it like this for now.
		void JB_Rec__Latchkum (Message* node, JB_String* Desc, JB_Object* Source);
		JB_Rec__Latchkum(nil, JB_FS_GetResult(Errs), nil);
	}
	if (!ErrsIn and Errs)
		JB_Delete((FreeObject*)Errs);
	
	int Exit = PicoStatus(Sh->Pico);
	JB_Delete((FreeObject*)Sh);
	if (Exit > 128)									// died from a signal. Perhaps a SEGFAULT.
		JB_ErrorHandleFile(self, nil, Exit, "crashed", "running");
	return Exit;
}


ShellStream* JB_Sh__Stream(JB_String* self, Array* Args, int Mode) {
// remove this?
	auto rz = JB_Sh_Constructor(0, self, Args, Mode);
	byte Error = JB_Sh_StartProcess(rz);
	if (Error) {
		JB_SetRef(rz, 0);
	}
	return rz;
}


///*(^&£^/ Shellstream vvvvv >>>>>>>

static const char* MiniName (JB_String* Path) {
	int N = Path->Length;
	auto S = (const char*)Path->Addr;
	while (--N >= 0) {
		auto C = S[N];
		if (C == '/')
			return S+N+1;
	}
	return S;
}


ShellStream* JB_Sh_Constructor (ShellStream* self, JB_String* Path, Array* Args, byte Mode) {
	JB_New2(ShellStream);
	self->Args = JB_Incr(Args);
	self->Path = JB_Incr(JB_Str_MakeC(Path));
	self->Mode = Mode; 
#ifndef AS_LIBRARY
	self->Pico = PicoCreate(MiniName(Path));
#endif
	self->UserFlags = 0;
	return self;
}


void JB_Sh_Destructor (ShellStream* self) {
	JB_Decr(self->Path);
	JB_Decr(self->Args);
#ifndef AS_LIBRARY
	PicoKill(self->Pico);
#endif
	PicoDestroy(self->Pico);
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

