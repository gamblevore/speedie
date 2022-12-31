
#define   U0_Li       ((( int)((Op.Raw)<<7))>>7)
#define   U0_Li_(x)   ((( int)((x)<<7))>>7)

#define   U0_Lu       (((uint)((Op.Raw)<<7))>>7)
#define   U0_Lu_(x)   (((uint)((x)<<7))>>7)


#define   U1_Li       ((( int)((Op.Raw)<<12))>>12)
#define   U1_Li_(x)   ((( int)((x)<<12))>>12)

#define   U1_Lu       (((uint)((Op.Raw)<<12))>>12)
#define   U1_Lu_(x)   (((uint)((x)<<12))>>12)


#define   U2_Li       ((( int)((Op.Raw)<<17))>>17)
#define   U2_Li_(x)   ((( int)((x)<<17))>>17)

#define   U2_Lu       (((uint)((Op.Raw)<<17))>>17)
#define   U2_Lu_(x)   (((uint)((x)<<17))>>17)


#define   U3_Li       ((( int)((Op.Raw)<<22))>>22)
#define   U3_Li_(x)   ((( int)((x)<<22))>>22)

#define   U3_Lu       (((uint)((Op.Raw)<<22))>>22)
#define   U3_Lu_(x)   (((uint)((x)<<22))>>22)


#define   U4_Li       ((( int)((Op.Raw)<<27))>>27)
#define   U4_Li_(x)   ((( int)((x)<<27))>>27)

#define   U4_Lu       (((uint)((Op.Raw)<<27))>>27)
#define   U4_Lu_(x)   (((uint)((x)<<27))>>27)


#define   Func_Modeu       (((uint)((Op.Raw)<<7))>>30)
#define   Func_Modeu_(x)   (((uint)((x)<<7))>>30)

#define   Func_JUMPi       ((( int)((Op.Raw)<<9))>>9)
#define   Func_JUMPi_(x)   ((( int)((x)<<9))>>9)

#define   Func_JUMPu       (((uint)((Op.Raw)<<9))>>9)
#define   Func_JUMPu_(x)   (((uint)((x)<<9))>>9)


#define   Cmp_Cmpu       (((uint)((Op.Raw)<<17))>>28)
#define   Cmp_Cmpu_(x)   (((uint)((x)<<17))>>28)

#define   Cmp_Li       ((( int)((Op.Raw)<<21))>>21)
#define   Cmp_Li_(x)   ((( int)((x)<<21))>>21)

#define   Cmp_Lu       (((uint)((Op.Raw)<<21))>>21)
#define   Cmp_Lu_(x)   (((uint)((x)<<21))>>21)


#define   CmpEq_bytesu       (((uint)((Op.Raw)<<17))>>30)
#define   CmpEq_bytesu_(x)   (((uint)((x)<<17))>>30)

#define   CmpEq_Jmpi       ((( int)((Op.Raw)<<19))>>19)
#define   CmpEq_Jmpi_(x)   ((( int)((x)<<19))>>19)

#define   CmpEq_Jmpu       (((uint)((Op.Raw)<<19))>>19)
#define   CmpEq_Jmpu_(x)   (((uint)((x)<<19))>>19)


#define   Const_rotu       (((uint)((Op.Raw)<<12))>>26)
#define   Const_rotu_(x)   (((uint)((x)<<12))>>26)

#define   Const_Li       ((( int)((Op.Raw)<<18))>>18)
#define   Const_Li_(x)   ((( int)((x)<<18))>>18)

#define   Const_Lu       (((uint)((Op.Raw)<<18))>>18)
#define   Const_Lu_(x)   (((uint)((x)<<18))>>18)


#define   Bra_c1u       (((uint)((Op.Raw)<<12))>>30)
#define   Bra_c1u_(x)   (((uint)((x)<<12))>>30)

#define   Bra_jmpi       ((( int)((Op.Raw)<<14))>>14)
#define   Bra_jmpi_(x)   ((( int)((x)<<14))>>14)

#define   Bra_jmpu       (((uint)((Op.Raw)<<14))>>14)
#define   Bra_jmpu_(x)   (((uint)((x)<<14))>>14)


