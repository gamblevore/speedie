
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



#include "JB_Umbrella.hpp"
#include "JB_Log.h"
#include "JB_MemUtils.h"

extern "C" {


bool JB_IsDebug() {
#if DEBUG
    return true;
#else
    return false;
#endif
}

int JB_PointerSize() {
#ifdef ENV64BIT
    return 64;
#else
    return 32;
#endif
}


int OutOfMemoryHappenedAlready;
static int  TotalAllocObjs;  // malloc stats get confused with OUR stats...
static int  TotalAllocBytes; // malloc-zones could do this, or WE COULD OURSELVES
							// just easier.



void JB_TooLargeAlloc(int64 N, const char* S) {
	JB_ReportMemoryError("Jeebox: Oversized alloc requested: ", N, S); 
}


// So the problem with realloc, is that... what if it fails?
// we wanna return the original pointer.
// does this not free? what if we realloc to 0?
allocate_result JB_allocate (int N, const void* Arr) {
	uint8* Result = 0;
	if (Arr) {
		TotalAllocBytes -= JB_msize(Arr);
		Result = (uint8*)realloc((void*)Arr, N);
	} else {
		TotalAllocObjs++;
		Result = (uint8*)calloc(1, N); // zeroed
	}
	if (Result) {
		TotalAllocBytes += JB_msize(Result);
		return {Result, true};
	}
	
	TotalAllocBytes += JB_msize(Arr);
	JB_OutOfUserMemory(N);					// Nothing has changed...
    return {(uint8*)Arr, false};
}


uint8* JB_zalloc(int N) {
	return JB_allocate(N).Result;
}

uint8* JB_malloc(int N) {
	return JB_allocate(N).Result;
}


// Setting the size to zero actually DOES make sense, in terms of code... and reallocing zero
uint8* JB_realloc (const void* Arr, int N) {
	auto R = JB_allocate(N, Arr);
	require (R.OK);
	return R.Result;
}


u64 JB_msize(const void* M) {
#ifdef __linux__
    return malloc_usable_size((void*)M);
#else
    return malloc_size(M);
#endif
}

u64 JB_memused() {
	return TotalAllocBytes + TotalAllocObjs*4;
}


void JB_free(const void* Arr) {
	if (Arr) {
		TotalAllocObjs--;
		TotalAllocBytes -= JB_msize(Arr);
		free((void*)Arr);
    }
}



///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   


bool JB_IsLibrary() {
#if AS_LIBRARY
	return 1;
#endif
	return 0;
}


int JB_Platform__CPU() {
	return __CPU_TYPE__;
}

bool JB_Platform__OSX() {
	return __PLATFORM_CURR__ == __PLATFORM_OSX__;
}
bool JB_Platform__Win() {
	return __PLATFORM_CURR__ == __PLATFORM_WIN__;
}
bool JB_Platform__Lin() {
	return __PLATFORM_CURR__ == __PLATFORM_LINUX__;
}

JB_String* JB_Platform() {
    static JB_String* Plat = 0;
    if (Plat) {
        return Plat;
    }
    
    #if __PLATFORM_CURR__ == __PLATFORM_OSX__
        Plat = JB_StrC("osx");
    #elif __PLATFORM_CURR__ == __PLATFORM_LINUX__
        Plat = JB_StrC("lin");
    #elif __PLATFORM_CURR__ == __PLATFORM_WIN__
        Plat = JB_StrC("win");
    #endif
    
    JB_Incr(Plat);
    return Plat;    
}


bool HasCStringSpace_(JB_Class* Cls, int N) {
	if (Cls==JB_AsClass(JB_String4))
		return 4 > N;
	if (Cls==JB_AsClass(JB_String20))
		return 20 > N;
	return false;
}


JB_Class* Str_IsCSub ( JB_String* self ) { // 0 means true
	int N = JB_Str_Length(self);
	if (!N) return 0;
    auto C = JB_ObjClass(self); 
    if (C == JB_AsClass(JB_StringC) or C == JB_AsClass(JB_String) or C == JB_AsClass(JB_File)) return 0;
	if (HasCStringSpace_(C, N) and !self->Addr[N])
		return 0;
    if (C == JB_AsClass(JB_StringExternal)) {
		JB_StringExternal* Ext = (JB_StringExternal*)self;
		if (Ext->Obj == self->Addr and Ext->Free == free)
			return 0;
	}
	return C;
}


bool JB_Str_IsC ( JB_String* self ) {
	auto C = Str_IsCSub(self);
	if (!C) return true;
	if (C == JB_AsClass(JB_StringShared)) {
		auto P = (JB_String*)(((JB_StringShared*) self)->Parent);
		if (P->Length+P->Addr == self->Length+self->Addr)
			return Str_IsCSub(P)==0;
	}
    
	return false;
}


JB_StringC* JB_Str_MakeC ( JB_String* self ) {
    if (JB_Str_IsC(self))
        return (JB_StringC*)self;

	int N = JB_Str_Length(self);
	JB_StringC* Rz = (JB_StringC*)JB_Str_NewCStr( N );
    if_usual (Rz) {
        CopyBytes(self->Addr, Rz->Addr, N);
    }
	return Rz;
}

} // 



