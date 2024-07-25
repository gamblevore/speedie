
/*
	Copyright (C) 2019 Theodore H. Smith.
*/


/*
todo:
	* FFI
Limits:
	* 256 OpCodes, including a few variable length opcodes
	* r0 = 0
	* can recursive vm->c->vm! 
*/


#include "JB_Umbrella.hpp"

extern "C" {
#if __VM__
#include "BitFields.h"
#include "JB_VM.h"
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


s64 RunVM (jb_vm& vm) {		// vm_run, vm__run, vmrun, run_vm
    const static Goto JumpTable[] = {
        #include "InstructionList.h"
    };

    ASM* Code	  = vm.Env.Code;
//    Goto Next     = 0;
    Register* r	 = vm.Registers;

    ASM  Op=-1;
//    ASM  Op2;
//	START:
	ı;
	#include "Instructions.i"
	ı 

    return 0;
}



jb_vm* vm;
ivec4* JB_ASM_Registers(jb_vm* V, bool Clear) {
	Register* Ret = V->Registers;
	if (Clear)
		memset(Ret, 0, sizeof(vec4)*32);
	return (ivec4*)(Ret+1);
}


#ifndef VMExitReturn
	#define VMExitReturn 2<<24
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
	vm->EXIT[0] = VMExitReturn; // thats not the right code!
	vm->EXIT[1] = 1; // halt
//	vm->Stack.ResultRegister = 1;		// Remove this? the calling instruction should specify the result.
	vm->StackSize  = (StackSize - sizeof(jb_vm))/sizeof(u64);
	return vm;
}


s64 JB_ASM_Run(u32* Code, u32 CodeLength) {
	auto V = JB_ASM_VM();
	if (V) {
		V->Env.Code       = (ASM*)Code;
		V->Env.CodeLength = CodeLength;
		return RunVM(*V);
	}
	return -1;
}

#else
ivec4* JB_ASM_Registers(jb_vm* V, bool i) {
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
