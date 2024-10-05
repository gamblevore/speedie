
/*
	Copyright (C) 2019 Theodore H. Smith.
*/


/*
todo:
	* FFI
Design:
	* 256 OpCodes, including a few variable length opcodes
	* r0 = 0
	* can recursive vm->c->vm! 
*/


#include "JB_Umbrella.hpp"

extern "C" {
#include "BitFields.h"
#include "JB_VM.h"


ivec4* JB_ASM_Registers(jb_vm* V, bool Clear) {
	if (!V)
		return 0;
	auto Ret = V->Registers;
	if (Clear) {
		memset(Ret, 0xFE, sizeof(VMRegister)*34);
	}
	return (ivec4*)(Ret+2);
}

#if __vm__
jb_vm* vm;



#pragma GCC optimize ("Os")
#include "JB_VM_Helpers.i"


#define ı         Op = *Code++;   goto *JumpTable[Op>>24]; // goto *Next;
#define ___     ; // Op = *Code++;   goto *JumpTable[Op>>24];
#define __      ; // Op  = Op2;      ASMPrint(Op);
#define _       ;  __   ___

// more optimised system... but needs debugging for multi-asm instructions
//#define ı         goto *Next;
//#define ___       Op2 = *Code++;  Next = JumpTable[Op2>>24];
//#define __      ; Op  = Op2;      ASMPrint(Op);
//#define _         __   ___
#define JumpLeaf(Addr)         LeafCode = Code;     Code = (Addr);
#define VMGuardValue 1234567890

ivec4* RunVM (jb_vm& pvm) {		// vm_run, vm__run, vmrun, run_vm
    const static Goto JumpTable[] = {
        #include "InstructionList.h"
    };
	RegVar(&vm, r19) = pvm;
    RegVar(Code,r20) = vm.Env.CodeBase;
    RegVar(Op,  r22) = (ASM)-1;

	VMStack& Stack = vm.Registers[0].Stack;
	Stack.Code = &vm.EXIT[0];
	Stack.SavedReg = 0;
	Stack.Alloc = VMGuardValue;		   // Env.AllocCurr gets set to this on exit. // Quite harmless
    RegVar(r,   r21) = vm.Registers+1; // space for stack + zeroreg
    r[0] = {};

	ı;
	#include "Instructions.i"
	ı 
	EXIT:;

    return &pvm.Registers[0].Ivec;
}


void** JB_ASM_InitTable(jb_vm* vm, int n) {
	free(vm->Env.Cpp);
	auto Result = calloc(n, sizeof(void*));
	vm->Env.Cpp = (Fn0*)Result;
	return (void**)Result;
}

jb_vm* JB_ASM__VM() {
	dbgexpect2 (sizeof(ASM)==4);
	if (vm) return vm;
	
	int StackSize  = 256*1024;			// Around 1600 ~fns deep. 
	vm             = (jb_vm*)calloc(StackSize, 1);
	if (!vm)
		return 0;
	
	auto& v = *vm;

	v.EXIT[0] = 1;					// Halt cleanly
//	v.Env.AllocCurr = 0;			// calloc did this already
//	v.EXIT[1] = 0;					// Halt with error

	v.StackSize  = (StackSize - sizeof(jb_vm))/sizeof(VMRegister);
	return vm;
}


ivec4* JB_ASM__Run(u32* Code, u32 CodeLength) {
	auto V = JB_ASM__VM();
	if (V) {
		V->Env.CodeBase = (ASM*)Code;
		V->Env.CodeLength = CodeLength;
		return RunVM(*V);
	}

	JB_ErrorHandleC("Can't allocate VM", JB_Str__Empty(), false);
	return 0;
}

#else
void*	JB_ASM__Load		(JB_StringC* S) {
	return 0;
}
void** JB_ASM_InitTable(jb_vm* vm, int n) {
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
