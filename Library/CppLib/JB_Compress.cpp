
#include "JB_Compress.h"


#define kExtend 0x70
#pragma GCC optimize O3

inline int u64Cmp(const u64* a, const u64* b, unsigned int n) {
	const u64* aEnd = a + n/8;
	while (a < aEnd) {
		u64 A = u64Sortable(*a++);
		u64 B = u64Sortable(*b++);
		if (B > A)
			return -1;
		  else if (B < A)
			return 1;
	};
	return 0;
}

int CompSorter (const void* _x, const void* _ap, void* _bp) {
	auto x = (const u8*)_x; auto ap = (const int*)_ap; auto bp = (const int*)_bp;
	int a		= *ap;
	int b		= *bp;
	auto va		= x - a;
	auto vb		= x - b;
	// shouldn't n be 128? considering we don't sort the last?
	// might optimise better...
	int n		= min(min(a, b), 128);
	int Result	= u64Cmp((u64*)va,  (u64*)vb, n);
	if (Result)
		return Result;
	return a - b;
}
#pragma GCC reset_options



void JB_SuffixArray(int* R0, int n, void* Thingy) {
#if __PLATFORM_CURR__ == __PLATFORM_LINUX__
	qsort_r(R0,  n - mUnitSize,  sizeof(int),  (__compar)CompSorter,  Thingy); // lol
#else // whyyyyy
	qsort_r(R0,  n - mUnitSize,  sizeof(int),  Thingy,  (__compar)CompSorter);
#endif	
}


struct CompState : FastBuff {
	int					LastOut;
	int*				EndGaps;
	int*				SortPositionAtByte;	
	int					B;
	
	
	bool TestOneCost (u8* Find,  u8* E,  int G,  MatchFound& Best, int Esc) {
		int N		= EndGaps[G];
		u8* Text	= E - N;
		N			= (Text < Find) ? (int)(E-Find) : 2; // we just want to know if any good ones remain.
		int i		= 0;
		for (; i < N; i++)
			if (Find[i] != Text[i]) break;
		
		if (i < 2)
			return STOP; // only gonna get worse. Better checking will make this faster.
		int Back	= (int)(Find - Text);
		if (Back <= 0)
			return CONT;
		
		int FixCost		= (Esc!=0) + 1 - i;
		int VaryCost	= (i > 9) + (Back >= 4096) + (Back >= 64_K);
		int Cost = FixCost + VaryCost;
		int BestCost = Best.Cost();
		if (Cost < BestCost) {
			Best = {Back, i, FixCost, VaryCost};
			return CONT;
		}
		if (Cost == BestCost or Best.Length <= i)
			return CONT;
		return STOP;
	}


	MatchFound BestPos (int R, u8* E) {
		int Self	= SortPositionAtByte[R];		// pos of OUR value.
		int Last	= Expected - mUnitSize;
		int L		= Self - 1;
		int H		= Self + 1;
		int B		= 0;
		B			= max(0, L-250);		// Actually lowers compresion! seem like we are reading A LOT.
		Last		= min(Last, H+250);		// the "next/prev endgaps.changesat[i]" opt would help!
		int Esc		= (R != LastOut)*0x20;
		u8* SelfTest= Read + R;
		
		MatchFound Best = {};
		while (L >= B or H <= Last) {
			if (L >= B    and TestOneCost(SelfTest, E, L--, Best, Esc)==STOP)
				L = -1;
			if (H <= Last and TestOneCost(SelfTest, E, H++, Best, Esc)==STOP)
				H = Last+1;
		}
		return Best;
	}


	u8* Detect () {
		int n		= Expected;
		int* R0		= EndGaps; 
		int* SP		= SortPositionAtByte;
		for_ (n)
			R0[i] = n - i;
	
		qsort_r(R0,  n - mUnitSize,  sizeof(int),  Read + n,  (__compar)CompSorter);

		for_(n)					// code is simple, but concept is confusing.
			SP[n - R0[i]] = i;	// each byte, gets told it's position in R0 (endgaps)
								// just look up SP[byte] and you get the position in SortArray for that byte. 
		return n + Read;
	}
	

////////////////////////////////////////////////////// COMPRESSION ////////////////////////////////////////////////////////////
	int AllocWrite (int Length, int MaxBits) {
		int Over = Length >> MaxBits;
		if (Over) {
			// 0 = 0bytes,  1-15 = 1byte,  16-255 = 2bytes
			int Loop = (JB_Int_Log2(Over) &~ 0x3) + 4;
			while (Loop > 0) {
				Loop -= 4;
				WriteByte( ((Over >> Loop)&15) | kExtend );
			}
		}
		
		return Length & ((1<<MaxBits)-1);
	}


