
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
#define JB_Shift(exp, amount)		((__typeof__(exp)) ((byte*)(exp)+(amount)))

#define likely(x)					__builtin_expect(!!(x),1)
#define unlikely(x)					__builtin_expect(!!(x),0)

#define if_rare(x)					if (unlikely(x))
#define if_usual(x)					if (likely(x))

#define JB_Ternary(cond,a,b)		((cond)?(a):(b))

#define __hot						__attribute__((hot))
#define __visible					__attribute__((__visibility__("default")))
#if __APPLE__
	#define __jb_restrict			__restrict
#else
	#define __jb_restrict
#endif
#define __boiling					__jb_restrict __attribute__((hot))

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" {

bool JB_Flow__Cond(bool b);
bool JB_Flow__Cond2(bool b);
bool JB_Plat__HasFlow();
void JB_Flow__PrintStats();



#define require(test)   			if  (!(test)) {return {};}
#define require0(test)  			if  (!(test)) {return;}
#define for_(count)					for (int i = 0; i < (count); i++)
#define FOR_(var, count)			for (int var = 0; var < (count); var++)


////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct JB_MemoryLayer;
struct JB_Class;
struct JB_FreeObject;
struct AllocationBlock;
struct JB_Object;
struct DummyBlock;
struct JB_MemoryWorld;
struct JBObject_Behaviour;


////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    JB_FreeObject*             	FirstFree;
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



struct AllocationBlock {
    u16                     ObjCount;
    u16                     HiddenObjCount;
    u16                     ObjSize;
    u16                     DebugMark; 
    AllocationBlock*        NextBlock;
    AllocationBlock*        PrevBlock;
    
    JB_MemoryLayer*         Owner;
    void*             		Unused;

    JB_FreeObject*          FirstFree;

    JBObject_Behaviour*     Virtuals;		// speed things up a bit.
};


struct JB_MemoryLayer : JB_Object  { // is actually a JB_Object... but a clang bug won't let me use "JBClass(JB_MemoryLayer..."

// User values
	int					Int;
    JB_Object*          Obj;
    JB_Object*          Obj2;

// Internal
    u16                 HiddenRefCount;
    bool                IsActive;
    bool                DummyBool;
    AllocationBlock*    CurrBlock;
    JB_Class*           Class;
    AllocationBlock*    SpareBlock;
    
    AllocationBlock     Dummy;
}; 
JBStructData (JB_MemoryLayer);



struct JB_Class : JB_Object { // JB_ClassData (is NOT a JB_Object. Would be nice but not so simple to achieve.)
    int					Index;
    const char*         Name;
    JB_Class*           Parent;
    JB_Class*           NextClass;
    JBObject_Behaviour* Virtuals; 
    int					LeakCounter;
    u16                 Size;
    uint8               ClassDepth;		// also
    bool                HasSubClasses;  // for optimised isa testing
    uint8*              SaveInfo;
    AllocationBlock*    DefaultBlock;

