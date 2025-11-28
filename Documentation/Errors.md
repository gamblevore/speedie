## Error Handling In Speedie

Error handling is quite important. Its a skill to get right in any language.

In Speedie, we use the `#require`/`#expect`/`#error`/`#check` statements to handle errors and control-flow in one go.

Any errors you create, are stored in the global  "`StdErr`" object. Errors can be generated from any function and won't silently affect control-flow. (There are no exceptions in Speedie).

Let's make a simple example:


    || BannedWords = ["poop", "smelly"]
    
    function string.NameIsOK (|bool|)
        for b in bannedwords
            if self contains b
                return false
        return true


    main (|file| usersfile)
        || userlist = usersfile.parse            #require
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

The same error checking, can be written in two ways:

        || A = "a,a,a".parse            #require        // one way
        || B = "b,b,b".parse
        require B                                       // the other

Both `A` and `B` are tested in the same way. But the first looks better to me. Its more "out of the way". There might be a reason you can't use the `#require` shorthand, for example:

    || S = "abc".parse
    require S.name == "abc"             // can't be shortened into #require

Lets make a list of the statements:

+ `expect X`  - If X is false, this will create an error, then the function will return nil.
+ `require X` - If X is false, the function will return nil. No error.
+ `check X`   - If X is false, this will create an error. But the code will continue to flow.
+ `error`     - This will create an error. Same as `check false`

`expect`, `check` and `error` usually are used by passing an "Error identifier", as well as the object to test. For example:

    function Rename (|string| NewName)
        expect (NewName) ("No name found! Can't rename thingy.")
        if (NewName.length > 50)
            error "Name is too long!"
            newname = newname[0, 50]    // trim name, but continue
        // Actually do the rename.
        
The identifier could simply be a string, like above, but that might not tell you enough. Normally, the best way to make errors, is... with jeebox! Like this:

    main (|file| f) // your first dog checker app! 🐶
        || s = f.parse  #require
        for ch.flat in s
            expect (ch.name!="dog") (ch, "No dogs 'aloud' in the pool.")


Here, `expect` will correctly report an error, report the error position in the file, as well as the file-path, and your nice error message 😍, all bundled up into one little `error` object containing all that info. Its quite powerful if done properly.

This means that anytime you are processing structured data, saved in files or typed by a user, it just makes sense to store that data in jeebox, as it will make error-reporting feel natural.

If you run that code above, on a jeebox file containing a "dog" node, you should see this:

    error occurred (-1)
    /path/to/file.xml:5:1: error: No dogs 'aloud' in the pool.
    <dog hope="I hope i can swim!"/>
    ^
    1 issue found

Jeebox can parse XML files, and JSON files too. Mostly aimed at importing and converting to jeebox. Either way, in this case I used an XML file containing a `<dog hope="I hope i can swim!"/>` node.

---

### Good Error Handling

Error handling is a skill to get right. Lets show some speedie code and then convert it to simpler code, to see how much worse the simple way is.
    
    main (|File.Existing| F)
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
+ Many functions (like `list[@tmp, "jobs"]`) create errors if something goes wrong... so we need to replicate that too.
+ We have to `return -1` often, to replace the inbuilt `return -1` you get when your program exits but `stderr.ok==false`.
+ We need "`StillOK`" booleans in many places, to replicate how `stderr` previously was catching errors generated in subfunctions.
+ As a bonus, I showed the main arguments feature: `main (|File.Existing| F)`. This actually does error-checking! It requires that we pass a file that exists, if not, the app will exit before running the first line of code. "main arguments" allows you to specify the inputs of your program, clearly and cleanly. It is very useful for demos, but utils and even big apps can use it.

Take a look again at the first example. Its just **sooo** much better. Everything does what it is meant to do. It is simple, readable... and works better.

    main (|File.Existing| F)
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
+ Can temporarily replace `stderr` with during certain code-sections, in case you want to contain your errors from harming the rest of the program.

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
### What To Do With The List Of Errors?

OK, so `stderr` collects a list of errors. What do we do with it now we have it? Depends on what you are trying to do.

For many short shell-tools, you don't do anything. On quit, your app will report the errors found so far. We don't print them immediately, because your app may want to filter the errors, especially if one user-mistake caused 10 errors, you might as well filter it down to 1 error per user-mistake.

For GUI-apps, you probably want to log the errors. Like this:

    main 
        stderr.LogFile = file.Logs["MyApp.log"] // set this once, at app-startup

Errors are actually automatically sent to the notification area, in GUI-apps, once per-frame.

For long-lived shelltools, you need to decide the behaviour for yourself. Print them? Log them? Send them to another process? Choice is yours.

The main thing is to see statements like `#expect` or `#require` like comments. You don't need to understand them in order to understand the code flow. They are almost "out of the way", like comments. So your eyes more naturally look to the code at the left. Thats the whole idea of it. And even if you were looking at them, the overall amount of code is still **much lower**.


