

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

typedef u16 ASMtmp;

typedef byte CharProp;

typedef uint Codepoint;

typedef byte ControlClipMode;

typedef ivec2 ControlLine;

typedef int ControlPoint;

typedef ivec4 ControlRect;

typedef u16 DataTypeCode;

typedef int64 Date;

typedef uint DeclMode;

typedef uint DotUseType;

typedef byte ErrorFlags;

typedef int ErrorInt;

typedef ivec2 ErrorInt2;

typedef uint ErrorMarker;

typedef byte ErrorSeverity;

typedef int FileMode;

typedef bool FileResolveMode;

typedef int64 FileSizeInt;

typedef vec4 FloatRangeConverter;

typedef vec2 FloatRangeConverterBasic;

typedef uint FlowControlStopper;

typedef uint FunctionType;

typedef int Ind;

typedef ivec2 IntRange;

typedef uint JSM;

typedef byte MaybeBool;

typedef u16 MsgParseFlags;

typedef uint NilCheckMode;

typedef uint64 NilRecord;

typedef byte NilState;

typedef int PID_Int;

typedef byte ProcessMode;

typedef int SCBaseInfo;

typedef byte SCBaseType;

typedef uint SCBlockage;

typedef uint SCDeclInfo;

typedef int SizeInt;

typedef byte Syntax;

typedef int TerminalColor;

typedef uint U24_8;

typedef uint64 __junktest_7__;

typedef vec4 mat2;

typedef byte nilreason;

typedef u16 ASMParam;

typedef JSM ASM;

typedef ASM ASM_BFLD;

typedef ASM ASM_Bra;

typedef ASM ASM_CNTC;

typedef ASM ASM_CNTR;

typedef ASM ASM_Cmp;

typedef ASM ASM_CmpEq;

typedef ASM ASM_Const;

typedef ASM ASM_Func;

typedef ASM ASM_Mem;

typedef ASM ASM_SWAP;

typedef ASM ASM_Setn;

typedef ASM ASM_U0;

typedef ASM ASM_U1;

typedef ASM ASM_U2;

typedef ASM ASM_U3;

typedef ASM ASM_U4;

struct ASMFuncState;

struct ASMVarType;

struct ArchonPurger;

struct ArgArrayCounter;

struct AsmReg;

struct CharProps;

struct CompressionStats;

struct ContainerStruct;

struct ContainerStruct2;

struct FakeJBString;

struct FastBuff;

struct FloatRange;

struct IR;

struct IntDownRange;

struct IsaTester;

struct LoopInfo;

struct Mat4;

struct MessagePosition;

struct ModelTest;

struct NameAndMsg;

struct NilRecorder;

struct ObjectLoader;

struct ObjectSaver;

struct Object_Behaviour;

struct ParserLineAndIndent;

struct Random;

struct RetroFloat;

struct SpeedTester;

struct StringDigitIterator;

struct StringLengthSplit;

struct StructSaveTest;

struct uint24;

struct Object_Behaviour;

struct ByteMap_Behaviour;

struct Charset_Behaviour;

struct CppRefs_Behaviour;

struct Cpp_Export_Behaviour;

struct DataTypeWrapper_Behaviour;

struct DictionaryReader_Behaviour;

struct ErrorReceiver_Behaviour;

struct FastString_Behaviour;

struct FileComparer_Behaviour;

struct FixedDict_Behaviour;

struct FlowControl_Behaviour;

struct Instruction_Behaviour;

struct LeakTester_Behaviour;

struct Macro_Behaviour;

struct MemoryLayer_Behaviour;

struct Memory_Behaviour;

struct NilTest_Behaviour;

struct ProcessOwner_Behaviour;

struct SCImport_Behaviour;

struct SCNodeRenamer_Behaviour;

struct SCObject_Behaviour;

struct SCOperator_Behaviour;

struct SCParamArray_Behaviour;

struct Saveable_Behaviour;

struct Selector_Behaviour;

struct StringFields_Behaviour;

struct StringReader_Behaviour;

struct String_Behaviour;

struct SyntaxObj_Behaviour;

struct TerminalCell_Behaviour;

struct TokenHandler_Behaviour;

struct __junktest_6___Behaviour;

struct autoitem_Behaviour;

struct xC2xB5Form_Behaviour;

struct xC2xB5Func_Behaviour;

struct Array_Behaviour;

struct Dictionary_Behaviour;

struct FastStringCpp_Behaviour;

struct File_Behaviour;

struct FastString_Behaviour;

struct MaterialsLol_Behaviour;

struct FastString_Behaviour;

struct Process_Behaviour;

struct RingTree_Behaviour;

struct SCBase_Behaviour;

struct SCDecl_Behaviour;

struct SCIterator_Behaviour;

struct SavingTest_Behaviour;

struct StringShared_Behaviour;

struct String_Behaviour;

struct StringZeroTerminated_Behaviour;

struct xC2xB5Func1_Behaviour;

struct File_Behaviour;

struct File_Behaviour;

struct File_Behaviour;

struct MessageID_Behaviour;

struct Message_Behaviour;

struct SCArg_Behaviour;

struct SCBehaviour_Behaviour;

struct SCClass_Behaviour;

struct SCFile_Behaviour;

struct SCFunction_Behaviour;

struct SCModule_Behaviour;

struct SaverClassInfo_Behaviour;

struct SimpleGraph_Behaviour;

struct SpdProcess_Behaviour;

struct Error_Behaviour;

struct Message_Behaviour;

struct Message_Behaviour;

struct Message_Behaviour;

struct JB_Object;

struct CppRefs;

struct Cpp_Export;

struct DTWrap;

struct JB_ErrorReceiver;

struct FileComparer;

struct FixedDict;

struct FlowControl;

struct Instruction;

struct LeakTester;

struct Macro;

struct MWrap;

struct NilTest;

struct SCImport;

struct SCNodeRenamer;

struct SCObject;

struct SCOperator;

struct SCParamArray;

struct Selector;

struct StringFields;

struct StringReader;

struct SyntaxObj;

struct TerminalCell;

struct __junktest_6__;

struct autoitem;

struct xC2xB5Form;

struct ASMFunc;

struct FastStringCpp;

struct FastString;

struct MaterialsLol;

struct FastString;

struct SCBase;

struct SCDecl;

struct SCIterator;

struct SavingTest;

struct JB_String;

struct ASMFunc2;

struct JB_File;

struct JB_File;

struct JB_File;

struct Message;

struct MessageID;

struct SCArg;

struct SCBehaviour;

struct SCClass;

struct SCFile;

struct SCFunction;

struct SCModule;

struct SaverClassInfo;

struct SimpleGraph;

struct SpdProcess;

struct JB_Error;

struct Message;

struct Message;

struct Message;

typedef ASM (*ASM_Encoder2)(IR* self);

typedef SCBase* (*CollectFunc)(Message* node, SCBase* name_space, Message* ErrPlace);

typedef SCObject* (*ExprResolver)(Message* Exp, SCBase* name_space, Message* side);

typedef NilState (*NilTrackerFn)(Message* msg, NilCheckMode Test);

typedef Message* (*ParseHandler)(int Start, Message* Parent);

typedef void (*SaverLoadClass)(JB_Class* cls, char* Data);

typedef bool (*ShellOption)(JB_String* Name, JB_String* Value, FastString* purpose);

typedef bool (*SorterComparer)(JB_Object* a, JB_Object* b);

typedef bool (*SorterComparerFn)(SCFunction* a, SCFunction* b);

typedef bool (*SpdMainFn)(_voidptr Obj, _cstring* args, PicoComms* Comms);

typedef JB_Object* (*TokenHandler_fp)(int Start, Message* parent);

typedef void (*TranFunc)(SCFunction* fn, Message* node, SCBase* name_space);

typedef JB_String* (*__Message_CopyID__)(Message* self);

typedef void (*__Saveable_LoadProperties__)(Saveable* self, ObjectLoader* Loader);

typedef JB_String* (*__Object_Render__)(JB_Object* self, FastString* fs_in);

typedef void (*__Saveable_SaveCollect__)(Saveable* self, ObjectSaver* Saver);

typedef void (*__Saveable_SaveWrite__)(Saveable* self, ObjectSaver* Saver);

typedef bool (*__Message_TextSet__)(Message* self, int i, JB_String* v);

typedef JB_String* (*__Message_Text__)(Message* self, int i);

typedef bool (*autosort_fn)(autoitem* a, autoitem* b);

typedef void (*fnErrorLogger)(JB_ErrorReceiver* self, JB_String* Data);

typedef JB_String* (*fnIDGenerator)(int Start, int End, Syntax f);

typedef bool (*fnPreReader)(SCFunction* self, Message* msg);

