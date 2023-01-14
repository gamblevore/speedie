
// Globals put into a separate file to make things faster.
#include "JB_Umbrella.hpp"
#include "JB.h"
#pragma GCC visibility push(hidden)

Message* JB__App__Conf;
JB_String* JB__App__Path;
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
JB_String* JB__Constants_Name;
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

JB_String* JB__zalgo_down;
JB_String* JB__zalgo_mid;
Random JB__zalgo_R;
JB_String* JB__zalgo_up;
SyntaxObj* JB__FuncArray_[64];
JB_String* JB__JbinHeader;
Dictionary* JB__SyxDict_;
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


byte JB__Proc_ClosePipesInstalled;
int JB__Proc_IncID;

byte JB__Proc_SpecialState;
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

JB_String* JB_LUB[341];

int JB_LUBLengths[] = {12, 33, 44, 16, 1, 3, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 2, 3, 1, 5, 6, 6, 1, 4, 1, 4, 1, 2, 1, 2, 8, 4, 6, 2, 7, 3, 17, 1, 2, 2, 2, 3, 1293, 1276, 6, 8, 4, 13, 1, 19, 28, 6, 4, 1, 14, 8, 14, 11, 11, 11, 11, 24, 2, 36, 9, 1, 1, 21, 2, 28, 1, 18, 22, 3, 1, 17, 20, 4, 3, 9, 3, 2, 19, 37, 3, 20, 33, 3, 3, 2, 1, 11, 2, 15, 3, 1, 5, 10, 76, 31, 15, 1, 2, 1, 2, 3, 1, 1, 1, 5, 1, 17, 2, 1, 2, 2, 2, 3, 1, 2, 3, 1, 2, 2, 3, 3, 2, 9, 18, 2, 3, 29, 1, 8, 11, 9, 3, 8, 17, 6, 9, 17, 3, 9, 14, 46, 15, 32, 29, 18, 16, 96, 46, 80, 22, 19, 40, 21, 2, 3, 8, 3, 8, 3, 7, 3, 5, 3, 8, 3, 4, 3, 9, 4, 4, 8, 4, 8, 4, 9, 4, 12, 3, 17, 4, 7, 3, 6, 4, 15, 4, 14, 3, 6, 3, 14, 4, 4, 8, 4, 18, 3, 3, 4, 8, 4, 8, 4, 19, 3, 9, 4, 19, 3, 6, 3, 5, 4, 4, 3, 14, 4, 9, 4, 9, 4, 11, 3, 12, 4, 19, 4, 21, 4, 22, 4, 13, 4, 8, 3, 4, 17, 4, 17, 3, 12, 4, 10, 3, 3, 4, 13, 3, 11, 3, 25, 4, 11, 4, 9, 4, 8, 3, 3, 3, 6, 4, 38, 5, 15, 2, 41, 2, 14, 4, 5, 2, 2, 6, 8, 7, 10, 12, 4, 4, 14, 8, 21, 21, 2, 5, 10, 12, 8, 14, 3, 5, 3, 2, 12, 2, 53, 1, 1, 1, 1, 12, 3, 10, 4, 3, 3, 6, 18, 8, 4, 4, 3, 4, 5, 10, 2, 2, 2, 2, 3, 5, 3, 22, 10, 3, 6, 9, 9, 4, 9, 8, 1, 0};

