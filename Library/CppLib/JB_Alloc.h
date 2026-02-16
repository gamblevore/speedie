
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __JB_ALLOC__
#define __JB_ALLOC__


#include <string.h>
#include <csignal>
#include "JB_BasicTypes.h"
#include "JB_MemUtils.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// LANGUAGE ADDITIONS
#define JBShift( exp, amount ) ( (__typeof__ ( exp )) ((byte*)(exp)+(amount)))

#define likely(x)				__builtin_expect(!!(x),1)
#define unlikely(x)				__builtin_expect(!!(x),0)

#define if_rare(x)				if (unlikely(x))
#define if_usual(x)				if (likely(x))

#define iif(x)					if (JB_Flow__Cond(x))
#define wwhile(x)				while (JB_Flow__Cond2(x)) 
#define JB_Ternary(cond,a,b)	((cond)?(a):(b))
#define JB_Ternaryy(cond,a,b)	(JB_Flow__Cond(cond)?(a):(b))

#define __hot					__attribute__((hot))

#define __visible				__attribute__((__visibility__("default")))

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" {

bool JB_Flow__Cond(bool b);
bool JB_Flow__Cond2(bool b);
bool JB_Plat__HasFlow();
void JB_Flow__PrintStats();



#define require(test)   if  (!(test)) {return {};}
#define require0(test)  if  (!(test)) {return;}
#define for_(count) for (int i = 0; i < (count); i++)
#define FOR_(var, count) for (int var = 0; var < (count); var++)


////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct JB_MemoryLayer;
struct JB_Class;
struct FreeObject;
struct AllocationBlock;
struct JB_Object;
struct DummyBlock;
struct JB_MemoryWorld;
struct SuperBlock;
struct JBObject_Behaviour;


////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define kObjMinSize				16 // safer.
#define JB_MArray(type, num)    ((type*)(JB_MArray_(sizeof(type),num)))
#define JB_NewClass(Cls)        (JB_Object*)(JB_AllocNew((Cls)->DefaultBlock))
#define JB_New(name)            (name*)(JB_AllocNew((name ## Data).DefaultBlock))
#define JB_New2(T)				{if (!self) self = JB_New(T);}
#define JB_NewEmpty(name)       (name*)(ClearFor_(JB_New(name), sizeof(name)))
#define JB_Zero(name)           (ClearFor_((void*)(name), sizeof(__typeof__(*name))))
#define JBStructData(a)         extern JB_Class a ## Data;
#define JBClass(a, b, c)        struct a : b {c}; JBStructData(a);
#define JB_AsClass(Name)        (&(Name ## Data))


#define JBClassPlace(Ty, Sup, Name, Des, Rend)									\
JBObject_Behaviour Ty##_FuncTable = {(void*)Des,(void*)Rend};					\
JB_Class Ty##Data = JBClassInit(Ty##Data, Name ,sizeof(Ty),JB_AsClass(Sup),(JBObject_Behaviour*)&(Ty##_FuncTable));

#define JBClassPlace5(Ty, Sup, Name, Beh)										\
JB_Class Ty##Data = JBClassInit(Ty##Data, Name, sizeof(Ty), Sup, (JBObject_Behaviour*)&(Beh));

////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef void (*fpDestructor)(JB_Object* self);
typedef void (*fpAllocator)(AllocationBlock* self);
////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct DummyBlock {
    JB_MemoryLayer*        		Owner;
    FreeObject*             	FirstFree;
};


#define JB_RefCountShift 1
struct JB_Object {
    u32 RefCount;
};


struct JB_RingList : JB_Object { // a list that does not own its items... unlike JB_List
	uint					Dummy;
    JB_RingList*			Next;
    JB_RingList*			Prev;
};


struct SuperBlock {
    uint                    ID;
    uint                    BlocksActive;
    SuperBlock*             Next;
    SuperBlock*             Prev;
    JB_MemoryWorld*         World;
    AllocationBlock*        FirstBlock;
    AllocationBlock*        StartBlock;
    FreeObject*             StartObj;
    void*                   BlockEnd;
};


struct AllocationBlock {
    u16                     ObjCount;
    u16                     HiddenObjCount;
    u16                     ObjSize;
    u16                     DebugMark; 
    AllocationBlock*        Next;
    AllocationBlock*        Prev;
    
    JB_MemoryLayer*         Owner;
    SuperBlock*             Super;

    FreeObject*             FirstFree;

    JBObject_Behaviour*     Virtuals;		// speed things up a bit.
};


