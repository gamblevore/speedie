
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
#include "JB_Umbrella.hpp"
#include "JB.h"
#pragma GCC visibility push(hidden) // hidden

extern "C" {

extern JB_StringC* JB_LUB[557];

extern Object_Behaviour JB_Object_FuncTable_;

JB_String* JB_App__AppName() {
	JB_String* _tmPf0 = JB_App__AppPath();
	JB_Incr(_tmPf0);
	JB_String* _tmPf1 = JB_Str_Name(_tmPf0);
	JB_Incr(_tmPf1);
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

JB_String* JB_App__AppPath() {
	if (JB_Platform__OSX()) {
		JB_String* _tmPf0 = JB_App__OrigPath();
		JB_Incr(_tmPf0);
		JB_String* _tmPf1 = JB_Str_BackToApp(_tmPf0);
		JB_Incr(_tmPf1);
		JB_Decr(_tmPf0);
		JB_SafeDecr(_tmPf1);
		return _tmPf1;
	}
	return JB_App__OrigPath();
}

int JB_App__Init_() {
	{
		JB_SetRef(JB__App_Usage, JB_LUB[0]);
		JB_SetRef(JB__App__Path, JB_LUB[0]);
	}
	;
	return 0;
}

JB_String* JB_App__OrigPath() {
	//visible;
	JB_String* P = JB__App__Path;
	JB_Incr(P);
	if (JB_Str_Exists(P)) {
		JB_SafeDecr(P);
		return P;
	}
	Dictionary* _tmPf0 = JB_App__Env();
	JB_Incr(_tmPf0);
	JB_SetRef(P, ((JB_String*)JB_Dict_Value0(_tmPf0, JB_LUB[31])));
	JB_Decr(_tmPf0);
	if (JB_Str_Exists(P)) {
		JB_SetRef(JB__App__Path, P);
		JB_SafeDecr(P);
		return P;
	}
	JB_SetRef(P, JB_App__Path());
	if (JB_Str_Exists(P)) {
		JB_SetRef(JB__App__Path, P);
		JB_SafeDecr(P);
		return P;
	}
	JB_Decr(P);
	return JB_LUB[0];
}

void JB_PrintStackTrace() {
	//visible;
	JB_String* _tmPf0 = JB_App__StackTrace(2, nil);
	JB_Incr(_tmPf0);
	JB_Print(_tmPf0);
	JB_Decr(_tmPf0);
}

JB_String* JB_App__StackTrace(int Skip, FastString* Fs_in) {
	FastString* Fs = JB_FS__FastNew(Fs_in);
	JB_Incr(Fs);
	void* Arr[128] = {
	};
	int Size = (128);
	_cstring* Strs = JB_App__BackTrace((&Arr[0]), (&Size));
	{
		IntRange _LoopSrcf2 = JB_int_OperatorTo(Skip, Size - 1);
		int __Endf0 = _LoopSrcf2[1];
		int I = _LoopSrcf2[0];
		while (I < __Endf0) {
			JB_FS_AppendCString(Fs, Strs[I]);
			JB_FS_AppendByte(Fs, '\n');
			(++I);
		};
	}
	;
	JB_Free(Strs);
	JB_String* _tmPf3 = JB_FS_SmartResult(Fs, Fs_in);
	JB_Incr(_tmPf3);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf3);
	return _tmPf3;
}

JB_String* JB_App__SyntaxAccess(JB_String* Name) {
	JB_String* Rz = JB_LUB[0];
	{
		Array* _LoopSrcf2 = JB_App__Args();
		int _if0 = 0;
		while (true) {
			JB_String* R = ((JB_String*)JB_Array_Value(_LoopSrcf2, _if0));
			if (R == nil) {
				break;
			}
			if (JB_Str_Equals(JB_Str_ArgName(R), Name, true)) {
				Rz = JB_Str_ArgValue(R);
				break;
			}
			(++_if0);
		};
	}
	;
	return Rz;
}


int JB_ErrorColors__Init_() {
	{
	}
	;
	return 0;
}



Message* JB_API__Errors() {
	Message* Rz = nil;
	if (JB_Rec_OK(JB_StdErr)) {
		return nil;
	}
	Rz = JB_StdErr->Errors;
	{
		Message* Err = ((Message*)JB_Ring_First(Rz));
		while (Err) {
			Message* _Nf1 = ((Message*)JB_Ring_NextSib(Err));
			JB_SetRef(Err->Name, JB_Msg_Render(Err, nil));
			Err = _Nf1;
		};
		;
	}
	;
	JB_Rec_Clear(JB_StdErr);
	return Rz;
}

int JB_API__Init(int Flags) {
	if (JB_StdErr != nil) {
		return 0;
	}
	int ErrCode = JB_SP_Init(nil, false);
	if (ErrCode) {
		return ErrCode;
	}
	JB_String* Msg = JB_Constants__TestJB();
	JB_Incr(Msg);
	if (Flags & 1) {
		JB_PrintLine(Msg);
	}
	JB_Decr(Msg);
	if (!JB_Rec_OK(JB_StdErr)) {
		JB_Error* F = ((JB_Error*)JB_Ring_First(JB_StdErr->Errors));
		JB_Incr(F);
		if (F) {
			JB_Print(F->Name);
		}
		JB_Decr(F);
		JB_Rec_Clear(JB_StdErr);
		return -1000;
	}
	return 0;
}

int JB_API__Init_() {
	{
	}
	;
	return 0;
}

void JB_API__NilCallBack(JB_String* ErrorMessage) {
	JB_PrintLine(ErrorMessage);
}

bool JB_API__NilHandler() {
	if (!JB_Rec_OK(JB_StdErr)) {
		return nil;
	}
	if ((++JB__API_NilHappened_) < 16) {
		JB_API__NilCallBack(JB_LUB[74]);
	}
	 else if (JB__API_NilHappened_ == 16) {
		JB_API__NilCallBack(JB_LUB[75]);
	}
	return false;
}

Message* JB_API__Parse(JB_String* S, JB_String* Path) {
	if (!JB_Safe_SyntaxCast(S)) {
		return nil;
	}
	JB_MemoryLayer* L = JB_ClassData_CreateUseLayer((&MessageData), Path, S);
	JB_Incr(L);
	if ((L)) {
		Message* Result = JB_Str_Parse(S, kJB_SyxArg, true);
		JB_Incr(Result);
		JB_ClassData_Restore((&MessageData));
		JB_Decr(L);
		JB_SafeDecr(Result);
		return Result;
	}
	JB_Decr(L);
	return nil;
}


void JB_Constants__AddEscape(uint /*byte*/ I, FastString* Fs) {
	JB_String* F = JB_Str__Byte(I);
	if (!((!JB_Str_Exists(((JB_StringC*)JB_Dict_Value0(JB__Constants_EscapeStr, F)))) or (!JB_Str_Exists(((JB_String*)JB_Dict_Value0(JB__Constants_EscapeChr, F)))))) {
		return;
	}
	JB_FS_AppendByte(Fs, '\\');
	JB_FS_AppendHex(Fs, I, 2);
	JB_String* T = JB_FS_GetResult(Fs);
	if (!JB_Str_Exists(((JB_StringC*)JB_Dict_Value0(JB__Constants_EscapeStr, F)))) {
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, F, JB_Str_CastZero(T)));
	}
	if (!JB_Str_Exists(((JB_String*)JB_Dict_Value0(JB__Constants_EscapeChr, F)))) {
		(JB_Dict_ValueSet(JB__Constants_EscapeChr, F, T));
	}
}

int JB_Constants__Init_() {
	{
		JB_SetRef(JB__Constants__SyxDict, JB_Dict_Constructor(nil));
		JB_SetRef(JB__Constants_EscapeStr, (JB_Dict_Constructor(nil)));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[88], JB_LUB[89]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[42], JB_LUB[41]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[90], JB_LUB[91]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[45], JB_LUB[92]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[82], JB_LUB[93]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[85], JB_LUB[94]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[84], JB_LUB[95]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[96], JB_LUB[97]));
		JB_SetRef(JB__Constants_XML_EscapeStr, (JB_Dict_Constructor(nil)));
		(JB_Dict_ValueSet(JB__Constants_XML_EscapeStr, JB_LUB[98], JB_LUB[99]));
		(JB_Dict_ValueSet(JB__Constants_XML_EscapeStr, JB_LUB[85], JB_LUB[100]));
		(JB_Dict_ValueSet(JB__Constants_XML_EscapeStr, JB_LUB[82], JB_LUB[101]));
		(JB_Dict_ValueSet(JB__Constants_XML_EscapeStr, JB_LUB[102], JB_LUB[103]));
		(JB_Dict_ValueSet(JB__Constants_XML_EscapeStr, JB_LUB[104], JB_LUB[105]));
		JB_SetRef(JB__Constants_JS_EscapeStr, (JB_Dict_Constructor(nil)));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[106], JB_LUB[107]));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[108], JB_LUB[109]));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[42], JB_LUB[41]));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[90], JB_LUB[91]));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[45], JB_LUB[92]));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[82], JB_LUB[93]));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[84], JB_LUB[95]));
		JB_SetRef(JB__Constants_CSWordMiddle, JB_Str_UniCS(JB_LUB[110]));
		JB_SetRef(JB__Constants_CSLettersOnly, JB_Str_UniCS(JB_LUB[111]));
		JB_SetRef(JB__Constants_CSWordStart, JB_Str_UniCS(JB_LUB[112]));
		JB_SetRef(JB__Constants_XMLWordMiddle, JB_Str_UniCS(JB_LUB[113]));
		JB_SetRef(JB__Constants_CSNum, JB__Constants_CSWordMiddle);
		JB_SetRef(JB__Constants_CSLine, JB_Str_CharSetWithBool(JB_LUB[114], false));
		JB_SetRef(JB__Constants_CSAfterDot, JB_Str_CharSetWithBool(JB_LUB[115], false));
		JB_SetRef(JB__Constants_CSAfterStatement, JB_Str_CharSetWithBool(JB_LUB[116], false));
		JB_SetRef(JB__Constants_CSLineBlack, JB_Str_CharSetWithBool(JB_LUB[117], false));
		JB_SetRef(JB__Constants_CSWrapSplit, JB_Str_CharSetWithBool(JB_LUB[118], false));
		JB_SetRef(JB__Constants_FFUUU, JB_LUB[119]);
	}
	;
	return 0;
}

int JB_Constants__InitCode_() {
	{
	}
	;
	JB_Constants__InitConstants();
	return 0;
}

void JB_Constants__InitConstants() {
	JB_Array_Constructor0(nil);
	JB_SetRef(JB__Constants_EscapeChr, JB_Dict__Copy(JB__Constants_EscapeStr));
	(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[80], JB_LUB[81]));
	JB_SetRef(JB__Constants_UnEscapeStr, JB_Dict__Reverse(JB__Constants_EscapeStr));
	JB_SetRef(JB__Constants_JS_UnEscapeStr, JB_Dict__Reverse(JB__Constants_JS_EscapeStr));
	JB_SetRef(JB__Constants_XML_UnEscapeStr, JB_Dict__Reverse(JB__Constants_XML_EscapeStr));
	(JB_Dict_ValueSet(JB__Constants_EscapeChr, JB_LUB[82], ((JB_String*)nil)));
	(JB_Dict_ValueSet(JB__Constants_EscapeChr, JB_LUB[80], ((JB_String*)nil)));
	(JB_Dict_ValueSet(JB__Constants_UnEscapeStr, JB_LUB[83], ((JB_String*)nil)));
	(JB_Dict_ValueSet(JB__Constants_UnEscapeStr, JB_LUB[84], JB_LUB[0]));
	(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[85], ((JB_StringC*)nil)));
	FastString* Tfs = JB_FS_Constructor(nil);
	JB_Incr(Tfs);
	{
		int I = 0;
		while (I < 256) {
			if ((I <= 31) or (((I == 127) or ((I == 192) or (I == 193))) or (I >= 245))) {
				JB_Constants__AddEscape(I, Tfs);
			}
			(++I);
		};
	}
	;
	JB_Decr(Tfs);
	JB_MSR_EscapeCodeSet(JB__Constants_UnEscapeStr, true);
	JB_MSR_DecodeEntitySet(JB__Constants_UnEscapeStr, true);
	JB_MSR_DecodeEntitySet(JB__Constants_XML_UnEscapeStr, true);
	(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[86], JB_LUB[87]));
}

JB_String* JB_Constants__TestJB() {
	FastString* Fs = JB_FS_Constructor(nil);
	JB_Incr(Fs);
	{
		int C = 0;
		while (C < 256) {
			JB_FS_AppendByte(Fs, ((byte)C));
			(++C);
		};
	}
	;
	JB_String* Str = JB_FS_GetResult(Fs);
	JB_Incr(Str);
	JB_Decr(Fs);
	if (!JB_Str_EscapeTest(Str)) {
		JB_Decr(Str);
		return JB_LUB[0];
	}
	JB_Decr(Str);
	JB_String* Natural_input = JB_LUB[543];
	JB_Incr(Natural_input);
	JB_String* Jbin_input = JB_LUB[543];
	JB_Incr(Jbin_input);
	JB_FreeIfDead(JB_Str_UpperCase(JB_LUB[544]));
	LeakTester* LKT = JB_Lk_Constructor(nil, JB_LUB[545]);
	JB_Incr(LKT);
	JB_FreeIfDead(JB_EntityTest());
	JB_Lk_FinalTest(LKT);
	JB_Decr(LKT);
	if (!JB_Rec_OK(JB_StdErr)) {
		JB_Decr(Jbin_input);
		JB_Decr(Natural_input);
		return JB_LUB[0];
	}
	Message* Root = JB_Str_Parse(Natural_input, kJB_SyxArg, true);
	JB_Incr(Root);
	JB_Decr(Natural_input);
	if (!Root) {
		JB_Decr(Root);
		JB_Decr(Jbin_input);
		return JB_LUB[0];
	}
	JB_Msg_jbinTest(Root);
	if (((JB_String*)JB_Str_Exists(Jbin_input))) {
		Message* _tmPf1 = JB_Msg_Copy(Root, nil);
		JB_Incr(_tmPf1);
		JB_Msg__TreeCompare(Root, _tmPf1, false);
		JB_Decr(_tmPf1);
		Message* _tmPf2 = JB_Str_Parse(Jbin_input, kJB_SyxArg, true);
		JB_Incr(_tmPf2);
		JB_Msg__TreeCompare(Root, _tmPf2, false);
		JB_String* _tmPf3 = JB_Msg_Render(Root, nil);
		JB_Incr(_tmPf3);
		JB_Msg_Test(Root, _tmPf3, JB_LUB[544]);
		JB_Decr(_tmPf3);
		JB_String* _tmPf4 = JB_Msg_RenderJbin(Root, JB_LUB[0], nil);
		JB_Incr(_tmPf4);
		JB_Msg_Test(Root, _tmPf4, JB_LUB[546]);
		JB_Decr(_tmPf4);
		JB_Decr(_tmPf2);
	}
	JB_Decr(Jbin_input);
	if (!JB_Rec_OK(JB_StdErr)) {
		JB_Decr(Root);
		return JB_LUB[0];
	}
	JB_Decr(Root);
	return JB_EntityTest();
}





int JB_Platform__Init_() {
	{
	}
	;
	return 0;
}

void JB_Platform__Log(JB_String* S) {
	//visible;
	JB_File* L = ({
		JB_File* _X = JB__Platform_Logger_;
		if (!_X) {
			_X = JB_Platform__OpenLog();
			JB_SetRef(JB__Platform_Logger_, _X);
		}
		 _X;
	});
	JB_File_SyntaxAppend(L, S);
	JB_File_SyntaxAppend(L, JB_LUB[42]);
}

JB_File* JB_Platform__OpenLog() {
	JB_File* Rz = nil;
	JB_Incr(Rz);
	JB_File* _tmPf0 = JB_File__Logs();
	JB_Incr(_tmPf0);
	JB_String* _tmPf2 = JB_App__AppName();
	JB_Incr(_tmPf2);
	JB_String* _tmPf1 = JB_Str_OperatorPlus(_tmPf2, JB_LUB[477]);
	JB_Incr(_tmPf1);
	JB_Decr(_tmPf2);
	JB_SetRef(Rz, JB_File_SyntaxAccess(_tmPf0, _tmPf1));
	JB_Decr(_tmPf0);
	JB_Decr(_tmPf1);
	JB_SetRef(JB__Platform_Logger_, Rz);
	JB_File_OpenBlank(Rz);
	JB_SafeDecr(Rz);
	return Rz;
}




ErrorInt JB_Main() {
	//visible;
	return 0;
}


bool JB_CompareError(Message* Expected, Message* Found) {
	JB_Incr(Found);
	FastString* Fs = JB_FS_Constructor(nil);
	JB_Incr(Fs);
	//;
	JB_FS_AppendString(Fs, JB_LUB[199]);
	JB_String* _tmPf3 = JB_Msg_Locate(Expected);
	JB_Incr(_tmPf3);
	JB_FS_AppendString(Fs, _tmPf3);
	JB_Decr(_tmPf3);
	JB_FS_AppendString(Fs, JB_LUB[369]);
	JB_String* _tmPf4 = JB_Msg_Locate(Found);
	JB_Incr(_tmPf4);
	JB_FS_AppendString(Fs, _tmPf4);
	JB_Decr(_tmPf4);
	JB_FS_AppendByte(Fs, '\n');
	//;
	//;
	JB_FS_AppendString(Fs, JB_LUB[398]);
	JB_String* _tmPf5 = JB_Msg_plocate(Expected);
	JB_Incr(_tmPf5);
	JB_FS_AppendString(Fs, _tmPf5);
	JB_Decr(_tmPf5);
	JB_FS_AppendByte(Fs, '\n');
	//;
	if (Found) {
		//;
		JB_FS_AppendString(Fs, JB_LUB[399]);
		JB_String* _tmPf6 = JB_Msg_plocate(Found);
		JB_Incr(_tmPf6);
		JB_FS_AppendString(Fs, _tmPf6);
		JB_Decr(_tmPf6);
		JB_FS_AppendByte(Fs, '\n');
		//;
	}
	 else {
		JB_SetRef(Found, Expected);
	}
	JB_String* _tmPf7 = JB_FS_SyntaxCast(Fs);
	JB_Incr(_tmPf7);
	JB_Decr(Fs);
	JB_PrintLine(_tmPf7);
	JB_Decr(_tmPf7);
	JB_Msg_Fail(Found, nil);
	JB_Decr(Found);
	return false;
}

JB_String* JB_EntityTest() {
	JB_String* Replicate = JB_LUB[40];
	JB_Incr(Replicate);
	Dictionary* Repl = JB_Dict_Constructor(nil);
	JB_Incr(Repl);
	(JB_Dict_ValueSet(Repl, JB_LUB[41], JB_LUB[42]));
	JB_MSR_DecodeEntitySet(Repl, true);
	JB_MSR_EscapeCodeSet(Repl, true);
	JB_String* S3 = JB_Str_Unescape(Replicate);
	JB_Incr(S3);
	JB_Decr(S3);
	JB_SetRef(Replicate, JB_Str_MultiReplaceAll(Replicate, Repl, JB_StdErr));
	JB_Decr(Repl);
	JB_String* Jb = JB_LUB[43];
	JB_Incr(Jb);
	JB_Decr(Jb);
	JB_String* _tmPf0 = JB_Str_LowerCase(Replicate);
	JB_Incr(_tmPf0);
	JB_Decr(Replicate);
	JB_String* _tmPf1 = JB_Str_OperatorPlus(_tmPf0, JB_LUB[44]);
	JB_Incr(_tmPf1);
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

int JB_Init_() {
	{
		JB_SetRef(JB___AppConfString, JB_LUB[366]);
		JB_SetRef(JB_StdErr, JB_Rec_Constructor(nil));
		JB_SetRef(JB__JbinHeader, JB_LUB[367]);
		JB_SetRef(JB__jBinNotJbin, JB_LUB[368]);
	}
	;
	//// App;
	JB_App__Init_();
	//// Jeebox;
	JB_Constants__Init_();
	//// parser;
	JB_Tk__Init_();
	//// zalgo;
	JB_zalgo__Init_();
	//// ErrorSeverity;
	JB_ErrorSeverity__Init_();
	//// CompressionStats;
	JB_MzSt__Init_();
	//// Random;
	JB_Rnd__Init_();
	//// FlowControl;
	JB_Flow__Init_();
	//// Macro;
	JB_Macro__Init_();
	//// File;
	JB_File__Init_();
	//// Error;
	JB_Err__Init_();
	JB_InitCode_();
	return 0;
}

int JB_SP_AppInit() {
	return JB_SP_AppInitSub_();
}

int JB_SP_AppInitSub_() {
	return 0;
}

int JB_InitCode_() {
	{
	}
	;
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Nil__)), JB_LUB[46], JB_LUB[261], 0);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Arg__)), JB_LUB[262], JB_LUB[263], 1);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Emb__)), JB_LUB[264], JB_LUB[265], 2);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Type__)), JB_LUB[266], JB_LUB[267], 3);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Decl__)), JB_LUB[268], JB_LUB[189], 4);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Tmp__)), JB_LUB[269], JB_LUB[190], 5);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Oat__)), JB_LUB[270], JB_LUB[271], 6);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Ques__)), JB_LUB[272], JB_LUB[273], 7);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Cnj__)), JB_LUB[274], JB_LUB[275], 8);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Opp__)), JB_LUB[276], JB_LUB[193], 9);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Thg__)), JB_LUB[277], JB_LUB[278], 10);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Sheb__)), JB_LUB[279], JB_LUB[280], 11);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_SCnj__)), JB_LUB[281], JB_LUB[282], 12);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_SThg__)), JB_LUB[283], JB_LUB[284], 13);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Num__)), JB_LUB[285], JB_LUB[286], 14);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_SStr__)), JB_LUB[287], JB_LUB[288], 15);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Back__)), JB_LUB[289], JB_LUB[290], 16);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Char__)), JB_LUB[66], JB_LUB[291], 17);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Bin__)), JB_LUB[292], JB_LUB[293], 18);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Str__)), JB_LUB[294], JB_LUB[295], 19);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Unit__)), JB_LUB[296], JB_LUB[0], 20);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_ARel__)), JB_LUB[297], JB_LUB[298], 21);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Name__)), JB_LUB[299], JB_LUB[0], 22);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Dot__)), JB_LUB[300], JB_LUB[301], 23);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_SDot__)), JB_LUB[302], JB_LUB[303], 24);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Func__)), JB_LUB[304], JB_LUB[305], 25);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_BRel__)), JB_LUB[306], JB_LUB[307], 26);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Adj__)), JB_LUB[308], JB_LUB[309], 27);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Badj__)), JB_LUB[310], JB_LUB[311], 28);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Acc__)), JB_LUB[312], JB_LUB[313], 29);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Item__)), JB_LUB[314], JB_LUB[0], 30);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Bra__)), JB_LUB[315], JB_LUB[316], 31);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_List__)), JB_LUB[317], JB_LUB[0], 32);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Prm__)), JB_LUB[318], JB_LUB[319], 33);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Arr__)), JB_LUB[320], JB_LUB[321], 34);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_File__)), JB_LUB[210], JB_LUB[322], 35);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Quot__)), JB_LUB[323], JB_LUB[324], 36);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Rel__)), JB_LUB[325], JB_LUB[326], 37);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_ERel__)), JB_LUB[327], JB_LUB[328], 38);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_TRel__)), JB_LUB[329], JB_LUB[330], 39);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Tril__)), JB_LUB[331], JB_LUB[332], 40);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_pinn__)), JB_LUB[333], JB_LUB[334], 41);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_binn__)), JB_LUB[335], JB_LUB[336], 42);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Ask__)), JB_LUB[337], JB_LUB[0], 43);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Yoda__)), JB_LUB[338], JB_LUB[339], 44);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_SCom__)), JB_LUB[340], JB_LUB[341], 45);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Msg__)), JB_LUB[342], JB_LUB[343], 46);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_Todo__)), JB_LUB[344], JB_LUB[345], 47);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_url__)), JB_LUB[346], JB_LUB[347], 48);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_XAtt__)), JB_LUB[348], JB_LUB[349], 49);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_XML__)), JB_LUB[350], JB_LUB[351], 50);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_XPI__)), JB_LUB[352], JB_LUB[353], 51);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_XCom__)), JB_LUB[354], JB_LUB[355], 52);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_XCDT__)), JB_LUB[356], JB_LUB[357], 53);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_XTxt__)), JB_LUB[358], JB_LUB[359], 54);
	JB_Syx__StdNew(((FP_fpMsgRender)(JB_Msg_max__)), JB_LUB[360], JB_LUB[361], 55);
	//// Jeebox;
	JB_Constants__InitCode_();
	//// parser;
	JB_Tk__InitCode_();
	//// Random;
	JB_Rnd__InitCode_();
	//// FlowControl;
	JB_Flow__InitCode_();
	return 0;
}

void JB_Print(JB_String* Data) {
	JB_Str_Print(Data);
}

void JB_PrintLine(JB_String* Data) {
	JB_Str_PrintLine(Data);
}


Message* JB_Tk__AddToOutput(Message* Output, Message* Curr, Message* Prev, int Pos) {
	if (Prev) {
		int Extra = JB_Msg_PrevIndentCheck(Curr, Prev);
		if (Extra < 0) {
			return JB_Tk__LoweredIndent(Output, Curr);
		}
		if (Extra > 0) {
			if ((Extra == 2) and (JB_int_OperatorIsa(((int)Prev->Indent), 4))) {
				return JB_Tk__ElseIfAdder(Prev, Curr);
			}
			return JB_Msg_GoIntoInvisArg(Curr, Prev, Pos);
		}
	}
	JB_Tree_SyntaxAppend(Output, Curr);
	return Output;
}

void JB_Tk__AddXMLText(Message* XML, JB_String* S, int Start, int I) {
	Ind A = JB_Str_OutWhite(S, Start, JB_int__Max());
	if (A >= I) {
		return;
	}
	JB_String* Str = JB_Str_Range(S, Start, I);
	JB_Incr(Str);
	JB_String* Str2 = JB_Str_Trim(Str, nil);
	JB_Incr(Str2);
	JB_Decr(Str);
	JB_String* Str3 = JB_Str_MultiReplaceAll(Str2, JB__Constants_XML_UnEscapeStr, JB_StdErr);
	JB_Incr(Str3);
	JB_Decr(Str2);
	JB_FreeIfDead(JB_Tk__NewParentName(XML, kJB_SyxXTxt, Start, Str3));
	JB_Decr(Str3);
}

Message* JB_Tk__BarThings(int Start, Syntax Syx) {
	Message* Rz = nil;
	JB_Incr(Rz);
	if (JB_Tk__NextByte() == '=') {
		JB_Decr(Rz);
		return nil;
	}
	JB__Tk__StopBars = (kJB__Tk_kTemporalSyx | kJB__Tk_kFuncAfterBar);
	Message* Item = JB_Tk__ProcessThingNoBar(kJB__Tk_kOppNoBar, false);
	JB_Incr(Item);
	if (Item) {
		JB_SetRef(Item, JB_Tk__ParseItem(Item, 0, kJB__Tk_kOppNoBar));
	}
	 else {
		JB_SetRef(Item, JB_Tk__NewEmpty(nil, kJB_SyxEmb, Start, Start));
	}
	JB__Tk__StopBars = 0;
	if (!JB_Tk__ExpectEndChar(JB_Tk__NextStart(), JB_LUB[490], true)) {
		JB_Decr(Item);
		JB_Decr(Rz);
		return nil;
	}
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, Syx, Start, JB_LUB[0]));
	JB_Tree_SyntaxAppend(Rz, Item);
	JB_Decr(Item);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__BeforeRelSub(int Start, bool Mode) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__NewParent(nil, kJB_SyxBRel, Start, JB_Tk__NextStart()));
	Message* _tmPf0 = JB_Tk__ProcessThing(0, Mode);
	JB_Incr(_tmPf0);
	if (!_tmPf0) {
		JB_Decr(_tmPf0);
		JB_Decr(Rz);
		return nil;
	}
	JB_Tree_SyntaxAppend(Rz, _tmPf0);
	JB_Decr(_tmPf0);
	JB_SafeDecr(Rz);
	return Rz;
}

bool JB_Tk__CanDot() {
	return JB_CS_HasChar(JB__Constants_CSAfterDot, JB_Tk__NextByte());
}

bool JB_Tk__CanStatement() {
	return JB_CS_HasChar(JB__Constants_CSAfterStatement, JB_Tk__NextByte());
}

Message* JB_Tk__ChainTemporalRels(Message* FirstThing, Message* Opp) {
	Message* Rz = nil;
	JB_Incr(Rz);
	if (JB_Msg_EqualsSyx(Opp, kJB_SyxSCom, false)) {
		JB_Tree_SyntaxAppend(Opp, FirstThing);
		JB_Decr(Rz);
		return Opp;
	}
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxTRel, FirstThing->Position, JB_LUB[0]));
	JB_Tree_SyntaxAppend(Rz, FirstThing);
	JB_Tree_SyntaxAppend(Rz, Opp);
	if (!JB_Tk__WillEnd()) {
		Message* Last = JB_Tk__ProcessThingOrTmp(kJB__Tk_kOpp);
		JB_Incr(Last);
		if (Last) {
			Message* _tmPf0 = JB_Tk__FixTRels(Rz, Last);
			JB_Incr(_tmPf0);
			JB_Decr(Last);
			JB_Decr(Rz);
			JB_SafeDecr(_tmPf0);
			return _tmPf0;
		}
		JB_Decr(Last);
	}
	JB_SafeDecr(Rz);
	return Rz;
}

JB_String* JB_Tk__CharName(int Start, uint /*byte*/ Find) {
	JB_String* _tmPf0 = JB_Tk__GetData();
	Ind After = JB_Str_JBFind(_tmPf0, Find, Start + 1, JB_int__Max());
	if (JB_Ind_SyntaxCast(After)) {
		(JB_Tk__NextStartSet(After + 1));
		JB_String* _tmPf1 = JB_Tk__SyntaxAccess(Start + 1, After, kJB_SyxChar);
		JB_Incr(_tmPf1);
		JB_String* _tmPf2 = JB_Str_Unescape(_tmPf1);
		JB_Incr(_tmPf2);
		JB_Decr(_tmPf1);
		JB_SafeDecr(_tmPf2);
		return _tmPf2;
	}
	return nil;
}

Message* JB_Tk__CloseXML(Message* XML, int I, JB_String* S) {
	Ind CloseEnd = JB_Str_FindByte(S, '>', I + 2, JB_int__Max());
	if ((!JB_Ind_SyntaxCast(CloseEnd))) {
		return JB_Tk__ErrorAdd(JB_LUB[375], I);
	}
	JB_String* CloseName = JB_Str_Range(S, I + 2, CloseEnd);
	JB_Incr(CloseName);
	if ((!JB_Str_Equals(CloseName, XML->Name, false))) {
		FastString* _fsf0 = JB_FS_Constructor(nil);
		JB_Incr(_fsf0);
		JB_FS_AppendString(_fsf0, JB_LUB[376]);
		JB_FS_AppendString(_fsf0, CloseName);
		JB_FS_AppendString(_fsf0, JB_LUB[377]);
		JB_FS_AppendString(_fsf0, XML->Name);
		JB_FS_AppendByte(_fsf0, '>');
		JB_String* _tmPf1 = JB_FS_GetResult(_fsf0);
		JB_Incr(_tmPf1);
		JB_Decr(_fsf0);
		Message* _tmPf2 = JB_Tk__ErrorAdd(_tmPf1, I);
		JB_Incr(_tmPf2);
		JB_Decr(_tmPf1);
		JB_Decr(CloseName);
		JB_SafeDecr(_tmPf2);
		return _tmPf2;
	}
	JB_Decr(CloseName);
	(JB_Tk__NextStartSet((++CloseEnd)));
	XML->RangeLength = (XML->Position - CloseEnd);
	return XML;
}

Message* JB_Tk__DecorateThing(Message* R, int Ops) {
	JB_Incr(R);
	JB_SetRef(R, JB_Tk__GetFuncAfter(R));
	if (JB_Tk__WillEnd()) {
		JB_SafeDecr(R);
		return R;
	}
	int NotTemp = Ops & (~kJB__Tk_kOppTemporal);
	if (NotTemp and (!JB_Msg_EqualsSyx(R, kJB_SyxArg, false))) {
		JB_SetRef(R, JB_Tk__MakeRel(R, NotTemp));
	}
	if (Ops & kJB__Tk_kOppTemporal) {
		Message* Opp = JB_Tk__Process(kJB__Tk_kOppTemporal, false, nil);
		JB_Incr(Opp);
		if (Opp) {
			if (JB_Msg_SyntaxEquals(Opp, JB_LUB[442], false)) {
				Message* A = JB_Tk__PostInnerAdj(R, Opp);
				JB_Incr(A);
				if (!A) {
					JB_Decr(A);
					JB_Decr(Opp);
					JB_SafeDecr(R);
					return R;
				}
				JB_Decr(R);
				Message* _tmPf1 = JB_Tk__DecorateThing(A, Ops);
				JB_Incr(_tmPf1);
				JB_Decr(A);
				JB_Decr(Opp);
				JB_SafeDecr(_tmPf1);
				return _tmPf1;
			}
			Message* _tmPf0 = JB_Tk__ChainTemporalRels(R, Opp);
			JB_Incr(_tmPf0);
			JB_Decr(R);
			JB_Decr(Opp);
			JB_SafeDecr(_tmPf0);
			return _tmPf0;
		}
		JB_Decr(Opp);
	}
	JB_SafeDecr(R);
	return R;
}

Message* JB_Tk__DotSub(Syntax Fn, int Start, Message* Parent) {
	Message* Rz = nil;
	int After = JB_Tk__Byte((++Start));
	if (JB_CS_HasChar(JB__Constants_CSWordStart, After)) {
		After = JB_Tk__WordAfter(Start);
		if (!After) {
			return nil;
		}
	}
	 else if (JB__Tk__DotInsertAllow) {
		After = Start;
		JB__Tk__DotInsertAllow = false;
	}
	 else {
		return JB_Tk__ErrorAdd(JB_LUB[509], Start);
	}
	Rz = JB_Tk__NewSkip(nil, Fn, Start - 1, Start, After);
	if (JB_Tk__EatString(JB_LUB[510])) {
		JB_Tk__Params(Rz, After);
	}
	 else {
		Message* Prms = JB_Tk__NewEmpty(Rz, kJB_SyxEmb, After, After);
		if (((JB_Msg_EqualsSyx(Parent, kJB_SyxArg, false))) and JB_Tk__CanDot()) {
			Message* P = JB_Tk__ProcessThingParent(Prms, kJB__Tk_kOpp, kJB__Tk_kThing);
			if (P) {
				JB_Tree_SyntaxAppend(Prms, P);
				Prms->Func = kJB_SyxPrm;
			}
		}
	}
	return Rz;
}

Message* JB_Tk__ElseIfAdder(Message* Prev, Message* Curr) {
	Syntax Cf = Curr->Func;
	if ((Prev->Func != kJB_SyxTmp) or ((Cf != kJB_SyxTmp) and (Cf != kJB_SyxBra))) {
		return JB_Tk__UnexpectedSyntax(Curr);
	}
	if (Curr->Indent & 1) {
		return JB_Tk__ErrorAdd(JB_LUB[443], Curr->Position);
	}
	JB_FreeIfDead(JB_Tk__NewParentName(Prev, kJB_SyxArg, Curr->Position, JB_LUB[0]));
	JB_Tree_SyntaxAppend(Prev, Curr);
	return Prev;
}

int JB_Tk__EmbeddedCode(JB_String* Close, Message* Dest, int TmpFlags) {
	JB_String* _tmPf2 = JB_Tk__GetData();
	Ind Result = JB_Str_InStr(_tmPf2, Close, JB_Tk__NextStart(), JB_int__Max(), false);
	if (!JB_Ind_SyntaxCast(Result)) {
		FastString* _fsf0 = JB_FS_Constructor(nil);
		JB_Incr(_fsf0);
		JB_FS_AppendString(_fsf0, JB_LUB[496]);
		JB_FS_AppendString(_fsf0, Close);
		JB_String* _tmPf3 = JB_FS_GetResult(_fsf0);
		JB_Incr(_tmPf3);
		JB_Decr(_fsf0);
		JB_FreeIfDead(JB_Tk__ErrorAdd(_tmPf3, JB_Tk__NextStart()));
		JB_Decr(_tmPf3);
		return Result;
	}
	JB_Tk__ParseLoop(Dest, TmpFlags);
	if (JB_Tk__NextStart() > Result) {
		FastString* _fsf1 = JB_FS_Constructor(nil);
		JB_Incr(_fsf1);
		JB_FS_AppendString(_fsf1, JB_LUB[497]);
		JB_FS_AppendString(_fsf1, Close);
		JB_FS_AppendString(_fsf1, JB_LUB[498]);
		JB_String* _tmPf4 = JB_FS_GetResult(_fsf1);
		JB_Incr(_tmPf4);
		JB_Decr(_fsf1);
		JB_FreeIfDead(JB_Tk__ErrorAdd(_tmPf4, Result));
		JB_Decr(_tmPf4);
		return Result;
	}
	Result = (Result + JB_Str_Length(Close));
	(JB_Tk__NextStartSet(Result));
	return Result;
}

Message* JB_Tk__ErrorAdd(JB_String* S, Ind Start) {
	if (JB_Tk__OK()) {
		return JB_Tk__ErrorAlwaysAdd(S, Start);
	}
	return nil;
}

Message* JB_Tk__ErrorAlwaysAdd(JB_String* S, Ind Start) {
	(JB_Tk__ErrorStartSet(Start));
	Message* _tmPf0 = JB_Msg_ConstructorEmpty(nil);
	JB_Incr(_tmPf0);
	JB_Error* Err = JB_Err_Constructor(nil, _tmPf0, JB_LUB[0], kJB__ErrorSeverity_Error, JB_LUB[0]);
	JB_Incr(Err);
	JB_Decr(_tmPf0);
	Err->Position = Start;
	(JB_Err_SyntaxIsSet(Err, kJB__ErrorFlags_DontStrip, true));
	(JB_Err_SyntaxIsSet(Err, kJB__ErrorFlags_Parse, true));
	JB_SetRef(Err->Name, S);
	JB_SetRef(Err->OriginalData, JB_Tk__GetData());
	JB_Rec_AppendErr(((JB_ErrorReceiver*)nil), Err);
	JB_Decr(Err);
	return nil;
}

