
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

#pragma GCC visibility push(hidden)
extern "C" {

extern JB_String* JB_LUB[349];

extern Object_Behaviour JB_Object_FuncTable_;



int JB_App__Init_() {
	{
		JB__App_Unregistered = false;
		JB_SetRef(JB__App__Path, JB_LUB[0]);
		JB_SetRef(JB__App_Usage, JB_LUB[1]);
		JB_SetRef(JB__App_codesign_native, JB_LUB[2]);
	}
	;
	return 0;
}

int JB_App__InitCode_() {
	return 0;
}

int JB_Main() {
	//visible;
	return 0;
}

int64 JB_App__ObjMemory() {
	return JB_MemCount();
}


int JB_ErrorColors__Init_() {
	{
		JB__ErrorColors_Enabled = false;
	}
	;
	return 0;
}

int JB_ErrorColors__InitCode_() {
	return 0;
}


Message* JB_API__errors() {
	Message* rz = nil;
	if (JB_Rec_OK(JB_StdErr)) {
		return nil;
	}
	rz = JB_StdErr->Errors;
	{
		Message* err = ((Message*)JB_Tree_First_(rz));
		while (err) {
			Message* _Nf1 = ((Message*)JB_Ring_NextSib(err));
			JB_SetRef(err->Name, JB_Msg_Render(err, nil));
			err = _Nf1;
		};
		(rz);
	}
	;
	JB_Rec_Clear(JB_StdErr);
	return rz;
}

int JB_API__Init(int flags) {
	if ((!(JB_StdErr == nil))) {
		return nil;
	}
	int ErrCode = JB_LibInit(nil);
	if (ErrCode) {
		return ErrCode;
	}
	JB_String* msg = JB_Incr(JB_Constants__TestJB());
	if (((bool)(flags & 1))) {
		JB_PrintLine(msg);
	}
	JB_Decr(msg);
	if ((!JB_Rec_OK(JB_StdErr))) {
		JB_Error* _tmPf0 = JB_Incr(((JB_Error*)JB_Ring_First(JB_StdErr->Errors)));
		JB_Str_Print(_tmPf0->Name);
		JB_Decr(_tmPf0);
		JB_Rec_Clear(JB_StdErr);
		return -1000;
	}
	return 0;
}

int JB_API__Init_() {
	{
		JB__API_NilHappened = 0;
	}
	;
	return 0;
}

int JB_API__InitCode_() {
	return 0;
}

void JB_API__NilCallBack(JB_String* ErrorMessage) {
	JB_PrintLine(ErrorMessage);
}

bool JB_API__NilHandler() {
	if ((!JB_Rec_OK(JB_StdErr))) {
		return nil;
	}
	debugger;
	if ((++JB__API_NilHappened) < 16) {
		JB_API__NilCallBack(JB_LUB[3]);
	}
	 else if (JB__API_NilHappened == 16) {
		JB_API__NilCallBack(JB_LUB[4]);
	}
	return false;
}

Message* JB_API__Parse(JB_String* s, JB_String* path) {
	if ((!(s != nil))) {
		return nil;
	}
	JB_MemoryLayer* L = JB_Incr(JB_Mem_CreateLayer((JB_AsClass(Message)), path));
	if ((!L)) {
		JB_Decr(L);
		return nil;
	}
	JB_Mem_Use(L);
	JB_SetRef(L->Obj2, s);
	JB_Decr(L);
	Message* Result = JB_Incr(JB_Str_Parse(s, JB_SyxArg, true));
	JB_ClassData_Restore((JB_AsClass(Message)));
	JB_SafeDecr(Result);
	return Result;
}


void JB_Constants__AddEscape(int i, FastString* fs) {
	JB_String* f = JB_Str__SyntaxAccess(i);
	if ((!((!JB_Str_Exists(((JB_String*)JB_Dict_ValueStr(JB__Constants_EscapeStr, f)))) or (!JB_Str_Exists(((JB_String*)JB_Dict_ValueStr(JB__Constants_EscapeChr, f))))))) {
		return;
	}
	JB_FS_AppendByte(fs, '\\');
	JB_FS_AppendHex(fs, i, 2);
	JB_String* t = JB_FS_GetResult(fs);
	if ((!(JB_Str_Exists(((JB_String*)JB_Dict_ValueStr(JB__Constants_EscapeStr, f)))))) {
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, f, t));
	}
	if ((!(JB_Str_Exists(((JB_String*)JB_Dict_ValueStr(JB__Constants_EscapeChr, f)))))) {
		(JB_Dict_ValueSet(JB__Constants_EscapeChr, f, t));
	}
}

int JB_Constants__Init_() {
	{
		JB_SetRef(JB__Constants_Name, JB_LUB[5]);
		JB_SetRef(JB__Constants_EscapeStr, (JB_Dict__New()));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[6], JB_LUB[7]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[8], JB_LUB[9]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[10], JB_LUB[11]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[12], JB_LUB[13]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[14], JB_LUB[15]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[16], JB_LUB[17]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[18], JB_LUB[19]));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[20], JB_LUB[21]));
		JB_SetRef(JB__Constants_XML_EscapeStr, (JB_Dict__New()));
		(JB_Dict_ValueSet(JB__Constants_XML_EscapeStr, JB_LUB[22], JB_LUB[23]));
		(JB_Dict_ValueSet(JB__Constants_XML_EscapeStr, JB_LUB[16], JB_LUB[24]));
		(JB_Dict_ValueSet(JB__Constants_XML_EscapeStr, JB_LUB[14], JB_LUB[25]));
		(JB_Dict_ValueSet(JB__Constants_XML_EscapeStr, JB_LUB[26], JB_LUB[27]));
		(JB_Dict_ValueSet(JB__Constants_XML_EscapeStr, JB_LUB[28], JB_LUB[29]));
		JB_SetRef(JB__Constants_JS_EscapeStr, (JB_Dict__New()));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[30], JB_LUB[31]));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[32], JB_LUB[33]));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[8], JB_LUB[9]));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[10], JB_LUB[11]));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[12], JB_LUB[13]));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[14], JB_LUB[15]));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_LUB[18], JB_LUB[19]));
		JB_SetRef(JB__Constants_CSWordMiddle, JB_Str_UniCS(JB_LUB[34]));
		JB_SetRef(JB__Constants_CSLettersOnly, JB_Str_UniCS(JB_LUB[35]));
		JB_SetRef(JB__Constants_CSWordStart, JB_Str_UniCS(JB_LUB[36]));
		JB_SetRef(JB__Constants_CSNum, JB__Constants_CSWordMiddle);
		JB_SetRef(JB__Constants_CSLine, JB_Str_CharSetWithBool(JB_LUB[37], false));
		JB_SetRef(JB__Constants_CSAfterStatement, JB_Str_CharSetWithBool(JB_LUB[38], false));
		JB_SetRef(JB__Constants_CSLineBlack, JB_Str_CharSetWithBool(JB_LUB[39], false));
		JB_SetRef(JB__Constants_CSWrapSplit, JB_Str_CharSetWithBool(JB_LUB[40], false));
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
	JB_FreeIfDead(JB_Array__New0());
	JB_SetRef(JB__Constants_EscapeChr, JB_Dict__Copy(JB__Constants_EscapeStr));
	(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[41], JB_LUB[42]));
	JB_SetRef(JB__Constants_UnEscapeStr, JB_Dict__Reverse(JB__Constants_EscapeStr));
	JB_SetRef(JB__Constants_JS_UnEscapeStr, JB_Dict__Reverse(JB__Constants_JS_EscapeStr));
	JB_SetRef(JB__Constants_XML_UnEscapeStr, JB_Dict__Reverse(JB__Constants_XML_EscapeStr));
	(JB_Dict_ValueSet(JB__Constants_EscapeChr, JB_LUB[14], ((JB_String*)nil)));
	(JB_Dict_ValueSet(JB__Constants_EscapeChr, JB_LUB[41], ((JB_String*)nil)));
	(JB_Dict_ValueSet(JB__Constants_UnEscapeStr, JB_LUB[43], ((JB_String*)nil)));
	(JB_Dict_ValueSet(JB__Constants_UnEscapeStr, JB_LUB[18], JB_LUB[0]));
	(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[16], ((JB_String*)nil)));
	FastString* tfs = JB_Incr(JB_FS__New());
	{
		int i = 0;
		while (i < 256) {
			if ((i <= 31) or (((i == 127) or ((i == 192) or (i == 193))) or (i >= 245))) {
				JB_Constants__AddEscape(i, tfs);
			}
			i++;
		};
	}
	;
	JB_Decr(tfs);
	JB_MSR_EscapeCodeSet(JB__Constants_UnEscapeStr, true);
	JB_MSR_DecodeEntitySet(JB__Constants_UnEscapeStr, true);
	JB_MSR_DecodeEntitySet(JB__Constants_XML_UnEscapeStr, true);
	(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_LUB[44], JB_LUB[45]));
}

JB_String* JB_Constants__TestJB() {
	FastString* fs = JB_Incr(JB_FS__New());
	{
		int c = 0;
		while (c < 256) {
			JB_FS_AppendByte(fs, ((byte)c));
			c++;
		};
	}
	;
	JB_String* str = JB_Incr(JB_FS_GetResult(fs));
	JB_Decr(fs);
	if ((!JB_Str_EscapeTest(str))) {
		JB_Decr(str);
		return nil;
	}
	JB_Decr(str);
	JB_String* natural_input = JB_Incr(JB_LUB[46]);
	JB_String* jbin_input = JB_Incr(JB_LUB[47]);
	if ((!(JB_TestCasting()))) {
		debugger;
	}
	JB_FreeIfDead(JB_Str_UpperCase(JB_LUB[48]));
	LeakTester* LKT = JB_Incr(JB_Lk__New(JB_LUB[49]));
	JB_FreeIfDead(JB_EntityTest());
	JB_Lk_FinalTest(LKT);
	JB_Decr(LKT);
	if ((!JB_Rec_OK(JB_StdErr))) {
		JB_Decr(natural_input);
		JB_Decr(jbin_input);
		return nil;
	}
	Message* root = JB_Incr(JB_Str_Parse(natural_input, JB_SyxArg, true));
	JB_Decr(natural_input);
	if ((!root)) {
		JB_Decr(jbin_input);
		JB_Decr(root);
		return nil;
	}
	JB_Msg_jbinTest(root);
	if (JB_Str_Exists(jbin_input)) {
		Message* _tmPf1 = JB_Incr(JB_Msg_NiceCopy(root, nil));
		JB_Msg__TreeCompare(root, _tmPf1, false);
		JB_Decr(_tmPf1);
		Message* _tmPf2 = JB_Incr(JB_Str_Parse(jbin_input, JB_SyxArg, true));
		JB_Msg__TreeCompare(root, _tmPf2, false);
		JB_String* _tmPf3 = JB_Incr(JB_Msg_Render(root, nil));
		JB_Msg_Test(root, _tmPf3, JB_LUB[48]);
		JB_Decr(_tmPf3);
		JB_String* _tmPf4 = JB_Incr(JB_Msg_render_jbin(root, JB_LUB[0], nil));
		JB_Msg_Test(root, _tmPf4, JB_LUB[50]);
		JB_Decr(_tmPf4);
		JB_Decr(_tmPf2);
	}
	JB_Decr(jbin_input);
	if ((!JB_Rec_OK(JB_StdErr))) {
		JB_Decr(root);
		return nil;
	}
	JB_Decr(root);
	return JB_EntityTest();
}




Message* JB_Tk__AddToOutput(Message* Output, Message* curr, Message* prev, int pos) {
	if (prev) {
		int Extra = JB_Msg_PrevIndentCheck(curr, prev);
		if (Extra < 0) {
			return JB_Tk__LoweredIndent(Output, curr);
		}
		if (Extra > 0) {
			if ((Extra == 2) and (JB_int_OperatorIsa(((int)prev->Indent), 4))) {
				Syntax cf = curr->Func;
				if ((prev->Func != JB_SyxTmp) or ((cf != JB_SyxTmp) and (cf != JB_SyxBra))) {
					return JB_Tk__UnexpectedSyntax(curr);
				}
				if (((bool)(curr->Indent & 1))) {
					return JB_Tk__ErrorAdd(JB_LUB[51], curr->Position);
				}
				JB_FreeIfDead(JB_Tk__NewParentName(prev, JB_SyxArg, curr->Position, JB_LUB[0]));
				JB_Tree_SyntaxAppend(prev, curr);
				return prev;
			}
			return JB_Msg_GoIntoInvisArg(curr, prev, pos);
		}
	}
	JB_Tree_SyntaxAppend(Output, curr);
	return Output;
}

void JB_Tk__AddXMLText(Message* XML, JB_String* s, int start, int i) {
	Ind a = JB_Str_OutWhite(s, start, JB_int__max());
	if ((!(a < i))) {
		return;
	}
	JB_String* str = JB_Incr(JB_Str_Range(s, start, i));
	JB_String* str2 = JB_Incr(JB_Str_Trim(str, nil));
	JB_Decr(str);
	JB_String* str3 = JB_Incr(JB_Str_MultiReplaceAll(str2, JB__Constants_XML_UnEscapeStr, JB_StdErr));
	JB_Decr(str2);
	JB_FreeIfDead(JB_Tk__NewParentName(XML, JB_SyxXTxt, start, str3));
	JB_Decr(str3);
}

Message* JB_Tk__BarThings(int Start, Syntax Syx) {
	Message* rz = nil;
	if ((!(JB_Tk__NextByte() != '='))) {
		JB_Decr(rz);
		return nil;
	}
	JB__Tk_StopBars = (kJB__Tk_TemporalSyx | kJB__Tk_FuncAfterBar);
	Message* item = JB_Incr(JB_Tk__ProcessThingNoBar(kJB__Tk_OppNoBar, false));
	if (item) {
		JB_SetRef(item, JB_Tk__ParseItem(item, 0, kJB__Tk_OppNoBar));
	}
	 else {
		JB_SetRef(item, JB_Tk__NewEmpty(nil, JB_SyxEmb, Start, Start));
	}
	JB__Tk_StopBars = 0;
	if ((!JB_Tk__ExpectEndChar(JB_Tk__NextStart(), JB_LUB[52], true))) {
		JB_Decr(rz);
		JB_Decr(item);
		return nil;
	}
	JB_SetRef(rz, JB_Tk__NewParentName(nil, Syx, Start, JB_LUB[0]));
	JB_Tree_SyntaxAppend(rz, item);
	JB_Decr(item);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__BeforeRelSub(int Start, bool Mode) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__NewParent(nil, JB_SyxBRel, Start, JB_Tk__NextStart()));
	Message* _tmPf0 = JB_Incr(JB_Tk__ProcessThing(0, Mode));
	if ((!_tmPf0)) {
		JB_Decr(rz);
		JB_Decr(_tmPf0);
		return nil;
	}
	JB_Tree_SyntaxAppend(rz, _tmPf0);
	JB_Decr(_tmPf0);
	JB_SafeDecr(rz);
	return rz;
}

bool JB_Tk__CanStatement() {
	return JB_CS_HasChar(JB__Constants_CSAfterStatement, JB_Tk__NextByte());
}

Message* JB_Tk__ChainTemporalRels(Message* FirstThing, Message* opp) {
	Message* rz = nil;
	if (JB_Msg_EqualsSyx(opp, JB_SyxSCom, false)) {
		JB_Tree_SyntaxAppend(opp, FirstThing);
		JB_Decr(rz);
		return opp;
	}
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxTRel, FirstThing->Position, JB_LUB[0]));
	JB_Tree_SyntaxAppend(rz, FirstThing);
	JB_Tree_SyntaxAppend(rz, opp);
	if ((!JB_Tk__WillEnd())) {
		Message* Last = JB_Incr(JB_Tk__ProcessThingOrTmp(kJB__Tk_Opp));
		if (Last) {
			Message* _tmPf0 = JB_Incr(JB_Tk__FixTRels(rz, Last));
			JB_Decr(rz);
			JB_Decr(Last);
			JB_SafeDecr(_tmPf0);
			return _tmPf0;
		}
		JB_Decr(Last);
	}
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__CloseXML(Message* XML, int i, JB_String* s) {
	Ind CloseEnd = JB_Str_FindByte(s, '>', i + 2, JB_int__max());
	if ((!(JB_Ind_SyntaxCast(CloseEnd)))) {
		return JB_Tk__ErrorAdd(JB_LUB[53], i);
	}
	JB_String* CloseName = JB_Incr(JB_Str_Range(s, i + 2, CloseEnd));
	if ((!JB_Str_Equals(CloseName, XML->Name, false))) {
		FastString* _fsf0 = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fsf0, JB_LUB[54]);
		JB_FS_AppendString(_fsf0, CloseName);
		JB_FS_AppendString(_fsf0, JB_LUB[55]);
		JB_FS_AppendString(_fsf0, XML->Name);
		JB_FS_AppendByte(_fsf0, '>');
		JB_String* _tmPf1 = JB_Incr(JB_FS_GetResult(_fsf0));
		JB_Decr(_fsf0);
		JB_Decr(CloseName);
		Message* _tmPf2 = JB_Incr(JB_Tk__ErrorAdd(_tmPf1, i));
		JB_Decr(_tmPf1);
		JB_SafeDecr(_tmPf2);
		return _tmPf2;
	}
	JB_Decr(CloseName);
	(JB_Tk__NextStartSet((++CloseEnd)));
	XML->Extra = ((XML->Position - CloseEnd) | JB__Tk_BaseExtra);
	return XML;
}

Message* JB_Tk__DecorateThing(Message* R, int Ops) {
	JB_Incr(R);
	JB_SetRef(R, JB_Tk__GetFuncAfter(R));
	if (JB_Tk__WillEnd()) {
		JB_SafeDecr(R);
		return R;
	}
	int NotTemp = Ops & (~kJB__Tk_OppTemporal);
	if (((bool)NotTemp) and (!JB_Msg_EqualsSyx(R, JB_SyxArg, false))) {
		JB_SetRef(R, JB_Tk__MakeRel(R, NotTemp));
	}
	if (((bool)(Ops & kJB__Tk_OppTemporal))) {
		Message* opp = JB_Incr(JB_Tk__Process(kJB__Tk_OppTemporal, false, nil));
		if (opp) {
			if (JB_Msg_SyntaxEquals(opp, JB_LUB[56], false)) {
				Message* A = JB_Incr(JB_Tk__PostInnerAdj(R, opp));
				JB_Decr(R);
				JB_Decr(opp);
				Message* _tmPf1 = JB_Incr(JB_Tk__DecorateThing(A, Ops));
				JB_Decr(A);
				JB_SafeDecr(_tmPf1);
				return _tmPf1;
			}
			Message* _tmPf0 = JB_Incr(JB_Tk__ChainTemporalRels(R, opp));
			JB_Decr(R);
			JB_Decr(opp);
			JB_SafeDecr(_tmPf0);
			return _tmPf0;
		}
		JB_Decr(opp);
	}
	JB_SafeDecr(R);
	return R;
}

Message* JB_Tk__DotSub(Syntax fn, int Start, Message* parent) {
	Message* rz = nil;
	int after = JB_Tk__Byte((++Start));
	if (JB_CS_HasChar(JB__Constants_CSWordStart, after)) {
		after = JB_Tk__WordAfter(Start);
		if ((!after)) {
			return nil;
		}
	}
	 else if (JB__Tk_DotInsertAllow) {
		after = Start;
		JB__Tk_DotInsertAllow = false;
	}
	 else {
		return nil;
	}
	rz = JB_Tk__NewSkip(nil, fn, Start - 1, Start, after);
	if (JB_Tk__EatString(JB_LUB[57])) {
		JB_Tk__Params(rz, after);
	}
	 else {
		Message* prms = JB_Tk__NewEmpty(rz, JB_SyxEmb, after, after);
		if (((JB_Msg_EqualsSyx(parent, JB_SyxArg, false))) and JB_Tk__CanStatement()) {
			Message* p = JB_Tk__ProcessThingParent(prms, kJB__Tk_Opp, kJB__Tk_Thing);
			if (p) {
				JB_Tree_SyntaxAppend(prms, p);
				prms->Func = JB_SyxPrm;
			}
		}
	}
	return rz;
}

int JB_Tk__EmbeddedArg(JB_String* close, Message* R, int Flags) {
	Message* arg = JB_Incr(JB_Tk__NewParentName(R, JB_SyxArg, JB_Tk__NextStart(), JB_LUB[0]));
	int _tmPf0 = JB_Tk__EmbeddedCode(close, arg, Flags);
	JB_Decr(arg);
	return _tmPf0;
}

int JB_Tk__EmbeddedCode(JB_String* close, Message* dest, int TmpoFlags) {
	Ind result = JB_Str_InStr(JB__Tk_Data, close, JB_Tk__NextStart(), JB_int__max(), false);
	if ((!(JB_Ind_SyntaxCast(result)))) {
		FastString* _fsf0 = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fsf0, JB_LUB[58]);
		JB_FS_AppendString(_fsf0, close);
		JB_String* _tmPf2 = JB_Incr(JB_FS_GetResult(_fsf0));
		JB_Decr(_fsf0);
		JB_FreeIfDead(JB_Tk__ErrorAdd(_tmPf2, JB_Tk__NextStart()));
		JB_Decr(_tmPf2);
		return result;
	}
	JB_Tk__ParseLoop(dest, TmpoFlags);
	if (JB_Tk__NextStart() > result) {
		FastString* _fsf1 = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fsf1, JB_LUB[59]);
		JB_FS_AppendString(_fsf1, close);
		JB_FS_AppendString(_fsf1, JB_LUB[60]);
		JB_String* _tmPf3 = JB_Incr(JB_FS_GetResult(_fsf1));
		JB_Decr(_fsf1);
		JB_FreeIfDead(JB_Tk__ErrorAdd(_tmPf3, result));
		JB_Decr(_tmPf3);
		return result;
	}
	result = (result + JB_Str_Length(close));
	(JB_Tk__NextStartSet(result));
	return result;
}

Message* JB_Tk__ErrorAdd(JB_String* s, Ind Start) {
	if ((!JB_Tk__OK())) {
		return nil;
	}
	return JB_Tk__ErrorAlwaysAdd(s, Start);
}

Message* JB_Tk__ErrorAlwaysAdd(JB_String* s, Ind Start) {
	(JB_Tk__ErrorStartSet(Start));
	Message* _tmPf0 = JB_Incr(JB_Msg__NewBasic());
	JB_Error* err = JB_Incr(JB_Err__New(_tmPf0, JB_LUB[0], kJB__ErrorSeverity_Error, JB_LUB[0]));
	JB_Decr(_tmPf0);
	err->Position = Start;
	(JB_Err_SyntaxIsSet(err, kJB__ErrorFlags_dontstrip, true));
	(JB_Err_SyntaxIsSet(err, kJB__ErrorFlags_parse, true));
	JB_SetRef(err->Name, s);
	JB_SetRef(err->OriginalData, JB__Tk_Data);
	JB_Rec_SyntaxAppend(JB_StdErr, err);
	JB_Decr(err);
	return nil;
}

void JB_Tk__ErrorEvent(int Start, int ExpectedBits, int RealBits) {
	//visible;
	FastString* Err = JB_Incr(JB_FS__New());
	if ((!(((bool)(RealBits & kJB__Tk_illegalchar))))) {
		if ((!(((bool)ExpectedBits) and (((bool)RealBits) and ((bool)JB_Tk__FindError(ExpectedBits)))))) {
			JB_FS_AppendString(Err, JB_LUB[61]);
		}
		 else {
			{
				int _Valuef1 = 0;
				while (_Valuef1 < 5) {
					ExpectedBits = JB_Tk__MessageErrorSub(Err, ExpectedBits, RealBits);
					_Valuef1++;
					if ((!ExpectedBits)) {
						break;
					}
				};
			}
			;
			JB_FS_AppendString(Err, JB_LUB[62]);
		}
	}
	if (RealBits == kJB__Tk_EndOfLine) {
		JB_FS_AppendString(Err, JB_LUB[63]);
	}
	 else if ((!RealBits)) {
		JB_FS_AppendString(Err, JB_LUB[64]);
	}
	 else {
		if (JB_Tk__NextStart() <= Start) {
			(JB_Tk__NextStartSet(Start + 1));
		}
		if (((bool)(RealBits & kJB__Tk_illegalchar))) {
			JB_FS_AppendString(Err, JB_LUB[65]);
			byte illegal = JB_Tk__Byte(Start);
			if (JB_byte_CanPrintAsNormalChar(illegal)) {
				JB_FS_AppendByte(Err, '\'');
				JB_FS_AppendByte(Err, JB_Tk__Byte(Start));
				JB_FS_AppendByte(Err, '\'');
			}
			 else {
				JB_FS_AppendString(Err, JB_LUB[66]);
				JB_FS_AppendHex(Err, illegal, 2);
				JB_FS_AppendByte(Err, ' ');
			}
		}
		 else {
			JB_FS_AppendByte(Err, '\'');
			Ind N = JB_int_OperatorMin(JB_Tk__NextStart(), (Start + 100));
			JB_String* _tmPf3 = JB_Incr(JB_Tk__Range(Start, N));
			JB_String* _tmPf2 = JB_Incr(JB_Str_Escape(_tmPf3));
			JB_Decr(_tmPf3);
			JB_FS_AppendString(Err, _tmPf2);
			JB_Decr(_tmPf2);
			JB_FS_AppendByte(Err, '\'');
		}
	}
	JB_String* _tmPf4 = JB_Incr(JB_FS_SyntaxCast(Err));
	JB_Decr(Err);
	JB_FreeIfDead(JB_Tk__ErrorAdd(_tmPf4, Start));
	JB_Decr(_tmPf4);
}

void JB_Tk__ErrorLetter(int Start) {
	JB_FreeIfDead(JB_Tk__ErrorAdd(JB_LUB[67], Start));
}

bool JB_Tk__ExpectEndChar(int start, JB_String* s, bool Expect) {
	JB_Tk__CleanSpaces();
	if (JB_Tk__EatString(s)) {
		return true;
	}
	if (Expect) {
		FastString* _fsf0 = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fsf0, JB_LUB[68]);
		JB_FS_AppendString(_fsf0, s);
		JB_FS_AppendByte(_fsf0, '\'');
		JB_String* _tmPf1 = JB_Incr(JB_FS_GetResult(_fsf0));
		JB_Decr(_fsf0);
		JB_FreeIfDead(JB_Tk__ErrorAdd(_tmPf1, start));
		JB_Decr(_tmPf1);
	}
	return false;
}

Message* JB_Tk__fAccess(int Start, Message* Parent) {
	Message* rz = nil;
	Ind pos = ((Ind)JB_Ternary(((bool)Parent), Parent->Position, ((Ind)Start)));
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxAcc, pos, JB_LUB[0]));
	Message* prms = JB_Incr(JB_Tk__NewParentName(rz, JB_SyxArr, Start, JB_LUB[0]));
	JB_Tk__ParseLoopFlags(prms, JB_LUB[69], 0);
	(JB_Msg_AfterSet(rz, JB_Msg_After(prms)));
	JB_Decr(prms);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fAdjectiveOp(int Start, Message* Parent) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxAdj, Start, JB_LUB[0]));
	Message* _tmPf0 = JB_Incr(JB_Tk__Process(kJB__Tk_OppChain, kJB__Tk_Expect, nil));
	JB_Tree_SyntaxAppend(rz, _tmPf0);
	JB_Decr(_tmPf0);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fAdjectiveThing(int Start, Message* Parent) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxAdj, Start, JB_LUB[0]));
	Message* _tmPf0 = JB_Incr(JB_Tk__ProcessThing(0, kJB__Tk_Expect));
	JB_Tree_SyntaxAppend(rz, _tmPf0);
	JB_Decr(_tmPf0);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fAfterRel(int Start, Message* Parent) {
	return JB_Tk__NewParent(nil, JB_SyxARel, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fArgColon(int Start, Message* Parent) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxArg, Start, JB_LUB[0]));
	(JB_Msg_SyntaxIsSet(rz, kJB__MsgUIFlags_Style2, true));
	rz->Extra = (1 | JB__Tk_BaseExtra);
	while (true) {
		Message* Item = JB_Incr(JB_Tk__Process(kJB__Tk_Temporal, false, rz));
		if ((!Item)) {
			JB_SetRef(Item, JB_Tk__ProcessThing(kJB__Tk_Opp, false));
		}
		JB_Tree_SyntaxAppend(rz, Item);
		if ((!(((bool)Item) and JB_Tk__Allow(kJB__Tk_Comma)))) {
			JB_Decr(Item);
			break;
		}
		JB_Decr(Item);
	};
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fArgOpen(int Start, Message* Parent) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxArg, Start, JB_LUB[0]));
	(JB_Msg_SyntaxIsSet(rz, kJB__MsgUIFlags_Style2, true));
	JB_Tk__ParseLoopFlags(rz, JB_LUB[70], kJB__Tk_Temporal);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fArray(int Start, Message* Parent) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxArr, Start, JB_LUB[0]));
	JB_Tk__ParseLoopFlags(rz, JB_LUB[69], kJB__Tk_TemporalSyxNoBar);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fAsk(int Start, Message* Parent) {
	return JB_Tk__fAskSub(Start, Parent, JB_SyxAsk);
}

Message* JB_Tk__fAskSub(int Start, Message* Parent, Syntax f) {
	Message* rz = nil;
	Message* opp = JB_Incr(JB_Tk__Process(kJB__Tk_Opp, kJB__Tk_Expect, nil));
	Message* first = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_OppSyx, kJB__Tk_Expect));
	if ((!(((bool)first) and ((bool)opp)))) {
		JB_Decr(rz);
		JB_Decr(opp);
		JB_Decr(first);
		return nil;
	}
	JB_SetRef(rz, JB_Tk__NewParentName(nil, f, Start, JB_LUB[0]));
	JB_Tree_SyntaxAppend(rz, first);
	JB_Decr(first);
	Message* NeedsAdj = JB_Incr(JB_Tk__Process(kJB__Tk_Opp, kJB__Tk_Allow, nil));
	if ((!(NeedsAdj))) {
		JB_Tree_SyntaxAppend(rz, opp);
	}
	 else {
		Message* adj = JB_Incr(JB_Tk__NewParentName(rz, JB_SyxAdj, NeedsAdj->Position, JB_LUB[0]));
		JB_Tree_SyntaxAppend(adj, opp);
		JB_Tree_SyntaxAppend(adj, NeedsAdj);
		JB_Decr(adj);
		Message* _tmPf0 = JB_Incr(JB_Tk__ProcessThingParent(rz, kJB__Tk_OppSyx, kJB__Tk_Thing));
		JB_Tree_SyntaxAppend(rz, _tmPf0);
		JB_Decr(_tmPf0);
	}
	JB_Decr(NeedsAdj);
	JB_Decr(opp);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fAtName(int Start, Message* Parent) {
	return JB_Tk__NewWord(nil, JB_SyxName, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fAtNamedExp(int Start, Message* Parent) {
	if ((!Parent)) {
		debugger;
		return nil;
	}
	if ((!JB_Tk__NeedName(Parent))) {
		return nil;
	}
	Parent->Func = JB_SyxName;
	Message* _tmPf0 = JB_Incr(JB_Tk__ProcessThing(0, kJB__Tk_Expect));
	JB_Tree_SyntaxAppend(Parent, _tmPf0);
	JB_Decr(_tmPf0);
	return Parent;
}

Message* JB_Tk__fBackTick(int Start, Message* Parent) {
	Ind After = JB_Str_FindByte(JB__Tk_Data, '`', JB_Tk__NextStart(), JB_int__max());
	if ((!JB_Ind_SyntaxCast(After))) {
		return JB_Tk__ErrorAdd(JB_LUB[71], Start);
	}
	(JB_Tk__NextStartSet(After + 1));
	return JB_Tk__NewSkip(nil, JB_SyxBack, Start, Start + 1, After);
}

Message* JB_Tk__fBAdjectiveOp(int Start, Message* Parent) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxBadj, Start, JB_LUB[0]));
	Message* _tmPf0 = JB_Incr(JB_Tk__Process(kJB__Tk_OppChain, kJB__Tk_Expect, nil));
	JB_Tree_SyntaxAppend(rz, _tmPf0);
	JB_Decr(_tmPf0);
	JB_Tree_SyntaxAppend(rz, Parent);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fBAdjectiveThing(int Start, Message* Parent) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxBadj, Start, JB_LUB[0]));
	Message* _tmPf0 = JB_Incr(JB_Tk__ProcessThing(0, kJB__Tk_Expect));
	JB_Tree_SyntaxAppend(rz, _tmPf0);
	JB_Decr(_tmPf0);
	JB_Tree_SyntaxAppend(rz, Parent);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fBeforeRel(int Start, Message* Parent) {
	return JB_Tk__BeforeRelSub(Start, kJB__Tk_Allow);
}

