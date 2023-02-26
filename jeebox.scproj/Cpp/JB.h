

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

typedef int SizeInt;

typedef byte Syntax;

typedef int TerminalColor;

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

typedef u16 MsgUIFlags;

typedef uint U24_8;

struct CompressionStats;

struct FloatRange;

struct IntDownRange;

struct IPCMessage;

struct MessagePosition;

struct ObjectLoader;

struct ObjectSaver;

struct ParserLineAndIndent;

struct Random;

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

struct DTWrap;

struct JB_ErrorReceiver;

struct FixedDict;

struct LeakTester;

struct Macro;

struct MWrap;

struct Process;

struct Selector;

struct JB_Object;

struct StringFields;

struct StringStream;

struct SyntaxObj;

struct FastString;

struct SaverClassInfo;

struct JB_String;

struct JB_String;

struct Message;

struct Message;

struct Message;

struct JB_Error;

struct Message;

typedef void (*fnErrorLogger)(JB_ErrorReceiver* self, JB_String* Data);

typedef void (*fpDestructor)(JB_Object* self);

typedef void (*fpMsgRender)(Message* self, FastString* fs);

typedef Message* (*ParseHandler)(int Start, Message* Parent);

typedef JB_Object* (*TokenHandler_fp)(int Start, Message* parent);

typedef void (*__Saveable_LoadProperties__)(Saveable* self, ObjectLoader* Loader);

typedef void (*__Saveable_SaveCollect__)(Saveable* self, ObjectSaver* Saver);

typedef void (*__Saveable_SaveWrite__)(Saveable* self, ObjectSaver* Saver);

typedef JB_String* (*__Object_Render__)(JB_Object* self, FastString* fs_in);

typedef JB_String* (*__Message_copyid__)(Message* self);

typedef JB_String* (*__Message_text__)(Message* self, int i);

typedef bool (*__Message_textset__)(Message* self, int i, JB_String* v);

//// HEADER Proj.h