void JB_Tk__ErrorEvent(int Start, int ExpectedBits, int RealBits) {
	//visible;
	FastString* Err = JB_FS_Constructor(nil);
	JB_Incr(Err);
	if (!(RealBits & kJB__Tk_kIllegalChar)) {
		if (!(ExpectedBits and (RealBits and JB_Tk__FindError(ExpectedBits)))) {
			JB_FS_AppendString(Err, JB_LUB[259]);
		}
		 else {
			{
				int _Valuef1 = 0;
				while (_Valuef1 < 5) {
					ExpectedBits = JB_Tk__MessageErrorSub(Err, ExpectedBits);
					(++_Valuef1);
					if ((!ExpectedBits)) {
						break;
					}
				};
			}
			;
			JB_FS_AppendString(Err, JB_LUB[369]);
		}
	}
	if (RealBits == kJB__Tk_kEndOfLine) {
		JB_FS_AppendString(Err, JB_LUB[378]);
	}
	 else if (!RealBits) {
		JB_FS_AppendString(Err, JB_LUB[379]);
	}
	 else {
		if (JB_Tk__NextStart() <= Start) {
			(JB_Tk__NextStartSet(Start + 1));
		}
		if (RealBits & kJB__Tk_kIllegalChar) {
			JB_FS_AppendString(Err, JB_LUB[380]);
			uint Illegal = JB_Tk__Byte(Start);
			if (JB_byte_CanPrintAsNormalChar(Illegal)) {
				JB_FS_AppendByte(Err, '\'');
				JB_FS_AppendByte(Err, JB_Tk__Byte(Start));
				JB_FS_AppendByte(Err, '\'');
			}
			 else {
				JB_FS_AppendString(Err, JB_LUB[202]);
				JB_FS_AppendHex(Err, Illegal, 2);
				JB_FS_AppendByte(Err, ' ');
			}
		}
		 else {
			JB_FS_AppendByte(Err, '\'');
			Ind N = JB_int_OperatorMin(JB_Tk__NextStart(), (Start + 100));
			JB_String* _tmPf3 = JB_Tk__SyntaxAccess(Start, N, kJB_SyxNil);
			JB_Incr(_tmPf3);
			JB_String* _tmPf2 = JB_Str_Escape(_tmPf3);
			JB_Incr(_tmPf2);
			JB_Decr(_tmPf3);
			JB_FS_AppendString(Err, _tmPf2);
			JB_Decr(_tmPf2);
			JB_FS_AppendByte(Err, '\'');
		}
	}
	JB_String* _tmPf4 = JB_FS_SyntaxCast(Err);
	JB_Incr(_tmPf4);
	JB_Decr(Err);
	JB_FreeIfDead(JB_Tk__ErrorAdd(_tmPf4, Start));
	JB_Decr(_tmPf4);
}

void JB_Tk__ErrorLetter(int Start) {
	JB_FreeIfDead(JB_Tk__ErrorAdd(JB_LUB[381], Start));
}

bool JB_Tk__ExpectEndChar(int Start, JB_String* S, bool Expect) {
	JB_Tk__CleanSpaces();
	if (JB_Tk__EatString(S)) {
		return true;
	}
	if (Expect) {
		FastString* _fsf0 = JB_FS_Constructor(nil);
		JB_Incr(_fsf0);
		JB_FS_AppendString(_fsf0, JB_LUB[382]);
		JB_FS_AppendString(_fsf0, S);
		JB_FS_AppendByte(_fsf0, '\'');
		JB_String* _tmPf1 = JB_FS_GetResult(_fsf0);
		JB_Incr(_tmPf1);
		JB_Decr(_fsf0);
		JB_FreeIfDead(JB_Tk__ErrorAdd(_tmPf1, Start));
		JB_Decr(_tmPf1);
	}
	return false;
}

Message* JB_Tk__fAccess(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	Ind Pos = ((Ind)JB_Ternary(Parent, Parent->Position, ((Ind)Start)));
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxAcc, Pos, JB_LUB[0]));
	Message* Prms = JB_Tk__NewParentName(Rz, kJB_SyxArr, Start, JB_LUB[0]);
	JB_Incr(Prms);
	JB_Tk__ParseLoopFlags(Prms, JB_LUB[503], 0);
	(JB_Msg_AfterSet(Rz, JB_Msg_After(Prms)));
	JB_Decr(Prms);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fAdjectiveOp(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxAdj, Start, JB_LUB[0]));
	Message* _tmPf0 = JB_Tk__Process(kJB__Tk_kOppChain, kJB__Tk_kExpect, nil);
	JB_Incr(_tmPf0);
	JB_Tree_SyntaxAppend(Rz, _tmPf0);
	JB_Decr(_tmPf0);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fAdjectiveThing(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxAdj, Start, JB_LUB[0]));
	Message* _tmPf0 = JB_Tk__ProcessThing(0, kJB__Tk_kExpect);
	JB_Incr(_tmPf0);
	JB_Tree_SyntaxAppend(Rz, _tmPf0);
	JB_Decr(_tmPf0);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fAfterRel(int Start, Message* Parent) {
	return JB_Tk__NewParent(nil, kJB_SyxARel, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fArgColon(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxArg, Start, JB_LUB[0]));
	Rz->RangeLength = 1;
	while (true) {
		Message* Item = JB_Tk__Process(kJB__Tk_kTemporal, false, Rz);
		JB_Incr(Item);
		if (!Item) {
			JB_SetRef(Item, JB_Tk__ProcessThing(kJB__Tk_kOpp, false));
		}
		JB_Tree_SyntaxAppend(Rz, Item);
		if (!(Item and JB_Tk__Allow(kJB__Tk_kComma))) {
			JB_Decr(Item);
			break;
		}
		JB_Decr(Item);
	};
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fArgName(int Start, Message* Parent) {
	if (Parent) {
		Syntax F = Parent->Func;
		if ((F == kJB_SyxArg) or ((F == kJB_SyxList) or ((F == kJB_SyxBra) or (F == kJB_SyxArr)))) {
			JB_String* Name = JB_Tk__CharName(Start + 1, '"');
			JB_Incr(Name);
			if (Name != nil) {
				JB_SetRef(Parent->Name, Name);
				JB_Decr(Name);
				return Parent;
			}
			JB_Decr(Name);
		}
	}
	return nil;
}

Message* JB_Tk__fArgOpen(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxArg, Start, JB_LUB[0]));
	JB_Tk__ParseLoopFlags(Rz, JB_LUB[504], kJB__Tk_kTemporal);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fArray(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxArr, Start, JB_LUB[0]));
	JB_Tk__ParseLoopFlags(Rz, JB_LUB[503], kJB__Tk_kTemporalSyxNoBar);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fAsk(int Start, Message* Parent) {
	return JB_Tk__fAskSub(Start, Parent, kJB_SyxAsk);
}

Message* JB_Tk__fAskSub(int Start, Message* Parent, Syntax F) {
	Message* Rz = nil;
	JB_Incr(Rz);
	Message* Opp = JB_Tk__Process(kJB__Tk_kOpp, kJB__Tk_kExpect, nil);
	JB_Incr(Opp);
	Message* First = JB_Tk__ProcessThing(kJB__Tk_kOppSyx, kJB__Tk_kExpect);
	JB_Incr(First);
	if (!(First and Opp)) {
		JB_Decr(First);
		JB_Decr(Opp);
		JB_Decr(Rz);
		return nil;
	}
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, F, Start, JB_LUB[0]));
	JB_Tree_SyntaxAppend(Rz, First);
	JB_Decr(First);
	Message* NeedsAdj = JB_Tk__Process(kJB__Tk_kOpp, kJB__Tk_kAllow, nil);
	JB_Incr(NeedsAdj);
	if (!NeedsAdj) {
		JB_Tree_SyntaxAppend(Rz, Opp);
	}
	 else {
		Message* Adj = JB_Tk__NewParentName(Rz, kJB_SyxAdj, NeedsAdj->Position, JB_LUB[0]);
		JB_Incr(Adj);
		JB_Tree_SyntaxAppend(Adj, Opp);
		JB_Tree_SyntaxAppend(Adj, NeedsAdj);
		JB_Decr(Adj);
		Message* _tmPf0 = JB_Tk__ProcessThingParent(Rz, kJB__Tk_kOppSyx, kJB__Tk_kThing);
		JB_Incr(_tmPf0);
		JB_Tree_SyntaxAppend(Rz, _tmPf0);
		JB_Decr(_tmPf0);
	}
	JB_Decr(Opp);
	JB_Decr(NeedsAdj);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fAtName(int Start, Message* Parent) {
	return JB_Tk__NewWord(nil, kJB_SyxName, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fAtNamedExp(int Start, Message* Parent) {
	if (!(Parent and JB_Tk__NeedName(Parent))) {
		return nil;
	}
	Parent->Func = kJB_SyxName;
	Message* _tmPf0 = JB_Tk__ProcessThing(0, kJB__Tk_kExpect);
	JB_Incr(_tmPf0);
	JB_Tree_SyntaxAppend(Parent, _tmPf0);
	JB_Decr(_tmPf0);
	return Parent;
}

Message* JB_Tk__fBackTick(int Start, Message* Parent) {
	JB_String* _tmPf0 = JB_Tk__GetData();
	Ind After = JB_Str_FindByte(_tmPf0, '`', JB_Tk__NextStart(), JB_int__Max());
	if (!JB_Ind_SyntaxCast(After)) {
		return JB_Tk__ErrorAdd(JB_LUB[391], Start);
	}
	(JB_Tk__NextStartSet(After + 1));
	return JB_Tk__NewSkip(nil, kJB_SyxBack, Start, Start + 1, After);
}

Message* JB_Tk__fBAdjectiveOp(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxBadj, Start, JB_LUB[0]));
	Message* _tmPf0 = JB_Tk__Process(kJB__Tk_kOppChain, kJB__Tk_kExpect, nil);
	JB_Incr(_tmPf0);
	JB_Tree_SyntaxAppend(Rz, _tmPf0);
	JB_Decr(_tmPf0);
	JB_Tree_SyntaxAppend(Rz, Parent);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fBAdjectiveThing(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxBadj, Start, JB_LUB[0]));
	Message* _tmPf0 = JB_Tk__ProcessThing(0, kJB__Tk_kExpect);
	JB_Incr(_tmPf0);
	JB_Tree_SyntaxAppend(Rz, _tmPf0);
	JB_Decr(_tmPf0);
	JB_Tree_SyntaxAppend(Rz, Parent);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fBeforeRel(int Start, Message* Parent) {
	return JB_Tk__BeforeRelSub(Start, kJB__Tk_kAllow);
}

Message* JB_Tk__fBeforeRelMinus(int Start, Message* Parent) {
	uint C = JB_Tk__Byte(Start + 1);
	if (JB_byte_IsInt(C) and (JB_Tk__Byte(Start) == '-')) {
		return JB_Tk__NumberSub(Start + 1, Start);
	}
	return JB_Tk__BeforeRelSub(Start, kJB__Tk_kAllow);
}

Message* JB_Tk__fBinary(int Start, Message* Parent) {
	JB_String* _tmPf0 = JB_Tk__GetData();
	Ind End = JB_Str_InStr(_tmPf0, JB_LUB[48], Start + 2, JB_int__Max(), false);
	if (JB_Ind_SyntaxCast(End)) {
		JB_String* S = JB_Tk__SyntaxAccess(Start + 2, End, kJB_SyxBin);
		JB_Incr(S);
		(JB_Tk__NextStartSet(End + 2));
		JB_String* _tmPf1 = JB_Str_UnHex(S, nil);
		JB_Incr(_tmPf1);
		JB_Decr(S);
		Message* _tmPf2 = JB_Tk__NewParentName(nil, kJB_SyxBin, Start, _tmPf1);
		JB_Incr(_tmPf2);
		JB_Decr(_tmPf1);
		JB_SafeDecr(_tmPf2);
		return _tmPf2;
	}
	return JB_Tk__ErrorAdd(JB_LUB[392], Start);
}

Message* JB_Tk__fBracket(int Start, Message* Parent) {
	Message* Rz = nil;
	Rz = JB_Tk__NewParentName(nil, kJB_SyxList, Start, JB_LUB[0]);
	bool Lines = JB_Tk__ParseLoopFlags(Rz, JB_LUB[445], kJB__Tk_kTemporalSyxNoBar);
	if ((!Lines) and JB_Ring_HasChildCount(Rz, 1)) {
		JB_Msg_BecomeStr(Rz, kJB_SyxBra, JB_LUB[0]);
	}
	return Rz;
}

Message* JB_Tk__fChar(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__fCharSub(Start, Start, '\''));
	if (!Rz) {
		JB_Decr(Rz);
		return JB_Tk__ErrorAdd(JB_LUB[393], JB_Tk__NextStart());
	}
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fCharSub(int Pos, int Start, uint /*byte*/ Find) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_String* Name = JB_Tk__CharName(Start, Find);
	JB_Incr(Name);
	if (Name != nil) {
		JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxChar, Pos, Name));
	}
	JB_Decr(Name);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fComment(int Start, Message* Parent) {
	int Count = 1;
	Ind I = JB_Tk__NextStart();
	JB_String* D = JB_Tk__GetData();
	JB_Incr(D);
	while (true) {
		I = JB_Str_FindByte(D, '/', I + 1, JB_int__Max());
		if (!JB_Ind_SyntaxCast(I)) {
			JB_Decr(D);
			return JB_Tk__ErrorAdd(JB_LUB[394], Start);
		}
		 else if (JB_Str_ByteValue(D, I - 1) == '*') {
			(--Count);
		}
		 else if (JB_Str_ByteValue(D, I + 1) == '*') {
			(++Count);
			I = (I + 2);
		}
		if ((!Count)) {
			break;
		}
	};
	JB_Decr(D);
	(JB_Tk__NextStartSet(I + 1));
	return JB__Tk__EndOfLineMarker;
}

Message* JB_Tk__fCommentLine(int Start, Message* Parent) {
	JB_Tk__GotoEndOfLine(JB_Tk__NextStart());
	return JB__Tk__EndOfLineMarker;
}

Message* JB_Tk__fDecl(int Start, Message* Parent) {
	Message* Result = JB_Tk__BarThings(Start, kJB_SyxDecl);
	JB_Incr(Result);
	if (Result and (!JB_Tk__WillEnd())) {
		Message* Curr = JB_Tk__ProcessThing(kJB__Tk_kOppSyx | kJB__Tk_kOppTemporal, false);
		JB_Incr(Curr);
		if (Curr) {
			JB_Tree_SyntaxAppend(Result, Curr);
		}
		JB_Decr(Curr);
	}
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fDot(int Start, Message* Parent) {
	Message* _tmPf0 = ((Message*)JB_Ring_Parent(Parent));
	JB_Incr(_tmPf0);
	Message* _tmPf1 = JB_Tk__DotSub(kJB_SyxDot, Start, _tmPf0);
	JB_Incr(_tmPf1);
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Message* JB_Tk__fDotAccess(int Start, Message* Parent) {
	Message* Rz = nil;
	int N = JB_Tk__NextStart();
	Message* Name = JB_Tk__NewWord(nil, kJB_SyxStr, N, N);
	int After = JB_Tk__NextStart();
	JB_SetRef(Name->Name, JB_Str_ReplaceAll(Name->Name, JB_LUB[137], JB_LUB[23], false, nil));
	Rz = JB_Tk__NewEmpty(nil, kJB_SyxAcc, Start, After);
	Message* Prms = JB_Tk__NewEmpty(Rz, kJB_SyxArr, Start, Start);
	JB_Tree_SyntaxAppend(Prms, Name);
	return Rz;
}

Message* JB_Tk__fEndOfLine(int Start, Message* Parent) {
	return JB__Tk__EndOfLineMarker;
}

Message* JB_Tk__fError(int Start, Message* Parent) {
	return nil;
}

Message* JB_Tk__fError2(int Start, Message* Parent) {
	return JB_Tk__ErrorAdd(JB_LUB[387], Start);
}

Message* JB_Tk__fFuncCall(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxFunc, Parent->Position, JB_LUB[0]));
	JB_Tk__Params(Rz, Start);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__FillXML(Message* XML, Ind I) {
	JB_String* S = JB_Tk__GetData();
	JB_Incr(S);
	if (JB_Str_ByteValue(S, I - 1) == '/') {
		(JB_Tk__NextStartSet(I + 1));
		JB_Decr(S);
		return XML;
	}
	(JB_Tk__NextStartSet(I));
	while (true) {
		int Prev = JB_Tk__NextStart();
		I = JB_Str_FindByte(S, '<', Prev, JB_int__Max());
		if (!JB_Ind_SyntaxCast(I)) {
			JB_Decr(S);
			return JB_Tk__ErrorAdd(JB_LUB[444], XML->Position);
		}
		JB_Tk__AddXMLText(XML, S, Prev, I);
		(JB_Tk__NextStartSet(I));
		uint Next = JB_Str_ByteValue(S, I + 1);
		if (Next == '/') {
			Message* _tmPf3 = JB_Tk__CloseXML(XML, I, S);
			JB_Incr(_tmPf3);
			JB_Decr(S);
			JB_SafeDecr(_tmPf3);
			return _tmPf3;
		}
		if (Next != '!') {
			Message* _tmPf0 = JB_Tk__fXML(I, nil);
			JB_Incr(_tmPf0);
			if (!_tmPf0) {
				JB_Decr(_tmPf0);
				JB_Decr(S);
				return nil;
			}
			JB_Tree_SyntaxAppend(XML, _tmPf0);
			JB_Decr(_tmPf0);
		}
		 else if (JB_Str_MidEquals(S, I, JB_LUB[15], false)) {
			Message* _tmPf1 = JB_Tk__XMLWhatever(I, 4, JB_LUB[16], kJB_SyxXCom);
			JB_Incr(_tmPf1);
			if (!_tmPf1) {
				JB_Decr(_tmPf1);
				JB_Decr(S);
				return nil;
			}
			JB_Tree_SyntaxAppend(XML, _tmPf1);
			JB_Decr(_tmPf1);
		}
		 else if (JB_Str_MidEquals(S, I, JB_LUB[13], false)) {
			Message* _tmPf2 = JB_Tk__XMLWhatever(I, 9, JB_LUB[14], kJB_SyxXCDT);
			JB_Incr(_tmPf2);
			if (!_tmPf2) {
				JB_Decr(_tmPf2);
				JB_Decr(S);
				return nil;
			}
			JB_Tree_SyntaxAppend(XML, _tmPf2);
			JB_Decr(_tmPf2);
		}
		 else {
			JB_Decr(S);
			return JB_Tk__ErrorAdd(JB_LUB[0], I);
		}
	};
	JB_Decr(S);
}

int JB_Tk__FindError(int Num) {
	if (Num == kJB__Tk_kThing) {
		return kJB__Tk_kThing;
	}
	{
		DictionaryReader* _navf0 = JB_Dict_Navigate(JB__Tk__ErrorNames);
		JB_Incr(_navf0);
		while (true) {
			JB_String* _Valuef2 = ((JB_String*)JB_DictionaryReader_NextValue(_navf0));
			JB_Incr(_Valuef2);
			if (_Valuef2 == nil) {
				JB_Decr(_Valuef2);
				break;
			}
			JB_Decr(_Valuef2);
			JB_String* Key = JB_Nav_Name(_navf0);
			JB_Incr(Key);
			int I = ((int)JB_Str_TextIntegerValid(Key, nil));
			JB_Decr(Key);
			if ((Num & I) == I) {
				JB_Decr(_navf0);
				return I;
			}
		};
		JB_Decr(_navf0);
	}
	;
	return 0;
}

int JB_Tk__FinishParseLoop(int Lines, Message* Output, int After) {
	if ((Output->Func == kJB_SyxArg) and JB_Msg_SyntaxIs(Output, kJB__MsgParseFlags_Style2)) {
		(JB_Msg_AfterSet(Output, After));
		while (true) {
			Output = ((Message*)JB_Ring_Parent(Output));
			if (!Output) {
				break;
			}
			if (Output->Func == kJB_SyxArg) {
				if (!JB_Msg_SyntaxIs(Output, kJB__MsgParseFlags_Style2)) {
					break;
				}
				(JB_Msg_AfterSet(Output, After));
			}
		};
	}
	return Lines;
}

Message* JB_Tk__fInnerNiceAdj(int Start, Message* Parent) {
	return JB_Tk__fAskSub(Start, Parent, kJB_Syxbinn);
}

Message* JB_Tk__FixTRels(Message* Self, Message* Last) {
	if ((!Last)) {
		0;
	}
	 else if (!JB_Msg_EqualsSyx(Last, kJB_SyxTRel, false)) {
		JB_Tree_SyntaxAppend(Self, Last);
	}
	 else {
		Message* _tmPf0 = ((Message*)JB_Ring_First(Last));
		JB_Incr(_tmPf0);
		JB_Tree_SyntaxAppend(Self, _tmPf0);
		JB_Decr(_tmPf0);
		(JB_Ring_FirstSet(Last, Self));
		return Last;
	}
	return Self;
}

Message* JB_Tk__fMsgList(int Start, Message* Parent) {
	Message* Result = JB_Tk__NewParentName(nil, kJB_SyxMsg, Start, JB_LUB[0]);
	JB_Incr(Result);
	Message* Name = JB_Tk__Process(kJB__Tk_kTemporalWord, true, Result);
	JB_Incr(Name);
	if (!Name) {
		JB_Decr(Name);
		JB_Decr(Result);
		return nil;
	}
	Message* It = ((Message*)JB_Tree_Second(Name));
	JB_Incr(It);
	JB_Decr(Name);
	if (It) {
		Message* _tmPf1 = JB_Tk__UnexpectedSyntax(It);
		JB_Incr(_tmPf1);
		JB_Decr(It);
		JB_Decr(Result);
		JB_SafeDecr(_tmPf1);
		return _tmPf1;
	}
	JB_Decr(It);
	int Ops = kJB__Tk_kOppSyx | (kJB__Tk_kOppTemporal | kJB__Tk_kOppYoda);
	while (JB_Tk__NextLineAndIndent(Result)[0]) {
		Message* Item = JB_Tk__ProcessThing(Ops, false);
		JB_Incr(Item);
		if (!Item) {
			JB_Decr(Item);
			break;
		}
		if (JB_Str_OperatorEndsWith(Item->Name, JB_LUB[133])) {
			Message* _tmPf0 = JB_Tk__ErrorAdd(JB_LUB[486], Item->Position);
			JB_Incr(_tmPf0);
			JB_Decr(Item);
			JB_Decr(Result);
			JB_SafeDecr(_tmPf0);
			return _tmPf0;
		}
		JB_Tree_SyntaxAppend(Result, Item);
		JB_Decr(Item);
	};
	JB_Tk__ExpectEndChar(Start, JB_LUB[133], true);
	(JB_Msg_AfterSet(Result, JB_Tk__NextStart()));
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fNumber(int Start, Message* Parent) {
	return JB_Tk__NumberSub(Start, Start);
}

Message* JB_Tk__fOpAsThing(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxOat, Start, JB_LUB[0]));
	Message* _tmPf0 = JB_Tk__Process(kJB__Tk_kOpp, false, nil);
	JB_Incr(_tmPf0);
	JB_Tree_SyntaxAppend(Rz, _tmPf0);
	JB_Decr(_tmPf0);
	Message* _tmPf1 = JB_Tk__ProcessThing(kJB__Tk_kOpp, false);
	JB_Incr(_tmPf1);
	JB_Tree_SyntaxAppend(Rz, _tmPf1);
	JB_Decr(_tmPf1);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fOppBracket(int Start, Message* Parent) {
	Message* Result = JB_Tk__NewParentName(nil, kJB_SyxBra, Start, JB_LUB[0]);
	JB_Incr(Result);
	Message* Opp1 = JB_Tk__Process(kJB__Tk_kOppChain, false, nil);
	JB_Incr(Opp1);
	Message* Opp2 = JB_Tk__Process(kJB__Tk_kOpp, false, nil);
	JB_Incr(Opp2);
	if (!Opp2) {
		JB_Tree_SyntaxAppend(Result, Opp1);
	}
	 else {
		Message* Rel = JB_Tk__NewParentName(Result, kJB_SyxRel, JB_Tk__NextStart() - 1, JB_LUB[0]);
		JB_Incr(Rel);
		JB_Tree_SyntaxAppend(Rel, Opp1);
		JB_Tree_SyntaxAppend(Rel, Opp2);
		Message* _tmPf0 = JB_Tk__Process(kJB__Tk_kOppChain, false, nil);
		JB_Incr(_tmPf0);
		JB_Tree_SyntaxAppend(Rel, _tmPf0);
		JB_Decr(Rel);
		JB_Decr(_tmPf0);
	}
	JB_Decr(Opp1);
	JB_Decr(Opp2);
	JB_Tk__ExpectEndChar(Start, JB_LUB[445], true);
	Message* _tmPf1 = JB_Tk__OppChain(Result);
	JB_Incr(_tmPf1);
	JB_Decr(Result);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Message* JB_Tk__fOppSyx(int Start, Message* Parent) {
	return JB_Tk__NewParent(nil, kJB_SyxOpp, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fOppSyxNeq(int Start, Message* Parent) {
	Message* Result = JB_Tk__fOppSyx(Start, nil);
	JB_Incr(Result);
	if ('=' == JB_Tk__NextByte()) {
		JB_Decr(Result);
		return JB_Tk__ErrorAdd(JB_LUB[395], JB_Tk__NextStart());
	}
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fOppWord(int Start, Message* Parent) {
	int After = JB_Tk__WordAfter(Start);
	if (JB_Tk__Byte(After) != '.') {
		Message* Opp = JB_Tk__NewParent(nil, kJB_SyxOpp, Start, After);
		JB_Incr(Opp);
		Message* _tmPf0 = JB_Tk__OppChain(Opp);
		JB_Incr(_tmPf0);
		JB_Decr(Opp);
		JB_SafeDecr(_tmPf0);
		return _tmPf0;
	}
	return nil;
}

Message* JB_Tk__fQuestion(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__NewWord(nil, kJB_SyxQues, Start, JB_Tk__NextStart()));
	Message* _tmPf0 = JB_Tk__ProcessThing(kJB__Tk_kOpp, false);
	JB_Incr(_tmPf0);
	JB_Tree_SyntaxAppend(Rz, _tmPf0);
	JB_Decr(_tmPf0);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fQuoteLang(int Start, Message* Parent) {
	Message* Rz = nil;
	Rz = JB_Tk__NewParentName(nil, kJB_SyxQuot, Start, JB_LUB[0]);
	JB_Tk__ParseLoopFlags(Rz, JB_LUB[135], kJB__Tk_kTemporalSyxNoBar);
	return Rz;
}

Message* JB_Tk__fSDot(int Start, Message* Parent) {
	if (Start > 0) {
		uint C = JB_Tk__Byte(Start - 1);
		if (JB_CS_HasChar(JB__Constants_CSWordMiddle, C)) {
			return nil;
		}
	}
	return JB_Tk__DotSub(kJB_SyxSDot, Start, Parent);
}

Message* JB_Tk__fShebang(int Start, Message* Parent) {
	Ind S = JB_Tk__NextStart();
	JB_String* _tmPf0 = JB_Tk__GetData();
	Ind S2 = JB_Str_Find(_tmPf0, JB__Constants_CSLine, S, JB_int__Max());
	(JB_Tk__NextStartSet(S2));
	return JB_Tk__NewSkip(Parent, kJB_SyxSheb, Start, S, S2);
}

Message* JB_Tk__fStatement(int Start, Message* Parent) {
	Message* Tmp = JB_Tk__fTmp(Start, kJB__Tk_kOpp & (~kJB__Tk_kOppBra), kJB__Tk_kThing, Parent);
	JB_Incr(Tmp);
	if (!JB_Msg_EqualsSyx(Tmp, kJB_SyxThg, false)) {
		JB_SafeDecr(Tmp);
		return Tmp;
	}
	JB_Tree_Remove(Tmp);
	JB_Decr(Tmp);
	(JB_Tk__NextStartSet(Start));
	return JB_Tk__ProcessThing(kJB__Tk_kOpp, false);
}

Message* JB_Tk__fStatementColon(int Start, Message* Parent) {
	return JB_Tk__fTmp(Start, kJB__Tk_kOpp & (~kJB__Tk_kOppBra), kJB__Tk_kThing | kJB__Tk_kColonArg, Parent);
}

Message* JB_Tk__fString(int Start, Message* Parent) {
	JB_String* _tmPf0 = JB_Tk__GetData();
	Ind After = JB_Str_JBFind(_tmPf0, '"', (JB_Tk__NextStart()), JB_int__Max());
	if (!JB_Ind_SyntaxCast(After)) {
		return JB_Tk__ErrorAdd(JB_LUB[505], JB_Tk__NextStart());
	}
	Ind StrPos = Start + 1;
	Message* Result = JB_Tk__NewParentName(nil, kJB_SyxStr, Start, JB_LUB[0]);
	JB_Incr(Result);
	while (JB_Ind_SyntaxCast((StrPos))) {
		JB_String* _tmPf1 = JB_Tk__GetData();
		Ind NewStrPos = JB_Str_JBFind(_tmPf1, '$', StrPos, After);
		if (!JB_Ind_SyntaxCast(NewStrPos)) {
			NewStrPos = After;
		}
		if (NewStrPos > StrPos) {
			Message* Str = JB_Tk__NewParent(Result, kJB_SyxEmb, StrPos, NewStrPos);
			JB_Incr(Str);
			JB_SetRef(Str->Name, JB_Str_Unescape(Str->Name));
			JB_Decr(Str);
		}
		if (NewStrPos >= After) {
			break;
		}
		(++NewStrPos);
		uint C0 = JB_Tk__Byte(NewStrPos);
		NewStrPos = (NewStrPos + (C0 == '{'));
		(JB_Tk__NextStartSet(NewStrPos));
		if (C0 == '{') {
			StrPos = JB_Tk__EmbeddedCode(JB_LUB[504], Result, kJB__Tk_kTemporalSyx);
		}
		 else {
			Syntax Type = kJB_SyxThg;
			if (C0 == '.') {
				Type = kJB_SyxSDot;
				(++NewStrPos);
			}
			JB_String* _tmPf2 = JB_Tk__GetData();
			StrPos = JB_Str_OutCharSet(_tmPf2, JB__Constants_CSWordMiddle, NewStrPos + 1, After);
			if (!JB_Ind_SyntaxCast(StrPos)) {
				StrPos = After;
			}
			Message* Rr = JB_Tk__NewParent(Result, Type, NewStrPos, StrPos);
			JB_Incr(Rr);
			if (C0 == '.') {
				JB_FreeIfDead(JB_Tk__NewParentName(Rr, kJB_SyxEmb, NewStrPos - 1, JB_LUB[0]));
			}
			JB_Decr(Rr);
		}
		if (StrPos > After) {
			JB_Decr(Result);
			return JB_Tk__ErrorAdd(JB_LUB[506], NewStrPos);
		}
	};
	(JB_Tk__NextStartSet((++After)));
	Result->RangeLength = (After - Start);
	JB_Msg_UnEmbedStr(Result);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fSuperStr(int Start, Message* Parent) {
	JB_String* D = JB_Tk__GetData();
	int Nest = 1;
	while (true) {
		Ind After = JB_Str_FindByte(D, '`', JB_Tk__NextStart(), JB_int__Max());
		if (!JB_Ind_SyntaxCast(After)) {
			break;
		}
		(JB_Tk__NextStartSet(After + 3));
		if (JB_Str_MidEquals(D, After - 2, JB_LUB[10], false)) {
			(++Nest);
		}
		 else if (JB_Str_MidEquals(D, After, JB_LUB[11], false)) {
			(--Nest);
			if (!Nest) {
				return JB_Tk__NewSkip(nil, kJB_SyxSStr, Start, Start + 3, After);
			}
		}
	};
	return JB_Tk__ErrorAdd(JB_LUB[391], Start);
}

Message* JB_Tk__fSyntacticComment(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxList, Start, JB_LUB[0]));
	bool Lines = JB_Tk__ParseLoopFlags(Rz, JB_LUB[507], kJB__Tk_kTemporalSyxNoBar);
	Rz->Func = kJB_SyxSCom;
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fTemporalHashThing(int Start, Message* Parent) {
	Message* Result = JB_Tk__NewParentName(Parent, kJB_SyxTril, Start, JB_LUB[0]);
	JB_Incr(Result);
	Ind S = JB_Tk__NextStart();
	JB_FreeIfDead(JB_Tk__NewParent(Result, kJB_SyxCnj, S, JB_Tk__WordAfter(S)));
	Message* X = JB_Tk__ProcessThingOrTmp(kJB__Tk_kOpp & (~kJB__Tk_kOppBra));
	JB_Incr(X);
	if (X) {
		JB_Tree_SyntaxAppend(Result, X);
		Message* _tmPf0 = JB_Tk__ProcessThing(kJB__Tk_kOpp, false);
		JB_Incr(_tmPf0);
		JB_Tree_SyntaxAppend(Result, _tmPf0);
		JB_Decr(_tmPf0);
	}
	JB_Decr(X);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fTemporalRel(int Start, Message* Parent) {
	return JB_Tk__NewWord(nil, kJB_SyxCnj, Start, JB_Tk__CleanSpaces());
}

Message* JB_Tk__fTemporalRelSyx(int Start, Message* Parent) {
	return JB_Tk__NewParent(nil, kJB_SyxSCnj, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fThingSyx(int Start, Message* Parent) {
	return JB_Tk__NewParent(nil, kJB_SyxSThg, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fThingWord(int Start, Message* Parent) {
	int Name = JB_Tk__WordAfter(Start);
	return JB_Tk__NewParent(nil, kJB_SyxThg, Start, Name);
}

Message* JB_Tk__fTmp(int Start, int OpFlags, int ThingFlags, Message* Parent) {
	Message* Result = JB_Tk__NewWord(Parent, kJB_SyxTmp, Start, Start);
	return JB_Tk__fTmpSub(Result, OpFlags, ThingFlags);
}

Message* JB_Tk__fTmpPlus(int Start, Message* Parent) {
	int C = JB_Tk__NextByte();
	if ((C == '"') or (C == '\'')) {
		Message* Tmp = JB_Tk__fCharSub(Start, Start + 1, C);
		if (Tmp) {
			Tmp->Func = kJB_SyxTmp;
			Tmp = JB_Tk__fTmpSub(Tmp, kJB__Tk_kOpp & (~kJB__Tk_kOppBra), kJB__Tk_kThing);
			if (!JB_Msg_EqualsSyx(Tmp, kJB_SyxThg, false)) {
				return Tmp;
			}
		}
	}
	return JB_Tk__fError2(Start, nil);
}

Message* JB_Tk__fTmpSub(Message* Result, int OpFlags, int ThingFlags) {
	JB_Incr(Result);
	if (JB_Tk__WillEnd()) {
		JB_SafeDecr(Result);
		return Result;
	}
	if (JB_Tk__CanStatement()) {
		while (true) {
			Message* Item = JB_Tk__ProcessThingParent(Result, OpFlags, ThingFlags);
			JB_Incr(Item);
			if (!Item) {
				JB_Decr(Item);
				break;
			}
			JB_Tree_SyntaxAppend(Result, Item);
			if (JB_Tk__WillEnd()) {
				JB_Decr(Item);
				JB_SafeDecr(Result);
				return Result;
			}
			if (JB_Msg_EqualsSyx(Item, kJB_SyxArg, false)) {
				Message* _tmPf0 = JB_Tk__UnTmpPlace(Result);
				JB_Incr(_tmPf0);
				Message* SubTmp = JB_Tk__Process(kJB__Tk_kTemporalWordColon, false, _tmPf0);
				JB_Incr(SubTmp);
				JB_Decr(_tmPf0);
				if (SubTmp or (JB_Msg_SyntaxEquals(Item, JB_LUB[491], false))) {
					JB_Decr(SubTmp);
					JB_Decr(Item);
					JB_SafeDecr(Result);
					return Result;
				}
				JB_Decr(SubTmp);
			}
			JB_Decr(Item);
			ThingFlags = (ThingFlags | kJB__Tk_kColonArg);
		};
	}
	Result->Func = kJB_SyxThg;
	if (JB_Ring_HasChildren(Result)) {
		JB_SafeDecr(Result);
		return Result;
	}
	JB_SetRef(Result, JB_Tk__DecorateThing(Result, kJB__Tk_kOpp));
	Message* _tmPf1 = JB_Tk__ParseItem(Result, kJB__Tk_kTemporalSyx, kJB__Tk_kOpp);
	JB_Incr(_tmPf1);
	JB_Decr(Result);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Message* JB_Tk__fTypeCast(int Start, Message* Parent) {
	Message* _tmPf0 = JB_Tk__BarThings(Start, kJB_SyxType);
	JB_Incr(_tmPf0);
	if (!_tmPf0) {
		JB_Decr(_tmPf0);
		return nil;
	}
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

Message* JB_Tk__fURL(int Start, Message* Parent) {
	if (!JB_Tk__NeedName(Parent)) {
		return nil;
	}
	JB_String* _tmPf0 = JB_Tk__GetData();
	(JB_Tk__NextStartSet(JB_Str_InWhite(_tmPf0, Start, JB_int__Max())));
	Parent->Func = kJB_Syxurl;
	Parent->RangeLength = (Parent->RangeLength + 3);
	Message* _tmPf1 = JB_Tk__NewParent(nil, kJB_SyxStr, Start + 3, JB_Tk__NextStart());
	JB_Incr(_tmPf1);
	JB_Tree_SyntaxAppend(Parent, _tmPf1);
	JB_Decr(_tmPf1);
	return Parent;
}

Message* JB_Tk__fXML(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	Ind EndPos = JB_Tk__XMLWordEnd(Start + 1);
	if (JB_Ind_SyntaxCast(EndPos)) {
		Message* XML = JB_Tk__NewSkip(nil, kJB_SyxXML, Start, Start + 1, EndPos);
		JB_Incr(XML);
		EndPos = JB_Tk__XMLAttribs(XML, EndPos);
		if (EndPos > 0) {
			JB_SetRef(Rz, JB_Tk__FillXML(XML, EndPos + 1));
			if (Rz) {
				(JB_Msg_AfterSet(Rz, JB_Tk__NextStart()));
			}
		}
		JB_Decr(XML);
	}
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fXML_Comment(int Start, Message* Parent) {
	return JB_Tk__XMLWhatever(Start, 4, JB_LUB[16], kJB_SyxXCom);
}

Message* JB_Tk__fXML_DocType(int Start, Message* Parent) {
	{
		JB_String* _tmPf4 = JB_Tk__GetData();
		IntRange _LoopSrcf2 = JB_int_OperatorTo(JB_Tk__NextStart(), JB_Str_Length(_tmPf4) - 1);
		int __Endf0 = _LoopSrcf2[1];
		int _Valuef3 = _LoopSrcf2[0];
		while (_Valuef3 < __Endf0) {
			int I = _Valuef3;
			JB_String* _tmPf5 = JB_Tk__GetData();
			uint C = JB_Str_ByteValue(_tmPf5, I);
			if (C == '[') {
				JB_String* _tmPf6 = JB_Tk__GetData();
				I = JB_Str_FindByte(_tmPf6, ']', I, JB_int__Max());
				if (!I) {
					return JB_Tk__ErrorAdd(JB_LUB[396], Start);
				}
			}
			 else if (C == '>') {
				(JB_Tk__NextStartSet(I + 1));
				JB_String* _tmPf8 = JB_Tk__GetData();
				JB_String* _tmPf7 = JB_Str_Range(_tmPf8, Start + 9, I);
				JB_Incr(_tmPf7);
				Message* _tmPf9 = JB_Tk__NewParentName(nil, kJB_SyxXCom, Start, _tmPf7);
				JB_Incr(_tmPf9);
				JB_Decr(_tmPf7);
				JB_SafeDecr(_tmPf9);
				return _tmPf9;
			}
			(++_Valuef3);
		};
	}
	;
	return nil;
}

Message* JB_Tk__fXML_PI(int Start, Message* Parent) {
	Message* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Tk__NewParentName(nil, kJB_SyxXPI, Start, JB_LUB[0]));
	JB_Tk__ParseLoopFlags(Rz, JB_LUB[233], kJB__Tk_kTemporal);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__fYoda(int Start, Message* Parent) {
	Message* Last = JB_Tk__ProcessThing(kJB__Tk_kOppSyx, true);
	JB_Incr(Last);
	Message* First = JB_Tk__ProcessThing(kJB__Tk_kOppSyx, true);
	JB_Incr(First);
	Message* Opp = JB_Tk__Process(kJB__Tk_kOpp, true, nil);
	JB_Incr(Opp);
	Message* Rel = JB_Tk__NewParentName(Parent, kJB_SyxYoda, Start, JB_LUB[0]);
	JB_Incr(Rel);
	JB_Tree_SyntaxAppend(Rel, First);
	JB_Decr(First);
	JB_Tree_SyntaxAppend(Rel, Opp);
	JB_Decr(Opp);
	JB_Tree_SyntaxAppend(Rel, Last);
	JB_Decr(Last);
	JB_SafeDecr(Rel);
	return Rel;
}

Message* JB_Tk__GetFuncAfter(Message* Result) {
	JB_Incr(Result);
	while (true) {
		uint ThisAfter = kJB__Tk_kFuncAfterAny & (~JB__Tk__StopBars);
		if (JB_Tk__NoFuncAfter(JB_Tk__NextByte())) {
			ThisAfter = (ThisAfter & (~kJB__Tk_kFuncAfterNoSpace));
		}
		Message* D = JB_Tk__Process(ThisAfter, false, Result);
		JB_Incr(D);
		if (!D) {
			JB_Decr(D);
			break;
		}
		Syntax Fn = D->Func;
		if ((Fn != kJB_SyxName) and ((Fn != kJB_SyxBadj) and (Fn != kJB_Syxurl))) {
			(JB_Ring_PrevSibSet(Result, D));
			(JB_Ring_FirstSet(D, Result));
		}
		JB_SetRef(Result, D);
		JB_Decr(D);
	};
	JB_SafeDecr(Result);
	return Result;
}

int JB_Tk__GotoEndOfLine(int From) {
	JB_String* _tmPf0 = JB_Tk__GetData();
	(JB_Tk__NextStartSet(JB_Str_Find(_tmPf0, JB__Constants_CSLine, From, JB_int__Max())));
	return JB_Tk__NextStart();
}

Message* JB_Tk__IndentBug(Message* Curr) {
	return JB_Tk__ErrorAlwaysAdd(JB_LUB[365], Curr->Position);
}

void JB_Tk__Init() {
	JB_Tk__TokenzFn(JB_LUB[513], kJB__Tk_kEndOfLine, ((FP_ParseHandler)(JB_Tk__fEndOfLine)));
	TokHan* _tmPf1 = JB_Tk__Handler(kJB__Tk_kComma | kJB__Tk_kEndOfLine, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fEndOfLine))));
	JB_Incr(_tmPf1);
	(JB_Tk__TokenSet(JB_LUB[514], _tmPf1));
	JB_Decr(_tmPf1);
	TokHan* _tmPf3 = JB_Tk__Handler(kJB__Tk_kColon, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fEndOfLine))));
	JB_Incr(_tmPf3);
	TokHan* _tmPf2 = JB_TH_Link(_tmPf3, kJB__Tk_kColonArg, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fArgColon))));
	JB_Incr(_tmPf2);
	JB_Decr(_tmPf3);
	(JB_Tk__TokenSet(JB_LUB[491], _tmPf2));
	JB_Decr(_tmPf2);
	JB_SetRef(JB__Tk__EndOfLineMarker, JB_Msg_ConstructorNormal(nil, kJB_SyxNil, JB_LUB[42]));
	Array* Numb = JB_Str_ByteSplit(JB_LUB[515]);
	JB_Incr(Numb);
	JB_String* Op_comp = JB_LUB[516];
	JB_Incr(Op_comp);
	JB_String* Op_math = JB_LUB[517];
	JB_Incr(Op_math);
	JB_String* PFix = JB_LUB[518];
	JB_Incr(PFix);
	TokHan* _tmPf6 = JB_Tk__Handler(kJB__Tk_kThingWord, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fThingWord))));
	JB_Incr(_tmPf6);
	TokHan* _tmPf5 = JB_TH_Link(_tmPf6, kJB__Tk_kTemporalWord, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fStatement))));
	JB_Incr(_tmPf5);
	JB_Decr(_tmPf6);
	TokHan* _tmPf4 = JB_TH_Link(_tmPf5, kJB__Tk_kTemporalWordColon, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fStatementColon))));
	JB_Incr(_tmPf4);
	JB_Decr(_tmPf5);
	TokHan* H = JB_TH_Link(_tmPf4, kJB__Tk_kOppWord, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fOppWord))));
	JB_Incr(H);
	JB_Decr(_tmPf4);
	Array* _tmPf7 = JB_CS_Bytes(JB__Constants_CSWordStart);
	JB_Incr(_tmPf7);
	JB_Tk__TokensHan(_tmPf7, H);
	JB_Decr(H);
	JB_Decr(_tmPf7);
	TokHan* _tmPf10 = JB_Tk__Handler(kJB__Tk_kFuncAfterNoSpace, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fFuncCall))));
	JB_Incr(_tmPf10);
	TokHan* _tmPf9 = JB_TH_Link(_tmPf10, kJB__Tk_kThingSyx, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fBracket))));
	JB_Incr(_tmPf9);
	JB_Decr(_tmPf10);
	TokHan* _tmPf8 = JB_TH_Link(_tmPf9, kJB__Tk_kOppBra, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fOppBracket))));
	JB_Incr(_tmPf8);
	JB_Decr(_tmPf9);
	(JB_Tk__TokenSet(JB_LUB[510], _tmPf8));
	JB_Decr(_tmPf8);
	TokHan* _tmPf12 = JB_Tk__Handler(kJB__Tk_kFuncAfterNoSpace, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fAccess))));
	JB_Incr(_tmPf12);
	TokHan* _tmPf11 = JB_TH_Link(_tmPf12, kJB__Tk_kThingSyx, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fArray))));
	JB_Incr(_tmPf11);
	JB_Decr(_tmPf12);
	(JB_Tk__TokenSet(JB_LUB[519], _tmPf11));
	JB_Decr(_tmPf11);
	TokHan* _tmPf13 = JB_Tk__Handler(kJB__Tk_kThingSyx, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fMsgList))));
	JB_Incr(_tmPf13);
	(JB_Tk__TokenSet(JB_LUB[132], _tmPf13));
	JB_Decr(_tmPf13);
	TokHan* _tmPf15 = JB_Tk__Handler(kJB__Tk_kFuncAfterNoSpace, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fDot))));
	JB_Incr(_tmPf15);
	TokHan* _tmPf14 = JB_TH_Link(_tmPf15, kJB__Tk_kThingSyx, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fSDot))));
	JB_Incr(_tmPf14);
	JB_Decr(_tmPf15);
	(JB_Tk__TokenSet(JB_LUB[21], _tmPf14));
	JB_Decr(_tmPf14);
	TokHan* _tmPf16 = JB_Tk__Handler(kJB__Tk_kFuncAfterNoSpace, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fDotAccess))));
	JB_Incr(_tmPf16);
	(JB_Tk__TokenSet(JB_LUB[520], _tmPf16));
	JB_Decr(_tmPf16);
	TokHan* _tmPf17 = JB_Tk__Handler(kJB__Tk_kFuncAfterNoSpace, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fURL))));
	JB_Incr(_tmPf17);
	(JB_Tk__TokenSet(JB_LUB[17], _tmPf17));
	JB_Decr(_tmPf17);
	TokHan* _tmPf20 = JB_Tk__Handler(kJB__Tk_kTemporalBar, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fDecl))));
	JB_Incr(_tmPf20);
	TokHan* _tmPf19 = JB_TH_Link(_tmPf20, kJB__Tk_kFuncAfterBar, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fTypeCast))));
	JB_Incr(_tmPf19);
	JB_Decr(_tmPf20);
	TokHan* _tmPf18 = JB_TH_Link(_tmPf19, kJB__Tk_kThingBar, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fDecl))));
	JB_Incr(_tmPf18);
	JB_Decr(_tmPf19);
	(JB_Tk__TokenSet(JB_LUB[490], _tmPf18));
	JB_Decr(_tmPf18);
	TokHan* _tmPf21 = JB_Tk__Handler(kJB__Tk_kThingSyx, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fArgName))));
	JB_Incr(_tmPf21);
	(JB_Tk__TokenSet(JB_LUB[521], _tmPf21));
	JB_Decr(_tmPf21);
	TokHan* _tmPf22 = JB_Tk__Handler(kJB__Tk_kTemporalSyx, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fTmpPlus))));
	JB_Incr(_tmPf22);
	(JB_Tk__TokenSet(JB_LUB[522], _tmPf22));
	JB_Decr(_tmPf22);
	TokHan* _tmPf24 = JB_Tk__Handler(kJB__Tk_kThingSyx, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fAtName))));
	JB_Incr(_tmPf24);
	TokHan* _tmPf23 = JB_TH_Link(_tmPf24, kJB__Tk_kFuncAfterNormal, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fAtNamedExp))));
	JB_Incr(_tmPf23);
	JB_Decr(_tmPf24);
	(JB_Tk__TokenSet(JB_LUB[523], _tmPf23));
	JB_Decr(_tmPf23);
	TokHan* _tmPf26 = JB_Tk__Handler(kJB__Tk_kFuncAfterNormal, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fAdjectiveThing))));
	JB_Incr(_tmPf26);
	TokHan* _tmPf25 = JB_TH_Link(_tmPf26, kJB__Tk_kAdjectiveOp, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fAdjectiveOp))));
	JB_Incr(_tmPf25);
	JB_Decr(_tmPf26);
	(JB_Tk__TokenSet(JB_LUB[59], _tmPf25));
	JB_Decr(_tmPf25);
	JB_Tk__TokenzFn(JB_LUB[524], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fBeforeRelMinus)));
	JB_Tk__TokenzFn(PFix, kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fBeforeRel)));
	JB_Tk__TokenzFn(PFix, kJB__Tk_kFuncAfterNormal, ((FP_ParseHandler)(JB_Tk__fAfterRel)));
	JB_Decr(PFix);
	JB_Tk__TokenzFn(JB_LUB[98], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fBeforeRel)));
	JB_Tk__TokenzFn(JB_LUB[525], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fArgOpen)));
	JB_Tk__TokenzFn(JB_LUB[526], kJB__Tk_kTmpOpp, ((FP_ParseHandler)(JB_Tk__fTemporalRelSyx)));
	JB_Tk__TokenzFn(JB_LUB[527], kJB__Tk_kTmpOpp, ((FP_ParseHandler)(JB_Tk__fSyntacticComment)));
	JB_Tk__TokenzFn(JB_LUB[528], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fOpAsThing)));
	JB_Tk__TokensFn(Numb, kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fNumber)));
	JB_Decr(Numb);
	JB_Tk__TokenzFn(JB_LUB[12], kJB__Tk_kTemporalSyxNoBar, ((FP_ParseHandler)(JB_Tk__fShebang)));
	JB_Tk__TokenzFn(JB_LUB[61], kJB__Tk_kEndOfLine, ((FP_ParseHandler)(JB_Tk__fCommentLine)));
	JB_Tk__TokenzFn(JB_LUB[529], kJB__Tk_kEndOfLine, ((FP_ParseHandler)(JB_Tk__fComment)));
	JB_Tk__TokenzFn(Op_comp, kJB__Tk_kOppSNB, ((FP_ParseHandler)(JB_Tk__fOppSyxNeq)));
	JB_Decr(Op_comp);
	JB_Tk__TokenzFn(Op_math, kJB__Tk_kOppSNB, ((FP_ParseHandler)(JB_Tk__fOppSyx)));
	JB_Decr(Op_math);
	JB_Tk__TokenzFn(JB_LUB[490], kJB__Tk_kOppBar, ((FP_ParseHandler)(JB_Tk__fOppSyx)));
	JB_Tk__TokenzFn(JB_LUB[22], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fThingSyx)));
	JB_Tk__TokenzFn(JB_LUB[82], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fString)));
	JB_Tk__TokenzFn(JB_LUB[85], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fChar)));
	JB_Tk__TokenzFn(JB_LUB[19], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fBackTick)));
	JB_Tk__TokenzFn(JB_LUB[10], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fSuperStr)));
	JB_Tk__TokenzFn(JB_LUB[47], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fBinary)));
	TokHan* _tmPf28 = JB_Tk__Handler(kJB__Tk_kFuncAfterNormal, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fBAdjectiveThing))));
	JB_Incr(_tmPf28);
	TokHan* _tmPf27 = JB_TH_Link(_tmPf28, kJB__Tk_kAdjectiveOp, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fBAdjectiveOp))));
	JB_Incr(_tmPf27);
	JB_Decr(_tmPf28);
	(JB_Tk__TokenSet(JB_LUB[530], _tmPf27));
	JB_Decr(_tmPf27);
	TokHan* _tmPf30 = JB_Tk__Handler(kJB__Tk_kTmpOpp, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fTemporalRel))));
	JB_Incr(_tmPf30);
	TokHan* _tmPf29 = JB_TH_Link(_tmPf30, kJB__Tk_kTemporalSyxNoBar, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fTemporalHashThing))));
	JB_Incr(_tmPf29);
	JB_Decr(_tmPf30);
	(JB_Tk__TokenSet(JB_LUB[531], _tmPf29));
	JB_Decr(_tmPf29);
	JB_Tk__TokenzFn(JB_LUB[532], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fInnerNiceAdj)));
	JB_Tk__TokenzFn(JB_LUB[533], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fYoda)));
	JB_Tk__TokenzFn(JB_LUB[138], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fQuoteLang)));
	JB_Tk__TokenzFn(JB_LUB[137], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fQuestion)));
	JB_Tk__TokenzFn(JB_LUB[225], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fAsk)));
	JB_Tk__TokenzFn(JB_LUB[102], kJB__Tk_kTemporalSyx, ((FP_ParseHandler)(JB_Tk__fXML)));
	JB_Tk__TokenzFn(JB_LUB[232], kJB__Tk_kTemporalSyx, ((FP_ParseHandler)(JB_Tk__fXML_PI)));
	JB_Tk__TokenzFn(JB_LUB[15], kJB__Tk_kTemporalSyx, ((FP_ParseHandler)(JB_Tk__fXML_Comment)));
	JB_Tk__TokenzFn(JB_LUB[534], kJB__Tk_kTemporalSyx, ((FP_ParseHandler)(JB_Tk__fXML_DocType)));
	JB_Tk__TokenzFn(JB_LUB[535], kJB__Tk_kEndContainer, ((FP_ParseHandler)(JB_Tk__fEndOfLine)));
	JB_Tk__TokenzFn(JB_LUB[536], kJB__Tk_kThingSyx, ((FP_ParseHandler)(JB_Tk__fError)));
	JB_Tk__TokenzFn(JB_LUB[537], kJB__Tk_kOppSyx, ((FP_ParseHandler)(JB_Tk__fError2)));
	TokHan* IllegalHandler = JB_Tk__Handler(-1, ((TokenHandler_fp)(((TokenHandler_fp)JB_Tk__fError))));
	JB_Incr(IllegalHandler);
	{
		int I = 0;
		while (I < 256) {
			JB_String* _tmPf31 = JB_Str__Byte(I);
			JB_Incr(_tmPf31);
			(JB_Tk__TokenNilSet(_tmPf31, IllegalHandler));
			JB_Decr(_tmPf31);
			(++I);
		};
	}
	;
	JB_Decr(IllegalHandler);
}

