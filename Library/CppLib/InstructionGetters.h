
#define   U0_Li       ((( int)((Op)<<8))>>8)
#define   U0_Li_(x)   ((( int)((x)<<8))>>8)

#define   U0_Lu       (((uint)((Op)<<8))>>8)
#define   U0_Lu_(x)   (((uint)((x)<<8))>>8)


#define   U1_Li       ((( int)((Op)<<13))>>13)
#define   U1_Li_(x)   ((( int)((x)<<13))>>13)

#define   U1_Lu       (((uint)((Op)<<13))>>13)
#define   U1_Lu_(x)   (((uint)((x)<<13))>>13)


#define   U2_Li       ((( int)((Op)<<18))>>18)
#define   U2_Li_(x)   ((( int)((x)<<18))>>18)

#define   U2_Lu       (((uint)((Op)<<18))>>18)
#define   U2_Lu_(x)   (((uint)((x)<<18))>>18)


#define   U3_Li       ((( int)((Op)<<23))>>23)
#define   U3_Li_(x)   ((( int)((x)<<23))>>23)

#define   U3_Lu       (((uint)((Op)<<23))>>23)
#define   U3_Lu_(x)   (((uint)((x)<<23))>>23)


#define   U4_Li       ((( int)((Op)<<28))>>28)
#define   U4_Li_(x)   ((( int)((x)<<28))>>28)

#define   U4_Lu       (((uint)((Op)<<28))>>28)
#define   U4_Lu_(x)   (((uint)((x)<<28))>>28)


#define   Func_JUMPi       ((( int)((Op)<<13))>>13)
#define   Func_JUMPi_(x)   ((( int)((x)<<13))>>13)

#define   Func_JUMPu       (((uint)((Op)<<13))>>13)
#define   Func_JUMPu_(x)   (((uint)((x)<<13))>>13)


#define   ForeignFunc_Tablei       ((( int)((Op)<<13))>>13)
#define   ForeignFunc_Tablei_(x)   ((( int)((x)<<13))>>13)

#define   ForeignFunc_Tableu       (((uint)((Op)<<13))>>13)
#define   ForeignFunc_Tableu_(x)   (((uint)((x)<<13))>>13)


#define   Tail_JUMPi       ((( int)((Op)<<8))>>8)
#define   Tail_JUMPi_(x)   ((( int)((x)<<8))>>8)

#define   Tail_JUMPu       (((uint)((Op)<<8))>>8)
#define   Tail_JUMPu_(x)   (((uint)((x)<<8))>>8)


#define   Alloc_Amounti       ((( int)((Op)<<13))>>13)
#define   Alloc_Amounti_(x)   ((( int)((x)<<13))>>13)

#define   Alloc_Amountu       (((uint)((Op)<<13))>>13)
#define   Alloc_Amountu_(x)   (((uint)((x)<<13))>>13)


#define   Jump_JUMPi       ((( int)((Op)<<8))>>8)
#define   Jump_JUMPi_(x)   ((( int)((x)<<8))>>8)

#define   Jump_JUMPu       (((uint)((Op)<<8))>>8)
#define   Jump_JUMPu_(x)   (((uint)((x)<<8))>>8)


#define   RotateConst_Roti       ((( int)((Op)<<13))>>26)
#define   RotateConst_Roti_(x)   ((( int)((x)<<13))>>26)

#define   RotateConst_Rotu       (((uint)((Op)<<13))>>26)
#define   RotateConst_Rotu_(x)   (((uint)((x)<<13))>>26)

#define   RotateConst_Invi       ((( int)((Op)<<19))>>31)
#define   RotateConst_Invi_(x)   ((( int)((x)<<19))>>31)

#define   RotateConst_Invu       (((uint)((Op)<<19))>>31)
#define   RotateConst_Invu_(x)   (((uint)((x)<<19))>>31)

#define   RotateConst_Valuei       ((( int)((Op)<<20))>>20)
#define   RotateConst_Valuei_(x)   ((( int)((x)<<20))>>20)

#define   RotateConst_Valueu       (((uint)((Op)<<20))>>20)
#define   RotateConst_Valueu_(x)   (((uint)((x)<<20))>>20)


