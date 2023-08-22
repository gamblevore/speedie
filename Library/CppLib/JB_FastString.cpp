
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt




        /* InLines and useful */


#include "JB_Umbrella.hpp"
#include <time.h>

extern "C" {

#define kDefaultSize (1024*2)

inline uint8 NumToHex(u32 Num) {
	if ( Num <= 9 )
		return Num + '0';
	return Num + ('A'-10);
}


void JB_FS_AppendMini(FastString* fs, MiniStr S) {
	FS_SanityCheck_(fs);
	dbgexpect(fs);
	dbgexpect(S.Length >= 0);

    uint8* Write = JB_FS_WriteAlloc_Inline_(fs, (int)S.Length);
    
	if (S.Length < 8) {
		while ( S )
			*Write++ = S.Next();
	} else {
		CopyBytes(S.Addr, Write, S.Length);
	}
    
	FS_SanityCheck_(fs);
}


void JB_FS_AppendMem_(FastString* fs, const uint8* s0, int Length) {
    MiniStr S = {Length, (uint8*)s0};
	JB_FS_AppendMini(fs, S);
}

uint8* JB_FS_WriteAlloc_(FastString* fs, int GrowBy) {
	return JB_FS_WriteAlloc_Inline_(fs, GrowBy);
}


int JB_FS_FreeSize(FastString* fs) {
	return fs->Reserved - fs->Length;
}

uint8* JB_FS_NeedSpare(FastString* fs, int Extra) { //JB_FS_FreeSizeSet
    int Spare = JB_FS_FreeSize(fs);
    if (Spare < Extra)
        if (!JB_FS_ResizeTo_(fs, fs->Reserved + Extra))
			return 0;
    return fs->ResultPtr + fs->Length;
}


void JB_FS_AppendDMY (FastString* fs, Date self) {
    time_t t = self >> 16; // lol
    tm TimeSpec;
    if (localtime_r( &t, &TimeSpec )) {
		char* write = (char*)JB_FS_WriteAlloc_(fs,26);
		if (write) {
			asctime_r(&TimeSpec, write);
			fs->Length-=2; // sigh
		}
    }
}

JB_String* JB_FS_Copy(FastString* fs) {
    FS_SanityCheck_(fs);
    return JB_Str_CopyFromPtr(fs->ResultPtr, fs->Length);
}

bool JB_FS_ResizeTo_(FastString* fs, int NewLength) {
    FS_SanityCheck_(fs);
    if (NewLength == fs->Reserved) {
        return true;
    }

	auto S = fs->Result;
//	if (S) {
//		int OldLength = S->Length;
//		if (NewLength < OldLength and S->RefCount > 1) {
//			JB_BA_Realloc_(S, fs->Length);
			// OK... this is an interesting issue. We have a wierd sharing behaviour. We need to just...
			// let go of it? or something? but at least shrink it down to the OldLength

			// lets say we have a big buffer
			// and a small portion of it shared
			// then we append something huge, so we need a HUGER buffer
			// we cant keep the old buffer... so we gotta make a new one
			// But we can't realloc the old one, right? It could MOVE in memory. Easily it can.
			// especially if it becomes very short. So... if it becomes short and moved...
			// then everything that uses it... becomes fucked. So we need to NOT realloc it.
			// so that means we need to keep the huge buffer.
			// seems better to just copy the buffer?
//		}
//	}
	if (!S) {
		if (fs->ResultPtr) {fs->Failed = true; return 0;}; // direct memory write.
		S = JB_Incr(JB_New( JB_String ));
		S->Addr = 0;
		fs->Result = S;
	}
	// So what if the size is lower than the current? AND if the current is... shared?

	require (JB_BA_Realloc_(S, NewLength));
    
    fs->Reserved = (int)JB_msize(S->Addr);
    fs->ResultPtr = S->Addr;
	fs->Length = Min(NewLength, fs->Length);

    return true;
}


uint8* JB_FS_GrowBy(FastString* fs, int Needs) {
    if ( JB_FS_Flush( fs ) and fs->Reserved >= Needs ) {
        fs->Length = Needs;
        return fs->ResultPtr;
    }

    int NewLength = fs->Length + Needs;
    if ( NewLength < kDefaultSize ) {
        NewLength = fs->File ? 32*1024 : kDefaultSize;
    }

    for (  int i = 2;   i >= 1;   i = i / 2  ) {
        if (NewLength*i  >=  NewLength) {
            if (JB_FS_ResizeTo_(fs, NewLength*i-1)) { // -1 to zeroterm
                int L = fs->Length;
                fs->Length = L + Needs;
                return fs->ResultPtr + L;
            }
        }
    }

    return 0;
}



	/* Appends */

void JB_FS_AppendString( FastString* self, JB_String* u ) {
	if ( u ) {
		JB_FS_AppendMem_( self, u->Addr, u->Length );
	}
}

void JB_FS_AppendLine( FastString* self, JB_String* u ) {
	JB_FS_AppendString(self, u);
	JB_FS_AppendByte(self, 10);
}


void JB_FS_AppendSection(FastString* self, JB_String* Data, int srStart, int srLength) {
	if ( Data and SectFix_( srStart, srLength, Data->Length ) ) {
        JB_FS_AppendMem_(self, Data->Addr + srStart, srLength );
	}
}

void JB_FS_AppendCString2(FastString* self, uint8* c) {
    JB_FS_AppendCString(self, (const char*)c);
}

void JB_FS_AppendCString(FastString* self, const char* c) {
    if ( c ) {
        int Length = (int)strlen( c );
        if (Length) {
            JB_FS_AppendMem_(self, (uint8*)c, Length);
        }
    }
}


void JB_FS_AppendByte(FastString* self, int byte) {
	uint8* Write = JB_FS_WriteAlloc_Inline_(self, 1);
	if ( Write ) {
		*Write = (uint8)byte;
	}
	FS_SanityCheck_(self);
}

int JB_FS_Last (FastString* self, int off) {
	int N = self->Length; 
	int i = N-(1+off);
	if ((uint)i < N)
		return self->ResultPtr[i];
	return -1;
}

    
void JB_FS_RemoveByte(FastString* self, byte B) {
    uint8* Addr = self->ResultPtr;
    if (Addr) {
        int Len_m_1 = self->Length - 1;
        if (Addr[Len_m_1] == B) {
            self->Length = Len_m_1;
        }
    }
}


void JB_FS_AppendMultiByte(FastString* self, int byte, int Count) { // - numbers become +2billion!
	if ( Count > 0 ) {
		uint8* Write = JB_FS_WriteAlloc_(self, Count);
		if (Write) {
			for ( ; Count > 0; Count-- ) {
				*Write++ = (uint8)byte;
			}
		}
	}
	FS_SanityCheck_(self);
}


void JB_FS_AppendIndent( FastString* self ) {
	JB_FS_AppendByte( self, '\n' );
    if (self->IndentChar) {
        JB_FS_AppendMultiByte( self, self->IndentChar, self->Indent );
    }
}


void JB_FS_AppendUTF8Char(FastString* self, int Char) {
    uint8* WritePos = JB_FS_WriteAlloc_Inline_(self, 4);
    if (WritePos) {
        int WroteLen = (int)(u8Write_( WritePos, Char ) - WritePos);
        JB_FS_AdjustLength_( self, 4, WroteLen );
    }
}


// this function must be able to write hex, in varying outputs.

void JB_FS_AppendHexSub(FastString* fs, int64 tVal, int RoundTo, uint8* CharMap) {
	RoundTo = std::min(RoundTo, 8);
	RoundTo = std::max(RoundTo, 1);
	int Bytes = 1;
	if (tVal)
		Bytes += ((int)JB_u64_Log2(tVal)>>2);
	int pd = Bytes % RoundTo;
	if (pd) while (pd++ < RoundTo)
		JB_FS_AppendByte(fs, '0');
	while ( Bytes-- > 0 ) {
		int64 oof = tVal >> (Bytes*4);
		oof &= 15;
		JB_FS_AppendByte(fs, CharMap[oof] );
	}
}


void JB_FS_AppendMultiReplace(FastString* self, JB_String* Data, Dictionary* MSR, JB_ErrorReceiver* Rec) {
	if ( MSR and Data )
		JB_MSR_ReplaceAll( MSR, Data, self, Rec );
	  else
		JB_FS_AppendString( self, Data );
}


void JB_FS_AppendLower(FastString* fs, JB_String* Data) {
    JB_FS_AppendByteMap(fs, Data, JB_BM__Lower());
}


void JB_FS_AppendByteMap(FastString* fs, JB_String* Data, ByteMap* BM) {
	require0 ( BM and Data );	
	int Length = Data->Length;
	uint8* wp = JB_FS_WriteAlloc_(fs, Length);
	require0 (wp);
	
	uint8* SelfPos = Data->Addr;
	uint8* map = BM->Cache;

	while ( Length-- > 0 )
		*wp++ = map[ *SelfPos++ ];
}


void JB_FS_AppendReplaceB(FastString* self, JB_String* Data, int From, int To) {
	JB_Str_ReplaceBytesSub_( Data, From, To, self );
}


// "2 000 000 000" is 10 int!

uint8* JB__WriteIntToBuffer (uint8* wp, int64 LeftOver) {
    do {
        int64 NewLeftOver = LeftOver / 10;
        int64 ThisChar = LeftOver - (NewLeftOver * 10) + '0';
        *--wp = (uint8)ThisChar;
        LeftOver = NewLeftOver;
    } while (LeftOver);
    return wp;
}


int JB_int_Render(int self, byte* Addr, int N) {
	return snprintf((char*)Addr, N, "%i", self);
}

void JB_FS_AppendIntegerAsText(FastString* self, int64 LeftOver, int RoundTo) {
	if (RoundTo <= 0) {RoundTo = 1;} else if (RoundTo > 16) {RoundTo = 16;}
     
	if (!LeftOver) {
		JB_FS_AppendMultiByte( self, '0', RoundTo ); return;
	}

	const int Alloced = 21; 
	uint8* wp = JB_FS_WriteAlloc_( self, Alloced );
	if ( !wp )
        return;

    int SignLen = 0; // can remove signlen and just put PadCount here...
    
    if (LeftOver < 0) {
        *wp++ = '-';
        LeftOver = -LeftOver;
        if (LeftOver <= 0) { return; } // PPC oddity
        SignLen = 1;
    }
	
    double tmpCount = log10( (double)LeftOver ); // all math lib funcs are DAMN fast.
    dbgexpect( tmpCount >= 0 and tmpCount <= 19 );
    int CountDigits = (int)tmpCount + 1;
    int PadCount = (CountDigits + SignLen) % RoundTo;
    if (PadCount) PadCount = RoundTo - PadCount;
    int PadFirst = PadCount;

    wp = wp + CountDigits + PadCount;
    wp = JB__WriteIntToBuffer(wp, LeftOver);

    while ( PadCount-- ) {
        *--wp = '0';
    }
    
    JB_FS_AdjustLength_( self, Alloced, CountDigits + PadFirst + SignLen );
}


void JB_FS_AppendDurr(FastString* self, Date D) {
    JB_FS_AppendDoubleAsText(self, ((double)D) / ((double)0x10000), 3, false);
}


void JB_FS_AppendDoubleAsText0(FastString* self, double D) {
    JB_FS_AppendDoubleAsText(self, D, 9, true);
}


bool HasDot (uint8* self, int Used) {
	for_ (Used) {
		if (self[i] == '.')
			return true;
	}
	return false;
}



void JB_FS_AppendDoubleAsText(FastString* self, double D, int dp, bool CanExp) {
// need a "mode" really... what about if we want no exp but DO want the full length?
    dp = Max(dp, 0);
    dp = Min(dp, 16);
    
    if (D < 0) {
		D = -D;
		JB_FS_AppendByte(self, '-');
	}
    int ActualExp = 0;
    if (CanExp and D) {
		double exp = log10(D);
		if (exp > 16.0 or exp < -9) {
			ActualExp = (int)floor(exp);
			D = D / JB_Pow10(ActualExp);
		}
	}
    
	double F = floor(D);
	double Frac = D-F;
	JB_FS_AppendIntegerAsText(self, F, 1);
	if (Frac and dp > 0) {
		JB_FS_AppendByte(self, '.');
		while (Frac and dp > 0) {
			dp--;
			Frac *= 10;
			double Num = floor(Frac);
			Frac -= Num;
			JB_FS_AppendByte(self, '0'+Num);
		}
	}
	if (ActualExp) {
		JB_FS_AppendByte(self, 'e');
		JB_FS_AppendIntegerAsText(self, ActualExp, 1);
	}
}



void JB_FS_AppendShort(FastString* self, int s) {
	short* wp = (short*)JB_FS_WriteAlloc_( self, 2 );
	if (wp)
		*wp = (short)s;
	FS_SanityCheck_(self);
}


// can’t share Appendint, due to float passing conventions :o(   )
void JB_FS_AppendSingle(FastString* self, float f) {
	float* fp = (float*)JB_FS_WriteAlloc_( self, 4 );
	if (fp)
		*fp = f;
	FS_SanityCheck_(self);
}


void JB_FS_AppendInteger(FastString* self, int l) {
	int* wp = (int*)JB_FS_WriteAlloc_Inline_( self, 4 );
	if (wp) {
		*wp = l;
	}
	FS_SanityCheck_(self);
}


void JB_FS_AppendDouble(FastString* self, double d) {
	double* fp = (double*)JB_FS_WriteAlloc_( self, 8 );
	if (fp)
		*fp = d;
	FS_SanityCheck_(self);
}



               /* Utilities */
int JB_FS_Mark(FastString* self) {
	return self->WrittenLength + self->Length;
}


bool JB_FS_Grew(FastString* self, int Old) {
	return (Old < JB_FS_Mark(self)); 
}



int JB_FS_Byte(FastString* fs, int offset) {
	if ((u32)offset < fs->Reserved)
		return fs->ResultPtr[offset];
	return -1;
}

void JB_FS_ByteSet(FastString* fs, int offset, byte B) {
	if ((u32)offset < fs->Reserved)
		fs->ResultPtr[offset] = B;
}



               /* Properties */

int JB_FS_Size(FastString* fs) {
	FS_SanityCheck_(fs);
	return fs->Reserved;
}


void JB_FS_SizeSet(FastString* fs, int NewSize) {
	if (NewSize < 1)
		JB_FS_Destructor( fs );
	  else
		JB_FS_ResizeTo_( fs, NewSize );
}


int JB_FS_Length(FastString* self) {
	FS_SanityCheck_(self);
	return self->Length;
}

int JB_FS_StreamLength(FastString* self) {
	return self->Length + self->WrittenLength;
}

void JB_FS_LengthSet(FastString* fs, int NewLength) {
    if ((u32)NewLength < (u32)fs->Reserved) {
        fs->Length = NewLength;
    }
	FS_SanityCheck_(fs);
}


bool JB_FS_Flush(FastString* fs) {
    JB_File* File = fs->File;
    if ( File and !fs->NoFlush ) {
        int N = fs->Length;
        if ( N ) {
            N = (int)JB_File_WriteRaw_( File, fs->ResultPtr, N );
            fs->WrittenLength += N;
            fs->Length = 0;
        }
		return true;
    }
    return false;
}

JB_File* JB_FS_File(FastString* fs) {
    return fs->File;
}

void JB_FS_FileSet(FastString* fs, JB_File* F) {
    JB_SetRef( fs->File, F );
    if (!F->Descriptor) {
        JB_File_OpenBlank(F);
    }
}


            /* Constructors */

void JB_FS_ConstructorSize(FastString* self, int Size) {
    JB_FS_Constructor(self);
	if ( Size ) {
		JB_FS_SizeSet( self, Size );
	}
}

void JB_FS_Constructor(FastString* self) {
    JB_Zero(self);
    self->IndentChar = '\t';
}

void JB_FS_Destructor(FastString* self) {
	// .dispose can call this.
	if (self->PrintLineOnClear) {
		JB_FS_AppendByte(self, '\n');
	}
    JB_FS_Flush( self );
    JB_SetRef( self->Result, 0 );
	JB_SetRef( self->File, 0 );
    JB_FS_Constructor(self); // clear pointers and length
}


JB_String* JB_FS_GetResult(FastString* self) {
	if (!self)
		return JB_Str__Empty();
	if (self->PrintLineOnClear) {
		JB_FS_AppendByte(self, '\n');
	}
	int Length = self->Length;
	JB_String* Result = self->Result;
    if (Result)
		JB_SafeDecr(Result);
	  else
		Result = JB_Str__Empty();
	JB_SetRef( self->File, 0 );
    JB_FS_Constructor(self);

	return Str_Shrink(Result, Length); // calls freeifdead
}


FastString* JB_FS__InternalNew() {
    FastString* fs = JB_New(FastString);
    JB_FS_Constructor( fs );
    return fs;
}

FastString* JB_FS__FileFlush(JB_File* f, bool b) {
	FastString* fs = JB_FS__InternalNew();
	fs->File = JB_Incr(f);
	fs->PrintLineOnClear = b;
	return fs;
}


FastString* TheSharedFastString;
FastString* JB_FS__FastNew(FastString* other) {
    if (other) {
        return other;
    }
    
	FastString* fs = TheSharedFastString; 
	if (fs and fs->RefCount > 100) debugger;


	if ( !fs or (JB_RefCount(fs) > 1)) {
        JB_SetRef(fs, JB_FS__InternalNew());
		TheSharedFastString=fs;
    } else {
        fs->Length = 0;
    }
    
    return fs;
}



} // 


