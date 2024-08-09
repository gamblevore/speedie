

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

typedef byte CharProp;

typedef int Codepoint;

typedef byte ControlClipMode;

typedef ivec2 ControlLine;

typedef int ControlPoint;

typedef ivec4 ControlRect;

typedef u16 DataTypeCode;

typedef int64 Date;

typedef byte ErrorFlags;

typedef int ErrorInt;

typedef ivec2 ErrorInt2;

typedef int ErrorMarker;

typedef byte ErrorSeverity;

typedef int FileDes;

typedef int FileMode;

typedef bool FileResolveMode;

typedef int64 FileSizeInt;

typedef double Float64;

typedef vec4 FloatRangeConverter;

typedef vec2 FloatRangeConverterBasic;

typedef int FlowControlStopper;

typedef int Ind;

typedef ivec2 IntRange;

typedef byte MaybeBool;

typedef byte MoveCode;

typedef u16 MsgParseFlags;

typedef int PID_Int;

typedef ivec4 ParserLineAndIndent;

typedef byte ProcessMode;

typedef int SizeInt;

typedef byte Syntax;

typedef byte TaskState;

typedef int jbinLeaver;

typedef vec4 mat2;

typedef Date HumanDate;

struct CompressionStats;

struct FakeJBString;

struct FastBuff;

struct FloatRange;

struct IntDownRange;

struct Mat4;

struct MessagePosition;

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

struct ByteMap_Behaviour;

struct Charset_Behaviour;

struct DataObject_Behaviour;

struct DictionaryReader_Behaviour;

struct ErrorReceiver_Behaviour;

struct FastString_Behaviour;

struct FixedDict_Behaviour;

struct FlowControl_Behaviour;

struct LeakTester_Behaviour;

struct Macro_Behaviour;

struct MemoryLayer_Behaviour;

struct Memory_Behaviour;

struct ProcessOwner_Behaviour;

struct Saveable_Behaviour;

struct Selector_Behaviour;

struct StringFields_Behaviour;

struct StringReader_Behaviour;

struct String_Behaviour;

struct SyntaxObj_Behaviour;

struct TokenHandler_Behaviour;

struct Array_Behaviour;

struct Dictionary_Behaviour;

struct File_Behaviour;

struct Process_Behaviour;

struct StringShared_Behaviour;

struct StringZeroTerminated_Behaviour;

struct list_Behaviour;

struct MessageID_Behaviour;

struct Message_Behaviour;

struct RangeCoder_Behaviour;

struct SaverClassInfo_Behaviour;

struct SimpleGraph_Behaviour;

struct SpdProcess_Behaviour;

struct Task_Behaviour;

struct Error_Behaviour;

struct JB_Object;

struct DTWrap;

struct JB_ErrorReceiver;

struct FixedDict;

struct FlowControl;

struct LeakTester;

struct Macro;

struct MWrap;

struct Selector;

struct StringFields;

struct StringReader;

struct SyntaxObj;

struct FastString;

struct FastString;

struct JB_String;

struct JB_File;

struct JB_File;

struct Message;

struct MessageID;

struct Dictionary;

struct RangeCoder;

struct SaverClassInfo;

struct SimpleGraph;

struct SpdProcess;

struct JB_Task;

struct JB_Error;

struct Message;

struct Message;

struct Message;

typedef Message* (*FP_ParseHandler)(int Start, Message* Parent);

typedef JB_Object* (*TokenHandler_fp)(int Start, Message* Parent);

typedef JB_String* (*__Message_CopyID__)(Message* self);

typedef void (*__Saveable_LoadProperties__)(Saveable* self, ObjectLoader* Loader);

typedef JB_String* (*__Object_Render__)(JB_Object* self, FastString* Fs_in);

typedef void (*__Saveable_SaveCollect__)(Saveable* self, ObjectSaver* Saver);

typedef void (*__Saveable_SaveWrite__)(Saveable* self, ObjectSaver* Saver);

typedef bool (*__Message_TextSet__)(Message* self, int I, JB_String* V);

typedef JB_String* (*__Message_Text__)(Message* self, int I);

typedef void (*FP_fnErrorLogger)(JB_ErrorReceiver* self, JB_String* Data);

typedef JB_String* (*FP_fnIDGenerator)(int Start, int End, Syntax F);

typedef void (*FP_fpMsgRender)(Message* self, FastString* fs);

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

struct CompressionStats {
	bool Live;
};

struct FastBuff {
	byte* Curr;
	byte* Start;
	byte* End;
	JB_String* ReadFrom;
	bool Owns;
	bool WentBad;
};

