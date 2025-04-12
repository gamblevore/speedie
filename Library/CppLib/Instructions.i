ı EROR: _
	if (u2 == u1 and u3 == u4) 
	VMFinish
;
ı TAIL: 
	__;
	TailStack(vm, r, Code, Op);
	___;
ı KNST2: _
	LoadConst(r, Op, *Code++);
ı KNST3: _
	LoadConst(r, Op, *((uint64 *)(Code)));
	Code += 2;
ı GMEM: _
	LoadGConst(r, Op, *Code++);
ı FNC: 
	__;
	Code = BumpStack(vm, r, Code + 1, Op, *Code);
	___;
ı FNC3: 
	__;
	Code = BumpStack(vm, r, Code + 2, Op, Code64);
	___;
ı FNCX: 
	__;
	ForeignFunc(vm, Code, r, Op, *Code);
	Code++;
	___;
ı FNCX3: 
	__;
	ForeignFunc(vm, Code, r, Op, Code64);
	Code += 2;
	___;
ı NOOP: _
	i1 = i1;
	// NOOP

ı TRAP: _
	JB_App__SelfSignal(Trap_Signalu);
ı GRAB: _
	u1 = (uint64)(&u2);
	u3 = (uint64)(&u4);
ı RET: 
	__;
	Code = ReturnFromFunc(vm, r, Op);
	___;
ı ALLO: _
	AllocStack(vm, r, Op);
ı SWAP: _
	JB_Swap(r[n1], r[n2]);
	JB_Swap(r[n3], r[n4]);
ı PRNT: _
	printf("%lli\n", i1);
	// better to print this also as float/double/signed/unsigned...

ı RARE: _
	Rare_(r, Op);
ı CONV: _
	RegConv(r, Op);
ı KNSR: _
	RotateConst(r, Op);
ı KNST: _
	LoadConst(r, Op, 0);
ı ADDK: _
	i1 = i2 + U2_Li;
ı ADPK: _
	i1 = i2;
	i2 = i2 + U2_Li;
ı MULK: _
	i1 = i2 * U2_Li;
ı ADD: _
	i1 = i2 + (i3 << Shift_Shu);
ı SUB: _
	i1 = (i2 - i3) >> Shift_Shu;
ı MUL: _
	i1 = (i2 * i3) + i4;
ı DIV: _
	DivMath(r, Op);
ı DIV2: _
	if (i2 < 0) 
	i1 = (i2 + ((1 << Div2_Addu) - 1)) >> Div2_Shu
;
	else 
	i1 = i2 >> Div2_Shu
;
ı CLAM: _
	if (Float_Du) 
	i1 = (std_min(std_max(i2, i3), i4))
;
	else 
	u1 = (std_min(std_max(u2, u3), u4))
;
ı BXOR: _
	u1 = u2 ^ (u3 | Shift_Shu);
ı BRSS: _
	i1 = (i2 << Shift_Shu) >> i3;
ı BRSH: _
	u1 = ((u2 << Shift_Shu) >> Shift_Shu) >> u3;
ı BLSH: _
	u1 = ((u2 << u3) << Shift_Shu) >> Shift_Shu;
ı BAND: _
	u1 = u2 & (u3 | Shift_Shu);
ı BOR: _
	u1 = u2 | (u3 | Shift_Shu);
ı BNAN: _
	u1 = u2 & ~(u3 | Shift_Shu);
ı BNOR: _
	u1 = u2 | ~(u3 | Shift_Shu);
ı BNOT: _
	u1 = ~u2 & ~(u3 | Shift_Shu);
ı BFLG: _
	if (BFLD_signu) 
	i1 = ((i2 << BFLD_upu) >> BFLD_downu)
;
	else 
	u1 = ((u2 << BFLD_upu) >> BFLD_downu)
;
ı BSTT: _
	i1 = 0;
ı CMPB: _
	u1 = BitComp(r, Op);
ı TERN: _
	if (u2) 
	r[n1] = r[n3]
;
	else 
	r[n1] = r[n4]
;
ı CMPI: _
	CompI(r, Op);
ı CMPIS: _
	CompIS(r, Op);
ı CMPF: _
	CompF(r, Op);
