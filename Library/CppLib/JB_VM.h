
typedef const void* Goto;
#define std_swap std::swap

// // // // // // // // // // // //  

// we really need to make this a simple32 bit number
// no special wierdness!!!!! ARGH
#ifndef ASM
	#define ASM u32
#endif
//	union {
//		u32				Raw;
//    };
//    ASM() {
//		Raw = 0;
//    }
//    ASM(u32 Op) {
//		Raw = Op<<24;
//    }
// 	operator u32() {
//		return Raw;
//	}
//};


struct RegInfo {
//	uint8			ResultRegister;
	uint8			CallerRegCount;
	Register		Registers[];
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
    Register*		CurrStack;
    int             StackSize;
    ASM				EXIT[2];
    int             GuardValue;
    RegInfo			Stack;
};


