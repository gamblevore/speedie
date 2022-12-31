

#ifndef __JB_ERRORS__
#define __JB_ERRORS__

#include "JB_Umbrella.h"

extern "C" {
extern int JB_ErrorNumber;
int JB_ErrorHandleFile(JB_String* self, JB_String* other, int errno, const char* errmsg, const char* Operation);
int JB_ErrorHandleC(const char* Msg, bool CanFree);

}

#endif

