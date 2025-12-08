

/*
 *  JB_Umbrella.hpp
 *
 */

#ifndef  __JB_UMBRELLA__
#define  __JB_UMBRELLA__

#include "JB_LibTypes.h"
#include <math.h>
#include <cmath> // somehow both are needed for OSX ARM vs OSX Intel. Sigh.
#include "StringFunctions.h"
#include "StringFunctionsLib.h"

#include "JB_SafeIncludes.h"
#include "JB_String.h"
#include "JB_File.h"
#include "JB_Errors.h"
#include "JB_Pipe.h"
#include "JB_FastString.h"
#include "JB_ByteMap.h"
#include "JB_Vectors.h"
#include "JB_Dict.h"
#include "JB_DictCore.h"
#include "JB_MSR.h"
#include "JB_Math.h"
#include "JB_Vec4.h"
#include "JB_Tokeniser.h"
#include "JB_List.h"
#include "JB_ListOld.h"
#include "JB_ByteArray.h"
#include "JB_ObjArray.h"
#include "JB_Date.h"
#include "JB_FileLister.h"
#include "JB_Linkage.h"
#include "JB_Temporal.h"


// game stuff...
#ifndef AS_LIBRARY
#include "JB_GameSmall.h"
#include "JB_GameAll.h"
#endif


#include <stdlib.h>
#include <string.h>
#include "JB_Atomic.h"
#include "PicoMsg.h"


#endif // __JB_UMBRELLA__



