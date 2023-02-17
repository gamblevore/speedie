
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


void JB__DefaultCrashHandler(int Sig) {
	bool Crash = Sig > 0;
	if (Sig < 0) Sig = -Sig;
    if (Sig != SIGTERM and Sig != SIGQUIT) {
		JB_PrintStackTrace();
		
		char ErrorBuff[64];
		snprintf(ErrorBuff, 64, "Crash: %s", strsignal(Sig));
		JB_Rec__CrashLog(ErrorBuff);
		if (Crash)
			exit(-1);
	} else if (getppid() > 1) {
		SafePrint("Child process got signal...\n" );
	} else { 
		SafePrint("Process got signal...\n" );
	}
}

void JB_App__CrashInstall(JB_CrashHandler P) {
	JB_CrashHandler C = (JB_CrashHandler)P;
	if (!C)
		C = SIG_DFL;
	int list[] = {SIGSEGV, SIGBUS, SIGILL, SIGFPE, SIGSYS};
	int n = sizeof(list)/sizeof(int);
	for_ (n) {
		if (signal(list[i], C) == SIG_IGN)
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

