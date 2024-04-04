

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

typedef int FileDes;

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

typedef byte MoveCode;

typedef u16 MsgParseFlags;

typedef uint NilCheckMode;

typedef byte NilReason;

typedef uint64 NilRecord;

typedef byte NilState;

typedef byte NumericLoss;

typedef u16 OpMode;

typedef int PID_Int;

typedef byte ProcessMode;

typedef uint SCBlockage;

typedef uint SCDeclInfo;

typedef int SCNodeFindMode;

typedef int SCNodeInfo;

typedef byte SCNodeType;

typedef int SizeInt;

typedef byte Syntax;

typedef byte TaskState;

typedef int TerminalColor;

typedef uint U24_8;

typedef uint64 __junktest_7__;

typedef vec4 mat2;

typedef u16 ASMParam;

typedef JSM ASM;

typedef Date HumanDate;

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

struct ContainerStruct2;

struct ContainerStruct;

struct ByteMap_Behaviour;

struct Charset_Behaviour;

struct CppRefs_Behaviour;

struct Cpp_Export_Behaviour;

struct DataObject_Behaviour;

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

struct MaterialsLol_Behaviour;

struct Process_Behaviour;

struct SCNamed_Behaviour;

struct SavingTest_Behaviour;

struct StringShared_Behaviour;

struct StringZeroTerminated_Behaviour;

struct list_Behaviour;

struct xC2xB5Func1_Behaviour;

struct MessageID_Behaviour;

struct Message_Behaviour;

struct SCDecl_Behaviour;

struct SCFile_Behaviour;

struct SCIterator_Behaviour;

struct SCNode_Behaviour;

struct SaverClassInfo_Behaviour;

struct SimpleGraph_Behaviour;

struct SpdProcess_Behaviour;

struct Task_Behaviour;

struct Error_Behaviour;

struct SCArg_Behaviour;

struct SCBehaviour_Behaviour;

struct SCClass_Behaviour;

struct SCFunction_Behaviour;

struct SCModule_Behaviour;

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

struct SCNamed;

struct SavingTest;

struct JB_String;

struct ASMFunc2;

struct JB_File;

struct JB_File;

struct Message;

struct MessageID;

struct SCDecl;

struct SCFile;

struct SCIterator;

struct SCNode;

struct SaverClassInfo;

struct SimpleGraph;

struct SpdProcess;

struct JB_Task;

struct JB_Error;

struct Message;

struct Message;

struct SCArg;

struct SCBehaviour;

struct SCClass;

struct SCFunction;

struct SCModule;

struct Message;

struct JB_Task;

struct LessThan3;

typedef ASM (*ASM_Encoder2)(IR* self);

typedef SCNode* (*FP_CollectFunc)(Message* node, SCNode* name_space, Message* ErrPlace);

typedef SCObject* (*FP_ExprResolver)(Message* Exp, SCNode* name_space, Message* side);

typedef NilState (*FP_NilTrackerFn)(Message* msg, NilCheckMode Test);

typedef Message* (*FP_ParseHandler)(int Start, Message* Parent);

typedef void (*FP_SaverLoadClass)(JB_Class* cls, char* Data);

typedef bool (*FP_ShellOption)(JB_String* Name, JB_String* Value, FastString* purpose);

typedef bool (*FP_SorterComparer)(JB_Object* a, JB_Object* b);

typedef bool (*FP_SorterComparerFn)(SCFunction* a, SCFunction* b);

typedef bool (*FP_SpdMainFn)(void* Obj, _cstring* args, PicoComms* Comms);

typedef JB_Object* (*TokenHandler_fp)(int Start, Message* parent);

typedef void (*FP_TranFunc)(SCFunction* fn, Message* node, SCNode* name_space);

typedef JB_String* (*__Message_CopyID__)(Message* self);

typedef void (*__Saveable_LoadProperties__)(Saveable* self, ObjectLoader* Loader);

typedef JB_String* (*__Object_Render__)(JB_Object* self, FastString* fs_in);

typedef void (*__Saveable_SaveCollect__)(Saveable* self, ObjectSaver* Saver);

typedef void (*__Saveable_SaveWrite__)(Saveable* self, ObjectSaver* Saver);

typedef bool (*__Message_TextSet__)(Message* self, int i, JB_String* v);

typedef JB_String* (*__Message_Text__)(Message* self, int i);

typedef bool (*autosort_fn)(autoitem* a, autoitem* b);

typedef void (*FP_fnErrorLogger)(JB_ErrorReceiver* self, JB_String* Data);

typedef JB_String* (*FP_fnIDGenerator)(int Start, int End, Syntax f);

typedef bool (*FP_fnPreReader)(SCFunction* self, Message* msg);

typedef AsmReg (*fn_OpASM)(ASMFuncState* self, AsmReg dest, AsmReg L, AsmReg R, Message* dbg);

typedef AsmReg (*fn_asm)(ASMFuncState* self, Message* exp, AsmReg Reg);

typedef void (*FP_fpDestructor)(JB_Object* self);

typedef void (*FP_fpMsgRender)(Message* self, FastString* fs);

typedef void (*FP_fpMsgRenderCpp)(Message* self, FastStringCpp* fs);

typedef bool (*Task_LessThan3_interface_prototype)(JB_Task* self, int i);

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

