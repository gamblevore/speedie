

#include "JB_Umbrella.h"
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#define TrackDirsOn 0

extern "C" {
#if TrackDirsOn
	extern bool TrackDirs;

	inline void trclosedir( DIR* d ) {
		if (TrackDirs) puts( "closedir" );
		closedir( d );
	}

	inline DIR* tropendir( const char* c ) {
		DIR* Result = opendir(c);
		if (TrackDirs) {
			const char* msg = "OK";
			if (!Result) {
				msg = "FAIL";
			}
			printf("opendir: %s %s\n", c, msg);
		}
		return Result;
	}
	
	inline long trchdir( const char* c ) {
		int Result = chdir(c);
		if (TrackDirs) printf("chdir: %s %i\n", c, Result);
		return Result;
	}

	inline dirent* trreaddir( DIR* D ) {
		dirent* Result = readdir(D);
		if (TrackDirs) {
			const char* s = "";
			if (Result) {
				s = Result->d_name;
			}
			printf("readdir: %s \n", s);
		}
		return Result;
	}
	
	
#else
	#define trclosedir closedir
	#define tropendir opendir
	#define trchdir chdir
	#define trreaddir readdir
#endif


#define DirReader DIR*
inline bool InitOpenDir_( DirReader* D, const char* c ) {
	*D = tropendir( c );
	return *D;
}

inline bool CloseDir_( DirReader* D ) {
	trclosedir( *D );
    return true;
}

    dirent* ReadDir_( DirReader* D );
    
}