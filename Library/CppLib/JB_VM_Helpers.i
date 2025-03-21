

#include <dlfcn.h>

// need to allow vectorcall on windows. to allow vectors to be passed
// using the SIMD registers.
typedef void (*FFI_Fn)(void);


// find app's own functions within itself...
extern "C" void* JB_ASM__Load (JB_StringC* S) {
    static void* MySelf;
    if (!MySelf) {
		MySelf = dlopen(0, RTLD_LAZY);
//		MySelf = dlopen("/usr/local/speedie/Terminal/Speedie", RTLD_LAZY);
		if (!MySelf) return 0;
	}
	void* R = dlsym(MySelf, (const char*)(S->Addr));
	if (!R) {
//		debugger;
		printf("// fn! %s\n", S->Addr);
	} else {
//		printf("// got %s\n", S->Addr);
	}
	return R;
}


AlwaysInline void DivMath(VMRegister* r, ASM Op) {
	auto R3 = i3;
	auto R4 = i4;
	uint A = n1;
	uint B = n2;
	
	switch (Div_Kindu & 3) { // so there are 4 possible divisions we can do
	  case 0:
		if (A) // on ARM, % does not come for free along with  /
			   // so its better not to do % unless we explicitly need it.
			r[A].Int = R3 / R4;
		if (B)
			r[B].Int = R3 % R4;
		return;
	  case 1:
		if (A)
			r[A].Int = (u64)R3 / (u64)R4;
		if (B)
			r[B].Int = (u64)R3 % (u64)R4;
		return;
	  case 2:
		if (A)
			r[A].Int = (int64)((int)R3 / (int)R4);
		if (B)
			r[B].Int = (int64)((int)R3 % (int)R4);
		return;
	  case 3:
		if (A)
			r[A].Int = (uint)R3 /(uint)R4;
		if (B)
			r[B].Int = (uint)R3 %(uint)R4;
		return;
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



AlwaysInline void LoadGConst (VMRegister* r, ASM Op, int64 Value) {
	Value = (Value << 32) >> 13;
	Value |= ConstGlobal_Valueu;
	r[n1].Int = Value;
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


AlwaysInline void SetRefApart(VMRegister* r, ASM Op) {
	JB_Incr(o3);
	JB_SafeDecr(o2);
	JB_FreeIfDead(o1);
}



#define mem0(t)				({ (u2) ? ((t*)u2)[u3+Read_Offsetu] : 0; }) // safely read.
#define mem1(t)				((t*)u2)[u3+Read_Offsetu]
#define mem2(t)				(u2 = (u64)((t*)u2 - Read_movei))

AlwaysInline JB_Object* alloc(void* o) {
	// we need a class table, and look it up from there.
	// we don't have dynamicly created classes anyhow...
	return JB_AllocNew(((JB_MemoryLayer*)o)->CurrBlock);
}

u64 table (jb_vm& vm, ASM Op) {
	if (Table_Modeu)
		return (u64)(vm.Env.LibGlobs+Table_Addu);
	return (u64)(vm.Env.PackGlobs+Table_Addu);
}


JB_Object* strs (jb_vm& vm, ASM Op) {
	auto Str = vm.Env.PackStrs[Table_Addu];
	if (Table_Modeu)
		JB_Incr(Str);
	return Str;
}


AlwaysInline void RegConv (VMRegister* r, ASM Op) {
	// float, double, u64, s64. 12 conversions possible (and 4 pointless ones)
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
/**/    case 11: d->Uint   = s->Int;   		break;
        case 12: d->Int    = s->Float; 		break;
        case 13: d->Int    = s->Double;		break;
        case 14: d->Int    = s->Uint;  		break;
/**/    case 15: d->Int    = s->Int;   		break; // just copies
    }
    d = d;
    s = s;
}

AlwaysInline void Rare_ (VMRegister* r, ASM Op) {
	auto r1 = i1;
	auto r2 = i2;
	if (r2 == 1) {		// time
		r[r1].Uint = RDTSC();
	} else if (r2 == 2) {
		JB_Date__Sleep(1);
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


bool CompI_ (VMRegister* r, ASM Op) {
	auto A = i1;
	auto B = i2;
	switch (JCmpI_Cmpu) {
		CmpSub(0,  A >   B);
		CmpSub(1,  A <=  B);
		CmpSub(2,  A ==  B);			// seems like these 4 should come out
		CmpSub(3,  A !=  B);			// they can be done by jumpeq
		CmpSub(4, (u64)A >  (u64)B);
		CmpSub(5, (u64)A <= (u64)B);
		CmpSub(6, (u64)A == (u64)B); default:;	// also
		CmpSub(7, (u64)A != (u64)B);			// also
	};
}


bool CompF_ (VMRegister* r, ASM Op) {
	auto A = &i1;
	auto B = &i2;

	switch (JCmpF_Cmpu) {
		CmpSub(0 , FA >  FB);
		CmpSub(1 , FA <= FB);
		CmpSub(2 , FA == FB);
		CmpSub(3 , FA != FB);
		
		CmpSub(4, DA >  DB);
		CmpSub(5, DA <= DB);
		CmpSub(6, DA == DB); default:
		CmpSub(7, DA != DB);
	};
}



AlwaysInline ASM* JumpI (VMRegister* r, ASM Op, ASM* Code) {
	return Code + CompI_(r, Op)*JCmpI_Jmpi;
}
		
AlwaysInline void CompI (VMRegister* r, ASM Op) {
	r[JCmpI_Jmpu].Int = CompI_(r, Op);
}

AlwaysInline ASM* JumpF (VMRegister* r, ASM Op, ASM* Code) {
	return Code + CompF_(r, Op)*JCmpF_Jmpi;
}

AlwaysInline void CompF (VMRegister* r, ASM Op) {
	r[JCmpF_Jmpu].Int = CompF_(r, Op);
}

AlwaysInline uint64 BitComp (VMRegister* r, ASM Op) { // cmpb
	auto i = CmpB_Invu;
	auto A = u2;
	auto B = u3;
	if (i&2)	// do we even need these? just remove?
		A = ~A;
	if (i&4)	// seems like we should remove these...
		B = ~B;
	return (A!=B) xor (i&1); // keep this though...
	// the first two could be "future upgrades"...?
}


AlwaysInline ASM* JumpEq (VMRegister* r, ASM Op, ASM* Code) {
	if (u1 == u2)
		return Code;
	return Code + JCmpEq_Jmpi;
}

AlwaysInline ASM* JumpNeq (VMRegister* r, ASM Op, ASM* Code) {
	if (u1 != u2)
		return Code;
	return Code + JCmpEq_Jmpi;
}

AlwaysInline ASM* JumpK (VMRegister* r, ASM Op, ASM* Code) {
	auto K = JCmpK_Ki;
	return Code + JCmpK_Jmpi * (i1 > K);
}

AlwaysInline ASM* JumpC (VMRegister* r, ASM Op, ASM* Code) {
	auto K = JCmpK_Ki;
	return Code + JCmpK_Jmpi * (i1 <= K);
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


AlwaysInline void IncrementAddr (VMRegister* r, ASM Op, bool UseOld) {
	int Size = CNTC_sizeu;
	int Off  = ((int)(CNTC_offsetu))-1;
	int Add  = CNTC_cnsti;
	auto PP = (uint*)(p1(u8) + (Off << Size));
	auto ni = n2;
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
	default:
	case 3:
		Old = *((u64*)PP); New = Old+Add;
		*((u64*)PP) = New;
		break;
	}
	if (ni)
		*Result = UseOld?Old:New;
}


//  Require can be a different instruction. // keep this thing fast.
//	VMRegister* Stack = r  +  ++Save;
//	Stack->Stack.Code = CodePtr;
//	Stack->Stack.SavedReg = Save;
//	Stack->Stack.Alloc = vm.Env.AllocCurr;
//	return Stack+1;


AlwaysInline ASM* ReturnFromFunc (VMRegister*& r, ASM Op) {
	JB_Decr(o2);
	JB_Decr(o3);
	VMRegister* stck = r-1;
	auto R1 = stck - stck->Stack.SavedReg;
	auto Code = stck->Stack.Code;
	auto Imm = RET_Valuei; // get before copy!
	auto Src = r+n1;
	
	*stck = *Src;
	stck->Uint |= Imm; // immediate
	if (RET_SafeDecru)
		JB_SafeDecr(o1);
	r = R1-1; // NewZero
	*r = {};
	return Code;
}

#define Transfer(Input,Shift)  (r[((Input)>>((Shift)*5))&31])
#define Transfer3(num)         case num: Zero[num] = Transfer(Code, num)


AlwaysInline void AllocStack (jb_vm& vm, VMRegister* r, ASM Op) {
	debugger; // do this later. We we need a separate stack for these?
	uint BEEETS = Alloc_Alignu;
	uint Align = 1 << BEEETS;
	int Amount = Alloc_Amounti << BEEETS;
	auto B = vm.Env.AllocBase;
	r[n1].Int = (uint64)(B);
	if (Amount > 0) {
		auto Up = (-((uint64)B) & (Align-1));
		B += Up+Amount;
	} else {
		debugger; // We need to de-align after
		B -= Amount;
		B -= (-((uint64)B) & (Align-1));
	}
	vm.Env.AllocBase = B;
}


AlwaysInline ASM* TailStack (VMRegister* r, ASM* Code, ASM Op) {
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


AlwaysInline VMRegister* SaveVMState (jb_vm& vm, VMRegister* r, ASM* CodePtr, int Save) { // jumpstack
	VMRegister* Stack = r + Save + 1;
	Stack->Stack.Code = CodePtr;
	Stack->Stack.SavedReg = Save;
	Stack->Stack.Alloc = vm.Env.AllocCurr;
	return Stack+1;
}


#define VMFinish {if (!U4_Lu) JB_App__SelfSignal(SIGINT); goto EXIT;}


AlwaysInline ASM* BumpStack (jb_vm& vm, VMRegister*& rp, ASM* CodePtr, ASM Op, u64 Code) { // jumpstack
	auto r = rp;
	auto Zero = SaveVMState(vm, r, CodePtr, n1);
	rp = Zero;

	switch ( Code&15 ) {
	default:
		Transfer3( 8);
		Transfer3( 7);
		Transfer3( 6);
		Transfer3( 5);
		Transfer3( 4);
		Transfer3( 3);
		Transfer3( 2);
		Transfer3( 1);
		debugger; 
	}

	Zero[ 0] = {};
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
#define FFISub(Mode, FP)	case 8-Mode:	V = ((Fn##Mode)Fn)FP; break

#define Code64 (*(u64*)Code)



void Nativeize(u64 data, Fn0 fn, VMRegister* r, int64 n);

AlwaysInline void ForeignFunc (jb_vm& vv, ASM* CodePtr, VMRegister* r, ASM Op, u64 funcdata) {
	auto T = ForeignFunc_Tableu;
	auto fn = (T<32) ? ((Fn0)(r[T].Uint)) : (vv.Env.Cpp[T]);
	if (fn)
		return Nativeize(funcdata, fn, r, n1);
	
	debugger;
	r[n1] = {}; // ugh
}

AlwaysInline void ForeignFunc2 (jb_vm& vv, ASM* CodePtr, VMRegister* r, ASM Op, u64 funcdata) {
	auto T = ForeignFunc_Tableu;
	auto fn = (T<32) ? ((Fn0)(r[T].Uint)) : (vv.Env.Cpp[T]);
	if (fn) {
		Nativeize(funcdata, fn, r, n1);
		JB_Incr(r[n1].Obj);
		return;
	}
	
	debugger;
	r[n1] = {}; // ugh
}