struct MessagePosition {
	JB_MemoryLayer* Layer;
	int Position;
	int Length;
	MsgParseFlags Flags;
	u16 Tag;
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

struct Object_Behaviour {
	void* __destructor__;
	__Object_Render__ render;
};

struct Charset_Behaviour: Object_Behaviour {
};

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

struct TokenHandler_Behaviour: Object_Behaviour {
};

struct Array_Behaviour: Saveable_Behaviour {
};

struct Dictionary_Behaviour: Saveable_Behaviour {
};

struct File_Behaviour: String_Behaviour {
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

struct SaverClassInfo_Behaviour: Array_Behaviour {
};

JBClass ( SaverClassInfo , Array , 
	JB_Class* Cls;
	SaverClassInfo* NextInfo;
	char* Data;
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
extern Message* JB__App__Conf;
extern Array* JB__App__OldArgs;
extern JB_String* JB__App__Path;
extern JB_File* JB__App__stdin;
extern JB_File* JB__App__StdOut;
extern JB_String* JB__App_Usage;
#define kJB__ErrorColors_bold (JB_LUB[19])
extern bool JB__ErrorColors_Enabled;
#define kJB__ErrorColors_error (JB_LUB[16])
#define kJB__ErrorColors_good (JB_LUB[17])
#define kJB__ErrorColors_normal (JB_LUB[20])
#define kJB__ErrorColors_underline (JB_LUB[17])
#define kJB__ErrorColors_warn (JB_LUB[18])
extern u16 JB__API_NilHappened_;
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
#define kJB__MZLab_Default 3
#define kJB__MZLab_Fast 2
#define kJB__MZLab_Fastest 1
#define kJB__MZLab_None (0)
#define kJB__MZLab_Strong 3
#define kJB__MZLab_Strongest 4
#define kJB__Math_E (2.7182818284590452353602874713526f)
#define kJB__Math_iTau (0.15915494309f)
extern JB_File* JB__Platform_Logger_;
extern SyntaxObj* JB__FuncArray_[64];
extern JB_String* JB__JbinHeader;
extern JB_String* JB__jBinNotJbin;
extern Dictionary* JB__SyxDict_;
#define kJB_kSaverEnd (JB_LUB[0])
#define kJB_kSaverStart1 (JB_LUB[177])
extern JB_ErrorReceiver* JB_StdErr;
#define kJB_SyxAcc 29
#define kJB_SyxAdj 27
#define kJB_SyxARel 21
#define kJB_SyxArg 1
#define kJB_SyxArr 34
#define kJB_SyxAsk 43
#define kJB_SyxBack 16
#define kJB_SyxBadj 28
#define kJB_SyxBin 18
#define kJB_Syxbinn 42
#define kJB_SyxBra 31
#define kJB_SyxBRel 26
#define kJB_SyxChar 17
#define kJB_SyxCnj 8
#define kJB_SyxDecl 4
#define kJB_SyxDot 23
#define kJB_SyxEmb 2
#define kJB_SyxERel 38
#define kJB_SyxFile 35
#define kJB_SyxFunc 25
#define kJB_SyxItem 30
#define kJB_SyxList 32
#define kJB_Syxmax 55
#define kJB_SyxMsg 46
#define kJB_SyxName 22
#define kJB_SyxNil (0)
#define kJB_SyxNum 14
#define kJB_SyxOat 6
#define kJB_SyxOpp 9
#define kJB_Syxpinn 41
#define kJB_SyxPrm 33
#define kJB_SyxQues 7
#define kJB_SyxQuot 36
#define kJB_SyxRel 37
#define kJB_SyxSCnj 12
#define kJB_SyxSCom 45
#define kJB_SyxSDot 24
#define kJB_SyxSheb 11
#define kJB_SyxSStr 15
#define kJB_SyxSThg 13
#define kJB_SyxStr 19
#define kJB_SyxThg 10
#define kJB_SyxTmp 5
#define kJB_SyxTodo 47
#define kJB_SyxTRel 39
#define kJB_SyxTril 40
#define kJB_SyxType 3
#define kJB_SyxUnit 20
#define kJB_Syxurl 48
#define kJB_SyxXAtt 49
#define kJB_SyxXCDT 53
#define kJB_SyxXCom 52
#define kJB_SyxXML 50
#define kJB_SyxXPI 51
#define kJB_SyxXTxt 54
#define kJB_SyxYoda 44
extern bool JB__Tk__DotInsertAllow;
extern Message* JB__Tk__EndOfLineMarker;
extern Dictionary* JB__Tk__ErrorNames;
extern u16 JB__Tk__StopBars;
extern JB_String* JB__Tk_Data;
#define kJB__Tk_kAdjectiveOp 1
#define kJB__Tk_kAllow (false)
#define kJB__Tk_kColon 2
#define kJB__Tk_kColonArg 4
#define kJB__Tk_kComma 128
#define kJB__Tk_kEnd 448
#define kJB__Tk_kEndContainer 256
#define kJB__Tk_kEndOfLine 64
#define kJB__Tk_kExpect 1
#define kJB__Tk_kFuncAfterAny 3584
#define kJB__Tk_kFuncAfterBar 2048
#define kJB__Tk_kFuncAfterNormal 512
#define kJB__Tk_kFuncAfterNoSpace 1024
#define kJB__Tk_kIllegalChar 4194304
#define kJB__Tk_kLameTemporal 56
#define kJB__Tk_kOpp 258048
#define kJB__Tk_kOppBar 16384
#define kJB__Tk_kOppBra 4096
#define kJB__Tk_kOppChain 94208
#define kJB__Tk_kOppNoBar 241664
#define kJB__Tk_kOppSNB 8192
#define kJB__Tk_kOppSyx 24576
#define kJB__Tk_kOppTemporal 32768
#define kJB__Tk_kOppWord 65536
#define kJB__Tk_kOppYoda 131072
#define kJB__Tk_kTemporal 56
#define kJB__Tk_kTemporalBar 32
#define kJB__Tk_kTemporalSyx 48
#define kJB__Tk_kTemporalSyxNoBar 16
#define kJB__Tk_kTemporalWord 8
#define kJB__Tk_kTemporalWordColon 262144
#define kJB__Tk_kThing 3670016
#define kJB__Tk_kThingBar 1048576
#define kJB__Tk_kThingSyx 524288
#define kJB__Tk_kThingWord 2097152
#define kJB__Tk_kTmpOpp 32784
extern FP_fnIDGenerator JB__Tk_Splitter;
extern MessagePosition JB__Tk_Using;
#define kJB__zalgo_down (JB_LUB[102])
#define kJB__zalgo_mid (JB_LUB[414])
extern Random JB__zalgo_R;
#define kJB__zalgo_up (JB_LUB[401])
#define kJB__byte_max 255
#define kJB__byte_min (0)
#define kJB__char_max 127
#define kJB__char_min -128
#define kJB__int16_max 32767
#define kJB__int16_min -32768
#define kJB__int64_max 9223372036854775807
#define kJB__int64_min -9223372036854775808
#define kJB__uint_max 4294967295
#define kJB__uint_min (0)
#define kJB__uint16_max 65535
#define kJB__uint16_min (0)
#define kJB__uint64_max -1
#define kJB__CharProp_AlmostLetter 6
#define kJB__CharProp_Letters 7
#define kJB__CharProp_Lower 9
#define kJB__CharProp_Nothing (0)
#define kJB__CharProp_Number 5
#define kJB__CharProp_Punct 2
#define kJB__CharProp_Unicode 10
#define kJB__CharProp_Upper 8
#define kJB__CharProp_VarNames 4
#define kJB__CharProp_White 1
#define kJB__CharProp_XMLPunct 3
#define kJB__ControlClipMode_Debug 4
#define kJB__ControlClipMode_SlideBackInParent 1
#define kJB__ControlClipMode_SlideBackInWindow 2
#define kJB__CL1_After 6
#define kJB__CL1_Before 4
#define kJB__CL1_Centered 7
#define kJB__CL1_High 2
#define kJB__CL1_Length 10
#define kJB__CL1_Low (0)
#define kJB__CL1_Percent 8
#define kJB__TC__void (0)
#define kJB__TC__voidptr 48
#define kJB__TC_atomic_byte 12
#define kJB__TC_atomic_int 108
#define kJB__TC_atomic_int64 124
#define kJB__TC_atomic_uint 44
#define kJB__TC_atomic_uint64 60
#define kJB__TC_bool 256
#define kJB__TC_byte 8
#define kJB__TC_Byte2 9
#define kJB__TC_Byte3 10
#define kJB__TC_Byte4 11
#define kJB__TC_char 72
#define kJB__TC_cstring 48
#define kJB__TC_Double 248
#define kJB__TC_f16 216
#define kJB__TC_f64 248
#define kJB__TC_Failed 1024
#define kJB__TC_Float 232
#define kJB__TC_HFloat 216
#define kJB__TC_Int 104
#define kJB__TC_int16 88
#define kJB__TC_int64 120
#define kJB__TC_int8 72
#define kJB__TC_iVec2 105
#define kJB__TC_iVec3 106
#define kJB__TC_iVec4 107
#define kJB__TC_Numeric 8
#define kJB__TC_PossibleBits 2047
#define kJB__TC_s16 88
#define kJB__TC_s16x2 89
#define kJB__TC_s16x3 90
#define kJB__TC_s16x4 91
#define kJB__TC_s64 120
#define kJB__TC_SByte 72
#define kJB__TC_SByte2 73
#define kJB__TC_SByte3 74
#define kJB__TC_SByte4 75
#define kJB__TC_sign 64
extern Dictionary* JB__TC_Types_Dict;
#define kJB__TC_u16 24
#define kJB__TC_u32 40
#define kJB__TC_u64 56
#define kJB__TC_UInt 40
#define kJB__TC_uint16 24
#define kJB__TC_uint64 56
#define kJB__TC_uint8 8
#define kJB__TC_UnusedType 112
#define kJB__TC_Vec2 233
#define kJB__TC_Vec3 234
#define kJB__TC_Vec4 235
#define kJB__Date_Highest 9223372036854775807
#define kJB__Date_kOneStep (0.000015258789f)
#define kJB__Date_kSecondsPerDay 86400
#define kJB__Date_kSecondsPerMonthApprox 2628000
#define kJB__Date_kSecondsPerWeek 604800
#define kJB__ErrorFlags_DontStrip 1
#define kJB__ErrorFlags_Keep (0)
#define kJB__ErrorFlags_Parse 4
#define kJB__ErrorFlags_PreferNoRenderPath 2
#define kJB__ErrorFlags_PrintAndKeep 1
#define kJB__ErrorFlags_PrintAndRemove 2
extern Array* JB__ErrorSeverity__names;
#define kJB__ErrorSeverity_Critical 5
#define kJB__ErrorSeverity_Error 4
#define kJB__ErrorSeverity_Hint 1
#define kJB__ErrorSeverity_MaxError 6
#define kJB__ErrorSeverity_OK (0)
#define kJB__ErrorSeverity_Problem 3
#define kJB__ErrorSeverity_Warning 2
#define kJB__FileDes_StdErr 2
#define kJB__FileDes_StdIn (0)
#define kJB__FileDes_StdOut 1
#define kJB__FileMode_CanExec 281474976710656
#define kJB__FileMode_Data 6
#define kJB__FileMode_Group 56
#define kJB__FileMode_Other 7
#define kJB__FileMode_Owner 448
#define kJB__FileMode_Process 115968
#define kJB__FileResolveMode_AllowMissing 1
#define kJB__MoveCode_All 63
#define kJB__MoveCode_Back 32
#define kJB__MoveCode_Backward 32
#define kJB__MoveCode_Bottom 8
#define kJB__MoveCode_Center 63
#define kJB__MoveCode_Close 128
#define kJB__MoveCode_Down 8
#define kJB__MoveCode_Forward 16
#define kJB__MoveCode_Front 16
#define kJB__MoveCode_Horizontal 3
#define kJB__MoveCode_Left 2
#define kJB__MoveCode_MiddleLeft 14
#define kJB__MoveCode_MiddleRight 13
#define kJB__MoveCode_Negative 170
#define kJB__MoveCode_Open 64
#define kJB__MoveCode_Positive 85
#define kJB__MoveCode_Right 1
#define kJB__MoveCode_Top 4
#define kJB__MoveCode_Up 4
#define kJB__MoveCode_Vertical 12
#define kJB__MsgParseFlags_BreakPoint 32768
#define kJB__MsgParseFlags_Editable 2048
#define kJB__MsgParseFlags_Inserted 4096
#define kJB__MsgParseFlags_MacroInserted 12288
#define kJB__MsgParseFlags_MacroMade 8192
#define kJB__MsgParseFlags_NicelyPositioned 1024
#define kJB__MsgParseFlags_Style2 16384
#define kJB__ProcessMode_AutoPrintErrors 4
#define kJB__ProcessMode_CaptureAll 5
#define kJB__ProcessMode_CaptureErrors 2
#define kJB__ProcessMode_CaptureOrPrintErrors 6
#define kJB__ProcessMode_CaptureStdOut 1
extern int JB__Syx_CurrFuncID_;
#define kJB__TaskState_Animation 16
#define kJB__TaskState_Finished 64
#define kJB__TaskState_HadErrors 8
#define kJB__TaskState_Paused 2
#define kJB__TaskState_Started 1
#define kJB__TaskState_Successful 32
#define kJB__TaskState_WaitsTillStart 4
extern CompressionStats JB__MzSt_all;
extern Dictionary* JB__LD_ClassList;
#define kJB__Saver_RefMark 1073741824
extern SaverClassInfo* JB__Saver_SaveableList;
extern Random JB__Rnd_Shared;
#define kJB__Wrap_kDelete 2
#define kJB__Wrap_kFree 1
#define kJB__Wrap_kNothing (0)
#define kJB__Rec_NonFatal (JB_LUB[275])
extern double JB__Rec_Progress;
#define kJB__fix_TypeDict 3
#define kJB__fix_TypeObj 1
#define kJB__fix_TypeStem 2
#define kJB__fix_TypeValue (0)
extern bool JB__Flow_AlwaysMove;
extern bool JB__Flow_BreakOnFail;
extern int JB__Flow_Disabled;
extern FlowControl* JB__Flow_Flow;
extern byte JB__Flow_FlowMode;
#define kJB__Flow_Log 1
#define kJB__Flow_Off (0)
extern CompressionStats JB__Flow_Stats;
#define kJB__Flow_Validate 2
extern Array* JB__Macro_TmpPrms_;
extern uint64 JB__Mrap_MDummy_[2];
extern JB_String* JB__File__Speedie;
extern bool JB__File_DebugExecute;
#define kJB__File_IgnoreErrors 1
#define kJB__File_O_APPEND 8
#define kJB__File_O_CREAT 512
#define kJB__File_O_EXCL 2048
#define kJB__File_O_RDONLY (0x000)
#define kJB__File_O_RDWR 2
#define kJB__File_O_TRUNC 1024
#define kJB__File_O_WRONLY 1
extern byte JB__Err_AutoPrint;
extern Array* JB__Err_CurrSource_;
extern bool JB__Err_KeepStackTrace;

//// HEADER JB.h



// App
JB_String* JB_App__AppName();

JB_String* JB_App__AppPath();

int JB_App__Init_();

int JB_App__InitCode_();

JB_String* JB_App__OrigPath();

void JB_PrintStackTrace();

JB_String* JB_App__StackTrace(int Skip, FastString* Fs_in);



// ErrorColors
int JB_ErrorColors__Init_();

int JB_ErrorColors__InitCode_();



// API
Message* JB_API__Errors();

int JB_API__Init(int Flags);

int JB_API__Init_();

int JB_API__InitCode_();

void JB_API__NilCallBack(JB_String* ErrorMessage);

bool JB_API__NilHandler();

Message* JB_API__Parse(JB_String* S, JB_String* Path);



// Constants
void JB_Constants__AddEscape(uint /*byte*/ I, FastString* Fs);

int JB_Constants__Init_();

int JB_Constants__InitCode_();

void JB_Constants__InitConstants();

JB_String* JB_Constants__TestJB();



// MZLab


// Math


// Platform
int JB_Platform__Init_();

int JB_Platform__InitCode_();

void JB_Platform__Log(JB_String* S);

JB_File* JB_Platform__OpenLog();



// RingTree


// __classes__


// __modules__


// JB
ErrorInt JB_Main();



// main
bool JB_CompareError(Message* Expected, Message* Found);

JB_String* JB_EntityTest();

int JB_Init_();

int JB_InitCode_();

void JB_PrintLine(JB_String* Data);

void JB_Obj_PrintLine(JB_Object* O);



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


// byte
bool JB_byte_CanPrintAsNormalChar(uint /*byte*/ Self);

bool JB_byte_IsInt(uint /*byte*/ Self);

bool JB_byte_IsLetter(uint /*byte*/ Self);

bool JB_byte_IsTextLine(uint /*byte*/ Self);

bool JB_byte_IsUpper(uint /*byte*/ Self);

bool JB_byte_IsWhite(uint /*byte*/ Self);

byte JB_byte_LowerCase(uint /*byte*/ Self);

JB_String* JB_byte_Render(uint /*byte*/ Self, FastString* Fs_in);



// char


// cstring


// f64


// float
float JB_f_Pow(float Self, int N);



// hfloat


// int
int JB_int_LowestBit(int Self);

int JB_int_OperatorAlign(int Self, int To);

bool JB_int_OperatorIsa(int Self, uint N);

int JB_int_OperatorMax(int Self, int Other);

int JB_int_OperatorMin(int Self, int Other);

JB_String* JB_int_operatorof(int Self, JB_String* Type, JB_String* Nothing);

IntRange JB_int_OperatorTo(int Self, int Other);

int JB_int__Max();



// int16


// int64
int64 JB_int64_OperatorMin(int64 Self, int64 D);

JB_String* JB_int64_Render(int64 Self, FastString* Fs_in);



// ivec2


// ivec3


// ivec4


// uint


// uint16


// uint64


// vec2


// vec3


// vec4


// CharProp
int JB_CharProp__Init_();

int JB_CharProp__InitCode_();



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
bool JB_TC_IsFloat(uint /*DataTypeCode*/ Self);

bool JB_TC_IsNumeric(uint /*DataTypeCode*/ Self);



// Date
Date JB_Date__New0();



// ErrorFlags


// ErrorInt


// ErrorInt2


// ErrorMarker


// ErrorSeverity
JB_String* JB_ErrorSeverity_Render(uint /*ErrorSeverity*/ Self, FastString* Fs_in);

int JB_ErrorSeverity__Init_();

int JB_ErrorSeverity__InitCode_();

Array* JB_ErrorSeverity__InitNames();



// FileDes


// FileMode


// FileResolveMode


// FileSizeInt


// Float64


// FloatRangeConverter


// FloatRangeConverterBasic


// FlowControlStopper


// Ind


// IntRange
int JB_Rg_Width(IntRange Self);



// MaybeBool


// MoveCode


// MsgParseFlags


// PID_Int


// ParserLineAndIndent


// ProcessMode


// SizeInt


// Syntax
bool JB_Syx_IsString(Syntax Self);

bool JB_Syx_ListViewable(Syntax Self);

JB_String* JB_Syx_LongName(Syntax Self);

Message* JB_Syx_Msg(Syntax Self, JB_String* Name);

JB_String* JB_Syx_Name(Syntax Self);

SyntaxObj* JB_Syx_Obj(Syntax Self);

FP_fpMsgRender JB_Syx_RenderAddr(Syntax Self);

bool JB_Syx_Translateable(Syntax Self);

Syntax JB_Syx__Func(JB_String* Name, Message* Where);

int JB_Syx__Init_();

int JB_Syx__InitCode_();

Syntax JB_Syx__StdNew(FP_fpMsgRender Msg, JB_String* Name, JB_String* LongName, int ID);



// TaskState


// int8


// jbinLeaver


// mat2


// HumanDate


// ParseHandler


// PicoThreadFn


// SaverLoadClass


// SorterComparer


// SorterComparer2


// SorterComparerMsg


// SpdDeathActionFn


// SpdMainFn


// TokenHandler_fp


// __CopyID__


// __LoadProperties__


// __Render__


// __SaveCollect__


// __SaveWrite__


// __TextSet__


// __Text__


// fnErrorLogger


// fnIDGenerator


// fpDestructor


// fpMsgRender


// JB_ClassData
JB_MemoryLayer* JB_ClassData_CreateUseLayer(JB_Class* Self, JB_Object* Obj, JB_Object* Obj2);

void JB_ClassData_Restore(JB_Class* Self);



// JB_CompressionStats
void JB_MzSt_Clear(CompressionStats* Self);

void JB_MzSt_End(CompressionStats* Self);

void JB_MzSt_LiveUpdate(CompressionStats* Self, int S, int Outt, bool Compress);

void JB_MzSt_Print(CompressionStats* Self, bool Compress);

CompressionStats* JB_MzSt_Start(CompressionStats* Self);

int JB_MzSt__Init_();

int JB_MzSt__InitCode_();



// JB_FakeJBString


// JB_FastBuff
byte JB_FastBuff_Byte(FastBuff* Self);

byte* JB_FastBuff_Clip(FastBuff* Self, int V, int Reduce);

int JB_FastBuff_CopyTo(FastBuff* Self, byte* Dest, int Length);

void JB_FastBuff_Destructor(FastBuff* Self);

bool JB_FastBuff_Has(FastBuff* Self, int N);

bool JB_FastBuff_HasAny(FastBuff* Self);

int JB_FastBuff_Length(FastBuff* Self);

int JB_FastBuff_Position(FastBuff* Self);

void JB_FastBuff_PositionSet(FastBuff* Self, int Value);

void JB_FastBuff_ReadFromSet(FastBuff* Self, JB_String* Value);

int JB_FastBuff_Remaining(FastBuff* Self);

int JB_FastBuff_Size(FastBuff* Self);

JB_String* JB_FastBuff_AccessStr(FastBuff* Self, int Pos, int After);

void JB_FastBuff_SyntaxExpect(FastBuff* Self, JB_String* S);

JB_String* JB_FastBuff_TmpStr(FastBuff* Self);



// JB_FloatRange


// JB_IntDownRange


// JB_Mat4


// JB_MemoryWorld


// JB_MessagePosition
void JB_MsgPos_Destructor(MessagePosition* Self);

void JB_MsgPos_SyntaxUsingComplete(MessagePosition* Self, JB_Object* Idk);



// JB_ObjectLoader
void JB_LD_Destructor(ObjectLoader* Self);

bool JB_LD_HasItem(ObjectLoader* Self);

int64 JB_LD_Int(ObjectLoader* Self);

int64 JB_LD_ItemInt(ObjectLoader* Self);

bool JB_LD_ItemIsInt(ObjectLoader* Self);

JB_String* JB_LD_ItemName(ObjectLoader* Self);

JB_Object* JB_LD_ItemObject(ObjectLoader* Self);

Message* JB_LD_Next(ObjectLoader* Self);

JB_Object* JB_LD_Object(ObjectLoader* Self);

JB_Object* JB_LD_ObjectSub(ObjectLoader* Self, Message* C);

JB_String* JB_LD_String(ObjectLoader* Self);

int JB_LD__Init_();

int JB_LD__InitCode_();



// JB_ObjectSaver
void JB_Saver_AppendInt(ObjectSaver* Self, int64 I);

void JB_Saver_AppendObject(ObjectSaver* Self, JB_Object* O);

void JB_Saver_AppendString(ObjectSaver* Self, JB_String* S);

void JB_Saver_Destructor(ObjectSaver* Self);

int JB_Saver__Init_();

int JB_Saver__InitCode_();



// JB_Object_Behaviour


// JB_Pico
int JB_Pico__Init_();

int JB_Pico__InitCode_();



// JB_PicoConfig


// JB_PicoGlobalConfig


// JB_PicoGlobalStats


// JB_PicoMessage


// JB_Random
void JB_Rnd_LoadProperties(Random* Self, ObjectLoader* Loader);

void JB_Rnd_SaveWrite(Random* Self, ObjectSaver* Saver);

void JB_Rnd_SeedSet(Random* Self, uint64 Value);

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


// JB_ByteMap_Behaviour


// JB_Charset_Behaviour


// JB_DataObject_Behaviour


// JB_DictionaryReader_Behaviour


// JB_ErrorReceiver_Behaviour


// JB_FastString_Behaviour


// JB_FixedDict_Behaviour


// JB_FlowControl_Behaviour


// JB_LeakTester_Behaviour


// JB_Macro_Behaviour


// JB_MemoryLayer_Behaviour


// JB_Memory_Behaviour


// JB_ProcessOwner_Behaviour


// JB_Saveable_Behaviour


// JB_Selector_Behaviour


// JB_StringFields_Behaviour


// JB_StringReader_Behaviour


// JB_String_Behaviour


// JB_SyntaxObj_Behaviour


// JB_TokenHandler_Behaviour


// JB_Array_Behaviour


// JB_Dictionary_Behaviour


// JB_File_Behaviour


// JB_Process_Behaviour


// JB_StringShared_Behaviour


// JB_StringZeroTerminated_Behaviour


// JB_list_Behaviour


// JB_MessageID_Behaviour


// JB_Message_Behaviour


// JB_RangeCoder_Behaviour


// JB_SaverClassInfo_Behaviour


// JB_SimpleGraph_Behaviour


// JB_SpdProcess_Behaviour


// JB_Task_Behaviour


// JB_Error_Behaviour


// JB_Object
void jdb(JB_Object* Self);

bool JB_Object_FastIsa(JB_Object* Self, JB_Class* X);

bool JB_Object_Isa(JB_Object* Self, JB_Class* Cls);

void JB_Object_SaveTryCollect(JB_Object* Self, ObjectSaver* Saver);

void JB_Object_Fail(JB_Object* Self, JB_String* Error);



// JB_AppArgument


// JB_ByteMap


// JB_Charset
Array* JB_CS_Bytes(CharSet* Self);

bool JB_CS_NextInCharset(CharSet* Self, int* P);

bool JB_CS_OperatorContains(CharSet* Self, JB_String* Data);



// JB_DataObject
DTWrap* JB_Wrap_ConstructorInt(DTWrap* Self, int64 V);

void JB_Wrap_Destructor(DTWrap* Self);

double JB_Wrap_FloatValue(DTWrap* Self);

JB_String* JB_Wrap_Render(DTWrap* Self, FastString* Fs_in);



// JB_DictionaryReader
JB_Object* JB_DictionaryReader_NextValue(DictionaryReader* Self);



// JB_ErrorReceiver
int JB_Rec_BadCount(JB_ErrorReceiver* Self);

bool JB_Rec_CanAddMore(JB_ErrorReceiver* Self, uint /*ErrorSeverity*/ Level);

void JB_Rec_Clear(JB_ErrorReceiver* Self);

JB_ErrorReceiver* JB_Rec_Constructor(JB_ErrorReceiver* Self);

void JB_Rec_Destructor(JB_ErrorReceiver* Self);

void JB_Rec_Incr(JB_ErrorReceiver* Self, JB_Error* Err, bool Add);

JB_Error* JB_Rec_LastError(JB_ErrorReceiver* Self);

void JB_Rec_LogFileWriter(JB_ErrorReceiver* Self, JB_String* Data);

ErrorMarker JB_Rec_Mark(JB_ErrorReceiver* Self);

bool JB_Rec_OK(JB_ErrorReceiver* Self);

int JB_Rec_PrintErrorsMain(JB_ErrorReceiver* Self, uint /*ErrorSeverity*/ Level, bool PrintCount, bool Shell);

JB_String* JB_Rec_Render(JB_ErrorReceiver* Self, FastString* Fs_in);

int JB_Rec_RenderErrors(JB_ErrorReceiver* Self, FastString* Fs, uint /*ErrorSeverity*/ Level, bool Shell);

int JB_Rec_ShellPrintErrors(JB_ErrorReceiver* Self);

void JB_Rec_AppendErr(JB_ErrorReceiver* Self, JB_Error* Err);

int JB_Rec__Init_();

int JB_Rec__InitCode_();

void JB_Rec__NewErrorWithNode(Message* Node, JB_String* Desc, JB_String* Path);

void JB_Rec__NewErrorSub(Message* Node, JB_String* Desc, JB_String* Path, int Sev);



// JB_FastString
void JB_FS_AppendEscape(FastString* Self, JB_String* S);

void JB_FS_AppendHexStr(FastString* Self, JB_String* Data);

void JB_FS_AppendObjectID(FastString* Self, Saveable* O);

void JB_FS_AppendObjectOrNil(FastString* Self, JB_Object* O);

void JB_FS_AppendQuotedEscape(FastString* Self, JB_String* S);

void JB_FS_AppendInfo(FastString* Self, JB_String* Name, JB_String* Data);

void JB_FS_AppendInfoNum(FastString* Self, JB_String* Name, int64 Data);

void JB_FS_AppendInfoFloat(FastString* Self, JB_String* Name, double Data);

void JB_FS_FieldStart(FastString* Self, JB_String* Name);

void JB_FS_hInt(FastString* Self, uint64 N);

void JB_FS_MsgErrorName(FastString* Self, JB_String* Name);

void JB_FS_PrintNicely(FastString* Self, JB_String* S);

void JB_FS_ProblemsFound(FastString* Self, int Count);

JB_String* JB_FS_Render(FastString* Self, FastString* Fs_in);

void JB_FS_AppendFastString(FastString* Self, FastString* Fs);

void JB_FS_AppendInt32(FastString* Self, int Data);

void JB_FS_SyntaxAppend(FastString* Self, Message* Msg);

FastString* JB_FS__Use(JB_Object* Other);



// JB_FixedDict


// JB_FlowControl
void JB_Flow_AddByte(FlowControl* Self, uint /*byte*/ Value);

bool JB_Flow_Cond(FlowControl* Self, uint /*byte*/ Value);

void JB_Flow_Destructor(FlowControl* Self);

void JB_Flow_Fail(FlowControl* Self, JB_String* Found, JB_String* Expected, JB_String* InputName);

void JB_Flow_Flush(FlowControl* Self);

int JB_Flow__Init_();

int JB_Flow__InitCode_();

void JB_Flow__Input(JB_String* Data, JB_String* Name);

bool JB_Flow__Cond(bool Value);



// JB_LeakTester
LeakTester* JB_Lk_Constructor(LeakTester* Self, JB_String* Name);

void JB_Lk_Destructor(LeakTester* Self);

void JB_Lk_FinalTest(LeakTester* Self);

void JB_Lk_Test2(LeakTester* Self);



// JB_Macro
int JB_Macro__Init_();

int JB_Macro__InitCode_();



// JB_Memory
MWrap* JB_Mrap_ConstructorPtr(MWrap* Self, int ItemCount, int ItemSize, byte* Ptr, uint /*byte*/ DeathAction);

void JB_Mrap_Destructor(MWrap* Self);

Array* JB_Mrap__CollectLeaks_(JB_Object* Self);

int JB_Mrap__Init_();

int JB_Mrap__InitCode_();

MWrap* JB_Mrap__Object(int Count, int ItemSize);

void jbl(JB_Object* Self);



// JB_MemoryLayer


// JB_ProcessOwner


// JB_Saveable
bool JB_Sav_IsSaveMarked(Saveable* Self);

void JB_Sav_LoadProperties(Saveable* Self, ObjectLoader* Loader);

void JB_Sav_SaveCollect(Saveable* Self, ObjectSaver* Saver);

bool JB_Sav_SaveMark(Saveable* Self);

SaverClassInfo* JB_Sav_SaverInfo(Saveable* Self);

void JB_Sav_SaveWrite(Saveable* Self, ObjectSaver* Saver);



// JB_Selector
void JB_Sel_Destructor(Selector* Self);



// JB_String
JB_String* JB_Str_AfterByte(JB_String* Self, uint /*byte*/ B, int Last);

JB_String* JB_Str_BackToApp(JB_String* Self);

JB_String* JB_Str_BeforeLastByte(JB_String* Self, uint /*byte*/ B, int Fudge);

Array* JB_Str_ByteSplit(JB_String* Self);

CharSet* JB_Str_CharSetWithBool(JB_String* Self, bool Range);

JB_String* JB_Str_Child(JB_String* Self, JB_String* Cname);

JB_String* JB_Str_Compress(JB_String* Self, int Strength, CompressionStats* St);

void JB_Str_CompressInto(JB_String* Self, JB_Object* Fs, int Strength, CompressionStats* St);

int JB_Str_Count(JB_String* Self, uint /*byte*/ B);

JB_String* JB_Str_Decompress(JB_String* Self, int Lim, CompressionStats* St);

bool JB_Str_EndsWith(JB_String* Self, JB_String* S, bool Aware);

JB_String* JB_Str_Escape(JB_String* Self);

JB_String* JB_Str_EscapeChr(JB_String* Self);

bool JB_Str_EscapeTest(JB_String* Self);

JB_File* JB_Str_AsFile(JB_String* Self);

Ind JB_Str_FindByte(JB_String* Self, uint /*byte*/ Find, int Start, int After);

Ind JB_Str_Find(JB_String* Self, CharSet* Cs, int Start, int After);

Ind JB_Str_FindSlash(JB_String* Self, int From);

Ind JB_Str_InWhite(JB_String* Self, int Start, int After);

bool JB_Str_IsCompressed(JB_String* Self);

int JB_Str_IsHexLike(JB_String* Self, int N);

Ind JB_Str_IsJbin(JB_String* Self);

bool JB_Str_IsLower(JB_String* Self);

bool JB_Str_IsOK(JB_String* Self);

bool JB_Str_IsStatementName(JB_String* Self);

Ind JB_Str_JBFind(JB_String* Self, uint /*byte*/ Find, int Off, int After);

byte JB_Str_Last(JB_String* Self, int Minus);

int JB_Str_LineCount(JB_String* Self);

ErrorInt JB_Str_MakeEntirePath(JB_String* Self, bool Last);

JB_String* JB_Str_Name(JB_String* Self);

bool JB_Str_ContainsString(JB_String* Self, JB_String* S);

bool JB_Str_OperatorEndsWith(JB_String* Self, JB_String* S);

int JB_Str_OperatorMinus(JB_String* Self, JB_String* S);

FastString* JB_Str_Out(JB_String* Self, bool Clear);

Ind JB_Str_OutCharSet(JB_String* Self, CharSet* Cs, int Start, int After);

Ind JB_Str_OutWhite(JB_String* Self, int Start, int After);

JB_String* JB_Str_Parent(JB_String* Self);

Message* JB_Str_Parse(JB_String* Self, Syntax Owner, bool AllowDecomp);

Message* JB_Str_ParseJbin(JB_String* Self, int64 Max);

Message* JB_Str_ParseSub(JB_String* Self, Syntax Owner, bool AllowDecomp);

JB_String* JB_Str_Pluralize(JB_String* Self, int Amount, JB_String* Nothing);

JB_String* JB_Str_Preview(JB_String* Self, int N);

Array* JB_Str_Split(JB_String* Self, uint /*byte*/ Sep);

JB_String* JB_Str_Squeeze(JB_String* Self);

StringReader* JB_Str_Stream(JB_String* Self);

void JB_Str_SyntaxExpect(JB_String* Self);

int JB_Str_TrimLastSub(JB_String* Self, uint /*byte*/ B);

JB_String* JB_Str_TrimSlashes(JB_String* Self, bool Pathfix);

JB_String* JB_Str_Unescape(JB_String* Self);

CharSet* JB_Str_UniCS(JB_String* Self);

int JB_Str_UnPrintable(JB_String* Self);

Array* JB_Str_Words(JB_String* Self);

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



// JB_TokenHandler


// JB_Array
JB_Object* JB_Array_Last(Array* Self);

void JB_Array_LoadProperties(Array* Self, ObjectLoader* Loader);

void JB_Array_SaveCollect(Array* Self, ObjectSaver* Saver);

void JB_Array_SaveWrite(Array* Self, ObjectSaver* Saver);

void JB_Array_SyntaxAppend(Array* Self, JB_Object* Item);



// JB_Dictionary
void JB_Dict_LoadProperties(Dictionary* Self, ObjectLoader* Loader);

void JB_Dict_SaveCollect(Dictionary* Self, ObjectSaver* Saver);

void JB_Dict_SaveWrite(Dictionary* Self, ObjectSaver* Saver);

JB_Object* JB_Dict_Value0(Dictionary* Self, JB_String* Key);

void JB_Dict_SetInt(Dictionary* Self, uint64 Key, JB_Object* Value);

JB_Object* JB_Dict_ValueInt(Dictionary* Self, uint64 Key);

JB_Object* JB_Dict_ValueLower(Dictionary* Self, JB_String* S);

Dictionary* JB_Dict__Copy(Dictionary* Dict);

Dictionary* JB_Dict__Reverse(Dictionary* Dict);



// JB_File
JB_File* JB_File_Child(JB_File* Self, JB_String* Name);

bool JB_File_Opened(JB_File* Self);

JB_File* JB_File_SyntaxAccess(JB_File* Self, JB_String* Name);

void JB_File_SyntaxAppend(JB_File* Self, JB_String* Data);

void JB_File_Fail(JB_File* Self, JB_String* Error);

int JB_File__Init_();

int JB_File__InitCode_();

JB_File* JB_File__Logs();



// JB_JBin
jbinLeaver JB_bin_Add(FastString* Self, Syntax Type, JB_String* Name, bool Into);

void JB_bin_AddInt(FastString* Self, int64 Name);

jbinLeaver JB_bin_AddMemory(FastString* Self, Syntax Type, uint64 L, bool GoIn, byte* Data);

void JB_bin_CloseSection(FastString* Self, int C);

FastString* JB_bin_Constructor0(FastString* Self, int N);

jbinLeaver JB_bin_Enter(FastString* Self, Syntax Type, JB_String* Name);

void JB_bin_Exit(FastString* Self, int Amount);

int JB_bin_OpenSection(FastString* Self);

void JB_bin_Sheb(FastString* Self, JB_String* Name);



// JB_OutputFile


// JB_Process


// JB_StringShared


// JB_StringThatWasReadSafely


// JB_StringZeroTerminated


// JB_list
void JB_Tree_Clear(JB_List* Self);

bool JB_Tree_HasOneChild(JB_List* Self);

void jdb2(JB_List* Self);

void jdb3(JB_List* Self);

void JB_Tree_Remove(JB_List* Self);

JB_String* JB_List_Render(JB_List* Self, FastString* Fs_in);

JB_List* JB_Tree_Second(JB_List* Self);

void JB_Tree_SyntaxAppend(JB_List* Self, JB_List* Last);

bool JB_Tree_SyntaxEquals(JB_List* Self, int N, bool Aware);

JB_List* JB_Tree_Upward(JB_List* Self, int N);



// JB_ExistingFile


// JB_JeeboxFile


// JB_Message
void JB_Msg_Acc__(Message* Self, FastString* Fs);

void JB_Msg_CantFind(Message* Self, Syntax S, JB_String* Name, Message* Found);

void JB_Msg_Adj__(Message* Self, FastString* Fs);

int JB_Msg_After(Message* Self);

void JB_Msg_AfterSet(Message* Self, int Value);

void JB_Msg_ARel__(Message* Self, FastString* Fs);

void JB_Msg_Arg__(Message* Self, FastString* Fs);

void JB_Msg_Arr__(Message* Self, FastString* Fs);

void JB_Msg_Ask__(Message* Self, FastString* Fs);

void JB_Msg_Back__(Message* Self, FastString* Fs);

void JB_Msg_Badj__(Message* Self, FastString* Fs);

void JB_Msg_BecomeStr(Message* Self, Syntax Fn, JB_String* Name);

void JB_Msg_Bin__(Message* Self, FastString* Fs);

void JB_Msg_binn__(Message* Self, FastString* Fs);

void JB_Msg_BinnRender(Message* Self, FastString* Fs, JB_String* Sepa, JB_String* Sepb);

void JB_Msg_Bra__(Message* Self, FastString* Fs);

void JB_Msg_BRel__(Message* Self, FastString* Fs);

void JB_Msg_Char__(Message* Self, FastString* Fs);

int JB_Msg_CleanIndent(Message* Self);

void JB_Msg_Cnj__(Message* Self, FastString* Fs);

Message* JB_Msg_ConstructorCopy(Message* Self, Message* Other);

Message* JB_Msg_ConstructorEmpty(Message* Self);

Message* JB_Msg_ConstructorNormal(Message* Self, Syntax Func, JB_String* Name);

Message* JB_Msg_ConstructorRange(Message* Self, Message* Parent, Syntax Func, int BytePos, JB_String* Name, int RangeLength);

Message* JB_Msg_Copy(Message* Self, Message* Pos_msg);

JB_String* JB_Msg_CopyID(Message* Self);

Message* JB_Msg_CopySub(Message* Self, Message* P);

void JB_Msg_Decl__(Message* Self, FastString* Fs);

void JB_Msg_Destructor(Message* Self);

void JB_Msg_Dot__(Message* Self, FastString* Fs);

void JB_Msg_Dummy(Message* Self, FastString* Fs);

void JB_Msg_Emb__(Message* Self, FastString* Fs);

void JB_Msg_ERel__(Message* Self, FastString* Fs);

bool JB_Msg_Expect(Message* Self, Syntax Type, JB_String* Name);

bool JB_Msg_ExpectLast(Message* Self, JB_String* Err);

void JB_Msg_File__(Message* Self, FastString* Fs);

JB_String* JB_Msg_FilePath(Message* Self);

Message* JB_Msg_FindSyxName(Message* Self, Syntax S, JB_String* Name, bool Err);

Message* JB_Msg_FindNotInserted(Message* Self);

JB_String* JB_Msg_FirstName(Message* Self);

void JB_Msg_FSListArg(Message* Self, FastString* Fs, bool AddLine);

void JB_Msg_FSListSep(Message* Self, FastString* Fs, JB_String* Sep);

void JB_Msg_Func__(Message* Self, FastString* Fs);

JB_String* JB_Msg_FuncName(Message* Self);

Message* JB_Msg_GoIntoInvisArg(Message* Self, Message* Tmp, int Pos);

int JB_Msg_IndentScore(Message* Self);

bool JB_Msg_InInvisArg(Message* Self);

int64 JB_Msg_Int(Message* Self, int StrStart);

void JB_Msg_Item__(Message* Self, FastString* Fs);

bool JB_Msg_jbinTest(Message* Self);

JB_String* JB_Msg_JDB2_(Message* Self, int Flags, FastString* Fs_in);

JB_String* JB_Msg_JDB_(Message* Self, FastString* Fs_in, int Flags);

int JB_Msg_Length(Message* Self);

void JB_Msg_List__(Message* Self, FastString* Fs);

bool JB_Msg_ListViewable(Message* Self);

JB_String* JB_Msg_Locate(Message* Self);

void JB_Msg_max__(Message* Self, FastString* Fs);

JB_String* JB_Msg_MiniName(Message* Self, JB_String* Prefix);

Message* JB_Msg_Msg(Message* Self, Syntax Fn, JB_String* Name);

void JB_Msg_Msg__(Message* Self, FastString* Fs);

void JB_Msg_Name__(Message* Self, FastString* Fs);

void JB_Msg_Nil__(Message* Self, FastString* Fs);

void JB_Msg_Num__(Message* Self, FastString* Fs);

void JB_Msg_Oat__(Message* Self, FastString* Fs);

bool JB_Msg_InMsg(Message* Self, Message* F);

bool JB_Msg_OperatorIn(Message* Self, Syntax F);

void JB_Msg_Opp__(Message* Self, FastString* Fs);

JB_String* JB_Msg_OriginalParseData(Message* Self);

Message* JB_Msg_ParseAST(Message* Self);

void JB_Msg_pinn__(Message* Self, FastString* Fs);

JB_String* JB_Msg_plocate(Message* Self);

int JB_Msg_PrevIndentCheck(Message* Self, Message* Pr);

void JB_Msg_Prm__(Message* Self, FastString* Fs);

void JB_Msg_Ques__(Message* Self, FastString* Fs);

void JB_Msg_Quot__(Message* Self, FastString* Fs);

void JB_Msg_RangeSet(Message* Self, IntRange R);

void JB_Msg_Rel__(Message* Self, FastString* Fs);

JB_String* JB_Msg_Render(Message* Self, FastString* Fs_in);

void JB_Msg_render_jbin_sub(Message* Self, FastString* Js);

JB_String* JB_Msg_RenderAST(Message* Self, int Flags, FastString* Fs_in);

JB_String* JB_Msg_RenderJbin(Message* Self, JB_String* Shell_path, FastString* Fs_in);

void JB_Msg_RenderPrm(Message* Self, FastString* Fs, uint /*byte*/ B1, uint /*byte*/ B2);

void JB_Msg_RenderWithSpaces(Message* Self, FastString* Fs, Message* Ch);

void JB_Msg_SCnj__(Message* Self, FastString* Fs);

void JB_Msg_SCom__(Message* Self, FastString* Fs);

void JB_Msg_SDot__(Message* Self, FastString* Fs);

void JB_Msg_Sheb__(Message* Self, FastString* Fs);

void JB_Msg_SStr__(Message* Self, FastString* Fs);

void JB_Msg_SThg__(Message* Self, FastString* Fs);

void JB_Msg_Str__(Message* Self, FastString* Fs);

bool JB_Msg_SyntaxEquals(Message* Self, JB_String* Name, bool Aware);

bool JB_Msg_EqualsSyx(Message* Self, Syntax X, bool Aware);

void JB_Msg_SyntaxExpect(Message* Self, JB_String* Error);

bool JB_Msg_SyntaxIs(Message* Self, uint /*MsgParseFlags*/ F);

void JB_Msg_SyntaxIsSet(Message* Self, uint /*MsgParseFlags*/ F, bool Value);

void JB_Msg_SyntaxUsing(Message* Self, MessagePosition* Rz);

void JB_Msg_Test(Message* Self, JB_String* New_render, JB_String* Name);

void JB_Msg_test_style(Message* Self);

bool JB_Msg_TestSub(Message* Self, JB_String* New_render, JB_String* Name);

JB_String* JB_Msg_Text(Message* Self, int I);

bool JB_Msg_TextSet(Message* Self, int I, JB_String* V);

Message* JB_Msg_TextViewChild(Message* Self);

void JB_Msg_Thg__(Message* Self, FastString* Fs);

void JB_Msg_Tmp__(Message* Self, FastString* Fs);

void JB_Msg_Todo__(Message* Self, FastString* Fs);

void JB_Msg_TRel__(Message* Self, FastString* Fs);

void JB_Msg_Tril__(Message* Self, FastString* Fs);

void JB_Msg_Type__(Message* Self, FastString* Fs);

void JB_Msg_UnEmbedStr(Message* Self);

void JB_Msg_Unit__(Message* Self, FastString* Fs);

void JB_Msg_url__(Message* Self, FastString* Fs);

void JB_Msg_XAtt__(Message* Self, FastString* Fs);

void JB_Msg_XCDT__(Message* Self, FastString* Fs);

void JB_Msg_XCom__(Message* Self, FastString* Fs);

void JB_Msg_XML__(Message* Self, FastString* Fs);

void JB_Msg_XPI__(Message* Self, FastString* Fs);

void JB_Msg_XTxt__(Message* Self, FastString* Fs);

void JB_Msg_Yoda__(Message* Self, FastString* Fs);

bool JB_Msg__TreeCompare(Message* Orig, Message* Reparse, bool PrintIfSame);

void JB_Msg__TreeComparePrint(Message* Orig);



// JB_MessageID


// JB_MessageTable


// JB_RangeCoder


// JB_SaverClassInfo
void JB_sci_Destructor(SaverClassInfo* Self);



// JB_SimpleGraph


// JB_SpdProcess
int JB_Proc__InitCode_();

void JB_Proc__InitOwner();



// JB_Task
void JB_Task_Destructor(JB_Task* Self);



// JB_Error
JB_Error* JB_Err_Constructor(JB_Error* Self, Message* Node, JB_String* Desc, uint /*ErrorSeverity*/ Level, JB_String* Path);

JB_Error* JB_Err_ConstructorNothing(JB_Error* Self);

void JB_Err_Destructor(JB_Error* Self);

void JB_Err_Fill(JB_Error* Self, JB_String* Path, JB_String* Desc);

void JB_Err_GrabLine(JB_Error* Self, FastString* Fs, bool Usecolor);

bool JB_Err_HasPosition(JB_Error* Self);

bool JB_Err_IsBad(JB_Error* Self);

bool JB_Err_IsError(JB_Error* Self);

bool JB_Err_IsWarning(JB_Error* Self);

bool JB_Err_LineIdentifiers(JB_Error* Self, FastString* Fs, JB_String* Path);

int JB_Err_LinePos(JB_Error* Self, JB_String* Data);

JB_String* JB_Err_Render(JB_Error* Self, FastString* Fs_in);

JB_String* JB_Err_RenderClang(JB_Error* Self, FastString* Fs_in);

bool JB_Err_SyntaxIs(JB_Error* Self, uint /*ErrorFlags*/ F);

void JB_Err_SyntaxIsSet(JB_Error* Self, uint /*ErrorFlags*/ F, bool Value);

void JB_Err_UpgradeWithNode(JB_Error* Self);

void JB_Err__CantParseNum(Message* Where, JB_String* Num, int Pos, bool Overflow);

int JB_Err__Init_();

int JB_Err__InitCode_();



// JB_FileArchive


// JB_MessageRoot


// JB_config
inline bool JB_ErrorMarker_SyntaxCast(ErrorMarker Self);

inline bool JB_FastBuff_AppendU8(FastBuff* Self, uint /*byte*/ V);

inline bool JB_File_SyntaxCast(JB_File* Self);

inline bool JB_Ind_SyntaxCast(Ind Self);

inline Syntax JB_Msg_Func(Message* Self);

inline JB_String* JB_Msg_Name(Message* Self);

inline JB_String* JB_Msg_Name_(Message* Self);

inline int JB_Sel_ID(Selector* Self);

inline JB_String* JB_Tk__SyntaxAccess(int S, int E, Syntax F);

inline bool JB_Array_SyntaxCast(Array* Self);

inline void JB_FS_AppendInt64(FastString* Self, int64 Data);

inline JB_String* JB_FS_SyntaxCast(FastString* Self);

inline JB_String* JB_Object___Render__(JB_Object* Self, FastString* Fs_in);

inline void JB_Sav___SaveCollect__(Saveable* Self, ObjectSaver* Saver);

inline JB_StringC* JB_Str_CastZero(JB_String* Self);

inline bool JB_Safe_SyntaxCast(JB_String* Self);

inline bool JB_Msg_NilCheck(Message* Self);

inline bool JB_Syx_NilCheck(Syntax Self);

JB_String* jb_msg_name(Message* Self);

Syntax jb_msg_func(Message* Self);

int jb_msg_position(Message* Self);

void* jb_msg_tag(Message* Self);

void jb_msg_nameset(Message* Self, JB_String* Result);

void jb_msg_funcset(Message* Self, Syntax Result);

void jb_msg_positionset(Message* Self, int Result);

void jb_msg_tagset(Message* Self, void* Result);

void jb_msg_firstset(Message* Self, Message* Result);

void jb_msg_lastset(Message* Self, Message* Result);

void jb_msg_prevset(Message* Self, Message* Result);

void jb_msg_nextset(Message* Self, Message* Result);

Message* jb_msg_first(Message* Self);

Message* jb_msg_last(Message* Self);

Message* jb_msg_prev(Message* Self);

Message* jb_msg_next(Message* Self);

Message* jb_msg_parent(Message* Self);

Message* jb_msg_flatnext(Message* Self);

Message* jb_msg_flatafter(Message* Self);

Message* jb_msg_root(Message* Self);

void jb_msg_remove(Message* Self);

JB_String* jb_msg_render(Message* Self, int Mode);

JB_String* jb_msg_ast(Message* Self);

Message* jb_msg_parseast(Message* Self);

Message* jb_msg_copy(Message* Self, Message* Layer);

Message* jb_msg_create(Message* Self, Syntax Type, JB_String* Name);

void jb_msg_error(Message* Self, JB_String* ErrorMsg);

Message* jb_msg_expect(Message* Self, Syntax Type, JB_String* Name, Message* ErrPlace);

Message* jb_msg_access(Message* Self, Syntax Type, JB_String* Name, bool IsError);

JB_String* jb_syx_name(Syntax Self);

JB_String* jb_syx_longname(Syntax Self);

_cstring jb_string_address(JB_String* Self);

int jb_string_length(JB_String* Self);

JB_String* jb_string_compress(JB_String* Self);

JB_String* jb_string_decompress(JB_String* Self);

JB_String* jb_string_copy(JB_String* Self);

Message* jb_string_parse(JB_String* Self, JB_String* Path);

JB_String* jb_string_escape(JB_String* Self);

void jb_string_print(JB_String* Self);

void jb_string_printline(JB_String* Self);

int64 jb_string_int(JB_String* Self, Message* M);

double jb_string_float(JB_String* Self, Message* M);

Syntax jb_syntax(JB_String* Name);

JB_String* jb_str(_cstring Str, int Length, void* Release, void* Tag);

JB_String* jb_cstr(_cstring Str);

void jb_delete_(JB_Object* Obj);

Message* jb_errors();

bool jb_ok();

void jb_debug(JB_Object* O);

int jb_init(int Flags);

int jb_shutdown();

int jb_version();

JB_String* jb_readfile(_cstring Path, bool AllowMissingFile);


//// HEADER Inlines.h
inline bool JB_ErrorMarker_SyntaxCast(ErrorMarker Self) {
	return JB_StdErr->ErrorCount == Self;
}

inline bool JB_FastBuff_AppendU8(FastBuff* Self, uint /*byte*/ V) {
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

inline bool JB_Array_SyntaxCast(Array* Self) {
	return JB_Array_Size(Self) > 0;
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

inline void JB_Sav___SaveCollect__(Saveable* Self, ObjectSaver* Saver) {
	Saveable_Behaviour* Table = ((Saveable_Behaviour*)JB_ObjClassBehaviours(Self));
	return (Table->savecollect)(Self, Saver);
}

inline JB_StringC* JB_Str_CastZero(JB_String* Self) {
	return JB_Str_MakeC(Self);
}

inline bool JB_Safe_SyntaxCast(JB_String* Self) {
	return JB_Str_IsOK(Self);
}

inline bool JB_Msg_NilCheck(Message* Self) {
	return ((bool)Self) or JB_API__NilHandler();
}

inline bool JB_Syx_NilCheck(Syntax Self) {
	return ((bool)Self) or JB_API__NilHandler();
}



}
#endif // __JB_H__
