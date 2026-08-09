
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.hpp"
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <cerrno>

extern "C" {
Date JB_Date__Create (u64 S, u64 NS) {
	u64 NS2 = (NS * 9223372046ULL)>>47ULL; // avoid division :)
    return (S << 16) + NS2;
}

// 0xFFFF -> 0.9999
// 0x8000 -> 0.5...

Date JB_Date__Now () {
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	return JB_Date__Create(ts.tv_sec, ts.tv_nsec);
}


#ifndef AS_LIBRARY // overkill

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


static timespec DateToTimeSpec (Date Durr) {
    struct timespec ts;
    ts.tv_sec = Durr>>16;
    ts.tv_nsec = (Durr & ((1<<16)-1)) * 15258.7890625;
    return ts;
}

void JB_Date__Sleep (Date Durr) {
    auto ts = DateToTimeSpec(Durr);
    while ((nanosleep(&ts, &ts) == -1 and errno == EINTR)) {
		;
    }	
}

bool JB_Date__TrySleep (Date Durr) {
	if (Durr <= 0)
		return Durr == 0;
    auto ts = DateToTimeSpec(Durr);
    return nanosleep(&ts, 0) == 0;
}


uint64 JB_Date_TimeID (Date Dt) {
// 2017y02m13d05h10m --> 2017021305
    time_t t = Dt >> 16;
    tm* Time = localtime( &t );
    
    int H = Time->tm_hour;
    int D = Time->tm_mday         * 100;
    int M = (Time->tm_mon+1)      * 10000;
    int Y = (Time->tm_year+1900)  * 1000000;

    return (H + D) + (M + Y);
}

#endif

}
