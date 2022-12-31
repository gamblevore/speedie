

#ifndef kJB__int_max
#define kJB__int_max (0x7FFFffff)
#define kJB__int_min (0x80000000)
struct JB_String;
struct ByteMap;
struct FastString;
struct Tokeniser;
struct Dictionary;
struct DictionaryReader;
struct TokHan;
struct RingTree;
struct JB_StringShared;
#ifndef __MM_SUCKS__ 
constexpr int operator"" _K(unsigned long long x) { return (int)x * 1024; } 
constexpr int operator"" _M(unsigned long long x) { return (int)x * 1024 * 1024; }
#endif 
#endif
