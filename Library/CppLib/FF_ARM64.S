
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

#ifdef __aarch64__
	#define __realarm64__
#endif
#ifdef _M_ARM64
	#define __realarm64__
#endif

#ifdef __realarm64__
	/*** __CAKE_BRIDGE__(u64 DATA, void* FN, Register* R, int n) ***/
	.text
	.global ___CAKE_BRIDGE__
	.balign 4

	___CAKE_BRIDGE__:								
		r		.req x15
		inj		.req x14
		flj		.req x13
		dest	.req x12
		fn		.req x11
		data	.req x10
		j9		.req x9
		j8		.req x8

		lsr     data, x0, 12				// data  = DATA>>12
		adr		flj, .floats
		adr		inj, .ints
		mov     fn,  x1						// fn    = FN
		mov     r,   x2						// r     = R
		add     dest, r, x3, lsl 4			// dest  = R+n 
		ubfx    j8,  x0,  6,  5				// j8    = (DATA>>6)&31
		and     j9,  x0,  63				// j9    = DATA&63
		add		j8,  j8,  j8, lsl 1			// j8    = j8*3
		add		j9,  j9,  j9, lsl 1			// j9    = j9*3
		add		j8,  flj, j8, lsl 2			// j8 adapt
		add		j9,  inj, j9, lsl 2			// j9 adapt
		br		j8 // jump

	.floats:
											// float-7
		ubfiz   x7, data, 4, 5				// x7 = (data&31) << 4
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

	.ints:
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
		ret

/*** END OF CODE 😭 ***/


#endif



// http://ethernut.de/en/documents/arm-inline-asm.html
// http://modexp.wordpress.com/2018/10/30/arm64-assembly/
// http://wolchok.org/posts/how-to-read-arm64-assembly-language/

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

