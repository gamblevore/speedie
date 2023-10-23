
// Copyright, Theodore H. Smith 2023.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


extern "C" {

JB_CriticalSection	ChildFinder;
ProcessOwner		Root;


static void AddLostChild_(int PID, int ExitCode) {
	ProcessOwner* F = JB_PID_Next(&Root);
	while (F) {
		if (F->PID == PID) {
			F->ExitCode = ExitCode;
			return;
		}
		F = JB_PID_Next(F);
	}
}


uint SignalsReceived;
void JB_SigMsgReceived(int signum) {
	uint X = SignalsReceived + 1;
	if (!X) X = 1;
	SignalsReceived = X;
};

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
	self->PID = 0;
}


int JB_PID_Exit(ProcessOwner* self) {
	int Code = self->ExitCode;
	if (WIFEXITED(Code)) {				// called exit()
		return WEXITSTATUS(Code);
	}
	return -1;
}


int JB_PID_TermSig(ProcessOwner* self) {
	int Code = self->ExitCode;
	if (WIFSIGNALED(Code)) {			// died from a signal
		return WTERMSIG(Code);
	}
	return 0; 
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
	return (ProcessOwner*)Root.Next;
}

int JB_PID_Signal(ProcessOwner* self, int sig) {
	int PID = self->PID;
	if (!PID) PID = getpid();
	return kill(PID, sig);
}


typedef void (*SignalHandler)(int Sig);

static void TrySetSig(int S, SignalHandler H) {
	struct sigaction Found;
	int Err = sigaction(S, 0, &Found);
	if (!Found.sa_handler) {
		signal(S, H);
	}
}

void JB_DefaultSignals() {
	TrySetSig(SIGUSR1, JB_SigMsgReceived);
	TrySetSig(SIGCHLD, JB_SigChild); // this might be a problem when used as a lib.
									 // better to find THEIR existing lib func and call it after we are done!
}


}
