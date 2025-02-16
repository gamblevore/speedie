#ifdef _M_X86
	#define __realintel__
#endif
#ifdef __i386__
	#define __realintel__
#endif
#ifdef __x86_64__
	#define __realintel__
#endif


#ifdef __realintel__

	/*** Nativeize(u64 DATA, void* FN, Register* R, int n) ***/
	.text
	.global _Nativeize
	.align 4

	_Nativeize:								
		ret


#endif

/*
Observations so far:
 	* Use godbolt.org... its simpler than understanding the documentation. (The docs seem wrong too)
	* ARM x17 is the highest register I can freely alter
 	* Both ARM and x86 only have two register files! Despite what the docs say.
		* Both do it the same way. General/int in one place, and SIMD+FP in another.
		* x87/MMX is unused on x86.
	* x86 has 6 regs for passing ints, the other two have to be done on the stack
	* the FP/SIMD are also just done in order
		* we have enough regs on ARM&X86
	* You can't specify registers in C++, not reliably.
*/

