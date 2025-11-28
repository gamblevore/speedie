## Speedie-Isms

Speedie has a lot of speedie-isms.

I just call them 'isms'. The more 'isms' you know, the better your code will look. But you don't **need** to know them. You only really need to know 'isms' for **reading** code, not writing. 

As long as you write generally good code in the first place, your code in Speedie will be also good. These "isms" just make code shorter, which is useful in large projects. With the **exception of error-handling**, that actually **is quite important** to know how to write properly.

[Error-handling](Errors.md) is described in it's own file.

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
    

+ `syntax append`  - Useful if your class can have things appended into it.
+ `syntax equals`  - Used for comparing if two objects are equal.
+ `syntax compare` - Used for comparing if one object is more or less than the other.
+ `syntax access`  - Used for accessing an object as if it were an array. Can take params of any kind, strings or messages even. Can even take multiple parameters.
+ `syntax expect`  - Used for error-handling.
+ `syntax cast`    - Allows a type to be implicitly casted into another type. Mostly used for turning a object into a bool, which is used for `"if"` tests. For example string has a `syntax cast` to `bool`, which returns true for strings with .length > 0. My `FastString` class has a cast to a `string`. Using `syntax cast` outside of converting to `bool`... is **generally dangerous and bad**. I've had issues myself even where I wrote syntax casts that broke stuff all over. But converting to a bool is almost always safe. So just restrict yourself to that and you'll be fine.
+ `syntax is`      - See below.

---
### 'is' and 'isnt'
Sometimes its nice to have constants work for you, rather than you work for them. `Syntax "is"` does that:

    function ClickedOnRow (|listviewrow| row, |bool|)
        if row is Modified
            .UpdateWithRow(row)
        if row isnt Disabled
            .ProcessRow(row)
            return true
    
Where are the names ("modified/disabled") defined? How are they found? They are found via the "`syntax is`" function!

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

The `isnt` operator is automatically defined as being the opposite of `is`. So as long as you define `syntax is`...  then both the `is` and `isnt` operators are enabled for you!

So these two versions are equivalent:

    require row isnt Disabled                     // version one
    if !row.syntaxis(listviewstate.disabled)      // version two
        return nil
    

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
Speedie uses custom operators a lot. For string appends obviously, but for all sorts of classes. For example, you can compare an array to an int. `Strings` too. And `list`!

    || x = ["a", "b", "c"]
    if x == 3
        "$x has three items."
    || H = "house"
    if H == 5
        "'$H' has five letters"
    || L = "(a,b,c,d)".parse
    if L == 4
        "The list $L has four items!"
        
`Isa` works on ints too, it checks if something is a multiple of something else. `(x isa 3)` is `true` for 0, 3, 6, 9, etc.

    || x = 0
    for i in 10
        if i isa 2
            "$i is even"
            x[i] = true
          else
            "$i is odd"
    "x is $x"
    
We can also set bits on ints even. Like above where I did `x[i] = true`, that is setting an individual bit on an int.

We have ternary expressions too. Useful sometimes.

    || x = (.LeftHand, .RightHand)(BeLeft)

Strings can be divided and multiplied. Dividing just calls `.split`.
    
    printline "hello,goodbye,away" / ','
    // prints: ["hello", "goodbye", "away"]
    Printline "abc"*4
    // prints: "abcabcabcabc"


For GUI dialogs or human-readable messages in games or in logs... you sometimes might want to display the number of items of a thing. For example "3 dogs" or "2 dogs" or "1 dog". For example you might want to say:

    "The folder $fol has $n files"

But what if `n` is 1? `"the folder /path/ has 1 files"`? That doesnt read right?! Speedie has the solution.

    "The folder $fol has ${n of `file`}"
    
Or more simply:

    || substr = n of "file"
    "The folder $fol has $substr"

Its not a hard thing for anyone to code without the '`of`' operator. But its so awkward that people normally don't bother. The real trick is that I made it simple and convenient.

---
### Printing Strings

Speedie lets you print strings, without a printline statement. Quite handy. Our prophet Terry Davis taught us this, and we should respect his holy wisdom.

    main
        "hello you cutie-pie ❤️ 🥰 😘" // prints to stdout


---    
### main

`main` is the first function your program runs. Speedie has a neat way of working with `main`. Speedie understands, that usually, what people want to do, is work with functions. Functions are good, because they specify the inputs and outputs. If you pass the wrong inputs and outputs, your program doesn't compile. Thats normal.

