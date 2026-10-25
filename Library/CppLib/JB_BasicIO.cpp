
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



#include "JB_Umbrella.hpp"
#include "JB_File.h"
#include <stdio.h>
#include <unistd.h>


#define __PRINTF__ AS_LIBRARY

extern "C" {

// Mixing write() with printf/etc causes buffering issues.
// write is a lot simpler and I can redirect it easier.
// perhaps printf is better if stdout/stderr are NOT being written to...
// by a file class or by PrintFile?
// a more generic system might be good.

#if !__PRINTF__
	static int PrintFile = STDOUT_FILENO;
#endif


void JB_File_UseAsStdOut (JB_File* f) {
#if __PRINTF__
	// can't do it! its just for libjeebox... so... that doesnt redirect stdout.
#else
	if (f) {
		int D = f->Descriptor;
		if (D >= 0) {
			f->FileFlags |= 4;
			PrintFile = D;
		}
	} else {
		PrintFile = STDOUT_FILENO;
	}
#endif
}

void JB_Str_PrintError (JB_String* s) {
	int n = JB_Str_Length(s);
	if (!n) return;
#if __PRINTF__
	fprintf(stderr, "%.*s", s->Length, s->Addr);
#else
	JB_Write_(STDERR_FILENO, s->Addr, n);
	if (!JB_ErrorNumber)
		JB_ErrorNumber = 1; // terminals complain if printerror without return error
	fsync(STDERR_FILENO);
#endif
}

void JB_PrintCString (const char* c) {
#if __PRINTF__
	printf("%s", c);
#else
	if (c) {
		int n = strlen(c);
		if (n)
			JB_Write_(PrintFile, (u8*)c, n);
	}
#endif
}

void JB_Str_PrintLine (JB_String* s) {
	if (!s)
		s = JB_Str__Empty();
	int n = s->Length;
#if __PRINTF__
	printf("%.*s\n", n, s->Addr);
#else
	byte Buf[256];
	if (n < sizeof(Buf)) {
		if (n)
			memcpy(Buf, s->Addr, n);
		Buf[n++] = 10;
		JB_Write_(PrintFile, Buf, n);		// only one write() call
	} else {
		JB_Write_(PrintFile, s->Addr, n);
		Buf[0] = 10;
		JB_Write_(PrintFile, Buf, 1);		// two write() calls
	}
	fsync(PrintFile);
#endif
}


static bool ShouldFlush_ (JB_String* s) {
	// kinda makes more sense that a thread would check the buffer.
	// it would only have to check like 64-bytes anyhow.
	// or none, if the buffer over 64-bytes big.
	
	// this will do for now though.
	int n = s->Length;
	if (n > 64)
		return true;
	
	auto c = s->Addr;
	while (--n >= 0)
		if (c[n] == 10)
			return true;
	
	return false;
}


void JB_Str_Print (JB_String* s) {
	if (!s)
		s = JB_Str__Empty();
	int n = s->Length;
#if __PRINTF__
	printf("%.*s", n, s->Addr);
#else
	if (n) {
		JB_Write_(PrintFile, s->Addr, n);
		if (ShouldFlush_(s))
			fsync(PrintFile);
	}
#endif
}



}


