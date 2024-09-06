
#include "JB_Compress.h"
#include "divsufsort.h" // Runs 5x (!!) faster than even my spdsort
// * I should also add a "next item differs at" thing to the suffixes...
// * and maybe a "strength" that allows further checking of suffixes?

#include <string>
#include <iostream>
#define ErrP ((u8*)(-1))
#define UnitSize 8
#define mUnitSize (UnitSize-1)

using namespace std;  using std::min;  using std::max;

struct MatchFound {
	int Back;
	int Length;
	int Score;
    operator bool() { return Length; }
};


struct FastBuff {
	u8*					Write;
	u8*					WriteStart;
	u8*					WriteEnd;
	u8*					Read;
	u8*					ReadEnd;
	int					Expected;
	int					BitCount;
	uint64_t			BitBuff;
	
	inline int Length() {
		return (int)(Write - WriteStart);
	}
	
	uint32_t ReadUInt() {
		auto C = (uint32_t*)Read;
		auto R = *C++;
		Read = (u8*)C;
		return R;
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
	
	inline int GetOffset() {
		uint Z = ZeroBits();
		uint Bits = (Z << 2) + 4;
		uint b = 0b00010001000100010001000100010001;
		Z = ((1<<Bits)-1) & b;
		uint F = GetBits(Bits);
		return F + Z;
	}

	inline int GetLength() {		// Lengths:	 1=(1),  3=(2-3),  5=(4-7),  7=(8-15),  9=(16-31),  11=(32-63)
		uint Z = ZeroBits();
		uint F = GetBits(Z);
		return F + (1<<Z) + 1;
	}
};


int ChunkLen_(int x) { 	// ((Total*9)/8)+12;
	int y	= JB_Int_Log2(x);
	int x2	= 1<<y;
	return y + (x2 < x);
}


#define DExpect(a,b) if (DErr(a,b)) return ErrP;
#define DReq(a,b,c) if (DErr(a,b)) return c;
bool DErr(bool Cond, const char* Err) {
	if (Cond) return false;
	puts(Err); debugger;
	JB_ErrorHandleC(Err, 0, false);
	return true;
}


static bool arr_reserve(FastBuff& B,  JB_String* self,  int Expected,  FastString* fs) {
	auto Addr	= self->Addr;
	auto End	= Addr + self->Length;

	B.Read		= Addr;
	B.ReadEnd	= End;

	B.Expected = Expected;
	B.Write = JB_FS_NeedSpare(fs, B.Expected);
	DReq (B.Write, "Out of memory", 0);
	B.WriteStart = fs->ResultPtr + fs->Length; // always the same as B.Write? 
	B.WriteEnd = B.Write + B.Expected;
	return true;
}


struct CompState : FastBuff {
	int					LastOut;
	int					B;
	int					StatsDetector;
	int					SearchStrength;
	int*				Suffixes;
	int*				SortPositionAtByte;	

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

	inline void PutLength (uint X) {
		if (X <= 1)
			return PutBits(1,  1);
			
		uint L = JB_Int_Log2(X>>1);
		PutBits(L+1,  1);
		X -= 1<<L;
		PutBits(L, X-(1<<L));
	}

	inline void PutOffset (uint X) {
		uint b = 0b00010001000100010001000100010000;
		for (int i = 5; i < 32; i+=4) {
			uint mask = (1<<i)-1;	// could opt this to start at the correct bit-range... using log2
			if (X > (b&mask)) continue;
			PutBits(i>>2,   1);
			PutBits(i-1, X-(mask>>4));
			return;
		}
		__builtin_trap(); // aaaa?????
	}
	
	bool TestOneCost (u8* Find,  u8* E,  int G,  MatchFound& Best) {
		int N = Suffixes[G];
		u8* Text = E - N;
		N = (Text < Find) ? (int)(E-Find) : 1; // we just want to know if any good ones remain.
											   // fix this?
		int i = 0;
		for (; i < N; i++)
			if (Find[i] != Text[i]) break;
		
		int Back = (int)(Find - Text);
		if (Back <= 0)
			return true;
		
		int Score = i; // for now
		if (Score > Best.Score) {
			Best = {Back, i, Score};
			return true; // continue
		}
		return (Score == Best.Score or Best.Length <= i);
	}


	int CompressOne (int R, u8* E) {
		int Self	= SortPositionAtByte[R];		// pos of OUR value.
		int Last	= Expected - mUnitSize;
		int L		= Self - 1;
		int H		= Self + 1;
		int B		= 0;
		B			= max(0, L-SearchStrength);
		Last		= min(Last, H+SearchStrength);	// the "next/prev endgaps.changesat[i]" opt would help!
		u8* SelfTest= Read + R;
		
		MatchFound Best = {R+1+E[R], 1, 0};
		while (L >= B or H <= Last) {
			if (L >= B    and !TestOneCost(SelfTest, E, L--, Best))
				L = -1;
			if (H <= Last and !TestOneCost(SelfTest, E, H++, Best))
				H = Last+1;
		}
		
		PutOffset(Best.Back);
		PutLength(Best.Length);
		return R + Best.Length;
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
};



static CompState	sigh;
static CompState& alloc_compress(JB_String* self, FastString* fs) {
	CompState& C		= sigh;
	C.SearchStrength	= 250; // can increase/decrease

	int Total			= self->Length;
	int CB				= max(ChunkLen_(Total), 12);
	int ChunkLength		= 1<<CB;

	C.Write = JB_FS_NeedSpare(fs, ChunkLength+1024);
	C.WriteStart = C.Write;
	C.WriteEnd = C.Write + ChunkLength;

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
	int Total = JB_Str_Length(self);
	if (!fs or !Total)
		return;
	
	DReq(Total <= 16_M, "Chunk size too large",);
	auto& C		= alloc_compress(self, fs);
	auto TextAfter = C.Detect();
	for (int i = 0;  i < Total; ) {
		i = C.CompressOne(i, TextAfter);
		dbgexpect (C.LastOut <= C.Expected);
	}

	dbgexpect (C.LastOut == C.Expected);
	fs->Length += C.Length();
}


//////////////////////////////////////////////// DECOMP ////////////////////////////////////////////////

static u8* DecompOneMz(u8* Addr, FastBuff& fb) {
	int Offset = fb.GetOffset();
	int Length = fb.GetLength();
	u8* Write	= fb.Write;
	u8* Src		= Write - Offset;
	fb.Write	= Write + Length;
	DExpect(Src >= fb.WriteStart and fb.Write <= fb.WriteEnd,	"Offset too far/too much data");
	u8* SrcEnd = Src+Length;
	auto W8 = (int64*)Write;  auto S8 = (int64*)Src; 
	*W8++ = *S8++; *W8++ = *S8++; // we can't just blindly do this anymore.
								  // need to check its in range.
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
	FastBuff fb = {};
	require (arr_reserve(fb, self, Expected, fs));
	u8* Addr = fb.Read; u8* AddrEnd = fb.ReadEnd;

	while (Addr < AddrEnd)
		Addr = DecompOneMz(Addr, fb);
	
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

