
#ifndef __JB_VECTOR__
#define __JB_VECTOR__

typedef unsigned int	uvec4	__attribute__ ((vector_size (16)));
typedef int				ivec4	__attribute__ ((vector_size (16)));
typedef float			vec4	__attribute__ ((vector_size (16)));
typedef unsigned char	bytevec4 __attribute__ ((vector_size (4), aligned (4))); // shouldn't they all be aligned?

typedef int				ivec3	__attribute__ ((vector_size (16)));
typedef float			vec3	__attribute__ ((vector_size (16)));

typedef int				ivec2	__attribute__ ((vector_size (8)));
typedef float			vec2	__attribute__ ((vector_size (8)));

inline ivec4 JB_ivec4_Load(unsigned char* data) {
	return ivec4{data[0], data[1], data[2], data[3]};
};
inline vec4 JB_vec4_Load(unsigned char* data) {
	return vec4{(float)(data[0]), (float)(data[1]), (float)(data[2]), (float)(data[3])};
};



//struct vec3 {
//	float S[3];
//	vec3() {S[0]=0;S[1]=0;S[2]=0;}
//	vec3(float a, float b, float c) {S[0]=a;S[1]=b;S[2]=c;}
//	vec3(float a) {S[0]=a;S[1]=a;S[2]=a;}
//	vec3(vec4 a) {S[0]=a[0];S[1]=a[1];S[2]=a[2];}
//
//	float& operator [] (int n) { return S[n]; }
//    explicit operator vec4() const { return vec4{S[0], S[1], S[2], 0.0f}; }
//    
//	vec3 operator * (float n) { return vec4(*this)*n; }
//	vec3 operator * (vec3 n)  { return vec4(*this)*vec4(n); }
//	vec3 operator / (float n) { return vec4(*this)/n; }
//	vec3 operator / (vec3 n)  { return vec4(*this)/vec4(n); }
//	vec3 operator + (float n) { return vec4(*this)+n; }
//	vec3 operator + (vec3 n)  { return vec4(*this)+vec4(n); }
//	vec3 operator - (float n) { return vec4(*this)-n; }
//	vec3 operator - (vec3 n)  { return vec4(*this)-vec4(n); }
//};
//
//inline vec3 operator * (float L, vec3 R) {return R * L;}
//inline vec3 operator / (float L, vec3 R) {return vec3(L) / R;}
//inline vec3 operator - (float L, vec3 R) {return vec3(L) - R;}
//inline vec3 operator + (float L, vec3 R) {return R + L;}


//struct ivec3 {
//	int S[3];
//	ivec3() {S[0]=0;S[1]=0;S[2]=0;}
//	ivec3(int a, int b, int c) {S[0]=a; S[1]=b; S[2]=c;}
//	ivec3(int a) {S[0]=a; S[1]=a; S[2]=a;}
//	ivec3(ivec4 a) {S[0]=a[0]; S[1]=a[1]; S[2]=a[2];}
//
//	int& operator [] (int n) { return S[n]; }
//    explicit operator ivec4() const { return ivec4{S[0], S[1], S[2], 0}; }
//
//	ivec3 operator >> (int n)   { return {S[0]>>n,    S[1]>>n,    S[2]>>n};    }
//	ivec3 operator >> (ivec3 n) { return {S[0]>>n[0], S[1]>>n[1], S[2]>>n[2]}; }
//	ivec3 operator << (int n)   { return {S[0]<<n,    S[1]<<n,    S[2]<<n};    }
//	ivec3 operator << (ivec3 n) { return {S[0]<<n[0], S[1]<<n[1], S[2]<<n[2]}; }
//	ivec3 operator * (int n)    { return ivec4(*this)*n;        }
//	ivec3 operator * (ivec3 n)  { return ivec4(*this)*ivec4(n); }
//	ivec3 operator / (int n)    { return ivec4(*this)/n;        }
//	ivec3 operator / (ivec3 n)  { return ivec4(*this)/ivec4(n); }
//	ivec3 operator + (int n)    { return ivec4(*this)+n;        }
//	ivec3 operator + (ivec3 n)  { return ivec4(*this)+ivec4(n); }
//	ivec3 operator - (int n)    { return ivec4(*this)-n;        }
//	ivec3 operator - (ivec3 n)  { return ivec4(*this)-ivec4(n); }
//};
//
//inline ivec3 operator * (int L, ivec3 R) {return R * L;}
//inline ivec3 operator / (int L, ivec3 R) {return ivec3(L) / R;}
//inline ivec3 operator - (int L, ivec3 R) {return ivec3(L) - R;}
//inline ivec3 operator + (int L, ivec3 R) {return R + L;}


#endif /* __JB_VECTOR__ */


