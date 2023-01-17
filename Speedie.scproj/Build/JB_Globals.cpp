
// Globals put into a separate file to make things faster.
#include "JB_Umbrella.hpp"
#include "JB.h"
#pragma GCC visibility push(hidden)

int SC____junktest_5___x[3];
JB_String* JB__App__CLN;
Message* JB__App__Conf;
JB_String* JB__App__Path;
JB_String* JB__App_codesign_native;
Array* JB__App_OldArgs;
Message* JB__App_Prefs;
bool JB__App_Unregistered;
JB_File* SC__Comp__BuildFolder;
JB_String* SC__Comp__Projects;
JB_String* SC__Comp__SpeedieProj;
Dictionary* SC__Comp_AdjDicts;
Array* SC__Comp_API_Funcs;
Array* SC__Comp_API_List;
Message* SC__Comp_API_Place;
JB_File* SC__Comp_BaseProjectPath;
Array* SC__Comp_ClassList;
SCFunction* SC__Comp_ClassListInitFunc;
Message* SC__Comp_ConfMsg;
int SC__Comp_CurrStage;
Message* SC__Comp_DebugInsert;
SCModule* SC__Comp_DisamClasses;
SCModule* SC__Comp_DisamModules;
Dictionary* SC__Comp_ExportNames;
Message* SC__Comp_Extend_list;
Array* SC__Comp_Extend_module_list;
Dictionary* SC__Comp_Files;
Array* SC__Comp_FuncList;
bool SC__Comp_HasMainFunc;
Array* SC__Comp_ImportedList;
Dictionary* SC__Comp_ImportedNames;
Dictionary* SC__Comp_InsecureWords;
SCFile* SC__Comp_InternalFile;
SCBase* SC__Comp_Interpreter;
Date SC__Comp_LastTime;
JB_String* SC__Comp_LastTimeName;
Array* SC__Comp_ModuleList;
JB_String* SC__Comp_OriginalInputPath;
SCFunction* SC__Comp_PrivateProperty;
SCModule* SC__Comp_program;
JB_String* SC__Comp_ProjectName;
Array* SC__Comp_ProtoTypes;
SCFunction* SC__Comp_RefDecr;
SCFunction* SC__Comp_RefFreeIfDead;
SCFunction* SC__Comp_RefIncr;
SCFunction* SC__Comp_RefSafeDecr;
SCFunction* SC__Comp_RefSetRef;
JB_String* SC__Comp_ReportedName;
int SC__Comp_stClasses;
int SC__Comp_stFuncs;
int SC__Comp_stFunctionProgress;
int SC__Comp_stParseTime;
int SC__Comp_stParseTimeTotal;
int SC__Comp_stReachedClass;
int SC__Comp_stReachedFunc;
int SC__Comp_stTotalFileCount;
int SC__Comp_stTotalSourceSize;
Array* SC__Comp_SyxArray;
JB_File* SC__Comp_TempFolder;
SCFunction* SC__Comp_TernaryFunc;
SCFunction* SC__Comp_TernaryFunc2;
FastString* SC__Comp_TimerOutput;
SCBase* SC__Comp_VisibleFuncs;
bool JB__ErrorColors_Enabled;
Array* SC__ExecTable_Funcs;
Array* SC__ExecTable_Globs;
Array* SC__Ext_Cleanup;
Array* SC__Ext_FoundObjects;
SCFunction* SC__FastStringOpts__ByteFunc;
int SC__FastStringOpts_FSRemoved;
int SC__FastStringOpts_StrRemoved;
Dictionary* SC__FB_AppOptions;
Array* SC__Flatten_PackFuncs;
ASMFuncState SC__Flatten_StdState;
Macro* SC__AC_all_tmp_src;
SCFunction* SC__AC_AnonFn;
SCBase* SC__AC_AnonParent;
JB_String* SC__AC_AnonText;
bool SC__AC_CompileUpToDate;
Macro* SC__AC_func_tmp_src;
int SC__AC_max_total;
Process* SC__AC_Perry;
byte SC__AC_ShouldEnter;
int SC__AC_total;
u16 JB__API_NilHappened;
CharSet* JB__Constants_CSAfterStatement;
CharSet* JB__Constants_CSLettersOnly;
CharSet* JB__Constants_CSLine;
CharSet* JB__Constants_CSLineBlack;
CharSet* JB__Constants_CSNum;
CharSet* JB__Constants_CSWordMiddle;
CharSet* JB__Constants_CSWordStart;
CharSet* JB__Constants_CSWrapSplit;
Dictionary* JB__Constants_EscapeChr;
Dictionary* JB__Constants_EscapeStr;
Dictionary* JB__Constants_JS_EscapeStr;
Dictionary* JB__Constants_JS_UnEscapeStr;
JB_String* JB__Constants_Name;
Dictionary* JB__Constants_UnEscapeStr;
Dictionary* JB__Constants_XML_EscapeStr;
Dictionary* JB__Constants_XML_UnEscapeStr;
Message* SC__Linkage_Dict;
Message* SC__Linkage_Flags;
Macro* SC__Macros_ASM_Datatype;
Macro* SC__Macros_Copier;
Macro* SC__Macros_Copier2;
Macro* SC__Macros_FS;
Macro* SC__Macros_InitExpand;
Macro* SC__Macros_Setter;
Macro* SC__Macros_Worked2;
bool SC__Options_ArgStats;
Dictionary* SC__Options_BannedClasses;
bool SC__Options_CheckMaxVars;
bool SC__Options_Compile;
bool SC__Options_Cpp;
bool SC__Options_ExternalCompile;
bool SC__Options_Final;
bool SC__Options_Flow;
bool SC__Options_ForceRecompile;
bool SC__Options_HideMultipleErrors;
bool SC__Options_IgnoreCantSaveErrors;
bool SC__Options_Is32Bit;
bool SC__Options_IsDirectTest;
bool SC__Options_KeepAllErrors;
bool SC__Options_ListAllLib;
bool SC__Options_MakeLib;
int SC__Options_OperationCount;
int SC__Options_Optimise;
JB_String* SC__Options_output_path;
byte SC__Options_Perry;
bool SC__Options_PrintCompileString;
bool SC__Options_PrintFiles;
bool SC__Options_PrintLibraries;
bool SC__Options_PrintStages;
int SC__Options_Products;
bool SC__Options_ProjectIsLibrary;
bool SC__Options_ProjectIsMiniLib;
bool SC__Options_Scripting;
int SC__Options_SelfReplacement;
bool SC__Options_Silent;
bool SC__Options_SingleCppOutput;
JB_String* SC__Options_SingleFileInput;
bool SC__Options_TargetDebug;
bool SC__Options_UseFuncCallCount;
JB_String* SC__Options_Variant;
bool SC__Options_Warnings;
int JB__Tk_BaseExtra;
JB_String* JB__Tk_Data;
bool JB__Tk_DotInsertAllow;
Message* JB__Tk_EndOfLineMarker;
Dictionary* JB__Tk_ErrorNames;
JB_String* JB__Tk_ErrorTabsAfterSpaces;
int JB__Tk_InsertedFlags;
int JB__Tk_StopBars;
int JB__Tk_UsingExtra;
int JB__Tk_UsingPos;
JB_File* JB__Platform_Logger;
Dictionary* SC__Errors_IgnoredBranches;
Dictionary* SC__SCGame3D_Types;
int SC__SC_UniqueNum;
SCFunction* SC__Refs_ThisFunc;
Message* SC__SCStrings_RenderFinish;
Message* SC__SCStrings_RenderInsides;
Message* SC__SCStrings_RenderNewParams;
Dictionary* SC__Targets_Items;
Dictionary* SC__TextAssembler_LabelsToDo;
Array* SC__VM_Builder_Builder;
Message* SC__VM_Builder_dt_prm;
FastString* SC__VM_Builder_form_h;
byte SC__VM_Builder_HighPos;
Message* SC__VM_Builder_ModuleArg;
Array* SC__VM_Builder_Msgs;
Message* SC__VM_Builder_NameList;
byte SC__VM_Builder_NormalPos;
JB_String* SC__VM_Builder_parent;
JB_File* SC__VM_Builder_vm_file;
JB_String* JB__zalgo_down;
JB_String* JB__zalgo_mid;
Random JB__zalgo_R;
JB_String* JB__zalgo_up;
JB_String* JB___AppConfString;
SyntaxObj* JB__FuncArray_[64];
JB_String* JB__JbinHeader;
bool _once1;
bool _once2;
Dictionary* JB__SyxDict_;
CharSet* JB_C_Letters;
Dictionary* JB_ClassLinkageTable;
Dictionary* JB_ClsCollectTable;
JB_String* JB_codesign_native;
Dictionary* JB_CppRefTable;
CharSet* JB_CSHex;
CharSet* JB_CSNum;
ExprResolver JB_ExprFuncs[64];
SCDecl* JB_FalseBool;
JB_String* JB_file_read_test;
fn_asm JB_fn_asm_table[64];
Dictionary* JB_FuncLinkageTable;
JB_String* JB_kNameConf;
int JB_naawgr[1];
Dictionary* JB_RootCollectTable;
JB_ErrorReceiver* JB_StdErr;
__lib__ Syntax JB_SyxAcc;
__lib__ Syntax JB_SyxAdj;
__lib__ Syntax JB_SyxARel;
__lib__ Syntax JB_SyxArg;
__lib__ Syntax JB_SyxArr;
__lib__ Syntax JB_SyxAsk;
__lib__ Syntax JB_SyxBack;
__lib__ Syntax JB_SyxBadj;
__lib__ Syntax JB_SyxBin;
__lib__ Syntax JB_Syxbinn;
__lib__ Syntax JB_SyxBra;
__lib__ Syntax JB_SyxBRel;
__lib__ Syntax JB_SyxChar;
__lib__ Syntax JB_SyxCnj;
__lib__ Syntax JB_SyxDecl;
__lib__ Syntax JB_SyxDot;
__lib__ Syntax JB_SyxEmb;
__lib__ Syntax JB_SyxERel;
__lib__ Syntax JB_SyxFile;
__lib__ Syntax JB_SyxFunc;
__lib__ Syntax JB_SyxItem;
__lib__ Syntax JB_SyxList;
__lib__ Syntax JB_SyxMsg;
__lib__ Syntax JB_SyxName;
__lib__ Syntax JB_SyxNil;
__lib__ Syntax JB_SyxNum;
__lib__ Syntax JB_SyxOat;
__lib__ Syntax JB_SyxOpp;
__lib__ Syntax JB_Syxpinn;
__lib__ Syntax JB_SyxPrm;
__lib__ Syntax JB_SyxQues;
__lib__ Syntax JB_SyxQuot;
__lib__ Syntax JB_SyxRel;
__lib__ Syntax JB_SyxSCnj;
__lib__ Syntax JB_SyxSCom;
__lib__ Syntax JB_SyxSDot;
__lib__ Syntax JB_SyxSheb;
__lib__ Syntax JB_SyxSStr;
__lib__ Syntax JB_SyxSThg;
__lib__ Syntax JB_SyxStr;
__lib__ Syntax JB_SyxThg;
__lib__ Syntax JB_SyxTmp;
__lib__ Syntax JB_SyxTodo;
__lib__ Syntax JB_SyxTRel;
__lib__ Syntax JB_SyxTril;
__lib__ Syntax JB_SyxType;
__lib__ Syntax JB_SyxUnit;
__lib__ Syntax JB_Syxurl;
__lib__ Syntax JB_SyxXAtt;
__lib__ Syntax JB_SyxXCDT;
__lib__ Syntax JB_SyxXCom;
__lib__ Syntax JB_SyxXML;
__lib__ Syntax JB_SyxXPI;
__lib__ Syntax JB_SyxXTxt;
__lib__ Syntax JB_SyxYoda;
SCDecl* JB_TrueBool;
SCClass* JB_TypeArray;
SCClass* JB_TypeBool;
SCClass* JB_TypeByte;
SCClass* JB_TypeCharSet;
SCClass* JB_TypeDate;
SCClass* JB_TypeDictionary;
SCClass* JB_Typef32;
SCClass* JB_Typef64;
SCClass* JB_TypeFastString;
SCClass* JB_Typefloat;
SCClass* JB_Typehfloat;
SCClass* JB_TypeInt;
SCClass* JB_TypeInt16;
SCClass* JB_TypeInt64;
SCClass* JB_TypeiVec2;
SCClass* JB_TypeiVec3;
SCClass* JB_TypeiVec4;
SCClass* JB_TypeJBClass;
SCDecl* JB_TypeNil;
SCClass* JB_TypeObject;
SCClass* JB_TypeSaveable;
SCClass* JB_TypeString;
SCClass* JB_TypeSyntax;
SCClass* JB_TypeuInt;
SCClass* JB_TypeuInt16;
SCClass* JB_TypeuInt64;
SCClass* JB_TypeVec2;
SCClass* JB_TypeVec3;
SCClass* JB_TypeVec4;
SCDecl* JB_TypeVoid;
SCClass* JB_TypeVoid_;
SCClass* JB_TypeVoidPtr;
SCClass* JB_TypeWrapper;
AsmReg SC_xxx;
Array* JB__ErrorSeverity_names;
int JB__Syx_CurrFuncID;
int JB__Syx_MaxFuncID;
Dictionary* JB__TC_Types_Dict;

ASM_Encoder2 SC__ASM_Encoders[128];
ASM_Encoder2 SC__ASM_Forms[32];
byte SC__ASM_NoisyASM;
ASM2 SC__flat_Dummy;
MWrap* SC__flat_JSMSpace;
CompressionStats JB__MzSt_All;

