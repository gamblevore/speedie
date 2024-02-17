
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



#include "JB_Umbrella.hpp"
#include <stdio.h>
#ifndef AS_LIBRARY
#include <unistd.h>
#endif



extern "C" {

#ifndef AS_LIBRARY
static void SendToStdOut(uint8* d, int N) {
	JB_Write( STDOUT_FILENO, d, N );
}

void JB_Str_PrintError(JB_String* s) {
	int N = JB_Str_Length(s);
    if (N) {
        JB_Write( STDERR_FILENO, s->Addr, N );
		if (!JB_ErrorNumber) {
			JB_DoAt(0);
			JB_ErrorNumber = -1; // terminals complain if printerror without return -1;
		}
    }
}

void JB_Str_Print(JB_String* s) {
	if (s)
		SendToStdOut(s->Addr, s->Length);
}

void JB_Str_PrintLine(JB_String* s) {
	JB_Str_Print(s);
	SendToStdOut( (uint8*)"\n", 1 );
}

#else

static const char* StrAddr(JB_String* s) {
	if (!s)
		return "";
	return (const char*)(s->Addr);
}

void JB_Str_PrintError(JB_String* s) {
    if (JB_Str_Length(s)) {
		fprintf(stderr, "%s", StrAddr(s)); // in wierd environments. also faster.
		if (!JB_ErrorNumber) {
			JB_DoAt(0);
			JB_ErrorNumber = -1; // terminals complain if printerror without return -1;
		}
    }
}

void JB_Str_PrintLine(JB_String* s) {
	puts(StrAddr(s)); // in wierd environments. also faster.
}

void JB_Str_Print(JB_String* s) {
	printf("%s", StrAddr(s)); // in wierd environments. also faster.
}

#endif




}


