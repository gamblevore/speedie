
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


void JB_Str_PrintError(JB_String* s) {
	int n = JB_Str_Length(s);
    if (n) {
		MyWrite(s->Addr, n, stderr);
		if (!JB_ErrorNumber) {
			JB_ErrorNumber = 1; // terminals complain if printerror without return -1;
		}
    }
}

void JB_Str_PrintLine(JB_String* s) {
	JB_Str_Print(s);
	putchar(10);
}


void JB_Str_Print(JB_String* s) {
	int n = JB_Str_Length(s);
	if (n) {
		MyWrite(s->Addr, n, stdout);
	}
}



}


