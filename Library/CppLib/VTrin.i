
	if (Mode == 0)
		return JB_vec4_Fract(R2);

	if (Mode == 1)
		return JB_vec4_Floor(R2);

	if (Mode == 2)
		return JB_vec4_Round(R2);

	if (Mode == 3)
		return JB_vec4_Length(R2);

	if (Mode == 5)
		return JB_vec4_InvSqrt(R2);

	if (Mode == 6)
		return JB_vec4_Sqrt(R2);

	if (Mode == 7)
		return JB_vec4_Exp(R2);

	if (Mode == 8)
		return JB_vec4_Log(R2);

	if (Mode == 9)
		return JB_vec4_Exp2(R2);

	if (Mode == 10)
		return JB_vec4_Log2(R2);

	if (Mode == 12)
		return JB_vec4_Unsin(R2);

	if (Mode == 13)
		return JB_vec4_Uncos(R2);

	if (Mode == 14)
		return JB_vec4_UnTan(R2);

	if (Mode == 15)
		return JB_vec4_Sine(R2);

	if (Mode == 16)
		return JB_vec4_Cos(R2);

	if (Mode == 17)
		return JB_vec4_Tan(R2);

	if (Mode == 21)
		return JB_vec4_OperatorPow(R2);

	if (Mode == 22)
		return JB_vec4_OperatorMod(R2);

	if (Mode == 23)
		return JB_vec4_OperatorSign(R2);

	if (Mode == 24)
		return JB_vec4_OperatorxE2x80xA2(R2);

	if (Mode == 25)
		return JB_vec4_OperatorCross(R2);

	if (Mode == 30)
		return JB_vec4_Mix(R2);

	if (Mode == 31)
		return JB_vec4_SmoothStep(R2);
