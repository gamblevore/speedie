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
ı TRAP: _
	0;
ı NOOP: _
	i1 = i1;
	// NOOP

ı DUMB: _
	0;
ı TIME: _
	Time_(r, Op);
ı CONV: _
	RegConv(r, Op);
ı FEET: _
	u1 = 0;
ı GRAB: _
	u1 = (uint64)(&u2);
ı RET: _
	Code = ReturnFromFunc(vm, r, Op);
ı AFNC: _
	i1 = FuncAddr(vm, Op, Code);
ı ALLO: _
	AllocStack(vm, r, Op);
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
ı ICLM: _
	i1 = std_clamp(btc(i2), btc(i3), btc(i4));
ı UCLM: _
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
ı BFLS: _
	u1 = u2 | (u3 << Shift_Shu);
ı BRSS: _
	i1 = ((i2 << Shift_Shu) >> Shift_Shu) >> i3;
ı BRSH: _
	u1 = ((u2 << Shift_Shu) >> Shift_Shu) >> u3;
ı BLSH: _
	u1 = ((u2 << u3) << Shift_Shu) >> Shift_Shu;
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
ı WCPY: _
	MemCopyRDWR(r, Op);
ı FADD: _
	if (!Float_Du)
	d1 = d2 + d3 - d4
;
	else
	f1 = f2 + f3 - f4
;
ı FADK: _
	f1 += f2 + FloatIncr1(Op);
ı FMUL: _
	if (!Float_Du)
	d1 = (d2 * d3) + d4
;
	else
	f1 = (f2 * f3) + f4
;
ı FMLK: _
	f1 = f2 * FloatIncr1(Op);
ı FDIV: _
	if (!Float_Du)
	d1 = d2 / d3
;
	else
	f1 = f2 / f3
;
ı FMOD: _
	if (!Float_Du)
	d1 = fmod(d2, d3)
;
	else
	f1 = fmodf(f2, f3)
;
ı FMAX: _
	if (!Float_Du)
	d1 = std_max(d2, d3)
;
	else
	f1 = std_max(f2, f3)
;
ı FMIN: _
	if (!Float_Du)
	d1 = std_min(d2, d3)
;
	else
	f1 = std_min(f2, f3)
;
ı FCLM: _
	if (!Float_Du)
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
ı VMOD: _
	v1 = JB_vec4_Mod(v2, v3);
ı VMAX: _
	v1 = JB_vec4_Max(v2, v3);
ı VMIN: _
	v1 = JB_vec4_Min(v2, v3);
ı QADD: _
	iv1 = iv2 + (iv3 << Shift_Shu);
ı QSUB: _
	iv1 = (iv2 - iv3) >> Shift_Shu;
ı QADK: _
	iv1 = iv2 + U2_Li;
ı QMUL: _
	iv1 = (iv2 * iv3) + iv4;
ı QDIV: _
	iv1 = iv2 / iv3;
ı QCLM: _
	iv1 = JB_ivec4_ClampVec(iv2, iv3, iv4);
ı QINC: _
	i1 = iv2[VecInc_partu] + VecInc_Amounti;
	iv2[VecInc_partu] = i1;
ı QFLG: _
	iv1 = ((iv2 << BFLD_upu) >> BFLD_downu);
ı QFLS: _
	iv1 |= ((iv2 << BFLD_upu) >> BFLD_downu);
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
ı QCNV: _
	VecConv(r, Op);
ı BSTT: _
	u1 = bitstats(u2, U2_Li);
ı FFRC: _
	f1 = JB_f_Fract(f2);
ı FFLR: _
	f1 = floorf(f2);
ı FRND: _
	f1 = roundf(f2);
ı FLNG: _
	f1 = JB_f_Length(f2);
ı FABS: _
	f1 = fabsf(f2);
ı FPOW: _
	f1 = powf(f2, f3);
ı FSQT: _
	f1 = sqrtf(f2);
ı FEXP: _
	f1 = expf(f2);
ı FLOG: _
	f1 = logf(f2);
ı FXP2: _
	f1 = exp2f(f2);
ı FLG2: _
	f1 = log2f(f2);
ı FNIS: _
	f1 = JB_f_Unsin(f2);
ı FSOC: _
	f1 = JB_f_Uncos(f2);
ı FNAT: _
	f1 = JB_f_UnTan(f2, f3);
ı FSIN: _
	f1 = JB_f_Sine(f2);
