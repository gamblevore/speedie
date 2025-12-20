

#ifndef __JB_MEM_UTILS__
#define __JB_MEM_UTILS__

#include <string.h>
#if __PLATFORM_CURR__ == __PLATFORM_OSX__
    #include <malloc/malloc.h>
#else
    #include <stdlib.h>
    #include <malloc.h>
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



#define MemZero(Where) (memzero(Where, sizeof(Where)))
inline void memzero (void* Where, int N) {
    memset(Where, 0, N);
}

inline int JB_Int_CountBits (int X) {
    return __builtin_popcount(X);
}

inline int JB_Int_Log2 (int X) {
    return 31- __builtin_clz(X);
}

inline int JB_Int_CTZ (int X) {
	return __builtin_ctz(X);
}

inline uint64 JB_u64_Log2 (u64 X) {
    return 63-__builtin_clzll(X);
}

inline uint64 JB_u32_Log2 (u64 X) { // fix this... we mean the other two!
    return 31-__builtin_clzl(X);
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

