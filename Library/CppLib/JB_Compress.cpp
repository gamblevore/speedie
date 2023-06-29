
#include "JB_Compress.h"
#include "divsufsort.h"

#define kExtend 0x70


struct CompState : FastBuff {
	int					LastOut;
	int*				Suffixes;
	int*				SortPositionAtByte;	
	int					B;
	
	
	bool TestOneCost (u8* Find,  u8* E,  int G,  MatchFound& Best, int Esc) {
		int N		= Suffixes[G];
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
		int* R0		= Suffixes; 
		int* SP		= SortPositionAtByte;
		divsufsort(Read, R0, n);
		for_(n)	{				// code is simple, but concept is confusing.
			SP[R0[i]] = i;
			R0[i] = n - R0[i];
		}

		bool print_sorted_array = 0; // debug it
		if (print_sorted_array) for_(n) {
			auto pos = (Read+n)-R0[i];
			for (int j = 0; j < 32; j++) {
				char c = pos[j]; 
				if (!c)
					break;
				if (c <= 32)
					c = 32;
				printf("%c", c);
			}
			puts("");
		}
		
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
		(CopyBytes(B, Write, N));
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
static FastBuff		FB;
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
		C.Suffixes				= (int*)JB_realloc(C.Suffixes,	2*ChunkLength*sizeof(int)); // dict
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
	C.WriteByte(kExtend); // end-marker
	dbgexpect (C.LastOut == C.Expected);
	fs->Length += C.Length();
}


//////////////////////////////////////////////////// DECOMP //////////////////////////////////////////////////////////////
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
		  else if (Code > kExtend)		//UPDATE
			Addr = DeBig_(Addr, fb, Code, AddrEnd);
		  else
			break; // finished!
	}
	
	require (Addr != ErrP);
	DReq(Addr == AddrEnd,						"Chunk read overflow",		0);
	DReq(fb.Expected == fb.Length(),			"Chunk write-length error",	0);
	fs->Length += fb.Expected;
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



///
///
/////
/// balz... modified from balz.cpp by Ilya Muravyov
/////
///
///

typedef unsigned short		ushort;

const int MIN_MATCH=3;
const int MAX_MATCH=255+MIN_MATCH;

const int BUF_BITS = 25;
const int BUF_SIZE = 1<<BUF_BITS; // I only input 4MB chunks... but I need this number
const int BUF_MASK = BUF_SIZE-1;  // changing it reduces compression ratio! Strangely!
  
const int TAB_BITS = 7;
const int TAB_SIZE = 1<<TAB_BITS;
const int TAB_MASK = TAB_SIZE-1;


struct Counter {
	ushort p1;
	ushort p2;

	uint P() const {
		return p1+p2;
	}

	void Update0() {
		p1-=p1>>3;
		p2-=p2>>6;
	}

	void Update1() {
		p1+=(p1^65535)>>3;
		p2+=(p2^65535)>>6;
	}
};


struct BalzComp {
	u8*			output;
	u8*			OutputEnd;
	u8*			input;
	u8*			inputEnd;
	uint		code;
	uint		low;
	uint		high;
	// why not just use fastbuff? its literally the same info?
	FastString* fs;
	Counter		counter1[256][512];
	Counter		counter2[256][TAB_SIZE];
	int			cnt[1<<16];
	uint		tab[1<<16][TAB_SIZE];
	
	inline u8 get () {
		DReq(input < inputEnd, "Chunk read overflow", 0);
		return *input++;
	}
	
	void Reset() {
		memset(this, 0, sizeof(*this));
		ushort* Start = &(counter1[0][0].p1);
		std::fill(Start, Start+sizeof(counter1), 1<<15);
		Start = &(counter2[0][0].p1);
		std::fill(Start, Start+sizeof(counter2), 1<<15);
		high = -1;
	}
	