ı FCOS: _
	f1 = JB_f_Cos(f2);
ı FTAN: _
	f1 = JB_f_Tan(f2);
ı FSGN: _
	f1 = copysignf(f2, f3);
ı FMIX: _
	f1 = JB_f_FloatMix(f2, f3, f4);
ı FSMS: _
	f1 = JB_f_SmoothStep(f2, f3, f4);
ı FXNN: _
	f1 = __isnanf(f2);
ı FXNF: _
	f1 = __isinff(f2);
ı VFRC: _
	v1 = JB_vec4_Fract(v2);
ı VFLR: _
	v1 = JB_vec4_Floor(v2);
ı VRND: _
	v1 = JB_vec4_Round(v2);
ı VLNG: _
	f1 = JB_vec4_Length(v2);
ı VABS: _
	v1 = JB_vec4_Abs(v2);
ı VPOW: _
	v1 = JB_vec4_Pow(v2, v3);
ı VSQT: _
	v1 = JB_vec4_Sqrt(v2);
ı VEXP: _
	v1 = JB_vec4_Exp(v2);
ı VLOG: _
	v1 = JB_vec4_Log(v2);
ı VXP2: _
	v1 = JB_vec4_Exp2(v2);
ı VLG2: _
	v1 = JB_vec4_Log2(v2);
ı VNIS: _
	v1 = JB_vec4_Unsin(v2);
ı VSOC: _
	v1 = JB_vec4_Uncos(v2);
ı VNAT: _
	v1 = JB_vec4_UnTan(v2, v3);
ı VSIN: _
	v1 = JB_vec4_Sine(v2);
ı VCOS: _
	v1 = JB_vec4_Cos(v2);
ı VTAN: _
	v1 = JB_vec4_Tan(v2);
ı VSGN: _
	v1 = JB_vec4_CopySign(v2, v3);
ı VCLM: _
	v1 = JB_vec4_Clamp(v2, v3, v4);
ı VMIX: _
	v1 = JB_vec4_Mix(v2, v3, v4);
ı VSMS: _
	v1 = JB_vec4_SmoothStep(v2, v3, v4);
ı VDOT: _
	f1 = JB_vec4_Dot(v2, v3);
ı VCRS: _
	v1 = JB_vec4_Cross(v2, v3);
ı VRFL: _
	v1 = JB_vec4_Reflect(v2, v3);
ı VSUM: _
	f1 = JB_vec4_Sum(v2);
ı 

Dı DEROR: _
	if (u2 == u1 and u3 == u4)
	VMFinish
;
Dı DTAIL: _
	TailStack(vm, r, Code, Op);
Dı DKNST2: _
	LoadConst(r, Op, *Code++);
Dı DKNST3: _
	LoadConst(r, Op, *((uint64 *)(Code)));
	Code += 2;
Dı DFNC: _
	Code = BumpStack(vm, r, Code + 1, Op, *Code);
Dı DFNC3: _
	Code = BumpStack(vm, r, Code + 2, Op, Code64);
Dı DFNCX: _
	ForeignFunc(vm, Code, r, Op, *Code);
	Code++;
Dı DFNCX3: _
	ForeignFunc(vm, Code, r, Op, Code64);
	Code += 2;
Dı DTRAP: _
	0;
Dı DNOOP: _
	i1 = i1;
	// NOOP

Dı DDUMB: _
	0;
Dı DTIME: _
	Time_(r, Op);
Dı DCONV: _
	RegConv(r, Op);
Dı DFEET: _
	u1 = 0;
Dı DGRAB: _
	u1 = (uint64)(&u2);
Dı DRET: _
	Code = ReturnFromFunc(vm, r, Op);
Dı DAFNC: _
	i1 = FuncAddr(vm, Op, Code);
Dı DALLO: _
	AllocStack(vm, r, Op);
Dı DKNSR: _
	RotateConst(r, Op);
Dı DKNST: _
	LoadConst(r, Op, 0);
Dı DADDB: _
	i1 = i1 + (U1_Li << 12);
Dı DADDK: _
	i1 = i2 + U2_Li;
Dı DADAK: _
	i1 = i2;
	i2 = i2 + U2_Li;
Dı DMULK: _
	i1 = i2 * U2_Li;
Dı DADD: _
	i1 = i2 + (i3 << Shift_Shu);
Dı DSUB: _
	i1 = (i2 - i3) >> Shift_Shu;
