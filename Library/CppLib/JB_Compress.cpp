
#include "JB_Compress.h"
#include "JB_MemUtils.h"
#include "CompressionProbability.h"
// Can we speed up myscore?



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

static PicoDate			JB_LastFlush;
static DateLocker		Allocator;
static u8*				Space;
//static int				TotalEscaped;



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

extern "C" int JB_BasicCareTaker(PicoDate D) {
	if (D - JB_LastFlush >= 64*1024) { // one second.
		JB_LastFlush = D;
		fflush(stdout);
	}

	return CompressionFree(10*64*1024);	// 10s ago!
}


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
scint HEAD_TO_PREV = HASH1_SIZE + HASH2_SIZE;
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
    uint offbits = std::max(SLOT_BITS+JB_Int_Log2(offset), W_MINUS+1+SLOT_BITS);
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
	u8*				Read;
	uint*			CmpOut;
	uint*			CmpOutStart;
	uint			h1;
	uint			h2;
	uint64_t		BitBuff;
	int				BitCount;

	void Write4 (uint i) {
		*CmpOut++ = i;
	}
	
	bool StartCompress (FastString* fs, JB_String* In) {
		int N = (HASH1_SIZE + HASH2_SIZE + W_SIZE) * sizeof(int);
		if (!Space and !(Space = JB_Realloc(NULL, N)))
			return false;
		
		int Size = JB_Str_Length(In);
		
		CmpOut = (uint*)JB_FS_WriteAlloc_(fs, (Size+20) + (Size>>6)); // might expand a little.
		if (!CmpOut)
			return false;
		CmpOutStart = CmpOut;

		Head = (int*)Space;
		Read = JB_Str_Address(In);

		Write4(-1);				// reserve space for compressed size.
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
			int Zeros = __builtin_clzll(B); // log2-safe
			BitCount = Missing + (Zeros + 1);
			return Zeros;
		}
		return 0;			/// Ooof
	}

	inline int GetOffset (Decomp& In) {
		int log = GetBits(In, SLOT_BITS) + W_MINUS;
		int Add = 0;
		if (log > W_MINUS)
			Add = 1<<log;
		  else
			log = W_MINUS+1;
		return GetBits(In, log) + Add;
	}
	
	void EscapeSub (int LastOut, int p) {
		probability_escape(p - LastOut);
		if (LastOut+1 == p) {
			int x = LastOut + 1 + Read[LastOut];
			if (x < W_SIZE)
				return PutOffset(x);
		}
		// I think the only way to improve this, is huff the escaped data. maybe a static-distribution-table?
		
		PutOffset(0);
		PutLength(p - LastOut);
		while (LastOut < p)
			PutBits(8, Read[LastOut++]);
	}

/*total {
	GrandTotal 567428
	Slot 32 = 119883 // (21.1%, 21.1%)  // 1 gain
	Slot 64 = 49465 // (8.7%, 29.8%)    // 1 gain
	Slot 128 = 55573 // (9.8%, 39.6%)   // 9 bit  --> 8 avail  --> 255 // 2 gain, 49.5 bits!
	Slot 256 = 62581 // (11.0%, 50.7%)
	Slot 512 = 57313 // (10.1%, 60.8%)
	Slot 1024 = 56816 // (10.0%, 70.8%)
	Slot 2048 = 55536 // (9.8%, 80.6%)
	Slot 4096 = 46539 // (8.2%, 88.8%)
	Slot 8192 = 37537 // (6.6%, 95.4%)
	Slot 16384 = 20584 // (3.6%, 99.0%)
	Slot 32768 = 5601 // (1.0%, 100.0%)
	Final 2313504-2299296 // 14K? ooof?
	      2302128
		  2300924 // 8, 3, 4	      
	Escape 830623 / 202325
} */

	uint PutOffsetSub (uint offset, uint Bits, bool More=true) {
		int B = 1<<Bits;
		int extra = offset >= B;
		PutBits(Bits+More, (offset&(B-1)) | (extra<<Bits));
		return offset >> Bits;
	}

	void PutOffset2 (uint p, uint offset) {
		probability_add(offset, W_MINUS);
//		  2300928 // 8, 3, 4	     
//		  2299300 // 9, 3, 3 // seems the most optimal.
 
		if (p >= 32*1024)
			return PutOffset(offset);
		if ((offset = PutOffsetSub(offset, 9)))
			if ((offset = PutOffsetSub(offset, 3)))
				PutOffsetSub(offset, 3, false);
	}
	
	
	
	

	inline void PutOffset (uint offset) {
		int log = std::max(JB_Int_Log2(offset), W_MINUS);
		PutBits(SLOT_BITS, log-W_MINUS);
		if (log > W_MINUS)
			offset -= 1<<log;
		  else
			log = W_MINUS+1;
		PutBits(log, offset);				// Requires 6 bits, and stores numbers 0 to 63
	}
	
	inline void PutLength (uint l) {
		int ll = 0;
		int n = 0;
		do {
			if (l<A_) {
				n = 1; ll = A_BITS; l -= 00; break;
			}
			if (l<B_) {
				n = 2; ll = B_BITS; l -= A_; break;
			}
			if (l<C_) {
				n = 3; ll = C_BITS; l -= B_; break;
			}
			if (l<D_) {
				n = 4; ll = D_BITS; l -= C_; break;
			}
			if (l<E_) {
				n = 5; ll = E_BITS; l -= D_; break;
			}
			if (l<F_) {
				n = 6; ll = F_BITS; l -= E_; break;
			}
			if (l<G_) {
				n = 7; ll = G_BITS; l -= F_; break;
			}
			if (l<H_) {
				n = 8; ll = H_BITS; l -= G_; break;
			}
			if (l<I_) {
				n = 9; ll = I_BITS; l -= H_; break;
			}
			{
				(void)I_; // just for viewing
				n = 10; ll = J_BITS; l -= I_; break;
			}
		} while (0);
		PutBits(n, 1);
		PutBits(ll, l);
	}
	
	inline int GetLength (Decomp& In) {
		int Z = HeaderBits(In);
		int Mode = A_BITS;
		switch (Z) {
			case 0:  break;
			case 1:  {Mode = B_BITS; Z = A_; break;}
			case 2:  {Mode = C_BITS; Z = B_; break;}
			case 3:  {Mode = D_BITS; Z = C_; break;}
			case 4:  {Mode = E_BITS; Z = D_; break;}
			case 5:  {Mode = F_BITS; Z = E_; break;}
			case 6:  {Mode = G_BITS; Z = F_; break;}
			case 7:  {Mode = H_BITS; Z = G_; break;}
			case 8:  {Mode = I_BITS; Z = H_; break;}
			default: {Mode = J_BITS; Z = I_; break;}
		}
		return GetBits(In, Mode) + Z;
	}
};



