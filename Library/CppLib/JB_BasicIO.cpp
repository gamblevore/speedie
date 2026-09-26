
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



#include "JB_Umbrella.hpp"
#include <stdio.h>
#include <unistd.h>


extern "C" {

// Mixing write() with printf/etc causes buffering issues.
// write is a lot simpler and I can redirect it easier.

static int PrintFile = STDOUT_FILENO;

void JB_Str_PrintError(JB_String* s) {
	int n = JB_Str_Length(s);
    if (n) {
		JB_Write_(STDERR_FILENO, s->Addr, n);
		if (!JB_ErrorNumber)
			JB_ErrorNumber = 1; // terminals complain if printerror without return -1;
		fsync(STDERR_FILENO);
    }
}

void JB_PrintCString (const char* c) {
	if (c) {
		int n = strlen(c);
		if (n)
			JB_Write_(PrintFile, (u8*)c, n);
	}
}

void JB_Str_PrintLine (JB_String* s) {
	byte Buf[256];
	int n = JB_Str_Length(s);
	if (n < sizeof(Buf)) {
		if (n)
			memcpy(Buf, s->Addr, n);
		Buf[n++] = 10;
		JB_Write_(PrintFile, Buf, n);
	} else {
		JB_Write_(PrintFile, s->Addr, n);
		Buf[0] = 10;
		JB_Write_(PrintFile, Buf, 1);
	}
	fsync(PrintFile);
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


void JB_Str_Print(JB_String* s) {
	int n = JB_Str_Length(s);
	if (n) {
		JB_Write_(PrintFile, s->Addr, n);
		if (ShouldFlush_(s))
			fsync(PrintFile);
	}
}



}


