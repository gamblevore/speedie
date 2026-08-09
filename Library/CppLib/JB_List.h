
/*
	Copyright (C) 2005 Theodore H. Smith.
*/


#ifndef __JB_List__
#define __JB_List__

#include "JB_String.h"


extern "C" {

JBClass( JB_List, JB_Object,
	int				Position;
	JB_Object*		Obj;
	JB_List*		Parent;
	JB_List*		Prev;
	JB_List*		Next;
	JB_List*		Child;
);


JB_List* JB_Ring_FlatPrev0( JB_List* self );
JB_List* JB_Ring_FlatPrev( JB_List* self, bool Down );
JB_List* JB_Ring_FlatNextDepth( JB_List* self, int* Depth, bool Down );
JB_List* JB_Ring_FlatNext0( JB_List* self );
JB_List* JB_Ring_FlatAfter( JB_List* self );
JB_List* JB_Ring_NextSib( JB_List* self );
JB_List* JB_Ring_PrevSib( JB_List* self );
JB_List* JB_Ring_Parent( JB_List* self );
JB_List* JB_Ring_First( JB_List* self );
JB_List* JB_Ring_Last( JB_List* self );
JB_List* JB_RT_SyntaxAccess( JB_List* self, int N );
void JB_Ring_TotalSanity(JB_List* Root);

JB_List* JB_Ring_Root( JB_List* self );
bool JB_Ring_IsRoot( JB_List* self );
bool JB_Ring_HasChildCount( JB_List* self, int HasCount );
int JB_Ring_Count( JB_List* self );
bool JB_Ring_HasChildren( JB_List* self );
JB_String* JB_List_Render(JB_List* self, FastString* fs_in);
void JB_Ring_Destructor( JB_List* self );
void JB_Ring_Dispose( JB_List* self );
JB_List* JB_Ring_Constructor0( JB_List* self );
JB_List* JB_Ring_Constructor( JB_List* self, JB_List* Parent );

void JB_Ring_ParentSet( JB_List* self, JB_List* NewParent );
void JB_Ring_NextSibSet( JB_List* self, JB_List* NewParent );
bool JB_Ring_PrevSibSet( JB_List* self, JB_List* NewParent );
bool JB_Ring_LastSet( JB_List* self, JB_List* NewParent );
bool JB_Ring_FirstSet( JB_List* self, JB_List* New );
JB_List* JB_Ring_MakeFirst( JB_List* self );

bool JB_Ring_Sanity( JB_List* ring );



} // extern "C"

#endif //__JB_List__