struct JB_MemoryLayer : JB_Object  { // is actually a JBObject... but a clang bug won't let me use "JBClass(JB_MemoryLayer..."
    u16                 HiddenRefCount;
    bool                IsActive;
    bool                BoostMode;
    AllocationBlock*    CurrBlock;
    JB_Class*           Class;
    AllocationBlock*    SpareBlock;
    JB_MemoryWorld*     World;
    
    JB_Object*          Obj;
    JB_Object*          Obj2;
    AllocationBlock     Dummy;
}; 
JBStructData (JB_MemoryLayer);



struct JB_Class : JB_Object { // JB_ClassData
    u16                 Size;
    bool                HasSubclasses;  // for optimised isa testing
    uint8               ClassDepth;		// also
    JB_Class*           Parent;
    AllocationBlock*    DefaultBlock;
    JB_Class*           NextClass;
    int					LeakCounter;
    JB_MemoryLayer      Memory;
    const char*         Name;
    JBObject_Behaviour* Virtuals; 
    uint8*              SaveInfo;
};


struct JB_MemoryWorld {
    int                 CountRef;
    SuperBlock*         CurrSuper;
    SuperBlock*         SpareSuper;
    uint8*              Name;

    uint8               SuperSize;
    uint8               BlockSize;
    uint8               ShadowSize;
    uint8               Alignment;
    int                 SupersMade;
    bool				Shutdown;
    
    float               SpareTrigger; // number of objects free in a block after which the block becomes "spare"...
};


struct JBObject_Behaviour {
	const void* __destructor__;
	const void* render;
};
struct JBSaver_Behaviour {
	const void* __destructor__;
	const void* render;
	const void* Load;
	const void* SaveCollect;
	const void* SaveWrite;
};


bool		JB_Cake__Prepare (int N, int B);
JB_Class*	JB_Cake__Class (const char* Name, int Size, JB_Class* Parent, int VCount);
void**		JB_Cake_Virtuals(JB_Class* C);


void JBClassInitReal (JB_Class& Cls, const char* Name, int Size, JB_Class* Parent, JBObject_Behaviour* b);
inline JB_Class JBClassInit (JB_Class& Cls, const char* Name, int Size, JB_Class* Parent, JBObject_Behaviour* b) {
	JBClassInitReal(Cls, Name, Size, Parent, b);
	return Cls;
}

JBStructData(JB_Object);
struct Array;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

JB_MemoryWorld* JB_MemStandardWorld();
JB_MemoryLayer* JB_Mem__New( JB_Class* Cls );
JB_MemoryLayer* JB_Mem__NewObj(JB_Class* Cls, JB_Object* Obj);
void JB_Mem_Use( JB_MemoryLayer* self );
void JB_Mem_Unmark( );
void JB_Mem_Mark( );
void JB_Mem_OwnedSet(JB_MemoryLayer* Mem, bool b);
bool JB_ObjIsOwned(JB_Object* Obj);
JB_Class* JB_ObjClass(JB_Object* Obj);
int JB_RefCount(JB_Object* Obj);
uint8* JB_ObjClassBehaviours(JB_Object* Obj);
JB_Object* JB_Mem_First( JB_MemoryLayer* Mem );
JB_Object* JB_ObjNext(JB_Object* Obj);
JB_MemoryLayer* JB_ObjLayer( JB_Object* Obj );
uint JB_ObjectID( JB_Object* Obj );
JB_MemoryLayer* JB_Class_DefaultLayer( JB_Class* Cls );
JB_MemoryLayer* JB_Class_Layer( JB_Class* Cls );
JB_MemoryLayer* JB_Class_CurrLayer( JB_Class* Cls );
JB_Object* JB_Class_AllocZeroed( JB_Class* Cls );
int64 JB_Class_MemoryUsed( JB_Class* Cls );
void JB_Class_Add( JB_Class* Cls, const char* s );
JB_Class* JB_Class__First();
//JB_MemoryLayer* JB_Mem_CreateLayer(JB_Class* Cls, JB_Object* Obj);
void JB_Mem_InitAndUse(JB_MemoryLayer* Mem, JB_Class* Cls);
JB_MemoryLayer* JB_Mem_Constructor( JB_MemoryLayer* self, JB_Class* Cls, JB_Object* Obj );
void JB_Class_Init(JB_Class* Cls, JB_MemoryWorld* World, int Size);
void JB_Class_SetIndex(JB_Class* cls, int i);
int JB_Class_Index(JB_Class* cls);
void JB_DebugAllMemory(bool b);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

