

void ASMPrint(ASM oof);

#define TSC 1
#define TSC_RD TSC

typedef u64 (*Fn0)();
typedef u64 (*Fn1)(u64);
typedef u64 (*Fn2)(u64, u64);
typedef u64 (*Fn3)(u64, u64, u64);
typedef u64 (*Fn4)(u64, u64, u64, u64);
typedef u64 (*Fn5)(u64, u64, u64, u64, u64);
typedef u64 (*Fn6)(u64, u64, u64, u64, u64, u64);
typedef u64 (*Fn7)(u64, u64, u64, u64, u64, u64, u64);
typedef u64 (*Fn8)(u64, u64, u64, u64, u64, u64, u64, u64);


#define AlwaysInline static inline __attribute__((__always_inline__))


AlwaysInline void divmath(s64* r, ASM Op) {
	auto R3 = i3;
	auto R4 = i4;
	switch (Op & 3) { // so there are 4 possible divisions we can do
	  case 0:
		i1 = (s64)R3 % (s64)R4;
		i2 = (s64)R3 / (s64)R4;
		return;
	  case 1:
		i1 = (u64)R3 % (u64)R4;
		i2 = (u64)R3 / (u64)R4;		
		return;
	  case 2:
		i1 = (int)R3 % (int)R4;
		i2 = (int)R3 / (int)R4;
		return;
	  case 3:
		i1 = (uint)R3 %(uint)R4;
		i2 = (uint)R3 /(uint)R4;
		return;
	}
}


AlwaysInline void loadconst(s64* r, ASM Op, ASM* Code) {
	u32 Cond  = Setn_Condu;
	u32 Count = Setn_RCntu+1;
	u32 Back  = Setn_Lu+1;
	
	u64* Read = ((u64*)Code)-Back;
	auto Write = (u64*)(&i1);
	if (Cond) {
		if (Cond == 1) {
			if (u1) return;
		} else if (Cond == 2) {
			if (!u1) return;
		} else if (Cond == 3) {
			if (u1) Read+=Count; // conditional const read :)
		}
	}
	for_(Count)
		*Write++ = *Read++;
}


// #define Const_roti(x)  ((( int)((x)<<13))>>26)
// #define Const_rotu(x)  (((uint)((x)<<13))>>26)

// So we have i1, i2, i3
// i literally don't know what this does.
// is it... "a bunch of stuff".
// if it is... we should use the most suitable for anyting.
// that is... they all take the same form.
// this looks like a U4, we can branch on L.
// ROT can be it's own instruction.

AlwaysInline u64 bitstats(u64 R2, u64 R3, u64 Mode) { // rotate
	if (Mode == 0)							// popcount
		return __builtin_popcountll(R2); 
	if (Mode == 1)							// popcount
		return __builtin_popcount((u32)R2); 
	if (Mode == 2)							// lsb
		return JB_u64_Log2(R2 & -R2);
	if (Mode == 3)							// lsb
		return (uint)JB_u32_Log2(R2 & -R2);
	if (Mode == 4)							// msb
		return JB_u64_Log2(R2);
	if (Mode == 5)							// msb
		return (uint)JB_u32_Log2(R2);
	return 0;
}

//AlwaysInline u64 bitstats(s64* r, ASM Op) { // rotate
//	if (L == 3) {					// rotate (rot 1 == rot 63)
//		s64 R3 = u3 + _Const_rotu;
//		return JB_u64_RotL(R2, R3);
//	}
//  if (L == 3) {
//		s64 R3 = u3 + _Const_rotu;
//		return JB_u32_RotL((u32)R2, (u32)R3);
//	return 0;
//}

AlwaysInline uint bitstats32(s64* r, ASM Op) {
	int L = Const_Li;
	u64 R2 = u2;
	if (L == 0) {							// popcount
		return __builtin_popcount((u32)R2); 
	} else if (L == 1) {					// lsb
		return (uint)JB_u32_Log2(R2 & -R2);
	} else if (L == 2) {					// msb
		return (uint)JB_u32_Log2(R2);
	} else if (L == 3) {
		s64 R3 = u3 + Const_rotu;
		return JB_u32_RotL((u32)R2, (u32)R3);
	}
	return 0;
}


#define incr(o)				JB_Incr((JB_Object*)o)
#define freeifdead(o)		JB_FreeIfDead((JB_Object*)o)
#define decr(o)				JB_Decr((JB_Object*)o)
#define safedecr(o)			JB_SafeDecr((JB_Object*)o)
#define setref(t, a, b)		{if (t) JB_SetRef(a,b); else incr(b);}  


