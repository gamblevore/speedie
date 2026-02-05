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
		TIME  (r1,3)			// -111
		LUPD  (r4, r0, 0, @test)
		RET   (r0,,0)

