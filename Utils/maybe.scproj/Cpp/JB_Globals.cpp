
// Globals put into a separate file to make things faster.
#include "JB_Umbrella.hpp"
#include "JB.h"
#pragma GCC visibility push(hidden)

Message* JB__App__Conf;
JB_String* JB__App_codesign_native;
Array* JB__App_OldArgs;

bool JB__App_Unregistered;
bool JB__ErrorColors_Enabled;
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
Dictionary* JB__Constants_UnEscapeStr;
Dictionary* JB__Constants_XML_EscapeStr;
Dictionary* JB__Constants_XML_UnEscapeStr;
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
JB_String* JB__zalgo_down;
JB_String* JB__zalgo_mid;
Random JB__zalgo_R;
JB_String* JB__zalgo_up;
SyntaxObj* JB__FuncArray_[64];
JB_String* JB__JbinHeader;
Dictionary* JB__SyxDict_;
Dictionary* JB_DoAction;
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
Array* JB__ErrorSeverity_names;
int JB__Syx_CurrFuncID;
int JB__Syx_MaxFuncID;
Dictionary* JB__TC_Types_Dict;
CompressionStats JB__MzSt_All;
Dictionary* JB__LD_ClassList;
SaverClassInfo* JB__Saver_SaveableList;
Random JB__Rnd_Shared;
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

