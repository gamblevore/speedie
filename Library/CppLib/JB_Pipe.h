

#ifndef __JB_PIPE__
#define __JB_PIPE__

#include "JB_Umbrella.h"
#include "PicoMsg.h"
#include "JB_List.h"

#define STDFUN_FILENO 3
#define STDPICO_FILENO 4

extern "C" {

JBClass( ShellStream, JB_Object,
	u8					Mode;
	PicoComms*			Pico;
	JB_String*			Path;
	Array*  			Args;
    int64				UserFlags;
);



int JB_Sh_Kill (ShellStream* F, int Code);
int JB_Sh_PID (ShellStream* F);
void JB_AddProcess (int PID);
int JB_Sh_Status (ShellStream* F);
JB_String* JB_Sh_Render (ShellStream* Self, FastString* Fs_in);
JB_StringC* JB_Err_SignalName (int Sig);
JB_StringC* JB_Err_Name (int Sig);



void JB_Sh_Destructor(ShellStream* self);
ShellStream* JB_Sh_Constructor(ShellStream* self, JB_String* Path, byte Mode, Array* Args, PicoComms* Comms);
ShellStream* JB_Sh__Stream(JB_String* self, Array* R, int Mode);
bool JB_Sh_Step(ShellStream* self);
int JB_Str_Execute(JB_String* self, Array* R, FastString* Out, FastString* Errs, int Mode, Date Timeout);
const char** JB_Proc__CreateArgs(JB_String* self, Array* R);
int JB_Sh_StartProcess(ShellStream* self);
JB_String* JB_Sh_ReadStdErr (ShellStream* self);
JB_String* JB_Sh_ReadStdOut (ShellStream* self);
bool JB_App__TurnInto(JB_String* self, Array* R); 
typedef void (*fn_app_deathaction)();
//void JB_App__AtExit (fn_app_deathaction b);
int JB_Str_System(JB_String* self);
int JB_Kill(int PID);
int JB_Signal(int pid, int sig);
void JB_App__CrashOnInterupt (bool b);
void JB_App__SetASMBreak(bool b);
void JB_SigMsgReceived(int signum);
struct SpdProcess;
SpdProcess* JB_App__Fork(Array* R);
//int JB_Str_StartProcess (JB_String* self, Array* Args, JB_File** StdOut);
void JB_AtExit(void* func);
const char** JB_App__BackTrace(void** space, int* size);
bool JB_PipeIsClosed(int fd);
bool JB_IsTerminal(int FD);
void JB_CrashTracer();
typedef void (*fnCrashHandler)(int);
void JB_KillWithParent();
void JB__DefaultCrashHandler(int Signal);
//void JB__ErrorStackTrace(int Signal);
void JB_Rec__CrashLog(const char* c);
struct SpdProcess;
void JB_App__SetThreadName(JB_String* name);
void JB_Pipe__StdErrorSet(int F);
void JB_Pipe__StdOutSet(int F);
    
}

#endif

