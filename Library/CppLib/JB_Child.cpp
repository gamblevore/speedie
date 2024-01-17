
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

#ifdef AS_LIBRARY

void JB_Child_Stub() {}

#else

#include "JB_Umbrella.hpp"
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <pthread.h>
#include <execinfo.h>


extern "C" {


int JB_App__ParentID() {
	return getppid();
}

int JB_App__ID() {
	return getpid();
}

const char** JB_App__BackTrace(void** space, int* size) {
    *size = backtrace( space, *size );
    return (const char**)backtrace_symbols( space, *size );
}


void JB_Rec__CrashLog(const char* c);
void JB_Proc__TellParentIDied(const char* signal);
int JB_Rec_ShellPrintErrors(void* self);


void JB_CrashTracer() {
    int   size = 32;
    void* array[size];
    auto  strings = JB_App__BackTrace(array, &size);

    for_(size) {
        JB_Rec__CrashLog(strings[i]);
	}
    
	JB_Rec__CrashLog("");    
    free( strings );
}

#define x(v) (1<<v) |
static const unsigned int CrashList = x(SIGTRAP) x(SIGHUP) x(SIGQUIT) x(SIGILL) x(SIGSEGV) x(SIGBUS)  x(SIGFPE) x(SIGSYS) x(SIGTERM) x(SIGEMT) x(SIGABRT) x(SIGXCPU) x(SIGXFSZ) 0;
static const unsigned int IgnoreList = x(SIGPIPE) x(SIGPROF) x(SIGWINCH) x(SIGINT)   0;
static const unsigned int WakeList = x(SIGURG) x(SIGVTALRM) x(SIGALRM) x(SIGINFO) x(SIGUSR1) x(SIGUSR2) 0;
#undef x



extern _cstring			App_CallPath;

void JB_Wake(int Sig) { ; /* do nothing! This will wake up the process hopefully? */ }

void JB_CrashHandler(int Sig) {
	if (Sig <= 0)
		return; // some unixes/shells can do this?

				// deregister
	for_(32)
		if (CrashList & (1<<i))
			signal(i, SIG_DFL);

				// report to stdout
	char ErrorBuff[128];
	snprintf(ErrorBuff, 64, "%s Signal: %s\n", App_CallPath, strsignal(Sig));
	puts(ErrorBuff);
	
				// log to file
	JB_Rec__CrashLog("\n\n****** CRASHED ******");
	JB_Rec__CrashLog(ErrorBuff);
	JB_CrashTracer();
	JB_Rec__CrashLog("-----------------------\n");

				// print normal-errors
	JB_Rec_ShellPrintErrors(nil);
	
				// we should crash now... that we removed this crash handler.
}

void JB_App__CrashInstall() {
	for_(32) {
		if (IgnoreList & (1<<i))
			signal(i, SIG_IGN);
		if (CrashList & (1<<i) and signal(i, JB_CrashHandler) == SIG_IGN)
			signal(i, SIG_IGN); // restore the old ignore signal... make speedie more unix-friendly.
		if (WakeList & (1<<i))
			signal(i, JB_Wake);
	}

	signal(SIGCHLD, JB_SigChild);
}
}
#endif

