
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
 Copyright (C) 2009 Theodore H. Smith.
*/


#include "JB_Umbrella.hpp"

extern "C" {

////////////////////////////////////////////////////////////////////////////////
		// Module
////////////////////////////////////////////////////////////////////////////////
static Tokeniser Tok;
static JB_String* _PzData;

////////////////////////////////////////////////////////////////////////////////
JB_String* JB_Tk__GetData () {
    return _PzData;
}


int JB_Tk__ErrorStart () {
    return Tok.ErrorStart;
}

void JB_Tk__ErrorStartSet (int Start) {
    Tok.ErrorStart = Start;
}

byte JB_Tk__Byte (int S) {
	return JB_Str_ByteValue(_PzData, S);
}

JB_String* JB_Tk__Range (int S, int E) {
	return JB_Str_Range(_PzData, S, E);
}


////////////////////////////////////////////////////////////////////////////////

inline bool Running_( u32 NextStart ) {
	return  (NextStart < _PzData->Length)  and  (Tok.ErrorStart < 0);
}

void JB_Tk__ErrorEvent(int A, int B, int C);



////////////////////////////////////////////////////////////////////////////////

bool JB_Tk__CppInited() {
    if (JB_RefCount(&Tok)) {
        return true;
    }
    
    Dictionary* Dict = JB_Dict_Constructor(0);
	Tok.WordDict = Dict;
    JB_SetRefCount(&Tok, 1000);
    JB_SetRefCount(Dict, 1000);
    JB_Dict_ValueSet(Dict, JB_Str__Empty(), JB_NewEmpty(TokHan));
    return false;
}


void JB_Tk__Clear(  ) { // never called
	JB_SetRef( _PzData, 0 );
	JB_SetRef( Tok.WordDict, 0 );
    JB_Zero(&Tok);
}

////////////////////////////////////////////////////////////////////////////////


int JB_Tk__NextByte() {
    byte* B = _PzData->Addr; 
    if (B) {
        int L = _PzData->Length;
        int N = Tok.NextStart;
        if (N < L) {
            byte b = B[N];
            return b;
        }
    }
    return -1;
}


bool JB_Tk__EatString(JB_String* S) {
    byte* DataAddr = _PzData->Addr; 
    if (DataAddr) {
        int SLength = S->Length;
        int DataPos = Tok.NextStart; 
        if (DataPos + SLength <= _PzData->Length) {   
            DataAddr += DataPos; 

            for (int i = 0; i < SLength; i++) {
                if (DataAddr[i] != S->Addr[i]) {
                    return false;
                }
            }

            Tok.NextStart += SLength;
            return true;
        }
    }
    
    return false;
}


void JB_Tk__NextStartSet( u32 NextStart ) {
	if ( NextStart < _PzData->Length ) { // 0 - 1 = 4billion!
		Tok.NextStart = NextStart;
	} else {
        Tok.NextStart = _PzData->Length; // Not Running
	}
}


int JB_Tk__NextStart(  ) {
    return Tok.NextStart;
}


void JB_Tk__StartParse (JB_String* Data) {
	Tok.NextStart = 0;
	Tok.ErrorStart = -1;
	if ( ! Data ) {
		JB_SetRef( _PzData, JB_Str__Empty() );
		return;
	}
#if DEBUG
	if ((Tok.WordDict->Width) != 255) // hmmm???
		debugger;
#endif
	JB_SetRef( _PzData, Data );
	JB_String BOM = {};
	BOM.Length = 3;
	BOM.Addr = (u8*)"\xEF\xBB\xBF";
	JB_Tk__EatString(&BOM);
}


JB_Object* DummyTokHan_( int TokenAfter );


void SetBits_(TokHan* T, u32 BitTypes, fpTok Func) {
	dbgexpect(Func)
	dbgexpect(BitTypes == -1 or BitTypes < 1<<kTokHanSize);
	for (u32 i = 0; i < kTokHanSize; i++) {
		u32 x = (1 << i);
		if (BitTypes & x) {
			T->Func[i] = Func;
		}
	}
}



void TH_Copy_( TokHan* T, TokHan* F ) {
	T->BitTypes |= F->BitTypes;
	for (int i = 0; i < kTokHanSize; i++) {
        fpTok fp = F->Func[i];
        if (fp) {
            T->Func[i] = fp;
        }
	}
}


TokHan* JB_Tk__Token(JB_String* s) {
    return (TokHan*)JB_Dict_Value(Tok.WordDict, s, 0);
}


void JB_Tk__TokenSet( JB_String* TokStr, TokHan* New_ ) {
    if (!New_) {
        return;
    }
    auto Debug = &Tok;
    JB_Object** Place = JB_Dict_MakePlace(Debug->WordDict, TokStr);
    dbgexpect(Place);
    TokHan* Old_ = (TokHan*)(*Place);

    if (Old_) {
        if (JB_RefCount(Old_)==1) { // optimisation :)
            TH_Copy_(Old_, New_);
            return;
        } else {
            TokHan* Cpy = JB_NewEmpty( TokHan );
            TH_Copy_(Cpy, Old_);
            TH_Copy_(Cpy, New_);
            New_ = Cpy;
        }
    }
    JB_SetRef_(Place, New_);
}


///


//////////////////////////////////////////////////////////////////////////////////////////

int JB_Tk__CleanSpacesSub ( int S ) {
	JB_String* D = _PzData;

    uint8* A = D->Addr;
	int N = D->Length;
	
	while (S < N) {
		auto c = A[S++]; 
		if (c != '\t' and c != ' ') {
			if (c=='\\' and S<N) {
				auto c2 = A[S++];
				if (c2 == '\r' or c2=='\n')
					continue; // its just a space lol.
				S--;
			}
			return S-1;
		}
	}

	Tok.NextStart = N;
	return S;
}


int JB_Tk__ClearIndent() {
	// merge with CleanSpacesSub?
	JB_String* D = _PzData;

    uint8* A = D->Addr;
	uint8* Finish = A + D->Length;
	A += Tok.NextStart;
	int Count = 0;
	
	while (A < Finish) {
		if (*A != '\t') {
			while (A < Finish) {
				if (*A != ' ') {
					Tok.NextStart = (int)(A - D->Addr); 
					return Count;
				}
				Count++;
				A++;
			}
		}
		Count += 4;
		A++;
	}

	return 0;
}


int JB_Tk__CleanSpaces() {
	return Tok.NextStart = JB_Tk__CleanSpacesSub(Tok.NextStart);
}


//////////////////////////////////////////////////////////////////////////////////////////

Message* JB_Tk__Process( u32 AskBits, long Mode, Message* Parent ) {
	if_rare ( Tok.ErrorStart >= 0 )
		return 0;
	
	u32 Start = JB_Tk__CleanSpacesSub( Tok.NextStart );
	MiniStr AL = Mini(_PzData, Start);
	ObjLength Found = JB_Dict_LongestKey_( Tok.WordDict, AL );
	TokHan* FatData = (TokHan*)Found.Obj;
	
	u32 FoundBits = FatData->BitTypes;
	u32 MatchBits = FoundBits & AskBits;
	
	if ( MatchBits ) {
		u32 Undo = Tok.NextStart;
		Tok.NextStart = Start + Found.Length;
		fpTok Func = FatData->Func[JB_Int_Log2(MatchBits)];
		Message* Result = (Message*)((Func)( Start, Parent ));
		if ( Result )
			return Result;
		
		Tok.NextStart = Undo;
	}
	
	if_rare ( Mode == 1 or FoundBits == -1)
		if ( Tok.ErrorStart < 0 )
			JB_Tk__ErrorEvent( Start, AskBits, FoundBits );
	
	return 0;
}

	
////////////////////////////////////////////////////////////////////////////////


bool JB_Tk__Running(  ) {
	return Running_( Tok.NextStart );
}

bool JB_Tk__Expect( u32 AskBits ) {
	return JB_FreeIfDead((JB_Object*)JB_Tk__Process( AskBits, 1, nullptr ));
}

bool JB_Tk__Allow( u32 AskBits ) {
	return JB_FreeIfDead((JB_Object*)JB_Tk__Process( AskBits, 0, nullptr ));
}


bool JB_Tk__Consume( u32 AskBits, int Expect ) {
	bool FoundAny = false;
	while ( JB_FreeIfDead((JB_Object*)JB_Tk__Process( AskBits, Expect, nullptr ) ) ) {
		FoundAny = true;
	};
	return FoundAny;
}


bool JB_Tk__CheckEnded ( u32 AskBits ) { // has to be called with an "ender". ") } > ]", "CR/LF", ","
	int NextStart = Tok.NextStart;
	bool Result = JB_Tk__Allow(AskBits) or !JB_Tk__Running();
	Tok.NextStart = NextStart;
	return Result;
}



////////////////////////////////////////////////////////////////////////////////
		// TokenHandler
////////////////////////////////////////////////////////////////////////////////


void JB_Tk__TokenNilSet( JB_String* Key, JB_Object* Value ) {
    JB_Object* Curr = JB_Dict_Value( Tok.WordDict, Key, 0 );
    if (!Curr) {
        JB_Dict_ValueSet(Tok.WordDict, Key, Value);
    }
}


TokHan* JB_TH_Link(TokHan* T, u32 BitTypes, fpTok Func) {
	T->BitTypes |= BitTypes;
	SetBits_( T, BitTypes, Func );
    return T;
}

    
TokHan* JB_Tk__Handler( int BitTypes, fpTok Func ) {
    return JB_TH_Link( JB_NewEmpty( TokHan ), BitTypes, Func );
}



////////////////////////////////////////////////////////////////////////////////
	
} // 