So why is it different when dealing with the `main` function? _"Well... it just is?"_. But in Speedie, things work better. You can define inputs for the `main` function. This validates input before your code runs.

    #!/usr/local/bin/spd
    main (|[file]| Files)
        expect (files) ("No files passed!")
        for f in files
            "$f: ${f.size.strsize}"

Try calling this with a few files, from the terminal: `/usr/local/speedie/Examples/main.spd /usr/local/speedie/Library/*`

You should see this output:
    
    /usr/local/speedie/Library/CppLib: 3.0KB
    /usr/local/speedie/Library/UnicodeLetters.txt: 33.2KB
    /usr/local/speedie/Library/funcs.jbin: 62.7KB
    /usr/local/speedie/Library/libSDL2.dylib: 3.0MB
    /usr/local/speedie/Library/library.input: 2.1KB

You can't specify the output, as `main` always returns an `int`. You can specify a few things with `main`'s arguments. Not everything, but some basic ones: `string`, `int`, `float`, `file`, `message` and arrays of these. You can only use array **once** and it must come **last**.

    main (|int| Count, |string| Msg, |float| Fraction)
        for i in Count
            "$Msg: $Fraction * $i = ${Fraction*i|float64|}"

Running this you should see:

    /usr/local/speedie/Examples/main2.spd 3 "hello" 1.3
    hello: 1.3 * 0 = 0
    hello: 1.3 * 1 = 1.3
    hello: 1.3 * 2 = 2.6

You might wonder: _"Was it even worth adding this feature?"_ Well... its great for demos! Short simple demos to demonstrate how to use speedie! It just cuts out all the clutter. And for more professional use, it standardises input and how things work. It also gives useful error messages:

    /usr/local/speedie/Examples/main2.spd 3 "hello"    
    error: Missing Fraction (float).

This is a purely compile-time feature made from syntactic-sugar. So if its not used, it adds nothing to your app.

As an easter egg, try writing just `main` as your entire program. Nothing else. See what happens.

    
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
    
Obviously the first version looks better. So don't worry about appending strings with embedded expressions! Its pre-optimised. (Also appending a string constant of 1 byte long, is optimised into appending a byte-number.)


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
This will return the value of `rz`.

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

### Random Numbers

Sometimes you just want a random number. Perhaps for a test or demo project. If thats all you want, try this:

    || x = 6() + 1        // Returns an int from 1 to 6.
    || y = (x+6)() + 1    // Returns a number from 1 to 12, weighted towards
                          // zero, due to reusing x.

Quite handy, and cute for little demos. As for generating booleans, you can do this:

    || Passed = 0.5[]          // One in 2 chance of returning true
    || Third = 0.3333333[]     // One in 3 chance of returning true
    || Sixth = 6th[]           // One in 6 chance...

_(Now remember one thing: Sharing a global random number generator, has replayability issues. But some simple demo code doesn't care or need to worry about that.)_


---
### Implicit "if"
"`if`" can be implicit, in speedie.

    || x = app.args[0]
        printline "You passed param $x"
      else
        printline "You passed nothing"

---
### Datatype Subclassing
Sometimes you want to define a new "datatype". For example Speedie has the "`ErrorInt`" type which evaluates to `true`, if it **is zero**. This is very useful for unix functions, because they tend to return 0 for success.

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
    
 <small>_(We reject the utterly retarded ISO kibble-bytes. We are proudly believe that 1024 bytes is a kilobyte, and that everyone at ISO is a freaking moron who does not understand programming.)_</small>

---
### Parsing
Remembering to use Jeebox instead of making a custom file format, is a good way to reduce code-size, even for very simple file formats like a file separated by lines and commas.


---
### Config Files

Quite often you have some kind of config file, and you want to access it as if it were like a "record". That is... you have rows and values in those rows. Here is an example:

    main
    	|| conf = ConfData.parse		#require
    	"Theme: ${conf[`theme`]}"
    	"Last Opened: ${conf[`date`].date}"
    	"Curr File: ${conf[`curropen`]}"

You should find this example in `/usr/local/speedie/examples/config_reader.spd`

Treating `message` class as a config, is done by accessing it with `msg[string]`. Config files probably need their own documentation file, as there some details, but mostly its just there to enable short-simple code.






