
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
    Fn0*			CppFuncs;
};


struct CakeVM;
typedef bool (*JB_ASM_Break)(CakeVM* VM, ASM* Code, int BreakValue);
struct CakeVM {
	vm_globs		Env;
    byte*			AllocBase;
    int				AllocCurr;
    int				StackSize;
    JB_ASM_Break	Break;
    
	void*const*		OriginalJumpTable;
	void*			JumpTable[514];
    int				VFlags;
    
    ASM				ExitGuard;
    ASM				EXIT[2];
	VMRegister		Registers[];
};


#define kJB_VM_TrapTooFar 1
#define kJB_VM_WantProtect 2
#define kJB_VM_IsProtected 4


#define AlwaysInline static inline __attribute__((__always_inline__))
