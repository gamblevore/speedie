
#include "JB_Compress.h"
// #include "divsufsort.h"
// this still seems a lot SLOWER than the original! Despite all my opts!
// could it be because the original perhaps used... registers? and mine isn't?
// sigh. That will suck, to change.
// it could be the myscore operation, though.
// either way, this could get a lot faster.
// if it gets faster without registers, then so will my original mz too.


struct DateLocker {
	atomic_int64_t	Value;
	bool			NoLongerNeeded;
	DateLocker  () {Value = 0; NoLongerNeeded=false;}
	void unlock () {
		Value &= ~1;
	}
	void lock () {
		Date Now = JB_Date__Now()|1;
		Date Expected;
		do {
			Expected = Value &~ 1;
		} while (!Value.compare_exchange_weak(Expected, Now));
	}
	bool start_clear (int Duration) {
		auto D = (Date)Value;
		require(D and !(D&1));										// its been used but not in-use
		require(NoLongerNeeded or JB_Date__Now() > D + Duration);	// enough time passed
		return Value.compare_exchange_weak(D, -1);
	}
	void cleared () {
		NoLongerNeeded = false;
		Value = 0;
	}
};


static DateLocker		Allocator;
static u8*				Space;

extern "C" int CompressionFree(int X) {
	if (Allocator.start_clear(X)) {
		JB_Free(Space);
		Space = 0;
		Allocator.cleared();
	}
	return 0;
}

extern "C" void JB_CompFreeNow() {
	Allocator.NoLongerNeeded = true;
}

extern "C" int JB_CompFreer() {
	return CompressionFree(10*64*1024);	// 10s ago!
}



#if 0

