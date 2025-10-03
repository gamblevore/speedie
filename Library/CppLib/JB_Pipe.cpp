
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


#define kStdOutPassThru 4
#define kStdOutSilence  8
#define kStdOutNil      12
#define kStdErrPassThru 16
#define kStdErrSilence  32
#define kStdErrSilence  32
#define kStdErrNil      48


extern "C" {
JBClassPlace( ProcessOwner,   JB_PID_UnRegister,     JB_AsClass(JB_Object),      0 );
}


#ifndef AS_LIBRARY
#include <string>
#include <iostream>


extern "C" {
const int RD = 0; const int WR = 1;
JBClassPlace( ShellStream,    JB_Sh_Destructor,      JB_AsClass(ProcessOwner),   0 );


void JB_Rec__Latchkum (Message* node, JB_String* Desc, JB_Object* Source);


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


//typedef void* (*PThread_Function)(void* Param);
// // just use pico, can get the buffer size down to 256 bytes if I want...
//int JB_App__Thread(void* Fn, void* Obj, JB_String* Name) {
//	pthread_t T = 0;
//	// pthread_setname_np sucks anyway ;-/
//	if (!pthread_create(&T, nullptr, (PThread_Function)Fn, Obj) and !pthread_detach(T))
//		return 0;
//	return JB_ErrorHandleFileC(0, errno, "Starting pthread");
//}
//

bool CanASMBKPT = true;
void JB_App__SetASMBreak(bool b) {
	CanASMBKPT = b;
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


static void Unblock (int fd) {
	if (fd < 0) return;
	int FL = fcntl(fd, F_GETFL, 0);
	if (FL!=-1)
		fcntl(fd, F_SETFL, FL | O_NONBLOCK);
}



static void CheckStillAlive (ShellStream* Sh) {
// kill() function unreliable. UNIX breaking it's own guidelines! As usual!
	require0 (Sh->_Status == -1  and  kill(Sh->PID, 0) != 0);
	JB_PID_Status(Sh);
	if (Sh->_Status < 0) // why?
		Sh->_Status = 0;
	JB_PID_UnRegister(Sh); // in case JB_PID_Exit can't find this. its possible! with unix.
}


int JB_Sh_StartProcess(ShellStream* self, JB_String* path, Array* Args, PicoComms* C, int Mode) {
// fcntl,Fork,execvp,Pipe,Dup2,Waitid,Errno,close,Eintr,_exit // far too much stuff in unix.
	auto& Sh = *self;
	auto argv = JB_Proc__CreateArgs(path, Args);
	if (!argv) return E2BIG;
	
	if (Sh.Output) {
		pipe(Sh.CaptureOut);
		Unblock(Sh.CaptureOut[RD]); // should never block
	}
	if (Sh.ErrorOutput) {
		pipe(Sh.CaptureErr);
		Unblock(Sh.CaptureErr[RD]); // even this blocking at all is kinda sus...
	}
	
	int PID = PicoStartFork(C, true);
	if (PID == 0) { // CHILD
		if (Mode&2) {
			setpgid(getpid(), getpid());
		}
		
		if (Mode&kStdOutSilence) {
			close(STDOUT_FILENO);
		} else {
			Dup2_( Sh.CaptureOut[WR], STDOUT_FILENO );
			pipe_close(Sh.CaptureOut[WR]);
			pipe_close(Sh.CaptureOut[RD]);
		} // move these two cases into a subfunction?
		
		if (Mode&kStdErrSilence) {
			close(STDERR_FILENO);
		} else {
			Dup2_( Sh.CaptureErr[WR], STDERR_FILENO );
			pipe_close(Sh.CaptureErr[WR]);
			pipe_close(Sh.CaptureErr[RD]);
		}
		
		execvp(argv[0], (char* const*)argv);
		_exit(errno-!errno); // in case execvp fails
	}

	byte Result = 0;
	if (PID > 0) {
		JB_PID_Register(&Sh);
		Sh._Status = -1;
		Sh.PID = PID;
		pipe_close(Sh.CaptureOut[WR]);
		pipe_close(Sh.CaptureErr[WR]);
		CheckStillAlive(&Sh);
	} else {
		Result = errno;
		JB_ErrorHandleFile(path, nil, Result, nil, "run");
	}

//	JB_FreeIfDead(path);
	free(argv);
	return Result;
}


int ReadIfItWasDoneProperly (int fd, unsigned char* Out, int Request, int64& Total, int AsFile, u8* Name);


int UpdatePipesSub_(ShellStream* self, FastString* FS, int& fd, int& Total) {
	if (!FS or fd < 0)
		return 0;
	const int BuffLen = 16*1024; // MacOS default size.
	uint8* Buffer = JB_FS_WriteAlloc_(FS, BuffLen);
	if (!Buffer) return -1;

	auto Name = self->Path->Addr;
	int64 N = 0;
	int Error = ReadIfItWasDoneProperly(fd, Buffer, BuffLen, N, 0, Name);
	if (Error == 0)
		pipe_close(fd);		// close the thing here if its finished? might as well?
	Total+=N;
	JB_FS_AdjustLength_(FS, BuffLen, (int)N);
    return Error;
}


bool UpdatePipes_(ShellStream* self, int& Read) {
	auto& Sh = *self;
	CheckStillAlive(self);
	// a better way, would be that each faststring, can contain a "message" that we send
	// via another thread. Basically a block of memory we are allowed to write to
	// Like u8* StreamBlock, int StreamBlockLength
	// FastString should be allowed to lower the length
	// how to syncronise it? Thats always fun. Use two lengths, as a ringbuffer?
	// one writes, one reads.
	 
	int ContinueOut = UpdatePipesSub_(self, Sh.Output,      Sh.CaptureOut[RD], Read);
	int ContinueErr = UpdatePipesSub_(self, Sh.ErrorOutput, Sh.CaptureErr[RD], Read);
	return (ContinueOut > 0) or (ContinueErr > 0);
}


void JB_Sh_UpdatePipes(ShellStream* self) {
	int Read = 0;
	UpdatePipes_(self, Read);
}


void JB_Sh_ClosePipes(ShellStream* self) {
	for (int i = 0; i < 4; i++) {
		pipe_close(self->CaptureOut[i]);
	}
	self->IsClosed = true;
}


int JB_Str_System(JB_String* self) { // needz escape params manually...
    uint8 Buffer[PATH_MAX];
    uint8* Result = JB_FastFileString(self, Buffer);
    int ugh = system((const char*)Result);
    return WEXITSTATUS(ugh);
}


void JB_FEPDWEE_Finish(ShellStream& Sh) {
	pipe_close(Sh.CaptureOut[RD]);
	pipe_close(Sh.CaptureErr[RD]);
	Sh.IsClosed = true;
}


int JB_Str_Execute (JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn, int Mode, Date TimeOut) {
	auto Sh = JB_Sh__Stream(self, R, FSOut, FSErrIn, Mode);
	if (!Sh) return errno|!errno;
	
	Date ExitAfter = 0;
	if (TimeOut > 0)
		ExitAfter = JB_Date__Now() + TimeOut;

	while (TimeOut >= 0) { // allow -1 time out which instantly exits...
		int ReadAmount = 0;
		UpdatePipes_(Sh, ReadAmount);
		if (JB_PID_Status(Sh) != -1)
			break;
		if (TimeOut > 0) {
			auto Now = JB_Date__Now();
			if (ReadAmount > 0)
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
		JB_Rec__Latchkum(nil, JB_FS_GetResult(ShErr), nil);
	}
	int Exit = Sh->_Status;
	JB_FreeIfDead(Sh);
	if (Exit>128)			// died from a signal // usually its what we want, despite being mixed up
		JB_ErrorHandleFile(self, nil, Exit, "crashed", "running");
	return Exit;
}


ShellStream* JB_Sh__Stream(JB_String* self, Array* Args, FastString* FSOut, FastString* FSErrIn, int Mode) {
	auto rz = JB_Sh_Constructor(0, self);
	if (FSOut) // cleanup
		Mode &= ~kStdOutNil;
	if (FSErrIn)
		Mode &= ~kStdErrNil;
	rz->Output = JB_Incr(FSOut);
	rz->ErrorOutput = JB_Incr(FSErrIn);
	rz->Args = JB_Incr(Args);
	byte Error = JB_Sh_StartProcess(rz, self, Args, 0, Mode);
	if (Error) {
		JB_SetRef(rz, 0);
	}
	return rz;
}


///*(^&£^/ Shellstream vvvvv >>>>>>>

ShellStream* JB_Sh_Constructor(ShellStream* self, JB_String* Path) {
	JB_New2(ShellStream);
	*self = {};
	JB_PID_Constructor(self);
	for (int i = 0; i < 4; i++)
		self->CaptureOut[i] = -1;
	
	self->IsClosed = false;
	self->Path = JB_Incr(JB_Str_MakeC(Path));
	return self;
}


void JB_Sh_Destructor(ShellStream* self) {
	ShellStream& Sh = *self;
	JB_FEPDWEE_Finish(Sh);
	JB_Decr(Sh.ErrorOutput);
	JB_Decr(Sh.Path);
	JB_Decr(Sh.Output);
	JB_Decr(Sh.Args);
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
		int ReadAmount = 0;
		if (UpdatePipes_(self, ReadAmount)>0) // means continue... there is more to get.
			return true;
		JB_FEPDWEE_Finish(Sh);
	}
	return false;
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

