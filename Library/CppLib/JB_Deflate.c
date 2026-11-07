
// Pull in the public API types and signatures
#if 1
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


int JB_GZIP_Max (void* C, int Length) {
	return (int)libdeflate_gzip_compress_bound((struct libdeflate_compressor *) C, Length);
}

int JB_GZIP_Compress (void* C, const void* In, int Length, void* Out, int Space) {
	return libdeflate_gzip_compress(C, In, Length, Out, Space);
}


//void* JB_GZIP (void* in_ptr, int Length, int* SizeOut, int Str) {
//	if (Str < 1)  Str = 1;
//	if (Str > 12) Str = 12;
//	static struct libdeflate_compressor* Compressor;
//	static int OldStr; 
//
//	*SizeOut = 0; 
//    if (OldStr != Str) {
//		if (Compressor) {
//			OldStr = 0;
//			libdeflate_free_compressor(Compressor);
//		}
//		// it should be possible to alter libdeflate_alloc_compressor
//		// so we don't need to realloc.
//		// but lets do that AFTER getting it to work.
//		Compressor = libdeflate_alloc_compressor(Str);
//		if (!Compressor)
//			return 0;
//		OldStr = Str;
//	}
//
//    size_t max_out_bytes = libdeflate_gzip_compress_bound(Compressor, Length);
//    
//    unsigned char* out_buffer = calloc(max_out_bytes, 1);
//
//    *SizeOut = (int)libdeflate_gzip_compress(
//        Compressor,
//        in_ptr,
//        Length,
//        out_buffer,
//        max_out_bytes
//    );
//
//    return out_buffer;
//}
//

#endif

