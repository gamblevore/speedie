
// Copyright, Theodore H. Smith 2017
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2017 Theodore H. Smith.
*/

#include "JB_Umbrella.hpp"



#define __spdsort_type__ JB_Squash
#define __spdsort_func__(fp,b,c,d)  ({									\
	((ArraySorterComparerInt)fp)(JB_UnSquash(d,b), JB_UnSquash(d,c));	\
})
#include "spdsort/spdsort.h"

#define kArrayLengthMax (2147483644)

#if __VM__
#undef __SPD_SORT__
#undef __spd_variant__
#undef __spdsort_func__
#define __spd_variant__(fn) (fn##VM) 
#define __spdsort_func__(fp,b,c,d)  ({					\
														\
	auto V = JB_GlobalVM;								\
	((JB_Object**)((V->ProposedStack)+2))[0] = JB_UnSquash(d,b);		\
	((JB_Object**)((V->ProposedStack)+3))[0] = JB_UnSquash(d,c);		\
	JB_ASM_CallBack(V, (u32*)fp)[0][0];					\
})
// VMSort COULD be optimised but I don't want to ruin my life optimising everything.
// You need to err on one side or the other... and I tend to err on the optimising side
// so... I might as well err the other way, for once.

#include "spdsort/spdsort.h"
#endif