	int Process (int i, u8* TextAfter) {
		auto Found = BestPos(i, TextAfter);
		require (Found);
		EscapeOld(i);
		WriteOffset(Found.Back, Found.Length);
		dbgexpect2 (LastOut <= Expected);
		return Found.Length - 1;
	}

	inline void WriteStr (const void* B, int N) {
		(u8*)CopyBytes(B, Write, N)
		Write+=N;
	}

	inline void WriteByte (u8 B) {
		*Write++ = B;
	}

	// (escapelength),(offsetcount), (escapedata), (offsets), (lengths)
	// (3)((3,4) (7, 10) (99, 4)) (abcd) (5)((3,4) (7, 10) (99, 4)) (7, 10) (99, 4)
	
	void EscapeOld (int NeedUpTo) {
		int L		= LastOut;
		int Length	= NeedUpTo - L;
		require0 (Length > 0);
		LastOut		= NeedUpTo;
		int ToWrite = AllocWrite(Length - 1, 4);
		WriteByte(ToWrite);
		WriteStr(Read+L, Length);
	}


	void WriteOffset (int Offset, int Length) {
		dbgexpect(Length >= 0 and Offset >= 1);
		LastOut		   += Length;
		Length			= AllocWrite(Length - 2, 3);			// 0x80 x 1, Length x 3, Offset x 4

		int Orig		= Offset;
		int ShiftCount	= 0;
		while (Offset >= 4096) {
			ShiftCount += 4;
			Offset >>= 4;
		}		
		
		WriteByte( 0x80 | (Length << 4) | (Offset >> 8) );
		WriteByte( Offset & 255 );

		while (ShiftCount > 0) {
			ShiftCount -= 4;
			int Sigh = (Orig >> ShiftCount) & 0xF;
			WriteByte( Sigh | 0x10 );
		}
	}
};



static CompState	sigh;
FastBuff			FB;
static CompState& alloc_compress(JB_String* self, FastString* fs) {
	CompState& C		= sigh;

	int Total			= self->Length;
	int CB				= max(ChunkLen_(Total),12);
	int ChunkLength		= 1<<CB;

	C.Write = JB_FS_NeedSpare(fs, ChunkLength+1024);
	C.WriteStart = C.Write;
	C.WriteEnd = C.Write + ChunkLength;
	C.WriteByte(CB-12);

	if (CB > C.B) {
		C.B = CB;
		C.EndGaps				= (int*)realloc(C.EndGaps,				2*ChunkLength*sizeof(int)); // dict
		C.SortPositionAtByte	= (int*)realloc(C.SortPositionAtByte,	ChunkLength*sizeof(int));
	}

	C.Expected			= Total;
	C.LastOut			= 0;
	C.Read				= JB_Str_Address(self);
	
	return C;
}


extern "C" void JB_Str_CompressChunk (FastString* fs, JB_String* self) { // comfort
	if (!fs or !self)
		return;
	
	int Total	= JB_Str_Length(self);
	require0 (Total);
	DReq(Total <= 2_M, "Chunk size too large",);
	auto& C		= alloc_compress(self, fs);
	if (Total >= 16) {
		auto TextAfter = C.Detect();
		for (int i = 2;  i < Total - 15;  i++)
			i += C.Process(i, TextAfter);
	}

	C.EscapeOld(C.Expected);
	C.WriteByte(kExtend); // end-marker
	dbgexpect (C.LastOut == C.Expected);
	fs->Length += C.Length();
}


//////////////////////////////////////////////////// DECOMP //////////////////////////////////////////////////////////////
u8* Copy_(u8* Addr, FastBuff& fb, int Offset, int Length);

