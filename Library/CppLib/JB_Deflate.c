
// Pull in the public API types and signatures
#include "libdeflate/lib/lib_common.h"
#include "libdeflate/libdeflate.h"

// 1. Force libdeflate's internal build configuration options
#define LIBDEFLATE_ENABLE_GZIP
#undef LIBDEFLATE_DLL

#include "libdeflate/lib/utils.c"

#if __arm__ || __aarch64__ || _M_ARM64
	#include "libdeflate/lib/arm/cpu_features.c"
#else
	#include "libdeflate/lib/x86/cpu_features.c"
#endif


#include "libdeflate/lib/adler32.c"
#include "libdeflate/lib/crc32.c"
#include "libdeflate/lib/deflate_compress.c"
#include "libdeflate/lib/deflate_decompress.c"
#include "libdeflate/lib/gzip_compress.c"
#include "libdeflate/lib/gzip_decompress.c"



void JB_GZIP_Free (void* C) {
	libdeflate_free_compressor((struct libdeflate_compressor *)C);
}

void* JB_GZIP_Alloc (int Str) {
	return libdeflate_alloc_compressor(Str);
}

void JB_GZIP_Free2 (void* C) {
	libdeflate_free_decompressor((struct libdeflate_decompressor *)C);
}

void* JB_GZIP_Alloc2 () { // could use these directly?
	return libdeflate_alloc_decompressor();
}



int JB_GZIP_Max (void* C, int Length) {
	return (int)libdeflate_gzip_compress_bound((struct libdeflate_compressor *) C, Length);
}

int JB_GZIP_Compress (void* C, const void* In, int Length, void* Out, int Space) {
	return (int)libdeflate_gzip_compress(C, In, Length, Out, Space);
}

int JB_GZIP_Decompress (void* C, const void* In, int* Length, void* Out, int Space) {
	size_t ActualOut = 0;
	size_t ActualIn = 0;
	int Error = libdeflate_deflate_decompress_ex(C, In, Length, Out, Space, &ActualIn, &ActualOut);
	*Length = (int)ActualIn;
	if (!Error)
		return (int)ActualOut;
	return -Error;
}


