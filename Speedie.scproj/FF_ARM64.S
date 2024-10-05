
#ifdef __aarch64__
	#define __realarm64__
#endif
#ifdef _M_ARM64
	#define __realarm64__
#endif


#ifdef __realarm64__
.text
.global _FFASMTest
.align 4
_FFASMTest:
	mov     x1, x0				// put in x1
	and     x1, x1, 15			// x1 = x1&15
	add     x8, x1, x1, lsl 2   // x8 = x1*5
	mov     x0, x8				// put back again
	ret
#endif


// http://ethernut.de/en/documents/arm-inline-asm.html
// http://modexp.wordpress.com/2018/10/30/arm64-assembly/
// http://wolchok.org/posts/how-to-read-arm64-assembly-language/

/*
	OK, what about saving the register state?
	We need to know how many regs to save. Thats not the same as where we place the result!
	Even if it were, we still need two counts. The send-count, and the save-count.
	
	The send-count is typed.
	
	The save-count has no type.
*/
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
	* You can't specify registers in C++, except when they are observed by ASM.
*/



	// I think calling the VM should be a simple-task. So instead of calling a function-pointer...
	// we test the function pointer, to see if its SPD or C. If C... we call it. Otherwise we call the VM.
	// this has to be done at every call-site. What about for passing to C++ libs? We'd have to generate
	// some native ASM for that. I think C++ has lambdas. It could be done.


#if 0
#define NextRegI(r,r2) 											\
	"ubfiz  x"#r",		%[CODE],	"#r2",		5		\n" 	\
	"ldr    x"#r",		[%[R],		x"#r", lsl 3]		\n" // needs to be 4 but can't do this directly????

#define NextRegF(r,r2) 											\
	"ubfiz  x"#r",		%[CODE],	"#r2",		5		\n" 	\
	"ldr    d"#r",		[%[R],		x"#r", lsl 3]		\n" // needs to be 4 but can't do this directly???

__asm__ volatile ( // we used to have ints first, but floats first makes more sense.
	"and     x1, %[CODE], 15		\n\t"		// x1 = code&15
	"add     x8, x1, x1, lsl 2		\n\t"		// x8 = x1*5
	"lsr     x8, %[CODE], x8		\n\t"		// x8 = code>>x8 // x8 = code>>(x1*5)

	"adr x0, 1f						\n\t"		
	"add x0, x0, x1, lsl 1			\n\t"		// x0 += x1 << 1
	"br  x0							\n\t"		// smart-jump
	"1:\n\t"
	// Float / SIMD
	NextRegF(8, 52) // not perfect yet... we need to pass the entire SIMD, not just a double!
	NextRegF(7, 47)
	NextRegF(6, 42)
	NextRegF(5, 37)
	NextRegF(4, 32)
	NextRegF(3, 27)
	NextRegF(2, 22)
	NextRegF(1, 17)
	NextRegF(0, 12)

	"ubfiz   x1, %[CODE], 4, 4		\n\t"		// x1 = (code>>4)&15 // still needs << 1
	"adr x0, 2f						\n\t"		// ADR + ADD can merge? SHOULD allow pc instead of x0 
	"add x0, x0, x1					\n\t"		// but doesnt... (make the first part non-volatile)?
	"br  x0							\n\t"		// smart-jump
	"2:\n\t"
	// ints
	NextRegI(8, 52)
	NextRegI(7, 47)
	NextRegI(6, 42)
	NextRegI(5, 37)
	NextRegI(4, 32)
	NextRegI(3, 27)
	NextRegI(2, 22)
	NextRegI(1, 17)
	NextRegI(0, 12)

	"stp     x29, x30, [sp, -16]!	\n\t"		// copy and alloc
	"mov     x29, sp				\n\t"		// update some shit
        
	"blr     %[FN]					\n\t"		// call some shit
    "ldp     x29, x30, [sp], 16		\n\t"		// restore some shit
	""
	 : [x0] "=&r" (iresult),   [q0] "=&w" (vresult)
	 : /*  input  */  [R] "r" (r),  [CODE] "r" (funcdata),  [FN] "r" (fn),  [OP] "r" (Op) 
	 : /* clobber */  "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17" );
	r+=n1; // do this first?
	if (Op&32)
		r->Int = iresult;
	  else
		r->Ivec = vresult;
	// i think that's it.
		
#endif

