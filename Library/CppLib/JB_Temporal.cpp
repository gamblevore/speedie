
//  
//  Generate temporal number stream: © 2019-2020 Theodore H. Smith
//  Could be used in almost anything! Even games :3
//  Can we make a computer FEEL Psychic energy?
//  2025: I might remove some of this? What if we can just get temporal info via the VM?

#include "JB_BasicTypes.h"
#include "JB_Temporal.h"
#include "JB_Math.h"
#ifdef __APPLE__
	#include <mach/mach_time.h>
#endif

#define for_(count)			for (int i = 0; i < (count); i++)
typedef u8					uSample;

#define Time_(R)			TimeInit(); u32 Finish = 0; while (Data < DataEnd) { u32 Start = Time32(); for_(R)
#define TimeEnd 			; Finish = Time32(); *Data++ = TimeDiff(Start,Finish);} TimeFinish();
#define SlowTime_(R)							\
	u32 MinTime = TimeInit();					\
	while (Data < DataEnd) {					\
		u32 Score = 0;							\
		u32 Start = Time32();					\
		u32 Finish = Start + (Reps*MinTime);	\
		while (true) {							\
			Score++;							\
			u32 T = Time32();					\
			if (T<Start or T >= Finish) break; 
#define SlowTimeEnd };							\
		*Data++ = Score;						\
	} TimeFinish();
#define Gen(name) 			u64 name##Generator (uSample* Data, uSample* DataEnd, u32 Input, int Reps)

extern "C" {

#define Time32() (u32)(RDTSC())


static inline void TimeFinish () {}

static inline int TimeInit () {
	auto A = Time32();
	while (1) {
		auto B = Time32();
		if (B!=A)
			return B-A;
	}
}


static int TimeDiff (s64 A, s64 B) {
	s64 D = B - A;
	return (int)D;
}


//	 							//////// Generators ////////	 

Gen(FloatSame) {
	const float x0 = Input + 1;
	const float y0 = Input + 1;
	float x = 0;
	float y = 0;
	Time_ (Reps) {
		x = x0;
		y = y0;
		y = y + 1000.5;
		x = x / 2.0;
		x = fmodf(x,2.0) - (x / 10000000.0);
		x = floor(x)	 - (x * 5000000.0);
		x = fminf(x, MAXFLOAT);
		y = fmaxf(y,-MAXFLOAT);
		x += y;
	} TimeEnd
	
	return x;
}


Gen(Time) {
	u32 x = Input;
	Time_ (Reps) {
		x = x xor Time32();
		x = x xor Time32();
	} TimeEnd

	return x;
}


Gen(Bool) {
	bool f = (Input == 0);
	bool t = (((int)Input) < 1);
	
	Time_ (Reps) {
		f = f and t;
		t = t or f;
		t = f or t;
		f = t and f;
	} TimeEnd
	
	return f;
}


Gen(BitOps) {
	u64 x = Input + 1;
	u64 y = Input + 1;
	Time_ (Reps) {
		y = y + 981723981723;
		x = x xor (x << 63);
		x = x xor (x >> 59);
		x = x xor (x << 5);
		x += y;
	} TimeEnd
	
	return x;
}



std::atomic<u64> ax;
std::atomic<u64> ay;
Gen(Atomic) {
	ax = Input + 1;
	ay = Input + 1;
	Time_ (Reps) {
		ay = ay + 981723981723;
		ax = ax xor (ax << 63);
		ax = ax xor (ax >> 59);
		ax = ax xor (ax << 5);
		ax += ay;
	} TimeEnd
	
	return ax;
}


Gen(Memory) {
	u32 CachedMemory[1024]; // 4KB of data.
	u32 x = Input;
	u32 Place = 0;
	Time_ (Reps) {
		u32 index = Place++ % 1024;
		x = x xor CachedMemory[index];
		CachedMemory[index] = x;
	} TimeEnd
	
	return x;
}


Gen(SlowPlus) {
	int x = Input + 1;
	SlowTime_ (Reps) {
		x = x + 3;
	} SlowTimeEnd
	
	return x;
}


Gen(SlowMemory) {
	u32 CachedMemory[1024]; // 4KB of data.
	u32 x = Input;
	u32 Place = 0;
	SlowTime_ (Reps)
		u32 index = Place++ % 1024;
		x = x xor CachedMemory[index];
		CachedMemory[index] = x;
	SlowTimeEnd
	
	return x;
}




Gen(Chaotic) {
	u32 CachedMemory[1024]; // 4KB of data.
	const float fx0 = Input + 1;
	const float fy0 = Input + 1;
	ax = Input + 1;
	ay = Input + 1;
	float fx = 0;
	float fy = 0;
	u32 f = (Input == 0);
	u64 x = Input + 1;
	u64 y = Input + 1;
	u32 Place = 0;
	u32 index = 0;


	const void* ChaosTable[] = {&&Floats, &&Time, &&Bool, &&Floats2, &&Atomic2, &&BitOps, &&Atomic, &&Memory};

	Time_ (Reps) {
		u32 Index = Finish >> ((i^x)%32); 
		goto* ChaosTable[(Index^i)%8];

Floats:
		fx = fx0;
		fy = fy0;
		fy = fy + 1000.5;
		fx = fx / 2.0;
		x = fx;
		goto Finish;
		
Floats2:
		fx = floor(fx)	 - (fx * 5000000.0);
		fx += fy + 1.0;
		x = fx;
		goto Finish;

Time:
		x = x xor Time32();
		x = x xor Time32();
		goto Finish;

Bool:
		f = (f&1) and (x&1);
		x = (bool)x or (bool)f;
		x = (bool)f or (bool)x;
		f = (bool)x and (bool)f;
		goto Finish;
		
BitOps:
		y = y + 981723981723;
		x = x xor (x << 63);
		x = x xor (x >> 59);
		x = x xor (x << 5);
		x += y;
		goto Finish;

Atomic:
		ay = ay + 981723981723;
		ax = ax xor (ax << 63);
		x = ax;
		goto Finish;

Atomic2:
		ax = ax xor (ax >> 59);
		ax = ax xor (ax << 5);
		ax += ay;
		x = ax;
		goto Finish;
		
Memory:
		index = Place++ % 1024;
		x = x xor CachedMemory[index];
		CachedMemory[index] = (u32)x;
		goto Finish;

Finish:;
	} TimeEnd
	
	return x + (int)fx;
}




Gen(Sudo) { // just to test our numerical strength.
	static u64 Oof = 9709823597812817ULL;
	u64 x = Oof;

	while (Data < DataEnd) {
		x = JB_uint64_hash(x);
		*Data++ = (u32)x;
	}

	Oof = x;
	return 0;
}



JB_TemporalGenerator TmpGenList[] = {
	{	SudoGenerator,			"pseudo",	10	},
	{	FloatSameGenerator,		"float",	10	},
	{	AtomicGenerator,		"atomic",	40	}, // 4x slower
	{	BoolGenerator,			"bool",		10	},
	{	BitOpsGenerator,		"bitops",	10	},
	{	MemoryGenerator,		"memory",	10	},
	{	TimeGenerator,			"time",		10	},
	{	ChaoticGenerator,		"chaotic",	10	},
	{	SlowPlusGenerator,		"plusARM",	0	},
	{	SlowMemoryGenerator,	"memoryARM",0	},
};

extern "C" JB_TemporalGenerator* JB_Tmp__Gen(uint i) {
	uint n = sizeof(TmpGenList) / sizeof(JB_TemporalGenerator);
	if (i < n)
		return &TmpGenList[i];
	return 0;
}

};
