## Project Structure

Projects in Speedie have a certain structure to them.


    MyCoolApp.scproj/
        Build/
            MyCoolApp
        input/
            MySourceCode.spd
            MoreCode.spd
            
Speedie Projects are nice because you don't need to include the files manually. Like in C++ or PHP or python. So you are free to rename/move/add/delete files as you like.

Actually the `Build` folders doesn't exist until you try to build a project.

The folder "`input`" is where your source code lives, but you can rename it to `AnyNameHere.input` if you want. If a folder or file contains "(Disabled)" in the filename, it is ignored.

You can also `import` other projects, to use them as libraries:

    import "GUI"
    
    main
        app.RunGUIStuff

Imports are located from the Speedie directory, which  currently is at `~/Speedie/` although I'll change that later.