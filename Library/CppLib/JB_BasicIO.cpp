
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
static void MyWrite_(int F, const char* s, int N) {
    write(F, s, N); // avoid writing to files if it's just jeebox!
}


void JB_Str_PrintError(JB_String* s) {
    if (JB_Str_Length(s)) {
		JB_Str_PrintTo(s, StdErrFD_);
		if (!JB_ErrorNumber) {
			JB_DoAt(0);
			JB_ErrorNumber = -1; // terminals complain if printerror without return -1;
		}
    }
}

#else

static void MyWrite_(int F, const char* s, int N) {
    printf("%.*s", N, s);
}
void JB_Str_PrintError(JB_String* s) {
    JB_Str_PrintTo(s, StdErrFD_);
}

#endif


void JB_Str_PrintTo(JB_String* s, int Num) {
    int N = JB_Str_Length( s );
    if ( N ) {
        MyWrite_( Num, (const char*)s->Addr, N );
    }
}

void JB_Str_PrintLine(JB_String* s) {
    JB_Str_PrintTo(s, StdOutFD_);
    MyWrite_( StdOutFD_, "\n", 1 );
}

void JB_Str_Print(JB_String* s) {
    JB_Str_PrintTo(s, StdOutFD_);
}




}


