#ifdef __aarch64__
	#define __realarm64__
#endif
#ifdef _M_ARM64
	#define __realarm64__
#endif


#ifdef __realarm64__


/*** StoreGreenRegs (u64* At) ***/
.text
.global _StoreGreenRegs
.align 4

_StoreGreenRegs:						// (u64 data, Fn0 fn, Register* r)
	stp     x19, x20, [x0]
	ret
	


/*** ReadGreenRegs (u64* From) ***/
.text
.global _ReadGreenRegs
.align 4

_ReadGreenRegs:
	ldp     x19, x20, [x0]
	ret



/*** Nativeize(u64 data, Fn0 fn, Register* r) ***/
.text
.global _Nativeize
.align 4

_Nativeize:								
	fli		.req x14
	flj		.req x13
	r		.req x12
	fn		.req x11
	data	.req x10
	j1		.req x8
	j2		.req x9
	
	//    (... prm4, prm3, prm2, prm1, prm0,) floats ints
	lsr     data, x0, 12			// data  = DATA>>12
	adr		flj,  floats
	adr		fli,  ints
	mov     fn,  x1					// fn    = FN
	mov     r,   x2					// r     = R
	and     j1,  x0, 15			    // j1    = DATA&15
	ubfx    j2,  x0, 4, 4			// j2    = (DATA>>4)&15
	add		j1,  j1, j1, lsl 1		// j1    = j1*3
	add		j2,  j2, j2, lsl 1		// j2    = j2*3
	add		j1,  flj, j1			// j1 adapt
	add		j2,  fli, j2			// j2 adapt
	br		j1 // jump
floats:
	
	lsr     x7, data, 35				// float-7
	ubfiz   x7, x7, 4, 5
	ldr     q7, [r, x7]
		
	lsr     x6, data, 30				// float-6
	ubfiz   x6, x6, 4, 5
	ldr     q6, [r, x6]
		
	lsr     x5, data, 25				// float-5
	ubfiz   x5, x5, 4, 5
	ldr     q5, [r, x5]
		
	lsr     x4, data, 20				// float-4
	ubfiz   x4, x4, 4, 5
	ldr     q4, [r, x4]
		
	lsr     x3, data, 15				// float-3
	ubfiz   x3, x3, 4, 5
	ldr     q3, [r, x3]
		
	lsr     x2, data, 10				// float-2
	ubfiz   x2, x2, 4, 5
	ldr     q2, [r, x2]
		
	lsr     x1, data,  5				// float-1
	ubfiz   x1, x2, 4, 5
	ldr     q1, [r, x1]
	
	lsr     x0, data, 0					// float-0
	ubfiz   x0, x0, 4, 5
	ldr     q0, [r, x0]	

	br j2

ints:
	
	lsr     x7, data, 35				// int-7
	ubfiz   x7, x7, 4, 5
	ldr     x7, [r, x7]
		
	lsr     x6, data, 30				// int-6
	ubfiz   x6, x6, 4, 5
	ldr     x6, [r, x6]
		
	lsr     x5, data, 25				// int-5
	ubfiz   x5, x5, 4, 5
	ldr     x5, [r, x5]
		
	lsr     x4, data, 20				// int-4
	ubfiz   x4, x4, 4, 5
	ldr     x4, [r, x4]
		
	lsr     x3, data, 15				// int-3
	ubfiz   x3, x3, 4, 5
	ldr     x3, [r, x3]
		
	lsr     x2, data, 10				// int-2
	ubfiz   x2, x2, 4, 5
	ldr     x2, [r, x2]
		
	lsr     x1, data,  5				// int-1
	ubfiz   x1, x2, 4, 5
	ldr     x1, [r, x1]
	
	lsr     x0, data, 0					// int-0
	ubfiz   x0, x0, 4, 5
	ldr     x0, [r, x0]	
	
	// how to save funcdata
	// we need to save r and data. Could we store a bit in r
	stp     fp, lr, [sp, -16]!			// save fp and lr 
	mov     fp, sp						// update fp with sp?
       
	blr     fn							// call fn!!
    ldp     fp, lr, [sp], 16			// restore some shit
    
	tbz     data, 8, SIMDReturn
	str     x0, [r]
	ret
SIMDReturn:
	str     q0, [r]
	ret
	
	
/*** END OF CODE 😭 ***/

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

