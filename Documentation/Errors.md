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
            // check all users for bad-names. Passes the object 'user' which knows
            // what position in what file it came from, and stores that in the error.
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

+ `expect` - If the expression is false, this will create an error, then the function will return nil.
+ `require` - If the expression is false, the function will return nil. No error.
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

Why is it so much worse?

+ We need to print often, to replicate how Speedie prints `stderr` on exit.
+ Many functions (like `string.ExistingFile`) create errors if something goes wrong... so we need to replicate that too.
+ We have to `return -1` often, to replace the inbuilt `return -1` you get when your program exits but `stderr.ok==false`.
* The same above two problems apply for accessing child nodes of `message`, which happens **all over the place**.
+ We need "`StillOK`" booleans in many places, to replicate how `stderr` previously was catching errors generated in subfunctions.

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

### Containing Errors

Another thing you can do is "fail gracefully". For example, lets say you are doing a long complex operation. Like converting some database tables, and an error occurs deep within the code. Lets say this is a GUI-app.

    
    using errorlist.new
        .startconversion
        .doconversion
        .finishconversion
        if !stderr.ok
            beep "An error occured during conversion:\n\n" + stderr.render

This command "`beep`" would open up an alert-window and beep with the message passed. The "`using errorlist.new`" thing, would "contain" any errors from contaminating the rest of the program, which in this example we don't want. It does this by:

* creating a new clean `stderr`, which has no errors inside, so you can be sure stderr.ok is true
* saving the old stderr
* putting the old `stderr` back, after our job is done

You could do it manually but thats messy.

    || old = stderr
    stderr = errorlist.new
    .startconversion
    .doconversion
    .finishconversion
    if !stderr.ok
        beep "An error occured during conversion:\n\n" + stderr.render
    stderr = old

This does the same thing but I prefer the first, don't you think? Also, the "using" syntax can handle early returns:

    using errorlist.new
        if !.startconversion
            return
        .doconversion
        .finishconversion
        if !stderr.ok
            beep "An error occured during conversion:\n\n" + stderr.render

This would actually make sure `stderr` is reset to its original value no matter how we exit the `using` block.

If you hate exceptions, or think exceptions suck, or think that manually dealing with errors all over the place like Go does... is awkward and just irritating... then Speedie is probably the language for you! It just does everything in a very clean way.

The main thing is to see statements like `#expect` or `#require` like comments. You don't need to understand them in order to understand the code flow. They are almost "out of the way", like comments. So your eyes more naturally look to the code at the left. Thats the whole idea of it. And even if you were looking at them, the overall amount of code is still **much lower**.

# Comparisons
Lets compare speedie error handling, to other languages.

### Comparison To Go

First lets look at "`Go`", a supposedly modern language with huge funding (not jealous at all 😂 😭). And then look at how much better it is in `Speedie`:

    package main
    import (
        "errors"
        "fmt"
    )
    
    func Hello(name string) (string, error) {
        if name == "" {
            return "", errors.New("empty name")
        }
        message := fmt.Sprintf("Hi, %v. Welcome!", name)
        return message, nil
    }
    
    func main() {
        message, err := Hello("")
        if err != nil {
            log.Fatal(err)
        }
        fmt.Println(message)
    }
    


OK, their syntax is quite understandable, in this case. `Go` has awkward syntax usually, but for this simple case it's OK! Now lets look at this in speedie:


    function Hello (|string| name, |string|)
        expect (name) "empty name"
        return "Hi, $name. Welcome!"

    main
        || message = hello("")
            printline message
            


Yeah... that. LITERALLY 1/2 of the code. Are you starting to feel it now Mr Krabs? Are ya? Are ya? Mr Krabs?

You might be wondering, why I didn't replace "`log.fatal`", well... because `log.fatal` only calls "`log.print(msg);os.Exit(1)`", so its just printing.

Turns out that Speedie apps do the same thing, on exit. Once the speedie app exits, if `stderr` contains errors, the errors are logged to the console, with an error number of -1. So it is literally the same thing... just happens without me even needing to say it.

Speedie really is remarkably expressive and well-designed.

### Python Comparison

Python overall is a minimal language, much like speedie in that way. But Speedie's error handling is unmatched.

    filename = '/'
    try:
        with open(filename) as f_obj:
            contents = f_obj.read()
    except OSError as e:
        print(f"Unable to open or read {filename}: {e}", file=sys.stderr)
        return
        
    print(contents.lower)

In Speedie:

    || filename = "/"
    || f_obj = filename.file
    || contents = f_obj.readall #require

    print contents.lowercase

Speedie's version is simpler. In fact, here we can rely on Speedie already printing good error messages. If you run this code, you should see this:

`error: Is a directory when reading '/'.`

Also, Speedie's error handling is harder to get wrong! Most of the examples I've seen for reading files, catch `FileNotFoundException`... which fails to catch most of the 50 file-system errors. I had to ignore most prevalent examples to find a good python example.

Also, there are two failiure points in the python code. `open()` and `read()`. Just because `open()` succeeded doesn't mean you can `read()` from it! Especially if you opened a directory. So error-handling with files in python, is still more difficult than it seems.

Things just are more convenient in speedie.

### Error Handling in C

C's error handling... what to say about it. It makes sense from a performance perspective. But from a coder's perspective its no fun. Awkward, easy to miss errors... messy.

    const char* Fol = "/tmp/a/b/c/";
    int err = mkdir(Fol, 0755);
    if (err) {
        if (err == -1 and errno == EEXIST) {
            ; // it's OK, just ignore
        } else {
            printf("An error %s occurred while trying to make a directory at %s\n", strerror(errno), Fol);
            return -1;
        }
    }
    UseFolder(Fol);

This code seems labourious, error-prone and time-wastery. What if you don't know about `EEXIST` or fail to log `strerror(errno)` and `Fol`. Thats 2 strings to log, and 2 checks to remember. Also the control flow is messy.

In Speedie:

    || Fol = "/tmp/a/b/c/".file
    require fol.makedir
    usefolder(fol)

Again! Super simple! Once the program exits, you get the list of errors printed. With nicely informative error message:

    error: File doesn't exist when makedir '/tmp/a/b/c/'.

# Conclusion:

It seems that my ErrorList approach for error handling is simpler, easier to use, more reliable, and cuts down total lines of code to 1/3 quite often.

It just gets error handling "out of the way" so you can focus on your code.