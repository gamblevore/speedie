

#ifndef __JB_ERRORS__
#define __JB_ERRORS__

#include "JB_Umbrella.h"

extern "C" {
extern byte JB_ErrorNumber;
int JB_ErrorHandleFile(JB_String* self, JB_String* other, int errno, const char* errmsg, const char* Operation, int Severity=4, const char* verb=0);
int64_t JB_ErrorHandleC(const char* Desc, JB_String* path, bool CanFreeDesc);
int JB_ErrorHandleFileC(const char* Path, int err, const char* Operation);
JB_String* JB_App__StackTrace(int Skip, FastString* Fs_in);

}

#endif