const char* JB_LUBSrc = "codesign_osx\x00Jeebox: NilObjectError in caller.\x00Jeebox: Too many NilObjectErrors. Silencing.\x00\n(\xC4\xB4\xC3\xAB\xC3\xAA\xC6\x81o\xE2\x93\xA7) \x00\x00\x00\\00\x00\n\x00\\n\x00\r\x00\\r\x00\t\x00\\t\x00\x22\x00\\\x22\x00'\x00\\'\x00\\\x00\\\\\x00&#\x00\\&#\x00&\x00&amp;\x00&apos;\x00&quot;\x00<\x00&lt;\x00>\x00&gt;\x00\x08\x00\\b\x00\x0C\x00\\f\x00""AZaz09__\x00""AZaz\x00""AZaz__\x00\n\r\x00 ,:\t\n\r\\\x00\n\r,\x00 \t\n\r\x0F-^+/\\*:;<>=,\x00$\x00\\$\x00\\0\x00${\x00$\\{\x00//jb self-test file.\n\x22Tests all syntax in small amount of code.\x22\n`Does not make sense in any other way.`\n\nhow %can someone fall so~far #without %realising it\n\nhttp://hello.kitty\n\n+\x22hahaha :3\x22\n\t+\x22""bbbb ()\x22 eeeep!\n\nstory X (\n\t\xE2\x80\x93which dog\n\tx (a < b) c\n\t\t\t-->\n\tsonic@the~hedgedog or @jeebox\n\t\n\t>~slowly i ran home\n\t\n\tA ((B~C)~D E F~G) I #W A t (o:c)\n)\n\n\n\nza a {\n\tart \xE2\x89\x88 brt // abc /deff\\ xyz\n\t1 (crt \xE2\x89\x88 drt) 2\n\t|1| x * y * z = \?()\?\n\t|| a = c or d\n\t(a,)\n\t([] --> a + a, b, d:e)\n\t[|0|d, a+b:c, [c, d]] /* /*\n\t\tnested comments!\n\t\t*/ I found it useful.*/\n\n\t// }\n}\n\nd d // savetext\n\tc c\n\t\ta, bbbbb\n\n#(70 68 61 6e 74617379207374617220706c696e6b20706c6f6e6b20706c696e6b2069747320736f2062656175746966 75 6c)# \n\nfunction name (|x: y + z| a, ||) {\n\t// label : func()\n\t\x22'\\\x22stri\\c3\\b1g test\\\x22'\x22\n\t`\\n\\(&#x134;&#xEB;\\C3\\AA\\C6\\81o&#9447;\\)`\n\t\x22\\n\\(&#x134;&#xEB;\\C3\\AA\\C6\\81o&#9447;\\)\x22\n\t--x-- mod= 'ioi \\'\x22\x22\\'oio'\n\t\n\ty.size(...\?, ..., <(`s`t`r`)>).y(-z)\n\n\tx = \x22{ab${x} ${y}${z}ab}\x22 + `abc`\n\t|(a,)|z += .exit(code: -3)\n\n\tfor (a in b) {\n\t\t$a$ = &b + !c!\n\t}\n\n\tif ('a' & b === !b (|) c) ^ (a ~>= b)\n\t\tif a: return 0xff + 10_miles\n}\n\n\n<\?xml version=\x22""1.0\x22 encoding=\x22UTF-8\x22\?>\n<\?why G A V~E\?>\n<!--comments\?\?\?\?\?<><><>YUSAJKD;-->\n<xml abc=\x22""def\x22 ghi=\x22&apos;abc&apos;\x22>\n\t<K C=\x22""def\x22/>\n\t<text>\n\t\tiiii&amp;jjjj\n\t</text>\n</xml>\n\x00\x10\x03@\x01\xA9\x0ETests all syntax in small amount of code.\xA5\tDoes not make sense in any other way.C\x06how@\x0C\x83\x04""can@&@$\x87\x03someone\x84\x04""fall@\x1A\x82\x03so\x83\x03""far\xC2\x87\x05without@\x0C\x89\x04realising\x82\x03it\xC4""D/http\x8B\x0Ehello.kitty\xC1I\x06hahaha :3@\x01G\x06""bbbb ()A\x15!\x85\x03""eeeep\xC4""E\x06story\x81\x03X@\x1F@\x08\x85\x03which\x83\x03""dog\xC1@&@$\x81\x03x@\x02@$\x81\x04""a\x81\x04<\x81\x04""b\xC2\x81\x03""c\xC1\x83\x10-->@$E\x07sonic@\x1A\x83\x03the\x88\x03hedgedog\xC2\x82\x04or\x86\x07jeebox\xC2@)\x81\x03i@\x1A\x86\x04slowly\x83\x04ran\xC1\x84\x03home\xC1@&@$\x81\x03""A@\x02@$@\x1A@\x02@\x1A\x81\x04""B\x81\x04""C\xC2\x81\x04""D\xC1\x81\x04""E@\x1A\x81\x04""F\x81\x04G\xC3\x81\x03I\xC1\x81\x05W@$\x81\x03""A\x81\x04t@\x1F@\x1E\x81\x03o\x81\x03""c\xC6""B\x06za\x81\x03""a@\x01@\x1B\x83\x03""brt\x83\x03""art\xC1@$\x81\x11""1@\x02@\x1B\x83\x04""drt\x83\x04""crt\xC2\x81\x11""2\xC1@#\x81\x11""1@$\x81\x03x\x81\x04*@$\x81\x03y\x81\x04*@$\x81\x03z\x81\x04=A\x19\?A\x15\?\x80\x1F\xC6@#\x80\x12@$\x81\x03""a\x81\x04=@$\x81\x03""c\x82\x04or\x81\x03""d\xC3@\x1F\x81\x03""a\xC1@\x1F@&\x80\x1D\x83\x10-->@$\x81\x03""a\x81\x04+\x81\x03""a\xC2\x81\x03""b@\x1E\x81\x03""d\x81\x03""e\xC2@\x1D@#\x81\x11""0\x81\x03""d\xC1@\x1E@$\x81\x03""a\x81\x04+\x81\x03""b\xC1\x81\x03""c\xC1@\x1D\x81\x03""c\x81\x03""d\xC4""A\x06""d\x81\x03""d@\x01""A\x06""c\x81\x03""c@\x01\x81\x06""a\x85\x06""bbbbb\xC4\xB0""6phantasy star plink plonk plink its so beautifulH\x06""function\x84\x03name@\x1F@#@\x1E\x81\x03x@$\x81\x03y\x81\x04+\x81\x03z\xC2\x81\x03""a\xC1@#\x80\x12\xC2@\x01\x90\x0E'\x22stri\xC3\xB1g test\x22'\xA7\t\\n\\(&#x134;&#xEB;\\C3\\AA\\C6\\81o&#9447;\\)\x8F\x0E\n(\xC4\xB4\xC3\xAB\xC3\xAA\xC6\x81o\xE2\x93\xA7)@%B\x19--B\x15--\x81\x03x\xC2\x83\x04mod\x8B\nioi '\x22\x22'oio\xC1""A\x16yD\x16size\x81\x03y@ A\x15\?\x83\x0F...\xC1\x83\x0F...\x85\x0Bs`t`r\xC2@ A\x19-\x81\x03z\xC3@$\x81\x03x\x81\x04=@$@\x0E\x83\x12{ab\x81\x03x\x81\x12 \x81\x03y\x81\x03z\x83\x12""ab}\xC1\x81\x04+\x83\tabc\xC2@#@\x1F\x81\x03""a\xC1@%\x81\x03z\x81\x04+D\x17""exit@ @\x1E\x84\x03""code\x82\x11-3\xC5""C\x06""for@\x02@$\x81\x03""a\x82\x04in\x81\x03""b\xC2@\x01@$A\x19$A\x15$\x81\x03""a\xC2\x81\x04=@$A\x19&\x81\x03""b\xC1\x81\x04+A\x19!A\x15!\x81\x03""c\xC6""B\x06if@$@\x02@$\x81\na\x81\x04&@$\x81\x03""b\x83\x04===@$A\x19!\x81\x03""b\xC1\x83\x04(|)\x81\x03""c\xC4\x81\x04^@\x02@$\x81\x03""a\x83\x04~>=\x81\x03""b\xC3@\x01""B\x06if\x81\x03""a@\x01""F\x06return@$\x84\x11""0xff\x81\x04+E\x13miles\x83\x11""10_\xC9@2C\x06xml@$\x87\x03version\x81\x04=@%\x83\x0E""1.0\x88\x04""encoding\x85\x0EUTF-8\xC4@2C\x06why@$\x81\x03G\x81\x04""A@\x1A\x81\x03V\x81\x03""E\xC4\x9B""3comments\?\?\?\?\?<><><>YUSAJKD;C1xml@\x01""C0abc\x83""5def\xC1""C0ghi\x85""5'abc'\xC2""A1K@\x01""A0C\x83""5def\xC3""D1text\x80\x01\x89""5iiii&jjjj\x00normal\x00""entities\x00jbin\x00Indent is odd\x00|\x00""Close-tag malformed\x00Open/close tags mismatch! </\x00> vs <\x00<\xE2\x89\x88\x00(\x00Missing close \x00Nested '\x00' not allowed.\x00Unexpected \x00 but found \x00""end-of-line\x00""end-of-data\x00""Found illegal-character \x00""0x\x00""Expected a letter (aA-zZ, '_', etc).\x00Missing '\x00]\x00}\x00String did not close.\x00)#\x00""Binary section didn't close!\x00)\x00""Char didn't close!\x00""Comment did not close.\x00\xE2\x80\x93\x00 \x00Unexpected syntax\x00""Element didn't close\x00<!--\x00-->\x00<![CDATA[\x00]]>\x00\xC2\xBB\x00Needs a space here.\x00""Can\xE2\x80\x99t have '=' after this operator.\x00\xE2\x80\x9D\x00String didn't close!\x00""Embedded expression didn't close.\x00<(`\x00`)>\x00#/\x00:\x00""Bad Doctype\x00\?>\x00Indent too low.\x00\r \n\x00,\x00line \x00""0123456789\x00= == === < > <= <== >= >== <> ~<> != !== <=> ~>= ~<= ~> ~< <~ ~= ~!= ~<=> :=\x00* / \\ + - ^ & >> << >>> <<< (|)\x00++ -- $ ! \? ...\x00[\x00\xC2\xAB\x00.\x00..\x00://\x00+\x00@\x00~\x00- * ~\x00{\x00--> <-- <--> <\xE2\x89\x88\x00/#\x00%\x00#!\x00//\x00/*\x00...\x00`\x00#(\x00\xE2\x89\x88\x00#\x00>~\x00\xC2\xAC\x00\xE2\x80\x9C\x00\xE2\x88\x86\x00<\?\x00<!DOCTYPE\x00] ) } #/ \xC2\xBB \xE2\x80\x9D \?>\x00::\x00!~=\x00""Can't have tabs after spaces.\x00=\x00temporal\x00""declaration\x00statement\x00':'\x00operator\x00temporal-operator\x00""a name\x00something\x00illegal-character\x00 / \x00""Expected \x00something else\x00Must be a proper name (a-z or unicode-letters)\x00""Expected a rel.\x00""Can\xE2\x80\x99t use temporals like this.\x00""Attribute value didn't close.\x00""Element malformed.\x00Tag didn't close\x00\xCC\x8D\xCC\x8E\xCC\x84\xCC\x85\xCC\xBF\xCC\x91\xCC\x86\xCC\x90\xCD\x92\xCD\x97\xCD\x91\xCC\x87\xCC\x88\xCC\x8A\xCD\x82\xCD\x83\xCD\x84\xCD\x8A\xCD\x8B\xCD\x8C\xCC\x83\xCC\x82\xCC\x8C\xCD\x90\xCC\x80\xCC\x81\xCC\x8B\xCC\x8F\xCC\x92\xCC\x93\xCC\x94\xCC\xBD\xCC\x89\xCD\xA3\xCD\xA4\xCD\xA5\xCD\xA6\xCD\xA7\xCD\xA8\xCD\xA9\xCD\xAA\xCD\xAB\xCD\xAC\xCD\xAD\xCD\xAE\xCD\x9B\xCD\x86\xCC\x9A\x00\xCC\x95\xCC\x9B\xCD\x80\xCD\x81\xCD\x98\xCC\xA1\xCC\xA2\xCC\xA7\xCC\xA8\xCC\xB4\xCC\xB5\xCC\xB6\xCD\x8F\xCD\x9C\xCD\x9D\xCD\x9E\xCD\x9F\xCD\xA0\xCD\xA2\xCC\xB8\xCC\xB7\xCD\xA1\xD2\x89\x00\xCC\x96\xCC\x97\xCC\x98\xCC\x99\xCC\x9C\xCC\x9D\xCC\x9E\xCC\x9F\xCC\xA0\xCC\xA4\xCC\xA5\xCC\xA6\xCC\xA9\xCC\xAA\xCC\xAB\xCC\xAC\xCC\xAD\xCC\xAE\xCC\xAF\xCC\xB0\xCC\xB1\xCC\xB2\xCC\xB3\xCC\xB9\xCC\xBA\xCC\xBB\xCC\xBC\xCD\x85\xCD\x87\xCD\x88\xCD\x89\xCD\x8D\xCD\x8E\xCD\x93\xCD\x94\xCD\x95\xCD\x96\xCD\x99\xCD\x9A\xCC\xA3\x00parent of expected is \x00parent of found is \x00\\n\\(&#x134;&#xEB;\\C3\\AA\\C6\\81o&#9447;\\) \x00 loaded successfully\n\x00\x10\x03\x00nil\x00WildCard\x00""arg\x00""Argument\x00""bra\x00""Bracket\x00thg\x00Thing\x00opp\x00Operator\x00""cnj\x00""conj\x00tmp\x00Statement\x00name\x00ques\x00Question\x00""back\x00""Backtick\x00""char\x00""Character\x00sstr\x00Super_String\x00oat\x00Operator_As_Thing\x00sheb\x00Shebang\x00str\x00String\x00sthg\x00Syntactic_Thing\x00scnj\x00Syntactic_conj\x00num\x00Number\x00""emb\x00""Embedded_Value\x00unit\x00type\x00Typecast\x00""arel\x00""After_Relationship\x00""dot\x00""Dot\x00sdot\x00Self_Dot\x00""func\x00""Function\x00""brel\x00""Before_Relationship\x00""adj\x00""Adjective\x00""badj\x00""Backwards_Adjective\x00""acc\x00""Access\x00""arr\x00""Array\x00item\x00list\x00prm\x00Parameter_List\x00""file\x00""File_List\x00quot\x00Quotation\x00""decl\x00""Declaration\x00rel\x00Relationship\x00""erel\x00""Equals_Relationship\x00trel\x00Temporal_Relationship\x00tril\x00Temporal_Relationship2\x00pinn\x00Post_InnerAdj\x00""binn\x00InnerAdj\x00""ask\x00yoda\x00Yoda_Relationship\x00scom\x00Syntactic_Comment\x00msg\x00Message_List\x00todo\x00To_Do_List\x00url\x00URL\x00xatt\x00XML_Attribute\x00xml\x00XML_Element\x00xpi\x00XML_ProcessingInstruction\x00xcom\x00XML_Comment\x00xcdt\x00XML_CDATA\x00xtxt\x00XML_Text\x00""bin\x00Hex\x00""abc\x00\x00\x00\x00\x00\x00\x00\x00""abc \x00OK note warning warning error critical\x00""child\x00Unknown syntax \x00``\x00This class has no saving function for it.\x00: \x00Internal Error\x00true\x00""false\x00 '\x00' \x00 issue\x00 found.\n\x00Leaked \x00 bytes in \x00. New Count \x00nil,\x00\x80\xBF\xC2\xF4\x00""Corrupted jbin\x00Not jbin\x00""Error decoding file: \x00""Error decoding data: \x00, \x00(nil)\x00""Expected @\x00 but found @\x00Missing \x00Missing syntax\x00 ~ \x00 \xE2\x89\x88 \x00>~ \x00= \x00, but found \x00^\x22\x00Indented blocks must be within @tmp or @item or @decl\x00x\x00K\x00M\x00G\x00Invalid unit\x00: '\x00 at byte: \x00 in \x00 \xC2\xBB\x00 @ \x00 <\xE2\x89\x88 \x00Indents mismatch (\x00 spaces)\x00 \xE2\x80\x9D\x00 /# \x00 #/\x00 \xE2\x80\x9C\x00Test \x00: Failed\n\n\x00+\x22\x00=\x22\x00/>\x00</\x00\xC2\xAC \x00""error\x00pos\x00""Can\xE2\x80\x99t parse number '\x00' (found '\x00').\x00\x1B[0;1m\x00\x1B[0;1;31m\x00\x1B[0;1;32m\x00\x1B[0m\x00\x1B[0;1;33m\x00@JBSave\n\x00""a\x00";

extern "C" void JB_Str__FindGlobals(JB_String*** lub, int** lengths, const char** src) {
	*lub = JB_LUB;
	*lengths = JB_LUBLengths;
	*src = JB_LUBSrc;
}
