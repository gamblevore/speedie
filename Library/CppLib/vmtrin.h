extern "C" {

float JB_f_Fract(float Self);

float JB_f_Length(float Self);

float JB_f_Unsin(float Self);

float JB_f_Uncos(float Self);

float JB_f_UnTan(float Self, float Y);

float JB_f_Sine(float Self);

float JB_f_Cos(float Self);

float JB_f_Tan(float Self);

float JB_f_FloatMix(float Self, float A, float B);

float JB_f_SmoothStep(float Self, float Low, float High);

vec4 JB_vec4_Fract(vec4 Self);

vec4 JB_vec4_Floor(vec4 Self);

vec4 JB_vec4_Round(vec4 Self);

float JB_vec4_Length(vec4 Self);

vec4 JB_vec4_Abs(vec4 Self);

vec4 JB_vec4_Pow(vec4 Self, vec4 Other);

vec4 JB_vec4_Sqrt(vec4 Self);

vec4 JB_vec4_Exp(vec4 Self);

vec4 JB_vec4_Log(vec4 Self);

vec4 JB_vec4_Exp2(vec4 Self);

vec4 JB_vec4_Log2(vec4 Self);

vec4 JB_vec4_Unsin(vec4 Self);

vec4 JB_vec4_Uncos(vec4 Self);

vec4 JB_vec4_UnTan(vec4 Self, vec4 Y);

vec4 JB_vec4_Sine(vec4 Self);

vec4 JB_vec4_Cos(vec4 Self);

vec4 JB_vec4_Tan(vec4 Self);

vec4 JB_vec4_CopySign(vec4 Self, vec4 From);

vec4 JB_vec4_Clamp(vec4 Self, vec4 Low, vec4 High);

vec4 JB_vec4_Mix(vec4 Self, vec4 A, vec4 B);

vec4 JB_vec4_SmoothStep(vec4 Self, vec4 Low, vec4 High);

float JB_vec4_Dot(vec4 Self, vec4 Other);

vec4 JB_vec4_Cross(vec4 Self, vec4 Other);

vec4 JB_vec4_Reflect(vec4 Self, vec4 Plane);

float JB_vec4_Sum(vec4 Self, int Which);

}