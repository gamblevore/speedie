

void* libdeflate_alloc_compressor (int);

int CompressGZIP (FastString* fs, JB_String* self, int Str) {
	if (Str < 1) Str = 1;
	if (Str > 9) Str = 9;
    if (GzipStr != Str) {
		if (GzipCompressor) {
			GzipStr = 0;
			JB_GZIP_Free(GzipCompressor);
		// it should be possible to alter libdeflate_alloc_compressor
		// so we don't need to realloc. but lets do that AFTER getting it to work.
		}
		

		GzipCompressor = libdeflate_alloc_compressor(Str);
		if (!GzipCompressor)
			return 0;
		GzipStr = Str;
	}

    int Req = JB_GZIP_Max(GzipCompressor, self->Length);
    auto Buff = JB_FS_WriteAlloc_(fs, Req);
    if (!Buff)
		return 0;
	
    int Actual = (int)JB_GZIP_Compress(
        GzipCompressor,
        self->Addr,
        self->Length,
        Buff,
        Req
    );

	JB_FS_AdjustLength_( fs, Req, Actual );
    return Actual;
}



extern "C" int JB_Str_CompressGZIP (FastString* fs, JB_String* self, int Level) {
	Allocator.Lock();
	int rz = CompressGZIP(fs, self, Level);
	Allocator.Unlock();
	return rz;
}



static uint GZIP_Size (const unsigned char* data, uint n) {
    if (n < 18)
        return 0; 
    return ((uint*)(data + n - 4))[0];
}


// yikes. what a f(&*@£Y$EOKJNING battle!
// let's assume it is ONE blob, only. Not more.
extern "C" int JB_Str_DecompressGZIP (FastString* fs,  JB_String* self) {
	int Req = GZIP_Size(self->Addr, self->Length);
	
	while (Req > 0 and Req < 1024*1024*256) {
		auto Buff = JB_FS_WriteAlloc_(fs, Req);
		if (!Buff)
			return 0;
		
		static void* GzipDeCompressor;
		if (!GzipDeCompressor) {
			GzipDeCompressor = JB_GZIP_Alloc2();
			if (!GzipDeCompressor)
				return 0;
		}

		int Used = self->Length;
		int Actual = (int)JB_GZIP_Decompress(
			GzipDeCompressor,
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