int JB_Tk__Init_() {
	{
		JB__Tk_Splitter = (&JB_Tk__Range);
		JB__Tk_Using = ((MessagePosition){});
	}
	;
	return 0;
}

int JB_Tk__InitCode_() {
	{
	}
	;
	JB__Tk_Using.Position = -1;
	return 0;
}

Message* JB_Tk__LoweredIndent(Message* Output, Message* Curr) {
	Ind BackPos = JB_Str_Find(JB_Tk__GetData(), JB__Constants_CSLine, Curr->Position, 0);
	int Chin = JB_Msg_CleanIndent(Curr);
	while (JB_Msg_IndentScore(Output) > Chin) {
		if (JB_Msg_EqualsSyx(Output, kJB_SyxArg, false)) {
			if (!JB_Msg_SyntaxIs(Output, kJB__MsgParseFlags_Style2)) {
				return JB_Tk__IndentBug(Curr);
			}
			if (BackPos > 0) {
				(JB_Msg_AfterSet(Output, BackPos));
			}
		}
		Output = ((Message*)JB_Ring_Parent(Output));
		if (!Output) {
			return JB_Tk__IndentBug(Curr);
		}
		if (JB_Msg_EqualsSyx(Output, kJB_SyxDecl, false)) {
			Output = ((Message*)JB_Ring_Parent(Output));
		}
	};
	JB_Tree_SyntaxAppend(Output, Curr);
	if (JB_Msg_CleanIndent(Curr) % 4) {
		return Curr;
	}
	return Output;
}

Message* JB_Tk__MakeInvisArg(Message* Tmp, int Indent) {
	Message* Rz = nil;
	if ((JB_Msg_EqualsSyx(Tmp, kJB_SyxItem, false))) {
		Message* Last = ((Message*)JB_Ring_Last(Tmp));
		if (!JB_Msg_EqualsSyx(Last, kJB_SyxEmb, false)) {
			return JB_Tk__UnexpectedSyntax(Last);
		}
		Last->Func = kJB_SyxArg;
		(JB_Msg_SyntaxIsSet(Last, kJB__MsgParseFlags_Style2, true));
		return Last;
	}
	Rz = JB_Tk__NewParentName(Tmp, kJB_SyxArg, Tmp->Position, JB_LUB[0]);
	(JB_Msg_SyntaxIsSet(Rz, kJB__MsgParseFlags_Style2, true));
	return Rz;
}

Message* JB_Tk__MakeRel(Message* First, int Bits) {
	Message* Opp = JB_Tk__Process(Bits, false, nil);
	if (!Opp) {
		return First;
	}
	Message* Rel = JB_Tk__NewParentName(nil, kJB_SyxRel, First->Position, JB_LUB[0]);
	JB_Tree_SyntaxAppend(Rel, First);
	JB_Tree_SyntaxAppend(Rel, Opp);
	if (JB_Tk__EatString(JB_LUB[242])) {
		Rel->Func = kJB_SyxERel;
		(++Opp->RangeLength);
	}
	bool Mode = kJB__Tk_kAllow;
	if (!JB_byte_IsLetter((JB_Str_First(Opp->Name)))) {
		Bits = (Bits | kJB__Tk_kOppWord);
	}
	JB_Tree_SyntaxAppend(Rel, JB_Tk__ProcessThing(Bits, Mode));
	(JB_Msg_AfterSet(Rel, JB_Msg_After(((Message*)JB_Ring_Last(Rel)))));
	return Rel;
}

int JB_Tk__MessageErrorSub(FastString* Fs, int Num) {
	Dictionary* E = JB__Tk__ErrorNames;
	JB_Incr(E);
	if (!E) {
		JB_SetRef(E, JB_Dict_Constructor(nil));
		JB_SetRef(JB__Tk__ErrorNames, E);
		(JB_Dict_SetInt(E, kJB__Tk_kTemporal, JB_LUB[188]));
		(JB_Dict_SetInt(E, kJB__Tk_kTemporalSyx, JB_LUB[189]));
		(JB_Dict_SetInt(E, kJB__Tk_kTemporalWord, JB_LUB[190]));
		(JB_Dict_SetInt(E, kJB__Tk_kEndOfLine, JB_LUB[191]));
		(JB_Dict_SetInt(E, kJB__Tk_kColon, JB_LUB[192]));
		(JB_Dict_SetInt(E, kJB__Tk_kOppSyx, JB_LUB[193]));
		(JB_Dict_SetInt(E, kJB__Tk_kOppWord, JB_LUB[193]));
		(JB_Dict_SetInt(E, kJB__Tk_kOpp, JB_LUB[193]));
		(JB_Dict_SetInt(E, kJB__Tk_kOppTemporal, JB_LUB[194]));
		(JB_Dict_SetInt(E, kJB__Tk_kThing, JB_LUB[195]));
		(JB_Dict_SetInt(E, kJB__Tk_kThingWord, JB_LUB[195]));
		(JB_Dict_SetInt(E, kJB__Tk_kThingSyx, JB_LUB[196]));
		(JB_Dict_SetInt(E, kJB__Tk_kIllegalChar, JB_LUB[197]));
	}
	if (Fs->Length) {
		JB_FS_AppendString(Fs, JB_LUB[198]);
	}
	 else {
		JB_FS_AppendString(Fs, JB_LUB[199]);
	}
	int BestValue = JB_Tk__FindError(Num);
	if (BestValue) {
		JB_String* S = ((JB_String*)JB_Dict_ValueInt(E, BestValue));
		JB_Incr(S);
		if (JB_Str_Exists(S)) {
			JB_FS_AppendString(Fs, S);
		}
		 else {
			JB_FS_AppendString(Fs, JB_LUB[200]);
		}
		JB_Decr(S);
		JB_Decr(E);
		return Num & (~BestValue);
	}
	JB_Decr(E);
	JB_FS_AppendString(Fs, JB_LUB[201]);
	return 0;
}

bool JB_Tk__NeedName(Message* Thg) {
	if ((JB_Msg_EqualsSyx(Thg, kJB_SyxThg, false))) {
		return true;
	}
	return ((bool)JB_FreeIfDead(JB_Tk__ErrorAdd(JB_LUB[383], Thg->Position)));
}

Message* JB_Tk__NewParentName(Message* Parent, Syntax Func, int Start, JB_String* Name) {
	Message* Rz = nil;
	Rz = JB_Msg_ConstructorRange(nil, Parent, Func, Start, Name, JB_Tk__NextStart() - Start);
	return Rz;
}

Message* JB_Tk__NewParent(Message* Parent, Syntax Func, int Start, int End) {
	Message* Rz = nil;
	JB_String* Name = JB_Tk__SyntaxAccess(Start, End, Func);
	Rz = JB_Msg_ConstructorRange(nil, Parent, Func, Start, Name, End - Start);
	return Rz;
}

Message* JB_Tk__NewEmpty(Message* P, Syntax F, int Start, int After) {
	Message* Rz = nil;
	Rz = JB_Msg_ConstructorRange(nil, P, F, Start, JB_LUB[0], After - Start);
	return Rz;
}

Message* JB_Tk__NewSkip(Message* P, Syntax F, int Start, int NameStart, int NameEnd) {
	Message* Rz = nil;
	JB_String* Name = JB_Tk__SyntaxAccess(NameStart, NameEnd, F);
	Rz = JB_Msg_ConstructorRange(nil, P, F, Start, Name, JB_Tk__NextStart() - Start);
	return Rz;
}

Message* JB_Tk__NewWord(Message* P, Syntax F, int Start, int SearchFrom) {
	Message* Rz = nil;
	int After = JB_Tk__WordAfter(SearchFrom);
	JB_String* Name = JB_Tk__SyntaxAccess(SearchFrom, After, F);
	Rz = JB_Msg_ConstructorRange(nil, P, F, Start, Name, After - Start);
	return Rz;
}

ParserLineAndIndent JB_Tk__NextLineAndIndent(Message* Parent) {
	ParserLineAndIndent Rz = ((ParserLineAndIndent){});
	int First = JB_Tk__NextStart();
	int N = First;
	JB_String* D = JB_Tk__GetData();
	int End = JB_Str_Length(D);
	byte* Addr = D->Addr;
	int State = 0;
	int Commas = 0;
	while (N < End) {
		uint C = Addr[N++];
		if (C == '\t') {
			Rz[2] = ((Rz[2] & (~3)) + (((!Commas)) << 2));
			if ((State & 1) and Rz[0]) {
				JB_FreeIfDead(JB_Tk__ErrorAdd(JB_LUB[384], N - 1));
			}
		}
		 else if (C == ',') {
			(++Commas);
			Message* L = ((Message*)JB_Ring_Last(Parent));
			if (L) {
				Rz[2] = L->Indent;
			}
			 else {
				Rz[2] = 0;
			}
			State = 0;
		}
		 else if (C == ' ') {
			State = (State | 1);
			if (Rz[3] != 3) {
				Rz[2] = (Rz[2] + (!Commas));
			}
			 else {
				if (Rz[2] < 4) {
					Rz[2] = (Rz[2] + (!Commas));
				}
				Rz[3] = 2;
			}
		}
		 else if (C == '/') {
			uint C2 = JB_Str_ByteValue(D, N);
			if ((C2 != '/') and (C2 != '*')) {
				if (State & 2) {
					if (Rz[3] > 1) {
						JB_FreeIfDead(JB_Tk__ErrorAdd(JB_LUB[385], N - 1));
					}
					Rz[3] = 3;
					Rz[2] = (Rz[2] + (!Commas));
					continue;
				}
				(--N);
				break;
			}
			State = 2;
			if (C2 != '*') {
				N = JB_Tk__GotoEndOfLine(N + 1);
				continue;
			}
			(++Rz[0]);
			Rz[2] = 0;
			(JB_Tk__NextStartSet(N - 1));
			Message* Line = JB_Tk__Process(kJB__Tk_kEndOfLine, kJB__Tk_kAllow, Parent);
			N = JB_Tk__NextStart();
			if (Line != JB__Tk__EndOfLineMarker) {
				break;
			}
		}
		 else {
			if ((C != '\n') and ((C != '\x0D') and (C != ';'))) {
				(--N);
				break;
			}
			(++Rz[0]);
			Rz[1] = (N - 1);
			Rz[2] = 0;
			Rz[3] = 0;
			Commas = 0;
			State = 2;
			if (Parent->Func == kJB_SyxList) {
				(JB_Msg_SyntaxIsSet(Parent, kJB__MsgParseFlags_Style2, true));
			}
		}
	};
	Rz[0] = (Rz[0] + Commas);
	(JB_Tk__NextStartSet(N));
	Rz[2] = (Rz[2] & (~1));
	if (((First > 0) and (!Rz[0])) or (Rz[2] < 0)) {
		Rz[2] = -1;
	}
	return Rz;
}

bool JB_Tk__NoFuncAfter(uint /*byte*/ B) {
	return (B == '\t') or ((B == ' ') or (B == '\\'));
}

Message* JB_Tk__NumberSub(int Start, int RealStart) {
	Message* Rz = nil;
	int After = JB_Tk__NumEnd(JB_Tk__GetData(), Start);
	(JB_Tk__NextStartSet(After));
	int StartAt = JB_Str_IsHexLike(JB_Tk__GetData(), Start);
	Ind UnitPos2 = -1;
	if (StartAt == 0) {
		UnitPos2 = JB_Str_OutCharSet(JB_Tk__GetData(), JB__Constants_CSLettersOnly, After, Start + StartAt);
	}
	if (!JB_Ind_SyntaxCast(UnitPos2)) {
		UnitPos2 = (After - 1);
	}
	(++UnitPos2);
	Message* Num = JB_Tk__NewParent(nil, kJB_SyxNum, RealStart, UnitPos2);
	if (After <= UnitPos2) {
		return Num;
	}
	Rz = JB_Tk__NewSkip(nil, kJB_SyxUnit, RealStart, UnitPos2, After);
	JB_Tree_SyntaxAppend(Rz, Num);
	return Rz;
}

int JB_Tk__NumEnd(JB_String* NumStr, int Start) {
	int Rz = 0;
	Ind Dot = JB_Str_OutCharSet(NumStr, JB__Constants_CSNum, Start, JB_int__Max());
	if (!JB_Ind_SyntaxCast(Dot)) {
		return JB_Str_Length(NumStr);
	}
	if (JB_Str_ByteValue(NumStr, Dot) != '.') {
		return Dot;
	}
	uint AfterDot = JB_Str_ByteValue(NumStr, Dot + 1);
	if (!JB_byte_IsInt(AfterDot)) {
		return Dot;
	}
	Rz = JB_Str_OutCharSet(NumStr, JB__Constants_CSNum, Dot + 1, JB_int__Max());
	if (!Rz) {
		Rz = JB_Str_Length(NumStr);
	}
	return Rz;
}

bool JB_Tk__OK() {
	return (!JB_Ind_SyntaxCast(JB_Tk__ErrorStart()));
}

Message* JB_Tk__OppChain(Message* Opp) {
	Message* Result = JB_Tk__Process(kJB__Tk_kAdjectiveOp, false, Opp);
	JB_Incr(Result);
	if (Result) {
		if (!JB_FreeIfDead(((Message*)JB_Ring_Parent(Opp)))) {
			(JB_Ring_FirstSet(Result, Opp));
		}
		JB_SafeDecr(Result);
		return Result;
	}
	JB_Decr(Result);
	return Opp;
}

void JB_Tk__Params(Message* Parent, int N) {
	Message* Result = JB_Tk__NewParentName(Parent, kJB_SyxPrm, N, JB_LUB[0]);
	JB_Incr(Result);
	JB_Tk__ParseLoopFlags(Result, JB_LUB[445], kJB__Tk_kTemporalSyxNoBar);
	JB_Decr(Result);
}

Message* JB_Tk__ParseItem(Message* Ch, int TemporalFlags, int Ops) {
	int Ns = JB_Tk__NextStart();
	if (!JB_Tk__Allow(kJB__Tk_kColon)) {
		return Ch;
	}
	if (JB_Msg_OperatorIn(Ch, kJB_SyxArg)) {
		if (JB_Msg_EqualsSyx(Ch, kJB_SyxThg, false)) {
			Ch->Func = kJB_SyxTmp;
			Message* _tmPf0 = JB_Tk__fArgColon(Ns, Ch);
			JB_Incr(_tmPf0);
			JB_Tree_SyntaxAppend(Ch, _tmPf0);
			JB_Decr(_tmPf0);
		}
		return Ch;
	}
	Message* Result = JB_Tk__NewParentName(nil, kJB_SyxItem, Ch->Position, JB_LUB[0]);
	JB_Incr(Result);
	JB_Tree_SyntaxAppend(Result, Ch);
	Message* Ch2 = JB_Tk__Process(TemporalFlags, false, Result);
	JB_Incr(Ch2);
	if (!Ch2) {
		JB_SetRef(Ch2, JB_Tk__ProcessThing(Ops, false));
	}
	if (!Ch2) {
		JB_SetRef(Ch2, JB_Tk__NewParentName(Result, kJB_SyxEmb, Ns, JB_LUB[0]));
	}
	JB_Tree_SyntaxAppend(Result, Ch2);
	(JB_Msg_AfterSet(Result, JB_Msg_After(Ch2)));
	JB_Decr(Ch2);
	JB_SafeDecr(Result);
	return Result;
}

int JB_Tk__ParseLoop(Message* Output, int TmpoFlags) {
	Message* Prev = nil;
	int LC = 0;
	while (Output) {
		ParserLineAndIndent Info = JB_Tk__NextLineAndIndent(Output);
		LC = (LC + Info[0]);
		if (JB_Tk__WillEnd()) {
			int Nxt = JB_Tk__NextStart();
			if (!JB_Tk__Running()) {
				Nxt = JB_Str_Length(JB_Tk__GetData());
			}
			return JB_Tk__FinishParseLoop(LC, Output, Nxt);
		}
		if (Prev and (!Info[0])) {
			return JB_Tk__FinishParseLoop(LC, Output, JB_Tk__NextStart() - 1);
		}
		Message* Ch = JB_Tk__ParseLoopItem(Output, TmpoFlags, Prev, Info[2]);
		if (!Ch) {
			return JB_Tk__FinishParseLoop(LC, Output, JB_Tk__NextStart() - 1);
		}
		if (Ch != Output) {
			LC = (LC + ((JB_Msg_EqualsSyx(Ch, kJB_SyxItem, false))));
			if (Info[3]) {
				(JB_Msg_SyntaxIsSet(Ch, kJB__MsgParseFlags_BreakPoint, true));
			}
			Output = JB_Tk__AddToOutput(Output, Ch, Prev, Info[1]);
			Prev = Ch;
		}
	};
	return LC;
}

bool JB_Tk__ParseLoopFlags(Message* Output, JB_String* Ender, int TmpFlags) {
	bool Rz = false;
	Ind Err = JB_Tk__NextStart();
	Rz = ((bool)JB_Tk__ParseLoop(Output, TmpFlags & (~JB__Tk__StopBars)));
	if (JB_Str_Exists(Ender)) {
		JB_Tk__ExpectEndChar(Err, Ender, true);
		(JB_Msg_AfterSet(Output, JB_Tk__NextStart()));
	}
	return Rz;
}

Message* JB_Tk__ParseLoopItem(Message* Output, int TmpoFlags, Message* Prev, int Indent) {
	Message* Ch = JB_Tk__Process(kJB__Tk_kTemporal & TmpoFlags, false, Output);
	JB_Incr(Ch);
	if ((!Ch)) {
		Message* Item = JB_Tk__ProcessThingParent(Output, kJB__Tk_kOpp, kJB__Tk_kThing);
		JB_Incr(Item);
		if ((!Item) or (Item == Output)) {
			JB_Decr(Ch);
			JB_SafeDecr(Item);
			return Item;
		}
		TmpoFlags = (TmpoFlags & (kJB__Tk_kTemporal & (~kJB__Tk_kTemporalWord)));
		JB_SetRef(Ch, JB_Tk__ParseItem(Item, TmpoFlags, kJB__Tk_kOpp));
		JB_Decr(Item);
	}
	 else if ((JB_Msg_EqualsSyx(Ch, kJB_SyxCnj, false)) or (JB_Msg_EqualsSyx(Ch, kJB_SyxSCnj, false))) {
		JB_SetRef(Ch, JB_Tk__ReRoute(Output, Ch, Prev));
		if (!Ch) {
			JB_Decr(Ch);
			return nil;
		}
		Message* _tmPf0 = ((Message*)JB_Ring_First(Ch));
		JB_Incr(_tmPf0);
		Indent = _tmPf0->Indent;
		JB_Decr(_tmPf0);
	}
	Ch->Indent = Indent;
	JB_SafeDecr(Ch);
	return Ch;
}

Message* JB_Tk__PostInnerAdj(Message* Rel, Message* Opp) {
	JB_Incr(Rel);
	Message* F = ((Message*)JB_Ring_First(Rel));
	JB_Incr(F);
	if ((!((JB_Msg_EqualsSyx(Rel, kJB_SyxRel, false)))) and (!((JB_Msg_EqualsSyx(Rel, kJB_SyxBra, false)) and (JB_Msg_EqualsSyx(F, kJB_SyxRel, false))))) {
		Message* _tmPf1 = JB_Tk__ErrorAdd(JB_LUB[386], Rel->Position);
		JB_Incr(_tmPf1);
		JB_Decr(Rel);
		JB_Decr(F);
		JB_SafeDecr(_tmPf1);
		return _tmPf1;
	}
	if (JB_Msg_EqualsSyx(Rel, kJB_SyxBra, false)) {
		JB_SetRef(Rel, F);
		JB_SetRef(F, ((Message*)JB_Ring_First(F)));
	}
	Message* Adverb = JB_Tk__Process(kJB__Tk_kOppWord | kJB__Tk_kOppBra, kJB__Tk_kExpect, nil);
	JB_Incr(Adverb);
	if (!Adverb) {
		JB_Decr(Rel);
		JB_Decr(Adverb);
		JB_Decr(F);
		return nil;
	}
	Message* Adj = JB_Syx_Msg(kJB_SyxAdj, JB_LUB[0]);
	JB_Incr(Adj);
	(JB_Ring_NextSibSet(F, Adj));
	JB_Decr(F);
	JB_Tree_SyntaxAppend(Adj, Adverb);
	JB_Decr(Adverb);
	Message* _tmPf0 = ((Message*)JB_Ring_NextSib(Adj));
	JB_Incr(_tmPf0);
	JB_Tree_SyntaxAppend(Adj, _tmPf0);
	JB_Decr(Adj);
	JB_Decr(_tmPf0);
	Rel->Func = kJB_Syxpinn;
	JB_SafeDecr(Rel);
	return Rel;
}

Message* JB_Tk__ProcessThing(int Ops, bool Expect) {
	return JB_Tk__ProcessThingSub(nil, Ops, kJB__Tk_kThing, Expect);
}

Message* JB_Tk__ProcessThingNoBar(int Ops, bool Expect) {
	return JB_Tk__ProcessThingSub(nil, Ops, kJB__Tk_kThingSyx | kJB__Tk_kThingWord, Expect);
}

Message* JB_Tk__ProcessThingOrTmp(int Opps) {
	return JB_Tk__ProcessThingSub(nil, Opps, kJB__Tk_kThingSyx | (kJB__Tk_kThingWord | kJB__Tk_kTemporalSyx), false);
}

Message* JB_Tk__ProcessThingParent(Message* Parent, int Ops, int ThingFlags) {
	return JB_Tk__ProcessThingSub(Parent, Ops, ThingFlags, false);
}

