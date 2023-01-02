## Speedie-Isms

Speedie has a lot of speedie-isms.

I just call them 'isms'. The more 'isms' you know, the better your code will look. But you don't **need** to know them. You only really need to know 'isms' for **reading** code, not writing. 

As long as you write generally good code in the first place, your code in Speedie will be also good. These "isms" just make code shorter, which is useful in large projects. With the **exception of error-handling**, that actually **is quite important** to know how to write properly.

---
### 'Syntax' Functions
These are special functions. They work like any other function, but are called via syntactic sugars. For example:

    class Something
        |string| Data
        syntax Access (|int| Position, |byte|)
            return .data[position]
    main
        || x = something("hello")
        printline x[2] // "l"
    

+ `syntax append` - Useful if your class can have things appended into it.
+ `syntax equals` - Used for comparing if two objects are equal.
+ `syntax compare` - Used for comparing if one object is more or less than the other.
+ `syntax access` - Used for accessing an object as if it were an array. Can take params of any kind, strings or messages even. Can even take multiple parameters.
+ `syntax expect` - Used for error-handling.
+ `syntax cast` - Decides how an object gets turned into a bool. Useful for `"if"` tests. Also used so you can return a `faststring` object from a function that expects a `string`... because the `faststring` has a cast to a `string`.
+ `syntax is/isnt` - See below.

---
### 'is' and 'isnt'
Sometimes its nice to have constants work for you, rather than you work for them. `Syntax "is"` does that:

    function ClickedOnRow (|listviewrow| row, |bool|)
        if row is Modified
            .UpdateWithRow(row)
        if row isnt Disabled
            .ProcessRow(row)
            return true
    
Where are the names ("modified/disabled") defined? How are they found? They are found via the "`syntax is`"  function on `listviewrow`.

    syntax is (|ListViewState| s, |bool|)
        if self
            return .state & s

Speedie checks the first param, and assumes we want a constant within `ListViewState`. And the `ListViewState` datatype, has some flags defined:
    
    datatype ListViewState (uint16)
        flags
            Selected 
            Modified
            Disabled
            ...
    

So these two lines are equivalent:

    require row isnt Disabled
    require row.syntaxisnt(listviewstate.disabled)

Obviously, the first looks better, but they both do the same thing, and the second is how people normally would be testing for flags on states in classes, in other languages. You can also do things like this:

    function Listviewrow.SetUpNicely (|listviewrow| other)
        is Modified // calls setter "is" on 'self'
        is selected
        (other is modified) // calls setter on 'other'
        (other is selected)

---
### Flag Constants
Speedie has bit-flag support. `Flags` can be used in modules, classes or globally, and works much like the `constants` statement.
    
    class MyListViewRow
        flags
            Opened    // 1
            Running   // 2
            Disabled  // 4

This is quite useful for when you don't want to waste time writing code like `Running = 1 << 15`, and then having to adjust everything everytime you delete a flag.

Sometimes you want to define that one flag, is the combination of a few others. Heres a quick way to do it:
    
    flags
        kEnd = (kEndOfLine, kComma, kEndContainer) 

This defines 3 flags (kEndOfLine, etc), and says that kEnd is equal to all of them combined.

Flags and constants can also have a custom datatype set to them.

    datatype HappyType (int)
        constants
            |HappyType|
            Excited   //  these constants are  //
            Gleeful   //  now typed as         //
            Bouncy    //  HappyType, and not   //
            Relieved  //  just a plain int.    //

---
### Property Hiding (+ A Bonus 'ism')

Speedie has setter functions. If a setter function has the same name as a property, then this property becomes "hidden", and only the class itself can see the property.

    class Person
        |int| age
        |string| name
        setter age (|int|)
            expect (value > 0 and value < 300) "Age $value out of range on ${.name}"
            .age = value
        // now no one can set the age to a negative value...
    
    main
        || P = person(12, "fred") // auto-constructor
        P.age = -2 // reports "error: Age -2 out of range on fred"

As a bonus, I've also demonstrated auto-constructors, which are created for anything with 6 or less properties and (no explicit constructors).

---
### Custom Operators
Speedie uses custom operators a lot. For string appends obviously, but for all sorts of classes. For example, you can compare an array to an int. `Strings` too. And `RingTree`!

    || x = ["a", "b", "c"]
    if x == 3
        "$x has three items."
    || H = "house"
    if H == 5
        "'$H' has five letters"
    || L = "(a,b,c,d)".parse
    if L == 4
        "The list $L has four items!"
        
`Isa` works on ints too, it checks if something is a multiple of somerthing else. We can also set bits on ints even.

    || x = 0
    for i in 10
        if i isa 2 // if 
            "$i is even"
            x[i] = true
          else
            "$i is odd"
    "x is $x"

We have ternary expressions too. Useful sometimes.

    || x = (.LeftHand, .RightHand)(BeLeft)
    
---
### FastString Tricks
You can append an string with embedded values, into a FastString. This actually is an optimised operation, and runs at full-speed.

     || fs = faststring()
     fs <~ "My name is $name and my age is $age"

this expands to:

     || fs = faststring()
     fs <~ "My name is "
     fs <~ name
     fs <~ " and my age is "
     fs <~ age
    
