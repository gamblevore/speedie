
#define CakeCodeMax		(1024*256)
#define VMHexEndCode	0x00BADA55 
#define VMHexEndStack	0xBAD57ACC 


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



struct CakeVM {
    int				ErrNo;
    int				VFlags;
    JB_ASM_Break	__VIEW__;
    byte*			LibGlobs;
    byte*			PackGlobs;
    Fn0*			CppFuncs;
    byte*			AllocBase;
    int				AllocCurr;
    
	void*const*		OriginalJumpTable;
	void*			JumpTable[514];
    VMStack*		CurrStack;
    
    ASM				ExitGuard;
	VMRegister		Registers[];
};


#define kJB_VM_WantProtect 8
#define kJB_VM_TrapTooFar 16
#define kJB_VM_AskDebug 32


#define AlwaysInline static inline __attribute__((__always_inline__))
