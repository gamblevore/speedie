
// Copyright, Theodore H. Smith 2023.
// Released under jeebox-licence http://jeebox.org/licence.txt

#if !defined(__JB_NETWORK__)
	void JB_CurlStub();
#else



#include "JB_Umbrella.hpp"
#include <curl/curl.h>

extern "C" {

//*
static CURL* curl;

static size_t CurlToJB (void *contents, size_t size, size_t nmemb, FastString* FS) {
	auto realsize = size * nmemb;
	JB_FS_AppendMem_(FS, (u8*)contents, (int)realsize);
	return realsize;
}

// OK... so can (Should?) we do this async? well... basically i don't need async. So why write it???
// just cos its hard? I DONT NEED IT. We can just set a timeout... thats all.

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

	if (JB_Str_Length(Cookie))
		curl_easy_setopt(curl, CURLOPT_COOKIE, Cookie->Addr);
	  else
		curl_easy_setopt(curl, CURLOPT_COOKIE, "");
	
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
//*/
}

#endif
