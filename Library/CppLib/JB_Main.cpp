//
//  JB_Main.cpp
//
//  Created by theodore on 19/01/2022.
//  Copyright © 2022 Theodore. All rights reserved.
//

#include <stdio.h>

extern "C" {

const char** JB_Main__Args;

int JB_SP_Run (const char** args, int Mode);
int main (int count, const char** args) {
	JB_Main__Args = args;	
    return 255 & JB_SP_Run(args, 3);
}

}