Message* JB_Tk__fBeforeRelMinus(int Start, Message* Parent) {
	byte c = JB_Tk__Byte(Start + 1);
	if (JB_byte_IsInt(c) and (JB_Tk__Byte(Start) == '-')) {
		return JB_Tk__NumberSub(Start + 1, Start);
	}
	return JB_Tk__BeforeRelSub(Start, kJB__Tk_Allow);
}

Message* JB_Tk__fBinary(int Start, Message* Parent) {
	Ind End = JB_Str_InStr(JB__Tk_Data, JB_LUB[72], Start + 2, JB_int__max(), false);
	if (JB_Ind_SyntaxCast(End)) {
		JB_String* S = JB_Incr(JB_Tk__Range(Start + 2, End));
		(JB_Tk__NextStartSet(End + 2));
		JB_String* _tmPf0 = JB_Incr(JB_Str_UnHex(S, nil));
		JB_Decr(S);
		Message* _tmPf1 = JB_Incr(JB_Tk__NewParentName(nil, JB_SyxBin, Start, _tmPf0));
		JB_Decr(_tmPf0);
		JB_SafeDecr(_tmPf1);
		return _tmPf1;
	}
	return JB_Tk__ErrorAdd(JB_LUB[73], Start);
}

Message* JB_Tk__fBracket(int Start, Message* Parent) {
	Message* rz = nil;
	rz = JB_Tk__NewParentName(nil, JB_SyxList, Start, JB_LUB[0]);
	bool Lines = JB_Tk__ParseLoopFlags(rz, JB_LUB[74], kJB__Tk_TemporalSyxNoBar);
	if ((!Lines) and JB_Ring_HasChildCount(rz, 1)) {
		JB_Msg_BecomeStr(rz, JB_SyxBra, JB_LUB[0]);
	}
	return rz;
}

Message* JB_Tk__fChar(int Start, Message* Parent) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__fCharSub(Start, Start, '\''));
	if ((!(rz))) {
		JB_Decr(rz);
		return JB_Tk__ErrorAdd(JB_LUB[75], JB_Tk__NextStart());
	}
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fCharSub(int pos, int start, byte find) {
	Message* rz = nil;
	Ind After = JB_Str_JBFind(JB__Tk_Data, find, start + 1, JB_int__max());
	if ((!JB_Ind_SyntaxCast(After))) {
		JB_Decr(rz);
		return nil;
	}
	(JB_Tk__NextStartSet(After + 1));
	JB_String* _tmPf0 = JB_Incr(JB_Tk__Range(start + 1, After));
	JB_String* name = JB_Incr(JB_Str_Unescape(_tmPf0));
	JB_Decr(_tmPf0);
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxChar, pos, name));
	JB_Decr(name);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fComment(int Start, Message* Parent) {
	int Count = 1;
	Ind i = JB_Tk__NextStart();
	JB_String* d = JB_Incr(JB__Tk_Data);
	while (true) {
		i = JB_Str_FindByte(d, '/', i + 1, JB_int__max());
		if ((!JB_Ind_SyntaxCast(i))) {
			JB_Decr(d);
			return JB_Tk__ErrorAdd(JB_LUB[76], Start);
		}
		 else if (JB_Str_ByteValue(d, i - 1) == '*') {
			Count--;
		}
		 else if (JB_Str_ByteValue(d, i + 1) == '*') {
			Count++;
			i = (i + 2);
		}
		if ((!Count)) {
			break;
		}
	};
	JB_Decr(d);
	(JB_Tk__NextStartSet(i + 1));
	return JB__Tk_EndOfLineMarker;
}

Message* JB_Tk__fCommentLine(int Start, Message* Parent) {
	(JB_Tk__NextStartSet(JB_Str_Find(JB__Tk_Data, JB__Constants_CSLine, JB_Tk__NextStart(), JB_int__max())));
	return JB__Tk_EndOfLineMarker;
}

Message* JB_Tk__fDecl(int Start, Message* Parent) {
	Message* Result = JB_Incr(JB_Tk__BarThings(Start, JB_SyxDecl));
	if (((bool)Result) and (!JB_Tk__WillEnd())) {
		Message* Curr = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_OppSyx | kJB__Tk_OppTemporal, false));
		if (Curr) {
			JB_Tree_SyntaxAppend(Result, Curr);
		}
		JB_Decr(Curr);
	}
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fDot(int Start, Message* Parent) {
	Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_Parent(Parent)));
	Message* _tmPf1 = JB_Incr(JB_Tk__DotSub(JB_SyxDot, Start, _tmPf0));
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Message* JB_Tk__fDotAccess(int Start, Message* Parent) {
	Message* rz = nil;
	int n = JB_Tk__NextStart();
	Message* name = JB_Tk__NewWord(nil, JB_SyxStr, n, n);
	if ((!name)) {
		return nil;
	}
	int after = JB_Tk__NextStart();
	JB_SetRef(name->Name, JB_Str_ReplaceAll(name->Name, JB_LUB[77], JB_LUB[78], false, nil));
	rz = JB_Tk__NewEmpty(nil, JB_SyxAcc, Start, after);
	Message* prms = JB_Tk__NewEmpty(rz, JB_SyxArr, Start, Start);
	JB_Tree_SyntaxAppend(prms, name);
	return rz;
}

Message* JB_Tk__fEndOfLine(int Start, Message* Parent) {
	return JB__Tk_EndOfLineMarker;
}

Message* JB_Tk__fError(int Start, Message* Parent) {
	return nil;
}

Message* JB_Tk__fError2(int Start, Message* Parent) {
	return JB_Tk__ErrorAdd(JB_LUB[79], Start);
}

Message* JB_Tk__fFuncCall(int Start, Message* Parent) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxFunc, Parent->Position, JB_LUB[0]));
	JB_Tk__Params(rz, Start);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__FillXML(Message* XML, Ind i) {
	JB_String* s = JB_Incr(JB__Tk_Data);
	if (JB_Str_ByteValue(s, i - 1) == '/') {
		(JB_Tk__NextStartSet(i + 1));
		JB_Decr(s);
		return XML;
	}
	(JB_Tk__NextStartSet(i));
	while (true) {
		int Prev = JB_Tk__NextStart();
		i = JB_Str_FindByte(s, '<', Prev, JB_int__max());
		if ((!(JB_Ind_SyntaxCast(i)))) {
			JB_Decr(s);
			return JB_Tk__ErrorAdd(JB_LUB[80], XML->Position);
		}
		JB_Tk__AddXMLText(XML, s, Prev, i);
		(JB_Tk__NextStartSet(i));
		byte next = JB_Str_ByteValue(s, i + 1);
		if (next == '/') {
			Message* _tmPf3 = JB_Incr(JB_Tk__CloseXML(XML, i, s));
			JB_Decr(s);
			JB_SafeDecr(_tmPf3);
			return _tmPf3;
		}
		if (next != '!') {
			Message* _tmPf0 = JB_Incr(JB_Tk__fXML(i, nil));
			if ((!_tmPf0)) {
				JB_Decr(s);
				JB_Decr(_tmPf0);
				return nil;
			}
			JB_Tree_SyntaxAppend(XML, _tmPf0);
			JB_Decr(_tmPf0);
		}
		 else if (JB_Str_MidEquals(s, i, JB_LUB[81], false)) {
			Message* _tmPf1 = JB_Incr(JB_Tk__XMLWhatever(i, 4, JB_LUB[82], JB_SyxXCom));
			if ((!_tmPf1)) {
				JB_Decr(s);
				JB_Decr(_tmPf1);
				return nil;
			}
			JB_Tree_SyntaxAppend(XML, _tmPf1);
			JB_Decr(_tmPf1);
		}
		 else if (JB_Str_MidEquals(s, i, JB_LUB[83], false)) {
			Message* _tmPf2 = JB_Incr(JB_Tk__XMLWhatever(i, 9, JB_LUB[84], JB_SyxXCDT));
			if ((!_tmPf2)) {
				JB_Decr(s);
				JB_Decr(_tmPf2);
				return nil;
			}
			JB_Tree_SyntaxAppend(XML, _tmPf2);
			JB_Decr(_tmPf2);
		}
		 else {
			JB_Decr(s);
			return JB_Tk__ErrorAdd(JB_LUB[0], i);
		}
	};
	JB_Decr(s);
	return nil;
}

int JB_Tk__FindError(int num) {
	if (num == kJB__Tk_Thing) {
		return kJB__Tk_Thing;
	}
	{
		DictionaryReader* _navf0 = JB_Incr(JB_Dict_Navigate(JB__Tk_ErrorNames));
		while (JB_Nav_MoveNext(_navf0)) {
			JB_String* Key = JB_Incr(JB_Nav_Name(_navf0));
			int i = ((int)JB_Str_TextIntegerValid(Key, nil));
			JB_Decr(Key);
			if ((num & i) == i) {
				JB_Decr(_navf0);
				return i;
			}
		};
		JB_Decr(_navf0);
	}
	;
	return 0;
}

Message* JB_Tk__fInnerNiceAdj(int Start, Message* Parent) {
	return JB_Tk__fAskSub(Start, Parent, JB_Syxbinn);
}

Message* JB_Tk__FixTRels(Message* self, Message* Last) {
	if ((!Last)) {
		0;
	}
	 else if ((!JB_Msg_EqualsSyx(Last, JB_SyxTRel, false))) {
		JB_Tree_SyntaxAppend(self, Last);
	}
	 else {
		Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_First(Last)));
		JB_Tree_SyntaxAppend(self, _tmPf0);
		JB_Decr(_tmPf0);
		(JB_Ring_FirstSet(Last, self));
		self = Last;
	}
	return self;
}

Message* JB_Tk__fMsgList(int Start, Message* Parent) {
	Message* Result = JB_Incr(JB_Tk__NewParentName(nil, JB_SyxMsg, Start, JB_LUB[0]));
	Message* name = JB_Incr(JB_Tk__Process(kJB__Tk_TemporalWord, true, Result));
	if ((!name)) {
		JB_Decr(Result);
		JB_Decr(name);
		return nil;
	}
	Message* it = JB_Incr(((Message*)JB_Tree_Second(name)));
	JB_Decr(name);
	if (it) {
		JB_Decr(Result);
		Message* _tmPf0 = JB_Incr(JB_Tk__UnexpectedSyntax(it));
		JB_Decr(it);
		JB_SafeDecr(_tmPf0);
		return _tmPf0;
	}
	JB_Decr(it);
	int Ops = kJB__Tk_OppSyx | (kJB__Tk_OppTemporal | kJB__Tk_OppYoda);
	while (JB_Tk__NextLineAndIndent(Result).Lines) {
		Message* item = JB_Incr(JB_Tk__ProcessThing(Ops, false));
		if ((!item)) {
			JB_Decr(item);
			break;
		}
		if (JB_Str_OperatorEndsWith(item->Name, JB_LUB[85])) {
			JB_Decr(Result);
			Message* _tmPf1 = JB_Incr(JB_Tk__ErrorAdd(JB_LUB[86], item->Position));
			JB_Decr(item);
			JB_SafeDecr(_tmPf1);
			return _tmPf1;
		}
		JB_Tree_SyntaxAppend(Result, item);
		JB_Decr(item);
	};
	JB_Tk__ExpectEndChar(Start, JB_LUB[85], true);
	(JB_Msg_AfterSet(Result, JB_Tk__NextStart()));
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fNumber(int Start, Message* Parent) {
	return JB_Tk__NumberSub(Start, Start);
}

Message* JB_Tk__fOpAsThing(int Start, Message* Parent) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxOat, Start, JB_LUB[0]));
	Message* _tmPf0 = JB_Incr(JB_Tk__Process(kJB__Tk_Opp, false, nil));
	JB_Tree_SyntaxAppend(rz, _tmPf0);
	JB_Decr(_tmPf0);
	Message* _tmPf1 = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_Opp, false));
	JB_Tree_SyntaxAppend(rz, _tmPf1);
	JB_Decr(_tmPf1);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fOppBracket(int Start, Message* Parent) {
	Message* result = JB_Incr(JB_Tk__NewParentName(nil, JB_SyxBra, Start, JB_LUB[0]));
	Message* opp1 = JB_Incr(JB_Tk__Process(kJB__Tk_OppChain, false, nil));
	Message* opp2 = JB_Incr(JB_Tk__Process(kJB__Tk_Opp, false, nil));
	if ((!opp2)) {
		JB_Tree_SyntaxAppend(result, opp1);
	}
	 else {
		Message* rel = JB_Incr(JB_Tk__NewParentName(result, JB_SyxRel, JB_Tk__NextStart() - 1, JB_LUB[0]));
		JB_Tree_SyntaxAppend(rel, opp1);
		JB_Tree_SyntaxAppend(rel, opp2);
		Message* _tmPf0 = JB_Incr(JB_Tk__Process(kJB__Tk_OppChain, false, nil));
		JB_Tree_SyntaxAppend(rel, _tmPf0);
		JB_Decr(_tmPf0);
		JB_Decr(rel);
	}
	JB_Decr(opp2);
	JB_Decr(opp1);
	JB_Tk__ExpectEndChar(Start, JB_LUB[74], true);
	Message* _tmPf1 = JB_Incr(JB_Tk__OppChain(result));
	JB_Decr(result);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Message* JB_Tk__fOppSyx(int Start, Message* Parent) {
	return JB_Tk__NewParent(nil, JB_SyxOpp, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fOppSyxNeq(int Start, Message* Parent) {
	Message* result = JB_Incr(JB_Tk__fOppSyx(Start, nil));
	if ('=' == JB_Tk__NextByte()) {
		JB_Decr(result);
		return JB_Tk__ErrorAdd(JB_LUB[87], JB_Tk__NextStart());
	}
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fOppWord(int Start, Message* Parent) {
	int After = JB_Tk__WordAfter(Start);
	if (JB_Tk__Byte(After) != '.') {
		Message* opp = JB_Incr(JB_Tk__NewParent(nil, JB_SyxOpp, Start, After));
		Message* _tmPf0 = JB_Incr(JB_Tk__OppChain(opp));
		JB_Decr(opp);
		JB_SafeDecr(_tmPf0);
		return _tmPf0;
	}
	return nil;
}

Message* JB_Tk__fQuestion(int Start, Message* Parent) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxQues, Start, JB_LUB[0]));
	JB_FreeIfDead(JB_Tk__NewWord(rz, JB_SyxThg, Start, JB_Tk__NextStart()));
	Message* _tmPf0 = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_Opp, false));
	JB_Tree_SyntaxAppend(rz, _tmPf0);
	JB_Decr(_tmPf0);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fQuoteLang(int Start, Message* Parent) {
	Message* rz = nil;
	rz = JB_Tk__NewParentName(nil, JB_SyxQuot, Start, JB_LUB[0]);
	JB_Tk__ParseLoopFlags(rz, JB_LUB[88], kJB__Tk_TemporalSyxNoBar);
	return rz;
}

Message* JB_Tk__fSDot(int Start, Message* Parent) {
	if (Start > 0) {
		byte c = JB_Tk__Byte(Start - 1);
		if (JB_CS_HasChar(JB__Constants_CSWordMiddle, c)) {
			return nil;
		}
	}
	return JB_Tk__DotSub(JB_SyxSDot, Start, Parent);
}

Message* JB_Tk__fShebang(int Start, Message* Parent) {
	Ind S = JB_Tk__NextStart();
	Ind S2 = JB_Str_Find(JB__Tk_Data, JB__Constants_CSLine, S, JB_int__max());
	(JB_Tk__NextStartSet(S2));
	return JB_Tk__NewSkip(Parent, JB_SyxSheb, Start, S, S2);
}

Message* JB_Tk__fStatement(int Start, Message* Parent) {
	Message* tmp = JB_Incr(JB_Tk__fTmp(Start, kJB__Tk_Opp & (~kJB__Tk_OppBra), kJB__Tk_Thing, Parent));
	if ((!JB_Msg_EqualsSyx(tmp, JB_SyxThg, false))) {
		JB_SafeDecr(tmp);
		return tmp;
	}
	JB_Tree_Remove(tmp);
	JB_Decr(tmp);
	(JB_Tk__NextStartSet(Start));
	return JB_Tk__ProcessThing(kJB__Tk_Opp, false);
}

Message* JB_Tk__fStatementColon(int Start, Message* Parent) {
	return JB_Tk__fTmp(Start, kJB__Tk_Opp & (~kJB__Tk_OppBra), kJB__Tk_Thing | kJB__Tk_colonarg, Parent);
}

Message* JB_Tk__fString(int Start, Message* Parent) {
	Ind After = JB_Str_JBFind(JB__Tk_Data, '"', (JB_Tk__NextStart()), JB_int__max());
	if ((!(JB_Ind_SyntaxCast(After)))) {
		return JB_Tk__ErrorAdd(JB_LUB[89], JB_Tk__NextStart());
	}
	Ind StrPos = Start + 1;
	Message* result = JB_Incr(JB_Tk__NewParentName(nil, JB_SyxStr, Start, JB_LUB[0]));
	while (JB_Ind_SyntaxCast(StrPos)) {
		Ind NewStrPos = JB_Str_JBFind(JB__Tk_Data, '$', StrPos, After);
		if ((!JB_Ind_SyntaxCast(NewStrPos))) {
			NewStrPos = After;
		}
		if (NewStrPos > StrPos) {
			Message* Str = JB_Incr(JB_Tk__NewParent(result, JB_SyxEmb, StrPos, NewStrPos));
			JB_SetRef(Str->Name, JB_Str_Unescape(Str->Name));
			JB_Decr(Str);
		}
		if (NewStrPos >= After) {
			break;
		}
		NewStrPos++;
		byte C0 = JB_Tk__Byte(NewStrPos);
		if (C0 == '{') {
			NewStrPos++;
		}
		(JB_Tk__NextStartSet(NewStrPos));
		if (C0 == '{') {
			StrPos = JB_Tk__EmbeddedCode(JB_LUB[70], result, kJB__Tk_TemporalSyx);
		}
		 else {
			Syntax type = JB_SyxThg;
			if (C0 == '.') {
				type = JB_SyxSDot;
				NewStrPos++;
			}
			StrPos = JB_Str_OutCharSet(JB__Tk_Data, JB__Constants_CSWordMiddle, NewStrPos + 1, After);
			if ((!(JB_Ind_SyntaxCast(StrPos)))) {
				StrPos = After;
			}
			Message* rr = JB_Incr(JB_Tk__NewParent(result, type, NewStrPos, StrPos));
			if (C0 == '.') {
				JB_FreeIfDead(JB_Tk__NewParentName(rr, JB_SyxEmb, NewStrPos - 1, JB_LUB[0]));
			}
			JB_Decr(rr);
		}
		if (StrPos > After) {
			JB_Decr(result);
			return JB_Tk__ErrorAdd(JB_LUB[90], NewStrPos);
		}
	};
	(JB_Tk__NextStartSet((++After)));
	result->Extra = ((After - Start) | JB__Tk_BaseExtra);
	JB_Msg_UnEmbed(result);
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fSuperStr(int Start, Message* Parent) {
	JB_String* d = JB__Tk_Data;
	int Nest = 1;
	while (true) {
		Ind After = JB_Str_FindByte(d, '`', JB_Tk__NextStart(), JB_int__max());
		if ((!JB_Ind_SyntaxCast(After))) {
			break;
		}
		(JB_Tk__NextStartSet(After + 3));
		if (JB_Str_MidEquals(d, After - 2, JB_LUB[91], false)) {
			Nest++;
		}
		 else if (JB_Str_MidEquals(d, After, JB_LUB[92], false)) {
			Nest--;
			if ((!Nest)) {
				return JB_Tk__NewSkip(nil, JB_SyxSStr, Start, Start + 3, After);
			}
		}
	};
	return JB_Tk__ErrorAdd(JB_LUB[71], Start);
}

Message* JB_Tk__fSyntacticComment(int Start, Message* Parent) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxSCom, Start, JB_LUB[0]));
	JB_Tk__EmbeddedArg(JB_LUB[93], rz, kJB__Tk_TemporalSyx);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fTemporalHashThing(int Start, Message* Parent) {
	Message* Result = JB_Incr(JB_Tk__NewParentName(Parent, JB_SyxTril, Start, JB_LUB[0]));
	Ind S = JB_Tk__NextStart();
	JB_FreeIfDead(JB_Tk__NewParent(Result, JB_SyxCnj, S, JB_Tk__WordAfter(S)));
	Message* x = JB_Incr(JB_Tk__ProcessThingOrTmp(kJB__Tk_Opp & (~kJB__Tk_OppBra)));
	if (x) {
		JB_Tree_SyntaxAppend(Result, x);
		Message* _tmPf0 = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_Opp, false));
		JB_Tree_SyntaxAppend(Result, _tmPf0);
		JB_Decr(_tmPf0);
	}
	JB_Decr(x);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fTemporalRel(int Start, Message* Parent) {
	return JB_Tk__NewWord(nil, JB_SyxCnj, Start, JB_Tk__CleanSpaces());
}

