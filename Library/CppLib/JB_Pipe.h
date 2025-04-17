

#ifndef __JB_PIPE__
#define __JB_PIPE__

#include "JB_Umbrella.h"
#include "PicoMsg.h"

#define STDFUN_FILENO 3
#define STDPICO_FILENO 4

extern "C" {


JBClass( ProcessOwner, JB_RingList,
	volatile int		_Status;
	bool				KillOnExit;
	bool				LeaveOrphaned;
);

void JB_PID_Start();
ProcessOwner* JB_PID_Constructor(ProcessOwner* self);
void JB_PID_UnRegister(ProcessOwner* self);
void JB_PID_Destructor(ProcessOwner* self);
void JB_PID_Register(ProcessOwner* self);
int JB_PID_Kill (ProcessOwner* F, int Code);
void JB_KillChildrenOnExit();
//int JB_PID_Exit (ProcessOwner* F);
int JB_PID_Status (ProcessOwner* F);
JB_StringC* JB_Err_SignalName (int Sig);
JB_StringC* JB_Err_Name (int Sig);
ProcessOwner* JB_PID_Next(ProcessOwner* self);
ProcessOwner* JB_PID__First();





JBClass( ShellStream, ProcessOwner,
	bool		IsClosed;
	JB_String*  Path;
	Array*  	Args;
	FastString* Output;
	FastString* ErrorOutput;
    int			CaptureOut[2];
    int			CaptureErr[2];
    Date		LastRead;
    int64		UserFlags;
    JB_Object*	UserObj; // just like jeebox!
);



void JB_Sh_Destructor(ShellStream* self);
ShellStream* JB_Sh_Constructor(ShellStream* self, JB_String* Path);
ShellStream* JB_Sh__Stream(JB_String* self, Array* R, FastString* FSOut, FastString* FSErrIn, int Mode);
bool JB_Sh_Step(ShellStream* self);
int JB_Str_Execute(JB_String* self, Array* R, FastString* Out, FastString* Errs, int Mode, Date Timeout);
const char** JB_Proc__CreateArgs(JB_String* self, Array* R);
int JB_Sh_StartProcess(ShellStream* self, JB_String* path, Array* Args, PicoComms* C, int Mode);
int JB_Sh_UpdatePipes(ShellStream* self);
void JB_Sh_ClosePipes(ShellStream* self);
bool JB_App__TurnInto(JB_String* self, Array* R); 
typedef void (*fn_app_deathaction)();
//void JB_App__AtExit (fn_app_deathaction b);
int JB_Str_System(JB_String* self);
int JB_Kill(int PID);
int JB_Signal(int pid, int sig);
void JB_App__CrashOnInterupt (bool b);
void JB_SigChild (int signum);
void JB_SigMsgReceived(int signum);
void JB_SigChildLock ();
void JB_SigChildUnLock ();
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
bool JB_Rec__CrashLogSub(const char* c);
struct SpdProcess;
void JB_App__SetThreadName(JB_String* name);
int JB_Pipe__IgnoreBreakPoints ();
void JB_Pipe__StdErrorSet(int F);
void JB_Pipe__StdOutSet(int F);
    
}

#endif

