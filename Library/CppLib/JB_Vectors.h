
/*
	Copyright (C) 2015 Theodore H. Smith.
*/

#ifndef AS_LIBRARY
#ifndef __JB_Vectors__
#define __JB_Vectors__
#include  <nmmintrin.h>

extern "C" {

bool SimdDetectAVX();
bool SimdDetectSSE42();
inline float  __attribute__((__always_inline__))  JB_IntAsFloat (int I) {
    return *((float*)(&I));
}
inline int  __attribute__((__always_inline__)) JB_FloatAsInt (float F) {
    return *((int*)(&F));
}

//  // 0x1B = 00 01 10 11... reverses the order of the elements
#define JB_IntVec_Shuf(w,z,y,x) ( ((x) << 6) | ((y) << 4) | ((z) << 2) | ((w) << 0) )

}

#endif
#endif