Message* JB_Tk__fTemporalRelSyx(int Start, Message* Parent) {
	return JB_Tk__NewParent(nil, JB_SyxSCnj, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fThingSyx(int Start, Message* Parent) {
	return JB_Tk__NewParent(nil, JB_SyxSThg, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fThingWord(int Start, Message* Parent) {
	int name = JB_Tk__WordAfter(Start);
	return JB_Tk__NewParent(nil, JB_SyxThg, Start, name);
}

Message* JB_Tk__fTmp(int Start, int OpFlags, int ThingFlags, Message* parent) {
	Message* Result = JB_Tk__NewWord(parent, JB_SyxTmp, Start, Start);
	return JB_Tk__fTmpSub(Result, OpFlags, ThingFlags);
}

Message* JB_Tk__fTmpPlus(int Start, Message* Parent) {
	if (JB_Tk__NextByte() == '"') {
		Message* tmp = JB_Tk__fCharSub(Start, Start + 1, '"');
		if (tmp) {
			tmp->Func = JB_SyxTmp;
			tmp = JB_Tk__fTmpSub(tmp, kJB__Tk_Opp & (~kJB__Tk_OppBra), kJB__Tk_Thing);
			if ((!JB_Msg_EqualsSyx(tmp, JB_SyxThg, false))) {
				return tmp;
			}
		}
	}
	return JB_Tk__fError2(Start, nil);
}

Message* JB_Tk__fTmpSub(Message* result, int OpFlags, int ThingFlags) {
	JB_Incr(result);
	if (JB_Tk__WillEnd()) {
		JB_SafeDecr(result);
		return result;
	}
	if (JB_Tk__CanStatement()) {
		while (true) {
			Message* item = JB_Incr(JB_Tk__ProcessThingParent(result, OpFlags, ThingFlags));
			if ((!item)) {
				JB_Decr(item);
				break;
			}
			JB_Tree_SyntaxAppend(result, item);
			if (JB_Tk__WillEnd()) {
				JB_Decr(item);
				JB_SafeDecr(result);
				return result;
			}
			if (JB_Msg_EqualsSyx(item, JB_SyxArg, false)) {
				Message* _tmPf0 = JB_Incr(JB_Tk__UnTmpPlace(result));
				Message* SubTmp = JB_Incr(JB_Tk__Process(kJB__Tk_temporalwordcolon, false, _tmPf0));
				JB_Decr(_tmPf0);
				if (((bool)SubTmp) or (JB_Msg_SyntaxEquals(item, JB_LUB[94], false))) {
					JB_Decr(item);
					JB_Decr(SubTmp);
					JB_SafeDecr(result);
					return result;
				}
				JB_Decr(SubTmp);
			}
			JB_Decr(item);
			ThingFlags = (ThingFlags | kJB__Tk_colonarg);
		};
	}
	result->Func = JB_SyxThg;
	if (JB_Ring_HasChildren(result)) {
		JB_SafeDecr(result);
		return result;
	}
	JB_SetRef(result, JB_Tk__DecorateThing(result, kJB__Tk_Opp));
	Message* _tmPf1 = JB_Incr(JB_Tk__ParseItem(result, kJB__Tk_TemporalSyx, kJB__Tk_Opp));
	JB_Decr(result);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Message* JB_Tk__fTypeCast(int Start, Message* Parent) {
	Message* _tmPf0 = JB_Incr(JB_Tk__BarThings(Start, JB_SyxType));
	if ((!_tmPf0)) {
		JB_Decr(_tmPf0);
		return nil;
	}
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

Message* JB_Tk__fURL(int Start, Message* Parent) {
	if ((!JB_Tk__NeedName(Parent))) {
		return nil;
	}
	(JB_Tk__NextStartSet(JB_Str_InWhite(JB__Tk_Data, Start, JB_int__max())));
	Parent->Func = JB_Syxurl;
	Parent->Extra = (Parent->Extra + 3);
	Message* _tmPf0 = JB_Incr(JB_Tk__NewParent(nil, JB_SyxStr, Start + 3, JB_Tk__NextStart()));
	JB_Tree_SyntaxAppend(Parent, _tmPf0);
	JB_Decr(_tmPf0);
	return Parent;
}

Message* JB_Tk__fXML(int Start, Message* Parent) {
	Message* rz = nil;
	Message* XML = JB_Incr(JB_Tk__NewWord(nil, JB_SyxXML, Start, Start + 1));
	int endpos = Start + (1 + JB_Msg_Length(XML));
	endpos = JB_Tk__XMLAttribs(XML, endpos);
	if ((!endpos)) {
		JB_Decr(rz);
		JB_Decr(XML);
		return nil;
	}
	JB_SetRef(rz, JB_Tk__FillXML(XML, endpos + 1));
	JB_Decr(XML);
	if (rz) {
		(JB_Msg_AfterSet(rz, JB_Tk__NextStart()));
	}
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fXML_Comment(int Start, Message* Parent) {
	return JB_Tk__XMLWhatever(Start, 4, JB_LUB[82], JB_SyxXCom);
}

Message* JB_Tk__fXML_DocType(int Start, Message* Parent) {
	{
		IntRange _LoopSrcf0 = JB_int_OperatorTo(JB_Tk__NextStart(), JB_Str_Length(JB__Tk_Data) - 1);
		while (_LoopSrcf0[0] < _LoopSrcf0[1]) {
			int i = _LoopSrcf0[0];
			byte c = JB_Str_ByteValue(JB__Tk_Data, i);
			if (c == '[') {
				i = JB_Str_FindByte(JB__Tk_Data, ']', i, JB_int__max());
				if ((!(i))) {
					return JB_Tk__ErrorAdd(JB_LUB[95], Start);
				}
			}
			 else if (c == '>') {
				(JB_Tk__NextStartSet(i + 1));
				JB_String* _tmPf2 = JB_Incr(JB_Str_Range(JB__Tk_Data, Start + 9, i));
				Message* _tmPf3 = JB_Incr(JB_Tk__NewParentName(nil, JB_SyxXCom, Start, _tmPf2));
				JB_Decr(_tmPf2);
				JB_SafeDecr(_tmPf3);
				return _tmPf3;
			}
			_LoopSrcf0[0] = (_LoopSrcf0[0] + 1);
		};
	}
	;
	return nil;
}

Message* JB_Tk__fXML_PI(int Start, Message* Parent) {
	Message* rz = nil;
	JB_SetRef(rz, JB_Tk__NewParentName(nil, JB_SyxXPI, Start, JB_LUB[0]));
	JB_Tk__ParseLoopFlags(rz, JB_LUB[96], kJB__Tk_Temporal);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_Tk__fYoda(int Start, Message* Parent) {
	Message* last = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_OppSyx, true));
	Message* first = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_OppSyx, true));
	Message* opp = JB_Incr(JB_Tk__Process(kJB__Tk_Opp, true, nil));
	Message* rel = JB_Incr(JB_Tk__NewParentName(Parent, JB_SyxYoda, Start, JB_LUB[0]));
	JB_Tree_SyntaxAppend(rel, first);
	JB_Decr(first);
	JB_Tree_SyntaxAppend(rel, opp);
	JB_Decr(opp);
	JB_Tree_SyntaxAppend(rel, last);
	JB_Decr(last);
	JB_SafeDecr(rel);
	return rel;
}

Message* JB_Tk__GetFuncAfter(Message* result) {
	JB_Incr(result);
	while (true) {
		int ThisAfter = kJB__Tk_FuncAfterAny & (~JB__Tk_StopBars);
		if (JB_Tk__NoFuncAfter(JB_Tk__NextByte())) {
			ThisAfter = (ThisAfter & (~kJB__Tk_FuncAfterNoSpace));
		}
		Message* d = JB_Incr(JB_Tk__Process(ThisAfter, false, result));
		if ((!d)) {
			JB_Decr(d);
			break;
		}
		Syntax fn = d->Func;
		if ((fn != JB_SyxName) and ((fn != JB_SyxBadj) and (fn != JB_Syxurl))) {
			(JB_Ring_PrevSibSet(result, d));
			(JB_Ring_FirstSet(d, result));
		}
		JB_SetRef(result, d);
		JB_Decr(d);
	};
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__IndentBug(Message* curr) {
	JB_DoAt(1);
	return JB_Tk__ErrorAlwaysAdd(JB_LUB[97], curr->Position);
}

void JB_Tk__Init() {
	if ((!(JB_Syx_Translateable(JB_SyxThg) and (JB_Syx_Translateable(JB_SyxOpp) and (JB_Syx_Translateable(JB_SyxCnj) and (JB_Syx_Translateable(JB_SyxTmp) and JB_Syx_Translateable(JB_SyxName))))))) {
		debugger;
	}
	JB_Tk__TokenzFn(JB_LUB[98], kJB__Tk_EndOfLine, JB_Tk__fEndOfLine);
	TokHan* _tmPf1 = JB_Incr(JB_Tk__Handler(kJB__Tk_Comma | kJB__Tk_EndOfLine, ((TokenHandler_fp)JB_Tk__fEndOfLine)));
	(JB_Tk__TokenSet(JB_LUB[99], _tmPf1));
	JB_Decr(_tmPf1);
	TokHan* _tmPf3 = JB_Incr(JB_Tk__Handler(kJB__Tk_colon, ((TokenHandler_fp)JB_Tk__fEndOfLine)));
	TokHan* _tmPf2 = JB_Incr(JB_TH_Link(_tmPf3, kJB__Tk_colonarg, ((TokenHandler_fp)JB_Tk__fArgColon)));
	JB_Decr(_tmPf3);
	(JB_Tk__TokenSet(JB_LUB[94], _tmPf2));
	JB_Decr(_tmPf2);
	JB_SetRef(JB__Tk_EndOfLineMarker, JB_Msg__NewNormal(nil, JB_LUB[100]));
	Array* numb = JB_Incr(JB_Str_ByteSplit(JB_LUB[101]));
	JB_String* op_comp = JB_Incr(JB_LUB[102]);
	JB_String* op_math = JB_Incr(JB_LUB[103]);
	JB_String* PFix = JB_Incr(JB_LUB[104]);
	TokHan* _tmPf6 = JB_Incr(JB_Tk__Handler(kJB__Tk_ThingWord, ((TokenHandler_fp)JB_Tk__fThingWord)));
	TokHan* _tmPf5 = JB_Incr(JB_TH_Link(_tmPf6, kJB__Tk_TemporalWord, ((TokenHandler_fp)JB_Tk__fStatement)));
	JB_Decr(_tmPf6);
	TokHan* _tmPf4 = JB_Incr(JB_TH_Link(_tmPf5, kJB__Tk_temporalwordcolon, ((TokenHandler_fp)JB_Tk__fStatementColon)));
	JB_Decr(_tmPf5);
	TokHan* H = JB_Incr(JB_TH_Link(_tmPf4, kJB__Tk_OppWord, ((TokenHandler_fp)JB_Tk__fOppWord)));
	JB_Decr(_tmPf4);
	Array* _tmPf7 = JB_Incr(JB_CS_Bytes(JB__Constants_CSWordStart));
	JB_Tk__TokensHan(_tmPf7, H);
	JB_Decr(_tmPf7);
	JB_Decr(H);
	TokHan* _tmPf10 = JB_Incr(JB_Tk__Handler(kJB__Tk_FuncAfterNoSpace, ((TokenHandler_fp)JB_Tk__fFuncCall)));
	TokHan* _tmPf9 = JB_Incr(JB_TH_Link(_tmPf10, kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fBracket)));
	JB_Decr(_tmPf10);
	TokHan* _tmPf8 = JB_Incr(JB_TH_Link(_tmPf9, kJB__Tk_OppBra, ((TokenHandler_fp)JB_Tk__fOppBracket)));
	JB_Decr(_tmPf9);
	(JB_Tk__TokenSet(JB_LUB[57], _tmPf8));
	JB_Decr(_tmPf8);
	TokHan* _tmPf12 = JB_Incr(JB_Tk__Handler(kJB__Tk_FuncAfterNoSpace, ((TokenHandler_fp)JB_Tk__fAccess)));
	TokHan* _tmPf11 = JB_Incr(JB_TH_Link(_tmPf12, kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fArray)));
	JB_Decr(_tmPf12);
	(JB_Tk__TokenSet(JB_LUB[105], _tmPf11));
	JB_Decr(_tmPf11);
	TokHan* _tmPf13 = JB_Incr(JB_Tk__Handler(kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fMsgList)));
	(JB_Tk__TokenSet(JB_LUB[106], _tmPf13));
	JB_Decr(_tmPf13);
	TokHan* _tmPf15 = JB_Incr(JB_Tk__Handler(kJB__Tk_FuncAfterNoSpace, ((TokenHandler_fp)JB_Tk__fDot)));
	TokHan* _tmPf14 = JB_Incr(JB_TH_Link(_tmPf15, kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fSDot)));
	JB_Decr(_tmPf15);
	(JB_Tk__TokenSet(JB_LUB[107], _tmPf14));
	JB_Decr(_tmPf14);
	TokHan* _tmPf16 = JB_Incr(JB_Tk__Handler(kJB__Tk_FuncAfterNoSpace, ((TokenHandler_fp)JB_Tk__fDotAccess)));
	(JB_Tk__TokenSet(JB_LUB[108], _tmPf16));
	JB_Decr(_tmPf16);
	TokHan* _tmPf17 = JB_Incr(JB_Tk__Handler(kJB__Tk_FuncAfterNoSpace, ((TokenHandler_fp)JB_Tk__fURL)));
	(JB_Tk__TokenSet(JB_LUB[109], _tmPf17));
	JB_Decr(_tmPf17);
	TokHan* _tmPf20 = JB_Incr(JB_Tk__Handler(kJB__Tk_TemporalBar, ((TokenHandler_fp)JB_Tk__fDecl)));
	TokHan* _tmPf19 = JB_Incr(JB_TH_Link(_tmPf20, kJB__Tk_FuncAfterBar, ((TokenHandler_fp)JB_Tk__fTypeCast)));
	JB_Decr(_tmPf20);
	TokHan* _tmPf18 = JB_Incr(JB_TH_Link(_tmPf19, kJB__Tk_ThingBar, ((TokenHandler_fp)JB_Tk__fDecl)));
	JB_Decr(_tmPf19);
	(JB_Tk__TokenSet(JB_LUB[52], _tmPf18));
	JB_Decr(_tmPf18);
	TokHan* _tmPf21 = JB_Incr(JB_Tk__Handler(kJB__Tk_TemporalSyx, ((TokenHandler_fp)JB_Tk__fTmpPlus)));
	(JB_Tk__TokenSet(JB_LUB[110], _tmPf21));
	JB_Decr(_tmPf21);
	TokHan* _tmPf23 = JB_Incr(JB_Tk__Handler(kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fAtName)));
	TokHan* _tmPf22 = JB_Incr(JB_TH_Link(_tmPf23, kJB__Tk_FuncAfterNormal, ((TokenHandler_fp)JB_Tk__fAtNamedExp)));
	JB_Decr(_tmPf23);
	(JB_Tk__TokenSet(JB_LUB[111], _tmPf22));
	JB_Decr(_tmPf22);
	TokHan* _tmPf25 = JB_Incr(JB_Tk__Handler(kJB__Tk_FuncAfterNormal, ((TokenHandler_fp)JB_Tk__fAdjectiveThing)));
	TokHan* _tmPf24 = JB_Incr(JB_TH_Link(_tmPf25, kJB__Tk_adjectiveop, ((TokenHandler_fp)JB_Tk__fAdjectiveOp)));
	JB_Decr(_tmPf25);
	(JB_Tk__TokenSet(JB_LUB[112], _tmPf24));
	JB_Decr(_tmPf24);
	JB_Tk__TokenzFn(JB_LUB[113], kJB__Tk_ThingSyx, JB_Tk__fBeforeRelMinus);
	JB_Tk__TokenzFn(PFix, kJB__Tk_ThingSyx, JB_Tk__fBeforeRel);
	JB_Tk__TokenzFn(PFix, kJB__Tk_FuncAfterNormal, JB_Tk__fAfterRel);
	JB_Decr(PFix);
	JB_Tk__TokenzFn(JB_LUB[22], kJB__Tk_ThingSyx, JB_Tk__fBeforeRel);
	JB_Tk__TokenzFn(JB_LUB[114], kJB__Tk_ThingSyx, JB_Tk__fArgOpen);
	JB_Tk__TokenzFn(JB_LUB[115], kJB__Tk_TmpOpp, JB_Tk__fTemporalRelSyx);
	JB_Tk__TokenzFn(JB_LUB[116], kJB__Tk_TmpOpp, JB_Tk__fSyntacticComment);
	JB_Tk__TokenzFn(JB_LUB[117], kJB__Tk_ThingSyx, JB_Tk__fOpAsThing);
	JB_Tk__TokensFn(numb, kJB__Tk_ThingSyx, JB_Tk__fNumber);
	JB_Decr(numb);
	JB_Tk__TokenzFn(JB_LUB[118], kJB__Tk_TemporalSyxNoBar, JB_Tk__fShebang);
	JB_Tk__TokenzFn(JB_LUB[119], kJB__Tk_EndOfLine, JB_Tk__fCommentLine);
	JB_Tk__TokenzFn(JB_LUB[120], kJB__Tk_EndOfLine, JB_Tk__fComment);
	JB_Tk__TokenzFn(op_comp, kJB__Tk_OppSNB, JB_Tk__fOppSyxNeq);
	JB_Decr(op_comp);
	JB_Tk__TokenzFn(op_math, kJB__Tk_OppSNB, JB_Tk__fOppSyx);
	JB_Decr(op_math);
	JB_Tk__TokenzFn(JB_LUB[52], kJB__Tk_OppBar, JB_Tk__fOppSyx);
	JB_Tk__TokenzFn(JB_LUB[121], kJB__Tk_ThingSyx, JB_Tk__fThingSyx);
	JB_Tk__TokenzFn(JB_LUB[14], kJB__Tk_ThingSyx, JB_Tk__fString);
	JB_Tk__TokenzFn(JB_LUB[16], kJB__Tk_ThingSyx, JB_Tk__fChar);
	JB_Tk__TokenzFn(JB_LUB[122], kJB__Tk_ThingSyx, JB_Tk__fBackTick);
	JB_Tk__TokenzFn(JB_LUB[91], kJB__Tk_ThingSyx, JB_Tk__fSuperStr);
	JB_Tk__TokenzFn(JB_LUB[123], kJB__Tk_ThingSyx, JB_Tk__fBinary);
	TokHan* _tmPf27 = JB_Incr(JB_Tk__Handler(kJB__Tk_FuncAfterNormal, ((TokenHandler_fp)JB_Tk__fBAdjectiveThing)));
	TokHan* _tmPf26 = JB_Incr(JB_TH_Link(_tmPf27, kJB__Tk_adjectiveop, ((TokenHandler_fp)JB_Tk__fBAdjectiveOp)));
	JB_Decr(_tmPf27);
	(JB_Tk__TokenSet(JB_LUB[124], _tmPf26));
	JB_Decr(_tmPf26);
	TokHan* _tmPf29 = JB_Incr(JB_Tk__Handler(kJB__Tk_TmpOpp, ((TokenHandler_fp)JB_Tk__fTemporalRel)));
	TokHan* _tmPf28 = JB_Incr(JB_TH_Link(_tmPf29, kJB__Tk_TemporalSyxNoBar, ((TokenHandler_fp)JB_Tk__fTemporalHashThing)));
	JB_Decr(_tmPf29);
	(JB_Tk__TokenSet(JB_LUB[125], _tmPf28));
	JB_Decr(_tmPf28);
	JB_Tk__TokenzFn(JB_LUB[126], kJB__Tk_ThingSyx, JB_Tk__fInnerNiceAdj);
	JB_Tk__TokenzFn(JB_LUB[127], kJB__Tk_ThingSyx, JB_Tk__fYoda);
	JB_Tk__TokenzFn(JB_LUB[128], kJB__Tk_ThingSyx, JB_Tk__fQuoteLang);
	JB_Tk__TokenzFn(JB_LUB[77], kJB__Tk_ThingSyx, JB_Tk__fQuestion);
	JB_Tk__TokenzFn(JB_LUB[129], kJB__Tk_ThingSyx, JB_Tk__fAsk);
	JB_Tk__TokenzFn(JB_LUB[26], kJB__Tk_TemporalSyx, JB_Tk__fXML);
	JB_Tk__TokenzFn(JB_LUB[130], kJB__Tk_TemporalSyx, JB_Tk__fXML_PI);
	JB_Tk__TokenzFn(JB_LUB[81], kJB__Tk_TemporalSyx, JB_Tk__fXML_Comment);
	JB_Tk__TokenzFn(JB_LUB[131], kJB__Tk_TemporalSyx, JB_Tk__fXML_DocType);
	JB_Tk__TokenzFn(JB_LUB[132], kJB__Tk_EndContainer, JB_Tk__fEndOfLine);
	JB_Tk__TokenzFn(JB_LUB[133], kJB__Tk_ThingSyx, JB_Tk__fError);
	JB_Tk__TokenzFn(JB_LUB[134], kJB__Tk_OppSyx, JB_Tk__fError2);
	TokHan* IllegalHandler = JB_Incr(JB_Tk__Handler(-1, ((TokenHandler_fp)JB_Tk__fError)));
	{
		int i = 0;
		while (i < 256) {
			JB_String* _tmPf30 = JB_Incr(JB_Str__SyntaxAccess(i));
			(JB_Tk__TokenNilSet(_tmPf30, IllegalHandler));
			JB_Decr(_tmPf30);
			i++;
		};
	}
	;
	JB_Decr(IllegalHandler);
}

int JB_Tk__Init_() {
	{
		JB_SetRef(JB__Tk_ErrorTabsAfterSpaces, JB_LUB[135]);
		JB_SetRef(JB__Tk_Data, JB_LUB[0]);
		JB__Tk_StopBars = 0;
		JB__Tk_BaseExtra = 0;
		JB__Tk_UsingPos = -1;
		JB__Tk_UsingExtra = -1;
		JB__Tk_InsertedFlags = 0;
		JB__Tk_DotInsertAllow = false;
	}
	;
	return 0;
}

int JB_Tk__InitCode_() {
	{
	}
	;
	JB_SetRef(JB_StdErr, JB_Rec__New());
	return 0;
}

Message* JB_Tk__LoweredIndent(Message* output, Message* curr) {
	int chin = JB_Msg_CleanIndent(curr);
	while (JB_Msg_IndentScore(output) > chin) {
		if ((JB_Msg_EqualsSyx(output, JB_SyxArg, false)) and JB_Msg_SyntaxIs(output, kJB__MsgUIFlags_Style2)) {
			return JB_Tk__IndentBug(curr);
		}
		output = ((Message*)JB_Ring_Parent(output));
		if ((!output)) {
			return JB_Tk__IndentBug(curr);
		}
		if (JB_Msg_EqualsSyx(output, JB_SyxDecl, false)) {
			output = ((Message*)JB_Ring_Parent(output));
		}
	};
	JB_Tree_SyntaxAppend(output, curr);
	if (((bool)(JB_Msg_CleanIndent(curr) % 4))) {
		return curr;
	}
	return output;
}

Message* JB_Tk__MakeInvisArg(Message* tmp, int indent) {
	if (JB_Msg_EqualsSyx(tmp, JB_SyxItem, false)) {
		Message* last = ((Message*)JB_Ring_Last(tmp));
		if ((!JB_Msg_EqualsSyx(last, JB_SyxEmb, false))) {
			return JB_Tk__UnexpectedSyntax(last);
		}
		last->Func = JB_SyxArg;
		return last;
	}
	return JB_Tk__NewParentName(tmp, JB_SyxArg, tmp->Position, JB_LUB[0]);
}

Message* JB_Tk__MakeRel(Message* first, int Bits) {
	Message* opp = JB_Tk__Process(Bits, false, nil);
	if ((!(opp))) {
		return first;
	}
	Message* Rel = JB_Tk__NewParentName(nil, JB_SyxRel, first->Position, JB_LUB[0]);
	JB_Tree_SyntaxAppend(Rel, first);
	JB_Tree_SyntaxAppend(Rel, opp);
	if (JB_Tk__EatString(JB_LUB[136])) {
		Rel->Func = JB_SyxERel;
		opp->Extra++;
	}
	bool Mode = kJB__Tk_Allow;
	if ((!JB_byte_IsLetter(JB_Str_ByteValue(opp->Name, 0)))) {
		Bits = (Bits | kJB__Tk_OppWord);
	}
	JB_Tree_SyntaxAppend(Rel, JB_Tk__ProcessThing(Bits, Mode));
	(JB_Msg_AfterSet(Rel, JB_Msg_After(((Message*)JB_Ring_Last(Rel)))));
	return Rel;
}

int JB_Tk__MessageErrorSub(FastString* fs, int num, int ButFound) {
	if ((!JB__Tk_ErrorNames)) {
		JB_SetRef(JB__Tk_ErrorNames, JB_Dict__New());
		(JB_Dict_SetInt(JB__Tk_ErrorNames, kJB__Tk_Temporal, JB_LUB[137]));
		(JB_Dict_SetInt(JB__Tk_ErrorNames, kJB__Tk_TemporalSyx, JB_LUB[138]));
		(JB_Dict_SetInt(JB__Tk_ErrorNames, kJB__Tk_TemporalWord, JB_LUB[139]));
		(JB_Dict_SetInt(JB__Tk_ErrorNames, kJB__Tk_EndOfLine, JB_LUB[63]));
		(JB_Dict_SetInt(JB__Tk_ErrorNames, kJB__Tk_colon, JB_LUB[140]));
		(JB_Dict_SetInt(JB__Tk_ErrorNames, kJB__Tk_OppSyx, JB_LUB[141]));
		(JB_Dict_SetInt(JB__Tk_ErrorNames, kJB__Tk_OppWord, JB_LUB[141]));
		(JB_Dict_SetInt(JB__Tk_ErrorNames, kJB__Tk_Opp, JB_LUB[141]));
		(JB_Dict_SetInt(JB__Tk_ErrorNames, kJB__Tk_OppTemporal, JB_LUB[142]));
		(JB_Dict_SetInt(JB__Tk_ErrorNames, kJB__Tk_Thing, JB_LUB[143]));
		(JB_Dict_SetInt(JB__Tk_ErrorNames, kJB__Tk_ThingWord, JB_LUB[143]));
		(JB_Dict_SetInt(JB__Tk_ErrorNames, kJB__Tk_ThingSyx, JB_LUB[144]));
		(JB_Dict_SetInt(JB__Tk_ErrorNames, kJB__Tk_illegalchar, JB_LUB[145]));
	}
	if (fs->Length) {
		JB_FS_AppendString(fs, JB_LUB[146]);
	}
	 else {
		JB_FS_AppendString(fs, JB_LUB[147]);
	}
	int BestValue = JB_Tk__FindError(num);
	if (BestValue) {
		JB_String* _tmPf0 = JB_Incr(((JB_String*)JB_Dict_ValueInt(JB__Tk_ErrorNames, BestValue)));
		JB_FS_AppendString(fs, _tmPf0);
		JB_Decr(_tmPf0);
		return num & (~BestValue);
	}
	JB_FS_AppendString(fs, JB_LUB[148]);
	return 0;
}

bool JB_Tk__NeedName(Message* thg) {
	if (JB_Msg_EqualsSyx(thg, JB_SyxThg, false)) {
		return true;
	}
	return ((bool)JB_FreeIfDead(JB_Tk__ErrorAdd(JB_LUB[149], thg->Position)));
}

Message* JB_Tk__NewParentName(Message* Parent, Syntax Func, int Start, JB_String* name) {
	Message* rz = nil;
	rz = JB_Msg__NewRange(Parent, Func, Start, name, JB_Tk__NextStart() - Start);
	return rz;
}

Message* JB_Tk__NewParent(Message* Parent, Syntax Func, int Start, int End) {
	Message* rz = nil;
	JB_String* name = JB_Tk__Range(Start, End);
	rz = JB_Msg__NewRange(Parent, Func, Start, name, End - Start);
	return rz;
}

Message* JB_Tk__NewEmpty(Message* P, Syntax F, int Start, int After) {
	Message* rz = nil;
	rz = JB_Msg__NewRange(P, F, Start, JB_LUB[0], After - Start);
	return rz;
}

Message* JB_Tk__NewSkip(Message* P, Syntax F, int Start, int NameStart, int NameEnd) {
	Message* rz = nil;
	JB_String* name = JB_Tk__Range(NameStart, NameEnd);
	rz = JB_Msg__NewRange(P, F, Start, name, JB_Tk__NextStart() - Start);
	return rz;
}

Message* JB_Tk__NewWord(Message* P, Syntax F, int Start, int SearchFrom) {
	Message* rz = nil;
	int after = JB_Tk__WordAfter(SearchFrom);
	JB_String* name = JB_Tk__Range(SearchFrom, after);
	rz = JB_Msg__NewRange(P, F, Start, name, after - Start);
	return rz;
}

ParserLineAndIndent JB_Tk__NextLineAndIndent(Message* parent) {
	ParserLineAndIndent rz = ((ParserLineAndIndent){});
	int first = JB_Tk__NextStart();
	int n = first;
	JB_String* D = JB__Tk_Data;
	int end = JB_Str_Length(D);
	byte* addr = D->Addr;
	bool GotSpaces = false;
	while (n < end) {
		byte c = addr[n++];
		if (c == '\t') {
			if ((!rz.Commas)) {
				rz.Indent = (rz.Indent + 4);
			}
			if (GotSpaces and ((bool)rz.Lines)) {
				JB_FreeIfDead(JB_Tk__ErrorAdd(JB__Tk_ErrorTabsAfterSpaces, n - 1));
			}
		}
		 else if (c == ' ') {
			GotSpaces = true;
			if ((!rz.Commas)) {
				rz.Indent++;
			}
		}
		 else if ((c == '\n') or (c == '\x0D')) {
			rz.Lines++;
			rz.IsDebug = ((bool)((int)(c == '\x0D')));
			rz.Indent = 0;
			rz.Commas = 0;
			rz.Pos = (n - 1);
			GotSpaces = false;
			if (JB_Msg_EqualsSyx(parent, JB_SyxList, false)) {
				(JB_Msg_SyntaxIsSet(parent, kJB__MsgUIFlags_Style2, true));
			}
		}
		 else if (c == ',') {
			rz.Commas++;
			Message* l = ((Message*)JB_Ring_Last(parent));
			if (l) {
				rz.Indent = l->Indent;
			}
			 else {
				rz.Indent = 0;
			}
			GotSpaces = false;
		}
		 else {
			GotSpaces = false;
			n--;
			if (c != '/') {
				break;
			}
			if (addr[n + 1] == '*') {
				rz.Lines++;
				rz.Indent = 0;
			}
			(JB_Tk__NextStartSet(n));
			Message* line = JB_Tk__Process(kJB__Tk_EndOfLine, kJB__Tk_Allow, parent);
			n = JB_Tk__NextStart();
			if ((!(line == JB__Tk_EndOfLineMarker))) {
				break;
			}
		}
	};
	rz.Lines = (rz.Lines + rz.Commas);
	(JB_Tk__NextStartSet(n));
	if (((first > 0) and (!rz.Lines)) or (rz.Indent < 0)) {
		rz.Indent = -1;
	}
	return rz;
}

bool JB_Tk__NoFuncAfter(byte b) {
	return (b == '\t') or ((b == ' ') or (b == '\\'));
}

Message* JB_Tk__NumberSub(int Start, int RealStart) {
	Message* rz = nil;
	int After = JB_Tk__NumEnd(JB__Tk_Data, Start);
	(JB_Tk__NextStartSet(After));
	int StartAt = JB_Str_IsHexLike(JB__Tk_Data, Start);
	Ind UnitPos2 = -1;
	if (StartAt == 0) {
		UnitPos2 = JB_Str_OutCharSet(JB__Tk_Data, JB__Constants_CSLettersOnly, After, Start + StartAt);
	}
	if ((!(JB_Ind_SyntaxCast(UnitPos2)))) {
		UnitPos2 = (After - 1);
	}
	UnitPos2++;
	Message* Num = JB_Tk__NewParent(nil, JB_SyxNum, RealStart, UnitPos2);
	if (After <= UnitPos2) {
		return Num;
	}
	rz = JB_Tk__NewSkip(nil, JB_SyxUnit, RealStart, UnitPos2, After);
	JB_Tree_SyntaxAppend(rz, Num);
	return rz;
}

int JB_Tk__NumEnd(JB_String* NumStr, int Start) {
	int rz = 0;
	Ind Dot = JB_Str_OutCharSet(NumStr, JB__Constants_CSNum, Start, JB_int__max());
	if ((!(JB_Ind_SyntaxCast(Dot)))) {
		return JB_Str_Length(NumStr);
	}
	if ((!(JB_Str_ByteValue(NumStr, Dot) == '.'))) {
		return Dot;
	}
	byte AfterDot = JB_Str_ByteValue(NumStr, Dot + 1);
	if ((!(JB_byte_IsInt(AfterDot)))) {
		return Dot;
	}
	rz = JB_Str_OutCharSet(NumStr, JB__Constants_CSNum, Dot + 1, JB_int__max());
	if ((!(rz))) {
		rz = JB_Str_Length(NumStr);
	}
	return rz;
}

bool JB_Tk__OK() {
	return (!JB_Ind_SyntaxCast(JB_Tk__ErrorStart()));
}

Message* JB_Tk__OppChain(Message* opp) {
	Message* result = JB_Incr(JB_Tk__Process(kJB__Tk_adjectiveop, false, opp));
	if ((!result)) {
		JB_Decr(result);
		return opp;
	}
	if ((!(JB_FreeIfDead(((Message*)JB_Ring_Parent(opp)))))) {
		(JB_Ring_FirstSet(result, opp));
	}
	JB_SafeDecr(result);
	return result;
}

void JB_Tk__Params(Message* Parent, int N) {
	Message* Result = JB_Incr(JB_Tk__NewParentName(Parent, JB_SyxPrm, N, JB_LUB[0]));
	JB_Tk__ParseLoopFlags(Result, JB_LUB[74], kJB__Tk_TemporalSyxNoBar);
	JB_Decr(Result);
}

Message* JB_Tk__ParseItem(Message* ch, int TemporalFlags, int ops) {
	int ns = JB_Tk__NextStart();
	if ((!(JB_Tk__Allow(kJB__Tk_colon)))) {
		return ch;
	}
	if (JB_Msg_OperatorIn(ch, JB_SyxArg)) {
		if (JB_Msg_EqualsSyx(ch, JB_SyxThg, false)) {
			ch->Func = JB_SyxTmp;
			Message* _tmPf0 = JB_Incr(JB_Tk__fArgColon(ns, ch));
			JB_Tree_SyntaxAppend(ch, _tmPf0);
			JB_Decr(_tmPf0);
		}
		return ch;
	}
	Message* Result = JB_Incr(JB_Tk__NewParentName(nil, JB_SyxItem, ch->Position, JB_LUB[0]));
	JB_Tree_SyntaxAppend(Result, ch);
	Message* ch2 = JB_Incr(JB_Tk__Process(TemporalFlags, false, Result));
	if ((!ch2)) {
		JB_SetRef(ch2, JB_Tk__ProcessThing(ops, false));
	}
	if ((!(ch2))) {
		JB_SetRef(ch2, JB_Tk__NewParentName(Result, JB_SyxEmb, ns, JB_LUB[0]));
	}
	JB_Tree_SyntaxAppend(Result, ch2);
	(JB_Msg_AfterSet(Result, JB_Msg_After(ch2)));
	JB_Decr(ch2);
	JB_SafeDecr(Result);
	return Result;
}

int JB_Tk__ParseLoop(Message* Output, int TmpoFlags) {
	int rz = 0;
	Message* prev = nil;
	while (Output) {
		ParserLineAndIndent Info = JB_Tk__NextLineAndIndent(Output);
		rz = (rz + Info.Lines);
		if (JB_Tk__WillEnd() or (((bool)prev) and (!Info.Lines))) {
			break;
		}
		Message* ch = JB_Tk__ParseLoopItem(Output, TmpoFlags, prev, Info.Indent);
		if ((!ch)) {
			break;
		}
		rz = (rz + ((JB_Msg_EqualsSyx(ch, JB_SyxItem, false))));
		if (Info.IsDebug) {
			ch->Flags = (ch->Flags | kJB__MsgUIFlags_BreakPoint);
		}
		Output = JB_Tk__AddToOutput(Output, ch, prev, Info.Pos);
		prev = ch;
	};
	return rz;
}

bool JB_Tk__ParseLoopFlags(Message* Output, JB_String* Ender, int TmpoFlags) {
	bool rz = false;
	Ind err = JB_Tk__NextStart();
	rz = ((bool)JB_Tk__ParseLoop(Output, TmpoFlags & (~JB__Tk_StopBars)));
	if (JB_Str_Exists(Ender)) {
		JB_Tk__ExpectEndChar(err, Ender, true);
		(JB_Msg_AfterSet(Output, JB_Tk__NextStart()));
	}
	return rz;
}

Message* JB_Tk__ParseLoopItem(Message* Output, int TmpoFlags, Message* Prev, int Indent) {
	Message* ch = JB_Incr(JB_Tk__Process(kJB__Tk_Temporal & TmpoFlags, false, Output));
	if ((!ch)) {
		Message* item = JB_Incr(JB_Tk__ProcessThingParent(Output, kJB__Tk_Opp, kJB__Tk_Thing));
		if ((!item)) {
			JB_Decr(ch);
			JB_Decr(item);
			return nil;
		}
		TmpoFlags = (TmpoFlags & (kJB__Tk_Temporal & (~kJB__Tk_TemporalWord)));
		JB_SetRef(ch, JB_Tk__ParseItem(item, TmpoFlags, kJB__Tk_Opp));
		JB_Decr(item);
	}
	 else if ((JB_Msg_EqualsSyx(ch, JB_SyxCnj, false)) or (JB_Msg_EqualsSyx(ch, JB_SyxSCnj, false))) {
		JB_SetRef(ch, JB_Tk__ReRoute(Output, ch, Prev));
		if ((!ch)) {
			JB_Decr(ch);
			return nil;
		}
		Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_First(ch)));
		Indent = _tmPf0->Indent;
		JB_Decr(_tmPf0);
	}
	ch->Indent = Indent;
	JB_SafeDecr(ch);
	return ch;
}

Message* JB_Tk__PostInnerAdj(Message* Rel, Message* opp) {
	JB_Incr(Rel);
	Message* f = JB_Incr(((Message*)JB_Ring_First(Rel)));
	if ((!(JB_Msg_EqualsSyx(Rel, JB_SyxRel, false))) and (!((JB_Msg_EqualsSyx(Rel, JB_SyxBra, false)) and (JB_Msg_EqualsSyx(f, JB_SyxRel, false))))) {
		Message* _tmPf1 = JB_Incr(JB_Tk__ErrorAdd(JB_LUB[150], Rel->Position));
		JB_Decr(Rel);
		JB_Decr(f);
		JB_SafeDecr(_tmPf1);
		return _tmPf1;
	}
	if (JB_Msg_EqualsSyx(Rel, JB_SyxBra, false)) {
		JB_SetRef(Rel, f);
		JB_SetRef(f, ((Message*)JB_Ring_First(f)));
	}
	Message* Adverb = JB_Incr(JB_Tk__Process(kJB__Tk_OppWord | kJB__Tk_OppBra, kJB__Tk_Expect, nil));
	if ((!Adverb)) {
		JB_Decr(Rel);
		JB_Decr(f);
		JB_Decr(Adverb);
		return nil;
	}
	Message* adj = JB_Incr(JB_Syx_Msg(JB_SyxAdj, JB_LUB[0]));
	(JB_Ring_NextSibSet(f, adj));
	JB_Decr(f);
	JB_Tree_SyntaxAppend(adj, Adverb);
	JB_Decr(Adverb);
	Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_NextSib(adj)));
	JB_Tree_SyntaxAppend(adj, _tmPf0);
	JB_Decr(_tmPf0);
	JB_Decr(adj);
	Rel->Func = JB_Syxpinn;
	JB_SafeDecr(Rel);
	return Rel;
}

Message* JB_Tk__ProcessThing(int Ops, bool Expect) {
	return JB_Tk__ProcessThingSub(nil, Ops, kJB__Tk_Thing, Expect);
}

Message* JB_Tk__ProcessThingNoBar(int Ops, bool Expect) {
	return JB_Tk__ProcessThingSub(nil, Ops, kJB__Tk_ThingSyx | kJB__Tk_ThingWord, Expect);
}

Message* JB_Tk__ProcessThingOrTmp(int opps) {
	return JB_Tk__ProcessThingSub(nil, opps, kJB__Tk_ThingSyx | (kJB__Tk_ThingWord | kJB__Tk_TemporalSyx), false);
}

Message* JB_Tk__ProcessThingParent(Message* parent, int Ops, int ThingFlags) {
	return JB_Tk__ProcessThingSub(parent, Ops, ThingFlags, false);
}

Message* JB_Tk__ProcessThingSub(Message* Parent, int Ops, int KindOfThing, bool Expect) {
	Message* result = JB_Incr(JB_Tk__Process(KindOfThing, Expect, Parent));
	if ((!result)) {
		JB_Decr(result);
		return nil;
	}
	if (JB_Tk__WillEnd()) {
		JB_SafeDecr(result);
		return result;
	}
	Message* _tmPf0 = JB_Incr(JB_Tk__DecorateThing(result, Ops));
	JB_Decr(result);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

Message* JB_Tk__ReRoute(Message* output, Message* cnj, Message* f) {
	Message* rz = nil;
	if ((!f)) {
		JB_Decr(rz);
		return JB_Tk__ErrorAdd(JB_LUB[151], JB_Tk__NextStart());
	}
	JB_SetRef(rz, JB_Tk__ChainTemporalRels(f, cnj));
	if ((!rz)) {
		JB_Decr(rz);
		return nil;
	}
	if (JB_Ring_HasChildCount(rz, 2) and JB_Tk__Allow(kJB__Tk_EndOfLine)) {
		Message* _tmPf0 = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_Opp, false));
		JB_Tree_SyntaxAppend(rz, _tmPf0);
		JB_Decr(_tmPf0);
	}
	JB_Tree_SyntaxAppend(output, rz);
	JB_SafeDecr(rz);
	return rz;
}

