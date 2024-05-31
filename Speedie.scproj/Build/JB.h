

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

#define __VM__ 1

#define __SPEEDIE__ 1


#ifndef __JB_H__
#define __JB_H__

extern "C" {

//// HEADER AllTypes.h

#ifndef ObjCID
	#define ObjCID void*
#endif

typedef uint ASM;

typedef int ASMMath;

typedef u16 ASMtmp;

typedef int64 AsmReg;

typedef byte CharProp;

typedef int ClassInfo;

typedef int Codepoint;

typedef byte ControlClipMode;

typedef ivec2 ControlLine;

typedef int ControlPoint;

typedef ivec4 ControlRect;

typedef u16 DataTypeCode;

typedef int64 Date;

typedef int DeclMode;

typedef int DotUseType;

typedef byte ErrorFlags;

typedef int ErrorInt;

typedef ivec2 ErrorInt2;

typedef int ErrorMarker;

typedef byte ErrorSeverity;

typedef int FailableInt;

typedef int FileDes;

typedef int FileMode;

typedef bool FileResolveMode;

typedef int64 FileSizeInt;

typedef vec4 FloatRangeConverter;

typedef vec2 FloatRangeConverterBasic;

typedef int FlowControlStopper;

typedef int FunctionType;

typedef int Ind;

typedef ivec2 IntRange;

typedef byte MaybeBool;

typedef byte MoveCode;

typedef u16 MsgParseFlags;

typedef int NilCheckMode;

typedef byte NilReason;

typedef uint64 NilRecord;

typedef byte NilState;

typedef int OpMode;

typedef int PID_Int;

typedef byte ProcessMode;

typedef int SCBlockage;

typedef int SCDeclInfo;

typedef int SCNodeFindMode;

typedef int SCNodeInfo;

typedef byte SCNodeType;

typedef int SizeInt;

typedef byte Syntax;

typedef byte TaskState;

typedef int TerminalColor;

typedef uint64 __junktest_7__;

typedef int jbinLeaver;

typedef vec4 mat2;

typedef u16 ASMParam;

typedef ASM ASM_BClear;

typedef ASM ASM_BCmp;

typedef ASM ASM_BFLD;

typedef ASM ASM_Bra;

typedef ASM ASM_CNTC;

typedef ASM ASM_Cmp;

typedef ASM ASM_CmpD;

typedef ASM ASM_CmpEq;

typedef ASM ASM_Const;

typedef ASM ASM_ConstStretchy;

typedef ASM ASM_Div;

typedef ASM ASM_Float;

typedef ASM ASM_FloatAddExp;

typedef ASM ASM_FloatConst;

typedef ASM ASM_Func;

typedef ASM ASM_Mem;

typedef ASM ASM_RET;

typedef ASM ASM_SWAP;

typedef ASM ASM_Setn;

typedef ASM ASM_Tail;

typedef ASM ASM_Trap;

typedef ASM ASM_U0;

typedef ASM ASM_U1;

typedef ASM ASM_U2;

typedef ASM ASM_U3;

typedef ASM ASM_U4;

typedef Date HumanDate;

struct ASMState;

struct ASMVarType;

struct ArchonPurger;

struct ArgArrayCounter;

struct CharProps;

struct CompressionStats;

struct FakeJBString;

struct FastBuff;

struct FatASM;

struct FloatRange;

struct IntDownRange;

struct IsaTester;

struct LoopInfo;

struct Mat4;

struct MessagePosition;

struct MiniHuffItem;

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

struct xD1x9B;

struct ByteMap_Behaviour;

struct Charset_Behaviour;

struct ContainerStruct2;

struct CppRefs_Behaviour;

struct Cpp_Export_Behaviour;

struct DataObject_Behaviour;

struct DictionaryReader_Behaviour;

struct ErrorReceiver_Behaviour;

struct FastString_Behaviour;

struct FileComparer_Behaviour;

struct FixedDict_Behaviour;

struct FlowControl_Behaviour;

struct HuffByteCoder_Behaviour;

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

struct ContainerStruct;

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

struct HuffNode_Behaviour;

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

struct HuffByteCoder;

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

struct MWrap;

struct Dictionary;

struct JB_File;

struct HuffNode;

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

typedef ASM (*ASM_Encoder2)(FatASM* self);

typedef SCNode* (*FP_CollectFunc)(Message* node, SCNode* name_space, Message* ErrPlace);

typedef SCObject* (*FP_ExprResolver)(Message* Exp, SCNode* name_space, Message* Side);

typedef NilState (*FP_NilTrackerFn)(Message* msg, NilCheckMode Test);

typedef Message* (*FP_ParseHandler)(int Start, Message* Parent);

typedef void (*FP_SaverLoadClass)(JB_Class* cls, char* Data);

typedef bool (*FP_ShellOption)(JB_String* Name, JB_String* Value, FastString* Purpose);

typedef bool (*FP_SorterComparer)(JB_Object* a, JB_Object* b);

typedef bool (*FP_SorterComparerDecl)(SCDecl* a, SCDecl* b);

typedef bool (*FP_SorterComparerFn)(SCFunction* a, SCFunction* b);

typedef bool (*FP_SpdMainFn)(void* Obj, _cstring* args, PicoComms* Comms);

typedef JB_Object* (*TokenHandler_fp)(int Start, Message* Parent);

typedef void (*FP_TranFunc)(SCFunction* Fn, Message* node, SCNode* name_space);

typedef JB_String* (*__Message_CopyID__)(Message* self);

typedef void (*__Saveable_LoadProperties__)(Saveable* self, ObjectLoader* Loader);

typedef JB_String* (*__Object_Render__)(JB_Object* self, FastString* Fs_in);

typedef void (*__Saveable_SaveCollect__)(Saveable* self, ObjectSaver* Saver);

typedef void (*__Saveable_SaveWrite__)(Saveable* self, ObjectSaver* Saver);

typedef bool (*__Message_TextSet__)(Message* self, int I, JB_String* V);

typedef JB_String* (*__Message_Text__)(Message* self, int I);

typedef bool (*autosort_fn)(autoitem* a, autoitem* b);

typedef void (*FP_fnErrorLogger)(JB_ErrorReceiver* self, JB_String* Data);

typedef JB_String* (*FP_fnIDGenerator)(int Start, int End, Syntax F);

typedef bool (*FP_fnPreReader)(SCFunction* self, Message* msg);

typedef AsmReg (*fn_OpASM)(ASMState* self, AsmReg Dest, AsmReg L, AsmReg R, Message* exp);

typedef AsmReg (*fn_asm)(ASMState* self, Message* exp, AsmReg Dest, int Mode);

typedef void (*FP_fpMsgRender)(Message* self, FastString* fs);

typedef void (*FP_fpMsgRenderCpp)(Message* self, FastStringCpp* fs);

typedef bool (*Task_LessThan3_interface_prototype)(JB_Task* self, int I);

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

//// HEADER Proj.h

struct ASMState {
	SCFunction* fn;
	ASMFunc* Out;
	FatASM* Start;
	FatASM* Curr;
	FatASM* End;
	FatASM* WhileStart;
	bool OK;
	bool Inited;
	byte LabelCount;
	DataTypeCode ReturnType;
	byte VDecls;
	byte VTmps;
	uint64 Consts[32];
};

struct ArchonPurger {
	NilRecord* Neel;
	NilRecord* RowEnd;
	NilRecord Realnesses;
	SCDecl* Decls[32];
	SCDecl* Return;
	int InsideBoolLogic;
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
	bool Owns;
	bool WentBad;
};

struct FatASM {
	uint R[6];
	byte Op;
	byte Label;
	u16 FileNum;
	int BytePos;
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
	int Length;
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
	Array* Disturbs;
	u16 DisturbParams;
	bool Owned;
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
	FastStringCpp* Syxes;
	FastStringCpp* Inlines;
	FastStringCpp* ModuleProperties;
);

struct DataObject_Behaviour: Object_Behaviour {
};

JBClass ( DTWrap , JB_Object , 
	int64 PrivValue;
	DataTypeCode DataType;
	byte DeathAction;
);

struct DictionaryReader_Behaviour: Object_Behaviour {
};

struct ErrorReceiver_Behaviour: Object_Behaviour {
};

JBClass ( JB_ErrorReceiver , JB_Object , 
	int MaxErrors;
	JB_Object* _LogObj;
	JB_Error* Errors;
	JB_String* Source;
	int MaxProblems;
	int ErrorCount;
	int ProblemCount;
	int WarnCount;
	int LowerErrorsTo;
	bool BlockErrors;
	FP_fnErrorLogger _LogFunc;
);

struct FastString_Behaviour: Object_Behaviour {
};

struct FlowControl_Behaviour: Object_Behaviour {
};

JBClass ( FlowControl , JB_Object , 
	StringReader* ReadInput;
	FastString* Write;
	FastString* Excuse;
	FastBuff Buff;
);

struct Instruction_Behaviour: Object_Behaviour {
};

JBClass ( Instruction , JB_Object , 
	xC2xB5Form* Sizes;
	JB_String* FormName;
	JB_String* Name;
	byte aType;
	byte PCount;
	byte OpCode;
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
	JB_String* Input;
	Message* _Parsed;
	bool Cleaned;
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
	int Depth;
	JB_File* Where;
	SCFile* Conf;
	Array* Files;
	JB_MemoryLayer* DeclLayer;
	SCModule* Mod;
	Dictionary* Resources;
	bool WarnUnusedFuncs;
	ErrorSeverity BlindCast;
	bool IsSTDLib;
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
	int LinkedFrom;
	Message* Source;
	Array* LinkFrom;
	SCNodeInfo NodeInfo;
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
	SCOperator* Opposite;
	OpMode Kind;
	ASMMath Code;
	fn_OpASM ASM;
);

struct SCParamArray_Behaviour: Object_Behaviour {
};

JBClass ( SCParamArray , JB_Object , 
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
	Message* Items[11];
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
	JB_File* File;
	JB_Object* UserObj;
	int ChunkSize;
	int StartFrom;
	bool _NoMoreChunks;
	FastBuff Data;
);

struct SyntaxObj_Behaviour: Object_Behaviour {
};

JBClass ( SyntaxObj , JB_Object , 
	JB_String* Name;
	JB_String* LongName;
	Syntax ID;
	FP_fpMsgRender ExportAddr;
	FP_fpMsgRender RenderAddr;
);

struct TerminalCell_Behaviour: Object_Behaviour {
};

JBClass ( TerminalCell , JB_Object , 
	int Color;
	JB_String* Text;
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
	int Count;
	ASMParam Params[6];
	JB_String* Name;
	int TotalBits;
	int Index;
);

struct xC2xB5Func_Behaviour: Object_Behaviour {
};

JBClass ( ASMFunc , JB_Object , 
	int Length;
	FatASM* IR;
	SCFunction* Fn;
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

struct Message_Behaviour: list_Behaviour {
	__Message_CopyID__ copyid;
	__Message_Text__ text;
	__Message_TextSet__ textset;
};

JBClass ( Message , JB_List , 
	JB_String* Name;
	JB_Object* Obj;
	u16 RangeLength;
	MsgParseFlags Flags;
	u16 Tag;
	byte Indent;
	Syntax Func;
);

struct MessageID_Behaviour: StringShared_Behaviour {
};

JBClass ( MessageID , JB_StringShared , 
	JB_Object* Obj;
	uint64 ID;
	uint64 Frequency;
	int Position;
	Syntax Func;
);

struct SCDecl_Behaviour: SCNamed_Behaviour {
};

JBClass ( SCDecl , SCNamed , 
	uint64 ExportPosition;
	SCFunction* HiderFunc;
	JB_Object* IsLookupOnly;
	JB_String* StringData;
	SCDecl* Internal;
	SCDecl* Contains;
	Message* Default;
	SCClass* Type;
	int C_Array;
	SCDeclInfo Info;
	DataTypeCode DType;
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
	u16 FileNum;
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
	int DeathLimit;
	int DiedCount;
	bool WeAreParent;
	bool AlreadyWarnedDied;
	ProcessMode Mode;
	FP_SpdMainFn SubProcess;
);

struct Task_Behaviour: list_Behaviour {
};

JBClass ( JB_Task , JB_List , 
	void* _func;
	int _Object;
	TaskState State;
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
	ClassInfo Flags;
	DataTypeCode TypeInfo;
	u16 Size;
	u16 TaskObjectCount;
	byte Depth;
	byte MinOpt;
	byte IsBehaviour;
	byte IsWrapper;
	byte IsRole;
	SCNodeType BaseType;
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
	FunctionType FuncInfo;
	u16 TmpCounter;
	u16 TableId;
	u16 LinkDepth;
	byte MinOpt;
	byte IsAssigns;
	byte IsCppInBuilt;
	ErrorSeverity BlindCasts;
	byte IsNilChecker;
	NilState NilSelf;
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
extern Array* JB__App__OldArgs;
extern JB_String* JB__App__Path;
extern Message* JB__App__Prefs;
extern JB_File* JB__App__stdin;
extern JB_File* JB__App__StdOut;
extern JB_String* JB__App_Usage;
extern JB_String* SC__AutoComplete_function_names;
extern Dictionary* SC__AutoComplete_Functions;
extern Dictionary* SC__AutoComplete_Owner;
extern JB_File* SC__Comp__BuildFolder;
extern JB_String* SC__Comp__Projects;
extern JB_String* SC__Comp__SpeedieProj;
extern Array* SC__Comp_ActualSyxes;
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
extern Dictionary* SC__Comp_Numbers;
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
#define kSC__CustomOps_Needed (64)
#define kSC__CustomOps_NotCustom (0)
#define kSC__CustomOps_OnlyLeftIsVector (65)
#define kSC__CustomOps_OnlyRightIsVector (66)
#define kSC__CustomOps_TypeCastFromBool (16)
#define kSC__CustomOps_TypeCastToBetter (32)
#define kJB__ErrorColors_bold (JB_LUB[94])
extern bool JB__ErrorColors_Enabled;
#define kJB__ErrorColors_error (JB_LUB[91])
#define kJB__ErrorColors_good (JB_LUB[92])
#define kJB__ErrorColors_normal (JB_LUB[95])
#define kJB__ErrorColors_underline (JB_LUB[92])
#define kJB__ErrorColors_warn (JB_LUB[93])
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
extern u16 JB__API_NilHappened_;
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
extern JB_String* JB__Constants_FFUUU;
extern Dictionary* JB__Constants_JS_EscapeStr;
extern Dictionary* JB__Constants_JS_UnEscapeStr;
extern Dictionary* JB__Constants_UnEscapeStr;
extern Dictionary* JB__Constants_XML_EscapeStr;
extern Dictionary* JB__Constants_XML_UnEscapeStr;
extern CharSet* JB__Constants_XMLWordMiddle;
extern int SC__LinkMap_CurrID;
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
extern int SC__Options_Dev;
extern bool SC__Options_ExternalCompile;
extern bool SC__Options_Final;
extern bool SC__Options_ForceRecompile;
extern bool SC__Options_GenFlowControlCode;
extern bool SC__Options_HideMultipleErrors;
extern bool SC__Options_IgnoreCantSaveErrors;
extern bool SC__Options_IsDirectTest;
extern bool SC__Options_KeepAllErrors;
extern bool SC__Options_MakeInterpreter;
extern bool SC__Options_MakeLib;
extern bool SC__Options_ModeCpp;
extern bool SC__Options_ModePack;
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
extern int SC__PackMaker_ExportPos;
extern Array* SC__PackMaker_LibFuncs;
extern Array* SC__PackMaker_LibGlobs;
extern Array* SC__PackMaker_PackFuncs;
extern Array* SC__PackMaker_PackGlobs;
extern JB_File* JB__Platform_Logger_;
extern Message* SC__PostIncrementNil_Msgs[32];
extern int SC__PostIncrementNil_Size;
extern bool SC__PostIncrementNil_Sync;
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
extern Message* SC__SCStrings_RenderFinish;
extern Message* SC__SCStrings_RenderInsides;
extern Message* SC__SCStrings_RenderNewParams;
extern Macro* SC__SCTasks_TaskMacro;
extern Message* SC__SCTasks_tmp;
extern Dictionary* SC__Errors_IgnoredBranches;
extern Dictionary* SC__SC_Targets_Items;
extern Array* SC__SpdAssembler_PackFuncs;
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
extern Array* JB__Terminal_TermScreen;
#define kJB__Terminal_w (80)
#define kJB__Terminal_White (37)
#define kJB__Terminal_Yellow (33)
extern Dictionary* SC__TextAssembler_LabelsToDo;
extern Array* SC__Ext_Cleanup;
extern int SC__Ext_CompilingLibFiles;
extern JB_String* SC__Ext_CppCompilerPath;
extern Array* SC__Ext_FoundObjects;
extern Date SC__Ext_LatestLibDate;
extern Message* SC__VM_Builder_dt_prm;
extern FastString* SC__VM_Builder_form_h;
extern Message* SC__VM_Builder_ModuleArg;
extern Array* SC__VM_Builder_NameList;
extern byte SC__VM_Builder_NormalPos;
extern JB_String* SC__VM_Builder_parent;
extern int SC__VM_Builder_Total;
extern JB_File* SC__VM_Builder_vm_file;
#define kSC____junktest_5___a (0)
#define kSC____junktest_5___b (1)
#define kSC____junktest_5___c (2)
extern int SC____junktest_5___x[3];
extern JB_String* SC___AppConfString;
extern SyntaxObj* JB__FuncArray_[64];
extern JB_String* JB__JbinHeader;
extern JB_String* JB__jBinNotJbin;
extern bool _once1;
extern bool _once2;
extern Dictionary* JB__SyxDict_;
extern CharSet* SC_C_Letters;
extern Dictionary* SC_ClassLinkageTable;
extern Dictionary* SC_ClsCollectTable;
#define kJB_codesign_native (JB_LUB[1460])
extern Dictionary* SC_CppRefTable;
extern CharSet* SC_CSHex;
extern CharSet* SC_CSNum;
extern JB_ErrorReceiver* SC_ErrorDelayer;
extern FP_ExprResolver SC_ExprFuncs[64];
extern SCDecl* SC_FalseBool;
extern fn_asm SC_fn_asm_table[64];
extern FastString* SC_fs_tmp_num;
extern Dictionary* SC_FuncLinkageTable;
extern Dictionary* SC_FuncPreReader;
#define kJB_kActualTypecasts ((~(128 | 32)))
#define kJB_kAddressOfMatch (3 << 22)
#define kJB_kCastedMatch (6 << 22)
#define kJB_kLossyCastedMatch (7 << 22)
extern JB_String* SC_kNameConf;
#define kJB_kNeeds ((16 << 22) | ((32 << 22) | (64 << 22)))
#define kJB_kNeedsAddressOf (32 << 22)
#define kJB_kNeedsAddressOfButAlsoNeedsSuperMatch (64 << 22)
#define kJB_kNeedsTypeCast (16 << 22)
#define kJB_kNoBoolTypeCast (32)
#define kJB_kNoMatch (0)
#define kJB_kNumericMatch (2 << 22)
#define kJB_kSaverEnd (JB_LUB[0])
#define kJB_kSaverStart1 (JB_LUB[489])
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
#define kJB_kUsingStr (JB_LUB[782])
#define kJB_kVoidPtrMatch (5 << 22)
extern Message* SC_ReturnSelfEqNil;
extern Dictionary* SC_RootCollectTable;
extern JB_ErrorReceiver* JB_StdErr;
#define kJB_SyxAcc (29)
#define kJB_SyxAdj (27)
#define kJB_SyxARel (21)
#define kJB_SyxArg (1)
#define kJB_SyxArr (34)
#define kJB_SyxAsk (43)
#define kJB_SyxBack (16)
#define kJB_SyxBadj (28)
#define kJB_SyxBin (18)
#define kJB_Syxbinn (42)
#define kJB_SyxBra (31)
#define kJB_SyxBRel (26)
#define kJB_SyxChar (17)
#define kJB_SyxCnj (8)
#define kJB_SyxDecl (4)
#define kJB_SyxDot (23)
#define kJB_SyxEmb (2)
#define kJB_SyxERel (38)
#define kJB_SyxFile (35)
#define kJB_SyxFunc (25)
#define kJB_SyxItem (30)
#define kJB_SyxList (32)
#define kJB_Syxmax (55)
#define kJB_SyxMsg (46)
#define kJB_SyxName (22)
#define kJB_SyxNil (0)
#define kJB_SyxNum (14)
#define kJB_SyxOat (6)
#define kJB_SyxOpp (9)
#define kJB_Syxpinn (41)
#define kJB_SyxPrm (33)
#define kJB_SyxQues (7)
#define kJB_SyxQuot (36)
#define kJB_SyxRel (37)
#define kJB_SyxSCnj (12)
#define kJB_SyxSCom (45)
#define kJB_SyxSDot (24)
#define kJB_SyxSheb (11)
#define kJB_SyxSStr (15)
#define kJB_SyxSThg (13)
#define kJB_SyxStr (19)
#define kJB_SyxThg (10)
#define kJB_SyxTmp (5)
#define kJB_SyxTodo (47)
#define kJB_SyxTRel (39)
#define kJB_SyxTril (40)
#define kJB_SyxType (3)
#define kJB_SyxUnit (20)
#define kJB_Syxurl (48)
#define kJB_SyxXAtt (49)
#define kJB_SyxXCDT (53)
#define kJB_SyxXCom (52)
#define kJB_SyxXML (50)
#define kJB_SyxXPI (51)
#define kJB_SyxXTxt (54)
#define kJB_SyxYoda (44)
extern SCDecl* SC_TrueBool;
extern SCClass* SC_TypeArray;
extern SCClass* SC_TypeBool;
extern SCClass* SC_TypeByte;
extern SCClass* SC_TypeCharSet;
extern SCClass* SC_TypeCodePoint;
extern SCClass* SC_TypeDate;
extern SCClass* SC_TypeDictionary;
extern SCClass* SC_Typef64;
extern SCClass* SC_TypeFastString;
extern SCClass* SC_Typefloat;
extern SCClass* SC_Typehfloat;
extern SCClass* SC_TypeInt;
extern SCClass* SC_TypeInt16;
extern SCClass* SC_TypeInt64;
extern SCClass* SC_TypeiVec2;
extern SCClass* SC_TypeiVec3;
extern SCClass* SC_TypeiVec4;
extern SCClass* SC_TypeJBClass;
extern SCDecl* SC_TypeNil;
extern SCClass* SC_TypeObject;
extern SCClass* SC_TypeSaveable;
extern SCClass* SC_TypeString;
extern SCClass* SC_TypeStringZero;
extern SCClass* SC_TypeSyntax;
extern SCClass* SC_TypeTask;
extern SCClass* SC_TypeuInt;
extern SCClass* SC_TypeuInt16;
extern SCClass* SC_TypeuInt64;
extern SCClass* SC_TypeVec2;
extern SCClass* SC_TypeVec3;
extern SCClass* SC_TypeVec4;
extern SCDecl* SC_TypeVoid;
extern SCClass* SC_TypeVoid_;
extern SCDecl* SC_TypeVoidPtr;
extern SCClass* SC_TypeWrapper;
extern bool JB__Tk__DotInsertAllow;
extern Message* JB__Tk__EndOfLineMarker;
extern Dictionary* JB__Tk__ErrorNames;
extern u16 JB__Tk__StopBars;
extern JB_String* JB__Tk_Data;
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
extern FP_fnIDGenerator JB__Tk_Splitter;
extern MessagePosition JB__Tk_Using;
#define kJB__zalgo_down (JB_LUB[2026])
#define kJB__zalgo_mid (JB_LUB[2025])
extern Random JB__zalgo_R;
#define kJB__zalgo_up (JB_LUB[2024])
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
#define kSC__ASM_ADD (23)
#define kSC__ASM_ADDK (24)
#define kSC__ASM_BAND (31)
#define kSC__ASM_BCLR (40)
#define kSC__ASM_BCMP (41)
#define kSC__ASM_BFLG (36)
#define kSC__ASM_BFLS (37)
#define kSC__ASM_BNOT (35)
#define kSC__ASM_BOAR (32)
#define kSC__ASM_BRAA (50)
#define kSC__ASM_BRAN (51)
#define kSC__ASM_BROL (38)
#define kSC__ASM_BROR (39)
#define kSC__ASM_BXNR (34)
#define kSC__ASM_BXOR (33)
#define kSC__ASM_CMPF (44)
#define kSC__ASM_CMPI (43)
#define kSC__ASM_CNTC (71)
#define kSC__ASM_CNTD (72)
#define kSC__ASM_CONV (21)
#define kSC__ASM_DIVV (27)
extern ASM_Encoder2 SC__ASM_Encoders[256];
#define kSC__ASM_EROR (0)
#define kSC__ASM_FADD (75)
#define kSC__ASM_FADK (76)
#define kSC__ASM_FDIV (79)
#define kSC__ASM_FEXK (74)
#define kSC__ASM_FFRC (80)
#define kSC__ASM_FMLK (78)
#define kSC__ASM_FMUL (77)
#define kSC__ASM_FNCX (5)
#define kSC__ASM_FNCX2 (5)
#define kSC__ASM_FNCX3 (6)
extern ASM_Encoder2 SC__ASM_Forms[32];
#define kSC__ASM_FUNC (1)
#define kSC__ASM_FUNC2 (1)
#define kSC__ASM_FUNC3 (2)
#define kSC__ASM_JMPE (48)
#define kSC__ASM_JMPF (47)
#define kSC__ASM_JMPI (46)
#define kSC__ASM_JMPN (49)
#define kSC__ASM_JUMP (45)
#define kSC__ASM_KNST (4)
#define kSC__ASM_KNST1 (4)
#define kSC__ASM_KNST2 (13)
#define kSC__ASM_KNST3 (10)
#define kSC__ASM_KSTR (22)
#define kSC__ASM_LUPD (53)
#define kSC__ASM_LUPU (52)
#define kSC__ASM_MEMM (73)
#define kSC__ASM_MULT (26)
extern byte SC__ASM_NoisyASM;
#define kSC__ASM_PRNT (19)
#define kSC__ASM_RALO (56)
#define kSC__ASM_RARE (20)
#define kSC__ASM_RD16 (65)
#define kSC__ASM_RD1S (59)
#define kSC__ASM_RD1U (58)
#define kSC__ASM_RD2S (61)
#define kSC__ASM_RD2U (60)
#define kSC__ASM_RD4S (63)
#define kSC__ASM_RD4U (62)
#define kSC__ASM_RD8U (64)
#define kSC__ASM_RET (17)
#define kSC__ASM_RSDE (54)
#define kSC__ASM_RSET (55)
#define kSC__ASM_SHLU (30)
#define kSC__ASM_SHRS (28)
#define kSC__ASM_SHRU (29)
#define kSC__ASM_SUBB (25)
#define kSC__ASM_SWAP (18)
#define kSC__ASM_TABL (57)
#define kSC__ASM_TAIL (9)
#define kSC__ASM_TAIL2 (9)
#define kSC__ASM_TERN (42)
#define kSC__ASM_TRAP (16)
#define kSC__ASM_WR16 (70)
#define kSC__ASM_WR1U (66)
#define kSC__ASM_WR2U (67)
#define kSC__ASM_WR4U (68)
#define kSC__ASM_WR8U (69)
#define kSC__ASMMath_Add ((1 << 16))
#define kSC__ASMMath_All (kSC__ASMMath_BitCorrect)
#define kSC__ASMMath_BAn ((12 << 16))
#define kSC__ASMMath_BitCorrect ((31 << 16))
#define kSC__ASMMath_BNt ((11 << 16))
#define kSC__ASMMath_BOr ((13 << 16))
#define kSC__ASMMath_Div ((4 << 16))
#define kSC__ASMMath_Mod ((5 << 16))
#define kSC__ASMMath_Mul ((3 << 16))
#define kSC__ASMMath_ROL ((6 << 16))
#define kSC__ASMMath_ROR ((7 << 16))
#define kSC__ASMMath_Shl ((8 << 16))
#define kSC__ASMMath_Shrs ((10 << 16))
#define kSC__ASMMath_Shru ((9 << 16))
#define kSC__ASMMath_Sub ((2 << 16))
#define kSC__ASMMath_Xnr ((15 << 16))
#define kSC__ASMMath_Xor ((14 << 16))
#define kSC__ASMtmp_ImmediatesOnly (2)
#define kSC__ASMtmp_IncrAfter (2)
#define kSC__ASMtmp_IncrBefore (0)
#define kSC__ASMtmp_kContinue (51)
#define kSC__ASMtmp_kDebugger (61)
#define kSC__ASMtmp_kElseIf (48)
#define kSC__ASMtmp_kExit (52)
#define kSC__ASMtmp_kFail (63)
#define kSC__ASMtmp_kIf (49)
#define kSC__ASMtmp_kIgnore (60)
#define kSC__ASMtmp_kPointer (59)
#define kSC__ASMtmp_kRejoin (54)
#define kSC__ASMtmp_kReturn (53)
#define kSC__ASMtmp_kSetVar (58)
#define kSC__ASMtmp_kStatExpr (57)
#define kSC__ASMtmp_kSwap (55)
#define kSC__ASMtmp_kTern (56)
#define kSC__ASMtmp_kWhile (50)
extern ASM_Mem SC__ASMtmp_ReadASM[10];
extern ASM_Mem SC__ASMtmp_WriteASM[5];
#define kSC__Reg_AddrRequest (4398046511104)
#define kSC__Reg_AlreadyNegated (137438953472)
#define kSC__Reg_Alternate (274877906944)
#define kSC__Reg_Arg (8589934592 | 4294967296)
#define kSC__Reg_Cond (549755813888)
#define kSC__Reg_CondRequest (70368744177664 | 4294967296)
#define kSC__Reg_ConstAny (140737488355328)
#define kSC__Reg_ContainsAddr (17179869184)
#define kSC__Reg_ForReturn (8796093022208)
#define kSC__Reg_FromMath (34359738368)
#define kSC__Reg_MathConst (140737488355328 | 34359738368)
#define kSC__Reg_Negate (1099511627776)
#define kSC__Reg_NewCondRequest (70368744177664)
#define kSC__Reg_NotYetUsed (8589934592)
#define kSC__Reg_Set (2199023255552)
#define kSC__Reg_SingleExpr (35184372088832)
#define kSC__Reg_SrcConst (4294967296)
#define kSC__Reg_StayOpen (68719476736)
#define kSC__Reg_Temp (17592186044416)
#define kSC__Reg_Zero (kSC__Reg_SrcConst)
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
#define kSC__ClassInfo_ASM (524288)
#define kSC__ClassInfo_AutoGeneratedSavers (64)
#define kSC__ClassInfo_Banned (512)
#define kSC__ClassInfo_Builtin (16384)
#define kSC__ClassInfo_ContainsParentClass (1)
#define kSC__ClassInfo_DefaultsToReal (2048)
#define kSC__ClassInfo_Fixed (131072)
#define kSC__ClassInfo_Flags (262144)
#define kSC__ClassInfo_HasCompareFunc (4)
#define kSC__ClassInfo_HasEqualsFunc (8)
#define kSC__ClassInfo_HasNilChecker (1024)
#define kSC__ClassInfo_HasSubClass (16)
#define kSC__ClassInfo_IgnoreContainedSelf (2)
#define kSC__ClassInfo_IsRole (4096)
#define kSC__ClassInfo_IsTask (8192)
#define kSC__ClassInfo_NoEarlyFree (32)
#define kSC__ClassInfo_NumericReduction ((65536 | 131072) | 262144)
#define kSC__ClassInfo_SavingCanSkip (128)
#define kSC__ClassInfo_SortsProperties (32768)
#define kSC__ClassInfo_Symbol (65536)
#define kSC__ClassInfo_TreatAsBaseType (256)
#define kJB__ControlClipMode_Debug (4)
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
#define kJB__TC_Failed (32768)
#define kJB__TC_Float (0 + (32 + (64 + (128 + 8))))
#define kJB__TC_HFloat (0 + (16 + (64 + (128 + 8))))
#define kJB__TC_Int (0 + (32 + (64 + (0 + 8))))
#define kJB__TC_int16 (0 + (16 + (64 + (0 + 8))))
#define kJB__TC_int64 (0 + (48 + (64 + (0 + 8))))
#define kJB__TC_int8 (kJB__TC_char)
#define kJB__TC_iVec2 (1 + (32 + (64 + (0 + 8))))
#define kJB__TC_iVec3 (2 + (32 + (64 + (0 + 8))))
#define kJB__TC_iVec4 (3 + (32 + (64 + (0 + 8))))
#define kJB__TC_numeric (8)
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
#define kJB__Date_Highest (9223372036854775807)
#define kJB__Date_kOneStep (0.000015258789f)
#define kJB__Date_kSecondsPerDay (86400)
#define kJB__Date_kSecondsPerMonthApprox (2628000)
#define kJB__Date_kSecondsPerWeek (604800)
#define kSC__DeclMode_Always (64)
#define kSC__DeclMode_FuncParam (4)
#define kSC__DeclMode_FunctionBody (8)
#define kSC__DeclMode_Globals (1)
#define kSC__DeclMode_Local (4 + 8)
#define kSC__DeclMode_Properties (3)
#define kSC__DeclMode_Proto (16)
#define kSC__DeclMode_ProtoParam (4 + 16)
#define kSC__DeclMode_TypeCast (32)
#define kSC__DotUseType_Memory (2)
#define kSC__DotUseType_Property (1)
#define kJB__ErrorFlags_DontStrip (1)
#define kJB__ErrorFlags_Keep (0)
#define kJB__ErrorFlags_Parse (4)
#define kJB__ErrorFlags_PreferNoRenderPath (2)
#define kJB__ErrorFlags_PrintAndKeep (1)
#define kJB__ErrorFlags_PrintAndRemove (2)
extern Array* JB__ErrorSeverity__names;
#define kJB__ErrorSeverity_Critical (5)
#define kJB__ErrorSeverity_Error (4)
#define kJB__ErrorSeverity_Hint (1)
#define kJB__ErrorSeverity_MaxError (6)
#define kJB__ErrorSeverity_OK (0)
#define kJB__ErrorSeverity_Problem (3)
#define kJB__ErrorSeverity_Warning (2)
#define kJB__FailableInt_Fail (2147483648)
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
#define kSC__FunctionType_API (8388608)
#define kSC__FunctionType_AutoGeneratedSaver (16777216)
#define kSC__FunctionType_Behaviour (2048)
#define kSC__FunctionType_Comparison (4)
#define kSC__FunctionType_ConOrDes (1 + 2)
#define kSC__FunctionType_Constructor (1)
#define kSC__FunctionType_Destructor (2)
#define kSC__FunctionType_Disabled (2097152)
#define kSC__FunctionType_EmptyConstructor (512)
#define kSC__FunctionType_ExpectsRealVars (8192)
#define kSC__FunctionType_ExternalLib (131072)
#define kSC__FunctionType_FlowDisabled (65536)
#define kSC__FunctionType_HidesProperties (33554432)
#define kSC__FunctionType_InitFunc (128)
#define kSC__FunctionType_Inline (524288)
#define kSC__FunctionType_Killer (1048576)
#define kSC__FunctionType_NewNew (4096)
#define kSC__FunctionType_NewStruct (16)
#define kSC__FunctionType_NoRefCounts (4194304)
#define kSC__FunctionType_NumberCreator (32)
#define kSC__FunctionType_Recursive (256)
#define kSC__FunctionType_Reffer (8)
#define kSC__FunctionType_Render (32768)
#define kSC__FunctionType_TypeTest (64)
#define kSC__FunctionType_VirtualCaller (1024)
#define kSC__FunctionType_Wrapper (262144)
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
#define kJB__MsgParseFlags_MacroInserted (12288)
#define kJB__MsgParseFlags_MacroMade (8192)
#define kJB__MsgParseFlags_NicelyPositioned (1024)
#define kJB__MsgParseFlags_Style2 (16384)
#define kSC__khalai_Active (2 + 1)
#define kSC__khalai_And (8)
#define kSC__khalai_Basic ((2 + 1) + 4)
#define kSC__khalai_Disappears (64)
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
#define kSC__OpMode_Addition (16)
#define kSC__OpMode_AND (65536)
#define kSC__OpMode_AndOr (32768 | 65536)
#define kSC__OpMode_Assigns (2)
#define kSC__OpMode_Bit (4)
#define kSC__OpMode_CaseAware (262144)
#define kSC__OpMode_Compare (1)
#define kSC__OpMode_Comparison (512)
#define kSC__OpMode_CompSet (1 | 2)
#define kSC__OpMode_Custom (131072)
#define kSC__OpMode_EqualOrNot (256)
#define kSC__OpMode_ExactEquals (4096 + (128 + (256 + 1)))
#define kSC__OpMode_ExactlyEquals (128)
#define kSC__OpMode_ExactNotEquals (4096 + (256 + 1))
#define kSC__OpMode_Less (2048)
#define kSC__OpMode_LoseBits (16384)
#define kSC__OpMode_MakesSigned (64)
#define kSC__OpMode_Math (8)
#define kSC__OpMode_MathLike (4 | 8)
#define kSC__OpMode_More (1024)
#define kSC__OpMode_NeedsCppFuncOnFloats (524288)
#define kSC__OpMode_NilTest (4096)
#define kSC__OpMode_NoExtraBits (8192)
#define kSC__OpMode_OR (32768)
#define kSC__OpMode_SameOrLessBits (8192 | 16384)
#define kSC__OpMode_Shift (32 + 8192)
#define kSC__OpMode_ShiftOnly (32)
#define kJB__ProcessMode_AutoPrintErrors (4)
#define kJB__ProcessMode_CaptureAll (1 | 4)
#define kJB__ProcessMode_CaptureErrors (2)
#define kJB__ProcessMode_CaptureOrPrintErrors (2 | 4)
#define kJB__ProcessMode_CaptureStdOut (1)
#define kSC__SCBlockage_Bits (480)
#define kSC__SCBlockage_Continue (64)
#define kSC__SCBlockage_Exit (128)
#define kSC__SCBlockage_Quit (kSC__SCBlockage_Return)
#define kSC__SCBlockage_Return (192)
#define kSC__SCDeclInfo_Altered (1048576)
#define kSC__SCDeclInfo_AlteredViaPointer (524288)
#define kSC__SCDeclInfo_API (512)
#define kSC__SCDeclInfo_Atomic (8388608)
#define kSC__SCDeclInfo_Biggest (134217728)
#define kSC__SCDeclInfo_Body (32768)
#define kSC__SCDeclInfo_Borrowed (1)
#define kSC__SCDeclInfo_ClassObj (1024)
#define kSC__SCDeclInfo_CompilerCreated (2048)
#define kSC__SCDeclInfo_Const (8)
#define kSC__SCDeclInfo_DclCopied (1048576 + (2 + (16 + (512 + (32 + 2048)))))
#define kSC__SCDeclInfo_DirectNumber (4)
#define kSC__SCDeclInfo_Disabled (8192)
#define kSC__SCDeclInfo_GameFlyingMem (2097152)
#define kSC__SCDeclInfo_Global (131072)
#define kSC__SCDeclInfo_Hidden (67108864)
#define kSC__SCDeclInfo_Local (32768 + 16384)
#define kSC__SCDeclInfo_NewlyCreated (64)
#define kSC__SCDeclInfo_NumberConst (4 + 8)
#define kSC__SCDeclInfo_Param (16384)
#define kSC__SCDeclInfo_PostIncremented (268435456)
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
#define kSC__SCNodeFindMode_ForClass (8)
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
extern int JB__Syx_CurrFuncID_;
#define kJB__TaskState_Animation (16)
#define kJB__TaskState_Finished (64)
#define kJB__TaskState_HadErrors (8)
#define kJB__TaskState_Paused (2)
#define kJB__TaskState_Started (1)
#define kJB__TaskState_Successful (32)
#define kJB__TaskState_WaitsTillStart (4)
#define kSC__TM_BaseShrinkSpeed (0.0005f)
#define kSC__TM_Halfmap (6148914691236517205)
#define kSC__TM_MOUSEBUTTONDOWN (1025)
#define kSC__TM_MOUSEMOTION (1024)
extern Array* SC__Pac_Ancients;
extern MWrap* SC__Pac_JSMSpace;
extern ASMState SC__Pac_Sh;
extern LoopInfo SC__nil_Loops;
extern FP_NilTrackerFn SC__nil_NilTable[64];
extern byte SC__nil_OldPrint;
extern ArchonPurger SC__nil_T;
extern CompressionStats JB__MzSt_All;
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
#define kJB__Rec_NonFatal (JB_LUB[982])
extern double JB__Rec_Progress;
#define kJB__fix_TypeDict (3)
#define kJB__fix_TypeObj (1)
#define kJB__fix_TypeStem (2)
#define kJB__fix_TypeValue (0)
extern bool JB__Flow_AlwaysMove;
extern bool JB__Flow_BreakOnFail;
extern int JB__Flow_Disabled;
extern FlowControl* JB__Flow_Flow;
extern byte JB__Flow_FlowMode;
#define kJB__Flow_Log (1)
#define kJB__Flow_Off (0)
extern CompressionStats JB__Flow_Stats;
#define kJB__Flow_Validate (2)
#define kSC__Instruction_kTypeConst (2)
#define kSC__Instruction_kTypeFunc (1)
extern Dictionary* SC__Instruction_TypeDict;
extern Instruction* SC__Instruction_TypeList[256];
extern Array* JB__Macro_TmpPrms_;
extern uint64 JB__Mrap_MDummy_[2];
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
extern SCOperator* SC__Opp_Assigns;
extern SCOperator* SC__Opp_Bnot;
extern int SC__Opp_CustomOperatorScore;
extern Dictionary* SC__Opp_Dict;
extern SCOperator* SC__Opp_Minus;
extern int SC__xC2xB5Form_Count;
extern Dictionary* SC__xC2xB5Form_Forms;
#define kSC__xC2xB5Form_Jump (32)
#define kSC__xC2xB5Form_NoExpect (512)
#define kSC__xC2xB5Form_Num (64)
#define kSC__xC2xB5Form_PositionBits (1024)
#define kSC__xC2xB5Form_Signed (128)
extern bool JB__File_DebugExecute;
#define kJB__File_IgnoreErrors (true)
#define kJB__File_O_APPEND (8)
#define kJB__File_O_CREAT (512)
#define kJB__File_O_EXCL (2048)
#define kJB__File_O_RDONLY (0x000)
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
#define kSC__Base_NoErrors (1)
extern SpdProcess* JB__Proc_Parent;
extern byte JB__Err_AutoPrint;
extern Array* JB__Err_CurrSource_;
extern bool JB__Err_KeepStackTrace;
#define kSC__Beh_kBehaviourProto (2)
#define kSC__Beh_kBehaviourProtoRequired (6)
#define kSC__Beh_kBehaviourTable (1)
extern SCFunction* SC__Func_CurrFunc;
extern int SC__Func_DisabledPoints;
extern int SC__Func_FuncStats[12];
extern int SC__Func_OnceCount;
extern int SC__Func_SyxID;
extern Dictionary* SC__Func_TemporalStatements;
extern SCModule* SC__Mod_Curr;

//// HEADER JB.h



// App
JB_String* JB_App__AppName();

JB_String* JB_App__AppPath();

JB_String* JB_App__Conf(JB_String* Name);

void JB_App__ConfigureSet(JB_String* Value);

void JB_App__Crash(JB_String* Reason);

ErrorInt JB_App__CWDSet(JB_String* Value);

JB_String* JB_App__FileName();

int JB_App__Init_();

int JB_App__InitCode_();

bool JB_App__IsMainThread();

bool JB_App__No(JB_String* Name);

JB_String* JB_App__OrigPath();

JB_String* JB_App__GetPref(JB_String* S);

void JB_App__PrefSet(JB_String* S, JB_String* Value);

JB_String* JB_App__PrefPath();

Message* JB_App__PrefsInit(Date When);

void JB_PrintStackTrace();

void JB_App__SavePrefs();

ErrorInt2 JB_App__Say(JB_String* S, bool Print);

JB_String* JB_App__StackTrace(int Skip, FastString* Fs_in);

int64 JB_App__StringMemory();

JB_String* JB_App__ArgValue(JB_String* Name);

bool JB_App__Yes(JB_String* Name);



// AutoComplete
int SC_AutoComplete__Init_();

int SC_AutoComplete__InitCode_();

bool SC_AutoComplete__IsAFunc(JB_String* S);



// CodeSorter
bool SC_CodeSorter__LeafFunctionsSorter(SCFunction* A, SCFunction* B);

void SC_CodeSorter__LeafsFirst();



// Comp
SCDecl* SC_Comp__AddGlobalConst(JB_String* Name, SCClass* C, NilState Dcl);

void SC_Comp__AddGlobalConstFloat(JB_String* Name, SCClass* C, JB_String* Value);

void SC_Comp__AddGlobalConstNum(JB_String* Name, SCClass* C, int64 Value);

bool SC_Comp__AddMain(int Mark);

JB_String* SC_Comp__AddSCProj(JB_String* Path);

Dictionary* SC_Comp__Adj(Message* F);

void SC_Comp__AppBuildLibs(JB_File* Inner);

void SC_Comp__AppBuildOneLib(JB_File* Inner, Message* Lib);

void SC_Comp__AppendCompilerTime(JB_String* S, int Durr);

void SC_Comp__AppleBuildApp(JB_File* Project, JB_File* Product);

bool SC_Comp__Banned(JB_String* Name);

JB_File* SC_Comp__BuildFolder();

void SC_Comp__Bundle();

void SC_Comp__CheckIsGoodLibrary();

bool SC_Comp__ClassSorter(JB_Object* A, JB_Object* B);

void SC_Comp__ClearEnvs();

void SC_Comp__CodeSign(JB_File* Gui_exe);

void SC_Comp__CollectConstants();

bool SC_Comp__CollectIsaTests(Message* S);

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

Macro* SC_Comp__FindAdj(Message* Exp, Array* Prms);

SCDecl* SC_Comp__FindClassType(Message* N);

SCFunction* SC_Comp__FindFunction(JB_String* Name);

SCModule* SC_Comp__FindModuleMsg(Message* Where, SCNodeFindMode Mode);

SCNode* SC_Comp__FindModuleOrClass(Message* Mod, bool Retry);

JB_File* SC_Comp__FindProject(JB_String* Path, bool Error);

JB_File* SC_Comp__FindProjectSub(JB_String* Base, JB_String* Path);

JB_String* SC_Comp__FindProjNoSuffix(JB_String* Path);

JB_File* SC_Comp__GeneratedCppsFolder();

JB_String* SC_Comp__IdealName();

void SC_Comp__ImportAll();

void SC_Comp__ImportLibs();

void SC_Comp__ImportProj();

int SC_Comp__Init_();

bool SC_Comp__InitBasicFuncs();

int SC_Comp__InitBasicStuff();

int SC_Comp__InitCode_();

void SC_Comp__InitCompiler();

void SC_Comp__InitTypes();

JB_File* SC_Comp__InputFile(JB_File* Default, JB_String* S, Message* Where);

bool SC_Comp__IsTest();

JB_File* SC_Comp__Jeebox();

JB_File* SC_Comp__Library();

void SC_Comp__LoadInitsAndMore();

SCFunction* SC_Comp__LoadRefFunc(JB_String* Name);

void SC_Comp__LoadSuperClasses();

SCFunction* SC_Comp__LoadTypeTest(JB_String* S);

void SC_Comp__Main();

Message* SC_Comp__MakeMainFunc();

void SC_Comp__MiniTests();

bool SC_Comp__ModulesSorter(JB_Object* A, JB_Object* B);

void SC_Comp__NewConst(SCDecl* D);

void SC_Comp__PostInitCodeCall();

void SC_Comp__PrepareAST();

void SC_Comp__PrintCompileErrors();

void SC_Comp__PrintCompileTime(Date Durr);

void SC_Comp__PrintErrors(ErrorSeverity MinSev);

void SC_Comp__PrintResults();

void SC_Comp__PrintStats();

JB_File* SC_Comp__ProductFile();

JB_String* SC_Comp__ProductPath();

JB_String* SC_Comp__Projects();

bool SC_Comp__Reached(JB_String* S);

int SC_Comp__ReachedClassCount();

int SC_Comp__Reachedfuncs();

JB_String* SC_Comp__RenderErrors(JB_ErrorReceiver* Stderr, ErrorSeverity MinSev);

JB_File* SC_Comp__ScriptLoc(JB_String* F);

bool SC_Comp__ScriptRecompile(JB_File* F, JB_File* Script_build);

void SC_Comp__SetupEnv();

bool SC_Comp__SortModulesAndClasses();

JB_File* SC_Comp__Speedie();

JB_File* SC_Comp__SpeedieDir(JB_String* S);

JB_String* SC_Comp__SpeedieProj();

bool SC_Comp__Stage(JB_String* Name);

SCClass* SC_Comp__FindClassName(JB_String* Name);

SCClass* SC_Comp__SyntaxAccess(Message* Name);

void SC_Comp__SyntaxAppend(Message* M);

void SC_Comp__TestDate();

void SC_Comp__TestTask();

void SC_Comp__Timer(JB_String* Name);

void SC_Comp__TimerSub(JB_String* S, int Durr);

bool SC_Comp__TryVariousStartModes();

JB_File* SC_Comp__UsingScript(JB_File* F);

JB_String* SC_Comp__VariantSuffix();

void SC_Comp__VariousSelfTests();

SCNode* SC_Comp__WrongConf(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCFunction* SC_Comp__XFunc(JB_String* Name, Message* M);



// CustomOps


// ErrorColors
void JB_ErrorColors__DisableIfNoTerminal();

int JB_ErrorColors__Init_();

int JB_ErrorColors__InitCode_();



// FastStringOpts
void SC_FastStringOpts__FS(Message* Exp, Message* Getresult);

int SC_FastStringOpts__Init_();

int SC_FastStringOpts__InitCode_();

void SC_FastStringOpts__String(Message* Exp, Message* Str);



// FB
bool SC_FB__AppOptions_alive(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_arch(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_argstats(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_beep(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_breakonerr(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_check(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_clean(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_codesign(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_cpp(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_crash(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_directtest(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_dosign(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_env(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_errortest(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_final(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_flow(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_force(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_funccount(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_gcc(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_help(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_ignorecantsave(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_keepallerrors(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_log(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_maxvars(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_nil(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_nocolor(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_nocompile(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_noisy(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_optimise(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_output_path(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_pack(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_path(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_perry(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_print(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_products(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_quiet(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_self(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_silent(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_single(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_stages(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_target(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_targetdebug(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_usescriptloc(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_variant(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_warn(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppTransCompile(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppVersionNumber(JB_String* Name, JB_String* Value, FastString* Purpose);

void SC_FB__CheckSelfModifying();

int SC_FB__CheckSelfModifying2();

bool SC_FB__CompilerInfo();

bool SC_FB__Explain(FastString* Purpose, JB_String* Name);

void SC_FB__Help();

int SC_FB__Init_();

int SC_FB__InitCode_();

bool SC_FB__ParseArgs();

bool SC_FB__ParseArgsSub(Array* Args);

void SC_FB__ParseOption(JB_Object* Obj);

void SC_FB__StopStripping();

JB_String* SC_FB__TryUseProject(JB_String* Path, bool IsScript);



// InbuiltShellArgs
SCNode* SC_InbuiltShellArgs__Collect(Message* Node, SCNode* Name_space, Message* ErrPlace);



// AC
bool SC_AC__Active();

void SC_AC__ActualDefine(Message* Rz, Message* S, JB_String* Purpose);

Message* SC_AC__AllTmps();

Message* SC_AC__AutoComplete(Message* Ff, JB_String* Name, JB_String* Purpose);

bool SC_AC__AutoCompleteSorter(autoitem* A, autoitem* B);

Message* SC_AC__AutoJump(Message* Cmd);

void SC_AC__AutoSub(SCNode* Scope, JB_String* Name, Array* Found, int Types, Message* NeedTypeLimit);

void SC_AC__AutoSub2(SCObject* Value, JB_String* Key, JB_String* Src_name, Array* Found, bool Exact, int Types, SCDecl* TypeLimiter);

Message* SC_AC__Backup_Define(SCFile* Myfile, int F, Message* Thg, JB_String* Purpose);

Message* SC_AC__CallFrom(Message* Msg, JB_String* Purpose, JB_Object* Found);

Message* SC_AC__CallFromDefine(Message* Msg, SCFunction* Fn, JB_Object* Found);

void SC_AC__CallFromSub(Message* Arg, SCFunction* Fn);

bool SC_AC__CanUseName(SCNode* L);

Message* SC_AC__Check(Message* Cmd);

Message* SC_AC__CmdCleanUp(Message* Arg);

Message* SC_AC__CmdResponse(Message* Cmd, Message* Arg);

bool SC_AC__CmdWrap(Message* Arg);

Message* SC_AC__Define(Message* Msg, JB_String* Purpose, JB_Object* Found);

Message* SC_AC__Define_Behaviour(SCFunction* Fn, JB_String* Purpose);

Message* SC_AC__DefineOrCall(Message* Msg, JB_String* Purpose, JB_Object* Found);

Message* SC_AC__Diissplay(Message* Msg, Message* S, JB_String* Purpose);

Message* SC_AC__DoCmd(Message* Cmd, Message* Arg);

bool SC_AC__EnterAutoComplete();

Message* SC_AC__ErrorsToPerry();

Message* SC_AC__FindAdj(Message* Msg, bool DisplayOnly);

Message* SC_AC__FuncTmps();

SCFunction* SC_AC__GetFunc(Message* Cmd, SCFile* Myfile, int Ff, int N);

SCFunction* SC_AC__GetFunc2(Message* Cmd, SCFile* Myfile, int F, int N);

SCNode* SC_AC__GetScope(Message* Orig, int* Types);

void SC_AC__IdentifyBetter(Message* Node, JB_String* Name);

int SC_AC__Init_();

int SC_AC__InitCode_();

bool SC_AC__InitedOK();

Message* SC_AC__JumpImport(Message* Cmd);

Message* SC_AC__LocateDefinition(Message* Msg, SCObject* Already_defined, bool DisplayOnly);

Message* SC_AC__LocateDefinitionSub(Message* Msg, SCObject* Already_defined, SCDecl* Ty, bool DisplayOnly);

Message* SC_AC__MainAct(Message* Cmd, SCFile* My_file);

Message* SC_AC__MainActAutoComplete(Message* Thg, JB_String* Str, Message* Cmd);

void SC_AC__ParserRestore();

void SC_AC__PerryTalk(SpdProcess* Perry);

Message* SC_AC__ReportMemory(Message* Cmd);

Message* SC_AC__RespondDefine(Message* Msg, Message* S, JB_String* Purpose);

Message* SC_AC__RootTmpComplete(Message* Cmd);

Message* SC_AC__TmpAutoComplete(Message* F, JB_String* Name, JB_String* Type);

Message* SC_AC__UnusedFuncs(Message* Cmd);

Message* SC_AC__WriteError(JB_String* Name);



// API
int JB_API__Init_();

int JB_API__InitCode_();

void JB_API__NilCallBack(JB_String* ErrorMessage);

bool JB_API__NilHandler();



// Constants
void JB_Constants__AddEscape(byte I, FastString* Fs);

int JB_Constants__Init_();

int JB_Constants__InitCode_();

void JB_Constants__InitConstants();

JB_String* JB_Constants__TestJB();

bool JB_Constants__TestCasting();



// LinkMap
void SC_LinkMap__Collect(SCFunction* Self);

void SC_LinkMap__CollectAll();

void SC_LinkMap__CollectFromSource(SCFunction* Self, Message* Src, bool InBranch);

int SC_LinkMap__Init_();

int SC_LinkMap__InitCode_();

void SC_LinkMap__Store(Array** Darr, SCObject* Obj);



// Linkage
JB_String* SC_Linkage__CombineFlags(JB_String* Name);

void SC_Linkage__CompilerCollect(Message* S);

JB_String* SC_Linkage__GetFlag(JB_String* Name, FastString* Fs);

int SC_Linkage__Init_();

int SC_Linkage__InitCode_();

bool SC_Linkage__Interpreter();

SCNode* SC_Linkage__LinkCollect(Message* Node, SCNode* Name_space, Message* ErrPlace);

bool SC_Linkage__SyntaxAccess(JB_String* Name);

bool SC_Linkage__VM();



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



// PackMaker
void SC_PackMaker__AddAll();

void SC_PackMaker__AddLibGlob(SCDecl* D);

JB_String* SC_PackMaker__BuildInterpreter();

void SC_PackMaker__DoLibGlobs(FastString* Lib);

void SC_PackMaker__DumpStrings(FastString* J);

void SC_PackMaker__FuncLink(FastString* J);

void SC_PackMaker__GlobLink(FastString* J);

int SC_PackMaker__Init_();

int SC_PackMaker__InitCode_();

void SC_PackMaker__ListPackFuncs(FastString* J, Array* Upon);

void SC_PackMaker__MakePack();

void SC_PackMaker__MiniTest(SCFunction* Fn1);

void SC_PackMaker__OrderGlobals(FastString* J);

int SC_PackMaker__OrderGlobalsSub();

void SC_PackMaker__PackClass(FastString* J);

void SC_PackMaker__SortAll();

void SC_PackMaker__SortSub(Array* List);

void SC_PackMaker__WriteLibFuncs(FastString* J);



// Platform
bool JB_Platform__CPU_ARM();

bool JB_Platform__CPU_Intel();

JB_String* JB_Platform__CPU_Name();

bool JB_Platform__CPU_PPC();

bool JB_Platform__CPU_Spd();

int JB_Platform__Init_();

int JB_Platform__InitCode_();

void JB_Platform__Log(JB_String* S);

JB_File* JB_Platform__OpenLog();

int JB_Platform__PointerBytes();

bool JB_Platform__Release();



// PostIncrementNil
void SC_PostIncrementNil__Check(Message* Ch);

void SC_PostIncrementNil__Clear();

int SC_PostIncrementNil__Init_();

int SC_PostIncrementNil__InitCode_();

void SC_PostIncrementNil__SyntaxAppend(Message* Ch);



// SCGame3D
int SC_SCGame3D__Init_();

int SC_SCGame3D__InitCode_();

SCNode* SC_SCGame3D__Love(Message* Node, SCNode* Name_space, Message* ErrPlace);

bool SC_SCGame3D__NeedShader(JB_String* Name);

SCNode* SC_SCGame3D__NeuModel(Message* Node, SCNode* Name_space, Message* ErrPlace);



// SC
int SC__Init_();

int SC__InitCode_();



// Refs
void SC_Refs__DeclInit(Message* Dcl, SCFunction* Fn, bool IsJustAnArg);

Message* SC_Refs__DecrMulti(SCDecl* D, Message* M);

void SC_Refs__Destructable(Message* Blocker, Message* Arg, Message* Name);

bool SC_Refs__ExitHitsOrGoesPast(Message* Curr, Message* Arg);

bool SC_Refs__ExprNeedsTemping(Message* Child, Message* Name);

Message* SC_Refs__LastUsedRefPlace(Message* Name, Message* Arg);

void SC_Refs__RC_CheckFuncAllocOK(SCFunction* Self, Message* Dot);

void SC_Refs__RC_DeclArg(SCDecl* AR, SCFunction* Fn);

void SC_Refs__RC_HandleDisappearing(SCFunction* Fn, Message* Msg, int Basis);

void SC_Refs__RC_IgnoreReturn(Message* Msg, bool DoRefs);

bool SC_Refs__RC_NeedsOwnBlock(Message* Msg, Message* Pp);

void SC_Refs__RC_Rel(Message* Rel);

void SC_Refs__RC_RelConstructor(Message* Rel);

int SC_Refs__RefBasis(Message* Msg, bool SetOnly);

int SC_Refs__RefBasisStruct(Message* Msg, bool SetOnly);

Message* SC_Refs__RefClearMsg(Message* Msg);

void SC_Refs__RefDecr(Message* Msg, Message* Place, int Basis);

Message* SC_Refs__RefDecrMsg(Message* Msg);

Message* SC_Refs__RefDestructorMsg(Message* Msg, SCFunction* Fn);

void SC_Refs__RefIncr(Message* Msg, Message* Place, bool IsJustAnArg);

Message* SC_Refs__RefMsg(Message* Msg, JB_String* Name, SCFunction* Func);

Message* SC_Refs__RefMsg0(JB_String* Name, SCFunction* Func);

void SC_Refs__RefSafeDecr(Message* Msg, Message* Place);

bool SC_Refs__RelNeedsRef(Message* Msg, Message* First);

void SC_Refs__ReturnHandle(Message* Blocker, Message* Arg, Message* Name, int Basis);

void SC_Refs__ReturnTempMoveOut(Message* Child, Message* Blocker);

void SC_Refs__ReturnTempMoveOutSub(Message* Child, Message* Blocker, Message* Temp);

Message* SC_Refs__SafeDecrMsg(Message* Msg);



// SCSelector
SCNode* SC_SCSelector__Build(Message* Node, SCNode* Name_space, Message* ErrPlace);

Message* SC_SCSelector__BuildClassCode(JB_String* Name, JB_String* Type);

void SC_SCSelector__DeclareOneSel(JB_String* Sel_name, JB_String* Type, Message* Place);

Message* SC_SCSelector__FindItems(Message* Arg);

bool SC_SCSelector__HasClassStuff(Message* Self);

void SC_SCSelector__LoadOneSel(JB_String* Sel_name, JB_String* Module_name, Message* LoaderPlace, Message* Prms);

SCNode* SC_SCSelector__Neu(Message* Node, SCNode* Name_space, Message* ErrPlace);



// SCStrings
int SC_SCStrings__Init_();

int SC_SCStrings__InitCode_();



// SCTasks
void SC_SCTasks__CollectAll();

int SC_SCTasks__Init_();

int SC_SCTasks__InitCode_();

SCNode* SC_SCTasks__NewTask(Message* Node, SCNode* Name_space, Message* ErrPlace);

void SC_SCTasks__NewTaskActual(Message* Node, SCNode* Name_space);



// SCThe
SCNode* SC_SCThe__NewInsertion(Message* Node, SCNode* Name_space, Message* ErrPlace);



// SC_API
void SC_SC_API__DelayedClassAPI(Message* Node, JB_String* Proj);

void SC_SC_API__NewAPI(Message* Api, JB_String* Part, SCNode* Parent, JB_String* Proj);

SCNode* SC_SC_API__NewExportAPI(Message* Node, SCNode* Name_space, Message* ErrPlace);

void SC_SC_API__NewExportAPISub(Message* Node, SCObject* Parent);



// Errors
JB_Error* SC_Errors__AlreadyIgnored(Message* F);

bool SC_Errors__CanKeep(JB_Error* Err);

int SC_Errors__Init_();

int SC_Errors__InitCode_();



// Sav
void SC_Sav__BugWorkAround();

void SC_Sav__TestSaver();



// SC_Targets
int SC_SC_Targets__Init_();

int SC_SC_Targets__InitCode_();

bool SC_SC_Targets__SyntaxAccess(JB_String* Name);

void SC_SC_Targets__SyntaxAccessSet(JB_String* Name, bool Value);



// SpdAssembler
Array* SC_SpdAssembler__CollectFuncs(JB_String* Exp);

bool SC_SpdAssembler__FlowControl();

void SC_SpdAssembler__GenerateASM(SCFunction* Fn);

int SC_SpdAssembler__Init_();

void SC_SpdAssembler__InitAss();

int SC_SpdAssembler__InitCode_();

bool SC_SpdAssembler__Optimise();

ASMFunc* SC_SpdAssembler__AccessStr(Message* M);

bool SC_SpdAssembler__Vacuum(SCFunction* Fn);



// SC
ErrorInt JB_Main();



// Crkt
void SC_Crkt__CollectString(Message* M, bool StdLib);

void SC_Crkt__Correct();

void SC_Crkt__CorrectConsts();

void SC_Crkt__CorrectFile(JB_File* Where);

void SC_Crkt__CorrectStrings();

int SC_Crkt__Count();

void SC_Crkt__IDSort(bool IDOrder);

int SC_Crkt__Init_();

int SC_Crkt__InitCode_();

void SC_Crkt__MergeTable(Message* Disk, Dictionary* D3);

MessageID* SC_Crkt__NewID(JB_String* Name);

bool SC_Crkt__UseID(MessageID* S, Message* Old);

void SC_Crkt__WriteTable(FastString* Fs);



// Terminal
void JB_Terminal__Display();

void JB_Terminal__DrawRect(ivec4 Rect, JB_String* Inside, TerminalColor Colors);

JB_String* JB_Terminal__Flat();

void JB_Terminal__FrameText(JB_String* S, ivec4 Frame, TerminalColor FrameCol, TerminalColor TextCol);

void JB_Terminal__init();

int JB_Terminal__Init_();

int JB_Terminal__InitCode_();

ivec2 JB_Terminal__Size();

void JB_Terminal__SyntaxAppend(JB_String* Text, ivec2 V, TerminalColor Colors);

void JB_Terminal__SyntaxExpect(JB_String* Msg);



// TextAssembler
void SC_TextAssembler__Assemble(Message* Msg);

int SC_TextAssembler__Init_();

int SC_TextAssembler__InitCode_();

void SC_TextAssembler__TextData(Message* Msg);

bool SC_TextAssembler__TextFunc(Message* Msg);



// Ext
bool SC_Ext__AllowedThisFile(JB_String* Name);

bool SC_Ext__BackupCompiler();

JB_String* SC_Ext__BackupPath();

bool SC_Ext__CanCompile(JB_String* Name);

bool SC_Ext__Clean();

void SC_Ext__ClearThis();

bool SC_Ext__CollectAndCompile(JB_File* Input, JB_String* Output);

Array* SC_Ext__CollectCppsInto(JB_File* Fol, JB_File* Objects);

void SC_Ext__CollectPico(JB_String* Lib);

JB_File* SC_Ext__CppLib();

Array* SC_Ext__CreateCompileString(Array* FileList, JB_String* Product, JB_String* Type);

bool SC_Ext__ExecuteGCC(Array* Commands);

void SC_Ext__ExportAndInstall(bool CanInstall);

Array* SC_Ext__FilterCppsIfAlreadyDone(Array* List, JB_File* Objects);

bool SC_Ext__HasType(Array* CppList, JB_String* Type);

int SC_Ext__Init_();

int SC_Ext__InitCode_();

void SC_Ext__InstallCompiler();

void SC_Ext__InstallOne(JB_File* Test);

bool SC_Ext__IsCompilerAndNeedsInstall();

JB_String* SC_Ext__LibSuff();

JB_String* SC_Ext__LibTmpPath();

JB_File* SC_Ext__LinkOK(JB_File* P);

void SC_Ext__MacBothArch(Array* R);

JB_String* SC_Ext__MakeDailyProductPath(JB_File* B);

void SC_Ext__MakeLib();

int SC_Ext__NeedNewObjForSrc(JB_String* Cpp, JB_File* Objects);

int SC_Ext__NoGoodObject(JB_String* Cpp, JB_File* H, JB_File* O);

void SC_Ext__PrintProduct(JB_String* S);

JB_String* SC_Ext__ProductBaseName();

JB_String* SC_Ext__ProductNameFull();

JB_String* SC_Ext__ProductSuffix();

JB_String* SC_Ext__ProjTmpPath();

void SC_Ext__ReplaceOld(JB_File* Input, JB_File* Backs);

void SC_Ext__RunCppCompile();

void SC_Ext__SayTest(JB_String* N);

bool SC_Ext__ShouldTransComp();

bool SC_Ext__TestNewCompiler();

void SC_Ext__TestNewestLib(JB_File* Cpplib);

JB_String* SC_Ext__TmpBase(JB_String* V);

JB_String* SC_Ext__TmpErr(JB_String* V);

JB_String* SC_Ext__TmpOut(JB_String* V);

bool SC_Ext__TransCompile(Array* Files, JB_String* Dest, JB_String* Type);

bool SC_Ext__TransCompileWrap(Array* Cpps);

bool SC_Ext__UseAndCompile(Array* Input, JB_String* Output);



// VM_Builder
void SC_VM_Builder__AddASM2(JB_String* Name, int Id);

xC2xB5Form* SC_VM_Builder__AddForm(Message* Form);

ASM SC_VM_Builder__BadEncoder(FatASM* Self);

bool SC_VM_Builder__BuildFiles();

void SC_VM_Builder__BuildInstructions(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_VM_Builder__Clean(Message* Msg);

JB_File* SC_VM_Builder__CppLibFile(JB_String* Ch);

Message* SC_VM_Builder__DataTypeCreate(Message* Form, int Fnum);

void SC_VM_Builder__DataTypeModule();

Message* SC_VM_Builder__DefineGet(JB_String* Fname, int Up, int Down, bool Last);

void SC_VM_Builder__DefineGetSub(JB_String* Fname, int Up, int Down, byte C, byte C2);

Array* SC_VM_Builder__FillEncoders(Message* List, bool ActuallyMakeTheVM);

void SC_VM_Builder__FillTypePrm(JB_String* Fname, int Pname);

int SC_VM_Builder__GenAcc(Message* Line, int Bit_pos, int Pname, int Max);

void SC_VM_Builder__GenerateForms(Message* Forms, bool Rest);

void SC_VM_Builder__GenerateOne(Message* Form_msg, int F);

int SC_VM_Builder__Init_();

int SC_VM_Builder__InitCode_();

bool SC_VM_Builder__JustMakeMyBread();

void SC_VM_Builder__MakeJump(Message* Msg, FastString* Jump);

void SC_VM_Builder__MakeTheVM();

void SC_VM_Builder__MakeVM(Message* Tmp, FastString* Vm);

int SC_VM_Builder__NextID(Message* Counts);

int SC_VM_Builder__NextIDWithCounts(Message* Counts);

void SC_VM_Builder__SafeWrite(JB_String* Name, FastString* Data);

Message* SC_VM_Builder__VMBox();

void SC_VM_Builder__VMCpp(FastString* Vm, FastString* Jump);

void SC_VM_Builder__VMDecl(Message* Tmp, Array* ActuallyMakeTheVM);

void SC_VM_Builder__VMLine(Message* Line, FastString* Vm);

void SC_VM_Builder__VMTmp(Message* Tmp, Array* ActuallyMakeTheVM);



// __classes__


// __junktest_5__
void SC___junktest_5____Abc(bool G);

int SC___junktest_5____Init_();

int SC___junktest_5____InitCode_();



// __modules__


// image
JB_String* SC_image__ConvertPNGToVOI(JB_String* P);



// main
void SC___junktest_11__();

void SC___junktest_1__();

void SC___junktest_2__();

bool SC___junktest_3__(IntRange Data);

void SC_AddToStaticSection(Message* Arg, Message* ToAdd);

int SC_ArrayInOrderCheck(int InOrder, Message* Msg);

bool SC_CanOpCompare(Message* Exp, SCDecl* Lc, SCDecl* Rc, SCOperator* Comp);

void SC_ClassLinkageTable_cpp_class(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_ClassLinkageTable_cpp_part(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_ClassLinkageTable_cpp_wrapper(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_ClassLinkageTable_datatype(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_ClassLinkageTable_ignore(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_ClassLinkageTable_noearlyfree(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_ClassLinkageTable_numeric(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_ClassLinkageTable_tighten(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_ClassLinkageTable_visible(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_ClassLinkageTable_wrapper(SCFunction* Fn, Message* Node, SCNode* Name_space);

SCClass* SC_ClassOfObjForC(Message* Curr);

SCNode* SC_ClsCollectTable_pragma(Message* Node, SCNode* Name_space, Message* ErrPlace);

void SC_CollectDeclsFuncBody(Message* Arg, SCNode* Scarg);

void SC_CollectDeclsFuncBodyJustWhatWeNewlyMade(Message* Arg, SCNode* Scarg);

void SC_CollectDeclsFuncBodyUnsureHowToRemove(Message* Arg, SCNode* Scarg);

void SC_CollectDeclsGlobals(Message* Arg, SCNode* Scarg);

bool JB_CompareError(Message* Expected, Message* Found);

void SC_CppRefTable_disowns(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_CppRefTable_disturbs(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Create_JeeboxTest(Message* Msg);

SCDecl* SC_CustomFuncOp(Message* Exp, SCOperator* Comp, SCNode* Name_space, Message* RN);

SCDecl* SC_DeclOfObjForC(Message* Curr);

Message* SC_DeclsDefault(Message* Def);

bool SC_DeclSizeSorter(SCDecl* A, SCDecl* B);

Message* SC_DefaultStitch(Message* Default, Message* Dcl);

SCNode* SC_DontRemove(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCDecl* SC_DoOpCompare(Message* Exp, SCDecl* Lc, SCDecl* Rc, SCOperator* Comp, SCNode* Name_space);

JB_String* JB_EntityTest();

SCDecl* SC_ExtractDecl(Message* C, SCNode* Name_space, DeclMode Purpose);

void fdb(Array* R);

Message* SC_FindBytePos(Message* Node);

Message* SC_FindBytePosSub(Message* Node);

AsmReg SC_fn_asm_table_63(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_fn_asm_table_ARG(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_fn_asm_table_DECL(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_fn_asm_table_LIST(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

void SC_FuncLinkageTable_cpp_part(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_FuncLinkageTable_cpp_wrapper(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_FuncLinkageTable_ignore(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_FuncLinkageTable_inline(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_FuncLinkageTable_visible(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_FuncPreReader_description(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_disabled(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_nil(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_numeric(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_opt(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_pragma(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_real(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_todo(SCFunction* Self, Message* Msg);

int JB_Init_();

int JB_InitCode_();

SCDecl* SC_IsPointerMath(SCDecl* L, SCDecl* R, SCOperator* Opp, Message* Exp);

void SC_ListFunctionsSub(JB_Object* O, Array* Rz);

SCDecl* SC_LowlevelArrayTransform(Message* Exp, SCClass* Cls);

Message* SC_MakeDecl(JB_String* Type, JB_String* Name, Message* Value, SCDeclInfo Purpose);

Message* SC_MakeDeclOrRel(Message* Into, Message* Namemsg, Message* Value);

void SC_MoveFutureStaticsIn(Message* Msg);

Message* SC_NewDeclWithStrStr(JB_String* Type, JB_String* Name);

Message* SC_NewDeclWithStrMsg(JB_String* Type, Message* RelOrName);

Message* SC_NewDeclNum(SCDecl* D, int64 N, JB_String* VarName);

Message* SC_NewEqRelWithMsgMsg(Message* L, Message* R);

Message* SC_NewEqRelWithStrStr(JB_String* L, JB_String* R);

Message* SC_NewFnc(JB_String* Name);

Message* SC_NewRejoin();

Message* SC_NewRel(Message* L, Message* R, JB_String* Op);

bool SC_NodeSorter(SCFunction* A, SCFunction* B);

SCDecl* SC_Or_And_Expansion(SCDecl* LC, SCDecl* RC, Message* Exp, SCNode* Name_space);

void JB_Obj_Print(JB_Object* O);

void SC_printfunc(JB_String* S);

void JB_PrintLine(JB_String* Data);

void JB_Obj_PrintLine(JB_Object* O);

void SC_RelSetOrExpansion(Message* Exp);

SCNode* SC_RootCollectTable_crash(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_RootCollectTable_extends(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_RootCollectTable_static(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCDecl* SC_SameTypeSub(Message* First, Message* Second, SCNode* Name_space);

bool SC_SCFuncSorter(SCFunction* A, SCFunction* B);

Message* SC_SettingAProperty(Message* Rel);

bool SC_SettingMemory(Message* Rel);

bool SC_SettingSelfProperty(Message* Rel);

Array* SC_SortInitOrder(Array* Mods);

bool SC_SortInitOrderSub(Array* Mods, Array* Out);

ErrorInt Speedie_Main(PicoComms* Comms, int Mode, _cstring* Args);

Message* SC_SpellOutMsg(Message* Type, Message* Exp, Message* Namemsg);

void SC_TemporalStatements_alert(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_TemporalStatements_break(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_TemporalStatements_crash(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_TemporalStatements_do(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_TemporalStatements_ignore(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Tran_ArgArray(Message* Exp, SCNode* Name_space, SCDecl* Decl);

void SC_Tran_Flow(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Tran_Msg(SCFunction* Fn, Message* Exp, SCNode* Name_space);

void SC_Tran_MsgList(SCFunction* Fn, Message* Exp, SCNode* Name_space);

SCObject* SC_TranNegate(Message* F, SCNode* Name_space);

SCObject* SC_TranRender(Message* Exp, SCNode* Name_space);

SCObject* SC_TypeOfAccess(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfAdj(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfARel(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfArgArr(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfArr(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfBlock(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfBra(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfBRel(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfChar(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfDot(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfDotDotDot(Message* Exp, SCNode* Name_space, Message* Side);

SCDecl* SC_TypeOfExpr(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfExprModulesOK(Message* Exp, SCNode* Name_space, Message* Side);

SCDecl* SC_TypeOfExprNeeded(Message* Exp, SCNode* Name_space);

SCObject* SC_TypeOfExprSub(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfFunc(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfFuncPointer(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfFuncSub(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfLast(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfList(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfMsg(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfNothing(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfNum(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfNumSub(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfQues(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfReal(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfRel(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfSDot(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfSString(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfSthg(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfStr(Message* Exp, SCNode* Name_space, Message* Side);

SCDecl* SC_TypeOfSwizzle(Message* Exp, SCDecl* Type, SCNode* Name_space, Message* Side, int Swiz);

SCDecl* SC_TypeOfSyntaxCall(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfSyx(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfTernary(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfThg(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfType(Message* Exp, SCNode* Name_space, Message* Side);

SCObject* SC_TypeOfUnit(Message* Exp, SCNode* Name_space, Message* Side);

SCDecl* SC_TypeOfVecAccess(Message* Index, SCDecl* Ty0, int W);

JB_String* SC_UniqueTmpVar(SCNode* Base, JB_String* Name);

int SC_UseCustomOperators(SCDecl* LC, SCDecl* RC, SCOperator* Comp, Message* ErrPlace);

SCClass* SC_VecType(bool Isfloat, int Count);

void* SC_voidtest(void* Abc);

void* SC_voidtest2(void* Abc);



// Tk
Message* JB_Tk__AddToOutput(Message* Output, Message* Curr, Message* Prev, int Pos);

void JB_Tk__AddXMLText(Message* XML, JB_String* S, int Start, int I);

Message* JB_Tk__BarThings(int Start, Syntax Syx);

Message* JB_Tk__BeforeRelSub(int Start, bool Mode);

bool JB_Tk__CanStatement();

Message* JB_Tk__ChainTemporalRels(Message* FirstThing, Message* Opp);

JB_String* JB_Tk__CharName(int Start, byte Find);

Message* JB_Tk__CloseXML(Message* XML, int I, JB_String* S);

Message* JB_Tk__DecorateThing(Message* R, int Ops);

Message* JB_Tk__DotSub(Syntax Fn, int Start, Message* Parent);

int JB_Tk__EmbeddedCode(JB_String* Close, Message* Dest, int TmpoFlags);

Message* JB_Tk__ErrorAdd(JB_String* S, Ind Start);

Message* JB_Tk__ErrorAlwaysAdd(JB_String* S, Ind Start);

void JB_Tk__ErrorEvent(int Start, int ExpectedBits, int RealBits);

void JB_Tk__ErrorLetter(int Start);

bool JB_Tk__ExpectEndChar(int Start, JB_String* S, bool Expect);

Message* JB_Tk__fAccess(int Start, Message* Parent);

Message* JB_Tk__fAdjectiveOp(int Start, Message* Parent);

Message* JB_Tk__fAdjectiveThing(int Start, Message* Parent);

Message* JB_Tk__fAfterRel(int Start, Message* Parent);

Message* JB_Tk__fArgColon(int Start, Message* Parent);

Message* JB_Tk__fArgName(int Start, Message* Parent);

Message* JB_Tk__fArgOpen(int Start, Message* Parent);

Message* JB_Tk__fArray(int Start, Message* Parent);

Message* JB_Tk__fAsk(int Start, Message* Parent);

Message* JB_Tk__fAskSub(int Start, Message* Parent, Syntax F);

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

Message* JB_Tk__fCharSub(int Pos, int Start, byte Find);

Message* JB_Tk__fComment(int Start, Message* Parent);

Message* JB_Tk__fCommentLine(int Start, Message* Parent);

Message* JB_Tk__fDecl(int Start, Message* Parent);

Message* JB_Tk__fDot(int Start, Message* Parent);

Message* JB_Tk__fDotAccess(int Start, Message* Parent);

Message* JB_Tk__fEndOfLine(int Start, Message* Parent);

Message* JB_Tk__fError(int Start, Message* Parent);

Message* JB_Tk__fError2(int Start, Message* Parent);

Message* JB_Tk__fFuncCall(int Start, Message* Parent);

Message* JB_Tk__FillXML(Message* XML, Ind I);

int JB_Tk__FindError(int Num);

Message* JB_Tk__fInnerNiceAdj(int Start, Message* Parent);

Message* JB_Tk__FixTRels(Message* Self, Message* Last);

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

Message* JB_Tk__fTmp(int Start, int OpFlags, int ThingFlags, Message* Parent);

Message* JB_Tk__fTmpPlus(int Start, Message* Parent);

Message* JB_Tk__fTmpSub(Message* Result, int OpFlags, int ThingFlags);

Message* JB_Tk__fTypeCast(int Start, Message* Parent);

Message* JB_Tk__fURL(int Start, Message* Parent);

Message* JB_Tk__fXML(int Start, Message* Parent);

Message* JB_Tk__fXML_Comment(int Start, Message* Parent);

Message* JB_Tk__fXML_DocType(int Start, Message* Parent);

Message* JB_Tk__fXML_PI(int Start, Message* Parent);

Message* JB_Tk__fYoda(int Start, Message* Parent);

Message* JB_Tk__GetFuncAfter(Message* Result);

int JB_Tk__GotoEndOfLine(int From);

Message* JB_Tk__IndentBug(Message* Curr);

void JB_Tk__Init();

int JB_Tk__Init_();

int JB_Tk__InitCode_();

Message* JB_Tk__LoweredIndent(Message* Output, Message* Curr);

Message* JB_Tk__MakeInvisArg(Message* Tmp, int Indent);

Message* JB_Tk__MakeRel(Message* First, int Bits);

int JB_Tk__MessageErrorSub(FastString* Fs, int Num, int ButFound);

bool JB_Tk__NeedName(Message* Thg);

Message* JB_Tk__NewParentName(Message* Parent, Syntax Func, int Start, JB_String* Name);

Message* JB_Tk__NewParent(Message* Parent, Syntax Func, int Start, int End);

Message* JB_Tk__NewEmpty(Message* P, Syntax F, int Start, int After);

Message* JB_Tk__NewSkip(Message* P, Syntax F, int Start, int NameStart, int NameEnd);

Message* JB_Tk__NewWord(Message* P, Syntax F, int Start, int SearchFrom);

ParserLineAndIndent JB_Tk__NextLineAndIndent(Message* Parent);

bool JB_Tk__NoFuncAfter(byte B);

Message* JB_Tk__NumberSub(int Start, int RealStart);

int JB_Tk__NumEnd(JB_String* NumStr, int Start);

bool JB_Tk__OK();

Message* JB_Tk__OppChain(Message* Opp);

void JB_Tk__Params(Message* Parent, int N);

Message* JB_Tk__ParseItem(Message* Ch, int TemporalFlags, int Ops);

int JB_Tk__ParseLoop(Message* Output, int TmpoFlags);

bool JB_Tk__ParseLoopFlags(Message* Output, JB_String* Ender, int TmpoFlags);

Message* JB_Tk__ParseLoopItem(Message* Output, int TmpoFlags, Message* Prev, int Indent);

Message* JB_Tk__PostInnerAdj(Message* Rel, Message* Opp);

Message* JB_Tk__ProcessThing(int Ops, bool Expect);

Message* JB_Tk__ProcessThingNoBar(int Ops, bool Expect);

Message* JB_Tk__ProcessThingOrTmp(int Opps);

Message* JB_Tk__ProcessThingParent(Message* Parent, int Ops, int ThingFlags);

Message* JB_Tk__ProcessThingSub(Message* Parent, int Ops, int KindOfThing, bool Expect);

Message* JB_Tk__ReRoute(Message* Output, Message* Cnj, Message* F);

void JB_Tk__StopParse();

Message* JB_Tk__ThingXMLAtt(int Start, Message* Parent);

void JB_Tk__TokensFn(Array* Arr, int Bits, FP_ParseHandler Func);

void JB_Tk__TokensHan(Array* Arr, TokHan* H);

void JB_Tk__TokenzFn(JB_String* S, int Bits, FP_ParseHandler Func);

Message* JB_Tk__UnexpectedSyntax(Message* Bad);

Message* JB_Tk__UnTmpPlace(Message* R);

bool JB_Tk__WillEnd();

int JB_Tk__WordAfter(int Start);

int JB_Tk__WordAfterSub(int Start, CharSet* Cs);

int JB_Tk__XMLAttribs(Message* XML, int Start);

Message* JB_Tk__XMLWhatever(int S, int Skip, JB_String* Ender, Syntax Fn);

Ind JB_Tk__XMLWordEnd(int From);



// zalgo
int JB_zalgo__Init_();

int JB_zalgo__InitCode_();



// _void


// atomic_byte


// atomic_int


// atomic_uint


// bool
JB_String* JB_bool_Render0(bool Self);



// byte
bool JB_byte_CanPrintAsNormalChar(byte Self);

bool JB_byte_In(byte Self, uint A, uint B);

bool JB_byte_IsHex(byte Self);

bool JB_byte_IsInt(byte Self);

bool JB_byte_IsLetter(byte Self);

bool JB_byte_IsLower(byte Self);

bool JB_byte_IsTextLine(byte Self);

bool JB_byte_IsUpper(byte Self);

bool JB_byte_IsWhite(byte Self);

byte JB_byte_LowerCase(byte Self);

JB_String* JB_byte_Render(byte Self, FastString* Fs_in);

byte JB_byte_UpperCase(byte Self);



// char


// cstring
JB_String* JB_cstring_Str(_cstring Self);

FakeJBString JB_cstring_temp(_cstring Self);



// f64
JB_String* JB_dbl_RenderFloat(double Self, FastString* Fs_in);



// float
float JB_f_RoundTo(float Self, int To);

float JB_f_Fract(float Self);

JB_String* JB_f_PC(float Self, FastString* Fs_in);

float JB_f_Pow(float Self, int N);

bool JB_f_SyntaxAccess(float Self);



// hfloat


// int
int SC_int___junktest_8__(int Self, int Inaaaadex, bool Create);

bool SC_int_IsNormalMatch(int Self);

bool SC_int_IsSimpleOrPointerCast(int Self);

int JB_int_LowestBit(int Self);

Message* JB_int_Msg(int Self);

int JB_int_OperatorAlign(int Self, int To);

bool JB_int_OperatorIsa(int Self, uint N);

int JB_int_OperatorMax(int Self, int Other);

int JB_int_OperatorMin(int Self, int Other);

int JB_int_OperatorPow(int Self, int A);

IntRange JB_int_OperatorTo(int Self, int Other);

AsmReg SC_int_ToReg(int Self);

JB_String* JB_int_RenderFS(int Self, FastString* Fs_in);

JB_String* JB_int_RenderSize(int Self, FastString* Fs_in);

bool JB_int_SyntaxAccess(int Self, int Bit);

int JB_int_SyntaxAccessSet(int Self, int Bit, bool Value);

int JB_int_TabsWidth(int Self);

int JB_int__Max();

int JB_int__Min();



// int16


// int64
int64 JB_int64_Abs(int64 Self);

bool SC_int64_CanStoreAsIntImmediate(int64 Self);

JB_String* JB_int64_Hex(int64 Self, FastString* Fs_in);

Message* JB_int64_Msg(int64 Self);

int64 JB_int64_OperatorMax(int64 Self, int64 D);

int64 JB_int64_OperatorMin(int64 Self, int64 D);

JB_String* JB_int64_Render(int64 Self, FastString* Fs_in);

void JB_int64_RenderSizePart(int64 Self, FastString* Fs, int Size, JB_String* Suff);

JB_String* JB_int64_StrSize(int64 Self, FastString* Fs_in);



// ivec2
bool JB_ivec2_OperatorContains(ivec2 Self, int X);

bool JB_ivec2_OperatorInrange(ivec2 Self, ivec2 P);

bool JB_ivec2_Equals2(ivec2 Self, ivec2 V, bool Aware);



// ivec3


// ivec4
ivec4 SC_ivec4___junktest_4__Set(ivec4 Self, int Value);

ivec4 JB_ivec4_Shrink(ivec4 Self, int I);

int JB_ivec4_Width(ivec4 Self);



// uint


// uint16


// uint64
bool SC_uint64_CanStoreAsFloatImmediate(uint64 Self);

uint64 JB_uint64_OperatorRol(uint64 Self, uint Bits);

uint64 JB_uint64_OperatorRor(uint64 Self, uint Bits);



// vec2


// vec3


// vec4


// ASM
ASM SC_ASM_BClear_Shift1Set(ASM Self, int Value);

ASM SC_ASM_BClear_Shift2Set(ASM Self, int Value);

ASM SC_ASM_BClear_SignSet(ASM Self, int Value);

ASM SC_ASM_BCmp_InvSet(ASM Self, int Value);

ASM SC_ASM_BCmp_ShiftSet(ASM Self, int Value);

ASM SC_ASM_BFLD_downSet(ASM Self, int Value);

ASM SC_ASM_BFLD_LSet(ASM Self, int Value);

ASM SC_ASM_BFLD_upSet(ASM Self, int Value);

ASM SC_ASM_Bra_c1Set(ASM Self, int Value);

ASM SC_ASM_Bra_jmpSet(ASM Self, int Value);

ASM SC_ASM_Cmp_CmpSet(ASM Self, int Value);

ASM SC_ASM_Cmp_LSet(ASM Self, int Value);

ASM SC_ASM_CmpD_LSet(ASM Self, int Value);

ASM SC_ASM_CmpEq_JmpSet(ASM Self, int Value);

ASM SC_ASM_CNTC_cnstSet(ASM Self, int Value);

ASM SC_ASM_CNTC_offsetSet(ASM Self, int Value);

ASM SC_ASM_CNTC_sizeSet(ASM Self, int Value);

ASM SC_ASM_Const_InvSet(ASM Self, int Value);

ASM SC_ASM_Const_RotSet(ASM Self, int Value);

ASM SC_ASM_Const_ValueSet(ASM Self, int Value);

ASM SC_ASM_ConstStretchy_CondSet(ASM Self, int Value);

ASM SC_ASM_ConstStretchy_InvSet(ASM Self, int Value);

ASM SC_ASM_ConstStretchy_Prm1Set(ASM Self, int Value);

ASM SC_ASM_ConstStretchy_ValueSet(ASM Self, int Value);

ASM SC_ASM_Div_KindSet(ASM Self, int Value);

ASM SC_ASM_Div_LSet(ASM Self, int Value);

ASM SC_ASM_Float_DSet(ASM Self, int Value);

ASM SC_ASM_Float_LSet(ASM Self, int Value);

ASM SC_ASM_FloatAddExp_DSet(ASM Self, int Value);

ASM SC_ASM_FloatAddExp_Sh2Set(ASM Self, int Value);

ASM SC_ASM_FloatAddExp_Sh3Set(ASM Self, int Value);

ASM SC_ASM_FloatConst_HighSet(ASM Self, int Value);

ASM SC_ASM_Func_IncrSet(ASM Self, int Value);

ASM SC_ASM_Func_JUMPSet(ASM Self, int Value);

ASM SC_ASM_Func_SaveRegsSet(ASM Self, int Value);

ASM SC_ASM_Mem_LSet(ASM Self, int Value);

ASM SC_ASM_Mem_moveSet(ASM Self, int Value);

ASM SC_ASM_OperatorxE2x80xA2(ASM Self, bool B);

void ASMPrint(ASM Self);

ASM SC_ASM_R1Set(ASM Self, uint Value);

ASM SC_ASM_R2Set(ASM Self, uint Value);

ASM SC_ASM_R3Set(ASM Self, uint Value);

ASM SC_ASM_R4Set(ASM Self, uint Value);

ASM SC_ASM_RET_CountSet(ASM Self, int Value);

ASM SC_ASM_RET_ExistsSet(ASM Self, int Value);

ASM SC_ASM_RET_LSet(ASM Self, int Value);

ASM SC_ASM_Setn_CondSet(ASM Self, int Value);

ASM SC_ASM_Setn_InvSet(ASM Self, int Value);

ASM SC_ASM_Setn_Prm1Set(ASM Self, int Value);

ASM SC_ASM_Setn_ValueSet(ASM Self, int Value);

ASM SC_ASM_SWAP_ASet(ASM Self, int Value);

ASM SC_ASM_SWAP_BSet(ASM Self, int Value);

ASM SC_ASM_SWAP_CSet(ASM Self, int Value);

ASM SC_ASM_SWAP_DSet(ASM Self, int Value);

ASM SC_ASM_Tail_JUMPSet(ASM Self, int Value);

ASM SC_ASM_Trap_FuncSet(ASM Self, int Value);

ASM SC_ASM_Trap_LSet(ASM Self, int Value);

ASM SC_ASM_Trap_SignalSet(ASM Self, int Value);

ASM SC_ASM_U0_LSet(ASM Self, int Value);

ASM SC_ASM_U1_LSet(ASM Self, int Value);

ASM SC_ASM_U2_LSet(ASM Self, int Value);

ASM SC_ASM_U3_LSet(ASM Self, int Value);

ASM SC_ASM_U4_LSet(ASM Self, int Value);

int SC_ASM__Init_();

int SC_ASM__InitCode_();

void SC_ASM__ListInstructions();

bool SC_ASM__Needed();

void SC_ASM__TestASM();

void SC_ASM__TestASMSub(Message* Tests);



// ASMMath
bool SC_ASMMath_SyntaxIs(ASMMath Self, ASMMath R);



// ASMtmp
bool SC_ASMtmp_SyntaxIs(ASMtmp Self, ASMtmp T);

AsmReg SC_ASMtmp__Access(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__ARel(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__BRel(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__Continue(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__CountOnAddr(ASMState* Self, Message* F, AsmReg Dest, int Mode, AsmReg Src, int64 Amount);

AsmReg SC_ASMtmp__Debugger(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__DoFunc(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__DoGlobal(ASMState* Self, Message* Exp, AsmReg Dest, SCDecl* D);

AsmReg SC_ASMtmp__DoMath(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__DoMathSub(ASMState* Self, Message* Exp, AsmReg Dest, AsmReg Mr, SCOperator* Scop);

AsmReg SC_ASMtmp__DoSingleMath(ASMState* Self, Message* Exp, AsmReg Dest, SCOperator* Scop);

AsmReg SC_ASMtmp__Dot(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__Exit(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__First(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__If(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__Ignore(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

int64 SC_ASMtmp__IncrAmount(AsmReg Dest, int Mode, SCDecl* D);

AsmReg SC_ASMtmp__Incrementatulatorifier(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

int SC_ASMtmp__Init_();

void SC_ASMtmp__InitAccess();

int SC_ASMtmp__InitCode_();

AsmReg SC_ASMtmp__Minus(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__Not(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__Num(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__Pointer(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__Return(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__SetRel(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__SlowerCountOnAddr(ASMState* Self, Message* F, AsmReg Dest, int Mode, AsmReg Src, int64 Amount);

AsmReg SC_ASMtmp__StatExpr(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__Ternary(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__Thg(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__TypeCast(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__Unexpected(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);

AsmReg SC_ASMtmp__While(ASMState* Self, Message* Exp, AsmReg Dest, int Mode);



// AsmReg
ErrorInt SC_Reg_BadBits(AsmReg Self, AsmReg R);

int SC_Reg_BitCount(AsmReg Self);

bool SC_Reg_BitsAreCorrect(AsmReg Self, int Gap);

AsmReg SC_Reg_boolasm(AsmReg Self);

bool SC_Reg_CanAddK(AsmReg Self, int64 T);

bool SC_Reg_Exists(AsmReg Self);

int SC_Reg_GapBits(AsmReg Self);

AsmReg SC_Reg_HaveAddr(AsmReg Self);

int SC_Reg_IntDivType(AsmReg Self);

ASMMath SC_Reg_Math(AsmReg Self);

AsmReg SC_Reg_Negate(AsmReg Self);

AsmReg SC_Reg_OperatorAsWithAsmmath(AsmReg Self, ASMMath M);

AsmReg SC_Reg_OperatorAsWithReg(AsmReg Self, AsmReg A);

AsmReg SC_Reg_OperatorAsnt(AsmReg Self, AsmReg A);

bool SC_Reg_OperatorIsaWithTc(AsmReg Self, DataTypeCode M);

AsmReg SC_Reg_OperatorxE2x80xA2(AsmReg Self, AsmReg Dest);

ASM SC_Reg_ReadOrWrite(AsmReg Self, Message* M);

ASM SC_Reg_ReadOrWriteSub(AsmReg Self, Message* M, DataTypeCode T, int Bytes);

int SC_Reg_Reg(AsmReg Self);

AsmReg SC_Reg_RegSet(AsmReg Self, int Value);

AsmReg SC_Reg_RequestPos(AsmReg Self);

AsmReg SC_Reg_Set(AsmReg Self);

bool SC_Reg_Signed(AsmReg Self);

bool SC_Reg_SyntaxIs(AsmReg Self, AsmReg R);

AsmReg SC_Reg_SyntaxIsSet(AsmReg Self, AsmReg R, bool Value);

DataTypeCode SC_Reg_xC2xB5Type(AsmReg Self);

AsmReg SC_Reg_xC2xB5TypeSet(AsmReg Self, DataTypeCode Value);

AsmReg SC_Reg__New();



// CharProp


// ClassInfo


// Codepoint
bool JB_CP_In(Codepoint Self, int A, int B);

bool JB_CP_IsHigher(Codepoint Self);

bool JB_CP_IsLetter(Codepoint Self);

bool JB_CP_IsLower(Codepoint Self);

bool JB_CP_IsUpper(Codepoint Self);

bool JB_CP_IsWhite(Codepoint Self);



// ControlClipMode


// ControlLine


// ControlPoint


// ControlRect


// DataTypeCode
int JB_TC__Shift(DataTypeCode Self);

SCClass* SC_TC_Better_Numeric_Sub(DataTypeCode Self, DataTypeCode T, OpMode Op, Message* Where);

int JB_TC_BitCount(DataTypeCode Self);

int JB_TC_ByteCount(DataTypeCode Self);

int JB_TC_Count(DataTypeCode Self);

bool JB_TC_ExistsButBadlyNamedOrDesigned(DataTypeCode Self);

int SC_TC_FloatIntMerge(DataTypeCode Self, int Old, Message* S);

bool JB_TC_IsFloat(DataTypeCode Self);

bool JB_TC_IsInt(DataTypeCode Self);

bool JB_TC_IsSigned(DataTypeCode Self);

int JB_TC_ItemBitCount(DataTypeCode Self);

int JB_TC_NumericCount(DataTypeCode Self);

int SC_TC_NumericCountBoolsToo(DataTypeCode Self, SCDecl* D);

int JB_TC_Register(DataTypeCode Self);

DataTypeCode JB_TC_RegisterSet(DataTypeCode Self, int Value);

bool JB_TC_SameBasicType(DataTypeCode Self, DataTypeCode B);

DataTypeCode JB_TC_SetSigned(DataTypeCode Self, bool B);

SCClass* SC_TC_SignedStuffClass(DataTypeCode Self);

bool JB_TC_SyntaxIs(DataTypeCode Self, DataTypeCode M);

Dictionary* JB_TC__Types();



// Date
Date JB_Date_Ago(Date Self);

int JB_Date_DayOfWeek(Date Self);

int64 JB_Date_Days(Date Self);

JB_String* JB_Date_RenderDurr(Date Self, FastString* Fs_in);

JB_String* JB_Date_RenderInt(Date Self, FastString* Fs_in);

double JB_Date_Seconds(Date Self);

int64 JB_Date_WholeSeconds(Date Self);

Date JB_Date__New0();



// DeclMode
bool SC_DeclMode_SyntaxIs(DeclMode Self, DeclMode O);



// DotUseType
bool SC_DotUseType_SyntaxIs(DotUseType Self, DotUseType D);



// ErrorFlags


// ErrorInt


// ErrorInt2


// ErrorMarker


// ErrorSeverity
JB_String* JB_ErrorSeverity_Render(ErrorSeverity Self, FastString* Fs_in);

bool JB_ErrorSeverity_SyntaxIs(ErrorSeverity Self, ErrorSeverity E);

ErrorSeverity JB_ErrorSeverity_SyntaxUsing(ErrorSeverity Self);

void JB_ErrorSeverity_SyntaxUsingComplete(ErrorSeverity Self, JB_Object* Idk);

ErrorSeverity JB_ErrorSeverity__Find(JB_String* Name, Message* Err);

int JB_ErrorSeverity__Init_();

int JB_ErrorSeverity__InitCode_();

Array* JB_ErrorSeverity__InitNames();



// FailableInt


// FileDes


// FileMode


// FileResolveMode


// FileSizeInt


// FloatRangeConverter


// FloatRangeConverterBasic


// FlowControlStopper
FlowControlStopper JB_FlowControlStopper_SyntaxUsing(FlowControlStopper Self);

void JB_FlowControlStopper_SyntaxUsingComplete(FlowControlStopper Self, JB_Object* Idk);



// FunctionType


// Ind


// IntRange
bool JB_Rg_Contains1(IntRange Self, int I);

int JB_Rg_Width(IntRange Self);



// MaybeBool
bool JB_MaybeBool_IsFalse(MaybeBool Self);

bool JB_MaybeBool_IsKnown(MaybeBool Self);

bool JB_MaybeBool_IsTrue(MaybeBool Self);



// MoveCode


// MsgParseFlags


// NilCheckMode
NilCheckMode SC_khalai_Activate(NilCheckMode Self);

NilCheckMode SC_khalai_Negate(NilCheckMode Self);

NilCheckMode SC_khalai_Normal(NilCheckMode Self);

bool SC_khalai_SyntaxIs(NilCheckMode Self, NilCheckMode Other);

NilCheckMode SC_khalai_SyntaxIsSet(NilCheckMode Self, NilCheckMode Other, bool Value);



// NilReason
bool SC_NilReason_SyntaxIs(NilReason Self, NilReason X);

int SC_NilReason__Init_();

int SC_NilReason__InitCode_();



// NilRecord
int SC_NRD_DepthOfVars(NilRecord Self);

void ndb5(NilRecord Self);

NilState SC_NRD_SyntaxAccess(NilRecord Self, int Item);



// NilState
JB_String* SC_NilState_RawName(NilState Self);

NilState SC_NilState_StatedReal(NilState Self);

bool SC_NilState_SyntaxIs(NilState Self, NilState Type);



// OpMode
bool SC_OpMode_SyntaxIs(OpMode Self, OpMode X);



// PID_Int


// ProcessMode
bool JB_ProcessMode_SyntaxIs(ProcessMode Self, ProcessMode M);



// SCBlockage
int SC_SCBlockage_BlockCombine(SCBlockage Self, SCBlockage B);

bool SC_SCBlockage_SyntaxIs(SCBlockage Self, SCBlockage B);



// SCDeclInfo
SCDeclInfo SC_SCDeclInfo_Set(SCDeclInfo Self, SCDeclInfo D, bool B);



// SCNodeFindMode
bool SC_SCNodeFindMode_SyntaxIs(SCNodeFindMode Self, SCNodeFindMode M);



// SCNodeInfo


// SCNodeType
bool SC_SCNodeType_HasPtrs(SCNodeType Self);

bool SC_SCNodeType_SyntaxIs(SCNodeType Self, SCNodeType D);



// SizeInt


// Syntax
void JB_Syx_ExportAddrSet(Syntax Self, FP_fpMsgRender Value);

FP_fpMsgRender JB_Syx_ExportAddr(Syntax Self);

bool JB_Syx_IsString(Syntax Self);

bool JB_Syx_ListViewable(Syntax Self);

JB_String* JB_Syx_LongName(Syntax Self);

Message* JB_Syx_Msg(Syntax Self, JB_String* Name);

Message* JB_Syx_IntMsg(Syntax Self, int64 Name);

JB_String* JB_Syx_Name(Syntax Self);

bool JB_Syx_NoChildren(Syntax Self);

SyntaxObj* JB_Syx_Obj(Syntax Self);

Message* JB_Syx_OperatorPlus(Syntax Self, JB_String* M);

Message* JB_Syx_PlusNum(Syntax Self, int M);

FP_fpMsgRender JB_Syx_RenderAddr(Syntax Self);

bool JB_Syx_Translateable(Syntax Self);

Syntax JB_Syx__Func(JB_String* Name, Message* Where);

int JB_Syx__Init_();

int JB_Syx__InitCode_();

Syntax JB_Syx__StdNew(FP_fpMsgRender Msg, JB_String* Name, JB_String* LongName, int ID);



// TaskState


// TerminalColor


// __junktest_7__


// int8


// jbinLeaver


// mat2


// µParam
int SC_xC2xB5Param_BitSize(ASMParam Self);

bool SC_xC2xB5Param_IsNumber(ASMParam Self);

bool SC_xC2xB5Param_IsReg(ASMParam Self);



// ASM_BClear
ASM JB_ASM_BClear__Encode(FatASM* Self);



// ASM_BCmp
ASM JB_ASM_BCmp__Encode(FatASM* Self);



// ASM_BFLD
ASM JB_ASM_BFLD__Encode(FatASM* Self);



// ASM_Bra
ASM JB_ASM_Bra__Encode(FatASM* Self);



// ASM_CNTC
ASM JB_ASM_CNTC__Encode(FatASM* Self);



// ASM_Cmp
ASM JB_ASM_Cmp__Encode(FatASM* Self);



// ASM_CmpD
ASM JB_ASM_CmpD__Encode(FatASM* Self);



// ASM_CmpEq
ASM JB_ASM_CmpEq__Encode(FatASM* Self);



// ASM_Const
ASM JB_ASM_Const__Encode(FatASM* Self);



// ASM_ConstStretchy
ASM JB_ASM_ConstStretchy__Encode(FatASM* Self);



// ASM_Div
ASM JB_ASM_Div__Encode(FatASM* Self);



// ASM_Float
ASM JB_ASM_Float__Encode(FatASM* Self);



// ASM_FloatAddExp
ASM JB_ASM_FloatAddExp__Encode(FatASM* Self);



// ASM_FloatConst
ASM JB_ASM_FloatConst__Encode(FatASM* Self);



// ASM_Func
ASM JB_ASM_Func__Encode(FatASM* Self);



// ASM_Mem
ASM JB_ASM_Mem__Encode(FatASM* Self);



// ASM_RET
ASM JB_ASM_RET__Encode(FatASM* Self);



// ASM_SWAP
ASM JB_ASM_SWAP__Encode(FatASM* Self);



// ASM_Setn
ASM JB_ASM_Setn__Encode(FatASM* Self);



// ASM_Tail
ASM JB_ASM_Tail__Encode(FatASM* Self);



// ASM_Trap
ASM JB_ASM_Trap__Encode(FatASM* Self);



// ASM_U0
ASM JB_ASM_U0__Encode(FatASM* Self);



// ASM_U1
ASM JB_ASM_U1__Encode(FatASM* Self);



// ASM_U2
ASM JB_ASM_U2__Encode(FatASM* Self);



// ASM_U3
ASM JB_ASM_U3__Encode(FatASM* Self);



// ASM_U4
ASM JB_ASM_U4__Encode(FatASM* Self);



// HumanDate


// ASM_Encoder2


// CollectFunc


// ExprResolver


// NilTrackerFn


// ParseHandler


// PicoThreadFn


// SaverLoadClass


// ShellOption


// SorterComparer
void JB_SorterComparer_sort(FP_SorterComparer Self, Array* A, bool Reverse);



// SorterComparer2


// SorterComparerDecl


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


// prototype


// JB_ASMState
AsmReg SC_Pac_AddConstant(ASMState* Self, Message* Exp, AsmReg Dest, AsmReg Src, int64 Value);

void SC_Pac_AddFuncParams(ASMState* Self, SCFunction* Fn);

void SC_Pac_AddLabel(ASMState* Self, Message* Ch);

void SC_Pac_AddToReg(ASMState* Self, AsmReg Addr, int Add, Message* Exp);

bool SC_Pac_Alloc(ASMState* Self, MWrap* J);

AsmReg SC_Pac_Assign(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_BitAnd(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_BitOr(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_BitXnor(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_BitXor(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_BoolMul(ASMState* Self, AsmReg Dest, AsmReg Boo, AsmReg R, Message* Exp);

FatASM* SC_Pac_Branch(ASMState* Self, Message* Cond);

AsmReg SC_Pac_Compare(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp, int Mode);

FatASM* SC_Pac_CompareFloat(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp, int Mode);

FatASM* SC_Pac_CompareInt(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp, int Mode);

AsmReg SC_Pac_DeclareMe(ASMState* Self, Message* Where, AsmReg T);

void SC_Pac_Destructor(ASMState* Self);

AsmReg SC_Pac_Div(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_DivFloat(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_DivInt(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_DoConsts(ASMState* Self, AsmReg D, AsmReg L, AsmReg R, uint64* RImm);

AsmReg SC_Pac_DoF32Const(ASMState* Self, AsmReg D, float* DD, float* LL, float* RR, OpMode M);

AsmReg SC_Pac_DoF64Const(ASMState* Self, AsmReg D, double* DD, double* LL, double* RR, OpMode M);

AsmReg SC_Pac_DoI32Const(ASMState* Self, AsmReg D, int* DD, int* LL, int* RR, OpMode M);

AsmReg SC_Pac_DoI64Const(ASMState* Self, AsmReg D, int64* DD, int64* LL, int64* RR, OpMode M);

void SC_Pac_DoPostIncr(ASMState* Self);

AsmReg SC_Pac_Equals(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

FatASM* SC_Pac_EqualsInt(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_ExistingVar(ASMState* Self, Message* M);

double SC_Pac_f(ASMState* Self, AsmReg R);

AsmReg SC_Pac_FindConst(ASMState* Self, uint64 Code);

FatASM* SC_Pac_FindLabel(ASMState* Self, FatASM* Dbg);

void SC_Pac_FinishASM(ASMState* Self);

int SC_Pac_GetLabelJump(ASMState* Self, Message* P);

void SC_Pac_InitState(ASMState* Self, SCFunction* Fn);

FailableInt SC_Pac_IntPowerOfTwo(ASMState* Self, AsmReg R);

FatASM* SC_Pac_Last(ASMState* Self);

AsmReg SC_Pac_Less(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_LessEq(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

bool SC_Pac_LoadLabelJumps(ASMState* Self);

Message* SC_Pac_LoadTitle(ASMState* Self, Message* M);

AsmReg SC_Pac_Mod(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_More(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_MoreEq(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_Mul(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_NotEq(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_NumToEgg(ASMState* Self, int64 V, Message* Exp);

void SC_Pac_NumToReg(ASMState* Self, int64 V, Message* Exp, int Reg);

int SC_Pac_OpenVars(ASMState* Self);

bool SC_Pac_PackMakerInit(ASMState* Self);

AsmReg SC_Pac_Plus(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_PlusFloat(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_PlusInt(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

void SC_Pac_PostOne(ASMState* Self, Message* Exp);

AsmReg SC_Pac_Prm(ASMState* Self, Message* Prm);

AsmReg SC_Pac_QuickFloatDiv(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_QuickFloatMul(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_QuickFloatOp(ASMState* Self, ASM Op, Message* Exp, AsmReg Dest, AsmReg L, AsmReg R);

AsmReg SC_Pac_QuickFloatPlus(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_QuickIntMul(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_ROL(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_ROR(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

bool SC_Pac_SetConst(ASMState* Self, Message* List, Message* Orig);

AsmReg SC_Pac_SHL(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_SHR(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

AsmReg SC_Pac_SimpleTernary(ASMState* Self, AsmReg Dest, AsmReg Ma, AsmReg Mb, Message* Cond);

AsmReg SC_Pac_Subtract(ASMState* Self, AsmReg Dest, AsmReg L, AsmReg R, Message* Exp);

FatASM* SC_Pac_RequestOp(ASMState* Self, int Code, Message* Dbg);

AsmReg SC_Pac_TempMe(ASMState* Self, Message* Where, AsmReg T);

bool SC_Pac_TextFuncSub(ASMState* Self, Message* M);

void SC_Pac_TextInstruction(ASMState* Self, Message* M);

bool SC_Pac_TextOp(ASMState* Self, Message* M);

AsmReg SC_Pac_xC2xB5Open(ASMState* Self, Message* Exp);

AsmReg SC_Pac_xC2xB5Sync(ASMState* Self, Message* Exp);

bool SC_Pac__ExpandJSM();

int SC_Pac__Init_();

int SC_Pac__InitCode_();



// JB_ASMVarType


// JB_ArchonPurger
void SC_nil_BecomeRealSub(ArchonPurger* Self, SCDecl* V);

NilRecord SC_nil_BranchEnter(ArchonPurger* Self, Message* Where);

NilState SC_nil_BranchExit(ArchonPurger* Self, NilRecord A);

NilRecord SC_nil_BranchSwap(ArchonPurger* Self, NilRecord A);

void SC_nil_CheckNilCheck(ArchonPurger* Self, SCFunction* F);

NilState SC_nil_Declare(ArchonPurger* Self, SCDecl* D, NilState Nd);

NilState SC_nil_DeclareSub(ArchonPurger* Self, SCDecl* D, NilState Nd);

void SC_nil_Destructor(ArchonPurger* Self);

void SC_nil_FinishNil(ArchonPurger* Self, SCFunction* F);

int SC_nil_NestDepth(ArchonPurger* Self);

NilState SC_nil_Self(ArchonPurger* Self);

Message* SC_nil_StartNil(ArchonPurger* Self, SCFunction* F);

NilState SC_nil__Access(Message* Msg, NilCheckMode Test);

NilState SC_nil__arel(Message* Msg, NilCheckMode Test);

NilState SC_nil__Argument(Message* Msg, NilCheckMode Test);

NilState SC_nil__BecomeReal(SCDecl* Sent, Message* Where, NilReason Reason, SCDecl* Recv, SCFunction* To);

NilState SC_nil__BecomeRealSub(SCDecl* Sent, Message* Where, NilReason Reason, SCDecl* Recv, SCFunction* To, NilState Curr);

NilState SC_nil__BooleanLogic(Message* Msg, NilCheckMode Test);

NilState SC_nil__Bracket(Message* Msg, NilCheckMode Test);

NilState SC_nil__Brel(Message* Msg, NilCheckMode Test);

NilState SC_nil__Char(Message* Msg, NilCheckMode Test);

NilState SC_nil__CompareObjs(Message* Ll, Message* Rr, NilCheckMode Test, SCOperator* Scop);

NilState SC_nil__Continue(Message* Msg, NilCheckMode Test);

NilState SC_nil__Debugger(Message* Msg, NilCheckMode Test);

NilState SC_nil__Declaration(Message* Msg, NilCheckMode Test);

NilState SC_nil__DetectStillChecks(Message* First);

NilState SC_nil__Dummy(Message* Msg, NilCheckMode Test);

NilState SC_nil__Exit(Message* Msg, NilCheckMode Test);

void SC_nil__ExterminateZergBugs(SCFunction* F);

NilState SC_nil__Fail(Message* Msg, NilCheckMode Test);

NilState SC_nil__FailedReal(SCFunction* To, Message* Where, NilReason Reason, NilState State);

void SC_nil__FixArchons();

NilState SC_nil__Function(Message* Msg, NilCheckMode Test);

NilState SC_nil__If(Message* Msg, NilCheckMode Test);

NilState SC_nil__Ignore(Message* Msg, NilCheckMode Test);

int SC_nil__Init_();

int SC_nil__InitCode_();

NilState SC_nil__Item(Message* Msg, NilCheckMode Test);

NilState SC_nil__JumpNoPosts(Message* Msg, NilCheckMode Test);

NilState SC_nil__List(Message* Msg, NilCheckMode Test);

void ndb4();

void SC_nil__NilParamPass(SCDecl* Recv, SCDecl* Sent, Message* Where, SCFunction* F, NilState V);

NilState SC_nil__Not(Message* Msg, NilCheckMode Test);

NilState SC_nil__Number(Message* Msg, NilCheckMode Test);

NilState SC_nil__Pointer(Message* Msg, NilCheckMode Test);

NilState SC_nil__ProcessNormalRel(Message* Msg, NilCheckMode Test);

NilState SC_nil__Property(Message* Msg, NilCheckMode Test);

NilState SC_nil__PropertyToFunc(Message* Dot, SCFunction* Fn);

NilState SC_nil__RealBool(bool B);

NilState SC_nil__Rejoin(Message* Msg, NilCheckMode Test);

NilState SC_nil__Rel(Message* Msg, NilCheckMode Test);

NilState SC_nil__Return(Message* Msg, NilCheckMode Test);

NilState SC_nil__SetRel(Message* Msg, NilCheckMode Test);

NilState SC_nil__StatementJump(Message* Msg, NilCheckMode Test);

NilState SC_nil__StatExpr(Message* Msg, NilCheckMode Test);

NilState SC_nil__String(Message* Msg, NilCheckMode Test);

NilState SC_nil__SuperSmartMagicCompare(Message* Ll, Message* Rr, NilCheckMode Test, SCOperator* Scop);

NilState SC_nil__SyncJump(Message* Msg, NilCheckMode Test);

NilState SC_nil__Tern(Message* Msg, NilCheckMode Test);

NilState SC_nil__Thing(Message* Msg, NilCheckMode Test);

NilState SC_nil__ThingSub(Message* Msg, NilCheckMode Test, SCDecl* Dcl);

void SC_nil__TrackerDummies();

NilState SC_nil__Type(Message* Msg, NilCheckMode Test);

NilState SC_nil__UseChildAsReal(Message* Msg, NilCheckMode Test, NilReason Reason);

NilState SC_nil__VariableSet(SCDecl* Recv, Message* RecvMsg, SCDecl* Sent, Message* SentMsg, NilState SentState);

NilState SC_nil__While(Message* Msg, NilCheckMode Test);



// JB_ArgArrayCounter
void SC_ArgArrayCounter_Check(ArgArrayCounter* Self, Message* Exp);

Message* SC_ArgArrayCounter_Do(ArgArrayCounter* Self, JB_String* Name, Message* Item, SCNode* Name_space);



// JB_CharProps


// JB_ClassData
JB_MemoryLayer* JB_ClassData_CreateUseLayer(JB_Class* Self, JB_Object* Obj, JB_Object* Obj2);

void JB_ClassData_Restore(JB_Class* Self);



// JB_CompressionStats
void JB_MzSt_Clear(CompressionStats* Self);

float JB_MzSt_Durr(CompressionStats* Self);

void JB_MzSt_End(CompressionStats* Self);

void JB_MzSt_LiveUpdate(CompressionStats* Self, int Inn, int Outt);

void JB_MzSt_Print(CompressionStats* Self);

JB_String* JB_MzSt_Render(CompressionStats* Self, FastString* Fs_in);

void JB_MzSt_Start(CompressionStats* Self);

int JB_MzSt__Init_();

int JB_MzSt__InitCode_();



// JB_FakeJBString


// JB_FastBuff
bool JB_FastBuff_Alloc(FastBuff* Self, int N);

byte JB_FastBuff_Byte(FastBuff* Self);

byte* JB_FastBuff_Clip(FastBuff* Self, int V, int Reduce);

int JB_FastBuff_CopyTo(FastBuff* Self, byte* Dest, int Length);

void JB_FastBuff_Destructor(FastBuff* Self);

bool JB_FastBuff_Has(FastBuff* Self, int N);

bool JB_FastBuff_HasAny(FastBuff* Self);

int JB_FastBuff_Length(FastBuff* Self);

bool JB_FastBuff_NeedAlloc(FastBuff* Self, int N);

int64 JB_FastBuff_Position(FastBuff* Self);

void JB_FastBuff_PositionSet(FastBuff* Self, int64 Value);

void JB_FastBuff_ReadFromSet(FastBuff* Self, JB_String* Value);

int64 JB_FastBuff_Remaining(FastBuff* Self);

int JB_FastBuff_Size(FastBuff* Self);

JB_String* JB_FastBuff_AccessStr(FastBuff* Self, int Pos, int After);

void JB_FastBuff_SyntaxExpect(FastBuff* Self, JB_String* S);

JB_String* JB_FastBuff_TmpStr(FastBuff* Self);



// JB_FatASM
void SC_FatASM_AddRegNum(FatASM* Self, Message* Src, int Write, int Num);

void SC_FatASM_AddRegParam(FatASM* Self, Message* Src, int Write);

void SC_FatASM_DebugSet(FatASM* Self, Message* Value);

ASM SC_FatASM_Encode(FatASM* Self);

JB_String* SC_FatASM_File(FatASM* Self);

bool SC_FatASM_OperatorIsa(FatASM* Self, int M);

void SC_FatASM_Print(FatASM* Self);

void SC_FatASM_Renda(FatASM* Self, FastString* Fs);

void SC_FatASM_SyntaxExpect(FatASM* Self, JB_String* Error);



// JB_FloatRange


// JB_GameFlyingMem


// JB_IntDownRange


// JB_IsaTester
int SC_IsaTester__Init_();

int SC_IsaTester__InitCode_();

void SC_IsaTester__SyntaxAppend(Message* O);



// JB_LoopInfo
LoopInfo SC_LoopInfo_BeginLoop(LoopInfo* Self, bool HasExitCond);

void SC_LoopInfo_FinishLoop(LoopInfo* Self, Message* Msg);

void SC_LoopInfo_NextLoop(LoopInfo* Self);



// JB_Mat4


// JB_MemoryWorld


// JB_MessagePosition
void JB_MsgPos_Destructor(MessagePosition* Self);

void JB_MsgPos_SyntaxUsingComplete(MessagePosition* Self, JB_Object* Idk);



// JB_MiniHuffItem


// JB_ModelTest


// JB_NameAndMsg
void SC_NameAndMsg_Destructor(NameAndMsg* Self);

void SC_NameAndMsg_SyntaxAppend(NameAndMsg* Self, Message* M);



// JB_NilRecorder
void SC_NRC_SyntaxCallSet(NilRecorder* Self, uint64 Item, uint64 Value);



// JB_ObjectLoader
void JB_LD_Destructor(ObjectLoader* Self);

void JB_LD_Finish(ObjectLoader* Self);

JB_Class* JB_LD_GetClassOf(ObjectLoader* Self, Message* Msg);

bool JB_LD_HasItem(ObjectLoader* Self);

int64 JB_LD_Int(ObjectLoader* Self);

int64 JB_LD_ItemInt(ObjectLoader* Self);

bool JB_LD_ItemIsInt(ObjectLoader* Self);

JB_String* JB_LD_ItemName(ObjectLoader* Self);

JB_Object* JB_LD_ItemObject(ObjectLoader* Self);

void JB_LD_LoadClass(ObjectLoader* Self, Message* Msg, Dictionary* Dict);

void JB_LD_LoadForReal(ObjectLoader* Self, Message* Root, Dictionary* D);

void JB_LD_LoadObject(ObjectLoader* Self, Message* Msg, Dictionary* Dict, JB_Class* Cls);

Message* JB_LD_Next(ObjectLoader* Self);

JB_Object* JB_LD_Object(ObjectLoader* Self);

JB_Object* JB_LD_ObjectSub(ObjectLoader* Self, Message* C);

void JB_LD_Preload(ObjectLoader* Self, Message* Root, Dictionary* Dict);

JB_String* JB_LD_String(ObjectLoader* Self);

bool JB_LD_VerifyFormat(ObjectLoader* Self, Message* Root);

void JB_LD__Init();

int JB_LD__Init_();

int JB_LD__InitCode_();

void JB_LD__LoadOne(JB_Class* Cls, char* Data);



// JB_ObjectSaver
void JB_Saver_AppendInt(ObjectSaver* Self, int64 I);

void JB_Saver_AppendObject(ObjectSaver* Self, JB_Object* O);

void JB_Saver_AppendString(ObjectSaver* Self, JB_String* S);

void JB_Saver_Destructor(ObjectSaver* Self);

void JB_Saver_Finish(ObjectSaver* Self, Saveable* First);

void JB_Saver__Init();

int JB_Saver__Init_();

int JB_Saver__InitCode_();

void JB_Saver__LoadOne(JB_Class* Cls, char* Data);

ObjectSaver JB_Saver__New();



// JB_Object_Behaviour


// JB_ParserLineAndIndent


// JB_Pico
JB_String* JB_Pico_Get(PicoComms* Self, float T);

bool JB_Pico_SendFS(PicoComms* Self, FastString* Fs, bool Wait);

int JB_Pico__Init_();

int JB_Pico__InitCode_();

PicoComms* JB_Pico__New(JB_StringC* Name, int Bits);

PicoComms* JB_Pico__Parent();



// JB_PicoConfig


// JB_PicoGlobalConfig


// JB_PicoGlobalStats


// JB_PicoMessage
PicoMessage JB_Pico__FromFS(FastString* Fs);



// JB_Random
double JB_Rnd_Double(Random* Self);

float JB_Rnd_Float(Random* Self);

int64 JB_Rnd_RndInt(Random* Self);

void JB_Rnd_LoadProperties(Random* Self, ObjectLoader* Loader);

void JB_Rnd_SaveWrite(Random* Self, ObjectSaver* Saver);

void JB_Rnd_SeedSet(Random* Self, uint64 Value);

double JB_Rnd_SyntaxAccess(Random* Self);

void JB_Rnd_TimeSeed(Random* Self);

int JB_Rnd__Init_();

int JB_Rnd__InitCode_();



// JB_RetroFloat


// JB_SpeedTester


// JB_StringDigitIterator


// JB_StringLengthSplit


// JB_StructSaveTest
void JB_StructSaveTest_Destructor(StructSaveTest* Self);

void JB_StructSaveTest_LoadProperties(StructSaveTest* Self, ObjectLoader* Loader);

void JB_StructSaveTest_SaveWrite(StructSaveTest* Self, ObjectSaver* Saver);



// JB_jb_vm


// JB_ћ


// JB_ByteMap_Behaviour


// JB_Charset_Behaviour


// JB_ContainerStruct2


// JB_CppRefs_Behaviour


// JB_Cpp_Export_Behaviour


// JB_DataObject_Behaviour


// JB_DictionaryReader_Behaviour


// JB_ErrorReceiver_Behaviour


// JB_FastString_Behaviour


// JB_FileComparer_Behaviour


// JB_FixedDict_Behaviour


// JB_FlowControl_Behaviour


// JB_HuffByteCoder_Behaviour


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


// JB_ContainerStruct


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


// JB_HuffNode_Behaviour


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
SCDecl* SC_Object_AsDecl(JB_Object* Self);

SCDecl* SC_Object_BaseAsDecl(JB_Object* Self);

SCNode* SC_Object_ClassOrModule(JB_Object* Self);

void jdb(JB_Object* Self);

bool JB_Object_MustBe(JB_Object* Self, JB_Class* X, Message* ErrNode);

JB_Object* JB_Object_As(JB_Object* Self, JB_Class* X);

JB_Object* JB_Object_FastAs(JB_Object* Self, JB_Class* X);

bool JB_Object_FastIsa(JB_Object* Self, JB_Class* X);

bool JB_Object_Isa(JB_Object* Self, JB_Class* Cls);

bool JB_Object_OperatorMustBe(JB_Object* Self, JB_Class* X);

void JB_Object_SaveTryCollect(JB_Object* Self, ObjectSaver* Saver);

void JB_Object_Fail(JB_Object* Self, JB_String* Error);

void JB_Object_SyntaxExpect(JB_Object* Self);

JB_Object* JB_Object_TypeFailed(JB_Object* Self, JB_Class* Cls, Message* Where);



// JB_AppArgument
JB_String* JB_AppArgument_Name(JB_Object* Self);

JB_String* JB_AppArgument_Value(JB_Object* Self);



// JB_ByteMap


// JB_Charset
Array* JB_CS_Bytes(CharSet* Self);

bool JB_CS_NextInCharset(CharSet* Self, int* P);

bool JB_CS_OperatorContains(CharSet* Self, JB_String* Data);



// JB_CppRefs
void SC_CppRefs_AddOne(CppRefs* Self, Message* C);

CppRefs* SC_CppRefs_Constructor(CppRefs* Self, Message* S);

void SC_CppRefs_Destructor(CppRefs* Self);

Array* SC_CppRefs_DisturbsGet(CppRefs* Self);

void SC_CppRefs_Read(CppRefs* Self, Message* Node);

void SC_CppRefs_SetDefaultRefStatus(CppRefs* Self);

SCNode* SC_CppRefs__Linkage(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_CppRefs__ReadIntoCppRefs(Message* Node, SCNode* Name_space, Message* ErrPlace);



// JB_Cpp_Export
void SC_Cpp_AppendCppField(Cpp_Export* Self, JB_String* Prop, FastStringCpp* Fs);

void SC_Cpp_AppendPropField(Cpp_Export* Self, SCDecl* Prop, FastStringCpp* Fs);

bool SC_Cpp_CanExportFunc(Cpp_Export* Self, SCFunction* F);

bool SC_Cpp_CanOpt(Cpp_Export* Self, bool Force);

void SC_Cpp_Codify(Cpp_Export* Self, SCModule* Scb, JB_String* fName);

void SC_Cpp_CodifyFuncs(Cpp_Export* Self, FastStringCpp* File, Array* List);

void SC_Cpp_CodifyInlines(Cpp_Export* Self);

Cpp_Export* SC_Cpp_Constructor(Cpp_Export* Self);

void SC_Cpp_CppFunc(Cpp_Export* Self, FastStringCpp* Fs, SCFunction* F);

void SC_Cpp_Destructor(Cpp_Export* Self);

void SC_Cpp_ExportBehaviourHeader(Cpp_Export* Self, SCClass* Cls);

bool SC_Cpp_ExportBehaviourInstance(Cpp_Export* Self, SCClass* Cls, FastStringCpp* Fs);

void SC_Cpp_ExportClass(Cpp_Export* Self, SCClass* Cls, FastStringCpp* CppFile);

void SC_Cpp_ExportModuleProperties(Cpp_Export* Self, SCModule* Modl, FastStringCpp* IntoModule);

bool SC_Cpp_ExportOneProperty(Cpp_Export* Self, SCClass* Cls, FastStringCpp* Fs, JB_String* Only);

void SC_Cpp_ExportProperties(Cpp_Export* Self, SCClass* Cls, FastStringCpp* Fs, JB_String* Ignore);

void SC_Cpp_ExportStruct(Cpp_Export* Self, SCClass* Cls, bool IsBehaviour);

void SC_Cpp_ExportSyx(Cpp_Export* Self);

void SC_Cpp_FillInterpreter(Cpp_Export* Self);

void SC_Cpp_FinalMergeOutputIntoACpp(Cpp_Export* Self);

JB_String* SC_Cpp_FuncHeader(Cpp_Export* Self, SCFunction* F);

void SC_Cpp_FuncStart(Cpp_Export* Self, FastStringCpp* Fs, SCFunction* F, JB_String* Funcheader);

void SC_Cpp_ListAllFuncs(Cpp_Export* Self, FastStringCpp* Fs, JB_String* Lib_pack);

void SC_Cpp_MakeWrapperFor(Cpp_Export* Self, FastStringCpp* Fs, SCFunction* F);

void SC_Cpp_OptEnd(Cpp_Export* Self, FastStringCpp* Fs, int M, bool Force);

void SC_Cpp_OptStart(Cpp_Export* Self, FastStringCpp* Fs, int M, bool Force);

void SC_Cpp_PreRun(Cpp_Export* Self);

void SC_Cpp_Run(Cpp_Export* Self);

void SC_Cpp_SetupFlow(Cpp_Export* Self, SCFunction* F);

FastStringCpp* SC_Cpp_StreamChild(Cpp_Export* Self, JB_String* S);

void SC_Cpp_WriteAPIFuncHeader(Cpp_Export* Self, SCFunction* F, FastStringCpp* Fs);

void SC_Cpp_WriteAPIHeader(Cpp_Export* Self, JB_File* Destfile);

void SC_Cpp_WriteHeader(Cpp_Export* Self);

JB_File* SC_Cpp__APIHeader();

void SC_Cpp__C_FSListComma(Message* Self, FastStringCpp* Fs);

bool SC_Cpp__C_OneParamType(FastStringCpp* Fs, Message* Curr, SCDecl* D);

void SC_Cpp__C_ParamsRender(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderAcc(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderArel(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderArg(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderBak(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderBra(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderBrel(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderChr(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderDcl(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderDot(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderFnc(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderItem(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderList(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderNum(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderOpp(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderRel(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderShe(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderSStr(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderStr(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderThg(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderTmp(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderTyp(Message* Self, FastStringCpp* Fs);

void SC_Cpp__C_RenderUnt(Message* Self, FastStringCpp* Fs);

JB_String* SC_Cpp__CDotType(Message* Msg, SCDecl* Type, FastStringCpp* Fs);

JB_String* SC_Cpp__CppLicence();

JB_File* SC_Cpp__CppProduct();

void SC_Cpp__CreateClassListFunc(FastString* Dest);

void SC_Cpp__CreateClassListHeader(FastString* Fs, JB_String* S);

int SC_Cpp__DontNeedMoreBrackets(Message* Msg);

bool SC_Cpp__DoSavers();

void SC_Cpp__ExportAllSource();

void SC_Cpp__GenLub(FastString* Fs);

void SC_Cpp__GenStrings(FastString* Fs);

JB_File* SC_Cpp__HProduct();

void SC_Cpp__Init();

int SC_Cpp__Init_();

int SC_Cpp__InitCode_();

bool SC_Cpp__MsgOKToImprove(Message* Msg);

bool SC_Cpp__NeedsDotForC(SCDecl* D);

JB_File* SC_Cpp__Product(JB_String* Name);

void SC_Cpp__RenderInBracketsIfRel(Message* Self, FastStringCpp* Fs);

void SC_Cpp__SmartWrite(JB_String* S, JB_File* F);

JB_String* SC_Cpp__SplitCpp(FastStringCpp* Fs, JB_String* Name);

void SC_Cpp__WriteClass(SCClass* C, FastStringCpp* T);

void SC_Cpp__WriteConst(SCDecl* D, FastStringCpp* T);

void SC_Cpp__WriteDecl(SCDecl* D, FastStringCpp* T, Message* Equality);

void SC_Cpp__WriteDeclBrackets(Message* Self, FastStringCpp* Fs);

void SC_Cpp__WriteDeclNoName(SCDecl* D, FastStringCpp* T);

void SC_Cpp__WriteFuncArgs(SCFunction* F, FastStringCpp* T, bool Names_only);

void SC_Cpp__WriteFuncSub(SCFunction* F, JB_String* E, FastStringCpp* T);

void SC_Cpp__WriteFunctionHeader(SCFunction* F, FastStringCpp* T);

void SC_Cpp__WriteName(JB_String* Name, FastString* Blob, FastString* Lengths);

JB_String* SC_Cpp__WriteStrings(FastString* Lengths);

void SC_Cpp__WriteThgMaybeTypeToo(Message* Msg, SCDecl* D, FastStringCpp* Fs);

void SC_Cpp__WriteType(SCClass* C, FastStringCpp* Fs, bool Always);



// JB_DataObject
DTWrap* JB_Wrap_ConstructorInt(DTWrap* Self, int64 V);

DTWrap* JB_Wrap_ConstructorVoidPtr(DTWrap* Self, void* P);

void JB_Wrap_Destructor(DTWrap* Self);

int64 JB_Wrap_First(DTWrap* Self);

double JB_Wrap_FloatValue(DTWrap* Self);

JB_String* JB_Wrap_Render(DTWrap* Self, FastString* Fs_in);

int64 JB_Wrap_Value(DTWrap* Self);



// JB_DictionaryReader
JB_Object* JB_DictionaryReader_NextValue(DictionaryReader* Self);

SCDecl* SC_DictionaryReader_ValueDecl(DictionaryReader* Self);



// JB_ErrorReceiver
int JB_Rec_BadCount(JB_ErrorReceiver* Self);

bool JB_Rec_CanAddMore(JB_ErrorReceiver* Self, ErrorSeverity Level);

void JB_Rec_Clear(JB_ErrorReceiver* Self);

JB_ErrorReceiver* JB_Rec_Constructor(JB_ErrorReceiver* Self);

void JB_Rec_Destructor(JB_ErrorReceiver* Self);

bool JB_Rec_HasAnything(JB_ErrorReceiver* Self);

bool JB_Rec_HasProblems(JB_ErrorReceiver* Self);

void JB_Rec_Incr(JB_ErrorReceiver* Self, JB_Error* Err, bool Add);

JB_Error* JB_Rec_LastError(JB_ErrorReceiver* Self);

void JB_Rec_LogFileWriter(JB_ErrorReceiver* Self, JB_String* Data);

ErrorMarker JB_Rec_Mark(JB_ErrorReceiver* Self);

bool JB_Rec_OK(JB_ErrorReceiver* Self);

JB_Error* JB_Rec_Pop(JB_ErrorReceiver* Self);

void SC_Rec_PrePrintErrors(JB_ErrorReceiver* Self);

int JB_Rec_PrintErrorsMain(JB_ErrorReceiver* Self, ErrorSeverity Level, bool PrintCount, bool Shell);

JB_String* JB_Rec_Render(JB_ErrorReceiver* Self, FastString* Fs_in);

int JB_Rec_RenderErrors(JB_ErrorReceiver* Self, FastString* Fs, ErrorSeverity Level, bool Shell);

int SC_Rec_ReturnErrors(JB_ErrorReceiver* Self, JB_ErrorReceiver* To);

int JB_Rec_ShellPrintErrors(JB_ErrorReceiver* Self);

void JB_Rec_AppendErr(JB_ErrorReceiver* Self, JB_Error* Err);

JB_ErrorReceiver* JB_Rec_SyntaxUsing(JB_ErrorReceiver* Self);

void JB_Rec_SyntaxUsingComplete(JB_ErrorReceiver* Self, JB_Object* Idk);

bool SC_Rec_TooMany(JB_ErrorReceiver* Self);

int JB_Rec__Init_();

int JB_Rec__InitCode_();

void JB_Rec__NewErrorWithNode(Message* Node, JB_String* Desc, JB_String* Path);

void JB_Rec__NewErrorSub(Message* Node, JB_String* Desc, JB_String* Path, int Sev);

void JB_Rec__NewProblem(Message* Node, JB_String* Desc, JB_String* Path);

void JB_Rec__NewWarning(Message* Node, JB_String* Desc, JB_String* Path);



// JB_FastString
void SC_FS_AppendCpp(FastString* Self, JB_String* S);

void SC_FS_AppendCppAll(FastString* Self, JB_String* S);

void JB_FS_AppendEscape(FastString* Self, JB_String* S);

void JB_FS_AppendHexStr(FastString* Self, JB_String* Data);

void JB_FS_AppendObjectID(FastString* Self, Saveable* O);

void JB_FS_AppendObjectOrNil(FastString* Self, JB_Object* O);

void JB_FS_AppendQuotedEscape(FastString* Self, JB_String* S);

void SC_FS_appendvoid(FastString* Self, JB_String* S, byte Extra);

void SC_FS_AppendWidth(FastString* Self, JB_String* S, int Width);

void SC_FS_CArrayAdd(FastString* Self, JB_String* S);

void SC_FS_CArrayAddB(FastString* Self, byte B);

void SC_FS_CArrayAddB0(FastString* Self, byte B);

void JB_FS_EncodeLength(FastString* Self, uint64 N);

void JB_FS_AppendInfo(FastString* Self, JB_String* Name, JB_String* Data);

void JB_FS_AppendInfoNum(FastString* Self, JB_String* Name, int64 Data);

void JB_FS_AppendInfoFloat(FastString* Self, JB_String* Name, double Data);

void JB_FS_FieldStart(FastString* Self, JB_String* Name);

void JB_FS_hInt(FastString* Self, uint64 N);

void SC_FS_IncludeH(FastString* Self, JB_String* Name);

void JB_FS_lInt(FastString* Self, uint64 N);

void JB_FS_MsgErrorName(FastString* Self, JB_String* Name);

void JB_FS_Normal(FastString* Self, JB_String* S);

void SC_FS_pc(FastString* Self, float Amount, float Over);

void JB_FS_PrintNicely(FastString* Self, JB_String* S);

void JB_FS_ProblemsFound(FastString* Self, int Count);

JB_String* JB_FS_Render(FastString* Self, FastString* Fs_in);

void JB_FS_RenderSpeed(FastString* Self, float Seconds, int64 BytesIn, int64 BytesOut, JB_String* Name);

void JB_FS_AppendMultiStr(FastString* Self, JB_String* Data, int Count);

void JB_FS_AppendFastString(FastString* Self, FastString* Fs);

void JB_FS_AppendInt64(FastString* Self, int64 Data);

void JB_FS_AppendUint(FastString* Self, uint Data);

void JB_FS_AppendInt32(FastString* Self, int Data);

void JB_FS_AppendFloatAsText(FastString* Self, float F);

void JB_FS_AppendBool(FastString* Self, bool B);

void JB_FS_SyntaxAppend(FastString* Self, Message* Msg);

FastString* JB_FS__Use(JB_Object* Other);



// JB_FileComparer


// JB_FixedDict


// JB_FlowControl
void JB_Flow_AddByte(FlowControl* Self, byte Value);

bool JB_Flow_Cond(FlowControl* Self, byte Value);

FlowControl* JB_Flow_Constructor(FlowControl* Self);

void JB_Flow_Destructor(FlowControl* Self);

void JB_Flow_Fail(FlowControl* Self, JB_String* Found, JB_String* Expected, JB_String* InputName);

void JB_Flow_Flush(FlowControl* Self);

void JB_Flow_Init(FlowControl* Self, JB_String* Path, JB_String* DateStr);

bool JB_Flow_LoadPath(FlowControl* Self, JB_String* Path, bool IsPrev);

FlowControlStopper JB_Flow__FlowAllow(JB_String* Name, uint64 StartCode);

int JB_Flow__Init_();

int JB_Flow__InitCode_();

bool JB_Flow__InputStrings(Array* Lines, JB_String* Name);

void JB_Flow__Input(JB_String* Data, JB_String* Name);

void JB_Flow__Stop();

bool JB_Flow__Cond(bool Value);



// JB_HuffByteCoder


// JB_Instruction
void SC_Instruction_Const(Instruction* Self);

Instruction* SC_Instruction_Constructor(Instruction* Self, JB_String* FormName, JB_String* Name, int Pos);

void SC_Instruction_Destructor(Instruction* Self);

bool SC_Instruction_IsSetConst(Instruction* Self);

JB_String* SC_Instruction_Render(Instruction* Self, FastString* Fs_in);

void SC_Instruction__Add(JB_String* FormName, JB_String* Name, int Pos);

int SC_Instruction__Init_();

int SC_Instruction__InitCode_();

void SC_Instruction__InstructionInit();

Instruction* SC_Instruction__SyntaxAccessWithMsg(Message* M);

Instruction* SC_Instruction__SyntaxAccessWithInt(int Pos);



// JB_LeakTester
LeakTester* JB_Lk_Constructor(LeakTester* Self, JB_String* Name);

void JB_Lk_Destructor(LeakTester* Self);

void JB_Lk_FinalTest(LeakTester* Self);

void JB_Lk_Test2(LeakTester* Self);



// JB_Macro
Macro* SC_Macro_clean(Macro* Self);

Macro* JB_Macro_ConstructorStr(Macro* Self, JB_String* S);

Macro* JB_Macro_ConstructorMsg(Macro* Self, Message* S);

void JB_Macro_Destructor(Macro* Self);

Message* JB_Macro_Run(Macro* Self, Array* Prms);

Message* JB_Macro_CallFast(Macro* Self, Message* Prm1, Message* Prm2);

Message* JB_Macro_Source(Macro* Self);

int JB_Macro__Init_();

int JB_Macro__InitCode_();



// JB_Memory
MWrap* JB_Mrap_ConstructorPtr(MWrap* Self, int ItemCount, int ItemSize, byte* Ptr, byte DeathAction);

void JB_Mrap_Destructor(MWrap* Self);

byte* JB_Mrap_Ptr(MWrap* Self);

bool JB_Mrap_SetCap(MWrap* Self, int Value);

Array* JB_Mrap__CollectLeaks_(JB_Object* Self);

int JB_Mrap__Init_();

int JB_Mrap__InitCode_();

MWrap* JB_Mrap__Object(int Count, int ItemSize);

void jbl(JB_Object* Self);

byte* JB_Mrap__Zalloc(int N);



// JB_MemoryLayer


// JB_NilTest
NilTest* SC_NilTest_Constructor(NilTest* Self);

void SC_NilTest_Destructor(NilTest* Self);

NilTest* SC_NilTest_Exists3(NilTest* Self, NilTest* P);

NilTest* SC_NilTest_Exists4(NilTest* Self);

NilTest* SC_NilTest_Exists5(NilTest* Self);

NilTest* SC_NilTest_Exists7(NilTest* Self);

int SC_NilTest__Init_();

int SC_NilTest__InitCode_();



// JB_ProcessOwner
bool JB_PID_IsRunning(ProcessOwner* Self);



// JB_SCImport
bool SC_Imp_CanBan(SCImport* Self, SCFile* Scf);

SCImport* SC_Imp_Constructor(SCImport* Self, JB_File* F, bool Builtin);

void SC_Imp_Destructor(SCImport* Self);

SCFile* SC_Imp_ImportDir(SCImport* Self, JB_File* F);

void SC_Imp_ImportMsg(SCImport* Self, Message* J);

SCFile* SC_Imp_ImportSpd(SCImport* Self, JB_File* C);

void SC_Imp_IncludeCHeaders(SCImport* Self, JB_File* F, Array* Output);

void SC_Imp_IndexConf(SCImport* Self, Message* Conf);

void SC_Imp_IndexLinkage(SCImport* Self, Message* Link, SCFile* Scf);

void SC_Imp_IndexTargets(SCImport* Self, Message* Tar);

void SC_Imp_LoadBanned(SCImport* Self, Message* List);

void SC_Imp_LoadConf(SCImport* Self, SCFile* Scf);

void SC_Imp_PrepareAll(SCImport* Self);

void SC_Imp_ReloadImports(SCImport* Self, SCFile* Index);

JB_String* SC_Imp_Render(SCImport* Self, FastString* Fs_in);

void SC_Imp_Use(SCImport* Self);

void SC_Imp__ExportShaders();

SCImport* SC_Imp__FindImport(JB_String* S);

JB_File* SC_Imp__FindInputFolder(JB_File* F);

SCImport* SC_Imp__ImportPath(JB_String* Path, JB_File* F, int ImportDepth, bool Builtin);

int SC_Imp__Init_();

int SC_Imp__InitCode_();

bool SC_Imp__IsInputName(JB_String* Name);

void SC_Imp__NoProj();



// JB_SCNodeRenamer
void SC_NR_Collect(SCNodeRenamer* Self, Message* Msg, JB_String* Name, Message* After);

void SC_NR_CollectDclThg(SCNodeRenamer* Self, Message* DclThg);

void SC_NR_CollectSelfs(SCNodeRenamer* Self, Message* Root);

SCNodeRenamer* SC_NR_Constructor(SCNodeRenamer* Self);

void SC_NR_Destructor(SCNodeRenamer* Self);

void SC_NR_Rename(SCNodeRenamer* Self, Message* Name);

void SC_NR_Uniqueify(SCNodeRenamer* Self, SCNode* P);



// JB_SCObject
Message* SC_SCObject_AnySource(SCObject* Self);

int SC_SCObject_Auto_Type(SCObject* Self);

int SC_SCObject_AutoCompleteType(SCObject* Self);

JB_String* SC_SCObject_BaseIcon(SCObject* Self);

JB_String* SC_SCObject_CallFromName(SCObject* Self);

JB_String* SC_SCObject_CanAuto(SCObject* Self, JB_String* Search);

JB_String* SC_SCObject_CanAutoSub(SCObject* Self, JB_String* Search);

SCObject* SC_SCObject_Constructor(SCObject* Self);

void SC_SCObject_Destructor(SCObject* Self);

SCFunction* SC_SCObject_Disambiguate(SCObject* Self, Message* Src);

JB_String* SC_SCObject_Display(SCObject* Self, bool Exact);

SCFile* SC_SCObject_File(SCObject* Self);

bool SC_SCObject_IsVisible(SCObject* Self);

void SC_SCObject_IsVisibleSet(SCObject* Self, bool Value);

SCObject* SC_SCObject_NextDisplay(SCObject* Self, bool Exact);

void SC_SCObject_Fail(SCObject* Self, JB_String* Error);

bool SC_SCObject_SyntaxIs(SCObject* Self, SCNodeInfo I);

void SC_SCObject_SyntaxIsSet(SCObject* Self, SCNodeInfo I, bool Value);



// JB_SCOperator
JB_String* SC_Opp_CaseAwareStr(SCOperator* Self);

SCOperator* SC_Opp_Constructor(SCOperator* Self, JB_String* Name, fn_OpASM ASM, OpMode Mode);

void SC_Opp_Destructor(SCOperator* Self);

void SC_Opp_InitComp(SCOperator* Self, JB_String* Name_);

bool SC_Opp_IsCompSet(SCOperator* Self);

void SC_Opp_SetFuncNameSet(SCOperator* Self, JB_String* S);

JB_String* SC_Opp_SimpleName(SCOperator* Self);

bool SC_Opp_SyntaxEquals(SCOperator* Self, JB_String* S, bool Aware);

OpMode SC_Opp_SyntaxIs(SCOperator* Self, OpMode X);

void SC_Opp__AddAssign();

void SC_Opp__AddBit(JB_String* S, JB_String* FuncName, fn_OpASM ASM, ASMMath Code, OpMode Mode);

void SC_Opp__AddComp(JB_String* S, fn_OpASM ASM, OpMode Mode);

SCOperator* SC_Opp__AddCustom(JB_String* S);

void SC_Opp__AddMath(JB_String* S, JB_String* FuncName, fn_OpASM ASM, ASMMath Code, OpMode Mode);

void SC_Opp__BuildOrder();

void SC_Opp__Init();

int SC_Opp__Init_();

int SC_Opp__InitCode_();

SCOperator* SC_Opp__Lookup(Message* Opch);

void SC_Opp__OppositeComp(JB_String* A, JB_String* B);



// JB_SCParamArray
void SC_PA_AddParam(SCParamArray* Self, Message* Item);

void SC_PA_addsub(SCParamArray* Self, Message* M);

bool SC_PA_AddTestedParam(SCParamArray* Self, Message* Item, SCNode* Name_space);

SCFunction* SC_PA_ArgsMatchError(SCParamArray* Self, int TypeCast, SCFunction* F, SCFunction* R);

SCParamArray* SC_PA_Constructor(SCParamArray* Self, Message* Exp);

Array* SC_PA_CopyArgs(SCParamArray* Self);

SCNode* SC_PA_DetectDotSuper(SCParamArray* Self, SCNode* Curr, SCNode* Arg_space);

int SC_PA_IgnoreSelfContain(SCParamArray* Self);

bool SC_PA_IsModule(SCParamArray* Self);

bool SC_PA_IsSelfCon(SCParamArray* Self);

int SC_PA_MacroSize(SCParamArray* Self);

bool SC_PA_MadeError(SCParamArray* Self);

JB_String* SC_PA_ModuleName(SCParamArray* Self);

bool SC_PA_PreReadTypes(SCParamArray* Self, SCNode* Name_Space, Message* P, Message* Side);

JB_String* SC_PA_Render(SCParamArray* Self, FastString* Fs_in);

JB_String* SC_PA_RenderKind(SCParamArray* Self);

void SC_PA_SideSet(SCParamArray* Self, Message* Value);

Message* SC_PA_SyntaxAccess(SCParamArray* Self, int I);



// JB_Saveable
bool JB_Sav_IsSaveMarked(Saveable* Self);

void JB_Sav_LoadProperties(Saveable* Self, ObjectLoader* Loader);

void JB_Sav_SaveCollect(Saveable* Self, ObjectSaver* Saver);

bool JB_Sav_SaveMark(Saveable* Self);

SaverClassInfo* JB_Sav_SaverInfo(Saveable* Self);

void JB_Sav_SaveToFile(Saveable* Self, JB_File* F);

JB_String* JB_Sav_SaveTo(Saveable* Self, FastString* Fs_in);

void JB_Sav_SaveUnMark(Saveable* Self);

void JB_Sav_SaveWrite(Saveable* Self, ObjectSaver* Saver);



// JB_Selector
Selector* JB_Sel_Constructor(Selector* Self, Selector* Next, Selector** Place, JB_String* Name);

void JB_Sel_Destructor(Selector* Self);

void JB_Sel_GiveIDs(Selector* Self);



// JB_String
JB_String* JB_Str_AddExt(JB_String* Self, JB_String* Ext);

JB_String* JB_Str_AfterByte(JB_String* Self, byte B, int Last);

JB_String* JB_Str_ArgName(JB_String* Self);

JB_String* SC_Str_ArgsMatchError(JB_String* Self, bool TypeCast);

JB_String* JB_Str_ArgValue(JB_String* Self);

JB_String* SC_Str_ASMNormalise(JB_String* Self);

JB_String* JB_Str_BackToApp(JB_String* Self);

JB_String* JB_Str_Before(JB_String* Self, JB_String* S);

JB_String* JB_Str_BeforeLastByte(JB_String* Self, byte B, int Fudge);

Array* JB_Str_ByteSplit(JB_String* Self);

CharSet* JB_Str_CharSetWithBool(JB_String* Self, bool Range);

JB_String* JB_Str_Child(JB_String* Self, JB_String* Cname);

Array* JB_Str_Components(JB_String* Self);

JB_String* JB_Str_Compress(JB_String* Self, int Strength, CompressionStats* St);

void JB_Str_CompressInto(JB_String* Self, JB_Object* Fs, int Strength, CompressionStats* St);

bool JB_Str_CompressTest(JB_String* Self, bool Report, int Which);

bool JB_Str_CompressTestSub(JB_String* Self, int Strength, bool Report);

JB_String* SC_Str_ContainerName(JB_String* Self, JB_String* Ext);

ErrorInt JB_Str_CopyFileTo(JB_String* Self, JB_String* Dest, bool AttrOnly);

int JB_Str_Count(JB_String* Self, byte B);

ErrorInt2 SC_Str_DebugExecute(JB_String* Self, Array* Args, FastString* Out, FastString* Errs);

JB_String* JB_Str_Decompress(JB_String* Self, int Lim, CompressionStats* St);

Dictionary* JB_Str_Dict(JB_String* Self, byte Sep);

JB_String* JB_Str_Digest(JB_String* Self);

bool JB_Str_EndsWith(JB_String* Self, JB_String* S, bool Aware);

JB_String* JB_Str_Escape(JB_String* Self);

JB_String* JB_Str_EscapeChr(JB_String* Self);

bool JB_Str_EscapeTest(JB_String* Self);

JB_String* JB_Str_Ext(JB_String* Self);

JB_File* JB_Str_AsFile(JB_String* Self);

JB_File* JB_Str_ChildFile(JB_String* Self, JB_String* Ch);

bool JB_Str_FileExists(JB_String* Self);

int64 JB_Str_FileSize(JB_String* Self);

JB_File* JB_Str_FileThatExists(JB_String* Self, JB_String* Operation);

Ind JB_Str_FindByte(JB_String* Self, byte Find, int Start, int After);

Ind JB_Str_Find(JB_String* Self, CharSet* Cs, int Start, int After);

Ind JB_Str_FindSlash(JB_String* Self, int From);

int JB_Str_FindTrailingSlashes(JB_String* Self);

double JB_Str_Float(JB_String* Self);

int64 JB_Str_Int(JB_String* Self);

JB_String* SC_Str_InterfaceToBehaviour(JB_String* Self);

JB_String* SC_Str_internal(JB_String* Self);

Ind JB_Str_InWhite(JB_String* Self, int Start, int After);

bool SC_Str_isCLike(JB_String* Self);

bool JB_Str_IsCompressed(JB_String* Self);

int JB_Str_IsHexLike(JB_String* Self, int N);

bool JB_Str_IsInt(JB_String* Self);

bool JB_Str_IsIntFrom(JB_String* Self, int I);

Ind JB_Str_IsJbin(JB_String* Self);

bool JB_Str_IsLower(JB_String* Self);

bool SC_Str_Isnull(JB_String* Self);

bool JB_Str_IsOK(JB_String* Self);

bool SC_Str_IsOKForImport(JB_String* Self);

bool SC_Str_IsSpeedieSrc(JB_String* Self);

bool JB_Str_IsStatementName(JB_String* Self);

int SC_Str_IsSwizzle(JB_String* Self, int Width);

bool SC_Str_IsZero(JB_String* Self);

Ind JB_Str_JBFind(JB_String* Self, byte Find, int Off, int After);

byte JB_Str_Last(JB_String* Self, int Minus);

int JB_Str_LineCount(JB_String* Self);

JB_File* SC_Str_MakeAndGoInto(JB_String* Self);

ErrorInt JB_Str_MakeEntirePath(JB_String* Self, bool Last);

JB_String* JB_Str_Moat(JB_String* Self);

Message* JB_Str_Msg(JB_String* Self);

JB_String* JB_Str_Name(JB_String* Self);

JB_String* SC_Str_NicerClassName(JB_String* Self);

bool JB_Str_ContainsString(JB_String* Self, JB_String* S);

bool JB_Str_ContainsByte(JB_String* Self, byte B);

Array* JB_Str_OperatorDivide(JB_String* Self, byte Sep);

bool JB_Str_OperatorEndsWith(JB_String* Self, JB_String* S);

bool JB_Str_OperatorIsa(JB_String* Self, JB_String* S);

int JB_Str_OperatorMinus(JB_String* Self, JB_String* S);

JB_String* JB_Str_MulBool(JB_String* Self, bool B);

JB_String* JB_Str_OperatorMul(JB_String* Self, int N);

JB_String* JB_Str_PlusByte(JB_String* Self, byte B);

JB_String* JB_Str_OperatorPlusWithCstring(JB_String* Self, _cstring C);

bool JB_Str_OperatorStarts(JB_String* Self, JB_String* S);

bool SC_Str_OptionBool(JB_String* Self);

int SC_Str_OptionInt(JB_String* Self);

FastString* JB_Str_Out(JB_String* Self, bool Clear);

Ind JB_Str_OutByteWithByteIntInt(JB_String* Self, byte Find, int Start, int After);

Ind JB_Str_OutCharSet(JB_String* Self, CharSet* Cs, int Start, int After);

Ind JB_Str_OutWhite(JB_String* Self, int Start, int After);

JB_String* JB_Str_Parent(JB_String* Self);

Message* JB_Str_Parse(JB_String* Self, Syntax Owner, bool AllowDecomp);

Message* SC_Str_ParseClean(JB_String* Self);

Message* SC_Str_ParseCleanWipe(JB_String* Self);

Message* JB_Str_ParseJbin(JB_String* Self, int64 Max);

Message* JB_Str_ParseSub(JB_String* Self, Syntax Owner, bool AllowDecomp);

Message* JB_Str_ParseWithError(JB_String* Self, JB_Error** Rec);

JB_String* JB_Str_PathDir(JB_String* Self);

JB_String* JB_Str_Preview(JB_String* Self, int N);

void JB_Str_PrintlineColor(JB_String* Self, JB_String* Color);

JB_String* JB_Str_ReadFile(JB_String* Self, int Lim, bool AllowMissing);

JB_String* JB_Str_ReplacePathComponent(JB_String* Self, int Num, JB_String* With);

JB_String* SC_Str_ResolveSpd(JB_String* Self);

void SC_Str_Safe(JB_String* Self, FastString* Fs, bool Local);

JB_String* SC_Str_ScriptContainer(JB_String* Self, JB_String* Container);

JB_String* SC_Str_ScriptLocation(JB_String* Self, JB_String* Container);

JB_String* JB_Str_Sibling(JB_String* Self, JB_String* Name);

ErrorInt2 JB_Str_SilentExecute(JB_String* Self, Array* Args, FastString* Out, FastString* Errs, Date Timeout);

JB_String* SC_Str_SpdScriptName(JB_String* Self);

Array* JB_Str_Split(JB_String* Self, byte Sep);

JB_String* JB_Str_Squeeze(JB_String* Self);

StringReader* JB_Str_Stream(JB_String* Self);

JB_String* JB_Str_SyntaxAccess(JB_String* Self, JB_String* S);

bool JB_Str_SyntaxAppend(JB_String* Self, JB_String* S);

int JB_Str_CompareStr(JB_String* Self, JB_String* Other, bool Aware);

int JB_Str_CompareInt(JB_String* Self, int Other, bool Aware);

bool JB_Str_EqualsInt(JB_String* Self, int Other, bool Aware);

void JB_Str_SyntaxExpect(JB_String* Self);

JB_String* JB_Str_TitleCase(JB_String* Self, FastString* Fs_in);

JB_String* JB_Str_Shorten(JB_String* Self, int N);

JB_String* JB_Str_TrimExtAndPath(JB_String* Self, bool KeepPath);

JB_String* JB_Str_TrimFirst(JB_String* Self, byte B);

int JB_Str_TrimLastSub(JB_String* Self, byte B);

JB_String* JB_Str_TrimSlashes(JB_String* Self, bool Pathfix);

bool SC_Str_UnderScoreAtAnyEnd(JB_String* Self);

JB_String* JB_Str_Unescape(JB_String* Self);

JB_String* SC_Str_UnicodeSafeName(JB_String* Self, FastString* Fs_in);

CharSet* JB_Str_UniCS(JB_String* Self);

int JB_Str_UnPrintable(JB_String* Self);

JB_String* JB_Str_UpperFirst(JB_String* Self);

bool JB_Str_Visible(JB_String* Self);

Array* JB_Str_Words(JB_String* Self);

JB_String* JB_Str_Wrap(JB_String* Self, int MaxWidth, FastString* Fs_in);

int JB_Str_WrapSub(JB_String* Self, int MaxWidth, bool IsInline, int P);

bool JB_Str_WriteSet(JB_String* Self, JB_String* Value);

bool JB_Str_Yes(JB_String* Self, Message* Where);

JB_String* JB_Str__FromPico(PicoMessage M);

bool JB_Str__Sorter(JB_Object* A, JB_Object* B);

JB_StringC* JB_Str__Wrap(_cstring Addr);



// JB_StringFields
StringFields* JB_FI_Constructor(StringFields* Self, JB_String* Source, byte Sep);

void JB_FI_Destructor(StringFields* Self);

JB_String* JB_FI_Field(StringFields* Self, Ind Prev, Ind Curr);

Ind JB_FI_NextSep(StringFields* Self, int Prev);



// JB_StringReader
int JB_SS_Byte(StringReader* Self);

void JB_SS_CompressInto(StringReader* Self, JB_Object* Dest, int Strength, CompressionStats* St);

StringReader* JB_SS_Constructor(StringReader* Self, JB_String* Data);

JB_String* JB_SS_Decompress(StringReader* Self, int Lim, CompressionStats* St, bool Multi);

bool JB_SS_DecompressInto(StringReader* Self, JB_Object* Dest, int Lim, CompressionStats* St);

void JB_SS_Destructor(StringReader* Self);

bool JB_SS_ExpectJbin(StringReader* Self);

bool JB_SS_HasAny(StringReader* Self);

int64 JB_SS_hInt(StringReader* Self);

bool JB_SS_IsCompressed(StringReader* Self);

bool JB_SS_IsJBin(StringReader* Self);

bool JB_SS_NextChunk(StringReader* Self);

Message* JB_SS_NextMsgExpect(StringReader* Self, Message* Parent, Syntax Fn, JB_String* Name);

Message* JB_SS_NextMsg(StringReader* Self);

uint64 JB_SS_NextMsgInfo(StringReader* Self);

bool JB_SS_NoMoreChunks(StringReader* Self);

int JB_SS_NonZeroByte(StringReader* Self);

Message* JB_SS_ParseJbin(StringReader* Self, int64 Remain);

int64 JB_SS_Position(StringReader* Self);

void JB_SS_PositionSet(StringReader* Self, int64 Value);

JB_String* JB_SS_ReadAll(StringReader* Self);

bool JB_SS_ReadChunk(StringReader* Self, JB_File* F);

int JB_SS_Remaining(StringReader* Self);

void JB_SS_Reset(StringReader* Self, JB_String* Data);

JB_String* JB_SS_Str(StringReader* Self, int N, int Skip);

JB_String* JB_SS_StrNoAdvance(StringReader* Self, int N, int Skip);

void JB_SS_SyntaxExpect(StringReader* Self, JB_String* Error);



// JB_SyntaxObj
SyntaxObj* JB_Fn_Constructor(SyntaxObj* Self, FP_fpMsgRender Msg, JB_String* Name, int ID);

void JB_Fn_Destructor(SyntaxObj* Self);

JB_String* JB_Fn_Render(SyntaxObj* Self, FastString* Fs_in);



// JB_TerminalCell
TerminalCell* JB_TerminalCell_ConstructorAuto(TerminalCell* Self, int Color, JB_String* Text);

void JB_TerminalCell_Destructor(TerminalCell* Self);



// JB_TokenHandler


// JB___junktest_6__
DTWrap* SC___junktest_6____AbcVis();



// JB_autoitem
autoitem* SC_autoitem_ConstructorAuto(autoitem* Self, JB_String* Sort, JB_String* Insert, SCObject* Value, JB_String* Display, bool Exact, int Type);

void SC_autoitem_Destructor(autoitem* Self);

bool SC_autoitem_OKBy(autoitem* Self, autoitem* Prev);



// JB_µForm
void SC_xC2xB5Form_AddP(xC2xB5Form* Self, int Size, ASMParam P);

void SC_xC2xB5Form_AddRemainder(xC2xB5Form* Self, int U);

xC2xB5Form* SC_xC2xB5Form_Constructor(xC2xB5Form* Self, JB_String* Data, Message* Tmp);

void SC_xC2xB5Form_Destructor(xC2xB5Form* Self);

void SC_xC2xB5Form_LoadParam(xC2xB5Form* Self, JB_String* Pl, Message* Place);

JB_String* SC_xC2xB5Form_Render(xC2xB5Form* Self, FastString* Fs_in);

ASMParam SC_xC2xB5Form_AccessInt(xC2xB5Form* Self, int I);

int SC_xC2xB5Form__Init_();

int SC_xC2xB5Form__InitCode_();

xC2xB5Form* SC_xC2xB5Form__Needform(JB_String* Form);



// JB_µFunc
ASMFunc* SC_ASMFunc_Constructor(ASMFunc* Self, SCFunction* Fn, FatASM* IR);

void SC_ASMFunc_Destructor(ASMFunc* Self);

MWrap* SC_ASMFunc_Finish(ASMFunc* Self);

JB_String* SC_ASMFunc_Render(ASMFunc* Self, FastString* Fs_in);



// JB_Array
void SC_Array_AddCStr(Array* Self, JB_String* S);

void SC_Array_AppendWords(Array* Self, JB_String* R);

void JB_Array_Clear(Array* Self);

JB_Object* JB_Array_First(Array* Self);

JB_String* JB_Array_join(Array* Self, JB_String* Sep);

JB_Object* JB_Array_Last(Array* Self);

void JB_Array_LoadProperties(Array* Self, ObjectLoader* Loader);

void JB_Array_SaveCollect(Array* Self, ObjectSaver* Saver);

void JB_Array_SaveWrite(Array* Self, ObjectSaver* Saver);

void JB_Array_SyntaxAppend(Array* Self, JB_Object* Item);

int JB_Array_SyntaxCompare(Array* Self, int N, bool Aware);

bool JB_Array_SyntaxEquals(Array* Self, int N, bool Aware);



// JB_Dictionary
JB_Object* JB_Dict_Expect(Dictionary* Self, Message* M);

void JB_Dict_LoadProperties(Dictionary* Self, ObjectLoader* Loader);

JB_Object* JB_Dict_Obj(Dictionary* Self, JB_Object* Prm);

void JB_Dict_ObjSet(Dictionary* Self, JB_Object* Prm, JB_Object* Value);

void JB_Dict_SaveCollect(Dictionary* Self, ObjectSaver* Saver);

void JB_Dict_SaveWrite(Dictionary* Self, ObjectSaver* Saver);

void JB_Dict_SetValue(Dictionary* Self, JB_String* Key, int64 Value);

JB_Object* JB_Dict_Syntax(Dictionary* Self, JB_String* Key);

JB_Object* JB_Dict_JB_Dict_Value(Dictionary* Self, JB_String* Key);

void JB_Dict_SetInt(Dictionary* Self, uint64 Key, JB_Object* Value);

JB_Object* JB_Dict_ValueInt(Dictionary* Self, uint64 Key);

JB_Object* JB_Dict_ValueLower(Dictionary* Self, JB_String* S);

void JB_Dict_ValueLowerSet(Dictionary* Self, JB_String* S, JB_Object* Value);

Dictionary* JB_Dict__Copy(Dictionary* Dict);

Dictionary* JB_Dict__Reverse(Dictionary* Dict);



// JB_FastStringCpp
void SC_FastStringCpp_AppendBehaviour(FastStringCpp* Self, JB_String* Name, SCFunction* Fn, SCClass* Type);

FastStringCpp* SC_FastStringCpp_Constructor(FastStringCpp* Self, JB_String* Name);

void SC_FastStringCpp_Destructor(FastStringCpp* Self);



// JB_File
JB_File* JB_File_Child(JB_File* Self, JB_String* Name);

ErrorInt2 SC_File_CodeSign(JB_File* Self, JB_String* Sign);

bool JB_File_CompareData(JB_File* Self, JB_String* A, JB_String* Error);

bool JB_File_FileCompare(JB_File* Self, JB_File* A, JB_String* Error);

bool JB_File_CompareMsg(JB_File* Self, ErrorInt Code, JB_String* Error);

ErrorInt JB_File_FileCompareSub(JB_File* Self, JB_File* A);

Message* JB_File_Conf(JB_File* Self, int Lim);

ErrorInt JB_File_CopyAll(JB_File* Self, JB_String* Dest, bool AttrOnly);

ErrorInt JB_File_DeleteAll(JB_File* Self);

bool JB_File_DirectoryContains(JB_File* Self, JB_String* Path);

ErrorInt JB_File_LinkToSet(JB_File* Self, JB_String* Value);

Array* JB_File_List(JB_File* Self, bool Invis);

bool JB_File_MustExist(JB_File* Self, JB_String* Operation);

bool JB_File_Opened(JB_File* Self);

bool JB_File_OperatorInside(JB_File* Self, JB_File* F);

bool JB_File_NewerThanFile(JB_File* Self, JB_File* F);

bool JB_File_OperatorIsNewerThan(JB_File* Self, Date F);

JB_File* JB_File_Parent(JB_File* Self);

Message* JB_File_Parse(JB_File* Self, int Lim, bool AllowMissing);

JB_File* JB_File_Sibling(JB_File* Self, JB_String* Name);

bool JB_File_SmartDataSet(JB_File* Self, JB_String* Nieu);

JB_File* JB_File_SyntaxAccess(JB_File* Self, JB_String* Name);

void JB_File_SyntaxAppend(JB_File* Self, JB_String* Data);

void JB_File_Fail(JB_File* Self, JB_String* Error);

bool SC_File_TestBatch(JB_File* Self);

bool SC_File_TestSpeedie(JB_File* Self, JB_String* V);

ErrorInt2 JB_File_Touch(JB_File* Self);

JB_String* JB_File__Applications();

int JB_File__Init_();

int JB_File__InitCode_();

JB_File* JB_File__Logs();

JB_String* JB_File__PreferencesPath();

JB_String* JB_File__Prefs(JB_String* Name);

JB_File* JB_File__PrefsFolder();

JB_String* JB_File__Speedie();



// JB_JBin
jbinLeaver JB_bin_Add(FastString* Self, Syntax Type, JB_String* Name, bool Into);

void SC_bin_Add(FastString* Self, ASMFunc* Fn);

void JB_bin_AddInt(FastString* Self, int64 Name);

jbinLeaver JB_bin_AddMemory(FastString* Self, Syntax Type, uint64 L, bool GoIn, byte* Data);

void JB_bin_CloseSection(FastString* Self, int C);

FastString* JB_bin_Constructor(FastString* Self, Syntax Type, JB_String* Name);

FastString* JB_bin_Constructor0(FastString* Self, int N);

jbinLeaver JB_bin_Enter(FastString* Self, Syntax Type, JB_String* Name);

void JB_bin_Exit(FastString* Self, int Amount);

int JB_bin_OpenSection(FastString* Self);

void JB_bin_Sheb(FastString* Self, JB_String* Name);

jbinLeaver JB_bin_Tmp(FastString* Self, JB_String* Name);



// JB_MaterialsLol
MaterialsLol* SC_MaterialsLol_Constructor(MaterialsLol* Self, Selector* Next, Selector** Place, JB_String* Name1);

void SC_MaterialsLol_Destructor(MaterialsLol* Self);

void SC_MaterialsLol____LoadSel(MaterialsLol** Place, JB_String* Name);

int SC_MaterialsLol__Init_();

int SC_MaterialsLol__InitCode_();



// JB_OutputFile


// JB_Process
JB_String* JB_Sh_Render(ShellStream* Self, FastString* Fs_in);



// JB_SCNamed
SCNamed* SC_Named_Constructor(SCNamed* Self);

void SC_Named_Destructor(SCNamed* Self);

JB_String* SC_Named_Render(SCNamed* Self, FastString* Fs_in);



// JB_SavingTest
SavingTest* SC_SavingTest_Constructor(SavingTest* Self, int N);

void SC_SavingTest_Destructor(SavingTest* Self);

void SC_SavingTest_LoadProperties(SavingTest* Self, ObjectLoader* Loader);

void SC_SavingTest_SaveWrite(SavingTest* Self, ObjectSaver* Saver);

bool SC_SavingTest__IsEqual(JB_Object* A, JB_Object* B);



// JB_StringShared


// JB_StringThatWasReadSafely


// JB_StringZeroTerminated
_cstring JB_Str_CString(JB_StringC* Self);



// JB_list
void JB_Tree_AppendAfter(JB_List* Self, JB_List* Item, JB_List* After);

void JB_Tree_AppendBefore(JB_List* Self, JB_List* Item, JB_List* Before);

int JB_Tree_BackDist(JB_List* Self, JB_List* B);

void JB_Tree_Clear(JB_List* Self);

int JB_Tree_Dist(JB_List* Self, JB_List* R);

JB_List* JB_Tree_FlatLast(JB_List* Self);

int JB_Tree_FwdDist(JB_List* Self, JB_List* F);

bool JB_Tree_HasOneChild(JB_List* Self);

bool JB_Tree_IsFirst(JB_List* Self);

bool JB_Tree_IsLast(JB_List* Self);

bool JB_Tree_IsOnlyChild(JB_List* Self);

void jdb2(JB_List* Self);

void jdb3(JB_List* Self);

bool JB_Tree_OperatorLessOrEqual(JB_List* Self, int N);

JB_List* JB_Tree_Pop(JB_List* Self);

void JB_Tree_Remove(JB_List* Self);

void JB_Tree_RemoveAfter(JB_List* Self);

JB_String* JB_List_Render(JB_List* Self, FastString* Fs_in);

JB_List* JB_Tree_Second(JB_List* Self);

JB_List* JB_Tree_Get(JB_List* Self, int N);

void JB_Tree_SyntaxAppend(JB_List* Self, JB_List* Last);

bool JB_Tree_SyntaxEquals(JB_List* Self, int N, bool Aware);

void JB_Tree_TakeAllFrom(JB_List* Self, JB_List* Src);

JB_List* JB_Tree_Upward(JB_List* Self, int N);

JB_List* JB_Tree_WrapWith(JB_List* Self, JB_List* W);



// JB_µFunc1
int64 SC_ASMFunc2_RunArgs(MWrap* Self, ivec4* Args, int ArgCount);



// JB_DictionaryLower


// JB_ExistingFile


// JB_HuffNode


// JB_JeeboxFile


// JB_Message
void JB_Msg_Acc__(Message* Self, FastString* Fs);

Message* JB_Msg_AccessAdd(Message* Self, JB_String* Key);

void JB_Msg_CantFind(Message* Self, Syntax S, JB_String* Name, Message* Found);

bool SC_Msg_ACInIsa(Message* Self);

void SC_Msg_AddBefore(Message* Self, Message* Before, Message* NewItem);

void JB_Msg_Adj__(Message* Self, FastString* Fs);

int JB_Msg_After(Message* Self);

void JB_Msg_AfterSet(Message* Self, int Value);

bool SC_Msg_AllowedMoveToInit(Message* Self);

Message* JB_Msg_Ancestor(Message* Self, Syntax F);

int SC_Msg_AndOrExpansionTest(Message* Self);

JB_String* SC_Msg_APICppProject(Message* Self);

void SC_Msg_AppendAllInto(Message* Self, Message* Dest);

void JB_Msg_AppendMacro(Message* Self, Macro* M, Array* Prms);

void JB_Msg_ARel__(Message* Self, FastString* Fs);

Message* JB_Msg_Arg(Message* Self);

void JB_Msg_Arg__(Message* Self, FastString* Fs);

JB_String* JB_Msg_ArgName(Message* Self);

JB_String* JB_Msg_ArgValue(Message* Self);

void JB_Msg_Arr__(Message* Self, FastString* Fs);

SCArg* SC_Msg_AsArg(Message* Self);

SCDecl* SC_Msg_AsDecl(Message* Self);

SCFunction* SC_Msg_AsFunc(Message* Self);

void JB_Msg_Ask__(Message* Self, FastString* Fs);

uint64 SC_Msg_ASMConst(Message* Self);

ASMtmp SC_Msg_ASMType(Message* Self);

void SC_Msg_ASMTypeSet(Message* Self, ASMtmp Value);

void SC_Msg_AssignsFix(Message* Self, SCFunction* F);

int SC_Msg_Autocomplete_State(Message* Self);

SCFunction* SC_Msg_AutoMsgFunc(Message* Self);

SCFunction* SC_Msg_AutoMsgFuncFn(Message* Self);

void SC_Msg_AvoidSafeDecr(Message* Self);

void JB_Msg_Back__(Message* Self, FastString* Fs);

void JB_Msg_Badj__(Message* Self, FastString* Fs);

void JB_Msg_BecomeStr(Message* Self, Syntax Fn, JB_String* Name);

void JB_Msg_BecomeNum(Message* Self, int64 Num);

void JB_Msg_BecomeMsg(Message* Self, Message* Src);

void SC_Msg_Become(Message* Self, SCOperator* Op);

void SC_Msg_BecomeAppend(Message* Self, JB_String* S);

void JB_Msg_BecomeMacro(Message* Self, Macro* M, Array* Prms);

void SC_Msg_BecomeNil(Message* Self);

void SC_Msg_BecomeSetRel(Message* Self);

void JB_Msg_Bin__(Message* Self, FastString* Fs);

void JB_Msg_binn__(Message* Self, FastString* Fs);

void JB_Msg_BinnRender(Message* Self, FastString* Fs, JB_String* Sepa, JB_String* Sepb);

ErrorSeverity SC_Msg_Blind(Message* Self);

SCBlockage SC_Msg_Blocks(Message* Self);

void SC_Msg_BlocksSet(Message* Self, int Value);

void JB_Msg_Bra__(Message* Self, FastString* Fs);

SCDecl* SC_Msg_BraDeclfind(Message* Self);

void JB_Msg_BRel__(Message* Self, FastString* Fs);

bool SC_Msg_BuildRunTask(Message* Self, Message* Fields, int Level);

void SC_Msg_BuildTask(Message* Self, Message* Fields, Message* Root, int Level);

void SC_Msg_BunchFix(Message* Self);

Message* SC_Msg_BunchFixPrepare(Message* Self);

void SC_Msg_BunchFixSub(Message* Self, Message* Subject, Message* Stuff);

void SC_Msg_BunchlessFix(Message* Self);

bool SC_Msg_CanGetAddress(Message* Self, SCNode* Name_space);

Message* SC_Msg_CastedParent(Message* Self);

int SC_Msg_CastFPToVoidPtr(Message* Self);

int SC_Msg_CastToBool(Message* Self, SCNode* Name_space);

int SC_Msg_CastToClass(Message* Self, SCClass* Type, SCNode* Name_space);

int SC_Msg_CastToType(Message* Self, JB_String* TypeName, SCClass* Type, SCNode* Name_space, int Loss);

Message* SC_Msg_CausesUnReachable(Message* Self, Message* Arg, Message* Dcl, Message* LastPlace);

void JB_Msg_Char__(Message* Self, FastString* Fs);

void SC_Msg_CheckContinuesAndExits(Message* Self);

void SC_Msg_CheckNotInStateExpr(Message* Self, Message* Top);

void SC_Msg_CheckSuperDotSave(Message* Self, JB_String* Name, bool ShouldBe);

void SC_Msg_Clean(Message* Self, bool Erl);

int JB_Msg_CleanIndent(Message* Self);

Message* SC_Msg_CmdImprove(Message* Self);

void JB_Msg_Cnj__(Message* Self, FastString* Fs);

bool SC_Msg_CollectAGlobalDecl(Message* Self, SCNode* Scarg);

Message* SC_Msg_CollectDclName(Message* Self);

SCDecl* SC_Msg_CollectDecl(Message* Self, SCNode* P, SCNode* Recv, int Mode, SCClass* Cls, SCFunction* FuncPrmz);

void SC_Msg_CollectFromBody(Message* Self, SCNode* Scarg);

JB_String* SC_Msg_CollectFuncTableName(Message* Self);

Message* SC_Msg_CollectionPlace(Message* Self);

bool SC_Msg_CollectOneParam(Message* Self, SCFunction* Func, SCNode* Recv, SCClass* Cls);

JB_String* SC_Msg_CollectUsage(Message* Self);

Message* JB_Msg_ConfArg(Message* Self);

void SC_Msg_ConfTake(Message* Self, Message* Dest, JB_String* Name);

Message* SC_Msg_ConstantExpandSub(Message* Self);

bool SC_Msg_ConstIntValue(Message* Self, SCNode* Name_space, int64* V);

bool SC_Msg_ConstIntValueSub(Message* Self, SCNode* Name_space, int64* V);

Message* JB_Msg_ConstructorCopy(Message* Self, Message* Other);

Message* JB_Msg_ConstructorEmpty(Message* Self);

Message* JB_Msg_ConstructorNormal(Message* Self, Syntax Func, JB_String* Name);

Message* JB_Msg_ConstructorRange(Message* Self, Message* Parent, Syntax Func, int BytePos, JB_String* Name, int RangeLength);

void SC_Msg_ConstructorAddNil(Message* Self, bool Isdot);

bool JB_Msg_ContainsInd(Message* Self, Ind P, bool AllowJustAfter);

Message* JB_Msg_Copy(Message* Self, Message* Pos_msg);

void SC_Msg_CopyAllAfter(Message* Self, Message* After, Message* Copylayer);

void SC_Msg_CopyAllAfterBefore(Message* Self, Message* Before, Message* Copylayer);

void SC_Msg_CopyAllAfterInto(Message* Self, Message* Into, Message* Copylayer);

void SC_Msg_CopyAllBefore(Message* Self, Message* Before, Message* Copylayer);

void SC_Msg_CopyAllBeforeInto(Message* Self, Message* Into, Message* Copylayer);

void SC_Msg_CopyAllInto(Message* Self, Message* J, bool Wipe);

JB_String* JB_Msg_CopyID(Message* Self);

Message* JB_Msg_CopySub(Message* Self, Message* P);

JB_String* SC_Msg_Cpp_Wrapper(Message* Self);

Message* SC_Msg_CreateNil(Message* Self);

Message* SC_Msg_CreateOwnBlock(Message* Self);

Message* SC_Msg_CutifyCopy(Message* Self);

Message* SC_Msg_DclExp(Message* Self);

void JB_Msg_Decl__(Message* Self, FastString* Fs);

Message* SC_Msg_DeclName(Message* Self);

bool JB_Msg_DeepEquals(Message* Self, Message* B, bool Aware);

Message* SC_Msg_Deepest(Message* Self, Syntax Tmp, JB_String* Name);

int SC_Msg_DeprecatedClassOption(Message* Self, JB_String* Name, JB_String* Kind);

void JB_Msg_Destructor(Message* Self);

Dictionary* JB_Msg_Dict(Message* Self, bool DoCount, bool DoLower);

bool SC_Msg_DoesAnything(Message* Self);

void JB_Msg_Dot__(Message* Self, FastString* Fs);

SCDecl* SC_Msg_DotMustBeProperty(Message* Self);

SCObject* SC_Msg_DotSpace(Message* Self, SCNode* Name_space);

DotUseType SC_Msg_DotType(Message* Self);

void JB_Msg_Dummy(Message* Self, FastString* Fs);

void SC_Msg_ElseNeverFires(Message* Self);

void JB_Msg_Emb__(Message* Self, FastString* Fs);

void JB_Msg_ERel__(Message* Self, FastString* Fs);

Message* SC_Msg_ExpandToBool(Message* Self, SCNode* Name_space);

bool JB_Msg_Expect(Message* Self, Syntax Type, JB_String* Name);

bool SC_Msg_ExpectClass(Message* Self, SCDecl* Slf, SCClass* Cls);

void SC_Msg_ExpectEmpty(Message* Self);

bool SC_Msg_ExpectInt(Message* Self, SCDecl* Type);

bool JB_Msg_ExpectLast(Message* Self, JB_String* Err);

bool SC_Msg_ExpectMatch(Message* Self, SCNode* Name_space, SCClass* With);

Message* SC_Msg_ExpectParamsTransform(Message* Self, int P, Message* Errnode, JB_String* Type);

bool JB_Msg_ExpectString(Message* Self);

SCFunction* SC_Msg_ExpFunc(Message* Self);

void JB_Msg_Export(Message* Self, FastString* Fs);

Message* SC_Msg_FailOrCopy(Message* Self, Message* P);

Message* SC_Msg_FalsifyNil(Message* Self);

SCDecl* SC_Msg_FastDecl(Message* Self);

SCFile* SC_Msg_File(Message* Self);

void JB_Msg_File__(Message* Self, FastString* Fs);

JB_String* SC_Msg_FileLocation(Message* Self);

int SC_Msg_FileNum(Message* Self);

JB_String* JB_Msg_FilePath(Message* Self);

Message* JB_Msg_FindSyx(Message* Self, Syntax S);

Message* JB_Msg_FindSyxName(Message* Self, Syntax S, JB_String* Name, bool Err);

Message* JB_Msg_FindName(Message* Self, JB_String* Name);

Array* JB_Msg_FindAll(Message* Self, Syntax Fn, JB_String* Name);

JB_String* SC_Msg_FindAndRemove(Message* Self, JB_String* Name, bool NothingOK, bool IsClass);

Message* SC_Msg_FindAndRemove2(Message* Self, Message* Place, bool NothingOK, bool IsClass);

Message* SC_Msg_FindAndRemoveSub(Message* Self, JB_String* Name, bool NothingOK, bool IsClass);

Message* SC_Msg_FindDestructor(Message* Self);

Message* JB_Msg_FindNested(Message* Self, Syntax Fn, JB_String* Name, bool Err);

Message* JB_Msg_FindNotInserted(Message* Self);

Message* SC_Msg_FindPos(Message* Self, int Fr, int Len);

Message* SC_Msg_FindPosSub(Message* Self, int Fr, int Len, bool Exact);

Message* SC_Msg_FindRef(Message* Self, SCFunction* Fn, JB_String* Name);

Message* SC_Msg_FindShader(Message* Self, JB_String* TypeName);

Message* JB_Msg_FindTightest(Message* Self, int Pos, bool Named, bool SamePosition);

JB_String* JB_Msg_FirstName(Message* Self);

void SC_Msg_FixElseif(Message* Self);

void SC_Msg_FixErl(Message* Self);

void SC_Msg_FixMultiArr(Message* Self);

double JB_Msg_Float(Message* Self);

float JB_Msg_Float32(Message* Self);

void JB_Msg_FSListArg(Message* Self, FastString* Fs, bool AddLine);

void JB_Msg_FSListSep(Message* Self, FastString* Fs, JB_String* Sep);

Message* SC_Msg_FullAfter(Message* Self);

void JB_Msg_Func__(Message* Self, FastString* Fs);

JB_String* JB_Msg_FuncName(Message* Self);

int SC_Msg_FuncPos(Message* Self, SCFunction* Fn);

void SC_Msg_FuncWrap(Message* Self, Message* Fnc);

int SC_Msg_GetAddressOf(Message* Self, SCDecl* Type, bool WasCArray);

Message* SC_Msg_GetASMFunc(Message* Self);

Message* SC_Msg_GetDclName(Message* Self, bool IsConstructor);

SCFunction* SC_Msg_GetFunctionPointer(Message* Self);

Message* SC_Msg_GetMarker(Message* Self, JB_String* S);

Message* SC_Msg_GetTypeLimiter(Message* Self);

Message* JB_Msg_GiveArg(Message* Self);

Message* JB_Msg_GoIntoInvisArg(Message* Self, Message* Tmp, int Pos);

Message* SC_Msg_HasOwnBlock(Message* Self);

bool JB_Msg_HasPosition(Message* Self);

bool SC_Msg_HasSelfAsFirst(Message* Self);

void SC_Msg_HateUnusedFuncs(Message* Self);

SCFunction* SC_Msg_IdentifyFunc(Message* Self);

Message* SC_Msg_InBuiltSizeOf(Message* Self, SCNode* Name_space, SCDecl* Sulf, Message* Sulf_exp);

int JB_Msg_IndentScore(Message* Self);

bool JB_Msg_InInvisArg(Message* Self);

bool SC_Msg_InitExpand(Message* Self);

bool SC_Msg_InitRootDecl(Message* Self, Message* Before, SCNode* Name_space);

void SC_Msg_InsertAfter(Message* Self, Message* Ins, Message* After);

void SC_Msg_InsertBefore(Message* Self, Message* J, Message* Ch);

void SC_Msg_InsertMainArgs(Message* Self, Message* Prms);

SCFunction* SC_Msg_InsideFunc(Message* Self);

int64 JB_Msg_IntRange(Message* Self, int StrStart, int64 Low, int64 High);

int64 JB_Msg_Int(Message* Self, int StrStart);

NameAndMsg SC_Msg_IntoVariable(Message* Self, SCNode* Name_space);

MaybeBool SC_Msg_IsAlwaysBool(Message* Self);

bool SC_Msg_IsAlwaysFalse(Message* Self);

bool SC_Msg_IsAssignable(Message* Self);

bool SC_Msg_IsBehaviour(Message* Self);

bool SC_Msg_IsClassType(Message* Self);

bool SC_Msg_IsFirstOfSetRel(Message* Self);

Message* SC_Msg_IsInDeclInBlock(Message* Self);

bool SC_Msg_IsInt(Message* Self);

bool SC_Msg_IsLinkageType(Message* Self);

bool SC_Msg_IsModuleType(Message* Self);

bool SC_Msg_IsNilOrZero(Message* Self);

int SC_Msg_IsNowNil(Message* Self);

SCFunction* SC_Msg_IsParentConCall(Message* Self);

bool SC_Msg_IsProperty(Message* Self);

bool SC_Msg_IsReffer(Message* Self);

bool SC_Msg_IsReturnOrRejoin(Message* Self);

Message* SC_Msg_IsSetIntoPlace(Message* Self);

Message* SC_Msg_IsSetIntoVar(Message* Self);

bool SC_Msg_IsSetRel(Message* Self);

bool SC_Msg_IsSettablePlace(Message* Self);

bool SC_Msg_IsSmallInt(Message* Self, SCDecl* T);

bool SC_Msg_IsStatementExpr(Message* Self);

bool JB_Msg_IsString(Message* Self);

bool JB_Msg_IsTypeOfDecl(Message* Self);

bool SC_Msg_IsVarAltered(Message* Self, JB_String* Name);

bool SC_Msg_IsVarUseableInLoop(Message* Self, JB_String* Name);

bool SC_Msg_IsZero(Message* Self);

void JB_Msg_Item__(Message* Self, FastString* Fs);

bool JB_Msg_jbinTest(Message* Self);

JB_String* JB_Msg_JDB2_(Message* Self, int Flags, FastString* Fs_in);

JB_String* jdb4(Message* Self);

JB_String* SC_Msg_JDB4_(Message* Self, FastString* Fs_in);

JB_String* JB_Msg_JDB_(Message* Self, FastString* Fs_in, int Flags);

void SC_Msg_KinderRemoveAfter(Message* Self);

Message* JB_Msg_Last(Message* Self, Syntax Need);

void SC_Msg_LastInBlock(Message* Self, SCBlockage Reason);

Message* SC_Msg_LastUsedFix(Message* Self);

int JB_Msg_Length(Message* Self);

void JB_Msg_List__(Message* Self, FastString* Fs);

Array* SC_Msg_ListAll(Message* Self);

bool JB_Msg_ListViewable(Message* Self);

JB_String* JB_Msg_Locate(Message* Self);

void SC_Msg_LoopContinue(Message* Self);

void SC_Msg_LoopExit(Message* Self);

void SC_Msg_LoopExitter(Message* Self, int ASMType, SCBlockage ExitCode);

Message* JB_Msg_MacroAvoidCopy(Message* Self);

void JB_Msg_MacroCopy(Message* Self, Message* Root, Array* Prms, Message* Dest);

void SC_Msg_MacroFixSub(Message* Self, SCDecl* Contains);

Message* JB_Msg_MacroPrm(Message* Self, Message* Root, Array* Prms, Message* Dest);

Message* JB_Msg_MacroSame(Message* Self, Message* Prm);

Message* SC_Msg_MainFix(Message* Self);

void SC_Msg_mainfix2(Message* Self);

int SC_Msg_MainOneArg(Message* Self, Message* Arg, int I, int Found);

void SC_Msg_MakeComment(Message* Self);

void SC_Msg_MakeTaskVar(Message* Self, Message* Con, Message* Before, bool First);

void JB_Msg_max__(Message* Self, FastString* Fs);

void SC_Msg_MiniArgCpp(Message* Self, FastString* Fs);

JB_String* JB_Msg_MiniName(Message* Self, JB_String* Prefix);

void SC_Msg_MiniTran(Message* Self, SCNode* Name_space, JB_String* On);

int SC_Msg_ModelMode(Message* Self);

Message* SC_Msg_ModelType(Message* Self);

Message* SC_Msg_ModuleSrc(Message* Self);

void SC_Msg_Move(Message* Self, Message* Last, Message* Into);

void SC_Msg_MoveAllAfter(Message* Self, Message* After);

Message* JB_Msg_Msg(Message* Self, Syntax Fn, JB_String* Name);

void JB_Msg_Msg__(Message* Self, FastString* Fs);

SCArg* SC_Msg_MsgArg(Message* Self);

SCDecl* SC_Msg_MsgDecl(Message* Self);

SCFunction* SC_Msg_MsgFunc(Message* Self);

SCFunction* SC_Msg_MsgOwningFunc(Message* Self);

void JB_Msg_Name__(Message* Self, FastString* Fs);

Message* SC_Msg_NeedBra(Message* Self);

Message* JB_Msg_NeedFirst(Message* Self);

Message* SC_Msg_NeedMarker(Message* Self, JB_String* S, bool B);

bool SC_Msg_NeedsPreprocess(Message* Self);

Message* SC_Msg_Negate(Message* Self);

Message* SC_Msg_NegateThg(Message* Self);

Message* JB_Msg_NextOfName(Message* Self, Syntax Need, JB_String* Name);

Message* JB_Msg_NextOf(Message* Self, Syntax Need);

void SC_Msg_Next_Index(Message* Self, SCIterator* Iter, Message* Node2);

SCDecl* SC_Msg_NiceIsFlagSyntax(Message* Self, Message* Opch, Message* RN, SCNode* Name_space, Message* Side);

Message* SC_Msg_NiceParent(Message* Self);

void JB_Msg_Nil__(Message* Self, FastString* Fs);

int SC_Msg_NilCheckMode(Message* Self, bool Ok);

Message* SC_Msg_NormaliseFunc(Message* Self, SCClass* AddSelf);

void SC_Msg_NotNilRZ(Message* Self, SCDecl* Type, SCNode* Space);

void JB_Msg_Num__(Message* Self, FastString* Fs);

bool SC_Msg_OarExpand(Message* Self);

void JB_Msg_Oat__(Message* Self, FastString* Fs);

SCClass* SC_Msg_ObjCls(Message* Self);

bool JB_Msg_ContainsStr(Message* Self, JB_String* S);

bool JB_Msg_InMsg(Message* Self, Message* F);

bool JB_Msg_OperatorIn(Message* Self, Syntax F);

bool SC_Msg_OperatorIsARel(Message* Self, JB_String* Name);

bool SC_Msg_OperatorIsBRel(Message* Self, JB_String* Name);

bool SC_Msg_OperatorIsDot(Message* Self, JB_String* Name);

bool SC_Msg_OperatorIsOpp(Message* Self, JB_String* Name);

bool SC_Msg_OperatorIsThing(Message* Self, JB_String* Name);

bool SC_Msg_OperatorIsTmp(Message* Self, JB_String* Name);

bool JB_Msg_OperatorMatches(Message* Self, Message* M);

bool JB_Msg_OperatorStarts(Message* Self, JB_String* S);

void JB_Msg_Opp__(Message* Self, FastString* Fs);

bool SC_Msg_OppExpand(Message* Self);

int SC_Msg_OpScore(Message* Self);

JB_String* JB_Msg_OriginalParseData(Message* Self);

Message* SC_Msg_OrigMsg(Message* Self);

JB_String* SC_Msg_OrigRender(Message* Self);

Message* SC_Msg_ParentForAddress(Message* Self);

Message* SC_Msg_ParentPoint(Message* Self);

Message* SC_Msg_ParseShaderSub(Message* Self);

void JB_Msg_pinn__(Message* Self, FastString* Fs);

Message* JB_Msg_PoorAnt(Message* Self);

void SC_Msg_PrepareAST(Message* Self, JB_String* Path);

int JB_Msg_PrevIndentCheck(Message* Self, Message* Pr);

void JB_Msg_Prm__(Message* Self, FastString* Fs);

SCFunction* SC_Msg_PrmFunc(Message* Self);

Message* SC_Msg_QMarkRel(Message* Self);

void JB_Msg_Ques__(Message* Self, FastString* Fs);

void JB_Msg_Quot__(Message* Self, FastString* Fs);

IntRange JB_Msg_Range(Message* Self);

void JB_Msg_RangeSet(Message* Self, IntRange R);

int SC_Msg_RC_HasTemporary(Message* Self);

NilState SC_Msg_RedundantDeclare(Message* Self, NilState D);

NilState SC_Msg_RedundantVar(Message* Self, SCDecl* Dcl, NilCheckMode Test);

bool SC_Msg_RefDisappears(Message* Self);

bool SC_Msg_RefTransparent(Message* Self);

AsmReg SC_Msg_Reg(Message* Self);

int SC_Msg_RegOrNum(Message* Self, bool NeedReg);

void JB_Msg_Rel__(Message* Self, FastString* Fs);

bool SC_Msg_RelFix(Message* Self, bool Force);

Message* SC_Msg_RemoveTypeCasts(Message* Self);

JB_String* JB_Msg_Render(Message* Self, FastString* Fs_in);

void JB_Msg_render_jbin_sub(Message* Self, FastString* Js);

JB_String* JB_Msg_RenderJbin(Message* Self, JB_String* Shell_path, FastString* Fs_in);

void JB_Msg_RenderPrm(Message* Self, FastString* Fs, byte B1, byte B2);

JB_String* SC_Msg_RenderType(Message* Self);

JB_String* SC_Msg_RenderTypeAndName(Message* Self);

void JB_Msg_RenderWithSpaces(Message* Self, FastString* Fs, Message* Ch);

Message* SC_Msg_ReplaceInbuiltSub(Message* Self, SCNode* Name_space, SCDecl* Self_decl);

Message* JB_Msg_ReplaceInto(Message* Self, Message* W);

Message* SC_Msg_ReplaceWith(Message* Self, Message* J);

Message* SC_Msg_ReplaceWithChild(Message* Self);

JB_Object* JB_Msg_RestoreLoad(Message* Self);

Message* SC_Msg_Resync(Message* Self, Message* Parent);

void SC_Msg_Safe(Message* Self, FastString* Fs);

void SC_Msg_SafeRemove(Message* Self, Syntax T);

void SC_Msg_SafeReplaceWith(Message* Self, Message* Incoming);

SCArg* SC_Msg_SCArg(Message* Self, SCNode* P, Message* Avoid);

SCArg* SC_Msg_SCArgNested(Message* Self, Message* Base, SCNode* P);

void JB_Msg_SCnj__(Message* Self, FastString* Fs);

void JB_Msg_SCom__(Message* Self, FastString* Fs);

void JB_Msg_SDot__(Message* Self, FastString* Fs);

int SC_Msg_SelfUsedForProperty(Message* Self);

Message* SC_Msg_SendPerryErrors(Message* Self);

bool SC_Msg_SettingToNil(Message* Self);

DotUseType SC_Msg_SetType(Message* Self);

bool JB_Msg_ShallowEquals(Message* Self, Message* B, bool Aware);

void JB_Msg_Sheb__(Message* Self, FastString* Fs);

void SC_Msg_SlidePositions(Message* Self, int Add);

void SC_Msg_SpdFuncSet(Message* Self, Syntax Value);

void JB_Msg_SStr__(Message* Self, FastString* Fs);

void SC_Msg_StartUsingAfter(Message* Self);

void SC_Msg_StatementExprSet(Message* Self, SCArg* Arg);

void JB_Msg_SThg__(Message* Self, FastString* Fs);

void JB_Msg_Str__(Message* Self, FastString* Fs);

Message* JB_Msg_NeedSyxOK(Message* Self, Syntax Need, Syntax OK);

Message* JB_Msg_NeedSyx(Message* Self, Syntax S);

Message* JB_Msg_NeedSyxInt(Message* Self, Syntax S, int N);

Message* JB_Msg_NeedSyxName(Message* Self, Syntax S, JB_String* Name);

void JB_Msg_SetStr(Message* Self, JB_String* Key, JB_String* Value);

void JB_Msg_SetMsg(Message* Self, JB_String* Key, Message* Value);

Message* JB_Msg_GetConf(Message* Self, JB_String* Key, bool Err);

void JB_Msg_AppendString(Message* Self, JB_String* Key);

void JB_Msg_AppendSyx(Message* Self, Syntax Fn, JB_String* Name);

void JB_Msg_AppendNum(Message* Self, int64 Num);

bool JB_Msg_SyntaxEquals(Message* Self, JB_String* Name, bool Aware);

bool JB_Msg_EqualsSyx(Message* Self, Syntax X, bool Aware);

void JB_Msg_SyntaxExpect(Message* Self, JB_String* Error);

bool JB_Msg_SyntaxIs(Message* Self, MsgParseFlags F);

void JB_Msg_SyntaxIsSet(Message* Self, MsgParseFlags F, bool Value);

void JB_Msg_SyntaxProblem(Message* Self, JB_String* Error);

MessagePosition JB_Msg_SyntaxUsing(Message* Self);

void JB_Msg_SyntaxWarn(Message* Self, JB_String* Error);

bool SC_Msg_TargetTest(Message* Self);

Message* SC_Msg_TaskConBefore(Message* Self);

void SC_Msg_tEENGAGERS(Message* Self);

Message* SC_Msg_TempIntoBlock(Message* Self, Message* ParentPlace);

void JB_Msg_Test(Message* Self, JB_String* New_render, JB_String* Name);

void JB_Msg_test_style(Message* Self);

bool SC_Msg_TestFuncName(Message* Self);

bool JB_Msg_TestSub(Message* Self, JB_String* New_render, JB_String* Name);

JB_String* JB_Msg_Text(Message* Self, int I);

bool JB_Msg_TextSet(Message* Self, int I, JB_String* V);

void JB_Msg_Thg__(Message* Self, FastString* Fs);

void JB_Msg_Tmp__(Message* Self, FastString* Fs);

void JB_Msg_Todo__(Message* Self, FastString* Fs);

void SC_Msg_Tran_Isnt(Message* Self, JB_String* Name);

void SC_Msg_Tran_QMark(Message* Self);

Message* SC_Msg_Tran_Target(Message* Self);

void SC_Msg_Tran_TargetSub(Message* Self);

void SC_Msg_Tran_With(Message* Self);

Message* SC_Msg_TranModel(Message* Self);

void JB_Msg_TRel__(Message* Self, FastString* Fs);

void JB_Msg_Tril__(Message* Self, FastString* Fs);

MaybeBool SC_Msg_Trueness(Message* Self, NilState Found);

bool SC_Msg_TrueOrFalse(Message* Self);

Message* JB_Msg_TViewCH(Message* Self);

void JB_Msg_Type__(Message* Self, FastString* Fs);

void SC_Msg_TypeExpect(Message* Self, DataTypeCode* Ty, DataTypeCode In);

Message* SC_Msg_TypeOfArrItem(Message* Self);

Message* SC_Msg_UnBra(Message* Self);

Message* SC_Msg_UnBraType(Message* Self);

void JB_Msg_UnEmbedStr(Message* Self);

void JB_Msg_Unit__(Message* Self, FastString* Fs);

bool SC_Msg_UnitMatch(Message* Self, JB_String* A, JB_String* B);

Message* SC_Msg_UnReachable(Message* Self);

Message* SC_Msg_UpToType(Message* Self);

void JB_Msg_url__(Message* Self, FastString* Fs);

Message* SC_Msg_UseNonRefChangers(Message* Self, bool Parent);

JB_String* JB_Msg_Value(Message* Self);

JB_String* SC_Msg_VarName(Message* Self);

bool SC_Msg_visible(Message* Self);

void SC_Msg_visibleSet(Message* Self, bool Value);

MaybeBool SC_Msg_visible2(Message* Self);

Message* SC_Msg_LayerWipeCopy(Message* Self, Message* Oof);

Message* SC_Msg_WipeCopy(Message* Self);

void JB_Msg_WipePositions(Message* Self);

void SC_Msg_WithDeclTransform(Message* Self, Message* Decl, Message* Rel, Message* Arg);

bool SC_Msg_WithinLoop(Message* Self, Message* Stop);

bool JB_Msg_WithinType(Message* Self, int Allowed);

int SC_Msg_WrapExpr(Message* Self, SCDecl* Src);

void SC_Msg_WrapFloatOrInt(Message* Self, DataTypeCode T, int N, SCDecl* D);

Message* SC_Msg_WrapWith(Message* Self, Syntax F, JB_String* S);

void JB_Msg_XAtt__(Message* Self, FastString* Fs);

void JB_Msg_XCDT__(Message* Self, FastString* Fs);

void JB_Msg_XCom__(Message* Self, FastString* Fs);

void JB_Msg_XML__(Message* Self, FastString* Fs);

void JB_Msg_XPI__(Message* Self, FastString* Fs);

void JB_Msg_XTxt__(Message* Self, FastString* Fs);

bool JB_Msg_Yes(Message* Self, bool Default);

void JB_Msg_Yoda__(Message* Self, FastString* Fs);

SyntaxObj* JB_Msg__GetFunc(Message* Msg);

Message* SC_Msg__NilchCompare();

bool JB_Msg__TreeCompare(Message* Orig, Message* Reparse, bool PrintIfSame);

void JB_Msg__TreeComparePrint(Message* Orig);



// JB_MessageID
MessageID* JB_ID_Constructor(MessageID* Self, JB_String* Name, Syntax Fn, uint64 ID);

void JB_ID_Destructor(MessageID* Self);

JB_String* JB_ID_Render(MessageID* Self, FastString* Fs_in);

bool JB_ID__ByID(JB_Object* A, JB_Object* B);



// JB_SCDecl
int SC_Decl_AllocatedSize(SCDecl* Self);

bool SC_Decl_AlreadyContains(SCDecl* Self);

bool SC_Decl_AssignabilityCheck(SCDecl* Self, Message* Ln, Message* RN, SCDecl* Rc);

JB_String* SC_Decl_AutoCompleteName(SCDecl* Self);

void SC_Decl_BecomeReal(SCDecl* Self);

SCDecl* SC_Decl_Better_Numeric(SCDecl* Self, SCDecl* O, OpMode Mode, Message* Where);

bool SC_Decl_CanNilCheck(SCDecl* Self);

bool SC_Decl_CantBeNilInCpp(SCDecl* Self);

SCDecl* SC_Decl_CanUpgradeInternalPointer(SCDecl* Self);

bool SC_Decl_CanUseDefault(SCDecl* Self);

bool SC_Decl_CanWrap(SCDecl* Self);

SCDecl* SC_Decl_CheckMath(SCDecl* Self, Message* Exp);

bool SC_Decl_CompareUnclear(SCDecl* Self, SCDecl* D, bool MakesSenseVsZero);

bool SC_Decl_ConstInRange(SCDecl* Self, Message* RN, SCDecl* Rt);

bool SC_Decl_ConstInRangeSub(SCDecl* Self, int64 Value);

SCDecl* SC_Decl_Constructor(SCDecl* Self, SCClass* Type);

SCDecl* SC_Decl_Containedfix(SCDecl* Self);

SCDecl* SC_Decl_ContainedReplace(SCDecl* Self, SCDecl* Contains, bool NeedsName);

bool SC_Decl_ContainsMatch(SCDecl* Self, SCDecl* O, int TypeCast);

SCDecl* SC_Decl_CopyDecl(SCDecl* Self, bool ForNewVariable);

void SC_Decl_CopyTypeInfoTo(SCDecl* Self, SCDecl* Dcl);

bool SC_Decl_CouldUpgradeToReal(SCDecl* Self);

Message* SC_Decl_CreateDefault(SCDecl* Self, Message* Errs, bool Isfunc);

Message* SC_Decl_CreateSimpleTypeCast(SCDecl* Self, Message* Exp);

Message* SC_Decl_CreateStructNil(SCDecl* Self, Message* Where);

Message* SC_Decl_CreateStructNilSub(SCDecl* Self);

int SC_Decl_DeclSize(SCDecl* Self);

int SC_Decl_DeclSizeSort(SCDecl* Self);

Message* SC_Decl_DeclToAddr(SCDecl* Self, SCDecl* P0);

Message* SC_Decl_DeclToDot(SCDecl* Self, SCDecl* P0);

SCDecl* SC_Decl_DefaultToReal(SCDecl* Self);

SCDecl* SC_Decl_DeReference(SCDecl* Self, Message* Brel, SCNode* Name_space, bool IsAccess);

SCDecl* SC_Decl_DeReferenceSub(SCDecl* Self, Message* Brel, SCNode* Name_space, bool IsAccess);

void SC_Decl_Destructor(SCDecl* Self);

SCDecl* SC_Decl_DownGrade(SCDecl* Self);

void SC_Decl_ExpectFail(SCDecl* Self, SCDecl* O, Message* Errnode, Message* Backup);

Message* SC_Decl_ExpectMatch(SCDecl* Self, SCDecl* O, int TypeCast, Message* Exp, Message* ErrNode);

void SC_Decl_ExpectRelMatch(SCDecl* Self, SCDecl* O, Message* Exp, Message* Side, Message* ErrNode);

SCDecl* SC_Decl_ExtractAmount(SCDecl* Self, Message* Prms, SCNode* Name_space);

SCDecl* SC_Decl_ExtractAmountSub(SCDecl* Self, Message* Prms, SCNode* Name_space);

bool SC_Decl_FastMatch(SCDecl* Self, SCDecl* O);

bool SC_Decl_Found(SCDecl* Self);

DataTypeCode SC_Decl_GameType(SCDecl* Self);

SCDecl* SC_Decl_GetAddress(SCDecl* Self, DeclMode Purpose);

SCDecl* SC_Decl_GetCArray(SCDecl* Self, int Amount);

SCIterator* SC_Decl_GetIteratorAny(SCDecl* Self, JB_String* Name, Message* Node);

bool SC_Decl_HasStruct(SCDecl* Self);

SCFunction* SC_Decl_HasStructDestructor(SCDecl* Self);

SCDecl* SC_Decl_HighestArrayContainMatch(SCDecl* Self, SCDecl* Other, Message* Exp);

SCDecl* SC_Decl_HighestMatch(SCDecl* Self, SCDecl* Other, Message* Exp);

bool SC_Decl_IntsOnly(SCDecl* Self, Message* Exp);

void SC_Decl_IsCarray(SCDecl* Self, int Size, SCDecl* Of);

bool SC_Decl_IsCArray(SCDecl* Self);

bool SC_Decl_IsConstOf(SCDecl* Self, SCDecl* B);

bool SC_Decl_IsDataTypeOnly(SCDecl* Self);

bool SC_Decl_IsFloat(SCDecl* Self);

bool SC_Decl_IsInt(SCDecl* Self);

bool SC_Decl_IsInteger(SCDecl* Self);

bool SC_Decl_IsLib(SCDecl* Self);

bool SC_Decl_IsNil(SCDecl* Self);

bool SC_Decl_IsNormal(SCDecl* Self);

bool SC_Decl_IsNormalBool(SCDecl* Self);

bool SC_Decl_IsNormalNumber(SCDecl* Self);

bool SC_Decl_IsNormalObject(SCDecl* Self);

bool SC_Decl_IsNormalStruct(SCDecl* Self);

bool SC_Decl_IsntReallyCastable(SCDecl* Self, Message* Side);

int SC_Decl_IsNumeric(SCDecl* Self);

bool SC_Decl_IsObject(SCDecl* Self);

bool SC_Decl_IsReffable(SCDecl* Self, bool SetOnly);

bool SC_Decl_IsReg(SCDecl* Self);

JB_String* SC_Decl_IsSaveable(SCDecl* Self);

void SC_Decl_IsTypeImproveSet(SCDecl* Self, bool Value);

bool SC_Decl_IsUintLike(SCDecl* Self);

bool SC_Decl_IsVoidPtr(SCDecl* Self);

bool SC_Decl_LoadContained(SCDecl* Self, Message* Contained, Message* Wrap, SCNode* Name_Space, DeclMode Purpose);

bool SC_Decl_LoadContainedSub(SCDecl* Self, SCDecl* Cont, Message* Wrap, SCNode* Name_Space, DeclMode Purpose);

SCDecl* SC_Decl_MakeAsObject(SCDecl* Self, SCDecl* Container, Message* ErrPlace);

SCDecl* SC_Decl_MakeBorrowed(SCDecl* Self, bool StayBorrowed);

void SC_Decl_MakeContainedObject(SCDecl* Self, Message* ErrPlace);

SCDecl* SC_Decl_MakeContainedOptional(SCDecl* Self);

SCDecl* SC_Decl_MakeDataObject(SCDecl* Self, SCNode* Name_Space, DeclMode Purpose);

SCDecl* SC_Decl_MakeExistance(SCDecl* Self, NilState Type, SCDecl* Default);

void SC_Decl_MakeGameFlying(SCDecl* Self, SCClass* Oof, Message* M);

SCDecl* SC_Decl_MakeNewNil(SCDecl* Self);

SCDecl* SC_Decl_MakeNewOptional(SCDecl* Self);

SCDecl* SC_Decl_MakeNewReal(SCDecl* Self);

SCDecl* SC_Decl_MakeReal(SCDecl* Self);

bool SC_Decl_MakeStatic(SCDecl* Self, Message* Wrap, SCNode* Name_Space, DeclMode Purpose);

void SC_Decl_MarkAsRefAltered(SCDecl* Self);

bool SC_Decl_MatchC(SCDecl* Self, SCDecl* O);

bool SC_Decl_MiniMatch(SCDecl* Self, SCDecl* O, int TypeCast);

void SC_Decl_NameSet(SCDecl* Self, JB_String* Value);

bool SC_Decl_NeedsContainedfix(SCDecl* Self);

SCDecl* SC_Decl_NewWrapper(SCDecl* Self, SCDecl* CastTo);

SCDecl* SC_Decl_NilConstructor(SCDecl* Self, NilState Type);

NilState SC_Decl_NilCurr(SCDecl* Self);

void SC_Decl_NilPrmFail(SCDecl* Self, Message* Where, SCFunction* F);

bool SC_Decl_NilStated(SCDecl* Self);

void SC_Decl_NoBlindCasts(SCDecl* Self, SCDecl* Old, Message* Exp, SCNode* Name_space);

void SC_Decl_numberconstSet(SCDecl* Self, uint64 V);

bool SC_Decl_OperatorExact_isa(SCDecl* Self, SCClass* V);

bool SC_Decl_MatchesDecl(SCDecl* Self, SCDecl* O);

bool SC_Decl_OperatorMatches(SCDecl* Self, SCClass* O);

int SC_Decl_PointerIncrement(SCDecl* Self);

bool SC_Decl_PointeryMatch(SCDecl* Self, SCDecl* O);

int SC_Decl_PointeryMatchSub(SCDecl* Self, SCDecl* O, int TypeCast);

void SC_Decl_PrefixedName(SCDecl* Self, FastString* Fs, SCModule* M);

JB_String* SC_Decl_PrmStateMsg(SCDecl* Self, JB_String* Needed, SCFunction* F);

SCDecl* SC_Decl_ProcessAs(SCDecl* Self, Message* Msg);

SCImport* SC_Decl_Project(SCDecl* Self);

SCDecl* SC_Decl_ReallyContains(SCDecl* Self);

JB_String* SC_Decl_RealName(SCDecl* Self);

Message* SC_Decl_RefDestructor(SCDecl* Self);

SCDecl* SC_Decl_RefineDecl(SCDecl* Self, Message* List);

AsmReg SC_Decl_Reg(SCDecl* Self);

DataTypeCode SC_Decl_RegType(SCDecl* Self);

JB_String* SC_Decl_Render(SCDecl* Self, FastString* Fs_in);

JB_String* SC_Decl_RenderTypeAndName(SCDecl* Self, int Minimal);

JB_String* SC_Decl_RenderTypeName(SCDecl* Self, FastString* Fs_in);

JB_String* SC_Decl_RenderTypeNameNicer(SCDecl* Self, FastString* Fs_in);

bool SC_Decl_SafelyWrappable(SCDecl* Self);

bool SC_Decl_SameForReplace(SCDecl* Self, SCDecl* C);

NilState SC_Decl_StatedOptional(SCDecl* Self);

NilState SC_Decl_StatedReal(SCDecl* Self);

void SC_Decl_SyntaxAppend(SCDecl* Self, SCDeclInfo D);

bool SC_Decl_SyntaxIs(SCDecl* Self, SCDeclInfo D);

void SC_Decl_SyntaxIsSet(SCDecl* Self, SCDeclInfo D, bool Value);

int SC_Decl_TryTypeCast(SCDecl* Self, SCDecl* O, Message* Exp, int TypeCast);

int SC_Decl_TryTypeCastPointer(SCDecl* Self, SCDecl* O, Message* Exp, int TypeCast, bool CArray);

JB_String* SC_Decl_TryUseSaveable(SCDecl* Self, bool IsSave, SCClass* Cls);

DataTypeCode SC_Decl_TypeInfo(SCDecl* Self);

bool SC_Decl_TypeIsReached(SCDecl* Self);

int SC_Decl_TypeMatch(SCDecl* Self, SCDecl* O, int TypeCast, Message* Exp);

int SC_Decl_TypeOfAccess(SCDecl* Self, SCDecl* Access, Message* Ch);

void SC_Decl_TypeReach(SCDecl* Self, SCNode* From, Message* Src);

bool SC_Decl_TypeSuffers(SCDecl* Self);

int SC_Decl_VarSizeSub(SCDecl* Self, bool TheVarItself);

Message* SC_Decl_WriteDeclFull(SCDecl* Self, JB_String* DeclName, int Minimal);

Message* SC_Decl_WriteDeclSub(SCDecl* Self, JB_String* Name, int Minimal);

Message* SC_Decl_WriteDeclTypeAndName(SCDecl* Self, JB_String* Name, int Minimal);

Message* SC_Decl_WriteNilDecl(SCDecl* Self);

Message* SC_Decl_WriteNilRel(SCDecl* Self);

Message* SC_Decl_WriteSimpleType(SCDecl* Self);

Message* SC_Decl_WriteType(SCDecl* Self, int Minimal);

Message* SC_Decl_WriteTypeCast(SCDecl* Self, Message* Msg);

Message* SC_Decl_WriteVerySimpleType(SCDecl* Self);



// JB_SCFile
Message* SC_SCFile_AST(SCFile* Self);

Message* SC_SCFile_ASTSub(SCFile* Self, bool Orig);

void SC_SCFile_CollectGlobals(SCFile* Self, SCNode* P);

SCFile* SC_SCFile_Constructor(SCFile* Self, JB_File* F, SCImport* P, int N);

void SC_SCFile_Destructor(SCFile* Self);

void SC_SCFile_DetectInsecureWords(SCFile* Self);

Message* SC_SCFile_GetMsg(SCFile* Self, int Pos);

Message* SC_SCFile_Orig(SCFile* Self);

Message* SC_SCFile_Start_AST(SCFile* Self);

void SC_SCFile_Use(SCFile* Self);



// JB_SCIterator
void SC_Iter_Check(SCIterator* Self, SCClass* Cls);

SCIterator* SC_Iter_Constructor(SCIterator* Self, SCClass* Parent, Message* Msg);

void SC_Iter_Destructor(SCIterator* Self);

Message* SC_Iter_MakeWhile(SCIterator* Self, Message* Arg, Message* Postcond);

void SC_Iter_RenameSelf(SCIterator* Self, Message* Name);

void SC_Iter_RenameValue(SCIterator* Self, Message* S);

void SC_Iter_Renuqify(SCIterator* Self, SCNode* P);

Array* SC_Iter_Uniqueify(SCIterator* Self, Message* Msg);

int SC_Iter__Init_();

int SC_Iter__InitCode_();

SCNode* SC_Iter__NeuIter(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCIterator* SC_Iter__SimpleIter(JB_String* Src);



// JB_SCNode
SCDecl* SC_Base_AddNumericConst(SCNode* Self, JB_String* Name, int64 Value, Message* Where);

JB_String* SC_Base_AutoCompleteKind(SCNode* Self);

uint64 SC_Base_CalculateConstWithMsg(SCNode* Self, Message* Value);

uint64 SC_Base_CalculateConstWithMsgTc(SCNode* Self, Message* Value, DataTypeCode* Ty);

uint64 SC_Base_CalculateConstRel(SCNode* Self, Message* Value, DataTypeCode* Ty);

void SC_Base_CollectConstantsSub(SCNode* Self, Message* Ch);

void SC_Base_CollectFromNode(SCNode* Self, Message* AST, bool Visible, Message* Dest);

bool SC_Base_CollectOne(SCNode* Self, Message* C, bool Visible);

void SC_Base_CollectOneConstants(SCNode* Self, Message* Ch);

Message* SC_Base_CollectStr(SCNode* Self, JB_String* S);

SCNode* SC_Base_CollectSub(SCNode* Self, Message* C);

void SC_Base_ConstantExpand(SCNode* Self, Message* Ch);

SCNode* SC_Base_Constructor0(SCNode* Self);

SCNode* SC_Base_ConstructorStr(SCNode* Self, JB_String* Name, bool Dummy);

SCNode* SC_Base_ConstructorMsg(SCNode* Self, Message* Node);

void SC_Base_CreateNameDict(SCNode* Self, Message* FuncName, Array* NameList);

void SC_Base_Destructor(SCNode* Self);

Message* SC_Base_DiissplayObj(SCNode* Self, Message* Rz);

bool SC_Base_ExpectModule(SCNode* Self, Message* Errplace);

SCClass* SC_Base_FindClass(SCNode* Self, JB_String* Name, Message* Where, SCNodeFindMode Mode);

SCClass* SC_Base_FindClassMsg(SCNode* Self, Message* Where, SCNodeFindMode Mode);

Message* SC_Base_FindCppWrapper(SCNode* Self, Message* Place, bool Isclass);

SCModule* SC_Base_FindModule(SCNode* Self, JB_String* Name, Message* Where, SCNodeFindMode Mode);

SCModule* SC_Base_FindModuleMsg(SCNode* Self, Message* Where, SCNodeFindMode Mode);

SCNode* SC_Base_FindModuleParent(SCNode* Self, SCNodeFindMode Mode);

bool SC_Base_FindVis(SCNode* Self, Message* C);

Message* SC_Base_FuncSrc(SCNode* Self);

void SC_Base_ImportFile(SCNode* Self, SCFile* File);

bool SC_Base_IsModuleFunc(SCNode* Self);

SCClass* SC_Base_IsNormalObject(SCNode* Self);

bool SC_Base_IsSTDLib(SCNode* Self);

JB_String* SC_Base_LateAddTempory(SCNode* Self, JB_String* Type, JB_String* Name1, Message* Value, Message* Err);

Message* SC_Base_LinkagePlace(SCNode* Self);

Array* SC_Base_ListFunctions(SCNode* Self);

void SC_Base_LoadExportName(SCNode* Self);

bool SC_Base_LoadVisibility(SCNode* Self, Message* P);

JB_Object* SC_Base_LookUpDot(SCNode* Self, JB_String* Name, Message* Exp, SCNode* Arg_space, SCDecl* Contains, Message* Side);

SCObject* SC_Base_LookUpFunc(SCNode* Self, JB_String* Name, Message* Exp, Message* ParamsHere);

SCObject* SC_Base_LookUpSub(SCNode* Self, JB_String* OrigName, Message* Exp, Message* ParamsHere, SCNode* Arg_Space, SCDecl* Contains, Message* Side, int Purpose);

SCObject* SC_Base_LookUpVar(SCNode* Self, JB_String* Name, Message* Exp, Message* Side);

SCDecl* SC_Base_LookUpVarDecl(SCNode* Self, JB_String* Name);

SCObject* SC_Base_LookUpVarRootDecl(SCNode* Self, JB_String* Name, Message* Exp);

bool SC_Base_NeedsExport(SCNode* Self);

SCFunction* SC_Base_OwningFunc(SCNode* Self);

SCNode* SC_Base_ProcessLinkage(SCNode* Self, Message* Node, Dictionary* Table);

SCNode* SC_Base_ProjectFix(SCNode* Self);

JB_String* SC_Base_ReachedName(SCNode* Self);

bool SC_Base_RehomeExport(SCNode* Self);

SCDecl* SC_Base_RequireContained(SCNode* Self, Message* Exp);

Message* SC_Base_Route(SCNode* Self, JB_String* Name);

void SC_Base_SetExportName(SCNode* Self, JB_String* S, bool Explicit);

SCClass* SC_Base_ShouldBeClass(SCNode* Self, Message* Errplace);

Message* SC_Base_SourceArg(SCNode* Self);

SCModule* SC_Base_SpaceModule(SCNode* Self, Message* Errplace);

JB_String* SC_Base_SubProjName(SCNode* Self);

SCObject* SC_Base_SyntaxAccessWithMsg(SCNode* Self, Message* S);

SCObject* SC_Base_SyntaxAccessWithStr(SCNode* Self, JB_String* S);

JB_String* SC_Base_TestExportName(SCNode* Self, JB_String* S, bool Explicit);

void SC_Base_Tran_Const(SCNode* Self, SCDecl* D, SCNode* Base);

void SC_Base_TryAdd(SCNode* Self, Message* ErrPlace, SCObject* IncObj, JB_String* Name);

void SC_Base_TryAddBase(SCNode* Self, Message* C, SCNode* Neu);

void SC_Base_TryAddSub(SCNode* Self, Message* ErrPlace, SCObject* IncObj, JB_String* Name);

JB_String* SC_Base_UniquifyExport(SCNode* Self, JB_String* S);

SCObject* SC_Base_UpCheck(SCNode* Self, JB_String* Name, bool LookUp);

SCNode* SC_Base_UpClass(SCNode* Self, Message* F);

void SC_Base_Use(SCNode* Self);

int SC_Base__Init_();

int SC_Base__InitCode_();

SCNode* SC_Base__LoadCppPart(Message* Node, SCNode* Name_space, Message* ErrPlace);



// JB_SaverClassInfo
void JB_sci_Clear(SaverClassInfo* Self);

SaverClassInfo* JB_sci_Constructor(SaverClassInfo* Self, JB_Class* Cls, char* Data);

void JB_sci_Destructor(SaverClassInfo* Self);

bool JB_sci_HasData(SaverClassInfo* Self);

void JB_sci_Output(SaverClassInfo* Self, ObjectSaver* Saver);



// JB_SimpleGraph


// JB_SpdProcess
bool JB_Proc_Alive(SpdProcess* Self);

bool JB_Proc_ChildAlive(SpdProcess* Self);

bool JB_Proc_CommsOpen(SpdProcess* Self);

SpdProcess* JB_Proc_Constructor(SpdProcess* Self, JB_String* Path, FP_SpdMainFn Fn, PicoComms* Pico, Array* Params, ProcessMode Mode);

void JB_Proc_Destructor(SpdProcess* Self);

void JB_Proc_Disconnect(SpdProcess* Self, JB_StringC* Why);

Message* JB_Proc_Get(SpdProcess* Self, float T);

bool JB_Proc_IsOpen(SpdProcess* Self);

bool JB_Proc_ParentAlive(SpdProcess* Self);

bool JB_Proc_Send(SpdProcess* Self, Message* Msg);

int JB_Proc__InitCode_();

void JB_Proc__InitOwner();



// JB_Task
JB_Task* JB_Task_Constructor(JB_Task* Self, uint Obj, void* Func);

void JB_Task_Destructor(JB_Task* Self);

LessThan3* SC_Task_LessThan3_Constructor(LessThan3* Self, JB_String* A, int B, JB_String* C);



// JB_Error
JB_Error* JB_Err_Constructor(JB_Error* Self, Message* Node, JB_String* Desc, ErrorSeverity Level, JB_String* Path);

JB_Error* JB_Err_ConstructorNothing(JB_Error* Self);

void JB_Err_Destructor(JB_Error* Self);

void JB_Err_Fill(JB_Error* Self, JB_String* Path, JB_String* Desc);

void JB_Err_GrabLine(JB_Error* Self, FastString* Fs, bool Usecolor);

bool JB_Err_HasPosition(JB_Error* Self);

void SC_Err_Improve(JB_Error* Self);

bool JB_Err_IsBad(JB_Error* Self);

bool JB_Err_IsError(JB_Error* Self);

bool JB_Err_IsWarning(JB_Error* Self);

bool JB_Err_LineIdentifiers(JB_Error* Self, FastString* Fs, JB_String* Path);

int JB_Err_LinePos(JB_Error* Self, JB_String* Data);

JB_String* JB_Err_Render(JB_Error* Self, FastString* Fs_in);

JB_String* SC_Err_Render_Unix(JB_Error* Self, FastString* Fs_in);

JB_String* JB_Err_RenderClang(JB_Error* Self, FastString* Fs_in);

void SC_Err_SCGrabLine(JB_Error* Self, FastString* Fs, bool Usecolor);

int SC_Err_SCLineCount(JB_Error* Self);

void SC_Err_SCLineIdentifiers(JB_Error* Self, FastString* Fs, JB_String* Data);

JB_String* SC_Err_SCOriginalData(JB_Error* Self);

JB_String* SC_Err_SCOriginalPath(JB_Error* Self);

JB_String* SC_Err_SCRender(JB_Error* Self, FastString* Fs_in);

void JB_Err_ShiftPosition(JB_Error* Self, int I);

bool JB_Err_SyntaxIs(JB_Error* Self, ErrorFlags F);

void JB_Err_SyntaxIsSet(JB_Error* Self, ErrorFlags F, bool Value);

void JB_Err_UpgradeWithNode(JB_Error* Self);

void JB_Err__CantParseNum(Message* Where, JB_String* Num, int Pos);

int JB_Err__Init_();

int JB_Err__InitCode_();

void JB_Err__SourceAdd(Message* M);

void JB_Err__SourceRemove();



// JB_FileArchive


// JB_MessageRoot


// JB_SCArg
SCArg* SC_Arg_Constructor(SCArg* Self, Message* Node);

void SC_Arg_Destructor(SCArg* Self);

JB_String* SC_Arg_Render(SCArg* Self, FastString* Fs_in);



// JB_SCBehaviour
void SC_Beh_Add(SCBehaviour* Self, SCNode* Fn);

SCClass* SC_Beh_Cls(SCBehaviour* Self);

SCBehaviour* SC_Beh_Constructor(SCBehaviour* Self, SCClass* Parent);

void SC_Beh_CreateFuncTable(SCBehaviour* Self, Message* ErrPlace);

void SC_Beh_Destructor(SCBehaviour* Self);

SCBehaviour* SC_Beh_Upwards(SCBehaviour* Self);

SCFunction* SC_Beh__MakeVirtualCaller(SCModule* Mod, SCClass* Cls, Message* ErrPlace);

SCNode* SC_Beh__NewActual(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Beh__NewVirtual(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCModule* SC_Beh__NewVirtualSub(Message* Node, SCClass* Cls, Message* ErrPlace);

bool SC_Beh__Tran_Behaviour(Message* Node, SCClass* Cls);



// JB_SCClass
void SC_Class_AddBehaviourOrInterface(SCClass* Self, SCNode* M, Message* ErrPlace);

void SC_Class_AfterAfterFuncs(SCClass* Self);

void SC_Class_AfterFuncsDecled(SCClass* Self);

JB_String* SC_Class_APIStructName(SCClass* Self);

void SC_Class_BannedCheck(SCClass* Self, Message* Src);

JB_String* SC_Class_BehaviourName(SCClass* Self);

SCFunction* SC_Class_BestBehaviourFor(SCClass* Self, JB_String* Name);

int SC_Class_CalculateSize(SCClass* Self, int Depth);

int SC_Class_CalculateSizeRaw(SCClass* Self, int Depth);

bool SC_Class_CanCompare(SCClass* Self, SCDecl* Against, bool AsEquals);

bool SC_Class_CanCompareSub(SCClass* Self, JB_String* S, SCDecl* Against);

bool SC_Class_CanHaveEmptyConstructor(SCClass* Self);

void SC_Class_CheckAllocVsWrapper(SCClass* Self, SCFunction* F, bool IsConstructor);

void SC_Class_CheckIterator(SCClass* Self);

void SC_Class_ClassCollect(SCClass* Self);

bool SC_Class_CollectProp(SCClass* Self, Message* Msg);

void SC_Class_CollectProperties(SCClass* Self);

SCFunction* SC_Class_ConOrDesForCall(SCClass* Self, bool IsConstructor, int Task);

SCClass* SC_Class_Constructor(SCClass* Self, Message* Node, SCNode* Parent, bool HasPtrs, SCModule* M);

void SC_Class_ContainedTypeLoad(SCClass* Self);

SCFunction* SC_Class_CreateAutoConstructor(SCClass* Self);

void SC_Class_CreateBehaviour(SCClass* Self);

void SC_Class_CreateConstructors(SCClass* Self);

SCFunction* SC_Class_CreateEmptyConstructors(SCClass* Self);

SCFunction* SC_Class_CreateEmptyFunc(SCClass* Self, JB_String* Fname, JB_String* Cpp_name);

JB_String* SC_Class_CStructName(SCClass* Self);

JB_String* SC_Class_CStructNameSub(SCClass* Self);

JB_String* SC_Class_CSuperStructName(SCClass* Self);

void SC_Class_DataTypePostLoad(SCClass* Self);

void SC_Class_DeclModel(SCClass* Self);

void SC_Class_DescribeInPack(SCClass* Self, FastString* J);

void SC_Class_Destructor(SCClass* Self);

SCFunction* SC_Class_DoSaver(SCClass* Self, JB_String* Name, int Stage);

Message* SC_Class_Falsify(SCClass* Self, Message* Ques);

void SC_Class_FillInterFaceIn(SCClass* Self, SCFunction* Fn, bool Late);

void SC_Class_FillInterFaceWrapper(SCClass* Self, SCFunction* Fn);

void SC_Class_FillRoleConstructor(SCClass* Self, SCFunction* Con);

void SC_Class_FillTaskConstructor(SCClass* Self, SCFunction* Con);

void SC_Class_FillTaskConstructorSub(SCClass* Self, Message* Con, Message* Before, int Depth);

SCFunction* SC_Class_FindAllocFunc(SCClass* Self, JB_String* Fname, bool DontCreate);

SCClass* SC_Class_FindContainedClass(SCClass* Self);

SCFunction* SC_Class_FindFunc(SCClass* Self, JB_String* Keyword, bool CheckParents, bool DoError);

SCFunction* SC_Class_FindSpecialFunc(SCClass* Self, JB_String* Keyword, bool CheckParents);

SCFunction* SC_Class_FirstDestructor(SCClass* Self);

int SC_Class_GetDepth(SCClass* Self);

SCClass* SC_Class_GetFlyingMemClassFor(SCClass* Self);

SCDecl* SC_Class_GetFlyingMemory(SCClass* Self, Message* Exp);

SCIterator* SC_Class_GetIteratorAny(SCClass* Self, JB_String* Name, Message* Node);

SCClass* SC_Class_GoUpTo(SCClass* Self, int D);

bool SC_Class_HasGameType(SCClass* Self);

bool SC_Class_HasObjectProperties(SCClass* Self);

bool SC_Class_HasOperator(SCClass* Self, JB_String* Op);

bool SC_Class_HasPackChildren(SCClass* Self);

bool SC_Class_HasStuffToHandleInDestructor(SCClass* Self);

SCClass* SC_Class_InterfaceFor(SCClass* Self, JB_String* Name, Message* Errplace);

SCClass* SC_Class_InterfaceForBehaviour(SCClass* Self, SCFunction* Fn);

bool SC_Class_IsA(SCClass* Self, SCClass* S);

bool SC_Class_IsBehaviourTable(SCClass* Self);

bool SC_Class_IsDataTypeOnly(SCClass* Self);

bool SC_Class_IsDataTypeOrFP(SCClass* Self);

bool SC_Class_IsFunc(SCClass* Self);

bool SC_Class_IsInterface(SCClass* Self);

bool SC_Class_IsMArray(SCClass* Self, Message* Arr);

bool SC_Class_IsObject(SCClass* Self);

bool SC_Class_IsSaveableObject(SCClass* Self);

bool SC_Class_IsSaveableStruct(SCClass* Self);

bool SC_Class_IsStruct(SCClass* Self);

bool SC_Class_IsTask(SCClass* Self);

void SC_Class_Iterfailed(SCClass* Self, JB_String* Name, Message* Node);

void SC_Class_LoadClassType(SCClass* Self);

void SC_Class_LoadConstructors(SCClass* Self);

void SC_Class_LoadLinkage(SCClass* Self);

void SC_Class_LoadModuleForCls(SCClass* Self, Message* Node, SCNode* P);

void SC_Class_LoadSaver(SCClass* Self);

JB_String* SC_Class_LoadSaverSub(SCClass* Self);

void SC_Class_LoadSuperBehaviours(SCClass* Self);

void SC_Class_LoadSuperClass(SCClass* Self);

SCDecl* SC_Class_MakeClassType(SCClass* Self, SCDecl* D);

void SC_Class_ModelDecls(SCClass* Self);

void SC_Class_NeedsDefaultValue(SCClass* Self, Message* Def, Message** Place, JB_String* Name);

bool SC_Class_NeedsExport(SCClass* Self);

void SC_Class_NewDeclInClassModule(SCClass* Self, JB_String* S, SCClass* T);

SCDecl* SC_Class_NotConst(SCClass* Self);

int SC_Class_NumericCount(SCClass* Self);

ClassInfo SC_Class_NumericReduction(SCClass* Self);

void SC_Class_OverrideSyntax(SCClass* Self);

void SC_Class_PackClassChildren(SCClass* Self, FastString* J);

void SC_Class_PackExport(SCClass* Self, FastString* J);

int SC_Class_PassableCount(SCClass* Self);

void SC_Class_ProcessBehaviours(SCClass* Self);

void SC_Class_ProcessInterfaces(SCClass* Self);

void SC_Class_Reach(SCClass* Self, SCNode* From, Message* Src);

void SC_Class_ReachBehaviours(SCClass* Self);

bool SC_Class_Real_Isa(SCClass* Self, SCClass* Cls);

bool SC_Class_Real_Isa2(SCClass* Self, SCClass* Cls);

SCClass* SC_Class_RealClass(SCClass* Self);

SCClass* SC_Class_RealSuper(SCClass* Self);

void SC_Class_RenameInterfaces(SCClass* Self);

JB_String* SC_Class_Render(SCClass* Self, FastString* Fs_in);

void SC_Class_RenderSaveable(SCClass* Self, FastString* Fs);

bool SC_Class_RenderSaveableSub(SCClass* Self, FastString* Fs);

void SC_Class_SortProperties(SCClass* Self);

SCDecl* SC_Class_SortPropHelper(SCClass* Self);

void SC_Class_StartupSaver(SCClass* Self, JB_String* Name);

JB_String* SC_Class_StructName(SCClass* Self);

bool SC_Class_EqualsName(SCClass* Self, JB_String* Name, bool Aware);

bool SC_Class_EqualsType(SCClass* Self, SCNodeType D, bool Aware);

bool SC_Class_SyntaxIs(SCClass* Self, ClassInfo Cls);

void SC_Class_SyntaxIsSet(SCClass* Self, ClassInfo Cls, bool Value);

void SC_Class_TaskProperties(SCClass* Self);

bool SC_Class_TestBanned(SCClass* Self);

void SC_Class_TryAddToProject(SCClass* Self);

void SC_Class_WriteStructOrUnion(SCClass* Self, FastStringCpp* Fs);

SCNode* SC_Class__DataType(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCModule* SC_Class__DataTypeSub(Message* Node, SCNode* Parent, Message* ErrPlace, JB_String* ForInterface, SCNodeType BaseType);

SCNode* SC_Class__ExtendOneFunc(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__GetDefault(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__GetFalse(Message* Node, SCNode* Name_space, Message* ErrPlace);

JB_String* SC_Class__LoadClassName(Message* Node);

SCNode* SC_Class__LoadSyntax(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__NeuClass(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCClass* SC_Class__NeuClassSub(Message* Node, SCNode* Parent, Message* ErrPlace, JB_String* ForInterface, SCNodeType Base);

SCNode* SC_Class__NeuRole(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__NewInnerClass(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__NewStruct(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__ProcessAs(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCFunction* SC_Class__ProcessExtend(Message* C, bool PreferClass, SCModule* M);

void SC_Class__ProcessExtendOld(Message* C, bool PreferClass);

SCNode* SC_Class__SetSize(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__StoreExtend(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__StoreExtendModule(Message* Node, SCNode* Name_space, Message* ErrPlace);



// JB_SCFunction
void SC_Func_AddConstructorReturn(SCFunction* Self, Message* Prms);

void SC_Func_AddConstructorReturn2(SCFunction* Self);

void SC_Func_AddSelfPrm(SCFunction* Self, SCClass* Cls);

void SC_Func_AddSelfToFunc(SCFunction* Self, SCClass* Cls, SCNode* Space);

void SC_Func_AnalyseRefs(SCFunction* Self, Array* List);

int SC_Func_ApparantArgCount(SCFunction* Self);

SCFunction* SC_Func_ArgsMatch(SCFunction* Self, SCDecl* Base, SCNode* Name_space, SCParamArray* Incoming, int Options);

SCFunction* SC_Func_ArgsMatch1(SCFunction* Self, SCDecl* Base, SCNode* Name_space, SCParamArray* Incoming, int Cast);

SCFunction* SC_Func_ArgsMatch2(SCFunction* Self, SCDecl* Base, int TypeCast, SCNode* Name_space, SCParamArray* Incoming);

int SC_Func_ArgsMatch3(SCFunction* Self, int TypeCast, SCDecl* Base, bool ThisAlter, SCNode* Name_space, SCParamArray* Incoming);

bool SC_Func_Borked(SCFunction* Self);

void SC_Func_BuildConstructorDestructor(SCFunction* Self);

void SC_Func_CallParents(SCFunction* Self);

void SC_Func_CallSuperMem(SCFunction* Self, SCFunction* Fn);

bool SC_Func_CanBuildConstructor(SCFunction* Self);

bool SC_Func_CanCompare(SCFunction* Self, SCDecl* Against);

bool SC_Func_CanLibLoad(SCFunction* Self);

bool SC_Func_CanLinkTo(SCFunction* Self, SCNode* To);

bool SC_Func_CanNil(SCFunction* Self);

void SC_Func_CheckConstructorAndDestructor(SCFunction* Self, Message* Root, bool IsConstructor);

void SC_Func_CheckNotBadName(SCFunction* Self);

void SC_Func_CheckReturnValue(SCFunction* Self, Message* Msg);

void SC_Func_Cleanupfunc(SCFunction* Self, Message* S);

void SC_Func_CollectDeclsParams(SCFunction* Self, Message* Prms, SCNode* AddToSpace);

void SC_Func_CollectLinks(SCFunction* Self, JB_Object* Obj, bool InBranch);

bool SC_Func_CollectReturnAsReal(SCFunction* Self);

SCFunction* SC_Func_ConOrDesForCall(SCFunction* Self, SCClass* C, bool IsConstructor, int Task);

SCFunction* SC_Func_Constructor(SCFunction* Self, Message* Msg);

Message* SC_Func_ConstructorLinePlace(SCFunction* Self);

void SC_Func_CopyParams(SCFunction* Self, Message* List);

Message* SC_Func_CountCallsToParentAlloc(SCFunction* Self, Message* Root);

int SC_Func_CreateTypeCast(SCFunction* Self, SCDecl* MyType, Message* Exp, int Loss);

void SC_Func_DeclsProtoCleanup(SCFunction* Self, SCClass* fpType, Message* Ch0, bool AssumeSelf, bool Late, Message* Route);

SCDecl* SC_Func_DeclsProtoTypeAdd(SCFunction* Self, SCClass* fpType);

void SC_Func_DeclsPrototypeClass(SCFunction* Self, Message* Ch0);

void SC_Func_DeclsPrototypeInterface(SCFunction* Self, Message* Ch0, SCClass* fpType, bool Late);

JB_String* SC_Func_Describe(SCFunction* Self, FastString* Fs_in);

void SC_Func_DescribeParamFail(SCFunction* Self, SCParamArray* Params, int Bad);

void SC_Func_Destructor(SCFunction* Self);

SCFunction* SC_Func_Disambiguate(SCFunction* Self, Message* Src);

void SC_Func_DoLinkBoth(SCFunction* Self, SCNode* To);

void SC_Func_DoLinkTo(SCFunction* Self, SCNode* To);

void SC_Func_DontWantSameReturnType(SCFunction* Self, SCFunction* F);

bool SC_Func_DoRefs(SCFunction* Self);

void SC_Func_DotFuncToNormalFunc(SCFunction* Self, Message* Dot);

bool SC_Func_EqualOrMoreSpecific(SCFunction* Self, SCFunction* F);

JB_String* SC_Func_ExportNameBuilder(SCFunction* Self, JB_String* CppPart);

void SC_Func_FillInDestructor(SCFunction* Self);

void SC_Func_FillInMissingConstructorDefaults(SCFunction* Self, Message* Root, Message* AfterHere);

void SC_Func_FillInSaver(SCFunction* Self, JB_String* Name);

Message* SC_Func_FindCallParents(SCFunction* Self);

Message* SC_Func_FindCppWrapperFunc(SCFunction* Self, Message* Place);

int SC_Func_FindDepths(SCFunction* Self);

void SC_Func_FixCnj(SCFunction* Self, Message* Exp);

void SC_Func_FixCnjSub(SCFunction* Self, Message* Exp);

void SC_Func_FLookupSet(SCFunction* Self, SCNode* Value);

bool SC_Func_FoundOneCpp(SCFunction* Self, JB_String* N);

void SC_Func_FuncDecls(SCFunction* Self);

bool SC_Func_HiderMatch(SCFunction* Self, bool IsAssigns);

void SC_Func_Init_Sub(SCFunction* Self, Message* Node, SCNode* Name_space);

SCObject* SC_Func_InsertIn(SCFunction* Self, SCNode* Parent, JB_String* Name);

bool SC_Func_IsAllocOrNew(SCFunction* Self);

bool SC_Func_IsARealSpdFunc(SCFunction* Self);

bool SC_Func_IsBehaviour(SCFunction* Self);

bool SC_Func_IsConstructorOnModule(SCFunction* Self, SCFunction* Old);

void SC_Func_IsCppInBuiltSet(SCFunction* Self, int Value);

bool SC_Func_IsReal(SCFunction* Self);

Message* SC_Func_IsSimpleCast(SCFunction* Self);

bool SC_Func_IsUnused(SCFunction* Self);

SCFunction* SC_Func_Last(SCFunction* Self);

SCDecl* SC_Func_MacroFix(SCFunction* Self, SCDecl* Contains, SCNode* Name_space, SCParamArray* Incoming);

void SC_Func_MakeMacro(SCFunction* Self, Message* Arg);

void SC_Func_MakeNilChecker(SCFunction* Self, Message* Msg);

void SC_Func_MakeParamsReal(SCFunction* Self);

JB_String* SC_Func_MakeProtoClassName(SCFunction* Self, JB_String* Start);

void SC_Func_MarkRecursive(SCFunction* Self, SCFunction* EndAt);

Message* SC_Func_NewDefaultRel(SCFunction* Self, Message* Place, SCDecl* D);

void SC_Func_NilSelff(SCFunction* Self, Message* Where, NilState V);

SCFunction* SC_Func_ParamlessConstructor(SCFunction* Self);

JB_String* SC_Func_ParamUniquer(SCFunction* Self, JB_String* S);

JB_String* SC_Func_ParentName(SCFunction* Self);

bool SC_Func_ParseName(SCFunction* Self, Message* Node);

void SC_Func_PreProcessExpects(SCFunction* Self);

void SC_Func_PreRead(SCFunction* Self, Message* Arg);

Message* SC_Func_Prms(SCFunction* Self);

void SC_Func_ProtoExportName(SCFunction* Self);

void SC_Func_ReachedDetect(SCFunction* Self);

bool SC_Func_ReachFunc(SCFunction* Self, SCNode* From);

void SC_Func_RefFunc(SCFunction* Self, Message* Prm, Message* After);

DataTypeCode SC_Func_RegType(SCFunction* Self);

JB_String* SC_Func_Render(SCFunction* Self, FastString* Fs_in);

JB_String* SC_Func_RenderName(SCFunction* Self, FastString* Fs_in);

JB_String* SC_Func_RenderParams(SCFunction* Self, bool ForErrors, FastString* Fs_in);

JB_String* SC_Func_RenderTitle(SCFunction* Self, bool ForErrors, FastString* Fs_in);

SCDecl* SC_Func_Self(SCFunction* Self);

void SC_Func_SetBlindCasts(SCFunction* Self, SCNode* Name_space);

Message* SC_Func_SourceArg(SCFunction* Self);

bool SC_Func_SyntaxEquals(SCFunction* Self, JB_String* Name, bool Aware);

bool SC_Func_SyntaxIs(SCFunction* Self, FunctionType K);

void SC_Func_SyntaxIsSet(SCFunction* Self, FunctionType K, bool Value);

void SC_Func_Transform(SCFunction* Self);

void SC_Func_TranStrings(SCFunction* Self);

void SC_Func_TryAdd(SCFunction* Self, SCNode* B);

SCFunction* SC_Func_TryKeepBetter(SCFunction* Self, int OldMatch, SCFunction* F, int Match);

bool SC_Func_Update_Source(SCFunction* Self, int Start, JB_String* Text, SCFile* Myfile, SCObject* Orig);

bool SC_Func_UpdateSourceSub(SCFunction* Self, Message* Src);

bool SC_Func_UseCppName(SCFunction* Self, JB_String* CppName);

bool SC_Func_UseExportWrapper(SCFunction* Self, JB_String* CppWrapper);

void SC_Func_ValidateSaver(SCFunction* Self, JB_String* Name);

int SC_Func_VisibleArgs(SCFunction* Self);

void SC_Func_WantAs(SCFunction* Self, NilState NS);

JB_String* SC_Func_WrappedName(SCFunction* Self);

Message* SC_Func__AlterPostCond(Message* PostCond, Message* IterPostCond, Message* NodeSrc);

Message* SC_Func__ArgToFunc(JB_String* NewName, Message* Params, Message* Arg);

bool SC_Func__CanKeepAsSource(Message* List, Message* Arg, SCDecl* D);

bool SC_Func__CanKeepAsValue(SCIterator* Iter, Message* Arg, SCDecl* Dcl, Message* Value);

void SC_Func__FastStringOpt(Message* S, SCNode* Name_space);

Message* SC_Func__GetFileString(Message* Msg, JB_String* Name);

bool SC_Func__InBuiltFunc(Message* Self, JB_String* Name);

int SC_Func__Init_();

int SC_Func__InitCode_();

SCNode* SC_Func__NeuLibrary(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Func__NeuMain(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Func__NeuSyx(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Func__NewConstructor(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Func__NewCppWrapper(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Func__NewDestructor(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Func__NewFunc(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCFunction* SC_Func__NewFuncSub(Message* Node, SCNode* Name_space);

SCNode* SC_Func__NewHelper(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Func__NewHider(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Func__NewMacro(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Func__NewProtoType(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCModule* SC_Func__NewProtoTypeSub(Message* Node, SCNode* Parent, Message* ErrPlace, JB_String* ForInterface);

SCNode* SC_Func__NewRender(Message* Node, SCNode* Name_space, Message* ErrPlace);

void SC_Func__ObjectifyString(Message* Msg);

void SC_Func__String_Expand(Message* Msg, SCFunction* Fn);

Message* SC_Func__TypedTempMoveOut(Message* Msg, JB_String* Name);

Message* SC_Func__TempMoveOut(Message* Msg, Message* Place);

SCDecl* SC_Func__Tran_AfterRel(Message* Msg, SCNode* Name_space, Message* Side, bool After);

void SC_Func__Tran_All(SCFunction* Fn, Message* S, SCNode* P);

void SC_Func__Tran_Array(Message* S, SCNode* Name_space);

void SC_Func__Tran_Beep(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_BlindCasts(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_CppRefs(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Debugger(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Deprecate(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Description(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_DoAt(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Else(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Expect(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Fails(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_For(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_ForStart(Message* Arg, Message* Index, SCNode* P);

void SC_Func__Tran_ForSub(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_FuncTable(Message* Msg);

void SC_Func__Tran_If(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Ifn(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_IfSub(Message* Node, SCNode* Name_space);

void SC_Func__Tran_Isa(Message* S, SCNode* P);

void SC_Func__Tran_Log(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_NotAllowed(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Once(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_OneIsa(Message* Isa_f, Message* Arg, SCNode* Space);

void SC_Func__Tran_Print(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Problem(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Quit(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Rejoin(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Render(Message* Msg, SCClass* Cls);

bool SC_Func__Tran_RenderSub(Message* Msg, SCClass* Cls);

Message* SC_Func__Tran_Result(SCFunction* F);

void SC_Func__Tran_ResultFinish(SCFunction* F, Message* R_z, SCNode* Space);

void SC_Func__Tran_Return(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Sdt(Message* Exp);

void SC_Func__Tran_Strings(Message* Start, SCFunction* Fn);

void SC_Func__Tran_Swap(SCFunction* Fn, Message* Node, SCNode* Name_space);

Message* SC_Func__Tran_Syx(Message* Msg);

void SC_Func__Tran_Temporal(SCFunction* Fn, Message* S, SCNode* Name_space);

void SC_Func__Tran_Using(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Visible(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_While(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__TransformAll();



// JB_SCModule
void SC_Mod_AddDelayedInit(SCModule* Self, Message* Src, Message* Dest, JB_String* Fn_name);

void SC_Mod_AddInterfaceToTable(SCModule* Self, SCClass* TableCls);

void SC_Mod_AddModuleToFunc(SCModule* Self, SCNode* Space);

void SC_Mod_BaseDecls(SCModule* Self);

Message* SC_Mod_BuildInitArg(SCModule* Self);

SCModule* SC_Mod_Constructor(SCModule* Self);

JB_String* SC_Mod_CppPath(SCModule* Self);

void SC_Mod_DelayedInitFuncTransform(SCModule* Self);

void SC_Mod_Destructor(SCModule* Self);

SCObject* SC_Mod_GetTheNewer(SCModule* Self);

void SC_Mod_GlobalsFix(SCModule* Self);

bool SC_Mod_HasActualCode(SCModule* Self, Message* Arg);

void SC_Mod_InitDecls(SCModule* Self);

bool SC_Mod_IsProperModule(SCModule* Self);

void SC_Mod_LoadInitFunc(SCModule* Self);

void SC_Mod_LoadInitFuncSub(SCModule* Self, Message* Init, JB_String* Name);

void SC_Mod_LoadModule(SCModule* Self, Message* Node);

void SC_Mod_MoveToInitFunc(SCModule* Self, Message* C, bool Visible);

SCFunction* SC_Mod_NewModuleFunc(SCModule* Self, Message* Src);

SCModule* SC_Mod_OneOrOther(SCModule* Self, SCModule* B);

JB_String* SC_Mod_Render(SCModule* Self, FastString* Fs_in);

JB_String* SC_Mod_SafeName(SCModule* Self);

SCModule* SC_Mod_SuperMod(SCModule* Self);

bool SC_Mod_TryInit(SCModule* Self, Array* Req);

SCNode* SC_Mod__ConstantCollector(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Mod__DoInitAfter(Message* Node, SCNode* Name_space, Message* ErrPlace);

int SC_Mod__Init_();

int SC_Mod__InitCode_();

SCNode* SC_Mod__NeuModule(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCModule* SC_Mod__NewContainer(JB_String* S);



// JB_config
Message* JB_config_ConfFirst(Message* Self);

bool JB_config_Save(Message* Self);



// JB_interface
bool SC_Task_LessThan3_interface_SyntaxCall(JB_Task* Self, int I);



// JB_LessThan3
bool SC_Task_LessThan3_run(LessThan3* Self, int I);

inline bool JB_ErrorInt_SyntaxCast(ErrorInt Self);

inline bool JB_ErrorMarker_SyntaxCast(ErrorMarker Self);

inline bool JB_FailableInt_SyntaxCast(FailableInt Self);

inline bool JB_FastBuff_AppendU8(FastBuff* Self, byte V);

inline bool JB_File_SyntaxCast(JB_File* Self);

inline bool JB_Ind_SyntaxCast(Ind Self);

inline Syntax JB_Msg_Func(Message* Self);

inline JB_String* JB_Msg_Name(Message* Self);

inline JB_String* JB_Msg_Name_(Message* Self);

inline int JB_Sel_ID(Selector* Self);

inline JB_String* JB_Tk__SyntaxAccess(int S, int E, Syntax F);

inline bool JB_int64_OperatorInRange(int64 Self, int64 D);

inline bool JB_int_OperatorInRange(int Self, int D);

inline JB_String* SC_Named_Name(SCNamed* Self);

inline bool SC_PA_SyntaxCast(SCParamArray* Self);

inline void SC_Pac_CloseVars(ASMState* Self, int Old, bool DeclsToo);

inline void SC_nil_SetAllNil(ArchonPurger* Self, NilRecord Dest);

inline NilRecord SC_nil_Value(ArchonPurger* Self);

inline bool JB_Array_SyntaxCast(Array* Self);

inline JB_String* JB_CP_SyntaxCast(Codepoint Self);

inline bool JB_Err2_SyntaxCast(ErrorInt2 Self);

inline JB_String* JB_FS_SyntaxCast(FastString* Self);

inline JB_String* JB_Object___Render__(JB_Object* Self, FastString* Fs_in);

inline void JB_Sav___LoadProperties__(Saveable* Self, ObjectLoader* Loader);

inline void JB_Sav___SaveCollect__(Saveable* Self, ObjectSaver* Saver);

inline void JB_Sav___SaveWrite__(Saveable* Self, ObjectSaver* Saver);

inline JB_StringC* JB_Str_CastZero(JB_String* Self);

inline _cstring JB_Str_SyntaxCast(JB_StringC* Self);

inline int JB_uint64_LELength(uint64 Self);

inline bool SC_NilTest_SyntaxCast(NilTest* Self);

inline bool SC_Reg_FourBytes(AsmReg Self);

inline bool SC_Reg_IsBig(AsmReg Self);

inline bool SC_Reg_IsFloat(AsmReg Self);

inline bool SC_Reg_IsInt(AsmReg Self);

inline NilState SC_nil_SetNilness(ArchonPurger* Self, SCDecl* D, NilState New);

inline void SC_nil__DeclKill();

inline NilState SC_nil__Jump(Message* Msg, NilCheckMode Test);

inline NilRecord SC_nil__Value();

inline bool JB_Safe_SyntaxCast(JB_String* Self);

inline bool SC_Decl_IsUnknownParam(SCDecl* Self);

inline AsmReg SC_Pac_Get(ASMState* Self, Message* Exp, AsmReg Dest);

inline uint64* SC_Pac_GetConst(ASMState* Self, AsmReg A);

inline bool SC_Reg_SyntaxCast(AsmReg Self);

inline int SC_Reg_ToInt(AsmReg Self);

inline NilRecord SC_nil__EndBlock();

inline void SC_Msg_AddValue(Message* Self, SCFunction* F);

inline FatASM* SC_Pac_AddASM0(ASMState* Self, int SM, Message* Dbg);

inline FatASM* SC_Pac_AddASM1(ASMState* Self, int SM, Message* Dbg, int A);

inline FatASM* SC_Pac_AddASM2(ASMState* Self, int SM, Message* Dbg, int A, int B);

inline FatASM* SC_Pac_AddASM3(ASMState* Self, int SM, Message* Dbg, int A, int B, int C);

inline FatASM* SC_Pac_AddASM4(ASMState* Self, int SM, Message* Dbg, int A, int B, int C, int D);

inline FatASM* SC_Pac_AddASM5(ASMState* Self, int SM, Message* Dbg, int A, int B, int C, int D, int E);

inline SCDecl* SC_TypeOfSwiz(Message* Exp, SCNode* Name_space, Message* Side, SCDecl* class_Space);


//// HEADER Inlines.h
inline bool JB_ErrorInt_SyntaxCast(ErrorInt Self) {
	return Self == 0;
}

inline bool JB_ErrorMarker_SyntaxCast(ErrorMarker Self) {
	return JB_StdErr->ErrorCount == Self;
}

inline bool JB_FailableInt_SyntaxCast(FailableInt Self) {
	return Self != kJB__FailableInt_Fail;
}

inline bool JB_FastBuff_AppendU8(FastBuff* Self, byte V) {
	Self->Curr++[0] = V;
	return Self->Curr >= Self->End;
}

inline bool JB_File_SyntaxCast(JB_File* Self) {
	return Self != nil;
}

inline bool JB_Ind_SyntaxCast(Ind Self) {
	return Self >= 0;
}

inline Syntax JB_Msg_Func(Message* Self) {
	if (Self) {
		return Self->Func;
	}
	return nil;
}

inline JB_String* JB_Msg_Name(Message* Self) {
	if (Self) {
		return Self->Name;
	}
	return JB_LUB[0];
}

inline JB_String* JB_Msg_Name_(Message* Self) {
	if (Self) {
		return Self->Name;
	}
	return JB_LUB[0];
}

inline int JB_Sel_ID(Selector* Self) {
	if (Self) {
		return Self->ID;
	}
	return 0;
}

inline JB_String* JB_Tk__SyntaxAccess(int S, int E, Syntax F) {
	return (JB__Tk_Splitter)(S, E, F);
}

inline bool JB_int64_OperatorInRange(int64 Self, int64 D) {
	return (((uint64)Self) < ((uint64)D));
}

inline bool JB_int_OperatorInRange(int Self, int D) {
	if (D > 0) {
		return (((uint)Self) < ((uint)D));
	}
	return false;
}

inline JB_String* SC_Named_Name(SCNamed* Self) {
	if (Self) {
		return Self->Name;
	}
	return JB_LUB[274];
}

inline bool SC_PA_SyntaxCast(SCParamArray* Self) {
	return (Self != nil) and Self->HasProperParams;
}

inline void SC_Pac_CloseVars(ASMState* Self, int Old, bool DeclsToo) {
	if (DeclsToo) {
		Self->VDecls = (Old & 255);
	}
	Self->VTmps = (((uint)Old) >> 8);
}

inline void SC_nil_SetAllNil(ArchonPurger* Self, NilRecord Dest) {
	Self->Neel[0] = (Dest & Self->Realnesses);
}

inline NilRecord SC_nil_Value(ArchonPurger* Self) {
	return Self->Neel[0];
}

inline bool JB_Array_SyntaxCast(Array* Self) {
	return JB_Array_Size(Self) > 0;
}

inline JB_String* JB_CP_SyntaxCast(Codepoint Self) {
	return JB_Str_ChrUTF8(Self);
}

inline bool JB_Err2_SyntaxCast(ErrorInt2 Self) {
	return (JB_ivec2_Equals2(Self, ivec2{0, 0}, false));
}

inline JB_String* JB_FS_SyntaxCast(FastString* Self) {
	return JB_FS_GetResult(Self);
}

inline JB_String* JB_Object___Render__(JB_Object* Self, FastString* Fs_in) {
	Object_Behaviour* Table = ((Object_Behaviour*)JB_ObjClassBehaviours(Self));
	return (Table->render)(Self, Fs_in);
}

inline void JB_Sav___LoadProperties__(Saveable* Self, ObjectLoader* Loader) {
	Saveable_Behaviour* Table = ((Saveable_Behaviour*)JB_ObjClassBehaviours(Self));
	return (Table->loadproperties)(Self, Loader);
}

inline void JB_Sav___SaveCollect__(Saveable* Self, ObjectSaver* Saver) {
	Saveable_Behaviour* Table = ((Saveable_Behaviour*)JB_ObjClassBehaviours(Self));
	return (Table->savecollect)(Self, Saver);
}

inline void JB_Sav___SaveWrite__(Saveable* Self, ObjectSaver* Saver) {
	Saveable_Behaviour* Table = ((Saveable_Behaviour*)JB_ObjClassBehaviours(Self));
	return (Table->savewrite)(Self, Saver);
}

inline JB_StringC* JB_Str_CastZero(JB_String* Self) {
	return JB_Str_MakeC(Self);
}

inline _cstring JB_Str_SyntaxCast(JB_StringC* Self) {
	return JB_Str_CString(Self);
}

inline int JB_uint64_LELength(uint64 Self) {
	return (JB_int_OperatorMax(JB_Int_Log2(((int)Self)), 0)) >> 3;
}

inline bool SC_NilTest_SyntaxCast(NilTest* Self) {
	return (Self != nil) and JB_Str_Exists(Self->V2);
}

inline bool SC_Reg_FourBytes(AsmReg Self) {
	return JB_TC__Shift(((DataTypeCode)Self)) == 2;
}

inline bool SC_Reg_IsBig(AsmReg Self) {
	return JB_TC__Shift(((DataTypeCode)Self)) == 3;
}

inline bool SC_Reg_IsFloat(AsmReg Self) {
	return JB_TC_IsFloat(((DataTypeCode)Self));
}

inline bool SC_Reg_IsInt(AsmReg Self) {
	return JB_TC_IsFloat(((DataTypeCode)Self));
}

inline NilState SC_nil_SetNilness(ArchonPurger* Self, SCDecl* D, NilState New) {
	NilRecorder* P = ((NilRecorder*)(Self->Neel));
	(SC_NRC_SyntaxCallSet((P), D->NilReg, New));
	return New;
}

inline void SC_nil__DeclKill() {
	if (!SC_nil_NestDepth((&SC__nil_T))) {
		SC__nil_T.RootReturned = true;
	}
	SC_nil_SetAllNil((&SC__nil_T), kSC__NilState_Basic);
}

inline NilState SC_nil__Jump(Message* Msg, NilCheckMode Test) {
	ASMtmp T = SC_Msg_ASMType(Msg);
	if (T) {
		return (SC__nil_NilTable[T])(Msg, Test);
	}
	T = ((ASMtmp)Msg->Func);
	(SC_Msg_ASMTypeSet(Msg, T));
	return (SC__nil_NilTable[T])(Msg, Test);
}

inline NilRecord SC_nil__Value() {
	return SC_nil_Value((&SC__nil_T));
}

inline bool JB_Safe_SyntaxCast(JB_String* Self) {
	return JB_Str_IsOK(Self);
}

inline bool SC_Decl_IsUnknownParam(SCDecl* Self) {
	return ((!SC_Decl_NilStated(Self))) and (SC_Decl_SyntaxIs(Self, kSC__SCDeclInfo_Param));
}

inline AsmReg SC_Pac_Get(ASMState* Self, Message* Exp, AsmReg Dest) {
	AsmReg Rz = ((AsmReg)0);
	ASMtmp T = SC_Msg_ASMType(Exp);
	fn_asm Fn = SC_fn_asm_table[T];
	if (!SC_Reg_SyntaxIs(Dest, kSC__Reg_StayOpen)) {
		debugger;
		// Can't close declarations in args!;
		int OV = SC_Pac_OpenVars(Self);
		Rz = (Fn)(Self, Exp, Dest, 0);
		SC_Pac_CloseVars(Self, OV, ((bool)SC_Reg_Reg(Dest)));
	}
	 else {
		Rz = (Fn)(Self, Exp, Dest, 0);
	}
	return Rz;
}

inline uint64* SC_Pac_GetConst(ASMState* Self, AsmReg A) {
	return (&Self->Consts[SC_Reg_Reg(A)]);
}

inline bool SC_Reg_SyntaxCast(AsmReg Self) {
	return ((bool)SC_Reg_Reg(Self));
}

inline int SC_Reg_ToInt(AsmReg Self) {
	return SC_Reg_Reg(Self);
}

inline NilRecord SC_nil__EndBlock() {
	NilRecord Rz = 0;
	Rz = SC_nil__Value();
	SC_nil_SetAllNil((&SC__nil_T), kSC__NilState_Basic);
	return Rz;
}

inline void SC_Msg_AddValue(Message* Self, SCFunction* F) {
	if (!JB_Ring_HasChildCount(Self, 2)) {
		if (true) {
			Message* __varf1 = F->Source;
			MessagePosition _usingf0 = JB_Msg_SyntaxUsing(__varf1);
			JB_Tree_SyntaxAppend(Self, (JB_Syx_Msg(kJB_SyxThg, JB_LUB[1267])));
			JB_MsgPos_SyntaxUsingComplete((&_usingf0), __varf1);
			JB_MsgPos_Destructor((&_usingf0));
		}
	}
}

inline FatASM* SC_Pac_AddASM0(ASMState* Self, int SM, Message* Dbg) {
	return SC_Pac_RequestOp(Self, SM, Dbg);
}

inline FatASM* SC_Pac_AddASM1(ASMState* Self, int SM, Message* Dbg, int A) {
	FatASM* Rz = nil;
	Rz = SC_Pac_RequestOp(Self, SM, Dbg);
	Rz->R[0] = A;
	return Rz;
}

inline FatASM* SC_Pac_AddASM2(ASMState* Self, int SM, Message* Dbg, int A, int B) {
	FatASM* Rz = nil;
	Rz = SC_Pac_RequestOp(Self, SM, Dbg);
	Rz->R[0] = A;
	Rz->R[1] = B;
	return Rz;
}

inline FatASM* SC_Pac_AddASM3(ASMState* Self, int SM, Message* Dbg, int A, int B, int C) {
	FatASM* Rz = nil;
	Rz = SC_Pac_RequestOp(Self, SM, Dbg);
	Rz->R[0] = A;
	Rz->R[1] = B;
	Rz->R[2] = C;
	return Rz;
}

inline FatASM* SC_Pac_AddASM4(ASMState* Self, int SM, Message* Dbg, int A, int B, int C, int D) {
	FatASM* Rz = nil;
	Rz = SC_Pac_RequestOp(Self, SM, Dbg);
	Rz->R[0] = A;
	Rz->R[1] = B;
	Rz->R[2] = C;
	Rz->R[3] = D;
	return Rz;
}

inline FatASM* SC_Pac_AddASM5(ASMState* Self, int SM, Message* Dbg, int A, int B, int C, int D, int E) {
	FatASM* Rz = nil;
	Rz = SC_Pac_RequestOp(Self, SM, Dbg);
	Rz->R[0] = A;
	Rz->R[1] = B;
	Rz->R[2] = C;
	Rz->R[3] = D;
	Rz->R[4] = E;
	return Rz;
}

inline SCDecl* SC_TypeOfSwiz(Message* Exp, SCNode* Name_space, Message* Side, SCDecl* class_Space) {
	int W = SC_Class_NumericCount(class_Space->Type);
	if ((W > 1) and (!JB_Ring_HasChildren(((Message*)JB_Ring_Last(Exp))))) {
		int Swz = SC_Str_IsSwizzle(Exp->Name, W);
		if (Swz) {
			return SC_TypeOfSwizzle(Exp, class_Space, Name_space, Side, Swz);
		}
	}
	return nil;
}



}
#endif // __JB_H__
