

//  Created by Theodore on 23/04/2019.
//  Copyright © 2019 Theodore. All rights reserved.

#include "Jeebox.h"
#include <stdio.h>
#include <vector>

using namespace Jeebox;
using namespace std;


//// APP-SPECIFIC (NON-JEEBOX) CODE HERE
//// Basically, our app has a user's list
//// And functions like AddUser() just add stuff to the user's list
//// which is nothing to do with Jeebox but useful for a demo.

class UserDemo {
public:;
    int                 ID;
    std::string         AccountName;
    std::string         ScreenName;
    vector<std::string> Inventory;
    vector<std::string> Clothing;
};

vector <UserDemo*> UsrList;
void SaveUsers();


UserDemo* GetUser(int ID) {
    for (auto U : UsrList) {
        if (U->ID == ID) {
            return U;
        }
    }
    return 0;
}


void AddUser() {
    auto User = new UserDemo();
    UsrList.push_back(User);

    User->AccountName = "NewKid";
    User->ID = 12345;
    User->ScreenName = "Hai Im new, first tiem joinig lolxoxlolxdd!";
    User->Inventory.push_back("wooden_sword");
    User->Clothing.push_back("jeans");
    User->Clothing.push_back("t_shirt");
}


void SaveUsers() {
    // Doesn't directly deal with Jeebox, just outputs in jeebox-format
    // straight from the app's users data to a string.
    // only one line is jeebox-relevant, the line with "String(U->ScreenName).escape()"
    printf("user_list (count:%i) {\n", (int)UsrList.size());
    for (auto U : UsrList) {
        printf("\tuser %s (%i) {\n", U->AccountName.c_str(), U->ID);
        
        printf("\t\tscreen_name \"" );
        String(U->ScreenName).escape().print(); // escaping strings is important
        printf("\"\n");                         // you can write strings with `` instead of ""
                                                // which doesn't need escaping, but I wanted to show escaping.
        printf("\t\tinventory (");
        for (auto I : U->Inventory) {
            printf("%s, ", I.c_str());
        }
        printf(")\n");

        printf("\t\tclothing (");
        for (auto I : U->Clothing) {
            printf("%s, ", I.c_str());
        }
        printf(")\n");
        printf("\t}\n\n");
    }
    
    printf("}\n");
}


void UsersExample () {
    if (!Jeebox::ok()) return;

// add a new user to the user-list
    AddUser();
    
// alter an existing user (give him a new item)
    UserDemo* ToAdd = GetUser(85910191);
    if (ToAdd) {
        ToAdd->Inventory.push_back("scrying_sphere");
        ToAdd->ScreenName = "Zach${}attack";
    }
    
    puts("\n     :: Altered version of 'Users.box'\n\n\
Here we created a little demo, to show you reading a users account file in Jeebox\n\
for a fictional game, altering the users data a little for saving. \n\
(we don't save, just show you the data as if we would)\n\
The code is just a demo, showing how to parse a Jeebox file and use it for something!\n\
Also how to handle errors in input, and do it cleanly, which is very important\n\
when using Jeebox.\n\n\
For example, if in Users.box, you replaced 'user_list (count:4) {' with 'user_list apple {', the parser will complain!\n     :: \n\n");

    SaveUsers();
}




///// START ACTUAL JEEBOX CODE
void LoadUserArg (UserDemo* User, Message Arg) {
    auto Screen = Arg.item($tmp, "screen_name");
    User->ScreenName = Screen.first($str).name();
    auto Inv = Arg.item($tmp, "inventory");
    for (auto Name : Inv.first_($list)) {
        Name.match($thg);
        User->Inventory.push_back(Name.name());
    }

    auto Clothing = Arg.item($tmp, "clothing");
    for (auto Name : Clothing.first_($list)) {
        Name.match($thg);
        User->Clothing.push_back(Name.name());
    }
}

void LoadUsers (Message Root) {
    Message user_list = Root.first($tmp, "user_list").first($list).next($arg);
    for (auto U : user_list) {
        if (!Jeebox::ok()) return;

        if (U.match($tmp, "user")) {
            auto User = new UserDemo();
            UsrList.push_back(User);

            auto NameMsg = U.first($thg);
            User->AccountName = NameMsg.name();
            auto IDMsg = NameMsg.next($bra);
            auto Arg = IDMsg.next($arg);
            IDMsg = IDMsg.first($num);
            User->ID = (int)IDMsg.nameint();

            LoadUserArg(User, Arg);
        }
    }
}
///// END ACTUAL JEEBOX CODE (not that much code to load+validate a jeebox file!)


int main(int argc, const char* argv[]) {
    const char* Path = argv[1];
    if (!Path) { Path = "Examples/Users.box"; }
    String S = Jeebox::readfile(Path);
    Message M = S.parse(Path);
    if (Jeebox::ok()) {
        S.printline();
        LoadUsers(M);
        UsersExample();
    }

    for (auto Err : Jeebox::errors()) {
        Err.name().printline();
    }
}


