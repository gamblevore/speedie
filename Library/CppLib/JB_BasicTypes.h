
#include <stdlib.h>
#include <stdio.h>

// need to include std headers first, as some use these words "u32", "u16" :(

#ifndef __JB_TYPES__
#define __JB_TYPES__

#include "JB_VectorTypes.h"
#ifdef nil
	#undef nil
#endif
#define nil 0

#ifndef _cstring
    typedef const char*         _cstring;
#endif
#ifndef _voidptr
    typedef void*               _voidptr;
#endif

#ifndef u64
    typedef unsigned long long  u64; 
#endif
#ifndef uint64
    typedef unsigned long long  uint64; 
#endif
#ifndef s64
    typedef long long           s64; 
#endif
#ifndef int64
    typedef long long           int64; 
#endif

#ifndef u32
    typedef unsigned int        u32;
#endif
#ifndef uint
    typedef unsigned int        uint;
    typedef unsigned int        u32;
#endif
#ifndef Fixed32
    typedef unsigned int        Fixed32;
#endif

#ifndef s16
    typedef short               s16; 
#endif
#ifndef u16
    typedef unsigned short      u16; 
#endif

#ifndef uint8
    typedef unsigned char       uint8;
    typedef unsigned char       u8;
#endif
#ifndef int8
    typedef char         		int8;
#endif

typedef unsigned char			byte;
typedef u32						CodePoint;


// nice simple time system... gives us almost 9 million years and a decent (64 thousand ticks per second) precision...
#define	kTicksPerSecond (2^16)
typedef int64					Date;



#ifdef TARGET_WIN32
	#define NativeFileChar u16
	#define NativeFileChar2 u16
	#define NFS_ L
#else
	#define NativeFileChar uint8
	#define NativeFileChar2 char
	#define NFS_ 
#endif


#if _WIN64 || __x86_64__ || __ppc64__ || _M_ARM64 || __powerpc64__ || __ppc64__ || _ARCH_PPC64 || __ia64 || _M_IA64 || __aarch64__
    #define ENV64BIT
#else
    #define ENV32BIT
#endif


#define __CPU_PPC__ 8
#define __CPU_INT__ 4 // intel
#define __CPU_ARM__ 2
#define __CPU_SPD__ 1

#define __PLATFORM_WIN__ 8
#define __PLATFORM_LINUX__ 4
#define __PLATFORM_OSX__ 2
#define __PLATFORM_SPD__ 1

#if defined(__APPLE__) && defined(__MACH__)
	#pragma message("Plat: OSX")
	#define __PLATFORM_CURR__ __PLATFORM_OSX__
#elif __unix__
	#pragma message("Plat: Linux")
	#define __PLATFORM_CURR__ __PLATFORM_LINUX__
	#ifndef __linux__ 
		#define __linux__
	#endif
#elif __WIN32__ || _WIN64
	#pragma message("Plat: Windows")
	#define __PLATFORM_CURR__ __PLATFORM_WIN__
	#define __WIN32__
#endif


#if _M_X86 || __i386__ || __x86_64__
//	#pragma message("CPU: Intel")
	#define __CPU_TYPE__ __CPU_INT__
#elif __arm__ || __aarch64__ || _M_ARM64
//	#pragma message("CPU: ARM")
	#define __CPU_TYPE__ __CPU_ARM__
#elif __ppc__ || __powerpc64__ || __ppc64__ || _ARCH_PPC64
//	#pragma message("CPU: PPC")
	#define __CPU_TYPE__ __CPU_PPC__
#elif __spd64__ || __spd32__
//	#pragma message("CPU: Speedie")
	#define __CPU_TYPE__ __CPU_SPD__
#else
//	#pragma message("CPU: None?")
	#define __CPU_TYPE__ 0
#endif

#ifdef ENV64BIT
    typedef long long int IntPtr;
    typedef unsigned long long int UintPtr;
#else
    typedef int IntPtr;
    typedef unsigned int UintPtr;
#endif


#ifndef __has_builtin
	#define __has_builtin(x) (false)
#endif



#ifndef kPlatformEndian
	#define kPlatformEndian 0
#endif


#define kMaxint								2147483647


/* used for testing if it is ascii! */
#define k4HighBits							0x80808080
#define Max(a, b) (((a) > (b)) ? (a) : (b))
#define Min(a, b) (((a) < (b)) ? (a) : (b))


#ifndef FieldOffset
	#define FieldOffset(type, field) (int)(&((type *) 0)->field)
#endif
#define CountCArray(x) (sizeof(x)/sizeof(x[0]))


#define __lib__ __attribute__ ((visibility ("default")))


#endif /* __JB_TYPES__ */

