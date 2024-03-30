
// Copyright, Theodore H. Smith 2023.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


extern "C" {

ProcessOwner		Root;


static void AddLostChild_(int PID, int C) {
	ProcessOwner* F = JB_PID_Next(&Root);
	while (F) {
		if (F->PID == PID) {
			int Ex = 255; 	int Sig = 0;
			if (WIFEXITED(C))   Ex = WEXITSTATUS(C);
			if (WIFSIGNALED(C)) Sig = WTERMSIG(C);
			if (Sig and !Ex) // in case unix is being dumb. Which happens a lot.
				Ex = 1;
			F->_Exit = Ex;
			F->_Status = Sig;
			return;
		}

		F = JB_PID_Next(F);
	}
}


std::atomic_int SigChildOutStanding = 0x0000000 + 0000 -1*0; // FUCK UNIX
void JB_SigChild (int signum) {
	SigChildOutStanding++;
}

int JB_PID_Status (ProcessOwner* F) {
	return F->_Status;
}

int JB_PID_Exit (ProcessOwner* F) {
	while (SigChildOutStanding > 0) {
		while (true) {
			int ExitCode = 0;
			int PID = waitpid(-1, &ExitCode, WNOHANG);
			if (PID > 0) {
				AddLostChild_(PID, ExitCode);
			} else if (PID == 0) {
				break;
			} else if (errno != EINTR) {
				return -3; // error
			}
		}
		SigChildOutStanding--;
	}
	if (SigChildOutStanding < 0) // ?what?
		SigChildOutStanding = 0;
	return F->_Exit;
}

void JB_PID_Kill (ProcessOwner* F) {
	if (F->_Exit == -1)
		F->_Exit = 1;
	if (F->PID > 0)
		kill(F->PID, SIGKILL);
}


////*&(^!@^*& ^^^^^^^ PiD ^^^^^^^^
//// BATCHES LOST CONTROL


void JB_PID_Start() {
	JB_PID_Constructor(&Root);
}

ProcessOwner* JB_PID_Constructor(ProcessOwner* self) {
	JB_New2(ProcessOwner);
	JB_Helper_SelfLink((JB_RingList*)self);
	self->_Status = 0;
	self->_Exit = -2;
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
	JB_Helper_PutAfter((JB_RingList*)(&Root), (JB_RingList*)self);
}


void JB_PID_Destructor(ProcessOwner* self) {
	JB_PID_UnRegister(self);
}

void JB_PID_UnRegister(ProcessOwner* self) {
	JB_Helper_Unlink((JB_RingList*)self);
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
