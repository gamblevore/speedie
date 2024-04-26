
#define   U0_Li       ((( int)((Op.Raw)<<8))>>8)
#define   U0_Li_(x)   ((( int)((x)<<8))>>8)

#define   U0_Lu       (((uint)((Op.Raw)<<8))>>8)
#define   U0_Lu_(x)   (((uint)((x)<<8))>>8)


#define   U1_Li       ((( int)((Op.Raw)<<13))>>13)
#define   U1_Li_(x)   ((( int)((x)<<13))>>13)

#define   U1_Lu       (((uint)((Op.Raw)<<13))>>13)
#define   U1_Lu_(x)   (((uint)((x)<<13))>>13)


#define   U2_Li       ((( int)((Op.Raw)<<18))>>18)
#define   U2_Li_(x)   ((( int)((x)<<18))>>18)

#define   U2_Lu       (((uint)((Op.Raw)<<18))>>18)
#define   U2_Lu_(x)   (((uint)((x)<<18))>>18)


#define   U3_Li       ((( int)((Op.Raw)<<23))>>23)
#define   U3_Li_(x)   ((( int)((x)<<23))>>23)

#define   U3_Lu       (((uint)((Op.Raw)<<23))>>23)
#define   U3_Lu_(x)   (((uint)((x)<<23))>>23)


#define   U4_Li       ((( int)((Op.Raw)<<28))>>28)
#define   U4_Li_(x)   ((( int)((x)<<28))>>28)

#define   U4_Lu       (((uint)((Op.Raw)<<28))>>28)
#define   U4_Lu_(x)   (((uint)((x)<<28))>>28)


#define   Func_SaveRegsu       (((uint)((Op.Raw)<<8))>>27)
#define   Func_SaveRegsu_(x)   (((uint)((x)<<8))>>27)

#define   Func_Incru       (((uint)((Op.Raw)<<13))>>31)
#define   Func_Incru_(x)   (((uint)((x)<<13))>>31)

#define   Func_JUMPi       ((( int)((Op.Raw)<<14))>>14)
#define   Func_JUMPi_(x)   ((( int)((x)<<14))>>14)

#define   Func_JUMPu       (((uint)((Op.Raw)<<14))>>14)
#define   Func_JUMPu_(x)   (((uint)((x)<<14))>>14)


#define   Cmp_Cmpu       (((uint)((Op.Raw)<<18))>>28)
#define   Cmp_Cmpu_(x)   (((uint)((x)<<18))>>28)

#define   Cmp_Li       ((( int)((Op.Raw)<<22))>>22)
#define   Cmp_Li_(x)   ((( int)((x)<<22))>>22)

#define   Cmp_Lu       (((uint)((Op.Raw)<<22))>>22)
#define   Cmp_Lu_(x)   (((uint)((x)<<22))>>22)


#define   CmpEq_Jmpi       ((( int)((Op.Raw)<<18))>>18)
#define   CmpEq_Jmpi_(x)   ((( int)((x)<<18))>>18)

#define   CmpEq_Jmpu       (((uint)((Op.Raw)<<18))>>18)
#define   CmpEq_Jmpu_(x)   (((uint)((x)<<18))>>18)


#define   Const_rotu       (((uint)((Op.Raw)<<13))>>26)
#define   Const_rotu_(x)   (((uint)((x)<<13))>>26)

#define   Const_Li       ((( int)((Op.Raw)<<19))>>19)
#define   Const_Li_(x)   ((( int)((x)<<19))>>19)

#define   Const_Lu       (((uint)((Op.Raw)<<19))>>19)
#define   Const_Lu_(x)   (((uint)((x)<<19))>>19)


#define   Bra_c1u       (((uint)((Op.Raw)<<13))>>30)
#define   Bra_c1u_(x)   (((uint)((x)<<13))>>30)

#define   Bra_jmpi       ((( int)((Op.Raw)<<15))>>15)
#define   Bra_jmpi_(x)   ((( int)((x)<<15))>>15)

#define   Bra_jmpu       (((uint)((Op.Raw)<<15))>>15)
#define   Bra_jmpu_(x)   (((uint)((x)<<15))>>15)


