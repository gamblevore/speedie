## Project Structure

Projects in Speedie have a certain structure to them.


    MyCoolApp.scproj/
        Build/
            MyCoolApp
        Cpp/
            JB_Globals.cpp
            JB.cpp
            JB.h
        input/
            MySourceCode.spd
            MoreCode.spd
            
Speedie Projects are nice because you don't need to include the files manually. Like in C++ or PHP or python. So you are free to rename/move/add/delete files as you like.

Actually the `Build` and `Cpp` folders don't exist until you try to build a project. And the `Cpp` folder won't exist unless you build using the `"-x"
` switch.

The folder "`input`" is where your source code lives, but you can rename it to `AnyNameHere.input` if you want, as long as it ends with "`.input`" or is called "`input`".

If a folder or file contains "(Disabled)" in the filename, it is ignored.

You can also `import` other projects, to use them as libraries:

    import "GUI"
    
    main
        app.RunGUIStuff

Imports don't self-loop. That means, if project A imports project B, and project B imports project A... well you just get A and B once. No infinite loops. Nice.
