
	if (Mode == 0)
		return JB_f_Fract(R2);

	if (Mode == 1)
		return floorf(R2);

	if (Mode == 2)
		return roundf(R2);

	if (Mode == 3)
		return fabsf(R2);

	if (Mode == 5)
		return JB_f_InvSqrt(R2);

	if (Mode == 6)
		return sqrtf(R2);

	if (Mode == 7)
		return logf(R2);

	if (Mode == 8)
		return expf(R2);

	if (Mode == 9)
		return log2f(R2);

	if (Mode == 10)
		return exp2f(R2);

	if (Mode == 11)
		return powf(R2);

	if (Mode == 12)
		return JB_f_Unsin(R2);

	if (Mode == 13)
		return JB_f_Uncos(R2);

	if (Mode == 14)
		return JB_f_UnTan(R2);

	if (Mode == 15)
		return JB_f_Sine(R2);

	if (Mode == 16)
		return JB_f_Cos(R2);

	if (Mode == 17)
		return JB_f_Tan(R2);

	if (Mode == 18)
		return __isnanf(R2);

	if (Mode == 19)
		return __isinff(R2);

	if (Mode == 24)
		return fmodf(R2);

	if (Mode == 25)
		return copysignf(R2);

	if (Mode == 30)
		return JB_f_FloatMix(R2);

	if (Mode == 31)
		return JB_f_SmoothStep(R2);
