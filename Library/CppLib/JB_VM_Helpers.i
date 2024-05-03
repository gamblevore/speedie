

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


AlwaysInline void DivMath(Register* r, ASM Op) {
	auto R3 = i3;
	auto R4 = i4;
	uint A = n1;
	uint B = n2;
	if (!A) A = 32; // dump it safely
	if (!B) B = 32; // dump it safely
	auto pA = &(r[A].Int);
	auto pB = &(r[B].Int);

	switch (Div_Kindu & 3) { // so there are 4 possible divisions we can do
	  case 0:
		*pA = (s64)R3 % (s64)R4;
		*pB = (s64)R3 / (s64)R4;
		return;
	  case 1:
		*pA = (u64)R3 % (u64)R4;
		*pB = (u64)R3 / (u64)R4;
		return;
	  case 2:
		*pA = (int)R3 % (int)R4;
		*pB = (int)R3 / (int)R4;
		return;
	  case 3:
		*pA = (uint)R3 %(uint)R4;
		*pB = (uint)R3 /(uint)R4;
		return;
	}
}


AlwaysInline void RotateConst (Register* r, ASM Op) {
	int64 A = JB_u64_RotL(Const_Valueu, Const_rotu);
	if (Const_invu)
		A = ~A;
	i1 = A;
}