void JB_Tk__StopParse() {
	JB_Tk__StartParse(nil);
}

void JB_Tk__TokensFn(Array* arr, int bits, ParseHandler func) {
	TokHan* _tmPf0 = JB_Incr(JB_Tk__Handler(bits, ((TokenHandler_fp)func)));
	JB_Tk__TokensHan(arr, _tmPf0);
	JB_Decr(_tmPf0);
}

void JB_Tk__TokensHan(Array* arr, TokHan* H) {
	{
		int _if0 = 0;
		while (_if0 < JB_Array_Size(arr)) {
			JB_String* s = JB_Incr(((JB_String*)JB_Array_Value(arr, _if0)));
			(JB_Tk__TokenSet(s, H));
			JB_Decr(s);
			_if0++;
		};
	};
}

void JB_Tk__TokenzFn(JB_String* s, int bits, ParseHandler func) {
	if (JB_Str_ContainsString(s, JB_LUB[78])) {
		Array* _tmPf0 = JB_Incr(JB_Str_Words(s));
		JB_Tk__TokensFn(_tmPf0, bits, func);
		JB_Decr(_tmPf0);
	}
	 else {
		TokHan* _tmPf1 = JB_Incr(JB_Tk__Handler(bits, ((TokenHandler_fp)func)));
		(JB_Tk__TokenSet(s, _tmPf1));
		JB_Decr(_tmPf1);
	}
}

Message* JB_Tk__UnexpectedSyntax(Message* bad) {
	return JB_Tk__ErrorAdd(JB_LUB[79], bad->Position);
}

Message* JB_Tk__UnTmpPlace(Message* R) {
	Message* p = ((Message*)JB_Ring_Parent(R));
	return ((Message*)JB_Ternary((JB_Msg_EqualsSyx(p, JB_SyxTmp, false)), p, R));
}

bool JB_Tk__WillEnd() {
	return JB_Tk__CheckEnded(kJB__Tk_End);
}

int JB_Tk__WordAfter(int Start) {
	int n = JB_Str_Length(JB__Tk_Data);
	if (Start < n) {
		Ind After = JB_Str_OutCharSet(JB__Tk_Data, JB__Constants_CSWordMiddle, Start, JB_int__max());
		if ((!JB_Ind_SyntaxCast(After))) {
			After = n;
		}
		if (After > Start) {
			(JB_Tk__NextStartSet(After));
			return After;
		}
	}
	JB_Tk__ErrorLetter(Start);
	return 0;
}

int JB_Tk__XMLAttribs(Message* XML, int start) {
	Message* AllAtts = JB_Incr(JB_Tk__NewParentName(XML, JB_SyxArg, start, JB_LUB[0]));
	JB_String* s = JB_Incr(JB__Tk_Data);
	while (true) {
		int i = JB_Tk__NextStart();
		byte c = 0;
		while (i < JB_Str_Length(s)) {
			c = JB_Str_ByteValue(s, i);
			if ((!JB_byte_IsWhite(c))) {
				break;
			}
			i++;
		};
		if ((c == '>') or ((c == '/') and (JB_Str_ByteValue(s, i + 1) == '>'))) {
			JB_Decr(AllAtts);
			JB_Decr(s);
			return i;
		}
		if ((!(JB_CS_HasChar(JB__Constants_CSWordStart, c)))) {
			break;
		}
		Message* Attr = JB_Incr(JB_Tk__fThingWord(i, nil));
		Attr->Func = JB_SyxXAtt;
		JB_Tree_SyntaxAppend(AllAtts, Attr);
		if ((!JB_Tk__ExpectEndChar(JB_Tk__NextStart(), JB_LUB[136], true))) {
			JB_Decr(AllAtts);
			JB_Decr(s);
			JB_Decr(Attr);
			return nil;
		}
		i = JB_Tk__CleanSpaces();
		c = JB_Str_ByteValue(s, i);
		if ((!((c == '\'') or (c == '"')))) {
			JB_FreeIfDead(JB_Tk__ErrorAdd(JB_LUB[152], i));
			JB_Decr(AllAtts);
			JB_Decr(s);
			JB_Decr(Attr);
			return nil;
		}
		Ind After = JB_Str_FindByte(s, c, i + 1, JB_int__max());
		Message* Txt = JB_Incr(JB_Tk__NewParentName(Attr, JB_SyxXTxt, start, JB_LUB[0]));
		JB_Decr(Attr);
		JB_String* _tmPf0 = JB_Incr(JB_Str_Range(s, i + 1, After));
		JB_SetRef(Txt->Name, JB_Str_MultiReplaceAll(_tmPf0, JB__Constants_XML_UnEscapeStr, JB_StdErr));
		JB_Decr(_tmPf0);
		JB_Decr(Txt);
		(JB_Tk__NextStartSet(After + 1));
	};
	JB_Decr(s);
	JB_Decr(AllAtts);
	JB_FreeIfDead(JB_Tk__ErrorAdd(JB_LUB[153], JB_Tk__NextStart()));
	return 0;
}

Message* JB_Tk__XMLWhatever(int s, int skip, JB_String* ender, Syntax fn) {
	Message* rz = nil;
	int i = s + skip;
	Ind EndPos = JB_Str_InStr(JB__Tk_Data, ender, i, JB_int__max(), false);
	if ((!JB_Ind_SyntaxCast(EndPos))) {
		JB_Decr(rz);
		return JB_Tk__ErrorAdd(JB_LUB[154], i);
	}
	(JB_Tk__NextStartSet(EndPos + JB_Str_Length(ender)));
	if (fn) {
		JB_String* _tmPf0 = JB_Incr(JB_Str_Range(JB__Tk_Data, i, EndPos));
		JB_SetRef(rz, JB_Tk__NewParentName(nil, fn, i, _tmPf0));
		JB_Decr(_tmPf0);
		rz->Position = s;
		(JB_Msg_AfterSet(rz, JB_Tk__NextStart()));
	}
	JB_SafeDecr(rz);
	return rz;
}



int JB_Platform__Init_() {
	{
	}
	;
	return 0;
}

int JB_Platform__InitCode_() {
	return 0;
}



int JB_zalgo__Init_() {
	{
		JB__zalgo_R = ((Random){});
		JB_SetRef(JB__zalgo_up, JB_LUB[155]);
		JB_SetRef(JB__zalgo_mid, JB_LUB[156]);
		JB_SetRef(JB__zalgo_down, JB_LUB[157]);
	}
	;
	return 0;
}

int JB_zalgo__InitCode_() {
	return 0;
}


bool JB_CompareError(Message* expected, Message* found) {
	FastString* _fsf0 = JB_Incr(JB_FS__New());
	JB_FS_AppendString(_fsf0, JB_LUB[147]);
	JB_String* _tmPf3 = JB_Incr(JB_Msg_Locate(expected));
	JB_FS_AppendString(_fsf0, _tmPf3);
	JB_Decr(_tmPf3);
	JB_FS_AppendString(_fsf0, JB_LUB[62]);
	JB_String* _tmPf4 = JB_Incr(JB_Msg_Locate(found));
	JB_FS_AppendString(_fsf0, _tmPf4);
	JB_Decr(_tmPf4);
	JB_String* _tmPf5 = JB_Incr(JB_FS_GetResult(_fsf0));
	JB_Decr(_fsf0);
	JB_PrintLine(_tmPf5);
	JB_Decr(_tmPf5);
	FastString* _fsf1 = JB_Incr(JB_FS__New());
	JB_FS_AppendString(_fsf1, JB_LUB[158]);
	Message* _tmPf7 = JB_Incr(JB_Msg_PoorAnt(expected));
	JB_String* _tmPf6 = JB_Incr(JB_Msg_Locate(_tmPf7));
	JB_Decr(_tmPf7);
	JB_FS_AppendString(_fsf1, _tmPf6);
	JB_Decr(_tmPf6);
	JB_String* _tmPf8 = JB_Incr(JB_FS_GetResult(_fsf1));
	JB_Decr(_fsf1);
	JB_PrintLine(_tmPf8);
	JB_Decr(_tmPf8);
	if (found) {
		FastString* _fsf2 = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fsf2, JB_LUB[159]);
		Message* _tmPf10 = JB_Incr(JB_Msg_PoorAnt(found));
		JB_String* _tmPf9 = JB_Incr(JB_Msg_Locate(_tmPf10));
		JB_Decr(_tmPf10);
		JB_FS_AppendString(_fsf2, _tmPf9);
		JB_Decr(_tmPf9);
		JB_String* _tmPf11 = JB_Incr(JB_FS_GetResult(_fsf2));
		JB_Decr(_fsf2);
		JB_PrintLine(_tmPf11);
		JB_Decr(_tmPf11);
	}
	 else {
		found = expected;
	}
	JB_Msg_SyntaxExpect(found, nil);
	return false;
}

