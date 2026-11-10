
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.hpp"
#include <unistd.h>
#include <errno.h>

#ifndef ELAST
	#define ELAST 4095
#endif

extern "C" {

void JB_Str_Fail(JB_String* self);
JB_Error* JB_Err_Constructor(JB_Error* self, Message* node, JB_String* desc, unsigned char level, JB_String* path);


JB_String* FreeableStr_(const char* Msg, bool CanFree) {
    // if canfree is true, then... we will call free() on dispose.
    // otherwise not.
    if (!CanFree)
        return JB_StrC(Msg);
    return JB_Str__Freeable0(Msg);
}


void JB_ErrorHandle2C(const char* Desc, bool CanFreeDesc, const char* Path, bool CanFreePath) {
	JB_Error* Err = JB_Err_Constructor(nil, 0, nil, 4, nil);
	JB_Err_Fill(Err, FreeableStr_(Path, CanFreePath), FreeableStr_(Desc, CanFreeDesc)); 
	JB_Rec_AppendErr(nil, Err);
}



// this could be used as a void*... with the high-bit set, so it can be either a string
// or a char*. Seems like a good idea?
// perhaps not... if its a file, we could block the destructor.
int JB_ErrorHandleFileC (const char* Path, int err, const char* Operation) {
	return JB_ErrorHandleFile(JB_Str_CopyFromCString(Path), nil, err, nil, Operation);
}

JB_String* JB_App__StackTrace(int Skip, FastString* Fs_in) {
	FastString* Fs = JB_FS__FastNew(Fs_in);
	int Size = 128;
	void* Arr[128] = {};
	_cstring* Strs = JB_App__BackTrace((&Arr[0]), &Size);
	int i = Skip;
	while (i < Size - 1) {
		JB_FS_AppendCString(Fs, Strs[i++]);
		JB_FS_AppendByte(Fs, '\n');
	};
	free(Strs);
	return JB_FS_SmartResult(Fs, Fs_in);
}


const char* JB_strerror (int Err) {
	if (Err == 126)
		return "StackOverFlow";
	if (Err == 127)
		return "DestructorOverFlow";
	return strerror(Err);
}


static JB_String* Desc_(JB_String* self, JB_String* other, int err, const char* str, const char* Operation, const char* verb) {
    FastString* FS = JB_FS__FastNew(0);
    static const char* EmptyPath = "Path was empty";
	if (!str) {
		if (err == ENOENT) {
			if (JB_Str_Length(self))
				str = "File doesn't exist";
			  else
				str = EmptyPath;
		}
		if (!str) {
			if (err > 0 and err < 128)
				str = JB_strerror(err);
			  else if (err >= 128 and err < 256) {
				str = strsignal(err&~128);
			}
		}
	}
	if (str)
		JB_FS_AppendCString(FS, str);
	  else
		JB_FS_AppendIntegerAsText(FS, err, 1);

	JB_FS_AppendCString(FS, " when ");
	JB_FS_AppendCString(FS, Operation);
	if (JB_Str_Length(self)) {
		JB_FS_AppendCString(FS, " '");
		JB_FS_AppendString(FS, self);
		if (JB_Str_Length(other)) {
			JB_FS_AppendCString(FS, "' ");
			if (!verb) verb = "to";
			JB_FS_AppendCString(FS, verb);
			JB_FS_AppendCString(FS, " '");
			JB_FS_AppendString(FS, other);
		}
		JB_FS_AppendCString(FS, "'.");
	}
	if (str == EmptyPath) {
		JB_FS_AppendMultiByte(FS, 10, 2);
		JB_App__StackTrace(2, FS);
	}
    return JB_FS_GetResult(FS);
}


static JB_String* Path_(JB_String* self) {
    if (!JB_Str_Length(self) or JB_Str_ByteValue(self, 0)== '/') {
        return self;
    }
    FastString* FS = JB_FS__FastNew(0);
    char* cwd = getcwd( 0, 0 );
    
    JB_FS_AppendCString(FS, cwd);
    JB_FS_AppendByte(FS, '/');
    JB_FS_AppendString(FS, self);
    free( cwd );
    return JB_FS_GetResult(FS);
}


int JB_ErrorHandleFile(JB_String* self, JB_String* other, int errnum, const char* DefaultErr, const char* op, int Severity, const char* verb) {
	if (!errnum)
		return 0;
	JB_String* Desc = Desc_(self, other, errnum, DefaultErr, op, verb);
	JB_String* Path = Path_(self);
	auto Err = JB_Err_Constructor(nil, 0, Desc, Severity, Path);
	JB_Rec_AppendErr(nil, Err);

    return errnum;
}


int64_t JB_ErrorHandleC(const char* Desc, JB_String* path, bool CanFreeDesc) {
    JB_Error* Err = JB_Err_Constructor(nil, 0, nil, 4, path);
    if (Err) {
		JB_Err_Fill(Err, nil, FreeableStr_(Desc, CanFreeDesc)); 
		JB_Rec_AppendErr(nil, Err);
	}
	return 0;
}



byte OutOfMemoryHappenedAlready;
char MemoryErrorSpace[127];

static bool ReportMemoryError (bool MainFail, int64 N) {
	if (OutOfMemoryHappenedAlready < 255)
		if (OutOfMemoryHappenedAlready++ > 10)
			return false;
	
	MainFail = false;
	const char* A = MainFail ? "Failed to allocate main object memory":"Failed to allocate array/string";
	int Count = snprintf(MemoryErrorSpace, sizeof(MemoryErrorSpace), "%s. Requested %lli ", A, N);
	if (Count > 0)
		A = MemoryErrorSpace;
	errno = MainFail?ENOMEM:ERANGE;
	perror(MemoryErrorSpace);
	
	JB_String* Str = JB_Str_CopyFromCString(MemoryErrorSpace);
	if (!Str) {				// We really are in trouble, sigh.
		Str = JB_StrC(MemoryErrorSpace);
		if (!Str)			// Still?
			exit(-1);		// Utter failiure
	}
	
	void JB_Rec__NewErrorSub(Message* Node, JB_String* Desc, JB_String* Path, uint /*ErrorSeverity*/ Sev);
	JB_Rec__NewErrorSub(nil, Str, nil, 16<<MainFail);
	
	JB_Str_Fail(Str);
	return false;
}


bool JB_OutOfUserMemory (int64 N) {
	return ReportMemoryError(false, N);
}


void JB_OutOfMainMemory (int64 N) {
// Used by the memory manager itself for blocks/objects
	ReportMemoryError(true, N);
}


bool JB_OutOfMemoryOccurred () {
    return OutOfMemoryHappenedAlready;
}


}

