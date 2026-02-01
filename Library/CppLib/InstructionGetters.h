
#define   U0_Li       ((( int)((Op)<<8))>>8)
#define   U0_Lu       (((uint)((Op)<<8))>>8)

#define   U1_Li       ((( int)((Op)<<13))>>13)
#define   U1_Lu       (((uint)((Op)<<13))>>13)

#define   U2_Li       ((( int)((Op)<<18))>>18)
#define   U2_Lu       (((uint)((Op)<<18))>>18)

#define   U3_Li       ((( int)((Op)<<23))>>23)
#define   U3_Lu       (((uint)((Op)<<23))>>23)

#define   U4_Li       ((( int)((Op)<<28))>>28)
#define   U4_Lu       (((uint)((Op)<<28))>>28)

#define   Func_JUMPi       ((( int)((Op)<<13))>>13)
#define   Func_JUMPu       (((uint)((Op)<<13))>>13)

#define   ForeignFunc_Tablei       ((( int)((Op)<<13))>>13)
#define   ForeignFunc_Tableu       (((uint)((Op)<<13))>>13)

#define   Tail_JUMPi       ((( int)((Op)<<8))>>8)
#define   Tail_JUMPu       (((uint)((Op)<<8))>>8)

#define   FuncAddr_Libraryi       ((( int)((Op)<<13))>>31)
#define   FuncAddr_Libraryu       (((uint)((Op)<<13))>>31)
#define   FuncAddr_Indexi       ((( int)((Op)<<14))>>14)
#define   FuncAddr_Indexu       (((uint)((Op)<<14))>>14)

#define   Alloc_Amounti       ((( int)((Op)<<13))>>13)
#define   Alloc_Amountu       (((uint)((Op)<<13))>>13)

#define   Jump_JUMPi       ((( int)((Op)<<8))>>8)
#define   Jump_JUMPu       (((uint)((Op)<<8))>>8)

#define   RotateConst_Roti       ((( int)((Op)<<13))>>26)
#define   RotateConst_Rotu       (((uint)((Op)<<13))>>26)
#define   RotateConst_Invi       ((( int)((Op)<<19))>>31)
#define   RotateConst_Invu       (((uint)((Op)<<19))>>31)
#define   RotateConst_Valuei       ((( int)((Op)<<20))>>20)
#define   RotateConst_Valueu       (((uint)((Op)<<20))>>20)

#define   JCmpEq_LSmalli       ((( int)((Op)<<18))>>31)
#define   JCmpEq_LSmallu       (((uint)((Op)<<18))>>31)
#define   JCmpEq_RSmalli       ((( int)((Op)<<19))>>31)
#define   JCmpEq_RSmallu       (((uint)((Op)<<19))>>31)
#define   JCmpEq_Jmpi       ((( int)((Op)<<20))>>20)
#define   JCmpEq_Jmpu       (((uint)((Op)<<20))>>20)

#define   HALT_SigNumi       ((( int)((Op)<<18))>>27)
#define   HALT_SigNumu       (((uint)((Op)<<18))>>27)
#define   HALT_Continuei       ((( int)((Op)<<23))>>28)
#define   HALT_Continueu       (((uint)((Op)<<23))>>28)
#define   HALT_Li       ((( int)((Op)<<27))>>27)
#define   HALT_Lu       (((uint)((Op)<<27))>>27)

#define   AddOrSubM_Shi       ((( int)((Op)<<23))>>26)
#define   AddOrSubM_Shu       (((uint)((Op)<<23))>>26)
#define   AddOrSubM_Li       ((( int)((Op)<<29))>>29)
#define   AddOrSubM_Lu       (((uint)((Op)<<29))>>29)

#define   TERN_Smalli       ((( int)((Op)<<28))>>31)
#define   TERN_Smallu       (((uint)((Op)<<28))>>31)
#define   TERN_Li       ((( int)((Op)<<29))>>29)
#define   TERN_Lu       (((uint)((Op)<<29))>>29)

