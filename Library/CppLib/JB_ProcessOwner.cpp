
// Copyright, Theodore H. Smith 2023.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


extern "C" {

ProcessOwner		PSRoot;


static void AddLostChild_(int PID, int C) {
	ProcessOwner* F = &PSRoot;
	while ((F = JB_PID_Next(F))) {
		if (F->PID == PID) {
			int Ex = WEXITSTATUS(C);
			int Sig = WTERMSIG(C);
			bool Exited = WIFEXITED(C);
			bool Signalled = WIFSIGNALED(C);
			if (Signalled)
				F->_Status = Sig|128;
			  else
				F->_Status = Ex;
			return;
		}
	}
}


std::atomic_int SigChildOutStanding = 0x0000000 + 0000 -1*0; // FUCK UNIX
void JB_SigChild (int signum) {
	SigChildOutStanding++;
}


int JB_PID_Status (ProcessOwner* F) {
	while (SigChildOutStanding > 0) {
		while (true) {
			int ExitCode = 0;
			int PID = waitpid(-1, &ExitCode, WNOHANG);
			if (PID > 0) {
				AddLostChild_(PID, ExitCode);
				JB_PID_UnRegister(F);
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


void JB_KillChildrenOnExit() {
	ProcessOwner* F = &PSRoot;
	while ((F = JB_PID_Next(F)))
		if (F->PID > 0 and F->KillOnExit)
			kill(F->PID, SIGKILL);
}

 
#ifndef AS_LIBRARY // shouldn't this be around more??
int JB_PID_Kill (ProcessOwner* F, int Code) {
	if (Code < 0) Code = 0;
	F->_Status = Code;
	
	return JB_Kill(F->PID);
}
#endif

////*&(^!@^*& ^^^^^^^ PiD ^^^^^^^^
//// BATCHES LOST CONTROL


void JB_PID_Start() {
	JB_PID_Constructor(&PSRoot);
}

void JB_Helper_SelfLink(JB_RingList* New) {
	New->PID = 0; // using this for the allocblock instead of just here... causes problemsssss
    New->Prev = New;
    New->Next = New;
}


ProcessOwner* JB_PID_Constructor(ProcessOwner* self) {
	JB_New2(ProcessOwner);
	JB_Helper_SelfLink((JB_RingList*)self);
	self->_Status = -2;
	self->KillOnExit = true;
	self->LeaveOrphaned = false;
	return self;
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
	JB_Helper_PutAfter((JB_RingList*)(&PSRoot), (JB_RingList*)self);
}


void JB_PID_Destructor(ProcessOwner* self) {
	JB_PID_UnRegister(self);
	if (!self->LeaveOrphaned)
#ifndef AS_LIBRARY
		JB_Kill(self->PID);
#else
		
		(0); // kill(self->PID, SIGKILL);
#endif

}

void JB_PID_UnRegister(ProcessOwner* self) {
	JB_Helper_Unlink((JB_RingList*)self);
}

ProcessOwner* JB_PID_Next(ProcessOwner* self) {
	auto Result = (ProcessOwner*)(self->Next);
	if (Result != &PSRoot) {
		return Result;
	}
	return 0;
}

ProcessOwner* JB_PID__First() {
	return JB_PID_Next((ProcessOwner*)&PSRoot);
}

int JB_Signal(int PID, int sig) {
	return kill(PID, sig);
}

}
