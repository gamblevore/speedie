
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


#define   Func_SaveRegsi       ((( int)((Op)<<8))>>27)
#define   Func_SaveRegsi_(x)   ((( int)((x)<<8))>>27)

#define   Func_SaveRegsu       (((uint)((Op)<<8))>>27)
#define   Func_SaveRegsu_(x)   (((uint)((x)<<8))>>27)

#define   Func_JUMPi       ((( int)((Op)<<13))>>13)
#define   Func_JUMPi_(x)   ((( int)((x)<<13))>>13)

#define   Func_JUMPu       (((uint)((Op)<<13))>>13)
#define   Func_JUMPu_(x)   (((uint)((x)<<13))>>13)


#define   Tail_JUMPi       ((( int)((Op)<<8))>>8)
#define   Tail_JUMPi_(x)   ((( int)((x)<<8))>>8)

#define   Tail_JUMPu       (((uint)((Op)<<8))>>8)
#define   Tail_JUMPu_(x)   (((uint)((x)<<8))>>8)


#define   Alloc_Aligni       ((( int)((Op)<<13))>>29)
#define   Alloc_Aligni_(x)   ((( int)((x)<<13))>>29)

#define   Alloc_Alignu       (((uint)((Op)<<13))>>29)
#define   Alloc_Alignu_(x)   (((uint)((x)<<13))>>29)

#define   Alloc_Amounti       ((( int)((Op)<<16))>>16)
#define   Alloc_Amounti_(x)   ((( int)((x)<<16))>>16)

#define   Alloc_Amountu       (((uint)((Op)<<16))>>16)
#define   Alloc_Amountu_(x)   (((uint)((x)<<16))>>16)


#define   Jump_JUMPi       ((( int)((Op)<<8))>>8)
#define   Jump_JUMPi_(x)   ((( int)((x)<<8))>>8)

#define   Jump_JUMPu       (((uint)((Op)<<8))>>8)
#define   Jump_JUMPu_(x)   (((uint)((x)<<8))>>8)


#define   Cmp_Cmpi       ((( int)((Op)<<23))>>29)
#define   Cmp_Cmpi_(x)   ((( int)((x)<<23))>>29)

#define   Cmp_Cmpu       (((uint)((Op)<<23))>>29)
#define   Cmp_Cmpu_(x)   (((uint)((x)<<23))>>29)

#define   Cmp_Li       ((( int)((Op)<<26))>>26)
#define   Cmp_Li_(x)   ((( int)((x)<<26))>>26)

#define   Cmp_Lu       (((uint)((Op)<<26))>>26)
#define   Cmp_Lu_(x)   (((uint)((x)<<26))>>26)


#define   MinMax_Signi       ((( int)((Op)<<23))>>31)
#define   MinMax_Signi_(x)   ((( int)((x)<<23))>>31)

#define   MinMax_Signu       (((uint)((Op)<<23))>>31)
#define   MinMax_Signu_(x)   (((uint)((x)<<23))>>31)

#define   MinMax_Li       ((( int)((Op)<<24))>>24)
#define   MinMax_Li_(x)   ((( int)((x)<<24))>>24)

#define   MinMax_Lu       (((uint)((Op)<<24))>>24)
#define   MinMax_Lu_(x)   (((uint)((x)<<24))>>24)


#define   Const_Roti       ((( int)((Op)<<13))>>26)
#define   Const_Roti_(x)   ((( int)((x)<<13))>>26)

#define   Const_Rotu       (((uint)((Op)<<13))>>26)
#define   Const_Rotu_(x)   (((uint)((x)<<13))>>26)

#define   Const_Invi       ((( int)((Op)<<19))>>31)
#define   Const_Invi_(x)   ((( int)((x)<<19))>>31)

#define   Const_Invu       (((uint)((Op)<<19))>>31)
#define   Const_Invu_(x)   (((uint)((x)<<19))>>31)

#define   Const_Valuei       ((( int)((Op)<<20))>>20)
#define   Const_Valuei_(x)   ((( int)((x)<<20))>>20)

#define   Const_Valueu       (((uint)((Op)<<20))>>20)
#define   Const_Valueu_(x)   (((uint)((x)<<20))>>20)


#define   JCmpEq_Jmpi       ((( int)((Op)<<18))>>18)
#define   JCmpEq_Jmpi_(x)   ((( int)((x)<<18))>>18)

#define   JCmpEq_Jmpu       (((uint)((Op)<<18))>>18)
#define   JCmpEq_Jmpu_(x)   (((uint)((x)<<18))>>18)


#define   JCmp_Cmpi       ((( int)((Op)<<18))>>29)
#define   JCmp_Cmpi_(x)   ((( int)((x)<<18))>>29)

#define   JCmp_Cmpu       (((uint)((Op)<<18))>>29)
#define   JCmp_Cmpu_(x)   (((uint)((x)<<18))>>29)

