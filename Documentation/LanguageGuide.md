## Speedie Language Guide

Hi and welcome to Speedie. Hopefully this guide won't take too long, as Speedie was designed to be simple.

So the best way to understand Speedie is to relate it to existing languages. "Speedie is like X but different in Y".

Lets start with the language 'C'. Speedie is modelled after C but with modern concepts like objects and iterators...

Let's make a simple example in C:

````
int CountStringLines(String* s) {
    auto Addr = s->Addr; // implicitly declared type
    int Length = s->Length;
    int Result = 0;
    for (int i = 0; i < Length; i++) {
        if (Addr[i] == '\n') {
            Result++;
        }
    }
    return Result;
}
````

Well... in Speedie things will look different, but the concept is the same.

Firstly, we define functions with the name "function". Secondly, we use `||` to declare variables or parameters in Speedie.

    function CountStringLines (|string| s, |int|)

This just means we take a string and return an int.

Let's just fill out the whole function. In the example code below, you will see that speedie doesn't use `;` to end lines. Also Speedie uses `.` to access object properties.

Speedie has implicit types (the `||` declarations.) You are expected to use implicit types for most variables (but not function declarations) in Speedie, its just natural to the language. This makes reading code easier. But Speedie is a strongly-typed language. Also Speedie uses indentation-aware code, like python but a bit simpler.

````
function CountStringLines (|string| s, |int|)
    || Addr = s.Addr
    || Length = s.Length
    || Result = 0
    for i in Length
        if Addr[i] == '\n'
            Result++
    return Result

````

So this function will basically do exactly the same as the C function! In Speedie, it is considered usually-bad to access a string's `.Addr` property directly, but the above is just an example of "something that does the same as C code", not "good speedie code". We'll make a good example next!

We can make this code shorter. Speedie has a lot of "Speedieisms", basically ways to make code shorter. I guess I just couldn't help myself while writing the compiler.

Firstly, we can directly loop over a string. This will produce identical code to the previous version! It's just simpler to write and understand.

````
function CountStringLines (|string| s, |int|)
    || Result = 0
    for c in s
        if c == '\n'
            Result++
    return Result
````

We can even make it smaller! Speedie has a special "rz" variable that means "this is the result of the function". "rz" is returned when the function ends, and it takes the type from the function's declaration.


````
function CountStringLines (|string| s, |int|)
    for c in s
        if c == '\n'
            rz++
````
Wow this function is looking great already! It does exactly the same as the original C version but contains only 3 lines of code. We can make it even better if we want. Let's make this function accessable ON string rather than a global function.

````
function string.CountLines (|int|)
    for c in self
        if c == '\n'
            rz++
````

Now that is more like it. A proper Speedie function. Let's try to use this in a program:

````
function string.CountLines (|int|)
    for c in self
        if c == '\n'
            rz++

main
    printline app.args[0].countlines
````

Speedie should be able to compile this, and make a working program! Not bad huh! Your first Speedie program.

Lets explain a bit what the words here mean. `"main"` here is just your program's main function. Similar to "int main (...)" in C++.

`printline` is a special statement that can take a string or object or number, and print it to stdout.

and `app.args` is an array of strings that were passed to your app from the command-line. `Countlines` is the function you just created. So thats great. A simple working program.

Thats it for now, but we can learn a lot more. There may be some things that surprise you or trip you up, so lets get to them first.

Looking through Speedie code, you may see a lot of strangely defined functions, or functions with cpp_wrapper in them.


## Possibly Surprising things

    class Logger
        |file| File
        function Log (|string| s)
            if !.file
                || L = file.logs.child(app.AppName+".log")
                .OpenLog(L)
            .File.write(s)
            .file.write("\n")
        
        function openlog (|string| path)
            .FILE = path.file
            .file.OpenEmpty        


One thing you will notice immediately, is that we are accessing our properties with `.` even within a class's own functions. This is different to most languages. `self.property` is equal to `.property` in speedie. The dot `.` is necessary, you can't access self's properties or functions without it. This reduces the chances of bugs.

Another thing you might spot is that when it comes to looking up names, Speedie is case-insensitive. It doesn't care if you write `.FILE` or or `.file` or `.fILe`. This makes writing code easier.

You might see a lot of functions like this, used internally by Speedie:

    function Path (|string|)
        cpp_wrapper JB_App__Path

This means it's implementation is created in C. So it does what it says. This is a wrapper around a C++ function.
 
Speedie has a lot of syntactic sugar. For example:

    || ab = "a" + "b"

This actually calls a string-append function, defined on the string class.

    operator plus (|string| other, |string|)
        cpp_wrapper JB_Str_OperatorPlus

You can write your own operator-functions on your own classes too, although its usually a bad idea for most classes. One exception is the `append` operator `<~`. It kind of looks like a wobbly-arrow flying through the air. Its useful for many many things. Mostly for classes that contain things, like an array or dictionary.

    class PeopleLister
        |[string]| People
        syntax Append (|string| person)
            .people <~ person
    
    main
        || list = PeopleLister.new
        list <~ "fred"
        list <~ "amy"
    
You'll see the `<~` operator used in most Speedie code, as appending one thing into another thing is one of the most common things you will do. It is used in the FastString class, and even the File class. Its used in arrays, messages, IPC, everything really.

    list.append("fred") // Most other languages do this
    list <~ "fred"      // which is easier to read?
 
Having to write `.append(var)` gets noisy really fast after many lines of the same thing.
 
Here's a few more tricks you'll might want to know. Actually these two lines do the same thing:
 
    || list1 = PeopleLister.new
    || list2 = PeopleLister() // I borrowed this syntax from python.
 
The `()` version is actually a lot nicer to read, most of the time.

I think that's enough for now. I'll write a proper documentation later.


