//
//  JB_Main.cpp
//
//  Created by theodore on 19/01/2022.
//  Copyright © 2022 Theodore. All rights reserved.
//

#include <stdio.h>

extern "C" {


int JB_SP_Run (const char** Args, int Mode);
int main (int count, const char** Args) {
    return 255 & JB_SP_Run(Args, 3);
}

}