Dı DMUL: _
	i1 = (i2 * i3) + i4;
Dı DDIV: _
	DivMath(r, Op);
Dı DDIV2: _
	if (i2 < 0)
	i1 = (((i2 + ((1 << Div2_Shu) - 1)) >> Div2_Shu) << Div2_Clearu) >> Div2_Clearu
;
	else
	i1 = ((i2 >> Div2_Shu) << Div2_Clearu) >> Div2_Clearu
;
Dı DICLM: _
	i1 = std_clamp(btc(i2), btc(i3), btc(i4));
Dı DUCLM: _
	u1 = std_clamp(btc(u2), btc(u3), btc(u4));
Dı DADDM: _
	i1 = i2 + (ii3 << AddOrSubM_Shu);
Dı DSUBM: _
	i1 = (i2 - ii3) >> AddOrSubM_Shu;
Dı DDIVS: _
	DivMath32(r, Op);
Dı DMULS: _
	i1 = (ii2 * ii3) + ii4;
Dı DBFLG: _
	if (BFLD_signu)
	i1 = ((i2 << BFLD_upu) >> BFLD_downu)
;
	else
	u1 = ((u2 << BFLD_upu) >> BFLD_downu)
;
Dı DBFLS: _
	u1 = u2 | (u3 << Shift_Shu);
Dı DBRSS: _
	i1 = ((i2 << Shift_Shu) >> Shift_Shu) >> i3;
Dı DBRSH: _
	u1 = ((u2 << Shift_Shu) >> Shift_Shu) >> u3;
Dı DBLSH: _
	u1 = ((u2 << u3) << Shift_Shu) >> Shift_Shu;
Dı DBAND: _
	u1 = u2 & ((u3 << Shift_Shu) >> Shift_Shu);
Dı DBORR: _
	u1 = u2 | ((u3 << Shift_Shu) >> Shift_Shu);
Dı DBXOR: _
	u1 = u2 ^ ((u3 << Shift_Shu) >> Shift_Shu);
Dı DBNOT: _
	u1 = ~u2 & ((~u3 << Shift_Shu) >> Shift_Shu);
Dı DBANK: _
	u1 = u2 & U2_Li;
Dı DBORK: _
	u1 = u2 | U2_Li;
Dı DBXRK: _
	u1 = u2 ^ U2_Li;
Dı DEQUL: _
	u1 = BitComp(r, Op);
Dı DTERN: _
	if (u2)
	r[n1] = r[n3]
;
	else
	r[n1] = r[n4]
;
Dı DCMPI: _
	CompI(r, Op);
Dı DCMPF: _
	CompF(r, Op);
Dı DJUMP: _
	Code += l0;
Dı DJMPI: _
	Code = JumpI(r, Op, Code);
Dı DJMPF: _
	Code = JumpF(r, Op, Code);
Dı DJMPE: _
	Code = JumpEq(r, Op, Code);
Dı DJMPN: _
	Code = JumpNeq(r, Op, Code);
Dı DJMKM: _
	Code = JumpK(r, Op, Code);
Dı DJMKL: _
	Code = JumpKN(r, Op, Code);
Dı DJMKE: _
	Code = JumpKE(r, Op, Code);
Dı DJMKN: _
	Code = JumpKNE(r, Op, Code);
Dı DJBOR: _
	if (u1 << (Bra_Smallu << 5))
	Code += Bra_Jmpi
;
Dı DJBAN: _
	if (!(u1 << (Bra_Smallu << 5)))
	Code += Bra_Jmpi
;
Dı DLUPU: _
	if (ii1++ < ii2)
	Code += Loop_Jmpi
;
Dı DLUPD: _
	if (ii1-- > ii2)
	Code += Loop_Jmpi
;
Dı DRFUN: _
	SetRefApart(r, Op);
Dı DRFST: _
	SetRefBasic(r, Op);
Dı DRFWR: _
	SetRefRegToMem(r, Op);
Dı DRFRD: _
	SetRefMemToReg(r, Op);
Dı DRALO: _
	o1 = alloc(o2);
Dı DRFRT: _
	Code = DeRefRegs(vm, r, Op);
Dı DGOBJ: _
	o1 = strs(vm, Op);
Dı DGTAB: _
	u1 = table(vm, Op);
Dı DRD1U: _
	u1 = mem1(uint8);
	mem2(uint8);
Dı DRD1S: _
	u1 = mem1(char);
	mem2(char);
