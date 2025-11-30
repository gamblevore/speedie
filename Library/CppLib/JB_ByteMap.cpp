
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.hpp"
//
// 
extern "C" {
/// bytemap was removed!
//// hahahah
//// i need a freaking holiday
//// and a dimensional spceship out of this reality.
inline void InitCharset_(CharSet* cs, uint8* SelfPos, u32 Len, bool Ranges) {
	uint8* Cache = cs->Cache;
    uint8* ReadEnd = SelfPos + Len;
    
	if (!Ranges) {
		while ( SelfPos < ReadEnd ) {
			Cache[ *SelfPos++ ] = 1;
		}
	} else {
		while ( SelfPos < ReadEnd ) {
			uint8 c = *SelfPos++;
			uint8 c2 = *SelfPos++;
			int a = Min( c, c2 );
			int b = Max( c, c2 );

			for ( ; a <= b; a++) {
				Cache[ a ] = 1;
			}
		}
	}
}
//
//
//void JB_BM_Clear( ByteMap* cs, int F ) {
//	uint8* Cache = cs->Cache;
//	for ( int i = 0; i < 256; i++ ) {
//		if (F < 0)
//			Cache[i] = i;
//		  else
//			Cache[i] = F;
//	}
//}
//
//
CharSet* JB_CS_Constructor(CharSet* self, JB_String* Source, bool Ranges) {
	JB_New2(CharSet);
	MemZero( self->Cache );
	if ( Source )
		InitCharset_( self, Source->Addr, Source->Length, Ranges );
	return self;
}
//
//
CharSet* JB_CS_Invert( CharSet* self ) {
    uint8* Cache = self->Cache;
    CharSet* Result = JB_NewEmpty( CharSet );
    if (Result) {
		uint8* CacheResult = Result->Cache;
		for_(256)
			CacheResult[i] = Cache[i]==0;
	}
    return Result;
}
//
//
//ByteMap* JB_BM_Invert( ByteMap* self, int Unfound ) {
//    uint8* Old = self->Cache;
//    ByteMap* Result = JB_NewEmpty( ByteMap );
//    require(Result);
//	JB_BM_Clear(Result, Unfound);
//    
//    uint8* New = Result->Cache;
//    for_(256) {
//        auto C = Old[i];
//        if (Old[C] != C) {
//            New[C] = (uint8)i;
//        }
//    }
//    
//    return Result;
//}
//
//
JB_String* JB_CS_Render(CharSet* self, FastString* fs_in) {
	uint8* Cache = self->Cache;
	FastString* fs = JB_FS__FastNew( fs_in );
    JB_FS_SizeSet(fs, 256);
	
	for_(256)
		if ( Cache[i] )
			JB_FS_AppendByte( fs, i );

	return JB_FS_SmartResult( fs, fs_in );
}
//
//
//uint8 JB_BM_Access( ByteMap* self, int Value ) {
//	if ((u32)Value<=255) 
//		return self->Cache[Value];
//	return -1;
//}
//void JB_BM_AccessSet( ByteMap* self, int S, int D ) {
//	if ((u32)S<=255) 
//		self->Cache[S] = D;
//}
//
//
bool JB_CS_HasChar( CharSet* self, int Value ) {
    if ((u32)Value <= 255)
        return self->Cache[Value];
    return false;
}

void JB_CS_HasCharSet( CharSet* self, int Value, bool Set ) {
    if ((u32)Value <= 255) {
		self->Cache[Value] = Set;
	}
}
//
//inline void JB_BM_MapWrite( ByteMap* cs, uint8* fr, uint8* tr, int Len) {
//    while ( Len-- ) {
//        cs->Cache[ *fr++ ] = *tr++;
//    }
//}
//
//
//ByteMap* JB_BM_Constructor( ByteMap* self, JB_String* From, JB_String* To ) {
//	JB_New2(ByteMap);
//	JB_BM_Clear( self, -1 );
//    int Len = Min( JB_Str_Length( From ), JB_Str_Length( To ) );
//    if ( Len )
//        JB_BM_MapWrite( self, (uint8*)JB_Str_Address(From), (uint8*)JB_Str_Address(To), Len );
//    return self;
//}
//
//
//
//
} // 
//
//
