
typedef const void* Goto;
#define std_swap std::swap

// // // // // // // // // // // //  

struct BasicRegs2 {
	u64	R1			: 5;
	u64	R2			: 5;
	u64	R3			: 5;
	u64	R4			: 5;
	u64	R5			: 5;
	u64	R6			: 5;
	u64	R7			: 5;
	u64	R8			: 5;
	u64 Jump		: 24;		// How far to jump.
};

struct BasicRegs3 {
	u64	R1    		: 5;
	u64	R2    		: 5;
	u64	R3    		: 5;
	u64	R4    		: 5;
	u64	R5    		: 5;
	u64	R6    		: 5;
	u64	R7    		: 5;
	u64	R8    		: 5;
	u64	R9    		: 5;
	u64	R10   		: 5;
	u64	R11   		: 5;
	u64	R12   		: 5;
	u64 Unused		: 4;
};


struct ASM {
	union {
		u32				Raw;
    };
    ASM() {
		Raw = 0;
    }
    ASM(u32 Op) {
		Raw = Op<<24;
    }
 	operator u32() {
		return Raw;
	}
};


struct RegInfo {
//	uint8			ResultRegister;
	uint8			CallerRegCount;
	bool			Verified;
	ASM*			JumpBackTo;
	s64				Registers[];
};


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
    s64*			CurrStack;
    int             StackSize;
    ASM				EXIT[2];
    int             GuardValue;
    RegInfo			Stack;
};


