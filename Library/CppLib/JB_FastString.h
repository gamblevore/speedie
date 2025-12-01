
/*
	Copyright (C) 2005 Theodore H. Smith.
*/


#ifndef __FastString__
#define __FastString__

#include "JB_Umbrella.h"

extern "C" {

typedef void (*FSEventResize)(FastString* self, int Needed);


JBClass( FastString, JB_Object,
	int 			Length;
    uint8*			ResultPtr;
    JB_String*      Result;
    JB_File*        File;
    int64           WrittenLength;

	int 			Reserved;		// actual size of buffer. here for speeeed.
    u16             Indent;			// Jeebox itself needs this.
    uint8           IndentChar;
);




        /* function declarations */

void JB_FS_AppendMini(FastString* fs, MiniStr S);
void JB_FS_AppendMem_(FastString* fs, const uint8* s0, int len);
void JB_FS_AppendCString(FastString* self, const char* c);
void JB_FS_AppendVArg (FastString* fs, JB_String* Fmt, ...);
bool JB_FS_ResizeTo_(FastString* fs, int NewLength);
uint8* JB_FS_NeedSpare(FastString* fs, int Extra);
void JB_FS_RemoveByte(FastString* self, byte B);

    
FastString* JB_FS__FastNew(FastString* Old);
JB_String* JB_FS_SmartResult(FastString* fs, JB_Object* Orig);
FastString* JB_FS__FileAppend(JB_File* f);
JB_String* JB_FS_Return( JB_String* Data, FastString* Orig );
uint8*  JB__WriteIntToBuffer (uint8* wp, s64 LeftOver);
bool JB_FS_SizeIf_( FastString* fs, int InitLength);
void JB_FS_ByteSet(FastString* self, int offset, byte Val);
uint8*  JB_FS_WriteAlloc_(FastString* fs, int GrowBy);
void JB_FS_AppendString(FastString* self, JB_String* u);
int JB_FS_AppendURL(FastString* self, JB_StringC* URL, uint64 TimeoutSeconds, JB_StringC* Cookie );
void JB_FS_AppendRange(FastString* self, JB_String* u, int Start, int After);
void JB_FS_AppendFastString(FastString* self, FastString* po);
void JB_FS_AppendSectFastString(FastString* self, FastString* po, int srStart, int srLength);
FastString* JB_FS_ConstructorSize(FastString* self, int wtf);
FastString* JB_FS_Constructor(FastString* self);
void JB_FS_AppendByte(FastString* self, int byte);
int JB_FS_Last (FastString* self, int off);
void JB_FS_AppendMultiByte(FastString* self, int byte, int Count);
void JB_FS_AppendUTF8Char(FastString* self, int Char);
void JB_FS_AppendDoubleAsText0(FastString* self, double D);
void JB_FS_AppendDoubleAsText(FastString* self, double D, int dp, int CanExp);
int64 JB_FS_Mark(FastString* self);
bool JB_FS_Grew(FastString* self, int m);
int JB_FS_Byte(FastString* self, int offset);
void JB_FS_AppendHex(FastString* self, int64 tVal, int PadTo);
void JB_FS_AppendHexData(FastString* fs, uint8* Addr, int N, int Spaces);
void JB_FS_AppendHex3(FastString* fs, int tVal);
void JB_FS_AppendIntegerAsText(FastString* self, s64 LeftOver, int RoundTo);
void JB_FS_AppendIndent( FastString* self );
void JB_FS_LineIndent( FastString* self );
int JB_int_Render(int Self, byte* Addr, int N);
void JB_FS_AppendDurr(FastString* self, Date D);
void JB_FS_AppendLocalTime(FastString* self, Date D);
void JB_FS_AppendShort(FastString* self, int s);
void JB_FS_AppendInteger(FastString* self, int l);
void JB_FS_AppendFract16(FastString* self, u16 Fract);
void JB_FS_AppendDouble(FastString* self, double d);
void JB_FS_AppendInteger(FastString* self, int i);
void JB_FS_Compact(FastString* self);
void JB_FS_EnsureMinSize(FastString* self, int minSize);
int JB_FS_Size(FastString* self);
void JB_FS_SizeSet(FastString* self, int newsize);
int JB_FS_FreeSize(FastString* self);
int JB_FS_Length(FastString* self);
int64 JB_FS_StreamLength(FastString* self);
void JB_FS_LengthSet(FastString* self, int newLength);
void JB_FS_AppendReplaceB(FastString* self, JB_String* Data, int From, int To);
void JB_FS_AppendMultiReplace(FastString* self, JB_String* Data, Dictionary* MSR, JB_ErrorReceiver* Rec);
//void JB_FS_AppendByteMap(FastString* self, JB_String* Data, ByteMap* MSR);
void JB_FS_AppendLower(FastString* fs, JB_String* Data);
bool JB_FS_Flush(FastString* self);
JB_File* JB_FS_File(FastString* fs);


struct JB_File;
void JB_FS_FileSet(FastString* fs, JB_File* F);
void JB_FS_Destructor(FastString* self);
JB_String* JB_FS_GetResult(FastString* self);
JB_String* JB_FS_Copy(FastString* fs);
uint8* JB_FS_GrowBy(FastString* fs, int Needs);


#define FS_SanityCheck_(fs)

inline uint8* JB_FS_WriteAlloc_Inline_(FastString* fs, int GrowBy) {
	int OldLen = fs->Length;
	int NewLen = OldLen + GrowBy;

	if ( fs->Reserved >= NewLen ) { // we put the usual case first :)
		fs->Length = NewLen;
		return fs->ResultPtr + OldLen;
	}

    return JB_FS_GrowBy(fs, GrowBy);
}

inline void JB_FS_AdjustLength_( FastString* fs, int Expected, int Actual ) {
	int Missing = Expected - Actual;
	fs->Length -= Max(Missing,0);
	FS_SanityCheck_(fs);
}


// INLINED CODE DIRECTLY. TO AVOID COMPILER NOT INLINING IT!!!!

} // ExternCEnd

#endif //__FastString__


