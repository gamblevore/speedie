
#ifndef AS_LIBRARY
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBIW_WINDOWS_UTF8
#include "stb_image_write.h"


#define STBI_NO_BMP
#define STBI_NO_PSD
#define STBI_NO_TGA
#define STBI_NO_GIF
#define STBI_NO_HDR
#define STBI_NO_PIC
#define STBI_NO_PNM
#define STB_IMAGE_IMPLEMENTATION
#define STBI_ASSERT(x)
#include "stb_image.h"


extern "C" {
    extern stbi_write_func JB_File_WriteRaw_;
    int JB_ErrorHandleC(const char* Desc, bool CanFreeDesc);
    
    int JB_File_WritePng(void* file, int w, int h, const void* data) {
        stbi_write_png_compression_level = 9;
        return stbi_write_png_to_func(JB_File_WriteRaw_, file, w, h, 4, data, w*4);
    }
    
	stbi_uc* JB_LoadImage(stbi_uc* data, int len, int* x, int* y, int* comp, int req_comp) {
		stbi_uc* img = stbi_load_from_memory(data, len, x, y, comp, req_comp);
		if (!img)
			JB_ErrorHandleC(stbi__g_failure_reason, false);
		return img;
	}
}



#else
// stop linker errors.
extern "C" void Stub_JB_PNG () {}
#endif