Dictionary* JB__LD_ClassList;
SaverClassInfo* JB__Saver_SaveableList;
Random JB__Rnd_Shared;
autoitem_Behaviour InitTableautoitem_() { // Behaviour 
	autoitem_Behaviour Result;
	Result.__destructor__ = (void*)SC_autoitem_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

autoitem_Behaviour autoitem_FuncTable_ = InitTableautoitem_();
JBClassPlace4(autoitem, JB_AsClass(JB_Object), autoitem_FuncTable_);

Array* SC__Cpp_Cpp_Includes;
Array* SC__Cpp_Cpp_Input;
JB_String* SC__Cpp_CppLicenceStr;
SCClass* SC__Cpp_CurrClass;
Array* SC__Cpp_H_Input;
Array* SC__Cpp_H_PostInput;
FastStringCpp* SC__Cpp_StringBlob;
int SC__Cpp_StringCount;
Dictionary* SC__Cpp_StringDict;
FastStringCpp* SC__Cpp_StringLengths;
bool SC__Cpp_WriteAPI;
bool SC__Cpp_WroteAny;
Cpp_Export_Behaviour InitTableCpp_Export_() { // Behaviour 
	Cpp_Export_Behaviour Result;
	Result.__destructor__ = (void*)SC_Cpp_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

Cpp_Export_Behaviour Cpp_Export_FuncTable_ = InitTableCpp_Export_();
JBClassPlace4(Cpp_Export, JB_AsClass(JB_Object), Cpp_Export_FuncTable_);

CppRefs_Behaviour InitTableCppRefs_() { // Behaviour 
	CppRefs_Behaviour Result;
	Result.__destructor__ = (void*)SC_CppRefs_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

CppRefs_Behaviour CppRefs_FuncTable_ = InitTableCppRefs_();
JBClassPlace4(CppRefs, JB_AsClass(JB_Object), CppRefs_FuncTable_);

DataTypeWrapper_Behaviour InitTableDTWrap_() { // Behaviour 
	DataTypeWrapper_Behaviour Result;
	Result.__destructor__ = (void*)JB_Wrap_Destructor;
	Result.render = (__Object_Render__)JB_Wrap_Render;
	return Result;
}

DataTypeWrapper_Behaviour DTWrap_FuncTable_ = InitTableDTWrap_();
JBClassPlace4(DTWrap, JB_AsClass(JB_Object), DTWrap_FuncTable_);

ErrorList_Behaviour InitTableJB_ErrorReceiver_() { // Behaviour 
	ErrorList_Behaviour Result;
	Result.__destructor__ = (void*)JB_Rec_destructor;
	Result.render = (__Object_Render__)JB_Rec_Render;
	return Result;
}

ErrorList_Behaviour JB_ErrorReceiver_FuncTable_ = InitTableJB_ErrorReceiver_();
JBClassPlace4(JB_ErrorReceiver, JB_AsClass(JB_Object), JB_ErrorReceiver_FuncTable_);

FastString* JB__FS_StdOutFS;
LeakTester_Behaviour InitTableLeakTester_() { // Behaviour 
	LeakTester_Behaviour Result;
	Result.__destructor__ = (void*)JB_Lk_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

LeakTester_Behaviour LeakTester_FuncTable_ = InitTableLeakTester_();
JBClassPlace4(LeakTester, JB_AsClass(JB_Object), LeakTester_FuncTable_);

Macro_Behaviour InitTableMacro_() { // Behaviour 
	Macro_Behaviour Result;
	Result.__destructor__ = (void*)JB_Macro_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

Macro_Behaviour Macro_FuncTable_ = InitTableMacro_();
JBClassPlace4(Macro, JB_AsClass(JB_Object), Macro_FuncTable_);

uint64 JB__Mrap_MDummy[2];
Memory_Behaviour InitTableMWrap_() { // Behaviour 
	Memory_Behaviour Result;
	Result.__destructor__ = (void*)JB_Mrap_Destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

Memory_Behaviour MWrap_FuncTable_ = InitTableMWrap_();
JBClassPlace4(MWrap, JB_AsClass(JB_Object), MWrap_FuncTable_);

Process* JB__Proc_Children[16];
byte JB__Proc_ClosePipesInstalled;
int JB__Proc_IncID;
Process* JB__Proc_Owner_;
byte JB__Proc_SpecialState;
Process_Behaviour InitTableProcess_() { // Behaviour 
	Process_Behaviour Result;
	Result.__destructor__ = (void*)JB_Proc_Destructor;
	Result.render = (__Object_Render__)JB_Proc_Render;
	return Result;
}

Process_Behaviour Process_FuncTable_ = InitTableProcess_();
JBClassPlace4(Process, JB_AsClass(JB_Object), Process_FuncTable_);

Array* SC__Imp_AllFiles;
SCImport* SC__Imp_Curr;
Date SC__Imp_Recent;
Dictionary* SC__Imp_Shaders;
bool SC__Imp_STDLibTime;
SCImport_Behaviour InitTableSCImport_() { // Behaviour 
	SCImport_Behaviour Result;
	Result.__destructor__ = (void*)SC_Imp_destructor;
	Result.render = (__Object_Render__)SC_Imp_Render;
	return Result;
}

SCImport_Behaviour SCImport_FuncTable_ = InitTableSCImport_();
JBClassPlace4(SCImport, JB_AsClass(JB_Object), SCImport_FuncTable_);

SCNodeRenamer_Behaviour InitTableSCNodeRenamer_() { // Behaviour 
	SCNodeRenamer_Behaviour Result;
	Result.__destructor__ = (void*)SC_NR_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

SCNodeRenamer_Behaviour SCNodeRenamer_FuncTable_ = InitTableSCNodeRenamer_();
JBClassPlace4(SCNodeRenamer, JB_AsClass(JB_Object), SCNodeRenamer_FuncTable_);

SCObject_Behaviour InitTableSCObject_() { // Behaviour 
	SCObject_Behaviour Result;
	Result.__destructor__ = (void*)SC_SCObject_destructor;
	Result.render = (__Object_Render__)SC_SCObject_Render;
	return Result;
}

SCObject_Behaviour SCObject_FuncTable_ = InitTableSCObject_();
JBClassPlace4(SCObject, JB_AsClass(JB_Object), SCObject_FuncTable_);

int SC__Opp_CustomOperatorScore;
Dictionary* SC__Opp_Dict;
SCOperator_Behaviour InitTableSCOperator_() { // Behaviour 
	SCOperator_Behaviour Result;
	Result.__destructor__ = (void*)SC_Opp_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

SCOperator_Behaviour SCOperator_FuncTable_ = InitTableSCOperator_();
JBClassPlace4(SCOperator, JB_AsClass(JB_Object), SCOperator_FuncTable_);

SCParamArray_Behaviour InitTableSCParamArray_() { // Behaviour 
	SCParamArray_Behaviour Result;
	Result.__destructor__ = nil;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

SCParamArray_Behaviour SCParamArray_FuncTable_ = InitTableSCParamArray_();
JBClassPlace4(SCParamArray, JB_AsClass(JB_Object), SCParamArray_FuncTable_);

Selector_Behaviour InitTableSelector_() { // Behaviour 
	Selector_Behaviour Result;
	Result.__destructor__ = (void*)JB_Sel_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

Selector_Behaviour Selector_FuncTable_ = InitTableSelector_();
JBClassPlace4(Selector, JB_AsClass(JB_Object), Selector_FuncTable_);

StringFields_Behaviour InitTableStringFields_() { // Behaviour 
	StringFields_Behaviour Result;
	Result.__destructor__ = (void*)JB_FI_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

StringFields_Behaviour StringFields_FuncTable_ = InitTableStringFields_();
JBClassPlace4(StringFields, JB_AsClass(JB_Object), StringFields_FuncTable_);

StringStream_Behaviour InitTableStringStream_() { // Behaviour 
	StringStream_Behaviour Result;
	Result.__destructor__ = (void*)JB_ss_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

StringStream_Behaviour StringStream_FuncTable_ = InitTableStringStream_();
JBClassPlace4(StringStream, JB_AsClass(JB_Object), StringStream_FuncTable_);

SyntaxObj_Behaviour InitTableSyntaxObj_() { // Behaviour 
	SyntaxObj_Behaviour Result;
	Result.__destructor__ = (void*)JB_Fn_destructor;
	Result.render = (__Object_Render__)JB_Fn_Render;
	return Result;
}

SyntaxObj_Behaviour SyntaxObj_FuncTable_ = InitTableSyntaxObj_();
JBClassPlace4(SyntaxObj, JB_AsClass(JB_Object), SyntaxObj_FuncTable_);

int SC__xC2xB5Form_Count;
Dictionary* SC__xC2xB5Form_Forms;
xC2xB5Form_Behaviour InitTablexC2xB5Form_() { // Behaviour 
	xC2xB5Form_Behaviour Result;
	Result.__destructor__ = (void*)SC_xC2xB5Form_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

xC2xB5Form_Behaviour xC2xB5Form_FuncTable_ = InitTablexC2xB5Form_();
JBClassPlace4(xC2xB5Form, JB_AsClass(JB_Object), xC2xB5Form_FuncTable_);

xC2xB5Func_Behaviour InitTableASMFunc_() { // Behaviour 
	xC2xB5Func_Behaviour Result;
	Result.__destructor__ = (void*)SC_ASMFunc_destructor;
	Result.render = (__Object_Render__)SC_ASMFunc_Render;
	return Result;
}

xC2xB5Func_Behaviour ASMFunc_FuncTable_ = InitTableASMFunc_();
JBClassPlace4(ASMFunc, JB_AsClass(JB_Object), ASMFunc_FuncTable_);

FastStringCpp_Behaviour InitTableFastStringCpp_() { // Behaviour 
	FastStringCpp_Behaviour Result;
	Result.__destructor__ = (void*)SC_FastStringCpp_destructor;
	Result.render = (__Object_Render__)JB_FS_Render;
	return Result;
}

FastStringCpp_Behaviour FastStringCpp_FuncTable_ = InitTableFastStringCpp_();
JBClassPlace4(FastStringCpp, JB_AsClass(FastString), FastStringCpp_FuncTable_);

bool JB__File_DebugExecute;
Instruction* SC__Instruction___First;
Instruction* SC__Instruction_ADD;
Instruction* SC__Instruction_ADDC;
Instruction* SC__Instruction_BAND;
Instruction* SC__Instruction_BFLG;
Instruction* SC__Instruction_BFLS;
Instruction* SC__Instruction_BNOT;
Instruction* SC__Instruction_BOR;
Instruction* SC__Instruction_BRA;
Instruction* SC__Instruction_BRAN;
Instruction* SC__Instruction_BROL;
Instruction* SC__Instruction_BROR;
Instruction* SC__Instruction_BXOR;
Instruction* SC__Instruction_CMPE;
Instruction* SC__Instruction_CMPF;
Instruction* SC__Instruction_CMPI;
Instruction* SC__Instruction_CMPN;
Instruction* SC__Instruction_CNTC;
Instruction* SC__Instruction_CONV;
Instruction* SC__Instruction_DADD;
Instruction* SC__Instruction_DDIV;
Instruction* SC__Instruction_DIV;
Instruction* SC__Instruction_DMUL;
Instruction* SC__Instruction_DSUB;
Instruction* SC__Instruction_EROR;
Instruction* SC__Instruction_FADD;
Instruction* SC__Instruction_FDIV;
Instruction* SC__Instruction_FMUL;
Instruction* SC__Instruction_FNC;
Instruction* SC__Instruction_FNCX;
Instruction* SC__Instruction_FSUB;
Instruction* SC__Instruction_HALT;
Instruction* SC__Instruction_LEAF;
Instruction* SC__Instruction_LUPD;
Instruction* SC__Instruction_LUPU;
Instruction* SC__Instruction_MEMM;
Instruction* SC__Instruction_MUL;
Instruction* SC__Instruction_PRNT;
Instruction* SC__Instruction_RALO;
Instruction* SC__Instruction_RARE;
Instruction* SC__Instruction_RD1S;
Instruction* SC__Instruction_RD1U;
Instruction* SC__Instruction_RD2S;
Instruction* SC__Instruction_RD2U;
Instruction* SC__Instruction_RD4S;
Instruction* SC__Instruction_RD4U;
Instruction* SC__Instruction_RD8U;
Instruction* SC__Instruction_RET;
Instruction* SC__Instruction_RETL;
Instruction* SC__Instruction_RSDE;
Instruction* SC__Instruction_RSET;
Instruction* SC__Instruction_SET1;
Instruction* SC__Instruction_SETK;
Instruction* SC__Instruction_SETN;
Instruction* SC__Instruction_SHLS;
Instruction* SC__Instruction_SHRS;
Instruction* SC__Instruction_SHRU;
Instruction* SC__Instruction_ST1U;
Instruction* SC__Instruction_ST2U;
Instruction* SC__Instruction_ST4U;
Instruction* SC__Instruction_ST8U;
Instruction* SC__Instruction_STCK;
Instruction* SC__Instruction_SUB;
Instruction* SC__Instruction_SWAP;
Dictionary* SC__Instruction_TypeDict;
Instruction* SC__Instruction_TypeList[256];
int SC__Instruction_TypeListSize;
Instruction_Behaviour InitTableInstruction_() { // Behaviour 
	Instruction_Behaviour Result;
	Result.__destructor__ = (void*)SC_Instruction_destructor;
	Result.render = (__Object_Render__)SC_Instruction_Render;
	return Result;
}

Instruction_Behaviour Instruction_FuncTable_ = InitTableInstruction_();
JBClassPlace4(Instruction, JB_AsClass(Selector), Instruction_FuncTable_);

MaterialsLol* SC__MaterialsLol___First;
MaterialsLol* SC__MaterialsLol_Iron;
MaterialsLol* SC__MaterialsLol_Pellets;
MaterialsLol* SC__MaterialsLol_WierdBlock;
MaterialsLol* SC__MaterialsLol_Wood;
MaterialsLol_Behaviour InitTableMaterialsLol_() { // Behaviour 
	MaterialsLol_Behaviour Result;
	Result.__destructor__ = (void*)SC_MaterialsLol_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

MaterialsLol_Behaviour MaterialsLol_FuncTable_ = InitTableMaterialsLol_();
JBClassPlace4(MaterialsLol, JB_AsClass(Selector), MaterialsLol_FuncTable_);

SaverClassInfo_Behaviour InitTableSaverClassInfo_() { // Behaviour 
	SaverClassInfo_Behaviour Result;
	Result.__destructor__ = (void*)JB_sci_destructor;
	Result.loadproperties = (__Saveable_LoadProperties__)JB_Array_LoadProperties;
	Result.savecollect = (__Saveable_SaveCollect__)JB_Array_SaveCollect;
	Result.savewrite = (__Saveable_SaveWrite__)JB_Array_SaveWrite;
	Result.render = (__Object_Render__)JB_Array_Render;
	return Result;
}

SaverClassInfo_Behaviour SaverClassInfo_FuncTable_ = InitTableSaverClassInfo_();
JBClassPlace4(SaverClassInfo, JB_AsClass(Array), SaverClassInfo_FuncTable_);

SavingTest_Behaviour InitTableSavingTest_() { // Behaviour 
	SavingTest_Behaviour Result;
	Result.__destructor__ = (void*)SC_SavingTest_destructor;
	Result.loadproperties = (__Saveable_LoadProperties__)SC_SavingTest_LoadProperties;
	Result.savecollect = (__Saveable_SaveCollect__)JB_Sav_SaveCollect;
	Result.savewrite = (__Saveable_SaveWrite__)SC_SavingTest_SaveWrite;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

SavingTest_Behaviour SavingTest_FuncTable_ = InitTableSavingTest_();
JBClassPlace4(SavingTest, JB_AsClass(Saveable), SavingTest_FuncTable_);

bool SC__Base_ConstantsLoadingOverride;
SCModule* SC__Base_CurrModule;
bool SC__Base_CurrVisibility;
SCBase_Behaviour InitTableSCBase_() { // Behaviour 
	SCBase_Behaviour Result;
	Result.__destructor__ = (void*)SC_Base_destructor;
	Result.render = (__Object_Render__)SC_SCObject_Render;
	return Result;
}

SCBase_Behaviour SCBase_FuncTable_ = InitTableSCBase_();
JBClassPlace4(SCBase, JB_AsClass(SCObject), SCBase_FuncTable_);

SCBehaviour_Behaviour InitTableSCBehaviour_() { // Behaviour 
	SCBehaviour_Behaviour Result;
	Result.__destructor__ = (void*)SC_Beh_destructor;
	Result.render = (__Object_Render__)SC_SCObject_Render;
	return Result;
}

SCBehaviour_Behaviour SCBehaviour_FuncTable_ = InitTableSCBehaviour_();
JBClassPlace4(SCBehaviour, JB_AsClass(SCBase), SCBehaviour_FuncTable_);

Message* SC__Class_ConstrLayerNew;
Message* SC__Class_ConstrLayerNew2;
Message* SC__Class_ConstrNew;
SCClass_Behaviour InitTableSCClass_() { // Behaviour 
	SCClass_Behaviour Result;
	Result.__destructor__ = (void*)SC_Class_destructor;
	Result.render = (__Object_Render__)SC_Class_Render;
	return Result;
}

SCClass_Behaviour SCClass_FuncTable_ = InitTableSCClass_();
JBClassPlace4(SCClass, JB_AsClass(SCBase), SCClass_FuncTable_);

SCDecl_Behaviour InitTableSCDecl_() { // Behaviour 
	SCDecl_Behaviour Result;
	Result.__destructor__ = (void*)SC_Decl_destructor;
	Result.render = (__Object_Render__)SC_Decl_Render;
	return Result;
}

SCDecl_Behaviour SCDecl_FuncTable_ = InitTableSCDecl_();
JBClassPlace4(SCDecl, JB_AsClass(SCObject), SCDecl_FuncTable_);

SCFile_Behaviour InitTableSCFile_() { // Behaviour 
	SCFile_Behaviour Result;
	Result.__destructor__ = (void*)SC_SCFile_destructor;
	Result.render = (__Object_Render__)JB_File_Render;
	return Result;
}

SCFile_Behaviour SCFile_FuncTable_ = InitTableSCFile_();
JBClassPlace4(SCFile, JB_AsClass(JB_File), SCFile_FuncTable_);

SCFunction* SC__Func_CurrFunc;
int SC__Func_DisabledPoints;
int SC__Func_FuncStats[12];
int SC__Func_OnceCount;
Dictionary* SC__Func_TemporalStatements;
SCFunction_Behaviour InitTableSCFunction_() { // Behaviour 
	SCFunction_Behaviour Result;
	Result.__destructor__ = (void*)SC_Func_destructor;
	Result.render = (__Object_Render__)SC_Func_Render;
	return Result;
}

SCFunction_Behaviour SCFunction_FuncTable_ = InitTableSCFunction_();
JBClassPlace4(SCFunction, JB_AsClass(SCBase), SCFunction_FuncTable_);

SCIterator* SC__Iter_c_array;
SCIterator* SC__Iter_pointer;
SCIterator_Behaviour InitTableSCIterator_() { // Behaviour 
	SCIterator_Behaviour Result;
	Result.__destructor__ = (void*)SC_Iter_destructor;
	Result.render = (__Object_Render__)SC_SCObject_Render;
	return Result;
}

SCIterator_Behaviour SCIterator_FuncTable_ = InitTableSCIterator_();
JBClassPlace4(SCIterator, JB_AsClass(SCObject), SCIterator_FuncTable_);

SCModule_Behaviour InitTableSCModule_() { // Behaviour 
	SCModule_Behaviour Result;
	Result.__destructor__ = (void*)SC_Mod_destructor;
	Result.render = (__Object_Render__)SC_Mod_Render;
	return Result;
}

SCModule_Behaviour SCModule_FuncTable_ = InitTableSCModule_();
JBClassPlace4(SCModule, JB_AsClass(SCBase), SCModule_FuncTable_);

xC2xB5Func1_Behaviour InitTableASMFunc2_() { // Behaviour 
	xC2xB5Func1_Behaviour Result;
	Result.__destructor__ = (void*)SC_ASMFunc2_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

xC2xB5Func1_Behaviour ASMFunc2_FuncTable_ = InitTableASMFunc2_();
JBClassPlace4(ASMFunc2, JB_AsClass(MWrap), ASMFunc2_FuncTable_);

GUIControl_Behaviour InitTableGUIControl_() { // Behaviour 
	GUIControl_Behaviour Result;
	Result.__destructor__ = (void*)SC_GUIControl_destructor;
	Result.loadproperties = (__Saveable_LoadProperties__)JB_Sav_LoadProperties;
	Result.savecollect = (__Saveable_SaveCollect__)JB_Sav_SaveCollect;
	Result.savewrite = (__Saveable_SaveWrite__)JB_Sav_SaveWrite;
	Result.render = (__Object_Render__)JB_Tree_Render;
	return Result;
}

GUIControl_Behaviour GUIControl_FuncTable_ = InitTableGUIControl_();
JBClassPlace4(GUIControl, JB_AsClass(RingTree), GUIControl_FuncTable_);

Message_Behaviour InitTableMessage_() { // Behaviour 
	Message_Behaviour Result;
	Result.__destructor__ = (void*)JB_Msg_destructor;
	Result.copyid = (__Message_copyid__)JB_Msg_copyid;
	Result.text = (__Message_text__)JB_Msg_text;
	Result.textset = (__Message_textset__)JB_Msg_textset;
	Result.loadproperties = (__Saveable_LoadProperties__)JB_Sav_LoadProperties;
	Result.savecollect = (__Saveable_SaveCollect__)JB_Sav_SaveCollect;
	Result.savewrite = (__Saveable_SaveWrite__)JB_Sav_SaveWrite;
	Result.render = (__Object_Render__)JB_Msg_Render;
	return Result;
}

Message_Behaviour Message_FuncTable_ = InitTableMessage_();
JBClassPlace4(Message, JB_AsClass(RingTree), Message_FuncTable_);

SCArg_Behaviour InitTableSCArg_() { // Behaviour 
	SCArg_Behaviour Result;
	Result.__destructor__ = (void*)SC_Arg_destructor;
	Result.render = (__Object_Render__)SC_Arg_Render;
	return Result;
}

SCArg_Behaviour SCArg_FuncTable_ = InitTableSCArg_();
JBClassPlace4(SCArg, JB_AsClass(SCBase), SCArg_FuncTable_);

int JB__Err_AutoPrint;
Error_Behaviour InitTableJB_Error_() { // Behaviour 
	Error_Behaviour Result;
	Result.__destructor__ = (void*)JB_Err_destructor;
	Result.copyid = (__Message_copyid__)JB_Msg_copyid;
	Result.text = (__Message_text__)JB_Msg_text;
	Result.textset = (__Message_textset__)JB_Msg_textset;
	Result.loadproperties = (__Saveable_LoadProperties__)JB_Sav_LoadProperties;
	Result.savecollect = (__Saveable_SaveCollect__)JB_Sav_SaveCollect;
	Result.savewrite = (__Saveable_SaveWrite__)JB_Sav_SaveWrite;
	Result.render = (__Object_Render__)JB_Msg_Render;
	return Result;
}

Error_Behaviour JB_Error_FuncTable_ = InitTableJB_Error_();
JBClassPlace4(JB_Error, JB_AsClass(Message), JB_Error_FuncTable_);

JB_String* JB_LUB[1790];

int JB_LUBLengths[] = {3, 3, 12, 10, 10, 12, 16, 14, 5, 7, 49, 5, 21, 6, 31, 14, 7, 7, 4, 15, 11, 25, 21, 4, 8, 15, 109, 5, 18, 14, 14, 8, 13, 13, 91, 11, 17, 19, 8, 11, 10, 8, 5, 11, 11, 2, 4, 7, 11, 9, 14, 83, 18, 18, 13, 22, 33, 41, 34, 23, 14, 13, 5, 4, 9, 18, 3, 3, 4, 4, 13, 6, 21, 26, 24, 21, 35, 24, 20, 26, 20, 28, 27, 27, 25, 26, 27, 25, 44, 18, 9, 22, 26, 7, 6, 9, 7, 7, 13, 11, 10, 58, 41, 3, 4, 5, 11, 7, 2, 18, 2, 18, 5, 3, 5, 5, 4, 6, 6, 3, 5, 6, 4, 6, 4, 7, 4, 4, 4, 5, 5, 5, 4, 9, 6, 6, 8, 5, 15, 10, 10, 5, 8, 3, 13, 4, 13, 14, 20, 15, 3, 11, 26, 2, 20, 19, 3, 18, 19, 4, 11, 2, 21, 4, 29, 29, 14, 1, 5, 5, 5, 3, 17, 10, 11, 8, 10, 9, 21, 20, 12, 12, 4, 2, 15, 14, 16, 4, 3, 1, 2, 14, 28, 1, 18, 31, 4, 4, 17, 21, 41, 37, 55, 36, 44, 71, 83, 35, 17, 2, 6, 15, 5, 7, 15, 41, 5, 4, 2, 14, 43, 7, 20, 16, 4, 3, 9, 8, 16, 8, 3, 9, 7, 8, 2, 9, 6, 7, 20, 2, 10, 5, 19, 10, 10, 6, 11, 9, 1, 11, 7, 1, 15, 13, 15, 4, 3, 3, 16, 40, 17, 39, 18, 7, 34, 4, 1, 16, 42, 44, 56, 6, 18, 27, 2, 33, 27, 70, 102, 5, 34, 14, 14, 58, 48, 36, 18, 50, 32, 3, 20, 114, 6, 4, 17, 51, 15, 17, 5, 26, 14, 21, 4, 7, 18, 3, 9, 10, 4, 13, 3, 15, 1, 5, 9, 8, 6, 5, 8, 14, 5, 6, 5, 10, 6, 4, 5, 8, 11, 6, 3, 9, 3, 4, 7, 7, 9, 8, 11, 5, 7, 5, 8, 6, 5, 7, 1, 4, 33, 32, 16, 2, 27, 84, 21, 24, 21, 24, 21, 6, 5, 5, 8, 6, 8, 4, 12, 5, 20, 19, 15, 7, 6, 8, 2, 10, 7, 6, 8, 8, 6, 7, 16, 26, 16, 360, 468, 12, 6, 3, 5, 9, 6, 2, 1, 1, 33, 44, 16, 1, 3, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 2, 3, 1, 5, 6, 6, 4, 1, 4, 1, 2, 1, 2, 8, 4, 6, 2, 7, 3, 17, 1, 2, 2, 2, 3, 1293, 1276, 6, 8, 4, 76, 11, 5, 20, 56, 86, 120, 14, 13, 78, 13, 1, 19, 28, 6, 4, 1, 14, 8, 14, 11, 11, 11, 11, 24, 2, 36, 9, 1, 1, 21, 2, 28, 1, 18, 22, 3, 17, 20, 4, 3, 9, 3, 2, 19, 37, 3, 20, 33, 3, 3, 2, 1, 11, 2, 15, 3, 1, 5, 10, 76, 31, 15, 1, 2, 1, 2, 3, 1, 1, 1, 5, 1, 17, 2, 1, 2, 2, 2, 3, 1, 2, 3, 1, 2, 2, 3, 3, 2, 9, 18, 2, 3, 29, 1, 8, 11, 9, 3, 8, 17, 6, 9, 17, 9, 14, 46, 15, 32, 29, 18, 16, 3, 4, 3, 3, 3, 1, 8, 11, 9, 11, 5, 14, 16, 5, 1, 8, 1, 14, 1, 1, 10, 1, 4, 2, 9, 2, 15, 2, 3, 2, 14, 14, 20, 17, 5, 53, 51, 2, 3, 6, 8, 7, 22, 116, 25, 38, 11, 5, 38, 18, 20, 15, 16, 5, 6, 11, 33, 9, 13, 7, 3, 3, 4, 9, 3, 3, 4, 28, 11, 10, 15, 4, 12, 10, 10, 2, 2, 19, 37, 14, 2, 2, 4, 3, 6, 5, 20, 14, 17, 5, 4, 6, 96, 46, 80, 17, 26, 28, 20, 22, 5, 7, 18, 14, 22, 5, 70, 31, 62, 28, 22, 19, 13, 31, 18, 22, 12, 2, 1, 13, 40, 21, 35, 6, 2, 2, 15, 8, 2, 6, 24, 2, 8, 3, 8, 3, 7, 3, 5, 3, 8, 3, 4, 3, 9, 4, 8, 4, 8, 4, 9, 4, 12, 3, 17, 4, 7, 3, 6, 4, 15, 4, 14, 3, 6, 3, 14, 4, 4, 8, 4, 18, 3, 3, 4, 8, 4, 8, 4, 19, 3, 9, 4, 19, 3, 6, 3, 5, 4, 4, 3, 14, 4, 9, 4, 9, 4, 11, 3, 12, 4, 19, 4, 21, 4, 22, 4, 13, 4, 8, 3, 4, 17, 4, 17, 3, 12, 4, 10, 3, 3, 4, 8, 15, 14, 11, 11, 11, 6, 5, 9, 4, 6, 5, 4, 10, 5, 9, 6, 15, 10, 6, 8, 6, 13, 7, 7, 8, 9, 11, 5, 10, 6, 6, 7, 8, 3, 9, 8, 7, 6, 9, 6, 9, 8, 4, 7, 8, 9, 7, 6, 11, 19, 7, 7, 13, 8, 813, 8, 4, 91, 4, 13, 3, 11, 3, 25, 4, 11, 4, 9, 4, 8, 3, 21, 15, 3, 28, 25, 37, 32, 3, 24, 49, 45, 6, 4, 26, 12, 34, 72, 18, 12, 19, 8, 26, 23, 19, 1, 20, 28, 37, 12, 20, 3, 26, 23, 40, 22, 27, 31, 32, 31, 6, 7, 7, 2, 4, 19, 29, 38, 30, 28, 27, 27, 1, 10, 21, 36, 25, 33, 26, 2, 1, 2, 1, 2, 1, 2, 2, 1, 2, 4, 3, 5, 4, 5, 4, 4, 3, 5, 4, 12, 21, 31, 38, 4, 5, 20, 4, 2, 5, 5, 5, 5, 6, 6, 6, 5, 5, 5, 6, 3, 3, 3, 3, 2, 4, 5, 3, 3, 12, 13, 10, 11, 11, 10, 10, 9, 3, 10, 5, 51, 20, 21, 15, 18, 25, 14, 15, 18, 18, 21, 15, 14, 4, 2, 8, 4, 2, 14, 15, 32, 2, 41, 15, 14, 2, 5, 10, 21, 9, 21, 11, 28, 19, 23, 5, 11, 3, 9, 4, 14, 15, 7, 8, 4, 12, 28, 2, 20, 4, 17, 37, 15, 4, 51, 23, 2, 14, 5, 3, 2, 38, 81, 5, 25, 37, 8, 4, 37, 118, 4, 7, 5, 28, 24, 3, 10, 6, 9, 20, 45, 139, 7, 23, 37, 27, 19, 1, 12, 323, 7, 16, 8, 18, 7, 6, 12, 4, 3, 22, 14, 9, 430, 39, 23, 51, 22, 27, 6, 6, 4, 2, 21, 2, 7, 11, 4, 5, 7, 4, 7, 2, 11, 6, 3, 5, 13, 3, 2, 11, 40, 14, 14, 18, 4, 23, 5, 24, 156, 2, 8, 4, 7, 9, 3, 33, 15, 1, 2, 2, 10, 2, 2, 6, 8, 7, 10, 12, 7, 14, 4, 10, 3, 22, 12, 7, 7, 12, 6, 8, 13, 14, 7, 14, 17, 20, 34, 43, 27, 17, 9, 10, 13, 7, 16, 4, 10, 9, 4, 4, 4, 26, 15, 20, 3, 13, 15, 17, 3, 23, 31, 7, 19, 9, 10, 14, 5, 20, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 15, 2, 2, 2, 1, 2, 135, 6, 2, 3, 4, 5, 3, 6, 6, 5, 3, 3, 10, 3, 11, 2, 10, 2, 9, 2, 18, 28, 11, 11, 5, 19, 52, 1, 20, 3, 17, 12, 9, 5, 8, 12, 3, 3, 4, 4, 2, 3, 14, 8, 21, 21, 4, 19, 8, 14, 5, 25, 6, 2, 45, 6, 7, 9, 2, 17, 8, 2, 15, 14, 4, 12, 5, 8, 11, 37, 6, 21, 28, 10, 7, 14, 5, 21, 15, 9, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 3, 4, 4, 4, 2, 4, 4, 2, 1, 2, 2, 2, 5, 4, 4, 2, 4, 3, 5, 3, 3, 4, 3, 26, 10, 4, 4, 7, 5, 7, 5, 2, 4, 18, 7, 4, 7, 25, 12, 25, 10, 17, 23, 8, 23, 11, 3, 9, 6, 15, 2, 12, 38, 35, 66, 3, 14, 31, 14, 30, 23, 4, 16, 7, 4, 34, 25, 9, 15, 68, 48, 29, 22, 39, 11, 17, 23, 22, 3, 47, 17, 7, 2, 22, 48, 9, 58, 37, 35, 33, 52, 19, 31, 2, 3, 42, 56, 11, 15, 6, 6, 13, 22, 10, 24, 12, 13, 67, 33, 9, 12, 2, 34, 10, 20, 35, 19, 37, 13, 15, 12, 12, 37, 5, 6, 11, 15, 3, 33, 45, 4, 7, 38, 34, 34, 10, 18, 19, 8, 26, 7, 8, 10, 9, 6, 4, 10, 23, 25, 8, 7, 5, 6, 2, 34, 12, 3, 14, 13, 11, 7, 12, 36, 101, 139, 171, 22, 24, 6, 36, 15, 19, 2, 25, 13, 26, 20, 39, 15, 40, 37, 22, 29, 64, 26, 5, 82, 26, 28, 3, 6, 4, 13, 19, 67, 13, 54, 30, 30, 34, 25, 52, 60, 23, 34, 65, 24, 24, 5, 3, 50, 52, 50, 55, 54, 10, 4, 3, 17, 3, 12, 2, 10, 18, 23, 7, 3, 4, 7, 6, 19, 4, 4, 13, 8, 100, 34, 3, 8, 25, 11, 19, 22, 37, 21, 15, 22, 9, 4, 4, 5, 8, 4, 8, 27, 26, 4, 13, 16, 17, 16, 25, 18, 15, 19, 3, 11, 4, 3, 9, 7, 4, 9, 9, 10, 4, 4, 13, 5, 2, 68, 37, 6, 16, 30, 58, 20, 10, 23, 35, 49, 40, 18, 7, 6, 2, 4, 10, 76, 9, 3, 22, 4, 4, 17, 9, 15, 35, 7, 22, 5, 46, 2, 7, 10, 3, 32, 37, 39, 44, 25, 8, 20, 20, 6, 2, 49, 21, 20, 11, 21, 6, 7, 22, 11, 19, 56, 37, 24, 13, 28, 5, 24, 126, 71, 3, 5, 9, 1, 37, 8, 10, 10, 12, 8, 14, 3, 25, 1, 5, 25, 3, 23, 53, 26, 33, 24, 38, 1, 26, 1, 6, 3, 7, 3, 2, 2, 12, 7, 13, 4, 16, 2, 12, 16, 31, 32, 15, 5, 5, 2, 32, 2, 53, 12, 4, 3, 10, 4, 18, 5, 7, 3, 3, 38, 28, 10, 8, 3, 5, 4, 15, 16, 44, 2, 6, 18, 8, 4, 36, 5, 21, 6, 4, 3, 11, 7, 7, 3, 5, 10, 44, 2, 71, 6, 2, 39, 15, 8, 2, 2, 2, 3, 21, 9, 3, 8, 5, 22, 10, 3, 6, 9, 9, 4, 9, 1, 8, 0};

const char* JB_LUBSrc = "abc\x00""def\x00""AboutToCrash\x00/tmp/logs/\x00.crash.txt\x00""codesign_osx\x00""exiting speedie \x00OrigScriptPath\x00prefs\x00""default\x00""App pref path should be 'default' or a full-path.\x00""first\x00""Compiling as library.\x00main:\n\x00""app.configure = __AppConfString\x00__IS_LIBRARY__\x00.scproj\x00general\x00libs\x00/usr/local/lib/\x00""Frameworks/\x00This should not be a link\x00""Create MacOSX Package\x00.app\x00Release/\x00""Contents/MacOS/\x00No export_api found for library-compile. Either create export_api, or create 'main' to make it not a library.\x00 has \x00 float params and \x00 float result.\x00 args of size \x00 maxvars\x00 funcs used. \x00 funcs total.\x00No code-signature found. (`speedie --codesign=\x22""details\x22 to save signature). Unable to sign \x00""Compilation\x00More constructors\x00Stripping dead code\x00RefCount\x00""Exporting C\x00""Export Cpp\x00""Finished\x00Parse\x00__classes__\x00__modules__\x00JB\x00main\x00Visible\x00Interpreter\x00SaveWrite\x00LoadProperties\x00""Can\xE2\x80\x99t make one save/load function but not the other. Either make both or neither.\x00/tmp/SpdPathHidden\x00/tmp/SpdLinkHidden\x00""a/b/c/d/e.txt\x00Unable to delete files\x00Testing link+write failed. Read: \x00""Expected a class but found something else\x00""Expected a class but found module.\x00""Can\xE2\x80\x99t find function: \x00""Can\xE2\x80\x99t find: \x00Not a module.\x00nomod\x00.spd\x00/Speedie/\x00/usr/local/speedie\x00""Cpp\x00""app\x00name\x00Read\x00""Finding Files\x00Import\x00Initialising Compiler\x00Processing Delayed Imports\x00""Creating Class Hierarchy\x00Savers and behaviours\x00""Creating Class Allocators And Stuff\x00Parsing Class Properties\x00""Collecting Constants\x00""Creating Class Exportnames\x00Initialising Modules\x00Handling Function Prototypes\x00Parsing Function Parameters\x00""A Bit More Stuff On Classes\x00""Collecting File Variables\x00""Even More Stuff On Classes\x00""Collecting Module Variables\x00Renaming Module Variables\x00""Creating Exportnames For Function Prototypes\x00""Checking Iterators\x00Transform\x00Transforming Functions\x00""Building Function Link Map\x00Library\x00Jeebox\x00JB_SetRef\x00JB_Incr\x00JB_Decr\x00JB_FreeIfDead\x00JB_SafeDecr\x00JB_Ternary\x00""function Private () {disabled `This property is private.`}\x00""Error in source syntax. Can\xE2\x80\x99t continue.\x00nil\x00true\x00""false\x00__time_id__\x00__now__\x00\xCF\x80\x00""3.1415926535897932\x00\xCF\x84\x00""6.2831853071795864\x00""Build\x00int\x00int16\x00int64\x00uint\x00uint16\x00uint64\x00""f64\x00""float\x00hfloat\x00""bool\x00string\x00""byte\x00""charset\x00vec2\x00vec3\x00vec4\x00ivec2\x00ivec3\x00ivec4\x00""date\x00""classdata\x00object\x00syntax\x00_voidptr\x00_void\x00""datatypewrapper\x00""dictionary\x00""faststring\x00""array\x00saveable\x00../\x00Insecure path\x00Test\x00Jeebox.scproj\x00Installation: \x00""Conf already exists!\x00__AppConfString\x00gui\x00initcode_()\x00""Disabled functions called \x00x!\x00\nClasses:           \x00""Funcs:             \x00 / \x00Total elapsed:\t   \x00Input source code: \x00 KB\n\x00""FuncStats: \x00, \x00""Conf missing prefpath\x00talk\x00""Can\xE2\x80\x99t sort classes properly\x00SortModulesSub too many loops\x00Speedie.scproj\x00 \x00  :: \x00 ::  \x00perry\x00#!/\x00/tmp/SpeedieApps/\x00""funcs.jbin\x00JB_File.cpp\x00JB_OSX.m\x00JB_PNG.cpp\x00JB_VM.cpp\x00JB_DirReaderWin32.cpp\x00JB_DirReaderUnix.cpp\x00JB_Child.cpp\x00LatestBackup\x00.cpp\x00.h\x00Terminal/Backup\x00/tmp/Speedie64\x00/tmp/SpeedieApps\x00 -c \x00""cpp\x00m\x00mm\x00Library/CppLib\x00-std=gnu++17  -stdlib=libc++\x00o\x00 -x objective-c++ \x00-fobjc-arc  -fobjc-link-runtime\x00-m32\x00-m64\x00-L/usr/local/lib/\x00-I /usr/local/include\x00-F/Library/Frameworks  -framework Cocoa  \x00-rpath @executable_path/../Frameworks\x00-rpath ~/Library/Frameworks  -rpath /Library/Frameworks\x00-w  -Wno-return-type-c-linkage -lc++\x00-finput-charset=UTF-8 -fextended-identifiers\x00 -fno-strict-aliasing  -fvisibility=hidden  -fvisibility-inlines-hidden\x00 -march=core2  -ffast-math  -mfpmath=sse  -mmmx  -msse  -msse2  -msse4.1  -msse4.2 \x00-fdata-sections -ffunction-sections\x00-dynamiclib -fPIC\x00-g\x00 -O0  \x00 -mtune=native \x00 -Os \x00 -flto \x00-D AS_LIBRARY=1\x00   -D TARGET_UNIX=1 -D __SPEEDIE__=1  -I \x00  -I \x00 -I \x00  \x00/usr/bin/clang\x00""C++ compiler failed to compile source code.\x00\nclang \x00Installing Speedie: \x00Terminal/Speedie\x00Mini\x00Lib\x00""build.txt\x00_Speedie\x00libspeedie.dylib\x00Lib at: \x00-o \x00/JB_Main.\x00/JB_VM.\x00/JB_OSX.\x00.o\x00Terminal/\x00.dylib\x00speedie\x00\nCompiling c++ to: \x22\x00\x22\n\x00\n()   Test\x00   ()\x00 already up to date\x00""BuildTest2\x00""BuildTest3\x00--self\x00--variant=2\x00--nocolor\x00""2\x00--variant=3\x00--final\x00""3\x00 doesn't match \x00/tmp/Speedie/\x00/tmp/Speedie64/\x00.txt\x00""err\x00out\x00JB_FS_AppendByte\x00Places the .cpp and header files locally\x00We seems alive :)\x00""Check only. same as --nocompile --cpp=0\x00Remove temp files.\x00""Cleaned\x00Gets/Sets the codesign certificate\x00none\x00-\x00""Codesign set to \x00""Compiles to cpp, using clang. Default true\x00""Crashes speedie to test it's crash handlers.\x00""Allows me to test certain compiler features more easily.\x00""direct\x00""Code signs an app.\x00Print environment variables\x00: \x00Tests if error handling works OK.\x00""Errors print successefully\n\x00""Forces recompilation even if the output is newer than the input files.\x00Spams each func with a static int, to count the number of times it's called. Useful debugging feature.\x00This.\x00Show more errors that were hidden.\x00""32-bit compile\x00""64-bit compile\x00Reports maximum number of vars/funcs/args used in program.\x00""Don't print text coloring symbols for terminals.\x00Will not compile any .cpp generated.\x00Prints more stuff.\x00Optimisation level. (0 to 3... EG: '--Optimise=1')\x00Specifies the build product path\x00""bin\x00klinkerhoppen.banned\x00""Acceptable values: pack, cpp, native. Combine like pack/native. 'native' = compiled via GCC. 'pack' = interpreted.\x00native\x00pack\x00Prints less stuff\x00""Compiles and installs new Speedie, after self-test.\x00Self-test only.\x00Prints the stages\x00""debug\x00Use 'targetdebug' instead.\x00Show warnings.\x00Print version number.\x00spd \x00Usage: \x00 /path/to/project\n\x00\n--\x00nocompile\x00""breakonerr\x00path\x00keepallerrors\x00""env\x00""externalcompile\x00x\x00""check\x00""errortest\x00""argstats\x00noisy \x00""alive\x00products\x00ignorecantsave\x00quiet\x00stages\x00print\x00""directtest\x00single\x00self\x00""crash\x00__talk__\x00targetdebug\x00target\x00m64\x00""funccount\x00m32\x00warn\x00maxvars\x00nocolor\x00selfdebug\x00optimise\x00output_path\x00""force\x00variant\x00""final\x00""codesign\x00""dosign\x00""clean\x00version\x00v\x00help\x00\nError: No operations requested.\n\x00\nToo many operations requested.\n\x00Unknown switch '\x00'\n\x00""Don't compile Library files\x00read project. (You may create it with: 'speedie --create /path/to/proj' if you want)\x00""asm_test,asm_test_sub\x00This function has no ASM\x00This isn't a function\x00""Can't find this function\x00This must be at root.\x00nopath\x00nomsg\x00""error\x00""callfrom\x00""define\x00nodefine\x00line\x00missing @arg\x00Perry\x00missing date in @arg\x00missing cmd in @arg\x00Not implemented\x00""display\x00""badcmd\x00nosource\x00__\x00""displayall\x00""compile\x00nofile\x00""badinput\x00noparent\x00notype\x00noscope\x00handling restart\x00restart grabbing a command\x00reading commands\x00return, require, \x22log <string>\x22, while, linkage, for, if, else, elseif, expect, warn, error, disabled, cpp_refs, once, debugger, debugat, deprecate, `description \x22<describe this function>\x22`, print, printline, zalgoline, printerror, beep, continue_with, cpp_part, cpp_name, cpp_wrapper, `self.`, `super.`, \x22visible\x22, \x22""exit\x22, \x22opt norefcounts\x22, \x22pragma inline\x22\n \x00\n@RCM\n\x22""function <name>\x22\n\x22helper <name>\x22\n\x22target <name>\x22\n@CM\nlinkage\n\x22syntax <kind>\x22\n@C\nmodule\nrender\niterator\n\x22operator <name>\x22\n\x22""behaviour <name>\x22\n\x22virtual <name>\x22\nconstructor\ndestructor\n@R\n\x22main\\n\\t<// code here>\x22\n\x22""extend_module <name>\x22\n\x22""class <name>\x22\n\x22role <name> (super_class)\x22\n\x22""datatype <name> (super_class)\x22\n\x22""extend <class_name>\x22\n\x22module <name>\x22\n\x22""dispatch <name> (<Parameters>)\x22\n@L\n\x22""cpp_part <name>\x22\n\x22""cpp_class <name>\x22\nvisible true\n\x22opt min <1-3>\x22\nwrapper\nnoauto\n\x00""autocomplete\x00import\x00log\x00nolen\x00""behaviour\x00result\x00ok\x00<\x00r\x00Jeebox: NilObjectError in caller.\x00Jeebox: Too many NilObjectErrors. Silencing.\x00\n(\xC4\xB4\xC3\xAB\xC3\xAA\xC6\x81o\xE2\x93\xA7) \x00\x00\x00\\00\x00\n\x00\\n\x00\r\x00\\r\x00\t\x00\\t\x00\x22\x00\\\x22\x00'\x00\\'\x00\\\x00\\\\\x00&#\x00\\&#\x00&\x00&amp;\x00&apos;\x00&quot;\x00&lt;\x00>\x00&gt;\x00\x08\x00\\b\x00\x0C\x00\\f\x00""AZaz09__\x00""AZaz\x00""AZaz__\x00\n\r\x00 ,:\t\n\r\\\x00\n\r,\x00 \t\n\r\x0F-^+/\\*:;<>=,\x00$\x00\\$\x00\\0\x00${\x00$\\{\x00//jb self-test file.\n\x22Tests all syntax in small amount of code.\x22\n`Does not make sense in any other way.`\n\nhow %can someone fall so~far #without %realising it\n\nhttp://hello.kitty\n\n+\x22hahaha :3\x22\n\t+\x22""bbbb ()\x22 eeeep!\n\nstory X (\n\t\xE2\x80\x93which dog\n\tx (a < b) c\n\t\t\t-->\n\tsonic@the~hedgedog or @jeebox\n\t\n\t>~slowly i ran home\n\t\n\tA ((B~C)~D E F~G) I #W A t (o:c)\n)\n\n\n\nza a {\n\tart \xE2\x89\x88 brt // abc /deff\\ xyz\n\t1 (crt \xE2\x89\x88 drt) 2\n\t|1| x * y * z = \?()\?\n\t|| a = c or d\n\t(a,)\n\t([] --> a + a, b, d:e)\n\t[|0|d, a+b:c, [c, d]] /* /*\n\t\tnested comments!\n\t\t*/ I found it useful.*/\n\n\t// }\n}\n\nd d // savetext\n\tc c\n\t\ta, bbbbb\n\n#(70 68 61 6e 74617379207374617220706c696e6b20706c6f6e6b20706c696e6b2069747320736f2062656175746966 75 6c)# \n\nfunction name (|x: y + z| a, ||) {\n\t// label : func()\n\t\x22'\\\x22stri\\c3\\b1g test\\\x22'\x22\n\t`\\n\\(&#x134;&#xEB;\\C3\\AA\\C6\\81o&#9447;\\)`\n\t\x22\\n\\(&#x134;&#xEB;\\C3\\AA\\C6\\81o&#9447;\\)\x22\n\t--x-- mod= 'ioi \\'\x22\x22\\'oio'\n\t\n\ty.size(...\?, ..., <(`s`t`r`)>).y(-z)\n\n\tx = \x22{ab${x} ${y}${z}ab}\x22 + `abc`\n\t|(a,)|z += .exit(code: -3)\n\n\tfor (a in b) {\n\t\t$a$ = &b + !c!\n\t}\n\n\tif ('a' & b === !b (|) c) ^ (a ~>= b)\n\t\tif a: return 0xff + 10_miles\n}\n\n\n<\?xml version=\x22""1.0\x22 encoding=\x22UTF-8\x22\?>\n<\?why G A V~E\?>\n<!--comments\?\?\?\?\?<><><>YUSAJKD;-->\n<xml abc=\x22""def\x22 ghi=\x22&apos;abc&apos;\x22>\n\t<K C=\x22""def\x22/>\n\t<text>\n\t\tiiii&amp;jjjj\n\t</text>\n</xml>\n\x00\x10\x03@\x01\xA9\x0ETests all syntax in small amount of code.\xA5\tDoes not make sense in any other way.C\x06how@\x0C\x83\x04""can@&@$\x87\x03someone\x84\x04""fall@\x1A\x82\x03so\x83\x03""far\xC2\x87\x05without@\x0C\x89\x04realising\x82\x03it\xC4""D/http\x8B\x0Ehello.kitty\xC1I\x06hahaha :3@\x01G\x06""bbbb ()A\x15!\x85\x03""eeeep\xC4""E\x06story\x81\x03X@\x1F@\x08\x85\x03which\x83\x03""dog\xC1@&@$\x81\x03x@\x02@$\x81\x04""a\x81\x04<\x81\x04""b\xC2\x81\x03""c\xC1\x83\x10-->@$E\x07sonic@\x1A\x83\x03the\x88\x03hedgedog\xC2\x82\x04or\x86\x07jeebox\xC2@)\x81\x03i@\x1A\x86\x04slowly\x83\x04ran\xC1\x84\x03home\xC1@&@$\x81\x03""A@\x02@$@\x1A@\x02@\x1A\x81\x04""B\x81\x04""C\xC2\x81\x04""D\xC1\x81\x04""E@\x1A\x81\x04""F\x81\x04G\xC3\x81\x03I\xC1\x81\x05W@$\x81\x03""A\x81\x04t@\x1F@\x1E\x81\x03o\x81\x03""c\xC6""B\x06za\x81\x03""a@\x01@\x1B\x83\x03""brt\x83\x03""art\xC1@$\x81\x11""1@\x02@\x1B\x83\x04""drt\x83\x04""crt\xC2\x81\x11""2\xC1@#\x81\x11""1@$\x81\x03x\x81\x04*@$\x81\x03y\x81\x04*@$\x81\x03z\x81\x04=A\x19\?A\x15\?\x80\x1F\xC6@#\x80\x12@$\x81\x03""a\x81\x04=@$\x81\x03""c\x82\x04or\x81\x03""d\xC3@\x1F\x81\x03""a\xC1@\x1F@&\x80\x1D\x83\x10-->@$\x81\x03""a\x81\x04+\x81\x03""a\xC2\x81\x03""b@\x1E\x81\x03""d\x81\x03""e\xC2@\x1D@#\x81\x11""0\x81\x03""d\xC1@\x1E@$\x81\x03""a\x81\x04+\x81\x03""b\xC1\x81\x03""c\xC1@\x1D\x81\x03""c\x81\x03""d\xC4""A\x06""d\x81\x03""d@\x01""A\x06""c\x81\x03""c@\x01\x81\x06""a\x85\x06""bbbbb\xC4\xB0""6phantasy star plink plonk plink its so beautifulH\x06""function\x84\x03name@\x1F@#@\x1E\x81\x03x@$\x81\x03y\x81\x04+\x81\x03z\xC2\x81\x03""a\xC1@#\x80\x12\xC2@\x01\x90\x0E'\x22stri\xC3\xB1g test\x22'\xA7\t\\n\\(&#x134;&#xEB;\\C3\\AA\\C6\\81o&#9447;\\)\x8F\x0E\n(\xC4\xB4\xC3\xAB\xC3\xAA\xC6\x81o\xE2\x93\xA7)@%B\x19--B\x15--\x81\x03x\xC2\x83\x04mod\x8B\nioi '\x22\x22'oio\xC1""A\x16yD\x16size\x81\x03y@ A\x15\?\x83\x0F...\xC1\x83\x0F...\x85\x0Bs`t`r\xC2@ A\x19-\x81\x03z\xC3@$\x81\x03x\x81\x04=@$@\x0E\x83\x12{ab\x81\x03x\x81\x12 \x81\x03y\x81\x03z\x83\x12""ab}\xC1\x81\x04+\x83\tabc\xC2@#@\x1F\x81\x03""a\xC1@%\x81\x03z\x81\x04+D\x17""exit@ @\x1E\x84\x03""code\x82\x11-3\xC5""C\x06""for@\x02@$\x81\x03""a\x82\x04in\x81\x03""b\xC2@\x01@$A\x19$A\x15$\x81\x03""a\xC2\x81\x04=@$A\x19&\x81\x03""b\xC1\x81\x04+A\x19!A\x15!\x81\x03""c\xC6""B\x06if@$@\x02@$\x81\na\x81\x04&@$\x81\x03""b\x83\x04===@$A\x19!\x81\x03""b\xC1\x83\x04(|)\x81\x03""c\xC4\x81\x04^@\x02@$\x81\x03""a\x83\x04~>=\x81\x03""b\xC3@\x01""B\x06if\x81\x03""a@\x01""F\x06return@$\x84\x11""0xff\x81\x04+E\x13miles\x83\x11""10_\xC9@2C\x06xml@$\x87\x03version\x81\x04=@%\x83\x0E""1.0\x88\x04""encoding\x85\x0EUTF-8\xC4@2C\x06why@$\x81\x03G\x81\x04""A@\x1A\x81\x03V\x81\x03""E\xC4\x9B""3comments\?\?\?\?\?<><><>YUSAJKD;C1xml@\x01""C0abc\x83""5def\xC1""C0ghi\x85""5'abc'\xC2""A1K@\x01""A0C\x83""5def\xC3""D1text\x80\x01\x89""5iiii&jjjj\x00normal\x00""entities\x00jbin\x00Supposed to be like: linkage { osx = \x22linker flags\x22, win = \x22linker flags2\x22 }\x00interpreter\x00""flags\x00|| fs = faststring()\x00({\n\t|| _X = _0\n\tif !_X\n\t\t_X = _1\n\t\t_0 = _X\n\trejoin _X\n})\x00({\n\t|| _ErrCount = stderr.errorcount \n\t(_0)\n\trejoin stderr.errorcount == _ErrCount \n})\x00""datatype _0 (ASM) \n\tmodule\n\t\tfunction Encode (ASM_Encoder2,)\n\t\t\trz = .op << 25\n\t\t\nASM.Forms[_1] = &_0.Encode // for now\n\x00rz._0 = .r[_1]\x00rz._0 = .rest\x00""function asm._0 (assigns:|uint|, |asm|): return self (|) ((value << _1) >> _2)\x00Indent is odd\x00|\x00""Close-tag malformed\x00Open/close tags mismatch! </\x00> vs <\x00<\xE2\x89\x88\x00(\x00Missing close \x00Nested '\x00' not allowed.\x00Unexpected \x00 but found \x00""end-of-line\x00""end-of-data\x00""Found illegal-character \x00""0x\x00""Expected a letter (aA-zZ, '_', etc).\x00Missing '\x00]\x00}\x00String did not close.\x00)#\x00""Binary section didn't close!\x00)\x00""Char didn't close!\x00""Comment did not close.\x00\xE2\x80\x93\x00Unexpected syntax\x00""Element didn't close\x00<!--\x00-->\x00<![CDATA[\x00]]>\x00\xC2\xBB\x00Needs a space here.\x00""Can\xE2\x80\x99t have '=' after this operator.\x00\xE2\x80\x9D\x00String didn't close!\x00""Embedded expression didn't close.\x00<(`\x00`)>\x00#/\x00:\x00""Bad Doctype\x00\?>\x00Indent too low.\x00\r \n\x00,\x00line \x00""0123456789\x00= == === < > <= <== >= >== <> ~<> != !== <=> ~>= ~<= ~> ~< <~ ~= ~!= ~<=> :=\x00* / \\ + - ^ & >> << >>> <<< (|)\x00++ -- $ ! \? ...\x00[\x00\xC2\xAB\x00.\x00..\x00://\x00+\x00@\x00~\x00- * ~\x00{\x00--> <-- <--> <\xE2\x89\x88\x00/#\x00%\x00#!\x00//\x00/*\x00...\x00`\x00#(\x00\xE2\x89\x88\x00#\x00>~\x00\xC2\xAC\x00\xE2\x80\x9C\x00\xE2\x88\x86\x00<\?\x00<!DOCTYPE\x00] ) } #/ \xC2\xBB \xE2\x80\x9D \?>\x00::\x00!~=\x00""Can't have tabs after spaces.\x00=\x00temporal\x00""declaration\x00statement\x00':'\x00operator\x00temporal-operator\x00""a name\x00something\x00illegal-character\x00""Expected \x00something else\x00Must be a proper name (a-z or unicode-letters)\x00""Expected a rel.\x00""Can\xE2\x80\x99t use temporals like this.\x00""Attribute value didn't close.\x00""Element malformed.\x00Tag didn't close\x00lin\x00.log\x00osx\x00win\x00""api\x00_\x00""cpp_name\x00libraryname\x00""class_api\x00""exportplace\x00hello\x00SavingTest.txt\x00SaveTest failed.\x00point\x00P\x00triangle\x00T\x00triangle_strip\x00t\x00L\x00line_strip\x00l\x00""cube\x00""C_\x00""billboard\x00""B_\x00shadowselection\x00H_\x00sdf\x00S_\x00ModelTest.vert\x00ModelTest.frag\x00""Can\xE2\x80\x99t find shader \x00Not a good model.\x00while\x00""Can only call constructors from within a constructor.\x00""Can only call destructors from within a destructor.\x00or\x00""and\x00return\x00selector\x00\nclass \x00 (selector)\n\tcontains \x00\n\tconstructor (|selector| Next, |&selector| Place, |string| name1)\n\t\tsuper.constructor(next, place, name1)\n\n\tmodule \x00\n\t\tfunction __LoadSel (|&\x00| Place, |string| Name)\n\t\t\tvisible\n\t\t\t\x00.__First = \x00.new(\x00.__First, place|&selector|, name)\n\n\t\t|\x00| __First\n\t\t...\n\t\t\x00.__first.GiveIDs\n\n\t\t\x00instructionlist\x00Should be empty.\x00items\x00module\x00""constructor\x00Selectors can't have constructors\x00__LoadSel\x00selector_init\x00ignored\x00the\x00""asm\x00""data\x00No params\x00mod\x00(|)\x00""ASM_\x00""extend_module ASM:constants:\x00\n#define   \x00       (((\x00int)((Op.Raw)<<\x00))>>\x00)\n#define   \x00_(x)   (((\x00int)((x)<<\x00)\n\x00_L\x00Too many total bits\x00Too large field. 25 bits max, found: \x00Too many forms\x00&&\x00,\n\x00\t// \x00\xC4\xB1 \x00vm.box\x00""forms\x00InstructionGetters.h\x00Instructions.i\x00InstructionList.h\x00\xC4\xB1 \n\n\x00""EROR\x00ignore\x00\xCC\x8D\xCC\x8E\xCC\x84\xCC\x85\xCC\xBF\xCC\x91\xCC\x86\xCC\x90\xCD\x92\xCD\x97\xCD\x91\xCC\x87\xCC\x88\xCC\x8A\xCD\x82\xCD\x83\xCD\x84\xCD\x8A\xCD\x8B\xCD\x8C\xCC\x83\xCC\x82\xCC\x8C\xCD\x90\xCC\x80\xCC\x81\xCC\x8B\xCC\x8F\xCC\x92\xCC\x93\xCC\x94\xCC\xBD\xCC\x89\xCD\xA3\xCD\xA4\xCD\xA5\xCD\xA6\xCD\xA7\xCD\xA8\xCD\xA9\xCD\xAA\xCD\xAB\xCD\xAC\xCD\xAD\xCD\xAE\xCD\x9B\xCD\x86\xCC\x9A\x00\xCC\x95\xCC\x9B\xCD\x80\xCD\x81\xCD\x98\xCC\xA1\xCC\xA2\xCC\xA7\xCC\xA8\xCC\xB4\xCC\xB5\xCC\xB6\xCD\x8F\xCD\x9C\xCD\x9D\xCD\x9E\xCD\x9F\xCD\xA0\xCD\xA2\xCC\xB8\xCC\xB7\xCD\xA1\xD2\x89\x00\xCC\x96\xCC\x97\xCC\x98\xCC\x99\xCC\x9C\xCC\x9D\xCC\x9E\xCC\x9F\xCC\xA0\xCC\xA4\xCC\xA5\xCC\xA6\xCC\xA9\xCC\xAA\xCC\xAB\xCC\xAC\xCC\xAD\xCC\xAE\xCC\xAF\xCC\xB0\xCC\xB1\xCC\xB2\xCC\xB3\xCC\xB9\xCC\xBA\xCC\xBB\xCC\xBC\xCD\x85\xCD\x87\xCD\x88\xCD\x89\xCD\x8D\xCD\x8E\xCD\x93\xCD\x94\xCD\x95\xCD\x96\xCD\x99\xCD\x9A\xCC\xA3\x00Missing argument.\x00""Expected this for a struct\x00""Expected this for a datatype\x00Unrecognised pragma.\x00""Can\xE2\x80\x99t use this here.\x00Value\x00""assigns\x00Not a declaration.\x00No name found.\x00Must be a proper name.\x00_fsf0\x00""Function declarations need a type. (Unless it's in a container class.)\x00Missing type, or default value.\x00Variables can\xE2\x80\x99t be borrowed in function parameters or return\x00Parameter is missing a name.\x00parent of expected is \x00parent of found is \x00self_test.txt\x00self_test.txt can\xE2\x80\x99t be found.\x00__SELF_TEST_JBIN__\x00Really bad error here!\x00SyntaxEquals\x00!=\x00!\x00SyntaxCompare\x00\\n\\(&#x134;&#xEB;\\C3\\AA\\C6\\81o&#9447;\\) \x00 loaded successfully\n\x00""Expected something like: |Type[10]|\x00memory\x00of\x00--\x00Must be numeric\x00""debugger\x00if\x00rejoin\x00Unknown statement in ASM\x00\x10\x03\x00WildCard\x00""arg\x00""Argument\x00""bra\x00""Bracket\x00thg\x00Thing\x00opp\x00Operator\x00""cnj\x00""conj\x00tmp\x00Statement\x00ques\x00Question\x00""back\x00""Backtick\x00""char\x00""Character\x00sstr\x00Super_String\x00oat\x00Operator_As_Thing\x00sheb\x00Shebang\x00str\x00String\x00sthg\x00Syntactic_Thing\x00scnj\x00Syntactic_conj\x00num\x00Number\x00""emb\x00""Embedded_Value\x00unit\x00type\x00Typecast\x00""arel\x00""After_Relationship\x00""dot\x00""Dot\x00sdot\x00Self_Dot\x00""func\x00""Function\x00""brel\x00""Before_Relationship\x00""adj\x00""Adjective\x00""badj\x00""Backwards_Adjective\x00""acc\x00""Access\x00""arr\x00""Array\x00item\x00list\x00prm\x00Parameter_List\x00""file\x00""File_List\x00quot\x00Quotation\x00""decl\x00""Declaration\x00rel\x00Relationship\x00""erel\x00""Equals_Relationship\x00trel\x00Temporal_Relationship\x00tril\x00Temporal_Relationship2\x00pinn\x00Post_InnerAdj\x00""binn\x00InnerAdj\x00""ask\x00yoda\x00Yoda_Relationship\x00scom\x00Syntactic_Comment\x00msg\x00Message_List\x00todo\x00To_Do_List\x00url\x00URL\x00love\x00""function\x00""extend_function\x00""cpp_libwrapper\x00""cpp_wrapper\x00""cpp_inbuilt\x00""cpp_nothing\x00helper\x00macro\x00insertion\x00""conf\x00static\x00""class\x00role\x00""export_api\x00model\x00prototype\x00render\x00""compile_linking\x00shell_args\x00struct\x00""datatype\x00""extend\x00""extend_module\x00""extends\x00library\x00""cpp_part\x00""constants\x00""debuginsert\x00""const\x00""destructor\x00setter\x00""fields\x00virtual\x00iterator\x00syx\x00processas\x00""cpp_refs\x00linkage\x00pragma\x00initafter\x00saveas\x00""cpp_class\x00""contains\x00size\x00""disowns\x00""disturbs\x00paramsafe\x00visible\x00inline\x00noearlyfree\x00""dontdestructlocally\x00wrapper\x00numeric\x00Name conflict\x00""AZaz__09\x00//jb\n\ntests oofit\n\tasm oofit (0)\n\t\tSET1  (r1, 3458764513820540931) //test\n\t\tSET1  (r1, 123)\n\t\t@test\n\t\tSET1  (r3, 18874368)\n\t\tSET1  (r3, -234)\n\t\tADD   (r1, r1, r3)\n\t\tPRNT  (r1,)\t\t\t// -111\n\t\tBRA   (r4, 1, @test)\n\t\tHALT  (r0,)\n\n\n\n/*\n/* func find (str, b) {\n    end = str.length\n    if (end) {\n        curr = str.addr\n        end += curr\n        loop:;\n        if (*curr == b) {\n            return curr - str.addr\n        }\n        if (++curr < end) {\n            goto loop\n        }\n    }\n    return -1\n} */\n\n    ASM program[] = {\n\t\t0,\n        RD4,  // length\n        BRA,  // if length\n        RD4,  // curr\n        ADD,  // end-ptr\n\t\tRD4,  // read-byte\n\t\tCMPN, // compare\n\t\tRD4,  // addr\n\t\tSUB,  // subtract\n\t\tRET,  // return\n\t\tLUPU, // (++curr < end)... go back\n\t\tSET1, // -1\n\t\tRET,  // return -1\n\t\t0, \n    };\n*/\n\x00""AFaf09__\x00""09..\x00no_print_args true\nprefs \x22klinkerhoppen.speedie\x22\nfun_and_fashion \x22tasks_function_correctly\x22\x00xatt\x00XML_Attribute\x00xml\x00XML_Element\x00xpi\x00XML_ProcessingInstruction\x00xcom\x00XML_Comment\x00xcdt\x00XML_CDATA\x00xtxt\x00XML_Text\x00Hex\x00Wrong params passed: \x00Missing params.\x00to \x00I think you mean 'constants'\x00I think you mean 'extend'\x00static is called 'module' in speedie.\x00Modules has recursive init order\x00Syx\x00I think you mean 'beep'\?\x00'break' not allowed. Either 'exit' or 'debugger'\?\x00'do' loops not allowed. Use 'for' or 'while'.\x00\x00\x00\x00\x00\x00\x00\x00""abc \x00Too many items in C-array.\x00SyntaxAppend\x00Use \xC2\xABthg \x22name\x22\xC2\xBB syntax instead!\x00""Can\xE2\x80\x99t cast to/from structs/carrays (pointers to structs are OK though)\x00SyntaxAccessExpect\x00SyntaxAccess\x00Must be a datatype.\x00""dispatch\x00""Array index is wrong type.\x00""Array indexes mismatch.\x00Must return a value\x00*\x00""Expected an integer.\x00""Chars must be one byte long.\x00This expression can\xE2\x80\x99t be used here.\x00Not a class.\x00Should be in a list.\x00max\x00""Can\xE2\x80\x99t use a module here.\x00""Can't use modules here.\x00This expression doesn't return anything.\x00(Using this function.)\x00""Failed to get type of this.\x00""Can\xE2\x80\x99t use this as a function.\x00Too many items in vector (max 4)\x00Too few items in vector (min 2)\x00vecmix\x00ivecmix\x00message\x00is\x00isnt\x00Invalid expression.\x00""Can't use this operator here.\x00""Can't use '=' here. Did you mean '=='\?\x00""Can\xE2\x80\x99t find the type of this.\x00""Can't swizzle that many yet.\x00Vectors max out at 4 items.\x00Vector access is too large.\x00""0\x00SyntaxCall\x00""expected: (a,b)(cond)\x00""Can\xE2\x80\x99t refer to a module like that.\x00""Can\xE2\x80\x99t refer to type \xE2\x80\x9C\x00\xE2\x80\x9D like that (it's not a class).\x00roles aren't real classes!\x00KB\x00K\x00MB\x00M\x00GB\x00G\x00TB\x00th\x00s\x00ms\x00""days\x00""day\x00weeks\x00week\x00years\x00year\x00mins\x00min\x00hours\x00hour\x00Unknown unit\x00Vector type mismatch.\x00""Cant compare bools to non-bools\x00OK note warning warning error critical\x00<0.1\x00""child\x00int or float vector\?\x00sign\x00u8\x00""byte2\x00""byte3\x00""byte4\x00sbyte\x00sbyte2\x00sbyte3\x00sbyte4\x00s16x2\x00s16x3\x00s16x4\x00""double\x00u32\x00s64\x00u64\x00""f16\x00s8\x00int8\x00uint8\x00u16\x00s16\x00""atomic_int64\x00""atomic_uint64\x00""atomic_int\x00""atomic_uint\x00""atomic_byte\x00unusedtype\x00syntax.asm\x00Opcodes:\n\x00 = \x00JB_ASM_Run\x00tests\x00Mixed indexes found. (Some have ':' and some don't)\x00""Can't load constant.\x00Number out of bounds.\x00Too many labels\x00Label already used\x00No ASM for this operator\?\x00No label found\x00Label not found\x00Too many arguments\x00No free registers.\x00""ASM is out of memory.\x00Too many params\x00Too few params\x00 to \x00 (\x00) in at \x00/s (\x00s)\x00Unknown class.\x00""Bad data found.\x00This class has no loader for it.\x00``\x00This class has no saving function for it.\x00""Expected class \x00Internal Error\x00\n\t\x00\n\n// \x00 InitTable\x00_() { // Behaviour \n\t\x00 Result;\n\x00""Cant find behaviour '\x00' on class \x00Missing behaviour on class: \x00\treturn Result;\n}\n\n\x00_FuncTable_ = InitTable\x00_();\n\x00\nJBClass ( \x00 , \x00JB_Object\x00\n);\n\x00JBClassPlace4(\x00_FuncTable_);\n\n\x00""extern \x00__lib__ \x00$(N)\x00#define kSyx\x00__attribute__((__packed__)) \x00 {\x00void* __destructor__\x00\n};\n\x00SyntaxConstants.h\x00\n// Auto-generated file, by speedie.\n\x00JB_Umbrella.hpp\x00JB.h\x00\n#pragma GCC visibility push(hidden)\nextern \x22""C\x22 {\n\n\x00 JB_Object_FuncTable_;\n\x00;\n\x00JB_Globals.cpp\x00}\n\n//\x00;\n\n\x00\n\n\x00__lib__ const char* JB_LibClassInfo = \x00;\nextern \x22""C\x22 JB_String* JB_App__LibClasses() {\n\treturn JB_StrCN(JB_LibClassInfo, \x00);\n}\n\x00// entire_function_list\n\n\x00\n__lib__ void* JB_AllFuncsList[] = {\n\x00\t(void*)\x00""0};\n\x00__lib__ const char* JB_LibFuncInfo = \x00\nextern \x22""C\x22 JB_String* JB_App__LibFuncs(void*** Funcs) {\n\t* Funcs = JB_AllFuncsList;\n\treturn JB_StrCN(JB_LibFuncInfo, \x00 {\n\t\x00return \x00;\n}\n\n\x00\n#pragma GCC reset_options\n\n\x00#pragma GCC optimize (\x22O\x00\x22)\n\x00""AllTypes.h\x00Proj.h\x00Inlines.h\x00ModuleProperties.cpp\x00\n#ifndef ObjCID\n\t#define ObjCID void*\n#endif\n\x00// Globals put into a separate file to make things faster.\n#include \x22JB_Umbrella.hpp\x22\n#include \x22JB.h\x22\n#pragma GCC visibility push(hidden)\n\n\x00""API.cpp\x00\n//// API START! ////\n\n\x00#pragma GCC visibility push(default)\n\x00#pragma GCC visibility pop\n\x00//// API END! ////\n\x00h\x00//// HEADER \x00\n\n\t\t// API\n\n\nextern \x22""C\x22 {\n\n\t\t// Types\n\ntypedef const char* _cstring;\ntypedef void* _voidptr;\n#ifndef u8\n\ttypedef unsigned char  u8; \n#endif\n#ifndef byte\n\ttypedef u8  byte; \n#endif\n#ifndef int64\n\ttypedef long long  int64; \n#endif\n#ifndef uint64\n\ttypedef unsigned long long  uint64; \n#endif\n\nstruct jbobject {int RefCount;};\n\x00struct \x00 : jbobject {};\n\x00typedef \x00""Can't export this.\x00\n\n\t\t// \x00Global\x00 functions\n\n\x00 /* \x00 */\x00\n\n\t\t// Jeebox Syntax\n\n\x00#define JB_Syx\x00#define $\x00\n\n#ifdef __nodebug\n\t#undef __nodebug\n#endif\n#if defined(__linux__)\n\t#define __nodebug inline __attribute__((__always_inline__)) // __nodebug__ doesn't exist on linux\?\n#else\n\t#define __nodebug inline __attribute__((__always_inline__, __nodebug__))\n#endif\n__nodebug void jb_incr(jbobject* s) {\n\tif (s) {s->RefCount++;}\n}\n\n__nodebug void jb_decr(jbobject* s) {\n\tif (s) { if (--s->RefCount <= 0) {jb_delete_(s);} }\n}\n\n} // end-extern\n\x00\n\n // Auto-generated file, by speedie.\n\x00\n#define __SPEEDIE__ 1\n\x00\n\n#ifndef __JB_H__\n#define __JB_H__\n\nextern \x22""C\x22 {\n\n\x00\n}\n#endif // __JB_H__\n\x00""Create API-Header for API: \x00_api.h\x00""elseif\x00""else\x00\\x\x00Missing property name\x00->\x00JB_LUB[\x00JB_AsClass(\x00""exit\x00""break\x00""else if\x00swap\x00JB_Swap\x00)(\x00licence.txt\x00JB.cpp\x00 {\n\x00\tfn(&\x00""Data, (char*)\x00);\n\x00}\n\x00saver_funcs\x00void JB_InitClassList(SaverLoadClass fn)\x00SaverClassInfo\x00saverloadclass\x00JB_String* JB_LUB[\x00];\n\n\x00int JB_LUBLengths[] = {\x00""0};\n\n\x00""const char* JB_LUBSrc = \x00;\n\nextern \x22""C\x22 void JB_Str__FindGlobals(JB_String*** lub, int** lengths, const char** src) {\n\t*lub = JB_LUB;\n\t*lengths = JB_LUBLengths;\n\t*src = JB_LUBSrc;\n}\n\x00.i\x00#define \x00void\x00inline \x00\ntypedef \x00 (*\x00Should be 'disturbs' or 'disowns'\x00returnsdisowned\x00/\x00\\\?\x00\x22\x22\x00#include \x22\x00 '\x00' \x00 issue\x00 found.\n\x00Leaked \x00 bytes in \x00. New Count \x00--talk=\x00No name given.\x00""died\x00""disconnect\x00get\x00Invalid message length\x00received nil\x00Parent \x00""Child  \x00-----------\n\x00talk: \x00, name: \x00ipc is open: \x00ipc not open.\n\x00""crashed\x00""can't open ipc\x00Unaligned memory.\x00MemorySharingFailed.\x00sent something to a closed parent.\x00hasnt read previous message. Cant send new!\x00""connection died during wait\x00""closed connection\x00timed out\x00waiting...\x00WaitFor ended\x00sending\x00Message too long\x00nil,\x00(disabled)\x00index.spd\x00vert\x00""frag\x00shad\x00""Can\xE2\x80\x99t find project at: '\x00' for import: '\x00""File included twice.\x00""App\x00""bannedclasses\x00""Copying Shaders\x00Resources/Shaders\x00S: \x00\n// (Copy of original)\n\x00Multiple input folders found! '\x00' and '\x00""Can't find folder '\x00/input/'.\x00""c_includes\x00""c_postincludes\x00input\x00We can't do that yet\x00 \x19 \x00 \x0C \x00 b \x00 v \x00 f \x00 \x0E \x00 \x1B \x00 k \x00 \n \x00   \x00(<>)\x00oper\x00OperatorCompare\x00==\x00-1\x00<=\x00""1\x00>=\x00\nmod\n^ pow\n/ divide\n* multiply\n- minus\n+ plus\n<<\n>>\n>>>\n&&& &\n^^^ xor ^\n||| | (|)\nto from custom\nby\n<\n<=\n>\n>=\n==\n!=\nis isnt\nin\nand\nor\n=\x00""custom\x00~=\x00Mod\x00Plus\x00Minus\x00Mul\x00""Divide\x00""BitAnd\x00""BitOr\x00Xor\x00<<<\x00RotateLeft\x00>>>\x00RotateRight\x00>>\x00ShiftRight\x00<<\x00ShiftLeft\x00<>\x00""Can\xE2\x80\x99t find type.\x00Multiple matching functions.\x00""Candidate 1\x00""Candidate 2\x00super\x00Too many parameters\x00 (But none matched exactly. All needed a type-cast.)\x00U\x00.app/Contents/MacOS/\x00\xC2\xB5z\x00Invalid mz header\x00Oversized mz\x00/tmp/shm/\x00""C\x06\xC2\xB5z\x00Library/\x00Invalid path\x00spd\x00yes\x00.uwu\x00\x80\xBF\xC2\xF4\x00no\x00off\x00""Corrupted jbin\x00Not jbin\x00""Error decoding file: \x00""Error decoding data: \x00""asm \x00Unrecognised name: \x00\tResult.\x00__destructor__\x00void*\x00""Can't find file/folder: '\x00' in '\x00'.\x00No name specified for sub-file of directory: \x00--deep\x00--force\x00--verbose\x00-s\x00/usr/bin/codesign\x00--verify\x00-a\x00/usr/sbin/spctl\x00""Can\xE2\x80\x99t find '\x00 at \x00, trying to \x00""Batch\x00Tested: \x00--nocompile\x00This file should really not be here: \x00Path: \x00 contains a space! :(\x00 --self --nocolor --variant=\x00--variant=\x00--noisy\x00/usr/bin/touch\x00.pref\x00~/Library/Preferences\x00~\nppDataRoaming\x00~/.config\x00PRNT\x00""DDIV\x00""DMUL\x00""DSUB\x00""DADD\x00""FDIV\x00""FMUL\x00""FSUB\x00""FADD\x00MEMM\x00""CNTC\x00ST8U\x00ST4U\x00ST2U\x00ST1U\x00RD8U\x00RD4S\x00RD4U\x00RD2S\x00RD2U\x00RD1S\x00RD1U\x00RALO\x00RSET\x00RSDE\x00LUPD\x00LUPU\x00""BRAN\x00""BRA\x00""CMPN\x00""CMPE\x00""CMPF\x00""CMPI\x00""BROR\x00""BROL\x00""BFLS\x00""BFLG\x00""BNOT\x00""BXOR\x00""BOR\x00""BAND\x00SHLS\x00SHRU\x00SHRS\x00""DIV\x00MUL\x00SUB\x00""ADD\x00""ADDC\x00SETN\x00SETK\x00SET1\x00""CONV\x00RARE\x00RETL\x00LEAF\x00RET\x00""FNCX\x00""FNC\x00SWAP\x00STCK\x00HALT\x00U1\x00Swap\x00""Func\x00rn\x00j\x00U2\x00U3\x00rS\x00""Const\x00setn\x00rrnl\x00U4\x00""BFLD\x00""Cmp\x00""CmpEq\x00""Bra\x00rrj\x00rrrj\x00mem\x00Isn't a valid instruction.\x00WierdBlock\x00Iron\x00Wood\x00Pellets\x00pos: \x00 line: \x00(nil)\x00(\n\x00""fred\x00""function prototype\x00unknown\x00""Flag\x00Largest\x00""Expected 'd=(a,b,c...)' .\x00Need a name.\x00This can't be a constant.\x00\nfunction \x00 (|dictionary of \x00|)\n\tvisible false\n\tifn \x00_Dict\n\t\t\x00_Dict = dictionary.new\n\x00_Dict.Set(\x22\x00\x22, \x00\n\treturn \x00_Dict\n\x00|dictionary of \x00| \x00_Dict = nil,\x00This should go into a module or class.\x00""Can't come before super.constructor\x00Wrap this expression in a bracket before calling a function on it.\x00new\x00""Disabled here.\x00""Function must have a prototype.\x00Not assignable\x00Unexpected params on variable.\x00""Can\xE2\x80\x99t find object \xE2\x80\x9C\x00\xE2\x80\x9D.\x00""Can\xE2\x80\x99t find \xE2\x80\x9C\x00\xE2\x80\x9D on \x00 \xE2\x80\x9C\x00 (But it does exist on the class.)\x00""Can\xE2\x80\x99t find function \xE2\x80\x9C\x00    via: \x00 (visible func)\x00""Can't rehome a std lib function. Use cpp_part to give a unique name.\x00""Can\xE2\x80\x99t use '...' here, no contained type found.\x00""Can only use this in a class.\x00""Export-name conflict: \x00This type isn't allowed for a constant.\x00""Empty name.\x00Name is too long.\x00Multiple setters found.\x00""Can't use 'self' here.\x00 (,\x00)\n\tpragma inline\n\t|| Table = .ClassBehaviours|&\x00|\n\treturn (Table.\x00)(...)\n\x00++\x00Interface has no name.\x00Interfaces can\xE2\x80\x99t start or end with underscore.\x00""Bad name.\x00roles can't specify behaviours (they aren't real classes!)\x00""Behaviours can\xE2\x80\x99t specify parameters\x00""Constructors can\xE2\x80\x99t return things.\x00""Can\xE2\x80\x99t have multiple destructors\x00""Destructor can\xE2\x80\x99t have a return type or parameters.\x00\n\tfunction Alloc (|\x00|)\n\t\treturn JB_New(__classes__.\x00)|\x00|\n\t\x00\n\tfunction LayerAlloc (|MemoryLayer| _L, |\x00|)\n\t\tvisible false\n\t\treturn JB_LayerNew(_L, __classes__.\x00""Constructor\x00""ConstructorAuto\x00sooper\x00__rz__\x00Invalid name.\x00""Banned class reached: \x00_Behaviour\x00""Class hierarchy too deep\x00syntaxequals\x00syntaxcompare\x00Wrapper classes must have a constructor that is a wrapper function.\x00Role's super lacks a constructor.\x00""function \x00 { cpp_part \x00 }\x00Need properties for a Game3D Type.\x00_AllocDraw\x00No saving behaviour \x00 was found for this saveable class.\x00No parameters found\x00' keyword only usable with functions.\x00GameFlyingMem\x00""DefaultIterator\x00No iterator \x00 for class: \x00No interface found for this behaviour\x00union\x00noauto\x00NoEarlyFree\x00TreatAsBaseType\x00opt\x00""Class acts can't have properties!\x00""Class properties can\xE2\x80\x99t have default values.\x00""fail\x00""canskip\x00""Datatypes can only subclass datatypes.\x00Structs can only subclass structs.\x00""Classes can only subclass classes.\x00SyntaxCast\x00No params allowed.\x00Need a return type.\x00SyntaxIs\x00""Error in ProcessInterface.\x00 struct\x00 numeric\x00 prototype\x00 datatype\x00 model\x00Save\x00""behaviour \x00 (|&ObjectSaver| Saver)\x00 (|&ObjectLoader| Loader)\x00visible\n\x00\tsuper.\x00saver\x00loader\x00\n}\x00""Datatypes can\xE2\x80\x99t have properties.\x00\n\t\tfunction \x00 (|\x00|)\n\t\t\treturn .\x00]\n\t\tfunction \x00 (assigns:|\x00|)\n\t\t\t.\x00] = value\n\t\t\x00Need space between bracket and name.\x00""function New () {\n\t|| __rz__ = alloc()|type|\n\tif __rz__|bool|\n\t\t__rz__.Constructor()\n\treturn __rz__\n}\x00""function New (|MemoryLayer| _L) {\n\tvisible false\n\t|| __rz__ = LayerAlloc(_L)|type|\n\tif __rz__|bool|\n\t\t__rz__.Constructor()\n\treturn __rz__\n}\x00""function NewWithLayer (|MemoryLayer| _L) {\n\tvisible false\n\tcpp_part NewWithLayer\n\t|| __rz__ = LayerAlloc(_L)|type|\n\tif __rz__|bool|\n\t\t__rz__.Constructor()\n\treturn __rz__\n}\x00""Can't find class name.\x00Too few fields specified\x00kCount\x00""Can't have properties in class acts.\x00Not assignable.\x00Loses numeric info.\x00:)\x00Type mismatch, expected '\x00' but found '\x00You can\xE2\x80\x99t modify 'self'.\x00""Can\xE2\x80\x99t be a pointer\x00SC_GameTypes.box doesn't contain type '\x00No class found.\x00""Datatype-wrappers can't contain objects.\x00""Datatype-wrappers can't contain this.\x00Not a container class.\x00This doesn't contain objects.\x00""Can't store this type as an object (in this version of speedie).\x00""const char $(N)_Init[] = {\x00""0 };\n\x00GameFlyingMem $(N) = {.InitData=(u8*)$(N)_Init, .InitDataLength=sizeof($(N)_Init)}\x00""Can\xE2\x80\x99t do bit ops on this\x00""Can\xE2\x80\x99t do bit ops on floats\x00tag\x00(nil!)\x00 of \x00""Can\xE2\x80\x99t save \x00Insecure word found\x00Need call to superclass's constructor, but can\xE2\x80\x99t auto-create one.\x00No name found\x00""Can't use a swizzle-name (xyzw/rgba) on a vector-type!\x00Need to specify a return value\x00""Can\xE2\x80\x99t return multiple values\x00This function has no return value.\x00""Can\xE2\x80\x99t find return type.\x00""Function should belong to parent class, but doesn't.\x00Multiple calls to parent constructor/destructor not allowed.\x00This isn't a prototype!\x00""Expected function parameters here.\x00Receiver must be same class as first param in function prototype.\x00Multiple casts found [1]\x00Multiple casts found [2]\x00Hider\x00Set\x00""Don't use self before the constructor is complete.\x00""Can\xE2\x80\x99t read object properties during a constructor.\x00""Can\xE2\x80\x99t set object properties during a destructor.\x00""Can\xE2\x80\x99t set object property twice during a constructor.\x00Object property set must be at the root. (not nested).\x00""for (i in \x00) {\n\x00raw\x00.SaveWrite(saver)\x00[i]\x00saver.Append\x00(&\x00)|&byte|, \x00loader.LoadRaw((&.\x00.LoadProperties(loader)\x00loader.\x00\n}\n\x00""cpp_\x00require\x00""expect\x00""continue_with_error\x00want\x00loop\x00""debug_require\x00""continue\x00Must be one of '#require, #expect, #continue, #debug_require, #continue_with_error, #error, #loop' .\x00Use brackets here, like this: \xE2\x80\x9C(\x00) #\x00""expected\x00#expected is deprecated: \x00NoRefCounts\x00""DontDestructLocally\x00This missing-function:\x00""doesn't match this incoming function.\x00Some params not used.\x00""For this macro.\x00Multiple macros match\?\x00_LayerNew\x00_New\x00With\x00using\x00timetest\x00Time\x00""disabled\x00""Called a disabled function.\x00This func needs some code.\x00Wrap\x00JB_Object_Isa\x00JB_Object_MustBe\x00JB_Object_FastIsa\x00operatorfast_isa\x00""Already got one of these.\x00JB_FS_AppendString\x00JB_FS_GetResult\x00""File does not exist\x00""for\x00""description\x00once\x00ifn\x00""deprecate\x00""debugat\x00""doat\x00printline\x00zalgoline\x00printerror\x00""beep\x00quit\x00""continue_with\x00""alert\x00""do\x00\n\t|| fs = FastString.New(fs_in)\n\tfinish\n\treturn fs.GetResult(fs_in)\n\x00\n\t|FastString| fs_in = nil\n\t|string|\n\x00""finish\x00""Can\xE2\x80\x99t use this\x00""Can\xE2\x80\x99t have main inside here.\x00""function app.Main (|int|) {cpp_name JB_Main, visible true}\x00""Expected an argument\x00""Destructor\x00No function name found.\x00Missing functions must be one line!\x00Missing functions don't directly state arguments.\x00""Function prototypes must be in a module.\x00Must go in a class\x00JB_Str3\x00""digest\x00""fs\x00_str\x00""FastString\x00Strings with expressions, must be in proper functions. (Compiler limitation)\x00getresult\x00tmP\x00Unrecognised operator.\x00next\x00prev\x00Invalid codepoint\x00""codepoint\x00SyntaxDeprecate\x00""Can\xE2\x80\x99t have multiple descriptions.\x00""DebugAt\x00Must be within a loop.\x00start\x00No index found for the iterator for this loop.\x00in\x00LoopSrc\x00""empty loop\x00""Fn_\x00Should be like (\x22""a\x22, \x22""b\x22) : code\x00Item needs to be like: 'name {code}'.\x00""Can\xE2\x80\x99t have this at the argument root!\x00""Can\xE2\x80\x99t use 'else if', use 'elseif' instead.\x00""Expected {argument} here.\x00platform\x00""Can't use this here.\x00Value expected here.\x00Render\x00rz\x00You can\xE2\x80\x99t return in a constructor or destructor\x00__SELF_TEST_NATURAL__\x00Just swap two items.\x00""fpMsgRender\x00Name too long (max=4)\x00StdNew\x00Message\x00Unrecognised statement\x00SyntaxUsing\x00SyntaxUsingComplete\x00This is not a real class. Test it's super-class instead.\x00iterator iter_test () {for yield_test\x00 in self {(yield_test)}}\x00missing while\x00missing argument for 'while'\x00yield\x00Missing yield statement.\x00iterator\t// eyyy mammi, i aint doin this\n\t|| first = &self[0]\n\t|| i = 0\n\twhile (i <  \xE2\x80\x93""count self)\n\t\tyield first[i] (i)\n\t\ti++\x00iterator\n\t|| curr = self\n\twhile self[0]\n\t\tyield self[0] (self)\n\t\tself++\x00// \x00Init_\x00InitCode_\x00k\x00""function Dispose () { visible false }\x00 (|int|)\x00module of \x00""Expected @\x00 but found @\x00Missing \x00Missing syntax\x00 ~ \x00""function app.Main (|int|)\x00""d\x00 \xE2\x89\x88 \x00Unused parameter to macro\x00>~ \x00Rel missing right side.\x00""Can't get address of vector element (c++ limitation).\x00""Can't get address of this.\x00""Can't get the address of a const.\x00""Can't typecast a struct!\x00""First statement must be call to super.\x00\xA0\x00Node contains option-space\x00\?\x00Use !=\x00~<>\x00Use ~!=\x00~!=\x00<~\x00~>\x00SyntaxSendTo\x00targets\x00""functiontable\x00with\x00""direct_test_only\x00= \x00, but found \x00""Expected integer\x00Please simplify this expression\x00Put this inside a 'Linkage' tag.\x00""Bad model type.\x00.frag\x00.vert\x00:=\x00""Float64 got clipped in a float32\x00^\x22\x00Indented blocks must be within @tmp or @item or @decl\x00Invalid unit\x00_imP\x00: '\x00 at byte: \x00 in \x00Not enough params.\x00""alpha\x00nodepth\x00 \xC2\xBB\x00 @ \x00 doesn\xE2\x80\x98t have 'syntax is' specified.\x00This func needs a parameter!\x00syntaxisnt\x00syntaxis\x00oar\x00jinit\x00init\x00""Expected a name\x00""function New (|&\x00|) {\n\t\treturn Game_FlyingAlloc(_AllocDraw)|&\x00|}\x00 <\xE2\x89\x88 \x00Indents mismatch (\x00 spaces)\x00 \xE2\x80\x9D\x00""Expected register between r0 and r31\x00""count\x00This is not a c-array\x00sizeof\x00 /# \x00 #/\x00 not found.\x00release\x00minilib\x00lnx\x00Test \x00: Failed\n\n\x00""Doesn't follow 'function name (|Type| Name)'\x00+\x22\x00Should look like a.b\?  or  .b\?  or  (a)(b)\?  or  a.b \?= c  or  (a) \?= b\x00_INSID\x00it\x00This value should be 'true' or 'false'.\x00Unit should be \x00newfloat\x00=\x22\x00/>\x00</\x00\xC2\xAC \x00""Can\xE2\x80\x99t find syntax: \x00SCArg: (\n\x00pos\x00(string)\x00 in:\n\x00""Can\xE2\x80\x99t parse number '\x00' (found '\x00').\x00\x1B[0;1m\x00\x1B[0;1;31m\x00\x1B[0;1;32m\x00\x1B[0m\x00\x1B[0;1;33m\x00^\x00@JBSave\n\x00";

extern "C" void JB_Str__FindGlobals(JB_String*** lub, int** lengths, const char** src) {
	*lub = JB_LUB;
	*lengths = JB_LUBLengths;
	*src = JB_LUBSrc;
}
