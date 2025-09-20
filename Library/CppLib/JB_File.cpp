
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

#include "JB_Umbrella.hpp"
#include <time.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#include <termios.h>    // struct termios, tcgetattr(), tcsetattr()
#include <pwd.h>

#if __linux__
	#include <sys/mman.h>
	#include <sys/sendfile.h>
	#include <linux/limits.h>
#else
	#include <copyfile.h>
	#include <sys/posix_shm.h>
#endif



// The design of the system... is "errors are soft"
// That means... not being pedantic. If we try to delete a file that doesn't exist who cares?

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


#define kDefaultMode (0775)

extern "C" {

JBClassPlace( JB_File,          JB_File_Destructor,    JB_AsClass(JB_StringShared),      JB_File_Render );


int SudoRelax = 1;		// seems actually preferable for MOST tools. To NOT write root files.
int CrashLogFile = 0;
extern const char* JB_CrashLogFileName;


int JB_ErrorHandleFileC(const char* Path, int err, const char* Operation);
extern uint Flow_Disabled;

void JB_Flow__ReportStringData(u8* Addr, int Length, u8* Name, int NameLen) {
#ifndef AS_LIBRARY
	if (!Flow_Disabled) {
		uint64 Hash = JB_CRC(Addr, Length, 0);
		Hash = Hash xor (Hash >> 32);
		JB_String A;
		JB_String B;
		A.Addr = (u8*)(&Hash);
		A.Length = 8;
		B.Addr = Name;
		B.Length = NameLen;
		void JB_Flow__Input(JB_String* data, JB_String* name);
		int p = 8;
		for (int i = 0; i < 4; i++) {
			auto C = (Hash >> i*8)&255;
			A.Addr[--p] = '@' + (C&15);
			A.Addr[--p] = '@' + (C>>4);
		}
		JB_Flow__Input(&A, &B);
	}
#endif
}

inline void JB_Flow__Report(JB_String* data, JB_String* name) {
#ifndef AS_LIBRARY
	if (!Flow_Disabled)
		JB_Flow__ReportStringData(data->Addr, data->Length, name->Addr, name->Length);
#endif
}


bool HasFD (JB_File*f) {
    return (f and f->Descriptor >= 0);
}

inline uint8* JB_FastFileThing(JB_File* S) {
	return S->Addr;
}

int64 ErrorHandle_(int64 MaybeErr, JB_String* self, JB_String* other, const char* Operation) {
    if (MaybeErr >= 0) {
        return MaybeErr;
    }
    JB_ErrorHandleFile(self, other, errno, nil, Operation);
    return MaybeErr;
}


int JB_File__RelaxSudo(int Active) {
	SudoRelax += Active;
	return SudoRelax;
}


static bool IsRootOrBad_ (const char* C) {
	if (!C or strlen(C) == 0) {
		return true;
	}
	if (strcmp(C, "root") == 0) {
		return true;
	}
	return false;
}


static const char* GetRealUser_() {
	auto C = getenv("SUDO_USER");
	if (IsRootOrBad_(C)) {
		C = getenv("LOGNAME");
		if (IsRootOrBad_(C)) {
			C = getlogin();
			if (IsRootOrBad_(C)) {
				return 0;
			}
		}
	}
	return C;
}


static int SmartGetUID (int &G, int &U, JB_String* ErrPath) {
	if (geteuid()) {
		return -1; // no need? everything is hunkydory.
	}
	
	// we are probably root.
	auto Name = GetRealUser_();
	if (!Name) {
		return -1; // OK so we can't find the real user's name. That is a fail.
	}
	
	auto pwd = getpwnam(Name);
	if (pwd) {
		G = pwd->pw_gid;
		U = pwd->pw_uid;
		return 1;
	}
	return -1; // failed?
}


static bool IsLink_(const char* Path) {
	struct _stat st;
	auto s = lstat( Path, &st );
	return (s == 0) and S_ISLNK(st.st_mode);
}


static int RelaxPath_(const char* Path, bool NeedsMode, JB_String* ErrPath) {
	// sometimes doing stuff in sudo leaves "root" owned files all over
	// which is not what we wanted.
	require (SudoRelax > 0);
	static int ChangeOwner;
	static int GID;
	static int UID;
		
	if (ChangeOwner == 0) {
		ChangeOwner = SmartGetUID(GID, UID, ErrPath);
	}
	if (!NeedsMode and ChangeOwner < 0) {
		return 0;
	}
	
	int			Err = 0;
	const char* Action = 0;
	bool		IsLink = IsLink_(Path);

	if (NeedsMode) {
		Action = "chmod";
		Err = chmod(Path, kDefaultMode);
		if (IsLink)
			Err = lchmod(Path, kDefaultMode);
	}
	
	if (!Err and ChangeOwner > 0) {
		Err = chown(Path, UID, GID);
		if (IsLink) 
			Err = lchown(Path, UID, GID);
	}
	
	return Err;
}


int JB_File_RelaxPath(JB_File* self, bool NeedsMode) {
	require (self); 
	return RelaxPath_((const char*)self->Addr, NeedsMode, self);
}



int JB_Str_MakeEntirePath(JB_String* self, bool Last);
bool RetryMakePath (JB_String* s) {
	int Err = errno;
	if (Err != ENOENT)
		return false;
	Err = JB_Str_MakeEntirePath(s, false);
	return (!Err);
}


int StrOpen_(JB_File* Path, int Flags, bool AllowMissing) {
	if (!JB_Str_Length(Path)) {
		errno = ENOENT;
	} else {
		NativeFileChar2* CPath = (NativeFileChar2*)JB_FastFileThing( Path );
		
		Flags |= O_Win32Sucks |  O_CLOEXEC; // mostly we dont want this... just for shm
		int FD = open( CPath,  Flags,  kDefaultMode );
		if (FD < 0  and  Flags&O_CREAT  and  RetryMakePath(Path))
			FD = open( CPath,  Flags,  kDefaultMode );

		if (FD >= 0) {
			if (Flags & O_CREAT) {
				RelaxPath_(CPath, false, Path);
			}
			return FD;
		}
		if ((errno == ENOENT) and AllowMissing)
			return -2;// ignore it...
	}
    
	JB_ErrorHandleFile(Path, nil, errno, nil, "opening");
    return -1;
}

static bool Stat2_( JB_String* ErrName,  struct _stat* st,  bool normal,  const char* tmp ) {
    int err = normal ? stat( tmp, st ) : lstat( tmp, st );
    if (!err) return true;
	if (errno != ENOENT  and access(tmp, 0)) {
		errno = ENOENT; // sometimes other errors are really ENOENT
	}					// So we need to refill this.

	if (errno != ENOENT)
		ErrorHandle_(err, ErrName, nil, "getting info on");
	return false;
}


bool Stat_( JB_String* self, struct _stat* st, bool normal=true ) {
    if (!self) return false;
    uint8 Tmp[PATH_MAX];
	auto tmp = (const char*)JB_FastFileString(self, Tmp);
	return Stat2_(self, st, normal, tmp);
}


uint8* JB_FastFileString( JB_String* Path, uint8* Tmp ) { // just use posix funcs? fuck windows 16-bit chars.
    u32 N = JB_Str_Length( Path );
    if ( ! N ) {
        return (uint8*)"";
    }

	uint8* Result = Path->Addr;
    if (JB_Str_IsC(Path))
        return Result;

    if (N > PATH_MAX)
        N = PATH_MAX;
    Tmp[ N ] = 0;
    return (uint8*)CopyBytes( Result, Tmp, N );
}


int File_GoToStart( JB_File* f, bool AllowMissing ) {
	int FD = f->Descriptor;
	if (FD >= 0) {
		int err = JB_File_OffsetSet(f, 0);
		if (err) return err;
		return FD;
	}
	return JB_File_Open( f, O_RDONLY, AllowMissing );
}

//bool DebugFile(JB_File* F, const char* S) {
//	JB_String D = {};
//	D.Addr = (u8*)S;
//	D.Length = (int)strlen(S);
//	bool JB_Str_ContainsString(JB_String* Self, JB_String* S);
//	return JB_Str_ContainsString(F, &D); 
//}

int JB_File_Open( JB_File* f, int OpenFlags, bool AllowMissing ) {
	if (!f)
		return -1;
	bool JB_Str_ContainsString(JB_String* Self, JB_String* S);
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


// does what write() should do.
// well kinda. It could write some of the bytes and STILL get an error. so the interface is just bad.
int JB_Write_(int fd, uint8* buffer, int N) {
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


int ReadIfItWasDoneProperly (int fd, unsigned char* Out, int Request, int64& Total, int AsFile, const char* Path) {	
    do { // read() forces me to deal with 9 cases. :[
		int nread = (int)read(fd, Out, Request);
		if (nread > 0) {
            Total += nread; Out += nread; Request -= nread;
			if (AsFile <= 0)									// 1) Let pipe get partial data. More responsive.
				return 1;										//    (pipes delay stuff?)
			if (Request <= 0)									// 2) We got the full requested amount.
				return 1;										
	        continue;											// 3) keep reading!
		}
		if (nread == 0) return 0;								// 4) Pipe is closed, or file EOF.
		int Error = errno;
		if (Error == EINTR)										// 5) Retry ;_;
			continue;
		if (Error == EWOULDBLOCK  or  Error == EAGAIN) {
			if (AsFile <= 0)
				return 1;										// 6) Tell pipe to retry later
			if (++AsFile < 1024)
				continue;										// 7) Files need a full read.
			 													// 8) File failed too many times, give up.
		}
		return -JB_ErrorHandleFileC(Path, Error, "reading");	// 9) return error
    } while (true);
}


// getting a string makes more sense, cos what about Unicode? And glyphs?
// HOWEVER, whabout someone copy/pasting an entire thing in? then what?
// ideally... we should just get the whole thing
// perhaps into a FastString? THEN we should... split it into glyphs.
// on the other side... that is. not within here. Could just use u8Count_
// to find a codepoint... maybe just ungetc. Do it later.
int JB_App__GetChar() {
	struct termios tio;

	tcgetattr(STDIN_FILENO, &tio);	/* get the terminal settings for stdin */

//  Disable canonical mode (buffered io) and local echo

	tcflag_t PrevFlag = tio.c_lflag; 
	tio.c_lflag &=~ (ICANON|ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &tio);
	int PrevState = fcntl(STDIN_FILENO, F_GETFL); 
	
	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
	int c = getchar();
	fcntl(STDIN_FILENO, F_SETFL, PrevState);	/* restore the former settings */
	tio.c_lflag = PrevFlag;
	tcsetattr(STDIN_FILENO, TCSANOW, &tio);
	
	return c;
}


static bool CrashLogSub(const char* c) {
	if (!CrashLogFile) {
		mkdir("/tmp/logs", kDefaultMode);
		int flags = O_RDWR | O_CREAT | O_TRUNC;
		CrashLogFile = open(JB_CrashLogFileName, flags, kDefaultMode);
		chmod(JB_CrashLogFileName, 777);
		if (CrashLogFile)
			fprintf(stderr, "Log At: %s\n", JB_CrashLogFileName);
	}

	fputs(c, stderr);

	if (!CrashLogFile) return false;
    JB_Write_( CrashLogFile, (u8*)c, (int)strlen(c) );
    return true;
}


void JB_Rec__CrashLog(const char* c) {
	if (c and CrashLogSub(c))
		JB_Write_( CrashLogFile, (u8*)"\n", 1 );
	fputc('\n', stderr);
}



int JB_FS_AppendFile(FastString* self, JB_File* F, uint64 L, bool LeaveOpen) {
	// Pass the exact amount to append, or -1 to append all.
	debugger;
	if (!self or !L or !F)
		return 0;
	int fd = JB_File_Open(F, 0, false);
	if (fd < 0)
		return -1;
	
	int Error = 0;
    while (true) {
		uint Req = (uint)std::min(L, (uint64)(64*1024));
		uint8* Buffer = JB_FS_WriteAlloc_(self, Req);
		int64 N = 0;
		Error = ReadIfItWasDoneProperly(fd, Buffer, Req, N, true, (const char*)F->Addr);
		JB_FS_AdjustLength_(self, 64 * 1024, (int)N);
		if ((int64)L>0)
			L -= N;
		if (Error < 0 or L==0) break;
	}
	if (!Error and (int64)L > 0)
		Error = -JB_ErrorHandleFile(F, nil, EIO, nil, "reading"); // File smaller than expected
	if (!LeaveOpen)
		JB_File_Close(F);
	return Error;
}


JB_String* JB_File_ReadAll ( JB_File* self, int lim, bool AllowMissing ) {
	JB_String* Result = JB_Str__Error();
	if (self) {
		bool WasOpen = self->Descriptor > STDPICO_FILENO;
		int FD = File_GoToStart(self, AllowMissing);
		if (FD == -2) { // ignore it
			Result = JB_Str__Empty();
		
		} else if (FD >= 0) {
			s64 S = JB_File_Size(self); 
			if (S <= (s64)lim) {
				Result = JB_File_Read( self, (int)S, AllowMissing );
				if (!WasOpen)
					JB_File_Close(self);
			} else {
				JB_ErrorHandleFile(self, nil, EFBIG, nil, "reading");
			}
		}
	}
//	JB_Flow__Report(Result, self); JB_File_Read already does this
	return Result;
}


static int CaseComparisonsAllowed = 1024*2;
int* JB_File__Compar() {
	return &CaseComparisonsAllowed;
}

inline bool WorthTestingCase() {
#if __PLATFORM_CURR__ == __PLATFORM_LINUX__
	return true;
#else
	if (CaseComparisonsAllowed > 0) {
		CaseComparisonsAllowed--;
		return true;
	}
	return false;
#endif
}

static void CaseFail_(JB_String* Orig, const char* Actual, bool Owned) {
	CaseComparisonsAllowed -= 64;
	JB_String* Ugh = Owned ? JB_Str__Freeable0(Actual) : JB_Str_CopyFromCString(Actual);
	JB_ErrorHandleFile(Orig, Ugh, -1, "case-differs", "finding path", 3, "found");
}

static void TrimSlash (MiniStr& A) {
	while (A.Length and A.Last()=='/') {
		A.Length--;
	}
}

static int CaseCompare_(JB_String* self, const char* Resolved, bool Owned) {
	auto A = Mini(self);
	auto B = Mini2(Resolved);
	TrimSlash(A);
	if (StrEquals( A, B )) {
		//if (Owned and B.Length != self->Length) debugger;
		return B.Length == self->Length;
	}

#if __PLATFORM_CURR__ == __PLATFORM_LINUX__
	return 0; // no need on linux.
#else
	if (!StrEqualsLex( A, B )) // Phew
		return 0;
	CaseFail_(self, Resolved, Owned); // BAD! The two paths only differ by case.
	return 2;
#endif
}



static void CaseTest_(JB_String* self) {
	require0 (JB_Str_Length(self));
	char Resolved[PATH_MAX];
	const char* s = (const char*)(self->Addr);
//	LogPut(s);
	if (realpath(s, Resolved))
		CaseCompare_(self, Resolved, false);
}


JB_String* JB_Str_ResolvePath( JB_String* self, bool AllowMissing ) {
	// realpath seems to add "/" to paths?
	// should we add them too? can we compare ignoring final "/"?
	JB_String* UserPath = JB_File_PathFix(self);
	if (!JB_Str_Length(UserPath))
		return UserPath;
		
	JB_String* Result = JB_Str__Error();
	char* Resolved = realpath((const char*)(UserPath->Addr), 0);
	if (Resolved) {
		int Cmp = CaseCompare_(self, Resolved, true); // do this later
		if (Cmp == 1) {
			free(Resolved);
			Result = self;
		} else {
			Result = JB_Str__Freeable0( Resolved );
		}
	} else if (!(errno == ENOENT and AllowMissing)) {
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
	int _NSGetExecutablePath (char* buf, u32* length); // oh apple...
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


int JB_App__SetEnv (JB_StringC* name, JB_StringC* value) {
	if (name) {
		if (value)
			return setenv((const char*)(name->Addr), (const char*)(value->Addr), 1);
		return unsetenv((const char*)(name->Addr));
	}
	return -999;
}


JB_String* JB_File_Read ( JB_File* self, int Length, bool AllowMissing ) {
	if (Length <= 0)
		return JB_Str__Empty();
    int FD = JB_File_Open( self, O_RDONLY, AllowMissing );
    JB_String* Result = JB_Str__Error();
    if (FD >= 0) {
		Result = JB_Str_New( Length );
		if (Result) {
			int64 Total = 0;
			int Read = ReadIfItWasDoneProperly( FD, Result->Addr, Length, Total, true, (const char*)(self->Addr) );
			if (Read < 0) {
				JB_FreeIfDead(Result);
				Result = JB_Str__Error();
			} else {
				Result = Str_Shrink( Result, (int)Total );
			}
		} else {
			JB_ErrorHandleFile(self, nil, ENOMEM, nil, "reading");
		}
	}
	JB_Flow__Report(Result, self);
	return Result;
}


bool JB_File_EOF ( JB_File* self ) {
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


int64 JB_File_WriteRaw_ ( JB_File* self, uint8* Data, int N ) {
    N = JB_Write_( self->Descriptor, Data, N );
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


void JB_File_Flush(JB_File* self) {
    if ( HasFD(self) ) {
		int err = 0;
//		err = fflush(self->Descriptor);
//		if (!err)
			err = fsync( self->Descriptor );
		ErrorHandle_( err, self, nil, "flushing" );
	}
}


bool JB_File_OpenBlank( JB_File* self ) {
	return JB_File_Open( self, O_RDWR | O_CREAT | O_TRUNC, false ) >= 0;
}

int JB_Str_MakeDir(JB_String* self) {
    uint8 Buffer[PATH_MAX];
    NativeFileChar2* tmp = (NativeFileChar2*)JB_FastFileString( self, Buffer );
	struct _stat st;
	int err = stat( tmp, &st );
	if (!err and S_ISDIR(st.st_mode)) {
		return 0;
	}
    err = mkdir(tmp, kDefaultMode);
    if (err == -1 and errno == ENOENT and RetryMakePath(self)) {
		err = mkdir(tmp, kDefaultMode);
	}
    if (!err)
		return RelaxPath_(tmp, true, self);
    return (int)ErrorHandle_(err, self, nil, "creating a folder");
}


int JB_File_Delete (JB_String* self) {
	uint8 Tmp[PATH_MAX];
    NativeFileChar2* tmp = (NativeFileChar2*)JB_FastFileString( self, Tmp );
    int err = remove( tmp );
    if (err == -1 and errno == ENOENT) {
        return 0;
    }
    return (int)ErrorHandle_(err, self, nil, "deleting");  // handle error
}


JB_String* JB_File_Path(JB_File* P) {
	if (P) 
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

JB_StringC* JB_File_PathFix(JB_String* P) {
// creates c-strings.
	int N = JB_Str_Length(P);
	if (!N) return (JB_StringC*)P;
	if (N >= PATH_MAX) {
		JB_ErrorHandleFile(JB_Str_Preview(P, 150), nil, ENAMETOOLONG, nil, "fixing-path");
		return (JB_StringC*)JB_Str__Error(); // hmmm
	}
	byte* s = P->Addr;
	if (s[0] == '/')
		return JB_Str_MakeC(P);
	
	FastString* fs = JB_FS__FastNew(0);
    if (s[0] == '~') {
		auto H = JB_File__Home();
		JB_FS_AppendString(fs, H);
		JB_FS_AppendRange(fs, P, 1, kMaxint);
	} else {
		const char* Created = getcwd( 0, 0 );
		JB_FS_AppendCString(fs, Created);
		if (JB_FS_Last(fs, 0) != '/')
			JB_FS_AppendByte(fs, '/');
		if (s[0] == '.' and P->Length >= 2  and  s[1] == '/') {
			JB_FS_AppendRange(fs, P, 2, kMaxint);
		} else {
			JB_FS_AppendString(fs, P);
		}
		free((void*)Created);
	}
	return (JB_StringC*)JB_FS_GetResult(fs);
}


JB_File* JB_File_Constructor( JB_File* self, JB_String* Path ) {
	JB_New2(JB_File);
	if (!JB_Str_Length(Path)) {
		auto Err = JB_Str__Error();
		if (Path == Err) {
			; // allow. They intended this file, as a place-holder, to stop nil-errors. 
		} else {
			Path = Err;
			static byte EmptyFilePaths = 0;
			if (EmptyFilePaths < 10) {
				EmptyFilePaths++; // don't spam them if their code is horribly flawed.
				JB_ErrorHandleFile(Path, nil, ENOENT, nil, "constructing", 3); // means a problem but not necessarily an error
			}
		}
	}
	
	Path = JB_File_PathFix(Path);
	self->Addr = Path->Addr;
	self->Length = Path->Length;
	self->Parent = JB_Incr(Path);
	
    self->Descriptor = -1;
    self->MyFlags = 0;
    self->OpenMode = 0;
        
	if (WorthTestingCase())
		CaseTest_(self);
	return self;
}


JB_String* JB_File_Render(JB_File* self, FastString* fs_in) {
    if (fs_in) {
        JB_FS_AppendString(fs_in, self);
        return 0;
	}
	return self;
}

void JB_File_ListStart (JB_File* File, JB_DirReader* Reader) {
    Reader->File = JB_Incr(File);
    Reader->Item = 0;									// in case already set?
    auto P = (const char*)JB_FastFileThing(File); 
    Reader->Dir = opendir( P );
}

void JB_File_ListEnd (JB_DirReader* self) {
    self->Item = 0;
	auto c = self->Dir;
    if (c) {
		self->Dir = 0;
        closedir((DIR*)c);
    }

    auto f = self->File;
    self->File = 0;
    JB_Decr(f);
}

void JB_File_Destructor (JB_File* self) {
    JB_File_Close(self);
	JB_Str_Destructor(self);
}


void JB_File_StopSHM (JB_File* self) {
	#ifndef AS_LIBRARY
	if (self->MyFlags & 1) { // 1 == server!
		printf("unlinking %s\n", self->Addr);
		shm_unlink((const char*)(self->Addr));
		self->MyFlags &= ~1;
	}
	#endif
}

void JB_File_CloseSub ( JB_File* self ) {
	int R = self->Descriptor;
	self->Descriptor  = -1;
	self->OpenMode = 0;
    if (R >= 0)
		ErrorHandle_(close( R ), self, nil, "closing");
}

void JB_File_Close ( JB_File* self ) {
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
	int Err = chmod(C, Mode);
	return (int)ErrorHandle_(Err, self, nil, "setting permissions");
}


int JB_Str_SymLink( JB_StringC* Existing, JB_String* ToCreate ) {
	int Err = 0;
	struct _stat st;
	if (Stat_(ToCreate, &st, false)) {
		Err = JB_File_Delete(ToCreate);
		if (Err)
			errno = EEXIST; // clearer error message.
	}
	if (!Err) {
		uint8 Tmp[PATH_MAX];
		auto Created = (const char*)JB_FastFileString(ToCreate, Tmp);
		Err	= symlink((const char*)(Existing->Addr), Created);
		
		if (Err and errno == ENOENT) {
			Err = 1; // creates clearer error messages.
			if (RetryMakePath(ToCreate))
				Err = symlink((const char*)(Existing->Addr), Created);
		}
		if (!Err)
			RelaxPath_(Created, true, ToCreate); // needed on MacOSX but not linux!
	}
	return (int)ErrorHandle_(Err, ToCreate, Existing, "linking");
}


bool JB_File_HardLinkTo( JB_File* self, JB_StringC* Link ) {
	auto C	= ((const char*)JB_FastFileThing(self));
    int Err	= link(C, (const char*)(Link->Addr));
    if (Err and RetryMakePath(Link))
		Err = link(C, (const char*)(Link->Addr));
	ErrorHandle_(Err, self, Link, "hardlinking");
	return !Err;
}


JB_String* JB_File_LinkToGet( JB_File* self ) {
	// symlink
	auto C = (const char*)JB_FastFileThing(self);
	char Found[PATH_MAX];
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
	int fd = JB_File_Open( self, O_RDWR, false );
	if (fd < 0)
		return fd;
	int err = ftruncate(self->Descriptor, N);
	return (int)ErrorHandle_( err,  self,  nil,  "set size of" );
}


s64 JB_File_Size( JB_File* self ) {
	struct _stat st;
	return Stat_(self, &st) * (u64)st.st_size;
}


Date JB_File_Accessed( JB_File* self ) {
    struct _stat st = {};
    require (Stat_(self, &st))
	#if __linux__
		return JB_Date__Create(st.st_atime, 0);
	#else
		return JB_Date__Create(st.st_atimespec.tv_sec, st.st_atimespec.tv_nsec);
	#endif
}


Date JB_File_Modified( JB_File* self ) {
    struct _stat st = {};
    require (Stat_(self, &st))
	#if __linux__
		return JB_Date__Create(st.st_mtime, 0);//st.st_mtime_nsec);
	#else
		return JB_Date__Create(st.st_mtimespec.tv_sec, st.st_mtimespec.tv_nsec);
	#endif
}


void JB_File_ModifiedSet( JB_File* self, Date when ) {
	auto path = (const char*)(self->Addr);
	struct timeval times[2] = {};
	times[0].tv_sec = when>>16;
	times[1].tv_sec = when>>16;
	int err = utimes(path, times);
	ErrorHandle_( err,  self,  nil,  "set modified date of" );
}



Date JB_File_Created( JB_File* self ) {
    struct _stat st = {};
    require (Stat_(self, &st))
	#if __linux__
		return JB_Date__Create(st.st_ctime, 0);
	#else
		return JB_Date__Create(st.st_ctimespec.tv_sec, st.st_ctimespec.tv_nsec);
	#endif
}


bool JB_File_Exists( JB_String* self ) {
    uint8 Tmp[PATH_MAX];
	auto tmp = (const char*)JB_FastFileString(self, Tmp);
	int err = access(tmp, 0);
	if (!err)
		return true;
	if (errno == ENOENT) {
		if (!JB_File_IsLink(self))
			return false;
		errno = EMLINK; // no broken link errno!
		JB_ErrorHandleFile(self, nil, EMLINK, "broken link", "testing the existance of");
	} else {
		ErrorHandle_(err, self, nil, "testing the existance of");
	}
	return false;
}


static uint8* TempBeforeMove(MiniStr& Self, uint8* Buff) {
	int N = Self.Length + 8;
	if (N > PATH_MAX)
		return Self.Addr;
	
	memmove(Buff, Self.Addr, Self.Length);
	memmove(Buff + Self.Length, ".tmpmov", 8);
	int Err = rename((const char*)Self.Addr, (const char*)Buff);
	if (Err)
		return Self.Addr;
	errno = ENOENT;
	return Buff;
}


static uint8* MoveWithinSelf(JB_File* Self, JB_String* New, uint8* Buff) {
	auto N = Mini(New);
	auto S = Mini(Self);
	if (N.Length > S.Length and N[S.Length] == '/') {
		N.Length = S.Length;
		if (StrEquals( N, S ))
			return TempBeforeMove(S, Buff);
	}
	return Self->Addr;
}


int JB_File_MoveTo(JB_File* Self, JB_String* New) {
    uint8 Buffer2[PATH_MAX];
    uint8* SelfPath = Self->Addr;
    uint8* NewPath  = JB_FastFileString(New,        Buffer2);
    int Err			= rename((const char*)SelfPath, (const char*)NewPath);
    if (Err) {
		uint8 Buffer3[PATH_MAX];
		uint8* S2 = MoveWithinSelf(Self, New, Buffer3);
		if (RetryMakePath(New))
			Err = rename((const char*)S2, (const char*)NewPath);
		if (Err and S2 != SelfPath)
			Err = rename((const char*)S2, (const char*)SelfPath);
		ErrorHandle_(Err, Self, New, "moving");
	}
    // do not change the path
    return Err;
}


// copy file properly!! keeps attrs!! :)
int CopyStats_(JB_File* self, JB_File* To) {
	struct stat st;
	if (Stat_(self, &st))
		return JB_File_ModeSet(To, st.st_mode);
	return 0;
}


int JB_File_Copy(JB_File* self, JB_File* To, bool AttrOnly) {
	if (!self or !To)
		return -1;
	if (AttrOnly)
		return CopyStats_(self, To);
	bool WasOpen = self->Descriptor > STDPICO_FILENO;
	int Output = JB_File_OpenBlank(To);
	if (Output < 0)
		return -1;

	int Read = 1;
	int Input = File_GoToStart( self, false );
	if (Input > 0) {
		const int ChunkSize = 64*1024;
		u8 Block[ChunkSize];
		while (Read > 0) {
			int64 Total = 0;
			Read = ReadIfItWasDoneProperly(Input, Block, ChunkSize, Total, true, (const char*)self->Addr);
			if (JB_File_WriteRaw_(To, Block, (int)Total) <= 0)
				break;
		}
	}

	JB_File_Close(To);
	if (!WasOpen)
		JB_File_Close(self);
	CopyStats_(self, To);
	if (Read == 1) Read = 0;
	return Read;
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
	bool WasOpen = self->Descriptor > STDPICO_FILENO;
	if (JB_File_Open(self, O_RDWR | O_CREAT | O_TRUNC, false) < 0)
		return false;
	JB_File_SizeSet(self, 0);
	JB_File_OffsetSet(self, 0); // necessary as ftruncate doesnt do this.
	int N = JB_File_Write(self, Data);
	if (!WasOpen)
		JB_File_Close(self);
	return (N == JB_Str_Length(Data));
}


JB_File* JB_File__NewPipe(int Pipe) {
	if (Pipe < 0)
		return nil;
	JB_File* F = JB_File_Constructor( 0, 0 );
	F->Descriptor = Pipe;
	F->MyFlags |= 2;
	return F;
}


bool JB_File_IsPipe(JB_File* f) {
	return f->MyFlags & 2;
}

JB_File* JB_Str_File( JB_String* Path ) {
	return JB_File_Constructor( 0, Path );
}


int JB_File__chdir( JB_String* Path ) {
    uint8 Buffer1[PATH_MAX];
	int err = trchdir( (NativeFileChar2*)JB_FastFileString( Path, Buffer1 ) );
	return (int)ErrorHandle_(err, Path, nil, "calling chdir"); 
}



bool JB_File_MoveNext(JB_DirReader* self) {
    DirReader* D = (DirReader*) (&self->Dir);
    self->Item = (int*)ReadDir_(D);
    return self->Item;
}


static bool ChildIsDir (JB_File* self, int MakeDirsObvious, dirent* Child, int ChLength) {
	int T = Child->d_type;
	if (T == DT_DIR)
		return true;
	
	if (T != DT_LNK  and  T != DT_UNKNOWN)
		return false;
	
	// Handle Unknown
    int N = self->Length;
    if (N + ChLength >= PATH_MAX-2)
		return false; // sigh
	
    uint8 Tmp[PATH_MAX];
    struct stat st = {};
    CopyBytes( self->Addr, Tmp, N );
    if (N > 0 and Tmp[N-1] != '/')
		Tmp[N++] = '/';
    CopyBytes( Child->d_name, Tmp+N, ChLength );
    Tmp[N+ChLength] = 0;
	
	if (Stat2_(self, &st, MakeDirsObvious==1, (const char*)(Tmp)))
		return S_ISDIR(st.st_mode);
	return false;
}


JB_String* JB_File_CurrChild (JB_DirReader* self, int MakeDirsObvious) {
    dirent* Child = (dirent*)(self->Item);
    if (!Child)
        return JB_Str__Empty();
    
    u32 NameLength = 0;
#if __PLATFORM_CURR__ == __PLATFORM_OSX__
    NameLength = Child->d_namlen;
#endif
    if ( ! NameLength ) NameLength = (int)strlen( Child->d_name );

	int IsDir = (MakeDirsObvious!=0) and ChildIsDir(self->File, MakeDirsObvious, Child, NameLength);
	// what about if its not? we need the full-file-path, then. So we need to concat two strings.
    JB_String* e = JB_Str_New( (int)NameLength + IsDir );
    if (e) {
        CopyBytes((uint8*)(Child->d_name), e->Addr, (int)NameLength);
        if (IsDir)
			e->Addr[NameLength] = '/';
    }
    return e;
}


bool JB_File_IsDir (JB_File* self) {
    struct stat st = {};
    return Stat_(self, &st) and S_ISDIR(st.st_mode);
}


bool JB_File_IsLink (JB_String* self) {
	struct stat st = {};
	return Stat_(self, &st, false) and S_ISLNK(st.st_mode);
}


void JB_munmap (void* mem, int64 n) {
	if (mem)
		ErrorHandle_(munmap(mem, n), nil, nil, "un-memmap");
}

/*
just some wierd thing I found out about unix... the dir_type and stat modes don't match up.

Sigh.

		#define DT_UNKNOWN       0
		#define DT_FIFO          1
		#define DT_CHR           2
		#define DT_DIR           4
		#define DT_BLK           6
		#define DT_REG           8
		#define DT_LNK          10
		#define DT_SOCK         12
		#define DT_WHT          14
		//  why can't unix just use the same dam numbers.
		#define S_IFMT          0170000         // [XSI] type of file mask
		#define S_IFIFO         0010000         // [XSI] named pipe (fifo)
		#define S_IFCHR         0020000         // [XSI] character special
		#define S_IFDIR         0040000         // [XSI] directory
		#define S_IFBLK         0060000         // [XSI] block special
		#define S_IFREG         0100000         // [XSI] regular
		#define S_IFLNK         0120000         // [XSI] symbolic link
		#define S_IFSOCK        0140000         // [XSI] socket
*/

}

