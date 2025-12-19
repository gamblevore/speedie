
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


ivec4* JB_ASM_Registers (jb_vm* V, bool Clear) {
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
#define Dı		JB_VM_DebugTrap(); ı
#define _		;

#define JB_VM_DebugTrap() if (!vm.ShadowLocation | (Code[vm.ShadowLocation]++)>>31) goto BREAK;
// seems easier to NOT have two code-tables. We should just "go to the next thing".
// the nxt thing will be the break-block. So we'll do a lot of table-alteration. We'll need two tables...
// but we HAVE two tables right now, and thats WITH an xor trick!
// we can remove the shadowlocation trick.

// What about breaking on a specific code location? Well... yes. Thats what the shadow is for.
// we could make a generalised place to jump to, but then I buggered the VM.
// We'd have to re-write the table each and every instruction. Debugging becomes impossibly slow.
// madness.
// I think the current design is better.

// we also need a debug function callback.
// doing that from within speedie... seems... painful. We'll need to do message-passing, all that crap.
// or re-write it. I think... lets not for now?


bool VM_Debug = false;
bool VM_Prepared = false;


void JB_ASM_BreakAll (jb_vm* V, bool Value) {
	if (Value)
		V->ShadowLocation = 0;
	  else
		V->ShadowLocation = V->ShadowAlloc - V->CodeBase;
}


u32* JB_ASM_SetDebug (jb_vm* V, bool Value) {
	auto Shadow = V->ShadowAlloc;
	if (!Shadow)
		return 0;

	if (VM_Debug != Value) {
		VM_Debug = Value;
		int64* J = (int64*)V->JumpTable;
		for (int i = 0; i < 256; i++)
			J[i] ^= J[i+256];
	}

	return Shadow;
}


static ivec4* PrepareJumpTable (jb_vm& vm, void** JumpTable) {
	if (VM_Prepared) return 0;
	for (int i = 0; i < 256; i++) {
		void* Dbg = JumpTable[i+256];
		int64 diff = (int64)Dbg xor (int64)JumpTable[i];
		JumpTable[i+256] = (void*)diff; // avoid creating yet ANOTHER table...
	}
	VM_Prepared = true;
	vm.JumpTable = JumpTable;
	return 0;
};


static ivec4* __CAKE_VM__ (jb_vm& vm, uint Op) {				// vm_run, vm__run, vmrun, run_vm
static void* JumpTable[] = {
#if __CPU_TYPE__ == __CPU_ARM__
	#include "InstructionList.h"
#endif
};
    if (Op)
		return PrepareJumpTable(vm, JumpTable);
    
    RegVar(Code,		r20) = vm.SavedCode;
    RegVar(r,			r21) = vm.SavedStack;

#if __CPU_TYPE__ == __CPU_ARM__
	ı;
	#include "Instructions.i"
#endif
	EXIT:;
    return &vm.Registers[1].Ivec;

	// we actually need to enter some loop. how though?
	BREAK:;
	auto BreakValue = Code[vm.ShadowLocation];
	if (BreakValue == 0x80000000) {					// Accidental trap from 2GB loop.
		Code[vm.ShadowLocation] = 1;				// reset 
		if (!(vm.VFlags & kJB_VM_TrapTooFar))
			ı;										// resume
	}
	
	vm.SavedCode = Code;
	vm.SavedStack = r;
    return 0;
}


void JB_ASM_FillTable (jb_vm* vm,  byte* LibGlobs,  byte* PackGlobs,  void** CppFuncs) {
	vm->Env.LibGlobs = LibGlobs;
	vm->Env.PackGlobs = PackGlobs;
	vm->Env.CppFuncs = (Fn0*)CppFuncs;
}


void** JB_ASM_InitTable (jb_vm* vm, int FuncCount, int GlobBytes) {
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


jb_vm* JB_ASM__VM (int AllocSize, int Flags) { // 256K is around 1600 ~fns deep.
	if (AllocSize < 256*1024)
		AllocSize = 256*1024;
	
	int ShadowSize = (Flags&kJB_VM_DebugCapable)*(1024*1024); // 4MB
	auto V = (jb_vm*)calloc(AllocSize+ShadowSize, 1);
	V->VFlags = Flags;
	if (ShadowSize)
		V->ShadowAlloc = (u32*)(((byte*)V)+AllocSize);
	
	int StackSize = (AllocSize - sizeof(jb_vm))/sizeof(VMRegister) - 1;
	V->StackSize = StackSize;
	__CAKE_VM__(*V, StackSize);
	return V;
}


// so how to do something... interetsing? breakpoints. So... lets try?
// what first? init the vm with shadow. so how.
ivec4* VM_Run (jb_vm& V, u32* Code, int CodeLength) {
	if (CodeLength <= 0)
		return &(V.Registers[1].Ivec);

	// re-entrant code will be called differently.
	V.CodeBase = Code;
	V.SavedCode = Code;
	V.SavedStack = V.Registers+2;
	V.Registers[2] = {};
	V.EXIT[0] = 1;
	auto& Stack = V.Registers[1].Stack;
	Stack.Code = &V.EXIT[0];	
	Stack.SavedReg = 0;
	Stack.Alloc = 0;
	Stack.Marker = 12345;
	Stack.Marker2 = 123;
	V.ShadowLocation = 0;
	
	if (V.ShadowAlloc)
		V.ShadowLocation = V.ShadowAlloc - Code;

	return __CAKE_VM__(V, 0);
}


ivec4* JB_ASM__Run (jb_vm* V, u32* Code, int CodeLength) {
	return VM_Run(*V, Code, CodeLength); // i can't stand pointer syntax.
}


#else
void*	JB_ASM__Load		(JB_StringC* S) {
	return 0;
}
void** JB_ASM_InitTable(jb_vm* vm, int n, int g) {
	return 0;
}
ivec4* JB_ASM__Registers(jb_vm* V, bool i) {
	return 0;
}
jb_vm* JB_ASM__VM(int StackSize, int Flags) {
	return 0;
}
ivec4* JB_ASM__Run(jb_vm* VM, u32* Code, int CodeSize) {
	return 0;
}


#endif
} //  cextern c
