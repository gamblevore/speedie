
#include "ffi.h"
typedef void (*FFI_Fn)(void);



Register DummyReg;
AlwaysInline void DivMath(Register* r, ASM Op) {
	auto R3 = i3;
	auto R4 = i4;
	uint A = n1;
	uint B = n2;
	auto& pA = r[A].Int;
	auto& pB = r[B].Int;
	if (!A) pA = DummyReg.Int;
	if (!B) pB = DummyReg.Int;
	
	switch (Div_Kindu & 3) { // so there are 4 possible divisions we can do
	  case 0:
		pA = R3 % R4;
		pB = R3 / R4;
		return;
	  case 1:
		pA = (u64)R3 % (u64)R4;
		pB = (u64)R3 / (u64)R4;
		return;
	  case 2:
		pA = (int64)((int)R3 % (int)R4);
		pB = (int64)((int)R3 / (int)R4);
		return;
	  case 3:
		pA = (uint)R3 %(uint)R4;
		pB = (uint)R3 /(uint)R4;
		return;
	}
}


AlwaysInline void BFLS (Register* r, ASM Op) { // rrxxbbb --> rr00bbb
	auto o = i2; // we want to clear those middle bits
	int up = BFLD_upu;
	int down = BFLD_downu;
	uint64 mask = -1;
	mask <<= up; mask >>= down;
	
	auto i = o << up;
	if (BFLD_Lu) 
		i = i >> down;
	  else 
		i = (uint64)i >> down;
	i2 = (o&mask) | i;
}


AlwaysInline void RotateConst (Register* r, ASM Op) {
	int64 A = JB_u64_RotL(Const_Valueu, Const_Rotu);
	if (Const_Invu)
		A = ~A;
	i1 = A;
}


float FloatIncr1 (ASM Op) {
    uint f = (FloatConst_Highu << 19);
    return reinterpret_cast<float&>(f);
}

float FloatSh1 (uint64 u, int S) {
	uint64 Exp = u + (S << 24); // don't do any error-checking :) overflows according to exactly this definition.
	return reinterpret_cast<float&>(Exp);
}

double FloatSh2 (uint64 u, int S) {
	uint64 Exp = u + ((uint64)S << 53);
	return reinterpret_cast<double&>(Exp);
}


AlwaysInline ASM* LoadConst (Register* r, ASM Op, ASM* Code) {
	uint64 Value = ConstStretchy_Valueu;
	int Remain = (Op>>24)&3;
	r+=n1;
	if (Remain) {
		if (Remain == 1)
			Value <<= 32; 
		  else
			// we already just read 64-bits now. so just discard the previous 16 bits
			Value = (uint64)(*Code++) << 32;
		Value |= *Code++;
	}
	if (!ConstStretchy_Condu or !r->Int) {
		if (ConstStretchy_Invu)
			Value = ~Value;
		r->Int = Value;
	}
	return Code; 
}

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
		s64 R3 = u3 + Const_Rotu;
		return JB_u32_RotL((u32)R2, (u32)R3);
	}
	return 0;
}


#define incr(o)				JB_Incr((JB_Object*)o)
#define freeifdead(o)		JB_FreeIfDead((JB_Object*)o)
#define decr(o)				JB_Decr((JB_Object*)o)
#define safedecr(o)			JB_SafeDecr((JB_Object*)o)
#define setref(t, a, b)		{if (t) JB_SetRef(a,b); else incr(b);}  
#define table(b)			((u64)(((void**)(&vm.Env))[b])+L2)  

#define mem(t)				((t*)u2)[I3+Read_Lu]
#define mem2(t)				(u2 = (u64)((t*)u2 + Read_moveu-1))

AlwaysInline JB_Object* alloc(void* o) {
	// we need a class table, and look it up from there.
	// we don't have dynamicly created classes anyhow...
	return JB_AllocNew(((JB_MemoryLayer*)o)->CurrBlock);
}


