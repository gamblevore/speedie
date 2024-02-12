

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
uint8* JB_malloc(int N);
uint8* JB_zalloc(int N);
struct allocate_result {
	uint8* Result;
	bool OK;
};

allocate_result JB_AllocateString (int N, const void* Arr = 0);
void JB_FreeString(const void* Arr);

allocate_result JB_allocate (int N, const void* Arr = 0);
void JB_free(const void* Arr);
uint8* JB_realloc(const void* Arr, int N);
u64 JB_msize(const void* Arr);
void JB_mtest(const void* M);
u64 JB_MemUsedString();
u64 JB_MemUsedOther();
inline void JB_unalloc(void** Arr) {
	if (*Arr) {
		JB_free(*Arr);
		*Arr = 0;
	}
}

#define MemZero(Where) (memzero(Where, sizeof(Where)))
inline void memzero(void* Where, int N) {
    memset(Where, 0, N);
}

inline int JB_Int_CountBits (int X) {
    return __builtin_popcount(X);
}

inline int JB_f_AsInt(float f) {
    float* fp = &f;
    int* ip = (int*)fp;
    return *ip;
}


inline int JB_Int_Log2 (int X) {
    return 31- __builtin_clz(X);
}

inline int JB_Int_CTZ (int X) {return __builtin_ctz(X);}

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