### Exceptions Are Bad

If you hate exceptions, or think exceptions suck, or think that manually dealing with errors all over the place like Go does... is awkward and just irritating... then Speedie is probably the language for you! It just does everything in a very clean way.

Here are a few examples why exceptions are bad:

* [open-std.org/jtc1/sc22/wg21/docs/papers/2022/p2544r0.html](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p2544r0.html)
* [youtube.com/watch?v=Fn0nWij8VEU](https://www.youtube.com/watch?v=Fn0nWij8VEU)
* [google.github.io/styleguide/cppguide.html#Exceptions](https://google.github.io/styleguide/cppguide.html#Exceptions)
* [youtube.com/watch?v=Iflu9zEJipQ](https://www.youtube.com/watch?v=Iflu9zEJipQ)
* [google.com/search?q=exceptions+considered+harmful](https://www.google.com/search?q=exceptions+considered+harmful)

Quite often an app will simply make a "Catch all" exception handler, and hope it never happens... which kind of defeats the purpose of exceptions in the first place but at least it lets your code survive thems.

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
    


OK, their syntax is quite understandable, in this case! Now lets look at this in speedie:


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

Python overall is a minimal language, much like speedie in that way. But Speedie's error handling is unmatched. Python's uses exceptions. And honestly, exceptions are a terrible idea. Absolutely awful concept.

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
    || contents = filename.readfile      #require   // worth 6 lines of python
    print contents.lowercase

**Or** this one liner!
    
    print ("/".readfile #require).lowercase
            

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
    

### C++ Exceptions

I found this C++ example, prominently on google. So perhaps hundreds of thouands of people may have read this example.

    #include <iostream>
    #include <fstream>
    using namespace std;
    
    void do_something_with(char ch) {} // Process the character 
    
    int main () {
      ifstream file;
      file.exceptions ( ifstream::badbit ); // No need to check failbit
      try {
        file.open ("test.txt");
        char ch;
        while (file.get(ch)) do_something_with(ch);
        // for line-oriented input use file.getline(s)
      }
      catch (const ifstream::failure& e) {
        cout << "Exception opening/reading file";
      }
    
      file.close();
    
      return 0;
    }

In Speedie:

    function do_something_with (|byte| b) // Process the character 
    
    main
        || file = "test.txt".in   #require // creates an input file-stream, returns if not readable
        for b in file
            do_something_with(b)

Again, this handles all the error codes that could happen. Like the file not existing, being a folder, lacking permissions, or anything. The C++ version doesn't even tell you what happened, or why, or what file-path it was! **Sure** you can extend your code to do all that, but in Speedie this happens automatically.

You might be wondering _"Where is all the code?"_ and _"I'll bet the speedie version runs slower!"_. In fact, speedie if you examine the C-code generated (Speedie can compile to C), you'll see the code is well-written C that is designed to execute fast. It probably runs the same speed, or perhaps faster than the C++ version.

Many of the speedie library equivalent functions are faster than their C++ counterparts. Even my `array.sort` function is faster (and safer when given bad sort comparison functions). Same with file-reading and writing, string-splitting, and much more. 

To help convince you... I'll show you the output given by Speedie's inbuilt ASM-Viewer. The ASM-Viewer also shows you the "C-level" version of the code, so it lets you see the code on 3 levels. Speedie, C, and ASM.

    function JB_Main (|int|)
        || file = JB_Str_In("test.txt", 0x7FFFFFFF)
        JB_Incr(file)
        if (!file) {
            JB_Decr(file)
            return -1
        }
     
        while (true) {
            || b = JB_SS_Byte(file)
            if (b < 0) {
                exit
            }
            do_something_with(b)
        }
        JB_Decr(file)
        return 0

This isn't "quite C" (missing semi-colons), its just close enough that you can understand it. However "proper C" (With semi-colons, etc) is actually output by Speedie, if you choose to compile to C.
     

### Rust's Result Types

    import { Result, ok, err } from 'neverthrow';
    import DB from 'my-synchronous-database';
    
    type DBError = string; // type alias for error message
    
    function getUser(id : UserID) : Result<User, DBError> {
        const user = DB.getUserById(id);
    
        if (user) {
            return ok(user); // return instance of OK
        } else {
            return err(`Cannot find the user by id ${id}`); // return instance of Err
        }
    }

Now lets look at Speedie's version:

    import "DB"
    function GetUser (|int| UserID, |User|)
        return DB.getUserById(id)        #expect ("Cannot find the user by id $id")

Wow. Same code... same result, but Speedie is just clear and simple.


# Conclusion:

It seems that my approach to error handling is simpler, easier to use, more reliable, and can halve the number of lines of code!

It just gets error handling "out of the way" so you can focus on your code.
