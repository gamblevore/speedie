
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



#include "JB_Umbrella.hpp"
#include <stdio.h>
#ifndef AS_LIBRARY
#include <unistd.h>
#endif



extern "C" {

#ifndef AS_LIBRARY
//void JB_PrintStackTrace();
static void SendToStdOut(uint8* d, int N) {
//	static bool InPrint;
//	if (!InPrint) {
//		InPrint = true;
//		JB_PrintStackTrace();
//		InPrint = false;
//	}
	JB_Write_( STDOUT_FILENO, d, N );
}

void JB_Str_PrintError(JB_String* s) {
	int N = JB_Str_Length(s);
    if (N) {
        JB_Write_( STDERR_FILENO, s->Addr, N );
		if (!JB_ErrorNumber) {
			JB_ErrorNumber = 1; // terminals complain if printerror without return 1;
		}
    }
}

void JB_Str_Print(JB_String* S) {
	if (S)
		SendToStdOut(S->Addr, S->Length);
}

//FastString* PrintCapturer;
//FastString** JB_Str_PrintCapturer() {
//	return &PrintCapturer;
//}

void JB_Str_PrintLine(JB_String* S) {
	JB_Str_Print(S);
	SendToStdOut( (uint8*)"\n", 1 );
//	auto P = PrintCapturer;
//	if_rare (P) {
//		JB_FS_AppendLine(P, S);
//	}
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
			JB_ErrorNumber = 1; // terminals complain if printerror without return -1;
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


