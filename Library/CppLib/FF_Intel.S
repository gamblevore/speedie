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
#if 1
		movq		data, %rdi
		sarq		$12, data					// data = DATA>>12
		leaq		.Floats(%rip), flj
		leaq		.Ints(%rip), inj

		movq		fn,  x1						// fn    = FN
		movq		r,   x2						// r     = R

		movq		dest, r						// n <<= 4; dest = r+n
        salq		$4, x3
        addq		dest, x3

		movq		j8, x4
		sarq		$6, j8
		andq		j8, 31						// j8    = (DATA>>6)&31

		movq		j9, x4
		andq		j9, 63						// j9    = DATA&63

		leaq		(j8,j8,2), j8				// j8    = j8*3
		leaq		(j9,j9,2), j9				// j9    = j9*3


		leaq		(flj,j8,2), j8				// j8 adapt
		leaq		(inj,j9,2), j9				// j9 adapt

		jmpq *j8
		
	.Floats:
		.long .F7-.Floats
		.long .F6-.Floats
		.long .F5-.Floats
		.long .F4-.Floats
		.long .F3-.Floats
		.long .F2-.Floats
		.long .F1-.Floats
		.long .F0-.Floats		
	.Ints:
		.long .I7-.Ints
		.long .I6-.Ints
		.long .I5-.Ints
		.long .I4-.Ints
		.long .I3-.Ints
		.long .I2-.Ints
		.long .I1-.Ints
		.long .I0-.Ints		
	.F7:								// x7 = (data&31) << 4
		movq data, x7					// x7 = data
		andq x7, 31						// x7 &= 31
        salq $4, x7						// x7 <<= 4
        salq $5, data					// data = data >> 5
        movaps (r,x7), q7				// q7 = r[x7]
			
	.F6:								// x6 = (data&31) << 4
		movq data, x6					// x6 = data
		andq x6, 31						// x6 &= 31
        salq $4, x6						// x6 <<= 4
        salq $5, data					// data = data >> 5
        movaps (r,x6), q6				// q6 = r[x6]

	.F5:								// x5 = (data&31) << 4
		movq data, x5					// x5 = data
		andq x5, 31						// x5 &= 31
        salq $4, x5						// x5 <<= 4
        salq $5, data					// data = data >> 5
        movaps (r,x5), q5				// q5 = r[x5]

	.F4:								// x4 = (data&31) << 4
		movq data, x4					// x4 = data
		andq x4, 31						// x4 &= 31
        salq $4, x4						// x4 <<= 4
        salq $5, data					// data = data >> 5
        movaps (r,x4), q4				// q4 = r[x4]

	.F3:								// x3 = (data&31) << 4
		movq data, x3					// x3 = data
		andq x3, 31						// x3 &= 31
        salq $4, x3						// x3 <<= 4
        salq $5, data					// data = data >> 5
        movaps (r,x3), q3				// q3 = r[x3]

	#undef xx
	#define xx x2
	.F2:								// x2 = (data&31) << 4
		movq data, xx					// x2 = data
		andq xx, 31						// x2 &= 31
        salq $4, xx						// x2 <<= 4
        salq $5, data					// data = data >> 5
        movaps (r,xx), q2				// q2 = r[x2]

	#undef xx
	#define xx x1
	.F1:								// x1 = (data&31) << 4
		movq data, xx					// x1 = data
		andq xx, 31						// x1 &= 31
        salq $4, xx						// x1 <<= 4
        salq $5, data					// data = data >> 5
        movaps (r,xx), q1				// q1 = r[x1]

	#undef xx
	#define xx x0
	.F0:								// x0 = (data&31) << 4
		movq data, xx					// x0 = data
		andq xx, 31						// x0 &= 31
        salq $4, xx						// x0 <<= 4
        salq $5, data					// data = data >> 5
        movaps (r,xx), q0				// q0 = r[x0]
	

	.I7:
		decl %esi
		addq $4, %rdi

/*
		br j9
*/

//	ubfiz   x7, data, 4, 5				// x7 = (data&31) << 4
//	lsr     data, data,  5				// data = data >> 5
//	ldr     q7,  [r, x7]				// q7 = r[x7]
			
	.I6:
		movl (%rdi), %ecx
		cmpq $4, %rcx
		ja .F7
	.I5:
		movl (%rdi), %ecx
		cmpq $4, %rcx
		ja .F7
	.I4:
		movl (%rdi), %ecx
		cmpq $4, %rcx
		ja .F7
	.I3:
		movl (%rdi), %ecx
		cmpq $4, %rcx
		ja .F7
	.I2:
		movq data, x2					// x2 = data
		andq x2, 31						// x2 &= 31
        salq $4, x2						// x2 <<= 4
        salq $5, data					// data = data >> 5
        movq (r,x2), x2					// x2 = r[x2]

	.I1:								// x1 = (data&31) << 4
		movq data, x1					// x1 = data
		andq x1, 31						// x1 &= 31
        salq $4, x1						// x1 <<= 4
        salq $5, data					// data = data >> 5
        movq (r,x1), x1					// x1 = r[x1]

	.I0:								// x0 = (data&31) << 4
		movq data, x0					// x0 = data
		andq x0, 31						// x0 &= 31
        salq $4, x0						// x0 <<= 4
        salq $5, data					// data = data >> 5
        movq (r,x0), x0					// x0 = r[x0]

/*
		
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
	* x87/MMX is unused on x86.
	* x86 has 6 regs for passing ints, the other two have to be done on the stack
*/

