
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

#ifdef AS_LIBRARY

extern "C" {
	bool JB_NoExitOnCrash;
	void JB_Child_Stub() {}
	void JB_RemoveHandlers() {};
}

#else

#include "JB_Umbrella.hpp"
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <execinfo.h>
	
#include <unistd.h>
#include <errno.h>
#include <signal.h>

extern "C" {

#ifndef SIGEMT
	#define SIGEMT 0
#endif
#ifndef SIGINFO
	#define SIGINFO 0
#endif

#define x(v) (1<<v) |
#if DEBUG
	#define x_release(v) 
#else  // ignore SIGTRAP, to stop Xcode crashing subprocesses, if speedie is run from xcode
	#define x_release(v) (1<<v) |
#endif

static const unsigned int CrashList = x(SIGHUP) x(SIGQUIT) x(SIGILL) x(SIGSEGV) x(SIGBUS)  x(SIGFPE) x(SIGSYS) x(SIGTERM) x(SIGEMT) x(SIGABRT) x(SIGXCPU) x(SIGXFSZ) 0;
static const unsigned int IgnoreList = x_release(SIGTRAP) x(SIGPIPE) x(SIGPROF) x(SIGWINCH) x(SIGINT)  0;
static const unsigned int WakeList = x(SIGURG) x(SIGVTALRM) x(SIGALRM) x(SIGINFO) x(SIGUSR1) x(SIGUSR2) 0;
#undef x


extern const char**		JB_Main__Args;
bool					JB_NoExitOnCrash;



int JB_App__ParentID() {
	return getppid();
}

int JB_App__ID() {
	return getpid();
}

void JB_Wake(int Sig) { ; /* do nothing! This will wake up the process hopefully? */ }



void JB_Proc__TellParentIDied	(const char* signal);
int JB_Rec_ShellPrintErrors		(void* self);


void JB_CrashTracer() {
    int   size = 32;
    void* array[32];
    auto  strings = JB_App__BackTrace(array, &size);

    for_(size) {
        JB_Rec__CrashLog(strings[i]);
	}
    
	JB_Rec__CrashLog("");    
    free( strings );
}


void JB_RemoveHandlers() {
	for_(32)
		if (CrashList & (1<<i))
			signal(i, SIG_DFL);
}


void JB_CrashHandler (int Sig) {
	if (Sig <= 0)		// Some unixes/shells can do this?
		return;

						// Stop crash-loops.
	static bool AlreadyCrashed;
	if (AlreadyCrashed)
		return;
	AlreadyCrashed = true;
	
						// Deregister
	JB_RemoveHandlers();

						// Report + Log
	char ErrorBuff[128];
	auto T = time(0);
	snprintf(ErrorBuff, sizeof(ErrorBuff), "%sSignal %i in %s", ctime(&T), Sig, *JB_Main__Args);
	if (Sig != SIGHUP and Sig != SIGQUIT and Sig != SIGKILL) {
		JB_Rec__CrashLog("\n\n****** CRASHED ******");
		JB_Rec__CrashLog(ErrorBuff, false);
		JB_Rec__CrashLog(" [");
		const char** c = JB_Main__Args;
		while (*(++c)) {
			JB_Rec__CrashLog("\t", 0);
			JB_Rec__CrashLog(*c);
		}
		JB_Rec__CrashLog("]\n");
		JB_CrashTracer();
		JB_Rec__CrashLog("-----------------------\n");
	} else {
		fputs(ErrorBuff, stderr);
	}

						// Print Normal Errors
	JB_Rec_ShellPrintErrors(nil);
	PicoFinish();
	bool AskExit = (Sig == SIGHUP) or (Sig == SIGQUIT) or (Sig == SIGKILL);
	if (!JB_NoExitOnCrash or AskExit) {
		if (AskExit)
			puts("ForcedToQuit");
		exit(128|Sig);
	}
}



// For some reason... once we have set the sigint to ignore, setting it to the crashhandler
// now does not exit. So lets crash.

static void TerminalInterupt(int Sig) {
	signal(Sig, SIG_IGN);
	JB_Rec_ShellPrintErrors(nil);
	_exit(0);
}

void JB_App__CrashOnInterupt (bool b) { // useful for command-line tools
	signal(SIGINT, b?TerminalInterupt:SIG_IGN);
}

void JB_App__CrashInstall() {
	for_(32) {
		if (IgnoreList & (1<<i)) {
			if (i != SIGINT or !isatty(STDIN_FILENO)) // allow ^C to kill speedie from terminal
				signal(i, SIG_IGN);					  // but don't allow breakpoints to kill it!!
		}
		if (CrashList & (1<<i))
			if (signal(i, JB_CrashHandler) == SIG_IGN)
				signal(i, SIG_IGN); // restore the old ignore signal... make speedie more unix-friendly.
		if (WakeList & (1<<i))
			signal(i, JB_Wake);
	}
}




}

#endif

