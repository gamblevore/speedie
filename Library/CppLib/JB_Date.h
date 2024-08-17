

#ifndef __JB_DATE__
#define __JB_DATE__

#include "JB_Umbrella.h"

extern "C" {
    // 9 million year time range at 64K/s. Quite enough...
    struct timespec;
	uint64 JB_Date_TimeID (Date Time);    
	Date JB_Date__Create( u64 S, u64 NS );
    void JB_Date__Sleep(Date Time);
    bool JB_Date__TrySleep (Date Time);
    Date JB_Date__Now( );
}

#if defined(__x86_64__) || defined(__amd64)
inline u64 RDTSC() {
	u64 a; u64 d;
	__asm__ volatile ("rdtsc" : "=a" (a), "=d" (d));
	return (d<<32) | a;
}
#elif defined(__i386__)
inline u64 RDTSC() {
	u64 x;
	__asm__ volatile ("rdtsc" : "=A" (x));
	return x;
}
#else
#include <chrono>
inline u64 RDTSC() {
	return static_cast<int64>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());

}
#endif

/* // could this work?
// SPDX-License-Identifier: GPL-2.0
u64 rdtsc(void)
{
    u64 val;

    asm volatile("mrs %0, cntvct_el0" : "=r" (val));

    return val;
}
*/

#endif

