
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

// todo
// * Use JB_List for world/super/block! makes code simpler!
// * Can just do block = JB_RT_Next2(block); // goes up and down if hits end
// 												easy way to list all blocks in the world!
// * also... can put worlds together. Like sound/map/graphics/obj

/*
What about this idea? Pointer compression:

    void* addr = mmap(
        NULL, // address hint
        1<<MemoryManager.SuperSize, // size
        PROT_READ | PROT_WRITE, // permissions
        MAP_32BIT | MAP_PRIVATE | MAP_ANONYMOUS, // flags
        -1, // file descriptor
        0 // offset
    );

    All our super-blocks can be allocated that way.
    
    We also need -pagezero_size,0x1000 linker flag. Or else OSX will flip out.

	We'll need some way to make sure our pointers only take 32-bits. Not sure if theres a built in way in C for that.
 */

#include "JB_Alloc.h"



#ifdef ENV64BIT
    #define kBlockSize          13  // 8K!
    #define BadBit				3
#else
    #define kBlockSize          12  // 4K
    #define BadBit				3
#endif



extern "C" {

int RefTrap = 0;
bool DoTotalMemoryTest=false;

inline void failed(const char* c) {
	printf("jbmem error: %s\n", c);
	debugger;
}

struct FreeObject {
	union { // ughweneedit
		int         FakeRefCount; // 
		FreeObject* Next;
	}; 
};


struct MemStats {
    int Objs;
    int Blocks;
};


enum {
    kFineBins = 3,
    kCoarseBins = 2,
};


int JB_AllocationBlockHeaderSize() {
    return sizeof(AllocationBlock);
}
void JB_Mem_Destructor( JB_MemoryLayer* self );


////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

static bool IsDummy( const AllocationBlock* Block ) {
    AllocationBlock* OwnersDummy = (AllocationBlock*)(&Block->Owner->Dummy);
    return OwnersDummy == Block;
}
static fpDestructor GetDestructor_(AllocationBlock* B) {
	return (fpDestructor)(B->Virtuals->__destructor__);
}



static inline AllocationBlock* OfficialStart_(SuperBlock* NewSuper, IntPtr BlockSize) {
	return (AllocationBlock*)(((IntPtr)NewSuper | (BlockSize-1)) &~ (sizeof(AllocationBlock)-1));
}
static inline AllocationBlock* StartBlock_(SuperBlock* Super) {
    return Super->StartBlock;
}
static inline AllocationBlock* EndBlock_(SuperBlock* Block) {return (AllocationBlock*)Block->BlockEnd;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

JB_MemoryWorld MemoryManager;


static JBObject_Behaviour DummyFuncTable = {};
JB_Class* AllClasses;
static int DM = 0;


static bool MiniCompare (const char* s, const char* find) {
	while (auto c = *find++)
		if (*s++ != c)
			return false;
	return true;
}

void JBClassInitReal(JB_Class& Cls, const char* Name, int Size, JB_Class* Parent, JBObject_Behaviour* Table) {
    if (!MemoryManager.Name) {
        MemoryManager.Name           = (uint8*)"JB Standard Memory";
        MemoryManager.SuperSize      = 20;
        MemoryManager.BlockSize      = kBlockSize;
        MemoryManager.Alignment      = 4;
        MemoryManager.SpareTrigger   = 0.75f;
    }
	
	Cls.RefCount = 1024;
	if (MiniCompare(Name, "JB_"))
		Name += 3;
    Cls.Name = Name;
    Cls.Parent = Parent;
    if (!Table) //
		Table = &DummyFuncTable;
    Cls.Virtuals = Table;
    Cls.DefaultBlock = (AllocationBlock*)(&Cls.Memory.Dummy);
    Cls.Memory.RefCount = 1024;
    Cls.Memory.Class = &Cls;
    Cls.Memory.Dummy.Owner = &Cls.Memory;
    Cls.Memory.CurrBlock = (AllocationBlock*)(&Cls.Memory.Dummy);
    Cls.Memory.IsActive = true;
    Cls.Memory.World = &MemoryManager;
    Cls.Size = Max(Size, sizeof(FreeObject));
    if (Parent) {
        Parent->HasSubclasses = true;
		Cls.ClassDepth = Parent->ClassDepth + 1; 
    }
    
    Cls.NextClass = AllClasses;
    AllClasses = &Cls;
}


// interpreter
JB_Class* CakeClass;
void** CakeVirtuals;
bool JB_Cake__Prepare (int N, int B) {
	N*=sizeof(JB_Class);
	B*=sizeof(void*);
	byte* Data = (byte*)calloc(N + B + 8, 1);
	if (!Data) return false;
	CakeClass = (JB_Class*)Data;
	CakeVirtuals = (void**)(Data + N + 8);
	return true;
}

void** JB_Cake_Virtuals(JB_Class* C) {
	return (void**)C->Virtuals;
}

JB_Class* JB_Cake__Class(const char* Name, int Size, JB_Class* Parent, int VCount) {
	auto Cls = CakeClass;
	CakeClass = Cls + 1;
	auto V = CakeVirtuals;
	CakeVirtuals = V + VCount;
	JBClassInitReal(*Cls, Name, Size, Parent, (JBObject_Behaviour*)V);
	return Cls;
}



MemStats JB_MemoryStats(JB_MemoryWorld* World, bool CountObjs, u16 Mark) {
    SuperBlock* First = World->CurrSuper;			// issue?
    SuperBlock* Super = First;						// issue?
    if (!Super)
		return {};
    MemStats Result = {};
    
	u16 ActualMark = Mark &~ 0xf000;
	bool IsCheck   = Mark & 0xf000;
    do {
        Result.Blocks += (Super->BlocksActive);
        
        if (CountObjs) {
            AllocationBlock* Start = StartBlock_(Super);
            AllocationBlock* Finish = EndBlock_(Super);

            do {
                int C = Start->ObjCount + Start->HiddenObjCount;
                Result.Objs += C;
                Start = JBShift(Start, 1 << World->BlockSize);
            } while (Start < Finish);
        }

        Super = Super->Next;
    } while (Super != First);
	
    return Result;
}


inline AllocationBlock* ObjBlock_(void* Obj) {
    IntPtr Addr = (IntPtr)Obj | ((1<<kBlockSize)-1);
    Addr = Addr &~ (sizeof(AllocationBlock)-1);
    return (AllocationBlock*)Addr;
}


char* BlockStart_(AllocationBlock* B) {
	return (char*)(((IntPtr)B) &~ ((1<<kBlockSize)-1));
}


void BlockIsFreeMark (JB_Object* self) {};

u64 JB_MemCount() {
    JB_MemoryWorld* World = JB_MemStandardWorld();
    return (u64)( JB_MemoryStats(World, false, 0).Blocks ) << World->BlockSize;
}

JBObject_Behaviour SuperSanityTable = {(void*)BlockIsFreeMark, 0};

#if !JBTestSanityOK
	#define TestMemory_(x)
	#define SanityOfInUse(a,b)
	#define SanityOfFree(a)
	static void Sanity(AllocationBlock* B, bool HasBeenSetup = true) {}
	#define ObjInBlock(a,b)
#else
	FreeObject* ObjInBlock(FreeObject* Obj, AllocationBlock* B) {
		char* S = BlockStart_(B);
		char* ObjEnd = ((char*)Obj) + B->ObjSize;
		if ((char*)Obj < S  or  ObjEnd > (char*)B) {
			if (Obj==B->FirstFree) {
				failed("corrupt block first free");
			} else {
				failed("corrupt freeobj next chain");
			}
		}
		if (((IntPtr)(Obj->Next)) & BadBit)
			failed("corrupt freeobj next ptr");
		return Obj->Next;
	}
	void AllocBlock_Debug(AllocationBlock* B) {
		FreeObject* Obj = B->FirstFree;
		while (Obj) {
			Obj = ObjInBlock(Obj, B);
		};
	}



	static bool FreeBlock_(AllocationBlock* B) {
		return (GetDestructor_(B) == BlockIsFreeMark);
	}


	void TestMemory_(AllocationBlock* B) {
		if (!B) {
			return;
		}
		if (IsDummy(B)) {
			return;
		}
		AllocationBlock* N = B->Next;
		AllocationBlock* P = B->Prev;
		if (N) {
			if (IsDummy(N))
				failed("isdummy");
			if (FreeBlock_(N) != FreeBlock_(B))
				failed("freeblock");
		}
		if (P) {
			if (IsDummy(P))
				failed("isdummy2");
			if (FreeBlock_(P) != FreeBlock_(B))
				failed("freeblock2");
		}
		
		AllocBlock_Debug(B);
		
		auto W = B->Owner;
		if (W) {
			auto Cls = W->Class;
			if (Cls and Cls->DefaultBlock == B) {
				return;
			}
		}
		
		
		FreeObject* O = B->FirstFree;
		if (!O) return;
		auto Curr = B->Super;
		if (O < Curr->StartObj)
			failed("startobj");
		if (O >= Curr->BlockEnd)
			failed("blockend");
		int i = 0;
		while (O) {
			O = O->Next; // check for memory corruption
			i++;
			if (i >= (1<<kBlockSize)>>2)
				failed("corrupt1");
		}
	}

	static bool IsBadFree_(AllocationBlock* Curr) {
		if (Curr->Prev) {
			failed("corrupt2");
			return true;
		}
		AllocationBlock* N = Curr->Next;
		if (N == Curr) {
			failed("corrupt3");
			return true;
		}
		fpDestructor D = GetDestructor_(Curr);
		if (D != BlockIsFreeMark) {
			failed("corrupt4");
			return true;
		}
		return false;
	}


	static int CanFollow2_( AllocationBlock* First, bool Forward ) { 
		// try to follow the links... until we find the end!
		int Count = 0; // max...
		AllocationBlock* Curr = First;
		do {
			fpDestructor D = GetDestructor_(Curr);
			if (D == BlockIsFreeMark) {
				failed("corrupt5");
				return -1;
			}
			Count++;
			if (Forward) {
				Curr = Curr->Next;
			} else {
				Curr = Curr->Prev;
			}
			if (!Curr) {
				failed("corrupt6");
				return -2;
			}
			if (Count > 100) {
				failed("corrupt7");
				return -3;
			}
		} while (Curr != First);
		return Count;
	}


	static bool IsBadInUse_(AllocationBlock* Curr) {
		TestMemory_(Curr);
		int A = CanFollow2_(Curr, true);
		int B = CanFollow2_(Curr, false);
		if (A != B) {
			failed("corrupt8");
		}
		return false;
	}


	static void SanityOfInUse(SuperBlock* Sup, JB_MemoryWorld* World) {
		AllocationBlock* Curr = StartBlock_(Sup);
		AllocationBlock* Finish = EndBlock_(Sup);
		while (Curr < Finish) {
			if (GetDestructor_(Curr) != BlockIsFreeMark) {
				IsBadInUse_(Curr);
			} else {
				TestMemory_(Curr);
			}
			Curr = JBShift( Curr, 1 << World->BlockSize );
		}
	}


	static void SanityOfFree(SuperBlock* Sup) {
		AllocationBlock* F = Sup->FirstBlock;
		AllocationBlock* Curr = F;
		while (Curr) {
			if (GetDestructor_(Curr) != BlockIsFreeMark) {
				failed("corrupt9");
			}
			IsBadFree_(Curr);
			Curr = Curr->Next;
		}
	}


	static void Sanity(AllocationBlock* B, bool HasBeenSetup = true) {
		if (B) {
			if (HasBeenSetup and !IsDummy(B) and !B->DebugMark)
				0; // debugger; // /????? // why is this happening?
			TestMemory_(B);
		}
	}
#endif

//void JB_Class_Init(JB_Class* Cls, JB_MemoryWorld* World, int Size) {
//    memzero(Cls, sizeof(JB_Class)); // can’t use JB_Zero.
//    Cls->DefaultBlock = (AllocationBlock*)(&Cls->Memory.Dummy);
//    Cls->Size = Size;
//    Cls->Memory.RefCount = 1; // so it never goes away
//    Cls->Memory.CurrBlock = (AllocationBlock*)(&Cls->Memory.Dummy);
//    Cls->Memory.Dummy.Owner = &Cls->Memory;
//    Cls->Memory.World = World;
//    Cls->Memory.Class = Cls;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

JB_MemoryLayer* JB_Mem_Constructor( JB_MemoryLayer* self, JB_Class* Cls ) {
	JB_New2(JB_MemoryLayer);
    JB_Zero(self);
    self->Class = Cls;
    self->CurrBlock = (AllocationBlock*)&(self->Dummy);
    self->Dummy.Owner = self;
    self->World = JB_MemStandardWorld();
    return self;
}


JB_MemoryLayer* JB_Mem_CreateLayer(JB_Class* Cls, JB_Object* Obj) {
    JB_MemoryLayer* Mem = JB_Mem_Constructor(0, Cls);
    JB_SetRef(Mem->Obj, Obj);
    return Mem;
}



void JB_Mem_Use( JB_MemoryLayer* self ) {
    // shouldn't we incr the layer? or not?
    if (self->IsActive) { // save time...
        return;
    }
    JB_Class* Cls = self->Class;
    AllocationBlock* ClsBlock = Cls->DefaultBlock;
    ClsBlock->Owner->IsActive = false;
    Cls->DefaultBlock = self->CurrBlock; // swap first...
    self->IsActive = true;
    /// what does this do even, or why? I forgot?
    /// we are putting into the class, but why compare something to self and why incr or decr?
    if (ClsBlock->Owner != self) {
        JB_Incr_((JB_Object*)self);
        JB_Decr(ClsBlock->Owner);
    }
    TestMemory_(Cls->DefaultBlock);
}


void JB_Mem_Unmark( ) {
	JB_MemoryStats(&MemoryManager, true, 1234|0xf000);
	JB_MemoryStats(&MemoryManager, true, 0);
}


void JB_Mem_Mark( ) {
	JB_MemoryStats(&MemoryManager, true, 1234);
}


void JB_Mem_Destructor( JB_MemoryLayer* self ) {
    if (self->SpareBlock) {
        self->SpareBlock->Owner = 0;
    }
    JB_SetRef( self->Obj, 0 );
    JB_SetRef( self->Obj2, 0 );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////


///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   



void JB_Helper_PutBefore(JB_RingList* Old, JB_RingList* New) {
	JB_RingList* P = Old->Prev;
	P->Next = New;
	New->Prev = P;
	New->Next = Old;
	Old->Prev = New;
}



void JB_Helper_Unlink(JB_RingList* Curr) {
    JB_RingList* N = Curr->Next;
    JB_RingList* P = Curr->Prev;
    N->Prev = P;
    P->Next = N;
    Curr->Next = Curr;
    Curr->Prev = Curr;
}



  ///////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////

JB_MemoryLayer* JB_Class_Layer( JB_Class* Cls ) {
    return Cls->DefaultBlock->Owner;
}

JB_MemoryLayer* JB_Class_CurrLayer( JB_Class* Cls ) {
    return JB_Class_Layer(Cls);
}


JB_Object* JB_Class_AllocZeroed( JB_Class* Cls ) {
    JB_Object* Result = JB_AllocNew(Cls->DefaultBlock);
    if (Result) {
        memzero(Result, Cls->Size);
    }
    return Result;
}


JB_MemoryLayer* JB_Class_DefaultLayer( JB_Class* Cls ) {
    return &Cls->Memory;
}


JB_MemoryLayer* JB_ObjLayer( JB_Object* Obj ) {
    if (Obj) {
        AllocationBlock* Block = ObjBlock_(Obj);
        return Block->Owner;
    }
    return 0;
}


uint JB_ObjectID( JB_Object* Obj ) {
	if (Obj) {
		AllocationBlock* Block = ObjBlock_(Obj);
		require(((IntPtr)Block->Super) >= 4000);
		uint SuperID = Block->Super->ID;
		IntPtr Offset = ((IntPtr)Obj) - ((IntPtr)(Block->Super));
		return (SuperID << 20) + (uint)(Offset >> 3);// min objectsize = 8. So we can lose 3 bits
													// SuperID is also different. Need to increase it so it won't collide.
	}
	return 0;
}


JB_Class* JB_ObjClass(JB_Object* Obj) {
	auto L = JB_ObjLayer(Obj);
	if_usual (L) // whatever
		return L->Class;
	return 0;
}

  

uint8* JB_ObjClassBehaviours(JB_Object* Obj) {
    // assume exists.
    auto Block = ObjBlock_(Obj);
    return (uint8*)(Block->Virtuals);
}


//void JB_ObjDestroy( JB_Object* Obj ) {
//  violates the nil-checker.
//	if (Obj) {
//		AllocationBlock* Block = ObjBlock_(Obj);
//		fpDestructor Destructor = GetDestructor_(Block);
//		if (Destructor) {
//			(Destructor)(Obj);
//		}
//		// in theory... I could call the default constructor after? In fact it may be faster than calling memset!
//		JB_Class* Cls = Block->Owner->Class;
//		memzero(4+(char*)Obj, Cls->Size - 4);
//	}
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////



static void SetCurrBlock_( JB_MemoryLayer* Mem, AllocationBlock* NewBlock ) {
Sanity(NewBlock);
    JB_Class* Cls = Mem->Class;
    if (Cls and (Cls->DefaultBlock == Mem->CurrBlock)) {
        // class is using this JB_MemoryLayer...
        Cls->DefaultBlock = NewBlock;
        TestMemory_(NewBlock); // sigh... test memory
    }
    
    Mem->CurrBlock = NewBlock;
}


void JB_DebugAllMemory(bool b)  {
	DoTotalMemoryTest = b;
}

bool JB_TotalSanity(bool Force) {
	if (!Force and !DoTotalMemoryTest)
		return true;
	auto cls = AllClasses;
	while (cls) {
		TestMemory_(cls->DefaultBlock);
		cls = cls->NextClass;
	}
	SuperBlock* Sup0 = MemoryManager.CurrSuper;
	SuperBlock* Curr = Sup0;
	if (!Curr) {
		return true;
	}

	do {
		SanityOfInUse(Curr, &MemoryManager);
		SanityOfFree(Curr);
		Curr = Curr->Next;
	} while (Curr and Curr != Sup0);
	return true;
}


static FreeObject* LinkIn_(JB_MemoryLayer* Mem, AllocationBlock* NewBlock) {
Sanity(NewBlock);
// Call this when returning the first item from a newly allocated block.
    SetCurrBlock_( Mem, NewBlock );
    Mem->RefCount+=1<<JB_RefCountShift;
    FreeObject* First = NewBlock->FirstFree;
    NewBlock->FirstFree = First->Next;
    NewBlock->ObjCount++;
Sanity(NewBlock);
	
    return First;
}

static AllocationBlock* LinkInSuper_(JB_MemoryWorld* World, SuperBlock* Super) {
    if (Super->World!=World) {
        Super->World = World;
        Super->BlocksActive++;
        World->CurrSuper = Super; // issue?
        World->CountRef++;
    }
    AllocationBlock* First = Super->FirstBlock;
Sanity(First, false);
Sanity(First->Next, false);
    Super->FirstBlock = First->Next;
    First->Next = 0;
    return First;
}



// write the AllocationBlocks... at the end.
static inline void SetupSuper_(SuperBlock* Super, JB_MemoryWorld* W) {
    AllocationBlock* Curr = StartBlock_( Super );
    AllocationBlock* End =  EndBlock_( Super );
    int Size = 1 << W->BlockSize;

    Super->FirstBlock = Curr;

    while (Curr < End) {
        AllocationBlock* Next = JBShift(Curr, Size);
        Curr->Super = Super;
        Curr->Virtuals = &SuperSanityTable;
        Curr->Owner = 0; // for clearing
        Curr->Next = Next;
        Curr = Next;
    }
    Curr = JBShift(Curr, -Size);
    Curr->Next = 0;
}



void* JB_BlockShadow(AllocationBlock* B) {
	SuperBlock* S = B->Super;
	JB_MemoryWorld* W = S->World;
	int Shadow = (1 << W->ShadowSize) &~ 1;
	return (void*)JBShift(B, -Shadow);
}


static void InitObjectsInBlock_(JB_MemoryLayer* Mem, AllocationBlock* NewBlock, JB_MemoryWorld* W, int Size) {
	NewBlock->ObjSize = Size;
    auto oof = NewBlock->Owner;
    int BS = W->BlockSize;
    int BlockBits = (1 << BS) - 1;
    FreeObject* Curr = (FreeObject*)(((IntPtr)NewBlock) &~ BlockBits);
    NewBlock->FirstFree = Curr; // for LinkIn_
	if (Mem->BoostMode) {
		return;
	}

    FreeObject* TrueFirst = NewBlock->Super->StartObj;
    if (Curr < TrueFirst) {
        Curr = TrueFirst;
    }
    
    FreeObject* End =  (FreeObject*)NewBlock;		// we aren't using shadows anymore...
    dbgexpect(Curr < End);							// it was a bad design...
    dbgexpect(!W->ShadowSize or W->ShadowSize > 3);
    int Shadow = (1 << W->ShadowSize) &~ 1;		// incase it's 0
    End = JBShift(End, -Shadow);
    dbgexpect(Curr < End);
    void* ShadowEnd = JB_BlockShadow(NewBlock);
    dbgexpect(End == ShadowEnd);
    
    NewBlock->FirstFree = Curr; // for LinkIn_
	
	FreeObject* NextStart = JBShift(Curr, Size);
    while (Curr) {
		FreeObject* NextEnd = JBShift(NextStart, Size);
		if (NextEnd >= End) {
			if (NextEnd == End) {
				NextEnd = 0;
			} else {
				NextStart = 0;
			}
		}
        Curr->Next = NextStart;
        Curr = NextStart;
        NextStart = NextEnd;
    }

	if (oof != NewBlock->Owner) failed("corrupt12");
}



static AllocationBlock* SuperBlockSetup_( SuperBlock* Super, JB_MemoryWorld* World ) {
	if (World->CurrSuper) {
		JB_Helper_PutBefore((JB_RingList*)(World->CurrSuper), (JB_RingList*)Super);
    } else {
		Super->Prev = Super;
		Super->Next = Super;
    }
    SetupSuper_( Super, World );
    return LinkInSuper_(World, Super);
}


int FindClassDepth(JB_Class* C) { 
	int n = 1;
	while (C) {
		C = C->Parent;
		n++;
	}
	return n;
}

void JB_CollectClassDepths () {
	auto C = AllClasses;
	while (C) {
		C->ClassDepth = FindClassDepth(C);
		C = C->NextClass;
	}
}


static FreeObject* BlockSetup_ ( JB_MemoryLayer* Mem, AllocationBlock* NewBlock, JB_MemoryWorld* World ) {
    if (!NewBlock)
        return 0;

//	printf("%x\n", NewBlock);
	NewBlock->DebugMark = ++DM;
    Sanity(NewBlock);
    JB_Class* Class = Mem->Class;
    NewBlock->Virtuals = Class->Virtuals; // faster vfuncs
    NewBlock->Owner = Mem;

	int Size = Class->Size;
    if (NewBlock->ObjSize != Size)
		InitObjectsInBlock_( Mem, NewBlock, World, Size );

    NewBlock->Prev = NewBlock;
    NewBlock->Next = NewBlock;

    return LinkIn_(Mem, NewBlock);
}




// SuperBlocks
// JB_MemoryLayer
// AllocationBlocks
// Objects


extern "C" int64 JB_ErrorHandleC(const char* Desc, bool CanFreeDesc);
extern "C" uint8* JB__WriteIntToBuffer (uint8* wp, s64 LeftOver);


void JB_OutOfMainMemory(int64 N) {
    if (!OutOfMemoryHappenedAlready) {
        printf("Jeebox: Failed to allocate %lli bytes of main memory.\n", N);
        OutOfMemoryHappenedAlready++;
		JB_ErrorHandleC("Memory Manager failed to allocate Object", false);
    }
}


bool JB_OutOfMemoryOccurred () {
    return OutOfMemoryHappenedAlready;
}


static SuperBlock* Super_calloc(JB_MemoryWorld* World) {
    int N = (1 << World->SuperSize);
    int Align = (1 << World->BlockSize);

    while (N >= Align*4) {
		SuperBlock* bla = (SuperBlock*)JB_AlignedAlloc(N, Align);
        if (bla) {
//            printf("allocating %i (%s): %X\n", N, World->Name, (void*)bla);
            memset(bla, 0, N);
            bla->BlockEnd = ((uint8*)bla) + N;
            return bla;
        }
        N -= Align;
    }
    
    JB_OutOfMainMemory(N);
    return 0;
}


static void SuperFree_(SuperBlock* Super) {
    Super->World->CountRef--;
    JB_AlignedFree(Super);
}


static SuperBlock* AllocSuper(JB_MemoryWorld* World) {
    SuperBlock* NewSuper = Super_calloc(World);
    require(NewSuper);
    
    NewSuper->ID = World->SupersMade++;

    int BlockSize = 1 << World->BlockSize;

    FreeObject* FirstWriteable = (FreeObject*)JBShift(NewSuper, sizeof(SuperBlock));
    
    int Alignment = 1 << World->Alignment;
    IntPtr Extra = (IntPtr)(FirstWriteable) & (Alignment - 1);
    if (Extra) {
        FirstWriteable = (FreeObject*)JBShift(FirstWriteable, Alignment - Extra);
    }

    NewSuper->StartObj = FirstWriteable;
    NewSuper->StartBlock = OfficialStart_(NewSuper, BlockSize);

    return NewSuper;
}


static AllocationBlock* NewSuperBlock_(JB_MemoryLayer* Mem, JB_MemoryWorld* World) {
    SuperBlock* Super = AllocSuper(World);
    require(Super);
    return SuperBlockSetup_( Super, World );
}


static AllocationBlock* FindAllocBlock_(JB_MemoryWorld* World) {
    SuperBlock* First = World->CurrSuper;
    if (!First) {
        return 0;
    }
    SuperBlock* Curr = First;
    
    do {
        AllocationBlock* Item = Curr->FirstBlock;
        if (Item) {
            Sanity(Item, false);
            if (Curr == World->SpareSuper) {
                World->SpareSuper = 0;
            }
            World->CurrSuper = Curr;
            Curr->BlocksActive++;
            Curr->FirstBlock = Item->Next;
            Item->Next = 0;
            return Item;
        }
        
        Curr = Curr->Next;
    } while (First != Curr);

    return 0;
}


static AllocationBlock* ReturnSpareHidden_(AllocationBlock* CurrBlock) {
    AllocationBlock* NewBlock = CurrBlock->Next;
    if (NewBlock != CurrBlock) {        // use this!
        JB_Helper_Unlink((JB_RingList*)CurrBlock);
        return NewBlock;
    }
    return 0;
}


static AllocationBlock* ReturnSpare_(JB_MemoryLayer* Mem) {
// Allocate a "NewBlock" by just re-using the spareblock as the currentblock...
    AllocationBlock* NewBlock = ReturnSpareHidden_( Mem->CurrBlock );
    if (NewBlock) {
        return NewBlock;
    }

    NewBlock = Mem->SpareBlock;
    Sanity(NewBlock);
    if (NewBlock) { // Improvement?: Stick the spareblock on the normal "next" list. And just test that it's a spare. 1 less branch!
        if (NewBlock->Owner!=Mem) {
            failed("corrupt13"); // big problem, our cleanspares function assumes this!
        }
        Mem->SpareBlock = 0;
        NewBlock->Super->BlocksActive++;
        return NewBlock;
    }
    return 0;
}


static u16 HiddenRef_(float R, int Size) {
    int N = (1<<kBlockSize) - sizeof(AllocationBlock);
    int N2 = N * R;
    return N2 / Size;
}


static FreeObject* NewBlock( AllocationBlock* CurrBlock ) {
    JB_MemoryLayer* Mem = CurrBlock->Owner;
    JB_MemoryWorld* World = Mem->World;
    if (!IsDummy(CurrBlock)) {
        u16 Hidden = Mem->HiddenRefCount;       // trigger re-use of this block before it hits empty.
        if (!Hidden) {
            Hidden = HiddenRef_(World->SpareTrigger, Mem->Class->Size);
            Mem->HiddenRefCount = Hidden;
        }
        CurrBlock->HiddenObjCount = Hidden;
        CurrBlock->ObjCount -= Hidden;

        AllocationBlock* Spare = ReturnSpare_( Mem );
        if (Spare) {
            return LinkIn_(Mem, Spare);
        }
    }

    AllocationBlock* Result = FindAllocBlock_( World );
    if (!Result)
        Result = NewSuperBlock_( Mem, World );
    return BlockSetup_( Mem, Result, World );
}



static JB_Class* ResetClass_( JB_Class* Cls ) {
    auto Mem = &Cls->Memory;
    if (JB_RefCount(Mem) != 2) {
        JB_SetRefCount(Mem, 2);
    }
    Mem->CurrBlock = Cls->DefaultBlock = (AllocationBlock*)&(Cls->Memory.Dummy);
    JB_Class* Result = Cls->NextClass;
    Cls->NextClass = 0;
    Mem->SpareBlock = 0; // why not?
    return Result;
}


static void CleanSpares_( SuperBlock* Super ) {
    JB_MemoryWorld* World = Super->World;
    int N = 1 << World->BlockSize;
    AllocationBlock* Curr = StartBlock_(Super);
    AllocationBlock* End = EndBlock_(Super);

    while (Curr < End) {	// not too sure this test is correct!
        JB_MemoryLayer* Mem = Curr->Owner;
        if ( Mem ) {		// Only exists if its a spare, seeing as the superblock's refcount is 0.
            Mem->SpareBlock = 0;
        }
        Curr = JBShift(Curr, N);
    }
}



static void PossiblyLast_(SuperBlock* Super) {
    JB_MemoryWorld* World = Super->World;
    if (World->CurrSuper == Super) {  // issue?
        SuperBlock* Next = Super->Next;
        if (Next == Super) {
            Next = 0;
        }
        World->CurrSuper = Next; // issue?
    }
}


static void JustGetRidOfIt_(SuperBlock* Super, bool ResettingApp) {
    PossiblyLast_(Super);
    JB_Helper_Unlink( (JB_RingList*)Super );
    if (!ResettingApp) {
        CleanSpares_( Super );
    }
    SuperFree_(Super);
}


static bool IsAlone_(SuperBlock* Super) {
    return Super->Next == Super;
}


static void SuperBlockFree_(SuperBlock* Super) {
    JB_MemoryWorld* World = Super->World;
    if ( World->SpareSuper ) {
        JustGetRidOfIt_(Super, false);

    } else if ( !IsAlone_( Super ) ) {
        World->SpareSuper = Super; // issue?
    }
}


static void BlockFree_( AllocationBlock* FreeBlock ) {
    Sanity(FreeBlock);
    JB_MemoryLayer* Mem = FreeBlock->Owner;
    SuperBlock* Super = FreeBlock->Super;
    if (JB_RefCount(Mem) == 2) {
        if (!Mem->World->SpareSuper and IsAlone_( Super ) ) { // avoid freeing last super, avoid thrashing.
            return;
        }
    }
    
    if (Mem->CurrBlock == FreeBlock) {
        AllocationBlock* NewCurr = ReturnSpareHidden_(FreeBlock);
        if (!NewCurr) {
            NewCurr = (AllocationBlock*)&(Mem->Dummy);
        }
        SetCurrBlock_(Mem, NewCurr);
    }
    JB_Helper_Unlink((JB_RingList*)FreeBlock);

    if (!Mem->SpareBlock) {
        Mem->SpareBlock = FreeBlock;
    } else {
        // return block to superblock

        FreeBlock->Prev = 0;
        FreeBlock->Virtuals = &SuperSanityTable;
        FreeBlock->Next = Super->FirstBlock;
        Super->FirstBlock = FreeBlock;
        Sanity(FreeBlock->Next, false); // this might not even be a real block?
    }

    JB_Decr(Mem); // i hope this works...
    
    int N = --(Super->BlocksActive);
    if (!N) {
        SuperBlockFree_(Super);
    }
}


void JB_DeleteSub_( FreeObject* Obj, AllocationBlock* Block ) {
    Obj->Next = Block->FirstFree;
    Block->FirstFree = Obj;
	ObjInBlock(Obj, Block);

    if_usual (--(Block->ObjCount) >= 1) {
        return;
    }

    int Hidden = Block->HiddenObjCount;
    if ( Hidden ) { // unhide
        Block->ObjCount = Hidden;
        Block->HiddenObjCount = 0;
        AllocationBlock* Curr = Block->Owner->CurrBlock;
        if ( IsDummy(Curr) ) {
            SetCurrBlock_(Block->Owner, Block);
        } else {
            JB_Helper_PutBefore( (JB_RingList*)Curr, (JB_RingList*)Block ); // allow it to be allocated from.
        }
        Sanity(Block);
    } else {
        BlockFree_( Block );
    }
}



// This COULD be optimised... so that we can do this with a... "stackless" system!
// it just uses loops. We create a delete-tree using the objects RAM...
// overwritign the last property. 
// that is... if we are deleting an object-tree... we don't actually need a function stack
// We'd need our optimised refcounting system... where we have like a 64-bit
// number that stores all the stuff we need to delete an object. PerryIDE only has 61 objects
// we can perhaps store the class-hierarchy within the 64-bit number or whatever.
// no need to worry about jbobject/savable... PerryIDE is only 3 classes deep...
// list is a bit of an issue, but that can be separately optimised :)
// could store the delete-info in the behaviour table or the allocationblock... either is ok.

// we could specify a compile flag that warns if any classes unnecssarily have too many vars
// to use optimised destructors.

// It could be very good to combine with reworking the constructor/new/alloc system which is
// overcomplex... Also allows for a simpler disposer...

__hot void JB_Delete( FreeObject* Obj ) {
	AllocationBlock* Block = ObjBlock_(Obj);
	Sanity(Block);
	fpDestructor Destructor = GetDestructor_(Block);
	if (Destructor) {
		(Destructor)((JB_Object*)Obj); // do this before altering memory.
	}
	JB_DeleteSub_(Obj, Block);
}


void JB_Array_Append(Array* R, JB_Object* Obj);

static void BlockFindLeakedObject_(AllocationBlock* Block, JB_Object* Obj, Array* R) {
	if (IsDummy(Block)) { // how???
		debugger;
		return;
	}
	int N = Block->ObjSize; if (N <= 0) return;
	JB_Object* S = (JB_Object*)BlockStart_(Block);
	while (S < (void*)Block) {
		JB_Object** Prop	= JBShift((JB_Object**)S, 4); // allow unaligned?
		JB_Object** PropEnd = JBShift((JB_Object**)S, N);
		if (JB_RefCount(S) < 1000) {
			while (Prop < PropEnd) {
				if (*Prop == Obj) {
					JB_Array_Append(R, S);
					break;
				}
				Prop = JBShift((JB_Object**)Prop, 4);
			}
		}
		S = (JB_Object*)PropEnd;
	}
}


static void SuperFindLeakedObject_(SuperBlock* Super, JB_Object* Obj,  Array* R) {
	AllocationBlock* Start = StartBlock_(Super);
	AllocationBlock* Finish = EndBlock_(Super);
	do {
		if (Start->Owner)
			BlockFindLeakedObject_(Start, Obj, R);
		Start = JBShift(Start, 1 << MemoryManager.BlockSize);
	} while (Start < Finish);
}


void JB_FindLeakedObject (JB_Object* Obj, Array* R) {
    SuperBlock* First = MemoryManager.CurrSuper;
    SuperBlock* Super = First;
    while (Super) {
        SuperFindLeakedObject_(Super, Obj, R);
        Super = Super->Next;
        if (Super == First) break;
    };
}


int64 JB_Class_MemoryUsed (JB_Class* Cls) {
	JB_MemoryWorld* World = &MemoryManager;
	uint C = 0;

    SuperBlock* First = World->CurrSuper;
    SuperBlock* Super = First;
    do {
		AllocationBlock* Start = StartBlock_(Super);
		AllocationBlock* Finish = EndBlock_(Super);

		do {
			auto Owner = Start->Owner;
			C += (Owner and Owner->Class == Cls);
			Start = JBShift(Start, 1 << World->BlockSize);
		} while (Start < Finish);
		Super = Super->Next;
    } while (Super != First);
    return ((int64)C) << kBlockSize;
}


void JB_Mem_ClassLeakCounter () {
	JB_MemoryWorld* World = &MemoryManager;
	static int Mode;
	if (Mode == 0)
		for (JB_Class* Cls = AllClasses; Cls; Cls = Cls->NextClass)
			Cls->LeakCounter = 0;

    SuperBlock* First = World->CurrSuper;
    SuperBlock* Super = First;
    do {
		AllocationBlock* Start = StartBlock_(Super);
		AllocationBlock* Finish = EndBlock_(Super);

		do {
			auto Owner = Start->Owner;
			int C = Start->ObjCount + Start->HiddenObjCount;
			if (Owner and Owner->Class)
				Owner->Class->LeakCounter += Mode == 1 ? C : -C;
			Start = JBShift(Start, 1 << World->BlockSize);
		} while (Start < Finish);
		Super = Super->Next;
    } while (Super != First);

	if (Mode == 1) {
		for (JB_Class* Cls = AllClasses; Cls; Cls = Cls->NextClass) {
			int C = Cls->LeakCounter;
			if (C)
				printf("Class: %s gained %i objects\n", Cls->Name, Cls->LeakCounter);
			Cls->LeakCounter = 0;
		}
	} else {
		printf("Classes collected\n");
	}
	Mode = Mode ^ 1;
}


static inline JB_Object* Trap_ (FreeObject* Obj) { // trap (  _trap(  trap_( 
//	if (JB_ObjectID((JB_Object*)Obj)==40981)
//		debugger;
	Obj->FakeRefCount = 0;
    return (JB_Object*)Obj;
}


__hot JB_Object* JB_AllocNew( AllocationBlock* CurrBlock ) {
	Sanity(CurrBlock);
    auto Obj = CurrBlock->FirstFree;
    if_usual (Obj) {
        CurrBlock->ObjCount++;
        CurrBlock->FirstFree = Obj->Next;
//        Obj->FakeRefCount = 0;
		Sanity(CurrBlock);
        return Trap_(Obj);
    }
	
	return Trap_(NewBlock( CurrBlock ));
}


JB_MemoryWorld* JB_MemStandardWorld() {
    return &MemoryManager;
}

JB_Class* JB_AllClasses() {
	return AllClasses;
}

void JB_MemFree(JB_MemoryWorld* World) {
    World->Shutdown = true;
    SuperBlock* First = World->CurrSuper;
    SuperBlock* Super = First;
    JB_Class* Cls = AllClasses; AllClasses = 0;
    while (Cls) {
        Cls = ResetClass_(Cls);
    }

    SuperBlock* Next = 0;
    while (Next != First and World->CurrSuper) {
        Next = Super->Next;
        JustGetRidOfIt_(Super, true);
        Super = Next;
    }
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////

JBObject_Behaviour Obj_FuncTable = {};
JBClassPlace5( JB_Object,		0,			"Object",		Obj_FuncTable );
JBClassPlace( JB_MemoryLayer,	JB_Object,	"MemoryLayer",	JB_Mem_Destructor,	0 );
/////////////////////////////////////////////////////////////////////////////////////////////////////////

}


// tasks and threads... add it when I need it...
// fireballs at da police's heads.


 
 
