
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

#ifdef __VM__
#pragma GCC optimize ("Os")

#include "BitFields.h"
#include "JB_VM.h"
#include "JB_VM_Helpers.i"


#define ı			 Op = *Code++;   goto *JumpTable[Op>>24];
#define VMCodePtr(V) ((ASM*)(((byte*)(V)) + 1024*1024))
#define CanDebug(V)  (((uint64)(V))>>63)
#define StackOverFlowErr (1<<10)

ivec4* JB_ASM_Registers (CakeVM* V, bool Clear) {
	if_rare (!V)
		return 0;
	auto Ret = V->Registers;
	if (Clear)
		memset(Ret, 0xFE, sizeof(VMRegister)*35);
	return (ivec4*)(Ret+3); // unused, stack, R0, R1 // don't return R0 cos we don't want them altering it.
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


int* JB_ASM_SetDebug (CakeVM* V, JB_ASM_Break Value) {
	if_rare (!CanDebug(V))
		return 0;
	auto J = V->JumpTable;
	void* Break = J[512];
	V->__VIEW__ = Value?Value:JB_ASM_NoBreak;
	if ((Value != nil) != (J[0] == Break)) {
		int i = 256;
		if (Value) while (--i >= 0)
			J[i] = Break;
		  else
			memcpy(J, V->OriginalJumpTable, 256*sizeof(void*));
	}
	auto AASM = VMCodePtr(V);
	return (int*)(AASM + CakeCodeMax);
}


static int StackOverFlow (CakeVM* V) {
	VMStack* Stack = V->CurrStack;
	if ( (byte*)Stack >= ((byte*)V)+(1024*1024*2) )
		return 2; // really far out
	if ( (byte*)Stack < (byte*)(V+1) )
		return -1;
	
	if ( ((ASM*)(Stack+32) < VMCodePtr(V)))
		return 0;
	V->ErrNo = errno | StackOverFlowErr;
	return 1;
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
		memcpy(vm.JumpTable, GlobalJumpTable, 256*sizeof(void*));
		memcpy(vm.JumpTable+256, GlobalJumpTable, sizeof(GlobalJumpTable));
		return 0;
	}
  
    RegVar(r, r21) = vm.Registers + 2;
    RegVar(JumpTable, r22) = &vm.JumpTable[0];
	Op = *Code++;									// spelled out for debug

	// // // // //  START VM  // // // // // 
	goto *JumpTable[Op>>24];
	#include "Instructions.i"
	EXIT:;
	
	if (StackOverFlow(&vm))
		return 0;
    return &vm.Registers[1].Ivec;
	
	PAUSE:;											// Assume was in debug mode
	++(Code[CakeCodeMax-1]);
	for (int i = 0; i < 256; i++)
		JumpTable[i] = &&TRYBREAK;					// Restore
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
	if (BackStack <= &vm->Registers[1].Stack)
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
			V.ErrNo = errno; // JB_ErrorHandleFileC is too aggressive for this
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
	int StackSize = 1024*1024;
	
	int AllocSize = StackSize + CakeCodeMax*4;
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
	
	V->VFlags = Flags;
	VMCodePtr(V)[CakeCodeMax-1] = VMHexEndCode;
	VMCodePtr(V)[-1] = VMHexEndStack;
	
	__CAKE_VM__(*V, 0, StackSize);
	return V;
}



AlwaysInline ivec4* JB_ASM_Run_ (CakeVM& V, int CodeIndex) {
	// re-entrant code will be called differently.
	V.Registers[0] = {};
	V.Registers[2] = {};
	if (!V.__VIEW__) V.__VIEW__ = JB_ASM_NoBreak;
	auto& Stack = V.Registers[1].Stack;
	V.CurrStack = (VMStack*)(&Stack);
	Stack.DestReg = 1;
	Stack.Alloc = 0;
	Stack.Depth = 1;
	Stack.Marker2 = 123;
	ASM* Code = VMCodePtr(&V);
	Stack.Code = Code + CakeCodeMax-1;
	if (Stack.Code[0] == VMHexEndCode)
		return __CAKE_VM__(V, VMProtect(V, true) + CodeIndex, 0);
	V.ErrNo |= StackOverFlowErr;
	return 0;
}


static ivec4* Crashed (CakeVM* V, int Signal) {
	Signal |= 128;
	errno = Signal;
	char ErrorBuff[40];
	const char* ErrStr = "Run CakeVM";
	int OverFlow = StackOverFlow(V);
	
	if (OverFlow < 0) {
		ErrStr = "StackUnderFlow";
	} else if (OverFlow > 1) {
		ErrStr = "StackPointerCorrupt";
	} else if (OverFlow == 1) {
		auto Stack = V->CurrStack;
		int Depth = Stack->Depth;
		snprintf(ErrorBuff, sizeof(ErrorBuff), "StackOverFlow: Stack is %i deep", Depth);
		ErrStr = ErrorBuff;
	}
	JB_ErrorHandleFileC(nil, Signal, ErrStr);
	return 0; 
}


static void CakeCorrupt (int Sig) {
	longjmp(VMRestorer, Sig);
}


ivec4* JB_ASM_Run (CakeVM* V, int Code) {
#ifdef DEBUG
	static_assert((sizeof(VMRegister) == sizeof(VMStack)), "sizeof type");
#endif

	auto OldSeg = signal(SIGSEGV, CakeCorrupt);
	auto OldBus = signal(SIGBUS,  CakeCorrupt);

	int Signal = setjmp(VMRestorer);
	ivec4* Reg =  Signal  ?  Crashed(V, Signal)  :  JB_ASM_Run_(*V, Code);
	signal(SIGSEGV, OldSeg);
	signal(SIGBUS, OldBus);
	return Reg;
}


#else

					// Stubs //

ivec4*	JB_ASM_Registers	(CakeVM* V, bool Clear)					{return 0;}
void	JB_ASM_Pause		(CakeVM* V)								{}
int*	JB_ASM_SetDebug		(CakeVM* V, JB_ASM_Break Value)			{return 0;}
int		JB_ASM_Index		(CakeVM* V, u32* Code)					{return 0;}
void	JB_ASM_FillTable	(CakeVM* V, byte*, byte*, void**)		{}
void**	JB_ASM_InitTable	(CakeVM* V, int, int)					{return 0;}
u32*	JB_ASM_Code			(CakeVM* V, int Length)					{return 0;}
CakeVM* JB_ASM__VM			(int Flags)								{return 0;}
ivec4*	JB_ASM_Run			(CakeVM* V, int CodeIndex)				{return 0;}

#endif
} // extern c
