
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

// todo
// * Use JB_List for world/super/block!		 // makes code simpler!
// * Can just do block = JB_RT_Next2(block); // goes up and down if hits end
// 												easy way to list all blocks in the world!
// * Simpler to have only one world?


#include "JB_Alloc.h"
#include <setjmp.h>
#include <sys/mman.h>



#define kUltraAlloc (1ull<<35)
#define kBlockSize          13  // 8K!



extern "C" {

bool			DoTotalMemoryTest;
jmp_buf 		JB_MemFailJump;
byte			MemFailKeeper;
JB_MemoryWorld2*	CompressedManager;


inline void failed(const char* c) {
#if DEBUG
	printf("jbmem error: %s\n", c);
#endif
	debugger;
}

struct JB_FreeObject {
	union { // ughweneedit
		int         FakeRefCount; // 
		JB_FreeObject* Next;
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


void JB_Layer_Destructor( JB_MemoryLayer* self );


////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

static bool IsDummy( const AllocationBlock* Block ) {
    AllocationBlock* OwnersDummy = (AllocationBlock*)(&Block->Owner->Dummy);
    return OwnersDummy == Block;
}
static fpDestructor GetDestructor_(AllocationBlock* B) {
	return (fpDestructor)(B->Virtuals->__destructor__);
}
static inline AllocationBlock* EndBlock_(SuperBlock* Block) {
	if (auto H = (AllocationBlock*)Block->HeadBlock; H)
		return H;
	return (AllocationBlock*)Block->BlockEnd;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////



static JBObject_Behaviour DummyFuncTable = {};
static JB_Class* AllClasses;
static int DM = 0;


static bool MiniCompare (const char* s, const char* find) {
	while (auto c = *find++)
		if (*s++ != c)
			return false;
	return true;
}

void JB_ClassInitReal (JB_Class& Cls, const char* Name, int Size, JB_Class* Parent, JBObject_Behaviour* Table) {
	Cls.RefCount = 1024;
	if (MiniCompare(Name, "JB_"))
		Name += 3;
    Cls.Name = Name;
    Cls.Parent = Parent;
    
    if (!Table) //
		Table = &DummyFuncTable;
	if (!Table->__destructor__)
		Table->__destructor__ = (const void*)JB_Obj_Destructor;
	
    Cls.Virtuals = Table;
    Cls.DefaultBlock = (AllocationBlock*)(&Cls.Memory.Dummy);
    Cls.Memory.RefCount = 1024;
    Cls.Memory.Class = &Cls;
    Cls.Memory.Dummy.Owner = &Cls.Memory;
    Cls.Memory.CurrBlock = (AllocationBlock*)(&Cls.Memory.Dummy);
    Cls.Memory.IsActive = true;
    if (Size < sizeof(JB_FreeObject)) Size = sizeof(JB_FreeObject); 
    Cls.Size = Size;
    
    if (Parent) {
        Parent->HasSubClasses = true;
		Cls.ClassDepth = Parent->ClassDepth + 1; 
    }
    
    Cls.NextClass = AllClasses;
    AllClasses = &Cls;
}


MemStats JB_MemoryStats (JB_MemoryWorld* World, bool CountObjs, u16 Mark) {
    SuperBlock* First = World->CurrSuper;			// issue?
    SuperBlock* Super = First;						// issue?
    if (!Super)
		return {};
    MemStats Result = {};
    
//	u16 ActualMark = Mark &~ 0xf000;
//	bool IsCheck   = Mark & 0xf000;
    do {
        Result.Blocks += (Super->BlocksActive);
        
        if (CountObjs) {
            AllocationBlock* Start = Super->SpaceBegin;
            AllocationBlock* Finish = EndBlock_(Super);

            do {
                int C = Start->ObjCount + Start->HiddenObjCount;
                Result.Objs += C;
                Start = JB_Shift(Start, 1 << kBlockSize);
            } while (Start < Finish);
        }

        Super = Super->Next;
    } while (Super != First);
	
    return Result;
}


inline AllocationBlock* ObjBlock_ (void* Obj) {
    IntPtr Addr = (IntPtr)Obj | ((1<<kBlockSize)-1);
    Addr = Addr &~ (sizeof(AllocationBlock)-1);
    return (AllocationBlock*)Addr;
}


char* BlockStart_ (AllocationBlock* B) {
	return (char*)(((IntPtr)B) &~ ((1<<kBlockSize)-1));
}


void BlockIsFreeMark (JB_Object* self) {};

u64 JB_MemCount () {
    JB_MemoryWorld* World = JB_MemStandardWorld();
    return (u64)( JB_MemoryStats(World, false, 0).Blocks ) << kBlockSize;
}

JBObject_Behaviour BlockIsFreeTable = {(void*)BlockIsFreeMark, 0};

#if !JBTestSanityOK
	#define TestMemory_(x)
	#define SanityOfInUse(a)
	#define SanityOfFree(a)
	static void Sanity(AllocationBlock* B, bool HasBeenSetup = true) {}
	#define ObjInBlock(a,b)
#else
	JB_FreeObject* ObjInBlock (JB_FreeObject* Obj, AllocationBlock* B) {
		char* S = BlockStart_(B);
		char* ObjEnd = ((char*)Obj) + B->ObjSize;
		if ((char*)Obj < S  or  ObjEnd > (char*)B) {
			if (Obj==B->FirstFree) {
				failed("corrupt block first free");
			} else {
				failed("corrupt freeobj next chain");
			}
		}
		if (((IntPtr)(Obj->Next)) & 3)
			failed("corrupt freeobj next ptr");
		return Obj->Next;
	}
	
	void AllocBlock_Debug (AllocationBlock* B) {
		JB_FreeObject* Obj = B->FirstFree;
		while (Obj) {
			Obj = ObjInBlock(Obj, B);
		};
	}

	static bool BlockIsFree_ (AllocationBlock* B) {
		return (GetDestructor_(B) == BlockIsFreeMark);
	}


	void TestMemory_ (AllocationBlock* B) {
		if (!B or IsDummy(B))
			return;

		if (!B->Virtuals)
			failed("v");
		AllocationBlock* N = B->NextBlock;
		AllocationBlock* P = B->PrevBlock;
		if (N) {
			if (IsDummy(N))
				failed("isdummy");
			if (BlockIsFree_(N) != BlockIsFree_(B))
				failed("freeblock");
		}
		if (P) {
			if (IsDummy(P))
				failed("isdummy2");
			if (BlockIsFree_(P) != BlockIsFree_(B))
				failed("freeblock2");
		}
		
		AllocBlock_Debug(B);
		
		
		if (auto W = B->Owner; W) {
			auto Cls = W->Class;
			if (Cls and Cls->DefaultBlock == B) {
				return;
			}
		}
		
		
		JB_FreeObject* O = B->FirstFree;
		if (!O) return;
		auto Curr = B->Super;
		if (O < Curr->StartObj)
			return failed("startobj");
		if (O >= Curr->BlockEnd)
			return failed("blockend");

		int i = 0;
		while (O) {
			O = O->Next; // check for memory corruption
			i++;
			if (i >= (1<<kBlockSize)>>2)
				return failed("corrupt1");
		}
	}

	static bool IsBadFree_ (AllocationBlock* Curr) {
		if (Curr->PrevBlock) {
			failed("corrupt2");
			return true;
		}
		AllocationBlock* N = Curr->NextBlock;
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


	static int CanFollow2_ ( AllocationBlock* First, bool Forward ) { 
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
				Curr = Curr->NextBlock;
			} else {
				Curr = Curr->PrevBlock;
			}
			if (!Curr) {
				failed("corrupt6");
				return -2;
			}
			if (Count > 10000) {
				failed("corrupt7");
				return -3;
			}
		} while (Curr != First);
		return Count;
	}


	static bool IsBadInUse_ (AllocationBlock* Curr) {
		TestMemory_(Curr);
		int A = CanFollow2_(Curr, true);
		int B = CanFollow2_(Curr, false);
		if (A != B) {
			failed("corrupt8");
		}
		return false;
	}


	static void SanityOfInUse (SuperBlock* Sup) {
		AllocationBlock* Curr = Sup->SpaceBegin;
		AllocationBlock* Finish = EndBlock_(Sup);
		while (Curr < Finish) {
			if (GetDestructor_(Curr) != BlockIsFreeMark) {
				IsBadInUse_(Curr);
			} else {
				TestMemory_(Curr);
			}
			Curr = JB_Shift( Curr, 1 << kBlockSize );
		}
	}


	static void SanityOfFree (SuperBlock* Sup) {
		AllocationBlock* F = Sup->AvailableBlock;
		AllocationBlock* Curr = F;
		while (Curr) {
			if (GetDestructor_(Curr) != BlockIsFreeMark) {
				failed("corrupt9");
			}
			IsBadFree_(Curr);
			Curr = Curr->NextBlock;
		}
	}


	static void Sanity (AllocationBlock* B, bool HasBeenSetup = true) {
		if (B) {
			if (HasBeenSetup and !IsDummy(B) and !B->DebugMark)
				0; // debugger; // /????? // why is this happening?
			TestMemory_(B);
		}
	}
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////

JB_MemoryLayer* JB_Layer_Constructor ( JB_MemoryLayer* self, JB_Class* Cls, JB_Object* Obj ) {
	JB_New2(JB_MemoryLayer);
    JB_Zero(self);
    self->Class = Cls;
    self->CurrBlock = (AllocationBlock*)&(self->Dummy);
    self->Dummy.Owner = self;
    JB_SetRef(self->Obj, Obj);
    return self;
}


void JB_Layer_Use ( JB_MemoryLayer* Layer ) {
    // shouldn't we incr the layer? or not?
    if (Layer->IsActive) { // save time...
        return;
    }
    JB_Class* Cls = Layer->Class;
    AllocationBlock* ClsBlock = Cls->DefaultBlock;
    ClsBlock->Owner->IsActive = false;
    Cls->DefaultBlock = Layer->CurrBlock; // swap first...
    Layer->IsActive = true;
    /// we are putting into the class, but why compare something to self and why incr or decr?
	// I guess we don't want the memorylayer to disapear while being used... thats all? 
	// but we didn't replace the owner... so whats to stop it being decrd multiple times?
    if (ClsBlock->Owner != Layer) {
        JB_Incr_((JB_Object*)Layer);
        JB_Decr(ClsBlock->Owner);
    }
    TestMemory_(Cls->DefaultBlock);
}


void JB_Mem_Unmark ( ) {
	JB_MemoryStats(JB_MemStandardWorld(), true, 1234|0xf000);
	JB_MemoryStats(JB_MemStandardWorld(), true, 0);
}


void JB_Mem_Mark ( ) {
	JB_MemoryStats(JB_MemStandardWorld(), true, 1234);
}


void JB_Layer_Destructor ( JB_MemoryLayer* self ) {
    if (auto S = self->SpareBlock; S)
        S->Owner = 0;
    if (auto B = self->CurrBlock; !IsDummy(B))
        B->Owner = 0;
    
    JB_SetRef( self->Obj, 0 );
    JB_SetRef( self->Obj2, 0 );
    JB_Obj_Destructor(self);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////


///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   



void JB_Helper_PutBefore (JB_RingList* Self, JB_RingList* Before) {
	JB_RingList* P = Self->Prev;
	Self->Prev = Before;
	P->Next = Before;
	Before->Prev = P;
	Before->Next = Self;
}



void JB_Helper_Unlink (JB_RingList* Curr) {
    JB_RingList* N = Curr->Next;
    JB_RingList* P = Curr->Prev;
    N->Prev = P;
    P->Next = N;
    Curr->Next = Curr;
    Curr->Prev = Curr;
}



  ///////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////

JB_MemoryLayer* JB_Class_Layer ( JB_Class* Cls ) {
    return Cls->DefaultBlock->Owner;
}

JB_MemoryLayer* JB_Class_CurrLayer ( JB_Class* Cls ) {
    return JB_Class_Layer(Cls);
}


JB_MemoryLayer* JB_Class_DefaultLayer ( JB_Class* Cls ) {
    return &Cls->Memory;
}


JB_MemoryLayer* JB_Obj_Layer ( JB_Object* Obj ) {
    if (Obj) {
        AllocationBlock* Block = ObjBlock_(Obj);
        return Block->Owner;
    }
    return 0;
}


uint JB_Obj_ID ( JB_Object* Obj ) {
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


JB_Class* JB_Obj_Class (JB_Object* Obj) {
	auto L = ObjBlock_(Obj);
	return L->Owner->Class;
}

  

void** JB_Obj_ClassBehaviours (JB_Object* Obj) {
    auto Block = ObjBlock_(Obj);
    return (void**)(Block->Virtuals);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////



static void SetCurrBlock_ ( JB_MemoryLayer* Mem, AllocationBlock* NewBlock ) {
Sanity(NewBlock);
    JB_Class* Cls = Mem->Class;
    if (Cls and (Cls->DefaultBlock == Mem->CurrBlock)) {
        // class is using this JB_MemoryLayer...
        Cls->DefaultBlock = NewBlock;
        TestMemory_(NewBlock); // sigh... test memory
    }
    
    Mem->CurrBlock = NewBlock;
}


bool JB_DebugAllMemory (bool b)  {
	bool old = DoTotalMemoryTest;
	DoTotalMemoryTest = b;
	return old;
}


void JB_MemoryAccessError (int sig) {
	longjmp(JB_MemFailJump, sig|128);
}



static int TestMemory (volatile byte* B, int N, int Mode) {
	int C = 0;

	for (int i = 0; i < N; i++)
		C ^= B[i];

	if (Mode & 2) {
		for (int i = 0; i < N; i++)
			B[i] ^= Mode;
		for (int i = 0; i < N; i++)
			B[i] ^= Mode;		// restore
	}
	
	MemFailKeeper = C;			// stop optimiser
	return 0;
}


static bool SuperIsValid (SuperBlock* B) {
	auto F = JB_MemStandardWorld()->CurrSuper;
	auto C = F;
	while (C) {
		if (C == B)
			return true;
		C = C->Next;
		if (C == F)
			break;
	}
	return false;
}


static int ObjIsValid (JB_Object* Obj) {
	auto Block = ObjBlock_(Obj);
	if (!SuperIsValid(Block->Super))
		return 1000;
	
	int Count = Block->ObjCount + Block->HiddenObjCount;
	if (Count <= 0)
		return 1010;

	if (!Block->NextBlock or !Block->PrevBlock)
		return 1020;

	auto Class = Block->Owner->Class;
	if (!Class)
		return 1030;
	auto Name = Class->Name;
	if (!Name)
		return 1035;
	
	auto NameLen = strnlen(Name, 72);
	if (NameLen >= 72 or NameLen <= 0)
		return 1037;
	
	int Size = Block->ObjSize;
	if (Size < 4 or Size >= 4096)
		return 1040; // obj size invalid

	int TotalSize = Size*Count;
	const int AllowedTotal = (int)((1<<kBlockSize)-sizeof(AllocationBlock));
	if (TotalSize > AllowedTotal)
		return 1050; // block itself is invalid
	
	if (Size > AllowedTotal)
		return 1060;

	return TestMemory((byte*)Obj, Size, 0);
}


int JB_TestMemory (void* B, int N, int Mode) {
	if (!B or !N) return -1;

	auto OldSeg = signal(SIGSEGV, JB_MemoryAccessError);
	auto OldBus = signal(SIGBUS, JB_MemoryAccessError);
	int Err = setjmp(JB_MemFailJump);
	if (!Err)
		Err =  (N < 0)  ?  ObjIsValid((JB_Object*)B)  :  TestMemory((byte*)B, N, Mode);
	signal(SIGSEGV, OldSeg);
	signal(SIGBUS, OldBus);
	return Err;
}


bool JB_TotalSanity (bool Force) {
	if (!Force and !DoTotalMemoryTest)
		return true;
	auto cls = AllClasses;
	while (cls) {
		TestMemory_(cls->DefaultBlock);
		cls = cls->NextClass;
	}
	SuperBlock* Sup0 = JB_MemStandardWorld()->CurrSuper;
	SuperBlock* Curr = Sup0;
	if (!Curr) {
		return true;
	}

	do {
		SanityOfInUse(Curr);
		SanityOfFree(Curr);
		Curr = Curr->Next;
	} while (Curr and Curr != Sup0);
	return true;
}


static JB_FreeObject* LinkIn_ (JB_MemoryLayer* Mem, AllocationBlock* NewBlock) {
	Sanity(NewBlock);
	
// Call this when returning the first item from a newly allocated block.
    SetCurrBlock_( Mem, NewBlock );
    Mem->RefCount+=1<<JB_RefCountShift;
    JB_FreeObject* First = NewBlock->FirstFree;
    NewBlock->FirstFree = First->Next;
    NewBlock->ObjCount++;
	Sanity(NewBlock);
	
    return First;
}


static void SetupSuperSub_ (SuperBlock* Super, AllocationBlock* Curr) {
	Curr->Super = Super;
	Curr->Virtuals = &BlockIsFreeTable;
	Curr->Owner = 0; // for clearing
	Curr->NextBlock = 0;
}


static void InitObjectsInBlock_ (JB_MemoryLayer* Mem, AllocationBlock* NewBlock, JB_MemoryWorld* W, int Size) {
	NewBlock->ObjSize = Size;
    auto oof = NewBlock->Owner;
    int BS = kBlockSize;
    int BlockBits = (1 << BS) - 1;
    JB_FreeObject* Curr = (JB_FreeObject*)(((IntPtr)NewBlock) &~ BlockBits);
    NewBlock->FirstFree = Curr; // for LinkIn_
//	if (Mem->BoostMode) {
//		return;
//	}

    JB_FreeObject* TrueFirst = NewBlock->Super->StartObj;
    if (Curr < TrueFirst) {
        Curr = TrueFirst;
    }
    
    JB_FreeObject* End =  (JB_FreeObject*)NewBlock;
    dbgexpect(Curr < End);
    
    NewBlock->FirstFree = Curr; // for LinkIn_
	
	JB_FreeObject* NextStart = JB_Shift(Curr, Size);
    while (Curr) {
		JB_FreeObject* NextEnd = JB_Shift(NextStart, Size);
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


static int FindClassDepth (JB_Class* C) { 
	int n = 1;
	while (C) {
		C = C->Parent;
		n++;
	}
	return n;
}


static JB_MemoryWorld2* CollectClassDepths (JB_MemoryWorld2* World) {
	auto C = AllClasses;
	World->AllClasses = C;
	while (C) {
		C->ClassDepth = FindClassDepth(C);
		C = C->NextClass;
	}
	return World;
}

static JB_FreeObject* BlockSetup_ ( JB_MemoryLayer* Mem, AllocationBlock* NewBlock, JB_MemoryWorld* World ) {
    if (!NewBlock)
        return 0;

	NewBlock->DebugMark = ++DM;
    Sanity(NewBlock);
    JB_Class* Class = Mem->Class;
    NewBlock->Virtuals = Class->Virtuals; // faster vfuncs
    NewBlock->Owner = Mem;

	int Size = Class->Size;
	if (Size&4) {
		debugger; // shouldn't it be 8?
	}
    if (NewBlock->ObjSize != Size)
		InitObjectsInBlock_( Mem, NewBlock, World, Size );
	
    NewBlock->PrevBlock = NewBlock;
    NewBlock->NextBlock = NewBlock;
    
    return LinkIn_(Mem, NewBlock);
}




void JB_Date__Sleep (Date Durr);

static JB_UltraMap* JB_UM_Alloc (uint64 Request) {
// I could allocate 32-GB of memory for pointer-compression
// remove supers + memoryworld

	for (int i = 0; i < 40; i++) {		// try for 10s. I've seen it fail sometimes, strangely.
		int Flags = MAP_PRIVATE | MAP_ANONYMOUS;
		#ifdef MAP_HUGETLB
			Flags |= MAP_HUGETLB;
		#endif
		auto Map = (JB_UltraMap*)mmap(0, Request, PROT_READ | PROT_WRITE, Flags, -1, 0);

		if (Map != MAP_FAILED) {
			Map->Allocated = Request;
			return Map;
		}
		JB_Date__Sleep(1<<14);			// 0.25s
	}
	JB_OutOfMainMemory(Request);
	return 0; // oof;
}

void JB_UM_Free (JB_UltraMap* self) {
	if (self) {
		munmap(self, self->Allocated);
	}
}

JB_MemoryWorld2* JB_Mem_WorldStart (void* self) {
	uint64 P = (uint64)self;
	P &= ~(kUltraAlloc-1);
	return (JB_MemoryWorld2*)P;
}


static JB_MemoryWorld2* PointerCompressionAlloc () {
// this can help with pointer compression!!
	auto Got = (JB_MemoryWorld2*)JB_UM_Alloc(kUltraAlloc); // 32GB.
	if (!((uint64)Got&(kUltraAlloc-1)))
		return Got;
	JB_UM_Free(Got);
	Got = (JB_MemoryWorld2*)JB_UM_Alloc(kUltraAlloc<<1); // oof
	if (Got)
		Got = (JB_MemoryWorld2*)((((uint64)Got) + kUltraAlloc)&~(kUltraAlloc-1));
	return Got;
}


JB_MemoryWorld2* JB_LibInit() {
	auto Mem = CompressedManager;
	if (Mem)
		return Mem;
	Mem = PointerCompressionAlloc();
	if (Mem) {
		Mem->RefCount = 1;
		int OneMB = 1<<20;
		Mem->NextSuper = (SuperBlock*)((((uint64)Mem) + OneMB) &~ (OneMB-1));
		CompressedManager = Mem;
		return CollectClassDepths(Mem);
	}
	return Mem;
}



static AllocationBlock* NewSuperBlock_ (JB_MemoryLayer* Mem, JB_MemoryWorld* World) {
    // we should move the superblock down
    // eventually we want to remove it anyhow.
	auto Ultra = JB_Mem_WorldStart(World);
	SuperBlock* Super = Ultra->NextSuper;
    Super->ID = World->SupersMade++;
	Ultra->NextSuper = JB_Shift(Super, 1<<20);
	Super->BlockEnd = Ultra->NextSuper;

    JB_FreeObject* FirstWriteable = (JB_FreeObject*)JB_Shift(Super, sizeof(SuperBlock));
    
    Super->StartObj = FirstWriteable;
    AllocationBlock* Curr = ObjBlock_(Super);
    Super->SpaceBegin = Curr;
    Super->HeadBlock = JB_Shift(Curr, 1 << kBlockSize);
    Super->AvailableBlock = 0;
	SetupSuperSub_(Super, Curr);

	if (World->CurrSuper) {
		JB_Helper_PutBefore((JB_RingList*)(World->CurrSuper), (JB_RingList*)Super);
    } else {
		Super->Prev = Super;
		Super->Next = Super;
    }

	Super->World = World;
	Super->BlocksActive++;
	World->CurrSuper = Super; // issue?
	World->CountRef++;
Sanity(Curr, false);
    return Curr;
}


static AllocationBlock* FindAllocBlock_ (JB_MemoryWorld* World) {
    SuperBlock* First = World->CurrSuper;
    if (!First) {
        return 0;
    }
    SuperBlock* Sup = First;
    
    do {
        AllocationBlock* Item = Sup->AvailableBlock;
        if (!Item) {
			Item = Sup->HeadBlock;
			if (Item) {
				SetupSuperSub_(Sup, Item);
				auto H = JB_Shift(Item,1<<kBlockSize);
				if (H >= Sup->BlockEnd)
					H = 0;
				Sup->HeadBlock = H;
			}
        }
        if (Item) {
            Sanity(Item, false);
            if (Sup == World->SpareSuper) {
                World->SpareSuper = 0;
            }
            World->CurrSuper = Sup;
            Sup->BlocksActive++;
            Sup->AvailableBlock = Item->NextBlock;
            Item->NextBlock = 0;
            return Item;
        }
        
        Sup = Sup->Next;
    } while (First != Sup);

    return 0;
}


static AllocationBlock* ReturnSpareHidden_ (AllocationBlock* CurrBlock) {
    AllocationBlock* NextBlock = CurrBlock->NextBlock;
    if (NextBlock != CurrBlock) {
    // Use next... Can't remember why i did this. Must have been a pretty good reason.
    // Perhaps... To save memory? I'm not exactly sure what is linked where and why, though.
    // The Next/Prev links seem only well-defined for free-blocks. And yet this works
    // so it must be partially defined at least?
	
        JB_Helper_Unlink((JB_RingList*)CurrBlock);
        return NextBlock;
    }
    return 0;
}


static AllocationBlock* ReturnSpare_ (JB_MemoryLayer* Mem) {
// Allocate a "NewBlock" by just re-using the spareblock as the currentblock...
    
    if (auto NewBlock = ReturnSpareHidden_( Mem->CurrBlock ); NewBlock) {
        return NewBlock;
    }

    AllocationBlock* NewBlock = Mem->SpareBlock;
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


static u16 HiddenRef_ (int Size) {
    int N = (1<<kBlockSize) - sizeof(AllocationBlock);
    int N2 = (N * 3)/4;
    return N2 / Size;
}


static JB_FreeObject* NewBlock ( AllocationBlock* CurrBlock ) {
    JB_MemoryLayer* Mem = CurrBlock->Owner;
    JB_MemoryWorld* World = JB_MemStandardWorld();
    if (!IsDummy(CurrBlock)) {
        u16 Hidden = Mem->HiddenRefCount;       // trigger re-use of this block before it hits empty.
        if (!Hidden) {
            Hidden = HiddenRef_(Mem->Class->Size);
            Mem->HiddenRefCount = Hidden;
        }
        CurrBlock->HiddenObjCount = Hidden;
        CurrBlock->ObjCount -= Hidden;

        if (AllocationBlock* Spare = ReturnSpare_( Mem ); Spare)
            return LinkIn_(Mem, Spare);
    }

    AllocationBlock* Result = FindAllocBlock_( World );
    if (!Result)
        Result = NewSuperBlock_( Mem, World );
    return BlockSetup_( Mem, Result, World );
}



static JB_Class* ResetClass_ ( JB_Class* Cls ) {
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


static void PossiblyLast_ (SuperBlock* Super) {
    JB_MemoryWorld* World = Super->World;
    if (World->CurrSuper == Super) {  // issue?
        SuperBlock* Next = Super->Next;
        if (Next == Super) {
            Next = 0;
        }
        World->CurrSuper = Next; // issue?
    }
}


static void JustGetRidOfIt_ (SuperBlock* Super) {
	auto World = JB_Mem_WorldStart(Super); 
	if (JB_Shift(World->NextSuper, -(1<<20)) != Super)
		return; // don't get rid of it :]
	
	World->NextSuper = Super;
    PossiblyLast_(Super);
    JB_Helper_Unlink( (JB_RingList*)Super );
    Super->World->CountRef--;

    AllocationBlock* Curr = Super->SpaceBegin;
    AllocationBlock* End = EndBlock_(Super);

    while (Curr < End) {	// not too sure this test is correct!
        JB_MemoryLayer* Mem = Curr->Owner;
        if ( Mem )			// Only exists if its a spare, seeing as the superblock's refcount is 0.
            Mem->SpareBlock = 0;
        Curr = JB_Shift(Curr, 1 << kBlockSize);
    }
}



static void SuperBlockFree_ (SuperBlock* Super) {
    JB_MemoryWorld* World = Super->World;
    if ( World->SpareSuper ) {
        JustGetRidOfIt_(Super);

    } else if ( Super->Next != Super ) { // is alone
        World->SpareSuper = Super; // issue?
    }
}


static void BlockFree_ ( AllocationBlock* FreeBlock ) {
    Sanity(FreeBlock);
    JB_MemoryLayer* Mem = FreeBlock->Owner;
    SuperBlock* Super = FreeBlock->Super;
    
    if (Mem->CurrBlock == FreeBlock) {
        AllocationBlock* NewCurr = ReturnSpareHidden_(FreeBlock);
        if (!NewCurr)
            NewCurr = (AllocationBlock*)&(Mem->Dummy);
        SetCurrBlock_(Mem, NewCurr);
    }
    JB_Helper_Unlink((JB_RingList*)FreeBlock);

    if (!Mem->SpareBlock) {
        Mem->SpareBlock = FreeBlock;
		if (JB_RefCount(Mem) == 1)
			FreeBlock->Owner = 0; // oof
		
    } else {
        // return block to superblock

        FreeBlock->PrevBlock = 0;
        FreeBlock->Virtuals = &BlockIsFreeTable;
        FreeBlock->NextBlock = Super->AvailableBlock;
        Super->AvailableBlock = FreeBlock;
        Sanity(FreeBlock->NextBlock, false); // this might not even be a real block?
		FreeBlock->Owner = 0; // oof
    }

    JB_Decr(Mem); // i hope this works...
    
    int N = --(Super->BlocksActive);
    if (!N) {
        SuperBlockFree_(Super);
    }
}


void JB_DeleteSub_ ( JB_FreeObject* Obj, AllocationBlock* Block ) {
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
// overwriting the memory we have decremented.
// that is... if we are deleting an object-tree... we don't actually need a function stack


// Another opt could be optimised decrementing. 
// Each class gets a 64-bit number, storing all the po itions to destroy objects at.
// could store the delete-info in the behaviour table or the allocationblock... either is ok.
//Put off for now.


#if __VM__
struct CakeVM {
    int				Dummy;
    int				Dummy2;
    void**			Dummy3;
    ivec4*			ProposedStack;
};

	extern CakeVM*	JB_GlobalVM;
	ivec4* JB_ASM_CallBack	 (CakeVM* V, u32* Code);
#endif


__boiling fpDestructor JB_Destructor (JB_Object* Obj) {
	return GetDestructor_(ObjBlock_(Obj));
}



__boiling void JB_Delete ( JB_FreeObject* Obj ) {
	AllocationBlock* Block = ObjBlock_(Obj);

	#if DEBUG
	int N = Block->ObjSize - 12;
	#endif

	Sanity(Block);
	fpDestructor Destructor = GetDestructor_(Block);

	#if __VM__
	if (((uint64)Destructor) >> 63) {			// VM based destructor
		auto V = JB_GlobalVM;
		((JB_FreeObject**)((V->ProposedStack)+2))[0] = Obj;
		JB_ASM_CallBack(V, (u32*)Destructor);
	} else
	#endif
	{(Destructor)((JB_Object*)Obj);}
	
	
	#if DEBUG
	if (N > 0) {
		byte* Bob = 12 + ((byte*)Obj);
		memset(Bob, 0xfe, N);
	}
	#endif
}


void JB_Obj_Destructor (JB_Object* Obj) {
	JB_DeleteSub_((JB_FreeObject*)Obj, ObjBlock_(Obj));
}


static void BlockFindLeakedObject_ (AllocationBlock* Block, JB_Object* Obj, Array* R) {
	if (IsDummy(Block)) { // how???
		debugger;
		return;
	}
	int N = Block->ObjSize; if (N <= 0) return;
	JB_Object* S = (JB_Object*)BlockStart_(Block);
	while (S < (void*)Block) {
		JB_Object** Prop	= JB_Shift((JB_Object**)S, 4); // allow unaligned?
		JB_Object** PropEnd = JB_Shift((JB_Object**)S, N);
		if (JB_RefCount(S) < 1000) {
			while (Prop < PropEnd) {
				if (*Prop == Obj) {
					void JB_Array_Append(Array* R, JB_Object* Obj);
					JB_Array_Append(R, S);
					break;
				}
				Prop = JB_Shift((JB_Object**)Prop, 4);
			}
		}
		S = (JB_Object*)PropEnd;
	}
}


static void SuperFindLeakedObject_ (SuperBlock* Super, JB_Object* Obj,  Array* R) {
	AllocationBlock* Start = Super->SpaceBegin;
	AllocationBlock* Finish = EndBlock_(Super);
	do {
		if (Start->Owner)
			BlockFindLeakedObject_(Start, Obj, R);
		Start = JB_Shift(Start, 1 << kBlockSize);
	} while (Start < Finish);
}


void JB_FindLeakedObject (JB_Object* Obj, Array* R) {
    SuperBlock* First = JB_MemStandardWorld()->CurrSuper;
    SuperBlock* Super = First;
    while (Super) {
        SuperFindLeakedObject_(Super, Obj, R);
        Super = Super->Next;
        if (Super == First) break;
    };
}


int64 JB_Class_MemoryUsed (JB_Class* Cls) {
	JB_MemoryWorld* World = JB_MemStandardWorld();
	uint C = 0;

    SuperBlock* First = World->CurrSuper;
    SuperBlock* Super = First;
    do {
		AllocationBlock* Start = Super->SpaceBegin;
		AllocationBlock* Finish = EndBlock_(Super);

		do {
			auto Owner = Start->Owner;
			C += (Owner and Owner->Class == Cls);
			Start = JB_Shift(Start, 1 << kBlockSize);
		} while (Start < Finish);
		Super = Super->Next;
    } while (Super != First);
    return ((int64)C) << kBlockSize;
}


void JB_Mem_ClassLeakCounter () {
	JB_MemoryWorld* World = JB_MemStandardWorld();
	static int Mode;
	if (Mode == 0)
		for (JB_Class* Cls = AllClasses; Cls; Cls = Cls->NextClass)
			Cls->LeakCounter = 0;

    SuperBlock* First = World->CurrSuper;
    SuperBlock* Super = First;
    do {
		AllocationBlock* Start = Super->SpaceBegin;
		AllocationBlock* Finish = EndBlock_(Super);

		do {
			auto Owner = Start->Owner;
			int C = Start->ObjCount + Start->HiddenObjCount;
			if (Owner and Owner->Class)
				Owner->Class->LeakCounter += Mode == 1 ? C : -C;
			Start = JB_Shift(Start, 1 << kBlockSize);
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


static inline JB_Object* Trap_ (JB_FreeObject* Obj) { // trap (  _trap(  trap_( 
//	if (JB_Obj_ID((JB_Object*)Obj)==31545429)
//		debugger;
	Obj->FakeRefCount = 0;
    return (JB_Object*)Obj;
}


__hot JB_Object* JB_AllocNew ( AllocationBlock* CurrBlock ) {
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


JB_MemoryWorld* JB_MemStandardWorld () {
    return &(CompressedManager->World);
}

JB_Class* JB_AllClasses () {
	return AllClasses;
}

bool JB_LibShutdown (bool Shutdown) {
	auto Mem = CompressedManager;
	if (!Mem) return false; // not even started up yet
	JB_MemoryWorld* World = &Mem->World;
	if (!Shutdown)
		return !Mem->RefCount;
    Mem->RefCount = 0;
    SuperBlock* First = World->CurrSuper;
    JB_Class* Cls = AllClasses; AllClasses = 0;
    while (Cls) {
        Cls = ResetClass_(Cls);
    }

    JB_UM_Free(Mem);
    return true;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

JBObject_Behaviour Obj_FuncTable = {(const void*)JB_Obj_Destructor};
JBClassPlace5( JB_Object,		0,			"Object",		Obj_FuncTable );
JBClassPlace( JB_MemoryLayer,	JB_Object,	"MemoryLayer",	JB_Layer_Destructor,	0 );
/////////////////////////////////////////////////////////////////////////////////////////////////////////

}


// tasks and threads... add it when I need it...
// fireballs at da police's heads.


 
 