struct DataObject_Behaviour: Object_Behaviour {
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
	FP_fnErrorLogger _LogFunc;
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
	JB_String* Input;
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
	bool WarnUnusedFuncs;
	ErrorSeverity BlindCast;
	int Depth;
	JB_File* Where;
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
	Array* LinkFrom;
	Message* Source;
	byte NoAutoComplete;
	byte AllocSource;
	uint LinkedFrom;
	SCNodeInfo NodeInfo;
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
	OpMode Kind;
	SCOperator* Opposite;
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
	bool AllowSelfToConstructor;
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
	FP_fpMsgRender RenderAddr;
	FP_fpMsgRender ExportAddr;
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

struct SCNamed_Behaviour: SCObject_Behaviour {
};

JBClass ( SCNamed , SCObject , 
	JB_String* Name;
	JB_String* ExportName;
);

struct SavingTest_Behaviour: Saveable_Behaviour {
};

JBClass ( SavingTest , Saveable , 
	JB_String* Name;
	int Value;
	int ABC[1];
);

struct StringShared_Behaviour: String_Behaviour {
};

struct StringZeroTerminated_Behaviour: String_Behaviour {
};

struct list_Behaviour: Saveable_Behaviour {
};

struct xC2xB5Func1_Behaviour: Memory_Behaviour {
};

JBClass ( ASMFunc2 , MWrap , 
);

struct Message_Behaviour: list_Behaviour {
	__Message_CopyID__ copyid;
	__Message_Text__ text;
	__Message_TextSet__ textset;
};

JBClass ( Message , JB_List , 
	JB_String* Name;
	JB_Object* Obj;
	Syntax Func;
	byte Indent;
	u16 RangeLength;
	MsgParseFlags Flags;
	u16 Tag;
);

struct MessageID_Behaviour: StringShared_Behaviour {
};

JBClass ( MessageID , JB_StringShared , 
	JB_Object* Obj;
	uint64 ID;
	Syntax Func;
);

struct SCDecl_Behaviour: SCNamed_Behaviour {
};

JBClass ( SCDecl , SCNamed , 
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
);

struct SCFile_Behaviour: File_Behaviour {
};

JBClass ( SCFile , JB_File , 
	JB_String* ExportName;
	SCImport* Proj;
	JB_String* FData;
	Message* LiveAST;
	Message* OrigAST;
	u16 filenum;
	bool IsInternal;
);

struct SCIterator_Behaviour: SCNamed_Behaviour {
};

JBClass ( SCIterator , SCNamed , 
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

struct SCNode_Behaviour: SCNamed_Behaviour {
};

JBClass ( SCNode , SCNamed , 
	Dictionary* Access;
	SCNode* Parent;
	SCNode* MyReacher;
	SCImport* Project;
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
	FP_SpdMainFn SubProcess;
	int DeathLimit;
	int DiedCount;
	bool WeAreParent;
	bool AlreadyWarnedDied;
	ProcessMode Mode;
);

struct Task_Behaviour: list_Behaviour {
};

JBClass ( JB_Task , JB_List , 
	TaskState State;
	uint _Object;
	void* _func;
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

struct SCArg_Behaviour: SCNode_Behaviour {
};

JBClass ( SCArg , SCNode , 
	SCFunction* ParentFunc;
	Message* TmpMovedOutFor;
	bool IsClassArg;
	bool IsStatementExpr;
);

struct SCBehaviour_Behaviour: SCNode_Behaviour {
};

JBClass ( SCBehaviour , SCNode , 
	SCModule* FuncTable;
	Dictionary* Interfaces;
	Array* WrapperFuncs;
);

struct SCClass_Behaviour: SCNode_Behaviour {
};

JBClass ( SCClass , SCNode , 
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
	SCDecl* DataObject;
	uint TaskObjectCount;
	u16 Size;
	u16 Depth;
	u16 StructContainerDepth;
	DataTypeCode TypeInfo;
	byte MinOpt;
	byte IsBehaviour;
	byte IsWrapper;
	bool ContainsParentClass;
	bool IgnoreContainedSelf;
	bool HasCompareFunc;
	bool HasEqualsFunc;
	bool HasSubClass;
	bool NoEarlyFree;
	bool AutoGeneratedSavers;
	bool SavingCanSkip;
	bool TreatAsBaseType;
	bool Banned;
	bool HasNilChecker;
	bool DefaultsToReal;
	byte IsRole;
	bool IsBuiltin;
	SCNodeType BaseType;
	bool IsASM;
	byte NumericReduction;
);

struct SCFunction_Behaviour: SCNode_Behaviour {
};

JBClass ( SCFunction , SCNode , 
	Array* LinkTo;
	Array* Args;
	SCClass* Cls;
	JB_String* Description;
	CppRefs* Refs;
	JB_Object* CounterPart;
	SCFunction* NextFunc;
	ASMFunc* ASM;
	SCDecl* ProtoDecl;
	SCClass* ProtoType;
	SCDecl* ReturnType;
	SCFunction* DepthFinder;
	Macro* IsMacro;
	u16 LinkDepth;
	u16 TmpCounter;
	u16 TableId;
	uint AllocCode;
	byte MinOpt;
	byte IsAssigns;
	byte IsCppInBuilt;
	ErrorSeverity BlindCasts;
	bool FlowDisabled;
	bool IsExternalLib;
	bool IsWrapper;
	byte IsNilChecker;
	NilState NilSelf;
	bool IsInline;
	bool IsKiller;
	bool IsDisabled;
	bool IsAPI;
	bool NoRefCounts;
	bool AutoGeneratedSaver;
	bool HidesProperties;
	byte Badness;
);

struct SCModule_Behaviour: SCNode_Behaviour {
};

JBClass ( SCModule , SCNode , 
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

JBClass ( LessThan3 , JB_Task , 
	JB_String* a;
	int b;
	JB_String* c;
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
extern Array* SC__Comp_DeclConstants;
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
extern bool SC__Comp_InPerry;
extern Dictionary* SC__Comp_InsecureWords;
extern SCFile* SC__Comp_InternalFile;
extern SCNode* SC__Comp_Interpreter;
#define kSC__Comp_kTimeWidth (19)
extern Date SC__Comp_LastTime;
extern JB_String* SC__Comp_LastTimeName;
extern SCFunction* SC__Comp_MainFunc;
extern Array* SC__Comp_ModuleList;
extern SCFunction* SC__Comp_NewFunc;
extern JB_String* SC__Comp_OriginalInputPath;
extern SCFunction* SC__Comp_PrivateProperty;
extern SCModule* SC__Comp_program;
extern SCImport* SC__Comp_Project;
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
extern int SC__Comp_stParseTime;
extern int SC__Comp_stParseTimeTotal;
extern int SC__Comp_stReachedClass;
extern int SC__Comp_stReachedFunc;
extern int SC__Comp_stTotalFileCount;
extern int SC__Comp_stTotalSourceSize;
extern Array* SC__Comp_SyxArray;
extern Array* SC__Comp_TasksList;
extern Array* SC__Comp_TasksTodo;
extern JB_File* SC__Comp_TempFolder;
extern SCFunction* SC__Comp_TernaryFunc;
extern FastString* SC__Comp_TimerOutput;
extern Array* SC__Comp_TodoList;
extern SCNode* SC__Comp_VisibleFuncs;
#define kSC__CustomOps_LeftOnlyIsVector (65)
#define kSC__CustomOps_Needed (64)
#define kSC__CustomOps_NotCustom (0)
#define kSC__CustomOps_RightOnlyIsVector (66)
#define kSC__CustomOps_TypeCastFromBool (16)
#define kSC__CustomOps_TypeCastToBetter (32)
#define kJB__ErrorColors_bold (JB_LUB[94])
extern bool JB__ErrorColors_Enabled;
#define kJB__ErrorColors_error (JB_LUB[91])
#define kJB__ErrorColors_good (JB_LUB[92])
#define kJB__ErrorColors_normal (JB_LUB[95])
#define kJB__ErrorColors_underline (JB_LUB[92])
#define kJB__ErrorColors_warn (JB_LUB[93])
extern Array* SC__ExecTable_Funcs;
extern Array* SC__ExecTable_Globs;
extern SCFunction* SC__FastStringOpts__ByteFunc;
extern int SC__FastStringOpts_FSRemoved;
extern int SC__FastStringOpts_StrRemoved;
extern Dictionary* SC__FB_AppOptions;
extern Macro* SC__AC_all_tmp_src;
extern SCFunction* SC__AC_AnonFn;
extern SCNode* SC__AC_AnonParent;
extern JB_String* SC__AC_AnonText;
extern bool SC__AC_Cleaned;
extern bool SC__AC_CompiledOK;
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
extern uint SC__LinkMap_CurrID;
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
extern Macro* SC__Macros_ConstructorNew;
extern Macro* SC__Macros_ConstructorNewTask;
extern Macro* SC__Macros_FS;
extern Macro* SC__Macros_InitExpand;
extern Macro* SC__Macros_MainArgArray;
extern Macro* SC__Macros_MainArgBasic;
extern Macro* SC__Macros_MainArgBasicReq;
extern Macro* SC__Macros_MainArgDefault;
extern Macro* SC__Macros_MainArgNoNE;
extern Macro* SC__Macros_MultiDecr;
extern Macro* SC__Macros_WhileDecl;
#define kJB__Math_E (2.7182818284590452353602874713526f)
#define kJB__Math_iTau (0.15915494309f)
extern JB_String* SC__Options_Arch;
extern bool SC__Options_ArgStats;
extern Dictionary* SC__Options_BannedClasses;
extern bool SC__Options_Beep;
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
extern byte SC__Options_PerryOutput;
extern bool SC__Options_PrintCompileString;
extern bool SC__Options_PrintFiles;
extern bool SC__Options_PrintLibraries;
extern bool SC__Options_PrintStages;
extern int SC__Options_Products;
extern bool SC__Options_ProjectIsLibrary;
extern bool SC__Options_ProjectIsMiniLib;
extern bool SC__Options_Scripting;
extern bool SC__Options_SelfReplacement;
extern bool SC__Options_Silent;
extern bool SC__Options_SingleCppOutput;
extern JB_String* SC__Options_SingleFileInput;
extern bool SC__Options_TargetDebug;
extern bool SC__Options_UseFuncCallCount;
extern byte SC__Options_UseScriptLoc;
extern JB_String* SC__Options_Variant;
extern bool SC__Options_Warnings;
extern JB_File* JB__Platform_Logger;
extern Dictionary* SC__SCGame3D_Types;
extern int SC__SC_UniqueNum;
#define kSC__Refs_kBasisCArray (8)
#define kSC__Refs_kBasisDeSTRUCTable (2)
#define kSC__Refs_kBasisNotObj (0)
#define kSC__Refs_kBasisObj (1)
#define kSC__Refs_kBasisTempStruct (4)
#define kSC__Refs_kHoldsDisowned (128)
#define kSC__Refs_kIsDisowner (64)
#define kSC__Refs_kIsNoisy (32)
#define kSC__Refs_kNotDisturbed (0)
#define kSC__Refs_kSufferedNoise (16)
#define kSC__Refs_LargestFlag (255)
extern Message* SC__SCStrings_RenderFinish;
extern Message* SC__SCStrings_RenderInsides;
extern Message* SC__SCStrings_RenderNewParams;
extern Macro* SC__SCTasks_TaskMacro;
extern Message* SC__SCTasks_tmp;
extern Dictionary* SC__Errors_IgnoredBranches;
extern Dictionary* SC__SC_Targets_Items;
extern Array* SC__Crkt_List;
extern Dictionary* SC__Crkt_Table2;
extern int SC__Crkt_TotalSize;
#define kJB__Terminal_Black (30)
#define kJB__Terminal_Blue (34)
#define kJB__Terminal_Cyan (36)
extern FastString* JB__Terminal_fs;
#define kJB__Terminal_Green (32)
#define kJB__Terminal_h (35)
extern Date JB__Terminal_LastDisplay;
#define kJB__Terminal_Magenta (35)
#define kJB__Terminal_Red (31)
extern Array* JB__Terminal_Screen;
#define kJB__Terminal_w (80)
#define kJB__Terminal_White (37)
#define kJB__Terminal_Yellow (33)
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
#define kJB_codesign_native (JB_LUB[1554])
extern Dictionary* JB_CppRefTable;
extern CharSet* JB_CSHex;
extern CharSet* JB_CSNum;
extern JB_ErrorReceiver* JB_ErrorDelayer;
extern FP_ExprResolver JB_ExprFuncs[64];
extern SCDecl* JB_FalseBool;
extern fn_asm JB_fn_asm_table[64];
extern FastString* JB_fs_tmp_num;
extern Dictionary* JB_FuncLinkageTable;
extern Dictionary* JB_FuncPreReader;
#define kJB_kActualTypecasts ((~(128 | 32)))
#define kJB_kAddressOfMatch (3 << 22)
#define kJB_kASM (63)
#define kJB_kBitOr (JB_LUB[277])
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
#define kJB_kSaverStart1 (JB_LUB[602])
#define kJB_kSimpleMatch (1 << 22)
#define kJB_kSuperClassMatch (4 << 22)
#define kJB_kTypeCastAssigns (64)
#define kJB_kTypeCastBothWays (16)
#define kJB_kTypeCastDescribeErrors (256)
#define kJB_kTypeCastFalse (0)
#define kJB_kTypeCastFromZero (512)
#define kJB_kTypeCastIgnoreAddressOf (8)
#define kJB_kTypeCastIgnoreContained (4)
#define kJB_kTypeCastMost (1)
#define kJB_kTypeCastNumbers (2)
#define kJB_kTypeCastTrue (1 | 2)
#define kJB_kTypeCastWantSuperDistance (128)
#define kJB_kUseDefaultParams (8 << 22)
#define kJB_kVoidPtrMatch (5 << 22)
extern Message* JB_ReturnSelfEqNil;
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
extern SCClass* JB_TypeCodePoint;
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
extern SCClass* JB_TypeTask;
extern SCClass* JB_TypeuInt;
extern SCClass* JB_TypeuInt16;
extern SCClass* JB_TypeuInt64;
extern SCClass* JB_TypeVec2;
extern SCClass* JB_TypeVec3;
extern SCClass* JB_TypeVec4;
extern SCDecl* JB_TypeVoid;
extern SCClass* JB_TypeVoid_;
extern SCDecl* JB_TypeVoidPtr;
extern SCClass* JB_TypeWrapper;
extern JB_String* JB__Tk_Data;
extern bool JB__Tk_DotInsertAllow;
extern Message* JB__Tk_EndOfLineMarker;
extern Dictionary* JB__Tk_ErrorNames;
#define kJB__Tk_kAdjectiveOp (1)
#define kJB__Tk_kAllow (false)
#define kJB__Tk_kColon (2)
#define kJB__Tk_kColonArg (4)
#define kJB__Tk_kComma (128)
#define kJB__Tk_kEnd ((64 | 128) | 256)
#define kJB__Tk_kEndContainer (256)
#define kJB__Tk_kEndOfLine (64)
#define kJB__Tk_kExpect (true)
#define kJB__Tk_kFuncAfterAny ((512 | 1024) | 2048)
#define kJB__Tk_kFuncAfterBar (2048)
#define kJB__Tk_kFuncAfterNormal (512)
#define kJB__Tk_kFuncAfterNoSpace (1024)
#define kJB__Tk_kIllegalChar (4194304)
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
#define kJB__Tk_kTemporalWordColon (262144)
#define kJB__Tk_kThing ((524288 | 1048576) | 2097152)
#define kJB__Tk_kThingBar (1048576)
#define kJB__Tk_kThingSyx (524288)
#define kJB__Tk_kThingWord (2097152)
#define kJB__Tk_kTmpOpp (32768 | 16)
#define kJB__Tk_LargestFlag (8388607)
extern FP_fnIDGenerator JB__Tk_Splitter;
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
#define kSC__ASMtmp_kContinue (4)
#define kSC__ASMtmp_kDebugger (12)
#define kSC__ASMtmp_kElseIf (1)
#define kSC__ASMtmp_kExit (5)
#define kSC__ASMtmp_kFail (13)
#define kSC__ASMtmp_kIf (2)
#define kSC__ASMtmp_kRejoin (7)
#define kSC__ASMtmp_kReturn (6)
#define kSC__ASMtmp_kSetVar (11)
#define kSC__ASMtmp_kStatementExpression (10)
#define kSC__ASMtmp_kSwap (8)
#define kSC__ASMtmp_kTern (9)
#define kSC__ASMtmp_kWhile (3)
#define kJB__CharProp_AlmostLetter (6)
#define kJB__CharProp_Letters (7)
#define kJB__CharProp_Lower (9)
#define kJB__CharProp_Nothing (0)
#define kJB__CharProp_Number (5)
#define kJB__CharProp_Punct (2)
#define kJB__CharProp_Unicode (10)
#define kJB__CharProp_Upper (8)
#define kJB__CharProp_VarNames (4)
#define kJB__CharProp_White (1)
#define kJB__CharProp_XMLPunct (3)
#define kJB__ControlClipMode_Debug (4)
#define kJB__ControlClipMode_LargestFlag (7)
#define kJB__ControlClipMode_SlideBackInParent (1)
#define kJB__ControlClipMode_SlideBackInWindow (2)
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
#define kSC__DotUseType_Memory (2)
#define kSC__DotUseType_Property (1)
#define kJB__ErrorFlags_DontStrip (1)
#define kJB__ErrorFlags_Keep (0)
#define kJB__ErrorFlags_LargestFlag (7)
#define kJB__ErrorFlags_Parse (4)
#define kJB__ErrorFlags_PreferNoRenderPath (2)
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
#define kJB__FileDes_StdErr (2)
#define kJB__FileDes_StdIn (0)
#define kJB__FileDes_StdOut (1)
#define kJB__FileMode_CanExec (1 << ((6 + 1) << ((3 + 1) << 0)))
#define kJB__FileMode_Data (6 << ((6 + 4) << ((2 + 4) << 2)))
#define kJB__FileMode_Group (7 << 3)
#define kJB__FileMode_Other (7 << 0)
#define kJB__FileMode_Owner (7 << 6)
#define kJB__FileMode_Process (((7 << 6) + 5) << ((3 + 5) << 0))
#define kJB__FileResolveMode_AllowMissing (true)
#define kSC__FunctionType_AlreadyExported (16384)
#define kSC__FunctionType_Behaviour (2048)
#define kSC__FunctionType_Comparison (4)
#define kSC__FunctionType_ConOrDes (1 + 2)
#define kSC__FunctionType_Constructor (1)
#define kSC__FunctionType_Destructor (2)
#define kSC__FunctionType_EmptyConstructor (512)
#define kSC__FunctionType_ExpectsRealVars (8192)
#define kSC__FunctionType_InitFunc (128)
#define kSC__FunctionType_LargestFlag (65535)
#define kSC__FunctionType_NewNew (4096)
#define kSC__FunctionType_NewStruct (16)
#define kSC__FunctionType_NumberCreator (32)
#define kSC__FunctionType_Recursive (256)
#define kSC__FunctionType_Reffer (8)
#define kSC__FunctionType_Render (32768)
#define kSC__FunctionType_TypeTest (64)
#define kSC__FunctionType_VirtualCaller (1024)
#define kJB__MoveCode_All (63)
#define kJB__MoveCode_Back (kJB__MoveCode_Backward)
#define kJB__MoveCode_Backward (32)
#define kJB__MoveCode_Bottom (kJB__MoveCode_Down)
#define kJB__MoveCode_Center (63)
#define kJB__MoveCode_Close (128)
#define kJB__MoveCode_Down (8)
#define kJB__MoveCode_Forward (16)
#define kJB__MoveCode_Front (kJB__MoveCode_Forward)
#define kJB__MoveCode_Horizontal (1 + 2)
#define kJB__MoveCode_LargestFlag (255)
#define kJB__MoveCode_Left (2)
#define kJB__MoveCode_MiddleLeft (2 + (4 + 8))
#define kJB__MoveCode_MiddleRight (1 + (4 + 8))
#define kJB__MoveCode_Negative ((2 + (8 + (32 + 128))))
#define kJB__MoveCode_Open (64)
#define kJB__MoveCode_Positive ((1 + (4 + (16 + 64))))
#define kJB__MoveCode_Right (1)
#define kJB__MoveCode_Top (kJB__MoveCode_Up)
#define kJB__MoveCode_Up (4)
#define kJB__MoveCode_Vertical (4 + 8)
#define kJB__MsgParseFlags_BreakPoint (32768)
#define kJB__MsgParseFlags_Editable (2048)
#define kJB__MsgParseFlags_Inserted (4096)
#define kJB__MsgParseFlags_LargestFlag (0)
#define kJB__MsgParseFlags_MacroInserted (12288)
#define kJB__MsgParseFlags_MacroMade (8192)
#define kJB__MsgParseFlags_NicelyPositioned (1024)
#define kJB__MsgParseFlags_Style2 (16384)
#define kSC__khalai_Active (2 + 1)
#define kSC__khalai_And (8)
#define kSC__khalai_Basic ((2 + 1) + 4)
#define kSC__khalai_Disappears (64)
#define kSC__khalai_LargestFlag (127)
#define kSC__khalai_Negative (1)
#define kSC__khalai_Nothing (0)
#define kSC__khalai_Positive (2)
#define kSC__khalai_Reversed (16)
#define kSC__khalai_Soft (4)
#define kSC__khalai_While (32)
#define kSC__khalai_WhileNeg (1 + 32)
#define kSC__khalai_WhilePos (2 + 32)
#define kSC__NilReason_Accessing (0)
#define kSC__NilReason_Passing (4)
#define kSC__NilReason_Property (1)
#define kSC__NilReason_Reading (2)
#define kSC__NilReason_Using (3)
extern Array* SC__NilReason_values;
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
#define kSC__NumericLoss_Fixed (2)
#define kSC__NumericLoss_Flag (4)
#define kSC__NumericLoss_LargestFlag (7)
#define kSC__NumericLoss_Normal (0)
#define kSC__NumericLoss_Symbol (1)
#define kSC__OpMode_Addition (16)
#define kSC__OpMode_AND (8192)
#define kSC__OpMode_AndOr (4096 | 8192)
#define kSC__OpMode_Assigns (2)
#define kSC__OpMode_Bit (4)
#define kSC__OpMode_CaseAware (32768)
#define kSC__OpMode_Compare (1)
#define kSC__OpMode_CompSet (1 | 2)
#define kSC__OpMode_Custom (16384)
#define kSC__OpMode_EqualOrNot (256)
#define kSC__OpMode_ExactEquals (512 + (128 + (256 + 1)))
#define kSC__OpMode_ExactlyEquals (128)
#define kSC__OpMode_ExactNotEquals (512 + (256 + 1))
#define kSC__OpMode_LargestFlag (65535)
#define kSC__OpMode_Left (32 + 1024)
#define kSC__OpMode_LeftOnly (32)
#define kSC__OpMode_LoseBits (2048)
#define kSC__OpMode_MakesSigned (64)
#define kSC__OpMode_Math (8)
#define kSC__OpMode_MathLike (4 | 8)
#define kSC__OpMode_NilTest (512)
#define kSC__OpMode_NoExtraBits (1024)
#define kSC__OpMode_OR (4096)
#define kSC__OpMode_SameOrLessBits (1024 | 2048)
#define kJB__ProcessMode_AutoPrintErrors (4)
#define kJB__ProcessMode_CaptureAll (1 | 4)
#define kJB__ProcessMode_CaptureErrors (2)
#define kJB__ProcessMode_CaptureOrPrintErrors (2 | 4)
#define kJB__ProcessMode_CaptureStdOut (1)
#define kJB__ProcessMode_LargestFlag (7)
#define kSC__SCBlockage_Bits (480)
#define kSC__SCBlockage_Continue (64)
#define kSC__SCBlockage_Exit (128)
#define kSC__SCBlockage_LargestFlag (0)
#define kSC__SCBlockage_Quit (kSC__SCBlockage_Return)
#define kSC__SCBlockage_Return (192)
#define kSC__SCDeclInfo_Altered (1048576)
#define kSC__SCDeclInfo_AlteredViaPointer (524288)
#define kSC__SCDeclInfo_API (512)
#define kSC__SCDeclInfo_Atomic (8388608)
#define kSC__SCDeclInfo_Body (32768)
#define kSC__SCDeclInfo_Borrowed (1)
#define kSC__SCDeclInfo_ClassObj (1024)
#define kSC__SCDeclInfo_CompilerCreated (2048)
#define kSC__SCDeclInfo_Const (8)
#define kSC__SCDeclInfo_DataConst (4 + 8)
#define kSC__SCDeclInfo_DataOnlyConst (4)
#define kSC__SCDeclInfo_DclCopied (1048576 + (2 + (16 + (512 + (32 + 2048)))))
#define kSC__SCDeclInfo_Disabled (8192)
#define kSC__SCDeclInfo_GameFlyingMem (2097152)
#define kSC__SCDeclInfo_Global (131072)
#define kSC__SCDeclInfo_LargestFlag (67108863)
#define kSC__SCDeclInfo_Local (32768 + 16384)
#define kSC__SCDeclInfo_NewlyCreated (64)
#define kSC__SCDeclInfo_Param (16384)
#define kSC__SCDeclInfo_Property (65536)
#define kSC__SCDeclInfo_PropertyWasConstructed (4096)
#define kSC__SCDeclInfo_Return (262144)
#define kSC__SCDeclInfo_Self (16777216)
#define kSC__SCDeclInfo_SelfImplicit (16777216 + (32768 + 16384))
#define kSC__SCDeclInfo_SetTo (33554432)
#define kSC__SCDeclInfo_Static (16)
#define kSC__SCDeclInfo_StayBorrowed (2)
#define kSC__SCDeclInfo_Task (4194304)
#define kSC__SCDeclInfo_TypeImprove (128)
#define kSC__SCDeclInfo_UpgradeableContained (32)
#define kSC__SCDeclInfo_UsedByCode (256)
#define kSC__SCNodeFindMode_DontGoUp (2)
#define kSC__SCNodeFindMode_LargestFlag (0)
#define kSC__SCNodeFindMode_NoErrors (1)
#define kSC__SCNodeFindMode_WantAType (4)
#define kSC__SCNodeInfo_ExplicitExport (0)
#define kSC__SCNodeInfo_Visible (1)
#define kSC__SCNodeType_DataType (2)
#define kSC__SCNodeType_FuncProto (3)
#define kSC__SCNodeType_Module (0)
#define kSC__SCNodeType_Nil (1)
#define kSC__SCNodeType_Object (5)
#define kSC__SCNodeType_Struct (4)
extern int JB__Syx_CurrFuncID;
extern int JB__Syx_MaxFuncID;
#define kJB__TaskState_Animation (16)
#define kJB__TaskState_Finished (64)
#define kJB__TaskState_HadErrors (8)
#define kJB__TaskState_LargestFlag (127)
#define kJB__TaskState_Paused (2)
#define kJB__TaskState_Started (1)
#define kJB__TaskState_Successful (32)
#define kJB__TaskState_WaitsTillStart (4)
#define kSC__TM_BaseShrinkSpeed (0.0005f)
#define kSC__TM_Halfmap (6148914691236517205)
#define kSC__TM_MOUSEBUTTONDOWN (1025)
#define kSC__TM_MOUSEMOTION (1024)
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
extern FP_NilTrackerFn SC__nil_NilSyxes[64];
extern FP_NilTrackerFn SC__nil_NilTmps[64];
extern byte SC__nil_NilTrapper;
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
extern Array* JB__Macro_TmpPrms;
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
extern MaterialsLol* SC__MaterialsLol___First;
extern MaterialsLol* SC__MaterialsLol_Iron;
extern MaterialsLol* SC__MaterialsLol_Pellets;
extern MaterialsLol* SC__MaterialsLol_WierdBlock;
extern MaterialsLol* SC__MaterialsLol_Wood;
extern SCIterator* SC__Iter_carray;
extern SCIterator* SC__Iter_pointer;
extern bool SC__Base_ConstantsLoadingOverride;
extern bool SC__Base_CurrVisibility;
#define kSC__Base_DontGoUp (2)
#define kSC__Base_kPurposeAddress (0)
#define kSC__Base_kPurposeDot (2)
#define kSC__Base_kPurposeFunc (1)
#define kSC__Base_kPurposeHider (65536)
#define kSC__Base_kPurposeVar (3)
#define kSC__Base_kPurposeVarDecl (4)
#define kSC__Base_LargestFlag (0)
#define kSC__Base_NoErrors (1)
extern SpdProcess* JB__Proc_Parent;
extern byte JB__Err_AutoPrint;
extern Array* JB__Err_CurrSource;
extern bool JB__Err_KeepStackTrace;
#define kSC__Beh_kBehaviourProto (2)
#define kSC__Beh_kBehaviourProtoRequired (6)
#define kSC__Beh_kBehaviourTable (1)
extern SCFunction* SC__Func_CurrFunc;
extern int SC__Func_DisabledPoints;
extern int SC__Func_FuncStats[12];
extern int SC__Func_OnceCount;
extern Dictionary* SC__Func_TemporalStatements;
extern SCModule* SC__Mod_Curr;

//// HEADER JB.h



// App
JB_String* JB_App__AppName();

JB_String* JB_App__AppPath();

JB_String* JB_App__Conf(JB_String* name);

void JB_App__ConfigureSet(JB_String* Value);

void JB_App__Crash(JB_String* reason);

ErrorInt JB_App__CWDSet(JB_String* Value);

JB_String* JB_App__FileName();

int JB_App__Init_();

int JB_App__InitCode_();

bool JB_App__IsMainThread();

JB_String* JB_App__OrigPath();

JB_String* JB_App__GetPref(JB_String* s);

void JB_App__PrefSet(JB_String* s, JB_String* Value);

JB_String* JB_App__PrefPath();

Message* JB_App__PrefsInit(Date when);

void JB_PrintStackTrace();

void JB_App__SavePrefs();

ErrorInt2 JB_App__Say(JB_String* s, bool print);

JB_String* JB_App__StackTrace(int skip, FastString* fs_in);

int64 JB_App__StringMemory();

JB_String* JB_App__ArgValue(JB_String* name);



// AutoComplete
int SC_AutoComplete__Init_();

int SC_AutoComplete__InitCode_();

bool SC_AutoComplete__IsAFunc(JB_String* s);



// CodeSorter
bool SC_CodeSorter__LeafFunctionsSorter(SCFunction* a, SCFunction* b);

void SC_CodeSorter__LeafsFirst();



// Comp
SCDecl* SC_Comp__AddGlobalConst(JB_String* name, SCClass* c, NilState dcl);

void SC_Comp__AddGlobalConstNumWithStrClassInt64(JB_String* name, SCClass* c, int64 value);

void SC_Comp__AddGlobalConstNumWithStrClassStr(JB_String* name, SCClass* c, JB_String* value);

bool SC_Comp__AddMain(int mark);

JB_String* SC_Comp__AddSCProj(JB_String* Path);

Dictionary* SC_Comp__Adj(Message* f);

void SC_Comp__AppBuildLibs(JB_File* inner);

void SC_Comp__AppBuildOneLib(JB_File* inner, Message* lib);

void SC_Comp__AppendCompilerTime(JB_String* s, int Durr);

void SC_Comp__AppleBuildApp(JB_File* project, JB_File* product);

bool SC_Comp__Banned(JB_String* name);

void SC_Comp__BuildConstructors();

JB_File* SC_Comp__BuildFolder();

void SC_Comp__CheckIsGoodLibrary();

bool SC_Comp__ClassSorter(JB_Object* a, JB_Object* b);

void SC_Comp__ClearEnvs();

void SC_Comp__CodeSign(JB_File* gui_exe);

void SC_Comp__Collect(Message* m, bool visible);

void SC_Comp__CollectConstants();

bool SC_Comp__CollectIsaTests(Message* s);

bool SC_Comp__CompileAll();

void SC_Comp__CompileTime();

void SC_Comp__CreateDisambiguation();

SCFunction* SC_Comp__CreateFuncFromSource(JB_String* Src);

void SC_Comp__CreateRoot();

void SC_Comp__DeadStrip();

void SC_Comp__DoRefAnalysis();

void SC_Comp__DoSavers(int Stage);

bool SC_Comp__EnterCompile();

void SC_Comp__FileSanityTests();

void SC_Comp__FileTestsSub(JB_File* Dest, JB_File* Src, JB_String* A, JB_String* B);

Macro* SC_Comp__FindAdj(Message* exp, Array* prms);

SCDecl* SC_Comp__FindClassType(Message* n);

SCFunction* SC_Comp__FindFunction(JB_String* Name);

SCModule* SC_Comp__FindModuleMsg(Message* where, SCNodeFindMode Mode);

SCNode* SC_Comp__FindModuleOrClass(Message* mod, bool retry);

JB_File* SC_Comp__FindProject(JB_String* Path, bool error);

JB_File* SC_Comp__FindProjectSub(JB_String* base, JB_String* Path);

JB_String* SC_Comp__FindProjNoSuffix(JB_String* Path);

JB_String* SC_Comp__FindSpeedieRoot();

JB_File* SC_Comp__GeneratedCppsFolder();

JB_String* SC_Comp__IdealName();

void SC_Comp__ImportAll();

void SC_Comp__ImportAST();

void SC_Comp__ImportLibs();

void SC_Comp__ImportProj();

int SC_Comp__Init_();

bool SC_Comp__InitBasicFuncs();

int SC_Comp__InitBasicStuff();

int SC_Comp__InitCode_();

void SC_Comp__InitCompiler();

void SC_Comp__InitTypes();

JB_File* SC_Comp__InputFile(JB_File* Default, JB_String* s, Message* where);

bool SC_Comp__IsTest();

JB_File* SC_Comp__Jeebox();

JB_File* SC_Comp__Library();

void SC_Comp__LoadInitsAndMore();

SCFunction* SC_Comp__LoadRefFunc(JB_String* name);

void SC_Comp__LoadSuperClasses();

SCFunction* SC_Comp__LoadTypeTest(JB_String* s);

void SC_Comp__Main();

Message* SC_Comp__MakeMainFunc();

void SC_Comp__MiniTests();

bool SC_Comp__ModulesSorter(JB_Object* a, JB_Object* b);

void SC_Comp__NewConst(SCDecl* d);

void SC_Comp__Package();

void SC_Comp__PostInitCodeCall();

void SC_Comp__PrepareInterpreter();

void SC_Comp__PrintCompileErrors();

void SC_Comp__PrintCompileTime(Date durr);

void SC_Comp__PrintErrors(ErrorSeverity MinSev);

void SC_Comp__PrintResults();

void SC_Comp__PrintStats();

JB_String* SC_Comp__Projects();

bool SC_Comp__Reached(JB_String* s);

int SC_Comp__ReachedClassCount();

int SC_Comp__Reachedfuncs();

JB_String* SC_Comp__RenderErrors(JB_ErrorReceiver* stderr, ErrorSeverity MinSev);

JB_File* SC_Comp__ScriptLoc(JB_String* f);

bool SC_Comp__ScriptRecompile(JB_File* f, JB_File* script_build);

void SC_Comp__SetupEnv();

void SC_Comp__SortModulesAndClasses();

JB_File* SC_Comp__Speedie();

JB_String* SC_Comp__SpeedieProj();

bool SC_Comp__Stage(JB_String* name);

SCClass* SC_Comp__FindClassName(JB_String* name);

SCClass* SC_Comp__SyntaxAccess(Message* name);

void SC_Comp__SyntaxAppend(Message* m);

void SC_Comp__TestDate();

void SC_Comp__TestTask();

void SC_Comp__Timer(JB_String* name);

void SC_Comp__TimerSub(JB_String* s, int Durr);

bool SC_Comp__TryVariousStartModes();

JB_File* SC_Comp__UsingScript(JB_File* f);

JB_String* SC_Comp__VariantSuffix();

void SC_Comp__VariousSelfTests();

SCNode* SC_Comp__WrongConf(Message* node, SCNode* name_space, Message* ErrPlace);



// CustomOps


// ErrorColors
void JB_ErrorColors__DisableIfNoTerminal();

int JB_ErrorColors__Init_();

int JB_ErrorColors__InitCode_();



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

bool SC_FB__AppOptions_asm(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_beep(JB_String* Name, JB_String* Value, FastString* purpose);

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

bool SC_FB__AppOptions_flow(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_force(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_funccount(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_gcc(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_help(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_ignorecantsave(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_keepallerrors(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_log(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_m32(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_m64(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_maxvars(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_nil(JB_String* Name, JB_String* Value, FastString* purpose);

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

bool SC_FB__AppOptions_silent(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_single(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_stages(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_target(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_targetdebug(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_usescriptloc(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_variant(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppOptions_warn(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppTransCompile(JB_String* Name, JB_String* Value, FastString* purpose);

bool SC_FB__AppVersionNumber(JB_String* Name, JB_String* Value, FastString* purpose);

void SC_FB__CheckSelfModifying();

int SC_FB__CheckSelfModifying2();

bool SC_FB__CompilerInfo();

bool SC_FB__Explain(FastString* Purpose, JB_String* name);

void SC_FB__Help();

int SC_FB__Init_();

int SC_FB__InitCode_();

bool SC_FB__ParseArgs();

bool SC_FB__ParseArgsSub(Array* args);

void SC_FB__ParseOption(JB_Object* Obj);

void SC_FB__StopStripping();

JB_String* SC_FB__TryUseProject(JB_String* path, bool IsScript);



// InbuiltShellArgs
SCNode* SC_InbuiltShellArgs__Collect(Message* node, SCNode* name_space, Message* ErrPlace);



// AC
bool SC_AC__Active();

void SC_AC__ActualDefine(Message* rz, Message* s, JB_String* purpose);

Message* SC_AC__AllTmps();

Message* SC_AC__AutoComplete(Message* ff, JB_String* name, JB_String* Purpose);

bool SC_AC__AutoCompleteSorter(autoitem* a, autoitem* b);

Message* SC_AC__AutoJump(Message* cmd);

void SC_AC__AutoSub(SCNode* scope, JB_String* name, Array* found, int Types, Message* NeedTypeLimit);

void SC_AC__AutoSub2(SCObject* value, JB_String* key, JB_String* src_name, Array* found, bool exact, int Types, SCDecl* TypeLimiter);

Message* SC_AC__Backup_Define(SCFile* myfile, int f, Message* thg, JB_String* purpose);

Message* SC_AC__CallFrom(Message* msg, JB_String* purpose, JB_Object* found);

Message* SC_AC__CallFromDefine(Message* msg, SCFunction* fn, JB_Object* found);

void SC_AC__CallFromSub(Message* arg, SCFunction* fn);

bool SC_AC__CanUseName(SCNode* l);

Message* SC_AC__Check(Message* cmd);

Message* SC_AC__CmdCleanUp(Message* arg);

Message* SC_AC__CmdResponse(Message* cmd, Message* arg);

bool SC_AC__CmdWrap(Message* arg);

Message* SC_AC__Define(Message* msg, JB_String* purpose, JB_Object* found);

Message* SC_AC__Define_Behaviour(SCFunction* fn, JB_String* purpose);

Message* SC_AC__DefineOrCall(Message* msg, JB_String* purpose, JB_Object* found);

Message* SC_AC__Diissplay(Message* msg, Message* s, JB_String* purpose);

Message* SC_AC__DoCmd(Message* cmd, Message* arg);

bool SC_AC__EnterAutoComplete();

Message* SC_AC__ErrorsToPerry();

Message* SC_AC__FindAdj(Message* msg, bool DisplayOnly);

Message* SC_AC__FuncTmps();

SCFunction* SC_AC__GetFunc(Message* cmd, SCFile* myfile, int ff, int n);

SCFunction* SC_AC__GetFunc2(Message* cmd, SCFile* myfile, int f, int n);

SCNode* SC_AC__GetScope(Message* orig, int* types);

void SC_AC__IdentifyBetter(Message* node, JB_String* name);

int SC_AC__Init_();

int SC_AC__InitCode_();

bool SC_AC__InitedOK();

Message* SC_AC__JumpImport(Message* cmd);

Message* SC_AC__LocateDefinition(Message* msg, SCObject* already_defined, bool DisplayOnly);

Message* SC_AC__LocateDefinitionSub(Message* msg, SCObject* already_defined, SCDecl* ty, bool DisplayOnly);

Message* SC_AC__MainAct(Message* cmd, SCFile* my_file);

Message* SC_AC__MainActAutoComplete(Message* thg, JB_String* str, Message* cmd);

void SC_AC__ParserRestore();

void SC_AC__PerryTalk(SpdProcess* perry);

Message* SC_AC__ReportMemory(Message* cmd);

Message* SC_AC__RespondDefine(Message* msg, Message* s, JB_String* purpose);

Message* SC_AC__RootTmpComplete(Message* cmd);

Message* SC_AC__TmpAutoComplete(Message* f, JB_String* name, JB_String* type);

Message* SC_AC__UnusedFuncs(Message* cmd);

Message* SC_AC__WriteError(JB_String* name);



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

bool JB_Constants__TestCasting();



// LinkMap
void SC_LinkMap__Collect(SCFunction* self);

void SC_LinkMap__CollectAll();

int SC_LinkMap__Init_();

int SC_LinkMap__InitCode_();

void SC_LinkMap__Store(Array** darr, SCObject* obj);



// Linkage
SCNode* SC_Linkage__Collect(Message* node, SCNode* name_space, Message* ErrPlace);

int SC_Linkage__Init_();

int SC_Linkage__InitCode_();

bool SC_Linkage__Interpreter();

SCNode* SC_Linkage__LinkerSub(Message* node, SCNode* name_space, Message* ErrPlace);

JB_String* SC_Linkage__SyntaxAccess(JB_String* name);



// MZLab


// Macros
int SC_Macros__Init_();

int SC_Macros__InitCode_();



// Math


// NilTest2


// Options
void SC_Options__ColorSet(bool Value);

bool SC_Options__Color();

int SC_Options__Init_();

int SC_Options__InitCode_();



// Platform
bool JB_Platform__CPU_ARM();

bool JB_Platform__CPU_Intel();

JB_String* JB_Platform__CPU_Name();

bool JB_Platform__CPU_PPC();

bool JB_Platform__CPU_Spd();

int JB_Platform__Init_();

int JB_Platform__InitCode_();

void JB_Platform__Log(JB_String* s);

JB_File* JB_Platform__OpenLog();

int JB_Platform__PointerBytes();

bool JB_Platform__Release();



// SCGame3D
int SC_SCGame3D__Init_();

int SC_SCGame3D__InitCode_();

SCNode* SC_SCGame3D__Love(Message* node, SCNode* name_space, Message* ErrPlace);

bool SC_SCGame3D__NeedShader(JB_String* Name);

SCNode* SC_SCGame3D__NeuModel(Message* node, SCNode* name_space, Message* ErrPlace);



// SC
int SC__Init_();

int SC__InitCode_();



// Refs
void SC_Refs__DeclInit(Message* dcl, SCFunction* fn, bool IsJustAnArg);

Message* SC_Refs__DecrMulti(SCDecl* d, Message* m);

void SC_Refs__Destructable(Message* Blocker, Message* arg, Message* name);

bool SC_Refs__ExitHitsOrGoesPast(Message* curr, Message* arg);

bool SC_Refs__ExprNeedsTemping(Message* child, Message* name);

Message* SC_Refs__LastUsedRefPlace(Message* name, Message* arg);

void SC_Refs__RC_CheckFuncAllocOK(SCFunction* self, Message* dot);

void SC_Refs__RC_DeclArg(SCDecl* AR, SCFunction* fn);

void SC_Refs__RC_HandleDisappearing(SCFunction* fn, Message* msg, int Basis);

void SC_Refs__RC_IgnoreReturn(Message* msg, bool DoRefs);

bool SC_Refs__RC_NeedsOwnBlock(Message* msg, Message* pp);

void SC_Refs__RC_Rel(Message* rel);

void SC_Refs__RC_RelConstructor(Message* rel);

int SC_Refs__RefBasis(Message* msg, bool SetOnly);

int SC_Refs__RefBasisStruct(Message* msg, bool SetOnly);

Message* SC_Refs__RefClearMsg(Message* msg);

void SC_Refs__RefDecr(Message* msg, Message* place, int Basis);

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
SCNode* SC_SCSelector__Build(Message* node, SCNode* name_space, Message* ErrPlace);

Message* SC_SCSelector__BuildClassCode(JB_String* name, JB_String* type);

void SC_SCSelector__DeclareOneSel(JB_String* sel_name, JB_String* type, Message* place);

Message* SC_SCSelector__FindItems(Message* arg);

bool SC_SCSelector__HasClassStuff(Message* self);

void SC_SCSelector__LoadOneSel(JB_String* sel_name, JB_String* module_name, Message* LoaderPlace, Message* Prms);

SCNode* SC_SCSelector__Neu(Message* node, SCNode* name_space, Message* ErrPlace);



// SCStrings
int SC_SCStrings__Init_();

int SC_SCStrings__InitCode_();



// SCTasks
void SC_SCTasks__CollectAll();

int SC_SCTasks__Init_();

int SC_SCTasks__InitCode_();

SCNode* SC_SCTasks__NewTask(Message* node, SCNode* name_space, Message* ErrPlace);

void SC_SCTasks__NewTaskActual(Message* node, SCNode* name_space);



// SCThe
SCNode* SC_SCThe__NewInsertion(Message* node, SCNode* name_space, Message* ErrPlace);



// SC_API
void SC_SC_API__DelayedClassAPI(Message* node, JB_String* proj);

void SC_SC_API__NewAPI(Message* api, JB_String* part, SCNode* parent, JB_String* proj);

SCNode* SC_SC_API__NewExportAPI(Message* node, SCNode* name_space, Message* ErrPlace);

void SC_SC_API__NewExportAPISub(Message* node, SCObject* parent);



// Errors
bool SC_Errors__AlreadyIgnored(Message* F);

int SC_Errors__Init_();

int SC_Errors__InitCode_();

bool SC_Errors__SyntaxAccess(JB_Error* Err);



// Sav
void SC_Sav__BugWorkAround();

void SC_Sav__TestSaver();



// SC_Targets
int SC_SC_Targets__Init_();

int SC_SC_Targets__InitCode_();

bool SC_SC_Targets__SyntaxAccess(JB_String* name);

void SC_SC_Targets__SyntaxAccessSet(JB_String* name, bool Value);



// SC
ErrorInt JB_Main();



// Crkt
void SC_Crkt__CollectString(Message* m);

void SC_Crkt__Correct(JB_File* where);

void SC_Crkt__CorrectConsts();

int SC_Crkt__Count();

int SC_Crkt__Init_();

int SC_Crkt__InitCode_();

void SC_Crkt__MergeTable(Message* disk, Dictionary* D3);

MessageID* SC_Crkt__NewID(JB_String* name);

void SC_Crkt__Sort(bool IDOrder);

bool SC_Crkt__UseID(MessageID* s, Message* old);

void SC_Crkt__WriteTable(FastString* fs);



// Terminal
int JB_Terminal__Init_();

int JB_Terminal__InitCode_();



// TextAssembler
void SC_TextAssembler__Assemble(Message* msg);

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

void SC_Ext__CollectPico();

JB_File* SC_Ext__CppLib();

Array* SC_Ext__CreateCompileString(Array* FileList, JB_String* Product, JB_String* Type);

bool SC_Ext__ExecuteGCC(Array* Commands);

void SC_Ext__ExportAndInstall(bool CanInstall);

Array* SC_Ext__FilterCppsIfAlreadyDone(Array* Cpps, JB_File* Objects, int* stdafx);

bool SC_Ext__HasType(Array* CppList, JB_String* Type);

int SC_Ext__Init_();

int SC_Ext__InitCode_();

void SC_Ext__InstallCompiler();

void SC_Ext__InstallOne(JB_File* test);

bool SC_Ext__IsCompilerAndNeedsInstall();

JB_String* SC_Ext__LibSuff();

JB_String* SC_Ext__LibTmpPath();

JB_File* SC_Ext__LinkOK(JB_File* p);

void SC_Ext__MacBothArch(Array* r);

JB_String* SC_Ext__MakeDailyProductPath(JB_File* B);

void SC_Ext__MakeLib();

int SC_Ext__NeedNewObjForSrc(JB_String* cpp, JB_File* objects);

int SC_Ext__NoGoodObject(JB_String* Cpp, JB_File* h, JB_File* o);

void SC_Ext__PrintProduct(JB_String* s);

JB_String* SC_Ext__ProductName();

JB_String* SC_Ext__ProductPath(bool Direct);

JB_String* SC_Ext__ProductSuffix();

JB_String* SC_Ext__ProjTmpPath();

void SC_Ext__ReplaceOld(JB_File* input, JB_File* Backs);

void SC_Ext__RunCppCompile();

void SC_Ext__SayTest(JB_String* n);

bool SC_Ext__ShouldTransComp();

bool SC_Ext__TestNewCompiler();

JB_String* SC_Ext__TmpBase(JB_String* V);

JB_String* SC_Ext__TmpErr(JB_String* V);

JB_String* SC_Ext__TmpOut(JB_String* V);

bool SC_Ext__TransCompile(Array* Files, JB_String* Dest, JB_String* Type);

bool SC_Ext__TransCompileWrap(Array* cpps);

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

void SC_VM_Builder__BuildInstructions(SCFunction* fn, Message* node, SCNode* name_space);

void SC_VM_Builder__Clean(Message* msg);

JB_File* SC_VM_Builder__CppLibFile(JB_String* ch);

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

void SC_VM_Builder__MakeJump(Message* msg, FastString* jump);

void SC_VM_Builder__MakeTheVM();

void SC_VM_Builder__MakeVM(Message* tmp, FastString* vm);

void SC_VM_Builder__VMCpp(FastString* vm, FastString* jump);

void SC_VM_Builder__VMDecl(Message* tmp, Array* msgs);

void SC_VM_Builder__VMLine(Message* line, FastString* vm);

Array* SC_VM_Builder__VMSpd(Message* list);

void SC_VM_Builder__VMTmp(Message* tmp, Array* msgs);



// __classes__


// __junktest_5__
void SC___junktest_5____Abc(bool g);

int SC___junktest_5____Init_();

int SC___junktest_5____InitCode_();



// __modules__


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



// image
JB_String* SC_image__ConvertPNGToVOI(JB_String* p);



// main
void SC___junktest_11__();

void SC___junktest_1__();

void SC___junktest_2__();

bool SC___junktest_3__(IntRange data);

void SC_AddToStaticSection(Message* arg, Message* ToAdd);

int SC_ArrayInOrderCheck(int InOrder, Message* msg);

bool SC_CanOpCompare(Message* exp, SCDecl* lc, SCDecl* rc, SCOperator* comp);

void SC_ClassLinkageTable_cpp_class(SCFunction* fn, Message* node, SCNode* name_space);

void SC_ClassLinkageTable_cpp_part(SCFunction* fn, Message* node, SCNode* name_space);

void SC_ClassLinkageTable_cpp_wrapper(SCFunction* fn, Message* node, SCNode* name_space);

void SC_ClassLinkageTable_datatype(SCFunction* fn, Message* node, SCNode* name_space);

void SC_ClassLinkageTable_ignore(SCFunction* fn, Message* node, SCNode* name_space);

void SC_ClassLinkageTable_noearlyfree(SCFunction* fn, Message* node, SCNode* name_space);

void SC_ClassLinkageTable_numeric(SCFunction* fn, Message* node, SCNode* name_space);

void SC_ClassLinkageTable_visible(SCFunction* fn, Message* node, SCNode* name_space);

void SC_ClassLinkageTable_wrapper(SCFunction* fn, Message* node, SCNode* name_space);

SCClass* SC_ClassOfObjForC(Message* curr);

SCNode* SC_ClsCollectTable_pragma(Message* node, SCNode* name_space, Message* ErrPlace);

void SC_CollectDeclsFuncBody(Message* arg, SCNode* scarg);

void SC_CollectDeclsFuncBodyJustWhatWeNewlyMade(Message* arg, SCNode* scarg);

void SC_CollectDeclsFuncBodyUnsureHowToRemove(Message* arg, SCNode* scarg);

void SC_CollectDeclsGlobals(Message* arg, SCNode* scarg);

bool JB_CompareError(Message* expected, Message* found);

void SC_CppRefTable_disowns(SCFunction* fn, Message* node, SCNode* name_space);

void SC_CppRefTable_disturbs(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Create_JeeboxTest(Message* msg);

SCDecl* SC_CustomFuncOp(Message* exp, SCOperator* comp, SCNode* name_space, Message* RN);

SCDecl* SC_DeclOfObjForC(Message* curr);

Message* SC_DeclsDefault(Message* def);

Message* SC_DefaultStitch(Message* Default, Message* dcl);

SCNode* SC_DontRemove(Message* node, SCNode* name_space, Message* ErrPlace);

SCDecl* SC_DoOpCompare(Message* exp, SCDecl* lc, SCDecl* rc, SCOperator* comp, SCNode* name_space);

JB_String* JB_EntityTest();

Message* SC_ExpandToBool(Message* inside, SCNode* name_space);

SCDecl* SC_ExtractDecl(Message* c, SCNode* name_space, DeclMode Purpose);

Message* SC_FindBytePos(Message* Node);

Message* SC_FindBytePosSub(Message* Node);

AsmReg SC_fn_asm_table_63(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_ACC(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_AREL(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_ARG(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_BRA(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_BREL(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_DECL(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_FUNC(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_LIST(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_NUM(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_REL(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_THG(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_TMP(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_fn_asm_table_TYPE(ASMFuncState* self, Message* exp, AsmReg Reg);

void SC_FuncLinkageTable_cpp_part(SCFunction* fn, Message* node, SCNode* name_space);

void SC_FuncLinkageTable_cpp_wrapper(SCFunction* fn, Message* node, SCNode* name_space);

void SC_FuncLinkageTable_ignore(SCFunction* fn, Message* node, SCNode* name_space);

void SC_FuncLinkageTable_inline(SCFunction* fn, Message* node, SCNode* name_space);

void SC_FuncLinkageTable_visible(SCFunction* fn, Message* node, SCNode* name_space);

bool SC_FuncPreReader_description(SCFunction* self, Message* msg);

bool SC_FuncPreReader_disabled(SCFunction* self, Message* msg);

bool SC_FuncPreReader_nil(SCFunction* self, Message* msg);

bool SC_FuncPreReader_numeric(SCFunction* self, Message* msg);

bool SC_FuncPreReader_opt(SCFunction* self, Message* msg);

bool SC_FuncPreReader_pragma(SCFunction* self, Message* msg);

bool SC_FuncPreReader_real(SCFunction* self, Message* msg);

bool SC_FuncPreReader_todo(SCFunction* self, Message* msg);

bool SC_funcsorter_fn(JB_Object* a, JB_Object* b);

int JB_Init_();

int JB_InitCode_();

SCDecl* SC_IsPointerMath(SCDecl* L, SCDecl* R, SCOperator* opp, Message* exp);

void SC_ListFunctionsSub(JB_Object* o, Array* rz);

SCDecl* SC_LowlevelArrayTransform(Message* exp, SCClass* Cls);

Message* SC_MakeDecl(JB_String* Type, JB_String* Name, Message* Value, SCDeclInfo Purpose);

Message* SC_MakeDeclOrRel(Message* Into, Message* namemsg, Message* value);

void SC_MoveFutureStaticsIn(Message* msg);

Message* SC_NewDeclWithStrStr(JB_String* type, JB_String* name);

Message* SC_NewDeclWithStrMsg(JB_String* type, Message* RelOrName);

Message* SC_NewDeclNum(SCDecl* D, int64 N, JB_String* VarName);

Message* SC_NewEqRelWithStrStr(JB_String* L, JB_String* R);

Message* SC_NewEqRelWithMsgMsg(Message* L, Message* R);

Message* SC_NewFnc(JB_String* name);

Message* SC_NewRejoin();

Message* SC_NewRel(Message* L, Message* R, JB_String* op);

NilState SC_NilSyxes_63(Message* msg, NilCheckMode Test);

NilState SC_NilTmps_63(Message* msg, NilCheckMode Test);

SCDecl* SC_Or_And_Expansion(SCDecl* LC, SCDecl* RC, Message* exp, SCNode* name_space);

void JB_Obj_Print(JB_Object* o);

void JB_PrintLine(JB_String* data);

void JB_Obj_PrintLine(JB_Object* o);

void SC_RelSetOrExpansion(Message* exp);

SCNode* SC_RootCollectTable_crash(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_RootCollectTable_extends(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_RootCollectTable_static(Message* node, SCNode* name_space, Message* ErrPlace);

SCDecl* SC_SameTypeSub(Message* first, Message* second, SCNode* name_space);

void SC_SC_MakeComment(Message* msg);

Message* SC_SettingAProperty(Message* Rel);

bool SC_SettingMemory(Message* Rel);

bool SC_SettingSelfProperty(Message* Rel);

Array* SC_SortInitOrder(Array* mods);

bool SC_SortInitOrderSub(Array* mods, Array* out);

ErrorInt Speedie_Main(PicoComms* comms, int Mode, _cstring* args);

Message* SC_SpellOutMsg(Message* type, Message* Exp, Message* namemsg);

void SC_TemporalStatements_alert(SCFunction* fn, Message* node, SCNode* name_space);

void SC_TemporalStatements_break(SCFunction* fn, Message* node, SCNode* name_space);

void SC_TemporalStatements_crash(SCFunction* fn, Message* node, SCNode* name_space);

void SC_TemporalStatements_do(SCFunction* fn, Message* node, SCNode* name_space);

void SC_TemporalStatements_ignore(SCFunction* fn, Message* node, SCNode* name_space);

void SC_TestNumeric();

int SC_TestNumeric2(float f);

bool SC_TooManyErrors();

void SC_Tran_ArgArray(Message* Exp, SCNode* name_space, SCDecl* decl);

void SC_Tran_Flow(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Tran_Msg(SCFunction* fn, Message* Exp, SCNode* name_space);

void SC_Tran_MsgList(SCFunction* fn, Message* Exp, SCNode* name_space);

SCObject* SC_TranNegate(Message* f, SCNode* name_space);

SCObject* SC_TranRender(Message* exp, SCNode* name_space);

SCObject* SC_TypeOfAccess(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfAdj(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfARel(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfArgArr(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfArr(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfBlock(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfBra(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfBRel(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfChar(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfDot(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfDotDotDot(Message* Exp, SCNode* name_space, Message* side);

SCDecl* SC_TypeOfExpr(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfExprModulesOK(Message* Exp, SCNode* name_space, Message* side);

SCDecl* SC_TypeOfExprNeeded(Message* exp, SCNode* name_space);

SCObject* SC_TypeOfExprSub(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfFunc(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfFuncPointer(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfFuncSub(Message* exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfLast(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfList(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfMsg(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfNothing(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfNum(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfQues(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfReal(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfRel(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfSDot(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfSString(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfSthg(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfStr(Message* Exp, SCNode* name_space, Message* side);

SCDecl* SC_TypeOfSwizzle(Message* Exp, SCDecl* Type, SCNode* name_space, Message* side, int swiz);

SCDecl* SC_TypeOfSyntaxCall(Message* exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfSyx(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfTernary(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfThg(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfType(Message* Exp, SCNode* name_space, Message* side);

SCObject* SC_TypeOfUnit(Message* Exp, SCNode* name_space, Message* side);

SCDecl* SC_TypeOfVecAccess(Message* index, SCDecl* ty0, int w);

JB_String* SC_UniqueTmpVar(SCNode* base, JB_String* name);

int SC_UseCustomOperators(SCDecl* LC, SCDecl* RC, SCOperator* Comp, Message* ErrPlace);

SCClass* SC_VecType(bool isfloat, int count);

void* SC_voidtest(void* abc);

void* SC_voidtest2(void* abc);



// Tk
Message* JB_Tk__AddToOutput(Message* Output, Message* curr, Message* prev, int pos);

void JB_Tk__AddXMLText(Message* XML, JB_String* s, int start, int i);

Message* JB_Tk__BarThings(int Start, Syntax Syx);

Message* JB_Tk__BeforeRelSub(int Start, bool Mode);

bool JB_Tk__CanStatement();

Message* JB_Tk__ChainTemporalRels(Message* FirstThing, Message* opp);

JB_String* JB_Tk__CharName(int start, byte find);

Message* JB_Tk__CloseXML(Message* XML, int i, JB_String* s);

Message* JB_Tk__DecorateThing(Message* R, int Ops);

Message* JB_Tk__DotSub(Syntax fn, int Start, Message* parent);

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

Message* JB_Tk__fArgName(int Start, Message* Parent);

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

int JB_Tk__GotoEndOfLine(int from);

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

Message* JB_Tk__ThingXMLAtt(int start, Message* Parent);

void JB_Tk__TokensFn(Array* arr, int bits, FP_ParseHandler func);

void JB_Tk__TokensHan(Array* arr, TokHan* H);

void JB_Tk__TokenzFn(JB_String* s, int bits, FP_ParseHandler func);

Message* JB_Tk__UnexpectedSyntax(Message* bad);

Message* JB_Tk__UnTmpPlace(Message* R);

bool JB_Tk__WillEnd();

int JB_Tk__WordAfter(int Start);

int JB_Tk__WordAfterSub(int Start, CharSet* cs);

int JB_Tk__XMLAttribs(Message* XML, int start);

Message* JB_Tk__XMLWhatever(int s, int skip, JB_String* ender, Syntax fn);

Ind JB_Tk__XMLWordEnd(int From);



// zalgo
int JB_zalgo__Init_();

int JB_zalgo__InitCode_();



// _void


// atomic_byte


// atomic_int


// atomic_uint


// bool
JB_String* JB_bool_Render0(bool self);



// byte
bool JB_byte_CanPrintAsNormalChar(byte self);

bool JB_byte_In(byte self, uint a, uint b);

bool JB_byte_IsHex(byte self);

bool JB_byte_IsInt(byte self);

bool JB_byte_IsLetter(byte self);

bool JB_byte_IsLower(byte self);

bool JB_byte_IsTextLine(byte self);

bool JB_byte_IsUpper(byte self);

bool JB_byte_IsWhite(byte self);

byte JB_byte_LowerCase(byte self);

JB_String* JB_byte_Render(byte self, FastString* fs_in);

byte JB_byte_UpperCase(byte self);



// char


// cstring
JB_String* JB_cstring_Str(_cstring self);

FakeJBString JB_cstring_temp(_cstring self);



// f64
int64 JB_dbl_AsInt(double self);

JB_String* JB_dbl_Render(double self, int dp, FastString* fs_in);



// float
float JB_f_RoundTo(float self, int to);

float JB_f_Fract(float self);

float JB_f_Pow(float self, int n);

bool JB_f_SyntaxAccess(float self);



// hfloat


// int
int SC_int___junktest_8__(int self, int Inaaaadex, bool Create);

int JB_int_Bits(int self);

bool SC_int_IsSimpleOrPointerCast(int self);

Message* JB_int_Msg(int self);

int JB_int_OperatorAlign(int self, int To);

bool JB_int_OperatorIsa(int self, uint n);

int JB_int_OperatorMax(int self, int other);

int JB_int_OperatorMin(int self, int other);

int JB_int_OperatorPow(int self, int a);

IntRange JB_int_OperatorTo(int self, int other);

AsmReg SC_int_Reg(int self);

JB_String* JB_int_RenderFS(int self, FastString* fs_in);

JB_String* JB_int_RenderSize(int self, FastString* fs_in);

bool JB_int_SyntaxAccess(int self, int bit);

int JB_int_SyntaxAccessSet(int self, int bit, bool Value);

int JB_int__Max();

int JB_int__Min();



// int16


// int64
int64 JB_int64_Abs(int64 self);

double JB_int64_AsFloat(int64 self);

JB_String* JB_int64_Hex(int64 self, FastString* fs_in);

Message* JB_int64_Msg(int64 self);

int64 JB_int64_OperatorMax(int64 self, int64 d);

int64 JB_int64_OperatorMin(int64 self, int64 d);

int64 JB_int64_OperatorRotl(int64 self, int Amount);

JB_String* JB_int64_Render(int64 self, FastString* fs_in);

void JB_int64_RenderSizePart(int64 self, FastString* fs, int Size, JB_String* Suff);

JB_String* JB_int64_StrSize(int64 self, FastString* fs_in);



// ivec2
bool JB_ivec2_Equals2(ivec2 self, ivec2 v, bool Aware);



// ivec3


// ivec4
ivec4 SC_ivec4___junktest_4__Set(ivec4 self, int Value);



// uint
bool SC_uint_IsNormalMatch(uint self);

uint JB_uint_LowestBit(uint self);



// uint16


// uint64
ivec2 SC_uint64_LongestBitStretch(uint64 self);

uint64 JB_uint64_LowestBit(uint64 self);



// vec2
vec2 JB_vec2__New2(float a, float b);



// vec3


// vec4


// ASMtmp
bool SC_ASMtmp_SyntaxIs(ASMtmp self, ASMtmp t);

AsmReg SC_ASMtmp__Debugger(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__If(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__Rejoin(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__Return(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__StateExpr(ASMFuncState* self, Message* exp, AsmReg Reg);

AsmReg SC_ASMtmp__While(ASMFuncState* self, Message* exp, AsmReg Reg);



// CharProp


// Codepoint
bool JB_CP_In(Codepoint self, int a, int b);

bool JB_CP_IsHigher(Codepoint self);

bool JB_CP_IsLetter(Codepoint self);

bool JB_CP_IsLower(Codepoint self);

bool JB_CP_IsUpper(Codepoint self);

bool JB_CP_IsWhite(Codepoint self);



// ControlClipMode


// ControlLine


// ControlPoint


// ControlRect


// DataTypeCode
int JB_TC__Shift(DataTypeCode self);

SCClass* SC_TC_Better_Numeric_Sub(DataTypeCode self, DataTypeCode t, OpMode Op);

int JB_TC_ByteSize(DataTypeCode self);

int JB_TC_Count(DataTypeCode self);

SCClass* SC_TC_CreateSignedStuff(DataTypeCode self);

bool JB_TC_ExistsButBadlyNamedOrDesigned(DataTypeCode self);

int SC_TC_FloatIntMerge(DataTypeCode self, int old, Message* s);

bool JB_TC_IsFloat(DataTypeCode self);

bool JB_TC_IsInt(DataTypeCode self);

bool JB_TC_IsSigned(DataTypeCode self);

int JB_TC_ItemBitCount(DataTypeCode self);

int JB_TC_NumericCount(DataTypeCode self);

int JB_TC_NumericCountBoolsToo(DataTypeCode self);

bool JB_TC_SameBasicType(DataTypeCode self, DataTypeCode b);

DataTypeCode JB_TC_SetSigned(DataTypeCode self, bool b);

bool JB_TC_SyntaxIs(DataTypeCode self, DataTypeCode M);

Dictionary* JB_TC__Types();



// Date
Date JB_Date_Ago(Date self);

int JB_Date_DayOfWeek(Date self);

int64 JB_Date_Days(Date self);

JB_String* JB_Date_RenderDurr(Date self, FastString* fs_in);

JB_String* JB_Date_RenderInt(Date self, FastString* fs_in);

double JB_Date_Seconds(Date self);

int64 JB_Date_WholeSeconds(Date self);

Date JB_Date__New0();



// DeclMode
bool SC_DeclMode_SyntaxIs(DeclMode self, DeclMode o);



// DotUseType
bool SC_DotUseType_SyntaxIs(DotUseType self, DotUseType d);



// ErrorFlags


// ErrorInt


// ErrorInt2


// ErrorMarker


// ErrorSeverity
JB_String* JB_ErrorSeverity_Render(ErrorSeverity self, FastString* fs_in);

bool JB_ErrorSeverity_SyntaxIs(ErrorSeverity self, ErrorSeverity e);

ErrorSeverity JB_ErrorSeverity_SyntaxUsing(ErrorSeverity self);

void JB_ErrorSeverity_SyntaxUsingComplete(ErrorSeverity self);

ErrorSeverity JB_ErrorSeverity__Find(JB_String* name, Message* err);

int JB_ErrorSeverity__Init_();

int JB_ErrorSeverity__InitCode_();

Array* JB_ErrorSeverity__InitNames();



// FileDes


// FileMode


// FileResolveMode


// FileSizeInt


// FloatRangeConverter


// FloatRangeConverterBasic


// FlowControlStopper
FlowControlStopper JB_FlowControlStopper_SyntaxUsing(FlowControlStopper self);

void JB_FlowControlStopper_SyntaxUsingComplete(FlowControlStopper self);



// FunctionType


// Ind


// IntRange
bool JB_Rg_Contains1(IntRange self, int i);

int JB_Rg_Width(IntRange self);



// JSM


// MaybeBool
bool JB_MaybeBool_Default(MaybeBool self);

bool JB_MaybeBool_IsFalse(MaybeBool self);

bool JB_MaybeBool_IsKnown(MaybeBool self);

bool JB_MaybeBool_IsTrue(MaybeBool self);

MaybeBool JB_MaybeBool__New(bool Default);



// MoveCode


// MsgParseFlags


// NilCheckMode
NilCheckMode SC_khalai_Activate(NilCheckMode self);

NilCheckMode SC_khalai_Negate(NilCheckMode self);

NilCheckMode SC_khalai_Normal(NilCheckMode self);

bool SC_khalai_SyntaxIs(NilCheckMode self, NilCheckMode other);

NilCheckMode SC_khalai_SyntaxIsSet(NilCheckMode self, NilCheckMode other, bool Value);



// NilReason
bool SC_NilReason_SyntaxIs(NilReason self, NilReason x);

int SC_NilReason__Init_();

int SC_NilReason__InitCode_();



// NilRecord
uint SC_NRD_DepthOfVars(NilRecord self);

void ndb5(NilRecord self);

NilState SC_NRD_SyntaxAccess(NilRecord self, int item);



// NilState
JB_String* SC_NilState_RawName(NilState self);

NilState SC_NilState_StatedReal(NilState self);

bool SC_NilState_SyntaxIs(NilState self, NilState type);



// NumericLoss


// OpMode
bool SC_OpMode_SyntaxIs(OpMode self, OpMode x);



// PID_Int


// ProcessMode
bool JB_ProcessMode_SyntaxIs(ProcessMode self, ProcessMode M);



// SCBlockage
int SC_SCBlockage_BlockCombine(SCBlockage self, SCBlockage B);

bool SC_SCBlockage_SyntaxIs(SCBlockage self, SCBlockage b);



// SCDeclInfo
SCDeclInfo SC_SCDeclInfo_Set(SCDeclInfo self, SCDeclInfo d, bool b);



// SCNodeFindMode
bool SC_SCNodeFindMode_SyntaxIs(SCNodeFindMode self, SCNodeFindMode m);



// SCNodeInfo


// SCNodeType
bool SC_SCNodeType_HasPtrs(SCNodeType self);

bool SC_SCNodeType_SyntaxIs(SCNodeType self, SCNodeType d);



// SizeInt


// Syntax
void JB_Syx_ExportAddrSet(Syntax self, FP_fpMsgRender Value);

FP_fpMsgRender JB_Syx_ExportAddr(Syntax self);

bool JB_Syx_IsString(Syntax self);

bool JB_Syx_ListViewable(Syntax self);

JB_String* JB_Syx_LongName(Syntax self);

Message* JB_Syx_Msg(Syntax self, JB_String* name);

Message* JB_Syx_IntMsg(Syntax self, int64 name);

JB_String* JB_Syx_Name(Syntax self);

bool JB_Syx_NoChildren(Syntax self);

SyntaxObj* JB_Syx_Obj(Syntax self);

Message* JB_Syx_OperatorPlus(Syntax self, JB_String* m);

Message* JB_Syx_PlusNum(Syntax self, int m);

FP_fpMsgRender JB_Syx_RenderAddr(Syntax self);

bool JB_Syx_Translateable(Syntax self);

Syntax JB_Syx__Func(JB_String* name, Message* where);

int JB_Syx__Init_();

int JB_Syx__InitCode_();

Syntax JB_Syx__StdNew(FP_fpMsgRender msg, JB_String* name, JB_String* LongName);



// TaskState


// TerminalColor


// U24_8


// __junktest_7__


// int8


// mat2


// µParam
uint SC_xC2xB5Param_BitSize(ASMParam self);

bool SC_xC2xB5Param_IsNumber(ASMParam self);

bool SC_xC2xB5Param_IsReg(ASMParam self);



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

ASM SC_ASM_R1Set(ASM self, uint Value);

ASM SC_ASM_R2Set(ASM self, uint Value);

ASM SC_ASM_R3Set(ASM self, uint Value);

ASM SC_ASM_R4Set(ASM self, uint Value);

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

int SC_ASM__Init_();

int SC_ASM__InitCode_();

void SC_ASM__ListInstructions();

bool SC_ASM__Needed();

void SC_ASM__TestASM();

void SC_ASM__TestASMSub(Message* tests);



// HumanDate


// ASM_BFLD
ASM JB_ASM_BFLD__Encode(IR* self);



// ASM_Bra
ASM JB_ASM_Bra__Encode(IR* self);



// ASM_CNTC
ASM JB_ASM_CNTC__Encode(IR* self);



// ASM_CNTR
ASM JB_ASM_CNTR__Encode(IR* self);



// ASM_Cmp
ASM JB_ASM_Cmp__Encode(IR* self);



// ASM_CmpEq
ASM JB_ASM_CmpEq__Encode(IR* self);



// ASM_Const
ASM JB_ASM_Const__Encode(IR* self);



// ASM_Func
ASM JB_ASM_Func__Encode(IR* self);



// ASM_Mem
ASM JB_ASM_Mem__Encode(IR* self);



// ASM_SWAP
ASM JB_ASM_SWAP__Encode(IR* self);



// ASM_Setn
ASM JB_ASM_Setn__Encode(IR* self);



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
AsmReg SC_fn_asm__Default(ASMFuncState* self, Message* exp, AsmReg Reg);

void SC_fn_asm__InitTable();



// fpDestructor


// fpMsgRender


// fpMsgRenderCpp


// prototype


// JB_ASMFuncState
void SC_flat_AddFuncParams(ASMFuncState* self, SCFunction* fn);

void SC_flat_AddLabel(ASMFuncState* self, Message* ch);

AsmReg SC_flat_AllocRegDecl(ASMFuncState* self, Message* exp, SCDecl* decl, AsmReg R);

void SC_flat_CloseVars(ASMFuncState* self, uint64 Old);

void JB_flat_Destructor(ASMFuncState* self);

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



// JB_ASMVarType


// JB_ArchonPurger
void SC_nil_BecomeRealSub(ArchonPurger* self, SCDecl* V);

NilRecord SC_nil_BranchEnter(ArchonPurger* self, Message* where);

NilState SC_nil_BranchExit(ArchonPurger* self, NilRecord A);

NilRecord SC_nil_BranchSwap(ArchonPurger* self, NilRecord A);

void SC_nil_CheckNilCheck(ArchonPurger* self, SCFunction* f);

NilState SC_nil_Declare(ArchonPurger* self, SCDecl* D, NilState nd);

NilState SC_nil_DeclareSub(ArchonPurger* self, SCDecl* D, NilState nd);

void JB_nil_Destructor(ArchonPurger* self);

void SC_nil_FinishNil(ArchonPurger* self, SCFunction* f);

int SC_nil_NestDepth(ArchonPurger* self);

NilState SC_nil_Self(ArchonPurger* self);

Message* SC_nil_StartNil(ArchonPurger* self, SCFunction* f);

NilState SC_nil__Access(Message* msg, NilCheckMode Test);

NilState SC_nil__arel(Message* msg, NilCheckMode Test);

NilState SC_nil__Argument(Message* msg, NilCheckMode Test);

NilState SC_nil__BecomeReal(SCDecl* sent, Message* where, NilReason reason, SCDecl* recv, SCFunction* To);

NilState SC_nil__BecomeRealSub(SCDecl* sent, Message* where, NilReason reason, SCDecl* recv, SCFunction* To, NilState curr);

NilState SC_nil__BooleanLogic(Message* msg, NilCheckMode Test);

NilState SC_nil__Bracket(Message* msg, NilCheckMode Test);

NilState SC_nil__Brel(Message* msg, NilCheckMode Test);

NilState SC_nil__Char(Message* msg, NilCheckMode Test);

NilState SC_nil__CompareObjs(Message* ll, Message* rr, NilCheckMode test, SCOperator* scop);

NilState SC_nil__Continue(Message* msg, NilCheckMode Test);

NilState SC_nil__Debugger(Message* msg, NilCheckMode Test);

NilState SC_nil__Declaration(Message* msg, NilCheckMode Test);

NilState SC_nil__DetectStillChecks(Message* first);

NilState SC_nil__Dummy(Message* msg, NilCheckMode Test);

NilState SC_nil__Exit(Message* msg, NilCheckMode Test);

void SC_nil__ExterminateZergBugs(SCFunction* f);

NilState SC_nil__Fail(Message* msg, NilCheckMode Test);

NilState SC_nil__FailedReal(SCFunction* To, Message* where, NilReason reason, NilState state);

void SC_nil__FixArchons();

NilState SC_nil__Function(Message* msg, NilCheckMode Test);

NilState SC_nil__If(Message* msg, NilCheckMode Test);

NilState SC_nil__Ignore(Message* msg, NilCheckMode Test);

int SC_nil__Init_();

int SC_nil__InitCode_();

NilState SC_nil__Item(Message* msg, NilCheckMode Test);

NilState SC_nil__List(Message* msg, NilCheckMode Test);

void ndb4();

void SC_nil__NilParamPass(SCDecl* Recv, SCDecl* Sent, Message* where, SCFunction* f, NilState v);

NilState SC_nil__Not(Message* msg, NilCheckMode Test);

NilState SC_nil__Number(Message* msg, NilCheckMode Test);

NilState SC_nil__ProcessCondRel(Message* msg, NilCheckMode Test);

NilState SC_nil__Property(Message* msg, NilCheckMode Test);

NilState SC_nil__PropertyToFunc(Message* dot, SCFunction* fn);

NilState SC_nil__RealBool(bool b);

NilState SC_nil__Rejoin(Message* msg, NilCheckMode Test);

NilState SC_nil__Rel(Message* msg, NilCheckMode Test);

NilState SC_nil__Return(Message* msg, NilCheckMode Test);

NilState SC_nil__SetRel(Message* msg, NilCheckMode Test);

NilState SC_nil__StatementJump(Message* msg, NilCheckMode Test);

NilState SC_nil__String(Message* msg, NilCheckMode Test);

NilState SC_nil__SuperSmartMagicCompare(Message* ll, Message* rr, NilCheckMode test, SCOperator* scop);

NilState SC_nil__Tern(Message* msg, NilCheckMode Test);

NilState SC_nil__Thing(Message* msg, NilCheckMode Test);

NilState SC_nil__ThingSub(Message* msg, NilCheckMode test, SCDecl* dcl);

void SC_nil__TrackerDummies();

NilState SC_nil__Type(Message* msg, NilCheckMode Test);

NilState SC_nil__UseChildAsReal(Message* msg, NilCheckMode test, NilReason reason);

NilState SC_nil__VariableSet(SCDecl* Recv, Message* RecvMsg, SCDecl* Sent, Message* SentMsg, NilState SentState);

NilState SC_nil__While(Message* msg, NilCheckMode Test);

void SC_nil__WhileInner(Message* Cond);



// JB_ArgArrayCounter
void SC_ArgArrayCounter_Check(ArgArrayCounter* self, Message* exp);

Message* SC_ArgArrayCounter_Do(ArgArrayCounter* self, JB_String* name, Message* item, SCNode* name_space);



// JB_AsmReg


// JB_CharProps


// JB_ClassData
JB_MemoryLayer* JB_ClassData_CreateUseLayer(JB_Class* self, JB_Object* obj, JB_Object* obj2);

void JB_ClassData_Restore(JB_Class* self);



// JB_CompressionStats
void JB_MzSt_Clear(CompressionStats* self);

float JB_MzSt_Durr(CompressionStats* self);

void JB_MzSt_End(CompressionStats* self);

void JB_MzSt_LiveUpdate(CompressionStats* self, int inn, int outt);

void JB_MzSt_Print(CompressionStats* self);

JB_String* JB_MzSt_Render(CompressionStats* self, FastString* fs_in);

void JB_MzSt_Start(CompressionStats* self);

int JB_MzSt__Init_();

int JB_MzSt__InitCode_();



// JB_FakeJBString


// JB_FastBuff
bool JB_FastBuff_Alloc(FastBuff* self, int n);

byte JB_FastBuff_Byte(FastBuff* self);

byte* JB_FastBuff_Clip(FastBuff* self, int v, int reduce);

uint JB_FastBuff_CopyTo(FastBuff* self, byte* Dest, int Length);

void JB_FastBuff_Destructor(FastBuff* self);

bool JB_FastBuff_Has(FastBuff* self, int n);

bool JB_FastBuff_HasAny(FastBuff* self);

int JB_FastBuff_Length(FastBuff* self);

bool JB_FastBuff_NeedAlloc(FastBuff* self, int n);

int64 JB_FastBuff_Position(FastBuff* self);

void JB_FastBuff_PositionSet(FastBuff* self, int64 Value);

void JB_FastBuff_ReadFromSet(FastBuff* self, JB_String* Value);

int64 JB_FastBuff_Remaining(FastBuff* self);

int JB_FastBuff_Size(FastBuff* self);

JB_String* JB_FastBuff_AccessStr(FastBuff* self, int pos, int after);

void JB_FastBuff_SyntaxExpect(FastBuff* self, JB_String* s);

JB_String* JB_FastBuff_TmpStr(FastBuff* self);



// JB_FloatRange


// JB_GameFlyingMem


// JB_IR
void SC_IR_AddRegParam(IR* self, Message* src, uint write);

Ind SC_IR_BytePos(IR* self);

void SC_IR_DebugSet(IR* self, Message* Value);

ASM SC_IR_Encode(IR* self);

JB_String* SC_IR_File(IR* self);

int SC_IR_FilePos(IR* self);

void SC_IR_FS(IR* self, FastString* fs);

bool SC_IR_OperatorIsa(IR* self, int m);

void SC_IR_Print(IR* self);

JB_String* SC_IR_Render(IR* self, FastString* fs_in);

void SC_IR_SyntaxExpect(IR* self, JB_String* Error);

int SC_IR__Init_();

int SC_IR__InitCode_();



// JB_IntDownRange


// JB_IsaTester
int SC_IsaTester__Init_();

int SC_IsaTester__InitCode_();

void SC_IsaTester__SyntaxAppend(Message* o);



// JB_LoopInfo
LoopInfo SC_LoopInfo_BeginLoop(LoopInfo* self, bool HasExitCond);

void SC_LoopInfo_FinishLoop(LoopInfo* self, Message* msg);

void SC_LoopInfo_NextLoop(LoopInfo* self);



// JB_Mat4


// JB_MemoryWorld


// JB_MessagePosition
void JB_MsgPos_Destructor(MessagePosition* self);

void JB_MsgPos_SyntaxUsingComplete(MessagePosition* self);



// JB_ModelTest


// JB_NameAndMsg
void JB_NameAndMsg_Destructor(NameAndMsg* self);

void SC_NameAndMsg_SyntaxAppend(NameAndMsg* self, Message* m);



// JB_NilRecorder
void SC_NRC_SyntaxCallSet(NilRecorder* self, uint64 item, uint64 value);



// JB_ObjectLoader
void JB_LD_Destructor(ObjectLoader* self);

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

int JB_LD__Init_();

int JB_LD__InitCode_();

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



// JB_Object_Behaviour


// JB_ParserLineAndIndent


// JB_Pico
JB_String* JB_Pico_Get(PicoComms* self, float T);

bool JB_Pico_SendFS(PicoComms* self, FastString* fs, bool Wait);

int JB_Pico__Init_();

int JB_Pico__InitCode_();

PicoComms* JB_Pico__New(JB_StringC* name, int bits);

PicoComms* JB_Pico__Parent();



// JB_PicoConfig


// JB_PicoGlobalConfig


// JB_PicoGlobalStats


// JB_PicoMessage
PicoMessage JB_Pico__FromFS(FastString* fs);



// JB_Random
double JB_Rnd_Double(Random* self);

float JB_Rnd_Float(Random* self);

int64 JB_Rnd_RndInt(Random* self);

void JB_Rnd_LoadProperties(Random* self, ObjectLoader* Loader);

void JB_Rnd_SaveWrite(Random* self, ObjectSaver* Saver);

void JB_Rnd_SeedSet(Random* self, uint64 Value);

double JB_Rnd_SyntaxAccess(Random* self);

void JB_Rnd_TimeSeed(Random* self);

int JB_Rnd__Init_();

int JB_Rnd__InitCode_();



// JB_RetroFloat


// JB_SpeedTester


// JB_StringDigitIterator


// JB_StringLengthSplit


// JB_StructSaveTest
void JB_StructSaveTest_Destructor(StructSaveTest* self);

void JB_StructSaveTest_LoadProperties(StructSaveTest* self, ObjectLoader* Loader);

void JB_StructSaveTest_SaveWrite(StructSaveTest* self, ObjectSaver* Saver);



// JB_jb_vm


// JB_uint24


// JB_ContainerStruct2


// JB_ContainerStruct


// JB_ByteMap_Behaviour


// JB_Charset_Behaviour


// JB_CppRefs_Behaviour


// JB_Cpp_Export_Behaviour


// JB_DataObject_Behaviour


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


// JB_MaterialsLol_Behaviour


// JB_Process_Behaviour


// JB_SCNamed_Behaviour


// JB_SavingTest_Behaviour


// JB_StringShared_Behaviour


// JB_StringZeroTerminated_Behaviour


// JB_list_Behaviour


// JB_µFunc1_Behaviour


// JB_MessageID_Behaviour


// JB_Message_Behaviour


// JB_SCDecl_Behaviour


// JB_SCFile_Behaviour


// JB_SCIterator_Behaviour


// JB_SCNode_Behaviour


// JB_SaverClassInfo_Behaviour


// JB_SimpleGraph_Behaviour


// JB_SpdProcess_Behaviour


// JB_Task_Behaviour


// JB_Error_Behaviour


// JB_SCArg_Behaviour


// JB_SCBehaviour_Behaviour


// JB_SCClass_Behaviour


// JB_SCFunction_Behaviour


// JB_SCModule_Behaviour


// JB_Object
SCDecl* SC_Object_AsDecl(JB_Object* self);

SCDecl* SC_Object_BaseAsDecl(JB_Object* self);

SCNode* SC_Object_ClassOrModule(JB_Object* self);

void jdb(JB_Object* self);

bool JB_Object_MustBe(JB_Object* self, JB_Class* x, Message* ErrNode);

JB_Object* JB_Object_As(JB_Object* self, JB_Class* x);

JB_Object* JB_Object_FastAs(JB_Object* self, JB_Class* x);

bool JB_Object_FastIsa(JB_Object* self, JB_Class* x);

bool JB_Object_Isa(JB_Object* self, JB_Class* cls);

bool JB_Object_OperatorMustBe(JB_Object* self, JB_Class* x);

void JB_Object_SaveTryCollect(JB_Object* self, ObjectSaver* Saver);

void JB_Object_Fail(JB_Object* self, JB_String* Error);

void JB_Object_SyntaxExpect(JB_Object* self);

JB_Object* JB_Object_TypeFailed(JB_Object* self, JB_Class* Cls, Message* where);



// JB_AppArgument
JB_String* JB_AppArgument_Name(JB_Object* self);

JB_String* JB_AppArgument_Value(JB_Object* self);



// JB_ByteMap


// JB_Charset
Array* JB_CS_Bytes(CharSet* self);

bool JB_CS_NextInCharset(CharSet* self, int* p);

bool JB_CS_OperatorContains(CharSet* self, JB_String* Data);



// JB_CppRefs
void SC_CppRefs_AddOne(CppRefs* self, Message* C);

CppRefs* SC_CppRefs_Constructor(CppRefs* self, Message* s);

void JB_CppRefs_Destructor(CppRefs* self);

Array* SC_CppRefs_DisturbsGet(CppRefs* self);

void SC_CppRefs_Read(CppRefs* self, Message* node);

void SC_CppRefs_SetDefaultRefStatus(CppRefs* self);

SCNode* SC_CppRefs__Linkage(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_CppRefs__ReadIntoCppRefs(Message* node, SCNode* name_space, Message* ErrPlace);



// JB_Cpp_Export
void SC_Cpp_AppendCppField(Cpp_Export* self, JB_String* prop, FastStringCpp* fs);

void SC_Cpp_AppendPropField(Cpp_Export* self, SCDecl* prop, FastStringCpp* fs);

bool SC_Cpp_CanExportFunc(Cpp_Export* self, SCFunction* F);

bool SC_Cpp_CanOpt(Cpp_Export* self, bool force);

void SC_Cpp_Codify(Cpp_Export* self, SCModule* scb, JB_String* fName);

void SC_Cpp_CodifyFuncs(Cpp_Export* self, FastStringCpp* file, Array* list);

void SC_Cpp_CodifyInlines(Cpp_Export* self);

Cpp_Export* SC_Cpp_Constructor(Cpp_Export* self);

void SC_Cpp_CppFunc(Cpp_Export* self, FastStringCpp* fs, SCFunction* F);

void JB_Cpp_Destructor(Cpp_Export* self);

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

JB_String* SC_Cpp_FuncHeader(Cpp_Export* self, FastStringCpp* fs, SCFunction* F);

void SC_Cpp_FuncStart(Cpp_Export* self, FastStringCpp* fs, SCFunction* f, JB_String* funcheader);

void SC_Cpp_ListAllClasses(Cpp_Export* self, FastStringCpp* fs);

void SC_Cpp_ListAllFuncs(Cpp_Export* self, FastStringCpp* fs);

void SC_Cpp_MakeWrapperFor(Cpp_Export* self, FastStringCpp* fs, SCFunction* f);

void SC_Cpp_OptEnd(Cpp_Export* self, FastStringCpp* fs, int m, bool force);

void SC_Cpp_OptStart(Cpp_Export* self, FastStringCpp* fs, int m, bool force);

void SC_Cpp_PreRun(Cpp_Export* self);

void SC_Cpp_Run(Cpp_Export* self);

void SC_Cpp_SetupFlow(Cpp_Export* self, SCFunction* f);

FastStringCpp* SC_Cpp_StreamChild(Cpp_Export* self, JB_String* s);

void SC_Cpp_WriteAPIFuncHeader(Cpp_Export* self, SCFunction* F, FastStringCpp* fs);

void SC_Cpp_WriteAPIHeader(Cpp_Export* self, JB_File* destfile);

void SC_Cpp_WriteHeader(Cpp_Export* self);

JB_File* SC_Cpp__APIHeader();

void SC_Cpp__C_FSListComma(Message* self, FastStringCpp* fs);

bool SC_Cpp__C_OneParamType(FastStringCpp* fs, Message* Curr, SCDecl* D);

void SC_Cpp__C_ParamsRender(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderAcc(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderArel(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderArg(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderBak(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderBra(Message* self, FastStringCpp* fs);

void SC_Cpp__C_RenderBrel(Message* self, FastStringCpp* fs);

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

JB_File* SC_Cpp__Product(JB_String* name);

void SC_Cpp__RenderInBracketsIfRel(Message* self, FastStringCpp* fs);

void SC_Cpp__SmartWrite(JB_String* S, JB_File* F);

JB_String* SC_Cpp__SplitCpp(FastStringCpp* fs, JB_String* name);

void SC_Cpp__WriteClass(SCClass* C, FastStringCpp* T);

void SC_Cpp__WriteConst(SCDecl* D, FastStringCpp* T);

void SC_Cpp__WriteDecl(SCDecl* D, FastStringCpp* T, Message* equality);

void SC_Cpp__WriteDeclBrackets(Message* self, FastStringCpp* fs);

void SC_Cpp__WriteDeclNoName(SCDecl* D, FastStringCpp* T);

void SC_Cpp__WriteFuncArgs(SCFunction* F, FastStringCpp* T, bool names_only);

void SC_Cpp__WriteFuncSub(SCFunction* F, JB_String* E, FastStringCpp* T);

void SC_Cpp__WriteFunctionHeader(SCFunction* F, FastStringCpp* T);

void SC_Cpp__WriteName(JB_String* name, FastString* blob, FastString* lengths);

JB_String* SC_Cpp__WriteStrings(FastString* Lengths);

void SC_Cpp__WriteThgMaybeTypeToo(Message* msg, SCDecl* d, FastStringCpp* fs);

void SC_Cpp__WriteType(SCClass* c, FastStringCpp* fs, bool always);



// JB_DataObject
DTWrap* JB_Wrap_ConstructorInt(DTWrap* self, int64 v);

DTWrap* JB_Wrap_ConstructorVoidPtr(DTWrap* self, void* p);

void JB_Wrap_Destructor(DTWrap* self);

int64 JB_Wrap_First(DTWrap* self);

double JB_Wrap_FloatValue(DTWrap* self);

JB_String* JB_Wrap_Render(DTWrap* self, FastString* fs_in);

int64 JB_Wrap_Value(DTWrap* self);



// JB_DictionaryReader
JB_Object* JB_DictionaryReader_NextValue(DictionaryReader* self);

SCDecl* SC_DictionaryReader_ValueDecl(DictionaryReader* self);



// JB_ErrorReceiver
int JB_Rec_BadCount(JB_ErrorReceiver* self);

bool JB_Rec_CanAddMore(JB_ErrorReceiver* self, ErrorSeverity level);

void JB_Rec_Clear(JB_ErrorReceiver* self);

JB_ErrorReceiver* JB_Rec_Constructor(JB_ErrorReceiver* self);

void JB_Rec_Destructor(JB_ErrorReceiver* self);

bool JB_Rec_HasAnything(JB_ErrorReceiver* self);

bool JB_Rec_HasProblems(JB_ErrorReceiver* self);

void JB_Rec_Incr(JB_ErrorReceiver* self, JB_Error* err, bool add);

JB_Error* JB_Rec_LastError(JB_ErrorReceiver* self);

void JB_Rec_LogFileWriter(JB_ErrorReceiver* self, JB_String* Data);

ErrorMarker JB_Rec_Mark(JB_ErrorReceiver* self);

bool JB_Rec_OK(JB_ErrorReceiver* self);

JB_Error* JB_Rec_Pop(JB_ErrorReceiver* self);

void SC_Rec_PrePrintErrors(JB_ErrorReceiver* self);

int JB_Rec_PrintErrorsMain(JB_ErrorReceiver* self, ErrorSeverity Level, bool PrintCount, bool shell);

JB_String* JB_Rec_Render(JB_ErrorReceiver* self, FastString* fs_in);

int JB_Rec_RenderErrors(JB_ErrorReceiver* self, FastString* fs, ErrorSeverity Level, bool shell);

int SC_Rec_ReturnErrors(JB_ErrorReceiver* self, JB_ErrorReceiver* To);

int JB_Rec_ShellPrintErrors(JB_ErrorReceiver* self);

void JB_Rec_AppendErr(JB_ErrorReceiver* self, JB_Error* Err);

JB_ErrorReceiver* JB_Rec_SyntaxUsing(JB_ErrorReceiver* self);

void JB_Rec_SyntaxUsingComplete(JB_ErrorReceiver* self);

int JB_Rec__Init_();

int JB_Rec__InitCode_();

void JB_Rec__NewErrorWithNode(Message* node, JB_String* Desc, JB_String* path);

void JB_Rec__NewErrorSub(Message* node, JB_String* Desc, JB_String* path, int sev);

void JB_Rec__NewProblem(Message* node, JB_String* Desc, JB_String* path);

void JB_Rec__NewWarning(Message* node, JB_String* Desc, JB_String* path);



// JB_FastString
void SC_FS_AppendCpp(FastString* self, JB_String* s);

void SC_FS_AppendCppAll(FastString* self, JB_String* s);

void JB_FS_AppendEscape(FastString* self, JB_String* s);

void JB_FS_AppendHexStr(FastString* self, JB_String* Data);

void JB_FS_AppendObjectID(FastString* self, Saveable* o);

void JB_FS_AppendObjectOrNil(FastString* self, JB_Object* o);

void JB_FS_AppendQuotedEscape(FastString* self, JB_String* s);

void SC_FS_AppendWidth(FastString* self, JB_String* s, int Width);

void SC_FS_CArrayAdd(FastString* self, JB_String* s);

void SC_FS_CArrayAddB(FastString* self, byte B);

void SC_FS_CArrayAddB0(FastString* self, byte B);

void JB_FS_EncodeLength(FastString* self, uint64 N);

void JB_FS_AppendInfo(FastString* self, JB_String* name, JB_String* data);

void JB_FS_AppendInfoNum(FastString* self, JB_String* name, int64 data);

void JB_FS_AppendInfoFloat(FastString* self, JB_String* name, double data);

void JB_FS_FieldStart(FastString* self, JB_String* name);

void JB_FS_hInt(FastString* self, uint64 n);

void SC_FS_IncludeH(FastString* self, JB_String* name);

void JB_FS_lInt(FastString* self, uint64 n);

void JB_FS_MsgErrorName(FastString* self, JB_String* name);

void JB_FS_Normal(FastString* self, JB_String* s);

void JB_FS_PrintNicely(FastString* self, JB_String* s);

void JB_FS_ProblemsFound(FastString* self, int count);

JB_String* JB_FS_Render(FastString* self, FastString* fs_in);

void JB_FS_RenderSpeed(FastString* self, float seconds, int64 BytesIn, int64 BytesOut, JB_String* Name);

void JB_FS_AppendMultiStr(FastString* self, JB_String* data, int count);

void JB_FS_AppendFastString(FastString* self, FastString* fs);

void JB_FS_AppendInt64(FastString* self, int64 data);

void JB_FS_AppendInt32(FastString* self, int data);

void JB_FS_AppendFloatAsText(FastString* self, float F);

void JB_FS_AppendBool(FastString* self, bool B);

void JB_FS_SyntaxAppend(FastString* self, Message* msg);

FastString* JB_FS__Use(JB_Object* other);



// JB_FileComparer


// JB_FixedDict


// JB_FlowControl
void JB_Flow_AddByte(FlowControl* self, byte value);

bool JB_Flow_Cond(FlowControl* self, byte value);

FlowControl* JB_Flow_Constructor(FlowControl* self);

void JB_Flow_Destructor(FlowControl* self);

void JB_Flow_Fail(FlowControl* self, JB_String* found, JB_String* expected, JB_String* InputName);

void JB_Flow_Flush(FlowControl* self);

void JB_Flow_Init(FlowControl* self, JB_String* path, JB_String* DateStr);

bool JB_Flow_LoadPath(FlowControl* self, JB_String* path, bool IsPrev);

FlowControlStopper JB_Flow__FlowAllow(JB_String* name, uint64 StartCode);

int JB_Flow__Init_();

int JB_Flow__InitCode_();

bool JB_Flow__InputStrings(Array* lines, JB_String* name);

void JB_Flow__Input(JB_String* data, JB_String* name);

void JB_Flow__Stop();

bool JB_Flow__Cond(bool value);



// JB_Instruction
void SC_Instruction_Const(Instruction* self);

Instruction* SC_Instruction_Constructor(Instruction* self, JB_String* FormName, JB_String* name, int pos);

void JB_Instruction_Destructor(Instruction* self);

bool SC_Instruction_IsSetConst(Instruction* self);

JB_String* SC_Instruction_Render(Instruction* self, FastString* fs_in);

void SC_Instruction__Add(JB_String* FormName, JB_String* name, int pos);

int SC_Instruction__Init_();

int SC_Instruction__InitCode_();

void SC_Instruction__InstructionInit();

Instruction* SC_Instruction__SyntaxAccessWithMsg(Message* m);

Instruction* SC_Instruction__SyntaxAccessWithInt(int pos);



// JB_LeakTester
LeakTester* JB_Lk_Constructor(LeakTester* self, JB_String* name);

void JB_Lk_Destructor(LeakTester* self);

void JB_Lk_FinalTest(LeakTester* self);

void JB_Lk_Test2(LeakTester* self);



// JB_Macro
Macro* SC_Macro_clean(Macro* self);

Macro* JB_Macro_ConstructorStr(Macro* self, JB_String* s);

Macro* JB_Macro_ConstructorMsg(Macro* self, Message* s);

void JB_Macro_Destructor(Macro* self);

Message* JB_Macro_Run(Macro* self, Array* prms);

Message* JB_Macro_CallFast(Macro* self, Message* prm1, Message* prm2);

Message* JB_Macro_Source(Macro* self);

int JB_Macro__Init_();

int JB_Macro__InitCode_();



// JB_Memory
void JB_Mrap_CapacitySet(MWrap* self, int Value);

MWrap* JB_Mrap_ConstructorPtr(MWrap* self, int ItemCount, uint ItemSize, byte* ptr, byte DeathAction);

void JB_Mrap_Destructor(MWrap* self);

byte* JB_Mrap_Ptr(MWrap* self);

bool JB_Mrap_SetCap(MWrap* self, int value);

Array* JB_Mrap__CollectLeaks_(JB_Object* self);

int JB_Mrap__Init_();

int JB_Mrap__InitCode_();

MWrap* JB_Mrap__Object(int Count, int ItemSize);

void jbl(JB_Object* self);

byte* JB_Mrap__Zalloc(int n);



// JB_MemoryLayer


// JB_NilTest
NilTest* SC_NilTest_Constructor(NilTest* self);

void JB_NilTest_Destructor(NilTest* self);

NilTest* SC_NilTest_Exists3(NilTest* self, NilTest* p);

NilTest* SC_NilTest_Exists4(NilTest* self);

NilTest* SC_NilTest_Exists5(NilTest* self);

NilTest* SC_NilTest_Exists7(NilTest* self);

int SC_NilTest__Init_();

int SC_NilTest__InitCode_();



// JB_ProcessOwner
bool JB_PID_IsRunning(ProcessOwner* self);



// JB_SCImport
bool SC_Imp_CanBan(SCImport* self, SCFile* scf);

SCImport* SC_Imp_Constructor(SCImport* self, JB_File* F, bool Builtin);

void JB_Imp_Destructor(SCImport* self);

SCFile* SC_Imp_ImportDir(SCImport* self, JB_File* f);

void SC_Imp_ImportMsg(SCImport* self, Message* j);

SCFile* SC_Imp_ImportSpd(SCImport* self, JB_File* c);

void SC_Imp_IncludeCHeaders(SCImport* self, JB_File* f, Array* output);

void SC_Imp_IndexConf(SCImport* self, Message* conf);

void SC_Imp_IndexLinkage(SCImport* self, Message* link, SCFile* scf);

void SC_Imp_IndexTargets(SCImport* self, Message* tar);

void SC_Imp_LoadBanned(SCImport* self, Message* list);

void SC_Imp_LoadConf(SCImport* self, SCFile* scf);

void SC_Imp_PrepareAll(SCImport* self);

void SC_Imp_ReloadImports(SCImport* self, SCFile* index);

JB_String* SC_Imp_Render(SCImport* self, FastString* fs_in);

void SC_Imp_Use(SCImport* self);

void SC_Imp__ExportShaders();

SCImport* SC_Imp__FindImport(JB_String* s);

JB_File* SC_Imp__FindInputFolder(JB_File* f);

SCImport* SC_Imp__ImportPath(JB_String* path, JB_File* f, int ImportDepth, bool Builtin);

int SC_Imp__Init_();

int SC_Imp__InitCode_();

bool SC_Imp__IsInputName(JB_String* name);

void SC_Imp__NoProj();



// JB_SCNodeRenamer
void SC_NR_Collect(SCNodeRenamer* self, Message* msg, JB_String* name, Message* after);

void SC_NR_CollectDclThg(SCNodeRenamer* self, Message* DclThg);

void SC_NR_CollectSelfs(SCNodeRenamer* self, Message* root);

SCNodeRenamer* JB_NR_Constructor(SCNodeRenamer* self);

void JB_NR_Destructor(SCNodeRenamer* self);

void SC_NR_Rename(SCNodeRenamer* self, Message* name);

void SC_NR_Uniqueify(SCNodeRenamer* self, SCNode* p);



// JB_SCObject
Message* SC_SCObject_AnySource(SCObject* self);

int SC_SCObject_Auto_Type(SCObject* self);

int SC_SCObject_AutoCompleteType(SCObject* self);

JB_String* SC_SCObject_BaseIcon(SCObject* self);

JB_String* SC_SCObject_CallFromName(SCObject* self);

JB_String* SC_SCObject_CanAuto(SCObject* self, JB_String* search);

JB_String* SC_SCObject_CanAutoSub(SCObject* self, JB_String* search);

SCObject* SC_SCObject_Constructor(SCObject* self);

void JB_SCObject_Destructor(SCObject* self);

SCFunction* SC_SCObject_Disambiguate(SCObject* self, Message* src);

JB_String* SC_SCObject_Display(SCObject* self, bool exact);

SCFile* SC_SCObject_File(SCObject* self);

bool SC_SCObject_IsVisible(SCObject* self);

void SC_SCObject_IsVisibleSet(SCObject* self, bool Value);

SCObject* SC_SCObject_NextDisplay(SCObject* self, bool exact);

void SC_SCObject_Fail(SCObject* self, JB_String* Error);

bool SC_SCObject_SyntaxIs(SCObject* self, SCNodeInfo i);

void SC_SCObject_SyntaxIsSet(SCObject* self, SCNodeInfo i, bool Value);



// JB_SCOperator
JB_String* SC_Opp_CaseAwareStr(SCOperator* self);

SCOperator* SC_Opp_Constructor(SCOperator* self, JB_String* name, fn_OpASM ASM, OpMode mode);

void JB_Opp_Destructor(SCOperator* self);

void SC_Opp_InitComp(SCOperator* self, JB_String* name_);

bool SC_Opp_IsCompSet(SCOperator* self);

void SC_Opp_SetFuncNameSet(SCOperator* self, JB_String* s);

JB_String* SC_Opp_SimpleName(SCOperator* self);

bool SC_Opp_SyntaxEquals(SCOperator* self, JB_String* s, bool aware);

OpMode SC_Opp_SyntaxIs(SCOperator* self, OpMode x);

void SC_Opp__AddAssign(JB_String* s);

void SC_Opp__AddBit(JB_String* s, JB_String* FuncName, fn_OpASM ASM, OpMode Mode);

void SC_Opp__AddComp(JB_String* s, fn_OpASM ASM, OpMode Mode);

SCOperator* SC_Opp__AddCustom(JB_String* s);

SCOperator* SC_Opp__AddMath(JB_String* s, JB_String* FuncName, fn_OpASM ASM, OpMode Mode);

void SC_Opp__BuildOrder();

void SC_Opp__Init();

int SC_Opp__Init_();

int SC_Opp__InitCode_();

SCOperator* SC_Opp__Lookup(Message* opch);

void SC_Opp__OppositeComp(JB_String* A, JB_String* B);



// JB_SCParamArray
void SC_PA_AddParam(SCParamArray* self, Message* item);

void SC_PA_addsub(SCParamArray* self, Message* m);

bool SC_PA_AddTestedParam(SCParamArray* self, Message* item, SCNode* name_space);

SCFunction* SC_PA_ArgsMatchError(SCParamArray* self, int TypeCast, SCFunction* f, SCFunction* R);

SCParamArray* SC_PA_Constructor(SCParamArray* self, Message* exp);

Array* SC_PA_CopyArgs(SCParamArray* self);

SCNode* SC_PA_DetectDotSuper(SCParamArray* self, SCNode* curr, SCNode* arg_space);

int SC_PA_IgnoreSelfContain(SCParamArray* self);

bool SC_PA_IsModule(SCParamArray* self);

bool SC_PA_IsSelfCon(SCParamArray* self);

int SC_PA_MacroSize(SCParamArray* self);

bool SC_PA_MadeError(SCParamArray* self);

JB_String* SC_PA_ModuleName(SCParamArray* self);

bool SC_PA_PreReadTypes(SCParamArray* self, SCNode* Name_Space, Message* P, Message* side);

JB_String* SC_PA_Render(SCParamArray* self, FastString* fs_in);

JB_String* SC_PA_RenderKind(SCParamArray* self);

void SC_PA_SideSet(SCParamArray* self, Message* Value);

Message* SC_PA_SyntaxAccess(SCParamArray* self, int i);



// JB_Saveable
bool JB_Sav_IsSaveMarked(Saveable* self);

void JB_Sav_LoadProperties(Saveable* self, ObjectLoader* Loader);

void JB_Sav_SaveCollect(Saveable* self, ObjectSaver* Saver);

bool JB_Sav_SaveMark(Saveable* self);

SaverClassInfo* JB_Sav_SaverInfo(Saveable* self);

void JB_Sav_SaveToFile(Saveable* self, JB_File* f);

JB_String* JB_Sav_SaveTo(Saveable* self, FastString* fs_in);

void JB_Sav_SaveUnMark(Saveable* self);

void JB_Sav_SaveWrite(Saveable* self, ObjectSaver* Saver);



// JB_Selector
Selector* JB_Sel_Constructor(Selector* self, Selector* Next, Selector** Place, JB_String* name);

void JB_Sel_Destructor(Selector* self);

void JB_Sel_GiveIDs(Selector* self);



// JB_String
JB_String* JB_Str_AddExt(JB_String* self, JB_String* ext);

JB_String* JB_Str_AfterByte(JB_String* self, byte b, int Last);

JB_String* JB_Str_ArgName(JB_String* self);

JB_String* SC_Str_ArgsMatchError(JB_String* self, bool TypeCast);

JB_String* JB_Str_ArgValue(JB_String* self);

uint SC_Str_ASMint(JB_String* self);

JB_String* SC_Str_ASMNormalise(JB_String* self);

JB_String* JB_Str_BackToApp(JB_String* self);

JB_String* JB_Str_Before(JB_String* self, JB_String* s);

JB_String* JB_Str_BeforeLastByte(JB_String* self, byte b, int fudge);

Array* JB_Str_ByteSplit(JB_String* self);

CharSet* JB_Str_CharSetWithBool(JB_String* self, bool Range);

JB_String* JB_Str_Child(JB_String* self, JB_String* cname);

Array* JB_Str_Components(JB_String* self);

JB_String* JB_Str_Compress(JB_String* self, int Strength, CompressionStats* st);

void JB_Str_CompressInto(JB_String* self, JB_Object* fs, int Strength, CompressionStats* st);

bool JB_Str_CompressTest(JB_String* self, bool report, int which);

bool JB_Str_CompressTestSub(JB_String* self, int Strength, bool report);

JB_String* SC_Str_ContainerName(JB_String* self, JB_String* ext);

ErrorInt JB_Str_CopyFileTo(JB_String* self, JB_String* Dest, bool AttrOnly);

int JB_Str_Count(JB_String* self, byte b);

ErrorInt2 SC_Str_DebugExecute(JB_String* self, Array* Args, FastString* Out, FastString* Errs);

void SC_Str_DebugFunc(JB_String* self);

JB_String* JB_Str_Decompress(JB_String* self, int lim, CompressionStats* st);

Dictionary* JB_Str_Dict(JB_String* self, byte sep);

JB_String* JB_Str_Digest(JB_String* self);

bool JB_Str_EndsWith(JB_String* self, JB_String* s, bool aware);

JB_String* JB_Str_Escape(JB_String* self);

JB_String* JB_Str_EscapeChr(JB_String* self);

bool JB_Str_EscapeTest(JB_String* self);

Ind JB_Str_ExecuteableJBin(JB_String* self);

JB_String* JB_Str_Ext(JB_String* self);

JB_File* JB_Str_AsFile(JB_String* self);

JB_File* JB_Str_ChildFile(JB_String* self, JB_String* ch);

bool JB_Str_FileExists(JB_String* self);

int64 JB_Str_FileSize(JB_String* self);

JB_File* JB_Str_FileThatExists(JB_String* self, JB_String* operation);

Ind JB_Str_FindByte(JB_String* self, byte find, int Start, int After);

Ind JB_Str_Find(JB_String* self, CharSet* cs, int Start, int After);

Ind JB_Str_FindSlash(JB_String* self, int from);

int JB_Str_FindTrailingSlashes(JB_String* self);

int64 JB_Str_Int(JB_String* self);

JB_String* SC_Str_InterfaceToBehaviour(JB_String* self);

Ind JB_Str_InWhite(JB_String* self, int Start, int After);

bool SC_Str_isCLike(JB_String* self);

bool JB_Str_IsCompressed(JB_String* self);

int JB_Str_IsHexLike(JB_String* self, int N);

bool JB_Str_IsInt(JB_String* self);

bool JB_Str_IsIntFrom(JB_String* self, int i);

bool JB_Str_IsJbin(JB_String* self);

bool JB_Str_IsLower(JB_String* self);

bool SC_Str_Isnull(JB_String* self);

bool JB_Str_IsOK(JB_String* self);

bool SC_Str_IsOKForImport(JB_String* self);

bool SC_Str_IsSpeedieSrc(JB_String* self);

bool JB_Str_IsStatementName(JB_String* self);

int SC_Str_IsSwizzle(JB_String* self, int Width);

bool SC_Str_IsZero(JB_String* self);

Ind JB_Str_JBFind(JB_String* self, byte find, int Off, int After);

byte JB_Str_Last(JB_String* self, int minus);

int JB_Str_LineCount(JB_String* self);

JB_File* SC_Str_MakeAndGoInto(JB_String* self);

ErrorInt JB_Str_MakeEntirePath(JB_String* self, bool Last);

JB_String* JB_Str_Moat(JB_String* self);

Message* JB_Str_Msg(JB_String* self);

JB_String* JB_Str_Name(JB_String* self);

bool JB_Str_ContainsString(JB_String* self, JB_String* s);

bool JB_Str_ContainsByte(JB_String* self, byte b);

Array* JB_Str_OperatorDivide(JB_String* self, byte sep);

bool JB_Str_OperatorEndsWith(JB_String* self, JB_String* s);

bool JB_Str_OperatorIsa(JB_String* self, JB_String* s);

int JB_Str_OperatorMinus(JB_String* self, JB_String* s);

JB_String* JB_Str_MulBool(JB_String* self, bool b);

JB_String* JB_Str_OperatorMul(JB_String* self, int n);

JB_String* JB_Str_PlusByte(JB_String* self, byte B);

JB_String* JB_Str_OperatorPlusWithCstring(JB_String* self, _cstring c);

bool JB_Str_OperatorStarts(JB_String* self, JB_String* s);

bool SC_Str_OptionBool(JB_String* self);

int SC_Str_OptionInt(JB_String* self);

FastString* JB_Str_Out(JB_String* self, bool Clear);

Ind JB_Str_OutByteWithByteIntInt(JB_String* self, byte find, int Start, int After);

Ind JB_Str_OutCharSet(JB_String* self, CharSet* cs, int Start, int After);

Ind JB_Str_OutWhite(JB_String* self, int Start, int After);

JB_String* JB_Str_Parent(JB_String* self);

Message* JB_Str_Parse(JB_String* self, Syntax owner, bool AllowDecomp);

Message* SC_Str_ParseClean(JB_String* self);

Message* SC_Str_ParseCleanWipe(JB_String* self);

Message* JB_Str_ParseJbin(JB_String* self, int64 max);

Message* JB_Str_ParseWithError(JB_String* self, JB_Error** rec);

JB_String* JB_Str_PathDir(JB_String* self);

JB_String* JB_Str_Preview(JB_String* self, int N);

void JB_Str_PrintlineColor(JB_String* self, JB_String* color);

JB_String* JB_Str_ReadFile(JB_String* self, int lim, bool AllowMissing);

JB_String* JB_Str_ReplacePathComponent(JB_String* self, int num, JB_String* With);

JB_String* SC_Str_ResolveSpd(JB_String* self);

void SC_Str_Safe(JB_String* self, FastString* fs);

JB_String* SC_Str_ScriptContainer(JB_String* self, JB_String* container);

JB_String* SC_Str_ScriptLocation(JB_String* self, JB_String* container);

JB_String* JB_Str_Sibling(JB_String* self, JB_String* name);

ErrorInt2 JB_Str_SilentExecute(JB_String* self, Array* Args, FastString* Out, FastString* Errs);

JB_String* SC_Str_SpdScriptName(JB_String* self);

Array* JB_Str_Split(JB_String* self, byte sep);

JB_String* JB_Str_Squeeze(JB_String* self);

StringReader* JB_Str_Stream(JB_String* self);

JB_String* JB_Str_SyntaxAccess(JB_String* self, JB_String* s);

bool JB_Str_SyntaxAppend(JB_String* self, JB_String* s);

int JB_Str_CompareStr(JB_String* self, JB_String* Other, bool Aware);

int JB_Str_CompareInt(JB_String* self, int Other, bool Aware);

bool JB_Str_EqualsInt(JB_String* self, int Other, bool Aware);

void JB_Str_SyntaxExpect(JB_String* self);

JB_String* JB_Str_TitleCase(JB_String* self, FastString* fs_in);

JB_String* JB_Str_Shorten(JB_String* self, int n);

JB_String* JB_Str_TrimExtAndPath(JB_String* self, bool KeepPath);

JB_String* JB_Str_TrimFirst(JB_String* self, byte b);

int JB_Str_TrimLastSub(JB_String* self, byte b);

JB_String* JB_Str_TrimSlashes(JB_String* self, bool Pathfix);

JB_String* JB_Str_TrimStart(JB_String* self, JB_String* s, bool All);

bool SC_Str_UnderScoreAtAnyEnd(JB_String* self);

JB_String* JB_Str_Unescape(JB_String* self);

JB_String* SC_Str_UnicodeSafeName(JB_String* self, FastString* fs_in);

CharSet* JB_Str_UniCS(JB_String* self);

int JB_Str_UnPrintable(JB_String* self);

JB_String* JB_Str_UpperFirst(JB_String* self);

bool JB_Str_Visible(JB_String* self);

Array* JB_Str_Words(JB_String* self);

bool JB_Str_WriteSet(JB_String* self, JB_String* Value);

bool JB_Str_Yes(JB_String* self);

JB_String* JB_Str__FromC(_cstring Addr);

JB_String* JB_Str__FromPico(PicoMessage M);

JB_String* JB_Str__Hex(int64 i);

bool JB_Str__Sorter(JB_Object* a, JB_Object* b);



// JB_StringFields
StringFields* JB_FI_Constructor(StringFields* self, JB_String* Source, byte Sep);

void JB_FI_Destructor(StringFields* self);

JB_String* JB_FI_Field(StringFields* self, Ind Prev, Ind Curr);

Ind JB_FI_NextSep(StringFields* self, int Prev);



// JB_StringReader
int JB_SS_Byte(StringReader* self);

void JB_SS_CompressInto(StringReader* self, JB_Object* dest, int Strength, CompressionStats* st);

StringReader* JB_SS_Constructor(StringReader* self, JB_String* Data);

JB_String* JB_SS_Decompress(StringReader* self, int lim, CompressionStats* st, bool Multi);

bool JB_SS_DecompressInto(StringReader* self, JB_Object* dest, int lim, CompressionStats* st);

void JB_SS_Destructor(StringReader* self);

bool JB_SS_HasAny(StringReader* self);

int64 JB_SS_hInt(StringReader* self);

bool JB_SS_IsCompressed(StringReader* self);

bool JB_SS_IsJBin(StringReader* self);

bool JB_SS_NextChunk(StringReader* self);

Message* JB_SS_NextMsgExpect(StringReader* self, Message* parent, Syntax fn, JB_String* name);

Message* JB_SS_NextMsg(StringReader* self);

uint64 JB_SS_NextMsgInfo(StringReader* self);

bool JB_SS_NoMoreChunks(StringReader* self);

int JB_SS_NonZeroByte(StringReader* self);

Message* JB_SS_ParseJbin(StringReader* self, int64 Remain);

int64 JB_SS_Position(StringReader* self);

void JB_SS_PositionSet(StringReader* self, int64 Value);

JB_String* JB_SS_ReadAll(StringReader* self);

bool JB_SS_ReadChunk(StringReader* self, JB_File* f);

int JB_SS_Remaining(StringReader* self);

JB_String* JB_SS_Str(StringReader* self, int n, int skip);

JB_String* JB_SS_StrNoAdvance(StringReader* self, int n, int skip);

void JB_SS_SyntaxExpect(StringReader* self, JB_String* Error);



// JB_SyntaxObj
SyntaxObj* JB_Fn_Constructor(SyntaxObj* self, FP_fpMsgRender msg, JB_String* name, int ID);

void JB_Fn_Destructor(SyntaxObj* self);

JB_String* JB_Fn_Render(SyntaxObj* self, FastString* fs_in);



// JB_TerminalCell


// JB_TokenHandler


// JB___junktest_6__
DTWrap* SC___junktest_6____AbcVis();



// JB_autoitem
autoitem* JB_autoitem_ConstructorAuto(autoitem* self, JB_String* Sort, JB_String* Insert, SCObject* Value, JB_String* Display, bool Exact, int type);

void JB_autoitem_Destructor(autoitem* self);

bool SC_autoitem_OKBy(autoitem* self, autoitem* prev);



// JB_µForm
void SC_xC2xB5Form_AddRemainder(xC2xB5Form* self, uint U);

xC2xB5Form* SC_xC2xB5Form_ConstructorWithStr(xC2xB5Form* self, JB_String* data);

xC2xB5Form* SC_xC2xB5Form_ConstructorWithMsg(xC2xB5Form* self, Message* tmp);

void JB_xC2xB5Form_Destructor(xC2xB5Form* self);

void SC_xC2xB5Form_Finish(xC2xB5Form* self);

void SC_xC2xB5Form_LoadParam(xC2xB5Form* self, JB_String* pl, Message* place);

ASMParam SC_xC2xB5Form_AccessInt(xC2xB5Form* self, int i);

void SC_xC2xB5Form_SyntaxAccessSet(xC2xB5Form* self, int i, ASMParam Value);

void SC_xC2xB5Form_SyntaxAppend(xC2xB5Form* self, ASMParam P);

int SC_xC2xB5Form__Init_();

int SC_xC2xB5Form__InitCode_();

xC2xB5Form* SC_xC2xB5Form__Needform(JB_String* Form);



// JB_µFunc
ASMFunc* SC_ASMFunc_Constructor(ASMFunc* self, SCFunction* fn);

void JB_ASMFunc_Destructor(ASMFunc* self);

ASMFunc2* SC_ASMFunc_Finish(ASMFunc* self);

JB_String* SC_ASMFunc_Render(ASMFunc* self, FastString* fs_in);



// JB_Array
void SC_Array_AddCStr(Array* self, JB_String* s);

void SC_Array_AppendWords(Array* self, JB_String* R);

void JB_Array_Clear(Array* self);

JB_Object* JB_Array_First(Array* self);

JB_String* JB_Array_join(Array* self, JB_String* sep);

JB_Object* JB_Array_Last(Array* self);

void JB_Array_LoadProperties(Array* self, ObjectLoader* Loader);

void JB_Array_SaveCollect(Array* self, ObjectSaver* Saver);

void JB_Array_SaveWrite(Array* self, ObjectSaver* Saver);

void JB_Array_SyntaxAppend(Array* self, JB_Object* item);

int JB_Array_SyntaxCompare(Array* self, int n, bool Aware);

bool JB_Array_SyntaxEquals(Array* self, int n, bool Aware);



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

Dictionary* JB_Dict__Copy(Dictionary* Dict);

Dictionary* JB_Dict__Reverse(Dictionary* Dict);



// JB_FastStringCpp
void SC_FastStringCpp_AppendBehaviour(FastStringCpp* self, JB_String* name, SCFunction* fn, SCClass* Type);

FastStringCpp* SC_FastStringCpp_Constructor(FastStringCpp* self, JB_String* name);

void JB_FastStringCpp_Destructor(FastStringCpp* self);



// JB_File
JB_File* JB_File_Child(JB_File* self, JB_String* name);

ErrorInt2 SC_File_CodeSign(JB_File* self, JB_String* sign);

bool JB_File_CompareData(JB_File* self, JB_String* A, JB_String* Error);

bool JB_File_FileCompare(JB_File* self, JB_File* A, JB_String* Error);

bool JB_File_CompareMsg(JB_File* self, ErrorInt code, JB_String* Error);

ErrorInt JB_File_FileCompareSub(JB_File* self, JB_File* A);

Message* JB_File_Conf(JB_File* self, int lim);

ErrorInt JB_File_CopyAll(JB_File* self, JB_String* Dest, bool AttrOnly);

ErrorInt JB_File_DeleteAll(JB_File* self);

bool JB_File_DirectoryContains(JB_File* self, JB_String* path);

ErrorInt JB_File_LinkToSet(JB_File* self, JB_String* Value);

Array* JB_File_List(JB_File* self, bool invis);

bool JB_File_MustExist(JB_File* self, JB_String* operation);

bool JB_File_Opened(JB_File* self);

bool JB_File_OperatorInside(JB_File* self, JB_File* f);

bool JB_File_NewerThanFile(JB_File* self, JB_File* F);

bool JB_File_OperatorIsNewerThan(JB_File* self, Date F);

JB_File* JB_File_Parent(JB_File* self);

Message* JB_File_Parse(JB_File* self, int lim, bool AllowMissing);

JB_File* JB_File_Sibling(JB_File* self, JB_String* name);

bool JB_File_SmartDataSet(JB_File* self, JB_String* nieu);

JB_File* JB_File_SyntaxAccess(JB_File* self, JB_String* name);

void JB_File_SyntaxAppend(JB_File* self, JB_String* data);

void JB_File_Fail(JB_File* self, JB_String* Error);

bool SC_File_TestBatch(JB_File* self);

bool SC_File_TestSpeedie(JB_File* self, JB_String* v);

ErrorInt2 JB_File_Touch(JB_File* self);

JB_String* JB_File__AppPrefs(JB_String* name);

int JB_File__Init_();

int JB_File__InitCode_();

JB_File* JB_File__Logs();

JB_String* JB_File__PreferencesPath();

JB_File* JB_File__PrefsFolder();



// JB_JBin
void JB_bin_Add(FastString* self, Syntax type, JB_String* data, bool into);

void JB_bin_AddInt(FastString* self, int64 data);

void JB_bin_AddMemory(FastString* self, Syntax type, byte* data, bool GoIn, uint64 L);

void JB_bin_CloseSection(FastString* self, uint c);

FastString* JB_bin_Constructor(FastString* self, Syntax type, JB_String* data);

FastString* JB_bin_Constructor0(FastString* self, int n);

void JB_bin_Enter(FastString* self, Syntax type, JB_String* data);

int JB_bin_OpenSection(FastString* self);

void JB_bin_Sheb(FastString* self, JB_String* data);

void JB_bin_Up(FastString* self, int amount);



// JB_MaterialsLol
MaterialsLol* SC_MaterialsLol_Constructor(MaterialsLol* self, Selector* Next, Selector** Place, JB_String* name1);

void JB_MaterialsLol_Destructor(MaterialsLol* self);

void SC_MaterialsLol____LoadSel(MaterialsLol** Place, JB_String* Name);

int SC_MaterialsLol__Init_();

int SC_MaterialsLol__InitCode_();



// JB_OutputFile


// JB_Process
JB_String* JB_Sh_Render(ShellStream* self, FastString* fs_in);



// JB_SCNamed
SCNamed* JB_Named_Constructor(SCNamed* self);

void JB_Named_Destructor(SCNamed* self);

JB_String* SC_Named_Render(SCNamed* self, FastString* fs_in);



// JB_SavingTest
SavingTest* SC_SavingTest_Constructor(SavingTest* self, int n);

void JB_SavingTest_Destructor(SavingTest* self);

void SC_SavingTest_LoadProperties(SavingTest* self, ObjectLoader* Loader);

void SC_SavingTest_SaveWrite(SavingTest* self, ObjectSaver* Saver);

bool SC_SavingTest__IsEqual(JB_Object* A, JB_Object* B);



// JB_StringShared


// JB_StringThatWasReadSafely


// JB_StringZeroTerminated
_cstring JB_Str_CString(JB_StringC* self);



// JB_list
void JB_Tree_AppendAfter(JB_List* self, JB_List* item, JB_List* after);

void JB_Tree_AppendBefore(JB_List* self, JB_List* item, JB_List* Before);

int JB_Tree_BackDist(JB_List* self, JB_List* B);

void JB_Tree_Clear(JB_List* self);

int JB_Tree_Dist(JB_List* self, JB_List* r);

JB_List* JB_Tree_FlatLast(JB_List* self);

int JB_Tree_FwdDist(JB_List* self, JB_List* F);

bool JB_Tree_HasOneChild(JB_List* self);

bool JB_Tree_IsFirst(JB_List* self);

bool JB_Tree_IsLast(JB_List* self);

bool JB_Tree_IsOnlyChild(JB_List* self);

void jdb2(JB_List* self);

void jdb3(JB_List* self);

bool JB_Tree_OperatorLessOrEqual(JB_List* self, int N);

JB_List* JB_Tree_Pop(JB_List* self);

void JB_Tree_Remove(JB_List* self);

void JB_Tree_RemoveAfter(JB_List* self);

JB_String* JB_List_Render(JB_List* self, FastString* fs_in);

JB_List* JB_Tree_Second(JB_List* self);

JB_List* JB_Tree_Get(JB_List* self, int n);

void JB_Tree_SyntaxAppend(JB_List* self, JB_List* Last);

bool JB_Tree_SyntaxEquals(JB_List* self, int n, bool Aware);

void JB_Tree_TakeAllFrom(JB_List* self, JB_List* src);

JB_List* JB_Tree_Upward(JB_List* self, int n);

JB_List* JB_Tree_WrapWith(JB_List* self, JB_List* W);



// JB_µFunc1
void JB_ASMFunc2_Destructor(ASMFunc2* self);

int64 SC_ASMFunc2_RunArgs(ASMFunc2* self, int64* Args, int ArgCount);

void SC_ASMFunc2_Visible(ASMFunc2* self);



// JB_ExistingFile


// JB_JeeboxFile


// JB_Message
void JB_Msg_Acc__(Message* self, FastString* fs);

Message* JB_Msg_AccessAdd(Message* self, JB_String* key);

void JB_Msg_CantFind(Message* self, Syntax s, JB_String* name, Message* found);

bool SC_Msg_ACInIsa(Message* self);

void SC_Msg_AddBefore(Message* self, Message* before, Message* NewItem);

void JB_Msg_Adj__(Message* self, FastString* fs);

int JB_Msg_After(Message* self);

void JB_Msg_AfterSet(Message* self, int Value);

bool SC_Msg_AllowedMoveToInit(Message* self);

Message* JB_Msg_Ancestor(Message* self, Syntax f);

uint SC_Msg_AndOrExpansionTest(Message* self);

JB_String* SC_Msg_APICppProject(Message* self);

void SC_Msg_AppendAllInto(Message* self, Message* Dest);

void JB_Msg_AppendMacro(Message* self, Macro* M, Array* prms);

void JB_Msg_ARel__(Message* self, FastString* fs);

Message* JB_Msg_Arg(Message* self);

void JB_Msg_Arg__(Message* self, FastString* fs);

JB_String* JB_Msg_ArgName(Message* self);

JB_String* JB_Msg_ArgValue(Message* self);

void JB_Msg_Arr__(Message* self, FastString* fs);

SCArg* SC_Msg_AsArg(Message* self);

SCDecl* SC_Msg_AsDecl(Message* self);

SCFunction* SC_Msg_AsFunc(Message* self);

void JB_Msg_Ask__(Message* self, FastString* fs);

uint64 SC_Msg_ASMConst(Message* self);

fn_asm SC_Msg_ASMFunc(Message* self);

void SC_Msg_AssignsFix(Message* self, SCFunction* f);

int SC_Msg_Autocomplete_State(Message* self);

SCFunction* SC_Msg_AutoMsgFunc(Message* self);

SCFunction* SC_Msg_AutoMsgFuncFn(Message* self);

void SC_Msg_AvoidSafeDecr(Message* self);

void JB_Msg_Back__(Message* self, FastString* fs);

void JB_Msg_Badj__(Message* self, FastString* fs);

void JB_Msg_BecomeStr(Message* self, Syntax fn, JB_String* name);

void JB_Msg_BecomeNum(Message* self, int64 num);

void JB_Msg_BecomeMsg(Message* self, Message* src);

void SC_Msg_Become(Message* self, SCOperator* op);

void SC_Msg_BecomeAppend(Message* self, JB_String* s);

void JB_Msg_BecomeMacro(Message* self, Macro* M, Array* prms);

void SC_Msg_BecomeNil(Message* self);

void SC_Msg_BecomeSyx(Message* self);

void JB_Msg_Bin__(Message* self, FastString* fs);

void JB_Msg_binn__(Message* self, FastString* fs);

void JB_Msg_BinnRender(Message* self, FastString* fs, JB_String* sepa, JB_String* sepb);

ErrorSeverity SC_Msg_Blind(Message* self);

SCBlockage SC_Msg_Blocks(Message* self);

void SC_Msg_BlocksSet(Message* self, int Value);

void JB_Msg_Bra__(Message* self, FastString* fs);

SCDecl* SC_Msg_BraDeclfind(Message* self);

void JB_Msg_BRel__(Message* self, FastString* fs);

bool SC_Msg_BuildRunTask(Message* self, Message* fields, int level);

void SC_Msg_BuildTask(Message* self, Message* fields, Message* root, int level);

void SC_Msg_BunchFix(Message* self);

Message* SC_Msg_BunchFixPrepare(Message* self);

void SC_Msg_BunchFixSub(Message* self, Message* subject, Message* stuff);

void SC_Msg_BunchlessFix(Message* self);

bool SC_Msg_CanGetAddress(Message* self, SCNode* name_space);

Message* SC_Msg_CastedParent(Message* self);

int SC_Msg_CastFPToVoidPtr(Message* self);

int SC_Msg_CastToBool(Message* self, SCNode* name_space);

int SC_Msg_CastToClass(Message* self, SCClass* type, SCNode* name_space);

int SC_Msg_CastToType(Message* self, JB_String* TypeName, SCClass* type, SCNode* name_space, int loss);

Message* SC_Msg_CausesUnReachable(Message* self, Message* arg, Message* Dcl, Message* LastPlace);

void JB_Msg_Char__(Message* self, FastString* fs);

void SC_Msg_CheckContinuesAndExits(Message* self);

void SC_Msg_CheckNotInStateExpr(Message* self, Message* top);

void SC_Msg_CheckSuperDotSave(Message* self, JB_String* name, bool ShouldBe);

void SC_Msg_Clean(Message* self, bool erl);

int JB_Msg_CleanIndent(Message* self);

Message* SC_Msg_CmdImprove(Message* self);

void JB_Msg_Cnj__(Message* self, FastString* fs);

bool SC_Msg_CollectAGlobalDecl(Message* self, SCNode* scarg);

Message* SC_Msg_CollectDclName(Message* self);

SCDecl* SC_Msg_CollectDecl(Message* self, SCNode* P, SCNode* Recv, int Mode, SCClass* cls, SCFunction* FuncPrms);

bool SC_Msg_CollectFromBody(Message* self, SCNode* scarg);

JB_String* SC_Msg_CollectFuncTableName(Message* self);

Message* SC_Msg_CollectionPlace(Message* self);

bool SC_Msg_CollectOneParam(Message* self, SCFunction* func, SCNode* Recv, SCClass* cls);

JB_String* SC_Msg_CollectUsage(Message* self);

Message* JB_Msg_ConfArg(Message* self);

void SC_Msg_ConfTake(Message* self, Message* dest, JB_String* name);

Message* SC_Msg_ConstantExpandSub(Message* self);

bool SC_Msg_ConstIntValue(Message* self, SCNode* name_space, int64* v);

bool SC_Msg_ConstIntValueSub(Message* self, SCNode* name_space, int64* v);

Message* JB_Msg_ConstructorCopy(Message* self, Message* other);

Message* JB_Msg_ConstructorEmpty(Message* self);

Message* JB_Msg_ConstructorNormal(Message* self, Syntax Func, JB_String* Name);

Message* JB_Msg_ConstructorRange(Message* self, Message* Parent, Syntax Func, int BytePos, JB_String* name, int RangeLength);

void SC_Msg_ConstructorAddNil(Message* self, bool isdot);

bool JB_Msg_ContainsInd(Message* self, Ind p, bool AllowJustAfter);

Message* JB_Msg_Copy(Message* self, Message* pos_msg);

void SC_Msg_CopyAllAfter(Message* self, Message* after, Message* copylayer);

void SC_Msg_CopyAllAfterBefore(Message* self, Message* Before, Message* copylayer);

void SC_Msg_CopyAllAfterInto(Message* self, Message* into, Message* copylayer);

void SC_Msg_CopyAllBefore(Message* self, Message* Before, Message* copylayer);

void SC_Msg_CopyAllBeforeInto(Message* self, Message* into, Message* copylayer);

void SC_Msg_CopyAllInto(Message* self, Message* j, bool wipe);

JB_String* JB_Msg_CopyID(Message* self);

Message* JB_Msg_CopySub(Message* self, Message* P);

JB_String* SC_Msg_Cpp_Wrapper(Message* self);

Message* SC_Msg_CreateNil(Message* self);

Message* SC_Msg_CreateOwnBlock(Message* self);

Message* SC_Msg_CutifyCopy(Message* self);

Message* SC_Msg_DclExp(Message* self);

void JB_Msg_Decl__(Message* self, FastString* fs);

Message* SC_Msg_DeclName(Message* self);

bool JB_Msg_DeepEquals(Message* self, Message* B, bool Aware);

Message* SC_Msg_Deepest(Message* self, Syntax Tmp, JB_String* name);

int SC_Msg_DeprecatedClassOption(Message* self, JB_String* name, JB_String* Kind);

void JB_Msg_Destructor(Message* self);

Dictionary* JB_Msg_Dict(Message* self, bool DoCount);

bool SC_Msg_DoesAnything(Message* self);

void JB_Msg_Dot__(Message* self, FastString* fs);

SCDecl* SC_Msg_DotMustBeProperty(Message* self);

SCObject* SC_Msg_DotSpace(Message* self, SCNode* name_space);

DotUseType SC_Msg_DotType(Message* self);

void JB_Msg_Dummy(Message* self, FastString* fs);

void SC_Msg_ElseNeverFires(Message* self);

void JB_Msg_Emb__(Message* self, FastString* fs);

void JB_Msg_ERel__(Message* self, FastString* fs);

bool JB_Msg_Expect(Message* self, Syntax type, JB_String* name);

bool SC_Msg_ExpectClass(Message* self, SCDecl* slf, SCClass* Cls);

void SC_Msg_ExpectEmpty(Message* self);

bool SC_Msg_ExpectInt(Message* self, SCDecl* type);

bool JB_Msg_ExpectLast(Message* self, JB_String* err);

bool SC_Msg_ExpectMatch(Message* self, SCNode* name_space, SCClass* With);

Message* SC_Msg_ExpectParamsTransform(Message* self, int P, Message* errnode, JB_String* Type);

bool JB_Msg_ExpectString(Message* self);

SCFunction* SC_Msg_ExpFunc(Message* self);

void JB_Msg_Export(Message* self, FastString* fs);

Message* SC_Msg_FailOrCopy(Message* self, Message* p);

Message* SC_Msg_FalsifyNil(Message* self);

SCDecl* SC_Msg_FastDecl(Message* self);

void JB_Msg_File__(Message* self, FastString* fs);

JB_String* SC_Msg_FileLocation(Message* self);

JB_String* JB_Msg_FilePath(Message* self);

Message* JB_Msg_FindSyx(Message* self, Syntax s);

Message* JB_Msg_FindSyxName(Message* self, Syntax s, JB_String* name, bool Err);

Message* JB_Msg_FindName(Message* self, JB_String* name);

Array* JB_Msg_FindAll(Message* self, Syntax fn, JB_String* name);

JB_String* SC_Msg_FindAndRemove(Message* self, JB_String* name, bool NothingOK, bool IsClass);

Message* SC_Msg_FindAndRemove2(Message* self, Message* place, bool NothingOK, bool IsClass);

Message* SC_Msg_FindAndRemoveSub(Message* self, JB_String* name, bool NothingOK, bool IsClass);

Message* SC_Msg_FindDestructor(Message* self);

Message* JB_Msg_FindNested(Message* self, Syntax fn, JB_String* name, bool Err);

Message* JB_Msg_FindNotInserted(Message* self);

Message* SC_Msg_FindPos(Message* self, int fr, int len);

Message* SC_Msg_FindPosSub(Message* self, int fr, int len, bool Exact);

Message* SC_Msg_FindRef(Message* self, SCFunction* fn, JB_String* name);

Message* SC_Msg_FindShader(Message* self, JB_String* TypeName);

Message* JB_Msg_FindTightest(Message* self, int pos, bool named, bool SamePosition);

JB_String* JB_Msg_FirstName(Message* self);

void SC_Msg_FixElseif(Message* self);

void SC_Msg_FixErl(Message* self);

void SC_Msg_FixMultiArr(Message* self);

double JB_Msg_Float(Message* self);

float JB_Msg_Float32(Message* self);

void JB_Msg_FSListArg(Message* self, FastString* fs, bool AddLine);

void JB_Msg_FSListSep(Message* self, FastString* fs, JB_String* sep);

Message* SC_Msg_FullAfter(Message* self);

void JB_Msg_Func__(Message* self, FastString* fs);

JB_String* JB_Msg_FuncName(Message* self);

int SC_Msg_FuncPos(Message* self, SCFunction* fn);

void SC_Msg_FuncWrap(Message* self, Message* fnc);

int SC_Msg_GetAddressOf(Message* self, SCDecl* Type, bool WasCArray);

Message* SC_Msg_GetASMFunc(Message* self);

Message* SC_Msg_GetDclName(Message* self, bool IsConstructor);

SCFunction* SC_Msg_GetFunctionPointer(Message* self);

Message* SC_Msg_GetMarker(Message* self, JB_String* s);

Message* SC_Msg_GetTypeLimiter(Message* self);

Message* JB_Msg_GiveArg(Message* self);

Message* JB_Msg_GoIntoInvisArg(Message* self, Message* tmp, int pos);

Message* SC_Msg_HasOwnBlock(Message* self);

bool JB_Msg_HasPosition(Message* self);

bool SC_Msg_HasSelfAsFirst(Message* self);

void SC_Msg_HateUnusedFuncs(Message* self);

SCFunction* SC_Msg_IdentifyFunc(Message* self);

Message* SC_Msg_InBuiltSizeOf(Message* self, SCNode* name_space, SCDecl* sulf, Message* sulf_exp);

int JB_Msg_IndentScore(Message* self);

bool JB_Msg_InInvisArg(Message* self);

bool SC_Msg_InitExpand(Message* self);

bool SC_Msg_InitRootDecl(Message* self, Message* before, SCNode* name_space);

void SC_Msg_InsertAfter(Message* self, Message* ins, Message* after);

void SC_Msg_InsertBefore(Message* self, Message* j, Message* ch);

void SC_Msg_InsertMainArgs(Message* self, Message* prms);

SCFunction* SC_Msg_InsideFunc(Message* self);

int64 JB_Msg_Int(Message* self, int i);

NameAndMsg SC_Msg_IntoVariable(Message* self, SCNode* name_space);

MaybeBool SC_Msg_IsAlwaysBool(Message* self);

bool SC_Msg_IsAlwaysFalse(Message* self);

bool SC_Msg_IsAssignable(Message* self);

bool SC_Msg_IsBehaviour(Message* self);

bool SC_Msg_IsClassType(Message* self);

bool SC_Msg_IsFirstOfSetRel(Message* self);

Message* SC_Msg_IsInDeclInBlock(Message* self);

bool SC_Msg_IsInt(Message* self);

bool SC_Msg_IsLinkageType(Message* self);

bool SC_Msg_IsModuleType(Message* self);

int SC_Msg_IsNowNil(Message* self);

SCFunction* SC_Msg_IsParentConCall(Message* self);

bool SC_Msg_IsProperty(Message* self);

bool SC_Msg_IsReffer(Message* self);

bool SC_Msg_IsReturnOrRejoin(Message* self);

Message* SC_Msg_IsSetIntoPlace(Message* self);

Message* SC_Msg_IsSetIntoVar(Message* self);

bool SC_Msg_IsSetRel(Message* self);

bool SC_Msg_IsSettablePlace(Message* self);

bool SC_Msg_IsStatementExpr(Message* self);

bool JB_Msg_IsString(Message* self);

bool JB_Msg_IsTypeOfDecl(Message* self);

bool SC_Msg_IsVarAltered(Message* self, JB_String* name);

bool SC_Msg_IsVarUseableInLoop(Message* self, JB_String* name);

bool SC_Msg_IsZero(Message* self);

void JB_Msg_Item__(Message* self, FastString* fs);

bool JB_Msg_jbinTest(Message* self);

JB_String* JB_Msg_JDB2_(Message* self, int Flags, FastString* fs_in);

JB_String* jdb4(Message* self);

JB_String* SC_Msg_JDB4_(Message* self, FastString* fs_in);

JB_String* JB_Msg_JDB_(Message* self, FastString* fs_in, int flags);

void SC_Msg_KinderRemoveAfter(Message* self);

Message* JB_Msg_Last(Message* self, Syntax Need);

void SC_Msg_LastInBlock(Message* self, SCBlockage Reason);

Message* SC_Msg_LastUsedFix(Message* self);

int JB_Msg_Length(Message* self);

void JB_Msg_List__(Message* self, FastString* fs);

Array* SC_Msg_ListAll(Message* self);

bool JB_Msg_ListViewable(Message* self);

JB_String* JB_Msg_Locate(Message* self);

void SC_Msg_LoopContinue(Message* self);

void SC_Msg_LoopExit(Message* self);

void SC_Msg_LoopExitter(Message* self, int ASMType, SCBlockage ExitCode);

Message* JB_Msg_MacroAvoidCopy(Message* self);

void JB_Msg_MacroCopy(Message* self, Message* root, Array* prms, Message* dest);

void SC_Msg_MacroFixSub(Message* self, SCDecl* contains);

Message* JB_Msg_MacroPrm(Message* self, Message* root, Array* prms, Message* dest);

Message* JB_Msg_MacroSame(Message* self, Message* prm);

Message* SC_Msg_MainFix(Message* self);

void SC_Msg_mainfix2(Message* self);

int SC_Msg_MainOneArg(Message* self, Message* arg, int i, int found);

void SC_Msg_MakeTaskVar(Message* self, Message* con, Message* before, bool First);

void JB_Msg_max__(Message* self, FastString* fs);

void SC_Msg_MiniArgCpp(Message* self, FastString* fs);

JB_String* JB_Msg_MiniName(Message* self, JB_String* prefix);

void SC_Msg_MiniTran(Message* self, SCNode* name_space, JB_String* On);

int SC_Msg_ModelMode(Message* self);

Message* SC_Msg_ModelType(Message* self);

Message* SC_Msg_ModuleSrc(Message* self);

void SC_Msg_Move(Message* self, Message* last, Message* into);

void SC_Msg_MoveAllAfter(Message* self, Message* after);

Message* JB_Msg_Msg(Message* self, Syntax fn, JB_String* name);

void JB_Msg_Msg__(Message* self, FastString* fs);

SCArg* SC_Msg_MsgArg(Message* self);

SCDecl* SC_Msg_MsgDecl(Message* self);

SCFunction* SC_Msg_MsgFunc(Message* self);

SCFunction* SC_Msg_MsgOwningFunc(Message* self);

void JB_Msg_Name__(Message* self, FastString* fs);

Message* SC_Msg_NeedBra(Message* self);

Message* JB_Msg_NeedFirst(Message* self);

Message* SC_Msg_NeedMarker(Message* self, JB_String* s, bool b);

bool SC_Msg_NeedsPreprocess(Message* self);

Message* SC_Msg_Negate(Message* self);

Message* SC_Msg_NegateThg(Message* self);

Message* JB_Msg_NextOfName(Message* self, Syntax Need, JB_String* Name);

Message* JB_Msg_NextOf(Message* self, Syntax Need);

void SC_Msg_Next_Index(Message* self, SCIterator* iter, Message* node2);

SCDecl* SC_Msg_NiceIsFlagSyntax(Message* self, Message* opch, Message* RN, SCNode* name_space, Message* side);

Message* SC_Msg_NiceParent(Message* self);

void JB_Msg_Nil__(Message* self, FastString* fs);

int SC_Msg_NilCheckMode(Message* self, bool ok);

Message* SC_Msg_NormaliseFunc(Message* self, SCClass* AddSelf);

void SC_Msg_NotNilRZ(Message* self, SCDecl* type, SCNode* space);

void JB_Msg_Num__(Message* self, FastString* fs);

bool SC_Msg_OarExpand(Message* self);

void JB_Msg_Oat__(Message* self, FastString* fs);

SCClass* SC_Msg_ObjCls(Message* self);

bool JB_Msg_ContainsStr(Message* self, JB_String* s);

bool JB_Msg_InMsg(Message* self, Message* f);

bool JB_Msg_OperatorIn(Message* self, Syntax f);

bool SC_Msg_OperatorIsARel(Message* self, JB_String* name);

bool SC_Msg_OperatorIsBRel(Message* self, JB_String* name);

bool SC_Msg_OperatorIsDot(Message* self, JB_String* name);

bool SC_Msg_OperatorIsOpp(Message* self, JB_String* name);

bool SC_Msg_OperatorIsThing(Message* self, JB_String* name);

bool SC_Msg_OperatorIsTmp(Message* self, JB_String* name);

bool JB_Msg_OperatorMatches(Message* self, Message* m);

bool JB_Msg_OperatorStarts(Message* self, JB_String* s);

void JB_Msg_Opp__(Message* self, FastString* fs);

bool SC_Msg_OppExpand(Message* self);

int SC_Msg_OpScore(Message* self);

JB_String* JB_Msg_OriginalParseData(Message* self);

Message* SC_Msg_OrigMsg(Message* self);

JB_String* SC_Msg_OrigRender(Message* self, FastString* fs);

Message* SC_Msg_ParentForAddress(Message* self);

Message* SC_Msg_ParentPoint(Message* self);

Message* SC_Msg_ParseShaderSub(Message* self);

void JB_Msg_pinn__(Message* self, FastString* fs);

Message* JB_Msg_PoorAnt(Message* self);

void SC_Msg_PrepareAST(Message* self, JB_String* path);

int JB_Msg_PrevIndentCheck(Message* self, Message* pr);

void JB_Msg_Prm__(Message* self, FastString* fs);

Message* SC_Msg_QMarkRel(Message* self);

void JB_Msg_Ques__(Message* self, FastString* fs);

void JB_Msg_Quot__(Message* self, FastString* fs);

IntRange JB_Msg_Range(Message* self);

void JB_Msg_RangeSet(Message* self, IntRange r);

int SC_Msg_RC_HasTemporary(Message* self);

NilState SC_Msg_RedundantDeclare(Message* self, NilState D);

NilState SC_Msg_RedundantVar(Message* self, SCDecl* dcl, NilCheckMode Test);

bool SC_Msg_RefDisappears(Message* self);

uint SC_Msg_Reg(Message* self);

uint SC_Msg_RegOrNum(Message* self, bool NeedReg);

void JB_Msg_Rel__(Message* self, FastString* fs);

bool SC_Msg_RelFix(Message* self, bool force);

Message* SC_Msg_RemoveTypeCasts(Message* self);

JB_String* JB_Msg_Render(Message* self, FastString* fs_in);

void JB_Msg_render_jbin_sub(Message* self, FastString* js);

JB_String* JB_Msg_RenderJbin(Message* self, JB_String* shell_path, FastString* fs_in);

void JB_Msg_RenderPrm(Message* self, FastString* fs, byte b1, byte b2);

JB_String* SC_Msg_RenderType(Message* self);

JB_String* SC_Msg_RenderTypeAndName(Message* self);

void JB_Msg_RenderWithSpaces(Message* self, FastString* fs, Message* ch);

Message* SC_Msg_ReplaceInbuiltSub(Message* self, SCNode* name_space, SCDecl* self_decl);

Message* JB_Msg_ReplaceInto(Message* self, Message* w);

Message* SC_Msg_ReplaceWith(Message* self, Message* j);

Message* SC_Msg_ReplaceWithChild(Message* self);

JB_Object* JB_Msg_RestoreLoad(Message* self);

Message* SC_Msg_Resync(Message* self, Message* parent);

void SC_Msg_Safe(Message* self, FastString* fs);

void SC_Msg_SafeRemove(Message* self, Syntax T);

void SC_Msg_SafeReplaceWith(Message* self, Message* Incoming);

SCArg* SC_Msg_SCArg(Message* self, SCNode* p, Message* avoid);

SCArg* SC_Msg_SCArgNested(Message* self, Message* base, SCNode* p);

SCFile* SC_Msg_SCFile(Message* self);

void JB_Msg_SCnj__(Message* self, FastString* fs);

void JB_Msg_SCom__(Message* self, FastString* fs);

void JB_Msg_SDot__(Message* self, FastString* fs);

int SC_Msg_SelfUsedForProperty(Message* self);

Message* SC_Msg_SendPerryErrors(Message* self);

bool SC_Msg_SettingToNil(Message* self);

DotUseType SC_Msg_SetType(Message* self);

bool JB_Msg_ShallowEquals(Message* self, Message* B, bool Aware);

void JB_Msg_Sheb__(Message* self, FastString* fs);

void SC_Msg_SlidePositions(Message* self, int add);

void JB_Msg_SStr__(Message* self, FastString* fs);

void SC_Msg_StartUsingAfter(Message* self);

void SC_Msg_StatementExprSet(Message* self, SCArg* arg);

void JB_Msg_SThg__(Message* self, FastString* fs);

void JB_Msg_Str__(Message* self, FastString* fs);

Message* JB_Msg_NeedSyxOK(Message* self, Syntax Need, Syntax OK);

Message* JB_Msg_NeedSyx(Message* self, Syntax s);

Message* JB_Msg_NeedSyxInt(Message* self, Syntax s, int n);

Message* JB_Msg_NeedSyxName(Message* self, Syntax s, JB_String* name);

void JB_Msg_SetStr(Message* self, JB_String* key, JB_String* Value);

void JB_Msg_SetMsg(Message* self, JB_String* key, Message* Value);

Message* JB_Msg_GetConf(Message* self, JB_String* key, bool Err);

void JB_Msg_AppendString(Message* self, JB_String* key);

void JB_Msg_AppendSyx(Message* self, Syntax Fn, JB_String* name);

void JB_Msg_AppendNum(Message* self, int64 Num);

void JB_Msg_SyntaxDeprecate(Message* self, JB_String* Error);

bool JB_Msg_SyntaxEquals(Message* self, JB_String* name, bool Aware);

bool JB_Msg_EqualsSyx(Message* self, Syntax X, bool Aware);

void JB_Msg_SyntaxExpect(Message* self, JB_String* Error);

bool JB_Msg_SyntaxIs(Message* self, MsgParseFlags F);

void JB_Msg_SyntaxIsSet(Message* self, MsgParseFlags F, bool Value);

MessagePosition JB_Msg_SyntaxUsing(Message* self);

void JB_Msg_SyntaxWarn(Message* self, JB_String* Error);

bool SC_Msg_TargetTest(Message* self);

Message* SC_Msg_TaskConBefore(Message* self);

Message* SC_Msg_TempIntoBlock(Message* self, Message* ParentPlace);

void JB_Msg_Test(Message* self, JB_String* new_render, JB_String* name);

void JB_Msg_test_style(Message* self);

bool SC_Msg_TestFuncName(Message* self);

bool JB_Msg_TestSub(Message* self, JB_String* new_render, JB_String* name);

JB_String* JB_Msg_Text(Message* self, int i);

bool JB_Msg_TextSet(Message* self, int i, JB_String* v);

void JB_Msg_Thg__(Message* self, FastString* fs);

void JB_Msg_Tmp__(Message* self, FastString* fs);

ASMtmp SC_Msg_TmpType(Message* self);

void SC_Msg_TmpTypeSet(Message* self, ASMtmp Value);

void JB_Msg_Todo__(Message* self, FastString* fs);

void SC_Msg_Tran_Isnt(Message* self, JB_String* name);

void SC_Msg_Tran_QMark(Message* self);

Message* SC_Msg_Tran_Target(Message* self);

void SC_Msg_Tran_TargetSub(Message* self);

void SC_Msg_Tran_With(Message* self);

Message* SC_Msg_TranModel(Message* self);

void JB_Msg_TRel__(Message* self, FastString* fs);

void JB_Msg_Tril__(Message* self, FastString* fs);

MaybeBool SC_Msg_Trueness(Message* self, NilState found);

bool SC_Msg_TrueOrFalse(Message* self);

Message* JB_Msg_TViewCH(Message* self);

void JB_Msg_Type__(Message* self, FastString* fs);

Message* SC_Msg_TypeOfArrItem(Message* self);

Message* SC_Msg_UnBra(Message* self);

Message* SC_Msg_UnBraType(Message* self);

void JB_Msg_UnEmbedStr(Message* self);

void JB_Msg_Unit__(Message* self, FastString* fs);

bool SC_Msg_UnitMatch(Message* self, JB_String* a, JB_String* b);

Message* SC_Msg_UnReachable(Message* self);

Message* SC_Msg_UpToType(Message* self);

void JB_Msg_url__(Message* self, FastString* fs);

Message* SC_Msg_UseNonRefChangers(Message* self, bool parent);

JB_String* JB_Msg_Value(Message* self);

JB_String* SC_Msg_VarName(Message* self);

Message* SC_Msg_LayerWipeCopy(Message* self, Message* oof);

Message* SC_Msg_WipeCopy(Message* self);

void JB_Msg_WipePositions(Message* self);

void SC_Msg_WithDeclTransform(Message* self, Message* decl, Message* rel, Message* arg);

bool SC_Msg_WithinLoop(Message* self, Message* stop);

bool JB_Msg_WithinType(Message* self, int Allowed);

int SC_Msg_WrapExpr(Message* self, SCDecl* src);

void SC_Msg_WrapFloatOrInt(Message* self, DataTypeCode T, int N, SCDecl* D);

Message* SC_Msg_WrapWith(Message* self, Syntax f, JB_String* s);

void JB_Msg_XAtt__(Message* self, FastString* fs);

void JB_Msg_XCDT__(Message* self, FastString* fs);

void JB_Msg_XCom__(Message* self, FastString* fs);

void JB_Msg_XML__(Message* self, FastString* fs);

void JB_Msg_XPI__(Message* self, FastString* fs);

void JB_Msg_XTxt__(Message* self, FastString* fs);

bool JB_Msg_Yes(Message* self);

void JB_Msg_Yoda__(Message* self, FastString* fs);

SyntaxObj* JB_Msg__GetFunc(Message* msg);

Message* SC_Msg__NilchCompare();

bool JB_Msg__TreeCompare(Message* orig, Message* reparse, bool PrintIfSame);

void JB_Msg__TreeComparePrint(Message* orig);



// JB_MessageID
MessageID* JB_ID_Constructor(MessageID* self, JB_String* Name, Syntax Fn, uint64 ID);

void JB_ID_Destructor(MessageID* self);

JB_String* JB_ID_Render(MessageID* self, FastString* fs_in);

bool JB_ID__IDSorter(JB_Object* a, JB_Object* b);



// JB_SCDecl
bool SC_Decl_AlreadyContains(SCDecl* self);

JB_String* SC_Decl_AutoCompleteName(SCDecl* self);

void SC_Decl_BecomeReal(SCDecl* self);

SCDecl* SC_Decl_Better_Numeric(SCDecl* self, SCDecl* o, OpMode Mode);

int SC_Decl_ByteSize(SCDecl* self);

bool SC_Decl_CanNilCheck(SCDecl* self);

bool SC_Decl_CantBeNilInCpp(SCDecl* self);

SCDecl* SC_Decl_CanUpgradeInternalPointer(SCDecl* self);

bool SC_Decl_CanUseDefault(SCDecl* self);

bool SC_Decl_CanWrap(SCDecl* self);

SCDecl* SC_Decl_CheckMath(SCDecl* self, Message* exp);

bool SC_Decl_ConstCheck(SCDecl* self, Message* ln, Message* RN, SCDecl* rc);

bool SC_Decl_ConstInRange(SCDecl* self, Message* RN, SCDecl* rt);

bool SC_Decl_ConstInRangeSub(SCDecl* self, int64 Value);

SCDecl* SC_Decl_Constructor(SCDecl* self, SCClass* type);

SCDecl* SC_Decl_Containedfix(SCDecl* self);

SCDecl* SC_Decl_ContainedReplace(SCDecl* self, SCDecl* contains, bool NeedsName);

bool SC_Decl_ContainsMatch(SCDecl* self, SCDecl* o, int TypeCast);

SCDecl* SC_Decl_CopyDecl(SCDecl* self, bool ForNewVariable);

void SC_Decl_CopyTypeInfoTo(SCDecl* self, SCDecl* Dcl);

bool SC_Decl_CouldUpgradeToReal(SCDecl* self);

Message* SC_Decl_CreateDefault(SCDecl* self, Message* errs, bool isfunc);

Message* SC_Decl_CreateSimpleTypeCast(SCDecl* self, Message* exp);

Message* SC_Decl_CreateStructNil(SCDecl* self, Message* where);

Message* SC_Decl_CreateStructNilSub(SCDecl* self);

Message* SC_Decl_DeclToAddr(SCDecl* self, SCDecl* P0);

Message* SC_Decl_DeclToDot(SCDecl* self, SCDecl* P0);

SCDecl* SC_Decl_DefaultToReal(SCDecl* self);

SCDecl* SC_Decl_DeReference(SCDecl* self, Message* brel, SCNode* name_space, bool IsAccess);

SCDecl* SC_Decl_DeReferenceSub(SCDecl* self, Message* brel, SCNode* name_space, bool IsAccess);

void JB_Decl_Destructor(SCDecl* self);

SCDecl* SC_Decl_DownGrade(SCDecl* self);

void SC_Decl_ExpectFail(SCDecl* self, SCDecl* o, Message* errnode, Message* backup);

Message* SC_Decl_ExpectMatch(SCDecl* self, SCDecl* O, int TypeCast, Message* exp, Message* ErrNode);

void SC_Decl_ExpectRelMatch(SCDecl* self, SCDecl* O, Message* exp, Message* side, Message* ErrNode);

SCDecl* SC_Decl_ExtractAmount(SCDecl* self, Message* Prms, SCNode* name_space);

SCDecl* SC_Decl_ExtractAmountSub(SCDecl* self, Message* Prms, SCNode* name_space);

bool SC_Decl_FastMatch(SCDecl* self, SCDecl* O);

bool SC_Decl_Found(SCDecl* self);

DataTypeCode SC_Decl_GameType(SCDecl* self);

SCDecl* SC_Decl_GetAddress(SCDecl* self, DeclMode Purpose);

SCDecl* SC_Decl_GetCArray(SCDecl* self, int Amount);

SCIterator* SC_Decl_GetIteratorAny(SCDecl* self, JB_String* name, Message* node);

bool SC_Decl_HasStruct(SCDecl* self);

SCFunction* SC_Decl_HasStructDestructor(SCDecl* self);

SCDecl* SC_Decl_HighestArrayContainMatch(SCDecl* self, SCDecl* Other, Message* exp);

SCDecl* SC_Decl_HighestMatch(SCDecl* self, SCDecl* Other, Message* exp);

void SC_Decl_IsCarray(SCDecl* self, int Size, SCDecl* Of);

bool SC_Decl_IsCArray(SCDecl* self);

bool SC_Decl_IsConstOf(SCDecl* self, SCDecl* b);

bool SC_Decl_IsDataTypeOnly(SCDecl* self);

bool SC_Decl_IsFloat(SCDecl* self);

bool SC_Decl_IsInteger(SCDecl* self);

bool SC_Decl_IsNil(SCDecl* self);

bool SC_Decl_IsNormal(SCDecl* self);

bool SC_Decl_IsNormalBool(SCDecl* self);

bool SC_Decl_IsNormalNumber(SCDecl* self);

bool SC_Decl_IsNormalObject(SCDecl* self);

bool SC_Decl_IsNormalStruct(SCDecl* self);

bool SC_Decl_IsntReallyCastable(SCDecl* self, Message* side);

int SC_Decl_IsNumeric(SCDecl* self);

bool SC_Decl_IsObject(SCDecl* self);

bool SC_Decl_IsReffable(SCDecl* self, bool SetOnly);

bool SC_Decl_IsReg(SCDecl* self);

JB_String* SC_Decl_IsSaveable(SCDecl* self);

void SC_Decl_IsTypeImproveSet(SCDecl* self, bool Value);

bool SC_Decl_IsUintLike(SCDecl* self);

bool SC_Decl_IsVoidPtr(SCDecl* self);

bool SC_Decl_LoadContained(SCDecl* self, Message* Contained, Message* wrap, SCNode* Name_Space, DeclMode Purpose);

bool SC_Decl_LoadContainedSub(SCDecl* self, SCDecl* Cont, Message* wrap, SCNode* Name_Space, DeclMode Purpose);

SCDecl* SC_Decl_MakeAsObject(SCDecl* self, SCDecl* Container, Message* ErrPlace);

SCDecl* SC_Decl_MakeBorrowed(SCDecl* self, bool StayBorrowed);

void SC_Decl_MakeContainedObject(SCDecl* self, Message* ErrPlace);

SCDecl* SC_Decl_MakeContainedOptional(SCDecl* self);

SCDecl* SC_Decl_MakeDataObject(SCDecl* self, SCNode* Name_Space, DeclMode Purpose);

SCDecl* SC_Decl_MakeExistance(SCDecl* self, NilState type, SCDecl* Default);

void SC_Decl_MakeGameFlying(SCDecl* self, SCClass* oof, Message* m);

SCDecl* SC_Decl_MakeNewNil(SCDecl* self);

SCDecl* SC_Decl_MakeNewOptional(SCDecl* self);

SCDecl* SC_Decl_MakeNewReal(SCDecl* self);

SCDecl* SC_Decl_MakeReal(SCDecl* self);

bool SC_Decl_MakeStatic(SCDecl* self, Message* wrap, SCNode* Name_Space, DeclMode Purpose);

void SC_Decl_MarkAsRefAltered(SCDecl* self);

bool SC_Decl_MatchC(SCDecl* self, SCDecl* O);

bool SC_Decl_MiniMatch(SCDecl* self, SCDecl* O, int TypeCast);

void SC_Decl_NameSet(SCDecl* self, JB_String* Value);

bool SC_Decl_NeedsContainedfix(SCDecl* self);

SCDecl* SC_Decl_NewWrapper(SCDecl* self, SCDecl* CastTo);

SCDecl* SC_Decl_NilConstructor(SCDecl* self, NilState type);

NilState SC_Decl_NilCurr(SCDecl* self);

void SC_Decl_NilPrmFail(SCDecl* self, Message* where, SCFunction* f);

bool SC_Decl_NilStated(SCDecl* self);

void SC_Decl_NoBlindCasts(SCDecl* self, SCDecl* old, Message* exp, SCNode* name_space);

bool SC_Decl_NoFloat(SCDecl* self, Message* exp);

bool SC_Decl_OperatorExact_isa(SCDecl* self, SCClass* v);

bool SC_Decl_MatchesDecl(SCDecl* self, SCDecl* O);

bool SC_Decl_OperatorMatches(SCDecl* self, SCClass* O);

bool SC_Decl_PointeryMatch(SCDecl* self, SCDecl* O);

uint SC_Decl_PointeryMatchSub(SCDecl* self, SCDecl* O, int TypeCast);

void SC_Decl_PrefixedName(SCDecl* self, FastString* fs, SCModule* M);

JB_String* SC_Decl_PrmStateMsg(SCDecl* self, JB_String* Needed, SCFunction* f);

SCDecl* SC_Decl_ProcessAs(SCDecl* self, Message* msg);

SCImport* SC_Decl_Project(SCDecl* self);

SCDecl* SC_Decl_ReallyContains(SCDecl* self);

JB_String* SC_Decl_RealName(SCDecl* self);

Message* SC_Decl_RefDestructor(SCDecl* self);

SCDecl* SC_Decl_RefineDecl(SCDecl* self, Message* list);

DataTypeCode SC_Decl_RegType(SCDecl* self);

JB_String* SC_Decl_Render(SCDecl* self, FastString* fs_in);

JB_String* SC_Decl_RenderTypeAndName(SCDecl* self, int minimal);

JB_String* SC_Decl_RenderTypeName(SCDecl* self, FastString* fs_in);

JB_String* SC_Decl_RenderTypeNameNicer(SCDecl* self, FastString* fs_in);

bool SC_Decl_SafelyWrappable(SCDecl* self);

bool SC_Decl_SameForReplace(SCDecl* self, SCDecl* c);

NilState SC_Decl_StatedOptional(SCDecl* self);

NilState SC_Decl_StatedReal(SCDecl* self);

void SC_Decl_SyntaxAppend(SCDecl* self, SCDeclInfo d);

bool SC_Decl_SyntaxIs(SCDecl* self, SCDeclInfo d);

void SC_Decl_SyntaxIsSet(SCDecl* self, SCDeclInfo d, bool Value);

int SC_Decl_TryTypeCast(SCDecl* self, SCDecl* O, Message* exp, int TypeCast);

int SC_Decl_TryTypeCastPointer(SCDecl* self, SCDecl* O, Message* exp, int TypeCast, bool CArray);

JB_String* SC_Decl_TryUseSaveable(SCDecl* self, bool IsSave, SCClass* cls);

DataTypeCode SC_Decl_TypeInfo(SCDecl* self);

bool SC_Decl_TypeIsReached(SCDecl* self);

uint SC_Decl_TypeMatch(SCDecl* self, SCDecl* O, int TypeCast, Message* exp);

void SC_Decl_TypeReach(SCDecl* self, SCNode* from, Message* src);

bool SC_Decl_TypeSuffers(SCDecl* self);

Message* SC_Decl_WriteDeclFull(SCDecl* self, JB_String* DeclName, int minimal);

Message* SC_Decl_WriteDeclSub(SCDecl* self, JB_String* Name, int minimal);

Message* SC_Decl_WriteDeclTypeAndName(SCDecl* self, JB_String* Name, int minimal);

Message* SC_Decl_WriteNilDecl(SCDecl* self);

Message* SC_Decl_WriteNilRel(SCDecl* self);

Message* SC_Decl_WriteSimpleType(SCDecl* self);

Message* SC_Decl_WriteType(SCDecl* self, int minimal);

Message* SC_Decl_WriteTypeCast(SCDecl* self, Message* msg);

Message* SC_Decl_WriteVerySimpleType(SCDecl* self);



// JB_SCFile
Message* SC_SCFile_AST(SCFile* self);

Message* SC_SCFile_ASTSub(SCFile* self, bool Orig);

void SC_SCFile_CollectGlobals(SCFile* self, SCNode* p);

SCFile* SC_SCFile_Constructor(SCFile* self, JB_File* f, SCImport* p);

void JB_SCFile_Destructor(SCFile* self);

void SC_SCFile_DetectInsecureWords(SCFile* self);

Message* SC_SCFile_GetMsg(SCFile* self, int pos);

Message* SC_SCFile_Orig(SCFile* self);

Message* SC_SCFile_Start_AST(SCFile* self);

void SC_SCFile_Use(SCFile* self);



// JB_SCIterator
void SC_Iter_Check(SCIterator* self, SCClass* cls);

SCIterator* SC_Iter_Constructor(SCIterator* self, SCClass* parent, Message* msg);

void JB_Iter_Destructor(SCIterator* self);

Message* SC_Iter_MakeWhile(SCIterator* self, Message* arg, Message* postcond);

void SC_Iter_RenameSelf(SCIterator* self, Message* Name);

void SC_Iter_RenameValue(SCIterator* self, Message* s);

void SC_Iter_Renuqify(SCIterator* self, SCNode* p);

Array* SC_Iter_Uniqueify(SCIterator* self, Message* msg);

int SC_Iter__Init_();

int SC_Iter__InitCode_();

SCNode* SC_Iter__NeuIter(Message* node, SCNode* name_space, Message* ErrPlace);

SCIterator* SC_Iter__SimpleIter(JB_String* src);



// JB_SCNode
JB_String* SC_Base_AutoCompleteKind(SCNode* self);

void SC_Base_Collect(SCNode* self, Message* AST, bool Visible, Message* dest);

void SC_Base_CollectConstantsSub(SCNode* self, Message* ch);

void SC_Base_CollectOne(SCNode* self, Message* c, bool Visible);

void SC_Base_CollectOneConstants(SCNode* self, Message* ch);

Message* SC_Base_CollectString(SCNode* self, JB_String* s);

SCNode* SC_Base_CollectSub(SCNode* self, Message* c);

void SC_Base_ConstantExpand(SCNode* self, Message* ch);

SCNode* SC_Base_Constructor0(SCNode* self);

SCNode* SC_Base_ConstructorStr(SCNode* self, JB_String* Name, bool Dummy);

SCNode* SC_Base_ConstructorMsg(SCNode* self, Message* node);

void SC_Base_CreateNameDict(SCNode* self, Message* FuncName, Array* NameList);

void JB_Base_Destructor(SCNode* self);

Message* SC_Base_DiissplayObj(SCNode* self, Message* rz);

bool SC_Base_ExpectModule(SCNode* self, Message* errplace);

SCClass* SC_Base_FindClass(SCNode* self, JB_String* name, Message* where, SCNodeFindMode Mode);

SCClass* SC_Base_FindClassMsg(SCNode* self, Message* where, SCNodeFindMode Mode);

Message* SC_Base_FindCppWrapper(SCNode* self, Message* place, bool isclass);

SCModule* SC_Base_FindModule(SCNode* self, JB_String* name, Message* where, SCNodeFindMode Mode);

SCModule* SC_Base_FindModuleMsg(SCNode* self, Message* where, SCNodeFindMode Mode);

SCNode* SC_Base_FindModuleParent(SCNode* self, SCNodeFindMode Mode);

bool SC_Base_FindVis(SCNode* self, Message* c);

Message* SC_Base_FuncSrc(SCNode* self);

void SC_Base_ImportFile(SCNode* self, SCFile* file);

bool SC_Base_IsModuleFunc(SCNode* self);

SCClass* SC_Base_IsNormalObject(SCNode* self);

bool SC_Base_IsSTDLib(SCNode* self);

JB_String* SC_Base_LateAddTempory(SCNode* self, JB_String* type, JB_String* name1, Message* Value, Message* err);

Message* SC_Base_LinkagePlace(SCNode* self);

Array* SC_Base_ListFunctions(SCNode* self);

void SC_Base_LoadExportName(SCNode* self);

void SC_Base_LoadVisibility(SCNode* self, Message* p);

JB_Object* SC_Base_LookUpDot(SCNode* self, JB_String* name, Message* exp, SCNode* arg_space, SCDecl* contains, Message* side);

SCFunction* SC_Base_LookUpFunc(SCNode* self, JB_String* name, Message* exp, Message* ParamsHere);

SCObject* SC_Base_LookUpSub(SCNode* self, JB_String* OrigName, Message* Exp, Message* ParamsHere, SCNode* Arg_Space, SCDecl* contains, Message* side, int Purpose);

SCObject* SC_Base_LookUpVar(SCNode* self, JB_String* name, Message* exp, Message* side);

SCDecl* SC_Base_LookUpVarDecl(SCNode* self, JB_String* name);

SCObject* SC_Base_LookUpVarRootDecl(SCNode* self, JB_String* name, Message* exp);

bool SC_Base_NeedsExport(SCNode* self);

SCFunction* SC_Base_OwningFunc(SCNode* self);

SCNode* SC_Base_ProcessLinkage(SCNode* self, Message* node, Dictionary* Table);

SCNode* SC_Base_ProjectFix(SCNode* self);

JB_String* SC_Base_ReachedName(SCNode* self);

bool SC_Base_RehomeExport(SCNode* self);

SCDecl* SC_Base_RequireContained(SCNode* self, Message* exp);

Message* SC_Base_Route(SCNode* self, JB_String* name);

void SC_Base_SetExportName(SCNode* self, JB_String* s, bool Explicit);

SCClass* SC_Base_ShouldBeClass(SCNode* self, Message* errplace);

Message* SC_Base_SourceArg(SCNode* self);

SCModule* SC_Base_SpaceModule(SCNode* self, Message* errplace);

JB_String* SC_Base_SubProjName(SCNode* self);

SCObject* SC_Base_SyntaxAccess(SCNode* self, JB_String* s);

JB_String* SC_Base_TestExportName(SCNode* self, JB_String* s, bool Explicit);

void SC_Base_Tran_Const(SCNode* self, SCDecl* D, SCNode* base);

void SC_Base_TryAdd(SCNode* self, Message* ErrPlace, SCObject* IncObj, JB_String* name);

void SC_Base_TryAddBase(SCNode* self, Message* c, SCNode* neu);

void SC_Base_TryAddSub(SCNode* self, Message* ErrPlace, SCObject* IncObj, JB_String* name);

JB_String* SC_Base_UniquifyExport(SCNode* self, JB_String* s);

SCObject* SC_Base_UpCheck(SCNode* self, JB_String* name, bool LookUp);

SCNode* SC_Base_UpClass(SCNode* self, Message* f);

void SC_Base_Use(SCNode* self);

int SC_Base__Init_();

int SC_Base__InitCode_();

SCNode* SC_Base__LoadCppPart(Message* node, SCNode* name_space, Message* ErrPlace);



// JB_SaverClassInfo
void JB_sci_Clear(SaverClassInfo* self);

SaverClassInfo* JB_sci_Constructor(SaverClassInfo* self, JB_Class* Cls, char* Data);

void JB_sci_Destructor(SaverClassInfo* self);

bool JB_sci_HasData(SaverClassInfo* self);

void JB_sci_Output(SaverClassInfo* self, ObjectSaver* Saver);



// JB_SimpleGraph


// JB_SpdProcess
bool JB_Proc_Alive(SpdProcess* self);

bool JB_Proc_ChildAlive(SpdProcess* self);

bool JB_Proc_CommsOpen(SpdProcess* self);

SpdProcess* JB_Proc_Constructor(SpdProcess* self, JB_String* path, FP_SpdMainFn fn, PicoComms* pico, Array* params, ProcessMode Mode);

void JB_Proc_Destructor(SpdProcess* self);

void JB_Proc_Disconnect(SpdProcess* self, JB_StringC* Why);

Message* JB_Proc_Get(SpdProcess* self, float T);

bool JB_Proc_IsOpen(SpdProcess* self);

bool JB_Proc_ParentAlive(SpdProcess* self);

bool JB_Proc_Send(SpdProcess* self, Message* msg);

int JB_Proc__InitCode_();

void JB_Proc__InitOwner();



// JB_Task
JB_Task* JB_Task_Constructor(JB_Task* self, uint Obj, void* func);

void JB_Task_Destructor(JB_Task* self);

LessThan3* SC_Task_LessThan3_Constructor(LessThan3* self, JB_String* a, int b, JB_String* c);



// JB_Error
JB_Error* JB_Err_Constructor(JB_Error* self, Message* node, JB_String* desc, ErrorSeverity level, JB_String* path);

JB_Error* JB_Err_ConstructorNothing(JB_Error* self);

void JB_Err_Destructor(JB_Error* self);

void JB_Err_Fill(JB_Error* self, JB_String* path, JB_String* desc);

void JB_Err_GrabLine(JB_Error* self, FastString* fs, bool Usecolor);

bool JB_Err_HasPosition(JB_Error* self);

void SC_Err_Improve(JB_Error* self);

bool JB_Err_IsBad(JB_Error* self);

bool JB_Err_IsError(JB_Error* self);

bool JB_Err_IsWarning(JB_Error* self);

bool JB_Err_LineIdentifiers(JB_Error* self, FastString* fs, JB_String* path);

int JB_Err_LinePos(JB_Error* self, JB_String* data);

JB_String* JB_Err_Render(JB_Error* self, FastString* fs_in);

JB_String* SC_Err_Render_Unix(JB_Error* self, FastString* fs_in);

JB_String* JB_Err_RenderClang(JB_Error* self, FastString* fs_in);

void SC_Err_SCGrabLine(JB_Error* self, FastString* fs, bool Usecolor);

int SC_Err_SCLineCount(JB_Error* self);

void SC_Err_SCLineIdentifiers(JB_Error* self, FastString* fs, JB_String* Data);

JB_String* SC_Err_SCOriginalData(JB_Error* self);

JB_String* SC_Err_SCOriginalPath(JB_Error* self);

JB_String* SC_Err_SCRender(JB_Error* self, FastString* fs_in);

void JB_Err_ShiftPosition(JB_Error* self, int i);

bool JB_Err_SyntaxIs(JB_Error* self, ErrorFlags F);

void JB_Err_SyntaxIsSet(JB_Error* self, ErrorFlags F, bool Value);

void JB_Err_UpgradeWithNode(JB_Error* self);

void JB_Err__CantParseNum(Message* Where, JB_String* num, int Pos);

int JB_Err__Init_();

int JB_Err__InitCode_();

void JB_Err__SourceAdd(Message* m);

void JB_Err__SourceRemove();



// JB_FileArchive


// JB_MessageRoot


// JB_SCArg
SCArg* SC_Arg_Constructor(SCArg* self, Message* node);

void JB_Arg_Destructor(SCArg* self);

JB_String* SC_Arg_Render(SCArg* self, FastString* fs_in);



// JB_SCBehaviour
void SC_Beh_Add(SCBehaviour* self, SCNode* fn);

SCClass* SC_Beh_Cls(SCBehaviour* self);

SCBehaviour* SC_Beh_Constructor(SCBehaviour* self, SCClass* parent);

void SC_Beh_CreateFuncTable(SCBehaviour* self, Message* ErrPlace);

void JB_Beh_Destructor(SCBehaviour* self);

SCBehaviour* SC_Beh_Upwards(SCBehaviour* self);

SCFunction* SC_Beh__MakeVirtualCaller(SCModule* Mod, SCClass* Cls, Message* ErrPlace);

SCNode* SC_Beh__NewActual(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Beh__NewVirtual(Message* node, SCNode* name_space, Message* ErrPlace);

SCModule* SC_Beh__NewVirtualSub(Message* node, SCClass* cls, Message* ErrPlace);

bool SC_Beh__Tran_Behaviour(Message* node, SCClass* cls);



// JB_SCClass
void SC_Class_AddBehaviourOrInterface(SCClass* self, SCNode* M, Message* ErrPlace);

void SC_Class_AfterAfterFuncs(SCClass* self);

void SC_Class_AfterFuncsDecled(SCClass* self);

JB_String* SC_Class_APIStructName(SCClass* self);

void SC_Class_BannedCheck(SCClass* self, Message* src);

JB_String* SC_Class_BehaviourName(SCClass* self);

SCFunction* SC_Class_BestBehaviourFor(SCClass* self, JB_String* name);

int SC_Class_CalculateSize(SCClass* self, int Depth);

int SC_Class_CalculateSizeRaw(SCClass* self, int Depth);

bool SC_Class_CanCompare(SCClass* self, SCDecl* Against, bool AsEquals);

bool SC_Class_CanCompareSub(SCClass* self, JB_String* s, SCDecl* against);

bool SC_Class_CanHaveEmptyConstructor(SCClass* self);

void SC_Class_CheckAllocVsWrapper(SCClass* self, SCFunction* f, bool IsConstructor);

void SC_Class_CheckIterator(SCClass* self);

void SC_Class_ClassCollect(SCClass* self);

bool SC_Class_CollectProp(SCClass* self, Message* msg);

void SC_Class_CollectProperties(SCClass* self);

SCFunction* SC_Class_ConOrDesForCall(SCClass* self, bool IsConstructor, int Task);

SCClass* SC_Class_Constructor(SCClass* self, Message* node, SCNode* parent, bool HasPtrs, SCModule* m);

void SC_Class_ContainedTypeLoad(SCClass* self);

SCFunction* SC_Class_CreateAutoConstructor(SCClass* self);

void SC_Class_CreateBehaviour(SCClass* self);

void SC_Class_CreateConstructors(SCClass* self);

SCFunction* SC_Class_CreateEmptyConstructors(SCClass* self);

SCFunction* SC_Class_CreateEmptyFunc(SCClass* self, JB_String* fname, JB_String* cpp_name);

JB_String* SC_Class_CStructName(SCClass* self);

JB_String* SC_Class_CStructNameSub(SCClass* self);

JB_String* SC_Class_CSuperStructName(SCClass* self);

void SC_Class_DataTypePostLoad(SCClass* self);

void SC_Class_DeclModel(SCClass* self);

void JB_Class_Destructor(SCClass* self);

SCFunction* SC_Class_DoSaver(SCClass* self, JB_String* name, int stage);

Message* SC_Class_Falsify(SCClass* self, Message* ques);

void SC_Class_FillInterFaceIn(SCClass* self, SCFunction* fn, bool Late);

void SC_Class_FillInterFaceWrapper(SCClass* self, SCFunction* fn);

void SC_Class_FillRoleConstructor(SCClass* self, SCFunction* con);

void SC_Class_FillTaskConstructor(SCClass* self, SCFunction* con);

void SC_Class_FillTaskConstructorSub(SCClass* self, Message* con, Message* before, int depth);

SCFunction* SC_Class_FindAllocFunc(SCClass* self, JB_String* fname, bool DontCreate);

SCClass* SC_Class_FindContainedClass(SCClass* self);

SCFunction* SC_Class_FindFunc(SCClass* self, JB_String* keyword, bool CheckParents, bool DoError);

SCFunction* SC_Class_FindSpecialFunc(SCClass* self, JB_String* keyword, bool CheckParents);

SCFunction* SC_Class_FirstDestructor(SCClass* self);

void SC_Class_GetDepth(SCClass* self);

SCClass* SC_Class_GetFlyingMemClassFor(SCClass* self);

SCDecl* SC_Class_GetFlyingMemory(SCClass* self, Message* exp);

SCIterator* SC_Class_GetIteratorAny(SCClass* self, JB_String* name, Message* node);

void SC_Class_GetStructDepth(SCClass* self);

SCClass* SC_Class_GoUpTo(SCClass* self, int d);

bool SC_Class_HasGameType(SCClass* self);

bool SC_Class_HasObjectProperties(SCClass* self);

bool SC_Class_HasOperator(SCClass* self, JB_String* op);

bool SC_Class_HasStuffToHandleInDestructor(SCClass* self);

SCClass* SC_Class_InterfaceFor(SCClass* self, JB_String* name, Message* errplace);

SCClass* SC_Class_InterfaceForBehaviour(SCClass* self, SCFunction* Fn);

bool SC_Class_IsA(SCClass* self, SCClass* S);

bool SC_Class_IsBehaviourTable(SCClass* self);

bool SC_Class_IsDataTypeOnly(SCClass* self);

bool SC_Class_IsDataTypeOrFP(SCClass* self);

bool SC_Class_IsFunc(SCClass* self);

bool SC_Class_IsInterface(SCClass* self);

bool SC_Class_IsMArray(SCClass* self, Message* arr);

bool SC_Class_IsObject(SCClass* self);

bool SC_Class_IsSaveableObject(SCClass* self);

bool SC_Class_IsSaveableStruct(SCClass* self);

bool SC_Class_IsStruct(SCClass* self);

bool SC_Class_IsTask(SCClass* self);

void SC_Class_Iterfailed(SCClass* self, JB_String* name, Message* node);

void SC_Class_LibExport(SCClass* self, FastString* j);

void SC_Class_LoadClassType(SCClass* self);

void SC_Class_LoadConstructors(SCClass* self);

void SC_Class_LoadLinkage(SCClass* self);

void SC_Class_LoadModuleForCls(SCClass* self, Message* node, SCNode* P);

void SC_Class_LoadSaver(SCClass* self);

JB_String* SC_Class_LoadSaverSub(SCClass* self);

void SC_Class_LoadSuperBehaviours(SCClass* self);

void SC_Class_LoadSuperClass(SCClass* self);

SCDecl* SC_Class_MakeClassType(SCClass* self, SCDecl* d);

void SC_Class_ModelDecls(SCClass* self);

void SC_Class_NeedsDefaultValue(SCClass* self, Message* def, Message** place, JB_String* name);

bool SC_Class_NeedsExport(SCClass* self);

void SC_Class_NewDeclInClassModule(SCClass* self, JB_String* S, SCClass* T);

SCDecl* SC_Class_NotConst(SCClass* self);

int SC_Class_NumericCount(SCClass* self);

void SC_Class_OverrideSyntax(SCClass* self);

int SC_Class_PassableCount(SCClass* self);

void SC_Class_ProcessBehaviours(SCClass* self);

void SC_Class_ProcessInterfaces(SCClass* self);

void SC_Class_Reach(SCClass* self, SCNode* from, Message* src);

void SC_Class_ReachBehaviours(SCClass* self);

bool SC_Class_Real_Isa(SCClass* self, SCClass* cls);

bool SC_Class_Real_Isa2(SCClass* self, SCClass* cls);

SCClass* SC_Class_RealClass(SCClass* self);

SCClass* SC_Class_RealSuper(SCClass* self);

void SC_Class_RenameInterfaces(SCClass* self);

JB_String* SC_Class_Render(SCClass* self, FastString* fs_in);

void SC_Class_RenderSaveable(SCClass* self, FastString* fs);

bool SC_Class_RenderSaveableSub(SCClass* self, FastString* fs);

void SC_Class_StartupSaver(SCClass* self, JB_String* Name);

JB_String* SC_Class_StructName(SCClass* self);

bool SC_Class_EqualsType(SCClass* self, SCNodeType d, bool aware);

void SC_Class_TaskProperties(SCClass* self);

bool SC_Class_TestBanned(SCClass* self);

void SC_Class_TryAddToProject(SCClass* self);

void SC_Class_WriteStructOrUnion(SCClass* self, FastStringCpp* fs);

SCNode* SC_Class__DataType(Message* node, SCNode* name_space, Message* ErrPlace);

SCModule* SC_Class__DataTypeSub(Message* Node, SCNode* Parent, Message* ErrPlace, JB_String* ForInterface, SCNodeType BaseType);

SCNode* SC_Class__ExtendOneFunc(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Class__GetDefault(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Class__GetFalse(Message* node, SCNode* name_space, Message* ErrPlace);

JB_String* SC_Class__LoadClassName(Message* node);

SCNode* SC_Class__LoadSyntax(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Class__NeuClass(Message* node, SCNode* name_space, Message* ErrPlace);

SCClass* SC_Class__NeuClassSub(Message* node, SCNode* parent, Message* ErrPlace, JB_String* ForInterface, SCNodeType base);

SCNode* SC_Class__NeuRole(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Class__NewInnerClass(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Class__NewStruct(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Class__ProcessAs(Message* node, SCNode* name_space, Message* ErrPlace);

SCFunction* SC_Class__ProcessExtend(Message* c, bool PreferClass, SCModule* m);

void SC_Class__ProcessExtendOld(Message* c, bool PreferClass);

SCNode* SC_Class__SetSize(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Class__StoreExtend(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Class__StoreExtendModule(Message* node, SCNode* name_space, Message* ErrPlace);



// JB_SCFunction
void SC_Func_AddConstructorReturn(SCFunction* self, Message* prms);

void SC_Func_AddConstructorReturn2(SCFunction* self);

void SC_Func_AddSelfPrm(SCFunction* self, SCClass* cls);

void SC_Func_AddSelfToFunc(SCFunction* self, SCClass* cls, SCNode* space);

void SC_Func_Addtotable(SCFunction* self, Array* r);

void SC_Func_AnalyseRefs(SCFunction* self, Array* list);

int SC_Func_ApparantArgCount(SCFunction* self);

SCFunction* SC_Func_ArgsMatch(SCFunction* self, SCDecl* base, SCNode* name_space, SCParamArray* Incoming, int Options);

SCFunction* SC_Func_ArgsMatch1(SCFunction* self, SCDecl* base, SCNode* name_space, SCParamArray* Incoming, int Cast);

SCFunction* SC_Func_ArgsMatch2(SCFunction* self, SCDecl* base, int TypeCast, SCNode* name_space, SCParamArray* Incoming);

int SC_Func_ArgsMatch3(SCFunction* self, int TypeCast, SCDecl* base, bool ThisAlter, SCNode* name_space, SCParamArray* Incoming);

bool SC_Func_Borked(SCFunction* self);

void SC_Func_BuildConstructorDestructor(SCFunction* self);

void SC_Func_CallParents(SCFunction* self);

void SC_Func_CallSuperMem(SCFunction* self, SCFunction* fn);

bool SC_Func_CanBuildConstructor(SCFunction* self);

bool SC_Func_CanCompare(SCFunction* self, SCDecl* Against);

bool SC_Func_CanLibLoad(SCFunction* self);

bool SC_Func_CanLinkTo(SCFunction* self, SCNode* To);

bool SC_Func_CanNil(SCFunction* self);

void SC_Func_CheckConstructorAndDestructor(SCFunction* self, Message* root, bool IsConstructor);

void SC_Func_CheckNotBadName(SCFunction* self);

void SC_Func_CheckReturnValue(SCFunction* self, Message* msg);

void SC_Func_Cleanupfunc(SCFunction* self, Message* s);

void SC_Func_CollectDeclsParams(SCFunction* self, Message* prms, SCNode* AddToSpace);

void SC_Func_CollectLinks(SCFunction* self, JB_Object* obj);

bool SC_Func_CollectReturnAsReal(SCFunction* self);

SCFunction* SC_Func_ConOrDesForCall(SCFunction* self, SCClass* c, bool IsConstructor, int Task);

SCFunction* SC_Func_Constructor(SCFunction* self, Message* msg);

Message* SC_Func_ConstructorLinePlace(SCFunction* self);

void SC_Func_CopyParams(SCFunction* self, Message* list);

Message* SC_Func_CountCallsToParentAlloc(SCFunction* self, Message* root);

int SC_Func_CreateTypeCast(SCFunction* self, SCDecl* MyType, Message* exp, int Loss);

void SC_Func_DeclsProtoCleanup(SCFunction* self, SCClass* fpType, Message* ch0, bool AssumeSelf, bool late, Message* Route);

SCDecl* SC_Func_DeclsProtoTypeAdd(SCFunction* self, SCClass* fpType);

void SC_Func_DeclsPrototypeClass(SCFunction* self, Message* ch0);

void SC_Func_DeclsPrototypeInterface(SCFunction* self, Message* ch0, SCClass* fpType, bool late);

JB_String* SC_Func_Describe(SCFunction* self, FastString* fs_in);

void SC_Func_DescribeParamFail(SCFunction* self, SCParamArray* params, int bad);

void JB_Func_Destructor(SCFunction* self);

SCFunction* SC_Func_Disambiguate(SCFunction* self, Message* src);

void SC_Func_DoLinkBoth(SCFunction* self, SCNode* To);

void SC_Func_DoLinkTo(SCFunction* self, SCNode* To);

void SC_Func_DontWantSameReturnType(SCFunction* self, SCFunction* f);

bool SC_Func_doRefs(SCFunction* self);

void SC_Func_DotFuncToNormalFunc(SCFunction* self, Message* dot);

bool SC_Func_EqualOrMoreSpecific(SCFunction* self, SCFunction* f);

JB_String* SC_Func_ExportNameBuilder(SCFunction* self, JB_String* CppPart);

void SC_Func_FillInDestructor(SCFunction* self);

void SC_Func_FillInMissingConstructorDefaults(SCFunction* self, Message* root, Message* AfterHere);

void SC_Func_FillInSaver(SCFunction* self, JB_String* name);

Message* SC_Func_FindCallParents(SCFunction* self);

Message* SC_Func_FindCppWrapperFunc(SCFunction* self, Message* place);

int SC_Func_FindDepths(SCFunction* self);

bool SC_Func_FindReached(SCFunction* self, SCNode* from);

void SC_Func_FixCnj(SCFunction* self, Message* exp);

void SC_Func_FixCnjSub(SCFunction* self, Message* exp);

void SC_Func_Flatten(SCFunction* self);

void SC_Func_FLookupSet(SCFunction* self, SCNode* Value);

bool SC_Func_FoundOneCpp(SCFunction* self, JB_String* n);

void SC_Func_FuncDecls(SCFunction* self);

bool SC_Func_HiderMatch(SCFunction* self, bool IsAssigns);

void SC_Func_Init_Sub(SCFunction* self, Message* node, SCNode* name_space);

SCObject* SC_Func_InsertIn(SCFunction* self, SCNode* parent, JB_String* name);

bool SC_Func_IsAllocOrNew(SCFunction* self);

bool SC_Func_IsARealSpdFunc(SCFunction* self);

bool SC_Func_IsBehaviour(SCFunction* self);

bool SC_Func_IsConstructorOnModule(SCFunction* self, SCFunction* old);

void SC_Func_IsCppInBuiltSet(SCFunction* self, int Value);

bool SC_Func_IsReal(SCFunction* self);

Message* SC_Func_IsSimpleCast(SCFunction* self);

bool SC_Func_IsUnused(SCFunction* self);

SCFunction* SC_Func_Last(SCFunction* self);

SCDecl* SC_Func_MacroFix(SCFunction* self, SCDecl* contains, SCNode* name_space, SCParamArray* Incoming);

void SC_Func_MakeMacro(SCFunction* self, Message* arg);

void SC_Func_MakeNilChecker(SCFunction* self, Message* msg);

void SC_Func_MakeParamsReal(SCFunction* self);

JB_String* SC_Func_MakeProtoClassName(SCFunction* self, JB_String* start);

void SC_Func_MarkRecursive(SCFunction* self, SCFunction* EndAt);

bool SC_Func_NeedsExport(SCFunction* self);

Message* SC_Func_NewDefaultRel(SCFunction* self, Message* place, SCDecl* d);

void SC_Func_NilSelff(SCFunction* self, Message* where, NilState v);

SCFunction* SC_Func_ParamlessConstructor(SCFunction* self);

JB_String* SC_Func_ParamUniquer(SCFunction* self, JB_String* s);

JB_String* SC_Func_ParentName(SCFunction* self);

bool SC_Func_ParseName(SCFunction* self, Message* node);

void SC_Func_PreProcessExpects(SCFunction* self);

void SC_Func_PreRead(SCFunction* self, Message* Arg);

Message* SC_Func_Prms(SCFunction* self);

void SC_Func_ProtoExportName(SCFunction* self);

void SC_Func_RefFunc(SCFunction* self, Message* prm, Message* after);

DataTypeCode SC_Func_RegType(SCFunction* self);

JB_String* SC_Func_Render(SCFunction* self, FastString* fs_in);

JB_String* SC_Func_RenderName(SCFunction* self, FastString* fs_in);

JB_String* SC_Func_RenderParams(SCFunction* self, bool ForErrors, FastString* fs_in);

JB_String* SC_Func_RenderTitle(SCFunction* self, bool ForErrors, FastString* fs_in);

SCDecl* SC_Func_Self(SCFunction* self);

void SC_Func_SetBlindCasts(SCFunction* self, SCNode* name_space);

Message* SC_Func_SourceArg(SCFunction* self);

void SC_Func_StripTest(SCFunction* self);

bool SC_Func_SyntaxEquals(SCFunction* self, JB_String* name, bool Aware);

bool SC_Func_SyntaxIs(SCFunction* self, FunctionType k);

void SC_Func_SyntaxIsSet(SCFunction* self, FunctionType k, bool Value);

void SC_Func_Transform(SCFunction* self);

void SC_Func_TranStrings(SCFunction* self);

void SC_Func_TryAdd(SCFunction* self, SCNode* b);

SCFunction* SC_Func_TryKeepBetter(SCFunction* self, int OldMatch, SCFunction* f, int Match);

bool SC_Func_Update_Source(SCFunction* self, int start, JB_String* text, SCFile* myfile, SCObject* orig);

bool SC_Func_UpdateSourceSub(SCFunction* self, Message* src);

bool SC_Func_UseCppName(SCFunction* self, JB_String* CppName);

bool SC_Func_UseExportWrapper(SCFunction* self, JB_String* CppWrapper);

void SC_Func_ValidateSaver(SCFunction* self, JB_String* name);

int SC_Func_VisibleArgs(SCFunction* self);

void SC_Func_WantAs(SCFunction* self, NilState NS);

JB_String* SC_Func_WrapName(SCFunction* self);

Message* SC_Func__AlterPostCond(Message* PostCond, Message* IterPostCond, Message* NodeSrc);

Message* SC_Func__ArgToFunc(JB_String* NewName, Message* Params, Message* arg);

bool SC_Func__CanKeepAsSource(Message* list, Message* arg, SCDecl* d);

bool SC_Func__CanKeepAsValue(SCIterator* iter, Message* arg, SCDecl* dcl, Message* value);

void SC_Func__FastStringOpt(Message* s, SCNode* name_space);

Message* SC_Func__GetFileString(Message* msg, JB_String* name);

bool SC_Func__InBuiltFunc(Message* self, JB_String* name);

int SC_Func__Init_();

int SC_Func__InitCode_();

void SC_Func__Link(SCFunction* fn);

void SC_Func__LinkAll(Array* Funcs);

SCNode* SC_Func__NeuLibrary(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Func__NeuMain(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Func__NeuSyx(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Func__NewConstructor(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Func__NewCppWrapper(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Func__NewDestructor(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Func__NewFunc(Message* node, SCNode* name_space, Message* ErrPlace);

SCFunction* SC_Func__NewFuncSub(Message* node, SCNode* name_space);

SCNode* SC_Func__NewHelper(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Func__NewHider(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Func__NewMacro(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Func__NewProtoType(Message* node, SCNode* name_space, Message* ErrPlace);

SCModule* SC_Func__NewProtoTypeSub(Message* node, SCNode* parent, Message* ErrPlace, JB_String* ForInterface);

SCNode* SC_Func__NewRender(Message* node, SCNode* name_space, Message* ErrPlace);

void SC_Func__ObjectifyString(Message* msg);

void SC_Func__String_Expand(Message* msg, SCFunction* fn);

Message* SC_Func__TypedTempMoveOut(Message* msg, JB_String* name);

Message* SC_Func__TempMoveOut(Message* msg, Message* parent);

SCDecl* SC_Func__Tran_AfterRel(Message* msg, SCNode* name_space, Message* side);

void SC_Func__Tran_All(SCFunction* fn, Message* s, SCNode* p);

void SC_Func__Tran_Array(Message* S, SCNode* name_space);

void SC_Func__Tran_Beep(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_BlindCasts(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_CppRefs(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_Debugger(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_Deprecate(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_Description(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_DoAt(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_Else(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_Expect(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_Fails(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_For(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_ForStart(Message* arg, Message* index, SCNode* p);

void SC_Func__Tran_ForSub(SCFunction* fn, Message* node, SCNode* name_space);

bool SC_Func__Tran_FuncTable(Message* msg);

void SC_Func__Tran_If(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_Ifn(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_IfSub(Message* node, SCNode* name_space);

void SC_Func__Tran_Isa(Message* S, SCNode* p);

void SC_Func__Tran_Log(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_NotAllowed(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_Once(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_OneIsa(Message* isa_f, Message* arg, SCNode* space);

void SC_Func__Tran_Print(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_Quit(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_Rejoin(SCFunction* fn, Message* node, SCNode* name_space);

bool SC_Func__Tran_Render(Message* msg, SCClass* Cls);

bool SC_Func__Tran_RenderSub(Message* msg, SCClass* Cls);

Message* SC_Func__Tran_Result(SCFunction* f);

void SC_Func__Tran_ResultFinish(SCFunction* f, Message* r_z, SCNode* space);

void SC_Func__Tran_Return(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_Sdt(Message* exp);

void SC_Func__Tran_Strings(Message* start, SCFunction* fn);

void SC_Func__Tran_Swap(SCFunction* fn, Message* node, SCNode* name_space);

Message* SC_Func__Tran_Syx(Message* msg);

void SC_Func__Tran_Temporal(SCFunction* fn, Message* s, SCNode* name_space);

void SC_Func__Tran_Using(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_Visible(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__Tran_While(SCFunction* fn, Message* node, SCNode* name_space);

void SC_Func__TransformAll();



// JB_SCModule
void SC_Mod_AddDelayedInit(SCModule* self, Message* src, Message* dest, JB_String* fn_name);

void SC_Mod_AddInterfaceToTable(SCModule* self, SCClass* TableCls);

void SC_Mod_AddModuleToFunc(SCModule* self, SCNode* space);

void SC_Mod_BaseDecls(SCModule* self);

Message* SC_Mod_BuildInitArg(SCModule* self);

SCModule* SC_Mod_Constructor(SCModule* self);

JB_String* SC_Mod_CppPath(SCModule* self);

void SC_Mod_DelayedInitFuncTransform(SCModule* self);

void JB_Mod_Destructor(SCModule* self);

SCObject* SC_Mod_GetTheNewer(SCModule* self);

void SC_Mod_GlobalsFix(SCModule* self);

bool SC_Mod_HasActualCode(SCModule* self, Message* arg);

void SC_Mod_InitDecls(SCModule* self);

bool SC_Mod_IsProperModule(SCModule* self);

void SC_Mod_LoadInitFunc(SCModule* self);

void SC_Mod_LoadInitFuncSub(SCModule* self, Message* init, JB_String* name);

void SC_Mod_LoadModule(SCModule* self, Message* node);

void SC_Mod_MoveToInitFunc(SCModule* self, Message* c);

SCFunction* SC_Mod_NewModuleFunc(SCModule* self, Message* src);

SCModule* SC_Mod_OneOrOther(SCModule* self, SCModule* B);

JB_String* SC_Mod_Render(SCModule* self, FastString* fs_in);

JB_String* SC_Mod_SafeName(SCModule* self);

SCModule* SC_Mod_SuperMod(SCModule* self);

bool SC_Mod_TryInit(SCModule* self, Array* req);

SCNode* SC_Mod__ConstantCollector(Message* node, SCNode* name_space, Message* ErrPlace);

SCNode* SC_Mod__DoInitAfter(Message* node, SCNode* name_space, Message* ErrPlace);

int SC_Mod__Init_();

int SC_Mod__InitCode_();

SCNode* SC_Mod__NeuModule(Message* node, SCNode* name_space, Message* ErrPlace);

SCModule* SC_Mod__NewContainer(JB_String* s);



// JB_config
Message* JB_config_ConfFirst(Message* self);

bool JB_config_Save(Message* self);



// JB_interface
bool SC_Task_LessThan3_interface_SyntaxCall(JB_Task* self, int i);



// JB_LessThan3
bool SC_Task_LessThan3_run(LessThan3* self, int i);

inline float JB_Date_CastFloat(Date self);

inline bool JB_ErrorInt_SyntaxCast(ErrorInt self);

inline bool JB_ErrorMarker_SyntaxCast(ErrorMarker self);

inline bool JB_FastBuff_AppendByte(FastBuff* self, byte v);

inline bool JB_File_SyntaxCast(JB_File* self);

inline bool JB_Ind_SyntaxCast(Ind self);

inline Syntax JB_Msg_Func(Message* self);

inline JB_String* JB_Msg_Name(Message* self);

inline JB_String* JB_Msg_Name_(Message* self);

inline int JB_Sel_ID(Selector* self);

inline JB_String* JB_Tk__SyntaxAccess(int s, int e, Syntax f);

inline bool JB_int64_OperatorInRange(int64 self, int64 d);

inline bool JB_int_OperatorInRange(int self, int d);

inline JB_String* SC_Named_Name(SCNamed* self);

inline bool SC_PA_SyntaxCast(SCParamArray* self);

inline int SC_Reg_ToInt(AsmReg* self);

inline void SC_nil_SetAllNil(ArchonPurger* self, NilRecord Dest);

inline NilRecord SC_nil_Value(ArchonPurger* self);

inline NilState SC_nil__Jump(Message* msg, NilCheckMode Test);

inline bool JB_Array_SyntaxCast(Array* self);

inline bool JB_Err2_SyntaxCast(ErrorInt2 self);

inline JB_String* JB_FS_SyntaxCast(FastString* self);

inline JB_String* JB_Object___Render__(JB_Object* self, FastString* fs_in);

inline void JB_Sav___LoadProperties__(Saveable* self, ObjectLoader* Loader);

inline void JB_Sav___SaveCollect__(Saveable* self, ObjectSaver* Saver);

inline void JB_Sav___SaveWrite__(Saveable* self, ObjectSaver* Saver);

inline JB_StringC* JB_Str_CastZero(JB_String* self);

inline _cstring JB_Str_SyntaxCast(JB_StringC* self);

inline int JB_uint64_LELength(uint64 self);

inline bool SC_NilTest_SyntaxCast(NilTest* self);

inline NilState SC_nil_SetNilness(ArchonPurger* self, SCDecl* d, NilState New);

inline void SC_nil__DeclKill();

inline NilRecord SC_nil__Value();

inline bool JB_Safe_SyntaxCast(JB_String* self);

inline bool SC_Decl_IsUnknownParam(SCDecl* self);

inline NilRecord SC_nil__EndBlock();

inline void SC_Msg_AddValue(Message* self, SCFunction* f);

inline IR* SC_flat_RequestOp2(ASMFuncState* self, uint Code);

inline IR* SC_flat_AddASM(ASMFuncState* self, Message* dbg, int SM, int a, int b, int c, int d);

inline void SC_flat_AddExtended(ASMFuncState* self, Message* err, uint Bits);

inline SCDecl* SC_TypeOfSwiz(Message* exp, SCNode* name_space, Message* side, SCDecl* class_Space);


//// HEADER Inlines.h
inline float JB_Date_CastFloat(Date self) {
	return (((float)self) * kJB__Date_kOneStep);
}

inline bool JB_ErrorInt_SyntaxCast(ErrorInt self) {
	return self == 0;
}

inline bool JB_ErrorMarker_SyntaxCast(ErrorMarker self) {
	return JB_StdErr->ErrorCount == self;
}

inline bool JB_FastBuff_AppendByte(FastBuff* self, byte v) {
	(*self->Curr++) = v;
	return self->Curr >= self->End;
}

inline bool JB_File_SyntaxCast(JB_File* self) {
	return self != nil;
}

inline bool JB_Ind_SyntaxCast(Ind self) {
	return self >= 0;
}

inline Syntax JB_Msg_Func(Message* self) {
	if (self) {
		return self->Func;
	}
	return nil;
}

inline JB_String* JB_Msg_Name(Message* self) {
	if (self) {
		return self->Name;
	}
	return JB_LUB[0];
}

inline JB_String* JB_Msg_Name_(Message* self) {
	if (self) {
		return self->Name;
	}
	return JB_LUB[0];
}

inline int JB_Sel_ID(Selector* self) {
	if (self) {
		return self->ID;
	}
	return 0;
}

inline JB_String* JB_Tk__SyntaxAccess(int s, int e, Syntax f) {
	return (JB__Tk_Splitter)(s, e, f);
}

inline bool JB_int64_OperatorInRange(int64 self, int64 d) {
	return (((uint64)self) < ((uint64)d));
}

inline bool JB_int_OperatorInRange(int self, int d) {
	if (d > 0) {
		return (((uint)self) < ((uint)d));
	}
	return false;
}

inline JB_String* SC_Named_Name(SCNamed* self) {
	if (self) {
		return self->Name;
	}
	return JB_LUB[275];
}

inline bool SC_PA_SyntaxCast(SCParamArray* self) {
	return (self != nil) and self->HasProperParams;
}

inline int SC_Reg_ToInt(AsmReg* self) {
	return self->Reg;
}

inline void SC_nil_SetAllNil(ArchonPurger* self, NilRecord Dest) {
	(*self->Neel) = (Dest & self->Realnesses);
}

inline NilRecord SC_nil_Value(ArchonPurger* self) {
	return (*self->Neel);
}

inline NilState SC_nil__Jump(Message* msg, NilCheckMode Test) {
	return (SC__nil_NilSyxes[msg->Func])(msg, Test);
}

inline bool JB_Array_SyntaxCast(Array* self) {
	return JB_Array_Size(self) > 0;
}

inline bool JB_Err2_SyntaxCast(ErrorInt2 self) {
	return (JB_ivec2_Equals2(self, ivec2{0, 0}, false));
}

inline JB_String* JB_FS_SyntaxCast(FastString* self) {
	return JB_FS_GetResult(self);
}

inline JB_String* JB_Object___Render__(JB_Object* self, FastString* fs_in) {
	Object_Behaviour* Table = ((Object_Behaviour*)JB_ObjClassBehaviours(self));
	return (Table->render)(self, fs_in);
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

inline JB_StringC* JB_Str_CastZero(JB_String* self) {
	return JB_Str_MakeC(self);
}

inline _cstring JB_Str_SyntaxCast(JB_StringC* self) {
	return JB_Str_CString(self);
}

inline int JB_uint64_LELength(uint64 self) {
	return (JB_int_OperatorMax(JB_Int_Log2(((int)self)), 0)) >> 3;
}

inline bool SC_NilTest_SyntaxCast(NilTest* self) {
	return (self != nil) and JB_Str_Exists(self->V2);
}

inline NilState SC_nil_SetNilness(ArchonPurger* self, SCDecl* d, NilState New) {
	NilRecorder* P = ((NilRecorder*)(self->Neel));
	(SC_NRC_SyntaxCallSet((P), d->NilReg, New));
	return New;
}

inline void SC_nil__DeclKill() {
	if ((!SC_nil_NestDepth((&SC__nil_T)))) {
		SC__nil_T.RootReturned = true;
	}
	SC_nil_SetAllNil((&SC__nil_T), kSC__NilState_Basic);
}

inline NilRecord SC_nil__Value() {
	return SC_nil_Value((&SC__nil_T));
}

inline bool JB_Safe_SyntaxCast(JB_String* self) {
	return JB_Str_IsOK(self);
}

inline bool SC_Decl_IsUnknownParam(SCDecl* self) {
	return ((!SC_Decl_NilStated(self))) and (SC_Decl_SyntaxIs(self, kSC__SCDeclInfo_Param));
}

inline NilRecord SC_nil__EndBlock() {
	NilRecord rz = 0;
	rz = SC_nil__Value();
	SC_nil_SetAllNil((&SC__nil_T), kSC__NilState_Basic);
	return rz;
}

inline void SC_Msg_AddValue(Message* self, SCFunction* f) {
	if ((!JB_Ring_HasChildCount(self, 2))) {
		if (true) {
			MessagePosition _usingf0 = JB_Msg_SyntaxUsing(f->Source);
			JB_Tree_SyntaxAppend(self, (JB_Syx_Msg(JB_SyxThg, JB_LUB[1369])));
			JB_MsgPos_SyntaxUsingComplete((&_usingf0));
			JB_MsgPos_Destructor((&_usingf0));
		}
	}
}

inline IR* SC_flat_RequestOp2(ASMFuncState* self, uint Code) {
	IR* rz = nil;
	rz = SC_flat_RequestOp(self);
	rz->Op = Code;
	return rz;
}

inline IR* SC_flat_AddASM(ASMFuncState* self, Message* dbg, int SM, int a, int b, int c, int d) {
	IR* rz = nil;
	rz = SC_flat_RequestOp2(self, SM);
	rz->r[0] = a;
	rz->r[1] = b;
	rz->r[2] = c;
	rz->r[3] = d;
	(SC_IR_DebugSet(rz, dbg));
	if (JB_IsDebug()) {
		SC_IR_Print(rz);
	}
	return rz;
}

inline void SC_flat_AddExtended(ASMFuncState* self, Message* err, uint Bits) {
	int B = 1 << 31;
	if ((((bool)(Bits & B)))) {
		JB_Msg_SyntaxExpect(err, nil);
		return;
	}
	SC_flat_RequestOp2(self, kSC__ASM_Extended)->Rest = (Bits | B);
}

inline SCDecl* SC_TypeOfSwiz(Message* exp, SCNode* name_space, Message* side, SCDecl* class_Space) {
	int W = SC_Class_NumericCount(class_Space->Type);
	if ((W > 1) and (!JB_Ring_HasChildren(((Message*)JB_Ring_Last(exp))))) {
		int swz = SC_Str_IsSwizzle(exp->Name, W);
		if (swz) {
			return SC_TypeOfSwizzle(exp, class_Space, name_space, side, swz);
		}
	}
	return nil;
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
