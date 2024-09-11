ı EROR: _
	return u1 + U1_Lu;
ı FUNK: 
	__;
	Code = BumpStack(r, Code, Op);
	___;
ı TAIL: 
	__;
	Code = TailStack(r, Code, Op);
	___;
ı FFNC: 
	__;
	vm.CurrRegs = r;
	Code = ForeignFunc(vm, Code, Op);
	___;
ı KNST: _
	Code = LoadConst(r, Op, Code);
ı NOOP: _
	i1 = i1;
	// NOOP

ı TRAP: _
	if (Trap_Continueu) 
	JB_App__SelfSignal(Trap_Lu)
;
	else 
	return u1
;
ı RET: 
	__;
	Code = Return(r, Code, Op);
	___;
ı ALLO: _
	AllocStack(vm, r, Op);
ı SWAP: _
	std_swap(r[n1], r[n2]);
	std_swap(r[n3], r[n4]);
ı PRNT: _
	printf("%lli\n", i1);
	// better to print this also as float/double/signed/unsigned...

ı RARE: _
	if_rare (Rare(r, Op)) return n3;
ı CONV: _
	RegConv(r, Convert_Modeu, Op);
ı KNSR: _
	RotateConst(r, Op);
ı ADDK: _
	i1 = i2 + U2_Li;
ı ADPK: _
	i1 = i2;
	i2 = i2 + U2_Li;
ı ADD: _
	i1 = i2 + (i3 << Shift_Shu);
ı SUB: _
	i1 = (i2 - i3) >> Shift_Shu;
ı MULT: _
	i1 = (i2 * i3) + i4;
ı DIVV: _
	DivMath(r, Op);
ı DIVK: _
	if (i2 < 0) 
	i1 = (i2 + ((1 << DivK_Addu) - 1)) >> DivK_Shu
;
	else 
	i1 = i2 >> DivK_Shu
;
ı MAX: _
	if (MinMax_Signu) 
	i1 = std_max(i2, i3)
;
	else 
	u1 = std_max(u2, u3)
;
ı MIN: _
	if (MinMax_Signu) 
	i1 = std_min(i2, i3)
;
	else 
	u1 = std_min(u2, u3)
;
ı BSHS: _
	i1 = i2 >> u3;
ı BSHR: _
	u1 = u2 >> u3;
ı BSHL: _
	u1 = u2 << u3;
ı BAND: _
	u1 = u2 & (u3 | Shift_Shu);
ı BOAR: _
	u1 = u2 | u3;
ı BXOR: _
	u1 = u2 ^ u3;
ı BNOT: _
	u1 = ~u2 & ~u3;
ı BFLG: _
	if (BFLD_signu) 
	i1 = ((i2 << BFLD_upu) >> BFLD_downu)
;
	else 
	u1 = ((u2 << BFLD_upu) >> BFLD_downu)
;
ı BSTT: _
	i1 = 0;
ı BCLR: _
	BitClear(r, Op);
ı CMPB: _
	u1 = BitComp(r, Op);
ı TERN: _
	if (u2) 
	u1 = u3
;
	else 
	u1 = u4
;
ı CMPI: _
	CompI(r, Op);
ı CMPF: _
	CompF(r, Op);
ı JUMP: _
	Code += l0;
ı JMPI: 
	__;
	Code = JompI(r, Op, Code);
	___;
ı JMPF: 
	__;
	Code = JompF(r, Op, Code);
	___;
ı JMPE: 
	__;
	Code = JompEq(r, Op, Code);
	___;
ı JMPN: 
	__;
	Code = JompNeq(r, Op, Code);
	___;
ı JBRA: 
	__;
	if (i1) 
	Code += Bra_Jmpi
;
	___;
ı JBRN: 
	__;
	if (!i1) 
	Code += Bra_Jmpi
;
	___;
ı LUPD: 
	__;
	if (i1-- > i2) 
	Code += Loop_Jmpi
;
	___;
ı LUPU: 
	__;
	if (i1++ < i2) 
	Code += Loop_Jmpi
;
	___;
ı RSET: _
	setref(n1, o1, o2);
	setref(n3, o3, o4);
ı RMEM: _
	i1 = i1;
	// Do later

ı RALO: _
	o1 = alloc(o2);
	// should call constructor too.

ı TABL: _
	u1 = table(n2);
ı RD1U: _
	u1 = mem(uint8);
	mem2(uint8);
ı RD1S: _
	u1 = mem(char);
	mem2(char);
ı RD2U: _
	u1 = mem(u16);
	mem2(u16);
ı RD2S: _
	u1 = mem(s16);
	mem2(s16);
ı RD4U: _
	u1 = mem(u32);
	mem2(u32);
ı RD4S: _
	u1 = mem(int);
	mem2(int);
ı RD8U: _
	u1 = mem(u64);
	mem2(u64);
ı RD16: _
	((ivec4 *) r)[n1] = mem(ivec4);
	mem2(ivec4);
ı WR1U: _
	mem(uint8) = u1;
	mem2(uint8);
ı WR2U: _
	mem(u16) = u1;
	mem2(u16);
ı WR4U: _
	//  xcode only complains about this one? ?

	mem(u32) = (u32) u1;
	mem2(u32);
ı WR8U: _
	mem(u64) = u1;
	mem2(u64);
ı WR16: _
	mem(ivec4) = (ivec4)(((ivec4 *) r)[n1]);
	mem2(ivec4);
ı CNTC: _
	CountConst(r, Op, 1);
ı CNTD: _
	CountConst(r, Op, 0);
ı MEMU: _
	//  copy/fill/endian/xor

	MemStuff((u32 *) u1, (u32 *) u2, n3, L3);
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
ı FMAX: _
	if (Float_Du) 
	d1 = std_max(d2, d3)
;
	else 
	f1 = std_max(f2, f3)
;
ı FMIN: _
	if (Float_Du) 
	d1 = std_min(d2, d3)
;
	else 
	f1 = std_min(f2, f3)
;
ı 

