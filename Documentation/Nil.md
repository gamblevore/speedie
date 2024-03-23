## Nil Safety In Speedie
*(aka "The billion dollar mistake")*

Nil-safety is perhaps the most important issue in making code reliable. Unfortunately it can also be the most difficult problem to fix. Nil-safety is such a huge problem for programming, that it caught a popular catch-phrase "The billion dollar mistake".

Nil-bugs can hide themselves for weeks, months or even years. And after release, you can be left embarassed in front of your users, as to why your code crashes. That... or the consequences can be deadly if the code handles machinery.

Some modern languages are catching up, and adding nil-safety mechanisms in. Speedie is one of those! Speedie's nil-checker is fast and smart. It will probably catch all potential issues.

Speedie's nil-checker should make coding more fun, by removing the pain... Its no fun having to spend hours trying to backtrack some nil-crash bug, back through several subsystems... down to the original point where something was set to `nil`, which silently left a trap for future functions to run.

But when you know that can't happen... things are a lot more fun.

Unlike other languages, the nil-checker in speedie has zero-overhead. We dont have `"optional integers"`, cos they are always real!

Speedie's nil-checker is extremely fast. Adds less than 0.003 seconds of compile time, for about 1MB of source code.

If you are wondering how its that fast, well to be honest, I think programmers are used to inefficient compilers. And they shouldn't be. Computers are super-fast these days, so I just took advantage of that.


### Abilities

The nil-checker checks all the possible states your objects can be, at every point in the code. This makes the nil-checker incredibly powerful.

We want you to write code as naturally as possible. We want people coming from a "write good C code" mindset, to find it easy to write code in `Speedie`! This means **NOT** burdening them with ridiculous levels of syntax (that other languages like Rust do).


### Some Terms Introduced
    
* `Real` means "object is not nil"
* `Optional` means "object might be nil".


### Parameter Inference

To help with writing code naturally, we do "inference" on the parameters. That means we try to logically figure out, how these parameters are used. To figure out if they should be `real` or `optional`.

    function guessable (|message| X, |message| Y, |message|)
        if X.position == -1               // X is now a "real" parameter.
            "X has a pos of -1"           // Because I used X directly.

        if (Y and Y.position == -1)       // Y is now a "optional" parameter
            "Y has a pos of -1"           // because I tested if Y exists.
        if random()
            return message()
    
    function test_guessable
        || m = message()
        || a = guessable(m, m)            // OK
        || b = guessable(m, nil)          // OK
        || c = guessable(nil, m)          // won't compile. X can't accept nil
        if (b)
            b.name = "fred"               // OK
        b.name = "fred"                   // wont compile

We want to make coding more "fluid", so you "flow" better. For example if you wanted `guessable()` to require `X` and `Y` to be `real`, you should remove the test `if (Y)`, and just directly work on the params.

This keeps your code in sync with itself... Meaning you only have to make a change in one place.

Return values are also inferenced to be `real` or `optional`. But if you don't like that, you can declare them:

    function fully_declared (|message!| X, |message?| Y, |message?|)
        if X.position == -1
            "X has a pos of -1"

        if (Y and Y.position == -1)
            "Y has a pos of -1"
        if random()
            return message()



### Nilness declarations

Function parameters and return types, class properties, and even global variables can have their nilness declared. Here are some global declarations:

    |String!|  MyGlobalStr = "abc"       // MyGlobalStr can't ever be set to nil!
    |Message!| MyGlobalMsg = message()   // same
    |message?| MyOptionalMsg             // Could be real or nil

Actually, some of this can be omitted, it will still come back to the same:

    ||        MyGlobalStr = "abc"
    ||        MyGlobalMsg = message()
    |message| MyOptionalMsg
    

Those are the same as above! _(This might change as I feel that having "|type| name" meaning "optional"... can be confusing.)_
 Lets look at how global variables can be set via functions:

    function NoNils (|message!| abc, |message!|)
        if abc.name == "abc"
            return message(@str, "string contents")
        return message(@name, "Fred")
    
    || MyRealGlobalMsg  = NoNils(message(@str, "abc"))    // compiles just fine.
    || MyRealGlobalMsg2 = NoNils(nil)                     // won't compile.

So if a global var is initialised to a function result, it uses that function's declared nilness. So make sure those functions have their return declared!! (`MyClass.new` is always declared `real`. `MyClass()` just means the same as `MyClass.new`)


Properties of classes/structs that are nillable, are assumed `real`, unless specified.
    
    class MyClass
        |object | x                 // x assumed real.
        |object?| z                 // could be nil?

        constructor (|object?| o)
            .z = o                  // OK
            .x = o                  // fails: Can't set .x to optional value.

        constructor (|object!| o)
            .z = o                  // OK
            .x = o                  // OK

Your class constructors need to be designed around how you defined your properties. You can't set a `real` property to `nil` during the constructor, and delay setting it to the actual `real` value later! Even if you know it will never be used as `nil`.

    

        
### General Inference

The nil-checker has a lot of intelligence! Not  actually as smart as you, but often smarter! If you follow the nil-checker blindly, you won't get any nil-crashes. Generally it accepts correct code, without you needing to do anything extra.

    function IAmGood
        || m = message()
        m.name = "A"
        if (random())
            m = nil
            m = message()
            m.name = "B"
          else
            m = message()
        m.name += "C"

    // Above code will compile just fine. However below wont:

    function IAmBad
        || msg = message()
        msg.name = "A"
        if (random())
            msg = nil        // <-- this causes a problem for a future line
          else
            msg = message()
        msg.name = "C"       // this line will fail to compile

