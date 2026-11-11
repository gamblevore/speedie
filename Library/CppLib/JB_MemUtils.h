

#ifndef __JB_MEM_UTILS__
#define __JB_MEM_UTILS__

#include <string.h>
#include <bit>
#if __PLATFORM_CURR__ == __PLATFORM_OSX__
    #include <malloc/malloc.h>
#else
    #include <stdlib.h>
    #include <malloc.h>
#endif


#ifndef kUltraAlloc
	//#define kUltraAlloc (1ull<<35) // 32GB
	#define kUltraAlloc (1ull<<31) // 2GB
#endif


#if kUltraAlloc <= 1ull<<32 // fits in 4GB, no need to do pointer shifting.
	#define kUltraShift 0	// one less instruction!
#else
	#define kUltraShift 3
#endif

#define JB_Squash uint
struct JB_Object;

inline JB_Object* JB_UnSquash (uint64 Base, JB_Squash Q) {
	return (JB_Object*)(Base | ((uint64)Q << kUltraShift));
}
inline JB_Object* JB_UnSquash (JB_Object* Self, JB_Squash Q) {
	return JB_UnSquash(((uint64)Self)&~(kUltraAlloc-1), Q);
}
inline uint64 JB_SquashBase (JB_Object* Self) {
	return ((uint64)Self)&~(kUltraAlloc-1);
}
inline JB_Squash JB_Squeeze (JB_Object* Self) {
	return ((uint64)Self)>>kUltraShift;
}




#ifdef JB_DEBUG_ON
    #define JBSanity( a ) // nothing for now
    #define JB_DEBUG(x) x
    #define JB_NOTDEBUG( a )
    #include <assert.h>
#else
    #define JBSanity( a )
    #define JB_NOTDEBUG( a ) a
    #define JB_DEBUG(x)
#endif


#ifdef DEBUG
	extern "C" bool CanASMBKPT;
	#if __has_builtin(__builtin_debugtrap)
		#define debugger if (CanASMBKPT) __builtin_debugtrap()
	#else
		#if __CPU_TYPE__ == __CPU_INT__
			#define debugger if (CanASMBKPT) __asm__("int3")
		#else
			#define debugger if (CanASMBKPT) std::raise(SIGINT)
		#endif
	#endif
    #define dbgexpect(test)  if  (!(test)) {debugger; return;} // int3 works in xcode but not in releasebuilds!
    #define dbgexpect2(test) if  (!(test)) {debugger; return 0;}
    #define JB_DoAt(count) {static int jDB = 0; if (++jDB == count) debugger;}
    #define JB_FuncCallCount(count) static int _fnCallCount_ = 0; _fnCallCount_++;
    #define DEBUGONLY(x) x
#else
    #define debugger ;// would crash...
    #define dbgexpect(test) ;
    #define dbgexpect2(test) ;
    #define JB_DoAt(count) ;
    #define JB_FuncCallCount(count)
    #define DEBUGONLY(x)
#endif

extern "C" {
#define CopyBytes(s0, d, Length) memcpy((void*)(d), (void*)(s0), (unsigned int)(Length))

struct JB_Object;

u64		JB_TotalMemoryCount	();
void	JB_OutOfMainMemory	(int64 N);
bool	JB_OutOfUserMemory	(int64 N);
uint8*	JB_AllocateString	(const void* Arr, int N);
void	JB_FreeString		(const void* Arr);

void	JB_MemSwap			(const void* A, const void* B, int Bytes);
uint8*	JB_Realloc			(const void* Arr, int N);
void	JB_Free				(const void* Arr);
u64		JB_msize			(const void* Arr);
u64		JB_MemUsedString	();
u64		JB_MemUsedOther		();


inline int JB_Int_Log2 (int X) {
#if __cpp_lib_bitops
	return 31-std::countl_zero((uint)X); // stable per-platform.
#else
	if (!X)
		return -1;
    return 31- __builtin_clz(X);   // this behaviour differs per-platform. very uncool!
#endif
}

inline int JB_u64_Log2 (u64 X) {
#if __cpp_lib_bitops
	return 63-std::countl_zero(X);
#else
	if (!X)
		return -1;
    return 63-__builtin_clzll(X);
#endif
}


inline void JB_memzero (void* Where, int64 N) {
    memset(Where, 0, N);
}

typedef int (*_qsort_garbage_)(const void* Space, const void* Result);

inline void JB_qsort (void* Data, uint64 Count, uint64 Width, void* Func) {
	qsort(Data, Count, Width, (_qsort_garbage_)Func);
}

inline int JB_Int_CountBits (int X) {
    return __builtin_popcount(X);
}

}


#endif

