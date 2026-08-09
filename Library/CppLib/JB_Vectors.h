
/*
	Copyright (C) 2015 Theodore H. Smith.
*/

#ifndef AS_LIBRARY
#ifndef __JB_Vectors__
#define __JB_Vectors__

extern "C" {

inline float  __attribute__((__always_inline__))  JB_IntAsFloat (int I) {
    return *((float*)(&I));
}
inline int  __attribute__((__always_inline__)) JB_FloatAsInt (float F) {
    return *((int*)(&F));
}

}

#endif
#endif
