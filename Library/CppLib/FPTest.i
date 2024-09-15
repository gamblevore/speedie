

int64 fpTestInt6 (int A, int64 I, char C, byte B, short S, u16 U) {
	printf("%X, %llX, %i, %i, %i, %i\n", A, I, C, B, S, U);
	return A;
}
int fpTestInt5 (int A, int64 I, char C, byte B, short S) {
	printf("%X, %llX, %i, %i, %i\n", A, I, C, B, S);
	return A;
}
int64 fpTestInt4 (int A, int64 I, char C, byte B) {
	printf("%X, %llX, %i, %i\n", A, I, C, B);
	return A;
}
int fpTestInt3 (int A, int64 I, char C) {
	printf("%X, %llX, %i\n", A, I, C);
	return A;
}
int64 fpTestInt2 (int A, int64 I) {
	printf("%X, %llX\n", A, I);
	return A;
}
int fpTestInt1 (int A) {
	printf("%X\n", A);
	return A;
}
int64 fpTestInt0 () {
	return (((int64)(INT_MAX))+1)*2;
}


double fpTestFloat6 (float A, double B, float C, double D, float E, double F) {
	printf("%f, %f, %e, %f, %e, %f\n", A, B, C, D, E, F);
	return A;
}
double fpTestFloat5 (float A, double B, float C, double D, float E) {
	printf("%f, %f, %e, %f, %e\n", A, B, C, D, E);
	return A;
}
double fpTestFloat4 (float A, double B, float C, double D) {
	printf("%f, %f, %e, %f\n", A, B, C, D);
	return A;
}
double fpTestFloat3 (float A, double B, float C) {
	printf("%f, %f, %e\n", A, B, C);
	return A;
}
double fpTestFloat2 (float A, double B) {
	printf("%f, %f\n", A, B);
	return A;
}
double fpTestFloat1 (float A) {
	printf("%f\n", A);
	return A;
}
double fpTestFloat0 () {
	return -0.875;
}



int64 fpTestMix6 (int64 A, double B, int64 C, double D, int64 E, double F) {
	printf("%llX, %f, %llX, %f, %llX, %f\n", A, B, C, D, E, F);
	return A;
}
double fpTestMix5 (int64 A, double B, int64 C, double D, int64 E) {
	printf("%llX, %f, %llX, %f, %llX\n", A, B, C, D, E);
	return A;
}
double fpTestMix4 (int64 A, double B, int64 C, double D) {
	printf("%llX, %f, %llX, %f\n", A, B, C, D);
	return A;
}
double fpTestMix3 (int64 A, double B, int64 C) {
	printf("%llX, %f, %llX\n", A, B, C);
	return A;
}
double fpTestMix2 (int64 A, double B) {
	printf("%llX, %f\n", A, B);
	return A;
}
double fpTestMix1 (int64 A) {
	printf("%llX\n", A);
	return A;
}

typedef int64  (*fpTestInts)   (int, int64, char, byte, short, u16);
typedef double (*fpTestFloats) (double, double, double, double, double, double);
typedef int64  (*fpMixed)      (int64, double, int64, double, int64, double);


int FPTest() {
	fpTestInts FP[7] = {fpTestInt6, (fpTestInts)fpTestInt5, (fpTestInts)fpTestInt4, (fpTestInts)fpTestInt3, (fpTestInts)fpTestInt2, (fpTestInts)fpTestInt1, (fpTestInts)fpTestInt0, };

	for (int i = 0; i < 7; i++) { // this does tho
		auto D = FP[i];
		auto E = (D)(0xFACEB00B, (0xB16B00B5ll<<32) + 1, 127, 98, -1000, 20000);
		printf("%llX\n", E);
	}

	fpMixed MFP[7] = {fpTestMix6, (fpMixed)fpTestMix5, (fpMixed)fpTestMix4, (fpMixed)fpTestMix3, (fpMixed)fpTestMix2, (fpMixed)fpTestMix1, (fpMixed)fpTestInt0};
	for (int i = 0; i < 7; i++) { // mixed doesn't seem to play nice. At least, the return doesn't.
		auto D = MFP[i];
		auto E = (D)(0xFACEB00B, 999888777666.5, (0xB16B00B5ll<<32) + 1, 0.00025, 0x7355BEA2, 1.5);
		printf("%llX\n", E);
	}

	fpTestFloats FFP[7] = {(fpTestFloats)fpTestFloat6, (fpTestFloats)fpTestFloat5, (fpTestFloats)fpTestFloat4, (fpTestFloats)fpTestFloat3, (fpTestFloats)fpTestFloat2, (fpTestFloats)fpTestFloat1, (fpTestFloats)fpTestFloat0, };
	
	


	Register Regs[6] = {};
	Regs[0].Float = 0.12345; Regs[1].Double = 999888777666.5; Regs[2].Float = 50000000000000; Regs[3].Double = 0.00025; Regs[4].Float = 0.0000000001; Regs[5].Double = 1.5;
	for (int i = 0; i < 7; i++) { // and this!
		auto D = FFP[i];
		auto E = (D)(Regs[0].Double, Regs[1].Double, Regs[2].Double, Regs[3].Double, Regs[4].Double, Regs[5].Double);
		printf("%f\n", E);
	}

	exit(0);
	return 0;
}
int fptest = FPTest();
