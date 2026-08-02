
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
	vec4 A = vec4{(float)(data[0]), (float)(data[1]), (float)(data[2]), (float)(data[3])};
//	vec4 B = (vec4)(JB_ivec4_Load(data)); // doesn't cast elements... just bit-casts
	return A;
};

#endif /* __JB_VECTOR__ */