#define   Mem_incru       (((uint)((Op.Raw)<<17))>>30)
#define   Mem_incru_(x)   (((uint)((x)<<17))>>30)

#define   Mem_Li       ((( int)((Op.Raw)<<19))>>19)
#define   Mem_Li_(x)   ((( int)((x)<<19))>>19)

#define   Mem_Lu       (((uint)((Op.Raw)<<19))>>19)
#define   Mem_Lu_(x)   (((uint)((x)<<19))>>19)


#define   Setn_lenu       (((uint)((Op.Raw)<<7))>>30)
#define   Setn_lenu_(x)   (((uint)((x)<<7))>>30)

#define   Setn_Destu       (((uint)((Op.Raw)<<9))>>27)
#define   Setn_Destu_(x)   (((uint)((x)<<9))>>27)

#define   Setn_Condu       (((uint)((Op.Raw)<<14))>>30)
#define   Setn_Condu_(x)   (((uint)((x)<<14))>>30)

#define   Setn_Li       ((( int)((Op.Raw)<<16))>>16)
#define   Setn_Li_(x)   ((( int)((x)<<16))>>16)

#define   Setn_Lu       (((uint)((Op.Raw)<<16))>>16)
#define   Setn_Lu_(x)   (((uint)((x)<<16))>>16)


#define   CNTR_incru       (((uint)((Op.Raw)<<17))>>29)
#define   CNTR_incru_(x)   (((uint)((x)<<17))>>29)

#define   CNTR_sizeu       (((uint)((Op.Raw)<<20))>>30)
#define   CNTR_sizeu_(x)   (((uint)((x)<<20))>>30)

#define   CNTR_Li       ((( int)((Op.Raw)<<22))>>22)
#define   CNTR_Li_(x)   ((( int)((x)<<22))>>22)

#define   CNTR_Lu       (((uint)((Op.Raw)<<22))>>22)
#define   CNTR_Lu_(x)   (((uint)((x)<<22))>>22)


#define   CNTC_cnstu       (((uint)((Op.Raw)<<12))>>24)
#define   CNTC_cnstu_(x)   (((uint)((x)<<12))>>24)

#define   CNTC_sizeu       (((uint)((Op.Raw)<<20))>>30)
#define   CNTC_sizeu_(x)   (((uint)((x)<<20))>>30)

#define   CNTC_Li       ((( int)((Op.Raw)<<22))>>22)
#define   CNTC_Li_(x)   ((( int)((x)<<22))>>22)

#define   CNTC_Lu       (((uint)((Op.Raw)<<22))>>22)
#define   CNTC_Lu_(x)   (((uint)((x)<<22))>>22)


#define   BFLD_upu       (((uint)((Op.Raw)<<17))>>26)
#define   BFLD_upu_(x)   (((uint)((x)<<17))>>26)

#define   BFLD_downu       (((uint)((Op.Raw)<<23))>>26)
#define   BFLD_downu_(x)   (((uint)((x)<<23))>>26)

#define   BFLD_signi       ((( int)((Op.Raw)<<29))>>29)
#define   BFLD_signi_(x)   ((( int)((x)<<29))>>29)

#define   BFLD_signu       (((uint)((Op.Raw)<<29))>>29)
#define   BFLD_signu_(x)   (((uint)((x)<<29))>>29)


#define   SWAP_Au       (((uint)((Op.Raw)<<7))>>26)
#define   SWAP_Au_(x)   (((uint)((x)<<7))>>26)

#define   SWAP_Bu       (((uint)((Op.Raw)<<13))>>26)
#define   SWAP_Bu_(x)   (((uint)((x)<<13))>>26)

#define   SWAP_Cu       (((uint)((Op.Raw)<<19))>>26)
#define   SWAP_Cu_(x)   (((uint)((x)<<19))>>26)

#define   SWAP_Du       (((uint)((Op.Raw)<<25))>>26)
#define   SWAP_Du_(x)   (((uint)((x)<<25))>>26)

#define   SWAP_Li       ((( int)((Op.Raw)<<31))>>31)
#define   SWAP_Li_(x)   ((( int)((x)<<31))>>31)

#define   SWAP_Lu       (((uint)((Op.Raw)<<31))>>31)
#define   SWAP_Lu_(x)   (((uint)((x)<<31))>>31)