Message* JB_Tk__ProcessThingSub(Message* Parent, int Ops, int KindOfThing, bool Expect) {
	Message* Result = JB_Tk__Process(KindOfThing, Expect, Parent);
	JB_Incr(Result);
	if ((!Result) or ((Result == Parent) or JB_Tk__WillEnd())) {
		JB_SafeDecr(Result);
		return Result;
	}
	Message* _tmPf0 = JB_Tk__DecorateThing(Result, Ops);
	JB_Incr(_tmPf0);
	JB_Decr(Result);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

Message* JB_Tk__ReRoute(Message* Output, Message* Cnj, Message* F) {
	Message* Rz = nil;
	JB_Incr(Rz);
	if ((!F)) {
		JB_Decr(Rz);
		return JB_Tk__ErrorAdd(JB_LUB[485], JB_Tk__NextStart());
	}
	JB_SetRef(Rz, JB_Tk__ChainTemporalRels(F, Cnj));
	if (JB_Ring_HasChildCount(Rz, 2) and JB_Tk__Allow(kJB__Tk_kEndOfLine)) {
		Message* _tmPf0 = JB_Tk__ProcessThing(kJB__Tk_kOpp, false);
		JB_Incr(_tmPf0);
		JB_Tree_SyntaxAppend(Rz, _tmPf0);
		JB_Decr(_tmPf0);
	}
	JB_Tree_SyntaxAppend(Output, Rz);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Tk__ThingXMLAtt(int Start, Message* Parent) {
	int Name = JB_Tk__WordAfterSub(Start, JB__Constants_XMLWordMiddle);
	return JB_Tk__NewParent(Parent, kJB_SyxXAtt, Start, Name);
}

void JB_Tk__TokensFn(Array* Arr, int Bits, FP_ParseHandler Func) {
	TokHan* _tmPf0 = JB_Tk__Handler(Bits, ((TokenHandler_fp)(((TokenHandler_fp)Func))));
	JB_Incr(_tmPf0);
	JB_Tk__TokensHan(Arr, _tmPf0);
	JB_Decr(_tmPf0);
}

void JB_Tk__TokensHan(Array* Arr, TokHan* H) {
	{
		int _if0 = 0;
		while (true) {
			JB_String* S = ((JB_String*)JB_Array_Value(Arr, _if0));
			JB_Incr(S);
			if (S == nil) {
				JB_Decr(S);
				break;
			}
			(JB_Tk__TokenSet(S, H));
			JB_Decr(S);
			(++_if0);
		};
	};
}

void JB_Tk__TokenzFn(JB_String* S, int Bits, FP_ParseHandler Func) {
	if (JB_Str_ContainsString(S, JB_LUB[23])) {
		Array* _tmPf0 = JB_Str_Words(S);
		JB_Incr(_tmPf0);
		JB_Tk__TokensFn(_tmPf0, Bits, ((FP_ParseHandler)(Func)));
		JB_Decr(_tmPf0);
	}
	 else {
		TokHan* _tmPf1 = JB_Tk__Handler(Bits, ((TokenHandler_fp)(((TokenHandler_fp)Func))));
		JB_Incr(_tmPf1);
		(JB_Tk__TokenSet(S, _tmPf1));
		JB_Decr(_tmPf1);
	}
}

Message* JB_Tk__UnexpectedSyntax(Message* Bad) {
	return JB_Tk__ErrorAdd(JB_LUB[387], Bad->Position);
}

Message* JB_Tk__UnTmpPlace(Message* R) {
	Message* P = ((Message*)JB_Ring_Parent(R));
	return ((Message*)JB_Ternary((JB_Msg_EqualsSyx(P, kJB_SyxTmp, false)), P, R));
}

bool JB_Tk__WillEnd() {
	return JB_Tk__CheckEnded(kJB__Tk_kEnd);
}

int JB_Tk__WordAfter(int Start) {
	return JB_Tk__WordAfterSub(Start, JB__Constants_CSWordMiddle);
}

int JB_Tk__WordAfterSub(int Start, CharSet* Cs) {
	int N = JB_Str_Length(JB_Tk__GetData());
	if (Start < N) {
		Ind After = JB_Str_OutCharSet(JB_Tk__GetData(), Cs, Start, JB_int__Max());
		if (!JB_Ind_SyntaxCast(After)) {
			After = N;
		}
		if (After > Start) {
			(JB_Tk__NextStartSet(After));
			return After;
		}
	}
	JB_Tk__ErrorLetter(Start);
	return 0;
}

int JB_Tk__XMLAttribs(Message* XML, int Start) {
	Message* AllAtts = JB_Tk__NewParentName(XML, kJB_SyxList, Start, JB_LUB[0]);
	JB_Incr(AllAtts);
	JB_String* S = JB_Tk__GetData();
	JB_Incr(S);
	while (true) {
		Ind I = JB_Str_OutWhite(S, JB_Tk__NextStart(), JB_int__Max());
		if (!JB_Ind_SyntaxCast(I)) {
			break;
		}
		uint C = JB_Str_ByteValue(S, I);
		if ((C == '>') or ((C == '/') and (JB_Str_ByteValue(S, I + 1) == '>'))) {
			JB_Decr(S);
			JB_Decr(AllAtts);
			return I;
		}
		if (!JB_CS_HasChar(JB__Constants_CSWordStart, C)) {
			break;
		}
		Message* Attr = JB_Tk__ThingXMLAtt(I, AllAtts);
		JB_Incr(Attr);
		if (!JB_Tk__ExpectEndChar(JB_Tk__NextStart(), JB_LUB[242], true)) {
			JB_Decr(Attr);
			JB_Decr(S);
			JB_Decr(AllAtts);
			return 0;
		}
		I = JB_Tk__CleanSpaces();
		C = JB_Str_ByteValue(S, I);
		if (!((C == '\'') or (C == '"'))) {
			JB_FreeIfDead(JB_Tk__ErrorAdd(JB_LUB[478], I));
			JB_Decr(Attr);
			JB_Decr(S);
			JB_Decr(AllAtts);
			return nil;
		}
		Ind After = JB_Str_FindByte(S, C, I + 1, JB_int__Max());
		Message* Txt = JB_Tk__NewParentName(Attr, kJB_SyxXTxt, Start, JB_LUB[0]);
		JB_Incr(Txt);
		JB_Decr(Attr);
		JB_String* _tmPf0 = JB_Str_Range(S, I + 1, After);
		JB_Incr(_tmPf0);
		JB_SetRef(Txt->Name, JB_Str_MultiReplaceAll(_tmPf0, JB__Constants_XML_UnEscapeStr, JB_StdErr));
		JB_Decr(Txt);
		JB_Decr(_tmPf0);
		(JB_Tk__NextStartSet(After + 1));
	};
	JB_Decr(AllAtts);
	JB_Decr(S);
	JB_FreeIfDead(JB_Tk__ErrorAdd(JB_LUB[479], JB_Tk__NextStart()));
	return 0;
}

Message* JB_Tk__XMLWhatever(int S, int Skip, JB_String* Ender, Syntax Fn) {
	Message* Rz = nil;
	JB_Incr(Rz);
	int I = S + Skip;
	JB_String* _tmPf0 = JB_Tk__GetData();
	Ind EndPos = JB_Str_InStr(_tmPf0, Ender, I, JB_int__Max(), false);
	if ((!JB_Ind_SyntaxCast(EndPos))) {
		JB_Decr(Rz);
		return JB_Tk__ErrorAdd(JB_LUB[388], I);
	}
	(JB_Tk__NextStartSet(EndPos + JB_Str_Length(Ender)));
	if (Fn) {
		JB_String* _tmPf2 = JB_Tk__GetData();
		JB_String* _tmPf1 = JB_Str_Range(_tmPf2, I, EndPos);
		JB_Incr(_tmPf1);
		JB_SetRef(Rz, JB_Tk__NewParentName(nil, Fn, I, _tmPf1));
		JB_Decr(_tmPf1);
		Rz->Position = S;
		(JB_Msg_AfterSet(Rz, JB_Tk__NextStart()));
	}
	JB_SafeDecr(Rz);
	return Rz;
}

Ind JB_Tk__XMLWordEnd(int From) {
	Ind Rz = -1;
	JB_String* _tmPf0 = JB_Tk__GetData();
	uint B = JB_Str_ByteValue(_tmPf0, From);
	if (!JB_CS_HasChar(JB__Constants_CSWordStart, B)) {
		JB_FreeIfDead(JB_Tk__ErrorAdd(JB_LUB[389], From));
	}
	 else {
		JB_String* _tmPf1 = JB_Tk__GetData();
		Rz = JB_Str_OutCharSet(_tmPf1, JB__Constants_XMLWordMiddle, From + 1, JB_int__Max());
		if (Rz == -1) {
			JB_FreeIfDead(JB_Tk__ErrorAdd(JB_LUB[390], JB_Tk__NextStart()));
		}
		(JB_Tk__NextStartSet(Rz));
	}
	return Rz;
}


int JB_zalgo__Init_() {
	{
		JB__zalgo_R = ((Random){});
	}
	;
	return 0;
}



void JB_bool_Append(bool Self, FastString* Fs_in) {
	JB_FS_AppendString(Fs_in, JB_bool_Render0(Self));
}

JB_String* JB_bool_Render0(bool Self) {
	return ((JB_StringC*)JB_Ternary(Self, JB_LUB[27], JB_LUB[28]));
}


bool JB_byte_CanPrintAsNormalChar(uint /*byte*/ Self) {
	return ((Self < 127) and (Self >= 32));
}

bool JB_byte_IsInt(uint /*byte*/ Self) {
	return ((uint)(((int)Self) - '0')) <= 9;
}

bool JB_byte_IsLetter(uint /*byte*/ Self) {
	return JB_CP_IsLetter(((Codepoint)Self));
}

bool JB_byte_IsTextLine(uint /*byte*/ Self) {
	return (Self == '\n') or (Self == '\x0D');
}

bool JB_byte_IsUpper(uint /*byte*/ Self) {
	return JB_CP_IsUpper(((Codepoint)Self));
}

bool JB_byte_IsWhite(uint /*byte*/ Self) {
	return JB_CP_IsWhite(((Codepoint)Self));
}

byte JB_byte_LowerCase(uint /*byte*/ Self) {
	if (JB_byte_IsUpper(Self)) {
		return Self + 32;
	}
	return Self;
}

JB_String* JB_byte_Render(uint /*byte*/ Self, FastString* Fs_in) {
	if ((!Fs_in)) {
		return JB_Str__Byte(Self);
	}
	JB_FS_AppendByte(Fs_in, ((byte)Self));
	return JB_LUB[0];
}




float JB_f_Pow(float Self, int N) {
	float Rz = 0.0f;
	//visible;
	Rz = Self;
	{
		int _Valuef1 = 0;
		while (_Valuef1 < N) {
			Rz = (Rz * Self);
			(++_Valuef1);
		};
	}
	;
	return Rz;
}



int JB_int_LowestBit(int Self) {
	return Self & (-Self);
}

int JB_int_OperatorAlign(int Self, int To) {
	if (To) {
		int Missing = (Self % To);
		if (Missing) {
			return Self + (To - Missing);
		}
		return Self;
	}
	return Self;
}

bool JB_int_OperatorIsa(int Self, uint N) {
	return (!(Self % N));
}

int JB_int_OperatorMax(int Self, int Other) {
	if (Self > Other) {
		return Self;
	}
	return Other;
}

int JB_int_OperatorMin(int Self, int Other) {
	if (Self < Other) {
		return Self;
	}
	return Other;
}

JB_String* JB_int_operatorof(int Self, JB_String* Type, JB_String* Nothing) {
	return JB_Str_Pluralize(Type, Self, Nothing);
}

IntRange JB_int_OperatorTo(int Self, int Other) {
	return ((IntRange)ivec2{Self, Other + 1});
}

int JB_int__Max() {
	return 2147483647;
}



JB_String* JB_int64_Render(int64 Self, FastString* Fs_in) {
	FastString* Fs = JB_FS__FastNew(Fs_in);
	JB_Incr(Fs);
	JB_FS_AppendInt64(Fs, Self);
	JB_String* _tmPf0 = JB_FS_SmartResult(Fs, Fs_in);
	JB_Incr(_tmPf0);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}












int JB_CharProp__Init_() {
	{
	}
	;
	return 0;
}


bool JB_CP_In(Codepoint Self, int A, int B) {
	return ((uint)(Self - A)) <= ((uint)(B - A));
}

bool JB_CP_IsHigher(Codepoint Self) {
	return JB_CP_In(Self, 128, 1114111);
}

bool JB_CP_IsLetter(Codepoint Self) {
	return JB_CP_IsUpper(Self) or (JB_CP_IsLower(Self) or JB_CP_IsHigher(Self));
}

bool JB_CP_IsLower(Codepoint Self) {
	return JB_CP_In(Self, 'a', 'z');
}

bool JB_CP_IsUpper(Codepoint Self) {
	return JB_CP_In(Self, 'A', 'Z');
}

bool JB_CP_IsWhite(Codepoint Self) {
	return (Self == ' ') or ((Self == '\n') or ((Self == '\x0D') or (Self == '\t')));
}






bool JB_TC_IsFloat(uint /*DataTypeCode*/ Self) {
	return ((bool)((Self >> 7) & 1));
}

bool JB_TC_IsNumeric(uint /*DataTypeCode*/ Self) {
	return ((bool)(Self & kJB__TC_Numeric));
}






JB_String* JB_ErrorSeverity_Render(uint /*ErrorSeverity*/ Self, FastString* Fs_in) {
	if (Self < kJB__ErrorSeverity_MaxError) {
		Array* _tmPf0 = JB_ErrorSeverity__InitNames();
		JB_Incr(_tmPf0);
		JB_String* Name = ((JB_String*)JB_Array_Value(_tmPf0, ((int)Self)));
		JB_Incr(Name);
		JB_Decr(_tmPf0);
		if (!Fs_in) {
			if (Name != nil) {
				JB_SafeDecr(Name);
				return Name;
			}
			JB_Decr(Name);
			return JB_LUB[0];
		}
		if (JB_Str_Exists(Name)) {
			JB_FS_AppendString(Fs_in, Name);
		}
		JB_Decr(Name);
	}
	return JB_LUB[0];
}

int JB_ErrorSeverity__Init_() {
	{
		JB_SetRef(JB__ErrorSeverity__names, JB_Array_Constructor0(nil));
	}
	;
	return 0;
}

Array* JB_ErrorSeverity__InitNames() {
	return ({
		Array* _X = JB__ErrorSeverity__names;
		if (!JB_Array_SyntaxCast(_X)) {
			_X = JB_Str_Words(JB_LUB[243]);
			JB_SetRef(JB__ErrorSeverity__names, _X);
		}
		 _X;
	});
}














int JB_Rg_Width(IntRange Self) {
	return Self[1] - Self[0];
}












bool JB_Syx_IsString(Syntax Self) {
	return (Self >= kJB_SyxSStr) and (Self <= kJB_SyxStr);
}

bool JB_Syx_ListViewable(Syntax Self) {
	return JB_Syx_Translateable(Self) or JB_Syx_IsString(Self);
}

JB_String* JB_Syx_LongName(Syntax Self) {
	if (Self) {
		SyntaxObj* O = JB_Syx_Obj(Self);
		if (O) {
			return O->LongName;
		}
	}
	return JB_LUB[26];
}

Message* JB_Syx_Msg(Syntax Self, JB_String* Name) {
	return JB_Msg_ConstructorRange(nil, nil, Self, JB__Tk_Using.Position, Name, JB_Str_Length(Name));
}

JB_String* JB_Syx_Name(Syntax Self) {
	if (Self) {
		SyntaxObj* O = JB_Syx_Obj(Self);
		if (O) {
			return O->Name;
		}
	}
	return JB_LUB[26];
}

SyntaxObj* JB_Syx_Obj(Syntax Self) {
	return JB__Constants__FuncArray[((int)Self)];
}

FP_fpMsgRender JB_Syx_RenderAddr(Syntax Self) {
	return ((FP_fpMsgRender)(JB_Syx_Obj(Self)->RenderAddr));
}

bool JB_Syx_Translateable(Syntax Self) {
	return (Self <= kJB_SyxThg) and (Self >= kJB_SyxTmp);
}

Syntax JB_Syx__Func(JB_String* Name, Message* Where) {
	//visible;
	if (Name != nil) {
		SyntaxObj* Obj = ((SyntaxObj*)JB_Dict_ValueLower(JB__Constants__SyxDict, Name));
		JB_Incr(Obj);
		if (!Obj) {
			JB_String* _tmPf0 = JB_Str_OperatorPlus(JB_LUB[441], Name);
			JB_Incr(_tmPf0);
			JB_Msg_Fail(Where, _tmPf0);
			JB_Decr(_tmPf0);
			JB_Decr(Obj);
			return nil;
		}
		Syntax _tmPf1 = Obj->ID;
		JB_Decr(Obj);
		return _tmPf1;
	}
	return nil;
}

int JB_Syx__Init_() {
	{
	}
	;
	return 0;
}

Syntax JB_Syx__StdNew(FP_fpMsgRender Msg, JB_String* Name, JB_String* LongName, int ID) {
	SyntaxObj* Result = JB_Fn_Constructor(nil, ((FP_fpMsgRender)(Msg)), Name, ID);
	JB_Incr(Result);
	(JB_Dict_ValueSet(JB__Constants__SyxDict, Name, Result));
	JB_SetRef(JB__Constants__FuncArray[ID], Result);
	if (((JB_String*)JB_Str_Exists(LongName))) {
		(JB_Dict_ValueSet(JB__Constants__SyxDict, LongName, Result));
		JB_SetRef(Result->LongName, LongName);
	}
	 else {
		JB_SetRef(Result->LongName, Name);
	}
	JB_Decr(Result);
	return ((Syntax)ID);
}



























JB_MemoryLayer* JB_ClassData_CreateUseLayer(JB_Class* Self, JB_Object* Obj, JB_Object* Obj2) {
	JB_MemoryLayer* Rz = nil;
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Mem_CreateLayer(Self, Obj));
	JB_Mem_Use(Rz);
	JB_SetRef(Rz->Obj2, Obj2);
	JB_SafeDecr(Rz);
	return Rz;
}

void JB_ClassData_Restore(JB_Class* Self) {
	JB_MemoryLayer* _tmPf0 = JB_Class_DefaultLayer(Self);
	JB_Incr(_tmPf0);
	JB_Mem_Use(_tmPf0);
	JB_Decr(_tmPf0);
}


void JB_MzSt_End(CompressionStats* Self) {
}

void JB_MzSt_LiveUpdate(CompressionStats* Self, int S, int Outt, bool Compress) {
}

CompressionStats* JB_MzSt_Start(CompressionStats* Self) {
	if (!Self) {
		return (&JB__MzSt_all);
	}
	return Self;
}

int JB_MzSt__Init_() {
	{
		JB__MzSt_all = ((CompressionStats){});
	}
	;
	return 0;
}




byte JB_FastBuff_Byte(FastBuff* Self) {
	return Self->Curr++[0];
}

byte* JB_FastBuff_Clip(FastBuff* Self, int V, int Reduce) {
	if (V <= 0) {
		return Self->Start;
	}
	V = JB_int_OperatorMin(V, (JB_FastBuff_Size(Self) - Reduce));
	return Self->Start + V;
}

int JB_FastBuff_CopyTo(FastBuff* Self, byte* Dest, int Length) {
	int Rz = 0;
	byte* A = Self->Curr;
	if (!((A < Self->End) and (Length > 0))) {
		return 0;
	}
	byte* B = A + Length;
	if (B > Self->End) {
		B = Self->End;
	}
	Rz = (B - A);
	Self->Curr = B;
	memcpy(Dest, A, Rz);
	return Rz;
}

void JB_FastBuff_Destructor(FastBuff* Self) {
	if (Self->Owns) {
		JB_Free(Self->Start);
	}
	JB_Clear(Self->ReadFrom);
}

bool JB_FastBuff_Has(FastBuff* Self, int N) {
	return (Self->End - Self->Curr) >= N;
}

bool JB_FastBuff_HasAny(FastBuff* Self) {
	return Self->End > Self->Curr;
}

int JB_FastBuff_Length(FastBuff* Self) {
	if (Self) {
		return JB_FastBuff_Position(Self);
	}
	return 0;
}

int JB_FastBuff_Position(FastBuff* Self) {
	return ((int)(Self->Curr - Self->Start));
}

void JB_FastBuff_PositionSet(FastBuff* Self, int Value) {
	byte* C = Self->Start + Value;
	if ((C < Self->Start) or (C > Self->End)) {
		if (true) {
			JB_FastBuff_SyntaxExpect(Self, JB_LUB[458]);
		}
		C = Self->End;
	}
	Self->Curr = C;
}

void JB_FastBuff_ReadFromSet(FastBuff* Self, JB_String* Value) {
	JB_SetRef(Self->ReadFrom, Value);
	Self->Start = Value->Addr;
	Self->End = (Self->Start + JB_Str_Length(Value));
	Self->Curr = Self->Start;
}

int JB_FastBuff_Remaining(FastBuff* Self) {
	return ((int)(Self->End - Self->Curr));
}

int JB_FastBuff_Size(FastBuff* Self) {
	if (Self) {
		return Self->End - Self->Start;
	}
	return 0;
}

JB_String* JB_FastBuff_AccessStr(FastBuff* Self, int Pos, int After) {
	JB_String* R = Self->ReadFrom;
	if (R != nil) {
		return JB_Str_Range(R, Pos, After);
	}
	byte* A = JB_FastBuff_Clip(Self, Pos, 1);
	byte* B = JB_FastBuff_Clip(Self, After, 0);
	if (B >= A) {
		return JB_Str_CopyFromPtr(A, B - A);
	}
	return JB_LUB[0];
}

void JB_FastBuff_SyntaxExpect(FastBuff* Self, JB_String* S) {
	if (!Self->WentBad) {
		if (true) {
			JB_Str_Fail(S);
		}
	}
	Self->WentBad = true;
}






void JB_MsgPos_Destructor(MessagePosition* Self) {
	JB__Tk_Using = (Self)[0];
	JB_Mem_Use(Self->Layer);
}

void JB_MsgPos_SyntaxUsingComplete(MessagePosition* Self, JB_Object* Idk) {
}


void JB_LD_Destructor(ObjectLoader* Self) {
	JB_Clear(Self->Result);
}

bool JB_LD_HasItem(ObjectLoader* Self) {
	return ((bool)Self->CurrItem);
}

int64 JB_LD_Int(ObjectLoader* Self) {
	Message* C = JB_LD_Next(Self);
	if (C) {
		return JB_Msg_Int(C, 0);
	}
	return 0;
}

int64 JB_LD_ItemInt(ObjectLoader* Self) {
	Message* C = Self->CurrItem;
	if (!C) {
		return 0;
	}
	Self->CurrItem = ((Message*)JB_Ring_NextSib(C));
	return JB_Msg_Int(((Message*)JB_Ring_Last(C)), 0);
}

bool JB_LD_ItemIsInt(ObjectLoader* Self) {
	Message* C = Self->CurrItem;
	return ((JB_Msg_EqualsSyx(((Message*)JB_Ring_Last(C)), kJB_SyxNum, false)));
}

JB_String* JB_LD_ItemName(ObjectLoader* Self) {
	Message* C = Self->CurrItem;
	return JB_Str_Unshare(JB_Msg_FirstName(C));
}

JB_Object* JB_LD_ItemObject(ObjectLoader* Self) {
	Message* C = Self->CurrItem;
	if (!C) {
		return nil;
	}
	Self->CurrItem = ((Message*)JB_Ring_NextSib(C));
	return JB_LD_ObjectSub(Self, ((Message*)JB_Ring_Last(C)));
}

Message* JB_LD_Next(ObjectLoader* Self) {
	Message* C = Self->CurrItem;
	if (C) {
		Self->CurrItem = ((Message*)JB_Ring_NextSib(C));
		return C;
	}
	return nil;
}

JB_Object* JB_LD_Object(ObjectLoader* Self) {
	return JB_LD_ObjectSub(Self, JB_LD_Next(Self));
}

JB_Object* JB_LD_ObjectSub(ObjectLoader* Self, Message* C) {
	if ((JB_Msg_EqualsSyx(C, kJB_SyxThg, false))) {
		return JB_Dict_Value0(Self->Dict, C->Name);
	}
	 else if ((JB_Msg_EqualsSyx(C, kJB_SyxStr, false))) {
		return JB_Str_Unshare(C->Name);
	}
	return nil;
}

JB_String* JB_LD_String(ObjectLoader* Self) {
	Message* C = JB_LD_Next(Self);
	if (!C) {
		return JB_LUB[0];
	}
	return JB_Str_Unshare(C->Name);
}

int JB_LD__Init_() {
	{
	}
	;
	return 0;
}


void JB_Saver_AppendInt(ObjectSaver* Self, int64 I) {
	JB_FS_AppendInt64(Self->Dest, I);
	JB_FS_AppendByte(Self->Dest, ',');
}

void JB_Saver_AppendObject(ObjectSaver* Self, JB_Object* O) {
	JB_FS_AppendObjectOrNil(Self->Dest, O);
	JB_FS_AppendByte(Self->Dest, ',');
}

void JB_Saver_AppendString(ObjectSaver* Self, JB_String* S) {
	JB_FS_AppendByte(Self->Dest, '`');
	JB_FreeIfDead(JB_Str_ReplaceAll(S, JB_LUB[19], JB_LUB[20], false, Self->Dest));
	JB_FS_AppendByte(Self->Dest, '`');
	JB_FS_AppendByte(Self->Dest, ',');
}

void JB_Saver_Destructor(ObjectSaver* Self) {
	if (Self->CantSaveThis) {
		JB_Object_FailStr(Self->CantSaveThis, JB_LUB[433]);
	}
	JB_Clear(Self->Dest);
}

int JB_Saver__Init_() {
	{
	}
	;
	return 0;
}








void JB_Rnd_LoadProperties(Random* Self, ObjectLoader* Loader) {
	//visible;
	Self->Store = ((uint64)JB_LD_Int(Loader));
	Self->State = ((uint64)JB_LD_Int(Loader));
}

void JB_Rnd_SaveWrite(Random* Self, ObjectSaver* Saver) {
	//visible;
	JB_Saver_AppendInt(Saver, Self->Store);
	JB_Saver_AppendInt(Saver, Self->State);
}

void JB_Rnd_SeedSet(Random* Self, uint64 Value) {
	Self->Store = Value;
	Self->State = 1;
}

void JB_Rnd_TimeSeed(Random* Self) {
	(JB_Rnd_SeedSet(Self, JB_Date__Now()));
}

int JB_Rnd__Init_() {
	{
		JB__Rnd_Shared = ((Random){});
	}
	;
	return 0;
}

int JB_Rnd__InitCode_() {
	{
	}
	;
	JB_Rnd_TimeSeed((&JB__Rnd_Shared));
	return 0;
}






void JB_StructSaveTest_Destructor(StructSaveTest* Self) {
	JB_Clear(Self->Sav);
	JB_Clear(Self->Str);
}

void JB_StructSaveTest_LoadProperties(StructSaveTest* Self, ObjectLoader* Loader) {
	//visible;
	JB_SetRef(Self->Sav, ((Saveable*)JB_LD_Object(Loader)));
	Self->Intt = ((int64)JB_LD_Int(Loader));
	JB_SetRef(Self->Str, ((JB_String*)JB_LD_String(Loader)));
}

void JB_StructSaveTest_SaveWrite(StructSaveTest* Self, ObjectSaver* Saver) {
	//visible;
	JB_Saver_AppendObject(Saver, Self->Sav);
	JB_Saver_AppendInt(Saver, Self->Intt);
	JB_Saver_AppendString(Saver, Self->Str);
}





































__lib__ void jdb(JB_Object* Self) {
	//visible;
	if (Self) {
		JB_StringC* _tmPf0 = JB_Str__Wrap(JB_ObjClass(Self)->Name);
		JB_Incr(_tmPf0);
		JB_Print(_tmPf0);
		JB_Decr(_tmPf0);
		JB_Print(JB_LUB[73]);
	}
	JB_String* _tmPf1 = JB_ObjRender(Self, nil);
	JB_Incr(_tmPf1);
	JB_PrintLine(_tmPf1);
	JB_Decr(_tmPf1);
}

bool JB_Object_FastIsa(JB_Object* Self, JB_Class* X) {
	return (Self) and (JB_ObjClass(Self) == X);
}

bool JB_Object_Isa(JB_Object* Self, JB_Class* Cls) {
	if (Self) {
		JB_Class* P = JB_ObjClass(Self);
		while (P) {
			if (P == Cls) {
				return true;
			}
			P = P->Parent;
		};
	}
	return false;
}

void JB_Object_SaveTryCollect(JB_Object* Self, ObjectSaver* Saver) {
	if (JB_Object_Isa(Self, &SaveableData)) {
		if (!JB_Sav_SaveMark(((Saveable*)Self))) {
			return;
		}
		JB_Array_SyntaxAppend(JB_Sav_SaverInfo(((Saveable*)Self)), ((Saveable*)Self));
		JB_Sav___SaveCollect__(((Saveable*)Self), Saver);
	}
	 else if (Self) {
		if (!JB_Object_Isa(Self, &JB_StringData)) {
			Saver->CantSaveThis = Self;
		}
	}
}

void JB_Object_FailStr(JB_Object* Self, JB_String* Error) {
	//visible;
	if (JB_Object_Isa(Self, &MessageData)) {
		JB_Rec__Latchkum(((Message*)Self), Error, nil);
	}
	 else {
		JB_Rec__Latchkum(nil, Error, nil);
	}
}




Array* JB_CS_Bytes(CharSet* Self) {
	Array* Rz = ((Array*)JB_Array_Constructor0(nil));
	{
		int _if0 = -1;
		while (JB_CS_NextInCharset(Self, (&_if0))) {
			uint B = ((byte)_if0);
			JB_Array_SyntaxAppend(Rz, JB_byte_Render(B, nil));
		};
	}
	;
	return Rz;
}

bool JB_CS_NextInCharset(CharSet* Self, int* P) {
	int I = P[0];
	while ((++I) < 256) {
		if (JB_CS_HasChar(Self, I)) {
			P[0] = I;
			return true;
		}
	};
	return false;
}

bool JB_CS_OperatorContains(CharSet* Self, JB_String* Data) {
	return (!JB_Ind_SyntaxCast(JB_Str_OutCharSet(Data, Self, 0, JB_int__Max())));
}


DTWrap* JB_Wrap_ConstructorInt(DTWrap* Self, int64 V) {
	if (Self == nil) {
		Self = ((DTWrap*)JB_NewClass(&DTWrapData));
	}
	Self->DeathAction = 0;
	Self->DataType = kJB__TC_s64;
	Self->PrivValue = V;
	return Self;
}

void JB_Wrap_Destructor(DTWrap* Self) {
	if (Self->DeathAction == kJB__Wrap_kFree) {
		JB_Free(((void*)Self->PrivValue));
	}
}

Float64 JB_Wrap_FloatValue(DTWrap* Self) {
	if (Self) {
		return JB_int64_AsFloat(Self->PrivValue);
	}
	return 0.0f;
}

JB_String* JB_Wrap_Render(DTWrap* Self, FastString* Fs_in) {
	FastString* Fs = JB_FS__FastNew(Fs_in);
	JB_Incr(Fs);
	//visible;
	if (JB_TC_IsFloat(Self->DataType)) {
		JB_FS_AppendDoubleAsText0(Fs, JB_Wrap_FloatValue(Self));
	}
	 else if (Self->DataType == kJB__TC_bool) {
		JB_bool_Append(((bool)Self->PrivValue), Fs);
	}
	 else if (!JB_TC_IsNumeric(Self->DataType)) {
		JB_FS_AppendString(Fs, JB_LUB[202]);
		JB_FS_AppendHex(Fs, Self->PrivValue, 2);
	}
	 else {
		JB_FS_AppendInt64(Fs, Self->PrivValue);
	}
	JB_String* _tmPf0 = JB_FS_SmartResult(Fs, Fs_in);
	JB_Incr(_tmPf0);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}


JB_Object* JB_DictionaryReader_NextValue(DictionaryReader* Self) {
	if (JB_Nav_MoveNext(Self)) {
		return JB_Nav_Value(Self);
	}
	return nil;
}


int JB_Rec_BadCount(JB_ErrorReceiver* Self) {
	//visible;
	return Self->ErrorCount + Self->ProblemCount;
}

bool JB_Rec_CanAddMore(JB_ErrorReceiver* Self, uint /*ErrorSeverity*/ Level) {
	if (!((!Self->BlockErrors) and (!JB_OutOfMemoryOccurred()))) {
		return nil;
	}
	if (Level == kJB__ErrorSeverity_Problem) {
		return (Self->ProblemCount < Self->MaxProblems);
	}
	if (Level >= kJB__ErrorSeverity_Error) {
		return (Self->ErrorCount < Self->MaxErrors);
	}
	return (Self->WarnCount < Self->MaxErrors);
}

void JB_Rec_Clear(JB_ErrorReceiver* Self) {
	JB_Tree_Clear(Self->Errors);
	Self->ErrorCount = 0;
	Self->WarnCount = 0;
	Self->ProblemCount = 0;
}

JB_ErrorReceiver* JB_Rec_Constructor(JB_ErrorReceiver* Self) {
	if (Self == nil) {
		Self = ((JB_ErrorReceiver*)JB_NewClass(&JB_ErrorReceiverData));
	}
	Self->_LogObj = nil;
	JB_Incr2(Self->Source, JB_LUB[0]);
	Self->_LogFunc = nil;
	Self->WarnCount = 0;
	Self->ProblemCount = 0;
	Self->ErrorCount = 0;
	Self->BlockErrors = false;
	Self->LowerErrorsTo = 0;
	JB_Incr2(Self->Errors, JB_Err_ConstructorNothing(nil));
	Self->MaxErrors = 512;
	Self->MaxProblems = 64;
	JB__API_NilHappened_ = nil;
	return Self;
}

void JB_Rec_Destructor(JB_ErrorReceiver* Self) {
	JB_Clear(Self->_LogObj);
	JB_Clear(Self->Source);
	JB_Clear(Self->Errors);
}

void JB_Rec_Incr(JB_ErrorReceiver* Self, JB_Error* Err, bool Add) {
	int N = JB_Ternary(Add, 1, ((int)-1));
	if (Err->Severity == kJB__ErrorSeverity_Problem) {
		Self->ProblemCount = (Self->ProblemCount + N);
	}
	 else if (JB_Err_IsError(Err)) {
		Self->ErrorCount = (Self->ErrorCount + N);
	}
	 else if (JB_Err_IsWarning(Err)) {
		Self->WarnCount = (Self->WarnCount + N);
	}
}

JB_Error* JB_Rec_LastError(JB_ErrorReceiver* Self) {
	//visible;
	{
		JB_Error* _LoopSrcf1 = Self->Errors;
		JB_Error* Err = ((JB_Error*)JB_Ring_Last(_LoopSrcf1));
		while (Err) {
			if (JB_Err_IsError(Err)) {
				return Err;
			}
			Err = ((JB_Error*)JB_Ring_PrevSib(Err));
		};
		;
	}
	;
	return nil;
}

void JB_Rec_LogFileWriter(JB_ErrorReceiver* Self, JB_String* Data) {
	//visible;
	JB_Object* F = Self->_LogObj;
	if (JB_Object_FastIsa(F, &JB_FileData)) {
		if (!JB_File_Opened(((JB_File*)F))) {
			JB_File_OpenBlank(((JB_File*)F));
		}
		JB_File_SyntaxAppend(((JB_File*)F), Data);
	}
}

ErrorMarker JB_Rec_Mark(JB_ErrorReceiver* Self) {
	return Self->ErrorCount;
}

bool JB_Rec_OK(JB_ErrorReceiver* Self) {
	if (Self) {
		return (!Self->ErrorCount);
	}
	return (!JB_StdErr->ErrorCount);
}

int JB_Rec_PrintErrorsMain(JB_ErrorReceiver* Self, uint /*ErrorSeverity*/ Level, bool PrintCount, bool Shell) {
	JB_ErrorReceiver* Rec = JB_StdErr;
	JB_Incr(Rec);
	if (Self) {
		JB_SetRef(Rec, Self);
	}
	FastString* Fs = JB_FS_Constructor(nil);
	JB_Incr(Fs);
	int Count = JB_Rec_RenderErrors(Rec, Fs, Level, Shell);
	JB_Decr(Rec);
	if (!Count) {
		JB_Decr(Fs);
		return 0;
	}
	JB_String* _tmPf0 = JB_FS_GetResult(Fs);
	JB_Incr(_tmPf0);
	JB_Str_PrintError(_tmPf0);
	JB_Decr(_tmPf0);
	JB_FS_ProblemsFound(Fs, Count);
	JB_String* _tmPf1 = JB_FS_GetResult(Fs);
	JB_Incr(_tmPf1);
	JB_Decr(Fs);
	JB_Str_PrintError(_tmPf1);
	JB_Decr(_tmPf1);
	if (Count) {
		return -1;
	}
	return 0;
}

JB_String* JB_Rec_Render(JB_ErrorReceiver* Self, FastString* Fs_in) {
	FastString* Fs = JB_FS__FastNew(Fs_in);
	JB_Incr(Fs);
	JB_Rec_RenderErrors(Self, Fs, 0, false);
	JB_String* _tmPf0 = JB_FS_SmartResult(Fs, Fs_in);
	JB_Incr(_tmPf0);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

int JB_Rec_RenderErrors(JB_ErrorReceiver* Self, FastString* Fs, uint /*ErrorSeverity*/ Level, bool Shell) {
	int Rz = 0;
	if (!Self) {
		return 0;
	}
	{
		JB_Error* Err = ((JB_Error*)JB_Ring_First(Self->Errors));
		while (Err) {
			JB_Error* _Nf1 = ((JB_Error*)JB_Ring_NextSib(Err));
			if (Err->Severity >= Level) {
				(++Rz);
				if (Shell) {
					JB_FreeIfDead(JB_Err_RenderUnix(Err, Fs));
				}
				 else {
					JB_FreeIfDead(JB_Err_Render(Err, Fs));
				}
				JB_FS_AppendByte(Fs, '\n');
			}
			Err = _Nf1;
		};
	}
	;
	return Rz;
}

int JB_Rec_ShellPrintErrors(JB_ErrorReceiver* Self) {
	//visible;
	return JB_Rec_PrintErrorsMain(Self, kJB__ErrorSeverity_Problem, false, true);
}

void JB_Rec_AppendErr(JB_ErrorReceiver* Self, JB_Error* Err) {
	if (!Self) {
		Self = JB_StdErr;
	}
	bool CanPrint = false;
	JB_Rec_Incr(Self, Err, true);
	if (!JB_Str_Exists(Err->Path)) {
		JB_SetRef(Err->Path, Self->Source);
	}
	if (JB__Err_KeepStackTrace) {
		if (!JB_Str_Exists(Err->StackTrace)) {
			JB_SetRef(Err->StackTrace, JB_App__StackTrace(2, nil));
		}
	}
	FP_fnErrorLogger Log = ((FP_fnErrorLogger)(Self->_LogFunc));
	if (Log) {
		JB_String* _tmPf0 = JB_Err_Render(Err, nil);
		JB_Incr(_tmPf0);
		(Log)(Self, _tmPf0);
		JB_Decr(_tmPf0);
	}
	if (CanPrint and JB_Err_IsBad(Err)) {
		JB_String* _tmPf1 = JB_Err_Render(Err, nil);
		JB_Incr(_tmPf1);
		JB_PrintLine(_tmPf1);
		JB_Decr(_tmPf1);
	}
	if (JB__Err_AutoPrint and (Err->Severity > kJB__ErrorSeverity_Problem)) {
		JB_DoAt(1);
	}
	if (JB__Err_AutoPrint != kJB__ErrorFlags_PrintAndRemove) {
		JB_Tree_SyntaxAppend(Self->Errors, Err);
	}
}

int JB_Rec__Init_() {
	{
	}
	;
	return 0;
}

void JB_Rec__Latchkum(Message* Node, JB_String* Desc, JB_String* Path) {
	JB_Rec__NewErrorSub(Node, Desc, Path, kJB__ErrorSeverity_Error);
}

void JB_Rec__NewErrorSub(Message* Node, JB_String* Desc, JB_String* Path, uint /*ErrorSeverity*/ Sev) {
	uint Lower = JB_StdErr->LowerErrorsTo;
	if (Lower) {
		Sev = JB_int_OperatorMin(((int)Lower), Sev);
	}
	if (JB_Rec_CanAddMore(JB_StdErr, Sev)) {
		if (Desc == nil) {
			Desc = JB_Msg_MiniName(Node, JB_LUB[259]);
		}
		JB_Rec_AppendErr(((JB_ErrorReceiver*)nil), JB_Err_Constructor(nil, JB_Msg_FindNotInserted(Node), Desc, Sev, ((JB_String*)JB_Ternary(JB_Str_Exists(Path), ((JB_String*)Path), ((JB_String*)JB_LUB[0])))));
	}
}


void JB_FS_AppendEscape(FastString* Self, JB_String* S) {
	JB_FS_AppendMultiReplace(Self, S, JB__Constants_EscapeStr, JB_StdErr);
}

void JB_FS_AppendHexStr(FastString* Self, JB_String* Data) {
	if (JB_Str_Exists(Data)) {
		JB_FS_AppendHexData(Self, Data->Addr, JB_Str_Length(Data), 0);
	}
}

void JB_FS_AppendObjectID(FastString* Self, Saveable* O) {
	JB_FS_AppendHex3(Self, JB_ObjectID(O));
}

void JB_FS_AppendObjectOrNil(FastString* Self, JB_Object* O) {
	if (JB_Object_Isa(O, &SaveableData)) {
		if (JB_Sav_IsSaveMarked(((Saveable*)O))) {
			JB_FS_AppendObjectID(Self, ((Saveable*)O));
		}
		 else {
			//"Valid behaviour! For example we save a level, but we don't save the player along with the level. Like terraria.";
			JB_FS_AppendString(Self, JB_LUB[46]);
		}
	}
	 else if (JB_Object_Isa(O, &JB_StringData)) {
		JB_FreeIfDead(JB_ObjRender(((JB_String*)O), Self));
	}
	 else {
		JB_FS_AppendString(Self, JB_LUB[46]);
	}
}

void JB_FS_AppendQuotedEscape(FastString* Self, JB_String* S) {
	JB_FS_AppendByte(Self, '"');
	JB_FS_AppendEscape(Self, S);
	JB_FS_AppendByte(Self, '"');
}

void JB_FS_AppendInfo(FastString* Self, JB_String* Name, JB_String* Data) {
	if (JB_Str_Exists(Data)) {
		JB_FS_FieldStart(Self, Name);
		JB_FS_AppendQuotedEscape(Self, Data);
	}
}

void JB_FS_AppendInfoNum(FastString* Self, JB_String* Name, int64 Data) {
	if (Data) {
		JB_FS_FieldStart(Self, Name);
		JB_FS_AppendInt64(Self, Data);
	}
}

void JB_FS_AppendInfoFloat(FastString* Self, JB_String* Name, Float64 Data) {
	if (Data) {
		JB_FS_FieldStart(Self, Name);
		JB_FS_AppendDoubleAsText0(Self, Data);
	}
}

void JB_FS_FieldStart(FastString* Self, JB_String* Name) {
	JB_FS_LineIndent(Self);
	if (JB_Str_Exists(Name)) {
		JB_FS_AppendString(Self, Name);
		JB_FS_AppendByte(Self, ' ');
	}
}

void JB_FS_hInt(FastString* Self, uint64 N) {
	while (true) {
		if (N <= 127) {
			JB_FS_AppendByte(Self, ((byte)(N)));
			break;
		}
		JB_FS_AppendByte(Self, ((byte)(N | 128)));
		N = (N >> 7);
	};
}

void JB_FS_MsgErrorName(FastString* Self, JB_String* Name) {
	if (((JB_String*)JB_Str_Exists(Name))) {
		JB_FS_AppendString(Self, JB_LUB[7]);
		JB_FS_AppendString(Self, Name);
		JB_FS_AppendString(Self, JB_LUB[8]);
	}
}

void JB_FS_PrintNicely(FastString* Self, JB_String* S) {
	int Cause = JB_Str_UnPrintable(S);
	if (Cause < 0) {
		//;
		JB_FS_AppendString(Self, JB_LUB[47]);
		JB_String* _tmPf1 = JB_Str_Hex(S, 0, nil);
		JB_Incr(_tmPf1);
		JB_FS_AppendString(Self, _tmPf1);
		JB_Decr(_tmPf1);
		JB_FS_AppendString(Self, JB_LUB[48]);
		//;
	}
	 else if (Cause == '\n') {
		JB_FreeIfDead(JB_Str_ReplaceAll(S, JB_LUB[42], JB_LUB[41], false, Self));
	}
	 else {
		JB_FS_AppendString(Self, S);
	}
}

void JB_FS_ProblemsFound(FastString* Self, int Count) {
	JB_String* _tmPf0 = JB_int_operatorof(Count, JB_LUB[215], JB_LUB[0]);
	JB_Incr(_tmPf0);
	JB_FS_AppendString(Self, _tmPf0);
	JB_Decr(_tmPf0);
	JB_FS_AppendString(Self, JB_LUB[216]);
}

JB_String* JB_FS_Render(FastString* Self, FastString* Fs_in) {
	FastString* Fs = JB_FS__FastNew(Fs_in);
	JB_Incr(Fs);
	JB_FS_AppendFastString(Fs, Self);
	JB_String* _tmPf0 = JB_FS_SmartResult(Fs, Fs_in);
	JB_Incr(_tmPf0);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

void JB_FS_AppendFastString(FastString* Self, FastString* Fs) {
	JB_FS_AppendMem_(Self, Fs->ResultPtr, Fs->Length);
}

void JB_FS_AppendInt32(FastString* Self, int Data) {
	JB_FS_AppendIntegerAsText(Self, Data, 1);
}

void JB_FS_AppendBuff(FastString* Self, FastBuff* B) {
	JB_FS_AppendMem_(Self, B->Start, JB_FastBuff_Length(B));
}

void JB_FS_SyntaxAppend(FastString* Self, Message* Msg) {
	if (Msg) {
		(JB_Syx_RenderAddr(Msg->Func))(Msg, Self);
	}
}

FastString* JB_FS__Use(JB_Object* Other) {
	if (JB_Object_FastIsa(Other, &FastStringData)) {
		return ((FastString*)Other);
	}
	if (JB_Object_Isa(Other, &JB_StringData)) {
		return JB_Str_Out(((JB_String*)Other), true);
	}
	if (Other) {
		if (true) {
			JB_Object_FailStr(Other, JB_LUB[403]);
		}
	}
	return nil;
}



void JB_Flow_AddByte(FlowControl* Self, uint /*byte*/ Value) {
	//;
	if (JB_FastBuff_AppendU8((&Self->Buff), Value)) {
		JB_Flow_Flush(Self);
	}
}

void JB_Flow_Destructor(FlowControl* Self) {
	//;
	(JB_Flow__DisabledSet(JB_int__Max()));
	JB_Flow_Flush(Self);
	if (Self->ReadInput != nil) {
		JB_PrintLine(JB_LUB[224]);
	}
	JB_Clear(Self->Write);
	JB_FastBuff_Destructor((&Self->Buff));
	JB_Clear(Self->ReadInput);
}

void JB_Flow_Fail(FlowControl* Self, JB_String* Found, JB_String* Expected, JB_String* InputName) {
	//;
	JB_SetRef(Self->ReadInput, Self->ReadInput);
	if (!Self->CanDoErrors) {
		return;
	}
	FastString* Fs = JB_FS_Constructor(nil);
	JB_Incr(Fs);
	if (JB_Str_Exists(InputName)) {
		//;
		JB_FS_AppendString(Fs, JB_LUB[244]);
		JB_FS_AppendString(Fs, InputName);
		JB_FS_AppendString(Fs, JB_LUB[245]);
		//;
	}
	if (!JB_SS_HasAny(Self->ReadInput)) {
		JB_FS_AppendString(Fs, JB_LUB[246]);
	}
	 else {
		JB_FS_AppendString(Fs, JB_LUB[247]);
		JB_FS_PrintNicely(Fs, Expected);
		JB_FS_AppendString(Fs, JB_LUB[248]);
		JB_FS_PrintNicely(Fs, Found);
	}
	JB_FS_AppendByte(Fs, '\n');
	JB_FreeIfDead(JB_App__StackTrace(3, Fs));
	JB_String* _tmPf1 = JB_FS_GetResult(Fs);
	JB_Incr(_tmPf1);
	JB_Decr(Fs);
	JB_PrintLine(_tmPf1);
	JB_Decr(_tmPf1);
	Self->CanDoErrors = false;
	JB_SetRef(Self->ReadInput, nil);
	if (JB__Flow_BreakOnFail) {
	}
}

void JB_Flow_Flush(FlowControl* Self) {
	//;
	FastString* W = Self->Write;
	JB_Incr(W);
	if (W) {
		JB_FS_AppendBuff(W, (&Self->Buff));
	}
	JB_Decr(W);
	Self->Buff.Curr = Self->Buff.Start;
}

bool JB_Flow_TestByte(FlowControl* Self, uint /*byte*/ Value) {
	//;
	//visible;
	JB_Flow_AddByte(Self, Value);
	StringReader* R = Self->ReadInput;
	if (R == nil) {
		return true;
	}
	int B = JB_SS_Byte(R);
	if (B == Value) {
		return true;
	}
	JB_Flow_Fail(Self, JB_Str__Byte(Value), JB_Str__Byte(B), JB_LUB[0]);
	return false;
}

bool JB_Flow__Cond(bool Value) {
	//visible;
	//;
	JB_Flow__SyntaxAppend(((byte)('A' + Value)));
	return Value;
}

void JB_Flow__GetActiveFlow() {
	JB_String* Str = JB_App__SyntaxAccess(JB_LUB[249]);
	JB_Incr(Str);
	if (JB_Str_Equals(Str, JB_LUB[250], true)) {
		JB__Flow_Active = kJB__Flow_Validate;
	}
	 else if (JB_Str_Equals(Str, JB_LUB[251], true)) {
		JB__Flow_Active = kJB__Flow_Log;
	}
	JB_Decr(Str);
}

int JB_Flow__Init_() {
	{
		JB__Flow_AlwaysMove = true;
	}
	;
	return 0;
}

int JB_Flow__InitCode_() {
	{
	}
	;
	JB_Flow__GetActiveFlow();
	return 0;
}

void JB_Flow__Input(JB_String* Data, JB_String* Name) {
	//visible;
	//;
	if (JB_Flow__IsDisabled()) {
		return;
	}
	(JB_Flow__DisabledSet(1));
	FlowControl* F = JB__Flow_Flow;
	StringReader* R = F->ReadInput;
	if (R != nil) {
		JB_String* Str = JB_SS_Str(R, JB_Str_Length(Data), 0);
		JB_Incr(Str);
		if (!JB_Str_Equals(Str, Data, false)) {
			JB_Flow_Fail(F, Str, Data, Name);
		}
		JB_Decr(Str);
	}
	{
		byte* _Startf0 = JB_Str_Address(Data);
		byte* _Endf1 = _Startf0 + JB_Str_Length(Data);
		while (_Startf0 < _Endf1) {
			uint C = _Startf0[0];
			JB_Flow_AddByte(F, C);
			(++_Startf0);
		};
	}
	;
	(JB_Flow__DisabledSet(0));
}

void JB_Flow__SyntaxAppend(uint /*byte*/ Value) {
	//visible;
	//;
	if (!JB_Flow__IsDisabled()) {
		(JB_Flow__DisabledSet(1));
		JB_Flow_TestByte(JB__Flow_Flow, Value);
		(JB_Flow__DisabledSet(0));
	}
}

bool JB_Flow__Cond2(bool Value) {
	//visible;
	//;
	if (Value) {
		return true;
	}
	JB_Flow__SyntaxAppend('W');
	return false;
}


LeakTester* JB_Lk_Constructor(LeakTester* Self, JB_String* Name) {
	if (Self == nil) {
		Self = ((LeakTester*)JB_NewClass(&LeakTesterData));
	}
	Self->MemUsedStart = JB_MemCount();
	JB_Incr2(Self->Name, Name);
	JB_Mem_Mark();
	return Self;
}

void JB_Lk_Destructor(LeakTester* Self) {
	JB_Clear(Self->Name);
}

void JB_Lk_FinalTest(LeakTester* Self) {
	JB_Lk_Test2(Self);
	Self->MemUsedStart = nil;
	JB_Mem_Unmark();
}

void JB_Lk_Test2(LeakTester* Self) {
	if (!Self->MemUsedStart) {
		return;
	}
	int NewAmount = JB_MemCount();
	int Diff = NewAmount - Self->MemUsedStart;
	if (Diff > 0) {
		FastString* _fsf0 = JB_FS_Constructor(nil);
		JB_Incr(_fsf0);
		JB_FS_AppendString(_fsf0, JB_LUB[49]);
		JB_FS_AppendInt32(_fsf0, Diff);
		JB_FS_AppendString(_fsf0, JB_LUB[50]);
		JB_FS_AppendString(_fsf0, Self->Name);
		JB_FS_AppendString(_fsf0, JB_LUB[51]);
		JB_FS_AppendInt32(_fsf0, NewAmount);
		JB_FS_AppendByte(_fsf0, '.');
		JB_String* _tmPf1 = JB_FS_GetResult(_fsf0);
		JB_Incr(_tmPf1);
		JB_Decr(_fsf0);
		JB_PrintLine(_tmPf1);
		JB_Decr(_tmPf1);
	}
}


int JB_Macro__Init_() {
	{
		JB_SetRef(JB__Macro_TmpPrms_, JB_Array_Constructor0(nil));
	}
	;
	return 0;
}


MWrap* JB_Mrap_ConstructorPtr(MWrap* Self, int ItemCount, int ItemSize, byte* Ptr, uint /*byte*/ DeathAction) {
	if (Self == nil) {
		Self = ((MWrap*)JB_NewClass(&MWrapData));
	}
	Self->ItemSize = ItemSize;
	Self->ItemCount = ItemCount;
	Self->DeathAction = DeathAction;
	Self->Length = 0;
	Self->_Ptr = Ptr;
	return Self;
}

void JB_Mrap_Destructor(MWrap* Self) {
	if (Self->DeathAction == kJB__Wrap_kFree) {
		JB_Free(Self->_Ptr);
	}
}

Array* JB_Mrap__CollectLeaks_(JB_Object* Self) {
	Array* Rz = ((Array*)JB_Array_Constructor0(nil));
	JB_Incr(Rz);
	JB_FindLeakedObject(Self, Rz);
	JB_SafeDecr(Rz);
	return Rz;
}

int JB_Mrap__Init_() {
	{
	}
	;
	return 0;
}

MWrap* JB_Mrap__Object(int Count, int ItemSize) {
	//visible;
	byte* P = JB_Zalloc(Count * ItemSize);
	if (P) {
		return JB_Mrap_ConstructorPtr(nil, Count, ItemSize, P, kJB__Wrap_kFree);
	}
	return nil;
}

void jbl(JB_Object* Self) {
	//visible;
	{
		Array* _LoopSrcf2 = JB_Mrap__CollectLeaks_(Self);
		JB_Incr(_LoopSrcf2);
		int _if0 = 0;
		while (true) {
			JB_Object* Bad = JB_Array_Value(_LoopSrcf2, _if0);
			JB_Incr(Bad);
			if (Bad == nil) {
				JB_Decr(Bad);
				break;
			}
			jdb(Bad);
			JB_Decr(Bad);
			(++_if0);
		};
		JB_Decr(_LoopSrcf2);
	};
}




bool JB_Sav_IsSaveMarked(Saveable* Self) {
	int* P = ((int*)Self);
	return ((bool)(P[0] & kJB__Saver_RefMark));
}

void JB_Sav_LoadProperties(Saveable* Self, ObjectLoader* Loader) {
	Loader->CouldntLoad = Self;
}

void JB_Sav_SaveCollect(Saveable* Self, ObjectSaver* Saver) {
}

bool JB_Sav_SaveMark(Saveable* Self) {
	int* P = ((int*)Self);
	int Rc = P[0];
	if ((Rc & kJB__Saver_RefMark)) {
		return nil;
	}
	P[0] = (Rc | kJB__Saver_RefMark);
	return true;
}

SaverClassInfo* JB_Sav_SaverInfo(Saveable* Self) {
	return ((SaverClassInfo*)JB_ObjClass(Self)->SaveInfo);
}

void JB_Sav_SaveWrite(Saveable* Self, ObjectSaver* Saver) {
	Saver->CantSaveThis = Self;
	JB_FS_AppendString(Saver->Dest, JB_LUB[18]);
}


void JB_Sel_Destructor(Selector* Self) {
	JB_Clear(Self->Name);
	JB_Clear(Self->Next);
}


JB_String* JB_Str_AfterByte(JB_String* Self, uint /*byte*/ B, int Last) {
	Ind Start = JB_Str_FindByte(Self, B, Last, 0);
	return JB_Str_Range(Self, Start + 1, Last);
}

JB_String* JB_Str_ArgName(JB_String* Self) {
	if (JB_Str_First(Self) == '-') {
		Ind I = JB_Str_FindByte(Self, '=', 0, JB_int__Max());
		if (!JB_Ind_SyntaxCast(I)) {
			I = JB_int__Max();
		}
		JB_String* S = JB_Str_Range(Self, 0, I);
		JB_Incr(S);
		JB_SetRef(S, JB_Str_TrimFirst(S, '-'));
		JB_String* _tmPf0 = JB_Str_LowerCase(S);
		JB_Incr(_tmPf0);
		JB_Decr(S);
		JB_SafeDecr(_tmPf0);
		return _tmPf0;
	}
	return JB_LUB[0];
}

JB_String* JB_Str_ArgValue(JB_String* Self) {
	if (JB_Str_ByteValue(Self, 0) != '-') {
		return Self;
	}
	Ind It = JB_Str_FindByte(Self, '=', 0, JB_int__Max());
	if (JB_Ind_SyntaxCast(It)) {
		return JB_Str_Range(Self, It + (1), JB_int__Max());
	}
	return JB_LUB[27];
}

JB_String* JB_Str_BackToApp(JB_String* Self) {
	JB_String* Rz = JB_LUB[0];
	JB_Incr(Rz);
	JB_String* S = JB_Str_TrimSlashes(Self, false);
	JB_Incr(S);
	JB_String* _tmPf0 = JB_Str_Name(Self);
	JB_Incr(_tmPf0);
	JB_String* Final = JB_Str_OperatorPlus(JB_LUB[260], _tmPf0);
	JB_Incr(Final);
	JB_Decr(_tmPf0);
	if (JB_Str_OperatorEndsWith(S, Final)) {
		JB_SetRef(Rz, JB_Str_Range(S, 0, 4 + (JB_Str_OperatorMinus(S, Final))));
	}
	 else {
		JB_SetRef(Rz, Self);
	}
	JB_Decr(S);
	JB_Decr(Final);
	JB_SafeDecr(Rz);
	return Rz;
}

JB_String* JB_Str_BeforeLastByte(JB_String* Self, uint /*byte*/ B, int Fudge) {
	int Last = JB_Str_TrimLastSub(Self, B);
	Ind Start = JB_Str_FindByte(Self, B, Last, 0);
	return JB_Str_Range(Self, 0, Start + Fudge);
}

Array* JB_Str_ByteSplit(JB_String* Self) {
	Array* Rz = ((Array*)JB_Array_Constructor0(nil));
	JB_Incr(Rz);
	{
		int _LoopSrcf1 = JB_Str_Length(Self);
		int N = 0;
		while (N < _LoopSrcf1) {
			JB_String* _tmPf2 = JB_Str__Byte(JB_Str_ByteValue(Self, N));
			JB_Incr(_tmPf2);
			JB_Array_SyntaxAppend(Rz, _tmPf2);
			JB_Decr(_tmPf2);
			(++N);
		};
	}
	;
	JB_SafeDecr(Rz);
	return Rz;
}

CharSet* JB_Str_CharSetWithBool(JB_String* Self, bool Range) {
	return JB_CS_Constructor(nil, Self, Range);
}

JB_String* JB_Str_Child(JB_String* Self, JB_String* Cname) {
	if (!JB_Str_Exists(Self)) {
		return Cname;
	}
	int C = ((int)(JB_Str_Last(Self, 0) == '/'));
	C = (C + (JB_Str_First(Cname) == '/'));
	if (C == 1) {
		return JB_Str_OperatorPlus(Self, Cname);
	}
	if (C == 0) {
		JB_String* _tmPf0 = JB_Str_OperatorPlus(JB_LUB[4], Cname);
		JB_Incr(_tmPf0);
		JB_String* _tmPf3 = JB_Str_OperatorPlus(Self, _tmPf0);
		JB_Incr(_tmPf3);
		JB_Decr(_tmPf0);
		JB_SafeDecr(_tmPf3);
		return _tmPf3;
	}
	JB_String* _tmPf1 = JB_Str_Range(Cname, 1, JB_int__Max());
	JB_Incr(_tmPf1);
	JB_String* _tmPf2 = JB_Str_OperatorPlus(Self, _tmPf1);
	JB_Incr(_tmPf2);
	JB_Decr(_tmPf1);
	JB_SafeDecr(_tmPf2);
	return _tmPf2;
}

JB_String* JB_Str_Compress(JB_String* Self, int Strength, CompressionStats* St) {
	FastString* J = JB_bin_Constructor0(nil, 0);
	JB_Incr(J);
	StringReader* _tmPf0 = JB_Str_Stream(Self);
	JB_Incr(_tmPf0);
	JB_SS_CompressInto(_tmPf0, J, Strength, St);
	JB_Decr(_tmPf0);
	JB_String* _tmPf1 = JB_FS_SyntaxCast(J);
	JB_Incr(_tmPf1);
	JB_Decr(J);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

int JB_Str_Count(JB_String* Self, uint /*byte*/ B) {
	int Rz = 0;
	{
		byte* _Startf0 = JB_Str_Address(Self);
		byte* _Endf1 = _Startf0 + JB_Str_Length(Self);
		while (_Startf0 < _Endf1) {
			uint C = _Startf0[0];
			Rz = (Rz + (C == B));
			(++_Startf0);
		};
	}
	;
	return Rz;
}

JB_String* JB_Str_Decompress(JB_String* Self, int Lim, CompressionStats* St) {
	StringReader* _tmPf0 = JB_Str_Stream(Self);
	JB_Incr(_tmPf0);
	JB_String* _tmPf1 = JB_SS_Decompress(_tmPf0, Lim, St);
	JB_Incr(_tmPf1);
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

bool JB_Str_EndsWith(JB_String* Self, JB_String* S, bool Aware) {
	int N = JB_Str_Length(S);
	int L = JB_Str_Length(Self);
	{
		IntRange _LoopSrcf2 = JB_int_OperatorTo(1, N);
		int __Endf0 = _LoopSrcf2[1];
		int I = _LoopSrcf2[0];
		while (I < __Endf0) {
			uint A = JB_Str_ByteValue(Self, L - I);
			uint B = JB_Str_ByteValue(S, N - I);
			if (Aware) {
				A = JB_byte_LowerCase(A);
				B = JB_byte_LowerCase(B);
			}
			if (A != B) {
				return nil;
			}
			(++I);
		};
	}
	;
	return true;
}

JB_String* JB_Str_Escape(JB_String* Self) {
	return JB_Str_MultiReplaceAll(Self, JB__Constants_EscapeStr, JB_StdErr);
}

JB_String* JB_Str_EscapeChr(JB_String* Self) {
	return JB_Str_MultiReplaceAll(Self, JB__Constants_EscapeChr, JB_StdErr);
}

bool JB_Str_EscapeTest(JB_String* Self) {
	JB_String* Esc = JB_Str_Escape(Self);
	JB_Incr(Esc);
	JB_String* Back = JB_Str_Unescape(Esc);
	JB_Incr(Back);
	JB_Decr(Esc);
	bool _tmPf0 = ((JB_Str_Equals(Back, Self, false)));
	JB_Decr(Back);
	return _tmPf0;
}

JB_File* JB_Str_AsFile(JB_String* Self) {
	if (JB_Object_FastIsa(Self, &JB_FileData)) {
		return ((JB_File*)Self);
	}
	return JB_Str_File(Self);
}

Ind JB_Str_FindByte(JB_String* Self, uint /*byte*/ Find, int Start, int After) {
	return JB_Str_InByte(Self, Start, After, Find);
}

Ind JB_Str_Find(JB_String* Self, CharSet* Cs, int Start, int After) {
	return JB_Str_CharSet(Self, Start, After, Cs, true);
}

Ind JB_Str_FindSlash(JB_String* Self, int From) {
	Ind Rz = -1;
	if (From < JB_Str_Length(Self)) {
		Rz = JB_Str_FindByte(Self, '/', From, JB_int__Max());
		if (!JB_Ind_SyntaxCast(Rz)) {
			Rz = JB_Str_Length(Self);
		}
	}
	return Rz;
}

Ind JB_Str_InWhite(JB_String* Self, int Start, int After) {
	return JB_Str_WhiteSpace(Self, Start, After, true);
}

bool JB_Str_IsCompressed(JB_String* Self) {
	return JB_Ind_SyntaxCast(JB_Str_IsJbin(Self)) and JB_Str_MidEquals(Self, JB_Str_Length(JB__JbinHeader), JB_LUB[146], false);
}

int JB_Str_IsHexLike(JB_String* Self, int N) {
	if (JB_Str_ByteValue(Self, N + 0x0) == '0') {
		uint X = JB_Str_ByteValue(Self, N + 1);
		if (JB_byte_IsLetter(X)) {
			return 2;
		}
	}
	return 0;
}

Ind JB_Str_IsJbin(JB_String* Self) {
	if ((JB_Str_First(Self) == '#') and (JB_Str_ByteValue(Self, 1) == '!')) {
		Ind Nl = JB_Str_FindByte(Self, '\n', 0, JB_int__Max());
		if (JB_Ind_SyntaxCast(Nl)) {
			(++Nl);
			if (JB_Str_MidEquals(Self, Nl, JB__JbinHeader, false)) {
				return Nl;
			}
		}
	}
	 else if (JB_Str_MidEquals(Self, 0, JB__JbinHeader, false)) {
		return 0;
	}
	return -1;
}

bool JB_Str_IsLower(JB_String* Self) {
	{
		byte* _Startf0 = JB_Str_Address(Self);
		byte* _Endf1 = _Startf0 + JB_Str_Length(Self);
		while (_Startf0 < _Endf1) {
			uint S = _Startf0[0];
			if (JB_byte_IsUpper(S)) {
				return nil;
			}
			(++_Startf0);
		};
	}
	;
	return true;
}

bool JB_Str_IsOK(JB_String* Self) {
	return (Self != nil) and (((JB_Object*)Self) != ((JB_Object*)JB_Str__Error()));
}

bool JB_Str_IsStatementName(JB_String* Self) {
	return (JB_CS_OperatorContains(JB__Constants_CSWordMiddle, Self)) and ((!JB_byte_IsInt(JB_Str_First(Self))));
}

Ind JB_Str_JBFind(JB_String* Self, uint /*byte*/ Find, int Off, int After) {
	After = JB_int_OperatorMin(After, JB_Str_Length(Self));
	while (Off < After) {
		uint C = JB_Str_ByteValue(Self, Off++);
		if (C == '\\') {
			(++Off);
		}
		 else if (C == Find) {
			if (Find == '$') {
				if (Off >= After) {
					break;
				}
				uint Nxt = JB_Str_ByteValue(Self, Off);
				if (!(((Nxt == '{') or (Nxt == '.')) or JB_CS_HasChar(JB__Constants_CSWordStart, Nxt))) {
					continue;
				}
			}
			return Off - 1;
		}
	};
	return -1;
}

byte JB_Str_Last(JB_String* Self, int Minus) {
	return JB_Str_ByteValue(Self, JB_Str_Length(Self) - (1 + Minus));
}

int JB_Str_LineCount(JB_String* Self) {
	if (!JB_Str_Exists(Self)) {
		return 1;
	}
	return JB_Str_Count(Self, '\n') + 1;
}

ErrorInt JB_Str_MakeEntirePath(JB_String* Self, bool Last) {
	ErrorInt Rz = 0;
	//visible;
	JB_String* P = ((JB_String*)JB_Ternary(Last, Self, JB_Str_Parent(Self)));
	JB_Incr(P);
	{
		JB_String* _Pf0 = JB_Str_TrimSlashes(P, true);
		JB_Incr(_Pf0);
		Ind _if1 = JB_Str_FindSlash(_Pf0, 1);
		while (_if1 > 0) {
			JB_String* S = JB_Str_Range(_Pf0, 0, _if1);
			JB_Incr(S);
			int Err = ((int)JB_Str_MakeDir(S));
			JB_Decr(S);
			if (Err) {
				Rz = Err;
				break;
			}
			_if1 = JB_Str_FindSlash(_Pf0, _if1 + 1);
		};
		JB_Decr(_Pf0);
	}
	;
	JB_Decr(P);
	return Rz;
}

JB_String* JB_Str_Name(JB_String* Self) {
	int Last = JB_Str_TrimLastSub(Self, '/');
	return JB_Str_AfterByte(Self, '/', Last);
}

bool JB_Str_ContainsString(JB_String* Self, JB_String* S) {
	return JB_Ind_SyntaxCast(JB_Str_InStr(Self, S, 0, JB_int__Max(), true));
}

bool JB_Str_OperatorEndsWith(JB_String* Self, JB_String* S) {
	return JB_Str_EndsWith(Self, S, true);
}

int JB_Str_OperatorMinus(JB_String* Self, JB_String* S) {
	return JB_Str_Length(Self) - JB_Str_Length(S);
}

FastString* JB_Str_Out(JB_String* Self, bool Clear) {
	FastString* Rz = nil;
	JB_Incr(Rz);
	JB_File* F = JB_Str_AsFile(Self);
	JB_Incr(F);
	if (Clear and (!JB_File_IsPipe(F))) {
		JB_File_Close(F);
		if (!JB_File_OpenBlank(F)) {
			JB_Decr(F);
			JB_Decr(Rz);
			return nil;
		}
	}
	JB_SetRef(Rz, JB_FS_Constructor(nil));
	(JB_FS_FileSet(Rz, F));
	JB_Decr(F);
	JB_SafeDecr(Rz);
	return Rz;
}

Ind JB_Str_OutByteWithByteIntInt(JB_String* Self, uint /*byte*/ Find, int Start, int After) {
	return JB_Str_OutByte(Self, Start, After, Find);
}

Ind JB_Str_OutCharSet(JB_String* Self, CharSet* Cs, int Start, int After) {
	return JB_Str_CharSet(Self, Start, After, Cs, false);
}

Ind JB_Str_OutWhite(JB_String* Self, int Start, int After) {
	return JB_Str_WhiteSpace(Self, Start, After, false);
}

JB_String* JB_Str_Parent(JB_String* Self) {
	if (!JB_Str_Equals(Self, JB_LUB[4], false)) {
		JB_String* _tmPf0 = JB_Str_TrimSlashes(Self, false);
		JB_Incr(_tmPf0);
		JB_String* _tmPf1 = JB_Str_BeforeLastByte(_tmPf0, '/', 1);
		JB_Incr(_tmPf1);
		JB_Decr(_tmPf0);
		JB_SafeDecr(_tmPf1);
		return _tmPf1;
	}
	return JB_LUB[0];
}

Message* JB_Str_Parse(JB_String* Self, Syntax Owner, bool AllowDecomp) {
	Message* Rz = ((Message*)nil);
	JB_Incr(Rz);
	JB_String* Data = JB_Str_Range(Self, JB_int_OperatorMax(JB_Str_IsJbin(Self), 0), JB_int__Max());
	JB_Incr(Data);
	if (AllowDecomp and JB_Str_IsCompressed(Data)) {
		JB_SetRef(Data, JB_Str_Decompress(Data, JB_int__Max(), nil));
	}
	Ind J2 = JB_Str_IsJbin(Data);
	if (JB_Ind_SyntaxCast(J2)) {
		JB_SetRef(Data, JB_Str_Range(Data, J2, JB_int__Max()));
		JB_SetRef(Rz, JB_Str_ParseJbin(Data, 1073741824));
	}
	 else {
		JB_SetRef(Rz, JB_Str_ParseSub(Data, Owner));
	}
	JB_Decr(Data);
	JB_SafeDecr(Rz);
	return Rz;
}

Message* JB_Str_ParseJbin(JB_String* Self, int64 Max) {
	StringReader* _tmPf0 = JB_Str_Stream(Self);
	JB_Incr(_tmPf0);
	Message* _tmPf1 = JB_SS_ParseJbin(_tmPf0, Max);
	JB_Incr(_tmPf1);
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Message* JB_Str_ParseSub(JB_String* Self, Syntax Owner) {
	if (!JB_Tk__CppInited()) {
		JB_Tk__Init();
	}
	JB_Tk__StartParse(Self);
	JB__Tk__StopBars = 0;
	ErrorMarker OK = JB_Rec_Mark(JB_StdErr);
	int Flags = kJB__Tk_kTemporal;
	Message* Into = JB_Msg_ConstructorRange(nil, nil, Owner, 0, JB_LUB[0], 0);
	JB_Incr(Into);
	if (Owner == kJB_SyxArg) {
		(JB_Msg_SyntaxIsSet(Into, kJB__MsgParseFlags_Style2, true));
	}
	bool Lines = JB_Tk__ParseLoopFlags(Into, JB_LUB[0], Flags);
	if ((!Lines) and JB_Ring_HasChildCount(Into, 1)) {
		JB_SetRef(Into, ((Message*)JB_Ring_First(Into)));
	}
	JB_Tk__CleanSpaces();
	if (JB_Tk__Running()) {
		JB_Tk__Expect(0);
	}
	JB_Tk__StartParse(nil);
	if (!JB_ErrorMarker_SyntaxCast(OK)) {
		JB_SetRef(Into, nil);
	}
	JB_SafeDecr(Into);
	return ((Message*)Into);
}

JB_String* JB_Str_Pluralize(JB_String* Self, int Amount, JB_String* Nothing) {
	if ((!Amount) and JB_Str_Exists(Nothing)) {
		return Nothing;
	}
	FastString* Fs = JB_FS_Constructor(nil);
	JB_Incr(Fs);
	if (Amount) {
		JB_FS_AppendInt32(Fs, Amount);
	}
	 else {
		JB_FS_AppendString(Fs, JB_LUB[60]);
	}
	JB_FS_AppendByte(Fs, ' ');
	JB_FS_AppendString(Fs, Self);
	if (Amount != 1) {
		if (JB_Str_Last(Self, 0) == 's') {
			JB_FS_AppendByte(Fs, 'e');
		}
		JB_FS_AppendByte(Fs, 's');
	}
	JB_String* _tmPf0 = JB_FS_SyntaxCast(Fs);
	JB_Incr(_tmPf0);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

JB_String* JB_Str_Preview(JB_String* Self, int N) {
	//visible;
	if (JB_Str_Length(Self) <= N) {
		return Self;
	}
	JB_String* _tmPf1 = JB_Str_Range(Self, 0, N);
	JB_Incr(_tmPf1);
	JB_String* _tmPf0 = JB_Str_UnicodeSync(_tmPf1);
	JB_Incr(_tmPf0);
	JB_Decr(_tmPf1);
	JB_String* _tmPf2 = JB_Str_OperatorPlus(_tmPf0, JB_LUB[22]);
	JB_Incr(_tmPf2);
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf2);
	return _tmPf2;
}

Array* JB_Str_Split(JB_String* Self, uint /*byte*/ Sep) {
	Array* Rz = ((Array*)JB_Array_Constructor0(nil));
	JB_Incr(Rz);
	{
		StringFields* _LoopSrcf2 = JB_FI_Constructor(nil, Self, Sep);
		JB_Incr(_LoopSrcf2);
		int _Prevf0 = 0;
		while (true) {
			Ind _Curr_f1 = JB_FI_NextSep(_LoopSrcf2, _Prevf0);
			JB_String* Field = JB_FI_Field(_LoopSrcf2, _Prevf0, _Curr_f1);
			JB_Incr(Field);
			JB_Array_SyntaxAppend(Rz, Field);
			JB_Decr(Field);
			_Prevf0 = (_Curr_f1 + 1);
			if (!JB_Ind_SyntaxCast(_Curr_f1)) {
				break;
			}
		};
		JB_Decr(_LoopSrcf2);
	}
	;
	JB_SafeDecr(Rz);
	return Rz;
}

JB_String* JB_Str_Squeeze(JB_String* Self) {
	//visible;
	FastString* Fs = JB_FS_Constructor(nil);
	JB_Incr(Fs);
	bool Broken = false;
	{
		byte* _Startf0 = JB_Str_Address(Self);
		byte* _Endf1 = _Startf0 + JB_Str_Length(Self);
		while (_Startf0 < _Endf1) {
			uint C = _Startf0[0];
			if (JB_byte_IsWhite(C)) {
				Broken = ((bool)Fs->Length);
			}
			 else {
				if (Broken) {
					JB_FS_AppendByte(Fs, ' ');
				}
				JB_FS_AppendByte(Fs, C);
				Broken = false;
			}
			(++_Startf0);
		};
	}
	;
	JB_String* _tmPf3 = JB_FS_SyntaxCast(Fs);
	JB_Incr(_tmPf3);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf3);
	return _tmPf3;
}

StringReader* JB_Str_Stream(JB_String* Self) {
	return JB_SS_Constructor(nil, Self);
}

void JB_Str_Fail(JB_String* Self) {
	//visible;
	JB_Rec__Latchkum(nil, Self, nil);
}

JB_String* JB_Str_TrimFirst(JB_String* Self, uint /*byte*/ B) {
	Ind S = JB_Str_OutByteWithByteIntInt(Self, B, 0, JB_int__Max());
	return JB_Str_Range(Self, (S), JB_int__Max());
}

int JB_Str_TrimLastSub(JB_String* Self, uint /*byte*/ B) {
	int N = JB_Str_Length(Self);
	while (JB_Str_ByteValue(Self, N - 1) == B) {
		(--N);
	};
	return N;
}

JB_String* JB_Str_TrimSlashes(JB_String* Self, bool Pathfix) {
	JB_String* Rz = JB_LUB[0];
	JB_Incr(Rz);
	JB_String* P = ((JB_String*)JB_Ternary(Pathfix, JB_File_PathFix_(Self), Self));
	JB_Incr(P);
	if (!((JB_Str_Last(P, 0) == '/') or JB_Str_ContainsString(P, JB_LUB[61]))) {
		JB_Decr(Rz);
		JB_SafeDecr(P);
		return P;
	}
	JB_Decr(P);
	FastString* Fs = JB_FS_Constructor(nil);
	JB_Incr(Fs);
	int Prev = 0;
	{
		byte* _Startf0 = JB_Str_Address(Self);
		byte* _Endf1 = _Startf0 + JB_Str_Length(Self);
		while (_Startf0 < _Endf1) {
			uint C = _Startf0[0];
			if ((C != '/') or (Prev != '/')) {
				JB_FS_AppendByte(Fs, C);
			}
			Prev = C;
			(++_Startf0);
		};
	}
	;
	if (Prev == '/') {
		(JB_FS_LengthSet(Fs, Fs->Length - 1));
	}
	JB_SetRef(Rz, JB_FS_SyntaxCast(Fs));
	JB_Decr(Fs);
	if ((!JB_Str_Exists(Rz)) and JB_Str_Exists(Self)) {
		JB_SetRef(Rz, JB_LUB[4]);
	}
	JB_SafeDecr(Rz);
	return Rz;
}

JB_String* JB_Str_Unescape(JB_String* Self) {
	return JB_Str_MultiReplaceAll(Self, JB__Constants_UnEscapeStr, JB_StdErr);
}

CharSet* JB_Str_UniCS(JB_String* Self) {
	JB_String* _tmPf0 = JB_Str_OperatorPlus(Self, JB_LUB[62]);
	JB_Incr(_tmPf0);
	CharSet* _tmPf1 = JB_Str_CharSetWithBool((_tmPf0), true);
	JB_Incr(_tmPf1);
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

int JB_Str_UnPrintable(JB_String* Self) {
	if (JB_Ind_SyntaxCast(JB_Str_BadUTF8(Self, 0))) {
		return -1;
	}
	{
		byte* _Startf0 = JB_Str_Address(Self);
		byte* _Endf1 = _Startf0 + JB_Str_Length(Self);
		while (_Startf0 < _Endf1) {
			uint C = _Startf0[0];
			if (!((C >= ' ') or (C == 9))) {
				if (JB_byte_IsTextLine(C)) {
					return '\n';
				}
				return -2;
			}
			(++_Startf0);
		};
	}
	;
	return 0;
}

Array* JB_Str_Words(JB_String* Self) {
	return JB_Str_Split(Self, ' ');
}

JB_StringC* JB_Str__Wrap(_cstring Addr) {
	return JB_StrC(Addr);
}


StringFields* JB_FI_Constructor(StringFields* Self, JB_String* Source, uint /*byte*/ Sep) {
	if (Self == nil) {
		Self = ((StringFields*)JB_NewClass(&StringFieldsData));
	}
	JB_Incr2(Self->Data, Source);
	Self->Sep = Sep;
	return Self;
}

void JB_FI_Destructor(StringFields* Self) {
	JB_Clear(Self->Data);
}

JB_String* JB_FI_Field(StringFields* Self, Ind Prev, Ind Curr) {
	if (!JB_Ind_SyntaxCast(Curr)) {
		Curr = JB_Str_Length(Self->Data);
	}
	return JB_Str_Range(Self->Data, Prev, Curr);
}

Ind JB_FI_NextSep(StringFields* Self, int Prev) {
	return JB_Str_FindByte(Self->Data, Self->Sep, Prev, JB_int__Max());
}


int JB_SS_Byte(StringReader* Self) {
	if (JB_FastBuff_HasAny((&Self->Data))) {
		return JB_FastBuff_Byte((&Self->Data));
	}
	if (JB_SS_NextChunk(Self)) {
		return JB_FastBuff_Byte((&Self->Data));
	}
	return -1;
}

void JB_SS_CompressInto(StringReader* Self, JB_Object* Dest, int Strength, CompressionStats* St) {
	if (Self == nil) {
		JB_Str_Fail(JB_LUB[481]);
		return;
	}
	FastString* J = JB_FS__Use(Dest);
	JB_Incr(J);
	if (!J) {
		JB_Decr(J);
		return;
	}
	St = JB_MzSt_Start(St);
	;
	JB_FS_AppendString(J, JB__JbinHeader);
	JB_bin_Enter(J, kJB_SyxTmp, JB_LUB[482]);
	JB_bin_AddInt(J, Self->Length);
	JB_bin_Enter(J, kJB_SyxArg, JB_LUB[0]);
	while (JB_SS_HasAny(Self)) {
		JB_String* Str = JB_SS_Str(Self, 4194304, 0);
		JB_Incr(Str);
		ivec2 Place = JB_bin_OpenSection(J);
		JB_Str_CompressChunk(J, Str, 2);
		JB_bin_CloseSection(J, Place[0], Place[1], kJB_SyxBin);
		JB_MzSt_LiveUpdate(St, JB_Str_Length(Str), J->Length - Place[0], true);
		JB_Decr(Str);
		if (!JB_SS_NoMoreChunks(Self)) {
			JB_FS_Flush(J);
		}
	};
	JB_bin_Exit(J, 2);
	JB_FS_Flush(J);
	JB_Str_CompressChunk(J, nil, 2);
	JB_Decr(J);
	JB_MzSt_End(St);
}

StringReader* JB_SS_Constructor(StringReader* Self, JB_String* Data) {
	if (Self == nil) {
		Self = ((StringReader*)JB_NewClass(&StringReaderData));
	}
	Self->StartFrom = 0;
	Self->File = nil;
	Self->Data = ((FastBuff){});
	Self->CallBack = nil;
	Self->_Object = nil;
	Self->Length = 0;
	Self->ChunkSize = 0;
	Self->_NoMoreChunks = false;
	JB_SS_Reset(Self, Data);
	return Self;
}

JB_String* JB_SS_Decompress(StringReader* Self, int Lim, CompressionStats* St) {
	FastString* Fs = JB_FS_Constructor(nil);
	JB_Incr(Fs);
	while (JB_SS_HasAny(Self)) {
		if (!JB_SS_DecompressInto(Self, Fs, Lim, St)) {
			(JB_FS_LengthSet(Fs, 0));
			break;
		}
	};
	JB_String* _tmPf0 = JB_FS_SyntaxCast(Fs);
	JB_Incr(_tmPf0);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

bool JB_SS_DecompressInto(StringReader* Self, JB_Object* Dest, int Lim, CompressionStats* St) {
	FastString* Fs = JB_FS__Use(Dest);
	JB_Incr(Fs);
	if (!Fs) {
		JB_Decr(Fs);
		return nil;
	}
	if (!JB_SS_IsCompressed(Self)) {
		JB_String* _tmPf0 = JB_SS_ReadAll(Self);
		JB_Incr(_tmPf0);
		JB_FS_AppendString(Fs, _tmPf0);
		JB_Decr(_tmPf0);
		JB_Decr(Fs);
		return true;
	}
	JB_SS_ExpectJbin(Self);
	Message* Mz = JB_SS_NextMsgExpect(Self, nil, kJB_SyxTmp, nil);
	JB_Incr(Mz);
	Message* _tmPf1 = JB_SS_NextMsgExpect(Self, Mz, kJB_SyxNum, nil);
	JB_Incr(_tmPf1);
	int64 Remaining = JB_Msg_Int(_tmPf1, 0);
	JB_Decr(_tmPf1);
	Message* Arg = JB_SS_NextMsgExpect(Self, Mz, kJB_SyxArg, nil);
	JB_Incr(Arg);
	JB_Decr(Mz);
	if ((Remaining > 0) and ((Remaining <= Lim) and (Arg))) {
		St = JB_MzSt_Start(St);
		while (true) {
			Message* C = JB_SS_NextMsgExpect(Self, Arg, kJB_SyxBin, nil);
			JB_Incr(C);
			if ((!C)) {
				JB_Decr(C);
				break;
			}
			int Expected = JB_Str_DecompressChunk(Fs, C->Name, 0);
			if (!Expected) {
				JB_Decr(C);
				break;
			}
			Remaining = (Remaining - Expected);
			JB_FS_Flush(Fs);
			JB_MzSt_LiveUpdate(St, JB_Msg_Length(C), Expected, false);
			JB_Tree_Remove(C);
			JB_Decr(C);
		};
		JB_MzSt_End(St);
	}
	 else if (Remaining > Lim) {
		if (true) {
			JB_SS_Fail(Self, JB_LUB[494]);
		}
	}
	 else {
		if (true) {
			JB_SS_Fail(Self, JB_LUB[495]);
		}
	}
	JB_Decr(Fs);
	JB_Decr(Arg);
	return (!Self->Data.WentBad);
}

void JB_SS_Destructor(StringReader* Self) {
	JB_Clear(Self->File);
	JB_FastBuff_Destructor((&Self->Data));
	JB_Clear(Self->CallBack);
}

bool JB_SS_ExpectJbin(StringReader* Self) {
	if (JB_SS_IsJBin(Self)) {
		return true;
	}
	if (true) {
		JB_SS_Fail(Self, JB__jBinNotJbin);
	}
	return false;
}

bool JB_SS_HasAny(StringReader* Self) {
	if (Self == nil) {
		return nil;
	}
	if (JB_FastBuff_HasAny((&Self->Data))) {
		return true;
	}
	return JB_SS_NextChunk(Self);
}

int64 JB_SS_hInt(StringReader* Self) {
	int Sh = 0;
	int V = 0;
	while (true) {
		int B = JB_SS_Byte(Self);
		if (B < 0) {
			break;
		}
		V = (V | ((B & 127) << Sh));
		if (B <= 127) {
			return V;
		}
		Sh = (Sh + 7);
		if (Sh > 57) {
			JB_SS_Fail(Self, JB_LUB[432]);
			return 0;
		}
	};
	return 0;
}

bool JB_SS_IsCompressed(StringReader* Self) {
	JB_String* Str = JB_SS_StrNoAdvance(Self, 16);
	JB_Incr(Str);
	bool _tmPf0 = JB_Str_IsCompressed(Str);
	JB_Decr(Str);
	return _tmPf0;
}

bool JB_SS_IsJBin(StringReader* Self) {
	JB_String* _tmPf0 = JB_SS_Str(Self, 4, 0);
	JB_Incr(_tmPf0);
	bool _tmPf1 = JB_Ind_SyntaxCast(JB_Str_IsJbin(_tmPf0));
	JB_Decr(_tmPf0);
	return _tmPf1;
}

bool JB_SS_NextChunk(StringReader* Self) {
	JB_File* F = Self->File;
	if (F) {
		Self->StartFrom = (Self->StartFrom + JB_FastBuff_Size((&Self->Data)));
		if (JB_SS_ReadChunk(Self, F)) {
			return true;
		}
		JB_SetRef(Self->File, nil);
	}
	return false;
}

Message* JB_SS_NextMsgExpect(StringReader* Self, Message* Parent, Syntax Fn, JB_String* Name) {
	Message* Rz = nil;
	Rz = JB_SS_NextMsg(Self);
	if (!Rz) {
		return nil;
	}
	if (!(JB_Msg_Expect(Rz, Fn, Name) and (JB_Tree_OperatorIn(Rz, Parent)))) {
		JB_Msg_Fail(Rz, nil);
		return nil;
	}
	return Rz;
}

Message* JB_SS_NextMsg(StringReader* Self) {
	return ((Message*)JB_SS_NextMsgInfo(Self));
}

uint64 JB_SS_NextMsgInfo(StringReader* Self) {
	Message* Msg = ((Message*)Self->_Object);
	int Info = 0;
	while (true) {
		Info = JB_SS_NonZeroByte(Self);
		if (Info <= 239) {
			break;
		}
		Msg = ((Message*)JB_Tree_Upward(Msg, Info - 239));
		Self->_Object = Msg;
		if (!Msg) {
			return 0;
		}
	};
	Syntax T = ((Syntax)(Info >> 1));
	if ((T < kJB_Syxmax) and (T > kJB_SyxNil)) {
		Msg = JB_Msg_Msg(Msg, T, JB_SS_Str(Self, JB_SS_hInt(Self), 0));
		if (Info & 1) {
			Self->_Object = Msg;
		}
		ParserCallBack* Cb = Self->CallBack;
		if (Cb) {
			JB_SS_ParserCallBack_interface_SyntaxCall((Cb), Msg);
		}
		return ((uint64)Msg);
	}
	Self->_Object = nil;
	if (Info >= 0) {
		if (T <= kJB_SyxNil) {
			JB_SS_Fail(Self, JB_LUB[483]);
			return 0;
		}
		if (true) {
			JB_SS_Fail(Self, JB_LUB[484]);
		}
	}
	return 0;
}

bool JB_SS_NoMoreChunks(StringReader* Self) {
	if (Self->_NoMoreChunks) {
		return true;
	}
	if (JB_FastBuff_Remaining((&Self->Data)) <= 0) {
		if (!Self->File) {
			return true;
		}
		if (Self->Length <= Self->StartFrom) {
			return true;
		}
	}
	return false;
}

int JB_SS_NonZeroByte(StringReader* Self) {
	while (true) {
		int B = JB_SS_Byte(Self);
		if (B) {
			return B;
		}
	};
}

Message* JB_SS_ParseJbin(StringReader* Self, int64 Remain) {
	Message* Rz = ((Message*)nil);
	JB_Incr(Rz);
	if (!JB_SS_ExpectJbin(Self)) {
		JB_Decr(Rz);
		return nil;
	}
	Self->_Object = nil;
	JB_SetRef(Rz, JB_SS_NextMsg(Self));
	while ((--Remain) > 0) {
		if (!JB_SS_NextMsgInfo(Self)) {
			break;
		}
	};
	if (Self->Data.WentBad) {
		JB_SetRef(Rz, nil);
	}
	JB_SafeDecr(Rz);
	return Rz;
}

ParserCallBack* JB_SS_ParserCallBack_Constructor(ParserCallBack* Self, StringReader* Upon) {
	if (Self == nil) {
		Self = ((ParserCallBack*)JB_Task_Constructor(nil, 256, ((void*)(&JB_SS_ParserCallBack_run))));
	}
	JB_Incr2(Self->Upon, Upon);
	//task;
	return Self;
}

int64 JB_SS_Position(StringReader* Self) {
	return JB_FastBuff_Position((&Self->Data)) + Self->StartFrom;
}

void JB_SS_PositionSet(StringReader* Self, int64 Value) {
	(JB_FastBuff_PositionSet((&Self->Data), Value - Self->StartFrom));
}

JB_String* JB_SS_ReadAll(StringReader* Self) {
	return JB_SS_Str(Self, Self->Length - Self->StartFrom, 0);
}

bool JB_SS_ReadChunk(StringReader* Self, JB_File* F) {
	JB_String* _tmPf0 = JB_File_Read(F, Self->ChunkSize, true);
	JB_Incr(_tmPf0);
	(JB_FastBuff_ReadFromSet((&Self->Data), _tmPf0));
	JB_Decr(_tmPf0);
	if (JB_Str_Length(Self->Data.ReadFrom) < Self->ChunkSize) {
		Self->_NoMoreChunks = true;
	}
	return JB_Str_Exists(Self->Data.ReadFrom);
}

int JB_SS_Remaining(StringReader* Self) {
	return Self->Length - JB_SS_Position(Self);
}

void JB_SS_Reset(StringReader* Self, JB_String* Data) {
	(JB_FastBuff_ReadFromSet((&Self->Data), Data));
	Self->Length = JB_Str_Length(Data);
	Self->_NoMoreChunks = true;
}

JB_String* JB_SS_Str(StringReader* Self, int N, int Skip) {
	if (!((N > 0) and (Skip < N))) {
		return JB_LUB[0];
	}
	if ((JB_FastBuff_Has((&Self->Data), N)) or (JB_SS_NoMoreChunks(Self))) {
		(N = JB_int_OperatorMin(N, JB_SS_Remaining(Self)));
		int Pos = JB_FastBuff_Position((&Self->Data));
		(JB_FastBuff_PositionSet((&Self->Data), N + Pos));
		return JB_FastBuff_AccessStr((&Self->Data), Pos + Skip, JB_FastBuff_Position((&Self->Data)));
	}
	int Remaining = N - Skip;
	JB_String* R = JB_Str_New(Remaining);
	JB_Incr(R);
	if (!JB_Str_Exists(R)) {
		JB_Decr(R);
		return JB_LUB[0];
	}
	byte* Dest = R->Addr;
	while (true) {
		int Copied = JB_FastBuff_CopyTo((&Self->Data), Dest, JB_int_OperatorMin(JB_FastBuff_Remaining((&Self->Data)), Remaining));
		Remaining = (Remaining - Copied);
		Dest = (Dest + Copied);
		if (Remaining <= 0) {
			break;
		}
		if (!JB_SS_NextChunk(Self)) {
			JB_String* _tmPf0 = JB_Str_Range(R, 0, JB_Str_Length(R) - Remaining);
			JB_Incr(_tmPf0);
			JB_SetRef(R, JB_Str_Copy(_tmPf0));
			JB_Decr(_tmPf0);
			break;
		}
	};
	JB_SafeDecr(R);
	return R;
}

JB_String* JB_SS_StrNoAdvance(StringReader* Self, int N) {
	JB_String* Rz = JB_LUB[0];
	JB_Incr(Rz);
	int64 P = JB_SS_Position(Self);
	JB_SetRef(Rz, JB_SS_Str(Self, N, 0));
	(JB_SS_PositionSet(Self, P));
	JB_SafeDecr(Rz);
	return Rz;
}

void JB_SS_Fail(StringReader* Self, JB_String* Error) {
	Self->_Object = nil;
	if (Self->Data.WentBad) {
		return;
	}
	Self->Data.WentBad = true;
	if (!JB_Str_Exists(Error)) {
		if (Self->File) {
			Error = JB_LUB[373];
		}
		 else {
			Error = JB_LUB[374];
		}
	}
	JB_Rec__Latchkum(nil, Error, Self->File);
}


SyntaxObj* JB_Fn_Constructor(SyntaxObj* Self, FP_fpMsgRender Msg, JB_String* Name, int ID) {
	if (Self == nil) {
		Self = ((SyntaxObj*)JB_NewClass(&SyntaxObjData));
	}
	JB_Incr2(Self->LongName, JB_LUB[0]);
	Self->RenderAddr = Msg;
	JB_Incr2(Self->Name, Name);
	Self->ID = ((Syntax)ID);
	Self->ExportAddr = JB_Msg_Dummy;
	return Self;
}

void JB_Fn_Destructor(SyntaxObj* Self) {
	JB_Clear(Self->LongName);
	JB_Clear(Self->Name);
}

JB_String* JB_Fn_Render(SyntaxObj* Self, FastString* Fs_in) {
	if (!Fs_in) {
		return JB_Str_LowerCase(Self->LongName);
	}
	JB_String* _tmPf0 = JB_Str_LowerCase(Self->LongName);
	JB_Incr(_tmPf0);
	JB_FS_AppendString(Fs_in, _tmPf0);
	JB_Decr(_tmPf0);
	return JB_LUB[0];
}



JB_Object* JB_Array_Last(Array* Self) {
	return JB_Array_Value(Self, JB_Array_Size(Self) - 1);
}

void JB_Array_LoadProperties(Array* Self, ObjectLoader* Loader) {
	while (JB_LD_HasItem(Loader)) {
		JB_Array_SyntaxAppend(Self, JB_LD_Object(Loader));
	};
}

void JB_Array_SaveCollect(Array* Self, ObjectSaver* Saver) {
	{
		int _if0 = 0;
		while (true) {
			JB_Object* V = JB_Array_Value(Self, _if0);
			if (V == nil) {
				break;
			}
			JB_Object_SaveTryCollect(V, Saver);
			(++_if0);
		};
	};
}

void JB_Array_SaveWrite(Array* Self, ObjectSaver* Saver) {
	FastString* D = Saver->Dest;
	{
		int _if0 = 0;
		int _firstf2 = _if0;
		while (true) {
			JB_Object* V = JB_Array_Value(Self, _if0);
			if (V == nil) {
				break;
			}
			if (_firstf2 != _if0) {
				JB_FS_AppendString(D, JB_LUB[6]);
			}
			//start;
			JB_FS_AppendObjectOrNil(D, V);
			(++_if0);
		};
	};
}

void JB_Array_SyntaxAppend(Array* Self, JB_Object* Item) {
	JB_Array_AppendCount(Self, Item, 1);
}


void JB_Dict_LoadProperties(Dictionary* Self, ObjectLoader* Loader) {
	while (JB_LD_HasItem(Loader)) {
		JB_String* Name = JB_LD_ItemName(Loader);
		if (JB_LD_ItemIsInt(Loader)) {
			(JB_Dict_ValueSet(Self, Name, JB_Wrap_ConstructorInt(nil, JB_LD_ItemInt(Loader))));
		}
		 else {
			(JB_Dict_ValueSet(Self, Name, JB_LD_ItemObject(Loader)));
		}
	};
}

void JB_Dict_SaveCollect(Dictionary* Self, ObjectSaver* Saver) {
	{
		DictionaryReader* _navf0 = JB_Dict_Navigate(Self);
		while (true) {
			JB_Object* V = JB_DictionaryReader_NextValue(_navf0);
			if (V == nil) {
				break;
			}
			JB_Object_SaveTryCollect(V, Saver);
		};
	};
}

void JB_Dict_SaveWrite(Dictionary* Self, ObjectSaver* Saver) {
	FastString* D = Saver->Dest;
	DictionaryReader* L = JB_Dict_Navigate(Self);
	while (JB_Nav_MoveNext(L)) {
		JB_FS_AppendString(D, JB_Nav_Name(L));
		JB_FS_AppendString(D, JB_LUB[73]);
		JB_FS_AppendObjectOrNil(D, JB_Nav_Value(L));
		JB_FS_AppendByte(D, ',');
	};
}

JB_Object* JB_Dict_Value0(Dictionary* Self, JB_String* Key) {
	return JB_Dict_Value(Self, Key, nil);
}

void JB_Dict_SetInt(Dictionary* Self, uint64 Key, JB_Object* Value) {
	(JB_Dict_ValueSet(Self, JB_int64_DictName(((int64)Key)), Value));
}

JB_Object* JB_Dict_ValueInt(Dictionary* Self, uint64 Key) {
	return JB_Dict_Value0(Self, JB_int64_DictName(((int64)Key)));
}

JB_Object* JB_Dict_ValueLower(Dictionary* Self, JB_String* S) {
	if (JB_Str_IsLower(S)) {
		return JB_Dict_Value0(Self, S);
	}
	JB_String* _tmPf0 = JB_Str_LowerCase(S);
	JB_Incr(_tmPf0);
	JB_Object* _tmPf1 = JB_Dict_Value0(Self, _tmPf0);
	JB_Incr(_tmPf1);
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Dictionary* JB_Dict__Copy(Dictionary* Dict) {
	Dictionary* Rz = ((Dictionary*)nil);
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Dict_Constructor(nil));
	{
		DictionaryReader* _navf0 = JB_Dict_Navigate(Dict);
		JB_Incr(_navf0);
		while (true) {
			JB_String* Value = ((JB_String*)JB_DictionaryReader_NextValue(_navf0));
			JB_Incr(Value);
			if (Value == nil) {
				JB_Decr(Value);
				break;
			}
			JB_String* Key = JB_Nav_Name(_navf0);
			JB_Incr(Key);
			(JB_Dict_ValueSet(Rz, Key, Value));
			JB_Decr(Value);
			JB_Decr(Key);
		};
		JB_Decr(_navf0);
	}
	;
	JB_SafeDecr(Rz);
	return Rz;
}

Dictionary* JB_Dict__Reverse(Dictionary* Dict) {
	Dictionary* Rz = ((Dictionary*)nil);
	JB_Incr(Rz);
	JB_SetRef(Rz, JB_Dict_Constructor(nil));
	{
		DictionaryReader* _navf0 = JB_Dict_Navigate(Dict);
		JB_Incr(_navf0);
		while (true) {
			JB_String* Value = ((JB_String*)JB_DictionaryReader_NextValue(_navf0));
			JB_Incr(Value);
			if (Value == nil) {
				JB_Decr(Value);
				break;
			}
			JB_String* Key = JB_Nav_Name(_navf0);
			JB_Incr(Key);
			(JB_Dict_ValueSet(Rz, Value, Key));
			JB_Decr(Value);
			JB_Decr(Key);
		};
		JB_Decr(_navf0);
	}
	;
	JB_SafeDecr(Rz);
	return Rz;
}


JB_File* JB_File_Child(JB_File* Self, JB_String* Name) {
	if ((!JB_Str_Exists(Name))) {
		JB_String* _tmPf0 = JB_Str_OperatorPlus(JB_LUB[405], Self);
		JB_Incr(_tmPf0);
		JB_File_Fail(Self, _tmPf0);
		JB_Decr(_tmPf0);
	}
	JB_String* _tmPf1 = JB_Str_Child(((JB_String*)Self), Name);
	JB_Incr(_tmPf1);
	JB_File* _tmPf2 = JB_File_Constructor(nil, _tmPf1);
	JB_Incr(_tmPf2);
	JB_Decr(_tmPf1);
	JB_SafeDecr(_tmPf2);
	return _tmPf2;
}

bool JB_File_Opened(JB_File* Self) {
	return Self->Descriptor >= 0;
}

JB_File* JB_File_SyntaxAccess(JB_File* Self, JB_String* Name) {
	return JB_File_Child(Self, Name);
}

void JB_File_SyntaxAppend(JB_File* Self, JB_String* Data) {
	JB_File_Write(Self, Data);
}

void JB_File_Fail(JB_File* Self, JB_String* Error) {
	JB_Rec__Latchkum(nil, Error, ((JB_String*)JB_Ternary(((bool)Self), ((JB_String*)JB_File_Path(Self)), ((JB_String*)JB_LUB[0]))));
}

int JB_File__Init_() {
	{
		JB_SetRef(JB__File__Speedie, JB_LUB[0]);
	}
	;
	return 0;
}

JB_File* JB_File__Logs() {
	return JB_Str_AsFile(JB_LUB[122]);
}


jbinLeaver JB_bin_Add(FastString* Self, Syntax Type, JB_String* Name, bool Into) {
	return JB_bin_AddMemory(Self, Type, JB_Str_Length(Name), Into, Name->Addr);
}

void JB_bin_AddInt(FastString* Self, int64 Name) {
	JB_String* _tmPf0 = JB_int64_Render(Name, nil);
	JB_Incr(_tmPf0);
	JB_bin_Add(Self, kJB_SyxNum, _tmPf0, false);
	JB_Decr(_tmPf0);
}

jbinLeaver JB_bin_AddMemory(FastString* Self, Syntax Type, uint64 L, bool GoIn, byte* Data) {
	int T = (((int)Type) << 1) | (GoIn);
	JB_FS_AppendByte(Self, ((byte)T));
	JB_FS_hInt(Self, L);
	if (Data) {
		JB_FS_AppendMem_(Self, Data, ((int)L));
	}
	Self->Indent = (Self->Indent + ((int)GoIn));
	return ((int)GoIn);
}

void JB_bin_CloseSection(FastString* Self, int C, int R, Syntax Type) {
	int CurrLen = Self->Length;
	if (CurrLen < C) {
		JB_Object_FailStr(Self, JB_LUB[446]);
		return;
	}
	Self->Length = (C - 6);
	int Blen = 5;
	C = (CurrLen - C);
	int Actual = C;
	while (true) {
		Actual = (Actual >> 7);
		(--Blen);
		if ((!Actual)) {
			break;
		}
	};
	JB_FS_AppendMultiByte(Self, ((byte)0), Blen);
	JB_FS_AppendByte(Self, ((byte)(((int)Type) << 1)));
	JB_FS_hInt(Self, C);
	Self->Length = CurrLen;
	int Nf = (--Self->NoFlush);
	if ((!Nf) and (Self->Length >= (R >> 1))) {
		JB_FS_Flush(Self);
	}
}

FastString* JB_bin_Constructor0(FastString* Self, int N) {
	if (Self == nil) {
		Self = ((FastString*)JB_NewClass(&FastStringData));
	}
	JB_FS_Constructor(Self);
	if (N) {
	}
	return Self;
}

jbinLeaver JB_bin_Enter(FastString* Self, Syntax Type, JB_String* Name) {
	return JB_bin_Add(Self, Type, Name, true);
}

void JB_bin_Exit(FastString* Self, int Amount) {
	int Add = 239;
	while (Amount > 0) {
		int B = JB_int_OperatorMin((Add + Amount), (255));
		JB_FS_AppendByte(Self, ((byte)B));
		Amount = (Amount - (B - Add));
	};
}

ivec2 JB_bin_OpenSection(FastString* Self) {
	(++Self->NoFlush);
	Self->Length = (Self->Length + 6);
	return ivec2{Self->Length, Self->Reserved};
}

void JB_bin_Sheb(FastString* Self, JB_String* Name) {
	JB_FS_AppendByte(Self, '#');
	JB_FS_AppendByte(Self, '!');
	JB_FS_AppendString(Self, Name);
	JB_FS_AppendByte(Self, '\n');
}







void JB_Tree_Clear(JB_List* Self) {
	while (true) {
		JB_List* F = JB_Ring_First(Self);
		if (!F) {
			return;
		}
		JB_Tree_Remove(F);
	};
}

bool JB_Tree_HasOneChild(JB_List* Self) {
	return JB_Ring_HasChildCount(Self, 1);
}

void jdb2(JB_List* Self) {
	//visible;
	if (Self) {
		JB_String* _tmPf0 = JB_Msg_JDB_(((Message*)Self), nil, 1);
		JB_Incr(_tmPf0);
		JB_PrintLine(_tmPf0);
		JB_Decr(_tmPf0);
	}
	 else {
		JB_PrintLine(JB_LUB[226]);
	}
}

void jdb3(JB_List* Self) {
	//visible;
	if (Self) {
		JB_String* _tmPf0 = JB_Msg_JDB_(((Message*)Self), nil, 3);
		JB_Incr(_tmPf0);
		JB_PrintLine(_tmPf0);
		JB_Decr(_tmPf0);
	}
	 else {
		JB_PrintLine(JB_LUB[226]);
	}
}

bool JB_Tree_OperatorIn(JB_List* Self, JB_List* F) {
	return JB_Ring_Parent(Self) == F;
}

void JB_Tree_Remove(JB_List* Self) {
	(JB_Ring_ParentSet(Self, nil));
}

JB_String* JB_List_Render(JB_List* Self, FastString* Fs_in) {
	FastString* Fs = JB_FS__FastNew(Fs_in);
	JB_Incr(Fs);
	//visible;
	JB_FS_AppendInt32(Fs, Self->Position);
	JB_FS_AppendByte(Fs, ':');
	JB_FS_AppendByte(Fs, '(');
	{
		JB_List* F = JB_Ring_First(Self);
		JB_Incr(F);
		while (F) {
			JB_List* _Nf1 = (JB_Ring_NextSib(F));
			JB_Incr(_Nf1);
			JB_FreeIfDead(JB_Object___Render__(F, Fs));
			JB_FS_AppendByte(Fs, ',');
			JB_FS_AppendByte(Fs, ' ');
			JB_SetRef(F, _Nf1);
			JB_Decr(_Nf1);
		};
		JB_Decr(F);
		;
	}
	;
	JB_FS_AppendByte(Fs, ')');
	JB_String* _tmPf2 = JB_FS_SmartResult(Fs, Fs_in);
	JB_Incr(_tmPf2);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf2);
	return _tmPf2;
}

JB_List* JB_Tree_Second(JB_List* Self) {
	JB_List* X = JB_Ring_First(Self);
	if (X) {
		return JB_Ring_NextSib(X);
	}
	return nil;
}

void JB_Tree_SyntaxAppend(JB_List* Self, JB_List* Last) {
	(JB_Ring_LastSet(Self, Last));
}

JB_List* JB_Tree_Upward(JB_List* Self, int N) {
	while (Self and ((--N) >= 0)) {
		Self = JB_Ring_Parent(Self);
	};
	return Self;
}




void JB_Msg_Acc__(Message* Self, FastString* Fs) {
	Message* F = ((Message*)JB_Ring_First(Self));
	JB_Incr(F);
	if (F) {
		JB_FS_SyntaxAppend(Fs, F);
		JB_SetRef(F, ((Message*)JB_Ring_NextSib(F)));
		if (F) {
			JB_Msg_RenderPrm(F, Fs, '[', ']');
		}
	}
	JB_Decr(F);
}

void JB_Msg_CantFind(Message* Self, Syntax S, JB_String* Name, Message* Found) {
	JB_Incr(Found);
	if (!Self) {
		JB_API__NilHandler();
		JB_Decr(Found);
		return;
	}
	FastString* Fs = JB_FS_Constructor(nil);
	JB_Incr(Fs);
	if (Found) {
		JB_FS_AppendString(Fs, JB_LUB[199]);
		JB_FS_MsgErrorName(Fs, Name);
		JB_String* _tmPf0 = JB_Syx_LongName(S);
		JB_Incr(_tmPf0);
		JB_FS_AppendString(Fs, _tmPf0);
		JB_Decr(_tmPf0);
		JB_FS_AppendString(Fs, JB_LUB[369]);
		JB_String* _tmPf1 = JB_Syx_LongName(Found->Func);
		JB_Incr(_tmPf1);
		JB_FS_AppendString(Fs, _tmPf1);
		JB_Decr(_tmPf1);
	}
	 else {
		if (S) {
			JB_FS_AppendString(Fs, JB_LUB[370]);
			JB_String* _tmPf2 = JB_Syx_LongName(S);
			JB_Incr(_tmPf2);
			JB_FS_AppendString(Fs, _tmPf2);
			JB_Decr(_tmPf2);
		}
		 else {
			JB_FS_AppendString(Fs, JB_LUB[371]);
		}
		JB_FS_MsgErrorName(Fs, Name);
		JB_SetRef(Found, Self);
	}
	JB_String* _tmPf3 = JB_FS_GetResult(Fs);
	JB_Incr(_tmPf3);
	JB_Decr(Fs);
	JB_Rec__Latchkum(Found, _tmPf3, nil);
	JB_Decr(_tmPf3);
	JB_Decr(Found);
}

void JB_Msg_Adj__(Message* Self, FastString* Fs) {
	Message* F = ((Message*)JB_Ring_First(Self));
	if (F) {
		Message* L = ((Message*)JB_Ring_NextSib(F));
		if (L) {
			JB_FS_SyntaxAppend(Fs, F);
			JB_FS_AppendString(Fs, JB_LUB[129]);
			JB_FS_SyntaxAppend(Fs, L);
		}
	}
}

int JB_Msg_After(Message* Self) {
	return Self->Position + Self->RangeLength;
}

void JB_Msg_AfterSet(Message* Self, int Value) {
	Self->RangeLength = (Value - Self->Position);
}

void JB_Msg_ARel__(Message* Self, FastString* Fs) {
	Message* _tmPf0 = ((Message*)JB_Ring_First(Self));
	JB_Incr(_tmPf0);
	JB_FS_SyntaxAppend(Fs, _tmPf0);
	JB_Decr(_tmPf0);
	JB_FS_AppendString(Fs, Self->Name);
}

void JB_Msg_Arg__(Message* Self, FastString* Fs) {
	bool Braces = (((Message*)JB_Ring_Parent(Self)) and (!JB_Msg_SyntaxIs(Self, kJB__MsgParseFlags_Style2))) or ((!JB_Ring_HasChildren(Self)) or (JB_Str_Exists(Self->Name) or (JB_Msg_OperatorIn(Self, kJB_SyxArg))));
	if (Braces) {
		JB_FS_AppendByte(Fs, '{');
	}
	JB_Msg_FSListArg(Self, Fs, Braces);
	if (Braces) {
		JB_FS_AppendIndent(Fs);
		JB_FS_AppendByte(Fs, '}');
		if (JB_Msg_EqualsSyx(((Message*)JB_Ring_Parent(Self)), kJB_SyxTmp, false)) {
			JB_FS_AppendByte(Fs, '\n');
		}
	}
	 else if (!((Message*)JB_Ring_Parent(Self))) {
		JB_FS_AppendByte(Fs, '\n');
	}
}

void JB_Msg_Arr__(Message* Self, FastString* Fs) {
	JB_FS_AppendByte(Fs, '[');
	JB_Msg_FSListSep(Self, Fs, JB_LUB[6]);
	JB_FS_AppendByte(Fs, ']');
}

void JB_Msg_Ask__(Message* Self, FastString* Fs) {
	JB_Msg_BinnRender(Self, Fs, JB_LUB[225], JB_LUB[0]);
}

void JB_Msg_Back__(Message* Self, FastString* Fs) {
	if (JB_Ind_SyntaxCast(JB_Str_FindByte(Self->Name, '`', 0, JB_int__Max()))) {
		JB_Msg_Str__(Self, Fs);
	}
	 else {
		JB_FS_AppendByte(Fs, '`');
		JB_FS_AppendString(Fs, Self->Name);
		JB_FS_AppendByte(Fs, '`');
	}
}

void JB_Msg_Badj__(Message* Self, FastString* Fs) {
	Message* F = ((Message*)JB_Ring_First(Self));
	if (F) {
		Message* L = ((Message*)JB_Ring_NextSib(F));
		if (L) {
			JB_FS_SyntaxAppend(Fs, L);
			JB_FS_AppendString(Fs, JB_LUB[130]);
			JB_FS_SyntaxAppend(Fs, F);
		}
	}
}

void JB_Msg_BecomeStr(Message* Self, Syntax Fn, JB_String* Name) {
	Self->Func = Fn;
	JB_SetRef(Self->Name, Name);
}

void JB_Msg_Bin__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, JB_LUB[47]);
	JB_FS_AppendHexStr(Fs, Self->Name);
	JB_FS_AppendString(Fs, JB_LUB[48]);
}

void JB_Msg_binn__(Message* Self, FastString* Fs) {
	JB_Msg_BinnRender(Self, Fs, JB_LUB[236], JB_LUB[0]);
}

void JB_Msg_BinnRender(Message* Self, FastString* Fs, JB_String* Sepa, JB_String* Sepb) {
	Message* F = ((Message*)JB_Ring_First(Self));
	if (!F) {
		return;
	}
	Message* Opp = ((Message*)JB_Ring_NextSib(F));
	if (!Opp) {
		return;
	}
	Message* L = ((Message*)JB_Ring_NextSib(Opp));
	Message* OF = ((Message*)JB_Ring_First(Opp));
	JB_FS_AppendString(Fs, Sepa);
	JB_FS_SyntaxAppend(Fs, ((Message*)JB_Ternary(OF, OF, Opp)));
	JB_FS_AppendByte(Fs, ' ');
	JB_FS_SyntaxAppend(Fs, F);
	if ((!OF)) {
		return;
	}
	Message* ON = ((Message*)JB_Ring_NextSib(OF));
	if (ON) {
		JB_FS_AppendByte(Fs, ' ');
		JB_FS_SyntaxAppend(Fs, ON);
	}
	if (L) {
		JB_FS_AppendByte(Fs, ' ');
		JB_FS_SyntaxAppend(Fs, L);
	}
}

void JB_Msg_Bra__(Message* Self, FastString* Fs) {
	JB_FS_AppendByte(Fs, '(');
	Message* _tmPf0 = ((Message*)JB_Ring_First(Self));
	JB_Incr(_tmPf0);
	JB_FS_SyntaxAppend(Fs, _tmPf0);
	JB_Decr(_tmPf0);
	JB_FS_AppendByte(Fs, ')');
}

void JB_Msg_BRel__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, Self->Name);
	Message* _tmPf0 = ((Message*)JB_Ring_First(Self));
	JB_Incr(_tmPf0);
	JB_FS_SyntaxAppend(Fs, _tmPf0);
	JB_Decr(_tmPf0);
}

void JB_Msg_Char__(Message* Self, FastString* Fs) {
	JB_FS_AppendByte(Fs, '\'');
	JB_String* _tmPf0 = JB_Str_EscapeChr(Self->Name);
	JB_Incr(_tmPf0);
	JB_FS_AppendString(Fs, _tmPf0);
	JB_Decr(_tmPf0);
	JB_FS_AppendByte(Fs, '\'');
}

int JB_Msg_CleanIndent(Message* Self) {
	return Self->Indent & (~1);
}

void JB_Msg_Cnj__(Message* Self, FastString* Fs) {
	JB_FS_AppendByte(Fs, '#');
	JB_FS_AppendString(Fs, Self->Name);
}

Message* JB_Msg_ConstructorCopy(Message* Self, Message* Other) {
	if (Self == nil) {
		Self = ((Message*)JB_NewClass(&MessageData));
	}
	JB_Ring_Constructor0(Self);
	(++JB__Tk_CountStats);
	Self->Position = Other->Position;
	JB_Incr2(Self->Name, Other->Name);
	Self->Func = Other->Func;
	JB_Incr2(Self->Obj, Other->Obj);
	Self->Indent = Other->Indent;
	Self->Flags = (Other->Flags | JB__Tk_Using.Flags);
	Self->RangeLength = Other->RangeLength;
	Self->Tag = Other->Tag;
	return Self;
}

Message* JB_Msg_ConstructorEmpty(Message* Self) {
	if (Self == nil) {
		Self = ((Message*)JB_NewClass(&MessageData));
	}
	JB_Ring_Constructor0(Self);
	JB_Incr2(Self->Name, JB_LUB[0]);
	Self->Indent = 0;
	(++JB__Tk_CountStats);
	Self->Func = kJB_SyxArg;
	Self->Position = JB__Tk_Using.Position;
	Self->Flags = JB__Tk_Using.Flags;
	Self->RangeLength = JB__Tk_Using.Length;
	Self->Tag = JB__Tk_Using.Tag;
	return Self;
}

Message* JB_Msg_ConstructorNormal(Message* Self, Syntax Func, JB_String* Name) {
	if (Self == nil) {
		Self = ((Message*)JB_NewClass(&MessageData));
	}
	JB_Ring_Constructor0(Self);
	Self->Indent = 0;
	(++JB__Tk_CountStats);
	JB_Incr2(Self->Name, Name);
	Self->Func = Func;
	Self->Position = JB__Tk_Using.Position;
	Self->Flags = JB__Tk_Using.Flags;
	Self->RangeLength = JB__Tk_Using.Length;
	Self->Tag = JB__Tk_Using.Tag;
	return Self;
}

Message* JB_Msg_ConstructorRange(Message* Self, Message* Parent, Syntax Func, int BytePos, JB_String* Name, int RangeLength) {
	if (Self == nil) {
		Self = ((Message*)JB_NewClass(&MessageData));
	}
	JB_Ring_Constructor(Self, Parent);
	Self->Indent = 0;
	(++JB__Tk_CountStats);
	JB_Incr2(Self->Name, Name);
	Self->Position = BytePos;
	Self->Func = Func;
	Self->RangeLength = RangeLength;
	Self->Flags = JB__Tk_Using.Flags;
	Self->Tag = JB__Tk_Using.Tag;
	return Self;
}

Message* JB_Msg_Copy(Message* Self, Message* Pos_msg) {
	Message* Rz = nil;
	Rz = ((Message*)JB_Ternary(Pos_msg, Pos_msg, Self));
	if (true) {
		MessagePosition _usingf0 = ((MessagePosition){});
		JB_Msg_SyntaxUsing(Rz, (&_usingf0));
		Rz = JB_Msg_CopyWithoutUsing(Self, Pos_msg);
		JB_MsgPos_SyntaxUsingComplete((&_usingf0), Rz);
		JB_MsgPos_Destructor((&_usingf0));
	}
	return Rz;
}

JB_String* JB_Msg_CopyID(Message* Self) {
	return JB_LUB[0];
}

Message* JB_Msg_CopyWithoutUsing(Message* Self, Message* P) {
	Message* Rz = nil;
	Rz = JB_Msg_ConstructorCopy(nil, Self);
	if (P) {
		Rz->Position = P->Position;
		Rz->RangeLength = P->RangeLength;
	}
	{
		Message* V = ((Message*)JB_Ring_First(Self));
		while (V) {
			Message* _Nf1 = (((Message*)JB_Ring_NextSib(V)));
			JB_Tree_SyntaxAppend(Rz, JB_Msg_CopyWithoutUsing(V, P));
			V = _Nf1;
		};
		;
	}
	;
	return Rz;
}

void JB_Msg_Decl__(Message* Self, FastString* Fs) {
	Message* Ch = ((Message*)JB_Ring_First(Self));
	JB_Incr(Ch);
	if (!Ch) {
		JB_Decr(Ch);
		return;
	}
	JB_FS_AppendByte(Fs, '|');
	JB_FS_SyntaxAppend(Fs, Ch);
	JB_FS_AppendByte(Fs, '|');
	JB_SetRef(Ch, ((Message*)JB_Ring_NextSib(Ch)));
	while (Ch) {
		JB_FS_AppendByte(Fs, ' ');
		JB_FS_SyntaxAppend(Fs, Ch);
		JB_SetRef(Ch, ((Message*)JB_Ring_NextSib(Ch)));
	};
	JB_Decr(Ch);
}

void JB_Msg_Destructor(Message* Self) {
	JB_Clear(Self->Name);
	JB_Ring_Destructor(Self);
}

void JB_Msg_Dot__(Message* Self, FastString* Fs) {
	Message* Ch = ((Message*)JB_Ring_First(Self));
	JB_Incr(Ch);
	if (Ch) {
		JB_FS_SyntaxAppend(Fs, Ch);
	}
	JB_FS_AppendByte(Fs, '.');
	JB_FS_AppendString(Fs, Self->Name);
	if (Ch) {
		Message* _tmPf0 = ((Message*)JB_Ring_NextSib(Ch));
		JB_Incr(_tmPf0);
		JB_FS_SyntaxAppend(Fs, _tmPf0);
		JB_Decr(_tmPf0);
	}
	JB_Decr(Ch);
}

void JB_Msg_Dummy(Message* Self, FastString* Fs) {
}

void JB_Msg_Emb__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, Self->Name);
	if (!JB_Ring_HasChildren(Self)) {
		return;
	}
	JB_Msg_RenderWithSpaces(Self, Fs, nil);
}