#define   JCmp_Jmpi       ((( int)((Op)<<21))>>21)
#define   JCmp_Jmpi_(x)   ((( int)((x)<<21))>>21)

#define   JCmp_Jmpu       (((uint)((Op)<<21))>>21)
#define   JCmp_Jmpu_(x)   (((uint)((x)<<21))>>21)


#define   BraBytes_Bytesi       ((( int)((Op)<<13))>>30)
#define   BraBytes_Bytesi_(x)   ((( int)((x)<<13))>>30)

#define   BraBytes_Bytesu       (((uint)((Op)<<13))>>30)
#define   BraBytes_Bytesu_(x)   (((uint)((x)<<13))>>30)

#define   BraBytes_Jmpi       ((( int)((Op)<<15))>>15)
#define   BraBytes_Jmpi_(x)   ((( int)((x)<<15))>>15)

#define   BraBytes_Jmpu       (((uint)((Op)<<15))>>15)
#define   BraBytes_Jmpu_(x)   (((uint)((x)<<15))>>15)


#define   Bra_Jmpi       ((( int)((Op)<<13))>>13)
#define   Bra_Jmpi_(x)   ((( int)((x)<<13))>>13)

#define   Bra_Jmpu       (((uint)((Op)<<13))>>13)
#define   Bra_Jmpu_(x)   (((uint)((x)<<13))>>13)


#define   Loop_Jmpi       ((( int)((Op)<<18))>>18)
#define   Loop_Jmpi_(x)   ((( int)((x)<<18))>>18)

#define   Loop_Jmpu       (((uint)((Op)<<18))>>18)
#define   Loop_Jmpu_(x)   (((uint)((x)<<18))>>18)


#define   Table_Modei       ((( int)((Op)<<13))>>30)
#define   Table_Modei_(x)   ((( int)((x)<<13))>>30)

#define   Table_Modeu       (((uint)((Op)<<13))>>30)
#define   Table_Modeu_(x)   (((uint)((x)<<13))>>30)

#define   Table_Addi       ((( int)((Op)<<15))>>15)
#define   Table_Addi_(x)   ((( int)((x)<<15))>>15)

#define   Table_Addu       (((uint)((Op)<<15))>>15)
#define   Table_Addu_(x)   (((uint)((x)<<15))>>15)


#define   Read_Li       ((( int)((Op)<<23))>>25)
#define   Read_Li_(x)   ((( int)((x)<<23))>>25)

#define   Read_Lu       (((uint)((Op)<<23))>>25)
#define   Read_Lu_(x)   (((uint)((x)<<23))>>25)

#define   Read_movei       ((( int)((Op)<<30))>>30)
#define   Read_movei_(x)   ((( int)((x)<<30))>>30)

#define   Read_moveu       (((uint)((Op)<<30))>>30)
#define   Read_moveu_(x)   (((uint)((x)<<30))>>30)


#define   Write_Li       ((( int)((Op)<<23))>>25)
#define   Write_Li_(x)   ((( int)((x)<<23))>>25)

#define   Write_Lu       (((uint)((Op)<<23))>>25)
#define   Write_Lu_(x)   (((uint)((x)<<23))>>25)

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


#define   BClear_Shift1i       ((( int)((Op)<<18))>>26)
#define   BClear_Shift1i_(x)   ((( int)((x)<<18))>>26)

#define   BClear_Shift1u       (((uint)((Op)<<18))>>26)
#define   BClear_Shift1u_(x)   (((uint)((x)<<18))>>26)

#define   BClear_Shift2i       ((( int)((Op)<<24))>>26)
#define   BClear_Shift2i_(x)   ((( int)((x)<<24))>>26)

#define   BClear_Shift2u       (((uint)((Op)<<24))>>26)
#define   BClear_Shift2u_(x)   (((uint)((x)<<24))>>26)

#define   BClear_Signi       ((( int)((Op)<<30))>>30)
#define   BClear_Signi_(x)   ((( int)((x)<<30))>>30)

#define   BClear_Signu       (((uint)((Op)<<30))>>30)
#define   BClear_Signu_(x)   (((uint)((x)<<30))>>30)


#define   Convert_Modei       ((( int)((Op)<<18))>>28)
#define   Convert_Modei_(x)   ((( int)((x)<<18))>>28)

#define   Convert_Modeu       (((uint)((Op)<<18))>>28)
#define   Convert_Modeu_(x)   (((uint)((x)<<18))>>28)

#define   Convert_Li       ((( int)((Op)<<22))>>22)
#define   Convert_Li_(x)   ((( int)((x)<<22))>>22)

#define   Convert_Lu       (((uint)((Op)<<22))>>22)
#define   Convert_Lu_(x)   (((uint)((x)<<22))>>22)


