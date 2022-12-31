


#ifndef  __JB_SAFE__
#define  __JB_SAFE__

extern "C" {

// Gives us some way to interact with the main system...
// but WITHOUT recompiling or including "jb.h"...
// or else... we get slow recompiles, and also it's bad coding style.

struct JB_Error;
struct JB_ErrorReceiver;
struct Array;
struct Dictionary;
struct Message;
extern JB_ErrorReceiver* JB_StdErr;


JB_Error* JB_Err__New(Message* Msg, JB_String* Desc, unsigned char Level, JB_String* Path);
void JB_Rec_NewItem(JB_ErrorReceiver* self, JB_Error* Err);
void JB_Rec_NewItemWithNode(JB_ErrorReceiver* self, Message* node, JB_String* Desc);
bool JB_Rec_OK(JB_ErrorReceiver* self);
void JB_Err_Fill(JB_Error* Err, JB_String* Path, JB_String* Desc ); 

int JB_Init_();
struct JB_App;
int JB_Main();


Dictionary* JB_Dict__New();

}


#endif // __JB_SAFE__