void JB_Msg_ERel__(Message* Self, FastString* Fs) {
	Message* Ch = ((Message*)JB_Ring_First(Self));
	JB_Incr(Ch);
	if (!Ch) {
		JB_Decr(Ch);
		return;
	}
	JB_FS_SyntaxAppend(Fs, Ch);
	JB_FS_AppendByte(Fs, ' ');
	JB_SetRef(Ch, ((Message*)JB_Ring_NextSib(Ch)));
	if (!Ch) {
		JB_Decr(Ch);
		return;
	}
	JB_FS_SyntaxAppend(Fs, Ch);
	JB_FS_AppendString(Fs, JB_LUB[131]);
	JB_SetRef(Ch, ((Message*)JB_Ring_NextSib(Ch)));
	if (!Ch) {
		JB_Decr(Ch);
		return;
	}
	JB_FS_SyntaxAppend(Fs, Ch);
	JB_Decr(Ch);
}

bool JB_Msg_Expect(Message* Self, Syntax Type, JB_String* Name) {
	if (!Self) {
		return nil;
	}
	if ((!Type) or (Self->Func == Type)) {
		if ((Name == nil) or ((JB_Str_Equals(Self->Name, Name, true)))) {
			return true;
		}
	}
	FastString* Fs = JB_FS_Constructor(nil);
	JB_Incr(Fs);
	JB_FS_AppendString(Fs, JB_LUB[199]);
	if (Type) {
		JB_String* _tmPf0 = JB_Syx_LongName(Type);
		JB_Incr(_tmPf0);
		JB_FS_AppendString(Fs, _tmPf0);
		JB_Decr(_tmPf0);
	}
	JB_FS_MsgErrorName(Fs, Name);
	JB_FS_AppendString(Fs, JB_LUB[415]);
	JB_String* _tmPf1 = JB_Syx_LongName(Self->Func);
	JB_Incr(_tmPf1);
	JB_FS_AppendString(Fs, _tmPf1);
	JB_Decr(_tmPf1);
	JB_FS_MsgErrorName(Fs, Self->Name);
	if (true) {
		JB_String* _tmPf2 = JB_FS_SyntaxCast(Fs);
		JB_Incr(_tmPf2);
		JB_Msg_Fail(Self, _tmPf2);
		JB_Decr(_tmPf2);
	}
	JB_Decr(Fs);
	return false;
}