    JB_MemoryLayer      Memory;
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


struct JB_UltraMap {
	int64 Allocated;
	uint  RefCount;
};

struct JB_MemoryWorld : JB_UltraMap {
	int						DebugMark;
	bool					DoTotalMemoryTest;
	byte					MemFailKeeper;
    AllocationBlock*		AvailableBlock;
    AllocationBlock*		HeadBlock;
    AllocationBlock*		SpaceBegin;
    JB_FreeObject*			StartObj;
    void*					BlockEnd;
} __attribute__ ((aligned (16)));




void JB_ClassInitReal (JB_Class& Cls, const char* Name, int Size, JB_Class* Parent, JBObject_Behaviour* b);
inline JB_Class JBClassInit (JB_Class& Cls, const char* Name, int Size, JB_Class* Parent, JBObject_Behaviour* b) {
	JB_ClassInitReal(Cls, Name, Size, Parent, b);
	return Cls;
}

JBStructData(JB_Object);
struct Array;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

JB_MemoryWorld* JB_MemStandardWorld();
void JB_Layer_Use( JB_MemoryLayer* self );
void JB_Mem__Unmark( );
void JB_Mem__Mark( );
byte* JB_Mem__PermAlloc (int64 Amount, int64 Align);
JB_Class* JB_Obj_Class(JB_Object* Obj);
int JB_RefCount(JB_Object* Obj);
void** JB_Obj_ClassBehaviours(JB_Object* Obj);
JB_MemoryLayer* JB_Obj_Layer( JB_Object* Obj );
uint JB_Obj_ID( JB_Object* Obj );
JB_MemoryLayer* JB_Class_DefaultLayer( JB_Class* Cls );
JB_MemoryLayer* JB_Class_Layer( JB_Class* Cls );
JB_MemoryLayer* JB_Class_CurrLayer( JB_Class* Cls );
int64 JB_Class_MemoryUsed( JB_Class* Cls );
JB_Class* JB_Class__First();
JB_MemoryLayer* JB_Layer_Constructor( JB_MemoryLayer* self, JB_Class* Cls, JB_Object* Obj );
void JB_Class_Init(JB_Class* Cls, JB_MemoryWorld* World, int Size);
bool JB_DebugAllMemory(bool b);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

__hot JB_Object* JB_AllocNew( AllocationBlock* CurrBlock );
void JB_Delete( JB_FreeObject* Obj );
fpDestructor JB_Destructor (JB_Object* Obj);
void JB_Obj_Destructor (JB_Object* Obj);
void JB_FindLeakedObject(JB_Object* Obj, Array* R);
void JB_Mem__ClassLeakCounter ();
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
    #ifndef JB_TotalSanity_Force
		#define JB_TotalSanity_Force 0
	#endif
#else
    #define JBObjRefTest(obj)
    #define JBTestSanityOK 0
#endif


bool JB_TotalSanity (bool Force);
bool JB_Obj_IsValid (JB_Object* Obj);


inline JB_Object* JB_Incr_(JB_Object* self) {
    if (self) {
    #if DEBUG
		JB_TotalSanity(JB_TotalSanity_Force);
	#endif
        self->RefCount += 1<<JB_RefCountShift;
    #if DEBUG
		JBObjRefTest(self);
	#endif
    }
    return self;
}


inline void JB_Decr(JB_Object* self) {
    if ( self ) {
		int N = self->RefCount - (1<<JB_RefCountShift);
		self->RefCount = N;
		JBObjRefTest(self);
        if (!N)
            JB_Delete( (JB_FreeObject*)self );
    }
}


inline void JB_SetSquash (JB_Object* Self, JB_Squash* Where, JB_Object* Value) {
	JB_Squash V2 = Value;
	JB_Incr_(Value);
	auto Old = *Where + Self;
	*Where = V2;
	JB_Decr(Old);
}


inline void JB_Clear_(JB_Object** Place) {
    #if DEBUG
		JB_TotalSanity(JB_TotalSanity_Force);
	#endif
	JB_Object* self = *Place;
	*Place = nil;
	JB_Decr(self);
}


inline JB_Object* JB_SafeDecr_(JB_Object* self) {
    if (self) {
        self->RefCount -= 1<<JB_RefCountShift;
		JBObjRefTest(self);
    }
    #if DEBUG
		JB_TotalSanity(JB_TotalSanity_Force);
	#endif
    return self;
}

inline JB_Object* JB_FreeIfDead(JB_Object* self) {
    #if DEBUG
		JB_TotalSanity(JB_TotalSanity_Force);
	#endif
    if (self) {
		JBObjRefTest(self);
        if (self->RefCount  <  1<<JB_RefCountShift)
            JB_Delete( (JB_FreeObject*)self );
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
    memset(JB_Shift(Place,4), 0, Size - 4); // refcount should be 0. Don't hide bug if refcount > 0!
    return Place;
}

inline void JB_MarkRefCount(JB_Object* obj, bool On) {
	int R = obj->RefCount &~ 1;
	obj -> RefCount = R | On;
}


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // __JB_ALLOC__