AlwaysInline ASM* LoadConst (Register* r, ASM Op, ASM* Code) {
	uint64 Value = Setn_Valueu;
	int Remain = Op&3;
	if (Remain) {
		if (Remain == 1)
			Value <<= 32; 
		  else
			// these 16-bits arent really needed. Even for SIMD!
			// we need like... loading 4 small values
			// or 4 same values. Or loading one value into a specific field.
			Value = (uint64)(*Code++) << 32;
		Value |= *Code++;
	}
	if (!Setn_Condu or !r->Int) {
		if (Setn_Invu)
			Value = ~Value;
		r->Int = Value; 
	}
	return Code; 
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

AlwaysInline uint bitstats32(Register* r, ASM Op) {
	int L = Const_Valuei;
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
#define table(b, c)			((u64)(((void**)(&vm.Env))[b])+c)  

#define mem(t)				((t*)u2)[u3+Mem_Lu]
#define mem2(t)				(u2 = (u64)((t*)u2 + Mem_moveu-1))

AlwaysInline JB_Object* alloc(void* o) {
	// we need a class table, and look it up from there.
	// we don't have dynamicly created classes anyhow...
	return JB_AllocNew(((JB_MemoryLayer*)o)->CurrBlock);
}


AlwaysInline void Conv (Register* r, int Conv, int Op) {
	// float, double, u64, s64. 12 conversions possible (and 4 pointless ones)

	Register& d = *(r + n1);  
	Register& s = *(r + n3);  
    switch (Conv) {
        case 0 : d.Float = s.Float;  break;
        case 1 : d.Float = s.Double; break;
        case 2 : d.Float = s.Uint;   break;
        case 3 : d.Float = s.Int;    break;
        
        case 4 : d.Double = s.Float;  break;
        case 5 : d.Double = s.Double; break;
        case 6 : d.Double = s.Uint;   break;
        case 7 : d.Double = s.Int;    break;
        
        case 8 : d.Uint = s.Float;  break;
        case 9 : d.Uint = s.Double; break;
        case 10: d.Uint = s.Uint;   break;
        case 11: d.Uint = s.Int;    break;
        
        case 12: d.Int = s.Float;  break;
        case 13: d.Int = s.Double; break;
        case 14: d.Int = s.Uint;   break;
        case 15: d.Int = s.Int;    break;
    }
}


AlwaysInline bool Rare (Register* r, ASM Op) {
	auto r1 = i1;
	auto r2 = i2;
	if (!r1 and !r2) return true;	// HALT	
	if (r2 == 1) {		// time
		r[r1].Uint = RDTSC();
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


AlwaysInline bool CompI_(Register* r, ASM Op) {
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


AlwaysInline bool CompF_(Register* r, ASM Op) {
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


AlwaysInline ASM* CompI(Register* r, ASM Op, ASM* Code) {
	uint Jump = Cmp_Lu; 
	bool b = CompI_(r, Op);
	if (Jump >= 32) {
		if (!b) return Code;
		return Code + Jump - (1<<9);
	}
		
	r[Jump].Int = b;
	return Code;
}


AlwaysInline ASM* CompF(Register* r, ASM Op, ASM* Code) {
	uint Jump = Cmp_Lu; 
	bool b = CompF_(r, Op);
	if (Jump >= 32) {
		if (!b) return Code;
		return Code + Jump - (1<<9);
	}
		
	r[Jump].Int = b;
	return Code;
}

AlwaysInline ASM* CompEq(Register* r, ASM Op, ASM* Code) {
	if (!(u1 xor u2))
		return Code;
	return Code + CmpEq_Jmpi;
}

AlwaysInline ASM* CompNeq(Register* r, ASM Op, ASM* Code) {
	if (u1 xor u2)
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

			
AlwaysInline void CountConst(Register* r, ASM Op) {
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
AlwaysInline ASM* Return (Register*& rp, ASM* Code, ASM Op) {
	Register* r		= rp;
	if ((u2 == 0) != RET_Existsu)
		return Code; // skip
	auto S			= r[-1].Stack;
	Code			= (ASM*)S.Addr + 2;
	auto To			= r - (S.Regs + 2);
	auto From		= r+u1;
	auto Result		= *From++;
	rp = To;

	// could use RET_Li to return true?
	if (S.Incr)
		incr(Result.Obj);
	int More = RET_Countu;
	while (More -->= 0) {
		To[++S.Regs] = Result;
		Result = *From++;
	}
		
	return Code;
}


/*
var transfers:
	1) Variable width in memory: Complex. Slow. Can't be simultaneous.
	2) Copy them by half: 		 Requires very long param lists. 7.5 simds max.
	3) Bigger registers:		 Double the size. Slower to save/restore. Simpler and faster to call functions and SIMD.
 */


#define Transfer(Input,Shift)  (r[(Input>>(Shift*5))&31])
AlwaysInline ASM* BumpStack (Register*& rp, ASM* Code, ASM Op) { // jumpstack
	Register* r = rp;
	ASM  Code2 = Code[0];
	ASM  Code3 = Code[1];
	int RemainCodes = Op&3;
	int Save = Func_SaveRegsu;
	Register* ENTR = r+Save+1;
	ENTR->Stack.Addr = Code+RemainCodes;
	ENTR->Stack.Regs = Save;
	ENTR->Stack.Incr = Func_Incru;

	r = ++ENTR; rp = r;
	ENTR[0] = {};
	ENTR[1] = Transfer(Code2, 0);
	ENTR[2] = Transfer(Code2, 1);
	ENTR[3] = Transfer(Code2, 2);
	ENTR[4] = Transfer(Code2, 3);
	ENTR[5] = Transfer(Code2, 4);
	ENTR[6] = Transfer(Code2, 5);
	if (RemainCodes>1) {					// transfer more regs.
		debugger; 
		ENTR[ 6] = Transfer(Code3, 0);
		ENTR[ 7] = Transfer(Code3, 1);
		ENTR[ 8] = Transfer(Code3, 2);
		ENTR[ 9] = Transfer(Code3, 3);
		ENTR[10] = Transfer(Code3, 4);
		ENTR[11] = Transfer(Code3, 5);
	}
	// we can take 31 values off the lower end. like 0x8000 is -32K 
	// read from registers instead.

	int j = Func_JUMPi;
	return Code + j;
}


AlwaysInline ASM* TailStack (Register* r, ASM* Code, ASM Op) {
	ASM Code2 = Code[0];
	// What if this overwrites params that we mean to read from?
	
	r[1] = Transfer(Code2, 0);
	r[2] = Transfer(Code2, 1);
	r[3] = Transfer(Code2, 2);
	r[4] = Transfer(Code2, 3);
	r[5] = Transfer(Code2, 4);
	r[6] = Transfer(Code2, 5);

	return Code + Tail_JUMPi;
}


#define FFISub(Mode, FP)	case 11-Mode:	return ((Fn##Mode)Fn)FP;
AlwaysInline u64 ForeignFuncSimple(Register* r, ASM*& Code, ASM Op) {
	// use libffi later
	// Op.Raw |= *Code++;
//	auto Oof = (BasicRegs3*)Code;
//	auto j = *Oof;
//	Code = (ASM*)Oof;
//	Goto Fn = (Goto*)r[0]; // it was the register pointer... but needs fix now
//	switch (8/*Func_RegsToSendu*/) {
//	default:
//		FFISub(8 , (r[j.R1], r[j.R2], r[j.R3], r[j.R4], r[j.R5], r[j.R6], r[j.R7], r[j.R8]));
//		FFISub(7 , (r[j.R1], r[j.R2], r[j.R3], r[j.R4], r[j.R5], r[j.R6], r[j.R7]));
//		FFISub(6 , (r[j.R1], r[j.R2], r[j.R3], r[j.R4], r[j.R5], r[j.R6]));
//		FFISub(5 , (r[j.R1], r[j.R2], r[j.R3], r[j.R4], r[j.R5]));
//		FFISub(4 , (r[j.R1], r[j.R2], r[j.R3], r[j.R4]));
//		FFISub(3 , (r[j.R1], r[j.R2], r[j.R3]));
//		FFISub(2 , (r[j.R1], r[j.R1]));
//		FFISub(1 , (r[j.R1]));
//		FFISub(0 , ());
//	};
	return 0;
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