JB_String* JB_EntityTest() {
	JB_String* replicate = JB_Incr(JB_LUB[160]);
	Dictionary* repl = JB_Incr(JB_Dict__New());
	(JB_Dict_ValueSet(repl, JB_LUB[9], JB_LUB[8]));
	JB_MSR_DecodeEntitySet(repl, true);
	JB_MSR_EscapeCodeSet(repl, true);
	JB_String* s3 = JB_Incr(JB_Str_Unescape(replicate));
	JB_SetRef(replicate, JB_Str_MultiReplaceAll(replicate, repl, JB_StdErr));
	JB_Decr(repl);
	if ((!((JB_Str_Equals(JB__Constants_Name, replicate, false)) and (JB_Str_Equals(JB__Constants_Name, s3, false))))) {
		debugger;
	}
	JB_Decr(s3);
	JB_String* _tmPf0 = JB_Incr(JB_Str_LowerCase(replicate));
	JB_Decr(replicate);
	JB_String* _tmPf1 = JB_Incr(JB_Str_OperatorPlus(_tmPf0, JB_LUB[161]));
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

int JB_Init_() {
	{
		JB_SetRef(JB__JbinHeader, JB_LUB[162]);
		JB_SetRef(JB__SyxDict_, JB_Dict__New());
		JB_SyxNil = JB_Syx__StdNew(JB_Msg_Nil__, JB_LUB[163], JB_LUB[164]);
		JB_SyxArg = JB_Syx__StdNew(JB_Msg_Arg__, JB_LUB[165], JB_LUB[166]);
		JB_SyxBra = JB_Syx__StdNew(JB_Msg_Bra__, JB_LUB[167], JB_LUB[168]);
		JB_SyxThg = JB_Syx__StdNew(JB_Msg_Thg__, JB_LUB[169], JB_LUB[170]);
		JB_SyxOpp = JB_Syx__StdNew(JB_Msg_Opp__, JB_LUB[171], JB_LUB[172]);
		JB_SyxCnj = JB_Syx__StdNew(JB_Msg_Cnj__, JB_LUB[173], JB_LUB[174]);
		JB_SyxTmp = JB_Syx__StdNew(JB_Msg_Tmp__, JB_LUB[175], JB_LUB[176]);
		JB_SyxName = JB_Syx__StdNew(JB_Msg_Name__, JB_LUB[177], JB_LUB[0]);
		JB_SyxQues = JB_Syx__StdNew(JB_Msg_Ques__, JB_LUB[178], JB_LUB[179]);
		JB_SyxBack = JB_Syx__StdNew(JB_Msg_Back__, JB_LUB[180], JB_LUB[181]);
		JB_SyxChar = JB_Syx__StdNew(JB_Msg_Char__, JB_LUB[182], JB_LUB[183]);
		JB_SyxSStr = JB_Syx__StdNew(JB_Msg_SStr__, JB_LUB[184], JB_LUB[185]);
		JB_SyxOat = JB_Syx__StdNew(JB_Msg_Oat__, JB_LUB[186], JB_LUB[187]);
		JB_SyxSheb = JB_Syx__StdNew(JB_Msg_Sheb__, JB_LUB[188], JB_LUB[189]);
		JB_SyxStr = JB_Syx__StdNew(JB_Msg_Str__, JB_LUB[190], JB_LUB[191]);
		JB_SyxSThg = JB_Syx__StdNew(JB_Msg_SThg__, JB_LUB[192], JB_LUB[193]);
		JB_SyxSCnj = JB_Syx__StdNew(JB_Msg_SCnj__, JB_LUB[194], JB_LUB[195]);
		JB_SyxNum = JB_Syx__StdNew(JB_Msg_Num__, JB_LUB[196], JB_LUB[197]);
		JB_SyxEmb = JB_Syx__StdNew(JB_Msg_Emb__, JB_LUB[198], JB_LUB[199]);
		JB_SyxUnit = JB_Syx__StdNew(JB_Msg_Unit__, JB_LUB[200], JB_LUB[0]);
		JB_SyxType = JB_Syx__StdNew(JB_Msg_Type__, JB_LUB[201], JB_LUB[202]);
		JB_SyxARel = JB_Syx__StdNew(JB_Msg_ARel__, JB_LUB[203], JB_LUB[204]);
		JB_SyxDot = JB_Syx__StdNew(JB_Msg_Dot__, JB_LUB[205], JB_LUB[206]);
		JB_SyxSDot = JB_Syx__StdNew(JB_Msg_SDot__, JB_LUB[207], JB_LUB[208]);
		JB_SyxFunc = JB_Syx__StdNew(JB_Msg_Func__, JB_LUB[209], JB_LUB[210]);
		JB_SyxBRel = JB_Syx__StdNew(JB_Msg_BRel__, JB_LUB[211], JB_LUB[212]);
		JB_SyxAdj = JB_Syx__StdNew(JB_Msg_Adj__, JB_LUB[213], JB_LUB[214]);
		JB_SyxBadj = JB_Syx__StdNew(JB_Msg_Badj__, JB_LUB[215], JB_LUB[216]);
		JB_SyxAcc = JB_Syx__StdNew(JB_Msg_Acc__, JB_LUB[217], JB_LUB[218]);
		JB_SyxArr = JB_Syx__StdNew(JB_Msg_Arr__, JB_LUB[219], JB_LUB[220]);
		JB_SyxItem = JB_Syx__StdNew(JB_Msg_Item__, JB_LUB[221], JB_LUB[0]);
		JB_SyxList = JB_Syx__StdNew(JB_Msg_List__, JB_LUB[222], JB_LUB[0]);
		JB_SyxPrm = JB_Syx__StdNew(JB_Msg_Prm__, JB_LUB[223], JB_LUB[224]);
		JB_SyxFile = JB_Syx__StdNew(JB_Msg_File__, JB_LUB[225], JB_LUB[226]);
		JB_SyxQuot = JB_Syx__StdNew(JB_Msg_Quot__, JB_LUB[227], JB_LUB[228]);
		JB_SyxDecl = JB_Syx__StdNew(JB_Msg_Decl__, JB_LUB[229], JB_LUB[230]);
		JB_SyxRel = JB_Syx__StdNew(JB_Msg_Rel__, JB_LUB[231], JB_LUB[232]);
		JB_SyxERel = JB_Syx__StdNew(JB_Msg_ERel__, JB_LUB[233], JB_LUB[234]);
		JB_SyxTRel = JB_Syx__StdNew(JB_Msg_TRel__, JB_LUB[235], JB_LUB[236]);
		JB_SyxTril = JB_Syx__StdNew(JB_Msg_Tril__, JB_LUB[237], JB_LUB[238]);
		JB_Syxpinn = JB_Syx__StdNew(JB_Msg_pinn__, JB_LUB[239], JB_LUB[240]);
		JB_Syxbinn = JB_Syx__StdNew(JB_Msg_binn__, JB_LUB[241], JB_LUB[242]);
		JB_SyxAsk = JB_Syx__StdNew(JB_Msg_Ask__, JB_LUB[243], JB_LUB[0]);
		JB_SyxYoda = JB_Syx__StdNew(JB_Msg_Yoda__, JB_LUB[244], JB_LUB[245]);
		JB_SyxSCom = JB_Syx__StdNew(JB_Msg_SCom__, JB_LUB[246], JB_LUB[247]);
		JB_SyxMsg = JB_Syx__StdNew(JB_Msg_Msg__, JB_LUB[248], JB_LUB[249]);
		JB_SyxTodo = JB_Syx__StdNew(JB_Msg_Todo__, JB_LUB[250], JB_LUB[251]);
		JB_Syxurl = JB_Syx__StdNew(JB_Msg_url__, JB_LUB[252], JB_LUB[253]);
		JB_SyxXAtt = JB_Syx__StdNew(JB_Msg_XAtt__, JB_LUB[254], JB_LUB[255]);
		JB_SyxXML = JB_Syx__StdNew(JB_Msg_XML__, JB_LUB[256], JB_LUB[257]);
		JB_SyxXPI = JB_Syx__StdNew(JB_Msg_XPI__, JB_LUB[258], JB_LUB[259]);
		JB_SyxXCom = JB_Syx__StdNew(JB_Msg_XCom__, JB_LUB[260], JB_LUB[261]);
		JB_SyxXCDT = JB_Syx__StdNew(JB_Msg_XCDT__, JB_LUB[262], JB_LUB[263]);
		JB_SyxXTxt = JB_Syx__StdNew(JB_Msg_XTxt__, JB_LUB[264], JB_LUB[265]);
		JB_SyxBin = JB_Syx__StdNew(JB_Msg_Bin__, JB_LUB[266], JB_LUB[267]);
	}
	;
	//// App;
	JB_App__Init_();
	//// ErrorColors;
	JB_ErrorColors__Init_();
	//// JB_API;
	JB_API__Init_();
	//// Jeebox;
	JB_Constants__Init_();
	//// parser;
	JB_Tk__Init_();
	//// zalgo;
	JB_zalgo__Init_();
	//// ErrorSeverity;
	JB_ErrorSeverity__Init_();
	//// Syntax;
	JB_Syx__Init_();
	//// Random;
	JB_Rnd__Init_();
	//// Process;
	JB_Proc__Init_();
	//// File;
	JB_File__Init_();
	//// Error;
	JB_Err__Init_();
	JB_InitCode_();
	return 0;
}

int JB_InitCode_() {
	//// Jeebox;
	JB_Constants__InitCode_();
	//// parser;
	JB_Tk__InitCode_();
	//// Random;
	JB_Rnd__InitCode_();
	return 0;
}

void JB_PrintLine(JB_String* data) {
	JB_Str_PrintLine(data);
}

void JB_Obj_PrintLine(JB_Object* o) {
	JB_String* _tmPf0 = JB_Incr(JB_ObjRender(o, nil));
	JB_PrintLine(_tmPf0);
	JB_Decr(_tmPf0);
}

bool JB_TestCasting() {
	Dictionary* d2 = JB_Incr(JB_Dict__New());
	DTWrap* _tmPf1 = JB_Incr(((DTWrap*)JB_Dict_ValueStr(d2, JB_LUB[268])));
	DTWrap* _tmPf0 = JB_Incr(JB_Wrap__NewInt(((int)JB_Wrap_Value(_tmPf1)) + 1));
	JB_Decr(_tmPf1);
	(JB_Dict_ValueSet(d2, JB_LUB[268], _tmPf0));
	JB_Decr(_tmPf0);
	JB_Decr(d2);
	Dictionary* d = JB_Incr(JB_Dict__New());
	JB_String* str = JB_Incr(JB_LUB[269]);
	if ((!((!JB_Str_ByteValue(str, 0)) and ((!JB_Str_ByteValue(str, 1)) and ((!JB_Str_ByteValue(str, 2)) and ((!JB_Str_ByteValue(str, 3)) and (JB_Str_Length(str) == 6))))))) {
		JB_Object_SyntaxExpect(nil);
		JB_Decr(d);
		JB_Decr(str);
		return nil;
	}
	(JB_Dict_ValueSet(d, str, str));
	JB_Decr(str);
	JB_Decr(d);
	if ('\x00') {
		return nil;
	}
	JB_Class* x = JB_AsClass(Message);
	Message* y = JB_Incr(JB_Msg__NewNormal(JB_SyxBra, JB_LUB[0]));
	JB_SetRef(y->Name, JB_LUB[270]);
	JB_Object* yy = nil;
	JB_SetRef(yy, y);
	Array* arr = JB_Incr((JB_Array__New0()));
	JB_Array_SyntaxAppend(arr, JB_LUB[0]);
	JB_Decr(arr);
	if (JB_Object_Isa(yy, JB_AsClass(Message))) {
		if ((!(JB_Str_Equals(((Message*)yy)->Name, JB_LUB[270], false)))) {
			debugger;
		}
	}
	JB_Decr(yy);
	bool _tmPf2 = JB_Object_Isa(y, x);
	JB_Decr(y);
	return (_tmPf2);
}








bool JB_byte_CanPrintAsNormalChar(byte self) {
	return ((self < 127) and (self >= 32));
}

bool JB_byte_In(byte self, uint a, uint b) {
	return (self >= a) and (self <= b);
}

bool JB_byte_IsInt(byte self) {
	return JB_byte_In(self, '0', '9');
}

bool JB_byte_IsLetter(byte self) {
	return JB_CP_IsLetter(((Codepoint)self));
}

bool JB_byte_IsUpper(byte self) {
	return JB_CP_IsUpper(((Codepoint)self));
}

bool JB_byte_IsWhite(byte self) {
	return JB_CP_IsWhite(((Codepoint)self));
}

byte JB_byte_LowerCase(byte self) {
	if (JB_byte_IsUpper(self)) {
		return self + 32;
	}
	return self;
}

JB_String* JB_byte_Render(byte self, FastString* fs_in) {
	if ((!fs_in)) {
		return JB_Str__SyntaxAccess(self);
	}
	JB_FS_AppendByte(fs_in, ((byte)self));
	return nil;
}





JB_String* JB_ErrorSeverity_Render(ErrorSeverity self, FastString* fs_in) {
	if (self < kJB__ErrorSeverity_MaxError) {
		if ((!(JB_Array_SyntaxCast(JB__ErrorSeverity_names)))) {
			JB_SetRef(JB__ErrorSeverity_names, JB_Str_Words(JB_LUB[271]));
		}
		JB_String* name = JB_Incr(((JB_String*)JB_Array_Value(JB__ErrorSeverity_names, ((int)self))));
		if ((!fs_in)) {
			JB_SafeDecr(name);
			return name;
		}
		JB_FS_AppendString(fs_in, name);
		JB_Decr(name);
	}
	return JB_LUB[0];
}

int JB_ErrorSeverity__Init_() {
	{
		JB_SetRef(JB__ErrorSeverity_names, JB_Array__New0());
	}
	;
	return 0;
}

int JB_ErrorSeverity__InitCode_() {
	return 0;
}



float JB_f_powow(float self, int n) {
	float rz = 0;
	//visible;
	rz = self;
	{
		int _Valuef1 = 0;
		while (_Valuef1 < n) {
			rz = (rz * rz);
			_Valuef1++;
		};
	}
	;
	return rz;
}



int JB_int_OperatorAlign(int self, int To) {
	int Missing = (self % To);
	if (Missing) {
		return self + (To - Missing);
	}
	return self;
}

bool JB_int_OperatorIsa(int self, uint n) {
	return (!(((bool)(self % n))));
}

int JB_int_OperatorMax(int self, int other) {
	if (self > other) {
		return self;
	}
	return other;
}

int JB_int_OperatorMin(int self, int other) {
	if (self < other) {
		return self;
	}
	return other;
}

IntRange JB_int_OperatorTo(int self, int other) {
	return ((IntRange)ivec2{self, other + 1});
}

int JB_int__max() {
	return 2147483647;
}



double JB_int64_AsFloat(int64 self) {
	int64* Addr = (&self);
	double* Addr2 = ((double*)Addr);
	return Addr2[0];
}

JB_String* JB_int64_Render(int64 self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_AppendInt64(fs, self);
	JB_String* _tmPf0 = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}










bool JB_Syx_ListViewable(Syntax self) {
	return (self >= JB_SyxThg) and (self <= JB_SyxEmb);
}

JB_String* JB_Syx_LongName(Syntax self) {
	if ((!self)) {
		return JB_LUB[272];
	}
	return JB_Syx_Obj(self)->LongName;
}

Message* JB_Syx_Msg(Syntax self, JB_String* name) {
	return JB_Msg__NewRange(nil, self, JB__Tk_UsingPos, name, JB_Str_Length(name));
}

Message* JB_Syx_ParentMsg(Syntax self, Message* parent, JB_String* name) {
	return JB_Msg__NewRange(parent, self, JB__Tk_UsingPos, name, JB_Str_Length(name));
}

JB_String* JB_Syx_Name(Syntax self) {
	if ((!self)) {
		return JB_LUB[272];
	}
	return JB_Syx_Obj(self)->Name;
}

SyntaxObj* JB_Syx_Obj(Syntax self) {
	return JB__FuncArray_[((int)self)];
}

fpMsgRender JB_Syx_RenderAddr(Syntax self) {
	return JB_Syx_Obj(self)->RenderAddr;
}

bool JB_Syx_Translateable(Syntax self) {
	return (self >= JB_SyxThg) and (self <= JB_SyxName);
}

Syntax JB_Syx__Func(JB_String* name, Message* where) {
	SyntaxObj* obj = JB_Incr(((SyntaxObj*)JB_Dict_ValueLower(JB__SyxDict_, name)));
	if ((!obj)) {
		JB_String* _tmPf0 = JB_Incr(JB_Str_OperatorPlus(JB_LUB[273], name));
		JB_Msg_SyntaxExpect(where, _tmPf0);
		JB_Decr(_tmPf0);
		JB_Decr(obj);
		return nil;
	}
	Syntax _tmPf1 = obj->ID;
	JB_Decr(obj);
	return _tmPf1;
}

int JB_Syx__Init_() {
	{
		JB__Syx_CurrFuncID = 0;
		JB__Syx_MaxFuncID = 0;
	}
	;
	return 0;
}

int JB_Syx__InitCode_() {
	return 0;
}

Syntax JB_Syx__StdNew(fpMsgRender msg, JB_String* name, JB_String* LongName) {
	int ID = JB__Syx_CurrFuncID++;
	SyntaxObj* result = JB_Incr(JB_Fn__New(msg, name, ID));
	JB__Syx_MaxFuncID = ID;
	(JB_Dict_ValueSet(JB__SyxDict_, name, result));
	JB_SetRef(JB__FuncArray_[ID], result);
	if (JB_Str_Exists(LongName)) {
		(JB_Dict_ValueSet(JB__SyxDict_, LongName, result));
		JB_SetRef(result->LongName, LongName);
	}
	 else {
		JB_SetRef(result->LongName, name);
	}
	JB_Decr(result);
	return ((Syntax)ID);
}








bool JB_CP_In(Codepoint self, int a, int b) {
	return ((Codepoint)(self - a)) <= ((Codepoint)(b - a));
}

bool JB_CP_IsHigher(Codepoint self) {
	return JB_CP_In(self, 128, 1114111);
}

bool JB_CP_IsLetter(Codepoint self) {
	return JB_CP_IsUpper(self) or (JB_CP_IsLower(self) or JB_CP_IsHigher(self));
}

bool JB_CP_IsLower(Codepoint self) {
	return JB_CP_In(self, 'a', 'z');
}

bool JB_CP_IsUpper(Codepoint self) {
	return JB_CP_In(self, 'A', 'Z');
}

bool JB_CP_IsWhite(Codepoint self) {
	return (self == ' ') or ((self == '\n') or ((self == '\x0D') or (self == '\t')));
}





bool JB_TC_IsFloat(DataTypeCode self) {
	return ((bool)((self >> 7) & 1));
}


Date JB_Date__New0() {
	return JB_Date__Now();
}





int JB_Rg_Width(IntRange self) {
	return self[1] - self[0];
}
























void JB_ClassData_Restore(JB_Class* self) {
	JB_MemoryLayer* _tmPf0 = JB_Incr(JB_Class_DefaultLayer(self));
	JB_Mem_Use(_tmPf0);
	JB_Decr(_tmPf0);
}


void JB_MzSt_len(CompressionStats* self, int n) {
}

void JB_MzSt_liveupdate(CompressionStats* self, JB_String* s, int outt) {
}

CompressionStats* JB_MzSt__all() {
	return nil;
}







void JB_LD_destructor(ObjectLoader* self) {
	JB_Decr(self->Result);
}

bool JB_LD_HasItem(ObjectLoader* self) {
	return ((bool)self->CurrItem);
}

int64 JB_LD_Int(ObjectLoader* self) {
	Message* C = JB_LD_Next(self);
	if ((!C)) {
		return nil;
	}
	return JB_Str_TextIntegerValid(C->Name, C);
}

int64 JB_LD_ItemInt(ObjectLoader* self) {
	Message* c = self->CurrItem;
	if ((!c)) {
		return nil;
	}
	self->CurrItem = ((Message*)JB_Ring_NextSib(c));
	return JB_Msg_Int(((Message*)JB_Ring_Last(c)), 0);
}

bool JB_LD_ItemIsInt(ObjectLoader* self) {
	Message* C = self->CurrItem;
	return ((JB_Msg_EqualsSyx(((Message*)JB_Ring_Last(C)), JB_SyxNum, false)));
}

JB_String* JB_LD_ItemName(ObjectLoader* self) {
	Message* c = self->CurrItem;
	return JB_Str_Unshare(JB_Msg_Nyme(((Message*)JB_Ring_First(c))));
}

JB_Object* JB_LD_ItemObject(ObjectLoader* self) {
	Message* c = self->CurrItem;
	if ((!c)) {
		return nil;
	}
	self->CurrItem = ((Message*)JB_Ring_NextSib(c));
	return JB_LD_ObjectSub(self, ((Message*)JB_Ring_Last(c)));
}

Message* JB_LD_Next(ObjectLoader* self) {
	Message* C = self->CurrItem;
	if (C) {
		self->CurrItem = ((Message*)JB_Ring_NextSib(C));
		return C;
	}
	return nil;
}

JB_Object* JB_LD_Object(ObjectLoader* self) {
	return JB_LD_ObjectSub(self, JB_LD_Next(self));
}

JB_Object* JB_LD_ObjectSub(ObjectLoader* self, Message* c) {
	if (JB_Msg_EqualsSyx(c, JB_SyxThg, false)) {
		return JB_Dict_ValueStr(self->Dict, c->Name);
	}
	 else if (JB_Msg_EqualsSyx(c, JB_SyxStr, false)) {
		return JB_Str_Unshare(c->Name);
	}
	return nil;
}

JB_String* JB_LD_String(ObjectLoader* self) {
	Message* C = JB_LD_Next(self);
	if ((!C)) {
		return nil;
	}
	return JB_Str_Unshare(C->Name);
}


void JB_Saver_AppendInt(ObjectSaver* self, int64 i) {
	JB_FS_AppendInt64(self->Dest, i);
	JB_FS_AppendByte(self->Dest, ',');
}

void JB_Saver_AppendObject(ObjectSaver* self, JB_Object* o) {
	JB_FS_AppendObjectOrNil(self->Dest, o);
	JB_FS_AppendByte(self->Dest, ',');
}

void JB_Saver_AppendString(ObjectSaver* self, JB_String* s) {
	JB_FS_AppendByte(self->Dest, '`');
	JB_FreeIfDead(JB_Str_ReplaceAll(s, JB_LUB[122], JB_LUB[274], false, self->Dest));
	JB_FS_AppendByte(self->Dest, '`');
	JB_FS_AppendByte(self->Dest, ',');
}

void JB_Saver_Destructor(ObjectSaver* self) {
	if (self->CantSaveThis) {
		JB_Object_Fail(self->CantSaveThis, JB_LUB[275]);
	}
	JB_Decr(self->Dest);
}

int JB_Saver__Init_() {
	{
	}
	;
	return 0;
}

int JB_Saver__InitCode_() {
	return 0;
}



void JB_Rnd_LoadProperties(Random* self, ObjectLoader* Loader) {
	//visible;
	self->Store = ((uint64)JB_LD_Int(Loader));
	self->State = ((uint64)JB_LD_Int(Loader));
}

void JB_Rnd_Reseed(Random* self) {
	(JB_Rnd_SeedSet(self, JB_Date__New0()));
}

void JB_Rnd_SaveWrite(Random* self, ObjectSaver* Saver) {
	//visible;
	JB_Saver_AppendInt(Saver, self->Store);
	JB_Saver_AppendInt(Saver, self->State);
}

void JB_Rnd_SeedSet(Random* self, uint64 Value) {
	self->Store = Value;
	self->State = 1;
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
	JB_Rnd_Reseed((&JB__Rnd_Shared));
	return 0;
}






void JB_StructSaveTest_destructor(StructSaveTest* self) {
	JB_Decr(self->Sav);
	JB_Decr(self->Str);
}

void JB_StructSaveTest_LoadProperties(StructSaveTest* self, ObjectLoader* Loader) {
	//visible;
	JB_SetRef(self->Sav, ((Saveable*)JB_LD_Object(Loader)));
	self->Intt = ((int64)JB_LD_Int(Loader));
	JB_SetRef(self->Str, ((JB_String*)JB_LD_String(Loader)));
}

void JB_StructSaveTest_SaveWrite(StructSaveTest* self, ObjectSaver* Saver) {
	//visible;
	JB_Saver_AppendObject(Saver, self->Sav);
	JB_Saver_AppendInt(Saver, self->Intt);
	JB_Saver_AppendString(Saver, self->Str);
}








































Array* JB_Object_CollectLeaks_(JB_Object* self) {
	Array* rz = JB_Incr(((Array*)JB_Array__New0()));
	JB_FindLeakedObject(self, rz);
	JB_SafeDecr(rz);
	return rz;
}

__lib__ void jdb(JB_Object* self) {
	//visible;
	if (self) {
		JB_String* _tmPf0 = JB_Incr(JB_Str__FromC(JB_ObjClass(self)->Name));
		JB_Str_Print(_tmPf0);
		JB_Decr(_tmPf0);
		JB_Str_Print(JB_LUB[276]);
	}
	JB_String* _tmPf1 = JB_Incr(JB_ObjRender(self, nil));
	JB_PrintLine(_tmPf1);
	JB_Decr(_tmPf1);
}

bool JB_Object_Isa(JB_Object* self, JB_Class* x) {
	if (self) {
		JB_Class* P = JB_ObjClass(self);
		if (x == P) {
			return true;
		}
		if ((!x->HasSubclasses)) {
			return nil;
		}
		P = P->Parent;
		while (P) {
			if (P == x) {
				return true;
			}
			P = P->Parent;
		};
	}
	return false;
}

void jbl(JB_Object* self) {
	//visible;
	{
		Array* _LoopSrcf1 = JB_Incr(JB_Object_CollectLeaks_(self));
		int _if0 = 0;
		while (_if0 < JB_Array_Size(_LoopSrcf1)) {
			JB_Object* bad = JB_Incr(JB_Array_Value(_LoopSrcf1, _if0));
			jdb(bad);
			JB_Decr(bad);
			debugger;
			_if0++;
		};
		JB_Decr(_LoopSrcf1);
	};
}

void JB_Object_SaveTryCollect(JB_Object* self, ObjectSaver* Saver) {
	if (JB_Object_Isa(self, JB_AsClass(Saveable))) {
		if ((!JB_Sav_SaveMark(((Saveable*)self)))) {
			return;
		}
		JB_Array_SyntaxAppend(JB_Sav_SaverInfo(((Saveable*)self)), ((Saveable*)self));
		JB_Sav___SaveCollect__(((Saveable*)self), Saver);
	}
	 else if ((bool)self) {
		if ((!(JB_Object_Isa(self, JB_AsClass(JB_String))))) {
			Saver->CantSaveThis = self;
		}
	}
}

void JB_Object_Fail(JB_Object* self, JB_String* Error) {
	//visible;
	if (JB_Object_Isa(self, JB_AsClass(Message))) {
		JB_Rec_NewErrorWithNode(JB_StdErr, ((Message*)self), Error, nil);
	}
	 else {
		JB_Rec_NewErrorWithNode(JB_StdErr, nil, Error, nil);
	}
}

void JB_Object_SyntaxExpect(JB_Object* self) {
	JB_PrintStackTrace();
	JB_Rec_NewErrorWithNode(JB_StdErr, nil, JB_LUB[277], nil);
}



Array* JB_CS_Bytes(CharSet* self) {
	Array* rz = ((Array*)JB_Array__New0());
	{
		int _if0 = 0;
		while (_if0 < 256) {
			if ((!JB_CS_HasChar(self, _if0))) {
				_if0++;
				continue;
			}
			byte b = ((byte)_if0);
			JB_Array_SyntaxAppend(rz, JB_byte_Render(b, nil));
			_if0++;
		};
	}
	;
	return rz;
}

bool JB_CS_OperatorContains(CharSet* self, JB_String* Data) {
	return (!JB_Ind_SyntaxCast(JB_Str_OutCharSet(Data, self, 0, JB_int__max())));
}

CharSet* JB_CS__Alloc() {
	return ((CharSet*)JB_New(CharSet));
}

CharSet* JB_CS__New(JB_String* Chars, bool UseRange) {
	CharSet* __rz__ = ((CharSet*)JB_CS__Alloc());
	if (__rz__) {
		JB_CS_Constructor(__rz__, Chars, UseRange);
	}
	return __rz__;
}


void JB_Wrap_ConstructorInt(DTWrap* self, int64 v) {
	self->DeathAction = 0;
	self->DataType = kJB__TC_s64;
	self->PrivValue = v;
}

void JB_Wrap_Destructor(DTWrap* self) {
	if (self->DeathAction == kJB__Wrap_Free) {
		JB_free(((_voidptr)self->PrivValue));
	}
}

double JB_Wrap_FloatValue(DTWrap* self) {
	if (self) {
		return JB_int64_AsFloat(self->PrivValue);
	}
	return 0;
}

JB_String* JB_Wrap_Render(DTWrap* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	//visible;
	if (JB_TC_IsFloat(self->DataType)) {
		JB_FS_AppendDoubleAsText0(fs, JB_Wrap_FloatValue(self));
	}
	 else if (self->DataType == kJB__TC_UnusedType) {
		JB_FS_AppendString(fs, JB_LUB[66]);
		JB_FS_AppendHex(fs, self->PrivValue, 2);
	}
	 else if (self->DataType == kJB__TC_bool) {
		JB_String* _tmPf0 = JB_Incr(((JB_String*)JB_Ternary(((bool)self->PrivValue), JB_LUB[278], JB_LUB[279])));
		JB_FS_AppendString(fs, _tmPf0);
		JB_Decr(_tmPf0);
	}
	 else {
		JB_FS_AppendInt64(fs, self->PrivValue);
	}
	JB_String* _tmPf1 = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

int64 JB_Wrap_Value(DTWrap* self) {
	if (self) {
		return self->PrivValue;
	}
	return 0;
}

DTWrap* JB_Wrap__Alloc() {
	return ((DTWrap*)JB_New(DTWrap));
}

DTWrap* JB_Wrap__NewInt(int64 v) {
	DTWrap* __rz__ = ((DTWrap*)JB_Wrap__Alloc());
	if (__rz__) {
		JB_Wrap_ConstructorInt(__rz__, v);
	}
	return __rz__;
}



bool JB_Rec_CanAddMore(JB_ErrorReceiver* self, ErrorSeverity level) {
	if ((!((!self->BlockErrors) and (!JB_OutOfMemoryOccurred())))) {
		return nil;
	}
	if (level >= kJB__ErrorSeverity_Error) {
		return (self->ErrorCount < self->MaxErrors);
	}
	 else {
		return (self->WarnCount < self->MaxErrors);
	}
	return false;
}

void JB_Rec_Clear(JB_ErrorReceiver* self) {
	JB_Tree_Clear(self->Errors);
	self->ErrorCount = 0;
	self->WarnCount = 0;
	self->ProblemCount = 0;
}

void JB_Rec_Constructor(JB_ErrorReceiver* self) {
	self->LogFunc = nil;
	self->ErrorCount = 0;
	self->ProblemCount = 0;
	self->WarnCount = 0;
	self->ErrorsAreWarnings = 0;
	self->BlockErrors = false;
	JB_String* _tmPf0 = JB_LUB[0];
	self->Source = JB_Incr(_tmPf0);
	self->LogObj = nil;
	JB_Error* _tmPf1 = JB_Err__New(nil, JB_LUB[0], kJB__ErrorSeverity_Error, JB_LUB[0]);
	self->Errors = JB_Incr(_tmPf1);
	self->Errors->Func = JB_SyxArg;
	self->MaxErrors = 512;
	JB__API_NilHappened = nil;
}

void JB_Rec_destructor(JB_ErrorReceiver* self) {
	JB_Decr(self->Errors);
	JB_Decr(self->Source);
	JB_Decr(self->LogObj);
}

JB_Error* JB_Rec_FirstError(JB_ErrorReceiver* self) {
	//visible;
	{
		JB_Error* _LoopSrcf2 = self->Errors;
		JB_Error* err = ((JB_Error*)JB_Tree_First_(_LoopSrcf2));
		while (err) {
			JB_Error* _Nf1 = ((JB_Error*)JB_Ring_NextSib(err));
			if (JB_Err_IsError(err)) {
				return err;
			}
			err = _Nf1;
		};
		(_LoopSrcf2);
	}
	;
	return nil;
}

void JB_Rec_incr(JB_ErrorReceiver* self, JB_Error* err, bool add) {
	int n = JB_Ternary(add, 1, -1);
	if (err->Severity == kJB__ErrorSeverity_Problem) {
		debugger;
		self->ProblemCount = (self->ProblemCount + n);
	}
	 else if (JB_Err_IsError(err)) {
		self->ErrorCount = (self->ErrorCount + n);
	}
	 else if (JB_Err_IsWarning(err)) {
		self->WarnCount = (self->WarnCount + n);
	}
}

void JB_Rec_NewErrorWithNode(JB_ErrorReceiver* self, Message* node, JB_String* Desc, JB_String* path) {
	ErrorSeverity sev = ((ErrorSeverity)JB_Ternary(self->ErrorsAreWarnings > 0, kJB__ErrorSeverity_Warning, ((ErrorSeverity)kJB__ErrorSeverity_Error)));
	JB_Error* _tmPf0 = JB_Incr(JB_Err__New(node, Desc, sev, path));
	JB_Rec_SyntaxAppend(self, _tmPf0);
	JB_Decr(_tmPf0);
}

void JB_Rec_NewItem(JB_ErrorReceiver* self, JB_Error* Err) {
	//visible;
	if (self) {
		JB_Rec_SyntaxAppend(self, Err);
	}
}

bool JB_Rec_OK(JB_ErrorReceiver* self) {
	return ((bool)self) and (!self->ErrorCount);
}

JB_Error* JB_Rec_Pop(JB_ErrorReceiver* self) {
	JB_Error* err = JB_Incr(((JB_Error*)JB_Tree_Pop(self->Errors)));
	if (err) {
		JB_Rec_incr(self, err, false);
		JB_SafeDecr(err);
		return err;
	}
	JB_Decr(err);
	return nil;
}

int JB_Rec_PrintErrorsMain(JB_ErrorReceiver* self, ErrorSeverity Level, bool PrintCount, bool shell) {
	JB_ErrorReceiver* rec = JB_Incr(self);
	if ((!rec)) {
		JB_SetRef(rec, JB_StdErr);
	}
	FastString* fs = JB_Incr(JB_FS__New());
	int Count = JB_Rec_RenderErrors(rec, fs, Level, shell);
	JB_Decr(rec);
	if ((!Count)) {
		JB_Decr(fs);
		return nil;
	}
	JB_String* _tmPf0 = JB_Incr(JB_FS_GetResult(fs));
	JB_Str_PrintError(_tmPf0);
	JB_Decr(_tmPf0);
	JB_FS_ProblemsFound(fs, Count);
	JB_String* _tmPf1 = JB_Incr(JB_FS_GetResult(fs));
	JB_Decr(fs);
	JB_Str_PrintError(_tmPf1);
	JB_Decr(_tmPf1);
	if (Count) {
		return -1;
	}
	return 0;
}

JB_String* JB_Rec_Render(JB_ErrorReceiver* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_Rec_RenderErrors(self, fs, 0, false);
	JB_String* _tmPf0 = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

int JB_Rec_RenderErrors(JB_ErrorReceiver* self, FastString* fs, ErrorSeverity Level, bool shell) {
	int rz = 0;
	if ((!self)) {
		return nil;
	}
	{
		JB_Error* err = ((JB_Error*)JB_Ring_First(self->Errors));
		while (err) {
			JB_Error* _Nf1 = ((JB_Error*)JB_Ring_NextSib(err));
			if (err->Severity >= Level) {
				rz++;
				if (shell) {
					JB_FreeIfDead(JB_Err_render_clang(err, fs));
				}
				 else {
					JB_FreeIfDead(JB_Err_render(err, fs));
				}
				JB_FS_AppendByte(fs, '\n');
			}
			err = _Nf1;
		};
	}
	;
	return rz;
}

int JB_Rec_ShellPrintErrors(JB_ErrorReceiver* self) {
	//visible;
	return JB_Rec_PrintErrorsMain(self, kJB__ErrorSeverity_Problem, false, true);
}

void JB_Rec_SyntaxAppend(JB_ErrorReceiver* self, JB_Error* Err) {
	bool CanPrint = (!self->ErrorCount) and ((bool)JB__Err_AutoPrint);
	JB_Rec_incr(self, Err, true);
	if ((!JB_Rec_CanAddMore(self, Err->Severity))) {
		return;
	}
	if ((!(JB_Str_Exists(Err->Path)))) {
		JB_SetRef(Err->Path, self->Source);
	}
	{
		fnErrorLogger __INSID102 = self->LogFunc;
		if (__INSID102) {
			JB_String* _tmPf0 = JB_Incr(JB_Err_render(Err, nil));
			(__INSID102)(self, _tmPf0);
			JB_Decr(_tmPf0);
		}
	}
	;
	if (CanPrint and JB_Err_NeedsPrint(Err)) {
		JB_String* _tmPf1 = JB_Incr(JB_Err_render(Err, nil));
		JB_PrintLine(_tmPf1);
		JB_Decr(_tmPf1);
	}
	if (((bool)JB__Err_AutoPrint) and (Err->Severity >= kJB__ErrorSeverity_Error)) {
		JB_DoAt(1);
	}
	if (JB__Err_AutoPrint != kJB__ErrorFlags_PrintAndRemove) {
		JB_Tree_SyntaxAppend(self->Errors, Err);
	}
}

JB_ErrorReceiver* JB_Rec__Alloc() {
	return ((JB_ErrorReceiver*)JB_New(JB_ErrorReceiver));
}

JB_ErrorReceiver* JB_Rec__New() {
	JB_ErrorReceiver* __rz__ = ((JB_ErrorReceiver*)JB_Rec__Alloc());
	if (__rz__) {
		JB_Rec_Constructor(__rz__);
	}
	return __rz__;
}


void JB_FS_AppendEscape(FastString* self, JB_String* s) {
	JB_FS_AppendMultiReplace(self, s, JB__Constants_EscapeStr, JB_StdErr);
}

void JB_FS_AppendHexStr(FastString* self, JB_String* Data) {
	if (JB_Str_Exists(Data)) {
		JB_FS_AppendHexData(self, Data->Addr, JB_Str_Length(Data), 0);
	}
}

void JB_FS_AppendObjectID(FastString* self, Saveable* o) {
	JB_FS_AppendHex3(self, JB_ObjID(o));
}

void JB_FS_AppendObjectOrNil(FastString* self, JB_Object* o) {
	if (JB_Object_Isa(o, JB_AsClass(Saveable))) {
		if (JB_Sav_IsSaveMarked(((Saveable*)o))) {
			JB_FS_AppendObjectID(self, ((Saveable*)o));
		}
		 else {
			//"Valid behaviour! For example we save a level, but we don't save the player along with the level. Like terraria.";
			JB_FS_AppendString(self, JB_LUB[163]);
		}
	}
	 else if (JB_Object_Isa(o, JB_AsClass(JB_String))) {
		JB_FreeIfDead(JB_ObjRender(((JB_String*)o), self));
	}
	 else {
		JB_FS_AppendString(self, JB_LUB[163]);
	}
}

void JB_FS_AppendInfo(FastString* self, JB_String* name, JB_String* data) {
	if (JB_Str_Exists(data)) {
		JB_FS_fieldstart(self, name);
		JB_FS_AppendByte(self, '"');
		JB_FS_AppendEscape(self, data);
		JB_FS_AppendByte(self, '"');
	}
}

void JB_FS_AppendInfoNum(FastString* self, JB_String* name, int64 data) {
	if (data) {
		JB_FS_fieldstart(self, name);
		JB_FS_AppendInt64(self, data);
	}
}

void JB_FS_fieldstart(FastString* self, JB_String* name) {
	JB_FS_AppendIndent(self);
	if (JB_Str_Exists(name)) {
		JB_FS_AppendString(self, name);
		JB_FS_AppendByte(self, ' ');
	}
}

void JB_FS_lint(FastString* self, uint64 n) {
	while (n) {
		JB_FS_AppendByte(self, ((byte)(n & 255)));
		n = (n >> 8);
	};
}

void JB_FS_MsgErrorName(FastString* self, JB_String* name) {
	if (JB_Str_Exists(name)) {
		JB_FS_AppendString(self, JB_LUB[280]);
		JB_FS_AppendString(self, name);
		JB_FS_AppendString(self, JB_LUB[281]);
	}
}

void JB_FS_ProblemsFound(FastString* self, int count) {
	JB_FS_AppendInt32(self, count);
	JB_FS_AppendString(self, JB_LUB[282]);
	if (count > 1) {
		JB_FS_AppendByte(self, 's');
	}
	JB_FS_AppendString(self, JB_LUB[283]);
}

JB_String* JB_FS_Render(FastString* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_AppendFastString(fs, self);
	JB_String* _tmPf0 = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

void JB_FS_AppendFastString(FastString* self, FastString* fs) {
	JB_FS_AppendMem_(self, fs->ResultPtr, fs->Length);
}

void JB_FS_AppendInt64(FastString* self, int64 data) {
	JB_FS_AppendIntegerAsText(self, data, 1);
}

void JB_FS_AppendInt32(FastString* self, int data) {
	JB_FS_AppendInt64(self, ((int64)data));
}

void JB_FS_SyntaxAppend(FastString* self, Message* msg) {
	if (msg) {
		(JB_Syx_RenderAddr(msg->Func))(msg, self);
	}
}

FastString* JB_FS__Alloc() {
	return ((FastString*)JB_New(FastString));
}

int JB_FS__Init_() {
	{
	}
	;
	return 0;
}

int JB_FS__InitCode_() {
	return 0;
}

FastString* JB_FS__New() {
	FastString* __rz__ = ((FastString*)JB_FS__Alloc());
	if (__rz__) {
		JB_FS_Constructor(__rz__);
	}
	return __rz__;
}



void JB_Lk_Constructor(LeakTester* self, JB_String* name) {
	self->MemUsedStart = JB_App__ObjMemory();
	self->Name = JB_Incr(name);
	JB_Mem_Mark();
}

void JB_Lk_destructor(LeakTester* self) {
	JB_Decr(self->Name);
}

void JB_Lk_FinalTest(LeakTester* self) {
	JB_Lk_Test2(self);
	self->MemUsedStart = nil;
	JB_Mem_Unmark();
}

void JB_Lk_Test1(LeakTester* self) {
	//visible;
	FastString* fs = JB_Incr(JB_FS__New());
	//;
	JB_FS_AppendByte(fs, 'a');
	JB_FS_AppendInt32(fs, 1);
	JB_FS_AppendByte(fs, 'b');
	JB_FS_AppendInt32(fs, 2);
	//;
	JB_Obj_PrintLine(fs);
	JB_Decr(fs);
}

void JB_Lk_Test2(LeakTester* self) {
	if ((!self->MemUsedStart)) {
		return;
	}
	int NewAmount = JB_App__ObjMemory();
	int Diff = NewAmount - self->MemUsedStart;
	if (Diff > 0) {
		debugger;
		FastString* _fsf0 = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fsf0, JB_LUB[284]);
		JB_FS_AppendInt32(_fsf0, Diff);
		JB_FS_AppendString(_fsf0, JB_LUB[285]);
		JB_FS_AppendString(_fsf0, self->Name);
		JB_FS_AppendString(_fsf0, JB_LUB[286]);
		JB_FS_AppendInt32(_fsf0, NewAmount);
		JB_FS_AppendByte(_fsf0, '.');
		JB_String* _tmPf1 = JB_Incr(JB_FS_GetResult(_fsf0));
		JB_Decr(_fsf0);
		JB_PrintLine(_tmPf1);
		JB_Decr(_tmPf1);
	}
}

LeakTester* JB_Lk__Alloc() {
	return ((LeakTester*)JB_New(LeakTester));
}

LeakTester* JB_Lk__New(JB_String* name) {
	LeakTester* __rz__ = ((LeakTester*)JB_Lk__Alloc());
	if (__rz__) {
		JB_Lk_Constructor(__rz__, name);
	}
	return __rz__;
}



void JB_Mrap_ConstructorDummy(MWrap* self, int ItemCount, uint ItemSize, bool DummyParam) {
	self->DataType = kJB__TC_UnusedType;
	int Request = ItemCount * ItemSize;
	self->ItemSize = ItemSize;
	self->Length = 0;
	self->_Ptr = JB_zalloc(Request);
	self->Capacity = JB_Ternary(((bool)self->_Ptr), ItemCount, ((int)0));
	self->DeathAction = kJB__Wrap_Free;
}

void JB_Mrap_Destructor(MWrap* self) {
	JB_Mrap_Free(self);
}

void JB_Mrap_Free(MWrap* self) {
	if (self->DeathAction == kJB__Wrap_Free) {
		JB_free(self->_Ptr);
	}
	self->_Ptr = nil;
	self->Capacity = 0;
}

MWrap* JB_Mrap__Alloc() {
	return ((MWrap*)JB_New(MWrap));
}

int JB_Mrap__Init_() {
	{
	}
	;
	return 0;
}

int JB_Mrap__InitCode_() {
	return 0;
}

MWrap* JB_Mrap__NewDummy(int ItemCount, uint ItemSize, bool DummyParam) {
	MWrap* __rz__ = ((MWrap*)JB_Mrap__Alloc());
	if (__rz__) {
		JB_Mrap_ConstructorDummy(__rz__, ItemCount, ItemSize, DummyParam);
	}
	return __rz__;
}

MWrap* JB_Mrap__Object(int ItemCount, int ItemSize) {
	MWrap* rz = JB_Incr(((MWrap*)nil));
	//visible;
	JB_SetRef(rz, JB_Mrap__NewDummy(ItemCount, ItemSize, false));
	if ((!rz->_Ptr)) {
		JB_Decr(rz);
		return nil;
	}
	JB_SafeDecr(rz);
	return rz;
}



int JB_Proc__Init_() {
	{
		JB__Proc_ClosePipesInstalled = 0;
		JB__Proc_SpecialState = 0;
		JB__Proc_IncID = 0;
	}
	;
	return 0;
}

int JB_Proc__InitCode_() {
	return 0;
}


bool JB_Sav_IsSaveMarked(Saveable* self) {
	int* p = ((int*)self);
	return (((bool)(p[0] & kJB__Saver_RefMark)));
}

void JB_Sav_LoadProperties(Saveable* self, ObjectLoader* Loader) {
	Loader->CouldntLoad = self;
}

void JB_Sav_SaveCollect(Saveable* self, ObjectSaver* Saver) {
}

bool JB_Sav_SaveMark(Saveable* self) {
	int* p = ((int*)self);
	int rc = p[0];
	if (((bool)(rc & kJB__Saver_RefMark))) {
		return nil;
	}
	p[0] = (rc | kJB__Saver_RefMark);
	return true;
}

SaverClassInfo* JB_Sav_SaverInfo(Saveable* self) {
	return ((SaverClassInfo*)JB_ObjClass(self)->SaveInfo);
}

void JB_Sav_SaveWrite(Saveable* self, ObjectSaver* Saver) {
	Saver->CantSaveThis = self;
	JB_FS_AppendString(Saver->Dest, JB_LUB[287]);
}




Array* JB_Str_ByteSplit(JB_String* self) {
	Array* rz = JB_Incr(((Array*)JB_Array__New0()));
	{
		int _LoopSrcf1 = JB_Str_Length(self);
		int n = 0;
		while (n < _LoopSrcf1) {
			JB_String* _tmPf2 = JB_Incr(JB_Str__SyntaxAccess(JB_Str_ByteValue(self, n)));
			JB_Array_SyntaxAppend(rz, _tmPf2);
			JB_Decr(_tmPf2);
			n++;
		};
	}
	;
	JB_SafeDecr(rz);
	return rz;
}

CharSet* JB_Str_CharSetWithBool(JB_String* self, bool Range) {
	return JB_CS__New(self, Range);
}

Array* JB_Str_Chunk(JB_String* self, int n) {
	Array* rz = JB_Incr(((Array*)JB_Array__New0()));
	int i = 0;
	while (i < JB_Str_Length(self)) {
		JB_String* _tmPf0 = JB_Incr(JB_Str_Range(self, i, i + n));
		JB_Array_SyntaxAppend(rz, _tmPf0);
		JB_Decr(_tmPf0);
		i = (i + n);
	};
	JB_SafeDecr(rz);
	return rz;
}

JB_String* JB_Str_Compress(JB_String* self, CompressionStats* st) {
	FastString* j = JB_Incr(JB_bin__New0());
	JB_Str_CompressIntoSub(self, j, st);
	JB_String* _tmPf0 = JB_Incr(JB_FS_SyntaxCast(j));
	JB_Decr(j);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

void JB_Str_CompressIntoSub(JB_String* self, FastString* j, CompressionStats* st) {
	if ((!(st))) {
		st = JB_MzSt__all();
	}
	JB_MzSt_len(st, j->Length);
	JB_bin_jinit(j);
	JB_bin_enter(j, JB_SyxTmp, JB_LUB[288]);
	JB_bin_addint(j, JB_Str_Length(self));
	JB_bin_enter(j, JB_SyxArg, JB_LUB[0]);
	{
		Array* _LoopSrcf1 = JB_Incr(JB_Str_Chunk(self, 1048576));
		int _if0 = 0;
		while (_if0 < JB_Array_Size(_LoopSrcf1)) {
			JB_String* s = JB_Incr(((JB_String*)JB_Array_Value(_LoopSrcf1, _if0)));
			int ugh = JB_bin_OpenStream(j);
			JB_Str_CompressChunk(j, s);
			JB_bin_CloseStream(j, ugh);
			JB_MzSt_liveupdate(st, s, j->Length);
			JB_Decr(s);
			_if0++;
		};
		JB_Decr(_LoopSrcf1);
	}
	;
	JB_bin_up(j, 2);
	JB_Str_CompressChunk(j, nil);
}

int JB_Str_Count(JB_String* self, byte b) {
	int rz = 0;
	{
		byte* _Startf0 = JB_Str_Address(self);
		byte* _Endf1 = _Startf0 + JB_Str_Length(self);
		while (_Startf0 < _Endf1) {
			byte c = _Startf0[0];
			rz = (rz + (c == b));
			_Startf0++;
		};
	}
	;
	return rz;
}

JB_String* JB_Str_Decompress(JB_String* self, CompressionStats* st, int lim) {
	JB_String* rz = JB_Incr(JB_LUB[0]);
	if ((!JB_Str_IsCompressed(self))) {
		JB_Decr(rz);
		return self;
	}
	JB_SetRef(rz, JB_Str__Error());
	FastString* fs = JB_Incr(JB_FS__New());
	Message* _tmPf0 = JB_Incr(JB_Str_parse_jbin(self));
	if (JB_Str_DecompressSub(self, st, lim, _tmPf0, fs)) {
		JB_SetRef(rz, JB_FS_SyntaxCast(fs));
	}
	JB_Decr(_tmPf0);
	JB_Decr(fs);
	JB_SafeDecr(rz);
	return rz;
}

bool JB_Str_DecompressSub(JB_String* self, CompressionStats* st, int lim, Message* j, FastString* fs) {
	if ((!(st))) {
		st = JB_MzSt__all();
	}
	Message* L = ((Message*)JB_Ring_First(j));
	Message* arg = ((Message*)JB_Ring_NextSib(L));
	int64 total_size = JB_Msg_Int(L, 0);
	if ((!((JB_Msg_EqualsSyx(L, JB_SyxNum, false)) and (JB_Msg_EqualsSyx(arg, JB_SyxArg, false))))) {
		JB_Object_Fail(self, JB_LUB[289]);
		return nil;
	}
	if ((!(total_size <= lim))) {
		JB_Object_Fail(self, JB_LUB[290]);
		return nil;
	}
	JB_MzSt_len(st, JB_Msg_Length(j));
	{
		Message* _LoopSrcf2 = ((Message*)JB_Ring_NextSib(L));
		Message* C = ((Message*)JB_Tree_First_(_LoopSrcf2));
		while (C) {
			Message* _Nf1 = ((Message*)JB_Ring_NextSib(C));
			if ((!JB_Str_DecompressChunk(fs, C->Name, total_size))) {
				return nil;
			}
			JB_MzSt_liveupdate(st, C->Name, fs->Length);
			C = _Nf1;
		};
		(_LoopSrcf2);
	}
	;
	return true;
}

bool JB_Str_EndsWith(JB_String* self, JB_String* s, bool aware) {
	int n = JB_Str_Length(s);
	int L = JB_Str_Length(self);
	{
		IntRange _LoopSrcf0 = JB_int_OperatorTo(1, n);
		while (_LoopSrcf0[0] < _LoopSrcf0[1]) {
			int i = _LoopSrcf0[0];
			byte a = JB_Str_ByteValue(self, L - i);
			byte b = JB_Str_ByteValue(s, n - i);
			if (aware) {
				a = JB_byte_LowerCase(a);
				b = JB_byte_LowerCase(b);
			}
			if ((!(a == b))) {
				return nil;
			}
			_LoopSrcf0[0] = (_LoopSrcf0[0] + 1);
		};
	}
	;
	return true;
}

JB_String* JB_Str_Escape(JB_String* self) {
	return JB_Str_MultiReplaceAll(self, JB__Constants_EscapeStr, JB_StdErr);
}

JB_String* JB_Str_EscapeChr(JB_String* self) {
	return JB_Str_MultiReplaceAll(self, JB__Constants_EscapeChr, JB_StdErr);
}

bool JB_Str_EscapeTest(JB_String* self) {
	JB_String* esc = JB_Incr(JB_Str_Escape(self));
	JB_String* back = JB_Incr(JB_Str_Unescape(esc));
	JB_Decr(esc);
	bool _tmPf0 = JB_Str_Equals(back, self, false);
	JB_Decr(back);
	return ((_tmPf0));
}

Ind JB_Str_FindByte(JB_String* self, byte find, int Start, int After) {
	return JB_Str_InByte(self, Start, After, find);
}

Ind JB_Str_Find(JB_String* self, CharSet* cs, int Start, int After) {
	return JB_Str_CharSet(self, Start, After, cs, true);
}

Ind JB_Str_HiddenJBin(JB_String* self) {
	Ind nl = 0;
	if ((JB_Str_ByteValue(self, 0) == '#') and (JB_Str_ByteValue(self, 1) == '!')) {
		nl = (JB_Str_FindByte(self, '\n', 0, JB_int__max()) + 1);
		if (nl == 0) {
			return -1;
		}
	}
	if (JB_Str_IsJbin(self)) {
		return nl;
	}
	return -1;
}

Ind JB_Str_InWhite(JB_String* self, int Start, int After) {
	return JB_Str_WhiteSpace(self, Start, After, true);
}

bool JB_Str_IsCompressed(JB_String* self) {
	return JB_Str_IsJbin(self) and JB_Str_MidEquals(self, 2, JB_LUB[291], false);
}

int JB_Str_IsHexLike(JB_String* self, int N) {
	if (JB_Str_ByteValue(self, N + 0) == '0') {
		byte X = JB_Str_ByteValue(self, N + 1);
		if (JB_byte_IsLetter(X)) {
			return 2;
		}
	}
	return 0;
}

bool JB_Str_IsJbin(JB_String* self) {
	return JB_Str_OperatorStarts(self, JB__JbinHeader);
}

bool JB_Str_IsStatementName(JB_String* self) {
	return (JB_CS_OperatorContains(JB__Constants_CSWordMiddle, self)) and ((!JB_byte_IsInt(JB_Str_ByteValue(self, 0))));
}

Ind JB_Str_JBFind(JB_String* self, byte find, int Off, int After) {
	After = JB_int_OperatorMin(After, JB_Str_Length(self));
	while (Off < After) {
		byte c = JB_Str_ByteValue(self, Off++);
		if (c == '\\') {
			Off++;
		}
		 else if (c == find) {
			if (find == '$') {
				if (Off >= After) {
					break;
				}
				byte nxt = JB_Str_ByteValue(self, Off);
				if ((!(((nxt == '{') or (nxt == '.')) or JB_CS_HasChar(JB__Constants_CSWordStart, nxt)))) {
					continue;
				}
			}
			return Off - 1;
		}
	};
	return -1;
}

byte JB_Str_Last(JB_String* self, int minus) {
	return JB_Str_ByteValue(self, JB_Str_Length(self) - (1 + minus));
}

int JB_Str_LineCount(JB_String* self) {
	if ((!JB_Str_Exists(self))) {
		return 1;
	}
	return JB_Str_Count(self, '\n') + 1;
}

bool JB_Str_ContainsString(JB_String* self, JB_String* s) {
	return JB_Ind_SyntaxCast(JB_Str_InStr(self, s, 0, JB_int__max(), true));
}

bool JB_Str_OperatorEndsWith(JB_String* self, JB_String* s) {
	return JB_Str_EndsWith(self, s, true);
}

bool JB_Str_OperatorStarts(JB_String* self, JB_String* s) {
	return JB_Str_MidEquals(self, 0, s, true);
}

Ind JB_Str_OutCharSet(JB_String* self, CharSet* cs, int Start, int After) {
	return JB_Str_CharSet(self, Start, After, cs, false);
}

Ind JB_Str_OutWhite(JB_String* self, int Start, int After) {
	return JB_Str_WhiteSpace(self, Start, After, false);
}

Message* JB_Str_Parse(JB_String* self, Syntax owner, bool AllowDecomp) {
	JB_String* data = JB_Incr(((JB_String*)JB_Ternary(AllowDecomp and JB_Str_IsCompressed(self), ((JB_String*)JB_Str_Decompress(self, nil, 268435456)), ((JB_String*)self))));
	Ind j = JB_Str_HiddenJBin(data);
	if (JB_Ind_SyntaxCast(j)) {
		JB_String* _tmPf0 = JB_Incr(JB_Str_Range(data, j, JB_int__max()));
		JB_Decr(data);
		Message* _tmPf1 = JB_Incr(JB_Str_parse_jbin(_tmPf0));
		JB_Decr(_tmPf0);
		JB_SafeDecr(_tmPf1);
		return _tmPf1;
	}
	if ((!JB_Tk__CppInited())) {
		JB_Tk__Init();
	}
	JB_Tk__StartParse(data);
	JB_Decr(data);
	JB__Tk_StopBars = 0;
	int Count = JB_StdErr->ErrorCount;
	int Flags = kJB__Tk_Temporal;
	Message* into = JB_Incr(JB_Msg__NewRange(nil, owner, 0, JB_LUB[0], 0));
	bool lines = JB_Tk__ParseLoopFlags(into, JB_LUB[0], Flags);
	if ((!lines) and JB_Ring_HasChildCount(into, 1)) {
		JB_SetRef(into, ((Message*)JB_Ring_First(into)));
	}
	JB_Tk__CleanSpaces();
	if (JB_Tk__Running()) {
		JB_Tk__Expect(0);
	}
	JB_Tk__StopParse();
	if (Count != JB_StdErr->ErrorCount) {
		JB_SetRef(into, nil);
	}
	JB_SafeDecr(into);
	return ((Message*)into);
}

Message* JB_Str_parse_jbin(JB_String* self) {
	StringStream* _tmPf0 = JB_Incr(JB_Str_reader(self, JB_LUB[0]));
	Message* _tmPf1 = JB_Incr(JB_ss_Parse_Jbin(_tmPf0));
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Message* JB_Str_ParseWithError(JB_String* self, JB_Error** rec) {
	Message* rz = ((Message*)nil);
	//visible;
	JB_ErrorReceiver* old = JB_StdErr;
	JB_StdErr = ({
		JB_ErrorReceiver* _X = JB__Constants_ParseProtector;
		if ((!_X)) {
			_X = JB_Rec__New();
			JB_SetRef(JB__Constants_ParseProtector, _X);
		}
		 _X;
	});
	JB_Rec_Clear(JB_StdErr);
	rz = JB_Str_Parse(self, JB_SyxArg, true);
	JB_SetRef((*rec), JB_Rec_Pop(JB_StdErr));
	JB_StdErr = old;
	return rz;
}

StringStream* JB_Str_reader(JB_String* self, JB_String* T) {
	StringStream* _tmPf0 = JB_Incr(JB_ss__New(self));
	StringStream* _tmPf1 = JB_Incr(JB_ss_test(_tmPf0, 0, T));
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Array* JB_Str_Split(JB_String* self, byte sep) {
	Array* rz = JB_Incr(((Array*)JB_Array__New0()));
	{
		StringFields* _LoopSrcf2 = JB_Incr(JB_FI__New(self, sep));
		int _Prevf0 = 0;
		while (_LoopSrcf2->Data != nil) {
			Ind _Curr_f1 = JB_FI_NextSep(_LoopSrcf2, _Prevf0);
			JB_String* field = JB_Incr(JB_FI_Field(_LoopSrcf2, _Prevf0, _Curr_f1));
			JB_Array_SyntaxAppend(rz, field);
			JB_Decr(field);
			_Prevf0 = (_Curr_f1 + 1);
			if ((!JB_Ind_SyntaxCast(_Curr_f1))) {
				break;
			}
		};
		JB_Decr(_LoopSrcf2);
	}
	;
	JB_SafeDecr(rz);
	return rz;
}

JB_String* JB_Str_Squeeze(JB_String* self) {
	//visible;
	FastString* fs = JB_Incr(JB_FS__New());
	bool broken = false;
	{
		byte* _Startf0 = JB_Str_Address(self);
		byte* _Endf1 = _Startf0 + JB_Str_Length(self);
		while (_Startf0 < _Endf1) {
			byte c = _Startf0[0];
			if (JB_byte_IsWhite(c)) {
				broken = ((bool)fs->Length);
			}
			 else {
				if (broken) {
					JB_FS_AppendByte(fs, ' ');
				}
				JB_FS_AppendByte(fs, c);
				broken = false;
			}
			_Startf0++;
		};
	}
	;
	JB_String* _tmPf3 = JB_Incr(JB_FS_SyntaxCast(fs));
	JB_Decr(fs);
	JB_SafeDecr(_tmPf3);
	return _tmPf3;
}

void JB_Str_SyntaxExpect(JB_String* self) {
	//visible;
	JB_Rec_NewErrorWithNode(JB_StdErr, nil, self, nil);
}

JB_String* JB_Str_Unescape(JB_String* self) {
	return JB_Str_MultiReplaceAll(self, JB__Constants_UnEscapeStr, JB_StdErr);
}

CharSet* JB_Str_UniCS(JB_String* self) {
	JB_String* _tmPf0 = JB_Incr(JB_Str_OperatorPlus(self, JB_LUB[292]));
	CharSet* _tmPf1 = JB_Incr(JB_Str_CharSetWithBool((_tmPf0), true));
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Array* JB_Str_Words(JB_String* self) {
	return JB_Str_Split(self, ' ');
}

JB_String* JB_Str__FromC(_cstring Addr) {
	return JB_StrC(Addr);
}

JB_String* JB_Str__SyntaxAccess(int b) {
	return JB_Str__Byte(b);
}



void JB_FI_Constructor(StringFields* self, JB_String* Source, byte Sep) {
	self->Data = JB_Incr(Source);
	self->Sep = Sep;
}

void JB_FI_destructor(StringFields* self) {
	JB_Decr(self->Data);
}

JB_String* JB_FI_Field(StringFields* self, Ind Prev, Ind Curr) {
	if ((!(JB_Ind_SyntaxCast(Curr)))) {
		Curr = JB_Str_Length(self->Data);
	}
	return JB_Str_Range(self->Data, Prev, Curr);
}

Ind JB_FI_NextSep(StringFields* self, int Prev) {
	return JB_Str_FindByte(self->Data, self->Sep, Prev, JB_int__max());
}

StringFields* JB_FI__Alloc() {
	return ((StringFields*)JB_New(StringFields));
}

StringFields* JB_FI__New(JB_String* Source, byte Sep) {
	StringFields* __rz__ = ((StringFields*)JB_FI__Alloc());
	if (__rz__) {
		JB_FI_Constructor(__rz__, Source, Sep);
	}
	return __rz__;
}



byte JB_ss_Byte(StringStream* self) {
	JB_ss_Need(self, 1);
	return JB_Str_ByteValue(self->Data, self->Position++);
}

void JB_ss_Constructor(StringStream* self, JB_String* d) {
	JB_Incr(d);
	JB_String* _tmPf0 = JB_LUB[0];
	self->FilePath = JB_Incr(_tmPf0);
	self->Position = 0;
	self->ChunkSize = 0;
	if ((!(JB_Str_Exists(d)))) {
		JB_SetRef(d, JB_LUB[0]);
	}
	self->Data = JB_Incr(d);
	self->Length = JB_Str_Length(d);
	JB_Decr(d);
}

void JB_ss_destructor(StringStream* self) {
	JB_Decr(self->Data);
	JB_Decr(self->FilePath);
}

int64 JB_ss_lint0(StringStream* self, int n) {
	int64 rz = 0;
	{
		int _LoopSrcf1 = n + 1;
		int i = 0;
		while (i < _LoopSrcf1) {
			rz = (rz | (JB_ss_Byte(self) << (i << 3)));
			i++;
		};
	}
	;
	return rz;
}

void JB_ss_Need(StringStream* self, int n) {
}

Message* JB_ss_parse_(StringStream* self) {
	Message* rz = JB_Incr(((Message*)nil));
	StringStream* _tmPf1 = JB_Incr(JB_ss_test(self, 0, JB__JbinHeader));
	if ((!JB_ss_SyntaxCast(_tmPf1))) {
		JB_Decr(rz);
		JB_Decr(_tmPf1);
		return nil;
	}
	JB_Decr(_tmPf1);
	Message* Curr = nil;
	while (JB_ss_SyntaxCast(self)) {
		uint info = JB_ss_Byte(self);
		uint L = info & 63;
		uint Dir = info >> 6;
		if (Dir == 3) {
			Message* _tmPf0 = JB_Incr(((Message*)JB_Tree_Upward(Curr, L)));
			if ((!_tmPf0)) {
				JB_Decr(_tmPf0);
				break;
			}
			JB_SetRef(Curr, _tmPf0);
			JB_Decr(_tmPf0);
		}
		 else {
			if (L >= 60) {
				L = JB_ss_lint0(self, L - 60);
			}
			byte type = JB_ss_Byte(self);
			JB_String* _tmPf2 = JB_Incr(JB_ss_Str(self, L, 0));
			Message* msg = JB_Incr(JB_Msg_Msg(Curr, ((Syntax)type), _tmPf2));
			JB_Decr(_tmPf2);
			if (msg->Func > JB_SyxBin) {
				if ((!false)) {
					JB_Msg_SyntaxExpect(msg, JB_LUB[293]);
				}
				msg->Func = JB_SyxTmp;
			}
			if ((!(rz))) {
				JB_SetRef(rz, msg);
			}
			if ((!Curr) or (Dir == 1)) {
				JB_SetRef(Curr, msg);
			}
			JB_Decr(msg);
		}
	};
	JB_Decr(Curr);
	JB_SafeDecr(rz);
	return rz;
}

Message* JB_ss_Parse_Jbin(StringStream* self) {
	Message* _tmPf0 = JB_Incr(JB_ss_parse_(self));
	if ((!_tmPf0)) {
		JB_ss_SyntaxExpect(self, JB_LUB[294]);
		JB_Decr(_tmPf0);
		return nil;
	}
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

JB_String* JB_ss_Str(StringStream* self, int n, int skip) {
	JB_ss_Need(self, n);
	int p = self->Position;
	int p2 = p + n;
	self->Position = p2;
	return JB_Str_Range(self->Data, p + skip, p2);
}

void JB_ss_SyntaxExpect(StringStream* self, JB_String* Error) {
	JB_DoAt(1);
	if (JB_Str_Exists(self->FilePath)) {
		JB_Rec_NewErrorWithNode(JB_StdErr, nil, JB_LUB[295], self->FilePath);
	}
	 else {
		JB_Rec_NewErrorWithNode(JB_StdErr, nil, JB_LUB[296], JB_LUB[0]);
	}
}

StringStream* JB_ss_test(StringStream* self, int a, JB_String* b) {
	if ((!JB_Str_Exists(b)) or (({
		JB_String* _tmP128 = JB_Incr(JB_ss_Str(self, JB_Str_Length(b), 0));
		bool _tmP127 = JB_Str_Equals(_tmP128, b, false);
		JB_Decr(_tmP128);
		 _tmP127;
	}))) {
		return self;
	}
	return nil;
}

StringStream* JB_ss__Alloc() {
	return ((StringStream*)JB_New(StringStream));
}

StringStream* JB_ss__New(JB_String* d) {
	StringStream* __rz__ = ((StringStream*)JB_ss__Alloc());
	if (__rz__) {
		JB_ss_Constructor(__rz__, d);
	}
	return __rz__;
}


void JB_Fn_Constructor(SyntaxObj* self, fpMsgRender msg, JB_String* name, int ID) {
	JB_String* _tmPf0 = JB_LUB[0];
	self->LongName = JB_Incr(_tmPf0);
	self->RenderAddr = msg;
	self->Name = JB_Incr(name);
	self->ID = ((Syntax)ID);
	self->ExportAddr = JB_Msg_Dummy;
}

void JB_Fn_destructor(SyntaxObj* self) {
	JB_Decr(self->Name);
	JB_Decr(self->LongName);
}

JB_String* JB_Fn_Render(SyntaxObj* self, FastString* fs_in) {
	if ((!(fs_in))) {
		return JB_Str_LowerCase(self->LongName);
	}
	JB_String* _tmPf0 = JB_Incr(JB_Str_LowerCase(self->LongName));
	JB_FS_AppendString(fs_in, _tmPf0);
	JB_Decr(_tmPf0);
	return JB_LUB[0];
}

SyntaxObj* JB_Fn__Alloc() {
	return ((SyntaxObj*)JB_New(SyntaxObj));
}

SyntaxObj* JB_Fn__New(fpMsgRender msg, JB_String* name, int ID) {
	SyntaxObj* __rz__ = ((SyntaxObj*)JB_Fn__Alloc());
	if (__rz__) {
		JB_Fn_Constructor(__rz__, msg, name, ID);
	}
	return __rz__;
}



void JB_Array_LoadProperties(Array* self, ObjectLoader* Loader) {
	while (JB_LD_HasItem(Loader)) {
		JB_Array_SyntaxAppend(self, JB_LD_Object(Loader));
	};
}

void JB_Array_SaveCollect(Array* self, ObjectSaver* Saver) {
	{
		int _if0 = 0;
		while (_if0 < JB_Array_Size(self)) {
			JB_Object* v = JB_Array_Value(self, _if0);
			JB_Object_SaveTryCollect(v, Saver);
			_if0++;
		};
	};
}

void JB_Array_SaveWrite(Array* self, ObjectSaver* Saver) {
	FastString* D = Saver->Dest;
	{
		int _if0 = 0;
		int _firstf2 = _if0;
		while (_if0 < JB_Array_Size(self)) {
			JB_Object* v = JB_Array_Value(self, _if0);
			if (_firstf2 != _if0) {
				JB_FS_AppendString(D, JB_LUB[297]);
			}
			//start;
			JB_FS_AppendObjectOrNil(D, v);
			_if0++;
		};
	};
}

void JB_Array_SyntaxAppend(Array* self, JB_Object* item) {
	JB_Array_AppendCount(self, item, 1);
}

Array* JB_Array__Alloc() {
	return ((Array*)JB_New(Array));
}

Array* JB_Array__New0() {
	Array* __rz__ = ((Array*)JB_Array__Alloc());
	if (__rz__) {
		JB_Array_Constructor0(__rz__);
	}
	return __rz__;
}


void JB_Dict_LoadProperties(Dictionary* self, ObjectLoader* Loader) {
	while (JB_LD_HasItem(Loader)) {
		JB_String* name = JB_LD_ItemName(Loader);
		if (JB_LD_ItemIsInt(Loader)) {
			(JB_Dict_ValueSet(self, name, JB_Wrap__NewInt(JB_LD_ItemInt(Loader))));
		}
		 else {
			(JB_Dict_ValueSet(self, name, JB_LD_ItemObject(Loader)));
		}
	};
}

void JB_Dict_SaveCollect(Dictionary* self, ObjectSaver* Saver) {
	{
		DictionaryReader* _navf0 = JB_Dict_Navigate(self);
		while (JB_Nav_MoveNext(_navf0)) {
			JB_Object* v = JB_Nav_Value(_navf0);
			JB_Object_SaveTryCollect(v, Saver);
		};
	};
}

void JB_Dict_SaveWrite(Dictionary* self, ObjectSaver* Saver) {
	FastString* D = Saver->Dest;
	DictionaryReader* L = JB_Dict_Navigate(self);
	while (JB_DictionaryReader_SyntaxCast(L)) {
		JB_FS_AppendString(D, JB_Nav_Name(L));
		JB_FS_AppendString(D, JB_LUB[276]);
		JB_FS_AppendObjectOrNil(D, JB_Nav_Value(L));
		JB_FS_AppendByte(D, ',');
	};
}

JB_Object* JB_Dict_ValueStr(Dictionary* self, JB_String* Key) {
	return JB_Dict_Value(self, Key, nil);
}

void JB_Dict_SetInt(Dictionary* self, uint64 Key, JB_Object* Value) {
	(JB_Dict_ValueSet(self, JB_int64_DictName(((int64)Key)), Value));
}

JB_Object* JB_Dict_ValueInt(Dictionary* self, uint64 Key) {
	return JB_Dict_ValueStr(self, JB_int64_DictName(((int64)Key)));
}

JB_Object* JB_Dict_ValueLower(Dictionary* self, JB_String* s) {
	JB_String* _tmPf0 = JB_Incr(JB_Str_LowerCase(s));
	JB_Object* _tmPf1 = JB_Incr(JB_Dict_ValueStr(self, _tmPf0));
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Dictionary* JB_Dict__Alloc() {
	return ((Dictionary*)JB_New(Dictionary));
}

Dictionary* JB_Dict__Copy(Dictionary* Dict) {
	Dictionary* rz = JB_Incr(((Dictionary*)nil));
	JB_SetRef(rz, JB_Dict__New());
	{
		DictionaryReader* _navf0 = JB_Incr(JB_Dict_Navigate(Dict));
		while (JB_Nav_MoveNext(_navf0)) {
			JB_String* key = JB_Incr(JB_Nav_Name(_navf0));
			JB_String* value = JB_Incr(((JB_String*)JB_Nav_Value(_navf0)));
			(JB_Dict_ValueSet(rz, key, value));
			JB_Decr(value);
			JB_Decr(key);
		};
		JB_Decr(_navf0);
	}
	;
	JB_SafeDecr(rz);
	return rz;
}

Dictionary* JB_Dict__New() {
	Dictionary* __rz__ = ((Dictionary*)JB_Dict__Alloc());
	if (__rz__) {
		JB_Dict_Constructor(__rz__);
	}
	return __rz__;
}

Dictionary* JB_Dict__Reverse(Dictionary* Dict) {
	Dictionary* rz = JB_Incr(((Dictionary*)nil));
	JB_SetRef(rz, JB_Dict__New());
	{
		DictionaryReader* _navf0 = JB_Incr(JB_Dict_Navigate(Dict));
		while (JB_Nav_MoveNext(_navf0)) {
			JB_String* key = JB_Incr(JB_Nav_Name(_navf0));
			JB_String* value = JB_Incr(((JB_String*)JB_Nav_Value(_navf0)));
			(JB_Dict_ValueSet(rz, value, key));
			JB_Decr(value);
			JB_Decr(key);
		};
		JB_Decr(_navf0);
	}
	;
	JB_SafeDecr(rz);
	return rz;
}


int JB_File__Init_() {
	{
		JB__File_DebugExecute = false;
	}
	;
	return 0;
}

int JB_File__InitCode_() {
	return 0;
}


void JB_bin_add(FastString* self, Syntax type, JB_String* data, bool into) {
	int L = JB_Str_Length(data);
	JB_bin_AddMemory(self, type, into, ((byte*)JB_Ternary(((bool)L), data->Addr, nil)), L);
}

void JB_bin_addint(FastString* self, int64 data) {
	JB_String* _tmPf0 = JB_Incr(JB_int64_Render(data, nil));
	JB_bin_add(self, JB_SyxNum, _tmPf0, false);
	JB_Decr(_tmPf0);
}

void JB_bin_AddMemory(FastString* self, Syntax type, bool GoIn, byte* data, uint64 L) {
	uint info = 128 >> GoIn;
	int L2 = JB_Ternary(L < 60, ((int)L), 60 + JB_uint64_lelength(L));
	JB_FS_AppendByte(self, ((byte)(info | L2)));
	if (L >= 60) {
		JB_FS_lint(self, L);
	}
	JB_FS_AppendByte(self, ((byte)type));
	if (data) {
		JB_FS_AppendMem_(self, data, ((int)L));
	}
}

void JB_bin_CloseStream(FastString* self, int c) {
	int nwe = self->Length;
	self->Length = (c - 6);
	JB_FS_AppendByte(self, ((byte)191));
	JB_FS_AppendInteger(self, nwe - c);
	JB_FS_AppendByte(self, ((byte)(JB_SyxBin)));
	self->Length = nwe;
}

void JB_bin_Constructor0(FastString* self) {
	JB_FS_Constructor(self);
}

void JB_bin_enter(FastString* self, Syntax type, JB_String* data) {
	JB_bin_add(self, type, data, true);
}

void JB_bin_jinit(FastString* self) {
	self->Length = 0;
	JB_FS_AppendString(self, JB__JbinHeader);
}

int JB_bin_OpenStream(FastString* self) {
	JB_bin_AddMemory(self, JB_SyxBin, false, nil, 1073741824);
	return self->Length;
}

void JB_bin_sheb(FastString* self, JB_String* data) {
	if (JB_Str_Exists(data)) {
		JB_FS_AppendByte(self, '#');
		JB_FS_AppendByte(self, '!');
		JB_FS_AppendString(self, data);
		JB_FS_AppendByte(self, '\n');
	}
}

void JB_bin_up(FastString* self, int amount) {
	while (amount > 0) {
		int less = JB_int_OperatorMin(amount, 63);
		JB_FS_AppendByte(self, ((byte)(less | 192)));
		amount = (amount - less);
	};
}

FastString* JB_bin__New0() {
	FastString* __rz__ = ((FastString*)JB_FS__Alloc());
	if (__rz__) {
		JB_bin_Constructor0(__rz__);
	}
	return __rz__;
}


void JB_Tree_Clear(RingTree* self) {
	while (true) {
		RingTree* _tmPf0 = JB_Ring_First(self);
		if ((!_tmPf0)) {
			return;
		}
		JB_Tree_Remove(_tmPf0);
	};
}

RingTree* JB_Tree_First_(RingTree* self) {
	if (self) {
		return JB_Ring_First(self);
	}
	return nil;
}

bool JB_Tree_HasOneChild(RingTree* self) {
	return JB_Ring_HasChildCount(self, 1);
}

__lib__ void jdb2(RingTree* self) {
	//visible;
	if (self) {
		JB_String* _tmPf0 = JB_Incr(JB_Msg_jdb_(((Message*)self), nil, 1));
		JB_PrintLine(_tmPf0);
		JB_Decr(_tmPf0);
	}
	 else {
		JB_PrintLine(JB_LUB[298]);
	}
}

__lib__ void jdb3(RingTree* self) {
	//visible;
	if (self) {
		JB_String* _tmPf0 = JB_Incr(JB_Msg_jdb_(((Message*)self), nil, 3));
		JB_PrintLine(_tmPf0);
		JB_Decr(_tmPf0);
	}
	 else {
		JB_PrintLine(JB_LUB[298]);
	}
}

RingTree* JB_Tree_Pop(RingTree* self) {
	RingTree* rz = nil;
	JB_SetRef(rz, JB_Ring_Last(self));
	if (rz) {
		JB_Tree_Remove(rz);
	}
	JB_SafeDecr(rz);
	return rz;
}

void JB_Tree_Remove(RingTree* self) {
	(JB_Ring_ParentSet(self, nil));
}

JB_String* JB_Tree_Render(RingTree* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_AppendByte(fs, '(');
	{
		RingTree* f = JB_Incr(JB_Tree_First_(self));
		while (f) {
			RingTree* _Nf1 = JB_Incr(((RingTree*)JB_Ring_NextSib(f)));
			JB_FreeIfDead(JB_Object___Render__(f, fs));
			JB_FS_AppendByte(fs, ',');
			JB_FS_AppendByte(fs, ' ');
			JB_SetRef(f, _Nf1);
			JB_Decr(_Nf1);
		};
		JB_Decr(f);
		(self);
	}
	;
	JB_FS_AppendByte(fs, ')');
	JB_String* _tmPf2 = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmPf2);
	return _tmPf2;
}

RingTree* JB_Tree_Second(RingTree* self) {
	RingTree* x = JB_Ring_First(self);
	if (x) {
		return JB_Ring_NextSib(x);
	}
	return nil;
}

void JB_Tree_SyntaxAppend(RingTree* self, RingTree* Last) {
	(JB_Ring_LastSet(self, Last));
}

RingTree* JB_Tree_Upward(RingTree* self, int n) {
	RingTree* rz = nil;
	rz = self;
	while (((bool)rz) and (n-- >= 1)) {
		rz = JB_Ring_Parent(rz);
	};
	return rz;
}


void JB_sci_destructor(SaverClassInfo* self) {
	JB_Decr(self->NextInfo);
	JB_Array_Destructor(self);
}





void JB_Msg_Acc__(Message* self, FastString* fs) {
	Message* f = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_SyntaxAppend(fs, f);
	Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_NextSib(f)));
	JB_Decr(f);
	JB_Msg_RenderPrm(_tmPf0, fs, '[', ']');
	JB_Decr(_tmPf0);
}

void JB_Msg_CantFind(Message* self, Syntax s, JB_String* name, Message* found) {
	if ((!self)) {
		JB_API__NilHandler();
		return;
	}
	FastString* fs = JB_Incr(JB_FS__New());
	if (found) {
		JB_FS_AppendString(fs, JB_LUB[299]);
		JB_FS_MsgErrorName(fs, name);
		JB_String* _tmPf0 = JB_Incr(JB_Syx_Name(s));
		JB_FS_AppendString(fs, _tmPf0);
		JB_Decr(_tmPf0);
		JB_FS_AppendString(fs, JB_LUB[300]);
		JB_String* _tmPf1 = JB_Incr(JB_Syx_Name(found->Func));
		JB_FS_AppendString(fs, _tmPf1);
		JB_Decr(_tmPf1);
	}
	 else {
		if (s) {
			JB_FS_AppendString(fs, JB_LUB[301]);
			JB_FS_AppendByte(fs, '@');
			JB_String* _tmPf2 = JB_Incr(JB_Syx_Name(s));
			JB_FS_AppendString(fs, _tmPf2);
			JB_Decr(_tmPf2);
		}
		 else {
			JB_FS_AppendString(fs, JB_LUB[302]);
		}
		JB_FS_MsgErrorName(fs, name);
		found = self;
	}
	JB_String* _tmPf3 = JB_Incr(JB_FS_GetResult(fs));
	JB_Decr(fs);
	JB_Rec_NewErrorWithNode(JB_StdErr, found, _tmPf3, nil);
	JB_Decr(_tmPf3);
}

void JB_Msg_Adj__(Message* self, FastString* fs) {
	Message* f = ((Message*)JB_Ring_First(self));
	Message* l = ((Message*)JB_Ring_NextSib(f));
	JB_FS_SyntaxAppend(fs, f);
	JB_FS_AppendString(fs, JB_LUB[303]);
	JB_FS_SyntaxAppend(fs, l);
}

int JB_Msg_After(Message* self) {
	return self->Position + self->Extra;
}

void JB_Msg_AfterSet(Message* self, int Value) {
	self->Extra = ((Value - self->Position) | JB__Tk_BaseExtra);
}

void JB_Msg_ARel__(Message* self, FastString* fs) {
	Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_SyntaxAppend(fs, _tmPf0);
	JB_Decr(_tmPf0);
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_Arg__(Message* self, FastString* fs) {
	bool Braces = (JB_Msg_SyntaxIs(self, kJB__MsgUIFlags_Style2)) or ((!JB_Ring_HasChildren(self)) or (JB_Msg_OperatorIn(self, JB_SyxArg)));
	if (Braces) {
		JB_FS_AppendByte(fs, '{');
	}
	JB_Msg_FSListArg(self, fs);
	if (Braces) {
		JB_FS_AppendIndent(fs);
		JB_FS_AppendByte(fs, '}');
	}
}

void JB_Msg_Arr__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '[');
	JB_Msg_FSListSep(self, fs, JB_LUB[297]);
	JB_FS_AppendByte(fs, ']');
}

void JB_Msg_Ask__(Message* self, FastString* fs) {
	JB_Msg_BinnRender(self, fs, JB_LUB[129], JB_LUB[0]);
}

void JB_Msg_Back__(Message* self, FastString* fs) {
	if (JB_Ind_SyntaxCast(JB_Str_FindByte(self->Name, '`', 0, JB_int__max()))) {
		JB_Msg_Str__(self, fs);
	}
	 else {
		JB_FS_AppendByte(fs, '`');
		JB_FS_AppendString(fs, self->Name);
		JB_FS_AppendByte(fs, '`');
	}
}

void JB_Msg_Badj__(Message* self, FastString* fs) {
	Message* f = ((Message*)JB_Ring_First(self));
	Message* l = ((Message*)JB_Ring_NextSib(f));
	JB_FS_SyntaxAppend(fs, l);
	JB_FS_AppendString(fs, JB_LUB[304]);
	JB_FS_SyntaxAppend(fs, f);
}

void JB_Msg_BecomeStr(Message* self, Syntax fn, JB_String* name) {
	self->Func = fn;
	JB_SetRef(self->Name, name);
}

void JB_Msg_Bin__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_LUB[123]);
	JB_FS_AppendHexStr(fs, self->Name);
	JB_FS_AppendString(fs, JB_LUB[72]);
}

void JB_Msg_binn__(Message* self, FastString* fs) {
	JB_Msg_BinnRender(self, fs, JB_LUB[305], JB_LUB[0]);
}

void JB_Msg_BinnRender(Message* self, FastString* fs, JB_String* sepa, JB_String* sepb) {
	Message* f = ((Message*)JB_Ring_First(self));
	if ((!f)) {
		return;
	}
	Message* opp = ((Message*)JB_Ring_NextSib(f));
	if ((!opp)) {
		return;
	}
	Message* l = ((Message*)JB_Ring_NextSib(opp));
	Message* OF = ((Message*)JB_Ring_First(opp));
	JB_FS_AppendString(fs, sepa);
	JB_FS_SyntaxAppend(fs, ((Message*)JB_Ternary(((bool)OF), OF, opp)));
	JB_FS_AppendByte(fs, ' ');
	JB_FS_SyntaxAppend(fs, f);
	if ((!OF)) {
		if ((!(!l))) {
			debugger;
		}
		return;
	}
	Message* ON = ((Message*)JB_Ring_NextSib(OF));
	if (ON) {
		JB_FS_AppendByte(fs, ' ');
		JB_FS_SyntaxAppend(fs, ON);
	}
	if (l) {
		JB_FS_AppendByte(fs, ' ');
		JB_FS_SyntaxAppend(fs, l);
	}
}

void JB_Msg_Bra__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '(');
	Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_SyntaxAppend(fs, _tmPf0);
	JB_Decr(_tmPf0);
	JB_FS_AppendByte(fs, ')');
}

void JB_Msg_BRel__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
	Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_SyntaxAppend(fs, _tmPf0);
	JB_Decr(_tmPf0);
}

