## Speedie-Isms

Speedie has a lot of speedie-isms.

I just call them 'isms'. The more 'isms' you know, the better your code will look. But you don't **need** to know them. You only really need to know 'isms' for **reading** code, not writing. 

As long as you write generally good code in the first place, your code in Speedie will be also good. These "isms" just make code shorter, which is useful in large projects. With the **exception of error-handling**, that actually **is quite important** to know how to write properly.

Error-handling is described in it's own file.

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
+ `syntax cast`    - Decides how an object gets turned into a bool. Useful for `"if"` tests. Also used so you can return a `faststring` object from a function that expects a `string`... because the `faststring` has a cast to a `string`.
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

The `isnt` operator is automatically defined as being the opposite of `is`. So as long as you define `syntax is`...  then both the `is` and `isnt` operators are enabled for you!

So these two versions are equivalent:

    require row isnt Disabled                    // version one
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
    
 <small>_(We reject the stupid ISO change that means 1KB = 1000. That is utterly retarded, and has nothing to do with programming, because programmers need powers of 2 numbers. kibble-bytes or whatever will never be added. We are proud believers of 1024 is a kilobyte and everyone else can go to hell.)_</small>

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

Treating `message` class as a config, is done by accessing it with `msg[string]`. Config files probably need their own file to explain how they work, as there some details, but mostly its just there to enable short-simple code.





