
#ifndef __JB_Str_FUNCTIONS__
#define __JB_Str_FUNCTIONS__

#include "JB_Alloc.h"

extern "C" {

struct JB_String;
struct FastString;
struct CharSet;
typedef JB_String* (*fpRenderer)(JB_Object* self, FastString* FS);

// obj?
JB_String* JB_Obj_Render(JB_Object* self, FastString* fs_in);
//JB_String* JB_Obj_GenericRender(JB_Object* self, FastString* fs_in);

// StringCore

struct MiniStr;
struct JB_StringExternal;
struct JB_StringC;
JB_String* JB_Str_New(int64 Len);
JB_String* JB_Str_NewCStr (int64 Length);
JB_String* Str_Shrink(JB_String* self, int Length);
JB_String* JB_Str_Render(JB_String* self, FastString* fs);
JB_String* JB_FS_Render(FastString* self, FastString* fs_in);
JB_StringC* JB_StrC( const char* c );
JB_String* JB_Str_CopyFromPtr( const void* Addr, int N );
JB_String* JB_Str_CopyFromCString( const char* C );
JB_String* JB_Str_Copy( JB_String* self );
void JB_Str_Destructor(JB_StringShared* self);
void JB_XStr_Destructor(JB_StringExternal* self);
//JB_String* JB_Str_Constructor( JB_String* self );
void JB_Str_Print( JB_String* s );
void JB_Str_PrintLine( JB_String* s );
void JB_PrintCString (const char* c);
FastString** JB_Str_PrintCapturer();
void JB_Str_PrintError(JB_String* s);
void JB_Str_PrintConsole(JB_String* s);
void JB_Str_Clone(JB_StringShared* self, JB_String* Name);

int JB_LogOpen_(const char* s);
struct Array;
void JB_Array_Print( Array* R );
Array* JB_Str_ArgV(const char** ArgV);
Dictionary* JB_EnvC(const char** self);


// StringConvert

JB_String* JB_Str_EncodeB64(JB_String* Str, FastString* fs);
JB_String* JB_Str_DecodeB64(JB_String* Str, FastString* fs);
u32 JB_Str_UTF8Size( u32 c );
u32 JB_u8p_Read ( uint8** source );
int JB_Str_CharCount(JB_String* self, int s, int s2);
JB_String* JB_Str_UTF16To8(JB_String* Str, FastString* fs_in, int SrcIsBig);
int JB_Str_BadUTF8 (JB_String* s, int err);
int JB_u8p_ByteCount(uint8* a, int Len, int CharCount);
u32 JB_u8_Size( uint8 FirstChar );
JB_String* JB_Str_Cleanse(JB_String* self, u32 Code);



// StringCS

int JB_Str_WhiteSpace( JB_String* self, int StartPos, int EndPos, bool IsIn );
int JB_Str_CharSet( JB_String* self, int BeginPos, int EndPos, CharSet* Find, bool IsIn );



// StringSearchers

int JB_Str_InStr( JB_String* self, JB_String* Find, int BeginPos, int After, bool CaseAware );
//int JB_Str_InRevStr( JB_String* self, JB_String* Find, int BeginPos, int EndPos, bool Lexer );
int JB_Str_InByte( JB_String* self, int StartPos, int After, int SearchChar );
int JB_Str_OutByte( JB_String* self, int StartPos, int After, int SearchChar );
bool JB_Str_Equals(JB_String* self, JB_String* Search, bool Lexer);
int JB_Str_DiffAt( JB_String* S, JB_String* F );
int JB_Str_Compare(JB_String* self, JB_String* Search, bool Lexer);








bool JB_Str_MidEquals(JB_String* self, int BeginOff, JB_String* find, bool Lexer);
int JB_Str_UTF8Value(JB_String* self, bool Error);
int JB_Str_ByteValue(JB_String* self, int offset);
int JB_Str_ByteValue2(JB_String* self, int offset, int Default);
byte JB_Str_First(JB_String* self);
int JB_Str_ShortValue(JB_String* self, u32 offset);
int JB_Str_IntValue(JB_String* self, u32 offset);
double JB_Str_DoubleValue(JB_String* self, u32 offset);
float JB_Str_SingleValue(JB_String* self, u32 offset);


// StringAlterCopy


JB_String* JB_Str_ReplaceAllB(JB_String* self, int cFrom, int cTo);
struct FastString;
struct JB_ErrorReceiver;
JB_String* JB_Str_ReplaceAll(JB_String* self, JB_String* Old, JB_String* New, bool Lex, FastString* fs_in);
JB_String* JB_Str_MultiReplaceAll(JB_String* self, 	Dictionary* Dict, JB_ErrorReceiver* Rec);
//JB_String* JB_Str_MultiReplaceAll(JB_String* self,  Dictionary* Dict, JB_ErrorReceiver* Rec);
JB_String* JB_Str_ReplaceBytesSub_(JB_String* self, int lFrom, int lTo, FastString* fs);
JB_String* JB_Str_UnHex(JB_String* self, FastString* fs = nil);
JB_String* JB_Str_Hex(JB_String* self, int Spaces, FastString* fs = nil);
JB_String* JB_Str_MapBytes(JB_String* self, ByteMap* CS, int Clear);
JB_String* JB_Str_LowerCase(JB_String* self);
JB_String* JB_Str_FastLower(JB_String* self);
ByteMap* JB_BM__Lower();
JB_String* JB_Str_UpperCase(JB_String* self);
bool JB_Str_IsAsciiName(JB_String* self);
JB_String* JB_Str_Reverse(JB_String* self, FastString* fs_in);
void JB_Str_StretchBack_(JB_String* self, int i);
JB_String* JB_Str_Trim(JB_String* self, CharSet* CS);
JB_String* JB_ASCII();
JB_String* JB_Upper();
JB_String* JB_Lower();
int JB_Str_CompressChunk (FastString* fs, JB_String* self, int Level);
int JB_Str_DecompressChunk (FastString* fs,  JB_String* self);
void JB_CompFreeNow();



// StringCloneAndCopy
/*
    JB_Object* JB_Str_DataCopy(JB_String* self);
    bool JB_Str_UnSplit( JB_String* self );
    bool JB_Str_Acquire( JB_String* self );
    JB_String* JB_Str_ObjectCopy(JB_String* self);
 */



// StringSplitters

//JB_String* JB_Str_Mid(JB_String* self, int Start, int Count);
JB_String* JB_Str_Range(JB_String* self, int Start, int Finish);
//void JB_Str__Uniqify(Dictionary* D);
JB_String* JB_Str_Left(JB_String* self, int Count);
JB_String* JB_Str_Right(JB_String* self, int Count);
JB_String* JB_Str_OperatorPlus(JB_String* self, JB_String* other);
JB_String* JB_Str_Append4(JB_String* A, JB_String* B, JB_String* C, JB_String* D);
JB_String* JB_Str_Append6(JB_String* A, JB_String* B, JB_String* C, JB_String* D, JB_String* E, JB_String* F);
JB_String* JB_Str_Unshare(JB_String* self);
JB_Object* JB_Str_Owner(JB_String* self);
//JB_String* JB_Str_RevMid(JB_String* self, int Count);



// StringEncoding

struct Message;
JB_String* JB_Str_UnicodeSync(JB_String* Str);
int JB_Str_EncodingXMLGuess(JB_String* Data);
JB_String* JB_Str_BOM(int Encoding, bool IsBigEndian);
double JB_Str_TextDouble(JB_String* self, Message* Where, bool Suffixes);
int64 JB_Str_TextIntegerSection( JB_String* self, int Start, Message* b );
int64 JB_Str_HexIntegerSection( JB_String* self, int Start, Message* b );
s64 JB_Str_HexInteger(JB_String* self, Message* b);
s64 JB_Str_TextIntegerValid(JB_String* self, Message* b);




// StringProperties

bool JB_Str_IsUnder(JB_String* self, u32 Under);
int JB_Str_LengthUTF8(JB_String* self);
uint64 JB_Str_CRC (JB_String* S, uint64 crc);
uint64 JB_CRC (u8* buf, uint64 crc, int n);
bool JB_Str_IsASCII(JB_String* self);
int JB_Str_Length( JB_String* self );
uint8* JB_Str_Address(JB_String* self);



// StringVerify

int JB_Str_Verify(JB_String* self, int utf);



// StringGlobals

JB_String* JB_Str__Empty();
JB_String* JB_Str__Error();
bool JB_Str_IsEmpty(JB_String* Obj);
bool JB_Str_Exists(JB_String* Obj);
JB_String* JB_Str_ChrUTF8(u32 c);
JB_String* JB_Str__Byte(int i);
void JB_Str__LoadGlobals2();
bool JB_Str_UniValid(u32 c);
JB_String* JB_Str_FromInt( int L, int R );
int64 JB_byte_SuffixSize (byte self);



}

#endif //#ifndef __JB_Str_FUNCTIONS__

