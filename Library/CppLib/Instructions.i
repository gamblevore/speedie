ı EROR: _
	if (u2 == u1 and u3 == u4)
	VMFinish
;
ı TAIL: _
	TailStack(vm, r, Code, Op);
ı KNST2: _
	LoadConst(r, Op, *Code++);
ı KNST3: _
	LoadConst(r, Op, *((uint64 *)(Code)));
	Code += 2;
ı FNC: _
	Code = BumpStack(vm, r, Code + 1, Op, *Code);
ı FNC3: _
	Code = BumpStack(vm, r, Code + 2, Op, Code64);
ı FNCX: _
	ForeignFunc(vm, Code, r, Op, *Code);
	Code++;
ı FNCX3: _
	ForeignFunc(vm, Code, r, Op, Code64);
	Code += 2;
ı NOOP: _
	i1 = i1;
	// NOOP

ı TRAP: _
	JB_App__SelfSignal(Trap_Signalu);
ı GRAB: _
	u1 = (uint64)(&u2);
ı RET: _
	Code = ReturnFromFunc(vm, r, Op);
ı AFNC: _
	i1 = FuncAddr(vm, Op);
ı ALLO: _
	AllocStack(vm, r, Op);
ı DUMI: _
	0;
ı RARE: _
	Rare_(r, Op);
ı CONV: _
	RegConv(r, Op);
ı FEAT: _
	u1 = 0;
ı KNSR: _
	RotateConst(r, Op);
ı KNST: _
	LoadConst(r, Op, 0);
ı ADDB: _
	i1 = i1 + (U1_Li << 12);
ı ADDK: _
	i1 = i2 + U2_Li;
ı ADAK: _
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
	i1 = (((i2 + ((1 << Div2_Shu) - 1)) >> Div2_Shu) << Div2_Clearu) >> Div2_Clearu
;
	else
	i1 = ((i2 >> Div2_Shu) << Div2_Clearu) >> Div2_Clearu
;
ı CLAMI: _
	i1 = std_clamp(btc(i2), btc(i3), btc(i4));
ı CLAMU: _
	u1 = std_clamp(btc(u2), btc(u3), btc(u4));
ı ADDM: _
	i1 = i2 + (ii3 << AddOrSubM_Shu);
ı SUBM: _
	i1 = (i2 - ii3) >> AddOrSubM_Shu;
ı DIVS: _
	DivMath32(r, Op);
ı MULS: _
	i1 = (ii2 * ii3) + ii4;
ı BFLG: _
	if (BFLD_signu)
	i1 = ((i2 << BFLD_upu) >> BFLD_downu)
;
	else
	u1 = ((u2 << BFLD_upu) >> BFLD_downu)
;
ı BRSS: _
	i1 = ((i2 << Shift_Shu) >> Shift_Shu) >> i3;
ı BRSH: _
	u1 = ((u2 << Shift_Shu) >> Shift_Shu) >> u3;
ı BLSH: _
	u1 = ((u2 << u3) << Shift_Shu) >> Shift_Shu;
ı BSTT: _
	i1 = 0;
ı BAND: _
	u1 = u2 & ((u3 << Shift_Shu) >> Shift_Shu);
ı BORR: _
	u1 = u2 | ((u3 << Shift_Shu) >> Shift_Shu);
ı BXOR: _
	u1 = u2 ^ ((u3 << Shift_Shu) >> Shift_Shu);
ı BNOT: _
	u1 = ~u2 & ((~u3 << Shift_Shu) >> Shift_Shu);
ı BANK: _
	u1 = u2 & U2_Li;
ı BORK: _
	u1 = u2 | U2_Li;
ı BXRK: _
	u1 = u2 ^ U2_Li;
ı EQUL: _
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
ı CMPF: _
	CompF(r, Op);
ı JUMP: _
	Code += l0;
ı JMPI: _
	Code = JumpI(r, Op, Code);
ı JMPF: _
	Code = JumpF(r, Op, Code);
ı JMPE: _
	Code = JumpEq(r, Op, Code);
ı JMPN: _
	Code = JumpNeq(r, Op, Code);
ı JMKM: _
	Code = JumpK(r, Op, Code);
ı JMKL: _
	Code = JumpKN(r, Op, Code);
ı JMKE: _
	Code = JumpKE(r, Op, Code);
ı JMKN: _
	Code = JumpKNE(r, Op, Code);
ı JBOR: _
	if (u1 << (Bra_Smallu << 5))
	Code += Bra_Jmpi
;
ı JBAN: _
	if (!(u1 << (Bra_Smallu << 5)))
	Code += Bra_Jmpi
;
ı LUPU: _
	if (ii1++ < ii2)
	Code += Loop_Jmpi
;
ı LUPD: _
	if (ii1-- > ii2)
	Code += Loop_Jmpi
;
ı RFUN: _
	SetRefApart(r, Op);
ı RFST: _
	SetRefBasic(r, Op);
ı RFWR: _
	SetRefRegToMem(r, Op);
ı RFRD: _
	SetRefMemToReg(r, Op);
ı RALO: _
	o1 = alloc(o2);
	// should call constructor too.

ı RFRT: _
	Code = DeRefRegs(vm, r, Op);
ı GOBJ: _
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
ı COPY: _
	MemCopyRDWR(r, Op);
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
	d1 = std_clamp(d2, d3, d4)
;
	else
	f1 = std_clamp(f2, f3, f4)
;
ı VGET: _
	i1 = iv2[n3 + u4];
ı VSET: _
	iv1[n3 + u4] = i2;
ı VBLD: _
	v1 = VBuild(r, Op);
ı VSWZ: _
	v1 = VSwiz(r, Op);
ı VMOV: _
	iv1 = iv2;
	iv3 = iv4;
ı VADD: _
	v1 = v2 + v3 - v4;
ı VADK: _
	v1 += v2 + FloatIncr1(Op);
ı VMUL: _
	v1 = (v2 * v3) + v4;
ı VMLK: _
	v1 = v2 * FloatIncr1(Op);
ı VDIV: _
	v1 = v2 / v3;
ı VFRC: _
	v1 = (v2 - VFloor(v2)) * v3;
ı VCLM: _
	v1 = VMin(VMax(v2, v3), v4);
ı QADD: _
	iv1 = iv2 + (iv3 << Shift_Shu);
ı QSUB: _
	iv1 = (iv2 - iv3) >> Shift_Shu;
ı QMUL: _
	iv1 = (iv2 * iv3) + iv4;
ı QDIV: _
	iv1 = iv2 / iv3;
ı QCLM: _
	iv1 = QMin(QMax(iv2, iv3), iv4);
ı QADK: _
	iv1 = iv2 + U2_Li;
ı QFLG: _
	iv1 = ((iv2 << BFLD_upu) >> BFLD_downu);
ı QRSS: _
	iv1 = (iv2 >> Shift_Shu) >> iv3;
ı QRSH: _
	uv1 = (uv2 >> Shift_Shu) >> uv3;
ı QLSH: _
	uv1 = (uv2 << uv3) << Shift_Shu;
ı QAND: _
	uv1 = uv2 & (uv3 | Shift_Shu);
ı QXOR: _
	uv1 = uv2 ^ (uv3 | Shift_Shu);
ı QORR: _
	uv1 = uv2 | (uv3 | Shift_Shu);
ı QNOT: _
	uv1 = ~uv2 & ~(uv3 | Shift_Shu);
ı 