AlwaysInline JB_Object* alloc(_voidptr o) {
	// we need a class table, and look it up from there.
	// we don't have dynamicly created classes anyhow...
	return JB_AllocFrom(((JB_MemoryLayer*)o)->CurrBlock);
}


AlwaysInline void Conv (s64* s, int Conv) {
	// float, double, u64, s64. 12 conversions possible (and 4 pointless ones)
	float*	f = (float*)s;
	double*	d = (double*)s;
	u64*	u = (u64*)s;
    switch (Conv) {
        case 0 : *f = *f; break;
        case 1 : *f = *d; break;
        case 2 : *f = *u; break;
        case 3 : *f = *s; break;
        
        case 4 : *d = *f; break;
        case 5 : *d = *d; break;
        case 6 : *d = *u; break;
        case 7 : *d = *s; break;
        
        case 8 : *u = *f; break;
        case 9 : *u = *d; break;
        case 10: *u = *u; break;
        case 11: *u = *s; break;
        
        case 12: *s = *f; break;
        case 13: *s = *d; break;
        case 14: *s = *u; break;
        case 15: *s = *s; break;
    }
}


AlwaysInline bool Rare(s64* r, ASM Op) {
	auto r1 = i1;
	auto r2 = i2;
	if (!r1 and !r2) return true;	// HALT	
	if (r2 == 1) {		// time
		r[r1] = RDTSC();
	} else if (r2 == 2) {
		JB_Date__Sleep(1);
	}
	return false;
}


#define  FA  *((float*)A)
#define  FB  *((float*)B)
#define  DA  *((double*)A)
#define  DB  *((double*)B)
#define  UA  *((u64*)A)
#define  UB  *((u64*)B)
#define  IA  *((int*)A)
#define  IB  *((int*)B)
#define  uA  *((uint*)A)
#define  uB  *((uint*)B)
#define CmpSub(Mode, Cmp) case Mode: return (Cmp);


AlwaysInline bool CompI_(s64* r, ASM Op) {
	auto A = &i1;
	auto B = &i2;
	switch (Cmp_Cmpu) {
		CmpSub(0 , IA <  IB);
		CmpSub(1 , IA >  IB);
		CmpSub(2 , IA <= IB);
		CmpSub(3 , IA >= IB);

		CmpSub(4 , uA <  uB);
		CmpSub(5 , uA >  uB);
		CmpSub(6 , uA <= uB);
		CmpSub(7 , uA >= uB);

		CmpSub(8 , A  <  B );
		CmpSub(9 , A  >  B );
		CmpSub(10, A  <= B );
		CmpSub(11, A  >= B );

		CmpSub(12, UA <  UB);
		CmpSub(13, UA >  UB);
		CmpSub(14, UA <= UB);
	default:
		CmpSub(15, UA >= UB);
	};
}


AlwaysInline bool CompF_(s64* r, ASM Op) {
	auto A = &i1;
	auto B = &i2;

	switch (Cmp_Cmpu) {
		CmpSub(0 , FA <  FB);
		CmpSub(1 , FA >  FB);
		CmpSub(2 , FA <= FB);
		CmpSub(3 , FA >= FB);

		CmpSub(4 , DA <  DB);
		CmpSub(5 , DA >  DB);
		CmpSub(6 , DA <= DB);
	default:
		CmpSub(7 , DA >= DB);
		// add vec2 and vec4 later... assume vec3 has 0 for w
	};
}


AlwaysInline ASM* CompI(s64* r, ASM Op, ASM* Code) {
	uint Jump = Cmp_Lu; 
	bool b = CompI_(r, Op);
	if (Jump >= 32) {
		if (!b) return Code;
		return Code + Jump - (1<<9);
	}
		
	r[Jump] = b;
	return Code;
}


AlwaysInline ASM* CompF(s64* r, ASM Op, ASM* Code) {
	uint Jump = Cmp_Lu; 
	bool b = CompF_(r, Op);
	if (Jump >= 32) {
		if (!b) return Code;
		return Code + Jump - (1<<9);
	}
		
	r[Jump] = b;
	return Code;
}

AlwaysInline ASM* CompEq(s64* r, ASM Op, ASM* Code) {
	uint Shift = 64-(8<<CmpEq_bytesu);	// 0, 32, 48, 56  <-- 64, 32, 16, 8
	if (!((u1 xor u2)<<Shift))
		return Code;
	return Code + CmpEq_Jmpi;
}

AlwaysInline ASM* CompNeq(s64* r, ASM Op, ASM* Code) {
	uint Shift = 64-(8<<CmpEq_bytesu);
	if ( ((u1 xor u2)<<Shift))
		return Code;
	return Code + CmpEq_Jmpi;
}