ı JSWI: _
	Code += n1 + n2 + JCmpEq_Jmpi;
ı JUMP: _
	Code += l0;
ı JMPI: _
	Code = JumpI(r, Op, Code);
ı JMPIS: _
	Code = JumpIS(r, Op, Code);
ı JMPF: _
	Code = JumpF(r, Op, Code);
ı JMPE: _
	Code = JumpEq(r, Op, Code);
ı JMPN: _
	Code = JumpNeq(r, Op, Code);
ı JMPK: _
	Code = JumpK(r, Op, Code);
ı JMPKN: _
	Code = JumpKN(r, Op, Code);
ı JBOR: _
	if (u1 << (64 - (8 << Bra_Bytezu))) 
	Code += Bra_Jmpi
;
ı JBAN: _
	if (!(u1 << (64 - (8 << Bra_Bytezu)))) 
	Code += Bra_Jmpi
;
ı LUPD: _
	if (i1-- > i2) 
	Code += Loop_Jmpi
;
ı LUPU: _
	if (i1++ < i2) 
	Code += Loop_Jmpi
;
ı RFAP: _
	SetRefApart(r, Op);
ı RFST: _
	SetRefBasic(r, Op);
ı RFWR: _
	SetRefRegToMem(r, Op);
ı RFRD: _
	SetRefMemToReg(r, Op);
ı RFDC: _
	SetRefDecrMem(r, Op);
ı RALO: _
	o1 = alloc(o2);
	// should call constructor too.

ı GSTR: _
	o1 = strs(vm, Op);
ı GTAB: _
	u1 = table(vm, Op);
ı RD1U: _
	u1 = mem1(uint8);
	mem2(uint8);
ı RD1S: _
	u1 = mem1(char);
	mem2(char);
ı RD2U: _
	u1 = mem1(u16);
	mem2(u16);
ı RD2S: _
	u1 = mem1(s16);
	mem2(s16);
ı RD4U: _
	u1 = mem1(u32);
	mem2(u32);
ı RD4S: _
	u1 = mem0(int);
	mem2(int);
ı RD8U: _
	u1 = mem1(u64);
	mem2(u64);
ı RD16: _
	((ivec4 *) r)[n1] = mem1(ivec4);
	mem2(ivec4);
ı WR1U: _
	mem1(uint8) = u1;
	mem2(uint8);
ı WR2U: _
	mem1(u16) = u1;
	mem2(u16);
ı WR4U: _
	//  xcode only complains about this one? ?

	mem1(u32) = (u32) u1;
	mem2(u32);
ı WR8U: _
	mem1(u64) = u1;
	mem2(u64);
ı WR16: _
	mem1(ivec4) = (ivec4)(((ivec4 *) r)[n1]);
	mem2(ivec4);
ı CNTC: _
	IncrementAddr(r, Op, 1);
ı CNTD: _
	IncrementAddr(r, Op, 0);
ı MEMZ: _
	memzero((void *) u1, L1);
ı FADD: _
	if (Float_Du) 
	d1 = d2 + d3 - d4
;
	else 
	f1 = f2 + f3 - f4
;
ı FADK: _
	f1 += f2 + FloatIncr1(Op);
ı FMUL: _
	if (Float_Du) 
	d1 = (d2 * d3) + d4
;
	else 
	f1 = (f2 * f3) + f4
;
ı FMLK: _
	f1 = f2 * FloatIncr1(Op);
ı FDIV: _
	if (Float_Du) 
	d1 = d2 / d3
;
	else 
	f1 = f2 / f3
;
ı FFRC: _
	if (Float_Du) 
	d1 = (d2 - floor(d2)) * d3
;
	else 
	f1 = (f2 - floor(f2)) * f3
;
ı FCLM: _
	if (Float_Du) 
	d1 = (std_min(std_max(d2, d3), d4))
;
	else 
	d1 = (std_min(std_max(d2, d3), d4))
;
ı VGET: _
	i1 = iv2[n3 + u4];
ı VSET: _
	iv1[n3 + u4] = i2;
ı VBLD: _
	v1 = VBuild(r, Op);
ı VSWZ: _
	v1 = VSwiz(r, Op);
ı 

