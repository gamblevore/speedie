
#include "JB_Compress.h"
#include "divsufsort.h" // Runs 5x (!!) faster than even my spdsort
// * I should also add a "next item differs at" thing to the suffixes...
// * and maybe a "strength" that allows further checking of suffixes?

#define UnitSize	8
#define mUnitSize	(UnitSize-1)
#define MZ_PRINT 1
int CountPrint = 0;

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
	
	inline int HeaderBits() {
		int C = BitCount;
		uint64_t B = BitBuff;
		if (C < 32) { // might read non-existant bits... needs to be fixed.
			auto R = ((uint64_t)ReadUInt())<<(32-C);
			B |= R;
			C += 32;
//			BitBuff = B;
		}
		int Zeros = __builtin_clzll(B)+1;
		
		BitBuff  = B<<Zeros;
		BitCount = C-Zeros;
		return Zeros;
	}
	
	inline uint GetBits (uint n) {
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
	
	inline uint GetOffset() {
		uint Z = HeaderBits();
		uint Bits = Z << 2;
		uint b = 0b00010001000100010001000100010000;
		Z = ((1<<Bits)-1) & b;
		uint F = GetBits(Bits);
		int Rz = F + Z;
		#if DEBUG
		if (Rz < 0)
			debugger;
		#endif
		return Rz;
	}

	void WriteUint(uint32_t X) {
		auto C = Write;
		*((int*)C) = X;
		Write = C + 4;
	}
	
	inline void PutBits (int n, uint64_t x) {
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

	inline void PutOffset (uint X, int Size=4) {
		///  Size=4:  16-16,  256-272,  4096-4368,  65536-69904  ///
		uint b = 0;
		uint header = 0;
		// the fastest way to do this is with explicit if-chains... avoid all the calculation
		// just use the hard-coded values. this will do for now :)
		// I could make it generate a C++ array of values?
		for (int i = Size; i < 32; i+= Size) {
			header++;
			int ii = 1<<i;
			if (X < ii) {
				PutBits(header, 1);
				PutBits(i, X);
				return;
			}
			X -= ii;
		}
		__builtin_trap(); // aaaa?????
	}

	inline uint GetLength() {		// Lengths:	 1=(1),  3=(2-3),  5=(4-7),  7=(8-15),  9=(16-31),  11=(32-63)
		uint Z = HeaderBits();
		if (Z <= 1)
			return 1;
		uint F = GetBits(--Z);
		uint Rz = F + (1<<Z);
		#if DEBUG
		if (Rz < 1)
			debugger;
		#endif
		return Rz;
	}
	
	inline void PutLength (uint X) {
		if (X <= 1)
			return PutBits(1,  1);
			
		uint L = JB_Int_Log2(X);
		uint X2 = X&((1<<L)-1);
		PutBits(L+1,  1);
		PutBits(L,   X2);
	}
};



int ChunkLen_(int x) {
	int y	= JB_Int_Log2(x);
	int x2	= 1<<y;
	return y + (x2 < x);
}


#define DReq(a,b,c)  if (DErr(a,b)) return c;
bool DErr(bool Cond, const char* Err) {
	if (Cond) return false;
	puts(Err); debugger;
	JB_ErrorHandleC(Err, 0, false);
	return true;
}


static bool arr_reserve(FastBuff& B,  JB_String* self,  int Expected,  FastString* fs) {
	auto Length = self->Length;
	DReq (!(Length&3), "Compressed Length Invalid", 0);
	B.Read = self->Addr;
	B.ReadEnd = B.Read + Length;
	B.Expected = Expected;
	B.WriteStart = B.Write = JB_FS_NeedSpare(fs, Expected+15);
	DReq (B.Write, "Out of memory", 0);
	B.WriteEnd = B.Write + Expected+15;
	B.BitCount = 0;
	B.BitBuff = 0;
	return true;
}


struct CompState : FastBuff {
	int					B;
	int					SearchStrength;
	uint*				Suffixes;
	uint*				SortPositionAtByte;	
	
	int GetDiff (u8* E, int G) {
		uint SG = Suffixes[G];
		if (SG&255)
			return SG&255;
		u8* A = E - (SG>>8);
		u8* B = E - (Suffixes[G+1]>>8);
		
		int N = std::min((int)std::min(E-A, E-B),255);
		int Dist = 0;
		for ( ; Dist < N; Dist++)
			if (A[Dist] != B[Dist]) break;
		Dist++;
		if (Dist > 255) debugger; // what?
		Suffixes[G] = SG | std::min(Dist, 255);
		return Dist;
	}
	
	int TestOneCost (u8* Find,  u8* E,  int G,  int Prev,  int PrevLength,  MatchFound& Best) {
		if ((uint)G >= Expected) return 0;
		u8* Text = E - (Suffixes[G]>>8);
		int Length = GetDiff(E, G-Prev) - 1;
		Length = std::min(Length, PrevLength);

		if (Length <= 0 or Length < Best.Length)
			return 0;
		if (Text < Find) {
			int Back = (int)(Find - Text);
			int Score = (Length<<6)-JB_Int_Log2(Back);
			if (Score > Best.Score)
				Best = {Back, Length, Score};
		}
		return Length;
	}
	
	int CompressOne (int R, u8* E) {
		int Best = SortPositionAtByte[R];		// pos of OUR value.
		
		u8* SelfTest = Read + R;
		int FWD = INT_MAX; int BAK = INT_MAX;
		int Count = 1;
		MatchFound Match = {R + 1 + *SelfTest, 1, INT_MIN};
		
		for ( /*;;__;;*/ ; FWD or BAK; Count++) {
			if (FWD)
				FWD = TestOneCost(SelfTest, E, Best+Count, 1, FWD, Match);
			if (BAK)
				BAK = TestOneCost(SelfTest, E, Best-Count, 0, BAK, Match);
		}

#if	MZ_PRINT
		printf("%i** -%i +%i:  <%.*s>\n", ++CountPrint, Match.Back, Match.Length, Match.Length, SelfTest);
#endif
		PutOffset(Match.Back-1);
		PutLength(Match.Length);

		return R + Match.Length;
	}
	
	u8* Detect () {
		int n = Expected;
		uint* SP = SortPositionAtByte;
		uint* R0 = Suffixes;
		divsufsort(Read, (int*)R0, n);
		for_(n)	{				// code is simple, but concept is confusing.
			SP[R0[i]] = i;
			R0[i] = (n - R0[i]) << 8;
		}
		return n + Read;
	}
};



//////////////////////////////////////////////// DECOMP ////////////////////////////////////////////////

static u8* DecompOneMz(FastBuff& fb, u8* Write, u8* WriteEnd) {
	uint Offset = fb.GetOffset()+1;
	int Length = fb.GetLength();
#if	MZ_PRINT
	printf("%i// -%i +%i\n", ++CountPrint, Offset, Length);
#endif	
//	require (Read < fb.ReadEnd); // read protect have to be handled in getbits
	u8* Src	= Write - Offset;
	u8* Start = fb.WriteStart;
	if (Src >= Start) {
		DReq (Write+Length <= WriteEnd, "oversized decomp", (u8*)(-1ll))
//		auto W8 = (int64*)Write;  
//		Write += Length;
		u8* SrcEnd = Src+Length;
//		auto S8 = (int64*)Src; 
//		*W8++ = *S8++; *W8++ = *S8++; // we can't just blindly do this anymore.
									  // need to check its in range.
//		if (SrcEnd <= Write) {
//			if (Length <= 16)
//				return Write;
//			memcpy(W8, S8, Length-16);
//		} else {
			while (Src < SrcEnd) *Write++ = *Src++;	// RLE
//		}
		return Write;
	}
	*Write++ = (Start - Src)-1;
	return Write;
}


extern "C" int JB_Str_DecompressChunk (FastString* fs,  JB_String* self,  int Expected) {
	FastBuff C = {};
	require (arr_reserve(C, self, Expected, fs));

	CountPrint = 0;
	u8* Curr = C.Write;
	u8* After = Curr + Expected;
	while (Curr < After)
		Curr = DecompOneMz(C, Curr, After);
	//	DReq(Addr == AddrEnd,						"Chunk read overflow",		0);
	if (Curr == (u8*)(-1ll))
		return 0;
	DReq(Curr >= After,			"Chunk missing data",	0);
	
	fs->Length += C.Expected;
	return C.Expected;
}


//////////////////////////////////////////////// COMPRESS ////////////////////////////////////////////////

static CompState	Reuseable;
static bool alloc_compress(FastString* fs, JB_String* self, int Strength) {
	int Total = JB_Str_Length(self);
	require (fs and Total and Total < 16_M)
	
	CompState& C		= Reuseable;
	C.SearchStrength	= min(max(Strength,50), 10000);
	int CB				= max(ChunkLen_(Total), 24);
	int ChunkLength		= 1<<CB;
	int RealMin			= (Total * 9 + 32)/8;

	C.Write = JB_FS_NeedSpare(fs, max(ChunkLength,RealMin));
	C.WriteStart = C.Write;
	C.WriteEnd = C.Write + ChunkLength;
	C.BitBuff = 0;
	C.BitCount = 0;

	if (CB > C.B) {
		C.B = CB;
		C.Suffixes = (uint*)JB_realloc(C.Suffixes,	2*ChunkLength*sizeof(int));
		C.SortPositionAtByte = C.Suffixes + ChunkLength;
	}

	C.Expected			= Total;
	C.Read				= JB_Str_Address(self);
	
	return true;
}


extern "C" void JB_Str_CompressChunk (FastString* fs, JB_String* self, int Strength) {
	require0(alloc_compress(fs, self, Strength));
	auto & C = Reuseable;
	CountPrint = 0;
	auto TextAfter = C.Detect();
	int i = 0;
	while (i < C.Expected)
		i = C.CompressOne(i, TextAfter);

	C.PutBits(31, 0);
	dbgexpect (i == C.Expected);
	fs->Length += C.Length();
}


extern "C" void JB_App__ClearCaches(int which) {
	if (Reuseable.B) {
		Reuseable.B = 0;
		JB_unalloc((void**)&Reuseable.Suffixes);
	}
}