	void Encode(int bit, Counter& counter) {
		const uint mid=low+((u64(high-low)*(counter.P()<<15))>>32);

		if (bit) {
			high=mid;
			counter.Update1();
		} else {
			low=mid+1;
			counter.Update0();
		}
		
		u8* out = JB_FS_WriteAlloc_(fs, 4);
		if (out) {
			auto start = out;
			while ((low^high)<(1<<24)) {
				*out++ = low>>24;
				low <<= 8;
				high = (high<<8)|255;
			}
			fs->Length -= (4-(out-start));
		}
	}

	void Flush() {
		u8* out = JB_FS_WriteAlloc_(fs, 4);
		for (int i=0; i<4; ++i) {
			*out++ = low>>24;
			low <<= 8;
		}
	}

	void Init() {
		for (int i=0; i<4; ++i) {
			code=(code<<8)|get();
		}
	}

	int Decode(Counter& counter) {
		const uint mid = low + ((u64(high-low)*(counter.P()<<15))>>32);

		const int bit = code<=mid;
		if (bit) {
			high=mid;
			counter.Update1();
		} else {
			low=mid+1;
			counter.Update0();
		}

		while ((low^high) < (1<<24)) {
			code=(code<<8)|get();
			low<<=8;
			high=(high<<8)|255;
		}

		return bit;
	}


	void Encode (int t, int c1) {
		int ctx=1;
		while (ctx<512) {
			const int bit=((t&256)!=0);
			t+=t;
			Encode(bit, counter1[c1][ctx]);
			ctx+=ctx+bit;
		}
	}

	void EncodeIdx (int x, int c2) {
		int ctx=1;
		while (ctx<TAB_SIZE) {
			const int bit=((x&(TAB_SIZE>>1))!=0);
			x+=x;
			Encode(bit, counter2[c2][ctx]);
			ctx+=ctx+bit;
		}
	}

	int Decode (int c1) {
		int ctx=1;
		while (ctx<512)
			ctx+=ctx+Decode(counter1[c1][ctx]);
		return ctx-512;
	}

	int DecodeIdx (int c2) {
		int ctx=1;
		while (ctx<TAB_SIZE)
			ctx+=ctx+Decode(counter2[c2][ctx]);
		return ctx-TAB_SIZE;
	}
	
	inline uint get_hash(u8* buf, int p) {
		return ((reinterpret_cast<uint&>(buf[p])&0xffffff) * 2654435769UL)&~BUF_MASK;
	}
	
	inline int get_pts(int len, int x) {
		return len>=MIN_MATCH
			? (len<<TAB_BITS)-x
			: ((MIN_MATCH-1)<<TAB_BITS)-8;
	}
	
