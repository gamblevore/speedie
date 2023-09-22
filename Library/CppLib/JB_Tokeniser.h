
/*
 Copyright (C) 2009 Theodore H. Smith.
 */



#ifndef __JB_Str_TOKENISER__
#define __JB_Str_TOKENISER__

#include "JB_Umbrella.h"
#define kTokHanSize 23


extern "C" {

    struct NodeArrayShift;
	typedef void (*TokErrorEvent)(int Start, int ExpectedBits, int RealBits );
	typedef JB_Object* (*fpTok)( int TokenAfter, Message* Parent );
	
	
	JBClass( TokHan, JB_Object,
		fpTok			Func[kTokHanSize];
		int             BitTypes;
	);
	
	
	JBClass( Tokeniser, JB_Object,
// could be "owned"
		TokErrorEvent		ErrorEvent;
        Dictionary*			WordDict;

// these could be moved into an object for concurrency... make it thread-local... function passes it to "self" param...
        int					ErrorStart;
		
		int					NextStart;
        //bool                ErrorImprove;
	);
	
	
	struct Message;
    void JB_Tk__TokenNilSet( JB_String* Key, JB_Object* Value );
	int JB_Tk__ClearIndent ();
    int JB_Tk__CleanSpaces (  );
	void JB_Tk__Constructor(  );
	void JB_Tk__Destructor(  );
	void JB_Tk__TokenSet( JB_String* TokStr, TokHan* Stuff );
    TokHan* JB_Tk__Token(JB_String* s);
    int JB_Tk__NextByte();
    bool JB_Tk__EatByte(byte b);
    bool JB_Tk__EatString(JB_String* s);
    bool JB_Tk__CppInited();    
    JB_String* JB_Tk__Data();
	void JB_Tk__StartParse( JB_String* Data );
	void JB_Tk__NextStartSet( u32 NextStart );
	bool JB_Tk__Running(  );
	Message* JB_Tk__Process( u32 AskBits, long Mode, Message* Parent );
    void JB_Tk__NeedsErrorImprove();
	bool JB_Tk__Expect( u32 AskBits );
	bool JB_Tk__Allow( u32 BitTypes );
	bool JB_Tk__Consume( u32 AskBits, int f );
	bool JB_Tk__CheckEnded( u32 AskBits );
	int JB_Tk__MessageIndent ( u32 N );
    TokHan* JB_Tk__Handler( int BitTypes, fpTok FuncName );

    int JB_Tk__NextStart(  );
    int JB_Tk__ErrorStart ();
    void JB_Tk__ErrorStartSet (int Start);
	byte JB_Tk__Byte (int P);
	JB_String* JB_Tk__Range (int S, int E, byte F);
    JB_String* JB_Tk__Data ();
    void JB_Tk__DataSet (JB_String* Data);
    void JB_Tk__ErrorEventSet (TokErrorEvent fp);

    TokHan* JB_TH_Link(TokHan* self, u32 BitTypes, fpTok FuncName);
    

} // ExternCEnd



#endif