#define   JCmpEq_Bigi       ((( int)((Op)<<18))>>31)
#define   JCmpEq_Bigi_(x)   ((( int)((x)<<18))>>31)

#define   JCmpEq_Bigu       (((uint)((Op)<<18))>>31)
#define   JCmpEq_Bigu_(x)   (((uint)((x)<<18))>>31)

#define   JCmpEq_Jmpi       ((( int)((Op)<<19))>>19)
#define   JCmpEq_Jmpi_(x)   ((( int)((x)<<19))>>19)

#define   JCmpEq_Jmpu       (((uint)((Op)<<19))>>19)
#define   JCmpEq_Jmpu_(x)   (((uint)((x)<<19))>>19)


#define   HALT_IsOKi       ((( int)((Op)<<28))>>28)
#define   HALT_IsOKi_(x)   ((( int)((x)<<28))>>28)

#define   HALT_IsOKu       (((uint)((Op)<<28))>>28)
#define   HALT_IsOKu_(x)   (((uint)((x)<<28))>>28)


#define   Compare4_Cleari       ((( int)((Op)<<28))>>29)
#define   Compare4_Cleari_(x)   ((( int)((x)<<28))>>29)

#define   Compare4_Clearu       (((uint)((Op)<<28))>>29)
#define   Compare4_Clearu_(x)   (((uint)((x)<<28))>>29)

#define   Compare4_Li       ((( int)((Op)<<31))>>31)
#define   Compare4_Li_(x)   ((( int)((x)<<31))>>31)

#define   Compare4_Lu       (((uint)((Op)<<31))>>31)
#define   Compare4_Lu_(x)   (((uint)((x)<<31))>>31)


#define   AddOrSubM_Shi       ((( int)((Op)<<23))>>26)
#define   AddOrSubM_Shi_(x)   ((( int)((x)<<23))>>26)

#define   AddOrSubM_Shu       (((uint)((Op)<<23))>>26)
#define   AddOrSubM_Shu_(x)   (((uint)((x)<<23))>>26)

#define   AddOrSubM_Li       ((( int)((Op)<<29))>>29)
#define   AddOrSubM_Li_(x)   ((( int)((x)<<29))>>29)

#define   AddOrSubM_Lu       (((uint)((Op)<<29))>>29)
#define   AddOrSubM_Lu_(x)   (((uint)((x)<<29))>>29)


#define   JCmpF_Cmpi       ((( int)((Op)<<18))>>29)
#define   JCmpF_Cmpi_(x)   ((( int)((x)<<18))>>29)

#define   JCmpF_Cmpu       (((uint)((Op)<<18))>>29)
#define   JCmpF_Cmpu_(x)   (((uint)((x)<<18))>>29)

#define   JCmpF_Jmpi       ((( int)((Op)<<21))>>21)
#define   JCmpF_Jmpi_(x)   ((( int)((x)<<21))>>21)

#define   JCmpF_Jmpu       (((uint)((Op)<<21))>>21)
#define   JCmpF_Jmpu_(x)   (((uint)((x)<<21))>>21)


#define   JCmpI_Cmpi       ((( int)((Op)<<18))>>30)
#define   JCmpI_Cmpi_(x)   ((( int)((x)<<18))>>30)

#define   JCmpI_Cmpu       (((uint)((Op)<<18))>>30)
#define   JCmpI_Cmpu_(x)   (((uint)((x)<<18))>>30)

#define   JCmpI_Jmpi       ((( int)((Op)<<20))>>20)
#define   JCmpI_Jmpi_(x)   ((( int)((x)<<20))>>20)

#define   JCmpI_Jmpu       (((uint)((Op)<<20))>>20)
#define   JCmpI_Jmpu_(x)   (((uint)((x)<<20))>>20)


#define   JCmpK_Ki       ((( int)((Op)<<13))>>23)
#define   JCmpK_Ki_(x)   ((( int)((x)<<13))>>23)

#define   JCmpK_Ku       (((uint)((Op)<<13))>>23)
#define   JCmpK_Ku_(x)   (((uint)((x)<<13))>>23)

