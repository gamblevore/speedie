
// Copyright, Theodore H. Smith 2023.
// Released under jeebox-licence http://jeebox.org/licence.txt

#include "JB_Alloc.h"
#include "JB_Umbrella.h"


extern "C" {
	extern void* JB__Flow_flow;
	void JB_Flow_Cond(void* a, bool b);
	void JB_Flow_While(bool value, uint p);
	bool JB_Flow__Cond(bool cond) {
		if (JB__Flow_flow) {
			JB_Flow_Cond(JB__Flow_flow, cond);
		}
		return cond;
	}

	bool JB_Flow__While(bool value, uint* p) {
		(*p)++;
		if (JB__Flow_flow) {
			JB_Flow_While(JB__Flow_flow, *p);
		}
		return value;
	}
	
	void test () {
		uint counter = 0; while (JB_Flow__While(counter < 10, &counter)) {
			printf("X: %i\n", counter);
			uint counter = 0; while (JB_Flow__While(counter < 10, &counter)) {
				printf("Y: %i\n", counter);
			}
		}
	}
}