Dı DRD2U: _
	u1 = mem1(u16);
	mem2(u16);
Dı DRD2S: _
	u1 = mem1(s16);
	mem2(s16);
Dı DRD4U: _
	u1 = mem1(u32);
	mem2(u32);
Dı DRD4S: _
	u1 = mem0(int);
	mem2(int);
Dı DRD8U: _
	u1 = mem1(u64);
	mem2(u64);
Dı DRD16: _
	((ivec4 *) r)[n1] = mem1(ivec4);
	mem2(ivec4);
Dı DWR1U: _
	mem1(uint8) = u1;
	mem2(uint8);
Dı DWR2U: _
	mem1(u16) = u1;
	mem2(u16);
Dı DWR4U: _
	//  xcode only complains about this one? ?

	mem1(u32) = (u32) u1;
	mem2(u32);
Dı DWR8U: _
	mem1(u64) = u1;
	mem2(u64);
Dı DWR16: _
	mem1(ivec4) = (ivec4)(((ivec4 *) r)[n1]);
	mem2(ivec4);
Dı DCNTC: _
	IncrementAddr(r, Op, 1);
Dı DCNTD: _
	IncrementAddr(r, Op, 0);
Dı DWCPY: _
	MemCopyRDWR(r, Op);
Dı DFADD: _
	if (!Float_Du)
	d1 = d2 + d3 - d4
;
	else
	f1 = f2 + f3 - f4
;
Dı DFADK: _
	f1 += f2 + FloatIncr1(Op);
Dı DFMUL: _
	if (!Float_Du)
	d1 = (d2 * d3) + d4
;
	else
	f1 = (f2 * f3) + f4
;
Dı DFMLK: _
	f1 = f2 * FloatIncr1(Op);
Dı DFDIV: _
	if (!Float_Du)
	d1 = d2 / d3
;
	else
	f1 = f2 / f3
;
Dı DFMOD: _
	if (!Float_Du)
	d1 = fmod(d2, d3)
;
	else
	f1 = fmodf(f2, f3)
;
Dı DFMAX: _
	if (!Float_Du)
	d1 = std_max(d2, d3)
;
	else
	f1 = std_max(f2, f3)
;
Dı DFMIN: _
	if (!Float_Du)
	d1 = std_min(d2, d3)
;
	else
	f1 = std_min(f2, f3)
;
Dı DFCLM: _
	if (!Float_Du)
	d1 = std_clamp(d2, d3, d4)
;
	else
	f1 = std_clamp(f2, f3, f4)
;
Dı DVGET: _
	i1 = iv2[n3 + u4];
Dı DVSET: _
	iv1[n3 + u4] = i2;
Dı DVBLD: _
	v1 = VBuild(r, Op);
Dı DVSWZ: _
	v1 = VSwiz(r, Op);
Dı DVMOV: _
	iv1 = iv2;
	iv3 = iv4;
Dı DVADD: _
	v1 = v2 + v3 - v4;
Dı DVADK: _
	v1 += v2 + FloatIncr1(Op);
Dı DVMUL: _
	v1 = (v2 * v3) + v4;
Dı DVMLK: _
	v1 = v2 * FloatIncr1(Op);
Dı DVDIV: _
	v1 = v2 / v3;
Dı DVMOD: _
	v1 = JB_vec4_Mod(v2, v3);
Dı DVMAX: _
	v1 = JB_vec4_Max(v2, v3);
Dı DVMIN: _
	v1 = JB_vec4_Min(v2, v3);
Dı DQADD: _
	iv1 = iv2 + (iv3 << Shift_Shu);
Dı DQSUB: _
	iv1 = (iv2 - iv3) >> Shift_Shu;
Dı DQADK: _
	iv1 = iv2 + U2_Li;
Dı DQMUL: _
	iv1 = (iv2 * iv3) + iv4;
Dı DQDIV: _
	iv1 = iv2 / iv3;
Dı DQCLM: _
	iv1 = JB_ivec4_ClampVec(iv2, iv3, iv4);
Dı DQINC: _
	i1 = iv2[VecInc_partu] + VecInc_Amounti;
	iv2[VecInc_partu] = i1;
Dı DQFLG: _
	iv1 = ((iv2 << BFLD_upu) >> BFLD_downu);
Dı DQFLS: _
	iv1 |= ((iv2 << BFLD_upu) >> BFLD_downu);