void JB_Msg_Char__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '\'');
	JB_String* _tmPf0 = JB_Incr(JB_Str_EscapeChr(self->Name));
	JB_FS_AppendString(fs, _tmPf0);
	JB_Decr(_tmPf0);
	JB_FS_AppendByte(fs, '\'');
}

int JB_Msg_CleanIndent(Message* self) {
	return self->Indent & (~1);
}

void JB_Msg_Cnj__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '#');
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_ConstructorBasic(Message* self) {
	JB_Ring_Constructor0(self);
	JB_String* _tmPf0 = JB_LUB[0];
	self->Name = JB_Incr(_tmPf0);
	self->Obj = nil;
	self->Indent = 0;
	self->Extra = 0;
	self->Position = JB__Tk_UsingPos;
	self->Func = JB_SyxArg;
	self->Flags = JB__Tk_InsertedFlags;
}

void JB_Msg_ConstructorCopy(Message* self, Message* other) {
	JB_Ring_Constructor0(self);
	self->Position = other->Position;
	if ((!JB_Ind_SyntaxCast(self->Position))) {
		self->Position = JB__Tk_UsingPos;
	}
	self->Func = other->Func;
	self->Flags = (other->Flags | JB__Tk_InsertedFlags);
	JB_String* _tmPf0 = other->Name;
	self->Name = JB_Incr(_tmPf0);
	self->Obj = other->Obj;
	self->Indent = other->Indent;
	self->Extra = other->Extra;
}

