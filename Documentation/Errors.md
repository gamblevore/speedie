## Error Handling In Speedie

Error handling is quite important. Its a skill to get right in any language.

This is how we do it in Speedie: We use an object called `stderr` to store reported errors... and we use the `#require`/`#expect`/`#error`/`#check` statements.  All errors flow through `StdErr`.

Errors can be generated from any function. Generated errors don't affect control-flow, unless you specifically state that it will.

Let's make a simple example:


    || BannedWords = ["poop", "smelly"]
    
    function string.NameIsOK (|bool|)
        for b in bannedwords
            if self contains b
                return false
        return true


    function CheckUserListNames (|string| userspath)
        // '#require' will exit this function, if userlist is set to nil.
        || userlist = userspath.file.parse            #require
        "User list parsed OK"
        
        for user in userlist
            // check all users for bad-names. Pass the message to nicely
            // describe where the errors were found in the source.
            check user.name.NameIsOK (user, "User has a bad name.")
            
        if stderr.ok
            "All users have good names"
          else
            "${stderr.errorCount} users have bad names"
        

Hopefully the comments explain this function well.

The statements `require` / `expect` / `check` / `error` are used for control-flow and error-handling. They remove the messy control-flow, so you can see your code clearly.

Each can be used after an expression, or before:

        || A = "a,a,a".parse            #require
        || B = "b,b,b".parse
        require B

both `A` and `B` are tested in the same way. But the first looks better to me, in this case. Its more "out of the way".

Lets make a list of the statements:

+ `expect` - This will create an error, and return from the function if the expression is false.
+ `require` - This will just return, if the expression is false. No error.
+ `check` - This will create an error if the expression is false. But the code will continue to flow.
+ `error` - This will create an error. Same as `check false`

---
### Good Error Handling
Error handling is a skill to get right. Lets show some speedie code and then convert it to simpler code, to see how much worse the simple way is.
    
    main
        || F = app.args[0].ExistingFile    #require
        || jobs = f.parse                  #require
        || list = jobs[@tmp, "jobs"][@arg] #require
        for job in list
            .ProcessJob(job)
        require stderr.ok
        for job in list
            .FinaliseJob(job)
        

Seems clear? Lets look at a version written **without** the Speedie error handling system.

    main
        || F = app.args[0].file
        if !F.exists
            "Error: File $f doesn't exist."
            return -1
        
        || jobs = f.parse
        if !jobs
            "Error: Can't parse file $f"
            return -1
        || list = jobs[0]
        if list != @tmp or list != "jobs"
            "Expected first item of file $f to be statement 'jobs'"
            return -1
        list = list[0]
        if list != @arg
            "Expected first item of statement 'jobs' in file $f to be an argument."
            return -1
        
        || StillOK = true
        for job in list
            if !.ProcessJob(job)
                StillOK = false
        require StillOK
        for job in list
            .FinaliseJob(job)
    

As you can tell, this is a mess. A disaster actually. Doing it the non-speedie way is awful, and makes error-reporting **worse**. For example, filepaths are now buried in an error-message, rather than separate and easy to parse.

Why is is so much worse?

+ We need to print often, to replicate how Speedie prints `stderr` on exit. Also many functions (like `string.ExistingFile`) create errors if something goes wrong... so we need to replicate that too.
+ We have to `return -1` often, to replace the inbuilt `return -1` you get when your program exits but `stderr.ok==false`.
* The same above two problems apply for accessing children of `message`, which happens **all over the place**.
+ We need "`StillOK`" booleans in many places, because previously any function could have been adding errors.

Take a look again at the first example. Its just SOOO much better. Everything does what it is meant to do. Its simple, readable, works better.

    main
        || F = app.args[0].ExistingFile    #require
        || jobs = f.parse                  #require
        || list = jobs[@tmp, "jobs"][@arg] #require
        for job in list
            .ProcessJob(job)
        require stderr.ok
        for job in list
            .FinaliseJob(job)

Accessing messages is so common that manually creating errors all the time would be totally undoable. In fact this is why my error system exists. But still useful elsewhere, especially for files or anything really.
 
Speedie's error-reporting system has a lot more features, such as:

+ Warnings: These get printed like errors, but leave `stderr.ok` true.
+ Logging of errors to a logfile
+ Treating errors as warnings during certain code-sections
+ Can temporarily replace `stderr` with another `ErrorList` during certain code-sections, in case you want to contain your errors from harming the rest of the program.

Overall it is a great thing. Use it if you need to deal with errors or generate errors. Sometimes you don't want errors to occur, like when reading from a file that doesn't exist, but actually I've already thought about that. `file.ReadAll` defaults to ignoring non-existing files.

    || x = "/path/to/optional_file"
    || data = x.file.readall
    printline data

`file.ReadAll` only ignores "file doesn't exist", not "the file is actually a folder", or recursive-symlinks, or some other file-system error.

---
### How Do We Know An Error Occurred Just Now?
`stderr` tells us if an error has occurred sometime in the past, but how to know if it happened just now? 

Basically by returning `nil`, `false`, or some value that evaluates to `false`.

For example: `string.parse` will return `nil` if an error occurred, and return a valid object otherwise. This is the convention that Speedie sticks to.

If copying a file fails, it will return an `ErrorInt` of -1, which evaluates to `false`. So you can do:
    
    require File1.CopyTo(File2)
    "$File1 copied successfully"

_Conclusion: The official way of detecting **if** an error just occurred in a function-call, is checking if the function returned something that evaluates to false. (Assuming the function does create errors, not all do.)_

---
### What to do with the List of Errors?

OK, so `stderr` collects a list of errors. What do we do with it now we have it? Depends on what you are trying to do.

For many short shell-tools, you don't do anything. On quit, your app will report the errors found so far. We don't print them immediately, because your app may want to filter the errors, especially if one user-mistake caused 10 errors, you might as well filter it down to 1 error per user-mistake.

For GUI-apps, you probably want to log the errors. Like this:

    main 
        stderr.LogFile = file.Logs["MyApp.log"] // set this once, at app-startup

Errors are actually automatically sent to the notification area, in GUI-apps, once per-frame.

For long-lived shelltools, you need to decide the behaviour for yourself. Print them? Log them? Send them to another process? Choice is yours.

Another thing you can do is "fail gracefully". For example, lets say you are doing a long complex operation. Like converting some database tables, and an error occurs deep within the code. You can do "`require stderr.ok`" at some point in your code to exit that operation...

Let's say you had a GUI-app doing a database-conversion.

    
    using errorlist.new
        .startconversion
        .doconversion
        .finishconversion
        if !stderr.ok
            beep "An error occured during conversion:\n\n" + stderr.render

This command "`beep`" would open up an alert-window and beep with the message passed. The "`using errorlist.new`" thing, would "contain" any errors from contaminating the rest of the program, which in this example we don't want. It does this by creating a new `stderr`... saving the old one, then replacing the old `stderr` after our job is done. You could do it manually but thats kind of ugly.

    || old = stderr
    stderr = errorlist.new
    .startconversion
    .doconversion
    .finishconversion
    if !stderr.ok
        beep "An error occured during conversion:\n\n" + stderr.render
    stderr = old

This does the same thing but it looks messier.