#define   JCmpK_Jmpi       ((( int)((Op)<<22))>>22)
#define   JCmpK_Jmpi_(x)   ((( int)((x)<<22))>>22)

#define   JCmpK_Jmpu       (((uint)((Op)<<22))>>22)
#define   JCmpK_Jmpu_(x)   (((uint)((x)<<22))>>22)


#define   Bra_Bytezi       ((( int)((Op)<<13))>>30)
#define   Bra_Bytezi_(x)   ((( int)((x)<<13))>>30)

#define   Bra_Bytezu       (((uint)((Op)<<13))>>30)
#define   Bra_Bytezu_(x)   (((uint)((x)<<13))>>30)

#define   Bra_Jmpi       ((( int)((Op)<<15))>>15)
#define   Bra_Jmpi_(x)   ((( int)((x)<<15))>>15)

#define   Bra_Jmpu       (((uint)((Op)<<15))>>15)
#define   Bra_Jmpu_(x)   (((uint)((x)<<15))>>15)


#define   Loop_Jmpi       ((( int)((Op)<<18))>>18)
#define   Loop_Jmpi_(x)   ((( int)((x)<<18))>>18)

#define   Loop_Jmpu       (((uint)((Op)<<18))>>18)
#define   Loop_Jmpu_(x)   (((uint)((x)<<18))>>18)


#define   Table_Modei       ((( int)((Op)<<13))>>31)
#define   Table_Modei_(x)   ((( int)((x)<<13))>>31)

#define   Table_Modeu       (((uint)((Op)<<13))>>31)
#define   Table_Modeu_(x)   (((uint)((x)<<13))>>31)

#define   Table_Addi       ((( int)((Op)<<14))>>14)
#define   Table_Addi_(x)   ((( int)((x)<<14))>>14)

#define   Table_Addu       (((uint)((Op)<<14))>>14)
#define   Table_Addu_(x)   (((uint)((x)<<14))>>14)


#define   Read_Offseti       ((( int)((Op)<<23))>>25)
#define   Read_Offseti_(x)   ((( int)((x)<<23))>>25)

#define   Read_Offsetu       (((uint)((Op)<<23))>>25)
#define   Read_Offsetu_(x)   (((uint)((x)<<23))>>25)

#define   Read_movei       ((( int)((Op)<<30))>>30)
#define   Read_movei_(x)   ((( int)((x)<<30))>>30)

#define   Read_moveu       (((uint)((Op)<<30))>>30)
#define   Read_moveu_(x)   (((uint)((x)<<30))>>30)


#define   Write_Offseti       ((( int)((Op)<<23))>>25)
#define   Write_Offseti_(x)   ((( int)((x)<<23))>>25)

#define   Write_Offsetu       (((uint)((Op)<<23))>>25)
#define   Write_Offsetu_(x)   (((uint)((x)<<23))>>25)

#define   Write_movei       ((( int)((Op)<<30))>>30)
#define   Write_movei_(x)   ((( int)((x)<<30))>>30)

#define   Write_moveu       (((uint)((Op)<<30))>>30)
#define   Write_moveu_(x)   (((uint)((x)<<30))>>30)


#define   MemUtil_Opi       ((( int)((Op)<<18))>>29)
#define   MemUtil_Opi_(x)   ((( int)((x)<<18))>>29)

#define   MemUtil_Opu       (((uint)((Op)<<18))>>29)
#define   MemUtil_Opu_(x)   (((uint)((x)<<18))>>29)

#define   MemUtil_Ni       ((( int)((Op)<<21))>>21)
#define   MemUtil_Ni_(x)   ((( int)((x)<<21))>>21)

#define   MemUtil_Nu       (((uint)((Op)<<21))>>21)
#define   MemUtil_Nu_(x)   (((uint)((x)<<21))>>21)


#define   CNTC_offseti       ((( int)((Op)<<18))>>27)
#define   CNTC_offseti_(x)   ((( int)((x)<<18))>>27)

#define   CNTC_offsetu       (((uint)((Op)<<18))>>27)
#define   CNTC_offsetu_(x)   (((uint)((x)<<18))>>27)

