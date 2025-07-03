
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



#include "JB_Umbrella.hpp"
#include "JB_DirReaderUnix.h"

extern "C" {

	
inline bool IgnoreDotDot( uint8* c ) {
	if ( c[0] != '.' ) {				// 'abcd' is OK
		return false;
	}

	char c1 = c[ 1 ];					// "." is bad
	if ( c1 == 0 ) {
		return true;
	}

	return (c1 == '.' and c[2] == 0);	// ".." is also bad.
}

dirent* ReadDir_( DirReader* D ) {
	while (*D) {
		dirent* Child = trreaddir( *D );
		if ( ! Child ) return 0;

		if (IgnoreDotDot( (uint8*)(Child->d_name) )) continue;
		return Child;
	};

    return 0;
}
	
}
