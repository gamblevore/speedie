
//  Created by Theodore on 23/04/2019.
//  Copyright © 2019 Theodore. All rights reserved.

#include "Jeebox.h"
#include <stdio.h>

using namespace Jeebox;


void msg (const char* m, int before=1, int after=1) {
    while (before-- > 0) {
        printf("\n");
    }
    printf("      :: %s :: ", m);
    while (after-- > 0) {
        printf("\n");
    }
}

void ExampleOfGoodJeebox (String S) { 
    Message M = S.parse();
    M.render().print();
    msg("You should see a parse-tree!");
    M.ast().printline();
}


void ExampleOfBadJeebox (String S) {
    if (S.parse()) {
        msg("failed to catch invalid input.");
    } else for (auto Err : Jeebox::errors()) {
        msg("Successfully caught invalid input!", 1, 2);
        Err.name().printline();
    }
}


void ExampleOfModifyingJeebox (String S) { 
    Message M = S.parse();
    M.render().printline();
    // two different ways to add to a tree.
    // 1) through parsing, 2) syntactically 

                // Add "%close the~book", through parsing.
    Message M2 = String("%close the~book").parse();
    M.append(M2.first()); // parsing returns the lines wrapped in an $arg
                          // so the first (only) line (%close the~book) is the first (only) child.


    msg("you know what? We parsed something, but...", 0, 0);
    msg("I want to alter the parse-tree too! Heres the final result", 1, 2);
                // Add "%open the~door", syntactically.
    auto Added = M.create($oat);
    Added.create($opp, "open");
    auto Adj = Added.create($adj);
    Adj.create($thg, "the");
    Adj.create($thg, "store");
    Adj.last().name("door");
    
    
                // Modify the name and syntax of a message
    auto F = M.first();
    if (F.type() == $tmp) {                   
        F.name("when");
        auto They = F.first().first();
        They.name("jake");                           // Rename something in the tree!
        They.type($name);                          // but only if it's a "tmp" (above test (F.type()==$tmp))
    }
    M.render().print();

    msg("Lets look at the tree of what we created", 1, 1);
    M.ast().printline();
}


void ExampleOfModifyingJeebox2 (String S) { 
    Message M = S.parse();
    // let's alter the name of something in the tree.
    // ideally you want to use std::string or some proper string library, in order to alter names.
    // but this example is OK for now.
    auto Tmp = M.first();
    auto NameMsg = Tmp.first();
    auto Name = NameMsg.name();
    int N = Name.length();
    
    msg("Lets parse some jeebox, then alter some names in the tree", 0, 2);
    // alteration incoming!
    char* Buff = (char*)malloc(N);
    for (int i = 0; i < N; i++) {
        Buff[i] = Name.address()[N-(i+1)]; // reverse string
    }
    auto NewName = Jeebox::string_owned(Buff, N); // Jeebox will call free() on NewName, when its no longer used.
    Tmp.render().printline();
    NameMsg.name(NewName); // Name is now reversed.
    Tmp.render().printline();
}



int main(int argc, const char * argv[]) {
    int Result = jb_init(0);
    if (Result) {return Result;}

    msg("Let's parse some jeebox code and see the parse tree", 0, 2);
    ExampleOfGoodJeebox("|int| a = b + c");
    msg("OK, now let's try parse some invalid Jeebox code, to see how Jeebox catches the errors", 0, 0);
    ExampleOfBadJeebox("|| (a,+a");
    
    msg("let's look at jeebox parsing something like English", 0, 2);
    ExampleOfModifyingJeebox("because @Fred snapped his~fingers");
    ExampleOfModifyingJeebox2("hello @SpongeBob");
    
    return jb_shutdown();
}

