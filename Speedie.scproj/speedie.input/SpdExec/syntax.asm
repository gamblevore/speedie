//jb

tests oofit
	asm oofit (0)
		KNST  (r1, 18874368)
		KNST  (r1, 3458764513820540931)
		KNST  (r1, 123)
		KNST  (r4, 2)
		@test
		KNST  (r3, 555)
		KNST  (r3, -234)
		ADD   (r1, r1, r3, 0)
		PRNT  (r1,)				// -111
		LUPD  (r4, r0, @test)
		HALT  (r0,0,0)



/*
/* func find (str, b) {
    end = str.length
    if (end) {
        curr = str.addr
        end += curr
        loop:;
        if (*curr == b) {
            return curr - str.addr
        }
        if (++curr < end) {
            goto loop
        }
    }
    return -1
} */

    ASM program[] = {
		0,
        RD4,  // length
        BRA,  // if length
        RD4,  // curr
        ADD,  // end-ptr
		RD4,  // read-byte
		CMPN, // compare
		RD4,  // addr
		SUB,  // subtract
		RET,  // return
		LUPU, // (++curr < end)... go back
		SET1, // -1
		RET,  // return -1
		0, 
    };
*/