bool JB_Msg_ExpectLast(Message* Self, JB_String* Err) {
	if (Self) {
		Message* N = ((Message*)JB_Ring_NextSib(Self));
		if (N) {
			JB_Msg_Fail(N, Err);
		}
		 else {
			return true;
		}
	}
	return false;
}

void JB_Msg_File__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, Self->Name);
	(++Self->Indent);
	{
		Message* Ch = ((Message*)JB_Ring_First(Self));
		while (Ch) {
			Message* _Nf1 = (((Message*)JB_Ring_NextSib(Ch)));
			JB_FS_LineIndent(Fs);
			JB_FS_SyntaxAppend(Fs, Ch);
			Ch = _Nf1;
		};
		;
	}
	;
	(--Self->Indent);
}

JB_String* JB_Msg_FilePath(Message* Self) {
	JB_Object* O = JB_ObjLayer(Self)->Obj;
	//;
	if (JB_Object_Isa(O, &JB_StringData)) {
		return ((JB_String*)O);
	}
	return JB_LUB[0];
}

Message* JB_Msg_FindSyxName(Message* Self, Syntax S, JB_String* Name, bool Err) {
	{
		Message* Ch = ((Message*)JB_Ring_First(Self));
		while (Ch) {
			Message* _Nf1 = (((Message*)JB_Ring_NextSib(Ch)));
			if ((JB_Msg_EqualsSyx(Ch, S, false)) and (JB_Msg_SyntaxEquals(Ch, Name, true))) {
				return Ch;
			}
			Ch = _Nf1;
		};
		;
	}
	;
	if (Err) {
		JB_Msg_CantFind(Self, S, Name, nil);
	}
	return nil;
}

