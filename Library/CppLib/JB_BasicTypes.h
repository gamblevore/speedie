
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
    typedef signed char         int8;
    typedef signed char         s8;
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

#ifdef ENV64BIT
    typedef long long int IntPtr;
    typedef unsigned long long int UintPtr;
#else
    typedef int IntPtr;
    typedef unsigned int UintPtr;
#endif





#ifndef kPlatformEndian
	#define kPlatformEndian 0
#endif

// probably should move all this into the string header... utf-8 isnt needed elsewhere
#if kPlatformEndian == 0
    #define kWrongUTF16			/*Becomes*/		(16+1)
	#define kUTF16BBOM			/*Becomes*/		0xFFFE
	#define kUTF16LBOM			/*Becomes*/		0xFEFF
	#define kUTF32LBOM			/*Becomes*/		0x0000FEFF
	#define kUTF32BBOM			/*Becomes*/		0xFFFE0000
#elif kPlatformEndian == 1
    #define kWrongUTF16			/*Becomes*/		(16)
	#define kUTF16BBOM			/*Becomes*/		0xFEFF
	#define kUTF16LBOM			/*Becomes*/		0xFFFE
	#define kUTF32LBOM			/*Becomes*/		0xFFFE0000
	#define kUTF32BBOM			/*Becomes*/		0x0000FEFF
#endif


#define kUTF8BOM			/*Becomes*/		0xEFBBBF
#define kUTF8BOM1			/*Becomes*/		0xEF
#define kUTF8BOM2			/*Becomes*/		0xBB
#define kUTF8BOM3			/*Becomes*/		0xBF
#define kLast3ByteMask		/*Becomes*/		0xFFFFFF00
#define kUTF8FirstMin						-62 /*A magic number! don't change it!*/

enum {
	kEncAscii = 0,
	kEncBytes = 0,
	kEncUTF8 = 8,
	kEncUTF16 = 16,
    kEncUTF32 = 32,
    kEncBE = 1,
    kEncUTF = kEncUTF8|kEncUTF16|kEncUTF32,
    kEncUTF8_BE = kEncUTF8|kEncBE,
    kEncUTF_BE = kEncUTF| kEncBE,
};



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

