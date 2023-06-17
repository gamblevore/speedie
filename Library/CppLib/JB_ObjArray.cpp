
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2017 Theodore H. Smith.
*/

#include "JB_Umbrella.hpp"

extern "C" {

#ifndef ENV64BIT
    #define kArrayLengthMax (1024*1024*512) // 512MB
#else
    #define kArrayLengthMax (2147483644) // 2GB
#endif
#define PtrSize (sizeof(void*))




void OutOfMem_(Array*self, int Count=0) {
    JB_OutOfUserMemory((self->Capacity+Count)*sizeof(void*));
}


static bool ReAlloc_(Array* self, int C) {
	auto X = (JB_Object**)JB_realloc(self->_Ptr, C*sizeof(void*));
	if (!X) {
        JB_OutOfUserMemory(C*sizeof(void*));
		return false;
	}
	self->_Ptr = X;
	self->Capacity = (int)(JB_msize(X)/sizeof(void*));
	return true;
}

bool JB_Array_Reserve(Array* self, int64 N) {
	int C = self->Capacity;
	if (N <= C) {
		return true;
	}
	
	if (N <= kArrayLengthMax) {
		if (ReAlloc_(self, (int)N)) {
			return true;
		}
    } else {
        JB_TooLargeAlloc(N, "array allocation");
    }
    return false;
}

static bool GrowToLength_(Array* self, int64 N) {
	require (JB_Array_Reserve(self, N));
	self->Length = (int)N;
	return true;
}


static void ShrinkLength_(Array* self, int64 NewLength) {
	self->Length = (int)NewLength;
	if (!NewLength) {
		auto P = self->_Ptr;
		self->Capacity = 0;
		self->_Ptr = 0;
		JB_free(P);
	} else {
		int C = self->Capacity;
		if (NewLength <= (C/2) and C > 8) {
			C = std::max((int)NewLength, 8);
			ReAlloc_(self, C);
		}
	}
}


void JB_Array_AppendCount( Array* self, JB_Object* Value, int64 Count ) {
	require0 (Value and Count > 0);
	int64 n = self->Length; 
	require0(GrowToLength_(self, n+Count));
	Value->RefCount += Count;
	auto P = self->_Ptr + n;
	auto Pf = P + Count;
	while (P < Pf)
		*P++ = Value;
}


void JB_Array_Append( Array* self, JB_Object* Value ) {
	JB_Array_AppendCount(self, Value, 1);
}


void JB_Array_SizeSet( Array* self, int64 NewLength ) {
    int Length = self->Length;	
    if (NewLength < Length) {
        JB_Object** Curr = self->_Ptr + --Length;
        JB_Object** Last = self->_Ptr + NewLength;
        while ( Curr >= Last ) // backwards is safer.
            JB_Decr( *Curr-- );
		ShrinkLength_(self, NewLength);
	}
}


JB_String* JB_Array_Render(Array* self, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	JB_FS_AppendByte(fs, '[');
	int n = JB_Array_Size(self);
    for_(n) {
        JB_Object* obj = JB_Array_Value(self, i);
        if (i)
            JB_FS_AppendCString(fs, ", ");
        JB_ObjRender(obj, fs);
    }
	JB_FS_AppendByte(fs, ']');
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
	ShrinkLength_(self, N-1);
	JB_Decr(Item);
}


void JB_Array_Destructor( Array* self ) {
    JB_Array_SizeSet( self, 0 );
}


int JB_Array_Size( Array* self ) {
    if (self)
        return (int)(self->Length);
    return 0;
}


Array* JB_Array_Copy(Array* self) {
    require(self);
	Array* Result = (Array*)JB_New(Array);
	int n = self->Length;
	if (!GrowToLength_(Result, n)) {
		JB_Decr(Result);
		return 0;
	}

    auto Place = Result->_Ptr;
	CopyBytes(self->_Ptr, Place, sizeof(void*) * n);
	for_(n) {
		JB_Incr(Place[i]);
	}
    return Result;
}

void JB_Array_Swap(Array* self, uint i, uint j) {
	uint n = JB_Array_Size(self);
	if (i < n and j < n) {
		std::swap(self->_Ptr[i], self->_Ptr[j]);
	}
}

void JB_Array_Constructor0( Array* self ) {
	self->Length = 0;
	self->Capacity = 0;
	self->_Ptr = 0;
	self->Marker = 0;
}


int JB_Array_Wipe(Array* self) {
    if (self)
		JB_Array_SizeSet(self, 0);
    return 0;
}


void JB_Array_ValueSet( Array* self, int Pos, JB_Object* Value ) {
	if (Value) {
		u32 n = (u32)self->Length;
		if ((u32)Pos < n) {
			JB_SetRef( self->_Ptr[Pos], Value );
		}
	} else {
		JB_ReportMemoryError("Tried to set a nil value into an array", 0, nil);
	}
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

#define obj JB_Object*

#ifndef AS_LIBRARY
void JB_Array_Shuffle( Array* self ) {
	int n = JB_Array_Size(self);
	JB_Object** Array = self->_Ptr;
	uint64 Hash = ~1234567;

	for_(n) {
		obj ai = Array[i];
		Hash = JB_uint64_hash(RDTSC() xor (~(uint64)ai) xor Hash);
		int i2 = Hash % n;
		Array[i] = Array[i2];
		Array[i2] = ai;
	}
}
#endif



static int SortABit(obj* array, int j, int high, SorterComparer fp) {
    auto pivot = array[high];
    while ((fp)(array[j++], pivot)) // no need swap
		if (j >= high)
			return j;
	int i = j-2;
    while (j < high) {
        if ((fp)(array[j], pivot))
            std::swap(array[++i], array[j]);
		j++;
	}
	std::swap(array[++i], array[high]);
	return i;
}


static void QuickSort(obj* array, int start, int end, SorterComparer fp) {
    require0 (start < end);
    int p = SortABit(	 array, start, end,   fp);
    QuickSort(			 array, start, p - 1, fp);
    QuickSort(			 array, p + 1, end,   fp);
}

void JB_Array_Sort ( Array* self, SorterComparer fp, bool down ) {
	int N = JB_Array_Size(self);
	require0 (fp and N>1);
	
	obj* J = self->_Ptr;
	QuickSort(J, 0, N-1, fp); // oop?
}


} // 


