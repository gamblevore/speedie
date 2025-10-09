
#define PICO_IMPLEMENTATION 
#include "PicoMsg.h"
// :O 😇😮😵😇😮😵😇🤯😮😮🤯😮😇😮😵😇😮😮😇😮😵😮😮😮

#include <signal.h>

extern "C" {
// need trousers
std::atomic_int SigChildOutStanding = 0; // FUCK UNIX

struct ChildInfo {
	int		PID;
	short	ExitCode;
	bool	KillOnExit;
};

// maybe just use a hash or something.
// we don't need complex behaviour...
#define MaxProcesses 63
struct ChildProcessList {
	ChildInfo		Children[MaxProcesses];
	int				Count;
	PicoTrousers	Lock;
	
	void LostChild (int PID, int ExitCode) {
		printf("Lost Child Process: %i\n", PID);
		int N = Count;
		if (N < 63) {
			if (WIFSIGNALED(ExitCode))
				ExitCode = WTERMSIG(ExitCode)|128;
			  else
				ExitCode = WEXITSTATUS(ExitCode);
			auto& C = Children[N];
			C.PID = PID;
			C.ExitCode = ExitCode;
			Count = N + 1;
		}
	}
	int FindLostChild (int PID) {
		int N = Count;
		for (int i = 0; i < N; i++) {
			auto& C = Children[i];
			if (C.PID == PID) {
				int Result = C.ExitCode;
				// its better as just an exit table, not a total table?
				// or else finding lost items, at all, will be slow!
				FastRemove(i);
				return Result;
			}
		}
		return -1;
	}
	
	void FastRemove (int i) {
		int n = Count-1;
		auto& C = Children[n];
		Children[i] = C;
		C = {};
		Count = n;
	}
	
	void AddChild (int PID) {
		int N = Count;
		Children[N] = {PID, -1, true};
	}

	void KillOnExit () {
		for (int i = Count-1; i >= 0; i--) {
			auto& C = Children[i];
			int ID = C.PID;
			if (C.KillOnExit)					// seems unused?
				kill(ID, SIGKILL);				// leave for now.
		}
		Count = 0;
	}
}; static ChildProcessList ChildTable;


void JB_KillChildrenOnExit () {
	ChildTable.KillOnExit();
}

void JB_AddProcess (int PID) {
	ChildTable.AddChild(PID);
}

void UpdateExitCodes () {
	int Remaining = 100;
	while (SigChildOutStanding > 0) {
		if (--Remaining <= 0)
			return; // sigh. endless EINTR?
		int ExitCode = 0;
		int ChildID = waitpid(-1, &ExitCode, WNOHANG);
		if (ChildID == 0)
			break; // no more found.
		if (ChildID < 0 and errno == EINTR)
			continue;
		if (ChildID < 0)
			break; // an error?
		ChildTable.LostChild(ChildID, ExitCode);
	}
	SigChildOutStanding--;
}


int FindExitCode (int PID) {
	if (SigChildOutStanding)
		UpdateExitCodes();
	return ChildTable.FindLostChild(PID);
}


void JB_SigChild (int signum) {
	SigChildOutStanding++;
}

}
