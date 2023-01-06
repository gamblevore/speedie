
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



#ifndef AS_LIBRARY // overkill

#include "JB_Umbrella.hpp"
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>


#if defined(__MACH__) && !defined(CLOCK_REALTIME)
#define CLOCK_REALTIME 0
// clock_gettime is OSX >= 10.12 and defines CLOCK_REALTIME.
int clock_gettime(int clk_id, timespec* t) {
    struct timeval now;
    int rv = gettimeofday(&now, NULL);
    if (rv) return rv;
    t->tv_sec  = now.tv_sec;
    t->tv_nsec = now.tv_usec * 1000;
    return 0;
}
#endif


extern "C" {
void JB_Date__Sleep(Date Time) {
    struct timespec ts;
    ts.tv_sec = Time>>16;
    ts.tv_nsec = (Time & ((1<<16)-1)) * 15258.7890625;
    errno = 0;
    int PID = getpid(); // for debug
    while ((nanosleep(&ts, &ts) == -1 and errno == EINTR)) {
		;
    }	
}



int64 JB_Date__TimeID () {
// 2017y02m13d05h10m --> 2017021305
    time_t t = time(nil);
    tm* Time = localtime( &t );
    
    int H = Time->tm_hour;
    int D = Time->tm_mday         * 100;
    int M = (Time->tm_mon+1)      * 10000;
    int Y = (Time->tm_year+1900)  * 1000000;

    return (H + D) + (M + Y);
}


Date JB_Date__Create( u64 S, u64 NS ) {
    NS /= (u64)15259;
    S <<= 16;
    return S + NS;
}

Date JB_Date__SpecToDate( timespec ts ) {
	return JB_Date__Create(ts.tv_sec, ts.tv_nsec);
}
// 0xFFFF -> 0.9999
// 0x8000 -> 0.5...

Date JB_Date__Now( ) {
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
//	int64 x = clock_gettime_nsec_np(CLOCK_REALTIME);
	return JB_Date__SpecToDate(ts);
}

}

#else
extern "C" void JB_Date__Stub() {
	return;
}

#endif
