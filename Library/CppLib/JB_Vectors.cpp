
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2013 Theodore H. Smith.
*/

#ifndef AS_LIBRARY
#include "JB_Umbrella.hpp"
#include <cpuid.h>

extern "C" {

void cpuid(int CPUInfo[4], int InfoType) {
    __asm__ __volatile__ (
        "cpuid":
        "=a" (CPUInfo[0]),
        "=b" (CPUInfo[1]),
        "=c" (CPUInfo[2]),
        "=d" (CPUInfo[3]) :
        "a" (InfoType), "c" (0)
    );
}

bool SimdDetectAVX() {
    int info[4];
    cpuid(info, 0x00000001);
    return (info[2] & ((int)1 << 28)) != 0;
}

bool SimdDetectAVX2() {
    int info[4];
    cpuid(info, 0x00000001);
    return (info[1] & ((int)1 <<  5)) != 0;
}


bool SimdDetectAVX512() {
    int info[4];
    cpuid(info, 0x00000001);
    return (info[1] & ((int)1 << 16)) != 0;
}

bool SimdDetectSSE42() {
    int info[4];
    cpuid(info, 0x00000001);
    return (info[2] & ((int)1 << 20)) != 0;
}

} // 

#else

// stop linker errors.
extern "C" void Stub_JB_Vectors () {
    
}

#endif

