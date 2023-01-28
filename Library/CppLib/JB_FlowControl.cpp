
// Copyright, Theodore H. Smith 2023.
// Released under jeebox-licence http://jeebox.org/licence.txt

#include "JB_Alloc.h"

extern "C" {

uint fn_depth = 0;
uint LastID = 0;
uint Counter = 0;
// the codeflow is really a tree.
// why not... just use... jbin? or something like that?
// i mean... it is a TREE... right?
// we need a tree for the nesting... and only update a position
// once we reach false.
// what a about a while-loop that calls a func that calls itself?
// I guess we can just mark function-call-depth... if it matches
static void Close_(uint Which) {
}
static bool GoDeeper_(uint Which) {
	return false;
}
static void Open_(uint Which) {
}
static void Add_(uint Which) {
}
static bool FlowAny_(uint Which, bool State) {
	if (!State)
		Close_(Which);
	  else if (GoDeeper_(Which))
		Open_(Which);
	  else
		Add_(Which);
		
	return State;
}

bool JB_Flow__If(bool State) {
	return FlowAny_(0, State);
}

bool JB_Flow__While(int Which, bool State) {
	return FlowAny_(Which, State);
}

#define if_(a) if (JB_Flow__If(a))
#define while_(a,b) while (JB_Flow__While(a,b))
#define call_(fn) ({fn_depth++; fn; fn_depth--;})
static int test (int b) {
	if_(b >= 10) {
		while_(1, b-- > 0) {
			if_ (b == 3) {
				puts("test");
			} else if_ (b == 5) {
				puts("test2");
			} else if_ (b==7) {
				call_(test(6));
			}
		}
	}
	return 0;
}

}