#define   CNTC_cnsti       ((( int)((Op)<<23))>>25)
#define   CNTC_cnsti_(x)   ((( int)((x)<<23))>>25)

#define   CNTC_cnstu       (((uint)((Op)<<23))>>25)
#define   CNTC_cnstu_(x)   (((uint)((x)<<23))>>25)

#define   CNTC_sizei       ((( int)((Op)<<30))>>30)
#define   CNTC_sizei_(x)   ((( int)((x)<<30))>>30)

#define   CNTC_sizeu       (((uint)((Op)<<30))>>30)
#define   CNTC_sizeu_(x)   (((uint)((x)<<30))>>30)


#define   BFLD_upi       ((( int)((Op)<<18))>>26)
#define   BFLD_upi_(x)   ((( int)((x)<<18))>>26)

#define   BFLD_upu       (((uint)((Op)<<18))>>26)
#define   BFLD_upu_(x)   (((uint)((x)<<18))>>26)

#define   BFLD_downi       ((( int)((Op)<<24))>>26)
#define   BFLD_downi_(x)   ((( int)((x)<<24))>>26)

#define   BFLD_downu       (((uint)((Op)<<24))>>26)
#define   BFLD_downu_(x)   (((uint)((x)<<24))>>26)

#define   BFLD_signi       ((( int)((Op)<<30))>>31)
#define   BFLD_signi_(x)   ((( int)((x)<<30))>>31)

#define   BFLD_signu       (((uint)((Op)<<30))>>31)
#define   BFLD_signu_(x)   (((uint)((x)<<30))>>31)

#define   BFLD_Li       ((( int)((Op)<<31))>>31)
#define   BFLD_Li_(x)   ((( int)((x)<<31))>>31)

#define   BFLD_Lu       (((uint)((Op)<<31))>>31)
#define   BFLD_Lu_(x)   (((uint)((x)<<31))>>31)


#define   CmpB_Invi       ((( int)((Op)<<23))>>29)
#define   CmpB_Invi_(x)   ((( int)((x)<<23))>>29)

#define   CmpB_Invu       (((uint)((Op)<<23))>>29)
#define   CmpB_Invu_(x)   (((uint)((x)<<23))>>29)

#define   CmpB_Li       ((( int)((Op)<<26))>>26)
#define   CmpB_Li_(x)   ((( int)((x)<<26))>>26)

#define   CmpB_Lu       (((uint)((Op)<<26))>>26)
#define   CmpB_Lu_(x)   (((uint)((x)<<26))>>26)


#define   Convert_Modei       ((( int)((Op)<<18))>>28)
#define   Convert_Modei_(x)   ((( int)((x)<<18))>>28)

#define   Convert_Modeu       (((uint)((Op)<<18))>>28)
#define   Convert_Modeu_(x)   (((uint)((x)<<18))>>28)

#define   Convert_Li       ((( int)((Op)<<22))>>22)
#define   Convert_Li_(x)   ((( int)((x)<<22))>>22)

#define   Convert_Lu       (((uint)((Op)<<22))>>22)
#define   Convert_Lu_(x)   (((uint)((x)<<22))>>22)


#define   RET_SafeDecri       ((( int)((Op)<<23))>>31)
#define   RET_SafeDecri_(x)   ((( int)((x)<<23))>>31)

#define   RET_SafeDecru       (((uint)((Op)<<23))>>31)
#define   RET_SafeDecru_(x)   (((uint)((x)<<23))>>31)

#define   RET_Valuei       ((( int)((Op)<<24))>>24)
#define   RET_Valuei_(x)   ((( int)((x)<<24))>>24)

#define   RET_Valueu       (((uint)((Op)<<24))>>24)
#define   RET_Valueu_(x)   (((uint)((x)<<24))>>24)


#define   REQ_Modei       ((( int)((Op)<<18))>>28)
#define   REQ_Modei_(x)   ((( int)((x)<<18))>>28)

#define   REQ_Modeu       (((uint)((Op)<<18))>>28)
#define   REQ_Modeu_(x)   (((uint)((x)<<18))>>28)

