
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

struct BasicASM {
	u32 Op			: 7;
	u32	R1    		: 5;
	u32	R2    		: 5;
	u32	R3    		: 5;
	u32	R4    		: 5;
	u32	L    		: 5;
};

struct ASM {
	union {
		u32				Raw;
    };
    ASM() {
		Raw = 0;
    }
    ASM(u32 Op) {
		Raw = Op<<25;
    }
 	operator u32() {
		return Raw;
	}
};


struct RegInfo {
	uint8			ResultRegister;
	uint8			CallerRegCount;
	bool			Verified;
	ASM*			JumpBackTo;
	s64				Registers[];
};


struct Function {
	const char*		Name;
	uint8*			Data;
	ASM				Code[];
};


struct jb_vm {
    Function*		FuncTable;
    ASM*            Code;
    ASM*            CodeEnd;
    s64*			CurrStack;
    const char*     Location;
    const char**    Args;
    int             StackSize;
    ASM				EXIT[2];
    int             GuardValue;
    RegInfo			Stack;
};


