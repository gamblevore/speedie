
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.hpp"
#include <unistd.h>
#include <errno.h>

extern "C" {


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




int JB_ErrorHandleFileC(const char* Path, int err, const char* Operation) {
	return JB_ErrorHandleFile(JB_StrC(Path), nil, err, nil, Operation);
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
		if (!str)
			str = strerror(err);
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
    free( cwd );
    JB_FS_AppendByte(FS, '/');
    JB_FS_AppendString(FS, self);
    return JB_FS_GetResult(FS);
}


int JB_ErrorHandleFile(JB_String* self, JB_String* other, int errnum, const char* BackupErr, const char* op, int Severity, const char* verb) {
	if (!errnum)
		return 0;
	JB_String* Desc = Desc_(self, other, errnum, BackupErr, op, verb);
	JB_String* Path = Path_(self);
	extern JB_Class JB_ErrorData;
	JB_Error* Err = (JB_Error*)JB_NewClass(&JB_ErrorData);
	JB_Err_Constructor(Err, 0, Desc, Severity, Path);
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



void JB_Str_Fail(JB_String* self);
void JB_OutOfUserMemory(int64 N) {
	if (++OutOfMemoryHappenedAlready <= 10) 
		JB_ReportMemoryError("Jeebox: Failed to allocate ", N, nil); 
} 

void JB_ReportMemoryError(const char* A, int64 N, const char* operation) {
    static uint8 ReportCount = 0;
    require0 (ReportCount < 10);
	FastString* FS = JB_FS__FastNew(0);
	require0 (FS);
	ReportCount++;
	JB_FS_AppendCString(FS, A);
	if (N) {
		JB_FS_AppendIntegerAsText(FS, N, 0);
		JB_FS_AppendCString(FS, " bytes of memory");
	}
	if (operation) {
		JB_FS_AppendCString(FS, " during ");
		JB_FS_AppendCString(FS, operation);
	}
	JB_Str_Fail(JB_FS_GetResult(FS));
}

}

