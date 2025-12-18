
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
jb_vm* Saved_VM;


#pragma GCC optimize ("Os")
#include "JB_VM_Helpers.i"


#define ı		Op = *Code++;   goto *JumpTable[Op>>24];
#define Dı		JB_VM_DebugTrap(); ı
#define _		;


// what does break do?
// well! thats very interesting.
// I'm not sure? long jump? just fireup a callback?
// can we store the state and simply.... return?
// saving the state sounds nice. We could pause a VM, execute it a bit, and continue.
// I like that. So... lets go to a save location. Perhaps just go to the last place?
#define JB_VM_DebugTrap() if (!vm.ShadowLocation | (Code[vm.ShadowLocation]++)>>31) goto BREAK;


static ivec4* PrepareJumpTable (jb_vm& vm, void** JumpTable) {
	for (int i = 0; i < 256; i++) {
		void* Dbg = JumpTable[i+256];
		int64 diff = (int64)Dbg xor (int64)JumpTable[i];
		JumpTable[i+256] = (void*)diff; // avoid creating yet ANOTHER table...
	}
	vm.Env.JumpTable = JumpTable;
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
    
    RegVar(Code,		r20) = vm.Env.SavedCode;
    RegVar(r,			r21) = vm.Env.SavedStack;

#if __CPU_TYPE__ == __CPU_ARM__
	ı;
	#include "Instructions.i"
	ı
#endif
	EXIT:;
    return &vm.Registers[1].Ivec;

	BREAK:;
	vm.Env.SavedCode = Code;
	vm.Env.SavedStack = r;
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


jb_vm* JB_ASM__VM (int StackSize) { // 1MB is around Around 6400 ~fns deep.
	dbgexpect2 (sizeof(ASM)==4);
	auto V = Saved_VM;
	if (V) return V;
	
	if (StackSize < 256*1024)
		StackSize = 256*1024;
	V = (jb_vm*)calloc(StackSize, 1);
	Saved_VM = V;
	V->Env.StackSize = (StackSize - sizeof(jb_vm))/sizeof(VMRegister);
	__CAKE_VM__(*V, StackSize);
	return V;
}


ivec4* JB_ASM__Run (jb_vm* V, u32* Code, u32 CodeLength) {
	V->Env.SavedCode = (ASM*)Code;
	V->Env.SavedStack = V->Registers+2;
	V->Registers[2] = {};
	V->EXIT[0] = 1;
	auto& Stack = V->Registers[1].Stack;
	Stack.Code = &V->EXIT[0];	
	Stack.SavedReg = 0;
	Stack.Alloc = 0;
	Stack.Marker = 12345;
	Stack.Marker2 = 123;

	return __CAKE_VM__(*V, 0);
}



ivec4* JB_ASM__Resume (jb_vm* V) {
	return __CAKE_VM__(*V, 0);
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
jb_vm* JB_ASM__VM(int StackSize) {
	return 0;
}
ivec4* JB_ASM__Run(jb_vm* VM, u32* Code, u32 CodeSize) {
	return 0;
}


#endif
} //  cextern c
