
/*
	Copyright (C) 2005 Theodore H. Smith.
*/



#ifndef __MSR__
#define __MSR__

#include "JB_Umbrella.h"


extern "C" {



	// Function Declarations


JB_String* JB_MSR_ReplaceAll(Dictionary* self, JB_String* Data, FastString* fs, JB_ErrorReceiver* Rec);
void JB_MSR_DecodeEntitySet(Dictionary* self, bool IsParam);
void JB_MSR_EscapeCodeSet(Dictionary* self, bool Value);
JB_String* JB_MSR_Dictionary(Dictionary* self);
int JB_MSR_Search( Dictionary* self, JB_String* Data, int Start, int Length, int* FoundLen );
int JB_MSR_Search0( Dictionary* self, JB_String* Data, int Start, int Length );
JB_String* JB_MSR_ReorderCombiners( Dictionary* self, JB_String* Data );


} // ExternCEnd

#endif // __MSR__

