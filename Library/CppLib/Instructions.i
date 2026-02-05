ı HALT:;
	if (!VMFinish(r, Op)) goto EXIT;
ı TAIL:;
	TailStack(vm, r, Code, Op);
ı KNST2:;
	LoadConst(r, Op, *Code++);
ı KNST3:;
	LoadConst(r, Op, *((uint64 *)(Code)));
	Code += 2;
ı FNC:;
	Code = BumpStack(vm, r, Code + 1, Op, *Code);
ı FNC3:;
	Code = BumpStack(vm, r, Code + 2, Op, Code64);
ı FNCX:;
	ForeignFunc(vm, Code, r, Op, *Code);
	Code++;
ı FNCX3:;
	ForeignFunc(vm, Code, r, Op, Code64);
	Code += 2;
ı TRAP:;
	((0));
ı NOOP:;
	i1 = i1;
	// NOOP

ı DUMB:;
	0;
ı TIME:;
	Time_(r, Op);
ı CONV:;
	RegConv(r, Op);
ı FEET:;
	u1 = 0;
ı GRAB:;
	u1 = (uint64)(&u2);
ı RET:;
	Code = ReturnFromFunc(vm, r, Op);
ı AFNC:;
	i1 = FuncAddr(vm, Op, Code);
ı ALLO:;
	AllocStack(vm, r, Op);
ı KNSR:;
	RotateConst(r, Op);
ı KNST:;
	LoadConst(r, Op, 0);
ı ADDB:;
	i1 = i1 + (U1_Li << 12);
ı ADDK:;
	i1 = i2 + U2_Li;
ı ADAK:;
	i1 = i2;
	i2 = i2 + U2_Li;
ı MULK:;
	i1 = i2 * U2_Li;
ı ADD:;
	i1 = i2 + (i3 << Shift_Shu);
ı SUB:;
	i1 = (i2 - i3) >> Shift_Shu;
ı MUL:;
	i1 = (i2 * i3) + i4;
ı DIV:;
	DivMath(r, Op);
ı DIV2:;
	i1 = Div2(i2, Div2_Clearu, Div2_Downu);
ı ICLM:;
	i1 = std_clamp(btc(i2), btc(i3), btc(i4));
ı UCLM:;
	u1 = std_clamp(btc(u2), btc(u3), btc(u4));
ı ADDM:;
	i1 = i2 + (ii3 << AddOrSubM_Shu);
ı SUBM:;
	i1 = (i2 - ii3) >> AddOrSubM_Shu;
ı DIVS:;
	DivMath32(r, Op);
ı MULS:;
	i1 = (ii2 * ii3) + ii4;
ı BFLG:;
	if (BFLD_signu)
	i1 = ((i2 << BFLD_upu) >> BFLD_downu)
;
	else
	u1 = ((u2 << BFLD_upu) >> BFLD_downu)
;
ı BFLS:;
	u1 = u2 | (u3 << Shift_Shu);
ı BRSS:;
	i1 = ((i2 << Shift_Shu) >> Shift_Shu) >> i3;
ı BRSH:;
	u1 = ((u2 << Shift_Shu) >> Shift_Shu) >> u3;
ı BLSH:;
	u1 = ((u2 << u3) << Shift_Shu) >> Shift_Shu;
ı BAND:;
	u1 = u2 & ((u3 << Shift_Shu) >> Shift_Shu);
ı BORR:;
	u1 = u2 | ((u3 << Shift_Shu) >> Shift_Shu);
ı BXOR:;
	u1 = u2 ^ ((u3 << Shift_Shu) >> Shift_Shu);
ı BNOT:;
	u1 = ~u2 & ((~u3 << Shift_Shu) >> Shift_Shu);
ı BANK:;
	u1 = u2 & U2_Li;
ı BORK:;
	u1 = u2 | U2_Li;
ı BXRK:;
	u1 = u2 ^ U2_Li;
ı EQUL:;
	u1 = BitComp(r, Op);
ı TERN:;
	if (u2)
	r[n1] = r[n3]
;
	else
	r[n1] = r[n4]
;
ı CMPI:;
	CompI(r, Op);
ı CMPF:;
	CompF(r, Op);
ı JUMP:;
	Code += l0;
ı JMPI:;
	Code = JumpI(r, Op, Code);
ı JMPF:;
	Code = JumpF(r, Op, Code);
ı JMPE:;
	Code = JumpEq(r, Op, Code);
ı JMPN:;
	Code = JumpNeq(r, Op, Code);
ı JMKM:;
	Code = JumpK(r, Op, Code);
ı JMKL:;
	Code = JumpKN(r, Op, Code);
ı JMKE:;
	Code = JumpKE(r, Op, Code);