void JB_Msg_ConstructorNormal(Message* self, Syntax Func, JB_String* Name) {
	JB_Ring_Constructor0(self);
	self->Obj = nil;
	self->Indent = 0;
	self->Position = JB__Tk_UsingPos;
	self->Func = Func;
	self->Flags = JB__Tk_InsertedFlags;
	self->Extra = JB_Ternary(self->Position < 0, JB_Str_Length(Name), ((int)JB__Tk_UsingExtra));
	self->Name = JB_Incr(Name);
}

void JB_Msg_ConstructorRange(Message* self, Message* Parent, Syntax Func, int BytePos, JB_String* name, int Extra) {
	JB_Ring_Constructor(self, Parent);
	self->Obj = nil;
	self->Indent = 0;
	self->Position = BytePos;
	self->Flags = JB__Tk_InsertedFlags;
	self->Func = Func;
	self->Extra = (Extra | JB__Tk_BaseExtra);
	self->Name = JB_Incr(name);
}

Message* JB_Msg_NiceCopy(Message* self, Message* L) {
	if (self) {
		if ((!L)) {
			return JB_Msg_Copy_(self, nil, JB_ObjLayer(self));
		}
		return JB_Msg_Copy_(self, L, JB_ObjLayer(L));
	}
	return nil;
}

Message* JB_Msg_Copy_(Message* self, Message* pos_msg, JB_MemoryLayer* L) {
	Message* rz = nil;
	rz = JB_Msg__NewWithLayerCopy(L, self);
	if (pos_msg) {
		rz->Position = pos_msg->Position;
	}
	{
		Message* v = ((Message*)JB_Tree_First_(self));
		while (v) {
			Message* _Nf1 = ((Message*)((Message*)JB_Ring_NextSib(v)));
			JB_Tree_SyntaxAppend(rz, JB_Msg_Copy_(v, pos_msg, L));
			v = _Nf1;
		};
		(self);
	}
	;
	return rz;
}

JB_String* JB_Msg_copyid(Message* self) {
	return nil;
}

void JB_Msg_Decl__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_AppendByte(fs, '|');
	JB_FS_SyntaxAppend(fs, ch);
	JB_FS_AppendByte(fs, '|');
	JB_SetRef(ch, ((Message*)JB_Ring_NextSib(ch)));
	while (ch) {
		JB_FS_AppendByte(fs, ' ');
		JB_FS_SyntaxAppend(fs, ch);
		JB_SetRef(ch, ((Message*)JB_Ring_NextSib(ch)));
	};
	JB_Decr(ch);
}

void JB_Msg_destructor(Message* self) {
	JB_Decr(self->Name);
	JB_Ring_Destructor(self);
}

void JB_Msg_Dot__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_SyntaxAppend(fs, ch);
	JB_FS_AppendByte(fs, '.');
	JB_FS_AppendString(fs, self->Name);
	Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
	JB_Decr(ch);
	JB_FS_SyntaxAppend(fs, _tmPf0);
	JB_Decr(_tmPf0);
}

void JB_Msg_Dummy(Message* self, FastString* fs) {
}

void JB_Msg_Emb__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
	if ((!JB_Ring_HasChildren(self))) {
		return;
	}
	JB_Msg_RenderWithSpaces(self, fs, nil);
}

void JB_Msg_ERel__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_SyntaxAppend(fs, ch);
	JB_FS_AppendByte(fs, ' ');
	JB_SetRef(ch, ((Message*)JB_Ring_NextSib(ch)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_SyntaxAppend(fs, ch);
	JB_FS_AppendString(fs, JB_LUB[306]);
	JB_SetRef(ch, ((Message*)JB_Ring_NextSib(ch)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_SyntaxAppend(fs, ch);
	JB_Decr(ch);
}

bool JB_Msg_Expect(Message* self, Syntax type, JB_String* name) {
	if ((!self)) {
		return nil;
	}
	if ((!type) or (self->Func == type)) {
		if ((name == nil) or ((JB_Str_Equals(self->Name, name, true)))) {
			return true;
		}
	}
	FastString* fs = JB_Incr(JB_FS__New());
	JB_FS_AppendString(fs, JB_LUB[147]);
	if (type) {
		JB_String* _tmPf0 = JB_Incr(JB_Syx_LongName(type));
		JB_FS_AppendString(fs, _tmPf0);
		JB_Decr(_tmPf0);
	}
	JB_FS_MsgErrorName(fs, name);
	JB_FS_AppendString(fs, JB_LUB[307]);
	JB_String* _tmPf1 = JB_Incr(JB_Syx_LongName(self->Func));
	JB_FS_AppendString(fs, _tmPf1);
	JB_Decr(_tmPf1);
	JB_FS_MsgErrorName(fs, self->Name);
	if ((!false)) {
		JB_String* _tmPf2 = JB_Incr(JB_FS_SyntaxCast(fs));
		JB_Msg_SyntaxExpect(self, _tmPf2);
		JB_Decr(_tmPf2);
	}
	JB_Decr(fs);
	return false;
}

bool JB_Msg_ExpectLast(Message* self, JB_String* err) {
	if ((!self)) {
		return nil;
	}
	Message* N = JB_Incr(((Message*)JB_Ring_NextSib(self)));
	if ((!(N))) {
		JB_Decr(N);
		return true;
	}
	JB_Msg_SyntaxExpect(N, err);
	JB_Decr(N);
	return false;
}

void JB_Msg_File__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
	self->Indent++;
	{
		Message* ch = ((Message*)JB_Tree_First_(self));
		while (ch) {
			Message* _Nf1 = ((Message*)((Message*)JB_Ring_NextSib(ch)));
			JB_FS_AppendIndent(fs);
			JB_FS_SyntaxAppend(fs, ch);
			ch = _Nf1;
		};
		(self);
	}
	;
	self->Indent--;
}

JB_String* JB_Msg_FilePath(Message* self) {
	JB_MemoryLayer* L = JB_Msg_OriginalParseLayer(self);
	if ((!L)) {
		return nil;
	}
	JB_Object* O = L->Obj;
	if (JB_Object_Isa(O, JB_AsClass(JB_String))) {
		return ((JB_String*)O);
	}
	//;
	return JB_LUB[0];
}

Message* JB_Msg_FindFlat(Message* self, Syntax s, JB_String* name, bool Err) {
	{
		Message* ch = ((Message*)JB_Tree_First_(self));
		while (ch) {
			Message* _Nf1 = ((Message*)((Message*)JB_Ring_NextSib(ch)));
			if ((JB_Msg_EqualsSyx(ch, s, false)) and (JB_Msg_SyntaxEquals(ch, name, true))) {
				return ch;
			}
			ch = _Nf1;
		};
		(self);
	}
	;
	if (Err) {
		JB_Msg_CantFind(self, s, name, nil);
	}
	return nil;
}

void JB_Msg_FSListArg(Message* self, FastString* fs) {
	bool hasp = ((Message*)JB_Ring_Parent(self)) != nil;
	fs->Indent = (fs->Indent + hasp);
	bool doind = hasp;
	if (JB_Str_Exists(self->Name)) {
		doind = true;
		JB_FS_AppendIndent(fs);
		JB_FS_AppendString(fs, JB_LUB[308]);
		JB_FS_AppendEscape(fs, self->Name);
		JB_FS_AppendByte(fs, '"');
	}
	{
		Message* ch = ((Message*)JB_Tree_First_(self));
		while (ch) {
			Message* _Nf1 = ((Message*)((Message*)JB_Ring_NextSib(ch)));
			if (doind) {
				JB_FS_AppendIndent(fs);
			}
			JB_FS_SyntaxAppend(fs, ch);
			doind = true;
			ch = _Nf1;
		};
		(self);
	}
	;
	fs->Indent = (fs->Indent - hasp);
	if (hasp) {
		JB_FS_AppendByte(fs, '\n');
	}
}

void JB_Msg_FSListSep(Message* self, FastString* fs, JB_String* sep) {
	{
		Message* ch = ((Message*)JB_Tree_First_(self));
		Message* _firstf2 = ch;
		while (ch) {
			Message* _Nf1 = ((Message*)((Message*)JB_Ring_NextSib(ch)));
			if (_firstf2 != ch) {
				JB_FS_AppendString(fs, sep);
			}
			//start;
			JB_FS_SyntaxAppend(fs, ch);
			ch = _Nf1;
		};
		(self);
	};
}

void JB_Msg_Func__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_SyntaxAppend(fs, ch);
	Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
	JB_Decr(ch);
	JB_FS_SyntaxAppend(fs, _tmPf0);
	JB_Decr(_tmPf0);
}

JB_String* JB_Msg_FuncName(Message* self) {
	JB_String* _tmPf0 = JB_Incr(JB_Syx_LongName(self->Func));
	JB_String* _tmPf1 = JB_Incr(JB_Str_LowerCase(_tmPf0));
	JB_Decr(_tmPf0);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

Message* JB_Msg_GoIntoInvisArg(Message* self, Message* tmp, int pos) {
	int i = JB_int_OperatorAlign(((int)self->Indent), 4);
	Syntax f = tmp->Func;
	if ((!((f == JB_SyxTmp) or ((f == JB_SyxItem) or (f == JB_SyxDecl))))) {
		return JB_Tk__ErrorAdd(JB_LUB[309], tmp->Position);
	}
	Message* it = JB_Tk__MakeInvisArg(tmp, i);
	if (it) {
		it->Indent = i;
		(JB_Msg_rangeSet(it, ((IntRange)ivec2{pos, pos})));
		JB_Tree_SyntaxAppend(it, self);
		return it;
	}
	return nil;
}

int JB_Msg_IndentScore(Message* self) {
	int ind = JB_Msg_CleanIndent(self);
	if ((JB_Msg_EqualsSyx(self, JB_SyxTmp, false)) or (JB_Msg_EqualsSyx(self, JB_SyxItem, false))) {
		return ind + 2;
	}
	if (JB_Msg_EqualsSyx(self, JB_SyxArg, false)) {
		return ind;
	}
	return JB_Msg_CleanIndent(self);
}

bool JB_Msg_InInvisArg(Message* self) {
	Message* p = ((Message*)JB_Ring_Parent(self));
	return ((JB_Msg_EqualsSyx(p, JB_SyxArg, false))) and (JB_Msg_SyntaxIsnt(p, kJB__MsgUIFlags_Style2));
}

int64 JB_Msg_Int(Message* self, int i) {
	if (self) {
		if ((!JB_Msg_EqualsSyx(self, JB_SyxUnit, false))) {
			return JB_Str_TextIntegerSection(self->Name, i, self);
		}
		Message* f = ((Message*)JB_Ring_First(self));
		if (JB_Msg_SyntaxEquals(self, JB_LUB[310], false)) {
			return JB_Str_HexIntegerSection(f->Name, i, f);
		}
		double mul = JB_Str_TextDouble(f->Name, nil);
		if (JB_Msg_SyntaxEquals(self, JB_LUB[311], false)) {
			mul = (mul * 1024);
		}
		 else if (JB_Msg_SyntaxEquals(self, JB_LUB[312], false)) {
			mul = (mul * 1048576);
		}
		 else if (JB_Msg_SyntaxEquals(self, JB_LUB[313], false)) {
			mul = (mul * 1073741824);
		}
		 else {
			if ((!false)) {
				JB_Msg_SyntaxExpect(self, JB_LUB[314]);
			}
			return 0;
		}
		return mul;
	}
	return 0;
}

void JB_Msg_Item__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_SyntaxAppend(fs, ch);
	JB_FS_AppendString(fs, JB_LUB[276]);
	Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
	JB_Decr(ch);
	JB_FS_SyntaxAppend(fs, _tmPf0);
	JB_Decr(_tmPf0);
}

bool JB_Msg_jbinTest(Message* self) {
	JB_String* _tmPf0 = JB_Incr(JB_Msg_render_jbin(self, JB_LUB[0], nil));
	Message* msg = JB_Incr(JB_Str_parse_jbin(_tmPf0));
	JB_Decr(_tmPf0);
	bool _tmPf1 = JB_Msg__TreeCompare(self, msg, false);
	JB_Decr(msg);
	return _tmPf1;
}

JB_String* JB_Msg_jdb2_(Message* self, int Flags, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	if (((bool)(Flags & 1))) {
		JB_FS_AppendString(fs, JB_LUB[106]);
	}
	JB_String* _tmPf2 = JB_Incr(JB_Syx_Name(self->Func));
	JB_FS_AppendString(fs, _tmPf2);
	JB_Decr(_tmPf2);
	JB_FS_AppendByte(fs, ' ');
	if (JB_Str_Exists(self->Name)) {
		JB_FS_AppendByte(fs, '"');
		if (((bool)(Flags & 2))) {
			JB_String* _tmPf3 = JB_Incr(JB_Str_Range(self->Name, 0, 32));
			JB_FS_AppendEscape(fs, _tmPf3);
			JB_Decr(_tmPf3);
		}
		 else {
			JB_FS_AppendEscape(fs, self->Name);
		}
		JB_FS_AppendByte(fs, '"');
	}
	if (JB_Ring_HasChildren(self)) {
		fs->Indent++;
		{
			Message* ch = JB_Incr(((Message*)JB_Tree_First_(self)));
			while (ch) {
				Message* _Nf1 = JB_Incr(((Message*)((Message*)JB_Ring_NextSib(ch))));
				JB_FS_AppendIndent(fs);
				JB_FreeIfDead(JB_Msg_jdb2_(ch, Flags, fs));
				JB_SetRef(ch, _Nf1);
				JB_Decr(_Nf1);
			};
			JB_Decr(ch);
			(self);
		}
		;
		fs->Indent--;
		if (((bool)(Flags & 1))) {
			JB_FS_AppendIndent(fs);
		}
	}
	if (((bool)(Flags & 1))) {
		JB_FS_AppendString(fs, JB_LUB[85]);
	}
	JB_String* _tmPf4 = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmPf4);
	return _tmPf4;
}

JB_String* JB_Msg_jdb_(Message* self, FastString* fs_in, int flags) {
	return JB_Msg_jdb2_(self, flags, fs_in);
}

int JB_Msg_Length(Message* self) {
	return JB_Str_Length(self->Name);
}

void JB_Msg_List__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '(');
	int count = 0;
	JB_String* sep = JB_LUB[297];
	if (JB_Msg_SyntaxIs(self, kJB__MsgUIFlags_Style2)) {
		sep = JB_LUB[8];
		JB_FS_AppendString(fs, sep);
	}
	{
		Message* ch = ((Message*)JB_Tree_First_(self));
		while (ch) {
			Message* _Nf1 = ((Message*)((Message*)JB_Ring_NextSib(ch)));
			if ((++count) > 1) {
				JB_FS_AppendString(fs, sep);
			}
			JB_FS_SyntaxAppend(fs, ch);
			if (JB_Msg_EqualsSyx(ch, JB_SyxItem, false)) {
				count++;
			}
			ch = _Nf1;
		};
		(self);
	}
	;
	if ((count == 1) or JB_Msg_SyntaxIs(self, kJB__MsgUIFlags_Style2)) {
		JB_FS_AppendString(fs, sep);
	}
	JB_FS_AppendByte(fs, ')');
}

bool JB_Msg_ListViewable(Message* self) {
	return ((bool)self) and JB_Syx_ListViewable(self->Func);
}

JB_String* JB_Msg_Locate(Message* self) {
	if ((!self)) {
		return JB_LUB[298];
	}
	JB_String* s = JB_Incr(JB_Msg_Render(self, nil));
	JB_String* fname = JB_Incr(JB_Syx_Name(self->Func));
	FastString* fs = JB_Incr(JB_FS__New());
	JB_FreeIfDead(JB_ObjRender(self->Name, fs));
	JB_FS_AppendByte(fs, '@');
	JB_FS_AppendString(fs, fname);
	JB_Decr(fname);
	JB_FS_AppendString(fs, JB_LUB[315]);
	JB_FS_AppendString(fs, s);
	JB_Decr(s);
	JB_FS_AppendByte(fs, '\'');
	if (self->Position >= 0) {
		JB_FS_AppendString(fs, JB_LUB[316]);
		JB_FS_AppendInt32(fs, self->Position);
		Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_Root(self)));
		JB_Object* r = JB_Incr(_tmPf0->Obj);
		JB_Decr(_tmPf0);
		if (JB_Object_Isa(r, JB_AsClass(JB_String))) {
			if (JB_Str_Length(((JB_String*)r))) {
				JB_FS_AppendString(fs, JB_LUB[317]);
				JB_FS_AppendString(fs, ((JB_String*)r));
			}
		}
		JB_Decr(r);
	}
	JB_FS_AppendByte(fs, '\n');
	JB_String* _tmPf1 = JB_Incr(JB_FS_SyntaxCast(fs));
	JB_Decr(fs);
	JB_SafeDecr(_tmPf1);
	return _tmPf1;
}

JB_String* JB_Msg_MiniName(Message* self) {
	FastString* _fsf0 = JB_Incr(JB_FS__New());
	JB_String* _tmPf1 = JB_Incr(JB_Msg_FuncName(self));
	JB_FS_AppendString(_fsf0, _tmPf1);
	JB_Decr(_tmPf1);
	JB_FS_AppendString(_fsf0, JB_LUB[318]);
	JB_String* _tmPf3 = JB_Incr(JB_Str_Range(self->Name, 0, 64));
	JB_String* _tmPf2 = JB_Incr(JB_Str_UnicodeSync(_tmPf3));
	JB_Decr(_tmPf3);
	JB_FS_AppendString(_fsf0, _tmPf2);
	JB_Decr(_tmPf2);
	JB_FS_AppendString(_fsf0, JB_LUB[88]);
	JB_String* _tmPf4 = JB_Incr(JB_FS_GetResult(_fsf0));
	JB_Decr(_fsf0);
	JB_SafeDecr(_tmPf4);
	return _tmPf4;
}

Message* JB_Msg_Msg(Message* self, Syntax fn, JB_String* name) {
	return JB_Msg__NewRange(self, fn, JB__Tk_UsingPos, name, JB_Str_Length(name));
}

void JB_Msg_Msg__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_LUB[106]);
	JB_Msg_FSListSep(self, fs, JB_LUB[297]);
	JB_FS_AppendString(fs, JB_LUB[319]);
}

void JB_Msg_Name__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	if (ch) {
		JB_FS_AppendString(fs, self->Name);
		JB_FS_AppendString(fs, JB_LUB[320]);
		JB_FS_SyntaxAppend(fs, ch);
	}
	 else {
		JB_FS_AppendByte(fs, '@');
		JB_FS_AppendString(fs, self->Name);
	}
	JB_Decr(ch);
}

void JB_Msg_Nil__(Message* self, FastString* fs) {
	debugger;
}

void JB_Msg_Num__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
}

JB_String* JB_Msg_Nyme(Message* self) {
	if (self) {
		return self->Name;
	}
	return JB_LUB[0];
}

void JB_Msg_Oat__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '%');
	JB_Msg_RenderWithSpaces(self, fs, nil);
}

bool JB_Msg_OperatorIn(Message* self, Syntax f) {
	if ((!self)) {
		return nil;
	}
	Message* p = ((Message*)JB_Ring_Parent(self));
	if (p) {
		return p->Func == f;
	}
	return false;
}

void JB_Msg_Opp__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
}

JB_String* JB_Msg_OriginalParseData(Message* self) {
	JB_MemoryLayer* L = JB_Msg_OriginalParseLayer(self);
	if (((bool)L) and JB_Object_Isa(L->Obj2, JB_AsClass(JB_String))) {
		return ((JB_String*)L->Obj2);
	}
	return JB_LUB[0];
}

JB_MemoryLayer* JB_Msg_OriginalParseLayer(Message* self) {
	if ((!self)) {
		return nil;
	}
	JB_MemoryLayer* L = JB_ObjLayer(self);
	if (((bool)L) and (L != JB_Class_DefaultLayer((JB_AsClass(Message))))) {
		return L;
	}
	return nil;
}

Message* JB_Msg_ParseAST(Message* self) {
	Message* rz = nil;
	if (JB_Msg_EqualsSyx(self, JB_SyxArg, false)) {
		Message* f = JB_Incr(((Message*)JB_Ring_First(self)));
		JB_Msg_ExpectLast(f, JB_LUB[0]);
		JB_Decr(rz);
		Message* _tmPf4 = JB_Incr(JB_Msg_ParseAST(f));
		JB_Decr(f);
		JB_SafeDecr(_tmPf4);
		return _tmPf4;
	}
	Syntax fn = JB_Syx__Func(self->Name, self);
	if ((!fn)) {
		JB_Decr(rz);
		return nil;
	}
	Message* name = JB_Incr(((Message*)JB_Ring_First(self)));
	bool isStr = (JB_Msg_EqualsSyx(name, JB_SyxStr, false));
	JB_String* _tmPf2 = JB_Incr(((JB_String*)JB_Ternary(isStr, name->Name, JB_LUB[0])));
	JB_SetRef(rz, JB_Msg__NewNormal(fn, _tmPf2));
	JB_Decr(_tmPf2);
	Message* arg = JB_Incr(((Message*)JB_Ternary(isStr, ((Message*)JB_Ring_NextSib(name)), name)));
	JB_Decr(name);
	if (JB_Msg_EqualsSyx(arg, JB_SyxArg, false)) {
		{
			Message* ch = JB_Incr(((Message*)JB_Tree_First_(arg)));
			while (ch) {
				Message* _Nf1 = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
				Message* _tmPf3 = JB_Incr(JB_Msg_ParseAST(ch));
				JB_Tree_SyntaxAppend(rz, _tmPf3);
				JB_Decr(_tmPf3);
				JB_SetRef(ch, _Nf1);
				JB_Decr(_Nf1);
			};
			JB_Decr(ch);
			(arg);
		};
	}
	JB_Decr(arg);
	JB_SafeDecr(rz);
	return rz;
}

void JB_Msg_pinn__(Message* self, FastString* fs) {
	Message* f = ((Message*)JB_Ring_First(self));
	Message* opp = ((Message*)JB_Ring_NextSib(f));
	Message* l = ((Message*)JB_Ring_NextSib(opp));
	JB_FS_SyntaxAppend(fs, f);
	JB_FS_AppendByte(fs, ' ');
	JB_FS_SyntaxAppend(fs, ((Message*)JB_Ring_Last(opp)));
	JB_FS_AppendByte(fs, ' ');
	JB_FS_SyntaxAppend(fs, l);
	JB_FS_AppendString(fs, JB_LUB[321]);
	JB_FS_SyntaxAppend(fs, ((Message*)JB_Ring_First(opp)));
}

Message* JB_Msg_PoorAnt(Message* self) {
	if (self) {
		return ((Message*)JB_Ring_Parent(self));
	}
	return nil;
}

int JB_Msg_PrevIndentCheck(Message* self, Message* pr) {
	int prin = JB_Msg_CleanIndent(pr);
	int chin = JB_Msg_CleanIndent(self);
	if ((!((prin != chin) and ((prin != 254) and (chin != 254))))) {
		return nil;
	}
	int IndExtra = chin - prin;
	if (JB_int_OperatorIsa(IndExtra, 2)) {
		if (IndExtra == 4) {
			return IndExtra;
		}
		if (IndExtra < 0) {
			if ((JB_int_OperatorIsa(IndExtra, 4)) or ((JB_int_OperatorIsa(chin, 4)) or (JB_Msg_InInvisArg(self)))) {
				return IndExtra;
			}
		}
		if ((IndExtra > 0) and ((JB_Msg_EqualsSyx(pr, JB_SyxTmp, false)))) {
			return IndExtra;
		}
	}
	FastString* _fsf0 = JB_FS__New();
	JB_FS_AppendString(_fsf0, JB_LUB[322]);
	JB_FS_AppendInt32(_fsf0, prin);
	JB_FS_AppendString(_fsf0, JB_LUB[323]);
	JB_FreeIfDead(JB_Tk__ErrorAlwaysAdd(JB_FS_GetResult(_fsf0), pr->Position));
	FastString* _fsf1 = JB_FS__New();
	JB_FS_AppendString(_fsf1, JB_LUB[322]);
	JB_FS_AppendInt32(_fsf1, chin);
	JB_FS_AppendString(_fsf1, JB_LUB[323]);
	JB_FreeIfDead(JB_Tk__ErrorAlwaysAdd(JB_FS_GetResult(_fsf1), self->Position));
	return 0;
}

void JB_Msg_Prm__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '(');
	{
		Message* ch = ((Message*)JB_Tree_First_(self));
		Message* _firstf2 = ch;
		while (ch) {
			Message* _Nf1 = ((Message*)((Message*)JB_Ring_NextSib(ch)));
			if (_firstf2 != ch) {
				JB_FS_AppendString(fs, JB_LUB[297]);
			}
			//start;
			JB_FS_SyntaxAppend(fs, ch);
			ch = _Nf1;
		};
		(self);
	}
	;
	JB_FS_AppendByte(fs, ')');
}

void JB_Msg_Ques__(Message* self, FastString* fs) {
	Message* f = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!f)) {
		JB_Decr(f);
		return;
	}
	JB_FS_AppendString(fs, JB_LUB[77]);
	JB_FS_SyntaxAppend(fs, f);
	Message* n = JB_Incr(((Message*)JB_Ring_NextSib(f)));
	JB_Decr(f);
	if ((!n)) {
		JB_Decr(n);
		return;
	}
	JB_FS_AppendByte(fs, ' ');
	JB_FS_SyntaxAppend(fs, n);
	JB_Decr(n);
}

void JB_Msg_Quot__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_LUB[128]);
	{
		Message* ch = ((Message*)JB_Tree_First_(self));
		while (ch) {
			Message* _Nf1 = ((Message*)((Message*)JB_Ring_NextSib(ch)));
			JB_FS_SyntaxAppend(fs, ch);
			if (((Message*)JB_Ring_NextSib(ch))) {
				JB_FS_AppendString(fs, JB_LUB[297]);
			}
			ch = _Nf1;
		};
		(self);
	}
	;
	JB_FS_AppendString(fs, JB_LUB[324]);
}

void JB_Msg_rangeSet(Message* self, IntRange r) {
	self->Position = r[0];
	self->Extra = (JB_Rg_Width(r) | JB__Tk_BaseExtra);
}

void JB_Msg_Rel__(Message* self, FastString* fs) {
	JB_Msg_RenderWithSpaces(self, fs, nil);
}

JB_String* JB_Msg_Render(Message* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_SyntaxAppend(fs, self);
	JB_String* _tmPf0 = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

JB_String* JB_Msg_render_jbin(Message* self, JB_String* sheb, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	if ((!self)) {
		return nil;
	}
	FastString* js = ((FastString*)fs);
	JB_bin_sheb(js, sheb);
	JB_bin_jinit(js);
	Message* ch = self;
	Message* after = ((Message*)JB_Ring_FlatAfter(self));
	while (ch != after) {
		int Depth = 0;
		Message* curr = ch;
		ch = ((Message*)JB_Ring_FlatNextDepth(ch, (&Depth), true));
		JB_bin_add(js, curr->Func, curr->Name, Depth > 0);
		JB_bin_up(js, (-Depth));
	};
	return JB_FS_SmartResult(fs, fs_in);
}

JB_String* JB_Msg_RenderAST(Message* self, int flags, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	if (((JB_Msg_EqualsSyx(self, JB_SyxArg, false))) and (JB_Ring_IsRoot(self))) {
		{
			Message* ch = JB_Incr(((Message*)JB_Tree_First_(self)));
			while (ch) {
				Message* _Nf1 = JB_Incr(((Message*)((Message*)JB_Ring_NextSib(ch))));
				JB_FreeIfDead(JB_Msg_jdb2_(ch, flags, fs));
				JB_FS_AppendByte(fs, '\n');
				JB_SetRef(ch, _Nf1);
				JB_Decr(_Nf1);
			};
			JB_Decr(ch);
			(self);
		};
	}
	 else {
		JB_FreeIfDead(JB_Msg_jdb2_(self, flags, fs));
	}
	JB_String* _tmPf2 = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmPf2);
	return _tmPf2;
}

void JB_Msg_RenderPrm(Message* self, FastString* fs, byte b1, byte b2) {
	JB_FS_AppendByte(fs, b1);
	JB_Msg_FSListSep(self, fs, JB_LUB[297]);
	JB_FS_AppendByte(fs, b2);
}

void JB_Msg_RenderWithSpaces(Message* self, FastString* fs, Message* ch) {
	if ((!(ch))) {
		ch = ((Message*)JB_Ring_First(self));
	}
	while (ch) {
		JB_FS_SyntaxAppend(fs, ch);
		ch = ((Message*)JB_Ring_NextSib(ch));
		if ((!ch)) {
			return;
		}
		JB_FS_AppendByte(fs, ' ');
	};
}

void JB_Msg_SCnj__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_SCom__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
	JB_FS_SyntaxAppend(fs, _tmPf0);
	JB_Decr(_tmPf0);
	JB_FS_AppendString(fs, JB_LUB[325]);
	if (JB_Tree_HasOneChild(ch)) {
		Message* _tmPf1 = JB_Incr(((Message*)JB_Ring_First(ch)));
		JB_FS_SyntaxAppend(fs, _tmPf1);
		JB_Decr(_tmPf1);
	}
	 else {
		JB_Msg_FSListArg(ch, fs);
		JB_FS_AppendByte(fs, '\n');
	}
	JB_Decr(ch);
	JB_FS_AppendString(fs, JB_LUB[326]);
}

void JB_Msg_SDot__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '.');
	JB_FS_AppendString(fs, self->Name);
	Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_SyntaxAppend(fs, _tmPf0);
	JB_Decr(_tmPf0);
}

void JB_Msg_Sheb__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_LUB[118]);
	JB_FS_AppendString(fs, self->Name);
	JB_FS_AppendByte(fs, '\n');
}

void JB_Msg_SStr__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_LUB[91]);
	JB_FS_AppendString(fs, self->Name);
	JB_FS_AppendString(fs, JB_LUB[92]);
}

