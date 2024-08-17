
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


static bool GrowToLength_(Array* self, int N) {
	int C = self->Capacity;
	if (N <= C) {
		self->Length = N;
		return true;
	}
	
	if (N <= kArrayLengthMax) {
		if (ReAlloc_(self, N)) {
			self->Length = N;
			return true;
		}
    } else {
        JB_TooLargeAlloc(N, "array allocation");
    }
    return false;
}


static void Clear_(Array* self) {
	auto P = self->_Ptr;
	self->Capacity = 0;
	self->_Ptr = 0;
	JB_free(P);
}


static void ShrinkCapacity_(Array* self, uint Smaller) {
	self->Length = Smaller;
	if (Smaller > 0) {
		int C = self->Capacity;
		if (C <= 8 or Smaller*2 > C)
			return;
		C = std::max((int)Smaller, 8);
		self->Capacity = C;
		self->_Ptr = (JB_Object**)JB_realloc(self->_Ptr, C*sizeof(void*));
		return;
	}
	Clear_(self);
}


void JB_Array_AppendCount( Array* self, JB_Object* Value, int Count ) {
	require0 (Value and Count > 0);
	int n = self->Length; 
	require0(GrowToLength_(self, n+Count));
	JB_SetRefCount(Value, JB_RefCount(Value) + Count);
	auto P = self->_Ptr + n;
	auto Pf = P + Count;
	while (P < Pf)
		*P++ = Value;
}


void JB_Array_Append( Array* self, JB_Object* Value ) {
	JB_Array_AppendCount(self, Value, 1);
}


static void Decr_(Array* self, int64 NewLength) {
	JB_Object** Curr = self->_Ptr + self->Length-1;
	JB_Object** First = self->_Ptr + NewLength;
	while ( Curr >= First ) // backwards is safer.
		JB_Decr( *Curr-- );
}


bool JB_Array_FastShrink( Array* self, int NewLength ) {
    int Length = self->Length;	
    if (NewLength < Length) {
		Decr_(self, NewLength);
		self->Length = (int)NewLength;
		return true;
	}
	return false;
}


void JB_Array_SizeSet( Array* self, int NewLength ) {
    if (JB_Array_FastShrink(self, NewLength)) {
		ShrinkCapacity_(self, NewLength);
	}
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
			JB_ObjRender(obj, fs);
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
		Decr_(self, 0);
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



static int SortABit(obj* array, int j, int high, SorterComparer fp, bool Up) {
    auto pivot = array[high];
    while ((fp)(array[j++], pivot)==Up) // no need swap
		if (j >= high)
			return j;
	int i = j-2;
    while (j < high) {
        if ((fp)(array[j], pivot)==Up)
            std::swap(array[++i], array[j]);
		j++;
	}
	std::swap(array[++i], array[high]);
	return i;
}


static void QuickSort(obj* array, int start, int end, SorterComparer fp, bool Up) {
    require0 (start < end);
    /// todo: this could be a lot faster if we used alloca and a depth and stored p
    /// vars there... I got a stack depth of over 100 on just storing modules. strange!
    /// could also be used for my compression code also... perhaps with a macro.
    int p = SortABit(	 array, start, end,   fp, Up);
    QuickSort(			 array, start, p - 1, fp, Up);
    QuickSort(			 array, p + 1, end,   fp, Up);
}


void JB_Array_Sort ( Array* self, SorterComparer fp, bool down ) {
	int N = JB_Array_Size(self);
	require0 (fp and N>1);
	
	obj* J = self->_Ptr;
	QuickSort(J, 0, N-1, fp, !down); // oop?
}


} // 


