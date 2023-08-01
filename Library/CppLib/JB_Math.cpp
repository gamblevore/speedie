
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

#include "JB_Umbrella.hpp"
#include <random>
#include <iostream>
#include <math.h>

extern "C" {
    double JB_Dlb_Max(double A, double B) {
        return fmax(A, B);
    }
    
    float fclampf (float d, float min, float max) {
        const float t = d < min ? min : d;
        return t > max ? max : t;
    }

    float JB_fCluster (float x) {
        float im = 2.0*x-1.0; // y = (2x-1)^3+0.5
        float y = ((im*im*im)/2.0) + 0.5;
        return y;
    }

    float JB_PowInt(float x, u32 n) {
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
    
    /*
    theta1=0.1963 * r^3 - 0.9817 * r + pi/4 (2a)
    theta2=0.1963 * r^3 - 0.9817 * r + 3*pi/4 (4a)
    */
    // could replace our arctan3 with this one... seems fair?
    float arctan3 (float y, float x) {
    //    http://dspguru.com/dsp/tricks/fixed-point-atan2-with-self-normalization/
        const float pio4 = 0.7853981634; //pi/4
        float abs_y = fabsf(y) + 1e-10;      // kludge to prevent 0/0 condition
        float r; float angle;
        if (x >= 0) {
            r = (x - abs_y) / (x + abs_y);
            angle = 0.1963 * (r*r*r) - 0.9817 * r + pio4;    // (2a)
        } else {
            r = (x + abs_y) / (abs_y - x);
            angle = 0.1963 * (r*r*r) - 0.9817 * r + 3*pio4;  // (4a)
        }
        if (y < 0) {
            return -angle;     // negate if in quad III or IV
        } else {
            return angle;
        }
    }

	double JB_Pow10(int x) {
		double rz = 1.0;
		for_(x) {
			rz *= 10.0;
		}
		return rz;
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
    int JB_Math_Rnd32() { //overkill for jeebox
        return rand();
    }
    #endif
    
    int JB_Rand() {
        static int Value = 123;
        Value = JB_uint_hash(Value);
        return Value;
    }
}


