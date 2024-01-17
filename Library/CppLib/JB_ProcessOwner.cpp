
// Copyright, Theodore H. Smith 2023.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


extern "C" {

JB_CriticalSection	ChildFinder;
ProcessOwner		Root;


void JB_FillProc (ProcessOwner* F, int C) {
	int Ex = 255; 	int Sig = 0;
	if (WIFEXITED(C))   Ex = WEXITSTATUS(C);
	if (WIFSIGNALED(C)) Sig = WTERMSIG(C);
	F->Exit = Ex;
	F->Status = Sig;
}


static void AddLostChild_(int PID, int ExitCode) {
	ProcessOwner* F = JB_PID_Next(&Root);
	while (F) {
		if (F->PID == PID)
			return JB_FillProc(F, ExitCode);
		F = JB_PID_Next(F);
	}
}


void JB_SigChild (int signum) {
	if (!JB_PID_Next(&Root)) return;
	ChildFinder.Lock();

	while (true) {
		int ExitCode = 0;
		int PID = waitpid(-1, &ExitCode, WNOHANG);
		if (PID > 0) {
			AddLostChild_(PID, ExitCode);
		} else if (PID == 0 or errno != EINTR) {
			break;
		}
	}

	ChildFinder.Finish();
}





////*&(^!@^*& ^^^^^^^ PiD ^^^^^^^^
//// BATCHES LOST CONTROL

void JB_PID_Constructor(ProcessOwner* self) {
	if (!self and !Root.Next) {
		self = &Root;
	}
	JB_Helper_SelfLink((JB_RingList*)self);
	self->Status = 0;
	self->Exit = -1;
}


JB_StringC* JB_Err_SignalName (int Sig) {
	const char* S = "NormalExit";
	if (Sig) S = strsignal(Sig);
	return JB_StrC(S);
}

JB_StringC* JB_Err_Name (int Err) {
	return JB_StrC(strerror(Err));
}


void JB_PID_Register(ProcessOwner* self) {
	ChildFinder.Lock();
	JB_Helper_PutAfter((JB_RingList*)(&Root), (JB_RingList*)self);
	ChildFinder.Finish();
}


void JB_PID_Destructor(ProcessOwner* self) {
	JB_PID_UnRegister(self);
}

void JB_PID_UnRegister(ProcessOwner* self) {
	ChildFinder.Lock();
	JB_Helper_Unlink((JB_RingList*)self);
	ChildFinder.Finish();
}

ProcessOwner* JB_PID_Next(ProcessOwner* self) {
	auto Result = (ProcessOwner*)(self->Next);
	if (Result != &Root) {
		return Result;
	}
	return 0;
}

ProcessOwner* JB_PID__First() {
	return JB_PID_Next((ProcessOwner*)&Root);
}

int JB_PID_Signal(int PID, int sig) {
	return kill(PID, sig);
}

}