__hot JB_Object* JB_AllocNew( AllocationBlock* CurrBlock );
void JB_Delete( FreeObject* Obj );
void JB_FindLeakedObject(JB_Object* Obj, Array* R);
void JB_Mem_ClassLeakCounter ();
__hot void JB_ClusterDelete( FreeObject* Obj );
void JB_MemFree(JB_MemoryWorld* World);
JB_Class* JB_AllClasses();

////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef JB_DEBUG_ON
    void JB_Sanity(JB_Object* obj);
#else
    #define JB_Sanity( obj )
#endif
void JB_SanityCheck(AllocationBlock* Block);
typedef bool (*fpDebug)(void* Space, void* Result);
int JB_LeakTrace(u16 Flag);
typedef void (*fpListAllClasses)(JB_Class* M);
u64 JB_MemCount();
bool JB_IsDebug();
int JB_PointerSize();
void JB_MemList();
u32 JB_ObjCount();


////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define JB_Incr(Obj)			({ auto _tMp_ = Obj; JB_Incr_(_tMp_); (_tMp_);})
#define JB_Incr2(a,b)			JB_Incr2_((JB_Object**)(&a), (JB_Object*)(b))
#define JB_SafeDecr(Obj)		JB_SafeDecr_((JB_Object*)(Obj))
#define JB_SetRef(a,b)			JB_SetRef_((JB_Object**)(&a), (JB_Object*)(b))
#define JB_Clear(a)				JB_Clear_((JB_Object**)(&a))
#define JB_Swap(a,b)			({auto _T = b; b = a; a = _T;})
#define JB_EarlyDecr			JB_Decr


#if DEBUG
	inline void JBObjRefTest(JB_Object* obj) {
		auto r = obj->RefCount;
		if ((r&1) and (r >= 4))
			debugger;
	}
    #define JBTestSanityOK 1
#else
    #define JBObjRefTest(obj)
    #define JBTestSanityOK 0
#endif


bool JB_TotalSanity (bool Force);
bool JB_Obj_IsValid (JB_Object* Obj);


inline JB_Object* JB_Incr_(JB_Object* self) {
    if (self) {
//		JB_TotalSanity(true);
        self->RefCount += 1<<JB_RefCountShift;
		JBObjRefTest(self);
    }
    return self;
}


inline void JB_Decr(JB_Object* self) {
    if ( self ) {
//		JB_TotalSanity(true);
		int N = self->RefCount - (1<<JB_RefCountShift);  self->RefCount = N;
		JBObjRefTest(self);
        if (!N)
            JB_Delete( (FreeObject*)self );
    }
}


inline void JB_Clear_(JB_Object** Place) {
	JB_Object* self = *Place;
	*Place = nil;
	JB_Decr(self);
}

#define JB_DecrMulti(a, b)  (JB_DecrMulti_((JB_Object**)(a),b))
inline void JB_DecrMulti_(JB_Object** Start, int n) {
	JB_Object** End = Start+n;
	while (Start < End) {
		JB_Decr(*Start++);
	}
}

inline JB_Object* JB_SafeDecr_(JB_Object* self) {
    if (self) {
        self->RefCount -= 1<<JB_RefCountShift;
		JBObjRefTest(self);
    }
    return self;
}

inline JB_Object* JB_FreeIfDead(JB_Object* self) {
    if (self) {
		JBObjRefTest(self);
        if (self->RefCount  <  1<<JB_RefCountShift)
            JB_Delete( (FreeObject*)self );
    }
    return self;
}


inline void JB_SetRef_(JB_Object** Place, JB_Object* New) {
	JB_Incr(New);
    JB_Object* Old = *Place;
	*Place = New;
	JB_Decr(Old); // Decr MUST come last.
}

inline void JB_Incr2_(JB_Object** Place, JB_Object* New) {
	JB_Incr(New);
	*Place = New;
}


inline int JB_RefCount( JB_Object* obj ) {
    return obj->RefCount >> JB_RefCountShift;
}

  
inline void JB_SetRefCount(JB_Object* Obj, int C) {
	int RC = Obj->RefCount & ((1<<JB_RefCountShift)-1);
	Obj->RefCount = (C << JB_RefCountShift) | RC;
}


inline void* ClearFor_(void* Place, u32 Size) {
    memset(JBShift(Place,4), 0, Size - 4); // refcount should be 0. Don't hide bug if refcount > 0!
    return Place;
}

inline void JB_MarkRefCount(JB_Object* obj, bool On) {
	int R = obj->RefCount &~ 1;
	obj -> RefCount = R | On;
}


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // __JB_ALLOC__