ı JMKN:;
	Code = JumpKNE(r, Op, Code);
ı JBOR:;
	if (u1 << (Bra_Smallu << 5))
	Code += Bra_Jmpi
;
ı JBAN:;
	if (!(u1 << (Bra_Smallu << 5)))
	Code += Bra_Jmpi
;
ı LUPU:;
	if (ii1++ < ii2)
	Code += Loop_Jmpi
;
ı LUPD:;
	if (ii1-- > ii2)
	Code += Loop_Jmpi
;
ı RFUN:;
	SetRefApart(r, Op);
ı RFST:;
	SetRefBasic(r, Op);
ı RFWR:;
	SetRefRegToMem(r, Op);
ı RFRD:;
	SetRefMemToReg(r, Op);
ı RALO:;
	o1 = alloc(o2);
ı RFRT:;
	Code = DeRefRegs(vm, r, Op);
ı GOBJ:;
	o1 = strs(vm, Op);
ı GTAB:;
	u1 = table(vm, Op);
ı RD1U:;
	u1 = mem1(uint8);
	mem2(uint8);
ı RD1S:;
	u1 = mem1(char);
	mem2(char);
ı RD2U:;
	u1 = mem1(u16);
	mem2(u16);
ı RD2S:;
	u1 = mem1(s16);
	mem2(s16);
ı RD4U:;
	u1 = mem1(u32);
	mem2(u32);
ı RD4S:;
	u1 = mem0(int);
	mem2(int);
ı RD8U:;
	u1 = mem1(u64);
	mem2(u64);
ı RD16:;
	((ivec4 *) r)[n1] = mem1(ivec4);
	mem2(ivec4);
ı WR1U:;
	mem1(uint8) = u1;
	mem2(uint8);
ı WR2U:;
	mem1(u16) = u1;
	mem2(u16);
ı WR4U:;
	//  xcode only complains about this one? ?

	mem1(u32) = (u32) u1;
	mem2(u32);
ı WR8U:;
	mem1(u64) = u1;
	mem2(u64);
ı WR16:;
	mem1(ivec4) = (ivec4)(((ivec4 *) r)[n1]);
	mem2(ivec4);
ı CNTC:;
	IncrementAddr(r, Op, 1);
ı CNTD:;
	IncrementAddr(r, Op, 0);
ı WCPY:;
	MemCopyRDWR(r, Op);
ı FADD:;
	if (!Float_Du)
	d1 = d2 + d3 - d4
;
	else
	f1 = f2 + f3 - f4
;
ı FADK:;
	f1 += f2 + FloatIncr1(Op);
ı FMUL:;
	if (!Float_Du)
	d1 = (d2 * d3) + d4
;
	else
	f1 = (f2 * f3) + f4
;
ı FMLK:;
	f1 = f2 * FloatIncr1(Op);
ı FDIV:;
	if (!Float_Du)
	d1 = d2 / d3
;
	else
	f1 = f2 / f3
;
ı FMOD:;
	if (!Float_Du)
	d1 = fmod(d2, d3)
;
	else
	f1 = fmodf(f2, f3)
;
ı FMAX:;
	if (!Float_Du)
	d1 = std_max(d2, d3)
;
	else
	f1 = std_max(f2, f3)
;
ı FMIN:;
	if (!Float_Du)
	d1 = std_min(d2, d3)
;
	else
	f1 = std_min(f2, f3)
;
ı FCLM:;
	if (!Float_Du)
	d1 = std_clamp(d2, d3, d4)
;
	else
	f1 = std_clamp(f2, f3, f4)
;
ı VGET:;
	i1 = iv2[u3 + n4];
ı VSET:;
	iv1[u3 + n4] = i2;
ı VBLD:;
	v1 = VBuild(r, Op);
ı VSWZ:;
	v1 = VSwiz(r, Op);
ı VMOV:;
	iv1 = iv2;
	iv3 = iv4;
ı VADD:;
	v1 = v2 + v3 - v4;
ı VADK:;
	v1 += v2 + FloatIncr1(Op);
ı VMUL:;
	v1 = (v2 * v3) + v4;
ı VMLK:;
	v1 = v2 * FloatIncr1(Op);
ı VDIV:;
	v1 = v2 / v3;
ı VMOD:;
	v1 = JB_vec4_Mod(v2, v3);
ı VMAX:;
	v1 = JB_vec4_Max(v2, v3);
ı VMIN:;
	v1 = JB_vec4_Min(v2, v3);
ı QADD:;
	iv1 = iv2 + (iv3 << Shift_Shu);
ı QSUB:;
	iv1 = (iv2 - iv3) >> Shift_Shu;
ı QADK:;
	iv1 = iv2 + U2_Li;
