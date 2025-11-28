## Safety In Speedie

Making your code safe, as in not crashing unexpectedly is a hugely important thing.

Speedie has a lot of safety features built in, including:

* Nil-Safety
* Type-Safety
* Numeric-Safety
* Exceptionless Error Handling
* Loop-Safety
* A Safe Library
* Managed-Memory

### Memory Safety

Speedie's memory-manager is a form of safety... its what you expect from most OOP systems, but its worth mentioning as C/C++ doesn't have it. 

You won't get double-frees (like C++ / C suffers from). And memory is freed once it is no longer refered to.



### Speedie's Safe Library

Speedie's library is safe too. It won't crash. _(If it crashes, then thats a bug that the speedie devs should fix. But I haven't seen that for a long time.)_ This isn't like C++ where `strlen(nil)` can crash your app.

All the basic speedie functions, and classes like arrays, lists, strings, dictionaries, messages, etc, are safe to use, even if you use them improperly.

For example this:

    || myarray = ["hello", "bye"]
    || a = myarray.pop
    || b = myarray.pop
    || c = myarray.pop // returns nil!

That won't crash. It just returns `nil`. Which is totally valid. Same with accessing `myarray[-1]`. `C` just becomes `nil`.
    


### Loop Safety

Speedie recognises a basic infinite loop. Not all but a basic one. It also recognises a recursion bug.

    function A
        while
            printline "infinite loop?" // speedie does not allow this
    
    function B
        printline "recursion!!"
        B() // speedie doesn't allow this either

Not a common bug, but nice that speedie saves you from it!



### Error Handling

Speedie has a great error-handling system that is exceptionless. It is really nice. Read about [it in it's own article](Errors.md). Its actually perfect.



### Numeric Safety

Speedie has a little numeric safety. Mostly on constants, so you can't define a constant that won't fit its type. Like defining a byte-constant of 1000, which is more than 255.

Also Speedie won't allow `int` / `float` conversions, to happen silently. You need to explicitly convert them. We allow a small leeway when it comes to integer constants, for example adding `2` to a float variable, is OK, as `2` is exactly representable as a float anyhow. We don't allow this for ints that are too big and would lose precision as a float!

In fact, we don't even allow implict floating point conversions between say 32-bit and 64-bit floats (or other sizes). This is because... float-32 and float-64 are basically incompatible formats, meaning you would get a hidden slowdown in your code (if I hadn't added this feature). Work should be explicit.

Also Speedie won't allow passing objects or numbers to a boolean parameter... because this is very dangerous, almost everything is convertible to boolean which means you can easily pass the wrong param!

Also speedie doesn't allow comparing signed and unsigned numbers in an "unclear" way. For example:

    function unclear (|int| x, |uint| y)
        if x > y        // speedie complains here! Rightfully so!
            DoSomething()
    
    function never_true (|uint| y)
        if y < 0  // never true
    
    function always_Ttrue (|uint| y)
        if y >= 0 // always true
    
    function silly (|uint| y)
        if y <= 0 // a silly test. Just write: if y == 0
    

This is OK though!

    function testOK (|uint| y,  |byte| b,  |int| c)
        if y > 0  // just fine!
        if b > c  // bytes fit in ints easily.
        if b < c  // also ok



### Type safety

Speedie is type-safe... this works like you'd expect in most languages. We have the `isa` operator:

    function abc (|object| o)
        if o isa message // o is type-casted to `message` within this branch
            printline m.name
        if o isa file   // same
            printline m.readall
        if o isa string
            printline o

The `as` operator:

    function def (|object| o)
        || m = o as message
            printline m.name
        // only prints m.name if 'o' is not nil and is a message

And the `mustbe` operator.

    function ghi (|object| f, |message| where)
        if f mustbe (file, where)
            printline f.path
        // if `mustbe` returns false, then it creates an error, using "where" to signify where the error came from


Lets finish with the biggest safety feature...



### Nil-safety

In fact, Speedie's nil-checker is mostly invisible. So you won't need to be writing very different code in order to use it. It is mostly silent... except when things go wrong. It is like a silent genius that thoroughly checks your code but rarely says anything... unless it finds a mistake.

The main thing to know, is that you need to specify if your objects or pointers, are "optional"... within object properties.

"Optional" in speedie doesn't mean the same thing as in other languages, it just means "it could be nil". There is zero overhead. And because numbers can't be nil, numbers are never optional! :)

So, to define a class with one optional and one real property, do this:

    class MyClass
        |string?|  Optional
        |string|   Real
        
        function Test
            || v = .optional
            if v != nil
                "v is real"
              else
                "v is nil"

Global properties are a bit different, they are assumed optional unless you create them on the same line. And strings/arrays have default "real" values anyhow, (empty string, empty array), so they are still real.

    module abc
        |myclass| optional
        |myclass| real = myclass()
        |string|  real_string   // same as real_string = ""
        
You can also set a global variable to a real value, but still declare it as optional.

    |myclass?| optional2 = myclass()

Local variables are all figured out for you! Speedie has a full "nil-inferencer". That means it does extensive logic on the nils. So it knows whether something can be nil or not at any point in the code. This is like having a helpful programming companion check your code for you. So its not like the language `Rust` which imposes a dreadful model on you.

Local variables include function parameters, params can be declared as optional or real... However! That only specifies what the caller may send. You can still alter parameters within a function.


    function abc (|message!| m)
        if m.position == 1
            "position 1"
        if random[] > 0.5
            m = nil // we altered the parameter 'm'
        if m == nil
            "m became nil"
          else 
            m.position = 7

You can also specify parameters as "real", or "optional" by putting ! or ? before or after the type.

    function abc2 (|message!| real, |message?| optional)
        "real is not nil"
        if optional
            "optional is not nil"
          else
            "optional is nil"

Param realness can be inferred also:

    function abc3 (|message| A, |message| B)
        if (A)
            "A is not nil"
          else
            "A is nil"
        B.position = 1  // OK. B was inferred to be real.
        A.position = 1  // fails to compile! A was inferred to be optional.
        

Local var inference is super-smart... it won't let bugs go unnoticed. Heres a simple example:

    function bad_loop
        || msg = message()
        for i in 10
            msg.Position++ // <-- compile error!
            if (random())
                msg = msg.next // could leave msg as nil

The nil-checker will complain when we set `msg.position`, because `msg` could be `nil`, at that point... due to something that happens later in the code!

    function fixed_loop
        || msg = message()
        for i in 10
            msg.position++ // OK!
            if (random())
                msg = msg.next #require

This works fine now! Because the nil-checker understands how loops work.

The infererencer only works on local vars, not on object properties or global vars, sadly. But you can copy them to a local var and then let the inferencer do its work.

You can also override the nil-checker using the `!` suffix. This can be pronounced as "bang"... which is what will happen if you get it wrong.

    // parsing this particular string, should never return nil, but speedie doesnt know this.
    || msg = "abc, def".parse
    msg!.position = 30

Obviously, if you get this wrong, your program crashes. The "!" suffix is better avoided, but you will have to decide for yourself. **_You won't ever kick yourself for siding with caution._** This is the safe approach and its not such a problem!:

    || msg = "abc, def".parse
    if msg
        msg.position = 30 // now is nil safe
    
    // or just do this. Same thing but shorter.
    || msg = "abc, def".parse
        msg.position = 30 // now is nil safe

