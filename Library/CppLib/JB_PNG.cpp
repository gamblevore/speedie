

#define STBI_MAX_DIMENSIONS 1<<14
#ifndef AS_LIBRARY
#define STBIW_WINDOWS_UTF8

#define QOI_NO_STDIO
#define QOI_IMPLEMENTATION
#include "qoi.h"

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
void JB_ErrorHandleC(const char* Desc, bool CanFreeDesc);

uint8* JB_Img__LoadQOI(uint8* data, int len, int* Size) {
	qoi_desc desc;
	auto pixels = (uint8*)qoi_decode(data, len, &desc, 4);
	if (!pixels)
		JB_ErrorHandleC("qoi could not decode", false);
	Size[0] = desc.width;
	Size[1] = desc.height;
	return pixels;
}

uint8* JB_Img__WriteQOI(uint8* data, int w, int h, int* len) {
	qoi_desc desc;
	desc.width = w;
	desc.height = h;
	desc.channels = 4;
	desc.colorspace = QOI_SRGB;
	auto qoi = (uint8*)qoi_encode(data, &desc, len);
	if (qoi)
		return qoi;
		
	JB_ErrorHandleC("qoi could not encode", false);
	return 0;
}

// I'd rather strip png support, cos it needs gz.  But I can't for now. Sadly.
uint8* JB_Img__LoadPNG(uint8* data, int len, int* x, int* y, int* comp) {
	uint8* img = stbi_load_from_memory(data, len, x, y, comp, 4);
	if (img)
		return img;
	JB_ErrorHandleC(stbi__g_failure_reason, false);
	return 0;
}
}

#else
// stop linker errors.
extern "C" void Stub_JB_PNG () {}
#endif
