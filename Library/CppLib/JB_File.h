

#ifndef __JB_FILE__
#define __JB_FILE__

#include "JB_Umbrella.h"

extern "C" {


JBClass( JB_File, JB_StringShared,
    int*            Dir;
    int*            DirEnt;
	int				OpenMode;
	int				MyFlags;
	int				Descriptor;
);


JB_String* JB_File__FileData( JB_String* Path );
int JB_File_WritePng(void* file, int w, int h, const void *data);
unsigned char* JB_LoadImage(unsigned char* data, int len, int* x, int* y, int* comp, int req_comp);
JB_String* JB_File_CurrChild (JB_File* self);
long JB_File_Test( );
JB_String* JB_File_Render(JB_File* self, FastString* fs);
bool JB_File_MoveNext(JB_File* self);
bool JB_File_ListStart( JB_File* self );
void JB_File_ListEnd( JB_File* self );
bool JB_File_ListActive( JB_File* self );

JB_Object JB_File__File( JB_File* self );
bool JB_FS_AppendPipe(FastString* self, int fd, int Mode);

JB_String* JB_Str_ResolvePath( JB_String* self, bool err );
int JB_Str_CopyFile(JB_String* self, JB_String* To, bool attronly);
int JB_File_Copy(JB_File* self, JB_File* To, bool attronly);
uint8* FastShellPath_( JB_String* Path, uint8* WriteTo );
int JB_File_Delete (JB_String* self);
u64 JB_File_Size( JB_File* self );
int JB_File_SizeSet( JB_File* self, IntPtr N );
void JB_File_Flush( JB_File* self );
bool JB_File_EOF( JB_File* self );
JB_String* JB_File_ReadAll( JB_File* self, int lim, bool Ignore );
JB_String* JB_File_PathFix_(JB_String* S);
JB_String* JB_File__Home();
JB_String* JB_File_Path(JB_File* S);
bool JB_File_IsDir (JB_File* self);
bool JB_File_IsLink (JB_File* self);
void* JB_File_IPC (JB_File* self, int* n);
void JB_munmap (void* mem, int64 n);
int JB_Str_MakeDir(JB_String* self);
JB_String* JB_File_Read(JB_File* self, IntPtr Length, bool Ignore);
JB_String* JB_File_ReadFD( int* FD, int Length, JB_String* Path );
bool JB_File_DataSet( JB_File* self, JB_String* Data );
JB_File* JB_Str_File( JB_String* Path );
JB_File* JB_File__NewPipe(int Pipe);
JB_File* JB_File__StdOut( );
bool JB_File_IsPipe(JB_File* self);
int JB_File_MoveTo(JB_File* self, JB_String* New);

bool JB_File_Exists( JB_String* self, bool LinkExists );
Date JB_File_Modified( JB_File* self );
Date JB_File_Created( JB_File* self );
bool JB_File_Create( JB_File* self );
JB_String* JB_cPath_ReadAll (const char* path, bool AllowMissingFile, int MaxFile);

long JB_File__chdir( JB_String* Path );
JB_String* JB_File__CWD( );
long JB_File_Remaining( JB_File* self );
int JB_File_Write( JB_File* self, JB_String* Data );
s64 JB_File_WriteRaw_( JB_File* self, uint8* Data, int N );
int JB_File_WriteCompressed_( JB_File* self, JB_String* str );

int JB_File_OpenBlank( JB_File* self );
int JB_File_Open(JB_File* self, int OpenFlags, bool ignore);
int JB_Str_Open(JB_String* Path, int Flags, bool Ignore);
int JB_App__GetChar();
void ErrorHandleSub_(JB_String* self, const char* Operation);
void JB_File_Constructor(JB_File* self, JB_String* Path);
int JB_File_OffsetSet( JB_File* self, s64 NewValue );
s64 JB_File_Offset( JB_File* self );
s64 JB_File_Size_( int FileDes );
int JB_File_Mode( JB_File* self );
int JB_File_ModeSet( JB_File* self, int Mode );
int JB_Str_SymLink( JB_StringC* self, JB_String* Link );
bool JB_File_HardLinkTo( JB_File* self, JB_StringC* Link );
JB_String* JB_File_LinkToGet( JB_File* self );
void JB_File_Destructor( JB_File* self );
void JB_File_Close( JB_File* self );



}

#endif

