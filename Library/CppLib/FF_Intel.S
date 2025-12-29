
/* jeebox-licence:
    By Theodore H. Smith, 2025, theo@jeebox.org
	
    This software is provided 'as-is', without any warranty.
    In no event will the author be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercially, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
        claim that you wrote the original software.
    2. If you use this software or portions of this software in a product, you
        are required to acknowledge this in at least one of:
        About-window / launch-screen / help-files / read-me-file
    3. Altered source vershions must be plainly marked as such, and must not be
        misrepresented as being the original software.
    4. Any jeebox-licence note may not be removed/altered from any source distribution.
*/

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

	/*** Nativeize(u64 data10, void* FN, Register* R, int n) ***/
	.text
	.global _Nativeize
	.balign 4

	_Nativeize:						
		#define r   	%r15
		#define inj14	%r14
		#define flj13	%r13
		#define dest	%r12
		#define fn11	%r11
		#define data10	%r10
		
		#define j9		%r9
		#define j8		%r8
		#define x7  	%rsp		// not really available. its for the frame pointer
		#define x6  	%rbp		// not really available. its for the stack pointer
		#define x5  	%rbx		// must be restored!
		#define x4  	%rax
		#define x3  	%rcx
		#define x2  	%rdx
		#define x1  	%rsi 
		#define x0  	%rdi
		#define q7  	%xmm7
		#define q6  	%xmm6
		#define q5  	%xmm5
		#define q4  	%xmm4
		#define q3  	%xmm3
		#define q2  	%xmm2
		#define q1  	%xmm1
		#define q0  	%xmm0

#if 1

		movq		x0,  data10
		sarq		$12, data10					// data = DATA>>12
		leaq		.F7(%rip), flj13
		leaq		.I7(%rip), inj14

		movq		x1,  fn11					// fn    = FN
		movq		x2,  r  					// r15   = R

        salq		$4, x3						// n <<= 4;
		movq		r,  dest					// dest = r+n			// dest=r12
        addq		x2, dest

		movq		x0, j8						// j8 = (DATA>>6)&31
		sarq		$6, j8
		andq		$31,j8 

		movq		x0, j9
		andq		$63,j9 						// j9    = DATA&63

		leaq		(j8,j8,4), j8				// j8    = j8*5 // leaq can only multiply by pow2
		leaq		(j9,j9,4), j9				// j9    = j9*5 // but we get *3 like this.

		leaq		(flj13,j8,4), j8			// j8 = flj13 + j8*4
		leaq		(inj14,j9,4), j9			// j9 = inj14 + j9*4

		jmpq *j8

	nop
	
	// floats need different instructions?
	.F7:								// q7 = r[(data&31) << 4]; data >>= 5;
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movaps (r,x0), q7	
			
	.F6:								// q6 = r[(data&31) << 4]; data >>= 5;
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movaps (r,x0), q6

	.F5:								// q5 = r[(data&31) << 4]; data >>= 5;
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movaps (r,x0), q5

	.F4:								// q4 = r[(data&31) << 4]; data >>= 5;
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movaps (r,x0), q4

	.F3:								// q3 = r[(data&31) << 4]; data >>= 5;
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movaps (r,x0), q3

	.F2:								// q2 = r[(data&31) << 4]; data >>= 5;
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movaps (r,x0), q2

	.F1:								// q1 = r[(data&31) << 4]; data >>= 5;
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movaps (r,x0), q1

	.F0:								// q0 = r[(data&31) << 4]; data >>= 5;
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movaps (r,x0), q0
	
	jmpq *j9
	nop;nop;nop;nop
	nop;nop;nop;nop
	nop;nop;nop;nop
	nop;nop;nop;nop
	nop
	// INTEGERS //
	.I7:								// x7 = r[(data&31) << 4]; data >>= 5;
		nop								// 1 byte spacer
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movq (r,x0), x5					// Perhaps we cannop these out...

	.I6:								// x6 = r[(data&31) << 4]; data >>= 5;
		nop								// 1 byte spacer
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movq (r,x0), x6

	.I5:								// x5 = r[(data&31) << 4]; data >>= 5;
		nop								// 1 byte spacer
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movq (r,x0), x5

	.I4:								// x4 = r[(data&31) << 4]; data >>= 5;
		nop								// 1 byte spacer
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movq (r,x0), x4

	.I3:								// x3 = r[(data&31) << 4]; data >>= 5;
		nop								// 1 byte spacer
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movq (r,x0), x3

	.I2:								// x2 = r[(data&31) << 4]; data >>= 5;
		nop								// 1 byte spacer
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movq (r,x0), x2

	.I1:								// x1 = r[(data&31) << 4]; data >>= 5;
		nop								// 1 byte spacer
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movq (r,x0), x1

	.I0:								// x0 = r[(data&31) << 4]; data >>= 5;
		nop								// 1 byte spacer
		movq data10, x0
		andq $31,x0
        salq $4, x0
        sarq $5, data10
        movq (r,x0), x0

/*			// **STACK MANAGEMENT HERE**
		stp     fp, lr, [sp, -32]!			// save fp and lr 
		mov     fp, sp						// fp = sp
		stp     dest, xzr, [sp, 16]

	// branch
		tbnz    data10, 11, .SIMD_Return
	
	.Int_Return:
		blr     fn11						// call fn... so we can store in x0
		ldp     dest, xzr, [sp, 16]
		ldp     fp, lr, [sp], 32			// restore fp/lr

		str     x0, [dest]
		ret
		
	.SIMD_Return:
		blr     fn11						// call fn, so we can store in q0
		ldp     dest, xzr, [sp, 16]
		ldp     fp, lr, [sp], 32			// restore fp/lr
		
		str     q0, [dest]
		*/
#endif
		ret

#endif

/*
Observations so far:
 	* Use godbolt.org... its simpler than understanding the documentation. (The docs seem wrong too)
	* x87/MMX is unused on x86.
	* x86 has 6 regs for passing ints, the other two have to be done on the stack
*/

