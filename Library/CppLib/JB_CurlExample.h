
// This is unused testing code.

// I don't want curl in my std-lib... too many dependancies.

// Perhaps I could dlopen/dlsym curl. But from the C++ libs, not the 
// cake side of things. Speedie's dylib importer can't use curl,
// which unfortunately, relies on va_arg... which is impossible
// for me to write the ASM in my CakeVM, in any reasonable time.

// UGH i hated this. Wasted 2 or more days of stress on curl/dylib efforts.

// I can get it working just for C++ compiles, but then you can't debug it.
// Or put it into the lib directly, like below. But then we get dependancies.

// I just want this to end, for now.


#ifndef __JB_NETWORK__
#define __JB_NETWORK__
#include <curl/curl.h>

extern "C" {

static CURL* curl;

static size_t CurlToJB (void *contents, size_t size, size_t nmemb, FastString* FS) {
	auto realsize = size * nmemb;
	JB_FS_AppendMem_(FS, (u8*)contents, (int)realsize);
	return realsize;
}


int JB_FS_AppendURL (FastString* self, JB_StringC* URL, uint64 Timeout, JB_StringC* Cookie ) {
	const char* url = (const char*)URL->Addr;
	if (!curl) {
		curl_global_init(CURL_GLOBAL_DEFAULT);
		curl = curl_easy_init();
		if (!curl) {
			return JB_ErrorHandleFileC(url, -1, "init curl");
		}

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlToJB);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
//		curl_easy_setopt(curl, CURLOPT_CA_CACHE_TIMEOUT, 86400); // harder to compile with this.
	}

	curl_easy_setopt(curl, CURLOPT_COOKIE, Cookie->Addr);
	
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, self);
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, (int)((float)Timeout / 65.536));
	CURLcode err = curl_easy_perform(curl);
	if (!err) {
		return 0;
	}
	JB_ErrorHandleC(curl_easy_strerror(err), URL, 0);
	return err;
}

void JB_Curl_Cleanup () {
	if (curl) {
		curl_easy_cleanup(curl);
		curl_global_cleanup();
		curl = 0;
	}
}