Message* JB_Msg_FindNotInserted(Message* Self) {
	{
		Message* C = Self;
		while (C) {
			if (C->Position > -1) {
				return C;
			}
			C = ((Message*)JB_Ring_Parent(C));
		};
		;
	}
	;
	return Self;
}

JB_String* JB_Msg_FirstName(Message* Self) {
	Message* F = ((Message*)JB_Ring_First(Self));
	if (F) {
		return F->Name;
	}
	return JB_LUB[0];
}

void JB_Msg_FSListArg(Message* Self, FastString* Fs, bool AddLine) {
	bool Hasp = ((Message*)JB_Ring_Parent(Self)) != nil;
	Fs->Indent = (Fs->Indent + Hasp);
	AddLine = ((bool)(AddLine | Hasp));
	if (JB_Str_Exists(Self->Name)) {
		AddLine = true;
		JB_FS_LineIndent(Fs);
		JB_FS_AppendByte(Fs, '^');
		JB_FS_AppendQuotedEscape(Fs, Self->Name);
	}
	{
		Message* Ch = ((Message*)JB_Ring_First(Self));
		while (Ch) {
			Message* _Nf1 = (((Message*)JB_Ring_NextSib(Ch)));
			if (AddLine) {
				JB_FS_LineIndent(Fs);
			}
			JB_FS_SyntaxAppend(Fs, Ch);
			AddLine = true;
			Ch = _Nf1;
		};
		;
	}
	;
	Fs->Indent = (Fs->Indent - Hasp);
	if (Hasp and (JB_FS_Last(Fs, 0) != '\n')) {
		JB_FS_AppendByte(Fs, '\n');
	}
}

void JB_Msg_FSListSep(Message* Self, FastString* Fs, JB_String* Sep) {
	{
		Message* Ch = ((Message*)JB_Ring_First(Self));
		Message* _firstf2 = Ch;
		while (Ch) {
			Message* _Nf1 = (((Message*)JB_Ring_NextSib(Ch)));
			if (_firstf2 != Ch) {
				JB_FS_AppendString(Fs, Sep);
			}
			//start;
			JB_FS_SyntaxAppend(Fs, Ch);
			Ch = _Nf1;
		};
		;
	};
}

void JB_Msg_Func__(Message* Self, FastString* Fs) {
	Message* Ch = ((Message*)JB_Ring_First(Self));
	JB_Incr(Ch);
	if (!Ch) {
		JB_Decr(Ch);
		return;
	}
	JB_FS_SyntaxAppend(Fs, Ch);
	Message* _tmPf0 = ((Message*)JB_Ring_NextSib(Ch));
	JB_Incr(_tmPf0);
	JB_Decr(Ch);
	JB_FS_SyntaxAppend(Fs, _tmPf0);
	JB_Decr(_tmPf0);
}

JB_String* JB_Msg_FuncName(Message* Self) {
	JB_String* _tmPf0 = JB_Syx_LongName(Self->Func);
	JB_Incr(_tmPf0);
	JB_String* _tmPf1 = JB_Str_LowerCase(_tmPf0);
	JB_Incr(_tmPf1);
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Message* JB_Msg_GoIntoInvisArg(Message* Self, Message* Tmp, int Pos) {
	int I = JB_int_OperatorAlign(((int)Self->Indent), 4);
	Syntax F = Tmp->Func;
	if (!((F == kJB_SyxTmp) or ((F == kJB_SyxItem) or (F == kJB_SyxDecl)))) {
		return JB_Tk__ErrorAdd(JB_LUB[466], Tmp->Position);
	}
	Message* It = JB_Tk__MakeInvisArg(Tmp, I);
	if (It) {
		It->Indent = I;
		(JB_Msg_RangeSet(It, ((IntRange)ivec2{Pos, Pos})));
		JB_Tree_SyntaxAppend(It, Self);
		return It;
	}
	return nil;
}

int JB_Msg_IndentScore(Message* Self) {
	int Ind = JB_Msg_CleanIndent(Self);
	if ((JB_Msg_EqualsSyx(Self, kJB_SyxTmp, false)) or (JB_Msg_EqualsSyx(Self, kJB_SyxItem, false))) {
		return Ind + 2;
	}
	if (JB_Msg_EqualsSyx(Self, kJB_SyxArg, false)) {
		return Ind;
	}
	return JB_Msg_CleanIndent(Self);
}

bool JB_Msg_InInvisArg(Message* Self) {
	Message* P = ((Message*)JB_Ring_Parent(Self));
	return ((JB_Msg_EqualsSyx(P, kJB_SyxArg, false))) and (JB_Msg_SyntaxIs(P, kJB__MsgParseFlags_Style2));
}

int64 JB_Msg_Int(Message* Self, int StrStart) {
	if (Self) {
		Message* F = ((Message*)JB_Ring_First(Self));
		if ((!F) or (!JB_Msg_EqualsSyx(Self, kJB_SyxUnit, false))) {
			return JB_Str_TextIntegerSection(Self->Name, StrStart, Self);
		}
		if (JB_Msg_SyntaxEquals(Self, JB_LUB[145], false)) {
			return JB_Str_HexIntegerSection(F->Name, StrStart, F);
		}
		Float64 Mul = JB_Str_TextDouble(F->Name, nil);
		if (JB_Msg_SyntaxEquals(Self, JB_LUB[420], false)) {
			Mul = (Mul * ((Float64)1024));
		}
		 else if (JB_Msg_SyntaxEquals(Self, JB_LUB[421], false)) {
			Mul = (Mul * ((Float64)1048576));
		}
		 else if (JB_Msg_SyntaxEquals(Self, JB_LUB[422], false)) {
			Mul = (Mul * ((Float64)1073741824));
		}
		 else {
			if (true) {
				JB_Msg_Fail(Self, JB_LUB[423]);
			}
			Mul = 0.0f;
		}
		return ((int64)Mul);
	}
	return 0;
}

void JB_Msg_Item__(Message* Self, FastString* Fs) {
	Message* Ch = ((Message*)JB_Ring_First(Self));
	JB_Incr(Ch);
	if (!Ch) {
		JB_Decr(Ch);
		return;
	}
	JB_FS_SyntaxAppend(Fs, Ch);
	JB_FS_AppendString(Fs, JB_LUB[73]);
	Message* _tmPf0 = ((Message*)JB_Ring_NextSib(Ch));
	JB_Incr(_tmPf0);
	JB_Decr(Ch);
	JB_FS_SyntaxAppend(Fs, _tmPf0);
	JB_Decr(_tmPf0);
}

bool JB_Msg_jbinTest(Message* Self) {
	JB_String* _tmPf0 = JB_Msg_RenderJbin(Self, JB_LUB[0], nil);
	JB_Incr(_tmPf0);
	Message* Msg = JB_Str_ParseJbin(_tmPf0, 1073741824);
	JB_Incr(Msg);
	JB_Decr(_tmPf0);
	bool _tmPf1 = JB_Msg__TreeCompare(Self, Msg, false);
	JB_Decr(Msg);
	return _tmPf1;
}

JB_String* JB_Msg_JDB2_(Message* Self, int Flags, FastString* Fs_in) {
	FastString* Fs = JB_FS__FastNew(Fs_in);
	JB_Incr(Fs);
	if (Flags & 1) {
		JB_FS_AppendString(Fs, JB_LUB[132]);
	}
	JB_String* _tmPf2 = JB_Syx_Name(Self->Func);
	JB_Incr(_tmPf2);
	JB_FS_AppendString(Fs, _tmPf2);
	JB_Decr(_tmPf2);
	JB_FS_AppendByte(Fs, ' ');
	if (((JB_String*)JB_Str_Exists(Self->Name))) {
		JB_String* _tmPf3 = ((JB_String*)JB_Ternary(Flags & 2, JB_Str_Range(Self->Name, 0, 32), Self->Name));
		JB_Incr(_tmPf3);
		JB_FS_AppendQuotedEscape(Fs, _tmPf3);
		JB_Decr(_tmPf3);
	}
	if (JB_Ring_HasChildren(Self)) {
		(++Fs->Indent);
		{
			Message* Ch = ((Message*)JB_Ring_First(Self));
			JB_Incr(Ch);
			while (Ch) {
				Message* _Nf1 = (((Message*)JB_Ring_NextSib(Ch)));
				JB_Incr(_Nf1);
				JB_FS_LineIndent(Fs);
				JB_FreeIfDead(JB_Msg_JDB2_(Ch, Flags, Fs));
				JB_SetRef(Ch, _Nf1);
				JB_Decr(_Nf1);
			};
			JB_Decr(Ch);
			;
		}
		;
		(--Fs->Indent);
		if (Flags & 1) {
			JB_FS_LineIndent(Fs);
		}
	}
	if (Flags & 1) {
		JB_FS_AppendString(Fs, JB_LUB[133]);
	}
	JB_String* _tmPf4 = JB_FS_SmartResult(Fs, Fs_in);
	JB_Incr(_tmPf4);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf4);
	return _tmPf4;
}

JB_String* JB_Msg_JDB_(Message* Self, FastString* Fs_in, int Flags) {
	return JB_Msg_JDB2_(Self, Flags, Fs_in);
}

int JB_Msg_Length(Message* Self) {
	return JB_Str_Length(Self->Name);
}

void JB_Msg_List__(Message* Self, FastString* Fs) {
	JB_FS_AppendByte(Fs, '(');
	int Count = 0;
	JB_String* Sep = JB_LUB[6];
	if (JB_Msg_SyntaxIs(Self, kJB__MsgParseFlags_Style2)) {
		Sep = JB_LUB[42];
		JB_FS_AppendString(Fs, Sep);
	}
	{
		Message* Ch = ((Message*)JB_Ring_First(Self));
		while (Ch) {
			Message* _Nf1 = (((Message*)JB_Ring_NextSib(Ch)));
			if ((++Count) > 1) {
				JB_FS_AppendString(Fs, Sep);
			}
			JB_FS_SyntaxAppend(Fs, Ch);
			if (JB_Msg_EqualsSyx(Ch, kJB_SyxItem, false)) {
				(++Count);
			}
			Ch = _Nf1;
		};
		;
	}
	;
	if ((Count == 1) or JB_Msg_SyntaxIs(Self, kJB__MsgParseFlags_Style2)) {
		JB_FS_AppendString(Fs, Sep);
	}
	JB_FS_AppendByte(Fs, ')');
}

bool JB_Msg_ListViewable(Message* Self) {
	return Self and JB_Syx_ListViewable(Self->Func);
}

JB_String* JB_Msg_Locate(Message* Self) {
	if ((!Self)) {
		return JB_LUB[226];
	}
	JB_String* S = JB_Msg_Render(Self, nil);
	JB_Incr(S);
	JB_String* Fname = JB_Syx_Name(Self->Func);
	JB_Incr(Fname);
	FastString* Fs = JB_FS_Constructor(nil);
	JB_Incr(Fs);
	JB_FreeIfDead(JB_ObjRender(Self->Name, Fs));
	JB_FS_AppendByte(Fs, '@');
	JB_FS_AppendString(Fs, Fname);
	JB_Decr(Fname);
	JB_FS_AppendString(Fs, JB_LUB[227]);
	JB_FS_AppendString(Fs, S);
	JB_Decr(S);
	JB_FS_AppendByte(Fs, '\'');
	if (Self->Position >= 0) {
		JB_FS_AppendString(Fs, JB_LUB[228]);
		JB_FS_AppendInt32(Fs, Self->Position);
		JB_MemoryLayer* _tmPf0 = JB_ObjLayer(Self);
		JB_Incr(_tmPf0);
		JB_Object* R = _tmPf0->Obj;
		JB_Incr(R);
		JB_Decr(_tmPf0);
		if (JB_Object_Isa(R, &JB_StringData)) {
			if (JB_Str_Length(((JB_String*)R))) {
				JB_FS_AppendString(Fs, JB_LUB[219]);
				JB_FS_AppendString(Fs, ((JB_String*)R));
			}
		}
		JB_Decr(R);
	}
	JB_FS_AppendByte(Fs, '\n');
	JB_String* _tmPf1 = JB_FS_SyntaxCast(Fs);
	JB_Incr(_tmPf1);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

void JB_Msg_max__(Message* Self, FastString* Fs) {
	0;
}

JB_String* JB_Msg_MiniName(Message* Self, JB_String* Prefix) {
	if (!Self) {
		return JB_LUB[0];
	}
	FastString* _fsf0 = JB_FS_Constructor(nil);
	JB_Incr(_fsf0);
	JB_FS_AppendString(_fsf0, Prefix);
	JB_String* _tmPf1 = JB_Msg_FuncName(Self);
	JB_Incr(_tmPf1);
	JB_FS_AppendString(_fsf0, _tmPf1);
	JB_Decr(_tmPf1);
	JB_FS_AppendString(_fsf0, JB_LUB[134]);
	JB_String* _tmPf3 = JB_Str_Range(Self->Name, 0, 64);
	JB_Incr(_tmPf3);
	JB_String* _tmPf2 = JB_Str_UnicodeSync(_tmPf3);
	JB_Incr(_tmPf2);
	JB_Decr(_tmPf3);
	JB_FS_AppendString(_fsf0, _tmPf2);
	JB_Decr(_tmPf2);
	JB_FS_AppendString(_fsf0, JB_LUB[135]);
	JB_String* _tmPf4 = JB_FS_GetResult(_fsf0);
	JB_Incr(_tmPf4);
	JB_Decr(_fsf0);
	JB_SafeDecr(_tmPf4);
	return _tmPf4;
}

Message* JB_Msg_Msg(Message* Self, Syntax Fn, JB_String* Name) {
	return JB_Msg_ConstructorRange(nil, Self, Fn, JB__Tk_Using.Position, Name, JB_Str_Length(Name));
}

void JB_Msg_Msg__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, JB_LUB[132]);
	JB_Msg_FSListSep(Self, Fs, JB_LUB[6]);
	JB_FS_AppendString(Fs, JB_LUB[229]);
}

void JB_Msg_Name__(Message* Self, FastString* Fs) {
	Message* Ch = ((Message*)JB_Ring_First(Self));
	JB_Incr(Ch);
	if (Ch) {
		JB_FS_AppendString(Fs, Self->Name);
		JB_FS_AppendString(Fs, JB_LUB[136]);
		JB_FS_SyntaxAppend(Fs, Ch);
	}
	 else {
		JB_FS_AppendByte(Fs, '@');
		JB_FS_AppendString(Fs, Self->Name);
	}
	JB_Decr(Ch);
}

void JB_Msg_Nil__(Message* Self, FastString* Fs) {
	JB_DoAt(1);
}

void JB_Msg_Num__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, Self->Name);
}

void JB_Msg_Oat__(Message* Self, FastString* Fs) {
	JB_FS_AppendByte(Fs, '%');
	JB_Msg_RenderWithSpaces(Self, Fs, nil);
}

bool JB_Msg_OperatorIn(Message* Self, Syntax F) {
	Message* P = ((Message*)JB_Ring_Parent(Self));
	if (P) {
		return P->Func == F;
	}
	return false;
}

void JB_Msg_Opp__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, Self->Name);
}

JB_String* JB_Msg_OriginalParseData(Message* Self) {
	JB_Object* D = JB_ObjLayer(Self)->Obj2;
	if (JB_Object_Isa(D, &JB_StringData)) {
		return ((JB_String*)D);
	}
	return JB_LUB[0];
}

Message* JB_Msg_ParseAST(Message* Self) {
	Message* Rz = nil;
	JB_Incr(Rz);
	if (JB_Msg_EqualsSyx(Self, kJB_SyxArg, false)) {
		Message* F = ((Message*)JB_Ring_First(Self));
		JB_Incr(F);
		if (!F) {
			JB_Decr(F);
			JB_Decr(Rz);
			return nil;
		}
		JB_Msg_ExpectLast(F, JB_LUB[0]);
		Message* _tmPf4 = JB_Msg_ParseAST(F);
		JB_Incr(_tmPf4);
		JB_Decr(F);
		JB_Decr(Rz);
		JB_SafeDecr(_tmPf4);
		return _tmPf4;
	}
	Syntax Fn = JB_Syx__Func(Self->Name, Self);
	if (!Fn) {
		JB_Decr(Rz);
		return nil;
	}
	Message* Name = ((Message*)JB_Ring_First(Self));
	JB_Incr(Name);
	if (Name) {
		bool isStr = (JB_Msg_EqualsSyx(Name, kJB_SyxStr, false));
		JB_String* _tmPf2 = ((JB_String*)JB_Ternary(isStr, ((JB_String*)Name->Name), ((JB_String*)JB_LUB[0])));
		JB_Incr(_tmPf2);
		JB_SetRef(Rz, JB_Msg_ConstructorNormal(nil, Fn, _tmPf2));
		JB_Decr(_tmPf2);
		Message* Arg = ((Message*)JB_Ternary(isStr, ((Message*)JB_Ring_NextSib(Name)), Name));
		JB_Incr(Arg);
		if (JB_Msg_EqualsSyx(Arg, kJB_SyxArg, false)) {
			{
				Message* Ch = ((Message*)JB_Ring_First(Arg));
				JB_Incr(Ch);
				while (Ch) {
					Message* _Nf1 = ((Message*)JB_Ring_NextSib(Ch));
					JB_Incr(_Nf1);
					Message* _tmPf3 = JB_Msg_ParseAST(Ch);
					JB_Incr(_tmPf3);
					JB_Tree_SyntaxAppend(Rz, _tmPf3);
					JB_Decr(_tmPf3);
					JB_SetRef(Ch, _Nf1);
					JB_Decr(_Nf1);
				};
				JB_Decr(Ch);
				;
			};
		}
		JB_Decr(Arg);
	}
	JB_Decr(Name);
	JB_SafeDecr(Rz);
	return Rz;
}

void JB_Msg_pinn__(Message* Self, FastString* Fs) {
	Message* F = ((Message*)JB_Ring_First(Self));
	Message* Opp = ((Message*)JB_Ring_NextSib(F));
	Message* L = ((Message*)JB_Ring_NextSib(Opp));
	JB_FS_SyntaxAppend(Fs, F);
	JB_FS_AppendByte(Fs, ' ');
	JB_FS_SyntaxAppend(Fs, ((Message*)JB_Ring_Last(Opp)));
	JB_FS_AppendByte(Fs, ' ');
	JB_FS_SyntaxAppend(Fs, L);
	JB_FS_AppendString(Fs, JB_LUB[144]);
	JB_FS_SyntaxAppend(Fs, ((Message*)JB_Ring_First(Opp)));
}

JB_String* JB_Msg_plocate(Message* Self) {
	if (Self) {
		Message* _tmPf0 = ((Message*)JB_Ring_Parent(Self));
		JB_Incr(_tmPf0);
		JB_String* _tmPf1 = JB_Msg_Locate(_tmPf0);
		JB_Incr(_tmPf1);
		JB_Decr(_tmPf0);
		JB_SafeDecr(_tmPf1);
		return _tmPf1;
	}
	return JB_LUB[0];
}

int JB_Msg_PrevIndentCheck(Message* Self, Message* Pr) {
	int Prin = JB_Msg_CleanIndent(Pr);
	int Chin = JB_Msg_CleanIndent(Self);
	if (!((Prin != Chin) and ((Prin != 254) and (Chin != 254)))) {
		return 0;
	}
	int IndExtra = Chin - Prin;
	if (JB_int_OperatorIsa(IndExtra, 2)) {
		if (IndExtra == 4) {
			return IndExtra;
		}
		if (IndExtra < 0) {
			if ((JB_int_OperatorIsa(IndExtra, 4)) or ((JB_int_OperatorIsa(Chin, 4)) or (JB_Msg_InInvisArg(Self)))) {
				return IndExtra;
			}
		}
		if ((IndExtra > 0) and ((JB_Msg_EqualsSyx(Pr, kJB_SyxTmp, false)))) {
			return IndExtra;
		}
	}
	FastString* _fsf0 = JB_FS_Constructor(nil);
	JB_FS_AppendString(_fsf0, JB_LUB[362]);
	JB_FS_AppendInt32(_fsf0, Prin);
	JB_FS_AppendString(_fsf0, JB_LUB[363]);
	JB_FS_AppendInt32(_fsf0, Chin);
	JB_FS_AppendString(_fsf0, JB_LUB[364]);
	JB_FreeIfDead(JB_Tk__ErrorAlwaysAdd(JB_FS_GetResult(_fsf0), Self->Position));
	return 0;
}

void JB_Msg_Prm__(Message* Self, FastString* Fs) {
	JB_FS_AppendByte(Fs, '(');
	{
		Message* Ch = ((Message*)JB_Ring_First(Self));
		Message* _firstf2 = Ch;
		while (Ch) {
			Message* _Nf1 = (((Message*)JB_Ring_NextSib(Ch)));
			if (_firstf2 != Ch) {
				JB_FS_AppendString(Fs, JB_LUB[6]);
			}
			//start;
			JB_FS_SyntaxAppend(Fs, Ch);
			Ch = _Nf1;
		};
		;
	}
	;
	JB_FS_AppendByte(Fs, ')');
}

void JB_Msg_Ques__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, JB_LUB[137]);
	JB_FS_AppendString(Fs, Self->Name);
	Message* N = ((Message*)JB_Ring_First(Self));
	JB_Incr(N);
	if (N) {
		JB_FS_AppendByte(Fs, ' ');
		JB_FS_SyntaxAppend(Fs, N);
	}
	JB_Decr(N);
}

void JB_Msg_Quot__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, JB_LUB[138]);
	{
		Message* Ch = ((Message*)JB_Ring_First(Self));
		while (Ch) {
			Message* _Nf1 = (((Message*)JB_Ring_NextSib(Ch)));
			JB_FS_SyntaxAppend(Fs, Ch);
			if (((Message*)JB_Ring_NextSib(Ch))) {
				JB_FS_AppendString(Fs, JB_LUB[6]);
			}
			Ch = _Nf1;
		};
		;
	}
	;
	JB_FS_AppendString(Fs, JB_LUB[139]);
}

void JB_Msg_RangeSet(Message* Self, IntRange R) {
	Self->Position = R[0];
	Self->RangeLength = JB_Rg_Width(R);
}

void JB_Msg_Rel__(Message* Self, FastString* Fs) {
	JB_Msg_RenderWithSpaces(Self, Fs, nil);
}

JB_String* JB_Msg_Render(Message* Self, FastString* Fs_in) {
	FastString* Fs = JB_FS__FastNew(Fs_in);
	JB_FS_SyntaxAppend(Fs, Self);
	return JB_FS_SmartResult(Fs, Fs_in);
}

void JB_Msg_render_jbin_sub(Message* Self, FastString* Js) {
	Message* Ch = Self;
	Message* After = ((Message*)JB_Ring_FlatAfter(Self));
	while (Ch and (Ch != After)) {
		int Depth = 0;
		Message* Curr = Ch;
		Ch = ((Message*)JB_Ring_FlatNextDepth(Curr, (&Depth), true));
		JB_bin_Add(Js, Curr->Func, Curr->Name, Depth > 0);
		JB_bin_Exit(Js, (-Depth));
	};
}

JB_String* JB_Msg_RenderAST(Message* Self, int Flags, FastString* Fs_in) {
	FastString* Fs = JB_FS__FastNew(Fs_in);
	JB_Incr(Fs);
	if (((JB_Msg_EqualsSyx(Self, kJB_SyxArg, false))) and (JB_Ring_IsRoot(Self))) {
		{
			Message* Ch = ((Message*)JB_Ring_First(Self));
			JB_Incr(Ch);
			while (Ch) {
				Message* _Nf1 = (((Message*)JB_Ring_NextSib(Ch)));
				JB_Incr(_Nf1);
				JB_FreeIfDead(JB_Msg_JDB2_(Ch, Flags, Fs));
				JB_FS_AppendByte(Fs, '\n');
				JB_SetRef(Ch, _Nf1);
				JB_Decr(_Nf1);
			};
			JB_Decr(Ch);
			;
		};
	}
	 else {
		JB_FreeIfDead(JB_Msg_JDB2_(Self, Flags, Fs));
	}
	JB_String* _tmPf2 = JB_FS_SmartResult(Fs, Fs_in);
	JB_Incr(_tmPf2);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf2);
	return _tmPf2;
}

JB_String* JB_Msg_RenderJbin(Message* Self, JB_String* Shell_path, FastString* Fs_in) {
	FastString* Fs = JB_FS__FastNew(Fs_in);
	if (!Self) {
		return JB_LUB[0];
	}
	FastString* Js = ((FastString*)Fs);
	if (JB_Str_Exists(Shell_path)) {
		JB_bin_Sheb(Js, Shell_path);
	}
	JB_FS_AppendString(Js, JB__JbinHeader);
	JB_Msg_render_jbin_sub(Self, Js);
	return JB_FS_SmartResult(Fs, Fs_in);
}

void JB_Msg_RenderPrm(Message* Self, FastString* Fs, uint /*byte*/ B1, uint /*byte*/ B2) {
	JB_FS_AppendByte(Fs, B1);
	JB_Msg_FSListSep(Self, Fs, JB_LUB[6]);
	JB_FS_AppendByte(Fs, B2);
}

void JB_Msg_RenderWithSpaces(Message* Self, FastString* Fs, Message* Ch) {
	if (!Ch) {
		Ch = ((Message*)JB_Ring_First(Self));
	}
	while (Ch) {
		JB_FS_SyntaxAppend(Fs, Ch);
		Ch = ((Message*)JB_Ring_NextSib(Ch));
		if (!Ch) {
			return;
		}
		JB_FS_AppendByte(Fs, ' ');
	};
}

void JB_Msg_SCnj__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, Self->Name);
}

void JB_Msg_SCom__(Message* Self, FastString* Fs) {
	Message* Ch = ((Message*)JB_Ring_First(Self));
	JB_Incr(Ch);
	if (!Ch) {
		JB_FS_AppendString(Fs, JB_LUB[230]);
		JB_Decr(Ch);
		return;
	}
	Message* _tmPf0 = ((Message*)JB_Ring_NextSib(Ch));
	JB_Incr(_tmPf0);
	JB_FS_SyntaxAppend(Fs, _tmPf0);
	JB_Decr(_tmPf0);
	JB_FS_AppendString(Fs, JB_LUB[230]);
	if (JB_Tree_HasOneChild(Ch)) {
		Message* _tmPf1 = ((Message*)JB_Ring_First(Ch));
		JB_Incr(_tmPf1);
		JB_FS_SyntaxAppend(Fs, _tmPf1);
		JB_Decr(_tmPf1);
	}
	 else {
		JB_Msg_FSListArg(Ch, Fs, false);
		JB_FS_AppendByte(Fs, '\n');
	}
	JB_Decr(Ch);
	JB_FS_AppendString(Fs, JB_LUB[231]);
}

