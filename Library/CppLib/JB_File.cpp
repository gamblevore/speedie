
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

#ifndef AS_LIBRARY

#include "JB_Umbrella.hpp"
#include <time.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#if __linux__
	#include <sys/mman.h>
	#include <sys/sendfile.h>
#else
	#include <copyfile.h>
	#include <sys/posix_shm.h>
#endif



// The design of the system... is "errors are soft"
// That means... not being pedantic. If we try to delete a file that doesn't exist who cares?
// I want to keep this "in sync" with my existing system...
// especially for strings... where nil.length = 0

#ifdef TARGET_WIN32
    #include "JB_DirReaderWin32.h"
#else
    #include "JB_DirReaderUnix.h"
#endif



#if defined(TARGET_WIN32)
extern "C" {
	#define fsync _commit

	#ifndef S_IRWXU
		#define O_Win32Sucks   0x8000  /* really this is O_BINARY. */
		#define O_RDONLY       0x0000  /* open for reading only */
		#define O_WRONLY       0x0001  /* open for writing only */
		#define O_RDWR         0x0002  /* open for reading and writing */
		#define O_APPEND       0x0008  /* writes done at eof */

		#define O_CREAT        0x0100  /* create and open file */
		#define O_TRUNC        0x0200  /* open and truncate */
		#define O_EXCL         0x0400  /* open only if file doesn't already exist */

		#define	S_IRWXU	0x0E00		/* Permissions for file owner class */
		#define	S_IRUSR 0x0800	/* Read permission file owner class */
		#define	S_IWUSR 0x0400	/* writ permission file owner class */
		#define	S_IXUSR 0x0200	/* exec permission file owner class */
		#define S_IRWXG 0x01C0		/* permissions for file group class */
		#define	S_IRGRP 0x0100	/* Read permission file group class */
		#define	S_IWGRP 0x0080	/* writ permission file group class */
		#define	S_IXGRP 0x0040	/* exec permission file group class */
		#define S_IRWXO 0x0038		/* permissions for file other class */
		#define	S_IROTH 0x0020	/* Read permission file other class */
		#define	S_IWOTH 0x0010	/* writ permission file other class */
		#define	S_IXOTH 0x0008	/* exec permission file other class */
	#endif

#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

	
	#define close( a ) _close( a ) 
	#define lseek( a, b, c ) _lseek( a, b, c ) 
	#define read( a, b, c ) _read( a, b, c ) 
	#define write( a, b, c ) _write( a, b, c ) 
	#define getcwd( a, b ) _wgetcwd( a, b ) 
	#define chdir( a ) _wchdir( a ) 
	#define open( a, b, c ) _wopen( a, b, c ) 
	#define fstat( a, b ) _fstat( a, b )
	#define stat( a, b ) _wstat( a, b ) 
	int __cdecl		_commit(int);
	int __cdecl		_wopen(const unsigned short*, int, int);
	int __cdecl		_wstat(const unsigned short*, struct _stat*);
	int __cdecl		_wchdir(const unsigned short*);
	int __stdcall		GetCurrentDirectoryW(int Length, unsigned short* Buffer);
	u32 __stdcall		GetLongPathNameW(unsigned short* A, unsigned short* B, int Length);

	#define trchdir chdir

	int* __cdecl		_errno();

// __declspec(dllimport)
	#define errno (*_errno())
}
#else
	#define O_Win32Sucks   0
	#define _stat stat


	#ifndef S_IRWXU
		#define	S_IRWXU		0000700		/* [XSI] RWX mask for owner */
		#define	S_IRUSR		0000400		/* [XSI] R for owner */
		#define	S_IWUSR		0000200		/* [XSI] W for owner */
		#define	S_IXUSR		0000100		/* [XSI] X for owner */
		/* Read, write, execute/search by group */
		#define	S_IRWXG		0000070		/* [XSI] RWX mask for group */
		#define	S_IRGRP		0000040		/* [XSI] R for group */
		#define	S_IWGRP		0000020		/* [XSI] W for group */
		#define	S_IXGRP		0000010		/* [XSI] X for group */
		/* Read, write, execute/search by others */
		#define	S_IRWXO		0000007		/* [XSI] RWX mask for other */
		#define	S_IROTH		0000004		/* [XSI] R for other */
		#define	S_IWOTH		0000002		/* [XSI] W for other */
		#define	S_IXOTH		0000001		/* [XSI] X for other */

		#define	S_ISUID		0004000		/* [XSI] set user id on execution */
		#define	S_ISGID		0002000		/* [XSI] set group id on execution */
		#define	S_ISVTX		0001000		/* [XSI] directory restrcted delete */
	#endif
