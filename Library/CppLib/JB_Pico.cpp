
#define PICO_IMPLEMENTATION
#include "PicoMsg/PicoMsg.h" // awesome new message system
// :O 😇😮😵😇😮😵😇🤯😮😮🤯😮😇😮😵😇😮😮😇😮😵😮😮😮
extern "C" const char** JB_App__BackTrace(void** space, int* size) _pico_code_ (
    *size = backtrace( space, *size );
    return (const char**)backtrace_symbols( space, *size );
)

// AMAAZING
