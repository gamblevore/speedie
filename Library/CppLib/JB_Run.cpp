
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


/*
Hidden Caches:
	* .LowerCase / .UpperCase ByteMap
    * EmptyString_
    * WhiteSpace_
	* JB_FS__FastNew
    * Dict fast name
	* 256 byte block! speeds up splitting when the length = 1!! for .Mid
*/

#include <experimental/simd>

#include "JB_Umbrella.hpp"
#include <vector>
#include <errno.h>
#include <unistd.h>


extern "C" {

#define JBClassPlaceSaver(a, b, c, d, e, f, g)  \
JBSaver_Behaviour a ## _FuncTable = {(void*)b,(void*)d,(void*)e,(void*)f,(void*)g};  \
JB_Class a ## Data = JBClassInit(a##Data, (#a), sizeof(a), c, (JBObject_Behaviour*)&(a##_FuncTable));
#define AddError(Result, name) {int abc = Result; if (abc and !JB_ErrorNumber) {JB_ErrorNumber = abc; fprintf(stderr, "error %s (%i)\n", name, abc); };} 


void JB_Array_SaveWrite(Array* self, void* Other);
void JB_Dict_SaveWrite(Dictionary* self, void* Other);
void JB_Array_SaveCollect(Array* self, void* Other);
void JB_Dict_SaveCollect(Dictionary* self, void* Other);
void JB_Dict_LoadProperties(Dictionary* self, void* Other);
void JB_Array_LoadProperties(Array* self, void* Other);
int  JB_Rec_ShellPrintErrors(JB_ErrorReceiver* self);

void JB_Sav_SaveCollect(Saveable* self, void* Saver);
void JB_Sav_SaveWrite(Saveable* self, void* Saver);
void JB_Sav_LoadProperties(Saveable* self, void* Other);
void JB_Dict__Init();

JBClassPlace( JB_String,		JB_BA_Destructor, 		JB_AsClass(JB_Object),		JB_Str_Render );
JBClassPlace( JB_StringC,		0,                		JB_AsClass(JB_String),		JB_Str_Render );
JBClassPlace( JB_StringShared,	JB_Str_Destructor,		JB_AsClass(JB_String),		JB_Str_Render );
JBClassPlace( JB_StringExternal,JB_XStr_Destructor,		JB_AsClass(JB_String),		JB_Str_Render );
JBClassPlace( JB_String4,		0,						JB_AsClass(JB_String),		JB_Str_Render );
JBClassPlace( JB_String20,		0,						JB_AsClass(JB_String),		JB_Str_Render );

JBClassPlace( Dictionary1,		JB_Dict_Destructor,		JB_AsClass(JB_Object),		0 );
JBClassPlace( Dictionary2,		JB_Dict_Destructor,		JB_AsClass(JB_Object),		0 );
JBClassPlace( Dictionary3,		JB_Dict_Destructor,		JB_AsClass(JB_Object),		0 );
JBClassPlace( Dictionary4,		JB_Dict_Destructor,		JB_AsClass(JB_Object),		0 );
JBClassPlace( DictionaryLeaf,	JB_Leaf_Destructor,		JB_AsClass(JB_Object),		0 );
JBClassPlace( DictionaryReader, JB_Nav_Destructor,		JB_AsClass(JB_Object),		0 );

JBClassPlaceSaver( Dictionary,	JB_Dict_Destructor,		JB_AsClass(Saveable),		JB_Dict_Render,  JB_Dict_LoadProperties,		JB_Dict_SaveCollect,	JB_Dict_SaveWrite );
JBClassPlaceSaver( Array,       JB_Array_Destructor,   	JB_AsClass(Saveable),		JB_Array_Render, JB_Array_LoadProperties,	JB_Array_SaveCollect,	JB_Array_SaveWrite );
JBClassPlaceSaver( Saveable,	0,                     	0,                         0,               JB_Sav_LoadProperties,      JB_Sav_SaveCollect,		JB_Sav_SaveWrite );

JBClassPlace( FastString,		JB_FS_Destructor,		JB_AsClass(JB_Object),		JB_FS_Render );
JBClassPlace( ByteMap,			0,						JB_AsClass(JB_Object),		0 );
JBClassPlace( CharSet,			0,						JB_AsClass(JB_Object),		JB_CS_Render );
JBClassPlace( JB_List,			JB_Ring_Destructor,		JB_AsClass(Saveable),		JB_List_Render );
JBClassPlace( TokHan,			0,						JB_AsClass(JB_Object),		0 );

extern JB_Class JB_TaskData;


CharSet*            WhiteSpace_;
JB_StringC*         EmptyString_;
JB_StringC*         ErrorString_;
JBObject_Behaviour  JB_Object_FuncTable_;
JB_Class*           ClassList;
byte				JB_ErrorNumber;
thread_local byte	JB_Active = 0;
extern char**		environ;
uint				Flow_Disabled;
static Array*		App_Args;
_cstring			App_CallPath;


Dictionary* JB_App__Env() {
    static Dictionary* App_Env;
    if (!App_Env) {
        App_Env = JB_EnvC((const char**)environ);
        JB_Incr(App_Env);
    }
    return App_Env;
}


static JB_StringC* emptystr() {
    JB_StringC* s = JB_New( JB_StringC );
    if (s) {
		JB_Incr(s);
		s->Length = 0;
		s->Addr = (uint8*)"";
	}
	return s;
}


CharSet*	JB_CS_Constructor	(CharSet* self, JB_String* Source, bool Ranges);
JB_String** JB_Str__FindGlobals	(u8** src, uint64* Hash);
void		JB_RemoveHandlers	();


static uint DecodeLength (u8*& p) {
	int lim = 256-8;
	uint rz = *p++;
	if (rz >= lim) {
		int n = rz - lim;
		int i = 0;
		rz = 0;
		while (i <= n) {
			rz |= *p++ << (i << 3);
			i++;
		};
	}
	return rz;
}


void JB_Load_StrError (int num) {
	char  s[] = "jb.loadglob ";
	s[11] = num+'0';
	AddError(EILSEQ, s);
	debugger;
}


void JB_Str__LoadGlobals () {
	u8*					Start = 0;
	uint64				StoredHash = 0;
	JB_String**			Write = JB_Str__FindGlobals(&Start, &StoredHash);
	u8*					Lengths = Start;
	*Write++ = EmptyString_;

	auto LengthBytes = DecodeLength(Lengths);
	auto ReadBytes = DecodeLength(Lengths);
	auto N = DecodeLength(Lengths);
	auto Read = (const char*)Lengths + LengthBytes;
	auto ReadEnd = Read + ReadBytes;
	
	JB_String S = {};
	S.Length = (int)((u8*)ReadEnd-(u8*)Start);
	S.Addr = (u8*)Start;
	uint64 DetectedHash = JB_Str_CRC(&S, 0);
	if (DetectedHash != StoredHash) {
		JB_Load_StrError(0);
	}

	while (N --> 0) {
		auto L = DecodeLength(Lengths);
		auto S = JB_StrCN((void*)Read, L);
		Read += L + 1;
		JB_SetRef(*Write++, S);
		if (Read > ReadEnd) {return JB_Load_StrError(1);}
	};
	if (Read != ReadEnd) {JB_Load_StrError(2);}
}

void JB_FinalEvents() {
	AddError(JB_Rec_ShellPrintErrors(nil),	"jb.stderr");
	JB_LibShutdown();
	JB_RemoveHandlers(); // some wierd systems call signals after we exit??
	JB_KillChildrenOnExit();
}

Array*	JB_App__Args()						{ return App_Args; }
JB_StringC*	JB_App__CallPath()				{ return JB_StrC(App_CallPath); }
void	JB_LibShutdown()					{ JB_MemFree(JB_MemStandardWorld()); }
bool	JB_LibIsShutdown()					{ return JB_MemStandardWorld()->Shutdown; }
bool	JB_LibIsThreaded()					{ return JB_Active & 4; }
void	JB_App__CrashInstall();
int		JB_SP_AppInit();


int JB_SP_Init (_cstring* R, bool IsThread) {
	JB_ErrorNumber = 0;
	JB_TaskData.Size = 128;
	Flow_Disabled = 0x7fffFFFF;
	

	static_assert((sizeof(ivec3) == 16 and sizeof(ivec4)==16 and sizeof(ivec2)==8) and sizeof(vec3) == 16 and sizeof(vec4)==16 and sizeof(vec2)==8 and sizeof(int) == 4  and  sizeof(int64) == 8, "sizeof type");
    if (JB_MemStandardWorld()->CurrSuper)
        return EADDRINUSE;
    if (!(EmptyString_ = emptystr()))
        return ENOMEM;
	if (R) {
		App_CallPath = *R;
		#ifndef AS_LIBRARY
			int err = dup2( STDOUT_FILENO, STDFUN_FILENO );	// reserve StdFUN
			err = dup2( STDOUT_FILENO, STDPICO_FILENO );	// reserve StdPico
			if (!IsThread) {
				JB_App__CrashInstall();
				if (getppid() > 1)
					PicoGlobalConf()->SuicideIfParentDies = true;
				// default Pico to suicide, if run. GUI.init will reset this.
			}
			atexit(JB_KillChildrenOnExit);
			
		#endif
	}
	App_Args = JB_Incr(JB_Str_ArgV(R));	// allow caller to remove their c-string data.
    
    ErrorString_ = emptystr();
    WhiteSpace_ = JB_CS_Constructor( nil, JB_StrC("\x9\xA\xD\x20"), false );
    JB_FS__FastNew( 0 );		// stop leak tests catching this.
    JB_Dict__Init();
    JB_Str__LoadGlobals();
    JB_PID_Start();

    int Err = JB_Init_();
	if (Err)
		return Err;
    #if DEBUG
	JB_TotalSanity(true);
	#endif
	return 0;
}



int JB_SP_Run (_cstring* C, int Mode)	{ // JB_SP_Main
	if (JB_Active & 1)
		return EALREADY;
	JB_Active = 1 | (Mode&4);
	if (JB_LibIsShutdown()) {
		AddError(EACCES, "jb.shutdown");
	} else {
		if (!App_Args and C) {
			AddError(JB_SP_Init(C, Mode&4), "jb.initlib");
			if (JB_ErrorNumber)
				return JB_ErrorNumber;
			AddError(JB_SP_AppInit(), "jb.initapp");
		}
		
		if ((Mode & 1) and App_Args and !JB_ErrorNumber)
			AddError(JB_Main(),	"occurred");

		if ((Mode & 2) and App_Args)
			JB_FinalEvents();
	}
	JB_Active &= ~1;
	
	byte b = JB_ErrorNumber;
	if (b >= 128)
		b = EINVAL;
	return b;
}


void JB_Flow__DisabledIncr(int i) {	Flow_Disabled += i; }
void JB_Flow__DisabledSet(int i) { 	Flow_Disabled = i; }
bool JB_Flow__IsDisabled() { return Flow_Disabled; }


byte* JB_App__ErrorNumber () {
	return &JB_ErrorNumber;
}

void JB_App__Quit (JB_String* Err, int Code) {
	if (JB_Str_Length(Err)) {
		if (!Code) {Code = -1;}
		JB_Str_PrintLine(Err);
	}
	JB_Rec_ShellPrintErrors(nil);
	if (!Code)
		Code = JB_ErrorNumber;
    exit(Code);
}



} // 



