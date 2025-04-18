
#include "InstructionGetters.h"

#define l0      U0_Li
#define l1      U1_Li
#define l2      U2_Li
#define l3      U3_Li
#define l4      U4_Li
#define L0      U0_Lu
#define L1      U1_Lu
#define L2      U2_Lu
#define L3      U3_Lu
#define L4      U4_Lu
#define n1      ((Op<< 8)>>27)
#define n2      ((Op<<13)>>27)
#define n3      ((Op<<18)>>27)
#define n4      ((Op<<23)>>27)
#define n5      ((Op<<28)>>27) // loses 1 bit!
#define i1      (r[n1].Int)
#define i2      (r[n2].Int)
#define i3      (r[n3].Int)
#define i4      (r[n4].Int)
#define ii1     (r[n1].Int32)
#define ii2     (r[n2].Int32)
#define ii3     (r[n3].Int32)
#define ii4     (r[n4].Int32)
#define p1(x)   ((x*)(r[n1].Obj))
#define p2(x)   ((x*)(r[n2].Obj))
#define p3(x)   ((x*)(r[n3].Obj))
#define p4(x)   ((x*)(r[n4].Obj))
#define u1      (r[n1].Uint)
#define u2      (r[n2].Uint)
#define u3      (r[n3].Uint)
#define u4      (r[n4].Uint)
#define f1      (r[n1].Float)
#define f2      (r[n2].Float)
#define f3      (r[n3].Float)
#define f4      (r[n4].Float)
#define f5      (r[n5].Float)
#define d1      (r[n1].Double)
#define d2      (r[n2].Double)
#define d3      (r[n3].Double)
#define d4      (r[n4].Double)
#define o1      (r[n1].Obj)
#define o2      (r[n2].Obj)
#define o3      (r[n3].Obj)
#define o4      (r[n4].Obj)
#define v1      (r[n1].Vec)
#define v2      (r[n2].Vec)
#define v3      (r[n3].Vec)
#define v4      (r[n4].Vec)
#define iv1     (r[n1].Ivec)
#define iv2     (r[n2].Ivec)
#define iv3     (r[n3].Ivec)
#define iv4     (r[n4].Ivec)
#define uv1     (r[n1].Ivec)
#define uv2     (r[n2].Ivec)
#define uv3     (r[n3].Ivec)
#define uv4     (r[n4].Ivec)

#define std_max std::max
#define std_min std::min
#define btc(x)  ((x)<<(Compare4_Clearu<<3))
