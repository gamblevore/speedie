
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

#include "JB_Umbrella.hpp"
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>


extern "C" {
static JB_String* jb_lib_file_err(const char* path, const char* op) {
    JB_ErrorHandleFileC(path, errno, op);
    return JB_Str__Empty();
}
    

static int GetFileSize(const char* filename) {
    struct stat stat_buf;
    int rc = stat(filename, &stat_buf);
    return rc == 0 ? (int)stat_buf.st_size : -1;
}


JB_String* JB_CPath_ReadAll (const char* path, bool AllowMissingFile, int MaxFile) {
    FILE* fp = fopen(path, "rb");
    if (!fp) {
        if (AllowMissingFile and errno == ENOENT) {
            return JB_Str__Empty();
        }
        return jb_lib_file_err(path, "opening");
    }

    JB_String* Result = 0;
    int N = GetFileSize(path);
    if (N < 0) {
        jb_lib_file_err(path, "opening");
    } else {
        Result = JB_Str_New(N+1);
        if (!Result) {
            jb_lib_file_err(path, "allocating memory for");
        } else {
            int Size = (int)fread(JB_Str_Address(Result), 1, N, fp);
            if (ferror(fp)) {
                jb_lib_file_err(path, "reading");
                JB_Delete((FreeObject*)Result); Result = 0;
            } else {
				Result->Length = Size;
                Result->Addr[Size] = 0; // make life easier for c-folks.
            }
        }
    }
    
    fclose(fp);
    return Result;
}


}


