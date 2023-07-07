

#define STBI_MAX_DIMENSIONS 1<<14
#ifndef AS_LIBRARY
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBIW_WINDOWS_UTF8
#include "stb_image_write.h"

#define QOI_IMPLEMENTATION
#include "qoi.h" // we can dump PNGs soon I hope

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
#define uint8 unsigned char



extern "C" {


uint8* JB_Img__LoadQOI(uint8* data, int len, int* Size) {
	qoi_desc desc;
	auto pixels = (uint8*)qoi_decode(data, len, &desc, 4);
	Size[0] = desc.width;
	Size[1] = desc.height;
//	Size[2] = desc.colorspace;
	return pixels;
}

uint8* JB_Img__WriteQOI(uint8* data, int w, int h, int* len) {
	qoi_desc desc;
	desc.width = w;
	desc.height = h;
	desc.channels = 4;
	desc.colorspace = QOI_SRGB;
	return (uint8*)qoi_encode(data, &desc, len);
}


extern stbi_write_func JB_File_WriteRaw_;
int JB_ErrorHandleC(const char* Desc, bool CanFreeDesc);

int JB_File_WritePng(void* file, int w, int h, const void* data) {
	stbi_write_png_compression_level = 9;
	return stbi_write_png_to_func(JB_File_WriteRaw_, file, w, h, 4, data, w*4);
}

uint8* JB_Img__LoadPNG(stbi_uc* data, int len, int* x, int* y, int* comp, int req_comp) {
	uint8* img = stbi_load_from_memory(data, len, x, y, comp, req_comp);
	if (!img)
		JB_ErrorHandleC(stbi__g_failure_reason, false);
	return img;
}

}



#else
// stop linker errors.
extern "C" void Stub_JB_PNG () {}
#endif