int CompressStrong (FastString* fs, JB_String* self, int Level) {
	Compression Fnd = {};
	require (Fnd.StartCompress(fs, self));
	
	Level = (std::max(std::min(Level, 30), 20) + 5) / 10;
	int LastOut = 0;
	int p = 0;
	int Len = 4;
	auto Read = Fnd.Read;
	auto Head = Fnd.Head;
	auto Size = self->Length;
	while (p+Len < Size) {
		{
			int h1 = Fnd.h1; int h2 = Fnd.h2;
			auto Prev = Head + HEAD_TO_PREV;
			while (Len-- > 0) {
				Head[h1]=p;
				Prev[p&W_MASK]=Head[h2+HASH1_SIZE];
				Head[h2+HASH1_SIZE]=p++;
				h1 = update_hash1(h1, Read[p+(HASH1_LEN-1)]);
				h2 = update_hash2(h2, Read[p+HASH1_LEN]);
			}
			Fnd.h1 = h1; Fnd.h2 = h2;
		}
		Len = 1;
		int Offset = W_SIZE;
		
		const int max_match = Size - p;
		const int limit = std::max(p - W_SIZE, 0);
		{
			int s = Head[Fnd.h1];
			if (s >= limit and Read[s]==Read[p]) {
				int l = 0;
				while (++l < max_match)
					if (Read[s+l] != Read[p+l])
						break;
				if (l > Len) {
					Len = l;
					Offset = p-s;
				}
			}
		}

		{ // early free vars
			int chain_len = 16 << (4*Level);
			int s = Head[Fnd.h2+HASH1_SIZE];
			int Sc = MyScore(Len, Offset);
	//		if (CanNest and len >= MIN_MATCH) {
	//			Sc += NextScore(p+len);
	//		}
	//		if (!CanNest and len >= MIN_MATCH) {
	//			CanNest = false;
	//		}
			
			auto Prev = Head + HEAD_TO_PREV;
			while ((chain_len--!=0) and (s>=limit)) {
				if ((Read[s+Len]==Read[p+Len]) and (Read[s]==Read[p])) {	
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
							Len = l;
							Offset = p-s;
							Sc = Sc2;
						}
					}
					if (l == max_match)
						break;
				}
				s = Prev[s & W_MASK];
			}
		}
		
		if (Len >= MIN_MATCH) {
			if (LastOut < p)
				Fnd.EscapeSub(LastOut, p);
			Fnd.PutOffset2(p, Offset);			
			Fnd.PutLength(Len - MIN_MATCH);
			LastOut = p + Len;
		} else {
			Len = 1;
		}
	}
	
	if (LastOut < Size)
		Fnd.EscapeSub(LastOut, Size);
	Fnd.PutBits(31, 0);
	int Req = (Size+20) + (Size>>6);
	int Actual = ((int)(Fnd.CmpOut - Fnd.CmpOutStart)) << 2;
	*Fnd.CmpOutStart = Actual;
	probability_output(Actual);
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
	Decomp In;
	{
		int N = JB_Str_Length(self);
		require(N);
		u8* A = JB_Str_Address(self);
		In = {(u32*)A, (u32*)(A + N)};
	 }

	uint Size = In.Read4();
	if (Size > 16*1024*1024)
		return JB_ErrorHandleC("mz chunk size bad", 0, false);
	
	Compression Cmp = {};
	auto Write = JB_FS_WriteAlloc_(fs, Size+7);
	if (!Write)
		return 0;
	
	Cmp.BitBuff = In.Read4();	
	for (int p = 0; p < Size;) {
		int ago = Cmp.GetOffset(In);
		int s = p - ago;
		if (!ago) {
			int n = Cmp.GetLength(In);
			if (n <= 0 or p+n>Size)
				return JB_ErrorHandleC("mz corruption", 0, false);
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


