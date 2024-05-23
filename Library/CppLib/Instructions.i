ı EROR: _
	if (n1 or U1_Lu) 
	return u1 + U1_Lu
;
ı FUNC: 
	__;
	Code = BumpStack(r, Code, Op);
	___;
ı SETN: _
	LoadConst(r, Op, Code);
ı FNCX: 
	__;
	vm.CurrStack = r;
	ForeignFuncSimple(r, Code, Op);
	___;
ı TAIL: 
	__;
	Code = TailStack(r, Code, Op);
	___;
ı TRAP: _
	if (Trap_Signalu) 
	JB_App__SelfSignal(Trap_Lu)
;
	else if (!Trap_Funcu) 
	debugger
;
ı RET: 
	__;
	Code = Return(r, Code, Op);
	___;
ı SWAP: _
	std_swap(r[SWAP_Au], r[SWAP_Bu]);
	std_swap(r[SWAP_Cu], r[SWAP_Du]);
ı PRNT: _
	printf("%lli\n", i1);
	// better to print this also as float/double/signed/unsigned...

ı RARE: _
	if_rare (Rare(r, Op)) return n3;
ı CONV: _
	Conv(r, n2, Op);
ı SETK: _
	RotateConst(r, Op);
ı ADD: _
	i1 = i2 + (i3 << L3);
ı ADDK: _
	i1 = i2 + U2_Li;
ı SUB: _
	i1 = i2 - (i3 << L3);
ı MUL: _
	i1 = (i2 * i3) + i4;
ı DIV: _
	DivMath(r, Op);
ı SHRS: _
	i1 = ((uint64)((i2 << L3) >> u3)) >> L3;
ı SHRU: _
	u1 = (u2 >> u3) | u4;
ı SHLU: _
	i1 = (i2 << u3) | u4;
ı BAND: _
	u1 = u2 & (u3 | L3);
ı BOR: _
	u1 |= (u2 | u3);
ı BXOR: _
	u1 = u2 ^ u3;
ı BXNR: _
	u1 = (~u2 ^ u3);
ı BNOT: _
	u1 = ~u2;
ı BFLG: _
	if (BFLD_Lu) 
	i1 = ((i2 << BFLD_upu) >> BFLD_downu)
;
	else 
	u1 = ((u2 << BFLD_upu) >> BFLD_downu)
;
ı BFLS: _
	i1 |= ((i2 << BFLD_downu) >> BFLD_upu);
ı BROL: _
	i1 = JB_u64_RotL(u2, u3 + L3);
ı BROR: _
	i1 = JB_u64_RotR(u2, u3 + L3);
ı BCLR: _
	BitClear(r, Op);
ı BCMP: _
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
	Code = CompEq(r, Op, Code);
	___;
ı JMPN: 
	__;
	Code = CompNeq(r, Op, Code);
	___;
ı BRA: 
	__;
	if (!i1) 
	Code += Bra_jmpi
;
	___;
	i1 += Bra_c1u - 1;
ı BRAN: 
	__;
	if (i1) 
	Code += Bra_jmpi
;
	___;
	i1 += Bra_c1u - 1;
ı LUPU: 
	__;
	if (i1++ < i2) 
	Code -= U2_Lu
;
	___;
ı LUPD: 
	__;
	if (i1-- > i2) 
	Code -= U2_Lu
;
	___;
ı RSDE: 
	__;
	Code += U3_Li;
	___;
	decr(o3);
	decr(o2);
	safedecr(o1);
	// jump too? for branches...

ı RSET: _
	setref(n1, o1, o2);
	setref(n3, o3, o4);
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
	CountConst(r, Op);
ı CNTD: _
	CountConstNew(r, Op);
ı MEMM: _
	//  copy/fill/endian/xor

	MemStuff((u32 *) u1, (u32 *) u2, n3, L3);
ı FEXK: _
	if FloatAddExp_Du 
	f1 = FloatSh2(u2, FloatAddExp_Sh2i) + FloatSh2(u3, FloatAddExp_Sh3i)
;
	else 
	f1 = FloatSh1(u2, FloatAddExp_Sh2i) + FloatSh1(u3, FloatAddExp_Sh3i)
;
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
ı 