#define   RET_Counti       ((( int)((Op)<<18))>>29)
#define   RET_Counti_(x)   ((( int)((x)<<18))>>29)

#define   RET_Countu       (((uint)((Op)<<18))>>29)
#define   RET_Countu_(x)   (((uint)((x)<<18))>>29)

#define   RET_Existsi       ((( int)((Op)<<21))>>31)
#define   RET_Existsi_(x)   ((( int)((x)<<21))>>31)

#define   RET_Existsu       (((uint)((Op)<<21))>>31)
#define   RET_Existsu_(x)   (((uint)((x)<<21))>>31)

#define   RET_Li       ((( int)((Op)<<22))>>22)
#define   RET_Li_(x)   ((( int)((x)<<22))>>22)

#define   RET_Lu       (((uint)((Op)<<22))>>22)
#define   RET_Lu_(x)   (((uint)((x)<<22))>>22)


#define   Div_Kindi       ((( int)((Op)<<28))>>30)
#define   Div_Kindi_(x)   ((( int)((x)<<28))>>30)

#define   Div_Kindu       (((uint)((Op)<<28))>>30)
#define   Div_Kindu_(x)   (((uint)((x)<<28))>>30)

#define   Div_Li       ((( int)((Op)<<30))>>30)
#define   Div_Li_(x)   ((( int)((x)<<30))>>30)

#define   Div_Lu       (((uint)((Op)<<30))>>30)
#define   Div_Lu_(x)   (((uint)((x)<<30))>>30)


#define   Trap_Continuei       ((( int)((Op)<<13))>>31)
#define   Trap_Continuei_(x)   ((( int)((x)<<13))>>31)

#define   Trap_Continueu       (((uint)((Op)<<13))>>31)
#define   Trap_Continueu_(x)   (((uint)((x)<<13))>>31)

#define   Trap_Modei       ((( int)((Op)<<14))>>30)
#define   Trap_Modei_(x)   ((( int)((x)<<14))>>30)

#define   Trap_Modeu       (((uint)((Op)<<14))>>30)
#define   Trap_Modeu_(x)   (((uint)((x)<<14))>>30)

#define   Trap_Li       ((( int)((Op)<<16))>>16)
#define   Trap_Li_(x)   ((( int)((x)<<16))>>16)

#define   Trap_Lu       (((uint)((Op)<<16))>>16)
#define   Trap_Lu_(x)   (((uint)((x)<<16))>>16)


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


#define   AddK_Ki       ((( int)((Op)<<18))>>18)
#define   AddK_Ki_(x)   ((( int)((x)<<18))>>18)

#define   AddK_Ku       (((uint)((Op)<<18))>>18)
#define   AddK_Ku_(x)   (((uint)((x)<<18))>>18)


#define   DivK_Shi       ((( int)((Op)<<18))>>26)
#define   DivK_Shi_(x)   ((( int)((x)<<18))>>26)

#define   DivK_Shu       (((uint)((Op)<<18))>>26)
#define   DivK_Shu_(x)   (((uint)((x)<<18))>>26)

#define   DivK_Addi       ((( int)((Op)<<24))>>26)
#define   DivK_Addi_(x)   ((( int)((x)<<24))>>26)

#define   DivK_Addu       (((uint)((Op)<<24))>>26)
#define   DivK_Addu_(x)   (((uint)((x)<<24))>>26)

#define   DivK_Li       ((( int)((Op)<<30))>>30)
#define   DivK_Li_(x)   ((( int)((x)<<30))>>30)

#define   DivK_Lu       (((uint)((Op)<<30))>>30)
#define   DivK_Lu_(x)   (((uint)((x)<<30))>>30)


#define   Shift_Shi       ((( int)((Op)<<23))>>26)
#define   Shift_Shi_(x)   ((( int)((x)<<23))>>26)

#define   Shift_Shu       (((uint)((Op)<<23))>>26)
#define   Shift_Shu_(x)   (((uint)((x)<<23))>>26)

#define   Shift_Li       ((( int)((Op)<<29))>>29)
#define   Shift_Li_(x)   ((( int)((x)<<29))>>29)

#define   Shift_Lu       (((uint)((Op)<<29))>>29)
#define   Shift_Lu_(x)   (((uint)((x)<<29))>>29)


#define   Swap_Li       ((( int)((Op)<<28))>>28)
#define   Swap_Li_(x)   ((( int)((x)<<28))>>28)

#define   Swap_Lu       (((uint)((Op)<<28))>>28)
#define   Swap_Lu_(x)   (((uint)((x)<<28))>>28)


#define   RefSet_Li       ((( int)((Op)<<28))>>28)
#define   RefSet_Li_(x)   ((( int)((x)<<28))>>28)

#define   RefSet_Lu       (((uint)((Op)<<28))>>28)
#define   RefSet_Lu_(x)   (((uint)((x)<<28))>>28)