	int get_pts_at(u8* buf, int p, int n) {
		const int c2=reinterpret_cast<ushort&>(buf[p-2]);
		const uint hash=get_hash(buf, p);
		
		int len=MIN_MATCH-1;
		int idx=TAB_SIZE;
		
		int max_match=n-p;
		if (max_match>MAX_MATCH)
			max_match=MAX_MATCH;
		
		for (int x=0; x<TAB_SIZE; ++x) {
			const uint d=tab[c2][(cnt[c2]-x)&TAB_MASK];
			if (!d)
				break;
			
			if ((d&~BUF_MASK)!=hash)
				continue;
			
			const int s=d&BUF_MASK;
			if ((buf[s+len]!=buf[p+len])||(buf[s]!=buf[p]))
				continue;
			
			int l = 0;
			while (++l<max_match)
				if (buf[s+l]!=buf[p+l])
					break;
			if (l>len) {
				idx=x;
				len=l;
				if (l==max_match)
					break;
			}
		}
		
		return get_pts(len, idx);
	}
	
	
	void balz_compress(JB_String* Data, bool max) {
		int Length = JB_Str_Length(Data);		
		int best_idx[MAX_MATCH+1];
		auto buf = Data->Addr;
		
		int p = 0;
		while (p < 2 and p < Length)
			Encode(buf[p++], 0);
		
		while (p < Length) {
			const int  c2   = reinterpret_cast<ushort&>(buf[p-2]);
			const uint hash = get_hash(buf, p);
			
			int len = MIN_MATCH-1;
			int idx = TAB_SIZE;
			
			int max_match=Length-p;
			if (max_match>MAX_MATCH)
				max_match=MAX_MATCH;
			
			for (int x = 0; x < TAB_SIZE; ++x) {
				const uint d = tab[c2][(cnt[c2]-x)&TAB_MASK];
				if (!d)
					break;
				
				if ((d&~BUF_MASK)!=hash)
					continue;
				
				const int s = d&BUF_MASK;
				if ((buf[s+len]!=buf[p+len])||(buf[s]!=buf[p]))
					continue;
				
				int l = 0;
				while (++l<max_match)
					if (buf[s+l]!=buf[p+l])
						break;
				if (l > len) {
					for (int i=l; i>len; --i)
						best_idx[i]=x;
					idx=x;
					len=l;
					if (l==max_match)
						break;
				}
			}
			
			if (max && len>=MIN_MATCH) {
				int sum=get_pts(len, idx)+get_pts_at(buf, p+len, Length);
				if (sum<get_pts(len+MAX_MATCH, 0)) {
					const int lookahead=len;
					for (int i=1; i<lookahead; ++i) {
						const int tmp=get_pts(i, best_idx[i])+get_pts_at(buf, p+i, Length);
						if (tmp > sum) {
							sum=tmp;
							len=i;
						}
					}
					
					idx = best_idx[len];
				}
			}
			
			tab[c2][++cnt[c2]&TAB_MASK]=hash|p;
			
			if (len >= MIN_MATCH) {
				Encode((256-MIN_MATCH)+len, buf[p-1]);
				EncodeIdx(idx, buf[p-2]);
				p += len;
			} else {
				Encode(buf[p], buf[p-1]);
				++p;
			}
		}

		Flush();
	}

	
	int balz_decompress(JB_String* S, int flen) {
		u8* buf = output;
		input = S->Addr;
		inputEnd = input + S->Length;
		
		Init();
		
		int p = 0;
		while (p < 2 and p < flen) {
			buf[p++] = Decode(0);
		}
		
		while (p < flen) {
			const int tmp = p;
			const int c2 = reinterpret_cast<ushort&>(buf[p-2]);
			const int t = Decode(buf[p-1]);
			if (t >= 256) {
				int len=t-256;
				int s=tab[c2][(cnt[c2]-DecodeIdx(buf[p-2]))&TAB_MASK];
				DReq(s >= 0 and s < p, "Corrupted ro data", -1);
				buf[p++]=buf[s++];
				buf[p++]=buf[s++];
				buf[p++]=buf[s++];
				while (len--)
					buf[p++]=buf[s++];
			} else {
				buf[p++]=t;
			}
			
			tab[c2][++cnt[c2]&TAB_MASK]=tmp;
		}
		
		return p;
	}
};



static BalzComp* BB;
static BalzComp* GetComp(FastString* out, int N=0) {
	if (!BB) BB = (BalzComp*)JB_zalloc(sizeof(BalzComp)); 
	BB->Reset();
	if (N) {
		BB->output = JB_FS_WriteAlloc_(out, N);
		BB->OutputEnd = BB->output+N;
	}
	BB->fs = out;
	return BB;
}

extern "C" void JB_App__ClearCaches(int which) {
	JB_unalloc((void**)&BB);
	JB_unalloc((void**)&sigh.Suffixes);
	JB_unalloc((void**)&sigh.SortPositionAtByte);
	sigh.B = 0;
}

extern "C" int JB_BALZ_CompressChunk(FastString* fs, JB_String* In, bool Strong) {
	if (!In or !fs)
		return 0;
	
	auto B = GetComp(fs);
	auto first = JB_FS_StreamLength(fs);
	B->balz_compress(In, Strong);
	return JB_FS_StreamLength(fs) - first;
}


extern "C" int JB_BALZ_DecompressChunk(FastString* fs, JB_String* In, int Expected) {
	DReq(JB_Str_Length(In) >= 5, "Too short chunk received",	0);    // i think 5 is the minimum?
	if (!fs) return 0;
	
	auto B = GetComp(fs, Expected);
	int Created = B->balz_decompress(In, Expected);
	if (Created >= 0)
		DReq(Expected == Created, "Chunk write-length error",	0);
    return Created;
}


