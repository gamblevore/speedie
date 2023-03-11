
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

extern "C" {


int JB_App__ParentID() {
	return getppid();
}

int JB_App__ID() {
	return getpid();
}

static void SafePrint (const char* c) {
	write(STDOUT_FILENO, c, strlen(c) );
}


void JB__PrintStackTraceAndLog(int Sig) {
	char ErrorBuff[64];
	snprintf(ErrorBuff, 64, "Crash: %s", strsignal(Sig));
	JB_Rec__CrashLog(ErrorBuff);
	JB_PrintStackTrace();
}

void JB_Rec__CrashLog(const char* c);
void JB__ProcessReportCrash();

void JB_PrintStackTrace() {
    int   size = 32;
    void* array[size];
    auto  strings = JB_BackTrace(array, &size);

    for_(size) {
        JB_Rec__CrashLog(strings[i]);
	}
    
	JB_Rec__CrashLog("");    
    free( strings );
}

void JB__CrashHandler(int Sig) {
    if (Sig != SIGTERM and Sig != SIGQUIT) {
		JB__PrintStackTraceAndLog(Sig);
		JB__ProcessReportCrash();
	} else if (getppid() > 1) {
		SafePrint("Child process got signal...\n" );
	} else { 
		SafePrint("Process got signal...\n" );
	}
	exit(-1);
}

void JB_App__CrashInstall() {
	int list[] = {SIGSEGV, SIGBUS, SIGILL, SIGFPE, SIGSYS, SIGTERM, SIGQUIT};
	int n = sizeof(list)/sizeof(int);
	for_ (n) {
		if (signal(list[i], JB__CrashHandler) == SIG_IGN)
			signal(list[i], SIG_IGN); // restore the old ignore signal... make speedie more unix-friendly.
	}
}


void* JB_SuicideChecker (void* obj) {
	while (getppid() > 1)
		JB_Date__Sleep(64*1024);
	kill(0, SIGSEGV);
	return 0;
}


int JB_App__BelongsToParent () {
	pthread_t thr = nil;
	int Err = pthread_create(&thr, nil, JB_SuicideChecker, nil);
	if (!Err)
		Err = pthread_detach(thr);
	return Err;
}


}
#endif

