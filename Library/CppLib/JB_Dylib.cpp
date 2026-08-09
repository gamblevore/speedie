
// Copyright, Theodore H. Smith 2025.
// Released under jeebox-licence http://jeebox.org/licence.txt


#ifndef AS_LIBRARY
#include "JB_Umbrella.hpp"
#include <stdarg.h>

extern "C" {

static void* curl_bloody_wrapper (void* curl, int Type, void* Value) {
	// writing a special-purpose wrapper like this, just for curl...
	// so I can call something lik:   int curl_easy_setopt (CURL* curl, int Type, ...)  // (varg)
	
	// That would defeat the purpose of making a dylib import system.
	
	// Now, I CAN generate the correct C++ code easily, but not compile it for Cake.
	// I would need (Mac,Linux,Windows) * (ARM,x86) ASM written, up to 6 variants of
	// the varg ASM calling code. No fun.
	
	// So is it worth continuing on this and making our C++-only dylib wrapper for vargs
	// and just error when compiling for Cake?
	return 0;
}


void* JB_dylib_Load (JB_Dylib* Self, JB_String* Name) {
	if (JB_Str_IsC(Name))
		return dlsym(Self->_handle, (const char*)(Name->Addr));
    uint8 Buffer[PATH_MAX];
    char* tmp = (char*)JB_FastFileString( Name, Buffer );
    if (!tmp)
		return 0;
	return dlsym(Self->_handle, tmp);
}

void JB_dylib_Close (JB_Dylib* Self) {
	if (Self->_handle) {
		dlclose(Self->_handle);
		Self->_handle = 0;
	}
}

const char* JB_dylib_Error (JB_Dylib* Self) {
	return dlerror();
}

bool JB_dylib_Open (JB_Dylib* Self, JB_String* Path, int Mode) {
	char* tmp = 0;
	uint8 Buffer[PATH_MAX];
	if (JB_Str_Length(Path)) {
		tmp = (char*)JB_FastFileString( Path, Buffer );
		if (!tmp)
			return false;
	}

	JB_dylib_Close(Self);
	auto R = dlopen(tmp, Mode);
	Self->_handle = R;
	return R;
}

}

#endif