typedef AsmReg (*fn_OpASM)(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

typedef AsmReg (*fn_asm)(ASMFuncState* self, Message* exp, AsmReg Reg);

typedef void (*fpDestructor)(JB_Object* self);

typedef void (*fpMsgRender)(Message* self, FastString* fs);

typedef void (*fpMsgRenderCpp)(Message* self, FastStringCpp* fs);

//// HEADER Proj.h

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

struct ArchonPurger {
	NilRecord* Neel;
	NilRecord* RowEnd;
	NilRecord Realnesses;
	SCDecl* Decls[32];
	SCDecl* Return;
	bool FnAbleToNilCheck;
	bool RootReturned;
	bool AnyReturns;
	NilRecord Rows[64];
};

struct ArgArrayCounter {
	int i;
	int max;
	bool IsItem;
	bool IsNotItem;
};

struct AsmReg {
	DataTypeCode AType;
	byte Reg;
};

struct CompressionStats {
	Date Duration;
	int In;
	int Out;
	bool Live;
};

struct FakeJBString {
	int Refcount;
	int Length;
	byte* Addr;
};

struct FastBuff {
	byte* Curr;
	byte* Start;
	byte* End;
	JB_String* ReadFrom;
	uint ErrorReported;
};

struct IR {
	byte Op;
	byte Label;
	byte Nothing[2];
	byte r[4];
	int Rest;
	uint Debug;
};

struct IsaTester {
	Message* Items[4];
	int Count;
	bool InUse;
};

struct LoopInfo {
	NilRecord ContRecord;
	NilRecord ExitRecord;
	byte VarCount;
	byte NestDepth;
	bool HasEscape;
};

struct MessagePosition {
	JB_MemoryLayer* Layer;
	int Position;
	uint Length;
	MsgParseFlags Flags;
	u16 Tag;
};

struct NameAndMsg {
	Message* Msg;
	JB_String* Name;
	Message* Arg;
};

struct NilRecorder {
	NilRecord Value;
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

struct Charset_Behaviour: Object_Behaviour {
};

struct CppRefs_Behaviour: Object_Behaviour {
};

JBClass ( CppRefs , JB_Object , 
	u16 DisturbParams;
	bool Owned;
	Array* Disturbs;
);

struct Cpp_Export_Behaviour: Object_Behaviour {
};

JBClass ( Cpp_Export , JB_Object , 
	Array* Outputs_cpp;
	Array* Outputs_h;
	FastStringCpp* T;
	FastStringCpp* AllTypes;
	FastStringCpp* TypesProj;
	FastStringCpp* HeaderProj;
	FastStringCpp* Inlines;
	FastStringCpp* ModuleProperties;
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

struct ErrorReceiver_Behaviour: Object_Behaviour {
};

JBClass ( JB_ErrorReceiver , JB_Object , 
	JB_Error* Errors;
	fnErrorLogger _LogFunc;
	JB_Object* _LogObj;
	int MaxErrors;
	int MaxProblems;
	int ErrorCount;
	int ProblemCount;
	int WarnCount;
	int LowerErrorsTo;
	bool BlockErrors;
	JB_String* Source;
);

struct FastString_Behaviour: Object_Behaviour {
};

struct FlowControl_Behaviour: Object_Behaviour {
};

JBClass ( FlowControl , JB_Object , 
	FastBuff Buff;
	StringReader* ReadInput;
	FastString* Write;
	FastString* Excuse;
);

struct Instruction_Behaviour: Object_Behaviour {
};

JBClass ( Instruction , JB_Object , 
	byte aType;
	byte PCount;
	byte OpCode;
	xC2xB5Form* Sizes;
	JB_String* FormName;
	JB_String* Name;
);

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
	Message* _Parsed;
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

struct NilTest_Behaviour: Object_Behaviour {
};

JBClass ( NilTest , JB_Object , 
	int V;
	JB_String* V2;
	byte* V3;
	byte* V4;
);

struct ProcessOwner_Behaviour: Object_Behaviour {
};

struct SCImport_Behaviour: Object_Behaviour {
};

JBClass ( SCImport , JB_Object , 
	bool IsSTDLib;
	ErrorSeverity BlindCast;
	int Depth;
	Array* Files;
	JB_MemoryLayer* DeclLayer;
	SCModule* Mod;
	Dictionary* Resources;
);

struct SCNodeRenamer_Behaviour: Object_Behaviour {
};

JBClass ( SCNodeRenamer , JB_Object , 
	JB_String* Name;
	Array* Nodes;
);

struct SCObject_Behaviour: Object_Behaviour {
};

JBClass ( SCObject , JB_Object , 
	Dictionary* LinkFrom;
	JB_String* Name;
	Message* Source;
	u16 TableId;
	byte NoAutoComplete;
	byte AllocSource;
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
	bool IsNilTest;
	bool IsExactlyEquals;
	bool IsSet;
	bool AsBit;
	bool IsCustom;
	bool DoesntNeedExtraBits;
	bool MakesSigned;
	byte IsAndOr;
);

struct SCParamArray_Behaviour: Object_Behaviour {
};

JBClass ( SCParamArray , JB_Object , 
	Message* Items[11];
	Message* Exp;
	SCClass* Cls;
	s16 Size;
	s16 ErrCount;
	bool IsAssigns;
	bool HasProperParams;
	bool IsDot;
	bool IsAddress;
	bool IsNotModule;
	bool IsSelf;
	bool IsSuper;
	bool Found;
);

struct Saveable_Behaviour: Object_Behaviour {
	__Saveable_LoadProperties__ loadproperties;
	__Saveable_SaveCollect__ savecollect;
	__Saveable_SaveWrite__ savewrite;
};

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

struct StringReader_Behaviour: Object_Behaviour {
};

JBClass ( StringReader , JB_Object , 
	int Length;
	FastBuff Data;
	JB_File* File;
	JB_Object* UserObj;
	int ChunkSize;
	int StartFrom;
	bool _NoMoreChunks;
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
	JB_String* Cpp_Name;
);

struct File_Behaviour: String_Behaviour {
};

struct MaterialsLol_Behaviour: Selector_Behaviour {
};

JBClass ( MaterialsLol , Selector , 
	JB_String* oof;
);

struct Process_Behaviour: ProcessOwner_Behaviour {
};

struct RingTree_Behaviour: Saveable_Behaviour {
};

struct SCBase_Behaviour: SCObject_Behaviour {
};

JBClass ( SCBase , SCObject , 
	SCBaseInfo BaseInfo;
	Dictionary* Access;
	JB_String* ExportName;
	SCBase* Parent;
	SCBase* CurrReacher;
	SCImport* Project;
);

struct SCDecl_Behaviour: SCObject_Behaviour {
};

JBClass ( SCDecl , SCObject , 
	int C_Array;
	SCFunction* HiderFunc;
	JB_Object* IsLookupOnly;
	JB_String* StringData;
	SCDecl* Internal;
	SCDecl* Contains;
	Message* Default;
	SCClass* Type;
	SCDeclInfo Info;
	AsmReg DReg;
	byte PointerCount;
	NilState NilDeclared;
	byte NilReg;
	byte NilAllocDepth;
	byte Special;
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
	SCClass* Parent;
	bool OK;
);

struct SavingTest_Behaviour: Saveable_Behaviour {
};

JBClass ( SavingTest , Saveable , 
	JB_String* Name;
	int Value;
	int ABC[1];
);

struct StringZeroTerminated_Behaviour: String_Behaviour {
};

struct xC2xB5Func1_Behaviour: Memory_Behaviour {
};

JBClass ( ASMFunc2 , MWrap , 
);

struct Message_Behaviour: RingTree_Behaviour {
	__Message_CopyID__ copyid;
	__Message_Text__ text;
	__Message_TextSet__ textset;
};

JBClass ( Message , RingTree , 
	JB_String* Name;
	JB_Object* Obj;
	Syntax Func;
	byte Indent;
	u16 RangeLength;
	MsgParseFlags Flags;
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

struct SCBehaviour_Behaviour: SCBase_Behaviour {
};

JBClass ( SCBehaviour , SCBase , 
	SCModule* FuncTable;
	Dictionary* Interfaces;
	Array* WrapperFuncs;
);

struct SCClass_Behaviour: SCBase_Behaviour {
};

JBClass ( SCClass , SCBase , 
	SCClass* Super;
	Message* Defawlt;
	Message* False;
	SCModule* Modul;
	Array* Properties;
	SCDecl* TypeNormal;
	SCDecl* TypeOptional;
	SCDecl* TypeReal;
	Array* Casts;
	Array* Children;
	SCDecl* Contained;
	SCDecl* Signed;
	SCDecl* _NotConst;
	SCFunction* FuncProto;
	SCFunction* TheIsFunc;
	SCFunction* ConstructorFunc;
	SCFunction* DestructorFunc;
	JB_String* CppClass;
	SCDecl* ClassType;
	SCDecl* SelfDecl;
	Message* IsModel;
	SCBehaviour* Behaviour;
	JB_String* SaveAs;
	SCClass* ProcessAs;
	SCClass* DowngradeTo;
	SCDecl* DataTypeWrapper;
	u16 Size;
	u16 Depth;
	u16 StructContainerDepth;
	DataTypeCode TypeInfo;
	byte MinOpt;
	byte IsBehaviour;
	byte IsWrapper;
	bool IgnoreContainedSelf;
	bool HasCompareFunc;
	bool HasEqualsFunc;
	bool HasSubClass;
	bool NoEarlyFree;
	bool AutoGeneratedSavers;
	bool SavingCanSkip;
	bool TreatAsBaseType;
	bool Banned;
	byte HasNilChecker;
	bool DefaultsToReal;
	bool IsRole;
	bool IsBuiltin;
	SCBaseType BaseType;
	bool IsASM;
	bool IsNotNumeric;
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
	u16 filenum;
	bool IsInternal;
);

struct SCFunction_Behaviour: SCBase_Behaviour {
};

JBClass ( SCFunction , SCBase , 
	Array* Args;
	SCClass* Cls;
	JB_String* Description;
	CppRefs* Refs;
	Dictionary* LinkTo;
	JB_Object* CounterPart;
	SCFunction* NextFunc;
	ASMFunc* ASM;
	SCDecl* ProtoDecl;
	SCClass* ProtoType;
	SCDecl* ReturnType;
	SCFunction* DepthFinder;
	u16 LinkDepth;
	u16 TmpCounter;
	uint AllocCode;
	byte MinOpt;
	byte IsAssigns;
	byte IsCppInBuilt;
	ErrorSeverity BlindCasts;
	bool FlowDisabled;
	bool IsExternalLib;
	bool IsWrapper;
	bool IsNilChecker;
	NilState NilSelf;
	bool IsInline;
	bool IsKiller;
	bool IsDisabled;
	bool IsAPI;
	bool NoRefCounts;
	bool AutoGeneratedSaver;
	bool IsMacro;
	bool HidesProperties;
	byte Badness;
);

struct SCModule_Behaviour: SCBase_Behaviour {
};

JBClass ( SCModule , SCBase , 
	SCClass* Cls;
	Message* InitVarsArg;
	Message* InitCodeArg;
	JB_String* CppPart;
	CppRefs* DefaultRefs;
	Message* InitAfter;
	JB_String* SubsFrom;
	bool Grabbed;
	bool IsImport;
	bool Inited;
	bool IsRequiredInterface;
);

struct SaverClassInfo_Behaviour: Array_Behaviour {
};

JBClass ( SaverClassInfo , Array , 
	JB_Class* Cls;
	SaverClassInfo* NextInfo;
	char* Data;
);

struct SpdProcess_Behaviour: Process_Behaviour {
};

JBClass ( SpdProcess , ShellStream , 
	FastString* Writer;
	PicoComms* Pico;
	JB_StringC* _DebugName;
	SpdMainFn SubProcess;
	int DeathLimit;
	int DiedCount;
	bool WeAreParent;
	bool AlreadyWarnedDied;
	ProcessMode Mode;
);

struct Error_Behaviour: Message_Behaviour {
};

JBClass ( JB_Error , Message , 
	JB_String* Path;
	JB_String* OriginalData;
	JB_String* StackTrace;
	double Progress;
	Message* Node;
	Date When;
	ErrorSeverity Severity;
	ErrorFlags ErrorFlags;
);
extern Message* JB__App__Conf;
extern JB_String* JB__App__Path;
extern Message* JB__App__Prefs;
extern JB_File* JB__App__stdin;
extern JB_File* JB__App__StdOut;
extern Array* JB__App_OldArgs;
extern JB_String* JB__App_Usage;
extern JB_String* SC__AutoComplete_function_names;
extern Dictionary* SC__AutoComplete_Functions;
extern Dictionary* SC__AutoComplete_Owner;
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
extern Message* SC__Comp_ConstantsList;
extern int SC__Comp_CurrStage;
extern Message* SC__Comp_DebugInsert;
extern SCModule* SC__Comp_DisamClasses;
extern SCModule* SC__Comp_DisamModules;
extern Dictionary* SC__Comp_ExportNames;
extern Message* SC__Comp_ExtendList;
extern Array* SC__Comp_ExtendModuleList;
extern Dictionary* SC__Comp_Files;
extern SCFunction* SC__Comp_fnAs;
extern SCFunction* SC__Comp_fnFastAs;
extern SCFunction* SC__Comp_fnFastIsa;
extern SCFunction* SC__Comp_fnIsa;
extern SCFunction* SC__Comp_fnMustbe;
extern SCFunction* SC__Comp_fnOpMustBe;
extern Array* SC__Comp_FuncList;
extern bool SC__Comp_HasMainFunc;
extern Array* SC__Comp_ImportedList;
extern Dictionary* SC__Comp_ImportedNames;
extern bool SC__Comp_InitedOK;
extern Dictionary* SC__Comp_InsecureWords;
extern SCFile* SC__Comp_InternalFile;
extern SCBase* SC__Comp_Interpreter;
#define kSC__Comp_kTimeWidth (19)
extern Date SC__Comp_LastTime;
extern JB_String* SC__Comp_LastTimeName;
extern SCFunction* SC__Comp_MainFunc;
extern Array* SC__Comp_ModuleList;
extern JB_String* SC__Comp_OriginalInputPath;
extern SCFunction* SC__Comp_PrivateProperty;
extern SCModule* SC__Comp_program;
extern JB_String* SC__Comp_ProjectName;
extern Array* SC__Comp_ProtoTypes;
extern SCFunction* SC__Comp_RefClear;
extern SCFunction* SC__Comp_RefDecr;
extern SCFunction* SC__Comp_RefDecrMulti;
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
extern SCImport* SC__Comp_UserProj;
extern SCBase* SC__Comp_VisibleFuncs;
#define kSC__CustomOps_LeftOnlyIsVector (65)
#define kSC__CustomOps_Needed (64)
#define kSC__CustomOps_NotCustom (0)
#define kSC__CustomOps_RightOnlyIsVector (66)
#define kSC__CustomOps_TypeCastFromBool (16)
#define kSC__CustomOps_TypeCastToBigger (32)
#define kJB__ErrorColors_bold (JB_LUB[1878])
extern bool JB__ErrorColors_Enabled;
#define kJB__ErrorColors_error (JB_LUB[1879])
#define kJB__ErrorColors_good (JB_LUB[1880])
#define kJB__ErrorColors_normal (JB_LUB[1881])
#define kJB__ErrorColors_underline (JB_LUB[1880])
#define kJB__ErrorColors_warn (JB_LUB[1882])
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
extern bool SC__AC_Cleaned;
extern JB_ErrorReceiver* SC__AC_Errors;
extern Macro* SC__AC_func_tmp_src;
extern int SC__AC_max_total;
extern JB_String* SC__AC_TestCrash;
extern int SC__AC_total;
extern bool SC__AC_WillExit;
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
extern Dictionary* JB__Constants_UnEscapeStr;
extern Dictionary* JB__Constants_XML_EscapeStr;
extern Dictionary* JB__Constants_XML_UnEscapeStr;
extern CharSet* JB__Constants_XMLWordMiddle;
extern Message* SC__Linkage_Flagz;
extern Message* SC__Linkage_OSXFrameworks;
#define kJB__MZLab_Default (kJB__MZLab_Strong)
#define kJB__MZLab_Fast (2)
#define kJB__MZLab_Fastest (1)
#define kJB__MZLab_None (0)
#define kJB__MZLab_Strong (3)
#define kJB__MZLab_Strongest (4)
extern Macro* SC__Macros_ASM_Datatype;
extern Macro* SC__Macros_ASMCopier;
extern Macro* SC__Macros_ASMCopier2;
extern Macro* SC__Macros_ASMSetter;
extern Macro* SC__Macros_FS;
extern Macro* SC__Macros_InitExpand;
extern Macro* SC__Macros_MainArgArray;
extern Macro* SC__Macros_MainArgBasic;
extern Macro* SC__Macros_MainArgBasicReq;
extern Macro* SC__Macros_MainArgDefault;
extern Macro* SC__Macros_MainArgFinal;
extern Macro* SC__Macros_MultiDecr;
extern Macro* SC__Macros_WhileDecl;
#define kJB__Math_E (2.7182818284590452353602874713526f)
#define kJB__Math_iTau (0.15915494309f)
extern JB_String* SC__Options_Arch;
extern bool SC__Options_ArgStats;
extern Dictionary* SC__Options_BannedClasses;
extern bool SC__Options_CheckMaxVars;
extern bool SC__Options_Compile;
extern MaybeBool SC__Options_Compile32Bit;
extern bool SC__Options_Cpp;
extern bool SC__Options_ExternalCompile;
extern bool SC__Options_Final;
extern bool SC__Options_ForceRecompile;
extern bool SC__Options_GenFlowControlCode;
extern bool SC__Options_HideMultipleErrors;
extern bool SC__Options_IgnoreCantSaveErrors;
extern bool SC__Options_IsDirectTest;
extern bool SC__Options_KeepAllErrors;
#define kSC__Options_LargestFlag (3)
extern bool SC__Options_ListAllLib;
extern bool SC__Options_MakeASM;
extern bool SC__Options_MakeLib;
#define kSC__Options_native (1)
extern ErrorSeverity SC__Options_NilStrength;
extern bool SC__Options_NilTestAllocNeverFails;
extern byte SC__Options_OperationCount;
extern byte SC__Options_Optimise;
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
extern byte SC__Options_SelfReplacement;
extern bool SC__Options_Silent;
extern bool SC__Options_SingleCppOutput;
extern JB_String* SC__Options_SingleFileInput;
extern bool SC__Options_TargetDebug;
extern bool SC__Options_UnusedFunctions;
extern bool SC__Options_UseFuncCallCount;
extern JB_String* SC__Options_Variant;
extern bool SC__Options_Warnings;
#define kJB__Pipe_StdErr_ (2)
#define kJB__Pipe_StdIn_ (0)
#define kJB__Pipe_StdOut_ (1)
extern JB_File* JB__Platform_Logger;
extern Dictionary* SC__SCGame3D_Types;
extern int SC__SC_UniqueNum;
#define kSC__Refs_kbasiscarray (8)
#define kSC__Refs_kbasisdestructable (2)
#define kSC__Refs_kBasisNotObj (0)
#define kSC__Refs_kbasisobj (1)
#define kSC__Refs_kbasistempstruct (4)
#define kSC__Refs_kholdsdisowned (128)
#define kSC__Refs_kisdisowner (64)
#define kSC__Refs_kisnoisy (32)
#define kSC__Refs_kNotDisturbed (0)
#define kSC__Refs_ksufferednoise (16)
#define kSC__Refs_LargestFlag (255)
extern Message* SC__SCStrings_RenderFinish;
extern Message* SC__SCStrings_RenderInsides;
extern Message* SC__SCStrings_RenderNewParams;
extern Dictionary* SC__Errors_IgnoredBranches;
extern Dictionary* SC__SC_Targets_Items;
#define kJB__Terminal_Black (30)
#define kJB__Terminal_blue (34)
#define kJB__Terminal_cyan (36)
extern FastString* JB__Terminal_fs;
#define kJB__Terminal_green (32)
#define kJB__Terminal_h (35)
extern Date JB__Terminal_LastDisplay;
#define kJB__Terminal_magenta (35)
#define kJB__Terminal_red (31)
extern Array* JB__Terminal_Screen;
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
extern Message* SC__VM_Builder_dt_prm;
extern FastString* SC__VM_Builder_form_h;
extern byte SC__VM_Builder_HighPos;
extern Message* SC__VM_Builder_ModuleArg;
extern Array* SC__VM_Builder_NameList;
extern byte SC__VM_Builder_NormalPos;
extern JB_String* SC__VM_Builder_parent;
extern JB_File* SC__VM_Builder_vm_file;
#define kSC____junktest_5___a (0)
#define kSC____junktest_5___b (1)
#define kSC____junktest_5___c (2)
extern int SC____junktest_5___x[3];
extern JB_String* JB___AppConfString;
extern SyntaxObj* JB__FuncArray_[64];
extern JB_String* JB__JbinHeader;
extern JB_String* JB__jBinNotJbin;
extern bool _once1;
extern bool _once2;
extern Dictionary* JB__SyxDict_;
extern CharSet* JB_C_Letters;
extern Dictionary* JB_ClassLinkageTable;
extern Dictionary* JB_ClsCollectTable;
#define kJB_codesign_native (JB_LUB[1883])
extern Dictionary* JB_CppRefTable;
extern CharSet* JB_CSHex;
extern CharSet* JB_CSNum;
extern JB_ErrorReceiver* JB_ErrorDelayer;
extern ExprResolver JB_ExprFuncs[64];
extern SCDecl* JB_FalseBool;
extern fn_asm JB_fn_asm_table[64];
extern FastString* JB_fs_tmp_num;
extern Dictionary* JB_FuncLinkageTable;
extern Dictionary* JB_FuncPreReader;
#define kJB_kActualTypecasts ((~(128 | 32)))
#define kJB_kAddressOfMatch (3 << 22)
#define kJB_kASM (63)
#define kJB_kBitAnd (JB_LUB[354])
#define kJB_kBitNot (JB_LUB[609])
#define kJB_kBitOr (JB_LUB[1328])
#define kJB_kBitXor (JB_LUB[1884])
#define kJB_kCastedMatch (6 << 22)
#define kJB_kDontSaveProperty (0)
#define kJB_kLossyCastedMatch (7 << 22)
extern JB_String* JB_kNameConf;
#define kJB_kNeeds ((16 << 22) | ((32 << 22) | (64 << 22)))
#define kJB_kNeedsAddressOf (32 << 22)
#define kJB_kNeedsAddressOfButAlsoNeedsSuperMatch (64 << 22)
#define kJB_kNeedsTypeCast (16 << 22)
#define kJB_kNoBoolTypeCast (32)
#define kJB_kNoMatch (0)
#define kJB_kNumericMatch (2 << 22)
#define kJB_kSaveProperty (1)
#define kJB_kSavePropertyAndGoIn (2)
#define kJB_kSaverEnd (JB_LUB[0])
#define kJB_kSaverStart1 (JB_LUB[1885])
#define kJB_kSelfDebug (2)
#define kJB_kSelfReplace (1)
#define kJB_kSimpleMatch (1 << 22)
#define kJB_kSuperClassMatch (4 << 22)
#define kJB_kTypeCastAssigns (64)
#define kJB_kTypeCastBothWays (16)
#define kJB_kTypeCastDescribeErrors (256)
#define kJB_kTypeCastFalse (0)
#define kJB_kTypeCastIgnoreAddressOf (8)
#define kJB_kTypeCastIgnoreContained (4)
#define kJB_kTypeCastMost (1)
#define kJB_kTypeCastNumbers (2)
#define kJB_kTypeCastTrue (1 | 2)
#define kJB_kTypeCastWantSuperDistance (128)
#define kJB_kUseDefaultParams (8 << 22)
#define kJB_kVoidPtrMatch (5 << 22)
extern Dictionary* JB_RootCollectTable;
extern JB_ErrorReceiver* JB_StdErr;
extern JB_ErrorReceiver* JB_StdErrOriginal;
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
extern Syntax JB_Syxmax;
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
extern SCClass* JB_TypeStringZero;
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
extern JB_String* JB__Tk_Data;
extern bool JB__Tk_DotInsertAllow;
extern Message* JB__Tk_EndOfLineMarker;
extern Dictionary* JB__Tk_ErrorNames;
#define kJB__Tk_kadjectiveop (1)
#define kJB__Tk_kAllow (false)
#define kJB__Tk_kcolon (2)
#define kJB__Tk_kcolonarg (4)
#define kJB__Tk_kComma (128)
#define kJB__Tk_kEnd ((64 | 128) | 256)
#define kJB__Tk_kEndContainer (256)
#define kJB__Tk_kEndOfLine (64)
#define kJB__Tk_kExpect (true)
#define kJB__Tk_kFuncAfterAny ((512 | 1024) | 2048)
#define kJB__Tk_kFuncAfterBar (2048)
#define kJB__Tk_kFuncAfterNormal (512)
#define kJB__Tk_kFuncAfterNoSpace (1024)
#define kJB__Tk_killegalchar (4194304)
#define kJB__Tk_kLameTemporal (8 | (16 | 32))
#define kJB__Tk_kOpp (((((4096 | 8192) | 16384) | 32768) | 65536) | 131072)
#define kJB__Tk_kOppBar (16384)
#define kJB__Tk_kOppBra (4096)
#define kJB__Tk_kOppChain (65536 | (4096 | (8192 | 16384)))
#define kJB__Tk_kOppNoBar ((((((4096 | 8192) | 16384) | 32768) | 65536) | 131072) & (~16384))
#define kJB__Tk_kOppSNB (8192)
#define kJB__Tk_kOppSyx (8192 | 16384)
#define kJB__Tk_kOppTemporal (32768)
#define kJB__Tk_kOppWord (65536)
#define kJB__Tk_kOppYoda (131072)
#define kJB__Tk_kTemporal ((8 | 16) | 32)
#define kJB__Tk_kTemporalBar (32)
#define kJB__Tk_kTemporalSyx (16 | 32)
#define kJB__Tk_kTemporalSyxNoBar (16)
#define kJB__Tk_kTemporalWord (8)
#define kJB__Tk_ktemporalwordcolon (262144)
#define kJB__Tk_kThing ((524288 | 1048576) | 2097152)
#define kJB__Tk_kThingBar (1048576)
#define kJB__Tk_kThingSyx (524288)
#define kJB__Tk_kThingWord (2097152)
#define kJB__Tk_kTmpOpp (32768 | 16)
#define kJB__Tk_LargestFlag (8388607)
extern fnIDGenerator JB__Tk_Splitter;
extern u16 JB__Tk_StopBars;
extern MessagePosition JB__Tk_Using;
extern JB_String* JB__zalgo_down;
extern JB_String* JB__zalgo_mid;
extern Random JB__zalgo_R;
extern JB_String* JB__zalgo_up;
#define kJB__byte_max (255)
#define kJB__byte_min (0)
#define kJB__char_max (127)
#define kJB__char_min (-128)
#define kJB__int16_max (32767)
#define kJB__int16_min (-32768)
#define kJB__int64_max (9223372036854775807)
#define kJB__int64_min (9223372036854775807 + 1)
#define kJB__uint_max (4294967295)
#define kJB__uint_min (0)
#define kJB__uint16_max (65535)
#define kJB__uint16_min (0)
#define kJB__uint64_max (-1)
#define kSC__ASMtmp_kcontinue (4)
#define kSC__ASMtmp_kdebugger (12)
#define kSC__ASMtmp_kElseIf (1)
#define kSC__ASMtmp_kexit (5)
#define kSC__ASMtmp_kfail (13)
#define kSC__ASMtmp_kif (2)
#define kSC__ASMtmp_krejoin (7)
#define kSC__ASMtmp_kreturn (6)
#define kSC__ASMtmp_ksetvar (11)
#define kSC__ASMtmp_kstatementexpression (10)
#define kSC__ASMtmp_kswap (8)
#define kSC__ASMtmp_ktern (9)
#define kSC__ASMtmp_kwhile (3)
#define kJB__CharProp_almostletter (6)
#define kJB__CharProp_letters (7)
#define kJB__CharProp_lower (9)
#define kJB__CharProp_nothing (0)
#define kJB__CharProp_number (5)
#define kJB__CharProp_punct (2)
#define kJB__CharProp_unicode (10)
#define kJB__CharProp_upper (8)
#define kJB__CharProp_varnames (4)
#define kJB__CharProp_white (1)
#define kJB__CharProp_xmlpunct (3)
#define kJB__ControlClipMode_debug (4)
#define kJB__ControlClipMode_LargestFlag (7)
#define kJB__ControlClipMode_slidebackinparent (1)
#define kJB__ControlClipMode_slidebackinwindow (2)
#define kJB__CL1_After (6)
#define kJB__CL1_Before (4)
#define kJB__CL1_Centered (7)
#define kJB__CL1_High (2)
#define kJB__CL1_Length (10)
#define kJB__CL1_Low (0)
#define kJB__CL1_Percent (8)
#define kJB__TC__void (0)
#define kJB__TC__voidptr (48)
#define kJB__TC_atomic_byte (0 + (8 + 4))
#define kJB__TC_atomic_int (0 + (32 + (64 + (0 + (8 + 4)))))
#define kJB__TC_atomic_int64 (0 + (48 + (64 + (0 + (8 + 4)))))
#define kJB__TC_atomic_uint (0 + (32 + (0 + (0 + (8 + 4)))))
#define kJB__TC_atomic_uint64 (0 + (48 + (0 + (0 + (8 + 4)))))
#define kJB__TC_bool (0)
#define kJB__TC_byte (0 + 8)
#define kJB__TC_Byte2 (1 + (0 + (0 + (0 + 8))))
#define kJB__TC_Byte3 (2 + (0 + (0 + (0 + 8))))
#define kJB__TC_Byte4 (3 + (0 + (0 + (0 + 8))))
#define kJB__TC_char (0 + (0 + (64 + (0 + 8))))
#define kJB__TC_cstring (48)
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
#define kJB__TC_SByte (0 + (0 + (64 + (0 + 8))))
#define kJB__TC_SByte2 (1 + (0 + (64 + (0 + 8))))
#define kJB__TC_SByte3 (2 + (0 + (64 + (0 + 8))))
#define kJB__TC_SByte4 (3 + (0 + (64 + (0 + 8))))
#define kJB__TC_sign (64)
extern Dictionary* JB__TC_Types_Dict;
#define kJB__TC_u16 (kJB__TC_uint16)
#define kJB__TC_u32 (kJB__TC_UInt)
#define kJB__TC_u64 (kJB__TC_uint64)
#define kJB__TC_UInt (0 + (32 + (0 + (0 + 8))))
#define kJB__TC_uint16 (0 + (16 + (0 + (0 + 8))))
#define kJB__TC_uint64 (0 + (48 + (0 + (0 + 8))))
#define kJB__TC_uint8 (kJB__TC_byte)
#define kJB__TC_UnusedType ((0 + (48 + (64 + (0 + 8)))) & (~8))
#define kJB__TC_Vec2 (1 + (32 + (64 + (128 + 8))))
#define kJB__TC_Vec3 (2 + (32 + (64 + (128 + 8))))
#define kJB__TC_Vec4 (3 + (32 + (64 + (128 + 8))))
#define kJB__Date_kClocksPerSecond (1000000)
#define kJB__Date_kOneSecond (65536)
#define kJB__Date_kOneStep (0.000015258789f)
#define kJB__Date_kSecondsPerDay (86400)
#define kJB__Date_kSecondsPerMonthApprox (2628000)
#define kJB__Date_kSecondsPerWeek (604800)
#define kJB__Date_kTickBits (16)
#define kSC__DeclMode_Always (64)
#define kSC__DeclMode_FuncParam (4)
#define kSC__DeclMode_FunctionBody (8)
#define kSC__DeclMode_Globals (1)
#define kSC__DeclMode_Local (4 + 8)
#define kSC__DeclMode_Properties (3)
#define kSC__DeclMode_Proto (16)
#define kSC__DeclMode_ProtoParam (4 + 16)
#define kSC__DeclMode_TypeCast (32)
#define kSC__DotUseType_LargestFlag (3)
#define kSC__DotUseType_memory (2)
#define kSC__DotUseType_property (1)
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
#define kJB__FileMode_CanExec (1 << ((6 + 1) << ((3 + 1) << 0)))
#define kJB__FileMode_Data (6 << ((6 + 4) << ((2 + 4) << 2)))
#define kJB__FileMode_Group (7 << 3)
#define kJB__FileMode_Other (7 << 0)
#define kJB__FileMode_Owner (7 << 6)
#define kJB__FileMode_Process (((7 << 6) + 5) << ((3 + 5) << 0))
#define kJB__FileResolveMode_AllowMissing (true)
#define kSC__FunctionType_alloc (64)
#define kSC__FunctionType_AllocOrNew (64 + 4)
#define kSC__FunctionType_behaviour (8192)
#define kSC__FunctionType_comparison (8)
#define kSC__FunctionType_ConOrDes (1 + 2)
#define kSC__FunctionType_ConOrNew (1 + 4)
#define kSC__FunctionType_constructor (1)
#define kSC__FunctionType_destructor (2)
#define kSC__FunctionType_emptyconstructor (2048)
#define kSC__FunctionType_expectsrealvars (16384)
#define kSC__FunctionType_initfunc (512)
#define kSC__FunctionType_LargestFlag (32767)
#define kSC__FunctionType_layer (32)
#define kSC__FunctionType_new (4)
#define kSC__FunctionType_newstruct (128)
#define kSC__FunctionType_recursive (1024)
#define kSC__FunctionType_reffer (16)
#define kSC__FunctionType_typetest (256)
#define kSC__FunctionType_virtualcaller (4096)
#define kJB__MsgParseFlags_BreakPoint (32768)
#define kJB__MsgParseFlags_Editable (4096)
#define kJB__MsgParseFlags_Inserted (8192)
#define kJB__MsgParseFlags_LargestFlag (0)
#define kJB__MsgParseFlags_NicelyPositioned (32768)
#define kJB__MsgParseFlags_Style2 (16384)
#define kSC__khalai_Active (2 + 1)
#define kSC__khalai_and (8)
#define kSC__khalai_Basic ((2 + 1) + 4)
#define kSC__khalai_disappears (64)
#define kSC__khalai_LargestFlag (127)
#define kSC__khalai_negative (1)
#define kSC__khalai_Nothing (0)
#define kSC__khalai_positive (2)
#define kSC__khalai_reversed (16)
#define kSC__khalai_soft (4)
#define kSC__khalai_while (32)
#define kSC__khalai_WhileNeg (1 + 32)
#define kSC__khalai_WhilePos (2 + 32)
#define kSC__NilState_ActuallyNil (1 + (4 + 16))
#define kSC__NilState_Basic (kSC__NilState_Realish)
#define kSC__NilState_Borked (128)
#define kSC__NilState_Either (3)
#define kSC__NilState_Failed (0)
#define kSC__NilState_FalseValue (16)
#define kSC__NilState_FnBecomesNilCh (8)
#define kSC__NilState_Killer (255)
#define kSC__NilState_KnownValue (16 + 32)
#define kSC__NilState_Nilish (1)
#define kSC__NilState_Optional (3 + 4)
#define kSC__NilState_Real (2 + 4)
#define kSC__NilState_Realish (2)
#define kSC__NilState_Solved (64)
#define kSC__NilState_Stated (4)
#define kSC__NilState_TrueValue (32)
#define kJB__ProcessMode_AutoPrintErrors (4)
#define kJB__ProcessMode_CaptureAll (1 | 4)
#define kJB__ProcessMode_CaptureErrors (2)
#define kJB__ProcessMode_CaptureOrPrintErrors (2 | 4)
#define kJB__ProcessMode_capturestdout (1)
#define kJB__ProcessMode_LargestFlag (7)
#define kSC__SCBaseInfo_explicitexport (0)
#define kSC__SCBaseInfo_visible (1)
#define kSC__SCBaseType_DataType (2)
#define kSC__SCBaseType_FuncProto (3)
#define kSC__SCBaseType_Module (0)
#define kSC__SCBaseType_Nil (1)
#define kSC__SCBaseType_Object (5)
#define kSC__SCBaseType_Struct (4)
#define kSC__SCBlockage_Bits (480)
#define kSC__SCBlockage_Continue (64)
#define kSC__SCBlockage_Exit (128)
#define kSC__SCBlockage_LargestFlag (0)
#define kSC__SCBlockage_Quit (kSC__SCBlockage_Return)
#define kSC__SCBlockage_Return (192)
#define kSC__SCDeclInfo_altered (524288)
#define kSC__SCDeclInfo_alteredviapointer (262144)
#define kSC__SCDeclInfo_api (512)
#define kSC__SCDeclInfo_atomic (2097152)
#define kSC__SCDeclInfo_body (16384)
#define kSC__SCDeclInfo_borrowed (1)
#define kSC__SCDeclInfo_compilercreated (1024)
#define kSC__SCDeclInfo_const (8)
#define kSC__SCDeclInfo_DataConst (4 + 8)
#define kSC__SCDeclInfo_dataonlyconst (4)
#define kSC__SCDeclInfo_DclCopied (524288 + (2 + (16 + (512 + (32 + 1024)))))
#define kSC__SCDeclInfo_disabled (4096)
#define kSC__SCDeclInfo_gameflyingmem (1048576)
#define kSC__SCDeclInfo_LargestFlag (16777215)
#define kSC__SCDeclInfo_Local (16384 + 8192)
#define kSC__SCDeclInfo_newlycreated (64)
#define kSC__SCDeclInfo_onmodule (65536)
#define kSC__SCDeclInfo_param (8192)
#define kSC__SCDeclInfo_property (32768)
#define kSC__SCDeclInfo_propertywasconstructed (2048)
#define kSC__SCDeclInfo_return (131072)
#define kSC__SCDeclInfo_self (4194304)
#define kSC__SCDeclInfo_SelfImplicit (4194304 + (16384 + 8192))
#define kSC__SCDeclInfo_setto (8388608)
#define kSC__SCDeclInfo_static (16)
#define kSC__SCDeclInfo_stayborrowed (2)
#define kSC__SCDeclInfo_typeimprove (128)
#define kSC__SCDeclInfo_upgradeablecontained (32)
#define kSC__SCDeclInfo_usedbycode (256)
extern int JB__Syx_CurrFuncID;
extern int JB__Syx_MaxFuncID;
#define kSC__TM_BaseShrinkSpeed (0.0005f)
#define kSC__TM_Halfmap (6148914691236517205)
#define kSC__TM_mousebuttondown (1025)
#define kSC__TM_MOUSEMOTION (1024)
#define kSC__nilreason_accessing (0)
#define kSC__nilreason_passing (4)
#define kSC__nilreason_property (1)
#define kSC__nilreason_reading (2)
#define kSC__nilreason_using (3)
extern Array* SC__nilreason_values;
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
extern LoopInfo SC__nil_Loops;
extern NilTrackerFn SC__nil_NilSyxes[64];
extern NilTrackerFn SC__nil_NilTmps[64];
extern byte SC__nil_OldPrint;
extern ArchonPurger SC__nil_T;
extern CompressionStats JB__MzSt_All;
extern int SC__IR_CurrFileNum;
#define kSC__IR_MsgDebugPosShift (19)
extern Array* SC__IR_Resources;
extern IsaTester SC__IsaTester_T;
extern Dictionary* JB__LD_ClassList;
#define kJB__Saver_RefMark (1073741824)
extern SaverClassInfo* JB__Saver_SaveableList;
extern PicoComms* JB__Pico_Parent_;
extern Random JB__Rnd_Shared;
extern Array* SC__Cpp_Cpp_Includes;
extern Array* SC__Cpp_Cpp_Input;
extern JB_String* SC__Cpp_CppLicenceStr;
extern SCClass* SC__Cpp_CurrClass;
extern JB_String* SC__Cpp_FindGlobalsCpp;
extern Array* SC__Cpp_H_Input;
extern Array* SC__Cpp_H_PostInput;
extern JB_String* SC__Cpp_IfName;
#define kSC__Cpp_kNeedsInnerBrackets (1)
#define kSC__Cpp_kNeedsNoBrackets (2)
#define kSC__Cpp_kNeedsOuterBrackets (0)
extern uint64 SC__Cpp_LubHash;
extern FastStringCpp* SC__Cpp_StringBlob;
extern int SC__Cpp_StringCount;
extern Dictionary* SC__Cpp_StringDict;
extern FastStringCpp* SC__Cpp_StringLengths2;
extern JB_String* SC__Cpp_WhileName;
extern bool SC__Cpp_WriteAPI;
extern bool SC__Cpp_WroteAny;
#define kJB__Wrap_kDelete (2)
#define kJB__Wrap_kFree (1)
#define kJB__Wrap_kNothing (0)
extern JB_String* JB__Rec_NonFatal;
extern double JB__Rec_Progress;
#define kJB__fix_TypeDict (3)
#define kJB__fix_TypeObj (1)
#define kJB__fix_TypeStem (2)
#define kJB__fix_TypeValue (0)
extern bool JB__Flow_AlwaysMove;
extern bool JB__Flow_BreakOnFail;
extern uint JB__Flow_Disabled;
extern FlowControl* JB__Flow_Flow;
extern byte JB__Flow_FlowMode;
#define kJB__Flow_Log (1)
#define kJB__Flow_Off (0)
extern CompressionStats JB__Flow_Stats;
#define kJB__Flow_Validate (2)
#define kSC__Instruction_kTypeConst (2)
#define kSC__Instruction_kTypeFunc (1)
extern Dictionary* SC__Instruction_TypeDict;
extern Instruction* SC__Instruction_TypeList[128];
extern Array* SC__Macro_TmpPrms;
extern uint64 JB__Mrap_MDummy[2];
extern NilTest* SC__NilTest_n0;
extern NilTest* SC__NilTest_n1;
extern byte SC__NilTest_NilTestByte;
extern NilTest* SC__NilTest_x1;
extern NilTest* SC__NilTest_x2;
extern JB_String* SC__NilTest_x3;
extern Array* SC__Imp_AllFiles;
extern SCImport* SC__Imp_Curr;
extern byte SC__Imp_CurrIsManuallyImported;
extern Date SC__Imp_Recent;
extern Dictionary* SC__Imp_Shaders;
extern bool SC__Imp_STDLibTime;
#define kSC__Opp_AND (3)
extern int SC__Opp_CustomOperatorScore;
extern Dictionary* SC__Opp_Dict;
#define kSC__Opp_OR (2)
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
extern MaterialsLol* SC__MaterialsLol___First;
extern MaterialsLol* SC__MaterialsLol_Iron;
extern MaterialsLol* SC__MaterialsLol_Pellets;
extern MaterialsLol* SC__MaterialsLol_WierdBlock;
extern MaterialsLol* SC__MaterialsLol_Wood;
extern bool SC__Base_ConstantsLoadingOverride;
extern SCModule* SC__Base_CurrModule;
extern bool SC__Base_CurrVisibility;
#define kSC__Base_kPurposeAddress (0)
#define kSC__Base_kPurposeDot (2)
#define kSC__Base_kPurposeFunc (1)
#define kSC__Base_kPurposeHider (65536)
#define kSC__Base_kPurposeVar (3)
#define kSC__Base_kPurposeVarDecl (4)
extern SCIterator* SC__Iter_carray;
extern SCIterator* SC__Iter_pointer;
#define kSC__Beh_kBehaviourProto (2)
#define kSC__Beh_kBehaviourProtoRequired (6)
#define kSC__Beh_kBehaviourTable (1)
extern Message* SC__Class_ConstrLayerNew2;
extern Message* SC__Class_ConstrNew;
extern SCFunction* SC__Func_CurrFunc;
extern int SC__Func_DisabledPoints;
extern int SC__Func_FuncStats[12];
extern int SC__Func_OnceCount;
extern Dictionary* SC__Func_TemporalStatements;
extern SpdProcess* JB__Proc_Parent;
extern byte JB__Err_AutoPrint;
extern Array* JB__Err_CurrSource;
extern bool JB__Err_KeepStackTrace;

//// HEADER JB.h



// App


// AutoComplete


// CodeSorter


// Comp


// CustomOps


// ErrorColors


// ExecTable


// FastStringOpts


// FB


// InbuiltShellArgs


// AC


// API


// Constants


// Linkage


// MZLab


// Macros


// Math


// NilTest2


// Options


// Pipe


// Platform


// SCGame3D


// SC


// Refs


// SCSelector


// SCStrings


// SCThe


// SC_API


// Errors


// Sav


// SC_Targets


// SC


// Terminal


// TextAssembler


// Ext


// TreeAssembler


// VM_Builder


// __classes__


// __junktest_5__


// __modules__


// asmOps


// depthtest


// image


// main


// Tk


// zalgo


// _void


// _voidptr


// atomic_byte


// atomic_int


// atomic_uint


// bool


// byte


// char


// cstring


// f64


// float


// hfloat


// int


// int16


// int64


// ivec2


// ivec3


// ivec4


// uint


// uint16


// uint64


// vec2


// vec3


// vec4


// ASMtmp


// CharProp


// Codepoint


// ControlClipMode


// ControlLine


// ControlPoint


// ControlRect


// DataTypeCode


// Date


// DeclMode


// DotUseType


// ErrorFlags


// ErrorInt


// ErrorInt2


// ErrorMarker


// ErrorSeverity


// FileMode


// FileResolveMode


// FileSizeInt


// FloatRangeConverter


// FloatRangeConverterBasic


// FlowControlStopper


// FunctionType


// Ind


// IntRange


// JSM


// MaybeBool


// MsgParseFlags


// NilCheckMode


// NilRecord


// NilState


// PID_Int


// ProcessMode


// SCBaseInfo


// SCBaseType


// SCBlockage


// SCDeclInfo


// SizeInt


// Syntax


// TerminalColor


// U24_8


// __junktest_7__


// int8


// mat2


// nilreason


// µParam


// ASM


// ASM_BFLD


// ASM_Bra


// ASM_CNTC


// ASM_CNTR


// ASM_Cmp


// ASM_CmpEq


// ASM_Const


// ASM_Func


// ASM_Mem


// ASM_SWAP


// ASM_Setn


// ASM_U0


// ASM_U1


// ASM_U2


// ASM_U3


// ASM_U4


// ASM_Decoder2


// ASM_Encoder2


// CollectFunc


// ExprResolver


// NilTrackerFn


// ParseHandler


// PicoThreadFn


// SaverLoadClass


// ShellOption


// SorterComparer


// SorterComparer2


// SorterComparerFn


// SorterComparerMsg


// SpdDeathActionFn


// SpdMainFn


// TokenHandler_fp


// TranFunc


// __CopyID__


// __LoadProperties__


// __Render__


// __SaveCollect__


// __SaveWrite__


// __TextSet__


// __Text__


// autosort_fn


// fnErrorLogger


// fnIDGenerator


// fnPreReader


// fn_OpASM


// fn_asm


// fpDestructor


// fpMsgRender


// fpMsgRenderCpp


// JB_ASMFuncState


// JB_ASMVarType


// JB_ArchonPurger


// JB_ArgArrayCounter


// JB_AsmReg


// JB_CharProps


// JB_ClassData


// JB_CompressionStats


// JB_FakeJBString


// JB_FastBuff


// JB_FloatRange


// JB_GameFlyingMem


// JB_IR


// JB_IntDownRange


// JB_IsaTester


// JB_LoopInfo


// JB_Mat4


// JB_MemoryWorld


// JB_MessagePosition


// JB_ModelTest


// JB_NameAndMsg


// JB_NilRecorder


// JB_ObjectLoader


// JB_ObjectSaver


// JB_Object_Behaviour


// JB_ParserLineAndIndent


// JB_Pico


// JB_PicoConfig


// JB_PicoMessage


// JB_Random


// JB_RetroFloat


// JB_SpeedTester


// JB_StringDigitIterator


// JB_StringLengthSplit


// JB_StructSaveTest


// JB_jb_vm


// JB_uint24


// JB_ContainerStruct2


// JB_ContainerStruct


// JB_AppArgument_Behaviour


// JB_ByteMap_Behaviour


// JB_Charset_Behaviour


// JB_CppRefs_Behaviour


// JB_Cpp_Export_Behaviour


// JB_DataTypeWrapper_Behaviour


// JB_DictionaryReader_Behaviour


// JB_ErrorReceiver_Behaviour


// JB_FastString_Behaviour


// JB_FileComparer_Behaviour


// JB_FixedDict_Behaviour


// JB_FlowControl_Behaviour


// JB_Instruction_Behaviour


// JB_LeakTester_Behaviour


// JB_Macro_Behaviour


// JB_MemoryLayer_Behaviour


// JB_Memory_Behaviour


// JB_NilTest_Behaviour


// JB_ProcessOwner_Behaviour


// JB_SCImport_Behaviour


// JB_SCNodeRenamer_Behaviour


// JB_SCObject_Behaviour


// JB_SCOperator_Behaviour


// JB_SCParamArray_Behaviour


// JB_Saveable_Behaviour


// JB_Selector_Behaviour


// JB_StringFields_Behaviour


// JB_StringReader_Behaviour


// JB_String_Behaviour


// JB_SyntaxObj_Behaviour


// JB_TerminalCell_Behaviour


// JB_TokenHandler_Behaviour


// JB___junktest_6___Behaviour


// JB_autoitem_Behaviour


// JB_µForm_Behaviour


// JB_µFunc_Behaviour


// JB_Array_Behaviour


// JB_Dictionary_Behaviour


// JB_FastStringCpp_Behaviour


// JB_File_Behaviour


// JB_JBin_Behaviour


// JB_MaterialsLol_Behaviour


// JB_OutputFile_Behaviour


// JB_Process_Behaviour


// JB_RingTree_Behaviour


// JB_SCBase_Behaviour


// JB_SCDecl_Behaviour


// JB_SCIterator_Behaviour


// JB_SavingTest_Behaviour


// JB_StringShared_Behaviour


// JB_StringThatWasReadSafely_Behaviour


// JB_StringZeroTerminated_Behaviour


// JB_µFunc1_Behaviour


// JB_ExistingFile_Behaviour


// JB_FileData_Behaviour


// JB_JeeboxFile_Behaviour


// JB_MessageID_Behaviour


// JB_Message_Behaviour


// JB_SCArg_Behaviour


// JB_SCBehaviour_Behaviour


// JB_SCClass_Behaviour


// JB_SCFile_Behaviour


// JB_SCFunction_Behaviour


// JB_SCModule_Behaviour


// JB_SaverClassInfo_Behaviour


// JB_SimpleGraph_Behaviour


// JB_SpdProcess_Behaviour


// JB_Error_Behaviour


// JB_FileArchive_Behaviour


// JB_MessageRoot_Behaviour


// JB_config_Behaviour


// JB_Object


// JB_AppArgument


// JB_ByteMap


// JB_Charset


// JB_CppRefs


// JB_Cpp_Export


// JB_DataTypeWrapper


// JB_DictionaryReader


// JB_ErrorReceiver


// JB_FastString


// JB_FileComparer


// JB_FixedDict


// JB_FlowControl


// JB_Instruction


// JB_LeakTester


// JB_Macro


// JB_Memory


// JB_MemoryLayer


// JB_NilTest


// JB_ProcessOwner


// JB_SCImport


// JB_SCNodeRenamer


// JB_SCObject


// JB_SCOperator


// JB_SCParamArray


// JB_Saveable


// JB_Selector


// JB_String


// JB_StringFields


// JB_StringReader


// JB_SyntaxObj


// JB_TerminalCell


// JB_TokenHandler


// JB___junktest_6__


// JB_autoitem


// JB_µForm


// JB_µFunc


// JB_Array


// JB_Dictionary


// JB_FastStringCpp


// JB_File


// JB_JBin


// JB_MaterialsLol


// JB_OutputFile


// JB_Process


// JB_RingTree


// JB_SCBase


// JB_SCDecl


// JB_SCIterator


// JB_SavingTest


// JB_StringShared


// JB_StringThatWasReadSafely


// JB_StringZeroTerminated


// JB_µFunc1


// JB_ExistingFile


// JB_FileData


// JB_JeeboxFile


// JB_Message


// JB_MessageID


// JB_SCArg


// JB_SCBehaviour


// JB_SCClass


// JB_SCFile


// JB_SCFunction


// JB_SCModule


// JB_SaverClassInfo


// JB_SimpleGraph


// JB_SpdProcess


// JB_Error


// JB_FileArchive


// JB_MessageRoot


// JB_config
void ASMPrint(ASM self);

int JB_API__InitCode_();

int JB_API__Init_();

void JB_ASMFunc_Destructor(ASMFunc* self);

int JB_App__InitCode_();

int JB_App__Init_();

Message* JB_App__Prefs();

bool JB_CP_In(Codepoint self, int a, int b);

bool JB_CP_IsWhite(Codepoint self);

void JB_CppRefs_Destructor(CppRefs* self);

void JB_Cpp_Destructor(Cpp_Export* self);

double JB_Date_Seconds(Date self);

int64 JB_Date_WholeSeconds(Date self);

bool JB_Err_HasPosition(JB_Error* self);

bool JB_Err_IsBad(JB_Error* self);

bool JB_Err_IsError(JB_Error* self);

bool JB_Err_IsWarning(JB_Error* self);

bool JB_Err_SyntaxIs(JB_Error* self, ErrorFlags F);

void JB_Err_SyntaxIsSet(JB_Error* self, ErrorFlags F, bool Value);

int JB_Err__InitCode_();

int JB_ErrorColors__InitCode_();

int JB_ErrorColors__Init_();

inline bool JB_ErrorInt_SyntaxCast(ErrorInt self);

inline bool JB_ErrorMarker_SyntaxCast(ErrorMarker self);

bool JB_ErrorSeverity_SyntaxIs(ErrorSeverity self, ErrorSeverity e);

ErrorSeverity JB_ErrorSeverity_SyntaxUsing(ErrorSeverity self);

void JB_ErrorSeverity_SyntaxUsingComplete(ErrorSeverity self);

int JB_ErrorSeverity__InitCode_();

inline void JB_FI_Constructor(StringFields* self, JB_String* Source, byte Sep);

void JB_FI_Destructor(StringFields* self);

inline bool JB_FastBuff_AppendByte(FastBuff* self, byte v);

byte JB_FastBuff_Byte(FastBuff* self);

void JB_FastBuff_Destructor(FastBuff* self);

bool JB_FastBuff_Has(FastBuff* self, int n);

bool JB_FastBuff_HasAny(FastBuff* self);

int JB_FastBuff_Length(FastBuff* self);

int64 JB_FastBuff_Position(FastBuff* self);

int64 JB_FastBuff_Remaining(FastBuff* self);

int JB_FastBuff_Size(FastBuff* self);

bool JB_File_Opened(JB_File* self);

inline bool JB_File_SyntaxCast(JB_File* self);

int JB_File__InitCode_();

int JB_File__Init_();

FlowControlStopper JB_FlowControlStopper_SyntaxUsing(FlowControlStopper self);

int JB_Flow__InitCode_();

void JB_Fn_Destructor(SyntaxObj* self);

void JB_Imp_Destructor(SCImport* self);

inline bool JB_Ind_SyntaxCast(Ind self);

void JB_Instruction_Destructor(Instruction* self);

void JB_LD_Destructor(ObjectLoader* self);

bool JB_LD_HasItem(ObjectLoader* self);

void JB_Lk_Destructor(LeakTester* self);

void JB_Macro_Destructor(Macro* self);

bool JB_MaybeBool_Default(MaybeBool self);

bool JB_MaybeBool_IsFalse(MaybeBool self);

bool JB_MaybeBool_IsKnown(MaybeBool self);

bool JB_MaybeBool_IsTrue(MaybeBool self);

MaybeBool JB_MaybeBool__New(bool Default);

inline void JB_Mrap_ConstructorPtr(MWrap* self, int ItemCount, uint ItemSize, byte* ptr, byte DeathAction);

byte* JB_Mrap_Ptr(MWrap* self);

int JB_Mrap__InitCode_();

int JB_Mrap__Init_();

void JB_MsgPos_SyntaxUsingComplete(MessagePosition* self);

int JB_Msg_After(Message* self);

void JB_Msg_AfterSet(Message* self, int Value);

void JB_Msg_BecomeStr(Message* self, Syntax fn, JB_String* name);

int JB_Msg_CleanIndent(Message* self);

JB_String* JB_Msg_CopyID(Message* self);

void JB_Msg_Dummy(Message* self, FastString* fs);

bool JB_Msg_EqualsSyx(Message* self, Syntax X, bool Aware);

bool JB_Msg_HasPosition(Message* self);

bool JB_Msg_IsContainer(Message* self);

JB_String* JB_Msg_Name(Message* self);

JB_String* JB_Msg_Name_(Message* self);

IntRange JB_Msg_Range(Message* self);

bool JB_Msg_SyntaxIs(Message* self, MsgParseFlags F);

void JB_Msg_SyntaxIsSet(Message* self, MsgParseFlags F, bool Value);

void JB_Msg_max__(Message* self, FastString* fs);

void JB_MzSt_Clear(CompressionStats* self);

int JB_MzSt__InitCode_();

int JB_MzSt__Init_();

inline void JB_NR_Constructor(SCNodeRenamer* self);

void JB_NR_Destructor(SCNodeRenamer* self);

void JB_NameAndMsg_Destructor(NameAndMsg* self);

void JB_NilTest_Destructor(NilTest* self);

void JB_Opp_Destructor(SCOperator* self);

PicoMessage JB_Pico__FromFS(FastString* fs);

int JB_Pico__InitCode_();

int JB_Pico__Init_();

int JB_Platform__InitCode_();

int JB_Platform__Init_();

bool JB_ProcessMode_SyntaxIs(ProcessMode self, ProcessMode M);

void JB_Rec_Destructor(JB_ErrorReceiver* self);

bool JB_Rec_HasAnything(JB_ErrorReceiver* self);

bool JB_Rec_HasProblems(JB_ErrorReceiver* self);

ErrorMarker JB_Rec_Mark(JB_ErrorReceiver* self);

bool JB_Rec_OK(JB_ErrorReceiver* self);

JB_ErrorReceiver* JB_Rec_SyntaxUsing(JB_ErrorReceiver* self);

void JB_Rec_SyntaxUsingComplete(JB_ErrorReceiver* self);

int JB_Rec__InitCode_();

int JB_Rec__Init_();

bool JB_Rg_Contains1(IntRange self, int i);

int JB_Rg_Width(IntRange self);

void JB_Rnd_SeedSet(Random* self, uint64 Value);

int JB_Rnd__Init_();

inline void JB_SCObject_Constructor(SCObject* self);

void JB_SCObject_Destructor(SCObject* self);

void JB_SS_Destructor(StringReader* self);

bool JB_Sav_IsSaveMarked(Saveable* self);

void JB_Sav_LoadProperties(Saveable* self, ObjectLoader* Loader);

void JB_Sav_SaveCollect(Saveable* self, ObjectSaver* Saver);

bool JB_Sav_SaveMark(Saveable* self);

void JB_Sav_SaveUnMark(Saveable* self);

int JB_Saver__InitCode_();

int JB_Saver__Init_();

void JB_SavingTest_Destructor(SavingTest* self);

inline void JB_Sel_Constructor(Selector* self, Selector* Next, Selector** Place, JB_String* name);

void JB_Sel_Destructor(Selector* self);

void JB_Sel_GiveIDs(Selector* self);

_cstring JB_Str_CString(JB_StringC* self);

void JB_StructSaveTest_Destructor(StructSaveTest* self);

bool JB_Syx_IsString(Syntax self);

bool JB_Syx_NoChildren(Syntax self);

SyntaxObj* JB_Syx_Obj(Syntax self);

bool JB_Syx_Translateable(Syntax self);

int JB_Syx__InitCode_();

int JB_Syx__Init_();

int JB_TC_Count(DataTypeCode self);

bool JB_TC_IsFloat(DataTypeCode self);

bool JB_TC_IsSigned(DataTypeCode self);

DataTypeCode JB_TC_SetSigned(DataTypeCode self, bool b);

bool JB_TC_SyntaxIsnt(DataTypeCode self, DataTypeCode M);

int JB_TC__Shift(DataTypeCode self);

int JB_Terminal__InitCode_();

int JB_Tk__InitCode_();

bool JB_Tk__NoFuncAfter(byte b);

Message* JB_Tk__ProcessThingOrTmp(int opps);

inline JB_String* JB_Tk__SyntaxAccess(int s, int e, Syntax f);

Message* JB_Tk__fEndOfLine(int Start, Message* Parent);

Message* JB_Tk__fError(int Start, Message* Parent);

inline void JB_Wrap_Constructor(DTWrap* self, _voidptr p);

inline void JB_Wrap_ConstructorInt(DTWrap* self, int64 v);

int64 JB_Wrap_First(DTWrap* self);

int64 JB_Wrap_Value(DTWrap* self);

inline void JB_autoitem_ConstructorAuto(autoitem* self, JB_String* Sort, JB_String* Insert, SCObject* Value, JB_String* Display, bool Exact, int type);

void JB_autoitem_Destructor(autoitem* self);

int JB_bin_OpenSection(FastString* self);

bool JB_byte_CanPrintAsNormalChar(byte self);

bool JB_byte_In(byte self, uint a, uint b);

bool JB_byte_IsInt(byte self);

bool JB_byte_IsTextLine(byte self);

int64 JB_dbl_AsInt(double self);

float JB_f_Pow(float self, int n);

void JB_flat_Destructor(ASMFuncState* self);

double JB_int64_AsFloat(int64 self);

inline bool JB_int64_OperatorInRange(int64 self, int64 d);

int64 JB_int64_OperatorMax(int64 self, int64 d);

int64 JB_int64_OperatorMin(int64 self, int64 d);

int JB_int_Bits(int self);

int JB_int_OperatorAlign(int self, int To);

inline bool JB_int_OperatorInRange(int self, int d);

bool JB_int_OperatorIsa(int self, uint n);

int JB_int_OperatorMax(int self, int other);

int JB_int_OperatorMin(int self, int other);

int JB_int_OperatorPow(int self, int a);

IntRange JB_int_OperatorTo(int self, int other);

bool JB_int_SyntaxAccess(int self, int bit);

int JB_int_SyntaxAccessSet(int self, int bit, bool Value);

int JB_int__Max();

int JB_int__Min();

bool JB_ivec2_Equals2(ivec2 self, ivec2 v, bool Aware);

void JB_nil_Destructor(ArchonPurger* self);

bool JB_sci_HasData(SaverClassInfo* self);

uint64 JB_uint64_LowestBit(uint64 self);

void JB_xC2xB5Form_Destructor(xC2xB5Form* self);

int JB_zalgo__InitCode_();

int JB_zalgo__Init_();

bool SC_AC__Active();

int SC_AC__InitCode_();

void SC_ASMFunc2_Visible(ASMFunc2* self);

inline void SC_ASMFunc_Constructor(ASMFunc* self, SCFunction* fn);

ASMFunc2* SC_ASMFunc_Finish(ASMFunc* self);

ASM SC_ASM_BFLD_downSet(ASM self, uint Value);

ASM SC_ASM_BFLD_signSet(ASM self, uint Value);

ASM SC_ASM_BFLD_upSet(ASM self, uint Value);

ASM SC_ASM_Bra_c1Set(ASM self, uint Value);

ASM SC_ASM_Bra_jmpSet(ASM self, uint Value);

ASM SC_ASM_CNTC_LSet(ASM self, uint Value);

ASM SC_ASM_CNTC_cnstSet(ASM self, uint Value);

ASM SC_ASM_CNTC_sizeSet(ASM self, uint Value);

ASM SC_ASM_CNTR_LSet(ASM self, uint Value);

ASM SC_ASM_CNTR_incrSet(ASM self, uint Value);

ASM SC_ASM_CNTR_sizeSet(ASM self, uint Value);

ASM SC_ASM_CmpEq_JmpSet(ASM self, uint Value);

ASM SC_ASM_CmpEq_bytesSet(ASM self, uint Value);

ASM SC_ASM_Cmp_CmpSet(ASM self, uint Value);

ASM SC_ASM_Cmp_LSet(ASM self, uint Value);

ASM SC_ASM_Const_LSet(ASM self, uint Value);

ASM SC_ASM_Const_rotSet(ASM self, uint Value);

ASM SC_ASM_Func_JUMPSet(ASM self, uint Value);

ASM SC_ASM_Func_ModeSet(ASM self, uint Value);

ASM SC_ASM_Mem_LSet(ASM self, uint Value);

ASM SC_ASM_Mem_incrSet(ASM self, uint Value);

ASM SC_ASM_R1Set(ASM self, uint Value);

ASM SC_ASM_R2Set(ASM self, uint Value);

ASM SC_ASM_R3Set(ASM self, uint Value);

ASM SC_ASM_R4Set(ASM self, uint Value);

ASM SC_ASM_SWAP_ASet(ASM self, uint Value);

ASM SC_ASM_SWAP_BSet(ASM self, uint Value);

ASM SC_ASM_SWAP_CSet(ASM self, uint Value);

ASM SC_ASM_SWAP_DSet(ASM self, uint Value);

ASM SC_ASM_SWAP_LSet(ASM self, uint Value);

ASM SC_ASM_Setn_CondSet(ASM self, uint Value);

ASM SC_ASM_Setn_DestSet(ASM self, uint Value);

ASM SC_ASM_Setn_LSet(ASM self, uint Value);

ASM SC_ASM_Setn_lenSet(ASM self, uint Value);

ASM SC_ASM_U0_LSet(ASM self, uint Value);

ASM SC_ASM_U1_LSet(ASM self, uint Value);

ASM SC_ASM_U2_LSet(ASM self, uint Value);

ASM SC_ASM_U3_LSet(ASM self, uint Value);

ASM SC_ASM_U4_LSet(ASM self, uint Value);

int SC_ASM__InitCode_();

int SC_ASM__Init_();

bool SC_ASMtmp_SyntaxIs(ASMtmp self, ASMtmp t);

AsmReg SC_ASMtmp__Debugger(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__If(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__Rejoin(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__StateExpr(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__While(ASMFuncState* self, Message* exp, AsmReg Reg);

int SC_AutoComplete__InitCode_();

bool SC_Base_NeedsExport(SCBase* self);

SCBase* SC_Base_ProjectFix(SCBase* self);

JB_String* SC_Base_SubProjName(SCBase* self);

int SC_Base__InitCode_();

int SC_Base__Init_();

SCClass* SC_Beh_Cls(SCBehaviour* self);

void SC_ClassLinkageTable_cpp_class(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_cpp_wrapper(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_ignore(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_noearlyfree(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_visible(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_wrapper(SCFunction* fn, Message* node, SCBase* name_space);

bool SC_Class_EqualsType(SCClass* self, SCBaseType d, bool aware);

SCClass* SC_Class_GoUpTo(SCClass* self, int d);

bool SC_Class_HasGameType(SCClass* self);

bool SC_Class_IsA(SCClass* self, SCClass* S);

bool SC_Class_IsBehaviourTable(SCClass* self);

bool SC_Class_IsDataTypeOnly(SCClass* self);

bool SC_Class_IsDataTypeOrFP(SCClass* self);

bool SC_Class_IsFunc(SCClass* self);

bool SC_Class_IsInterface(SCClass* self);

bool SC_Class_IsStruct(SCClass* self);

SCClass* SC_Class_RealClass(SCClass* self);

int SC_Class__Init_();

void SC_Comp__CreateRoot();

int SC_Comp__InitCode_();

void SC_Comp__PrepareInterpreter();

void SC_Comp__TestDate();

void SC_CppRefTable_disowns(SCFunction* fn, Message* node, SCBase* name_space);

void SC_CppRefTable_disturbs(SCFunction* fn, Message* node, SCBase* name_space);

bool SC_Cpp_CanOpt(Cpp_Export* self, bool force);

void SC_Cpp_SetupFlow(Cpp_Export* self, SCFunction* f);

int SC_Cpp__InitCode_();

bool SC_DeclMode_SyntaxIsnt(DeclMode self, DeclMode o);

void SC_Decl_CArraySizeSet(SCDecl* self, int Value);

void SC_Decl_CopyTypeInfoTo(SCDecl* self, SCDecl* Dcl);

bool SC_Decl_FastMatch(SCDecl* self, SCDecl* O);

bool SC_Decl_IsCArray(SCDecl* self);

bool SC_Decl_IsNil(SCDecl* self);

NilState SC_Decl_IsOptional(SCDecl* self);

NilState SC_Decl_IsReal(SCDecl* self);

JB_String* SC_Decl_IsSaveable(SCDecl* self);

SCDecl* SC_Decl_MakeSignedIfPossible(SCDecl* self);

bool SC_Decl_MatchC(SCDecl* self, SCDecl* O);

SCDecl* SC_Decl_ReallyContains(SCDecl* self);

void SC_Decl_SyntaxAppend(SCDecl* self, SCDeclInfo d);

bool SC_Decl_SyntaxIs(SCDecl* self, SCDeclInfo d);

bool SC_Decl_TypeIsReached(SCDecl* self);

void SC_Decl_TypeReach(SCDecl* self, SCBase* from, Message* src);

SCBase* SC_DontRemove(Message* node, SCBase* name_space, Message* ErrPlace);

bool SC_DotUseType_SyntaxIs(DotUseType self, DotUseType d);

int SC_Errors__InitCode_();

int SC_ExecTable__InitCode_();

int SC_Ext__InitCode_();

JB_String* SC_Ext__LibSuff();

int SC_FB__InitCode_();

int SC_FastStringOpts__InitCode_();

int SC_FastStringOpts__Init_();

void SC_FuncLinkageTable_cpp_wrapper(SCFunction* fn, Message* node, SCBase* name_space);

void SC_FuncLinkageTable_ignore(SCFunction* fn, Message* node, SCBase* name_space);

void SC_FuncLinkageTable_inline(SCFunction* fn, Message* node, SCBase* name_space);

void SC_FuncLinkageTable_visible(SCFunction* fn, Message* node, SCBase* name_space);

bool SC_Func_Borked(SCFunction* self);

bool SC_Func_CanNil(SCFunction* self);

bool SC_Func_HiderMatch(SCFunction* self, bool IsAssigns);

bool SC_Func_IsReal(SCFunction* self);

SCFunction* SC_Func_Last(SCFunction* self);

bool SC_Func_NeedsExport(SCFunction* self);

void SC_Func_SetBlindCasts(SCFunction* self, SCBase* name_space);

bool SC_Func_SyntaxIs(SCFunction* self, FunctionType k);

void SC_Func_SyntaxIsSet(SCFunction* self, FunctionType k, bool Value);

bool SC_Func_SyntaxIsnt(SCFunction* self, FunctionType k);

void SC_Func__Link(SCFunction* fn);

void SC_Func__ObjectifyString(Message* msg);

bool SC_Func_doRefs(SCFunction* self);

ASM SC_IR_Encode(IR* self);

int SC_IR_FilePos(IR* self);

bool SC_IR_OperatorIsa(IR* self, int m);

int SC_IR__InitCode_();

int SC_Imp__InitCode_();

void SC_Instruction_Const(Instruction* self);

bool SC_Instruction_IsSetConst(Instruction* self);

int SC_Instruction__InitCode_();

Instruction* SC_Instruction__SyntaxAccessWithInt(int pos);

int SC_IsaTester__InitCode_();

int SC_IsaTester__Init_();

void SC_IsaTester__SyntaxAppend(Message* o);

int SC_Iter__Init_();

int SC_Linkage__InitCode_();

inline void SC_Macro_ConstructorMsg(Macro* self, Message* s);

inline void SC_Macro_ConstructorStr(Macro* self, JB_String* s);

int SC_Macro__InitCode_();

int SC_Macros__InitCode_();

int SC_MaterialsLol__Init_();

bool SC_Mod_IsProperModule(SCModule* self);

SCModule* SC_Mod_SuperMod(SCModule* self);

SCBlockage SC_Msg_Blocks(Message* self);

void SC_Msg_BlocksSet(Message* self, int Value);

bool SC_Msg_IsAssignable(Message* self);

ASMtmp SC_Msg_TmpType(Message* self);

void SC_Msg_TmpTypeSet(Message* self, ASMtmp Value);

void SC_NRC_SyntaxCallSet(NilRecorder* self, uint64 item, uint64 value);

NilState SC_NRD_SyntaxAccess(NilRecord self, int item);

bool SC_NilState_SyntaxIs(NilState self, NilState type);

NilState SC_NilSyxes_63(Message* msg, NilCheckMode Test);

inline void SC_NilTest_Constructor(NilTest* self);

int SC_NilTest__InitCode_();

NilState SC_NilTmps_63(Message* msg, NilCheckMode Test);

inline void SC_Opp_Constructor(SCOperator* self, fn_OpASM ASM);

void SC_Opp_InitBit(SCOperator* self, JB_String* name_, JB_String* FuncName_);

void SC_Opp_InitNormal(SCOperator* self, JB_String* name_, JB_String* FuncName_);

bool SC_Opp_IsCompSet(SCOperator* self);

int SC_Opp__InitCode_();

int SC_Opp__Init_();

bool SC_Options__Color();

void SC_Options__ColorSet(bool Value);

int SC_Options__InitCode_();

bool SC_PA_IsModule(SCParamArray* self);

int SC_PA_MacroSize(SCParamArray* self);

bool SC_PA_MadeError(SCParamArray* self);

JB_String* SC_PA_RenderKind(SCParamArray* self);

Message* SC_PA_SyntaxAccess(SCParamArray* self, int i);

inline bool SC_PA_SyntaxCast(SCParamArray* self);

inline int SC_Reg_ToInt(AsmReg* self);

bool SC_SCBaseType_HasPtrs(SCBaseType self);

bool SC_SCBlockage_SyntaxIs(SCBlockage self, SCBlockage b);

SCDeclInfo SC_SCDeclInfo_Set(SCDeclInfo self, SCDeclInfo d, bool b);

int SC_SCGame3D__InitCode_();

int SC_SCStrings__InitCode_();

int SC_SCStrings__Init_();

int SC_SC_Targets__InitCode_();

void SC_Sav__BugWorkAround();

int SC_TextAssembler__InitCode_();

int SC_TextAssembler__Init_();

void SC_TextAssembler__TextData(Message* msg);

bool SC_TooManyErrors();

int SC_TreeAssembler__InitCode_();

SCObject* SC_TypeOfNothing(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfSString(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfSthg(Message* Exp, SCBase* name_space, Message* side);

int SC_VM_Builder__InitCode_();

SCClass* SC_VecType(bool isfloat, int count);

int SC__InitCode_();

int SC__Init_();

int SC___junktest_5____InitCode_();

int SC___junktest_5____Init_();

DTWrap* SC___junktest_6____AbcVis();

void SC_flat_CloseVars(ASMFuncState* self, uint64 Old);

IR* SC_flat_Last(ASMFuncState* self);

uint64 SC_flat_OpenVars(ASMFuncState* self);

int SC_flat__InitCode_();

AsmReg SC_fn_asm__Default(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_63(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_ACC(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_AREL(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_BREL(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_DECL(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_LIST(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_NUM(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_TYPE(ASMFuncState* self, Message* exp, AsmReg Reg);

bool SC_int_IsSimpleOrPointerCast(int self);

AsmReg SC_int_Reg(int self);

int SC_int___junktest_8__(int self, int Inaaaadex, bool Create);

ivec4 SC_ivec4___junktest_4__Set(ivec4 self, int Value);

NilCheckMode SC_khalai_Negate(NilCheckMode self);

bool SC_khalai_SyntaxIs(NilCheckMode self, NilCheckMode other);

NilCheckMode SC_khalai_SyntaxIsSet(NilCheckMode self, NilCheckMode other, bool Value);

bool SC_khalai_SyntaxIsnt(NilCheckMode self, NilCheckMode other);

int SC_nil_NestDepth(ArchonPurger* self);

inline void SC_nil_SetAllNil(ArchonPurger* self, NilRecord Dest);

inline NilRecord SC_nil_Value(ArchonPurger* self);

NilState SC_nil__Debugger(Message* msg, NilCheckMode Test);

NilState SC_nil__Dummy(Message* msg, NilCheckMode Test);

NilState SC_nil__Fail(Message* msg, NilCheckMode Test);

NilState SC_nil__Ignore(Message* msg, NilCheckMode Test);

inline NilState SC_nil__Jump(Message* msg, NilCheckMode Test);

NilState SC_nil__RealBool(bool b);

bool SC_nilreason_SyntaxIs(nilreason self, nilreason x);

int SC_nilreason__InitCode_();

bool SC_uint_IsNormalMatch(uint self);

ASMParam SC_xC2xB5Form_AccessInt(xC2xB5Form* self, int i);

void SC_xC2xB5Form_SyntaxAccessSet(xC2xB5Form* self, int i, ASMParam Value);

void SC_xC2xB5Form_SyntaxAppend(xC2xB5Form* self, ASMParam P);

int SC_xC2xB5Form__InitCode_();

uint SC_xC2xB5Param_BitSize(ASMParam self);

bool SC_xC2xB5Param_IsNumber(ASMParam self);

ASMFunc* JB_ASMFunc__Alloc();

ASM JB_ASM_BFLD__Encode(IR* self);

ASM JB_ASM_Bra__Encode(IR* self);

ASM JB_ASM_CNTC__Encode(IR* self);

ASM JB_ASM_CNTR__Encode(IR* self);

ASM JB_ASM_CmpEq__Encode(IR* self);

ASM JB_ASM_Cmp__Encode(IR* self);

ASM JB_ASM_Const__Encode(IR* self);

ASM JB_ASM_Func__Encode(IR* self);

ASM JB_ASM_Mem__Encode(IR* self);

ASM JB_ASM_SWAP__Encode(IR* self);

ASM JB_ASM_Setn__Encode(IR* self);

ASM JB_ASM_U0__Encode(IR* self);

ASM JB_ASM_U1__Encode(IR* self);

ASM JB_ASM_U2__Encode(IR* self);

ASM JB_ASM_U3__Encode(IR* self);

ASM JB_ASM_U4__Encode(IR* self);

ErrorInt JB_App__CWDSet(JB_String* Value);

bool JB_App__IsMainThread();

JB_String* JB_App__StackTrace(int skip, FastString* fs_in);

int64 JB_App__StringMemory();

SCArg* JB_Arg__Alloc();

void JB_Array_Clear(Array* self);

JB_Object* JB_Array_First(Array* self);

JB_Object* JB_Array_Last(Array* self);

JB_Object* JB_Array_Pop(Array* self);

void JB_Array_SyntaxAppend(Array* self, JB_Object* item);

inline bool JB_Array_SyntaxCast(Array* self);

bool JB_Array_SyntaxEquals(Array* self, int n, bool Aware);

Array* JB_Array__Alloc();

void JB_Base_Destructor(SCBase* self);

SCBase* JB_Base__Alloc();

SCBehaviour* JB_Beh__Alloc();

bool JB_CP_IsHigher(Codepoint self);

bool JB_CP_IsLower(Codepoint self);

bool JB_CP_IsUpper(Codepoint self);

bool JB_CS_NextInCharset(CharSet* self, int* p);

CharSet* JB_CS__Alloc();

JB_MemoryLayer* JB_ClassData_CreateUseLayer(JB_Class* self, JB_Object* obj, JB_Object* obj2);

void JB_ClassData_Restore(JB_Class* self);

SCClass* JB_Class__Alloc();

CppRefs* JB_CppRefs__Alloc();

Cpp_Export* JB_Cpp__Alloc();

Date JB_Date_Ago(Date self);

int64 JB_Date_Days(Date self);

JB_String* JB_Date_Render(Date self, FastString* fs_in);

JB_String* JB_Date_RenderDurr(Date self, FastString* fs_in);

Date JB_Date__New0();

void JB_Decl_Destructor(SCDecl* self);

SCDecl* JB_Decl__Alloc();

void JB_Dict_SetInt(Dictionary* self, uint64 Key, JB_Object* Value);

void JB_Dict_ValueLowerSet(Dictionary* self, JB_String* s, JB_Object* Value);

JB_Object* JB_Dict_ValueStr(Dictionary* self, JB_String* Key);

Dictionary* JB_Dict__Alloc();

JB_Object* JB_DictionaryReader_NextValue(DictionaryReader* self);

inline bool JB_DictionaryReader_SyntaxCast(DictionaryReader* self);

inline bool JB_Err2_SyntaxCast(ErrorInt2 self);

bool JB_Err_SyntaxIsnt(JB_Error* self, ErrorFlags F);

JB_Error* JB_Err__Alloc();

JB_String* JB_FI_Field(StringFields* self, Ind Prev, Ind Curr);

StringFields* JB_FI__Alloc();

void JB_FS_AppendEscape(FastString* self, JB_String* s);

void JB_FS_AppendFastString(FastString* self, FastString* fs);

void JB_FS_AppendHexStr(FastString* self, JB_String* Data);

void JB_FS_AppendInt32(FastString* self, int data);

void JB_FS_AppendInt64(FastString* self, int64 data);

void JB_FS_AppendMultiStr(FastString* self, JB_String* data, int count);

void JB_FS_AppendObjectID(FastString* self, Saveable* o);

void JB_FS_FieldStart(FastString* self, JB_String* name);

void JB_FS_MsgErrorName(FastString* self, JB_String* name);

inline JB_String* JB_FS_SyntaxCast(FastString* self);

FastString* JB_FS__Alloc();

void JB_FS_hInt(FastString* self, uint64 n);

void JB_FS_lInt(FastString* self, uint64 n);

byte* JB_FastBuff_Clip(FastBuff* self, int v, int reduce);

uint JB_FastBuff_CopyTo(FastBuff* self, byte* Dest, int Length);

void JB_FastBuff_ReadFromSet(FastBuff* self, JB_String* Value);

JB_String* JB_FastBuff_TmpStr(FastBuff* self);

void JB_FastStringCpp_Destructor(FastStringCpp* self);

FastStringCpp* JB_FastStringCpp__Alloc();

ErrorInt JB_File_FileCompareSub(JB_File* self, JB_File* A);

ErrorInt JB_File_LinkToSet(JB_File* self, JB_String* Value);

bool JB_File_OperatorIsNewerThan(JB_File* self, Date F);

bool JB_File_SmartDataSet(JB_File* self, JB_String* nieu);

void JB_File_SyntaxAppend(JB_File* self, JB_String* data);

JB_File* JB_File__Alloc();

JB_String* JB_File__PreferencesPath();

FlowControl* JB_Flow__Alloc();

int JB_Flow__Init_();

void JB_Flow__Stop();

inline void JB_Fn_Constructor(SyntaxObj* self, fpMsgRender msg, JB_String* name, int ID);

JB_String* JB_Fn_Render(SyntaxObj* self, FastString* fs_in);

SyntaxObj* JB_Fn__Alloc();

SCFunction* JB_Func__Alloc();

SCImport* JB_Imp__Alloc();

Instruction* JB_Instruction__Alloc();

void JB_Iter_Destructor(SCIterator* self);

SCIterator* JB_Iter__Alloc();

bool JB_LD_ItemIsInt(ObjectLoader* self);

void JB_LD_LoadObject(ObjectLoader* self, Message* msg, Dictionary* dict, JB_Class* Cls);

Message* JB_LD_Next(ObjectLoader* self);

inline void JB_Lk_Constructor(LeakTester* self, JB_String* name);

LeakTester* JB_Lk__Alloc();

Macro* JB_Macro__Alloc();

void JB_MaterialsLol_Destructor(MaterialsLol* self);

MaterialsLol* JB_MaterialsLol__Alloc();

SCModule* JB_Mod__Alloc();

void JB_Mrap_Destructor(MWrap* self);

MWrap* JB_Mrap__Alloc();

byte* JB_Mrap__Zalloc(int n);

void JB_MsgPos_Destructor(MessagePosition* self);

Message* JB_Msg_Ancestor(Message* self, Syntax f);

void JB_Msg_Cnj__(Message* self, FastString* fs);

Message* JB_Msg_ConfArg(Message* self);

inline void JB_Msg_ConstructorCopy(Message* self, Message* other);

inline void JB_Msg_ConstructorEmpty(Message* self);

inline void JB_Msg_ConstructorNormal(Message* self, Syntax Func, JB_String* Name);

inline void JB_Msg_ConstructorRange(Message* self, Message* Parent, Syntax Func, int BytePos, JB_String* name, int RangeLength);

void JB_Msg_Destructor(Message* self);

Message* JB_Msg_FindNotInserted(Message* self);

Message* JB_Msg_FindSyx(Message* self, Syntax s);

JB_String* JB_Msg_FirstName(Message* self);

double JB_Msg_Float(Message* self);

bool JB_Msg_InInvisArg(Message* self);

bool JB_Msg_InMsg(Message* self, Message* f);

int JB_Msg_IndentScore(Message* self);

int JB_Msg_Length(Message* self);

void JB_Msg_Nil__(Message* self, FastString* fs);

void JB_Msg_Num__(Message* self, FastString* fs);

bool JB_Msg_OperatorIn(Message* self, Syntax f);

bool JB_Msg_OperatorMatches(Message* self, Message* m);

bool JB_Msg_OperatorStarts(Message* self, JB_String* s);

void JB_Msg_Opp__(Message* self, FastString* fs);

Message* JB_Msg_PoorAnt(Message* self);

void JB_Msg_RangeSet(Message* self, IntRange r);

void JB_Msg_SCnj__(Message* self, FastString* fs);

void JB_Msg_SStr__(Message* self, FastString* fs);

void JB_Msg_SThg__(Message* self, FastString* fs);

bool JB_Msg_ShallowEquals(Message* self, Message* B, bool Aware);

void JB_Msg_Sheb__(Message* self, FastString* fs);

bool JB_Msg_SyntaxEquals(Message* self, JB_String* name, bool Aware);

bool JB_Msg_SyntaxIsnt(Message* self, MsgParseFlags F);

MessagePosition JB_Msg_SyntaxUsing(Message* self);

void JB_Msg_Thg__(Message* self, FastString* fs);

void JB_Msg_WipePositions(Message* self);

void JB_Msg_XCDT__(Message* self, FastString* fs);

void JB_Msg_XCom__(Message* self, FastString* fs);

void JB_Msg_XTxt__(Message* self, FastString* fs);

Message* JB_Msg__Alloc();

Message* JB_Msg__LayerAlloc(JB_MemoryLayer* _L);

void JB_Msg_test_style(Message* self);

void JB_Msg_url__(Message* self, FastString* fs);

SCNodeRenamer* JB_NR__Alloc();

NilTest* JB_NilTest__Alloc();

void JB_Obj_Print(JB_Object* o);

bool JB_Object_FastIsa(JB_Object* self, JB_Class* x);

bool JB_Object_Isa(JB_Object* self, JB_Class* cls);

inline JB_String* JB_Object___Render__(JB_Object* self, FastString* fs_in);

SCOperator* JB_Opp__Alloc();

SCParamArray* JB_PA__Alloc();

bool JB_Pico_SendFS(PicoComms* self, FastString* fs, bool Wait);

bool JB_Pipe__StdOutIsTerminal();

bool JB_Platform__CPU_ARM();

bool JB_Platform__CPU_Intel();

bool JB_Platform__CPU_PPC();

bool JB_Platform__CPU_Spd();

int JB_Platform__PointerBytes();

bool JB_Platform__Release();

void JB_PrintLine(JB_String* data);

bool JB_Proc_CommsOpen(SpdProcess* self);

bool JB_Proc_ParentAlive(SpdProcess* self);

SpdProcess* JB_Proc__Alloc();

bool JB_Rec_CanAddMore(JB_ErrorReceiver* self, ErrorSeverity level);

void JB_Rec_Incr(JB_ErrorReceiver* self, JB_Error* err, bool add);

JB_Error* JB_Rec_LastError(JB_ErrorReceiver* self);

JB_ErrorReceiver* JB_Rec__Alloc();

int64 JB_Rnd_RndInt(Random* self);

void JB_SCFile_Destructor(SCFile* self);

SCFile* JB_SCFile__Alloc();

bool JB_SS_NoMoreChunks(StringReader* self);

int64 JB_SS_Position(StringReader* self);

StringReader* JB_SS__Alloc();

void JB_Sav_SaveWrite(Saveable* self, ObjectSaver* Saver);

SaverClassInfo* JB_Sav_SaverInfo(Saveable* self);

inline void JB_Sav___LoadProperties__(Saveable* self, ObjectLoader* Loader);

inline void JB_Sav___SaveCollect__(Saveable* self, ObjectSaver* Saver);

inline void JB_Sav___SaveWrite__(Saveable* self, ObjectSaver* Saver);

void JB_Saver_AppendString(ObjectSaver* self, JB_String* s);

SavingTest* JB_SavingTest__Alloc();

JB_String* JB_Str_AddExt(JB_String* self, JB_String* ext);

JB_String* JB_Str_Before(JB_String* self, JB_String* s);

inline JB_StringC* JB_Str_CastZero(JB_String* self);

int JB_Str_CompareInt(JB_String* self, int Other, bool Aware);

int JB_Str_CompareStr(JB_String* self, JB_String* Other, bool Aware);

bool JB_Str_ContainsString(JB_String* self, JB_String* s);

int JB_Str_Count(JB_String* self, byte b);

bool JB_Str_EqualsInt(JB_String* self, int Other, bool Aware);

JB_String* JB_Str_Escape(JB_String* self);

JB_String* JB_Str_EscapeChr(JB_String* self);

Ind JB_Str_Find(JB_String* self, CharSet* cs, int Start, int After);

Ind JB_Str_FindByte(JB_String* self, byte find, int Start, int After);

int JB_Str_FindTrailingSlashes(JB_String* self);

Ind JB_Str_InWhite(JB_String* self, int Start, int After);

int64 JB_Str_Int(JB_String* self);

bool JB_Str_IsIntFrom(JB_String* self, int i);

bool JB_Str_IsOK(JB_String* self);

Ind JB_Str_JBFind(JB_String* self, byte find, int Off, int After);

byte JB_Str_Last(JB_String* self, int minus);

JB_String* JB_Str_MulBool(JB_String* self, bool b);

int JB_Str_OperatorMinus(JB_String* self, JB_String* s);

bool JB_Str_OperatorStarts(JB_String* self, JB_String* s);

Ind JB_Str_OutByteWithByteIntInt(JB_String* self, byte find, int Start, int After);

Ind JB_Str_OutCharSet(JB_String* self, CharSet* cs, int Start, int After);

Ind JB_Str_OutWhite(JB_String* self, int Start, int After);

JB_String* JB_Str_PlusByte(JB_String* self, byte B);

JB_String* JB_Str_Preview(JB_String* self, int N);

void JB_Str_PrintColor(JB_String* self, JB_String* color);

ErrorInt2 JB_Str_SilentExecute(JB_String* self, Array* Args, FastString* Out, FastString* Errs);

inline _cstring JB_Str_SyntaxCast(JB_StringC* self);

int JB_Str_TrimLastSub(JB_String* self, byte b);

JB_String* JB_Str_TrimStart(JB_String* self, JB_String* s, bool All);

int JB_Str_UnPrintable(JB_String* self);

JB_String* JB_Str_Unescape(JB_String* self);

JB_String* JB_Str__FromC(_cstring Addr);

JB_String* JB_Str__FromPico(PicoMessage M);

fpMsgRender JB_Syx_ExportAddr(Syntax self);

void JB_Syx_ExportAddrSet(Syntax self, fpMsgRender Value);

bool JB_Syx_ListViewable(Syntax self);

JB_String* JB_Syx_LongName(Syntax self);

JB_String* JB_Syx_Name(Syntax self);

fpMsgRender JB_Syx_RenderAddr(Syntax self);

int JB_TC_ByteSize(DataTypeCode self);

bool JB_TC_ExistsButBadlyNamedOrDesigned(DataTypeCode self);

bool JB_TC_IsInt(DataTypeCode self);

int JB_TC_ItemBitCount(DataTypeCode self);

int JB_TC_NumericCount(DataTypeCode self);

int JB_TC_NumericCountBoolsToo(DataTypeCode self);

bool JB_TC_SameBasicType(DataTypeCode self, DataTypeCode b);

bool JB_Tk__CanStatement();

Message* JB_Tk__GetFuncAfter(Message* result);

int JB_Tk__Init_();

bool JB_Tk__OK();

Message* JB_Tk__OppChain(Message* opp);

void JB_Tk__StopParse();

void JB_Tk__TokensHan(Array* arr, TokHan* H);

Message* JB_Tk__UnTmpPlace(Message* R);

bool JB_Tk__WillEnd();

void JB_Tree_AppendAfter(RingTree* self, RingTree* item, RingTree* after);

void JB_Tree_AppendBefore(RingTree* self, RingTree* item, RingTree* Before);

int JB_Tree_BackDist(RingTree* self, RingTree* B);

int JB_Tree_FwdDist(RingTree* self, RingTree* F);

RingTree* JB_Tree_Get(RingTree* self, int n);

bool JB_Tree_HasOneChild(RingTree* self);

bool JB_Tree_IsFirst(RingTree* self);

bool JB_Tree_IsLast(RingTree* self);

bool JB_Tree_IsOnlyChild(RingTree* self);

bool JB_Tree_OperatorLessOrEqual(RingTree* self, int N);

void JB_Tree_Remove(RingTree* self);

RingTree* JB_Tree_Second(RingTree* self);

void JB_Tree_SyntaxAppend(RingTree* self, RingTree* Last);

bool JB_Tree_SyntaxEquals(RingTree* self, int n, bool Aware);

void JB_Tree_TakeAllFrom(RingTree* self, RingTree* src);

RingTree* JB_Tree_Upward(RingTree* self, int n);

RingTree* JB_Tree__Alloc();

void JB_Wrap_Destructor(DTWrap* self);

double JB_Wrap_FloatValue(DTWrap* self);

DTWrap* JB_Wrap__Alloc();

autoitem* JB_autoitem__Alloc();

inline void JB_bin_Constructor0(FastString* self, int n);

void JB_bin_Sheb(FastString* self, JB_String* data);

void JB_bin_Up(FastString* self, int amount);

JB_String* JB_bool_Render0(bool self);

bool JB_byte_IsHex(byte self);

bool JB_byte_IsWhite(byte self);

JB_String* JB_byte_Render(byte self, FastString* fs_in);

FakeJBString JB_cstring_temp(_cstring self);

JB_String* JB_dbl_Render(double self, int dp, FastString* fs_in);

float JB_f_Fract(float self);

float JB_f_RoundTo(float self, float to);

int64 JB_int64_Abs(int64 self);

JB_String* JB_int64_Hex(int64 self, FastString* fs_in);

int64 JB_int64_OperatorRotl(int64 self, int Amount);

inline void JB_sci_Constructor(SaverClassInfo* self, JB_Class* Cls, char* Data);

void JB_sci_Destructor(SaverClassInfo* self);

SaverClassInfo* JB_sci__Alloc();

inline int JB_uint64_LELength(uint64 self);

xC2xB5Form* JB_xC2xB5Form__Alloc();

int64 SC_ASMFunc2_RunArgs(ASMFunc2* self, int64* Args, int ArgCount);

void SC_ASM__Enc1();

inline void SC_Base_ConstructorStr(SCBase* self, JB_String* Name, bool Dummy);

bool SC_Base_IsSTDLib(SCBase* self);

JB_String* SC_Base_ReachedName(SCBase* self);

bool SC_Base_SyntaxIs(SCBase* self, SCBaseInfo i);

void SC_Base_SyntaxIsSet(SCBase* self, SCBaseInfo i, bool Value);

bool SC_Base_SyntaxIsnt(SCBase* self, SCBaseInfo i);

SCBehaviour* SC_Beh_Upwards(SCBehaviour* self);

JB_String* SC_Class_BehaviourName(SCClass* self);

bool SC_Class_IsObject(SCClass* self);

bool SC_Class_IsSaveableStruct(SCClass* self);

bool SC_Class_NeedsExport(SCClass* self);

int SC_Class_PassableCount(SCClass* self);

SCClass* SC_Class_RealSuper(SCClass* self);

bool SC_Class_Real_Isa(SCClass* self, SCClass* cls);

bool SC_Class_Real_Isa2(SCClass* self, SCClass* cls);

bool SC_Class_RenderSaveableSub(SCClass* self, FastString* fs);

JB_String* SC_Class_StructName(SCClass* self);

void SC_Class_WriteStructOrUnion(SCClass* self, FastStringCpp* fs);

JB_File* SC_Comp__BuildFolder();

int SC_Comp__Reachedfuncs();

bool SC_Comp__ScriptRecompile(JB_File* f, JB_File* script_build);

JB_String* SC_Comp__VariantSuffix();

void SC_Cpp_AppendCppField(Cpp_Export* self, JB_String* prop, FastStringCpp* fs);

bool SC_Cpp_CanExportFunc(Cpp_Export* self, SCFunction* F);

void SC_Cpp_OptEnd(Cpp_Export* self, FastStringCpp* fs, int m, bool force);

void SC_Cpp__C_RenderBak(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderOpp(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderShe(Message* self, FastStringCpp* fs);

void SC_Cpp__CreateClassListHeader(FastString* fs, JB_String* s);

bool SC_Cpp__NeedsDotForC(SCDecl* d);

bool SC_Decl_CanNilCheck(SCDecl* self);

SCDecl* SC_Decl_CanUpgradeInternalPointer(SCDecl* self);

SCDecl* SC_Decl_ClassActReplace(SCDecl* self, SCClass* cls);

inline void SC_Decl_Constructor(SCDecl* self, SCClass* type);

bool SC_Decl_ContainsMatch(SCDecl* self, SCDecl* o, int TypeCast);

bool SC_Decl_HasStruct(SCDecl* self);

SCDecl* SC_Decl_HighestMatch(SCDecl* self, SCDecl* Other, Message* exp);

bool SC_Decl_IsConstOf(SCDecl* self, SCDecl* b);

bool SC_Decl_IsDataTypeOnly(SCDecl* self);

bool SC_Decl_IsFloat(SCDecl* self);

bool SC_Decl_IsNormal(SCDecl* self);

bool SC_Decl_IsNormalBool(SCDecl* self);

bool SC_Decl_IsNormalStruct(SCDecl* self);

bool SC_Decl_IsReg(SCDecl* self);

void SC_Decl_IsTypeImproveSet(SCDecl* self, bool Value);

bool SC_Decl_MatchesDecl(SCDecl* self, SCDecl* O);

bool SC_Decl_NeedsContainedfix(SCDecl* self);

bool SC_Decl_NilStated(SCDecl* self);

bool SC_Decl_PointeryMatch(SCDecl* self, SCDecl* O);

bool SC_Decl_SameForReplace(SCDecl* self, SCDecl* c);

void SC_Decl_SyntaxIsSet(SCDecl* self, SCDeclInfo d, bool Value);

bool SC_Decl_SyntaxIsnt(SCDecl* self, SCDeclInfo d);

void SC_Decl_SyntaxIsntSet(SCDecl* self, SCDeclInfo d, bool Value);

DataTypeCode SC_Decl_TypeInfo(SCDecl* self);

bool SC_Decl_TypeSuffers(SCDecl* self);

JB_String* SC_ExecTable__FuncStr(FastString* fs_in);

bool SC_Ext__AllowedThisFile(JB_String* name);

JB_String* SC_Ext__ProductSuffix();

JB_String* SC_Ext__TmpBase(JB_String* V);

bool SC_FB__Explain(FastString* Purpose, JB_String* name);

void SC_FS_AppendCppAll(FastString* self, JB_String* s);

void SC_FS_AppendWidth(FastString* self, JB_String* s, int Width);

void SC_FS_CArrayAddB(FastString* self, byte B);

void SC_FS_IncludeH(FastString* self, JB_String* name);

inline void SC_FastStringCpp_Constructor(FastStringCpp* self, JB_String* name);

Message* SC_FindBytePosSub(Message* Node);

int SC_Func_ApparantArgCount(SCFunction* self);

bool SC_Func_FoundOneCpp(SCFunction* self, JB_String* n);

bool SC_Func_IsAllocOrNew(SCFunction* self);

bool SC_Func_IsBehaviour(SCFunction* self);

bool SC_Func_IsConstructorOrDestructor(SCFunction* self);

void SC_Func_MarkRecursive(SCFunction* self, SCFunction* EndAt);

SCDecl* SC_Func_Self(SCFunction* self);

Message* SC_Func_SourceArg(SCFunction* self);

bool SC_Func_SyntaxEquals(SCFunction* self, JB_String* name, bool Aware);

SCFunction* SC_Func_TryKeepBetter(SCFunction* self, int OldMatch, SCFunction* f, int Match);

int SC_Func_VisibleArgs(SCFunction* self);

void SC_Func__LinkAll(Array* Funcs);

Ind SC_IR_BytePos(IR* self);

void SC_IR_DebugSet(IR* self, Message* Value);

JB_String* SC_IR_File(IR* self);

JB_String* SC_Imp_Render(SCImport* self, FastString* fs_in);

void SC_Imp_Use(SCImport* self);

JB_String* SC_Instruction_Render(Instruction* self, FastString* fs_in);

inline void SC_MaterialsLol_Constructor(MaterialsLol* self, Selector* Next, Selector** Place, JB_String* name1);

bool SC_Mod_HasActualCode(SCModule* self, Message* arg);

JB_String* SC_Mod_SafeName(SCModule* self);

fn_asm SC_Msg_ASMFunc(Message* self);

void SC_Msg_AppendAllInto(Message* self, Message* Dest);

void SC_Msg_BecomeSyx(Message* self);

Message* SC_Msg_CmdImprove(Message* self);

bool SC_Msg_DoesAnything(Message* self);

Message* SC_Msg_FullAfter(Message* self);

int SC_Msg_FuncPos(Message* self, SCFunction* fn);

void SC_Msg_InsertAfter(Message* self, Message* ins, Message* after);

void SC_Msg_InsertBefore(Message* self, Message* j, Message* ch);

bool SC_Msg_IsStatementExpr(Message* self);

void SC_Msg_Move(Message* self, Message* last, Message* into);

void SC_Msg_MoveAllAfter(Message* self, Message* after);

bool SC_Msg_OperatorIsARel(Message* self, JB_String* name);

bool SC_Msg_OperatorIsBRel(Message* self, JB_String* name);

bool SC_Msg_OperatorIsDot(Message* self, JB_String* name);

bool SC_Msg_OperatorIsOpp(Message* self, JB_String* name);

bool SC_Msg_OperatorIsThing(Message* self, JB_String* name);

bool SC_Msg_OperatorIsTmp(Message* self, JB_String* name);

Message* SC_Msg_ParentPoint(Message* self);

Message* SC_Msg_RemoveTypeCasts(Message* self);

Message* SC_Msg_Resync(Message* self, Message* parent);

void SC_Msg_SlidePositions(Message* self, int add);

void SC_Msg_StatementExprSet(Message* self, SCArg* arg);

Message* SC_Msg_UnBra(Message* self);

Message* SC_Msg_UnBraType(Message* self);

Message* SC_Msg_WrapWith(Message* self, Message* W);

uint SC_NRD_DepthOfVars(NilRecord self);

JB_String* SC_NilState_RawName(NilState self);

bool SC_NilState_SyntaxIsnt(NilState self, NilState type);

inline bool SC_NilTest_SyntaxCast(NilTest* self);

JB_String* SC_Opp_SimpleName(SCOperator* self);

bool SC_Opp_SyntaxEquals(SCOperator* self, JB_String* s, bool aware);

int SC_Options__Init_();

int SC_PA_IgnoreSelfContain(SCParamArray* self);

int SC_SCBlockage_BlockCombine(SCBlockage self, SCBlockage B);

void SC_SCFile_Use(SCFile* self);

JB_String* SC_SCObject_Render(SCObject* self, FastString* fs_in);

JB_String* SC_Str_ArgsMatchError(JB_String* self, bool TypeCast);

JB_String* SC_Str_InterfaceToBehaviour(JB_String* self);

bool SC_Str_IsZero(JB_String* self);

bool SC_Str_Isnull(JB_String* self);

bool SC_Str_OptionBool(JB_String* self);

bool SC_Str_UnderScoreAtAnyEnd(JB_String* self);

bool SC_Str_isCLike(JB_String* self);

void SC_VM_Builder__MakeJump(Message* msg, FastString* jump);

bool SC___junktest_3__(IntRange data);

bool SC_autoitem_OKBy(autoitem* self, autoitem* prev);

void SC_fn_asm__InitTable();

NilCheckMode SC_khalai_Normal(NilCheckMode self);

void SC_nil_BecomeRealSub(ArchonPurger* self, SCDecl* V);

void SC_nil_FinishNil(ArchonPurger* self, SCFunction* f);

NilState SC_nil_Self(ArchonPurger* self);

inline NilState SC_nil_SetNilness(ArchonPurger* self, SCDecl* d, NilState New);

inline void SC_nil__DeclKill();

NilState SC_nil__List(Message* msg, NilCheckMode Test);

NilState SC_nil__Rejoin(Message* msg, NilCheckMode Test);

NilState SC_nil__StatementJump(Message* msg, NilCheckMode Test);

void SC_nil__TrackerDummies();

inline NilRecord SC_nil__Value();

NilState SC_nil__arel(Message* msg, NilCheckMode Test);

ivec2 SC_uint64_LongestBitStretch(uint64 self);

void SC_xC2xB5Form_AddRemainder(xC2xB5Form* self, uint U);

void SC_xC2xB5Form_Finish(xC2xB5Form* self);

bool SC_xC2xB5Param_IsReg(ASMParam self);

void JB_API__NilCallBack(JB_String* ErrorMessage);

void JB_ASMFunc2_Destructor(ASMFunc2* self);

void JB_App__Crash(JB_String* reason);

JB_String* JB_App__OrigPath();

void JB_Arg_Destructor(SCArg* self);

Array* JB_Array__New0();

void JB_Beh_Destructor(SCBehaviour* self);

bool JB_CP_IsLetter(Codepoint self);

bool JB_CS_OperatorContains(CharSet* self, JB_String* Data);

CharSet* JB_CS__New(JB_String* Chars, bool UseRange);

void JB_Class_Destructor(SCClass* self);

void JB_Constants__AddEscape(byte i, FastString* fs);

int JB_Date_DayOfWeek(Date self);

JB_Object* JB_Dict_Syntax(Dictionary* self, JB_String* Key);

JB_Object* JB_Dict_ValueInt(Dictionary* self, uint64 Key);

JB_Object* JB_Dict_ValueLower(Dictionary* self, JB_String* s);

Dictionary* JB_Dict__New();

inline void JB_Err_ConstructorNothing(JB_Error* self);

void JB_Err_Destructor(JB_Error* self);

void JB_Err_Fill(JB_Error* self, JB_String* path, JB_String* desc);

void JB_Err_GrabLine(JB_Error* self, FastString* fs, bool Usecolor);

void JB_Err__SourceAdd(Message* m);

void JB_Err__SourceRemove();

void JB_ErrorColors__DisableIfNoTerminal();

Ind JB_FI_NextSep(StringFields* self, int Prev);

StringFields* JB_FI__New(JB_String* Source, byte Sep);

void JB_FS_AppendInfo(FastString* self, JB_String* name, JB_String* data);

void JB_FS_AppendInfoFloat(FastString* self, JB_String* name, double data);

void JB_FS_AppendInfoNum(FastString* self, JB_String* name, int64 data);

void JB_FS_AppendObjectOrNil(FastString* self, JB_Object* o);

void JB_FS_AppendQuotedEscape(FastString* self, JB_String* s);

void JB_FS_EncodeLength(FastString* self, uint64 N);

void JB_FS_PrintNicely(FastString* self, JB_String* s);

void JB_FS_ProblemsFound(FastString* self, int count);

JB_String* JB_FS_Render(FastString* self, FastString* fs_in);

void JB_FS_SyntaxAppend(FastString* self, Message* msg);

FastString* JB_FS__New();

FastString* JB_FS__NewSize(int size);

JB_String* JB_FastBuff_AccessStr(FastBuff* self, int pos, int after);

bool JB_FastBuff_Alloc(FastBuff* self, int n);

bool JB_File_NewerThanFile(JB_File* self, JB_File* F);

JB_File* JB_File__New(JB_String* path);

void JB_FlowControlStopper_SyntaxUsingComplete(FlowControlStopper self);

SyntaxObj* JB_Fn__New(fpMsgRender msg, JB_String* name, int ID);

void JB_Func_Destructor(SCFunction* self);

JB_Class* JB_LD_GetClassOf(ObjectLoader* self, Message* msg);

int64 JB_LD_Int(ObjectLoader* self);

JB_String* JB_LD_ItemName(ObjectLoader* self);

void JB_LD_LoadForReal(ObjectLoader* self, Message* root, Dictionary* d);

JB_Object* JB_LD_ObjectSub(ObjectLoader* self, Message* c);

JB_String* JB_LD_String(ObjectLoader* self);

LeakTester* JB_Lk__New(JB_String* name);

void JB_Mod_Destructor(SCModule* self);

MWrap* JB_Mrap__NewPtr(int ItemCount, uint ItemSize, byte* ptr, byte DeathAction);

JB_String* JB_Msg_ArgName(Message* self);

JB_String* JB_Msg_ArgValue(Message* self);

void JB_Msg_Bin__(Message* self, FastString* fs);

void JB_Msg_Char__(Message* self, FastString* fs);

bool JB_Msg_DeepEquals(Message* self, Message* B, bool Aware);

void JB_Msg_Export(Message* self, FastString* fs);

JB_String* JB_Msg_FilePath(Message* self);

Message* JB_Msg_FindName(Message* self, JB_String* name);

JB_String* JB_Msg_FuncName(Message* self);

bool JB_Msg_IsType(Message* self, int Allowed);

bool JB_Msg_ListViewable(Message* self);

JB_String* JB_Msg_OriginalParseData(Message* self);

Message* JB_Msg_ReplaceInto(Message* self, Message* w);

void JB_Msg_UnEmbedStr(Message* self);

JB_String* JB_Msg_Value(Message* self);

Message* JB_Msg__NewCopy(Message* other);

Message* JB_Msg__NewEmpty();

Message* JB_Msg__NewNormal(Syntax Func, JB_String* Name);

Message* JB_Msg__NewRange(Message* Parent, Syntax Func, int BytePos, JB_String* name, int RangeLength);

Message* JB_Msg__NewWithLayerCopy(JB_MemoryLayer* _L, Message* other);

Message* JB_Msg__NewWithLayerNormal(JB_MemoryLayer* _L, Syntax Func, JB_String* Name);

Message* JB_Msg__NewWithLayerRange(JB_MemoryLayer* _L, Message* Parent, Syntax Func, int BytePos, JB_String* name, int RangeLength);

float JB_MzSt_Durr(CompressionStats* self);

void JB_MzSt_End(CompressionStats* self);

void JB_MzSt_Start(CompressionStats* self);

SCNodeRenamer* JB_NR__New();

void JB_Obj_PrintLine(JB_Object* o);

void JB_Object_SaveTryCollect(JB_Object* self, ObjectSaver* Saver);

JB_String* JB_Pico_Get(PicoComms* self, float T);

PicoComms* JB_Pico__New(JB_StringC* name, int bits);

JB_String* JB_Platform__CPU_Name();

void JB_PrintStackTrace();

bool JB_Proc_ChildAlive(SpdProcess* self);

void JB_Proc_Destructor(SpdProcess* self);

bool JB_Proc_IsOpen(SpdProcess* self);

void JB_Rec_LogFileWriter(JB_ErrorReceiver* self, JB_String* Data);

RingTree* JB_Ring__New0();

double JB_Rnd_Double(Random* self);

void JB_Rnd_TimeSeed(Random* self);

inline void JB_SS_Constructor(StringReader* self, JB_String* Data);

bool JB_SS_ReadChunk(StringReader* self);

int JB_SS_Remaining(StringReader* self);

inline bool JB_Safe_SyntaxCast(JB_String* self);

void JB_Saver_AppendInt(ObjectSaver* self, int64 i);

void JB_Saver_Finish(ObjectSaver* self, Saveable* first);

JB_String* JB_Str_AfterByte(JB_String* self, byte b, int Last);

JB_String* JB_Str_ArgValue(JB_String* self);

JB_File* JB_Str_AsFile(JB_String* self);

JB_String* JB_Str_BeforeLastByte(JB_String* self, byte b, int fudge);

JB_String* JB_Str_Child(JB_String* self, JB_String* cname);

bool JB_Str_ContainsByte(JB_String* self, byte b);

bool JB_Str_EscapeTest(JB_String* self);

JB_String* JB_Str_Ext(JB_String* self);

Ind JB_Str_FindSlash(JB_String* self, int from);

bool JB_Str_IsInt(JB_String* self);

bool JB_Str_IsJbin(JB_String* self);

int JB_Str_LineCount(JB_String* self);

JB_String* JB_Str_PathDir(JB_String* self);

void JB_Str_PrintlineColor(JB_String* self, JB_String* color);

JB_String* JB_Str_TrimExtAndPath(JB_String* self, bool KeepPath);

JB_String* JB_Str_TrimFirst(JB_String* self, byte b);

JB_String* JB_Str__Hex(int64 i);

bool JB_StringSorter(JB_Object* a, JB_Object* b);

int JB_Tk__FindError(int num);

Message* JB_Tk__FixTRels(Message* self, Message* Last);

int JB_Tk__GotoEndOfLine(int from);

int JB_Tk__NumEnd(JB_String* NumStr, int Start);

void JB_Tk__TokensFn(Array* arr, int bits, ParseHandler func);

void JB_Tree_Clear(RingTree* self);

int JB_Tree_Dist(RingTree* self, RingTree* r);

RingTree* JB_Tree_Pop(RingTree* self);

void JB_Tree_RemoveAfter(RingTree* self);

JB_String* JB_Tree_Render(RingTree* self, FastString* fs_in);

JB_String* JB_Wrap_Render(DTWrap* self, FastString* fs_in);

DTWrap* JB_Wrap__New(_voidptr p);

DTWrap* JB_Wrap__NewInt(int64 v);

autoitem* JB_autoitem__NewAuto(JB_String* Sort, JB_String* Insert, SCObject* Value, JB_String* Display, bool Exact, int type);

void JB_bin_AddMemory(FastString* self, Syntax type, byte* data, bool GoIn, uint64 L);

FastString* JB_bin__New0(int n);

bool JB_byte_IsLower(byte self);

bool JB_byte_IsUpper(byte self);

Message* JB_config_ConfFirst(Message* self);

JB_String* JB_cstring_Str(_cstring self);

JB_String* JB_int64_Render(int64 self, FastString* fs_in);

void JB_int64_RenderSizePart(int64 self, FastString* fs, float Size, JB_String* Suff);

JB_String* JB_int_RenderFS(int self, FastString* fs_in);

void JB_sci_Clear(SaverClassInfo* self);

void JB_sci_Output(SaverClassInfo* self, ObjectSaver* Saver);

SaverClassInfo* JB_sci__New(JB_Class* Cls, char* Data);

bool SC_AC__AutoCompleteSorter(autoitem* a, autoitem* b);

bool SC_AC__CanUseName(SCBase* l);

ASMFunc* SC_ASMFunc__New(SCFunction* fn);

bool SC_ASM__Needed();

void SC_Array_AddCStr(Array* self, JB_String* s);

bool SC_AutoComplete__IsAFuncWithStr(JB_String* s);

void SC_Base_Addtotable(SCBase* self, Array* r);

JB_String* SC_Base_AutoCompleteKind(SCBase* self);

bool SC_Base_IsModuleFunc(SCBase* self);

SCClass* SC_Base_IsNormalObject(SCBase* self);

bool SC_Base_IsVisible(SCBase* self);

void SC_Base_IsVisibleSet(SCBase* self, bool Value);

SCFunction* SC_Base_OwningFunc(SCBase* self);

Message* SC_Base_SourceArg(SCBase* self);

SCBase* SC_Base_UpClass(SCBase* self, Message* f);

void SC_Base_Use(SCBase* self);

SCBase* SC_Base__NewStr(JB_String* Name, bool Dummy);

void SC_Class_AddInterfacesTo(SCClass* self, Array* List);

bool SC_Class_CanHaveEmptyConstructor(SCClass* self);

void SC_Class_GetDepth(SCClass* self);

bool SC_Class_IsMArray(SCClass* self, Message* arr);

bool SC_Class_IsSaveableObject(SCClass* self);

int SC_Class_NumericCount(SCClass* self);

void SC_Class_RenameInterfaces(SCClass* self);

void SC_Class_RenderSaveable(SCClass* self, FastString* fs);

SCBase* SC_Class__StoreExtend(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Class__StoreExtendModule(Message* node, SCBase* name_space, Message* ErrPlace);

bool SC_CodeSorter__LeafFunctionsSorter(SCFunction* a, SCFunction* b);

void SC_Comp__AddSubProjects(Array* Modules);

void SC_Comp__AppendCompilerTime(JB_String* s, int Durr);

void SC_Comp__ClearEnvs();

bool SC_Comp__ModulesSorter(JB_Object* a, JB_Object* b);

void SC_Comp__OrderClassList();

int SC_Comp__ReachedClassCount();

void SC_Comp__SyntaxAppend(Message* m);

void SC_Cpp_ExportOneSyx(Cpp_Export* self, int i, FastStringCpp* fs);

void SC_Cpp__C_RenderChr(Message* self, FastStringCpp* fs);

int SC_Cpp__DontNeedMoreBrackets(Message* msg);

void SC_Cpp__GenLub(FastString* fs);

void SC_Decl_BecomeReal(SCDecl* self);

bool SC_Decl_CanUseDefault(SCDecl* self);

bool SC_Decl_CanWrap(SCDecl* self);

bool SC_Decl_CirSub(SCDecl* self, int64 Value);

bool SC_Decl_CouldUpgradeToReal(SCDecl* self);

SCFunction* SC_Decl_HasStructDestructor(SCDecl* self);

SCDecl* SC_Decl_HighestArrayContainMatch(SCDecl* self, SCDecl* Other, Message* exp);

bool SC_Decl_IsInteger(SCDecl* self);

bool SC_Decl_IsObject(SCDecl* self);

bool SC_Decl_IsReffable(SCDecl* self, bool SetOnly);

bool SC_Decl_IsUintLike(SCDecl* self);

inline bool SC_Decl_IsUnknownParam(SCDecl* self);

bool SC_Decl_IsntReallyCastable(SCDecl* self, Message* side);

bool SC_Decl_MakeStatic(SCDecl* self, Message* wrap, SCBase* Name_Space, DeclMode Purpose);

void SC_Decl_MarkAsRefAltered(SCDecl* self);

NilState SC_Decl_NilCurr(SCDecl* self);

bool SC_Decl_OperatorExact_isa(SCDecl* self, SCClass* v);

bool SC_Decl_OperatorMatches(SCDecl* self, SCClass* O);

uint SC_Decl_PointeryMatchSub(SCDecl* self, SCDecl* O, int TypeCast);

DataTypeCode SC_Decl_RegType(SCDecl* self);

SCDecl* SC_Decl__New(SCClass* type);

SCDecl* SC_DictionaryReader_ValueDecl(DictionaryReader* self);

JB_String* SC_Ext__LibTmpPath();

JB_String* SC_Ext__ProductName();

JB_String* SC_Ext__TmpErr(JB_String* V);

JB_String* SC_Ext__TmpOut(JB_String* V);

bool SC_FB__AppOptions_alive(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_argstats(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_asm(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_check(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_cpp(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_dosign(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_env(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_errortest(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_final(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_force(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_funccount(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_gcc(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_ignorecantsave(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_keepallerrors(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_log(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_m32(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_m64(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_maxvars(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_nocolor(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_nocompile(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_noisy(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_optimise(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_path(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_print(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_quiet(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_silent(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_single(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_stages(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_targetdebug(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_warn(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppTransCompile(JB_String* Name, JB_String* Value, FastString* purpose);

void SC_FS_AppendCpp(FastString* self, JB_String* s);

void SC_FS_CArrayAdd(FastString* self, JB_String* s);

void SC_FS_CArrayAddB0(FastString* self, byte B);

FastStringCpp* SC_FastStringCpp__New(JB_String* name);

SCFunction* SC_FastStringOpts__ByteFunc();

bool SC_Func_CanCompare(SCFunction* self, SCDecl* Against);

bool SC_Func_CanDoRefs(SCFunction* self);

bool SC_Func_CanLibLoad(SCFunction* self);

bool SC_Func_CollectReturnAsReal(SCFunction* self);

bool SC_Func_EqualOrMoreSpecific(SCFunction* self, SCFunction* f);

Message* SC_Func_FindCppWrapperFunc(SCFunction* self, Message* place);

int SC_Func_FindDepths(SCFunction* self);

void SC_Func_Flatten(SCFunction* self);

JB_String* SC_Func_NameOfClassAllocator(SCFunction* self, JB_String* s, JB_String* CppPart);

SCFunction* SC_Func_Paramless(SCFunction* self);

JB_String* SC_Func_ParentName(SCFunction* self);

Message* SC_Func_Prms(SCFunction* self);

void SC_IR_FS(IR* self, FastString* fs);

void SC_Imp__NoProj();

void SC_ListFunctionsSub(JB_Object* o, Array* rz);

LoopInfo SC_LoopInfo_BeginLoop(LoopInfo* self, bool HasExitCond);

void SC_LoopInfo_NextLoop(LoopInfo* self);

Macro* SC_Macro__NewMsg(Message* s);

Macro* SC_Macro__NewStr(JB_String* s);

MaterialsLol* SC_MaterialsLol__New(Selector* Next, Selector** Place, JB_String* name1);

SCBase* SC_Mod__ConstantCollector(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Msg_AddBefore(Message* self, Message* before, Message* NewItem);

bool SC_Msg_AllowedMoveToInit(Message* self);

SCArg* SC_Msg_AsArg(Message* self);

SCDecl* SC_Msg_AsDecl(Message* self);

SCFunction* SC_Msg_AsFunc(Message* self);

Message* SC_Msg_CastedParent(Message* self);

JB_String* SC_Msg_CollectFuncTableName(Message* self);

Message* SC_Msg_CollectionPlace(Message* self);

JB_String* SC_Msg_Cpp_Wrapper(Message* self);

Message* SC_Msg_DclExp(Message* self);

Message* SC_Msg_Deepest(Message* self, Syntax Tmp, JB_String* name);

DotUseType SC_Msg_DotType(Message* self);

SCFunction* SC_Msg_ExpFunc(Message* self);

Message* SC_Msg_FindPosSub(Message* self, int fr, int len, bool Exact);

Message* SC_Msg_FindRef(Message* self, SCFunction* fn, JB_String* name);

void SC_Msg_FuncWrap(Message* self, Message* fnc);

Message* SC_Msg_GetMarker(Message* self, JB_String* s);

Message* SC_Msg_GetTypeLimiter(Message* self);

SCFunction* SC_Msg_IdentifyFunc(Message* self);

bool SC_Msg_IsClassType(Message* self);

bool SC_Msg_IsInt(Message* self);

bool SC_Msg_IsLinkageType(Message* self);

bool SC_Msg_IsModuleType(Message* self);

bool SC_Msg_IsReturnOrRejoin(Message* self);

bool SC_Msg_IsSetRel(Message* self);

bool SC_Msg_IsVarAltered(Message* self, JB_String* name);

bool SC_Msg_IsZero(Message* self);

JB_String* SC_Msg_JDB4_(Message* self, FastString* fs_in);

SCArg* SC_Msg_MsgArg(Message* self);

SCFunction* SC_Msg_MsgOwningFunc(Message* self);

bool SC_Msg_NeedsPreprocess(Message* self);

Message* SC_Msg_ParentForAddress(Message* self);

Message* SC_Msg_ReplaceWith(Message* self, Message* j);

Message* SC_Msg_ReplaceWithChild(Message* self);

SCFile* SC_Msg_SCFile(Message* self);

void SC_Msg_SafeRemove(Message* self, Syntax T);

bool SC_Msg_SettingToNil(Message* self);

Message* SC_Msg_TypeOfArrItem(Message* self);

Message* SC_Msg_UpToType(Message* self);

bool SC_Msg_WithinLoop(Message* self, Message* stop);

void SC_NR_Collect(SCNodeRenamer* self, Message* msg, JB_String* name, Message* after);

void SC_NameAndMsg_SyntaxAppend(NameAndMsg* self, Message* m);

NilTest* SC_NilTest_Exists3(NilTest* self, NilTest* p);

NilTest* SC_NilTest__New();

SCDecl* SC_Object_BaseAsDecl(JB_Object* self);

SCBase* SC_Object_ClassOrModule(JB_Object* self);

JB_String* SC_Opp_CaseAwareStr(SCOperator* self);

void SC_Opp_InitComp(SCOperator* self, JB_String* name_);

SCOperator* SC_Opp__New(fn_OpASM ASM);

bool SC_Refs__ExitHitsOrGoesPast(Message* msg, Message* arg);

bool SC_Refs__RC_NeedsOwnBlock(Message* msg, Message* pp);

int SC_SCObject_AutoCompleteType(SCObject* self);

int SC_SCObject_Auto_Type(SCObject* self);

JB_String* SC_SCObject_BaseIcon(SCObject* self);

SCObject* SC_SCObject_NextDisplay(SCObject* self, bool exact);

void SC_SC_Targets__SyntaxAccessSet(JB_String* name, bool Value);

bool SC_SavingTest__IsEqual(JB_Object* A, JB_Object* B);

uint SC_Str_ASMint(JB_String* self);

ErrorInt2 SC_Str_DebugExecute(JB_String* self, Array* Args, FastString* Out, FastString* Errs);

int SC_Str_OptionInt(JB_String* self);

SCClass* SC_TC_Better_Numeric_Sub(DataTypeCode self, DataTypeCode t);

void SC_TemporalStatements_ignore(SCFunction* fn, Message* node, SCBase* name_space);

void SC_VM_Builder__Clean(Message* msg);

void SC_VM_Builder__DefineGetSub(JB_String* fname, int up, int down, byte c, byte c2);

void SC___junktest_5____Abc(bool g);

AsmReg SC_flat_Reg(ASMFuncState* self, Message* exp, AsmReg reg);

bool SC_funcsorter_fn(JB_Object* a, JB_Object* b);

NilCheckMode SC_khalai_Activate(NilCheckMode self);

NilState SC_nil_BranchExit(ArchonPurger* self, NilRecord A);

NilRecord SC_nil_BranchSwap(ArchonPurger* self, NilRecord A);

void SC_nil_CheckNilCheck(ArchonPurger* self, SCFunction* f);

NilState SC_nil__Bracket(Message* msg, NilCheckMode Test);

NilState SC_nil__Char(Message* msg, NilCheckMode Test);

inline NilRecord SC_nil__EndBlock();

int SC_nil__InitCode_();

NilState SC_nil__Number(Message* msg, NilCheckMode Test);

NilState SC_nil__String(Message* msg, NilCheckMode Test);

ErrorInt Speedie_Main(PicoComms* comms, int Mode, _cstring* args);

void jdb(JB_Object* self);

bool JB_API__NilHandler();

JB_String* JB_AppArgument_Value(JB_Object* self);

ErrorInt2 JB_App__Say(JB_String* s, bool print);

void JB_Array_SaveCollect(Array* self, ObjectSaver* Saver);

void JB_Array_SaveWrite(Array* self, ObjectSaver* Saver);

JB_String* JB_Array_join(Array* self, JB_String* sep);

Array* JB_CS_Bytes(CharSet* self);

void JB_Dict_SaveCollect(Dictionary* self, ObjectSaver* Saver);

void JB_Dict_SaveWrite(Dictionary* self, ObjectSaver* Saver);

void JB_Dict_SetValue(Dictionary* self, JB_String* key, int64 Value);

Dictionary* JB_Dict__Copy(Dictionary* Dict);

Dictionary* JB_Dict__Reverse(Dictionary* Dict);

JB_String* JB_EntityTest();

int JB_Err_LinePos(JB_Error* self, JB_String* data);

JB_String* JB_Err_Render(JB_Error* self, FastString* fs_in);

void JB_Err_UpgradeWithNode(JB_Error* self);

int JB_Err__Init_();

JB_Error* JB_Err__NewNothing();

int JB_ErrorSeverity__Init_();

bool JB_File_DirectoryContains(JB_File* self, JB_String* path);

bool JB_File_OperatorInside(JB_File* self, JB_File* f);

ErrorInt2 JB_File_Touch(JB_File* self);

JB_File* JB_File__Logs();

JB_File* JB_File__PrefsFolder();

JB_Object* JB_LD_ItemObject(ObjectLoader* self);

JB_Object* JB_LD_Object(ObjectLoader* self);

void JB_LD__LoadOne(JB_Class* cls, char* Data);

void JB_Lk_Test2(LeakTester* self);

Array* JB_Mrap__CollectLeaks_(JB_Object* self);

MWrap* JB_Mrap__Object(int Count, int ItemSize);

void JB_Msg_ARel__(Message* self, FastString* fs);

void JB_Msg_Adj__(Message* self, FastString* fs);

void JB_Msg_BRel__(Message* self, FastString* fs);

void JB_Msg_Badj__(Message* self, FastString* fs);

void JB_Msg_BecomeMsg(Message* self, Message* src);

void JB_Msg_BecomeNum(Message* self, int64 num);

void JB_Msg_BinnRender(Message* self, FastString* fs, JB_String* sepa, JB_String* sepb);

void JB_Msg_Bra__(Message* self, FastString* fs);

Message* JB_Msg_Copy(Message* self, Message* pos_msg);

void JB_Msg_Decl__(Message* self, FastString* fs);

void JB_Msg_Dot__(Message* self, FastString* fs);

void JB_Msg_ERel__(Message* self, FastString* fs);

void JB_Msg_FSListArg(Message* self, FastString* fs, bool AddLine);

void JB_Msg_FSListSep(Message* self, FastString* fs, JB_String* sep);

void JB_Msg_File__(Message* self, FastString* fs);

void JB_Msg_Func__(Message* self, FastString* fs);

bool JB_Msg_IsTypeOfDecl(Message* self);

void JB_Msg_Item__(Message* self, FastString* fs);

JB_String* JB_Msg_JDB2_(Message* self, int Flags, FastString* fs_in);

void JB_Msg_List__(Message* self, FastString* fs);

JB_String* JB_Msg_MiniName(Message* self, JB_String* prefix);

Message* JB_Msg_Msg(Message* self, Syntax fn, JB_String* name);

void JB_Msg_Name__(Message* self, FastString* fs);

void JB_Msg_Prm__(Message* self, FastString* fs);

void JB_Msg_Ques__(Message* self, FastString* fs);

void JB_Msg_Quot__(Message* self, FastString* fs);

JB_String* JB_Msg_Render(Message* self, FastString* fs_in);

void JB_Msg_RenderWithSpaces(Message* self, FastString* fs, Message* ch);

void JB_Msg_SDot__(Message* self, FastString* fs);

void JB_Msg_Str__(Message* self, FastString* fs);

Message* JB_Msg_TViewCH(Message* self);

void JB_Msg_Tril__(Message* self, FastString* fs);

void JB_Msg_Type__(Message* self, FastString* fs);

void JB_Msg_XAtt__(Message* self, FastString* fs);

void JB_Msg_XML__(Message* self, FastString* fs);

void JB_Msg_Yoda__(Message* self, FastString* fs);

void JB_Msg_pinn__(Message* self, FastString* fs);

PicoComms* JB_Pico__Parent();

bool JB_Proc_Alive(SpdProcess* self);

void JB_Rec_Clear(JB_ErrorReceiver* self);

JB_Error* JB_Rec_Pop(JB_ErrorReceiver* self);

float JB_Rnd_Float(Random* self);

void JB_Rnd_LoadProperties(Random* self, ObjectLoader* Loader);

void JB_Rnd_SaveWrite(Random* self, ObjectSaver* Saver);

double JB_Rnd_SyntaxAccess(Random* self);

int JB_Rnd__InitCode_();

bool JB_SS_NextChunk(StringReader* self);

StringReader* JB_SS__New(JB_String* Data);

void JB_Saver_AppendObject(ObjectSaver* self, JB_Object* o);

void JB_Saver__LoadOne(JB_Class* cls, char* Data);

JB_String* JB_Str_ArgName(JB_String* self);

Array* JB_Str_ByteSplit(JB_String* self);

CharSet* JB_Str_CharSetWithBool(JB_String* self, bool Range);

JB_File* JB_Str_ChildFile(JB_String* self, JB_String* ch);

ErrorInt JB_Str_CopyFileTo(JB_String* self, JB_String* Dest, bool AttrOnly);

Dictionary* JB_Str_Dict(JB_String* self, byte sep);

Ind JB_Str_ExecuteableJBin(JB_String* self);

bool JB_Str_FileExists(JB_String* self);

int64 JB_Str_FileSize(JB_String* self);

bool JB_Str_IsCompressed(JB_String* self);

bool JB_Str_IsLower(JB_String* self);

bool JB_Str_IsStatementName(JB_String* self);

JB_String* JB_Str_Moat(JB_String* self);

JB_String* JB_Str_Name(JB_String* self);

bool JB_Str_OperatorIsa(JB_String* self, JB_String* s);

JB_String* JB_Str_OperatorMul(JB_String* self, int n);

JB_String* JB_Str_OperatorPlusWithCstring(JB_String* self, _cstring c);

FastString* JB_Str_Out(JB_String* self, bool Clear);

JB_String* JB_Str_ReadFile(JB_String* self, int lim, bool AllowMissing);

Array* JB_Str_Split(JB_String* self, byte sep);

JB_String* JB_Str_Squeeze(JB_String* self);

JB_String* JB_Str_SyntaxAccess(JB_String* self, JB_String* s);

JB_String* JB_Str_TrimSlashes(JB_String* self, bool Pathfix);

JB_String* JB_Str_UpperFirst(JB_String* self);

bool JB_Str_WriteSet(JB_String* self, JB_String* Value);

Message* JB_Syx_Msg(Syntax self, JB_String* name);

Syntax JB_Syx__StdNew(fpMsgRender msg, JB_String* name, JB_String* LongName);

int JB_Terminal__Init_();

int JB_Tk__MessageErrorSub(FastString* fs, int num, int ButFound);

Message* JB_Tk__NewEmpty(Message* P, Syntax F, int Start, int After);

Message* JB_Tk__NewParent(Message* Parent, Syntax Func, int Start, int End);

Message* JB_Tk__NewParentName(Message* Parent, Syntax Func, int Start, JB_String* name);

Message* JB_Tk__NewSkip(Message* P, Syntax F, int Start, int NameStart, int NameEnd);

Message* JB_Tk__fCommentLine(int Start, Message* Parent);

Array* JB_Tree_Flatten(RingTree* self);

void JB_bin_Add(FastString* self, Syntax type, JB_String* data, bool into);

bool JB_byte_IsLetter(byte self);

byte JB_byte_LowerCase(byte self);

byte JB_byte_UpperCase(byte self);

JB_String* JB_int64_StrSize(int64 self, FastString* fs_in);

void SC_ASM__ListInstructions();

JB_String* SC_Arg_Render(SCArg* self, FastString* fs_in);

inline void SC_Base_Constructor0(SCBase* self);

inline void SC_Base_ConstructorMsg(SCBase* self, Message* node);

Message* SC_Base_FuncSrc(SCBase* self);

Array* SC_Base_ListFunctions(SCBase* self);

void SC_Base_StoreLinkToMe(SCBase* self, Dictionary** dp);

SCObject* SC_Base_SyntaxAccess(SCBase* self, JB_String* s);

JB_String* SC_Class_AllocStr(SCClass* self);

JB_String* SC_Class_AllocStrLayer(SCClass* self);

bool SC_Class_CanCompareSub(SCClass* self, JB_String* s, SCDecl* against);

bool SC_Class_HasStuffToHandleInDestructor(SCClass* self);

JB_String* SC_Class_LoadSaverSub(SCClass* self);

SCDecl* SC_Class_MakeClassType(SCClass* self, SCDecl* d);

JB_String* SC_Class_Render(SCClass* self, FastString* fs_in);

bool SC_Comp__Banned(JB_String* name);

void SC_Comp__PrintCompileTime(Date durr);

void SC_Comp__PrintStats();

void SC_Comp__SortModules();

bool SC_Comp__Stage(JB_String* name);

void SC_Comp__TimerSub(JB_String* s, int Durr);

Array* SC_CppRefs_DisturbsGet(CppRefs* self);

void SC_Cpp_OptStart(Cpp_Export* self, FastStringCpp* fs, int m, bool force);

void SC_Cpp_PreRun(Cpp_Export* self);

void SC_Cpp__C_FSListComma(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderAcc(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderArel(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderArg(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderBra(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderItem(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderNum(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderStr(Message* self, FastStringCpp* fs);

void SC_Cpp__GenStrings(FastString* fs);

int SC_Cpp__Init_();

bool SC_Cpp__MsgOKToImprove(Message* msg);

void SC_Cpp__RenderInBracketsIfRel(Message* self, FastStringCpp* fs);

int SC_Cpp__SyntaxAccess(JB_String* name);

SCDecl* SC_Decl_Better_Numeric(SCDecl* self, SCDecl* o);

SCDecl* SC_Decl_CopyDecl(SCDecl* self, bool ForNewVariable);

bool SC_Decl_IsNormalNumber(SCDecl* self);

bool SC_Decl_IsNormalObject(SCDecl* self);

int SC_Decl_IsNumeric(SCDecl* self);

SCDecl* SC_Decl_NewWrapper(SCDecl* self, SCDecl* CastTo);

JB_String* SC_Decl_PrmStateMsg(SCDecl* self, JB_String* Needed, SCFunction* f);

Message* SC_DeclsDefault(Message* def);

bool SC_Errors__AlreadyIgnored(Message* F);

int SC_Errors__Init_();

void SC_ExecTable__AddAll(Array* fl, bool WantLib);

int SC_ExecTable__Init_();

bool SC_Ext__CanCompile(JB_String* name);

void SC_Ext__CollectPico();

int SC_Ext__Init_();

JB_File* SC_Ext__LinkOK(JB_File* p);

JB_String* SC_Ext__MakeDailyProductPath(JB_File* B);

int SC_Ext__NoGoodObject(JB_String* Cpp, JB_File* h, JB_File* o);

JB_String* SC_Ext__ProjTmpPath();

void SC_Ext__SayTest(JB_String* n);

bool SC_FB__AppOptions_breakonerr(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_crash(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_directtest(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_flow(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_variant(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__CompilerInfo();

void SC_FastStringOpts__String(Message* exp, Message* str);

ErrorInt2 SC_File_CodeSign(JB_File* self, JB_String* sign);

Message* SC_FindBytePos(Message* Node);

Message* SC_Func_ConstructorLinePlace(SCFunction* self);

JB_String* SC_Func_Describe(SCFunction* self, FastString* fs_in);

SCFunction* SC_Func_Disambiguate(SCFunction* self, Message* src);

void SC_Func_FLookupSet(SCFunction* self, SCBase* Value);

DataTypeCode SC_Func_RegType(SCFunction* self);

JB_String* SC_Func_RenderName(SCFunction* self, FastString* fs_in);

JB_String* SC_IR_Render(IR* self, FastString* fs_in);

int SC_IR__Init_();

int SC_Imp__Init_();

int SC_Instruction__Init_();

int SC_Linkage__Init_();

JB_String* SC_Linkage__SyntaxAccess(JB_String* name);

Array* SC_ListModules(Dictionary* access);

int SC_Macro__Init_();

void SC_MaterialsLol____LoadSel(MaterialsLol** Place, JB_String* Name);

bool SC_Msg_ACInIsa(Message* self);

JB_String* SC_Msg_APICppProject(Message* self);

int SC_Msg_Autocomplete_State(Message* self);

void SC_Msg_BecomeNil(Message* self);

SCDecl* SC_Msg_BraDeclfind(Message* self);

Message* SC_Msg_CausesUnReachable(Message* self, Message* arg, Message* Dcl, Message* LastPlace);

SCDecl* SC_Msg_FastDecl(Message* self);

JB_String* SC_Msg_FileLocation(Message* self);

Message* SC_Msg_FindDestructor(Message* self);

Message* SC_Msg_FindPos(Message* self, int fr, int len);

Message* SC_Msg_HasOwnBlock(Message* self);

SCFunction* SC_Msg_InsideFunc(Message* self);

bool SC_Msg_IsFirstOfSetRel(Message* self);

int SC_Msg_IsNowNil(Message* self);

bool SC_Msg_IsProperty(Message* self);

bool SC_Msg_IsReffer(Message* self);

bool SC_Msg_IsVarUseableInLoop(Message* self, JB_String* name);

void SC_Msg_LastInBlock(Message* self, SCBlockage Reason);

Array* SC_Msg_ListAll(Message* self);

void SC_Msg_MiniArgCpp(Message* self, FastString* fs);

SCDecl* SC_Msg_MsgDecl(Message* self);

SCFunction* SC_Msg_MsgFunc(Message* self);

int SC_Msg_OpScore(Message* self);

void SC_Msg_SafeReplaceWith(Message* self, Message* Incoming);

int SC_Msg_SelfUsedForProperty(Message* self);

DotUseType SC_Msg_SetType(Message* self);

void SC_Msg_StartUsingAfter(Message* self);

Message* SC_Msg_WipeCopy(Message* self);

NilTest* SC_NilTest_Exists4(NilTest* self);

SCDecl* SC_Object_AsDecl(JB_Object* self);

void SC_Opp__AddBit(JB_String* s, JB_String* FuncName, fn_OpASM ASM);

void SC_Opp__AddComp2(JB_String* s, fn_OpASM ASM);

void SC_Opp__AddCompSub(JB_String* s, fn_OpASM fn);

SCOperator* SC_Opp__AddNormal(JB_String* s, JB_String* FuncName, fn_OpASM ASM);

SCBase* SC_RootCollectTable_crash(Message* node, SCBase* name_space, Message* ErrPlace);

Message* SC_SCFile_Start_AST(SCFile* self);

int SC_SCGame3D__Init_();

Message* SC_SCObject_AnySource(SCObject* self);

int SC_SC_Targets__Init_();

inline void SC_SavingTest_Constructor(SavingTest* self, int n);

void SC_SavingTest_LoadProperties(SavingTest* self, ObjectLoader* Loader);

void SC_SavingTest_SaveWrite(SavingTest* self, ObjectSaver* Saver);

Message* SC_SettingAProperty(Message* Rel);

Macro* SC_Str_Macro(JB_String* self);

void SC_Str_Safe(JB_String* self, FastString* fs);

JB_String* SC_Str_UnicodeSafeName(JB_String* self);

void SC_TemporalStatements_crash(SCFunction* fn, Message* node, SCBase* name_space);

int SC_TreeAssembler__Init_();

JB_String* SC_UniqueTmpVar(SCBase* base, JB_String* name);

int SC_VM_Builder__Init_();

void SC___junktest_1__();

void SC___junktest_2__();

AsmReg SC_flat_RegSaved(ASMFuncState* self, Message* exp);

AsmReg SC_fn_asm_table_ARG(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_BRA(ASMFuncState* self, Message* exp, AsmReg Reg);

NilState SC_nil__Continue(Message* msg, NilCheckMode Test);

NilState SC_nil__Exit(Message* msg, NilCheckMode Test);

NilState SC_nil__Not(Message* msg, NilCheckMode Test);

NilState SC_nil__PropertyToFunc(Message* dot, SCFunction* fn);

NilState SC_nil__SuperSmartMagicCompare(Message* ll, Message* rr, NilCheckMode test, SCOperator* scop);

int SC_nilreason__Init_();

int SC_xC2xB5Form__Init_();

JB_String* jdb4(Message* self);

void ndb5(NilRecord self);

JB_String* JB_AppArgument_Name(JB_Object* self);

JB_String* JB_App__ArgValue(JB_String* name);

JB_String* JB_App__FileName();

void JB_Array_LoadProperties(Array* self, ObjectLoader* Loader);

void JB_Constants__InitConstants();

inline void JB_Err_Constructor(JB_Error* self, Message* node, JB_String* desc, ErrorSeverity level, JB_String* path);

bool JB_Err_LineIdentifiers(JB_Error* self, FastString* fs, JB_String* path);

void JB_FS_RenderSpeed(FastString* self, float seconds, int64 BytesIn, int64 BytesOut, JB_String* Name);

void JB_LD__Init();

void JB_Lk_FinalTest(LeakTester* self);

Message* JB_Msg_AccessAdd(Message* self, JB_String* key);

void JB_Msg_AppendNum(Message* self, int64 Num);

void JB_Msg_AppendSyx(Message* self, Syntax Fn, JB_String* name);

void JB_Msg_Arg__(Message* self, FastString* fs);

void JB_Msg_Arr__(Message* self, FastString* fs);

void JB_Msg_Ask__(Message* self, FastString* fs);

void JB_Msg_Back__(Message* self, FastString* fs);

void JB_Msg_Emb__(Message* self, FastString* fs);

Message* JB_Msg_GiveArg(Message* self);

JB_String* JB_Msg_JDB_(Message* self, FastString* fs_in, int flags);

JB_String* JB_Msg_Locate(Message* self);

void JB_Msg_Msg__(Message* self, FastString* fs);

void JB_Msg_Oat__(Message* self, FastString* fs);

void JB_Msg_Rel__(Message* self, FastString* fs);

void JB_Msg_RenderPrm(Message* self, FastString* fs, byte b1, byte b2);

void JB_Msg_SCom__(Message* self, FastString* fs);

void JB_Msg_SyntaxAppend(Message* self, JB_String* key);

void JB_Msg_TRel__(Message* self, FastString* fs);

JB_String* JB_Msg_Text(Message* self, int i);

bool JB_Msg_TextSet(Message* self, int i, JB_String* v);

void JB_Msg_Tmp__(Message* self, FastString* fs);

void JB_Msg_Todo__(Message* self, FastString* fs);

void JB_Msg_XPI__(Message* self, FastString* fs);

void JB_Msg__TreeComparePrint(Message* orig);

void JB_Msg_binn__(Message* self, FastString* fs);

void JB_Msg_render_jbin_sub(Message* self, FastString* js);

inline void JB_Proc_Constructor(SpdProcess* self, JB_String* path, SpdMainFn fn, JB_StringC* DebugName, Array* params, ProcessMode Mode);

void JB_Proc_Disconnect(SpdProcess* self, JB_StringC* Why);

void JB_Rec_AppendErr(JB_ErrorReceiver* self, JB_Error* Err);

inline void JB_Rec_Constructor(JB_ErrorReceiver* self);

int JB_SS_Byte(StringReader* self);

bool JB_SS_HasAny(StringReader* self);

void JB_Saver__Init();

JB_String* JB_Sh_Render(ShellStream* self, FastString* fs_in);

Array* JB_Str_Components(JB_String* self);

bool JB_Str_EndsWith(JB_String* self, JB_String* s, bool aware);

int JB_Str_IsHexLike(JB_String* self, int N);

Array* JB_Str_OperatorDivide(JB_String* self, byte sep);

JB_String* JB_Str_Parent(JB_String* self);

StringReader* JB_Str_Stream(JB_String* self);

bool JB_Str_SyntaxAppend(JB_String* self, JB_String* s);

JB_String* JB_Str_TitleCase(JB_String* self, FastString* fs_in);

CharSet* JB_Str_UniCS(JB_String* self);

bool JB_Str_Visible(JB_String* self);

Array* JB_Str_Words(JB_String* self);

void JB_StructSaveTest_LoadProperties(StructSaveTest* self, ObjectLoader* Loader);

void JB_StructSaveTest_SaveWrite(StructSaveTest* self, ObjectSaver* Saver);

Message* JB_Syx_IntMsg(Syntax self, int64 name);

Message* JB_Syx_OperatorPlus(Syntax self, JB_String* m);

Message* JB_Syx_PlusNum(Syntax self, int m);

Dictionary* JB_TC__Types();

void JB_Tk__AddXMLText(Message* XML, JB_String* s, int start, int i);

Message* JB_Tk__ChainTemporalRels(Message* FirstThing, Message* opp);

Message* JB_Tk__MakeRel(Message* first, int Bits);

Message* JB_Tk__fAdjectiveOp(int Start, Message* Parent);

Message* JB_Tk__fAfterRel(int Start, Message* Parent);

Message* JB_Tk__fBAdjectiveOp(int Start, Message* Parent);

Message* JB_Tk__fCharSub(int pos, int start, byte find);

Message* JB_Tk__fOppSyx(int Start, Message* Parent);

Message* JB_Tk__fShebang(int Start, Message* Parent);

Message* JB_Tk__fTemporalRelSyx(int Start, Message* Parent);

Message* JB_Tk__fThingSyx(int Start, Message* Parent);

void JB_bin_AddInt(FastString* self, int64 data);

void JB_bin_Enter(FastString* self, Syntax type, JB_String* data);

bool JB_f_SyntaxAccess(float self);

int SC_AC__Init_();

JB_String* SC_ASMFunc_Render(ASMFunc* self, FastString* fs_in);

inline void SC_Arg_Constructor(SCArg* self, Message* node);

int SC_AutoComplete__Init_();

Message* SC_Base_DiissplayObj(SCBase* self, Message* rz);

SCObject* SC_Base_UpCheck(SCBase* self, JB_String* name, bool LookUp);

inline void SC_Beh_Constructor(SCBehaviour* self, SCClass* parent);

SCClass* SC_ClassOfObjForC(Message* curr);

SCFunction* SC_Class_BestBehaviourFor(SCClass* self, JB_String* name);

JB_String* SC_Class_CStructName(SCClass* self);

bool SC_Class_CanCompare(SCClass* self, SCDecl* Against, bool AsEquals);

Message* SC_Class_Falsify(SCClass* self, Message* ques);

SCFunction* SC_Class_FirstDestructor(SCClass* self);

bool SC_Class_HasObjectProperties(SCClass* self);

bool SC_Class_HasOperator(SCClass* self, JB_String* op);

void SC_Class_LoadClassType(SCClass* self);

SCDecl* SC_Class_NotConst(SCClass* self);

bool SC_Class_TestBanned(SCClass* self);

JB_String* SC_Comp__AddSCProj(JB_String* Path);

JB_String* SC_Comp__FindProjNoSuffix(JB_String* Path);

SCFunction* SC_Comp__LoadTypeTest(JB_String* s);

void SC_Comp__Timer(JB_String* name);

void SC_CppRefs_SetDefaultRefStatus(CppRefs* self);

void SC_Cpp_FuncStart(Cpp_Export* self, FastStringCpp* fs, SCFunction* f, JB_String* funcheader);

FastStringCpp* SC_Cpp_StreamChild(Cpp_Export* self, JB_String* s);

void SC_Cpp__C_ParamsRender(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderBrel(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderList(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderRel(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderSStr(Message* self, FastStringCpp* fs);

void SC_Cpp__WriteConst(SCDecl* D, FastStringCpp* T);

SCDecl* SC_DeclOfObjForC(Message* curr);

bool SC_Decl_CantBeNilInCpp(SCDecl* self);

SCDecl* SC_Decl_ContainedReplace(SCDecl* self, SCDecl* contains, bool NeedsName);

SCDecl* SC_Decl_Containedfix(SCDecl* self);

SCDecl* SC_Decl_DownGrade(SCDecl* self);

SCDecl* SC_Decl_MakeBorrowed(SCDecl* self, bool StayBorrowed);

SCDecl* SC_Decl_MakeExistance(SCDecl* self, NilState type, SCDecl* Default);

SCDecl* SC_Decl_NilConstructor(SCDecl* self, NilState type);

bool SC_Decl_SafelyWrappable(SCDecl* self);

Message* SC_DefaultStitch(Message* Default, Message* dcl);

void SC_DotFuncToNormalFunc(Message* dot, SCFunction* fn);

void SC_Err_Improve(JB_Error* self);

JB_String* SC_Err_SCOriginalPath(JB_Error* self);

bool SC_Errors__SyntaxAccess(JB_Error* Err);

bool SC_Ext__HasType(Array* CppList, JB_String* Type);

bool SC_FB__AppVersionNumber(JB_String* Name, JB_String* Value, FastString* purpose);

inline void SC_Func_Constructor(SCFunction* self, Message* msg);

void SC_Func_DoLinkTo(SCFunction* self, SCBase* B);

SCObject* SC_Func_InsertIn(SCFunction* self, SCBase* parent, JB_String* name);

void SC_Func_RefFunc(SCFunction* self, Message* prm, Message* after);

JB_String* SC_Func_Render(SCFunction* self, FastString* fs_in);

void SC_Func_TranDebugInsert(SCFunction* self);

bool SC_Func__CanKeepAsSource(Message* list, Message* arg, SCDecl* d);

bool SC_Func__CanKeepAsValue(SCIterator* iter, Message* arg, SCDecl* dcl, Message* value);

void SC_Func__Tran_Sdt(Message* exp);

bool SC_Imp_CanBan(SCImport* self, SCFile* scf);

bool SC_Imp__IsInputName(JB_String* name);

Message* SC_Iter_MakeWhile(SCIterator* self, Message* arg, Message* postcond);

int SC_Macros__Init_();

int SC_MaterialsLol__InitCode_();

void SC_Mod_AddDelayedInit(SCModule* self, Message* src, Message* dest, JB_String* fn_name);

Message* SC_Mod_BuildInitArg(SCModule* self);

SCObject* SC_Mod_GetTheNewer(SCModule* self);

JB_String* SC_Mod_Render(SCModule* self, FastString* fs_in);

inline void SC_Msg_AddValue(Message* self, SCFunction* f);

SCFunction* SC_Msg_AutoMsgFunc(Message* self);

void SC_Msg_AvoidSafeDecr(Message* self);

void SC_Msg_CopyAllAfterInto(Message* self, Message* into, Message* copylayer);

void SC_Msg_CopyAllBefore(Message* self, Message* Before, Message* copylayer);

void SC_Msg_CopyAllBeforeInto(Message* self, Message* into, Message* copylayer);

void SC_Msg_CopyAllInto(Message* self, Message* j, bool wipe);

Message* SC_Msg_CreateNil(Message* self);

Message* SC_Msg_CutifyCopy(Message* self);

Message* SC_Msg_ExpectParamsTransform(Message* self, int P, Message* errnode, JB_String* Type);

void SC_Msg_FixMultiArr(Message* self);

int SC_Msg_GetAddressOf(Message* self, SCDecl* Type, bool WasCArray);

SCFunction* SC_Msg_IsParentConCall(Message* self);

bool SC_Msg_IsSettablePlace(Message* self);

Message* SC_Msg_LayerWipeCopy(Message* self, Message* oof);

Message* SC_Msg_MacroAvoidCopy(Message* self);

Message* SC_Msg_MacroSame(Message* self, Message* prm);

Message* SC_Msg_NeedBra(Message* self);

Message* SC_Msg_NegateThg(Message* self);

bool SC_Msg_RefDisappears(Message* self);

void SC_Msg_Safe(Message* self, FastString* fs);

Message* SC_Msg_TheTmpVarOf(Message* self, JB_String* tmpname);

MaybeBool SC_Msg_Trueness(Message* self, NilState found);

Message* SC_Msg_UnReachable(Message* self);

Message* SC_Msg_UseNonRefChangers(Message* self, bool parent);

void SC_Msg_WrapFloatOrInt(Message* self, DataTypeCode T, int N, SCDecl* D);

Message* SC_NewDeclNum(SCDecl* D, int64 N, JB_String* VarName);

Message* SC_NewEqRelWithStrStr(JB_String* L, JB_String* R);

Message* SC_NewFnc(JB_String* name);

Message* SC_NewRel(Message* L, Message* R, JB_String* op);

NilTest* SC_NilTest_Exists5(NilTest* self);

void SC_Opp__AddComp(JB_String* s, fn_OpASM ASM);

SCOperator* SC_Opp__Lookup(Message* opch);

inline void SC_SCFile_Constructor(SCFile* self, JB_File* f, SCImport* p);

SCBase* SC_SCGame3D__Love(Message* node, SCBase* name_space, Message* ErrPlace);

SCFunction* SC_SCObject_Disambiguate(SCObject* self, Message* src);

void SC_SCObject_DoLinkFrom(SCObject* self, SCBase* B);

void SC_SCSelector__LoadOneSel(JB_String* sel_name, JB_String* module_name, Message* LoaderPlace, Message* Prms);

SavingTest* SC_SavingTest__New(int n);

bool SC_SettingMemory(Message* Rel);

bool SC_SettingSelfProperty(Message* Rel);

Message* SC_SpellOutMsg(Message* type, Message* Exp, Message* namemsg);

JB_String* SC_Str_ASMNormalise(JB_String* self);

JB_String* SC_Str_ContainerName(JB_String* self, JB_String* ext);

bool SC_Str_IsSpeedieSrc(JB_String* self);

int SC_Str_IsSwizzle(JB_String* self, int Width);

JB_String* SC_Str_ScriptContainer(JB_String* self, JB_String* container);

void SC_VM_Builder__VMLine(Message* line, FastString* vm);

int SC_flat__Init_();

NilState SC_nil__Type(Message* msg, NilCheckMode Test);

void jbl(JB_Object* self);

void ndb4();

int JB_Constants__InitCode_();

int JB_Constants__Init_();

JB_Error* JB_Err__New(Message* node, JB_String* desc, ErrorSeverity level, JB_String* path);

Array* JB_ErrorSeverity__InitNames();

JB_File* JB_File_Parent(JB_File* self);

void JB_Flow_Fail(FlowControl* self, JB_String* found, JB_String* expected, JB_String* InputName);

void JB_Msg_Acc__(Message* self, FastString* fs);

JB_String* JB_Msg_RenderJbin(Message* self, JB_String* shell_path, FastString* fs_in);

void JB_Msg_SetMsg(Message* self, JB_String* key, Message* Value);

void JB_Msg_Unit__(Message* self, FastString* fs);

JB_String* JB_MzSt_Render(CompressionStats* self, FastString* fs_in);

SpdProcess* JB_Proc__New(JB_String* path, SpdMainFn fn, JB_StringC* DebugName, Array* params, ProcessMode Mode);

int JB_Rec_ReturnErrors(JB_ErrorReceiver* self, JB_ErrorReceiver* To);

JB_ErrorReceiver* JB_Rec__New();

int JB_SS_NonZeroByte(StringReader* self);

ObjectSaver JB_Saver__New();

ErrorInt JB_Str_MakeEntirePath(JB_String* self, bool Last);

Message* JB_Str_Msg(JB_String* self);

bool JB_Str_OperatorEndsWith(JB_String* self, JB_String* s);

JB_String* JB_Str_ReplacePathComponent(JB_String* self, int num, JB_String* With);

Message* JB_Tk__NumberSub(int Start, int RealStart);

void JB_Tk__TokenzFn(JB_String* s, int bits, ParseHandler func);

inline void JB_bin_Constructor(FastString* self, Syntax type, JB_String* data);

Message* JB_int_Msg(int self);

Message* SC_AC__BuildError(JB_String* name);

Message* SC_AC__CmdCleanUp(Message* arg);

void SC_AC__IdentifyBetter(Message* node, JB_String* name);

Message* SC_AC__ReportMemory(Message* cmd);

SCArg* SC_Arg__New(Message* node);

void SC_Array_AppendWords(Array* self, JB_String* R);

SCBehaviour* SC_Beh__New(SCClass* parent);

bool SC_CanOpCompare(Message* exp, SCDecl* lc, SCDecl* rc, SCOperator* comp);

JB_String* SC_Class_APIStructName(SCClass* self);

JB_String* SC_Class_CSuperStructName(SCClass* self);

void SC_Class_LibExport(SCClass* self, FastString* j);

JB_String* SC_Comp__FindSpeedieRoot();

bool SC_Comp__IsTest();

void SC_Cpp_ExportSyx(Cpp_Export* self);

void SC_Cpp__C_RenderTmp(Message* self, FastStringCpp* fs);

Message* SC_Decl_DeclToDot(SCDecl* self, SCDecl* P0);

SCDecl* SC_Decl_DefaultToReal(SCDecl* self);

SCDecl* SC_Decl_MakeContainedOptional(SCDecl* self);

SCDecl* SC_Decl_MakeNewNil(SCDecl* self);

SCDecl* SC_Decl_MakeNewOptional(SCDecl* self);

SCDecl* SC_Decl_MakeReal(SCDecl* self);

Message* SC_Decl_WriteNilRel(SCDecl* self);

Message* SC_Decl_WriteSimpleType(SCDecl* self);

JB_String* SC_Err_SCOriginalData(JB_Error* self);

bool SC_FB__AppOptions_arch(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_products(JB_String* Name, JB_String* Value, FastString* purpose);

void SC_Func_CollectLinks(SCFunction* self, JB_Object* obj);

JB_String* SC_Func_ParamUniquer(SCFunction* self, JB_String* s);

Message* SC_Func__AlterPostCond(Message* PostCond, Message* IterPostCond, Message* NodeSrc);

Message* SC_Func__ArgToFunc(JB_String* NewName, Message* Params, Message* arg);

SCFunction* SC_Func__New(Message* msg);

Message* SC_Msg_ConstantExpandSub(Message* self);

void SC_Msg_CopyAllAfter(Message* self, Message* after, Message* copylayer);

void SC_Msg_CopyAllAfterBefore(Message* self, Message* Before, Message* copylayer);

void SC_Msg_ElseNeverFires(Message* self);

Message* SC_Msg_FalsifyNil(Message* self);

void SC_Msg_FixElseif(Message* self);

Message* SC_Msg_Negate(Message* self);

Message* SC_Msg_NiceParent(Message* self);

void SC_NR_CollectSelfs(SCNodeRenamer* self, Message* root);

Message* SC_NewDeclWithStrMsg(JB_String* type, Message* RelOrName);

Message* SC_NewEqRelWithMsgMsg(Message* L, Message* R);

Message* SC_NewRejoin();

NilTest* SC_NilTest_Exists7(NilTest* self);

void SC_Opp__BuildOrder();

void SC_Rec_PrePrintErrors(JB_ErrorReceiver* self);

void SC_Refs__RefIncr(Message* msg, Message* Place, bool IsJustAnArg);

Message* SC_Refs__RefMsg(Message* msg, JB_String* name, SCFunction* func);

Message* SC_Refs__RefMsg0(JB_String* name, SCFunction* func);

SCFile* SC_SCFile__New(JB_File* f, SCImport* p);

JB_String* SC_Str_SpdScriptName(JB_String* self);

Array* SC_TreeAssembler__CollectFuncs(JB_String* exp);

Array* SC_VM_Builder__DefineGet(JB_String* fname, int up, int down, bool last);

NilState SC_nil__DetectStillChecks(Message* first);

void jdb2(RingTree* self);

void jdb3(RingTree* self);

void JB_Err__CantParseNum(Message* Where, JB_String* num, int Pos);

JB_String* JB_ErrorSeverity_Render(ErrorSeverity self, FastString* fs_in);

void JB_Msg_SetStr(Message* self, JB_String* key, JB_String* Value);

void JB_MzSt_Print(CompressionStats* self);

bool JB_Proc_Send(SpdProcess* self, Message* msg);

void JB_Proc__InitOwner();

void JB_Rec__NewErrorSub(Message* node, JB_String* Desc, JB_String* path, int sev);

JB_String* JB_Sav_SaveTo(Saveable* self, FastString* fs_in);

JB_String* JB_Str_BackToApp(JB_String* self);

JB_String* JB_Str_Sibling(JB_String* self, JB_String* name);

Message* JB_Tk__ErrorAlwaysAdd(JB_String* s, Ind Start);

Message* JB_Tk__fNumber(int Start, Message* Parent);

FastString* JB_bin__New(Syntax type, JB_String* data);

void SC_AC__ParserRestore();

JB_String* SC_Base_UniquifyExport(SCBase* self, JB_String* s);

JB_String* SC_Comp__Projects();

void SC_Cpp__WriteClass(SCClass* C, FastStringCpp* T);

SCDecl* SC_Decl_MakeNewReal(SCDecl* self);

void SC_Decl_NoBlindCasts(SCDecl* self, SCDecl* old, Message* exp, SCBase* name_space);

void SC_Err_SCGrabLine(JB_Error* self, FastString* fs, bool Usecolor);

int SC_Err_SCLineCount(JB_Error* self);

void SC_Ext__MacBothArch(Array* r);

void SC_FB__StopStripping();

JB_String* SC_Func_ExportNameBuilder(SCFunction* self, JB_String* CppPart);

void SC_Func_MakeParamsReal(SCFunction* self);

void SC_Func_PostTransform(SCFunction* self);

void SC_IR_SyntaxExpect(IR* self, JB_String* Error);

Message* SC_MakeDeclOrRel(Message* Into, Message* namemsg, Message* value);

Message* SC_Msg_IsInDeclInBlock(Message* self);

Message* SC_Msg_IsSetIntoPlace(Message* self);

void SC_Msg_Next_Index(Message* self, SCIterator* iter, Message* node2);

JB_String* SC_Msg_RenderType(Message* self);

SCArg* SC_Msg_SCArg(Message* self, SCBase* p, Message* avoid);

Message* SC_NewDeclWithStrStr(JB_String* type, JB_String* name);

int SC_NilTest__Init_();

inline void SC_PA_Constructor(SCParamArray* self, Message* exp);

Message* SC_Refs__RefClearMsg(Message* msg);

Message* SC_Refs__RefDecrMsg(Message* msg);

Message* SC_Refs__RefDestructorMsg(Message* msg, SCFunction* fn);

Message* SC_Refs__SafeDecrMsg(Message* msg);

void SC_RelSetOrExpansion(Message* exp);

JB_File* SC_Str_MakeAndGoInto(JB_String* self);

JB_String* SC_Str_ResolveSpd(JB_String* self);

JB_String* SC_Str_ScriptLocation(JB_String* self, JB_String* container);

JB_String* JB_App__AppPath();

void JB_App__PrefsSet(JB_String* s, JB_String* Value);

JB_String* JB_Err_RenderClang(JB_Error* self, FastString* fs_in);

JB_File* JB_File_Sibling(JB_File* self, JB_String* name);

int JB_Msg_PrevIndentCheck(Message* self, Message* pr);

void JB_MzSt_LiveUpdate(CompressionStats* self, int inn, int outt);

int JB_Proc__InitCode_();

void JB_Rec__NewErrorWithNode(Message* node, JB_String* Desc, JB_String* path);

void JB_Rec__NewProblem(Message* node, JB_String* Desc, JB_String* path);

void JB_Rec__NewWarning(Message* node, JB_String* Desc, JB_String* path);

void JB_Sav_SaveToFile(Saveable* self, JB_File* f);

Message* JB_Tk__ErrorAdd(JB_String* s, Ind Start);

Message* JB_Tk__IndentBug(Message* curr);

JB_File* SC_Comp__Jeebox();

JB_File* SC_Comp__Library();

JB_File* SC_Comp__Speedie();

JB_String* SC_Comp__SpeedieProj();

void SC_Cpp__WriteDeclNoName(SCDecl* D, FastStringCpp* T);

void SC_Err_SCLineIdentifiers(JB_Error* self, FastString* fs, JB_String* Data);

JB_String* SC_Ext__BackupPath();

JB_File* SC_Ext__CppLib();

JB_String* SC_Ext__ProductPath(bool Direct);

void SC_Func_IsCppInBuiltSet(SCFunction* self, int Value);

JB_String* SC_Func_WrapName(SCFunction* self);

Message* SC_Msg_CreateOwnBlock(Message* self);

Message* SC_Msg_IsSetIntoVar(Message* self);

SCArg* SC_Msg_SCArgNested(Message* self, Message* base, SCBase* p);

JB_String* SC_PA_ModuleName(SCParamArray* self);

SCParamArray* SC_PA__New(Message* exp);

void SC_Refs__RefSafeDecr(Message* msg, Message* place);

void SC_SCSelector__DeclareOneSel(JB_String* sel_name, JB_String* type, Message* place);

void SC_VM_Builder__VMDecl(Message* tmp, Array* msgs);

IR* SC_flat_FindLabel(ASMFuncState* self, IR* dbg);

JB_String* JB_App__AppName();

void JB_File_Fail(JB_File* self, JB_String* Error);

void JB_Msg_CantFind(Message* self, Syntax s, JB_String* name, Message* found);

void JB_Msg_SyntaxDeprecate(Message* self, JB_String* Error);

void JB_Msg_SyntaxExpect(Message* self, JB_String* Error);

void JB_Msg_SyntaxWarn(Message* self, JB_String* Error);

void JB_Object_Fail(JB_Object* self, JB_String* Error);

void JB_Object_SyntaxExpect(JB_Object* self);

int JB_Rec_RenderErrors(JB_ErrorReceiver* self, FastString* fs, ErrorSeverity Level, bool shell);

void JB_SS_SyntaxExpect(StringReader* self, JB_String* Error);

void JB_Str_SyntaxExpect(JB_String* self);

Message* JB_Tk__CloseXML(Message* XML, int i, JB_String* s);

void JB_Tk__ErrorEvent(int Start, int ExpectedBits, int RealBits);

void JB_Tk__ErrorLetter(int Start);

bool JB_Tk__ExpectEndChar(int start, JB_String* s, bool Expect);

Message* JB_Tk__LoweredIndent(Message* output, Message* curr);

bool JB_Tk__NeedName(Message* thg);

ParserLineAndIndent JB_Tk__NextLineAndIndent(Message* parent);

Message* JB_Tk__PostInnerAdj(Message* Rel, Message* opp);

Message* JB_Tk__UnexpectedSyntax(Message* bad);

Message* JB_Tk__XMLWhatever(int s, int skip, JB_String* ender, Syntax fn);

Ind JB_Tk__XMLWordEnd(int From);

Message* JB_Tk__fBackTick(int Start, Message* Parent);

Message* JB_Tk__fBinary(int Start, Message* Parent);

Message* JB_Tk__fChar(int Start, Message* Parent);

Message* JB_Tk__fComment(int Start, Message* Parent);

Message* JB_Tk__fError2(int Start, Message* Parent);

Message* JB_Tk__fOppSyxNeq(int Start, Message* Parent);

Message* JB_Tk__fSuperStr(int Start, Message* Parent);

Message* JB_Tk__fXML_DocType(int Start, Message* Parent);

JB_String* SC_Cpp__CDotType(Message* msg, SCDecl* Type, FastStringCpp* fs);

bool SC_Cpp__C_OneParamType(FastStringCpp* fs, Message* Curr, SCDecl* D);

void SC_Cpp__WriteDecl(SCDecl* D, FastStringCpp* T, Message* equality);

void SC_Cpp__WriteDeclBrackets(Message* self, FastStringCpp* fs);

JB_String* SC_Err_Render_Unix(JB_Error* self, FastString* fs_in);

bool SC_Ext__ShouldTransComp();

int SC_FB__CheckSelfModifying2();

void SC_SCFile_DetectInsecureWords(SCFile* self);

void SC_SCObject_Fail(SCObject* self, JB_String* Error);

void SC_VM_Builder__VMTmp(Message* tmp, Array* msgs);

bool SC_flat_LoadLabelJumps(ASMFuncState* self);

bool JB_CompareError(Message* expected, Message* found);

bool JB_Constants__TestCasting();

JB_Object* JB_Dict_Expect(Dictionary* self, Message* m);

ErrorSeverity JB_ErrorSeverity__Find(JB_String* name, Message* err);

FastString* JB_FS__Use(JB_Object* other);

bool JB_FastBuff_NeedAlloc(FastBuff* self, int n);

void JB_FastBuff_SyntaxExpect(FastBuff* self, JB_String* s);

JB_File* JB_File_Child(JB_File* self, JB_String* name);

bool JB_File_CompareMsg(JB_File* self, ErrorInt code, JB_String* Error);

bool JB_File_MustExist(JB_File* self, JB_String* operation);

void JB_LD_Finish(ObjectLoader* self);

void JB_LD_LoadClass(ObjectLoader* self, Message* msg, Dictionary* dict);

bool JB_Mrap_SetCap(MWrap* self, int value);

bool JB_Msg_Expect(Message* self, Syntax type, JB_String* name);

bool JB_Msg_ExpectLast(Message* self, JB_String* err);

Message* JB_Msg_FindNested(Message* self, Syntax fn, JB_String* name, bool Err);

Message* JB_Msg_FindSyxName(Message* self, Syntax s, JB_String* name, bool Err);

float JB_Msg_Float32(Message* self);

Message* JB_Msg_GetConf(Message* self, JB_String* key, bool Err);

int64 JB_Msg_Int(Message* self, int i);

Message* JB_Msg_Last(Message* self, Syntax Need);

Message* JB_Msg_NeedFirst(Message* self);

Message* JB_Msg_NeedSyx(Message* self, Syntax s);

Message* JB_Msg_NeedSyxInt(Message* self, Syntax s, int n);

Message* JB_Msg_NeedSyxOK(Message* self, Syntax Need, Syntax OK);

Message* JB_Msg_NextOf(Message* self, Syntax Need);

SyntaxObj* JB_Msg__GetFunc(Message* msg);

int JB_Rec_PrintErrorsMain(JB_ErrorReceiver* self, ErrorSeverity Level, bool PrintCount, bool shell);

JB_String* JB_Rec_Render(JB_ErrorReceiver* self, FastString* fs_in);

int64 JB_SS_hInt(StringReader* self);

void JB_Saver_Destructor(ObjectSaver* self);

bool JB_Str_Yes(JB_String* self);

Message* JB_Tk__DecorateThing(Message* R, int Ops);

Message* JB_Tk__FillXML(Message* XML, Ind i);

Message* JB_Tk__MakeInvisArg(Message* tmp, int indent);

int JB_Tk__WordAfterSub(int Start, CharSet* cs);

Message* JB_Tk__fOppBracket(int Start, Message* Parent);

Message* JB_Tk__fURL(int Start, Message* Parent);

Message* JB_Tk__fXML_Comment(int Start, Message* Parent);

void JB_bin_CloseSection(FastString* self, uint c);

void SC_AC__ActualDefine(Message* rz, Message* s, JB_String* purpose);

bool SC_AC__InitedOK();

void SC_ArgArrayCounter_Check(ArgArrayCounter* self, Message* exp);

void SC_Base_ConstantExpand(SCBase* self, Message* ch);

bool SC_Base_RehomeExport(SCBase* self);

SCClass* SC_Base_ShouldBeClass(SCBase* self, Message* errplace);

SCModule* SC_Base_SpaceModule(SCBase* self, Message* errplace);

void SC_Base_TryAdd(SCBase* self, Message* ErrPlace, SCObject* IncObj, JB_String* name);

void SC_Class_BannedCheck(SCClass* self, Message* src);

int SC_Class_CalculateSizeRaw(SCClass* self, int Depth);

void SC_Class_CheckAllocVsWrapper(SCClass* self, SCFunction* f, bool IsConstructor);

SCFunction* SC_Class_FindFunc(SCClass* self, JB_String* keyword, bool CheckParents, bool DoError);

void SC_Class_GetStructDepth(SCClass* self);

void SC_Class_Iterfailed(SCClass* self, JB_String* name, Message* node);

void SC_Class_NeedsDefaultValue(SCClass* self, Message* def, Message** place, JB_String* name);

SCBase* SC_Class__ExtendOneFunc(Message* node, SCBase* name_space, Message* ErrPlace);

JB_String* SC_Class__LoadClassName(Message* node);

SCBase* SC_ClsCollectTable_pragma(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_CodeSorter__LeafsFirst();

void SC_Comp__CheckIsGoodLibrary();

SCFunction* SC_Comp__FindFunction(JB_String* Name);

SCModule* SC_Comp__FindModule(JB_String* name, Message* where, bool ErrMsg);

SCBase* SC_Comp__WrongConf(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Cpp_AppendPropField(Cpp_Export* self, SCDecl* prop, FastStringCpp* fs);

void SC_Cpp_ExportModuleProperties(Cpp_Export* self, SCModule* modl, FastStringCpp* IntoModule);

void SC_Cpp__C_RenderFnc(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderTyp(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderUnt(Message* self, FastStringCpp* fs);

void SC_Cpp__WriteFuncArgs(SCFunction* F, FastStringCpp* T, bool names_only);

void SC_Cpp__WriteThgMaybeTypeToo(Message* msg, SCDecl* d, FastStringCpp* fs);

DataTypeCode SC_Decl_GameType(SCDecl* self);

SCDecl* SC_Decl_GetAddress(SCDecl* self, DeclMode Purpose);

SCDecl* SC_Decl_MakeAsObject(SCDecl* self, SCDecl* Container, Message* ErrPlace);

void SC_Decl_NilPrmFail(SCDecl* self, Message* where, SCFunction* f);

bool SC_Decl_NoFloat(SCDecl* self, Message* exp);

SCDecl* SC_Decl_RefineDecl(SCDecl* self, Message* list);

JB_String* SC_Decl_TryUseSaveable(SCDecl* self, bool IsSave, SCClass* cls);

JB_String* SC_Err_SCRender(JB_Error* self, FastString* fs_in);

bool SC_Ext__ExecuteGCC(Array* Commands);

bool SC_FB__AppOptions_target(JB_String* Name, JB_String* Value, FastString* purpose);

void SC_FastStringCpp_AppendBehaviour(FastStringCpp* self, JB_String* name, SCFunction* fn, SCClass* Type);

Message* SC_Func_AddParentAllocFunc(SCFunction* self, Message* root, SCFunction* fn);

void SC_Func_CheckNotBadName(SCFunction* self);

Message* SC_Func_CountCallsToParentAlloc(SCFunction* self, Message* root);

void SC_Func_NilSelff(SCFunction* self, Message* where, NilState v);

void SC_Func_WantAs(SCFunction* self, NilState NS);

SCBase* SC_Func__DebugInsert(Message* node, SCBase* name_space, Message* ErrPlace);

bool SC_Func__InBuiltFunc(Message* self, JB_String* name);

void SC_Func__Tran_Else(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Fails(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_NotAllowed(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Rejoin(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Temporal(SCFunction* fn, Message* s, SCBase* name_space);

SCFile* SC_Imp_ImportSpd(SCImport* self, JB_File* c);

Instruction* SC_Instruction__SyntaxAccessWithMsg(Message* m);

void SC_Mod_MoveToInitFunc(SCModule* self, Message* c);

SCModule* SC_Mod_OneOrOther(SCModule* self, SCModule* B);

void SC_Msg_BunchFixSub(Message* self, Message* subject, Message* stuff);

void SC_Msg_CheckNotInStateExpr(Message* self, Message* top);

void SC_Msg_CheckSuperDotSave(Message* self, JB_String* name, bool ShouldBe);

Message* SC_Msg_CollectDclName(Message* self);

void SC_Msg_ExpectEmpty(Message* self);

bool SC_Msg_ExpectInt(Message* self, SCDecl* type);

Message* SC_Msg_FailOrCopy(Message* self, Message* p);

void SC_Msg_KinderRemoveAfter(Message* self);

Message* SC_Msg_MacroPrm(Message* self, Message* root, Array* prms);

int SC_Msg_ModelMode(Message* self);

Message* SC_Msg_ModelType(Message* self);

Message* SC_Msg_QMarkRel(Message* self);

NilState SC_Msg_Redundant(Message* self, SCDecl* dcl, NilCheckMode Test);

bool SC_Msg_TestFuncName(Message* self);

bool SC_Msg_TrueOrFalse(Message* self);

bool SC_Msg_UnitMatch(Message* self, JB_String* a, JB_String* b);

void SC_NR_CollectDclThg(SCNodeRenamer* self, Message* DclThg);

void SC_NR_Rename(SCNodeRenamer* self, Message* name);

SCFunction* SC_PA_ArgsMatchError(SCParamArray* self, int TypeCast, SCFunction* f, SCFunction* R);

void SC_PA_addsub(SCParamArray* self, Message* m);

void SC_Refs__RC_CheckFuncAllocOK(SCFunction* self, Message* dot);

SCBase* SC_RootCollectTable_extends(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_RootCollectTable_static(Message* node, SCBase* name_space, Message* ErrPlace);

bool SC_SCGame3D__NeedShader(JB_String* Name);

bool SC_SCSelector__HasClassStuff(Message* self);

void SC_SC_MakeComment(Message* msg);

bool SC_Str_IsOKForImport(JB_String* self);

int SC_TC_FloatIntMerge(DataTypeCode self, int old, Message* s);

void SC_TemporalStatements_alert(SCFunction* fn, Message* node, SCBase* name_space);

void SC_TemporalStatements_break(SCFunction* fn, Message* node, SCBase* name_space);

void SC_TemporalStatements_do(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Tran_MsgList(SCFunction* fn, Message* Exp, SCBase* name_space);

ASMFunc* SC_TreeAssembler__AccessStr(Message* m);

SCObject* SC_TypeOfExprSub(Message* Exp, SCBase* name_space, Message* side);

int SC_UseCustomOperators(SCDecl* LC, SCDecl* RC, SCOperator* Comp, Message* ErrPlace);

void SC_VM_Builder__BuildInstructions(SCFunction* fn, Message* node, SCBase* name_space);

Array* SC_VM_Builder__VMSpd(Message* list);

void SC_flat_AddLabel(ASMFuncState* self, Message* ch);

uint SC_flat_GetLabelJump(ASMFuncState* self, Message* P);

void SC_flat_NeedSomewhere(ASMFuncState* self, Message* err, AsmReg* dest, DataTypeCode T);

IR* SC_flat_RequestOp(ASMFuncState* self);

NilRecord SC_nil_BranchEnter(ArchonPurger* self, Message* where);

NilState SC_nil_DeclareSub(ArchonPurger* self, SCDecl* D, NilState nd);

NilState SC_nil__Argument(Message* msg, NilCheckMode Test);

NilState SC_nil__Return(Message* msg, NilCheckMode Test);

void SC_xC2xB5Form_LoadParam(xC2xB5Form* self, JB_String* pl, Message* place);

JB_String* JB_App__Conf(JB_String* name);

JB_String* JB_App__GetPref(JB_String* s);

void JB_FastBuff_PositionSet(FastBuff* self, int64 Value);

bool JB_File_CompareData(JB_File* self, JB_String* A, JB_String* Error);

ErrorInt JB_File_CopyAll(JB_File* self, JB_String* Dest, bool AttrOnly);

ErrorInt JB_File_DeleteAll(JB_File* self);

bool JB_File_FileCompare(JB_File* self, JB_File* A, JB_String* Error);

JB_File* JB_File_SyntaxAccess(JB_File* self, JB_String* name);

inline void JB_Flow_Constructor(FlowControl* self);

int64 JB_LD_ItemInt(ObjectLoader* self);

void JB_LD_Preload(ObjectLoader* self, Message* root, Dictionary* dict);

bool JB_LD_VerifyFormat(ObjectLoader* self, Message* root);

void JB_Mrap_CapacitySet(MWrap* self, int Value);

Message* JB_Msg_Arg(Message* self);

bool JB_Msg_ContainsStr(Message* self, JB_String* s);

Message* JB_Msg_GoIntoInvisArg(Message* self, Message* tmp, int pos);

Message* JB_Msg_NeedSyxName(Message* self, Syntax s, JB_String* name);

Message* JB_Msg_NextOfName(Message* self, Syntax Need, JB_String* Name);

bool JB_Msg_Yes(Message* self);

bool JB_Msg__TreeCompare(Message* orig, Message* reparse, bool PrintIfSame);

int JB_Rec_ShellPrintErrors(JB_ErrorReceiver* self);

JB_File* JB_Str_FileThatExists(JB_String* self, JB_String* operation);

Message* JB_Tk__ProcessThingSub(Message* Parent, int Ops, int KindOfThing, bool Expect);

Message* JB_Tk__ThingXMLAtt(int start, Message* Parent);

int JB_Tk__WordAfter(int Start);

void SC_AddToStaticSection(Message* arg, Message* ToAdd);

int SC_ArrayInOrderCheck(int InOrder, Message* msg);

SCBase* SC_Base_CollectSub(SCBase* self, Message* c);

Message* SC_Base_LinkagePlace(SCBase* self);

SCBase* SC_Base_ProcessLinkage(SCBase* self, Message* node, Dictionary* Table);

JB_String* SC_Base_TestExportName(SCBase* self, JB_String* s, bool Explicit);

void SC_Base_TryAddBase(SCBase* self, Message* c, SCBase* neu);

SCBase* SC_Base__LoadCppPart(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Beh_Add(SCBehaviour* self, SCBase* fn);

bool SC_Beh__Tran_Behaviour(Message* node, SCClass* cls);

int SC_Class_CalculateSize(SCClass* self, int Depth);

inline void SC_Class_Constructor(SCClass* self, Message* node, SCBase* parent, bool HasPtrs, SCModule* m);

SCFunction* SC_Class_FindSpecialFunc(SCClass* self, JB_String* keyword, bool CheckParents);

SCDecl* SC_Class_GetFlyingMemory(SCClass* self, Message* exp);

SCIterator* SC_Class_GetIteratorAny(SCClass* self, JB_String* name, Message* node);

SCClass* SC_Class_InterfaceFor(SCClass* self, JB_String* name, Message* errplace);

void SC_Class_NewDeclInClassModule(SCClass* self, JB_String* S, SCClass* T);

void SC_Class_Reach(SCClass* self, SCBase* from, Message* src);

SCBase* SC_Class__GetFalse(Message* node, SCBase* name_space, Message* ErrPlace);

SCDecl* SC_Comp__AddGlobalConst(JB_String* name, SCClass* c, NilState dcl);

Dictionary* SC_Comp__Adj(Message* f);

SCClass* SC_Comp__FindClass(JB_String* name, Message* where, bool err);

SCModule* SC_Comp__FindModuleMsg(Message* where);

SCBase* SC_Comp__FindModuleOrClass(Message* mod, bool retry);

JB_String* SC_Comp__IdealName();

SCFunction* SC_Comp__LoadRefFunc(JB_String* name);

JB_String* SC_Comp__RenderErrors(JB_ErrorReceiver* stderr, ErrorSeverity MinSev);

void SC_CppRefs_AddOne(CppRefs* self, Message* C);

bool SC_Cpp_ExportOneProperty(Cpp_Export* self, SCClass* cls, FastStringCpp* fs, JB_String* Only);

void SC_Cpp_ExportProperties(Cpp_Export* self, SCClass* cls, FastStringCpp* fs, JB_String* Ignore);

void SC_Cpp__C_RenderThg(Message* self, FastStringCpp* fs);

void SC_Cpp__WriteFuncSub(SCFunction* F, JB_String* E, FastStringCpp* T);

void SC_Cpp__WriteType(SCClass* c, FastStringCpp* fs, bool always);

bool SC_Decl_ConstInRange(SCDecl* self, Message* RN, SCDecl* rt);

Message* SC_Decl_DeclToAddr(SCDecl* self, SCDecl* P0);

void SC_Decl_MakeContainedObject(SCDecl* self, Message* ErrPlace);

void SC_Decl_MakeGameFlying(SCDecl* self, SCClass* oof, Message* m);

JB_File* SC_ExecTable__FuncFile();

bool SC_FB__AppOptions_nil(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_output_path(JB_String* Name, JB_String* Value, FastString* purpose);

void SC_FB__Help();

bool SC_File_TestSpeedie(JB_File* self, JB_String* v);

bool SC_FuncPreReader_description(SCFunction* self, Message* msg);

bool SC_FuncPreReader_disabled(SCFunction* self, Message* msg);

bool SC_FuncPreReader_opt(SCFunction* self, Message* msg);

bool SC_FuncPreReader_pragma(SCFunction* self, Message* msg);

bool SC_FuncPreReader_real(SCFunction* self, Message* msg);

void SC_Func_AddSelfToFunc(SCFunction* self, SCClass* cls, SCBase* space);

Message* SC_Func_CallParents(SCFunction* self, Message* root, bool IsConstructor);

SCDecl* SC_Func_DeclsProtoTypeAdd(SCFunction* self, SCClass* fpType);

Message* SC_Func_IsSimpleCast(SCFunction* self);

void SC_Func_MakeNilChecker(SCFunction* self, Message* msg);

bool SC_Func_ParseName(SCFunction* self, Message* node);

void SC_Func_TryAdd(SCFunction* self, SCBase* b);

void SC_Func_ValidateSaver(SCFunction* self, JB_String* name);

void SC_Func__Tran_Description(SCFunction* fn, Message* node, SCBase* name_space);

bool SC_Func__Tran_FuncTable(Message* msg);

void SC_Imp_LoadBanned(SCImport* self, Message* list);

void SC_Iter_RenameSelf(SCIterator* self, Message* Name);

void SC_Iter_RenameValue(SCIterator* self, Message* s);

bool SC_Linkage__Interpreter();

void SC_LoopInfo_FinishLoop(LoopInfo* self, Message* msg);

void SC_Mod_AddInterfaceToTable(SCModule* self, SCClass* TableCls);

void SC_Mod_AddModuleToFunc(SCModule* self, SCBase* space);

SCBase* SC_Mod__DoInitAfter(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_MoveFutureStaticsIn(Message* msg);

uint64 SC_Msg_ASMConst(Message* self);

void SC_Msg_AssignsFix(Message* self, SCFunction* f);

void SC_Msg_BecomeAppend(Message* self, JB_String* s);

ErrorSeverity SC_Msg_Blind(Message* self);

void SC_Msg_BunchlessFix(Message* self);

void SC_Msg_ConfTake(Message* self, Message* dest, JB_String* name);

bool SC_Msg_ConstIntValueSub(Message* self, SCBase* name_space, int64* v);

Message* SC_Msg_DeclName(Message* self);

int SC_Msg_DeprecatedClassOption(Message* self, JB_String* name, JB_String* Kind);

Message* SC_Msg_FindAndRemove2(Message* self, Message* place, bool NothingOK, bool IsClass);

Message* SC_Msg_FindShader(Message* self, JB_String* TypeName);

Message* SC_Msg_GetDclName(Message* self, bool Need);

void SC_Msg_LoopExitter(Message* self, int ASMType, SCBlockage ExitCode);

void SC_Msg_MacroCopy(Message* self, Message* root, Array* prms, Message* dest);

Message* SC_Msg_ModuleSrc(Message* self);

Message* SC_Msg_NeedMarker(Message* self, JB_String* s, bool b);

Message* SC_Msg_NormaliseFunc(Message* self);

int SC_Msg_ParamNum(Message* self);

uint SC_Msg_RegOrNum(Message* self, bool NeedReg);

void SC_Msg_Tran_Isnt(Message* self, JB_String* name);

void SC_Msg_WithDeclTransform(Message* self, Message* decl, Message* rel, Message* arg);

void SC_NR_Uniqueify(SCNodeRenamer* self, SCBase* p);

void SC_PA_AddParam(SCParamArray* self, Message* item);

void SC_PA_SideSet(SCParamArray* self, Message* Value);

Message* SC_SCSelector__FindItems(Message* arg);

SCBase* SC_SCThe__NewInsertion(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_SC_API__NewExportAPISub(Message* node, SCObject* parent);

bool SC_SC_Targets__SyntaxAccess(JB_String* name);

void SC_Tran_Flow(SCFunction* fn, Message* node, SCBase* name_space);

SCDecl* SC_TypeOfExpr(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfNum(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfUnit(Message* Exp, SCBase* name_space, Message* side);

SCDecl* SC_TypeOfVecAccess(Message* index, SCDecl* ty0, int w);

void SC_VM_Builder__MakeVM(Message* tmp, FastString* vm);

AsmReg SC_flat_AllocRegDecl(ASMFuncState* self, Message* exp, SCDecl* decl, AsmReg R);

AsmReg SC_flat_DoRels(ASMFuncState* self, Message* L, AsmReg dest);

Message* SC_flat_LoadTitle(ASMFuncState* self, Message* m);

inline IR* SC_flat_RequestOp2(ASMFuncState* self, uint Code);

NilState SC_nil_Declare(ArchonPurger* self, SCDecl* D, NilState nd);

Message* SC_nil_StartNil(ArchonPurger* self, SCFunction* f);

NilState SC_nil__BooleanLogic(Message* msg, NilCheckMode Test);

NilState SC_nil__CompareObjs(Message* ll, Message* rr, NilCheckMode test, SCOperator* scop);

NilState SC_nil__Tern(Message* msg, NilCheckMode Test);

void SC_nil__WhileInner(Message* Cond);

inline void SC_xC2xB5Form_ConstructorWithMsg(xC2xB5Form* self, Message* tmp);

inline void SC_xC2xB5Form_ConstructorWithStr(xC2xB5Form* self, JB_String* data);

void JB_Dict_LoadProperties(Dictionary* self, ObjectLoader* Loader);

JB_String* JB_File__AppPrefs(JB_String* name);

FlowControl* JB_Flow__New();

JB_Object* JB_Msg_RestoreLoad(Message* self);

JB_File* JB_Platform__OpenLog();

void JB_SS_PositionSet(StringReader* self, int64 Value);

JB_String* JB_SS_Str(StringReader* self, int n, int skip);

Message* JB_Tk__AddToOutput(Message* Output, Message* curr, Message* prev, int pos);

Message* JB_Tk__NewWord(Message* P, Syntax F, int Start, int SearchFrom);

Message* JB_Tk__ProcessThing(int Ops, bool Expect);

Message* JB_Tk__ProcessThingNoBar(int Ops, bool Expect);

Message* JB_Tk__ProcessThingParent(Message* parent, int Ops, int ThingFlags);

int JB_Tk__XMLAttribs(Message* XML, int start);

Message* JB_Tk__fOppWord(int Start, Message* Parent);

Message* JB_Tk__fThingWord(int Start, Message* Parent);

bool SC_Base_FindVis(SCBase* self, Message* c);

void SC_Base_SetExportName(SCBase* self, JB_String* s, bool Explicit);

void SC_Base_Tran_Const(SCBase* self, SCDecl* D, SCBase* base);

void SC_ClassLinkageTable_cpp_part(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Class_AddBehaviourOrInterface(SCClass* self, SCBase* M, Message* ErrPlace);

void SC_Class_DeclModel(SCClass* self);

SCClass* SC_Class_GetFlyingMemClassFor(SCClass* self);

SCClass* SC_Class_InterfaceForBehaviour(SCClass* self, SCFunction* Fn);

void SC_Class_LoadLinkage(SCClass* self);

void SC_Class_TryAddToProject(SCClass* self);

SCClass* SC_Class__New(Message* node, SCBase* parent, bool HasPtrs, SCModule* m);

SCClass* SC_Comp__AccessStr(JB_String* name, Message* where);

void SC_Comp__AppBuildOneLib(JB_File* inner, Message* lib);

void SC_Comp__CodeSign(JB_File* gui_exe);

void SC_Comp__FileTestsSub(JB_File* Dest, JB_File* Src, JB_String* A, JB_String* B);

Macro* SC_Comp__FindAdj(Message* exp, Array* prms);

JB_File* SC_Comp__FindProjectSub(JB_String* base, JB_String* Path);

JB_File* SC_Comp__GeneratedCppsFolder();

JB_File* SC_Comp__InputFile(JB_File* Default, JB_String* s, Message* where);

SCClass* SC_Comp__SyntaxAccess(Message* name);

void SC_CppRefs_Read(CppRefs* self, Message* node);

SCBase* SC_CppRefs__Linkage(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Cpp_ExportStruct(Cpp_Export* self, SCClass* cls, bool IsBehaviour);

void SC_Cpp_MakeWrapperFor(Cpp_Export* self, FastStringCpp* fs, SCFunction* f);

JB_File* SC_Cpp__APIHeader();

void SC_Cpp__C_RenderDcl(Message* self, FastStringCpp* fs);

void SC_Cpp__SmartWrite(JB_String* S, JB_File* F);

void SC_Cpp__WriteFunctionHeader(SCFunction* F, FastStringCpp* T);

int SC_Decl_ByteSize(SCDecl* self);

bool SC_Decl_ConstCheck(SCDecl* self, Message* ln, Message* RN, SCDecl* rc);

SCDecl* SC_Decl_DeReferenceSub(SCDecl* self, Message* brel, SCBase* name_space, bool IsAccess);

SCIterator* SC_Decl_GetIteratorAny(SCDecl* self, JB_String* name, Message* node);

JB_String* SC_Decl_RealName(SCDecl* self);

SCDecl* SC_DoOpCompare(Message* exp, SCDecl* lc, SCDecl* rc, SCOperator* comp, SCBase* name_space);

void SC_ExecTable__Run();

bool SC_Ext__Clean();

void SC_Ext__ClearThis();

void SC_Ext__InstallOne(JB_File* test);

void SC_Ext__ReplaceOld(JB_File* input, JB_File* Backs);

bool SC_ExtractAmount(Message* Prms, SCBase* name_space, SCDecl* R);

bool SC_FB__AppOptions_help(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_perry(JB_String* Name, JB_String* Value, FastString* purpose);

void SC_FB__CheckSelfModifying();

void SC_FastStringOpts__FS(Message* exp, Message* getresult);

bool SC_File_TestBatch(JB_File* self);

void SC_FuncLinkageTable_cpp_part(SCFunction* fn, Message* node, SCBase* name_space);

bool SC_FuncPreReader_nil(SCFunction* self, Message* msg);

void SC_Func_CopyParams(SCFunction* self, Message* list);

int SC_Func_CreateTypeCast(SCFunction* self, SCDecl* MyType, Message* exp, int Loss);

bool SC_Func_FindReached(SCFunction* self, SCBase* from);

void SC_Func_PreRead(SCFunction* self, Message* Arg);

SCDecl* SC_Func__Tran_AfterRel(Message* msg, SCBase* name_space, Message* side);

void SC_Func__Tran_BlindCasts(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Deprecate(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_DoAt(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Expect(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Log(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Print(SCFunction* fn, Message* node, SCBase* name_space);

bool SC_Func__Tran_RenderSub(Message* msg, SCClass* Cls);

void SC_IR_AddRegParam(IR* self, Message* src, uint write);

void SC_Imp_IncludeCHeaders(SCImport* self, JB_File* f, Array* output);

void SC_Imp_IndexLinkage(SCImport* self, Message* link, SCFile* scf);

void SC_Imp_IndexTargets(SCImport* self, Message* tar);

void SC_Imp__ExportShaders();

JB_File* SC_Imp__FindInputFolder(JB_File* f);

void SC_Iter_Renuqify(SCIterator* self, SCBase* p);

Array* SC_Iter_Uniqueify(SCIterator* self, Message* msg);

SCBase* SC_Linkage__LinkerSub(Message* node, SCBase* name_space, Message* ErrPlace);

SCDecl* SC_LowlevelArrayTransform(Message* exp, SCClass* Cls);

bool SC_Mod_TryInit(SCModule* self, Array* req);

uint SC_Msg_AndOrExpansionTest(Message* self);

bool SC_Msg_CanGetAddress(Message* self, SCBase* name_space);

int SC_Msg_CastToType(Message* self, JB_String* TypeName, SCClass* type, SCBase* name_space, int loss);

JB_String* SC_Msg_CollectUsage(Message* self);

bool SC_Msg_ConstIntValue(Message* self, SCBase* name_space, int64* v);

Message* SC_Msg_FindAndRemoveSub(Message* self, JB_String* name, bool NothingOK, bool IsClass);

bool SC_Msg_HasSelfAsFirst(Message* self);

void SC_Msg_LoopContinue(Message* self);

void SC_Msg_LoopExit(Message* self);

int SC_Msg_MacroFixCount(Message* self);

void SC_Msg_MiniTran(Message* self, SCBase* name_space, JB_String* On);

SCDecl* SC_Msg_NiceIsFlagSyntax(Message* self, Message* opch, Message* RN, SCBase* name_space, Message* side);

void SC_Msg_NotNilRZ(Message* self, SCDecl* type, SCBase* space);

void SC_Msg_PrepareAST(Message* self, JB_String* path);

uint SC_Msg_Reg(Message* self);

bool SC_Msg_TargetTest(Message* self);

int SC_Msg_WrapExpr(Message* self, SCDecl* src);

bool SC_PA_AddTestedParam(SCParamArray* self, Message* item, SCBase* name_space);

SCBase* SC_PA_DetectDotSuper(SCParamArray* self, SCBase* curr, SCBase* arg_space);

void SC_Refs__Destructable(Message* Blocker, Message* arg, Message* name);

int SC_Refs__RefBasisStruct(Message* msg, bool SetOnly);

SCBase* SC_SC_API__NewExportAPI(Message* node, SCBase* name_space, Message* ErrPlace);

SCClass* SC_TC_CreateSignedStuff(DataTypeCode self);

SCObject* SC_TranRender(Message* exp, SCBase* name_space);

SCObject* SC_TypeOfChar(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfDotDotDot(Message* Exp, SCBase* name_space, Message* side);

SCDecl* SC_TypeOfExprNeeded(Message* exp, SCBase* name_space);

SCObject* SC_TypeOfLast(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfReal(Message* Exp, SCBase* name_space, Message* side);

SCDecl* SC_TypeOfSyntaxCall(Message* exp, SCBase* name_space, Message* side);

JB_File* SC_VM_Builder__CppLibFile(JB_String* ch);

void SC_VM_Builder__VMCpp(FastString* vm, FastString* jump);

inline IR* SC_flat_AddASM(ASMFuncState* self, Message* dbg, int SM, int a, int b, int c, int d);

inline void SC_flat_AddExtended(ASMFuncState* self, Message* err, uint Bits);

void SC_flat_AddFuncParams(ASMFuncState* self, SCFunction* fn);

void SC_flat_TotalInit(ASMFuncState* self);

AsmReg SC_fn_asm_table_REL(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_THG(ASMFuncState* self, Message* exp, AsmReg Reg);

NilState SC_nil__Declaration(Message* msg, NilCheckMode Test);

void SC_nil__ExterminateZergBugs(SCFunction* f);

NilState SC_nil__ProcessCondRel(Message* msg, NilCheckMode Test);

xC2xB5Form* SC_xC2xB5Form__NewWithMsg(Message* tmp);

xC2xB5Form* SC_xC2xB5Form__NewWithStr(JB_String* data);

JB_String* JB_App__PrefPath();

void JB_Platform__Log(JB_String* s);

void JB_SS_CompressInto(StringReader* self, JB_Object* dest, int Strength, CompressionStats* st);

bool JB_SS_IsJBin(StringReader* self);

uint64 JB_SS_NextMsgInfo(StringReader* self);

JB_String* JB_SS_ReadAll(StringReader* self);

JB_String* JB_SS_StrNoAdvance(StringReader* self, int n, int skip);

Message* JB_Tk__BeforeRelSub(int Start, bool Mode);

Message* JB_Tk__ReRoute(Message* output, Message* cnj, Message* f);

Message* JB_Tk__fAdjectiveThing(int Start, Message* Parent);

Message* JB_Tk__fArgColon(int Start, Message* Parent);

Message* JB_Tk__fAskSub(int Start, Message* Parent, Syntax f);

Message* JB_Tk__fAtName(int Start, Message* Parent);

Message* JB_Tk__fAtNamedExp(int Start, Message* Parent);

Message* JB_Tk__fBAdjectiveThing(int Start, Message* Parent);

Message* JB_Tk__fDotAccess(int Start, Message* Parent);

Message* JB_Tk__fMsgList(int Start, Message* Parent);

Message* JB_Tk__fOpAsThing(int Start, Message* Parent);

Message* JB_Tk__fQuestion(int Start, Message* Parent);

Message* JB_Tk__fTemporalHashThing(int Start, Message* Parent);

Message* JB_Tk__fTemporalRel(int Start, Message* Parent);

Message* JB_Tk__fXML(int Start, Message* Parent);

Message* JB_Tk__fYoda(int Start, Message* Parent);

Message* SC_AC__FindAdj(Message* msg, bool DisplayOnly);

AsmReg SC_ASMtmp__Return(ASMFuncState* self, Message* exp, AsmReg Reg);

Message* SC_ArgArrayCounter_Do(ArgArrayCounter* self, JB_String* name, Message* item, SCBase* name_space);

Message* SC_Base_FindCppWrapper(SCBase* self, Message* place, bool isclass);

void SC_Base_LoadVisibility(SCBase* self, Message* p);

void SC_Class_AfterAfterFuncs(SCClass* self);

void SC_Class_ContainedTypeLoad(SCClass* self);

void SC_Class_DataTypePostLoad(SCClass* self);

void SC_Class_LoadSaver(SCClass* self);

void SC_Class_LoadSuperClass(SCClass* self);

void SC_Class_ModelDecls(SCClass* self);

void SC_Class_ReachBehaviours(SCClass* self);

void SC_Comp__AppBuildLibs(JB_File* inner);

void SC_Comp__FileSanityTests();

JB_File* SC_Comp__FindProject(JB_String* Path, bool error);

void SC_Comp__InitTypes();

bool SC_Comp__Reached(JB_String* s);

inline void SC_CppRefs_Constructor(CppRefs* self, Message* s);

SCBase* SC_CppRefs__ReadIntoCppRefs(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Cpp_ExportBehaviourHeader(Cpp_Export* self, SCClass* cls);

bool SC_Cpp_ExportBehaviourInstance(Cpp_Export* self, SCClass* cls, FastStringCpp* fs);

JB_String* SC_Cpp_FuncHeader(Cpp_Export* self, FastStringCpp* fs, SCFunction* F);

void SC_Cpp_WriteAPIFuncHeader(Cpp_Export* self, SCFunction* F, FastStringCpp* fs);

JB_String* SC_Cpp__CppLicence();

JB_File* SC_Cpp__CppProduct();

JB_File* SC_Cpp__HProduct();

JB_File* SC_Cpp__Product(JB_String* name);

SCDecl* SC_Decl_DeReference(SCDecl* self, Message* brel, SCBase* name_space, bool IsAccess);

int SC_Decl_TryTypeCastPointer(SCDecl* self, SCDecl* O, Message* exp, int TypeCast, bool CArray);

Array* SC_Ext__CreateCompileString(Array* FileList, JB_String* Product, JB_String* Type);

bool SC_FB__AppOptions_clean(JB_String* Name, JB_String* Value, FastString* purpose);

JB_String* SC_FB__TryUseProject(JB_String* path, bool IsScript);

bool SC_Func_MacroGet(SCFunction* self, SCParamArray* paramsarray, SCFunction* prev);

void SC_Func_StripTest(SCFunction* self);

bool SC_Func_UseCppName(SCFunction* self, JB_String* CppName);

bool SC_Func_UseExportNameConstructor(SCFunction* self, JB_String* CppPart, JB_String* CppWrapper);

bool SC_Func_UseExportWrapper(SCFunction* self, JB_String* CppWrapper);

void SC_Func__FastStringOpt(Message* s, SCBase* name_space);

void SC_Func__Tran_Beep(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Quit(SCFunction* fn, Message* node, SCBase* name_space);

bool SC_Func__Tran_Render(Message* msg, SCClass* Cls);

void SC_Func__Tran_Swap(SCFunction* fn, Message* node, SCBase* name_space);

inline void SC_Iter_Constructor(SCIterator* self, SCClass* parent, Message* msg);

SCBase* SC_Linkage__Collect(Message* node, SCBase* name_space, Message* ErrPlace);

SCFunction* SC_Msg_AutoMsgFuncFn(Message* self);

int SC_Msg_CastToBool(Message* self, SCBase* name_space);

int SC_Msg_CastToClass(Message* self, SCClass* type, SCBase* name_space);

int SC_Msg_CastToVoidPtr(Message* self, SCBase* name_space);

void SC_Msg_CheckContinuesAndExits(Message* self);

JB_String* SC_Msg_FindAndRemove(Message* self, JB_String* name, bool NothingOK, bool IsClass);

Message* SC_Msg_GetASMFunc(Message* self);

Message* SC_Msg_InBuiltSizeOf(Message* self, SCBase* name_space, SCDecl* sulf, Message* sulf_exp);

int SC_Msg_RC_HasTemporary(Message* self);

void SC_Msg_Tran_TargetSub(Message* self);

bool SC_PA_PreReadTypes(SCParamArray* self, SCBase* Name_Space, Message* P, Message* side);

int SC_Refs__RefBasis(Message* msg, bool SetOnly);

JB_String* SC_SCObject_CanAutoSub(SCObject* self, JB_String* search);

bool SC_SortInitOrderSub(Array* mods, Array* out);

SCObject* SC_TypeOfARel(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfMsg(Message* Exp, SCBase* name_space, Message* side);

xC2xB5Form* SC_VM_Builder__AddForm(Message* form);

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

void SC_flat_FinishASM(ASMFuncState* self);

Message* SC_flat_FuncPrms(ASMFuncState* self, Message* pr, int Remain, uint Bits);

void SC_flat_InitState(ASMFuncState* self, SCFunction* fn);

bool SC_flat_TrySmallConst(ASMFuncState* self, uint reg, int64 Value, Message* where);

void SC_nil__FixArchons();

xC2xB5Form* SC_xC2xB5Form__Needform(JB_String* Form);

JB_Object* JB_Object_TypeFailed(JB_Object* self, JB_Class* Cls, Message* where);

bool JB_SS_IsCompressed(StringReader* self);

Message* JB_SS_NextMsg(StringReader* self);

void JB_Str_CompressInto(JB_String* self, JB_Object* fs, int Strength, CompressionStats* st);

Message* JB_Tk__ParseItem(Message* ch, int TemporalFlags, int ops);

Message* JB_Tk__fAsk(int Start, Message* Parent);

Message* JB_Tk__fBeforeRel(int Start, Message* Parent);

Message* JB_Tk__fBeforeRelMinus(int Start, Message* Parent);

Message* JB_Tk__fInnerNiceAdj(int Start, Message* Parent);

Message* SC_AC__JumpImport(Message* cmd);

void SC_Base_CollectOne(SCBase* self, Message* c, bool Visible);

void SC_Base_LoadExportName(SCBase* self);

void SC_Comp__AppleBuildApp(JB_File* project, JB_File* product);

void SC_Comp__DeadStrip();

int SC_Comp__InitBasicStuff();

JB_File* SC_Comp__usingScript(JB_File* f);

CppRefs* SC_CppRefs__New(Message* s);

void SC_Cpp_ExportClass(Cpp_Export* self, SCClass* cls, FastStringCpp* CppFile);

void SC_Cpp_Func(Cpp_Export* self, FastStringCpp* fs, SCFunction* F);

void SC_Cpp_WriteAPIHeader(Cpp_Export* self, JB_File* destfile);

void SC_Cpp_WriteHeader(Cpp_Export* self);

bool SC_Cpp__DoSavers();

JB_String* SC_Cpp__SplitCpp(FastStringCpp* fs, JB_String* name);

int SC_Decl_TryTypeCast(SCDecl* self, SCDecl* O, Message* exp, int TypeCast);

bool SC_Ext__BackupCompiler();

bool SC_Ext__TestNewCompiler();

bool SC_Ext__TransCompile(Array* Files, JB_String* Dest, JB_String* Type);

bool SC_FB__AppOptions_self(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_selfdebug(JB_String* Name, JB_String* Value, FastString* purpose);

void SC_FB__ParseOption(JB_Object* Obj);

void SC_Func__Tran_Visible(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Imp_ImportMsg(SCImport* self, Message* j);

inline void SC_Instruction_Constructor(Instruction* self, JB_String* FormName, JB_String* name, int pos);

SCIterator* SC_Iter__New(SCClass* parent, Message* msg);

Message* SC_Msg_LastUsedFix(Message* self);

Message* SC_Msg_Tran_Target(Message* self);

void SC_Opp__Init();

bool SC_Refs__ExprNeedsTemping(Message* child, Message* name);

void SC_Refs__RC_IgnoreReturn(Message* msg, bool DoRefs);

bool SC_Refs__RelNeedsRef(Message* msg, Message* first);

void SC_Refs__ReturnTempMoveOutSub(Message* Child, Message* blocker, Message* temp);

JB_String* SC_SCObject_CanAuto(SCObject* self, JB_String* search);

Array* SC_SortInitOrder(Array* mods);

void SC_TreeAssembler__Stamp(SCFunction* fn);

AsmReg SC_flat_DoFunc(ASMFuncState* self, Message* prms, AsmReg dest);

bool SC_flat_SetConst(ASMFuncState* self, Message* List, Message* Orig);

AsmReg SC_fn_asm_table_TMP(ASMFuncState* self, Message* exp, AsmReg Reg);

void JB_Flow_Flush(FlowControl* self);

JB_Object* JB_Object_As(JB_Object* self, JB_Class* x);

JB_Object* JB_Object_FastAs(JB_Object* self, JB_Class* x);

bool JB_Object_MustBe(JB_Object* self, JB_Class* x, Message* ErrNode);

Message* JB_SS_NextMsgExpect(StringReader* self, Message* parent, Syntax fn, JB_String* name);

Message* JB_SS_ParseJbin(StringReader* self, int64 Remain);

JB_String* JB_Str_Compress(JB_String* self, int Strength, CompressionStats* st);

Message* JB_Tk__BarThings(int Start, Syntax Syx);

Message* JB_Tk__ParseLoopItem(Message* Output, int TmpoFlags, Message* Prev, int Indent);

Message* JB_Tk__fTmpSub(Message* result, int OpFlags, int ThingFlags);

void SC_Base_Collect(SCBase* self, Message* AST, bool Visible, Message* dest);

void SC_Comp__Collect(Message* m, bool visible);

void SC_Comp__Package();

void SC_Cpp_CodifyFuncs(Cpp_Export* self, FastStringCpp* file, Array* list);

void SC_Cpp__CreateClassListFunc(FastString* dest);

uint SC_Decl_TypeMatch(SCDecl* self, SCDecl* O, int TypeCast, Message* exp);

bool SC_Ext__IsCompilerAndNeedsInstall();

void SC_Ext__MakeLib();

bool SC_Ext__TransCompileWrap(Array* cpps);

bool SC_FB__ParseArgsSub(Array* args);

void SC_Func__Tran_CppRefs(SCFunction* fn, Message* node, SCBase* name_space);

Instruction* SC_Instruction__New(JB_String* FormName, JB_String* name, int pos);

inline void SC_Mod_Constructor(SCModule* self);

Message* SC_Refs__LastUsedRefPlace(Message* name, Message* arg);

void SC_Refs__RC_Rel(Message* rel);

void SC_TreeAssembler__StampAll(Array* Funcs);

bool SC_flat_TextOp(ASMFuncState* self, Message* m);

AsmReg SC_fn_asm_table_FUNC(ASMFuncState* self, Message* exp, AsmReg Reg);

void JB_Flow_AddByte(FlowControl* self, byte value);

void JB_Flow_Destructor(FlowControl* self);

bool JB_Object_OperatorMustBe(JB_Object* self, JB_Class* x);

bool JB_SS_DecompressInto(StringReader* self, JB_Object* dest, int lim, CompressionStats* st);

Message* JB_Str_ParseJbin(JB_String* self, int64 max);

int JB_Tk__ParseLoop(Message* Output, int TmpoFlags);

Message* JB_Tk__fDecl(int Start, Message* Parent);

Message* JB_Tk__fTmp(int Start, int OpFlags, int ThingFlags, Message* parent);

Message* JB_Tk__fTmpPlus(int Start, Message* Parent);

Message* JB_Tk__fTypeCast(int Start, Message* Parent);

SCDecl* SC_Base_RequireContained(SCBase* self, Message* exp);

void SC_ClassLinkageTable_datatype(SCFunction* fn, Message* node, SCBase* name_space);

void SC_ClassLinkageTable_numeric(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Class_ClassCollect(SCClass* self);

SCBase* SC_Class__GetDefault(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Class__ProcessAs(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Class__ProcessExtendOld(Message* c, bool PreferClass);

void SC_Cpp_Codify(Cpp_Export* self, SCModule* scb, JB_String* fName);

void SC_Cpp_FinalMergeOutputIntoACpp(Cpp_Export* self);

void SC_Cpp_ListAllClasses(Cpp_Export* self, FastStringCpp* fs);

void SC_Cpp_ListAllFuncs(Cpp_Export* self, FastStringCpp* fs);

bool SC_Decl_MiniMatch(SCDecl* self, SCDecl* O, int TypeCast);

SCImport* SC_Decl_Project(SCDecl* self);

void SC_Ext__InstallCompiler();

bool SC_FB__ParseArgs();

void SC_Func_CheckConstructorAndDestructor(SCFunction* self, Message* root, bool IsConstructor);

SCBase* SC_InbuiltShellArgs__Collect(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Instruction__Add(JB_String* FormName, JB_String* name, int pos);

SCBase* SC_Iter__NeuIter(Message* node, SCBase* name_space, Message* ErrPlace);

Message* SC_MakeDecl(JB_String* Type, JB_String* Name, Message* Value, SCDeclInfo Purpose);

void SC_Mod_LoadModule(SCModule* self, Message* node);

SCModule* SC_Mod__New();

SCFunction* SC_Msg_GetFunctionPointer(Message* self);

MaybeBool SC_Msg_IsAlwaysBool(Message* self);

SCClass* SC_Msg_ObjCls(Message* self);

void SC_Tran_ArgArray(Message* Exp, SCBase* name_space);

void SC_TreeAssembler__BuildPack();

SCObject* SC_TypeOfList(Message* Exp, SCBase* name_space, Message* side);

void SC_flat_TextInstruction(ASMFuncState* self, Message* m);

JB_String* SC_image__ConvertPNGToVOI(JB_String* p);

bool JB_Flow_Cond(FlowControl* self, byte value);

void JB_Flow__Input(JB_String* data, JB_String* name);

bool JB_Msg_jbinTest(Message* self);

JB_String* JB_SS_Decompress(StringReader* self, int lim, CompressionStats* st, bool Multi);

int JB_Tk__EmbeddedCode(JB_String* close, Message* dest, int TmpoFlags);

bool JB_Tk__ParseLoopFlags(Message* Output, JB_String* Ender, int TmpoFlags);

Message* JB_Tk__fStatement(int Start, Message* Parent);

Message* JB_Tk__fStatementColon(int Start, Message* Parent);

JB_String* SC_Base_LateAddTempory(SCBase* self, JB_String* type, JB_String* name1, Message* Value, Message* err);

bool SC_Comp__CollectIsaTests(Message* s);

void SC_Cpp_DoInterpreter(Cpp_Export* self);

void SC_Cpp_Run(Cpp_Export* self);

SCDecl* SC_CustomFuncOp(Message* exp, SCOperator* comp, SCBase* name_space, Message* RN);

bool SC_Decl_AlreadyContains(SCDecl* self);

JB_String* SC_Decl_RenderTypeName(SCDecl* self, FastString* fs_in);

void SC_Func_AddSelfPrm(SCFunction* self, SCClass* cls);

void SC_Func_DontWantSameReturnType(SCFunction* self, SCFunction* f);

Message* SC_Func__GetFileString(Message* msg, JB_String* name);

Message* SC_Func__TempMoveOut(Message* msg, Message* parent);

void SC_Func__Tran_ForStart(Message* arg, Message* index, SCBase* p);

Message* SC_Func__Tran_Syx(Message* msg);

void SC_Func__Tran_Using(SCFunction* fn, Message* node, SCBase* name_space);

Message* SC_Func__TypedTempMoveOut(Message* msg, JB_String* name);

void SC_Imp_IndexConf(SCImport* self, Message* conf);

void SC_Instruction__InstructionInit();

JB_String* SC_Mod_GetPrefix(SCModule* self, SCDecl* D);

void SC_Mod_LoadModuleForCls(SCModule* self, Message* node, SCClass* cls);

SCBase* SC_Mod__NeuModule(Message* node, SCBase* name_space, Message* ErrPlace);

SCModule* SC_Mod__NewContainer(JB_String* s);

SCDecl* SC_Msg_DotMustBeProperty(Message* self);

bool SC_Msg_IsAlwaysFalse(Message* self);

void SC_Msg_Tran_QMark(Message* self);

SCObject* SC_TypeOfArgArr(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfArr(Message* Exp, SCBase* name_space, Message* side);

bool SC_flat_TextFuncSub(ASMFuncState* self, Message* m);

NilState SC_nil__If(Message* msg, NilCheckMode Test);

NilState SC_nil__While(Message* msg, NilCheckMode Test);

bool JB_Flow__Cond(bool value);

bool JB_Flow__InputStrings(Array* lines, JB_String* name);

JB_String* JB_Str_Decompress(JB_String* self, int lim, CompressionStats* st);

void JB_Tk__Params(Message* Parent, int N);

Message* JB_Tk__fAccess(int Start, Message* Parent);

Message* JB_Tk__fArgOpen(int Start, Message* Parent);

Message* JB_Tk__fArray(int Start, Message* Parent);

Message* JB_Tk__fBracket(int Start, Message* Parent);

Message* JB_Tk__fQuoteLang(int Start, Message* Parent);

Message* JB_Tk__fString(int Start, Message* Parent);

Message* JB_Tk__fXML_PI(int Start, Message* Parent);

void SC_Class_OverrideSyntax(SCClass* self);

void SC_Class_ProcessInterfaces(SCClass* self);

SCClass* SC_Class__NeuClassSub(Message* node, SCBase* parent, Message* ErrPlace, JB_String* ForInterface, SCBaseType base);

void SC_Comp__CreateDisambiguation();

void SC_Cpp__C_RenderDot(Message* self, FastStringCpp* fs);

JB_String* SC_Decl_PrefixedName(SCDecl* self, SCModule* M);

JB_String* SC_Decl_RenderTypeNameNicer(SCDecl* self, FastString* fs_in);

Message* SC_Decl_WriteType(SCDecl* self, int minimal);

int SC_Ext__NeedNewObjForSrc(JB_String* cpp, JB_File* objects);

void SC_Func_FixCnjSub(SCFunction* self, Message* exp);

void SC_Func__Tran_Array(Message* S, SCBase* name_space);

inline void SC_Imp_Constructor(SCImport* self, JB_File* F, bool Builtin);

Message* SC_Msg_BunchFixPrepare(Message* self);

Message* SC_Msg_TempIntoBlock(Message* self, Message* ParentPlace);

void SC_Msg_Tran_With(Message* self);

void SC_Refs__RC_RelConstructor(Message* rel);

void SC_Refs__ReturnTempMoveOut(Message* Child, Message* blocker);

bool SC_TextAssembler__TextFunc(Message* msg);

void SC_TreeAssembler__InitAll();

Array* JB_File_List(JB_File* self, bool invis);

bool JB_Flow_LoadPath(FlowControl* self, JB_String* path, bool IsPrev);

bool JB_Str_CompressTestSub(JB_String* self, int Strength, bool report);

Message* JB_Tk__DotSub(Syntax fn, int Start, Message* parent);

Message* JB_Tk__fFuncCall(int Start, Message* Parent);

void SC_Class_AfterFuncsDecled(SCClass* self);

SCModule* SC_Class__DataTypeSub(Message* Node, SCBase* Parent, Message* ErrPlace, JB_String* ForInterface, SCBaseType BaseType);

SCBase* SC_Class__NeuClass(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Class__NewStruct(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Cpp__Init();

JB_String* SC_Decl_AutoCompleteName(SCDecl* self);

Message* SC_Decl_CreateSimpleTypeCast(SCDecl* self, Message* exp);

Message* SC_Decl_CreateStructNil(SCDecl* self, Message* errs);

JB_String* SC_Decl_ExpectFail(SCDecl* self, SCDecl* O);

Message* SC_Decl_WriteDeclSub(SCDecl* self, JB_String* Name, int minimal);

Message* SC_Decl_WriteDeclTypeAndName(SCDecl* self, JB_String* Name, int minimal);

Message* SC_Decl_WriteNilDecl(SCDecl* self);

Message* SC_Decl_WriteTypeCast(SCDecl* self, Message* msg);

Array* SC_Ext__FilterCppsIfAlreadyDone(Array* Cpps, JB_File* Objects, int* stdafx);

void SC_Func_FixCnj(SCFunction* self, Message* exp);

SCDecl* SC_Func_MacroFix(SCFunction* self, SCDecl* contains, SCBase* name_space, SCParamArray* Incoming);

SCImport* SC_Imp__New(JB_File* F, bool Builtin);

void SC_Mod_GlobalsFix(SCModule* self);

void SC_Refs__RC_HandleDisappearing(SCFunction* fn, Message* msg, int Basis);

void SC_TextAssembler__Assemble(Message* msg);

void SC___junktest_11__();

void JB_Flow_Init(FlowControl* self, JB_String* path, JB_String* DateStr);

bool JB_Str_CompressTest(JB_String* self, bool report, int which);

Message* JB_Tk__fDot(int Start, Message* Parent);

Message* JB_Tk__fSDot(int Start, Message* Parent);

void SC_ASM__TestASMSub(Message* tests);

void SC_Beh_CreateFuncTable(SCBehaviour* self, Message* ErrPlace);

SCBase* SC_Class__DataType(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Class__NeuRole(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Comp__InitCompiler();

int SC_Comp__Init_();

inline void SC_Cpp_Constructor(Cpp_Export* self);

Message* SC_Decl_CreateDefault(SCDecl* self, Message* errs, bool isfunc);

Message* SC_Decl_ExpectMatch(SCDecl* self, SCDecl* O, int TypeCast, Message* exp, Message* ErrNode);

SCDecl* SC_Decl_ProcessAs(SCDecl* self, Message* msg);

JB_String* SC_Decl_RenderTypeAndName(SCDecl* self, int minimal);

Message* SC_Decl_WriteDeclFull(SCDecl* self, JB_String* DeclName, int minimal);

Array* SC_Ext__CollectCppsInto(JB_File* Fol, JB_File* Objects, int* stdafx);

bool SC_Ext__UseAndCompile(Array* Input, JB_String* Output);

void SC_Func_PreProcessExpects(SCFunction* self);

SCFile* SC_Imp_ImportDir(SCImport* self, JB_File* f);

JB_String* SC_SCObject_CallFromName(SCObject* self);

SCDecl* SC_SameTypeSub(Message* first, Message* second, SCBase* name_space);

FlowControlStopper JB_Flow__FlowAllow(JB_String* name, uint64 StartCode);

void JB_Tk__Init();

void SC_AC__CallFromSub(Message* arg, SCFunction* fn);

Message* SC_AC__LocateDefinitionSub(Message* msg, SCObject* already_defined, SCDecl* ty, bool DisplayOnly);

void SC_Class_CreateBehaviour(SCClass* self);

Cpp_Export* SC_Cpp__New();

void SC_Decl_ExpectRelMatch(SCDecl* self, SCDecl* O, Message* exp, Message* side, Message* ErrNode);

bool SC_Decl_LoadContainedSub(SCDecl* self, SCDecl* Cont, Message* wrap, SCBase* Name_Space, DeclMode Purpose);

JB_String* SC_Decl_Render(SCDecl* self, FastString* fs_in);

Message* SC_ExpandToBool(Message* inside, SCBase* name_space);

bool SC_Ext__CollectAndCompile(JB_File* Input, JB_String* Output);

void SC_Func_CheckReturnValue(SCFunction* self, Message* msg);

Message* SC_Func_NewDefaultRel(SCFunction* self, Message* place, SCDecl* d);

Message* SC_Func__Tran_Result(SCFunction* f);

void SC_Func__Tran_ResultFinish(SCFunction* f, Message* r_z, SCBase* space);

SCDecl* SC_IsPointerMath(SCDecl* L, SCDecl* R, SCOperator* opp, Message* exp);

bool SC_Msg_ExpectClass(Message* self, SCDecl* slf, SCClass* Cls);

JB_String* SC_Msg_RenderTypeAndName(Message* self);

Message* JB_Str_Parse(JB_String* self, Syntax owner, bool AllowDecomp);

Message* SC_AC__Diissplay(Message* msg, Message* s, JB_String* purpose);

Message* SC_AC__LocateDefinition(Message* msg, SCObject* already_defined, bool DisplayOnly);

void SC_Cpp__ExportAllSource();

bool SC_Decl_LoadContained(SCDecl* self, Message* Contained, Message* wrap, SCBase* Name_Space, DeclMode Purpose);

SCDecl* SC_Decl_MakeDataTypeWrapper(SCDecl* self, SCBase* Name_Space, DeclMode Purpose);

void SC_Ext__RunCppCompile();

void SC_Func_FillInMissingConstructorDefaults(SCFunction* self, Message* root, Message* AfterHere);

JB_String* SC_Func_RenderParams(SCFunction* self, bool ForErrors, FastString* fs_in);

void SC_Func__Tran_Return(SCFunction* fn, Message* node, SCBase* name_space);

bool SC_Msg_ExpectMatch(Message* self, SCBase* name_space, SCClass* With);

SCDecl* SC_Or_And_Expansion(SCDecl* LC, SCDecl* RC, Message* exp, SCBase* name_space);

JB_String* SC_PA_Render(SCParamArray* self, FastString* fs_in);

SCObject* SC_TranNegate(Message* f, SCBase* name_space);

SCObject* SC_TypeOfTernary(Message* Exp, SCBase* name_space, Message* side);

Message* JB_File_Parse(JB_File* self, int lim, bool AllowMissing);

bool JB_Msg_TestSub(Message* self, JB_String* new_render, JB_String* name);

Message* JB_Proc_Get(SpdProcess* self, float T);

JB_String* JB_Str_Digest(JB_String* self);

Message* JB_Str_ParseWithError(JB_String* self, JB_Error** rec);

Message* SC_AC__ErrorsToPerry();

Message* SC_AC__RespondDefine(Message* msg, Message* s, JB_String* purpose);

void SC_ASM__TestASM();

void SC_Class_StartupSaver(SCClass* self, JB_String* Name);

void SC_Ext__ExportAndInstall(bool CanInstall);

SCDecl* SC_ExtractDecl(Message* c, SCBase* name_space, DeclMode Purpose);

void SC_Func_FillInSaver(SCFunction* self, JB_String* name);

JB_String* SC_Func_RenderTitle(SCFunction* self, bool ForErrors, FastString* fs_in);

SCIterator* SC_Iter__SimpleIter(JB_String* src);

Message* SC_Macro_Source(Macro* self);

Message* SC_Msg_ParseShaderSub(Message* self);

Message* SC_SCSelector__BuildClassCode(JB_String* name, JB_String* type);

SCObject* SC_TypeOfRel(Message* Exp, SCBase* name_space, Message* side);

void SC_VM_Builder__DataTypeModule();

void JB_App__ConfigureSet(JB_String* Value);

Message* JB_File_Conf(JB_File* self, int lim);

void JB_Msg_Test(Message* self, JB_String* new_render, JB_String* name);

bool JB_config_Save(Message* self);

Message* SC_AC__AllTmps();

Message* SC_AC__Define(Message* msg, JB_String* purpose, JB_Object* found);

Message* SC_AC__FuncTmps();

SCFunction* SC_Class_DoSaver(SCClass* self, JB_String* name, int stage);

void SC_Comp__PrintErrors(ErrorSeverity MinSev);

void SC_Create_JeeboxTest(Message* msg);

void SC_Func_DeclsProtoCleanup(SCFunction* self, SCClass* fpType, Message* ch0, bool AssumeSelf, bool late);

void SC_Func_DescribeParamFail(SCFunction* self, SCParamArray* params, int bad);

void SC_Func__String_Expand(Message* msg, SCFunction* fn);

int SC_Iter__InitCode_();

void SC_Msg_AppendMacro(Message* self, Macro* M, Array* prms);

SCDecl* SC_Msg_CollectDecl(Message* self, SCBase* P, SCBase* Recv, int Mode, SCClass* cls, SCFunction* FuncPrms);

Message* SC_Msg_SendPerryErrors(Message* self);

Message* SC_Msg_TranModel(Message* self);

JB_String* SC_SCObject_Display(SCObject* self, bool exact);

SCBase* SC_SCSelector__Build(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Sav__TestSaver();

SCObject* SC_TypeOfType(Message* Exp, SCBase* name_space, Message* side);

NilState SC_nil__FailedReal(SCFunction* To, Message* where, nilreason reason, NilState state);

bool JB_App__PrefsInit(Date when);

void JB_App__SavePrefs();

JB_String* JB_Constants__TestJB();

void SC_AC__AutoSub2(SCObject* value, JB_String* key, JB_String* src_name, Array* found, bool exact, int Types, SCDecl* TypeLimiter);

Message* SC_AC__CallFromDefine(Message* msg, SCFunction* fn, JB_Object* found);

Message* SC_AC__Check(Message* cmd);

Message* SC_AC__ReportBuildOrRestart(Message* cmd);

Message* SC_AC__RootTmpComplete(Message* cmd);

void SC_Class_FillInterFaceWrapper(SCClass* self, SCFunction* fn);

void SC_Comp__DoSavers(int Stage);

void SC_Comp__PrintCompileErrors();

int SC_Func_ArgsMatch3(SCFunction* self, int TypeCast, SCDecl* base, bool ThisAlter, SCBase* name_space, SCParamArray* Incoming);

void SC_Func_DeclsPrototypeClass(SCFunction* self, Message* ch0);

void SC_Func_DeclsPrototypeInterface(SCFunction* self, Message* ch0, SCClass* fpType, bool late);

void SC_Func__Tran_Strings(Message* start, SCFunction* fn);

void SC_Msg_BecomeMacro(Message* self, Macro* M, Array* prms);

bool SC_Msg_CollectAGlobalDecl(Message* self, SCBase* scarg);

bool SC_Msg_CollectFromBody(Message* self, SCBase* scarg);

bool SC_Msg_CollectOneParam(Message* self, SCFunction* func, SCBase* Recv, SCClass* cls);

bool SC_Msg_CollectProp(Message* self, SCClass* cls);

Message* SC_Msg_ReplaceInbuiltSub(Message* self, SCBase* name_space, SCDecl* self_decl);

void SC_Msg_SyntaxAppend(Message* self, Macro* M, Array* prms);

SCBase* SC_SCGame3D__NeuModel(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_SCSelector__Neu(Message* node, SCBase* name_space, Message* ErrPlace);

SCObject* SC_TypeOfStr(Message* Exp, SCBase* name_space, Message* side);

NilState SC_nil__BecomeReal(SCDecl* sent, Message* where, nilreason reason, SCFunction* To);

void SC_AC__AutoSub(SCBase* scope, JB_String* name, Array* found, int Types, Message* NeedTypeLimit);

Message* SC_AC__CallFrom(Message* msg, JB_String* purpose, JB_Object* found);

bool SC_Class_CollectDeclsProperties(SCClass* self);

void SC_Class_FillInterFaceIn(SCClass* self, SCFunction* fn, bool Late);

void SC_CollectDeclsFuncBodyJustWhatWeNewlyMade(Message* arg, SCBase* scarg);

void SC_CollectDeclsGlobals(Message* arg, SCBase* scarg);

void SC_Comp__PrintResults();

void SC_Comp__SetupEnv();

void SC_Comp__VariousSelfTests();

bool SC_FB__AppOptions_codesign(JB_String* Name, JB_String* Value, FastString* purpose);

SCFunction* SC_Func_ArgsMatch2(SCFunction* self, SCDecl* base, int TypeCast, SCBase* name_space, SCParamArray* Incoming);

void SC_Func_CollectDeclsParams(SCFunction* self, Message* prms, SCBase* AddToSpace);

void SC_Func_TranStrings(SCFunction* self);

Message* SC_Macro_CallFast(Macro* self, Message* prm1, Message* prm2);

Message* SC_Macro_SyntaxCall(Macro* self, Array* prms);

void SC_Msg_FixErl(Message* self);

NameAndMsg SC_Msg_IntoVariable(Message* self, SCBase* name_space);

SCObject* SC_TypeOfAdj(Message* Exp, SCBase* name_space, Message* side);

void SC_nil__NilParamPass(SCDecl* Recv, SCDecl* Sent, Message* where, SCFunction* f);

NilState SC_nil__ThingSub(Message* msg, NilCheckMode test, SCDecl* dcl);

NilState SC_nil__UseChildAsReal(Message* msg, nilreason reason);

NilState SC_nil__VariableSet(SCDecl* Recv, Message* RecvMsg, SCDecl* Sent, Message* SentMsg, NilState SentState);

Message* SC_AC__DefineOrCall(Message* msg, JB_String* purpose, JB_Object* found);

void SC_Class_LoadProperties(SCClass* self);

void SC_Class_ProcessBehaviours(SCClass* self);

void SC_CollectDeclsFuncBody(Message* arg, SCBase* scarg);

void SC_CollectDeclsFuncBodyUnsureHowToRemove(Message* arg, SCBase* scarg);

int SC_FB__Init_();

SCFunction* SC_Func_ArgsMatch1(SCFunction* self, SCDecl* base, SCBase* name_space, SCParamArray* Incoming, int Cast);

void SC_Func_Cleanupfunc(SCFunction* self, Message* s);

void SC_Func_FuncDecls(SCFunction* self);

void SC_Func_Init_Sub(SCFunction* self, Message* node, SCBase* name_space);

void SC_Mod_BaseDecls(SCModule* self);

void SC_Mod_InitDecls(SCModule* self);

bool SC_Msg_InitExpand(Message* self);

bool SC_Msg_RelFix(Message* self, bool force);

Message* SC_Refs__DecrMulti(SCDecl* d, Message* m);

void SC_SCFile_CollectGlobals(SCFile* self, SCBase* p);

void SC_Tran_Msg(SCFunction* fn, Message* Exp, SCBase* name_space);

SCDecl* SC_TypeOfSwizzle(Message* Exp, SCDecl* Type, SCBase* name_space, Message* side, int swiz);

Message* SC_VM_Builder__DataTypeCreate(Message* form, int fnum);

void SC_VM_Builder__FillTypePrm(JB_String* fname, int pname);

NilState SC_nil__Access(Message* msg, NilCheckMode Test);

NilState SC_nil__Brel(Message* msg, NilCheckMode Test);

NilState SC_nil__Function(Message* msg, NilCheckMode Test);

NilState SC_nil__Property(Message* msg, NilCheckMode Test);

NilState SC_nil__SetRel(Message* msg, NilCheckMode Test);

NilState SC_nil__Thing(Message* msg, NilCheckMode Test);

Message* SC_AC__Define_Behaviour(SCFunction* fn, JB_String* purpose);

Message* SC_Decl_RefDestructor(SCDecl* self);

SCFunction* SC_Func_ArgsMatch(SCFunction* self, SCDecl* base, SCBase* name_space, SCParamArray* Incoming, int DescribeFail);

SCFunction* SC_Func__NewFuncSub(Message* node, SCBase* name_space);

void SC_Func__Tran_All(SCFunction* fn, Message* s, SCBase* p);

void SC_Msg_BunchFix(Message* self);

void SC_Refs__RefDecr(Message* msg, Message* place, int Basis);

inline SCDecl* SC_TypeOfSwiz(Message* exp, SCBase* name_space, Message* side, SCDecl* class_Space);

NilState SC_nil__Rel(Message* msg, NilCheckMode Test);

SCObject* SC_Base_LookUpSub(SCBase* self, JB_String* OrigName, Message* Exp, Message* ParamsHere, SCBase* Arg_Space, SCDecl* contains, Message* side, int Purpose);

SCFunction* SC_Class__ProcessExtend(Message* c, bool PreferClass, SCModule* m);

void SC_Func_FillInDestructor(SCFunction* self);

void SC_Func_Transform(SCFunction* self);

SCBase* SC_Func__NewFunc(Message* node, SCBase* name_space, Message* ErrPlace);

bool SC_Msg_OarExpand(Message* self);

void SC_Refs__ReturnHandle(Message* Blocker, Message* arg, Message* name, int Basis);

SCObject* SC_TypeOfBlock(Message* Exp, SCBase* name_space, Message* side);

int SC_nil__Init_();

JB_Object* SC_Base_LookUpDot(SCBase* self, JB_String* name, Message* exp, SCBase* arg_space, SCDecl* contains, Message* side);

SCFunction* SC_Base_LookUpFunc(SCBase* self, JB_String* name, Message* exp, Message* ParamsHere);

SCObject* SC_Base_LookUpVar(SCBase* self, JB_String* name, Message* exp, Message* side);

SCDecl* SC_Base_LookUpVarDecl(SCBase* self, JB_String* name);

SCObject* SC_Base_LookUpVarRootDecl(SCBase* self, JB_String* name, Message* exp);

SCBase* SC_Beh__NewBehaviour(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Class__LoadSyntax(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Func_BuildConstructorDestructor(SCFunction* self);

SCBase* SC_Func__NewConstructor(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewCppWrapper(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewDestructor(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewHelper(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewHider(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewMissingFunc(Message* node, SCBase* name_space, Message* ErrPlace);

SCModule* SC_Func__NewProtoTypeSub(Message* node, SCBase* parent, Message* ErrPlace, JB_String* ForInterface);

SCFunction* SC_Mod_NewModuleFunc(SCModule* self, Message* src);

bool SC_Msg_OppExpand(Message* self);

void SC_Refs__DeclInit(Message* dcl, SCFunction* fn, bool IsJustAnArg);

void SC_SC_API__NewAPI(Message* api, JB_String* part, SCBase* parent, JB_String* proj);

SCObject* SC_TypeOfBra(Message* Exp, SCBase* name_space, Message* side);

int SC_VM_Builder__GenAcc(Message* line, int bit_pos, int pname);

SCModule* SC_Beh__NewVirtualSub(Message* node, SCClass* cls, Message* ErrPlace);

void SC_Class_NewClassNew(SCClass* self, SCFunction* con, Message* src, int ExtraCode);

void SC_Comp__RefConstructors();

SCBase* SC_Func__NeuSyx(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewProtoType(Message* node, SCBase* name_space, Message* ErrPlace);

SCBase* SC_Func__NewRender(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Func__Tran_OneIsa(Message* isa_f, Message* arg, SCBase* space);

void SC_Msg_Clean(Message* self, bool erl);

bool SC_Msg_InitRootDecl(Message* self, Message* before, SCBase* name_space);

void SC_Refs__RC_DeclArg(SCDecl* AR, SCFunction* fn);

void SC_SC_API__DelayedClassAPI(Message* node, JB_String* proj);

SCObject* SC_TypeOfExprModulesOK(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfFuncSub(Message* exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfThg(Message* Exp, SCBase* name_space, Message* side);

void SC_VM_Builder__GenerateOne(Message* form_msg, int f);

SCBase* SC_AC__GetScope(Message* orig, int* types);

void SC_Func_AnalyseRefs(SCFunction* self, Array* list);

void SC_Func__Tran_Isa(Message* S, SCBase* p);

Macro* SC_Macro_clean(Macro* self);

void SC_Mod_DelayedInitFuncTransform(SCModule* self);

SCObject* SC_Msg_DotSpace(Message* self, SCBase* name_space);

Message* SC_Str_ParseClean(JB_String* self);

SCObject* SC_TypeOfFunc(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfQues(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfSyx(Message* Exp, SCBase* name_space, Message* side);

void SC_VM_Builder__GenerateForms(Message* forms);

Message* SC_AC__AutoComplete(Message* ff, JB_String* name, JB_String* Purpose);

Message* SC_Base_CollectString(SCBase* self, JB_String* s);

void SC_Base_CreateNameDict(SCBase* self, Message* FuncName, Array* NameList);

SCFunction* SC_Beh__MakeVirtualCaller(SCModule* Mod, SCClass* Cls, Message* ErrPlace);

void SC_Class_CreateAlloc(SCClass* self, JB_String* ParseThing, int Extra);

SCFunction* SC_Class_CreateEmptyFunc(SCClass* self, JB_String* fname, JB_String* cpp_name);

int SC_Class__InitCode_();

SCFunction* SC_Comp__CreateFuncFromSource(JB_String* Src);

void SC_Comp__DoRefAnalysis();

void SC_Comp__PostInitCodeCall();

void SC_Func__Tran_IfSub(Message* node, SCBase* name_space);

void SC_Func__Tran_While(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Iter_Check(SCIterator* self, SCClass* cls);

void SC_Mod_LoadInitFuncSub(SCModule* self, Message* init, JB_String* name);

int SC_Msg_MainOneArg(Message* self, Message* arg, int i, int found);

Message* SC_SCFile_ASTSub(SCFile* self);

Message* SC_Str_ParseCleanWipe(JB_String* self);

SCObject* SC_TypeOfDot(Message* Exp, SCBase* name_space, Message* side);

bool SC_VM_Builder__BuildFiles();

Message* SC_AC__Jump(Message* cmd);

Message* SC_AC__TmpAutoComplete(Message* f, JB_String* name, JB_String* type);

void SC_Base_CollectConstantsSub(SCBase* self, Message* ch);

SCBase* SC_Beh__NewVirtual(Message* node, SCBase* name_space, Message* ErrPlace);

void SC_Class_CheckIterator(SCClass* self);

SCFunction* SC_Class_CreateAutoConstructor(SCClass* self);

SCFunction* SC_Class_FindAllocFunc(SCClass* self, JB_String* fname, bool DontCreate);

bool SC_Comp__InitBasicFuncs();

Message* SC_Comp__MakeMainFunc();

int SC_Func__InitCode_();

void SC_Func__Tran_ForSub(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_If(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Mod_LoadInitFunc(SCModule* self);

void SC_Msg_InsertMainArgs(Message* self, Message* prms);

Message* SC_SCFile_AST(SCFile* self);

Message* SC_SCFile_Orig(SCFile* self);

SCObject* SC_TypeOfAccess(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfFuncPointer(Message* Exp, SCBase* name_space, Message* side);

SCObject* SC_TypeOfSDot(Message* Exp, SCBase* name_space, Message* side);

void SC_VM_Builder__MakeTheVM();

int JB_InitCode_();

SCFunction* SC_AC__GetFunc2(Message* cmd, SCFile* myfile, int f, int n);

Message* SC_AC__MainActAutoComplete(Message* thg, JB_String* str, Message* cmd);

void SC_Base_CollectOneConstants(SCBase* self, Message* ch);

void SC_Base_ImportFile(SCBase* self, SCFile* file);

SCFunction* SC_Class_CreateEmptyConstructors(SCClass* self);

bool SC_Comp__AddMain(int mark);

void SC_Comp__LoadInitsAndMore();

void SC_Func__Tran_Debugger(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_For(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Ifn(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Func__Tran_Once(SCFunction* fn, Message* node, SCBase* name_space);

void SC_Imp_LoadConf(SCImport* self, SCFile* scf);

void SC_Imp_PrepareAll(SCImport* self);

void SC_Imp_ReloadImports(SCImport* self, SCFile* index);

Message* SC_Msg_MainFix(Message* self);

Message* SC_SCFile_GetMsg(SCFile* self, int pos, bool needname);

SCObject* SC_TypeOfBRel(Message* Exp, SCBase* name_space, Message* side);

Message* SC_AC__Backup_Define(SCFile* myfile, int f, Message* thg, JB_String* purpose);

void SC_Class_CreateConstructors(SCClass* self);

void SC_Comp__CollectConstants();

void SC_Comp__ImportAST();

int SC_Func__Init_();

SCBase* SC_Func__NeuMain(Message* node, SCBase* name_space, Message* ErrPlace);

SCImport* SC_Imp__ImportPath(JB_String* path, JB_File* f, int ImportDepth, bool Builtin);

void SC_Msg_mainfix2(Message* self);

void SC_Class_LoadConstructorsAndAllocators(SCClass* self);

void SC_Comp__ImportLibs();

void SC_Comp__ImportProj();

bool SC_Func_UpdateSourceSub(SCFunction* self, Message* src);

SCBase* SC_Func__NeuLibrary(Message* node, SCBase* name_space, Message* ErrPlace);

int JB_Init_();

void SC_Comp__ImportAll();

bool SC_Func_Update_Source(SCFunction* self, int start, JB_String* text, SCFile* myfile, SCObject* orig);

SCFunction* SC_AC__GetFunc(Message* cmd, SCFile* myfile, int ff, int n);

bool SC_Comp__CompileAll();

Message* SC_AC__MainAct(Message* cmd, SCFile* my_file);

void SC_Comp__CompileTime();

Message* SC_AC__DoCmd(Message* cmd, Message* arg);

bool SC_Comp__TryVariousStartModes();

Message* SC_AC__CmdResponse(Message* cmd, Message* arg);

bool SC_AC__CmdWrap(Message* arg);

void SC_AC__PerryTalk(SpdProcess* perry);

bool SC_AC__EnterAutoComplete();

bool SC_Comp__EnterCompile();

void SC_Comp__Main();

ErrorInt JB_Main();


//// HEADER Inlines.h
inline SCDecl* SC_TypeOfSwiz(Message* exp, SCBase* name_space, Message* side, SCDecl* class_Space) {
	int W = SC_Class_NumericCount(class_Space->Type);
	if ((W > 1) and (!JB_Ring_HasChildren(((Message*)JB_Ring_Last(exp))))) {
		int swz = SC_Str_IsSwizzle(exp->Name, W);
		if (swz) {
			return SC_TypeOfSwizzle(exp, class_Space, name_space, side, swz);
		}
	}
	return nil;
}

inline JB_String* JB_Tk__SyntaxAccess(int s, int e, Syntax f) {
	return (JB__Tk_Splitter)(s, e, f);
}

inline bool JB_int_OperatorInRange(int self, int d) {
	if (d > 0) {
		return (((uint)self) < ((uint)d));
	}
	return false;
}

inline bool JB_int64_OperatorInRange(int64 self, int64 d) {
	return (((uint64)self) < ((uint64)d));
}

inline int JB_uint64_LELength(uint64 self) {
	return (JB_int_OperatorMax(JB_Int_Log2(((int)self)), 0)) >> 3;
}

inline bool JB_ErrorInt_SyntaxCast(ErrorInt self) {
	return self == 0;
}

inline bool JB_Err2_SyntaxCast(ErrorInt2 self) {
	return (JB_ivec2_Equals2(self, ivec2{0, 0}, false));
}

inline bool JB_ErrorMarker_SyntaxCast(ErrorMarker self) {
	return JB_StdErr->ErrorCount == self;
}

inline bool JB_Ind_SyntaxCast(Ind self) {
	return self >= 0;
}

inline IR* SC_flat_AddASM(ASMFuncState* self, Message* dbg, int SM, int a, int b, int c, int d) {
	IR* rz = nil;
	rz = SC_flat_RequestOp2(self, SM);
	rz->r[0] = a;
	rz->r[1] = b;
	rz->r[2] = c;
	rz->r[3] = d;
	(SC_IR_DebugSet(rz, dbg));
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

inline void SC_nil_SetAllNil(ArchonPurger* self, NilRecord Dest) {
	(*self->Neel) = (Dest & self->Realnesses);
}

inline NilState SC_nil_SetNilness(ArchonPurger* self, SCDecl* d, NilState New) {
	NilRecorder* P = ((NilRecorder*)(self->Neel));
	(SC_NRC_SyntaxCallSet((P), d->NilReg, New));
	return New;
}

inline NilRecord SC_nil_Value(ArchonPurger* self) {
	return (*self->Neel);
}

inline void SC_nil__DeclKill() {
	if ((!SC_nil_NestDepth((&SC__nil_T)))) {
		SC__nil_T.RootReturned = true;
	}
	SC_nil_SetAllNil((&SC__nil_T), kSC__NilState_Basic);
}

inline NilRecord SC_nil__EndBlock() {
	NilRecord rz = 0;
	rz = SC_nil__Value();
	SC_nil_SetAllNil((&SC__nil_T), kSC__NilState_Basic);
	return rz;
}

inline NilState SC_nil__Jump(Message* msg, NilCheckMode Test) {
	return (SC__nil_NilSyxes[msg->Func])(msg, Test);
}

inline NilRecord SC_nil__Value() {
	return SC_nil_Value((&SC__nil_T));
}

inline int SC_Reg_ToInt(AsmReg* self) {
	return self->Reg;
}

inline bool JB_FastBuff_AppendByte(FastBuff* self, byte v) {
	(*self->Curr++) = v;
	return self->Curr >= self->End;
}

inline JB_String* JB_Object___Render__(JB_Object* self, FastString* fs_in) {
	Object_Behaviour* Table = ((Object_Behaviour*)JB_ObjClassBehaviours(self));
	return (Table->render)(self, fs_in);
}

inline void SC_CppRefs_Constructor(CppRefs* self, Message* s) {
	self->DisturbParams = 0;
	self->Owned = false;
	Array* _tmPf0 = JB_Array__New0();
	self->Disturbs = JB_Incr(_tmPf0);
	if (s) {
		SC_CppRefs_Read(self, s);
	}
}

inline void SC_Cpp_Constructor(Cpp_Export* self) {
	Array* _tmPf0 = JB_Incr((JB_Array__New0()));
	self->Outputs_cpp = JB_Incr(_tmPf0);
	JB_Decr(_tmPf0);
	Array* _tmPf1 = JB_Incr((JB_Array__New0()));
	self->Outputs_h = JB_Incr(_tmPf1);
	JB_Decr(_tmPf1);
	FastStringCpp* _tmPf7 = SC_FastStringCpp__New(JB_LUB[0]);
	self->T = JB_Incr(_tmPf7);
	FastStringCpp* _tmPf6 = SC_Cpp_StreamChild(self, JB_LUB[1043]);
	self->AllTypes = JB_Incr(_tmPf6);
	FastStringCpp* _tmPf5 = SC_Cpp_StreamChild(self, JB_LUB[1044]);
	self->TypesProj = JB_Incr(_tmPf5);
	FastStringCpp* _tmPf4 = SC_Cpp_StreamChild(self, JB_LUB[1045]);
	self->HeaderProj = JB_Incr(_tmPf4);
	FastStringCpp* _tmPf3 = SC_Cpp_StreamChild(self, JB_LUB[1046]);
	self->Inlines = JB_Incr(_tmPf3);
	FastStringCpp* _tmPf2 = SC_Cpp_StreamChild(self, JB_LUB[1047]);
	self->ModuleProperties = JB_Incr(_tmPf2);
	SC_Cpp__Init();
}

inline void JB_Wrap_ConstructorInt(DTWrap* self, int64 v) {
	self->DeathAction = 0;
	self->DataType = kJB__TC_s64;
	self->PrivValue = v;
}

inline void JB_Wrap_Constructor(DTWrap* self, _voidptr p) {
	self->DeathAction = 0;
	self->DataType = kJB__TC_UnusedType;
	self->PrivValue = ((int64)p);
}

inline bool JB_DictionaryReader_SyntaxCast(DictionaryReader* self) {
	return JB_Nav_MoveNext(self);
}

inline void JB_Rec_Constructor(JB_ErrorReceiver* self) {
	self->_LogFunc = nil;
	self->_LogObj = nil;
	self->ErrorCount = 0;
	self->ProblemCount = 0;
	self->WarnCount = 0;
	self->LowerErrorsTo = 0;
	self->BlockErrors = false;
	JB_StringC* _tmPf1 = JB_LUB[0];
	self->Source = JB_Incr(_tmPf1);
	JB_Error* _tmPf0 = JB_Err__NewNothing();
	self->Errors = JB_Incr(_tmPf0);
	self->MaxErrors = 512;
	self->MaxProblems = 16;
	JB__API_NilHappened = nil;
}

inline JB_String* JB_FS_SyntaxCast(FastString* self) {
	return JB_FS_GetResult(self);
}

inline void JB_Flow_Constructor(FlowControl* self) {
	self->Buff = ((FastBuff){});
	self->ReadInput = nil;
	self->Write = nil;
	//;
	JB_FastBuff_NeedAlloc((&self->Buff), 1048576);
	FastString* _tmPf0 = JB_FS__New();
	self->Excuse = JB_Incr(_tmPf0);
}

inline void SC_Instruction_Constructor(Instruction* self, JB_String* FormName, JB_String* name, int pos) {
	self->aType = 0;
	self->FormName = JB_Incr(FormName);
	self->OpCode = pos;
	self->Name = JB_Incr(name);
	xC2xB5Form* _tmPf0 = SC_xC2xB5Form__Needform(self->FormName);
	self->Sizes = JB_Incr(_tmPf0);
	if (self->Sizes) {
		self->PCount = self->Sizes->Count;
	}
}

inline void JB_Lk_Constructor(LeakTester* self, JB_String* name) {
	self->MemUsedStart = JB_MemCount();
	self->Name = JB_Incr(name);
	JB_Mem_Mark();
}

inline void SC_Macro_ConstructorStr(Macro* self, JB_String* s) {
	self->Cleaned = false;
	self->_Parsed = nil;
	self->input = JB_Incr(s);
}

inline void SC_Macro_ConstructorMsg(Macro* self, Message* s) {
	self->Cleaned = false;
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->input = JB_Incr(_tmPf0);
	self->_Parsed = JB_Incr(s);
}

inline void JB_Mrap_ConstructorPtr(MWrap* self, int ItemCount, uint ItemSize, byte* ptr, byte DeathAction) {
	self->DataType = kJB__TC_UnusedType;
	self->DeathAction = 0;
	self->ItemSize = ItemSize;
	self->Length = 0;
	self->Capacity = ItemCount;
	self->_Ptr = ptr;
}

inline void SC_NilTest_Constructor(NilTest* self) {
	self->V = 0;
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->V2 = JB_Incr(_tmPf0);
	self->V4 = ((byte*)((&SC__NilTest_NilTestByte)));
	self->V3 = ((byte*)0);
}

inline bool SC_NilTest_SyntaxCast(NilTest* self) {
	JB_Incr(self);
	bool _tmPf0 = (self != nil) and JB_Str_Exists(self->V2);
	JB_Decr(self);
	return _tmPf0;
}

inline void SC_Imp_Constructor(SCImport* self, JB_File* F, bool Builtin) {
	JB_Incr(F);
	self->IsSTDLib = false;
	self->Depth = 0;
	Array* _tmPf3 = JB_Array__New0();
	self->Files = JB_Incr(_tmPf3);
	Dictionary* _tmPf2 = JB_Dict__New();
	self->Resources = JB_Incr(_tmPf2);
	self->BlindCast = JB_Ternary(Builtin, 0, ((int)kJB__ErrorSeverity_Error));
	JB_MemoryLayer* _tmPf1 = JB_Mem_CreateLayer((&SCDeclData), self);
	self->DeclLayer = JB_Incr(_tmPf1);
	SCBase* _tmPf0 = JB_Incr(SC_Mod__NeuModule(nil, SC__Comp_program, nil));
	SCModule* M = JB_Incr(((SCModule*)_tmPf0));
	JB_Decr(_tmPf0);
	self->Mod = JB_Incr(M);
	M->Project = self;
	M->IsImport = true;
	if (F != nil) {
		JB_SetRef(M->Name, JB_Str_Name(F));
		SC__Imp_Recent = JB_int64_OperatorMax(SC__Imp_Recent, JB_File_Modified(F));
	}
	JB_Decr(M);
	JB_Decr(F);
}

inline void JB_NR_Constructor(SCNodeRenamer* self) {
	JB_StringC* _tmPf1 = JB_LUB[0];
	self->Name = JB_Incr(_tmPf1);
	Array* _tmPf0 = JB_Array__New0();
	self->Nodes = JB_Incr(_tmPf0);
}

inline void JB_SCObject_Constructor(SCObject* self) {
	self->LinkFrom = nil;
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->Name = JB_Incr(_tmPf0);
	self->Source = nil;
	self->TableId = 0;
	self->NoAutoComplete = 0;
	self->AllocSource = 0;
}

inline void SC_Opp_Constructor(SCOperator* self, fn_OpASM ASM) {
	self->Score = 0;
	JB_StringC* _tmPf3 = JB_LUB[0];
	self->Name = JB_Incr(_tmPf3);
	JB_StringC* _tmPf2 = JB_LUB[0];
	self->CompOp = JB_Incr(_tmPf2);
	JB_StringC* _tmPf1 = JB_LUB[0];
	self->CompParam = JB_Incr(_tmPf1);
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->FuncName = JB_Incr(_tmPf0);
	self->IsCaseAware = false;
	self->IsCompare = false;
	self->IsEquals = false;
	self->IsNilTest = false;
	self->IsExactlyEquals = false;
	self->IsSet = false;
	self->AsBit = false;
	self->IsCustom = false;
	self->DoesntNeedExtraBits = false;
	self->MakesSigned = false;
	self->IsAndOr = 0;
	self->ASM = ASM;
}

inline void SC_PA_Constructor(SCParamArray* self, Message* exp) {
	self->Cls = nil;
	self->Size = 0;
	self->IsAssigns = false;
	self->HasProperParams = false;
	self->IsNotModule = false;
	self->IsSelf = false;
	self->IsSuper = false;
	self->Found = false;
	self->Exp = exp;
	self->IsDot = ((JB_Msg_EqualsSyx(exp, JB_SyxDot, false)));
	self->IsAddress = (((bool)exp) and SC_Msg_OperatorIsBRel(SC_Msg_NiceParent(exp), JB_LUB[354]));
	self->ErrCount = JB_StdErr->ErrorCount;
}

inline bool SC_PA_SyntaxCast(SCParamArray* self) {
	JB_Incr(self);
	bool _tmPf0 = (self != nil) and self->HasProperParams;
	JB_Decr(self);
	return _tmPf0;
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

inline void JB_Sel_Constructor(Selector* self, Selector* Next, Selector** Place, JB_String* name) {
	self->ID = 0;
	self->Name = JB_Incr(name);
	self->Next = JB_Incr(Next);
	JB_SetRef((*Place), self);
}

inline JB_StringC* JB_Str_CastZero(JB_String* self) {
	return JB_Str_MakeC(self);
}

inline void JB_FI_Constructor(StringFields* self, JB_String* Source, byte Sep) {
	self->Data = JB_Incr(Source);
	self->Sep = Sep;
}

inline void JB_SS_Constructor(StringReader* self, JB_String* Data) {
	self->Data = ((FastBuff){});
	self->File = nil;
	self->UserObj = nil;
	self->ChunkSize = 0;
	self->StartFrom = 0;
	(JB_FastBuff_ReadFromSet((&self->Data), Data));
	self->Length = JB_Str_Length(Data);
	self->_NoMoreChunks = true;
}

inline void JB_Fn_Constructor(SyntaxObj* self, fpMsgRender msg, JB_String* name, int ID) {
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->LongName = JB_Incr(_tmPf0);
	self->RenderAddr = msg;
	self->Name = JB_Incr(name);
	self->ID = ((Syntax)ID);
	self->ExportAddr = JB_Msg_Dummy;
}

inline void JB_autoitem_ConstructorAuto(autoitem* self, JB_String* Sort, JB_String* Insert, SCObject* Value, JB_String* Display, bool Exact, int type) {
	self->Sort = JB_Incr(Sort);
	self->Insert = JB_Incr(Insert);
	self->Value = JB_Incr(Value);
	self->Display = JB_Incr(Display);
	self->Exact = Exact;
	self->type = type;
}

inline void SC_xC2xB5Form_ConstructorWithStr(xC2xB5Form* self, JB_String* data) {
	self->Count = 0;
	self->Varies = false;
	self->Name = JB_Incr(data);
	{
		byte* _Startf0 = JB_Str_Address(data);
		byte* _Endf1 = _Startf0 + JB_Str_Length(data);
		while (_Startf0 < _Endf1) {
			byte param = _Startf0[0];
			SC_xC2xB5Form_LoadParam(self, JB_Str__Byte(param), nil);
			_Startf0++;
		};
	}
	;
	SC_xC2xB5Form_Finish(self);
	self->Index = (++SC__xC2xB5Form_Count);
}

inline void SC_xC2xB5Form_ConstructorWithMsg(xC2xB5Form* self, Message* tmp) {
	self->Count = 0;
	self->Varies = false;
	JB_String* _tmPf3 = tmp->Name;
	self->Name = JB_Incr(_tmPf3);
	{
		Message* _LoopSrcf2 = JB_Msg_Last(tmp, JB_SyxArg);
		Message* line = ((Message*)JB_Ring_First(_LoopSrcf2));
		while (line) {
			Message* _Nf1 = ((Message*)JB_Ring_NextSib(line));
			Message* f = JB_Msg_NeedFirst(line);
			SC_xC2xB5Form_LoadParam(self, JB_Msg_Name(f), f);
			line = _Nf1;
		};
		;
	}
	;
	SC_xC2xB5Form_Finish(self);
	self->Index = (++SC__xC2xB5Form_Count);
}

inline void SC_ASMFunc_Constructor(ASMFunc* self, SCFunction* fn) {
	self->Start = 0;
	self->Length = 0;
	self->OK = false;
	self->Fn = JB_Incr(fn);
	JB_SetRef(fn->ASM, self);
}

inline bool JB_Array_SyntaxCast(Array* self) {
	return JB_Array_Size(self) > 0;
}

inline void SC_FastStringCpp_Constructor(FastStringCpp* self, JB_String* name) {
	JB_FS_Constructor(self);
	self->Cpp_Name = JB_Incr(name);
}

inline bool JB_File_SyntaxCast(JB_File* self) {
	JB_Incr(self);
	bool _tmPf0 = self != nil;
	JB_Decr(self);
	return _tmPf0;
}

inline void JB_bin_Constructor(FastString* self, Syntax type, JB_String* data) {
	JB_FS_Constructor(self);
	JB_FS_AppendString(self, JB__JbinHeader);
	JB_bin_Enter(self, type, data);
}

inline void JB_bin_Constructor0(FastString* self, int n) {
	JB_FS_Constructor(self);
	if (n) {
		debugger;
	}
}

inline void SC_MaterialsLol_Constructor(MaterialsLol* self, Selector* Next, Selector** Place, JB_String* name1) {
	JB_Sel_Constructor(self, Next, Place, name1);
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->oof = JB_Incr(_tmPf0);
}

inline void SC_Base_Constructor0(SCBase* self) {
	JB_SCObject_Constructor(self);
	self->BaseInfo = 0;
	self->Access = nil;
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->ExportName = JB_Incr(_tmPf0);
	self->Parent = nil;
	self->CurrReacher = nil;
	self->Project = SC__Imp_Curr;
	(SC_Base_IsVisibleSet(self, SC__Base_CurrVisibility));
}

inline void SC_Base_ConstructorStr(SCBase* self, JB_String* Name, bool Dummy) {
	JB_SCObject_Constructor(self);
	self->BaseInfo = 0;
	self->Access = nil;
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->ExportName = JB_Incr(_tmPf0);
	self->Parent = nil;
	self->CurrReacher = nil;
	self->Project = nil;
	self->Name = JB_Incr(Name);
}

inline void SC_Base_ConstructorMsg(SCBase* self, Message* node) {
	JB_SCObject_Constructor(self);
	self->BaseInfo = 0;
	self->Access = nil;
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->ExportName = JB_Incr(_tmPf0);
	self->Parent = nil;
	self->CurrReacher = nil;
	self->Source = JB_Incr(node);
	(SC_Base_IsVisibleSet(self, SC__Base_CurrVisibility));
	self->Project = SC__Imp_Curr;
}

inline void SC_Decl_Constructor(SCDecl* self, SCClass* type) {
	JB_SCObject_Constructor(self);
	self->C_Array = 0;
	self->HiderFunc = nil;
	self->IsLookupOnly = nil;
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->StringData = JB_Incr(_tmPf0);
	self->Internal = nil;
	self->Contains = nil;
	self->Default = nil;
	self->DReg = ((AsmReg){});
	self->PointerCount = 0;
	self->NilReg = 0;
	self->NilAllocDepth = 0;
	self->Special = 0;
	self->Type = JB_Incr(type);
	self->NilDeclared = kSC__NilState_Either;
	self->Info = kSC__SCDeclInfo_altered;
}

inline bool SC_Decl_IsUnknownParam(SCDecl* self) {
	return ((!SC_Decl_NilStated(self))) and (SC_Decl_SyntaxIs(self, kSC__SCDeclInfo_param));
}

inline void SC_Iter_Constructor(SCIterator* self, SCClass* parent, Message* msg) {
	JB_SCObject_Constructor(self);
	self->ValueRenamer = nil;
	self->Parent = JB_Incr(parent);
	Message* thg = JB_Incr(((Message*)JB_Ring_First(msg)));
	JB_String* x = JB_Incr(JB_Msg_Name(thg));
	JB_Decr(thg);
	if ((!JB_Str_Exists(x))) {
		JB_SetRef(x, JB_LUB[1486]);
	}
	self->Name = JB_Incr(x);
	JB_Decr(x);
	ErrorMarker M = JB_Rec_Mark(JB_StdErr);
	Message* src = JB_Incr(JB_Msg_Last(msg, JB_SyxArg));
	if ((!src)) {
		JB_Msg_SyntaxExpect(msg, nil);
	}
	self->Source = JB_Incr(src);
	Message* _tmPf0 = JB_Incr(JB_Msg_FindSyxName(self->Source, JB_SyxTmp, JB_LUB[428], false));
	if ((!_tmPf0)) {
		JB_Msg_SyntaxExpect(msg, JB_LUB[1487]);
	}
	self->WhileLoop = JB_Incr(_tmPf0);
	JB_Decr(_tmPf0);
	Message* WhileArg = JB_Incr(JB_Msg_FindSyx(self->WhileLoop, JB_SyxArg));
	if ((!WhileArg)) {
		JB_Msg_SyntaxExpect(self->WhileLoop, JB_LUB[1488]);
	}
	Message* _tmPf2 = JB_Incr(((Message*)JB_Ring_NextSib(WhileArg)));
	Message* _tmPf4 = ((Message*)JB_Ring_First(_tmPf2));
	JB_Decr(_tmPf2);
	self->LoopEndCond = JB_Incr(_tmPf4);
	Message* Cond = JB_Incr(((Message*)JB_Ring_First(self->WhileLoop)));
	if (Cond == WhileArg) {
		JB_SetRef(Cond, (JB_Syx_Msg(JB_SyxThg, JB_LUB[107])));
	}
	 else if ((bool)Cond) {
		JB_SetRef(Cond, SC_Msg_NeedBra(Cond));
	}
	self->LoopCond = JB_Incr(Cond);
	JB_Decr(Cond);
	Message* w = nil;
	if (WhileArg) {
		JB_SetRef(w, JB_Msg_FindNested(WhileArg, JB_SyxTmp, JB_LUB[1489], false));
		if ((!w)) {
			JB_Msg_SyntaxExpect(WhileArg, JB_LUB[1490]);
		}
	}
	JB_Decr(WhileArg);
	self->Yield = JB_Incr(w);
	JB_Decr(w);
	Message* _tmPf1 = JB_Incr(((Message*)JB_Ring_First(self->Yield)));
	if ((!_tmPf1)) {
		JB_Msg_SyntaxExpect(self->Yield, JB_LUB[1491]);
	}
	self->Value = JB_Incr(_tmPf1);
	JB_Decr(_tmPf1);
	Message* i = JB_Incr(((Message*)JB_Tree_Second(self->Yield)));
	if (i) {
		JB_Msg_Expect(i, JB_SyxBra, nil);
		JB_SetRef(i, ((Message*)JB_Ring_First(i)));
	}
	self->Index = JB_Incr(i);
	JB_Decr(i);
	SCNodeRenamer* sn = JB_Incr(JB_NR__New());
	self->selfs = JB_Incr(sn);
	if (src) {
		SC_NR_CollectSelfs(sn, src);
	}
	JB_Decr(sn);
	Array* _tmPf3 = SC_Iter_Uniqueify(self, src);
	JB_Decr(src);
	self->Names = JB_Incr(_tmPf3);
	self->OK = JB_ErrorMarker_SyntaxCast(M);
}

inline void SC_SavingTest_Constructor(SavingTest* self, int n) {
	JB_Sav_Constructor(self);
	JB_String* _tmPf0 = JB_Incr(JB_int_RenderFS(n, nil));
	JB_String* _tmPf1 = JB_Str_OperatorPlus(JB_LUB[1494], _tmPf0);
	JB_Decr(_tmPf0);
	self->Name = JB_Incr(_tmPf1);
	self->Value = (1000 + n);
}

inline bool JB_Safe_SyntaxCast(JB_String* self) {
	return JB_Str_IsOK(self);
}

inline _cstring JB_Str_SyntaxCast(JB_StringC* self) {
	return JB_Str_CString(self);
}

inline void SC_Msg_AddValue(Message* self, SCFunction* f) {
	if ((!JB_Ring_HasChildCount(self, 2))) {
		if (true) {
			MessagePosition _usingf0 = JB_Msg_SyntaxUsing(f->Source);
			JB_Tree_SyntaxAppend(self, (JB_Syx_Msg(JB_SyxThg, JB_LUB[1498])));
			JB_MsgPos_SyntaxUsingComplete((&_usingf0));
			JB_MsgPos_Destructor((&_usingf0));
		}
	}
}

inline void JB_Msg_ConstructorCopy(Message* self, Message* other) {
	JB_Ring_Constructor0(self);
	self->Position = other->Position;
	JB_String* _tmPf1 = other->Name;
	self->Name = JB_Incr(_tmPf1);
	self->Func = other->Func;
	JB_Object* _tmPf0 = other->Obj;
	self->Obj = JB_Incr(_tmPf0);
	self->Indent = other->Indent;
	self->Flags = (other->Flags | JB__Tk_Using.Flags);
	self->RangeLength = other->RangeLength;
	self->Tag = other->Tag;
}

inline void JB_Msg_ConstructorEmpty(Message* self) {
	JB_Ring_Constructor0(self);
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->Name = JB_Incr(_tmPf0);
	self->Obj = nil;
	self->Indent = 0;
	self->Func = JB_SyxArg;
	self->Position = JB__Tk_Using.Position;
	self->Flags = JB__Tk_Using.Flags;
	self->RangeLength = JB__Tk_Using.Length;
	self->Tag = JB__Tk_Using.Tag;
}

inline void JB_Msg_ConstructorNormal(Message* self, Syntax Func, JB_String* Name) {
	JB_Ring_Constructor0(self);
	self->Obj = nil;
	self->Indent = 0;
	self->Name = JB_Incr(Name);
	self->Func = Func;
	self->Position = JB__Tk_Using.Position;
	self->Flags = JB__Tk_Using.Flags;
	self->RangeLength = JB__Tk_Using.Length;
	self->Tag = JB__Tk_Using.Tag;
}

inline void JB_Msg_ConstructorRange(Message* self, Message* Parent, Syntax Func, int BytePos, JB_String* name, int RangeLength) {
	JB_Ring_Constructor(self, Parent);
	self->Obj = nil;
	self->Indent = 0;
	self->Name = JB_Incr(name);
	self->Position = BytePos;
	self->Func = Func;
	self->RangeLength = RangeLength;
	self->Flags = JB__Tk_Using.Flags;
	self->Tag = JB__Tk_Using.Tag;
}

inline void SC_Arg_Constructor(SCArg* self, Message* node) {
	SC_Base_ConstructorMsg(self, node);
	self->ParentFunc = nil;
	self->TmpMovedOutFor = nil;
	self->IsClassArg = false;
	self->IsStatementExpr = false;
}

inline void SC_Beh_Constructor(SCBehaviour* self, SCClass* parent) {
	SC_Base_Constructor0(self);
	self->FuncTable = nil;
	Array* _tmPf1 = JB_Array__New0();
	self->WrapperFuncs = JB_Incr(_tmPf1);
	self->Project = parent->Project;
	self->Parent = parent;
	Dictionary* _tmPf0 = JB_Dict__New();
	self->Interfaces = JB_Incr(_tmPf0);
}

inline void SC_Class_Constructor(SCClass* self, Message* node, SCBase* parent, bool HasPtrs, SCModule* m) {
	SC_Base_Constructor0(self);
	self->Super = nil;
	self->Defawlt = nil;
	self->False = nil;
	Array* _tmPf7 = JB_Array__New0();
	self->Properties = JB_Incr(_tmPf7);
	Array* _tmPf6 = JB_Array__New0();
	self->Casts = JB_Incr(_tmPf6);
	Array* _tmPf5 = JB_Array__New0();
	self->Children = JB_Incr(_tmPf5);
	self->Contained = nil;
	self->Signed = nil;
	self->_NotConst = nil;
	self->FuncProto = nil;
	self->TheIsFunc = nil;
	self->ConstructorFunc = nil;
	self->DestructorFunc = nil;
	JB_StringC* _tmPf4 = JB_LUB[0];
	self->CppClass = JB_Incr(_tmPf4);
	self->ClassType = nil;
	self->IsModel = nil;
	self->Behaviour = nil;
	self->ProcessAs = nil;
	self->DowngradeTo = nil;
	self->DataTypeWrapper = nil;
	self->Size = 0;
	self->Depth = 0;
	self->StructContainerDepth = 0;
	self->MinOpt = 0;
	self->IsBehaviour = 0;
	self->IsWrapper = 0;
	self->IgnoreContainedSelf = false;
	self->HasCompareFunc = false;
	self->HasEqualsFunc = false;
	self->HasSubClass = false;
	self->NoEarlyFree = false;
	self->AutoGeneratedSavers = false;
	self->SavingCanSkip = false;
	self->TreatAsBaseType = false;
	self->HasNilChecker = 0;
	self->DefaultsToReal = false;
	self->IsRole = false;
	self->IsBuiltin = false;
	self->BaseType = 0;
	self->IsASM = false;
	self->IsNotNumeric = false;
	SC__Comp_stClasses++;
	JB_SetRef(node->Obj, self);
	JB_String* _tmPf3 = SC_Class__LoadClassName(node);
	self->Name = JB_Incr(_tmPf3);
	self->Source = JB_Incr(node);
	self->Modul = JB_Incr(m);
	self->Project = parent->Project;
	(SC_Base_IsVisibleSet(self, SC__Base_CurrVisibility));
	JB_StringC* _tmPf2 = JB_LUB[0];
	self->SaveAs = JB_Incr(_tmPf2);
	self->TypeInfo = kJB__TC_UnusedType;
	self->Banned = SC_Class_TestBanned(self);
	SCDecl* T = JB_Incr(SC_Decl__New(self));
	T->NilDeclared = (kSC__NilState_Real >> HasPtrs);
	self->TypeNormal = JB_Incr(T);
	SCDecl* _tmPf1 = SC_Decl_NilConstructor(T, kSC__NilState_Optional * HasPtrs);
	self->TypeOptional = JB_Incr(_tmPf1);
	SCDecl* _tmPf0 = SC_Decl_NilConstructor(T, kSC__NilState_Real * HasPtrs);
	self->TypeReal = JB_Incr(_tmPf0);
	if (JB_Msg_SyntaxEquals(node, JB_LUB[739], false)) {
		JB_SetRef(T, SC_Decl_GetAddress(T, kSC__DeclMode_FuncParam));
	}
	 else {
		JB_SetRef(T, SC_Decl_CopyDecl(T, false));
	}
	self->SelfDecl = JB_Incr(T);
	JB_SetRef(T->Name, JB_LUB[238]);
	(SC_Decl_SyntaxIsSet(T, kSC__SCDeclInfo_SelfImplicit, true));
	(SC_Decl_SyntaxIsntSet(T, kSC__SCDeclInfo_altered, true));
	JB_Decr(T);
}

inline void SC_SCFile_Constructor(SCFile* self, JB_File* f, SCImport* p) {
	JB_Incr(f);
	JB_String* _tmPf0 = JB_Incr(((JB_String*)JB_Ternary(f != nil, ((JB_String*)JB_File_Path(f)), ((JB_String*)JB_LUB[0]))));
	JB_File_Constructor(self, _tmPf0);
	JB_Decr(_tmPf0);
	JB_StringC* _tmPf3 = JB_LUB[0];
	self->ExportName = JB_Incr(_tmPf3);
	JB_StringC* _tmPf2 = JB_LUB[0];
	self->FData = JB_Incr(_tmPf2);
	self->OrigAST = nil;
	self->OrigDate = 0;
	self->filenum = 0;
	//;
	self->Proj = JB_Incr(p);
	self->IsInternal = (f == nil);
	Message* _tmPf1 = SC_SCFile_Start_AST(self);
	self->LiveAST = JB_Incr(_tmPf1);
	SC__Comp_stTotalFileCount = (SC__Comp_stTotalFileCount + self->IsInternal);
	SC__Imp_Recent = JB_int64_OperatorMax(SC__Imp_Recent, JB_File_Modified(f));
	JB_Decr(f);
}

inline void SC_Func_Constructor(SCFunction* self, Message* msg) {
	SC_Base_ConstructorMsg(self, msg);
	Array* _tmPf1 = JB_Array__New0();
	self->Args = JB_Incr(_tmPf1);
	self->Cls = nil;
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->Description = JB_Incr(_tmPf0);
	self->Refs = nil;
	self->LinkTo = nil;
	self->CounterPart = nil;
	self->NextFunc = nil;
	self->ASM = nil;
	self->ProtoDecl = nil;
	self->ProtoType = nil;
	self->ReturnType = nil;
	self->DepthFinder = nil;
	self->LinkDepth = 0;
	self->TmpCounter = 0;
	self->AllocCode = 0;
	self->MinOpt = 0;
	self->IsAssigns = 0;
	self->IsCppInBuilt = 0;
	self->BlindCasts = 0;
	self->FlowDisabled = false;
	self->IsExternalLib = false;
	self->IsWrapper = false;
	self->IsNilChecker = false;
	self->NilSelf = 0;
	self->IsInline = false;
	self->IsKiller = false;
	self->IsDisabled = false;
	self->IsAPI = false;
	self->NoRefCounts = false;
	self->AutoGeneratedSaver = false;
	self->IsMacro = false;
	self->HidesProperties = false;
	self->Badness = 0;
	if (msg) {
		SC__Comp_stFuncs++;
	}
}

inline void SC_Mod_Constructor(SCModule* self) {
	SC_Base_Constructor0(self);
	self->Cls = nil;
	self->InitVarsArg = nil;
	self->InitCodeArg = nil;
	JB_StringC* _tmPf2 = JB_LUB[0];
	self->CppPart = JB_Incr(_tmPf2);
	self->InitAfter = nil;
	JB_StringC* _tmPf1 = JB_LUB[0];
	self->SubsFrom = JB_Incr(_tmPf1);
	self->Grabbed = false;
	self->IsImport = false;
	self->Inited = false;
	self->IsRequiredInterface = false;
	CppRefs* _tmPf0 = SC_CppRefs__New(nil);
	self->DefaultRefs = JB_Incr(_tmPf0);
	if (SC_Base_IsVisible(self)) {
		debugger;
	}
}

inline void JB_sci_Constructor(SaverClassInfo* self, JB_Class* Cls, char* Data) {
	JB_Array_Constructor0(self);
	self->NextInfo = nil;
	self->Cls = Cls;
	self->Data = Data;
}

inline void JB_Proc_Constructor(SpdProcess* self, JB_String* path, SpdMainFn fn, JB_StringC* DebugName, Array* params, ProcessMode Mode) {
	JB_Sh_Constructor(self, path);
	self->DiedCount = 0;
	self->AlreadyWarnedDied = false;
	self->DeathLimit = 12;
	self->WeAreParent = ((!JB_Str_Equals(path, JB_LUB[0], false)) or (fn != nil));
	self->Params = JB_Incr(params);
	self->SubProcess = fn;
	self->Mode = Mode;
	FastString* _tmPf2 = ((FastString*)JB_Ternary(JB_ProcessMode_SyntaxIs(self->Mode, kJB__ProcessMode_capturestdout), JB_FS__New(), nil));
	self->Output = JB_Incr(_tmPf2);
	FastString* _tmPf1 = ((FastString*)JB_Ternary(JB_ProcessMode_SyntaxIs(self->Mode, kJB__ProcessMode_CaptureOrPrintErrors), JB_FS__New(), nil));
	self->ErrorOutput = JB_Incr(_tmPf1);
	FastString* _tmPf0 = JB_FS__New();
	self->Writer = JB_Incr(_tmPf0);
	self->Pico = ((PicoComms*)JB_Ternary(self->WeAreParent, JB_Pico__New(DebugName, 16), ((PicoComms*)JB_Pico__Parent())));
	self->_DebugName = JB_Incr(DebugName);
}

inline void JB_Err_Constructor(JB_Error* self, Message* node, JB_String* desc, ErrorSeverity level, JB_String* path) {
	JB_Msg_ConstructorEmpty(self);
	JB_StringC* _tmPf1 = JB_LUB[0];
	self->OriginalData = JB_Incr(_tmPf1);
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->StackTrace = JB_Incr(_tmPf0);
	self->ErrorFlags = 0;
	self->Position = -1;
	self->Node = JB_Incr(node);
	self->Severity = level;
	self->Progress = JB__Rec_Progress;
	self->Name = JB_Incr(desc);
	self->Path = JB_Incr(path);
	self->When = JB_Date__New0();
	self->Func = JB_SyxSStr;
	JB_Err_UpgradeWithNode(self);
}

inline void JB_Err_ConstructorNothing(JB_Error* self) {
	JB_Msg_ConstructorEmpty(self);
	JB_StringC* _tmPf2 = JB_LUB[0];
	self->Path = JB_Incr(_tmPf2);
	JB_StringC* _tmPf1 = JB_LUB[0];
	self->OriginalData = JB_Incr(_tmPf1);
	JB_StringC* _tmPf0 = JB_LUB[0];
	self->StackTrace = JB_Incr(_tmPf0);
	self->Progress = 0;
	self->Node = nil;
	self->ErrorFlags = 0;
	self->Position = -1;
	self->Severity = kJB__ErrorSeverity_OK;
	self->When = JB_Date__New0();
	self->Func = JB_SyxArg;
}


//// HEADER SyntaxConstants.h
#define kSyxNil 0
#define kSyxArg 1
#define kSyxEmb 2
#define kSyxType 3
#define kSyxDecl 4
#define kSyxTmp 5
#define kSyxOat 6
#define kSyxQues 7
#define kSyxCnj 8
#define kSyxOpp 9
#define kSyxThg 10
#define kSyxSheb 11
#define kSyxSCnj 12
#define kSyxSThg 13
#define kSyxNum 14
#define kSyxSStr 15
#define kSyxBack 16
#define kSyxChar 17
#define kSyxBin 18
#define kSyxStr 19
#define kSyxUnit 20
#define kSyxARel 21
#define kSyxName 22
#define kSyxDot 23
#define kSyxSDot 24
#define kSyxFunc 25
#define kSyxBRel 26
#define kSyxAdj 27
#define kSyxBadj 28
#define kSyxAcc 29
#define kSyxItem 30
#define kSyxBra 31
#define kSyxList 32
#define kSyxPrm 33
#define kSyxArr 34
#define kSyxFile 35
#define kSyxQuot 36
#define kSyxRel 37
#define kSyxERel 38
#define kSyxTRel 39
#define kSyxTril 40
#define kSyxpinn 41
#define kSyxbinn 42
#define kSyxAsk 43
#define kSyxYoda 44
#define kSyxSCom 45
#define kSyxMsg 46
#define kSyxTodo 47
#define kSyxurl 48
#define kSyxXAtt 49
#define kSyxXML 50
#define kSyxXPI 51
#define kSyxXCom 52
#define kSyxXCDT 53
#define kSyxXTxt 54
#define kSyxmax 55


}
#endif // __JB_H__
