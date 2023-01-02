## More Advanced Subjects

Like any language, there are rarely used pieces of it that are fundamentally vital for the language to work properly. Mostly because they are used internally.

Sometimes its useful to know about these things...



## Roles
Roles are just classes... that aren't really a separate class. OK that doesn't explain much so let's just say this. Imagine the `class` "person". Person does a lot of things. He can bake, run, climb, do math, even painting and writing. And a lot more too.

Well... imagine that this isn't very useful in structuring a program, because you want to give some extra abilities to this "`Person`" class, but really, dumping all that extra features onto one class is too much.

Let's say you wanted a specific kind of `person`, let's say a `fireman`.

+ You could add all the "Fireman" functions to `Person`. 
+ Or you could subclass `person` with `Fireman`.

Neither is very good. A person can become a fireman or stop being a fireman. You could structure person a bit better with a "`Job`" property, but thats no good either.

What you really wanted to do was to add `Fireman` functions to person, **without** dumping them onto most code. So that is exactly what a role is.

A role is a class pretending to be a subclass... without really being a subclass. It is useful for the `Message` class most of all, because `message` is so generally useful (kind of like a person), that you can actually use message for almost anything.

Which isn't great because then `Message` becomes too complex in it's behaviour and description. What you want, is for "Subclasses" (Fake ones) of Message that really are just plain messages, to have a "role".

For example, `ListViewRow` is actually just a `message`

## File.ReadAll on non-existing files?

Let's say you call `.readall` on a file that doesn't exist on the file-system. Well... speedie is helpful here, because `.Readall` returns not a string, but a `StringThatWasReadSafely`.

You have to keep that in mind when calling `.ReadAll`. But this behaviour is usually better.

`StringThatWasReadSafely` only evaluates to `false`, if the function returning it, had an error. So a `StringThatWasReadSafely` of `""`, actually evaluates to `true`!

_Reminder: The general way of detecting **if** an error just occurred in that function-call, is checking if called-function returned something that evaluates to false._

That is why this behaviour exists.


## Memory-Layers

`MemoryLayer`s are a concept I came up with myself. I use them for Jeebox, for it's parser. Basically, when you are parsing a file, you want all the `message`s to belong to the same `"MemoryLayer"`.

This means, that all the messages **know** what file they belong to, without actually each message object storing the file itself. The `"MemoryLayer"` stores the file reference!

Its just a simple way of saving memory and making things go faster, for something quite complex and large like parsing a Jeebox file. Very useful, at least internally.

`MemoryLayer`s aren't well documented but you can look at `Object.spd` file to see the functions on the `MemoryLayer` class. Layers can be created, used, or the default `MemoryLayer` can be used.


## debugat
Sometimes an error occurs but you don't know what caused it. The cause is buried too deep in the callstack, and only occurs on function-call 100,852x.

That's where `debugat` is useful. `debugat` is only used when using xcode to debug the C++ output, right now, but later it will work from Perry too.

    function WhyIsThisCrashing (|myclass| o)
        for .Amount
            o = .DoAlotOfWork(o)
            if o.property == 1 // nilobject crash
                o.DoSomething
        // checking nil would only hide the problem.

So lets first add debugat, to find WHEN its happening:
        
    function WhyIsThisCrashing (|myclass| o)
        for .Amount
            debugat 0 // makes a counter called lDB
            o = .DoAlotOfWork(o)
            if o.property == 1
                o.DoSomething

Next time it crashes, you will find lDB contains a number, lets say it crashed on call 99955.
        
    function WhyIsThisCrashing (|myclass| o)
        for .Amount
            // breakpoint fires when the counter hits 99955
            debugat 99955
            o = .DoAlotOfWork(o)
            if o.property == 1
                o.DoSomething

Now we can step through the code to see where it happened. Quite a useful approach in general, not just in Speedie but in any language.