struct CompressionStats {
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

struct Saveable_Behaviour: Object_Behaviour {
	__Saveable_LoadProperties__ loadproperties;
	__Saveable_SaveCollect__ savecollect;
	__Saveable_SaveWrite__ savewrite;
};

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

struct Array_Behaviour: Saveable_Behaviour {
};

struct Dictionary_Behaviour: Saveable_Behaviour {
};

struct RingTree_Behaviour: Saveable_Behaviour {
};

struct SaverClassInfo_Behaviour: Array_Behaviour {
};

JBClass ( SaverClassInfo , Array , 
	JB_Class* Cls;
	SaverClassInfo* NextInfo;
	char* Data;
);

struct StringZeroTerminated_Behaviour: String_Behaviour {
};

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
	int Extra;
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
extern Message* JB__App__Conf;
extern JB_String* JB__App__Path;
extern JB_String* JB__App_codesign_native;
extern Array* JB__App_OldArgs;

extern bool JB__App_Unregistered;
extern JB_String* JB__App_Usage;
#define kJB__ErrorColors_bold (JB_LUB[345])
extern bool JB__ErrorColors_Enabled;
#define kJB__ErrorColors_error (JB_LUB[346])
#define kJB__ErrorColors_good (JB_LUB[347])
#define kJB__ErrorColors_normal (JB_LUB[348])
#define kJB__ErrorColors_underline (JB_LUB[347])
#define kJB__ErrorColors_warn (JB_LUB[349])
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
#define kJB__Math_E (2.7182818284590452353602874713526f)
extern int JB__Tk_BaseExtra;
extern JB_String* JB__Tk_Data;
extern bool JB__Tk_DotInsertAllow;
extern Message* JB__Tk_EndOfLineMarker;
extern Dictionary* JB__Tk_ErrorNames;
extern JB_String* JB__Tk_ErrorTabsAfterSpaces;
extern int JB__Tk_InsertedFlags;
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
extern int JB__Tk_UsingExtra;
extern int JB__Tk_UsingPos;
#define kJB__Pipe_StdErr_ (2)
#define kJB__Pipe_StdIn_ (0)
#define kJB__Pipe_StdOut_ (1)

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
#define kJB__Terminal_TermClear (JB_LUB[350])
#define kJB__Terminal_TermReset (JB_LUB[351])
#define kJB__Terminal_w (80)
#define kJB__Terminal_white (37)
#define kJB__Terminal_yellow (33)
extern JB_String* JB__zalgo_down;
extern JB_String* JB__zalgo_mid;
extern Random JB__zalgo_R;
extern JB_String* JB__zalgo_up;
extern SyntaxObj* JB__FuncArray_[64];
extern JB_String* JB__JbinHeader;
extern Dictionary* JB__SyxDict_;
#define kJB_SaverEnd (JB_LUB[0])
#define kJB_SaverStart1 (JB_LUB[352])
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
#define kJB__int64_max (9223372036854775)
#define kJB__int64_min (9223372036854775 + 1)
extern int JB__Syx_CurrFuncID;
extern int JB__Syx_MaxFuncID;
#define kJB__uint_max (4294967295)
#define kJB__uint_min (0)
#define kJB__uint16_max (65535)
#define kJB__uint16_min (0)
#define kJB__uint64_max (-1)
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
extern Dictionary* JB__LD_ClassList;
#define kJB__Saver_RefMark (1073741824)
extern SaverClassInfo* JB__Saver_SaveableList;
extern Random JB__Rnd_Shared;
#define kJB__Wrap_Delete (2)
#define kJB__Wrap_Free (1)
#define kJB__Wrap_Nothing (0)
extern FastString* JB__FS_StdOutFS;
#define kJB__dict_TypeDict (3)
#define kJB__dict_TypeObj (1)
#define kJB__dict_TypeStem (2)
#define kJB__dict_TypeValue (0)
extern uint64 JB__Mrap_MDummy[2];

extern byte JB__Proc_ClosePipesInstalled;
extern int JB__Proc_IncID;

#define kJB__Proc_PrintWaiting (2)
extern byte JB__Proc_SpecialState;
extern bool JB__File_DebugExecute;
#define kJB__File_IgnoreErrors (true)
#define kJB__File_O_APPEND (8)
#define kJB__File_O_CREAT (512)
#define kJB__File_O_EXCL (2048)
#define kJB__File_O_RDONLY (0)
#define kJB__File_O_RDWR (2)
#define kJB__File_O_TRUNC (1024)
#define kJB__File_O_WRONLY (1)
extern byte JB__Err_AutoPrint;
extern bool JB__Err_KeepTraceStack;

//// HEADER JB.h



// __classes__


// __modules__


// App
int JB_App__Init_();

int JB_App__InitCode_();

int JB_Main();

int64 JB_App__ObjMemory();

JB_String* JB_App__StackTrace(FastString* fs_in);



// ErrorColors
int JB_ErrorColors__Init_();

int JB_ErrorColors__InitCode_();



// API
Message* JB_API__errors();

int JB_API__Init(int flags);

int JB_API__Init_();

int JB_API__InitCode_();

void JB_API__NilCallBack(JB_String* ErrorMessage);

bool JB_API__NilHandler();

Message* JB_API__Parse(JB_String* s, JB_String* path);



// Constants
void JB_Constants__AddEscape(int i, FastString* fs);

int JB_Constants__Init_();

int JB_Constants__InitCode_();

void JB_Constants__InitConstants();

JB_String* JB_Constants__TestJB();



// Math


// MZLab


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


// Platform
int JB_Platform__Init_();

int JB_Platform__InitCode_();



// ProT


// Terminal
JB_String* JB_Terminal__Flat();

int JB_Terminal__Init_();

int JB_Terminal__InitCode_();



// zalgo
int JB_zalgo__Init_();

int JB_zalgo__InitCode_();



// main
bool JB_CompareError(Message* expected, Message* found);

JB_String* JB_EntityTest();

int JB_Init_();

int JB_InitCode_();

void JB_PrintLine(JB_String* data);

void JB_Obj_PrintLine(JB_Object* o);

bool JB_TestCasting();



// _void


// _voidptr


// atomic_byte


// atomic_int


// atomic_uint


// bool


// byte
bool JB_byte_CanPrintAsNormalChar(byte self);

bool JB_byte_In(byte self, uint a, uint b);

bool JB_byte_IsInt(byte self);

bool JB_byte_IsLetter(byte self);

bool JB_byte_IsUpper(byte self);

bool JB_byte_IsWhite(byte self);

byte JB_byte_LowerCase(byte self);

JB_String* JB_byte_Render(byte self, FastString* fs_in);



// char


// cstring


// ErrorFlags


// ErrorSeverity
JB_String* JB_ErrorSeverity_Render(ErrorSeverity self, FastString* fs_in);

int JB_ErrorSeverity__Init_();

int JB_ErrorSeverity__InitCode_();



// f64


// float
float JB_f_powow(float self, int n);



// hfloat


// int
int JB_int_OperatorAlign(int self, int To);

inline bool JB_int_OperatorInRange(int self, int d);

bool JB_int_OperatorIsa(int self, uint n);

int JB_int_OperatorMax(int self, int other);

int JB_int_OperatorMin(int self, int other);

IntRange JB_int_OperatorTo(int self, int other);

int JB_int__max();



// int16


// int64
double JB_int64_AsFloat(int64 self);

JB_String* JB_int64_Render(int64 self, FastString* fs_in);



// int8


// ivec2


// ivec3


// ivec4


// MaybeBool


// ObjCID


// PID_Int


// SizeInt


// Syntax
bool JB_Syx_ListViewable(Syntax self);

JB_String* JB_Syx_LongName(Syntax self);

Message* JB_Syx_Msg(Syntax self, JB_String* name);

Message* JB_Syx_ParentMsg(Syntax self, Message* parent, JB_String* name);

JB_String* JB_Syx_Name(Syntax self);

inline bool JB_Syx_NilCheck(Syntax self);

SyntaxObj* JB_Syx_Obj(Syntax self);

fpMsgRender JB_Syx_RenderAddr(Syntax self);

bool JB_Syx_Translateable(Syntax self);

Syntax JB_Syx__Func(JB_String* name, Message* where);

int JB_Syx__Init_();

int JB_Syx__InitCode_();

Syntax JB_Syx__StdNew(fpMsgRender msg, JB_String* name, JB_String* LongName);



// TerminalColor


// uint


// uint16


// uint64
inline int JB_uint64_lelength(uint64 self);



// vec2


// vec3


// vec4


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
bool JB_TC_IsFloat(DataTypeCode self);



// Date
Date JB_Date__New0();



// ErrorInt


// FileMode


// Ind
inline bool JB_Ind_SyntaxCast(Ind self);



// IntRange
int JB_Rg_Width(IntRange self);



// IPCState


// MsgUIFlags


// U24_8


// fn_app_DeathAction


// fn_pth_wrap


// fn_subprocess


// fnErrorLogger


// fpDestructor


// fpMsgRender


// ParseHandler


// SaverLoadClass


// ShellOption


// SorterComparer


// TokenHandler_fp


// __LoadProperties__


// __SaveCollect__


// __SaveWrite__


// __Render__


// __copyid__


// __text__


// __textset__


// JB_ClassData
void JB_ClassData_Restore(JB_Class* self);



// JB_CompressionStats
void JB_MzSt_len(CompressionStats* self, int n);

void JB_MzSt_liveupdate(CompressionStats* self, JB_String* s, int outt);

CompressionStats* JB_MzSt__all();



// JB_FloatRange


// JB_IntDownRange


// JB_IPCMessage


// JB_MemoryWorld


// JB_MessagePosition


// JB_ObjectLoader
void JB_LD_destructor(ObjectLoader* self);

bool JB_LD_HasItem(ObjectLoader* self);

int64 JB_LD_Int(ObjectLoader* self);

int64 JB_LD_ItemInt(ObjectLoader* self);

bool JB_LD_ItemIsInt(ObjectLoader* self);

JB_String* JB_LD_ItemName(ObjectLoader* self);

JB_Object* JB_LD_ItemObject(ObjectLoader* self);

Message* JB_LD_Next(ObjectLoader* self);

JB_Object* JB_LD_Object(ObjectLoader* self);

JB_Object* JB_LD_ObjectSub(ObjectLoader* self, Message* c);

JB_String* JB_LD_String(ObjectLoader* self);



// JB_ObjectSaver
void JB_Saver_AppendInt(ObjectSaver* self, int64 i);

void JB_Saver_AppendObject(ObjectSaver* self, JB_Object* o);

void JB_Saver_AppendString(ObjectSaver* self, JB_String* s);

void JB_Saver_Destructor(ObjectSaver* self);

int JB_Saver__Init_();

int JB_Saver__InitCode_();



// JB_ParserLineAndIndent


// JB_Random
void JB_Rnd_LoadProperties(Random* self, ObjectLoader* Loader);

void JB_Rnd_Reseed(Random* self);

void JB_Rnd_SaveWrite(Random* self, ObjectSaver* Saver);

void JB_Rnd_SeedSet(Random* self, uint64 Value);

int JB_Rnd__Init_();

int JB_Rnd__InitCode_();



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


// JB_Object
inline JB_String* JB_Object___Render__(JB_Object* self, FastString* fs_in);

Array* JB_Object_CollectLeaks_(JB_Object* self);

void jdb(JB_Object* self);

bool JB_Object_Isa(JB_Object* self, JB_Class* x);

void jbl(JB_Object* self);

void JB_Object_SaveTryCollect(JB_Object* self, ObjectSaver* Saver);

void JB_Object_Fail(JB_Object* self, JB_String* Error);

void JB_Object_SyntaxExpect(JB_Object* self);



// JB_ByteMap


// JB_Charset
Array* JB_CS_Bytes(CharSet* self);

bool JB_CS_OperatorContains(CharSet* self, JB_String* Data);

CharSet* JB_CS__Alloc();

CharSet* JB_CS__New(JB_String* Chars, bool UseRange);



// JB_DataTypeWrapper
void JB_Wrap_ConstructorInt(DTWrap* self, int64 v);

void JB_Wrap_Destructor(DTWrap* self);

double JB_Wrap_FloatValue(DTWrap* self);

JB_String* JB_Wrap_Render(DTWrap* self, FastString* fs_in);

int64 JB_Wrap_Value(DTWrap* self);

DTWrap* JB_Wrap__Alloc();

DTWrap* JB_Wrap__NewInt(int64 v);



// JB_DictionaryReader
inline bool JB_DictionaryReader_SyntaxCast(DictionaryReader* self);



// JB_ErrorList
bool JB_Rec_CanAddMore(JB_ErrorReceiver* self, ErrorSeverity level);

void JB_Rec_Clear(JB_ErrorReceiver* self);

void JB_Rec_Constructor(JB_ErrorReceiver* self);

void JB_Rec_destructor(JB_ErrorReceiver* self);

JB_Error* JB_Rec_FirstError(JB_ErrorReceiver* self);

void JB_Rec_incr(JB_ErrorReceiver* self, JB_Error* err, bool add);

void JB_Rec_NewErrorWithNode(JB_ErrorReceiver* self, Message* node, JB_String* Desc, JB_String* path);

void JB_Rec_NewItem(JB_ErrorReceiver* self, JB_Error* Err);

bool JB_Rec_OK(JB_ErrorReceiver* self);

JB_Error* JB_Rec_Pop(JB_ErrorReceiver* self);

int JB_Rec_PrintErrorsMain(JB_ErrorReceiver* self, ErrorSeverity Level, bool PrintCount, bool shell);

JB_String* JB_Rec_Render(JB_ErrorReceiver* self, FastString* fs_in);

int JB_Rec_RenderErrors(JB_ErrorReceiver* self, FastString* fs, ErrorSeverity Level, bool shell);

int JB_Rec_ShellPrintErrors(JB_ErrorReceiver* self);

void JB_Rec_SyntaxAppend(JB_ErrorReceiver* self, JB_Error* Err);

JB_ErrorReceiver* JB_Rec__Alloc();

JB_ErrorReceiver* JB_Rec__New();



// JB_FastString
void JB_FS_AppendEscape(FastString* self, JB_String* s);

void JB_FS_AppendHexStr(FastString* self, JB_String* Data);

void JB_FS_AppendObjectID(FastString* self, Saveable* o);

void JB_FS_AppendObjectOrNil(FastString* self, JB_Object* o);

void JB_FS_AppendInfo(FastString* self, JB_String* name, JB_String* data);

void JB_FS_AppendInfoNum(FastString* self, JB_String* name, int64 data);

void JB_FS_fieldstart(FastString* self, JB_String* name);

void JB_FS_lint(FastString* self, uint64 n);

void JB_FS_MsgErrorName(FastString* self, JB_String* name);

void JB_FS_ProblemsFound(FastString* self, int count);

JB_String* JB_FS_Render(FastString* self, FastString* fs_in);

void JB_FS_AppendFastString(FastString* self, FastString* fs);

void JB_FS_AppendInt64(FastString* self, int64 data);

void JB_FS_AppendInt32(FastString* self, int data);

void JB_FS_SyntaxAppend(FastString* self, Message* msg);

inline JB_String* JB_FS_SyntaxCast(FastString* self);

FastString* JB_FS__Alloc();

int JB_FS__Init_();

int JB_FS__InitCode_();

FastString* JB_FS__New();



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
int JB_Proc__Init_();

int JB_Proc__InitCode_();



// JB_Saveable
inline void JB_Sav___SaveCollect__(Saveable* self, ObjectSaver* Saver);

bool JB_Sav_IsSaveMarked(Saveable* self);

void JB_Sav_LoadProperties(Saveable* self, ObjectLoader* Loader);

void JB_Sav_SaveCollect(Saveable* self, ObjectSaver* Saver);

bool JB_Sav_SaveMark(Saveable* self);

SaverClassInfo* JB_Sav_SaverInfo(Saveable* self);

void JB_Sav_SaveWrite(Saveable* self, ObjectSaver* Saver);



// JB_Selector


// JB_ShellStream


// JB_String
Array* JB_Str_ByteSplit(JB_String* self);

CharSet* JB_Str_CharSetWithBool(JB_String* self, bool Range);

Array* JB_Str_Chunk(JB_String* self, int n);

JB_String* JB_Str_Compress(JB_String* self, CompressionStats* st);

void JB_Str_CompressIntoSub(JB_String* self, FastString* j, CompressionStats* st);

int JB_Str_Count(JB_String* self, byte b);

JB_String* JB_Str_Decompress(JB_String* self, CompressionStats* st, int lim);

bool JB_Str_DecompressSub(JB_String* self, CompressionStats* st, int lim, Message* j, FastString* fs);

bool JB_Str_EndsWith(JB_String* self, JB_String* s, bool aware);

JB_String* JB_Str_Escape(JB_String* self);

JB_String* JB_Str_EscapeChr(JB_String* self);

bool JB_Str_EscapeTest(JB_String* self);

Ind JB_Str_FindByte(JB_String* self, byte find, int Start, int After);

Ind JB_Str_Find(JB_String* self, CharSet* cs, int Start, int After);

Ind JB_Str_HiddenJBin(JB_String* self);

Ind JB_Str_InWhite(JB_String* self, int Start, int After);

bool JB_Str_IsCompressed(JB_String* self);

int JB_Str_IsHexLike(JB_String* self, int N);

bool JB_Str_IsJbin(JB_String* self);

bool JB_Str_IsStatementName(JB_String* self);

Ind JB_Str_JBFind(JB_String* self, byte find, int Off, int After);

byte JB_Str_Last(JB_String* self, int minus);

int JB_Str_LineCount(JB_String* self);

bool JB_Str_ContainsString(JB_String* self, JB_String* s);

bool JB_Str_OperatorEndsWith(JB_String* self, JB_String* s);

bool JB_Str_OperatorStarts(JB_String* self, JB_String* s);

Ind JB_Str_OutCharSet(JB_String* self, CharSet* cs, int Start, int After);

Ind JB_Str_OutWhite(JB_String* self, int Start, int After);

Message* JB_Str_Parse(JB_String* self, Syntax owner, bool AllowDecomp);

Message* JB_Str_parse_jbin(JB_String* self);

Message* JB_Str_ParseWithError(JB_String* self, JB_Error** rec);

StringStream* JB_Str_reader(JB_String* self, JB_String* T);

Array* JB_Str_Split(JB_String* self, byte sep);

JB_String* JB_Str_Squeeze(JB_String* self);

void JB_Str_SyntaxExpect(JB_String* self);

JB_String* JB_Str_Unescape(JB_String* self);

CharSet* JB_Str_UniCS(JB_String* self);

Array* JB_Str_Words(JB_String* self);

JB_String* JB_Str__FromC(_cstring Addr);

JB_String* JB_Str__SyntaxAccess(int b);



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


// JB_Array
void JB_Array_LoadProperties(Array* self, ObjectLoader* Loader);

void JB_Array_SaveCollect(Array* self, ObjectSaver* Saver);

void JB_Array_SaveWrite(Array* self, ObjectSaver* Saver);

void JB_Array_SyntaxAppend(Array* self, JB_Object* item);

inline bool JB_Array_SyntaxCast(Array* self);

Array* JB_Array__Alloc();

Array* JB_Array__New0();



// JB_Dictionary
void JB_Dict_LoadProperties(Dictionary* self, ObjectLoader* Loader);

void JB_Dict_SaveCollect(Dictionary* self, ObjectSaver* Saver);

void JB_Dict_SaveWrite(Dictionary* self, ObjectSaver* Saver);

JB_Object* JB_Dict_ValueStr(Dictionary* self, JB_String* Key);

void JB_Dict_SetInt(Dictionary* self, uint64 Key, JB_Object* Value);

JB_Object* JB_Dict_ValueInt(Dictionary* self, uint64 Key);

JB_Object* JB_Dict_ValueLower(Dictionary* self, JB_String* s);

Dictionary* JB_Dict__Alloc();

Dictionary* JB_Dict__Copy(Dictionary* Dict);

Dictionary* JB_Dict__New();

Dictionary* JB_Dict__Reverse(Dictionary* Dict);



// JB_File
int JB_File__Init_();

int JB_File__InitCode_();



// JB_JBin
void JB_bin_add(FastString* self, Syntax type, JB_String* data, bool into);

void JB_bin_addint(FastString* self, int64 data);

void JB_bin_AddMemory(FastString* self, Syntax type, bool GoIn, byte* data, uint64 L);

void JB_bin_CloseStream(FastString* self, int c);

void JB_bin_Constructor0(FastString* self);

void JB_bin_enter(FastString* self, Syntax type, JB_String* data);

void JB_bin_jinit(FastString* self);

int JB_bin_OpenStream(FastString* self);

void JB_bin_sheb(FastString* self, JB_String* data);

void JB_bin_up(FastString* self, int amount);

FastString* JB_bin__New0();



// JB_RingTree
void JB_Tree_Clear(RingTree* self);

RingTree* JB_Tree_First_(RingTree* self);

bool JB_Tree_HasOneChild(RingTree* self);

void jdb2(RingTree* self);

void jdb3(RingTree* self);

RingTree* JB_Tree_Pop(RingTree* self);

void JB_Tree_Remove(RingTree* self);

JB_String* JB_Tree_Render(RingTree* self, FastString* fs_in);

RingTree* JB_Tree_Second(RingTree* self);

void JB_Tree_SyntaxAppend(RingTree* self, RingTree* Last);

RingTree* JB_Tree_Upward(RingTree* self, int n);



// JB_SaverClassInfo
void JB_sci_destructor(SaverClassInfo* self);



// JB_String_ArgValue


// JB_StringThatWasReadSafely


// JB_StringZeroTerminated


// JB_Message
void JB_Msg_Acc__(Message* self, FastString* fs);

void JB_Msg_CantFind(Message* self, Syntax s, JB_String* name, Message* found);

void JB_Msg_Adj__(Message* self, FastString* fs);

int JB_Msg_After(Message* self);

void JB_Msg_AfterSet(Message* self, int Value);

void JB_Msg_ARel__(Message* self, FastString* fs);

void JB_Msg_Arg__(Message* self, FastString* fs);

void JB_Msg_Arr__(Message* self, FastString* fs);

void JB_Msg_Ask__(Message* self, FastString* fs);

void JB_Msg_Back__(Message* self, FastString* fs);

void JB_Msg_Badj__(Message* self, FastString* fs);

void JB_Msg_BecomeStr(Message* self, Syntax fn, JB_String* name);

void JB_Msg_Bin__(Message* self, FastString* fs);

void JB_Msg_binn__(Message* self, FastString* fs);

void JB_Msg_BinnRender(Message* self, FastString* fs, JB_String* sepa, JB_String* sepb);

void JB_Msg_Bra__(Message* self, FastString* fs);

void JB_Msg_BRel__(Message* self, FastString* fs);

void JB_Msg_Char__(Message* self, FastString* fs);

int JB_Msg_CleanIndent(Message* self);

void JB_Msg_Cnj__(Message* self, FastString* fs);

void JB_Msg_ConstructorBasic(Message* self);

void JB_Msg_ConstructorCopy(Message* self, Message* other);

void JB_Msg_ConstructorNormal(Message* self, Syntax Func, JB_String* Name);

void JB_Msg_ConstructorRange(Message* self, Message* Parent, Syntax Func, int BytePos, JB_String* name, int Extra);

Message* JB_Msg_NiceCopy(Message* self, Message* L);

Message* JB_Msg_Copy_(Message* self, Message* pos_msg, JB_MemoryLayer* L);

JB_String* JB_Msg_copyid(Message* self);

void JB_Msg_Decl__(Message* self, FastString* fs);

void JB_Msg_destructor(Message* self);

void JB_Msg_Dot__(Message* self, FastString* fs);

void JB_Msg_Dummy(Message* self, FastString* fs);

void JB_Msg_Emb__(Message* self, FastString* fs);

void JB_Msg_ERel__(Message* self, FastString* fs);

bool JB_Msg_Expect(Message* self, Syntax type, JB_String* name);

bool JB_Msg_ExpectLast(Message* self, JB_String* err);

void JB_Msg_File__(Message* self, FastString* fs);

JB_String* JB_Msg_FilePath(Message* self);

Message* JB_Msg_FindFlat(Message* self, Syntax s, JB_String* name, bool Err);

void JB_Msg_FSListArg(Message* self, FastString* fs);

void JB_Msg_FSListSep(Message* self, FastString* fs, JB_String* sep);

void JB_Msg_Func__(Message* self, FastString* fs);

JB_String* JB_Msg_FuncName(Message* self);

Message* JB_Msg_GoIntoInvisArg(Message* self, Message* tmp, int pos);

int JB_Msg_IndentScore(Message* self);

bool JB_Msg_InInvisArg(Message* self);

int64 JB_Msg_Int(Message* self, int i);

void JB_Msg_Item__(Message* self, FastString* fs);

bool JB_Msg_jbinTest(Message* self);

JB_String* JB_Msg_jdb2_(Message* self, int Flags, FastString* fs_in);

JB_String* JB_Msg_jdb_(Message* self, FastString* fs_in, int flags);

int JB_Msg_Length(Message* self);

void JB_Msg_List__(Message* self, FastString* fs);

bool JB_Msg_ListViewable(Message* self);

JB_String* JB_Msg_Locate(Message* self);

JB_String* JB_Msg_MiniName(Message* self);

Message* JB_Msg_Msg(Message* self, Syntax fn, JB_String* name);

void JB_Msg_Msg__(Message* self, FastString* fs);

void JB_Msg_Name__(Message* self, FastString* fs);

inline bool JB_Msg_NilCheck(Message* self);

void JB_Msg_Nil__(Message* self, FastString* fs);

void JB_Msg_Num__(Message* self, FastString* fs);

JB_String* JB_Msg_Nyme(Message* self);

void JB_Msg_Oat__(Message* self, FastString* fs);

bool JB_Msg_OperatorIn(Message* self, Syntax f);

void JB_Msg_Opp__(Message* self, FastString* fs);

JB_String* JB_Msg_OriginalParseData(Message* self);

JB_MemoryLayer* JB_Msg_OriginalParseLayer(Message* self);

Message* JB_Msg_ParseAST(Message* self);

void JB_Msg_pinn__(Message* self, FastString* fs);

Message* JB_Msg_PoorAnt(Message* self);

int JB_Msg_PrevIndentCheck(Message* self, Message* pr);

void JB_Msg_Prm__(Message* self, FastString* fs);

void JB_Msg_Ques__(Message* self, FastString* fs);

void JB_Msg_Quot__(Message* self, FastString* fs);

void JB_Msg_rangeSet(Message* self, IntRange r);

void JB_Msg_Rel__(Message* self, FastString* fs);

JB_String* JB_Msg_Render(Message* self, FastString* fs_in);

JB_String* JB_Msg_render_jbin(Message* self, JB_String* sheb, FastString* fs_in);

JB_String* JB_Msg_RenderAST(Message* self, int flags, FastString* fs_in);

void JB_Msg_RenderPrm(Message* self, FastString* fs, byte b1, byte b2);

void JB_Msg_RenderWithSpaces(Message* self, FastString* fs, Message* ch);

void JB_Msg_SCnj__(Message* self, FastString* fs);

void JB_Msg_SCom__(Message* self, FastString* fs);

void JB_Msg_SDot__(Message* self, FastString* fs);

void JB_Msg_Sheb__(Message* self, FastString* fs);

void JB_Msg_SStr__(Message* self, FastString* fs);

void JB_Msg_SThg__(Message* self, FastString* fs);

void JB_Msg_Str__(Message* self, FastString* fs);

bool JB_Msg_SyntaxEquals(Message* self, JB_String* name, bool Aware);

bool JB_Msg_EqualsSyx(Message* self, Syntax X, bool Aware);

void JB_Msg_SyntaxExpect(Message* self, JB_String* Error);

bool JB_Msg_SyntaxIs(Message* self, MsgUIFlags F);

void JB_Msg_SyntaxIsSet(Message* self, MsgUIFlags F, bool Value);

bool JB_Msg_SyntaxIsnt(Message* self, MsgUIFlags F);

void JB_Msg_Test(Message* self, JB_String* new_render, JB_String* name);

void JB_Msg_test_style(Message* self);

bool JB_Msg_TestSub(Message* self, JB_String* new_render, JB_String* name);

JB_String* JB_Msg_text(Message* self, int i);

bool JB_Msg_textset(Message* self, int i, JB_String* v);

void JB_Msg_Thg__(Message* self, FastString* fs);

void JB_Msg_Tmp__(Message* self, FastString* fs);

void JB_Msg_Todo__(Message* self, FastString* fs);

void JB_Msg_TRel__(Message* self, FastString* fs);

void JB_Msg_Tril__(Message* self, FastString* fs);

Message* JB_Msg_tviewch(Message* self);

void JB_Msg_Type__(Message* self, FastString* fs);

void JB_Msg_UnEmbed(Message* self);

void JB_Msg_Unit__(Message* self, FastString* fs);

void JB_Msg_url__(Message* self, FastString* fs);

void JB_Msg_XAtt__(Message* self, FastString* fs);

void JB_Msg_XCDT__(Message* self, FastString* fs);

void JB_Msg_XCom__(Message* self, FastString* fs);

void JB_Msg_XML__(Message* self, FastString* fs);

void JB_Msg_XPI__(Message* self, FastString* fs);

void JB_Msg_XTxt__(Message* self, FastString* fs);

void JB_Msg_Yoda__(Message* self, FastString* fs);

Message* JB_Msg__Alloc();

Message* JB_Msg__LayerAlloc(JB_MemoryLayer* _L);

Message* JB_Msg__NewBasic();

Message* JB_Msg__NewNormal(Syntax Func, JB_String* Name);

Message* JB_Msg__NewRange(Message* Parent, Syntax Func, int BytePos, JB_String* name, int Extra);

Message* JB_Msg__NewWithLayerCopy(JB_MemoryLayer* _L, Message* other);

bool JB_Msg__TreeCompare(Message* orig, Message* reparse, bool PrintIfSame);



// JB_MessageRoot


// JB_config


// JB_Error
void JB_Err_Constructor(JB_Error* self, Message* node, JB_String* desc, ErrorSeverity level, JB_String* path);

void JB_Err_destructor(JB_Error* self);

void JB_Err_Fill(JB_Error* self, JB_String* path, JB_String* desc);

void JB_Err_GrabLine(JB_Error* self, FastString* fs, bool Usecolor);

bool JB_Err_HasPosition(JB_Error* self);

bool JB_Err_IsError(JB_Error* self);

bool JB_Err_IsWarning(JB_Error* self);

bool JB_Err_LineIdentifiers(JB_Error* self, FastString* fs, JB_String* path);

int JB_Err_LinePos(JB_Error* self, JB_String* data);

bool JB_Err_NeedsPrint(JB_Error* self);

JB_String* JB_Err_render(JB_Error* self, FastString* fs_in);

JB_String* JB_Err_render_clang(JB_Error* self, FastString* fs_in);

bool JB_Err_SyntaxIs(JB_Error* self, ErrorFlags F);

void JB_Err_SyntaxIsSet(JB_Error* self, ErrorFlags F, bool Value);

bool JB_Err_SyntaxIsnt(JB_Error* self, ErrorFlags F);

JB_Error* JB_Err__Alloc();

void JB_Err__CantParseNum(Message* Where, JB_String* num, int Pos);

int JB_Err__Init_();

int JB_Err__InitCode_();

JB_Error* JB_Err__New(Message* node, JB_String* desc, ErrorSeverity level, JB_String* path);



// JB_FileArchive
JB_String* jb_msg_name(Message* self);

Syntax jb_msg_func(Message* self);

int jb_msg_position(Message* self);

_voidptr jb_msg_tag(Message* self);

void jb_msg_nameset(Message* self, JB_String* Result);

void jb_msg_funcset(Message* self, Syntax Result);

void jb_msg_positionset(Message* self, int Result);

void jb_msg_tagset(Message* self, _voidptr Result);

void jb_msg_firstset(Message* self, Message* Result);

void jb_msg_lastset(Message* self, Message* Result);

void jb_msg_prevset(Message* self, Message* Result);

void jb_msg_nextset(Message* self, Message* Result);

Message* jb_msg_first(Message* self);

Message* jb_msg_last(Message* self);

Message* jb_msg_prev(Message* self);

Message* jb_msg_next(Message* self);

Message* jb_msg_parent(Message* self);

Message* jb_msg_flatnext(Message* self);

Message* jb_msg_flatafter(Message* self);

Message* jb_msg_root(Message* self);

void jb_msg_remove(Message* self);

JB_String* jb_msg_render(Message* self, int mode);

JB_String* jb_msg_ast(Message* self);

Message* jb_msg_parseast(Message* self);

Message* jb_msg_copy(Message* self, Message* layer);

Message* jb_msg_create(Message* self, Syntax Type, JB_String* Name);

void jb_msg_error(Message* self, JB_String* ErrorMsg);

Message* jb_msg_expect(Message* self, Syntax Type, JB_String* name, Message* ErrPlace);

Message* jb_msg_access(Message* self, Syntax Type, JB_String* name, bool IsError);

JB_String* jb_syx_name(Syntax self);

JB_String* jb_syx_longname(Syntax self);

_cstring jb_string_address(JB_String* self);

int jb_string_length(JB_String* self);

JB_String* jb_string_compress(JB_String* self);

JB_String* jb_string_decompress(JB_String* self);

JB_String* jb_string_copy(JB_String* self);

Message* jb_string_parse(JB_String* self, JB_String* path);

JB_String* jb_string_escape(JB_String* self);

void jb_string_print(JB_String* self);

void jb_string_printline(JB_String* self);

int64 jb_string_int(JB_String* self, Message* m);

double jb_string_float(JB_String* self, Message* m);

Syntax jb_syntax(JB_String* name);

JB_String* jb_str(_cstring Str, int Length, _voidptr Release, _voidptr Tag);

JB_String* jb_cstr(_cstring Str);

void jb_delete_(JB_Object* obj);

Message* jb_errors();

bool jb_ok();

void jb_debug(JB_Object* o);

int jb_init(int Flags);

int jb_shutdown();

int jb_version();

JB_String* jb_readfile(_cstring path, bool AllowMissingFile);


//// HEADER Inlines.h
inline bool JB_int_OperatorInRange(int self, int d) {
	return (((uint)self) < ((uint)d));
}

inline bool JB_Syx_NilCheck(Syntax self) {
	return ((bool)self) or JB_API__NilHandler();
}

inline int JB_uint64_lelength(uint64 self) {
	return (JB_int_OperatorMax(JB_Int_Log2(((int)self)), 0)) >> 3;
}

inline bool JB_Ind_SyntaxCast(Ind self) {
	return self >= 0;
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

inline void JB_Sav___SaveCollect__(Saveable* self, ObjectSaver* Saver) {
	Saveable_Behaviour* Table = ((Saveable_Behaviour*)JB_ObjClassBehaviours(self));
	return (Table->savecollect)(self, Saver);
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

inline bool JB_Msg_NilCheck(Message* self) {
	return ((bool)self) or JB_API__NilHandler();
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