u8* DeOffset_(u8* Addr, FastBuff& fb, u32 Value) {
	u32 Info	= (Value << 8) | *Addr++;
	int Length	= (Info >> 12) + 2;
	int Offset	= Info & 4095;
	u8  Next	= *Addr;
	while ( (Next&0xF0) == 0x10 ) { // offset extend.  //update
		Offset = (Offset << 4) | (Next & 0x0F);
		Next = *++Addr;
	}
	
	return Copy_(Addr, fb, Offset, Length); 
}


u8* DeEscape_(u8* Addr, FastBuff& fb, int Dist) {
	auto OldWrite = fb.Write;
	fb.Write = ++Dist + OldWrite;

	DReq(fb.Write <= fb.WriteEnd,		"Chunk output too large",0);
	memcpy(OldWrite, Addr, Dist);
	return Addr + Dist;
}


u8* DeBig_(u8* Addr, FastBuff& fb, u32 Code, u8* End) {
	u32 Value = 0;			// 0x80 x 1, Length x 3, Offset x 4 
	while ((Code&0xF0) == kExtend and Addr < End) {
		Value = (Value << 4) | (Code & 15);
		Code = *Addr++;
	}
	
	if (Code >= 0x80)
		return DeOffset_(Addr, fb, (Value << 7) | (Code &~ 0x80));
	return DeEscape_(Addr, fb, (Value << 4) | Code);
}

u8* Copy_(u8* Addr, FastBuff& fb, int Offset, int Length) {
	u8* Write	= fb.Write;
	u8* Src		= Write - Offset;
	fb.Write	= Write + Length;
	DExpect(Src >= fb.WriteStart and fb.Write <= fb.WriteEnd,	"Offset too far/too much data");
	u8* SrcEnd = Src+Length;
	auto W8 = (int64*)Write;  auto S8 = (int64*)Src; 
	*W8++ = *S8++; *W8++ = *S8++;
	if (SrcEnd <= Write) {
		if (Length <= 16)
			return Addr;
		memcpy(W8, S8, Length-16);
	} else {
		while (Src < SrcEnd) *Write++ = *Src++;	// RLE
	}
	return Addr;
}

void BackFlush_ (FastString* fs, int CurrLength) {
	if (fs->File) {
		memmove(fs->ResultPtr, fs->ResultPtr+fs->Length, CurrLength);
		fs->Length = CurrLength;
		JB_FS_Flush(fs);
	}
	fs->Length += CurrLength;
}
  
extern "C" int JB_Str_DecompressChunk (FastString* fs,  JB_String* self,  int TotalLength) {
	FastBuff& fb = FB;
	require (arr_reserve(fb, self, TotalLength, fs));
	u8* Addr = fb.Read; u8* AddrEnd = fb.ReadEnd;

	while (Addr < AddrEnd) {
		u8 Code = *Addr++;
		if (Code >= 0x80)
			Addr = DeOffset_(Addr, fb, Code &~ 0x80);
		  else if (Code <= 0x0f)
			Addr = DeEscape_(Addr, fb, Code);
		  else if (Code > kExtend)		//UPDATE
			Addr = DeBig_(Addr, fb, Code, AddrEnd);
		  else
			break; // finished!
	}
	require (Addr != ErrP);
	DReq(Addr == AddrEnd,						"Chunk read overflow",		0);
	DReq(fb.Expected == fb.Length(),			"Chunk write-length error",	0);
	BackFlush_(fs, fb.Expected);
	return fb.Expected; 
}


/* 

  Length	Values					Meaning
	1		00-0F					Escape
	1		10-1F					bigoff/minidict (can't minidict these after an offset)
	1		20-6F					MiniDict			
	1		70-7f					Extend
	2		80-FF, 00-FF (10-1F)	Offset
	
// new
  Length	Values					Meaning
	1		00-0F					Escape
	1		10-1F					Extend
	2		20-EF, 00-FF (F0-FF)	Offset
	1		F0-FF, 00-FF			bigoff

	12x chunk-size for compress, 1MB-->12MB
	2x  chunk-size for decomp,   1MB-->2MB
*/
