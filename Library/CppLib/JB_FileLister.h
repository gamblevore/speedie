

#ifndef __JB_FILE__
#define __JB_FILE__

#include "JB_Umbrella.h"

extern "C" {

JBClass( FileLister, JB_Object,
	DIR*			Dir;
);

void JB_FileLister_Constructor(JB_FileLister* self, JB_String* Path);
void JB_FileLister_Destructor( JB_FileLister* self );


}

#endif