AlwaysInline void RegConv (Register* r, int Conv, int Op) {
	// float, double, u64, s64. 12 conversions possible (and 4 pointless ones)
	Register* s = r + n3;
	Register* d = r + n1;
		
    switch (Conv) {
        case 0 : d->Float  = s->Float; 		break; // just copies
        case 1 : d->Float  = s->Double;		break;
        case 2 : d->Float  = s->Uint;  		break;
/**/    case 3 : d->Float  = s->Int;   		break;
		case 4 : d->Double = s->Float; 		break;
        case 5 : d->Double = s->Double;		break; // just copies
        case 6 : d->Double = s->Uint;  		break;
/**/    case 7 : d->Double = s->Int;   		break;
	    case 8 : d->Uint   = s->Float; 		break;
        case 9 : d->Uint   = s->Double;		break;
        case 10: d->Uint   = s->Uint;  		break; // just copies
/**/    case 11: d->Uint   = s->Int;   		break;
        case 12: d->Int    = s->Float; 		break;
        case 13: d->Int    = s->Double;		break;
        case 14: d->Int    = s->Uint;  		break;
/**/    case 15: d->Int    = s->Int;   		break; // just copies
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



#define  DA  *((double*)A)
#define  DB  *((double*)B)
#define  FA  *((float*)A)
#define  FB  *((float*)B)

#define  UA  *((u64*)A)
#define  UB  *((u64*)B)
#define  iA  *((int*)A)
#define  iB  *((int*)B)
#define  uA  *((uint*)A)
#define  uB  *((uint*)B)

#define CmpSub(Mode, Cmp) case Mode: return (Cmp);


bool CompI_ (Register* r, ASM Op) {
	auto A = &i1;
	auto B = &i2;
	switch (Cmp_Cmpu) {
		CmpSub(0 , iA > iB);
		CmpSub(1 , iA < iB);
		CmpSub(2,  uA > uB);
		CmpSub(3,  uA < uB);

		CmpSub(4 ,  A >  B);
		CmpSub(5 ,  A <  B);
		CmpSub(6,  UA > UB); default:;
		CmpSub(7,  UA < UB);
	};
}

bool CompF_ (Register* r, ASM Op) {
	auto A = &i1;
	auto B = &i2;

	switch (Cmp_Cmpu) {
		CmpSub(0 , FA >  FB);
		CmpSub(1 , FA <  FB);
		CmpSub(2 , FA == FB);
		CmpSub(3 , FA != FB);
		
		CmpSub(4 , FA >  DB);
		CmpSub(5 , FA <  DB);
		CmpSub(6 , FA == DB);
		CmpSub(7 , FA != DB);
		
		CmpSub(8 , DA >  FB);
		CmpSub(9 , DA <  FB);
		CmpSub(10, DA == FB);
		CmpSub(11, DA != FB);
		
		CmpSub(12, DA >  DB);
		CmpSub(13, DA <  DB);
		CmpSub(14, DA == DB); default:
		CmpSub(15, DA != DB);
	};
}



AlwaysInline ASM* JompI (Register* r, ASM Op, ASM* Code) {
	return Code + Cmp_Lu*CompI_(r, Op);
}

AlwaysInline ASM* JompF (Register* r, ASM Op, ASM* Code) {
	return Code + Cmp_Lu*CompF_(r, Op);
}
		
AlwaysInline void CompI (Register* r, ASM Op) {
	r[Cmp_Lu].Int = CompI_(r, Op);
}

AlwaysInline void CompF (Register* r, ASM Op) {
	r[Cmp_Lu].Int = CompF_(r, Op);
}


AlwaysInline uint64 BitComp (Register* r, ASM Op) { // cmpb
	auto i = CmpB_Invu;
	auto A = u2;
	auto B = u3;
	if (i&2)	// do we even need these? just remove?
		A = ~A;
	if (i&4)	// seems like we should remove these...
		B = ~B;
	return (A==B) xor (i&1); // keep this though...
	// the first two could be "future upgrades"...?
}


AlwaysInline void BitClear (Register* r, ASM Op) {
	auto i = BClear_Signu;
	uint S1 = BClear_Shift1u;
	uint S2 = BClear_Shift2u;
	if (i&1)
		i1 = (i1 << S1)>>S1;
	  else
		u1 = (u1 << S1)>>S1;
	if (i&2)
		i2 = (i2 << S2)>>S2;
	  else
		u2 = (u2 << S2)>>S2;
}


AlwaysInline ASM* JompEq (Register* r, ASM Op, ASM* Code) {
	if (u1 == u2)
		return Code;
	return Code + JCmpEq_Jmpi;
}


AlwaysInline ASM* JompNeq (Register* r, ASM Op, ASM* Code) {
	if (u1 != u2)
		return Code;
	return Code + JCmpEq_Jmpi;
}

#define shu(x) ((((x)<<Shift_Shu))>>Shift_Shu)

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

			
AlwaysInline void CountConst (Register* r, ASM Op, bool UseOld) {
	int Size = CNTC_sizeu;
	int Off  = CNTC_offsetu;
	int Add  = CNTC_cnsti;
	auto PP = p1(u8);
	PP += Off << Size;
	uint64 Old = 0;
	uint64 New = 0;
	auto ni = n2;
	if (!ni) ni = 32; // just write past the end.
	auto Where = &(r[ni].Uint);

	switch (Size) {
	case 0:
		Old = *PP;         New = Old+Add;
		*PP = New;
		break;
	case 1:
		Old = *((u16*)PP); New = Old+Add;
		*((u16*)PP) = New;
		break;
	case 2:
		Old = *((u32*)PP); New = Old+Add;
		*((u32*)PP) = (u32)(New);
		break;
	default:
	case 3:
		Old = *((u64*)PP); New = Old+Add;
		*((u64*)PP) = New;
		break;
	}
	if (UseOld)
		*Where = Old;
	  else
		*Where = New;
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
//	if (S.Incr)
//		incr(Result.Obj);
	int More = RET_Countu;
	while (More -->= 0) {
		To[++S.Regs] = Result;
		Result = *From++;
	}
		
	return Code;
}


#define Transfer(Input,Shift)  (r[((Input)>>((Shift)*5))&31])
#define Transfer3(num)         case num: ENTR[num] = Transfer(Code, num)


AlwaysInline void AllocStack (jb_vm& vm, Register* r, ASM Op) {
	debugger; // do this later. We we need a separate stack for these?
	uint BEEETS = Alloc_Alignu;
	uint Align = 1 << BEEETS;
	int Amount = Alloc_Amounti << BEEETS;
	auto B = vm.StructAllocator;
	r[n1].Int = (uint64)(B);
	if (Amount > 0) {
		auto Up = (-((uint64)B) & (Align-1));
		B += Up+Amount;
	} else {
		debugger; // We need to de-align after
		B -= Amount;
		B -= (-((uint64)B) & (Align-1));
	}
	vm.StructAllocator = B;
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


// The linker can do the conversions or deciding which functions to upgrade, not the ASM!
// ideally the compiler should, right? I mean... with one compiler and one distribution
// theres one answer.

AlwaysInline ASM* BumpStack (Register*& rp, ASM* CodePtr, ASM Op, ASM Code2) { // jumpstack
	Register* r = rp;
	u64 Code = *CodePtr++;
	int Save = n1;
	Register* ENTR = r+Save+1;
	ENTR->Stack.Addr = CodePtr;
	ENTR->Stack.Regs = Save;
//	ENTR->Stack.Incr = Func_Incru;

	rp = r = ++ENTR;
	switch (Code&15) {
	Transfer3(11);
	Transfer3(10);
	Transfer3( 9);
	Transfer3( 8);
	Transfer3( 7);
	Transfer3( 6);
	Transfer3( 5);
	Transfer3( 4);
	Transfer3( 3);
	Transfer3( 2);
	Transfer3( 1);
	default:
	case  0: ENTR[ 0] = {};
	debugger; 
	}
	
	int j = Func_JUMPi;
	return CodePtr + j;
}

/*
	int				4579	// Almost entirely int
	float			122 	// We could make a pure float version
	float/int		35		// Only 35 float/ints need ffiing
	vector			98		// SIMD we will look at later. Are they considered structs? or just not supported?
	vector/in		74
	vector/float	28
                               0:410   1:2066,  2:3530,  3:4243,  4:4410,  5:4471,  6:4481,  7:4485
Speedie's function histogram:  0:410,  1:1656,  2:1464,  3: 713,  4: 167,  5:  61,  6:  10,  7:   4
*/


#define q1  r[(a<< 5)>>27].Uint
#define q2  r[(a<<10)>>22].Uint
#define q3  r[(a<<15)>>17].Uint
#define q4  r[(a<<20)>>12].Uint
#define q5  r[(a<<25)>> 7].Uint
#define q6  r[(b<< 0)>>27].Uint
#define q7  r[(b<< 5)>>22].Uint
#define q8  r[(b<<10)>>17].Uint
#define q9  r[(b<<15)>>12].Uint
#define q10 r[(b<<20)>> 7].Uint
#define q11 r[(b<<25)>> 2].Uint
#define FFISub(Mode, FP)	case 11-Mode:	V = ((Fn##Mode)Fn)FP; break


AlwaysInline ASM* ForeignFunc (jb_vm& vm, ASM* CodePtr, ASM Op) {
	ASM a = CodePtr[0];
	ASM b = CodePtr[1];
	auto Mode = ForeignFunc_Fastu;
	ASM PrmCount = Op&15;
	auto T = ForeignFunc_Tableu;
	auto &r = vm.Registers;
	auto Fn = (T<32) ? ((Fn0)(r[T].Uint)) : (vm.Env.Cpp[T]) ;

	if (!Mode) {
//
//		ffi_cif cif;
//		ffi_type *args[1];
//		void *values[1];
//		char *s;
//		ffi_arg rc;
//		/* Initialize the argument info vectors */
//		args[0] = &ffi_type_pointer;
//		values[0] = &s;
//		/* Initialize the cif */
//		if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, 1,
//						 &ffi_type_sint, args) == FFI_OK)
//		{
//			s = "Hello World!";
//			ffi_call(&cif, (FFI_Fn)puts, &rc, values);
//			/* rc now holds the result of the call to puts */
//			/* values holds a pointer to the function’s arg, so to
//			 call puts() again all we need to do is change the
//			 value of s */
//			s = "This is cool!";
//			ffi_call(&cif, (FFI_Fn)puts, &rc, values);
//		}
//		;
	}
	// our format is unnecessary if they are all the same type! otherwise we need format info.
	// how do we cache the ffi type info? Arbitrarily? we need to collect it somewhere in the ASM.
	if (Mode == 1) {
		uint64 V; //     Could do float, double, vec4, ivec4, etc... too
		switch (PrmCount) {
		default:
			// hopefully this just becomes a jump-table... :3
			FFISub(11, (q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11));
			FFISub(10, (q1, q2, q3, q4, q5, q6, q7, q8, q9, q10));
			FFISub(9 , (q1, q2, q3, q4, q5, q6, q7, q8, q9));
			FFISub(8 , (q1, q2, q3, q4, q5, q6, q7, q8));
			FFISub(7 , (q1, q2, q3, q4, q5, q6, q7));
			FFISub(6 , (q1, q2, q3, q4, q5, q6));
			FFISub(5 , (q1, q2, q3, q4, q5));
			FFISub(4 , (q1, q2, q3, q4));
			FFISub(3 , (q1, q2, q3));
			FFISub(2 , (q1, q2));
			FFISub(1 , (q1));
			FFISub(0 , ());
		};
	
		vm.Registers[n1].Int = V;
	}

	return CodePtr;
}


	// I think calling the VM should be a simple-task. So instead of calling a function-pointer...
	// we test the function pointer, to see if its SPD or C. If C... we call it. Otherwise we call the VM.
	// this has to be done at every call-site. What about for passing to C++ libs? We'd have to generate
	// some native ASM for that. I think C++ has lambdas. It could be done.