#define   Mem_moveu       (((uint)((Op.Raw)<<18))>>30)
#define   Mem_moveu_(x)   (((uint)((x)<<18))>>30)

#define   Mem_Li       ((( int)((Op.Raw)<<20))>>20)
#define   Mem_Li_(x)   ((( int)((x)<<20))>>20)

#define   Mem_Lu       (((uint)((Op.Raw)<<20))>>20)
#define   Mem_Lu_(x)   (((uint)((x)<<20))>>20)


#define   Setn_lenu       (((uint)((Op.Raw)<<8))>>30)
#define   Setn_lenu_(x)   (((uint)((x)<<8))>>30)

#define   Setn_Destu       (((uint)((Op.Raw)<<10))>>27)
#define   Setn_Destu_(x)   (((uint)((x)<<10))>>27)

#define   Setn_Condu       (((uint)((Op.Raw)<<15))>>30)
#define   Setn_Condu_(x)   (((uint)((x)<<15))>>30)

#define   Setn_Li       ((( int)((Op.Raw)<<17))>>17)
#define   Setn_Li_(x)   ((( int)((x)<<17))>>17)

#define   Setn_Lu       (((uint)((Op.Raw)<<17))>>17)
#define   Setn_Lu_(x)   (((uint)((x)<<17))>>17)


#define   CNTR_incru       (((uint)((Op.Raw)<<18))>>29)
#define   CNTR_incru_(x)   (((uint)((x)<<18))>>29)

#define   CNTR_sizeu       (((uint)((Op.Raw)<<21))>>30)
#define   CNTR_sizeu_(x)   (((uint)((x)<<21))>>30)

#define   CNTR_Li       ((( int)((Op.Raw)<<23))>>23)
#define   CNTR_Li_(x)   ((( int)((x)<<23))>>23)

#define   CNTR_Lu       (((uint)((Op.Raw)<<23))>>23)
#define   CNTR_Lu_(x)   (((uint)((x)<<23))>>23)


#define   CNTC_cnstu       (((uint)((Op.Raw)<<13))>>24)
#define   CNTC_cnstu_(x)   (((uint)((x)<<13))>>24)

#define   CNTC_sizeu       (((uint)((Op.Raw)<<21))>>30)
#define   CNTC_sizeu_(x)   (((uint)((x)<<21))>>30)

#define   CNTC_Li       ((( int)((Op.Raw)<<23))>>23)
#define   CNTC_Li_(x)   ((( int)((x)<<23))>>23)

#define   CNTC_Lu       (((uint)((Op.Raw)<<23))>>23)
#define   CNTC_Lu_(x)   (((uint)((x)<<23))>>23)


#define   BFLD_upu       (((uint)((Op.Raw)<<18))>>26)
#define   BFLD_upu_(x)   (((uint)((x)<<18))>>26)

#define   BFLD_downu       (((uint)((Op.Raw)<<24))>>26)
#define   BFLD_downu_(x)   (((uint)((x)<<24))>>26)

#define   BFLD_Li       ((( int)((Op.Raw)<<30))>>30)
#define   BFLD_Li_(x)   ((( int)((x)<<30))>>30)

#define   BFLD_Lu       (((uint)((Op.Raw)<<30))>>30)
#define   BFLD_Lu_(x)   (((uint)((x)<<30))>>30)


#define   SWAP_Au       (((uint)((Op.Raw)<<8))>>26)
#define   SWAP_Au_(x)   (((uint)((x)<<8))>>26)

#define   SWAP_Bu       (((uint)((Op.Raw)<<14))>>26)
#define   SWAP_Bu_(x)   (((uint)((x)<<14))>>26)

#define   SWAP_Cu       (((uint)((Op.Raw)<<20))>>26)
#define   SWAP_Cu_(x)   (((uint)((x)<<20))>>26)

#define   SWAP_Di       ((( int)((Op.Raw)<<26))>>26)
#define   SWAP_Di_(x)   ((( int)((x)<<26))>>26)

#define   SWAP_Du       (((uint)((Op.Raw)<<26))>>26)
#define   SWAP_Du_(x)   (((uint)((x)<<26))>>26)

