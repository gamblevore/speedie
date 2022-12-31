
/*
	Copyright (C) 2017 Theodore H. Smith.
*/


#ifndef __LIST__
#define __LIST__

#include "JB_LibTypes.h"
#include "StringFunctions.h"
#include "StringFunctionsLib.h"

#include "JB_SafeIncludes.h"
#include "JB_String.h"


extern "C" {

#ifndef _SaveableType_
#define _SaveableType_
JBClass( Saveable, JB_Object,	);
#endif	


JBClass( JB_LinkedList, Saveable,
	JB_LinkedList*     _Next;
	JB_LinkedList**    _BackRef;
);


void JB_LinkedList_Constructor(JB_LinkedList* self);
void JB_LinkedList_NextSet(JB_LinkedList* self, JB_LinkedList* B);
JB_LinkedList* JB_LinkedList_Next(JB_LinkedList* self);
JB_LinkedList* JB_LinkedList_PrepareMoveTo_(JB_LinkedList* self, JB_LinkedList** Where, JB_LinkedList* OldNext);
JB_LinkedList* JB_LinkedList_Remove(JB_LinkedList* self);
void JB_LinkedList_Destructor(JB_LinkedList* self);
void JB_LinkedList_ClearAll(JB_LinkedList* self);

void JB_LinkedList_StoreAt(JB_LinkedList* Self, JB_LinkedList** Place);



} // extern "C"

#endif // __LIST__
