
// Copyright, Theodore H. Smith 2025.
// Released under jeebox-licence http://jeebox.org/licence.txt


#ifndef AS_LIBRARY
#include "JB_Umbrella.hpp"

extern "C" void* JB_dylib_Load (JB_Dylib* Self, JB_String* Name) {
	if (JB_Str_IsC(Name)) {
		return dlsym(Self->handle, (const char*)(Name->Addr));
	}
    uint8 Buffer[PATH_MAX];
    NativeFileChar2* tmp = (NativeFileChar2*)JB_FastFileString( Name, Buffer );
	return dlsym(Self->handle, tmp);
}

extern "C" void JB_dylib_Open (JB_Dylib* Self, JB_String* Path, int Mode) {
	if (Self->handle)
		dlclose(Self->handle);
	if (!JB_Str_Length(Path)) {
		Self->handle = dlopen(0, RTLD_LAZY);
		return;
	}
    uint8 Buffer[PATH_MAX];
    NativeFileChar2* tmp = (NativeFileChar2*)JB_FastFileString( Path, Buffer );
	Self->handle = dlopen(tmp, Mode);
}

#endif

