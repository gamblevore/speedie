
#define std_swap std::swap
#if __CPU_TYPE__ == __CPU_ARM__
	#define RegVar(x,n) register auto x asm (#n)
#else
	#define RegVar(x,n) auto x
#endif



// // // // // // // // // // // //  

#ifndef ASM
	#define ASM u32
#endif

typedef u64 (*Fn0 )();
typedef u64 (*Fn1 )(u64);
typedef u64 (*Fn2 )(u64, u64);
typedef u64 (*Fn3 )(u64, u64, u64);
typedef u64 (*Fn4 )(u64, u64, u64, u64);
typedef u64 (*Fn5 )(u64, u64, u64, u64, u64);
typedef u64 (*Fn6 )(u64, u64, u64, u64, u64, u64);
typedef u64 (*Fn7 )(u64, u64, u64, u64, u64, u64, u64);
typedef u64 (*Fn8 )(u64, u64, u64, u64, u64, u64, u64, u64);
typedef u64 (*Fn9 )(u64, u64, u64, u64, u64, u64, u64, u64, u64);
typedef u64 (*Fn10)(u64, u64, u64, u64, u64, u64, u64, u64, u64, u64);
typedef u64 (*Fn11)(u64, u64, u64, u64, u64, u64, u64, u64, u64, u64, u64);
typedef u64 (*Fn12)(u64, u64, u64, u64, u64, u64, u64, u64, u64, u64, u64, u64);


struct Function { 
	uint8			JbinStart; // bytes backward to the jbin string
	uint			CallCount;
	ASM				Code[];
};


struct vm_globs {
    byte*			LibGlobs;
    byte*			PackGlobs;
    JB_String**		PackStrs;
    Fn0*			Cpp;
    Function*		PackCallbacks;
    Function*		LibCallbacks;
    byte*			AllocBase;
    int				AllocCurr;
    ASM* 			CodeBase;
    int				CodeLength;
};



struct jb_vm {
	vm_globs		Env;
    int				StackSize;
    ASM				EXIT[2];
	VMRegister		Registers[];
};


#define AlwaysInline static inline __attribute__((__always_inline__))
