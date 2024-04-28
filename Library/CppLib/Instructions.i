	// 						 (((((STOP)))))
ı EROR: _
	debugger;
	return u1 + U1_Lu;
ı FUNC: 
	__;
	Code = BumpStack(r, Code, Op);
	___;
ı FNCX: 
	__;
	vm.CurrStack = r;
	ForeignFuncSimple(r, Code, Op);
	___;
	// 						 (((((FUNC)))))
ı RET: 
	__;
	Code = Return(r, Code, Op);
	___;
ı SWAP: _
	std_swap(r[SWAP_Au], r[SWAP_Bu]);
	std_swap(r[SWAP_Cu], r[SWAP_Du]);
ı LEAF: 
	__;
	JumpLeaf(Code + U0_Li);
	___;
ı RETL: 
	__;
	Code = LeafCode;
	___;
	// 						 (((((Utils)))))
ı RARE: _
	if_rare (Rare(r, Op)) return n3;
ı CONV: _
	Conv(r, n2, Op);
	// 						 (((((Consts)))))
ı SET1: _
	i1 = U1_Li;
ı SETK: _
	i1 = JB_u64_RotL(Const_Lu, Const_rotu);
ı SETN: _
	loadconst(r, Op, Code);
	// 						 (((((Math)))))
ı ADDC: _
	i1 = i2 + JB_u64_RotL(L3, n3);
ı ADD: _
	i1 = i2 + (i3 << L3);
ı SUB: _
	i1 = i2 - (i3 << L3);
ı MUL: _
	i1 = (i2 * i3) + i4;
ı DIV: _
	DivMath(r, Op);
	// 						 (((((Bitops)))))
ı SHRS: _
	i1 = i2 >> (u3 + L3);
ı SHRU: _
	u1 = u2 >> (u3 + L3);
ı SHLS: _
	i1 = i2 >> (u3 + L3);
ı BAND: _
	u1 = u2 & (u3 | L3);
ı BOR: _
	u1 |= (u2 | u3);
ı BXOR: _
	u1 = u2 ^ u3;
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
	// 						 (((((Branches)))))
ı CMPI: 
	__;
	Code = CompI(r, Op, Code);
	___;
ı CMPF: 
	__;
	Code = CompF(r, Op, Code);
	___;
ı CMPE: _
	Code = CompEq(r, Op, Code);
	___;
ı CMPN: 
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
	// 						 (((((Refs)))))
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

	// 						(((((Memory)))))
ı TABL: _
	u1 = table(u2, L2);
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
ı MEMM: _
	//  copy/fill/endian/xor

	MemStuff((u32 *) u1, (u32 *) u2, n3, L3);
	// 						(((((Float)))))
ı FADD: _
	f1 = f2 + f3;
ı FSUB: _
	f1 = f2 - f3;
ı FMUL: _
	f1 = (f2 * f3) + f4;
ı FDIV: _
	f1 = f2 / f3;
ı DADD: _
	d1 = d2 + d3;
ı DSUB: _
	d1 = d2 - d3;
ı DMUL: _
	d1 = (d2 * d3) + d4;
ı DDIV: _
	d1 = d2 / d3;
ı PRNT: _
	printf("%lli\n", i1);
ı 

