
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

#include "JB_Umbrella.hpp"
#include <random>
#include <iostream>
#include <math.h>

extern "C" {
	bool JB_dbl_IsNan (double x) {
		return std::isnan(x);
	}
	bool JB_dbl_IsInf (double x) {
		return std::isinf(x);
	}
	bool JB_f_IsNan (float x) {
		return std::isnan(x);
	}
	bool JB_f_IsInf (float x) {
		return std::isinf(x);
	}
	
    float JB_f_Clamp (float d, float min, float max) {
		return std_clamp(d, min, max);
    }
    
	vec4 JB_Vec4_ClampVec (vec4 Self, vec4 A, vec4 B) {
		// we can't rely on std::clamp... it seems to give bad results sometimes.
		// thats aside from reuseing clamp as a min/max func by passing (self, A, self)!!
		Self[0] = std_clamp(Self[0], A[0], B[0]);
		Self[1] = std_clamp(Self[1], A[1], B[1]);
		Self[2] = std_clamp(Self[2], A[2], B[2]);
		Self[3] = std_clamp(Self[3], A[3], B[3]);
		return Self;
	}
	
	vec4 JB_Vec4_Clamp (vec4 Self, float A, float B) {
		return JB_Vec4_ClampVec(Self, (vec4){A,A,A,A}, (vec4){B,B,B,B});
	}
    
	ivec4 JB_ivec4_ClampVec (ivec4 Self, ivec4 A, ivec4 B) {
		// we can't rely on std::clamp... it seems to give bad results sometimes.
		// thats without even reuseing clamp as min/max by passing (self, A, self)!!
		Self[0] = std_clamp(Self[0], A[0], B[0]);
		Self[1] = std_clamp(Self[1], A[1], B[1]);
		Self[2] = std_clamp(Self[2], A[2], B[2]);
		Self[3] = std_clamp(Self[3], A[3], B[3]);
		return Self;
	}
	
	ivec4 JB_ivec4_Clamp (ivec4 Self, int A, int B) {
		return JB_ivec4_ClampVec(Self, (ivec4){A,A,A,A}, (ivec4){B,B,B,B});
	}
	    

    float JB_f_Cluster (float x) {
        float im = 2.0*x-1.0; // y = (2x-1)^3+0.5
        float y = ((im*im*im)/2.0) + 0.5;
        return y;
    }

    float JB_f_IntPow (float x, u32 n) {
        float z = 1;
        float base = x;

        while (n) {
            if (n & 1) {
                z *= base;
            }
            n >>= 1;
            base *= base;
        }

        return z;
    }
    
//	static inline float atan_fma_approximation (float x) {
//		const float a1  =  0.99997726f / (M_PI*2);
//		const float a3  = -0.33262347f / (M_PI*2);
//		const float a5  =  0.19354346f / (M_PI*2);
//		const float a7  = -0.11643287f / (M_PI*2);
//		const float a9  =  0.05265332f / (M_PI*2);
//		const float a11 = -0.01172120f / (M_PI*2);
//
//		// Compute approximation using Horner's method
//		float x_sq = x*x;
//		return
//			x * fmaf(x_sq, fmaf(x_sq, fmaf(x_sq, fmaf(x_sq, fmaf(x_sq, a11, a9), a7), a5), a3), a1);
//	}
//    
//    // nevermind this... I can't get it to the same range as the other atan2
//	float JB_ATan2Fast (float x, float y) {
//		const float pi = 0.5;
//		const float pi_2 = 0.25;
//
//		// Ensure input is in [-1, +1]
//		bool swap = fabs(x) < fabs(y);
//		float atan_input = (swap ? x : y) / (swap ? y : x);
//		float res = atan_fma_approximation(atan_input);
//
//		if (swap)
//			res = copysignf(pi_2, atan_input) - res;
//
//		// Adjust the result depending on the input quadrant
//		return res + copysignf(pi, y) * (x < 0.0f);
//	}

	double JB_Pow10(double rz, int x) {
		x = Min(x, 350);
		x = Max(x,-350);
		if (x < 0) {
			for_(-x)
				rz *= 0.1;
		} else {
			for_(x)
				rz *= 10.0;
		}
		return rz;
	}
    
	ivec2 JB_f_Exponent (float f) {
		uint i = reinterpret_cast<uint&>(f);
		uint x = (i<<1) >> 24;
		int x2 = x - 127;
		return (ivec2){ x2, JB_uint_IsPow2(i<<9) };
	}
    
	float JB_f_Log (float f) {
		return std::log(f);
	}
	
	double JB_dbl_Log (double f) {
		return std::log(f);
	}
	

	ivec2 JB_F64_Exponent (double d) {
		uint64 i = reinterpret_cast<uint64&>(d);
		uint64 x = (i<<1) >> 53;
		int x2 = (int)x - 1023;
		return (ivec2){ x2, JB_u64_IsPow2(i<<12) };
	}
    
    u32 JB_uint_hash (u32 x) {
        x ^= x >> 16;
        x *= UINT32_C(0x7feb352d);
        x ^= x >> 15;
        x *= UINT32_C(0x846ca68b);
        x ^= x >> 16;
        return x;
    }

    u32 JB_uint_unhash (u32 x) {
        x ^= x >> 16;
        x *= UINT32_C(0x43021123);
        x ^= x >> 15 ^ x >> 30;
        x *= UINT32_C(0x1d69e2a5);
        x ^= x >> 16;
        return x;
    }

    u64 JB_uint64_hash (u64 x) {
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        x = x ^ (x >> 31);
        return x;
    }

    #ifndef AS_LIBRARY
    int JB_Math_Rnd32 () { //overkill for jeebox
        return rand();
    }
    #endif
}


