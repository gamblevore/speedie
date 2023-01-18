

#ifndef __JB_PIPE__
#define __JB_PIPE__

#include "JB_Umbrella.h"

extern "C" {

JBClass( ShellStreamer, JB_Object,
	int PID;
	int Err;
	int Mode;
	FastString* FSOut;
	FastString* FSErr;
    int CaptureOut[2];
    int StdErrPipe[2];
    Date Last;
);



void JB_Sh_Destructor(ShellStreamer* self);
void JB_Sh_Constructor(ShellStreamer* self);
ShellStreamer* JB_Sh__New(JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn);
bool JB_Sh_Step(ShellStreamer* self);
int JB_Str_Execute(JB_String* self, Array* R, FastString* Out, FastString* Errs, bool KeepStdOut);
int JB_App__TurnInto(JB_String* self, Array* R);
typedef void (*fn_app_deathaction)();
void JB_App__AtExit (fn_app_deathaction b);
int JB_ArrayPrepare_(JB_String* self, const char** argv, Array* R);
int JB_Str_System(JB_String* self);
int JB_Kill(int PID);
JB_File* JB_Str_StartIPC (JB_String* self, Array* Args, int* PID);
void JB_AtExit(void* func);
bool JB_PipeIsClosed(int fd);
bool JB_IsTerminal(int FD);
void JB_PrintStackTrace();
const char** JB_BackTrace(void** space, int* size);
typedef void (*JB_CrashHandler)(int);
void JB_App__CrashInstall(JB_CrashHandler P);
int JB_App__BelongsToParent();
void JB__DefaultCrashHandler(int Signal);
void JB_Rec__CrashLog(const char* c);
struct Process;
typedef int	(*fn_pth_wrap)(Process* obj);
int JB_ThreadStart (fn_pth_wrap wrap, JB_Object* IPC, bool join);
int JB_Pipe__Ignore (int Signal);
void JB_Pipe__StdErrorSet(int F);
void JB_Pipe__StdOutSet(int F);
    
}

#endif

