
#include "JB_Compress.h"
#include "JB_MemUtils.h"


extern "C" {
	// could replace these with calling libdeflate directly
	// less linker garbage.
	void  JB_GZIP_Free			(void* C);
	void* JB_GZIP_Alloc			(int Str);
	int   JB_GZIP_Max			(void* C, int Length);
	int   JB_GZIP_Compress		(void* C, const void* In, int Length, void* Out, int Space);
	int	  JB_GZIP_Decompress 	(void* C, const void* In, int* Length, void* Out, int Space);
	void  JB_GZIP_Free2			(void* C);
	void* JB_GZIP_Alloc2		();
}


struct DateLocker {
	atomic_int64	Value;
	bool			NoLongerNeeded;
	DateLocker  () {Value = 0; NoLongerNeeded=false;}
	void Unlock () {
		Value &= ~1;
	}
	void Lock () {
		Date Now = JB_Date__Now()|1;
		Date Expected;
		do {
			Expected = Value &~ 1;
		} while (!Value.compare_exchange_weak(Expected, Now));
	}
	bool StartClear (int Duration) {
		auto D = (Date)Value;
		require(D and !(D&1));										// its been used but not in-use
		require(NoLongerNeeded or JB_Date__Now() > D + Duration);	// enough time passed
		return Value.compare_exchange_weak(D, -1);
	}
	void Cleared () {
		NoLongerNeeded = false;
		Value = 0;
	}
};



static DateLocker		Allocator;
static u8*				Space;
static void*			GzipCompressor;
static int 				GzipStrength;


extern "C" void JB_CompFreeNow() {
	Allocator.NoLongerNeeded = true;
}

extern "C" int JB_BasicCareTaker(PicoDate D) {
	#if __JB_PRINTF__
	static PicoDate			JB_LastFlush;
	if (D - JB_LastFlush >= 64*1024) { // one second.
		JB_LastFlush = D;
		fflush(stdout); // hmmm. but we don't use printf?
	}
	#endif

	if (Allocator.StartClear(10*64*1024)) {	// 10s ago!
//		JB_GZIP_Free(GzipCompressor);
		GzipCompressor = 0;
		GzipStrength = 0;
		JB_Free(Space);
		Space = 0;
		Allocator.Cleared();
	}
	return 0;
}

#include "CompressMz.i"
//#include "CompressGzip.i"

