#include "JB_FastString.h"
#include <string>
#include <iostream>
using namespace std;

#define u8 unsigned char
#define ErrP ((u8*)(-1))
#define UnitSize 8
#define CONT true
#define STOP false
#define mUnitSize (UnitSize-1)

#if __BYTE_ORDER == __LITTLE_ENDIAN
	#define u64Sortable(a) __builtin_bswap64(a)
#else
	#define u64Sortable(a) (a)
#endif

 
using std::min;
using std::max;

extern "C" {

void JB_CompFreeNow();

#if false
static void ReportOffset_(int Offset, int Length, int C);
static void ReportEscape_(int Length, int C);
#endif

struct MatchFound {
	int Back;
	int Length;
	int Fixed;
	int Varying;
    operator bool() { return Length; }
    int Cost() { return Fixed+Varying; }
};


struct FastBuff {
	u8*	Write;
	u8*	WriteStart;
	u8* WriteEnd;
	u8*	Read;
	u8*	ReadEnd;
	int Expected;
	inline int Length() {
		return (int)(Write - WriteStart);
	}
};


int ChunkLen_(int x) {
	int y	= JB_Int_Log2(x);
	int x2	= 1<<y;
	return y + (x2 < x);
}



#define DExpect(a,b) if (DErr(a,b)) return ErrP;
#define DReq(a,b,c) if (DErr(a,b)) return c;
inline bool DErr(bool Cond, const char* Err) {
	if (Cond) return false;
	puts(Err); debugger;
	JB_ErrorHandleC(Err, 0, false);
	return true;
}

//
//static bool arr_reserve(FastBuff& B,  JB_String* self,  int Expected,  FastString* fs) {
//	auto Addr	= self->Addr;
//	auto End	= Addr + self->Length;
//
//	int C		= (*Addr++ & 15) + 12;
//	int Chunk	= 1 << C;
//	DReq(Chunk <= 1<<22, "Chunk size too large", 0);
//
//	B.Read		= Addr;
//	B.ReadEnd	= End;
//
//	B.Expected = Expected;
//	B.Write = JB_FS_NeedSpare(fs, B.Expected);
//	DReq (B.Write, "Out of memory", 0);
//	B.WriteStart = fs->ResultPtr + fs->Length; // always the same as B.Write? 
//	B.WriteEnd = B.Write + B.Expected;
//	return true;
//}


////////////////////////////////////////////////////// TESTS ////////////////////////////////////////////////////////////
#if false
int ReportCount = 0;
int ReportTotalInput = 0;
int ReportTotalOutput = 0;
bool AllowReport = false;
void FinishReport () ;
void RestartDecompReport (const char* Name) {
	ReportCount = 0;
	AllowReport = true;
	printf("Decompressing: %s\n", Name);
}
static bool CanReport () {
	if (AllowReport and ReportCount < 2000) {
		ReportCount++;
		return true;
	}
	FinishReport();
	return false;
}
static void ReportOffset_(int Offset, int Length, int C) {
	if (CanReport()) {
		C += 2;
		if (Length >= 10) {C++;}
		if (Length >= 130) {C++;}
		if (Offset > 4096) {C++;}
		ReportTotalInput+=Length;
		ReportTotalOutput+=C;
		printf("Offset: %i, %i\t\t(%i in, %i out, +%i)\n", Offset, Length, ReportTotalInput, ReportTotalOutput, C);
	}
}
static void ReportEscape_(int Length, int C) {
	if (CanReport()) {
		C++;
		if (Length > 16) {C++;}
		if (Length > 256) {C++;} 
		if (Length > 4096) {C++;} 
		ReportTotalInput+=Length;
		ReportTotalOutput+=C+Length;
		printf("Escape: %i\t\t(%i in, %i out, +%i)\n", Length, ReportTotalInput, ReportTotalOutput, C+Length);
	}
}

void FinishReport () {
	AllowReport = false;
}
#endif

}

