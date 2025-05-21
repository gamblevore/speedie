
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


/*
    A tree good for fast insert, append, remove and with no cyclical refcounting.

    No JB_List can be moved into it's own desendant or itself.

    I do things a bit lopsided, but it works out for the best!
    LastChild.next = 0, apart from that it's a plain double-ring.
*/


#include "JB_Umbrella.hpp"


extern "C" {

static void RingLeave_( JB_List* rt );


inline bool RingIsRoot_( JB_List* rt ) {
	if ( !rt->Parent ) {
		dbgexpect2( !rt->Prev );
		dbgexpect2( !rt->Next );
		return true;
	}
	return false;
}

#define Sanity(s)

static void AncestorSanity_(JB_List* Curr) {
    // not parent of myself
    JB_List* Parent = Curr->Parent;
    while (Parent) {
        if (Curr == Parent) {
            debugger;
        }
        Parent = Parent->Parent;
    }
}


static void LoopSanity_(JB_List* self) {
	JB_List* Curr = self->Next;
	while (Curr) {
		if (Curr == self)
			debugger;
		JB_List* N = Curr->Next;
		if (N and N->Prev != Curr)
			debugger;
		Curr = N;
	}
}


static void AmContainedSanity_(JB_List* Curr) {
    // find self in parent
    JB_List* Parent = Curr->Parent;
    if (!Parent) {
        return;
    }

    bool Found = false;
    JB_List* Ch = Parent->Child;
    while (Ch) {
        if (Ch == Curr) {
            Found = true;
        }
        Ch = Ch->Next;
        if (!Ch) {
            break;
        }

        JB_List* Prev = Ch->Prev;
        if (Prev->Next != Ch) {
            debugger;
        }
    }

    if (!Found) {
        debugger; // not found
    }
}

static void Sanity_(JB_List* Curr) {
    if (!Curr) {
        return;
    }

    
    AncestorSanity_( Curr );
    AmContainedSanity_( Curr );
    LoopSanity_(Curr);
}


static JB_List* LastSanity = 0;
void JB_Ring_TotalSanity(JB_List* Root) {
    if (!Root) {
        Root = LastSanity;
        if (!Root) {
            return;
        }
    } else {
        LastSanity = Root;
    }
    
    JB_List* After = JB_Ring_FlatAfter(Root);
    JB_List* Curr = Root;
    while (Curr != After) {
        AmContainedSanity_(Curr);
        Curr = JB_Ring_FlatNext0(Curr);
    }
}



inline void RingOwnForDeref_( JB_List* Curr ) {
    Curr->Next = 0;
    Curr->Parent = 0;
    Curr->Prev = 0;
}


bool JB_Ring_IsAncestor( JB_List* child, JB_List* ance ) {
	JB_List* p = child->Parent;
	while ( p ) {
		if ( p == ance ) {
			return true;
		}

		p = p->Parent;
	}

	return false;   
}

static bool DB_RingIsAncestor_( JB_List* child, JB_List* ance ) {
#if DEBUG || AS_LIBRARY // important!
	return JB_Ring_IsAncestor(child, ance);
#endif

	return false;   
}


inline bool PrepareMove_( JB_List* place, JB_List* mover ) {
    if (!mover)
        return false;
    
	if ( place != mover ) {
        if ( mover->Child and DB_RingIsAncestor_( place, mover ) ) {
            ; // fail
        } else {
            if ( mover->Parent ) {
                RingLeave_( mover );
            } else {
                JB_Incr( mover );
            }
            return true;
        }
    }

	JB_DoAt(1);
    return JB_ErrorHandleC("Error: moved a JB_List node to the wrong place", 0, false);
}


bool JB_Ring_HasChildren( JB_List* self ) {
    return self and self->Child;
}

int JB_Ring_Count( JB_List* self ) {
	JB_List* c = self->Child;
	
    int N = 0;
	while ( c ) {
		c = c->Next;
        N++;
	}
	
	return N;
}

bool JB_Ring_HasChildCount( JB_List* self, int HasCount ) {
	JB_List* c = self->Child;
	
	while ( HasCount-- >= 1 ) {
		if ( !c ) {
			return false;
		}
		c = c->Next;
	}
	
	return ( !c );
}

JB_List* JB_Ring_Last( JB_List* self ) {
	if (self) {
		JB_List* c = self->Child;
		if ( c ) {
			return c->Prev;
		}
	}
	return 0;
}

JB_List* JB_Ring_NextSib( JB_List* self ) {
	if (self) {
		return self->Next;
	}
	return 0;
}

JB_List* JB_Ring_PrevSib( JB_List* self ) {
	if (self) {
		JB_List* Prev = self->Prev;
		if (Prev and Prev->Next) { // the last one has no next!
			return Prev;
		}
	}
		
	return 0;
}

JB_List* JB_Ring_First( JB_List* self ) {
	if (self)
		return self->Child;
	return 0;
}

JB_List* JB_Ring_Parent( JB_List* self ) {
	if (self)
		return self->Parent;
	return 0;
}

JB_List* JB_Ring_Root( JB_List* self ) {
	JB_List* rz = self;
	while ( self ) {
		rz = self;
		self = self->Parent;
	}
	return rz;
}


bool JB_Ring_IsRoot( JB_List* self ) {
	if (self) {
		return ( !self->Parent );
	}
	return 0;
}


static void RingLeave_( JB_List* rt ) {
    Sanity(rt);
	dbgexpect( rt );
	dbgexpect( !RingIsRoot_( rt ) ); // 
	JB_List* n = rt->Next;
	JB_List* p = rt->Prev;
	JB_List* Parent = rt->Parent;
    rt->Parent = 0;
	dbgexpect( p );
	dbgexpect( Parent );

	if (p == rt) { // we are the only ones in our parent!
		Parent->Child = 0;
	} else if (!n) { // we are removing the last.
        p->Next = 0;
		Parent->Child->Prev = p;
	} else {
		n->Prev = p;
		if (Parent->Child == rt) {
			Parent->Child = n;
		} else {
			p->Next = n;
		}
 	}
}


inline void InsertBefore_( JB_List* pl, JB_List* rt ) {
	dbgexpect( rt );
	dbgexpect( pl );
	JB_List* Parent = pl->Parent;
	dbgexpect( Parent );

	JB_List* Prev = pl->Prev;
	if ( Parent->Child == pl ) {
		Parent->Child = rt; // put ourselves first!
	} else {
		Prev->Next = rt;
	}
	pl->Prev = rt;
	rt->Prev = Prev;
	rt->Next = pl;
	rt->Parent = Parent;
}


inline void InsertAfter_( JB_List* pl, JB_List* rt ) {
	dbgexpect( rt );
	dbgexpect( pl );
	JB_List* Parent = pl->Parent;
	dbgexpect( Parent );

	JB_List* Next = pl->Next;

	rt->Next = Next;
	rt->Prev = pl;
	pl->Next = rt;
	if (Next) {
		Next->Prev = rt;
	} else {
		Parent->Child->Prev = rt;
	}

	rt->Parent = Parent;
}


struct DepthNode { JB_List* Node; int Depth; };

DepthNode FlatNext( JB_List* self, bool AllowDown ) {
	Sanity( self );
	
	JB_List* c = self->Child;
	JB_List* up = self->Parent;
	int Depth = 0;

	if (AllowDown and c) {
		if (up != self) { // owner!
			Depth++;
		}
		return {c, Depth};
	}

	while (up != self  and  up) {
		JB_List* n = self->Next;

		if ( n ) {
			return {n, Depth};
		}

		// we want to go up!
		Depth--;
		self = up;
		up = self->Parent;
	}

	return {0, Depth};
}

// very cool
JB_List* JB_Ring_FlatNext0( JB_List* self ) {
	if (self)
		return FlatNext( self, true ).Node;
	return 0;
}


JB_List* JB_Ring_FlatNextDepth( JB_List* self, int* Depth, bool Down ) {
	auto D = FlatNext( self, Down );
	if (Depth)
		*Depth += D.Depth;
	return D.Node;
}


JB_List* JB_Ring_FlatAfter( JB_List* self ) {
	if (self)
		return FlatNext( self, false ).Node;
	return 0;
}


void JB_Ring_ParentSet( JB_List* self, JB_List* NewParent ) {
	if (NewParent) {
		JB_Ring_LastSet( NewParent, self );
	} else if (self and self->Parent) {
		RingLeave_( self );
		RingOwnForDeref_( self );
		JB_Decr(self);
	}
}


void JB_Ring_NextSibSet( JB_List* self, JB_List* Mover ) {
	if ( self->Parent and PrepareMove_( self, Mover ) ) {
		InsertAfter_( self, Mover );
	}
}


bool JB_Ring_PrevSibSet( JB_List* self, JB_List* Mover ) {
	if ( self->Parent and PrepareMove_( self, Mover ) ) {
		InsertBefore_( self, Mover );
		return true;
	}
	return false;
}


bool JB_Ring_LastSet( JB_List* self, JB_List* New ) {
	if ( !self or !PrepareMove_( self, New ) ) {
        return false;
    }

	New->Parent = self;
	JB_List* c = self->Child;

	if ( !c ) {
		self->Child = New;
		New->Next = 0;
		New->Prev = New;
	} else {
		JB_List* Last = c->Prev;

		c->Prev = New;

		New->Next = 0;
		New->Prev = Last;

		Last->Next = New;
	}
	return true;
}



bool JB_Ring_FirstSet( JB_List* self, JB_List* Mover ) {
	if ( Mover and self ) {
        JB_List* First = JB_Ring_First( self );
        if ( !First )
            return JB_Ring_LastSet( self, Mover );
		  else if (First != Mover) 
			return JB_Ring_PrevSibSet( First, Mover );
    }
    return false;
}


JB_List* JB_Ring_Constructor0( JB_List* self ) {
	JB_New2(JB_List);
    self->Position = 0;
    self->Obj = 0;
    self->Parent = 0;
    self->Next = 0;
    self->Prev = 0;
    self->Child = 0;
    return self;
}
    
    
JB_List* JB_Ring_Constructor( JB_List* self, JB_List* Parent ) {
	JB_New2(JB_List);
    self->Position = 0;
    self->Obj = 0;
    self->Next = 0;
    self->Child = 0;
    self->Parent = Parent;
    if (!Parent) {
        self->Prev = 0;
        return self;
    }

    Sanity(Parent);
	JB_List* First = Parent->Child;

    JB_Incr( self );
	
    if ( First ) {
        JB_List* Last = First->Prev;
        First->Prev = self;
        Last->Next = self;
        self->Prev = Last;
    } else {
		Parent->Child = self;
		self->Prev = self;
    }
    Sanity(self);
    Sanity(Parent);
    return self;
}
    


void JB_Ring_Destructor( JB_List* self ) {
	JB_List* Curr = self->Child;
	// some kind of flattened destroyer sounds good?
	// less ffing around with stuff.
	while (Curr) {
		JB_List* Next = Curr->Next;
		RingOwnForDeref_( Curr );
		JB_Decr( Curr );
		Curr = Next;
	};
    if (self->Parent) {
		RingLeave_( self );
		RingOwnForDeref_( self );
		JB_SafeDecr( self );
	}
	JB_SetRef(self->Obj, 0);
}

}

