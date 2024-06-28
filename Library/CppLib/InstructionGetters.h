
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


#define   Func_SaveRegsi       ((( int)((Op.Raw)<<8))>>27)
#define   Func_SaveRegsi_(x)   ((( int)((x)<<8))>>27)

#define   Func_SaveRegsu       (((uint)((Op.Raw)<<8))>>27)
#define   Func_SaveRegsu_(x)   (((uint)((x)<<8))>>27)

#define   Func_JUMPi       ((( int)((Op.Raw)<<13))>>13)
#define   Func_JUMPi_(x)   ((( int)((x)<<13))>>13)

#define   Func_JUMPu       (((uint)((Op.Raw)<<13))>>13)
#define   Func_JUMPu_(x)   (((uint)((x)<<13))>>13)


#define   Tail_JUMPi       ((( int)((Op.Raw)<<8))>>8)
#define   Tail_JUMPi_(x)   ((( int)((x)<<8))>>8)

#define   Tail_JUMPu       (((uint)((Op.Raw)<<8))>>8)
#define   Tail_JUMPu_(x)   (((uint)((x)<<8))>>8)


#define   Cmp_Cmpi       ((( int)((Op.Raw)<<18))>>28)
#define   Cmp_Cmpi_(x)   ((( int)((x)<<18))>>28)

#define   Cmp_Cmpu       (((uint)((Op.Raw)<<18))>>28)
#define   Cmp_Cmpu_(x)   (((uint)((x)<<18))>>28)

#define   Cmp_Li       ((( int)((Op.Raw)<<22))>>22)
#define   Cmp_Li_(x)   ((( int)((x)<<22))>>22)

#define   Cmp_Lu       (((uint)((Op.Raw)<<22))>>22)
#define   Cmp_Lu_(x)   (((uint)((x)<<22))>>22)


#define   CmpD_Li       ((( int)((Op.Raw)<<23))>>23)
#define   CmpD_Li_(x)   ((( int)((x)<<23))>>23)

#define   CmpD_Lu       (((uint)((Op.Raw)<<23))>>23)
#define   CmpD_Lu_(x)   (((uint)((x)<<23))>>23)


#define   CmpEq_Jmpi       ((( int)((Op.Raw)<<18))>>18)
#define   CmpEq_Jmpi_(x)   ((( int)((x)<<18))>>18)

#define   CmpEq_Jmpu       (((uint)((Op.Raw)<<18))>>18)
#define   CmpEq_Jmpu_(x)   (((uint)((x)<<18))>>18)


#define   Const_Roti       ((( int)((Op.Raw)<<13))>>26)
#define   Const_Roti_(x)   ((( int)((x)<<13))>>26)

#define   Const_Rotu       (((uint)((Op.Raw)<<13))>>26)
#define   Const_Rotu_(x)   (((uint)((x)<<13))>>26)

#define   Const_Invi       ((( int)((Op.Raw)<<19))>>31)
#define   Const_Invi_(x)   ((( int)((x)<<19))>>31)

#define   Const_Invu       (((uint)((Op.Raw)<<19))>>31)
#define   Const_Invu_(x)   (((uint)((x)<<19))>>31)

#define   Const_Valuei       ((( int)((Op.Raw)<<20))>>20)
#define   Const_Valuei_(x)   ((( int)((x)<<20))>>20)

#define   Const_Valueu       (((uint)((Op.Raw)<<20))>>20)
#define   Const_Valueu_(x)   (((uint)((x)<<20))>>20)


#define   Bra_c1i       ((( int)((Op.Raw)<<13))>>30)
#define   Bra_c1i_(x)   ((( int)((x)<<13))>>30)

#define   Bra_c1u       (((uint)((Op.Raw)<<13))>>30)
#define   Bra_c1u_(x)   (((uint)((x)<<13))>>30)

#define   Bra_jmpi       ((( int)((Op.Raw)<<15))>>15)
#define   Bra_jmpi_(x)   ((( int)((x)<<15))>>15)

#define   Bra_jmpu       (((uint)((Op.Raw)<<15))>>15)
#define   Bra_jmpu_(x)   (((uint)((x)<<15))>>15)


#define   Mem_Li       ((( int)((Op.Raw)<<23))>>25)
#define   Mem_Li_(x)   ((( int)((x)<<23))>>25)

#define   Mem_Lu       (((uint)((Op.Raw)<<23))>>25)
#define   Mem_Lu_(x)   (((uint)((x)<<23))>>25)

#define   Mem_movei       ((( int)((Op.Raw)<<30))>>30)
#define   Mem_movei_(x)   ((( int)((x)<<30))>>30)

#define   Mem_moveu       (((uint)((Op.Raw)<<30))>>30)
#define   Mem_moveu_(x)   (((uint)((x)<<30))>>30)


#define   CNTC_offseti       ((( int)((Op.Raw)<<18))>>27)
#define   CNTC_offseti_(x)   ((( int)((x)<<18))>>27)

