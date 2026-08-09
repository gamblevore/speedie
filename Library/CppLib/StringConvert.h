

extern "C" {

	/* Some fundamental constants */
#define UNI_REPLACEMENT_CHAR 0x0000FFFD
#define UNI_BADOFFSET		0xFFFFFFFF
#define UNI_MAX_BMP			0x0000FFFF
#define UNI_MAX_UTF			0x0010FFFF
#define UNI_MAX_2BYTES		0x7FF
#define UNI_SUR_HIGH_START	0xD800
#define UNI_SUR_HIGH_END	0xDBFF
#define UNI_SUR_LOW_START	0xDC00
#define UNI_SUR_LOW_END		0xDFFF
#define UNI_IS_SURR(s)		(s >= UNI_SUR_HIGH_START and s <= UNI_SUR_LOW_END)


	/* Some utility constants */
#define halfShift 10

#define halfBase 0x0010000
#define halfMask 0x3FF
#define byteMask 0xBF
#define byteMark 0x80


bool JB_Str_UniValid( u32 c );

} // ExternCEnd

