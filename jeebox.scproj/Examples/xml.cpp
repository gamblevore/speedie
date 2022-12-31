
//  Created by Theodore on 23/04/2019.
//  Copyright © 2019 Theodore. All rights reserved.

#include "Jeebox.h"
#include <stdio.h>

using namespace Jeebox;


void ExampleOfJeeboxToXML (Message M, int Depth=0) {
    for (int i = 0; i < Depth; i++) { // indent
        printf("    "); 
    }
    putchar('<'); M.type().name().print();
    if (M.first()) {
        if (M.name()) {
            printf(" name=\"");
            M.name().print();
            putchar('"');
        }
        putchar('>');
    } else {
        putchar('>');
        M.name().print();
    }

    for (auto C : M) {
        putchar('\n');
        ExampleOfJeeboxToXML(C, Depth+1);
    }

    if (M.first()) {
        putchar('\n');
        for (int i = 0; i < Depth; i++) { // indent
            printf("    "); 
        }
    }
    printf("</"); M.type().name().print(); putchar('>');
    if (!Depth) {
        putchar('\n');
    }
}



int main(int argc, const char * argv[]) {
    jb_init(1);
    String S = String("while @Mary laughed (at:the~adorable~birbs) (the~rain fell)");
    S.printline();
    ExampleOfJeeboxToXML(S.parse());
}