#define   REQ_Vali       ((( int)((Op)<<22))>>22)
#define   REQ_Vali_(x)   ((( int)((x)<<22))>>22)

#define   REQ_Valu       (((uint)((Op)<<22))>>22)
#define   REQ_Valu_(x)   (((uint)((x)<<22))>>22)


#define   Div_Kindi       ((( int)((Op)<<28))>>30)
#define   Div_Kindi_(x)   ((( int)((x)<<28))>>30)

#define   Div_Kindu       (((uint)((Op)<<28))>>30)
#define   Div_Kindu_(x)   (((uint)((x)<<28))>>30)

#define   Div_Li       ((( int)((Op)<<30))>>30)
#define   Div_Li_(x)   ((( int)((x)<<30))>>30)

#define   Div_Lu       (((uint)((Op)<<30))>>30)
#define   Div_Lu_(x)   (((uint)((x)<<30))>>30)


#define   Trap_Modei       ((( int)((Op)<<13))>>30)
#define   Trap_Modei_(x)   ((( int)((x)<<13))>>30)

#define   Trap_Modeu       (((uint)((Op)<<13))>>30)
#define   Trap_Modeu_(x)   (((uint)((x)<<13))>>30)

#define   Trap_Signali       ((( int)((Op)<<15))>>26)
#define   Trap_Signali_(x)   ((( int)((x)<<15))>>26)

#define   Trap_Signalu       (((uint)((Op)<<15))>>26)
#define   Trap_Signalu_(x)   (((uint)((x)<<15))>>26)

#define   Trap_Li       ((( int)((Op)<<21))>>21)
#define   Trap_Li_(x)   ((( int)((x)<<21))>>21)

#define   Trap_Lu       (((uint)((Op)<<21))>>21)
#define   Trap_Lu_(x)   (((uint)((x)<<21))>>21)


#define   Float_Di       ((( int)((Op)<<28))>>31)
#define   Float_Di_(x)   ((( int)((x)<<28))>>31)

#define   Float_Du       (((uint)((Op)<<28))>>31)
#define   Float_Du_(x)   (((uint)((x)<<28))>>31)

#define   Float_Li       ((( int)((Op)<<29))>>29)
#define   Float_Li_(x)   ((( int)((x)<<29))>>29)

#define   Float_Lu       (((uint)((Op)<<29))>>29)
#define   Float_Lu_(x)   (((uint)((x)<<29))>>29)


#define   FloatConst_Highi       ((( int)((Op)<<18))>>18)
#define   FloatConst_Highi_(x)   ((( int)((x)<<18))>>18)

#define   FloatConst_Highu       (((uint)((Op)<<18))>>18)
#define   FloatConst_Highu_(x)   (((uint)((x)<<18))>>18)


#define   ConstStretchy_Condi       ((( int)((Op)<<13))>>31)
#define   ConstStretchy_Condi_(x)   ((( int)((x)<<13))>>31)

#define   ConstStretchy_Condu       (((uint)((Op)<<13))>>31)
#define   ConstStretchy_Condu_(x)   (((uint)((x)<<13))>>31)

#define   ConstStretchy_Invi       ((( int)((Op)<<14))>>31)
#define   ConstStretchy_Invi_(x)   ((( int)((x)<<14))>>31)

#define   ConstStretchy_Invu       (((uint)((Op)<<14))>>31)
#define   ConstStretchy_Invu_(x)   (((uint)((x)<<14))>>31)

#define   ConstStretchy_Valuei       ((( int)((Op)<<15))>>15)
#define   ConstStretchy_Valuei_(x)   ((( int)((x)<<15))>>15)

#define   ConstStretchy_Valueu       (((uint)((Op)<<15))>>15)
#define   ConstStretchy_Valueu_(x)   (((uint)((x)<<15))>>15)


#define   ConstGlobal_Valuei       ((( int)((Op)<<13))>>15)
#define   ConstGlobal_Valuei_(x)   ((( int)((x)<<13))>>15)

#define   ConstGlobal_Valueu       (((uint)((Op)<<13))>>15)
#define   ConstGlobal_Valueu_(x)   (((uint)((x)<<13))>>15)

