
typedef const void* Goto;
#define std_swap std::swap

// // // // // // // // // // // //  

#ifndef ASM
	#define ASM u32
#endif



struct Function {
	uint			CallCount;
	u16				NameLength;				
	u16				DataLength;				
	byte			Data[];
};


struct vm_globs {
    byte*			LibGlobs;
    byte*			PackGlobs;
    Function*		DebugFuncTable;
    ASM*            Code;
    int             CodeLength;
};


struct jb_vm {
	vm_globs		Env;
    Register*		CurrRegs;
    int             StackSize;
    ASM				EXIT[2];
    int             GuardValue;
    byte*			StructAllocator;
	Register		Registers[];
};


