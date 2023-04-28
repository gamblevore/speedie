
/*
	Copyright (C) 2005 Theodore H. Smith.
*/



#ifndef __JB_Str__
#define __JB_Str__








			 // Includes

#include "JB_Alloc.h"
#include "JB_LibTypes.h"
#include "StringFunctions.h"
#include "StringFunctionsLib.h"
#include "StringConvert.h"
#include "JB_ByteArray.h"

extern "C" {


void JB_BALZ_Clear();
int JB_BALZ_CompressChunk(FastString* fs, JB_String* In, bool Strong);
int JB_BALZ_DecompressChunk(FastString* fs, JB_String* In, int Expected);
int balzmain(int argc, const char* argv[]);

extern JB_String* JB_LUB[];


inline uint8 LowerCaseB(uint8 c) {
    if (c <= 90 and c >= 65) {
        return (uint8)(c + 32);
    }
    return c;
}


JBClass( JB_StringShared, JB_String,
    JB_Object*      Parent; // refcount parent
);

JBClass( JB_StringExternal, JB_String,
    void*           Free;   // fp
    void*           Obj ;
);


JBClass( JB_StringC, JB_String,

);

JBClass( JB_String4, JB_String,
        uint8  Data[4];
);

JBClass( JB_String20, JB_String,
        uint8  Data[20];
);



struct MiniStr {
    int				Length; // length
    uint8*			Addr; // address
    
    bool Exists() {
        return Length;
    }
    bool Forward() {
        return Length >= 1;
    }
    uint8 Next() {
// Tests show that using .Next() intead of *Ptr++ is equally fast.
// good optimiser i guess?
        Length--;
        return *Addr++;
    }
    uint8 Prev() {
		++Length;
        return *(--Addr);
    }
    uint8 PrevLower() {
        return LowerCaseB(Prev());
    }
    uint8 Curr() {
        return *Addr;
    }
    uint8 NextLower() {
        return LowerCaseB(Next());
    }
    operator bool() {
        return Length;
    }
    operator uint8*() {
        return Addr;
    }
    uint8* After() {
        return Addr+Length;
    }
    int Dir() {
        if (Length < 0) {
            Addr--;
            return -1;
        } else {
            return 1;
        }
    }
    inline uint8 Move(int D) {
        Length -= D;
        uint8 Result = *Addr; // Next() already compiled to as fast as *Ptr++, perhaps this will too?
        Addr += D;
        return Result;
    }
    bool operator==(const MiniStr &str) const{
        return Addr==str.Addr and Length == str.Length;
    }
    MiniStr operator+(int D) const{
        MiniStr Result = {Length - D, Addr + D};
        return Result;
    }
    bool operator!=(const MiniStr &str) const{
        return !(*this == str);
    }
};


inline MiniStr Mini(JB_String* S, int N=0) {
    MiniStr M = {S->Length, S->Addr};
    return M + N;
}


// how to "unshare" this? If we are only keeping a small part of many files?
// seems... we could try to re-link the parent memorylayer into the main memorylayer for String, and go through all the AllocationBlocks and set them to use the main memorylayer...


inline bool SectFix_( int& srOffset, int& srLength, int CurrLen ) {
    if (srOffset < 0) {
        srLength += srOffset;
        srOffset = 0;
    }
/*
     * We want to make sure that we fix bad ranges.
     * We want to allow huge ranges, like String.kEnd (largest possible number)
     * We don't need it to be ints or uints specifically.
     * As few operations as possible!
     
     It used to fail with kMax! because kMax + 1 = -1
     
     I hope using u32 fixes this. I can't remember :(
*/
    u32 Final = (u32)srLength + (u32)srOffset;
    if (Final > (u32)CurrLen) {
        srLength = CurrLen - srOffset;
    }
    return (srLength >= 1);
}


inline MiniStr ReadAddrs_( JB_String* self, int StartOff, int AfterOff ) {
    int SelfAfter = self->Length;
    if (StartOff < 0) {
        StartOff = SelfAfter + 1 + StartOff;
    } else if (StartOff > SelfAfter) {
        StartOff = SelfAfter;
    }
    if (AfterOff > SelfAfter) {
        AfterOff = SelfAfter;
    } else if (AfterOff < 0) {
        AfterOff = SelfAfter + 1 + AfterOff;
    }

    return {AfterOff - StartOff, self->Addr + StartOff};  
}
    

inline int ResultFix_(uint8* Result, JB_String* S, int Dir) {
    if (Result) {
        return (int)(Result - (S->Addr + Dir));
    } else {
        return -1;
    }
}





} // extern "C"




#endif // __JB_Str__

