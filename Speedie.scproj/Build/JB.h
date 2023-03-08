

 // Auto-generated file, by speedie.

/* jeebox-licence:
    By Theodore H. Smith, 2019, theo@jeebox.org
	
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

#define __SPEEDIE__ 1


#ifndef __JB_H__
#define __JB_H__

extern "C" {

//// HEADER AllTypes.h

#ifndef ObjCID
	#define ObjCID void*
#endif

typedef byte ErrorFlags;

typedef byte ErrorSeverity;

typedef byte MaybeBool;

typedef int PID_Int;

typedef int SCBaseInfo;

typedef int SCBaseType;

typedef int SizeInt;

typedef byte Syntax;

typedef int TerminalColor;

typedef u16 ASMParam;

typedef uint64 __junktest_7__;

typedef uint Codepoint;

typedef ivec2 ControlLine;

typedef int ControlPoint;

typedef ivec4 ControlRect;

typedef u16 DataTypeCode;

typedef int64 Date;

typedef int ErrorInt;

typedef int FileMode;

typedef int Ind;

typedef ivec2 IntRange;

typedef u16 IPCState;

typedef uint JSM;

typedef u16 MsgUIFlags;

typedef uint SCDeclInfo;

typedef uint U24_8;

typedef JSM ASM;

typedef ASM ASM_BFLD;

typedef ASM ASM_Bra;

typedef ASM ASM_Cmp;

typedef ASM ASM_CmpEq;

typedef ASM ASM_CNTC;

typedef ASM ASM_CNTR;

typedef ASM ASM_Const;

typedef ASM ASM_Func;

typedef ASM ASM_Mem;

typedef ASM ASM_Setn;

typedef ASM ASM_SWAP;

typedef ASM ASM_U0;

typedef ASM ASM_U1;

typedef ASM ASM_U2;

typedef ASM ASM_U3;

typedef ASM ASM_U4;

struct ArgArrayCounter;

struct asdas;

struct asdas2;

struct ASMFuncState;

struct AsmReg;

struct ASMVarType;

struct CompressionStats;

struct FloatRange;

struct IntDownRange;

struct IPCMessage;

struct IR;

struct MessagePosition;

struct ModelTest;

struct NameAndMsg;

struct ObjectLoader;

struct ObjectSaver;

struct ParserLineAndIndent;

struct Random;

struct RetroFloat;

struct RingDownRange;

struct RingRange;

struct SpeedTester;

struct StringLengthSplit;

struct StructSaveTest;

struct uint24;

struct Object_Behaviour;

struct MemoryLayer_Behaviour;

struct SyntaxObj_Behaviour;

struct Macro_Behaviour;

struct StringShared_Behaviour;

struct SCObject_Behaviour;

struct SCDecl_Behaviour;

struct CppRefs_Behaviour;

struct autoitem_Behaviour;

struct SCParamArray_Behaviour;

struct SCIterator_Behaviour;

struct Cpp_Export_Behaviour;

struct SCImport_Behaviour;

struct __junktest_6___Behaviour;

struct xC2xB5Func_Behaviour;

struct SCOperator_Behaviour;

struct xC2xB5Form_Behaviour;

struct SCNodeRenamer_Behaviour;

struct LeakTester_Behaviour;

struct StringFields_Behaviour;

struct Selector_Behaviour;

struct FastString_Behaviour;

struct ShellStream_Behaviour;

struct DictionaryReader_Behaviour;

struct Object_Behaviour;

struct TokenHandler_Behaviour;

struct Charset_Behaviour;

struct StringStream_Behaviour;

struct Saveable_Behaviour;

struct ErrorList_Behaviour;

struct ByteMap_Behaviour;

struct Process_Behaviour;

struct DataTypeWrapper_Behaviour;

struct Memory_Behaviour;

struct RingTree_Behaviour;

struct FixedDict_Behaviour;

struct String_Behaviour;

struct StringZeroTerminated_Behaviour;

struct FastString_Behaviour;

struct Message_Behaviour;

struct SCBase_Behaviour;

struct GUIControl_Behaviour;

struct TreeView_Behaviour;

struct GUIControl_Behaviour;

struct Message_Behaviour;

struct Message_Behaviour;

struct SCModule_Behaviour;

struct SCClass_Behaviour;

struct SCArg_Behaviour;

struct SCFunction_Behaviour;

struct SavingTest_Behaviour;

struct MaterialsLol_Behaviour;

struct SCBehaviour_Behaviour;

struct FastStringCpp_Behaviour;

struct xC2xB5Func1_Behaviour;

struct Instruction_Behaviour;

struct File_Behaviour;

struct String_Behaviour;

struct Array_Behaviour;

struct String_Behaviour;

struct Message_Behaviour;

struct Dictionary_Behaviour;

struct Error_Behaviour;

struct SaverClassInfo_Behaviour;

struct Message_Behaviour;

struct Message_Behaviour;

struct SCFile_Behaviour;

struct __junktest_6__;

struct autoitem;

struct Cpp_Export;

struct CppRefs;

struct DTWrap;

struct JB_ErrorReceiver;

struct FixedDict;

struct LeakTester;

struct Macro;

struct MWrap;

struct Process;

struct SCImport;

struct SCNodeRenamer;

struct SCObject;

struct SCOperator;

struct SCParamArray;

struct Selector;

struct JB_Object;

struct StringFields;

struct StringStream;

struct SyntaxObj;

struct xC2xB5Form;

struct ASMFunc;

struct FastStringCpp;

struct Instruction;

struct FastString;

struct MaterialsLol;

struct SaverClassInfo;

struct SavingTest;

struct SCBase;

struct SCBehaviour;

struct SCClass;

struct SCDecl;

struct SCFile;

struct SCFunction;

struct SCIterator;

struct SCModule;

struct JB_String;

struct JB_String;

struct ASMFunc2;

struct GUIControl;

struct Message;

struct Message;

struct SCArg;

struct GUIControl;

struct TreeView;

struct Message;

struct Message;

struct JB_Error;

struct Message;

struct Message;

typedef ASM (*ASM_Encoder2)(IR* self);

typedef bool (*autosort_fn)(autoitem* a, autoitem* b);

typedef SCBase* (*CollectFunc)(Message* node, SCBase* name_space, Message* ErrPlace);

typedef SCObject* (*ExprResolver)(Message* Exp, SCBase* name_space, Message* side);

typedef AsmReg (*fn_asm)(ASMFuncState* self, Message* exp, AsmReg Reg);

typedef AsmReg (*fn_OpASM)(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

typedef ErrorInt (*fn_subprocess)(_cstring* args, int Mode);

typedef void (*fnErrorLogger)(JB_ErrorReceiver* self, JB_String* Data);

typedef void (*fpDestructor)(JB_Object* self);

typedef void (*fpMsgRender)(Message* self, FastString* fs);

typedef void (*fpMsgRenderCpp)(Message* self, FastStringCpp* fs);

typedef Message* (*ParseHandler)(int Start, Message* Parent);

typedef void (*SaverLoadClass)(JB_Class* cls, char* Data);

typedef bool (*ShellOption)(JB_String* Name, JB_String* Value, FastString* purpose);

typedef bool (*SorterComparer)(JB_Object* a, JB_Object* b);

typedef JB_Object* (*TokenHandler_fp)(int Start, Message* parent);

typedef void (*TranFunc)(SCFunction* fn, Message* node, SCBase* name_space);

typedef void (*__Saveable_LoadProperties__)(Saveable* self, ObjectLoader* Loader);

typedef void (*__Saveable_SaveCollect__)(Saveable* self, ObjectSaver* Saver);

typedef void (*__Saveable_SaveWrite__)(Saveable* self, ObjectSaver* Saver);

typedef JB_String* (*__Object_Render__)(JB_Object* self, FastString* fs_in);

typedef JB_String* (*__Message_copyid__)(Message* self);

typedef JB_String* (*__Message_text__)(Message* self, int i);

typedef bool (*__Message_textset__)(Message* self, int i, JB_String* v);

//// HEADER Proj.h

struct ArgArrayCounter {
	int i;
	int max;
	bool IsItem;
	bool IsNotItem;
};

struct asdas {
	int aaabbb;
};

struct asdas2 {
	asdas www;
};

struct ASMFuncState {
	SCFunction* fn;
	ASMFunc* Out;
	IR* Start;
	int Written;
	uint MaxLength;
	bool OK;
	byte LabelCount;
	uint64 UsedRegs;
	uint64 TrueBits[32];
	uint64 FalseBits[32];
	uint AnyTrue;
};

struct AsmReg {
	DataTypeCode AType;
	byte Reg;
};

struct CompressionStats {
	Date Duration;
	int In;
	int LastOut;
	int Out;
	bool Live;
};

struct IPCMessage {
	uint DataLength;
	uint SendID;
	uint ReadID;
	IPCState State;
	byte Queued;
	byte Special;
};

struct IR {
	byte Op;
	byte Label;
	byte Nothing[2];
	byte r[4];
	int Rest;
	uint Debug;
};

struct MessagePosition {
	int OldPosition;
	uint OldLength;
	uint OldTag;
	JB_MemoryLayer* OldLayer;
};

struct NameAndMsg {
	Message* Msg;
	JB_String* Name;
	Message* Arg;
};

struct ObjectLoader {
	Dictionary* Dict;
	Message* CurrItem;
	JB_Object* CouldntLoad;
	Saveable* Result;
	Message* DataError;
	Message* NoClass;
};

struct ObjectSaver {
	FastString* Dest;
	JB_Object* CantSaveThis;
	JB_Object* Root;
};

struct ParserLineAndIndent {
	int Lines;
	int Indent;
	int Commas;
	int Pos;
	bool IsDebug;
};

struct Random {
	uint64 Store;
	uint64 State;
};

struct StructSaveTest {
	Saveable* Sav;
	int64 Intt;
	JB_String* Str;
};

struct Object_Behaviour {
	void* __destructor__;
	__Object_Render__ render;
};

struct autoitem_Behaviour: Object_Behaviour {
};

JBClass ( autoitem , JB_Object , 
	JB_String* Sort;
	JB_String* Insert;
	SCObject* Value;
	JB_String* Display;
	bool Exact;
	int type;
);

struct Charset_Behaviour: Object_Behaviour {
};

struct Cpp_Export_Behaviour: Object_Behaviour {
};

JBClass ( Cpp_Export , JB_Object , 
	FastStringCpp* T;
	Array* Outputs_cpp;
	Array* Outputs_h;
	FastStringCpp* Inlines;
	FastStringCpp* TypesProj;
	FastStringCpp* HeaderProj;
	FastStringCpp* AllTypes;
	FastStringCpp* ModuleProperties;
);

struct CppRefs_Behaviour: Object_Behaviour {
};

JBClass ( CppRefs , JB_Object , 
	u16 DisturbParams;
	bool Owned;
	Array* Disturbs;
);

struct DataTypeWrapper_Behaviour: Object_Behaviour {
};

JBClass ( DTWrap , JB_Object , 
	DataTypeCode DataType;
	byte DeathAction;
	int64 PrivValue;
);

struct DictionaryReader_Behaviour: Object_Behaviour {
};

struct ErrorList_Behaviour: Object_Behaviour {
};

JBClass ( JB_ErrorReceiver , JB_Object , 
	JB_Error* Errors;
	fnErrorLogger LogFunc;
	int MaxErrors;
	int ErrorCount;
	int ProblemCount;
	int WarnCount;
	int ErrorsAreWarnings;
	bool BlockErrors;
	JB_String* Source;
	JB_Object* LogObj;
);

struct FastString_Behaviour: Object_Behaviour {
};

struct LeakTester_Behaviour: Object_Behaviour {
};

JBClass ( LeakTester , JB_Object , 
	int MemUsedStart;
	JB_String* Name;
);

struct Macro_Behaviour: Object_Behaviour {
};

JBClass ( Macro , JB_Object , 
	bool Cleaned;
	JB_String* input;
	Message* Parsed;
);

struct Memory_Behaviour: Object_Behaviour {
};

JBClass ( MWrap , JB_Object , 
	int Capacity;
	byte* _Ptr;
	int Length;
	u16 ItemSize;
	DataTypeCode DataType;
	byte DeathAction;
);

struct MemoryLayer_Behaviour: Object_Behaviour {
};

struct Process_Behaviour: Object_Behaviour {
};

JBClass ( Process , JB_Object , 
	JB_File* Talker;
	FastString* Writer;
	JB_String* Name;
	JB_String* Path;
	byte* Orig;
	IPCMessage* Ours;
	IPCMessage* Theirs;
	Date LastSend;
	fn_subprocess SubProcess;
	Array* Params;
	JB_File* LogFile;
	JB_File* _StdOutFile;
	FastString* _StdOut;
	RingTree* SendQueue;
	Ind ProcPos;
	IPCMessage Dummy;
	int OrigSize;
	int Offset;
	int DeathLimit;
	int DiedCount;
	int CID;
	bool IsServer;
	bool TrapStdOut;
	byte CanPrint;
);

struct Saveable_Behaviour: Object_Behaviour {
	__Saveable_LoadProperties__ loadproperties;
	__Saveable_SaveCollect__ savecollect;
	__Saveable_SaveWrite__ savewrite;
};

struct SCImport_Behaviour: Object_Behaviour {
};

JBClass ( SCImport , JB_Object , 
	bool IsSTDLib;
	int Depth;
	Array* Files;
	JB_File* InputFolder;
	JB_File* Proj;
	JB_MemoryLayer* DeclLayer;
	SCModule* Mod;
	Dictionary* Resources;
);

struct SCNodeRenamer_Behaviour: Object_Behaviour {
};

JBClass ( SCNodeRenamer , JB_Object , 
	JB_String* Name;
	Array* nodes;
);

struct SCObject_Behaviour: Object_Behaviour {
};

JBClass ( SCObject , JB_Object , 
	Dictionary* LinkFrom;
	JB_String* Name;
	Message* Source;
	u16 TableId;
	byte NoAutoComplete;
);

struct SCOperator_Behaviour: Object_Behaviour {
};

JBClass ( SCOperator , JB_Object , 
	int Score;
	JB_String* Name;
	JB_String* CompOp;
	JB_String* CompParam;
	JB_String* FuncName;
	fn_OpASM ASM;
	bool IsCaseAware;
	bool IsCompare;
	bool IsEquals;
	bool IsSet;
	bool AsBit;
	bool IsCustom;
	bool DoesntNeedExtraBits;
	bool MakesSigned;
	bool IsBoolable;
);

struct SCParamArray_Behaviour: Object_Behaviour {
};

JBClass ( SCParamArray , JB_Object , 
	Message* Items[11];
	Message* Exp;
	s16 Size;
	s16 ErrCount;
	bool IsAssigns;
	bool HasProperParams;
	bool IsDot;
	bool IsAddress;
	bool IsForClass;
	bool IsSelf;
	bool IsSuper;
	bool Found;
);

struct Selector_Behaviour: Object_Behaviour {
};

JBClass ( Selector , JB_Object , 
	int ID;
	JB_String* Name;
	Selector* Next;
);

struct String_Behaviour: Object_Behaviour {
};

struct StringFields_Behaviour: Object_Behaviour {
};

JBClass ( StringFields , JB_Object , 
	JB_String* Data;
	byte Sep;
);

struct StringStream_Behaviour: Object_Behaviour {
};

JBClass ( StringStream , JB_Object , 
	JB_String* Data;
	JB_String* FilePath;
	int Position;
	int Length;
	int ChunkSize;
);

struct SyntaxObj_Behaviour: Object_Behaviour {
};

JBClass ( SyntaxObj , JB_Object , 
	fpMsgRender RenderAddr;
	fpMsgRender ExportAddr;
	JB_String* Name;
	JB_String* LongName;
	Syntax ID;
);

struct TokenHandler_Behaviour: Object_Behaviour {
};

struct xC2xB5Form_Behaviour: Object_Behaviour {
};

JBClass ( xC2xB5Form , JB_Object , 
	JB_String* Name;
	ASMParam Params[8];
	int Count;
	int Index;
	bool Varies;
);

struct xC2xB5Func_Behaviour: Object_Behaviour {
};

JBClass ( ASMFunc , JB_Object , 
	SCFunction* Fn;
	int Start;
	int Length;
	bool OK;
);

struct Array_Behaviour: Saveable_Behaviour {
};

struct Dictionary_Behaviour: Saveable_Behaviour {
};

struct FastStringCpp_Behaviour: FastString_Behaviour {
};

JBClass ( FastStringCpp , FastString , 
	Message* ExtraAfter;
	SCFile* OrigFile;
	JB_String* OrigSrc;
	JB_String* Cpp_Name;
	Message* SrcEnd;
	SCFunction* CurrFunc;
	uint LastLine;
	uint LastPos;
);

struct File_Behaviour: String_Behaviour {
};

struct Instruction_Behaviour: Selector_Behaviour {
};

JBClass ( Instruction , Selector , 
	byte OpLength;
	byte aType;
	byte PCount;
	xC2xB5Form* Sizes;
	JB_String* FormName;
);

struct MaterialsLol_Behaviour: Selector_Behaviour {
};

JBClass ( MaterialsLol , Selector , 
	JB_String* oof;
);

struct RingTree_Behaviour: Saveable_Behaviour {
};

struct SaverClassInfo_Behaviour: Array_Behaviour {
};

JBClass ( SaverClassInfo , Array , 
	JB_Class* Cls;
	SaverClassInfo* NextInfo;
	char* Data;
);

struct SavingTest_Behaviour: Saveable_Behaviour {
};

JBClass ( SavingTest , Saveable , 
	JB_String* Name;
	int Value;
	int ABC[1];
);

struct SCBase_Behaviour: SCObject_Behaviour {
};

JBClass ( SCBase , SCObject , 
	SCBaseInfo BaseInfo;
	Dictionary* Access;
	JB_String* ExportName;
	SCBase* Lookup;
	SCBase* CurrReacher;
	SCImport* Project;
);

struct SCBehaviour_Behaviour: SCBase_Behaviour {
};

JBClass ( SCBehaviour , SCBase , 
	SCModule* FuncTayble;
	Dictionary* Interfaces;
	Array* WrapperFuncs;
);

struct SCClass_Behaviour: SCBase_Behaviour {
};

JBClass ( SCClass , SCBase , 
	SCClass* Super;
	Message* Defawlt;
	Message* SourceClass;
	SCModule* Modul;
	Array* Properties;
	SCDecl* TypeNormal;
	Array* Casts;
	Array* Children;
	SCDecl* Contained;
	SCDecl* Signed;
	SCDecl* NotConstUwU;
	SCFunction* FuncProto;
	SCFunction* TheIsFunc;
	SCFunction* ConstructorFunc;
	SCFunction* DestructorFunc;
	JB_String* CppClass;
	SCDecl* ClassType;
	SCDecl* SelfStrong;
	Message* IsModel;
	SCBehaviour* Behaviour;
	JB_String* SaveAs;
	SCClass* ProcessAs;
	SCDecl* DataTypeWrapper;
	u16 Size;
	DataTypeCode TypeInfo;
	bool HasCompareFunc;
	bool HasEqualsFunc;
	bool IsRole;
	byte IsBehaviour;
	byte Depth;
	byte MinOpt;
	bool IsBuiltin;
	bool IsDataTypeLike;
	bool IsStruct;
	bool IsDataType;
	byte IsWrapper;
	bool HasSubClass;
	bool NoEarlyFree;
	bool AutoGeneratedSavers;
	bool SavingCanSkip;
	bool TreatAsBaseType;
	bool IsNotNumeric;
	bool Banned;
);

struct SCDecl_Behaviour: SCObject_Behaviour {
};

JBClass ( SCDecl , SCObject , 
	byte PointerCount;
	byte AllocSource;
	byte Strength;
	SCFunction* Setter;
	JB_Object* IsLookupOnly;
	JB_String* StringData;
	SCDecl* AutoCastTo;
	SCDecl* Contains;
	Message* Default;
	SCClass* Type;
	int C_Array;
	SCDeclInfo Info;
	AsmReg DRegister;
);

struct SCFile_Behaviour: File_Behaviour {
};

JBClass ( SCFile , JB_File , 
	JB_String* ExportName;
	SCImport* Proj;
	JB_String* FData;
	Message* LiveAST;
	Message* OrigAST;
	Date OrigDate;
	int filenum;
	bool IsInternal;
);

struct SCFunction_Behaviour: SCBase_Behaviour {
};

JBClass ( SCFunction , SCBase , 
	Array* Args;
	SCClass* Cls;
	JB_String* Disabled;
	CppRefs* Refs;
	Dictionary* LinkTo;
	JB_Object* CounterPart;
	SCFunction* NextFunc;
	ASMFunc* ASM;
	SCDecl* ProtoDecl;
	SCClass* ProtoType;
	SCDecl* ReturnType;
	JB_String* Description;
	u16 TmpCounter;
	u16 AllocCode;
	byte MinOpt;
	byte IsAssigns;
	byte IsCppInBuilt;
	bool IsInline;
	bool IsExternalLib;
	bool IsWrapper;
	bool NoRefCounts;
	bool IsAPI;
	bool AutoGeneratedSaver;
	bool IsMacro;
	bool ExternalOnly;
);

struct SCIterator_Behaviour: SCObject_Behaviour {
};

JBClass ( SCIterator , SCObject , 
	Array* Names;
	SCNodeRenamer* selfs;
	SCNodeRenamer* ValueRenamer;
	Message* Index;
	Message* LoopCond;
	Message* LoopEndCond;
	Message* Value;
	Message* WhileLoop;
	Message* Yield;
	SCClass* parent;
);

struct SCModule_Behaviour: SCBase_Behaviour {
};

JBClass ( SCModule , SCBase , 
	SCClass* Cls;
	Message* InitVarsArg;
	Message* InitCodeArg;
	JB_String* CppPart;
	SCFunction* DisposeFunc;
	CppRefs* DefaultRefs;
	Message* InitAfter;
	JB_String* SubsFrom;
	bool Grabbed;
	bool IsImport;
	bool Inited;
	bool IsRequiredInterface;
);

struct StringZeroTerminated_Behaviour: String_Behaviour {
};

struct xC2xB5Func1_Behaviour: Memory_Behaviour {
};

JBClass ( ASMFunc2 , MWrap , 
);

struct GUIControl_Behaviour: RingTree_Behaviour {
};

JBClass ( GUIControl , RingTree , 
	int xyz;
);

struct Message_Behaviour: RingTree_Behaviour {
	__Message_copyid__ copyid;
	__Message_text__ text;
	__Message_textset__ textset;
};

JBClass ( Message , RingTree , 
	JB_String* Name;
	JB_Object* Obj;
	Syntax Func;
	byte Indent;
	MsgUIFlags Flags;
	u16 RangeLength;
	u16 Tag;
);

struct SCArg_Behaviour: SCBase_Behaviour {
};

JBClass ( SCArg , SCBase , 
	SCFunction* ParentFunc;
	Message* TmpMovedOutFor;
	bool IsClassArg;
	bool IsStatementExpr;
);

struct Error_Behaviour: Message_Behaviour {
};

JBClass ( JB_Error , Message , 
	JB_String* Path;
	JB_String* OriginalData;
	JB_String* StackTrace;
	Message* Node;
	Date When;
	ErrorSeverity Severity;
	ErrorFlags ErrorFlags;
);
#define kSC____junktest_5___a (0)
#define kSC____junktest_5___b (1)
#define kSC____junktest_5___c (2)
extern int SC____junktest_5___x[3];
extern JB_String* JB__App__CLN;
extern Message* JB__App__Conf;
extern JB_String* JB__App__Path;
extern JB_String* JB__App_codesign_native;
extern Array* JB__App_OldArgs;
extern Message* JB__App_Prefs;
extern bool JB__App_Unregistered;
#define kSC__ASMtmp_iDebugger (63)
#define kSC__ASMtmp_iIf (62)
#define kSC__ASMtmp_iRejoin (61)
#define kSC__ASMtmp_iReturn (60)
#define kSC__ASMtmp_iSwap (58)
#define kSC__ASMtmp_iWhile (59)
extern JB_File* SC__Comp__BuildFolder;
extern JB_String* SC__Comp__Projects;
extern JB_String* SC__Comp__SpeedieProj;
extern Dictionary* SC__Comp_AdjDicts;
extern Array* SC__Comp_API_Funcs;
extern Array* SC__Comp_API_List;
extern Message* SC__Comp_API_Place;
extern JB_File* SC__Comp_BaseProjectPath;
extern Array* SC__Comp_ClassList;
extern SCFunction* SC__Comp_ClassListInitFunc;
extern Message* SC__Comp_ConfMsg;
extern int SC__Comp_CurrStage;
extern Message* SC__Comp_DebugInsert;
extern SCModule* SC__Comp_DisamClasses;
extern SCModule* SC__Comp_DisamModules;
extern Dictionary* SC__Comp_ExportNames;
extern Message* SC__Comp_Extend_list;
extern Array* SC__Comp_Extend_module_list;
extern Dictionary* SC__Comp_Files;
extern Array* SC__Comp_FuncList;
extern bool SC__Comp_HasMainFunc;
extern Array* SC__Comp_ImportedList;
extern Dictionary* SC__Comp_ImportedNames;
extern Dictionary* SC__Comp_InsecureWords;
extern SCFile* SC__Comp_InternalFile;
extern SCBase* SC__Comp_Interpreter;
#define kSC__Comp_TimeWidth (19)
extern Date SC__Comp_LastTime;
extern JB_String* SC__Comp_LastTimeName;
extern Array* SC__Comp_ModuleList;
extern JB_String* SC__Comp_OriginalInputPath;
extern SCFunction* SC__Comp_PrivateProperty;
extern SCModule* SC__Comp_program;
extern JB_String* SC__Comp_ProjectName;
extern Array* SC__Comp_ProtoTypes;
extern SCFunction* SC__Comp_RefDecr;
extern SCFunction* SC__Comp_RefFreeIfDead;
extern SCFunction* SC__Comp_RefIncr;
extern SCFunction* SC__Comp_RefSafeDecr;
extern SCFunction* SC__Comp_RefSetRef;
extern JB_String* SC__Comp_ReportedName;
extern int SC__Comp_stClasses;
extern int SC__Comp_stFuncs;
extern int SC__Comp_stFunctionProgress;
extern int SC__Comp_stParseTime;
extern int SC__Comp_stParseTimeTotal;
extern int SC__Comp_stReachedClass;
extern int SC__Comp_stReachedFunc;
extern int SC__Comp_stTotalFileCount;
extern int SC__Comp_stTotalSourceSize;
extern Array* SC__Comp_SyxArray;
extern JB_File* SC__Comp_TempFolder;
extern SCFunction* SC__Comp_TernaryFunc;
extern SCFunction* SC__Comp_TernaryFunc2;
extern FastString* SC__Comp_TimerOutput;
extern SCBase* SC__Comp_VisibleFuncs;
#define kSC__CustomOps_LeftOnlyIsVector (65)
#define kSC__CustomOps_Needed (64)
#define kSC__CustomOps_NotCustom (0)
#define kSC__CustomOps_RightOnlyIsVector (66)
#define kSC__CustomOps_TypeCastFromBool (16)
#define kSC__CustomOps_TypeCastToBigger (32)
#define kJB__ErrorColors_bold (JB_LUB[1812])
extern bool JB__ErrorColors_Enabled;
#define kJB__ErrorColors_error (JB_LUB[1813])
#define kJB__ErrorColors_good (JB_LUB[1814])
#define kJB__ErrorColors_normal (JB_LUB[1815])
#define kJB__ErrorColors_underline (JB_LUB[1814])
#define kJB__ErrorColors_warn (JB_LUB[1816])
extern Array* SC__ExecTable_Funcs;
extern Array* SC__ExecTable_Globs;
extern SCFunction* SC__FastStringOpts__ByteFunc;
extern int SC__FastStringOpts_FSRemoved;
extern int SC__FastStringOpts_StrRemoved;
extern Dictionary* SC__FB_AppOptions;
extern Macro* SC__AC_all_tmp_src;
extern SCFunction* SC__AC_AnonFn;
extern SCBase* SC__AC_AnonParent;
extern JB_String* SC__AC_AnonText;
extern bool SC__AC_CompileUpToDate;
extern Macro* SC__AC_func_tmp_src;
extern int SC__AC_max_total;
extern Process* SC__AC_Perry;
extern byte SC__AC_ShouldEnter;
extern int SC__AC_total;
extern u16 JB__API_NilHappened;
extern CharSet* JB__Constants_CSAfterStatement;
extern CharSet* JB__Constants_CSLettersOnly;
extern CharSet* JB__Constants_CSLine;
extern CharSet* JB__Constants_CSLineBlack;
extern CharSet* JB__Constants_CSNum;
extern CharSet* JB__Constants_CSWordMiddle;
extern CharSet* JB__Constants_CSWordStart;
extern CharSet* JB__Constants_CSWrapSplit;
extern Dictionary* JB__Constants_EscapeChr;
extern Dictionary* JB__Constants_EscapeStr;
extern Dictionary* JB__Constants_JS_EscapeStr;
extern Dictionary* JB__Constants_JS_UnEscapeStr;
extern JB_String* JB__Constants_Name;
extern JB_ErrorReceiver* JB__Constants_ParseProtector;
extern Dictionary* JB__Constants_UnEscapeStr;
extern Dictionary* JB__Constants_XML_EscapeStr;
extern Dictionary* JB__Constants_XML_UnEscapeStr;
extern Message* SC__Linkage_Dict;
extern Message* SC__Linkage_Flags;
extern Macro* SC__Macros_ASM_Datatype;
extern Macro* SC__Macros_Copier;
extern Macro* SC__Macros_Copier2;
extern Macro* SC__Macros_FS;
extern Macro* SC__Macros_InitExpand;
extern Macro* SC__Macros_MainArg1;
extern Macro* SC__Macros_MainArg2;
extern Macro* SC__Macros_Setter;
extern Macro* SC__Macros_Worked2;
#define kJB__Math_E (2.7182818284590452353602874713526f)
extern JB_String* SC__Options_Arch;
extern bool SC__Options_ArgStats;
extern Dictionary* SC__Options_BannedClasses;
extern bool SC__Options_CheckMaxVars;
extern bool SC__Options_Compile;
extern MaybeBool SC__Options_Compile32Bit;
extern bool SC__Options_Cpp;
extern bool SC__Options_ExternalCompile;
extern bool SC__Options_Final;
extern bool SC__Options_Flow;
extern bool SC__Options_ForceRecompile;
extern bool SC__Options_HideMultipleErrors;
extern bool SC__Options_IgnoreCantSaveErrors;
extern bool SC__Options_IsDirectTest;
extern bool SC__Options_KeepAllErrors;
#define kSC__Options_LargestFlag (3)
extern bool SC__Options_ListAllLib;
extern bool SC__Options_MakeLib;
#define kSC__Options_native (1)
extern int SC__Options_OperationCount;
extern int SC__Options_Optimise;
extern JB_String* SC__Options_output_path;
#define kSC__Options_pack (2)
extern byte SC__Options_Perry;
extern bool SC__Options_PrintCompileString;
extern bool SC__Options_PrintFiles;
extern bool SC__Options_PrintLibraries;
extern bool SC__Options_PrintStages;
extern int SC__Options_Products;
extern bool SC__Options_ProjectIsLibrary;
extern bool SC__Options_ProjectIsMiniLib;
extern bool SC__Options_Scripting;
extern int SC__Options_SelfReplacement;
extern bool SC__Options_Silent;
extern bool SC__Options_SingleCppOutput;
extern JB_String* SC__Options_SingleFileInput;
extern bool SC__Options_TargetDebug;
extern bool SC__Options_UseFuncCallCount;
extern JB_String* SC__Options_Variant;
extern bool SC__Options_Warnings;
extern JB_String* JB__Tk_Data;
extern bool JB__Tk_DotInsertAllow;
extern Message* JB__Tk_EndOfLineMarker;
extern Dictionary* JB__Tk_ErrorNames;
extern JB_String* JB__Tk_ErrorTabsAfterSpaces;
extern MsgUIFlags JB__Tk_InsertedFlags;
#define kJB__Tk_adjectiveop (1)
#define kJB__Tk_Allow (false)
#define kJB__Tk_colon (2)
#define kJB__Tk_colonarg (4)
#define kJB__Tk_Comma (16)
#define kJB__Tk_End ((8 | 16) | 32)
#define kJB__Tk_EndContainer (32)
#define kJB__Tk_EndOfLine (8)
#define kJB__Tk_Expect (true)
#define kJB__Tk_FuncAfterAny ((64 | 128) | 256)
#define kJB__Tk_FuncAfterBar (256)
#define kJB__Tk_FuncAfterNormal (64)
#define kJB__Tk_FuncAfterNoSpace (128)
#define kJB__Tk_illegalchar (4194304)
#define kJB__Tk_LameTemporal (32768 | (65536 | 131072))
#define kJB__Tk_Opp (((((512 | 1024) | 2048) | 4096) | 8192) | 16384)
#define kJB__Tk_OppBar (2048)
#define kJB__Tk_OppBra (512)
#define kJB__Tk_OppChain (8192 | 512)
#define kJB__Tk_OppNoBar ((((((512 | 1024) | 2048) | 4096) | 8192) | 16384) & (~2048))
#define kJB__Tk_OppSNB (1024)
#define kJB__Tk_OppSyx (1024 | 2048)
#define kJB__Tk_OppTemporal (4096)
#define kJB__Tk_OppWord (8192)
#define kJB__Tk_OppYoda (16384)
#define kJB__Tk_Temporal ((32768 | 65536) | 131072)
#define kJB__Tk_TemporalBar (131072)
#define kJB__Tk_TemporalSyx (65536 | 131072)
#define kJB__Tk_TemporalSyxNoBar (65536)
#define kJB__Tk_TemporalWord (32768)
#define kJB__Tk_temporalwordcolon (262144)
#define kJB__Tk_Thing ((524288 | 1048576) | 2097152)
#define kJB__Tk_ThingBar (1048576)
#define kJB__Tk_ThingSyx (524288)
#define kJB__Tk_ThingWord (2097152)
#define kJB__Tk_TmpOpp (4096 | 65536)
#define kJB__Tk_LargestFlag (8388607)
extern int JB__Tk_StopBars;
extern u16 JB__Tk_UsingLength;
extern int JB__Tk_UsingPos;
extern u16 JB__Tk_UsingTag;
#define kJB__Pipe_StdErr_ (2)
#define kJB__Pipe_StdIn_ (0)
#define kJB__Pipe_StdOut_ (1)
extern JB_File* JB__Platform_Logger;
extern Dictionary* SC__Errors_IgnoredBranches;
extern Dictionary* SC__SCGame3D_Types;
extern int SC__SC_UniqueNum;
#define kSC__Refs_BasisDeSTRUCTable (2)
#define kSC__Refs_BasisNotObj (0)
#define kSC__Refs_BasisObj (1)
#define kSC__Refs_BasisTempStruct (4)
#define kSC__Refs_HoldsDisowned (64)
#define kSC__Refs_IsDisowner (32)
#define kSC__Refs_IsNoisy (16)
#define kSC__Refs_NotDisturbed (0)
#define kSC__Refs_SufferedNoise (8)
extern SCFunction* SC__Refs_ThisFunc;
extern Message* SC__SCStrings_RenderFinish;
extern Message* SC__SCStrings_RenderInsides;
extern Message* SC__SCStrings_RenderNewParams;
extern Dictionary* SC__Targets_Items;
#define kJB__Terminal_Black (30)
#define kJB__Terminal_blue (34)
extern MWrap* JB__Terminal_ColorInfo;
#define kJB__Terminal_cyan (36)
extern FastString* JB__Terminal_fs;
#define kJB__Terminal_green (32)
#define kJB__Terminal_h (35)
extern Date JB__Terminal_LastDisplay;
#define kJB__Terminal_magenta (35)
#define kJB__Terminal_red (31)
extern Array* JB__Terminal_Screen;
#define kJB__Terminal_TermClear (JB_LUB[1817])
#define kJB__Terminal_TermReset (JB_LUB[1818])
#define kJB__Terminal_w (80)
#define kJB__Terminal_white (37)
#define kJB__Terminal_yellow (33)
extern Dictionary* SC__TextAssembler_LabelsToDo;
extern Array* SC__Ext_Cleanup;
extern int SC__Ext_CompilingLibFiles;
extern JB_String* SC__Ext_CppCompilerPath;
extern Array* SC__Ext_FoundObjects;
extern Array* SC__TreeAssembler_PackFuncs;
extern ASMFuncState SC__TreeAssembler_StdState;
extern Array* SC__VM_Builder_Builder;
extern Message* SC__VM_Builder_dt_prm;
extern FastString* SC__VM_Builder_form_h;
extern byte SC__VM_Builder_HighPos;
extern Message* SC__VM_Builder_ModuleArg;
extern Array* SC__VM_Builder_Msgs;
extern Message* SC__VM_Builder_NameList;
extern byte SC__VM_Builder_NormalPos;
extern JB_String* SC__VM_Builder_parent;
extern JB_File* SC__VM_Builder_vm_file;
extern JB_String* JB__zalgo_down;
extern JB_String* JB__zalgo_mid;
extern Random JB__zalgo_R;
extern JB_String* JB__zalgo_up;
extern JB_String* JB___AppConfString;
extern SyntaxObj* JB__FuncArray_[64];
extern JB_String* JB__JbinHeader;
extern bool _once1;
extern bool _once2;
extern Dictionary* JB__SyxDict_;
extern CharSet* JB_C_Letters;
extern Dictionary* JB_ClassLinkageTable;
extern Dictionary* JB_ClsCollectTable;
extern JB_String* JB_codesign_native;
extern Dictionary* JB_CppRefTable;
extern CharSet* JB_CSHex;
extern CharSet* JB_CSNum;
extern ExprResolver JB_ExprFuncs[64];
extern SCDecl* JB_FalseBool;
extern fn_asm JB_fn_asm_table[64];
extern Dictionary* JB_FuncLinkageTable;
#define kSC_AddressOfMatch (3)
#define kSC_BitAnd (JB_LUB[336])
#define kSC_BitNot (JB_LUB[435])
#define kSC_BitOr (JB_LUB[644])
#define kSC_BitXor (JB_LUB[1819])
#define kSC_CastedMatch (6)
#define kSC_DestructorNotFromLocalRefs (512)
#define kSC_DontSaveProperty (0)
#define kSC_IsAlloc (128)
#define kSC_IsComparison (16)
#define kSC_IsConstructor (1)
#define kSC_IsDestructor (2)
#define kSC_IsEmptyConstructor (1 << 13)
#define kSC_IsInitFunc (1024)
#define kSC_IsLayer (64)
#define kSC_IsMemory (2048)
#define kSC_IsNew (4)
#define kSC_IsNewStruct (256)
#define kSC_IsProperty (8)
#define kSC_IsReffer (32)
#define kSC_IsVirtualCaller (4096)
#define kSC_LossyCastedMatch (7)
extern JB_String* JB_kNameConf;
#define kSC_Needs (16 | (32 | 64))
#define kSC_NeedsAddressOf (32)
#define kSC_NeedsAddressOfButAlsoNeedsSuperMatch (64)
#define kSC_NeedsTypeCast (16)
#define kSC_NoBoolTypeCast (16)
#define kSC_NoMatch (0)
#define kSC_NumericMatch (2)
#define kSC_Replaced (2048)
#define kSC_SaveProperty (1)
#define kSC_SavePropertyAndGoIn (2)
#define kJB_SaverEnd (JB_LUB[0])
#define kJB_SaverStart1 (JB_LUB[1820])
#define kSC_SelfDebug (2)
#define kSC_SelfReplace (1)
#define kSC_SimpleMatch (1)
#define kSC_StrOwned (20)
#define kSC_StrShared (0)
#define kSC_StrSharedParams (10)
#define kSC_SuperClassMatch (4)
#define kSC_TypeCastAssigns (32)
#define kSC_TypeCastBothWays (8)
#define kSC_TypeCastFalse (0)
#define kSC_TypeCastIgnoreContained (4)
#define kSC_TypeCastMost (1)
#define kSC_TypeCastNumbers (2)
#define kSC_TypeCastTrue (1 | 2)
#define kSC_UseDefaultParams (10)
#define kSC_VoidPtrMatch (5)
#define kSC_MsgDebugPosShift (19)
extern int JB_naawgr[1];
extern Dictionary* JB_RootCollectTable;
extern JB_ErrorReceiver* JB_StdErr;
extern Syntax JB_SyxAcc;
extern Syntax JB_SyxAdj;
extern Syntax JB_SyxARel;
extern Syntax JB_SyxArg;
extern Syntax JB_SyxArr;
extern Syntax JB_SyxAsk;
extern Syntax JB_SyxBack;
extern Syntax JB_SyxBadj;
extern Syntax JB_SyxBin;
extern Syntax JB_Syxbinn;
extern Syntax JB_SyxBra;
extern Syntax JB_SyxBRel;
extern Syntax JB_SyxChar;
extern Syntax JB_SyxCnj;
extern Syntax JB_SyxDecl;
extern Syntax JB_SyxDot;
extern Syntax JB_SyxEmb;
extern Syntax JB_SyxERel;
extern Syntax JB_SyxFile;
extern Syntax JB_SyxFunc;
extern Syntax JB_SyxItem;
extern Syntax JB_SyxList;
extern Syntax JB_SyxMsg;
extern Syntax JB_SyxName;
extern Syntax JB_SyxNil;
extern Syntax JB_SyxNum;
extern Syntax JB_SyxOat;
extern Syntax JB_SyxOpp;
extern Syntax JB_Syxpinn;
extern Syntax JB_SyxPrm;
extern Syntax JB_SyxQues;
extern Syntax JB_SyxQuot;
extern Syntax JB_SyxRel;
extern Syntax JB_SyxSCnj;
extern Syntax JB_SyxSCom;
extern Syntax JB_SyxSDot;
extern Syntax JB_SyxSheb;
extern Syntax JB_SyxSStr;
extern Syntax JB_SyxSThg;
extern Syntax JB_SyxStr;
extern Syntax JB_SyxThg;
extern Syntax JB_SyxTmp;
extern Syntax JB_SyxTodo;
extern Syntax JB_SyxTRel;
extern Syntax JB_SyxTril;
extern Syntax JB_SyxType;
extern Syntax JB_SyxUnit;
extern Syntax JB_Syxurl;
extern Syntax JB_SyxXAtt;
extern Syntax JB_SyxXCDT;
extern Syntax JB_SyxXCom;
extern Syntax JB_SyxXML;
extern Syntax JB_SyxXPI;
extern Syntax JB_SyxXTxt;
extern Syntax JB_SyxYoda;
extern SCDecl* JB_TrueBool;
extern SCClass* JB_TypeArray;
extern SCClass* JB_TypeBool;
extern SCClass* JB_TypeByte;
extern SCClass* JB_TypeCharSet;
extern SCClass* JB_TypeDate;
extern SCClass* JB_TypeDictionary;
extern SCClass* JB_Typef32;
extern SCClass* JB_Typef64;
extern SCClass* JB_TypeFastString;
extern SCClass* JB_Typefloat;
extern SCClass* JB_Typehfloat;
extern SCClass* JB_TypeInt;
extern SCClass* JB_TypeInt16;
extern SCClass* JB_TypeInt64;
extern SCClass* JB_TypeiVec2;
extern SCClass* JB_TypeiVec3;
extern SCClass* JB_TypeiVec4;
extern SCClass* JB_TypeJBClass;
extern SCDecl* JB_TypeNil;
extern SCClass* JB_TypeObject;
extern SCClass* JB_TypeSaveable;
extern SCClass* JB_TypeString;
extern SCClass* JB_TypeSyntax;
extern SCClass* JB_TypeuInt;
extern SCClass* JB_TypeuInt16;
extern SCClass* JB_TypeuInt64;
extern SCClass* JB_TypeVec2;
extern SCClass* JB_TypeVec3;
extern SCClass* JB_TypeVec4;
extern SCDecl* JB_TypeVoid;
extern SCClass* JB_TypeVoid_;
extern SCClass* JB_TypeVoidPtr;
extern SCClass* JB_TypeWrapper;
extern AsmReg SC_xxx;
#define kJB__byte_max (255)
#define kJB__byte_min (0)
#define kJB__char_max (127)
#define kJB__char_min (-128)
#define kJB__ErrorFlags_dontstrip (1)
#define kJB__ErrorFlags_Keep (0)
#define kJB__ErrorFlags_LargestFlag (7)
#define kJB__ErrorFlags_parse (4)
#define kJB__ErrorFlags_prefernorenderpath (2)
#define kJB__ErrorFlags_PrintAndKeep (1)
#define kJB__ErrorFlags_PrintAndRemove (2)
#define kJB__ErrorSeverity_Critical (5)
#define kJB__ErrorSeverity_Error (4)
#define kJB__ErrorSeverity_Hint (1)
#define kJB__ErrorSeverity_MaxError (6)
extern Array* JB__ErrorSeverity_names;
#define kJB__ErrorSeverity_OK (0)
#define kJB__ErrorSeverity_Problem (3)
#define kJB__ErrorSeverity_Warning (2)
#define kJB__int16_max (32767)
#define kJB__int16_min (-32768)
#define kJB__int64_max (9223372036854775807)
#define kJB__int64_min (9223372036854775807 + 1)
#define kSC__SCBaseInfo_explicitexport (0)
#define kSC__SCBaseInfo_visible (1)
#define kSC__SCBaseType_DataType (4)
#define kSC__SCBaseType_FuncProto (5)
#define kSC__SCBaseType_Module (0)
#define kSC__SCBaseType_Nil (1)
#define kSC__SCBaseType_Object (2)
#define kSC__SCBaseType_Struct (3)
extern int JB__Syx_CurrFuncID;
extern int JB__Syx_MaxFuncID;
#define kJB__uint_max (4294967295)
#define kJB__uint_min (0)
#define kJB__uint16_max (65535)
#define kJB__uint16_min (0)
#define kJB__uint64_max (-1)
#define kSC__TM_BaseShrinkSpeed (0.0005f)
#define kSC__TM_Halfmap (6148914691236517205)
#define kSC__TM_mousebuttondown (1025)
#define kSC__TM_MOUSEMOTION (1024)
#define kJB__CL1_After (6)
#define kJB__CL1_Before (4)
#define kJB__CL1_Centered (7)
#define kJB__CL1_High (2)
#define kJB__CL1_Length (10)
#define kJB__CL1_Low (0)
#define kJB__CL1_Percent (8)
#define kJB__CL1_SlideBackInParent (1)
#define kJB__CL1_SlideBackInWindow (2)
#define kJB__TC_atomic_byte (0 + (8 + 4))
#define kJB__TC_atomic_int (0 + (32 + (64 + (0 + (8 + 4)))))
#define kJB__TC_atomic_int64 (0 + (48 + (64 + (0 + (8 + 4)))))
#define kJB__TC_atomic_uint (0 + (32 + (0 + (0 + (8 + 4)))))
#define kJB__TC_atomic_uint64 (0 + (48 + (0 + (0 + (8 + 4)))))
#define kJB__TC_bool (0)
#define kJB__TC_byte (kJB__TC_u8)
#define kJB__TC_Byte2 (1 + (0 + (0 + (0 + 8))))
#define kJB__TC_Byte3 (2 + (0 + (0 + (0 + 8))))
#define kJB__TC_Byte4 (3 + (0 + (0 + (0 + 8))))
#define kJB__TC_char (0 + (0 + (64 + (0 + 8))))
#define kJB__TC_Double (0 + (48 + (64 + (128 + 8))))
#define kJB__TC_f16 (kJB__TC_HFloat)
#define kJB__TC_f64 (kJB__TC_Double)
#define kJB__TC_Float (0 + (32 + (64 + (128 + 8))))
#define kJB__TC_HFloat (0 + (16 + (64 + (128 + 8))))
#define kJB__TC_Int (0 + (32 + (64 + (0 + 8))))
#define kJB__TC_int16 (0 + (16 + (64 + (0 + 8))))
#define kJB__TC_int64 (0 + (48 + (64 + (0 + 8))))
#define kJB__TC_int8 (kJB__TC_char)
#define kJB__TC_iVec2 (1 + (32 + (64 + (0 + 8))))
#define kJB__TC_iVec3 (2 + (32 + (64 + (0 + 8))))
#define kJB__TC_iVec4 (3 + (32 + (64 + (0 + 8))))
#define kJB__TC_s16 (kJB__TC_int16)
#define kJB__TC_s16x2 (1 + (16 + (64 + (0 + 8))))
#define kJB__TC_s16x3 (2 + (16 + (64 + (0 + 8))))
#define kJB__TC_s16x4 (3 + (16 + (64 + (0 + 8))))
#define kJB__TC_s64 (kJB__TC_int64)
#define kJB__TC_s8 (kJB__TC_char)
#define kJB__TC_SByte (0 + (0 + (64 + (0 + 8))))
#define kJB__TC_SByte2 (1 + (0 + (64 + (0 + 8))))
#define kJB__TC_SByte3 (2 + (0 + (64 + (0 + 8))))
#define kJB__TC_SByte4 (3 + (0 + (64 + (0 + 8))))
#define kJB__TC_sign (64)
extern Dictionary* JB__TC_Types_Dict;
#define kJB__TC_u16 (kJB__TC_uint16)
#define kJB__TC_u32 (kJB__TC_UInt)
#define kJB__TC_u64 (kJB__TC_uint64)
#define kJB__TC_u8 (0 + 8)
#define kJB__TC_UInt (0 + (32 + (0 + (0 + 8))))
#define kJB__TC_uint16 (0 + (16 + (0 + (0 + 8))))
#define kJB__TC_uint64 (0 + (48 + (0 + (0 + 8))))
#define kJB__TC_uint8 (kJB__TC_u8)
#define kJB__TC_UnusedType ((0 + (48 + (64 + (0 + 8)))) & (~8))
#define kJB__TC_Vec2 (1 + (32 + (64 + (128 + 8))))
#define kJB__TC_Vec3 (2 + (32 + (64 + (128 + 8))))
#define kJB__TC_Vec4 (3 + (32 + (64 + (128 + 8))))
#define kJB__Date_ClocksPerSecond (1000000)
#define kJB__Date_OneSecond (65536)
#define kJB__Date_SecondsPerDay (86400)
#define kJB__Date_SecondsPerMonthApprox (2628000)
#define kJB__Date_SecondsPerWeek (604800)
#define kJB__Date_TickBits (16)
#define kJB__Date_Ticks (65536)
#define kJB__FileMode_CanExec (1 << ((6 + 1) << ((3 + 1) << 0)))
#define kJB__FileMode_Data (6 << ((6 + 4) << ((2 + 4) << 2)))
#define kJB__FileMode_Group (7 << 3)
#define kJB__FileMode_Other (7 << 0)
#define kJB__FileMode_Owner (7 << 6)
#define kJB__FileMode_Process (((7 << 6) + 5) << ((3 + 5) << 0))
#define kJB__IPCState_closed (4664)
#define kJB__IPCState_connected (4662)
#define kJB__IPCState_connecting (4661)
#define kJB__IPCState_crashed (4666)
#define kJB__IPCState_dead (4665)
#define kJB__IPCState_invalid (4667)
#define kJB__IPCState_timedout (4663)
#define kJB__IPCState_Waiting (4660)
#define kJB__MsgUIFlags_BreakPoint (32768)
#define kJB__MsgUIFlags_Inserted (8192)
#define kJB__MsgUIFlags_LargestFlag (0)
#define kJB__MsgUIFlags_Reserved (4096)
#define kJB__MsgUIFlags_Style2 (16384)
#define kSC__SCDeclInfo_api (128)
#define kSC__SCDeclInfo_atomic (8192)
#define kSC__SCDeclInfo_borrowed (1)
#define kSC__SCDeclInfo_compilercreated (512)
#define kSC__SCDeclInfo_const (2)
#define kSC__SCDeclInfo_disabled (1024)
#define kSC__SCDeclInfo_gameflyingmem (2048)
#define kSC__SCDeclInfo_hidden (256)
#define kSC__SCDeclInfo_LargestFlag (32767)
#define kSC__SCDeclInfo_newlycreated (16)
#define kSC__SCDeclInfo_property (4096)
#define kSC__SCDeclInfo_setto (16384)
#define kSC__SCDeclInfo_static (4)
#define kSC__SCDeclInfo_typeimprove (32)
#define kSC__SCDeclInfo_upgradeablecontained (8)
#define kSC__SCDeclInfo_usedbycode (64)
#define kSC__ASM_ADD (12)
#define kSC__ASM_ADDC (11)
#define kSC__ASM_BAND (19)
#define kSC__ASM_BFLG (23)
#define kSC__ASM_BFLS (24)
#define kSC__ASM_BNOT (22)
#define kSC__ASM_BOR (20)
#define kSC__ASM_BRA (31)
#define kSC__ASM_BRAN (32)
#define kSC__ASM_BROL (25)
#define kSC__ASM_BROR (26)
#define kSC__ASM_BXOR (21)
#define kSC__ASM_CMPE (29)
#define kSC__ASM_CMPF (28)
#define kSC__ASM_CMPI (27)
#define kSC__ASM_CMPN (30)
#define kSC__ASM_CNTC (49)
#define kSC__ASM_CONV (8)
#define kSC__ASM_DADD (55)
#define kSC__ASM_DDIV (58)

#define kSC__ASM_DIV (15)
#define kSC__ASM_DMUL (57)
#define kSC__ASM_DSUB (56)
extern ASM_Encoder2 SC__ASM_Encoders[128];
#define kSC__ASM_EROR (0)
#define kSC__ASM_Extended (255)
#define kSC__ASM_FADD (51)
#define kSC__ASM_FDIV (54)
#define kSC__ASM_FMUL (53)
#define kSC__ASM_FNC (112)
#define kSC__ASM_FNCX (113)
extern ASM_Encoder2 SC__ASM_Forms[32];
#define kSC__ASM_FSUB (52)
#define kSC__ASM_HALT (1)
#define kSC__ASM_Jump (32)
#define kSC__ASM_LargestFlag (0)
#define kSC__ASM_LEAF (5)
#define kSC__ASM_LUPD (34)
#define kSC__ASM_LUPU (33)
#define kSC__ASM_MEMM (50)
#define kSC__ASM_MUL (14)
#define kSC__ASM_NoExpect (512)
extern byte SC__ASM_NoisyASM;
#define kSC__ASM_Num (64)
#define kSC__ASM_PositionBits (1024)
#define kSC__ASM_PRNT (59)
#define kSC__ASM_RALO (37)
#define kSC__ASM_RARE (7)
#define kSC__ASM_RD1S (39)
#define kSC__ASM_RD1U (38)
#define kSC__ASM_RD2S (41)
#define kSC__ASM_RD2U (40)
#define kSC__ASM_RD4S (43)
#define kSC__ASM_RD4U (42)
#define kSC__ASM_RD8U (44)
#define kSC__ASM_Remainder (256)
#define kSC__ASM_RET (4)
#define kSC__ASM_RETL (6)
#define kSC__ASM_RSDE (35)
#define kSC__ASM_RSET (36)
#define kSC__ASM_SET1 (9)
#define kSC__ASM_SETK (10)
#define kSC__ASM_SETN (114)
#define kSC__ASM_SHLS (18)
#define kSC__ASM_SHRS (16)
#define kSC__ASM_SHRU (17)
#define kSC__ASM_Signed (128)
#define kSC__ASM_ST1U (45)
#define kSC__ASM_ST2U (46)
#define kSC__ASM_ST4U (47)
#define kSC__ASM_ST8U (48)
#define kSC__ASM_STCK (2)
#define kSC__ASM_SUB (13)
#define kSC__ASM_SWAP (3)
extern IR SC__flat_Dummy;
extern MWrap* SC__flat_JSMSpace;
extern CompressionStats JB__MzSt_All;

extern Dictionary* JB__LD_ClassList;
#define kJB__Saver_RefMark (1073741824)
extern SaverClassInfo* JB__Saver_SaveableList;
extern Random JB__Rnd_Shared;
extern Array* SC__Cpp_Cpp_Includes;
extern Array* SC__Cpp_Cpp_Input;
extern JB_String* SC__Cpp_CppLicenceStr;
extern SCClass* SC__Cpp_CurrClass;
extern JB_String* SC__Cpp_FindGlobalsCpp;
extern Array* SC__Cpp_H_Input;
extern Array* SC__Cpp_H_PostInput;
#define kSC__Cpp_NeedsInnerBrackets (1)
#define kSC__Cpp_NeedsNoBrackets (2)
#define kSC__Cpp_NeedsOuterBrackets (0)
extern uint64 SC__Cpp_LubHash;
extern FastStringCpp* SC__Cpp_StringBlob;
extern int SC__Cpp_StringCount;
extern Dictionary* SC__Cpp_StringDict;
extern FastStringCpp* SC__Cpp_StringLengths2;
extern bool SC__Cpp_WriteAPI;
extern bool SC__Cpp_WroteAny;
#define kJB__Wrap_Delete (2)
#define kJB__Wrap_Free (1)
#define kJB__Wrap_Nothing (0)
extern FastString* JB__FS_StdOutFS;
#define kJB__dict_TypeDict (3)
#define kJB__dict_TypeObj (1)
#define kJB__dict_TypeStem (2)
#define kJB__dict_TypeValue (0)
extern uint64 JB__Mrap_MDummy[2];
extern Process* JB__Proc_Children[16];
extern byte JB__Proc_ClosePipesInstalled;
extern int JB__Proc_IncID;
extern Process* JB__Proc_Owner_;
#define kJB__Proc_PrintWaiting (2)
extern byte JB__Proc_SpecialState;
extern Array* SC__Imp_AllFiles;
extern SCImport* SC__Imp_Curr;
extern Date SC__Imp_Recent;
extern Dictionary* SC__Imp_Shaders;
extern bool SC__Imp_STDLibTime;
extern int SC__Opp_CustomOperatorScore;
extern Dictionary* SC__Opp_Dict;
extern int SC__xC2xB5Form_Count;
extern Dictionary* SC__xC2xB5Form_Forms;
extern bool JB__File_DebugExecute;
#define kJB__File_IgnoreErrors (true)
#define kJB__File_O_APPEND (8)
#define kJB__File_O_CREAT (512)
#define kJB__File_O_EXCL (2048)
#define kJB__File_O_RDONLY (0)
#define kJB__File_O_RDWR (2)
#define kJB__File_O_TRUNC (1024)
#define kJB__File_O_WRONLY (1)
extern Instruction* SC__Instruction___First;
extern Instruction* SC__Instruction_ADD;
extern Instruction* SC__Instruction_ADDC;
extern Instruction* SC__Instruction_BAND;
extern Instruction* SC__Instruction_BFLG;
extern Instruction* SC__Instruction_BFLS;
extern Instruction* SC__Instruction_BNOT;
extern Instruction* SC__Instruction_BOR;
extern Instruction* SC__Instruction_BRA;
extern Instruction* SC__Instruction_BRAN;
extern Instruction* SC__Instruction_BROL;
extern Instruction* SC__Instruction_BROR;
extern Instruction* SC__Instruction_BXOR;
extern Instruction* SC__Instruction_CMPE;
extern Instruction* SC__Instruction_CMPF;
extern Instruction* SC__Instruction_CMPI;
extern Instruction* SC__Instruction_CMPN;
extern Instruction* SC__Instruction_CNTC;
extern Instruction* SC__Instruction_CONV;
extern Instruction* SC__Instruction_DADD;
extern Instruction* SC__Instruction_DDIV;
extern Instruction* SC__Instruction_DIV;
extern Instruction* SC__Instruction_DMUL;
extern Instruction* SC__Instruction_DSUB;
extern Instruction* SC__Instruction_EROR;
extern Instruction* SC__Instruction_FADD;
extern Instruction* SC__Instruction_FDIV;
extern Instruction* SC__Instruction_FMUL;
extern Instruction* SC__Instruction_FNC;
extern Instruction* SC__Instruction_FNCX;
extern Instruction* SC__Instruction_FSUB;
extern Instruction* SC__Instruction_HALT;
#define kSC__Instruction_TypeConst (2)
#define kSC__Instruction_TypeFunc (1)
extern Instruction* SC__Instruction_LEAF;
extern Instruction* SC__Instruction_LUPD;
extern Instruction* SC__Instruction_LUPU;
extern Instruction* SC__Instruction_MEMM;
extern Instruction* SC__Instruction_MUL;
extern Instruction* SC__Instruction_PRNT;
extern Instruction* SC__Instruction_RALO;
extern Instruction* SC__Instruction_RARE;
extern Instruction* SC__Instruction_RD1S;
extern Instruction* SC__Instruction_RD1U;
extern Instruction* SC__Instruction_RD2S;
extern Instruction* SC__Instruction_RD2U;
extern Instruction* SC__Instruction_RD4S;
extern Instruction* SC__Instruction_RD4U;
extern Instruction* SC__Instruction_RD8U;
extern Instruction* SC__Instruction_RET;
extern Instruction* SC__Instruction_RETL;
extern Instruction* SC__Instruction_RSDE;
extern Instruction* SC__Instruction_RSET;
extern Instruction* SC__Instruction_SET1;
extern Instruction* SC__Instruction_SETK;
extern Instruction* SC__Instruction_SETN;
extern Instruction* SC__Instruction_SHLS;
extern Instruction* SC__Instruction_SHRS;
extern Instruction* SC__Instruction_SHRU;
extern Instruction* SC__Instruction_ST1U;
extern Instruction* SC__Instruction_ST2U;
extern Instruction* SC__Instruction_ST4U;
extern Instruction* SC__Instruction_ST8U;
extern Instruction* SC__Instruction_STCK;
extern Instruction* SC__Instruction_SUB;
extern Instruction* SC__Instruction_SWAP;
extern Dictionary* SC__Instruction_TypeDict;
extern Instruction* SC__Instruction_TypeList[256];
extern int SC__Instruction_TypeListSize;
extern MaterialsLol* SC__MaterialsLol___First;
extern MaterialsLol* SC__MaterialsLol_Iron;
extern MaterialsLol* SC__MaterialsLol_Pellets;
extern MaterialsLol* SC__MaterialsLol_WierdBlock;
extern MaterialsLol* SC__MaterialsLol_Wood;
extern bool SC__Base_ConstantsLoadingOverride;
extern SCModule* SC__Base_CurrModule;
extern bool SC__Base_CurrVisibility;
#define kSC__Base_PurposeAddress (0)
#define kSC__Base_PurposeDot (2)
#define kSC__Base_PurposeFunc (1)
#define kSC__Base_PurposeHider (65536)
#define kSC__Base_PurposeVar (3)
#define kSC__Base_PurposeVarDecl (4)
#define kSC__Beh_BehaviourProto (2)
#define kSC__Beh_BehaviourProtoRequired (6)
#define kSC__Beh_BehaviourTable (1)
extern Message* SC__Class_ConstrLayerNew;
extern Message* SC__Class_ConstrLayerNew2;
extern Message* SC__Class_ConstrNew;
extern SCFunction* SC__Func_CurrFunc;
extern int SC__Func_DisabledPoints;
extern int SC__Func_FuncStats[12];
extern int SC__Func_OnceCount;
extern Dictionary* SC__Func_TemporalStatements;
extern SCIterator* SC__Iter_c_array;
extern SCIterator* SC__Iter_pointer;
extern byte JB__Err_AutoPrint;
extern bool JB__Err_KeepTraceStack;

//// HEADER JB.h



// __classes__


// __junktest_5__
void SC___junktest_5____abc(bool g);

int SC___junktest_5____Init_();

int SC___junktest_5____InitCode_();



// __modules__


// App
JB_String* JB_App__AppName();

JB_String* JB_App__AppPath();

JB_String* JB_App__conf(JB_String* name);

void JB_App__configureSet(JB_String* Value);

void JB_App__Crash(JB_String* reason);

JB_StringC* JB_App__CrashLogName();

ErrorInt JB_App__CWDSet(JB_String* Value);

void JB_App__Die(JB_String* Err, int code);

JB_String* JB_App__FileName();

int JB_App__Init_();

int JB_App__InitCode_();

bool JB_App__IsMainThread();

int JB_Main();

int64 JB_App__ObjMemory();

JB_String* JB_App__OrigPath();

JB_String* JB_App__Pref(JB_String* s);

void JB_App__PrefSet(JB_String* s, JB_String* Value);

JB_String* JB_App__pref_path();

void JB_App__PrefsInit(Date when);

void JB_App__Restart();

void JB_App__SavePrefs();

JB_String* JB_App__StackTrace(FastString* fs_in);

JB_String* JB_App__ArgValue(JB_String* name);



// asmOps
AsmReg SC_asmOps__Assign(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__BitAnd(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__BitOr(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__BitXor(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__Div(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__Equals(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__Less(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__LessEq(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__Minus(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__Mod(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__More(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__MoreEq(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__Mul(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__NotEq(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__Plus(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__ROL(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__ROR(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__SHL(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

AsmReg SC_asmOps__SHR(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);



// ASMtmp
AsmReg SC_ASMtmp__Debugger(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__If(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__Rejoin(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__Return(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__StateExpr(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__While(ASMFuncState* self, Message* exp, AsmReg Reg);



// Comp
SCDecl* SC_Comp__AddGlobalConst(JB_String* name, SCClass* c);

void SC_Comp__AddMain();

JB_String* SC_Comp__AddSCProj(JB_String* Path);

void SC_Comp__AddSubProjects(Array* Modules);

Dictionary* SC_Comp__Adj(Message* f);

void SC_Comp__AppBuildLibs(JB_File* inner);

void SC_Comp__AppBuildOneLib(JB_File* inner, Message* lib);

void SC_Comp__AppendCompilerTime(JB_String* s, int Durr);

void SC_Comp__AppleBuildApp(JB_File* project, JB_File* product);

bool SC_Comp__Banned(JB_String* name);

JB_String* SC_Comp__BuildErrors(ErrorSeverity MinSev);

JB_File* SC_Comp__BuildFolder();

void SC_Comp__CheckIsGoodLibrary();

void SC_Comp__CheckMaxVars();

void SC_Comp__CodeSign(JB_File* gui_exe);

void SC_Comp__Collect(Message* m, bool visible);

bool SC_Comp__CompileAll();

void SC_Comp__CompileTime();

SCClass* SC_Comp__Constpiler(JB_String* name);

void SC_Comp__CreateDisambiguation();

SCFunction* SC_Comp__CreateFuncFromSource(JB_String* Src);

void SC_Comp__CreateRoot();

void SC_Comp__DeadCodeStrip();

void SC_Comp__DoRefsB();

void SC_Comp__DoSavers(int Stage);

bool SC_Comp__EnterCompile();

Message* SC_Comp__ErrorsToPerry();

void SC_Comp__FileSanityTests();

void SC_Comp__FileTestsSub(JB_File* Dest, JB_File* Src, JB_String* A, JB_String* B);

SCClass* SC_Comp__FindClass(JB_String* name, Message* where);

SCClass* SC_Comp__FindClassOK(JB_String* name);

SCFunction* SC_Comp__FindFunction(JB_String* Name);

SCModule* SC_Comp__FindModule(JB_String* name, Message* where, JB_String* ErrMsg);

SCModule* SC_Comp__FindModuleMsg(Message* where);

SCBase* SC_Comp__FindModuleOrClass(Message* mod, bool retry);

JB_File* SC_Comp__FindProject(JB_String* Path, bool error);

JB_File* SC_Comp__FindProjectSub(JB_String* base, JB_String* Path);

JB_String* SC_Comp__FindProjNoSuffix(JB_String* Path);

JB_String* SC_Comp__FindSpeedieRoot();

JB_File* SC_Comp__GeneratedCppsFolder();

SCFunction* SC_Comp__GetMainFunc(Message* where);

JB_String* SC_Comp__IdealName();

void SC_Comp__ImportAll();

void SC_Comp__ImportLibs();

void SC_Comp__ImportProj();

int SC_Comp__Init_();

bool SC_Comp__InitBasicFuncs();

bool SC_Comp__InitBasicStuff();

int SC_Comp__InitCode_();

void SC_Comp__InitCompiler();

void SC_Comp__InitTypes();

JB_File* SC_Comp__InputFile(JB_File* Default, JB_String* s, Message* where);

bool SC_Comp__IsTest();

JB_File* SC_Comp__Jeebox();

JB_File* SC_Comp__Library();

void SC_Comp__LoadInits();

SCFunction* SC_Comp__LoadRefFunc(JB_String* name);

void SC_Comp__Main();

SCBase* SC_Comp__NewConf(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Comp__OrderClassList();

void SC_Comp__Package();

void SC_Comp__PostInitCodeCall();

void SC_Comp__PrepareInterpreter();

void SC_Comp__PrePrintErrors();

void SC_Comp__PrintCompileErrors();

void SC_Comp__PrintCompileTime(Date durr);

void SC_Comp__PrintErrors(ErrorSeverity MinSev);

void SC_Comp__PrintResults();

void SC_Comp__PrintStats();

JB_String* SC_Comp__Projects();

bool SC_Comp__Reached(JB_String* s);

int SC_Comp__ReachedClassCount();

int SC_Comp__Reachedfuncs();

void SC_Comp__RefConstructors();

bool SC_Comp__ScriptRecompile(JB_File* f, JB_File* script_build);

void SC_Comp__SetupEnv();

void SC_Comp__SortModules();

void SC_Comp__SortModulesBase(Array* NewList);

void SC_Comp__SortModulesSub(SCBaseType TypeWanted, Array* NewList);

JB_File* SC_Comp__Speedie();

JB_String* SC_Comp__SpeedieProj();

bool SC_Comp__Stage(JB_String* name);

SCClass* SC_Comp__AccessStr(JB_String* name, Message* where);

SCClass* SC_Comp__SyntaxAccess(Message* name);

void SC_Comp__SyntaxAppend(Message* m);

void SC_Comp__testdate();

void SC_Comp__Timer(JB_String* name);

void SC_Comp__TimerSub(JB_String* s, int Durr);

bool SC_Comp__TryVariousStartModes();

JB_File* SC_Comp__usingScript(JB_File* f);

JB_String* SC_Comp__VariantSuffix();



// CustomOps


// ErrorColors
void JB_ErrorColors__DisableIfNoTerminal();

int JB_ErrorColors__Init_();

int JB_ErrorColors__InitCode_();



// exec


// ExecTable
void SC_ExecTable__AddAll(Array* fl, bool WantLib);

JB_File* SC_ExecTable__FuncFile();

JB_String* SC_ExecTable__FuncStr(FastString* fs_in);

int SC_ExecTable__Init_();

int SC_ExecTable__InitCode_();

void SC_ExecTable__Run();



// FastStringOpts
SCFunction* SC_FastStringOpts__ByteFunc();

void SC_FastStringOpts__FS(Message* exp, Message* getresult);

int SC_FastStringOpts__Init_();

int SC_FastStringOpts__InitCode_();

void SC_FastStringOpts__String(Message* exp, Message* str);



// FB
bool SC_FB__AppOptions_alive(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_arch(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_argstats(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_breakonerr(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_check(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_clean(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_codesign(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_cpp(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_crash(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_directtest(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_dosign(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_env(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_errortest(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_final(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_force(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_funccount(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_gcc(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_help(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_ignorecantsave(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_keepallerrors(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_m32(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_m64(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_maxvars(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_nocolor(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_nocompile(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_noisy(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_optimise(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_output_path(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_path(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_perry(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_print(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_products(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_quiet(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_self(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_selfdebug(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_single(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_stages(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_target(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_targetdebug(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_variant(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_warn(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppTalk(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppTransCompile(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppVersionNumber(JB_String* Name, JB_String* Value, FastString* purpose);

void SC_FB__CheckSelfModifying(JB_String* S);

int SC_FB__CheckSelfModifying2();

bool SC_FB__CompilerInfo();

bool SC_FB__Explain(FastString* Purpose, JB_String* name);

void SC_FB__Help();

int SC_FB__Init_();

int SC_FB__InitCode_();

bool SC_FB__ParseArgs();

bool SC_FB__ParseArgsSub(Array* args);

void SC_FB__ParseOption(JB_Object* Obj);

JB_String* SC_FB__TryUseProject(JB_String* path, bool IsScript);



// InbuiltShellArgs
SCBase* SC_InbuiltShellArgs__Collect(Message* node, SCBase* name_space, Message* ErrPlace);



// AC
bool SC_AC__active();

void SC_AC__ActualDefine(Message* rz, Message* s, JB_String* purpose);

Message* SC_AC__AllTmps();

Message* SC_AC__AutoComplete(Message* ff, JB_String* name, JB_String* Purpose);

bool SC_AC__AutoCompleteSorter(autoitem* a, autoitem* b);

void SC_AC__AutoSub(SCBase* scope, JB_String* name, Array* found, int Types, Message* NeedTypeLimit);

void SC_AC__AutoSub2(SCObject* value, JB_String* key, JB_String* src_name, Array* found, bool exact, int Types, SCDecl* TypeLimiter);

Message* SC_AC__Backup_Define(SCFile* myfile, int f, Message* thg, JB_String* purpose);

Message* SC_AC__BuildError(JB_String* name);

Message* SC_AC__CallFrom(Message* msg, JB_String* purpose, JB_Object* found);

Message* SC_AC__CallFromDefine(Message* msg, SCFunction* fn, JB_Object* found);

void SC_AC__CallFromSub(Message* arg, SCFunction* fn);

bool SC_AC__CanUseName(SCBase* l);

Message* SC_AC__CmdResponse(Message* cmd, Message* arg);

void SC_AC__CmdWrap(Message* arg);

Message* SC_AC__Debug(Message* cmd);

Message* SC_AC__Define(Message* msg, JB_String* purpose, JB_Object* found);

Message* SC_AC__Define_Behaviour(SCFunction* fn, JB_String* purpose);

Message* SC_AC__DefineOrCall(Message* msg, JB_String* purpose, JB_Object* found);

Message* SC_AC__Diissplay(Message* msg, Message* s, JB_String* purpose);

Message* SC_AC__DoCmd(Message* cmd, Message* arg);

bool SC_AC__Enter();

JB_String* SC_AC__ErrName();

Message* SC_AC__FuncTmps();

SCFunction* SC_AC__GetFunc(Message* cmd, SCFile* myfile, int ff, int n);

SCFunction* SC_AC__GetFunc2(Message* cmd, SCFile* myfile, int f, int n);

SCBase* SC_AC__GetScope(Message* orig, int* types);

void SC_AC__HandleRestartedCompile();

void SC_AC__IdentifyBetter(Message* node, JB_String* name);

int SC_AC__Init_();

int SC_AC__InitCode_();

Message* SC_AC__Jump(Message* cmd);

Message* SC_AC__JumpImport(Message* cmd);

Message* SC_AC__LocateDefinition(Message* msg, SCObject* already_defined, bool DisplayOnly);

Message* SC_AC__LocateDefinitionSub(Message* msg, SCObject* already_defined, bool DisplayOnly);

Message* SC_AC__Log();

Message* SC_AC__MainAct(Message* cmd, SCFile* my_file);

Message* SC_AC__MainActAutoComplete(Message* thg, JB_String* str, Message* cmd);

void SC_AC__ReInit();

Message* SC_AC__ReportBuild(Message* cmd);

Message* SC_AC__ReportBuildOrRestart(Message* cmd, Message* arg);

Message* SC_AC__RespondDefine(Message* msg, Message* s, JB_String* purpose);

void SC_AC__Restart(Message* arg);

void SC_AC__ReturnsWhenPerryClosesUs();

Message* SC_AC__RootTmpComplete(Message* cmd);

Message* SC_AC__TmpAutoComplete(Message* f, JB_String* name, JB_String* type);



// API
int JB_API__Init_();

int JB_API__InitCode_();

void JB_API__NilCallBack(JB_String* ErrorMessage);

bool JB_API__NilHandler();



// Constants
void JB_Constants__AddEscape(byte i, FastString* fs);

int JB_Constants__Init_();

int JB_Constants__InitCode_();

void JB_Constants__InitConstants();

JB_String* JB_Constants__TestJB();



// Linkage
SCBase* SC_Linkage__Collect(Message* node, SCBase* name_space, Message* ErrPlace);

Message* SC_Linkage__conf(JB_String* name);

int SC_Linkage__Init_();

int SC_Linkage__InitCode_();

bool SC_Linkage__Interpreter();

SCBase* SC_Linkage__LinkerSub(Message* node, SCBase* name_space, Message* ErrPlace);

JB_String* SC_Linkage__SyntaxAccess(JB_String* name);



// Macros
int SC_Macros__Init_();

int SC_Macros__InitCode_();



// Math


// MZLab


// Options
void SC_Options__ColorSet(bool Value);

bool SC_Options__Color();

int SC_Options__Init_();

int SC_Options__InitCode_();



// Tk
Message* JB_Tk__AddToOutput(Message* Output, Message* curr, Message* prev, int pos);

void JB_Tk__AddXMLText(Message* XML, JB_String* s, int start, int i);

Message* JB_Tk__BarThings(int Start, Syntax Syx);

Message* JB_Tk__BeforeRelSub(int Start, bool Mode);

bool JB_Tk__CanStatement();

Message* JB_Tk__ChainTemporalRels(Message* FirstThing, Message* opp);

Message* JB_Tk__CloseXML(Message* XML, int i, JB_String* s);

Message* JB_Tk__DecorateThing(Message* R, int Ops);

Message* JB_Tk__DotSub(Syntax fn, int Start, Message* parent);

int JB_Tk__EmbeddedArg(JB_String* close, Message* R, int Flags);

int JB_Tk__EmbeddedCode(JB_String* close, Message* dest, int TmpoFlags);

Message* JB_Tk__ErrorAdd(JB_String* s, Ind Start);

Message* JB_Tk__ErrorAlwaysAdd(JB_String* s, Ind Start);

void JB_Tk__ErrorEvent(int Start, int ExpectedBits, int RealBits);

void JB_Tk__ErrorLetter(int Start);

bool JB_Tk__ExpectEndChar(int start, JB_String* s, bool Expect);

Message* JB_Tk__fAccess(int Start, Message* Parent);

Message* JB_Tk__fAdjectiveOp(int Start, Message* Parent);

Message* JB_Tk__fAdjectiveThing(int Start, Message* Parent);

Message* JB_Tk__fAfterRel(int Start, Message* Parent);

Message* JB_Tk__fArgColon(int Start, Message* Parent);

Message* JB_Tk__fArgOpen(int Start, Message* Parent);

Message* JB_Tk__fArray(int Start, Message* Parent);

Message* JB_Tk__fAsk(int Start, Message* Parent);

Message* JB_Tk__fAskSub(int Start, Message* Parent, Syntax f);

Message* JB_Tk__fAtName(int Start, Message* Parent);

Message* JB_Tk__fAtNamedExp(int Start, Message* Parent);

Message* JB_Tk__fBackTick(int Start, Message* Parent);

Message* JB_Tk__fBAdjectiveOp(int Start, Message* Parent);

Message* JB_Tk__fBAdjectiveThing(int Start, Message* Parent);

Message* JB_Tk__fBeforeRel(int Start, Message* Parent);

Message* JB_Tk__fBeforeRelMinus(int Start, Message* Parent);

Message* JB_Tk__fBinary(int Start, Message* Parent);

Message* JB_Tk__fBracket(int Start, Message* Parent);

Message* JB_Tk__fChar(int Start, Message* Parent);

Message* JB_Tk__fCharSub(int pos, int start, byte find);

Message* JB_Tk__fComment(int Start, Message* Parent);

Message* JB_Tk__fCommentLine(int Start, Message* Parent);

Message* JB_Tk__fDecl(int Start, Message* Parent);

Message* JB_Tk__fDot(int Start, Message* Parent);

Message* JB_Tk__fDotAccess(int Start, Message* Parent);

Message* JB_Tk__fEndOfLine(int Start, Message* Parent);

Message* JB_Tk__fError(int Start, Message* Parent);

Message* JB_Tk__fError2(int Start, Message* Parent);

Message* JB_Tk__fFuncCall(int Start, Message* Parent);

Message* JB_Tk__FillXML(Message* XML, Ind i);

int JB_Tk__FindError(int num);

Message* JB_Tk__fInnerNiceAdj(int Start, Message* Parent);

Message* JB_Tk__FixTRels(Message* self, Message* Last);

Message* JB_Tk__fMsgList(int Start, Message* Parent);

Message* JB_Tk__fNumber(int Start, Message* Parent);

Message* JB_Tk__fOpAsThing(int Start, Message* Parent);

Message* JB_Tk__fOppBracket(int Start, Message* Parent);

Message* JB_Tk__fOppSyx(int Start, Message* Parent);

Message* JB_Tk__fOppSyxNeq(int Start, Message* Parent);

Message* JB_Tk__fOppWord(int Start, Message* Parent);

Message* JB_Tk__fQuestion(int Start, Message* Parent);

Message* JB_Tk__fQuoteLang(int Start, Message* Parent);

Message* JB_Tk__fSDot(int Start, Message* Parent);

Message* JB_Tk__fShebang(int Start, Message* Parent);

Message* JB_Tk__fStatement(int Start, Message* Parent);

Message* JB_Tk__fStatementColon(int Start, Message* Parent);

Message* JB_Tk__fString(int Start, Message* Parent);

Message* JB_Tk__fSuperStr(int Start, Message* Parent);

Message* JB_Tk__fSyntacticComment(int Start, Message* Parent);

Message* JB_Tk__fTemporalHashThing(int Start, Message* Parent);

Message* JB_Tk__fTemporalRel(int Start, Message* Parent);

Message* JB_Tk__fTemporalRelSyx(int Start, Message* Parent);

Message* JB_Tk__fThingSyx(int Start, Message* Parent);

Message* JB_Tk__fThingWord(int Start, Message* Parent);

Message* JB_Tk__fTmp(int Start, int OpFlags, int ThingFlags, Message* parent);

Message* JB_Tk__fTmpPlus(int Start, Message* Parent);

Message* JB_Tk__fTmpSub(Message* result, int OpFlags, int ThingFlags);

Message* JB_Tk__fTypeCast(int Start, Message* Parent);

Message* JB_Tk__fURL(int Start, Message* Parent);

Message* JB_Tk__fXML(int Start, Message* Parent);

Message* JB_Tk__fXML_Comment(int Start, Message* Parent);

Message* JB_Tk__fXML_DocType(int Start, Message* Parent);

Message* JB_Tk__fXML_PI(int Start, Message* Parent);

Message* JB_Tk__fYoda(int Start, Message* Parent);

Message* JB_Tk__GetFuncAfter(Message* result);

Message* JB_Tk__IndentBug(Message* curr);

void JB_Tk__Init();

int JB_Tk__Init_();

int JB_Tk__InitCode_();

Message* JB_Tk__LoweredIndent(Message* output, Message* curr);

Message* JB_Tk__MakeInvisArg(Message* tmp, int indent);

Message* JB_Tk__MakeRel(Message* first, int Bits);

int JB_Tk__MessageErrorSub(FastString* fs, int num, int ButFound);

bool JB_Tk__NeedName(Message* thg);

Message* JB_Tk__NewParentName(Message* Parent, Syntax Func, int Start, JB_String* name);

Message* JB_Tk__NewParent(Message* Parent, Syntax Func, int Start, int End);

Message* JB_Tk__NewEmpty(Message* P, Syntax F, int Start, int After);

Message* JB_Tk__NewSkip(Message* P, Syntax F, int Start, int NameStart, int NameEnd);

Message* JB_Tk__NewWord(Message* P, Syntax F, int Start, int SearchFrom);

ParserLineAndIndent JB_Tk__NextLineAndIndent(Message* parent);

bool JB_Tk__NoFuncAfter(byte b);

Message* JB_Tk__NumberSub(int Start, int RealStart);

int JB_Tk__NumEnd(JB_String* NumStr, int Start);

bool JB_Tk__OK();

Message* JB_Tk__OppChain(Message* opp);

void JB_Tk__Params(Message* Parent, int N);

Message* JB_Tk__ParseItem(Message* ch, int TemporalFlags, int ops);

int JB_Tk__ParseLoop(Message* Output, int TmpoFlags);

bool JB_Tk__ParseLoopFlags(Message* Output, JB_String* Ender, int TmpoFlags);

Message* JB_Tk__ParseLoopItem(Message* Output, int TmpoFlags, Message* Prev, int Indent);

Message* JB_Tk__PostInnerAdj(Message* Rel, Message* opp);

Message* JB_Tk__ProcessThing(int Ops, bool Expect);

Message* JB_Tk__ProcessThingNoBar(int Ops, bool Expect);

Message* JB_Tk__ProcessThingOrTmp(int opps);

Message* JB_Tk__ProcessThingParent(Message* parent, int Ops, int ThingFlags);

Message* JB_Tk__ProcessThingSub(Message* Parent, int Ops, int KindOfThing, bool Expect);

Message* JB_Tk__ReRoute(Message* output, Message* cnj, Message* f);

void JB_Tk__StopParse();

void JB_Tk__TokensFn(Array* arr, int bits, ParseHandler func);

void JB_Tk__TokensHan(Array* arr, TokHan* H);

void JB_Tk__TokenzFn(JB_String* s, int bits, ParseHandler func);

Message* JB_Tk__UnexpectedSyntax(Message* bad);

Message* JB_Tk__UnTmpPlace(Message* R);

bool JB_Tk__WillEnd();

int JB_Tk__WordAfter(int Start);

int JB_Tk__XMLAttribs(Message* XML, int start);

Message* JB_Tk__XMLWhatever(int s, int skip, JB_String* ender, Syntax fn);



// Pipe
bool JB_Pipe__StdOutIsTerminal();



// Platform
bool JB_Platform__CPU_ARM();

bool JB_Platform__CPU_Intel();

JB_String* JB_Platform__CPU_Name();

bool JB_Platform__CPU_PPC();

bool JB_Platform__CPU_Spd();

int JB_Platform__Init_();

int JB_Platform__InitCode_();

bool JB_Platform__linux();

void JB_Platform__Log(JB_String* s);

void JB_Platform__OpenLog(JB_String* name);

bool JB_Platform__OSX();

int JB_Platform__PointerBytes();

bool JB_Platform__windows();



// ProT


// SC_API
void SC_SC_API__DelayedClassAPI(Message* node, JB_String* proj);

void SC_SC_API__NewAPI(Message* api, JB_String* part, SCBase* parent, JB_String* proj);

SCBase* SC_SC_API__NewExportAPI(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_SC_API__NewExportAPISub(Message* node, SCObject* parent);



// Errors
bool SC_Errors__AlreadyIgnored(Message* F);

int SC_Errors__Init_();

int SC_Errors__InitCode_();

bool SC_Errors__SyntaxAccess(JB_Error* Err);



// Sav
void SC_Sav__BugWorkAround();

void SC_Sav__Test();



// SCGame3D
int SC_SCGame3D__Init_();

int SC_SCGame3D__InitCode_();

SCBase* SC_SCGame3D__Love(Message* node, SCBase* name_space, Message* ErrPlace);

bool SC_SCGame3D__NeedShader(JB_String* Name);

SCBase* SC_SCGame3D__NeuModel(Message* node, SCBase* name_space, Message* ErrPlace);



// SC
int SC__Init_();

int SC__InitCode_();



// Refs
void SC_Refs__Destructable(Message* Blocker, Message* arg, Message* name);

bool SC_Refs__ExitHitsOrGoesPast(Message* msg, Message* arg);

bool SC_Refs__ExprNeedsTemping(Message* child, Message* name);

int SC_Refs__Init_();

int SC_Refs__InitCode_();

Message* SC_Refs__LastUsedRefPlace(Message* name, Message* arg);

void SC_Refs__RC_CheckFuncAllocOK(SCFunction* self, Message* dot);

void SC_Refs__RC_DeclArg(SCDecl* AR, SCFunction* fn);

void SC_Refs__RC_DeclInit(Message* dcl, SCFunction* fn, bool IsJustAnArg);

void SC_Refs__RC_IgnoreReturn(Message* msg, bool DoRefs);

bool SC_Refs__RC_NeedsOwnBlock(Message* msg, Message* pp);

void SC_Refs__RC_Rel(Message* rel);

void SC_Refs__RC_RelConstructor(Message* rel);

void SC_Refs__RC_Temps(SCFunction* FN, Message* msg, int Basis);

int SC_Refs__RefBasis(Message* msg, bool SetOnly);

int SC_Refs__RefBasisStruct(Message* msg, bool SetOnly);

void SC_Refs__RefDecr(Message* msg, Message* place);

void SC_Refs__RefDecrEnd(Message* msg, Message* place);

Message* SC_Refs__RefDecrMsg(Message* msg);

Message* SC_Refs__RefDestructorMsg(Message* msg, SCFunction* fn);

void SC_Refs__RefIncr(Message* msg, Message* Place, bool IsJustAnArg);

Message* SC_Refs__RefMsg(Message* msg, JB_String* name, SCFunction* func);

Message* SC_Refs__RefMsg0(JB_String* name, SCFunction* func);

void SC_Refs__RefSafeDecr(Message* msg, Message* place);

bool SC_Refs__RelNeedsRef(Message* msg, Message* first);

void SC_Refs__ReturnHandle(Message* Blocker, Message* arg, Message* name, int Basis);

void SC_Refs__ReturnTempMoveOut(Message* Child, Message* blocker);

void SC_Refs__ReturnTempMoveOutSub(Message* Child, Message* blocker, Message* temp);

Message* SC_Refs__SafeDecrMsg(Message* msg);



// SCSelector
SCBase* SC_SCSelector__Build(Message* node, SCBase* name_space, Message* ErrPlace);

Message* SC_SCSelector__BuildClassCode(JB_String* name, JB_String* type);

void SC_SCSelector__DeclareOneSel(JB_String* sel_name, JB_String* type, Message* place);

Message* SC_SCSelector__FindItems(Message* arg);

bool SC_SCSelector__HasClassStuff(Message* self);

void SC_SCSelector__LoadOneSel(JB_String* sel_name, JB_String* module_name, Message* LoaderPlace, Message* Prms);

SCBase* SC_SCSelector__Neu(Message* node, SCBase* name_space, Message* ErrPlace);



// SCStrings
int SC_SCStrings__Init_();

int SC_SCStrings__InitCode_();



// SCThe
SCBase* SC_SCThe__NewInsertion(Message* node, SCBase* name_space, Message* ErrPlace);



// Targets
int SC_Targets__Init_();

int SC_Targets__InitCode_();

void SC_Targets__SetMsg(Message* thg);

void SC_Targets__Set(JB_String* name);

bool SC_Targets__SyntaxAccess(JB_String* name);



// Terminal
JB_String* JB_Terminal__Flat();

int JB_Terminal__Init_();

int JB_Terminal__InitCode_();



// TextAssembler
void SC_TextAssembler__assemble(Message* msg);

int SC_TextAssembler__Init_();

int SC_TextAssembler__InitCode_();

void SC_TextAssembler__TextData(Message* msg);

bool SC_TextAssembler__TextFunc(Message* msg);



// Ext
bool SC_Ext__AllowedThisFile(JB_String* name);

bool SC_Ext__BackupCompiler();

JB_String* SC_Ext__BackupPath();

bool SC_Ext__CanCompile(JB_String* name);

bool SC_Ext__Clean();

void SC_Ext__ClearThis();

bool SC_Ext__CollectAndCompile(JB_File* Input, JB_String* Output);

Array* SC_Ext__CollectCppsInto(JB_File* Fol, JB_File* Objects, int* stdafx);

JB_File* SC_Ext__CppLib();

Array* SC_Ext__CreateCompileString(Array* CppList, JB_String* Product, JB_String* Type);

bool SC_Ext__ExecuteGCC(Array* Commands);

Array* SC_Ext__FilterCppsIfAlreadyDone(Array* Cpps, JB_File* Objects, int* stdafx);

int SC_Ext__Init_();

int SC_Ext__InitCode_();

void SC_Ext__InstallCompiler();

void SC_Ext__InstallOne(JB_File* test);

bool SC_Ext__IsCompilerAndNeedsInstall();

JB_String* SC_Ext__LibSuff();

JB_String* SC_Ext__LibTmpPath();

JB_File* SC_Ext__LinkOK(JB_File* p);

JB_String* SC_Ext__LogName();

void SC_Ext__MacBothArch(Array* r);

JB_String* SC_Ext__MakeDailyProductPath(JB_File* B);

void SC_Ext__MakeLib();

int SC_Ext__NeedNewObjForSrc(JB_String* cpp, JB_File* objects);

int SC_Ext__NoGoodObject(JB_String* Cpp, JB_File* h, JB_File* o);

JB_String* SC_Ext__ProductName();

JB_String* SC_Ext__ProductPath();

JB_String* SC_Ext__ProductSuffix();

JB_String* SC_Ext__ProjTmpPath();

void SC_Ext__ReplaceOld(JB_File* input, JB_File* Backs);

void SC_Ext__RunCppCompile();

void SC_Ext__saytest(int n);

bool SC_Ext__ShouldTransComp();

bool SC_Ext__TestNewCompiler();

JB_String* SC_Ext__TmpBase(JB_String* V);

JB_String* SC_Ext__TmpErr(JB_String* V);

JB_String* SC_Ext__TmpOut(JB_String* V);

void SC_Ext__TransComp();

bool SC_Ext__TransCompile(Array* Files, JB_String* Dest, JB_String* Type);

bool SC_Ext__UseAndCompile(Array* Input, JB_String* Output);



// TreeAssembler
void SC_TreeAssembler__BuildPack();

Array* SC_TreeAssembler__CollectFuncs(JB_String* exp);

int SC_TreeAssembler__Init_();

void SC_TreeAssembler__InitAll();

int SC_TreeAssembler__InitCode_();

void SC_TreeAssembler__Stamp(SCFunction* fn);

void SC_TreeAssembler__StampAll(Array* Funcs);

ASMFunc* SC_TreeAssembler__AccessStr(Message* m);



// VM_Builder
xC2xB5Form* SC_VM_Builder__AddForm(Message* form);

bool SC_VM_Builder__BuildFiles();

void SC_VM_Builder__BuildInstructions(Message* mu);

void SC_VM_Builder__Clean(Message* msg);

Message* SC_VM_Builder__DataTypeCreate(Message* form, int fnum);

void SC_VM_Builder__DataTypeModule();

Array* SC_VM_Builder__DefineGet(JB_String* fname, int up, int down, bool last);

void SC_VM_Builder__DefineGetSub(JB_String* fname, int up, int down, byte c, byte c2);

void SC_VM_Builder__FillTypePrm(JB_String* fname, int pname);

int SC_VM_Builder__GenAcc(Message* line, int bit_pos, int pname);

void SC_VM_Builder__GenerateForms(Message* forms);

void SC_VM_Builder__GenerateOne(Message* form_msg, int f);

int SC_VM_Builder__Init_();

int SC_VM_Builder__InitCode_();

JB_File* SC_VM_Builder__InstructionList(JB_String* ch);

void SC_VM_Builder__MakeJump(Message* msg, FastString* jump);

void SC_VM_Builder__MakeVM(Message* tmp, FastString* vm);

void SC_VM_Builder__Run();

void SC_VM_Builder__VMCpp(FastString* vm, FastString* jump);

void SC_VM_Builder__VMDecl(Message* tmp);

void SC_VM_Builder__VMLine(Message* line, FastString* vm);

void SC_VM_Builder__VMSpd(Message* list);

void SC_VM_Builder__VMTmp(Message* tmp);



// zalgo
int JB_zalgo__Init_();

int JB_zalgo__InitCode_();



// main
void SC___junktest_1__();

void SC___junktest_2__();

bool SC___junktest_3__(IntRange data);

void SC_AddToStaticSection(Message* arg, Message* ToAdd);

int SC_ArrayInOrderCheck(int InOrder, Message* msg);

bool SC_CanOpCompare(Message* exp, SCDecl* lc, SCDecl* rc, SCOperator* comp);

void SC_ClassLinkageTable_cpp_class(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_cpp_part(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_cpp_wrapper(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_datatype(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_dontdestructlocally(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_ignore(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_noearlyfree(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_numeric(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_visible(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_wrapper(SCFunction* fn, Message* node, SCBase* name_space);

SCClass* SC_ClassOfObjForC(Message* curr);

SCBase* SC_ClsCollectTable_linkage(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_ClsCollectTable_pragma(Message* node, SCBase* name_space, Message* ErrPlace);

Array* SC_CollectDecls(Message* DeclList, SCBase* Name_Space, SCBase* AddToSpace, int PropertyMode);

bool JB_CompareError(Message* expected, Message* found);

SCDecl* SC_CopyDecl(Message* CopyFrom, JB_String* name);

void SC_CppRefTable_disowns(SCFunction* fn, Message* node, SCBase* name_space);

void SC_CppRefTable_disturbs(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Create_JeeboxTest(Message* msg);

SCDecl* SC_CustomFuncOp(Message* exp, SCOperator* comp, SCBase* name_space, Message* RN);

SCDecl* SC_DeclOfObjForC(Message* curr);

Message* SC_DeclsDefault(Message* def);

void SC_DefaultStitch(Message* Default, Message* args);

SCBase* SC_DontRemove(Message* node, SCBase* name_space, Message* ErrPlace);

SCDecl* SC_DoOpCompare(Message* exp, SCDecl* lc, SCDecl* rc, SCOperator* comp, SCBase* name_space);

void SC_DotFuncToNormalFunc(Message* dot, SCFunction* fn);

JB_String* JB_EntityTest();

Message* SC_ExpandToBool(Message* inside, SCBase* name_space);

SCObject* SC_ExprFuncs_63(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_ExprFuncs_Back(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_ExprFuncs_Emb(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_ExprFuncs_SDot(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_ExprFuncs_Sheb(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_ExprFuncs_Str(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_ExprFuncs_Type(Message* Exp, SCBase* name_space, Message* side);

bool SC_ExtractAmount(Message* Prms, SCBase* name_space, SCDecl* R);

SCDecl* SC_ExtractDecl(Message* c, SCBase* name_space);

Array* SC_FindAllSyx(Message* msg, Syntax syx);

Message* SC_FindBytePos(Message* Node, bool EndInside);

AsmReg SC_fn_asm_table_acc(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_arel(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_arg(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_bra(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_brel(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_decl(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_func(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_list(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_num(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_rel(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_thg(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_tmp(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_type(ASMFuncState* self, Message* exp, AsmReg Reg);

void SC_FuncLinkageTable_cpp_part(SCFunction* fn, Message* node, SCBase* name_space);

void SC_FuncLinkageTable_cpp_wrapper(SCFunction* fn, Message* node, SCBase* name_space);

void SC_FuncLinkageTable_ignore(SCFunction* fn, Message* node, SCBase* name_space);

void SC_FuncLinkageTable_inline(SCFunction* fn, Message* node, SCBase* name_space);

void SC_FuncLinkageTable_visible(SCFunction* fn, Message* node, SCBase* name_space);

bool SC_funcsorter_fn(JB_Object* a, JB_Object* b);

int JB_Init_();

int JB_InitCode_();

SCDecl* SC_IsPointerMath(SCDecl* L, SCDecl* R, SCOperator* opp, Message* exp);

Message* SC_IsSelfOfSetter(Message* curr);

JB_String* JB_Join2(Array* R, JB_String* sep);

void SC_ListFunctionsSub(JB_Object* o, Array* rz);

Array* SC_ListModules(Dictionary* access);

SCDecl* SC_LowlevelArrayTransform(Message* exp, SCClass* Cls);

Message* SC_MakeDecl(JB_String* Type, JB_String* Name, Message* Value);

Message* SC_MakeDeclOrRel(Message* Into, Message* namemsg, Message* value);

void SC_MatchBase();

void SC_MoveFutureStaticsIn(Message* msg);

Message* SC_NewDeclWithStrStr(JB_String* type, JB_String* name);

Message* SC_NewDeclWithStrMsg(JB_String* type, Message* RelOrName);

Message* SC_NewDeclNum(SCDecl* D, int64 N, JB_String* VarName);

Message* SC_NewFnc(JB_String* name);

Message* SC_NewRelStr(JB_String* L, JB_String* op, JB_String* R);

Message* SC_NewRel(Message* L, JB_String* op, Message* R);

SCDecl* SC_Or_And_Expansion(SCDecl* LC, SCDecl* RC, Message* exp, SCBase* name_space);

void SC_ParamsFail(SCFunction* f, SCParamArray* params);

void JB_Obj_Print(JB_Object* o);

void JB_PrintLine(JB_String* data);

void JB_Obj_PrintLine(JB_Object* o);

JB_String* SC_ProjName();

void SC_RelSetOrExpansion(Message* exp);

SCBase* SC_RootCollectTable_const(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_RootCollectTable_crash(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_RootCollectTable_extends(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_RootCollectTable_static(Message* node, SCBase* name_space, Message* ErrPlace);

SCDecl* SC_SameTypeSub(Message* first, Message* second, SCBase* name_space);

void SC_SC_MakeComment(Message* msg);

int SC_SelfKindaUse(Message* curr);

Message* SC_SettingAProperty(Message* Rel);

bool SC_SettingMemory(Message* Rel);

bool SC_SettingSelfProperty(Message* Rel);

Array* SC_SortInitOrder(Array* mods);

bool SC_SortInitOrderSub(Array* mods, Array* out);

ErrorInt Speedie_Main(_cstring* args, int Mode);

Message* SC_SpellOutMsg(Message* type, Message* Exp, Message* namemsg);

void SC_TemporalStatements_alert(SCFunction* fn, Message* node, SCBase* name_space);

void SC_TemporalStatements_break(SCFunction* fn, Message* node, SCBase* name_space);

void SC_TemporalStatements_crash(SCFunction* fn, Message* node, SCBase* name_space);

void SC_TemporalStatements_do(SCFunction* fn, Message* node, SCBase* name_space);

void SC_TemporalStatements_ignore(SCFunction* fn, Message* node, SCBase* name_space);

bool JB_TestCasting();

bool SC_TooManyErrors();

void SC_Tran_ArgArray(Message* Exp, SCBase* name_space);

void SC_Tran_Msg(SCFunction* fn, Message* Exp, SCBase* name_space);

void SC_Tran_MsgList(SCFunction* fn, Message* Exp, SCBase* name_space);

SCObject* SC_TypeCastCheck(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfAccess(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfAddress(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfAdj(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfARel(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfArgArr(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfArr(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfBlock(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfBra(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfBRel(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfChar(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfDot(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfDotDotDot(Message* Exp, SCBase* name_space, Message* side);

SCDecl* SC_TypeOfExpr(Message* Exp, SCBase* name_space, Message* side);

SCDecl* SC_TypeOfExprMaybeNil(Message* Exp, SCBase* name_space);

SCDecl* SC_TypeOfExprModulesNotOK(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfExprModulesOK(Message* Exp, SCBase* name_space, Message* side);

SCDecl* SC_TypeOfExprNeeded(Message* exp, SCBase* name_space);

SCObject* SC_TypeOfExprSub(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfExprSub2(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfFunc(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfFuncSub(Message* exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfLast(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfList(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfMsg(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfNum(Message* Exp, SCBase* name_space, Message* side);

SCDecl* SC_TypeOfPointerAccess(SCDecl* ty0);

SCObject* SC_TypeOfQues(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfRel(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfSthg(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfString(Message* Exp, SCBase* name_space, Message* side);

SCDecl* SC_TypeOfSwizzle(Message* Exp, SCDecl* Type, SCBase* name_space, Message* side, int swiz);

SCDecl* SC_TypeOfSyntaxCall(Message* exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfSyx(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfTernary(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfThg(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfThgSub(Message* Exp, SCBase* name_space, Message* side, bool AllowAny);

SCObject* SC_TypeOfUnit(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfURL(Message* Exp, SCBase* name_space, Message* side);

SCDecl* SC_TypeOfVecAccess(Message* index, SCDecl* ty0, int w);

int SC_UniqueNum();

JB_String* SC_UniqueTmpVar(SCBase* base, JB_String* name);

int SC_UseCustomOperators(SCDecl* LC, SCDecl* RC, SCOperator* Comp, Message* ErrPlace);

SCClass* SC_VecType(bool isfloat, int count);

void JB_ZalgoLine(JB_String* data);



// _void


// _voidptr


// atomic_byte


// atomic_int


// atomic_uint


// bool
int JB_bool_OperatorSign(bool self, int i);

JB_String* JB_bool_Render0(bool self);



// byte
bool JB_byte_CanPrintAsNormalChar(byte self);

bool JB_byte_In(byte self, uint a, uint b);

bool JB_byte_IsHex(byte self);

bool JB_byte_IsInt(byte self);

bool JB_byte_IsLetter(byte self);

bool JB_byte_IsLower(byte self);

bool JB_byte_IsUpper(byte self);

bool JB_byte_IsWhite(byte self);

byte JB_byte_LowerCase(byte self);

JB_String* JB_byte_Render(byte self, FastString* fs_in);

byte JB_byte_UpperCase(byte self);



// char


// cstring


// ErrorFlags


// ErrorSeverity
JB_String* JB_ErrorSeverity_Render(ErrorSeverity self, FastString* fs_in);

bool JB_ErrorSeverity_SyntaxIs(ErrorSeverity self, ErrorSeverity e);

int JB_ErrorSeverity__Init_();

int JB_ErrorSeverity__InitCode_();



// f64
int64 JB_dbl_AsInt(double self);

JB_String* JB_dbl_Render(double self, JB_String* fmt, FastString* fs_in);



// float
JB_String* JB_f_pc(float self, FastString* fs_in);

float JB_f_powow(float self, int n);



// hfloat


// int
int JB_int___junktest_8__(int self, int Inaaaadex, bool Create);

int JB_int_bits(int self);

bool JB_int_IsNormalMatch(int self);

bool JB_int_IsSimpleOrPointerCast(int self);

int JB_int_OperatorAlign(int self, int To);

inline bool JB_int_OperatorInRange(int self, int d);

bool JB_int_OperatorIsa(int self, uint n);

int JB_int_OperatorMax(int self, int other);

int JB_int_OperatorMin(int self, int other);

JB_String* JB_int_operatorpc(int self, int x);

IntRange JB_int_OperatorTo(int self, int other);

AsmReg JB_int_Reg(int self);

JB_String* JB_int_RenderFS(int self, FastString* fs_in);

JB_String* JB_int_RenderSize(int self, FastString* fs_in);

bool JB_int_SyntaxAccess(int self, int bit);

int JB_int_SyntaxAccessSet(int self, int bit, bool Value);

int JB_int__max();

int JB_int__min();



// int16


// int64
int64 JB_int64_abs(int64 self);

double JB_int64_AsFloat(int64 self);

inline bool JB_int64_OperatorInRange(int64 self, int64 d);

int64 JB_int64_OperatorMax(int64 self, int64 d);

int64 JB_int64_OperatorRotl(int64 self, int Amount);

JB_String* JB_int64_Render(int64 self, FastString* fs_in);

void JB_int64_RenderSizePart(int64 self, FastString* fs, int Size, JB_String* Suff);

JB_String* JB_int64_strsize(int64 self, FastString* fs_in);



// int8


// ivec2


// ivec3


// ivec4
ivec4 JB_ivec4___junktest_4__Set(ivec4 self, int Value);



// MaybeBool
bool JB_MaybeBool_Default(MaybeBool self);

bool JB_MaybeBool_IsKnown(MaybeBool self);

MaybeBool JB_MaybeBool__New(bool Default);



// ObjCID


// PID_Int


// SCBaseInfo


// SCBaseType
bool SC_SCBaseType_SyntaxIs(SCBaseType self, SCBaseType d);



// SizeInt


// Syntax
void JB_Syx_ExportAddrSet(Syntax self, fpMsgRender Value);

fpMsgRender JB_Syx_ExportAddr(Syntax self);

bool JB_Syx_ListViewable(Syntax self);

JB_String* JB_Syx_LongName(Syntax self);

Message* JB_Syx_Msg(Syntax self, JB_String* name);

Message* JB_Syx_ParentMsg(Syntax self, Message* parent, JB_String* name);

Message* JB_Syx_IntMsg(Syntax self, int64 name);

JB_String* JB_Syx_Name(Syntax self);

SyntaxObj* JB_Syx_Obj(Syntax self);

Message* JB_Syx_OperatorPlus(Syntax self, JB_String* m);

Message* JB_Syx_PlusNum(Syntax self, int m);

fpMsgRender JB_Syx_RenderAddr(Syntax self);

bool JB_Syx_Translateable(Syntax self);

int JB_Syx__Init_();

int JB_Syx__InitCode_();

Syntax JB_Syx__StdNew(fpMsgRender msg, JB_String* name, JB_String* LongName);



// TerminalColor


// uint


// uint16


// uint64
inline int JB_uint64_lelength(uint64 self);

ivec2 JB_uint64_LongestBitStretch(uint64 self);

uint64 JB_uint64_LowestBit(uint64 self);



// vec2


// vec3


// vec4


// µParam
uint SC_xC2xB5Param_BitSize(ASMParam self);

bool SC_xC2xB5Param_IsNumber(ASMParam self);

bool SC_xC2xB5Param_IsReg(ASMParam self);



// __junktest_7__
inline uint64 SC_TM_ClearBit(__junktest_7__ self, uint64 i);



// Codepoint
bool JB_CP_In(Codepoint self, int a, int b);

bool JB_CP_IsHigher(Codepoint self);

bool JB_CP_IsLetter(Codepoint self);

bool JB_CP_IsLower(Codepoint self);

bool JB_CP_IsUpper(Codepoint self);

bool JB_CP_IsWhite(Codepoint self);



// ControlLine


// ControlPoint


// ControlRect


// DataTypeCode
int JB_TC__Shift(DataTypeCode self);

SCClass* JB_TC_better_numeric_sub(DataTypeCode self, DataTypeCode t);

int JB_TC_ByteSize(DataTypeCode self);

int JB_TC_Count(DataTypeCode self);

SCClass* JB_TC_CreateSignedStuff(DataTypeCode self);

bool JB_TC_ExistsButBadlyNamedOrDesigned(DataTypeCode self);

int JB_TC_FloatIntMerge(DataTypeCode self, int old, Message* s);

bool JB_TC_IsFloat(DataTypeCode self);

bool JB_TC_IsInt(DataTypeCode self);

bool JB_TC_IsSigned(DataTypeCode self);

int JB_TC_ItemBitCount(DataTypeCode self);

int JB_TC_NumericCount(DataTypeCode self);

int JB_TC_NumericCountBoolsToo(DataTypeCode self);

bool JB_TC_SameBasicType(DataTypeCode self, DataTypeCode b);

DataTypeCode JB_TC_SetSigned(DataTypeCode self, bool b);

bool JB_TC_SyntaxIsnt(DataTypeCode self, DataTypeCode M);

Dictionary* JB_TC__Types();



// Date
Date JB_Date_ago(Date self);

int JB_Date_DayOfWeek(Date self);

int64 JB_Date_Days(Date self);

JB_String* JB_Date_Render(Date self, FastString* fs_in);

JB_String* JB_Date_RenderDurr(Date self, FastString* fs_in);

double JB_Date_Seconds(Date self);

int64 JB_Date_WholeSeconds(Date self);

Date JB_Date__New0();



// ErrorInt
inline bool JB_ErrorInt_SyntaxCast(ErrorInt self);



// FileMode


// Ind
inline bool JB_Ind_SyntaxCast(Ind self);



// IntRange
bool JB_Rg_Contains1(IntRange self, int i);

int JB_Rg_Width(IntRange self);



// IPCState
inline bool JB_IPCState_SyntaxCast(IPCState self);



// JSM


// MsgUIFlags


// SCDeclInfo
SCDeclInfo SC_SCDeclInfo_Set(SCDeclInfo self, SCDeclInfo d, bool b);



// U24_8


// ASM
ASM SC_ASM_BFLD_downSet(ASM self, uint Value);

ASM SC_ASM_BFLD_signSet(ASM self, uint Value);

ASM SC_ASM_BFLD_upSet(ASM self, uint Value);

ASM SC_ASM_Bra_c1Set(ASM self, uint Value);

ASM SC_ASM_Bra_jmpSet(ASM self, uint Value);

ASM SC_ASM_Cmp_CmpSet(ASM self, uint Value);

ASM SC_ASM_Cmp_LSet(ASM self, uint Value);

ASM SC_ASM_CmpEq_bytesSet(ASM self, uint Value);

ASM SC_ASM_CmpEq_JmpSet(ASM self, uint Value);

ASM SC_ASM_CNTC_cnstSet(ASM self, uint Value);

ASM SC_ASM_CNTC_LSet(ASM self, uint Value);

ASM SC_ASM_CNTC_sizeSet(ASM self, uint Value);

ASM SC_ASM_CNTR_incrSet(ASM self, uint Value);

ASM SC_ASM_CNTR_LSet(ASM self, uint Value);

ASM SC_ASM_CNTR_sizeSet(ASM self, uint Value);

ASM SC_ASM_Const_LSet(ASM self, uint Value);

ASM SC_ASM_Const_rotSet(ASM self, uint Value);

ASM SC_ASM_Func_JUMPSet(ASM self, uint Value);

ASM SC_ASM_Func_ModeSet(ASM self, uint Value);

ASM SC_ASM_Mem_incrSet(ASM self, uint Value);

ASM SC_ASM_Mem_LSet(ASM self, uint Value);

void ASMPrint(ASM self);

ASM SC_ASM_r1Set(ASM self, uint Value);

ASM SC_ASM_r2Set(ASM self, uint Value);

ASM SC_ASM_r3Set(ASM self, uint Value);

ASM SC_ASM_r4Set(ASM self, uint Value);

ASM SC_ASM_Setn_CondSet(ASM self, uint Value);

ASM SC_ASM_Setn_DestSet(ASM self, uint Value);

ASM SC_ASM_Setn_LSet(ASM self, uint Value);

ASM SC_ASM_Setn_lenSet(ASM self, uint Value);

ASM SC_ASM_SWAP_ASet(ASM self, uint Value);

ASM SC_ASM_SWAP_BSet(ASM self, uint Value);

ASM SC_ASM_SWAP_CSet(ASM self, uint Value);

ASM SC_ASM_SWAP_DSet(ASM self, uint Value);

ASM SC_ASM_SWAP_LSet(ASM self, uint Value);

ASM SC_ASM_U0_LSet(ASM self, uint Value);

ASM SC_ASM_U1_LSet(ASM self, uint Value);

ASM SC_ASM_U2_LSet(ASM self, uint Value);

ASM SC_ASM_U3_LSet(ASM self, uint Value);

ASM SC_ASM_U4_LSet(ASM self, uint Value);

void SC_ASM__Enc1();

void SC_ASM__Init();

int SC_ASM__Init_();

int SC_ASM__InitCode_();

void SC_ASM__ListInstructions();

bool SC_ASM__Needed();

void SC_ASM__SelfTestASM(Message* tests);

void SC_ASM__TestASM();



// ASM_BFLD
ASM JB_ASM_BFLD__Encode(IR* self);



// ASM_Bra
ASM JB_ASM_Bra__Encode(IR* self);



// ASM_Cmp
ASM JB_ASM_Cmp__Encode(IR* self);



// ASM_CmpEq
ASM JB_ASM_CmpEq__Encode(IR* self);



// ASM_CNTC
ASM JB_ASM_CNTC__Encode(IR* self);



// ASM_CNTR
ASM JB_ASM_CNTR__Encode(IR* self);



// ASM_Const
ASM JB_ASM_Const__Encode(IR* self);



// ASM_Func
ASM JB_ASM_Func__Encode(IR* self);



// ASM_Mem
ASM JB_ASM_Mem__Encode(IR* self);



// ASM_Setn
ASM JB_ASM_Setn__Encode(IR* self);



// ASM_SWAP
ASM JB_ASM_SWAP__Encode(IR* self);



// ASM_U0
ASM JB_ASM_U0__Encode(IR* self);



// ASM_U1
ASM JB_ASM_U1__Encode(IR* self);



// ASM_U2
ASM JB_ASM_U2__Encode(IR* self);



// ASM_U3
ASM JB_ASM_U3__Encode(IR* self);



// ASM_U4
ASM JB_ASM_U4__Encode(IR* self);



// ASM_Decoder2


// ASM_Encoder2


// autosort_fn


// CollectFunc


// ExprResolver


// fn_app_DeathAction


// fn_asm
AsmReg SC_fn_asm__default(ASMFuncState* self, Message* exp, AsmReg Reg);

void SC_fn_asm__InitTable();



// fn_OpASM


// fn_pth_wrap


// fn_subprocess


// fnErrorLogger


// fpDestructor


// fpMsgRender


// fpMsgRenderCpp


// ParseHandler


// SaverLoadClass


// ShellOption


// SorterComparer


// TokenHandler_fp


// TranFunc


// __LoadProperties__


// __SaveCollect__


// __SaveWrite__


// __Render__


// __copyid__


// __text__


// __textset__


// JB_ArgArrayCounter
void SC_ArgArrayCounter_check(ArgArrayCounter* self, Message* exp);

Message* SC_ArgArrayCounter_Do(ArgArrayCounter* self, JB_String* name, Message* item, SCBase* name_space);



// JB_asdas


// JB_asdas2
void SC_asdas2_hhh(asdas2* self);



// JB_ASMFuncState
inline IR* SC_flat_AddASM(ASMFuncState* self, Message* dbg, int SM, int a, int b, int c, int d);

inline void SC_flat_AddExtended(ASMFuncState* self, Message* err, uint Bits);

void SC_flat_AddFuncParams(ASMFuncState* self, SCFunction* fn);

void SC_flat_AddLabel(ASMFuncState* self, Message* ch);

AsmReg SC_flat_AllocRegDecl(ASMFuncState* self, Message* exp, SCDecl* decl, AsmReg R);

void SC_flat_CloseVars(ASMFuncState* self, uint64 Old);

void SC_flat_destructor(ASMFuncState* self);

AsmReg SC_flat_DoFunc(ASMFuncState* self, Message* prms, AsmReg dest);

AsmReg SC_flat_DoRels(ASMFuncState* self, Message* L, AsmReg dest);

IR* SC_flat_FindLabel(ASMFuncState* self, IR* dbg);

void SC_flat_FinishASM(ASMFuncState* self);

Message* SC_flat_FuncPrms(ASMFuncState* self, Message* pr, int Remain, uint Bits);

uint SC_flat_GetLabelJump(ASMFuncState* self, Message* P);

void SC_flat_InitState(ASMFuncState* self, SCFunction* fn);

IR* SC_flat_Last(ASMFuncState* self);

bool SC_flat_LoadLabelJumps(ASMFuncState* self);

Message* SC_flat_LoadTitle(ASMFuncState* self, Message* m);

void SC_flat_NeedSomewhere(ASMFuncState* self, Message* err, AsmReg* dest, DataTypeCode T);

uint64 SC_flat_OpenVars(ASMFuncState* self);

inline IR* SC_flat_RequestOp2(ASMFuncState* self, uint Code);

IR* SC_flat_RequestOp(ASMFuncState* self);

bool SC_flat_SetConst(ASMFuncState* self, Message* List, Message* Orig);

bool SC_flat_TextFuncSub(ASMFuncState* self, Message* m);

void SC_flat_TextInstruction(ASMFuncState* self, Message* m);

bool SC_flat_TextOp(ASMFuncState* self, Message* m);

void SC_flat_TotalInit(ASMFuncState* self);

bool SC_flat_TrySmallConst(ASMFuncState* self, uint reg, int64 Value, Message* where);

AsmReg SC_flat_Reg(ASMFuncState* self, Message* exp, AsmReg reg);

AsmReg SC_flat_RegSaved(ASMFuncState* self, Message* exp);

int SC_flat__Init_();

int SC_flat__InitCode_();



// JB_AsmReg
inline int SC_Reg_ToInt(AsmReg* self);



// JB_ASMVarType


// JB_ClassData
void JB_ClassData_Restore(JB_Class* self);



// JB_CompressionStats
float JB_MzSt_durr(CompressionStats* self);

void JB_MzSt_len(CompressionStats* self, int n);

void JB_MzSt_liveupdate(CompressionStats* self, JB_String* s, int outt);

JB_String* JB_MzSt_Render(CompressionStats* self, FastString* fs_in);

int JB_MzSt__Init_();

int JB_MzSt__InitCode_();



// JB_FloatRange


// JB_GameFlyingMem


// JB_IntDownRange


// JB_IPCMessage
bool JB_IPCMessage_Closed(IPCMessage* self);

byte* JB_IPCMessage_Data(IPCMessage* self);

bool JB_IPCMessage_IsOpen(IPCMessage* self);



// JB_IR
void SC_IR_AddRegParam(IR* self, Message* src, uint write);

void SC_IR_debugSet(IR* self, Message* Value);

ASM SC_IR_Encode(IR* self);

SCFile* SC_IR_File(IR* self);

Ind SC_IR_FilePos(IR* self);

void SC_IR_fs(IR* self, FastString* fs);

bool SC_IR_OperatorIsa(IR* self, int m);

JB_String* SC_IR_Render(IR* self, FastString* fs_in);

void SC_IR_SyntaxExpect(IR* self, JB_String* Error);



// JB_jb_vm


// JB_MemoryWorld


// JB_MessagePosition
void JB_MsgPos_Destructor(MessagePosition* self);

void JB_MsgPos_SyntaxUsingComplete(MessagePosition* self);



// JB_ModelTest


// JB_NameAndMsg
void SC_NameAndMsg_destructor(NameAndMsg* self);

void SC_NameAndMsg_SyntaxAppend(NameAndMsg* self, Message* m);



// JB_ObjectLoader
void JB_LD_destructor(ObjectLoader* self);

void JB_LD_Finish(ObjectLoader* self);

JB_Class* JB_LD_GetClassOf(ObjectLoader* self, Message* msg);

bool JB_LD_HasItem(ObjectLoader* self);

int64 JB_LD_Int(ObjectLoader* self);

int64 JB_LD_ItemInt(ObjectLoader* self);

bool JB_LD_ItemIsInt(ObjectLoader* self);

JB_String* JB_LD_ItemName(ObjectLoader* self);

JB_Object* JB_LD_ItemObject(ObjectLoader* self);

void JB_LD_LoadClass(ObjectLoader* self, Message* msg, Dictionary* dict);

void JB_LD_LoadForReal(ObjectLoader* self, Message* root, Dictionary* d);

void JB_LD_LoadObject(ObjectLoader* self, Message* msg, Dictionary* dict, JB_Class* Cls);

Message* JB_LD_Next(ObjectLoader* self);

JB_Object* JB_LD_Object(ObjectLoader* self);

JB_Object* JB_LD_ObjectSub(ObjectLoader* self, Message* c);

void JB_LD_Preload(ObjectLoader* self, Message* root, Dictionary* dict);

JB_String* JB_LD_String(ObjectLoader* self);

bool JB_LD_VerifyFormat(ObjectLoader* self, Message* root);

void JB_LD__Init();

void JB_LD__LoadOne(JB_Class* cls, char* Data);



// JB_ObjectSaver
void JB_Saver_AppendInt(ObjectSaver* self, int64 i);

void JB_Saver_AppendObject(ObjectSaver* self, JB_Object* o);

void JB_Saver_AppendString(ObjectSaver* self, JB_String* s);

void JB_Saver_Destructor(ObjectSaver* self);

void JB_Saver_Finish(ObjectSaver* self, Saveable* first);

void JB_Saver__Init();

int JB_Saver__Init_();

int JB_Saver__InitCode_();

void JB_Saver__LoadOne(JB_Class* cls, char* Data);

ObjectSaver JB_Saver__New();



// JB_ParserLineAndIndent


// JB_Random
double JB_Rnd_Double(Random* self);

int64 JB_Rnd_int(Random* self);

void JB_Rnd_LoadProperties(Random* self, ObjectLoader* Loader);

void JB_Rnd_Reseed(Random* self);

void JB_Rnd_SaveWrite(Random* self, ObjectSaver* Saver);

void JB_Rnd_SeedSet(Random* self, uint64 Value);

double JB_Rnd_SyntaxAccess(Random* self);

int JB_Rnd__Init_();

int JB_Rnd__InitCode_();



// JB_RetroFloat


// JB_RingDownRange


// JB_RingRange


// JB_SpeedTester


// JB_StringLengthSplit


// JB_StructSaveTest
void JB_StructSaveTest_destructor(StructSaveTest* self);

void JB_StructSaveTest_LoadProperties(StructSaveTest* self, ObjectLoader* Loader);

void JB_StructSaveTest_SaveWrite(StructSaveTest* self, ObjectSaver* Saver);



// JB_uint24


// JB_Object_Behaviour


// JB_MemoryLayer_Behaviour


// JB_SyntaxObj_Behaviour


// JB_Macro_Behaviour


// JB_StringShared_Behaviour


// JB_SCObject_Behaviour


// JB_SCDecl_Behaviour


// JB_CppRefs_Behaviour


// JB_autoitem_Behaviour


// JB_SCParamArray_Behaviour


// JB_SCIterator_Behaviour


// JB_Cpp_Export_Behaviour


// JB_SCImport_Behaviour


// JB___junktest_6___Behaviour


// JB_µFunc_Behaviour


// JB_SCOperator_Behaviour


// JB_µForm_Behaviour


// JB_SCNodeRenamer_Behaviour


// JB_LeakTester_Behaviour


// JB_StringFields_Behaviour


// JB_Selector_Behaviour


// JB_FastString_Behaviour


// JB_ShellStream_Behaviour


// JB_DictionaryReader_Behaviour


// JB_string_aware_Behaviour


// JB_TokenHandler_Behaviour


// JB_Charset_Behaviour


// JB_StringStream_Behaviour


// JB_Saveable_Behaviour


// JB_ErrorList_Behaviour


// JB_ByteMap_Behaviour


// JB_Process_Behaviour


// JB_DataTypeWrapper_Behaviour


// JB_Memory_Behaviour


// JB_RingTree_Behaviour


// JB_FixedDict_Behaviour


// JB_String_Behaviour


// JB_StringZeroTerminated_Behaviour


// JB_JBin_Behaviour


// JB_Message_Behaviour


// JB_SCBase_Behaviour


// JB_GUIControl_Behaviour


// JB_TreeView_Behaviour


// JB_StretchControl_Behaviour


// JB_TreeViewRow_Behaviour


// JB_TreeViewRoot_Behaviour


// JB_SCModule_Behaviour


// JB_SCClass_Behaviour


// JB_SCArg_Behaviour


// JB_SCFunction_Behaviour


// JB_SavingTest_Behaviour


// JB_MaterialsLol_Behaviour


// JB_SCBehaviour_Behaviour


// JB_FastStringCpp_Behaviour


// JB_µFunc1_Behaviour


// JB_Instruction_Behaviour


// JB_File_Behaviour


// JB_StringThatWasReadSafely_Behaviour


// JB_Array_Behaviour


// JB_String_ArgValue_Behaviour


// JB_FileArchive_Behaviour


// JB_Dictionary_Behaviour


// JB_Error_Behaviour


// JB_SaverClassInfo_Behaviour


// JB_MessageRoot_Behaviour


// JB_config_Behaviour


// JB_SCFile_Behaviour


// JB_Object
inline JB_String* JB_Object___Render__(JB_Object* self, FastString* fs_in);

JB_String* JB_Object_ArgName(JB_Object* self);

JB_String* JB_Object_ArgValue(JB_Object* self);

SCDecl* JB_Object_AsDecl(JB_Object* self);

Array* JB_Object_CollectLeaks_(JB_Object* self);

void jdb(JB_Object* self);

bool JB_Object_HasArgName(JB_Object* self, JB_String* name);

bool JB_Object_MustBe(JB_Object* self, JB_Class* x, Message* ErrNode);

bool JB_Object_FastIsa(JB_Object* self, JB_Class* x);

bool JB_Object_Isa(JB_Object* self, JB_Class* x);

void jbl(JB_Object* self);

void JB_Object_SaveTryCollect(JB_Object* self, ObjectSaver* Saver);

void JB_Object_Fail(JB_Object* self, JB_String* Error);

void JB_Object_SyntaxExpect(JB_Object* self);



// JB___junktest_6__
DTWrap* SC___junktest_6____abcvis();



// JB_autoitem
void SC_autoitem_ConstructorAuto(autoitem* self, JB_String* Sort, JB_String* Insert, SCObject* Value, JB_String* Display, bool Exact, int type);

void SC_autoitem_destructor(autoitem* self);

bool SC_autoitem_OKBy(autoitem* self, autoitem* prev);

autoitem* SC_autoitem__Alloc();

autoitem* SC_autoitem__NewAuto(JB_String* Sort, JB_String* Insert, SCObject* Value, JB_String* Display, bool Exact, int type);



// JB_ByteMap


// JB_Charset
Array* JB_CS_Bytes(CharSet* self);

bool JB_CS_OperatorContains(CharSet* self, JB_String* Data);

CharSet* JB_CS__Alloc();

CharSet* JB_CS__New(JB_String* Chars, bool UseRange);



// JB_Cpp_Export
void SC_Cpp_AppendCppField(Cpp_Export* self, JB_String* prop, FastStringCpp* fs);

void SC_Cpp_AppendPropField(Cpp_Export* self, SCDecl* prop, FastStringCpp* fs);

void SC_Cpp_Codify(Cpp_Export* self, SCModule* scb, JB_String* fName);

void SC_Cpp_CodifyFuncs(Cpp_Export* self, FastStringCpp* file, Array* list);

void SC_Cpp_Constructor(Cpp_Export* self);

void SC_Cpp_destructor(Cpp_Export* self);

void SC_Cpp_DoInterpreter(Cpp_Export* self);

void SC_Cpp_ExportBehaviourHeader(Cpp_Export* self, SCClass* cls);

bool SC_Cpp_ExportBehaviourInstance(Cpp_Export* self, SCClass* cls, FastStringCpp* fs);

void SC_Cpp_ExportClass(Cpp_Export* self, SCClass* cls, FastStringCpp* CppFile);

void SC_Cpp_ExportModuleProperties(Cpp_Export* self, SCModule* modl, FastStringCpp* IntoModule);

bool SC_Cpp_ExportOneProperty(Cpp_Export* self, SCClass* cls, FastStringCpp* fs, JB_String* Only);

void SC_Cpp_ExportOneSyx(Cpp_Export* self, int i, FastStringCpp* fs);

void SC_Cpp_ExportProperties(Cpp_Export* self, SCClass* cls, FastStringCpp* fs, JB_String* Ignore);

void SC_Cpp_ExportStruct(Cpp_Export* self, SCClass* cls, bool IsBehaviour);

void SC_Cpp_ExportSyx(Cpp_Export* self);

void SC_Cpp_FinalMergeOutputIntoACpp(Cpp_Export* self);

void SC_Cpp_Func(Cpp_Export* self, FastStringCpp* fs, SCFunction* F, FastStringCpp* H);

void SC_Cpp_ListAllClasses(Cpp_Export* self, FastStringCpp* fs);

void SC_Cpp_ListAllFuncs(Cpp_Export* self, FastStringCpp* fs);

void SC_Cpp_MakeWrapperFor(Cpp_Export* self, FastStringCpp* fs, SCFunction* f);

void SC_Cpp_OptEnd(Cpp_Export* self, FastStringCpp* fs, int m, bool force);

void SC_Cpp_OptStart(Cpp_Export* self, FastStringCpp* fs, int m, bool force);

void SC_Cpp_PreRun(Cpp_Export* self);

void SC_Cpp_Run(Cpp_Export* self);

FastStringCpp* SC_Cpp_StreamChild(Cpp_Export* self, JB_String* s);

void SC_Cpp_WriteAPIFuncHeader(Cpp_Export* self, SCFunction* F, FastStringCpp* fs);

void SC_Cpp_WriteAPIHeader(Cpp_Export* self, JB_File* destfile);

void SC_Cpp_WriteHeader(Cpp_Export* self);

Cpp_Export* SC_Cpp__Alloc();

JB_File* SC_Cpp__APIHeader();

void SC_Cpp__C_FSListComma(Message* self, FastStringCpp* fs);

bool SC_Cpp__C_OneParamType(FastStringCpp* fs, Message* Curr, SCDecl* D);

void SC_Cpp__C_ParamsRender(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderAcc(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderArg(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderArl(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderBak(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderBra(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderBrl(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderChr(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderDcl(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderDot(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderFnc(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderItem(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderList(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderNum(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderOpp(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderRel(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderShe(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderSStr(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderStr(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderThg(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderTmp(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderTyp(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderUnt(Message* self, FastStringCpp* fs);

JB_String* SC_Cpp__CDotType(Message* msg, SCDecl* Type, FastStringCpp* fs);

JB_String* SC_Cpp__CppLicence();

JB_File* SC_Cpp__CppProduct();

void SC_Cpp__CreateClassListFunc(FastString* dest);

void SC_Cpp__CreateClassListHeader(FastString* fs, JB_String* s);

int SC_Cpp__DontNeedMoreBrackets(Message* msg);

bool SC_Cpp__DoSavers();

void SC_Cpp__ExportAllSource();

void SC_Cpp__GenLub(FastString* fs);

void SC_Cpp__GenStrings(FastString* fs);

JB_File* SC_Cpp__HProduct();

void SC_Cpp__Init();

int SC_Cpp__Init_();

int SC_Cpp__InitCode_();

bool SC_Cpp__MsgOKToImprove(Message* msg);

bool SC_Cpp__NeedsDotForC(SCDecl* d);

Cpp_Export* SC_Cpp__New();

JB_File* SC_Cpp__Product(JB_String* name);

void SC_Cpp__RenderInBracketsIfRel(Message* self, FastStringCpp* fs);

void SC_Cpp__SmartWrite(JB_String* S, JB_File* F);

JB_String* SC_Cpp__SplitCpp(FastStringCpp* fs, JB_String* name);

int SC_Cpp__SyntaxAccess(JB_String* name);

void SC_Cpp__WriteClass(SCClass* C, FastStringCpp* T);

void SC_Cpp__WriteConst(SCDecl* D, FastStringCpp* T);

void SC_Cpp__WriteDecl(SCDecl* D, FastStringCpp* T, Message* equality);

void SC_Cpp__WriteDeclBrackets(Message* self, FastStringCpp* fs);

void SC_Cpp__WriteDeclNoName(SCDecl* D, FastStringCpp* T);

void SC_Cpp__WriteFuncArgs(SCFunction* F, FastStringCpp* T, bool names_only);

void SC_Cpp__WriteFuncSub(SCFunction* F, JB_String* E, FastStringCpp* T);

void SC_Cpp__WriteFunctionHeader(SCFunction* F, FastStringCpp* T);

void SC_Cpp__WriteThgMaybeTypeToo(Message* msg, SCDecl* d, FastStringCpp* fs);

void SC_Cpp__WriteType(SCClass* c, FastStringCpp* fs, bool always);



// JB_CppRefs
void SC_CppRefs_AddOne(CppRefs* self, Message* C);

void SC_CppRefs_Constructor(CppRefs* self, Message* s);

void SC_CppRefs_destructor(CppRefs* self);

void SC_CppRefs_Read(CppRefs* self, Message* node);

void SC_CppRefs_SetDefaultRefStatus(CppRefs* self);

CppRefs* SC_CppRefs__Alloc();

CppRefs* SC_CppRefs__New(Message* s);



// JB_DataTypeWrapper
void JB_Wrap_ConstructorInt(DTWrap* self, int64 v);

void JB_Wrap_Constructor(DTWrap* self, _voidptr p);

void JB_Wrap_Destructor(DTWrap* self);

double JB_Wrap_FloatValue(DTWrap* self);

JB_String* JB_Wrap_Render(DTWrap* self, FastString* fs_in);

int64 JB_Wrap_Value(DTWrap* self);

DTWrap* JB_Wrap__Alloc();

DTWrap* JB_Wrap__NewInt(int64 v);

DTWrap* JB_Wrap__New(_voidptr p);



// JB_DictionaryReader
inline bool JB_DictionaryReader_SyntaxCast(DictionaryReader* self);



// JB_ErrorList
bool JB_Rec_CanAddMore(JB_ErrorReceiver* self, ErrorSeverity level);

void JB_Rec_Clear(JB_ErrorReceiver* self);

void JB_Rec_Constructor(JB_ErrorReceiver* self);

void JB_Rec_destructor(JB_ErrorReceiver* self);

JB_Error* JB_Rec_FirstError(JB_ErrorReceiver* self);

void JB_Rec_incr(JB_ErrorReceiver* self, JB_Error* err, bool add);

void JB_Rec_LogFileSet(JB_ErrorReceiver* self, JB_String* Value);

void JB_Rec_LogFileWriter(JB_ErrorReceiver* self, JB_String* Data);

void JB_Rec_NewErrorWithNode(JB_ErrorReceiver* self, Message* node, JB_String* Desc, JB_String* path);

void JB_Rec_NewItem(JB_ErrorReceiver* self, JB_Error* Err);

void JB_Rec_NewProblem(JB_ErrorReceiver* self, Message* node, JB_String* Desc);

void JB_Rec_NewWarning(JB_ErrorReceiver* self, Message* node, JB_String* Desc);

bool JB_Rec_OK(JB_ErrorReceiver* self);

JB_Error* JB_Rec_Pop(JB_ErrorReceiver* self);

int JB_Rec_PrintErrors(JB_ErrorReceiver* self);

int JB_Rec_PrintErrorsMain(JB_ErrorReceiver* self, ErrorSeverity Level, bool PrintCount, bool shell);

bool JB_Rec_Problems(JB_ErrorReceiver* self);

JB_String* JB_Rec_Render(JB_ErrorReceiver* self, FastString* fs_in);

int JB_Rec_RenderErrors(JB_ErrorReceiver* self, FastString* fs, ErrorSeverity Level, bool shell);

int JB_Rec_ShellPrintErrors(JB_ErrorReceiver* self);

void JB_Rec_SyntaxAppend(JB_ErrorReceiver* self, JB_Error* Err);

JB_ErrorReceiver* JB_Rec_SyntaxUsing(JB_ErrorReceiver* self);

void JB_Rec_SyntaxUsingComplete(JB_ErrorReceiver* self);

JB_ErrorReceiver* JB_Rec__Alloc();

JB_ErrorReceiver* JB_Rec__New();



// JB_FastString
void JB_FS_AppendCpp(FastString* self, JB_String* s);

void JB_FS_AppendCppAll(FastString* self, JB_String* s);

void JB_FS_AppendEscape(FastString* self, JB_String* s);

bool JB_FS_AppendFile(FastString* self, JB_File* f);

void JB_FS_AppendHexStr(FastString* self, JB_String* Data);

void JB_FS_AppendObjectID(FastString* self, Saveable* o);

void JB_FS_AppendObjectOrNil(FastString* self, JB_Object* o);

void JB_FS_AppendWidth(FastString* self, JB_String* s, int Width);

void JB_FS_CArrayAdd(FastString* self, JB_String* s);

void JB_FS_CArrayAddB(FastString* self, byte B);

void JB_FS_CArrayAddB0(FastString* self, byte B);

void JB_FS_EncodeLength(FastString* self, uint64 N);

void JB_FS_AppendInfo(FastString* self, JB_String* name, JB_String* data);

void JB_FS_AppendInfoNum(FastString* self, JB_String* name, int64 data);

void JB_FS_fieldstart(FastString* self, JB_String* name);

void JB_FS_includeh(FastString* self, JB_String* name);

void JB_FS_lInt(FastString* self, uint64 n);

void JB_FS_MsgErrorName(FastString* self, JB_String* name);

void JB_FS_ProblemsFound(FastString* self, int count);

JB_String* JB_FS_Render(FastString* self, FastString* fs_in);

void JB_FS_AppendFastString(FastString* self, FastString* fs);

void JB_FS_AppendInt64(FastString* self, int64 data);

void JB_FS_AppendInt32(FastString* self, int data);

void JB_FS_AppendFloatAsText(FastString* self, float F);

void JB_FS_SyntaxAppend(FastString* self, Message* msg);

inline JB_String* JB_FS_SyntaxCast(FastString* self);

FastString* JB_FS__Alloc();

int JB_FS__Init_();

int JB_FS__InitCode_();

FastString* JB_FS__New();

FastString* JB_FS__NewSize(int size);



// JB_FixedDict


// JB_LeakTester
void JB_Lk_Constructor(LeakTester* self, JB_String* name);

void JB_Lk_destructor(LeakTester* self);

void JB_Lk_FinalTest(LeakTester* self);

void JB_Lk_Test1(LeakTester* self);

void JB_Lk_Test2(LeakTester* self);

LeakTester* JB_Lk__Alloc();

LeakTester* JB_Lk__New(JB_String* name);



// JB_Macro
void JB_Macro_ConstructorStr(Macro* self, JB_String* s);

void JB_Macro_ConstructorMsg(Macro* self, Message* s);

void JB_Macro_destructor(Macro* self);

Message* JB_Macro_Pz(Macro* self);

Message* JB_Macro_SyntaxCall(Macro* self, Array* prms);

Macro* JB_Macro__Alloc();

Macro* JB_Macro__NewStr(JB_String* s);

Macro* JB_Macro__NewMsg(Message* s);



// JB_Memory
void JB_Mrap_ConstructorDummy(MWrap* self, int ItemCount, uint ItemSize, bool DummyParam);

void JB_Mrap_Destructor(MWrap* self);

void JB_Mrap_Free(MWrap* self);

byte* JB_Mrap_Ptr(MWrap* self);

MWrap* JB_Mrap__Alloc();

int JB_Mrap__Init_();

int JB_Mrap__InitCode_();

MWrap* JB_Mrap__NewDummy(int ItemCount, uint ItemSize, bool DummyParam);

MWrap* JB_Mrap__Object(int ItemCount, int ItemSize);



// JB_MemoryLayer


// JB_Process
bool JB_Proc_Alive(Process* self);

bool JB_Proc_CanSend(Process* self);

bool JB_Proc_ChildAlive(Process* self);

bool JB_Proc_Closed(Process* self);

void JB_Proc_Constructor(Process* self, JB_String* name, int n, Array* params, fn_subprocess sub, bool TrapStdOut);

void JB_Proc_Destructor(Process* self);

void JB_Proc_Died(Process* self);

void JB_Proc_Disconnect(Process* self);

void JB_Proc_Flush(Process* self);

bool JB_Proc_Found(Process* self, bool send);

Message* JB_Proc_Get(Process* self, Date TimeOut);

Message* JB_Proc_GetSub(Process* self, Date TimeOut);

bool JB_Proc_IsOpen(Process* self);

void JB_Proc_log(Process* self, JB_String* s);

void JB_Proc_LogMsg(Process* self, JB_String* msg);

void JB_Proc_LogUs(Process* self);

void JB_Proc_OpenSharedMemory(Process* self, int n);

void JB_Proc_Other(Process* self, JB_String* msg, bool strong);

JB_String* JB_Proc_OurName(Process* self, bool us);

bool JB_Proc_ParentAlive(Process* self);

void JB_Proc_RefillOpen(Process* self);

void JB_Proc_Release(Process* self);

JB_String* JB_Proc_Render(Process* self, FastString* fs_in);

JB_String* JB_Proc_ReportConnection(Process* self, JB_String* s, FastString* fs_in);

void JB_Proc_Self(Process* self, JB_String* msg, bool strong);

void JB_Proc_SendCrashed(Process* self);

void JB_Proc_SendSub(Process* self, Message* msg);

void JB_Proc_SetupAdjust(Process* self, int n);

int JB_Proc_SetupAlloc(Process* self, int n);

void JB_Proc_SetupServerState(Process* self);

PID_Int JB_Proc_SideID(Process* self);

bool JB_Proc_Send(Process* self, Message* msg, Date TimeOut);

void JB_Proc_SyntaxExpect(Process* self, JB_String* err);

void JB_Proc_SyntaxIsSet(Process* self, IPCState d, bool Value);

bool JB_Proc_SyntaxIsnt(Process* self, IPCState d);

JB_String* JB_Proc_TheirName(Process* self);

void JB_Proc_Unlink(Process* self);

void JB_Proc_Unmap(Process* self);

void JB_Proc_UpdateStdOut(Process* self);

void JB_Proc_UseDummy(Process* self);

int JB_Proc_Wait(Process* self, int wait);

bool JB_Proc_WaitFor(Process* self, Date TimeOut, bool Send);

void JB_Proc_WriteSub(Process* self);

Process* JB_Proc__Alloc();

int JB_Proc__Init_();

int JB_Proc__InitCode_();

Process* JB_Proc__New(JB_String* name, int n, Array* params, fn_subprocess sub, bool TrapStdOut);

Process* JB_Proc__Parent();

void JB_Proc__StackTraceJbin(FastString* j, JB_String* reason, int skip);

void JB__ProcessReportCrash();



// JB_Saveable
inline void JB_Sav___LoadProperties__(Saveable* self, ObjectLoader* Loader);

inline void JB_Sav___SaveCollect__(Saveable* self, ObjectSaver* Saver);

inline void JB_Sav___SaveWrite__(Saveable* self, ObjectSaver* Saver);

bool JB_Sav_IsSaveMarked(Saveable* self);

void JB_Sav_LoadProperties(Saveable* self, ObjectLoader* Loader);

void JB_Sav_SaveCollect(Saveable* self, ObjectSaver* Saver);

bool JB_Sav_SaveMark(Saveable* self);

SaverClassInfo* JB_Sav_SaverInfo(Saveable* self);

void JB_Sav_SaveToFile(Saveable* self, JB_File* f);

JB_String* JB_Sav_SaveTo(Saveable* self, FastString* fs_in);

void JB_Sav_SaveUnMark(Saveable* self);

void JB_Sav_SaveWrite(Saveable* self, ObjectSaver* Saver);



// JB_SCImport
bool SC_Imp_CanBan(SCImport* self, SCFile* scf);

void SC_Imp_Constructor(SCImport* self, JB_File* F);

void SC_Imp_destructor(SCImport* self);

SCFile* SC_Imp_ImportDir(SCImport* self, JB_File* f, JB_String* Path);

void SC_Imp_ImportMsg(SCImport* self, Message* j);

SCFile* SC_Imp_ImportSpd(SCImport* self, JB_File* c, JB_String* CurrPath);

void SC_Imp_IncludeCHeaders(SCImport* self, JB_File* f, Array* output);

void SC_Imp_LoadBanned(SCImport* self, Message* list);

void SC_Imp_LoadPrefix(SCImport* self, SCFile* scf, int depth);

void SC_Imp_PrepareAll(SCImport* self);

void SC_Imp_ReloadImports(SCImport* self);

JB_String* SC_Imp_Render(SCImport* self, FastString* fs_in);

void SC_Imp_Use(SCImport* self);

SCImport* SC_Imp__Alloc();

void SC_Imp__ExportShaders();

JB_File* SC_Imp__FindInputFolder(JB_File* f);

void SC_Imp__ImportPath(JB_String* path, JB_File* f, int ImportDepth);

int SC_Imp__Init_();

int SC_Imp__InitCode_();

bool SC_Imp__IsInputName(JB_String* name);

SCImport* SC_Imp__New(JB_File* F);

void SC_Imp__NoProj();



// JB_SCNodeRenamer
void SC_NR_Collect(SCNodeRenamer* self, Message* msg, JB_String* name, Message* after);

void SC_NR_CollectDclThg(SCNodeRenamer* self, Message* DclThg);

void SC_NR_CollectSelfs(SCNodeRenamer* self, Message* root);

void SC_NR_Constructor(SCNodeRenamer* self);

void SC_NR_destructor(SCNodeRenamer* self);

void SC_NR_Rename(SCNodeRenamer* self, Message* name);

void SC_NR_RenameStr(SCNodeRenamer* self, JB_String* s, Syntax func);

void SC_NR_Uniqueify(SCNodeRenamer* self, SCBase* p);

SCNodeRenamer* SC_NR__Alloc();

SCNodeRenamer* SC_NR__New();



// JB_SCObject
Message* SC_SCObject_AnySource(SCObject* self);

int SC_SCObject_auto_type(SCObject* self);

int SC_SCObject_AutoCompleteType(SCObject* self);

JB_String* SC_SCObject_BaseIcon(SCObject* self);

JB_String* SC_SCObject_CallFromName(SCObject* self);

JB_String* SC_SCObject_CanAuto(SCObject* self, JB_String* search);

bool SC_SCObject_CanAutoLimit(SCObject* self, int Type, SCDecl* Limiter);

JB_String* SC_SCObject_CanAutoSub(SCObject* self, JB_String* search);

void SC_SCObject_Constructor(SCObject* self);

void SC_SCObject_destructor(SCObject* self);

SCFunction* SC_SCObject_Disambiguate(SCObject* self, Message* src);

JB_String* SC_SCObject_Display(SCObject* self, bool exact);

SCObject* SC_SCObject_NextDisplay(SCObject* self, bool exact);

JB_String* SC_SCObject_Render(SCObject* self, FastString* fs_in);

bool SC_SCObject_ShouldUnWrap(SCObject* self);

void SC_SCObject_Fail(SCObject* self, JB_String* Error);



// JB_SCOperator
JB_String* SC_Opp_CaseAwareStr(SCOperator* self);

void SC_Opp_Constructor(SCOperator* self, fn_OpASM ASM);

void SC_Opp_destructor(SCOperator* self);

void SC_Opp_InitBit(SCOperator* self, JB_String* name_, JB_String* FuncName_);

void SC_Opp_InitComp(SCOperator* self, JB_String* name_);

void SC_Opp_InitNormal(SCOperator* self, JB_String* name_, JB_String* FuncName_);

bool SC_Opp_IsCompSet(SCOperator* self);

JB_String* SC_Opp_SimpleName(SCOperator* self);

bool SC_Opp_SyntaxEquals(SCOperator* self, JB_String* s, bool aware);

void SC_Opp__AddBit(JB_String* s, JB_String* FuncName, fn_OpASM ASM);

void SC_Opp__AddComp(JB_String* s, fn_OpASM ASM);

void SC_Opp__AddComp2(JB_String* s, fn_OpASM ASM);

void SC_Opp__AddCompSub(JB_String* s, fn_OpASM fn);

SCOperator* SC_Opp__AddNormal(JB_String* s, JB_String* FuncName, fn_OpASM ASM);

SCOperator* SC_Opp__Alloc();

void SC_Opp__BuildOrder();

void SC_Opp__Init();

int SC_Opp__Init_();

int SC_Opp__InitCode_();

SCOperator* SC_Opp__Lookup(Message* opch);

SCOperator* SC_Opp__New(fn_OpASM ASM);



// JB_SCParamArray
void SC_PA_AddParam(SCParamArray* self, Message* item);

bool SC_PA_AddTestedParam(SCParamArray* self, Message* item, SCBase* name_space);

SCFunction* SC_PA_ArgsMatchError(SCParamArray* self, int TypeCast, SCFunction* f, SCFunction* R);

void SC_PA_Constructor(SCParamArray* self, Message* exp, Message* side);

SCBase* SC_PA_DetectDotSuper(SCParamArray* self, SCBase* curr);

int SC_PA_IgnoreSelf(SCParamArray* self);

bool SC_PA_IsModule(SCParamArray* self);

int SC_PA_MacroSize(SCParamArray* self);

bool SC_PA_MadeError(SCParamArray* self);

bool SC_PA_PreReadTypes(SCParamArray* self, SCBase* Name_Space, Message* P, Message* side);

IntRange SC_PA_Range(SCParamArray* self);

JB_String* SC_PA_RenderName(SCParamArray* self);

JB_String* SC_PA_RenderType(SCParamArray* self);

void SC_PA_SideSet(SCParamArray* self, Message* Value);

Message* SC_PA_SyntaxAccess(SCParamArray* self, int i);

void SC_PA_SyntaxAppend(SCParamArray* self, Message* m);

inline bool SC_PA_SyntaxCast(SCParamArray* self);

SCParamArray* SC_PA__Alloc();

SCParamArray* SC_PA__New(Message* exp, Message* side);



// JB_Selector
void JB_Sel_Constructor(Selector* self, Selector* Next, Selector** Place, JB_String* namee);

void JB_Sel_destructor(Selector* self);

void JB_Sel_GiveIDs(Selector* self);

inline uint JB_Sel_UCast(Selector* self);



// JB_ShellStream


// JB_String
JB_String* JB_Str_AfterByte(JB_String* self, byte b, int Last);

JB_String* JB_Str_ArgName(JB_String* self);

JB_String* JB_Str_ArgsMatchError(JB_String* self, bool TypeCast);

JB_String* JB_Str_ArgValue(JB_String* self);

uint JB_Str_ASMint(JB_String* self);

JB_String* JB_Str_ASMNormalise(JB_String* self);

JB_String* JB_Str_BackToApp(JB_String* self);

JB_String* JB_Str_Before(JB_String* self, JB_String* s);

JB_String* JB_Str_BeforeLastByte(JB_String* self, byte b, int fudge);

Array* JB_Str_ByteSplit(JB_String* self);

CharSet* JB_Str_CharSetWithBool(JB_String* self, bool Range);

JB_String* JB_Str_Child(JB_String* self, JB_String* cname);

Array* JB_Str_Chunk(JB_String* self, int n);

JB_String* JB_Str_Compress(JB_String* self, CompressionStats* st);

void JB_Str_CompressIntoSub(JB_String* self, FastString* j, CompressionStats* st);

JB_String* JB_Str_ContainerName(JB_String* self, JB_String* ext);

ErrorInt JB_Str_CopyFileTo(JB_String* self, JB_String* Dest, bool AttrOnly);

int JB_Str_Count(JB_String* self, byte b);

ErrorInt JB_Str_DebugExecute(JB_String* self, Array* Args, FastString* Out, FastString* Errs);

JB_String* JB_Str_Decompress(JB_String* self, CompressionStats* st, int lim);

bool JB_Str_DecompressSub(JB_String* self, CompressionStats* st, int lim, Message* j, FastString* fs);

Dictionary* JB_Str_Dict(JB_String* self, byte sep);

JB_String* JB_Str_digest(JB_String* self);

bool JB_Str_EndsWith(JB_String* self, JB_String* s, bool aware);

JB_String* JB_Str_Escape(JB_String* self);

JB_String* JB_Str_EscapeChr(JB_String* self);

bool JB_Str_EscapeTest(JB_String* self);

JB_File* JB_Str_ExistingFile(JB_String* self, JB_String* operation);

JB_String* JB_Str_Ext(JB_String* self);

JB_File* JB_Str_AsFile(JB_String* self);

JB_File* JB_Str_ChildFile(JB_String* self, JB_String* ch);

bool JB_Str_FileExists(JB_String* self);

Ind JB_Str_FindByte(JB_String* self, byte find, int Start, int After);

Ind JB_Str_Find(JB_String* self, CharSet* cs, int Start, int After);

int JB_Str_FindTrailingSlashes(JB_String* self);

byte JB_Str_First(JB_String* self);

bool JB_Str_HasMoat(JB_String* self);

Ind JB_Str_HiddenJBin(JB_String* self);

int64 JB_Str_int(JB_String* self);

JB_String* JB_Str_InterfaceToBehaviour(JB_String* self);

Ind JB_Str_InWhite(JB_String* self, int Start, int After);

JB_String* JB_Str_ipcName(JB_String* self);

JB_String* JB_Str_ipcPath(JB_String* self);

bool JB_Str_isCLike(JB_String* self);

bool JB_Str_IsCompressed(JB_String* self);

int JB_Str_IsHexLike(JB_String* self, int N);

bool JB_Str_IsInt(JB_String* self);

bool JB_Str_IsIntFrom(JB_String* self, int i);

bool JB_Str_IsJbin(JB_String* self);

bool JB_Str_IsOKForImport(JB_String* self);

bool JB_Str_IsSpeedieSrc(JB_String* self);

bool JB_Str_IsStatementName(JB_String* self);

int JB_Str_IsSwizzle(JB_String* self, int Width);

bool JB_Str_IsZero(JB_String* self);

Ind JB_Str_JBFind(JB_String* self, byte find, int Off, int After);

byte JB_Str_Last(JB_String* self, int minus);

int JB_Str_LineCount(JB_String* self);

Macro* JB_Str_macro(JB_String* self);

JB_File* JB_Str_MakeAndGoInto(JB_String* self);

ErrorInt JB_Str_MakeEntirePath(JB_String* self, bool Last);

JB_String* JB_Str_Name(JB_String* self);

JB_String* JB_Str_Normalise(JB_String* self);

bool JB_Str_ContainsString(JB_String* self, JB_String* s);

bool JB_Str_ContainsByte(JB_String* self, byte b);

Array* JB_Str_OperatorDivide(JB_String* self, byte sep);

bool JB_Str_OperatorEndsWith(JB_String* self, JB_String* s);

bool JB_Str_OperatorIsa(JB_String* self, JB_String* s);

int JB_Str_OperatorMinus(JB_String* self, JB_String* s);

bool JB_Str_OperatorPathMatch(JB_String* self, JB_String* path);

JB_String* JB_Str_PlusByte(JB_String* self, byte B);

bool JB_Str_OperatorStarts(JB_String* self, JB_String* s);

bool JB_Str_optionbool(JB_String* self);

int JB_Str_optionint(JB_String* self);

Ind JB_Str_OutByteWithByteIntInt(JB_String* self, byte find, int Start, int After);

Ind JB_Str_OutCharSet(JB_String* self, CharSet* cs, int Start, int After);

Ind JB_Str_OutWhite(JB_String* self, int Start, int After);

JB_String* JB_Str_Parent(JB_String* self);

Message* JB_Str_Parse(JB_String* self, Syntax owner, bool AllowDecomp);

Message* JB_Str_parse_jbin(JB_String* self);

Message* JB_Str_ParseClean(JB_String* self);

Message* JB_Str_ParseCleanWipe(JB_String* self);

Message* JB_Str_ParseWithError(JB_String* self, JB_Error** rec);

JB_String* JB_Str_PathDir(JB_String* self);

JB_String* JB_Str_Preview(JB_String* self, int N);

void JB_Str_PrintColor(JB_String* self, JB_String* color);

void JB_Str_PrintlineColor(JB_String* self, JB_String* color);

StringStream* JB_Str_reader(JB_String* self, JB_String* T);

JB_String* JB_Str_ReadFile(JB_String* self, int lim, bool AllowMissing);

JB_String* JB_Str_ReplacePathComponent(JB_String* self, int num, JB_String* With);

void JB_Str_safe(JB_String* self, FastString* fs);

JB_String* JB_Str_ScriptLocation(JB_String* self, JB_String* container);

JB_String* JB_Str_Sibling(JB_String* self, JB_String* name);

ErrorInt JB_Str_SilentExecute(JB_String* self, Array* Args, FastString* Out, FastString* Errs);

JB_String* JB_Str_SpdScriptName(JB_String* self);

Array* JB_Str_Split(JB_String* self, byte sep);

JB_String* JB_Str_Squeeze(JB_String* self);

JB_String* JB_Str_SyntaxAccess(JB_String* self, JB_String* s);

bool JB_Str_SyntaxAppend(JB_String* self, JB_String* s);

inline JB_StringC* JB_Str_CastZero(JB_String* self);

int JB_Str_CompareStr(JB_String* self, JB_String* Other, bool Aware);

int JB_Str_CompareInt(JB_String* self, int Other, bool Aware);

bool JB_Str_EqualsInt(JB_String* self, int Other, bool Aware);

void JB_Str_SyntaxExpect(JB_String* self);

JB_String* JB_Str_TitleCase(JB_String* self, FastString* fs_in);

JB_String* JB_Str_TrimExtAndPath(JB_String* self, bool KeepPath);

JB_String* JB_Str_TrimFirst(JB_String* self, byte b);

int JB_Str_TrimLastSub(JB_String* self, byte b);

JB_String* JB_Str_TrimStart(JB_String* self, JB_String* s);

JB_String* JB_Str_TrimTrailingSlashes(JB_String* self);

bool JB_Str_UnderScoreAtAnyEnd(JB_String* self);

JB_String* JB_Str_Unescape(JB_String* self);

JB_String* JB_Str_unicodesafename(JB_String* self);

CharSet* JB_Str_UniCS(JB_String* self);

JB_String* JB_Str_UpperFirst(JB_String* self);

Array* JB_Str_Words(JB_String* self);

bool JB_Str_WriteSet(JB_String* self, JB_String* Value);

bool JB_Str_Yes(JB_String* self);

JB_String* JB_Str__FromC(_cstring Addr);

JB_String* JB_Str__Hex(int64 i);



// JB_string_aware


// JB_StringFields
void JB_FI_Constructor(StringFields* self, JB_String* Source, byte Sep);

void JB_FI_destructor(StringFields* self);

JB_String* JB_FI_Field(StringFields* self, Ind Prev, Ind Curr);

Ind JB_FI_NextSep(StringFields* self, int Prev);

StringFields* JB_FI__Alloc();

StringFields* JB_FI__New(JB_String* Source, byte Sep);



// JB_StringShared


// JB_StringStream
byte JB_ss_Byte(StringStream* self);

void JB_ss_Constructor(StringStream* self, JB_String* d);

void JB_ss_destructor(StringStream* self);

int64 JB_ss_lint0(StringStream* self, int n);

void JB_ss_Need(StringStream* self, int n);

Message* JB_ss_parse_(StringStream* self);

Message* JB_ss_Parse_Jbin(StringStream* self);

JB_String* JB_ss_Str(StringStream* self, int n, int skip);

inline bool JB_ss_SyntaxCast(StringStream* self);

void JB_ss_SyntaxExpect(StringStream* self, JB_String* Error);

StringStream* JB_ss_test(StringStream* self, int a, JB_String* b);

StringStream* JB_ss__Alloc();

StringStream* JB_ss__New(JB_String* d);



// JB_SyntaxObj
void JB_Fn_Constructor(SyntaxObj* self, fpMsgRender msg, JB_String* name, int ID);

void JB_Fn_destructor(SyntaxObj* self);

JB_String* JB_Fn_Render(SyntaxObj* self, FastString* fs_in);

SyntaxObj* JB_Fn__Alloc();

SyntaxObj* JB_Fn__New(fpMsgRender msg, JB_String* name, int ID);



// JB_TokenHandler


// JB_µForm
void SC_xC2xB5Form_AddRemainder(xC2xB5Form* self, uint U);

void SC_xC2xB5Form_ConstructorWithStr(xC2xB5Form* self, JB_String* data);

void SC_xC2xB5Form_ConstructorWithMsg(xC2xB5Form* self, Message* tmp);

void SC_xC2xB5Form_destructor(xC2xB5Form* self);

void SC_xC2xB5Form_Finish(xC2xB5Form* self);

void SC_xC2xB5Form_LoadParam(xC2xB5Form* self, JB_String* pl, Message* place);

ASMParam SC_xC2xB5Form_AccessInt(xC2xB5Form* self, int i);

void SC_xC2xB5Form_SyntaxAccessSet(xC2xB5Form* self, int i, ASMParam Value);

void SC_xC2xB5Form_SyntaxAppend(xC2xB5Form* self, ASMParam P);

xC2xB5Form* SC_xC2xB5Form__Alloc();

int SC_xC2xB5Form__Init_();

int SC_xC2xB5Form__InitCode_();

xC2xB5Form* SC_xC2xB5Form__Needform(JB_String* Form);

xC2xB5Form* SC_xC2xB5Form__NewWithStr(JB_String* data);

xC2xB5Form* SC_xC2xB5Form__NewWithMsg(Message* tmp);



// JB_µFunc
void SC_ASMFunc_Constructor(ASMFunc* self, SCFunction* fn);

void SC_ASMFunc_destructor(ASMFunc* self);

ASMFunc2* SC_ASMFunc_Finish(ASMFunc* self);

JB_String* SC_ASMFunc_Render(ASMFunc* self, FastString* fs_in);

ASMFunc* SC_ASMFunc__Alloc();

ASMFunc* SC_ASMFunc__New(SCFunction* fn);



// JB_Array
void JB_Array_AddCStr(Array* self, JB_String* s);

void JB_Array_AppendWords(Array* self, JB_String* R);

void JB_Array_Clear(Array* self);

JB_Object* JB_Array_First(Array* self);

JB_Object* JB_Array_Last(Array* self);

void JB_Array_LoadProperties(Array* self, ObjectLoader* Loader);

JB_Object* JB_Array_Pop(Array* self);

void JB_Array_SaveCollect(Array* self, ObjectSaver* Saver);

void JB_Array_SaveWrite(Array* self, ObjectSaver* Saver);

void JB_Array_SyntaxAppend(Array* self, JB_Object* item);

inline bool JB_Array_SyntaxCast(Array* self);

bool JB_Array_SyntaxEquals(Array* self, int n, bool Aware);

Array* JB_Array__Alloc();

Array* JB_Array__New0();



// JB_Dictionary
JB_Object* JB_Dict_Expect(Dictionary* self, Message* m);

void JB_Dict_LoadProperties(Dictionary* self, ObjectLoader* Loader);

void JB_Dict_SaveCollect(Dictionary* self, ObjectSaver* Saver);

void JB_Dict_SaveWrite(Dictionary* self, ObjectSaver* Saver);

void JB_Dict_SetValue(Dictionary* self, JB_String* key, int64 Value);

JB_Object* JB_Dict_Syntax(Dictionary* self, JB_String* Key);

JB_Object* JB_Dict_ValueStr(Dictionary* self, JB_String* Key);

void JB_Dict_SetInt(Dictionary* self, uint64 Key, JB_Object* Value);

JB_Object* JB_Dict_ValueInt(Dictionary* self, uint64 Key);

JB_Object* JB_Dict_ValueLower(Dictionary* self, JB_String* s);

void JB_Dict_ValueLowerSet(Dictionary* self, JB_String* s, JB_Object* Value);

Dictionary* JB_Dict__Alloc();

Dictionary* JB_Dict__Copy(Dictionary* Dict);

Dictionary* JB_Dict__New();

Dictionary* JB_Dict__Reverse(Dictionary* Dict);



// JB_FastStringCpp
void SC_FastStringCpp_AppendBehaviour(FastStringCpp* self, JB_String* name, SCFunction* fn, SCClass* Type);

void SC_FastStringCpp_Constructor(FastStringCpp* self, JB_String* name);

void SC_FastStringCpp_destructor(FastStringCpp* self);

FastStringCpp* SC_FastStringCpp__Alloc();

FastStringCpp* SC_FastStringCpp__New(JB_String* name);



// JB_File
JB_File* JB_File_Child(JB_File* self, JB_String* name, bool errs);

ErrorInt JB_File_CodeSign(JB_File* self, JB_String* sign);

bool JB_File_FileCompare(JB_File* self, JB_File* A);

bool JB_File_Compare(JB_File* self, JB_String* S);

Message* JB_File_conf(JB_File* self, int lim);

ErrorInt JB_File_CopyAll(JB_File* self, JB_String* Dest, bool AttrOnly);

ErrorInt JB_File_DeleteAll(JB_File* self);

bool JB_File_DirectoryContains(JB_File* self, JB_String* path);

ErrorInt JB_File_LinkToSet(JB_File* self, JB_String* Value);

bool JB_File_StrMatch(JB_File* self, JB_String* s);

bool JB_File_MatchFile(JB_File* self, JB_File* f);

bool JB_File_MustExist(JB_File* self, JB_String* operation);

bool JB_File_Opened(JB_File* self);

bool JB_File_OperatorInside(JB_File* self, JB_File* f);

bool JB_File_NewerThanFile(JB_File* self, JB_File* F);

bool JB_File_OperatorIsNewerThan(JB_File* self, Date F);

JB_File* JB_File_Parent(JB_File* self);

Message* JB_File_Parse(JB_File* self, int lim, bool AllowMissing);

JB_String* JB_File_ReadSafely(JB_File* self, int lim, bool AllowMissing);

JB_File* JB_File_sibling(JB_File* self, JB_String* name);

bool JB_File_SmartDataSet(JB_File* self, JB_String* nieu);

JB_File* JB_File_SyntaxAccess(JB_File* self, JB_String* name, bool Errs);

void JB_File_SyntaxAppend(JB_File* self, JB_String* data);

inline bool JB_File_SyntaxCast(JB_File* self);

void JB_File_Fail(JB_File* self, JB_String* Error);

bool JB_File_TestBatch(JB_File* self);

bool JB_File_TestSpeedie(JB_File* self, JB_String* Variant);

ErrorInt JB_File_touch(JB_File* self);

bool JB_File_visible(JB_File* self);

FastString* JB_File_writer(JB_File* self);

JB_File* JB_File__Alloc();

JB_String* JB_File__AppPrefs(JB_String* name);

int JB_File__Init_();

int JB_File__InitCode_();

JB_File* JB_File__Logs();

JB_File* JB_File__New(JB_String* path);

JB_String* JB_File__PreferencesPath();

JB_File* JB_File__PrefsFolder();

void JB_File__testjb();



// JB_Instruction
void SC_Instruction_ActualInit(Instruction* self);

void SC_Instruction_Const(Instruction* self);

void SC_Instruction_Constructor(Instruction* self, Selector* Next, Selector** Place, JB_String* name1);

void SC_Instruction_destructor(Instruction* self);

bool SC_Instruction_IsSetConst(Instruction* self);

JB_String* SC_Instruction_Render(Instruction* self, FastString* fs_in);

void SC_Instruction_selector_init(Instruction* self, JB_String* formName, int num);

void SC_Instruction____LoadSel(Instruction** Place, JB_String* Name);

Instruction* SC_Instruction__Alloc();

void SC_Instruction__Init();

int SC_Instruction__Init_();

int SC_Instruction__InitCode_();

Instruction* SC_Instruction__New(Selector* Next, Selector** Place, JB_String* name1);

void SC_Instruction__Store(Instruction* i);

Instruction* SC_Instruction__SyntaxAccess(Message* m);



// JB_JBin
void JB_bin_add(FastString* self, Syntax type, JB_String* data, bool into);

void JB_bin_AddCstring(FastString* self, _cstring data, Syntax type);

void JB_bin_addint(FastString* self, int64 data);

void JB_bin_AddMemory(FastString* self, Syntax type, bool GoIn, byte* data, uint64 L);

void JB_bin_CloseStream(FastString* self, int c);

void JB_bin_Constructor(FastString* self, Syntax type, JB_String* data);

void JB_bin_Constructor0(FastString* self);

void JB_bin_enter(FastString* self, Syntax type, JB_String* data);

void JB_bin_jinit(FastString* self);

int JB_bin_OpenStream(FastString* self);

void JB_bin_sheb(FastString* self, JB_String* data);

void JB_bin_up(FastString* self, int amount);

FastString* JB_bin__New(Syntax type, JB_String* data);

FastString* JB_bin__New0();



// JB_MaterialsLol
void SC_MaterialsLol_Constructor(MaterialsLol* self, Selector* Next, Selector** Place, JB_String* name1);

void SC_MaterialsLol_destructor(MaterialsLol* self);

void SC_MaterialsLol____LoadSel(MaterialsLol** Place, JB_String* Name);

MaterialsLol* SC_MaterialsLol__Alloc();

int SC_MaterialsLol__Init_();

int SC_MaterialsLol__InitCode_();

MaterialsLol* SC_MaterialsLol__New(Selector* Next, Selector** Place, JB_String* name1);



// JB_RingTree
void JB_Tree_AppendAfter(RingTree* self, RingTree* item, RingTree* after);

void JB_Tree_AppendBefore(RingTree* self, RingTree* item, RingTree* Before);

int JB_Tree_backdist(RingTree* self, RingTree* B);

void JB_Tree_Clear(RingTree* self);

void dbglineinfo(RingTree* self);

int JB_Tree_dist(RingTree* self, RingTree* r);

RingTree* JB_Tree_First_(RingTree* self);

RingTree* JB_Tree_FlatLast(RingTree* self);

Array* JB_Tree_Flatten(RingTree* self);

int JB_Tree_fwddist(RingTree* self, RingTree* F);

bool JB_Tree_HasOneChild(RingTree* self);

bool JB_Tree_IsFirst(RingTree* self);

bool JB_Tree_IsOnlyChild(RingTree* self);

void jdb2(RingTree* self);

void jdb3(RingTree* self);

bool JB_Tree_OperatorLessOrEqual(RingTree* self, int N);

RingTree* JB_Tree_Pop(RingTree* self);

void JB_Tree_Remove(RingTree* self);

void JB_Tree_RemoveAfter(RingTree* self);

JB_String* JB_Tree_Render(RingTree* self, FastString* fs_in);

RingTree* JB_Tree_Second(RingTree* self);

RingTree* JB_Tree_Get(RingTree* self, int n);

void JB_Tree_SyntaxAppend(RingTree* self, RingTree* Last);

bool JB_Tree_SyntaxEquals(RingTree* self, int n, bool Aware);

void JB_Tree_TakeAllFrom(RingTree* self, RingTree* src);

RingTree* JB_Tree_Upward(RingTree* self, int n);

RingTree* JB_Tree__Alloc();

RingTree* JB_Ring__New0();



// JB_SaverClassInfo
void JB_sci_Clear(SaverClassInfo* self);

void JB_sci_Constructor(SaverClassInfo* self, JB_Class* Cls, char* Data);

void JB_sci_destructor(SaverClassInfo* self);

bool JB_sci_HasData(SaverClassInfo* self);

void JB_sci_Output(SaverClassInfo* self, ObjectSaver* Saver);

SaverClassInfo* JB_sci__Alloc();

SaverClassInfo* JB_sci__New(JB_Class* Cls, char* Data);



// JB_SavingTest
void SC_SavingTest_constructor(SavingTest* self, int n);

void SC_SavingTest_destructor(SavingTest* self);

void SC_SavingTest_LoadProperties(SavingTest* self, ObjectLoader* Loader);

void SC_SavingTest_SaveWrite(SavingTest* self, ObjectSaver* Saver);

SavingTest* SC_SavingTest__Alloc();

bool SC_SavingTest__IsEqual(JB_Object* A, JB_Object* B);

SavingTest* SC_SavingTest__New(int n);



// JB_SCBase
void SC_Base_Addtotable(SCBase* self, Array* r);

JB_String* SC_Base_AutoCompleteName(SCBase* self);

SCClass* SC_Base_CodeCls(SCBase* self);

void SC_Base_Collect(SCBase* self, Message* AST, bool Visible, Message* dest);

void SC_Base_CollectConstants(SCBase* self, Message* src, SCImport* imp);

void SC_Base_CollectConstantsSub(SCBase* self, Message* ch, SCImport* imp);

void SC_Base_CollectOne(SCBase* self, Message* c, bool Visible);

Message* SC_Base_CollectString(SCBase* self, JB_String* s);

SCBase* SC_Base_CollectSub(SCBase* self, Message* c);

void SC_Base_ConstantExpand(SCBase* self, Message* ch);

void SC_Base_Constructor0(SCBase* self);

void SC_Base_ConstructorStr(SCBase* self, JB_String* Name, bool Dummy);

void SC_Base_ConstructorMsg(SCBase* self, Message* node);

void SC_Base_CreateNameDict(SCBase* self, Message* FuncName, Array* NameList);

void SC_Base_destructor(SCBase* self);

Message* SC_Base_DiissplayObj(SCBase* self, Message* rz);

void SC_Base_DoLinkFrom(SCBase* self, SCBase* B);

Message* SC_Base_FindCppWrapper(SCBase* self, Message* place, bool isclass);

bool SC_Base_FindVis(SCBase* self, Message* c);

Message* SC_Base_FuncSrc(SCBase* self);

SCModule* SC_Base_GetAsModule(SCBase* self, Message* errplace);

void SC_Base_ImportFile(SCBase* self, SCFile* file);

bool SC_Base_IsClassFunc(SCBase* self);

bool SC_Base_IsModuleFunc(SCBase* self);

SCClass* SC_Base_IsNormalObject(SCBase* self);

bool SC_Base_IsSTDLib(SCBase* self);

bool SC_Base_IsVisible(SCBase* self);

void SC_Base_IsVisibleSet(SCBase* self, bool Value);

JB_String* SC_Base_LateAddTempory(SCBase* self, JB_String* type, JB_String* name1, Message* Value, Message* err);

Message* SC_Base_LinkagePlace(SCBase* self);

Array* SC_Base_ListFunctions(SCBase* self);

void SC_Base_LoadExportName(SCBase* self);

void SC_Base_LoadVisibility(SCBase* self, Message* p);

JB_Object* SC_Base_LookUpDot(SCBase* self, JB_String* name, Message* exp, SCBase* arg_space, SCDecl* contains, Message* side);

SCObject* SC_Base_LookUpFunc(SCBase* self, JB_String* name, Message* exp, Message* ParamsHere);

SCObject* SC_Base_LookUpSub(SCBase* self, JB_String* OrigName, Message* Exp, Message* ParamsHere, SCBase* arg_space, SCDecl* contains, Message* side, int Purpose);

SCObject* SC_Base_LookUpVar(SCBase* self, JB_String* name, Message* exp, Message* side);

SCDecl* SC_Base_LookUpVarDecl(SCBase* self, JB_String* name);

SCObject* SC_Base_LookUpVarRootDecl(SCBase* self, JB_String* name, Message* exp);

bool SC_Base_NeedsExport(SCBase* self);

SCFunction* SC_Base_OwningFunc(SCBase* self);

SCBase* SC_Base_ProcessLinkage(SCBase* self, Message* node, Dictionary* Table);

SCBase* SC_Base_ProjectFix(SCBase* self);

JB_String* SC_Base_ReachedName(SCBase* self);

bool SC_Base_RehomeExport(SCBase* self);

SCDecl* SC_Base_RequireContained(SCBase* self, Message* exp);

void SC_Base_SetExportName(SCBase* self, JB_String* s, bool Explicit);

SCClass* SC_Base_ShouldBeClass(SCBase* self, Message* errplace);

Message* SC_Base_SourceArg(SCBase* self);

void SC_Base_StoreLinkToMe(SCBase* self, Dictionary** dp);

JB_String* SC_Base_SubProjName(SCBase* self);

SCObject* SC_Base_SyntaxAccess(SCBase* self, JB_String* s);

bool SC_Base_SyntaxIs(SCBase* self, SCBaseInfo i);

void SC_Base_SyntaxIsSet(SCBase* self, SCBaseInfo i, bool Value);

bool SC_Base_SyntaxIsnt(SCBase* self, SCBaseInfo i);

JB_String* SC_Base_TestExportName(SCBase* self, JB_String* s, bool Explicit);

void SC_Base_Tran_Const(SCBase* self, SCDecl* D, SCBase* base);

void SC_Base_TryAdd(SCBase* self, Message* ErrPlace, SCObject* IncObj, JB_String* name);

void SC_Base_TryAddBase(SCBase* self, Message* c, SCBase* neu);

JB_String* SC_Base_UniquifyExport(SCBase* self, JB_String* s);

SCObject* SC_Base_UpCheck(SCBase* self, JB_String* name, bool LookUp);

SCBase* SC_Base_UpClass(SCBase* self, Message* f);

void SC_Base_Use(SCBase* self);

SCBase* SC_Base__Alloc();

int SC_Base__Init_();

int SC_Base__InitCode_();

SCBase* SC_Base__LoadCppPart(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Base__NewStr(JB_String* Name, bool Dummy);



// JB_SCBehaviour
void SC_Beh_Add(SCBehaviour* self, SCBase* fn);

SCClass* SC_Beh_Cls(SCBehaviour* self);

void SC_Beh_Constructor(SCBehaviour* self, SCClass* parent);

void SC_Beh_CreateFuncTable(SCBehaviour* self, Message* ErrPlace);

void SC_Beh_destructor(SCBehaviour* self);

SCBehaviour* SC_Beh_Upwards(SCBehaviour* self);

SCBehaviour* SC_Beh__Alloc();

SCFunction* SC_Beh__MakeCallerSub(JB_String* FnStr, SCClass* Cls, Message* ErrPlace);

SCFunction* SC_Beh__MakeInterfaceCaller(SCModule* Mod, SCClass* Cls, Message* ErrPlace);

SCBehaviour* SC_Beh__New(SCClass* parent);

SCBase* SC_Beh__NewBehaviour(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Beh__NewInterface(Message* node, SCBase* name_space, Message* ErrPlace);

SCModule* SC_Beh__NewInterfaceSub(Message* node, SCClass* cls, Message* ErrPlace);

bool SC_Beh__Tran_Behaviour(Message* node, SCClass* cls);



// JB_SCClass
void SC_Class_AddBehaviourOrInterface(SCClass* self, SCBase* M, Message* ErrPlace);

void SC_Class_AddInterfacesTo(SCClass* self, Array* List);

void SC_Class_AddSelfToFunc(SCClass* self, SCBase* space);

void SC_Class_AfterAfterFuncs(SCClass* self);

void SC_Class_AfterFuncsDecled(SCClass* self);

JB_String* SC_Class_AllocStr(SCClass* self);

JB_String* SC_Class_AllocStrLayer(SCClass* self);

JB_String* SC_Class_APIStructName(SCClass* self);

void SC_Class_AutoConstructor(SCClass* self);

void SC_Class_BannedCheck(SCClass* self, Message* src);

JB_String* SC_Class_BehaviourName(SCClass* self);

SCFunction* SC_Class_BestBehaviourFor(SCClass* self, JB_String* name);

int SC_Class_CalculateSize(SCClass* self, int Depth);

int SC_Class_CalculateSizeRaw(SCClass* self, int Depth);

bool SC_Class_CanCompare(SCClass* self, SCDecl* Against, bool AsEquals);

bool SC_Class_CanCompareSub(SCClass* self, JB_String* s, SCDecl* against);

void SC_Class_CheckAllocVsWrapper(SCClass* self, SCFunction* f, bool IsConstructor);

void SC_Class_CheckIterator(SCClass* self);

void SC_Class_ClassCollect(SCClass* self);

void SC_Class_Constructor(SCClass* self, Message* node, SCBase* parent);

SCDecl* SC_Class_ContainedButNotUpgrade(SCClass* self);

void SC_Class_CreateAlloc(SCClass* self, JB_String* ParseThing, int Extra);

void SC_Class_CreateBehaviour(SCClass* self);

void SC_Class_CreateConstructors(SCClass* self);

SCFunction* SC_Class_CreateEmptyConstructors(SCClass* self);

SCFunction* SC_Class_CreateEmptyFunc(SCClass* self, JB_String* fname, JB_String* cpp_name);

JB_String* SC_Class_CStructName(SCClass* self);

JB_String* SC_Class_CSuperStructName(SCClass* self);

void SC_Class_DataTypePostLoad(SCClass* self);

void SC_Class_DeclModel(SCClass* self);

void SC_Class_destructor(SCClass* self);

SCFunction* SC_Class_DoSaver(SCClass* self, JB_String* name, int stage);

void SC_Class_FillInterFaceIn(SCClass* self, SCFunction* fn, bool Late);

void SC_Class_FillInterFaceWrapper(SCClass* self, SCFunction* fn);

SCFunction* SC_Class_FindAllocFunc(SCClass* self, JB_String* fname, bool DontCreate);

Message* SC_Class_FindDecl(SCClass* self, JB_String* name);

SCFunction* SC_Class_FindFunc(SCClass* self, JB_String* keyword, bool CheckParents, bool DoError);

SCFunction* SC_Class_FindSpecialFunc(SCClass* self, JB_String* keyword, bool CheckParents);

SCFunction* SC_Class_FirstDestructor(SCClass* self);

void SC_Class_GetDepth(SCClass* self);

SCClass* SC_Class_GetFlyingMemClassFor(SCClass* self);

SCDecl* SC_Class_GetFlyingMemory(SCClass* self, Message* exp);

SCIterator* SC_Class_GetIteratorAny(SCClass* self, JB_String* name, Message* node);

SCClass* SC_Class_GoUpTo(SCClass* self, int d);

bool SC_Class_HasGameType(SCClass* self);

bool SC_Class_HasObjectProperties(SCClass* self);

bool SC_Class_HasOperator(SCClass* self, JB_String* op);

bool SC_Class_HasStuffToHandleInDestructor(SCClass* self);

SCClass* SC_Class_InterfaceFor(SCClass* self, JB_String* name, Message* errplace);

SCClass* SC_Class_InterfaceForBehaviour(SCClass* self, SCFunction* Fn);

bool SC_Class_IsA(SCClass* self, SCClass* S);

bool SC_Class_IsBehaviourTable(SCClass* self);

bool SC_Class_IsDataTypeOrStruct(SCClass* self);

bool SC_Class_IsFunc(SCClass* self);

bool SC_Class_IsInterface(SCClass* self);

bool SC_Class_IsObject(SCClass* self);

bool SC_Class_IsSaveableObject(SCClass* self);

bool SC_Class_IsSaveableStruct(SCClass* self);

bool SC_Class_IsSTDLib(SCClass* self);

JB_String* SC_Class_JSStructName(SCClass* self);

void SC_Class_LibExport(SCClass* self, FastString* j);

void SC_Class_LoadConstructorsAndAllocators(SCClass* self);

void SC_Class_LoadContainedType(SCClass* self);

void SC_Class_LoadLinkage(SCClass* self);

void SC_Class_LoadProperties(SCClass* self);

void SC_Class_LoadSaver(SCClass* self);

JB_String* SC_Class_LoadSaverSub(SCClass* self);

void SC_Class_LoadSuperclass(SCClass* self);

void SC_Class_ModelDecls(SCClass* self);

void SC_Class_MoreConstantCollection(SCClass* self);

bool SC_Class_NeedsExport(SCClass* self);

void SC_Class_NewClassNew(SCClass* self, SCFunction* con, Message* src, int ExtraCode);

void SC_Class_NewDeclInClassModule(SCClass* self, JB_String* S, SCClass* T);

SCDecl* SC_Class_NotConst(SCClass* self);

int SC_Class_NumericCount(SCClass* self);

void SC_Class_OverrideSyntax(SCClass* self);

int SC_Class_PassableCount(SCClass* self);

bool SC_Class_PreferAddress(SCClass* self);

void SC_Class_ProcessBehaviours(SCClass* self);

void SC_Class_ProcessInterfaces(SCClass* self);

void SC_Class_Reach(SCClass* self, SCBase* from, Message* src);

void SC_Class_ReachBehaviours(SCClass* self);

bool SC_Class_real_isa(SCClass* self, SCClass* cls);

SCClass* SC_Class_RealClass(SCClass* self);

SCClass* SC_Class_RealSuper(SCClass* self);

void SC_Class_RenameInterfaces(SCClass* self);

JB_String* SC_Class_Render(SCClass* self, FastString* fs_in);

void SC_Class_RenderSaveable(SCClass* self, FastString* fs);

bool SC_Class_RenderSaveableSub(SCClass* self, FastString* fs);

void SC_Class_StartupSaver(SCClass* self, JB_String* Name);

bool SC_Class_StructContainerShipGrabbed(SCClass* self);

bool SC_Class_SuperGrabbed(SCClass* self);

bool SC_Class_EqualsType(SCClass* self, SCBaseType d, bool aware);

bool SC_Class_TestBanned(SCClass* self);

void SC_Class_TryAddToProject(SCClass* self);

SCObject* SC_Class_UpCheckSub(SCClass* self, JB_String* name);

void SC_Class_WriteStructOrUnion(SCClass* self, FastStringCpp* fs);

SCClass* SC_Class__Alloc();

SCBase* SC_Class__DataType(Message* node, SCBase* name_space, Message* ErrPlace);

SCModule* SC_Class__DataTypeSub(Message* Node, SCBase* Parent, Message* ErrPlace, JB_String* ForInterface);

Message* SC_Class__DoOneNamedField(Message* c, JB_String* name, JB_String* datatype, int n);

SCBase* SC_Class__ExtendOneFunc(Message* node, SCBase* name_space, Message* ErrPlace);

int SC_Class__Init_();

int SC_Class__InitCode_();

JB_String* SC_Class__LoadClassName(Message* node);

SCBase* SC_Class__LoadSyntax(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Class__NamedPropertyFields(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Class__NeuClass(Message* node, SCBase* name_space, Message* ErrPlace);

SCClass* SC_Class__NeuClassSub(Message* node, SCBase* parent, Message* ErrPlace, JB_String* ForInterface);

SCBase* SC_Class__NeuRole(Message* node, SCBase* name_space, Message* ErrPlace);

SCClass* SC_Class__New(Message* node, SCBase* parent);

SCBase* SC_Class__NewStruct(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Class__ProcessAs(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Class__ProcessExtend(Message* c, bool PreferClass);

void SC_Class__ProcessExtendOld(Message* c, bool PreferClass);

SCBase* SC_Class__StoreExtend(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Class__StoreExtendModule(Message* node, SCBase* name_space, Message* ErrPlace);



// JB_SCDecl
bool SC_Decl_AlreadyContains(SCDecl* self, SCDecl* c);

SCDecl* SC_Decl_AsPointer(SCDecl* self);

JB_String* SC_Decl_AutoCompleteName(SCDecl* self);

SCDecl* SC_Decl_better_numeric(SCDecl* self, SCDecl* o);

int SC_Decl_ByteSize(SCDecl* self);

bool SC_Decl_CantBeNilInCpp(SCDecl* self);

bool SC_Decl_CanUseDefault(SCDecl* self);

bool SC_Decl_CanWrap(SCDecl* self);

bool SC_Decl_CirSub(SCDecl* self, int64 Value);

SCDecl* SC_Decl_ClassActReplace(SCDecl* self, SCClass* cls);

void SC_Decl_CompilerCreatedSet(SCDecl* self, bool Value);

bool SC_Decl_ConstCheck(SCDecl* self, Message* ln, Message* RN, SCDecl* rc);

bool SC_Decl_ConstInRange(SCDecl* self, Message* RN, SCDecl* rt);

void SC_Decl_Constructor(SCDecl* self);

SCDecl* SC_Decl_ContainedNilfix(SCDecl* self);

SCDecl* SC_Decl_ContainedReplace(SCDecl* self, SCClass* DotCls, SCDecl* contains, bool NeedsName);

bool SC_Decl_ContainsMatch(SCDecl* self, SCDecl* o, int TypeCast);

SCDecl* SC_Decl_Copy(SCDecl* self, bool ForNewVariable);

void SC_Decl_CopyTypeInfoTo(SCDecl* self, SCDecl* Dcl);

Message* SC_Decl_CreateDefault(SCDecl* self, Message* errs, bool isfunc);

Message* SC_Decl_CreateSimpleTypeCast(SCDecl* self, Message* exp);

Message* SC_Decl_CreateStructNil(SCDecl* self, Message* errs);

void SC_Decl_destructor(SCDecl* self);

Message* SC_Decl_ExpectMatch(SCDecl* self, SCDecl* O, int TypeCast, Message* exp, Message* ErrNode);

void SC_Decl_ExpectMatchRel(SCDecl* self, SCDecl* O, Message* exp, Message* side, Message* ErrNode);

DataTypeCode SC_Decl_GameType(SCDecl* self);

SCDecl* SC_Decl_GetAddress(SCDecl* self);

SCDecl* SC_Decl_GetAddress0(SCDecl* self);

SCIterator* SC_Decl_GetIteratorAny(SCDecl* self, JB_String* name, Message* node);

bool SC_Decl_HasStruct(SCDecl* self);

SCFunction* SC_Decl_HasStructDestructor(SCDecl* self);

SCDecl* SC_Decl_HighestArrayContainMatch(SCDecl* self, SCDecl* Other, Message* exp);

SCDecl* SC_Decl_HighestMatch(SCDecl* self, SCDecl* Other, Message* exp);

void SC_Decl_IsAPISet(SCDecl* self, bool Value);

void SC_Decl_IsBorrowedSet(SCDecl* self, bool Value);

void SC_Decl_IsConstSet(SCDecl* self, bool Value);

bool SC_Decl_IsConstOf(SCDecl* self, SCDecl* b);

bool SC_Decl_IsDataType(SCDecl* self);

bool SC_Decl_isfloat(SCDecl* self);

bool SC_Decl_IsInteger(SCDecl* self);

void SC_Decl_IsNewlyCreatedSet(SCDecl* self, bool Value);

bool SC_Decl_isnil(SCDecl* self);

bool SC_Decl_IsNormal(SCDecl* self);

bool SC_Decl_IsNormalBool(SCDecl* self);

bool SC_Decl_IsNormalNumber(SCDecl* self);

bool SC_Decl_IsNormalObject(SCDecl* self);

bool SC_Decl_IsNormalStruct(SCDecl* self);

bool SC_Decl_IsntReallyCastable(SCDecl* self, Message* side);

int SC_Decl_IsNumeric(SCDecl* self);

bool SC_Decl_ispassable(SCDecl* self);

bool SC_Decl_IsReffable(SCDecl* self, bool SetOnly);

JB_String* SC_Decl_IsSaveable(SCDecl* self);

void SC_Decl_IsStaticSet(SCDecl* self, bool Value);

void SC_Decl_IsTypeImproveSet(SCDecl* self, bool Value);

bool SC_Decl_isuintlike(SCDecl* self);

bool SC_Decl_LoadContained(SCDecl* self, Message* Contained, Message* c, SCBase* Name_Space);

SCDecl* SC_Decl_MakeAsObject(SCDecl* self, SCDecl* Container, Message* ErrPlace);

SCDecl* SC_Decl_MakeBorrowed(SCDecl* self);

void SC_Decl_MakeContainedObject(SCDecl* self);

void SC_Decl_MakeGameFlying(SCDecl* self, SCClass* oof);

SCDecl* SC_Decl_MakePointer(SCDecl* self);

SCDecl* SC_Decl_MakeSignedIfPossible(SCDecl* self);

bool SC_Decl_MakeStatic(SCDecl* self, SCDecl* R);

int SC_Decl_Match(SCDecl* self, SCDecl* O, int TypeCast, Message* exp);

bool SC_Decl_MatchC(SCDecl* self, SCDecl* O);

bool SC_Decl_MiniMatch(SCDecl* self, SCDecl* O, int TypeCast);

bool SC_Decl_NeedsContainedfix(SCDecl* self);

SCDecl* SC_Decl_NewWrapper(SCDecl* self, SCDecl* CastTo);

SCDecl* SC_Decl_NewWrapperSub(SCDecl* self, SCDecl* CastTo);

bool SC_Decl_NoFloat(SCDecl* self, Message* exp);

bool SC_Decl_IsaDecl(SCDecl* self, SCDecl* O);

bool SC_Decl_OperatorIsa(SCDecl* self, SCClass* O);

bool SC_Decl_PointeryMatch(SCDecl* self, SCDecl* O);

int SC_Decl_PointeryMatchSub(SCDecl* self, SCDecl* O, int TypeCast);

JB_String* SC_Decl_PrefixedName(SCDecl* self, SCModule* M);

SCDecl* SC_Decl_ProcessAs(SCDecl* self, Message* msg);

SCImport* SC_Decl_Project(SCDecl* self);

SCDecl* SC_Decl_reallycontains(SCDecl* self);

JB_String* SC_Decl_RealName(SCDecl* self);

SCDecl* SC_Decl_RefineDecl(SCDecl* self, Message* list);

DataTypeCode SC_Decl_RegType(SCDecl* self);

JB_String* SC_Decl_Render(SCDecl* self, FastString* fs_in);

JB_String* SC_Decl_RenderTypeAndName(SCDecl* self, bool minimal);

JB_String* SC_Decl_RenderTypeName(SCDecl* self, FastString* fs_in);

bool SC_Decl_SafelyWrappable(SCDecl* self);

bool SC_Decl_SameForReplace(SCDecl* self, SCDecl* c);

void SC_Decl_SyntaxAppend(SCDecl* self, SCDeclInfo d);

bool SC_Decl_SyntaxIs(SCDecl* self, SCDeclInfo d);

void SC_Decl_SyntaxIsSet(SCDecl* self, SCDeclInfo d, bool Value);

bool SC_Decl_SyntaxIsnt(SCDecl* self, SCDeclInfo d);

int SC_Decl_TryTypeCast(SCDecl* self, SCDecl* O, Message* exp, int TypeCast);

JB_String* SC_Decl_TryUseSaveable(SCDecl* self, bool IsSave, SCClass* cls);

void SC_Decl_TypeContainedSet(SCDecl* self, SCClass* Value);

DataTypeCode SC_Decl_TypeInfo(SCDecl* self);

bool SC_Decl_TypeIsReached(SCDecl* self);

void SC_Decl_TypeReach(SCDecl* self, SCBase* from, Message* src);

SCDecl* SC_Decl_UnWrapDataType(SCDecl* self, Message* exp, SCBase* name_space);

Message* SC_Decl_WriteDeclFull(SCDecl* self, JB_String* DeclName, bool minimal);

Message* SC_Decl_WriteDeclSub(SCDecl* self, JB_String* Name, bool minimal);

Message* SC_Decl_WriteDeclTypeAndName(SCDecl* self, JB_String* Name, bool minimal);

Message* SC_Decl_WriteNilDecl(SCDecl* self);

Message* SC_Decl_WriteNilRel(SCDecl* self);

Message* SC_Decl_WriteSimpleType(SCDecl* self);

Message* SC_Decl_WriteType(SCDecl* self, bool minimal);

Message* SC_Decl_WriteTypeCast(SCDecl* self, Message* msg);

SCDecl* SC_Decl__Alloc();

SCDecl* SC_Decl__New();



// JB_SCFile
Message* SC_SCFile_AST(SCFile* self);

Message* SC_SCFile_ASTSub(SCFile* self);

void SC_SCFile_Constructor(SCFile* self, JB_File* f);

void SC_SCFile_Decls(SCFile* self, SCBase* p);

void SC_SCFile_destructor(SCFile* self);

void SC_SCFile_DetectInsecureWords(SCFile* self);

Message* SC_SCFile_GetMsg(SCFile* self, int pos, bool needname);

Message* SC_SCFile_Orig(SCFile* self);

Message* SC_SCFile_start_ast(SCFile* self);

void SC_SCFile_Use(SCFile* self);

SCFile* SC_SCFile__Alloc();

SCFile* SC_SCFile__New(JB_File* f);



// JB_SCFunction
Message* SC_Func_AddParentAllocFunc(SCFunction* self, Message* root, SCFunction* fn);

void SC_Func_AddSelfToFunc(SCFunction* self, SCClass* cls);

void SC_Func_AnalyseRefsB(SCFunction* self);

void SC_Func_AnalyseRefsConstructors(SCFunction* self);

int SC_Func_ApparantArgCount(SCFunction* self);

SCFunction* SC_Func_ArgsMatch(SCFunction* self, SCDecl* base, SCBase* name_space, SCParamArray* Incoming);

SCFunction* SC_Func_ArgsMatchSub(SCFunction* self, SCDecl* base, int TypeCast, SCBase* name_space, SCParamArray* Incoming);

int SC_Func_ArgsMatchTwo(SCFunction* self, int TypeCast, SCDecl* base, bool ThisAlter, SCBase* name_space, SCParamArray* Incoming);

Message* SC_Func_CallParents(SCFunction* self, Message* root, bool IsConstructor);

bool SC_Func_CanCompare(SCFunction* self, SCDecl* Against);

bool SC_Func_CanDoRefs(SCFunction* self);

bool SC_Func_CanLibLoad(SCFunction* self);

void SC_Func_CheckNotBadName(SCFunction* self);

void SC_Func_CheckReturnValue(SCFunction* self, Message* msg);

void SC_Func_Cleanupfunc(SCFunction* self);

void SC_Func_CollectLinks(SCFunction* self, JB_Object* obj);

void SC_Func_Constructor(SCFunction* self, Message* msg);

Message* SC_Func_ConstructorLinePlace(SCFunction* self);

void SC_Func_CopyParams(SCFunction* self, Message* list);

Message* SC_Func_CountCallsToParentAlloc(SCFunction* self, Message* root);

int SC_Func_CreateTypeCast(SCFunction* self, SCDecl* MyType, Message* exp, int Loss);

void SC_Func_DeclsProtoType(SCFunction* self, Message* ch0, SCClass* fpType, bool late);

void SC_Func_DeclsProtoTypeAdd(SCFunction* self, SCClass* fpType);

void SC_Func_DeclsProtoTypeRemove(SCFunction* self, SCClass* fpType, Message* ch0, bool AssumeSelf, bool late);

Message* SC_Func_DeclToDot(SCFunction* self, SCDecl* d);

JB_String* SC_Func_Describe(SCFunction* self, FastString* fs_in);

void SC_Func_destructor(SCFunction* self);

bool SC_Func_Disablerizer(SCFunction* self);

SCFunction* SC_Func_Disambiguate(SCFunction* self, Message* src);

void SC_Func_DoLinkTo(SCFunction* self, SCBase* B);

void SC_Func_DontWantSameReturnType(SCFunction* self, SCFunction* f);

bool SC_Func_doRefs(SCFunction* self);

bool SC_Func_EqualOrMoreSpecific(SCFunction* self, SCFunction* f);

JB_String* SC_Func_ExportNameBuilder(SCFunction* self, JB_String* CppPart);

void SC_Func_FillInConstructorAndDestructor(SCFunction* self, Message* root, bool IsConstructor, Message* SuperDot);

void SC_Func_FillInDestructor(SCFunction* self);

void SC_Func_FillInSaver(SCFunction* self, JB_String* name);

Message* SC_Func_FindCppWrapperFunc(SCFunction* self, Message* place);

void SC_Func_FindReached(SCFunction* self, SCBase* from);

void SC_Func_FixCnj(SCFunction* self, Message* exp);

void SC_Func_FixCnjSub(SCFunction* self, Message* exp);

void SC_Func_Flatten(SCFunction* self);

void SC_Func_FLookupSet(SCFunction* self, SCBase* Value);

void SC_Func_FuncDecls(SCFunction* self);

int SC_Func_HasFloatparams(SCFunction* self);

int SC_Func_HasFloatReturn(SCFunction* self);

void SC_Func_init_sub(SCFunction* self, Message* node, SCBase* name_space);

SCObject* SC_Func_InsertIn(SCFunction* self, SCBase* parent, JB_String* name);

bool SC_Func_IsAllocOrNew(SCFunction* self);

bool SC_Func_IsBehaviour(SCFunction* self);

bool SC_Func_IsConstructorOrDestructor(SCFunction* self);

bool SC_Func_IsReal(SCFunction* self);

Message* SC_Func_IsSimpleCast(SCFunction* self);

SCFunction* SC_Func_Last(SCFunction* self);

SCDecl* SC_Func_MacroFix(SCFunction* self, SCDecl* contains, SCBase* name_space, SCParamArray* Incoming);

bool SC_Func_MacroGet(SCFunction* self, SCParamArray* paramsarray, SCFunction* prev);

int SC_Func_MaxVars(SCFunction* self);

JB_String* SC_Func_NameOfClassAllocator(SCFunction* self, JB_String* s, JB_String* CppPart);

bool SC_Func_NeedsExport(SCFunction* self);

Message* SC_Func_NewDefaultRel(SCFunction* self, Message* place, SCDecl* d);

bool SC_Func_OperatorIsa(SCFunction* self, int Code);

SCFunction* SC_Func_Paramless(SCFunction* self);

JB_String* SC_Func_ParamUniquer(SCFunction* self, JB_String* s);

JB_String* SC_Func_ParentName(SCFunction* self);

bool SC_Func_ParseName(SCFunction* self, Message* cName);

void SC_Func_PostTransform(SCFunction* self);

void SC_Func_PreProcessExpects(SCFunction* self);

Message* SC_Func_prms(SCFunction* self);

void SC_Func_ReadDisabled(SCFunction* self, Message* arg);

void SC_Func_RefFunc(SCFunction* self, Message* prm, Message* after);

void SC_Func_RefSmooth(SCFunction* self, SCDecl* N);

DataTypeCode SC_Func_RegType(SCFunction* self);

JB_String* SC_Func_Render(SCFunction* self, FastString* fs_in);

JB_String* SC_Func_RenderName(SCFunction* self, FastString* fs_in);

JB_String* SC_Func_RenderParams(SCFunction* self, bool ForErrors, FastString* fs_in);

JB_String* SC_Func_RenderTitle(SCFunction* self, bool ForErrors, FastString* fs_in);

void SC_Func_SetFuncType(SCFunction* self, Message* node);

void SC_Func_StripTest(SCFunction* self);

bool SC_Func_SyntaxEquals(SCFunction* self, JB_String* name, bool Aware);

void SC_Func_TranDebugInsert(SCFunction* self);

void SC_Func_Transform(SCFunction* self);

void SC_Func_TranStrings(SCFunction* self, bool Add);

void SC_Func_TryAdd(SCFunction* self, SCBase* b);

SCFunction* SC_Func_TryKeepBetter(SCFunction* self, int OldMatch, SCFunction* f, int Match);

bool SC_Func_update_source(SCFunction* self, int start, JB_String* text, SCFile* myfile, SCObject* orig);

bool SC_Func_updateSourceSub(SCFunction* self, Message* source);

bool SC_Func_UseCppName(SCFunction* self, JB_String* CppName);

bool SC_Func_UseExportNameConstructor(SCFunction* self, JB_String* CppPart, JB_String* CppWrapper);

bool SC_Func_UseExportWrapper(SCFunction* self, JB_String* CppWrapper);

void SC_Func_ValidateSaver(SCFunction* self, JB_String* name);

int SC_Func_VisibleArgs(SCFunction* self);

JB_String* SC_Func_WrapName(SCFunction* self);

SCFunction* SC_Func__Alloc();

Message* SC_Func__AlterPostCond(Message* PostCond, Message* IterPostCond, Message* NodeSrc);

Message* SC_Func__ArgToFunc(JB_String* NewName, Message* Params, Message* arg);

bool SC_Func__CanKeepAsSource(Message* list, Message* arg, SCDecl* d);

bool SC_Func__CanKeepAsValue(SCIterator* iter, Message* arg, SCDecl* dcl, Message* value);

bool SC_Func__CollectIsaTests(Message* s, Array* out);

SCBase* SC_Func__DebugInsert(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Func__FastStringOpt(Message* s, SCBase* name_space);

Message* SC_Func__GetFileString(Message* msg, JB_String* name);

bool SC_Func__InBuiltFunc(Message* self, JB_String* name);

int SC_Func__Init_();

int SC_Func__InitCode_();

void SC_Func__Link(SCFunction* fn);

void SC_Func__LinkAll(Array* Funcs);

SCBase* SC_Func__NeuLibrary(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NeuMain(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NeuSyx(Message* node, SCBase* name_space, Message* ErrPlace);

SCFunction* SC_Func__New(Message* msg);

SCBase* SC_Func__NewConstructor(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewCppWrapper(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewDestructor(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewFunc(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewFuncSub(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewHelper(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewMissingFunc(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewProtoType(Message* node, SCBase* name_space, Message* ErrPlace);

SCModule* SC_Func__NewProtoTypeSub(Message* node, SCBase* parent, Message* ErrPlace, JB_String* ForInterface);

SCBase* SC_Func__NewRender(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewSetter(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Func__ObjectifyString(Message* msg);

void SC_Func__String_Expand(Message* msg, SCFunction* fn);

Message* SC_Func__TypedTempMoveOut(Message* msg, JB_String* name);

Message* SC_Func__TempMoveOut(Message* msg, Message* parent);

SCDecl* SC_Func__Tran_AfterRel(Message* msg, SCBase* name_space, Message* side);

void SC_Func__Tran_All(SCFunction* fn, Message* s, SCBase* p);

void SC_Func__Tran_Array(Message* S, SCBase* name_space);

void SC_Func__Tran_Beep(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Chr(Message* msg, SCFunction* fn);

void SC_Func__Tran_CppRefs(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Debugger(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Deprecate(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Description(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_DoAt(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Else(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Exit(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Expect(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_For(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_ForStart(Message* arg, Message* index, SCBase* p);

void SC_Func__Tran_ForSub(SCFunction* fn, Message* node, SCBase* name_space);

bool SC_Func__Tran_FuncTable(Message* msg);

void SC_Func__Tran_If(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Ifn(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_IfSub(int mode, Message* node, SCBase* name_space);

void SC_Func__Tran_Isa(Message* S, SCBase* p);

void SC_Func__Tran_Log(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Once(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Print(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Quit(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Rejoin(SCFunction* fn, Message* node, SCBase* name_space);

bool SC_Func__Tran_Render(Message* msg, SCClass* Cls);

bool SC_Func__Tran_RenderSub(Message* msg, SCClass* Cls);

Message* SC_Func__Tran_Result(SCFunction* f);

void SC_Func__Tran_ResultFinish(SCFunction* f, Message* r_z, SCBase* space);

void SC_Func__Tran_Return(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Sdt(Message* exp);

void SC_Func__Tran_Strings(Message* start, SCFunction* fn);

void SC_Func__Tran_Swap(SCFunction* fn, Message* node, SCBase* name_space);

Message* SC_Func__Tran_Syx(Message* msg);

void SC_Func__Tran_Temporal(SCFunction* FN, Message* s, SCBase* name_space);

void SC_Func__Tran_Using(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Visible(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_While(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__TranFuncDummy(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__TranOneIsa(Message* isa_f, Message* arg, SCBase* space);



// JB_SCIterator
void SC_Iter_Check(SCIterator* self, SCClass* cls);

void SC_Iter_Constructor(SCIterator* self, SCClass* parent);

void SC_Iter_destructor(SCIterator* self);

bool SC_Iter_InitIter(SCIterator* self, Message* msg);

Message* SC_Iter_MakeWhile(SCIterator* self, Message* arg, Message* postcond);

void SC_Iter_RenameSelf(SCIterator* self, Message* Name);

void SC_Iter_RenameValue(SCIterator* self, JB_String* s);

void SC_Iter_Renuqify(SCIterator* self, SCBase* p);

Array* SC_Iter_Uniqueify(SCIterator* self, Message* msg);

SCIterator* SC_Iter__Alloc();

int SC_Iter__Init_();

int SC_Iter__InitCode_();

SCBase* SC_Iter__NeuIter(Message* node, SCBase* name_space, Message* ErrPlace);

SCIterator* SC_Iter__New(SCClass* parent);

SCIterator* SC_Iter__SimpleIter(JB_String* src);



// JB_SCModule
void SC_Mod_AddDelayedInit(SCModule* self, Message* src, Message* dest, JB_String* fn_name);

void SC_Mod_AddInterfaceToTable(SCModule* self, SCClass* TableCls);

void SC_Mod_AddModuleToFunc(SCModule* self, SCBase* space);

void SC_Mod_BaseDecls(SCModule* self);

Message* SC_Mod_BuildInitArg(SCModule* self);

bool SC_Mod_CanGrabBase(SCModule* self, bool IsDataType);

void SC_Mod_Constructor(SCModule* self);

void SC_Mod_DelayedInitFuncTransform(SCModule* self);

void SC_Mod_destructor(SCModule* self);

void SC_Mod_FillDisposeFunc(SCModule* self);

JB_String* SC_Mod_GetPrefix(SCModule* self, SCDecl* D);

SCModule* SC_Mod_Grab(SCModule* self);

bool SC_Mod_HasActualCode(SCModule* self, Message* arg);

void SC_Mod_InitDecls(SCModule* self);

bool SC_Mod_IsMArray(SCModule* self, Message* arr);

bool SC_Mod_IsProperModule(SCModule* self);

Array* SC_Mod_ListProperties(SCModule* self);

Array* SC_Mod_ListVars(SCModule* self, bool NoFuncs);

void SC_Mod_LoadInitFunc(SCModule* self);

void SC_Mod_LoadInitFuncSub(SCModule* self, Message* init, JB_String* name);

void SC_Mod_LoadModule(SCModule* self, Message* node);

void SC_Mod_MoveToInitFunc(SCModule* self, Message* c);

SCFunction* SC_Mod_NewModuleFunc(SCModule* self, Message* src);

bool SC_Mod_OKToSort(SCModule* self);

SCModule* SC_Mod_OperatorOneOrOther(SCModule* self, SCModule* B);

void SC_Mod_RenameVars(SCModule* self);

JB_String* SC_Mod_Render(SCModule* self, FastString* fs_in);

JB_String* SC_Mod_safename(SCModule* self);

SCModule* SC_Mod_SuperMod(SCModule* self);

bool SC_Mod_TryInit(SCModule* self, Array* req);

SCModule* SC_Mod__Alloc();

SCBase* SC_Mod__DoInitAfter(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Mod__Neu(Message* node, SCBase* name_space, Message* ErrPlace);

SCModule* SC_Mod__New();

SCModule* SC_Mod__NewContainer(JB_String* s);

SCBase* SC_Mod__ReadIntoCppRefs(Message* node, SCBase* name_space, Message* ErrPlace);



// JB_String_ArgValue
inline bool JB_Arg_SyntaxCast(JB_String* self);



// JB_StringThatWasReadSafely
inline bool JB_Safe_SyntaxCast(JB_String* self);



// JB_StringZeroTerminated
_cstring JB_Str_cstring(JB_StringC* self);

inline _cstring JB_Str_SyntaxCast(JB_StringC* self);



// JB_µFunc1
void SC_ASMFunc2_destructor(ASMFunc2* self);

int64 SC_ASMFunc2_RunArgs(ASMFunc2* self, int64* Args, int ArgCount);

void SC_ASMFunc2_Visible(ASMFunc2* self);



// JB_GUIControl
void SC_GUIControl_Constructor(GUIControl* self, GUIControl* p);

void SC_GUIControl_destructor(GUIControl* self);

GUIControl* SC_GUIControl__Alloc();

GUIControl* SC_GUIControl__New(GUIControl* p);



// JB_Message
void JB_Msg_Acc__(Message* self, FastString* fs);

Message* JB_Msg_AccessAdd(Message* self, JB_String* key);

void JB_Msg_CantFind(Message* self, Syntax s, JB_String* name, Message* found);

void JB_Msg_AddBefore(Message* self, Message* before, Message* NewItem);

void JB_Msg_Adj__(Message* self, FastString* fs);

int JB_Msg_After(Message* self);

void JB_Msg_AfterSet(Message* self, int Value);

bool JB_Msg_AllowedMoveToInit(Message* self);

Message* JB_Msg_Ancestor(Message* self, Syntax f);

uint JB_Msg_AndOrExpansionTest(Message* self);

JB_String* JB_Msg_APICppProject(Message* self);

void JB_Msg_AppMainFix(Message* self);

void JB_Msg_ARel__(Message* self, FastString* fs);

void JB_Msg_Arg__(Message* self, FastString* fs);

JB_String* JB_Msg_ArgName(Message* self);

JB_String* JB_Msg_ArgValue(Message* self);

void JB_Msg_Arr__(Message* self, FastString* fs);

SCArg* JB_Msg_AsArg(Message* self);

SCDecl* JB_Msg_AsDecl(Message* self);

SCFunction* JB_Msg_AsFunc(Message* self);

void JB_Msg_Ask__(Message* self, FastString* fs);

uint64 JB_Msg_ASMConst(Message* self);

fn_asm JB_Msg_ASMFunc(Message* self);

SCModule* JB_Msg_AsModule(Message* self);

void JB_Msg_AssignsFix(Message* self, SCFunction* f);

int JB_Msg_autocomplete_state(Message* self);

SCFunction* JB_Msg_AutoMsgFunc(Message* self);

SCFunction* JB_Msg_AutoMsgFuncFn(Message* self);

void JB_Msg_Back__(Message* self, FastString* fs);

void JB_Msg_Badj__(Message* self, FastString* fs);

void JB_Msg_BecomeStr(Message* self, Syntax fn, JB_String* name);

void JB_Msg_BecomeNum(Message* self, int64 num);

void JB_Msg_BecomeMsg(Message* self, Message* src);

void JB_Msg_BecomeMacro(Message* self, Macro* b, Array* prms);

void JB_Msg_BecomeAppend(Message* self, JB_String* s);

void JB_Msg_BecomeSyx(Message* self);

void JB_Msg_BeLike(Message* self, Message* belikeme);

void JB_Msg_Bin__(Message* self, FastString* fs);

void JB_Msg_binn__(Message* self, FastString* fs);

void JB_Msg_BinnRender(Message* self, FastString* fs, JB_String* sepa, JB_String* sepb);

void JB_Msg_Bra__(Message* self, FastString* fs);

void JB_Msg_BRel__(Message* self, FastString* fs);

void JB_Msg_BunchFix(Message* self);

Message* JB_Msg_BunchFixOof(Message* self);

void JB_Msg_BunchFixSub(Message* self, Message* subject, Message* stuff);

void JB_Msg_BunchlessFix(Message* self);

bool JB_Msg_CanGetAddress(Message* self, SCBase* name_space, bool DoErr);

Message* JB_Msg_CastedParent(Message* self);

int JB_Msg_CastToBool(Message* self, SCBase* name_space);

int JB_Msg_CastToClass(Message* self, SCClass* type, SCBase* name_space);

int JB_Msg_CastToType(Message* self, JB_String* TypeName, SCClass* type, SCBase* name_space, int loss);

int JB_Msg_CastToVoidPtr(Message* self, SCBase* name_space);

Message* JB_Msg_CausesUnReachable(Message* self, Message* arg, Message* Curr, Message* LastPlace);

void JB_Msg_Char__(Message* self, FastString* fs);

void JB_Msg_CheckSuperDotSave(Message* self, JB_String* name, bool ShouldBe);

void JB_Msg_Clean(Message* self, bool erl);

int JB_Msg_CleanIndent(Message* self);

Message* JB_Msg_CmdImprove(Message* self);

void JB_Msg_Cnj__(Message* self, FastString* fs);

JB_String* JB_Msg_CollectFuncTableName(Message* self);

Message* JB_Msg_CollectionPlace(Message* self);

Message* JB_Msg_ConfArg(Message* self);

Message* JB_Msg_ConstantExpandSub(Message* self);

bool JB_Msg_ConstIntValue(Message* self, SCBase* name_space, int64* v);

bool JB_Msg_ConstIntValueSub(Message* self, SCBase* name_space, int64* v);

void JB_Msg_ConstructorCopy(Message* self, Message* other);

void JB_Msg_ConstructorNormal(Message* self, Syntax Func, JB_String* Name);

void JB_Msg_ConstructorRange(Message* self, Message* Parent, Syntax Func, int BytePos, JB_String* name, int RangeLength);

Message* JB_Msg_Copy(Message* self, Message* pos_msg);

void JB_Msg_CopyAllAfter(Message* self, Message* after, Message* copylayer);

void JB_Msg_CopyAllAfterBefore(Message* self, Message* Before, Message* copylayer);

void JB_Msg_CopyAllAfterInto(Message* self, Message* into, Message* copylayer);

void JB_Msg_CopyAllBefore(Message* self, Message* Before, Message* copylayer);

void JB_Msg_CopyAllBeforeInto(Message* self, Message* into, Message* copylayer);

void JB_Msg_CopyAllInto(Message* self, Message* j, bool wipe);

JB_String* JB_Msg_copyid(Message* self);

JB_String* JB_Msg_cpp_wrapper(Message* self);

Message* JB_Msg_createnil(Message* self);

Message* JB_Msg_CreateOwnBlock(Message* self, bool ForSelf);

Message* JB_Msg_CutifyCopy(Message* self);

Message* JB_Msg_DclExp(Message* self);

void JB_Msg_Decl__(Message* self, FastString* fs);

Message* JB_Msg_DeclName(Message* self);

bool JB_Msg_DeepEquals(Message* self, Message* B, bool Aware);

Message* JB_Msg_Deepest(Message* self, Syntax Tmp, JB_String* name);

void JB_Msg_destructor(Message* self);

bool JB_Msg_DoesAnything(Message* self);

void JB_Msg_Dot__(Message* self, FastString* fs);

int JB_Msg_DotType(Message* self);

void JB_Msg_Dummy(Message* self, FastString* fs);

void JB_Msg_Emb__(Message* self, FastString* fs);

void JB_Msg_ERel__(Message* self, FastString* fs);

bool JB_Msg_Expect(Message* self, Syntax type, JB_String* name);

bool JB_Msg_ExpectClass(Message* self, SCDecl* slf, SCClass* Cls);

bool JB_Msg_ExpectInt(Message* self, SCDecl* type);

bool JB_Msg_ExpectLast(Message* self, JB_String* err);

bool JB_Msg_expectmatch(Message* self, SCBase* name_space, SCClass* With);

Message* JB_Msg_ExpectParamsTransform(Message* self, int P, Message* errnode, JB_String* Type);

SCFunction* JB_Msg_expfunc(Message* self);

void JB_Msg_Export(Message* self, FastString* fs);

Message* JB_Msg_FailOrCopy(Message* self, Message* p);

void JB_Msg_File__(Message* self, FastString* fs);

JB_String* JB_Msg_FileLocation(Message* self);

JB_String* JB_Msg_FilePath(Message* self);

Message* JB_Msg_FindSyx(Message* self, Syntax s);

Message* JB_Msg_FindSyxName(Message* self, Syntax s, JB_String* name);

Message* JB_Msg_FindName(Message* self, JB_String* name);

Array* JB_Msg_FindAllDclNames(Message* self);

Array* JB_Msg_FindAllDcls(Message* self);

JB_String* JB_Msg_FindAndRemove(Message* self, JB_String* name, bool NothingOK, bool IsClass);

Message* JB_Msg_FindAndRemove2(Message* self, Message* place, bool NothingOK, bool IsClass);

Message* JB_Msg_FindAndRemoveSub(Message* self, JB_String* name, bool NothingOK, bool IsClass);

int JB_Msg_FindClassOption(Message* self, JB_String* name, JB_String* Kind);

Message* JB_Msg_FindDestructor(Message* self);

Message* JB_Msg_FindFlat(Message* self, Syntax s, JB_String* name, bool Err);

Message* JB_Msg_FindNested(Message* self, Syntax fn, JB_String* name, bool Err);

Message* JB_Msg_FindOwningLoop(Message* self, Message* top);

Message* JB_Msg_FindPos(Message* self, int fr, int len);

Message* JB_Msg_FindPosSub(Message* self, int fr, int len, bool Exact);

Message* JB_Msg_FindRef(Message* self, SCFunction* fn, JB_String* name);

Message* JB_Msg_FindShader(Message* self, JB_String* TypeName);

void JB_Msg_FixElseif(Message* self);

void JB_Msg_FixErl(Message* self);

void JB_Msg_FixMultiArr(Message* self);

double JB_Msg_Float(Message* self);

float JB_Msg_float32(Message* self);

void JB_Msg_FSListArg(Message* self, FastString* fs);

void JB_Msg_FSListSep(Message* self, FastString* fs, JB_String* sep);

Message* JB_Msg_FullAfter(Message* self);

void JB_Msg_Func__(Message* self, FastString* fs);

JB_String* JB_Msg_FuncName(Message* self);

int JB_Msg_FuncPos(Message* self, SCFunction* fn);

void JB_Msg_FuncWrap(Message* self, Message* fnc);

int JB_Msg_GetAddressOf(Message* self, SCDecl* Type, bool WasCArray);

void JB_Msg_GetAddressOf2(Message* self);

Message* JB_Msg_GetASMFunc(Message* self);

Message* JB_Msg_GetDclName(Message* self);

Message* JB_Msg_GetMarker(Message* self, JB_String* s);

Message* JB_Msg_GetTypeLimiter(Message* self);

Message* JB_Msg_GiveArg(Message* self);

Message* JB_Msg_GoIntoInvisArg(Message* self, Message* tmp, int pos);

Message* JB_Msg_HasOwnBlock(Message* self);

bool JB_Msg_HasPosition(Message* self);

SCFunction* JB_Msg_IdentifyFunc(Message* self);

Message* JB_Msg_InbuiltSizeOf(Message* self, SCBase* name_space, SCDecl* sulf, Message* sulf_exp);

int JB_Msg_IndentScore(Message* self);

bool JB_Msg_InInvisArg(Message* self);

bool JB_Msg_InitExpand(Message* self);

bool JB_Msg_InitRootDecl(Message* self, Message* before, SCBase* name_space);

void JB_Msg_InsertAfter(Message* self, Message* j, Message* ch);

void JB_Msg_InsertBefore(Message* self, Message* j, Message* ch);

SCFunction* JB_Msg_InsideFunc(Message* self);

int64 JB_Msg_Int(Message* self, int i);

NameAndMsg JB_Msg_IntoVariable(Message* self, SCBase* name_space);

bool JB_Msg_IsAssignable(Message* self);

bool JB_Msg_IsClassType(Message* self);

bool JB_Msg_IsContainer(Message* self);

Message* JB_Msg_IsInDeclInBlock(Message* self);

bool JB_Msg_isint(Message* self);

bool JB_Msg_IsLast(Message* self);

bool JB_Msg_IsModuleType(Message* self);

SCFunction* JB_Msg_IsParentConCall(Message* self);

bool JB_Msg_IsProperty(Message* self);

bool JB_Msg_IsReffer(Message* self);

bool JB_Msg_IsReturnOrRejoin(Message* self);

Message* JB_Msg_IsSetIntoPlace(Message* self);

Message* JB_Msg_IsSetIntoVar(Message* self);

bool JB_Msg_IsSetRel(Message* self);

bool JB_Msg_IsStatementExpr(Message* self);

bool JB_Msg_IsType(Message* self, int Allowed);

bool JB_Msg_IsTypeOfDecl(Message* self);

bool JB_Msg_IsVarAltered(Message* self, JB_String* name);

bool JB_Msg_IsVarUseableInLoop(Message* self, JB_String* name);

bool JB_Msg_iszero(Message* self);

void JB_Msg_Item__(Message* self, FastString* fs);

bool JB_Msg_jbinTest(Message* self);

JB_String* JB_Msg_jdb2_(Message* self, int Flags, FastString* fs_in);

JB_String* jdb4(Message* self);

JB_String* JB_Msg_jdb4_(Message* self, FastString* fs_in);

JB_String* JB_Msg_jdb_(Message* self, FastString* fs_in, int flags);

Message* JB_Msg_Last(Message* self, Syntax Need);

Message* JB_Msg_LastUsedFix(Message* self);

int JB_Msg_Length(Message* self);

bool JB_Msg_LinkageType(Message* self);

void JB_Msg_List__(Message* self, FastString* fs);

Array* JB_Msg_ListAll(Message* self);

bool JB_Msg_ListViewable(Message* self);

JB_String* JB_Msg_Locate(Message* self);

void JB_Msg_LocateAll(Message* self);

Message* JB_Msg_MacroAvoidCopy(Message* self);

Message* JB_Msg_MacroCopy(Message* self, Message* root, Array* prms);

Message* JB_Msg_MacroDot(Message* self, Message* prm);

int JB_Msg_MacroFixCount(Message* self);

Message* JB_Msg_MacroPrm(Message* self, Message* root, Array* prms);

void JB_Msg_MiniArgCpp(Message* self, FastString* fs);

JB_String* JB_Msg_MiniName(Message* self);

void JB_Msg_MiniTran(Message* self, SCBase* name_space, JB_String* On);

int JB_Msg_ModelMode(Message* self);

Message* JB_Msg_ModelType(Message* self);

Message* JB_Msg_ModuleSrc(Message* self);

void JB_Msg_Move(Message* self, Message* last, Message* into);

void JB_Msg_MoveAllAfter(Message* self, Message* after);

void JB_Msg_MoveAllIn(Message* self, Message* Dest);

Message* JB_Msg_Msg(Message* self, Syntax fn, JB_String* name);

void JB_Msg_Msg__(Message* self, FastString* fs);

SCArg* JB_Msg_MsgArg(Message* self);

SCDecl* JB_Msg_MsgDecl(Message* self);

SCFunction* JB_Msg_MsgFunc(Message* self);

SCFunction* JB_Msg_MsgOwningFunc(Message* self);

void JB_Msg_Name__(Message* self, FastString* fs);

Message* JB_Msg_NeedBra(Message* self);

Message* JB_Msg_NeedMarker(Message* self, JB_String* s, bool b);

bool JB_Msg_NeedsPreprocess(Message* self);

Message* JB_Msg_Negate(Message* self);

Message* JB_Msg_NextOf(Message* self, Syntax Need, JB_String* Name);

Message* JB_Msg_NextOf2(Message* self, Syntax Need, Syntax OK);

SCDecl* JB_Msg_NiceIsFlagSyntax(Message* self, Message* list, Message* RN, SCBase* name_space, Message* side);

Message* JB_Msg_NiceParent(Message* self);

void JB_Msg_Nil__(Message* self, FastString* fs);

bool JB_Msg_NoPointlessBlockRefs(Message* self, Message* dcl);

Message* JB_Msg_NormaliseFunc(Message* self);

void JB_Msg_NotNilRZ(Message* self, SCDecl* type, SCBase* space);

void JB_Msg_Num__(Message* self, FastString* fs);

JB_String* JB_Msg_Nyme(Message* self);

bool JB_Msg_OarExpand(Message* self);

void JB_Msg_Oat__(Message* self, FastString* fs);

bool JB_Msg_ContainsSyx(Message* self, Syntax s);

bool JB_Msg_OperatorIn(Message* self, Syntax f);

bool JB_Msg_OperatorIsARel(Message* self, JB_String* name);

bool JB_Msg_OperatorIsBRel(Message* self, JB_String* name);

bool JB_Msg_OperatorIsDot(Message* self, JB_String* name);

bool JB_Msg_OperatorIsRel(Message* self, JB_String* name);

bool JB_Msg_OperatorIsThing(Message* self, JB_String* name);

bool JB_Msg_OperatorIsTmp(Message* self, JB_String* name);

bool JB_Msg_OperatorStarts(Message* self, JB_String* s);

void JB_Msg_Opp__(Message* self, FastString* fs);

bool JB_Msg_OppExpand(Message* self);

int JB_Msg_OpScore(Message* self);

JB_String* JB_Msg_OriginalParseData(Message* self);

JB_MemoryLayer* JB_Msg_OriginalParseLayer(Message* self);

int JB_Msg_ParamNum(Message* self);

Message* JB_Msg_ParentPoint(Message* self);

Message* JB_Msg_ParseShaderSub(Message* self);

void JB_Msg_pinn__(Message* self, FastString* fs);

Message* JB_Msg_PoorAnt(Message* self);

void JB_Msg_PrepareAST(Message* self);

int JB_Msg_PrevIndentCheck(Message* self, Message* pr);

void JB_Msg_Prm__(Message* self, FastString* fs);

void JB_Msg_Ques__(Message* self, FastString* fs);

void JB_Msg_Quot__(Message* self, FastString* fs);

IntRange JB_Msg_range(Message* self);

void JB_Msg_rangeSet(Message* self, IntRange r);

int JB_Msg_RC_HasTemporary(Message* self);

bool JB_Msg_RefDisappears(Message* self);

uint JB_Msg_Reg(Message* self);

uint JB_Msg_RegOrNum(Message* self, bool NeedReg);

void JB_Msg_Rel__(Message* self, FastString* fs);

bool JB_Msg_RelFix(Message* self, bool force);

void JB_Msg_RemoveElseIf(Message* self);

Message* JB_Msg_RemoveTypeCasts(Message* self);

JB_String* JB_Msg_Render(Message* self, FastString* fs_in);

JB_String* JB_Msg_render_jbin(Message* self, JB_String* sheb, FastString* fs_in);

void JB_Msg_RenderPrm(Message* self, FastString* fs, byte b1, byte b2);

JB_String* JB_Msg_RenderType(Message* self);

JB_String* JB_Msg_RenderTypeAndName(Message* self);

void JB_Msg_RenderWithSpaces(Message* self, FastString* fs, Message* ch);

void JB_Msg_ReplaceInbuilt(Message* self, SCBase* name_space, SCDecl* sulf, Message* sulf_exp);

Message* JB_Msg_ReplaceInbuiltSub(Message* self, SCBase* name_space, SCDecl* self_decl, Message* self_exp);

Message* JB_Msg_ReplaceInto(Message* self, Message* w);

Message* JB_Msg_ReplaceWith(Message* self, Message* j);

Message* JB_Msg_ReplaceWithChild(Message* self);

JB_Object* JB_Msg_RestoreLoad(Message* self);

Message* JB_Msg_Resync(Message* self, Message* parent);

void JB_Msg_safe(Message* self, FastString* fs);

void JB_Msg_SafeRemove(Message* self, Syntax T);

void JB_Msg_SafeReplaceWith(Message* self, Message* Incoming);

SCArg* JB_Msg_SCArg(Message* self, SCBase* p, Message* avoid);

SCArg* JB_Msg_SCArgNested(Message* self, Message* base, SCBase* p);

SCFile* JB_Msg_SCFile(Message* self);

void JB_Msg_SCnj__(Message* self, FastString* fs);

void JB_Msg_SCom__(Message* self, FastString* fs);

void JB_Msg_SDot__(Message* self, FastString* fs);

bool JB_Msg_SettingToNil(Message* self);

bool JB_Msg_ShallowEquals(Message* self, Message* B, bool Aware);

void JB_Msg_Sheb__(Message* self, FastString* fs);

void JB_Msg_SlidePositions(Message* self, int add);

void JB_Msg_SStr__(Message* self, FastString* fs);

void JB_Msg_SThg__(Message* self, FastString* fs);

void JB_Msg_Str__(Message* self, FastString* fs);

Message* JB_Msg_NeedSyxOK(Message* self, Syntax Need, Syntax OK);

Message* JB_Msg_NeedSyx(Message* self, Syntax s);

Message* JB_Msg_NeedSyxInt(Message* self, Syntax s, int n);

Message* JB_Msg_NeedSyxName(Message* self, Syntax s, JB_String* name);

void JB_Msg_SetStr(Message* self, JB_String* key, JB_String* Value);

void JB_Msg_SetMsg(Message* self, JB_String* key, Message* Value);

Message* JB_Msg_GetConf(Message* self, JB_String* key, bool Err);

void JB_Msg_SyntaxAppend(Message* self, JB_String* key);

void JB_Msg_AppendSyx(Message* self, Syntax Fn, JB_String* name);

void JB_Msg_AppendNum(Message* self, int64 Num);

void JB_Msg_SyntaxDeprecate(Message* self, JB_String* Error);

bool JB_Msg_SyntaxEquals(Message* self, JB_String* name, bool Aware);

bool JB_Msg_EqualsSyx(Message* self, Syntax X, bool Aware);

void JB_Msg_SyntaxExpect(Message* self, JB_String* Error);

bool JB_Msg_SyntaxIs(Message* self, MsgUIFlags F);

void JB_Msg_SyntaxIsSet(Message* self, MsgUIFlags F, bool Value);

bool JB_Msg_SyntaxIsnt(Message* self, MsgUIFlags F);

MessagePosition JB_Msg_SyntaxUsing(Message* self);

void JB_Msg_SyntaxWarn(Message* self, JB_String* Error);

bool JB_Msg_TargetTest(Message* self);

Message* JB_Msg_TempIntoBlock(Message* self, Message* ParentPlace);

void JB_Msg_Test(Message* self, JB_String* new_render, JB_String* name);

void JB_Msg_test_style(Message* self);

bool JB_Msg_TestFuncName(Message* self);

bool JB_Msg_TestSub(Message* self, JB_String* new_render, JB_String* name);

JB_String* JB_Msg_text(Message* self, int i);

bool JB_Msg_textset(Message* self, int i, JB_String* v);

Message* JB_Msg_TheTmpVarOf(Message* self, JB_String* tmpname);

void JB_Msg_Thg__(Message* self, FastString* fs);

void JB_Msg_Tmp__(Message* self, FastString* fs);

void JB_Msg_Todo__(Message* self, FastString* fs);

void JB_Msg_Tran_Isnt(Message* self, JB_String* name);

void JB_Msg_Tran_QMark(Message* self);

Message* JB_Msg_tran_target(Message* self);

void JB_Msg_Tran_TargetSub(Message* self);

void JB_Msg_Tran_With(Message* self);

Message* JB_Msg_TranModel(Message* self);

void JB_Msg_TRel__(Message* self, FastString* fs);

void JB_Msg_Tril__(Message* self, FastString* fs);

bool JB_Msg_TrueOrFalse(Message* self);

Message* JB_Msg_tviewch(Message* self);

void JB_Msg_Type__(Message* self, FastString* fs);

Message* JB_Msg_TypeOfArrItem(Message* self);

Message* JB_Msg_UnBra(Message* self);

Message* JB_Msg_UnBraType(Message* self);

void JB_Msg_UnEmbed(Message* self);

void JB_Msg_Unit__(Message* self, FastString* fs);

bool JB_Msg_unitmatch(Message* self, JB_String* a, JB_String* b);

Message* JB_Msg_UnReachable(Message* self);

void JB_Msg_url__(Message* self, FastString* fs);

Message* JB_Msg_UseNonRefChangers(Message* self, bool parent);

JB_String* JB_Msg_Value(Message* self);

Message* JB_Msg_WantAsArg(Message* self, Message* ErrPlace, JB_String* errmsg);

Message* JB_Msg_LayerWipeCopy(Message* self, Message* oof);

Message* JB_Msg_WipeCopy(Message* self);

void JB_Msg_WipePositions(Message* self);

void JB_Msg_WithDeclTransform(Message* self, Message* decl, Message* rel, Message* arg);

JB_String* JB_Msg_WithDirectName(Message* self, Message* p);

bool JB_Msg_WithinLoop(Message* self, Message* stop);

int JB_Msg_WrapExpr(Message* self, SCDecl* src);

void JB_Msg_WrapFloatOrInt(Message* self, DataTypeCode T, int N, SCDecl* D);

Message* JB_Msg_WrapWith(Message* self, Message* W);

void JB_Msg_XAtt__(Message* self, FastString* fs);

void JB_Msg_XCDT__(Message* self, FastString* fs);

void JB_Msg_XCom__(Message* self, FastString* fs);

void JB_Msg_XML__(Message* self, FastString* fs);

void JB_Msg_XPI__(Message* self, FastString* fs);

void JB_Msg_XTxt__(Message* self, FastString* fs);

void JB_Msg_Yoda__(Message* self, FastString* fs);

Message* JB_Msg__Alloc();

SyntaxObj* JB_Msg__GetFunc(Message* msg);

Message* JB_Msg__LayerAlloc(JB_MemoryLayer* _L);

Message* JB_Msg__NewCopy(Message* other);

Message* JB_Msg__NewNormal(Syntax Func, JB_String* Name);

Message* JB_Msg__NewRange(Message* Parent, Syntax Func, int BytePos, JB_String* name, int RangeLength);

Message* JB_Msg__NewWithLayerCopy(JB_MemoryLayer* _L, Message* other);

Message* JB_Msg__NewWithLayerNormal(JB_MemoryLayer* _L, Syntax Func, JB_String* Name);

bool JB_Msg__TreeCompare(Message* orig, Message* reparse, bool PrintIfSame);



// JB_MessageRoot


// JB_SCArg
void SC_Arg_Constructor(SCArg* self, Message* node);

int SC_Arg_Count(SCArg* self);

void SC_Arg_destructor(SCArg* self);

JB_String* SC_Arg_Render(SCArg* self, FastString* fs_in);

SCArg* SC_Arg__Alloc();

SCArg* SC_Arg__New(Message* node);



// JB_StretchControl
void SC_StretchControl_xxxtest(GUIControl* self, GUIControl* p);



// JB_TreeView


// JB_TreeViewRow


// JB_config
Message* JB_config_conffirst(Message* self);

bool JB_config_Save(Message* self);



// JB_Error
void JB_Err_Constructor(JB_Error* self, Message* node, JB_String* desc, ErrorSeverity level, JB_String* path);

void JB_Err_destructor(JB_Error* self);

void JB_Err_Fill(JB_Error* self, JB_String* path, JB_String* desc);

void JB_Err_GrabLine(JB_Error* self, FastString* fs, bool Usecolor);

bool JB_Err_HasPosition(JB_Error* self);

void JB_Err_Improve(JB_Error* self);

bool JB_Err_IsError(JB_Error* self);

bool JB_Err_IsWarning(JB_Error* self);

bool JB_Err_LineIdentifiers(JB_Error* self, FastString* fs, JB_String* path);

int JB_Err_LinePos(JB_Error* self, JB_String* data);

bool JB_Err_NeedsPrint(JB_Error* self);

JB_String* JB_Err_render(JB_Error* self, FastString* fs_in);

JB_String* JB_Err_render_clang(JB_Error* self, FastString* fs_in);

JB_String* JB_Err_render_unix(JB_Error* self, FastString* fs_in);

void JB_Err_SCGrabLine(JB_Error* self, FastString* fs, bool Usecolor);

int JB_Err_SCLineCount(JB_Error* self);

void JB_Err_SCLineIdentifiers(JB_Error* self, FastString* fs, JB_String* Data);

JB_String* JB_Err_SCOriginalData(JB_Error* self);

JB_String* JB_Err_SCOriginalPath(JB_Error* self);

JB_String* JB_Err_SCRender(JB_Error* self, FastString* fs_in);

bool JB_Err_SyntaxIs(JB_Error* self, ErrorFlags F);

void JB_Err_SyntaxIsSet(JB_Error* self, ErrorFlags F, bool Value);

bool JB_Err_SyntaxIsnt(JB_Error* self, ErrorFlags F);

JB_Error* JB_Err__Alloc();

void JB_Err__CantParseNum(Message* Where, JB_String* num, int Pos);

int JB_Err__Init_();

int JB_Err__InitCode_();

JB_Error* JB_Err__New(Message* node, JB_String* desc, ErrorSeverity level, JB_String* path);



// JB_FileArchive


// JB_TreeViewRoot

//// HEADER Inlines.h
inline bool JB_int_OperatorInRange(int self, int d) {
	return (((uint)self) < ((uint)d));
}

inline bool JB_int64_OperatorInRange(int64 self, int64 d) {
	return (((uint64)self) < ((uint64)d));
}

inline int JB_uint64_lelength(uint64 self) {
	return (JB_int_OperatorMax(JB_Int_Log2(((int)self)), 0)) >> 3;
}

inline uint64 SC_TM_ClearBit(__junktest_7__ self, uint64 i) {
	//visible;
	__junktest_7__ x = kSC__TM_Halfmap;
	float x2 = kSC__TM_BaseShrinkSpeed;
	return self & (~(((uint64)1) << i));
}

inline bool JB_ErrorInt_SyntaxCast(ErrorInt self) {
	return self == 0;
}

inline bool JB_Ind_SyntaxCast(Ind self) {
	return self >= 0;
}

inline bool JB_IPCState_SyntaxCast(IPCState self) {
	return (self >= kJB__IPCState_Waiting) and (self < kJB__IPCState_closed);
}

inline IR* SC_flat_AddASM(ASMFuncState* self, Message* dbg, int SM, int a, int b, int c, int d) {
	IR* rz = nil;
	rz = SC_flat_RequestOp2(self, SM);
	rz->r[0] = a;
	rz->r[1] = b;
	rz->r[2] = c;
	rz->r[3] = d;
	(SC_IR_debugSet(rz, dbg));
	return rz;
}

inline void SC_flat_AddExtended(ASMFuncState* self, Message* err, uint Bits) {
	int B = 1 << 31;
	if (((bool)(Bits & B))) {
		JB_Msg_SyntaxExpect(err, nil);
		return;
	}
	SC_flat_RequestOp2(self, kSC__ASM_Extended)->Rest = (Bits | B);
}

inline IR* SC_flat_RequestOp2(ASMFuncState* self, uint Code) {
	IR* rz = nil;
	rz = SC_flat_RequestOp(self);
	rz->Op = Code;
	return rz;
}

inline int SC_Reg_ToInt(AsmReg* self) {
	return self->Reg;
}

inline JB_String* JB_Object___Render__(JB_Object* self, FastString* fs_in) {
	Object_Behaviour* Table = ((Object_Behaviour*)JB_ObjClassBehaviours(self));
	return (Table->render)(self, fs_in);
}

inline bool JB_DictionaryReader_SyntaxCast(DictionaryReader* self) {
	return JB_Nav_MoveNext(self);
}

inline JB_String* JB_FS_SyntaxCast(FastString* self) {
	return JB_FS_GetResult(self);
}

inline void JB_Sav___LoadProperties__(Saveable* self, ObjectLoader* Loader) {
	Saveable_Behaviour* Table = ((Saveable_Behaviour*)JB_ObjClassBehaviours(self));
	return (Table->loadproperties)(self, Loader);
}

inline void JB_Sav___SaveCollect__(Saveable* self, ObjectSaver* Saver) {
	Saveable_Behaviour* Table = ((Saveable_Behaviour*)JB_ObjClassBehaviours(self));
	return (Table->savecollect)(self, Saver);
}

inline void JB_Sav___SaveWrite__(Saveable* self, ObjectSaver* Saver) {
	Saveable_Behaviour* Table = ((Saveable_Behaviour*)JB_ObjClassBehaviours(self));
	return (Table->savewrite)(self, Saver);
}

inline bool SC_PA_SyntaxCast(SCParamArray* self) {
	return self->HasProperParams;
}

inline uint JB_Sel_UCast(Selector* self) {
	return self->ID;
}

inline JB_StringC* JB_Str_CastZero(JB_String* self) {
	return JB_Str_MakeC(self);
}

inline bool JB_ss_SyntaxCast(StringStream* self) {
	if ((!(self != nil))) {
		return nil;
	}
	return (JB_int_OperatorInRange(self->Position, self->Length));
}

inline bool JB_Array_SyntaxCast(Array* self) {
	return ((bool)self) and (JB_Array_Size(self) >= 1);
}

inline bool JB_File_SyntaxCast(JB_File* self) {
	return self != nil;
}

inline bool JB_Arg_SyntaxCast(JB_String* self) {
	return JB_Str_Yes(self);
}

inline bool JB_Safe_SyntaxCast(JB_String* self) {
	JB_Object* o = ((JB_Object*)self);
	return (o != JB_Str__Error()) and (o != nil);
}

inline _cstring JB_Str_SyntaxCast(JB_StringC* self) {
	return JB_Str_cstring(self);
}


//// HEADER SyntaxConstants.h
#define kSyxNil 0
#define kSyxArg 1
#define kSyxBra 2
#define kSyxThg 3
#define kSyxOpp 4
#define kSyxCnj 5
#define kSyxTmp 6
#define kSyxName 7
#define kSyxQues 8
#define kSyxBack 9
#define kSyxChar 10
#define kSyxSStr 11
#define kSyxOat 12
#define kSyxSheb 13
#define kSyxStr 14
#define kSyxSThg 15
#define kSyxSCnj 16
#define kSyxNum 17
#define kSyxEmb 18
#define kSyxUnit 19
#define kSyxType 20
#define kSyxARel 21
#define kSyxDot 22
#define kSyxSDot 23
#define kSyxFunc 24
#define kSyxBRel 25
#define kSyxAdj 26
#define kSyxBadj 27
#define kSyxAcc 28
#define kSyxArr 29
#define kSyxItem 30
#define kSyxList 31
#define kSyxPrm 32
#define kSyxFile 33
#define kSyxQuot 34
#define kSyxDecl 35
#define kSyxRel 36
#define kSyxERel 37
#define kSyxTRel 38
#define kSyxTril 39
#define kSyxpinn 40
#define kSyxbinn 41
#define kSyxAsk 42
#define kSyxYoda 43
#define kSyxSCom 44
#define kSyxMsg 45
#define kSyxTodo 46
#define kSyxurl 47
#define kSyxXAtt 48
#define kSyxXML 49
#define kSyxXPI 50
#define kSyxXCom 51
#define kSyxXCDT 52
#define kSyxXTxt 53
#define kSyxBin 54


}
#endif // __JB_H__
