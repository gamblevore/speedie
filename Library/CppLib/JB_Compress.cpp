
#include "JB_Compress.h"
#include "divsufsort.h" // Runs 5x (!!) faster than a plain quicksort or even my spdsort
// * i should also add a "next item differs at" thing to the suffixes...
// * and maybe a "strength" that allows further checking of suffixes?


#define kExtend 0x70

struct CompState : FastBuff {
	int					LastOut;
	int					B;
	int					StatsDetector;
	int					BitCount;
	uint64_t			BitBuff;
	int*				Suffixes;
	int*				SortPositionAtByte;	
	

	uint32_t ReadUInt() {
		auto C = (uint32_t*)Read;
		auto R = *C++;
		Read = (u8*)C;
		return R;
	}
	
	void WriteUint(uint32_t X) {
		auto C = Write;
		*((int*)C) = X;
		Write = C + 4;
	}
	
	inline void PutBits (int n, uint64_t x) {
		StatsDetector += n;
		n += BitCount;
		auto B = BitBuff | (x<<(64-n));
		if (n >= 32) {
			BitCount = n - 32;
			BitBuff = B << 32;
			WriteUint(B>>32);
		} else {
			BitBuff = B;
			BitCount = n;
		}
	}

	inline uint GetBits (uint n) {
		if (n) {
			int C = BitCount;
			uint64_t B = BitBuff;
			if (C < n) {
				auto R = ((uint64_t)ReadUInt())<<(32-C);
				B |= R;
				C += 32;
			}

			int X = (int)(B>>(64-n));
			BitBuff  = B<<n;
			BitCount = C-n;
			return X;
		}
		return 0;
	}
	
	inline int ZeroBits() {
		int C = BitCount;
		uint64_t B = BitBuff;
		if (C < 32) {
			auto R = ((uint64_t)ReadUInt())<<(32-C);
			B |= R;
			C += 32;
			BitBuff = B;
		}
		int Zeros = __builtin_clzll(B);
		
		BitBuff  = B<<Zeros;
		BitCount = C-Zeros;
		return Zeros;
	}

	inline int GetOffset() {
		uint Z = ZeroBits();
		uint Bits = (Z << 2) + 4;
		uint b = 0b00010001000100010001000100010001;
		Z = ((1<<Bits)-1) & b;
		uint F = GetBits(Bits);
		return F + Z;
	}
	
	inline void PutOffset (uint X) {
		uint b = 0b00010001000100010001000100010000;
		for (int i = 5; i < 32; i+=4) {
			uint mask = (1<<i)-1; // could opt this to start at the correct bit-range... using log2
			if (X > (b&mask)) continue;
			PutBits(i>>2,   1);
			PutBits(i-1, X-(mask>>4));
			return;
		}
		__builtin_trap(); // aaaa?????
	}

	inline int GetLength() {
// Lengths:	 1=(1),  3=(2-3),  5=(4-7),  7=(8-15),  9=(16-31),  11=(32-63)
		uint Z = ZeroBits();
		uint F = GetBits(Z);
		return F + (1<<Z) + 1;
	}

