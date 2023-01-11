
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



#include "JB_Umbrella.hpp"
#include "JB_Log.h"
#include <stdio.h>
#ifndef AS_LIBRARY
#include <unistd.h>
#endif



extern "C" {


int StdOutFD_ = 1;
int StdErrFD_ = 2;
   
void JB_Pipe__StdErrorSet(int F) {
    StdErrFD_ = F;
}


void JB_Pipe__StdOutSet(int F) {
    StdOutFD_ = F;
}

#ifndef AS_LIBRARY
static void PrintTo(JB_String* s, int Num) {
    int N = JB_Str_Length( s );
    if ( N ) {
        write( Num, (const char*)s->Addr, N );
    }
}

void JB_Str_PrintError(JB_String* s) {
    if (JB_Str_Length(s)) {
		PrintTo(s, StdErrFD_);
		if (!JB_ErrorNumber) {
			JB_DoAt(0);
			JB_ErrorNumber = -1; // terminals complain if printerror without return -1;
		}
    }
}

void JB_Str_Print(JB_String* s) {
    PrintTo(s, StdOutFD_);
}
void JB_Str_PrintLine(JB_String* s) {
	JB_Str_Print(s);
	PrintTo(JB_Str__Byte('\n'), StdOutFD_);
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


