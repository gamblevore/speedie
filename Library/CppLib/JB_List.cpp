
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2017 Theodore H. Smith.
*/




/*
	Another shit class.
	USE RINGTREE!
*/


    

#include "JB_List.h"

extern "C" {

JBClassPlace( JB_LinkedList,     JB_LinkedList_Destructor,     JB_AsClass(Saveable), 0 );


void JB_LinkedList_Constructor(JB_LinkedList* self) {
	self->_BackRef = nil;
	self->_Next = nil;
}


JB_LinkedList* JB_LinkedList_PrepareMoveTo_(JB_LinkedList* self, JB_LinkedList** Where, JB_LinkedList* OldNext) {
    dbgexpect2(self);
	JB_LinkedList** B = self->_BackRef;
	self->_BackRef = Where;
	JB_LinkedList* N = self->_Next;
	self->_Next = OldNext;
	if (OldNext) {
		OldNext->_BackRef = &self->_Next;
	}
	if (N) {
		N->_BackRef = B;
	}
	if (B) {
        *B = N;
    } else {
        JB_DoAt(1); // why incr? We are removing????
		JB_Incr(self);
	}
    return N;
}


JB_LinkedList* JB_LinkedList_Remove(JB_LinkedList* self) {
	require (self and self->_BackRef);
    JB_LinkedList* N = JB_LinkedList_PrepareMoveTo_(self, nil, nil);
    JB_Decr(self);
    return N;
}


void JB_LinkedList_ClearAll(JB_LinkedList* self) {
    require0 (self);
    if (self->_BackRef) {
        *(self->_BackRef) = 0;
    }
    JB_LinkedList* C = self;
    while (C) {
        JB_LinkedList* N = C->_Next;
        C->_Next = 0;
        C->_BackRef = 0;
        if (C->RefCount) {  // Fix to allow call from destructor.
            JB_Decr(C);
        }
        C = N;
    };
}


void JB_LinkedList_Destructor(JB_LinkedList* self) {
    dbgexpect(!self->_BackRef); // Should really never happen
    require0(self->_Next);      // should also never happen. The list owns nodes.
                                // And the list should clear our refs on it's destructor. 
    JB_DoAt(1);
    JB_LinkedList_ClearAll(self);
}



void JB_LinkedList_ListSanity(JB_LinkedList* Self);
// OK so... here's the plan... first we remove.
// then we add... Makes sense?
void JB_LinkedList_StoreAt(JB_LinkedList* self, JB_LinkedList** Place) {
    JB_LinkedList** Back = self->_BackRef;    // remove
    if (Back) {
        JB_LinkedList* Next = self->_Next;
        if (Next) {
            Next->_BackRef = Back;
        }
        *Back = Next;
    } else {
        JB_Incr(self);
    }
    
    JB_LinkedList* OldValue = *Place;         // add
    self->_Next = OldValue;
    if (OldValue)
        OldValue->_BackRef = &self->_Next; 
    *Place = self;
    self->_BackRef = Place; 
}


} // 

