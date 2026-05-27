
#define CakeStackSize		(1024*1024)
#define CakeStackObjSize	(1024*1024)
#define CakeCodeMax			(1024*256)
#define VMHexEndCleanly		0x00BADA55 
#define VMHexFinalReturn	11537169
#define VMHexEndStack		0xBAD57ACC 


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


#define VMOpt static inline __restrict __attribute__((__always_inline__))


//float JB_f_Uncos(float Self) {
//	//visible;
//	return acosf(Self) * kJB__Math_iTau;
//}
//
//float JB_f_Unsin(float Self) {
//	//visible;
//	return asinf(Self) * kJB__Math_iTau;
//}
//
//float JB_f_UnTan(float Self, float Y) {
//	float Rz = 0.0f;
//	//visible;
//	Rz = atan2f(Self, Y);
//	Rz = (Rz * (-kJB__Math_iTau));
//	if (Rz < 0.0f) {
//		(++Rz);
//	}
//	return Rz;
//}


