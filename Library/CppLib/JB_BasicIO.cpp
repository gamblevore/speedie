
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


// Mixing write() with printf/puts/etc causes buffering issues.
// This is why I don't use write() here.
 

void JB_Str_PrintError(JB_String* s) {
	int n = JB_Str_Length(s);
    if (n) {
		MyWrite(s->Addr, n, stderr);
		if (!JB_ErrorNumber)
			JB_ErrorNumber = 1; // terminals complain if printerror without return -1;
		fflush(stderr);
    }
}


void JB_Str_PrintLine(JB_String* s) {
	int n = JB_Str_Length(s);
	if (n)
		MyWrite(s->Addr, n, stdout);
	putchar(10);
	fflush(stdout);
}


static bool ShouldFlush_ (JB_String* s) {
	// kinda makes more sense that a thread would check the buffer.
	// it would only have to check like 64-bytes anyhow.
	// or none, if the buffer over 64-bytes big.
	int n = s->Length;
	if (n > 64)
		return true;
	
	auto c = s->Addr;
	while (--n >= 0)
		if (c[n] == 10)
			return true;
	
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


