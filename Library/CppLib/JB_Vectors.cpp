
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2025 Theodore H. Smith.
*/

#include "JB_Math.h"
#include "JB_Vec4.h"

extern "C" {

#include "vmtrin.h"


#ifndef __H__
	#define __H__
#endif
#define iTau	0.15915494309f
#define Tau		6.2831853072f
#define one		vec4{1.0f,1.0f,1.0f,1.0f}
#define zero	vec4{}

#define vf1(name, x)					\
  (vec4) {  						\
	std::name(x[0]),				\
	std::name(x[1]),				\
	std::name(x[2]),				\
	std::name(x[3]) 				\
}

#define vf2(name, x, y)				\
  (vec4) {  						\
	std::name(x[0], y[0]),			\
	std::name(x[1], y[1]),			\
	std::name(x[2], y[2]),			\
	std::name(x[3], y[3]) 			\
}



__H__ vec4 JB_vec4_Round (vec4 x) {
	#if __has_builtin(__builtin_elementwise_roundeven)
		return __builtin_elementwise_roundeven(x);
	#else
		return vf1(roundf, x);
	#endif
}

__H__ vec4 JB_vec4_Abs (vec4 x) {
	#if __has_builtin(__builtin_elementwise_abs)
		return __builtin_elementwise_abs(x);
	#else
		return vf2(fabsf, x);
	#endif
}

__H__ vec4 JB_vec4_Floor (vec4 x) {
	#if __has_builtin(__builtin_elementwise_floor)
		return __builtin_elementwise_floor(x);
	#else
		return vf1(floorf, x);
	#endif
}

__H__ vec4 JB_vec4_Sqrt (vec4 x) {
	#if __has_builtin(__builtin_elementwise_sqrt)
		return __builtin_elementwise_sqrt(x);
	#else
		return vf1(sqrtf, x);
	#endif
}

__H__ vec4 JB_vec4_Exp (vec4 x) {
	#if __has_builtin(__builtin_elementwise_exp)
		return __builtin_elementwise_exp(x);
	#else
		return vf1(expf, x);
	#endif
}

__H__ vec4 JB_vec4_Log (vec4 x) {
	#if __has_builtin(__builtin_elementwise_log)
		return __builtin_elementwise_log(x);
	#else
		return vf1(logf, x);
	#endif
}

__H__ vec4 JB_vec4_Exp2 (vec4 x) {
	#if __has_builtin(__builtin_elementwise_exp2)
		return __builtin_elementwise_exp2(x);
	#else
		return vf1(exp2f, x);
	#endif
}

__H__ vec4 JB_vec4_Log2 (vec4 x) {
	#if __has_builtin(__builtin_elementwise_log2)
		return __builtin_elementwise_log2(x);
	#else
		return vf1(log2f, x);
	#endif
}

__H__ vec4 JB_vec4_Unsin (vec4 x) {
	#if __has_builtin(__builtin_elementwise_asin)
		return __builtin_elementwise_asin(x) * iTau;
	#else
		return vf1(asinf, x) * iTau;
	#endif
}

__H__ vec4 JB_vec4_Uncos (vec4 x) {
	#if __has_builtin(__builtin_elementwise_acos)
		return __builtin_elementwise_acos(x) * iTau;
	#else
		return vf1(acosf, x) * iTau;
	#endif
}

__H__ vec4 JB_vec4_UnTan (vec4 x, vec4 y) {
	#if __has_builtin(__builtin_elementwise_atan2)
		return __builtin_elementwise_atan2(x, y) * iTau;
	#else
		return vf2(atan2f, x, y) * iTau;
	#endif
}

__H__ vec4 JB_vec4_Sine (vec4 x) {
	#if __has_builtin(__builtin_elementwise_sin)
		return __builtin_elementwise_sin(x) * Tau;
	#else
		return vf1(sinf, x) * Tau;
	#endif
}

__H__ vec4 JB_vec4_Cos (vec4 x) {
	#if __has_builtin(__builtin_elementwise_cos)
		return __builtin_elementwise_cos(x) * Tau;
	#else
		return vf1(cosf, x) * Tau;
	#endif
}

__H__ vec4 JB_vec4_Tan (vec4 x) {
	#if __has_builtin(__builtin_elementwise_tan)
		return __builtin_elementwise_tan(x) * Tau;
	#else
		return vf1(tanf, x) * Tau;
	#endif
}

__H__ vec4 JB_vec4_Pow (vec4 x, vec4 y) {
	#if __has_builtin(__builtin_elementwise_pow)
		return __builtin_elementwise_pow(x, y);
	#else
		return vf2(powf, x, y);
	#endif
}

__H__ vec4 JB_vec4_Mod (vec4 x, vec4 y) {
	#if __has_builtin(__builtin_elementwise_fmod)
		return __builtin_elementwise_fmod(x, y);
	#else
		return vf2(fmodf, x, y);
	#endif
}

__H__ vec4 JB_vec4_CopySign (vec4 x, vec4 y) {
	#if __has_builtin(__builtin_elementwise_copysign)
		return __builtin_elementwise_copysign(x, y);
	#else
		return vf2(copysignf, x, y);
	#endif
}

__H__ vec4 JB_vec4_Max (vec4 x, vec4 y) {
	#if __has_builtin(__builtin_elementwise_max)
		return __builtin_elementwise_max(x, y);
	#else
		return vf2(fmaxf, x, y);
	#endif
}

__H__ vec4 JB_vec4_Min (vec4 x, vec4 y) {
	#if __has_builtin(__builtin_elementwise_min)
		return __builtin_elementwise_min(x, y);
	#else
		return vf2(fminf, x, y);
	#endif
}

__H__ vec4 JB_vec4_Fract (vec4 x) {
	return x - JB_vec4_Floor(x);
}

__H__ vec4 JB_vec4_InvSqrt (vec4 x) {
	return 1.0f/JB_vec4_Sqrt(x);
}

__H__ vec4 JB_vec4_Inv (vec4 x) {
	return 1.0f/x;
}

__H__ vec4 JB_vec4_Mix (vec4 x, vec4 low, vec4 high) {
	return low + (x * (high - low));
}

__H__ float JB_vec4_Sum (vec4 x, int Which) { // perhaps this would be better...
	float r = x[0]*!(Which&1) + x[1]*!(Which&2);
	r += x[2]*!(Which&4) + x[3]*!(Which&8);
	return r;
}

__H__ float JB_vec4_Dot (vec4 x, vec4 y) {
	return JB_vec4_Sum(x * y);
}

__H__ float JB_vec4_Length (vec4 x) {
	return sqrtf(JB_vec4_Dot(x,x));
}

__H__ vec4 JB_vec4_Cross (vec4 x, vec4 y) {
	return (vec4){
		x[1]*y[2]-y[1]*x[2],
		x[2]*y[0]-y[2]*x[0],
		x[0]*y[1]-y[0]*x[1],
		0.0f
	};
}

__H__ vec4 JB_vec4_Normal (vec4 x) {
	return x / JB_vec4_Length(x);
}

__H__ vec4 JB_vec4_Reflect (vec4 x, vec4 y) {
	return x - 2.0f * JB_vec4_Dot(y, x) * y;
}

__H__ vec4 JB_vec4_Clamp (vec4 x, vec4 y, vec4 z) {
	return (vec4) {
		std::clamp(x[0], y[0], z[0]),
		std::clamp(x[1], y[1], z[1]),
		std::clamp(x[2], y[2], z[2]),
		std::clamp(x[3], y[3], z[3])
	};
}

__H__ vec4 JB_vec4_ClampFloat (vec4 Self, float A, float B) {
	return JB_vec4_Clamp(Self, (vec4){A,A,A,A}, (vec4){B,B,B,B});
}

__H__ vec4 JB_vec4_SmoothStep (vec4 x, vec4 low, vec4 high) {
	vec4 t = JB_vec4_Clamp((x - low) / (high - low), zero, one);
	return t * t * (3.0 - 2.0 * t);
}


}