ı QMUL:;
	iv1 = (iv2 * iv3) + iv4;
ı QDIV:;
	iv1 = iv2 / iv3;
ı QCLM:;
	iv1 = JB_ivec4_ClampVec(iv2, iv3, iv4);
ı QINC:;
	QInc(r, Op);
ı QFLG:;
	iv1 = ((iv2 << BFLD_upu) >> BFLD_downu);
ı QFLS:;
	iv1 |= ((iv2 << BFLD_upu) >> BFLD_downu);
ı QRSS:;
	iv1 = (iv2 >> Shift_Shu) >> iv3;
ı QRSH:;
	uv1 = (uv2 >> Shift_Shu) >> uv3;
ı QLSH:;
	uv1 = (uv2 << uv3) << Shift_Shu;
ı QAND:;
	uv1 = uv2 & (uv3 | Shift_Shu);
ı QXOR:;
	uv1 = uv2 ^ (uv3 | Shift_Shu);
ı QORR:;
	uv1 = uv2 | (uv3 | Shift_Shu);
ı QNOT:;
	uv1 = ~uv2 & ~(uv3 | Shift_Shu);
ı QCNV:;
	VecConv(r, Op);
ı BSTT:;
	u1 = bitstats(u2, U2_Li);
ı FFRC:;
	f1 = JB_f_Fract(f2);
ı FFLR:;
	f1 = floorf(f2);
ı FRND:;
	f1 = roundf(f2);
ı FLNG:;
	f1 = JB_f_Length(f2);
ı FABS:;
	f1 = fabsf(f2);
ı FPOW:;
	f1 = powf(f2, f3);
ı FSQT:;
	f1 = sqrtf(f2);
ı FEXP:;
	f1 = expf(f2);
ı FLOG:;
	f1 = logf(f2);
ı FXP2:;
	f1 = exp2f(f2);
ı FLG2:;
	f1 = log2f(f2);
ı FNIS:;
	f1 = JB_f_Unsin(f2);
ı FSOC:;
	f1 = JB_f_Uncos(f2);
ı FNAT:;
	f1 = JB_f_UnTan(f2, f3);
ı FSIN:;
	f1 = JB_f_Sine(f2);
ı FCOS:;
	f1 = JB_f_Cos(f2);
ı FTAN:;
	f1 = JB_f_Tan(f2);
ı FSGN:;
	f1 = copysignf(f2, f3);
ı FMIX:;
	f1 = JB_f_FloatMix(f2, f3, f4);
ı FSMS:;
	f1 = JB_f_SmoothStep(f2, f3, f4);
ı FXNN:;
	f1 = __isnanf(f2);
ı FXNF:;
	f1 = __isinff(f2);
ı VFRC:;
	v1 = JB_vec4_Fract(v2);
ı VFLR:;
	v1 = JB_vec4_Floor(v2);
ı VRND:;
	v1 = JB_vec4_Round(v2);
ı VLNG:;
	f1 = JB_vec4_Length(v2);
ı VABS:;
	v1 = JB_vec4_Abs(v2);
ı VPOW:;
	v1 = JB_vec4_Pow(v2, v3);
ı VSQT:;
	v1 = JB_vec4_Sqrt(v2);
ı VEXP:;
	v1 = JB_vec4_Exp(v2);
ı VLOG:;
	v1 = JB_vec4_Log(v2);
ı VXP2:;
	v1 = JB_vec4_Exp2(v2);
ı VLG2:;
	v1 = JB_vec4_Log2(v2);
ı VNIS:;
	v1 = JB_vec4_Unsin(v2);
ı VSOC:;
	v1 = JB_vec4_Uncos(v2);
ı VNAT:;
	v1 = JB_vec4_UnTan(v2, v3);
ı VSIN:;
	v1 = JB_vec4_Sine(v2);
ı VCOS:;
	v1 = JB_vec4_Cos(v2);
ı VTAN:;
	v1 = JB_vec4_Tan(v2);
ı VSGN:;
	v1 = JB_vec4_CopySign(v2, v3);
ı VCLM:;
	v1 = JB_vec4_Clamp(v2, v3, v4);
ı VMIX:;
	v1 = JB_vec4_Mix(v2, v3, v4);
ı VSMS:;
	v1 = JB_vec4_SmoothStep(v2, v3, v4);
ı VDOT:;
	f1 = JB_vec4_Dot(v2, v3);
ı VCRS:;
	v1 = JB_vec4_Cross(v2, v3);
ı VRFL:;
	v1 = JB_vec4_Reflect(v2, v3);
ı VSUM:;
	f1 = JB_vec4_Sum(v2);
ı MARK:;
	0;
ı 