extern "C" {
void JB_Array_Sort (Array* Self, ArraySorterComparerInt fp) {
	int N = JB_Array_Length(Self);
	require0 (N >= 2);
	
	auto Base = JB_SquashBase(Self);
	auto Start = Self->_Ptr;
	auto After = Start+N-1; 
	#if __VM__
	if (((IntPtr)fp)>>63)		// speedie func!
		return SpdSortVM((void*)fp, Start, After, Base);
	#endif
	
	SpdSort((void*)fp, Start, After, Base);
}




static bool ReAlloc_ (Array* self, int C) {
	auto X = (JB_Squash*)JB_Realloc(self->_Ptr, C*sizeof(JB_Squash));
	if (!X)
		return false;
	self->_Ptr = X;
	self->_Capacity = (int)(JB_msize(X)/sizeof(JB_Squash));
	return true;
}


static bool GrowToLength_ (Array* self, int N, bool Extra) {
	int C = self->_Capacity;
	if (N <= C) {				// fast grow length
		self->_Length = N;
		return true;
	}
	
	if_rare (N > kArrayLengthMax)
        return JB_OutOfUserMemory(N);
	if_rare (!ReAlloc_(self, N+((N*Extra)>>1)))
		return false;

	self->_Length = N;
	return true;
}


static void ArrayClear (Array* self) {
	auto P = self->_Ptr;
	self->_Capacity = 0;
	self->_Length = 0;
	self->_Ptr = 0;
	JB_Free(P);
}


static void ShrinkCapacity_ (Array* self, uint Length) {
	if (Length <= 0)
		return ArrayClear(self);
	self->_Length = Length;

	int C = self->_Capacity;
	if (C <= 5  or  Length*2 > C)
		return;
	C = std::max((int)Length, 8);
	self->_Capacity = C;
	self->_Ptr = (JB_Squash*)JB_Realloc(self->_Ptr, C*sizeof(JB_Squash));
}


int JB_Array_Find (Array* Self, JB_Object* F) {
	if (Self) {
		JB_Squash F2 = F;
		auto P = Self->_Ptr; 
		int N = Self->_Length;
		int i = 0; 
		while (i < N) {
			if (P[i] == F2)
				return i;
			i++;
		}
	}
	return -1;
}


bool JB_Array_AppendCount( Array* self, JB_Object* Value, int Count ) {
	require (Value and Count > 0);
	int n = self->_Length; 
	require(GrowToLength_(self, n+Count, true));
	JB_SetRefCount(Value, JB_RefCount(Value) + Count);
	auto P = self->_Ptr + n;
	auto Pf = P + Count;
	JB_Squash V2 = Value;
	while (P < Pf)
		*P++ = V2;
	return true;
}


bool JB_Array_Append ( Array* self, JB_Object* Value ) {
	if (Value) {
		int n = self->_Length; 
		if (GrowToLength_(self, n+1, true)) {
			JB_Incr(Value);
			self->_Ptr[n] = JB_Squash(Value);
			return true;
		}
	}
	return false;
}


bool JB_Array_Insert ( Array* Self, int Pos, JB_Object* Value ) {
	int n = Self->_Length;
	if ( (uint)Pos > n  or  !JB_Array_Append(Self, Value) )
		return false;
	if (Pos == n)
		return true; // already done.
	
	auto P = Self->_Ptr;
	
	JB_Squash* Curr = P+n;
	JB_Squash* First = P+Pos;
	while (Curr > First) {
		Curr--;
		Curr[1] = Curr[0];
	}
	First[0] = JB_Squash(Value);
	
	return true;
}


static void ArrayDecrDownTo_ (Array* Self, int64 NewLength) {
	int N = Self->_Length - 1;
	JB_Squash* Curr = Self->_Ptr + N;
	JB_Squash* First = Self->_Ptr + NewLength;
	auto Base = JB_SquashBase(Self);
	while ( Curr >= First ) { // backwards is safer.
		JB_Decr( JB_UnSquash(Base, *Curr--) );
	}
}


void JB_Array_Shrink (Array* self) {
	int L = self->_Length;
	if (L < self->_Capacity) {
		self->_Capacity = L;
		self->_Ptr = (JB_Squash*)JB_Realloc(self->_Ptr, L*sizeof(JB_Squash));
	}
}

void JB_Array_LengthSet( Array* self, int NewLength ) {
    int Length = self->_Length;	
    if (NewLength >= Length)
		return;
	ArrayDecrDownTo_(self, NewLength);
	ShrinkCapacity_(self, NewLength);
}


bool ObjContainerOK_ (JB_Object* Self, FastString* FS) {
	if (Self->RefCount & 1<<30) {
		JB_FS_AppendCString(FS, "..."); // infinite loop!
		return false;
	}
	Self->RefCount |= 1<<30;
	return true;
}


JB_String* JB_Array_Render (Array* self, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	if (!self) {
		JB_FS_AppendCString(fs, "nil");
	} else {
		JB_FS_AppendByte(fs, '[');
		if (ObjContainerOK_(self, fs)) {
			int n = JB_Array_Length(self);
			for_(n) {
				JB_Object* obj = JB_Array_Value(self, i);
				if (i)
					JB_FS_AppendCString(fs, ", ");
				JB_Obj_Render(obj, fs);
			}
			self->RefCount &= ~(1<<30);
		}
		JB_FS_AppendByte(fs, ']');
	}
	return JB_FS_SmartResult(fs, fs_in);
}


void JB_Array_Reverse( Array* self ) {
    int n = (int)(self->_Length)/2;
    auto F = self->_Ptr;
    for_(n)
        F[i] = F[n-(i+1)];
}


void JB_Array_Remove( Array* self, int Pos ) {
	auto Item = JB_Array_Value(self, Pos);
	if (Item) {
		int N = self->_Length;
		while (Pos < N) {
			self->_Ptr[Pos] = self->_Ptr[Pos+1];
			Pos++;  
		}
		ShrinkCapacity_(self, N-1);
		JB_Decr(Item);
	}
}


void JB_Array_Destructor( Array* self ) {
	if (self->_Ptr) {
		ArrayDecrDownTo_(self, 0);
		ArrayClear(self);
	}
	JB_Obj_Destructor(self);
}


int JB_Array_Length( Array* self ) {
    if (self)
        return (int)(self->_Length);
    return 0;
}


Array* JB_Array_Copy (Array* Self) {
    require(Self);
	Array* Result = JB_Array_Constructor0(nil);
	int n = Self->_Length;
	if (!n)
		return Result;
	if (!GrowToLength_(Result, n, false)) {
		JB_Array_Destructor(Result);
		return 0;
	}

    auto Dest = Result->_Ptr;
    auto After = Dest + n;
    auto Src = Self->_Ptr;
    auto Base = JB_SquashBase(Self);
	while (Dest < After) {
		auto O = *Src++;
		*Dest++ = O;
		auto O2 = JB_UnSquash(Base, O);
		JB_Incr(O2);
	}
    return Result;
}


void JB_Array_Swap (Array* self, uint i, uint j) {
	uint n = JB_Array_Length(self);
	if (i < n and j < n) {
		std::swap(self->_Ptr[i], self->_Ptr[j]);
	}
}


Array* JB_Array_Constructor0 ( Array* self ) {
	JB_New2(Array);
	self->_Length = 0;
	self->_Capacity = 0;
	self->_Ptr = 0;
	self->_Marker = 0;
	return self;
}


int JB_Array_Wipe (Array* self) {
    if (self)
		JB_Array_LengthSet(self, 0);
    return 0;
}


void JB_Array_ValueSet ( Array* Self, int Pos, JB_Object* Value ) {
	if ((u32)Pos < (u32)(Self->_Length)) {
		JB_SetSquash(Self, Self->_Ptr+Pos, Value);
	}
}


JB_Object* JB_Array_Pop (Array* Self) {
	if (Self) {
		int n = Self->_Length - 1;
		if (n >= 0) {
			JB_Squash rz = Self->_Ptr[n];
			ShrinkCapacity_(Self, n);
			return JB_UnSquash(Self, rz);
		}
	}
	return nil;
}


JB_Object* JB_Array_Value( Array* self, int Pos ) {
    if (self and (u32)Pos < self->_Length) {
        return JB_UnSquash(self, self->_Ptr[ Pos ]);
    }
    return 0;
}

JB_Object* JB_Array_Last( Array* self, int Pos ) {
    if (self) {
		int N = self->_Length;
		Pos = N - (Pos+1);
		if ((uint)Pos < (uint)N)
			return JB_UnSquash(self, self->_Ptr[ Pos ]);
    }
    return 0;
}


#ifndef AS_LIBRARY
void JB_Array_Shuffle( Array* self ) {
	int n = JB_Array_Length(self);
	require0(n);
	JB_Squash* Array = self->_Ptr;
	uint64 Hash = JB_Date__Now();
	self->_Marker = 0;

	for_(n) {
		auto ai = Array[i];
		Hash = JB_uint64_hash(JB_uint64_hash(~(uint64)ai xor Hash) + i);
		int i2 = Hash % n;
		Array[i] = Array[i2];
		Array[i2] = ai;
	}
}
#endif


} // 


