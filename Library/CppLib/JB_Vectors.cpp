
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2025 Theodore H. Smith.
*/

#include "JB_Math.h"
#include "JB_Vec4.h"
//#include <OpenCL/opencl.h>
// std::experimental::simd ?
// https://github.com/simd-everywhere/simde ?
// 
extern "C" {

#define iTau 0.15915494309f
#define Tau  6.2831853072f
#define iTau4 (vec4){iTau,iTau,iTau,iTau}
#define one vec4{1.0f,1.0f,1.0f,1.0f}
#define zero vec4{}


vec4 JB_vec4_Floor (vec4 x) {
	return (vec4){
		std::floorf(x[0]),
		std::floorf(x[1]),
		std::floorf(x[2]),
		std::floorf(x[3])
	};
}

vec4 JB_vec4_Round (vec4 x) {
	return (vec4){
		std::roundf(x[0]),
		std::roundf(x[1]),
		std::roundf(x[2]),
		std::roundf(x[3])
	};
}

float JB_vec4_Length (vec4 x) {
	return sqrtf(x[0]+x[1]+x[2]+x[3]);
}

vec4 JB_vec4_Sqrt (vec4 x) {
	return (vec4){
		std::sqrtf(x[0]),
		std::sqrtf(x[1]),
		std::sqrtf(x[2]),
		std::sqrtf(x[3])
	};
}

vec4 JB_vec4_InvSqrt (vec4 x) {
	return (vec4){
		1.0f/std::sqrtf(x[0]),
		1.0f/std::sqrtf(x[1]),
		1.0f/std::sqrtf(x[2]),
		1.0f/std::sqrtf(x[3])
	};
}


vec4 JB_vec4_Exp (vec4 x) {
	return (vec4){
		std::expf(x[0]),
		std::expf(x[1]),
		std::expf(x[2]),
		std::expf(x[3])
	};
}

vec4 JB_vec4_Log (vec4 x) {
	return (vec4){
		std::logf(x[0]),
		std::logf(x[1]),
		std::logf(x[2]),
		std::logf(x[3])
	};
}

vec4 JB_vec4_Exp2 (vec4 x) {
	return (vec4){
		std::exp2f(x[0]),
		std::exp2f(x[1]),
		std::exp2f(x[2]),
		std::exp2f(x[3])
	};
}

vec4 JB_vec4_Log2 (vec4 x) {
	return (vec4){
		std::log2f(x[0]),
		std::log2f(x[1]),
		std::log2f(x[2]),
		std::log2f(x[3])
	};
}

vec4 JB_vec4_Unsin (vec4 x) {
	return (vec4){
		std::asinf(x[0]),
		std::asinf(x[1]),
		std::asinf(x[2]),
		std::asinf(x[3])
	} * iTau4;
}

vec4 JB_vec4_Uncos (vec4 x) {
	return (vec4){
		std::acosf(x[0]),
		std::acosf(x[1]),
		std::acosf(x[2]),
		std::acosf(x[3])
	} * iTau4;
}

vec4 JB_vec4_UnTan (vec4 x, vec4 y) {
	return (vec4){
		std::atanf(x[0]),
		std::atanf(x[1]),
		std::atanf(x[2]),
		std::atanf(x[3])
	} * iTau;
}

vec4 JB_vec4_Sine (vec4 x) {
	x*=Tau;
	return (vec4){
		std::sinf(x[0]),
		std::sinf(x[1]),
		std::sinf(x[2]),
		std::sinf(x[3])
	};
}

vec4 JB_vec4_Cos (vec4 x) {
	x*=Tau;
	return (vec4){
		std::cosf(x[0]),
		std::cosf(x[1]),
		std::cosf(x[2]),
		std::cosf(x[3])
	};
}

vec4 JB_vec4_Tan (vec4 x) {
	x*=Tau;
	return (vec4){
		std::tanf(x[0]),
		std::tanf(x[1]),
		std::tanf(x[2]),
		std::tanf(x[3])
	};
}

vec4 JB_vec4_pow (vec4 x, vec4 y) {
	return (vec4){
		std::powf(x[0], y[0]),
		std::powf(x[1], y[1]),
		std::powf(x[2], y[2]),
		std::powf(x[3], y[3])
	};
}

vec4 JB_vec4_mod (vec4 x, vec4 y) {
	return (vec4){
		std::fmodf(x[0], y[0]),
		std::fmodf(x[1], y[1]),
		std::fmodf(x[2], y[2]),
		std::fmodf(x[3], y[3])
	};
}

vec4 JB_vec4_CopySign (vec4 x, vec4 y) {
	return (vec4){
		std::copysignf(x[0], y[0]),
		std::copysignf(x[1], y[1]),
		std::copysignf(x[2], y[2]),
		std::copysignf(x[3], y[3])
	};
}

vec4 JB_vec4_Mix (vec4 x, vec4 low, vec4 high) {
	return low + (x * (high - low));
}

vec4 JB_Vec4_ClampVec (vec4 Self, vec4 A, vec4 B) {
	// we can't rely on std::clamp... it seems to give bad results sometimes.
	// thats aside from reuseing clamp as a min/max func by passing (self, A, self)!!
	// try to use std::clamp... later! maybe it can work?
	Self[0] = std_clamp(Self[0], A[0], B[0]);
	Self[1] = std_clamp(Self[1], A[1], B[1]);
	Self[2] = std_clamp(Self[2], A[2], B[2]);
	Self[3] = std_clamp(Self[3], A[3], B[3]);
	return Self;
}

vec4 JB_vec4_SmoothStep (vec4 x, vec4 low, vec4 high) {
	vec4 t = JB_Vec4_ClampVec((x - low) / (high - low), zero, one);
	return t * t * (3.0 - 2.0 * t);
}

vec4 JB_Vec4_Clamp (vec4 Self, float A, float B) {
	return JB_Vec4_ClampVec(Self, (vec4){A,A,A,A}, (vec4){B,B,B,B});
}

}
