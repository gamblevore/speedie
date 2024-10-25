

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

typedef uint64 ASMReg;

typedef u16 ASMType;

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

typedef double Float64;

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

typedef ivec4 ParserLineAndIndent;

typedef byte ProcessMode;

typedef byte ProcessOwnerMode;

typedef int SCBlockage;

typedef int SCDeclInfo;

typedef int SCNodeFindMode;

typedef int SCNodeInfo;

typedef byte SCNodeType;

typedef int SizeInt;

typedef byte Syntax;

typedef byte TaskState;

typedef int TerminalColor;

typedef int jbinLeaver;

typedef vec4 mat2;

typedef u16 ASMParam;

typedef ASM ASM_AddK;

typedef ASM ASM_Alloc;

typedef ASM ASM_BClear;

typedef ASM ASM_BFLD;

typedef ASM ASM_Bra;

typedef ASM ASM_BraBytes;

typedef ASM ASM_CNTC;

typedef ASM ASM_CmpB;

typedef ASM ASM_ConstStretchy;

typedef ASM ASM_Convert;

typedef ASM ASM_Div;

typedef ASM ASM_Div2;

typedef ASM ASM_Float;

typedef ASM ASM_FloatConst;

typedef ASM ASM_ForeignFunc;

typedef ASM ASM_Func;

typedef ASM ASM_HALT;

typedef ASM ASM_JCmpEq;

typedef ASM ASM_JCmpF;

typedef ASM ASM_JCmpI;

typedef ASM ASM_Jump;

typedef ASM ASM_Loop;

typedef ASM ASM_MemUtil;

typedef ASM ASM_MinMax;

typedef ASM ASM_REQ;

typedef ASM ASM_RET;

typedef ASM ASM_Read;

typedef ASM ASM_RefDecrMem;

typedef ASM ASM_RefSet;

typedef ASM ASM_RefSet2;

typedef ASM ASM_RefSet3;

typedef ASM ASM_RotateConst;

typedef ASM ASM_Shift;

typedef ASM ASM_Swap;

typedef ASM ASM_Table;

typedef ASM ASM_Tail;

typedef ASM ASM_Trap;

typedef ASM ASM_U0;

typedef ASM ASM_U1;

typedef ASM ASM_U2;

typedef ASM ASM_U3;

typedef ASM ASM_U4;

typedef ASM ASM_VecMix;

typedef ASM ASM_Write;

typedef Date Duration;

typedef Date HumanDate;

struct ArchonPurger;

struct ArgArrayCounter;

struct CompressionStats;

struct FakeJBString;

struct FastBuff;

struct FatASM;

struct FatRange;

struct FloatRange;

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

struct Random;

struct RangeCoderItem;

struct RetroFloat;

struct SpeedTester;

struct StringDigitIterator;

struct StringLengthSplit;

struct StructSaveTest;

struct ASMState;

struct ByteMap_Behaviour;

struct Charset_Behaviour;

struct CppRefs_Behaviour;

struct Cpp_Export_Behaviour;

struct DataObject_Behaviour;

struct DictionaryReader_Behaviour;

struct ErrorReceiver_Behaviour;

struct FastString_Behaviour;

struct FixedDict_Behaviour;

struct FlowControl_Behaviour;

struct Instruction_Behaviour;

struct LeakTester_Behaviour;

struct Macro_Behaviour;

struct MemoryLayer_Behaviour;

struct Memory_Behaviour;

struct ProcessOwner_Behaviour;

struct RefTest_Behaviour;

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

struct MessageID_Behaviour;

struct Message_Behaviour;

struct RangeCoder_Behaviour;

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

struct SCBetterNode_Behaviour;

struct SCClass_Behaviour;

struct SCFunction_Behaviour;

struct SCModule_Behaviour;

struct JB_Object;

struct CppRefs;

struct Cpp_Export;

struct DTWrap;

struct JB_ErrorReceiver;

struct FixedDict;

struct FlowControl;

struct Instruction;

struct LeakTester;

struct Macro;

struct MWrap;

struct RefTest;

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

struct autoitem;

struct xC2xB5Form;

struct FuncInASM;

struct FastStringCpp;

struct FastString;

struct MaterialsLol;

struct FastString;

struct SCNamed;

struct SavingTest;

struct JB_String;

struct JB_File;

struct JB_File;

struct Message;

struct MessageID;

struct Dictionary;

struct RangeCoder;

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

struct SCBetterNode;

struct Message;

struct JB_Task;

struct LessThan3;

struct SCClass;

struct SCFunction;

struct SCModule;

struct Task2;

typedef ASM* (*ASM_Encoder)(FatASM* self, ASM* Curr, ASM* After, int64 ExtraInfo);

typedef SCNode* (*FP_CollectFunc)(Message* node, SCNode* name_space, Message* ErrPlace);

typedef SCObject* (*FP_ExprResolver)(Message* Exp, SCNode* name_space, Message* Side);

typedef bool (*Fn_µOpt)(FatASM* self, FatASM* P, FatASM* N);

typedef NilState (*FP_NilTrackerFn)(Message* msg, NilCheckMode Test);

typedef Message* (*FP_ParseHandler)(int Start, Message* Parent);

typedef void (*FP_SaverLoadClass)(JB_Class* cls, int8* Data);

typedef bool (*FP_ShellOption)(JB_String* Name, JB_String* Value, FastString* Purpose);

typedef int (*FP_SorterComparer)(JB_Object* a, JB_Object* b);

typedef bool (*FP_SorterComparerBool)(JB_Object* a, JB_Object* b);

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

typedef void (*fn_ASMConstifier)(FatASM* self, ASMReg L, ASMReg R);

typedef ASMReg (*fn_OpASM)(ASMState* self, ASMReg Dest, ASMReg L, ASMReg R, Message* exp);

typedef ASMReg (*fn_asm)(ASMState* self, Message* exp, ASMReg Dest, int Mode);

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
	Duration Duration;
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
	ASMReg Info;
	Message* Msg;
	uint64 Const;
	uint R[7];
	uint ASMIndex;
	u16 BlockNum;
	u16 ParentBlock;
	u16 RefCount;
	byte Op;
	byte JumpReg;
};

struct FatRange {
	FatASM* Start;
	FatASM* After;
};

