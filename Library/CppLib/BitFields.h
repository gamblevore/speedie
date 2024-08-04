
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
#define i1      (r[n1].Int)
#define i2      (r[n2].Int)
#define i3      (r[n3].Int)
#define i4      (r[n4].Int)
#define p1(x)   ((x*)(r[n1].Stack.Addr))
#define p2(x)   ((x*)(r[n2].Stack.Addr))
#define p3(x)   ((x*)(r[n3].Stack.Addr))
#define p4(x)   ((x*)(r[n4].Stack.Addr))
#define u1      (r[n1].Uint)
#define u2      (r[n2].Uint)
#define u3      (r[n3].Uint)
#define u4      (r[n4].Uint)
#define f1      (r[n1].Float)
#define f2      (r[n2].Float)
#define f3      (r[n3].Float)
#define f4      (r[n4].Float)
#define d1      (r[n1].Double)
#define d2      (r[n2].Double)
#define d3      (r[n3].Double)
#define d4      (r[n4].Double)
#define o1      (r[n1].Obj)
#define o2      (r[n2].Obj)
#define o3      (r[n3].Obj)
#define o4      (r[n4].Obj)
#define I1      (r[n1].Int32)
#define I2      (r[n2].Int32)
#define I3      (r[n3].Int32)
#define I4      (r[n4].Int32)

#define std_max std::max
#define std_min std::min

