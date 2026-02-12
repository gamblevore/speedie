
/*
	Copyright (C) 2019 Theodore H. Smith.
*/


/*
Design:
	* 256 OpCodes, including a few variable length opcodes
	* r0 = 0
	* can recursive vm->c->vm! 
*/


#include "JB_Umbrella.hpp"
#define __H__  inline
#include "JB_Vectors.cpp"
#include <sys/mman.h>
#include <setjmp.h>


extern "C" {
jmp_buf 		VMRestorer;
byte			CrashState;
uint			CrashCount;

#ifdef __VM__
#pragma GCC optimize ("Os")

#define kReallyFarOut	-4								// Really far out
#define kTooFarBack		-3								// Gone back. Must be corrupt.
#define kOverFlowStack	-2
#define kStillInRange	-1
#define		VMCodePtr(V)			((ASM*)(((byte*)(V)) + 1024*1024))
#define		CanDebug(V)				(((uint64)(V))>>63)


#include "BitFields.h"
#include "JB_VM.h"
#include "JB_VM_Helpers.i"


#define		ı						Op = *Code++;   goto *JumpTable[Op>>24];
#define		ErrStck					(1<<10)



ivec4* JB_ASM_Registers (CakeVM* V, bool Clear) {
	if_rare (!V)
		return 0;
	auto Ret = V->Registers;
	if (Clear)
		memset(Ret, 0xFE, sizeof(VMRegister)*31);
	return (ivec4*)(Ret+4);
	// stack(halt), r0, stack(main), R0, R1 // don't return R0 cos we don't want them altering it.
}


int JB_ASM_Index (CakeVM* vm, ASM* Code) {
	ASM* Start = VMCodePtr(vm);
	if (Code < Start)
		return -1;
	if (Code >= Start + CakeCodeMax)
		return -1;
	return (int)(Code - Start);
}


int64 JB_ASM_Debug (CakeVM& vm, ASM* Code, VMRegister* r) {
	auto Index = JB_ASM_Index(&vm, Code);
	auto Break = (Code[CakeCodeMax]<<1)>>1;
	return (vm.__VIEW__)(&vm, Index, Break, (ivec4*)r);
}


void JB_ASM_Pause (CakeVM* V) {
	if CanDebug(V) {
		auto J = V->JumpTable;
		void* Pause = J[513];
		for (int i = 0; i < 256; i++)
			J[i] = Pause;
	}
}


int64 JB_ASM_NoBreak (CakeVM* VM, int Code, int BreakValue, ivec4* R) {
	return false;
}


/*
	So...
	
	We need to always have exec's debugger in here. always. for stackoverflow reporting.
	
	That means we need another param for on/off.
*/
 

int* JB_ASM_SetDebug (CakeVM* V, bool On) {
	if_rare (!CanDebug(V))
		return 0;
	auto J = V->JumpTable;
	void* Break = J[512];
	if ((On) != (J[0] == Break)) {
		int i = 256;
		if (On) while (--i >= 0)
			J[i] = Break;
		  else
			memcpy(J, V->OriginalJumpTable, 256*sizeof(void*));
	}
	auto AASM = VMCodePtr(V);
	return (int*)(AASM + CakeCodeMax);
}


 
#define EROR HALT
static ivec4* __CAKE_VM__ (CakeVM& vm, ASM* Code, uint Op) { // __cakevm__, __cakerun__
static void * const GlobalJumpTable[] = {
	#include "InstructionList.h"
	&&TRYBREAK,
	&&PAUSE,
};
    if (Op) {
		vm.OriginalJumpTable = &GlobalJumpTable[0];
		memcpy(vm.JumpTable,     GlobalJumpTable, sizeof(void*)     * 256);
		memcpy(vm.JumpTable+256, GlobalJumpTable, sizeof(GlobalJumpTable));
		return 0;
	}
  
    RegVar(r, r21) = vm.Registers + 3;
    RegVar(JumpTable, r22) = &vm.JumpTable[0];
	Op = *Code++;									// spelled out for debug

	// // // // //  START VM  // // // // // 
	goto *JumpTable[Op>>24];
	#include "Instructions.i"
	EXIT:;
	return &vm.Registers[2].Ivec;
	
	PAUSE:;											// Assume was in debug mode
	++(Code[CakeCodeMax-1]);
	for (int i = 0; i < 256; i++)
		JumpTable[i] = &&TRYBREAK;					// Restore debug mode
	goto BREAK;

	
	TRYBREAK:; {
		auto BreakValue = ++(Code[CakeCodeMax-1]);
		if_usual (!(BreakValue & 0x80000000))
			goto *JumpTable[256+(Op>>24)];			// Resume
		if_rare (!(BreakValue<<1)) {				// Accidental trap from 2GB loop.
			Code[CakeCodeMax-1] = ((~BreakValue>>31)<<31)|0x40000000;// Reset to a big number 
			if (!(vm.VFlags & kJB_VM_TrapTooFar))
				goto *JumpTable[256+(Op>>24)];		// Resume
		}
	}
	
	BREAK:;	{										// The actual breakpoint
		int64 Value = JB_ASM_Debug(vm, Code-1, r);
		if_rare (Value) {
			if (Value >= 256) return 0;				// Should we set an error in the VM?
			if (Value >= 0)   exit((int)Value);
						
			Code += Value;							// Jump back? I guess so?
			if (Code < VMCodePtr(&vm))
				Code -= Value;						// Debugger jumped out of range!!
			  else 
				Op = *Code++;
		}
	}
	
	goto *JumpTable[256+(Op>>24)];					// Resume
}


ivec4* JB_ASM_PrevStack (CakeVM* vm, ivec4* Reg0) {
	if (!Reg0) return 0;
	auto Stack = (VMStack*)(Reg0-1);
	int Saved = Stack->DestReg;
	auto BackStack = Stack - Saved;
	if (BackStack <= &vm->Registers[2].Stack)
		return 0; // last?

	return (ivec4*)(BackStack+1);
}


int JB_ASM_StackCode (CakeVM* vm, ivec4* Reg0) {
	auto Stack = (VMStack*)(Reg0-1);
	return JB_ASM_Index(vm, Stack->Code);
}


void JB_ASM_FillTable (CakeVM* vm,  byte* LibGlobs,  byte* PackGlobs,  void** CppFuncs) {
	vm->LibGlobs = LibGlobs;
	vm->PackGlobs = PackGlobs;
	vm->CppFuncs = (Fn0*)CppFuncs;
}


void** JB_ASM_InitTable (CakeVM* vm, int FuncCount, int GlobBytes) {
	if (vm->CppFuncs)
		return (void**)(vm->CppFuncs);
	int FuncBytes = sizeof(void*) * FuncCount;
	auto Result = (byte*)calloc(FuncBytes + GlobBytes + 8, 1);
	if (Result) {
		((int64*)(Result + GlobBytes))[0] = 0x12345789ABCDEFED; // sentinel
		vm->PackGlobs = Result;
		vm->CppFuncs = (Fn0*)(Result + GlobBytes + 8);
		return (void**)(vm->CppFuncs);
	}
	return 0;
}


static ASM* VMProtect (CakeVM& V, bool Protect) {
	ASM* Code = VMCodePtr(&V);
	Code = (ASM*)((((int64)Code)<<1)>>1);
	int F = V.VFlags;
	int CanWrite = PROT_WRITE*(!Protect);
	if (CanWrite  !=  (F&PROT_WRITE)) {
		int Err = mprotect(Code, CakeCodeMax*4, PROT_READ|CanWrite);
		if (Err) {
			V.CakeFail = errno; // JB_ErrorHandleFileC is too aggressive for this
			return Code;
		}
		F = (F & ~PROT_WRITE) | CanWrite;
		V.VFlags = F;
	}
	return Code;
}


ASM* JB_ASM_Code (CakeVM* V, int Length) {
	if_rare (!V or (uint)Length > CakeCodeMax)
		return 0;
	return VMProtect(*V, false);
}


CakeVM* JB_ASM__VM (int Flags) {				// 256K is around 1600 ~fns deep.
	const int Page = 16*1024;
	int AllocSize = CakeStackSize + CakeCodeMax*4;
	if (Flags&kJB_VM_AskDebug)
		AllocSize += CakeCodeMax*4;
	
	Flags |= PROT_READ | PROT_WRITE;
	auto V = (CakeVM*)JB_AlignedAlloc(AllocSize, Page);
	if (!V) {
		JB_ErrorHandleFileC(nil, errno, "mmap CakeVM");
		return 0;
	}
	
	memzero(V, AllocSize);
	auto HighBit = 1ull << 63ull;
	V = (CakeVM*)(((int64)V)&~HighBit);
	if (Flags&kJB_VM_AskDebug)
		V = (CakeVM*)(((int64)(V)) | HighBit);
	
	V->__VIEW__ = JB_ASM_NoBreak;
	V->VFlags = Flags;
	VMCodePtr(V)[CakeCodeMax-1] = VMHexFinalReturn;
	VMCodePtr(V)[-1] = VMHexEndStack;
	
	__CAKE_VM__(*V, 0, CakeStackSize);
	return V;
}


 
AlwaysInline ivec4* JB_ASM_Run_ (CakeVM& V, int CodeIndex) {
	// re-entrant code will be called differently.
	auto Base = (VMStack*)(&V.Registers[0]);
	Base[0].Code = VMCodePtr(&V) + CakeCodeMax-1;
	Base[2].Code = VMProtect(V, true) + CodeIndex;
	for (int i = 1; i <= 2; i++) {
		Base->DestReg = 1;
		Base->Dummy = 987654321;
		Base->Depth = i;
		Base->GoUp = 0;
		Base[1] = {};
		Base += 2;
	}
	return __CAKE_VM__(V, Base[-2].Code, 0);
}


static ivec4* CakeCrashedSub (CakeVM* V, int ErrorKind, VMStack* Stack, int Signal) {
	char ErrorBuff[40];
	const char* ErrStr = "Run CakeVM";					CrashState = 3;
	if (Stack) {
		int Depth = Stack->Depth;
		snprintf(ErrorBuff, sizeof(ErrorBuff), "StackOverFlow: Stack is %i deep", Depth);
		ErrStr = ErrorBuff;
	}
	
	Signal |= 128;
	V->CakeFail = Signal;
	(V->__VIEW__)(V, ErrorKind, 0, (ivec4*)(Stack));	CrashState = 30;
	JB_ErrorHandleFileC(nil, Signal, ErrStr);			CrashState = 40;
	V->Registers[2] = {.Int = Signal};
	
	return 0; 
}


static ivec4* CakeCrashed (CakeVM* V, int Signal) {
	if (CrashState) {
		printf("Crashed inside crash handler, at point: %i\n", CrashState);
		return 0;
	}													CrashState = 2;
	Signal |= 128;
	errno = Signal;
	//int ErrorKind = StackOverFlow(V);						CrashState = 4;
	//auto Stack = V->CurrStack;							CrashState = 20;
	CakeCrashedSub(V, -1, nil, Signal);
	return 0;
}


static void CakeCorrupt (int Sig) {
	CrashCount++;
	longjmp(VMRestorer, Sig);
}


ivec4* JB_ASM_Run (CakeVM* V, int Code) {
#ifdef DEBUG
	static_assert((sizeof(VMRegister) == sizeof(VMStack)), "sizeof type");
#endif

	V = (CakeVM*)(((IntPtr)V)&~(1ull<<63ull));
	auto OldSeg = signal(SIGSEGV, CakeCorrupt);
	auto OldBus = signal(SIGBUS,  CakeCorrupt);

	int Signal = setjmp(VMRestorer);
	ivec4* Reg =  Signal  ?  CakeCrashed(V, Signal)  :  JB_ASM_Run_(*V, Code);
	signal(SIGSEGV, OldSeg);
	signal(SIGBUS, OldBus);
	CrashState = 0;
	return Reg;
}


#else

					// Stubs //

ivec4*	JB_ASM_Registers	(CakeVM* V, bool Clear)					{return 0;}
void	JB_ASM_Pause		(CakeVM* V)								{}
int*	JB_ASM_SetDebug		(CakeVM* V, bool On)					{return 0;}
int		JB_ASM_Index		(CakeVM* V, u32* Code)					{return 0;}
void	JB_ASM_FillTable	(CakeVM* V, byte*, byte*, void**)		{}
void**	JB_ASM_InitTable	(CakeVM* V, int, int)					{return 0;}
u32*	JB_ASM_Code			(CakeVM* V, int Length)					{return 0;}
CakeVM* JB_ASM__VM			(int Flags)								{return 0;}
ivec4*	JB_ASM_Run			(CakeVM* V, int CodeIndex)				{return 0;}

#endif
} // extern c
