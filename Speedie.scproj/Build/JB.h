

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

typedef uint ASMParam;

typedef uint64 ASMReg;

typedef u16 ASMType;

typedef uint CharSet;

typedef int ClassInfo;

typedef int Codepoint;

typedef int CompilerStage;

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

typedef int ErrorMarker;

typedef byte ErrorSeverity;

typedef int ExitCode;

typedef int FailableInt;

typedef int FileDes;

typedef int FileMode;

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

typedef vec4 Plane3D;

typedef byte ProcessMode;

typedef int SCBlockage;

typedef uint SCDeclInfo;

typedef int SCNodeFindMode;

typedef byte SCNodeInfo;

typedef byte SCNodeType;

typedef int SizeInt;

typedef int SortComparison;

typedef byte Syntax;

typedef byte TaskState;

typedef int TerminalColor;

typedef int jbinLeaver;

typedef vec4 mat2;

typedef u16 MuParam;

typedef ASM ASM_AddAK;

typedef ASM ASM_AddB;

typedef ASM ASM_AddK;

typedef ASM ASM_AddOrSubM;

typedef ASM ASM_Alloc;

typedef ASM ASM_BFLD;

typedef ASM ASM_BFLS;

typedef ASM ASM_Bra;

typedef ASM ASM_CNTC;

typedef ASM ASM_CmpF;

typedef ASM ASM_CmpI;

typedef ASM ASM_Compare4;

typedef ASM ASM_ConstStretchy;

typedef ASM ASM_Convert;

typedef ASM ASM_Div;

typedef ASM ASM_Div2;

typedef ASM ASM_Float;

typedef ASM ASM_FloatConst;

typedef ASM ASM_ForeignFunc;

typedef ASM ASM_Func;

typedef ASM ASM_FuncAddr;

typedef ASM ASM_GObj;

typedef ASM ASM_GTable;

typedef ASM ASM_HALT;

typedef ASM ASM_JCmpEq;

typedef ASM ASM_JCmpF;

typedef ASM ASM_JCmpI;

typedef ASM ASM_JCmpK;

typedef ASM ASM_Jump;

typedef ASM ASM_Loop;

typedef ASM ASM_MemUtil;

typedef ASM ASM_MemoryCopy;

typedef ASM ASM_REQ;

typedef ASM ASM_RET;

typedef ASM ASM_Read;

typedef ASM ASM_RefDecrMem;

typedef ASM ASM_RefReturn;

typedef ASM ASM_RefSet1;

typedef ASM ASM_RefSet2;

typedef ASM ASM_RefSet3;

typedef ASM ASM_RefSetApart;

typedef ASM ASM_RotateConst;

typedef ASM ASM_Shift;

typedef ASM ASM_Swap;

typedef ASM ASM_TERN;

typedef ASM ASM_Tail;

typedef ASM ASM_Trap;

typedef ASM ASM_U0;

typedef ASM ASM_U1;

typedef ASM ASM_U2;

typedef ASM ASM_U3;

typedef ASM ASM_U4;

typedef ASM ASM_VecBuild;

typedef ASM ASM_VecConst;

typedef ASM ASM_VecGet;

typedef ASM ASM_VecInc;

typedef ASM ASM_VecMix;

typedef ASM ASM_VecSet;

typedef ASM ASM_VecSwizzle;

typedef ASM ASM_Write;

typedef Date JB_Duration;

typedef Date HumanDate;

struct ASMState;

struct ArchonPurger;

struct ArgArrayCounter;

struct AtomicLock;

struct CompressionStats;

struct DDA_Caster;

struct DeclAlterable;

struct FastBuff;

struct FatASM;

struct FatRange;

struct FloatRange;

struct HairyMan;

struct InlineInfo;

struct IntDownRange;

struct IsaTester;

struct LeakTester;

struct LoopInfo;

struct Mat4;

struct MessagePosition;

struct NilRecorder;

struct Object_Behaviour;

struct ParserLineAndIndent;

struct RandomXOR;

struct RegFile;

struct RetroFloat;

struct StructWithObj;

struct TerminalDisplay;

struct VirtualJBString;

struct Array_Behaviour;

struct Assembler;

struct AutoItem_Behaviour;

struct CppRefs_Behaviour;

struct Cpp_Export_Behaviour;

struct DataObject_Behaviour;

struct DictionaryReader_Behaviour;

struct Dictionary_Behaviour;

struct ErrorReceiver_Behaviour;

struct FastString_Behaviour;

struct FixedDict_Behaviour;

struct FlowControl_Behaviour;

struct InputStream_Behaviour;

struct Instruction_Behaviour;

struct MemoryLayer_Behaviour;

struct Memory_Behaviour;

struct SCImport_Behaviour;

struct SCNodeRenamer_Behaviour;

struct SCObject_Behaviour;

struct SCOperator_Behaviour;

struct SCParamArray_Behaviour;

struct SavedRegisters;

struct Selector_Behaviour;

struct String_Behaviour;

struct SyntaxObj_Behaviour;

struct TokenHandler_Behaviour;

struct UnixProcess_Behaviour;

struct Validator_Behaviour;

struct list_Behaviour;

struct xC2xB5Form_Behaviour;

struct FastStringCpp_Behaviour;

struct File_Behaviour;

struct Message_Behaviour;

struct SCDecl_Behaviour;

struct SCIterator_Behaviour;

struct SCNode_Behaviour;

struct SpdProcess_Behaviour;

struct StringShared_Behaviour;

struct StringZeroTerminated_Behaviour;

struct Task_Behaviour;

struct Error_Behaviour;

struct MessageID_Behaviour;

struct SCArg_Behaviour;

struct SCBehaviour_Behaviour;

struct SCBetterNode_Behaviour;

struct SCFile_Behaviour;

struct SCClass_Behaviour;

struct SCFunction_Behaviour;

struct SCModule_Behaviour;

struct AutoItem;

struct CppRefs;

struct Cpp_Export;

struct DTWrap;

struct JB_ErrorReceiver;

struct FixedDict;

struct FlowControl;

struct InputStream;

struct Instruction;

struct MWrap;

struct JB_Object;

struct SCImport;

struct SCNodeRenamer;

struct SCObject;

struct SCOperator;

struct SCParamArray;

struct Selector;

struct SyntaxObj;

struct Validator;

struct xC2xB5Form;

struct DTWrap;

struct DTWrap;

struct FastStringCpp;

struct FastString;

struct Message;

struct Dictionary;

struct SCDecl;

struct SCIterator;

struct SCNode;

struct SpdProcess;

struct JB_String;

struct JB_Task;

struct Validator;

struct Validator;

struct JB_Error;

struct Message;

struct Message;

struct MessageID;

struct Message;

struct SCArg;

struct SCBehaviour;

struct SCBetterNode;

struct SCFile;

struct Message;

struct JB_Task;

struct ParserCallBack;

struct SCClass;

struct SCFunction;

struct SCModule;

typedef ASM* (*ASM_Encoder)(FatASM* Self, ASM* Curr, ASM* After);

typedef int64 (*CakeVM_CakeChef)(CakeVM* Self, int Index, int BreakValue, ivec4* Reg0);

typedef SCNode* (*FP_CollectFunc)(Message* Node, SCNode* Name_space, Message* ErrPlace);

typedef SCObject* (*FP_ExprResolver)(Message* Exp, SCNode* Name_space, Message* Side);

typedef NilState (*FP_NilTrackerFn)(Message* Msg, NilCheckMode Test);

typedef Message* (*FP_ParseHandler)(int Start, Message* Parent);

typedef bool (*FP_ShellOption)(JB_String* Name, JB_String* Value, FastString* Purpose);

typedef SortComparison (*FP_SorterComparer)(JB_Object* Self, JB_Object* B);

typedef bool (*SpdProcess_Thread)(SpdProcess* Self, PicoComms* Comms, int64 Data, _cstring* Args);

typedef JB_Object* (*TokenHandler_fp)(int Start, Message* Parent);

typedef bool (*FP_TranFunc)(SCFunction* Fn, Message* Node, SCNode* Name_space);

typedef JB_String* (*__Message_CopyID__)(Message* Self);

typedef JB_String* (*__Message_DisplayName__)(Message* Self, int I);

typedef JB_String* (*__Object_Render__)(JB_Object* Self, FastString* Fs_in);

typedef bool (*__Message_TextSet__)(Message* Self, int I, JB_String* V);

typedef void (*FP_fnErrorLogger)(JB_ErrorReceiver* Self, JB_String* Data);

typedef JB_String* (*FP_fnIDGenerator)(int Start, int End, Syntax F);

typedef bool (*FP_fnPreReader)(SCFunction* Self, Message* Msg);

typedef int64 (*fn_ASMConstifier)(ASMReg L, ASMReg R);

typedef ASMReg (*fn_OpASM)(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

typedef ASMReg (*fn_asm)(Assembler* Self, Message* Exp, ASMReg Dest);

typedef void (*FP_fpMsgRender)(Message* Self, FastString* Fs);

typedef void (*FP_fpMsgRenderCpp)(Message* Self, FastStringCpp* Fs);

typedef void (*InputStream_ParserCallBack_interface_prototype)(JB_Task* Self, Message* Msg);

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
#define kSyxURL 48
#define kSyxXAtt 49
#define kSyxXML 50
#define kSyxXPI 51
#define kSyxXCom 52
#define kSyxXCDT 53
#define kSyxXTxt 54
#define kSyxXDTD 55
#define kSyxmax 56

//// HEADER Proj.h

struct ASMState {
	SCFunction* Fn;
	ASMReg Return;
	uint64 ParentVars;
	byte BranchDepth;
	bool TailInlineable;
};

struct ArchonPurger {
	NilRecord* Neel;
	NilRecord* RowEnd;
	NilRecord Realnesses;
	SCDecl* Decls[32];
	Message* Closers[32];
	SCDecl* Return;
	int InsideBoolLogic;
	bool FnAbleToNilCheck;
	bool AnyReturns;
	NilRecord Rows[64];
};

struct ArgArrayCounter {
	int i;
	int Max;
	bool IsItem;
	bool IsNotItem;
};

struct CompressionStats {
	JB_Duration Duration;
	int In;
	int Out;
	byte Purpose;
	bool Live;
};

struct DeclAlterable {
	uint64 ExportPosition;
	SCDeclInfo Info;
	DataTypeCode DataType;
	u16 ModuleNum;
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
	byte BranchID;
	byte InputFats;
	byte InputPrms;
	byte _Outputs;
	byte _Op;
	byte JumpPrm;
	u16 ASMIndex;
	u16 BasicBlock;
	s16 xC2xB5RefCount;
	uint SrcMap;
	ASMParam Prms[6];
	uint64 _Const;
	ASMReg Info;
	Message* Msg;
};

struct FatRange {
	FatASM* Start;
	FatASM* After;
	MaybeBool Constness;
};

struct HairyMan {
	u16 Savings;
	u16 Curr;
	uint Total;
};

struct InlineInfo {
	ASMReg Items[10];
	uint Altered;
	uint References;
	uint Normal;
};

struct IsaTester {
	Message* Items[4];
	int Count;
	bool InUse;
};

struct LeakTester {
	int MemUsedStart;
	JB_String* Name;
};

struct LoopInfo {
	NilRecord ContRecord;
	NilRecord ExitRecord;
	byte BranchDepth;
	bool HasEscape;
};

struct MessagePosition {
	JB_MemoryLayer* Layer;
	int Position;
	int Length;
	MsgParseFlags Flags;
	u16 Tag;
};

struct NilRecorder {
	NilRecord Value;
};

struct ParserLineAndIndent {
	int Lines;
	int Position;
	int Dentine;
	int IsDebug;
	int FirstLine;
};

struct RandomXOR {
	uint64 Store;
	uint64 State;
};

struct RegFile {
	u16 Setters[32];
	int KnownMap;
};

struct TerminalDisplay {
	Array* Screen;
	FastString* fs;
	Date LastDisplay;
};

struct VirtualJBString {
	int Refcount;
	int Length;
	byte* Addr;
};

struct Assembler {
	u16 BasicBlock;
	ASMState InlineState[8];
	byte InlineDepth;
	byte DeepestInline;
	byte InlineDepthLimit;
	uint RegDebugInfo;
	uint VDecls_;
	uint VTemps_;
	int CurrFuncGrab;
	u16 BranchID;
	u16 NextBranchID;
	bool NeedsRework;
	bool Inited;
	SCFunction* Out;
	FatASM* InlineEnd;
	FatASM* FuncStart_;
	FatASM* Start;
	FatASM* Curr_;
	FatASM* End;
	RegFile Regs;
	FatASM Zero;
};

struct SavedRegisters {
	byte RegCount;
	u16 BasicBlock;
	DeclAlterable Decls[32];
	RegFile Regs;
};

struct Object_Behaviour {
	void* __destructor__;
	__Object_Render__ render;
};

struct Array_Behaviour: Object_Behaviour {
};

struct AutoItem_Behaviour: Object_Behaviour {
};

JBClass ( AutoItem , JB_Object , 
	JB_String* Sort;
	JB_String* Insert;
	SCObject* Value;
	JB_String* Display;
	bool Exact;
	int Type;
);

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
	FastStringCpp* GlobsInLib;
	FastStringCpp* Syxes;
	FastStringCpp* Inlines;
	FastStringCpp* ModuleProperties;
);

struct DataObject_Behaviour: Object_Behaviour {
};

JBClass ( DTWrap , JB_Object , 
	DataTypeCode Kind;
	byte DeathAction;
	int64 PrivValue;
);

struct Dictionary_Behaviour: Object_Behaviour {
};

struct DictionaryReader_Behaviour: Object_Behaviour {
};

struct ErrorReceiver_Behaviour: Object_Behaviour {
};

JBClass ( JB_ErrorReceiver , JB_Object , 
	int MaxErrors;
	JB_Object* _LogObj;
	ErrorSeverity LowerErrorsTo;
	bool BlockErrors;
	int MaxProblems;
	int ErrorCount;
	int ProblemCount;
	int WarnCount;
	JB_Error* Errors;
	FP_fnErrorLogger _LogFunc;
	JB_String* Source;
);

struct FastString_Behaviour: Object_Behaviour {
};

struct FlowControl_Behaviour: Object_Behaviour {
};

JBClass ( FlowControl , JB_Object , 
	bool CanDoErrors;
	FastString* Write;
	InputStream* ReadInput;
	FastBuff Buff;
);

struct InputStream_Behaviour: Object_Behaviour {
};

JBClass ( InputStream , JB_Object , 
	int StartFrom;
	JB_File* File;
	bool _NoMoreChunks;
	bool TryRecoverBadData;
	int ChunkSize;
	int Length;
	ParserCallBack* CallBack;
	JB_Object* _Object;
	FastBuff Data;
);

struct Instruction_Behaviour: Object_Behaviour {
};

JBClass ( Instruction , JB_Object , 
	byte OpCode;
	byte aType;
	byte PCount;
	xC2xB5Form* Sizes;
	JB_String* Name;
);

struct Memory_Behaviour: Object_Behaviour {
};

JBClass ( MWrap , JB_Object , 
	uint ItemSize;
	byte* _Ptr;
	byte DeathAction;
	int Length;
	int Size;
);

struct MemoryLayer_Behaviour: Object_Behaviour {
};

struct SCImport_Behaviour: Object_Behaviour {
};

JBClass ( SCImport , JB_Object , 
	int Depth;
	JB_File* Where;
	bool IsSTDLib;
	bool WarnUnusedFuncs;
	ErrorSeverity BlindCast;
	Array* Files;
	JB_MemoryLayer* DeclLayer;
	SCModule* Mod;
	Dictionary* Resources;
);

struct SCNodeRenamer_Behaviour: Object_Behaviour {
};

JBClass ( SCNodeRenamer , JB_Object , 
	Array* Nodes;
	JB_String* Name;
);

struct SCObject_Behaviour: Object_Behaviour {
};

JBClass ( SCObject , JB_Object , 
	u16 CurrFuncLink;
	u16 GPackID;
	Array* LinkFrom;
	byte NoAutoComplete;
	byte AllocSource;
	SCNodeInfo NodeInfo;
	u16 FPackID;
	Message* Source;
	JB_String* Name;
	JB_String* ExportName;
);

struct SCOperator_Behaviour: Object_Behaviour {
};

JBClass ( SCOperator , JB_Object , 
	int Score;
	JB_String* CompOp;
	OpMode Kind;
	JB_String* CompParam;
	JB_String* FuncName;
	fn_OpASM OpASM;
	JB_String* Name;
	SCOperator* Opposite;
);

struct SCParamArray_Behaviour: Object_Behaviour {
};

JBClass ( SCParamArray , JB_Object , 
	s16 Size;
	s16 ErrCount;
	Message* Items[8];
	Message* Exp;
	int8 FailedAt;
	bool HasSide;
	bool HasProperParams;
	bool IsDot;
	bool IsAddress;
	bool IsNotModule;
	bool IsSelf;
	bool IsSuper;
	bool Found;
	bool AllowSelfToConstructor;
	SCClass* Cls;
	JB_String* LookupName;
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

struct SyntaxObj_Behaviour: Object_Behaviour {
};

JBClass ( SyntaxObj , JB_Object , 
	Syntax ID;
	JB_String* LongName;
	JB_String* Name;
	FP_fpMsgRender ExportAddr;
	FP_fpMsgRender RenderAddr;
);

struct TokenHandler_Behaviour: Object_Behaviour {
};

struct UnixProcess_Behaviour: Object_Behaviour {
};

struct list_Behaviour: Object_Behaviour {
};

struct xC2xB5Form_Behaviour: Object_Behaviour {
};

JBClass ( xC2xB5Form , JB_Object , 
	int Count;
	Message* src;
	MuParam Params[6];
	int TotalBits;
	int RegsAltered;
	int Index;
	int RegForJump;
	JB_String* Name;
);

struct FastStringCpp_Behaviour: FastString_Behaviour {
};

JBClass ( FastStringCpp , FastString , 
	JB_String* Cpp_Name;
);

struct File_Behaviour: String_Behaviour {
};

struct Message_Behaviour: list_Behaviour {
	__Message_CopyID__ copyid;
	__Message_DisplayName__ displayname;
	__Message_TextSet__ textset;
};

JBClass ( Message , JB_List , 
	Syntax Func;
	byte Indent;
	u16 RangeLength;
	MsgParseFlags Flags;
	u16 Tag;
	JB_String* Name;
);

struct SCDecl_Behaviour: SCObject_Behaviour {
};

JBClass ( SCDecl , SCObject , 
	NilState NilDeclared;
	byte PointerCount;
	byte NilReg;
	byte DepthOfBranch;
	byte DepthOfLoop;
	bool Suffers;
	bool WasHex;
	int C_Array;
	SCClass* Type;
	SCFunction* HiderFunc;
	JB_Object* IsLookupOnly;
	SCDecl* Internal;
	SCDecl* LocalVarList;
	SCDecl* Contains;
	Message* Default;
	DeclAlterable mu;
);

struct SCIterator_Behaviour: SCObject_Behaviour {
};

JBClass ( SCIterator , SCObject , 
	bool OK;
	Message* Yield;
	Message* WhileLoop;
	Message* Value;
	Message* LoopEndCond;
	Message* Index;
	SCNodeRenamer* ValueRenamer;
	SCNodeRenamer* selfs;
	Array* Names;
);

struct SCNode_Behaviour: SCObject_Behaviour {
};

JBClass ( SCNode , SCObject , 
	Dictionary* Access;
	SCDecl* LocalVarList;
	SCNode* Parent;
	SCNode* MyReacher;
	SCImport* Project;
);

struct SpdProcess_Behaviour: UnixProcess_Behaviour {
};

JBClass ( SpdProcess , ShellStream , 
	bool AlreadyWarnedDied;
	int DeathLimit;
	SpdProcess_Thread SubProcess;
	FastString* Writer;
);

struct StringShared_Behaviour: String_Behaviour {
};

struct StringZeroTerminated_Behaviour: String_Behaviour {
};

struct Task_Behaviour: list_Behaviour {
};

JBClass ( JB_Task , JB_List , 
	TaskState _State;
	int _Object;
	void* _func;
);

struct Error_Behaviour: Message_Behaviour {
};

JBClass ( JB_Error , Message , 
	ErrorSeverity Severity;
	ErrorFlags ErrorFlags;
	JB_String* StackTrace;
	Message* Node;
	Date When;
	JB_String* Path;
	JB_String* OriginalData;
);

struct MessageID_Behaviour: StringShared_Behaviour {
};

JBClass ( MessageID , JB_StringShared , 
	Syntax Func;
	int Position;
	int64 Frequency;
	int64 ID;
	JB_Object* Obj;
);

struct SCArg_Behaviour: SCNode_Behaviour {
};

JBClass ( SCArg , SCNode , 
	Message* TmpMovedOutFor;
	bool IsClassArg;
	bool IsStatementExpr;
	SCFunction* ParentFunc;
);

struct SCBehaviour_Behaviour: SCNode_Behaviour {
};

JBClass ( SCBehaviour , SCNode , 
	SCModule* FuncTable;
	Dictionary* Interfaces;
	Array* WrapperFuncs;
);

struct SCBetterNode_Behaviour: SCNode_Behaviour {
};

JBClass ( SCBetterNode , SCNode , 
	JB_String* Description;
);

struct SCFile_Behaviour: File_Behaviour {
};

JBClass ( SCFile , JB_File , 
	bool Unfinished;
	bool IsInternal;
	bool UsedByASM;
	u16 FileNum;
	Message* OrigAST;
	Message* LiveAST;
	JB_String* ExportName;
	SCImport* Proj;
	JB_String* FData;
	Array* Types;
);

JBClass ( ParserCallBack , JB_Task , 
	InputStream* Upon;
);

struct SCClass_Behaviour: SCBetterNode_Behaviour {
};

JBClass ( SCClass , SCBetterNode , 
	byte Depth;
	byte Alignment;
	byte MinOpt;
	byte Behaviourness;
	byte IsWrapper;
	byte IsRole;
	SCNodeType BaseType;
	DataTypeCode TypeInfo;
	DataTypeCode ASMTypeInfo;
	u16 TableID;
	u16 ClsSizeRaw;
	u16 ClsSize;
	u16 TaskObjectCount;
	ClassInfo Flags;
	SCDecl* DataObject;
	SCClass* DowngradeTo;
	SCClass* ProcessAs;
	SCBehaviour* Behaviour;
	Message* IsModel;
	SCDecl* SelfDecl;
	SCDecl* ClassType;
	JB_String* CppClass;
	SCFunction* DestructorFunc;
	SCFunction* ConstructorFunc;
	SCFunction* TheBoolFunc;
	SCFunction* TheCompareFunc;
	SCFunction* TheIsFunc;
	SCFunction* FuncProto;
	SCDecl* TypeReal;
	Array* Casts;
	Array* Children;
	SCDecl* Contained;
	SCDecl* Signed;
	SCDecl* _NotConst;
	SCClass* Super;
	Message* Defawlt;
	Message* False;
	SCModule* Modul;
	Array* Properties;
	SCDecl* TypeNormal;
	SCDecl* TypeOptional;
);

struct SCFunction_Behaviour: SCBetterNode_Behaviour {
};

JBClass ( SCFunction , SCBetterNode , 
	NilState NilSelf;
	byte ReturnedVars;
	byte FSOpt;
	byte MinOpt;
	byte MaxASM;
	byte IsAssigns;
	byte IsCppInBuilt;
	ErrorSeverity BlindCasts;
	byte IsNilChecker;
	byte Badness;
	byte IntPrmCount;
	byte StructReturnPos;
	u16 LinkDepth;
	u16 TmpCounter;
	u16 LinkID;
	u16 xC2xB5ASMLength;
	FunctionType FuncInfo;
	uint xC2xB5Start;
	uint xC2xB5FATLength;
	SCDecl* HasProto;
	SCClass* ProtoType;
	SCDecl* ReturnType;
	SCFunction* DepthFinder;
	Message* IsMacro;
	Array* LinkTo;
	Array* Args;
	SCClass* Cls;
	CppRefs* Refs;
	JB_Error* SavedError;
	Message* Intrinsic;
	SCFunction* NextFunc;
);

struct SCModule_Behaviour: SCBetterNode_Behaviour {
};

JBClass ( SCModule , SCBetterNode , 
	bool Inited;
	bool IsImport;
	bool IsRequiredInterface;
	int ModuleNum;
	Message* InitAfter;
	CppRefs* DefaultRefs;
	JB_String* CppPart;
	Array* Globals;
	Message* InitCodeArg;
	SCClass* Cls;
	Message* InitVarsArg;
);
#define JB__App__Args JB__.App__Args
#define JB__App__Conf JB__.App__Conf
#define JB__App__Path JB__.App__Path
#define JB__App__Prefs JB__.App__Prefs
#define JB__App__stdin JB__.App__stdin
#define JB__App__StdOut JB__.App__StdOut
#define JB__App_Usage JB__.App_Usage
extern JB_String* SC__AutoComplete_function_anywhere;
extern JB_String* SC__AutoComplete_function_cls_only;
extern JB_String* SC__AutoComplete_function_names;
extern Dictionary* SC__AutoComplete_Functions;
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
extern Message* SC__Comp_ConfMsg;
extern Message* SC__Comp_ConstantsList;
extern int SC__Comp_CurrStage;
extern Array* SC__Comp_DeclConstants;
extern SCModule* SC__Comp_DisamClasses;
extern SCModule* SC__Comp_DisamModules;
extern byte SC__Comp_During;
extern Dictionary* SC__Comp_ExportGlobs;
extern Dictionary* SC__Comp_ExportNames;
extern Message* SC__Comp_ExtendList;
extern Array* SC__Comp_ExtendModuleList;
extern Dictionary* SC__Comp_Files;
extern SCFunction* SC__Comp_fnAs;
extern SCFunction* SC__Comp_fnFastAs;
extern SCFunction* SC__Comp_fnFastIsa;
extern SCFunction* SC__Comp_fnIsa;
extern Array* SC__Comp_FuncList;
extern bool SC__Comp_HasFunny;
extern Array* SC__Comp_ImportedList;
extern Dictionary* SC__Comp_ImportedNames;
extern SCNodeInfo SC__Comp_InBuiltType;
extern bool SC__Comp_InitedOK;
extern byte SC__Comp_InPerry;
extern Dictionary* SC__Comp_InsecureWords;
extern SCFile* SC__Comp_InternalFile;
extern SCNode* SC__Comp_Interpreter;
extern JB_File* SC__Comp_JeeboxProj_;
#define kSC__Comp_kTimeWidth ((int)19)
extern Date SC__Comp_LastTime;
extern JB_String* SC__Comp_LastTimeName;
extern JB_File* SC__Comp_Library;
extern SCFunction* SC__Comp_MainFunc;
extern Array* SC__Comp_ModuleList;
extern Dictionary* SC__Comp_Numbers;
extern JB_String* SC__Comp_OriginalInputPath;
extern SCModule* SC__Comp_Program;
extern SCImport* SC__Comp_Project;
extern JB_String* SC__Comp_ProjectName;
extern Array* SC__Comp_ProtoTypes;
extern Array* SC__Comp_ReachedClassTable;
extern SCFunction* SC__Comp_RefClear;
extern SCFunction* SC__Comp_RefDecr;
extern SCFunction* SC__Comp_RefDecrMulti;
extern SCFunction* SC__Comp_RefEarlyDecr;
extern SCFunction* SC__Comp_RefEarlyDecrMulti;
extern SCFunction* SC__Comp_RefFreeIfDead;
extern SCFunction* SC__Comp_RefIncr;
extern SCFunction* SC__Comp_RefIncr2;
extern SCFunction* SC__Comp_RefNew;
extern SCFunction* SC__Comp_RefSafeDecr;
extern SCFunction* SC__Comp_RefSetRef;
extern JB_String* SC__Comp_StageName;
extern int SC__Comp_stDebugInfo;
extern int SC__Comp_stLibFuncs;
extern int SC__Comp_stParseTime;
extern int SC__Comp_stParseTimeTotal;
extern int SC__Comp_stReachedClass;
extern int SC__Comp_stReachedFunc;
extern int SC__Comp_stTotalASMOps;
extern int SC__Comp_stTotalFileCount;
extern int64 SC__Comp_stTotalSourceSize;
extern byte SC__Comp_Successfulness;
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
#define kSC__CustomOps_OnlyLeftIsVector ((int)257)
#define kSC__CustomOps_OnlyRightIsVector ((int)258)
#define kSC__CustomOps_RecheckType ((int)4)
#define kSC__CustomOps_TypeCastFromBool ((int)16)
#define kSC__CustomOps_TypeCastToBetter ((int)32)
#define kSC__CustomOps_TypeCastToSmaller ((int)64)
extern SCFunction* SC__FastStringOpts_FnAppend;
extern SCFunction* SC__FastStringOpts_FnAppend4;
extern SCFunction* SC__FastStringOpts_FnAppend6;
extern SCFunction* SC__FastStringOpts_FnByte;
extern SCFunction* SC__FastStringOpts_FnGetResult;
extern SCFunction* SC__FastStringOpts_FnPlus;
extern int SC__FastStringOpts_FSRemoved;
extern int SC__FastStringOpts_InitedOK;
extern int SC__FastStringOpts_StrRemoved;
extern int SC__FastStringOpts_VargCount;
extern Dictionary* SC__FB_AppOptions;
extern Message* SC__AC_all_tmp_src;
extern SCFunction* SC__AC_AnonFn;
extern SCNode* SC__AC_AnonParent;
extern JB_String* SC__AC_AnonText;
extern bool SC__AC_Cleaned;
extern JB_ErrorReceiver* SC__AC_Errors;
extern Message* SC__AC_func_tmp_src;
extern int SC__AC_max_total;
extern SCObject* SC__AC_OrigFn;
extern JB_String* SC__AC_TestCrash;
extern int SC__AC_total;
extern Array* SC__Intrinsics_Floats;
extern Array* SC__Intrinsics_Vectors;
#define JB__API_NilHappened_ JB__.API_NilHappened_
#define JB__Constants__FuncArray JB__.Constants__FuncArray
#define JB__Constants__SyxDict JB__.Constants__SyxDict
#define JB__Constants_EscapeChr JB__.Constants_EscapeChr
#define JB__Constants_EscapeStr JB__.Constants_EscapeStr
#define JB__Constants_JS_EscapeStr JB__.Constants_JS_EscapeStr
#define JB__Constants_JS_UnEscapeStr JB__.Constants_JS_UnEscapeStr
#define JB__Constants_UnEscapeStr JB__.Constants_UnEscapeStr
#define JB__Constants_XML_EscapeStr JB__.Constants_XML_EscapeStr
#define JB__Constants_XML_UnEscapeStr JB__.Constants_XML_UnEscapeStr
extern int SC__LibStability_LastLibID;
extern Message* SC__Linkage_Flagz;
extern Message* SC__Linkage_OSXFrameworks;
#define kJB__MZLab_Default ((int)20)
#define kJB__MZLab_Fast ((int)10)
#define kJB__MZLab_None ((int)0)
#define kJB__MZLab_Strong ((int)20)
#define kJB__MZLab_Strongest ((int)30)
extern Message* SC__Macros_ConstructorNew;
extern Message* SC__Macros_ConstructorNewTask;
extern Message* SC__Macros_InitExpand;
extern Message* SC__Macros_MainArgArray;
extern Message* SC__Macros_MainArgBasic;
extern Message* SC__Macros_MainArgBasicReq;
extern Message* SC__Macros_MainArgDefault;
extern Message* SC__Macros_MainArgNoNE;
extern Message* SC__Macros_MultiDecr;
extern Message* SC__Macros_MultiEarlyDecr;
extern Message* SC__Macros_WhileDecl;
#define kJB__Math_E (2.7182818284590452353602874713526f)
#define kJB__Math_iTau (0.15915494309f)
extern JB_String* SC__Options_Arch;
extern bool SC__Options_ArgStats;
extern Dictionary* SC__Options_BannedClasses;
extern bool SC__Options_Beep;
#define kSC__Options_cake ((int)2)
extern bool SC__Options_Compile;
extern bool SC__Options_CompileDebugSeparately;
#define kSC__Options_cpp ((int)1)
extern int SC__Options_Dev;
extern JB_String* SC__Options_exe_path;
extern bool SC__Options_ExternalCompile;
extern bool SC__Options_ForceRecompile;
extern bool SC__Options_GenFlowControlCode;
extern bool SC__Options_HideawayScripts;
extern bool SC__Options_InlineLib;
extern bool SC__Options_IsDirectTest;
extern bool SC__Options_KeepAllErrors;
extern bool SC__Options_MakeExec;
extern byte SC__Options_Mode;
extern bool SC__Options_NilTestAllocNeverFails;
extern byte SC__Options_OperationCount;
extern int8 SC__Options_Optimise;
extern JB_String* SC__Options_output_path;
extern byte SC__Options_PerryOutput;
extern bool SC__Options_PrintCompileString;
extern bool SC__Options_PrintLibraries;
extern bool SC__Options_PrintMemoryUsage;
extern bool SC__Options_PrintStages;
extern bool SC__Options_ProjectIsLibrary;
extern bool SC__Options_ProjectIsMiniLib;
extern bool SC__Options_Scripting;
extern bool SC__Options_SelfReplacement;
extern bool SC__Options_Silent;
extern bool SC__Options_SingleCppOutput;
extern JB_String* SC__Options_SingleFileInput;
extern bool SC__Options_StripNames;
extern bool SC__Options_TargetDebug;
extern JB_String* SC__Options_Variant;
extern bool SC__Options_Warnings;
extern Array* SC__PackMaker_LibFuncs;
extern Array* SC__PackMaker_LibGlobs;
extern int SC__PackMaker_LibGlobSize;
extern int SC__PackMaker_PackFuncIndex;
extern Array* SC__PackMaker_PackFuncs;
extern Array* SC__PackMaker_PackGlobs;
extern int SC__PackMaker_PackGlobSize;
extern HairyMan SC__PackMaker_PackSaved;
extern Array* SC__PackMaker_PackStrings;
#define JB__Tk__DotInsertAllow JB__.Tk__DotInsertAllow
#define JB__Tk__EndOfLineMarker JB__.Tk__EndOfLineMarker
#define JB__Tk__ErrorNames JB__.Tk__ErrorNames
#define JB__Tk__StopBars JB__.Tk__StopBars
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
#define JB__Tk_Splitter JB__.Tk_Splitter
#define JB__Tk_Using JB__.Tk_Using
#define kJB__PicoNoise_All ((int)15)
#define kJB__PicoNoise_Debug ((int)3)
#define kJB__PicoNoise_DebugChild ((int)1)
#define kJB__PicoNoise_DebugParent ((int)2)
#define kJB__PicoNoise_Events ((int)12)
#define kJB__PicoNoise_EventsChild ((int)4)
#define kJB__PicoNoise_EventsParent ((int)8)
#define JB__Platform_Logger_ JB__.Platform_Logger_
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
#define kSC__SCTasks_AlreadyDone ((int)12345)
extern Message* SC__SCTasks_TaskMacro;
extern Message* SC__SCTasks_tmp;
extern Dictionary* SC__Errors_IgnoredBranches;
extern Dictionary* SC__SC_Targets_Items;
extern int SC__SourceMap_LastLength;
extern FastString* SC__SourceMap_Positions;
extern Array* SC__Crkt_CppStrings;
extern Dictionary* SC__Crkt_Table2;
extern int SC__Crkt_TotalSize;
extern Array* SC__StructStuff_FixMe;
extern Dictionary* SC__TextAssembler_Labels;
extern Array* SC__Ext_Cleanup;
extern int SC__Ext_CompilingLibFiles;
extern JB_String* SC__Ext_CppCompilerPath;
extern Array* SC__Ext_FoundObjects;
extern Date SC__Ext_LatestLibDate;
extern Array* SC__VM_Builder_Appended;
extern Message* SC__VM_Builder_arms;
extern Message* SC__VM_Builder_ASM_Datatype;
extern Message* SC__VM_Builder_ASMFile;
extern Message* SC__VM_Builder_double_rizzler;
extern Message* SC__VM_Builder_dt_prm;
extern FastString* SC__VM_Builder_FatFile;
extern FastString* SC__VM_Builder_form_h;
extern uint SC__VM_Builder_FreeMultiASM;
extern Message* SC__VM_Builder_gyatt;
extern Message* SC__VM_Builder_icecream;
extern Message* SC__VM_Builder_legs;
extern Message* SC__VM_Builder_ModuleArg;
extern Array* SC__VM_Builder_NameList;
extern byte SC__VM_Builder_NormalPos;
extern Message* SC__VM_Builder_ohio;
extern Message* SC__VM_Builder_Ooof;
extern JB_String* SC__VM_Builder_parent;
extern Array* SC__VM_Builder_rdz;
extern Message* SC__VM_Builder_rizzler;
extern Message* SC__VM_Builder_skibidy;
extern Message* SC__VM_Builder_TempDests;
extern int SC__VM_Builder_Total;
extern Message* SC__VM_Builder_Ugh;
extern byte SC__VM_Builder_XType;
extern Dictionary* SC_ClassOrModuleLinkage;
extern Dictionary* SC_ClsCollectTable;
extern Dictionary* SC_CodePointTable;
#define kJB_codesign_native ((JB_StringC*)JB_LUB[2407])
extern Dictionary* SC_CppRefTable;
extern JB_ErrorReceiver* SC_ErrorDelayer;
extern int SC_ExportPosFails;
extern FP_ExprResolver SC_ExprFuncs[64];
extern SCDecl* SC_FalseBool;
extern fn_asm SC_fn_asm_table[64];
extern FastString* SC_fs_tmp_num;
extern Dictionary* SC_FuncLinkageTable;
extern Dictionary* SC_FuncPreReader;
#define kJB_kActualTypecasts ((int)-16545)
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
#define kJB_kSimpleMatch ((int)4194304)
#define kJB_kSuperClassMatch ((int)16777216)
#define kJB_kTypeCastAssigns ((int)64)
#define kJB_kTypeCastBothWays ((int)16)
#define kJB_kTypeCastDescribeErrors ((int)256)
#define kJB_kTypeCastFalse ((int)0)
#define kJB_kTypeCastForParams ((int)16384)
#define kJB_kTypeCastForRelSet ((int)8192)
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
#define kJB_kUsingStr ((JB_StringC*)JB_LUB[2408])
#define kJB_kVoidPtrMatch ((int)20971520)
#define JB_Random JB__.Random
#define JB_RandomShared JB__.RandomShared
extern Message* SC_ReturnSelfEqNil;
extern Dictionary* SC_RootCollectTable;
extern JB_Dylib SC_SelfLib;
#define JB_StdErr JB__.StdErr
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
#define kJB_Syxmax ((Syntax)56)
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
#define kJB_SyxURL ((Syntax)48)
#define kJB_SyxXAtt ((Syntax)49)
#define kJB_SyxXCDT ((Syntax)53)
#define kJB_SyxXCom ((Syntax)52)
#define kJB_SyxXDTD ((Syntax)55)
#define kJB_SyxXML ((Syntax)50)
#define kJB_SyxXPI ((Syntax)51)
#define kJB_SyxXTxt ((Syntax)54)
#define kJB_SyxYoda ((Syntax)44)
extern SCDecl* SC_TrueBool;
extern SCClass* SC_TypeArray;
extern SCClass* SC_TypeBool;
extern SCClass* SC_TypeByte;
extern SCClass* SC_TypeChar;
extern SCClass* SC_TypeCodePoint;
extern SCClass* SC_TypeDate;
extern SCClass* SC_TypeDictionary;
extern SCClass* SC_TypeDuration;
extern SCClass* SC_Typefloat;
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
#define kJB__zalgo_down ((JB_StringC*)JB_LUB[2406])
#define kJB__zalgo_mid ((JB_StringC*)JB_LUB[2405])
#define JB__zalgo_R JB__.zalgo_R
#define kJB__zalgo_up ((JB_StringC*)JB_LUB[2404])
#define kJB__byte_max ((byte)255)
#define kJB__byte_min ((byte)0)
#define kJB__int_Max ((int)2147483647)
#define kJB__int_Min ((int)2147483648)
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
#define kSC__ASM_ADAK ((ASM)46)
#define kSC__ASM_ADD ((ASM)48)
#define kSC__ASM_ADDB ((ASM)44)
#define kSC__ASM_ADDK ((ASM)45)
#define kSC__ASM_ADDM ((ASM)55)
#define kSC__ASM_AFNC ((ASM)40)
#define kSC__ASM_ALLO ((ASM)41)
#define kSC__ASM_BAND ((ASM)64)
#define kSC__ASM_BANK ((ASM)68)
#define kSC__ASM_BFLG ((ASM)59)
#define kSC__ASM_BFLS ((ASM)60)
#define kSC__ASM_BLSH ((ASM)63)
#define kSC__ASM_BNOT ((ASM)67)
#define kSC__ASM_BORK ((ASM)69)
#define kSC__ASM_BORR ((ASM)65)
#define kSC__ASM_BRSH ((ASM)62)
#define kSC__ASM_BRSS ((ASM)61)
#define kSC__ASM_BSTT ((ASM)151)
#define kSC__ASM_BXOR ((ASM)66)
#define kSC__ASM_BXRK ((ASM)70)
#define kSC__ASM_CMPF ((ASM)74)
#define kSC__ASM_CMPI ((ASM)73)
#define kSC__ASM_CNTC ((ASM)109)
#define kSC__ASM_CNTD ((ASM)110)
#define kSC__ASM_CONV ((ASM)36)
#define kSC__ASM_DIV ((ASM)51)
#define kSC__ASM_DIV2 ((ASM)52)
#define kSC__ASM_DIVS ((ASM)57)
#define kSC__ASM_DUMB ((ASM)34)
extern ASM_Encoder SC__ASM_Encoders[256];
#define kSC__ASM_EQUL ((ASM)71)
#define kSC__ASM_FABS ((ASM)156)
#define kSC__ASM_FADD ((ASM)112)
#define kSC__ASM_FADK ((ASM)113)
#define kSC__ASM_FCLM ((ASM)120)
#define kSC__ASM_FCOS ((ASM)167)
#define kSC__ASM_FDIV ((ASM)116)
#define kSC__ASM_FEET ((ASM)37)
#define kSC__ASM_FEXP ((ASM)159)
#define kSC__ASM_FFLR ((ASM)153)
#define kSC__ASM_FFRC ((ASM)152)
#define kSC__ASM_FLG2 ((ASM)162)
#define kSC__ASM_FLNG ((ASM)155)
#define kSC__ASM_FLOG ((ASM)160)
#define kSC__ASM_FMAX ((ASM)118)
#define kSC__ASM_FMIN ((ASM)119)
#define kSC__ASM_FMIX ((ASM)170)
#define kSC__ASM_FMLK ((ASM)115)
#define kSC__ASM_FMOD ((ASM)117)
#define kSC__ASM_FMUL ((ASM)114)
#define kSC__ASM_FNAT ((ASM)165)
#define kSC__ASM_FNC ((ASM)24)
#define kSC__ASM_FNC3 ((ASM)25)
#define kSC__ASM_FNCX ((ASM)26)
#define kSC__ASM_FNCX3 ((ASM)27)
#define kSC__ASM_FNIS ((ASM)163)
extern ASM_Encoder SC__ASM_Forms[128];
#define kSC__ASM_FPOW ((ASM)157)
#define kSC__ASM_FRND ((ASM)154)
#define kSC__ASM_FSGN ((ASM)169)
#define kSC__ASM_FSIN ((ASM)166)
#define kSC__ASM_FSMS ((ASM)171)
#define kSC__ASM_FSOC ((ASM)164)
#define kSC__ASM_FSQT ((ASM)158)
#define kSC__ASM_FTAN ((ASM)168)
#define kSC__ASM_FXNF ((ASM)173)
#define kSC__ASM_FXNN ((ASM)172)
#define kSC__ASM_FXP2 ((ASM)161)
#define kSC__ASM_GOBJ ((ASM)94)
#define kSC__ASM_GRAB ((ASM)38)
#define kSC__ASM_GTAB ((ASM)95)
#define kSC__ASM_HALT ((ASM)0)
#define kSC__ASM_ICLM ((ASM)53)
#define kSC__ASM_JBAN ((ASM)85)
#define kSC__ASM_JBOR ((ASM)84)
#define kSC__ASM_JMKE ((ASM)82)
#define kSC__ASM_JMKL ((ASM)81)
#define kSC__ASM_JMKM ((ASM)80)
#define kSC__ASM_JMKN ((ASM)83)
#define kSC__ASM_JMPE ((ASM)78)
#define kSC__ASM_JMPF ((ASM)77)
#define kSC__ASM_JMPI ((ASM)76)
#define kSC__ASM_JMPN ((ASM)79)
#define kSC__ASM_JUMP ((ASM)75)
#define kSC__ASM_KNSR ((ASM)42)
#define kSC__ASM_KNST ((ASM)43)
#define kSC__ASM_KNST2 ((ASM)4)
#define kSC__ASM_KNST3 ((ASM)5)
#define kSC__ASM_LUPD ((ASM)87)
#define kSC__ASM_LUPU ((ASM)86)
#define kSC__ASM_MARK ((ASM)255)
#define kSC__ASM_MUL ((ASM)50)
#define kSC__ASM_MULK ((ASM)47)
#define kSC__ASM_MULS ((ASM)58)
extern byte SC__ASM_NoisyASM;
#define kSC__ASM_NOOP ((ASM)33)
#define kSC__ASM_QADD ((ASM)134)
#define kSC__ASM_QADK ((ASM)136)
#define kSC__ASM_QAND ((ASM)146)
#define kSC__ASM_QCLM ((ASM)139)
#define kSC__ASM_QCNV ((ASM)150)
#define kSC__ASM_QDIV ((ASM)138)
#define kSC__ASM_QFLG ((ASM)141)
#define kSC__ASM_QFLS ((ASM)142)
#define kSC__ASM_QINC ((ASM)140)
#define kSC__ASM_QLSH ((ASM)145)
#define kSC__ASM_QMUL ((ASM)137)
#define kSC__ASM_QNOT ((ASM)149)
#define kSC__ASM_QORR ((ASM)148)
#define kSC__ASM_QRSH ((ASM)144)
#define kSC__ASM_QRSS ((ASM)143)
#define kSC__ASM_QSUB ((ASM)135)
#define kSC__ASM_QXOR ((ASM)147)
#define kSC__ASM_RALO ((ASM)92)
#define kSC__ASM_RD16 ((ASM)103)
#define kSC__ASM_RD1S ((ASM)97)
#define kSC__ASM_RD1U ((ASM)96)
#define kSC__ASM_RD2S ((ASM)99)
#define kSC__ASM_RD2U ((ASM)98)
#define kSC__ASM_RD4S ((ASM)101)
#define kSC__ASM_RD4U ((ASM)100)
#define kSC__ASM_RD8U ((ASM)102)
#define kSC__ASM_RET ((ASM)39)
#define kSC__ASM_RFRD ((ASM)91)
#define kSC__ASM_RFRT ((ASM)93)
#define kSC__ASM_RFST ((ASM)89)
#define kSC__ASM_RFUN ((ASM)88)
#define kSC__ASM_RFWR ((ASM)90)
#define kSC__ASM_SUB ((ASM)49)
#define kSC__ASM_SUBM ((ASM)56)
#define kSC__ASM_TAIL ((ASM)2)
#define kSC__ASM_TERN ((ASM)72)
#define kSC__ASM_TIME ((ASM)35)
#define kSC__ASM_TRAP ((ASM)32)
extern Dictionary* SC__ASM_Types_Dict;
#define kSC__ASM_UCLM ((ASM)54)
#define kSC__ASM_VABS ((ASM)178)
#define kSC__ASM_VADD ((ASM)126)
#define kSC__ASM_VADK ((ASM)127)
#define kSC__ASM_VBLD ((ASM)123)
#define kSC__ASM_VCLM ((ASM)192)
#define kSC__ASM_VCOS ((ASM)189)
#define kSC__ASM_VCRS ((ASM)196)
#define kSC__ASM_VDIV ((ASM)130)
#define kSC__ASM_VDOT ((ASM)195)
#define kSC__ASM_VEXP ((ASM)181)
#define kSC__ASM_VFLR ((ASM)175)
#define kSC__ASM_VFRC ((ASM)174)
#define kSC__ASM_VGET ((ASM)121)
#define kSC__ASM_VLG2 ((ASM)184)
#define kSC__ASM_VLNG ((ASM)177)
#define kSC__ASM_VLOG ((ASM)182)
#define kSC__ASM_VMAX ((ASM)132)
#define kSC__ASM_VMIN ((ASM)133)
#define kSC__ASM_VMIX ((ASM)193)
#define kSC__ASM_VMLK ((ASM)129)
#define kSC__ASM_VMOD ((ASM)131)
#define kSC__ASM_VMOV ((ASM)125)
#define kSC__ASM_VMUL ((ASM)128)
#define kSC__ASM_VNAT ((ASM)187)
#define kSC__ASM_VNIS ((ASM)185)
#define kSC__ASM_VPOW ((ASM)179)
#define kSC__ASM_VRFL ((ASM)197)
#define kSC__ASM_VRND ((ASM)176)
#define kSC__ASM_VSET ((ASM)122)
#define kSC__ASM_VSGN ((ASM)191)
#define kSC__ASM_VSIN ((ASM)188)
#define kSC__ASM_VSMS ((ASM)194)
#define kSC__ASM_VSOC ((ASM)186)
#define kSC__ASM_VSQT ((ASM)180)
#define kSC__ASM_VSUM ((ASM)198)
#define kSC__ASM_VSWZ ((ASM)124)
#define kSC__ASM_VTAN ((ASM)190)
#define kSC__ASM_VXP2 ((ASM)183)
#define kSC__ASM_WCPY ((ASM)111)
#define kSC__ASM_WR16 ((ASM)108)
#define kSC__ASM_WR1U ((ASM)104)
#define kSC__ASM_WR2U ((ASM)105)
#define kSC__ASM_WR4U ((ASM)106)
#define kSC__ASM_WR8U ((ASM)107)
#define kSC__Reg_AddrForceRequest ((ASMReg)274877906944)
#define kSC__Reg_AddrNeed ((ASMReg)962072674304)
#define kSC__Reg_AddrNoFiddle ((ASMReg)549755813888)
#define kSC__Reg_AddrRequest ((ASMReg)137438953472)
#define kSC__Reg_AllowNopDest ((ASMReg)4294967296)
#define kSC__Reg_AlreadyNegated ((ASMReg)131072)
#define kSC__Reg_Alternate ((ASMReg)1048576)
#define kSC__Reg_BlockNop ((ASMReg)8589934592)
#define kSC__Reg_CondAnswer ((ASMReg)1073741824)
#define kSC__Reg_CondRequest ((ASMReg)536870912)
#define kSC__Reg_Const ((ASMReg)68719476736)
#define kSC__Reg_ConstRequest ((ASMReg)268435456)
#define kSC__Reg_ContainsAddr ((ASMReg)67108864)
#define kSC__Reg_DebugVars ((ASMReg)8388608)
#define kSC__Reg_Discard ((ASMReg)262144)
#define kSC__Reg_Exit ((ASMReg)3298534883328)
#define kSC__Reg_ExitAtAll ((ASMReg)2199023255552)
#define kSC__Reg_ExitFunction ((ASMReg)1099511627776)
#define kSC__Reg_FlagsToRemove ((ASMReg)68719738880)
#define kSC__Reg_ForceInto ((ASMReg)16777216)
#define kSC__Reg_GlobalMemory ((ASMReg)17179869184)
#define kSC__Reg_Negate ((ASMReg)65536)
#define kSC__Reg_NewlyDeclared ((ASMReg)4194304)
#define kSC__Reg_NoScale ((ASMReg)33554432)
#define kSC__Reg_OKAsTemp ((ASMReg)2147483648)
#define kSC__Reg_Param ((ASMReg)524288)
#define kSC__Reg_PreferEqul ((ASMReg)34359738368)
#define kSC__Reg_Set ((ASMReg)2097152)
#define kSC__Reg_SetAlways ((ASMReg)136314880)
#define kSC__Reg_Subtract ((ASMReg)1048576)
#define kSC__Reg_Temp ((ASMReg)1024)
#define kSC__Reg_Textual ((ASMReg)134217728)
#define kSC__Reg_Zero ((ASMReg)68720001080)
#define kSC__ASMType_IncrAfter ((int)2)
#define kSC__ASMType_IncrBefore ((int)0)
#define kSC__ASMType_kContinue ((ASMType)52)
#define kSC__ASMType_kDebugger ((ASMType)60)
#define kSC__ASMType_kExit ((ASMType)53)
#define kSC__ASMType_kFail ((ASMType)63)
#define kSC__ASMType_kIf ((ASMType)50)
#define kSC__ASMType_kIgnore ((ASMType)59)
#define kSC__ASMType_kRefCount ((ASMType)61)
#define kSC__ASMType_kRejoin ((ASMType)55)
#define kSC__ASMType_kReturn ((ASMType)54)
#define kSC__ASMType_kSetRel ((ASMType)58)
#define kSC__ASMType_kStatExpr ((ASMType)49)
#define kSC__ASMType_kSwap ((ASMType)56)
#define kSC__ASMType_kSwizzle ((ASMType)57)
#define kSC__ASMType_kTern ((ASMType)48)
#define kSC__ASMType_kUnusedFirst ((ASMType)47)
#define kSC__ASMType_kWhile ((ASMType)51)
extern ASM SC__ASMType_ReadASM[10];
extern ASM SC__ASMType_WriteASM[5];
#define kJB__CharSet_AfterDot ((CharSet)344)
#define kJB__CharSet_AfterStatement ((CharSet)1368)
#define kJB__CharSet_AfterTmp ((CharSet)1024)
#define kJB__CharSet_Colon ((CharSet)64)
#define kJB__CharSet_CommaSlash ((CharSet)256)
#define kJB__CharSet_DotDash ((CharSet)128)
#define kJB__CharSet_EditorSeparators ((CharSet)2048)
#define kJB__CharSet_EditorSplitter ((CharSet)2392)
#define kJB__CharSet_fAfterTmp ((int)10)
#define kJB__CharSet_fColon ((int)6)
#define kJB__CharSet_fCommaSlash ((int)8)
#define kJB__CharSet_fDotDash ((int)7)
#define kJB__CharSet_fEditorSeparators ((int)11)
#define kJB__CharSet_fHSpace ((int)4)
#define kJB__CharSet_fInvalid ((int)0)
#define kJB__CharSet_fLine ((int)3)
#define kJB__CharSet_fLower ((int)14)
#define kJB__CharSet_fNull ((int)1)
#define kJB__CharSet_fNumber ((int)12)
#define kJB__CharSet_fRemainingPunct ((int)9)
#define kJB__CharSet_fUnderscore ((int)5)
#define kJB__CharSet_fUnicode ((int)15)
#define kJB__CharSet_fUnprintable ((int)2)
#define kJB__CharSet_fUpper ((int)13)
#define kJB__CharSet_HSpace ((CharSet)16)
#define kJB__CharSet_Invalid ((CharSet)1)
#define kJB__CharSet_LettersOnly ((CharSet)57344)
#define kJB__CharSet_LettersUnderScore ((CharSet)57376)
#define kJB__CharSet_Line ((CharSet)8)
#define kJB__CharSet_Lower ((CharSet)16384)
#define kJB__CharSet_NameMid ((CharSet)61472)
#define kJB__CharSet_Null ((CharSet)2)
#define kJB__CharSet_Number ((CharSet)4096)
#define JB__CharSet_Props JB__.CharSet_Props
#define kJB__CharSet_RemainingPunct ((CharSet)512)
#define kJB__CharSet_SafeInC ((CharSet)28704)
#define kJB__CharSet_Trim ((CharSet)26)
#define kJB__CharSet_Underscore ((CharSet)32)
#define kJB__CharSet_Unicode ((CharSet)32768)
#define kJB__CharSet_Unprintable ((CharSet)4)
#define kJB__CharSet_Upper ((CharSet)8192)
#define kJB__CharSet_White ((CharSet)24)
#define kJB__CharSet_XMLNameMid ((CharSet)61664)
#define kSC__ClassInfo_Banned ((ClassInfo)64)
#define kSC__ClassInfo_Builtin ((ClassInfo)2048)
#define kSC__ClassInfo_ContainsParentClass ((ClassInfo)1)
#define kSC__ClassInfo_DefaultsToReal ((ClassInfo)256)
#define kSC__ClassInfo_Flags ((ClassInfo)16384)
#define kSC__ClassInfo_HasEqualsFunc ((ClassInfo)4)
#define kSC__ClassInfo_HasNilChecker ((ClassInfo)128)
#define kSC__ClassInfo_HasSubClass ((ClassInfo)8)
#define kSC__ClassInfo_IgnoreContainedSelf ((ClassInfo)2)
#define kSC__ClassInfo_NoEarlyFree ((ClassInfo)16)
#define kSC__ClassInfo_NumericReduction ((ClassInfo)24576)
#define kSC__ClassInfo_SortsProperties ((ClassInfo)4096)
#define kSC__ClassInfo_Stateful ((ClassInfo)1024)
#define kSC__ClassInfo_Stateless ((ClassInfo)512)
#define kSC__ClassInfo_Symbol ((ClassInfo)8192)
#define kSC__ClassInfo_TreatAsBaseType ((ClassInfo)32)
#define kSC__CompilerStage_CppExport ((CompilerStage)7)
#define kSC__CompilerStage_Hungry ((CompilerStage)5)
#define kSC__CompilerStage_Import ((CompilerStage)1)
#define kSC__CompilerStage_Initialising ((CompilerStage)0)
#define kSC__CompilerStage_NilChecking ((CompilerStage)3)
#define kSC__CompilerStage_Packing ((CompilerStage)6)
#define kSC__CompilerStage_RefCounts ((CompilerStage)4)
#define kSC__CompilerStage_Transform ((CompilerStage)2)
#define kJB__ControlClipMode_Debug ((int)4)
#define kJB__ControlClipMode_SlideBackInParent ((int)1)
#define kJB__ControlClipMode_SlideBackInWindow ((int)2)
#define kJB__CL1_After ((ControlPoint)6)
#define kJB__CL1_Before ((ControlPoint)4)
#define kJB__CL1_Centered ((ControlPoint)7)
#define kJB__CL1_High ((ControlPoint)2)
#define kJB__CL1_Length ((ControlPoint)10)
#define kJB__CL1_Low ((ControlPoint)0)
#define kJB__TC__voidptr ((DataTypeCode)624)
#define kJB__TC_bool ((DataTypeCode)256)
#define kJB__TC_byte ((DataTypeCode)72)
#define kJB__TC_Byte2 ((DataTypeCode)73)
#define kJB__TC_Byte3 ((DataTypeCode)74)
#define kJB__TC_Byte4 ((DataTypeCode)75)
#define kJB__TC_char ((DataTypeCode)8)
#define kJB__TC_cstring ((DataTypeCode)624)
#define kJB__TC_Double ((DataTypeCode)184)
#define kJB__TC_f16 ((DataTypeCode)152)
#define kJB__TC_f64 ((DataTypeCode)184)
#define kJB__TC_Failed ((DataTypeCode)192)
#define kJB__TC_Float ((DataTypeCode)168)
#define kJB__TC_Float16 ((DataTypeCode)152)
#define kJB__TC_Floating ((DataTypeCode)128)
#define kJB__TC_HFloat ((DataTypeCode)152)
#define kJB__TC_Int ((DataTypeCode)40)
#define kJB__TC_int16 ((DataTypeCode)24)
#define kJB__TC_int64 ((DataTypeCode)56)
#define kJB__TC_int8 ((DataTypeCode)8)
#define kJB__TC_iVec2 ((DataTypeCode)41)
#define kJB__TC_iVec3 ((DataTypeCode)42)
#define kJB__TC_iVec4 ((DataTypeCode)43)
#define kJB__TC_Numeric ((DataTypeCode)8)
#define kJB__TC_Pointer ((DataTypeCode)512)
#define kJB__TC_PossibleBits ((DataTypeCode)1023)
#define kJB__TC_s16 ((DataTypeCode)24)
#define kJB__TC_s16x2 ((DataTypeCode)25)
#define kJB__TC_s16x3 ((DataTypeCode)26)
#define kJB__TC_s16x4 ((DataTypeCode)27)
#define kJB__TC_s64 ((DataTypeCode)56)
#define kJB__TC_SByte ((DataTypeCode)8)
#define kJB__TC_SByte2 ((DataTypeCode)9)
#define kJB__TC_SByte3 ((DataTypeCode)10)
#define kJB__TC_SByte4 ((DataTypeCode)11)
#define JB__TC_Types_Dict JB__.TC_Types_Dict
#define kJB__TC_u16 ((DataTypeCode)88)
#define kJB__TC_u32 ((DataTypeCode)104)
#define kJB__TC_u64 ((DataTypeCode)120)
#define kJB__TC_UInt ((DataTypeCode)104)
#define kJB__TC_uint16 ((DataTypeCode)88)
#define kJB__TC_uint64 ((DataTypeCode)120)
#define kJB__TC_uint8 ((DataTypeCode)72)
#define kJB__TC_Unsigned ((DataTypeCode)64)
#define kJB__TC_Vec2 ((DataTypeCode)169)
#define kJB__TC_Vec3 ((DataTypeCode)170)
#define kJB__TC_Vec4 ((DataTypeCode)171)
#define kJB__Date_Highest ((int64)9223372036854775807)
#define kJB__Date_kOneStep (0.000015258789f)
#define kJB__Date_kSecondsPerDay ((int)86400)
#define kJB__Date_kSecondsPerMonthApprox ((int)2628000)
#define kJB__Date_kSecondsPerWeek ((int)604800)
#define kSC__DeclMode_Always ((DeclMode)64)
#define kSC__DeclMode_FuncParam ((DeclMode)4)
#define kSC__DeclMode_FunctionBody ((DeclMode)8)
#define kSC__DeclMode_Globals ((DeclMode)1)
#define kSC__DeclMode_Properties ((DeclMode)3)
#define kSC__DeclMode_Proto ((DeclMode)16)
#define kSC__DeclMode_ProtoParam ((DeclMode)20)
#define kSC__DeclMode_TypeCast ((DeclMode)32)
#define kSC__DotUseType_Property ((DotUseType)1)
#define kJB__ErrorFlags_DontStrip ((ErrorFlags)1)
#define kJB__ErrorFlags_Keep ((int)0)
#define kJB__ErrorFlags_Parse ((ErrorFlags)4)
#define kJB__ErrorFlags_PreferNoRenderPath ((ErrorFlags)2)
#define kJB__ErrorFlags_PrintAndKeep ((int)1)
#define kJB__ErrorFlags_PrintAndRemove ((int)2)
#define JB__ErrorSeverity__ErrorNames JB__.ErrorSeverity__ErrorNames
#define kJB__ErrorSeverity_Critical ((ErrorSeverity)5)
#define kJB__ErrorSeverity_Error ((ErrorSeverity)4)
#define kJB__ErrorSeverity_Hint ((ErrorSeverity)1)
#define kJB__ErrorSeverity_MaxError ((ErrorSeverity)6)
#define kJB__ErrorSeverity_OK ((ErrorSeverity)0)
#define kJB__ErrorSeverity_Problem ((ErrorSeverity)3)
#define kJB__ErrorSeverity_Warning ((ErrorSeverity)2)
#define kJB__ExitCode_EINPROGRESS ((int)36)
#define kJB__FailableInt_Fail ((int)2147483648)
#define kJB__FileDes_StdErr ((FileDes)2)
#define kJB__FileDes_StdIn ((FileDes)0)
#define kJB__FileDes_StdOut ((FileDes)1)
#define kJB__FileMode_CanExec ((FileMode)73)
#define kJB__FileMode_Data ((FileMode)416)
#define kJB__FileMode_Group ((FileMode)56)
#define kJB__FileMode_Other ((FileMode)7)
#define kJB__FileMode_Owner ((FileMode)448)
#define kJB__FileMode_Process ((FileMode)493)
#define kSC__FunctionType_AlreadyExported ((FunctionType)8192)
#define kSC__FunctionType_API ((FunctionType)8388608)
#define kSC__FunctionType_Behaviour ((FunctionType)1024)
#define kSC__FunctionType_CantInline ((FunctionType)131072)
#define kSC__FunctionType_ConOrDes ((FunctionType)3)
#define kSC__FunctionType_Constructor ((FunctionType)1)
#define kSC__FunctionType_Cpp ((FunctionType)134217728)
#define kSC__FunctionType_Destructor ((FunctionType)2)
#define kSC__FunctionType_Disabled ((FunctionType)2097152)
#define kSC__FunctionType_EmptyConstructor ((FunctionType)256)
#define kSC__FunctionType_ExpectsRealVars ((FunctionType)4096)
#define kSC__FunctionType_ExternalLib ((FunctionType)65536)
#define kSC__FunctionType_FlowDisabled ((FunctionType)32768)
#define kSC__FunctionType_HidesProperties ((FunctionType)33554432)
#define kSC__FunctionType_InitFunc ((FunctionType)64)
#define kSC__FunctionType_Killer ((FunctionType)1048576)
#define kSC__FunctionType_LinkInline ((FunctionType)524288)
#define kSC__FunctionType_NewNew ((FunctionType)2048)
#define kSC__FunctionType_NewStruct ((FunctionType)8)
#define kSC__FunctionType_NoExport ((FunctionType)2621504)
#define kSC__FunctionType_NotRefCounted ((FunctionType)4194304)
#define kSC__FunctionType_NumberCreator ((FunctionType)16)
#define kSC__FunctionType_OptInline ((FunctionType)262144)
#define kSC__FunctionType_Recursive ((FunctionType)128)
#define kSC__FunctionType_Reffer ((FunctionType)4)
#define kSC__FunctionType_Render ((FunctionType)16384)
#define kSC__FunctionType_Stateless ((FunctionType)16777216)
#define kSC__FunctionType_TypeTest ((FunctionType)32)
#define kSC__FunctionType_UsedByASM ((FunctionType)268435456)
#define kSC__FunctionType_VirtualCaller ((FunctionType)512)
#define kSC__FunctionType_Wrapper ((FunctionType)67108864)
#define kJB__MaybeBool_False ((MaybeBool)0)
#define kJB__MaybeBool_MaybeFalse ((MaybeBool)8)
#define kJB__MaybeBool_MaybeTrue ((MaybeBool)9)
#define kJB__MaybeBool_True ((MaybeBool)1)
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
#define kJB__MsgParseFlags_Inserted ((int)2048)
#define kJB__MsgParseFlags_MacroInserted ((int)6144)
#define kJB__MsgParseFlags_MacroMade ((int)4096)
#define kJB__MsgParseFlags_SplitHere ((int)8192)
#define kJB__MsgParseFlags_Style2 ((int)16384)
#define kSC__khalai_Active ((NilCheckMode)3)
#define kSC__khalai_AllowRegisterAddr ((NilCheckMode)512)
#define kSC__khalai_And ((NilCheckMode)8)
#define kSC__khalai_Assigns ((NilCheckMode)128)
#define kSC__khalai_Disappears ((NilCheckMode)64)
#define kSC__khalai_ForBools ((NilCheckMode)256)
#define kSC__khalai_IfNeg ((NilCheckMode)769)
#define kSC__khalai_IfPos ((NilCheckMode)770)
#define kSC__khalai_Negative ((NilCheckMode)1)
#define kSC__khalai_Nothing ((NilCheckMode)0)
#define kSC__khalai_Positive ((NilCheckMode)2)
#define kSC__khalai_Reversed ((NilCheckMode)16)
#define kSC__khalai_Soft ((NilCheckMode)4)
#define kSC__khalai_While ((NilCheckMode)32)
#define kSC__khalai_WhileNeg ((NilCheckMode)801)
#define kSC__khalai_WhilePos ((NilCheckMode)802)
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
#define kSC__NilState_Stated ((NilState)4)
#define kSC__NilState_TrueValue ((NilState)32)
#define kSC__OpMode_Addition ((OpMode)16)
#define kSC__OpMode_AND ((OpMode)1048576)
#define kSC__OpMode_AndOr ((OpMode)1572864)
#define kSC__OpMode_Assigns ((OpMode)2)
#define kSC__OpMode_Bit ((OpMode)4)
#define kSC__OpMode_CaseAware ((OpMode)4194304)
#define kSC__OpMode_Compare ((OpMode)1)
#define kSC__OpMode_Comparison ((OpMode)512)
#define kSC__OpMode_CompOrSet ((OpMode)3)
#define kSC__OpMode_Custom ((OpMode)2097152)
#define kSC__OpMode_CustomOnFloat ((OpMode)8388608)
#define kSC__OpMode_EqualOrNot ((OpMode)256)
#define kSC__OpMode_ExactEquals ((OpMode)16769)
#define kSC__OpMode_ExactlyEquals ((OpMode)128)
#define kSC__OpMode_ExactNotEquals ((OpMode)16641)
#define kSC__OpMode_Less ((OpMode)2048)
#define kSC__OpMode_LessOrEqual ((OpMode)8192)
#define kSC__OpMode_LoseBits ((OpMode)262144)
#define kSC__OpMode_MakesSigned ((OpMode)64)
#define kSC__OpMode_Math ((OpMode)8)
#define kSC__OpMode_MathLike ((OpMode)12)
#define kSC__OpMode_More ((OpMode)1024)
#define kSC__OpMode_MoreOrEqual ((OpMode)4096)
#define kSC__OpMode_Multiply ((OpMode)32768)
#define kSC__OpMode_NilTest ((OpMode)16384)
#define kSC__OpMode_NoExtraBits ((OpMode)131072)
#define kSC__OpMode_OR ((OpMode)524288)
#define kSC__OpMode_RightShift ((OpMode)131104)
#define kSC__OpMode_SameOrLessBits ((OpMode)393216)
#define kSC__OpMode_ShiftOnly ((OpMode)32)
#define kSC__OpMode_Subtraction ((OpMode)80)
#define kSC__OpMode_SyntaxIs ((OpMode)65536)
#define kJB__PIDM_CaptureAll ((ProcessMode)0)
#define kJB__PIDM_MsgPassing ((ProcessMode)1)
#define kJB__PIDM_OwnGroup ((ProcessMode)128)
#define kJB__PIDM_PassThru ((ProcessMode)40)
#define kJB__PIDM_Silence ((ProcessMode)20)
#define kJB__PIDM_StdErrPassThru ((ProcessMode)32)
#define kJB__PIDM_StdErrSilence ((ProcessMode)16)
#define kJB__PIDM_StdOutPassThru ((ProcessMode)8)
#define kJB__PIDM_StdOutSilence ((ProcessMode)4)
#define kSC__SCBlockage_Bits ((int)7)
#define kSC__SCBlockage_Continue ((int)1)
#define kSC__SCBlockage_Exit ((int)2)
#define kSC__SCBlockage_Quit ((int)4)
#define kSC__SCBlockage_Return ((int)4)
#define kSC__SCDeclInfo_Altered ((SCDeclInfo)65536)
#define kSC__SCDeclInfo_AlteredBranchLike ((SCDeclInfo)393216)
#define kSC__SCDeclInfo_AlteredCopy ((SCDeclInfo)983040)
#define kSC__SCDeclInfo_AlteredInBranch ((SCDeclInfo)131072)
#define kSC__SCDeclInfo_AlteredInLoop ((SCDeclInfo)262144)
#define kSC__SCDeclInfo_AlteredOrRef ((SCDeclInfo)1114112)
#define kSC__SCDeclInfo_AlteredParamObject ((SCDeclInfo)524288)
#define kSC__SCDeclInfo_API ((SCDeclInfo)128)
#define kSC__SCDeclInfo_ASMReached ((SCDeclInfo)1073741824)
#define kSC__SCDeclInfo_Body ((SCDeclInfo)4096)
#define kSC__SCDeclInfo_Borrowed ((SCDeclInfo)1)
#define kSC__SCDeclInfo_ClassObj ((SCDeclInfo)256)
#define kSC__SCDeclInfo_CompilerCreated ((SCDeclInfo)512)
#define kSC__SCDeclInfo_Const ((SCDeclInfo)8)
#define kSC__SCDeclInfo_DclCopied ((SCDeclInfo)103074)
#define kSC__SCDeclInfo_DirectNumber ((SCDeclInfo)4)
#define kSC__SCDeclInfo_Global ((SCDeclInfo)16384)
#define kSC__SCDeclInfo_Grabbed ((SCDeclInfo)33554432)
#define kSC__SCDeclInfo_IntendedAsReturn ((SCDeclInfo)2147483648)
#define kSC__SCDeclInfo_Library ((SCDeclInfo)536870912)
#define kSC__SCDeclInfo_Local ((SCDeclInfo)6144)
#define kSC__SCDeclInfo_NeedsClose ((SCDeclInfo)528384)
#define kSC__SCDeclInfo_NumberConst ((SCDeclInfo)12)
#define kSC__SCDeclInfo_Param ((SCDeclInfo)2048)
#define kSC__SCDeclInfo_PostIncremented ((SCDeclInfo)67108864)
#define kSC__SCDeclInfo_Property ((SCDeclInfo)8192)
#define kSC__SCDeclInfo_PropertyWasConstructed ((SCDeclInfo)1024)
#define kSC__SCDeclInfo_ReadFrom ((SCDeclInfo)8388608)
#define kSC__SCDeclInfo_Reference ((SCDeclInfo)1048576)
#define kSC__SCDeclInfo_Return ((SCDeclInfo)32768)
#define kSC__SCDeclInfo_ReturnedStruct ((SCDeclInfo)268435456)
#define kSC__SCDeclInfo_Self ((SCDeclInfo)4194304)
#define kSC__SCDeclInfo_SelfImplicit ((SCDeclInfo)4200448)
#define kSC__SCDeclInfo_SetTo ((SCDeclInfo)16777216)
#define kSC__SCDeclInfo_StayBorrowed ((SCDeclInfo)2)
#define kSC__SCDeclInfo_Task ((SCDeclInfo)2097152)
#define kSC__SCDeclInfo_Temp ((SCDeclInfo)4608)
#define kSC__SCDeclInfo_TypeImprove ((SCDeclInfo)64)
#define kSC__SCDeclInfo_UnknownConst ((SCDeclInfo)16)
#define kSC__SCDeclInfo_UpgradeableContained ((SCDeclInfo)32)
#define kSC__SCDeclInfo_VarThatGotReturned ((SCDeclInfo)134217728)
#define kSC__SCDeclInfo_VarType ((SCDeclInfo)30720)
extern int SC__SCNodeFindMode_aaa;
#define kSC__SCNodeFindMode_DontGoUp ((SCNodeFindMode)2)
#define kSC__SCNodeFindMode_ForClass ((SCNodeFindMode)8)
#define kSC__SCNodeFindMode_NoErrors ((SCNodeFindMode)1)
#define kSC__SCNodeFindMode_WantAType ((SCNodeFindMode)4)
#define kSC__SCNodeInfo_AllowLinkedLists ((int)4)
#define kSC__SCNodeInfo_EmbeddedOnly ((int)64)
#define kSC__SCNodeInfo_ExplicitExport ((int)1)
#define kSC__SCNodeInfo_InBuiltDataType ((int)8)
#define kSC__SCNodeInfo_LibOnly ((int)16)
#define kSC__SCNodeInfo_LibOnlyAll ((int)32)
#define kSC__SCNodeInfo_Visible ((int)2)
#define kSC__SCNodeType_DataType ((SCNodeType)1)
#define kSC__SCNodeType_Module ((SCNodeType)0)
#define kSC__SCNodeType_Object ((SCNodeType)4)
#define kSC__SCNodeType_Pointer ((SCNodeType)5)
#define kSC__SCNodeType_ProtoType ((SCNodeType)3)
#define kSC__SCNodeType_Struct ((SCNodeType)2)
#define JB__Syx_CurrFuncID_ JB__.Syx_CurrFuncID_
#define kJB__TaskState_Animation ((TaskState)16)
#define kJB__TaskState_Finished ((TaskState)64)
#define kJB__TaskState_HadErrors ((TaskState)8)
#define kJB__TaskState_Paused ((TaskState)2)
#define kJB__TaskState_Started ((TaskState)1)
#define kJB__TaskState_Successful ((TaskState)32)
#define kJB__TaskState_WaitsTillStart ((TaskState)4)
#define kJB__TerminalColor_Black ((TerminalColor)30)
#define kJB__TerminalColor_Blue ((TerminalColor)34)
#define kJB__TerminalColor_Bold ((JB_StringC*)JB_LUB[2400])
#define kJB__TerminalColor_Cyan ((TerminalColor)36)
#define JB__TerminalColor_Enabled JB__.TerminalColor_Enabled
#define kJB__TerminalColor_Error ((JB_StringC*)JB_LUB[2401])
#define kJB__TerminalColor_Good ((JB_StringC*)JB_LUB[2402])
#define kJB__TerminalColor_Green ((TerminalColor)32)
#define kJB__TerminalColor_Magenta ((TerminalColor)35)
#define kJB__TerminalColor_Normal ((JB_StringC*)JB_LUB[2399])
#define kJB__TerminalColor_Red ((TerminalColor)31)
#define kJB__TerminalColor_Underline ((JB_StringC*)JB_LUB[2402])
#define kJB__TerminalColor_Warn ((JB_StringC*)JB_LUB[2403])
#define kJB__TerminalColor_White ((TerminalColor)37)
#define kJB__TerminalColor_Yellow ((TerminalColor)33)
#define kSC__xC2xB5Param_Input ((MuParam)512)
#define kSC__xC2xB5Param_Jump ((MuParam)32)
#define kSC__xC2xB5Param_NoExpect ((MuParam)256)
#define kSC__xC2xB5Param_NonReg ((MuParam)96)
#define kSC__xC2xB5Param_Number ((MuParam)64)
#define kSC__xC2xB5Param_Output ((MuParam)1024)
#define kSC__xC2xB5Param_Signed ((MuParam)128)
extern LoopInfo SC__nil_Loops;
extern bool SC__nil_NewFuncsLoaded;
extern FP_NilTrackerFn SC__nil_NilTable[64];
extern byte SC__nil_OldPrint;
extern ArchonPurger SC__nil_T;
#define kJB__CakeVM_CanDebug ((int)32)
#define kJB__CakeVM_ErrOverFlow ((int)-2)
#define kJB__CakeVM_ErrStillInRange ((int)-1)
#define kJB__CakeVM_TrapTooFar ((int)16)
#define JB__MzSt_All JB__.MzSt_All
#define kJB__MzSt_Compression ((int)1)
#define kJB__MzSt_Decompression ((int)2)
#define kJB__dylib_Global ((int)8)
#define kJB__dylib_Lazy ((int)1)
#define kJB__dylib_Local ((int)4)
#define kJB__dylib_NoDelete ((int)128)
#define kJB__dylib_NoLoad ((int)16)
#define kJB__dylib_Now ((int)2)
extern IsaTester SC__IsaTester_T;
#define kJB__TerminalDisplay_h ((int)35)
#define kJB__TerminalDisplay_w ((int)80)
extern FastString* SC__Pac_DebugDecls;
extern MWrap* SC__Pac_HoistSpace;
extern MWrap* SC__Pac_JSM;
#define kSC__Pac_kContinue ((int)254)
#define kSC__Pac_kExit ((int)255)
extern Assembler SC__Pac_Sh;
extern int SC__Pac_StringsOutOfRange;
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
#define kJB__Wrap_kFree ((int)1)
#define kJB__Wrap_kNothing ((int)0)
#define kJB__Rec_NonFatal ((JB_StringC*)JB_LUB[2398])
#define JB__Rec_Progress JB__.Rec_Progress
#define kJB__fix_TypeDict ((int)3)
#define kJB__fix_TypeObj ((int)1)
#define kJB__fix_TypeStem ((int)2)
#define kJB__fix_TypeValue ((int)0)
#define JB__Flow_Active JB__.Flow_Active
#define JB__Flow_AlwaysMove JB__.Flow_AlwaysMove
#define JB__Flow_BreakOnFail JB__.Flow_BreakOnFail
#define JB__Flow_Flow JB__.Flow_Flow
#define kJB__Flow_Log ((int)1)
#define kJB__Flow_Off ((int)0)
#define kJB__Flow_Validate ((int)2)
#define kSC__Instruction_kTypeConst ((int)2)
extern Dictionary* SC__Instruction_OpDict;
extern Instruction* SC__Instruction_TypeList[256];
#define JB__Mrap_MDummy_ JB__.Mrap_MDummy_
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
extern SCOperator* SC__Opp_LeftShift;
extern SCOperator* SC__Opp_Negative;
extern SCOperator* SC__Opp_Subtract;
extern int SC__xC2xB5Form_Count;
extern Dictionary* SC__xC2xB5Form_Forms;
#define JB__File__Speedie JB__.File__Speedie
#define kJB__File_AllowInvisible ((int)1)
#define kJB__File_AllowMissing ((bool)1)
#define kJB__File_AllowSymLinks ((int)2)
#define kJB__File_AppendMode ((int)8)
#define kJB__File_CreateMode ((int)512)
#define kJB__File_ExclusiveMode ((int)2048)
#define kJB__File_ExpectExists ((bool)false)
#define kJB__File_ReadMode ((int)0x000)
#define kJB__File_ReadWriteMode ((int)2)
#define kJB__File_TruncateMode ((int)1024)
#define kJB__File_WantFileObjects ((int)4)
#define kJB__File_WriteMode ((int)1)
#define JB__bin_Header JB__.bin_Header
extern SCIterator* SC__Iter_carray;
extern bool SC__Base_ConstantsLoadingOverride;
extern bool SC__Base_CurrVisibility;
#define kSC__Base_DontGoUp ((int)2)
#define kSC__Base_kPurposeDot ((int)1)
#define kSC__Base_kPurposeFunc ((int)0)
#define kSC__Base_kPurposeVar ((int)2)
#define kSC__Base_kPurposeVarDecl ((int)3)
#define JB__Proc__Parent JB__.Proc__Parent
#define JB__Proc_CheckedParent JB__.Proc_CheckedParent
#define JB__Err_AutoPrint JB__.Err_AutoPrint
#define JB__Err_BackupErrorSource JB__.Err_BackupErrorSource
#define JB__Err_KeepStackTrace JB__.Err_KeepStackTrace
#define JB__Macro_TmpPrms_ JB__.Macro_TmpPrms_
#define kSC__Beh_kBehaviourProto ((int)2)
#define kSC__Beh_kBehaviourProtoRequired ((int)6)
#define kSC__Beh_kBehaviourTable ((int)1)
extern SCFile* SC__File_Curr;
extern SCFunction* SC__Func__CurrFunc;
extern FunctionType SC__Func__Info;
extern int SC__Func_FuncStats[12];
extern int SC__Func_InBranch;
extern int SC__Func_InLoop;
extern int SC__Func_OnceCount;
extern int SC__Func_SyxID;
extern Dictionary* SC__Func_TemporalStatements;
extern SCModule* SC__Mod_Curr;
extern int SC__Mod_ModuleDepth;

//// HEADER LibGlobs.h

struct JB_Globals {
	byte __Dummy__;
	bool Tk__DotInsertAllow;
	bool TerminalColor_Enabled;
	bool Flow_AlwaysMove;
	bool Flow_BreakOnFail;
	byte Flow_Active;
	bool Proc_CheckedParent;
	byte Err_AutoPrint;
	bool Err_KeepStackTrace;
	u16 Tk__StopBars;
	u16 API_NilHappened_;
	int Syx_CurrFuncID_;
	Float64 Rec_Progress;
	Dictionary* Constants_JS_UnEscapeStr;
	Dictionary* Constants_XML_UnEscapeStr;
	Dictionary* Constants_EscapeChr;
	Message* Tk__EndOfLineMarker;
	Dictionary* Constants_EscapeStr;
	Dictionary* TC_Types_Dict;
	JB_File* Platform_Logger_;
	JB_ErrorReceiver* StdErr;
	Dictionary* Constants_JS_EscapeStr;
	JB_String* App_Usage;
	Dictionary* Constants_UnEscapeStr;
	FlowControl* Flow_Flow;
	Message* App__Conf;
	Message* App__Prefs;
	JB_File* App__StdOut;
	JB_String* File__Speedie;
	JB_String* bin_Header;
	JB_File* App__stdin;
	SpdProcess* Proc__Parent;
	Message* Err_BackupErrorSource;
	Dictionary* Constants_XML_EscapeStr;
	Dictionary* Constants__SyxDict;
	Array* Macro_TmpPrms_;
	Array* App__Args;
	JB_String* App__Path;
	Dictionary* Tk__ErrorNames;
	Array* ErrorSeverity__ErrorNames;
	InputStream_ParserCallBack_interface_prototype SS_ParserCallBack_run;
	FP_fnIDGenerator Tk_Splitter;
	FP_SorterComparer Str__Sorter;
	FP_SorterComparer Msg__Sorter;
	CakeVM_CakeChef CakeVM_DummyChef;
	FP_SorterComparer File__Sorter;
	FP_SorterComparer Tree__Sorter;
	FP_SorterComparer ID__ByID;
	FP_SorterComparer ID__ByFreq;
	RandomXOR* Random;
	RandomXOR RandomShared;
	RandomXOR zalgo_R;
	CompressionStats MzSt_All;
	MessagePosition Tk_Using;
	uint64 Mrap_MDummy_[2];
	byte CharSet_Props[256];
	SyntaxObj* Constants__FuncArray[64];
};
extern JB_Globals JB__;


//// HEADER JB.h



// App
JB_String* JB_App__AppPath();

JB_String* JB_App__Conf(JB_String* Name);

void JB_App__Crash(JB_String* Reason);

ErrorInt JB_App__CWDSet(JB_String* Value);

JB_String* JB_App__FileName();

int JB_App__Init_();

bool JB_App__IsMainThread();

ErrorInt JB_Main();

JB_String* JB_App__MemoryUsage(int Over, FastString* Fs_in);

SpdProcess* JB_App__Parent(bool Expect);

JB_String* JB_App__OrigPath();

Message* JB_App__Prefs();

void JB_PrintStackTrace();

ExitCode JB_App__Say(JB_String* S, bool Print);

JB_String* JB_App__ArgValue(JB_String* Name);

bool JB_App__Yes(JB_String* Name);



// AutoComplete
int SC_AutoComplete__Init_();



// CodeSorter
SortComparison SC_CodeSorter__FPackID(SCObject* Self, SCObject* B);

SortComparison SC_CodeSorter__GPackID(SCDecl* Self, SCDecl* B);

SortComparison SC_CodeSorter__Leafness(SCFunction* Self, SCFunction* B);

void SC_CodeSorter__LeafsFirst();

FP_SorterComparer SC_CodeSorter__PackID(bool IsFunc);



// Comp
void SC_Comp__AddFunny(Message* Msg, Message* Curr);

SCDecl* SC_Comp__AddGlobalConst(JB_String* Name, SCClass* C, uint /*NilState*/ Dcl);

void SC_Comp__AddGlobalConstFloat(JB_String* Name, SCClass* C, JB_String* Value);

void SC_Comp__AddGlobalConstNum(JB_String* Name, SCClass* C, int64 Value);

bool SC_Comp__AddMain(int Mark);

JB_String* SC_Comp__AddSCProj(JB_String* Path);

Dictionary* SC_Comp__Adj(Message* F);

void SC_Comp__AppBuildLibs(JB_File* Inner);

void SC_Comp__AppBuildOneLib(JB_File* Inner, JB_String* Name);

void SC_Comp__AppendCompilerTime(JB_String* S, int Durr);

void SC_Comp__AppleBuildApp(JB_File* Product, JB_File* Project);

bool SC_Comp__Banned(JB_String* Name);

JB_File* SC_Comp__BuildFolder();

void SC_Comp__Bundle();

JB_String* SC_Comp__CakeExt();

JB_File* SC_Comp__CanTryModes();

void SC_Comp__CheckIsGoodLibrary();

void SC_Comp__ClearEnvs();

void SC_Comp__CodeSign(JB_File* Gui_exe);

void SC_Comp__CollectConstants();

void SC_Comp__CollectInbuiltSizes();

bool SC_Comp__CollectIsaTests(Message* S);

void SC_Comp__CompileAll();

void SC_Comp__CompileTime();

bool SC_Comp__ConfBool(JB_String* Name, bool Default);

void SC_Comp__CreateDisambiguation();

void SC_Comp__CreateInitsAndMore();

void SC_Comp__CreateRoot();

void SC_Comp__DeadStrip();

void SC_Comp__DoRefAnalysis();

bool SC_Comp__EnterCompile();

JB_String* SC_Comp__exe();

void SC_Comp__FileSanityTests();

void SC_Comp__FileTestsSub(JB_File* Dest, JB_File* Src, JB_String* A, JB_String* B);

Message* SC_Comp__FindAdj(Message* Exp, Array* Prms);

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

JB_File* SC_Comp__InputFile(JB_String* S, Message* Where);

JB_File* SC_Comp__InputFileAlways(JB_String* S);

bool SC_Comp__IsTest();

JB_File* SC_Comp__Jeebox();

SCFunction* SC_Comp__LoadRefFunc(JB_String* Name);

void SC_Comp__LoadSuperClasses();

SCFunction* SC_Comp__LoadTypeTest(JB_String* S);

void SC_Comp__MiniTests();

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

bool SC_Comp__ScriptRecompile(JB_File* F, JB_File* Script_build);

void SC_Comp__SetConf(SCImport* Proj, Message* Conf);

void SC_Comp__SetupEnv();

SCClass* SC_Comp__SoftClass(JB_String* Name);

bool SC_Comp__SortModulesAndClasses();

JB_File* SC_Comp__SpeedieDir(JB_String* S);

JB_String* SC_Comp__SpeedieProj();

bool SC_Comp__Stage(JB_String* Name);

SCClass* SC_Comp__FindClassName(JB_String* Name, SCNodeFindMode Mode);

SCClass* SC_Comp__SyntaxAccess(Message* Name);

bool SC_Comp__SyntaxIs(CompilerStage Type);

void SC_Comp__SyntaxIsSet(CompilerStage Type, bool Value);

void SC_Comp__TestDate();

void SC_Comp__Timer(JB_String* Name);

void SC_Comp__TimerSub(JB_String* S, int Durr);

bool SC_Comp__TimeTest(Date Elapsed);

bool SC_Comp__TryCopyLib(JB_File* Ldest, JB_String* Name, JB_String* Base);

bool SC_Comp__TryVariousStartModes();

JB_File* SC_Comp__UsingScript(JB_File* F);

JB_String* SC_Comp__VariantSuffix();

void SC_Comp__VariousSelfTests();

SCNode* SC_Comp__WrongConf(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCFunction* SC_Comp__XFunc(JB_String* Name, Message* M);



// CustomOps


// Existing


// FastStringOpts
void SC_FastStringOpts__FS(Message* Exp, Message* GetResult);

void SC_FastStringOpts__FSOptInit(JB_String* Name, Message* S);

bool SC_FastStringOpts__Init(Message* S);

int SC_FastStringOpts__Init_();

void SC_FastStringOpts__Optimise(Message* S);

void SC_FastStringOpts__StringToByte(Message* Str);

void SC_FastStringOpts__TryStringAppend(Message* S);



// FB
bool SC_FB__AppOptions_alive(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_arch(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_b(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_bake(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_beep(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_breakonerr(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_cake(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_check(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_clean(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_codesign(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_cpp(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_crash(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_d(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_directtest(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_dosign(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_elf(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_env(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_flow(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_flowmode(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_force(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_gcc(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_help(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_hideaway(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_inlinelib(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_keepallerrors(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_mem(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_nocolor(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_nocompile(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_noisy(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_optimise(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_output_path(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_path(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_perry(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_print(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_quiet(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_self(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_single(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_stages(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_strip(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_target(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_targetdebug(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_variant(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppOptions_warn(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppTransCompile(JB_String* Name, JB_String* Value, FastString* Purpose);

bool SC_FB__AppVersionNumber(JB_String* Name, JB_String* Value, FastString* Purpose);

void SC_FB__CheckSelfModifying();

bool SC_FB__CompilerInfo();

bool SC_FB__Explain(FastString* Purpose, JB_String* Name);

void SC_FB__Help();

int SC_FB__Init_();

bool SC_FB__ParseArgs();

void SC_FB__ParseOption(JB_String* Arg);

void SC_FB__SetFlow();

void SC_FB__SetOutputPath(JB_String* Path);

void SC_FB__StopStripping();

JB_String* SC_FB__TryUseProject(JB_String* Path, bool IsScript);



// ImageHelper
JB_String* JB_ImageHelper__ConvertPNGToVOI(JB_String* P, Message* Where);



// AC
bool SC_AC__Active();

void SC_AC__ActualDefine(Message* M, Message* S);

Message* SC_AC__AllTmps();

bool SC_AC__ASM(Message* Msg, SCFunction* Fn);

Message* SC_AC__ASMFail(SCFunction* Fn, Message* Ret);

Message* SC_AC__AutoComplete(Message* Ff, JB_String* Name, JB_String* Purpose);

void SC_AC__AutoCompleteSub(Message* Ff, JB_String* Name, Message* Into);

Message* SC_AC__AutoJump(Message* Cmd);

void SC_AC__AutoSub(SCNode* Scope, JB_String* Name, Array* Found, int Types, Message* NeedTypeLimit);

void SC_AC__AutoSub2(SCNode* Scope, JB_String* Name, Array* Found, int Types, Message* NeedTypeLimit, DictionaryReader* Within);

void SC_AC__AutoSub3(SCObject* Value, JB_String* Key, Array* Found, JB_String* SearchedName, int Types, SCDecl* TypeLimiter);

Message* SC_AC__CallFrom(Message* Msg, JB_Object* Found);

Message* SC_AC__CallFromDefine(Message* Msg, SCFunction* Fn, JB_Object* Found);

void SC_AC__CallFromSub(Message* Arg, SCFunction* Fn);

bool SC_AC__CanUseName(SCNode* L);

Message* SC_AC__Check(Message* Cmd);

Message* SC_AC__CheckSub(Message* Cmd);

Message* SC_AC__CmdCleanUp(Message* Arg);

bool SC_AC__CmdWrap(Message* Arg);

Message* SC_AC__CppASM(Message* Msg, SCFunction* Fn);

void SC_AC__CppView(Message* Out, SCFunction* Fn);

Message* SC_AC__Define(Message* Msg, JB_String* Purpose, JB_Object* Found);

Message* SC_AC__Define_Behaviour(SCFunction* Fn, JB_String* Purpose);

Message* SC_AC__Define_Something(SCFile* Myfile, int F, Message* Thg, JB_String* Purpose);

Message* SC_AC__DefineOrCall(Message* Msg, JB_String* Purpose, JB_Object* Found);

Message* SC_AC__Diissplay(Message* Msg, Message* S, JB_String* Purpose);

Message* SC_AC__DoCmd(Message* Cmd);

bool SC_AC__EnterAutoComplete();

Message* SC_AC__ErrorsInAWayThatPerryLikes();

bool SC_AC__FeedBackViewASMSub(Message* Out, SCFunction* Fn, FastString* Fs, bool RenderBlocks);

Message* SC_AC__FindAdj(Message* Msg);

Message* SC_AC__FuncTmps();

SCFunction* SC_AC__GetFunc(Message* Cmd, SCFile* Myfile, int Ff, int N);

SCFunction* SC_AC__GetFunc2(SCFile* Myfile, int F, int N);

SCNode* SC_AC__GetScope(Message* Orig, int& Types);

void SC_AC__IdentifyBetter(Message* Node, JB_String* Name);

int SC_AC__Init_();

bool SC_AC__InitedOK();

Message* SC_AC__JumpImport(Message* Cmd);

Message* SC_AC__LocateDefinition(Message* Msg, SCObject* Already_defined, bool DisplayOnly);

Message* SC_AC__LocateDefinitionSub(Message* Msg, SCObject* Already_defined, SCDecl* Ty, bool DisplayOnly);

Message* SC_AC__MainAct(Message* Cmd, SCFile* My_file);

Message* SC_AC__MainActAutoComplete(Message* Thg, JB_String* Str, Message* Cmd);

Message* SC_AC__MiniErrors(JB_ErrorReceiver* L, uint /*ErrorSeverity*/ Sev);

void SC_AC__ParserRestore();

void SC_AC__PerryTalk(SpdProcess* Perry);

Message* SC_AC__ReportMemory(Message* Cmd);

Message* SC_AC__RespondDefine(Message* Msg, Message* S, JB_String* Purpose);

Message* SC_AC__RootTmpComplete(Message* Cmd);

Message* SC_AC__TmpAutoComplete(Message* F, JB_String* Name, JB_String* Type);

Message* SC_AC__UnusedStuff(Message* Cmd);

Message* SC_AC__WriteError(JB_String* Name);



// Intrinsics
int SC_Intrinsics__Init_();

void SC_Intrinsics__Process();

void SC_Intrinsics__ProcessTrin(FastString* Vm, FastString* Cpp, Array* Codes, uint /*byte*/ T);

bool SC_Intrinsics__PullOutVecs();

SortComparison SC_Intrinsics__TrinSort(Message* Self, Message* B);



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



// Jeebox


// LibStability
SCObject* SC_LibStability__Find(JB_String* Str, bool Funcs);

int SC_LibStability__Init_();

void SC_LibStability__StabiliseFuncs();

void SC_LibStability__StabiliseGlobs();

void SC_LibStability__StabiliseSub(JB_String* Name, Array* List, bool IsFuncs);

void SC_LibStability__StabiliseSub2(FastString* Fs, Array* List, bool IsFunc);

void SC_LibStability__UseBank(JB_String* Data, bool Funcs);



// LinkMap
void SC_LinkMap__CollectAll();

void SC_LinkMap__CollectFromSource(SCFunction* Self, Message* Src, bool InBranch);

void SC_LinkMap__CollectLinksInOne(SCFunction* Self);



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

bool SC_Options__ModeCake();

bool SC_Options__ModeCpp();



// Output


// PackMaker
void SC_PackMaker__AddAll();

void SC_PackMaker__AddFunc(SCFunction* F);

bool SC_PackMaker__AnyClassesNeeded();

bool SC_PackMaker__BakeAllFuncs(FastString* J);

bool SC_PackMaker__BakeASM(FastString* J);

void SC_PackMaker__BakeClasses(FastString* J);

void SC_PackMaker__BakeDebug(FastString* J);

void SC_PackMaker__BakePackToDisk();

void SC_PackMaker__BakeStrings(FastString* J);

bool SC_PackMaker__BuildGlobs();

void SC_PackMaker__DumpStringsSub(FastString* Strs);

bool SC_PackMaker__FATCompile();

void SC_PackMaker__FatCompileSub();

void SC_PackMaker__FinalPrepare();

int SC_PackMaker__GlobalsSize(Array* List);

int SC_PackMaker__Init_();

void SC_PackMaker__MakePack();

void SC_PackMaker__OrderLibGlobs();

void SC_PackMaker__PackClasses(FastString* J, bool Pack);

void SC_PackMaker__PackIDFuncs(Array* List);

bool SC_PackMaker__UseMain(JB_String* Name, int Id);



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

Message* JB_Tk__fTmpSection(int Start, Message* Parent);

Message* JB_Tk__fTmpSub(Message* Result, int OpFlags, int ThingFlags);

Message* JB_Tk__fTypeCast(int Start, Message* Parent);

Message* JB_Tk__fURL(int Start, Message* Parent);

Message* JB_Tk__fXML(int Start, Message* Parent);

Message* JB_Tk__fXML_Comment(int Start, Message* Parent);

Message* JB_Tk__fXML_DTD(int Start, Message* Parent);

Message* JB_Tk__fXML_PI(int Start, Message* Parent);

Message* JB_Tk__fYoda(int Start, Message* Parent);

Message* JB_Tk__GetFuncAfter(Message* Result);

int JB_Tk__GotoEndOfLine(int From);

Message* JB_Tk__IndentBug(Message* Curr);

void JB_Tk__Init();

int JB_Tk__Init_();

int JB_Tk__InitCode_();

Message* JB_Tk__LoweredIndent(Message* Output, Message* Curr);

Message* JB_Tk__MakeInvisArg(Message* Tmp);

Message* JB_Tk__MakeRel(Message* First, int Bits);

int JB_Tk__MessageErrorSub(FastString* Fs, int Num);

bool JB_Tk__NeedName(Message* Thg);

Message* JB_Tk__NewParentName(Message* Parent, Syntax Func, int Start, JB_String* Name);

Message* JB_Tk__NewParent(Message* Parent, Syntax Func, int Start, int End);

Message* JB_Tk__NewEmpty(Message* P, Syntax F, int Start, int After);

Message* JB_Tk__NewSkip(Message* P, Syntax F, int Start, int NameStart, int NameEnd);

Message* JB_Tk__NewWord(Message* P, Syntax F, int Start, int SearchFrom);

void JB_Tk__NextLineAndIndent(Message* Parent, ParserLineAndIndent* Rz);

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

Message* JB_Tk__ProcessSyxParent(Message* Parent, int Ops, int ThingFlags);

Message* JB_Tk__ProcessSyxSub(Message* Parent, int Ops, int KindOfThing, bool Expect);

Message* JB_Tk__ProcessThing(int Ops, bool Expect);

Message* JB_Tk__ProcessThingNoBar(int Ops, bool Expect);

Message* JB_Tk__ProcessThingOrTmp(int Opps);

Message* JB_Tk__ReRoute(Message* Output, Message* Cnj, Message* F);

Message* JB_Tk__ThingXMLAtt(int Start, Message* Parent);

void JB_Tk__TokensChar(JB_String* Range, TokHan* H);

void JB_Tk__TokensFn(Array* Arr, int Bits, FP_ParseHandler Func);

void JB_Tk__TokensHan(Array* Arr, TokHan* H);

void JB_Tk__TokenzFn(JB_String* S, int Bits, FP_ParseHandler Func);

Message* JB_Tk__UnexpectedSyntax(Message* Bad);

Message* JB_Tk__UnTmpPlace(Message* R);

bool JB_Tk__WillEnd();

int JB_Tk__WordAfter(int Start);

int JB_Tk__WordAfterSub(int Start, CharSet Cs);

int JB_Tk__XMLAttribs(Message* XML, int Start);

Message* JB_Tk__XMLWhatever(int S, int Skip, JB_String* Ender, Syntax Fn);

Ind JB_Tk__XMLWordEnd(int From);



// PicoNoise


// Platform
JB_String* JB_Platform__CPU_Name();

int JB_Platform__Init_();

void JB_Platform__Log(JB_String* S);

JB_File* JB_Platform__OpenLog();



// PostIncrementNil
void SC_PostIncrementNil__Check(Message* Ch);

void SC_PostIncrementNil__Clear();

int SC_PostIncrementNil__Init_();

void SC_PostIncrementNil__SyntaxAppend(Message* Ch);



// SCGame3D
int SC_SCGame3D__Init_();

SCNode* SC_SCGame3D__Love(Message* Node, SCNode* Name_space, Message* ErrPlace);

bool SC_SCGame3D__NeedShader(JB_String* Name);

SCNode* SC_SCGame3D__NeuModel(Message* Node, SCNode* Name_space, Message* ErrPlace);



// SC
int SC__Init_();



// Refs
void SC_Refs__DeclInit(Message* Dcl, SCFunction* Fn, bool IsJustAnArg);

Message* SC_Refs__DecrMulti(SCDecl* D, Message* M, bool IsReturn);

void SC_Refs__Destructable(Message* Blocker, Message* Arg, Message* Name);

bool SC_Refs__ExitHitsOrGoesPast(Message* Curr, Message* Arg);

bool SC_Refs__ExprNeedsTemping(Message* Child, Message* Name);

Message* SC_Refs__LastUsedRefPlace(Message* Name, Message* Arg);

void SC_Refs__RC_CheckFuncAllocOK(SCFunction* Self, Message* Dot);

void SC_Refs__RC_CheckNoObjPms(Message* Msg);

void SC_Refs__RC_DeclArg(SCDecl* AR, SCFunction* Fn);

void SC_Refs__RC_HandleDisappearing(Message* Msg, int Basis);

void SC_Refs__RC_HandleDisappearingSub(Message* Msg, int Basis);

void SC_Refs__RC_IgnoreReturn(Message* Msg);

bool SC_Refs__RC_NeedsOwnBlock(Message* Msg, Message* Pp);

void SC_Refs__RC_Rel(Message* Rel);

void SC_Refs__RC_RelConstructor(Message* Rel);

void SC_Refs__RC_RelInit(Message* Rel);

void SC_Refs__RealRefIncr(Message* Name, Message* Dcl);

int SC_Refs__RefBasis(Message* Msg, bool SetOnly);

int SC_Refs__RefBasisStruct(Message* Msg, bool SetOnly);

Message* SC_Refs__RefClearMsg(Message* Msg);

void SC_Refs__RefDecr(Message* Msg, Message* Place, int Basis, bool IsReturn);

Message* SC_Refs__RefDecrMsg(Message* Msg, bool IsReturn);

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
JB_Error* SC_Errors__AlreadyIgnored(Message* F, SCFunction* Fn);

bool SC_Errors__CanKeep(JB_Error* Err);

int SC_Errors__Init_();



// SC_Targets
int SC_SC_Targets__Init_();

bool SC_SC_Targets__SyntaxAccess(JB_String* Name);

void SC_SC_Targets__SyntaxAccessSet(JB_String* Name, bool Value);



// SourceMap
bool SC_SourceMap__Check(SCFunction* Fn, int T);

int SC_SourceMap__Init_();

uint* SC_SourceMap__Reserve(int T);



// Crkt
void SC_Crkt__CollectString(Message* M);

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



// StructStuff
void SC_StructStuff__DelayedFix();

int SC_StructStuff__Init_();



// TextAssembler
int SC_TextAssembler__Init_();



// Ext
bool SC_Ext__AllowedThisFile(JB_String* Name);

bool SC_Ext__BackupCompiler();

JB_String* SC_Ext__BackupPath();

bool SC_Ext__CanCompile(JB_String* Name);

bool SC_Ext__Clean();

void SC_Ext__ClearThis();

bool SC_Ext__CollectAndCompile(JB_File* Input, JB_String* Output);

Array* SC_Ext__CollectCppsInto(JB_File* Fol, JB_File* Objects);

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

int SC_Ext__NeedNewObjForSrc(JB_String* Cpp, JB_File* Objects);

int SC_Ext__NoGoodObject(JB_String* Cpp, JB_File* H, JB_File* O);

JB_String* SC_Ext__PrintProduct(JB_String* S, bool ActualCompile);

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

JB_String* SC_Ext__TmpBase(JB_String* V, bool Lib);

JB_String* SC_Ext__TmpErr(JB_String* V);

JB_String* SC_Ext__TmpOut(JB_String* V);

bool SC_Ext__TransCompile(Array* Files, JB_String* Dest, JB_String* Type, JB_File* ToDelete);

bool SC_Ext__TransCompileWrap(Array* Cpps);

bool SC_Ext__UseAndCompile(Array* Input, JB_String* Output);



// VM_Builder
xC2xB5Form* SC_VM_Builder__AddForm(Message* Form);

void SC_VM_Builder__AddxC2xB5Op(JB_String* Name, int Id);

bool SC_VM_Builder__BuildFiles();

bool SC_VM_Builder__BuildInstructions(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_VM_Builder__Clean(Message* Msg);

JB_File* SC_VM_Builder__CppLibFile(JB_String* Ch);

Message* SC_VM_Builder__DataTypeCreate(Message* Form, int Fnum);

void SC_VM_Builder__DataTypeModule();

Message* SC_VM_Builder__DefineGet(JB_String* Fname, int Up, int Down);

void SC_VM_Builder__DefineGetSub(JB_String* Fname, int Up, int Down, uint /*byte*/ C, uint /*byte*/ C2);

Message* SC_VM_Builder__FatCreatorSub(JB_String* Name, xC2xB5Form* Form);

void SC_VM_Builder__FillEncoders(Message* List, bool ActuallyMakeTheVM);

void SC_VM_Builder__FillTypePrm(JB_String* Fname, int Pname);

void SC_VM_Builder__FinishAcc();

int SC_VM_Builder__FreeID(Message* M, int Ask);

int SC_VM_Builder__GenAcc(Message* Line, int Bit_pos, int Pname, int Max);

void SC_VM_Builder__GenerateForms(Message* Forms, bool DoMore);

void SC_VM_Builder__GenerateOne(Message* Form_msg, int F);

int SC_VM_Builder__Init_();

bool SC_VM_Builder__JustDefineInstructions();

void SC_VM_Builder__MakeFatCreator(JB_String* Name, xC2xB5Form* Form);

void SC_VM_Builder__MakeJump(Message* Tmp, FastString* Jump);

bool SC_VM_Builder__MakeTheVM();

void SC_VM_Builder__MakeVM(Message* Tmp, FastString* Vm);

ASM* SC_VM_Builder__MissingInstruction(FatASM* Self, ASM* Curr, ASM* After);

bool SC_VM_Builder__OKBoomer(Message* Tmp, int X, ASM_Encoder FormEnc, Array* R);

void SC_VM_Builder__SafeWrite(JB_String* Name, FastString* Data);

void SC_VM_Builder__SyntaxAppend(Message* M);

void SC_VM_Builder__VM_FillPos(Message* List, Array* Out);

void SC_VM_Builder__VM_MakeInstructionSub(Message* Tmp, bool Ask, Array* ActuallyMakeTheVM, int ForceID);

bool SC_VM_Builder__VM_NewIns(Message* Tmp, bool Ask, Array* ActuallyMakeTheVM);

void SC_VM_Builder__VM_NewInstructions(Message* List, bool Amount, Array* Out);

Message* SC_VM_Builder__VMBox();

void SC_VM_Builder__VMCpp(FastString* Vm_code, FastString* Jump);

JB_File* SC_VM_Builder__VMFile(JB_String* Name);

void SC_VM_Builder__VMLine(Message* Line, FastString* Vm);



// __classes__


// __modules__


// main
void SC_AddToStaticSection(Message* Arg, Message* ToAdd);

int SC_ArrayInOrderCheck(int InOrder, Message* Msg);

SCClass* SC_ClassOfObjForC(Message* Curr);

bool SC_ClassOrModuleLinkage_cpp_class(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_cpp_part(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_cpp_wrapper(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_datatype(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_embedded(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_ignore(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_libinternal(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_noearlyfree(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_numeric(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_sort_properties(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_stateful(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_stateless(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_tighten(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_visible(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_ClassOrModuleLinkage_wrapper(SCFunction* Fn, Message* Node, SCNode* Name_space);

SCNode* SC_ClsCollectTable_description(Message* Node, SCNode* Name_space, Message* ErrPlace);

void SC_CollectDeclsGlobals(Message* Arg, SCModule* Mod);

void SC_CollectManyDeclsFromBody(Message* Arg, SCNode* Scarg);

bool JB_CompareError(Message* Expected, Message* Found);

int64 SC_ConstifyBitAnd(ASMReg L, ASMReg R);

int64 SC_ConstifyBitNot(ASMReg L, ASMReg R);

int64 SC_ConstifyBitOr(ASMReg L, ASMReg R);

int64 SC_ConstifyBitSHL(ASMReg L, ASMReg R);

int64 SC_ConstifyBitSHR(ASMReg L, ASMReg R);

int64 SC_ConstifyBitSHS(ASMReg L, ASMReg R);

int64 SC_ConstifyBitXor(ASMReg L, ASMReg R);

int64 SC_ConstifyBoolMul(ASMReg L, ASMReg R);

int64 SC_ConstifyFloatDiv(ASMReg L, ASMReg R);

int64 SC_ConstifyFloatMod(ASMReg L, ASMReg R);

int64 SC_ConstifyFloatMul(ASMReg L, ASMReg R);

int64 SC_ConstifyFloatPlus(ASMReg L, ASMReg R);

int64 SC_ConstifyIntDiv(ASMReg L, ASMReg R);

int64 SC_ConstifyIntMod(ASMReg L, ASMReg R);

int64 SC_ConstifyIntMul(ASMReg L, ASMReg R);

int64 SC_ConstifyIntPlus(ASMReg L, ASMReg R);

bool SC_CppRefTable_disowns(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_CppRefTable_disturbs(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Create_JeeboxTest(Message* Msg);

SCDecl* SC_CustomFuncOp(Message* Exp, SCOperator* Comp, SCNode* Name_space, Message* RN);

SCDecl* SC_DeclOfObjForC(Message* Curr);

Message* SC_DeclsDefault(Message* Def);

Message* SC_DefaultStitch(Message* Default, Message* Dcl);

SCObject* SC_DollaDolla(Message* Exp, SCNode* Name_space);

SCNode* SC_DontRemove(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCDecl* SC_DoOpCompare(Message* Exp, SCDecl* Lc, SCDecl* Rc, SCOperator* Comp, SCNode* Name_space);

JB_String* JB_EntityTest();

SCDecl* SC_ExtractDecl(Message* C, SCNode* Name_space, DeclMode Purpose, int Depth);

ASMReg SC_FinalDecrements(Assembler* Self, Message* Exp, ASMReg Dest);

Message* SC_FindBytePos(Message* Node);

Message* SC_FindBytePosSub(Message* Node);

bool SC_FuncLinkageTable_cpp_part(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_FuncLinkageTable_cpp_wrapper(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_FuncLinkageTable_ignore(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_FuncLinkageTable_maxasm(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_FuncLinkageTable_visible(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_FuncPreReader_asm(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_description(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_disabled(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_inline(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_nil(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_numeric(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_opt(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_real(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_todo(SCFunction* Self, Message* Msg);

bool SC_FuncPreReader_trin(SCFunction* Self, Message* Msg);

int JB_Init_();

int JB_SP_AppInit();

int JB_SP_AppInitSub_();

int JB_InitCode_();

SCDecl* SC_IsPointerMath(SCDecl* L, SCDecl* R, SCOperator* Opp, Message* Exp);

void SC_ListFunctionsSub(JB_Object* O, Array* Out);

SCDecl* SC_LowlevelArrayTransform(Message* Exp, SCClass* Cls);

Message* SC_MakeDecl(JB_String* Type, JB_String* Name, Message* Value, SCDeclInfo Purpose);

Message* SC_MakeDeclOrRel(Message* Into, Message* Namemsg, Message* Value);

void SC_MoveFutureStaticsIn(Message* Msg);

Message* SC_NewDeclWithStrMsg(JB_String* Type, Message* RelOrName);

Message* SC_NewDeclNumConst(SCDecl* D, int64 N, JB_String* VarName, bool Shifts);

Message* SC_NewEqRelWithMsgMsg(Message* L, Message* R);

Message* SC_NewEqRelWithStrStr(JB_String* L, JB_String* R);

Message* SC_NewFnc(JB_String* Name);

Message* SC_NewRejoin();

Message* SC_NewRel(Message* L, Message* R, JB_String* Op);

SCDecl* SC_Or_And_Expansion(SCDecl* LC, SCDecl* RC, Message* Exp, SCNode* Name_space);

void JB_Obj_Print(JB_Object* O);

void SC_RelSetOrExpansion(Message* Exp);

SCNode* SC_RootCollectTable_crash(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_RootCollectTable_extends(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_RootCollectTable_static(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCDecl* SC_SameTypeSub(Message* First, Message* Second, SCNode* Name_space);

Message* SC_SettingAProperty(Message* Rel);

bool SC_SettingMemory(Message* Rel);

bool SC_SettingSelfProperty(Message* Rel);

SortComparison SC_SimplestFirst(SCDecl* Self, SCDecl* B);

SortComparison SC_SmallestAlignedFirst(SCDecl* Self, SCDecl* B);

Array* SC_SortInitOrder(Array* Mods);

bool SC_SortInitOrderSub(Array* Mods, Array* Out);

ErrorInt Speedie_Main(PicoComms* Comms, int64 Mode, _cstring* Args);

bool SC_TemporalStatements_alert(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_TemporalStatements_break(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_TemporalStatements_crash(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_TemporalStatements_do(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Tran_ArgArray(Message* Exp, SCNode* Name_space, SCDecl* Decl);

bool SC_Tran_Flow(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Tran_Log(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Tran_Rejoin(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Tran_Time(SCFunction* Fn, Message* Node, SCNode* Name_space);

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

SCDecl* SC_TypeOfSwizSub(Message* Exp, SCDecl* Type, SCNode* Name_space, Message* Side, int Swiz);

SCDecl* SC_TypeOfSwizzle(Message* Exp, SCNode* Name_space, Message* Side, SCDecl* class_Space);

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



// zalgo
int JB_zalgo__Init_();



// _void


// bool
int SC_bool_EqulMode(bool Self, ASMReg L, ASMReg R);

void JB_bool_Append(bool Self, FastString* Fs_in);

JB_String* JB_bool_Render0(bool Self);



// byte
bool JB_byte_CanPrintAsNormalChar(uint /*byte*/ Self);

bool JB_byte_In(uint /*byte*/ Self, uint A, uint B);

bool JB_byte_IsHex(uint /*byte*/ Self);

bool JB_byte_IsInt(uint /*byte*/ Self);

bool JB_byte_IsTextLine(uint /*byte*/ Self);

byte JB_byte_LowerCase(uint /*byte*/ Self);

bool JB_byte_OperatorEq(uint /*byte*/ Self, uint /*byte*/ B);

JB_String* JB_byte_Render(uint /*byte*/ Self, FastString* Fs_in);

byte JB_byte_UpperCase(uint /*byte*/ Self);



// cstring
void JB_cstring_temp(_cstring Self, VirtualJBString* Rz);



// f64
JB_String* JB_dbl_Render(double Self, int Dp, FastString* Fs_in);



// float
float JB_f_ClampWithF(float Self, float H);

float JB_f_Cos(float Self);

float JB_f_Fract(float Self);

float JB_f_Length(float Self);

float JB_f_FloatMix(float Self, float A, float B);

float JB_f_Pow(float Self, int N);

float JB_f_Sine(float Self);

float JB_f_SmoothStep(float Self, float Low, float High);

float JB_f_Tan(float Self);

float JB_f_Uncos(float Self);

float JB_f_Unsin(float Self);

float JB_f_UnTan(float Self, float Y);



// hfloat


// int
ASMReg SC_int_ToASM(int Self);

bool SC_int_IsNormalMatch(int Self);

bool SC_int_IsSimpleOrPointerCast(int Self);

int JB_int_LowestBit(int Self);

int JB_int_OperatorAlign(int Self, int To);

int JB_int_OperatorMax(int Self, int Other);

int JB_int_OperatorMin(int Self, int Other);

JB_String* JB_int_operatorof(int Self, JB_String* Type, JB_String* Nothing);

JB_String* JB_int_RenderFS(int Self, FastString* Fs_in);

int JB_int_SetSign(int Self, bool IsNeg);

JB_String* JB_int_RenderSize(int Self, FastString* Fs_in);

int JB_int_SyntaxAccessSet(int Self, int Bit, bool Value);



// int16


// int64
int64 JB_int64_Abs(int64 Self);

int SC_int64_BitsNeeded(int64 Self);

bool SC_int64_CanStoreAsAddK(int64 Self);

bool SC_int64_Fits(int64 Self, int Amount, bool Signed);

Message* SC_int64_MsgForConst(int64 Self, bool AllowShift);

int64 JB_int64_OperatorMax(int64 Self, int64 D);

JB_String* JB_int64_Render(int64 Self, FastString* Fs_in);

JB_String* JB_int64_StrSize(int64 Self, FastString* Fs_in);

int64 SC_int64_ValueTrap(int64 Self, int64 L, int64 H);



// int8


// ivec2
bool JB_ivec2_OperatorContains(ivec2 Self, int X);

bool JB_ivec2_OperatorInrange(ivec2 Self, ivec2 P);



// ivec3


// ivec4
ivec4 JB_ivec4_Shrink(ivec4 Self, int I);



// uint
bool SC_uint_EqulInputsAreBothBool(uint Self);

FatASM* SC_uint_FAT(uint Self);

uint JB_uint_LowestBit(uint Self);



// uint16


// uint64
int JB_uint64_HintLength(uint64 Self);

uint64 JB_uint64_LowestBit(uint64 Self);

uint64 SC_uint64_rotl1(uint64 Self);

uint64 SC_uint64_Trim(uint64 Self, int B);



// vec2


// vec3


// vec4


// ASM
ASM SC_ASM_AddAK_KSet(ASM Self, uint Value);

ASM SC_ASM_AddB_KSet(ASM Self, uint Value);

ASM SC_ASM_AddK_KSet(ASM Self, uint Value);

ASM SC_ASM_AddOrSubM_LSet(ASM Self, uint Value);

ASM SC_ASM_AddOrSubM_ShSet(ASM Self, uint Value);

ASM SC_ASM_Alloc_AmountSet(ASM Self, uint Value);

ASM SC_ASM_BFLD_downSet(ASM Self, uint Value);

ASM SC_ASM_BFLD_LSet(ASM Self, uint Value);

ASM SC_ASM_BFLD_signSet(ASM Self, uint Value);

ASM SC_ASM_BFLD_upSet(ASM Self, uint Value);

ASM SC_ASM_BFLS_downSet(ASM Self, uint Value);

ASM SC_ASM_BFLS_LSet(ASM Self, uint Value);

ASM SC_ASM_BFLS_signSet(ASM Self, uint Value);

ASM SC_ASM_BFLS_upSet(ASM Self, uint Value);

ASM SC_ASM_Bra_JmpSet(ASM Self, uint Value);

ASM SC_ASM_Bra_SmallSet(ASM Self, uint Value);

ASM SC_ASM_CmpF_CmpSet(ASM Self, uint Value);

ASM SC_ASM_CmpF_LSet(ASM Self, uint Value);

ASM SC_ASM_CmpI_CmpSet(ASM Self, uint Value);

ASM SC_ASM_CmpI_LSet(ASM Self, uint Value);

ASM SC_ASM_CNTC_cnstSet(ASM Self, uint Value);

ASM SC_ASM_CNTC_offsetSet(ASM Self, uint Value);

ASM SC_ASM_CNTC_sizeSet(ASM Self, uint Value);

ASM SC_ASM_Compare4_LSet(ASM Self, uint Value);

ASM SC_ASM_Compare4_SmallSet(ASM Self, uint Value);

ASM SC_ASM_ConstStretchy_CondSet(ASM Self, uint Value);

ASM SC_ASM_ConstStretchy_InvSet(ASM Self, uint Value);

ASM SC_ASM_ConstStretchy_ValueSet(ASM Self, uint Value);

ASM SC_ASM_Convert_LSet(ASM Self, uint Value);

ASM SC_ASM_Convert_ModeSet(ASM Self, uint Value);

ASM SC_ASM_Div2_ClearSet(ASM Self, uint Value);

ASM SC_ASM_Div2_DownSet(ASM Self, uint Value);

ASM SC_ASM_Div2_LSet(ASM Self, uint Value);

ASM SC_ASM_Div_KindSet(ASM Self, uint Value);

ASM SC_ASM_Div_LSet(ASM Self, uint Value);

ASM SC_ASM_Float_DSet(ASM Self, uint Value);

ASM SC_ASM_Float_LSet(ASM Self, uint Value);

ASM SC_ASM_FloatConst_HighSet(ASM Self, uint Value);

ASM SC_ASM_ForeignFunc_TableSet(ASM Self, uint Value);

ASM SC_ASM_Func_JUMPSet(ASM Self, uint Value);

ASM SC_ASM_FuncAddr_IndexSet(ASM Self, uint Value);

ASM SC_ASM_FuncAddr_LibrarySet(ASM Self, uint Value);

ASM SC_ASM_GObj_AddSet(ASM Self, uint Value);

ASM SC_ASM_GObj_ModeSet(ASM Self, uint Value);

ASM SC_ASM_GObj_RefSet(ASM Self, uint Value);

ASM SC_ASM_GTable_AddSet(ASM Self, uint Value);

ASM SC_ASM_GTable_ModeSet(ASM Self, uint Value);

ASM SC_ASM_HALT_ReservedSet(ASM Self, uint Value);

ASM SC_ASM_JCmpEq_JmpSet(ASM Self, uint Value);

ASM SC_ASM_JCmpEq_LSmallSet(ASM Self, uint Value);

ASM SC_ASM_JCmpEq_RSmallSet(ASM Self, uint Value);

ASM SC_ASM_JCmpF_CmpSet(ASM Self, uint Value);

ASM SC_ASM_JCmpF_JmpSet(ASM Self, uint Value);

ASM SC_ASM_JCmpI_CmpSet(ASM Self, uint Value);

ASM SC_ASM_JCmpI_JmpSet(ASM Self, uint Value);

ASM SC_ASM_JCmpK_JmpSet(ASM Self, uint Value);

ASM SC_ASM_JCmpK_KSet(ASM Self, uint Value);

ASM SC_ASM_Jump_JUMPSet(ASM Self, uint Value);

ASM SC_ASM_Loop_JmpSet(ASM Self, uint Value);

ASM SC_ASM_Loop_SmallSet(ASM Self, uint Value);

ASM SC_ASM_MemoryCopy_LengthSet(ASM Self, uint Value);

ASM SC_ASM_MemUtil_NSet(ASM Self, uint Value);

ASM SC_ASM_MemUtil_OpSet(ASM Self, uint Value);

void PrintASM(ASM Self);

ASM SC_ASM_R1Set(ASM Self, uint Value);

ASM SC_ASM_R2Set(ASM Self, uint Value);

ASM SC_ASM_R3Set(ASM Self, uint Value);

ASM SC_ASM_R4Set(ASM Self, uint Value);

ASM SC_ASM_R5Set(ASM Self, uint Value);

ASM SC_ASM_Read_moveSet(ASM Self, uint Value);

ASM SC_ASM_Read_OffsetSet(ASM Self, uint Value);

ASM SC_ASM_RefDecrMem_CountSet(ASM Self, uint Value);

ASM SC_ASM_RefDecrMem_OffsetSet(ASM Self, uint Value);

ASM SC_ASM_RefReturn_LSet(ASM Self, uint Value);

ASM SC_ASM_RefSet1_LSet(ASM Self, uint Value);

ASM SC_ASM_RefSet2_DecrSet(ASM Self, uint Value);

ASM SC_ASM_RefSet2_OffsetSet(ASM Self, uint Value);

ASM SC_ASM_RefSet3_DecrSet(ASM Self, uint Value);

ASM SC_ASM_RefSet3_OffsetSet(ASM Self, uint Value);

ASM SC_ASM_RefSetApart_LSet(ASM Self, uint Value);

ASM SC_ASM_REQ_ModeSet(ASM Self, uint Value);

ASM SC_ASM_REQ_ValSet(ASM Self, uint Value);

ASM SC_ASM_RET_ValueSet(ASM Self, uint Value);

ASM SC_ASM_RotateConst_InvSet(ASM Self, uint Value);

ASM SC_ASM_RotateConst_RotSet(ASM Self, uint Value);

ASM SC_ASM_RotateConst_ValueSet(ASM Self, uint Value);

ASM SC_ASM_Shift_ShSet(ASM Self, uint Value);

ASM SC_ASM_Swap_LSet(ASM Self, uint Value);

ASM SC_ASM_Tail_JUMPSet(ASM Self, uint Value);

ASM SC_ASM_TERN_LSet(ASM Self, uint Value);

ASM SC_ASM_TERN_SmallSet(ASM Self, uint Value);

ASM SC_ASM_Trap_UponSet(ASM Self, uint Value);

ASM SC_ASM_U0_LSet(ASM Self, uint Value);

ASM SC_ASM_U1_LSet(ASM Self, uint Value);

ASM SC_ASM_U2_LSet(ASM Self, uint Value);

ASM SC_ASM_U3_LSet(ASM Self, uint Value);

ASM SC_ASM_U4_LSet(ASM Self, uint Value);

ASM SC_ASM_VecConst_K1Set(ASM Self, uint Value);

ASM SC_ASM_VecGet_IndSet(ASM Self, uint Value);

ASM SC_ASM_VecGet_LSet(ASM Self, uint Value);

ASM SC_ASM_VecInc_AmountSet(ASM Self, uint Value);

ASM SC_ASM_VecInc_partSet(ASM Self, uint Value);

ASM SC_ASM_VecMix_LSet(ASM Self, uint Value);

ASM SC_ASM_VecMix_ModeSet(ASM Self, uint Value);

ASM SC_ASM_VecSet_IndSet(ASM Self, uint Value);

ASM SC_ASM_VecSet_LSet(ASM Self, uint Value);

ASM SC_ASM_VecSwizzle_FieldsSet(ASM Self, uint Value);

ASM SC_ASM_VecSwizzle_LSet(ASM Self, uint Value);

ASM SC_ASM_Write_moveSet(ASM Self, uint Value);

ASM SC_ASM_Write_OffsetSet(ASM Self, uint Value);

int SC_ASM__Init_();

void SC_ASM__TestASMText();



// ASMParam
ASMReg SC_ASMParam_ASMReg(ASMParam Self);

bool SC_ASMParam_OperatorIz(ASMParam Self, ASMReg M);

int SC_ASMParam_Reg(ASMParam Self);



// ASMReg
ASMReg SC_Reg_BasicVec(ASMReg Self);

int SC_Reg_BitCount(ASMReg Self);

int SC_Reg_BitLoss(ASMReg Self);

ASMReg SC_Reg_BoolAnswer(ASMReg Self);

int SC_Reg_ByteCount(ASMReg Self);

int SC_Reg_ByteShift(ASMReg Self);

int SC_Reg_Clip(ASMReg Self);

int64 SC_Reg_Const(ASMReg Self);

void SC_Reg_ConstCheck(ASMReg Self);

ASMReg SC_Reg_ExpectSameType(ASMReg Self, ASMReg Dest);

float SC_Reg_F32(ASMReg Self);

Float64 SC_Reg_F64(ASMReg Self);

FatASM* SC_Reg_FAT(ASMReg Self);

uint SC_Reg_FatIndex(ASMReg Self);

ASMReg SC_Reg_FatIndexSet(ASMReg Self, uint Value);

Float64 SC_Reg_float(ASMReg Self);

ASMReg SC_Reg_HaveAddr(ASMReg Self);

ASMReg SC_Reg_incr(ASMReg Self);

bool SC_Reg_IsBitCorrect(ASMReg Self);

bool SC_Reg_IsVec(ASMReg Self);

bool SC_Reg_IsZero(ASMReg Self);

int SC_Reg_LeftScore(ASMReg Self);

FatASM* SC_Reg_NeedFAT(ASMReg Self);

ASMReg SC_Reg_Negate(ASMReg Self, bool Neg);

ASMReg SC_Reg_OperatorAs(ASMReg Self, ASMReg A);

ASMReg SC_Reg_OperatorAsnt(ASMReg Self, ASMReg A);

ASMReg SC_Reg_OperatorBitand(ASMReg Self, ASMReg A);

bool SC_Reg_OperatorIsa(ASMReg Self, uint /*DataTypeCode*/ M);

bool SC_Reg_OperatorIz(ASMReg Self, ASMReg M);

ASMReg SC_Reg_OperatorMul(ASMReg Self, bool B);

ASMReg SC_Reg_OperatorTemp(ASMReg Self, Message* M);

ASMReg SC_Reg_OperatorxE2x80xA2(ASMReg Self, ASMReg Dest);

int SC_Reg_PointerMul(ASMReg Self, Message* Exp, bool Swapped);

SCDecl* SC_Reg_PointerMulSub(ASMReg Self, Message* Exp, bool Swapped);

ASMParam SC_Reg_Prm(ASMReg Self);

ASMReg SC_Reg_ReallySimplify(ASMReg Self);

int SC_Reg_Reg(ASMReg Self);

ASMReg SC_Reg_RegSetWithInt(ASMReg Self, int Value);

ASMReg SC_Reg_RegSetWithReg(ASMReg Self, ASMReg Value);

bool SC_Reg_Signed(ASMReg Self);

ASMReg SC_Reg_Simplify(ASMReg Self);

bool SC_Reg_SomePointer(ASMReg Self);

bool SC_Reg_SyntaxIs(ASMReg Self, ASMReg R);

ASMReg SC_Reg_SyntaxIsSet(ASMReg Self, ASMReg R, bool Value);

bool SC_Reg_TmpCheck(ASMReg Self);

ASMReg SC_Reg_TryRegSet(ASMReg Self, ASMReg Dest);

ASMReg SC_Reg_xC2xB5TypeSetWithTc(ASMReg Self, uint /*DataTypeCode*/ Value);

ASMReg SC_Reg_xC2xB5TypeSetWithReg(ASMReg Self, ASMReg Value);

ASMReg SC_Reg__New();



// ASMType
bool SC_ASMType_IsBlocker(uint /*ASMType*/ Self);

bool SC_ASMType_SyntaxIs(uint /*ASMType*/ Self, uint /*ASMType*/ T);

ASMReg SC_ASMType__Access(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__AddressOf(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__AllocBearStruct(int Dir, Message* Exp, ASMReg Dest, int Size);

ASMReg SC_ASMType__ARel(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__Argument(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__ArgumentSub(Assembler* Self, Message* Exp, ASMReg Mask);

ASMReg SC_ASMType__ASMFunction(Assembler* Self, Message* Exp, ASMReg Dest);

bool SC_ASMType__BadBflg(Assembler* Self, FatASM* L, int Rr);

ASMReg SC_ASMType__BoolNot(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__BRel(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__Char(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__ConstConvert(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg From, uint /*DataTypeCode*/ Old, uint /*DataTypeCode*/ New);

ASMReg SC_ASMType__ConstFromThgName(Assembler* Self, Message* Exp, ASMReg Dest, SCDecl* D);

ASMReg SC_ASMType__Debugger(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__Decl(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__DeclSub(Assembler* Self, Message* Exp, ASMReg Dest, SCDecl* Ty, Message* Rel);

ASMReg SC_ASMType__DoGlobal(Assembler* Self, ASMReg Dest, Message* Exp, SCDecl* D);

ASMReg SC_ASMType__Dot(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__DotConst(Assembler* Self, ASMReg Dest, Message* Exp, SCDecl* Prop);

ASMReg SC_ASMType__First(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__GrabAddr(Assembler* Self, Message* Exp, ASMReg Dest, SCDecl* D, ASMReg T);

ASMReg SC_ASMType__Ignore(Assembler* Self, Message* Exp, ASMReg Dest);

int64 SC_ASMType__IncrAmount(ASMReg Upon, int IsPlus, SCDecl* D);

ASMReg SC_ASMType__Incrementa(Assembler* Self, Message* Exp, ASMReg Dest, int Mode);

ASMReg SC_ASMType__IncrOnAddr(Assembler* Self, Message* Exp, ASMReg Dest, int Mode, ASMReg Addr, int64 Amount, SCDecl* Glob);

ASMReg SC_ASMType__IncrSlowOnAddr(Assembler* Self, Message* F, ASMReg Dest, int Mode, ASMReg Addr, int64 Amount, SCDecl* Glob);

int SC_ASMType__Init_();

void SC_ASMType__InitAccess();

ASMReg SC_ASMType__InlinedReturn(Assembler* Self, Message* Exp, ASMReg Dest);

void SC_ASMType__NotTemp(Assembler* Self, ASMReg Src, Message* P);

ASMReg SC_ASMType__Num(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__Rejoin(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__Return(Assembler* Self, Message* Exp, ASMReg Dest);

bool SC_ASMType__ReturnOpt(Assembler* Self, ASMReg& Ret_);

ASMReg SC_ASMType__Second(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__SetRel(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__Sheb(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__StatExpr(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__Swap(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__Thg(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__ThgReference(Assembler* Self, Message* Exp, ASMReg Dest, SCDecl* D);

ASMReg SC_ASMType__ThgSub(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__TypeCast(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_ASMType__Unexpected(Assembler* Self, Message* Exp, ASMReg Dest);



// CharSet
bool JB_CharSet_SyntaxAccess(CharSet Self, uint B);

int JB_CharSet__Init_();

int JB_CharSet__InitCode_();

void JB_CharSet__MakeDefault();



// ClassInfo


// Codepoint
bool JB_CP_IsLetter(Codepoint Self);

bool JB_CP_IsWhite(Codepoint Self);



// CompilerStage


// ControlClipMode


// ControlLine


// ControlPoint


// ControlRect


// DataTypeCode
int SC_TC_ASMConv(uint /*DataTypeCode*/ Self, uint /*DataTypeCode*/ To);

int SC_TC_ASMPart(uint /*DataTypeCode*/ Self);

int JB_TC_BitCount(uint /*DataTypeCode*/ Self);

int SC_TC_FloatIntMerge(uint /*DataTypeCode*/ Self, int Old, Message* S);

int JB_TC_NumericCount(uint /*DataTypeCode*/ Self);

int SC_TC_NumericCountBoolsToo(uint /*DataTypeCode*/ Self, SCDecl* D);

JB_String* JB_TC_Render(uint /*DataTypeCode*/ Self, FastString* Fs_in);

DataTypeCode JB_TC_SetSigned(uint /*DataTypeCode*/ Self, bool HasSign);

SCClass* SC_TC_SignedStuffClass(uint /*DataTypeCode*/ Self);

bool JB_TC_SpecialReg(uint /*DataTypeCode*/ Self);

ASMReg SC_TC_zero(uint /*DataTypeCode*/ Self);

Dictionary* JB_TC__Types();



// Date
JB_Duration JB_Date_Ago(Date Self);

int JB_Date_DayOfWeekApprox(Date Self);

int64 JB_Date_Days(Date Self);

Float64 JB_Date_Float64(Date Self);

JB_String* JB_Date_RenderDurr(Date Self, FastString* Fs_in);

int64 JB_Date_WholeSeconds(Date Self);



// DeclMode
bool SC_DeclMode_SyntaxIs(DeclMode Self, DeclMode O);



// DotUseType
bool SC_DotUseType_SyntaxIs(DotUseType Self, DotUseType D);



// ErrorFlags


// ErrorInt


// ErrorMarker


// ErrorSeverity
JB_String* JB_ErrorSeverity_Render(uint /*ErrorSeverity*/ Self, FastString* Fs_in);

bool JB_ErrorSeverity_SyntaxIs(uint /*ErrorSeverity*/ Self, uint /*ErrorSeverity*/ E);

ErrorSeverity JB_ErrorSeverity_SyntaxUsing(uint /*ErrorSeverity*/ Self);

void JB_ErrorSeverity_SyntaxUsingComplete(uint /*ErrorSeverity*/ Self, JB_Object* Idk);

ErrorSeverity JB_ErrorSeverity__Find(JB_String* Name, Message* Err);

Array* JB_ErrorSeverity__InitNames();



// ExitCode


// FailableInt


// FileDes


// FileMode


// FileSizeInt


// Float16


// Float64


// FloatRangeConverter


// FloatRangeConverterBasic


// FlowControlStopper
FlowControlStopper JB_flow_SyntaxUsing(FlowControlStopper Self);

void JB_flow_SyntaxUsingComplete(FlowControlStopper Self, JB_Object* Dummy);



// FunctionType
bool SC_FunctionType_SyntaxIs(FunctionType Self, FunctionType T);



// Ind


// IntRange
bool JB_Rg_Contains1(IntRange Self, int I);



// MaybeBool


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


// Plane3D


// ProcessMode


// SCBlockage
int SC_SCBlockage_BlockCombine(SCBlockage Self, SCBlockage B);

bool SC_SCBlockage_SyntaxIs(SCBlockage Self, SCBlockage B);



// SCDeclInfo
SCDeclInfo SC_SCDeclInfo_Set(SCDeclInfo Self, SCDeclInfo D, bool B);

bool SC_SCDeclInfo_SyntaxIs(SCDeclInfo Self, SCDeclInfo D);



// SCNodeFindMode
bool SC_SCNodeFindMode_SyntaxIs(SCNodeFindMode Self, SCNodeFindMode M);

int SC_SCNodeFindMode__Init_();



// SCNodeInfo


// SCNodeType
bool SC_SCNodeType_HasASMPtrs(SCNodeType Self);

bool SC_SCNodeType_HasPtrs(SCNodeType Self);

bool SC_SCNodeType_SyntaxIs(SCNodeType Self, SCNodeType D);



// SizeInt


// SortComparison


// Syntax
void JB_Syx_ExportAddrSet(Syntax Self, FP_fpMsgRender Value);

FP_fpMsgRender JB_Syx_ExportAddr(Syntax Self);

bool JB_Syx_IsList(Syntax Self);

bool JB_Syx_IsString(Syntax Self);

bool JB_Syx_ListViewable(Syntax Self);

JB_String* JB_Syx_LongName(Syntax Self);

Message* JB_Syx_Msg(Syntax Self, JB_String* Name);

JB_String* JB_Syx_Name(Syntax Self);

SyntaxObj* JB_Syx_Obj(Syntax Self);

Message* JB_Syx_PlusNum(Syntax Self, int64 M);

FP_fpMsgRender JB_Syx_RenderAddr(Syntax Self);

bool JB_Syx_Translateable(Syntax Self);

Syntax JB_Syx__Func(JB_String* Name, Message* Where);

int JB_Syx__Init_();

Syntax JB_Syx__StdNew(FP_fpMsgRender Msg, JB_String* Name, JB_String* LongName, int ID);



// TaskState


// TerminalColor
JB_String* JB_TerminalColor_Colorise(TerminalColor Self, JB_String* S);

JB_String* JB_TerminalColor_Render(TerminalColor Self, FastString* Fs_in);

int JB_TerminalColor__Init_();



// jbinLeaver


// mat2


// µParam
int SC_xC2xB5Param_BitSize(uint /*MuParam*/ Self);

bool SC_xC2xB5Param_IsReg(uint /*MuParam*/ Self);

bool SC_xC2xB5Param_SyntaxIs(uint /*MuParam*/ Self, uint /*MuParam*/ P);



// ASM_AddAK
ASM* SC_ASM_AddAK__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_AddB
ASM* SC_ASM_AddB__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_AddK
ASM* SC_ASM_AddK__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_AddOrSubM
ASM* SC_ASM_AddOrSubM__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Alloc
ASM* SC_ASM_Alloc__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_BFLD
ASM* SC_ASM_BFLD__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_BFLS
ASM* SC_ASM_BFLS__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Bra
ASM* SC_ASM_Bra__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_CNTC
ASM* SC_ASM_CNTC__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_CmpF
ASM* SC_ASM_CmpF__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_CmpI
ASM* SC_ASM_CmpI__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Compare4
ASM* SC_ASM_Compare4__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_ConstStretchy
ASM* SC_ASM_ConstStretchy__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Convert
ASM* SC_ASM_Convert__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Div
ASM* SC_ASM_Div__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Div2
ASM* SC_ASM_Div2__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Float
ASM* SC_ASM_Float__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_FloatConst
ASM* SC_ASM_FloatConst__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_ForeignFunc
ASM* SC_ASM_ForeignFunc__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Func
ASM* SC_ASM_Func__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_FuncAddr
ASM* SC_ASM_FuncAddr__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_GObj
ASM* SC_ASM_GObj__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_GTable
ASM* SC_ASM_GTable__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_HALT
ASM* SC_ASM_HALT__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_JCmpEq
ASM* SC_ASM_JCmpEq__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_JCmpF
ASM* SC_ASM_JCmpF__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_JCmpI
ASM* SC_ASM_JCmpI__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_JCmpK
ASM* SC_ASM_JCmpK__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Jump
ASM* SC_ASM_Jump__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Loop
ASM* SC_ASM_Loop__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_MemUtil
ASM* SC_ASM_MemUtil__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_MemoryCopy
ASM* SC_ASM_MemoryCopy__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_REQ
ASM* SC_ASM_REQ__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_RET
ASM* SC_ASM_RET__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Read
ASM* SC_ASM_Read__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_RefDecrMem
ASM* SC_ASM_RefDecrMem__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_RefReturn
ASM* SC_ASM_RefReturn__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_RefSet1
ASM* SC_ASM_RefSet1__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_RefSet2
ASM* SC_ASM_RefSet2__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_RefSet3
ASM* SC_ASM_RefSet3__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_RefSetApart
ASM* SC_ASM_RefSetApart__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_RotateConst
ASM* SC_ASM_RotateConst__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Shift
ASM* SC_ASM_Shift__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Swap
ASM* SC_ASM_Swap__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_TERN
ASM* SC_ASM_TERN__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Tail
ASM* SC_ASM_Tail__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Trap
ASM* SC_ASM_Trap__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_U0
ASM* SC_ASM_U0__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_U1
ASM* SC_ASM_U1__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_U2
ASM* SC_ASM_U2__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_U3
ASM* SC_ASM_U3__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_U4
ASM* SC_ASM_U4__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_VecBuild
ASM* SC_ASM_VecBuild__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_VecConst
ASM* SC_ASM_VecConst__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_VecGet
ASM* SC_ASM_VecGet__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_VecInc
ASM* SC_ASM_VecInc__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_VecMix
ASM* SC_ASM_VecMix__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_VecSet
ASM* SC_ASM_VecSet__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_VecSwizzle
ASM* SC_ASM_VecSwizzle__Encode(FatASM* Self, ASM* Curr, ASM* After);



// ASM_Write
ASM* SC_ASM_Write__Encode(FatASM* Self, ASM* Curr, ASM* After);



// Duration
float JB_Duration_Float(JB_Duration Self);



// HumanDate


// JB_ASMState


// JB_ArchonPurger
void SC_nil_BecomeRealSub(ArchonPurger* Self, SCDecl* V);

int SC_nil_BranchDepth(ArchonPurger* Self);

NilRecord SC_nil_BranchEnter(ArchonPurger* Self, Message* Where);

NilState SC_nil_BranchExit(ArchonPurger* Self, NilRecord A);

NilState SC_nil_BranchExitBool(ArchonPurger* Self, NilRecord A, NilCheckMode Test, NilRecord Orig);

NilState SC_nil_BranchRestore(ArchonPurger* Self, NilRecord A);

NilRecord SC_nil_BranchSwap(ArchonPurger* Self, NilRecord A);

void SC_nil_CheckNilCheck(ArchonPurger* Self, SCFunction* F);

NilState SC_nil_Declare(ArchonPurger* Self, SCDecl* D, uint /*NilState*/ Nd, Message* ToClose);

NilState SC_nil_DeclareSub(ArchonPurger* Self, SCDecl* D, uint /*NilState*/ Nd, Message* ToClose);

void SC_nil_Destructor(ArchonPurger* Self);

void SC_nil_FinishNil(ArchonPurger* Self, SCFunction* F);

NilState SC_nil_Self(ArchonPurger* Self);

Message* SC_nil_StartNil(ArchonPurger* Self, SCFunction* F);

NilRecord SC_nil_Value(ArchonPurger* Self);

void SC_nil_ValueSet(ArchonPurger* Self, NilRecord Dest);

NilState SC_nil__Access(Message* Msg, NilCheckMode Test);

NilState SC_nil__Arel(Message* Msg, NilCheckMode Test);

NilState SC_nil__Argument(Message* Msg, NilCheckMode Test);

NilState SC_nil__BecomeReal(SCDecl* Sent, Message* Where, uint /*NilReason*/ Reason, SCDecl* Recv, SCFunction* To);

NilState SC_nil__BecomeRealSub(SCDecl* Sent, Message* Where, uint /*NilReason*/ Reason, SCDecl* Recv, SCFunction* To, uint /*NilState*/ Curr);

void SC_nil__BeginLoop(bool HasExitCond, LoopInfo* Rz);

NilState SC_nil__BooleanLogic(Message* Msg, NilCheckMode Test);

NilState SC_nil__Bracket(Message* Msg, NilCheckMode Test);

NilState SC_nil__Brel(Message* Msg, NilCheckMode Test);

NilState SC_nil__Char(Message* Msg, NilCheckMode Test);

NilState SC_nil__CompareObjs(Message* Ll, Message* Rr, NilCheckMode Test, SCOperator* Scop);

NilState SC_nil__Continue(Message* Msg, NilCheckMode Test);

NilState SC_nil__Declaration(Message* Msg, NilCheckMode Test);

void SC_nil__DeclKill();

NilState SC_nil__DetectStillChecks(Message* First);

NilState SC_nil__Dummy(Message* Msg, NilCheckMode Test);

NilRecord SC_nil__EndBlock();

NilState SC_nil__Exit(Message* Msg, NilCheckMode Test);

void SC_nil__ExterminateZergBugs(SCFunction* F);

NilState SC_nil__Fail(Message* Msg, NilCheckMode Test);

NilState SC_nil__FailedReal(SCFunction* To, Message* Where, uint /*NilReason*/ Reason, uint /*NilState*/ State);

NilState SC_nil__If(Message* Msg, NilCheckMode Test);

NilState SC_nil__Ignore(Message* Msg, NilCheckMode Test);

int SC_nil__Init_();

int SC_nil__InitCode_();

NilState SC_nil__Item(Message* Msg, NilCheckMode Test);

NilState SC_nil__FlowJump(Message* Msg, NilCheckMode Test);

NilState SC_nil__JumpWithinBool(Message* Msg, NilCheckMode Test);

void SC_nil__LaunchMothership();

void SC_nil__LaunchMothershipSub(JB_ErrorReceiver* Old, JB_ErrorReceiver* Rec);

NilState SC_nil__List(Message* Msg, NilCheckMode Test);

NilState SC_nil__NilFunction(Message* Msg, NilCheckMode Test);

void SC_nil__NilParamPass(SCDecl* Recv, SCDecl* Sent, Message* Where, SCFunction* F, uint /*NilState*/ V);

NilState SC_nil__Not(Message* Msg, NilCheckMode Test);

NilState SC_nil__Number(Message* Msg, NilCheckMode Test);

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

NilRecord SC_nil__Value();

NilState SC_nil__VariableSet(SCDecl* Recv, Message* RecvMsg, SCDecl* Sent, Message* SentMsg, uint /*NilState*/ SentState);

NilState SC_nil__While(Message* Msg, NilCheckMode Test);



// JB_ArgArrayCounter
void SC_ArgArrayCounter_Check(ArgArrayCounter* Self, Message* Exp);

Message* SC_ArgArrayCounter_Do(ArgArrayCounter* Self, JB_String* Name, Message* Item, SCNode* Name_space);



// JB_AtomicLock


// JB_CakeStack


// JB_CakeVM


// JB_ClassData
JB_MemoryLayer* JB_ClassData_CreateLayerAndUse(JB_Class* Self, JB_Object* Obj, JB_Object* Obj2);



// JB_CompressionStats
JB_Duration JB_MzSt_Durr(CompressionStats* Self);

void JB_MzSt_LiveUpdate(CompressionStats* Self, int In, int Out);

JB_String* JB_MzSt_Report(CompressionStats* Self, FastString* Fs_in);

CompressionStats* JB_MzSt_Start(CompressionStats* Self, int Purpose);

int JB_MzSt__Init_();



// JB_DDA_Caster


// JB_DeclAlterable


// JB_DirectoryReader


// JB_DynamicLibrary
void JB_dylib__New(JB_String* F, int Mode, JB_Dylib* Rz);



// JB_FastBuff
byte* JB_FastBuff_Clip(FastBuff* Self, int V, int Reduce);

int JB_FastBuff_CopyTo(FastBuff* Self, byte* Dest, int Length);

void JB_FastBuff_Destructor(FastBuff* Self);

bool JB_FastBuff_Has(FastBuff* Self, int N);

int JB_FastBuff_Length(FastBuff* Self);

void JB_FastBuff_PositionSet(FastBuff* Self, int Value);

void JB_FastBuff_ReadFromSet(FastBuff* Self, JB_String* Value);

int JB_FastBuff_Size(FastBuff* Self);

JB_String* JB_FastBuff_AccessStr(FastBuff* Self, int Pos, int After);

void JB_FastBuff_SyntaxExpect(FastBuff* Self, JB_String* S);



// JB_FatASM
ASMReg SC_FAT_ASMReg(FatASM* Self, int A);

int SC_FAT_BaseOp(FatASM* Self);

bool SC_FAT_CanCloseRegs(FatASM* Self, int R);

bool SC_FAT_CanMarkSomething(FatASM* Self, Message* Exp, ASMReg Declared, SCDecl* Ty);

void SC_FAT_CheckHasOutput(FatASM* Self);

int64 SC_FAT_Const(FatASM* Self);

void SC_FAT_ConstSet(FatASM* Self, int64 Value);

ASMReg SC_FAT_ConstFill(FatASM* Self, ASMReg Dest, int64 K);

void SC_FAT_ConstFinish(FatASM* Self);

bool SC_FAT_CopyFrom(FatASM* Self, FatASM* D);

void SC_FAT_DebugPrint(FatASM* Self);

ASMReg SC_FAT_Dest(FatASM* Self, uint A, ASMReg Info, Assembler* Sh);

float SC_FAT_F32(FatASM* Self);

Float64 SC_FAT_F64(FatASM* Self);

void SC_FAT_FillLabelRequest(FatASM* Self, ASM* Start, ASM* After, int Reg);

FatASM* SC_FAT_FindOlder(FatASM* Self);

int64 SC_FAT_FloatConvConst(FatASM* Self, int DestBitSize);

int64 SC_FAT_FloatIntConvConst(FatASM* Self, uint /*DataTypeCode*/ Src, uint /*DataTypeCode*/ Dest);

uint64 SC_FAT_FuncPrms(FatASM* Self, SCFunction* Fn);

int SC_FAT_GuessSize(FatASM* Self);

ASM* SC_FAT_Halt_Encoder(FatASM* Self, ASM* Curr, ASM* After);

uint SC_FAT_Index(FatASM* Self);

FatASM* SC_FAT_InputFat(FatASM* Self, int I);

ASMReg SC_FAT_IsDecr(FatASM* Self);

bool SC_FAT_IsFinisherWithReg(FatASM* Self, ASMReg Info);

bool SC_FAT_IsFinisherWith0(FatASM* Self);

bool SC_FAT_IsFunc(FatASM* Self);

bool SC_FAT_IsRead(FatASM* Self);

int SC_FAT_Jump(FatASM* Self);

void SC_FAT_JumpFix(FatASM* Self, FatASM* Curr);

bool SC_FAT_JumpImprove(FatASM* Self, Assembler* Sh);

void SC_FAT_JumpInputSet(FatASM* Self, int A, int V);

void SC_FAT_JumpNegateWith0(FatASM* Self);

bool SC_FAT_JumpNegateWithPacFat(FatASM* Self, Assembler* Sh, FatASM* Mid);

FatASM* SC_FAT_JumpTo(FatASM* Self);

void SC_FAT_JumpToSet(FatASM* Self, FatASM* Value);

ASM* SC_FAT_KNST_Encoder(FatASM* Self, ASM* Curr, ASM* After);

ASM* SC_FAT_Nop_Encoder(FatASM* Self, ASM* Curr, ASM* After);

void SC_FAT_NumInputSet(FatASM* Self, int A, int V);

byte SC_FAT_Op(FatASM* Self);

bool SC_FAT_OperatorIsa(FatASM* Self, ASM M);

ASMReg SC_FAT_AsReg(FatASM* Self, ASMReg Flags);

ASMParam SC_FAT_Output(FatASM* Self);

void SC_FAT_OutputDebugVars(FatASM* Self);

ASMParam SC_FAT_p0(FatASM* Self);

ASMParam SC_FAT_p1(FatASM* Self);

void SC_FAT_p1Set(FatASM* Self, uint Value);

ASMParam SC_FAT_p2(FatASM* Self);

void SC_FAT_p2Set(FatASM* Self, uint Value);

ASMParam SC_FAT_p3(FatASM* Self);

void SC_FAT_p3Set(FatASM* Self, uint Value);

void SC_FAT_PrmCollectCounterPart(FatASM* Self, FastString* Fs);

void SC_FAT_Prm(FatASM* Self, int A, ASMReg Value);

int SC_FAT_RegOnly(FatASM* Self, int I);

void SC_FAT_RendaKnst(FatASM* Self, FastString* Fs, int Sofar);

void SC_FAT_RenderFat(FatASM* Self, FastString* Fs, bool Simpler);

bool SC_FAT_RotateConst(FatASM* Self, uint64 V);

void SC_FAT_SetOpSet(FatASM* Self, uint /*byte*/ Value);

bool SC_FAT_SimpleConst(FatASM* Self, uint64 V, int Space);

ASMReg SC_FAT_SyntaxCall(FatASM* Self, uint I);

void SC_FAT_SyntaxExpect(FatASM* Self, JB_String* Error);

bool SC_FAT_SyntaxIs(FatASM* Self, ASMReg Flags);

void SC_FAT_SyntaxIsSet(FatASM* Self, ASMReg Flags, bool Value);

ASMReg SC_FAT_Vectorise(FatASM* Self, ASMReg Dest, ASM VOpp);

ASMReg SC_FAT_VectoriseSmall(FatASM* Self, ASMReg Dest, ASM VOpp, ASM SOpp);

bool SC_FAT_WillRenderFat(FatASM* Self);

bool SC_FAT__VerifyNumbers();



// JB_FatRange
bool SC_FatRange_Always(FatRange* Self);

void SC_FatRange_JumpTo(FatRange* Self, FatASM* Curr);

int SC_FatRange_Length(FatRange* Self);

bool SC_FatRange_Never(FatRange* Self);



// JB_FloatRange


// JB_HairyMan
bool SC_HairyMan_AddOrShrink(HairyMan* Self, FastString* J, SCFunction* F);

void SC_HairyMan_Churn(HairyMan* Self, FastString* Fs);



// JB_InlineInfo
void SC_InlineInfo_CleanupClash(InlineInfo* Self, Array* Args);

void SC_InlineInfo_ClearInlineParamClash(InlineInfo* Self, Array* Args, int AR, int AN);

void SC_InlineInfo_DoImmediates(InlineInfo* Self, Message* P, Array* Args);

void SC_InlineInfo_NopParams(InlineInfo* Self, int N, ASMReg Ret);

ASMReg SC_InlineInfo_PreInlineOneParam(InlineInfo* Self, Message* P, SCDecl* A, Assembler* Sh);



// JB_IntDownRange


// JB_IsaTester
int SC_IsaTester__Init_();

void SC_IsaTester__SyntaxAppend(Message* O);



// JB_LeakTester
void JB_Lk_Destructor(LeakTester* Self);

void JB_Lk_Test(LeakTester* Self);

void JB_Lk__New(JB_String* Name, LeakTester* Rz);



// JB_LoopInfo
void SC_LoopInfo_BeginLoop(LoopInfo* Self, bool HasExitCond);

void SC_LoopInfo_FinishLoop(LoopInfo* Self, Message* Msg);

void SC_LoopInfo_NextLoop(LoopInfo* Self);



// JB_Mat4


// JB_MemoryWorld


// JB_MessagePosition
void JB_MsgPos_Destructor(MessagePosition* Self);

void JB_MsgPos_SyntaxUsingComplete(MessagePosition* Self, JB_Object* Idk);



// JB_NilRecorder
void SC_NRC_SyntaxCallSet(NilRecorder* Self, uint64 Item, uint64 Value);



// JB_Object_Behaviour


// JB_ParserLineAndIndent
int JB_ParserLineAndIndent_ArgPos(ParserLineAndIndent* Self);



// JB_Pico
JB_String* JB_Pico_Get(PicoComms* Self, float T);

bool JB_Pico_SendString(PicoComms* Self, JB_String* Str, bool Wait);

SpdProcess* JB_Pico_UseAsParent(PicoComms* Self);

PicoComms* JB_Pico__New(JB_StringC* Name, int Noise);



// JB_PicoConfig


// JB_PicoGlobalConfig


// JB_PicoGlobalStats


// JB_PicoMessage


// JB_RandomXOR
float JB_Rnd_Float(RandomXOR* Self);

int64 JB_Rnd_RndInt(RandomXOR* Self);

void JB_Rnd_SeedSet(RandomXOR* Self, uint64 Value);

void JB_Rnd_TimeSeed(RandomXOR* Self);

int JB_Rnd__InitCode_();



// JB_RegFile


// JB_RetroFloat


// JB_StructWithObj


// JB_TerminalDisplay
void JB_TerminalDisplay_Beep(TerminalDisplay* Self);

void JB_TerminalDisplay_Destructor(TerminalDisplay* Self);

void JB_TerminalDisplay_Display(TerminalDisplay* Self);

void JB_TerminalDisplay_DrawRect(TerminalDisplay* Self, ivec4 Rect, JB_String* Inside, TerminalColor Colors);

JB_String* JB_TerminalDisplay_Flat(TerminalDisplay* Self);

void JB_TerminalDisplay_FrameText(TerminalDisplay* Self, JB_String* S, ivec4 Frame, TerminalColor FrameCol, TerminalColor TextCol);

void JB_TerminalDisplay_SyntaxAppend(TerminalDisplay* Self, JB_String* Text, ivec2 V, TerminalColor Colors);



// JB_VirtualJBString


// JB_Array_Behaviour


// JB_Assembler
ASMReg SC_Pac_AddConst(Assembler* Self, int Add, Message* Exp, ASMReg Base);

void SC_Pac_AddFuncParams(Assembler* Self, SCFunction* Fn);

ASMReg SC_Pac_AddToReg(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg Orig, int64 Amount);

ASMReg SC_Pac_AlreadyABool(Assembler* Self, ASMReg L, ASMReg Zero);

ASMReg SC_Pac_AskForInline(Assembler* Self, Message* Prms, ASMReg Dest, SCFunction* Fn);

void SC_Pac_AskNop(Assembler* Self, FatASM* ToNop);

void SC_Pac_AskNopTemp(Assembler* Self, ASMReg R);

ASMReg SC_Pac_ASMBoolMaker(Assembler* Self, Message* Exp, ASMReg Dest, OpMode Opp);

void SC_Pac_ASMInit(Assembler* Self);

void SC_Pac_ASMReach(Assembler* Self, SCFunction* Fn);

ASMReg SC_Pac_Assign(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg Src);

void SC_Pac_BackCond(Assembler* Self, FatASM* Start);

ASMReg SC_Pac_BFLG(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg Src, int Up, int Down);

ASMReg SC_Pac_BFLG_Sub(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg Src, int Up, int Down, bool Sign);

ASMReg SC_Pac_BitAnd(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_BitAndNop(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_BitMaker(Assembler* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp, ASM Opp, ASM VOpp);

ASMReg SC_Pac_BitNot(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_BitOr(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_BitXor(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_BoolAndOrOpt(Assembler* Self, Message* A, Message* B, ASMReg Dest, OpMode Opp);

ASMReg SC_Pac_BoolAndOrValue(Assembler* Self, Message* A, Message* B, ASMReg Dest, OpMode Opp);

ASMReg SC_Pac_BoolAndOrValueSub(Assembler* Self, Message* A, Message* B, ASMReg Dest, OpMode Opp);

ASMReg SC_Pac_BoolConst1(Assembler* Self, Message* B, ASMReg Dest, OpMode Opp, ASMReg Ml);

ASMReg SC_Pac_BoolConst2(Assembler* Self, ASMReg Ml, ASMReg Kr, OpMode Opp, FatASM* Jump);

ASMReg SC_Pac_BoolMul(Assembler* Self, ASMReg Dest, ASMReg Bule, ASMReg V, Message* Exp);

FatASM* SC_Pac_BoolTestAndJump(Assembler* Self, Message* Exp, ASMReg Req, OpMode Opp);

ASMReg SC_Pac_Branch(Assembler* Self, Message* Cond, FatRange* Range, bool Neg);

ASMReg SC_Pac_BranchAnd(Assembler* Self, Message* A, Message* B, ASMReg Dest);

ASMReg SC_Pac_BranchOr(Assembler* Self, Message* A, Message* B, ASMReg Dest);

void SC_Pac_BranchToCurr(Assembler* Self, FatRange* Range);

ASMReg SC_Pac_CallFunc(Assembler* Self, Message* Exp, ASMReg Dest, SCFunction* Fn);

bool SC_Pac_CanAddK(Assembler* Self, ASMReg R, int64 T);

int SC_Pac_CanBAND_BFLG(Assembler* Self, ASMReg R);

Ind SC_Pac_CanMergeBits(Assembler* Self, int UpA, int DownA, int UpB, int DownB, int Total);

FatASM* SC_Pac_CanOptDecr(Assembler* Self, ASMReg Obj, FatASM* Last);

void SC_Pac_CapASM(Assembler* Self);

bool SC_Pac_ClearAllStructs(Assembler* Self, Message* Exp);

void SC_Pac_ClearGRABbedAndTrampled(Assembler* Self, Message* Prms, ASMReg Dest, FatASM* Start);

bool SC_Pac_ClearStruct(Assembler* Self, Message* Exp, FatASM* Fat, int V);

bool SC_Pac_CloseOneVar(Assembler* Self, Message* Exp, uint Missing);

ASMReg SC_Pac_CloseVars(Assembler* Self, uint64 Orig, Message* Exp, ASMReg Return);

ASMReg SC_Pac_Compare(Assembler* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp, int Mode);

ASMReg SC_Pac_CompareFloat(Assembler* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp, int Mode);

ASMReg SC_Pac_CompareInt(Assembler* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp, int Mode);

Ind SC_Pac_Const(Assembler* Self, ASMReg R, int Bits, bool Signed);

ASMReg SC_Pac_ConstCompareFloat(Assembler* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp, int Mode);

bool SC_Pac_ConstCompareFloatSub(Assembler* Self, ASMReg L, ASMReg R, int Mode);

ASMReg SC_Pac_ConstCompareInt(Assembler* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp, int Mode);

bool SC_Pac_ConstCompareIntSub(Assembler* Self, ASMReg L, ASMReg R, int Mode);

ASMReg SC_Pac_Continue(Assembler* Self, Message* Exp, ASMReg Dest);

FatASM* SC_Pac_CopyMemory(Assembler* Self, int Index, Message* Exp, ASMReg Src, ASMReg Dest, ASMReg Vara, SCDecl* D);

FatASM* SC_Pac_Curr(Assembler* Self);

int SC_Pac_CurrGain(Assembler* Self, FatASM* Start);

ASMReg SC_Pac_DeclareBody(Assembler* Self, Message* Where, SCDecl* Type);

ASMReg SC_Pac_DeclareMe(Assembler* Self, Message* Where, ASMReg V);

ASMReg SC_Pac_DeclareVar(Assembler* Self, Message* Where, SCDecl* Type);

void SC_Pac_DeclReset(Assembler* Self, SCDecl* D);

void SC_Pac_Decr(Assembler* Self, FatASM* F, bool Soft, int Depth);

ASMReg SC_Pac_DecrObj(Assembler* Self);

ASMReg SC_Pac_DivFloat(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_Divide(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_DivInt(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_DoIntrinsic(Assembler* Self, Message* Where, ASMReg Dest, SCFunction* Fn, Message* Trin);

ASMReg SC_Pac_DoMath(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_Pac_DoMathSub(Assembler* Self, Message* Exp, ASMReg Mode, fn_OpASM Fn);

ASMReg SC_Pac_DotAddr(Assembler* Self, Message* Exp, ASMReg Dest, int Pos, SCDecl* Prop, ASMReg Obj);

void SC_Pac_Dummy(Assembler* Self, Message* Exp);

ASMReg SC_Pac_ElseSub(Assembler* Self, Message* Other);

ASMReg SC_Pac_Equals(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_EqualsInt(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_EqualsSame(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_ExistingVar(Assembler* Self, Message* M);

ASMReg SC_Pac_Exit(Assembler* Self, Message* Exp, ASMReg Dest);

bool SC_Pac_FatterCompile(Assembler* Self, SCFunction* Fn);

void SC_Pac_FillDebugInfo(Assembler* Self);

Ind SC_Pac_FillTheFat(Assembler* Self, ASMReg* Collection, FatASM* Fat, Message* Prms, int N);

void SC_Pac_FinishASM(Assembler* Self);

void SC_Pac_FinishMost(Assembler* Self);

void SC_Pac_FinishReturn(Assembler* Self);

ASMReg SC_Pac_FinishSingleIf(Assembler* Self, FatRange* B);

ASMReg SC_Pac_FloatMul(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_FloatPlus(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

SCFunction* SC_Pac_fn(Assembler* Self);

int SC_Pac_FnLength(Assembler* Self);

bool SC_Pac_FoundReg(Assembler* Self, Message* All, int R);

void SC_Pac_Fries(Assembler* Self, ASMReg* Collection, FatASM* Fat, Message* S, int I, int MaxParam);

FatASM* SC_Pac_FuncStart(Assembler* Self);

ASMReg SC_Pac_GlobAddr(Assembler* Self, SCDecl* D, Message* Exp, ASMReg Dest);

void SC_Pac_Guard(Assembler* Self);

ASMReg SC_Pac_If(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_Pac_IfSub(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_Pac_InbuiltTernary(Assembler* Self, ASMReg Dest, ASMReg A, ASMReg B, Message* Cond);

ASMReg SC_Pac_IncrPointerByVar(Assembler* Self, ASMReg Dest, ASMReg Base, ASMReg Vara, Message* Exp);

ASMReg SC_Pac_IncrPost(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg Src, int64 Value);

ASMReg SC_Pac_IncrPre(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg Src, int64 Value);

ASMReg SC_Pac_IncrVectorPart(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg Src, int64 Value, int Mode);

int SC_Pac_Index(Assembler* Self);

void SC_Pac_InitAndStartFunc(Assembler* Self, SCFunction* Fn);

bool SC_Pac_InlineAddK(Assembler* Self, ASMReg XIn, int64 Add, ASMReg XOut);

ASMReg SC_Pac_InlineFinish(Assembler* Self, FatRange* R);

ASMReg SC_Pac_InlineOffsetOpt(Assembler* Self, ASMReg Base, int Bytes, int& Index, uint MaxBits, SCDecl* Decl, Message* Exp);

void SC_Pac_InlineParameters(Assembler* Self, Message* Prms, InlineInfo* Info);

ASMReg SC_Pac_IntMul(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_IntPlus(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

FailableInt SC_Pac_IntPowerOfTwo(Assembler* Self, ASMReg R, int Sub);

bool SC_Pac_IsASMConst(Assembler* Self, Message* Exp);

bool SC_Pac_IsCurr(Assembler* Self, FatASM* F);

ASMReg SC_Pac_IsOnlyVarThatWeReturn(Assembler* Self, SCDecl* D);

ASMReg SC_Pac_JumpIntK(Assembler* Self, ASMReg Dest, ASMReg L, ASMReg R, Message* Exp, uint Mode);

ASMReg SC_Pac_Killed(Assembler* Self, Message* Exp, FatASM* Fat);

void SC_Pac_KnownValuesSet(Assembler* Self, int Changed, bool Value);

void SC_Pac_Knst(Assembler* Self, ASM Op);

FatASM* SC_Pac_LastWith0(Assembler* Self);

FatASM* SC_Pac_LastWithAsm(Assembler* Self, ASM Type);

FatASM* SC_Pac_Last(Assembler* Self, ASM Type, ASM Type2);

ASMReg SC_Pac_Less(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_LessEq(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_LoadNumber(Assembler* Self, Message* Exp, int64 V, bool Special, ASMReg Dest);

ASMReg SC_Pac_LocalThg(Assembler* Self, SCDecl* D);

void SC_Pac_LoopFill(Assembler* Self, FatASM* C, FatASM* S, FatASM* A);

ASMReg SC_Pac_MakeConstFromTwo(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R, fn_ASMConstifier Fn);

void SC_Pac_MarkVarClosed(Assembler* Self, int RegBits);

ASMReg SC_Pac_MarkVarOpen(Assembler* Self, Message* Exp, ASMReg Declared, SCDecl* Ty, FatASM* Start);

ASMReg SC_Pac_MegaNumFinder(Assembler* Self, int64 V, bool Special, uint /*DataTypeCode*/ Type);

ASMReg SC_Pac_MemOffsetFix(Assembler* Self, ASMReg Base, int Pow2, int& Index, uint MaxBits, SCDecl* Glob, Message* Exp);

int SC_Pac_MemOpt(Assembler* Self, ASMReg& Base, int& Index, int Bytes);

ASMReg SC_Pac_MergeBFLG(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg Src, uint upB, uint downB, int SignB);

ASMReg SC_Pac_MiniBFLS(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_MiniBOR(Assembler* Self, ASMReg L, ASMReg R);

ASMReg SC_Pac_MiniClampOpt(Assembler* Self, Message* Exp, FatASM* Compare);

ASMReg SC_Pac_Minus(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_Mod(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_ModFloat(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_ModInt(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_More(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_MoreEq(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

FatASM* SC_Pac_MUL_(Assembler* Self, ASMReg Dest, ASMReg A, ASMReg B, ASMReg Add, Message* Exp);

ASMReg SC_Pac_Multiply(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

void SC_Pac_NextBasicBlock(Assembler* Self);

void SC_Pac_Nop(Assembler* Self, FatASM* ToNop);

void SC_Pac_Nop2Consts(Assembler* Self, ASMReg A, ASMReg B);

void SC_Pac_nop_sub(Assembler* Self, FatASM* Fat, bool Soft, int Depth);

bool SC_Pac_NopConstWithRegInt64(Assembler* Self, ASMReg R, int64 K);

void SC_Pac_NopConstWithReg(Assembler* Self, ASMReg R);

void SC_Pac_NopRange(Assembler* Self, FatASM* Start, FatASM* After, bool Soft);

void SC_Pac_NopReg(Assembler* Self, ASMReg R);

ASMReg SC_Pac_NotEq(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_NumToReg(Assembler* Self, Message* Exp, ASMReg Reg, int64 K, uint /*DataTypeCode*/ SrcType);

uint64 SC_Pac_OpenVars(Assembler* Self);

ASMReg SC_Pac_PackGlobAddr(Assembler* Self, SCDecl* D, Message* Exp, ASMReg Dest, int64 ExportPos);

ASMReg SC_Pac_Plus(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_PlusSub(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

uint64 SC_Pac_PrmCollect(Assembler* Self, Message* Prms, SCFunction* Fn);

uint64 SC_Pac_PrmCollectSpd(Assembler* Self, Message* Prms, SCFunction* Fn);

ASMReg SC_Pac_Quick1Or1Sub(Assembler* Self, ASMReg Dest, ASMReg L, int Ptoi, Message* Exp);

ASMReg SC_Pac_QuickFloat32Plus(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_QuickFloatDiv(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_QuickFloatMul(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_QuickFloatPlusConstSub(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_QuickIntDiv(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_QuickIntMul(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_ReadOrWrite(Assembler* Self, ASMReg Dest, Message* Exp, ASMReg Base, ASMReg VarAdd, SCDecl* Ty, int Index);

FatASM* SC_Pac_ReadOrWriteSub(Assembler* Self, ASMReg Dest, Message* Exp, ASMReg Base, ASMReg VarAdd, SCDecl* Decl, int Index);

ASMReg SC_Pac_RealTernary(Assembler* Self, Message* Exp, ASMReg Dest, Message* A, Message* B, FatRange* Branch);

ASMReg SC_Pac_ReDestWithFatReg(Assembler* Self, FatASM* F, ASMReg Dest);

ASMReg SC_Pac_ReDestWithFatRegUint(Assembler* Self, FatASM* F, ASMReg Dest, uint A);

ASMReg SC_Pac_RefCount(Assembler* Self, Message* Exp, ASMReg Dest);

FatASM* SC_Pac_RefCountClear(Assembler* Self, Message* Exp, Message* Prms);

FatASM* SC_Pac_RefCountDecr(Assembler* Self, Message* Exp, Message* Prms, ASMReg Obj);

FatASM* SC_Pac_RefCountIncr(Assembler* Self, Message* Exp, Message* Prms, ASMReg Obj);

FatASM* SC_Pac_RefCountIncr2(Assembler* Self, Message* Exp, Message* Prms);

FatASM* SC_Pac_RefCountSet(Assembler* Self, Message* Exp, Message* Prms);

FatASM* SC_Pac_RefCountSub(Assembler* Self, Message* Exp, Message* Prms, SCFunction* Fn);

void SC_Pac_RegClear(Assembler* Self, Message* Exp, FatASM* C, int I);

bool SC_Pac_RegIsConst(Assembler* Self, ASMReg R, int64 K);

FatASM* SC_Pac_Register(Assembler* Self, int I);

ASMReg SC_Pac_RemoveableBFLG(Assembler* Self, ASMReg Dest, ASMReg A, ASMReg B);

FatASM* SC_Pac_RequestOp(Assembler* Self, ASM Op, Message* Exp);

bool SC_Pac_Rework(Assembler* Self, SCFunction* Fn);

void SC_Pac_RootGen(Assembler* Self, SCFunction* Fn);

ASMReg SC_Pac_SafeDecr(Assembler* Self, ASMReg Match);

ASMReg SC_Pac_SelfDivide(Assembler* Self, ASMReg Dest, Message* Exp);

ASMReg SC_Pac_SetConst(Assembler* Self, Message* Exp, int64 Value, ASMReg Ml, ASMReg Dest);

ASMReg SC_Pac_SetRegister(Assembler* Self, int Changed, ASMReg Info, FatASM* Value);

ASMReg SC_Pac_SHL(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_SHR(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_SmallToBig(Assembler* Self, ASMReg Src, ASMReg Cmp, Message* Exp);

void SC_Pac_SoftNop(Assembler* Self, FatASM* ToNop);

ASMState* SC_Pac_State(Assembler* Self);

ASMReg SC_Pac_Str(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_Pac_Subtract(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg L, ASMReg R);

ASMReg SC_Pac_TempOnly(Assembler* Self, ASMReg T);

ASMReg SC_Pac_TempTypedWithDeclReg(Assembler* Self, SCDecl* Type, ASMReg T);

ASMReg SC_Pac_TempTypedWithMsgReg(Assembler* Self, Message* Where, ASMReg T);

ASMReg SC_Pac_Ternary(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_Pac_TernRefCount(Assembler* Self, ASMReg A, ASMReg B);

ASMReg SC_Pac_TheTrinity(Assembler* Self, Message* SrcPrms, Message* ASMPrms, ASMReg Dest, uint /*byte*/ OpCode);

ASMReg SC_Pac_TryInline(Assembler* Self, Message* Prms, ASMReg Dest, SCFunction* Fn, int AllowedGain);

ASMReg SC_Pac_TryInlineSub(Assembler* Self, Message* Prms, SCFunction* Fn, int AllowedGain, FatRange* LL);

bool SC_Pac_Unchanged(Assembler* Self, Message* A, ASMReg Dest, Message* B);

ASMReg SC_Pac_UniqueLocation(Assembler* Self, Message* A, ASMReg Dest, Message* B);

uint SC_Pac_vdecls(Assembler* Self);

void SC_Pac_vdeclsSet(Assembler* Self, uint Value);

ASMReg SC_Pac_VecAccess(Assembler* Self, Message* Exp, ASMReg Dest, ASMReg Base, ASMReg Vara);

ASMReg SC_Pac_VecSwizzle(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_Pac_VectorLoad(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_Pac_VectorUpgrade(Assembler* Self, ASMReg Src, Message* Exp);

uint SC_Pac_vtemps(Assembler* Self);

void SC_Pac_vtempsSet(Assembler* Self, uint Value);

ASMReg SC_Pac_While(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_Pac_WhileSub(Assembler* Self, Message* Exp);

ASMReg SC_Pac_Zeros(Assembler* Self, ASMReg Info);

ASMReg SC_Pac_xC2xB5(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_Pac_xC2xB5BoolInto(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_Pac_xC2xB5GetReal(Assembler* Self, Message* Exp, ASMReg ModeOnly);

ASMReg SC_Pac_xC2xB5GetRealOffer(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_Pac_xC2xB5InlineParam(Assembler* Self, Message* Exp, SCDecl* A, ASMReg Dest);

ASMReg SC_Pac_xC2xB5Into(Assembler* Self, Message* Exp, ASMReg Dest);

ASMReg SC_Pac_xC2xB5Reffed(Assembler* Self, Message* Exp, SCDecl* A);

ASMReg SC_Pac_xC2xB5Trin(Assembler* Self, Message* Exp);

void SC_Pac__ClassLayout(FastString* J);

void SC_Pac__DebugClassesAndGlobals(FastString* J);

int SC_Pac__Init_();

void adb();



// JB_AutoItem_Behaviour


// JB_CppRefs_Behaviour


// JB_Cpp_Export_Behaviour


// JB_DataObject_Behaviour


// JB_DictionaryReader_Behaviour


// JB_Dictionary_Behaviour


// JB_ErrorReceiver_Behaviour


// JB_FastString_Behaviour


// JB_FixedDict_Behaviour


// JB_FlowControl_Behaviour


// JB_InputStream_Behaviour


// JB_Instruction_Behaviour


// JB_MemoryLayer_Behaviour


// JB_Memory_Behaviour


// JB_SCImport_Behaviour


// JB_SCNodeRenamer_Behaviour


// JB_SCObject_Behaviour


// JB_SCOperator_Behaviour


// JB_SCParamArray_Behaviour


// JB_SavedRegisters
void SC_SavedRegisters_Collect(SavedRegisters* Self, Array* Args, Assembler* Sh);

void SC_SavedRegisters_Restore(SavedRegisters* Self, Array* Args);

void SC_SavedRegisters_Rewind(SavedRegisters* Self, Assembler* Sh);



// JB_Selector_Behaviour


// JB_String_Behaviour


// JB_SyntaxObj_Behaviour


// JB_TokenHandler_Behaviour


// JB_UnixProcess_Behaviour


// JB_Validator_Behaviour


// JB_list_Behaviour


// JB_µForm_Behaviour


// JB_FastStringCpp_Behaviour


// JB_File_Behaviour


// JB_Message_Behaviour


// JB_SCDecl_Behaviour


// JB_SCIterator_Behaviour


// JB_SCNode_Behaviour


// JB_SpdProcess_Behaviour


// JB_StringShared_Behaviour


// JB_StringZeroTerminated_Behaviour


// JB_Task_Behaviour


// JB_Error_Behaviour


// JB_MessageID_Behaviour


// JB_SCArg_Behaviour


// JB_SCBehaviour_Behaviour


// JB_SCBetterNode_Behaviour


// JB_SCFile_Behaviour


// JB_SCClass_Behaviour


// JB_SCFunction_Behaviour


// JB_SCModule_Behaviour


// ASM_Encoder


// CakeChef


// CollectFunc


// ExprResolver


// NilTrackerFn


// ParseHandler


// PicoThreadFn


// ShellOption


// SorterComparer


// SpdDeathActionFn


// Thread


// Thread


// TokenHandler_fp


// TranFunc


// __CopyID__


// __DisplayName__


// __Render__


// __TextSet__


// fnErrorLogger


// fnIDGenerator


// fnPreReader


// fn_ASMConstifier


// fn_OpASM


// fn_asm


// fpMsgRender


// fpMsgRenderCpp


// prototype


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

void JB_Object_FailStr(JB_Object* Self, JB_String* Error);

void JB_Object_Fail(JB_Object* Self);

JB_Object* JB_Object_TypeFailed(JB_Object* Self, JB_Class* Cls, Message* Where);



// JB_Array
void SC_Array_AddCStr(Array* Self, JB_String* S);

void SC_Array_AppendWords(Array* Self, JB_String* R);

int SC_Array_CArraySize(Array* Self, int Size);

void JB_Array_Clear(Array* Self);

void JB_Array_FastRemove(Array* Self, int Pos);

JB_Object* JB_Array_First(Array* Self);

JB_String* JB_Array_join(Array* Self, JB_String* Sep);

JB_String* JB_Array_join_sub(Array* Self, JB_String* Sep, int N);



// JB_AutoItem
AutoItem* SC_AutoItem_ConstructorAuto(AutoItem* Self, JB_String* Sort, JB_String* Insert, SCObject* Value, JB_String* Display, bool Exact, int Type);

int SC_AutoItem_Depth(AutoItem* Self);

void SC_AutoItem_Destructor(AutoItem* Self);

bool SC_AutoItem_OKBy(AutoItem* Self, AutoItem* Prev);

SortComparison SC_AutoItem__Sorter(AutoItem* Self, AutoItem* B);



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

void SC_Cpp_FillLibGlobs(Cpp_Export* Self, FastStringCpp* Fs, bool Simple);

void SC_Cpp_FinalMergeOutputIntoACpp(Cpp_Export* Self);

JB_String* SC_Cpp_FuncHeader(Cpp_Export* Self, SCFunction* F);

void SC_Cpp_FuncStart(Cpp_Export* Self, FastStringCpp* Fs, SCFunction* F, JB_String* Funcheader);

void SC_Cpp_LibAPI_Cpp(Cpp_Export* Self);

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

void SC_Cpp_WriteLibGlobLookup(Cpp_Export* Self, FastStringCpp* Fs);

void SC_Cpp_WriteVMFuncs(Cpp_Export* Self, FastStringCpp* Fs);

void SC_Cpp_WriteVMGlobsAndPtrs(Cpp_Export* Self, FastStringCpp* Fs);

JB_File* SC_Cpp__APIHeader();

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

void SC_Cpp__C_RenderNothing(Message* Self, FastStringCpp* Fs);

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

JB_String* SC_Cpp__CDotType(Message* Msg, SCDecl* Type, FastStringCpp* Fs, bool DoIt);

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

JB_String* SC_Cpp__WriteCppStrings(FastString* Lengths);

void SC_Cpp__WriteDecl(SCDecl* D, FastString* T, Message* Equality);

void SC_Cpp__WriteDeclBrackets(Message* Self, FastStringCpp* Fs);

void SC_Cpp__WriteDeclNoName(SCDecl* D, FastString* T);

void SC_Cpp__WriteFuncArgs(SCFunction* F, FastString* T, bool Names_only);

void SC_Cpp__WriteFuncSub(SCFunction* F, JB_String* E, FastString* T);

void SC_Cpp__WriteFunctionHeader(SCFunction* F, FastStringCpp* T);

void SC_Cpp__WriteName(JB_String* Name, FastString* Blob, FastString* Lengths);

void SC_Cpp__WriteThgMaybeTypeToo(Message* Msg, SCDecl* D, FastStringCpp* Fs);

void SC_Cpp__WriteType(SCClass* C, FastStringCpp* Fs, bool Always);



// JB_DataObject
DTWrap* JB_Wrap_ConstructorInt(DTWrap* Self, int64 V);

DTWrap* JB_Wrap_ConstructorVoidPtr(DTWrap* Self, void* P);

void JB_Wrap_Destructor(DTWrap* Self);

JB_String* JB_Wrap_Render(DTWrap* Self, FastString* Fs_in);



// JB_Dictionary
JB_Object* JB_Dict_Expect(Dictionary* Self, Message* M);

JB_Object* JB_Dict_Obj(Dictionary* Self, JB_Object* Prm);

void JB_Dict_ObjSet(Dictionary* Self, JB_Object* Prm, JB_Object* Value);

void JB_Dict_SetValue(Dictionary* Self, JB_String* Key, int64 Value);

JB_Object* JB_Dict_Value0(Dictionary* Self, JB_String* Key);

void JB_Dict_SetInt(Dictionary* Self, uint64 Key, JB_Object* Value);

JB_Object* JB_Dict_ValueInt(Dictionary* Self, uint64 Key);

JB_Object* JB_Dict_ValueLower(Dictionary* Self, JB_String* S);

void JB_Dict_ValueLowerSet(Dictionary* Self, JB_String* S, JB_Object* Value);

Dictionary* JB_Dict__Copy(Dictionary* Dict);

Dictionary* JB_Dict__Reverse(Dictionary* Dict);



// JB_DictionaryReader
JB_Object* JB_DictionaryReader_NextValue(DictionaryReader* Self);

SCDecl* SC_DictionaryReader_ValueDecl(DictionaryReader* Self);



// JB_ErrorReceiver
bool JB_Rec_CanAddMore(JB_ErrorReceiver* Self, uint /*ErrorSeverity*/ Level);

void JB_Rec_Clear(JB_ErrorReceiver* Self);

JB_ErrorReceiver* JB_Rec_Constructor(JB_ErrorReceiver* Self);

void JB_Rec_Destructor(JB_ErrorReceiver* Self);

bool JB_Rec_HasAnything(JB_ErrorReceiver* Self);

bool JB_Rec_HasProblems(JB_ErrorReceiver* Self);

void JB_Rec_Incr(JB_ErrorReceiver* Self, JB_Error* Err, bool Add);

JB_Error* JB_Rec_LastError(JB_ErrorReceiver* Self);

void JB_Rec_LogFileWriter(JB_ErrorReceiver* Self, JB_String* Data);

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

void JB_Rec__NewCriticalError(Message* Node, JB_String* Desc, JB_String* Path);

void JB_Rec__Latchkum(Message* Node, JB_String* Desc, JB_String* Path);

void JB_Rec__NewErrorSub(Message* Node, JB_String* Desc, JB_String* Path, uint /*ErrorSeverity*/ Sev);

void JB_Rec__NewProblem(Message* Node, JB_String* Desc, JB_String* Path);

void JB_Rec__NewWarning(Message* Node, JB_String* Desc, JB_String* Path);



// JB_FastString
void SC_FS_AppendCpp(FastString* Self, JB_String* S);

void SC_FS_AppendCppAll(FastString* Self, JB_String* S);

void JB_FS_AppendEscape(FastString* Self, JB_String* S);

void JB_FS_AppendHexStr(FastString* Self, JB_String* Data);

void JB_FS_AppendHInt(FastString* Self, int N);

void SC_FS_AppendLibGlob(FastString* Self, SCDecl* D);

void JB_FS_AppendQuotedEscape(FastString* Self, JB_String* S, uint /*byte*/ Quote);

void SC_FS_AppendVoid(FastString* Self, JB_String* S, uint /*byte*/ Extra);

void SC_FS_AppendWidth(FastString* Self, JB_String* S, int Width);

void SC_FS_AppendWrap(FastString* Self, SCFunction* F);

void SC_FS_CArrayAdd(FastString* Self, JB_String* S);

void SC_FS_CArrayAddB(FastString* Self, uint /*byte*/ B);

void SC_FS_CArrayAddB0(FastString* Self, uint /*byte*/ B);

void SC_FS_EncodeLength(FastString* Self, uint64 N);

void JB_FS_AppendInfo(FastString* Self, JB_String* Name, JB_String* Data);

void JB_FS_AppendInfoNum(FastString* Self, JB_String* Name, int64 Data);

void JB_FS_FieldStart(FastString* Self, JB_String* Name);

void SC_FS_IncludeH(FastString* Self, JB_String* Name);

void JB_FS_MemoryReport(FastString* Self, JB_String* Name, int64 Amount);

void JB_FS_MsgErrorName(FastString* Self, JB_String* Name);

void SC_FS_Normal(FastString* Self, JB_String* S);

void JB_FS_PrintNicely(FastString* Self, JB_String* S);

void JB_FS_ProblemsFound(FastString* Self, int Count);

JB_String* JB_FS_Render(FastString* Self, FastString* Fs_in);

void JB_FS_AppendJoin(FastString* Self, Array* Data, JB_String* Sep);

void JB_FS_AppendMultiStr(FastString* Self, JB_String* Data, int Count);

void JB_FS_AppendBuff(FastString* Self, FastBuff* B);

void JB_FS_SyntaxAppend(FastString* Self, Message* Msg);

void JB_FS_Fail(FastString* Self);

FastString* JB_FS__NewFile(JB_File* F);

FastString* JB_FS__UseAsOutput(JB_Object* Other);



// JB_FixedDict


// JB_FlowControl
void JB_Flow_AddByte(FlowControl* Self, uint /*byte*/ Value);

void JB_Flow_Destructor(FlowControl* Self);

void JB_Flow_Fail(FlowControl* Self, JB_String* Found, JB_String* Expected, JB_String* InputName);

void JB_Flow_Flush(FlowControl* Self);

bool JB_Flow_TestByte(FlowControl* Self, uint /*byte*/ Value);

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



// JB_InputStream
Ind JB_SS_Byte(InputStream* Self);

void JB_SS_CompressInto(InputStream* Self, JB_Object* Dest, int Strength, CompressionStats* St);

InputStream* JB_SS_Constructor(InputStream* Self, JB_String* Data);

JB_String* JB_SS_Decompress(InputStream* Self, JB_Object* Dest, uint Limit, CompressionStats* St);

bool JB_SS_DecompressSub(InputStream* Self, FastString* Fs, CompressionStats* St, int OutRemain);

void JB_SS_Destructor(InputStream* Self);

int JB_SS_Eat(InputStream* Self, JB_String* S);

int JB_SS_Find(InputStream* Self, uint /*byte*/ C);

bool JB_SS_HasAny(InputStream* Self);

bool JB_SS_HasHeader(InputStream* Self, JB_String* Header);

int JB_SS_HInt(InputStream* Self);

bool JB_SS_NextChunk(InputStream* Self);

uint64 JB_SS_NextMsgInfo(InputStream* Self);

bool JB_SS_NoMoreChunksToRead(InputStream* Self);

int JB_SS_NonZeroByte(InputStream* Self);

ParserCallBack* JB_SS_ParserCallBack_Constructor(ParserCallBack* Self, InputStream* Upon);

int JB_SS_Position(InputStream* Self);

void JB_SS_PositionSet(InputStream* Self, int Value);

bool JB_SS_ReadChunk(InputStream* Self, JB_File* F);

int JB_SS_Remaining(InputStream* Self);

void JB_SS_Reset(InputStream* Self, JB_String* Data);

JB_String* JB_SS_Str(InputStream* Self, int N, int Skip);

Message* JB_SS_StreamJbin(InputStream* Self, int64 Remain);

void JB_SS_Fail(InputStream* Self, JB_String* Error);

uint64 JB_SS_UInt(InputStream* Self, int Size);



// JB_Instruction
void SC_Instruction_Const(Instruction* Self);

Instruction* SC_Instruction_Constructor(Instruction* Self, JB_String* FormName, JB_String* Name, int Pos);

void SC_Instruction_Destructor(Instruction* Self);

JB_String* SC_Instruction_Render(Instruction* Self, FastString* Fs_in);

void SC_Instruction__Add(JB_String* FormName, JB_String* Name, int Pos);

int SC_Instruction__Init_();

void SC_Instruction__InstructionInit();

Instruction* SC_Instruction__SyntaxAccessWithMsg(Message* M);

Instruction* SC_Instruction__SyntaxAccessWithInt(int Pos);



// JB_Memory
MWrap* JB_Mrap_ConstructorPtr(MWrap* Self, int ItemCount, int ItemSize, byte* Ptr, uint /*byte*/ DeathAction);

int JB_Mrap_CopyFrom(MWrap* Self, void* Src, int Length);

void JB_Mrap_Destructor(MWrap* Self);

void JB_Mrap_LengthSet(MWrap* Self, int Value);

byte* JB_Mrap_NeedSpare(MWrap* Self, int ReqItems, int Extra);

bool JB_Mrap_SetSize(MWrap* Self, int ItemCount);

void JB_Mrap_Zero(MWrap* Self);

Array* SC_Mrap__CollectLeaks_(JB_Object* Self);

int JB_Mrap__Init_();

MWrap* JB_Mrap__Object(int Count, int ItemSize);

void SC_Mrap__PrintLeaks(JB_Object* Self);



// JB_MemoryLayer


// JB_NameTableConcept


// JB_SCImport
bool SC_Imp_CanBan(SCImport* Self, SCFile* Scf);

SCImport* SC_Imp_Constructor(SCImport* Self, JB_File* F, bool Builtin);

void SC_Imp_Destructor(SCImport* Self);

SCFile* SC_Imp_ImportDir(SCImport* Self, JB_File* F);

void SC_Imp_ImportMsg(SCImport* Self, Message* J);

void SC_Imp_ImportMsgSub(SCImport* Self, Message* J);

SCFile* SC_Imp_ImportSpd(SCImport* Self, JB_File* C);

void SC_Imp_IncludeCHeaders(SCImport* Self, JB_File* F, Array* Output);

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

bool SC_Imp__ImportPathSub(JB_String* Path, JB_File* F, SCImport* Upon, JB_String* Fpl);

int SC_Imp__Init_();

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
int SC_SCObject_Auto_Type(SCObject* Self);

JB_String* SC_SCObject_AutoCompleteKind(SCObject* Self);

int SC_SCObject_AutoCompleteType(SCObject* Self);

JB_String* SC_SCObject_BaseIcon(SCObject* Self);

JB_String* SC_SCObject_CallFromName(SCObject* Self);

JB_String* SC_SCObject_CanAuto(SCObject* Self, JB_String* Search);

JB_String* SC_SCObject_CanAutoSub(SCObject* Self, JB_String* Search);

bool SC_SCObject_CanLinkFrom(SCObject* Self, SCFunction* Fn);

SCObject* SC_SCObject_Constructor(SCObject* Self);

void SC_SCObject_Destructor(SCObject* Self);

SCFunction* SC_SCObject_Disambiguate(SCObject* Self, Message* Src);

JB_String* SC_SCObject_Display(SCObject* Self, bool Exact);

SCFile* SC_SCObject_File(SCObject* Self);

bool SC_SCObject_IsVisible(SCObject* Self);

void SC_SCObject_IsVisibleSet(SCObject* Self, bool Value);

void SC_SCObject_MakeID(SCObject* Self, FastString* Fs, void** Table, bool IsFunc);

void SC_SCObject_MarkUnused(SCObject* Self, Message* Feedback, uint /*byte*/ Debug, JB_String* Name);

void SC_SCObject_NameConflict(SCObject* Self, SCObject* Old, JB_String* Name);

SCObject* SC_SCObject_NextDisplay(SCObject* Self, bool Exact);

int SC_SCObject_PackID(SCObject* Self, bool isFunc);

void SC_SCObject_PackIDSet(SCObject* Self, bool isFunc, int Value);

bool SC_SCObject_RehomeExport(SCObject* Self);

JB_String* SC_SCObject_Render(SCObject* Self, FastString* Fs_in);

bool SC_SCObject_syntaxequals(SCObject* Self, JB_String* Name);

void SC_SCObject_Fail(SCObject* Self, JB_String* Error);

bool SC_SCObject_SyntaxIs(SCObject* Self, uint /*SCNodeInfo*/ I);

void SC_SCObject_SyntaxIsSet(SCObject* Self, uint /*SCNodeInfo*/ I, bool Value);

SCFunction* SC_SCObject_TheIsFunc2(SCObject* Self, Message* Err);

JB_String* SC_SCObject_UniquifyExport(SCObject* Self, JB_String* S);

JB_String* SC_SCObject_UnusedReason(SCObject* Self);

JB_String* SC_SCObject_UnusedStr(SCObject* Self, JB_String* Name);



// JB_SCOperator
bool SC_Opp_CanOpCompare(SCOperator* Self, SCDecl* Lc, SCDecl* Rc, Message* Exp);

SCOperator* SC_Opp_Constructor(SCOperator* Self, JB_String* Name, fn_OpASM ASM, OpMode Mode);

void SC_Opp_Destructor(SCOperator* Self);

void SC_Opp_InitComp(SCOperator* Self, JB_String* Name_);

JB_String* SC_Opp_Render(SCOperator* Self, FastString* Fs_in);

void SC_Opp_SetFuncNameSet(SCOperator* Self, JB_String* S);

JB_String* SC_Opp_SimpleName(SCOperator* Self);

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

SCParamArray* SC_PA_Constructor(SCParamArray* Self, Message* Exp, JB_String* Name);

void SC_PA_Destructor(SCParamArray* Self);

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

void SC_PA_StructReturner(SCParamArray* Self, SCDecl* Type, SCFunction* Fn);

Message* SC_PA_SyntaxAccess(SCParamArray* Self, int I);



// JB_Selector
void JB_Sel_Destructor(Selector* Self);



// JB_String
JB_String* JB_Str_AfterByte(JB_String* Self, uint /*byte*/ B, int Last);

JB_String* JB_Str_ArgName(JB_String* Self);

JB_String* SC_Str_ArgsMatchError(JB_String* Self, bool TypeCast);

JB_String* JB_Str_ArgValue(JB_String* Self);

JB_String* JB_Str_BackToApp(JB_String* Self);

JB_String* JB_Str_Before(JB_String* Self, JB_String* S);

JB_String* JB_Str_BeforeLastByte(JB_String* Self, uint /*byte*/ B, int Fudge);

JB_String* JB_Str_Child(JB_String* Self, JB_String* Cname);

Array* JB_Str_Components(JB_String* Self);

JB_String* JB_Str_Compress(JB_String* Self, int Strength, CompressionStats* St, FastString* Fs_in);

JB_String* SC_Str_ContainerName(JB_String* Self, JB_String* Ext);

JB_String* JB_Str_Decompress(JB_String* Self, JB_Object* Dest, int Lim, CompressionStats* St);

Dictionary* JB_Str_Dict(JB_String* Self, uint /*byte*/ Sep);

JB_String* JB_Str_Digest(JB_String* Self);

bool JB_Str_EndsWith(JB_String* Self, JB_String* S, bool Aware);

bool JB_Str_EscapeTest(JB_String* Self);

JB_String* JB_Str_Ext(JB_String* Self);

JB_File* JB_Str_AsFile(JB_String* Self);

JB_File* JB_Str_ChildFile(JB_String* Self, JB_String* Ch);

int64 JB_Str_FileSize(JB_String* Self);

JB_File* JB_Str_FileThatExists(JB_String* Self, JB_String* Operation);

Ind JB_Str_FindCharset(JB_String* Self, CharSet Find, int From, int After);

ivec2 JB_Str_FindExt(JB_String* Self);

Ind JB_Str_FindSlash(JB_String* Self, int From);

int JB_Str_FindTrailingSlashes(JB_String* Self);

JB_String* SC_Str_InterfaceToBehaviour(JB_String* Self);

JB_String* SC_Str_internal(JB_String* Self);

bool JB_Str_IsBinary(JB_String* Self, float F);

bool SC_Str_isCLike(JB_String* Self);

bool JB_Str_IsCompressed(JB_String* Self);

int JB_Str_IsHexLike(JB_String* Self, int N);

bool JB_Str_IsIntFrom(JB_String* Self, int I);

Ind JB_Str_IsJbin(JB_String* Self);

bool JB_Str_IsLower(JB_String* Self);

bool SC_Str_Isnull(JB_String* Self);

bool JB_Str_IsOK(JB_String* Self);

bool SC_Str_IsOKForImport(JB_String* Self);

bool SC_Str_IsSpeedieSrc(JB_String* Self);

int SC_Str_IsSwizzle(JB_String* Self, int Width);

bool SC_Str_IsZero(JB_String* Self);

Ind JB_Str_JBFind(JB_String* Self, uint /*byte*/ Find, int Off, int After);

byte JB_Str_Last(JB_String* Self, int Minus);

int JB_Str_LineCount(JB_String* Self);

JB_File* SC_Str_MakeAndGoInto(JB_String* Self);

ErrorInt JB_Str_MakeEntirePath(JB_String* Self, bool Last);

void SC_Str_MiniName(JB_String* Self, FastString* Fs, bool IsClass);

JB_String* JB_Str_Moat(JB_String* Self);

JB_String* JB_Str_Name(JB_String* Self);

JB_String* JB_Str_NextField(JB_String* Self, uint /*byte*/ Sep, int& Begin);

JB_String* SC_Str_NicerClassName(JB_String* Self);

bool JB_Str_ContainsString(JB_String* Self, JB_String* S);

Ind JB_Str_OpInList(JB_String* Self, Array* List);

bool JB_Str_OperatorIsa(JB_String* Self, JB_String* S);

JB_String* JB_Str_OperatorMul(JB_String* Self, int N);

JB_String* JB_Str_OperatorPlusWithCstring(JB_String* Self, _cstring C);

JB_String* JB_Str_OperatorPlusWithInt64(JB_String* Self, int64 I);

bool SC_Str_OptionBool(JB_String* Self);

int SC_Str_OptionInt(JB_String* Self);

FastString* JB_Str_OutputStream(JB_String* Self, bool Clear);

JB_String* JB_Str_Parent(JB_String* Self);

Message* JB_Str_Parse(JB_String* Self, Syntax Owner, bool AllowDecomp);

Message* SC_Str_ParseClean(JB_String* Self);

Message* SC_Str_ParseCleanWipe(JB_String* Self);

Message* JB_Str_ParseJbin(JB_String* Self, int64 Max);

Message* JB_Str_ParseSub(JB_String* Self, Syntax Owner);

JB_String* JB_Str_PathDir(JB_String* Self);

JB_String* SC_Str_PathFixSpd(JB_String* Self);

JB_String* JB_Str_PluraliseAmount(JB_String* Self, int Amount, JB_String* Nothing);

JB_String* JB_Str_Pluralize(JB_String* Self, bool Plural, FastString* Fs_in);

JB_String* JB_Str_Preview(JB_String* Self, int N);

JB_String* JB_Str_ReadAll(JB_String* Self, int Lim, bool AllowMissing);

JB_String* JB_Str_RegularPath(JB_String* Self);

JB_String* JB_Str_RenderSpeed(JB_String* Self, JB_Object* Fs_in, int64 BytesIn, JB_Duration Duration, int64 BytesOut);

JB_String* JB_Str_ReplacePathComponent(JB_String* Self, int Num, JB_String* With);

void SC_Str_Safe(JB_String* Self, FastString* Fs, bool Local);

JB_String* SC_Str_ScriptContainer(JB_String* Self, JB_String* Container);

JB_String* SC_Str_ScriptLocation(JB_String* Self, JB_String* Container);

JB_String* JB_Str_Shorten(JB_String* Self, int N);

JB_String* JB_Str_Sibling(JB_String* Self, JB_String* Name);

ExitCode JB_Str_SilentExecute(JB_String* Self, Array* Args, FastString* Out, FastString* Errs, Date Timeout);

JB_String* SC_Str_SpdScriptName(JB_String* Self);

Array* JB_Str_Split(JB_String* Self, uint /*byte*/ Sep);

JB_String* JB_Str_Squeeze(JB_String* Self);

InputStream* JB_Str_Stream(JB_String* Self);

int64 JB_Str_SuffixSize(JB_String* Self);

JB_String* JB_Str_RangeVec(JB_String* Self, ivec2 R);

JB_String* JB_Str_SyntaxAccess(JB_String* Self, JB_String* S);

void JB_Str_Fail(JB_String* Self);

JB_String* JB_Str_TitleCase(JB_String* Self, FastString* Fs_in);

bool SC_Str_trap(JB_String* Self, Message* Msg);

JB_String* JB_Str_Trim(JB_String* Self, CharSet CS);

JB_String* JB_Str_TrimExtAndPath(JB_String* Self, bool RemovePath);

JB_String* JB_Str_TrimFirst(JB_String* Self, uint /*byte*/ B);

int JB_Str_TrimLastSub(JB_String* Self, uint /*byte*/ B);

JB_String* JB_Str_TrimSlashes(JB_String* Self);

bool SC_Str_UnderScoreAtAnyEnd(JB_String* Self);

JB_String* SC_Str_UnicodeSafeName(JB_String* Self, FastString* Fs_in);

int JB_Str_UnPrintable(JB_String* Self);

JB_String* JB_Str_UpperFirst(JB_String* Self);

ivec2 JB_Str_UTF8Badness(JB_String* Self);

bool JB_Str_Visible(JB_String* Self);

FileSizeInt JB_Str_WriteAll(JB_String* Self, JB_String* Data);

bool JB_Str_Yes(JB_String* Self, Message* Where);

JB_String* JB_Str__FromPico(PicoMessage* M);

SortComparison JB_Str__Sorter(JB_String* Self, JB_String* B);



// JB_SyntaxObj
SyntaxObj* JB_Fn_Constructor(SyntaxObj* Self, FP_fpMsgRender Msg, JB_String* Name, int ID);

void JB_Fn_Destructor(SyntaxObj* Self);

JB_String* JB_Fn_Render(SyntaxObj* Self, FastString* Fs_in);



// JB_TokenHandler


// JB_UnixProcess


// JB_Validator


// JB_list
void JB_Tree_AppendAfter(JB_List* Self, JB_List* Item, JB_List* After);

void JB_Tree_AppendAll(JB_List* Self, JB_List* Src);

void JB_Tree_AppendBefore(JB_List* Self, JB_List* Item, JB_List* Before);

void JB_Tree_Clear(JB_List* Self);

JB_List* JB_Tree_FlatLast(JB_List* Self);

bool JB_Tree_HasOneChild(JB_List* Self);

bool JB_Tree_IsFirst(JB_List* Self);

bool JB_Tree_IsLast(JB_List* Self);

bool JB_Tree_IsOnlyChild(JB_List* Self);

JB_List* JB_Tree_Pop(JB_List* Self);

void JB_Tree_PrependAll(JB_List* Self, JB_List* Src);

void JB_Tree_Remove(JB_List* Self);

void JB_Tree_RemoveAfter(JB_List* Self);

JB_String* JB_List_Render(JB_List* Self, FastString* Fs_in);

JB_List* JB_Tree_Second(JB_List* Self);

JB_List* JB_Tree_stepbool(JB_List* Self, bool Fwd);

JB_List* JB_Tree_Get(JB_List* Self, int N);

void JB_Tree_SyntaxAppend(JB_List* Self, JB_List* Last);

JB_List* JB_Tree_Upward(JB_List* Self, int N);

JB_List* JB_Tree_WrapWith(JB_List* Self, JB_List* W);



// JB_µForm
void SC_xC2xB5Form_AddP(xC2xB5Form* Self, int Size, uint /*MuParam*/ P);

void SC_xC2xB5Form_AddRemainder(xC2xB5Form* Self, int U);

xC2xB5Form* SC_xC2xB5Form_Constructor(xC2xB5Form* Self, Message* Tmp);

void SC_xC2xB5Form_Destructor(xC2xB5Form* Self);

void SC_xC2xB5Form_LoadParam(xC2xB5Form* Self, JB_String* Pl, Message* Place);

JB_String* SC_xC2xB5Form_Render(xC2xB5Form* Self, FastString* Fs_in);

MuParam SC_xC2xB5Form_AccessInt(xC2xB5Form* Self, int I);

int SC_xC2xB5Form__Init_();

xC2xB5Form* SC_xC2xB5Form__NeedForm(JB_String* Form, Message* M);



// JB_DataObjectFloat32


// JB_DataObjectFloat64


// JB_FastStringCpp
bool SC_FastStringCpp_AddProperty(FastStringCpp* Self, SCDecl* Prop, bool Intomodule);

void SC_FastStringCpp_AppendBehaviour(FastStringCpp* Self, JB_String* Name, SCFunction* Fn, SCClass* Type);

FastStringCpp* SC_FastStringCpp_Constructor(FastStringCpp* Self, JB_String* Name);

void SC_FastStringCpp_Destructor(FastStringCpp* Self);



// JB_File
JB_File* JB_File_Child(JB_File* Self, JB_String* Name);

ExitCode SC_File_CodeSign(JB_File* Self, JB_String* Sign);

bool JB_File_CompareData(JB_File* Self, JB_String* A, JB_String* Error);

bool JB_File_FileCompare(JB_File* Self, JB_File* A, JB_String* Error);

bool JB_File_CompareMsg(JB_File* Self, ErrorInt Code, JB_String* Error);

ErrorInt JB_File_FileCompareSub(JB_File* Self, JB_File* A);

Message* JB_File_Config(JB_File* Self, int Lim);

ErrorInt JB_File_CopyAll(JB_File* Self, JB_String* Dest, bool AttrOnly);

ErrorInt JB_File_DeleteAll(JB_File* Self, bool KeepSelf);

bool JB_File_DirectoryContains(JB_File* Self, JB_String* Path);

ErrorInt JB_File_LinkToSet(JB_File* Self, JB_String* Value);

Array* JB_File_List(JB_File* Self, int Mode);

Array* JB_File_ListFiles(JB_File* Self, int Mode);

bool JB_File_MustExist(JB_File* Self, JB_String* Operation);

bool JB_File_NewerThanFile(JB_File* Self, JB_File* F);

JB_File* JB_File_Parent(JB_File* Self);

Message* JB_File_Parse(JB_File* Self, int Lim, bool AllowMissing, Syntax Owner);

JB_File* JB_File_Sibling(JB_File* Self, JB_String* Name);

bool JB_File_SmartDataSet(JB_File* Self, JB_String* Nieu);

FileSizeInt JB_File_SyntaxAccessSet(JB_File* Self, JB_String* Data);

void JB_File_Fail(JB_File* Self, JB_String* Error);

bool SC_File_TestBatch(JB_File* Self);

bool SC_File_TestSpeedie(JB_File* Self, JB_String* V);

ExitCode JB_File_Touch(JB_File* Self);

int JB_File__Init_();

JB_File* JB_File__Prefs(JB_String* Name);

JB_String* JB_File__SpeedieDir();



// JB_JBin
jbinLeaver JB_bin_Add(FastString* Self, Syntax Type, JB_String* Name, bool Into);

jbinLeaver JB_bin_AddFS(FastString* Self, Syntax Type, FastString* Fs, bool Into);

void JB_bin_AddInt(FastString* Self, int64 Name);

jbinLeaver JB_bin_AddMemory(FastString* Self, Syntax Type, int L, bool GoIn, byte* Data);

void JB_bin_AddRow(FastString* Self, JB_String* Row, Syntax Type, JB_String* Value);

bool SC_bin_BakeASM(FastString* Self, SCFunction* Fn);

bool SC_bin_BakeASMSub(FastString* Self, SCFunction* Fn, int T);

void SC_bin_BakeFuncName(FastString* Self, SCFunction* Fn);

void SC_bin_Cakeify(FastString* Self, SCFunction* Fn);

FastString* JB_bin_Constructor(FastString* Self, Syntax Type, JB_String* Name);

void SC_bin_DebugCloseVar(FastString* Self, int Pos, int Reg);

jbinLeaver JB_bin_Enter(FastString* Self, Syntax Type, JB_String* Name);

int JB_bin_Exit(FastString* Self, int Amount);

void JB_bin_Exit0(FastString* Self);

int JB_bin_FinishAdd(FastString* Self, Syntax Ty, int Start);

void SC_bin_PropertyLayout(FastString* Self, Array* List);

void JB_bin_RunHeader(FastString* Self, JB_String* Name);

int JB_bin_StartAdd(FastString* Self);

jbinLeaver JB_bin_TmpArg(FastString* Self, JB_String* Name);

void JB_bin_WriteType(FastString* Self, Syntax Type, bool GoIn);

int JB_bin__Init_();



// JB_Message
void JB_Msg_Acc__(Message* Self, FastString* Fs);

Message* JB_Msg_AccessAdd(Message* Self, JB_String* Key);

bool SC_Msg_ACInIsa(Message* Self);

FatASM* SC_Msg_ADAK(Message* Self, ASMReg R1, ASMReg R2, int K);

FatASM* SC_Msg_ADD(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_ADDB(Message* Self, ASMReg R1, int K);

void SC_Msg_AddBefore(Message* Self, Message* Before, Message* NewItem);

FatASM* SC_Msg_ADDK(Message* Self, ASMReg R1, ASMReg R2, int K);

FatASM* SC_Msg_ADDM(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_AddOrSubInt(Message* Self, ASMReg Dest, ASMReg L, ASMReg R, int Sh);

FatASM* SC_Msg_AddShifted(Message* Self, ASMReg Dest, ASMReg L, ASMReg R, int Sh);

void SC_Msg_AddValue(Message* Self, SCFunction* F);

void JB_Msg_Adj__(Message* Self, FastString* Fs);

FatASM* SC_Msg_AFNC(Message* Self, ASMReg R1, int Library, int Index);

FatASM* SC_Msg_ALLO(Message* Self, ASMReg R1, int Amount);

bool SC_Msg_AllowedMoveToInit(Message* Self);

ASMReg SC_Msg_AllowsTemp(Message* Self);

Message* JB_Msg_Ancestor(Message* Self, Syntax F);

int SC_Msg_AndOrExpansionTest(Message* Self);

bool SC_Msg_AOrBExpand(Message* Self);

JB_String* SC_Msg_APICppProject(Message* Self);

void SC_Msg_AppendAllInto(Message* Self, Message* Dest);

void JB_Msg_AppendMacro(Message* Self, Message* M, Array* Prms);

void JB_Msg_ARel__(Message* Self, FastString* Fs);

void JB_Msg_Arg__(Message* Self, FastString* Fs);

void JB_Msg_Arr__(Message* Self, FastString* Fs);

SCArg* SC_Msg_AsArg(Message* Self);

SCDecl* SC_Msg_AsDecl(Message* Self);

SCFunction* SC_Msg_AsFunc(Message* Self);

void JB_Msg_Ask__(Message* Self, FastString* Fs);

SCDecl* SC_Msg_ASMDecl(Message* Self);

int SC_Msg_AsmIndent(Message* Self, Message* Top);

ASMType SC_Msg_ASMType(Message* Self);

void SC_Msg_ASMTypeSet(Message* Self, uint /*ASMType*/ Value);

Message* SC_Msg_ASMUnbra(Message* Self);

void SC_Msg_AssignsFix(Message* Self, SCFunction* F);

int SC_Msg_Autocomplete_State(Message* Self);

JB_String* SC_Msg_AutoCompleteDecl(Message* Self);

SCFunction* SC_Msg_AutoMsgFuncFn(Message* Self);

void SC_Msg_AvoidSafeDecr(Message* Self);

void JB_Msg_Back__(Message* Self, FastString* Fs);

void JB_Msg_Badj__(Message* Self, FastString* Fs);

FatASM* SC_Msg_BAND(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_BANK(Message* Self, ASMReg R1, ASMReg R2, int K);

void JB_Msg_BecomeMsg(Message* Self, Message* Src);

void SC_Msg_BecomeWithOpp(Message* Self, SCOperator* Op);

void SC_Msg_BecomeWithFunc(Message* Self, SCFunction* Func);

void SC_Msg_BecomeAppend(Message* Self, JB_String* S);

void JB_Msg_BecomeCopy(Message* Self, Message* Src);

void JB_Msg_BecomeMacro(Message* Self, Message* M, Array* Prms);

void SC_Msg_BecomeNil(Message* Self);

void SC_Msg_BecomeSetRel(Message* Self);

void SC_Msg_BecomeTarget(Message* Self);

FatASM* SC_Msg_BFLG(Message* Self, ASMReg R1, ASMReg R2, int Up, int Down, int Sign);

FatASM* SC_Msg_BFLS(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

void JB_Msg_Bin__(Message* Self, FastString* Fs);

void JB_Msg_binn__(Message* Self, FastString* Fs);

void JB_Msg_BinnRender(Message* Self, FastString* Fs, JB_String* Sepa);

ErrorSeverity SC_Msg_Blind(Message* Self);

SCBlockage SC_Msg_Blocks(Message* Self);

void SC_Msg_BlocksSet(Message* Self, int Value);

FatASM* SC_Msg_BLSH(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_BNOT(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_BORK(Message* Self, ASMReg R1, ASMReg R2, int K);

FatASM* SC_Msg_BORR(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

void JB_Msg_Bra__(Message* Self, FastString* Fs);

SCDecl* SC_Msg_BraDeclfind(Message* Self);

void JB_Msg_BRel__(Message* Self, FastString* Fs);

FatASM* SC_Msg_BRSH(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_BRSS(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

bool SC_Msg_BuildRunTask(Message* Self, Message* Fields, int Level);

void SC_Msg_BuildTask(Message* Self, Message* Fields, int Level);

Message* SC_Msg_BunchFixPrepare(Message* Self);

void SC_Msg_BunchFixSub(Message* Self, Message* Subject, Message* Stuff);

void SC_Msg_BunchlessFix(Message* Self);

FatASM* SC_Msg_BXOR(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_BXRK(Message* Self, ASMReg R1, ASMReg R2, int K);

void SC_Msg_CallChainError(Message* Self, JB_String* Name);

bool SC_Msg_CanGetAddress(Message* Self, SCNode* Name_space);

Message* SC_Msg_CastedParent(Message* Self);

int SC_Msg_CastFPToVoidPtr(Message* Self);

int SC_Msg_CastToBool(Message* Self, SCNode* Name_space);

int SC_Msg_CastToClass(Message* Self, SCClass* Type, SCNode* Name_space);

int SC_Msg_CastToType(Message* Self, JB_String* TypeName, SCClass* Type, SCNode* Name_space, int Loss);

Message* SC_Msg_CausesUnReachable(Message* Self, Message* Arg, Message* Dcl, Message* LastPlace);

void JB_Msg_Char__(Message* Self, FastString* Fs);

void SC_Msg_CheckConstShift(Message* Self, SCDecl* LC, SCDecl* RC, bool Bigger);

void SC_Msg_CheckContinuesAndExits(Message* Self);

void SC_Msg_CheckNotInStatExpr(Message* Self, Message* Top);

void SC_Msg_Clean(Message* Self, bool Erl);

Message* SC_Msg_CmdImprove(Message* Self);

FatASM* SC_Msg_CMPF(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Cmp);

FatASM* SC_Msg_CMPI(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Cmp);

void JB_Msg_Cnj__(Message* Self, FastString* Fs);

FatASM* SC_Msg_CNTC(Message* Self, ASMReg R1, ASMReg R2, int Offset, int Cnst, int Size);

FatASM* SC_Msg_CNTD(Message* Self, ASMReg R1, ASMReg R2, int Offset, int Cnst, int Size);

bool SC_Msg_CollectAGlobalDecl(Message* Self, SCModule* Mod);

Message* SC_Msg_CollectDclName(Message* Self);

SCDecl* SC_Msg_CollectDecl(Message* Self, SCNode* P, SCNode* Recv, DeclMode Mode, SCClass* Cls, SCFunction* FuncPrmz);

void SC_Msg_CollectFromBody(Message* Self, SCNode* Name_space);

JB_String* SC_Msg_CollectFuncTableName(Message* Self);

Message* SC_Msg_CollectionPlace(Message* Self);

bool SC_Msg_CollectOneParam(Message* Self, SCFunction* Func, SCNode* Recv, SCClass* Cls);

Message* JB_Msg_ConfArg(Message* Self);

void SC_Msg_ConfTake(Message* Self, Message* Dest, JB_String* Name);

Message* SC_Msg_ConstantExpandSub(Message* Self);

bool SC_Msg_ConstIntValue(Message* Self, SCNode* Name_space, int64& V);

bool SC_Msg_ConstIntValueSub(Message* Self, int64& V);

Message* JB_Msg_ConstructorCopy(Message* Self, Message* Other);

Message* JB_Msg_ConstructorEmpty(Message* Self);

Message* JB_Msg_Constructor(Message* Self, Message* Parent, Syntax Func, JB_String* Name);

Message* JB_Msg_ConstructorParser(Message* Self, Message* Parent, Syntax Func, int BytePos, JB_String* Name, int RangeLength);

void SC_Msg_ConstructorAddNil(Message* Self, bool Isdot);

bool JB_Msg_ContainsInd(Message* Self, Ind P, bool AllowJustAfter);

bool SC_Msg_ContainsFunc(Message* Self);

FatASM* SC_Msg_CONV(Message* Self, ASMReg R1, ASMReg R2, int Mode);

Message* JB_Msg_Copy(Message* Self, Message* Pos_msg);

void SC_Msg_CopyAllAfter(Message* Self, Message* After, Message* Copylayer);

void SC_Msg_CopyAllAfterBefore(Message* Self, Message* Before, Message* Copylayer);

void SC_Msg_CopyAllAfterInto(Message* Self, Message* Into, Message* Copylayer);

void SC_Msg_CopyAllBefore(Message* Self, Message* Before, Message* Copylayer);

void SC_Msg_CopyAllBeforeInto(Message* Self, Message* Into, Message* Copylayer);

void JB_Msg_CopyAllInto(Message* Self, Message* J);

JB_String* JB_Msg_CopyID(Message* Self);

Message* JB_Msg_CopyWithoutUsing(Message* Self, Message* P);

Message* SC_Msg_CreateNil(Message* Self);

Message* SC_Msg_CreateOwnBlock(Message* Self);

Message* SC_Msg_CutifyCopy(Message* Self);

Message* SC_Msg_DclExp(Message* Self);

void JB_Msg_Decl__(Message* Self, FastString* Fs);

Message* SC_Msg_Declable(Message* Self);

void SC_Msg_DeclAddNumbInt(Message* Self, int64 Num, SCNode* Name_space);

Message* SC_Msg_DeclName(Message* Self);

bool JB_Msg_DeepEquals(Message* Self, Message* B, bool Aware);

Message* SC_Msg_Deepest(Message* Self, Syntax Tmp, JB_String* Name);

void SC_Msg_DefaultPrmFix(Message* Self, SCDecl* Base);

void SC_Msg_DenyPreviousUse(Message* Self, Message* Msg);

int SC_Msg_DeprecatedClassOption(Message* Self, JB_String* Name, JB_String* Kind);

void JB_Msg_Destructor(Message* Self);

Dictionary* JB_Msg_Dict(Message* Self, bool DoLower, bool DoCount);

JB_String* JB_Msg_DisplayName(Message* Self, int I);

FatASM* SC_Msg_DIV(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int Kind);

FatASM* SC_Msg_DIV2(Message* Self, ASMReg R1, ASMReg R2, int Clear, int Down);

void SC_Msg_DivByZero(Message* Self);

FatASM* SC_Msg_DIVS(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int Kind);

bool SC_Msg_DoesAnything(Message* Self);

void JB_Msg_Dot__(Message* Self, FastString* Fs);

SCDecl* SC_Msg_DotMustBeProperty(Message* Self);

SCObject* SC_Msg_DotSpace(Message* Self, SCNode* Name_space);

DotUseType SC_Msg_DotType(Message* Self);

FatASM* SC_Msg_DUMB(Message* Self, ASMReg R1, ASMReg R2);

void JB_Msg_Dummy(Message* Self, FastString* Fs);

bool SC_Msg_ElseIfIndentBad(Message* Self);

void SC_Msg_ElseNeverFires(Message* Self);

void JB_Msg_Emb__(Message* Self, FastString* Fs);

FatASM* SC_Msg_EQUL(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Cmp);

void JB_Msg_ERel__(Message* Self, FastString* Fs);

FatASM* SC_Msg_EROR(Message* Self, ASMReg R1, ASMReg R2, int SigNum, int Continue);

ASMReg SC_Msg_ExpandBits(Message* Self, ASMReg Src, uint /*DataTypeCode*/ Type);

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

FatASM* SC_Msg_FADD(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

FatASM* SC_Msg_FADK(Message* Self, ASMReg R1, ASMReg R2, int High);

Message* SC_Msg_FailOrCopy(Message* Self, Message* P);

Message* SC_Msg_FalsifyNil(Message* Self);

SCDecl* SC_Msg_FastDecl(Message* Self);

SCDecl* SC_Msg_FastDeclSafe(Message* Self);

FatASM* SC_Msg_FCLM(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

FatASM* SC_Msg_FDIV(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

FatASM* SC_Msg_FEET(Message* Self, ASMReg R1, ASMReg R2, int K);

SCFile* SC_Msg_File(Message* Self);

void JB_Msg_File__(Message* Self, FastString* Fs);

Message* SC_Msg_FileMark(Message* Self);

Message* JB_Msg_FindSyx(Message* Self, Syntax S);

Message* JB_Msg_FindSyxName(Message* Self, Syntax S, JB_String* Name, bool Err);

Message* SC_Msg_FindName(Message* Self, JB_String* Name);

Message* SC_Msg_find(Message* Self, Syntax P, Syntax Ch, JB_String* Name);

Array* SC_Msg_FindAll(Message* Self, Syntax Fn, JB_String* Name);

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

JB_Object* SC_Msg_FirstPrmObj(Message* Self);

void SC_Msg_FixElseif(Message* Self);

void SC_Msg_FixErl(Message* Self);

void SC_Msg_FixMultiArr(Message* Self);

Float64 JB_Msg_Float(Message* Self);

FatASM* SC_Msg_FMLK(Message* Self, ASMReg R1, ASMReg R2, int High);

FatASM* SC_Msg_FMOD(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

FatASM* SC_Msg_FMUL(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

FatASM* SC_Msg_FNC(Message* Self, ASMReg R1, int JUMP, int Prm1, int Prm2);

FatASM* SC_Msg_FNC3(Message* Self, ASMReg R1, int JUMP, int Prm1, int Prm2);

FatASM* SC_Msg_FNCX(Message* Self, ASMReg R1, int Table, int Prm1, int Prm2);

FatASM* SC_Msg_FNCX3(Message* Self, ASMReg R1, int Table, int Prm1, int Prm2);

bool SC_Msg_FoundFuncWith0(Message* Self);

bool SC_Msg_FoundFuncWithFunc(Message* Self, SCFunction* F);

void JB_Msg_FSListArg(Message* Self, FastString* Fs, bool AddLine);

void JB_Msg_FSListSep(Message* Self, FastString* Fs, JB_String* Sep);

Message* SC_Msg_FullAfter(Message* Self);

void JB_Msg_Func__(Message* Self, FastString* Fs);

JB_String* JB_Msg_FuncName(Message* Self);

JB_String* SC_Msg_FuncPos(Message* Self, SCFunction* Fn, int& Pos);

void SC_Msg_FuncWrap(Message* Self, Message* Fnc);

Message* SC_Msg_GetAddrButNicer(Message* Self);

int SC_Msg_GetAddressOf(Message* Self, SCDecl* Type, bool WasCArray);

Message* SC_Msg_GetDclName(Message* Self, bool IsConstructor);

SCFunction* SC_Msg_GetFunctionPointer(Message* Self);

Message* SC_Msg_GetMarker(Message* Self, JB_String* S);

Message* SC_Msg_GetTypeLimiter(Message* Self);

Message* JB_Msg_GiveArg(Message* Self);

FatASM* SC_Msg_GOBJ(Message* Self, ASMReg R1, int Mode, int Ref, int Add);

Message* JB_Msg_GoIntoInvisArg(Message* Self, Message* Tmp, int Pos);

FatASM* SC_Msg_GRAB(Message* Self, ASMReg R1, ASMReg R2);

FatASM* SC_Msg_GTAB(Message* Self, ASMReg R1, int Mode, int Add);

FatASM* SC_Msg_HALT(Message* Self, ASMReg R1, ASMReg R2, int SigNum, int Continue);

bool SC_Msg_HasActualCode(Message* Self);

bool SC_Msg_HasAsmStuff(Message* Self);

Message* SC_Msg_HasOwnBlock(Message* Self);

bool SC_Msg_HasSelfAsFirst(Message* Self);

void SC_Msg_HateUnusedFuncs(Message* Self);

FatASM* SC_Msg_ICLM(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int Small);

SCFunction* SC_Msg_IdentifyFunc(Message* Self);

Message* SC_Msg_InBuiltContained(Message* Self, SCDecl* Dcl);

Message* SC_Msg_InBuiltSizeOf(Message* Self, SCDecl* Sulf);

Message* SC_Msg_InBuiltTypeOf(Message* Self, SCDecl* Dcl);

bool SC_Msg_InDecl(Message* Self);

int JB_Msg_IndentScore(Message* Self);

bool JB_Msg_InInvisArg(Message* Self);

bool SC_Msg_InitExpand(Message* Self);

int SC_Msg_InlineCount(Message* Self, int Remain);

void SC_Msg_InsertBefore(Message* Self, Message* J, Message* Ch);

void SC_Msg_InsertMainArgs(Message* Self, Message* Prms);

SCFunction* SC_Msg_InsideFunc(Message* Self);

int64 JB_Msg_IntRange(Message* Self, int StrStart, int64 Low, int64 High);

int64 JB_Msg_Int(Message* Self, int StrStart);

Message* SC_Msg_IntoVariable(Message* Self, SCNode* Name_space);

int SC_Msg_IntSmallness(Message* Self, SCDecl* T);

bool SC_Msg_IsAddr(Message* Self);

MaybeBool SC_Msg_IsAlwaysBool(Message* Self);

bool SC_Msg_IsAlwaysFalse(Message* Self);

bool SC_Msg_IsAssignable(Message* Self);

bool SC_Msg_IsBehaviour(Message* Self);

bool SC_Msg_IsCake(Message* Self);

bool SC_Msg_IsClassType(Message* Self);

bool SC_Msg_IsFirstOfSetRel(Message* Self);

bool SC_Msg_IsFuncDot(Message* Self);

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

bool SC_Msg_IsTern(Message* Self);

bool JB_Msg_IsTypeOfDecl(Message* Self);

bool SC_Msg_IsVarAltered(Message* Self, JB_String* Name);

bool SC_Msg_IsVarUseableInLoop(Message* Self, JB_String* Name);

bool SC_Msg_IsZero(Message* Self);

void JB_Msg_Item__(Message* Self, FastString* Fs);

FatASM* SC_Msg_JBAN(Message* Self, ASMReg R1, int Small, int Jmp);

bool JB_Msg_jbinTest(Message* Self);

FatASM* SC_Msg_JBOR(Message* Self, ASMReg R1, int Small, int Jmp);

void jdb2(Message* Self);

FatASM* SC_Msg_JMKE(Message* Self, ASMReg R1, int K, int Jmp);

FatASM* SC_Msg_JMKL(Message* Self, ASMReg R1, int K, int Jmp);

FatASM* SC_Msg_JMKM(Message* Self, ASMReg R1, int K, int Jmp);

FatASM* SC_Msg_JMKN(Message* Self, ASMReg R1, int K, int Jmp);

FatASM* SC_Msg_JMPE(Message* Self, ASMReg R1, ASMReg R2, int LSmall, int RSmall, int Jmp);

FatASM* SC_Msg_JMPF(Message* Self, ASMReg R1, ASMReg R2, int Cmp, int Jmp);

FatASM* SC_Msg_JMPI(Message* Self, ASMReg R1, ASMReg R2, int Cmp, int Jmp);

FatASM* SC_Msg_JMPN(Message* Self, ASMReg R1, ASMReg R2, int LSmall, int RSmall, int Jmp);

FatASM* SC_Msg_JUMP(Message* Self, int JUMP);

void SC_Msg_KinderRemoveAfter(Message* Self);

FatASM* SC_Msg_KNSR(Message* Self, ASMReg R1, int Rot, int Inv, int Value);

FatASM* SC_Msg_KNST(Message* Self, ASMReg R1, int Cond, int Inv, int Value);

FatASM* SC_Msg_KNST2(Message* Self, ASMReg R1, int Cond, int Inv, int Value);

FatASM* SC_Msg_KNST3(Message* Self, ASMReg R1, int Cond, int Inv, int Value);

Message* JB_Msg_Last(Message* Self, Syntax Need);

void SC_Msg_LastInBlock(Message* Self, SCBlockage Reason);

Message* SC_Msg_LastUsedFix(Message* Self);

void JB_Msg_List__(Message* Self, FastString* Fs);

Array* SC_Msg_ListAll(Message* Self);

bool JB_Msg_ListViewable(Message* Self);

JB_String* JB_Msg_Locate(Message* Self);

void SC_Msg_LoopContinue(Message* Self);

void SC_Msg_LoopExit(Message* Self);

void SC_Msg_LoopExitter(Message* Self, int ASMType, SCBlockage ExitCode);

FatASM* SC_Msg_LUPD(Message* Self, ASMReg R1, ASMReg R2, int Small, int Jmp);

FatASM* SC_Msg_LUPU(Message* Self, ASMReg R1, ASMReg R2, int Small, int Jmp);

Message* JB_Msg_MacroAvoidCopy(Message* Self);

void JB_Msg_MacroCopy(Message* Self, Message* Root, Array* Prms, Message* Dest);

void SC_Msg_MacroFixSub(Message* Self, SCDecl* Contains);

Message* JB_Msg_MacroPrm(Message* Self, Message* Root, Array* Prms, Message* Dest);

Message* JB_Msg_MacroSame(Message* Self, Message* Prm);

Message* SC_Msg_MainArgDotFix(Message* Self);

bool SC_Msg_MainArgsCanBeZero(Message* Self);

Message* SC_Msg_MainFix(Message* Self);

void SC_Msg_MainFix2(Message* Self);

int SC_Msg_MainOneArg(Message* Self, Message* Arg, int I, int Found);

Message* SC_Msg_MakeAccess0(Message* Self);

Message* SC_Msg_MakeAfter(Message* Self);

void SC_Msg_MakeComment(Message* Self);

void SC_Msg_MakeTaskVar(Message* Self, Message* Con, Message* Before, bool First);

FatASM* SC_Msg_MARK(Message* Self);

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

Message* SC_Msg_MsgFix(Message* Self, Message* Parent);

SCFunction* SC_Msg_MsgFunc(Message* Self);

SCFunction* SC_Msg_MsgOwningFunc(Message* Self);

FatASM* SC_Msg_MUL(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4);

FatASM* SC_Msg_MULK(Message* Self, ASMReg R1, ASMReg R2, int K);

FatASM* SC_Msg_MULS(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4);

void JB_Msg_Name__(Message* Self, FastString* Fs);

Message* SC_Msg_NeedBra(Message* Self);

Message* SC_Msg_NeedMarker(Message* Self, JB_String* S, bool B);

bool SC_Msg_NeedsPreprocess(Message* Self);

Message* SC_Msg_Negate(Message* Self);

Message* SC_Msg_NegateThg(Message* Self);

Message* JB_Msg_NextOf(Message* Self, Syntax Need, JB_String* Name);

void SC_Msg_Next_Index(Message* Self, SCIterator* Iter, Message* Node2);

Message* SC_Msg_NextPath(Message* Self, Message* Before, Message* Path);

SCDecl* SC_Msg_NiceIsFlagSyntax(Message* Self, Message* Opch, Message* RN, SCNode* Name_space, Message* Side);

Message* SC_Msg_NiceParent(Message* Self);

void JB_Msg_Nil__(Message* Self, FastString* Fs);

int SC_Msg_NilCheckMode(Message* Self, bool Ok);

SCDecl* SC_Msg_NilDecl(Message* Self);

FatASM* SC_Msg_NOOP(Message* Self);

Message* SC_Msg_NormaliseFunc(Message* Self, SCClass* AddSelf);

void SC_Msg_NotNilRZ(Message* Self, SCDecl* Type, SCNode* Space);

void JB_Msg_Num__(Message* Self, FastString* Fs);

void JB_Msg_Oat__(Message* Self, FastString* Fs);

SCClass* SC_Msg_ObjCls(Message* Self);

bool JB_Msg_OperatorIn(Message* Self, Syntax F);

bool SC_Msg_OperatorIsARel(Message* Self, JB_String* Name);

bool SC_Msg_OperatorIsBRel(Message* Self, JB_String* Name);

bool SC_Msg_OperatorIsOpp(Message* Self, JB_String* Name);

bool SC_Msg_OperatorIsThing(Message* Self, JB_String* Name);

bool SC_Msg_OperatorIsTmp(Message* Self, JB_String* Name);

bool SC_Msg_operatormatches(Message* Self, Message* M);

bool JB_Msg_OperatorStarts(Message* Self, JB_String* S);

void JB_Msg_Opp__(Message* Self, FastString* Fs);

bool SC_Msg_OppExpand(Message* Self);

int SC_Msg_OpScore(Message* Self);

JB_String* JB_Msg_OriginalFilePath(Message* Self);

JB_String* JB_Msg_OriginalParseData(Message* Self);

Message* SC_Msg_OrigMsg(Message* Self);

JB_String* SC_Msg_OrigRender(Message* Self, FastString* Fs_in);

Message* SC_Msg_ParseShaderSub(Message* Self);

void JB_Msg_pinn__(Message* Self, FastString* Fs);

JB_String* JB_Msg_plocate(Message* Self);

void SC_Msg_PrepareAST(Message* Self);

int JB_Msg_PrevIndentCheck(Message* Self, Message* Pr);

void JB_Msg_Prm__(Message* Self, FastString* Fs);

SCFunction* SC_Msg_PrmFunc(Message* Self);

Message* SC_Msg_PrmFuncStructMsg(Message* Self);

FatASM* SC_Msg_QADD(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_QADK(Message* Self, ASMReg R1, ASMReg R2, int K);

FatASM* SC_Msg_QAND(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_QCLM(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4);

FatASM* SC_Msg_QCNV(Message* Self, ASMReg R1, ASMReg R2, int Mode);

FatASM* SC_Msg_QDIV(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int Kind);

FatASM* SC_Msg_QFLG(Message* Self, ASMReg R1, ASMReg R2, int Up, int Down, int Sign);

FatASM* SC_Msg_QFLS(Message* Self, ASMReg R1, ASMReg R2, int Up, int Down, int Sign);

FatASM* SC_Msg_QINC(Message* Self, ASMReg R1, ASMReg R2, int Part, int Amount);

FatASM* SC_Msg_QLSH(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

Message* SC_Msg_QMarkRel(Message* Self);

FatASM* SC_Msg_QMUL(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4);

FatASM* SC_Msg_QNOT(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_QORR(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_QRSH(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_QRSS(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_QSUB(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

void JB_Msg_Ques__(Message* Self, FastString* Fs);

void JB_Msg_Quot__(Message* Self, FastString* Fs);

FatASM* SC_Msg_QXOR(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_RALO(Message* Self, ASMReg R1, ASMReg R2);

IntRange JB_Msg_Range(Message* Self);

void JB_Msg_RangeSet(Message* Self, IntRange R);

int SC_Msg_RC_HasTemporary(Message* Self);

FatASM* SC_Msg_RD16(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* SC_Msg_RD1S(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* SC_Msg_RD1U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* SC_Msg_RD2S(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* SC_Msg_RD2U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* SC_Msg_RD4S(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* SC_Msg_RD4U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* SC_Msg_RD8U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

NilState SC_Msg_RedundantDeclare(Message* Self, uint /*NilState*/ D);

NilState SC_Msg_RedundantVar(Message* Self, SCDecl* Dcl, NilCheckMode Test);

bool SC_Msg_RefDisappears(Message* Self);

Message* SC_Msg_RefMsgToUse(Message* Self);

bool SC_Msg_RefTransparent(Message* Self);

void JB_Msg_Rel__(Message* Self, FastString* Fs);

bool SC_Msg_RelFix(Message* Self, bool Force);

JB_String* JB_Msg_Render(Message* Self, FastString* Fs_in);

void JB_Msg_render_jbin_sub(Message* Self, FastString* Js);

JB_String* JB_Msg_RenderAST(Message* Self, bool RenderRoot, FastString* Fs_in);

JB_String* JB_Msg_RenderJbin(Message* Self, JB_String* Shell_path, FastString* Fs_in);

void JB_Msg_RenderPrm(Message* Self, FastString* Fs, uint /*byte*/ B1, uint /*byte*/ B2);

JB_String* SC_Msg_RenderType(Message* Self);

void JB_Msg_RenderWithSpaces(Message* Self, FastString* Fs, Message* Ch);

Message* SC_Msg_ReplaceInbuiltSub(Message* Self, SCDecl* Self_decl);

Message* SC_Msg_ReplaceInto(Message* Self, Message* W);

Message* SC_Msg_ReplaceWith(Message* Self, Message* J);

Message* SC_Msg_ReplaceWithChild(Message* Self);

void JB_Msg_CantFind(Message* Self, Syntax S, JB_String* Name, Message* Found);

Message* SC_Msg_Resync(Message* Self, Message* Parent);

FatASM* SC_Msg_RET(Message* Self, ASMReg R1, int Value);

FatASM* SC_Msg_RFRD(Message* Self, ASMReg R1, ASMReg R2, int Decr, int Offset);

FatASM* SC_Msg_RFRT(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4);

FatASM* SC_Msg_RFST(Message* Self, ASMReg R1, ASMReg R2);

FatASM* SC_Msg_RFUN(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3);

FatASM* SC_Msg_RFWR(Message* Self, ASMReg R1, ASMReg R2, int Decr, int Offset);

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

bool JB_Msg_ShallowEquals(Message* Self, Message* B, bool Aware);

void JB_Msg_Sheb__(Message* Self, FastString* Fs);

void SC_Msg_SlidePositions(Message* Self, int Add);

void SC_Msg_SortImprove(Message* Self, SCNode* Name_space);

void SC_Msg_SpdFuncSet(Message* Self, Syntax Value);

uint SC_Msg_SrcMap(Message* Self);

void JB_Msg_SStr__(Message* Self, FastString* Fs);

void SC_Msg_StartUsingAfter(Message* Self);

void SC_Msg_StatementExprSet(Message* Self, SCArg* Arg);

void JB_Msg_SThg__(Message* Self, FastString* Fs);

void JB_Msg_Str__(Message* Self, FastString* Fs);

void SC_Msg_StructReturnCleanup(Message* Self, SCFunction* Fn, SCNode* Name_space);

FatASM* SC_Msg_SUB(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

FatASM* SC_Msg_SUBM(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Sh);

Message* JB_Msg_NeedSyxOK(Message* Self, Syntax Need, Syntax OK);

Message* JB_Msg_NeedSyx(Message* Self, Syntax S);

Message* JB_Msg_NeedSyxInt(Message* Self, Syntax S, int N);

Message* JB_Msg_NeedSyxName(Message* Self, Syntax S, JB_String* Name);

void JB_Msg_SetStr(Message* Self, JB_String* Key, JB_String* Value);

void JB_Msg_SetMsg(Message* Self, JB_String* Key, Message* Value);

Message* JB_Msg_GetConf(Message* Self, JB_String* Key, bool Err);

void JB_Msg_AppendString(Message* Self, JB_String* Key);

void JB_Msg_AppendNum(Message* Self, int64 Num);

bool JB_Msg_SyntaxEquals(Message* Self, JB_String* Name, bool Aware);

bool JB_Msg_EqualsSyx(Message* Self, Syntax X);

bool JB_Msg_SyntaxIs(Message* Self, uint /*MsgParseFlags*/ F);

void JB_Msg_SyntaxIsSet(Message* Self, uint /*MsgParseFlags*/ F, bool Value);

void JB_Msg_SyntaxUsing(Message* Self, MessagePosition* Rz);

FatASM* SC_Msg_TAIL(Message* Self, int JUMP, int Prm1);

bool SC_Msg_TargetTest(Message* Self);

int SC_Msg_TargetTestOp(Message* Self, Message* C);

bool SC_Msg_TargetThg(Message* Self);

Message* SC_Msg_TaskConBefore(Message* Self);

Message* SC_Msg_TempIntoBlock(Message* Self, Message* ParentPlace);

FatASM* SC_Msg_TERN(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int Small);

void JB_Msg_Test(Message* Self, JB_String* New_render, JB_String* Name);

void JB_Msg_test_style(Message* Self);

bool SC_Msg_TestFuncName(Message* Self);

bool JB_Msg_TestSub(Message* Self, JB_String* New_render, JB_String* Name);

bool JB_Msg_TextSet(Message* Self, int I, JB_String* V);

Message* JB_Msg_TextViewChild(Message* Self);

void JB_Msg_Thg__(Message* Self, FastString* Fs);

FatASM* SC_Msg_TIME(Message* Self, ASMReg R1, ASMReg R2);

void JB_Msg_Tmp__(Message* Self, FastString* Fs);

void JB_Msg_Todo__(Message* Self, FastString* Fs);

void SC_Msg_Tran_Isnt(Message* Self, JB_String* Name);

void SC_Msg_Tran_QMark(Message* Self);

Message* SC_Msg_Tran_Target(Message* Self);

void SC_Msg_Tran_TargetSub(Message* Self);

void SC_Msg_Tran_With(Message* Self);

void SC_Msg_TranAllTargets(Message* Self);

Message* SC_Msg_TranModel(Message* Self);

FatASM* SC_Msg_TRAP(Message* Self, ASMReg R1, int Upon);

void JB_Msg_TRel__(Message* Self, FastString* Fs);

void JB_Msg_Tril__(Message* Self, FastString* Fs);

int SC_Msg_TrinInt(Message* Self);

MaybeBool SC_Msg_Trueness(Message* Self, uint /*NilState*/ Found);

bool SC_Msg_TrueOrFalse(Message* Self);

int SC_Msg_TryImproveShiftConstants(Message* Self, SCDecl* LC, SCDecl* RC);

void JB_Msg_Type__(Message* Self, FastString* Fs);

bool SC_Msg_TypeCastDoesNothing(Message* Self);

void SC_Msg_TypeExpect(Message* Self, uint /*DataTypeCode*/& Ty, uint /*DataTypeCode*/ In);

Message* SC_Msg_TypeOfArrItem(Message* Self);

FatASM* SC_Msg_UCLM(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int Small);

Message* SC_Msg_UnBra(Message* Self);

Message* SC_Msg_UnBraType(Message* Self);

void JB_Msg_UnEmbedStr(Message* Self);

void JB_Msg_Unit__(Message* Self, FastString* Fs);

bool SC_Msg_UnitMatch(Message* Self, JB_String* A, JB_String* B);

Message* SC_Msg_UnReachable(Message* Self);

Message* SC_Msg_Unwrap(Message* Self);

Message* SC_Msg_UpToArg(Message* Self);

Message* SC_Msg_UpToType(Message* Self);

void JB_Msg_URL__(Message* Self, FastString* Fs);

Message* SC_Msg_UseNonRefChangers(Message* Self, bool Parent);

FatASM* SC_Msg_VADD(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

FatASM* SC_Msg_VADK(Message* Self, ASMReg R1, ASMReg R2, int High);

JB_String* JB_Msg_Value(Message* Self);

void SC_Msg_VariableParamSafety(Message* Self);

JB_String* SC_Msg_VarName(Message* Self);

FatASM* SC_Msg_VBLD(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, ASMReg R5);

FatASM* SC_Msg_VDIV(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

FatASM* SC_Msg_VGET(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Ind);

bool SC_Msg_visible(Message* Self);

void SC_Msg_visibleSet(Message* Self, bool Value);

MaybeBool SC_Msg_visible2(Message* Self);

int SC_Msg_VMBits(Message* Self);

FatASM* SC_Msg_VMLK(Message* Self, ASMReg R1, ASMReg R2, int High);

JB_String* SC_Msg_VMMsgArgName(Message* Self, int I);

FatASM* SC_Msg_VMOV(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4);

FatASM* SC_Msg_VMUL(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, ASMReg R4, int D);

FatASM* SC_Msg_VSET(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Ind);

FatASM* SC_Msg_VSWZ(Message* Self, ASMReg R1, ASMReg R2, int Fields);

FatASM* SC_Msg_WCPY(Message* Self, ASMReg R1, ASMReg R2, int Length);

Message* SC_Msg_WipePos(Message* Self, int V);

void SC_Msg_WithDeclTransform(Message* Self, Message* Decl, Message* Rel, Message* Arg);

bool SC_Msg_WithinLoop(Message* Self, Message* Stop);

bool JB_Msg_WithinType(Message* Self, int Allowed);

FatASM* SC_Msg_WR16(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* SC_Msg_WR1U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* SC_Msg_WR2U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* SC_Msg_WR4U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

FatASM* SC_Msg_WR8U(Message* Self, ASMReg R1, ASMReg R2, ASMReg R3, int Offset, int Move);

int SC_Msg_WrapExpr(Message* Self, SCDecl* Src);

void SC_Msg_WrapFloatOrInt(Message* Self, uint /*DataTypeCode*/ T, int N, SCDecl* D);

JB_String* SC_Msg_WrapperCpp(Message* Self);

Message* SC_Msg_WrapWith(Message* Self, Syntax F, JB_String* S);

void JB_Msg_XAtt__(Message* Self, FastString* Fs);

void JB_Msg_XCDT__(Message* Self, FastString* Fs);

void JB_Msg_XCom__(Message* Self, FastString* Fs);

void JB_Msg_XDTD__(Message* Self, FastString* Fs);

void JB_Msg_XML__(Message* Self, FastString* Fs);

void JB_Msg_XPI__(Message* Self, FastString* Fs);

void JB_Msg_XTxt__(Message* Self, FastString* Fs);

bool JB_Msg_Yes(Message* Self, bool Default);

void JB_Msg_Yoda__(Message* Self, FastString* Fs);

Message* SC_Msg__NilchCompare();

SortComparison JB_Msg__Sorter(JB_List* Self, JB_List* B);

bool JB_Msg__TreeCompare(Message* Orig, Message* Reparse, bool PrintIfSame);

void JB_Msg__TreeComparePrint(Message* Orig);



// JB_MessageTable


// JB_SCDecl
SCDecl* SC_Decl_AccessToMemCpy(SCDecl* Self, Message* Exp, Message* Side, SCDecl* Type);

int SC_Decl_AccessType(SCDecl* Self, SCDecl* Access, Message* Ch);

SCDecl* SC_Decl_ActualReplace(SCDecl* Self, SCDecl* New);

bool SC_Decl_AddToGlobs(SCDecl* Self);

int SC_Decl_Alignment(SCDecl* Self, bool PutStructsAfter);

bool SC_Decl_AlreadyContains(SCDecl* Self);

void SC_Decl_AsBody(SCDecl* Self);

uint64 SC_Decl_AsConst(SCDecl* Self, Message* Value, uint /*DataTypeCode*/& Ty);

SCDecl* SC_Decl_AsLocal(SCDecl* Self);

void SC_Decl_ASMRegSet(SCDecl* Self, ASMReg Value);

DataTypeCode SC_Decl_ASMRegType(SCDecl* Self);

bool SC_Decl_AssignabilityCheck(SCDecl* Self, Message* Ln, Message* RN, SCDecl* Rc, bool WasHex);

JB_String* SC_Decl_AutoCompleteName(SCDecl* Self);

SCDecl* SC_Decl_AvoidGlobals(SCDecl* Self);

void SC_Decl_BecomeReal(SCDecl* Self);

int SC_Decl_BestFloat(SCDecl* Self, SCDecl* OT);

SCDecl* SC_Decl_Better_Numeric(SCDecl* Self, SCDecl* O, OpMode Mode, Message* Left, Message* Right);

SCClass* SC_Decl_Better_Numeric_Sub(SCDecl* Self, SCDecl* Ot, OpMode Op, Message* Left, Message* Right);

ASMReg SC_Decl_CalculateASMType(SCDecl* Self);

DataTypeCode SC_Decl_CalculateDataType(SCDecl* Self);

DataTypeCode SC_Decl_CalculateDataTypeSub(SCDecl* Self);

int SC_Decl_CalculateDeclSize(SCDecl* Self, int Depth);

bool SC_Decl_CanCompare(SCDecl* Self, SCDecl* Against, bool AsEquals);

bool SC_Decl_CanCopyNormally(SCDecl* Self);

bool SC_Decl_CanGetAddressSafely(SCDecl* Self);

bool SC_Decl_CanNilCheck(SCDecl* Self);

bool SC_Decl_CanRemoveArgOnReturn(SCDecl* Self, Message* R);

bool SC_Decl_CantBeNilInCpp(SCDecl* Self);

int SC_Decl_CanUpgradeRegister(SCDecl* Self);

bool SC_Decl_CanUseDefault(SCDecl* Self);

bool SC_Decl_CanWrap(SCDecl* Self);

SCDecl* SC_Decl_CArrayInner(SCDecl* Self);

int SC_Decl_CArraySize(SCDecl* Self, int Mul);

int SC_Decl_CArrayTotal(SCDecl* Self);

SCDecl* SC_Decl_CheckMath(SCDecl* Self, Message* Exp);

void SC_Decl_CheckUnusedDecl(SCDecl* Self, Message* Feedback, uint /*byte*/ Dbg);

bool SC_Decl_CompareUnclear(SCDecl* Self, SCDecl* D, bool MakesSenseVsZero);

int SC_Decl_Complexity(SCDecl* Self);

void SC_Decl_ConstInRange(SCDecl* Self, Message* RN, SCDecl* Rt, bool WasHex);

int64 SC_Decl_ConstInRangeSub(SCDecl* Self, int64 Value, bool WasHex);

SCDecl* SC_Decl_Constructor(SCDecl* Self, SCClass* Type);

SCDecl* SC_Decl_Containedfix(SCDecl* Self);

SCDecl* SC_Decl_ContainedReplace(SCDecl* Self, SCDecl* Contains, bool NeedsName);

bool SC_Decl_ContainsMatch(SCDecl* Self, SCDecl* O, int TypeCast);

SCDecl* SC_Decl_CopyDecl(SCDecl* Self, bool ForNewVariable);

SCDecl* SC_Decl_CopyDeclForVar(SCDecl* Self);

SCDecl* SC_Decl_CopyDeclsStructFixer(SCDecl* Self, Message* Src, DeclMode Mode, Message* Type);

void SC_Decl_CopyTypeInfoTo(SCDecl* Self, SCDecl* Dcl);

bool SC_Decl_CouldUpgradeToReal(SCDecl* Self);

Message* SC_Decl_CreateDefault(SCDecl* Self, Message* Errs, bool Isfunc);

Message* SC_Decl_CreateSimpleTypeCast(SCDecl* Self, Message* Exp);

Message* SC_Decl_CreateStructNil(SCDecl* Self, Message* Where);

Message* SC_Decl_CreateStructNilSub(SCDecl* Self);

Message* SC_Decl_DeclToAddr(SCDecl* Self, SCDecl* P0);

Message* SC_Decl_DeclToDot(SCDecl* Self, SCDecl* P0);

void SC_Decl_Destructor(SCDecl* Self);

SCDecl* SC_Decl_DownGrade(SCDecl* Self);

int SC_Decl_DumpCls(SCDecl* Self);

void SC_Decl_DumpDecl(SCDecl* Self, FastString* Dd, int Pos);

void SC_Decl_DumpWierdness(SCDecl* Self, FastString* J);

void SC_Decl_ExpectFail(SCDecl* Self, SCDecl* O, Message* Errnode, Message* Backup);

Message* SC_Decl_ExpectMatch(SCDecl* Self, SCDecl* O, int TypeCast, Message* Exp, Message* ErrNode);

Message* SC_Decl_ExpectMatchForDecl(SCDecl* Self, SCDecl* O, Message* Exp);

Message* SC_Decl_ExpectMatchSub(SCDecl* Self, SCDecl* O, int TypeCast, Message* Exp, Message* ErrNode);

bool SC_Decl_ExpectRelMatch(SCDecl* Self, SCDecl* O, Message* Exp, Message* Side, Message* ErrNode);

int64 SC_Decl_ExportPosition(SCDecl* Self);

void SC_Decl_ExportPositionSet(SCDecl* Self, int64 Value);

SCDecl* SC_Decl_ExtractAmount(SCDecl* Self, Message* Amount, SCNode* Name_space);

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

SCDecl* SC_Decl_Inner(SCDecl* Self);

bool SC_Decl_IntsOnly(SCDecl* Self, Message* Exp);

bool SC_Decl_IsBareStruct(SCDecl* Self);

bool SC_Decl_IsBool(SCDecl* Self);

bool SC_Decl_IsCArray(SCDecl* Self);

void SC_Decl_IsCarray(SCDecl* Self, int Size, SCDecl* Of);

bool SC_Decl_IsConstOf(SCDecl* Self, SCDecl* B);

bool SC_Decl_IsDataTypeOnly(SCDecl* Self);

bool SC_Decl_IsFloat(SCDecl* Self);

bool SC_Decl_IsInt(SCDecl* Self);

bool SC_Decl_IsInteger(SCDecl* Self);

int SC_Decl_IsLib(SCDecl* Self);

bool SC_Decl_IsMemoryOnly(SCDecl* Self);

bool SC_Decl_IsMostlyNormal(SCDecl* Self);

bool SC_Decl_IsNearlyNormalNumber(SCDecl* Self);

bool SC_Decl_IsNil(SCDecl* Self);

bool SC_Decl_IsNormal(SCDecl* Self);

bool SC_Decl_IsNormalBool(SCDecl* Self);

bool SC_Decl_IsNormalNumber(SCDecl* Self);

bool SC_Decl_IsNormalObject(SCDecl* Self);

int SC_Decl_IsNumeric(SCDecl* Self);

bool SC_Decl_IsObject(SCDecl* Self);

bool SC_Decl_IsReallyNumeric(SCDecl* Self);

bool SC_Decl_IsReffable(SCDecl* Self, bool SetOnly);

bool SC_Decl_IsReg(SCDecl* Self);

bool SC_Decl_IsRegister(SCDecl* Self);

void SC_Decl_IsTypeImproveSet(SCDecl* Self, bool Value);

bool SC_Decl_IsUintLike(SCDecl* Self);

bool SC_Decl_IsUnknownParam(SCDecl* Self);

bool SC_Decl_IsVoidPtr(SCDecl* Self);

bool SC_Decl_IsZero(SCDecl* Self);

bool SC_Decl_LoadContained(SCDecl* Self, Message* Contained, Message* Wrap, SCNode* Name_Space, DeclMode Purpose);

bool SC_Decl_LoadContainedSub(SCDecl* Self, SCDecl* Cont, Message* Wrap, SCNode* Name_Space, DeclMode Purpose);

bool SC_Decl_LocalIsUsed(SCDecl* Self);

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

SCDecl* SC_Decl_MakeReference(SCDecl* Self);

void SC_Decl_MarkAsAltered(SCDecl* Self);

void SC_Decl_MarkAsUsed(SCDecl* Self, Message* Side, Message* Exp);

bool SC_Decl_MatchC(SCDecl* Self, SCDecl* O);

SCDecl* SC_Decl_MemAccess(SCDecl* Self, Message* Access, Message* Side);

SCDecl* SC_Decl_MemAccessNonStorable(SCDecl* Self, Message* Exp, Message* Side);

SCDecl* SC_Decl_MemAccessSub(SCDecl* Self, Message* Exp, Message* Side);

bool SC_Decl_MiniMatch(SCDecl* Self, SCDecl* O, int TypeCast);

void SC_Decl_MiniName(SCDecl* Self, FastString* Fs);

void SC_Decl_NameSet(SCDecl* Self, JB_String* Value);

bool SC_Decl_NeedsContainedfix(SCDecl* Self);

bool SC_Decl_NeedsCppCarrayFix(SCDecl* Self);

SCDecl* SC_Decl_NewWrapper(SCDecl* Self, SCDecl* CastTo);

SCDecl* SC_Decl_NilConstructor(SCDecl* Self, uint /*NilState*/ Type);

NilState SC_Decl_NilCurr(SCDecl* Self);

void SC_Decl_NilPrmFail(SCDecl* Self, SCFunction* F);

bool SC_Decl_NilStated(SCDecl* Self);

void SC_Decl_NoBlindCasts(SCDecl* Self, SCDecl* Old, Message* Exp);

bool SC_Decl_NoStructOrCArrayCasts(SCDecl* Self, Message* Side);

SCDecl* SC_Decl_NotLocal(SCDecl* Self);

void SC_Decl_NumberConstSet(SCDecl* Self, uint64 V);

int SC_Decl_NumericCountWithBools(SCDecl* Self);

bool SC_Decl_OperatorExact_isa(SCDecl* Self, SCClass* V);

bool SC_Decl_MatchesDecl(SCDecl* Self, SCDecl* O);

bool SC_Decl_OperatorMatches(SCDecl* Self, SCClass* O);

void SC_Decl_Paramfix(SCDecl* Self);

int SC_Decl_PointerIncrement(SCDecl* Self);

bool SC_Decl_PointeryMatch(SCDecl* Self, SCDecl* O);

int SC_Decl_PointeryMatchSub(SCDecl* Self, SCDecl* O, int TypeCast);

void SC_Decl_PrefixedName(SCDecl* Self, FastString* Fs, SCModule* M);

JB_String* SC_Decl_PrmStateMsg(SCDecl* Self, JB_String* Needed);

SCDecl* SC_Decl_ProcessAs(SCDecl* Self, Message* Msg);

SCImport* SC_Decl_Project(SCDecl* Self);

void SC_Decl_Reach(SCDecl* Self);

SCDecl* SC_Decl_ReallyContains(SCDecl* Self);

JB_String* SC_Decl_RealName(SCDecl* Self);

Message* SC_Decl_RefDestructor(SCDecl* Self);

SCDecl* SC_Decl_RefineDecl(SCDecl* Self, Message* List);

int SC_Decl_Reg(SCDecl* Self);

JB_String* SC_Decl_Render(SCDecl* Self, FastString* Fs_in);

JB_String* SC_Decl_RenderTypeAndName(SCDecl* Self, int Minimal, FastString* Fs_in);

JB_String* SC_Decl_RenderTypeName(SCDecl* Self, FastString* Fs_in);

JB_String* SC_Decl_RenderTypeNameNicer(SCDecl* Self, FastString* Fs_in);

bool SC_Decl_SafelyWrappable(SCDecl* Self);

bool SC_Decl_SameForReplace(SCDecl* Self, SCDecl* C);

void SC_Decl_Sanity(SCDecl* Self);

int SC_Decl_SizeOfQuery(SCDecl* Self);

int SC_Decl_SortScore(SCDecl* Self);

bool SC_Decl_SpecialReg(SCDecl* Self);

NilState SC_Decl_StatedOptional(SCDecl* Self);

NilState SC_Decl_StatedReal(SCDecl* Self);

void SC_Decl_StoreExport(SCDecl* Self);

void SC_Decl_SyntaxAppend(SCDecl* Self, SCDeclInfo D);

bool SC_Decl_SyntaxIs(SCDecl* Self, SCDeclInfo D);

void SC_Decl_SyntaxIsSet(SCDecl* Self, SCDeclInfo D, bool Value);

byte SC_Decl_Trin(SCDecl* Self);

int SC_Decl_TryTypeCast(SCDecl* Self, SCDecl* O, Message* OExp, int TypeCast);

int SC_Decl_TryTypeCastCarray(SCDecl* Self, SCDecl* O, Message* Exp);

int SC_Decl_TryTypeCastDeref(SCDecl* Self, SCDecl* O, Message* Exp, int TypeCast);

int SC_Decl_TryTypeCastPointer(SCDecl* Self, SCDecl* O, Message* Exp, int TypeCast, bool CArray);

DataTypeCode SC_Decl_TypeInfo(SCDecl* Self);

bool SC_Decl_TypeIsReached(SCDecl* Self);

int SC_Decl_TypeMatch(SCDecl* Self, SCDecl* O, int TypeCast, Message* Exp);

DataTypeCode SC_Decl_TypeOnly(SCDecl* Self);

void SC_Decl_TypeReach(SCDecl* Self, SCNode* From, Message* Src);

bool SC_Decl_TypeSuffers(SCDecl* Self);

void SC_Decl_WholeTypeSet(SCDecl* Self, ASMReg Value);

ASMReg SC_Decl_WholeType(SCDecl* Self);

int SC_Decl_Wierdness(SCDecl* Self);

Message* SC_Decl_WriteDeclFull(SCDecl* Self, JB_String* DeclName, int Minimal);

Message* SC_Decl_WriteDeclSub(SCDecl* Self, JB_String* Name, int Minimal);

Message* SC_Decl_WriteDeclTypeAndName(SCDecl* Self, JB_String* Name, int Minimal);

Message* SC_Decl_WriteNilDecl(SCDecl* Self);

Message* SC_Decl_WriteNilRel(SCDecl* Self);

Message* SC_Decl_WriteSimpleType(SCDecl* Self, bool Optionals);

Message* SC_Decl_WriteType(SCDecl* Self, int Minimal, bool Optionals);

Message* SC_Decl_WriteTypeCast(SCDecl* Self, Message* Msg);

Message* SC_Decl_WriteVerySimpleType(SCDecl* Self);

SortComparison SC_Decl__Sorter(SCDecl* Self, SCDecl* B);



// JB_SCIterator
void SC_Iter_Check(SCIterator* Self, SCClass* Cls);

SCIterator* SC_Iter_Constructor(SCIterator* Self, Message* Msg);

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
void SC_Base_ActualAdd(SCNode* Self, JB_String* Name, SCObject* IncObj);

SCDecl* SC_Base_AddNumericConst(SCNode* Self, JB_String* Name, int64 Value, Message* Where);

uint64 SC_Base_CalculateConst(SCNode* Self, Message* Value);

uint64 SC_Base_CalculateConstRel(SCNode* Self, Message* Value, uint /*DataTypeCode*/& Ty);

uint64 SC_Base_CalculateConstSub(SCNode* Self, Message* Value, uint /*DataTypeCode*/& Ty);

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

Message* SC_Base_DiissplayObj(SCNode* Self, Message* M);

bool SC_Base_ExpectModule(SCNode* Self, Message* Errplace);

SCClass* SC_Base_FindClass(SCNode* Self, JB_String* Name, Message* Where, SCNodeFindMode Mode);

SCClass* SC_Base_FindClassMsg(SCNode* Self, Message* Where, SCNodeFindMode Mode);

Message* SC_Base_FindCppWrapper(SCNode* Self, Message* Place, bool Isclass);

SCFunction* SC_Base_FindFunction(SCNode* Self, JB_String* Name, Message* Where);

SCModule* SC_Base_FindModule(SCNode* Self, JB_String* Name, Message* Where, SCNodeFindMode Mode);

SCModule* SC_Base_FindModuleMsg(SCNode* Self, Message* Where, SCNodeFindMode Mode);

SCNode* SC_Base_FindModuleParent(SCNode* Self, SCNodeFindMode Mode);

bool SC_Base_FindVis(SCNode* Self, Message* C);

Message* SC_Base_FuncSrc(SCNode* Self);

void SC_Base_ImportFile(SCNode* Self, SCFile* File);

bool SC_Base_IsLibrary(SCNode* Self);

bool SC_Base_IsModuleFunc(SCNode* Self);

SCClass* SC_Base_IsNormalObject(SCNode* Self);

JB_String* SC_Base_LateAddTemporary(SCNode* Self, JB_String* Type, JB_String* Name1, Message* Value, Message* Err);

Message* SC_Base_LinkagePlace(SCNode* Self);

Array* SC_Base_ListFunctions(SCNode* Self);

bool SC_Base_LoadVisibility(SCNode* Self, Message* P);

JB_Object* SC_Base_LookUpDot(SCNode* Self, JB_String* Name, Message* Exp, SCNode* Arg_space, SCDecl* Contains, Message* Side);

SCObject* SC_Base_LookUpFunc(SCNode* Self, JB_String* Name, Message* Exp);

SCObject* SC_Base_LookUpSub(SCNode* Self, JB_String* OrigName, Message* Exp, SCNode* Arg_Space, SCDecl* Contains, Message* Side, int Purpose);

SCObject* SC_Base_LookUpVar(SCNode* Self, JB_String* Name, Message* Exp, Message* Side);

SCDecl* SC_Base_LookUpVarDecl(SCNode* Self, JB_String* Name);

SCObject* SC_Base_LookUpVarRootDecl(SCNode* Self, JB_String* Name, Message* Exp);

SCModule* SC_Base_Module(SCNode* Self);

SCFunction* SC_Base_OwningFunc(SCNode* Self);

SCNode* SC_Base_ProcessLinkage(SCNode* Self, Message* Node, Dictionary* Table, bool Strict);

SCNode* SC_Base_ProjectFix(SCNode* Self);

JB_String* SC_Base_ReachedName(SCNode* Self);

SCDecl* SC_Base_RequireContained(SCNode* Self, Message* Errplace);

Message* SC_Base_Route(SCNode* Self, JB_String* Name);

void SC_Base_SetInternal(SCNode* Self, Message* Node, ClassInfo Info);

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

bool SC_Base_UnReached(SCNode* Self, SCNode* From);

SCObject* SC_Base_UpCheck(SCNode* Self, JB_String* Name, bool LookUp);

SCNode* SC_Base_UpClass(SCNode* Self, Message* F);

void SC_Base_Use(SCNode* Self);

int SC_Base__Init_();

SCNode* SC_Base__LoadCppPart(Message* Node, SCNode* Name_space, Message* ErrPlace);



// JB_SpdProcess
bool JB_Proc_CommsOpen(SpdProcess* Self);

SpdProcess* JB_Proc_Constructor(SpdProcess* Self, JB_String* Path, SpdProcess_Thread Fn, PicoComms* Pico, Array* Params, uint /*ProcessMode*/ Mode);

void JB_Proc_Destructor(SpdProcess* Self);

void JB_Proc_Disconnect(SpdProcess* Self, JB_String* Why);

Message* JB_Proc_Get(SpdProcess* Self, float T);

bool JB_Proc_IsOpen(SpdProcess* Self);

bool JB_Proc_Send(SpdProcess* Self, Message* Msg);

int JB_Proc__Init_();



// JB_StringShared


// JB_StringThatWasReadSafely


// JB_StringZeroTerminated


// JB_Task
JB_Task* JB_Task_Constructor(JB_Task* Self, uint Obj, void* Func);

void JB_Task_Destructor(JB_Task* Self);



// JB_ValidatorAll


// JB_ValidatorSome


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



// JB_FileArchive


// JB_Macro
Message* SC_Macro_clean(Message* Self);

Message* JB_Macro_CallFast(Message* Self, Message* Prm1, Message* Prm2);

Message* JB_Macro_Source(Message* Self);

Message* JB_Macro__Build(Message* S);

int JB_Macro__Init_();



// JB_MessageID
MessageID* JB_ID_Constructor(MessageID* Self, JB_String* Name, Syntax Fn, uint64 ID);

void JB_ID_Destructor(MessageID* Self);

JB_String* JB_ID_Render(MessageID* Self, FastString* Fs_in);

SortComparison JB_ID__ByID(MessageID* Self, MessageID* B);



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

void SC_SCBetterNode_LoadExportName(SCBetterNode* Self);

void SC_SCBetterNode_ReadDescription(SCBetterNode* Self, Message* Msg);

void SC_SCBetterNode_SetExportName(SCBetterNode* Self, JB_String* Name, bool Explicit);



// JB_SCFile
Message* SC_File_AST(SCFile* Self);

Message* SC_File_ASTSub(SCFile* Self, bool Orig);

void SC_File_CollectGlobals(SCFile* Self, SCModule* P);

SCFile* SC_File_Constructor(SCFile* Self, JB_File* F, SCImport* P);

void SC_File_Destructor(SCFile* Self);

void SC_File_DetectInsecureWords(SCFile* Self);

Message* SC_File_GetMsg(SCFile* Self, int Pos);

Message* SC_File_Orig(SCFile* Self);

Message* SC_File_Start_AST(SCFile* Self);

void SC_File_Stop(SCFile* Self);

void SC_File_SyntaxAppend(SCFile* Self, SCClass* C);

void SC_File_Use(SCFile* Self);

int SC_File__Init_();

SortComparison SC_File__Sorter(SCFile* Self, SCFile* B);



// JB_config
Message* JB_config_ConfFirst(Message* Self);

JB_File* JB_config_Path(Message* Self);

bool JB_config_Save(Message* Self);

Message* JB_config__Create(JB_String* Path);



// JB_interface
void JB_SS_ParserCallBack_interface_SyntaxCall(JB_Task* Self, Message* Msg);



// JB_ParserCallBack
void JB_SS_ParserCallBack_run(ParserCallBack* Self, Message* Msg);



// JB_SCClass
void SC_Class_AddBehaviourOrInterface(SCClass* Self, SCNode* M);

void SC_Class_AfterAfterFuncs(SCClass* Self);

void SC_Class_AfterFuncsDecled(SCClass* Self);

void SC_Class_AlignProperties(SCClass* Self);

bool SC_Class_AlignSub(SCClass* Self, Array* Dest, SCDecl* D);

void SC_Class_AlignTo(SCClass* Self, Array* Dest, int Bits);

JB_String* SC_Class_APIStructName(SCClass* Self);

void SC_Class_BannedCheck(SCClass* Self, Message* Src);

JB_String* SC_Class_BehaviourName(SCClass* Self);

SCFunction* SC_Class_BestBehaviourFor(SCClass* Self, JB_String* Name);

int SC_Class_CalculateSize(SCClass* Self, int Depth);

bool SC_Class_CanCompareSub(SCClass* Self, JB_String* S, SCDecl* Against);

bool SC_Class_CanHaveEmptyConstructor(SCClass* Self);

void SC_Class_CheckAllocVsWrapper(SCClass* Self, SCFunction* F, bool IsConstructor);

void SC_Class_CheckIterator(SCClass* Self);

void SC_Class_CheckStateful(SCClass* Self, Message* Node);

void SC_Class_CheckUnusedClass(SCClass* Self, Message* Feedback);

void SC_Class_ClassCollect(SCClass* Self);

void SC_Class_CollectBehaviours(SCClass* Self, FastString* J, SCBehaviour* B);

bool SC_Class_CollectProp(SCClass* Self, Message* Msg);

void SC_Class_CollectProperties(SCClass* Self);

SCFunction* SC_Class_ConOrDesForCall(SCClass* Self, bool IsConstructor, int Task);

SCClass* SC_Class_Constructor(SCClass* Self, Message* Node, bool HasPtrs, SCModule* M);

bool SC_Class_ConstructorUsed(SCClass* Self);

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

Message* SC_Class_Falsify(SCClass* Self, Message* Ques);

void SC_Class_FillInterFaceIn(SCClass* Self, SCFunction* Fn, bool Late);

void SC_Class_FillInterFaceWrapper(SCClass* Self, SCFunction* Fn);

void SC_Class_FillRoleConstructor(SCClass* Self, SCFunction* Con);

void SC_Class_FillTaskConstructor(SCClass* Self, SCFunction* Con);

void SC_Class_FillTaskConstructorSub(SCClass* Self, Message* Con, Message* Before, int Depth);

SCFunction* SC_Class_FindAllocFunc(SCClass* Self, JB_String* Fname, bool DontCreate);

SCClass* SC_Class_FindContainedClass(SCClass* Self);

SCFunction* SC_Class_FindFunc(SCClass* Self, JB_String* Keyword, bool CheckParents, bool DoError);

void SC_Class_FindNilChecker(SCClass* Self);

SCDecl* SC_Class_FindPropAlignedTo(SCClass* Self, int Align);

SCFunction* SC_Class_FindSpecialFunc(SCClass* Self, JB_String* Keyword, bool CheckParents);

SCFunction* SC_Class_FirstDestructor(SCClass* Self);

int SC_Class_GetDepth(SCClass* Self);

SCClass* SC_Class_GetFlyingMemClass(SCClass* Self);

SCDecl* SC_Class_GetFlyingMemory(SCClass* Self, Message* Exp);

SCFunction* SC_Class_GetFunc(SCClass* Self, JB_String* Keyword, bool DoError);

SCIterator* SC_Class_GetIteratorAny(SCClass* Self, JB_String* Name, Message* Node);

SCClass* SC_Class_GoUpTo(SCClass* Self, int D);

bool SC_Class_HasObjectProperties(SCClass* Self);

bool SC_Class_HasOperator(SCClass* Self, JB_String* Op);

bool SC_Class_HasStuffToHandleInDestructor(SCClass* Self);

SCClass* SC_Class_HigherNumber(SCClass* Self);

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

bool SC_Class_IsStruct(SCClass* Self);

bool SC_Class_IsTask(SCClass* Self);

void SC_Class_Iterfailed(SCClass* Self, JB_String* Name, Message* Node);

void SC_Class_ListLayout(SCClass* Self, FastString* J);

void SC_Class_LoadClassType(SCClass* Self);

void SC_Class_LoadConstructors(SCClass* Self);

void SC_Class_LoadLinkage(SCClass* Self);

void SC_Class_LoadModuleForCls(SCClass* Self, Message* Node, SCNode* P);

void SC_Class_LoadSuperBehaviours(SCClass* Self);

void SC_Class_LoadSuperClass(SCClass* Self);

SCDecl* SC_Class_MakeClassType(SCClass* Self, SCDecl* TypeNormal);

int SC_Class_mini_size(SCClass* Self, int B);

void SC_Class_MissingVirtual(SCClass* Self, JB_String* S);

void SC_Class_ModelDecls(SCClass* Self);

void SC_Class_NeedsDefaultValue(SCClass* Self, Message* Def, Message** Place, JB_String* Name);

bool SC_Class_NeedsExport(SCClass* Self);

bool SC_Class_NeedsPackExport(SCClass* Self);

void SC_Class_NewDeclInClassModule(SCClass* Self, JB_String* S, SCClass* T);

SCDecl* SC_Class_NotConst(SCClass* Self);

int SC_Class_NumericCount(SCClass* Self);

ClassInfo SC_Class_NumericReduction(SCClass* Self);

void SC_Class_OverrideSyntax(SCClass* Self);

int SC_Class_PassableCount(SCClass* Self);

void SC_Class_ProcessBehaviours(SCClass* Self);

void SC_Class_ProcessBehavioursSub(SCClass* Self);

void SC_Class_ProcessInterfaces(SCClass* Self);

void SC_Class_Reach(SCClass* Self, SCNode* From, Message* Src);

void SC_Class_ReachBehaviours(SCClass* Self);

bool SC_Class_Real_Isa(SCClass* Self, SCClass* Cls);

bool SC_Class_Real_Isa2(SCClass* Self, SCClass* Cls);

SCClass* SC_Class_RealClass(SCClass* Self);

SCClass* SC_Class_RealSuper(SCClass* Self);

void SC_Class_RenameInterfaces(SCClass* Self);

JB_String* SC_Class_Render(SCClass* Self, FastString* Fs_in);

void SC_Class_SimplerDataTypes(SCClass* Self, FastString* Fs, SCDecl* D);

JB_String* SC_Class_StructName(SCClass* Self);

bool SC_Class_EqualsName(SCClass* Self, JB_String* Name);

bool SC_Class_EqualsType(SCClass* Self, SCNodeType D);

bool SC_Class_SyntaxIs(SCClass* Self, ClassInfo Cls);

void SC_Class_SyntaxIsSet(SCClass* Self, ClassInfo Cls, bool Value);

void SC_Class_TaskProperties(SCClass* Self);

bool SC_Class_TestBanned(SCClass* Self);

void SC_Class_TryAddToProject(SCClass* Self);

void SC_Class_WriteStructOrUnion(SCClass* Self, FastStringCpp* Fs);

SCModule* SC_Class__DataTypeSub(Message* Node, SCNode* Parent, Message* ErrPlace, JB_String* ForInterface, SCNodeType BaseType);

SCNode* SC_Class__ExtendOneFunc(Message* Node);

SCNode* SC_Class__GetDefault(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__GetFalse(Message* Node, SCNode* Name_space, Message* ErrPlace);

JB_String* SC_Class__LoadClassName(Message* Node);

SCNode* SC_Class__LoadSyntax(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__NeuClass(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCClass* SC_Class__NeuClassSub(Message* Node, SCNode* Parent, Message* ErrPlace, JB_String* ForInterface, SCNodeType Base);

SCNode* SC_Class__NeuRole(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__NewDataType(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__NewInnerClass(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__NewStruct(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__ProcessAs(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCFunction* SC_Class__ProcessExtend(Message* C, bool PreferClass, SCModule* M);

void SC_Class__ProcessExtendOld(Message* C, bool PreferClass);

SCNode* SC_Class__SetSize(Message* Node, SCNode* Name_space, Message* ErrPlace);

SortComparison SC_Class__Sorter(SCClass* Self, SCClass* B);

SCNode* SC_Class__StoreExtend(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Class__StoreExtendModule(Message* Node, SCNode* Name_space, Message* ErrPlace);



// JB_SCFunction
void SC_Func_AddConstructorReturn(SCFunction* Self, Message* Prms);

void SC_Func_AddConstructorReturn2(SCFunction* Self);

void SC_Func_AddSelfPrm(SCFunction* Self, SCClass* Cls);

void SC_Func_AddSelfToFunc(SCFunction* Self, SCClass* Cls, SCNode* Space);

void SC_Func_AddTrin(SCFunction* Self, Message* Msg);

void SC_Func_AddTypeInfo(SCFunction* Self, SCDecl* Dcl);

void SC_Func_AnalyseRefs(SCFunction* Self, Array* List);

int SC_Func_ApparantArgCount(SCFunction* Self);

SCFunction* SC_Func_ArgsMatch(SCFunction* Self, SCDecl* Base, SCNode* Name_space, SCParamArray* Incoming, int Failed);

SCFunction* SC_Func_ArgsMatch1(SCFunction* Self, SCDecl* Base, SCNode* Name_space, SCParamArray* Incoming, int Cast);

SCFunction* SC_Func_ArgsMatch2(SCFunction* Self, SCDecl* Base, int TypeCast, SCNode* Name_space, SCParamArray* Incoming);

int SC_Func_ArgsMatch3(SCFunction* Self, int TypeCast, SCDecl* Base, bool ThisAlter, SCNode* Name_space, SCParamArray* Incoming);

ASM* SC_Func_ASMBake(SCFunction* Self, ASM* Where, ASM* After, uint* Positions);

SCDecl* SC_Func_ASMReturnWith0(SCFunction* Self);

ASMReg SC_Func_ASMReturnWithReg(SCFunction* Self, ASMReg Dest);

void SC_Func_BeforeTransform(SCFunction* Self);

bool SC_Func_Borked(SCFunction* Self);

void SC_Func_BuildConstructorDestructor(SCFunction* Self);

void SC_Func_CallParents(SCFunction* Self);

void SC_Func_CallSuperMem(SCFunction* Self, SCFunction* Fn);

bool SC_Func_CanBuildConstructor(SCFunction* Self);

bool SC_Func_CanCompareAgainst(SCFunction* Self, SCDecl* Against);

bool SC_Func_CanLibLoad(SCFunction* Self);

bool SC_Func_CanPrepareInline(SCFunction* Self);

void SC_Func_CheckConstructorAndDestructor(SCFunction* Self, Message* Root, bool IsConstructor);

void SC_Func_CheckNotBadName(SCFunction* Self);

void SC_Func_CheckReturnValue(SCFunction* Self, Message* Msg, SCNode* Name_space);

void SC_Func_CheckUnused(SCFunction* Self, Message* Feedback);

void SC_Func_CheckUnusedArgs(SCFunction* Self, Message* Feedback);

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

Message* SC_Func_DeclAfter(SCFunction* Self, Message* After, SCDecl* Orig, SCDecl* D);

void SC_Func_DeclsProtoCleanup(SCFunction* Self, SCClass* fpType, Message* Ch0, bool AssumeSelf, bool Late, Message* Route);

void SC_Func_DeclsProtoCleanUpContainedness(SCFunction* Self, Message* P, Message* Ch0, SCClass* fpType);

SCDecl* SC_Func_DeclsProtoTypeAdd(SCFunction* Self, SCClass* fpType);

void SC_Func_DeclsPrototypeClass(SCFunction* Self, Message* Ch0);

void SC_Func_DeclsPrototypeInterface(SCFunction* Self, Message* Ch0, SCClass* fpType, bool Late);

JB_String* SC_Func_Describe(SCFunction* Self, FastString* Fs_in);

void SC_Func_DescribeParamFail(SCFunction* Self, SCParamArray* Params, int Bad);

void SC_Func_Destructor(SCFunction* Self);

void SC_Func_DetectIfReached(SCFunction* Self);

SCFunction* SC_Func_Disambiguate(SCFunction* Self, Message* Src);

void SC_Func_DoLinkToDecl(SCFunction* Self, SCDecl* Decl);

void SC_Func_DoLinkToNode(SCFunction* Self, SCNode* To);

void SC_Func_DontWantSameReturnType(SCFunction* Self, SCFunction* F);

bool SC_Func_DoRefs(SCFunction* Self);

void SC_Func_DotFuncToNormalFunc(SCFunction* Self, Message* Dot);

bool SC_Func_EqualOrMoreSpecific(SCFunction* Self, SCFunction* F);

JB_String* SC_Func_ExportNameBuilder(SCFunction* Self, JB_String* CppPart);

FatASM* SC_Func_FatFirst(SCFunction* Self);

void SC_Func_FillInDestructor(SCFunction* Self);

void SC_Func_FillInMissingConstructorDefaults(SCFunction* Self, Message* After);

Message* SC_Func_FindCallParents(SCFunction* Self);

Message* SC_Func_FindCppWrapperFunc(SCFunction* Self, Message* Place);

int SC_Func_FindDepths(SCFunction* Self);

void SC_Func_FixCnj(SCFunction* Self, Message* Exp);

void SC_Func_FixCnjSub(SCFunction* Self, Message* Exp);

void SC_Func_FLookupSet(SCFunction* Self, SCNode* Value);

bool SC_Func_FoundOneCpp(SCFunction* Self, JB_String* N);

void SC_Func_FuncParamsLoad(SCFunction* Self);

bool SC_Func_HasCVersion(SCFunction* Self);

bool SC_Func_HasProperSpeedieCode(SCFunction* Self);

bool SC_Func_HiderMatch(SCFunction* Self, bool IsAssigns);

void SC_Func_Init_Sub(SCFunction* Self, Message* Node, SCNode* Name_space);

SCObject* SC_Func_InsertIn(SCFunction* Self, SCNode* Parent, JB_String* Name);

bool SC_Func_IsAllocOrNew(SCFunction* Self);

bool SC_Func_IsARealSpdFunc(SCFunction* Self);

bool SC_Func_IsBehaviour(SCFunction* Self);

bool SC_Func_IsConstructorOnModule(SCFunction* Self, SCFunction* Old);

void SC_Func_IsCppInBuiltSet(SCFunction* Self, int Value);

bool SC_Func_IsOKConstructorCall(SCFunction* Self, SCClass* C);

bool SC_Func_IsReal(SCFunction* Self);

Message* SC_Func_IsSimpleCast(SCFunction* Self);

bool SC_Func_IsUnused(SCFunction* Self);

SCFunction* SC_Func_Last(SCFunction* Self);

SCDecl* SC_Func_MacroFix(SCFunction* Self, SCDecl* Contains, SCNode* Name_space, SCParamArray* Incoming);

void SC_Func_MakeConstructor(SCFunction* Self);

void SC_Func_MakeLibOnly(SCFunction* Self, Message* Node);

void SC_Func_MakeLinkInline(SCFunction* Self);

void SC_Func_MakeMacro(SCFunction* Self, Message* Arg);

void SC_Func_MakeNilChecker(SCFunction* Self, Message* Msg);

void SC_Func_MakeParamsReal(SCFunction* Self);

JB_String* SC_Func_MakeProtoClassName(SCFunction* Self, JB_String* Start);

void SC_Func_MarkRecursive(SCFunction* Self, SCFunction* EndAt);

SCFunction* SC_Func_MatchImprove(SCFunction* Self, SCParamArray* Incoming);

bool SC_Func_NeedsLibExport(SCFunction* Self);

bool SC_Func_NeedsStableID(SCFunction* Self);

void SC_Func_NilSelff(SCFunction* Self, Message* Where, uint /*NilState*/ V);

SCFunction* SC_Func_ParamlessConstructor(SCFunction* Self);

JB_String* SC_Func_ParamUniquer(SCFunction* Self, JB_String* S);

JB_String* SC_Func_ParentName(SCFunction* Self);

bool SC_Func_ParseName(SCFunction* Self, Message* Node);

void SC_Func_PostTrin(SCFunction* Self, Message* S);

void SC_Func_PreProcessExpects(SCFunction* Self);

void SC_Func_PreRead(SCFunction* Self, Message* Arg);

Message* SC_Func_Prms(SCFunction* Self);

void SC_Func_ProtoExportName(SCFunction* Self);

void SC_Func_Reach(SCFunction* Self);

void SC_Func_ReachFunc(SCFunction* Self, SCNode* From);

void SC_Func_ReachFuncFromFunc(SCFunction* Self, SCFunction* From);

void SC_Func_RefFunc(SCFunction* Self, Message* Prm, Message* After);

JB_String* SC_Func_Render(SCFunction* Self, FastString* Fs_in);

JB_String* SC_Func_RenderName(SCFunction* Self, FastString* Fs_in);

JB_String* SC_Func_RenderParams(SCFunction* Self, bool ForErrors, FastString* Fs_in);

JB_String* SC_Func_RenderSheBless(SCFunction* Self);

JB_String* SC_Func_RenderTitle(SCFunction* Self, bool ForErrors, FastString* Fs_in);

bool SC_Func_ReturnsObject(SCFunction* Self);

SCDecl* SC_Func_Self(SCFunction* Self);

void SC_Func_SetBlindCasts(SCFunction* Self, SCNode* Name_space);

Message* SC_Func_SourceArg(SCFunction* Self);

void SC_Func_SourceArgSet(SCFunction* Self, Message* Value);

void SC_Func_StatelessAccumulate(SCFunction* Self);

void SC_Func_StoreExport(SCFunction* Self);

SCDecl* SC_Func_StructReturned(SCFunction* Self);

void SC_Func_SubFuncParamsLoad(SCFunction* Self, Message* P);

bool SC_Func_SyntaxIs(SCFunction* Self, FunctionType K);

void SC_Func_SyntaxIsSet(SCFunction* Self, FunctionType K, bool Value);

void SC_Func_Transform(SCFunction* Self);

void SC_Func_TranStrings(SCFunction* Self);

void SC_Func_TryAdd(SCFunction* Self, SCNode* B);

SCFunction* SC_Func_TryKeepBetter(SCFunction* Self, int OldMatch, SCFunction* F, int Match);

bool SC_Func_Update_Source(SCFunction* Self, int Start, JB_String* Text);

bool SC_Func_UpdateSourceSub(SCFunction* Self, Message* Src, Array* List);

bool SC_Func_UseCppName(SCFunction* Self, JB_String* CppName);

bool SC_Func_UseExportWrapper(SCFunction* Self, JB_String* CppWrapper);

int SC_Func_VisibleArgs(SCFunction* Self);

void SC_Func_WantAs(SCFunction* Self, uint /*NilState*/ NS);

JB_String* SC_Func_WrappedName(SCFunction* Self);

Message* SC_Func__AlterPostCond(Message* PostCond, Message* IterPostCond, Message* NodeSrc);

Message* SC_Func__ArgToFunc(JB_String* NewName, Message* Params, Message* Arg);

bool SC_Func__CanKeepAsSource(Message* List, Message* Arg, SCDecl* D);

bool SC_Func__CanKeepAsValue(SCIterator* Iter, Message* Arg, SCDecl* Dcl, Message* Value);

void SC_Func__CurrFuncSet(SCFunction* Value);

SCFunction* SC_Func__CurrFunc();

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

void SC_Func__ObjectifyString(Message* Func);

void SC_Func__String_Expand(Message* Msg, SCFunction* Fn);

Message* SC_Func__TypedTempMoveOut(Message* Msg, JB_String* Name, SCDecl* Type);

Message* SC_Func__TempMoveOut(Message* Msg, Message* Place);

SCDecl* SC_Func__Tran_AfterRel(Message* Msg, SCNode* Name_space, Message* Side);

void SC_Func__Tran_All(SCFunction* Fn, Message* S, SCNode* P);

void SC_Func__Tran_All_Final(SCFunction* Fn, Message* S, SCNode* P, Syntax F);

void SC_Func__Tran_Array(Message* S, SCNode* Name_space);

bool SC_Func__Tran_Beep(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_BlindCasts(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_BreakPoint(SCFunction* Fn, SCNode* P, Message* Ch);

bool SC_Func__Tran_CppRefs(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_DebugAt(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Debugger(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Description(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Else(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Expect(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Fails(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_For(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_ForStart(Message* Arg, Message* Index, SCNode* P);

bool SC_Func__Tran_ForSub(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_FuncTable(Message* Msg);

bool SC_Func__Tran_If(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Ifn(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_IfSub(Message* Node, SCNode* Name_space);

void SC_Func__Tran_Isa(Message* S, SCNode* P);

bool SC_Func__Tran_NotAllowed(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Once(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_OneIsa(Message* Isa_f, Message* Arg, SCNode* Space);

bool SC_Func__Tran_Print(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_PrintSub(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Problem(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Quit(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Remove(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Render(Message* Msg, SCClass* Cls);

bool SC_Func__Tran_RenderSub(Message* Msg, SCClass* Cls);

Message* SC_Func__Tran_Result(SCFunction* F);

void SC_Func__Tran_ResultFinish(SCFunction* F, Message* R_z, SCNode* Space);

bool SC_Func__Tran_Return(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_Sdt(Message* Exp);

void SC_Func__Tran_Strings(Message* Start, SCFunction* Fn);

bool SC_Func__Tran_Swap(SCFunction* Fn, Message* Node, SCNode* Name_space);

Message* SC_Func__Tran_Syx(Message* Msg);

bool SC_Func__Tran_Temporal(SCFunction* Fn, Message* S, SCNode* Name_space);

bool SC_Func__Tran_TestProblem(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Using(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_Visible(SCFunction* Fn, Message* Node, SCNode* Name_space);

bool SC_Func__Tran_While(SCFunction* Fn, Message* Node, SCNode* Name_space);

void SC_Func__Tran_WhileSub(SCNode* Name_space, Message* Node);

void SC_Func__TransformAll();



// JB_SCModule
void SC_Mod_AddInterfaceToTable(SCModule* Self, SCClass* TableCls);

void SC_Mod_AddModuleToFunc(SCModule* Self, SCNode* Space);

bool SC_Mod_AvoidMain(SCModule* Self, Message* C);

void SC_Mod_BaseDecls(SCModule* Self);

Message* SC_Mod_BuildInitArg(SCModule* Self);

Message* SC_Mod_BuildInitArgSub(SCModule* Self);

void SC_Mod_CallInit(SCModule* Self, Message* Src, Message* Dest, JB_String* Fn_name);

void SC_Mod_CallOurInits(SCModule* Self, Message* DestVars, Message* DestCode);

void SC_Mod_CallOurInitsByTheBiggerInitFunc(SCModule* Self);

SCModule* SC_Mod_Constructor(SCModule* Self);

JB_String* SC_Mod_CppPath(SCModule* Self);

void SC_Mod_CreateInitFunc(SCModule* Self);

void SC_Mod_CreateInitFuncSub(SCModule* Self, Message* Init, JB_String* Name);

void SC_Mod_Destructor(SCModule* Self);

SCObject* SC_Mod_GetTheNewer(SCModule* Self);

void SC_Mod_GlobalsFix(SCModule* Self);

void SC_Mod_InitDeclFixer(SCModule* Self, Message* List);

void SC_Mod_InitDecls(SCModule* Self);

bool SC_Mod_InitRootDecl(SCModule* Self, Message* DeclMsg);

bool SC_Mod_IsProperModule(SCModule* Self);

void SC_Mod_LoadModule(SCModule* Self, Message* Node);

void SC_Mod_MoveToInitFunc(SCModule* Self, Message* C);

SCFunction* SC_Mod_NewModuleFunc(SCModule* Self, Message* Src);

SCModule* SC_Mod_OneOrOther(SCModule* Self, SCModule* B, JB_String* Name);

JB_String* SC_Mod_Render(SCModule* Self, FastString* Fs_in);

JB_String* SC_Mod_SafeName(SCModule* Self);

SCModule* SC_Mod_SuperMod(SCModule* Self);

bool SC_Mod_TryInit(SCModule* Self, Array* Req);

void SC_Mod_Use(SCModule* Self);

SCNode* SC_Mod__ConstantCollector(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCNode* SC_Mod__DoInitAfter(Message* Node, SCNode* Name_space, Message* ErrPlace);

int SC_Mod__Init_();

SCNode* SC_Mod__NeuModule(Message* Node, SCNode* Name_space, Message* ErrPlace);

SCModule* SC_Mod__NewContainer(JB_String* S);

SortComparison SC_Mod__Sorter(SCModule* Self, SCModule* B);

inline bool JB_CP_Bool(Codepoint Self);

inline bool JB_CP_In(Codepoint Self, int A, int B);

inline JB_Duration JB_Date_OperatorMinus(Date Self, Date D);

inline bool JB_ErrorInt_SyntaxCast(ErrorInt Self);

inline bool JB_ErrorMarker_SyntaxCast(ErrorMarker Self);

inline bool JB_ExitCode_IsRunning(ExitCode Self);

inline bool JB_ExitCode_NotStarted(ExitCode Self);

inline bool JB_ExitCode_Successful(ExitCode Self);

inline bool JB_FailableInt_SyntaxCast(FailableInt Self);

inline bool JB_FastBuff_AppendU8(FastBuff* Self, uint /*byte*/ V);

inline byte JB_FastBuff_Byte(FastBuff* Self);

inline bool JB_FastBuff_HasAny(FastBuff* Self);

inline int JB_FastBuff_Position(FastBuff* Self);

inline int JB_FastBuff_Remaining(FastBuff* Self);

inline bool JB_FileDes_SyntaxCast(FileDes Self);

inline bool JB_FileSizeInt_SyntaxCast(FileSizeInt Self);

inline bool JB_File_Opened(JB_File* Self);

inline JB_String* JB_File__Applications();

inline bool JB_Ind_SyntaxCast(Ind Self);

inline bool JB_MaybeBool_Default(MaybeBool Self);

inline bool JB_MaybeBool_IsKnown(MaybeBool Self);

inline bool JB_MaybeBool_KnownFalse(MaybeBool Self);

inline bool JB_MaybeBool_KnownTrue(MaybeBool Self);

inline MaybeBool JB_MaybeBool_Negate(MaybeBool Self);

inline MaybeBool JB_MaybeBool__Default(bool Default);

inline MaybeBool JB_MaybeBool__Known(bool As);

inline int JB_Mrap_ByteCapacity(MWrap* Self);

inline byte* JB_Mrap_Ptr(MWrap* Self);

inline int JB_Msg_After(Message* Self);

inline void JB_Msg_AfterSet(Message* Self, int Value);

inline void JB_Msg_BecomeStr(Message* Self, Syntax Fn, JB_String* Name);

inline Syntax JB_Msg_Func(Message* Self);

inline JB_String* JB_Msg_Name(Message* Self);

inline PicoConfig* JB_Pico_Config(PicoComms* Self);

inline int JB_Rec_BadCount(JB_ErrorReceiver* Self);

inline ErrorMarker JB_Rec_Mark(JB_ErrorReceiver* Self);

inline int JB_Rg_Width(IntRange Self);

inline int JB_Sel_ID(Selector* Self);

inline JB_String* JB_Str_MulBool(JB_String* Self, bool B);

inline _cstring JB_Str_SyntaxCast(JB_StringC* Self);

inline TerminalColor JB_Str_TerminalColor(JB_String* Self);

inline DataTypeCode JB_TC_Basictype(uint /*DataTypeCode*/ Self);

inline uint JB_TC_ByteShift(uint /*DataTypeCode*/ Self);

inline bool JB_TC_IsFloat(uint /*DataTypeCode*/ Self);

inline bool JB_TC_IsSigned(uint /*DataTypeCode*/ Self);

inline bool JB_TC_SyntaxIs(uint /*DataTypeCode*/ Self, uint /*DataTypeCode*/ M);

inline DataTypeCode JB_TC_SyntaxIsSet(uint /*DataTypeCode*/ Self, uint /*DataTypeCode*/ M, bool Value);

inline int JB_TC_VecCount(uint /*DataTypeCode*/ Self);

inline DataTypeCode JB_TC_VecCountSet(uint /*DataTypeCode*/ Self, int Value);

inline ivec2 JB_TerminalDisplay_Size(TerminalDisplay* Self);

inline JB_String* JB_Tk__SyntaxAccess(int S, int E, Syntax F);

inline int64 JB_Wrap_SyntaxAccess(DTWrap* Self);

inline int64 JB_Wrap_Value(DTWrap* Self);

inline bool JB_dylib_IsOpen(JB_Dylib* Self);

inline bool JB_int64_IsPow2(int64 Self);

inline Float64 JB_int64_OperatorDiv(int64 Self, int64 D);

inline bool JB_int64_OperatorInRange(int64 Self, int64 Length);

inline int JB_int_AlignUp(int Self, int To);

inline bool JB_int_IsPow2(int Self);

inline float JB_int_OperatorDiv(int Self, int D);

inline bool JB_int_OperatorInRange(int Self, int Length);

inline bool JB_int_OperatorIsa(int Self, uint N);

inline IntRange JB_int_OperatorTo(int Self, int Other);

inline int JB_ivec2_Width(ivec2 Self);

inline bool SC_PA_SyntaxCast(SCParamArray* Self);

inline DataTypeCode SC_Reg_xC2xB5Type(ASMReg Self);

inline JB_String* SC_SCObject_Name(SCObject* Self);

inline void JB_Array_SyntaxAppend(Array* Self, JB_Object* Item);

inline bool JB_Array_SyntaxCast(Array* Self);

inline int JB_Array_SyntaxCompare(Array* Self, int N);

inline bool JB_Array_SyntaxEquals(Array* Self, int N);

inline JB_String* JB_CP_AsString(Codepoint Self);

inline bool JB_CP_IsHigher(Codepoint Self);

inline bool JB_CP_IsLower(Codepoint Self);

inline bool JB_CP_IsUpper(Codepoint Self);

inline void JB_ClassData_Restore(JB_Class* Self);

inline void JB_FS_AppendBool(FastString* Self, bool B);

inline void JB_FS_AppendByte2(FastString* Self, uint /*byte*/ Data);

inline void JB_FS_AppendFastString(FastString* Self, FastString* Fs);

inline void JB_FS_AppendFloat(FastString* Self, float D, int Dp, bool CanExp);

inline void JB_FS_AppendInt32(FastString* Self, int Data);

inline void JB_FS_AppendInt64(FastString* Self, int64 Data);

inline void JB_FS_AppendUint(FastString* Self, uint Data);

inline void JB_FS_AppendUint16(FastString* Self, uint /*u16*/ Data);

inline JB_String* JB_FS_SyntaxCast(FastString* Self);

inline bool JB_File_FileExistance(JB_File* Self);

inline bool JB_File_OperatorIsNewerThan(JB_File* Self, Date F);

inline bool JB_File_SyntaxEquals(JB_File* Self, JB_String* S, bool Aware);

inline bool JB_Macro_Cleaned(Message* Self);

inline void JB_Macro_CleanedSet(Message* Self, bool Value);

inline byte* JB_Mrap__Zalloc(int N);

inline bool JB_Msg_IsString(Message* Self);

inline int JB_Msg_Length(Message* Self);

inline void JB_MzSt_End(CompressionStats* Self);

inline JB_String* JB_Object___Render__(JB_Object* Self, FastString* Fs_in);

inline bool JB_Platform__CPU_ARM();

inline bool JB_Platform__CPU_Intel();

inline bool JB_Platform__CPU_Spd();

inline int JB_Platform__PointerBytes();

inline bool JB_Platform__Release();

inline void JB_Print(JB_String* Data);

inline void JB_PrintLine(JB_String* Data);

inline JB_StringC* JB_Str_CastZero(JB_String* Self);

inline int JB_Str_CompareInt(JB_String* Self, int Other);

inline bool JB_Str_EqualsInt(JB_String* Self, int Other);

inline JB_String* JB_Str_Escape(JB_String* Self);

inline JB_String* JB_Str_EscapeChr(JB_String* Self);

inline Ind JB_Str_FindByte(JB_String* Self, uint /*byte*/ Find, int Start, int After);

inline Float64 JB_Str_Float(JB_String* Self, bool Suffixes);

inline int64 JB_Str_Int(JB_String* Self);

inline int JB_Str_OperatorMinus(JB_String* Self, JB_String* S);

inline bool JB_Str_OperatorStarts(JB_String* Self, JB_String* S);

inline Ind JB_Str_OutByteWithByteIntInt(JB_String* Self, uint /*byte*/ Find, int Start, int After);

inline JB_String* JB_Str_Unescape(JB_String* Self);

inline int JB_TC_ByteCount(uint /*DataTypeCode*/ Self);

inline bool JB_TC_IsInt(uint /*DataTypeCode*/ Self);

inline int JB_TC_ItemBitCount(uint /*DataTypeCode*/ Self);

inline Codepoint JB_TerminalDisplay_SyntaxAccess(TerminalDisplay* Self);

inline bool JB_Tree_OperatorIn(JB_List* Self, JB_List* F);

inline bool JB_Tree_SyntaxEquals(JB_List* Self, int N);

inline bool JB_byte_IsWhite(uint /*byte*/ Self);

inline JB_String* JB_cstring_Wrap(_cstring Self);

inline int JB_int64_Log2(int64 Self);

inline int JB_int_SyntaxCompare(int Self, JB_String* S);

inline int JB_uint_Log2(uint Self);

inline ASM* SC_FAT_xC2xB5RenderInto(FatASM* Self, ASM* Where, ASM* After);

inline ASMReg SC_Pac_GetASM(Assembler* Self, Message* Exp, ASMReg Dest);

inline bool SC_Reg_FourBytes(ASMReg Self);

inline bool SC_Reg_IsBig(ASMReg Self);

inline bool SC_Reg_IsBool(ASMReg Self);

inline bool SC_Reg_IsFloat(ASMReg Self);

inline bool SC_Reg_IsSmall(ASMReg Self);

inline NilState SC_nil_SetNilness(ArchonPurger* Self, SCDecl* D, uint /*NilState*/ New);

inline bool JB_Safe_SyntaxCast(JB_String* Self);

inline bool JB_Str_ContainsByte(JB_String* Self, uint /*byte*/ B);

inline Ind JB_Str_InWhite(JB_String* Self, int Start, int After);

inline bool JB_Str_IsInt(JB_String* Self);

inline Ind JB_Str_OutCharSet(JB_String* Self, CharSet Find, int From, int After);

inline Ind JB_Str_OutWhite(JB_String* Self, int Start, int After);

inline int JB_TC_Floatness(uint /*DataTypeCode*/ Self);

inline bool JB_byte_IsLower(uint /*byte*/ Self);

inline bool JB_byte_IsUpper(uint /*byte*/ Self);

inline ASMReg SC_Reg_BoolCondAnswer(ASMReg Self);

inline ASMReg SC_Reg_BoolNegateAnswer(ASMReg Self);

inline bool SC_Reg_IsInt(ASMReg Self);

inline bool JB_CharSet_ContainsStr(CharSet Self, JB_String* S);

inline void JB_FS_AppendTermCol(FastString* Self, TerminalColor Col);

inline JB_File* JB_File__Logs();

inline void JB_Msg_AppendSyx(Message* Self, Syntax Fn, JB_String* Name);

inline Message* JB_Syx_OperatorPlus(Syntax Self, JB_String* M);

inline bool JB_byte_IsLetter(uint /*byte*/ Self);

inline JB_String* JB_config_AsString(Message* Self);

inline Message* JB_Str_Msg(JB_String* Self);

inline Array* JB_Str_OperatorDivide(JB_String* Self, uint /*byte*/ Sep);

inline Array* JB_Str_Words(JB_String* Self);

inline Message* JB_int64_Msg(int64 Self);

inline Message* JB_int_Msg(int Self);

inline bool JB_Str_OperatorEndsWith(JB_String* Self, JB_String* S);

inline JB_String* JB_App__AppName();

inline void JB_Msg_Fail(Message* Self, JB_String* Error);

inline void JB_Msg_SyntaxProblem(Message* Self, JB_String* Error);

inline void JB_Str_SyntaxProblem(JB_String* Self);

inline JB_File* JB_File_SyntaxAccess(JB_File* Self, JB_String* Name);

inline Message* JB_Msg_Arg(Message* Self);

inline bool JB_Msg_ContainsStr(Message* Self, JB_String* S);

inline Message* JB_Msg_NeedFirst(Message* Self);

inline bool JB_App__No(JB_String* Name);

inline void JB_MzSt_Print(CompressionStats* Self);

inline void SC_Pac_SoftNopRange(Assembler* Self, FatASM* Start, FatASM* After);

inline bool JB_Str_CompressTestSub_(JB_String* Self, int Strength, bool Report);

inline bool JB_Str_CompressTest_(JB_String* Self, bool Report, int Which);

inline ASMReg SC_Pac_ImproveAssign(Assembler* Self, ASMReg Dest, ASMReg Src);

inline ASMReg SC_Pac_Exists(Assembler* Self, ASMReg Dest, ASMReg L, Message* Exp);

inline Message* JB_Macro_Run(Message* Self, Array* Prms);

inline FatASM* SC_Pac_Read(Assembler* Self, ASMReg Dest, Message* Exp, ASMReg Ptr, ASMReg VarAdd, SCDecl* ReadDecl, int Index);

inline FatASM* SC_Pac_Write(Assembler* Self, ASMReg Value, Message* Exp, ASMReg Ptr, ASMReg VarAdd, SCDecl* DestDecl, int Index);


//// HEADER Inlines.h
inline bool JB_CP_Bool(Codepoint Self) {
	//cpp_part;
	return Self > 0;
}

inline bool JB_CP_In(Codepoint Self, int A, int B) {
	return ((uint)(Self - A)) <= ((uint)(B - A));
}

inline JB_Duration JB_Date_OperatorMinus(Date Self, Date D) {
	return ((int64)Self) - ((int64)D);
}

inline bool JB_ErrorInt_SyntaxCast(ErrorInt Self) {
	return Self == 0;
}

inline bool JB_ErrorMarker_SyntaxCast(ErrorMarker Self) {
	return JB_StdErr->ErrorCount == Self;
}

inline bool JB_ExitCode_IsRunning(ExitCode Self) {
	return (Self == -1) or (Self == kJB__ExitCode_EINPROGRESS);
}

inline bool JB_ExitCode_NotStarted(ExitCode Self) {
	return Self < -1;
}

inline bool JB_ExitCode_Successful(ExitCode Self) {
	return Self == 0;
}

inline bool JB_FailableInt_SyntaxCast(FailableInt Self) {
	return Self != ((int)kJB__FailableInt_Fail);
}

inline bool JB_FastBuff_AppendU8(FastBuff* Self, uint /*byte*/ V) {
	//cpp_part;
	Self->Curr++[0] = V;
	return Self->Curr >= Self->End;
}

inline byte JB_FastBuff_Byte(FastBuff* Self) {
	return Self->Curr++[0];
}

inline bool JB_FastBuff_HasAny(FastBuff* Self) {
	//cpp_part;
	return Self->End > Self->Curr;
}

inline int JB_FastBuff_Position(FastBuff* Self) {
	return ((int)(Self->Curr - Self->Start));
}

inline int JB_FastBuff_Remaining(FastBuff* Self) {
	return ((int)(Self->End - Self->Curr));
}

inline bool JB_FileDes_SyntaxCast(FileDes Self) {
	return Self >= 0;
}

inline bool JB_FileSizeInt_SyntaxCast(FileSizeInt Self) {
	return Self >= 0;
}

inline bool JB_File_Opened(JB_File* Self) {
	return Self->Descriptor >= 0;
}

inline JB_String* JB_File__Applications() {
	return JB_LUB[2];
}

inline bool JB_Ind_SyntaxCast(Ind Self) {
	return Self >= 0;
}

inline bool JB_MaybeBool_Default(MaybeBool Self) {
	return ((bool)(((byte)Self) & 1));
}

inline bool JB_MaybeBool_IsKnown(MaybeBool Self) {
	return ((byte)Self) <= 1;
}

inline bool JB_MaybeBool_KnownFalse(MaybeBool Self) {
	return ((byte)Self) == 0;
}

inline bool JB_MaybeBool_KnownTrue(MaybeBool Self) {
	return ((byte)Self) == 1;
}

inline MaybeBool JB_MaybeBool_Negate(MaybeBool Self) {
	return ((MaybeBool)(((byte)Self) ^ 1));
}

inline MaybeBool JB_MaybeBool__Default(bool Default) {
	return ((MaybeBool)(8 + Default));
}

inline MaybeBool JB_MaybeBool__Known(bool As) {
	return ((MaybeBool)(As));
}

inline int JB_Mrap_ByteCapacity(MWrap* Self) {
	return ((int)Self->ItemSize) * ((int)Self->Size);
}

inline byte* JB_Mrap_Ptr(MWrap* Self) {
	return ((byte*)Self->_Ptr);
}

inline int JB_Msg_After(Message* Self) {
	return Self->Position + Self->RangeLength;
}

inline void JB_Msg_AfterSet(Message* Self, int Value) {
	Self->RangeLength = (Value - Self->Position);
}

inline void JB_Msg_BecomeStr(Message* Self, Syntax Fn, JB_String* Name) {
	//cpp_part;
	Self->Func = Fn;
	JB_SetRef(Self->Name, Name);
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

inline PicoConfig* JB_Pico_Config(PicoComms* Self) {
	return ((PicoConfig*)Self);
}

inline int JB_Rec_BadCount(JB_ErrorReceiver* Self) {
	//visible;
	return Self->ErrorCount + Self->ProblemCount;
}

inline ErrorMarker JB_Rec_Mark(JB_ErrorReceiver* Self) {
	return Self->ErrorCount;
}

inline int JB_Rg_Width(IntRange Self) {
	return Self[1] - Self[0];
}

inline int JB_Sel_ID(Selector* Self) {
	if (Self) {
		return Self->ID;
	}
	return 0;
}

inline JB_String* JB_Str_MulBool(JB_String* Self, bool B) {
	//cpp_part;
	return ((JB_String*)JB_Ternary(B, Self, JB_LUB[0]));
}

inline _cstring JB_Str_SyntaxCast(JB_StringC* Self) {
	return ((_cstring)Self->Addr);
}

inline TerminalColor JB_Str_TerminalColor(JB_String* Self) {
	return (((int64)Self) >> 60) + kJB__TerminalColor_Black;
}

inline DataTypeCode JB_TC_Basictype(uint /*DataTypeCode*/ Self) {
	return Self & (128 + (8 + 3));
}

inline uint JB_TC_ByteShift(uint /*DataTypeCode*/ Self) {
	return (Self >> 4) & 3;
}

inline bool JB_TC_IsFloat(uint /*DataTypeCode*/ Self) {
	return ((bool)((Self >> 7) & 1));
}

inline bool JB_TC_IsSigned(uint /*DataTypeCode*/ Self) {
	return (!(Self & kJB__TC_Unsigned));
}

inline bool JB_TC_SyntaxIs(uint /*DataTypeCode*/ Self, uint /*DataTypeCode*/ M) {
	return (Self & M) == M;
}

inline DataTypeCode JB_TC_SyntaxIsSet(uint /*DataTypeCode*/ Self, uint /*DataTypeCode*/ M, bool Value) {
	if (Value) {
		return Self | M;
	}
	return Self & (~M);
}

inline int JB_TC_VecCount(uint /*DataTypeCode*/ Self) {
	return (Self & 3) + 1;
}

inline DataTypeCode JB_TC_VecCountSet(uint /*DataTypeCode*/ Self, int Value) {
	return (Self & (~3)) | (Value - 1);
}

inline ivec2 JB_TerminalDisplay_Size(TerminalDisplay* Self) {
	return ivec2{kJB__TerminalDisplay_w, kJB__TerminalDisplay_h};
}

inline JB_String* JB_Tk__SyntaxAccess(int S, int E, Syntax F) {
	return (JB__Tk_Splitter)(S, E, F);
}

inline int64 JB_Wrap_SyntaxAccess(DTWrap* Self) {
	if (Self) {
		return Self->PrivValue;
	}
	return 0;
}

inline int64 JB_Wrap_Value(DTWrap* Self) {
	if (Self) {
		return Self->PrivValue;
	}
	return 0;
}

inline bool JB_dylib_IsOpen(JB_Dylib* Self) {
	return Self->handle != nil;
}

inline bool JB_int64_IsPow2(int64 Self) {
	if (Self) {
		return (!(Self & (Self - 1)));
	}
	return false;
}

inline Float64 JB_int64_OperatorDiv(int64 Self, int64 D) {
	return ((Float64)Self) / ((Float64)D);
}

inline bool JB_int64_OperatorInRange(int64 Self, int64 Length) {
	if (Length >= 0) {
		return (((uint64)Self) < ((uint64)Length));
	}
	return false;
}

inline int JB_int_AlignUp(int Self, int To) {
	return Self + ((-((uint)Self)) % To);
}

inline bool JB_int_IsPow2(int Self) {
	if (Self) {
		return (!(Self & (Self - 1)));
	}
	return false;
}

inline float JB_int_OperatorDiv(int Self, int D) {
	return ((float)Self) / ((float)D);
}

inline bool JB_int_OperatorInRange(int Self, int Length) {
	if (Length >= 0) {
		return (((uint)Self) < ((uint)Length));
	}
	return false;
}

inline bool JB_int_OperatorIsa(int Self, uint N) {
	return (!(Self % N));
}

inline IntRange JB_int_OperatorTo(int Self, int Other) {
	return ((IntRange)ivec2{Self, Other + 1});
}

inline int JB_ivec2_Width(ivec2 Self) {
	return Self[1] - Self[0];
}

inline bool SC_PA_SyntaxCast(SCParamArray* Self) {
	return (Self != nil) and Self->HasProperParams;
}

inline DataTypeCode SC_Reg_xC2xB5Type(ASMReg Self) {
	return ((DataTypeCode)Self) & kJB__TC_PossibleBits;
}

inline JB_String* SC_SCObject_Name(SCObject* Self) {
	if (Self) {
		return Self->Name;
	}
	return JB_LUB[13];
}

inline void JB_Array_SyntaxAppend(Array* Self, JB_Object* Item) {
	JB_Array_AppendCount(Self, Item, 1);
}

inline bool JB_Array_SyntaxCast(Array* Self) {
	return JB_Array_Size(Self) > 0;
}

inline int JB_Array_SyntaxCompare(Array* Self, int N) {
	return JB_Array_Size(Self) - N;
}

inline bool JB_Array_SyntaxEquals(Array* Self, int N) {
	return JB_Array_Size(Self) == N;
}

inline JB_String* JB_CP_AsString(Codepoint Self) {
	//cpp_part;
	return JB_Str_ChrUTF8(Self);
}

inline bool JB_CP_IsHigher(Codepoint Self) {
	return JB_CP_In(Self, 128, 1114111);
}

inline bool JB_CP_IsLower(Codepoint Self) {
	return JB_CP_In(Self, 'a', 'z');
}

inline bool JB_CP_IsUpper(Codepoint Self) {
	return JB_CP_In(Self, 'A', 'Z');
}

inline void JB_ClassData_Restore(JB_Class* Self) {
	JB_Mem_Use(JB_Class_DefaultLayer(Self));
}

inline void JB_FS_AppendBool(FastString* Self, bool B) {
	//cpp_name;
	JB_FS_AppendString(Self, JB_bool_Render0(B));
}

inline void JB_FS_AppendByte2(FastString* Self, uint /*byte*/ Data) {
	//cpp_part;
	JB_FS_AppendByte(Self, Data);
}

inline void JB_FS_AppendFastString(FastString* Self, FastString* Fs) {
	//cpp_part;
	JB_FS_AppendString(Self, ((JB_String*)Fs));
}

inline void JB_FS_AppendFloat(FastString* Self, float D, int Dp, bool CanExp) {
	JB_FS_AppendDoubleAsText(Self, ((Float64)D), Dp, CanExp);
}

inline void JB_FS_AppendInt32(FastString* Self, int Data) {
	//cpp_part;
	JB_FS_AppendIntegerAsText(Self, Data, 1);
}

inline void JB_FS_AppendInt64(FastString* Self, int64 Data) {
	//cpp_part;
	JB_FS_AppendIntegerAsText(Self, Data, 1);
}

inline void JB_FS_AppendUint(FastString* Self, uint Data) {
	//cpp_part;
	JB_FS_AppendIntegerAsText(Self, Data, 1);
}

inline void JB_FS_AppendUint16(FastString* Self, uint /*u16*/ Data) {
	//cpp_part;
	JB_FS_AppendIntegerAsText(Self, Data, 1);
}

inline JB_String* JB_FS_SyntaxCast(FastString* Self) {
	return JB_FS_GetResult(Self);
}

inline bool JB_File_FileExistance(JB_File* Self) {
	//cpp_part;
	return JB_File_Exists(((JB_String*)Self));
}

inline bool JB_File_OperatorIsNewerThan(JB_File* Self, Date F) {
	return (JB_File_Modified(Self) > F);
}

inline bool JB_File_SyntaxEquals(JB_File* Self, JB_String* S, bool Aware) {
	return JB_Str_Equals(Self, S, Aware);
}

inline bool JB_Macro_Cleaned(Message* Self) {
	return JB_Msg_SyntaxIs(Self, kJB__MsgParseFlags_MacroMade);
}

inline void JB_Macro_CleanedSet(Message* Self, bool Value) {
	((JB_Msg_SyntaxIsSet(Self, kJB__MsgParseFlags_MacroMade, Value)));
}

inline byte* JB_Mrap__Zalloc(int N) {
	return JB_Realloc(nil, N);
}

inline bool JB_Msg_IsString(Message* Self) {
	if (Self) {
		return JB_Syx_IsString(Self->Func);
	}
	return false;
}

inline int JB_Msg_Length(Message* Self) {
	return JB_Str_Length(Self->Name);
}

inline void JB_MzSt_End(CompressionStats* Self) {
	Self->Duration = (Self->Duration + JB_Date__Now());
}

inline JB_String* JB_Object___Render__(JB_Object* Self, FastString* Fs_in) {
	Object_Behaviour* Table = ((Object_Behaviour*)JB_ObjClassBehaviours(Self));
	return (((__Object_Render__)(Table->render)))(Self, Fs_in);
}

inline bool JB_Platform__CPU_ARM() {
	return ((bool)(JB_Platform__CPU() & 2));
}

inline bool JB_Platform__CPU_Intel() {
	return ((bool)(JB_Platform__CPU() & 4));
}

inline bool JB_Platform__CPU_Spd() {
	return ((bool)(JB_Platform__CPU() & 1));
}

inline int JB_Platform__PointerBytes() {
	return JB_PointerSize() >> 3;
}

inline bool JB_Platform__Release() {
	return (!JB_IsDebug());
}

inline void JB_Print(JB_String* Data) {
	JB_Str_Print(Data);
}

inline void JB_PrintLine(JB_String* Data) {
	JB_Str_PrintLine(Data);
}

inline JB_StringC* JB_Str_CastZero(JB_String* Self) {
	//cpp_part;
	return JB_Str_MakeC(Self);
}

inline int JB_Str_CompareInt(JB_String* Self, int Other) {
	//cpp_part;
	return JB_Str_Length(Self) - Other;
}

inline bool JB_Str_EqualsInt(JB_String* Self, int Other) {
	//cpp_part;
	return JB_Str_Length(Self) == Other;
}

inline JB_String* JB_Str_Escape(JB_String* Self) {
	return JB_Str_MultiReplaceAll(Self, JB__Constants_EscapeStr, JB_StdErr);
}

inline JB_String* JB_Str_EscapeChr(JB_String* Self) {
	return JB_Str_MultiReplaceAll(Self, JB__Constants_EscapeChr, JB_StdErr);
}

inline Ind JB_Str_FindByte(JB_String* Self, uint /*byte*/ Find, int Start, int After) {
	//cpp_part;
	return JB_Str_InByte(Self, Start, After, Find);
}

inline Float64 JB_Str_Float(JB_String* Self, bool Suffixes) {
	return JB_Str_TextDouble(Self, nil, Suffixes);
}

inline int64 JB_Str_Int(JB_String* Self) {
	return JB_Str_TextIntegerValid(Self, nil);
}

inline int JB_Str_OperatorMinus(JB_String* Self, JB_String* S) {
	return JB_Str_Length(Self) - JB_Str_Length(S);
}

inline bool JB_Str_OperatorStarts(JB_String* Self, JB_String* S) {
	return JB_Str_MidEquals(Self, 0, S, true);
}

inline Ind JB_Str_OutByteWithByteIntInt(JB_String* Self, uint /*byte*/ Find, int Start, int After) {
	return JB_Str_OutByte(Self, Start, After, Find);
}

inline JB_String* JB_Str_Unescape(JB_String* Self) {
	return JB_Str_MultiReplaceAll(Self, JB__Constants_UnEscapeStr, JB_StdErr);
}

inline int JB_TC_ByteCount(uint /*DataTypeCode*/ Self) {
	return JB_TC_VecCount(Self) << JB_TC_ByteShift(Self);
}

inline bool JB_TC_IsInt(uint /*DataTypeCode*/ Self) {
	return (!JB_TC_IsFloat(Self));
}

inline int JB_TC_ItemBitCount(uint /*DataTypeCode*/ Self) {
	return 8 << JB_TC_ByteShift(Self);
}

inline Codepoint JB_TerminalDisplay_SyntaxAccess(TerminalDisplay* Self) {
	return JB_App__GetChar();
}

inline bool JB_Tree_OperatorIn(JB_List* Self, JB_List* F) {
	return JB_Ring_Parent(Self) == F;
}

inline bool JB_Tree_SyntaxEquals(JB_List* Self, int N) {
	return JB_Ring_HasChildCount(Self, N);
}

inline bool JB_byte_IsWhite(uint /*byte*/ Self) {
	return JB_CP_IsWhite(((Codepoint)Self));
}

inline JB_String* JB_cstring_Wrap(_cstring Self) {
	return JB_StrC(Self);
}

inline int JB_int64_Log2(int64 Self) {
	return JB_u64_Log2(((uint64)Self));
}

inline int JB_int_SyntaxCompare(int Self, JB_String* S) {
	return Self - JB_Str_Length(S);
}

inline int JB_uint_Log2(uint Self) {
	return JB_Int_Log2(((int)Self));
}

inline ASM* SC_FAT_xC2xB5RenderInto(FatASM* Self, ASM* Where, ASM* After) {
	return (SC__ASM_Encoders[SC_FAT_Op(Self)])(Self, Where, After);
}

inline ASMReg SC_Pac_GetASM(Assembler* Self, Message* Exp, ASMReg Dest) {
	//cpp_part;
	fn_asm Fn = SC_fn_asm_table[SC_Msg_ASMType(Exp)];
	ASMReg Ss = (Fn)(Self, Exp, Dest);
	return Ss;
}

inline bool SC_Reg_FourBytes(ASMReg Self) {
	return JB_TC_ByteShift(((DataTypeCode)Self)) == 2;
}

inline bool SC_Reg_IsBig(ASMReg Self) {
	return JB_TC_ByteShift(((DataTypeCode)Self)) == 3;
}

inline bool SC_Reg_IsBool(ASMReg Self) {
	return JB_TC_SyntaxIs(SC_Reg_xC2xB5Type(Self), kJB__TC_bool);
}

inline bool SC_Reg_IsFloat(ASMReg Self) {
	return JB_TC_IsFloat(((DataTypeCode)Self));
}

inline bool SC_Reg_IsSmall(ASMReg Self) {
	return (JB_TC_ByteShift(((DataTypeCode)Self)) < 3);
}

inline NilState SC_nil_SetNilness(ArchonPurger* Self, SCDecl* D, uint /*NilState*/ New) {
	NilRecorder* P = ((NilRecorder*)(Self->Neel));
	(SC_NRC_SyntaxCallSet((P), D->NilReg, New));
	return New;
}

inline bool JB_Safe_SyntaxCast(JB_String* Self) {
	return JB_Str_IsOK(Self);
}

inline bool JB_Str_ContainsByte(JB_String* Self, uint /*byte*/ B) {
	//cpp_part;
	return JB_Ind_SyntaxCast(JB_Str_FindByte(Self, B, 0, kJB__int_Max));
}

inline Ind JB_Str_InWhite(JB_String* Self, int Start, int After) {
	return JB_Str_FindCharset(Self, kJB__CharSet_White, Start, After);
}

inline bool JB_Str_IsInt(JB_String* Self) {
	return JB_Str_IsIntFrom(Self, 0);
}

inline Ind JB_Str_OutCharSet(JB_String* Self, CharSet Find, int From, int After) {
	return JB_Str_FindCharset(Self, (~Find), From, After);
}

inline Ind JB_Str_OutWhite(JB_String* Self, int Start, int After) {
	return JB_Str_FindCharset(Self, (~kJB__CharSet_White), Start, After);
}

inline int JB_TC_Floatness(uint /*DataTypeCode*/ Self) {
	return JB_TC_IsFloat(Self) * JB_TC_ByteCount(Self);
}

inline bool JB_byte_IsLower(uint /*byte*/ Self) {
	return JB_CP_IsLower(((Codepoint)Self));
}

inline bool JB_byte_IsUpper(uint /*byte*/ Self) {
	return JB_CP_IsUpper(((Codepoint)Self));
}

inline ASMReg SC_Reg_BoolCondAnswer(ASMReg Self) {
	if (SC_Reg_SyntaxIs(Self, kSC__Reg_CondRequest)) {
		Self = SC_Reg_SyntaxIsSet(Self, kSC__Reg_CondRequest, (!true));
		Self = SC_Reg_SyntaxIsSet(Self, kSC__Reg_CondAnswer, true);
	}
	return Self;
}

inline ASMReg SC_Reg_BoolNegateAnswer(ASMReg Self) {
	Self = SC_Reg_xC2xB5TypeSetWithTc(Self, kJB__TC_bool);
	Self = SC_Reg_SyntaxIsSet(Self, kSC__Reg_AlreadyNegated, true);
	Self = SC_Reg_SyntaxIsSet(Self, kSC__Reg_Negate, (!true));
	return Self;
}

inline bool SC_Reg_IsInt(ASMReg Self) {
	return JB_TC_IsInt(((DataTypeCode)Self));
}

inline bool JB_CharSet_ContainsStr(CharSet Self, JB_String* S) {
	//cpp_part;
	return JB_Str_OutCharSet(S, Self, 0, kJB__int_Max) < 0;
}

inline void JB_FS_AppendTermCol(FastString* Self, TerminalColor Col) {
	//cpp_part;
	JB_FreeIfDead(JB_TerminalColor_Render(Col, Self));
}

inline JB_File* JB_File__Logs() {
	return JB_Str_AsFile(JB_LUB[529]);
}

inline void JB_Msg_AppendSyx(Message* Self, Syntax Fn, JB_String* Name) {
	//cpp_part;
	JB_FreeIfDead(JB_Msg_Msg(Self, Fn, Name));
}

inline Message* JB_Syx_OperatorPlus(Syntax Self, JB_String* M) {
	return JB_Syx_Msg(Self, M);
}

inline bool JB_byte_IsLetter(uint /*byte*/ Self) {
	return JB_CP_IsLetter(((Codepoint)Self));
}

inline JB_String* JB_config_AsString(Message* Self) {
	//cpp_part;
	if (Self) {
		return JB_Msg_Value(Self);
	}
	return JB_LUB[0];
}

inline Message* JB_Str_Msg(JB_String* Self) {
	return JB_Syx_OperatorPlus(kJB_SyxStr, Self);
}

inline Array* JB_Str_OperatorDivide(JB_String* Self, uint /*byte*/ Sep) {
	return JB_Str_Split(Self, Sep);
}

inline Array* JB_Str_Words(JB_String* Self) {
	return JB_Str_Split(Self, ' ');
}

inline Message* JB_int64_Msg(int64 Self) {
	return JB_Syx_OperatorPlus(kJB_SyxNum, JB_int64_Render(Self, nil));
}

inline Message* JB_int_Msg(int Self) {
	JB_String* _tmPf0 = JB_int_RenderFS(Self, nil);
	JB_Incr(_tmPf0);
	Message* _tmPf1 = JB_Syx_OperatorPlus(kJB_SyxNum, _tmPf0);
	JB_Incr(_tmPf1);
	JB_EarlyDecr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

inline bool JB_Str_OperatorEndsWith(JB_String* Self, JB_String* S) {
	return JB_Str_EndsWith(Self, S, true);
}

inline JB_String* JB_App__AppName() {
	JB_String* _tmPf0 = JB_App__AppPath();
	JB_Incr(_tmPf0);
	JB_String* _tmPf1 = JB_Str_Name(_tmPf0);
	JB_Incr(_tmPf1);
	JB_EarlyDecr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

inline void JB_Msg_Fail(Message* Self, JB_String* Error) {
	//cpp_part;
	JB_Rec__Latchkum(Self, Error, nil);
}

inline void JB_Msg_SyntaxProblem(Message* Self, JB_String* Error) {
	JB_Rec__NewProblem(Self, Error, nil);
}

inline void JB_Str_SyntaxProblem(JB_String* Self) {
	JB_Rec__NewProblem(nil, Self, nil);
}

inline JB_File* JB_File_SyntaxAccess(JB_File* Self, JB_String* Name) {
	return JB_File_Child(Self, Name);
}

inline Message* JB_Msg_Arg(Message* Self) {
	return JB_Msg_Last(Self, kJB_SyxArg);
}

inline bool JB_Msg_ContainsStr(Message* Self, JB_String* S) {
	//cpp_part;
	return ((bool)JB_Msg_FindNested(Self, kJB_SyxNil, S, false));
}

inline Message* JB_Msg_NeedFirst(Message* Self) {
	return JB_Msg_NeedSyx(Self, kJB_SyxNil);
}

inline bool JB_App__No(JB_String* Name) {
	return (!JB_App__Yes(Name));
}

inline void JB_MzSt_Print(CompressionStats* Self) {
	JB_String* _tmPf0 = JB_MzSt_Report(Self, nil);
	JB_Incr(_tmPf0);
	JB_PrintLine(_tmPf0);
	JB_Decr(_tmPf0);
}

inline void SC_Pac_SoftNopRange(Assembler* Self, FatASM* Start, FatASM* After) {
	SC_Pac_NopRange(Self, Start, After, true);
}

inline bool JB_Str_CompressTestSub_(JB_String* Self, int Strength, bool Report) {
	bool Rz = false;
	CompressionStats Stats = ((CompressionStats){});
	JB_String* C = JB_Str_Compress(Self, Strength, (&Stats), nil);
	JB_Incr(C);
	if (Report) {
		JB_MzSt_Print((&Stats));
	}
	JB_String* Decomp = JB_Str_Decompress(C, nil, kJB__int_Max, nil);
	JB_Incr(Decomp);
	Rz = (JB_Str_Equals(Self, Decomp, false));
	if (!Rz) {
		if (true) {
			JB_String* _tmPf0 = JB_Str_OperatorPlus(JB_LUB[1840], Self);
			JB_Incr(_tmPf0);
			JB_Str_Fail(_tmPf0);
			JB_Decr(_tmPf0);
		}
		JB_SetRef(Decomp, JB_Str_Decompress(C, nil, kJB__int_Max, nil));
	}
	JB_Decr(C);
	JB_EarlyDecr(Decomp);
	return Rz;
}

inline bool JB_Str_CompressTest_(JB_String* Self, bool Report, int Which) {
	if (Which & 1) {
		if (!JB_Str_CompressTestSub_(Self, kJB__MZLab_Strong, Report)) {
			return nil;
		}
	}
	if (Which & 2) {
		if (!JB_Str_CompressTestSub_(Self, kJB__MZLab_Strongest, Report)) {
			return nil;
		}
	}
	return true;
}

inline ASMReg SC_Pac_ImproveAssign(Assembler* Self, ASMReg Dest, ASMReg Src) {
	FatASM* F = SC_Reg_FAT(Src);
	if (!F) {
		return nil;
	}
	if (!SC_Reg_SyntaxIs(Src, kSC__Reg_Temp)) {
		if (!(SC_Pac_IsCurr(Self, F) and (SC_Reg_SyntaxIs(Dest, kSC__Reg_ExitAtAll)))) {
			return nil;
		}
		uint Vdecls = ((uint)SC_Pac_State(Self)->ParentVars);
		int Find = 1 << SC_Reg_Reg(Src);
		if (!(Vdecls & Find)) {
			return nil;
		}
	}
	return SC_Pac_ReDestWithFatReg(Self, F, Dest);
}

inline ASMReg SC_Pac_Exists(Assembler* Self, ASMReg Dest, ASMReg L, Message* Exp) {
	return SC_Pac_Equals(Self, Exp, SC_Reg_Negate(Dest, true), L, SC_Reg__New());
}

inline Message* JB_Macro_Run(Message* Self, Array* Prms) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Msg_ConstructorEmpty(nil));
	JB_Msg_BecomeMacro(Rz, Self, Prms);
	JB_SafeDecr(Rz);
	return Rz;
}

inline FatASM* SC_Pac_Read(Assembler* Self, ASMReg Dest, Message* Exp, ASMReg Ptr, ASMReg VarAdd, SCDecl* ReadDecl, int Index) {
	Dest = SC_Reg_SyntaxIsSet(Dest, kSC__Reg_Set, (!true));
	if (0) {
		SC_Pac_Dummy(Self, Exp);
	}
	return SC_Pac_ReadOrWriteSub(Self, Dest, Exp, Ptr, VarAdd, ReadDecl, Index);
}

inline FatASM* SC_Pac_Write(Assembler* Self, ASMReg Value, Message* Exp, ASMReg Ptr, ASMReg VarAdd, SCDecl* DestDecl, int Index) {
	Value = SC_Reg_SyntaxIsSet(Value, kSC__Reg_Set, true);
	return SC_Pac_ReadOrWriteSub(Self, Value, Exp, Ptr, VarAdd, DestDecl, Index);
}



}
#endif // __JB_H__


#ifdef __NEED_LIB_GLOBS__
struct JB_Globals {
	byte __Dummy__;
	bool Tk__DotInsertAllow;
	bool TerminalColor_Enabled;
	bool Flow_AlwaysMove;
	bool Flow_BreakOnFail;
	byte Flow_Active;
	bool Proc_CheckedParent;
	byte Err_AutoPrint;
	bool Err_KeepStackTrace;
	u16 Tk__StopBars;
	u16 API_NilHappened_;
	int Syx_CurrFuncID_;
	Float64 Rec_Progress;
	JB_Object* Constants_JS_UnEscapeStr;
	JB_Object* Constants_XML_UnEscapeStr;
	JB_Object* Constants_EscapeChr;
	JB_Object* Tk__EndOfLineMarker;
	JB_Object* Constants_EscapeStr;
	JB_Object* TC_Types_Dict;
	JB_Object* Platform_Logger_;
	JB_Object* StdErr;
	JB_Object* Constants_JS_EscapeStr;
	JB_Object* App_Usage;
	JB_Object* Constants_UnEscapeStr;
	JB_Object* Flow_Flow;
	JB_Object* App__Conf;
	JB_Object* App__Prefs;
	JB_Object* App__StdOut;
	JB_Object* File__Speedie;
	JB_Object* bin_Header;
	JB_Object* App__stdin;
	JB_Object* Proc__Parent;
	JB_Object* Err_BackupErrorSource;
	JB_Object* Constants_XML_EscapeStr;
	JB_Object* Constants__SyxDict;
	JB_Object* Macro_TmpPrms_;
	JB_Object* App__Args;
	JB_Object* App__Path;
	JB_Object* Tk__ErrorNames;
	JB_Object* ErrorSeverity__ErrorNames;
};
extern JB_Globals JB__;


#endif // __NEED_LIB_GLOBS__ 