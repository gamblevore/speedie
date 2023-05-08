
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.hpp"
#include <unistd.h>
#include <errno.h>

extern "C" {


JB_String* FreeableStr_(const char* Msg, bool CanFree) {
    // if canfree is true, then... we will call free() on dispose.
    // otherwise not.
    if (!CanFree) {
        return JB_StrC(Msg);
    }
    JB_String* Str = JB_New( JB_String );
    Str->Addr = (uint8*)Msg;
    Str->Length = (int)strlen(Msg);
    return Str;
}


void JB_ErrorHandle2C(const char* Desc, bool CanFreeDesc, const char* Path, bool CanFreePath) {
    JB_Error* Err = JB_Err__New(0, nil, 4, nil);
    JB_Err_Fill(Err, FreeableStr_(Path, CanFreePath), FreeableStr_(Desc, CanFreeDesc)); 
    JB_Rec_NewItem(JB_StdErr, Err);
}




int JB_ErrorHandleFileC(const char* Path, int err, const char* Operation) {
	return JB_ErrorHandleFile(JB_StrC(Path), nil, err, nil, Operation);
}


static JB_String* Desc_(JB_String* self, JB_String* other, int err, const char* str, const char* Operation) {
    FastString* FS = JB_FS__FastNew(0);
	if (!str) {
		if (err == ENOENT) {
			if (JB_Str_Length(self))
				str = "File doesn't exist";
			  else
				str = "Path was empty";
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
	if (self) {
		JB_FS_AppendCString(FS, " '");
		JB_FS_AppendString(FS, self);
		if (JB_Str_Length(other)) {
			JB_FS_AppendCString(FS, "' to '");
			JB_FS_AppendString(FS, other);
		}
		JB_FS_AppendCString(FS, "'.");
	}
    return JB_FS_GetResult(FS);
}


static JB_String* Path_(JB_String* self) {
    if (!self or JB_Str_ByteValue(self, 0)== '/') {
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


int JB_ErrorHandleFile(JB_String* self, JB_String* other, int errnum, const char* BackupErr, const char* op) {
	if (!errnum)
		return 0;
    JB_String* Desc = Desc_(self, other, errnum, BackupErr, op);
    JB_String* Path = Path_(self);
    JB_Error* Err = JB_Err__New(0, Desc, 4, Path);
    JB_Rec_NewItem(JB_StdErr, Err);

    return errnum;
}


int JB_ErrorHandleC(const char* Desc, bool CanFreeDesc) {
    JB_Error* Err = JB_Err__New(0, nil, 4, nil);
    if (!Err) {
        return -1;
    }
    JB_Err_Fill(Err, nil, FreeableStr_(Desc, CanFreeDesc)); 
    JB_Rec_NewItem(JB_StdErr, Err);
    return 0;
}



void JB_Str_SyntaxExpect(JB_String* self);
void JB_OutOfUserMemory(int N) {
	if (++OutOfMemoryHappenedAlready <= 10) 
		JB_ReportMemoryError("Jeebox: Failed to allocate ", N, nil); 
} 

void JB_ReportMemoryError(const char* A, int N, const char* operation) {
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
	JB_Str_SyntaxExpect(JB_FS_GetResult(FS));
}

}

