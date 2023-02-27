
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

// OK so... we could merge constuctors and newing...
// to have a "constuctornew" func... that returns a new object if nil


/*
Hidden Caches:
	* .LowerCase / .UpperCase ByteMap
    * EmptyString_
    * WhiteSpace_
	* JB_FS__FastNew
    * Dict fast name
	* 256 byte block! speeds up splitting when the length = 1!! for .Mid
    * Hex mapping in FastString
*/


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

JBClassPlace( JB_String,        JB_BA_Destructor,      JB_AsClass(JB_Object),      JB_Str_Render );
JBClassPlace( JB_StringC,       0,                     JB_AsClass(JB_String),      JB_Str_Render );
JBClassPlace( JB_StringShared,  JB_Str_Destructor,     JB_AsClass(JB_String),      JB_Str_Render );
JBClassPlace( JB_StringExternal,JB_XStr_Destructor,    JB_AsClass(JB_String),      JB_Str_Render );
JBClassPlace( JB_String4,       0,                     JB_AsClass(JB_String),      JB_Str_Render );
JBClassPlace( JB_String20,      0,                     JB_AsClass(JB_String),      JB_Str_Render );

JBClassPlace( Dictionary1,      JB_Dict_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace( Dictionary2,      JB_Dict_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace( Dictionary3,      JB_Dict_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace( Dictionary4,      JB_Dict_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace( DictionaryLeaf,   JB_Leaf_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace( DictionaryReader, JB_Nav_Destructor,     JB_AsClass(JB_Object),      0 );

JBClassPlaceSaver( Dictionary,   JB_Dict_Destructor,    JB_AsClass(Saveable),       JB_Dict_Render,  JB_Dict_LoadProperties,  JB_Dict_SaveCollect, JB_Dict_SaveWrite );
JBClassPlaceSaver( Array,        JB_Array_Destructor,   JB_AsClass(Saveable),       JB_Array_Render, JB_Array_LoadProperties, JB_Array_SaveCollect, JB_Array_SaveWrite );
JBClassPlaceSaver( Saveable,     0,                     0,                          0,               JB_Sav_LoadProperties,                       JB_Sav_SaveCollect, JB_Sav_SaveWrite );

JBClassPlace( FastString,       JB_FS_Destructor,      JB_AsClass(JB_Object),      JB_FS_Render );
JBClassPlace( ByteMap,          0,                     JB_AsClass(JB_Object),      0 );
JBClassPlace( CharSet,          0,                     JB_AsClass(JB_Object),      JB_CS_Render );
JBClassPlace( RingTree,         JB_Ring_Destructor,    JB_AsClass(Saveable),       0 );
JBClassPlace( TokHan,           0,                     JB_AsClass(JB_Object),      0 );


CharSet*            WhiteSpace_;
JB_StringC*         EmptyString_;
JB_StringC*         ErrorString_;
JBObject_Behaviour  JB_Object_FuncTable_ = {0,0};
JB_Class*           ClassList;
int					JB_ErrorNumber;
extern char**		environ;
static Array*		App_Args;
_cstring			App_CalledBy;


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
		s->RefCount = 1;
		s->Length = 0;
		s->Addr = (uint8*)"";
	}
	return s;
}


CharSet* JB_CS__New(JB_String* charset, bool Ranges);
void JB_Str__FindGlobals(JB_String*** lub, int** lengths, const char** src);


void JB_Str__LoadGlobals2() {
	extern JB_StringC*	EmptyString_;
	const char*			Read = 0;
	int*				Lengths = 0;
	JB_String**			Write = 0;
	JB_Str__FindGlobals(&Write, &Lengths, &Read);
	require0 (Write);
	*Write++ = EmptyString_;
	require0 (Lengths and Read);
	while (int n = *Lengths++) {
		auto S = JB_StrCN((void*)Read, n);
		Read+=n+1;
		#ifndef DEBUG
		S->RefCount = 1; // whatever
		#endif
		JB_SetRef(*Write++, S);
	};
}


int JB_LibInit (_cstring* R) {
	JB_ErrorNumber = 0;

	static_assert((sizeof(ivec3) == 12 and sizeof(ivec4)==16 and sizeof(ivec2)==8) and sizeof(vec3) == 12 and sizeof(vec4)==16 and sizeof(vec2)==8 and sizeof(int) == 4  and  sizeof(int64) == 8, "sizeof type");
    if (JB_MemStandardWorld()->CurrSuper)
        return EADDRINUSE;
    if (!(EmptyString_ = emptystr()))
        return ENOMEM;
	if (R) {
		App_CalledBy = *R;
		#ifndef AS_LIBRARY
			void JB_App__CrashInstall();
			JB_App__CrashInstall();
		#endif
	}
	App_Args = JB_Incr(JB_Str_ArgV(R));	// allow caller to remove their c-string data.

    ErrorString_ = emptystr();
    WhiteSpace_ = JB_CS__New( JB_StrC("\x9\xA\xD\x20"), false );
    JB_FS__FastNew( 0 );		// stop leak tests catching this.
    JB_Dict__Init();
    JB_Str__LoadGlobals2();

    return JB_Init_();
}


Array*	JB_App__Args()						{ return App_Args; }
JB_StringC*	JB_App__CalledBy()				{ return JB_StrC(App_CalledBy); }
void	JB_LibShutdown()					{ JB_MemFree(JB_MemStandardWorld()); }
bool	JB_LibIsShutdown()					{ return JB_MemStandardWorld()->Shutdown; }
byte	JB_Active = false;
bool	JB_LibIsThreaded()					{ return JB_Active & 4; }

int		JB_SP_Run (_cstring* C, int Mode)	{
	if (JB_Active)
		return EALREADY;
	JB_Active = 1 | (Mode&4);
	if (JB_LibIsShutdown()) {
		AddError(EACCES, "jb.shutdown");
	} else {
		if (!App_Args and C)
			AddError(JB_LibInit(C),		"jb.init");
		
		if ((Mode & 1) and App_Args and !JB_ErrorNumber)
			AddError(JB_Main(),			"occurred");
//		int ch = getch();
		if ((Mode & 2) and App_Args) {
			AddError(JB_Rec_ShellPrintErrors(nil),	"jb.stderr");
			JB_LibShutdown();
		}
	}
	JB_Active = false;
	return JB_ErrorNumber;
}



void JB_App__Quit (int Code) {
	JB_Rec_ShellPrintErrors(nil);
	if (!Code)
		Code = JB_ErrorNumber;
    exit(Code);
}



} // 



