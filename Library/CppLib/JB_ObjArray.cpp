
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2017 Theodore H. Smith.
*/

#include "JB_Umbrella.hpp"

#include <vector>

extern "C" {

#ifndef ENV64BIT
    #define kArrayLengthMax (1024*1024*512) // 512MB
#else
    #define kArrayLengthMax (2147483644) // 2GB
#endif
#define PtrSize (sizeof(void*))




void OutOfMem_(Array*self, int Count=0) {
    JB_OutOfUserMemory(((int)(self->Vec.size())+Count)*sizeof(void*));
}

void JB_Array_AppendCount( Array* self, JB_Object* Value, int Count ) {
	if (Value) {
		try {
			while (Count-- > 0) {
				self->Vec.push_back(Value);
				JB_Incr(Value);
			}
		} catch (const std::bad_alloc&) {
			OutOfMem_(self);
		}
    } else {
		static int Errs = 0;
		Errs++;
		if (Errs <= 16) {
			JB_ReportMemoryError("Tried to append a nil value into an array", 0, nil);
		}
    }
}

void JB_Array_Append( Array* self, JB_Object* Value ) {
	JB_Array_AppendCount(self, Value, 1);
}

void JB_Array_Insert( Array* self, int Pos, JB_Object* Value ) {
	if (Pos < 0 or !Value) {
		JB_ReportMemoryError("Tried to insert a nil value into an array", 0, nil);
		return;
	}
	Pos = Min(Pos, JB_Array_Size(self));
	try {
		self->Vec.insert( self->Vec.begin()+Pos, 1,  Value );
		JB_Incr(Value);
	} catch (const std::bad_alloc&) {
		OutOfMem_(self);
	}
}


void JB_Array_SizeSet( Array* self, int NewLength ) {
    require0(self and NewLength >= 0);
    int Length = (int)(self->Vec.size());
	require0(NewLength!=Length);
	
    if (NewLength < Length) {
        JB_Object** Curr = &(self->Vec[--Length]);
        JB_Object** Last = &(self->Vec[NewLength]);
        while ( Curr >= Last ) // backwards is safer.
            JB_Decr( *Curr-- );
	} else if (NewLength > kArrayLengthMax) {
        JB_TooLargeAlloc(NewLength, "array allocation");
    }
    
    try {
        self->Vec.resize(NewLength);
    } catch (const std::bad_alloc&) {
        JB_OutOfUserMemory(NewLength*sizeof(void*));
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
    int n = (int)(self->Vec.size())/2;
    auto F = self->Vec.begin();
    for_(n)
        F[i] = F[n-(i+1)];
}

void JB_Array_Remove( Array* self, int Pos ) {
    self->Vec.erase(self->Vec.begin()+Pos);
}


void JB_Array_Destructor( Array* self ) {
    JB_Array_SizeSet( self, 0 );
}


int JB_Array_Size( Array* self ) {
    if (self)
        return (int)(self->Vec.size());
    return 0;
}


Array* JB_Array_Copy(Array* self) {
    require(self);
	Array* Result = (Array*)JB_New(Array);
    auto Place = &Result->Vec;
    new (Place) std::vector<JB_Object*>(self->Vec);
	int n = JB_Array_Size(self);
	for_(n)
		JB_Incr(Result->Vec[i]);
    return Result;
}

void JB_Array_Swap(Array* self, uint i, uint j) {
	uint n = JB_Array_Size(self);
	if (i < n and j < n) {
		std::swap(self->Vec[i], self->Vec[j]);
	}
}

void JB_Array_Constructor0( Array* self ) {
    auto Place = &self->Vec;
    new (Place) std::vector<JB_Object*>();
}


int JB_Array_Wipe(Array* self) {
    require(self);
    JB_Array_SizeSet(self, 0);
    return 0;
}


void JB_Array_ValueSet( Array* self, int Pos, JB_Object* Value ) {
	if (Value) {
		u32 n = (u32)self->Vec.size();
		if ((u32)Pos < n) {
			JB_SetRef( self->Vec[Pos], Value );
		}
	} else {
		JB_ReportMemoryError("Tried to set a nil value into an array", 0, nil);
	}
}


JB_Object* JB_Array_Value( Array* self, int Pos ) {
    if (self and (u32)Pos < self->Vec.size()) {
        return self->Vec[ Pos ];
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
	JB_Object** Array = &self->Vec[0];
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
	
	obj* J = &(self->Vec[0]);
	QuickSort(J, 0, N-1, fp); // oop?
}


} // 


