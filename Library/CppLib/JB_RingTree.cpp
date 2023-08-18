
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


/*
    A tree good for fast insert, append, remove and with no cyclical refcounting.

    No RingTree can be moved into it's own desendant or itself.

    I do things a bit lopsided, but it works out for the best!
    LastChild.next = 0, apart from that it's a plain double-ring.
*/


#include "JB_Umbrella.hpp"


extern "C" {

static void RingLeave_( RingTree* rt );


inline bool RingIsRoot_( RingTree* rt ) {
	if ( !rt->Parent ) {
		dbgexpect2( !rt->Prev );
		dbgexpect2( !rt->Next );
		return true;
	}
	return false;
}

#define Sanity(s)

static void AncestorSanity_(RingTree* Curr) {
    // not parent of myself
    RingTree* Parent = Curr->Parent;
    while (Parent) {
        if (Curr == Parent) {
            debugger;
        }
        Parent = Parent->Parent;
    }
}


static void LoopSanity_(RingTree* self) {
	RingTree* Curr = self->Next;
	while (Curr) {
		if (Curr == self)
			debugger;
		RingTree* N = Curr->Next;
		if (N and N->Prev != Curr)
			debugger;
		Curr = N;
	}
}


static void AmContainedSanity_(RingTree* Curr) {
    // find self in parent
    RingTree* Parent = Curr->Parent;
    if (!Parent) {
        return;
    }

    bool Found = false;
    RingTree* Ch = Parent->Child;
    while (Ch) {
        if (Ch == Curr) {
            Found = true;
        }
        Ch = Ch->Next;
        if (!Ch) {
            break;
        }

        RingTree* Prev = Ch->Prev;
        if (Prev->Next != Ch) {
            debugger;
        }
    }

    if (!Found) {
        debugger; // not found
    }
}

static void Sanity_(RingTree* Curr) {
    if (!Curr) {
        return;
    }

    
    AncestorSanity_( Curr );
    AmContainedSanity_( Curr );
    LoopSanity_(Curr);
}


static RingTree* LastSanity = 0;
void JB_Ring_TotalSanity(RingTree* Root) {
    if (!Root) {
        Root = LastSanity;
        if (!Root) {
            return;
        }
    } else {
        LastSanity = Root;
    }
    
    RingTree* After = JB_Ring_FlatAfter(Root);
    RingTree* Curr = Root;
    while (Curr != After) {
        AmContainedSanity_(Curr);
        Curr = JB_Ring_FlatNext0(Curr);
    }
}



inline void RingOwnForDeref_( RingTree* Curr ) {
    Curr->Next = 0;
    Curr->Parent = 0;
    Curr->Prev = 0;
}


bool JB_Ring_IsAncestor( RingTree* child, RingTree* ance ) {
	RingTree* p = child->Parent;
	while ( p ) {
		if ( p == ance ) {
			return true;
		}

		p = p->Parent;
	}

	return false;   
}

static bool DB_RingIsAncestor_( RingTree* child, RingTree* ance ) {
#if DEBUG || AS_LIBRARY // important!
	return JB_Ring_IsAncestor(child, ance);
#endif

	return false;   
}


inline bool PrepareMove_( RingTree* place, RingTree* mover ) {
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

    JB_ErrorHandleC("Error: moved a RingTree node to the wrong place", false);
	JB_DoAt(1);

    return false;
}


bool JB_Ring_HasChildren( RingTree* self ) {
    return self and self->Child;
}

int JB_Ring_Count( RingTree* self ) {
	RingTree* c = self->Child;
	
    int N = 0;
	while ( c ) {
		c = c->Next;
        N++;
	}
	
	return N;
}

bool JB_Ring_HasChildCount( RingTree* self, int HasCount ) {
	RingTree* c = self->Child;
	
	while ( HasCount-- >= 1 ) {
		if ( !c ) {
			return false;
		}
		c = c->Next;
	}
	
	return ( !c );
}

RingTree* JB_Ring_Last( RingTree* self ) {
	if (self) {
		RingTree* c = self->Child;
		if ( c ) {
			return c->Prev;
		}
	}
	return 0;
}

RingTree* JB_Ring_NextSib( RingTree* self ) {
	if (self) {
		return self->Next;
	}
	return 0;
}

RingTree* JB_Ring_PrevSib( RingTree* self ) {
	if (self) {
		RingTree* Prev = self->Prev;
		if (Prev and Prev->Next) { // the last one has no next!
			return Prev;
		}
	}
		
	return 0;
}

RingTree* JB_Ring_First( RingTree* self ) {
	if (self)
		return self->Child;
	return 0;
}

RingTree* JB_Ring_Parent( RingTree* self ) {
	if (self)
		return self->Parent;
	return 0;
}

RingTree* JB_Ring_Root( RingTree* self ) {
	RingTree* rz = self;
	while ( self ) {
		rz = self;
		self = self->Parent;
	}
	return rz;
}


bool JB_Ring_IsRoot( RingTree* self ) {
	if (self) {
		return ( !self->Parent );
	}
	return 0;
}


static void RingLeave_( RingTree* rt ) {
    Sanity(rt);
	dbgexpect( rt );
	dbgexpect( !RingIsRoot_( rt ) ); // 
	RingTree* n = rt->Next;
	RingTree* p = rt->Prev;
	RingTree* Parent = rt->Parent;
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


inline void InsertBefore_( RingTree* pl, RingTree* rt ) {
	dbgexpect( rt );
	dbgexpect( pl );
	RingTree* Parent = pl->Parent;
	dbgexpect( Parent );

	RingTree* Prev = pl->Prev;
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


inline void InsertAfter_( RingTree* pl, RingTree* rt ) {
	dbgexpect( rt );
	dbgexpect( pl );
	RingTree* Parent = pl->Parent;
	dbgexpect( Parent );

	RingTree* Next = pl->Next;

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


struct DepthNode { RingTree* Node; int Depth; };

DepthNode FlatNext( RingTree* self, bool AllowDown ) {
	Sanity( self );
	
	RingTree* c = self->Child;
	RingTree* up = self->Parent;
	int Depth = 0;

	if (AllowDown and c) {
		if (up != self) { // owner!
			Depth++;
		}
		return {c, Depth};
	}

	while (up != self  and  up) {
		RingTree* n = self->Next;

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
RingTree* JB_Ring_FlatNext0( RingTree* self ) {
	return FlatNext( self, true ).Node;
}


RingTree* JB_Ring_FlatNextDepth( RingTree* self, int* Depth, bool Down ) {
	auto D = FlatNext( self, Down );
	if (Depth)
		*Depth += D.Depth;
	return D.Node;
}


RingTree* JB_Ring_FlatAfter( RingTree* self ) {
	if (self)
		return FlatNext( self, false ).Node;
	return 0;
}


void JB_Ring_ParentSet( RingTree* self, RingTree* NewParent ) {
	if (NewParent) {
		JB_Ring_LastSet( NewParent, self );
	} else if (self and self->Parent) {
		RingLeave_( self );
		RingOwnForDeref_( self );
		JB_Decr(self);
	}
}


void JB_Ring_NextSibSet( RingTree* self, RingTree* Mover ) {
	if ( self->Parent and PrepareMove_( self, Mover ) ) {
		InsertAfter_( self, Mover );
	}
	//return false;
}


bool JB_Ring_PrevSibSet( RingTree* self, RingTree* Mover ) {
	if ( self->Parent and PrepareMove_( self, Mover ) ) {
		InsertBefore_( self, Mover );
		return true;
	}
	return false;
}


bool JB_Ring_LastSet( RingTree* self, RingTree* New ) {
	if ( !self or !PrepareMove_( self, New ) ) {
        return false;
    }

	New->Parent = self;
	RingTree* c = self->Child;

	if ( !c ) {
		self->Child = New;
		New->Next = 0;
		New->Prev = New;
	} else {
		RingTree* Last = c->Prev;

		c->Prev = New;

		New->Next = 0;
		New->Prev = Last;

		Last->Next = New;
	}
	return true;
}



bool JB_Ring_FirstSet( RingTree* self, RingTree* Mover ) {
	if ( Mover and self ) {
        RingTree* First = JB_Ring_First( self );
        if ( !First )
            return JB_Ring_LastSet( self, Mover );
		  else if (First != Mover) 
			return JB_Ring_PrevSibSet( First, Mover );
    }
    return false;
}


RingTree* JB_Ring_MakeFirst( RingTree* self ) {
	// buggy? the order seems altered...
	RingTree* P = self->Parent;
	require(P);
	RingTree* F = P->Child;
	RingTree* L = F->Prev;
	RingTree* Pr = self->Prev;
	L->Next = F;							// Restore the links!
	P->Child = self;						// OK... so we become the first...
	Pr->Next = nil;							// Thats it???
	Sanity_(self);
	return F;
}


void JB_Ring_Constructor0( RingTree* self ) {
    self->Position = 0;
    self->Parent = 0;
    self->Next = 0;
    self->Prev = 0;
    self->Child = 0;
}
    
    
void JB_Ring_Constructor( RingTree* self, RingTree* Parent ) {
    self->Position = 0;
    self->Next = 0;
    self->Child = 0;
    self->Parent = Parent;
    if (!Parent) {
        self->Prev = 0;
        return;
    }

    Sanity(Parent);
	RingTree* First = Parent->Child;

    JB_Incr( self );
	
    if ( First ) {
        RingTree* Last = First->Prev;
        First->Prev = self;
        Last->Next = self;
        self->Prev = Last;
    } else {
		Parent->Child = self;
		self->Prev = self;
    }
    Sanity(self);
    Sanity(Parent);
}
    


void JB_Ring_Destructor( RingTree* self ) {
	RingTree* Curr = self->Child;
	
	// if it's got a prev...
		// it has either got a parent (so its dispose)
		// it it doesnt               (so its a weaklist destructor, but check for the refcount)
	
	while (Curr) {
		RingTree* Next = Curr->Next;
		RingOwnForDeref_( Curr );
		JB_Decr( Curr );
		Curr = Next;
	};
    if (self->Parent) {				// from .dispose
		RingLeave_( self );
		RingOwnForDeref_( self );
		JB_SafeDecr( self );
	}
	// weaklist can just decrement an existing node?/?
	
}

}

