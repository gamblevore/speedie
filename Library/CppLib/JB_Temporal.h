
#include "JB_BasicTypes.h"

#ifndef __TEMPORAL__
#define __TEMPORAL__
typedef u64 (*fpTemporal) (uint* Data, uint* DataEnd, uint Input, int Reps);

struct JB_TemporalGenerator {
	fpTemporal		Steve;
	const char*		Name;
	u8       		Slowness;
};

extern "C" JB_TemporalGenerator* JB_Tmp__Gen(uint i);

#endif