
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


JB_List* JB_List_FlatPrev0( JB_List* self );
JB_List* JB_List_FlatPrev( JB_List* self, bool Down );
JB_List* JB_List_FlatNextDepth( JB_List* self, int* Depth, bool Down );
JB_List* JB_List_FlatNext0( JB_List* self );
JB_List* JB_List_FlatAfter( JB_List* self );
JB_List* JB_List_NextSib( JB_List* self );
JB_List* JB_List_PrevSib( JB_List* self );
JB_List* JB_List_Parent( JB_List* self );
JB_List* JB_List_First( JB_List* self );
JB_List* JB_List_Last( JB_List* self );
JB_List* JB_RT_SyntaxAccess( JB_List* self, int N );
void JB_List_TotalSanity(JB_List* Root);

JB_List* JB_List_Root( JB_List* self );
bool JB_List_IsRoot( JB_List* self );
bool JB_List_HasChildCount( JB_List* self, int HasCount );
int JB_List_Count( JB_List* self );
bool JB_List_HasChildren( JB_List* self );
JB_String* JB_List_Render(JB_List* self, FastString* fs_in);
void JB_List_Destructor( JB_List* self );
void JB_List_Dispose( JB_List* self );
JB_List* JB_List_Constructor0( JB_List* self );
JB_List* JB_List_Constructor( JB_List* self, JB_List* Parent );

void JB_List_ParentSet( JB_List* self, JB_List* NewParent );
void JB_List_NextSibSet( JB_List* self, JB_List* NewParent );
bool JB_List_PrevSibSet( JB_List* self, JB_List* NewParent );
bool JB_List_LastSet( JB_List* self, JB_List* NewParent );
bool JB_List_FirstSet( JB_List* self, JB_List* New );
void JB_List_Swap (JB_List* S, JB_List* O);

bool JB_List_Sanity( JB_List* ring );



} // extern "C"

#endif //__JB_List__
