
#include "JB_Compress.h"
#include "JB_MemUtils.h"


extern "C" {
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
	void unlock () {
		Value &= ~1;
	}
	void lock () {
		Date Now = JB_Date__Now()|1;
		Date Expected;
		do {
			Expected = Value &~ 1;
		} while (!Value.compare_exchange_weak(Expected, Now));
	}
	bool start_clear (int Duration) {
		auto D = (Date)Value;
		require(D and !(D&1));										// its been used but not in-use
		require(NoLongerNeeded or JB_Date__Now() > D + Duration);	// enough time passed
		return Value.compare_exchange_weak(D, -1);
	}
	void cleared () {
		NoLongerNeeded = false;
		Value = 0;
	}
};

static PicoDate			JB_LastFlush;
static DateLocker		Allocator;
static void*			Compressor;
static void*			DeCompressor;
static int 				OldStr;

 
extern "C" int CompressionFree(int X) {
	if (Allocator.start_clear(X)) {
		JB_GZIP_Free(Compressor);
		Compressor = 0;
		OldStr = 0;
		Allocator.cleared();
	}
	return 0;
}

extern "C" void JB_CompFreeNow() {
	Allocator.NoLongerNeeded = true;
}

extern "C" int JB_BasicCareTaker(PicoDate D) {
	if (D - JB_LastFlush >= 64*1024) { // one second.
		JB_LastFlush = D;
	#if __PRINTF__
		fflush(stdout); // hmmm. but we don't use printf?
	#endif
	}

	return CompressionFree(10*64*1024);	// 10s ago!
}


const int MaxCompressSize = 16*1024*1024;
int CompressStrong (FastString* fs, JB_String* self, int Str) {
	if (Str < 1)  Str = 1;
	if (Str > 12) Str = 12;
    if (OldStr != Str) {
		if (Compressor) {
			OldStr = 0;
			JB_GZIP_Free(Compressor);
		// it should be possible to alter libdeflate_alloc_compressor
		// so we don't need to realloc. but lets do that AFTER getting it to work.
		}
		Compressor = JB_GZIP_Alloc(Str);
		if (!Compressor)
			return 0;
		OldStr = Str;
	}

    int Req = JB_GZIP_Max(Compressor, self->Length);
    auto Buff = JB_FS_WriteAlloc_(fs, Req);
    if (!Buff)
		return 0;
	
    int Actual = (int)JB_GZIP_Compress(
        Compressor,
        self->Addr,
        self->Length,
        Buff,
        Req
    );

	JB_FS_AdjustLength_( fs, Req, Actual );
    return Actual;
}



extern "C" int JB_Str_CompressChunk (FastString* fs, JB_String* self, int Level) {
	Allocator.lock();
	int rz = CompressStrong(fs, self, Level);
	Allocator.unlock();
	return rz;
}





static uint GZIP_Size (const unsigned char* data, uint n) {
    if (n < 18)
        return 0; 
    return ((uint*)(data + n - 4))[0];
}


// yikes. what a f(&*@£Y$EOKJNING battle!
extern "C" int JB_Str_DecompressChunk (FastString* fs,  JB_String* self) {
	int Req = GZIP_Size(self->Addr, self->Length);
	
	while (Req > 0 and Req < 1024*1024*256) {
		auto Buff = JB_FS_WriteAlloc_(fs, Req);
		if (!Buff)
			return 0;
		
		if (!DeCompressor) {
			DeCompressor = JB_GZIP_Alloc2();
			if (!DeCompressor)
				return 0;
		}

		int Used = self->Length;
		int Actual = (int)JB_GZIP_Decompress(
			DeCompressor,
			self->Addr,
			&Used,
			Buff,
			Req
		);
		if (Actual >= 0) {
			JB_FS_AdjustLength_( fs, Req, Actual );
			return Used;
		}
		JB_FS_AdjustLength_( fs, Req, 0 );
		if (-Actual <= 2) {		// corrupt!
			if (-Actual == 2)	// too few bytes? how is that a problem?
				debugger;
			return 0;
		}
		Req = std_max(Used, Req*2); // not enough data!
	}
	return 0;
}


