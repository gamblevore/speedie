
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2005 Theodore H. Smith.
*/


#include "JB_Umbrella.hpp"

extern "C" {


uint8* EntityRead_( FastString* fs, uint8 FirstChar, uint8* NextRead, uint8* SelfEnd, JB_ErrorReceiver* Rec ) {
    uint8* EntPos = NextRead;
	u32 EntityFound = 0;
	bool IsHex = true;

    if (FirstChar == '\\') { // "\$"
        ; //
    } else if ( *EntPos == 'x' ) {
        EntPos++;
    } else {
        IsHex = false;
    }

	while ( EntPos < SelfEnd ) {
		u32 ThisChar = (u32)(*EntPos++);
		
		if ( ThisChar <= '9' and ThisChar >= '0'  ) { // 0 - 9
			ThisChar = ThisChar - '0'; // Numeric

		} else if ( ThisChar <= 'F' and ThisChar >= 'A' ) { // A - F
			ThisChar = ThisChar - ('A' - 10); // makes A=10

		} else if ( ThisChar <= 'f' and ThisChar >= 'a' ) { // a - f
			ThisChar = ThisChar - ('a' - 10); // makes a=10

		} else if (FirstChar != '\\' and ThisChar == ';') { // End of ent!
            JB_FS_AppendUTF8Char( fs, EntityFound );
            return EntPos;

        } else {
            if (FirstChar == '\\' and (EntPos == NextRead+2)) {
                EntPos--;
                goto DoItAnyWay;
            }
            break; // ERROR
        }

		if (IsHex) {
			EntityFound = EntityFound*16 + ThisChar;
		} else {
			EntityFound = EntityFound*10 + ThisChar;
		}

        if (FirstChar=='\\' and ((EntPos == NextRead+2) or EntPos == SelfEnd)) { //    '\0'    too short, but we'll allow.
            DoItAnyWay:;
            JB_FS_AppendByte( fs, EntityFound );
            return EntPos;
        }
	}

    // failed... sigh. Really we should just create an error? How serious is this error, though. That's the issue.
    // Do we even WANT to trap it? Errors. What a mess.
    // maybe a warning?

    if (FirstChar != '\\') {
        JB_FS_AppendByte( fs, FirstChar );
    }
    
    return NextRead;
}



// I can’t do entity validation properly here, because there are too many error conditions,
// and this class simply does not do validation. All it really needs to do, is parse
// correct conditions properly, and handle incorrect enities gracefully, not ruining the
// rest of the text that is valid.

//	>>>		>>>		>>>		>>>


JB_String* JB_MSR_ReplaceAll( Dictionary* Dict, JB_String* Data, FastString* fs_in, JB_ErrorReceiver* Rec ) {
    if (!Data) {
        return 0;
    }

	JB_String* EntityMarker = JB_Str__Byte( '&' );
	
    uint8* SearchStart = Data->Addr;
	uint8* SearchEnd = SearchStart + Data->Length;
    FastString* fs = fs_in;
	
	do {
        MiniStr FoundStr;
        MiniStr Input = {(int)(SearchEnd - SearchStart), SearchStart};
        JB_String* Found = (JB_String*)JB_Dict_Scan_(Dict, Input, &FoundStr);

        if (!fs) {
            if ( !Found ) {
                return Data;
            }
            fs = JB_FS_Constructor(0);
        }

		JB_FS_AppendMem_( fs, SearchStart, (int)(FoundStr.Addr - SearchStart) );
		if ( ! Found ) { break; }
		
        SearchStart = FoundStr.Addr + FoundStr.Length;
		if ( Found != EntityMarker ) {
			JB_FS_AppendMem_( fs, Found->Addr, Found->Length );
		} else {
			SearchStart = EntityRead_( fs, *FoundStr.Addr, SearchStart, SearchEnd, Rec );
		}
	} while ( true );

	auto Str = JB_FS_SmartResult( fs, fs_in );
	if (fs != fs_in)
		JB_FreeIfDead(fs);
	return Str;
}
	//	>>>		>>>		>>>		>>>


		

// combiner stuff. Good for UTF-8 processing!!
// maybe don't add it? Is it worth it?
int JB_MSR_CombiningCode( Dictionary* self, JB_String* Data ) {
	if ( Data ) {
		Data = (JB_String*)JB_Dict_Value( self, Data, 0 );
		if (Data) {
			if (Data->Length) {
				return *Data->Addr;
			}
			return -1; // error, shouldn't have 0 length as a combiner!!
		}
	}
	return 0;
}





struct CharList {
	uint8* Addr;
	uint8 Length;
	uint8 Score;
	CharList* Next;
};

inline CharList* CharNext_( CharList* C ) {
	return C->Next;
}

inline void CharNextSet_( CharList* C, CharList* N ) {
	C->Next = N;
}


CharList* ReorderArrays_( CharList* First ) {
	CharList* i = First;
	CharList Dummy;
	CharList* p = &Dummy;

	for ( ; i; i = CharNext_(i) ) {
		CharList* LowScore = i;
		CharList* pLow = i;
		CharList* j = CharNext_(i);

		for ( ; j; j = CharNext_(j) ) {
			if ( j->Score < LowScore->Score ) {
				LowScore = j;
			}
			pLow = j;
		}
		
		if (LowScore != i) { // should be more than i!!
			CharNextSet_( pLow, CharNext_(LowScore) );
			CharNextSet_( p, LowScore );
			CharNextSet_( LowScore, i );
			if (i == First) {
				First = LowScore;
			}
		}

		p = i;
	}
	
	return First;
}




		// Object Properties
    
void EntitySet_(Dictionary* self, JB_String* Key, bool Value) {
    JB_String* ent = 0;
    if (Value) {
        ent = JB_Str__Byte( '&' );
    }
    JB_Dict_ValueSet(self, Key, ent);
}

void JB_MSR_DecodeEntitySet(Dictionary* self, bool Value) {
    static JB_String* V;
    if (!V)
        V = JB_StrC("&#");
    EntitySet_( self, V, Value );
}

void JB_MSR_EscapeCodeSet(Dictionary* self, bool Value) {
    EntitySet_( self, JB_Str__Byte( '\\' ), Value );
}


} // 


