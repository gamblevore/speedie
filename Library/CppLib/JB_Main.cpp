//
//  JB_Main.cpp
//
//  Created by theodore on 19/01/2022.
//  Copyright © 2022 Theodore. All rights reserved.
//

extern "C" int JB_SP_Run (const char** args, int Mode);
extern "C" int main (int count, const char** args) {
    return 255 & JB_SP_Run(args, 3);
}
