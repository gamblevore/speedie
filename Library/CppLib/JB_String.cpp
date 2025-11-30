
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

// this file used to be split off into .i files...
// but this caused so many problems
// if we wanna split this up, it has to be into .cpp files.


#include "JB_Umbrella.hpp"
#include <stdio.h>
#include "float.h"
#include <string.h>


extern "C" {


#ifdef ENV64BIT
    #define kStrLengthMax (2147483644) // 2GB string max
#else
    #define kStrLengthMax (1024*1024*1024) // 1GB string max
#endif

// probably should move all this into the string header... utf-8 isnt needed elsewhere
#if kPlatformEndian == 0
    #define kWrongUTF16			/*Becomes*/		(16+1)
	#define kUTF16BBOM			/*Becomes*/		0xFFFE
	#define kUTF16LBOM			/*Becomes*/		0xFEFF
	#define kUTF32LBOM			/*Becomes*/		0x0000FEFF
	#define kUTF32BBOM			/*Becomes*/		0xFFFE0000
#elif kPlatformEndian == 1
    #define kWrongUTF16			/*Becomes*/		(16)
	#define kUTF16BBOM			/*Becomes*/		0xFEFF
	#define kUTF16LBOM			/*Becomes*/		0xFFFE
	#define kUTF32LBOM			/*Becomes*/		0xFFFE0000
	#define kUTF32BBOM			/*Becomes*/		0x0000FEFF
#endif


#define kUTF8BOM			/*Becomes*/		0xEFBBBF
#define kUTF8BOM1			/*Becomes*/		0xEF
#define kUTF8BOM2			/*Becomes*/		0xBB
#define kUTF8BOM3			/*Becomes*/		0xBF
#define kLast3ByteMask		/*Becomes*/		0xFFFFFF00
#define kUTF8FirstMin						-62 /*A magic number! don't change it!*/

enum {
	kEncAscii = 0,
	kEncBytes = 0,
	kEncUTF8 = 8,
	kEncUTF16 = 16,
    kEncUTF32 = 32,
    kEncBE = 1,
    kEncUTF = kEncUTF8|kEncUTF16|kEncUTF32,
    kEncUTF8_BE = kEncUTF8|kEncBE,
    kEncUTF_BE = kEncUTF| kEncBE,
};



bool JB_Byte_IsWhite (byte self) {
	return (self == 32) or (self == 10) or (self == 13) or (self == 9);
}


bool JB_BA_Realloc_( JB_String* self, int Length ) { // is a c-string
    if (Length <= 0) {
        JB_FreeString( self->Addr );
        self->Addr = 0; self->Length = 0;
        return 0;
    }

    if (Length > kStrLengthMax) {
        JB_TooLargeAlloc(Length, "strings");
        return 0;
    }
    
    auto Result = JB_AllocateString( self->Addr, Length+1 );
    require (Result);
    Result[Length] = 0;
    self->Addr = Result;
	self->Length = Length;
	return true;
}
    

void JB_BA_Destructor( JB_String* self ) {
    JB_FreeString( self->Addr );
}


JB_String* JB_Str_CopyFromPtr( const void* Addr, int N ) {
    JB_String* e = JB_Str_New( N );
    if (e and N) {
        CopyBytes(Addr, e->Addr, N);
    }
    return e;
}

JB_String* JB_Str_CopyFromCString( const char* C ) {
	if (C)
		return JB_Str_CopyFromPtr(C, (int)strlen(C));
	return 0;
}

JB_String* JB_Str_Copy( JB_String* self ) {
    if (self)
        return JB_Str_CopyFromPtr(self->Addr, self->Length);
    return 0;
}

JB_String* JB_StrFromPtr(void* c, int N, void* Free, void* Obj) {
	if (N > 0) {
		JB_StringExternal* S = JB_New( JB_StringExternal );
		S->Addr = (uint8*)c;
		S->Length = N;
		S->Free = Free;
		S->Obj = Obj;
		return S;
    }
	return JB_Str__Empty();
}

JB_StringC* JB_StrC( const char* c ) {
	int n = c ? (int)strlen(c) : 0;
	return JB_StrCN(c, n);
}

JB_StringC* JB_StrCN( const void* c, int N ) {
	if (N > 0) {
		JB_StringC* S = JB_New( JB_StringC );
		S->Addr = (uint8*)c;
		S->Length = N;
		return S;
	}
	return (JB_StringC*)JB_Str__Empty();
}

JB_String* JB_Str__Freeable(uint8* p, int n) {
    JB_String* Str = JB_New( JB_String );
    Str->Addr = (uint8*)p;
    Str->Length = n;
    return Str;
}

JB_String* JB_Str__Freeable0(const char* Msg) {
	return JB_Str__Freeable((uint8*)Msg, (int)strlen(Msg));
}


		// Utilities

int JB_Str_Length( JB_String* self ) {
	if (self)
		return self->Length;
	return 0;
}

uint8* JB_Str_Address( JB_String* self ) {
	if (self) 
		return (uint8*)self->Addr;
	return (uint8*)"";
}

      
JB_String* JB_Str_NewInlined(int Length, JB_Class* Cls) {
    if (!Length)
        return JB_Str__Empty();
    
    JB_String16* Result = (JB_String16*)(JB_NewClass(Cls));
    Result->Data[Length]=0; // zero term
    Result->Addr = (Result->Data);
    Result->Length = Length;
    return (JB_String*)Result;
}

 
JB_String* JB_Str_NewCStr (int64 N) {
	int Extra = (N == 4 or N == 16);
	JB_String* Rz = JB_Str_New(N + Extra);
	if (Rz and Extra) {
        Rz->Addr[N] = 0; // ooof.
        Rz->Length = (int)N;
	}
	return Rz;
}

JB_String* JB_Str_New (int64 Length) {
	// only allows huge values to "Catch" file-errors... otherwise limited to int-length.
	if (Length < 16) {
        if (Length < 8) {
            if (Length < 0)
				return 0;	// error
			return JB_Str_NewInlined( (int)Length, JB_AsClass(JB_String8) );
        }
        return JB_Str_NewInlined( (int)Length, JB_AsClass(JB_String16) );
    }
    
    require (Length <= kStrLengthMax);
    JB_String* Str = JB_New( JB_String ); // is a cstring... but how do I KNOW that?
    if_usual (Str) {							  // I guess as long as it's not shared????? is that it?
		Str->Addr = 0;
		if (JB_BA_Realloc_(Str, (int)Length))
			return Str;
		JB_SetRef(Str, 0);
    }
    return Str;
}


// calls freeifdead
JB_String* Str_Shrink (JB_String* u, int Length) {
	if (!u or u->Length == Length) {
		return u;
	}
	if (Length <= 0) {
		JB_FreeIfDead(u);
		if (Length < 0)
			return JB_Str__Error();
		return JB_Str__Empty();
	}
	
	// so... we can freeifdead if we need to copy
	// needs zero-terminate... if we shrink
	// keep the class unless it's resizeable... otherwise just copy...
	
	JB_Class* Cls = JB_ObjClass(u);
	if ( Cls == JB_AsClass(JB_String8)  or  Cls == JB_AsClass(JB_String16) ) {
	   u->Length = Length; // just keep it.
	   return u;
	}
	if ( Cls == JB_AsClass(JB_String) and Length >= 16 ) {
		JB_BA_Realloc_(u, Length);
		return u;
	}

    JB_String* CopyTo = JB_Str_CopyFromPtr(u->Addr, Length);
	JB_FreeIfDead(u);
    return CopyTo;
}



void JB_Str_Destructor(JB_StringShared* self) {
	JB_Decr( self->Parent );
}


typedef void (*XStrFree)(const char* Addr, void* Param);

void JB_XStr_Destructor(JB_StringExternal* self) {
    auto F = self->Free;
    auto O = self->Obj;
    auto A = self->Addr;
    if (F and O) {
        self->Addr = 0; self->Obj = 0;
        ((XStrFree)(F))((const char*)A, O);
    }
}



////////////    #include "StringConvert.i"

/*
		Unicode Ranges:

		// Functions that appreciate unicode numbers!
These must be unified in appreciation of the numbers, or chaos will bomb us!

  JB_Str_UTF8Size
  u8Write_
  JB_Str_UniValid
  c32to8_ etc etc


Table 3.1B. Legal UTF-8 Byte Sequences
 Code Points		1st Byte	2nd Byte	3rd Byte	4th Byte
U+0000..U+007F		00..7F			 
U+0080..U+07FF		C2..DF		80..BF		 
U+0800..U+0FFF		E0			A0..BF		80..BF	 
U+1000..U+CFFF		E1..EC		80..BF		80..BF	 
U+D000..U+D7FF		ED			80..9F		80..BF	 
U+D800..U+DFFF		ill-formed
U+E000..U+FFFF		EE..EF		80..BF		80..BF	 
U+10000..U+3FFFF	F0			90..BF		80..BF		80..BF
U+40000..U+FFFFF	F1..F3		80..BF		80..BF		80..BF
U+100000..U+10FFFF	F4			80..8F		80..BF		80..BF
*/


static uint8* u8Read( uint8* source, u32* pch ) {
	u32 ch = *source++;
    
	if (ch >= 0x80) {
        u32 ch0 = ch;
        ch <<= 6;
        ch += *source++;
		if (ch0 <= 0xDF) {
			ch -= 0x00003080;
            
		} else {
            ch <<= 6;
            ch += *source++;
            if (ch0 <= 0xEF) {
                ch -= 0x000E2080;
                
            } else {
                ch <<= 6;
                ch += *source++;
                ch -= 0x03C82080;
            }
        }
	}
    
    *pch = ch;
    return source;
}



uint8* u8Write_ ( uint8* target, u32 ch ) {
	if (ch < 0x80) {
		*target++ = (uint8)ch;

	} else {
		if (ch < 0x800) {
            *target++ = (uint8)( (ch >> 6) | 0xC0 );

		} else {
            if (ch < 0x10000) {
                *target++ = (uint8)( (ch >> 12) | 0xE0 );
                
            } else {
                *target++ = (uint8)( (ch >> 18) | 0xF0 );
                *target++ = (uint8)( ((ch >> 12) | byteMark) & byteMask );
            }
            *target++ = (uint8)( (ch >> 6 | byteMark) & byteMask );
        }
        *target++ = (uint8)( (ch >> 0 | byteMark) & byteMask );
	}

	return target;
}


inline u16* u16Read( u16* source, u32* ch ) {
	*ch = *source++;
	if (*ch >= UNI_SUR_HIGH_START and *ch <= UNI_SUR_HIGH_END) {
		u32 ch2 = *source++;
        *ch = ((*ch - UNI_SUR_HIGH_START) << halfShift) + (ch2 - UNI_SUR_LOW_START) + halfBase;
	}
	return source;
}


JB_String* JB_Str_UTF16To8(JB_String* Str, FastString* fs_in, int SrcIsBig) {
	int N = JB_Str_Length(Str)/2;
	if (N < 1)
		return 0;
	
	u16* S = (u16*)(Str->Addr);
	u16* End = S+N;
	if (*S == 0xFFFE) {
		SrcIsBig=0;
		S++;
	} else if (*S == 0xFEFF) {
		SrcIsBig=1;
		S++;
	} else if (SrcIsBig == 2) {
		if (!fs_in)
			return Str;
		JB_FS_AppendString(fs_in, Str);
		return 0;
	}

	FastString* fs = JB_FS__FastNew(fs_in);
	bool Native = (SrcIsBig != (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__));
	while (S < End) {
		u32 ch = *S++;
		if (!Native)
			ch = __builtin_bswap16(ch);
		if (ch >= UNI_SUR_HIGH_START and ch <= UNI_SUR_HIGH_END) {
			u32 ch2 = *S++;
			if (!Native)
				ch2 = __builtin_bswap16(ch2);
			ch = ((ch - UNI_SUR_HIGH_START) << halfShift) + (ch2 - UNI_SUR_LOW_START) + halfBase;
		}
		JB_FS_AppendUTF8Char(fs, ch);
	}
	return JB_FS_SmartResult(fs, fs_in);
}


// kUTF8FirstMin is a special trick to test for a UTF8 starter, in 1 test, instead of 2

static int ValidateUTF8 (uint8* p, int Len) {
	int i = 0;
	while (i < Len) {		
		u32 v = p[i++];									/* 0xxxxxxx */
		if (v < 0x80) {
			if (v < 32 and (v != 9 and v != 10 and v != 13))
				return i-1;
			continue;
		}
		
		if (i >= Len)
			return i-1;
		v = (v << 8) | p[i++];							/* 110xxxxx 10xxxxxx */
		if ((v & 0xE0C0) == 0xC080) {
			v = v & 0x1E00;
			if (v == 0)
				return i-2;
			continue;
		}
		
		if (i >= Len)
			return i-2;
		v = (v << 8) | p[i++];							/* 1110xxxx 10xxxxxx 10xxxxxx */
		if ((v & 0xF0C0C0) == 0xE08080) {
			v = v & 0x0F2000;
			if (v == 0 or v == 0x0D2000)
				return i-3;
			continue;
		}
		
		if (i >= Len)
			return i-3;
		v = (v << 8) | p[i++];							/* 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx */
		if ((v & 0xF8C0C0C0) == 0xF0808080) {
			v = v & 0x07300000;
			if (v == 0 or v > 0x04000000)
				return i-4;
		}
	}
	
	return -1;
}


int JB_Str_BadUTF8 (JB_String* s, int Err) {
	int n = JB_Str_Length(s);
	if (n <= 0)
		return -1;

	u8* Where = JB_Str_Address(s) + Err;
	return ValidateUTF8(Where, n - Err);
}


// Param and return is 1 based!
int JB_u8p_ByteCount(uint8* a, int Len, int CharCount) {
	if (CharCount <= 0)
		return 0;

	int8* s = (int8*)a;
	int Count = 0;
	for (int n = Len; n > 0; n--)
		if ( *s++ >= kUTF8FirstMin and ++Count > CharCount )
			return (int)((uint8*)s - a) - 1;

	return Len;
}

int u8Count_ (uint8* a, int Len) {
	char* s = (char*)a;	
	int cCount = 0;
	while (Len-- > 0)
		if ( *s++ >= kUTF8FirstMin )
			cCount++;
	return cCount;
}


int JB_Str_CharCount (JB_String* self, int s, int s2) {
	int L = JB_Str_Length(self);
	require(L and s < L);
	s2 = Min(s2, L);
	uint8* a = JB_Str_Address(self);
	return u8Count_(a+s, s2-s);
}


u32 JB_u8p_Read ( uint8** source ) {
	u32 Result;
	*source = u8Read( *source, &Result );
	return Result;
}


u32 JB_Str_UTF8Size ( u32 c ) {
	if (c < 0x80) { // common case first!
		return 1;
	} else if (c <= UNI_MAX_2BYTES) {
		return 2;
	} else if (c < 0xFFFE) {
		if (c >= UNI_SUR_HIGH_START and c <= UNI_SUR_LOW_END) {
			return 0;
		}
		return 3;
	} else if (c == 0xFFFE or c == 0xFFFF) {
		return 0;
	} else if (c <= UNI_MAX_UTF) { // logically can only be this now!
		return 4;
	}
	return 0;
}


int JB_Str_UTF8Value (JB_String* self, bool Strict) {
	int Len = JB_Str_Length(self);
	if (Len <= 0)
		return UNI_BADOFFSET;

	uint8* Source = self->Addr;
	if (!Strict or ValidateUTF8(Source, Len) < 0) {
		uint8* Source = self->Addr;
		int N = JB_u8_Size(*Source);
		if ((N <= Len) and (!Strict or N == Len)) {
			u32 Result;
			u8Read( Source, &Result );
			return (int)Result;
		}
	}

	return UNI_BADOFFSET;
}


u32 JB_u8_Size ( uint8 FirstChar ) {
	if (FirstChar < 0x80) return 1;
	if (FirstChar <= 0xC1) return 0;
	if (FirstChar <= 0xDF) return 2;
	if (FirstChar <= 0xEF) return 3;
	return 4;
}


// Tells us how many bytes on the end of the UTF8 are not a complete byte
int JB_Str_Scan_BadUTF8AtEnd(JB_String* u) {
	int Len = u->Length;
	if ( Len ) {
        char* Last = (char*)u->Addr + Len;
        int LastCharLen = 0;

        while (LastCharLen < Len) {
            char c = *(--Last);
            LastCharLen++;  // we found it...
            if (c >= kUTF8FirstMin) {
                return JB_u8_Size((uint8)c) - LastCharLen;
            }
        }
	}

    return Len;
}


static const uint8 EscapeTable_[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz._";

void JB_FS_AppendHexSub ( FastString* fs, int64 tVal,  int RoundTo, const uint8* CharMap);
void JB_FS_AppendHexData( FastString* fs, uint8* Addr, int Len, int Spaces ) {
	require0(Len >= 1);
	Spaces &= ~1;
	int Added = 0;
	int Alloc = Len*2;
	if (Spaces>0) {
		Alloc += (Alloc-1)/Spaces;
	}

	uint8* wp = JB_FS_WriteAlloc_(fs, Alloc);
	uint8* orig = wp;
    if (!wp) { return; }

    auto CharMap = &EscapeTable_[0];
	while (Len-- >= 1) {
		if (Spaces>0 and Added >= Spaces) {
			*wp++ = ' ';
			Added = 0;
		}
        uint8 C = *Addr++;
        *wp++ = CharMap[C>>4];
        *wp++ = CharMap[C&15];
		Added += 2;
	}
	if (wp != orig+Alloc)
		debugger;
}


void JB_FS_AppendHex(FastString* fs, int64 tVal, int RoundTo) {
    JB_FS_AppendHexSub(fs, tVal, RoundTo, EscapeTable_);
}


void JB_FS_AppendHex3(FastString* fs, int tVal) {
    JB_FS_AppendHexSub(fs, tVal, 1, EscapeTable_ + 10);
}



////////////    #include "StringCS.i" 

int JB_Str_WhiteSpace( JB_String* self, int StartOff, int AfterOff, bool IsIn ) {
    extern CharSet* WhiteSpace_;
	return JB_Str_CharSet( self, StartOff, AfterOff, WhiteSpace_, IsIn );
}



         //  Main subroutines. These are generalised, and need interfacing routines.

extern JB_StringC* EmptyString_;
int JB_Str_CharSet( JB_String* Self, int StartOff, int AfterOff, CharSet* cs, bool IsIn ) {
	if (!Self or !cs)
		return -1;
    MiniStr S = ReadAddrs_(Self, StartOff, AfterOff);
	int Dir = S.Dir();
		
	while (S) {
		uint8 C = S.Move(Dir);
		if ( (cs->Cache[C]!=0) == IsIn ) {
			return ResultFix_(S, Self, Dir);
		}
	}

	return -1;
}

 //////////   #include "StringSearchers.i"




inline uint8* u8Pos( MiniStr S, uint8 TheChar ) {
	while (	S ) {
		if (S.Next() == TheChar) {
			return S;
		}
	}
	return 0;
}


inline uint8* u8PosLex( MiniStr S, uint8 TheChar ) {
	TheChar = LowerCaseB(TheChar);
	while (	S ) {
		if (S.NextLower() == TheChar) {
			return S;
		}
	}
	return 0;
}


inline MiniStr Theo2Pos( MiniStr S, uint8 Find1, uint8 Find2 ) {
    u32 Read1 = S.Next();
    while (	S ) {
        u32 Read2 = S.Next();
        if (Read1 == Find1 and Read2 == Find2) {
            S.Move(-1);
            return S;
        }
        Read1 = Read2;
    }
    return {0, 0};
}



inline MiniStr Theo2PosLex( MiniStr S, uint8 Find1, uint8 Find2 ) {
    u32 Read1 = S.NextLower();
    while (	S ) {
        u32 Read2 = S.NextLower();
        if (Read1 == Find1 and Read2 == Find2) {
            S.Move(-1);
            return S;
        }
        Read1 = Read2;
    }
    return {0,0};
}


inline uint8* u8PosRev( MiniStr S, uint8 TheChar ) {
	while (	S ) {
		if (S.Prev() == TheChar) {
			return S;
		}
	}
	return 0;
}


inline uint8* u8PosRevLex( MiniStr S, uint8 TheChar ) {
	TheChar = LowerCaseB(TheChar);
	while (	S ) {
		if (S.PrevLower() == TheChar) {
			return S;
		}
	}
	return 0;
}


inline MiniStr Theo2PosRev( MiniStr S, uint8 Find1, uint8 Find2 ) {
    u32 Read1 = S.Prev();
    while (	S ) {
        u32 Read2 = S.Prev();
        if (Read1 == Find1 and Read2 == Find2) {
			// so we are moving the address back
			// why?
			// well... i guess we give it the address after the thing we want to search? are we?
			// let's assume so. fix later if not
			// So... NEXT time we get in here... we have the address of what? something we read?
			// seems fair... idk really. i dont get it.
            return S;
        }
        Read1 = Read2;
    }
    return {1, 0};
}



inline MiniStr Theo2PosLexRev( MiniStr S, uint8 Find1, uint8 Find2 ) {
    u32 Read1 = S.PrevLower();
    while (	S ) {
        u32 Read2 = S.PrevLower();
        if (Read1 == Find1 and Read2 == Find2) {
            return S;
        }
        Read1 = Read2;
    }
    return {1, 0};
}


uint8* SearchForward_( MiniStr S, MiniStr F, bool Lex ) {
    u32 FirstChar = F.Next();
    if (!F) {
		if (Lex)
			return u8PosLex(S, FirstChar);
		  else
			return u8Pos( S, FirstChar );
    }
    u32 SecondChar = F.Next();
    
	if (!Lex) {
        do {
            S = Theo2Pos( S, FirstChar, SecondChar );
            require (S.Length >= F.Length);
            if (OffsetEquals_( S.Addr + 1, F )) {
                return S.Addr;
            }
        } while (S);
		
	} else {
        SecondChar = LowerCaseB(SecondChar);
        FirstChar = LowerCaseB(FirstChar);
        do {
            S = Theo2PosLex( S, FirstChar, SecondChar );
            require (S.Length >= F.Length);
            if (OffsetEqualsLex( S.Addr + 1, F )) {
                return S.Addr;
            }
        } while (S);
	}

    return 0;
}


uint8* SearchBackward_( MiniStr S, MiniStr F, bool Lex ) {
    u32 FirstChar = F.Next();
    if (!F) {
		if (Lex)
			return u8PosRevLex( S, FirstChar );
		else
			return u8PosRev( S, FirstChar );
	}
	
    u32 SecondChar = F.Next();
    uint8* End = S.Addr;
	S.Move(-F.Length); // sigh
	
	if (!Lex) {
        do {
            S = Theo2PosRev( S, SecondChar, FirstChar );
            require (S.Length<=0  and  S.Addr+F.Length < End);
            if (OffsetEquals_( S.Addr + 2, F ))
                return S.Addr;
        } while (S);
		
	} else {
        SecondChar = LowerCaseB(SecondChar);
        FirstChar = LowerCaseB(FirstChar);
        do {
            S = Theo2PosLexRev( S, SecondChar, FirstChar );
            require (S.Length<=0  and  S.Addr+F.Length < End);
            if (OffsetEqualsLex( S.Addr + 2, F ))
                return S.Addr;
        } while (S);
	}

    return 0;
}



inline bool OffsetEquals_( uint8* S, MiniStr F ) {
	// you need to compare the length before calling this function!

	if (S != F.Addr)
		while (F) {
			auto f = F.Next();
			auto s = *S++;
			if (f != s)
				return false;
		}

	return true;
}

bool StrEquals( MiniStr S, MiniStr F ) {
	return (S.Length == F.Length) and OffsetEquals_( S.Addr, F );
}


bool OffsetEqualsLex( uint8* S, MiniStr F ) {
// you need to compare the length before calling this function!
	if (S != F.Addr) {
		while (F) {
			if (F.NextLower() != LowerCaseB(*S++)) {
				return false;
			}
		}
	}
	return true;
}

bool StrEqualsLex( MiniStr S, MiniStr F ) {
    return (S.Length == F.Length) and OffsetEqualsLex( S.Addr, F );
}


int JB_Str_DiffAt( JB_String* S, JB_String* F ) {
	return StrDiffAt2( Mini(S), Mini(F) );
}



inline int OffsetCompare_( MiniStr S, MiniStr F ) {
	int UseLen = Min( S.Length, F.Length );
	
	if (S.Addr != F.Addr) {
		while (UseLen-- > 0) {
			uint8 fChar = F.Next();
			uint8 sChar = S.Next();
			if (fChar == sChar) {
				; //
			} else if (fChar < sChar) {
				return 1;
			} else {
				return -1;
			}
		}
	}
	
	if ( S.Length > F.Length ) {
		return 1; // should work?
	} else if ( S.Length < F.Length ) {
		return -1;
	}
	return 0;
}


int OffsetCompareLex( MiniStr S_, MiniStr F_ ) {
    MiniStr S = S_;
    MiniStr F = F_;
	int UseLen = Min(S.Length, F.Length);

	if (S.Addr != F.Addr) {
		while (UseLen-- > 0) {
			uint8 fChar = F.NextLower();
			uint8 sChar = S.NextLower();
			if (fChar == sChar) {
				; //
			} else if (fChar < sChar) {
				return 1;
			} else {
				return -1;
			}
		}
	}

	return OffsetCompare_( S_, F_ );
}

bool JB_Str_Equals(JB_String* self, JB_String* find, bool Lexer) {
	if (self != find) {
		if (!self)
			self = EmptyString_;
		if (!find)
			find = EmptyString_;
		if ( ! Lexer ) {
			return StrEquals( Mini(self), Mini(find) );
		} else {
			return StrEqualsLex( Mini(self), Mini(find) );
		}
	}
	return true;
}


int JB_Str_Compare(JB_String* self, JB_String* Find, bool Lexer) {
	if (!self)
		self = EmptyString_;
	if (!Find)
		Find = EmptyString_;
	if ( ! Lexer ) {
		return OffsetCompare_( Mini(self), Mini(Find) );
	} else {
		return OffsetCompareLex( Mini(self), Mini(Find) );
	}
}




	// Interfaces

extern JB_StringC* EmptyString_;
extern JB_StringC* ErrorString_;
bool JB_Str_MidEquals(JB_String* self, int BeginOff, JB_String* find, bool CaseAware) {
	int n = JB_Str_Length(find); 
	if (!n)
		return false;
	if (!self)
		self = EmptyString_;

	MiniStr S = ReadAddrs_( self,  BeginOff,  BeginOff + n );
	if ( CaseAware ) {
		return StrEqualsLex( Mini(find), S );
	} else {
		return StrEquals( Mini(find), S );
	}
}


// Move0 Mod0  1234 5678
// Move3 Mod1   123 4567 8
// Move2 Mod2    12 3456 78
// Move1 Mod3     1 2345 678

bool IsAsciiSub_(uint8* SelfPos, u32 Length) {
	uint8* SelfEnd = SelfPos + Length; // must be done before I alter selfpos!

	while ( ((UintPtr)SelfPos % 4) and SelfPos < SelfEnd ) {
		if ( *SelfPos++ >= 0x80 ) {
			return false;
		}
	}
	
	while ( ((UintPtr)SelfEnd % 4) and SelfPos < SelfEnd ) {
		if ( *(--SelfEnd) >= 0x80 ) {
			return false;
		}
	}
	
	int TrimLength = (int)(SelfEnd - SelfPos) / 4;
	u32* intPos = (u32*)SelfPos;
	while ( TrimLength-- ) {
		if ( (*intPos++) & k4HighBits ) {
			return false;
		}
	}

	return true;
}


int JB_Str_InStr( JB_String* self, JB_String* f, int BeginOff, int AfterOff, bool lex ) {
	if ( f and self ) {
        MiniStr S	= ReadAddrs_( self, BeginOff, AfterOff );
		MiniStr F	= Mini( f );
		if (F and S) {
			int		Dir = S.Forward();
			uint8*	W	= 0;
			if ( Dir ) {
				W = SearchForward_( S, F, lex );
			} else {
				W = SearchBackward_( S, F, lex );
			}
			return ResultFix_( W, self, Dir );
		}
	}

	return -1;
}


int JB_Str_Byte( JB_String* self, int StartOff, int AfterOff, int SearchChar, bool Find ) {
	if (self) {
		MiniStr S = ReadAddrs_( self, StartOff, AfterOff );
		int Dir = S.Dir();
		
		while (	S ) {
			if ((S.Move(Dir) == SearchChar) == Find) {
				return ResultFix_(S, self, Dir);
			}
		}
	}
    
    return -1;
}


int JB_Str_InByte( JB_String* self, int StartOff, int AfterOff, int SearchChar ) {
    return JB_Str_Byte( self, StartOff, AfterOff, SearchChar, true );
}


int JB_Str_OutByte( JB_String* self, int StartOff, int AfterOff, int SearchChar ) {
    return JB_Str_Byte( self, StartOff, AfterOff, SearchChar, false );
}



byte JB_Str_First(JB_String* self) {
	int n = self->Length;
	if (n)
		return self->Addr[0];
	return 0;
}


int JB_Str_ByteValue2(JB_String* self, int offset, int Default) {
	if ((u32)offset < (u32)self->Length) {
		return (int) (self->Addr[offset]) ;

	} else if (offset < 0) {
		offset = self->Length + offset;
		if ((u32)offset < (u32)self->Length) {
			return (int) (self->Addr[offset]) ;
		}
	}
    return Default;
}

int JB_Str_ByteValue(JB_String* self, int offset) {
	return JB_Str_ByteValue2(self, offset, 0);
}



#define kParseEnd_Dot 1
#define kParseEnd_E 2
#define kParseEnd_Both 3

void JB_Err__CantParseNum(Message* Where, JB_String* self, int Pos, bool Overflow);
void ParseNumErr_( JB_String* self, uint8* BadPos, Message*& Where, bool OverFlow ) {
    int CharPos = (int)(BadPos - self->Addr - 1);
    JB_Err__CantParseNum(Where, self, CharPos, OverFlow);
    
    Where = nil;
}


static double ParseDouble_(JB_String* Str, uint8** ReadPlaceOut, uint8* ReadEnd, bool IsFrac, Message*& Where, int Endable) {
	double Value = 0;
	uint8* Read = *ReadPlaceOut;
	double Mul0 = 10;
//	if (ReadEnd[-1] == 'm') { // the universe is 12-based. m for "month".
//		ReadEnd--; // what digit, though.? 7.6am?? Seems we really need unicode.
//		Mul0 = 12;
//	}
	double Max = __DBL_MAX__/Mul0;
	if (IsFrac) Mul0 = 1.0 / Mul0;
	double Mul = Mul0;

	while ( Read < ReadEnd ) {
		int ch = *Read++;
        if (ch != '_') {
            int c = ch - '0';
            if ((u32)c > 9) {
                if (ch == 'e' and Endable&kParseEnd_E) {
                    ; //
                } else if (ch == '.' and Endable&kParseEnd_Dot) {
                    ; //
                } else {
                    ParseNumErr_( Str, Read, Where, false );
                }
                break;
            }

            double num = c;
            if ( IsFrac ) {
                Value = Value + num*Mul;
                Mul = Mul * Mul0;
            } else {
				if (Value > Max) {
					ParseNumErr_( Str, Read, Where, true );
					break;
				}
                Value = Value*Mul + num;
            }
        }
	}

	*ReadPlaceOut = Read;
	return Value;
}


int64 JB_byte_SuffixSize (byte self) {
	if (self == 'K')
		return 1ull<<10ull;
	if (self == 'M')
		return 1ull<<20ull;
	if (self == 'G')
		return 1ull<<30ull;
	if (self == 'T')
		return 1ull<<40ull;
	if (self == 'P')
		return 1ull<<50ull;
	return 0;
}



double JB_Str_TextDouble (JB_String* self, Message* Where, bool Suffixes) {
	if (!self) return 0;
	int Length = JB_Str_Length(self);
	uint8* ReadPlace = self->Addr;
	uint8* ReadEnd = ReadPlace + Length;
	while (true) {
		if (ReadPlace >= ReadEnd)
			return 0;
		if (JB_Byte_IsWhite(*ReadPlace))
			ReadPlace++;
		  else if (JB_Byte_IsWhite(*(ReadEnd-1)))
			ReadEnd--;
		  else
			break;
	}
	
	double Suffix = 1.0;
	if (ReadEnd[-1] == 'B') {
		ReadEnd--;
		if (ReadPlace >= ReadEnd) { // "B" is the entire string!
			ParseNumErr_( self, ReadPlace, Where, false );
			return 0;
		}
		ReadEnd--;
		Suffix = (double)JB_byte_SuffixSize(ReadEnd[0]);
	}

	if (ReadPlace[0] == '-') {
		if (++ReadPlace >= ReadEnd)
			return 0;
		Suffix = -Suffix;
	}

	double Value = ParseDouble_( self, &ReadPlace, ReadEnd, false, Where, kParseEnd_Both );

	if (ReadPlace[-1] == '.') {
		Value += ParseDouble_( self, &ReadPlace, ReadEnd, true, Where, kParseEnd_E );
	}
	if (ReadPlace[-1] == 'e') {
		bool ExpMinus = (ReadPlace[0] == '-');
		if (ExpMinus) ReadPlace++;
		double Exp = ParseDouble_( self, &ReadPlace, ReadEnd, false, Where, 0 );
		if (ExpMinus) Exp = -Exp;
		Value = Value * pow(10, Exp);
	}
	
	return Value*Suffix;
}


static int64 ParseNumbers__( JB_String* self, int Mode, Message* Where, MiniStr S ) {
	bool IsMinus = (S.Curr() == '-');
	if (IsMinus)
		S.Next();
	
	int Mul = 10;
	while (S and JB_Byte_IsWhite(S[0]))
		S.Next();
	while (S and JB_Byte_IsWhite(S[S.Length-1]))
		S.Length--;
	if (S.Length >= 2 and S[0] == '0') {
		char c = S[1];
		if (c=='x' or c == 'b') {
			Mode = 1+(c=='x');
			S.Next(); S.Next();
		}
	}
	if (Mode == 1) {
		Mul = 2;
	} else if (Mode == 2) {
		Mul = 16;
	}
		

	uint64 Value = 0;
	bool Overflow = false;

	while ( S ) {
		uint c = S.Next();
		if (c == '_')
			continue;
		if (c >= 'a' and c <= 'f')
			c -= 32; // a --> A
		if (c >= '0' and c <= '9') {
			c = c - '0';
			if (Mode == 1 and c > 1) goto BadPos;
		} else if ( Mode == 2 and c >= 'A' and c <= 'F' ) {
			c = c + (10 - 'A');
		} else {
			goto BadPos;
		}
		if (__builtin_mul_overflow(Value, Mul, &Value) or __builtin_add_overflow(Value, c, &Value)) {
			Overflow = true;
			BadPos:;
			ParseNumErr_(self, S.Addr, Where, Overflow);
			break;
		}
	}

	if (IsMinus) {
		Value = -Value;
	}
	return Value;
}


static int64 ParseNumbers_( JB_String* self, int Start, Message* Where, int AsHex ) {
// assumes valid input
	if (self) {
		MiniStr S = {self->Length-Start, self->Addr+Start};
		return ParseNumbers__( self, AsHex, Where, S );
	}
	return 0;
}


int64 JB_Str_TextIntegerSection( JB_String* self, int Start, Message* b ) {
	return ParseNumbers_( self, Start, b, 0 );
}

int64 JB_Str_HexIntegerSection( JB_String* self, int Start, Message* b ) {
	return ParseNumbers_( self, Start, b, 2 );
}

int64 JB_Str_HexInteger( JB_String* self, Message* b ) {
	return ParseNumbers_( self, 0, b, 2 );
}

int64 JB_Str_TextIntegerValid( JB_String* self, Message* b ) {
	return ParseNumbers_( self, 0, b, 0 );
}



////////////    #include "StringAlterCopy.i" 

inline bool CanByteReplace_(MiniStr F, MiniStr T, bool Lexer) {
	uint8 FindChar = F.Curr();
	if ( F.Length == 1  and  T.Length == 1 ) {
		if (Lexer and FindChar >= 'a' and FindChar <= 'z') {
			; //
		} else if (Lexer and FindChar >= 'A' and FindChar <= 'Z') {
			; //
		} else {
			return true;
		}
	}
	return false;
}



JB_String* JB_Str_ReplaceAll(JB_String* self, JB_String* Old, JB_String* New, bool Lex, FastString* fs_in) {
    FastString* fs = JB_FS__FastNew(fs_in);
    int prev = 0;
    int curr = JB_Str_InStr(self, Old, 0, kJB__int_max, Lex);
    while (curr >= 0) {
        JB_FS_AppendRange(fs, self, prev, curr);
        JB_FS_AppendString(fs, New);
        curr = (curr + JB_Str_Length(Old));
        prev = curr;
        curr = JB_Str_InStr(self, Old, curr, kJB__int_max, Lex);
    };
    if (!fs->Length and !fs_in) {
        return self;
    }
    JB_FS_AppendRange(fs, self, prev, kJB__int_max);
    return JB_FS_SmartResult(fs, fs_in);
}


JB_String* JB_Str_MultiReplaceAll(JB_String* self, Dictionary* Dict, JB_ErrorReceiver* Rec) {
	return JB_MSR_ReplaceAll(Dict, self, 0, Rec);
}


JB_String* JB_FS_Return( JB_String* Data, FastString* fs_in ) {
	if ( fs_in ) {
        JB_FS_AppendString( fs_in, Data );
        return 0;
	}

    return Data;
}

JB_String* JB_FS_SmartResult( FastString* fs, JB_Object* Orig ) {
	if ( !Orig ) {
		return JB_FS_GetResult( fs );
	}
	return EmptyString_;
}


JB_String* JB_Str_Hex(JB_String* s, int Spaces, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew( fs_in );
	JB_FS_AppendHexData( fs, JB_Str_Address(s), JB_Str_Length(s), Spaces );
	return JB_FS_SmartResult( fs, fs_in );
}


// bytemap should be removed. Just... do upper/lower manually!
static int BM_Affects_(ByteMap* BM, JB_String* s) {
	if (s and BM) {
		uint8* map = BM->Cache;
		uint8* a = s->Addr;
		int n = s->Length;
		for_(n) {
			uint8 c = a[i];
			if (map[c] != c) {
				return i;
			}
		}
	}
	return -1;
}

JB_String* JB_Str_MapBytes(JB_String* s, ByteMap* BM, int Clear) {
	if ( BM_Affects_( BM, s ) == -1 ) return s;

	JB_String* r = JB_Str_New( s->Length );

	uint8* map = BM->Cache;
	uint8* SelfPos = s->Addr;
	uint8* OutPos = r->Addr;
	int SelfLen = s->Length;

	while ( SelfLen-- > 0 ) {
		uint8 C = map[ *SelfPos++ ];
		if (C!=Clear)
			*OutPos++ = C;
	}
	r->Length = (int)(OutPos - r->Addr);

	return r;
}


JB_String* JB_Str_UnHex(JB_String* self, FastString* fs_in) {
	int SelfLen = JB_Str_Length(self);
	require(SelfLen);
	uint8* SelfPos = self->Addr;
	FastString* fs = JB_FS__FastNew( fs_in );
    JB_FS_SizeSet(fs, SelfLen / 2);
	
	
	if ( fs->Reserved ) {
		int PrevByte = -1;

		while ( SelfLen-- ) {
			u32 byte2 = (u32)*SelfPos++;
			if (byte2 >= '0' and byte2 <= '9') {
				byte2 = byte2 - 48;
			} else if (byte2 >= 'a' and byte2 <= 'f') {
				byte2 = 10+(byte2 - 'a');
			} else if (byte2 >= 'A' and byte2 <= 'F') {
				byte2 = 10+(byte2 - 'A');
			} else { // ignore
				continue;
			}

			if ( PrevByte >= 0 ) { // much better
				JB_FS_AppendByte(fs, (PrevByte<<4)|(byte2));
				PrevByte = -1;
			} else {
				PrevByte = byte2;
			}	
		}
	}

	return JB_FS_SmartResult( fs, fs_in );
}


JB_String* JB_ASCII() {
    static JB_String* ASCII = 0;
    if (!ASCII) {
        static const char kASCII[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 0};
        ASCII = JB_New( JB_String );
        ASCII->Addr = (uint8*)kASCII;
        ASCII->Length = 128;
        JB_Incr(ASCII);
    }
    return ASCII;
}

JB_String* JB_Upper() {
    return JB_Str_Range( JB_ASCII(), 'A', 'Z' + 1 );
}

JB_String* JB_Lower() {
    return JB_Str_Range( JB_ASCII(), 'a', 'z' + 1 );
}



JB_String* JB_Str_FastLower (JB_String* self) {
    int N = self->Length;    
    uint8* A = self->Addr;
    for_(N) {
		uint8 C = *A++;
		if (C >= 'A' and C <= 'Z') {	// need lower-casing
			return JB_Str_LowerCase(self);
		}
	}

    return self;
}


ByteMap* JB_BM__Lower() {
    static ByteMap* LowerMap_ = 0;
    if (!LowerMap_) {
        LowerMap_ = JB_BM_Constructor( 0, JB_Upper(), JB_Lower() );
        JB_Incr(LowerMap_);
    }
    return LowerMap_;
}

JB_String* JB_Str_LowerCase(JB_String* self) {
	return JB_Str_MapBytes( self, JB_BM__Lower(), -1 );
}
// bytemap should be removed!
JB_String* JB_Str_UpperCase(JB_String* self) {
    static ByteMap* UpperMap_ = 0;
    if (!UpperMap_) {
        UpperMap_ = JB_BM_Constructor( 0, JB_Lower(), JB_Upper() );
        JB_Incr(UpperMap_);
    }
	return JB_Str_MapBytes( self, UpperMap_, -1 );
}


bool Nameable_(uint8 C, bool Mid) {
	if (C >= 'A' and C <= 'Z')
		return 1;
	if (C >= 'a' and C <= 'z')
		return 1;
	if (C=='_')
		return 1;
	if (Mid and C >= '0' and C <= '9')
		return 1;
	return 0;
}

bool JB_Str_IsAsciiName(JB_String* self) {
	require (self);
	uint8* A	 = self->Addr;
	for_ (self->Length)
		require(Nameable_(A[i], i));
	return true;
}



CharSet* JB_CS_Constructor(CharSet* self, JB_String* Source, bool Ranges);
CharSet* TrimCS_() {
	static CharSet* cs;
	if (!cs) {
		JB_String Dummy;  Dummy.Addr = (uint8*)" \t\n\r\0";  Dummy.Length = 5;
		cs = JB_CS_Constructor(nil, &Dummy, false);
	}
	return cs;
}

JB_String* JB_Str_Trim(JB_String* self, CharSet* CS) {
	int n = JB_Str_Length(self);
	if (n <= 0)
		return self;
	if (!CS) CS = TrimCS_();
	uint8* CC = CS->Cache;
	byte* Addr = self->Addr;
	
	int i = 0;
	for (; i < n; i++)
		if (!CC[Addr[i]])
			break;
	for (; i < n; n--)
		if (!CC[Addr[n-1]])
			break;
	return JB_Str_Range(self, i, n);
}


JB_String* JB_Str_ReplaceAllB(JB_String* self, int lFrom, int lTo) {
	return JB_Str_ReplaceBytesSub_(self, lFrom, lTo, 0 );
}

JB_String* JB_Str_ReplaceBytesSub_(JB_String* self, int lFrom, int lTo, FastString* fs_in) {
	int FirstOff = JB_Str_InByte( self, 0, kMaxint, lFrom );
	if ( FirstOff < 0 )
		return JB_FS_Return(self, fs_in);

	FastString* fs = JB_FS__FastNew(fs_in);
	int Length = self->Length;
	uint8* WriteTo = JB_FS_WriteAlloc_(fs, Length);
	if (!WriteTo) {
		return 0;
	}
	if (FirstOff) {
		CopyBytes( self->Addr, WriteTo, FirstOff );
	}

	uint8* SelfPos = self->Addr + FirstOff;
	uint8* OutPos  = WriteTo + FirstOff;
	int SelfLen = Length - FirstOff;

	while ( SelfLen-- ) {
		uint8 Char = *SelfPos++;
		if (Char == (uint8)lFrom) {
			Char = (uint8)lTo;
		}
		*OutPos++ = Char;
	}

    return JB_FS_SmartResult(fs, fs_in);
}


JB_String* JB_Str_Reverse(JB_String* self, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	int i = JB_Str_Length(self);
	uint8* P = JB_FS_WriteAlloc_(fs, i);
	uint8* R = self->Addr;
	if (P and R)
		while (i > 0)
			*P++ = R[--i];
	return JB_FS_SmartResult(fs, fs_in);
}



//////////    #include "StringSplitters.i"

extern "C" void Str_Share_(JB_StringShared* u, JB_String* p, int i, int L) {
	u->Addr = p->Addr + i;
	u->Length = L;
	JB_Class* Cls = JB_ObjClass(p);
	if (Cls==JB_AsClass(JB_StringShared)) {
		p = (JB_String*)((JB_StringShared*)p)->Parent;
	}
	u->Parent = JB_Incr( p );
}

extern "C" void JB_Str_Clone(JB_StringShared* self, JB_String* orig) {
	if (!orig)
		orig = JB_Str__Empty();
	Str_Share_(self, orig, 0, JB_Str_Length(orig));
}


JB_String* JB_Str_Range(JB_String* self, int StartOff, int AfterOff) {
	if_rare ( !self ) {
		debugger;
		return 0;
	}
	if_rare ( StartOff < 0 )
		StartOff = 0;

	int CurrLen = self->Length;
	if ( (u32)AfterOff > (u32)CurrLen )
		AfterOff = CurrLen;

    int Length = AfterOff - StartOff;
    if ( CurrLen == Length )
        return self;

	if ( Length > 1 ) {
        if (Length <= 4)
            return JB_Str_CopyFromPtr( (uint8*)self->Addr + StartOff, Length);
        
        JB_StringShared* u = JB_New( JB_StringShared );
        if_usual ( u )
			Str_Share_(u, self, StartOff, Length); 

        return u;

    } else if ( Length == 1 ) {
		return JB_Str__Byte( self->Addr[StartOff] );
	}

	return JB_Str__Empty();
}


// useful later when I add support for faster string appends...
// to make error reporting take up less code = less bloat!
static JB_String* Str_Append_(JB_String* Items[], int N, int Bytes) {
    if (N == 1) return Items[0];
	if (Bytes <= 0) return JB_Str__Empty();

    // OK so we got the length...
    JB_String* Result = JB_Str_New( Bytes );
    if (Result) {
		uint8* WriteTo = Result->Addr;
		for (int i = 0; i < N; i++) {
			JB_String* S = Items[i];
			CopyBytes(S->Addr, WriteTo, S->Length);
			WriteTo += S->Length;
		}
    }
    
    return Result;
}



#define Append_(X) if (X) {int L = X->Length; N += L; if (L) {Items[i++] = X;}}
JB_String* JB_Str_Append4(JB_String* A, JB_String* B, JB_String* C, JB_String* D) {
    JB_String* Items[4];
    int i = 0;
    int N = 0;
    Append_(A);
    Append_(B);
    Append_(C);
    Append_(D);
    return Str_Append_(Items, i, N);
}

JB_String* JB_Str_Append6(JB_String* A, JB_String* B, JB_String* C, JB_String* D, JB_String* E, JB_String* F) {
    JB_String* Items[8];
    int i = 0;
    int N = 0;
    Append_(A);
    Append_(B);
    Append_(C);
    Append_(D);
    Append_(E);
    Append_(F);
    return Str_Append_(Items, i, N);
}
#undef Append_


JB_String* JB_Str_OperatorPlus(JB_String* self, JB_String* other) {
    int NS = JB_Str_Length(self);
    int NO = JB_Str_Length(other);
    if (!NS)
        return other;
    if (!NO)
        return self;

    JB_String* s = JB_Str_New( NS + NO );
    if (s) {
        CopyBytes(self->Addr, s->Addr, NS);
        CopyBytes(other->Addr, s->Addr + NS, NO);
    }
    return s;
}


JB_String* JB_Str_Unshare(JB_String* self) {
// avoid wasting RAM when we this str is only a small part of a big file!!
    if (self and JB_ObjClass(self) == JB_AsClass(JB_StringShared)) {
        return JB_Str_Copy(self);
    }
    return self;
}


JB_Object* JB_Str_Owner(JB_String* self) {
// avoid wasting RAM when we this str is only a small part of a big file!!
    if (self and JB_ObjClass(self) == JB_AsClass(JB_StringShared)) {
        return ((JB_StringShared*)self)->Parent;
    }
    return self;
}


/////////    #include "StringEncoding.i"

JB_String* JB_Str_UnicodeSync(JB_String* Str) {
    int i = JB_Str_Scan_BadUTF8AtEnd(Str);
    if (i) {
        return JB_Str_Range(Str, 0, JB_Str_Length(Str) - i);
    }
    return Str;
}


JB_String* JB_Str_BOM (int Encoding, bool IsBigEndian) {
	uint8 Write[4];
	int Len = 0;

	if (Encoding == kEncUTF8) {
		Len = 3;
		Write[0] = (uint8)kUTF8BOM1;
		Write[1] = (uint8)kUTF8BOM2;
		Write[2] = (uint8)kUTF8BOM3;
	} else if (Encoding == kEncUTF16) {
		Len = 2;
		if (IsBigEndian) {
			*(u16*)Write = (u16)kUTF16BBOM;
		} else {
			*(u16*)Write = (u16)kUTF16LBOM;
		}
	} else if (Encoding == kEncUTF32) {
		Len = 4;
		if (IsBigEndian) {
			*(u32*)Write = (u32)kUTF32BBOM;
		} else {
			*(u32*)Write = (u32)kUTF32LBOM;
		}
	}

	JB_String* result = JB_Str_New( Len );
	if (result and Len) {
		CopyBytes( Write, result->Addr, Len );
	}

	return result;
}


JB_String* JB_Str_ChrUTF8(u32 C) {
	if (C <= 127) {
		return JB_Str__Byte( C );
	}
    
	u32 N = JB_Str_UTF8Size( C );
    if (N) {
		JB_String* Result = JB_Str_New( N );
		if ( Result ) {
			u8Write_( Result->Addr, C );
			return Result;
		}
    }
    return JB_Str__Error();
}


bool JB_Str_UniValid( u32 c ) { // negative c looks like > 2 billion, which is going to return false!
	if ( c < UNI_SUR_HIGH_START ) { // common case first
		return true;
	} else if ( c <= UNI_MAX_UTF and c > UNI_SUR_LOW_END and c != 0xFFFF and c != 0xFFFE ) {
		return true;
	}
	return false;
}


int JB_Str_LengthUTF8(JB_String* self) {
	return u8Count_( self->Addr, self->Length );
}


////////////    #include "StringProperties.i"


bool JB_Str_IsASCII(JB_String* self) {
	return IsAsciiSub_( self->Addr, self->Length );
}

uint64 JB_CRC (u8* buf, uint64 crc, int n) {
	if (n <= 0)
		return crc;
	
	u64* six = (u64*)buf; 
	for_(n>>3) {
		crc ^= JB_uint64_hash(*six++);
	}
	if (n&7) {
		buf = (u8*)six;
		u64 Last = 0;
		for_(n&7) {
			Last <<= 8;
			Last |= *buf++;
		}
		crc ^= JB_uint64_hash(Last);
	}
	
	return crc;
}


uint64 JB_Str_CRC (JB_String* S, uint64 crc) {
	return JB_CRC( JB_Str_Address(S), crc, JB_Str_Length(S));
}


Array* JB_Array_Constructor0( Array* self );
Array* JB_Str_ArgV(const char** ArgV) {
    Array* Result = JB_Array_Constructor0(nil);
    while (ArgV) {
        const char* c = *++ArgV;
        if (!c)
			break;
        if (c[0] == '-' and c[1] == '-' and c[2] == 0)
			break; // useful to ignore arguments that xcode is spamming us with.
        JB_Array_Append(Result, JB_StrC(c));
    }
    return Result;
}


Dictionary* JB_EnvC(const char** self) {
    Dictionary* D = JB_Dict_Constructor(nil);
    
	if (self) for (int i = 0; const char* C = self[i]; i++) {
        JB_String* S = JB_StrC(C);
        if (JB_Str_Exists(S)) {
            int Eq = JB_Str_InByte(S, 0, kJB__int_max, '=');
            JB_String* Before = JB_Str_Range(S, 0, Eq);
            JB_String* After = JB_Str_Range(S, Eq + 1, kJB__int_max);
            (JB_Dict_ValueSet(D, Before, After));
            JB_FreeIfDead(Before);
            JB_FreeIfDead(After);
        }
		JB_FreeIfDead(S);
    };
    return D;
}


JB_String* JB_Str__Error() {
	return ErrorString_;
}


JB_String* JB_Str__Empty() {
	return EmptyString_;
}


bool JB_Str_Exists(JB_String* Str) {
	return  (Str and Str->Length);
}



JB_String* JB_Str_FromInt( int L, int R ) {
	FastString* FS = JB_FS__FastNew( 0 );
	JB_FS_SizeSet( FS, 16 );
	JB_FS_AppendIntegerAsText( FS, L, R );
	return JB_FS_GetResult( FS );
}


struct ChrBData {
	JB_String* Objects[256];
};
static ChrBData StrByteObjs = {};

JB_String* JB_Str__Byte (int i) {
	i&=0xFF;
	JB_String* Result = StrByteObjs.Objects[i];
	if (Result)
		return Result;

    Result = JB_Str_New(1);
	StrByteObjs.Objects[i] = (JB_String*)JB_Incr(Result);
    Result->Addr[0] = i;
	return Result;
}


////////////    #include "StringRender.i"


void JB_FS_AppendEscape(FastString* fs, JB_String* self);
// actually made by jeebox... :/ sigh.
// I suppose it COULD be built in? I mean... why not, at this point?
// It's not as if I'm gonna be building tiny 4K apps...
// more like a standard library/compiler/IDE/whatever
// and... tiny 4k apps being VMed by it!!

// Assuming Jeebox might be a GOOD thing. And it's small... besides. 90K?


JB_String* JB_Str_Render(JB_String* self, FastString* fs_in) {
    FastString* fs = JB_FS__FastNew(fs_in);
    JB_FS_AppendByte(fs, '"');
    JB_FS_AppendEscape(fs, self);
    JB_FS_AppendByte(fs, '"');
	return JB_FS_SmartResult( fs, fs_in );
}


JB_String* JB_CStr_Render(const char* Name, FastString* fs_in) {
    if (!fs_in)
        return JB_StrC(Name); 
    
    JB_FS_AppendCString(fs_in, Name);
    return 0;
}


JB_String* JB_Obj_GenericRender(JB_Object* self, FastString* fs_in) {
    // OK so! We have... a generic renderer... what should it do?
    // well... let's see? something that parses OK in jeebox and we can understand OK?
    // ["abc"] // array of string
    // [1234]  // array of int-object
    // [(1,2,3)] // array of set
    // [JB_List(741)] // seems to make sense?
    FastString* fs = JB_FS__FastNew(fs_in);

    JB_Class* Cls = JB_ObjClass(self);
    JB_FS_AppendCString(fs, (const char*)Cls->Name);
    JB_FS_AppendCString(fs, "(");
    JB_FS_AppendIntegerAsText(fs, JB_ObjectID(self), 1);
    JB_FS_AppendByte(fs, ')');

	return JB_FS_SmartResult( fs, fs_in );
}


JB_String* JB_Obj_Render(JB_Object* self, FastString* fs_in) {
    // OK so first we want the class...
    if (!self) {
        return JB_CStr_Render("(nil)", fs_in);
    }
    
    JB_Class* Cls = JB_ObjClass(self);
    auto R = Cls->CppTable->render;
    fpRenderer FN = (fpRenderer)R;
    if (!FN or (FN == JB_Obj_Render)) {
        return JB_Obj_GenericRender(self, fs_in);
    }
    
    return (FN)(self, fs_in);
}




} // 


