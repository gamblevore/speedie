
/*
	Copyright (C) 2005 Theodore H. Smith.
*/


#ifndef __RINGTREE__
#define __RINGTREE__

#include "JB_String.h"


extern "C" {

JBClass( RingTree, Saveable,
	int		  Position;
	RingTree* Parent;
	RingTree* Prev;
	RingTree* Next;
	RingTree* Child;
);




#define ksRing		"RingTree"

RingTree* JB_Ring_FlatPrev0( RingTree* self );
RingTree* JB_Ring_FlatPrev( RingTree* self, bool Down );
RingTree* JB_Ring_FlatNextDepth( RingTree* self, int* Depth, bool Down );
RingTree* JB_Ring_FlatNext0( RingTree* self );
RingTree* JB_Ring_FlatAfter( RingTree* self );
RingTree* JB_Ring_NextSib( RingTree* self );
RingTree* JB_Ring_PrevSib( RingTree* self );
RingTree* JB_Ring_Parent( RingTree* self );
RingTree* JB_Ring_First( RingTree* self );
RingTree* JB_Ring_Last( RingTree* self );
RingTree* JB_RT_SyntaxAccess( RingTree* self, int N );
void JB_Ring_TotalSanity(RingTree* Root);

RingTree* JB_Ring_Root( RingTree* self );
bool JB_Ring_IsRoot( RingTree* self );
bool JB_Ring_HasChildCount( RingTree* self, int HasCount );
int JB_Ring_Count( RingTree* self );
bool JB_Ring_HasChildren( RingTree* self );
void JB_Ring_Destructor( RingTree* self );
void JB_Ring_Dispose( RingTree* self );
void JB_Ring_Constructor0( RingTree* self );
void JB_Ring_Constructor( RingTree* self, RingTree* Parent );

void JB_Ring_ParentSet( RingTree* self, RingTree* NewParent );
void JB_Ring_NextSibSet( RingTree* self, RingTree* NewParent );
bool JB_Ring_PrevSibSet( RingTree* self, RingTree* NewParent );
bool JB_Ring_LastSet( RingTree* self, RingTree* NewParent );
bool JB_Ring_FirstSet( RingTree* self, RingTree* New );
RingTree* JB_Ring_MakeFirst( RingTree* self );

bool JB_Ring_Sanity( RingTree* ring );



} // extern "C"

#endif //__RINGTREE__
