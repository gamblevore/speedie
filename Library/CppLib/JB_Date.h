

#ifndef __JB_DATE__
#define __JB_DATE__

#include "JB_Umbrella.h"

extern "C" {
    
    // do I really want such a class? why not just use a 64-bit value?
    // I could do... hmmm.... 32+16=48 bits for seconds? and 16 for fractional seconds?
    // That gives us 9 million year time range. Quite enough...
    struct timespec;
    Date JB_Date__SpecToDate( timespec ts );
    int64 JB_Date__TimeID ();
    void JB_Date__Sleep(Date Time);
    Date JB_Date__Now( );
#if defined(__x86_64__) || defined(__amd64)
inline u64 rdtsc() {
	u64 a; u64; d;
	__asm__ volatile ("rdtsc" : "=a" (a), "=d" (d));
	return (d<<32) | a;
}
#elif defined(__i386__)
inline u64 rdtsc() {
	u64 x;
	__asm__ volatile ("rdtsc" : "=A" (x));
	return x;
}
#else
	inline u64 RDTSC() {
		return __builtin_ia32_rdtsc();
	}
#endif

}

#endif