struct IntDownRange {
	int From;
	int To;
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

struct Random {
	uint64 Store;
	uint64 State;
};

struct StructSaveTest {
	Saveable* Sav;
	int64 Intt;
	JB_String* Str;
};

struct ASMState {
	u16 BlockNum;
	u16 ParentBlock;
	byte VDecls;
	byte VTmps;
	DataTypeCode ReturnASM;
	bool OK;
	bool Inited;
	FuncInASM* Out;
	FatASM* FuncStart;
	FatASM* LastProgress;
	FatASM* Start;
	FatASM* Curr;
	FatASM* End;
	FatASM Zero;
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
	Array* Disturbs;
	bool Owned;
);

struct Cpp_Export_Behaviour: Object_Behaviour {
};

JBClass ( Cpp_Export , JB_Object , 
	FastStringCpp* ModuleProperties;
	Array* Outputs_cpp;
	Array* Outputs_h;
	FastStringCpp* T;
	FastStringCpp* AllTypes;
	FastStringCpp* TypesProj;
	FastStringCpp* HeaderProj;
	FastStringCpp* Inlines;
	FastStringCpp* Syxes;
);

struct DataObject_Behaviour: Object_Behaviour {
};

JBClass ( DTWrap , JB_Object , 
	DataTypeCode DataType;
	int64 PrivValue;
	byte DeathAction;
);

struct DictionaryReader_Behaviour: Object_Behaviour {
};

struct ErrorReceiver_Behaviour: Object_Behaviour {
};

JBClass ( JB_ErrorReceiver , JB_Object , 
	int MaxErrors;
	JB_String* Source;
	JB_Object* _LogObj;
	JB_Error* Errors;
	int LowerErrorsTo;
	int MaxProblems;
	int ErrorCount;
	int WarnCount;
	int ProblemCount;
	bool BlockErrors;
	FP_fnErrorLogger _LogFunc;
);

struct FastString_Behaviour: Object_Behaviour {
};

struct FlowControl_Behaviour: Object_Behaviour {
};

JBClass ( FlowControl , JB_Object , 
	bool CanDoErrors;
	StringReader* ReadInput;
	FastString* Write;
	FastBuff Buff;
);

struct Instruction_Behaviour: Object_Behaviour {
};

JBClass ( Instruction , JB_Object , 
	byte OpCode;
	JB_String* Name;
	xC2xB5Form* Sizes;
	JB_String* FormName;
	byte aType;
	byte PCount;
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
	Message* _Parsed;
	JB_String* Input;
);

struct Memory_Behaviour: Object_Behaviour {
};

JBClass ( MWrap , JB_Object , 
	int BufferSize;
	byte* _Ptr;
	int Length;
	u16 ItemSize;
	byte DeathAction;
);

struct MemoryLayer_Behaviour: Object_Behaviour {
};

struct ProcessOwner_Behaviour: Object_Behaviour {
};

struct RefTest_Behaviour: Object_Behaviour {
};

JBClass ( RefTest , JB_Object , 
	JB_String* s;
);

struct SCImport_Behaviour: Object_Behaviour {
};

JBClass ( SCImport , JB_Object , 
	int Depth;
	Dictionary* Resources;
	SCModule* Mod;
	JB_File* Where;
	SCFile* Conf;
	JB_MemoryLayer* DeclLayer;
	Array* Files;
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
	SCOperator* Opposite;
	JB_String* Name;
	JB_String* CompOp;
	JB_String* CompParam;
	JB_String* FuncName;
	OpMode Kind;
	fn_OpASM ASM;
);

struct SCParamArray_Behaviour: Object_Behaviour {
};

JBClass ( SCParamArray , JB_Object , 
	s16 Size;
	SCClass* Cls;
	Message* Exp;
	s16 ErrCount;
	bool AllowSelfToConstructor;
	bool Found;
	int8 FailedAt;
	bool HasSide;
	bool HasProperParams;
	bool IsDot;
	bool IsAddress;
	bool IsNotModule;
	bool IsSuper;
	bool IsSelf;
	Message* Items[8];
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
	Selector* Next;
	JB_String* Name;
);

struct String_Behaviour: Object_Behaviour {
};

struct StringFields_Behaviour: Object_Behaviour {
};

JBClass ( StringFields , JB_Object , 
	byte Sep;
	JB_String* Data;
);

struct StringReader_Behaviour: Object_Behaviour {
};

JBClass ( StringReader , JB_Object , 
	int Length;
	JB_Object* UserObj;
	JB_File* File;
	int StartFrom;
	int ChunkSize;
	bool _NoMoreChunks;
	FastBuff Data;
);

struct SyntaxObj_Behaviour: Object_Behaviour {
};

JBClass ( SyntaxObj , JB_Object , 
	Syntax ID;
	JB_String* Name;
	JB_String* LongName;
	FP_fpMsgRender RenderAddr;
	FP_fpMsgRender ExportAddr;
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
	ASMParam Params[7];
	Message* src;
	JB_String* Name;
	int RegForJump;
	int TotalBits;
	int Index;
	int Outputs;
);

struct xC2xB5Func_Behaviour: Object_Behaviour {
};

JBClass ( FuncInASM , JB_Object , 
	int Length;
	SCFunction* Fn;
	MWrap* Testing;
	FatASM* IR;
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
	int ABC[1];
	int Value;
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
	u16 Tag;
	u16 RangeLength;
	MsgParseFlags Flags;
	Syntax Func;
	byte Indent;
);

struct MessageID_Behaviour: StringShared_Behaviour {
};

JBClass ( MessageID , JB_StringShared , 
	int64 Frequency;
	int64 ID;
	JB_Object* Obj;
	int Position;
	Syntax Func;
);

struct SCDecl_Behaviour: SCNamed_Behaviour {
};

JBClass ( SCDecl , SCNamed , 
	SCClass* Type;
	uint64 ExportPosition;
	SCFunction* HiderFunc;
	JB_Object* IsLookupOnly;
	JB_String* StringData;
	SCDecl* Internal;
	Message* Default;
	SCDecl* Contains;
	SCDeclInfo Info;
	int C_Array;
	DataTypeCode DataType;
	byte NilAllocDepth;
	NilState NilDeclared;
	byte NilReg;
	byte PointerCount;
);

struct SCFile_Behaviour: File_Behaviour {
};

JBClass ( SCFile , JB_File , 
	Message* OrigAST;
	JB_String* ExportName;
	SCImport* Proj;
	Message* LiveAST;
	JB_String* FData;
	u16 FileNum;
	bool IsInternal;
);

struct SCIterator_Behaviour: SCNamed_Behaviour {
};

JBClass ( SCIterator , SCNamed , 
	SCClass* Parent;
	Array* Names;
	SCNodeRenamer* selfs;
	SCNodeRenamer* ValueRenamer;
	Message* Index;
	Message* LoopCond;
	Message* LoopEndCond;
	Message* Value;
	Message* Yield;
	Message* WhileLoop;
	bool OK;
);

struct SCNode_Behaviour: SCNamed_Behaviour {
};

JBClass ( SCNode , SCNamed , 
	SCImport* Project;
	Dictionary* Access;
	SCNode* MyReacher;
	SCNode* Parent;
);

struct SaverClassInfo_Behaviour: Array_Behaviour {
};

JBClass ( SaverClassInfo , Array , 
	int8* Data;
	SaverClassInfo* NextInfo;
	JB_Class* Cls;
);

struct SpdProcess_Behaviour: Process_Behaviour {
};

JBClass ( SpdProcess , ShellStream , 
	JB_StringC* _DebugName;
	PicoComms* Pico;
	FastString* Writer;
	int DiedCount;
	int DeathLimit;
	ProcessMode Mode;
	bool AlreadyWarnedDied;
	bool WeAreParent;
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
	Date When;
	JB_String* Path;
	JB_String* OriginalData;
	JB_String* StackTrace;
	Message* Node;
	Float64 Progress;
	ErrorFlags ErrorFlags;
	ErrorSeverity Severity;
);

struct SCArg_Behaviour: SCNode_Behaviour {
};

JBClass ( SCArg , SCNode , 
	SCFunction* ParentFunc;
	Message* TmpMovedOutFor;
	bool IsStatementExpr;
	bool IsClassArg;
);

struct SCBehaviour_Behaviour: SCNode_Behaviour {
};

JBClass ( SCBehaviour , SCNode , 
	Array* WrapperFuncs;
	Dictionary* Interfaces;
	SCModule* FuncTable;
);

struct SCBetterNode_Behaviour: SCNode_Behaviour {
};

JBClass ( SCBetterNode , SCNode , 
	JB_String* Description;
);

JBClass ( LessThan3 , JB_Task , 
	JB_String* a;
	int b;
	JB_String* c;
);

struct SCClass_Behaviour: SCBetterNode_Behaviour {
};

JBClass ( SCClass , SCBetterNode , 
	SCDecl* DataObject;
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
	SCFunction* TheBoolFunc;
	SCFunction* ConstructorFunc;
	SCFunction* DestructorFunc;
	JB_String* CppClass;
	SCDecl* ClassType;
	SCDecl* SelfDecl;
	Message* IsModel;
	SCBehaviour* Behaviour;
	JB_String* SaveAs;
	SCClass* DowngradeTo;
	SCClass* ProcessAs;
	ClassInfo Flags;
	u16 TaskObjectCount;
	u16 Size;
	DataTypeCode TypeInfo;
	SCNodeType BaseType;
	byte Depth;
	byte MinOpt;
	byte Behaviourness;
	byte IsRole;
	byte IsWrapper;
);

struct SCFunction_Behaviour: SCBetterNode_Behaviour {
};

JBClass ( SCFunction , SCBetterNode , 
	Macro* IsMacro;
	Array* LinkTo;
	Array* Args;
	SCClass* Cls;
	CppRefs* Refs;
	JB_Object* CounterPart;
	SCFunction* NextFunc;
	FuncInASM* ASM;
	SCDecl* HasProto;
	SCClass* ProtoType;
	SCFunction* DepthFinder;
	SCDecl* ReturnType;
	FunctionType FuncInfo;
	u16 AltersParams;
	u16 LinkDepth;
	u16 TableId;
	u16 TmpCounter;
	byte IntPrmCount;
	NilState NilSelf;
	byte MinOpt;
	byte IsAssigns;
	byte IsCppInBuilt;
	ErrorSeverity BlindCasts;
	byte IsNilChecker;
	byte Badness;
	byte OptCounts;
	byte StructReturnPos;
);

struct SCModule_Behaviour: SCBetterNode_Behaviour {
};

JBClass ( SCModule , SCBetterNode , 
	JB_String* SubsFrom;
	SCClass* Cls;
	Message* InitVarsArg;
	Message* InitCodeArg;
	JB_String* CppPart;
	Message* InitAfter;
	CppRefs* DefaultRefs;
	bool IsRequiredInterface;
	bool Grabbed;
	bool Inited;
	bool IsImport;
);

JBClass ( Task2 , LessThan3 , 
	vec2 V;
	float Strength;
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
extern Message* SC__Comp_AppInitCode;
extern Message* SC__Comp_AppInitGlobals;
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
extern bool SC__Comp_HasFunny;
extern bool SC__Comp_HasMainFunc;
extern Array* SC__Comp_ImportedList;
extern Dictionary* SC__Comp_ImportedNames;
extern bool SC__Comp_InitedOK;
extern bool SC__Comp_InPerry;
extern Dictionary* SC__Comp_InsecureWords;
extern SCFile* SC__Comp_InternalFile;
extern SCNode* SC__Comp_Interpreter;
#define kSC__Comp_kTimeWidth ((int)19)
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
extern SCFunction* SC__Comp_RefIncr2;
extern SCFunction* SC__Comp_RefSafeDecr;
extern SCFunction* SC__Comp_RefSetRef;
extern JB_String* SC__Comp_ReportedName;
extern JB_String* SC__Comp_StageName;
extern int SC__Comp_stClasses;
extern int SC__Comp_stFuncs;
extern int SC__Comp_stLibFuncs;
extern int SC__Comp_stParseTime;
extern int SC__Comp_stParseTimeTotal;
extern int SC__Comp_stReachedClass;
extern int SC__Comp_stReachedFunc;
extern int SC__Comp_stTotalFileCount;
extern int SC__Comp_stTotalSourceSize;
extern SCFunction* SC__Comp_SwapFunc;
extern Array* SC__Comp_SyxArray;
extern Array* SC__Comp_TasksList;
extern Array* SC__Comp_TasksTodo;
extern JB_File* SC__Comp_TempFolder;
extern SCFunction* SC__Comp_TernaryFunc;
extern FastString* SC__Comp_TimerOutput;
extern Array* SC__Comp_TodoList;
extern SCNode* SC__Comp_VisibleFuncs;
#define kSC__CustomOps_Needed ((int)256)
#define kSC__CustomOps_NotCustom ((int)0)
#define kSC__CustomOps_OnlyLeftIsVector ((int)257)
#define kSC__CustomOps_OnlyRightIsVector ((int)258)
#define kSC__CustomOps_RecheckType ((int)4)
#define kSC__CustomOps_TypeCastFromBool ((int)16)
#define kSC__CustomOps_TypeCastToBetter ((int)32)
#define kSC__CustomOps_TypeCastToSmaller ((int)64)
#define kJB__ErrorColors_bold ((JB_StringC*)JB_LUB[125])
extern bool JB__ErrorColors_Enabled;
#define kJB__ErrorColors_error ((JB_StringC*)JB_LUB[133])
#define kJB__ErrorColors_good ((JB_StringC*)JB_LUB[162])
#define kJB__ErrorColors_normal ((JB_StringC*)JB_LUB[107])
#define kJB__ErrorColors_underline ((JB_StringC*)JB_LUB[162])
#define kJB__ErrorColors_warn ((JB_StringC*)JB_LUB[195])
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
extern SyntaxObj* JB__Constants__FuncArray[64];
extern Dictionary* JB__Constants__SyxDict;
extern CharSet* JB__Constants_CSAfterDot;
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
#define kJB__MZLab_Default ((int)3)
#define kJB__MZLab_Fast ((int)2)
#define kJB__MZLab_Fastest ((int)1)
#define kJB__MZLab_None ((int)0)
#define kJB__MZLab_Strong ((int)3)
#define kJB__MZLab_Strongest ((int)4)
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
extern Macro* SC__Macros_OptPath;
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
extern bool SC__Options_ForceRecompile;
extern bool SC__Options_GenFlowControlCode;
extern bool SC__Options_IgnoreCantSaveErrors;
extern bool SC__Options_IsDirectTest;
extern bool SC__Options_KeepAllErrors;
extern bool SC__Options_MakeInterpreter;
extern bool SC__Options_MakeLib;
extern bool SC__Options_ModeCpp;
extern bool SC__Options_ModePack;
#define kSC__Options_native ((int)1)
extern bool SC__Options_NilTestAllocNeverFails;
extern byte SC__Options_OperationCount;
extern byte SC__Options_Optimise;
extern JB_String* SC__Options_output_path;
#define kSC__Options_pack ((int)2)
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
extern byte SC__Options_UseScriptLoc;
extern JB_String* SC__Options_Variant;
extern bool SC__Options_Warnings;
extern int SC__PackMaker_ExportPos;
extern Array* SC__PackMaker_LibFuncs;
extern Array* SC__PackMaker_LibGlobs;
extern Array* SC__PackMaker_PackFuncs;
extern Array* SC__PackMaker_PackGlobs;
#define kJB__PicoNoise_All ((int)15)
#define kJB__PicoNoise_Debug ((int)3)
#define kJB__PicoNoise_DebugChild ((int)1)
#define kJB__PicoNoise_DebugParent ((int)2)
#define kJB__PicoNoise_Events ((int)12)
#define kJB__PicoNoise_EventsChild ((int)4)
#define kJB__PicoNoise_EventsParent ((int)8)
extern JB_File* JB__Platform_Logger_;
extern Message* SC__PostIncrementNil_Msgs[32];
extern int SC__PostIncrementNil_Size;
extern bool SC__PostIncrementNil_Sync;
extern Dictionary* SC__SCGame3D_Types;
extern int SC__SC_UniqueNum;
#define kSC__Refs_kBasisCArray ((int)8)
#define kSC__Refs_kBasisDeSTRUCTable ((int)2)
#define kSC__Refs_kBasisNotObj ((int)0)
#define kSC__Refs_kBasisObj ((int)1)
#define kSC__Refs_kBasisTempStruct ((int)4)
#define kSC__Refs_kHoldsDisowned ((int)128)
#define kSC__Refs_kIsDisowner ((int)64)
#define kSC__Refs_kIsNoisy ((int)32)
#define kSC__Refs_kNotDisturbed ((int)0)
#define kSC__Refs_kSufferedNoise ((int)16)
extern Message* SC__SCStrings_RenderFinish;
extern Message* SC__SCStrings_RenderInsides;
extern Message* SC__SCStrings_RenderNewParams;
extern Macro* SC__SCTasks_TaskMacro;
extern Message* SC__SCTasks_tmp;
extern Dictionary* SC__Errors_IgnoredBranches;
extern Dictionary* SC__SC_Targets_Items;
extern int SC__SpdAssembler_OptPathCount;
extern Message* SC__SpdAssembler_OptPathNames[64];
extern int SC__SpdAssembler_OptPaths[64];
extern Array* SC__SpdAssembler_PackFuncs;
extern Fn_µOpt SC__SpdAssembler_xC2xB5Opt[256];
extern Array* SC__Crkt_List;
extern Dictionary* SC__Crkt_Table2;
extern int SC__Crkt_TotalSize;
#define kJB__Terminal_Black ((TerminalColor)30)
#define kJB__Terminal_Blue ((TerminalColor)34)
#define kJB__Terminal_Cyan ((TerminalColor)36)
extern FastString* JB__Terminal_fs;
#define kJB__Terminal_Green ((TerminalColor)32)
#define kJB__Terminal_h ((int)35)
extern Date JB__Terminal_LastDisplay;
#define kJB__Terminal_Magenta ((TerminalColor)35)
#define kJB__Terminal_Red ((TerminalColor)31)
extern Array* JB__Terminal_TermScreen;
#define kJB__Terminal_w ((int)80)
#define kJB__Terminal_White ((TerminalColor)37)
#define kJB__Terminal_Yellow ((TerminalColor)33)
extern Dictionary* SC__TextAssembler_Labels;
extern Array* SC__Ext_Cleanup;
extern int SC__Ext_CompilingLibFiles;
extern JB_String* SC__Ext_CppCompilerPath;
extern Array* SC__Ext_FoundObjects;
extern Date SC__Ext_LatestLibDate;
extern Macro* SC__VM_Builder_arms;
extern Macro* SC__VM_Builder_ASM_Datatype;
extern Macro* SC__VM_Builder_double_rizzler;
extern Message* SC__VM_Builder_dt_prm;
extern FastString* SC__VM_Builder_form_h;
extern uint SC__VM_Builder_FreeMultiASM;
extern Macro* SC__VM_Builder_gyatt;
extern Macro* SC__VM_Builder_icecream;
extern Macro* SC__VM_Builder_legs;
extern Message* SC__VM_Builder_ModuleArg;
extern Array* SC__VM_Builder_NameList;
extern byte SC__VM_Builder_NormalPos;
extern Macro* SC__VM_Builder_ohio;
extern Macro* SC__VM_Builder_Ooof;
extern JB_String* SC__VM_Builder_parent;
extern Macro* SC__VM_Builder_rizzler;
extern Macro* SC__VM_Builder_skibidy;
extern int SC__VM_Builder_Total;
extern Macro* SC__VM_Builder_Ugh;
extern JB_File* SC__VM_Builder_vm_file;
extern byte SC__VM_Builder_XType;
extern JB_String* SC___AppConfString;
extern JB_String* JB__JbinHeader;
extern JB_String* JB__jBinNotJbin;
extern int JB_aaaaaaa;
extern JB_String* SC_ASM_ASK;
extern CharSet* SC_C_Letters;
extern Dictionary* SC_ClassLinkageTable;
extern Dictionary* SC_ClsCollectTable;
extern Dictionary* SC_CodePointTable;
#define kJB_codesign_native ((JB_StringC*)JB_LUB[172])
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
#define kJB_kActualTypecasts ((int)-161)
#define kJB_kAddressOfMatch ((int)12582912)
#define kJB_kCastedMatch ((int)25165824)
#define kJB_kLossyCastedMatch ((int)29360128)
#define kJB_kMultipleErrors ((int)2097152)
#define kJB_kNeeds ((int)469762048)
#define kJB_kNeedsAddressOf ((int)134217728)
#define kJB_kNeedsAddressOfButAlsoNeedsSuperMatch ((int)268435456)
#define kJB_kNeedsTypeCast ((int)67108864)
#define kJB_kNoBoolTypeCast ((int)32)
#define kJB_kNoMatch ((int)0)
#define kJB_kNumericMatch ((int)8388608)
#define kJB_kSaverEnd ((JB_StringC*)JB_LUB[0])
#define kJB_kSaverStart1 ((JB_StringC*)JB_LUB[200])
#define kJB_kSimpleMatch ((int)4194304)
#define kJB_kSuperClassMatch ((int)16777216)
#define kJB_kTypeCastAssigns ((int)64)
#define kJB_kTypeCastBothWays ((int)16)
#define kJB_kTypeCastDescribeErrors ((int)256)
#define kJB_kTypeCastFalse ((int)0)
#define kJB_kTypeCastForSetRel ((int)512)
#define kJB_kTypeCastFromSmallInt ((int)4096)
#define kJB_kTypeCastFromZero ((int)2048)
#define kJB_kTypeCastIgnoreAddressOf ((int)8)
#define kJB_kTypeCastIgnoreContained ((int)4)
#define kJB_kTypeCastMost ((int)1)
#define kJB_kTypeCastNumbers ((int)2)
#define kJB_kTypeCastSetToMemory ((int)1024)
#define kJB_kTypeCastTrue ((int)3)
#define kJB_kTypeCastWantSuperDistance ((int)128)
#define kJB_kUseDefaultParams ((int)33554432)
#define kJB_kUsingStr ((JB_StringC*)JB_LUB[1578])
#define kJB_kVoidPtrMatch ((int)20971520)
extern Message* SC_ReturnSelfEqNil;
extern Dictionary* SC_RootCollectTable;
extern JB_ErrorReceiver* JB_StdErr;
#define kJB_SyxAcc ((Syntax)29)
#define kJB_SyxAdj ((Syntax)27)
#define kJB_SyxARel ((Syntax)21)
#define kJB_SyxArg ((Syntax)1)
#define kJB_SyxArr ((Syntax)34)
#define kJB_SyxAsk ((Syntax)43)
#define kJB_SyxBack ((Syntax)16)
#define kJB_SyxBadj ((Syntax)28)
#define kJB_SyxBin ((Syntax)18)
#define kJB_Syxbinn ((Syntax)42)
#define kJB_SyxBra ((Syntax)31)
#define kJB_SyxBRel ((Syntax)26)
#define kJB_SyxChar ((Syntax)17)
#define kJB_SyxCnj ((Syntax)8)
#define kJB_SyxDecl ((Syntax)4)
#define kJB_SyxDot ((Syntax)23)
#define kJB_SyxEmb ((Syntax)2)
#define kJB_SyxERel ((Syntax)38)
#define kJB_SyxFile ((Syntax)35)
#define kJB_SyxFunc ((Syntax)25)
#define kJB_SyxItem ((Syntax)30)
#define kJB_SyxList ((Syntax)32)
#define kJB_Syxmax ((Syntax)55)
#define kJB_SyxMsg ((Syntax)46)
#define kJB_SyxName ((Syntax)22)
#define kJB_SyxNil ((Syntax)0)
#define kJB_SyxNum ((Syntax)14)
#define kJB_SyxOat ((Syntax)6)
#define kJB_SyxOpp ((Syntax)9)
#define kJB_Syxpinn ((Syntax)41)
#define kJB_SyxPrm ((Syntax)33)
#define kJB_SyxQues ((Syntax)7)
#define kJB_SyxQuot ((Syntax)36)
#define kJB_SyxRel ((Syntax)37)
#define kJB_SyxSCnj ((Syntax)12)
#define kJB_SyxSCom ((Syntax)45)
#define kJB_SyxSDot ((Syntax)24)
#define kJB_SyxSheb ((Syntax)11)
#define kJB_SyxSStr ((Syntax)15)
#define kJB_SyxSThg ((Syntax)13)
#define kJB_SyxStr ((Syntax)19)
#define kJB_SyxThg ((Syntax)10)
#define kJB_SyxTmp ((Syntax)5)
#define kJB_SyxTodo ((Syntax)47)
#define kJB_SyxTRel ((Syntax)39)
#define kJB_SyxTril ((Syntax)40)
#define kJB_SyxType ((Syntax)3)
#define kJB_SyxUnit ((Syntax)20)
#define kJB_Syxurl ((Syntax)48)
#define kJB_SyxXAtt ((Syntax)49)
#define kJB_SyxXCDT ((Syntax)53)
#define kJB_SyxXCom ((Syntax)52)
#define kJB_SyxXML ((Syntax)50)
#define kJB_SyxXPI ((Syntax)51)
#define kJB_SyxXTxt ((Syntax)54)
#define kJB_SyxYoda ((Syntax)44)
extern SCDecl* SC_TrueBool;
extern SCClass* SC_TypeArray;
extern SCClass* SC_TypeBool;
extern SCClass* SC_TypeByte;
extern SCClass* SC_TypeChar;
extern SCClass* SC_TypeCharSet;
extern SCClass* SC_TypeCodePoint;
extern SCClass* SC_TypeDate;
extern SCClass* SC_TypeDictionary;
extern SCClass* SC_TypeDuration;
extern SCClass* SC_TypeFastString;
extern SCClass* SC_Typefloat;
extern SCClass* SC_TypeFloat16;
extern SCClass* SC_TypeFloat64;
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
#define kJB__Tk_kAdjectiveOp ((int)1)
#define kJB__Tk_kAllow ((bool)false)
#define kJB__Tk_kColon ((int)2)
#define kJB__Tk_kColonArg ((int)4)
#define kJB__Tk_kComma ((int)128)
#define kJB__Tk_kEnd ((int)448)
#define kJB__Tk_kEndContainer ((int)256)
#define kJB__Tk_kEndOfLine ((int)64)
#define kJB__Tk_kExpect ((bool)1)
#define kJB__Tk_kFuncAfterAny ((int)3584)
#define kJB__Tk_kFuncAfterBar ((int)2048)
#define kJB__Tk_kFuncAfterNormal ((int)512)
#define kJB__Tk_kFuncAfterNoSpace ((int)1024)
#define kJB__Tk_kIllegalChar ((int)4194304)
#define kJB__Tk_kLameTemporal ((int)56)
#define kJB__Tk_kOpp ((int)258048)
#define kJB__Tk_kOppBar ((int)16384)
#define kJB__Tk_kOppBra ((int)4096)
#define kJB__Tk_kOppChain ((int)94208)
#define kJB__Tk_kOppNoBar ((int)241664)
#define kJB__Tk_kOppSNB ((int)8192)
#define kJB__Tk_kOppSyx ((int)24576)
#define kJB__Tk_kOppTemporal ((int)32768)
#define kJB__Tk_kOppWord ((int)65536)
#define kJB__Tk_kOppYoda ((int)131072)
#define kJB__Tk_kTemporal ((int)56)
#define kJB__Tk_kTemporalBar ((int)32)
#define kJB__Tk_kTemporalSyx ((int)48)
#define kJB__Tk_kTemporalSyxNoBar ((int)16)
#define kJB__Tk_kTemporalWord ((int)8)
#define kJB__Tk_kTemporalWordColon ((int)262144)
#define kJB__Tk_kThing ((int)3670016)
#define kJB__Tk_kThingBar ((int)1048576)
#define kJB__Tk_kThingSyx ((int)524288)
#define kJB__Tk_kThingWord ((int)2097152)
#define kJB__Tk_kTmpOpp ((int)32784)
extern FP_fnIDGenerator JB__Tk_Splitter;
extern MessagePosition JB__Tk_Using;
#define kJB__zalgo_down ((JB_StringC*)JB_LUB[1408])
#define kJB__zalgo_mid ((JB_StringC*)JB_LUB[448])
extern Random JB__zalgo_R;
#define kJB__zalgo_up ((JB_StringC*)JB_LUB[263])
#define kJB__byte_max ((byte)255)
#define kJB__byte_min ((byte)0)
#define kJB__int16_max ((s16)32767)
#define kJB__int16_min ((s16)-32768)
#define kJB__int64_max ((int64)9223372036854775807)
#define kJB__int64_min ((int64)-9223372036854775808)
#define kJB__int8_max ((int8)127)
#define kJB__int8_min ((int8)-128)
#define kJB__uint_max ((uint)4294967295)
#define kJB__uint_min ((uint)0)
#define kJB__uint16_max ((u16)65535)
#define kJB__uint16_min ((u16)0)
#define kJB__uint64_max ((uint64)-1)
#define kSC__ASM_ADD ((ASM_Shift)44)
#define kSC__ASM_ADDK ((ASM_AddK)42)
#define kSC__ASM_ADDR ((ASM_U4)34)
#define kSC__ASM_ADPK ((ASM_AddK)43)
#define kSC__ASM_ALLO ((ASM_Alloc)36)
#define kSC__ASM_BAND ((ASM_Shift)55)
#define kSC__ASM_BCLR ((ASM_BClear)62)
#define kSC__ASM_BFLG ((ASM_BFLD)60)
#define kSC__ASM_BNAN ((ASM_Shift)57)
#define kSC__ASM_BNOR ((ASM_Shift)58)
#define kSC__ASM_BNOT ((ASM_Shift)59)
#define kSC__ASM_BOR ((ASM_Shift)56)
#define kSC__ASM_BSHL ((ASM_Shift)54)
#define kSC__ASM_BSHR ((ASM_Shift)53)
#define kSC__ASM_BSHS ((ASM_Shift)52)
#define kSC__ASM_BSTT ((ASM_U4)61)
#define kSC__ASM_BXOR ((ASM_Shift)51)
#define kSC__ASM_CMPB ((ASM_CmpB)63)
#define kSC__ASM_CMPF ((ASM_JCmpF)66)
#define kSC__ASM_CMPI ((ASM_JCmpI)65)
#define kSC__ASM_CNTC ((ASM_CNTC)96)
#define kSC__ASM_CNTD ((ASM_CNTC)97)
#define kSC__ASM_CONV ((ASM_Convert)40)
#define kSC__ASM_DIV2 ((ASM_Div2)48)
#define kSC__ASM_DIVV ((ASM_Div)47)
extern ASM_Encoder SC__ASM_Encoders[256];
#define kSC__ASM_EROR ((ASM_HALT)0)
#define kSC__ASM_FADD ((ASM_Float)99)
#define kSC__ASM_FADK ((ASM_FloatConst)100)
#define kSC__ASM_FDIV ((ASM_Float)103)
#define kSC__ASM_FFNC ((ASM_ForeignFunc)9)
#define kSC__ASM_FFNC2 ((ASM_ForeignFunc)9)
#define kSC__ASM_FFNC3 ((ASM_ForeignFunc)10)
#define kSC__ASM_FFNC33 ((ASM_ForeignFunc)10)
#define kSC__ASM_FFRC ((ASM_Float)104)
#define kSC__ASM_FMAX ((ASM_Float)105)
#define kSC__ASM_FMIN ((ASM_Float)106)
#define kSC__ASM_FMLK ((ASM_FloatConst)102)
#define kSC__ASM_FMUL ((ASM_Float)101)
#define kSC__ASM_FNC ((ASM_Func)1)
#define kSC__ASM_FNC2 ((ASM_Func)1)
#define kSC__ASM_FNC3 ((ASM_Func)2)
#define kSC__ASM_FNC33 ((ASM_Func)2)
extern ASM_Encoder SC__ASM_Forms[128];
#define kSC__ASM_JBRA ((ASM_Bra)73)
#define kSC__ASM_JBRN ((ASM_Bra)74)
#define kSC__ASM_JMPE ((ASM_JCmpEq)71)
#define kSC__ASM_JMPF ((ASM_JCmpF)70)
#define kSC__ASM_JMPI ((ASM_JCmpI)69)
#define kSC__ASM_JMPN ((ASM_JCmpEq)72)
#define kSC__ASM_JSWI ((ASM_JCmpEq)67)
#define kSC__ASM_JUMP ((ASM_Jump)68)
#define kSC__ASM_KNSR ((ASM_RotateConst)41)
#define kSC__ASM_KNST ((ASM_ConstStretchy)4)
#define kSC__ASM_KNST2 ((ASM_ConstStretchy)5)
#define kSC__ASM_KNST3 ((ASM_ConstStretchy)6)
#define kSC__ASM_LUPD ((ASM_Loop)75)
#define kSC__ASM_LUPU ((ASM_Loop)76)
#define kSC__ASM_MAX ((ASM_MinMax)49)
#define kSC__ASM_MEMU ((ASM_MemUtil)98)
#define kSC__ASM_MIN ((ASM_MinMax)50)
#define kSC__ASM_MULT ((ASM_U4)46)
extern byte SC__ASM_NoisyASM;
#define kSC__ASM_NOOP ((ASM_U0)32)
#define kSC__ASM_PRNT ((ASM_U1)38)
#define kSC__ASM_RALO ((ASM_U2)81)
#define kSC__ASM_RARE ((ASM_U2)39)
#define kSC__ASM_RD16 ((ASM_Read)90)
#define kSC__ASM_RD1S ((ASM_Read)84)
#define kSC__ASM_RD1U ((ASM_Read)83)
#define kSC__ASM_RD2S ((ASM_Read)86)
#define kSC__ASM_RD2U ((ASM_Read)85)
#define kSC__ASM_RD4S ((ASM_Read)88)
#define kSC__ASM_RD4U ((ASM_Read)87)
#define kSC__ASM_RD8U ((ASM_Read)89)
#define kSC__ASM_RET ((ASM_RET)35)
#define kSC__ASM_RFDC ((ASM_RefDecrMem)80)
#define kSC__ASM_RFRD ((ASM_RefSet3)79)
#define kSC__ASM_RFRG ((ASM_RefSet)77)
#define kSC__ASM_RFWR ((ASM_RefSet2)78)
#define kSC__ASM_SUB ((ASM_Shift)45)
#define kSC__ASM_SWAP ((ASM_Swap)37)
#define kSC__ASM_TABL ((ASM_Table)82)
#define kSC__ASM_TAIL ((ASM_Tail)13)
#define kSC__ASM_TAIL2 ((ASM_Tail)13)
#define kSC__ASM_TERN ((ASM_U4)64)
#define kSC__ASM_TRAP ((ASM_Trap)33)
#define kSC__ASM_WR16 ((ASM_Write)95)
#define kSC__ASM_WR1U ((ASM_Write)91)
#define kSC__ASM_WR2U ((ASM_Write)92)
#define kSC__ASM_WR4U ((ASM_Write)93)
#define kSC__ASM_WR8U ((ASM_Write)94)
#define kSC__Reg_AddrRequest ((ASMReg)4294967296)
#define kSC__Reg_AlreadyNegated ((ASMReg)1048576)
#define kSC__Reg_Alternate ((ASMReg)2097152)
#define kSC__Reg_Arg ((ASMReg)4194304)
#define kSC__Reg_CondAnswer ((ASMReg)34359738368)
#define kSC__Reg_CondRequest ((ASMReg)17179869184)
#define kSC__Reg_ConstAny ((ASMReg)1073741824)
#define kSC__Reg_ContainsAddr ((ASMReg)2147483648)
#define kSC__Reg_Decl ((ASMReg)25165824)
#define kSC__Reg_Discard ((ASMReg)4194304)
#define kSC__Reg_FatRef ((int)1073741824)
#define kSC__Reg_ForCast ((ASMReg)67108864)
#define kSC__Reg_ForReturn ((ASMReg)33554432)
#define kSC__Reg_FromExistingVar ((ASMReg)262144)
#define kSC__Reg_FromMath ((ASMReg)131072)
#define kSC__Reg_MathConst ((ASMReg)1073872896)
#define kSC__Reg_Negate ((ASMReg)65536)
#define kSC__Reg_NeverAltered ((ASMReg)268435456)
#define kSC__Reg_NotYetUsed ((ASMReg)16777216)
#define kSC__Reg_Set ((ASMReg)8388608)
#define kSC__Reg_SingleExpr ((ASMReg)536870912)
#define kSC__Reg_StayOpen ((ASMReg)524288)
#define kSC__Reg_Temp ((ASMReg)134217728)
#define kSC__Reg_Textual ((ASMReg)8589934592)
#define kSC__Reg_Zero ((ASMReg)1073741880)
#define kSC__ASMType_IncrAfter ((int)2)
#define kSC__ASMType_IncrBefore ((int)0)
#define kSC__ASMType_kContinue ((ASMType)54)
#define kSC__ASMType_kDebugger ((ASMType)61)
#define kSC__ASMType_kElseIf ((ASMType)51)
#define kSC__ASMType_kExit ((ASMType)55)
#define kSC__ASMType_kFail ((ASMType)63)
#define kSC__ASMType_kIf ((ASMType)52)
#define kSC__ASMType_kIgnore ((ASMType)60)
#define kSC__ASMType_kPointer ((ASMType)48)
#define kSC__ASMType_kRefCount ((ASMType)62)
#define kSC__ASMType_kRejoin ((ASMType)57)
#define kSC__ASMType_kReturn ((ASMType)56)
#define kSC__ASMType_kSetRel ((ASMType)59)
#define kSC__ASMType_kStatExpr ((ASMType)50)
#define kSC__ASMType_kSwap ((ASMType)58)
#define kSC__ASMType_kTern ((ASMType)49)
#define kSC__ASMType_kUnusedFirst ((ASMType)47)
#define kSC__ASMType_kWhile ((ASMType)53)
extern ASM_Read SC__ASMType_ReadASM[10];
extern ASM_Write SC__ASMType_WriteASM[5];
#define kJB__CharProp_AlmostLetter ((CharProp)6)
#define kJB__CharProp_Letters ((CharProp)7)
#define kJB__CharProp_Lower ((CharProp)9)
#define kJB__CharProp_Nothing ((CharProp)0)
#define kJB__CharProp_Number ((CharProp)5)
#define kJB__CharProp_Punct ((CharProp)2)
#define kJB__CharProp_Unicode ((CharProp)10)
#define kJB__CharProp_Upper ((CharProp)8)
#define kJB__CharProp_VarNames ((CharProp)4)
#define kJB__CharProp_White ((CharProp)1)
#define kJB__CharProp_XMLPunct ((CharProp)3)
#define kSC__ClassInfo_ASM ((ClassInfo)524288)
#define kSC__ClassInfo_AutoGeneratedSavers ((ClassInfo)64)
#define kSC__ClassInfo_Banned ((ClassInfo)512)
#define kSC__ClassInfo_Builtin ((ClassInfo)16384)
#define kSC__ClassInfo_ContainsParentClass ((ClassInfo)1)
#define kSC__ClassInfo_DefaultsToReal ((ClassInfo)2048)
#define kSC__ClassInfo_Fixed ((ClassInfo)131072)
#define kSC__ClassInfo_Flags ((ClassInfo)262144)
#define kSC__ClassInfo_HasCompareFunc ((ClassInfo)4)
#define kSC__ClassInfo_HasEqualsFunc ((ClassInfo)8)
#define kSC__ClassInfo_HasNilChecker ((ClassInfo)1024)
#define kSC__ClassInfo_HasSubClass ((ClassInfo)16)
#define kSC__ClassInfo_IgnoreContainedSelf ((ClassInfo)2)
#define kSC__ClassInfo_IsRole ((ClassInfo)4096)
#define kSC__ClassInfo_IsTask ((ClassInfo)8192)
#define kSC__ClassInfo_NoEarlyFree ((ClassInfo)32)
#define kSC__ClassInfo_NumericReduction ((ClassInfo)458752)
#define kSC__ClassInfo_SavingCanSkip ((ClassInfo)128)
#define kSC__ClassInfo_SortsProperties ((ClassInfo)32768)
#define kSC__ClassInfo_Symbol ((ClassInfo)65536)
#define kSC__ClassInfo_TreatAsBaseType ((ClassInfo)256)
#define kJB__ControlClipMode_Debug ((int)4)
#define kJB__ControlClipMode_SlideBackInParent ((int)1)
#define kJB__ControlClipMode_SlideBackInWindow ((int)2)
#define kJB__CL1_After ((ControlPoint)6)
#define kJB__CL1_Before ((ControlPoint)4)
#define kJB__CL1_Centered ((ControlPoint)7)
#define kJB__CL1_High ((ControlPoint)2)
#define kJB__CL1_Length ((ControlPoint)10)
#define kJB__CL1_Low ((ControlPoint)0)
#define kJB__CL1_Percent ((ControlPoint)8)
#define kJB__TC__void ((DataTypeCode)0)
#define kJB__TC__voidptr ((DataTypeCode)48)
#define kJB__TC_bool ((DataTypeCode)256)
#define kJB__TC_byte ((DataTypeCode)8)
#define kJB__TC_Byte2 ((DataTypeCode)9)
#define kJB__TC_Byte3 ((DataTypeCode)10)
#define kJB__TC_Byte4 ((DataTypeCode)11)
#define kJB__TC_char ((DataTypeCode)72)
#define kJB__TC_cstring ((DataTypeCode)48)
#define kJB__TC_Double ((DataTypeCode)248)
#define kJB__TC_f16 ((DataTypeCode)216)
#define kJB__TC_f64 ((DataTypeCode)248)
#define kJB__TC_Failed ((DataTypeCode)1024)
#define kJB__TC_Float ((DataTypeCode)232)
#define kJB__TC_Float16 ((DataTypeCode)216)
#define kJB__TC_HFloat ((DataTypeCode)216)
#define kJB__TC_Int ((DataTypeCode)104)
#define kJB__TC_int16 ((DataTypeCode)88)
#define kJB__TC_int64 ((DataTypeCode)120)
#define kJB__TC_int8 ((DataTypeCode)72)
#define kJB__TC_iVec2 ((DataTypeCode)105)
#define kJB__TC_iVec3 ((DataTypeCode)106)
#define kJB__TC_iVec4 ((DataTypeCode)107)
#define kJB__TC_Numeric ((DataTypeCode)8)
#define kJB__TC_PossibleBits ((DataTypeCode)2047)
#define kJB__TC_s16 ((DataTypeCode)88)
#define kJB__TC_s16x2 ((DataTypeCode)89)
#define kJB__TC_s16x3 ((DataTypeCode)90)
#define kJB__TC_s16x4 ((DataTypeCode)91)
#define kJB__TC_s64 ((DataTypeCode)120)
#define kJB__TC_SByte ((DataTypeCode)72)
#define kJB__TC_SByte2 ((DataTypeCode)73)
#define kJB__TC_SByte3 ((DataTypeCode)74)
#define kJB__TC_SByte4 ((DataTypeCode)75)
#define kJB__TC_sign ((DataTypeCode)64)
extern Dictionary* JB__TC_Types_Dict;
#define kJB__TC_u16 ((DataTypeCode)24)
#define kJB__TC_u32 ((DataTypeCode)40)
#define kJB__TC_u64 ((DataTypeCode)56)
#define kJB__TC_UInt ((DataTypeCode)40)
#define kJB__TC_uint16 ((DataTypeCode)24)
#define kJB__TC_uint64 ((DataTypeCode)56)
#define kJB__TC_uint8 ((DataTypeCode)8)
#define kJB__TC_UnusedType ((DataTypeCode)112)
#define kJB__TC_Vec2 ((DataTypeCode)233)
#define kJB__TC_Vec3 ((DataTypeCode)234)
#define kJB__TC_Vec4 ((DataTypeCode)235)
#define kJB__Date_Highest ((int64)9223372036854775807)
#define kJB__Date_kOneStep (0.000015258789f)
#define kJB__Date_kSecondsPerDay ((int)86400)
#define kJB__Date_kSecondsPerMonthApprox ((int)2628000)
#define kJB__Date_kSecondsPerWeek ((int)604800)
#define kSC__DeclMode_Always ((DeclMode)64)
#define kSC__DeclMode_FuncParam ((DeclMode)4)
#define kSC__DeclMode_FunctionBody ((DeclMode)8)
#define kSC__DeclMode_Globals ((DeclMode)1)
#define kSC__DeclMode_Local ((DeclMode)12)
#define kSC__DeclMode_Properties ((DeclMode)3)
#define kSC__DeclMode_Proto ((DeclMode)16)
#define kSC__DeclMode_ProtoParam ((DeclMode)20)
#define kSC__DeclMode_TypeCast ((DeclMode)32)
#define kSC__DotUseType_Memory ((DotUseType)2)
#define kSC__DotUseType_Property ((DotUseType)1)
#define kJB__ErrorFlags_DontStrip ((ErrorFlags)1)
#define kJB__ErrorFlags_Keep ((int)0)
#define kJB__ErrorFlags_Parse ((ErrorFlags)4)
#define kJB__ErrorFlags_PreferNoRenderPath ((ErrorFlags)2)
#define kJB__ErrorFlags_PrintAndKeep ((int)1)
#define kJB__ErrorFlags_PrintAndRemove ((int)2)
extern Array* JB__ErrorSeverity__names;
#define kJB__ErrorSeverity_Critical ((ErrorSeverity)5)
#define kJB__ErrorSeverity_Error ((ErrorSeverity)4)
#define kJB__ErrorSeverity_Hint ((ErrorSeverity)1)
#define kJB__ErrorSeverity_MaxError ((ErrorSeverity)6)
#define kJB__ErrorSeverity_OK ((ErrorSeverity)0)
#define kJB__ErrorSeverity_Problem ((ErrorSeverity)3)
#define kJB__ErrorSeverity_Warning ((ErrorSeverity)2)
#define kSC__FailableInt_Fail ((int)2147483648)
#define kJB__FileDes_StdErr ((FileDes)2)
#define kJB__FileDes_StdIn ((FileDes)0)
#define kJB__FileDes_StdOut ((FileDes)1)
#define kJB__FileMode_CanExec ((FileMode)281474976710656)
#define kJB__FileMode_Data ((FileMode)6)
#define kJB__FileMode_Group ((FileMode)56)
#define kJB__FileMode_Other ((FileMode)7)
#define kJB__FileMode_Owner ((FileMode)448)
#define kJB__FileMode_Process ((FileMode)115968)
#define kJB__FileResolveMode_AllowMissing ((bool)1)
#define kSC__FunctionType_AlreadyExported ((FunctionType)16384)
#define kSC__FunctionType_API ((FunctionType)8388608)
#define kSC__FunctionType_AutoGeneratedSaver ((FunctionType)16777216)
#define kSC__FunctionType_Behaviour ((FunctionType)2048)
#define kSC__FunctionType_Comparison ((FunctionType)4)
#define kSC__FunctionType_ConOrDes ((FunctionType)3)
#define kSC__FunctionType_Constructor ((FunctionType)1)
#define kSC__FunctionType_Cpp ((FunctionType)268435456)
#define kSC__FunctionType_Destructor ((FunctionType)2)
#define kSC__FunctionType_Disabled ((FunctionType)2097152)
#define kSC__FunctionType_EmptyConstructor ((FunctionType)512)
#define kSC__FunctionType_ExpectsRealVars ((FunctionType)8192)
#define kSC__FunctionType_ExternalLib ((FunctionType)131072)
#define kSC__FunctionType_FlowDisabled ((FunctionType)65536)
#define kSC__FunctionType_HidesProperties ((FunctionType)33554432)
#define kSC__FunctionType_InitFunc ((FunctionType)128)
#define kSC__FunctionType_Inline ((FunctionType)524288)
#define kSC__FunctionType_Killer ((FunctionType)1048576)
#define kSC__FunctionType_NewNew ((FunctionType)4096)
#define kSC__FunctionType_NewStruct ((FunctionType)16)
#define kSC__FunctionType_NotRefCounted ((FunctionType)4194304)
#define kSC__FunctionType_NumberCreator ((FunctionType)32)
#define kSC__FunctionType_PrintedForDebugViewing ((FunctionType)67108864)
#define kSC__FunctionType_Recursive ((FunctionType)256)
#define kSC__FunctionType_Reffer ((FunctionType)8)
#define kSC__FunctionType_Render ((FunctionType)32768)
#define kSC__FunctionType_ReturnASMFloats ((FunctionType)134217728)
#define kSC__FunctionType_TypeTest ((FunctionType)64)
#define kSC__FunctionType_VirtualCaller ((FunctionType)1024)
#define kSC__FunctionType_Wrapper ((FunctionType)262144)
#define kJB__MoveCode_All ((MoveCode)63)
#define kJB__MoveCode_Back ((MoveCode)32)
#define kJB__MoveCode_Backward ((MoveCode)32)
#define kJB__MoveCode_Bottom ((MoveCode)8)
#define kJB__MoveCode_Center ((MoveCode)63)
#define kJB__MoveCode_Close ((MoveCode)128)
#define kJB__MoveCode_Down ((MoveCode)8)
#define kJB__MoveCode_Forward ((MoveCode)16)
#define kJB__MoveCode_Front ((MoveCode)16)
#define kJB__MoveCode_Horizontal ((MoveCode)3)
#define kJB__MoveCode_Left ((MoveCode)2)
#define kJB__MoveCode_MiddleLeft ((MoveCode)14)
#define kJB__MoveCode_MiddleRight ((MoveCode)13)
#define kJB__MoveCode_Negative ((MoveCode)170)
#define kJB__MoveCode_Open ((MoveCode)64)
#define kJB__MoveCode_Positive ((MoveCode)85)
#define kJB__MoveCode_Right ((MoveCode)1)
#define kJB__MoveCode_Top ((MoveCode)4)
#define kJB__MoveCode_Up ((MoveCode)4)
#define kJB__MoveCode_Vertical ((MoveCode)12)
#define kJB__MsgParseFlags_BreakPoint ((int)32768)
#define kJB__MsgParseFlags_Editable ((int)2048)
#define kJB__MsgParseFlags_Inserted ((int)4096)
#define kJB__MsgParseFlags_MacroInserted ((int)12288)
#define kJB__MsgParseFlags_MacroMade ((int)8192)
#define kJB__MsgParseFlags_NicelyPositioned ((int)1024)
#define kJB__MsgParseFlags_Special ((int)2048)
#define kJB__MsgParseFlags_Style2 ((int)16384)
#define kSC__khalai_Active ((NilCheckMode)3)
#define kSC__khalai_And ((NilCheckMode)8)
#define kSC__khalai_Assigns ((NilCheckMode)128)
#define kSC__khalai_Basic ((NilCheckMode)7)
#define kSC__khalai_Disappears ((NilCheckMode)64)
#define kSC__khalai_ForBools ((NilCheckMode)256)
#define kSC__khalai_IfNeg ((NilCheckMode)257)
#define kSC__khalai_IfPos ((NilCheckMode)258)
#define kSC__khalai_Negative ((NilCheckMode)1)
#define kSC__khalai_Nothing ((NilCheckMode)0)
#define kSC__khalai_Positive ((NilCheckMode)2)
#define kSC__khalai_Reversed ((NilCheckMode)16)
#define kSC__khalai_Soft ((NilCheckMode)4)
#define kSC__khalai_While ((NilCheckMode)32)
#define kSC__khalai_WhileNeg ((NilCheckMode)289)
#define kSC__khalai_WhilePos ((NilCheckMode)290)
#define kSC__NilReason_Accessing ((NilReason)0)
#define kSC__NilReason_Passing ((NilReason)4)
#define kSC__NilReason_Property ((NilReason)1)
#define kSC__NilReason_Reading ((NilReason)2)
#define kSC__NilReason_Using ((NilReason)3)
extern Array* SC__NilReason_values;
#define kSC__NilState_ActuallyNil ((NilState)21)
#define kSC__NilState_Basic ((NilState)2)
#define kSC__NilState_Borked ((NilState)128)
#define kSC__NilState_Either ((NilState)3)
#define kSC__NilState_Failed ((NilState)0)
#define kSC__NilState_FalseValue ((NilState)16)
#define kSC__NilState_FnBecomesNilCh ((NilState)8)
#define kSC__NilState_Killer ((NilState)255)
#define kSC__NilState_KnownValue ((NilState)48)
#define kSC__NilState_Nilish ((NilState)1)
#define kSC__NilState_Optional ((NilState)7)
#define kSC__NilState_Real ((NilState)6)
#define kSC__NilState_Realish ((NilState)2)
#define kSC__NilState_Solved ((NilState)64)
#define kSC__NilState_Stated ((NilState)4)
#define kSC__NilState_TrueValue ((NilState)32)
#define kSC__OpMode_Addition ((OpMode)16)
#define kSC__OpMode_AND ((OpMode)131072)
#define kSC__OpMode_AndOr ((OpMode)196608)
#define kSC__OpMode_Assigns ((OpMode)2)
#define kSC__OpMode_Bit ((OpMode)4)
#define kSC__OpMode_CaseAware ((OpMode)524288)
#define kSC__OpMode_Compare ((OpMode)1)
#define kSC__OpMode_Comparison ((OpMode)512)
#define kSC__OpMode_CompOrSet ((OpMode)3)
#define kSC__OpMode_Custom ((OpMode)262144)
#define kSC__OpMode_EqualOrNot ((OpMode)256)
#define kSC__OpMode_ExactEquals ((OpMode)4481)
#define kSC__OpMode_ExactlyEquals ((OpMode)128)
#define kSC__OpMode_ExactNotEquals ((OpMode)4353)
#define kSC__OpMode_Less ((OpMode)2048)
#define kSC__OpMode_LoseBits ((OpMode)32768)
#define kSC__OpMode_MakesSigned ((OpMode)64)
#define kSC__OpMode_Math ((OpMode)8)
#define kSC__OpMode_MathLike ((OpMode)12)
#define kSC__OpMode_More ((OpMode)1024)
#define kSC__OpMode_Multiply ((OpMode)8192)
#define kSC__OpMode_NeedsCppFuncOnFloats ((OpMode)1048576)
#define kSC__OpMode_NilTest ((OpMode)4096)
#define kSC__OpMode_NoExtraBits ((OpMode)16384)
#define kSC__OpMode_OR ((OpMode)65536)
#define kSC__OpMode_SameOrLessBits ((OpMode)49152)
#define kSC__OpMode_Shift ((OpMode)16416)
#define kSC__OpMode_ShiftOnly ((OpMode)32)
#define kSC__OpMode_Subtraction ((OpMode)80)
#define kJB__ProcessMode_AutoPrintErrors ((int)4)
#define kJB__ProcessMode_CaptureAll ((int)5)
#define kJB__ProcessMode_CaptureErrors ((int)2)
#define kJB__ProcessMode_CaptureOrPrintErrors ((int)6)
#define kJB__ProcessMode_CaptureStdOut ((int)1)
#define kJB__PIDM_Default ((ProcessOwnerMode)0)
#define kJB__PIDM_OwnGroup ((ProcessOwnerMode)2)
#define kJB__PIDM_StdOutFlowsThroughUs ((ProcessOwnerMode)1)
#define kSC__SCBlockage_Bits ((int)480)
#define kSC__SCBlockage_Continue ((int)64)
#define kSC__SCBlockage_Exit ((int)128)
#define kSC__SCBlockage_Quit ((int)192)
#define kSC__SCBlockage_Return ((int)192)
#define kSC__SCDeclInfo_Altered ((SCDeclInfo)1048576)
#define kSC__SCDeclInfo_AlteredViaPointer ((SCDeclInfo)524288)
#define kSC__SCDeclInfo_API ((SCDeclInfo)1024)
#define kSC__SCDeclInfo_Biggest ((SCDeclInfo)268435456)
#define kSC__SCDeclInfo_Body ((SCDeclInfo)32768)
#define kSC__SCDeclInfo_Borrowed ((SCDeclInfo)1)
#define kSC__SCDeclInfo_ClassObj ((SCDeclInfo)2048)
#define kSC__SCDeclInfo_CompilerCreated ((SCDeclInfo)4096)
#define kSC__SCDeclInfo_Const ((SCDeclInfo)8)
#define kSC__SCDeclInfo_DclCopied ((SCDeclInfo)1086562)
#define kSC__SCDeclInfo_DirectNumber ((SCDeclInfo)4)
#define kSC__SCDeclInfo_GameFlyingMem ((SCDeclInfo)4194304)
#define kSC__SCDeclInfo_Global ((SCDeclInfo)131072)
#define kSC__SCDeclInfo_Hidden ((SCDeclInfo)134217728)
#define kSC__SCDeclInfo_IntendedAsReturn ((SCDeclInfo)2147483648)
#define kSC__SCDeclInfo_Local ((SCDeclInfo)49152)
#define kSC__SCDeclInfo_NewlyCreated ((SCDeclInfo)128)
#define kSC__SCDeclInfo_NumberConst ((SCDeclInfo)12)
#define kSC__SCDeclInfo_Param ((SCDeclInfo)16384)
#define kSC__SCDeclInfo_PostIncremented ((SCDeclInfo)536870912)
#define kSC__SCDeclInfo_Property ((SCDeclInfo)65536)
#define kSC__SCDeclInfo_PropertyWasConstructed ((SCDeclInfo)8192)
#define kSC__SCDeclInfo_ReadFrom ((SCDeclInfo)33554432)
#define kSC__SCDeclInfo_Return ((SCDeclInfo)262144)
#define kSC__SCDeclInfo_ReturnedStruct ((SCDeclInfo)1073741824)
#define kSC__SCDeclInfo_Self ((SCDeclInfo)16777216)
#define kSC__SCDeclInfo_SelfImplicit ((SCDeclInfo)16826368)
#define kSC__SCDeclInfo_SetTo ((SCDeclInfo)67108864)
#define kSC__SCDeclInfo_Static ((SCDeclInfo)32)
#define kSC__SCDeclInfo_StayBorrowed ((SCDeclInfo)2)
#define kSC__SCDeclInfo_Swappable ((SCDeclInfo)245760)
#define kSC__SCDeclInfo_Task ((SCDeclInfo)8388608)
#define kSC__SCDeclInfo_TypeImprove ((SCDeclInfo)256)
#define kSC__SCDeclInfo_UnknownConst ((SCDeclInfo)16)
#define kSC__SCDeclInfo_UpgradeableContained ((SCDeclInfo)64)
#define kSC__SCDeclInfo_UsedButAlteredBySomethingAheadInLoop ((SCDeclInfo)2097152)
#define kSC__SCDeclInfo_UsedByCode ((SCDeclInfo)512)
#define kSC__SCNodeFindMode_DontGoUp ((SCNodeFindMode)2)
#define kSC__SCNodeFindMode_ForClass ((SCNodeFindMode)8)
#define kSC__SCNodeFindMode_NoErrors ((SCNodeFindMode)1)
#define kSC__SCNodeFindMode_WantAType ((SCNodeFindMode)4)
#define kSC__SCNodeInfo_ExplicitExport ((int)0)
#define kSC__SCNodeInfo_Visible ((int)1)
#define kSC__SCNodeType_DataType ((SCNodeType)2)
#define kSC__SCNodeType_FuncProto ((SCNodeType)3)
#define kSC__SCNodeType_Module ((SCNodeType)0)
#define kSC__SCNodeType_Nil ((SCNodeType)1)
#define kSC__SCNodeType_Object ((SCNodeType)5)
#define kSC__SCNodeType_Struct ((SCNodeType)4)
extern int JB__Syx_CurrFuncID_;
#define kJB__TaskState_Animation ((TaskState)16)
#define kJB__TaskState_Finished ((TaskState)64)
#define kJB__TaskState_HadErrors ((TaskState)8)
#define kJB__TaskState_Paused ((TaskState)2)
#define kJB__TaskState_Started ((TaskState)1)
#define kJB__TaskState_Successful ((TaskState)32)
#define kJB__TaskState_WaitsTillStart ((TaskState)4)
#define kSC__xC2xB5Param_Jump ((ASMParam)32)
#define kSC__xC2xB5Param_NoExpect ((ASMParam)256)
#define kSC__xC2xB5Param_Number ((ASMParam)64)
#define kSC__xC2xB5Param_Output ((ASMParam)1024)
#define kSC__xC2xB5Param_PositionBits ((ASMParam)512)
#define kSC__xC2xB5Param_Signed ((ASMParam)128)
extern LoopInfo SC__nil_Loops;
extern FP_NilTrackerFn SC__nil_NilTable[64];
extern byte SC__nil_OldPrint;
extern ArchonPurger SC__nil_T;
extern CompressionStats JB__MzSt_All;
extern IsaTester SC__IsaTester_T;
extern Dictionary* JB__LD_ClassList;
#define kJB__Saver_RefMark ((int)1073741824)
extern SaverClassInfo* JB__Saver_SaveableList;
extern PicoComms* JB__Pico_Parent_;
extern Random JB__Rnd_Shared;
extern Array* SC__Pac_Ancients;
extern MWrap* SC__Pac_JSMSpace;
#define kSC__Pac_kContinue ((int)254)
#define kSC__Pac_kExit ((int)255)
extern ASMState SC__Pac_Sh;
extern Array* SC__Cpp_Cpp_Includes;
extern Array* SC__Cpp_Cpp_Input;
extern JB_String* SC__Cpp_CppLicenceStr;
extern SCClass* SC__Cpp_CurrClass;
extern JB_String* SC__Cpp_FindGlobalsCpp;
extern Array* SC__Cpp_H_Input;
extern Array* SC__Cpp_H_PostInput;
extern JB_String* SC__Cpp_IfName;
#define kSC__Cpp_kNeedsInnerBrackets ((int)1)
#define kSC__Cpp_kNeedsNoBrackets ((int)2)
#define kSC__Cpp_kNeedsOuterBrackets ((int)0)
extern uint64 SC__Cpp_LubHash;
extern JB_String* SC__Cpp_WhileName;
extern bool SC__Cpp_WriteAPI;
extern bool SC__Cpp_WroteAny;
#define kJB__Wrap_kDelete ((int)2)
#define kJB__Wrap_kFree ((int)1)
#define kJB__Wrap_kNothing ((int)0)
#define kJB__Rec_NonFatal ((JB_StringC*)JB_LUB[2128])
extern Float64 JB__Rec_Progress;
#define kJB__fix_TypeDict ((int)3)
#define kJB__fix_TypeObj ((int)1)
#define kJB__fix_TypeStem ((int)2)
#define kJB__fix_TypeValue ((int)0)
extern byte JB__Flow_Active;
extern bool JB__Flow_AlwaysMove;
extern bool JB__Flow_BreakOnFail;
extern int JB__Flow_Disabled;
extern FlowControl* JB__Flow_Flow;
#define kJB__Flow_Log ((int)1)
#define kJB__Flow_Off ((int)0)
#define kJB__Flow_Validate ((int)2)
#define kSC__Instruction_kTypeConst ((int)2)
#define kSC__Instruction_kTypeFunc ((int)1)
extern Dictionary* SC__Instruction_OpDict;
extern Instruction* SC__Instruction_TypeList[256];
extern Array* JB__Macro_TmpPrms_;
extern uint64 JB__Mrap_MDummy_[2];
extern Array* SC__Imp_AllFiles;
extern SCImport* SC__Imp_Curr;
extern byte SC__Imp_CurrIsManuallyImported;
extern Date SC__Imp_Recent;
extern Dictionary* SC__Imp_Shaders;
extern bool SC__Imp_STDLibTime;
extern SCOperator* SC__Opp_And;
extern SCOperator* SC__Opp_Assigns;
extern SCOperator* SC__Opp_Bnot;
extern int SC__Opp_CustomOperatorScore;
extern Dictionary* SC__Opp_Dict;
extern SCOperator* SC__Opp_LeftShift;
extern SCOperator* SC__Opp_Negative;
extern SCOperator* SC__Opp_Or;
extern SCOperator* SC__Opp_Subtract;
extern Array* SC__PA_FixMe;
extern int SC__xC2xB5Form_Count;
extern Dictionary* SC__xC2xB5Form_Forms;
extern JB_String* JB__File__Speedie;
extern bool JB__File_DebugExecute;
#define kJB__File_IgnoreErrors ((bool)1)
#define kJB__File_O_APPEND ((int)8)
#define kJB__File_O_CREAT ((int)512)
#define kJB__File_O_EXCL ((int)2048)
#define kJB__File_O_RDONLY ((int)0x000)
#define kJB__File_O_RDWR ((int)2)
#define kJB__File_O_TRUNC ((int)1024)
#define kJB__File_O_WRONLY ((int)1)
extern MaterialsLol* SC__MaterialsLol___First;
extern MaterialsLol* SC__MaterialsLol_Iron;
extern MaterialsLol* SC__MaterialsLol_Pellets;
extern MaterialsLol* SC__MaterialsLol_WierdBlock;
extern MaterialsLol* SC__MaterialsLol_Wood;
extern SCIterator* SC__Iter_carray;
extern SCIterator* SC__Iter_pointer;
extern bool SC__Base_ConstantsLoadingOverride;
extern bool SC__Base_CurrVisibility;
#define kSC__Base_DontGoUp ((int)2)
#define kSC__Base_kPurposeAddress ((int)0)
#define kSC__Base_kPurposeDot ((int)2)
#define kSC__Base_kPurposeFunc ((int)1)
#define kSC__Base_kPurposeHider ((int)65536)
#define kSC__Base_kPurposeVar ((int)3)
#define kSC__Base_kPurposeVarDecl ((int)4)
#define kSC__Base_NoErrors ((int)1)
extern SpdProcess* JB__Proc_Parent;
extern byte JB__Err_AutoPrint;
extern Array* JB__Err_CurrSource_;
extern bool JB__Err_KeepStackTrace;
#define kSC__Beh_kBehaviourProto ((int)2)
#define kSC__Beh_kBehaviourProtoRequired ((int)6)
#define kSC__Beh_kBehaviourTable ((int)1)
extern SCFunction* SC__Func__CurrFunc;
extern int SC__Func_DisabledPoints;
extern int SC__Func_FuncArgAndReturnTypes[8];
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

bool JB_App__IsMainThread();

bool JB_App__No(JB_String* Name);

JB_String* JB_App__OrigPath();

void JB_App__PrefSet(JB_String* S, JB_String* Value);

JB_String* JB_App__GetPref(JB_String* S);

JB_String* JB_App__PrefPath();

Message* JB_App__PrefsInit(Date When);

void JB_PrintStackTrace();

void JB_App__SavePrefs();

ErrorInt2 JB_App__Say(JB_String* S, bool Print);

JB_String* JB_App__StackTrace(int Skip, FastString* Fs_in);

JB_String* JB_App__SyntaxAccess(JB_String* Name);

bool JB_App__Yes(JB_String* Name);



// AutoComplete
int SC_AutoComplete__Init_();

bool SC_AutoComplete__IsAFunc(JB_String* S);



// CodeSorter
bool SC_CodeSorter__LeafFunctionsSorter(SCFunction* A, SCFunction* B);

void SC_CodeSorter__LeafsFirst();



// Comp
void SC_Comp__AddFunny(Message* Msg);

SCDecl* SC_Comp__AddGlobalConst(JB_String* Name, SCClass* C, uint /*NilState*/ Dcl);

void SC_Comp__AddGlobalConstFloat(JB_String* Name, SCClass* C, JB_String* Value);

void SC_Comp__AddGlobalConstNum(JB_String* Name, SCClass* C, int64 Value);

bool SC_Comp__AddMain(int Mark);

JB_String* SC_Comp__AddSCProj(JB_String* Path);

Dictionary* SC_Comp__Adj(Message* F);

void SC_Comp__AppBuildLibs(JB_File* Inner);

void SC_Comp__AppBuildOneLib(JB_File* Inner, Message* Lib);

void SC_Comp__AppendCompilerTime(JB_String* S, int Durr);

void SC_Comp__AppleBuildApp(JB_File* Product);

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

JB_File* SC_Comp__FindProject(JB_String* Path);

JB_File* SC_Comp__FindProjectSub(JB_String* Base, JB_String* Path);

JB_String* SC_Comp__FindProjNoSuffix(JB_String* Path);

JB_File* SC_Comp__GeneratedCppsFolder();

SCDecl* SC_Comp__GetTypeVoid();

JB_String* SC_Comp__IdealName();

void SC_Comp__ImportAll();

void SC_Comp__ImportLibs();

void SC_Comp__ImportProj();

int SC_Comp__Init_();

bool SC_Comp__InitBasicFuncs();

int SC_Comp__InitBasicStuff();

void SC_Comp__InitCompiler();

bool SC_Comp__InitTypes();

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

void SC_Comp__PrintErrors(uint /*ErrorSeverity*/ MinSev);

void SC_Comp__PrintResults();

void SC_Comp__PrintStats();

JB_File* SC_Comp__ProductFile();

JB_String* SC_Comp__ProductPath();

JB_String* SC_Comp__Projects();

bool SC_Comp__Reached(JB_String* S);

int SC_Comp__ReachedClassCount();

JB_String* SC_Comp__RenderErrors(JB_ErrorReceiver* Stderr, uint /*ErrorSeverity*/ MinSev);

JB_File* SC_Comp__ScriptLoc(JB_String* F);

bool SC_Comp__ScriptRecompile(JB_File* F, JB_File* Script_build);

void SC_Comp__SetupEnv();

SCClass* SC_Comp__SoftClass(JB_String* Name);

bool SC_Comp__SortModulesAndClasses();

JB_File* SC_Comp__Speedie();

JB_File* SC_Comp__SpeedieDir(JB_String* S);

JB_String* SC_Comp__SpeedieProj();

bool SC_Comp__Stage(JB_String* Name);

SCClass* SC_Comp__FindClassName(JB_String* Name, SCNodeFindMode Mode);

SCClass* SC_Comp__SyntaxAccess(Message* Name);

void SC_Comp__SyntaxAppend(Message* M);

void SC_Comp__TestDate();

void SC_Comp__TestTask();

void SC_Comp__Timer(JB_String* Name);

void SC_Comp__TimerSub(JB_String* S, int Durr);

bool SC_Comp__TimeTest(Date Elapsed);

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



// FastStringOpts
void SC_FastStringOpts__FS(Message* Exp, Message* Getresult);

int SC_FastStringOpts__Init_();

void SC_FastStringOpts__String(Message* Str);



// FB
bool SC_FB__AppOptions_alive(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_arch(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_beep(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_breakonerr(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_check(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_clean(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_codesign(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_cpp(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_crash(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_directtest(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_dosign(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_elf(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_env(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_errortest(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_flow(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_flowmode(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_force(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_gcc(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_help(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_ignorecantsave(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_keepallerrors(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_maxvars(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_nocolor(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_nocompile(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_noisy(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_optimise(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_output_path(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_pack(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_path(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_perry(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_print(JB_String* Name, JB_String* Value, FastString* Purpose);

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

bool SC_FB__ParseArgs();

bool SC_FB__ParseArgsSub(Array* Args);

void SC_FB__ParseOption(JB_Object* Obj);

void SC_FB__SetFlow();

void SC_FB__StopStripping();

JB_String* SC_FB__TryUseProject(JB_String* Path, bool IsScript);



// InbuiltShellArgs
SCNode* SC_InbuiltShellArgs__Collect(Message* Node, SCNode* Name_space, Message* ErrPlace);



// AC
bool SC_AC__Active();

void SC_AC__ActualDefine(Message* Rz, Message* S);

Message* SC_AC__AllTmps();

Message* SC_AC__AutoComplete(Message* Ff, JB_String* Name, JB_String* Purpose);

bool SC_AC__AutoCompleteSorter(autoitem* A, autoitem* B);

Message* SC_AC__AutoJump(Message* Cmd);

void SC_AC__AutoSub(SCNode* Scope, JB_String* Name, Array* Found, int Types, Message* NeedTypeLimit);

void SC_AC__AutoSub2(SCObject* Value, JB_String* Key, JB_String* Src_name, Array* Found, bool Exact, int Types, SCDecl* TypeLimiter);

Message* SC_AC__Backup_Define(SCFile* Myfile, int F, Message* Thg, JB_String* Purpose);

Message* SC_AC__CallFrom(Message* Msg, JB_Object* Found);

Message* SC_AC__CallFromDefine(Message* Msg, SCFunction* Fn, JB_Object* Found);

void SC_AC__CallFromSub(Message* Arg, SCFunction* Fn);

bool SC_AC__CanUseName(SCNode* L);

Message* SC_AC__Check(Message* Cmd);

Message* SC_AC__CmdCleanUp(Message* Arg);

Message* SC_AC__CmdResponse(Message* Cmd);

bool SC_AC__CmdWrap(Message* Arg);

Message* SC_AC__Define(Message* Msg, JB_String* Purpose, JB_Object* Found);

Message* SC_AC__Define_Behaviour(SCFunction* Fn, JB_String* Purpose);

Message* SC_AC__DefineOrCall(Message* Msg, JB_String* Purpose, JB_Object* Found);

Message* SC_AC__Diissplay(Message* Msg, Message* S, JB_String* Purpose);

Message* SC_AC__DoCmd(Message* Cmd);

bool SC_AC__EnterAutoComplete();

Message* SC_AC__ErrorsToPerry();

Message* SC_AC__FindAdj(Message* Msg);

Message* SC_AC__FuncTmps();

SCFunction* SC_AC__GetFunc(Message* Cmd, SCFile* Myfile, int Ff, int N);

SCFunction* SC_AC__GetFunc2(SCFile* Myfile, int F, int N);

SCNode* SC_AC__GetScope(Message* Orig, int* Types);

void SC_AC__IdentifyBetter(Message* Node, JB_String* Name);

int SC_AC__Init_();

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

void JB_API__NilCallBack(JB_String* ErrorMessage);

bool JB_API__NilHandler();



// Constants
void JB_Constants__AddEscape(uint /*byte*/ I, FastString* Fs);

int JB_Constants__Init_();

int JB_Constants__InitCode_();

void JB_Constants__InitConstants();

JB_String* JB_Constants__TestJB();



// LinkMap
void SC_LinkMap__Collect(SCFunction* Self);

void SC_LinkMap__CollectAll();

void SC_LinkMap__CollectFromSource(SCFunction* Self, Message* Src, bool InBranch);

int SC_LinkMap__Init_();

void SC_LinkMap__Store(Array** Darr, SCObject* Obj);



// Linkage
JB_String* SC_Linkage__CombineFlags(JB_String* Name);

void SC_Linkage__CompilerCollect(Message* S);

JB_String* SC_Linkage__GetFlag(JB_String* Name, FastString* Fs);

int SC_Linkage__Init_();

bool SC_Linkage__Interpreter();

SCNode* SC_Linkage__LinkCollect(Message* Node, SCNode* Name_space, Message* ErrPlace);

bool SC_Linkage__SyntaxAccess(JB_String* Name);

bool SC_Linkage__VM();



// MZLab


// Macros
int SC_Macros__Init_();



// Math


// Options
void SC_Options__ColorSet(bool Value);

bool SC_Options__Color();

int SC_Options__Init_();



// PackMaker
bool SC_PackMaker__ActualASMCompile();

void SC_PackMaker__AddAll();

void SC_PackMaker__AddLibGlob(SCDecl* D);

JB_String* SC_PackMaker__BuildInterpreter();

void SC_PackMaker__DoLibGlobs(FastString* Lib);

void SC_PackMaker__DumpStrings(FastString* J);

void SC_PackMaker__FuncLink(FastString* J);

void SC_PackMaker__GlobLink(FastString* J);

int SC_PackMaker__Init_();

void SC_PackMaker__ListPackFuncs(FastString* J);

void SC_PackMaker__MakePack();

void SC_PackMaker__OrderGlobals(FastString* J);

int SC_PackMaker__OrderGlobalsSub();

void SC_PackMaker__PackClass(FastString* J);

void SC_PackMaker__RunAFewTests();

void SC_PackMaker__SortAll();

void SC_PackMaker__SortSub(Array* List, bool Test);

void SC_PackMaker__SyntaxAccessSetWithIntInt64(int V, int64 Value);

void SC_PackMaker__SyntaxAccessSetWithIntObject(int V, JB_Object* Value);

SCFunction* SC_PackMaker__TestFn(JB_String* S);

void SC_PackMaker__WriteLibFuncs(FastString* J);



// PicoNoise


// Platform
bool JB_Platform__CPU_ARM();

bool JB_Platform__CPU_Intel();

JB_String* JB_Platform__CPU_Name();

bool JB_Platform__CPU_PPC();

bool JB_Platform__CPU_Spd();

int JB_Platform__Init_();

void JB_Platform__Log(JB_String* S);

JB_File* JB_Platform__OpenLog();

int JB_Platform__PointerBytes();

bool JB_Platform__Release();



// PostIncrementNil
void SC_PostIncrementNil__Check(Message* Ch);

void SC_PostIncrementNil__Clear();

int SC_PostIncrementNil__Init_();

void SC_PostIncrementNil__SyntaxAppend(Message* Ch);



// RingTree


// SCGame3D
int SC_SCGame3D__Init_();

SCNode* SC_SCGame3D__Love(Message* Node, SCNode* Name_space, Message* ErrPlace);

bool SC_SCGame3D__NeedShader(JB_String* Name);

SCNode* SC_SCGame3D__NeuModel(Message* Node, SCNode* Name_space, Message* ErrPlace);



// SC
int SC__Init_();



// Refs
void SC_Refs__DeclInit(Message* Dcl, SCFunction* Fn, bool IsJustAnArg);

Message* SC_Refs__DecrMulti(SCDecl* D, Message* M);

void SC_Refs__Destructable(Message* Blocker, Message* Arg, Message* Name);

bool SC_Refs__ExitHitsOrGoesPast(Message* Curr, Message* Arg);

bool SC_Refs__ExprNeedsTemping(Message* Child, Message* Name);

Message* SC_Refs__LastUsedRefPlace(Message* Name, Message* Arg);

void SC_Refs__RC_CheckFuncAllocOK(SCFunction* Self, Message* Dot);

void SC_Refs__RC_CheckNoObjPms(Message* Msg);

void SC_Refs__RC_DeclArg(SCDecl* AR, SCFunction* Fn);

void SC_Refs__RC_HandleDisappearing(Message* Msg, int Basis);

void SC_Refs__RC_IgnoreReturn(Message* Msg);

bool SC_Refs__RC_NeedsOwnBlock(Message* Msg, Message* Pp);

void SC_Refs__RC_Rel(Message* Rel);

void SC_Refs__RC_RelConstructor(Message* Rel);

void SC_Refs__RC_RelInit(Message* Rel);

void SC_Refs__RealRefIncr(Message* Name, Message* Dcl);

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

bool SC_Refs__RelNeedsRef(Message* First);

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



// SCTasks
void SC_SCTasks__CollectAll();

int SC_SCTasks__Init_();

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



// Sav
void SC_Sav__BugWorkAround();

void SC_Sav__TestSaver();



// SC_Targets
int SC_SC_Targets__Init_();

bool SC_SC_Targets__SyntaxAccess(JB_String* Name);

void SC_SC_Targets__SyntaxAccessSet(JB_String* Name, bool Value);



// SpdAssembler
bool SC_SpdAssembler__GenerateASM(SCFunction* Fn);

bool SC_SpdAssembler__GenerateASMSub(SCFunction* Fn);

void SC_SpdAssembler__Guard();

int SC_SpdAssembler__Init_();

void SC_SpdAssembler__InitAss();

bool SC_SpdAssembler__OptAddF(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptAddI(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptBFLG(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptBitAnd(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptBitNot(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptBitOr(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptBra(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptCompare(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptCount(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptFADK(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptFunc(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptJump(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptJumpC(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptJumpE(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptNothing(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptRet(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptShifting(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptSubI(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptTabl(FatASM* Self, FatASM* P, FatASM* N);

bool SC_SpdAssembler__OptTern(FatASM* Self, FatASM* P, FatASM* N);

FuncInASM* SC_SpdAssembler__AccessStr(Message* M);



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

ivec2 JB_Terminal__Size();

void JB_Terminal__SyntaxAppend(JB_String* Text, ivec2 V, TerminalColor Colors);

void JB_Terminal__Fail(JB_String* Msg);



// TextAssembler
void SC_TextAssembler__Assemble(Message* Msg);

bool SC_TextAssembler__GetLabel(FatASM* Jumper);

int SC_TextAssembler__Init_();

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

void SC_Ext__ExportAndInstall(Date Elapsed);

Array* SC_Ext__FilterCppsIfAlreadyDone(Array* List, JB_File* Objects);

bool SC_Ext__HasType(Array* CppList, JB_String* Type);

int SC_Ext__Init_();

void SC_Ext__InstallCompiler();

void SC_Ext__InstallOne(JB_File* Test);

bool SC_Ext__IsCompilerAndNeedsInstall();

JB_String* SC_Ext__LibSuff();

JB_String* SC_Ext__LibTmpPath();

JB_File* SC_Ext__LinkOK(JB_File* P);

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
xC2xB5Form* SC_VM_Builder__AddForm(Message* Form);

void SC_VM_Builder__AddxC2xB5Op(JB_String* Name, int Id);

ASM* SC_VM_Builder__BadEncoder(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);

bool SC_VM_Builder__BuildFiles();

void SC_VM_Builder__BuildInstructions(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_VM_Builder__Clean(Message* Msg);

JB_File* SC_VM_Builder__CppLibFile(JB_String* Ch);

Message* SC_VM_Builder__DataTypeCreate(Message* Form, int Fnum);

void SC_VM_Builder__DataTypeModule();

Message* SC_VM_Builder__DefineGet(JB_String* Fname, int Up, int Down);

void SC_VM_Builder__DefineGetSub(JB_String* Fname, int Up, int Down, uint /*byte*/ C, uint /*byte*/ C2);

void SC_VM_Builder__FillEncoders(Message* List, bool ActuallyMakeTheVM);

void SC_VM_Builder__FillTypePrm(JB_String* Fname, int Pname);

void SC_VM_Builder__FinishAcc();

int SC_VM_Builder__FreeID(Message* M, int Ask);

int SC_VM_Builder__GenAcc(Message* Line, int Bit_pos, int Pname, int Max);

void SC_VM_Builder__GenerateForms(Message* Forms, bool DoMore);

void SC_VM_Builder__GenerateOne(Message* Form_msg, int F);

int SC_VM_Builder__Init_();

bool SC_VM_Builder__JustDefineInstructions();

void SC_VM_Builder__MakeJump(Message* Msg, FastString* Jump);

void SC_VM_Builder__MakeMsgCreator(JB_String* Name, xC2xB5Form* Form);

bool SC_VM_Builder__MakeTheVM();

void SC_VM_Builder__MakeVM(Message* Tmp, FastString* Vm);

bool SC_VM_Builder__OKBoomer(Message* Tmp, int X, ASM_Encoder Formenc, Array* R);

void SC_VM_Builder__SafeWrite(JB_String* Name, FastString* Data);

void SC_VM_Builder__VM_FillPos(Message* List, Array* Rz);

void SC_VM_Builder__VM_MakeInstructionSub(Message* Tmp, int Ask, Array* ActuallyMakeTheVM, int ForceID);

bool SC_VM_Builder__VM_NewIns(Message* Tmp, int Ask, Array* ActuallyMakeTheVM);

void SC_VM_Builder__VM_NewInstructions(Message* List, int Amount, Array* Rz);

Message* SC_VM_Builder__VMBox();

void SC_VM_Builder__VMCpp(FastString* Vm, FastString* Jump);

void SC_VM_Builder__VMLine(Message* Line, FastString* Vm);



// __classes__


// __modules__


// image
JB_String* SC_image__ConvertPNGToVOI(JB_String* P);



// main
void SC_AddToStaticSection(Message* Arg, Message* ToAdd);

int SC_ArrayInOrderCheck(int InOrder, Message* Msg);

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

SCNode* SC_ClsCollectTable_description(Message* Node, SCNode* Name_space, Message* ErrPlace);

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

bool SC_DeclSizeSorterRev(SCDecl* A, SCDecl* B);

Message* SC_DefaultStitch(Message* Default, Message* Dcl);

SCObject* SC_DollaDolla(Message* Exp, SCNode* Name_space);

SCNode* SC_DontRemove(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCDecl* SC_DoOpCompare(Message* Exp, SCDecl* Lc, SCDecl* Rc, SCOperator* Comp, SCNode* Name_space);

JB_String* JB_EntityTest();

SCDecl* SC_ExtractDecl(Message* C, SCNode* Name_space, DeclMode Purpose, int Depth);

void fdb(Array* R);

Message* SC_FindBytePos(Message* Node);

Message* SC_FindBytePosSub(Message* Node);

ASMReg SC_fn_asm_table_LIST(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

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

bool SC_FuncPreReader_real(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_todo(SCFunction* Self, Message* Msg);

int JB_Init_();

int JB_SP_AppInit();

int JB_SP_AppInitSub_();

int JB_InitCode_();

SCDecl* SC_IsPointerMath(SCDecl* L, SCDecl* R, SCOperator* Opp, Message* Exp);

void SC_ListFunctionsSub(JB_Object* O, Array* Rz);

SCDecl* SC_LowlevelArrayTransform(Message* Exp, SCClass* Cls);

Message* SC_MakeDecl(JB_String* Type, JB_String* Name, Message* Value, SCDeclInfo Purpose);

Message* SC_MakeDeclOrRel(Message* Into, Message* Namemsg, Message* Value);

void SC_MoveFutureStaticsIn(Message* Msg);

Message* SC_NewDeclWithStrStr(JB_String* Type, JB_String* Name);

Message* SC_NewDeclWithStrMsg(JB_String* Type, Message* RelOrName);

Message* SC_NewDeclNum(SCDecl* D, int64 N, JB_String* VarName, bool Shifts);

Message* SC_NewEqRelWithMsgMsg(Message* L, Message* R);

Message* SC_NewEqRelWithStrStr(JB_String* L, JB_String* R);

Message* SC_NewFnc(JB_String* Name);

Message* SC_NewRejoin();

Message* SC_NewRel(Message* L, Message* R, JB_String* Op);

bool SC_NodeSorter(SCFunction* A, SCFunction* B);

SCDecl* SC_Or_And_Expansion(SCDecl* LC, SCDecl* RC, Message* Exp, SCNode* Name_space);

void JB_Obj_Print(JB_Object* O);

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

Message* SC_SpellOutMsg(Message* Type, Message* Exp, Message* Namemsg);

void SC_TemporalStatements_alert(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_TemporalStatements_break(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_TemporalStatements_crash(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_TemporalStatements_do(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_TemporalStatements_ignore(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Tran_ArgArray(Message* Exp, SCNode* Name_space, SCDecl* Decl);

void SC_Tran_Flow(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Tran_Msg(SCFunction* Fn, Message* Exp, SCNode* Name_space);

void SC_Tran_MsgList(Message* Exp);

void SC_Tran_OptPath(SCFunction* Fn, Message* Node, SCNode* Name_space);

SCObject* SC_TranNegate(Message* F, SCNode* Name_space);

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

int SC_UseCustomOperators(SCDecl* LC, SCDecl* RC, SCOperator* Comp, Message* MsgRel);

SCClass* SC_VecType(bool Isfloat, int Count);



// Tk
Message* JB_Tk__AddToOutput(Message* Output, Message* Curr, Message* Prev, int Pos);

void JB_Tk__AddXMLText(Message* XML, JB_String* S, int Start, int I);

Message* JB_Tk__BarThings(int Start, Syntax Syx);

Message* JB_Tk__BeforeRelSub(int Start, bool Mode);

bool JB_Tk__CanDot();

bool JB_Tk__CanStatement();

Message* JB_Tk__ChainTemporalRels(Message* FirstThing, Message* Opp);

JB_String* JB_Tk__CharName(int Start, uint /*byte*/ Find);

Message* JB_Tk__CloseXML(Message* XML, int I, JB_String* S);

Message* JB_Tk__DecorateThing(Message* R, int Ops);

Message* JB_Tk__DotSub(Syntax Fn, int Start, Message* Parent);

Message* JB_Tk__ElseIfAdder(Message* Prev, Message* Curr);

int JB_Tk__EmbeddedCode(JB_String* Close, Message* Dest, int TmpFlags);

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

Message* JB_Tk__fCharSub(int Pos, int Start, uint /*byte*/ Find);

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

int JB_Tk__FinishParseLoop(int Lines, Message* Output, int After);

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

bool JB_Tk__NoFuncAfter(uint /*byte*/ B);

Message* JB_Tk__NumberSub(int Start, int RealStart);

int JB_Tk__NumEnd(JB_String* NumStr, int Start);

bool JB_Tk__OK();

Message* JB_Tk__OppChain(Message* Opp);

void JB_Tk__Params(Message* Parent, int N);

Message* JB_Tk__ParseItem(Message* Ch, int TemporalFlags, int Ops);

int JB_Tk__ParseLoop(Message* Output, int TmpoFlags);

bool JB_Tk__ParseLoopFlags(Message* Output, JB_String* Ender, int TmpFlags);

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



// _void


// bool
void JB_bool_Append(bool Self, FastString* Fs_in);

JB_String* JB_bool_Render0(bool Self);



// byte
bool JB_byte_CanPrintAsNormalChar(uint /*byte*/ Self);

bool JB_byte_In(uint /*byte*/ Self, uint A, uint B);

bool JB_byte_IsHex(uint /*byte*/ Self);

bool JB_byte_IsInt(uint /*byte*/ Self);

bool JB_byte_IsLetter(uint /*byte*/ Self);

bool JB_byte_IsLower(uint /*byte*/ Self);

bool JB_byte_IsTextLine(uint /*byte*/ Self);

bool JB_byte_IsUpper(uint /*byte*/ Self);

bool JB_byte_IsWhite(uint /*byte*/ Self);

byte JB_byte_LowerCase(uint /*byte*/ Self);

JB_String* JB_byte_Render(uint /*byte*/ Self, FastString* Fs_in);

byte JB_byte_UpperCase(uint /*byte*/ Self);



// cstring
JB_String* JB_cstring_Str(_cstring Self);

void JB_cstring_temp(_cstring Self, FakeJBString* Rz);



// f64
Float64 JB_dbl_Fract(double Self);

JB_String* JB_dbl_RenderFloat(double Self, FastString* Fs_in);



// float
float JB_f_RoundTo(float Self, int To);

float JB_f_Fract(float Self);

float JB_f_Pow(float Self, int N);



// hfloat


// int
bool SC_int_IsNormalMatch(int Self);

bool SC_int_IsSimpleOrPointerCast(int Self);

int JB_int_LowestBit(int Self);

Message* JB_int_Msg(int Self);

int JB_int_OperatorAlign(int Self, int To);

void JB_int_OperatorDownto(int Self, int Other, IntDownRange* Rz);

bool JB_int_OperatorIsa(int Self, uint N);

int JB_int_OperatorMax(int Self, int Other);

int JB_int_OperatorMin(int Self, int Other);

JB_String* JB_int_operatorof(int Self, JB_String* Type, JB_String* Nothing);

int JB_int_OperatorPow(int Self, int A);

IntRange JB_int_OperatorTo(int Self, int Other);

JB_String* JB_int_RenderFS(int Self, FastString* Fs_in);

JB_String* JB_int_RenderSize(int Self, FastString* Fs_in);

bool JB_int_SyntaxAccess(int Self, int Bit);

int JB_int_SyntaxAccessSet(int Self, int Bit, bool Value);

int JB_int_TabsWidth(int Self);

ASMReg SC_int_TextASM(int Self);

int JB_int__Max();

int JB_int__Min();



// int16


// int64
int64 JB_int64_Abs(int64 Self);

bool SC_int64_CanStoreAsIntImmediate(int64 Self);

bool SC_int64_Fits(int64 Self, int Amount, bool Signed);

int64 JB_int64_Log2(int64 Self);

Message* JB_int64_Msg(int64 Self);

Message* SC_int64_MsgForConst(int64 Self, bool AllowShift);

int64 JB_int64_OperatorMax(int64 Self, int64 D);

int64 JB_int64_OperatorMin(int64 Self, int64 D);

JB_String* JB_int64_Render(int64 Self, FastString* Fs_in);

void JB_int64_RenderSizePart(int64 Self, FastString* Fs, int Size, JB_String* Suff);

JB_String* JB_int64_StrSize(int64 Self, FastString* Fs_in);



// int8


// ivec2
bool JB_ivec2_OperatorContains(ivec2 Self, int X);

bool JB_ivec2_OperatorInrange(ivec2 Self, ivec2 P);

bool JB_ivec2_Equals2(ivec2 Self, ivec2 V, bool Aware);



// ivec3


// ivec4
ivec4 JB_ivec4_Shrink(ivec4 Self, int I);

int JB_ivec4_Width(ivec4 Self);



// uint
int64 SC_uint_ConstValue(uint Self);

bool SC_uint_isconst(uint Self);



// uint16


// uint64
bool SC_uint64_CanStoreAsFloatImmediate(uint64 Self);

ivec2 SC_uint64_LongestBitStretch(uint64 Self);



// vec2


// vec3


// vec4


// ASM
ASM SC_ASM_AddK_KSet(ASM Self, uint Value);

ASM SC_ASM_Alloc_AlignSet(ASM Self, uint Value);

ASM SC_ASM_Alloc_AmountSet(ASM Self, uint Value);

ASM SC_ASM_BClear_Shift1Set(ASM Self, uint Value);

ASM SC_ASM_BClear_Shift2Set(ASM Self, uint Value);

ASM SC_ASM_BClear_SignSet(ASM Self, uint Value);

ASM SC_ASM_BFLD_downSet(ASM Self, uint Value);

ASM SC_ASM_BFLD_LSet(ASM Self, uint Value);

ASM SC_ASM_BFLD_signSet(ASM Self, uint Value);

ASM SC_ASM_BFLD_upSet(ASM Self, uint Value);

ASM SC_ASM_Bra_JmpSet(ASM Self, uint Value);

ASM SC_ASM_BraBytes_BytesSet(ASM Self, uint Value);

ASM SC_ASM_BraBytes_JmpSet(ASM Self, uint Value);

ASM SC_ASM_CmpB_InvSet(ASM Self, uint Value);

ASM SC_ASM_CmpB_LSet(ASM Self, uint Value);

ASM SC_ASM_CNTC_cnstSet(ASM Self, uint Value);

ASM SC_ASM_CNTC_offsetSet(ASM Self, uint Value);

ASM SC_ASM_CNTC_sizeSet(ASM Self, uint Value);

ASM SC_ASM_ConstStretchy_CondSet(ASM Self, uint Value);

ASM SC_ASM_ConstStretchy_InvSet(ASM Self, uint Value);

ASM SC_ASM_ConstStretchy_ValueSet(ASM Self, uint Value);

ASM SC_ASM_Convert_LSet(ASM Self, uint Value);

ASM SC_ASM_Convert_ModeSet(ASM Self, uint Value);

ASM SC_ASM_Div2_AddSet(ASM Self, uint Value);

ASM SC_ASM_Div2_LSet(ASM Self, uint Value);

ASM SC_ASM_Div2_ShSet(ASM Self, uint Value);

ASM SC_ASM_Div_KindSet(ASM Self, uint Value);

ASM SC_ASM_Div_LSet(ASM Self, uint Value);

ASM SC_ASM_Float_DSet(ASM Self, uint Value);

ASM SC_ASM_Float_LSet(ASM Self, uint Value);

ASM SC_ASM_FloatConst_HighSet(ASM Self, uint Value);

ASM SC_ASM_ForeignFunc_TableSet(ASM Self, uint Value);

ASM SC_ASM_Func_JUMPSet(ASM Self, uint Value);

ASM SC_ASM_HALT_IsOKSet(ASM Self, uint Value);

ASM SC_ASM_JCmpEq_JmpSet(ASM Self, uint Value);

ASM SC_ASM_JCmpF_CmpSet(ASM Self, uint Value);

ASM SC_ASM_JCmpF_JmpSet(ASM Self, uint Value);

ASM SC_ASM_JCmpI_CmpSet(ASM Self, uint Value);

ASM SC_ASM_JCmpI_JmpSet(ASM Self, uint Value);

ASM SC_ASM_Jump_JUMPSet(ASM Self, uint Value);

ASM SC_ASM_Loop_JmpSet(ASM Self, uint Value);

ASM SC_ASM_MemUtil_NSet(ASM Self, uint Value);

ASM SC_ASM_MemUtil_OpSet(ASM Self, uint Value);

ASM SC_ASM_MinMax_LSet(ASM Self, uint Value);

ASM SC_ASM_MinMax_SignSet(ASM Self, uint Value);

void ASMPrint(ASM Self);

ASM SC_ASM_R1Set(ASM Self, uint Value);

ASM SC_ASM_R2Set(ASM Self, uint Value);

ASM SC_ASM_R3Set(ASM Self, uint Value);

ASM SC_ASM_R4Set(ASM Self, uint Value);

ASM SC_ASM_Read_moveSet(ASM Self, uint Value);

ASM SC_ASM_Read_OffsetSet(ASM Self, uint Value);

ASM SC_ASM_RefDecrMem_CountSet(ASM Self, uint Value);

ASM SC_ASM_RefDecrMem_OffsetSet(ASM Self, uint Value);

ASM SC_ASM_RefSet2_DecrSet(ASM Self, uint Value);

ASM SC_ASM_RefSet2_OffsetSet(ASM Self, uint Value);

ASM SC_ASM_RefSet3_DecrSet(ASM Self, uint Value);

ASM SC_ASM_RefSet3_OffsetSet(ASM Self, uint Value);

ASM SC_ASM_RefSet_DecrSet(ASM Self, uint Value);

ASM SC_ASM_RefSet_FreeSet(ASM Self, uint Value);

ASM SC_ASM_RefSet_IncrSet(ASM Self, uint Value);

ASM SC_ASM_RefSet_MoveSet(ASM Self, uint Value);

ASM SC_ASM_REQ_ModeSet(ASM Self, uint Value);

ASM SC_ASM_REQ_ValSet(ASM Self, uint Value);

ASM SC_ASM_RET_CountSet(ASM Self, uint Value);

ASM SC_ASM_RET_SafeDecrSet(ASM Self, uint Value);

ASM SC_ASM_RET_ValueSet(ASM Self, uint Value);

ASM SC_ASM_RotateConst_InvSet(ASM Self, uint Value);

ASM SC_ASM_RotateConst_RotSet(ASM Self, uint Value);

ASM SC_ASM_RotateConst_ValueSet(ASM Self, uint Value);

ASM SC_ASM_Shift_ShSet(ASM Self, uint Value);

ASM SC_ASM_Swap_LSet(ASM Self, uint Value);

ASM SC_ASM_Table_AddSet(ASM Self, uint Value);

ASM SC_ASM_Table_ModeSet(ASM Self, uint Value);

ASM SC_ASM_Tail_JUMPSet(ASM Self, uint Value);

ASM SC_ASM_Trap_LSet(ASM Self, uint Value);

ASM SC_ASM_Trap_ModeSet(ASM Self, uint Value);

ASM SC_ASM_Trap_SignalSet(ASM Self, uint Value);

ASM SC_ASM_U0_LSet(ASM Self, uint Value);

ASM SC_ASM_U1_LSet(ASM Self, uint Value);

ASM SC_ASM_U2_LSet(ASM Self, uint Value);

ASM SC_ASM_U3_LSet(ASM Self, uint Value);

ASM SC_ASM_U4_LSet(ASM Self, uint Value);

ASM SC_ASM_VecMix_LSet(ASM Self, uint Value);

ASM SC_ASM_VecMix_ModeSet(ASM Self, uint Value);

ASM SC_ASM_Write_moveSet(ASM Self, uint Value);

ASM SC_ASM_Write_OffsetSet(ASM Self, uint Value);

int SC_ASM__Init_();

void SC_ASM__TestASM();

void SC_ASM__TestASMSub(Message* Tests);



// ASMReg
int SC_Reg_BitCount(ASMReg Self);

ASMReg SC_Reg_BoolAnswer(ASMReg Self);

int SC_Reg_CallFunc(ASMReg Self, int V);

bool SC_Reg_CanAddK(ASMReg Self, int64 T);

int64 SC_Reg_Const(ASMReg Self);

void SC_Reg_ConstSet(ASMReg Self, int64 Value);

float SC_Reg_F32(ASMReg Self);

Float64 SC_Reg_F64(ASMReg Self);

FatASM* SC_Reg_FAT(ASMReg Self);

uint SC_Reg_FatIndex(ASMReg Self);

ASMReg SC_Reg_FatIndexSet(ASMReg Self, uint Value);

Float64 SC_Reg_float(ASMReg Self);

ASMReg SC_Reg_HaveAddr(ASMReg Self);

int SC_Reg_IntDivType(ASMReg Self);

bool SC_Reg_IsConst(ASMReg Self, int64 Val);

int SC_Reg_LeftScore(ASMReg Self);

FatASM* SC_Reg_NeedFAT(ASMReg Self);

ASMReg SC_Reg_Negate(ASMReg Self, bool Neg);

int64 SC_Reg_NOP(ASMReg Self);

bool SC_Reg_NopMinusOne(ASMReg Self);

ASMReg SC_Reg_OperatorAs(ASMReg Self, ASMReg A);

ASMReg SC_Reg_OperatorAsnt(ASMReg Self, ASMReg A);

ASMReg SC_Reg_OperatorBitand(ASMReg Self, ASMReg A);

bool SC_Reg_OperatorIsa(ASMReg Self, uint /*DataTypeCode*/ M);

ASMReg SC_Reg_OperatorMul(ASMReg Self, bool B);

ASMReg SC_Reg_OperatorWith(ASMReg Self, ASMReg Dest);

ASMReg SC_Reg_OperatorxE2x80xA2(ASMReg Self, ASMReg Dest);

int SC_Reg_PointerMul(ASMReg Self, Message* Exp, int Swapped);

ASMReg SC_Reg_ReadOrWriteWithMsgRegInt(ASMReg Self, Message* M, ASMReg Ptr, int Index);

FatASM* SC_Reg_ReadOrWriteWithMsgRegIntBool(ASMReg Self, Message* M, ASMReg Ptr, int Index, bool DoWrite);

int SC_Reg_Reg(ASMReg Self);

ASMReg SC_Reg_RegSet(ASMReg Self, int Value);

ASMReg SC_Reg_RequestPos(ASMReg Self);

bool SC_Reg_Signed(ASMReg Self);

bool SC_Reg_SyntaxIs(ASMReg Self, ASMReg R);

ASMReg SC_Reg_SyntaxIsSet(ASMReg Self, ASMReg R, bool Value);

ASMReg SC_Reg_with(ASMReg Self, ASMReg Dest, ASMReg InUse);

ASMReg SC_Reg_xC2xB5TypeSet(ASMReg Self, uint /*DataTypeCode*/ Value);

ASMReg SC_Reg__New();



// ASMType
bool SC_ASMType_SyntaxIs(uint /*ASMType*/ Self, uint /*ASMType*/ T);

ASMReg SC_ASMType__Access(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__ARel(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__Arg(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__BitNot(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__BoolNot(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__BRel(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__Debugger(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__Decl(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__DoFunction(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__DoGlobal(ASMState* Self, Message* Exp, ASMReg Dest, SCDecl* D);

ASMReg SC_ASMType__DoGlobalSub(FatASM* Addr, int Add, Message* Exp);

ASMReg SC_ASMType__DoMath(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__Dot(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__First(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__Ignore(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

int64 SC_ASMType__IncrAmount(ASMReg Upon, int IsSubtract, SCDecl* D);

ASMReg SC_ASMType__Incrementatulatorifier(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__IncrOnAddr(ASMState* Self, Message* F, ASMReg Dest, int Mode, ASMReg Addr, int64 Amount);

ASMReg SC_ASMType__IncrSlowOnAddr(ASMState* Self, Message* F, ASMReg Dest, int Mode, ASMReg Addr, int64 Amount);

int SC_ASMType__Init_();

void SC_ASMType__InitAccess();

ASMReg SC_ASMType__Negative(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__Num(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__Pointer(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__RefCount(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

FatASM* SC_ASMType__RefCountSub(ASMState* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__Return(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__SetRel(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__StatExpr(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__Thg(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__ThgSub(ASMState* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__TypeCast(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__TypeCastSub(ASMState* Self, Message* Exp, ASMReg Dest, ASMReg Sr);

ASMReg SC_ASMType__Unexpected(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);



// CharProp
int JB_CharProp__Init_();



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
int JB_TC__Shift(uint /*DataTypeCode*/ Self);

int SC_TC_ASMConv(uint /*DataTypeCode*/ Self, uint /*DataTypeCode*/ To);

int SC_TC_ASMPart(uint /*DataTypeCode*/ Self);

bool JB_TC_ASMUseIntRegs(uint /*DataTypeCode*/ Self);

DataTypeCode JB_TC_Basictype(uint /*DataTypeCode*/ Self);

SCClass* SC_TC_Better_Numeric_Sub(uint /*DataTypeCode*/ Self, uint /*DataTypeCode*/ T, OpMode Op, Message* Left, Message* Right);

int JB_TC_BitCount(uint /*DataTypeCode*/ Self);

int JB_TC_ByteCount(uint /*DataTypeCode*/ Self);

int JB_TC_Count(uint /*DataTypeCode*/ Self);

void JB_TC_DebugPrint(uint /*DataTypeCode*/ Self);

int SC_TC_FloatIntMerge(uint /*DataTypeCode*/ Self, int Old, Message* S);

int JB_TC_Floatness(uint /*DataTypeCode*/ Self);

bool JB_TC_IsFloat(uint /*DataTypeCode*/ Self);

bool JB_TC_IsInt(uint /*DataTypeCode*/ Self);

bool JB_TC_IsNumeric(uint /*DataTypeCode*/ Self);

bool JB_TC_IsPointer(uint /*DataTypeCode*/ Self);

bool JB_TC_IsSigned(uint /*DataTypeCode*/ Self);

int JB_TC_ItemBitCount(uint /*DataTypeCode*/ Self);

int JB_TC_NumericCount(uint /*DataTypeCode*/ Self);

int SC_TC_NumericCountBoolsToo(uint /*DataTypeCode*/ Self, SCDecl* D);

JB_String* JB_TC_Render(uint /*DataTypeCode*/ Self, FastString* Fs_in);

bool JB_TC_SameBasicType(uint /*DataTypeCode*/ Self, uint /*DataTypeCode*/ B);

DataTypeCode JB_TC_SetSigned(uint /*DataTypeCode*/ Self, bool B);

SCClass* SC_TC_SignedStuffClass(uint /*DataTypeCode*/ Self);

ASMReg SC_TC_zero(uint /*DataTypeCode*/ Self);

Dictionary* JB_TC__Types();



// Date
Duration JB_Date_Ago(Date Self);

int JB_Date_DayOfWeek(Date Self);

int64 JB_Date_Days(Date Self);

Float64 JB_Date_Float64(Date Self);

Duration JB_Date_OperatorMinus(Date Self, Date D);

JB_String* JB_Date_RenderDurr(Date Self, FastString* Fs_in);

JB_String* JB_Date_RenderInt(Date Self, FastString* Fs_in);

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
JB_String* JB_ErrorSeverity_Render(uint /*ErrorSeverity*/ Self, FastString* Fs_in);

bool JB_ErrorSeverity_SyntaxIs(uint /*ErrorSeverity*/ Self, uint /*ErrorSeverity*/ E);

ErrorSeverity JB_ErrorSeverity_SyntaxUsing(uint /*ErrorSeverity*/ Self);

void JB_ErrorSeverity_SyntaxUsingComplete(uint /*ErrorSeverity*/ Self, JB_Object* Idk);

ErrorSeverity JB_ErrorSeverity__Find(JB_String* Name, Message* Err);

int JB_ErrorSeverity__Init_();

Array* JB_ErrorSeverity__InitNames();



// FailableInt


// FileDes


// FileMode


// FileResolveMode


// FileSizeInt


// Float16


// Float64


// FloatRangeConverter


// FloatRangeConverterBasic


// FlowControlStopper
FlowControlStopper JB_FlowControlStopper_SyntaxUsing(FlowControlStopper Self);

void JB_FlowControlStopper_SyntaxUsingComplete(FlowControlStopper Self, JB_Object* Dummy);



// FunctionType


// Ind


// IntRange
bool JB_Rg_Contains1(IntRange Self, int I);

int JB_Rg_Width(IntRange Self);



// MaybeBool
bool JB_MaybeBool_Default(MaybeBool Self);

bool JB_MaybeBool_IsKnown(MaybeBool Self);

bool JB_MaybeBool_KnownFalse(MaybeBool Self);

bool JB_MaybeBool_KnownTrue(MaybeBool Self);

MaybeBool JB_MaybeBool__Known(bool As);



// MoveCode


// MsgParseFlags


// NilCheckMode
NilCheckMode SC_khalai_Activate(NilCheckMode Self);

NilCheckMode SC_khalai_Negate(NilCheckMode Self);

NilCheckMode SC_khalai_Normal(NilCheckMode Self);

bool SC_khalai_SyntaxIs(NilCheckMode Self, NilCheckMode Other);

NilCheckMode SC_khalai_SyntaxIsSet(NilCheckMode Self, NilCheckMode Other, bool Value);



// NilReason
bool SC_NilReason_SyntaxIs(uint /*NilReason*/ Self, uint /*NilReason*/ X);

int SC_NilReason__Init_();



// NilRecord
int SC_NRD_DepthOfVars(NilRecord Self);

NilState SC_NRD_SyntaxAccess(NilRecord Self, int Item);



// NilState
JB_String* SC_NilState_RawName(uint /*NilState*/ Self);

NilState SC_NilState_StatedReal(uint /*NilState*/ Self);

bool SC_NilState_SyntaxIs(uint /*NilState*/ Self, uint /*NilState*/ Type);



// OpMode
bool SC_OpMode_SyntaxIs(OpMode Self, OpMode X);



// PID_Int


// ParserLineAndIndent


// ProcessMode
bool JB_ProcessMode_SyntaxIs(uint /*ProcessMode*/ Self, uint /*ProcessMode*/ M);



// ProcessOwnerMode


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

SyntaxObj* JB_Syx_Obj(Syntax Self);

Message* JB_Syx_OperatorPlus(Syntax Self, JB_String* M);

Message* JB_Syx_PlusNum(Syntax Self, int M);

FP_fpMsgRender JB_Syx_RenderAddr(Syntax Self);

bool JB_Syx_Translateable(Syntax Self);

Syntax JB_Syx__Func(JB_String* Name, Message* Where);

int JB_Syx__Init_();

Syntax JB_Syx__StdNew(FP_fpMsgRender Msg, JB_String* Name, JB_String* LongName, int ID);



// TaskState


// TerminalColor


// jbinLeaver


// mat2


// µParam
int SC_xC2xB5Param_BitSize(uint /*ASMParam*/ Self);

bool SC_xC2xB5Param_IsReg(uint /*ASMParam*/ Self);

bool SC_xC2xB5Param_SyntaxIs(uint /*ASMParam*/ Self, uint /*ASMParam*/ P);

Macro* SC_xC2xB5Param_Which(uint /*ASMParam*/ Self);



// ASM_AddK
ASM* JB_ASM_AddK__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Alloc
ASM* JB_ASM_Alloc__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_BClear
ASM* JB_ASM_BClear__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_BFLD
ASM* JB_ASM_BFLD__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Bra
ASM* JB_ASM_Bra__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_BraBytes
ASM* JB_ASM_BraBytes__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_CNTC
ASM* JB_ASM_CNTC__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_CmpB
ASM* JB_ASM_CmpB__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_ConstStretchy
ASM* JB_ASM_ConstStretchy__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Convert
ASM* JB_ASM_Convert__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Div
ASM* JB_ASM_Div__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Div2
ASM* JB_ASM_Div2__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Float
ASM* JB_ASM_Float__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_FloatConst
ASM* JB_ASM_FloatConst__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_ForeignFunc
ASM* JB_ASM_ForeignFunc__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Func
ASM* JB_ASM_Func__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_HALT
ASM* JB_ASM_HALT__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_JCmpEq
ASM* JB_ASM_JCmpEq__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_JCmpF
ASM* JB_ASM_JCmpF__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_JCmpI
ASM* JB_ASM_JCmpI__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Jump
ASM* JB_ASM_Jump__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Loop
ASM* JB_ASM_Loop__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_MemUtil
ASM* JB_ASM_MemUtil__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_MinMax
ASM* JB_ASM_MinMax__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_REQ
ASM* JB_ASM_REQ__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_RET
ASM* JB_ASM_RET__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Read
ASM* JB_ASM_Read__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_RefDecrMem
ASM* JB_ASM_RefDecrMem__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_RefSet
ASM* JB_ASM_RefSet__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_RefSet2
ASM* JB_ASM_RefSet2__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_RefSet3
ASM* JB_ASM_RefSet3__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_RotateConst
ASM* JB_ASM_RotateConst__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Shift
ASM* JB_ASM_Shift__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Swap
ASM* JB_ASM_Swap__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Table
ASM* JB_ASM_Table__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Tail
ASM* JB_ASM_Tail__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Trap
ASM* JB_ASM_Trap__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_U0
ASM* JB_ASM_U0__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_U1
ASM* JB_ASM_U1__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_U2
ASM* JB_ASM_U2__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_U3
ASM* JB_ASM_U3__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_U4
ASM* JB_ASM_U4__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_VecMix
ASM* JB_ASM_VecMix__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// ASM_Write
ASM* JB_ASM_Write__Encode(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);



// Duration
float JB_Duration_Float(Duration Self);



// HumanDate


// ASM_Encoder


// CollectFunc


// ExprResolver


// Fn_µOpt


// NilTrackerFn


// ParseHandler


// PicoThreadFn


// SaverLoadClass


// ShellOption


// SorterComparer


// SorterComparerBool
void JB_SorterComparerBool_sort(FP_SorterComparerBool Self, Array* A);



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


// fn_ASMConstifier


// fn_OpASM


// fn_asm


// fn_fatasm


// fpDestructor


// fpMsgRender


// fpMsgRenderCpp


// prototype


// JB_ArchonPurger
void SC_nil_BecomeRealSub(ArchonPurger* Self, SCDecl* V);

NilRecord SC_nil_BranchEnter(ArchonPurger* Self, Message* Where);

NilState SC_nil_BranchExit(ArchonPurger* Self, NilRecord A);

NilState SC_nil_BranchExitBool(ArchonPurger* Self, NilRecord A, NilCheckMode Test, NilRecord Orig);

NilState SC_nil_BranchRestore(ArchonPurger* Self, NilRecord A);

NilRecord SC_nil_BranchSwap(ArchonPurger* Self, NilRecord A);

void SC_nil_CheckNilCheck(ArchonPurger* Self, SCFunction* F);

NilState SC_nil_Declare(ArchonPurger* Self, SCDecl* D, uint /*NilState*/ Nd);

NilState SC_nil_DeclareSub(ArchonPurger* Self, SCDecl* D, uint /*NilState*/ Nd);

void SC_nil_Destructor(ArchonPurger* Self);

void SC_nil_FinishNil(ArchonPurger* Self, SCFunction* F);

int SC_nil_NestDepth(ArchonPurger* Self);

NilState SC_nil_Self(ArchonPurger* Self);

Message* SC_nil_StartNil(ArchonPurger* Self, SCFunction* F);

NilState SC_nil__Access(Message* Msg, NilCheckMode Test);

NilState SC_nil__arel(Message* Msg, NilCheckMode Test);

NilState SC_nil__Argument(Message* Msg, NilCheckMode Test);

NilState SC_nil__BecomeReal(SCDecl* Sent, Message* Where, uint /*NilReason*/ Reason, SCDecl* Recv, SCFunction* To);

NilState SC_nil__BecomeRealSub(SCDecl* Sent, Message* Where, uint /*NilReason*/ Reason, SCDecl* Recv, SCFunction* To, uint /*NilState*/ Curr);

NilState SC_nil__BooleanLogic(Message* Msg, NilCheckMode Test);

NilState SC_nil__Bracket(Message* Msg, NilCheckMode Test);

NilState SC_nil__Brel(Message* Msg, NilCheckMode Test);

NilState SC_nil__Char(Message* Msg, NilCheckMode Test);

NilState SC_nil__CompareObjs(Message* Ll, Message* Rr, NilCheckMode Test, SCOperator* Scop);

NilState SC_nil__Continue(Message* Msg, NilCheckMode Test);

NilState SC_nil__Declaration(Message* Msg, NilCheckMode Test);

NilState SC_nil__DetectStillChecks(Message* First);

NilState SC_nil__Dummy(Message* Msg, NilCheckMode Test);

NilState SC_nil__Exit(Message* Msg, NilCheckMode Test);

void SC_nil__ExterminateZergBugs(SCFunction* F);

NilState SC_nil__Fail(Message* Msg, NilCheckMode Test);

NilState SC_nil__FailedReal(SCFunction* To, Message* Where, uint /*NilReason*/ Reason, uint /*NilState*/ State);

NilState SC_nil__Function(Message* Msg, NilCheckMode Test);

NilState SC_nil__If(Message* Msg, NilCheckMode Test);

NilState SC_nil__Ignore(Message* Msg, NilCheckMode Test);

int SC_nil__Init_();

int SC_nil__InitCode_();

NilState SC_nil__Item(Message* Msg, NilCheckMode Test);

NilState SC_nil__FlowJump(Message* Msg, NilCheckMode Test);

NilState SC_nil__JumpWithinBool(Message* Msg, NilCheckMode Test);

void SC_nil__LaunchMothership();

NilState SC_nil__List(Message* Msg, NilCheckMode Test);

void SC_nil__NilParamPass(SCDecl* Recv, SCDecl* Sent, Message* Where, SCFunction* F, uint /*NilState*/ V);

NilState SC_nil__Not(Message* Msg, NilCheckMode Test);

NilState SC_nil__Number(Message* Msg, NilCheckMode Test);

NilState SC_nil__Pointer(Message* Msg, NilCheckMode Test);

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

NilState SC_nil__Swap(Message* Msg, NilCheckMode Test);

NilState SC_nil__Swapity(SCDecl* LD, Message* L, SCDecl* RD, Message* R, uint /*NilState*/ RN);

NilState SC_nil__SyncJump(Message* Msg, NilCheckMode Test);

NilState SC_nil__Tern(Message* Msg, NilCheckMode Test);

NilState SC_nil__Thing(Message* Msg, NilCheckMode Test);

NilState SC_nil__ThingSub(Message* Msg, NilCheckMode Test, SCDecl* Dcl);

void SC_nil__TrackerDummies();

NilState SC_nil__Type(Message* Msg, NilCheckMode Test);

NilState SC_nil__UseAsReal(Message* Msg, NilCheckMode Test, uint /*NilReason*/ Reason);

NilState SC_nil__UseAsRealSub(Message* Ch, NilCheckMode Test, uint /*NilReason*/ Reason, SCDecl* Dcl);

NilState SC_nil__UseChildAsReal(Message* Msg, NilCheckMode Test, uint /*NilReason*/ Reason);

NilState SC_nil__VariableSet(SCDecl* Recv, Message* RecvMsg, SCDecl* Sent, Message* SentMsg, uint /*NilState*/ SentState);

NilState SC_nil__While(Message* Msg, NilCheckMode Test);



// JB_ArgArrayCounter
void SC_ArgArrayCounter_Check(ArgArrayCounter* Self, Message* Exp);

Message* SC_ArgArrayCounter_Do(ArgArrayCounter* Self, JB_String* Name, Message* Item, SCNode* Name_space);



// JB_ClassData
JB_MemoryLayer* JB_ClassData_CreateUseLayer(JB_Class* Self, JB_Object* Obj, JB_Object* Obj2);

void JB_ClassData_Restore(JB_Class* Self);



// JB_CompressionStats
float JB_MzSt_Durr(CompressionStats* Self);

void JB_MzSt_End(CompressionStats* Self);

void JB_MzSt_LiveUpdate(CompressionStats* Self, int Inn, int Outt, bool Compress);

void JB_MzSt_Print(CompressionStats* Self, bool Compression);

JB_String* JB_MzSt_Report(CompressionStats* Self, bool Compression, FastString* Fs_in);

CompressionStats* JB_MzSt_Start(CompressionStats* Self);

int JB_MzSt__Init_();



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

int JB_FastBuff_Position(FastBuff* Self);

void JB_FastBuff_PositionSet(FastBuff* Self, int Value);

void JB_FastBuff_ReadFromSet(FastBuff* Self, JB_String* Value);

int JB_FastBuff_Remaining(FastBuff* Self);

int JB_FastBuff_Size(FastBuff* Self);

JB_String* JB_FastBuff_AccessStr(FastBuff* Self, int Pos, int After);

void JB_FastBuff_SyntaxExpect(FastBuff* Self, JB_String* S);



// JB_FatASM
uint SC_FAT_a(FatASM* Self);

void SC_FAT_aSet(FatASM* Self, uint Value);

void SC_FAT_AddLabelRequest(FatASM* Self, Message* P, int Pos);

void SC_FAT_AddRegNum(FatASM* Self, Message* Src, int Write, int Num);

void SC_FAT_AddRegParam(FatASM* Self, Message* Src, int Write);

uint SC_FAT_b(FatASM* Self);

void SC_FAT_bSet(FatASM* Self, uint Value);

int SC_FAT_BaseOp(FatASM* Self);

int SC_FAT_BytePos(FatASM* Self);

uint SC_FAT_c(FatASM* Self);

void SC_FAT_cSet(FatASM* Self, uint Value);

void SC_FAT_ConstifyBitAnd(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyBitNot(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyBitOr(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyBitSHL(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyBitSHR(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyBitSHS(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyBitXor(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyBoolMul(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyFloatDiv(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyFloatMod(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyFloatMul(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyFloatPlus(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyIntDiv(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyIntMod(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyIntMul(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConstifyIntPlus(FatASM* Self, ASMReg L, ASMReg R);

void SC_FAT_ConvertConst(FatASM* Self, uint /*DataTypeCode*/ Oldtype, uint /*DataTypeCode*/ Newtype);

uint SC_FAT_d(FatASM* Self);

void SC_FAT_dSet(FatASM* Self, uint Value);

void SC_FAT_DebugSet(FatASM* Self, Message* Value);

void SC_FAT_DebugPrint(FatASM* Self);

bool SC_FAT_Dest(FatASM* Self, uint A, ASMReg Info);

ASM SC_FAT_Encode(FatASM* Self);

void SC_FAT_F32Set(FatASM* Self, float Value);

float SC_FAT_F32(FatASM* Self);

void SC_FAT_F64Set(FatASM* Self, Float64 Value);

Float64 SC_FAT_F64(FatASM* Self);

JB_String* SC_FAT_File(FatASM* Self);

int SC_FAT_FileNum(FatASM* Self);

void SC_FAT_FillLabelRequest(FatASM* Self, ASM* Start, ASM* After, int Reg);

void SC_FAT_FloatConvConst(FatASM* Self, FatASM* Src, int DestBitSize);

void SC_FAT_FloatIntConvConst(FatASM* Self, FatASM* Fat, uint /*DataTypeCode*/ Src, uint /*DataTypeCode*/ Dest);

xC2xB5Form* SC_FAT_Form(FatASM* Self);

bool SC_FAT_has(FatASM* Self, int A, int B);

FatASM* SC_FAT_HaveAddr(FatASM* Self);

void SC_FAT_JumpInputSet(FatASM* Self, int A, int V);

void SC_FAT_JumpToSet(FatASM* Self, FatASM* Value);

ASM* SC_FAT_KNST_Encoder(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);

void SC_FAT_LinkedFrom(FatASM* Self, FatASM* New);

bool SC_FAT_match3_2(FatASM* Self, int Reg);

ASM* SC_FAT_NOOP_Encoder(FatASM* Self, ASM* Curr, ASM* After, int64 ExtraInfo);

bool SC_FAT_Nop(FatASM* Self);

void SC_FAT_NumInputSet(FatASM* Self, int A, int V);

bool SC_FAT_OperatorIsa(FatASM* Self, int M);

ASMReg SC_FAT_AsReg(FatASM* Self, ASMReg Info);

uint SC_FAT_out(FatASM* Self);

int SC_FAT_Prm(FatASM* Self, int A, ASMReg Info);

void SC_FAT_Renda(FatASM* Self, FastString* Fs);

void SC_FAT_RendaKnst(FatASM* Self, FastString* Fs, int Sofar);

void SC_FAT_Swap(FatASM* Self, int A, int B);

void SC_FAT_SyntaxExpect(FatASM* Self, JB_String* Error);

bool SC_FAT_SyntaxIs(FatASM* Self, ASMReg Flags);

void SC_FAT_SyntaxIsSet(FatASM* Self, ASMReg Flags, bool Value);

void SC_FAT_TryRotateConst(FatASM* Self);



// JB_FatRange
MaybeBool SC_FatRange_Constness(FatRange* Self);

void SC_FatRange_JumpTo(FatRange* Self, FatASM* Curr);



// JB_FloatRange


// JB_GameFlyingMem


// JB_IntDownRange


// JB_IsaTester
int SC_IsaTester__Init_();

void SC_IsaTester__SyntaxAppend(Message* O);



// JB_LoopInfo
void SC_LoopInfo_BeginLoop(LoopInfo* Self, bool HasExitCond, LoopInfo* Rz);

void SC_LoopInfo_FinishLoop(LoopInfo* Self, Message* Msg);

void SC_LoopInfo_NextLoop(LoopInfo* Self);



// JB_Mat4


// JB_MemoryWorld


// JB_MessagePosition
void JB_MsgPos_Destructor(MessagePosition* Self);

void JB_MsgPos_SyntaxUsingComplete(MessagePosition* Self, JB_Object* Idk);



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

void JB_LD__LoadOne(JB_Class* Cls, int8* Data);



// JB_ObjectSaver
void JB_Saver_AppendInt(ObjectSaver* Self, int64 I);

void JB_Saver_AppendObject(ObjectSaver* Self, JB_Object* O);

void JB_Saver_AppendString(ObjectSaver* Self, JB_String* S);

void JB_Saver_Constructor(ObjectSaver* Self);

void JB_Saver_Destructor(ObjectSaver* Self);

void JB_Saver_Finish(ObjectSaver* Self, Saveable* First);

void JB_Saver__Init();

int JB_Saver__Init_();

void JB_Saver__LoadOne(JB_Class* Cls, int8* Data);



// JB_Object_Behaviour


// JB_Pico
JB_String* JB_Pico_Get(PicoComms* Self, float T);

bool JB_Pico_SendMsg(PicoComms* Self, PicoMessage* A, bool Wait);

bool JB_Pico_SendFS(PicoComms* Self, FastString* Fs, bool Wait);

int JB_Pico__Init_();

PicoComms* JB_Pico__New(JB_StringC* Name, int Noise);

PicoComms* JB_Pico__Parent();



// JB_PicoConfig


// JB_PicoGlobalConfig


// JB_PicoGlobalStats


// JB_PicoMessage
void JB_Pico__FromFS(FastString* Fs, PicoMessage* Rz);



// JB_Random
Float64 JB_Rnd_Float64(Random* Self);

int64 JB_Rnd_RndInt(Random* Self);

void JB_Rnd_LoadProperties(Random* Self, ObjectLoader* Loader);

void JB_Rnd_SaveWrite(Random* Self, ObjectSaver* Saver);

void JB_Rnd_SeedSet(Random* Self, uint64 Value);

Float64 JB_Rnd_SyntaxAccess(Random* Self);

void JB_Rnd_TimeSeed(Random* Self);

int JB_Rnd__Init_();

int JB_Rnd__InitCode_();



// JB_RangeCoderItem


// JB_RetroFloat


// JB_SpeedTester


// JB_StringDigitIterator


// JB_StringLengthSplit


// JB_StructSaveTest
void JB_StructSaveTest_Destructor(StructSaveTest* Self);

void JB_StructSaveTest_LoadProperties(StructSaveTest* Self, ObjectLoader* Loader);

void JB_StructSaveTest_SaveWrite(StructSaveTest* Self, ObjectSaver* Saver);



// JB_jb_vm


// JB_ASMState
void SC_Pac_AddFuncParams(ASMState* Self, SCFunction* Fn);

void SC_Pac_AddLabel(ASMState* Self, Message* Ch);

ASMReg SC_Pac_AddOrSubtractInt(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

bool SC_Pac_Alloc(ASMState* Self, MWrap* J);

ASMReg SC_Pac_ASMBoolBadnessMadness(ASMState* Self, Message* Exp, ASMReg Dest, OpMode Opp);

ASMReg SC_Pac_ASMBoolShrink(ASMState* Self, Message* Exp, ASMReg Dest, ASMReg Ml);

ASMReg SC_Pac_Assign(ASMState* Self, ASMReg Dest, ASMReg Src, Message* Exp);

ASMReg SC_Pac_BFLG_Const(ASMState* Self, Message* Exp, ASMReg Dest, ASMReg Src, uint Up, uint Down);

ASMReg SC_Pac_BitAnd(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_BitMaker(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp, ASM Op);

ASMReg SC_Pac_BitMakerSwap(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp, ASM Op);

ASMReg SC_Pac_BitNot(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_BitOr(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_BitXor(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_BoolConst1(ASMState* Self, Message* B, ASMReg Dest, OpMode Opp, ASMReg Ml);

ASMReg SC_Pac_BoolConst2(ASMState* Self, OpMode Opp, ASMReg Ml, ASMReg Mr);

ASMReg SC_Pac_BoolFromBools(ASMState* Self, Message* Exp, ASMReg Dest, OpMode Opp, ASMReg Ml, ASMReg Mr);

ASMReg SC_Pac_BoolMul(ASMState* Self, ASMReg Dest, ASMReg Bule, ASMReg V, Message* Exp);

FatASM* SC_Pac_BoolTestAndJump(ASMState* Self, Message* Exp, ASMReg Req, OpMode Opp);

ASMReg SC_Pac_BoolValue(ASMState* Self, Message* A, ASMReg Dest, OpMode Opp, Message* B);

ASMReg SC_Pac_BranchAnd(ASMState* Self, Message* A, Message* B, ASMReg Dest);

void SC_Pac_BranchConstAware(ASMState* Self, Message* Cond, bool Neg, FatRange* Rz);

ASMReg SC_Pac_BranchOr(ASMState* Self, Message* A, Message* B, ASMReg Dest);

void SC_Pac_BranchSub(ASMState* Self, Message* Cond, bool Neg, bool CanConst, FatRange* Rz);

void SC_Pac_CloseVDecls(ASMState* Self, int I);

void SC_Pac_CloseVTmps(ASMState* Self, int I);

ASMReg SC_Pac_Compare(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp, int Mode);

ASMReg SC_Pac_CompareFloat(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp, int Mode);

ASMReg SC_Pac_CompareInt(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp, int Mode);

ASMReg SC_Pac_Continue(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_Pac_DeclareMe(ASMState* Self, Message* Where, SCDecl* Type);

void SC_Pac_Destructor(ASMState* Self);

ASMReg SC_Pac_DivFloat(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_Divide(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_DivInt(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_DoMathSub(ASMState* Self, Message* Exp, ASMReg Dest, fn_OpASM Fn);

ASMReg SC_Pac_Equals(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_EqualsInt(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_ExistingBool(ASMState* Self, Message* A, ASMReg Dest);

ASMReg SC_Pac_ExistingVar(ASMState* Self, Message* M);

ASMReg SC_Pac_Exit(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

void SC_Pac_FinishASM(ASMState* Self);

ASMReg SC_Pac_FloatMul(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_FloatPlus(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_FuncPrm(ASMState* Self, Message* Prm);

ASMReg SC_Pac_If(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_Pac_IncrPost(ASMState* Self, Message* Exp, ASMReg Dest, ASMReg ToGrow, int64 Value);

ASMReg SC_Pac_IncrPre(ASMState* Self, Message* Exp, ASMReg Dest, ASMReg Src, int64 Value);

ASMReg SC_Pac_IntMul(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

FailableInt SC_Pac_IntPowerOfTwo(ASMState* Self, ASMReg R, int Sub);

FatASM* SC_Pac_Last(ASMState* Self);

ASMReg SC_Pac_Less(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_LessEq(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

bool SC_Pac_LoadLabelJumps(ASMState* Self);

Message* SC_Pac_LoadTitle(ASMState* Self, Message* M);

ASMReg SC_Pac_MakeConst(ASMState* Self, FatASM* Fat, ASMReg Reg);

ASMReg SC_Pac_MakeConst2(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp, fn_ASMConstifier Fn);

ASMReg SC_Pac_Minus(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_Mod(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_ModFloat(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_ModInt(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_More(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_MoreEq(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_Multiply(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

void SC_Pac_NopWithFat(ASMState* Self, FatASM* R);

void SC_Pac_NopWithFatrange(ASMState* Self, FatRange* R);

ASMReg SC_Pac_NotEq(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

FatASM* SC_Pac_NumToFat(ASMState* Self, Message* Exp, int64 V, ASMReg Reg);

ASMReg SC_Pac_NumToReg(ASMState* Self, Message* Exp, int64 V, ASMReg Reg);

bool SC_Pac_PackMakerInit(ASMState* Self);

ASMReg SC_Pac_Plus(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

void SC_Pac_PrintProgress(ASMState* Self, Message* Exp);

uint64 SC_Pac_PrmCollect(ASMState* Self, Message* Prms, SCFunction* Fn, bool Native);

uint64 SC_Pac_PrmCollectNative(ASMState* Self, Message* Prms, SCFunction* Fn);

ASMReg SC_Pac_Quick1Or1Sub(ASMState* Self, ASMReg Dest, ASMReg L, int Ptoi, Message* Exp);

ASMReg SC_Pac_QuickFloat32Plus(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_QuickFloatDiv(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_QuickFloatMul(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_QuickFloatPlusConstSub(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_QuickIntDiv(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_QuickIntMul(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_SelfDivide(ASMState* Self, ASMReg Dest, Message* Exp);

bool SC_Pac_SetConst(ASMState* Self, Message* List, Message* Orig);

void SC_Pac_SetLength(ASMState* Self);

ASMReg SC_Pac_SHL(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_SHR(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

ASMReg SC_Pac_SimpleTernary(ASMState* Self, ASMReg Dest, ASMReg Ma, ASMReg Mb, Message* Cond);

void SC_Pac_StartFunc(ASMState* Self, SCFunction* Fn);

ASMReg SC_Pac_Subtract(ASMState* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp);

FatASM* SC_Pac_RequestOp(ASMState* Self, int Code, Message* Dbg);

void SC_Pac_Fail(ASMState* Self, Message* Where, JB_String* Msg);

ASMReg SC_Pac_TempOnly(ASMState* Self, Message* Where, ASMReg T);

ASMReg SC_Pac_TempTyped(ASMState* Self, Message* Where, ASMReg T);

ASMReg SC_Pac_Ternary(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

bool SC_Pac_TextFuncSub(ASMState* Self, Message* M);

void SC_Pac_TextOp(ASMState* Self, Message* M);

bool SC_Pac_TextOpSub(ASMState* Self, Message* M);

ASMReg SC_Pac_UniqueLocation(ASMState* Self, Message* Opmsg, ASMReg Dest);

ASMReg SC_Pac_While(ASMState* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_Pac_Zeros(ASMState* Self, ASMReg Dest, Message* Exp);

ASMReg SC_Pac_xC2xB5BoolInto(ASMState* Self, Message* Exp, ASMReg Dest);

ASMReg SC_Pac_xC2xB5Into(ASMState* Self, Message* Exp, ASMReg Dest);

bool SC_Pac__ExpandJSM();

int SC_Pac__Init_();



// JB_ByteMap_Behaviour


// JB_Charset_Behaviour


// JB_CppRefs_Behaviour


// JB_Cpp_Export_Behaviour


// JB_DataObject_Behaviour


// JB_DictionaryReader_Behaviour


// JB_ErrorReceiver_Behaviour


// JB_FastString_Behaviour


// JB_FixedDict_Behaviour


// JB_FlowControl_Behaviour


// JB_Instruction_Behaviour


// JB_LeakTester_Behaviour


// JB_Macro_Behaviour


// JB_MemoryLayer_Behaviour


// JB_Memory_Behaviour


// JB_ProcessOwner_Behaviour


// JB_RefTest_Behaviour


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


// JB_MessageID_Behaviour


// JB_Message_Behaviour


// JB_RangeCoder_Behaviour


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


// JB_SCBetterNode_Behaviour


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

void JB_Object_FailStr(JB_Object* Self, JB_String* Error);

void JB_Object_Fail(JB_Object* Self);

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

bool SC_Cpp__MsgOKToImprove(Message* Msg);

bool SC_Cpp__NeedsDotForC(SCDecl* D);

JB_File* SC_Cpp__Product(JB_String* Name);

void SC_Cpp__RenderInBracketsIfRel(Message* Self, FastStringCpp* Fs);

void SC_Cpp__SmartWrite(JB_String* S, JB_File* F);

JB_String* SC_Cpp__SplitCpp(FastStringCpp* Fs, JB_String* Name);

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

Float64 JB_Wrap_FloatValue(DTWrap* Self);

JB_String* JB_Wrap_Render(DTWrap* Self, FastString* Fs_in);

int64 JB_Wrap_SyntaxAccess(DTWrap* Self);

int64 JB_Wrap_Value(DTWrap* Self);



// JB_DictionaryReader
JB_Object* JB_DictionaryReader_NextValue(DictionaryReader* Self);

SCDecl* SC_DictionaryReader_ValueDecl(DictionaryReader* Self);



// JB_ErrorReceiver
int JB_Rec_BadCount(JB_ErrorReceiver* Self);

bool JB_Rec_CanAddMore(JB_ErrorReceiver* Self, uint /*ErrorSeverity*/ Level);

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

int JB_Rec_PrintErrorsMain(JB_ErrorReceiver* Self, uint /*ErrorSeverity*/ Level, bool PrintCount, bool Shell);

JB_String* JB_Rec_Render(JB_ErrorReceiver* Self, FastString* Fs_in);

int JB_Rec_RenderErrors(JB_ErrorReceiver* Self, FastString* Fs, uint /*ErrorSeverity*/ Level, bool Shell);

int SC_Rec_ReturnErrors(JB_ErrorReceiver* Self, JB_ErrorReceiver* To);

int JB_Rec_ShellPrintErrors(JB_ErrorReceiver* Self);

void JB_Rec_AppendErr(JB_ErrorReceiver* Self, JB_Error* Err);

JB_ErrorReceiver* JB_Rec_SyntaxUsing(JB_ErrorReceiver* Self);

void JB_Rec_SyntaxUsingComplete(JB_ErrorReceiver* Self, JB_Object* Idk);

bool SC_Rec_TooMany(JB_ErrorReceiver* Self);

int JB_Rec__Init_();

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

void SC_FS_appendvoid(FastString* Self, JB_String* S, uint /*byte*/ Extra);

void SC_FS_AppendWidth(FastString* Self, JB_String* S, int Width);

void SC_FS_CArrayAdd(FastString* Self, JB_String* S);

void SC_FS_CArrayAddB(FastString* Self, uint /*byte*/ B);

void SC_FS_CArrayAddB0(FastString* Self, uint /*byte*/ B);

void JB_FS_EncodeLength(FastString* Self, uint64 N);

void JB_FS_AppendInfo(FastString* Self, JB_String* Name, JB_String* Data);

void JB_FS_AppendInfoNum(FastString* Self, JB_String* Name, int64 Data);

void JB_FS_AppendInfoFloat(FastString* Self, JB_String* Name, Float64 Data);

void JB_FS_FieldStart(FastString* Self, JB_String* Name);

void JB_FS_hInt(FastString* Self, uint64 N);

void SC_FS_IncludeH(FastString* Self, JB_String* Name);

void JB_FS_lInt(FastString* Self, uint64 N);

void JB_FS_MsgErrorName(FastString* Self, JB_String* Name);

void JB_FS_Normal(FastString* Self, JB_String* S);

void JB_FS_PrintNicely(FastString* Self, JB_String* S);

void SC_FS_PrintStatType(FastString* Self, JB_String* Name, int Count);

void JB_FS_ProblemsFound(FastString* Self, int Count);

JB_String* JB_FS_Render(FastString* Self, FastString* Fs_in);

void JB_FS_RenderSpeed(FastString* Self, float Seconds, int64 BytesIn, int64 BytesOut, JB_String* Name);

void JB_FS_AppendMultiStr(FastString* Self, JB_String* Data, int Count);

void JB_FS_AppendFastString(FastString* Self, FastString* Fs);

void JB_FS_AppendUint(FastString* Self, uint Data);

void JB_FS_AppendInt32(FastString* Self, int Data);

void JB_FS_AppendBool(FastString* Self, bool B);

void JB_FS_AppendBuff(FastString* Self, FastBuff* B);

void JB_FS_SyntaxAppend(FastString* Self, Message* Msg);

FastString* JB_FS__Use(JB_Object* Other);



// JB_FixedDict


// JB_FlowControl
void JB_Flow_AddByte(FlowControl* Self, uint /*byte*/ Value);

FlowControl* JB_Flow_Constructor(FlowControl* Self, JB_String* OutPath, JB_String* InPath);

void JB_Flow_Destructor(FlowControl* Self);

void JB_Flow_Fail(FlowControl* Self, JB_String* Found, JB_String* Expected, JB_String* InputName);

void JB_Flow_Flush(FlowControl* Self);

bool JB_Flow_TestByte(FlowControl* Self, uint /*byte*/ Value);

FlowControlStopper JB_Flow__Activate(JB_String* Name);

JB_String* JB_Flow__AskPath(JB_String* Name, bool WantValidate);

FlowControlStopper JB_Flow__Attempt(JB_String* Name);

bool JB_Flow__Cond(bool Value);

void JB_Flow__GetActiveFlow();

int JB_Flow__Init_();

int JB_Flow__InitCode_();

void JB_Flow__InputStrings(Array* Lines, JB_String* Name);

void JB_Flow__Input(JB_String* Data, JB_String* Name);

void JB_Flow__InputLine(JB_String* Data, JB_String* Name);

void JB_Flow__Stop();

void JB_Flow__SyntaxAppend(uint /*byte*/ Value);

bool JB_Flow__Cond2(bool Value);



// JB_Instruction
void SC_Instruction_Const(Instruction* Self);

Instruction* SC_Instruction_Constructor(Instruction* Self, JB_String* FormName, JB_String* Name, int Pos);

void SC_Instruction_Destructor(Instruction* Self);

bool SC_Instruction_IsSetConst(Instruction* Self);

JB_String* SC_Instruction_Render(Instruction* Self, FastString* Fs_in);

void SC_Instruction__Add(JB_String* FormName, JB_String* Name, int Pos);

int SC_Instruction__Init_();

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



// JB_Memory
MWrap* JB_Mrap_ConstructorPtr(MWrap* Self, int ItemCount, int ItemSize, byte* Ptr, uint /*byte*/ DeathAction);

void JB_Mrap_Destructor(MWrap* Self);

void JB_Mrap_LengthSet(MWrap* Self, int Value);

byte* JB_Mrap_Ptr(MWrap* Self);

bool JB_Mrap_SetSize(MWrap* Self, int Value);

void JB_Mrap_SizeSet(MWrap* Self, int Value);

Array* JB_Mrap__CollectLeaks_(JB_Object* Self);

int JB_Mrap__Init_();

MWrap* JB_Mrap__Object(int Count, int ItemSize);

void jbl(JB_Object* Self);

byte* JB_Mrap__Zalloc(int N);



// JB_MemoryLayer


// JB_ProcessOwner
bool JB_PID_IsRunning(ProcessOwner* Self);



// JB_RefTest
RefTest* SC_RefTest_Constructor(RefTest* Self);

void SC_RefTest_Destructor(RefTest* Self);



// JB_SCImport
bool SC_Imp_CanBan(SCImport* Self, SCFile* Scf);

SCImport* SC_Imp_Constructor(SCImport* Self, JB_File* F, bool Builtin);

void SC_Imp_Destructor(SCImport* Self);

SCFile* SC_Imp_ImportDir(SCImport* Self, JB_File* F);

void SC_Imp_ImportMsg(SCImport* Self, Message* J);

void SC_Imp_ImportMsgSub(SCImport* Self, Message* J);

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

SCNode* SC_Imp__DoImport(Message* Node, SCNode* Name_space, Message* ErrPlace);

void SC_Imp__ExportShaders();

SCImport* SC_Imp__FindImport(JB_String* S);

JB_File* SC_Imp__FindInputFolder(JB_File* F);

SCImport* SC_Imp__ImportPath(JB_String* Path, JB_File* F, int ImportDepth, bool Builtin);

int SC_Imp__Init_();

bool SC_Imp__IsInputName(JB_String* Name);

void SC_Imp__NoProj();

bool SC_Imp__Sorter(JB_Object* A, JB_Object* B);



// JB_SCNodeRenamer
void SC_NR_Collect(SCNodeRenamer* Self, Message* Msg, JB_String* Name, Message* After);

void SC_NR_CollectDclThg(SCNodeRenamer* Self, Message* DclThg);

void SC_NR_CollectSelfs(SCNodeRenamer* Self, Message* Root);

SCNodeRenamer* SC_NR_Constructor(SCNodeRenamer* Self);

void SC_NR_Destructor(SCNodeRenamer* Self);

void SC_NR_Rename(SCNodeRenamer* Self, Message* Name);

void SC_NR_Uniqueify(SCNodeRenamer* Self, SCNode* P);



// JB_SCObject
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

void SC_SCObject_NameConflict(SCObject* Self, SCObject* Old, JB_String* Name);

SCObject* SC_SCObject_NextDisplay(SCObject* Self, bool Exact);

void SC_SCObject_Fail(SCObject* Self, JB_String* Error);

bool SC_SCObject_SyntaxIs(SCObject* Self, SCNodeInfo I);

void SC_SCObject_SyntaxIsSet(SCObject* Self, SCNodeInfo I, bool Value);



// JB_SCOperator
bool SC_Opp_CanOpCompare(SCOperator* Self, SCDecl* Lc, SCDecl* Rc, Message* Exp);

JB_String* SC_Opp_CaseAwareStr(SCOperator* Self);

SCOperator* SC_Opp_Constructor(SCOperator* Self, JB_String* Name, fn_OpASM ASM, OpMode Mode);

void SC_Opp_Destructor(SCOperator* Self);

void SC_Opp_InitComp(SCOperator* Self, JB_String* Name_);

bool SC_Opp_IsCompOrSet(SCOperator* Self);

JB_String* SC_Opp_Render(SCOperator* Self, FastString* Fs_in);

void SC_Opp_SetFuncNameSet(SCOperator* Self, JB_String* S);

JB_String* SC_Opp_SimpleName(SCOperator* Self);

bool SC_Opp_SyntaxEquals(SCOperator* Self, JB_String* S, bool Aware);

OpMode SC_Opp_SyntaxIs(SCOperator* Self, OpMode X);

void SC_Opp__AddBasic();

SCOperator* SC_Opp__AddBit(JB_String* S, JB_String* FuncName, fn_OpASM ASM, OpMode Mode);

void SC_Opp__AddComp(JB_String* S, fn_OpASM ASM, OpMode Mode);

SCOperator* SC_Opp__AddCustom(JB_String* S);

void SC_Opp__AddMath(JB_String* S, JB_String* FuncName, fn_OpASM ASM, OpMode Mode);

void SC_Opp__BuildOrder();

void SC_Opp__Init();

int SC_Opp__Init_();

SCOperator* SC_Opp__Lookup(Message* Opch);

void SC_Opp__OppositeComp(JB_String* A, JB_String* B);



// JB_SCParamArray
void SC_PA_AddParam(SCParamArray* Self, Message* Item);

void SC_PA_AddSub(SCParamArray* Self, Message* M);

Message* SC_PA_AddTestedParam(SCParamArray* Self, Message* Item, SCNode* Name_space);

SCParamArray* SC_PA_Constructor(SCParamArray* Self, Message* Exp);

SCNode* SC_PA_DetectDotSuper(SCParamArray* Self, SCNode* Curr, SCNode* Arg_space);

int SC_PA_IgnoreSelfContain(SCParamArray* Self);

bool SC_PA_IsModule(SCParamArray* Self);

bool SC_PA_IsSelfCon(SCParamArray* Self);

Array* SC_PA_MacroCopyArgs(SCParamArray* Self);

int SC_PA_MacroSize(SCParamArray* Self);

bool SC_PA_MadeError(SCParamArray* Self);

JB_String* SC_PA_ModuleName(SCParamArray* Self);

SCFunction* SC_PA_MultipleMatchingFunctions(SCParamArray* Self, int TypeCast, SCFunction* F, SCFunction* R);

bool SC_PA_PreReadTypes(SCParamArray* Self, SCNode* Name_Space, Message* P, Message* Side);

JB_String* SC_PA_Render(SCParamArray* Self, FastString* Fs_in);

JB_String* SC_PA_RenderKind(SCParamArray* Self);

void SC_PA_SideSet(SCParamArray* Self, Message* Value);

void SC_PA_StructExtract(SCParamArray* Self, SCDecl* Type);

void SC_PA_StructLover(SCParamArray* Self, SCDecl* Type, SCFunction* Fn);

Message* SC_PA_SyntaxAccess(SCParamArray* Self, int I);

int SC_PA__Init_();

void SC_PA__PostStructFix();



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
JB_String* JB_Str_AfterByte(JB_String* Self, uint /*byte*/ B, int Last);

JB_String* JB_Str_ArgName(JB_String* Self);

JB_String* SC_Str_ArgsMatchError(JB_String* Self, bool TypeCast);

JB_String* JB_Str_ArgValue(JB_String* Self);

JB_String* JB_Str_BackToApp(JB_String* Self);

JB_String* JB_Str_Before(JB_String* Self, JB_String* S);

JB_String* JB_Str_BeforeLastByte(JB_String* Self, uint /*byte*/ B, int Fudge);

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

int JB_Str_Count(JB_String* Self, uint /*byte*/ B);

ErrorInt2 SC_Str_DebugExecute(JB_String* Self, Array* Args, FastString* Out, FastString* Errs);

JB_String* JB_Str_Decompress(JB_String* Self, int Lim, CompressionStats* St);

Dictionary* JB_Str_Dict(JB_String* Self, uint /*byte*/ Sep);

JB_String* JB_Str_Digest(JB_String* Self);

bool JB_Str_EndsWith(JB_String* Self, JB_String* S, bool Aware);

JB_String* JB_Str_Escape(JB_String* Self);

JB_String* JB_Str_EscapeChr(JB_String* Self);

bool JB_Str_EscapeTest(JB_String* Self);

JB_String* JB_Str_Ext(JB_String* Self);

JB_File* JB_Str_AsFile(JB_String* Self);

JB_File* JB_Str_ChildFile(JB_String* Self, JB_String* Ch);

bool JB_Str_FileExists(JB_String* Self);

JB_File* JB_Str_FileThatExists(JB_String* Self, JB_String* Operation);

Ind JB_Str_FindByte(JB_String* Self, uint /*byte*/ Find, int Start, int After);

Ind JB_Str_Find(JB_String* Self, CharSet* Cs, int Start, int After);

Ind JB_Str_FindSlash(JB_String* Self, int From);

int JB_Str_FindTrailingSlashes(JB_String* Self);

Float64 JB_Str_Float(JB_String* Self);

StringReader* JB_Str_In(JB_String* Self, JB_String* Header, int ChunkSize);

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

Ind JB_Str_JBFind(JB_String* Self, uint /*byte*/ Find, int Off, int After);

byte JB_Str_Last(JB_String* Self, int Minus);

int JB_Str_LineCount(JB_String* Self);

JB_File* SC_Str_MakeAndGoInto(JB_String* Self);

ErrorInt JB_Str_MakeEntirePath(JB_String* Self, bool Last);

JB_String* JB_Str_Moat(JB_String* Self);

Message* JB_Str_Msg(JB_String* Self);

JB_String* JB_Str_Name(JB_String* Self);

JB_String* SC_Str_NicerClassName(JB_String* Self);

bool JB_Str_ContainsString(JB_String* Self, JB_String* S);

bool JB_Str_ContainsByte(JB_String* Self, uint /*byte*/ B);

Array* JB_Str_OperatorDivide(JB_String* Self, uint /*byte*/ Sep);

bool JB_Str_OperatorEndsWith(JB_String* Self, JB_String* S);

bool JB_Str_OperatorIsa(JB_String* Self, JB_String* S);

int JB_Str_OperatorMinus(JB_String* Self, JB_String* S);

JB_String* JB_Str_MulBool(JB_String* Self, bool B);

JB_String* JB_Str_OperatorMul(JB_String* Self, int N);

JB_String* JB_Str_PlusByte(JB_String* Self, uint /*byte*/ B);

JB_String* JB_Str_OperatorPlusWithCstring(JB_String* Self, _cstring C);

bool JB_Str_OperatorStarts(JB_String* Self, JB_String* S);

bool SC_Str_OptionBool(JB_String* Self);

int SC_Str_OptionInt(JB_String* Self);

FastString* JB_Str_Out(JB_String* Self, bool Clear);

Ind JB_Str_OutByteWithByteIntInt(JB_String* Self, uint /*byte*/ Find, int Start, int After);

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

JB_String* JB_Str_Pluralize(JB_String* Self, int Amount, JB_String* Nothing);

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

Array* JB_Str_Split(JB_String* Self, uint /*byte*/ Sep);

JB_String* JB_Str_Squeeze(JB_String* Self);

StringReader* JB_Str_Stream(JB_String* Self);

JB_String* JB_Str_SyntaxAccess(JB_String* Self, JB_String* S);

bool JB_Str_SyntaxAppend(JB_String* Self, JB_String* S);

int JB_Str_CompareStr(JB_String* Self, JB_String* Other, bool Aware);

int JB_Str_CompareInt(JB_String* Self, int Other, bool Aware);

bool JB_Str_EqualsInt(JB_String* Self, int Other, bool Aware);

void JB_Str_Fail(JB_String* Self);

JB_String* JB_Str_TitleCase(JB_String* Self, FastString* Fs_in);

bool SC_Str_trap(JB_String* Self, Message* Msg);

JB_String* JB_Str_Shorten(JB_String* Self, int N);

JB_String* JB_Str_TrimExtAndPath(JB_String* Self, bool KeepPath);

JB_String* JB_Str_TrimFirst(JB_String* Self, uint /*byte*/ B);

int JB_Str_TrimLastSub(JB_String* Self, uint /*byte*/ B);

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

JB_String* JB_Str__FromPico(PicoMessage* M);

int JB_Str__Sorter(JB_Object* A, JB_Object* B);

JB_StringC* JB_Str__Wrap(_cstring Addr);



// JB_StringFields
StringFields* JB_FI_Constructor(StringFields* Self, JB_String* Source, uint /*byte*/ Sep);

void JB_FI_Destructor(StringFields* Self);

JB_String* JB_FI_Field(StringFields* Self, Ind Prev, Ind Curr);

Ind JB_FI_NextSep(StringFields* Self, int Prev);



// JB_StringReader
int JB_SS_Byte(StringReader* Self);

void JB_SS_CompressInto(StringReader* Self, JB_Object* Dest, int Strength, CompressionStats* St);

StringReader* JB_SS_Constructor(StringReader* Self, JB_String* Data);

StringReader* JB_SS_ConstructorFile(StringReader* Self, JB_File* File, int ChunkSize);

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

void JB_SS_Fail(StringReader* Self, JB_String* Error);

bool JB_SS_Test(StringReader* Self, JB_String* Header);



// JB_SyntaxObj
SyntaxObj* JB_Fn_Constructor(SyntaxObj* Self, FP_fpMsgRender Msg, JB_String* Name, int ID);

void JB_Fn_Destructor(SyntaxObj* Self);

JB_String* JB_Fn_Render(SyntaxObj* Self, FastString* Fs_in);



// JB_TerminalCell
TerminalCell* JB_TerminalCell_ConstructorAuto(TerminalCell* Self, int Color, JB_String* Text);

void JB_TerminalCell_Destructor(TerminalCell* Self);



// JB_TokenHandler


// JB_autoitem
autoitem* SC_autoitem_ConstructorAuto(autoitem* Self, JB_String* Sort, JB_String* Insert, SCObject* Value, JB_String* Display, bool Exact, int Type);

int SC_autoitem_Depth(autoitem* Self);

void SC_autoitem_Destructor(autoitem* Self);

bool SC_autoitem_OKBy(autoitem* Self, autoitem* Prev);



// JB_µForm
void SC_xC2xB5Form_AddP(xC2xB5Form* Self, int Size, uint /*ASMParam*/ P);

void SC_xC2xB5Form_AddRemainder(xC2xB5Form* Self, int U);

xC2xB5Form* SC_xC2xB5Form_Constructor(xC2xB5Form* Self, Message* Tmp);

void SC_xC2xB5Form_Destructor(xC2xB5Form* Self);

void SC_xC2xB5Form_LoadParam(xC2xB5Form* Self, JB_String* Pl, Message* Place, bool IsLast);

JB_String* SC_xC2xB5Form_Render(xC2xB5Form* Self, FastString* Fs_in);

ASMParam SC_xC2xB5Form_AccessInt(xC2xB5Form* Self, int I);

int SC_xC2xB5Form__Init_();

xC2xB5Form* SC_xC2xB5Form__NeedForm(JB_String* Form, Message* M);



// JB_µFunc
FuncInASM* SC_FuncInASM_Constructor(FuncInASM* Self, SCFunction* Fn, FatASM* IR);

void SC_FuncInASM_Destructor(FuncInASM* Self);

JB_String* SC_FuncInASM_Render(FuncInASM* Self, FastString* Fs_in);

ASM* SC_FuncInASM_xC2xB5Render(FuncInASM* Self, ASM* Where, ASM* After);

MWrap* SC_FuncInASM_xC2xB5Test(FuncInASM* Self);



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

JB_Object* JB_Dict_Value0(Dictionary* Self, JB_String* Key);

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

Array* JB_File_List(JB_File* Self, bool Invis, bool AsFile);

Array* JB_File_ListFiles(JB_File* Self, bool Invis);

bool JB_File_MustExist(JB_File* Self, JB_String* Operation);

bool JB_File_Opened(JB_File* Self);

bool JB_File_OperatorInside(JB_File* Self, JB_File* F);

bool JB_File_NewerThanFile(JB_File* Self, JB_File* F);

bool JB_File_OperatorIsNewerThan(JB_File* Self, Date F);

JB_File* JB_File_OperatorPlus(JB_File* Self, JB_String* S);

JB_File* JB_File_Parent(JB_File* Self);

Message* JB_File_Parse(JB_File* Self, int Lim, bool AllowMissing);

JB_File* JB_File_Sibling(JB_File* Self, JB_String* Name);

bool JB_File_SmartDataSet(JB_File* Self, JB_String* Nieu);

JB_File* JB_File_SyntaxAccess(JB_File* Self, JB_String* Name);

void JB_File_SyntaxAppend(JB_File* Self, JB_String* Data);

bool JB_File_SyntaxEquals(JB_File* Self, JB_String* S, bool Aware);

void JB_File_Fail(JB_File* Self, JB_String* Error);

bool SC_File_TestBatch(JB_File* Self);

bool SC_File_TestSpeedie(JB_File* Self, JB_String* V);

ErrorInt2 JB_File_Touch(JB_File* Self);

JB_String* JB_File__Applications();

int JB_File__Init_();

JB_File* JB_File__Logs();

JB_String* JB_File__PrefPath();

JB_File* JB_File__Prefs(JB_String* Name);

JB_String* JB_File__Speedie();



// JB_JBin
jbinLeaver JB_bin_Add(FastString* Self, Syntax Type, JB_String* Name, bool Into);

void SC_bin_Add(FastString* Self, FuncInASM* Fn);

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

void JB_Tree_Clear(JB_List* Self);

JB_List* JB_Tree_FlatLast(JB_List* Self);

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



// JB_ExistingFile


// JB_JeeboxFile


// JB_Message
void JB_Msg_Acc__(Message* Self, FastString* Fs);

Message* JB_Msg_AccessAdd(Message* Self, JB_String* Key);

void JB_Msg_CantFind(Message* Self, Syntax S, JB_String* Name, Message* Found);

bool SC_Msg_ACInIsa(Message* Self);

FatASM* JB_Msg_ADD(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

void SC_Msg_AddBefore(Message* Self, Message* Before, Message* NewItem);

FatASM* JB_Msg_ADDK(Message* Self, ASMReg R1, ASMReg R2, int K);

FatASM* JB_Msg_ADDR(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4);

void JB_Msg_Adj__(Message* Self, FastString* Fs);

FatASM* JB_Msg_ADPK(Message* Self, ASMReg R1, ASMReg R2, int K);

int JB_Msg_After(Message* Self);

void JB_Msg_AfterSet(Message* Self, int Value);

FatASM* JB_Msg_ALLO(Message* Self, ASMReg R1, int Align, int Amount);

bool SC_Msg_AllowedMoveToInit(Message* Self);

void SC_Msg_AlmostAppend(Message* Self, Message* V);

Message* JB_Msg_Ancestor(Message* Self, Syntax F);

int SC_Msg_AndOrExpansionTest(Message* Self);

bool SC_Msg_AOrBExpand(Message* Self);

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

SCDecl* SC_Msg_ASMDecl(Message* Self);

ASMType SC_Msg_ASMType(Message* Self);

void SC_Msg_ASMTypeSet(Message* Self, uint /*ASMType*/ Value);

void SC_Msg_AssignsFix(Message* Self, SCFunction* F);

int SC_Msg_Autocomplete_State(Message* Self);

JB_String* SC_Msg_AutoCompleteDecl(Message* Self);

SCFunction* SC_Msg_AutoMsgFunc(Message* Self);

SCFunction* SC_Msg_AutoMsgFuncFn(Message* Self);

void SC_Msg_AvoidSafeDecr(Message* Self);

void JB_Msg_Back__(Message* Self, FastString* Fs);

void JB_Msg_Badj__(Message* Self, FastString* Fs);

FatASM* JB_Msg_BAND(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* JB_Msg_BCLR(Message* Self, ASMReg R1, ASMReg R2, int Shift1, int Shift2, int Sign);

void JB_Msg_BecomeStr(Message* Self, Syntax Fn, JB_String* Name);

void JB_Msg_BecomeNum(Message* Self, int64 Num);

void JB_Msg_BecomeMsg(Message* Self, Message* Src);

void SC_Msg_BecomeWithOpp(Message* Self, SCOperator* Op);

void SC_Msg_BecomeWithFunc(Message* Self, SCFunction* Func);

void SC_Msg_BecomeAppend(Message* Self, JB_String* S);

void JB_Msg_BecomeMacro(Message* Self, Macro* M, Array* Prms);

void SC_Msg_BecomeNil(Message* Self);

void SC_Msg_BecomeSetRel(Message* Self);

void SC_Msg_BecomeTarget(Message* Self);

FatASM* JB_Msg_BFLG(Message* Self, ASMReg R1, ASMReg R2, int Up, int Down, int Sign);

void JB_Msg_Bin__(Message* Self, FastString* Fs);

void JB_Msg_binn__(Message* Self, FastString* Fs);

void JB_Msg_BinnRender(Message* Self, FastString* Fs, JB_String* Sepa, JB_String* Sepb);

ErrorSeverity SC_Msg_Blind(Message* Self);

SCBlockage SC_Msg_Blocks(Message* Self);

void SC_Msg_BlocksSet(Message* Self, int Value);

FatASM* JB_Msg_BNAN(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* JB_Msg_BNOR(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* JB_Msg_BNOT(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* JB_Msg_BOR(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

void JB_Msg_Bra__(Message* Self, FastString* Fs);

SCDecl* SC_Msg_BraDeclfind(Message* Self);

void JB_Msg_BRel__(Message* Self, FastString* Fs);

FatASM* JB_Msg_BSHL(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* JB_Msg_BSHR(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* JB_Msg_BSHS(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* JB_Msg_BSTT(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4);

bool SC_Msg_BuildRunTask(Message* Self, Message* Fields, int Level);

void SC_Msg_BuildTask(Message* Self, Message* Fields, Message* Root, int Level);

Message* SC_Msg_BunchFixPrepare(Message* Self);

void SC_Msg_BunchFixSub(Message* Self, Message* Subject, Message* Stuff);

void SC_Msg_BunchlessFix(Message* Self);

FatASM* JB_Msg_BXOR(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

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

FatASM* JB_Msg_CMPB(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Inv);

FatASM* JB_Msg_CMPF(Message* Self, ASMReg R1, ASMReg R2, int Cmp, int Jmp);

FatASM* JB_Msg_CMPI(Message* Self, ASMReg R1, ASMReg R2, int Cmp, int Jmp);

void JB_Msg_Cnj__(Message* Self, FastString* Fs);

FatASM* JB_Msg_CNTC(Message* Self, ASMReg R1, ASMReg R2, int Offset, int Cnst, int Size);

FatASM* JB_Msg_CNTD(Message* Self, ASMReg R1, ASMReg R2, int Offset, int Cnst, int Size);

bool SC_Msg_CollectAGlobalDecl(Message* Self, SCNode* Scarg);

Message* SC_Msg_CollectDclName(Message* Self);

SCDecl* SC_Msg_CollectDecl(Message* Self, SCNode* P, SCNode* Recv, DeclMode Mode, SCClass* Cls, SCFunction* FuncPrmz);

void SC_Msg_CollectFromBody(Message* Self, SCNode* Scarg);

JB_String* SC_Msg_CollectFuncTableName(Message* Self);

Message* SC_Msg_CollectionPlace(Message* Self);

bool SC_Msg_CollectOneParam(Message* Self, SCFunction* Func, SCNode* Recv, SCClass* Cls);

JB_String* SC_Msg_CollectUsage(Message* Self);

Message* JB_Msg_ConfArg(Message* Self);

void SC_Msg_ConfTake(Message* Self, Message* Dest, JB_String* Name);

Message* SC_Msg_ConstantExpandSub(Message* Self);

bool SC_Msg_ConstIntValue(Message* Self, SCNode* Name_space, int64* V);

bool SC_Msg_ConstIntValueSub(Message* Self, int64* V);

Message* JB_Msg_ConstructorCopy(Message* Self, Message* Other);

Message* JB_Msg_ConstructorEmpty(Message* Self);

Message* JB_Msg_ConstructorNormal(Message* Self, Syntax Func, JB_String* Name);

Message* JB_Msg_ConstructorRange(Message* Self, Message* Parent, Syntax Func, int BytePos, JB_String* Name, int RangeLength);

void SC_Msg_ConstructorAddNil(Message* Self, bool Isdot);

bool JB_Msg_ContainsInd(Message* Self, Ind P, bool AllowJustAfter);

FatASM* JB_Msg_CONV(Message* Self, ASMReg R1, ASMReg R2, int Mode);

Message* JB_Msg_Copy(Message* Self, Message* Pos_msg);

void SC_Msg_CopyAllAfter(Message* Self, Message* After, Message* Copylayer);

void SC_Msg_CopyAllAfterBefore(Message* Self, Message* Before, Message* Copylayer);

void SC_Msg_CopyAllAfterInto(Message* Self, Message* Into, Message* Copylayer);

void SC_Msg_CopyAllBefore(Message* Self, Message* Before, Message* Copylayer);

void SC_Msg_CopyAllBeforeInto(Message* Self, Message* Into, Message* Copylayer);

void SC_Msg_CopyAllInto(Message* Self, Message* J);

JB_String* JB_Msg_CopyID(Message* Self);

Message* JB_Msg_CopySub(Message* Self, Message* P);

JB_String* SC_Msg_Cpp_Wrapper(Message* Self);

Message* SC_Msg_CreateNil(Message* Self);

Message* SC_Msg_CreateOwnBlock(Message* Self);

Message* SC_Msg_CutifyCopy(Message* Self);

Message* SC_Msg_DclExp(Message* Self);

void JB_Msg_Decl__(Message* Self, FastString* Fs);

void SC_Msg_DeclAddNumbInt(Message* Self, int64 Num, SCNode* Name_space);

Message* SC_Msg_DeclName(Message* Self);

bool JB_Msg_DeepEquals(Message* Self, Message* B, bool Aware);

Message* SC_Msg_Deepest(Message* Self, Syntax Tmp, JB_String* Name);

int SC_Msg_DeprecatedClassOption(Message* Self, JB_String* Name, JB_String* Kind);

void JB_Msg_Destructor(Message* Self);

Dictionary* JB_Msg_Dict(Message* Self, bool DoLower, bool DoCount);

FatASM* JB_Msg_DIV2(Message* Self, ASMReg R1, ASMReg R2, int Sh, int Add);

void SC_Msg_DivByZero(Message* Self);

FatASM* JB_Msg_DIVV(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int Kind);

bool SC_Msg_DoesAnything(Message* Self);

void JB_Msg_Dot__(Message* Self, FastString* Fs);

SCDecl* SC_Msg_DotMustBeProperty(Message* Self);

SCObject* SC_Msg_DotSpace(Message* Self, SCNode* Name_space);

DotUseType SC_Msg_DotType(Message* Self);

void JB_Msg_Dummy(Message* Self, FastString* Fs);

void SC_Msg_ElseNeverFires(Message* Self);

void JB_Msg_Emb__(Message* Self, FastString* Fs);

void JB_Msg_ERel__(Message* Self, FastString* Fs);

FatASM* JB_Msg_EROR(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int IsOK);

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

FatASM* JB_Msg_FADD(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

FatASM* JB_Msg_FADK(Message* Self, ASMReg R1, ASMReg R2, int High);

Message* SC_Msg_FailOrCopy(Message* Self, Message* P);

Message* SC_Msg_FalsifyNil(Message* Self);

SCDecl* SC_Msg_FastDecl(Message* Self);

FatASM* JB_Msg_FDIV(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

FatASM* JB_Msg_FFNC(Message* Self, ASMReg R1, int Table, int Prm1, int Prm2);

FatASM* JB_Msg_FFNC3(Message* Self, ASMReg R1, int Table, int Prm1, int Prm2);

FatASM* JB_Msg_FFRC(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

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

Float64 JB_Msg_Float(Message* Self);

float JB_Msg_Float32(Message* Self);

FatASM* JB_Msg_FMAX(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

FatASM* JB_Msg_FMIN(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

FatASM* JB_Msg_FMLK(Message* Self, ASMReg R1, ASMReg R2, int High);

FatASM* JB_Msg_FMUL(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

FatASM* JB_Msg_FNC(Message* Self, ASMReg R1, int JUMP, int Prm1, int Prm2);

FatASM* JB_Msg_FNC3(Message* Self, ASMReg R1, int JUMP, int Prm1, int Prm2);

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

bool SC_Msg_HasAsmStuff(Message* Self);

Message* SC_Msg_HasOwnBlock(Message* Self);

bool JB_Msg_HasPosition(Message* Self);

bool SC_Msg_HasSelfAsFirst(Message* Self);

void SC_Msg_HateUnusedFuncs(Message* Self);

SCFunction* SC_Msg_IdentifyFunc(Message* Self);

Message* SC_Msg_InBuiltSizeOf(Message* Self, SCDecl* Sulf);

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

void SC_Msg_IntoVariable(Message* Self, SCNode* Name_space, NameAndMsg* Rz);

int SC_Msg_IntSmallness(Message* Self, SCDecl* T);

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

bool SC_Msg_IsStatementExpr(Message* Self);

bool JB_Msg_IsString(Message* Self);

bool SC_Msg_IsTern(Message* Self);

bool JB_Msg_IsTypeOfDecl(Message* Self);

bool SC_Msg_IsVarAltered(Message* Self, JB_String* Name);

bool SC_Msg_IsVarUseableInLoop(Message* Self, JB_String* Name);

bool SC_Msg_IsZero(Message* Self);

void JB_Msg_Item__(Message* Self, FastString* Fs);

bool JB_Msg_jbinTest(Message* Self);

FatASM* JB_Msg_JBRA(Message* Self, ASMReg R1, int Jmp);

FatASM* JB_Msg_JBRN(Message* Self, ASMReg R1, int Jmp);

JB_String* JB_Msg_JDB2_(Message* Self, int Flags, FastString* Fs_in);

JB_String* jdb4(Message* Self);

JB_String* SC_Msg_JDB4_(Message* Self, FastString* Fs_in);

JB_String* JB_Msg_JDB_(Message* Self, FastString* Fs_in, int Flags);

FatASM* JB_Msg_JMPE(Message* Self, ASMReg R1, ASMReg R2, int Jmp);

FatASM* JB_Msg_JMPF(Message* Self, ASMReg R1, ASMReg R2, int Cmp, int Jmp);

FatASM* JB_Msg_JMPI(Message* Self, ASMReg R1, ASMReg R2, int Cmp, int Jmp);

FatASM* JB_Msg_JMPN(Message* Self, ASMReg R1, ASMReg R2, int Jmp);

FatASM* JB_Msg_JSWI(Message* Self, ASMReg R1, ASMReg R2, int Jmp);

FatASM* JB_Msg_JUMP(Message* Self, int JUMP);

void SC_Msg_KinderRemoveAfter(Message* Self);

FatASM* JB_Msg_KNSR(Message* Self, ASMReg R1, int Rot, int Inv, int Value);

FatASM* JB_Msg_KNST(Message* Self, ASMReg R1, int Cond, int Inv, int Value);

FatASM* JB_Msg_KNST2(Message* Self, ASMReg R1, int Cond, int Inv, int Value);

FatASM* JB_Msg_KNST3(Message* Self, ASMReg R1, int Cond, int Inv, int Value);

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

FatASM* JB_Msg_LUPD(Message* Self, ASMReg R1, ASMReg R2, int Jmp);

FatASM* JB_Msg_LUPU(Message* Self, ASMReg R1, ASMReg R2, int Jmp);

Message* JB_Msg_MacroAvoidCopy(Message* Self);

void JB_Msg_MacroCopy(Message* Self, Message* Root, Array* Prms, Message* Dest);

void SC_Msg_MacroFixSub(Message* Self, SCDecl* Contains);

Message* JB_Msg_MacroPrm(Message* Self, Message* Root, Array* Prms, Message* Dest);

Message* JB_Msg_MacroSame(Message* Self, Message* Prm);

bool SC_Msg_MainArgsCanBeZero(Message* Self);

Message* SC_Msg_MainFix(Message* Self);

void SC_Msg_MainFix2(Message* Self);

int SC_Msg_MainOneArg(Message* Self, Message* Arg, int I, int Found);

Message* SC_Msg_MakeAccess0(Message* Self);

void SC_Msg_MakeComment(Message* Self);

int SC_Msg_MakeDereference(Message* Self, SCDecl* Type);

void SC_Msg_MakeTaskVar(Message* Self, Message* Con, Message* Before, bool First);

FatASM* JB_Msg_MAX(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sign);

void JB_Msg_max__(Message* Self, FastString* Fs);

FatASM* JB_Msg_MEMU(Message* Self, ASMReg R1, ASMReg R2, int Op, int N);

FatASM* JB_Msg_MIN(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sign);

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

FatASM* JB_Msg_MULT(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4);

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

FatASM* JB_Msg_NOOP(Message* Self);

Message* SC_Msg_NormaliseFunc(Message* Self, SCClass* AddSelf);

void SC_Msg_NotNilRZ(Message* Self, SCDecl* Type, SCNode* Space);

void JB_Msg_Num__(Message* Self, FastString* Fs);

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

Syntax SC_Msg_ParentForAddress(Message* Self);

Message* SC_Msg_ParentPoint(Message* Self);

Message* SC_Msg_ParseShaderSub(Message* Self);

void JB_Msg_pinn__(Message* Self, FastString* Fs);

JB_String* JB_Msg_plocate(Message* Self);

void SC_Msg_PrepareAST(Message* Self);

int JB_Msg_PrevIndentCheck(Message* Self, Message* Pr);

void JB_Msg_Prm__(Message* Self, FastString* Fs);

SCFunction* SC_Msg_PrmFunc(Message* Self);

Message* SC_Msg_PrmFuncStructMsg(Message* Self);

FatASM* JB_Msg_PRNT(Message* Self, ASMReg R1);

Message* SC_Msg_QMarkRel(Message* Self);

void JB_Msg_Ques__(Message* Self, FastString* Fs);

void JB_Msg_Quot__(Message* Self, FastString* Fs);

FatASM* JB_Msg_RALO(Message* Self, ASMReg R1, ASMReg R2);

IntRange JB_Msg_Range(Message* Self);

void JB_Msg_RangeSet(Message* Self, IntRange R);

FatASM* JB_Msg_RARE(Message* Self, ASMReg R1, ASMReg R2);

int SC_Msg_RC_HasTemporary(Message* Self);

FatASM* JB_Msg_RD16(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* JB_Msg_RD1S(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* JB_Msg_RD1U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* JB_Msg_RD2S(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* JB_Msg_RD2U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* JB_Msg_RD4S(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* JB_Msg_RD4U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* JB_Msg_RD8U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

NilState SC_Msg_RedundantDeclare(Message* Self, uint /*NilState*/ D);

NilState SC_Msg_RedundantVar(Message* Self, SCDecl* Dcl, NilCheckMode Test);

bool SC_Msg_RefDisappears(Message* Self);

bool SC_Msg_RefTransparent(Message* Self);

int SC_Msg_Reg(Message* Self);

int SC_Msg_RegOrNum(Message* Self);

void JB_Msg_Rel__(Message* Self, FastString* Fs);

bool SC_Msg_RelFix(Message* Self, bool Force);

JB_String* JB_Msg_Render(Message* Self, FastString* Fs_in);

void JB_Msg_render_jbin_sub(Message* Self, FastString* Js);

JB_String* JB_Msg_RenderJbin(Message* Self, JB_String* Shell_path, FastString* Fs_in);

void JB_Msg_RenderPrm(Message* Self, FastString* Fs, uint /*byte*/ B1, uint /*byte*/ B2);

JB_String* SC_Msg_RenderType(Message* Self);

void JB_Msg_RenderWithSpaces(Message* Self, FastString* Fs, Message* Ch);

Message* SC_Msg_ReplaceInbuiltSub(Message* Self, SCNode* Name_space, SCDecl* Self_decl);

Message* JB_Msg_ReplaceInto(Message* Self, Message* W);

Message* SC_Msg_ReplaceWith(Message* Self, Message* J);

Message* SC_Msg_ReplaceWithChild(Message* Self);

JB_Object* JB_Msg_RestoreLoad(Message* Self);

Message* SC_Msg_Resync(Message* Self, Message* Parent);

FatASM* JB_Msg_RET(Message* Self, ASMReg R1, int Count, int SafeDecr, int Value);

FatASM* JB_Msg_RFDC(Message* Self, ASMReg R1, int Count, int Offset);

FatASM* JB_Msg_RFRD(Message* Self, ASMReg R1, ASMReg R2, int Decr, int Offset);

FatASM* JB_Msg_RFRG(Message* Self, ASMReg R1, ASMReg R2, int Incr, int Move, int Free, int Decr);

FatASM* JB_Msg_RFWR(Message* Self, ASMReg R1, ASMReg R2, int Decr, int Offset);

void SC_Msg_Safe(Message* Self, FastString* Fs);

void SC_Msg_SafeRemove(Message* Self, Syntax T);

void SC_Msg_SafeReplaceWith(Message* Self, Message* Incoming);

SCArg* SC_Msg_SCArg(Message* Self, SCNode* P, Message* Avoid);

SCArg* SC_Msg_SCArgNested(Message* Self, Message* Base, SCNode* P);

void JB_Msg_SCnj__(Message* Self, FastString* Fs);

void JB_Msg_SCom__(Message* Self, FastString* Fs);

void JB_Msg_SDot__(Message* Self, FastString* Fs);

bool SC_Msg_SecondIs(Message* Self, Syntax Fn, JB_String* Name);

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

void SC_Msg_StructReturnCleanup(Message* Self, SCFunction* Fn, SCNode* Name_space);

FatASM* JB_Msg_SUB(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* JB_Msg_SWAP(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4);

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

void JB_Msg_Fail(Message* Self, JB_String* Error);

bool JB_Msg_SyntaxIs(Message* Self, uint /*MsgParseFlags*/ F);

void JB_Msg_SyntaxIsSet(Message* Self, uint /*MsgParseFlags*/ F, bool Value);

void JB_Msg_SyntaxProblem(Message* Self, JB_String* Error);

void JB_Msg_SyntaxUsing(Message* Self, MessagePosition* Rz);

void JB_Msg_SyntaxWarn(Message* Self, JB_String* Error);

FatASM* JB_Msg_TABL(Message* Self, ASMReg R1, int Mode, int Add);

FatASM* JB_Msg_TAIL(Message* Self, int JUMP, int Prm1);

bool SC_Msg_TargetTest(Message* Self);

Message* SC_Msg_TaskConBefore(Message* Self);

Message* SC_Msg_TempIntoBlock(Message* Self, Message* ParentPlace);

FatASM* JB_Msg_TERN(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4);

void JB_Msg_Test(Message* Self, JB_String* New_render, JB_String* Name);

void JB_Msg_test_style(Message* Self);

bool SC_Msg_TestFuncName(Message* Self);

bool JB_Msg_TestSub(Message* Self, JB_String* New_render, JB_String* Name);

JB_String* JB_Msg_Text(Message* Self, int I);

bool JB_Msg_TextSet(Message* Self, int I, JB_String* V);

Message* JB_Msg_TextViewChild(Message* Self);

void JB_Msg_Thg__(Message* Self, FastString* Fs);

void JB_Msg_Tmp__(Message* Self, FastString* Fs);

void JB_Msg_Todo__(Message* Self, FastString* Fs);

void SC_Msg_Tran_Isnt(Message* Self, JB_String* Name);

void SC_Msg_Tran_QMark(Message* Self);

Message* SC_Msg_Tran_Target(Message* Self);

void SC_Msg_Tran_TargetSub(Message* Self);

void SC_Msg_Tran_With(Message* Self);

void SC_Msg_TranAllTargets(Message* Self);

Message* SC_Msg_TranModel(Message* Self);

FatASM* JB_Msg_TRAP(Message* Self, ASMReg R1, int Mode, int Signal);

void JB_Msg_TRel__(Message* Self, FastString* Fs);

void JB_Msg_Tril__(Message* Self, FastString* Fs);

MaybeBool SC_Msg_Trueness(Message* Self, uint /*NilState*/ Found);

bool SC_Msg_TrueOrFalse(Message* Self);

int SC_Msg_TryImproveShiftConstants(Message* Self, SCDecl* LC, SCDecl* RC);

void JB_Msg_Type__(Message* Self, FastString* Fs);

bool SC_Msg_TypeCastDoesNothing(Message* Self);

void SC_Msg_TypeExpect(Message* Self, DataTypeCode* Ty, uint /*DataTypeCode*/ In);

Message* SC_Msg_TypeOfArrItem(Message* Self);

Message* SC_Msg_UnBra(Message* Self);

Message* SC_Msg_UnBraType(Message* Self);

void JB_Msg_UnEmbedStr(Message* Self);

void JB_Msg_Unit__(Message* Self, FastString* Fs);

bool SC_Msg_UnitMatch(Message* Self, JB_String* A, JB_String* B);

Message* SC_Msg_UnReachable(Message* Self);

Message* SC_Msg_Unwrap(Message* Self);

Message* SC_Msg_UpToType(Message* Self);

void JB_Msg_url__(Message* Self, FastString* Fs);

Message* SC_Msg_UseNonRefChangers(Message* Self, bool Parent);

JB_String* JB_Msg_Value(Message* Self);

JB_String* SC_Msg_VarName(Message* Self);

bool SC_Msg_visible(Message* Self);

void SC_Msg_visibleSet(Message* Self, bool Value);

MaybeBool SC_Msg_visible2(Message* Self);

int SC_Msg_VMBits(Message* Self);

JB_String* SC_Msg_VMMsgArgName(Message* Self, int I);

Message* SC_Msg_LayerWipeCopy(Message* Self, Message* Oof);

Message* SC_Msg_WipeCopy(Message* Self);

void JB_Msg_WipePositions(Message* Self);

void SC_Msg_WithDeclTransform(Message* Self, Message* Decl, Message* Rel, Message* Arg);

bool SC_Msg_WithinLoop(Message* Self, Message* Stop);

bool JB_Msg_WithinType(Message* Self, int Allowed);

FatASM* JB_Msg_WR16(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* JB_Msg_WR1U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* JB_Msg_WR2U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* JB_Msg_WR4U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* JB_Msg_WR8U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

int SC_Msg_WrapExpr(Message* Self, SCDecl* Src);

void SC_Msg_WrapFloatOrInt(Message* Self, uint /*DataTypeCode*/ T, int N, SCDecl* D);

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



// JB_MessageTable


// JB_RangeCoder


// JB_SCDecl
int SC_Decl_AccessType(SCDecl* Self, SCDecl* Access, Message* Ch);

SCDecl* SC_Decl_ActualReplace(SCDecl* Self, SCDecl* New);

int SC_Decl_AllocatedSize(SCDecl* Self);

bool SC_Decl_AlreadyContains(SCDecl* Self);

uint64 SC_Decl_AsConst(SCDecl* Self, Message* Value, DataTypeCode* Ty);

SCDecl* SC_Decl_AsLocal(SCDecl* Self);

bool SC_Decl_AssignabilityCheck(SCDecl* Self, Message* Ln, Message* RN, SCDecl* Rc, bool WasHex);

JB_String* SC_Decl_AutoCompleteName(SCDecl* Self);

void SC_Decl_BecomeReal(SCDecl* Self);

SCDecl* SC_Decl_Better_Numeric(SCDecl* Self, SCDecl* O, OpMode Mode, Message* Left, Message* Right);

ASMReg SC_Decl_CalculateASMType(SCDecl* Self);

bool SC_Decl_CanCompare(SCDecl* Self, SCDecl* Against, bool AsEquals);

bool SC_Decl_CanNilCheck(SCDecl* Self);

bool SC_Decl_CanRemoveArgOnReturn(SCDecl* Self, Message* R);

bool SC_Decl_CantBeNilInCpp(SCDecl* Self);

SCDecl* SC_Decl_CanUpgradeInternalPointer(SCDecl* Self);

bool SC_Decl_CanUseDefault(SCDecl* Self);

bool SC_Decl_CanWrap(SCDecl* Self);

SCDecl* SC_Decl_CheckMath(SCDecl* Self, Message* Exp);

bool SC_Decl_CompareUnclear(SCDecl* Self, SCDecl* D, bool MakesSenseVsZero);

bool SC_Decl_ConstInRange(SCDecl* Self, Message* RN, SCDecl* Rt, bool WasHex);

bool SC_Decl_ConstInRangeSub(SCDecl* Self, int64 Value, bool WasHex);

SCDecl* SC_Decl_Constructor(SCDecl* Self, SCClass* Type);

SCDecl* SC_Decl_Containedfix(SCDecl* Self);

SCDecl* SC_Decl_ContainedReplace(SCDecl* Self, SCDecl* Contains, bool NeedsName);

bool SC_Decl_ContainsMatch(SCDecl* Self, SCDecl* O, int TypeCast);

SCDecl* SC_Decl_CopyDecl(SCDecl* Self, bool ForNewVariable);

SCDecl* SC_Decl_CopyDeclsStructFixer(SCDecl* Self, Message* Src, DeclMode Mode);

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

Message* SC_Decl_ExpectMatchForDecl(SCDecl* Self, SCDecl* O, Message* Exp);

Message* SC_Decl_ExpectMatchSub(SCDecl* Self, SCDecl* O, int TypeCast, Message* Exp, Message* ErrNode);

bool SC_Decl_ExpectRelMatch(SCDecl* Self, SCDecl* O, Message* Exp, Message* Side, Message* ErrNode);

SCDecl* SC_Decl_ExtractAmount(SCDecl* Self, Message* Prms);

SCDecl* SC_Decl_ExtractAmountSub(SCDecl* Self, Message* Prms);

bool SC_Decl_FastMatch(SCDecl* Self, SCDecl* O);

int SC_Decl_FloatCast(SCDecl* Self, SCDecl* Orig, Message* Exp);

SCDecl* SC_Decl_ForContained(SCDecl* Self);

bool SC_Decl_Found(SCDecl* Self);

DataTypeCode SC_Decl_GameType(SCDecl* Self);

SCDecl* SC_Decl_GetAddress(SCDecl* Self, DeclMode Purpose);

SCDecl* SC_Decl_GetCArray(SCDecl* Self, int Amount);

SCIterator* SC_Decl_GetIteratorAny(SCDecl* Self, JB_String* Name, Message* Node);

bool SC_Decl_HasStruct(SCDecl* Self);

SCFunction* SC_Decl_HasStructDestructor(SCDecl* Self);

SCDecl* SC_Decl_HighestArrayContainMatch(SCDecl* Self, SCDecl* Other);

SCDecl* SC_Decl_HighestMatch(SCDecl* Self, SCDecl* Other);

bool SC_Decl_IntRegs(SCDecl* Self);

bool SC_Decl_IntsOnly(SCDecl* Self, Message* Exp);

bool SC_Decl_IsBareStruct(SCDecl* Self);

bool SC_Decl_IsBool(SCDecl* Self);

void SC_Decl_IsCarray(SCDecl* Self, int Size, SCDecl* Of);

bool SC_Decl_IsCArray(SCDecl* Self);

bool SC_Decl_IsConstOf(SCDecl* Self, SCDecl* B);

bool SC_Decl_IsDataTypeOnly(SCDecl* Self);

bool SC_Decl_IsFloat(SCDecl* Self);

bool SC_Decl_IsInt(SCDecl* Self);

bool SC_Decl_IsInteger(SCDecl* Self);

bool SC_Decl_IsLib(SCDecl* Self);

bool SC_Decl_IsMostlyNormal(SCDecl* Self);

bool SC_Decl_IsNearlyNormalNumber(SCDecl* Self);

bool SC_Decl_IsNil(SCDecl* Self);

bool SC_Decl_IsNormal(SCDecl* Self);

bool SC_Decl_IsNormalBool(SCDecl* Self);

bool SC_Decl_IsNormalNumber(SCDecl* Self);

bool SC_Decl_IsNormalObject(SCDecl* Self);

bool SC_Decl_IsntReallyCastable(SCDecl* Self, Message* Side);

int SC_Decl_IsNumeric(SCDecl* Self);

bool SC_Decl_IsObject(SCDecl* Self);

bool SC_Decl_IsReffable(SCDecl* Self, bool SetOnly);

bool SC_Decl_IsReg(SCDecl* Self);

bool SC_Decl_IsRegister(SCDecl* Self);

JB_String* SC_Decl_IsSaveable(SCDecl* Self);

void SC_Decl_IsTypeImproveSet(SCDecl* Self, bool Value);

bool SC_Decl_IsUintLike(SCDecl* Self);

bool SC_Decl_IsVoidPtr(SCDecl* Self);

bool SC_Decl_LoadContained(SCDecl* Self, Message* Contained, Message* Wrap, SCNode* Name_Space, DeclMode Purpose);

bool SC_Decl_LoadContainedSub(SCDecl* Self, SCDecl* Cont, Message* Wrap, SCNode* Name_Space, DeclMode Purpose);

Message* SC_Decl_MakeAccess0(SCDecl* Self);

SCDecl* SC_Decl_MakeAsObject(SCDecl* Self, SCDecl* Container, Message* ErrPlace);

SCDecl* SC_Decl_MakeBorrowed(SCDecl* Self, bool StayBorrowed);

void SC_Decl_MakeContainedObject(SCDecl* Self, Message* ErrPlace);

SCDecl* SC_Decl_MakeContainedOptional(SCDecl* Self);

SCDecl* SC_Decl_MakeDataObject(SCDecl* Self, SCNode* Name_Space, DeclMode Purpose);

SCDecl* SC_Decl_MakeExistance(SCDecl* Self, uint /*NilState*/ Type, SCDecl* Default);

void SC_Decl_MakeGameFlying(SCDecl* Self, SCClass* Oof, Message* M);

SCDecl* SC_Decl_MakeNewNil(SCDecl* Self);

SCDecl* SC_Decl_MakeNewOptional(SCDecl* Self);

SCDecl* SC_Decl_MakeNewReal(SCDecl* Self);

SCDecl* SC_Decl_MakeReal(SCDecl* Self);

bool SC_Decl_MakeStatic(SCDecl* Self, Message* Wrap, SCNode* Name_Space, DeclMode Purpose);

void SC_Decl_MarkAsAltered(SCDecl* Self);

bool SC_Decl_MatchC(SCDecl* Self, SCDecl* O);

bool SC_Decl_MiniMatch(SCDecl* Self, SCDecl* O, int TypeCast);

void SC_Decl_NameSet(SCDecl* Self, JB_String* Value);

bool SC_Decl_NeedsContainedfix(SCDecl* Self);

SCDecl* SC_Decl_NewWrapper(SCDecl* Self, SCDecl* CastTo);

SCDecl* SC_Decl_NilConstructor(SCDecl* Self, uint /*NilState*/ Type);

NilState SC_Decl_NilCurr(SCDecl* Self);

void SC_Decl_NilPrmFail(SCDecl* Self, SCFunction* F);

bool SC_Decl_NilStated(SCDecl* Self);

void SC_Decl_NoBlindCasts(SCDecl* Self, SCDecl* Old, Message* Exp);

SCDecl* SC_Decl_NotLocal(SCDecl* Self);

void SC_Decl_NumberConstSet(SCDecl* Self, uint64 V);

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

DataTypeCode SC_Decl_RegType(SCDecl* Self);

JB_String* SC_Decl_Render(SCDecl* Self, FastString* Fs_in);

JB_String* SC_Decl_RenderTypeAndName(SCDecl* Self, int Minimal);

JB_String* SC_Decl_RenderTypeName(SCDecl* Self, FastString* Fs_in);

JB_String* SC_Decl_RenderTypeNameNicer(SCDecl* Self, FastString* Fs_in);

bool SC_Decl_SafelyWrappable(SCDecl* Self);

bool SC_Decl_SameForReplace(SCDecl* Self, SCDecl* C);

bool SC_Decl_SpecialRegs(SCDecl* Self);

NilState SC_Decl_StatedOptional(SCDecl* Self);

NilState SC_Decl_StatedReal(SCDecl* Self);

void SC_Decl_SyntaxAppend(SCDecl* Self, SCDeclInfo D);

bool SC_Decl_SyntaxIs(SCDecl* Self, SCDeclInfo D);

void SC_Decl_SyntaxIsSet(SCDecl* Self, SCDeclInfo D, bool Value);

int SC_Decl_TryTypeCast(SCDecl* Self, SCDecl* O, Message* OExp, int TypeCast);

int SC_Decl_TryTypeCastAccess(SCDecl* Self, SCDecl* O, Message* Exp, int TypeCast);

int SC_Decl_TryTypeCastPointer(SCDecl* Self, SCDecl* O, Message* Exp, int TypeCast, bool CArray);

JB_String* SC_Decl_TryUseSaveable(SCDecl* Self, bool IsSave, SCClass* Cls);

DataTypeCode SC_Decl_TypeInfo(SCDecl* Self);

bool SC_Decl_TypeIsReached(SCDecl* Self);

int SC_Decl_TypeMatch(SCDecl* Self, SCDecl* O, int TypeCast, Message* Exp);

DataTypeCode SC_Decl_TypeOnly(SCDecl* Self);

void SC_Decl_TypeReach(SCDecl* Self, SCNode* From, Message* Src);

bool SC_Decl_TypeSuffers(SCDecl* Self);

int SC_Decl_VarSizeSub(SCDecl* Self, bool TheVarItself);

void SC_Decl_WholeTypeSet(SCDecl* Self, uint /*DataTypeCode*/ Value);

ASMReg SC_Decl_WholeType(SCDecl* Self);

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
Message* SC_File_AST(SCFile* Self);

Message* SC_File_ASTSub(SCFile* Self, bool Orig);

void SC_File_CollectGlobals(SCFile* Self, SCNode* P);

SCFile* SC_File_Constructor(SCFile* Self, JB_File* F, SCImport* P);

void SC_File_Destructor(SCFile* Self);

void SC_File_DetectInsecureWords(SCFile* Self);

Message* SC_File_GetMsg(SCFile* Self, int Pos);

Message* SC_File_Orig(SCFile* Self);

Message* SC_File_Start_AST(SCFile* Self);

void SC_File_Use(SCFile* Self);



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

uint64 SC_Base_CalculateConst(SCNode* Self, Message* Value);

uint64 SC_Base_CalculateConstRel(SCNode* Self, Message* Value, DataTypeCode* Ty);

uint64 SC_Base_CalculateConstSub(SCNode* Self, Message* Value, DataTypeCode* Ty);

void SC_Base_CollectConstantsSub(SCNode* Self, Message* Ch);

void SC_Base_CollectFromNode(SCNode* Self, Message* AST, bool Visible, Message* Dest);

bool SC_Base_CollectOne(SCNode* Self, Message* C, bool Visible);

void SC_Base_CollectOneConstants(SCNode* Self, Message* Ch);

Message* SC_Base_CollectStr(SCNode* Self, JB_String* S);

SCNode* SC_Base_CollectSub(SCNode* Self, Message* C);

void SC_Base_ConstantExpand(SCNode* Self, Message* Ch);

SCNode* SC_Base_Constructor0(SCNode* Self);

SCNode* SC_Base_ConstructorStr(SCNode* Self, JB_String* Name);

SCNode* SC_Base_ConstructorMsg(SCNode* Self, Message* Node);

void SC_Base_CreateNameDict(SCNode* Self, Message* FuncName, Array* NameList);

void SC_Base_Destructor(SCNode* Self);

Message* SC_Base_DiissplayObj(SCNode* Self, Message* Rz);

bool SC_Base_ExpectModule(SCNode* Self, Message* Errplace);

SCClass* SC_Base_FindClass(SCNode* Self, JB_String* Name, Message* Where, SCNodeFindMode Mode);

SCClass* SC_Base_FindClassMsg(SCNode* Self, Message* Where, SCNodeFindMode Mode);

Message* SC_Base_FindCppWrapper(SCNode* Self, Message* Place, bool Isclass);

SCFunction* SC_Base_FindFunction(SCNode* Self, JB_String* Name);

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

SCObject* SC_Base_LookUpFunc(SCNode* Self, JB_String* Name, Message* Exp);

SCObject* SC_Base_LookUpSub(SCNode* Self, JB_String* OrigName, Message* Exp, SCNode* Arg_Space, SCDecl* Contains, Message* Side, int Purpose);

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

SCNode* SC_Base__LoadCppPart(Message* Node, SCNode* Name_space, Message* ErrPlace);



// JB_SaverClassInfo
void JB_sci_Clear(SaverClassInfo* Self);

SaverClassInfo* JB_sci_Constructor(SaverClassInfo* Self, JB_Class* Cls, int8* Data);

void JB_sci_Destructor(SaverClassInfo* Self);

bool JB_sci_HasData(SaverClassInfo* Self);

void JB_sci_Output(SaverClassInfo* Self, ObjectSaver* Saver);



// JB_SimpleGraph


// JB_SpdProcess
bool JB_Proc_Alive(SpdProcess* Self);

bool JB_Proc_ChildAlive(SpdProcess* Self);

bool JB_Proc_CommsOpen(SpdProcess* Self);

SpdProcess* JB_Proc_Constructor(SpdProcess* Self, JB_String* Path, FP_SpdMainFn Fn, PicoComms* Pico, Array* Params, uint /*ProcessMode*/ Mode);

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

void JB_Task_SyntaxIsSet(JB_Task* Self, uint /*TaskState*/ S, bool Value);

Task2* SC_Task_Task2_Constructor(Task2* Self, JB_String* A, int B, JB_String* C, vec2 V, float Strength);



// JB_Error
JB_Error* JB_Err_Constructor(JB_Error* Self, Message* Node, JB_String* Desc, uint /*ErrorSeverity*/ Level, JB_String* Path);

JB_Error* JB_Err_ConstructorNothing(JB_Error* Self);

void JB_Err_Destructor(JB_Error* Self);

void JB_Err_Fill(JB_Error* Self, JB_String* Path, JB_String* Desc);

bool SC_Err_FromSamePlace(JB_Error* Self, Message* S);

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

JB_String* JB_Err_RenderUnix(JB_Error* Self, FastString* Fs_in);

void SC_Err_SCGrabLine(JB_Error* Self, FastString* Fs, bool Usecolor);

int SC_Err_SCLineCount(JB_Error* Self);

void SC_Err_SCLineIdentifiers(JB_Error* Self, FastString* Fs, JB_String* Data);

JB_String* SC_Err_SCOriginalData(JB_Error* Self);

JB_String* SC_Err_SCOriginalPath(JB_Error* Self);

JB_String* SC_Err_SCRender(JB_Error* Self, FastString* Fs_in);

void JB_Err_ShiftPosition(JB_Error* Self, int I);

bool JB_Err_SyntaxIs(JB_Error* Self, uint /*ErrorFlags*/ F);

void JB_Err_SyntaxIsSet(JB_Error* Self, uint /*ErrorFlags*/ F, bool Value);

void JB_Err_UpgradeWithNode(JB_Error* Self);

void JB_Err__CantParseNum(Message* Where, JB_String* Num, int Pos, bool Overflow);

int JB_Err__Init_();

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



// JB_SCBetterNode
SCBetterNode* SC_SCBetterNode_ConstructorWith0(SCBetterNode* Self);

SCBetterNode* SC_SCBetterNode_ConstructorWithMsg(SCBetterNode* Self, Message* Msg);

void SC_SCBetterNode_Destructor(SCBetterNode* Self);

void SC_SCBetterNode_ReadDescription(SCBetterNode* Self, Message* Msg);



// JB_config
Message* JB_config_ConfFirst(Message* Self);

bool JB_config_Save(Message* Self);



// JB_interface
bool SC_Task_LessThan3_interface_SyntaxCall(JB_Task* Self, int I);



// JB_LessThan3
bool SC_Task_LessThan3_run(LessThan3* Self, int I);



// JB_SCClass
void SC_Class_AddBehaviourOrInterface(SCClass* Self, SCNode* M);

void SC_Class_AfterAfterFuncs(SCClass* Self);

void SC_Class_AfterFuncsDecled(SCClass* Self);

JB_String* SC_Class_APIStructName(SCClass* Self);

void SC_Class_BannedCheck(SCClass* Self, Message* Src);

JB_String* SC_Class_BehaviourName(SCClass* Self);

SCFunction* SC_Class_BestBehaviourFor(SCClass* Self, JB_String* Name);

int SC_Class_CalculateSize(SCClass* Self, int Depth);

int SC_Class_CalculateSizeRaw(SCClass* Self, int Depth);

bool SC_Class_CanCompareSub(SCClass* Self, JB_String* S, SCDecl* Against);

bool SC_Class_CanHaveEmptyConstructor(SCClass* Self);

void SC_Class_CheckAllocVsWrapper(SCClass* Self, SCFunction* F, bool IsConstructor);

void SC_Class_CheckIterator(SCClass* Self);

void SC_Class_ClassCollect(SCClass* Self);

bool SC_Class_CollectProp(SCClass* Self, Message* Msg);

void SC_Class_CollectProperties(SCClass* Self);

SCFunction* SC_Class_ConOrDesForCall(SCClass* Self, bool IsConstructor, int Task);

SCClass* SC_Class_Constructor(SCClass* Self, Message* Node, bool HasPtrs, SCModule* M);

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

SCClass* SC_Class_GetFlyingMemClass(SCClass* Self);

SCDecl* SC_Class_GetFlyingMemory(SCClass* Self, Message* Exp);

SCIterator* SC_Class_GetIteratorAny(SCClass* Self, JB_String* Name, Message* Node);

SCClass* SC_Class_GoUpTo(SCClass* Self, int D);

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

void SC_Class_SimplerDataTypes(SCClass* Self, FastString* Fs, SCDecl* D);

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

void SC_Func_AddTypeInfo(SCFunction* Self, SCDecl* Dcl);

void SC_Func_AnalyseRefs(SCFunction* Self, Array* List);

int SC_Func_ApparantArgCount(SCFunction* Self);

SCFunction* SC_Func_ArgsMatch(SCFunction* Self, SCDecl* Base, SCNode* Name_space, SCParamArray* Incoming, int Failed);

SCFunction* SC_Func_ArgsMatch1(SCFunction* Self, SCDecl* Base, SCNode* Name_space, SCParamArray* Incoming, int Cast);

SCFunction* SC_Func_ArgsMatch2(SCFunction* Self, SCDecl* Base, int TypeCast, SCNode* Name_space, SCParamArray* Incoming);

int SC_Func_ArgsMatch3(SCFunction* Self, int TypeCast, SCDecl* Base, bool ThisAlter, SCNode* Name_space, SCParamArray* Incoming);

bool SC_Func_Borked(SCFunction* Self);

void SC_Func_BuildConstructorDestructor(SCFunction* Self);

void SC_Func_CallParents(SCFunction* Self);

void SC_Func_CallSuperMem(SCFunction* Self, SCFunction* Fn);

bool SC_Func_CanBuildConstructor(SCFunction* Self);

bool SC_Func_CanCompareAgainst(SCFunction* Self, SCDecl* Against);

bool SC_Func_CanLibLoad(SCFunction* Self);

bool SC_Func_CanLinkTo(SCFunction* Self, SCNode* To);

bool SC_Func_CanNil(SCFunction* Self);

void SC_Func_CheckConstructorAndDestructor(SCFunction* Self, Message* Root, bool IsConstructor);

void SC_Func_CheckNotBadName(SCFunction* Self);

void SC_Func_CheckReturnValue(SCFunction* Self, Message* Msg, SCNode* Name_space);

void SC_Func_CheckUnused(SCFunction* Self, Message* Feedback);

void SC_Func_Cleanupfunc(SCFunction* Self, Message* S);

void SC_Func_CollectDeclsParams(SCFunction* Self, Message* Prms, SCNode* AddToSpace);

void SC_Func_CollectLinks(SCFunction* Self, JB_Object* Obj);

bool SC_Func_CollectReturnAsReal(SCFunction* Self);

void SC_Func_CollectStats(SCFunction* Self);

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

void SC_Func_FuncParamsLoad(SCFunction* Self);

bool SC_Func_HasCVersion(SCFunction* Self);

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

void SC_Func_NilSelff(SCFunction* Self, Message* Where, uint /*NilState*/ V);

bool SC_Func_operatorin(SCFunction* Self, JB_String* S);

SCFunction* SC_Func_ParamlessConstructor(SCFunction* Self);

JB_String* SC_Func_ParamUniquer(SCFunction* Self, JB_String* S);

JB_String* SC_Func_ParentName(SCFunction* Self);

bool SC_Func_ParseName(SCFunction* Self, Message* Node);

void SC_Func_PreProcessExpects(SCFunction* Self);

void SC_Func_PreRead(SCFunction* Self, Message* Arg);

Message* SC_Func_Prms(SCFunction* Self);

void SC_Func_ProtoExportName(SCFunction* Self);

bool SC_Func_Reach(SCFunction* Self);

void SC_Func_ReachedDetect(SCFunction* Self);

bool SC_Func_ReachFunc(SCFunction* Self, SCNode* From);

void SC_Func_RefFunc(SCFunction* Self, Message* Prm, Message* After);

DataTypeCode SC_Func_RegType(SCFunction* Self);

JB_String* SC_Func_Render(SCFunction* Self, FastString* Fs_in);

JB_String* SC_Func_RenderName(SCFunction* Self, FastString* Fs_in);

JB_String* SC_Func_RenderParams(SCFunction* Self, bool ForErrors, FastString* Fs_in);

JB_String* SC_Func_RenderTitle(SCFunction* Self, bool ForErrors, FastString* Fs_in);

bool SC_Func_ReturnsObject(SCFunction* Self);

SCDecl* SC_Func_Self(SCFunction* Self);

void SC_Func_SetBlindCasts(SCFunction* Self, SCNode* Name_space);

Message* SC_Func_SourceArg(SCFunction* Self);

SCDecl* SC_Func_StructReturned(SCFunction* Self);

bool SC_Func_SyntaxEquals(SCFunction* Self, JB_String* Name, bool Aware);

bool SC_Func_SyntaxIs(SCFunction* Self, FunctionType K);

void SC_Func_SyntaxIsSet(SCFunction* Self, FunctionType K, bool Value);

ivec4* SC_Func_Test(SCFunction* Self);

void SC_Func_Transform(SCFunction* Self);

void SC_Func_TranStrings(SCFunction* Self);

void SC_Func_TryAdd(SCFunction* Self, SCNode* B);

SCFunction* SC_Func_TryKeepBetter(SCFunction* Self, int OldMatch, SCFunction* F, int Match);

bool SC_Func_Update_Source(SCFunction* Self, int Start, JB_String* Text, SCObject* Orig);

bool SC_Func_UpdateSourceSub(SCFunction* Self, Message* Src);

bool SC_Func_UseCppName(SCFunction* Self, JB_String* CppName);

bool SC_Func_UseExportWrapper(SCFunction* Self, JB_String* CppWrapper);

void SC_Func_ValidateSaver(SCFunction* Self, JB_String* Name);

int SC_Func_VisibleArgs(SCFunction* Self);

void SC_Func_WantAs(SCFunction* Self, uint /*NilState*/ NS);

JB_String* SC_Func_WrappedName(SCFunction* Self);

Message* SC_Func__AlterPostCond(Message* PostCond, Message* IterPostCond, Message* NodeSrc);

Message* SC_Func__ArgToFunc(JB_String* NewName, Message* Params, Message* Arg);

bool SC_Func__CanKeepAsSource(Message* List, Message* Arg, SCDecl* D);

bool SC_Func__CanKeepAsValue(SCIterator* Iter, Message* Arg, SCDecl* Dcl, Message* Value);

void SC_Func__CurrFuncSet(SCFunction* Value);

SCFunction* SC_Func__CurrFunc();

void SC_Func__FastStringOpt(Message* S);

Message* SC_Func__GetFileString(Message* Msg, JB_String* Name);

bool SC_Func__InBuiltFunc(Message* Self, JB_String* Name);

int SC_Func__Init_();

int SC_Func__InitCode_();

bool SC_Func__InType(SCNodeType Ty);

JB_String* SC_Func__NameList();

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

void SC_Func__PrintStats(FastString* Fs);

void SC_Func__String_Expand(Message* Msg, SCFunction* Fn);

Message* SC_Func__TypedTempMoveOut(Message* Msg, JB_String* Name, SCDecl* Type);

Message* SC_Func__TempMoveOut(Message* Msg, Message* Place);

SCDecl* SC_Func__Tran_AfterRel(Message* Msg, SCNode* Name_space, Message* Side);

void SC_Func__Tran_All(SCFunction* Fn, Message* S, SCNode* P);

void SC_Func__Tran_Array(Message* S, SCNode* Name_space);

void SC_Func__Tran_Beep(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_BlindCasts(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_CppRefs(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_DebugAt(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Debugger(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Deprecate(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Description(SCFunction* Fn, Message* Node, SCNode* Name_space);

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

void SC_Func__Tran_PrintSub(SCFunction* Fn, Message* Node, SCNode* Name_space);

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

void SC_Mod_MoveToInitFunc(SCModule* Self, Message* C);

SCFunction* SC_Mod_NewModuleFunc(SCModule* Self, Message* Src);

SCModule* SC_Mod_OneOrOther(SCModule* Self, SCModule* B, JB_String* Name);

JB_String* SC_Mod_Render(SCModule* Self, FastString* Fs_in);

JB_String* SC_Mod_SafeName(SCModule* Self);

SCModule* SC_Mod_SuperMod(SCModule* Self);

bool SC_Mod_TryInit(SCModule* Self, Array* Req);

SCNode* SC_Mod__ConstantCollector(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Mod__DoInitAfter(Message* Node, SCNode* Name_space, Message* ErrPlace);

int SC_Mod__Init_();

SCNode* SC_Mod__NeuModule(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCModule* SC_Mod__NewContainer(JB_String* S);



// JB_Task2
bool SC_Task_Task2_run(Task2* Self, int I);

void SC_Task_Task2_Stuff(Task2* Self);

inline bool JB_ErrorInt_SyntaxCast(ErrorInt Self);

inline bool JB_ErrorMarker_SyntaxCast(ErrorMarker Self);

inline bool JB_FastBuff_AppendU8(FastBuff* Self, uint /*byte*/ V);

inline bool JB_Ind_SyntaxCast(Ind Self);

inline Syntax JB_Msg_Func(Message* Self);

inline JB_String* JB_Msg_Name(Message* Self);

inline JB_String* JB_Msg_Name_(Message* Self);

inline int JB_Sel_ID(Selector* Self);

inline bool JB_TC_SyntaxIs(uint /*DataTypeCode*/ Self, uint /*DataTypeCode*/ M);

inline JB_String* JB_Tk__SyntaxAccess(int S, int E, Syntax F);

inline bool JB_int64_IsPow2(int64 Self);

inline bool JB_int64_OperatorInRange(int64 Self, int64 D);

inline bool JB_int_IsPow2(int Self);

inline bool JB_int_OperatorInRange(int Self, int D);

inline uint SC_FAT_Index(FatASM* Self);

inline ASMReg SC_FAT_Info(FatASM* Self);

inline ASM* SC_FAT_xC2xB5RenderInto(FatASM* Self, ASM* Where, ASM* After);

inline bool SC_FailableInt_SyntaxCast(FailableInt Self);

inline JB_String* SC_Named_Name(SCNamed* Self);

inline bool SC_PA_SyntaxCast(SCParamArray* Self);

inline DataTypeCode SC_Reg_xC2xB5Type(ASMReg Self);

inline NilRecord SC_nil_Value(ArchonPurger* Self);

inline void SC_nil_ValueSet(ArchonPurger* Self, NilRecord Dest);

inline FatASM* SC_uint_FAT(uint Self);

inline void JB_Array_SortBool(Array* Self, FP_SorterComparerBool Compare);

inline bool JB_Array_SyntaxCast(Array* Self);

inline JB_String* JB_CP_SyntaxCast(Codepoint Self);

inline bool JB_Err2_SyntaxCast(ErrorInt2 Self);

inline void JB_FS_AppendFloat(FastString* Self, float D, int Dp, bool CanExp, bool Dot);

inline void JB_FS_AppendInt64(FastString* Self, int64 Data);

inline JB_String* JB_FS_SyntaxCast(FastString* Self);

inline JB_String* JB_Object___Render__(JB_Object* Self, FastString* Fs_in);

inline void JB_Sav___LoadProperties__(Saveable* Self, ObjectLoader* Loader);

inline void JB_Sav___SaveCollect__(Saveable* Self, ObjectSaver* Saver);

inline void JB_Sav___SaveWrite__(Saveable* Self, ObjectSaver* Saver);

inline byte* JB_Str_Addr(JB_String* Self);

inline JB_StringC* JB_Str_CastZero(JB_String* Self);

inline _cstring JB_Str_SyntaxCast(JB_StringC* Self);

inline int JB_uint64_LELength(uint64 Self);

inline bool SC_Reg_FourBytes(ASMReg Self);

inline bool SC_Reg_IsBig(ASMReg Self);

inline bool SC_Reg_IsBool(ASMReg Self);

inline bool SC_Reg_IsFloat(ASMReg Self);

inline int SC_Reg_ToInt(ASMReg Self);

inline NilState SC_nil_SetNilness(ArchonPurger* Self, SCDecl* D, uint /*NilState*/ New);

inline void SC_nil__DeclKill();

inline NilState SC_nil__JumpSub(Message* Msg, NilCheckMode Test);

inline NilRecord SC_nil__Value();

inline bool JB_Safe_SyntaxCast(JB_String* Self);

inline bool SC_Decl_IsUnknownParam(SCDecl* Self);

inline ASMReg SC_Pac_GetASM(ASMState* Self, Message* Exp, ASMReg Dest);

inline bool SC_Reg_IsInt(ASMReg Self);

inline NilRecord SC_nil__EndBlock();

inline void SC_Msg_AddValue(Message* Self, SCFunction* F);

inline FatASM* SC_Reg_Read(ASMReg Self, Message* M, ASMReg Ptr, int Index);

inline FatASM* SC_Reg_Write(ASMReg Self, Message* M, ASMReg Ptr, int Index);

inline ASMReg SC_Pac_Exists(ASMState* Self, ASMReg Dest, ASMReg L, Message* Exp);

inline SCDecl* SC_TypeOfSwiz(Message* Exp, SCNode* Name_space, Message* Side, SCDecl* class_Space);


//// HEADER Inlines.h
inline bool JB_ErrorInt_SyntaxCast(ErrorInt Self) {
	return Self == 0;
}

inline bool JB_ErrorMarker_SyntaxCast(ErrorMarker Self) {
	return JB_StdErr->ErrorCount == Self;
}

inline bool JB_FastBuff_AppendU8(FastBuff* Self, uint /*byte*/ V) {
	Self->Curr++[0] = V;
	return Self->Curr >= Self->End;
}

inline bool JB_Ind_SyntaxCast(Ind Self) {
	return Self >= 0;
}

inline Syntax JB_Msg_Func(Message* Self) {
	iif (Self) {
		return Self->Func;
	}
	return nil;
}

inline JB_String* JB_Msg_Name(Message* Self) {
	iif (Self) {
		return Self->Name;
	}
	return JB_LUB[0];
}

inline JB_String* JB_Msg_Name_(Message* Self) {
	iif (Self) {
		return Self->Name;
	}
	return JB_LUB[0];
}

inline int JB_Sel_ID(Selector* Self) {
	iif (Self) {
		return Self->ID;
	}
	return 0;
}

inline bool JB_TC_SyntaxIs(uint /*DataTypeCode*/ Self, uint /*DataTypeCode*/ M) {
	return (Self & kJB__TC_PossibleBits) == (M & kJB__TC_PossibleBits);
}

inline JB_String* JB_Tk__SyntaxAccess(int S, int E, Syntax F) {
	return (JB__Tk_Splitter)(S, E, F);
}

inline bool JB_int64_IsPow2(int64 Self) {
	return (Self & (Self - 1)) == 0;
}

inline bool JB_int64_OperatorInRange(int64 Self, int64 D) {
	return (((uint64)Self) < ((uint64)D));
}

inline bool JB_int_IsPow2(int Self) {
	return (Self & (Self - 1)) == 0;
}

inline bool JB_int_OperatorInRange(int Self, int D) {
	iif (D > 0) {
		return (((uint)Self) < ((uint)D));
	}
	return false;
}

inline uint SC_FAT_Index(FatASM* Self) {
	return 1 + (Self - SC__Pac_Sh.FuncStart);
}

inline ASMReg SC_FAT_Info(FatASM* Self) {
	return SC_FAT_Info(Self);
}

inline ASM* SC_FAT_xC2xB5RenderInto(FatASM* Self, ASM* Where, ASM* After) {
	return (SC__ASM_Encoders[Self->Op])(Self, Where, After, 0);
}

inline bool SC_FailableInt_SyntaxCast(FailableInt Self) {
	return Self != ((int)kSC__FailableInt_Fail);
}

inline JB_String* SC_Named_Name(SCNamed* Self) {
	iif (Self) {
		return Self->Name;
	}
	return JB_LUB[273];
}

inline bool SC_PA_SyntaxCast(SCParamArray* Self) {
	return (Self != nil) and Self->HasProperParams;
}

inline DataTypeCode SC_Reg_xC2xB5Type(ASMReg Self) {
	return ((DataTypeCode)Self) & kJB__TC_PossibleBits;
}

inline NilRecord SC_nil_Value(ArchonPurger* Self) {
	return Self->Neel[0];
}

inline void SC_nil_ValueSet(ArchonPurger* Self, NilRecord Dest) {
	Self->Neel[0] = (Dest & Self->Realnesses);
}

inline FatASM* SC_uint_FAT(uint Self) {
	return SC__Pac_Sh.FuncStart + (Self - 1);
}

inline void JB_Array_SortBool(Array* Self, FP_SorterComparerBool Compare) {
	JB_Array_Sort(Self, ((FP_SorterComparer)Compare));
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

inline void JB_FS_AppendFloat(FastString* Self, float D, int Dp, bool CanExp, bool Dot) {
	JB_FS_AppendDoubleAsText(Self, ((Float64)D), Dp, CanExp, Dot);
}

inline void JB_FS_AppendInt64(FastString* Self, int64 Data) {
	JB_FS_AppendIntegerAsText(Self, Data, 1);
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

inline byte* JB_Str_Addr(JB_String* Self) {
	return JB_Str_Address(Self);
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

inline bool SC_Reg_FourBytes(ASMReg Self) {
	return JB_TC__Shift(((DataTypeCode)Self)) == 2;
}

inline bool SC_Reg_IsBig(ASMReg Self) {
	return JB_TC__Shift(((DataTypeCode)Self)) == 3;
}

inline bool SC_Reg_IsBool(ASMReg Self) {
	return JB_TC_SyntaxIs(SC_Reg_xC2xB5Type(Self), kJB__TC_bool);
}

inline bool SC_Reg_IsFloat(ASMReg Self) {
	return JB_TC_IsFloat(((DataTypeCode)Self));
}

inline int SC_Reg_ToInt(ASMReg Self) {
	return SC_Reg_Reg(Self);
}

inline NilState SC_nil_SetNilness(ArchonPurger* Self, SCDecl* D, uint /*NilState*/ New) {
	NilRecorder* P = ((NilRecorder*)(Self->Neel));
	(SC_NRC_SyntaxCallSet((P), D->NilReg, New));
	return New;
}

inline void SC_nil__DeclKill() {
	iif (!SC_nil_NestDepth((&SC__nil_T))) {
		SC__nil_T.RootReturned = true;
	}
	(SC_nil_ValueSet((&SC__nil_T), kSC__NilState_Basic));
}

inline NilState SC_nil__JumpSub(Message* Msg, NilCheckMode Test) {
	uint T = SC_Msg_ASMType(Msg);
	iif (T) {
		return (SC__nil_NilTable[T])(Msg, Test);
	}
	T = ((ASMType)Msg->Func);
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

inline ASMReg SC_Pac_GetASM(ASMState* Self, Message* Exp, ASMReg Dest) {
	fn_asm Fn = SC_fn_asm_table[SC_Msg_ASMType(Exp)];
	uint TmpCloser = Self->VTmps;
	ASMReg Ss = (Fn)(Self, Exp, Dest, 0);
	iif (!SC_Reg_SyntaxIs(Dest, kSC__Reg_StayOpen)) {
		SC_Pac_CloseVTmps(Self, TmpCloser);
	}
	return Ss;
}

inline bool SC_Reg_IsInt(ASMReg Self) {
	return JB_TC_IsInt(((DataTypeCode)Self));
}

inline NilRecord SC_nil__EndBlock() {
	NilRecord Rz = 0;
	Rz = SC_nil__Value();
	(SC_nil_ValueSet((&SC__nil_T), kSC__NilState_Basic));
	return Rz;
}

inline void SC_Msg_AddValue(Message* Self, SCFunction* F) {
	iif (!JB_Ring_HasChildCount(Self, 2)) {
		iif (true) {
			Message* __varf1 = F->Source;
			MessagePosition _usingf0 = ((MessagePosition){});
			JB_Msg_SyntaxUsing(__varf1, (&_usingf0));
			JB_Tree_SyntaxAppend(Self, (JB_Syx_Msg(kJB_SyxThg, JB_LUB[1268])));
			JB_MsgPos_SyntaxUsingComplete((&_usingf0), __varf1);
			JB_MsgPos_Destructor((&_usingf0));
		}
	}
}

inline FatASM* SC_Reg_Read(ASMReg Self, Message* M, ASMReg Ptr, int Index) {
	return SC_Reg_ReadOrWriteWithMsgRegIntBool(Self, M, Ptr, Index, false);
}

inline FatASM* SC_Reg_Write(ASMReg Self, Message* M, ASMReg Ptr, int Index) {
	return SC_Reg_ReadOrWriteWithMsgRegIntBool(Self, M, Ptr, Index, true);
}

inline ASMReg SC_Pac_Exists(ASMState* Self, ASMReg Dest, ASMReg L, Message* Exp) {
	return SC_Pac_Equals(Self, Dest, L, SC_Reg__New(), Exp);
}

inline SCDecl* SC_TypeOfSwiz(Message* Exp, SCNode* Name_space, Message* Side, SCDecl* class_Space) {
	int W = SC_Class_NumericCount(class_Space->Type);
	iif ((W > 1) and (!JB_Ring_HasChildren(((Message*)JB_Ring_Last(Exp))))) {
		int Swz = SC_Str_IsSwizzle(Exp->Name, W);
		iif (Swz) {
			return SC_TypeOfSwizzle(Exp, class_Space, Name_space, Side, Swz);
		}
	}
	return nil;
}



}
#endif // __JB_H__
