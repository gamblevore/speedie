
/*
	Copyright (C) 2005 Theodore H. Smith.
*/


#ifndef __CHARSET__        // InLines and useful
#define __CHARSET__

#include "JB_Alloc.h"

extern "C" {

//JBClass( ByteMap, JB_Object,
//	uint8			Cache[256];
//);
JBClass( CharSet, JB_Object,
	uint8			Cache[256];
);



        // function Declarations

CharSet* JB_CS_Constructor(CharSet* self, JB_String* Source, bool Ranges);
bool JB_CS_HasChar( CharSet* self, int Value );
void JB_CS_HasCharSet( CharSet* self, int Value, bool Set );

//uint8 JB_BM_Access( ByteMap* self, int Value );
//void JB_BM_AccessSet( ByteMap* self, int S, int D );
JB_String* JB_CS_Render(CharSet* self, FastString* Orig);
CharSet* JB_CS_Invert( CharSet* self );
//void JB_BM_Clear( ByteMap* cs, int F );
//ByteMap* JB_BM_Invert( ByteMap* self, int Unfound );
//ByteMap* JB_BM_Constructor(ByteMap* self, JB_String* From, JB_String* To);
//ByteMap* JB_BM_( JB_String* a, JB_String* b );


} // ExternCEnd

#endif //__CHARSET__


