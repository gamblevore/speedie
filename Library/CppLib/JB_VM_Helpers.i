


#include <utility>
#if !__has_builtin(__builtin_unreachable)
	#define __builtin_unreachable()
#endif


extern "C" {
// need to allow vectorcall on windows. to allow vectors to be passed
// using the SIMD registers.
typedef void (*FFI_Fn)(void);
extern "C" pid_t getpid(void);
static ivec4* CakeCrashedSub (CakeVM* V, int ErrorKind, VMStack* Stack, int Signal);
static ivec4* CakeCrashed (CakeVM* V, int Signal);


AlwaysInline int64 Div2 (int64 V, int Clear, int Down) {
	int64 Sign = V < 0;
	Sign = (Sign << Down) - Sign;
	V = (V << Clear) >> Clear;
	return (V + Sign) >> Down;
}

AlwaysInline void DivMath(VMRegister* r, ASM Op) {
	auto R3 = i3;
	auto R4 = i4;
	uint A = n1;
	uint B = n2;
	
	if (Div_Kindu) {
		if (A) // on ARM, % does not come for free along with  /
			   // so its better not to do % unless we explicitly need it.
			r[A].Int = R3 / R4;
		if (B)
			r[B].Int = R3 % R4;
	} else {
		if (A)
			r[A].Int = (u64)R3 / (u64)R4;
		if (B)
			r[B].Int = (u64)R3 % (u64)R4;
	}
}


AlwaysInline void DivMath32(VMRegister* r, ASM Op) {
	auto R3 = i3;
	auto R4 = i4;
	uint A = n1;
	uint B = n2;
	
	if (Div_Kindu) {
		if (A)
			r[A].Int = (int64)((int)R3 / (int)R4);
		if (B)
			r[B].Int = (int64)((int)R3 % (int)R4);
	} else {
		if (A)
			r[A].Int = (uint64)((uint)R3 /(uint)R4);
		if (B)
			r[B].Int = (uint64)((uint)R3 %(uint)R4);
	}
}


AlwaysInline void BFLS (VMRegister* r, ASM Op) { // rrxxbbb --> rr00bbb
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

inline u64 JB_u64_RotR (u64 x, u64 N) {
	return (x >> N) | (x << (64-N));
}

AlwaysInline void RotateConst (VMRegister* r, ASM Op) {
	auto V = RotateConst_Valueu; auto R = RotateConst_Rotu;
	uint64 A = JB_u64_RotR(V, R);
	if (RotateConst_Invu)
		A = ~A;
	u1 = A;
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



AlwaysInline void LoadConst (VMRegister* r, ASM Op, uint64 Value) {
	int N = n1;
	if (!ConstStretchy_Condu or !r[N].Int) {
		Value <<= 17;
		Value |= ((uint64)ConstStretchy_Valueu);
		if (ConstStretchy_Invu)
			Value = ~Value;
		r[N].Int = Value;
	}
}


AlwaysInline u64 bitstats(u64 R2, u64 Mode) {
					// popcount //
	if (Mode == 0)
		return __builtin_popcountll(R2); 
	if (Mode == 1)
		return __builtin_popcount((u32)R2); 
		
					// msb //
	if (Mode == 2)
		return JB_u64_Log2(R2);
	if (Mode == 3)
		return (uint)JB_Int_Log2((u32)R2);
	
				// byte_swap //
	if (Mode == 4)
		return __builtin_bswap64(R2);
	if (Mode == 5)
		return (uint)__builtin_bswap32((u32)R2);
	return 0;
}


///


AlwaysInline vec4 VBuild (VMRegister* r, ASM Op) {
	return vec4{f2, f3, f4, f5};
}


AlwaysInline vec4 VBuild2 (VMRegister* r, ASM Op) {
	auto F = f2;
	uint Bits = Alloc_Amountu; 
	return vec4{
		F * ((Bits>>0)&1),
		F * ((Bits>>1)&1),
		F * ((Bits>>2)&1),
		F * ((Bits>>3)&1)
	};
}


AlwaysInline vec4 VSwiz (VMRegister* r, ASM Op) {
	auto Input = v2;
	vec4 Output;
	auto F = VecSwizzle_Fieldsu;
	Output[0] = Input[(F>>0)&2]*((F>>2 )&1);
	Output[1] = Input[(F>>3)&2]*((F>>5 )&1);
	Output[2] = Input[(F>>6)&2]*((F>>8 )&1);
	Output[3] = Input[(F>>9)&2]*((F>>11)&1);
	return Output;
}

///



#define incr(o)					JB_Incr((JB_Object*)o)
#define freeifdead(o)			JB_FreeIfDead((JB_Object*)o)
#define decr(o)					JB_Decr((JB_Object*)o)
#define safedecr(o)				JB_SafeDecr((JB_Object*)o)



AlwaysInline void SetRefRegToMem(VMRegister* r, ASM Op) {
	auto New = o2;				 						// reg
	auto pOld = ((JB_Object**)(u1))+RefSet2_Offsetu;	// mem
	auto Old = *pOld;
	
	*pOld = JB_Incr(New);
	if (RefSet2_Decru)
		JB_Decr(Old);
}


AlwaysInline void SetRefMemToReg(VMRegister* r, ASM Op) {
	auto pNew = ((JB_Object**)(u2))+RefSet2_Offsetu;
	auto New = *pNew;									// mem
	auto Old = o1;				 						// reg
	
	o1 = JB_Incr(New);
	if (RefSet2_Decru)
		JB_Decr(Old);
}


AlwaysInline void SetRefDecrMem(VMRegister* r, ASM Op) {
	auto Where = ((JB_Object**)(u1))+RefDecrMem_Offsetu;	// mem
	int n = RefDecrMem_Countu;
	for (int i = 0;  i <= n;  i++) {
		JB_Decr(*Where++);
	} 
}


AlwaysInline void SetRefBasic(VMRegister* r, ASM Op) {
	int out = n1;
	int in = n2;
	auto B = r[in].Obj;
	JB_Incr(B);
	if (out) {
		auto A = r[out].Obj;
		r[out].Obj = B;
		JB_Decr(A);
	}
}


AlwaysInline void SetRefApart (VMRegister* r, ASM Op) {
	JB_Incr(o3);
	JB_SafeDecr(o2);
	JB_FreeIfDead(o1);
}



#define mem0(t)				({ (u2) ? ((t*)u2)[u3+Read_Offsetu-1] : 0; }) // safely read.
#define mem1(t)				((t*)u2)[u3+Read_Offsetu-1]
#define mem2(t)				(u2 = (u64)((t*)u2 + Read_movei))


AlwaysInline JB_Object* alloc(void* o) {
	// we need a class table, and look it up from there.
	// we don't have dynamicly created classes anyhow...
	return JB_AllocNew(((JB_MemoryLayer*)o)->CurrBlock);
}

u64 gtable (CakeVM& vm, ASM Op) {
	auto Where = GTable_Modeu?vm.LibGlobs:vm.PackGlobs;
	auto Add = GTable_Addu;
	return (u64)(Where+Add);
}


JB_Object* gobj (CakeVM& vm, ASM Op) {
	auto Where = GObj_Modeu?vm.LibGlobs:vm.PackGlobs;
	auto Str = ((JB_Object**)(Where))[GObj_Addu];
	if (GObj_Refu)
		JB_Incr(Str);
	return Str;
}

AlwaysInline void VecConv (VMRegister* r, ASM Op) {
	// vec/ivec conversions
	auto s = r + n2;
	auto d = r + n1;

    if (Convert_Modeu) {
        d->Vec  = (vec4)(s->Ivec);
	} else {
		d->Ivec   = (ivec4)(s->Vec);
    }
}


AlwaysInline void RegConv (VMRegister* r, ASM Op) {
	// float, double, u64, s64. 12 conversions possible (and 6 pointless ones)
	auto s = r + n2;
	auto d = r + n1;

    switch (Convert_Modeu) {
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
/**/    case 11: d->Uint   = s->Int;   		break; // actually pointless
        case 12: d->Int    = s->Float; 		break;
        case 13: d->Int    = s->Double;		break;
        case 14: d->Int    = s->Uint;  		break; // actually pointless
/**/    case 15: d->Int    = s->Int;   		break; // just copies
		default:
		__builtin_unreachable();
    }
//    d = d;
//    s = s;
}

AlwaysInline void Time_ (VMRegister* r, ASM Op) {
	auto r1 = i1;
	auto r2 = n2;
	if (r2 == 1) {		// time
		r[r1].Uint = RDTSC();
	} else if (r2 == 2) {
		JB_Date__Sleep(1);
	} else if (r2 == 3) {
		printf("%lli\n", r1);
	}
}



#define  DA  *((double*)A)
#define  DB  *((double*)B)
#define  FA  *((float* )A)
#define  FB  *((float* )B)

#define  UA  *((u64* )A)
#define  UB  *((u64* )B)
#define  iA  *((int* )A)
#define  iB  *((int* )B)
#define  uA  *((uint*)A)
#define  uB  *((uint*)B)

#define CmpSub(Mode, Cmp) case Mode: return (Cmp);


bool CompI_ (int64 A, int64 B, uint Mode) {
	switch (Mode) {
		CmpSub(0,  (int64) A  >  (int64)B );
		CmpSub(1,  (int64) A  <= (int64)B );
		CmpSub(2,    (u64) A  >  (u64)  B );
		CmpSub(3,    (u64) A  <= (u64)  B );
		
		CmpSub(4,    (int) A  >  (int64)B );
		CmpSub(5,    (int) A  <= (int64)B );
		CmpSub(6,    (uint)A  >  (u64)  B );
		CmpSub(7,    (uint)A  <= (u64)  B );
		
		CmpSub(8,  (int64) A  >  (int)  B );
		CmpSub(9,  (int64) A  <= (int)  B );
		CmpSub(10,   (u64) A  >  (uint) B );
		CmpSub(11,   (u64) A  <= (uint) B );
		
		CmpSub(12,   (int) A  >   (int) B );
		CmpSub(13,   (int) A  <=  (int) B );
		CmpSub(14,   (uint)A  >  (uint) B );
		CmpSub(15,   (uint)A  <= (uint) B );
		default:
		__builtin_unreachable();
	};
}


bool CompF_ (VMRegister* A, VMRegister* B, uint Mode) {
	switch (Mode) {
		CmpSub(0 , FA >  FB);
		CmpSub(1 , FA <= FB);
		CmpSub(2 , FA == FB);
		CmpSub(3 , FA != FB);
		
		CmpSub(4, DA >  DB);
		CmpSub(5, DA <= DB);
		CmpSub(6, DA == DB);
		CmpSub(7, DA != DB);
		default:
		__builtin_unreachable();
	};
}



AlwaysInline ASM* JumpI (VMRegister* r, ASM Op, ASM* Code) {
	auto V = CompI_(i1, i2, JCmpI_Cmpu);
	return Code + V*JCmpI_Jmpi;
}

AlwaysInline void CompI (VMRegister* r, ASM Op) {
	auto V = CompI_(i2, i3, CmpI_Cmpu);
	i1 = V;
}

//	JCmpF
//		r1		r
//		r2		r
//		Cmp		3
//		Jmp		j


AlwaysInline ASM* JumpF (VMRegister* r, ASM Op, ASM* Code) {
	auto V = CompF_(r+n1, r+n2, JCmpF_Cmpu);
	return Code + V*JCmpF_Jmpi;
}

AlwaysInline void CompF (VMRegister* r, ASM Op) {
	i1 = CompF_(r+n2, r+n3, CmpF_Cmpu);
}


inline uint64 clip (uint64 x, uint64 s) {
	s = 64 - (1<<s);
	return (x << s) >> s;
}


AlwaysInline uint64 BitComp (VMRegister* r, ASM Op) {
	auto i = CmpI_Cmpu;
	auto A = clip(u2, (i >> 1)&7);
	auto B = clip(u3, (i >> 4)&7);
	return (A!=B) xor (i&1);
}


inline uint64 jclip (uint64 x, uint64 s) {
	return (x << s) >> s;
}

AlwaysInline ASM* JumpEq (VMRegister* r, ASM Op, ASM* Code) {
	auto V = jclip(u1, JCmpEq_LSmallu<<5) == jclip(u2, JCmpEq_RSmallu<<5);
	return Code + V*JCmpEq_Jmpi;
}

AlwaysInline ASM* JumpNeq (VMRegister* r, ASM Op, ASM* Code) {
	auto V = jclip(u1, JCmpEq_LSmallu<<5) != jclip(u2, JCmpEq_RSmallu<<5);
	return Code + V*JCmpEq_Jmpi;
}

AlwaysInline ASM* JumpK (VMRegister* r, ASM Op, ASM* Code) {
	auto K = JCmpK_Ki;
	auto J = JCmpK_Jmpi * (ii1 > K);
	return Code + J;
}

AlwaysInline ASM* JumpKN (VMRegister* r, ASM Op, ASM* Code) {
	auto K = JCmpK_Ki;
	auto J = JCmpK_Jmpi * (ii1 <= K);
	return Code + J;
}

AlwaysInline ASM* JumpKE (VMRegister* r, ASM Op, ASM* Code) {
	auto K = JCmpK_Ki;
	auto J = JCmpK_Jmpi * (ii1 == K);
	return Code + J;
}

AlwaysInline ASM* JumpKNE (VMRegister* r, ASM Op, ASM* Code) {
	auto K = JCmpK_Ki;
	auto J = JCmpK_Jmpi * (ii1 != K);
	return Code + J;
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
	L++;
	if (Operation == 0 or 1)
		std::fill(A, A+L, -Operation);
	  else if (Operation == 2)
		memcpy(A, B, L);
	  else if (Operation == 3)
		bswap32(A, L);
	  else if (Operation == 4)
		bswap64((u64*)A, L);
}


AlwaysInline void MemCopyRDWR (VMRegister* r, ASM Op) {
	byte* d = (byte*)u2;
	uint s = n1;
	uint n = MemoryCopy_Lengthu;
	n |= (!n)<<14; // 0 means 1<<14. Would microcode easier than +1? Simple bit ops no math.
	if (s) {
		memcpy(d, r[s].Obj, n);
	} else { // copying from r0 means zero.
		memset(d, 0, n);
	}
}
 
AlwaysInline void IncrementAddr (VMRegister* r, ASM Op, bool UseOld) {
	int Size = CNTC_sizeu;
	int Off  = (int)(CNTC_offsetu);
	int Add  = CNTC_cnsti;
	auto PP = (uint*)(p2(u8) + (Off << Size));
	auto ni = n1;
	auto Result = &(r[ni].Uint);
	uint64 Old;
	uint64 New;
	switch (Size) {
	case 0:
		Old = *((u8* )PP); New = Old+Add;
		*((u8* )PP) = New;
		break;
	case 1:
		Old = *((u16*)PP); New = Old+Add;
		*((u16*)PP) = New;
		break;
	case 2:
		Old = *((u32*)PP); New = Old+Add;
		*((u32*)PP) = (u32)(New);
		break;
	case 3:
		Old = *((u64*)PP); New = Old+Add;
		*((u64*)PP) = New;
		break;
	default:
		__builtin_unreachable();
	}
	if (ni)
		*Result = UseOld?Old:New;
}



// r0(1), <stack/result>, <r0> (2)...<r31>

AlwaysInline ASM* RestoreStack (CakeVM& vm, VMRegister*& R0, ASM Op, ASM* DebugCode) {
	(DebugCode);
	auto Stack	= (VMStack*)(R0 - 1);
	int StepBack= Stack->DestReg;
	auto Imm	= RET_Valuei;					// get before copy!
	auto Src	= R0 + n1;
	
	*((VMRegister*)Stack) = *Src;
	((VMRegister*)Stack)->Uint |= Imm;			// immediate
	
	auto NewR0 = (VMRegister*)(Stack-StepBack);
	R0			= NewR0;						// NewZero
	Stack		= (VMStack*)(NewR0 - 1);
//	vm.CurrStack = Stack;
	auto Code	= Stack->Code;
	Stack->GoUp = 0;
//	*R0			= {};							// unnecessary?
	
	return Code;
}


AlwaysInline ASM* DeRefRegs (CakeVM& vm, VMRegister*& r, ASM Op) {
	if (n4)
		JB_Decr(o4);
	if (n3)
		JB_Decr(o3);
	if (n2)
		JB_Decr(o2);
	if (n1)
		JB_SafeDecr(o1);
	return RestoreStack(vm, r, (Op>>19)<<19, 0);
}


#define Transfer(Input,Shift)  (r[((Input)>>((Shift)*5))&31])
#define Transfer3(num)         case num: Zero[num] = Transfer(Code, num)


AlwaysInline void AllocStack (CakeVM& vm, VMRegister* r, ASM Op) {
	debugger; // do this later. We we need a separate stack for these?
	int Amount = Alloc_Amounti << 4;
	auto B = vm.AllocBase;
	int n = n1;
	if (n)
		r[n].Int = (uint64)(B);
	if (Amount > 0) {
		memzero(B, Amount);
		B += Amount;
	} else {
		debugger;
		B -= Amount;
	}
	vm.AllocBase = B;
}


AlwaysInline ASM* TailStack (CakeVM& vm, VMRegister* r, ASM* Code, ASM Op) {
	VMRegister* stck = r-1;
	debugger;
//	vm.AllocCurr = stck->Stack.Alloc;
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




//	HaltStack.DestReg = 1;
//	HaltStack.Alloc = 0;
//	HaltStack.Depth = 1;
//	HaltStack.GoUp = 0;
//	HaltStack.Code = VMCodePtr(&V) + CakeCodeMax-1;
//
//	auto Code = VMProtect(V, true) + CodeIndex;
//	MainStack.DestReg = 1;
//	MainStack.Alloc = 0;
//	MainStack.Depth = 1;
//	MainStack.GoUp = 0;
//	MainStack.Code = Code;

AlwaysInline ASM* BumpStack (CakeVM& vm, VMRegister*& rp, ASM* CodePtr, ASM Op, u64 Code) {	// jumpstack
	auto r = rp;
	int Dest = n1;
	VMStack* NewStack = &((r + Dest)->Stack);
	{
		auto End = (VMStack*)(((byte*)(&vm)) + CakeStackSize-1024);
		auto OldStack = (VMStack*)(r-1);
		if_rare (NewStack >= End) {			// stackoverflow
			CakeCrashedSub(&vm, kOverFlowStack, OldStack, SIGSEGV);
			vm.Registers[2] = {.Int = errno}; // clear stack. its gone. And we already reported it.
			return VMCodePtr(&vm)+CakeCodeMax-1;
		}
		
		OldStack->GoUp = Dest;
		NewStack->Depth = OldStack->Depth+1;
		OldStack->Code = CodePtr;
	}
	NewStack->DestReg = Dest;
	NewStack->GoUp = 0;
//	NewStack->Alloc = vm.AllocCurr;
//	vm.CurrStack = NewStack;
	auto Zero = ((VMRegister*)NewStack)+1;
	rp = Zero;
	CodePtr += Func_JUMPi;
	NewStack->Code = CodePtr;

	switch ( Code&15 ) {
		default: __builtin_unreachable();
		Transfer3( 8);
		Transfer3( 7);
		Transfer3( 6);
		Transfer3( 5);
		Transfer3( 4);
		Transfer3( 3);
		Transfer3( 2);
		Transfer3( 1);
		case 0:;
	}

	Zero[ 0] = {};
	return CodePtr;
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
#define FFISub(Mode, FP)	case 8-Mode:	V = ((Fn##Mode)Fn)FP; break

#define Code64 (*(u64*)Code)



extern "C"  __attribute__((sysv_abi))   void  __CAKE_BRIDGE__ (u64 data, Fn0 fn, VMRegister* r, int64 n);

AlwaysInline int64 FuncAddr (CakeVM& vv, ASM Op, ASM* Code) {
	if (FuncAddr_Libraryu)
		return (int64)(vv.CppFuncs[FuncAddr_Indexu]);
	return (int64)(Code+FuncAddr_Indexi);
}


AlwaysInline void ForeignFunc (CakeVM& vv, ASM* CodePtr, VMRegister* r, ASM Op, u64 funcdata) {
	auto T = ForeignFunc_Tableu;
//	printf("T: %i\n", T);
	auto fn = (T<32) ? ((Fn0)(r[T].Uint)) : (vv.CppFuncs[T]);
	return __CAKE_BRIDGE__(funcdata, fn, r, n1);
}


AlwaysInline ivec4 QMax (ivec4 A, ivec4 B) {
	return {
		std::max(A[0], B[0]),
		std::max(A[1], B[1]),
		std::max(A[2], B[2]),
		std::max(A[3], B[3])
	};
}

AlwaysInline ivec4 QMin (ivec4 A, ivec4 B) {
	return {
		std::min(A[0], B[0]),
		std::min(A[1], B[1]),
		std::min(A[2], B[2]),
		std::min(A[3], B[3])
	};
}

AlwaysInline void QInc (VMRegister* r, ASM Op) {
	int i = VecInc_partu;
	auto V = iv2;
	auto N = V[i] + VecInc_Amounti;
	V[i] = N;
	if (n1)
		i1 = N;
}

}


