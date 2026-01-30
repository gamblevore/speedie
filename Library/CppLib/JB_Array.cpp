
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2017 Theodore H. Smith.
*/

#include "JB_Umbrella.hpp"
#define __spdsort_type__ JB_Object*
#define __spdsort_func__(fp,b,c)  (((ArraySorterComparerInt)fp)(b, c))
#define __spdsort_swap__ JB_Swap
#include "spdsort/spdsort.h"

extern "C" {
void JB_Array_Sort ( Array* self, ArraySorterComparerInt fp) {
	int N = JB_Array_Size(self);
	if (fp and N >= 2) // remove the check for fp? nilchecker should find it.
		SpdSort((void*)fp, self->_Ptr, self->_Ptr+N-1);
}


#define kArrayLengthMax (2147483644)	 	// 16GB on 64-bit platforms, 8GB on 32-bit platforms.
#define PtrSize (sizeof(void*))




void OutOfMem_ (Array*self, int Count=0) {
    JB_OutOfUserMemory((self->Capacity+Count)*sizeof(void*));
}


static bool ReAlloc_ (Array* self, int C) {
	auto X = (JB_Object**)JB_Realloc(self->_Ptr, C*sizeof(void*));
	if (!X)
		return false;
	self->_Ptr = X;
	self->Capacity = (int)(JB_msize(X)/sizeof(void*));
	return true;
}


static bool GrowToLength_ (Array* self, int N, bool Extra) {
	int C = self->Capacity;
	if (N <= C) {				// fast grow length
		self->Length = N;
		return true;
	}
	
	if (N <= kArrayLengthMax) {
		if (ReAlloc_(self, N+((N*Extra)>>1))) {
			self->Length = N;
			return true;
		}
    } else {
        JB_TooLargeAlloc(N, "array allocation");
    }
    return false;
}


static void Clear_ (Array* self) {
	auto P = self->_Ptr;
	self->Capacity = 0;
	self->_Ptr = 0;
	JB_Free(P);
}


static void ShrinkCapacity_ (Array* self, uint Length) {
	self->Length = Length;
	if (Length <= 0)
		return Clear_(self);

	int C = self->Capacity;
	if (C <= 5  or  Length*2 > C)
		return;
	C = std::max((int)Length, 8);
	self->Capacity = C;
	self->_Ptr = (JB_Object**)JB_Realloc(self->_Ptr, C*sizeof(void*));
}


int JB_Array_Find (Array* Self, JB_Object* F) {
	if (Self) {
		auto P = Self->_Ptr; 
		auto A = P + Self->Length; 
		while (P < A)
			if (*P++ == F)
				return (A - P)-1;
	}
	return -1;
}




void JB_Array_AppendCount( Array* self, JB_Object* Value, int Count ) {
	require0 (self and Value and Count > 0);
	int n = self->Length; 
	require0(GrowToLength_(self, n+Count, true));
	JB_SetRefCount(Value, JB_RefCount(Value) + Count);
	auto P = self->_Ptr + n;
	auto Pf = P + Count;
	while (P < Pf)
		*P++ = Value;
}


void JB_Array_Append( Array* self, JB_Object* Value ) {
	JB_Array_AppendCount(self, Value, 1);
}


static void ArrayDecrDownTo_(Array* self, int64 NewLength) {
	JB_Object** Curr = self->_Ptr + self->Length-1;
	JB_Object** First = self->_Ptr + NewLength;
	while ( Curr >= First ) // backwards is safer.
		JB_Decr( *Curr-- );
}


void JB_Array_Shrink (Array* self) {
	int L = self->Length;
	if (L < self->Capacity) {
		self->Capacity = L;
		self->_Ptr = (JB_Object**)JB_Realloc(self->_Ptr, L*sizeof(void*));
	}
}

void JB_Array_SizeSet( Array* self, int NewLength ) {
    int Length = self->Length;	
    if (NewLength >= Length)
		return;
	ArrayDecrDownTo_(self, NewLength);
	ShrinkCapacity_(self, NewLength);
}


JB_String* JB_Array_Render(Array* self, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	if (!self) {
		JB_FS_AppendCString(fs, "nil");
	} else {
		JB_FS_AppendByte(fs, '[');
		int n = JB_Array_Size(self);
		for_(n) {
			JB_Object* obj = JB_Array_Value(self, i);
			if (i)
				JB_FS_AppendCString(fs, ", ");
			JB_Obj_Render(obj, fs);
		}
		JB_FS_AppendByte(fs, ']');
	}
	return JB_FS_SmartResult(fs, fs_in);
}



void JB_Array_Reverse( Array* self ) {
    int n = (int)(self->Length)/2;
    auto F = self->_Ptr;
    for_(n)
        F[i] = F[n-(i+1)];
}

void JB_Array_Remove( Array* self, int Pos ) {
	auto Item = JB_Array_Value(self, Pos);
	require0 (Item);
	int N = self->Length;
	while (Pos < N) {
		self->_Ptr[Pos] = self->_Ptr[Pos+1];
		Pos++;  
	}
	ShrinkCapacity_(self, N-1);
	JB_Decr(Item);
}


void JB_Array_Destructor( Array* self ) {
	if (self->_Ptr) {
		ArrayDecrDownTo_(self, 0);
		Clear_(self);
	}
}


int JB_Array_Size( Array* self ) {
    if (self)
        return (int)(self->Length);
    return 0;
}

Array* JB_Array_Copy(Array* self) {
    require(self);
	Array* Result = JB_Array_Constructor0(nil);
	int n = self->Length;
	if (!n)
		return Result;
	if (!GrowToLength_(Result, n, false)) {
		JB_Delete((FreeObject*)Result);
		return 0;
	}

    auto Dest = Result->_Ptr;
    auto After = Dest + n;
    auto Src = self->_Ptr;
	while (Dest < After) {
		auto O = *Src++;
		*Dest++ = O;
		JB_Incr(O);
	}
    return Result;
}

void JB_Array_Swap(Array* self, uint i, uint j) {
	uint n = JB_Array_Size(self);
	if (i < n and j < n) {
		std::swap(self->_Ptr[i], self->_Ptr[j]);
	}
}

Array* JB_Array_Constructor0( Array* self ) {
	JB_New2(Array);
	self->Length = 0;
	self->Capacity = 0;
	self->_Ptr = 0;
	self->Marker = 0;
	return self;
}


int JB_Array_Wipe(Array* self) {
    if (self)
		JB_Array_SizeSet(self, 0);
    return 0;
}


void JB_Array_ValueSet( Array* self, int Pos, JB_Object* Value ) {
	if ((u32)Pos < (u32)(self->Length)) {
		JB_SetRef( self->_Ptr[Pos], Value );
	}
}


JB_Object* JB_Array_Pop(Array* self) {
	if (self) {
		int n = self->Length - 1;
		if (n >= 0) {
			JB_Object* rz = self->_Ptr[n];
			ShrinkCapacity_(self, n);
			return rz;
		}
	}
	return nil;
}


JB_Object* JB_Array_Value( Array* self, int Pos ) {
    if (self and (u32)Pos < self->Length) {
        return self->_Ptr[ Pos ];
    }
    return 0;
}
    
void JB_FillInts(int* Start, int N, int Value) {
	std::fill(Start, Start+N, Value);
}


#ifndef AS_LIBRARY
void JB_Array_Shuffle( Array* self ) {
	int n = JB_Array_Size(self);
	JB_Object** Array = self->_Ptr;
	uint64 Hash = ~1234567;
	self->Marker = 0;

	for_(n) {
		auto ai = Array[i];
		Hash = JB_uint64_hash(RDTSC() xor (~(uint64)ai) xor Hash);
		int i2 = Hash % n;
		Array[i] = Array[i2];
		Array[i2] = ai;
	}
}
#endif


} // 


