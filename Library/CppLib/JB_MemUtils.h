

#ifndef __JB_MEM_UTILS__
#define __JB_MEM_UTILS__

#include <string.h>
#if __PLATFORM_CURR__ == __PLATFORM_OSX__
    #include <malloc/malloc.h>
#else
    #include <stdlib.h>
    #include <malloc.h>
#endif


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
    #define debugger// would crash...
    #define dbgexpect(test)
    #define dbgexpect2(test)
    #define JB_DoAt(count)
    #define JB_FuncCallCount(count)
    #define DEBUGONLY(x)
#endif

extern "C" {
#define CopyBytes(s0, d, Length) memcpy((void*)(d), (void*)(s0), (unsigned int)(Length))

struct JB_Object;

extern int OutOfMemoryHappenedAlready;
bool JB_OutOfMemoryOccurred();
u64 JB_TotalMemoryCount();
void JB_TooLargeAlloc(int64 N, const char* S);
void JB_OutOfMainMemory(int64 N);
void JB_OutOfUserMemory(int64 N);
void JB_ReportMemoryError(const char* A, int64 N, const char* B);
uint8* JB_AllocateString (const void* Arr, int N);
void JB_FreeString(const void* Arr);

uint8* JB_Realloc (const void* Arr, int N);
void JB_Free(const void* Arr);
u64 JB_msize(const void* Arr);
void JB_mtest(const void* M);
u64 JB_MemUsedString();
u64 JB_MemUsedOther();

#if __linux__
	#define JB_AlignedAlloc(R, A)	aligned_alloc(A, R) 
	#define JB_AlignedFree(M)		free(M)
#else 
	#define JB_AlignedAlloc(R, A)	malloc_zone_memalign(malloc_default_zone(), A, R)
	#define JB_AlignedFree(M)		malloc_zone_free(malloc_default_zone(), M);
#endif


inline int JB_Int_Log2 (int X) {
#if DEBUG
	if (!X) debugger;
#endif
    return 31- __builtin_clz(X);
}

inline uint64 JB_u64_Log2 (u64 X) {
#if DEBUG
	if (!X) debugger;
#endif
    return 63-__builtin_clzll(X);
}


#define MemZero(Where) (memzero(Where, sizeof(Where)))
inline void memzero (void* Where, int N) {
    memset(Where, 0, N);
}

inline int JB_Int_CountBits (int X) {
    return __builtin_popcount(X);
}

inline int JB_Int_CTZ (int X) {
	return __builtin_ctz(X);
}

inline int JB_Int_BiggestBit (int X) {
    int N = JB_Int_Log2( X );
    return 1 << (N - 1);
}

inline int JB_Int_RoundUp(int N, int To) {
	return N + (((uint)(-N)) % To);
}

}


#endif