	inline void PutLength (uint X) {
		if (X <= 1)
			return PutBits(1,  1);
			
		uint L = JB_Int_Log2(X>>1);
		PutBits(L+1,  1);
		X -= 1<<L;
		PutBits(L, X-(1<<L));
	}

	
	bool TestOneCost (u8* Find,  u8* E,  int G,  MatchFound& Best, int Esc) {
		int N		= Suffixes[G];
		u8* Text	= E - N;
		N			= (Text < Find) ? (int)(E-Find) : 2; // we just want to know if any good ones remain.
		int i		= 0;
		for (; i < N; i++)
			if (Find[i] != Text[i]) break;
		
		if (i < 2)
			return false; // only gonna get worse. Better checking will make this faster.
		int Back	= (int)(Find - Text);
		if (Back <= 0)
			return true;
		
		int FixCost		= (Esc!=0) + 1 - i;
		int VaryCost	= (i > 9) + (Back >= 4096) + (Back >= 64_K);
		int Cost = FixCost + VaryCost;
		int BestCost = Best.Cost();
		if (Cost < BestCost) {
			Best = {Back, i, FixCost, VaryCost};
			return true; // continue
		}
		if (Cost == BestCost or Best.Length <= i)
			return true; // continue
		return false; // stop
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
			if (L >= B    and TestOneCost(SelfTest, E, L--, Best, Esc)==false)
				L = -1;
			if (H <= Last and TestOneCost(SelfTest, E, H++, Best, Esc)==false)
				H = Last+1;
		}
		return Best;
	}
	
	u8* Detect () {
		int n		= Expected;
		int* SP		= SortPositionAtByte;
		int* R0		= Suffixes;
		divsufsort(Read, R0, n);
		for_(n)	{				// code is simple, but concept is confusing.
			SP[R0[i]] = i;
			R0[i] = n - R0[i];
		}
		return n + Read;
	}
	

//////////////////////////////////////////////// COMPRESSION //////////////////////////////////////////////////////
	int AllocWrite (int Length, int MaxBits) {
		int Over = Length >> MaxBits;
		if (Over) {
			// 0 = 0bytes,  1-15 = 1byte,  16-255 = 2bytes
			int Loop = (JB_Int_Log2(Over) &~ 0x3) + 4;
			while (Loop > 0) {
				Loop -= 4;
				*Write++ = ((Over >> Loop)&15) | kExtend;
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
		(CopyBytes(B, Write, N));
		Write+=N;
	}

	void WriteOffset (int Offset, int Length) {
		dbgexpect(Length >= 0 and Offset >= 1);
	}
};



static CompState	sigh;
static FastBuff		FB;
static CompState& alloc_compress(JB_String* self, FastString* fs) {
	CompState& C		= sigh;

	int Total			= self->Length;
	int CB				= max(ChunkLen_(Total), 12);
	int ChunkLength		= 1<<CB;

	C.Write = JB_FS_NeedSpare(fs, ChunkLength+1024);
	C.WriteStart = C.Write;
	C.WriteEnd = C.Write + ChunkLength;
//	C.WriteByte(CB-12);

	if (CB > C.B) {
		C.B = CB;
		C.Suffixes				= (int*)JB_realloc(C.Suffixes,	2*ChunkLength*sizeof(int)+16);
		C.SortPositionAtByte	= (int*)JB_realloc(C.SortPositionAtByte,	ChunkLength*sizeof(int));
	}

	C.Expected			= Total;
	C.LastOut			= 0;
	C.Read				= JB_Str_Address(self);
	
	return C;
}


extern "C" void JB_Str_CompressChunk (FastString* fs, JB_String* self) {
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
	dbgexpect (C.LastOut == C.Expected);
	fs->Length += C.Length();
}


//////////////////////////////////////////////////// DECOMP //////////////////////////////////////////////////////////////

u8* DeOffset_(u8* Addr, FastBuff& fb, u32 Length) {
	int Offset = 0;
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

  
extern "C" int JB_Str_DecompressChunk (FastString* fs,  JB_String* self,  int Expected) {
	FastBuff& fb = FB;
	require (arr_reserve(fb, self, Expected, fs));
	u8* Addr = fb.Read; u8* AddrEnd = fb.ReadEnd;

	while (Addr < AddrEnd) {
		u8 Code = *Addr++;
		Addr = DeOffset_(Addr, fb, Code &~ 0x80);
	}
	
	require (Addr != ErrP);
	DReq(Addr == AddrEnd,						"Chunk read overflow",		0);
	DReq(fb.Expected == fb.Length(),			"Chunk write-length error",	0);
	fs->Length += fb.Expected;
	return fb.Expected;
}


extern "C" void JB_App__ClearCaches(int which) {
	if (sigh.B) {
		sigh.B = 0;
		JB_unalloc((void**)&sigh.Suffixes);
		JB_unalloc((void**)&sigh.SortPositionAtByte);
	}
}

// was 295 lines.