#define   JCmpI_Cmpi       ((( int)((Op)<<18))>>28)
#define   JCmpI_Cmpu       (((uint)((Op)<<18))>>28)
#define   JCmpI_Jmpi       ((( int)((Op)<<22))>>22)
#define   JCmpI_Jmpu       (((uint)((Op)<<22))>>22)

#define   CmpI_Cmpi       ((( int)((Op)<<23))>>28)
#define   CmpI_Cmpu       (((uint)((Op)<<23))>>28)
#define   CmpI_Li       ((( int)((Op)<<27))>>27)
#define   CmpI_Lu       (((uint)((Op)<<27))>>27)

#define   CmpF_Cmpi       ((( int)((Op)<<23))>>28)
#define   CmpF_Cmpu       (((uint)((Op)<<23))>>28)
#define   CmpF_Li       ((( int)((Op)<<27))>>27)
#define   CmpF_Lu       (((uint)((Op)<<27))>>27)

#define   JCmpF_Cmpi       ((( int)((Op)<<18))>>29)
#define   JCmpF_Cmpu       (((uint)((Op)<<18))>>29)
#define   JCmpF_Jmpi       ((( int)((Op)<<21))>>21)
#define   JCmpF_Jmpu       (((uint)((Op)<<21))>>21)

#define   Compare4_Smalli       ((( int)((Op)<<28))>>31)
#define   Compare4_Smallu       (((uint)((Op)<<28))>>31)
#define   Compare4_Li       ((( int)((Op)<<29))>>29)
#define   Compare4_Lu       (((uint)((Op)<<29))>>29)

#define   JCmpK_Ki       ((( int)((Op)<<13))>>23)
#define   JCmpK_Ku       (((uint)((Op)<<13))>>23)
#define   JCmpK_Jmpi       ((( int)((Op)<<22))>>22)
#define   JCmpK_Jmpu       (((uint)((Op)<<22))>>22)

#define   Bra_Smalli       ((( int)((Op)<<13))>>31)
#define   Bra_Smallu       (((uint)((Op)<<13))>>31)
#define   Bra_Jmpi       ((( int)((Op)<<14))>>14)
#define   Bra_Jmpu       (((uint)((Op)<<14))>>14)

#define   Loop_Smalli       ((( int)((Op)<<18))>>31)
#define   Loop_Smallu       (((uint)((Op)<<18))>>31)
#define   Loop_Jmpi       ((( int)((Op)<<19))>>19)
#define   Loop_Jmpu       (((uint)((Op)<<19))>>19)

#define   GTable_Modei       ((( int)((Op)<<13))>>31)
#define   GTable_Modeu       (((uint)((Op)<<13))>>31)
#define   GTable_Addi       ((( int)((Op)<<14))>>14)
#define   GTable_Addu       (((uint)((Op)<<14))>>14)

#define   GObj_Modei       ((( int)((Op)<<13))>>31)
#define   GObj_Modeu       (((uint)((Op)<<13))>>31)
#define   GObj_Refi       ((( int)((Op)<<14))>>31)
#define   GObj_Refu       (((uint)((Op)<<14))>>31)
#define   GObj_Addi       ((( int)((Op)<<15))>>15)
#define   GObj_Addu       (((uint)((Op)<<15))>>15)

#define   Read_Offseti       ((( int)((Op)<<23))>>25)
#define   Read_Offsetu       (((uint)((Op)<<23))>>25)
#define   Read_movei       ((( int)((Op)<<30))>>30)
#define   Read_moveu       (((uint)((Op)<<30))>>30)

#define   Write_Offseti       ((( int)((Op)<<23))>>25)
#define   Write_Offsetu       (((uint)((Op)<<23))>>25)
#define   Write_movei       ((( int)((Op)<<30))>>30)
#define   Write_moveu       (((uint)((Op)<<30))>>30)

#define   MemUtil_Opi       ((( int)((Op)<<18))>>29)
#define   MemUtil_Opu       (((uint)((Op)<<18))>>29)
#define   MemUtil_Ni       ((( int)((Op)<<21))>>21)
#define   MemUtil_Nu       (((uint)((Op)<<21))>>21)

