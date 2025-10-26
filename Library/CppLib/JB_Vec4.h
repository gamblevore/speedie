

#ifndef __JB_VEC4__
#define __JB_VEC4__


extern "C" {
vec4 JB_Vec4_Abs		(vec4 x);
vec4 JB_vec4_Floor		(vec4 x);
vec4 JB_vec4_Round		(vec4 x);
float JB_vec4_Length	(vec4 x);
float JB_vec4_Dot		(vec4 x, vec4 y);
vec4 JB_vec4_Cross		(vec4 x, vec4 y);
vec4 JB_vec4_InvSqrt	(vec4 x);
vec4 JB_vec4_Sqrt		(vec4 x);
vec4 JB_vec4_Exp		(vec4 x);
vec4 JB_vec4_Log		(vec4 x);
vec4 JB_vec4_Exp2		(vec4 x);
vec4 JB_vec4_Log2		(vec4 x);
vec4 JB_vec4_Unsin		(vec4 x);
vec4 JB_vec4_Uncos		(vec4 x);
vec4 JB_vec4_UnTan		(vec4 x, vec4 y);
vec4 JB_vec4_Sine		(vec4 x);
vec4 JB_vec4_Cos		(vec4 x);
vec4 JB_vec4_Tan		(vec4 x);
vec4 JB_vec4_pow		(vec4 x, vec4 y);
vec4 JB_vec4_mod		(vec4 x, vec4 y);
vec4 JB_vec4_CopySign	(vec4 x, vec4 y);
vec4 JB_vec4_Mix		(vec4 x, vec4 low, vec4 high);
vec4 JB_vec4_SmoothStep	(vec4 x, vec4 low, vec4 high);
vec4 JB_Vec4_ClampFloat	(vec4 Self, float A, float B);
vec4 JB_Vec4_Clamp		(vec4 Self, vec4 A, vec4 B);
}

#endif

