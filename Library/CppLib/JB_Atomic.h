

#include <atomic>
extern "C" {
	typedef std::atomic<unsigned char> atomic_byte;
	typedef std::atomic<unsigned int> atomic_uint;
	typedef std::atomic<unsigned short> atomic_uint16;
	typedef std::atomic<unsigned long long> atomic_uint64;

	typedef std::atomic<char> atomic_char;
	typedef std::atomic<int> atomic_int;
	typedef std::atomic<short> atomic_int16;
	typedef std::atomic<long long> atomic_int64;
} // ExternCEnd

