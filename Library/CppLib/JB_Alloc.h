
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __JB_ALLOC__
#define __JB_ALLOC__


#include <string.h>
#include "JB_BasicTypes.h"
#include "JB_MemUtils.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// LANGUAGE ADDITIONS
#define JBShift( exp, amount ) ( (__typeof__ ( exp )) ((byte*)(exp)+(amount)))

#define likely(x)   __builtin_expect(!!(x),1)
#define unlikely(x) __builtin_expect(!!(x),0)

#define if_rare(x) if (unlikely(x))
#define if_usual(x) if (likely(x))
#define __hot __attribute__((hot))

#define __visible __attribute__((__visibility__("default")))

#if _WIN64 || __x86_64__ || __ppc64__
    #define ENV64BIT
#else
    #define ENV32BIT
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" {


#ifdef JB_DEBUG_ON
    #define JBSanity( a ) // nothing for now
    #define JB_DEBUG(x) x
    #define JB_NOTDEBUG( a )
    #include <assert.h>
#else
    #define JBSanity( a )
    #define JB_NOTDEBUG( a ) a
    #define JB_DEBUG(x)
#endif


#ifdef DEBUG
	#if defined(ARM)
		#define BK_PT "bkpt"
	#else
		#define BK_PT "int3"
	#endif
	extern bool CanASMBKPT;
    #define debugger if (CanASMBKPT) __asm__(BK_PT) // int3 works in xcode but not in releasebuilds!
    #define dbgexpect(test)  if  (!(test)) {debugger; return;} // int3 works in xcode but not in releasebuilds!
    #define dbgexpect2(test) if  (!(test)) {debugger; return 0;}
    #define JB_DoAt(count) int ldb; {static int jDB = 0; if (++jDB == count) {debugger;}; ldb = jDB; }
    #define JB_FuncCallCount(count) static int _fnCallCount_ = 0; _fnCallCount_++;
    #define DEBUGONLY(x) x
#else
    #define debugger// would crash...
    #define dbgexpect(test)
    #define dbgexpect2(test)
    #define JB_DoAt(count)
    #define JB_FuncCallCount(count)
    #define DEBUGONLY(x)
#endif


//#define IsKnown(x) (((x) & ((x) - 1)) == 0)
//#define AlwaysInline inline __attribute__((__always_inline__))
#define require(test)   if  (!(test)) {return {};}
#define require0(test)  if  (!(test)) {return;}
#define for_(count) for (int i = 0; i < count; i++)
#define FOR_(var, count) for (int var = 0; var < count; var++)


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
#define kObjMinSize 16 // safer.
#define JB_MArray(type, num)    ((type*)(JB_MArray_(sizeof(type),num)))
#define JB_NewClass(name)       (JB_Object*)(JB_Alloc2(name->DefaultBlock))
#define JB_New(name)            (name*)(JB_Alloc2((name ## Data).DefaultBlock))
#define JB_NewEmpty(name)       (name*)(ClearFor_(JB_New(name), sizeof(name)))
#define JB_LayerNew(L, name)    (name*)(JB_Alloc(L))
#define JB_Zero(name)           (ClearFor_((void*)(name), sizeof(__typeof__(*name))))
#define JBStructData(a)         extern JB_Class a ## Data;
#define JBClass(a, b, c)        struct a : b {c}; JBStructData(a);
#define JB_AsClass(Name)        (&(Name ## Data))



#define JBClassPlace0(a, b, c, d)                                           	\
JBObject_Behaviour a ## _FuncTable = {(void*)b,(void*)d};                   	\
JB_Class a ## Data = JBClassInit(a##Data, (#a), sizeof(a), c, (JBObject_Behaviour*)&(a##_FuncTable));

#define JBClassPlace(a, b, c, d)												\
JBObject_Behaviour a ## _FuncTable = {(void*)b,(void*)d};                   	\
JB_Class a ## Data = JBClassInit(a##Data, (#a), sizeof(a), c, (JBObject_Behaviour*)&(a##_FuncTable));

#define JBClassPlace4(a, b, c)													\
JB_Class a ## Data = JBClassInit(a##Data, (#a), sizeof(a), b, (JBObject_Behaviour*)&(c));


////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef void (*fpDestructor)(JB_Object* self);
typedef void (*fpAllocator)(AllocationBlock* self);
////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct DummyBlock {
    JB_MemoryLayer*        		Owner;
    FreeObject*             	FirstFree;
};


struct JB_Object {
    u32 RefCount;
};


struct JB_MemoryLayer : JB_Object  { // is actually a JBObject... but a clang bug won't let me use "JBClass(JB_MemoryLayer..."
    u16                 HiddenRefCount;
    bool                IsActive;
    bool                DontAlloc;
    AllocationBlock*    CurrBlock;
    JB_Class*           Class;
    AllocationBlock*    SpareBlock;
    JB_MemoryWorld*     World;
    
    JB_Object*          Obj;
    JB_Object*          Obj2;
    DummyBlock          Dummy;
}; 
JBStructData (JB_MemoryLayer);



struct JB_Class {
    JB_Class*           Parent;
    AllocationBlock*    DefaultBlock;
    JB_Class*           NextClass;
    u16                 Size; // Move to JB_MemoryLayer for refcountless allocs. Or put a "UsesRefCounts" bool in MemLayer
    bool                HasSubclasses;  // for optimised isa testing
    uint8               ClassDepth;		// for optimised isa testing
    int					Flags;
    int					LeakCounter;
    JB_MemoryLayer      Memory;
    const char*         Name;
    JBObject_Behaviour* FuncTable;
    uint8*              SaveInfo;
};


