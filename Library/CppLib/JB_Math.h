

#ifndef __JB_MATH__
#define __JB_MATH__

#include "JB_Umbrella.h"

extern "C" {
    int JB_Math_Rnd32();
    float fclampf (float d, float min, float max);
    float JB_fCluster (float x);
    u32 JB_uint_hash (u32 x);
    u32 JB_uint_unhash (u32 x);
    u64 JB_uint64_hash (u64 x);
     
    inline float JB_f__max () {
        return __FLT_MAX__;
    }
    inline float JB_f__nan () {
        return __builtin_nanf("");
    }


#if __has_builtin(__builtin_rotateleft64)
	inline u64 JB_u64_RotL(u64 x, u64 N) {
		return __builtin_rotateleft64(x, N);
	}
	inline u64 JB_u64_RotR(u64 x, u64 N) {
		return __builtin_rotateright64(x, N);
	}
	inline u32 JB_u32_RotL(u32 x, u32 N) {
		return __builtin_rotateleft32(x, N);
	}
	inline u32 JB_u32_RotR(u32 x, u32 N) {
		return __builtin_rotateright32(x, N);
	}
#else
	inline u64 JB_u64_RotL(u64 x, u64 N) {
		const u64 width = sizeof(x)*8;
		return (x << N) | (x >> (width-N));
	}
	inline u64 JB_u64_RotR(u64 x, u64 N) {
		const u64 width = sizeof(x)*8;
		return (x >> N) | (x << (width-N));
	}
	inline u32 JB_u32_RotL(u32 x, u32 N) {
		const u32 width = sizeof(x)*8;
		return (x << N) | (x >> (width-N));
	}
	inline u32 JB_u32_RotR(u32 x, u32 N) {
		const u32 width = sizeof(x)*8;
		return (x >> N) | (x << (width-N));
	}
#endif

}

#endif

