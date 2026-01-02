

#ifndef __JB_MATH__
#define __JB_MATH__

#include "JB_Umbrella.h"

extern "C" {
	int    JB_Math_Rnd32		();
	float  JB_f_Clamp			(float d, float min, float max);
	ivec4  JB_ivec4_ClampVec	(ivec4 Self, ivec4 A, ivec4 B);
	ivec4  JB_ivec4_Clamp		(ivec4 Self, int A, int B);
	float  JB_f_Cluster			(float x);
	u32    JB_uint_hash			(u32 x);
	double JB_Pow10				(double rz, int x);
	u32    JB_uint_unhash		(u32 x);
	u64    JB_uint64_hash		(u64 x);
	ivec2  JB_f_Exponent		(float x);
	float  JB_f_Log 			(float x);
	double JB_dbl_Log			(double x);
	ivec2  JB_F64_Exponent		(double x);
	
	
	inline bool JB_u64_IsPow2 (uint64 Self) {
		return (Self!=0) & ((Self & (Self - 1)) == 0);
	}

	inline bool JB_uint_IsPow2 (uint Self) {
		return (Self!=0) & ((Self & (Self - 1)) == 0);
	}

	inline double JB_int64_AsFloat (int64 Self) {
		return reinterpret_cast<double&>(Self);	
	}

	inline float JB_int_AsFloat (int Self) {
		return reinterpret_cast<float&>(Self);	
	}

	inline int JB_f_AsInt (float Self) {
		return reinterpret_cast<int&>(Self);	
	}

	inline int64 JB_dbl_AsInt (double Self) {
		return reinterpret_cast<int64&>(Self);	
	}
     
    inline float JB_f__max () {
        return __FLT_MAX__;
    }
    inline float JB_f__nan () {
        return __builtin_nanf("");
    }

#if __PLATFORM_CURR__ != __PLATFORM_OSX__
	// seems to not exist outside of OSX... just yet
	#define __sinpif(x)			sinf((x)*M_PI)
	#define __cospif(x)			cosf((x)*M_PI)
	#define __tanpif(x)			tanf((x)*M_PI)
	#define __sincospif(x,y,z)	sincosf((x)*M_PI, y, z)
#endif

}

#include <algorithm>
template <typename T>
constexpr T std_clamp (T v, T lo, T hi) {
	if (v < lo)
		return lo;
	if (v > hi)
		return hi;
	return v;
}
template <typename T>
constexpr T std_min (T a, T b) {
	if (a > b)
		return b;
	return a;
}
template <typename T>
constexpr T std_max (T a, T b) {
	if (a < b)
		return b;
	return a;
}


#endif