#define   CNTC_offsetu       (((uint)((Op.Raw)<<18))>>27)
#define   CNTC_offsetu_(x)   (((uint)((x)<<18))>>27)

#define   CNTC_cnsti       ((( int)((Op.Raw)<<23))>>25)
#define   CNTC_cnsti_(x)   ((( int)((x)<<23))>>25)

#define   CNTC_cnstu       (((uint)((Op.Raw)<<23))>>25)
#define   CNTC_cnstu_(x)   (((uint)((x)<<23))>>25)

#define   CNTC_sizei       ((( int)((Op.Raw)<<30))>>30)
#define   CNTC_sizei_(x)   ((( int)((x)<<30))>>30)

#define   CNTC_sizeu       (((uint)((Op.Raw)<<30))>>30)
#define   CNTC_sizeu_(x)   (((uint)((x)<<30))>>30)


#define   BFLD_upi       ((( int)((Op.Raw)<<18))>>26)
#define   BFLD_upi_(x)   ((( int)((x)<<18))>>26)

#define   BFLD_upu       (((uint)((Op.Raw)<<18))>>26)
#define   BFLD_upu_(x)   (((uint)((x)<<18))>>26)

#define   BFLD_downi       ((( int)((Op.Raw)<<24))>>26)
#define   BFLD_downi_(x)   ((( int)((x)<<24))>>26)

#define   BFLD_downu       (((uint)((Op.Raw)<<24))>>26)
#define   BFLD_downu_(x)   (((uint)((x)<<24))>>26)

#define   BFLD_signi       ((( int)((Op.Raw)<<30))>>31)
#define   BFLD_signi_(x)   ((( int)((x)<<30))>>31)

#define   BFLD_signu       (((uint)((Op.Raw)<<30))>>31)
#define   BFLD_signu_(x)   (((uint)((x)<<30))>>31)

#define   BFLD_Li       ((( int)((Op.Raw)<<31))>>31)
#define   BFLD_Li_(x)   ((( int)((x)<<31))>>31)

#define   BFLD_Lu       (((uint)((Op.Raw)<<31))>>31)
#define   BFLD_Lu_(x)   (((uint)((x)<<31))>>31)


#define   BCmp_Shifti       ((( int)((Op.Raw)<<23))>>26)
#define   BCmp_Shifti_(x)   ((( int)((x)<<23))>>26)

#define   BCmp_Shiftu       (((uint)((Op.Raw)<<23))>>26)
#define   BCmp_Shiftu_(x)   (((uint)((x)<<23))>>26)

#define   BCmp_Invi       ((( int)((Op.Raw)<<29))>>29)
#define   BCmp_Invi_(x)   ((( int)((x)<<29))>>29)

#define   BCmp_Invu       (((uint)((Op.Raw)<<29))>>29)
#define   BCmp_Invu_(x)   (((uint)((x)<<29))>>29)


#define   BClear_Shift1i       ((( int)((Op.Raw)<<18))>>26)
#define   BClear_Shift1i_(x)   ((( int)((x)<<18))>>26)

#define   BClear_Shift1u       (((uint)((Op.Raw)<<18))>>26)
#define   BClear_Shift1u_(x)   (((uint)((x)<<18))>>26)

#define   BClear_Shift2i       ((( int)((Op.Raw)<<24))>>26)
#define   BClear_Shift2i_(x)   ((( int)((x)<<24))>>26)

#define   BClear_Shift2u       (((uint)((Op.Raw)<<24))>>26)
#define   BClear_Shift2u_(x)   (((uint)((x)<<24))>>26)

#define   BClear_Signi       ((( int)((Op.Raw)<<30))>>30)
#define   BClear_Signi_(x)   ((( int)((x)<<30))>>30)

#define   BClear_Signu       (((uint)((Op.Raw)<<30))>>30)
#define   BClear_Signu_(x)   (((uint)((x)<<30))>>30)


#define   RET_Counti       ((( int)((Op.Raw)<<18))>>29)
#define   RET_Counti_(x)   ((( int)((x)<<18))>>29)

#define   RET_Countu       (((uint)((Op.Raw)<<18))>>29)
#define   RET_Countu_(x)   (((uint)((x)<<18))>>29)

#define   RET_Existsi       ((( int)((Op.Raw)<<21))>>31)
#define   RET_Existsi_(x)   ((( int)((x)<<21))>>31)

#define   RET_Existsu       (((uint)((Op.Raw)<<21))>>31)
#define   RET_Existsu_(x)   (((uint)((x)<<21))>>31)

#define   RET_Li       ((( int)((Op.Raw)<<22))>>22)
#define   RET_Li_(x)   ((( int)((x)<<22))>>22)

#define   RET_Lu       (((uint)((Op.Raw)<<22))>>22)
#define   RET_Lu_(x)   (((uint)((x)<<22))>>22)


#define   Div_Kindi       ((( int)((Op.Raw)<<28))>>30)
#define   Div_Kindi_(x)   ((( int)((x)<<28))>>30)

