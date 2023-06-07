

#ifndef __JB_PIPE__
#define __JB_PIPE__

#include "JB_Umbrella.h"

extern "C" {

JBClass( ShellStream, JB_Object,
	int Mode;
	int PID;
	int ErrorCode;
	JB_String*  Path;
	FastString* Output;
	FastString* ErrorOutput;
    int CaptureOut[2]; // remove these? they are just temps?
    int StdErrPipe[2]; // check if they are!
    Date LastRead;
    int64 UserFlags;
    JB_Object* UserObj; // just like jeebox!
);



void JB_Sh_Destructor(ShellStream* self);
void JB_Sh_Constructor(ShellStream* self);
ShellStream* JB_Sh__New(JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn);
bool JB_Sh_Step(ShellStream* self);
int JB_Str_Execute(JB_String* self, Array* R, FastString* Out, FastString* Errs, bool KeepStdOut);
int JB_App__TurnInto(JB_String* self, Array* R);
typedef void (*fn_app_deathaction)();
void JB_App__AtExit (fn_app_deathaction b);
int JB_ArrayPrepare_(JB_String* self, const char** argv, Array* R);
int JB_Str_System(JB_String* self);
int JB_Kill(int PID);
int JB_Str_StartProcess (JB_String* self, Array* Args, JB_File** StdOut);
void JB_AtExit(void* func);
bool JB_PipeIsClosed(int fd);
bool JB_IsTerminal(int FD);
void JB_CrashTracer();
const char** JB_BackTrace(void** space, int* size);
typedef void (*JB_CrashHandler)(int);
int JB_App__BelongsToParent();
void JB__DefaultCrashHandler(int Signal);
void JB__ErrorStackTrace(int Signal);
void JB_Rec__CrashLog(const char* c);
struct Process;
typedef int	(*fn_pth_wrap)(Process* obj);
int JB_ThreadStart (fn_pth_wrap wrap, JB_Object* IPC, bool join);
int JB_Pipe__IgnoreBreakPoints ();
void JB_Pipe__StdErrorSet(int F);
void JB_Pipe__StdOutSet(int F);
    
}

#endif

