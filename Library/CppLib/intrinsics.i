
	if (Mode == 19)
		return __isinff(R2);

	if (Mode == 18)
		return __isnanf(R2);

	if (Mode == 17)
		return __sinpif(R2);

	if (Mode == 16)
		return __tanpif(R2);

	if (Mode == 15)
		return __cospif(R2);

	if (Mode == 14)
		return atan2f(R2);

	if (Mode == 13)
		return acosf(R2);

	if (Mode == 12)
		return asinf(R2);

	if (Mode == 11)
		return powf(R2);

	if (Mode == 10)
		return fminf(R2);

	if (Mode == 9)
		return fmaxf(R2);

	if (Mode == 8)
		return expf(R2);

	if (Mode == 7)
		return log2f(R2);

	if (Mode == 6)
		return sqrtf(R2);

	if (Mode == 5)
		return JB_f_InvSqrt(R2);

	if (Mode == 4)
		return fdimf(R2);

	if (Mode == 3)
		return fabsf(R2);

	if (Mode == 2)
		return roundf(R2);

	if (Mode == 1)
		return floorf(R2);

	if (Mode == 0)
		return copysignf(R2);