Dı DQRSS: _
	iv1 = (iv2 >> Shift_Shu) >> iv3;
Dı DQRSH: _
	uv1 = (uv2 >> Shift_Shu) >> uv3;
Dı DQLSH: _
	uv1 = (uv2 << uv3) << Shift_Shu;
Dı DQAND: _
	uv1 = uv2 & (uv3 | Shift_Shu);
Dı DQXOR: _
	uv1 = uv2 ^ (uv3 | Shift_Shu);
Dı DQORR: _
	uv1 = uv2 | (uv3 | Shift_Shu);
Dı DQNOT: _
	uv1 = ~uv2 & ~(uv3 | Shift_Shu);
Dı DQCNV: _
	VecConv(r, Op);
Dı DBSTT: _
	u1 = bitstats(u2, U2_Li);
Dı DFFRC: _
	f1 = JB_f_Fract(f2);
Dı DFFLR: _
	f1 = floorf(f2);
Dı DFRND: _
	f1 = roundf(f2);
Dı DFLNG: _
	f1 = JB_f_Length(f2);
Dı DFABS: _
	f1 = fabsf(f2);
Dı DFPOW: _
	f1 = powf(f2, f3);
Dı DFSQT: _
	f1 = sqrtf(f2);
Dı DFEXP: _
	f1 = expf(f2);
Dı DFLOG: _
	f1 = logf(f2);
Dı DFXP2: _
	f1 = exp2f(f2);
Dı DFLG2: _
	f1 = log2f(f2);
Dı DFNIS: _
	f1 = JB_f_Unsin(f2);
Dı DFSOC: _
	f1 = JB_f_Uncos(f2);
Dı DFNAT: _
	f1 = JB_f_UnTan(f2, f3);
Dı DFSIN: _
	f1 = JB_f_Sine(f2);
Dı DFCOS: _
	f1 = JB_f_Cos(f2);
Dı DFTAN: _
	f1 = JB_f_Tan(f2);
Dı DFSGN: _
	f1 = copysignf(f2, f3);
Dı DFMIX: _
	f1 = JB_f_FloatMix(f2, f3, f4);
Dı DFSMS: _
	f1 = JB_f_SmoothStep(f2, f3, f4);
Dı DFXNN: _
	f1 = __isnanf(f2);
Dı DFXNF: _
	f1 = __isinff(f2);
Dı DVFRC: _
	v1 = JB_vec4_Fract(v2);
Dı DVFLR: _
	v1 = JB_vec4_Floor(v2);
Dı DVRND: _
	v1 = JB_vec4_Round(v2);
Dı DVLNG: _
	f1 = JB_vec4_Length(v2);
Dı DVABS: _
	v1 = JB_vec4_Abs(v2);
Dı DVPOW: _
	v1 = JB_vec4_Pow(v2, v3);
Dı DVSQT: _
	v1 = JB_vec4_Sqrt(v2);
Dı DVEXP: _
	v1 = JB_vec4_Exp(v2);
Dı DVLOG: _
	v1 = JB_vec4_Log(v2);
Dı DVXP2: _
	v1 = JB_vec4_Exp2(v2);
Dı DVLG2: _
	v1 = JB_vec4_Log2(v2);
Dı DVNIS: _
	v1 = JB_vec4_Unsin(v2);
Dı DVSOC: _
	v1 = JB_vec4_Uncos(v2);
Dı DVNAT: _
	v1 = JB_vec4_UnTan(v2, v3);
Dı DVSIN: _
	v1 = JB_vec4_Sine(v2);
Dı DVCOS: _
	v1 = JB_vec4_Cos(v2);
Dı DVTAN: _
	v1 = JB_vec4_Tan(v2);
Dı DVSGN: _
	v1 = JB_vec4_CopySign(v2, v3);
Dı DVCLM: _
	v1 = JB_vec4_Clamp(v2, v3, v4);
Dı DVMIX: _
	v1 = JB_vec4_Mix(v2, v3, v4);
Dı DVSMS: _
	v1 = JB_vec4_SmoothStep(v2, v3, v4);
Dı DVDOT: _
	f1 = JB_vec4_Dot(v2, v3);
Dı DVCRS: _
	v1 = JB_vec4_Cross(v2, v3);
Dı DVRFL: _
	v1 = JB_vec4_Reflect(v2, v3);
Dı DVSUM: _
	f1 = JB_vec4_Sum(v2);
Dı 