#endif


#define kDefaultMode (S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)

extern "C" {

JBClassPlace( JB_File,          JB_File_Destructor,    JB_AsClass(JB_Object),      JB_File_Render );


int JB_ErrorHandleFileC(const char* Path, int err, const char* Operation);


bool HasFD (JB_File*f) {
    return (f and f->Descriptor >= 0);
}

inline uint8* JB_FastFileThing( JB_File* S) {
	return S->Addr;
}


int64 ErrorHandleStr_(int64 MaybeErr, JB_String* self, JB_String* other, const char* Operation) {
    if (MaybeErr >= 0) {
        return MaybeErr;
    }
    JB_ErrorHandleFile(self, other, errno, nil, Operation);
    return MaybeErr;
}


int64 ErrorHandle_(int64 MaybeErr, JB_File* self, JB_File* other, const char* Operation) {
    return ErrorHandleStr_(MaybeErr, self, other, Operation);
}


int JB_Str_MakeEntirePath(JB_String* self, bool Last);
bool MakeParentPath_ (JB_String* s) {
	int Err = errno;
	if (Err != ENOENT)
		return false;
	return !JB_Str_MakeEntirePath(s, false);
}


int StrOpen_(JB_File* Path, int Flags, bool AllowMissing) {
    NativeFileChar2* CPath = (NativeFileChar2*)JB_FastFileThing( Path );

    Flags |= O_Win32Sucks |  O_CLOEXEC; // mostly we dont want this... just for shm
    int FD = open( CPath,  Flags,  kDefaultMode );
    if (FD < 0  and  Flags&O_CREAT  and  MakeParentPath_(Path))
		FD = open( CPath,  Flags,  kDefaultMode );

    if (FD >= 0)
        return FD;
    
    if ((errno == ENOENT) and AllowMissing)
        return -2;// ignore it...
	JB_ErrorHandleFile(Path, nil, errno, nil, "opening");
    return -1;
}


bool Stat_( JB_String* self, struct _stat* st, bool normal=true ) {
    if (!self) return false;
    int err = 0;
    uint8 Tmp[1024];
	auto tmp = (const char*)JB_FastFileString(self, Tmp);
	if (normal)
		err = stat( tmp, st );
	  else
		err = lstat( tmp, st );
    if (!err) return true;
	if (errno != ENOENT  and access(tmp, 0)) {
		errno = ENOENT; // sometimes we get ENOENT when it really IS a ENOENT
	}					// So we need to refill this.

	if (errno != ENOENT)
		ErrorHandleStr_(err, self, nil, "getting info on");
	return false;
}


uint8* JB_FastCString( JB_String* Path, uint8* Tmp ) {
    u32 N = JB_Str_Length( Path );
    if ( ! N ) {
        return (uint8*)"";
    }

	uint8* Result = Path->Addr;
	auto Cls = JB_ObjClass(Path); 
    if (Cls==JB_AsClass(JB_StringC) or Cls==JB_AsClass(JB_File))
        return Result;

    if (N > 1023)
        N = 1023;
	
    if (!Tmp) {
        debugger;
        return 0;
    }
    
    Tmp[ N ] = 0;
    return (uint8*)CopyBytes( Result, Tmp, N );
}


uint8* JB_FastFileString( JB_String* Path, uint8* Tmp ) { // utf-16 on windows :(? Or do we just use posix funcs?
#ifndef TARGET_WINDOWS
    return JB_FastCString(Path, Tmp);
#else
	unsigned short* Result16 = (unsigned short*)Result;
    N = local_c8to16( Result, N, &BufferData );
    if ( ! N ) {
        return 0; // error
    }
    Result16 = (unsigned short*)BufferData.Addr;
    Result16[ N / 2 ] = 0;
    return (uint8*)Result16;
#endif
}


int JB_File_OpenStart( JB_File* f, bool AllowMissing ) {
	int FD = f->Descriptor;
	if (FD >= 0) {
		JB_File_OffsetSet(f, 0); // in case it was already open... sigh.
		return FD;
	}
	return JB_File_Open( f, O_RDONLY, AllowMissing );
}


int JB_File_Open( JB_File* f, int OpenFlags, bool AllowMissing ) {
	if (!f)
		return -1;
	if (HasFD(f)  and  (OpenFlags & O_RDWR)  and  !(f->OpenMode & O_RDWR)) {
		JB_File_Close(f); // sigh
	}
	int FD = f->Descriptor;
    if (FD >= 0)
		return FD;
	FD = StrOpen_(f, OpenFlags, AllowMissing);
	if (FD >= 0) {
		f->Descriptor = FD;
		f->OpenMode = OpenFlags;
	}
    return FD;
}


int InterWrite(int fd, uint8* buffer, int N) {
    int TotalCount = 0;
    while (N > TotalCount) {
        int written = (int)write(fd, buffer+TotalCount, N-TotalCount);
        if (written == -1) {
            if (errno == EINTR) continue;
            return -1;
        }
        TotalCount += written;
    }
    return TotalCount;
}


// this function does what the C++ read function SHOULD do.
int InterRead (int fd, unsigned char* buffer, int N, JB_String* ErrorPath, int& Error, int Mode) {
    int Total = 0;
	Error = 0;
    do {
		// read has 6 possible cases! i fucking hate read()
		int nread = (int)read(fd, buffer, N);
		if (nread > 0) {				// partial
            Total += nread; buffer += nread; N -= nread;
			if (N <= 0) {
				Error = -2;
				return Total;			// finished
			}
			if (Mode == 1) {			// only single step, be responsive
				Error = -1;
				return Total;
			}
	        continue;
		}
		if (nread == 0) {
			Error = 0;
			return Total;				// finished
		}
		Error = errno; // earlier, for debug
		if (Error == EINTR)
			continue;
		if (Error==EWOULDBLOCK  or  Error==EAGAIN) {
			Error = -1;
			return Total;
		}
		if (!Error)
			Error = EIO;
		break;
    } while (true);

    if (!ErrorPath and isatty(fd))
        JB_ErrorHandleFileC(ttyname(fd), Error, "reading");
      else
        ErrorHandleStr_( -1, ErrorPath, nil, "reading" );
    
    return Total;
}


int JB_FS_InterPipe(FastString* self, int Desired, int fd, int Mode) {
	uint8* Buffer = JB_FS_WriteAlloc_(self, Desired);
	if (!Buffer) return false;
	int Error = 0;
	int N = InterRead(fd, Buffer, Desired, 0, Error, Mode); // we want to know if an error-happened or not.
	JB_FS_AdjustLength_(self, Desired, N);
	return Error;
}


int CrashLogFile = 0;
JB_StringC* JB_App__CrashLogName();
void JB_Rec__CrashLog(const char* c) {
	if (!c) return;
	puts(c);

// this filename tho... lol. fucking lack of strings...
	JB_StringC* Name = JB_App__CrashLogName();
	if (!CrashLogFile and Name) {
		mkdir("/tmp/logs", kDefaultMode);
		auto s = (const char*)(Name->Addr);
		int flags = O_RDWR | O_CREAT | O_TRUNC;
		CrashLogFile = open(s, flags, kDefaultMode);
	}
	if (!CrashLogFile) return;

    InterWrite( CrashLogFile, (u8*)c, (int)strlen(c) );
    InterWrite( CrashLogFile, (u8*)"\n", 1 );
}


bool JB_FS_AppendPipe(FastString* self, int fd, int Mode) {
	// Error:
	//	0  means finished. we wanna close. Same with errors. So (>= 0) --> close
	//  -1 means  call back later
	//  -2 means we need more buffer
    while (self) {
		int Error = JB_FS_InterPipe(self, 64 * 1024, fd, Mode);
		if (Error >=  -1) return Error == -1; // true means call back later.
											  // false  means we are finished.
    }
    return false;
}


JB_String* JB_File_ReadAll ( JB_File* self, int lim, bool AllowMissing ) {
	if (self) {
		bool WasOpen = HasFD(self);
		int FD = JB_File_OpenStart(self, AllowMissing);
		if (FD == -2)	// ignore it
			return JB_Str__Empty();
		
		if (FD >= 0) {
			u64 S = JB_File_Size(self); 
			if (S <= (u64)lim) {
				JB_String* Result = JB_File_Read( self, S, AllowMissing );
				if (!WasOpen)
					JB_File_Close(self);
				return Result;
			}
			JB_ErrorHandleFile(self, nil, EFBIG, nil, "reading");
		}
	}
	return JB_Str__Error();
}


JB_String* JB_Str_ResolvePath( JB_String* self, bool AllowMissing ) {
	JB_String* Result = JB_Str__Error();
	if (!JB_Str_Length(self))
		return Result;
	JB_String* UserPath = JB_File_PathFix_(self);
    uint8 Tmp[1024];
	uint8* Path = JB_FastFileString(UserPath, Tmp);
	if (Path) {
		char* realpath(const char* file_name, char* resolved_name);
		char* Resolved = realpath((const char*)Path, 0);
		if (Resolved)
			Result = JB_StrC( Resolved );
		  else if (!(errno == ENOENT and AllowMissing))
			JB_ErrorHandleFile(self, nil, errno, nil, "resolving path");
	}
	if (UserPath != self)
		JB_FreeIfDead(UserPath);
	
	return Result;
}


#if __linux__
	JB_String* JB_App__Path() {
		static JB_String* Result;
		if (!Result) {
			char Path[ PATH_MAX ];
			int count = (int)readlink( "/proc/self/exe", Path, PATH_MAX );
			Result = JB_Str_CopyFromPtr((u8*)(&Path[0]), count);
			JB_Incr(Result);
		}
		return Result;
	}
#else
	int _NSGetExecutablePath(char* buf, u32* length); // oh apple...
	JB_String* JB_App__Path() {
		static JB_String* Result;
		if (!Result) {
			u32 N = 0;
			_NSGetExecutablePath(0, &N);
			Result = JB_Str_New(N-1);
			_NSGetExecutablePath((char*)(Result->Addr), &N);
			JB_Incr(Result);
		}
		return Result;
	}
#endif

int JB_App__SetEnv(JB_StringC* name, JB_StringC* value) {
	if (name and value)
		return setenv((const char*)(name->Addr), (const char*)(value->Addr), 1);
	return -999;
}


static JB_String* FileAlloc( JB_File* self, IntPtr Length ) {
    JB_String* Str = JB_Str_New( Length );
    if (!Str)
		JB_ErrorHandleFile(self, nil, ENOMEM, nil, "reading");
    return Str;
}


JB_String* JB_File_Read( JB_File* self, IntPtr Length, bool AllowMissing ) {
    int FD = JB_File_Open( self, O_RDONLY, AllowMissing );
    if (FD >= 0) {
		JB_String* Str = FileAlloc( self, Length );
		if (Str) {
			int Error = 0;
			int Mode = (self->MyFlags & 2) != 0;
			Length = InterRead( FD, Str->Addr, (int)Length, self, Error, Mode );
			return JB_Str_Shrink( Str, (int)Length );
		}
	}
	return JB_Str__Error();
}


bool JB_File_EOF( JB_File* self ) {
    if (HasFD(self)) {
        off_t Cur = JB_File_Offset(self);
        if (Cur >= 0) {
            off_t End = lseek( self->Descriptor, 0, SEEK_END );
            ErrorHandle_((int)End, self, nil, "find length of");
            return Cur == End;
        }
    }
    return true;
}


int64 JB_File_WriteRaw_( JB_File* self, uint8* Data, int N ) {
    N = InterWrite( self->Descriptor, Data, N );
    return ErrorHandle_(N, self, nil, "write to");
}


int JB_File_Write( JB_File* self, JB_String* Data ) {
    if (!JB_Str_Length(Data))
		return 0;
	if (JB_File_Open( self, O_RDWR | O_CREAT, false ) >= 0 ) {
		return (int)JB_File_WriteRaw_(self, Data->Addr, Data->Length );
	}
    return -1;
}

int JB_File_WriteCString( JB_File* self, const char* Data, int Sep ) {
    if (!Data)
		return 0;
	if (JB_File_Open( self, O_RDWR | O_CREAT, false ) >= 0 ) {
		int N = (int)JB_File_WriteRaw_(self, (u8*)Data, (int)strlen(Data));
		byte Sep2 = (byte)Sep;
		if (N > 0 and Sep >= 0 and JB_File_WriteRaw_(self, (u8*)"\n", 1) > 0)
			N++;
		return N;
	}
    return -1;
}

    

void JB_File_Flush(JB_File* self) {
    if ( HasFD(self) )
        ErrorHandle_( fsync( self->Descriptor ), self, nil, "flushing" );
}


int JB_File_OpenBlank( JB_File* self ) {
	return JB_File_Open( self, O_RDWR | O_CREAT | O_TRUNC, false );
}


bool filenameis (const char* tmp, const char* match) {
	char buff[1000];
	int nw = 0;
	int nr = 0;
	while (1) {
		char s = tmp[nr++];
		if (s>='A' and s <= 'Z')
			s+=32;
		buff[nw++] = s;
		if (!s) break;
		if (s=='/' or s == '.')
			nw = 0;
	};
	if (strcmp(buff, match) == 0) {
		return true;
	} 
	
	return false;
}


int JB_Str_MakeDir(JB_String* self) {
    uint8 Buffer[1024];
    NativeFileChar2* tmp = (NativeFileChar2*)JB_FastFileString( self, Buffer );
    if (filenameis(tmp, "h") or filenameis(tmp, "cpp")  or filenameis(tmp, "txt") )
		debugger; // what?
    int err = mkdir(tmp, kDefaultMode);
    if (err == -1 and errno == EEXIST) {
        return 0; // ignore. really. I don't need this.
    }
    return (int)ErrorHandleStr_(err, self, nil, "creating a folder");
}


int JB_File_Delete (JB_String* self) {
	uint8 Tmp[1024];
    NativeFileChar2* tmp = (NativeFileChar2*)JB_FastFileString( self, Tmp );
    int err = remove( tmp );
    if (err == -1 and errno == ENOENT) {
        return 0;
    }
    return (int)ErrorHandleStr_(err, self, nil, "deleting");  // handle error
}


JB_String* JB_File_Path(JB_File* P) {
	if  (P) 
		return (JB_String*)(P->Parent); // hmmmm
	return JB_Str__Empty();
}

JB_String* Home;

JB_String* JB_File__Home() {
	if (Home)
		return Home;
	Home = JB_Incr(JB_StrC(getenv("HOME")));
	return Home;
}

JB_String* JB_Str_Preview(JB_String* P, int N);
JB_String* JB_File_PathFix_(JB_String* P) {
// creates c-strings.
	int N = JB_Str_Length(P);
	if (!N) return P;
	if (N >= PATH_MAX) {
		JB_ErrorHandleFile(JB_Str_Preview(P, 150), nil, ENAMETOOLONG, nil, "fixing-path");
		return JB_Str__Error(); // hmmm
	}
	// P = JB_File_RemoveDotDot(P); // doesnt do anything
	byte* s = P->Addr;
	if (s[0] == '/')
		return JB_Str_MakeC(P);
	FastString* fs = JB_FS__FastNew(0);
    if (s[0] == '~') {
		auto H = JB_File__Home();
		JB_FS_AppendString(fs, H);
		JB_FS_AppendSection(fs, P, 1, kMaxint);
	} else {
		const char* Created = getcwd( 0, 0 );
		JB_FS_AppendCString(fs, Created);
		if (JB_FS_Last(fs, 0) != '/')
			JB_FS_AppendByte(fs, '/');
		if (s[0] == '.' and P->Length >= 2  and  s[1] == '/') {
			JB_FS_AppendSection(fs, P, 2, kMaxint);
		} else {
			JB_FS_AppendString(fs, P);
		}
		free((void*)Created);
	}
	return JB_FS_GetResult(fs);
}


void JB_File_Constructor( JB_File* self, JB_String* Path ) {
	if (!Path)
		Path = JB_Str__Empty();
	Path = JB_File_PathFix_(Path);
	self->Addr = Path->Addr;
	self->Length = Path->Length;
	self->Parent = JB_Incr(Path); // not ideal but whatever...
    self->Descriptor = -1;
    self->MyFlags = 0;
    self->OpenMode = 0;
    self->Dir = 0;
    self->DirEnt = 0;
}


JB_String* JB_File_Render(JB_File* self, FastString* fs_in) {
    if (fs_in) {
        JB_FS_AppendString(fs_in, self);
        return 0;
	}
	return self;
}

bool JB_File_ListActive (JB_File* self) {
	return self->Dir;
}

bool JB_File_ListStart (JB_File* self) {
    int** I = (&self->Dir);
    DirReader* D = (DirReader*)I;
    self->DirEnt = 0; // in case already set?
    return InitOpenDir_( D, (const char*)JB_FastFileThing(self) );
}

void JB_File_ListEnd( JB_File* self ) {
    if (self->Dir) {
        int** I = (&self->Dir);
        DirReader* D = (DirReader*)I;
        CloseDir_(D);
        self->Dir = 0;
    }
    self->DirEnt = 0;
}

void JB_File_Destructor( JB_File* self ) {
    JB_File_Close( self );
	JB_Str_Destructor(self);
	JB_File_ListEnd(self);
}


void JB_File_StopSHM (JB_File* self) {
	if (self->MyFlags & 1) { // 1 == server!
		printf("unlinking %s\n", self->Addr);
		shm_unlink((const char*)(self->Addr));
		self->MyFlags &= ~1;
	}
}

void JB_File_CloseSub ( JB_File* self ) {
	int R = self->Descriptor;
	self->Descriptor  = -1;
	self->OpenMode = 0;
    if (R >= 0)
		ErrorHandleStr_(close( R ), self, nil, "closing");
}

void JB_File_Close ( JB_File* self ) {
	JB_File_ListEnd(self);
	JB_File_StopSHM(self);
	JB_File_CloseSub(self);
}

int JB_File_Mode( JB_File* self ) {
	struct _stat st;
    require (Stat_(self, &st));
	return st.st_mode&(7+(7<<3)+(7<<6));
}

int JB_File_ModeSet( JB_File* self, int Mode ) {
    require (self);
	auto C = (const char*)JB_FastFileThing(self);
	return chmod(C, Mode);
}


int JB_Str_SymLink( JB_StringC* Existing, JB_String* ToCreate ) {
	int Err = 0;
	if (JB_File_Exists(ToCreate, true)) {
		Err = JB_File_Delete(ToCreate);
		if (Err) {
			errno = EEXIST; // clearer error message.
		}
	}
	if (!Err) {
		uint8 Tmp[1024];
		auto Created = (const char*)JB_FastFileString(ToCreate, Tmp);
		Err	= symlink((const char*)(Existing->Addr), Created);
		
		if (Err and errno == ENOENT) {
			if (MakeParentPath_(ToCreate)) {
				Err = symlink((const char*)(Existing->Addr), Created);
			} else {
				Err = 0; // creates clearer error messages. 
			}
		}
	}
	return (int)ErrorHandleStr_(Err, ToCreate, Existing, "linking");
}


bool JB_File_HardLinkTo( JB_File* self, JB_StringC* Link ) {
	auto C	= ((const char*)JB_FastFileThing(self));
    int Err	= link(C, (const char*)(Link->Addr));
    if (Err and MakeParentPath_(Link))
		Err = link(C, (const char*)(Link->Addr));
	ErrorHandleStr_(Err, self, Link, "hardlinking");
	return !Err;
}


JB_String* JB_File_LinkToGet( JB_File* self ) {
	// symlink
	auto C = (const char*)JB_FastFileThing(self);
	char Found[1024];
	int bytes = (int)readlink((const char *)C, Found, sizeof(Found));
	return JB_Str_CopyFromPtr((uint8*)Found, bytes);
}


int JB_File_OffsetSet( JB_File* self, int64 NewValue ) {
    // no need to check for -1 FileDes if lseek handles it?
	int err = -1;
    if (HasFD(self)) {
		int Mode = SEEK_SET;
		if (NewValue < 0) {
			Mode = SEEK_END;
			NewValue = -(NewValue+1);
		}
		err = (int)lseek( self->Descriptor, NewValue, Mode ); 
		ErrorHandle_(err, self, nil, "set offset of");
	}
	return err;
}


int64 JB_File_Offset( JB_File* self ) {
    // no need to check for -1 FileDes if lseek handles it?
    int64 N = lseek( self->Descriptor, 0, SEEK_CUR );
    ErrorHandle_(N, self, nil, "get offset of");
    return N;
}



int JB_File_SizeSet( JB_File* self, IntPtr N ) {
    int err = ftruncate(self->Descriptor, N);
    ErrorHandle_(err, self, nil, "set size of");
    return err;
}


u64 JB_File_Size( JB_File* self ) {
	struct _stat st;
	return Stat_(self, &st) * (u64)st.st_size;
}


// IT MAKES NO SENSE!!!
// I got two files... the newer one is coming out with an OLDER DATE.
// it seemse USELESS. Whats the point of a date that can't be used.

Date JB_File_Modified( JB_File* self ) {
    struct _stat st = {};
    require (Stat_(self, &st))
	#if __linux__
		return JB_Date__Create(st.st_mtime, 0);//st.st_mtime_nsec);
	#else
		return JB_Date__Create(st.st_mtimespec.tv_sec, st.st_mtimespec.tv_nsec);
	#endif
}


Date JB_File_Created( JB_File* self ) {
    struct _stat st = {};
    require (Stat_(self, &st))
	#if __linux__
		return JB_Date__Create(st.st_ctime, 0);//st.st_ctime_nsec);
	#else
		return JB_Date__Create(st.st_ctimespec.tv_sec, st.st_ctimespec.tv_nsec);
	#endif
}


bool JB_File_Create( JB_File* self ) {
	if (JB_File_Exists(self, false))
		return true;
	if (JB_File_OpenBlank(self) < 0)
		return false;
	JB_File_Close(self);
	return true; // OK so... check of it exists...
}


bool JB_File_Exists( JB_String* self, bool LinkExists ) {
	if (LinkExists) {
		struct _stat st;
		return Stat_(self, &st, false);
	}
    uint8 Tmp[1024];
	auto tmp = (const char*)JB_FastFileString(self, Tmp);
	int err = access(tmp, 0);
	if (!err)
		return true;
	if (errno != ENOENT) {
		ErrorHandleStr_(err, self, nil, "testing the existance of");
	}
	return false;
}


int JB_File_MoveTo(JB_File* self, JB_String* New) {
    uint8 Buffer2[1024];
    uint8* SelfPath = JB_FastFileThing(self);
    uint8* NewPath  = JB_FastFileString(New,        Buffer2);
    int Err			= rename((const char*)SelfPath, (const char*)NewPath);
    if (Err and MakeParentPath_(New))
		Err = rename((const char*)SelfPath, (const char*)NewPath);
    ErrorHandleStr_(Err, self, New, "moving");
//    if (!Err) // causes so many bugs
//        JB_SetRef(self, New);
    return Err;
}


// copy file properly!! keeps attrs!! :)
int JB_File_Copy(JB_File* self, JB_File* To, bool AttrOnly) {
	if (!self or !To)
		return -1;
	int output	= JB_File_OpenBlank(To);
	if (output < 0)
		return -1;

	int input	= JB_File_OpenStart( self, false );
	if (input > 0) {
	#if defined(__APPLE__) || defined(__FreeBSD__)
		int mode = AttrOnly ? COPYFILE_METADATA : COPYFILE_ALL;
		int result = fcopyfile(input, output, 0, mode);							// FreeBSD / OSX 
	#else
		off_t bytesCopied = 0;
		struct stat fileinfo = {};
		if (!AttrOnly)
			fstat(input, &fileinfo);
		int result = sendfile(output, input, &bytesCopied, fileinfo.st_size);	// Linux
	#endif
	}
	
	if (result)
		JB_ErrorHandleFile(self, To, errno, nil,  "copying");
	return result;
}




#ifndef TARGET_WINDOWS
	JB_String* JB_File__CWD( ) {
		char* path = getcwd( 0, 0 );
		if (!path) {
			JB_ErrorHandleFile(nil, nil, errno, strerror(errno),  "calling-getcwd");
			return JB_Str__Error(); // sigh. it's possible, and can crash your app.
		}
		IntPtr N = strlen( path );
		while (path[N-1] == '/')		// linux is different than Mac :(
			N = N - 1;
        
        JB_String* Result = JB_Str_CopyFromPtr( (uint8*)path, (int)N+1 );
        if (Result)
			Result->Addr[N] = '/';
		free( path );
		return Result;
	}


#else
/*
	JB_String* JB_File__CWD( ) {
		u32 Length = GetCurrentDirectoryW( 0, 0 ); // includes 0 terminator.
		JB_String* Result = Str_New( Length*2, kEncUTF16 );
		if ( ! Result ) return JB_Str__Empty();

		Length = GetCurrentDirectoryW( Length, (u16*)Result->Addr ); // excludes 0 terminator. I know, windows is stupid.
		Result = ShrinkInPlace_( Result, Length*2 );
		return Result;
	}
*/
#endif



bool JB_File_DataSet( JB_File* self, JB_String* Data ) {
	bool WasOpen = HasFD(self);
	if (JB_File_Open(self, O_RDWR | O_CREAT | O_TRUNC, false)<0) {
		return false;
	}
	JB_File_SizeSet(self, 0);
	int N = JB_File_Write(self, Data);
	if (!WasOpen)
		JB_File_Close(self);
	if (N == JB_Str_Length(Data))
		return true;
	debugger; // why?
	return false;
}

JB_File* JB_File__NewPipe(int Pipe) {
	if (Pipe < 0) {
		return nil;
	}
	JB_File* F = JB_New( JB_File );
	JB_File_Constructor( F, 0 );
	F->Descriptor = Pipe;
	F->MyFlags |= 2;
	return F;
}


JB_File* JB_Str_File( JB_String* Path ) {
	// || f = .resolve.file
	// if resolve fails, file should be nil?
	if (Path != JB_Str__Error()) {
		JB_File* F = JB_New( JB_File );
		JB_File_Constructor( F, Path );
		return F;
	}
	return 0;
}


long JB_File__chdir( JB_String* Path ) {
    uint8 Buffer1[1024];
	long err = trchdir( (NativeFileChar2*)JB_FastFileString( Path, Buffer1 ) );
	return ErrorHandleStr_(err, Path, nil, "calling chdir"); 
}
    
bool JB_File_MoveNext(JB_File* self) {
    int** I = (&self->Dir);
    DirReader* D = (DirReader*)I;
    self->DirEnt = (int*)ReadDir_(D);
    return self->DirEnt;
}

 
JB_String* JB_File_CurrChild (JB_File* self) {
    dirent* Child = (dirent*)self->DirEnt;
    if (!Child)
        return JB_Str__Empty();
    
    const char* ChildName = Child->d_name;
#ifdef TARGET_API_MAC_OS
    u32 NameLength = Child->d_namlen;
    if ( ! NameLength ) NameLength = strlen( ChildName );
#else
    u32 NameLength = (u32)strlen( ChildName );
#endif

    return JB_Str_CopyFromPtr( (uint8*)ChildName, (int)NameLength );
}


bool JB_File_IsDir (JB_File* self) {
    struct stat st = {};
    return Stat_(self, &st) and S_ISDIR(st.st_mode);
}


bool JB_File_IsLink (JB_File* self) {
	struct stat st = {};
	return Stat_(self, &st, false) and S_ISLNK(st.st_mode);
}


#define SavedParentIPC 321


void* JB_File_IPC (JB_File* self, int* np) {
	if (self->Descriptor >= 0) {
		JB_ErrorHandleFile(self, nil, EISCONN, nil, "shm_open");
		return 0;
	}	
	
	MakeParentPath_(self);
	int Mode = O_RDWR;
	bool Srv = *np;
	const char* Try = 0;
	int Err = 0;
	int FD = -1;
	if (Srv) {
		Try  = "shm_unlink"; // create in a clean space
		Err  = shm_unlink((const char*)(self->Addr));
		if (Err == -1 and errno == ENOENT)
			Err = 0;
		Mode |= O_CREAT;
	} else if (!JB_LibIsThreaded()) {
		// makse no sense from not the main thread...
		struct stat Dummy;
		if (!fstat(SavedParentIPC, &Dummy))
			FD = SavedParentIPC;
	}
	
	if (!Err and FD < 0) {
		Try = "shm_open";
		FD = shm_open((const char*)self->Addr, Mode, S_IRUSR|S_IWUSR);
	}
	if (FD >= 1) {
		self->Descriptor = FD;
		self->MyFlags = (int)Srv;
		if (Srv) {
			*np = JB_Int_RoundUp(*np, getpagesize());
			Try = "fcntl";
			int fdflags = fcntl(FD, F_GETFD);
			if (fdflags == -1)
				Err = fdflags;
			  else
				Err = fcntl(FD, F_SETFD, fdflags &~ FD_CLOEXEC);
			if (!Err) {
				Try = "ftruncate";
				Err = ftruncate(FD, *np);
			}
		} else {
			struct _stat st;
			Try = "fstat";
			if ((Err = fstat( FD, &st )) == 0) {
				*np = (int)st.st_size;
				if (!JB_LibIsThreaded()) 
					dup2(FD, SavedParentIPC); // store it... so restarted processes can pick it up again.
			}
		}
		if (!Err and *np) {
			Try = "mmap";
			void* Result = mmap(0, *np, PROT_READ | PROT_WRITE, MAP_SHARED, FD, 0);
			if (Result != MAP_FAILED)
				return Result;
		}
	}
    JB_ErrorHandleFile(self, nil, errno, nil, Try);
	return 0;
}


void JB_munmap (void* mem, int64 n) {
	ErrorHandle_(munmap(mem, n), nil, nil, "un-memmap");
}



}

#else 

// stop linker errors
extern "C" void Stub_JB_File() {}

#endif