#define   CNTC_offseti       ((( int)((Op)<<18))>>26)
#define   CNTC_offsetu       (((uint)((Op)<<18))>>26)
#define   CNTC_cnsti       ((( int)((Op)<<24))>>26)
#define   CNTC_cnstu       (((uint)((Op)<<24))>>26)
#define   CNTC_sizei       ((( int)((Op)<<30))>>30)
#define   CNTC_sizeu       (((uint)((Op)<<30))>>30)

#define   BFLD_upi       ((( int)((Op)<<18))>>26)
#define   BFLD_upu       (((uint)((Op)<<18))>>26)
#define   BFLD_downi       ((( int)((Op)<<24))>>26)
#define   BFLD_downu       (((uint)((Op)<<24))>>26)
#define   BFLD_signi       ((( int)((Op)<<30))>>31)
#define   BFLD_signu       (((uint)((Op)<<30))>>31)
#define   BFLD_Li       ((( int)((Op)<<31))>>31)
#define   BFLD_Lu       (((uint)((Op)<<31))>>31)

#define   BFLS_upi       ((( int)((Op)<<18))>>26)
#define   BFLS_upu       (((uint)((Op)<<18))>>26)
#define   BFLS_downi       ((( int)((Op)<<24))>>26)
#define   BFLS_downu       (((uint)((Op)<<24))>>26)
#define   BFLS_signi       ((( int)((Op)<<30))>>31)
#define   BFLS_signu       (((uint)((Op)<<30))>>31)
#define   BFLS_Li       ((( int)((Op)<<31))>>31)
#define   BFLS_Lu       (((uint)((Op)<<31))>>31)

#define   Convert_Modei       ((( int)((Op)<<18))>>28)
#define   Convert_Modeu       (((uint)((Op)<<18))>>28)
#define   Convert_Li       ((( int)((Op)<<22))>>22)
#define   Convert_Lu       (((uint)((Op)<<22))>>22)

#define   RET_Valuei       ((( int)((Op)<<13))>>13)
#define   RET_Valueu       (((uint)((Op)<<13))>>13)

#define   REQ_Modei       ((( int)((Op)<<18))>>28)
#define   REQ_Modeu       (((uint)((Op)<<18))>>28)
#define   REQ_Vali       ((( int)((Op)<<22))>>22)
#define   REQ_Valu       (((uint)((Op)<<22))>>22)

#define   Div_Kindi       ((( int)((Op)<<28))>>30)
#define   Div_Kindu       (((uint)((Op)<<28))>>30)
#define   Div_Li       ((( int)((Op)<<30))>>30)
#define   Div_Lu       (((uint)((Op)<<30))>>30)

#define   Trap_Uponi       ((( int)((Op)<<13))>>13)
#define   Trap_Uponu       (((uint)((Op)<<13))>>13)

#define   Float_Di       ((( int)((Op)<<28))>>31)
#define   Float_Du       (((uint)((Op)<<28))>>31)
#define   Float_Li       ((( int)((Op)<<29))>>29)
#define   Float_Lu       (((uint)((Op)<<29))>>29)

#define   FloatConst_Highi       ((( int)((Op)<<18))>>18)
#define   FloatConst_Highu       (((uint)((Op)<<18))>>18)

#define   ConstStretchy_Condi       ((( int)((Op)<<13))>>31)
#define   ConstStretchy_Condu       (((uint)((Op)<<13))>>31)
#define   ConstStretchy_Invi       ((( int)((Op)<<14))>>31)
#define   ConstStretchy_Invu       (((uint)((Op)<<14))>>31)
#define   ConstStretchy_Valuei       ((( int)((Op)<<15))>>15)
#define   ConstStretchy_Valueu       (((uint)((Op)<<15))>>15)

#define   MemoryCopy_Lengthi       ((( int)((Op)<<18))>>18)
#define   MemoryCopy_Lengthu       (((uint)((Op)<<18))>>18)

#define   AddB_Ki       ((( int)((Op)<<13))>>13)
#define   AddB_Ku       (((uint)((Op)<<13))>>13)

#define   AddK_Ki       ((( int)((Op)<<18))>>18)
#define   AddK_Ku       (((uint)((Op)<<18))>>18)

