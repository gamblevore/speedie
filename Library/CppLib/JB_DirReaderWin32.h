
#ifdef TARGET_WIN32

#include "ObjectPlatform.h"
#include <io.h> /* _findfirst and _findnext set errno if they return -1 */

extern "C" {


struct DirReader {
    _wfinddata_t		DirEnt;
    long				Handle;
    bool				IgnoreFirst;
};

inline bool CloseDir_( DirReader* dir ) {
	return _findclose( dir->Handle );
}


inline bool InitOpenDir_( DirReader* dir ) {
	wchar_t* Path = L"./*";
	dir->Handle = _wfindfirst( Path, &dir->DirEnt ); // should be using shorts!
	dir->IgnoreFirst = true;
	return (dir->Handle != -1);
}


bool ReadDir_( DirReader* D, NativeFileChar** ChildName, u32* NameLength, bool* IsDir );

}


#endif