struct JB_MemoryWorld {
    int                 RefCount;
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


JB_Class JBClassInit(JB_Class& Cls, const char* Name, int Size, JB_Class* Parent, JBObject_Behaviour* b);

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
void* JB_BlockShadow(AllocationBlock* B);
void ClassWierdTest( );
int JB_ObjRefCount(JB_Object* Obj);
uint8* JB_ObjClassBehaviours(JB_Object* Obj);
JB_Object* JB_Mem_First( JB_MemoryLayer* Mem );
JB_Object* JB_ObjNext(JB_Object* Obj);
JB_MemoryLayer* JB_ObjLayer( JB_Object* Obj );
int JB_ObjID( JB_Object* Obj );
void JB_ObjDestroy( JB_Object* Obj );
JB_MemoryLayer* JB_Class_DefaultLayer( JB_Class* Cls );
JB_MemoryLayer* JB_Class_Layer( JB_Class* Cls );
JB_MemoryLayer* JB_Class_CurrLayer( JB_Class* Cls );
JB_Object* JB_Class_AllocZeroed( JB_Class* Cls );
void JB_Class_Add( JB_Class* Cls, const char* s );
JB_Class* JB_Class__First();
JB_MemoryLayer* JB_Mem_CreateLayer(JB_Class* Cls, JB_Object* Obj);
void JB_Mem_InitAndUse(JB_MemoryLayer* Mem, JB_Class* Cls);
void JB_Mem_Constructor( JB_MemoryLayer* self, JB_Class* Cls );
void JB_Class_Init(JB_Class* Cls, JB_MemoryWorld* World, int Size);
void JB_Class_SetIndex(JB_Class* cls, int i);
int JB_Class_Index(JB_Class* cls);
void JB_TotalMemorySet(bool b);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

__hot JB_Object* JB_Alloc( JB_MemoryLayer* Mem );
void JB_MemoryReset(JB_MemoryWorld* World, int Max);
__hot JB_Object* JB_Alloc2( AllocationBlock* CurrBlock );
void JB_Delete( FreeObject* Obj );
void JB_FindLeakedObject(JB_Object* Obj, Array* R);
void JB_Mem_ClassLeakCounter ();
__hot void JB_ClusterDelete( FreeObject* Obj );
void JB_MemFree(JB_MemoryWorld* World);

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
#define JB_SafeDecr(Obj)		JB_SafeDecr_((JB_Object*)(Obj))
#define JB_SetRef(a,b)			JB_SetRef_((JB_Object**)(&a), (JB_Object*)(b))
#define JB_Swap(a,b)			(std::swap(*(a),*(b)))
#define JB_Ternary(cond,a,b)	((cond)?(a):(b))
#define JB_LongObjOr(A, B)            ({ \
    JB_Object* _T = (A);                 \
    if (!_T) {                           \
        _T = (B);                        \
    }                                    \
    (_T);                                \
})


#if 0
	extern int RefTrap;
    #define JBObjRefTest(obj) if ( (obj->RefCount) > 100000 and !RefTrap and !(obj->RefCount&~0x10000000)) { RefTrap = 1; debugger; }
    #define JBObjRefTrap(obj) //if (JB_ObjID(obj)==RefTrap) { printf("ref of %i: %i\n", RefTrap, obj->RefCount); debugger; }
    #define JBTestSanityOK 1
#else
    #define JBObjRefTest(obj)
    #define JBTestSanityOK 0
#endif

void JB_TotalMemorySanity();
extern JB_Class ProcessData;


inline JB_Object* JB_Incr_(JB_Object* self) {
    if (self) {
		JBObjRefTest(self);
		//JB_TotalMemorySanity();
        self->RefCount++;
    }
    return self;
}

inline void JB_Decr(JB_Object* self) {
    if ( self ) {
		JBObjRefTest(self);
		//JB_TotalMemorySanity();
        int N = --self->RefCount; 
        if (!N)
            JB_Delete( (FreeObject*)self );
    }
}

inline JB_Object* JB_SafeDecr_(JB_Object* self) {
    if (self) {
		JBObjRefTest(self);
		//JB_TotalMemorySanity();
        self->RefCount--;
    }
    return self;
}

inline JB_Object* JB_FreeIfDead(JB_Object* self) {
    if (self) {
		JBObjRefTest(self);
		//JB_TotalMemorySanity();
        if (!self->RefCount) {
            JB_Delete( (FreeObject*)self );
        }
    }
    return self;
}


inline void JB_SetRef_(JB_Object** Place, JB_Object* New) {
	JB_Incr(New);
    JB_Object* Old = *Place; // Decr MUST come last, or else
	*Place = New; // a destructor can set a var into Place and we overwrite it.
	JB_Decr(Old);
}

inline int JB_RefCount( JB_Object* obj ) {
    return obj->RefCount;
}
    
inline void* ClearFor_(void* Place, u32 Size) {
    memset(JBShift(Place,4), 0, Size - 4); // refcount should be 0. Don't hide bug if refcount > 0!
    return Place;
}
    

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // __JB_ALLOC__


