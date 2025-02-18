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
	.balign 4

	_Nativeize:						
		#define r   	%r15
		#define inj		%r14
		#define flj		%r13
		#define dest	%r12
		#define fn		%r11
		#define data	%r10
		#define j9		%r9
		#define j8		%r8
		#define x7  	%rsi // hope they don't use 7 int params
		#define x6  	%rsi // hope they don't use 7 int params
		#define x5  	%rsi
		#define x4  	%rdi
		#define x3  	%rdx
		#define x2  	%rcx
		#define x1  	%rbx
		#define x0  	%rax
		#define q7  	%xmm7
		#define q6  	%xmm6
		#define q5  	%xmm5
		#define q4  	%xmm4
		#define q3  	%xmm3
		#define q2  	%xmm2
		#define q1  	%xmm1
		#define q0  	%xmm0 // edi, esi, edx, ecx, r8d, r9d
#if 0
		movq		data, %rdi
		sarq		data, 12					// data = DATA>>12	// 12 is "invalid operand for instruction". why?
		movq		flj, .floats				// I know this is wrong but it compiles
		movq		inj, .ints					// Compiles even with "movq    inj, .DeFiNiTeLyNoTaLABEL"

		movq		fn,  x1						// fn    = FN
		movq		r,   x2						// r     = R

		movq		dest, r						// n <<= 4; dest = r+n
        salq		x3, 4						// fail // 4 is "invalid operand for instruction"
        addq		dest, x3

		movq		j8, x4
		sarq		j8, 6						// fail // 6 is "invalid operand for instruction"?
		andq		j8, 31						// j8    = (DATA>>6)&31

		movq		j9, x4
		andq		j9, 63						// j9    = DATA&63

		leaq		(j8,j8,2), j8				// j8    = j8*3
		leaq		(j9,j9,2), j9				// j9    = j9*3


		leaq		(flj,j8,2), j8				// j8 adapt
		leaq		(inj,j9,2), j9				// j9 adapt
		
		jmpq		j8							//  "invalid operand for instruction"?
	.floats:
											// float-7
/*		ubfiz   x7, data, 4, 5				// x7 = (data&31) << 4
		lsr     data, data,  5				// data = data >> 5
		ldr     q7,  [r, x7]				// q7 = r[x7]

		ubfiz   x6, data, 4, 5				// float-6
		lsr     data, data,  5	
		ldr     q6,  [r, x6]		

		ubfiz   x5, data, 4, 5				// float-5
		lsr     data, data,  5	
		ldr     q5,  [r, x5]		

		ubfiz   x4, data, 4, 5				// float-4
		lsr     data, data,  5	
		ldr     q4,  [r, x4]		

		ubfiz   x3, data, 4, 5				// float-3
		lsr     data, data,  5	
		ldr     q3,  [r, x3]		

		ubfiz   x2, data, 4, 5				// float-2
		lsr     data, data,  5	
		ldr     q2,  [r, x2]		

		ubfiz   x1, data, 4, 5				// float-1
		lsr     data, data,  5	
		ldr     q1,  [r, x1]		

		ubfiz   x0, data, 4, 5				// float-0
		lsr     data, data,  5	
		ldr     q0,  [r, x0]		

		br j9
		nop
		nop
*/

	.ints:
/*
											// int-7
		ubfiz   x7, data, 4, 5				// x7 = (data&31) << 4
		lsr     data, data,  5				// data = data >> 5
		ldr     x7,  [r, x7]				// x7 = r[x7]
			
		ubfiz   x6, data, 4, 5				// int-6
		lsr     data, data,  5
		ldr     x6,  [r, x6]
			
		ubfiz   x5, data, 4, 5				// int-5
		lsr     data, data,  5
		ldr     x5,  [r, x5]
			
		ubfiz   x4, data, 4, 5				// int-4
		lsr     data, data,  5
		ldr     x4,  [r, x4]
			
		ubfiz   x3, data, 4, 5				// int-3
		lsr     data, data,  5
		ldr     x3,  [r, x3]
			
		ubfiz   x2, data, 4, 5				// int-2
		lsr     data, data,  5
		ldr     x2,  [r, x2]
			
		ubfiz   x1, data, 4, 5				// int-1
		lsr     data, data,  5
		ldr     x1,  [r, x1]
		
		ubfiz   x0, data, 4, 5				// int-0
		ldr     x0,  [r, x0]
		nop
		
			// **STACK MANAGEMENT HERE**
		stp     fp, lr, [sp, -32]!			// save fp and lr 
		mov     fp, sp						// fp = sp
		stp     dest, xzr, [sp, 16]

	// branch
		tbnz    data, 11, .SIMD_Return
	
	.Int_Return:
		blr     fn							// call fn... so we can store in x0
		ldp     dest, xzr, [sp, 16]
		ldp     fp, lr, [sp], 32			// restore fp/lr

		str     x0, [dest]
		ret
		
	.SIMD_Return:
		blr     fn							// call fn, so we can store in q0
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
 	* Both ARM and x86 only have two register files! Despite what the docs say.
		* Both do it the same way. General/int in one place, and SIMD+FP in another.
		* x87/MMX is unused on x86.
	* x86 has 6 regs for passing ints, the other two have to be done on the stack
	* the FP/SIMD are also just done in order
		* we have enough regs on ARM&X86
	* You can't specify registers in C++, not reliably.
*/

