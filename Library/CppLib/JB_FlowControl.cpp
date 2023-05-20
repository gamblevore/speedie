
// Copyright, Theodore H. Smith 2023.
// Released under jeebox-licence http://jeebox.org/licence.txt

#include "JB_Alloc.h"
#include "JB_Umbrella.h"


extern "C" {
	struct FlowControl;
	extern FlowControl* JB__Flow_Flow;
	extern uint  JB__Flow_Disabled;
	void JB_Flow_Cond(FlowControl* flow, bool b);
	bool JB_Flow__Cond(bool cond) {
		if (!JB__Flow_Disabled) {
			JB__Flow_Disabled++;
			JB_Flow_Cond(JB__Flow_Flow, cond);
			JB__Flow_Disabled--;
		}
		return cond;
	}
}