#define   AddAK_Ki       ((( int)((Op)<<18))>>18)
#define   AddAK_Ku       (((uint)((Op)<<18))>>18)

#define   Div2_Cleari       ((( int)((Op)<<18))>>26)
#define   Div2_Clearu       (((uint)((Op)<<18))>>26)
#define   Div2_Downi       ((( int)((Op)<<24))>>26)
#define   Div2_Downu       (((uint)((Op)<<24))>>26)
#define   Div2_Li       ((( int)((Op)<<30))>>30)
#define   Div2_Lu       (((uint)((Op)<<30))>>30)

#define   Shift_Shi       ((( int)((Op)<<23))>>23)
#define   Shift_Shu       (((uint)((Op)<<23))>>23)

#define   Swap_Li       ((( int)((Op)<<28))>>28)
#define   Swap_Lu       (((uint)((Op)<<28))>>28)

#define   RefSet1_Li       ((( int)((Op)<<18))>>18)
#define   RefSet1_Lu       (((uint)((Op)<<18))>>18)

#define   RefReturn_Li       ((( int)((Op)<<28))>>28)
#define   RefReturn_Lu       (((uint)((Op)<<28))>>28)

#define   RefSetApart_Li       ((( int)((Op)<<23))>>23)
#define   RefSetApart_Lu       (((uint)((Op)<<23))>>23)

#define   RefSet2_Decri       ((( int)((Op)<<18))>>31)
#define   RefSet2_Decru       (((uint)((Op)<<18))>>31)
#define   RefSet2_Offseti       ((( int)((Op)<<19))>>19)
#define   RefSet2_Offsetu       (((uint)((Op)<<19))>>19)

#define   RefSet3_Decri       ((( int)((Op)<<18))>>31)
#define   RefSet3_Decru       (((uint)((Op)<<18))>>31)
#define   RefSet3_Offseti       ((( int)((Op)<<19))>>19)
#define   RefSet3_Offsetu       (((uint)((Op)<<19))>>19)

#define   RefDecrMem_Counti       ((( int)((Op)<<13))>>25)
#define   RefDecrMem_Countu       (((uint)((Op)<<13))>>25)
#define   RefDecrMem_Offseti       ((( int)((Op)<<20))>>20)
#define   RefDecrMem_Offsetu       (((uint)((Op)<<20))>>20)

#define   VecMix_Modei       ((( int)((Op)<<28))>>29)
#define   VecMix_Modeu       (((uint)((Op)<<28))>>29)
#define   VecMix_Li       ((( int)((Op)<<31))>>31)
#define   VecMix_Lu       (((uint)((Op)<<31))>>31)

#define   VecGet_Indi       ((( int)((Op)<<23))>>30)
#define   VecGet_Indu       (((uint)((Op)<<23))>>30)
#define   VecGet_Li       ((( int)((Op)<<25))>>25)
#define   VecGet_Lu       (((uint)((Op)<<25))>>25)

#define   VecSet_Indi       ((( int)((Op)<<23))>>30)
#define   VecSet_Indu       (((uint)((Op)<<23))>>30)
#define   VecSet_Li       ((( int)((Op)<<25))>>25)
#define   VecSet_Lu       (((uint)((Op)<<25))>>25)


#define   VecSwizzle_Fieldsi       ((( int)((Op)<<18))>>20)
#define   VecSwizzle_Fieldsu       (((uint)((Op)<<18))>>20)
#define   VecSwizzle_Li       ((( int)((Op)<<30))>>30)
#define   VecSwizzle_Lu       (((uint)((Op)<<30))>>30)

#define   VecConst_K1i       ((( int)((Op)<<13))>>13)
#define   VecConst_K1u       (((uint)((Op)<<13))>>13)

#define   VecInc_parti       ((( int)((Op)<<18))>>30)
#define   VecInc_partu       (((uint)((Op)<<18))>>30)
#define   VecInc_Amounti       ((( int)((Op)<<20))>>20)
#define   VecInc_Amountu       (((uint)((Op)<<20))>>20)