#define   Div_Kindu       (((uint)((Op.Raw)<<28))>>30)
#define   Div_Kindu_(x)   (((uint)((x)<<28))>>30)

#define   Div_Li       ((( int)((Op.Raw)<<30))>>30)
#define   Div_Li_(x)   ((( int)((x)<<30))>>30)

#define   Div_Lu       (((uint)((Op.Raw)<<30))>>30)
#define   Div_Lu_(x)   (((uint)((x)<<30))>>30)


#define   Trap_Continuei       ((( int)((Op.Raw)<<13))>>31)
#define   Trap_Continuei_(x)   ((( int)((x)<<13))>>31)

#define   Trap_Continueu       (((uint)((Op.Raw)<<13))>>31)
#define   Trap_Continueu_(x)   (((uint)((x)<<13))>>31)

#define   Trap_Modei       ((( int)((Op.Raw)<<14))>>30)
#define   Trap_Modei_(x)   ((( int)((x)<<14))>>30)

#define   Trap_Modeu       (((uint)((Op.Raw)<<14))>>30)
#define   Trap_Modeu_(x)   (((uint)((x)<<14))>>30)

#define   Trap_Li       ((( int)((Op.Raw)<<16))>>16)
#define   Trap_Li_(x)   ((( int)((x)<<16))>>16)

#define   Trap_Lu       (((uint)((Op.Raw)<<16))>>16)
#define   Trap_Lu_(x)   (((uint)((x)<<16))>>16)


#define   Float_Di       ((( int)((Op.Raw)<<28))>>31)
#define   Float_Di_(x)   ((( int)((x)<<28))>>31)

#define   Float_Du       (((uint)((Op.Raw)<<28))>>31)
#define   Float_Du_(x)   (((uint)((x)<<28))>>31)

#define   Float_Li       ((( int)((Op.Raw)<<29))>>29)
#define   Float_Li_(x)   ((( int)((x)<<29))>>29)

#define   Float_Lu       (((uint)((Op.Raw)<<29))>>29)
#define   Float_Lu_(x)   (((uint)((x)<<29))>>29)


#define   FloatConst_Highi       ((( int)((Op.Raw)<<18))>>18)
#define   FloatConst_Highi_(x)   ((( int)((x)<<18))>>18)

#define   FloatConst_Highu       (((uint)((Op.Raw)<<18))>>18)
#define   FloatConst_Highu_(x)   (((uint)((x)<<18))>>18)


#define   FloatAddExp_Sh2i       ((( int)((Op.Raw)<<23))>>28)
#define   FloatAddExp_Sh2i_(x)   ((( int)((x)<<23))>>28)

#define   FloatAddExp_Sh2u       (((uint)((Op.Raw)<<23))>>28)
#define   FloatAddExp_Sh2u_(x)   (((uint)((x)<<23))>>28)

#define   FloatAddExp_Sh3i       ((( int)((Op.Raw)<<27))>>28)
#define   FloatAddExp_Sh3i_(x)   ((( int)((x)<<27))>>28)

#define   FloatAddExp_Sh3u       (((uint)((Op.Raw)<<27))>>28)
#define   FloatAddExp_Sh3u_(x)   (((uint)((x)<<27))>>28)

#define   FloatAddExp_Di       ((( int)((Op.Raw)<<31))>>31)
#define   FloatAddExp_Di_(x)   ((( int)((x)<<31))>>31)

#define   FloatAddExp_Du       (((uint)((Op.Raw)<<31))>>31)
#define   FloatAddExp_Du_(x)   (((uint)((x)<<31))>>31)


#define   ConstStretchy_Condi       ((( int)((Op.Raw)<<13))>>31)
#define   ConstStretchy_Condi_(x)   ((( int)((x)<<13))>>31)

#define   ConstStretchy_Condu       (((uint)((Op.Raw)<<13))>>31)
#define   ConstStretchy_Condu_(x)   (((uint)((x)<<13))>>31)

#define   ConstStretchy_Invi       ((( int)((Op.Raw)<<14))>>31)
#define   ConstStretchy_Invi_(x)   ((( int)((x)<<14))>>31)

#define   ConstStretchy_Invu       (((uint)((Op.Raw)<<14))>>31)
#define   ConstStretchy_Invu_(x)   (((uint)((x)<<14))>>31)

#define   ConstStretchy_Valuei       ((( int)((Op.Raw)<<15))>>16)
#define   ConstStretchy_Valuei_(x)   ((( int)((x)<<15))>>16)

#define   ConstStretchy_Valueu       (((uint)((Op.Raw)<<15))>>16)
#define   ConstStretchy_Valueu_(x)   (((uint)((x)<<15))>>16)

#define   ConstStretchy_Prm1i       ((( int)((Op.Raw)<<31))>>31)
#define   ConstStretchy_Prm1i_(x)   ((( int)((x)<<31))>>31)

#define   ConstStretchy_Prm1u       (((uint)((Op.Raw)<<31))>>31)
#define   ConstStretchy_Prm1u_(x)   (((uint)((x)<<31))>>31)