#define   ConstGlobal_Li       ((( int)((Op)<<30))>>30)
#define   ConstGlobal_Li_(x)   ((( int)((x)<<30))>>30)

#define   ConstGlobal_Lu       (((uint)((Op)<<30))>>30)
#define   ConstGlobal_Lu_(x)   (((uint)((x)<<30))>>30)


#define   AddK_Ki       ((( int)((Op)<<18))>>18)
#define   AddK_Ki_(x)   ((( int)((x)<<18))>>18)

#define   AddK_Ku       (((uint)((Op)<<18))>>18)
#define   AddK_Ku_(x)   (((uint)((x)<<18))>>18)


#define   Div2_Shi       ((( int)((Op)<<18))>>26)
#define   Div2_Shi_(x)   ((( int)((x)<<18))>>26)

#define   Div2_Shu       (((uint)((Op)<<18))>>26)
#define   Div2_Shu_(x)   (((uint)((x)<<18))>>26)

#define   Div2_Cleari       ((( int)((Op)<<24))>>29)
#define   Div2_Cleari_(x)   ((( int)((x)<<24))>>29)

#define   Div2_Clearu       (((uint)((Op)<<24))>>29)
#define   Div2_Clearu_(x)   (((uint)((x)<<24))>>29)

#define   Div2_Li       ((( int)((Op)<<27))>>27)
#define   Div2_Li_(x)   ((( int)((x)<<27))>>27)

#define   Div2_Lu       (((uint)((Op)<<27))>>27)
#define   Div2_Lu_(x)   (((uint)((x)<<27))>>27)


#define   Shift_Shi       ((( int)((Op)<<23))>>23)
#define   Shift_Shi_(x)   ((( int)((x)<<23))>>23)

#define   Shift_Shu       (((uint)((Op)<<23))>>23)
#define   Shift_Shu_(x)   (((uint)((x)<<23))>>23)


#define   Swap_Li       ((( int)((Op)<<28))>>28)
#define   Swap_Li_(x)   ((( int)((x)<<28))>>28)

#define   Swap_Lu       (((uint)((Op)<<28))>>28)
#define   Swap_Lu_(x)   (((uint)((x)<<28))>>28)


#define   RefSetCode_Codei       ((( int)((Op)<<18))>>28)
#define   RefSetCode_Codei_(x)   ((( int)((x)<<18))>>28)

#define   RefSetCode_Codeu       (((uint)((Op)<<18))>>28)
#define   RefSetCode_Codeu_(x)   (((uint)((x)<<18))>>28)

#define   RefSetCode_Li       ((( int)((Op)<<22))>>22)
#define   RefSetCode_Li_(x)   ((( int)((x)<<22))>>22)

#define   RefSetCode_Lu       (((uint)((Op)<<22))>>22)
#define   RefSetCode_Lu_(x)   (((uint)((x)<<22))>>22)


#define   RefSet1_Li       ((( int)((Op)<<18))>>18)
#define   RefSet1_Li_(x)   ((( int)((x)<<18))>>18)

#define   RefSet1_Lu       (((uint)((Op)<<18))>>18)
#define   RefSet1_Lu_(x)   (((uint)((x)<<18))>>18)


#define   RefSetApart_Li       ((( int)((Op)<<23))>>23)
#define   RefSetApart_Li_(x)   ((( int)((x)<<23))>>23)

#define   RefSetApart_Lu       (((uint)((Op)<<23))>>23)
#define   RefSetApart_Lu_(x)   (((uint)((x)<<23))>>23)


#define   RefSet2_Decri       ((( int)((Op)<<18))>>31)
#define   RefSet2_Decri_(x)   ((( int)((x)<<18))>>31)

#define   RefSet2_Decru       (((uint)((Op)<<18))>>31)
#define   RefSet2_Decru_(x)   (((uint)((x)<<18))>>31)

#define   RefSet2_Offseti       ((( int)((Op)<<19))>>19)
#define   RefSet2_Offseti_(x)   ((( int)((x)<<19))>>19)

