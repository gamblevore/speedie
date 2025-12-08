
/*
	Copyright (C) 2013 Theodore H. Smith.
*/

#ifndef __JB_Array__
#define __JB_Array__

#include <vector>

extern "C" {

JBClass( Array, JB_Object,
	int					Marker;
	JB_Object**			_Ptr;
	int					Capacity;
	int					Length;
);
typedef int (*ArraySorterComparerInt)(JB_Object* a, JB_Object* b);

void JB_Array_Sort( Array* self, ArraySorterComparerInt fp );
void JB_Array_Remove( Array* self, int Pos );
void JB_Array_Reverse( Array* self );
JB_String* JB_Array_Render(Array* self, FastString* fs);
void JB_Array_Shuffle( Array* self );
void JB_Array_Shrink (Array* self);
void JB_Array_SizeSet( Array* self, int NewSize );
void JB_Array_Append( Array* self, JB_Object* Value );
void JB_Array_AppendCount( Array* self, JB_Object* Value, int Count );
int JB_Array_Find (Array* Self, JB_Object* F);
void JB_Array_Destructor( Array* self );
int JB_Array_Size( Array* self );
Array* JB_Array_Copy(Array* self);
void JB_Array_Swap(Array* self, uint i, uint j);

void JB_Array_ValueSet( Array* self, int Pos, JB_Object* Value );
JB_Object* JB_Array_Value( Array* self, int Pos );
JB_Object* JB_Array_Pop(Array* self);
int JB_Array_Find( Array* self, JB_Object* Obj );
void JB_FillInts(int* Start, int N, int Value);
Array* JB_Array_Constructor0( Array* self );
//inline Array* JB_Array_Constructor( Array* self, int n ) {JB_Array_Constructor0(self); if (n) debugger;}
int JB_Array_Wipe(Array* self);
    
} // ExternCEnd

#endif //__JB_Array__

