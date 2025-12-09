


#ifndef __String_FUNCTIONS_LIB__
#define __String_FUNCTIONS_LIB__


extern "C" {

struct JB_StringC;
uint8* JB_FastFileString( JB_String* S, uint8* Buff);
uint8* JB_FastCString( JB_String* S, uint8* Buff, int Max);
JB_StringC* JB_Str_MakeC( JB_String* self );
bool JB_Str_IsC ( JB_String* self );
JB_String* JB_StrFromPtr(void* c, int N, void* Free, void* Obj);
JB_String* JB_Str__Freeable(uint8* p, int n);
JB_String* JB_Str__Freeable0(const char* Msg);
JB_StringC* JB_StrC( const char* c );
JB_StringC* JB_StrCN( const void* c, int N );


struct MiniStr;
uint8* SearchForward_ ( MiniStr S, MiniStr F, bool Lex );
JB_String* JB_Split_(JB_String* fd, int ByteOff, int LenB);
uint8* u8Write_( uint8* target, u32 ch );




// StringConvert
//int c8to16_(u8* source, int Len, JB_String** e);
//int c16to8_(u8* pSource, int Len, JB_String** e);
//int cLto8_(u8* pSource, int Len, JB_String** e);
//int cLto16_(u8* pSource, int Len, JB_String** e);
//
//int c8toL_(u8* pSource, int Len, JB_String** e);
//int c8to16_(u8* source, int Len, JB_String** e);
//int c16toL_( u8* source, int Len, JB_String** e);
//int c16to8_(u8* pSource, int Len, JB_String** e);

uint8* LegalUTF8_(uint8 FirstChar, uint8* source);
//static int RevByteCount_(u8* a, int Len, int CharCount);
//static int ByteCount_(u8* a, int Len, int CharCount);
//static int u8Count_(u8* a, int Len);
//static u32 u8Size_( u8 FirstChar );



// StringSearchers

//void Clear_(JB_String* self);
u32* Mark4Find_(u32* pSelfPos, u32 pLength, u32 Mask);

int StrDiffAt2( MiniStr S, MiniStr F );
bool StrEqualsLex( MiniStr S, MiniStr F );
bool StrEquals( MiniStr A, MiniStr B );
inline bool OffsetEquals_( uint8* S, MiniStr F );
bool OffsetEqualsLex( uint8* S, MiniStr F );
int OffsetCompareLex( MiniStr S, MiniStr F );

bool IsAscii_(JB_String* e);
bool IsAsciiSub_(uint8* SelfPos, u32 Length);



} // ExternCEnd


#endif


