
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


#ifdef __x86_64__

	/*** Nativeize (u64 Data, void* FN, Register* R, int N) ***/
	.text
	.global _Nativeize
	.balign 4

	_Nativeize:
		// Volatile:  RDI, RSI, RDX, RCX, R8,  R9,    ...  R10, R11, RAX
		// Saved:     RBX, R12, R13, R14, R15
		// Stack:	  RBP, RSP
		
		#define q7  		%xmm7
		#define q6  		%xmm6
		#define q5  		%xmm5
		#define q4  		%xmm4
		#define q3  		%xmm3
		#define q2  		%xmm2
		#define q1  		%xmm1
		#define q0  		%xmm0
		
		#define x5			%r9
		#define x4			%r8
		#define x3  		%rcx
		#define x2  		%rdx
		#define x1  		%rsi 
		#define x0  		%rdi
		

		#define dest		%rcx		// needs push/pop
		
		#define xtemp		%r11		// temps
		#define DataPrm		%r10		// Used up till the call
		#define _FN_		%rax		// Used AT the call.
		#define RegFile		x0			// Not used after call
		
		#define int_jmp 	x5			// Finishes early
		#define flo_jmp		x4			// Finishes early
		
		#define ji			x3
		#define jf  		x2			// no!
		
		movq		x0,  DataPrm				// Data
		movq		x1,  _FN_					// FN
		movq		x2,  RegFile				// R

        salq		$4, x3						// n <<= 4;
		addq		x2, x3						// dest = r+n
		push		x3

		movq		DataPrm, ji
		movq		DataPrm, jf
		
		sarq		$12, DataPrm				// data = DATA>>12
		leaq		.F7(%rip), flo_jmp
		leaq		.I7(%rip), int_jmp
		
		andq		$63,ji 						// ji = DATA&63
		leaq		(ji,ji,4), ji				// ji = ji*5
		leaq		(int_jmp,ji,4), ji			// ji = int_jmp + ji*4

		sarq		$6, jf						// jf = (DATA>>6)&31
		andq		$31,jf 
		leaq		(jf,jf,4), jf				// jf = jf*5 // leaq can only multiply by pow2
		leaq		(flo_jmp,jf,4), jf			// jf = flo_jmp + jf*4

		jmpq		*jf

		.balign 4
	
	.F7:								// q7 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movaps (RegFile, xtemp), q7	
			
	.F6:								// q6 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movaps (RegFile, xtemp), q6

	.F5:								// q5 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movaps (RegFile, xtemp), q5

	.F4:								// q4 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movaps (RegFile, xtemp), q4

	.F3:								// q3 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movaps (RegFile, xtemp), q3

	.F2:								// q2 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movaps (RegFile, xtemp), q2

	.F1:								// q1 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movaps (RegFile, xtemp), q1

	.F0:								// q0 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movaps (RegFile, xtemp), q0
	
	.FCAP:
		jmpq *ji
		.balign 4
		nop;nop;nop;nop
		nop;nop;nop;nop
		nop;nop;nop;nop
		nop;nop;nop;nop

	.I7:
		nop;nop;nop;nop					// Speedie disallows over 6 ints/ptrs passed per func
		nop;nop;nop;nop					// None of the lib funcs needed 7 anyhow.
		nop;nop;nop;nop					// SystemV (Linux/MacOSX) only allows 6 ints to be passed directly.
		nop;nop;nop;nop					// Windows would need to use the stack. Sigh. 
		nop;nop;nop;nop 
					
	.I6:
		nop;nop;nop;nop
		nop;nop;nop;nop
		nop;nop;nop;nop
		nop;nop;nop;nop
		nop;nop;nop;nop 
	
	// INTEGERS //
	.I5:								// x5 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movq (RegFile, xtemp), x5
		.balign 4

	.I4:								// x4 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movq (RegFile, xtemp), x4
		.balign 4

	.I3:								// x3 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movq (RegFile, xtemp), x3
		.balign 4

	.I2:								// x2 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movq (RegFile, xtemp), x2
		.balign 4

	.I1:								// x1 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movq (RegFile, xtemp), x1
		.balign 4

	.I0:								// x0 = r[(data&31) << 4]; data >>= 5;
		movq DataPrm, xtemp
		andq $31, xtemp
        salq $4, xtemp
        sarq $5, DataPrm
        movq (RegFile, xtemp), x0


	.STACK:
			// **STACK MANAGEMENT HERE**
	testq    $2048, DataPrm 
	jne      .SIMD_Return
	.Int_Return:
	call     *_FN_							// call fn... so we can store in x0
	pop		dest ///
	movq    %rax, (dest)
	ret

	.SIMD_Return:
	call     *_FN_							// call fn... so we can store in x0
	pop		dest ///
	movaps  q0, (dest)
	ret

#endif

/*
Observations so far:
 	* Use godbolt.org... its simpler than understanding the documentation. (The docs seem wrong too)
	* x87/MMX is unused on x86.
	* x86 on osx/linux has 6 regs for passing ints, the other two get passed on the stack
		* Windows does it differently :/
*/

