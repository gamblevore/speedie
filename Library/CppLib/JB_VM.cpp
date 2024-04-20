
/*
	Copyright (C) 2019 Theodore H. Smith.
*/


/*
todo:
	* FFI
Limits:
	* 16M instructions per-program
	* 256 OpCodes, and a few variable length opcodes
	* r0 = 0
	* can recursive vm->c->vm! 

Later:
	* endian / sign-extend / popcount / truncate bits?
	* use gccbuiltin for all
*/


#include "JB_Umbrella.hpp"
#include "BitFields.h"
#include "JB_VM.h"

extern "C" {
#if 1
#include "JB_VM_Helpers.i"


#define ı         goto *Next;
#define ___       Op2 = *Code++;  Next = JumpTable[Op2>>25];
#define __      ; Op  = Op2;      ASMPrint(Op);
#define _         __   ___
#define JumpLeaf(Addr)         LeafCode = Code;     Code = (Addr);


s64 RunVM (jb_vm& vm) {		// vm_run, vm__run, vmrun, run_vm
    const static Goto JumpTable[] = {
        #include "InstructionList.h"
    };
    require (VerifyTable(vm, &JumpTable[0]));

    ASM  Op;
    ASM  Op2;
    ASM* LeafCode = 0;
    ASM* Code	  = vm.Code;
    Goto Next     = 0;
    s64* r		  = vm.Stack.Registers;
    s64  Tmp	  = 0;

	START: ___;
	#include "Instructions.i"
	ı 

    return 0;
}



jb_vm* vm;
s64* JB_ASM_Registers(jb_vm* V) {
	return V->Stack.Registers+1;
}
s64* JB_ASM_ClearRegisters(jb_vm* V, int i) {
	s64* Ret = V->Stack.Registers;
	Ret[0] = 0;
	while (++i <= 32) {
		Ret[i] = 0;
	}
	return Ret+1;
}


#ifndef VMExitReturn
	#define VMExitReturn 2<<25
#endif

jb_vm* JB_ASM_VM() {
	int N = sizeof(ASM);
	dbgexpect2 (N==4);
	if (vm) return vm;
	
	int StackSize  = (10*8)*400; // 400 levels deep on average.
	vm             = (jb_vm*)calloc(StackSize, 1);
	if (!vm)
		return 0;
	vm->GuardValue = 1234567890;
	vm->EXIT[0] = VMExitReturn;
	vm->EXIT[1] = 1; // halt
	vm->Stack.JumpBackTo = vm->EXIT;	// yay
	vm->Stack.ResultRegister = 1;		// No args/returns in r0. 
	vm->StackSize  = (StackSize - sizeof(jb_vm))/sizeof(u64);
	return vm;
}


s64 JB_ASM_Run(u32* Code, u32 CodeSize) {
	auto V = JB_ASM_VM();
	if (V) {
		V->Code    = (ASM*)Code;
		V->CodeEnd = (ASM*)Code + (CodeSize-1);
		return RunVM(*V);
	}
	return -1;
}

#else
s64* JB_ASM_ClearRegisters(jb_vm* V, int i) {
	return 0;
}
jb_vm* JB_ASM_VM() {
	return 0;
}
s64 JB_ASM_Run(u32* Code, u32 CodeSize) {
	return 0;
}


#endif
} //  cextern c