uint64 JB__Mrap_MDummy[2];
Memory_Behaviour InitTableMWrap_() { // Behaviour 
	Memory_Behaviour Result;
	Result.__destructor__ = (void*)JB_Mrap_Destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

Memory_Behaviour MWrap_FuncTable_ = InitTableMWrap_();
JBClassPlace4(MWrap, JB_AsClass(JB_Object), MWrap_FuncTable_);

Person_Behaviour InitTablePerson_() { // Behaviour 
	Person_Behaviour Result;
	Result.__destructor__ = (void*)App_Person_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

Person_Behaviour Person_FuncTable_ = InitTablePerson_();
JBClassPlace4(Person, JB_AsClass(JB_Object), Person_FuncTable_);

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

RPGHero_Behaviour InitTableRPGHero_() { // Behaviour 
	RPGHero_Behaviour Result;
	Result.__destructor__ = (void*)App_RPGHero_destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

RPGHero_Behaviour RPGHero_FuncTable_ = InitTableRPGHero_();
JBClassPlace4(RPGHero, JB_AsClass(JB_Object), RPGHero_FuncTable_);

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

bool JB__File_DebugExecute;
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

JB_String* JB_LUB[351];

int JB_LUBLengths[] = {12, 4, 1, 1, 1, 17, 5, 18, 9, 9, 16, 8, 7, 5, 4, 10, 1, 3, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 2, 3, 1, 5, 6, 6, 1, 4, 1, 4, 1, 2, 1, 2, 8, 4, 6, 2, 7, 3, 17, 1, 2, 2, 2, 3, 13, 1, 19, 28, 6, 4, 1, 14, 8, 14, 11, 11, 11, 11, 24, 2, 36, 9, 1, 1, 21, 2, 28, 1, 18, 22, 3, 1, 17, 20, 4, 3, 9, 3, 2, 19, 37, 3, 20, 33, 3, 3, 2, 1, 11, 2, 15, 3, 1, 5, 10, 76, 31, 15, 1, 2, 1, 2, 3, 1, 1, 1, 5, 1, 17, 2, 1, 2, 2, 2, 3, 1, 2, 3, 1, 2, 2, 3, 3, 2, 9, 18, 2, 3, 29, 1, 8, 11, 9, 3, 8, 17, 6, 9, 17, 3, 9, 14, 46, 15, 32, 29, 18, 16, 4, 3, 96, 46, 80, 16, 16, 13, 2, 3, 8, 3, 8, 3, 7, 3, 5, 3, 8, 3, 4, 3, 9, 4, 4, 8, 4, 8, 4, 9, 4, 12, 3, 17, 4, 7, 3, 6, 4, 15, 4, 14, 3, 6, 3, 14, 4, 4, 8, 4, 18, 3, 3, 4, 8, 4, 8, 4, 19, 3, 9, 4, 19, 3, 6, 3, 5, 4, 4, 3, 14, 4, 9, 4, 9, 4, 11, 3, 12, 4, 19, 4, 21, 4, 22, 4, 13, 4, 8, 3, 4, 17, 4, 17, 3, 12, 4, 10, 3, 3, 3, 4, 4, 13, 3, 11, 3, 25, 4, 11, 4, 9, 4, 8, 3, 3, 9, 14, 15, 38, 5, 2, 41, 2, 14, 4, 5, 6, 8, 4, 17, 10, 7, 7, 12, 6, 8, 13, 14, 4, 20, 1, 4, 14, 8, 21, 21, 2, 25, 6, 2, 45, 10, 5, 3, 5, 3, 2, 2, 53, 1, 1, 1, 1, 12, 3, 3, 6, 18, 8, 4, 4, 3, 4, 2, 2, 2, 2, 3, 5, 3, 22, 10, 3, 6, 9, 9, 4, 9, 8, 0};

const char* JB_LUBSrc = "codesign_osx\x00""fred\x00""a\x00""b\x00""c\x00 has three items.\x00house\x00' has five letters\x00(a,b,c,d)\x00The list \x00 has four items!\x00 is even\x00 is odd\x00z is \x00jump\x00hes scared\x00\x00\x00\\00\x00\n\x00\\n\x00\r\x00\\r\x00\t\x00\\t\x00\x22\x00\\\x22\x00'\x00\\'\x00\\\x00\\\\\x00&#\x00\\&#\x00&\x00&amp;\x00&apos;\x00&quot;\x00<\x00&lt;\x00>\x00&gt;\x00\x08\x00\\b\x00\x0C\x00\\f\x00""AZaz09__\x00""AZaz\x00""AZaz__\x00\n\r\x00 ,:\t\n\r\\\x00\n\r,\x00 \t\n\r\x0F-^+/\\*:;<>=,\x00$\x00\\$\x00\\0\x00${\x00$\\{\x00Indent is odd\x00|\x00""Close-tag malformed\x00Open/close tags mismatch! </\x00> vs <\x00<\xE2\x89\x88\x00(\x00Missing close \x00Nested '\x00' not allowed.\x00Unexpected \x00 but found \x00""end-of-line\x00""end-of-data\x00""Found illegal-character \x00""0x\x00""Expected a letter (aA-zZ, '_', etc).\x00Missing '\x00]\x00}\x00String did not close.\x00)#\x00""Binary section didn't close!\x00)\x00""Char didn't close!\x00""Comment did not close.\x00\xE2\x80\x93\x00 \x00Unexpected syntax\x00""Element didn't close\x00<!--\x00-->\x00<![CDATA[\x00]]>\x00\xC2\xBB\x00Needs a space here.\x00""Can\xE2\x80\x99t have '=' after this operator.\x00\xE2\x80\x9D\x00String didn't close!\x00""Embedded expression didn't close.\x00<(`\x00`)>\x00#/\x00:\x00""Bad Doctype\x00\?>\x00Indent too low.\x00\r \n\x00,\x00line \x00""0123456789\x00= == === < > <= <== >= >== <> ~<> != !== <=> ~>= ~<= ~> ~< <~ ~= ~!= ~<=> :=\x00* / \\ + - ^ & >> << >>> <<< (|)\x00++ -- $ ! \? ...\x00[\x00\xC2\xAB\x00.\x00..\x00://\x00+\x00@\x00~\x00- * ~\x00{\x00--> <-- <--> <\xE2\x89\x88\x00/#\x00%\x00#!\x00//\x00/*\x00...\x00`\x00#(\x00\xE2\x89\x88\x00#\x00>~\x00\xC2\xAC\x00\xE2\x80\x9C\x00\xE2\x88\x86\x00<\?\x00<!DOCTYPE\x00] ) } #/ \xC2\xBB \xE2\x80\x9D \?>\x00::\x00!~=\x00""Can't have tabs after spaces.\x00=\x00temporal\x00""declaration\x00statement\x00':'\x00operator\x00temporal-operator\x00""a name\x00something\x00illegal-character\x00 / \x00""Expected \x00something else\x00Must be a proper name (a-z or unicode-letters)\x00""Expected a rel.\x00""Can\xE2\x80\x99t use temporals like this.\x00""Attribute value didn't close.\x00""Element malformed.\x00Tag didn't close\x00.log\x00osx\x00\xCC\x8D\xCC\x8E\xCC\x84\xCC\x85\xCC\xBF\xCC\x91\xCC\x86\xCC\x90\xCD\x92\xCD\x97\xCD\x91\xCC\x87\xCC\x88\xCC\x8A\xCD\x82\xCD\x83\xCD\x84\xCD\x8A\xCD\x8B\xCD\x8C\xCC\x83\xCC\x82\xCC\x8C\xCD\x90\xCC\x80\xCC\x81\xCC\x8B\xCC\x8F\xCC\x92\xCC\x93\xCC\x94\xCC\xBD\xCC\x89\xCD\xA3\xCD\xA4\xCD\xA5\xCD\xA6\xCD\xA7\xCD\xA8\xCD\xA9\xCD\xAA\xCD\xAB\xCD\xAC\xCD\xAD\xCD\xAE\xCD\x9B\xCD\x86\xCC\x9A\x00\xCC\x95\xCC\x9B\xCD\x80\xCD\x81\xCD\x98\xCC\xA1\xCC\xA2\xCC\xA7\xCC\xA8\xCC\xB4\xCC\xB5\xCC\xB6\xCD\x8F\xCD\x9C\xCD\x9D\xCD\x9E\xCD\x9F\xCD\xA0\xCD\xA2\xCC\xB8\xCC\xB7\xCD\xA1\xD2\x89\x00\xCC\x96\xCC\x97\xCC\x98\xCC\x99\xCC\x9C\xCC\x9D\xCC\x9E\xCC\x9F\xCC\xA0\xCC\xA4\xCC\xA5\xCC\xA6\xCC\xA9\xCC\xAA\xCC\xAB\xCC\xAC\xCC\xAD\xCC\xAE\xCC\xAF\xCC\xB0\xCC\xB1\xCC\xB2\xCC\xB3\xCC\xB9\xCC\xBA\xCC\xBB\xCC\xBC\xCD\x85\xCD\x87\xCD\x88\xCD\x89\xCD\x8D\xCD\x8E\xCD\x93\xCD\x94\xCD\x95\xCD\x96\xCD\x99\xCD\x9A\xCC\xA3\x00 ducked because \x00 jumped because \x00 ran because \x00\x10\x03\x00nil\x00WildCard\x00""arg\x00""Argument\x00""bra\x00""Bracket\x00thg\x00Thing\x00opp\x00Operator\x00""cnj\x00""conj\x00tmp\x00Statement\x00name\x00ques\x00Question\x00""back\x00""Backtick\x00""char\x00""Character\x00sstr\x00Super_String\x00oat\x00Operator_As_Thing\x00sheb\x00Shebang\x00str\x00String\x00sthg\x00Syntactic_Thing\x00scnj\x00Syntactic_conj\x00num\x00Number\x00""emb\x00""Embedded_Value\x00unit\x00type\x00Typecast\x00""arel\x00""After_Relationship\x00""dot\x00""Dot\x00sdot\x00Self_Dot\x00""func\x00""Function\x00""brel\x00""Before_Relationship\x00""adj\x00""Adjective\x00""badj\x00""Backwards_Adjective\x00""acc\x00""Access\x00""arr\x00""Array\x00item\x00list\x00prm\x00Parameter_List\x00""file\x00""File_List\x00quot\x00Quotation\x00""decl\x00""Declaration\x00rel\x00Relationship\x00""erel\x00""Equals_Relationship\x00trel\x00Temporal_Relationship\x00tril\x00Temporal_Relationship2\x00pinn\x00Post_InnerAdj\x00""binn\x00InnerAdj\x00""ask\x00yoda\x00Yoda_Relationship\x00scom\x00Syntactic_Comment\x00msg\x00Message_List\x00todo\x00To_Do_List\x00url\x00URL\x00run\x00""duck\x00xatt\x00XML_Attribute\x00xml\x00XML_Element\x00xpi\x00XML_ProcessingInstruction\x00xcom\x00XML_Comment\x00xcdt\x00XML_CDATA\x00xtxt\x00XML_Text\x00""bin\x00Hex\x00Me says: \x00Rebecca says: \x00 (very quietly)\x00OK note warning warning error critical\x00""child\x00``\x00This class has no saving function for it.\x00: \x00Internal Error\x00true\x00""false\x00 issue\x00 found.\n\x00""Age \x00 out of range on \x00""disconnect\x00Parent \x00""Child  \x00-----------\n\x00talk: \x00, name: \x00ipc is open: \x00ipc not open.\n\x00nil,\x00.app/Contents/MacOS/\x00/\x00\x80\xBF\xC2\xF4\x00""Corrupted jbin\x00Not jbin\x00""Error decoding data: \x00""Error decoding file: \x00, \x00""Can't find file/folder: '\x00' in '\x00'.\x00No name specified for sub-file of directory: \x00/tmp/logs/\x00(nil)\x00 ~ \x00 \xE2\x89\x88 \x00>~ \x00= \x00^\x22\x00Indented blocks must be within @tmp or @item or @decl\x00x\x00K\x00M\x00G\x00Invalid unit\x00 \xC2\xBB\x00 @ \x00 <\xE2\x89\x88 \x00Indents mismatch (\x00 spaces)\x00 \xE2\x80\x9D\x00 /# \x00 #/\x00 \xE2\x80\x9C\x00+\x22\x00=\x22\x00/>\x00</\x00\xC2\xAC \x00""error\x00pos\x00""Can\xE2\x80\x99t parse number '\x00' (found '\x00').\x00\x1B[0;1m\x00\x1B[0;1;31m\x00\x1B[0;1;32m\x00\x1B[0m\x00\x1B[0;1;33m\x00@JBSave\n\x00";

extern "C" void JB_Str__FindGlobals(JB_String*** lub, int** lengths, const char** src) {
	*lub = JB_LUB;
	*lengths = JB_LUBLengths;
	*src = JB_LUBSrc;
}
