

// need to allow vectorcall on windows. to allow vectors to be passed using the
// SIMD registers.
//#include "ffi.h"
typedef void (*FFI_Fn)(void);



AlwaysInline void DivMath(VMRegister* r, ASM Op) {
	auto R3 = i3;
	auto R4 = i4;
	uint A = n1;
	uint B = n2;
	
	switch (Div_Kindu & 3) { // so there are 4 possible divisions we can do
	  case 0:
		if (A) // on ARM, % does not come for free along with  /
			   // so its better not to do % unless we explicitly need it.
			r[A].Int = R3 % R4;
		if (B)
			r[B].Int = R3 / R4;
		return;
	  case 1:
		if (A)
			r[A].Int = (u64)R3 % (u64)R4;
		if (B)
			r[B].Int = (u64)R3 / (u64)R4;
		return;
	  case 2:
		if (A)
			r[A].Int = (int64)((int)R3 % (int)R4);
		if (B)
			r[B].Int = (int64)((int)R3 / (int)R4);
		return;
	  case 3:
		if (A)
			r[A].Int = (uint)R3 %(uint)R4;
		if (B)
			r[B].Int = (uint)R3 /(uint)R4;
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


AlwaysInline void SetRefRegToReg(VMRegister* r, ASM Op) {
	auto A = r[n1].Obj;
	auto B = r[n2].Obj;
	if (RefSet_Incru)
		JB_Incr(B);
	if (RefSet_Moveu)
		r[n1].Obj = B;
	if (RefSet_Decru)
		JB_SafeDecr_(A);
	if (RefSet_Freeu)
		JB_FreeIfDead(A);
}



#define table(b)			((u64)(((void**)(&vm.Env))[b])+L2)
#define mem(t)				((t*)u2)[I3+Read_Lu]
#define mem2(t)				(u2 = (u64)((t*)u2 + Read_moveu-1))

AlwaysInline JB_Object* alloc(void* o) {
	// we need a class table, and look it up from there.
	// we don't have dynamicly created classes anyhow...
	return JB_AllocNew(((JB_MemoryLayer*)o)->CurrBlock);
}


AlwaysInline void RegConv (VMRegister* r, int Conv, ASM Op) {
	// float, double, u64, s64. 12 conversions possible (and 4 pointless ones)
	auto s = r + n2;
	auto d = r + n1;
		
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
#define  FA  *((float*)A)
#define  FB  *((float*)B)

#define  UA  *((u64*)A)
#define  UB  *((u64*)B)
#define  iA  *((int*)A)
#define  iB  *((int*)B)
#define  uA  *((uint*)A)
#define  uB  *((uint*)B)

#define CmpSub(Mode, Cmp) case Mode: return (Cmp);


bool CompI_ (VMRegister* r, ASM Op) {
	auto A = &i1;
	auto B = &i2;
	switch (JCmpI_Cmpu) {
		CmpSub(0,  A >   B);
		CmpSub(1,  A >=  B);
		CmpSub(2,  A ==  B);
		CmpSub(3,  A !=  B);
		CmpSub(4, UA >  UB);
		CmpSub(5, UA >= UB);
		CmpSub(6, UA == UB); default:;
		CmpSub(7, UA != UB);
	};
}


bool CompF_ (VMRegister* r, ASM Op) {
	auto A = &i1;
	auto B = &i2;

	switch (JCmpF_Cmpu) {
		CmpSub(0 , FA >  FB);
		CmpSub(1 , FA >= FB);
		CmpSub(2 , FA == FB);
		CmpSub(3 , FA != FB);
		
		CmpSub(4 , FA >  DB);
		CmpSub(5 , FA >= DB);
		CmpSub(6 , FA == DB);
		CmpSub(7 , FA != DB);
		
		CmpSub(8 , DA >  FB);
		CmpSub(9 , DA >= FB);
		CmpSub(10, DA == FB);
		CmpSub(11, DA != FB);
		
		CmpSub(12, DA >  DB);
		CmpSub(13, DA >= DB);
		CmpSub(14, DA == DB); default:
		CmpSub(15, DA != DB);
	};
}



AlwaysInline ASM* JompI (VMRegister* r, ASM Op, ASM* Code) {
	return Code + JCmpI_Jmpu*CompI_(r, Op);
}
		
AlwaysInline void CompI (VMRegister* r, ASM Op) {
	r[JCmpI_Jmpu].Int = CompI_(r, Op);
}

AlwaysInline ASM* JompF (VMRegister* r, ASM Op, ASM* Code) {
	return Code + JCmpF_Jmpu*CompF_(r, Op);
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
	return (A==B) xor (i&1); // keep this though...
	// the first two could be "future upgrades"...?
}

AlwaysInline void BitClear (VMRegister* r, ASM Op) {
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

AlwaysInline ASM* JompEq (VMRegister* r, ASM Op, ASM* Code) {
	if (u1 == u2)
		return Code;
	return Code + JCmpEq_Jmpi;
}


AlwaysInline ASM* JompNeq (VMRegister* r, ASM Op, ASM* Code) {
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


AlwaysInline void IncrementAddr (VMRegister* r, ASM Op, bool UseOld) {
	int Size = CNTC_sizeu;
	int Off  = CNTC_offsetu;
	int Add  = CNTC_cnsti;
	auto PP = p1(u8);
	PP += Off << Size;
	uint64 Old;
	uint64 New;
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
	*Where = UseOld?Old:New;
}


//  Require can be a different instruction. // keep this thing fast.
//	VMRegister* Stack = r  +  ++Save;
//	Stack->Stack.Code = CodePtr;
//	Stack->Stack.SavedReg = Save;
//	Stack->Stack.Alloc = vm.Env.AllocCurr;
//	return Stack+1;

AlwaysInline ASM* Return (VMRegister*& ZeroPlace, ASM Op) {
	auto OldZero = ZeroPlace;
	VMRegister* stck = OldZero-1;
	auto R1 = stck - stck->Stack.SavedReg;
	auto Code = stck->Stack.Code;
	auto V = RET_Valuei; // get before copy!
	auto Src = OldZero+n1;
	ZeroPlace = R1-1; // NewZero
	stck = (VMRegister*)memcpy(stck, Src, RET_Countu<<4);
	if (V)
		stck->Uint |= V;
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


 
 Fn0 VMDummyTable[] = {(Fn0)JB_Str_Length, (Fn0)JB_Str_Address, (Fn0)JB_Str_WhiteSpace, (Fn0)JB_Str_OperatorPlus, (Fn0)JB_Str_ChrUTF8, (Fn0)0}; 


#define NextRegI(r,r2) 											\
	"ubfiz  x"#r",		%[CODE],	"#r2",		5		\n" 	\
	"ldr    x"#r",		[%[R],		x"#r", lsl 3]		\n" // needs to be 4 but can't do this directly????

#define NextRegF(r,r2) 											\
	"ubfiz  x"#r",		%[CODE],	"#r2",		5		\n" 	\
	"ldr    d"#r",		[%[R],		x"#r", lsl 3]		\n" // needs to be 4 but can't do this directly???



AlwaysInline void ForeignFunc (jb_vm& vv, ASM* CodePtr, VMRegister* r, ASM Op, u64 funcdata) {
// Only OP needs saving...
	auto T = ForeignFunc_Tableu;
	auto fn = (T<32) ? ((Fn0)(r[T].Uint)) : (vv.Env.Cpp[T]);
	u64 iresult; // need a simd... also
	ivec4 vresult;
	
#if __CPU_TYPE__ == __CPU_ARM__
	__asm__ volatile ( // we used to have ints first, but floats first makes more sense.
	"and     x1, %[CODE], 15		\n\t"		// x1 = code&15
	"add     x8, x1, x1, lsl 2		\n\t"		// x8 = x1*5
	"lsr     x8, %[CODE], x8		\n\t"		// x8 = code>>x8 // x8 = code>>(x1*5)

//	::[CODE] "r" (funcdata) // in case we wanna make this a lil more optimised.
//	);
//	__asm__ volatile (

	"adr x0, 1f						\n\t"		
	"add x0, x0, x1, lsl 1			\n\t"		// x0 += x1 << 1
	"br  x0							\n\t"		// smart-jump
	"1:\n\t"
	// Float / SIMD
	NextRegF(8, 52) // not perfect yet... we need to pass the entire SIMD, not just a double!
	NextRegF(7, 47)
	NextRegF(6, 42)
	NextRegF(5, 37)
	NextRegF(4, 32)
	NextRegF(3, 27)
	NextRegF(2, 22)
	NextRegF(1, 17)
	NextRegF(0, 12)

	"ubfiz   x1, %[CODE], 4, 4		\n\t"		// x1 = (code>>4)&15 // still needs << 1
	"adr x0, 2f						\n\t"		// ADR + ADD can merge? SHOULD allow pc instead of x0 
	"add x0, x0, x1					\n\t"		// but doesnt... (make the first part non-volatile)?
	"br  x0							\n\t"		// smart-jump
	"2:\n\t"
	// ints
	NextRegI(8, 52)
	NextRegI(7, 47)
	NextRegI(6, 42)
	NextRegI(5, 37)
	NextRegI(4, 32)
	NextRegI(3, 27)
	NextRegI(2, 22)
	NextRegI(1, 17)
	NextRegI(0, 12)

	"stp     x29, x30, [sp, -16]!	\n\t"		// copy and alloc
	"mov     x29, sp				\n\t"		// update some shit
        
	"blr     %[FN]					\n\t"		// call some shit
    "ldp     x29, x30, [sp], 16		\n\t"		// restore some shit
	""
	 : [x0] "=&r" (iresult),   [q0] "=&w" (vresult)
	 : /*  input  */  [R] "r" (r),  [CODE] "r" (funcdata),  [FN] "r" (fn),  [OP] "r" (Op) 
	 : /* clobber */  "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17" );
	 
	r+=n1;
	if (Op&32)
		r->Int = iresult;
	  else
		r->Ivec = vresult;
	// i think that's it.
		
#else
	#warning "unimplemented VM"
#endif
}



// http://ethernut.de/en/documents/arm-inline-asm.html
// http://modexp.wordpress.com/2018/10/30/arm64-assembly/
// http://wolchok.org/posts/how-to-read-arm64-assembly-language/

/*
	OK, what about saving the register state?
	We need to know how many regs to save. Thats not the same as where we place the result!
	Even if it were, we still need two counts. The send-count, and the save-count.
	
	The send-count is typed.
	
	The save-count has no type.
*/
/*

Observations so far:
 	* Use godbolt.org... its simpler than understanding the documentation. (The docs seem wrong too)
	* ARM x17 is the highest register I can freely alter
 	* Both ARM and x86 only have two register files! Despite what the docs say.
		* Both do it the same way. General/int in one place, and SIMD+FP in another.
		* x87/MMX is unused on x86.
	* x86 has 6 regs for passing ints, the other two have to be done on the stack
	* the FP/SIMD are also just done in order
		* we have enough regs on ARM&X86
	* You can't specify registers in C++, except when they are observed by ASM.
*/



	// I think calling the VM should be a simple-task. So instead of calling a function-pointer...
	// we test the function pointer, to see if its SPD or C. If C... we call it. Otherwise we call the VM.
	// this has to be done at every call-site. What about for passing to C++ libs? We'd have to generate
	// some native ASM for that. I think C++ has lambdas. It could be done.