#define   RefSet2_Offsetu       (((uint)((Op)<<19))>>19)
#define   RefSet2_Offsetu_(x)   (((uint)((x)<<19))>>19)


#define   RefSet3_Decri       ((( int)((Op)<<18))>>31)
#define   RefSet3_Decri_(x)   ((( int)((x)<<18))>>31)

#define   RefSet3_Decru       (((uint)((Op)<<18))>>31)
#define   RefSet3_Decru_(x)   (((uint)((x)<<18))>>31)

#define   RefSet3_Offseti       ((( int)((Op)<<19))>>19)
#define   RefSet3_Offseti_(x)   ((( int)((x)<<19))>>19)

#define   RefSet3_Offsetu       (((uint)((Op)<<19))>>19)
#define   RefSet3_Offsetu_(x)   (((uint)((x)<<19))>>19)


#define   RefDecrMem_Counti       ((( int)((Op)<<13))>>25)
#define   RefDecrMem_Counti_(x)   ((( int)((x)<<13))>>25)

#define   RefDecrMem_Countu       (((uint)((Op)<<13))>>25)
#define   RefDecrMem_Countu_(x)   (((uint)((x)<<13))>>25)

#define   RefDecrMem_Offseti       ((( int)((Op)<<20))>>20)
#define   RefDecrMem_Offseti_(x)   ((( int)((x)<<20))>>20)

#define   RefDecrMem_Offsetu       (((uint)((Op)<<20))>>20)
#define   RefDecrMem_Offsetu_(x)   (((uint)((x)<<20))>>20)


#define   VecMix_Modei       ((( int)((Op)<<28))>>29)
#define   VecMix_Modei_(x)   ((( int)((x)<<28))>>29)

#define   VecMix_Modeu       (((uint)((Op)<<28))>>29)
#define   VecMix_Modeu_(x)   (((uint)((x)<<28))>>29)

#define   VecMix_Li       ((( int)((Op)<<31))>>31)
#define   VecMix_Li_(x)   ((( int)((x)<<31))>>31)

#define   VecMix_Lu       (((uint)((Op)<<31))>>31)
#define   VecMix_Lu_(x)   (((uint)((x)<<31))>>31)


#define   VecGet_Indi       ((( int)((Op)<<23))>>30)
#define   VecGet_Indi_(x)   ((( int)((x)<<23))>>30)

#define   VecGet_Indu       (((uint)((Op)<<23))>>30)
#define   VecGet_Indu_(x)   (((uint)((x)<<23))>>30)

#define   VecGet_Li       ((( int)((Op)<<25))>>25)
#define   VecGet_Li_(x)   ((( int)((x)<<25))>>25)

#define   VecGet_Lu       (((uint)((Op)<<25))>>25)
#define   VecGet_Lu_(x)   (((uint)((x)<<25))>>25)


#define   VecBuild_r5i       ((( int)((Op)<<28))>>28)
#define   VecBuild_r5i_(x)   ((( int)((x)<<28))>>28)

#define   VecBuild_r5u       (((uint)((Op)<<28))>>28)
#define   VecBuild_r5u_(x)   (((uint)((x)<<28))>>28)


#define   VecSwizzle_Fieldsi       ((( int)((Op)<<18))>>20)
#define   VecSwizzle_Fieldsi_(x)   ((( int)((x)<<18))>>20)

#define   VecSwizzle_Fieldsu       (((uint)((Op)<<18))>>20)
#define   VecSwizzle_Fieldsu_(x)   (((uint)((x)<<18))>>20)

#define   VecSwizzle_Li       ((( int)((Op)<<30))>>30)
#define   VecSwizzle_Li_(x)   ((( int)((x)<<30))>>30)

#define   VecSwizzle_Lu       (((uint)((Op)<<30))>>30)
#define   VecSwizzle_Lu_(x)   (((uint)((x)<<30))>>30)


#define   VecConst_K1i       ((( int)((Op)<<13))>>13)
#define   VecConst_K1i_(x)   ((( int)((x)<<13))>>13)

#define   VecConst_K1u       (((uint)((Op)<<13))>>13)
#define   VecConst_K1u_(x)   (((uint)((x)<<13))>>13)

