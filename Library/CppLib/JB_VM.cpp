
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

#ifdef __vm__
jb_vm* vm;


#pragma GCC optimize ("Os")
#include "JB_VM_Helpers.i"


#define ı		Op = *Code++;   goto *JumpTable[Op>>24]; // goto *Next;
#define _		;

// more optimised system... but needs debugging for multi-asm instructions
#define JumpLeaf(Addr)         LeafCode = Code;     Code = (Addr);
#define VMGuardValue 1234567890

ivec4* RunVM (jb_vm& pvm) {				// vm_run, vm__run, vmrun, run_vm
    const static void* jumptable[] = {
#if __CPU_TYPE__ == __CPU_ARM__
        #include "InstructionList.h"
#endif
    };
	RegVar(&vm,			r19) = pvm;
    RegVar(Code,		r20) = vm.Env.CodeBase;
    RegVar(r,			r21) = vm.Registers+2;	// space for stack + zeroreg
    RegVar(Op,			r22) = (ASM)-1;
    RegVar(JumpTable,	r23) = jumptable;
    if ('_') {
		vm.Registers[2] = {};
		auto& Stack = vm.Registers[1].Stack;
		Stack.Code = &vm.EXIT[0];
		vm.EXIT[0] = 1; // just in case it got corrupted.
		Stack.SavedReg = 0;
		Stack.Alloc = 0;
		Stack.Marker = 12345;
		Stack.Marker2 = 123;
	}
    r[0] = {};
#if __CPU_TYPE__ == __CPU_ARM__
	ı;
	#include "Instructions.i"
	ı
#endif
	EXIT:;

    return &pvm.Registers[1].Ivec;
}


void** JB_ASM_InitTable(jb_vm* vm, int n, int g) {
	if (vm->Env.CppFuncs)
		return (void**)(vm->Env.CppFuncs);
	vm->Env.PackGlobs = 0;
	// some sentinel space would be nice.
	auto Result = (byte*)calloc(n*sizeof(void*) + g + 8, 1);
	if (Result) {
		((int64*)(Result + g))[0] = 0x12345789ABCDEFED;
		vm->Env.PackGlobs = Result;
		vm->Env.CppFuncs = (Fn0*)(Result + g + 8);
		return (void**)(vm->Env.CppFuncs);
	}
	return 0;
}


jb_vm* JB_ASM__VM() {
	dbgexpect2 (sizeof(ASM)==4);
	auto v = vm;
	if (v) return v;
	
	int StackSize = 1024*1024;			// Around 6400 ~fns deep. 
	v             = (jb_vm*)calloc(StackSize, 1);
	if (!v)
		return 0;
	vm = v;
	v->StackSize  = (StackSize - sizeof(jb_vm))/sizeof(VMRegister);
	return v;
}


ivec4* JB_ASM__Run(u32* Code, u32 CodeLength) {
	auto V = JB_ASM__VM();
	if (V) {
		V->Env.CodeBase = (ASM*)Code;
		V->Env.CodeLength = CodeLength;
		return RunVM(*V);
	}

	return (ivec4*)JB_ErrorHandleC("Can't allocate VM", JB_Str__Empty(), false);
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
jb_vm* JB_ASM__VM() {
	return 0;
}
ivec4* JB_ASM__Run(u32* Code, u32 CodeSize) {
	return 0;
}


#endif
} //  cextern c
