
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



#include "JB_Umbrella.hpp"
#include <stdio.h>


extern "C" {

#ifndef AS_LIBRARY
	#define MyWrite(s,n,c)		fwrite(s, 1, n, c) // faster?
#else
	#define MyWrite(s,n,c)		fprintf(c, "%.*s", n, s)
#endif


// It is bad practice to write() to stdout... (fwrite() is OK)
// unless thats ALL you do. For example, many other parts of the program
// might call printf. If any do, (even some lib I'm using), the results
// can be inter-mixed. 

// However, at least write() will flush! sigh. I found 
// fwrite() and even putchar(10) on MacOSX DOES NOT flush! 
 

void JB_Str_PrintError(JB_String* s) {
	int n = JB_Str_Length(s);
    if (n) {
		MyWrite(s->Addr, n, stderr);
		if (!JB_ErrorNumber) {
			JB_ErrorNumber = 1; // terminals complain if printerror without return -1;
		}
		fflush(stdout);
    }
}

void JB_Str_PrintLine(JB_String* s) {
	int n = JB_Str_Length(s);
	if (n) {
		MyWrite(s->Addr, n, stdout);
	}
	putchar(10);
	fflush(stdout);
}


static bool ShouldFlush_ (JB_String* s) {
	int n = s->Length;
	if (n > 128)
		return true;
	auto c = s->Addr;
	while (--n >= 0) {
		if (c[n] == 10)
			return true;
	}
	return false;
}


void JB_Str_Print(JB_String* s) {
	int n = JB_Str_Length(s);
	if (n) {
		MyWrite(s->Addr, n, stdout);
		if (ShouldFlush_(s))
			fflush(stdout);
	}
}



}