The nil-checker also knows about `while/for` loops, `exit/continue` loop statements, nested `if/else` chains, `return` statements, even `app.quit` functions, and all the subtle ways they can affect nilness. Basically it knows programming inside-out and should not allow any `nil`-bugs.

    function bad_loop
        || msg = message()
        for i in 10
            msg.name = "fred" // <-- error!
            if (random())
                msg = msg.next // could leave msg as nil

The nil-checker will complain when we set `msg.name`, because `msg` could be `nil`, at that point... due to something that happens later in the code!

    function fixed_loop
        || msg = message()
        for i in 10
            msg.name = "fred" // OK!
            if (random())
                msg = msg.next #require

This works fine now! Because the nil-checker understands how loops work.

It also knows about functions that imply an object is `real`.
    
    function cool
        || strs = ["cat", "cow", "dog"]
        while
            || s = strs.pop     // Doesn't crash if empty! just returns nil if empty.
            if s contains "c"
                "$s is not nil"
              else
                exit

`string.OperatorContains` is a function that accepts a `nil` `self`, and returns `false` if so.

So if a string contains "c" it can't be `nil`! The most common example is the "`isa`" operator.

    function something (|object?| o)
        if o isa message
            // yay o is not nil!
            o.name = "hooray!"
            o.position = 123
            o.func = @str

The inference only works on function local vars, params and returns. Not globals or class properties. _(This could be extended later.)_ So for example, to use an `optional` global object:

    |message| GlobalMsg
    function NonLocals
        || g = GlobalMsg
        if g
            "GlobalMsg ${g.name} exists!"

        // or use the short-hand
        || sh = GlobalMsg
            "GlobalMsg ${sh.name} exists!"

The nil-checker is also very smart with boolean logic.

    function smart (|message| A, |message| B)
        if !A or !B
            "something was nil"
          else
            // well... both A and B must be real now!
            A.name = "good" // this compiles just fine
            B.name = "nice"
        
        if !A or A.name != "good" // it knows the test on A.name is nil-safe
            "Something is not good"
          else
            "its good"
            
        if !A or !B
            return
        // smart enough to realise that A and B are real now.
        printline A.render
        printline B.render

It also complains about redundant tests... But they can re-enabled with "`?`" if you want. Perhaps to test for out-of-memory bugs.

    function Redundant (|message!| m)
        m.name = "Fred"
        if m                  // won't compile because this is a redundant test.
            m.name = "Mary"
    
    function AllocationTest
        || m = message()
        if m?                 // Testing with ? is OK.
            "m was allocated successfully"



### Smaller Details

But what if you want to set a global to a `real` value initially, but later set them to `nil`?

    |string?|  MyGlobalStr = "nil me later"   // can be nil later
    
Strings and arrays have a "real default" value, so don't need explicitly settng to a `real` value... they are assumed `real`.

    |string| AnotherGlobalString          // starts off with the value "", which is real.
    |array|  TheGlobalArr                 // Starts off with [], also real.

That means that the two examples above, (`TheGlobalArr`/`AnotherGlobalString`) can't later be set to `nil`.

The nil-checkers "intelligence" spans one variable. Testing if a variable is `nil`, then storing that in a separate variable, is something we will miss:

    function lost_track (|message?| m)
        || IsReal = m != nil
        if IsReal
            printline m.render // this code is correct, but speedie doesn't realise and flags it as incorrect.
        
        if m != nil
            printline m.render // speedie understands this!
            
                
    
    
### When you know better !
    
    || msg = "abc, def".parse
    msg.name = "fred" // <-- Nil-checker will not allow this!

So, `string.parse` can return `nil`, if the input did not parse properly.

But we know the input is valid jeebox, so it shouldn't return `nil`. Sadly, the compiler doesn't know this. In fact many problems are proveable to a human but not to a compiler, and not even worth trying to prove because they require general intelligence.

That is why you can override the nil-checker, using the `!` symbol. This works like in most modern languages that also have nil-checkers.

    || msg = "abc, def".parse
    msg!.name = "fred" // Now it is OK.

Unfortunately... in certain code, this is needed quite often. For example, with global variables that are set early in the program, but not immediately.

For example, the code above, could be fixed, in a "safe" way like this:

    || msg = "abc, def".parse
    if msg
        msg.name = "fred" // a nil safe fix

However... I find this to be stupid. Because... I am saying that "I don't know what my program is doing". My job as a programmer, is to understand the code. Maybe not completely and perfectly... but for obvious things like this... absolutely, I should know that the above jeebox code will never fail to parse. So why check that it failed to parse? If I know better?

Once you start writing defensive code like that... where do you draw the line? You can take it to very stupid lengths:

    || Root = message()
    root.first = message()
    ///
    || s = root.first      // s is 'real'. But the compiler doesn't know!
    if (s)                 // the dumb way of doing it
        s.name = "Fred"
    s!.name = "Fred"       // the cool way of doing it.
    

Honestly, I personally just refuse to write bad code... because it is slower, and means that I don't know what I am doing. So... in the above case I would write it in the "cool" way, not the "dumb" way.

The code itself should reflect a knowledge of what the app is doing. If we make unnecesary tests for "`s`" here, that means the code itself is "documenting" that a value I just set could be `nil` despite me knowing better. Which is a nonsense document, that causes confusion to a new-comer.

Code should act not just to tell the computer how to act, but to inform programmers about how your program, language, and APIs work! Overly-defensive code will confuse new-comers.

If I see people walking around the streets of my city, wearing full-metal body armour  anytime they go near a mouse... I might start to believe that mice are dangerous animals. Its like that. It causes misinformation and confusion to young minds. So don't be over-defensive.

Your coding style should be your own... but thats my way. And its the right way.

The nice thing here... is that actually, having saved 90% of your brain power on simple obvious tasks (because of the nil-checker), now you have more brain-power left over for the smarter things that the compiler can't possibly know for you. 

