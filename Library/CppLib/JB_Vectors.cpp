
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2013 Theodore H. Smith.
*/

#ifndef AS_LIBRARY
#include "JB_Umbrella.hpp"
#include <cpuid.h>

extern "C" {

bool SimdDetectAVX() {
	return true; // assume true for now...
}
bool SimdDetectAVX2() {
	return true; // same
}
bool SimdDetectAVX512() {
	return true; // same
}
bool SimdDetectSSE42() {
	return true; // same
}

} // 

#else

// stop linker errors.
extern "C" void Stub_JB_Vectors () {
    
}

#endif