void bswap32 (u32* Start, uint Count) {
	for_(Count) {
		*Start = __builtin_bswap32(*Start);
		Start++; 
	}
}


void bswap64 (u64* Start, uint Count) {
	for_(Count) {
		*Start = __builtin_bswap64(*Start);
		Start++; 
	}
}

		

void MemStuff(u32* A, u32* B, u32 Operation, u32 L) {
	// operation = xor/endian/fill/copy
	if (Operation == 0 or 1)
		std::fill(A, A+((1+L)<<2), -Operation);
	  else if (Operation == 2)
		memcpy(A, B, 1+L);
	  else if (Operation == 3)
		bswap32(A, 1+L);
	  else if (Operation == 4)
		bswap64((u64*)A, 1+L);
}

			
AlwaysInline void CountConst(s64* r, ASM Op) {
	int Size = CNTC_sizeu;
	int Off  = CNTC_Lu-8;
	int Add  = CNTC_cnstu-128;
	switch (Size) {
	case 0:
		p1(u8 )[Off] += Add;  break;
	case 1:
		p1(u16)[Off] += Add;  break;
	case 2:
		p1(u32)[Off] += Add;  break;
	case 3:
		p1(u64)[Off] += Add;  break;
	}
}


// BasicASMFunc
AlwaysInline ASM* Return (s64*& r, ASM* Code, ASM Op) {
	Code			= (ASM*)(r[-1]);
	auto CpyFrom    = u1; 
	auto CpyLen     = u2; // unused
	auto j			= *Code; // this is at where we are going back to.
	Code += 2;

	auto Result     = r[CpyFrom];
	r			   -= Func_SaveRegsu_(j) + 2;
	if (Func_Modeu_(j))
		incr(Result);
	r[Func_ENTRu_(j)] = Result;
	return Code;
}


#define RegCpy(n)    case n: Dest[n] = Src[Regs.R##n]
AlwaysInline ASM* BumpStack (s64*& Src, ASM* Code, ASM j) { // jumpstack 
	BasicRegs2	Regs = *((BasicRegs2*)Code); 
	auto		N    = Func_RegsToSendu_(j.Raw);
	s64*		Dest = Src+Func_SaveRegsu_(j.Raw)+1;
	*(u64*)Dest		 = (u64)(Code-1); // return point
	Dest++;
	switch (N) {
	default:
		RegCpy(8);
		RegCpy(7);
		RegCpy(6);
		RegCpy(5);
		RegCpy(4);
		RegCpy(3);
		RegCpy(2);
		RegCpy(1);
	case 0:
		Dest[0] = 0;
	};

	u32 RP = Regs.Jump;
	if (RP<32) {
		Src = Dest;
		return Code + signext32(RP-32, 25);
	}
	ASM* Result = ((ASM**)Src)[RP];
	Src = Dest;
	return Result;
}


#define FFISub(Mode, FP)	case 11-Mode:	return ((Fn##Mode)Fn)FP;
AlwaysInline u64 ForeignFuncSimple(s64* r, ASM*& Code, ASM Op) {
	// use libffi later
	// Op.Raw |= *Code++;
	auto Oof = (BasicRegs3*)Code;
	auto j = *Oof;
	Code = (ASM*)Oof;
	Goto Fn = (Goto*)r[0]; // it was the register pointer... but needs fix now
	switch (Func_RegsToSendu) {
	default:
		FFISub(8 , (r[j.R1], r[j.R2], r[j.R3], r[j.R4], r[j.R5], r[j.R6], r[j.R7], r[j.R8]));
		FFISub(7 , (r[j.R1], r[j.R2], r[j.R3], r[j.R4], r[j.R5], r[j.R6], r[j.R7]));
		FFISub(6 , (r[j.R1], r[j.R2], r[j.R3], r[j.R4], r[j.R5], r[j.R6]));
		FFISub(5 , (r[j.R1], r[j.R2], r[j.R3], r[j.R4], r[j.R5]));
		FFISub(4 , (r[j.R1], r[j.R2], r[j.R3], r[j.R4]));
		FFISub(3 , (r[j.R1], r[j.R2], r[j.R3]));
		FFISub(2 , (r[j.R1], r[j.R1]));
		FFISub(1 , (r[j.R1]));
		FFISub(0 , ());
	};
}


bool VerifyTable(jb_vm& vm, const Goto* JumpTable) {
	if (vm.Stack.Verified)
		return true;
	auto first = JumpTable[0];
	for_(255) {
		if (JumpTable[i]!=first and JumpTable[i+1]!=first and JumpTable[i] >= JumpTable[i+1]) {
			debugger;
			return false;
		}
	}
	vm.Stack.Verified = true; 
	return true;
}

