
// Copyright, Theodore H. Smith 2025.
// Released under jeebox-licence http://jeebox.org/licence.txt


#ifndef AS_LIBRARY
#include "JB_Umbrella.hpp"

extern "C" void* JB_dylib_Load (JB_Dylib* Self, JB_String* Name) {
	if (JB_Str_IsC(Name))
		return dlsym(Self->_handle, (const char*)(Name->Addr));
    uint8 Buffer[PATH_MAX];
    char* tmp = (char*)JB_FastFileString( Name, Buffer );
    if (!tmp)
		return 0;
	return dlsym(Self->_handle, tmp);
}

extern "C" void JB_dylib_Close (JB_Dylib* Self) {
	if (Self->_handle) {
		dlclose(Self->_handle);
		Self->_handle = 0;
	}
}

extern "C" bool JB_dylib_Open (JB_Dylib* Self, JB_String* Path, int Mode) {
	char* tmp = 0;
	uint8 Buffer[PATH_MAX];
	if (JB_Str_Length(Path)) {
		tmp = (char*)JB_FastFileString( Path, Buffer );
		if (!tmp)
			return false;
	}

	JB_dylib_Close(Self);
	Self->_handle = dlopen(tmp, Mode);
	return Self->_handle;
}

#endif