Obviously the first version looks better. So don't worry about appending strings with embedded expressions! Its pre-optimised.

---
### Extending classes and modules
Sometimes you want to add a function to a class or module, without altering the file it is defined in.
    
    function string.AddNumber (|int| num, |string|)
        return self + " " + num.render
        
    function @string.AllNumbers (|string|) // this extends the module
        return "0123456789"
        
To extend many functions at once do this:

    extends string // or whatever class you want
        function A
        function B
        function C

---
### rz ###
`rz` is a special variable that is automatically created for functions that return things. Simply using `rz` at all, will create the variable, otherwise it won't be created.

````
function string.CountLines (|int|)
    for c in self
        rz += (c == '\n')
````

---
### Bools
Bools have special treatment. You can add or even multiply them with numbers. The above `rz` example demonstrates adding a bool.

However, bools are treated with extra caution when passed to function parameters. This is because almost everything can be converted to a bool, and it is very error-prone to pass let's say an int to a function that takes a bool.

    function ErrorProne (|bool| Param, |string|)
        ...
    
    || a = "a"
    || x1 = .ErrorProne(a)       // fails
    || x2 = .ErrorProne(a!="")   // works

Well, you might **want** that to compile, but speedie won't do it, because its a source of errors. Testing for bools is easy though.
    
    function Example (|string| name)
        if Name // if name != "" then we call .dostuff
            .DoStuff(name)

---
### Implicit "if"
"`if`" can be implicit, in speedie.

    || x = app.args[0]
        printline "You passed param $x"
      else
        printline "You passed nothing"

---
### Datatype Subclassing
Sometimes you want to define a new "datatype". For example Speedie has the "`ErrorInt`" type which evaluates to `true`, if it is **not zero**. This is very useful for unix functions, because they tend to return 0 for success.

Obviously, datatype subclasses can't add properties or have virtual functions. This example datatype will count as "true" for if-tests or anytime a bool is needed, only if it is an odd-number.

    datatype OddIsTrue (int)
        syntax Cast (|bool|)
            return self & 1

---
### File/Memory Sizes
Speedie has some handy constants!
    
    || x1 = 1KB
    || x2 = 2MB
    || x3 = 1.5MB
    "$x1 $x2 $x3"

Obviously, these are in power of 2, so 1KB = 1024. Reporting sizes can be done nicely too!

    "${x.strsize} ${x2.strsize} ${x3.strsize}" // prints: "1024 2MB 1.5MB"

---
### Parsing
Remembering to use Jeebox instead of making a custom file format, is a good way to reduce code-size, even for very simple file formats like a file separated by lines and commas.

---
### Good Error Handling
Error handling is quite important. Its a skill to get right. The tools available are `stderr` which stores reported errors, and the `#require`/`#expect`/`#error` statements. Lets show some speedie code and then convert it to simpler code, to see how much worse the simpler way is.
    
    main
        || F = app.args[0].ExistingFile    #require
        || jobs = f.parse                  #require
        || list = jobs[@tmp, "jobs"][@arg] #require
        for job in list
            .ProcessJob(job)
        require stderr.ok
        for job in list
            .FinaliseJob(job)
        

Seems simple? Lets look at a version written **without** the Speedie error handling system.

        
    
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
    

As you can tell, this is a mess. Doing it the non-speedie way is a mess, and makes error-reporting **worse**. For example, filepaths are now buried in an error-message, rather than separate and easy to parse.

Why is is so much worse?

+ We need to print often, to replace the inbuilt-error-reporting in many functions like `.ExistingFile`... and the fact that Speedie prints `stderr` on exit.
+ We have to `return -1` often, to replace the inbuilt `return -1` you get when your program exits but `stderr.ok==false`.
+ We must replace the same functionality (`printing`/`return -1`) for testing for message types or names. This makes code unreadable.
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

Speedie's error-reporting system has a lot more features, such as:

+ Reporting warnings, which get printed but like normal but leave `stderr.ok` true.
+ Logging of errors to a logfile
+ Treating errors as warnings during certain code-sections
+ Can temporarily replace `stderr` with another `ErrorList` during certain code-sections, in case you want to contain your errors from harming the rest of the program.

Overall it is a great thing. Use it if you need to deal with errors or generate errors. Sometimes you don't want errors to occur, like when reading from a file that doesn't exist, but actually I've already thought about that. `file.ReadAll` defaults to ignoring non-existing files.

    || x = "/path/to/optional_file"
    || data = x.file.readall
    printline data

This only ignores "file doesn't exist", not "the file is actually a folder", or recursive-symlinks, or some other file-system error.

---
### How do we know an Error Occurred Just now?
OK, so `stderr` will tell us if an error has occurred sometime in the past, not "just now". How to know if it happened just now? Mostly... by returning `nil`, or `false`, or some value that evaluates to `false`.

For example parsing a string, will return `nil` if an error occurred during parse.

If copying a file fails, it will return an `ErrorInt` of -1, which evaluates to false. So you can do:
    
    require File1.CopyTo(File2)
    "$File1 copied successfully"

_Conclusion: The general way of detecting **if** an error just occurred in a function-call, is checking if the called-function returned something that evaluates to false._
