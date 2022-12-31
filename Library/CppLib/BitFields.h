
#include "InstructionGetters.h"

#define l1      U1_Li
#define l2      U2_Li
#define l3      U3_Li
#define l4      U4_Li
#define L1      U1_Lu
#define L2      U2_Lu
#define L3      U3_Lu
#define L4      U4_Lu
#define n1      ((Op<< 7)>>27)
#define n2      ((Op<<12)>>27)
#define n3      ((Op<<17)>>27)
#define n4      ((Op<<22)>>27)
#define i1      (r[n1])
#define i2      (r[n2])
#define i3      (r[n3])
#define i4      (r[n4])
#define p1(x)   ((x*)(((s64*)r)[n1]))
#define p2(x)   ((x*)(((s64*)r)[n2]))
#define p3(x)   ((x*)(((s64*)r)[n3]))
#define p4(x)   ((x*)(((s64*)r)[n4]))
#define u1      (((u64*)r)[n1])
#define u2      (((u64*)r)[n2])
#define u3      (((u64*)r)[n3])
#define u4      (((u64*)r)[n4])
#define f1      (*(float*)&i1)
#define f2      (*(float*)&i2)
#define f3      (*(float*)&i3)
#define f4      (*(float*)&i4)
#define d1      (*(double*)&i1)
#define d2      (*(double*)&i2)
#define d3      (*(double*)&i3)
#define d4      (*(double*)&i4)
#define o1      (*(JB_Object**)&i1)
#define o2      (*(JB_Object**)&i2)
#define o3      (*(JB_Object**)&i3)
#define o4      (*(JB_Object**)&i4)
#define mem(t)	((t*)u2)[Mem_Lu]

#define signext32(a,b)				((((int  )(a)) << (32-(b))) >> (32-(b)))
#define signext64(a,b)				((((int64)(a)) << (64-(b))) >> (64-(b)))