void JB_Msg_SThg__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_Str__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '"');
	JB_FS_AppendEscape(fs, self->Name);
	{
		Message* ch = JB_Incr(((Message*)JB_Tree_First_(self)));
		while (ch) {
			Message* _Nf1 = JB_Incr(((Message*)((Message*)JB_Ring_NextSib(ch))));
			if (JB_Msg_EqualsSyx(ch, JB_SyxEmb, false)) {
				JB_FS_AppendEscape(fs, ch->Name);
			}
			 else {
				JB_FS_AppendByte(fs, '$');
				JB_FS_AppendByte(fs, '{');
				JB_FS_SyntaxAppend(fs, ch);
				JB_FS_AppendByte(fs, '}');
			}
			JB_SetRef(ch, _Nf1);
			JB_Decr(_Nf1);
		};
		JB_Decr(ch);
		(self);
	}
	;
	JB_FS_AppendByte(fs, '"');
}

bool JB_Msg_SyntaxEquals(Message* self, JB_String* name, bool Aware) {
	return ((bool)self) and JB_Str_Equals(self->Name, name, Aware);
}

bool JB_Msg_EqualsSyx(Message* self, Syntax X, bool Aware) {
	return ((bool)self) and (self->Func == X);
}

void JB_Msg_SyntaxExpect(Message* self, JB_String* Error) {
	JB_Incr(Error);
	if ((!JB_Str_Exists(Error))) {
		if ((!self)) {
			JB_Object_SyntaxExpect(nil);
			JB_Decr(Error);
			return;
		}
		JB_String* _tmPf0 = JB_Incr(JB_Msg_MiniName(self));
		JB_SetRef(Error, JB_Str_OperatorPlus(JB_LUB[61], _tmPf0));
		JB_Decr(_tmPf0);
	}
	JB_Rec_NewErrorWithNode(JB_StdErr, self, Error, nil);
	JB_Decr(Error);
}

bool JB_Msg_SyntaxIs(Message* self, MsgUIFlags F) {
	if (self) {
		return ((bool)(self->Flags & F));
	}
	return false;
}

void JB_Msg_SyntaxIsSet(Message* self, MsgUIFlags F, bool Value) {
	if (self) {
		if (Value) {
			self->Flags = (self->Flags | F);
		}
		 else {
			self->Flags = (self->Flags & (~F));
		}
	}
}

bool JB_Msg_SyntaxIsnt(Message* self, MsgUIFlags F) {
	return (!JB_Msg_SyntaxIs(self, F));
}

void JB_Msg_Test(Message* self, JB_String* new_render, JB_String* name) {
	if ((!(JB_Msg_TestSub(self, new_render, name)))) {
		FastString* _fsf0 = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fsf0, JB_LUB[327]);
		JB_FS_AppendString(_fsf0, name);
		JB_FS_AppendString(_fsf0, JB_LUB[328]);
		JB_FS_AppendString(_fsf0, new_render);
		JB_String* _tmPf1 = JB_Incr(JB_FS_GetResult(_fsf0));
		JB_Decr(_fsf0);
		JB_Str_Print(_tmPf1);
		JB_Decr(_tmPf1);
		JB_Rec_Clear(JB_StdErr);
	}
}

void JB_Msg_test_style(Message* self) {
	bool b = false;
	{
		Message* s = self;
		Message* _afterf1 = ((Message*)JB_Ring_FlatAfter(self));
		while (((bool)s) and (s != _afterf1)) {
			Message* _N_f2 = ((Message*)((Message*)JB_Ring_FlatNext0(s)));
			if ((JB_Msg_EqualsSyx(s, JB_SyxArg, false)) or (JB_Msg_EqualsSyx(s, JB_SyxList, false))) {
				b = (!b);
				((JB_Msg_SyntaxIsSet(s, kJB__MsgUIFlags_Style2, b)));
			}
			s = _N_f2;
		};
		(self);
	};
}

bool JB_Msg_TestSub(Message* self, JB_String* new_render, JB_String* name) {
	LeakTester* LKT = JB_Incr(JB_Lk__New(name));
	{
		Message* reparse = JB_Incr(JB_Str_Parse(new_render, JB_SyxArg, true));
		if ((!reparse)) {
			JB_Decr(LKT);
			JB_Decr(reparse);
			return nil;
		}
		JB_Msg_test_style(reparse);
		JB_Msg_test_style(self);
		if ((!JB_Msg__TreeCompare(self, reparse, false))) {
			JB_Decr(LKT);
			JB_Decr(reparse);
			return nil;
		}
		JB_String* self_render = JB_Incr(JB_Msg_Render(self, nil));
		if ((!JB_Str_Exists(self_render))) {
			JB_Decr(LKT);
			JB_Decr(reparse);
			JB_Decr(self_render);
			return nil;
		}
		JB_String* reparse_render = JB_Incr(JB_Msg_Render(reparse, nil));
		if ((!JB_Str_Exists(reparse_render))) {
			JB_Decr(LKT);
			JB_Decr(reparse);
			JB_Decr(self_render);
			JB_Decr(reparse_render);
			return nil;
		}
		if ((!(JB_Rec_OK(JB_StdErr) and ((JB_Str_Equals(self_render, reparse_render, false)))))) {
			JB_Decr(LKT);
			JB_Decr(reparse);
			JB_Decr(self_render);
			JB_Decr(reparse_render);
			return nil;
		}
		JB_Decr(reparse_render);
		JB_Decr(self_render);
		JB_Decr(reparse);
	}
	;
	(JB_Lk_FinalTest(LKT));
	JB_Decr(LKT);
	return true;
}

JB_String* JB_Msg_text(Message* self, int i) {
	if (i == 0) {
		return JB_Msg_tviewch(self)->Name;
	}
	return JB_LUB[0];
}

bool JB_Msg_textset(Message* self, int i, JB_String* v) {
	if (i == 0) {
		JB_SetRef(JB_Msg_tviewch(self)->Name, v);
		return true;
	}
	return false;
}

void JB_Msg_Thg__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_Tmp__(Message* self, FastString* fs) {
	if (JB_Str_IsStatementName(self->Name)) {
		JB_FS_AppendString(fs, self->Name);
	}
	 else {
		JB_FS_AppendString(fs, JB_LUB[329]);
		JB_FS_AppendEscape(fs, self->Name);
		JB_FS_AppendByte(fs, '"');
	}
	if ((!JB_Ring_HasChildren(self))) {
		return;
	}
	Message* ch = ((Message*)JB_Ring_First(self));
	bool HasArg = false;
	while (ch) {
		if (HasArg) {
			JB_FS_AppendIndent(fs);
		}
		JB_FS_AppendByte(fs, ' ');
		JB_FS_SyntaxAppend(fs, ch);
		if (JB_Msg_EqualsSyx(ch, JB_SyxArg, false)) {
			HasArg = true;
		}
		ch = ((Message*)JB_Ring_NextSib(ch));
	};
}

void JB_Msg_Todo__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
	JB_Msg_FSListSep(self, fs, JB_LUB[78]);
}

void JB_Msg_TRel__(Message* self, FastString* fs) {
	JB_Msg_RenderWithSpaces(self, fs, nil);
}

void JB_Msg_Tril__(Message* self, FastString* fs) {
	Message* f = ((Message*)JB_Ring_First(self));
	if ((!f)) {
		return;
	}
	JB_FS_AppendByte(fs, '#');
	JB_FS_SyntaxAppend(fs, f);
	Message* s = ((Message*)JB_Ring_NextSib(f));
	if ((!s)) {
		return;
	}
	JB_FS_AppendByte(fs, ' ');
	JB_FS_SyntaxAppend(fs, s);
	Message* l = ((Message*)JB_Ring_NextSib(s));
	if ((!l)) {
		return;
	}
	JB_FS_AppendByte(fs, ' ');
	JB_FS_SyntaxAppend(fs, l);
}

Message* JB_Msg_tviewch(Message* self) {
	if ((!JB_Msg_EqualsSyx(self, JB_SyxTmp, false))) {
		return self;
	}
	Message* ch = ((Message*)JB_Ring_First(self));
	if (ch) {
		Message* ch2 = ((Message*)JB_Ring_NextSib(ch));
		if (JB_Msg_ListViewable(ch2)) {
			return ch2;
		}
		if (JB_Msg_ListViewable(ch)) {
			return ch;
		}
	}
	return self;
}

void JB_Msg_Type__(Message* self, FastString* fs) {
	Message* obj = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!obj)) {
		JB_Decr(obj);
		return;
	}
	Message* type = JB_Incr(((Message*)JB_Ring_NextSib(obj)));
	JB_FS_SyntaxAppend(fs, obj);
	JB_Decr(obj);
	JB_FS_AppendByte(fs, '|');
	if (type) {
		JB_FS_SyntaxAppend(fs, type);
	}
	JB_Decr(type);
	JB_FS_AppendByte(fs, '|');
}

void JB_Msg_UnEmbed(Message* self) {
	Message* s1 = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!(((JB_Msg_EqualsSyx(s1, JB_SyxEmb, false))) and ((!JB_FreeIfDead(((Message*)JB_Ring_NextSib(s1)))))))) {
		JB_Decr(s1);
		return;
	}
	JB_Tree_Remove(s1);
	JB_SetRef(self->Name, s1->Name);
	JB_Decr(s1);
}

void JB_Msg_Unit__(Message* self, FastString* fs) {
	Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_String* num = JB_Incr(_tmPf0->Name);
	JB_Decr(_tmPf0);
	JB_FS_AppendString(fs, num);
	if (((bool)JB_Str_IsHexLike(num, 0)) and (JB_Str_Last(num, 0) != '_')) {
		JB_FS_AppendByte(fs, '_');
	}
	JB_Decr(num);
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_url__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
	JB_FS_AppendString(fs, JB_LUB[109]);
	Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_AppendString(fs, _tmPf0->Name);
	JB_Decr(_tmPf0);
}

void JB_Msg_XAtt__(Message* self, FastString* fs) {
	//;
	JB_FS_AppendByte(fs, ' ');
	JB_FS_AppendString(fs, self->Name);
	JB_FS_AppendString(fs, JB_LUB[330]);
	JB_FS_SyntaxAppend(fs, ((Message*)JB_Ring_First(self)));
	JB_FS_AppendByte(fs, '"');
	//;
}

void JB_Msg_XCDT__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_LUB[83]);
	JB_FS_AppendString(fs, self->Name);
	JB_FS_AppendString(fs, JB_LUB[84]);
}

void JB_Msg_XCom__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_LUB[81]);
	JB_FS_AppendString(fs, self->Name);
	JB_FS_AppendString(fs, JB_LUB[82]);
}

void JB_Msg_XML__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '<');
	JB_FS_AppendString(fs, self->Name);
	Message* atts = ((Message*)JB_Ring_First(self));
	{
		Message* A = ((Message*)JB_Tree_First_(atts));
		while (A) {
			Message* _Nf2 = ((Message*)JB_Ring_NextSib(A));
			JB_FS_SyntaxAppend(fs, A);
			A = _Nf2;
		};
		(atts);
	}
	;
	Message* Children = ((Message*)JB_Ternary(((bool)atts), ((Message*)JB_Ring_NextSib(atts)), nil));
	if ((!Children)) {
		JB_FS_AppendString(fs, JB_LUB[331]);
		return;
	}
	JB_FS_AppendByte(fs, '>');
	bool SingleText = ((JB_Msg_EqualsSyx(Children, JB_SyxXTxt, false))) and ((!((Message*)JB_Ring_NextSib(Children))));
	if (SingleText) {
		JB_FS_SyntaxAppend(fs, Children);
	}
	 else {
		fs->Indent++;
		{
			Message* ch = Children;
			while (ch) {
				JB_FS_AppendIndent(fs);
				JB_FS_SyntaxAppend(fs, ch);
				ch = ((Message*)JB_Ring_NextSib(ch));
			};
			(Children);
		}
		;
		fs->Indent--;
		JB_FS_AppendIndent(fs);
	}
	//;
	JB_FS_AppendString(fs, JB_LUB[332]);
	JB_FS_AppendString(fs, self->Name);
	JB_FS_AppendByte(fs, '>');
	//;
}

void JB_Msg_XPI__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_LUB[130]);
	if (JB_Ring_HasChildCount(self, 1)) {
		Message* _tmPf0 = JB_Incr(((Message*)JB_Ring_First(self)));
		JB_FS_SyntaxAppend(fs, _tmPf0);
		JB_Decr(_tmPf0);
	}
	 else {
		JB_Msg_FSListArg(self, fs);
		JB_FS_AppendByte(fs, '\n');
	}
	JB_FS_AppendString(fs, JB_LUB[96]);
}

void JB_Msg_XTxt__(Message* self, FastString* fs) {
	JB_FS_AppendMultiReplace(fs, self->Name, JB__Constants_XML_EscapeStr, JB_StdErr);
}

void JB_Msg_Yoda__(Message* self, FastString* fs) {
	Message* f = ((Message*)JB_Ring_First(self));
	Message* s = ((Message*)JB_Ring_NextSib(f));
	Message* l = ((Message*)JB_Ring_NextSib(s));
	JB_FS_AppendString(fs, JB_LUB[333]);
	JB_FS_SyntaxAppend(fs, l);
	JB_FS_AppendByte(fs, ' ');
	JB_FS_SyntaxAppend(fs, f);
	JB_FS_AppendByte(fs, ' ');
	JB_FS_SyntaxAppend(fs, s);
}

Message* JB_Msg__Alloc() {
	return ((Message*)JB_New(Message));
}

Message* JB_Msg__LayerAlloc(JB_MemoryLayer* _L) {
	//visible;
	return ((Message*)JB_LayerNew(_L, Message));
}

Message* JB_Msg__NewBasic() {
	Message* __rz__ = ((Message*)JB_Msg__Alloc());
	if (__rz__) {
		JB_Msg_ConstructorBasic(__rz__);
	}
	return __rz__;
}

Message* JB_Msg__NewNormal(Syntax Func, JB_String* Name) {
	Message* __rz__ = ((Message*)JB_Msg__Alloc());
	if (__rz__) {
		JB_Msg_ConstructorNormal(__rz__, Func, Name);
	}
	return __rz__;
}

Message* JB_Msg__NewRange(Message* Parent, Syntax Func, int BytePos, JB_String* name, int Extra) {
	Message* __rz__ = ((Message*)JB_Msg__Alloc());
	if (__rz__) {
		JB_Msg_ConstructorRange(__rz__, Parent, Func, BytePos, name, Extra);
	}
	return __rz__;
}

Message* JB_Msg__NewWithLayerCopy(JB_MemoryLayer* _L, Message* other) {
	//visible;
	Message* __rz__ = ((Message*)JB_Msg__LayerAlloc(_L));
	if (__rz__) {
		JB_Msg_ConstructorCopy(__rz__, other);
	}
	return __rz__;
}

bool JB_Msg__TreeCompare(Message* orig, Message* reparse, bool PrintIfSame) {
	if ((!(((bool)orig) and ((bool)reparse)))) {
		return JB_CompareError(orig, reparse);
	}
	if ((orig->Func != reparse->Func) or ((!JB_Str_Equals(orig->Name, reparse->Name, false)))) {
		return JB_CompareError(orig, reparse);
	}
	Message* r1 = JB_Incr(((Message*)JB_Ring_First(reparse)));
	Message* s1 = JB_Incr(((Message*)JB_Ring_First(orig)));
	while (((bool)r1) or ((bool)s1)) {
		if ((!JB_Msg__TreeCompare(s1, r1, false))) {
			JB_Decr(r1);
			JB_Decr(s1);
			return nil;
		}
		JB_SetRef(r1, ((Message*)JB_Ring_NextSib(r1)));
		JB_SetRef(s1, ((Message*)JB_Ring_NextSib(s1)));
	};
	JB_Decr(s1);
	JB_Decr(r1);
	if (PrintIfSame) {
		FastString* _fsf0 = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fsf0, JB_LUB[334]);
		JB_String* _tmPf1 = JB_Incr(JB_Msg_MiniName(orig));
		JB_FS_AppendString(_fsf0, _tmPf1);
		JB_Decr(_tmPf1);
		JB_FS_AppendString(_fsf0, JB_LUB[335]);
		JB_String* _tmPf2 = JB_Incr(JB_FS_GetResult(_fsf0));
		JB_Decr(_fsf0);
		JB_PrintLine(_tmPf2);
		JB_Decr(_tmPf2);
	}
	return true;
}




void JB_Err_Constructor(JB_Error* self, Message* node, JB_String* desc, ErrorSeverity level, JB_String* path) {
	JB_Msg_ConstructorBasic(self);
	self->ErrorFlags = 0;
	self->Position = -1;
	if (node) {
		self->Position = node->Position;
	}
	self->Node = JB_Incr(node);
	self->Severity = level;
	self->Name = JB_Incr(desc);
	JB_String* _tmPf0 = ((JB_String*)JB_Ternary(JB_Str_Exists(path), path, JB_Msg_FilePath(node)));
	self->Path = JB_Incr(_tmPf0);
	JB_String* _tmPf1 = JB_Msg_OriginalParseData(node);
	self->OriginalData = JB_Incr(_tmPf1);
	self->When = JB_Date__New0();
	self->Func = JB_SyxSStr;
}

void JB_Err_destructor(JB_Error* self) {
	JB_Decr(self->Path);
	JB_Decr(self->OriginalData);
	JB_Decr(self->Node);
	JB_Msg_destructor(self);
}

void JB_Err_Fill(JB_Error* self, JB_String* path, JB_String* desc) {
	//visible;
	JB_SetRef(self->Path, path);
	((JB_Err_SyntaxIsSet(self, kJB__ErrorFlags_prefernorenderpath, JB_Str_ContainsString(desc, path))));
	JB_SetRef(self->Name, desc);
}

void JB_Err_GrabLine(JB_Error* self, FastString* fs, bool Usecolor) {
	if (Usecolor) {
		JB_FS_AppendString(fs, kJB__ErrorColors_normal);
	}
	JB_String* d = JB_Incr(self->OriginalData);
	if ((!(JB_Str_Exists(d) and JB_Err_HasPosition(self)))) {
		JB_Decr(d);
		return;
	}
	JB_FS_AppendByte(fs, '\n');
	Ind Start = JB_Str_Find(d, JB__Constants_CSLine, self->Position, 0) + 1;
	Ind Finish = JB_Str_Find(d, JB__Constants_CSLine, (self->Position), JB_int__max());
	if (Finish == -1) {
		Finish = (JB_Str_Length(d) + 1);
	}
	JB_String* _tmPf1 = JB_Incr(JB_Str_Range(d, Start, Finish));
	JB_Decr(d);
	JB_String* _tmPf0 = JB_Incr(JB_Str_ReplaceAll(_tmPf1, JB_LUB[12], JB_LUB[78], false, nil));
	JB_Decr(_tmPf1);
	JB_FS_AppendString(fs, _tmPf0);
	JB_Decr(_tmPf0);
	Ind Spaces = (self->Position - Start);
	if (Spaces > 200) {
		Spaces = 0;
	}
	JB_FS_AppendByte(fs, '\n');
	if (Usecolor) {
		JB_FS_AppendString(fs, kJB__ErrorColors_underline);
	}
	JB_FS_AppendMultiByte(fs, ' ', Spaces);
	JB_FS_AppendByte(fs, '^');
}

bool JB_Err_HasPosition(JB_Error* self) {
	return self->Position >= 0;
}

bool JB_Err_IsError(JB_Error* self) {
	return (self->Severity >= kJB__ErrorSeverity_Error);
}

bool JB_Err_IsWarning(JB_Error* self) {
	return (self->Severity <= kJB__ErrorSeverity_Warning);
}

bool JB_Err_LineIdentifiers(JB_Error* self, FastString* fs, JB_String* path) {
	if ((!(JB_Err_HasPosition(self)))) {
		return nil;
	}
	JB_String* d = JB_Incr(self->OriginalData);
	if ((!JB_Str_Exists(d))) {
		JB_Decr(d);
		return nil;
	}
	if ((!JB_Str_Exists(path))) {
		JB_FS_AppendString(fs, JB_LUB[100]);
	}
	JB_FS_AppendInt32(fs, JB_Err_LinePos(self, d));
	JB_FS_AppendByte(fs, ':');
	Ind Start = JB_Str_Find(d, JB__Constants_CSLine, self->Position, 0);
	JB_Decr(d);
	JB_FS_AppendInt32(fs, self->Position - Start);
	JB_FS_AppendByte(fs, ':');
	return true;
}

int JB_Err_LinePos(JB_Error* self, JB_String* data) {
	if (JB_Err_HasPosition(self)) {
		JB_String* _tmPf0 = JB_Incr(JB_Str_Range(data, 0, self->Position));
		int _tmPf1 = JB_Str_LineCount(_tmPf0);
		JB_Decr(_tmPf0);
		return _tmPf1;
	}
	return 0;
}

bool JB_Err_NeedsPrint(JB_Error* self) {
	return (self->Severity >= kJB__ErrorSeverity_Problem);
}

JB_String* JB_Err_render(JB_Error* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_AppendString(fs, JB_LUB[336]);
	fs->Indent++;
	JB_FS_AppendInfo(fs, JB_LUB[0], self->Name);
	if (self->Position >= 0) {
		JB_FS_AppendInfoNum(fs, JB_LUB[337], self->Position);
	}
	JB_FS_AppendInfo(fs, JB_LUB[225], self->Path);
	JB_FS_AppendInfoNum(fs, JB_LUB[338], self->Severity);
	JB_FS_AppendByte(fs, '\n');
	fs->Indent--;
	JB_String* _tmPf0 = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

JB_String* JB_Err_render_clang(JB_Error* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	int M = JB_FS_Mark(fs);
	JB_String* p = JB_Incr(self->Path);
	if ((JB_Err_SyntaxIsnt(self, kJB__ErrorFlags_prefernorenderpath)) and JB_Str_Exists(p)) {
		JB_FS_AppendString(fs, self->Path);
		JB_FS_AppendByte(fs, ':');
	}
	if ((!JB_Err_LineIdentifiers(self, fs, p)) and ((bool)self->Node)) {
		JB_FreeIfDead(JB_Msg_Render(self->Node, fs));
	}
	JB_Decr(p);
	if (JB_FS_Grew(fs, M)) {
		JB_FS_AppendByte(fs, ' ');
	}
	JB_FreeIfDead(JB_ErrorSeverity_Render(self->Severity, fs));
	JB_FS_AppendString(fs, JB_LUB[276]);
	JB_FS_AppendString(fs, self->Name);
	JB_Err_GrabLine(self, fs, false);
	JB_String* _tmPf0 = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmPf0);
	return _tmPf0;
}

bool JB_Err_SyntaxIs(JB_Error* self, ErrorFlags F) {
	return ((bool)self) and ((bool)(self->ErrorFlags & F));
}

void JB_Err_SyntaxIsSet(JB_Error* self, ErrorFlags F, bool Value) {
	if (Value) {
		self->ErrorFlags = (self->ErrorFlags | F);
	}
	 else {
		self->ErrorFlags = (self->ErrorFlags & (~F));
	}
}

bool JB_Err_SyntaxIsnt(JB_Error* self, ErrorFlags F) {
	return (!JB_Err_SyntaxIs(self, F));
}

JB_Error* JB_Err__Alloc() {
	return ((JB_Error*)JB_New(JB_Error));
}

void JB_Err__CantParseNum(Message* Where, JB_String* num, int Pos) {
	//visible;
	FastString* _fsf0 = JB_Incr(JB_FS__New());
	JB_FS_AppendString(_fsf0, JB_LUB[339]);
	JB_String* _tmPf1 = JB_Incr(JB_Str_Range(num, 0, 10));
	JB_FS_AppendString(_fsf0, _tmPf1);
	JB_Decr(_tmPf1);
	JB_FS_AppendString(_fsf0, JB_LUB[340]);
	JB_FS_AppendByte(_fsf0, JB_Str_ByteValue(num, Pos));
	JB_FS_AppendString(_fsf0, JB_LUB[341]);
	JB_String* msg = JB_Incr(JB_FS_GetResult(_fsf0));
	JB_Decr(_fsf0);
	JB_Error* _tmPf2 = JB_Incr(JB_Err__New(Where, msg, kJB__ErrorSeverity_Error, JB_LUB[0]));
	JB_Decr(msg);
	JB_Rec_SyntaxAppend(JB_StdErr, _tmPf2);
	JB_Decr(_tmPf2);
}

int JB_Err__Init_() {
	{
		JB__Err_AutoPrint = 0;
	}
	;
	return 0;
}

int JB_Err__InitCode_() {
	return 0;
}

JB_Error* JB_Err__New(Message* node, JB_String* desc, ErrorSeverity level, JB_String* path) {
	JB_Error* __rz__ = ((JB_Error*)JB_Err__Alloc());
	if (__rz__) {
		JB_Err_Constructor(__rz__, node, desc, level, path);
	}
	return __rz__;
}




//// API START! ////

#pragma GCC visibility push(default)
__lib__ JB_String* jb_msg_name(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return self->Name;
}

__lib__ Syntax jb_msg_func(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return self->Func;
}

__lib__ int jb_msg_position(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return self->Position;
}

__lib__ _voidptr jb_msg_tag(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((_voidptr)self->Obj);
}

__lib__ void jb_msg_nameset(Message* self, JB_String* Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	JB_SetRef(self->Name, Result);
}

__lib__ void jb_msg_funcset(Message* self, Syntax Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	self->Func = Result;
}

__lib__ void jb_msg_positionset(Message* self, int Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	self->Position = Result;
}

__lib__ void jb_msg_tagset(Message* self, _voidptr Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	self->Obj = ((JB_Object*)Result);
}

__lib__ void jb_msg_firstset(Message* self, Message* Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	(JB_Ring_FirstSet(self, Result));
}

__lib__ void jb_msg_lastset(Message* self, Message* Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	(JB_Ring_LastSet(self, Result));
}

__lib__ void jb_msg_prevset(Message* self, Message* Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	(JB_Ring_PrevSibSet(self, Result));
}

__lib__ void jb_msg_nextset(Message* self, Message* Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	(JB_Ring_NextSibSet(self, Result));
}

__lib__ Message* jb_msg_first(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_First(self));
}

__lib__ Message* jb_msg_last(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_Last(self));
}

__lib__ Message* jb_msg_prev(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_PrevSib(self));
}

__lib__ Message* jb_msg_next(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_NextSib(self));
}

__lib__ Message* jb_msg_parent(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_Parent(self));
}

__lib__ Message* jb_msg_flatnext(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_FlatNext0(self));
}

__lib__ Message* jb_msg_flatafter(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_FlatAfter(self));
}

__lib__ Message* jb_msg_root(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_Root(self));
}

__lib__ void jb_msg_remove(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	JB_Tree_Remove(self);
}

__lib__ JB_String* jb_msg_render(Message* self, int mode) {
	JB_String* rz = JB_Incr(JB_LUB[0]);
	if ((!JB_Msg_NilCheck(self))) {
		JB_Decr(rz);
		return nil;
	}
	if (((bool)(mode & 1))) {
		JB_SetRef(rz, JB_Msg_render_jbin(self, JB_LUB[0], nil));
	}
	 else {
		JB_SetRef(rz, JB_Msg_Render(self, nil));
	}
	if (((bool)(mode & 2))) {
		JB_SetRef(rz, JB_Str_Compress(rz, nil));
	}
	JB_SafeDecr(rz);
	return rz;
}

__lib__ JB_String* jb_msg_ast(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return JB_Msg_RenderAST(self, 1, nil);
}

__lib__ Message* jb_msg_parseast(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return JB_Msg_ParseAST(self);
}

__lib__ Message* jb_msg_copy(Message* self, Message* layer) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return JB_Msg_NiceCopy(self, layer);
}

__lib__ Message* jb_msg_create(Message* self, Syntax Type, JB_String* Name) {
	if ((!JB_Syx_NilCheck(Type))) {
		return nil;
	}
	return JB_Syx_ParentMsg(Type, self, Name);
}

__lib__ void jb_msg_error(Message* self, JB_String* ErrorMsg) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	JB_Rec_NewErrorWithNode(JB_StdErr, self, ErrorMsg, nil);
}

__lib__ Message* jb_msg_expect(Message* self, Syntax Type, JB_String* name, Message* ErrPlace) {
	if (self) {
		if (JB_Msg_Expect(self, Type, name)) {
			return self;
		}
	}
	 else if ((bool)ErrPlace) {
		JB_Msg_CantFind(ErrPlace, Type, name, nil);
	}
	return nil;
}

__lib__ Message* jb_msg_access(Message* self, Syntax Type, JB_String* name, bool IsError) {
	return JB_Msg_FindFlat(self, Type, name, IsError);
}

__lib__ JB_String* jb_syx_name(Syntax self) {
	if ((!JB_Syx_NilCheck(self))) {
		return nil;
	}
	return JB_Syx_Name(self);
}

__lib__ JB_String* jb_syx_longname(Syntax self) {
	if ((!JB_Syx_NilCheck(self))) {
		return nil;
	}
	return JB_Syx_LongName(self);
}

__lib__ _cstring jb_string_address(JB_String* self) {
	if ((!(JB_Str_Exists(self)))) {
		return nil;
	}
	return ((_cstring)JB_Str_Address(self));
}

__lib__ int jb_string_length(JB_String* self) {
	return JB_Str_Length(self);
}

__lib__ JB_String* jb_string_compress(JB_String* self) {
	return JB_Str_Compress(self, nil);
}

__lib__ JB_String* jb_string_decompress(JB_String* self) {
	return JB_Str_Decompress(self, nil, 268435456);
}

__lib__ JB_String* jb_string_copy(JB_String* self) {
	return JB_Str_Copy(self);
}

__lib__ Message* jb_string_parse(JB_String* self, JB_String* path) {
	if ((!(JB_Str_Exists(self)))) {
		return nil;
	}
	return JB_API__Parse(self, path);
}

__lib__ JB_String* jb_string_escape(JB_String* self) {
	return JB_Str_Escape(self);
}

__lib__ void jb_string_print(JB_String* self) {
	JB_Str_Print(self);
}

__lib__ void jb_string_printline(JB_String* self) {
	JB_PrintLine(self);
}

__lib__ int64 jb_string_int(JB_String* self, Message* m) {
	return JB_Str_TextIntegerValid(self, m);
}

__lib__ double jb_string_float(JB_String* self, Message* m) {
	return JB_Str_TextDouble(self, m);
}

__lib__ Syntax jb_syntax(JB_String* name) {
	return JB_Syx__Func(name, nil);
}

__lib__ JB_String* jb_str(_cstring Str, int Length, _voidptr Release, _voidptr Tag) {
	if ((!Str) or (Length < 0)) {
		return JB_LUB[0];
	}
	if ((!(Length))) {
		Length = strlen(Str);
	}
	return JB_StrFromPtr(((_voidptr)Str), Length, Release, Tag);
}

__lib__ JB_String* jb_cstr(_cstring Str) {
	if (Str) {
		return JB_StrFromPtr(((_voidptr)Str), strlen(Str), nil, nil);
	}
	return JB_LUB[0];
}

__lib__ void jb_delete_(JB_Object* obj) {
}

__lib__ Message* jb_errors() {
	return JB_API__errors();
}

__lib__ bool jb_ok() {
	return JB_Rec_OK(JB_StdErr);
}

__lib__ void jb_debug(JB_Object* o) {
	jdb(o);
}

__lib__ int jb_init(int Flags) {
	JB_PrintLine(JB_LUB[348]);
	return JB_API__Init(Flags);
}

__lib__ int jb_shutdown() {
	JB_SetRef(JB_StdErr, nil);
	JB_LibShutdown();
	return 0;
}

__lib__ int jb_version() {
	return (2023022022);
}

__lib__ JB_String* jb_readfile(_cstring path, bool AllowMissingFile) {
	JB_API__Init(0);
	return JB_cPath_ReadAll(path, AllowMissingFile, 100000000);
}

#pragma GCC visibility pop
//// API END! ////
}

// 6565725007342036 -616871519083821 -893550536634198