#define kExtend 0x70
// not sure if I should keep both? i should use one match-finder, not both.
struct CompState : FastBuff {
	int                                     LastOut;
	int*                            		Suffixes;
	int*                            		SortPositionAtByte;     
	int                                     B;
	
	
	bool TestOneCost (u8* Find,  u8* E,  int G,  MatchFound& Best, int Esc) {
		int N           = Suffixes[G];
		u8* Text        = E - N;
		N               = (Text < Find) ? (int)(E-Find) : 2; // we just want to know if any good ones remain.
		int i           = 0;
		for (; i < N; i++)
			if (Find[i] != Text[i]) break;
		
		if (i < 2)
			return STOP; // only gonna get worse. Better checking will make this faster.
		int Back        = (int)(Find - Text);
		if (Back <= 0)
			return CONT;
		
		int FixCost             = (Esc!=0) + 1 - i;
		int VaryCost    = (i > 9) + (Back >= 4096) + (Back >= 64_K);
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
		int Self        = SortPositionAtByte[R];                // pos of OUR value.
		int Last        = Expected - mUnitSize;
		int L           = Self - 1;
		int H           = Self + 1;
		int B           = 0;
		B                       = max(0, L-250);        // Actually lowers compresion! seem like we are reading A LOT.
		Last            = min(Last, H+250);             // the "next/prev endgaps.changesat[i]" opt would help!
		int Esc         = (R != LastOut)*0x20;
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
		int n           = Expected;
		int* SP         = SortPositionAtByte;
		int* R0         = Suffixes;
		divsufsort(Read, R0, n);
		for_(n) {                               // code is simple, but concept is confusing.
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
		(CopyBytes(B, Write, N));
		Write+=N;
	}
	
	inline void WriteByte (u8 B) {
		*Write++ = B;
	}
	
	void EscapeOld (int NeedUpTo) {
		int L           = LastOut;
		int Length      = NeedUpTo - L;
		require0 (Length > 0);
		LastOut         = NeedUpTo;
		int ToWrite = AllocWrite(Length - 1, 4);
		WriteByte(ToWrite);
		WriteStr(Read+L, Length);
	}
	
	
	void WriteOffset (int Offset, int Length) {
		dbgexpect(Length >= 0 and Offset >= 1);
		LastOut            += Length;
		Length                  = AllocWrite(Length - 2, 3);                         // 0x80 x 1, Length x 3, Offset x 4
		
		int Orig                = Offset;
		int ShiftCount  = 0;
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



static CompState        sigh;
static FastBuff         FB;
static CompState& alloc_compress(JB_String* self, FastString* fs) {
	CompState& C            = sigh;
	
	int Total                       = self->Length;
	int CB                          = max(ChunkLen_(Total+1024),12);
	int ChunkLength         = 1<<CB;
	
	C.Write = JB_FS_NeedSpare(fs, ChunkLength+1024*16);
	C.WriteStart = C.Write;
	C.WriteEnd = C.Write + ChunkLength;
	C.WriteByte(CB-12);
	
	if (CB > C.B) {
		C.B = CB;
		C.Suffixes              	= (int*)JB_Realloc(C.Suffixes,       2*ChunkLength*sizeof(int)+16);
		C.SortPositionAtByte		= (int*)JB_Realloc(C.SortPositionAtByte,             ChunkLength*sizeof(int));
	}
	
	C.Expected                      = Total;
	C.LastOut                       = 0;
	C.Read                          = JB_Str_Address(self);
	
	return C;
}

inline void JB_unalloc(void** Arr) {
	if (*Arr) {
		JB_Free(*Arr);
		*Arr = 0;
	}
}

static void ClearCaches() {
	if (sigh.B) {
		sigh.B = 0;
		JB_unalloc((void**)&sigh.Suffixes);
		JB_unalloc((void**)&sigh.SortPositionAtByte);
	}
}



extern "C" void JB_Str_CompressChunk (FastString* fs, JB_String* self, int Ignore) {
	if (!fs or !self)
		return ClearCaches();
	
	int Total       = JB_Str_Length(self);
	require0 (Total);
	DReq(Total <= 2_M, "Chunk size too large",);
	auto& C         = alloc_compress(self, fs);
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
u8* Copy_(u8* Addr, FastBuff& fb, int Offset, int Length) {
	u8* Write       = fb.Write;
	u8* Src         = Write - Offset;
	fb.Write        = Write + Length;
	DExpect(Src >= fb.WriteStart and fb.Write <= fb.WriteEnd,       "Offset too far/too much data");
	u8* SrcEnd = Src+Length;
	auto W8 = (int64*)Write;  auto S8 = (int64*)Src; 
	*W8++ = *S8++; *W8++ = *S8++;
	if (SrcEnd <= Write) {
		if (Length <= 16)
			return Addr;
		memcpy(W8, S8, Length-16);
	} else {
		while (Src < SrcEnd) *Write++ = *Src++; // RLE
	}
	return Addr;
}

u8* DeOffset_(u8* Addr, FastBuff& fb, u32 Value) {
	u32 Info        = (Value << 8) | *Addr++;
	int Length      = (Info >> 12) + 2;
	int Offset      = Info & 4095;
	u8  Next        = *Addr;
	while ( (Next&0xF0) == 0x10 ) { // offset extend.  //update
		Offset = (Offset << 4) | (Next & 0x0F);
		Next = *++Addr;
	}
	
	return Copy_(Addr, fb, Offset, Length); 
}


u8* DeEscape_(u8* Addr, FastBuff& fb, int Dist) {
	auto OldWrite = fb.Write;
	fb.Write = ++Dist + OldWrite;
	
	DReq(fb.Write <= fb.WriteEnd,           "Chunk output too large",0);
	memcpy(OldWrite, Addr, Dist);
	return Addr + Dist;
}


u8* DeBig_(u8* Addr, FastBuff& fb, u32 Code, u8* End) {
	u32 Value = 0;                  // 0x80 x 1, Length x 3, Offset x 4 
	while ((Code&0xF0) == kExtend and Addr < End) {
		Value = (Value << 4) | (Code & 15);
		Code = *Addr++;
	}
	
	if (Code >= 0x80)
		return DeOffset_(Addr, fb, (Value << 7) | (Code &~ 0x80));
	return DeEscape_(Addr, fb, (Value << 4) | Code);
}


extern "C" int JB_Str_DecompressChunk (FastString* fs,  JB_String* self,  int Expected) {
	FastBuff& fb = FB;
	require (arr_reserve(fb, self, Expected, fs));
	u8* Addr = fb.Read; u8* AddrEnd = fb.ReadEnd;
	
	while (Addr < AddrEnd) {
		u8 Code = *Addr++;
		if (Code >= 0x80)
			Addr = DeOffset_(Addr, fb, Code &~ 0x80);
		else if (Code <= 0x0f)
			Addr = DeEscape_(Addr, fb, Code);
		else if (Code > kExtend)              //UPDATE
			Addr = DeBig_(Addr, fb, Code, AddrEnd);
		else
			break; // finished!
	}
	
	require (Addr != ErrP);
	DReq(Addr == AddrEnd,									"Chunk read overflow",       0);
	DReq(fb.Expected == fb.Length(),						"Chunk write-length error",  0);
	fs->Length += fb.Expected;
	return fb.Expected;
}


/* 
 
 Length        Values                                  Meaning
 1               00-0F                                   Escape
 1               10-1F                                   bigoff/minidict (can't minidict these after an offset)
 1               20-6F                                   MiniDict                             
 1               70-7f                                   Extend
 2               80-FF, 00-FF (10-1F)    Offset
 
 // new
 Length        Values                                  Meaning
 1               00-0F                                   Escape
 1               10-1F                                   Extend
 2               20-EF, 00-FF (F0-FF)    Offset
 1               F0-FF, 00-FF                    bigoff
 
 12x chunk-size for compress, 1MB-->12MB
 2x  chunk-size for decomp,   1MB-->2MB
 */



#else







#define scint   static const int
scint W_BITS     = 21; // Window size (17..23)
scint HASH1_BITS = 21;
scint HASH2_BITS = 24;
scint W_SIZE     = 1<<W_BITS;
scint W_MASK     = W_SIZE-1;
scint SLOT_BITS  = 4;
scint NUM_SLOTS  = 1<<SLOT_BITS;
scint W_MINUS    = W_BITS-NUM_SLOTS;
scint MIN_MATCH  = 3;


// CONFIG
// these offsets could be configured per-file? It affects compression heavily.

scint A_BITS = 2;			// 1 xx		
scint B_BITS = 2;			// 01 xx		
scint C_BITS = 2;			// 001 xx	
scint D_BITS = 3;			// 0001 xxx	
scint E_BITS = 3;			// 00001 xxx
scint F_BITS = 5;			// 000001 xxxxx
scint G_BITS = 5;			// 0000001 xxxxx
scint H_BITS = 7;			// 00000001 xxxxxxx
scint I_BITS = 8;			// 000000001 xxxxxxxx
scint J_BITS = W_BITS;		// 0000000001 xxxxxxxxxxxxxxxxxxxxx // 31 bits!

scint A_ = (1<<A_BITS)+00;
scint B_ = (1<<B_BITS)+A_;
scint C_ = (1<<C_BITS)+B_;
scint D_ = (1<<D_BITS)+C_;
scint E_ = (1<<E_BITS)+D_;
scint F_ = (1<<F_BITS)+E_;
scint G_ = (1<<G_BITS)+F_;
scint H_ = (1<<H_BITS)+G_;
scint I_ = (1<<I_BITS)+H_;
scint J_ = (1<<J_BITS)+I_;

// STUFF
scint HASH1_LEN   = MIN_MATCH;
scint HASH2_LEN   = MIN_MATCH+1;
scint HASH1_SIZE  = 1<<HASH1_BITS;
scint HASH2_SIZE  = 1<<HASH2_BITS;
scint HASH1_MASK  = HASH1_SIZE-1;
scint HASH2_MASK  = HASH2_SIZE-1;
scint HASH1_SHIFT = (HASH1_BITS+(HASH1_LEN-1))/HASH1_LEN;
scint HASH2_SHIFT = (HASH2_BITS+(HASH2_LEN-1))/HASH2_LEN;

static inline int update_hash1 (int h, int c) {
	return ((h<<HASH1_SHIFT)+c)&HASH1_MASK;
}

static inline int update_hash2 (int h, int c) {
	return ((h<<HASH2_SHIFT)+c)&HASH2_MASK;
}


extern "C" inline int MyScore (uint len, uint offset) {
    uint offbits = std::max(SLOT_BITS+31-__builtin_clz(offset), W_MINUS+1+SLOT_BITS);
	// could simplify. longer lengths are always better?
    uint l = len - MIN_MATCH;
    uint ln = 0;
    if (l<A_) {
        ln = A_BITS+1;
    } else if (l<B_) {
        ln = B_BITS+2;
    } else if (l<C_) {
        ln = C_BITS+3;
    } else if (l<D_) {
        ln = D_BITS+4;
    } else if (l<E_) {
        ln = E_BITS+5;
    } else if (l<F_) {
        ln = F_BITS+6;
    } else if (l<G_) {
        ln = G_BITS+7;
    } else if (l < H_) {
        ln = H_BITS+8;
    } else if (l < I_) {
        ln = I_BITS+9;
    } else if (l < J_) {
        ln = J_BITS+10;
    }

//	return len*8 - (ln*1 + offbits*1);			// greedy matching isnt easy to get a good heuristic for
//	return len*8 - (ln*1 + offbits*3);			// exact-pair lengths might help but its not easy.
    return len*8 - (ln*4 + offbits*4);			// both seem to work on different kinds of files. I do not know...
}



struct Decomp {
	u32* Curr;
	u32* After;
	
	inline u32 Read4() {
		if (Curr < After)
			return *Curr++;
		return 0;
	}
};



struct Compression {
	int*			Head;
	int*			Prev;
//	int*			TwoByte;
	u8*				Read;
	uint*			CmpOut;
	uint*			CmpOutStart;
	uint			Size;
	uint			Level;
	uint			h1;
	uint			h2;
	uint64_t		BitBuff;
	int				BitCount;

	void Write4 (uint i) {
		*CmpOut++ = i;
	}
	
	bool StartCompress (FastString* fs, JB_String* In) {
		int N = (HASH1_SIZE + HASH2_SIZE + W_SIZE +256*256*0) * sizeof(int); //256*256 is for TwoByte
		if (!Space and !(Space = JB_Realloc(NULL, N)))
			return false;
		
		Size = JB_Str_Length(In);
		
		CmpOut = (uint*)JB_FS_WriteAlloc_(fs, (Size+20) + (Size>>6)); // might expand a little.
		if (!CmpOut)
			return false;
		CmpOutStart = CmpOut;

		Head = (int*)Space;
		Prev = Head + HASH1_SIZE + HASH2_SIZE;
//		TwoByte = Prev+W_SIZE;
		Read = JB_Str_Address(In);

		Write4(-1);
		Write4(Size);
		memset(Head, -1, N);
		for (int i = 0; i < HASH1_LEN; ++i)
			h1 = update_hash1(h1, Read[i]);
		for (int i = 0; i < HASH2_LEN; ++i)
			h2 = update_hash2(h2, Read[i]);
		return true;
	}

	inline void PutBits (int n, uint64_t x) {
		if (n >= 1) {
			auto B = (BitBuff<<n) | x;
			BitBuff = B;
			n += BitCount;
			if (n >= 32) {
				n -= 32;
				Write4((uint)(B>>n));
			}
			BitCount = n;
		}
	}


	inline uint GetBits (Decomp& BS, int n) {
		if (n) {
			int Missing = BitCount;
			auto B = BitBuff;
			if (Missing > 0) {
				auto In = (uint64_t)BS.Read4();
				B = (B << 32)|In;
				Missing -= 32;
				BitBuff = B;
			}
			BitCount = Missing+n;
			B <<= 32+Missing;
			B >>= 64-n;
			return (uint)B;
		}
		exit(-1);
		return 0;
	}
	
	inline int HeaderBits (Decomp& BS) {
		auto Missing = BitCount;
		auto B = BitBuff;
		if (Missing > 0) {
			auto In = (uint64_t)BS.Read4();
			B = (B << 32)|In;
			Missing -= 32;
			BitBuff = B;
		}
		B <<= 32+Missing;
		if (B) {
			int Zeros = __builtin_clzll(B);
			BitCount = Missing + (Zeros + 1);
			return Zeros;
		}
		return 0;			/// Ooof
	}

	inline int GetOffset (Decomp& In) {
		const int log = GetBits(In, SLOT_BITS) + W_MINUS;
		if (log > W_MINUS)
			return GetBits(In, log) + (1<<log);
		  else
			return GetBits(In, W_MINUS+1);
	}
	
	void EscapeSub (int LastOut, int p) {
		if (LastOut+1 == p) {
			int x = LastOut + 1 + Read[LastOut];
			if (x < W_SIZE)
				return PutOffset(x);
		}
		// I think the only way to improve this, is to do rolz.
		
		PutOffset(0);
		PutLength(p - LastOut);
		PutBits(1, 1); // aligner. Can be byte-aligned for speed. Optional.
		while (LastOut < p)
			PutBits(8, Read[LastOut++]);
	}

	inline void Escape (int LastOut, int p) {
		if (LastOut < p)
			EscapeSub(LastOut, p);
	}
	
	inline void PutOffset (uint offset) {
		int log = std::max(31-__builtin_clz(offset), W_MINUS);
		PutBits(SLOT_BITS, log-W_MINUS);
		if (log > W_MINUS)
			PutBits(log, offset-(1<<log));		// removes the highest bit only. Neatly stores the rest.
		  else
			PutBits(W_MINUS+1, offset);			// Requires 6 bits, and stores numbers 0 to 63
	}
	
	inline void PutLength (uint l) {
		int ll = 0;
		int n = 0;
		do {
			++n; if (l<A_) {
				ll = A_BITS; l -= 00; break;
			}
			++n; if (l<B_) {
				ll = B_BITS; l -= A_; break;
			}
			++n; if (l<C_) {
				ll = C_BITS; l -= B_; break;
			}
			++n; if (l<D_) {
				ll = D_BITS; l -= C_; break;
			}
			++n; if (l<E_) {
				ll = E_BITS; l -= D_; break;
			}
			++n; if (l<F_) {
				ll = F_BITS; l -= E_; break;
			}
			++n; if (l<G_) {
				ll = G_BITS; l -= F_; break;
			}
			++n; if (l<H_) {
				ll = H_BITS; l -= G_; break;
			}
			++n; if (l<I_) {
				ll = I_BITS; l -= H_; break;
			}
			++n; if (true) {
				(void)I_; // just for viewing
				ll = J_BITS; l -= I_; break;
			}
		} while (0);
		PutBits(n, 1);
		PutBits(ll, l);
	}
	
	inline int GetLength(Decomp& In) {
		int Z = HeaderBits(In);
		if (Z==0) return GetBits(In, A_BITS) + 00;
		if (Z==1) return GetBits(In, B_BITS) + A_;
		if (Z==2) return GetBits(In, C_BITS) + B_;
		if (Z==3) return GetBits(In, D_BITS) + C_;
		if (Z==4) return GetBits(In, E_BITS) + D_;
		if (Z==5) return GetBits(In, F_BITS) + E_;
		if (Z==6) return GetBits(In, G_BITS) + F_;
		if (Z==7) return GetBits(In, H_BITS) + G_;
		if (Z==8) return GetBits(In, I_BITS) + H_;
		if (true) return GetBits(In, J_BITS) + I_;
	}

	inline int InsertSubStrings (int p, int len) {
		while (len-- > 0) {
//			u16 SS = *((u16*)(Read+p));
//			TwoByte[SS] = p;
			Head[h1]=p;
			Prev[p&W_MASK]=Head[h2+HASH1_SIZE];
			Head[h2+HASH1_SIZE]=p++;
			h1 = update_hash1(h1, Read[p+(HASH1_LEN-1)]);
			h2 = update_hash2(h2, Read[p+HASH1_LEN]);
		}
		return p;
	}
	
	inline int NextScore (int p) {
		auto [A, B, C] = FindMatch(p, false);
		return std::max(C,0);
	}
	
	inline std::tuple<int, int, int> FindMatch (int p, bool CanNest=true) {
		int len = 1;
		int offset = W_SIZE;
		const int max_match = Size - p;
		const int limit = std::max(p - W_SIZE, 0);
		
//		auto SS = TwoByte[*((u16*)(Read+p))];
//		if (SS) {
//			offset = p - SS;
//			if (offset < W_SIZE)
//				len = 2;
//			  else
//				offset = W_SIZE;
//		}
		
		if (Head[h1] >= limit) {
			int s = Head[h1];
			if (Read[s]==Read[p]) {
				int l = 0;
				while (++l < max_match)
					if (Read[s+l] != Read[p+l])
						break;
				if (l > len) {
					len = l;
					offset = p-s;
				}
			}
		}

		// Attempt to find best PAIR seemed to make things worse? Not sure why.
		int chain_len = 16 << (4*Level);
		int s = Head[h2+HASH1_SIZE];
				
		int Sc = MyScore(len, offset);
//		if (CanNest and len >= MIN_MATCH) {
//			Sc += NextScore(p+len);
//		}
//		if (!CanNest and len >= MIN_MATCH) {
//			CanNest = false;
//		}
			
		while ((chain_len--!=0) and (s>=limit)) {
			if ((Read[s+len]==Read[p+len]) and (Read[s]==Read[p])) {	
				int l = 0;
				while (++l < max_match)
					if (Read[s+l] != Read[p+l])
						break;
				if (l >= MIN_MATCH) {
					int Sc2 = MyScore(l, p-s); // seems to not work
//					if (CanNest) {
//						Sc2 += NextScore(p+len);
//					}
					if (Sc2 > Sc) {
						len = l;
						offset = p-s;
						Sc = Sc2;
					}
				}
				if (l == max_match)
					break;
			}
			s = Prev[s & W_MASK];
		}

		return {len, offset, Sc};
	}
};



int CompressStrong (FastString* fs, JB_String* self, int Level) {
	Compression Fnd = {};
	Level = (std::max(std::min(Level, 30), 20) + 5) / 10;
	Fnd.Level = Level;
	require (Fnd.StartCompress(fs, self));
	
	int LastOut = 0;
	int p = Fnd.InsertSubStrings(0, 4);
	while (p < Fnd.Size) {
		auto [Len, Offset, _] = Fnd.FindMatch(p);	
		if (Len >= MIN_MATCH) {
			Fnd.Escape(LastOut, p);
			Fnd.PutOffset(Offset);
			Fnd.PutLength(Len - MIN_MATCH);
			LastOut = p + Len;
		} else {
			Len = 1;
		}
		p = Fnd.InsertSubStrings(p, Len);
	}
	
	Fnd.Escape(LastOut, Fnd.Size);
	Fnd.PutBits(31, 0);
	auto Size = Fnd.Size;
	int Req = (Size+20) + (Size>>6);
	int Actual = (Fnd.CmpOut - Fnd.CmpOutStart) << 2;
	*Fnd.CmpOutStart = Actual;
	fs->Length += Actual - Req;
	return Actual;
}


extern "C" int JB_Str_CompressChunk (FastString* fs, JB_String* self, int Level) {
	Allocator.lock();
	int rz = CompressStrong(fs, self, Level);
	Allocator.unlock();
	return rz;
}



// Should return the consumed length. in case str had multiple compressed chunks appended.

extern "C" int JB_Str_DecompressChunk (FastString* fs,  JB_String* self) {
	int StrLen = JB_Str_Length(self);
	require(StrLen);

	u8* A = JB_Str_Address(self);
	Decomp In = {(u32*)A, (u32*)(A + StrLen)};

	uint Size = In.Read4();
	if (Size > 16*1024*1024)
		return JB_ErrorHandleC("Size field corrupt", 0, false);
	
	Compression Cmp = {};
	auto Write = JB_FS_WriteAlloc_(fs, Size+7);
	if (!Write)
		return JB_ErrorHandleC("Size field corrupt", 0, false);
	
	Cmp.BitBuff = In.Read4();	
	for (int p = 0; p < Size; ) {
		int ago = Cmp.GetOffset(In);
		int s = p - ago;
		if (!ago) {
			int n = Cmp.GetLength(In);
			if (!n) break; // incase of bad data.
			Cmp.HeaderBits(In); // clear
			for (int i = 0; i < n; i++)
				Write[p++] = Cmp.GetBits(In, 8);
		
		} else if (ago > p) {
			Write[p++] = -(s+1);

		} else {
			int len = Cmp.GetLength(In) + MIN_MATCH;
			len = std::min(len, (int)(Size-p));

			if (ago >= 8) {				// much faster :)
				int L8 = (len + 7) >> 3;
				auto W = (u64*)(Write + p);
				auto R = (u64*)(Write + s);
				while (L8--)
					*W++ = *R++;
				p += len;
			
			} else while (len--)		// RLE.
				Write[p++] = Write[s++];
		}
	}
	
	fs->Length -= 7;
	return Size;
}

#endif

