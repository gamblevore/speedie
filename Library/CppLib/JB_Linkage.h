

extern "C" {

JB_String* JB_Platform();
bool JB_Platform__OSX();
bool JB_Platform__Win();
bool JB_Platform__Lin();
int JB_Platform__CPU();
bool JB_IsLibrary();
Array* JB_App__Args();
JB_StringC*	JB_App__CallPath();
JB_String* JB_App__Readline();
bool JB_App__ShouldDie();
int JB_App__LostChild();
int JB_App__ParentID();
int JB_App__ID();
Dictionary* JB_App__Env();
void JB_App__Quit (JB_String* Err, int Code);
byte* JB_App__ErrorNumber ();
void JB_Flow__DisabledIncr(int i);
void JB_Flow__DisabledSet(int i);
bool JB_Flow__IsDisabled();
JB_String* JB_App__Path();
int JB_App__SetEnv(JB_StringC* name, JB_StringC* value);
int JB_Rec__PrintErrors();
JB_String* JB_App__LibInfo();   
void** JB_App__LibFuncs();
void** JB_App__LibGlobs();
u16* JB_App__GlobTable();
JB_String* JB_App__LibClasses(); 

// startup
void JB_LibShutdown();
bool JB_LibIsThreaded();

// APP
void JB_App__Beep ();
void JB_App__GUIMode(bool Die);
void JB_App__SetIcon (const char* Path);
void JB_App__InitStuff ();
void JB_SDL_RemoveWindowBorder (void* window);
void JB_SDL_FullScreenToggle (void* w);	
void JB_SDL_SetModified (void* w, bool b);
void JB_App__ShowURL (const char* Path);
JB_String* JB_App__DocumentOpened (bool Clear);

// Sub process
int* JB_SP_ErrorNumber ();
int JB_SP_Run (const char** R, int Mode);
int JB_SP_Init (const char** R, bool IsThread);

// dylib
#include <dlfcn.h>

struct JB_Dylib {
	void* handle;
};

void* JB_dylib_Load (JB_Dylib* Self, JB_String* Path);
void JB_dylib_Open (JB_Dylib* Self, JB_String* Path, int Mode);




// VM 
struct VMStack {
	u32*		Code;
	uint		Alloc;			
	byte		Marker2;
	byte		SavedReg;
	u16			Marker;
};


struct VMRegister {
	union {
		VMStack			Stack;
		JB_Object*		Obj;
		s64				Int;
		u64				Uint;
		float			Float;
		double			Double;
		ivec4			Ivec;
		uvec4			Uvec;
		vec4			Vec;
		int				Int32;
		uint			Uint32;
	};
};

typedef void (*SaverLoadClass)(JB_Class* cls, int8* Data);
void	JB_InitClassList	(SaverLoadClass fn);

struct	jb_vm;
jb_vm*	JB_ASM__VM			(int StackSize, int Flags);
void	JB_ASM_FillTable	(jb_vm* V, byte* LibGlobs,  byte* PackGlobs,  void** CppFuncs);
ivec4*	JB_ASM__Run			(jb_vm* V, u32* Code, int CodeSize);
void**	JB_ASM_InitTable	(jb_vm* V, int n, int g);
ivec4*	JB_ASM_Registers	(jb_vm* V, bool Clear);

} // ExternCEnd

