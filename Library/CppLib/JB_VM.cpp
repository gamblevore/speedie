
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


extern "C" {
#include "BitFields.h"
#include "JB_VM.h"


ivec4* JB_ASM_Registers (CakeVM* V, bool Clear) {
	if (!V)
		return 0;
	auto Ret = V->Registers;
	if (Clear)
		memset(Ret, 0xFE, sizeof(VMRegister)*35);
	return (ivec4*)(Ret+3);
}


#ifdef __VM__
#pragma GCC optimize ("Os")
#include "JB_VM_Helpers.i"


#define ı		Op = *Code++;   goto *JumpTable[Op>>24];
#define _		;



void JB_ASM_Pause (CakeVM* V) {
	auto J = V->JumpTable;
	void* Break = J[256];
	for (int i = 0; i < 256; i++)
		J[i] = Break;
}


int* JB_ASM_SetDebug (CakeVM* V, bool Value) {
	auto J = V->JumpTable;
	void* Break = J[512];
	if (Value != (J[0] == Break)) {
		int i = 256;
		if (Value) while (--i >= 0)
			J[i] = Break;
		  else
			memcpy(J, V->OriginalJumpTable, 256*sizeof(void*));
	}
	byte* B = (byte*)V;
	return (int*)(B + (1024*1024) + (V->StackSize));
}


static ivec4* __CAKE_VM__ (CakeVM& vm, uint Op) {
static void * const GlobalJumpTable[] = {
#if __CPU_TYPE__ == __CPU_ARM__
	#include "InstructionList.h"
	&&TRYBREAK, 									// 512
	&&PAUSE,										// 513
#endif
};
    if (Op) {
		vm.OriginalJumpTable = &GlobalJumpTable[0];
		memcpy(vm.JumpTable, GlobalJumpTable, 256*sizeof(void*));
		memcpy(vm.JumpTable+256, GlobalJumpTable, sizeof(GlobalJumpTable));
		return 0;
	}
  
    RegVar(Code, r20) = JB_ASM_Code(&vm,0,0);
    RegVar(r, r21) = vm.Registers+2;
    RegVar(JumpTable, r22) = &vm.JumpTable[0];

#if __CPU_TYPE__ == __CPU_ARM__
	ı;
	#include "Instructions.i"
#endif
	EXIT:;
    return &vm.Registers[1].Ivec;

	
	PAUSE:;											// Assume was in debug mode
	++Code[1024*1024];
	for (int i = 0; i < 256; i++)
		JumpTable[i] = &&TRYBREAK;
	goto BREAK;

	
	TRYBREAK:; {
		auto BreakValue = ++Code[1024*1024];
		if_rare (BreakValue == 0x80000000) {		// Accidental trap from 2GB loop.
			Code[1024*1024] = 1;					// Reset 
			if (!(vm.VFlags & kJB_VM_TrapTooFar))
				goto *JumpTable[256+(Op>>24)];		// Resume
		}
		if_usual (BreakValue != 0)
			goto *JumpTable[256+(Op>>24)];			// Resume
	}
	
	BREAK:;											// the actual breakpoint
	while (auto B = vm.Break)
		if (!(B)(&vm, Code-1, Code[1024*1024]))
			break;

	goto *JumpTable[256+(Op>>24)];					// Resume
}



void JB_ASM_FillTable (CakeVM* vm,  byte* LibGlobs,  byte* PackGlobs,  void** CppFuncs) {
	vm->Env.LibGlobs = LibGlobs;
	vm->Env.PackGlobs = PackGlobs;
	vm->Env.CppFuncs = (Fn0*)CppFuncs;
}


void** JB_ASM_InitTable (CakeVM* vm, int FuncCount, int GlobBytes) {
	if (vm->Env.CppFuncs)
		return (void**)(vm->Env.CppFuncs);
	int FuncBytes = sizeof(void*) * FuncCount;
	auto Result = (byte*)calloc(FuncBytes + GlobBytes + 8, 1);
	if (Result) {
		((int64*)(Result + GlobBytes))[0] = 0x12345789ABCDEFED; // sentinel
		vm->Env.PackGlobs = Result;
		vm->Env.CppFuncs = (Fn0*)(Result + GlobBytes + 8);
		return (void**)(vm->Env.CppFuncs);
	}
	return 0;
}


ASM* JB_ASM_Code (CakeVM* V, ASM* Code, int Length) {
	if (Length <= (1024*1024)/4) {
		auto D = (ASM*)(((byte*)V) + V->StackSize);
		if (Code)
			return (ASM*)memcpy(D, Code, 4*Length);
		return D;
	}
	return 0;
}


CakeVM* JB_ASM__VM (int StackSize, int Flags) {				// 256K is around 1600 ~fns deep.
	const int MB = 1024*1024;
	const int Page = 16*1024;
	StackSize = StackSize&~(Page-1);						// remove garbage
	if (StackSize < MB/4)
		StackSize = MB/4;
	int AllocSize = StackSize + 2*MB;	
	auto V = (CakeVM*)JB_AlignedAlloc(AllocSize, Page);		// page aligned. Can call mprotect later.
	if (V) {
		memzero(V, AllocSize);
		V->VFlags = Flags;
		V->StackSize = StackSize;
		__CAKE_VM__(*V, StackSize);
	}
	return V;
}


static ivec4* VM_Run (CakeVM& V) {
	// re-entrant code will be called differently.
	V.Registers[2] = {};
	V.EXIT[0] = 1;
	auto& Stack = V.Registers[1].Stack;
	Stack.Code = &V.EXIT[0];	
	Stack.SavedReg = 0;
	Stack.Alloc = 0;
	Stack.Marker = 12345;
	Stack.Marker2 = 123;
	return __CAKE_VM__(V, 0);
}


ivec4* JB_ASM_Run (CakeVM* V) {
	return VM_Run(*V); // i can't stand pointer syntax.
}


#else
void*	JB_ASM__Load		(JB_StringC* S) {
	return 0;
}
void** JB_ASM_InitTable(CakeVM* vm, int n, int g) {
	return 0;
}
ivec4* JB_ASM__Registers(CakeVM* V, bool i) {
	return 0;
}
CakeVM* JB_ASM__VM(int StackSize, int Flags) {
	return 0;
}
ivec4* JB_ASM__Run(CakeVM* VM, u32* Code, int CodeSize) {
	return 0;
}


#endif
} //  cextern c
