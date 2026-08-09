
/*
	Copyright (C) 2005 Theodore H. Smith.
*/

#ifndef __DICT_CORE__
#define __DICT_CORE__


#include "JB_Alloc.h"

extern "C" {


struct Dictionary0;

struct FindResult {
    JB_Object*   Obj;
    JB_Object**  Place;
    MiniStr      Data;
    Dictionary0* Parent;
};


JBClass( Dictionary0, JB_Object,
    Dictionary*	Parent;
    uint8			Letter;
    uint8			Start;
    uint8			UserFlags; // not used by the dict itself.
    uint8			Width;
    uint			Depth; 
    JB_Object*		InPlaceValue;
);

JBClass( Dictionary1,    Dictionary0,
    JB_Object*      Items[30];
);
JBClass( Dictionary2,    Dictionary0,
    JB_Object*      Items[62];
);
JBClass( Dictionary3,    Dictionary0,
    JB_Object*      Items[126];
);
JBClass( Dictionary4,    Dictionary0,
    JB_Object*      Items[190];
);
JBClass( Dictionary,     Dictionary0,
    JB_Object*      Items[256];
);
JBClass( IntWrapper,     JB_Object,
    u64     Value;
);
JBClass( DictionaryLeaf, Dictionary0,
    JB_String*      Key;
    JB_Object*      Value;
);

JBClass( DictionaryReader, JB_Object,
    FindResult      State;
);

#define kDictLengthm1 8
#define kDictLength0 16
#define kDictLength1 30
#define kDictLength2 62
#define kDictLength3 126
#define kDictLength4 190
#define kDictLength5 256



    
// Scanner

JB_Object* JB_Dict_Scan_(Dictionary* self, MiniStr Data, MiniStr* Result);
    struct ObjLength {
        JB_Object* Obj;
        int        Length;
    };
ObjLength JB_Dict_LongestKey_( Dictionary* First, MiniStr Data );


// Setter

JB_Object** Dict_MakePlace_(Dictionary* di, JB_String* Key);


// Utilities


}

#endif //__DICT_CORE__

