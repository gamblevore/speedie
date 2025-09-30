
/*
	Copyright (C) 2005 Theodore H. Smith.
*/



#ifndef __Dictionary__
#define __Dictionary__

#include "JB_Umbrella.h"
#include "JB_DictCore.h"


extern "C" {



JB_Object* JB_Dict_FindRaw(Dictionary* self, uint8* key, int Length);
void JB_Dict_AddRaw(Dictionary* self, uint8* key, int Length, JB_Object* Object);
void JB_Dict_IntValueObjSet(Dictionary* self, s64 Key, JB_Object* Value);
JB_Object* JB_Dict_IntValueObj(Dictionary* self, s64 Key);
JB_Object** JB_Dict_MakePlace(Dictionary* self, JB_String* key);
JB_Object** JB_Dict_GetPlace(Dictionary* self, JB_String* key);
void JB_Dict_ValueSet(Dictionary* self, JB_String* key, JB_Object* val);
JB_Object* JB_Dict_Value(Dictionary* self, JB_String* key, JB_Object* Default) ;
JB_Object* JB_Dict_ValueC(Dictionary* self, const char* Addr);
bool JB_Dict_Contains(Dictionary* self, JB_String* key);
JB_Object* JB_Dict_LowerValue(Dictionary* self, JB_String* key);
s64 JB_Dict_IntValue(Dictionary* self, JB_String* key, s64 Missing);
void JB_Dict_IntValueSet(Dictionary* self, JB_String* key, s64 Value);
s64 JB_Dict_IntValueInt(Dictionary* self, s64 Key, s64 Missing);
void JB_Dict_IntValueIntSet(Dictionary* self, s64 Key, s64 Value);
JB_Object* JB_Dict_Longest( Dictionary* self, JB_String* Key, int* Found );
JB_Object* JB_Dict_FindStr( Dictionary* Dict, JB_String* self, ivec2* Found );
bool JB_Dict_HasKey( Dictionary* self, JB_String* key );
void JB_Dict_HasKeySet(Dictionary* self, JB_String* key, bool UseKey, bool Has);

bool JB_Dict_HasKeyObject( Dictionary* self, JB_Object* key );
void JB_Dict_HasKeyJB_Set( Dictionary* self, JB_Object* key, bool b);

void JB_Dict_Dispose(Dictionary* self);
JB_String* JB_Dict_Render(Dictionary* self, FastString* fs);
void JB_Dict_Destructor(Dictionary* self);
void JB_Leaf_Destructor(DictionaryLeaf* self);
Dictionary* JB_Dict_Constructor(Dictionary* self);
int JB_Dict_Count(Dictionary* self);
int JB_Dict_RAMUsed(Dictionary* self);
int JB_Dict_Search(
	Dictionary* self,
	JB_String* Data,
	JB_Object* Ignore,
	int Start,
	int Length
);

int JB_Dict_SearchObj(
	Dictionary* self,
	JB_String* Data,
	JB_Object* Ignore,
	int Start,
	int Length,
	int* FoundLen,
	JB_Object** Result
);

JB_Object* JB_Dict_Key( Dictionary* self, JB_String* Data, int Start, int* Len );
JB_Object* JB_Dict_Key0( Dictionary* self, JB_String* Data, int Start );
DictionaryReader* JB_Dict_Navigate( Dictionary* Dict );


JB_String* JB_Obj_DictName (JB_Object* obj);
JB_String* JB_int_DictName (int obj);
JB_String* JB_int64_DictName (s64 obj);

    
    

// NAVIGATOR!!

JB_String* JB_Nav_Name(DictionaryReader* self);
JB_Object* JB_Nav_Value(DictionaryReader* self);
void JB_Nav_ValueSet(DictionaryReader* self, JB_Object* V);
bool JB_Nav_HasInt(DictionaryReader* self, s64* Where);
bool JB_Nav_MoveNext(DictionaryReader* self);
JB_Object* JB_Nav_NextValue(DictionaryReader* self);
void JB_Nav_Destructor( DictionaryReader* self );
bool JB_Nav_Equals( DictionaryReader* self, DictionaryReader* other );
DictionaryReader* JB_Nav_Constructor( DictionaryReader* self, Dictionary* Dict );


} // ExternCEnd


#endif //__Dictionary__

