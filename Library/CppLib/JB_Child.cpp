
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


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

void SafePrint (const char* c) {
	write(STDOUT_FILENO, c, strlen(c) );
}

void JB__DefaultCrashHandler(int Sig) {
	debugger;
    if (Sig != SIGTERM and Sig != SIGQUIT) {
		JB_PrintStackTrace();
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
