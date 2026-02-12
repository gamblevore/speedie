
#define CakeStackSize	(1024*1024)
#define CakeCodeMax		(1024*256)
#define VMHexEndCleanly	0x00BADA55 
#define VMHexFinalReturn 11537169
#define VMHexEndStack	0xBAD57ACC 


#define std_swap std::swap
#if __CPU_TYPE__ == __CPU_ARM__
	#define RegVar(x,n) register auto x asm (#n)
#else
	#define RegVar(x,n) auto x
#endif


#ifndef ASM
	#define ASM u32
#endif


typedef u64 (*Fn0 )();


#define kJB_VM_WantProtect 8
#define kJB_VM_TrapTooFar 16
#define kJB_VM_AskDebug 32


#define AlwaysInline static inline __attribute__((__always_inline__))