void JB_Msg_SDot__(Message* Self, FastString* Fs) {
	JB_FS_AppendByte(Fs, '.');
	JB_FS_AppendString(Fs, Self->Name);
	Message* _tmPf0 = ((Message*)JB_Ring_First(Self));
	JB_Incr(_tmPf0);
	JB_FS_SyntaxAppend(Fs, _tmPf0);
	JB_Decr(_tmPf0);
}

void JB_Msg_Sheb__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, JB_LUB[12]);
	JB_FS_AppendString(Fs, Self->Name);
	JB_FS_AppendByte(Fs, '\n');
}

void JB_Msg_SStr__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, JB_LUB[10]);
	JB_FS_AppendString(Fs, Self->Name);
	JB_FS_AppendString(Fs, JB_LUB[11]);
}

void JB_Msg_SThg__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, Self->Name);
}

void JB_Msg_Str__(Message* Self, FastString* Fs) {
	JB_FS_AppendByte(Fs, '"');
	JB_FS_AppendEscape(Fs, Self->Name);
	{
		Message* Ch = ((Message*)JB_Ring_First(Self));
		JB_Incr(Ch);
		while (Ch) {
			Message* _Nf1 = (((Message*)JB_Ring_NextSib(Ch)));
			JB_Incr(_Nf1);
			if ((JB_Msg_EqualsSyx(Ch, kJB_SyxEmb, false))) {
				JB_FS_AppendEscape(Fs, Ch->Name);
			}
			 else {
				JB_FS_AppendByte(Fs, '$');
				JB_FS_AppendByte(Fs, '{');
				JB_FS_SyntaxAppend(Fs, Ch);
				JB_FS_AppendByte(Fs, '}');
			}
			JB_SetRef(Ch, _Nf1);
			JB_Decr(_Nf1);
		};
		JB_Decr(Ch);
		;
	}
	;
	JB_FS_AppendByte(Fs, '"');
}

bool JB_Msg_SyntaxEquals(Message* Self, JB_String* Name, bool Aware) {
	return Self and JB_Str_Equals(Self->Name, Name, Aware);
}

bool JB_Msg_EqualsSyx(Message* Self, Syntax X, bool Aware) {
	return Self and (Self->Func == X);
}

void JB_Msg_Fail(Message* Self, JB_String* Error) {
	JB_Rec__Latchkum(Self, Error, nil);
}

bool JB_Msg_SyntaxIs(Message* Self, uint /*MsgParseFlags*/ F) {
	if (Self) {
		return ((bool)(Self->Flags & F));
	}
	return false;
}

void JB_Msg_SyntaxIsSet(Message* Self, uint /*MsgParseFlags*/ F, bool Value) {
	if (Self) {
		if (Value) {
			Self->Flags = (Self->Flags | F);
		}
		 else {
			Self->Flags = (Self->Flags & (~F));
		}
	}
}

void JB_Msg_SyntaxUsing(Message* Self, MessagePosition* Rz) {
	Rz[0] = JB__Tk_Using;
	Rz->Layer = JB_Class_Layer((&MessageData));
	JB__Tk_Using.Position = Self->Position;
	JB__Tk_Using.Length = Self->RangeLength;
	JB__Tk_Using.Tag = Self->Tag;
	JB__Tk_Using.Flags = kJB__MsgParseFlags_Inserted;
	JB_Mem_Use(JB_ObjLayer(Self));
}

void JB_Msg_Test(Message* Self, JB_String* New_render, JB_String* Name) {
	if (!JB_Msg_TestSub(Self, New_render, Name)) {
		FastString* _fsf0 = JB_FS_Constructor(nil);
		JB_Incr(_fsf0);
		JB_FS_AppendString(_fsf0, JB_LUB[541]);
		JB_FS_AppendString(_fsf0, Name);
		JB_FS_AppendString(_fsf0, JB_LUB[542]);
		JB_FS_AppendString(_fsf0, New_render);
		JB_String* _tmPf1 = JB_FS_GetResult(_fsf0);
		JB_Incr(_tmPf1);
		JB_Decr(_fsf0);
		JB_Print(_tmPf1);
		JB_Decr(_tmPf1);
		JB_Rec_Clear(JB_StdErr);
	}
}

void JB_Msg_test_style(Message* Self) {
	bool B = false;
	{
		Message* S = Self;
		Message* _afterf1 = ((Message*)JB_Ring_FlatAfter(Self));
		while ((S) and (S != _afterf1)) {
			Message* _N_f2 = (((Message*)JB_Ring_FlatNext0(S)));
			if ((JB_Msg_EqualsSyx(S, kJB_SyxArg, false)) or (JB_Msg_EqualsSyx(S, kJB_SyxList, false))) {
				B = (!B);
				((JB_Msg_SyntaxIsSet(S, kJB__MsgParseFlags_Style2, B)));
			}
			S = _N_f2;
		};
		;
	};
}

bool JB_Msg_TestSub(Message* Self, JB_String* New_render, JB_String* Name) {
	LeakTester* LKT = JB_Lk_Constructor(nil, Name);
	JB_Incr(LKT);
	{
		Message* Reparse = JB_Str_Parse(New_render, kJB_SyxArg, true);
		JB_Incr(Reparse);
		if (!Reparse) {
			JB_Decr(Reparse);
			JB_Decr(LKT);
			return nil;
		}
		JB_Msg_test_style(Reparse);
		JB_Msg_test_style(Self);
		if (!JB_Msg__TreeCompare(Self, Reparse, false)) {
			JB_Decr(Reparse);
			JB_Decr(LKT);
			return nil;
		}
		JB_String* Self_render = JB_Msg_Render(Self, nil);
		JB_Incr(Self_render);
		if (!JB_Str_Exists(Self_render)) {
			JB_Decr(Self_render);
			JB_Decr(Reparse);
			JB_Decr(LKT);
			return nil;
		}
		JB_String* Reparse_render = JB_Msg_Render(Reparse, nil);
		JB_Incr(Reparse_render);
		if (!JB_Str_Exists(Reparse_render)) {
			JB_Decr(Reparse_render);
			JB_Decr(Self_render);
			JB_Decr(Reparse);
			JB_Decr(LKT);
			return nil;
		}
		if (!(JB_Rec_OK(JB_StdErr) and ((JB_Str_Equals(Self_render, Reparse_render, false))))) {
			JB_Decr(Reparse_render);
			JB_Decr(Self_render);
			JB_Decr(Reparse);
			JB_Decr(LKT);
			return nil;
		}
		JB_Decr(Self_render);
		JB_Decr(Reparse_render);
		JB_Decr(Reparse);
	}
	;
	(JB_Lk_FinalTest(LKT));
	JB_Decr(LKT);
	return true;
}

JB_String* JB_Msg_Text(Message* Self, int I) {
	if (I == 0) {
		return JB_Msg_TextViewChild(Self)->Name;
	}
	return JB_LUB[0];
}

bool JB_Msg_TextSet(Message* Self, int I, JB_String* V) {
	if (I == 0) {
		JB_SetRef(JB_Msg_TextViewChild(Self)->Name, V);
		return true;
	}
	return false;
}

Message* JB_Msg_TextViewChild(Message* Self) {
	if (!JB_Msg_EqualsSyx(Self, kJB_SyxTmp, false)) {
		return Self;
	}
	Message* Ch = ((Message*)JB_Ring_First(Self));
	if (Ch) {
		Message* Ch2 = ((Message*)JB_Ring_NextSib(Ch));
		if (JB_Msg_ListViewable(Ch2)) {
			return Ch2;
		}
		if (JB_Msg_ListViewable(Ch)) {
			return Ch;
		}
	}
	return Self;
}

void JB_Msg_Thg__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, Self->Name);
}

void JB_Msg_Tmp__(Message* Self, FastString* Fs) {
	if (JB_Str_IsStatementName(Self->Name)) {
		JB_FS_AppendString(Fs, Self->Name);
	}
	 else {
		JB_FS_AppendByte(Fs, '+');
		JB_FS_AppendQuotedEscape(Fs, Self->Name);
	}
	if (!JB_Ring_HasChildren(Self)) {
		return;
	}
	Message* Ch = ((Message*)JB_Ring_First(Self));
	bool HasArg = false;
	while (Ch) {
		if (HasArg) {
			JB_FS_LineIndent(Fs);
		}
		JB_FS_AppendByte(Fs, ' ');
		JB_FS_SyntaxAppend(Fs, Ch);
		if (JB_Msg_EqualsSyx(Ch, kJB_SyxArg, false)) {
			HasArg = true;
		}
		Ch = ((Message*)JB_Ring_NextSib(Ch));
	};
}

void JB_Msg_Todo__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, Self->Name);
	JB_Msg_FSListSep(Self, Fs, JB_LUB[23]);
}

void JB_Msg_TRel__(Message* Self, FastString* Fs) {
	JB_Msg_RenderWithSpaces(Self, Fs, nil);
}

void JB_Msg_Tril__(Message* Self, FastString* Fs) {
	Message* F = ((Message*)JB_Ring_First(Self));
	if (!F) {
		return;
	}
	JB_FS_AppendByte(Fs, '#');
	JB_FS_SyntaxAppend(Fs, F);
	Message* S = ((Message*)JB_Ring_NextSib(F));
	if (!S) {
		return;
	}
	JB_FS_AppendByte(Fs, ' ');
	JB_FS_SyntaxAppend(Fs, S);
	Message* L = ((Message*)JB_Ring_NextSib(S));
	if (!L) {
		return;
	}
	JB_FS_AppendByte(Fs, ' ');
	JB_FS_SyntaxAppend(Fs, L);
}

void JB_Msg_Type__(Message* Self, FastString* Fs) {
	Message* Obj = ((Message*)JB_Ring_First(Self));
	JB_Incr(Obj);
	if (!Obj) {
		JB_Decr(Obj);
		return;
	}
	Message* Type = ((Message*)JB_Ring_NextSib(Obj));
	JB_Incr(Type);
	JB_FS_SyntaxAppend(Fs, Obj);
	JB_Decr(Obj);
	JB_FS_AppendByte(Fs, '|');
	if (Type) {
		JB_FS_SyntaxAppend(Fs, Type);
	}
	JB_Decr(Type);
	JB_FS_AppendByte(Fs, '|');
}

void JB_Msg_UnEmbedStr(Message* Self) {
	Message* S1 = ((Message*)JB_Ring_First(Self));
	JB_Incr(S1);
	if (((JB_Msg_EqualsSyx(S1, kJB_SyxEmb, false))) and (!JB_FreeIfDead(((Message*)JB_Ring_NextSib(S1))))) {
		JB_Tree_Remove(S1);
		JB_SetRef(Self->Name, S1->Name);
	}
	JB_Decr(S1);
}

void JB_Msg_Unit__(Message* Self, FastString* Fs) {
	JB_String* Num = JB_Msg_FirstName(Self);
	JB_Incr(Num);
	JB_FS_AppendString(Fs, Num);
	if ((JB_Str_IsHexLike(Num, 0)) and (JB_Str_Last(Num, 0) != '_')) {
		JB_FS_AppendByte(Fs, '_');
	}
	JB_Decr(Num);
	JB_FS_AppendString(Fs, Self->Name);
}

void JB_Msg_url__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, Self->Name);
	JB_FS_AppendString(Fs, JB_LUB[17]);
	Message* F = ((Message*)JB_Ring_First(Self));
	JB_Incr(F);
	if (F) {
		JB_FS_AppendString(Fs, F->Name);
	}
	JB_Decr(F);
}

void JB_Msg_XAtt__(Message* Self, FastString* Fs) {
	//;
	JB_FS_AppendByte(Fs, ' ');
	JB_FS_AppendString(Fs, Self->Name);
	JB_FS_AppendString(Fs, JB_LUB[140]);
	JB_FS_SyntaxAppend(Fs, ((Message*)JB_Ring_First(Self)));
	JB_FS_AppendByte(Fs, '"');
	//;
}

void JB_Msg_XCDT__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, JB_LUB[13]);
	JB_FS_AppendString(Fs, Self->Name);
	JB_FS_AppendString(Fs, JB_LUB[14]);
}

void JB_Msg_XCom__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, JB_LUB[15]);
	JB_FS_AppendString(Fs, Self->Name);
	JB_FS_AppendString(Fs, JB_LUB[16]);
}

void JB_Msg_XML__(Message* Self, FastString* Fs) {
	JB_FS_AppendByte(Fs, '<');
	JB_FS_AppendString(Fs, Self->Name);
	Message* Atts = ((Message*)JB_Ring_First(Self));
	{
		Message* A = ((Message*)JB_Ring_First(Atts));
		while (A) {
			Message* _Nf2 = ((Message*)JB_Ring_NextSib(A));
			JB_FS_SyntaxAppend(Fs, A);
			A = _Nf2;
		};
		;
	}
	;
	Message* Children = ((Message*)JB_Ternary(Atts, ((Message*)JB_Ring_NextSib(Atts)), nil));
	if (!Children) {
		JB_FS_AppendString(Fs, JB_LUB[141]);
		return;
	}
	JB_FS_AppendByte(Fs, '>');
	bool SingleText = ((JB_Msg_EqualsSyx(Children, kJB_SyxXTxt, false))) and ((!((Message*)JB_Ring_NextSib(Children))));
	if (SingleText) {
		JB_FS_SyntaxAppend(Fs, Children);
	}
	 else {
		(++Fs->Indent);
		{
			Message* Ch = Children;
			while (Ch) {
				JB_FS_LineIndent(Fs);
				JB_FS_SyntaxAppend(Fs, Ch);
				Ch = ((Message*)JB_Ring_NextSib(Ch));
			};
			;
		}
		;
		(--Fs->Indent);
		JB_FS_LineIndent(Fs);
	}
	//;
	JB_FS_AppendString(Fs, JB_LUB[142]);
	JB_FS_AppendString(Fs, Self->Name);
	JB_FS_AppendByte(Fs, '>');
	//;
}

void JB_Msg_XPI__(Message* Self, FastString* Fs) {
	JB_FS_AppendString(Fs, JB_LUB[232]);
	if (JB_Ring_HasChildCount(Self, 1)) {
		Message* _tmPf0 = ((Message*)JB_Ring_First(Self));
		JB_Incr(_tmPf0);
		JB_FS_SyntaxAppend(Fs, _tmPf0);
		JB_Decr(_tmPf0);
	}
	 else {
		JB_Msg_FSListArg(Self, Fs, false);
		JB_FS_AppendByte(Fs, '\n');
	}
	JB_FS_AppendString(Fs, JB_LUB[233]);
}

void JB_Msg_XTxt__(Message* Self, FastString* Fs) {
	JB_FS_AppendMultiReplace(Fs, Self->Name, JB__Constants_XML_EscapeStr, JB_StdErr);
}

void JB_Msg_Yoda__(Message* Self, FastString* Fs) {
	Message* F = ((Message*)JB_Ring_First(Self));
	Message* S = ((Message*)JB_Ring_NextSib(F));
	Message* L = ((Message*)JB_Ring_NextSib(S));
	JB_FS_AppendString(Fs, JB_LUB[143]);
	JB_FS_SyntaxAppend(Fs, L);
	JB_FS_AppendByte(Fs, ' ');
	JB_FS_SyntaxAppend(Fs, F);
	JB_FS_AppendByte(Fs, ' ');
	JB_FS_SyntaxAppend(Fs, S);
}

bool JB_Msg__TreeCompare(Message* Orig, Message* Reparse, bool PrintIfSame) {
	if (!(Orig and Reparse)) {
		return JB_CompareError(Orig, Reparse);
	}
	if ((Orig->Func != Reparse->Func) or ((!JB_Str_Equals(Orig->Name, Reparse->Name, false)))) {
		return JB_CompareError(Orig, Reparse);
	}
	Message* R1 = ((Message*)JB_Ring_First(Reparse));
	Message* S1 = ((Message*)JB_Ring_First(Orig));
	while (R1 or S1) {
		if (!JB_Msg__TreeCompare(S1, R1, false)) {
			return nil;
		}
		R1 = ((Message*)JB_Ring_NextSib(R1));
		S1 = ((Message*)JB_Ring_NextSib(S1));
	};
	if (PrintIfSame) {
		JB_Msg__TreeComparePrint(Orig);
	}
	return true;
}

void JB_Msg__TreeComparePrint(Message* Orig) {
	FastString* _fsf0 = JB_FS_Constructor(nil);
	JB_Incr(_fsf0);
	JB_FS_AppendString(_fsf0, JB_LUB[234]);
	JB_String* _tmPf1 = JB_Msg_MiniName(Orig, JB_LUB[0]);
	JB_Incr(_tmPf1);
	JB_FS_AppendString(_fsf0, _tmPf1);
	JB_Decr(_tmPf1);
	JB_FS_AppendString(_fsf0, JB_LUB[235]);
	JB_String* _tmPf2 = JB_FS_GetResult(_fsf0);
	JB_Incr(_tmPf2);
	JB_Decr(_fsf0);
	JB_PrintLine(_tmPf2);
	JB_Decr(_tmPf2);
}




void JB_sci_Destructor(SaverClassInfo* Self) {
	JB_Clear(Self->NextInfo);
	JB_Array_Destructor(Self);
}



int JB_Proc__Init_() {
	{
	}
	;
	return 0;
}


JB_Task* JB_Task_Constructor(JB_Task* Self, uint Obj, void* Func) {
	if (Self == nil) {
		Self = ((JB_Task*)JB_NewClass(&JB_TaskData));
	}
	JB_Ring_Constructor0(Self);
	Self->_State = 0;
	Self->_Object = Obj;
	Self->_func = Func;
	return Self;
}

void JB_Task_Destructor(JB_Task* Self) {
	//visible;
	JB_Object** Curr = ((JB_Object**)Self);
	int O = Self->_Object;
	while (O) {
		int I = JB_int_LowestBit(O);
		O = (O & (~I));
		I = JB_Int_Log2(((int)I));
		JB_Decr(Curr[I]);
	};
	JB_Ring_Destructor(Self);
}


JB_Error* JB_Err_Constructor(JB_Error* Self, Message* Node, JB_String* Desc, uint /*ErrorSeverity*/ Level, JB_String* Path) {
	if (Self == nil) {
		Self = ((JB_Error*)JB_NewClass(&JB_ErrorData));
	}
	//visible;
	JB_Msg_ConstructorEmpty(Self);
	JB_Incr2(Self->OriginalData, JB_LUB[0]);
	JB_Incr2(Self->StackTrace, JB_LUB[0]);
	Self->ErrorFlags = 0;
	Self->Position = -1;
	JB_Incr2(Self->Node, Node);
	Self->Severity = Level;
	Self->Progress = JB__Rec_Progress;
	JB_Incr2(Self->Name, Desc);
	JB_Incr2(Self->Path, Path);
	Self->When = JB_Date__Now();
	Self->Func = kJB_SyxSStr;
	JB_Err_UpgradeWithNode(Self);
	return Self;
}

JB_Error* JB_Err_ConstructorNothing(JB_Error* Self) {
	if (Self == nil) {
		Self = ((JB_Error*)JB_NewClass(&JB_ErrorData));
	}
	JB_Msg_ConstructorEmpty(Self);
	JB_Incr2(Self->OriginalData, JB_LUB[0]);
	JB_Incr2(Self->Path, JB_LUB[0]);
	Self->Node = nil;
	Self->Progress = 0.0f;
	JB_Incr2(Self->StackTrace, JB_LUB[0]);
	Self->ErrorFlags = 0;
	Self->Position = -1;
	Self->Severity = kJB__ErrorSeverity_OK;
	Self->When = JB_Date__Now();
	Self->Func = kJB_SyxArg;
	return Self;
}

void JB_Err_Destructor(JB_Error* Self) {
	JB_Clear(Self->OriginalData);
	JB_Clear(Self->Path);
	JB_Clear(Self->Node);
	JB_Clear(Self->StackTrace);
	JB_Msg_Destructor(Self);
}

void JB_Err_Fill(JB_Error* Self, JB_String* Path, JB_String* Desc) {
	//visible;
	JB_SetRef(Self->Path, Path);
	((JB_Err_SyntaxIsSet(Self, kJB__ErrorFlags_PreferNoRenderPath, JB_Str_ContainsString(Desc, Path))));
	JB_SetRef(Self->Name, Desc);
}

void JB_Err_GrabLine(JB_Error* Self, FastString* Fs, bool Usecolor) {
	if (Usecolor) {
		JB_FS_AppendString(Fs, kJB__ErrorColors_normal);
	}
	JB_String* D = Self->OriginalData;
	JB_Incr(D);
	if (!(JB_Str_Exists(D) and JB_Err_HasPosition(Self))) {
		JB_Decr(D);
		return;
	}
	JB_FS_AppendByte(Fs, '\n');
	Ind Start = JB_Str_Find(D, JB__Constants_CSLine, Self->Position, 0) + 1;
	Ind Finish = JB_Str_Find(D, JB__Constants_CSLine, (Self->Position), JB_int__Max());
	if (Finish == -1) {
		Finish = (JB_Str_Length(D) + 1);
	}
	JB_String* _tmPf1 = JB_Str_Range(D, Start, Finish);
	JB_Incr(_tmPf1);
	JB_Decr(D);
	JB_String* _tmPf0 = JB_Str_ReplaceAll(_tmPf1, JB_LUB[45], JB_LUB[23], false, nil);
	JB_Incr(_tmPf0);
	JB_Decr(_tmPf1);
	JB_FS_AppendString(Fs, _tmPf0);
	JB_Decr(_tmPf0);
	Ind Spaces = (Self->Position - Start);
	if (Spaces > 200) {
		Spaces = 0;
	}
	JB_FS_AppendByte(Fs, '\n');
	if (Usecolor) {
		JB_FS_AppendString(Fs, kJB__ErrorColors_underline);
	}
	JB_FS_AppendMultiByte(Fs, ' ', Spaces);
	JB_FS_AppendByte(Fs, '^');
}

bool JB_Err_HasPosition(JB_Error* Self) {
	return Self->Position >= 0;
}

bool JB_Err_IsBad(JB_Error* Self) {
	return (Self->Severity >= kJB__ErrorSeverity_Problem);
}

bool JB_Err_IsError(JB_Error* Self) {
	return (Self->Severity >= kJB__ErrorSeverity_Error);
}

bool JB_Err_IsWarning(JB_Error* Self) {
	return (Self->Severity <= kJB__ErrorSeverity_Warning);
}

bool JB_Err_LineIdentifiers(JB_Error* Self, FastString* Fs, JB_String* Path) {
	if (!JB_Err_HasPosition(Self)) {
		return nil;
	}
	JB_String* D = Self->OriginalData;
	JB_Incr(D);
	if (!JB_Str_Exists(D)) {
		JB_Decr(D);
		return nil;
	}
	if (!JB_Str_Exists(Path)) {
		JB_FS_AppendString(Fs, JB_LUB[207]);
	}
	JB_FS_AppendInt32(Fs, JB_Err_LinePos(Self, D));
	JB_FS_AppendByte(Fs, ':');
	Ind Start = JB_Str_Find(D, JB__Constants_CSLine, Self->Position, 0);
	JB_Decr(D);
	JB_FS_AppendInt32(Fs, Self->Position - Start);
	JB_FS_AppendByte(Fs, ':');
	return true;
}

int JB_Err_LinePos(JB_Error* Self, JB_String* Data) {
	if (JB_Err_HasPosition(Self)) {
		JB_String* _tmPf0 = JB_Str_Range(Data, 0, Self->Position);
		JB_Incr(_tmPf0);
		int _tmPf1 = JB_Str_LineCount(_tmPf0);
		JB_Decr(_tmPf0);
		return _tmPf1;
	}
	return 0;
}

JB_String* JB_Err_Render(JB_Error* Self, FastString* Fs_in) {
	FastString* Fs = JB_FS__FastNew(Fs_in);
	JB_Incr(Fs);
	JB_FS_AppendString(Fs, JB_LUB[208]);
	(++Fs->Indent);
	JB_FS_AppendInfo(Fs, JB_LUB[0], Self->Name);
	if (Self->Position >= 0) {
		JB_FS_AppendInfoNum(Fs, JB_LUB[209], Self->Position);
	}
	JB_FS_AppendInfo(Fs, JB_LUB[210], Self->Path);
	JB_FS_AppendInfoNum(Fs, JB_LUB[211], Self->Severity);
	if (Self->Progress) {
		JB_FS_AppendInfoFloat(Fs, JB_LUB[212], Self->Progress);
	}
	if (JB_Str_Exists(Self->StackTrace)) {
		JB_FS_AppendInfo(Fs, JB_LUB[213], JB_LUB[0]);
		(++Fs->Indent);
		{
			JB_String* _LoopSrcf2 = Self->StackTrace;
			JB_Incr(_LoopSrcf2);
			int _Prevf0 = 0;
			while (((JB_String*)JB_Str_Exists((_LoopSrcf2)))) {
				Ind _Curr_f1 = JB_Str_Find(_LoopSrcf2, JB__Constants_CSLine, _Prevf0, JB_int__Max());
				JB_String* Fn = JB_Str_Range(_LoopSrcf2, _Prevf0, _Curr_f1);
				JB_Incr(Fn);
				JB_FS_AppendInfo(Fs, JB_LUB[214], Fn);
				JB_Decr(Fn);
				_Prevf0 = (_Curr_f1 + 1);
				if (!JB_Ind_SyntaxCast(_Curr_f1)) {
					break;
				}
			};
			JB_Decr(_LoopSrcf2);
		}
		;
		(--Fs->Indent);
	}
	JB_FS_AppendByte(Fs, '\n');
	(--Fs->Indent);
	JB_String* _tmPf4 = JB_FS_SmartResult(Fs, Fs_in);
	JB_Incr(_tmPf4);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf4);
	return _tmPf4;
}

JB_String* JB_Err_RenderUnix(JB_Error* Self, FastString* Fs_in) {
	FastString* Fs = JB_FS__FastNew(Fs_in);
	JB_Incr(Fs);
	int M = JB_FS_Mark(Fs);
	JB_String* P = Self->Path;
	JB_Incr(P);
	if (((!JB_Err_SyntaxIs(Self, kJB__ErrorFlags_PreferNoRenderPath))) and JB_Str_Exists(P)) {
		JB_FS_AppendString(Fs, Self->Path);
		JB_FS_AppendByte(Fs, ':');
	}
	if ((!JB_Err_LineIdentifiers(Self, Fs, P)) and Self->Node) {
		JB_FreeIfDead(JB_Msg_Render(Self->Node, Fs));
	}
	JB_Decr(P);
	if (JB_FS_Mark(Fs) > M) {
		JB_FS_AppendByte(Fs, ' ');
	}
	JB_FreeIfDead(JB_ErrorSeverity_Render(Self->Severity, Fs));
	JB_FS_AppendString(Fs, JB_LUB[73]);
	JB_FS_AppendString(Fs, Self->Name);
	JB_Err_GrabLine(Self, Fs, false);
	JB_String* _tmPf0 = JB_FS_SmartResult(Fs, Fs_in);
	JB_Incr(_tmPf0);
	JB_Decr(Fs);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

bool JB_Err_SyntaxIs(JB_Error* Self, uint /*ErrorFlags*/ F) {
	return Self and (Self->ErrorFlags & F);
}

void JB_Err_SyntaxIsSet(JB_Error* Self, uint /*ErrorFlags*/ F, bool Value) {
	if (Value) {
		Self->ErrorFlags = (Self->ErrorFlags | F);
	}
	 else {
		Self->ErrorFlags = (Self->ErrorFlags & (~F));
	}
}

void JB_Err_UpgradeWithNode(JB_Error* Self) {
	Message* Node = Self->Node;
	if (!Node) {
		Node = ((Message*)JB_Array_Last(JB__Err_CurrSource_));
		if (!Node) {
			return;
		}
		JB_SetRef(Self->Node, Node);
	}
	Self->Position = Node->Position;
	if (!JB_Str_Exists(Self->Path)) {
		JB_SetRef(Self->Path, JB_Msg_FilePath(Node));
	}
	JB_SetRef(Self->OriginalData, JB_Msg_OriginalParseData(Node));
}

void JB_Err__CantParseNum(Message* Where, JB_String* Num, int Pos, bool Overflow) {
	//visible;
	JB_String* Str = JB_LUB[257];
	JB_Incr(Str);
	if (!Overflow) {
		JB_String* _tmPf0 = JB_byte_Render(JB_Str_ByteValue(Num, Pos), nil);
		JB_Incr(_tmPf0);
		JB_SetRef(Str, JB_Str_OperatorPlus(JB_LUB[258], _tmPf0));
		JB_Decr(_tmPf0);
	}
	JB_Error* _tmPf1 = JB_Err_Constructor(nil, Where, Str, kJB__ErrorSeverity_Error, JB_LUB[0]);
	JB_Incr(_tmPf1);
	JB_Decr(Str);
	JB_Rec_AppendErr(((JB_ErrorReceiver*)nil), _tmPf1);
	JB_Decr(_tmPf1);
}

int JB_Err__Init_() {
	{
		JB_SetRef(JB__Err_CurrSource_, JB_Array_Constructor0(nil));
	}
	;
	return 0;
}





void JB_SS_ParserCallBack_interface_SyntaxCall(JB_Task* Self, Message* Msg) {
	return ((StringReader_ParserCallBack_interface_prototype)Self->_func)(Self, Msg);
}


void JB_SS_ParserCallBack_run(ParserCallBack* Self, Message* Msg) {
}



//// API START! ////

#pragma GCC visibility push(default)
__lib__ JB_String* jb_msg_name(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return JB_LUB[0];
	}
	return Self->Name;
}

__lib__ Syntax jb_msg_func(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return nil;
	}
	return Self->Func;
}

__lib__ int jb_msg_position(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return 0;
	}
	return Self->Position;
}

__lib__ void* jb_msg_tag(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return nil;
	}
	return ((void*)Self->Obj);
}

__lib__ void jb_msg_nameset(Message* Self, JB_String* Result) {
	if (!JB_Msg_NilCheck(Self)) {
		return;
	}
	JB_SetRef(Self->Name, Result);
}

__lib__ void jb_msg_funcset(Message* Self, Syntax Result) {
	if (!JB_Msg_NilCheck(Self)) {
		return;
	}
	Self->Func = Result;
}

__lib__ void jb_msg_positionset(Message* Self, int Result) {
	if (!JB_Msg_NilCheck(Self)) {
		return;
	}
	Self->Position = Result;
}

__lib__ void jb_msg_tagset(Message* Self, void* Result) {
	if (!JB_Msg_NilCheck(Self)) {
		return;
	}
	JB_SetRef(Self->Obj, ((JB_Object*)Result));
}

__lib__ void jb_msg_firstset(Message* Self, Message* Result) {
	if (!JB_Msg_NilCheck(Self)) {
		return;
	}
	(JB_Ring_FirstSet(Self, Result));
}

__lib__ void jb_msg_lastset(Message* Self, Message* Result) {
	if (!JB_Msg_NilCheck(Self)) {
		return;
	}
	(JB_Ring_LastSet(Self, Result));
}

__lib__ void jb_msg_prevset(Message* Self, Message* Result) {
	if (!JB_Msg_NilCheck(Self)) {
		return;
	}
	(JB_Ring_PrevSibSet(Self, Result));
}

__lib__ void jb_msg_nextset(Message* Self, Message* Result) {
	if (!JB_Msg_NilCheck(Self)) {
		return;
	}
	(JB_Ring_NextSibSet(Self, Result));
}

__lib__ Message* jb_msg_first(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return nil;
	}
	return ((Message*)JB_Ring_First(Self));
}

__lib__ Message* jb_msg_last(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return nil;
	}
	return ((Message*)JB_Ring_Last(Self));
}

__lib__ Message* jb_msg_prev(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return nil;
	}
	return ((Message*)JB_Ring_PrevSib(Self));
}

__lib__ Message* jb_msg_next(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return nil;
	}
	return ((Message*)JB_Ring_NextSib(Self));
}

__lib__ Message* jb_msg_parent(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return nil;
	}
	return ((Message*)JB_Ring_Parent(Self));
}

__lib__ Message* jb_msg_flatnext(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return nil;
	}
	return ((Message*)JB_Ring_FlatNext0(Self));
}

__lib__ Message* jb_msg_flatafter(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return nil;
	}
	return ((Message*)JB_Ring_FlatAfter(Self));
}

__lib__ Message* jb_msg_root(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return nil;
	}
	return ((Message*)JB_Ring_Root(Self));
}

__lib__ void jb_msg_remove(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return;
	}
	JB_Tree_Remove(Self);
}

__lib__ JB_String* jb_msg_render(Message* Self, int Mode) {
	JB_String* Rz = JB_LUB[0];
	JB_Incr(Rz);
	if (!JB_Msg_NilCheck(Self)) {
		JB_Decr(Rz);
		return JB_LUB[0];
	}
	if (Mode & 1) {
		JB_SetRef(Rz, JB_Msg_RenderJbin(Self, JB_LUB[0], nil));
	}
	 else {
		JB_SetRef(Rz, JB_Msg_Render(Self, nil));
	}
	if (Mode & 2) {
		JB_SetRef(Rz, JB_Str_Compress(Rz, kJB__MZLab_Default, nil));
	}
	JB_SafeDecr(Rz);
	return Rz;
}

__lib__ JB_String* jb_msg_ast(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return JB_LUB[0];
	}
	return JB_Msg_RenderAST(Self, 1, nil);
}

__lib__ Message* jb_msg_parseast(Message* Self) {
	if (!JB_Msg_NilCheck(Self)) {
		return nil;
	}
	return JB_Msg_ParseAST(Self);
}

__lib__ Message* jb_msg_copy(Message* Self, Message* Layer) {
	if (!JB_Msg_NilCheck(Self)) {
		return nil;
	}
	return JB_Msg_Copy(Self, Layer);
}

__lib__ Message* jb_msg_create(Message* Self, Syntax Type, JB_String* Name) {
	if (!JB_Syx_NilCheck(Type)) {
		return nil;
	}
	return JB_Msg_Msg(Self, Type, Name);
}

__lib__ void jb_msg_error(Message* Self, JB_String* ErrorMsg) {
	if (!JB_Msg_NilCheck(Self)) {
		return;
	}
	JB_Rec__Latchkum(Self, ErrorMsg, nil);
}

__lib__ Message* jb_msg_expect(Message* Self, Syntax Type, JB_String* Name, Message* ErrPlace) {
	if (Self) {
		if (JB_Msg_Expect(Self, Type, Name)) {
			return Self;
		}
	}
	 else if (ErrPlace) {
		JB_Msg_CantFind(ErrPlace, Type, Name, nil);
	}
	return nil;
}

__lib__ Message* jb_msg_access(Message* Self, Syntax Type, JB_String* Name, bool IsError) {
	return JB_Msg_FindSyxName(Self, Type, Name, IsError);
}

__lib__ JB_String* jb_syx_name(Syntax Self) {
	if (!JB_Syx_NilCheck(Self)) {
		return JB_LUB[0];
	}
	return JB_Syx_Name(Self);
}

__lib__ JB_String* jb_syx_longname(Syntax Self) {
	if (!JB_Syx_NilCheck(Self)) {
		return JB_LUB[0];
	}
	return JB_Syx_LongName(Self);
}

__lib__ _cstring jb_string_address(JB_String* Self) {
	if ((!JB_Str_Exists(Self))) {
		return nil;
	}
	return ((_cstring)Self->Addr);
}

__lib__ int jb_string_length(JB_String* Self) {
	return JB_Str_Length(Self);
}

__lib__ JB_String* jb_string_compress(JB_String* Self) {
	return JB_Str_Compress(Self, kJB__MZLab_Default, nil);
}

__lib__ JB_String* jb_string_decompress(JB_String* Self) {
	return JB_Str_Decompress(Self, 268435456, nil);
}

__lib__ JB_String* jb_string_copy(JB_String* Self) {
	return JB_Str_Copy(Self);
}

__lib__ Message* jb_string_parse(JB_String* Self, JB_String* Path) {
	if ((!JB_Str_Exists(Self))) {
		return nil;
	}
	return JB_API__Parse(Self, Path);
}

__lib__ JB_String* jb_string_escape(JB_String* Self) {
	return JB_Str_Escape(Self);
}

__lib__ void jb_string_print(JB_String* Self) {
	JB_Print(Self);
}

__lib__ void jb_string_printline(JB_String* Self) {
	JB_PrintLine(Self);
}

__lib__ int64 jb_string_int(JB_String* Self, Message* M) {
	return JB_Str_TextIntegerValid(Self, M);
}

__lib__ Float64 jb_string_float(JB_String* Self, Message* M) {
	return JB_Str_TextDouble(Self, M);
}

__lib__ Syntax jb_syntax(JB_String* Name) {
	return JB_Syx__Func(Name, nil);
}

__lib__ JB_String* jb_str(_cstring Str, int Length, void* Release, void* Tag) {
	if ((!Str) or (Length < 0)) {
		return JB_LUB[0];
	}
	if (!Length) {
		Length = strlen(Str);
	}
	return JB_StrFromPtr(((void*)Str), Length, Release, Tag);
}

__lib__ JB_String* jb_cstr(_cstring Str) {
	if (Str) {
		return JB_StrFromPtr(((void*)Str), strlen(Str), nil, nil);
	}
	return JB_LUB[0];
}

__lib__ void jb_delete_(JB_Object* Obj) {
}

__lib__ Message* jb_errors() {
	return JB_API__Errors();
}

__lib__ bool jb_ok() {
	return JB_Rec_OK(JB_StdErr);
}

__lib__ void jb_debug(JB_Object* O) {
	jdb(O);
}

__lib__ int jb_init(int Flags) {
	return JB_API__Init(Flags);
}

__lib__ int jb_shutdown() {
	JB_Rec_Clear(JB_StdErr);
	JB_LibShutdown();
	return 0;
}

__lib__ int jb_version() {
	return (2025052018);
}

__lib__ JB_String* jb_readfile(_cstring Path, bool AllowMissingFile) {
	JB_API__Init(0);
	return JB_CPath_ReadAll(Path, AllowMissingFile, 100000000);
}

#pragma GCC visibility pop
//// API END! ////
}

// -2934619186805667969 7046592197676587629 20170614151768522
