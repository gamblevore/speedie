## More Advanced Subjects

Like any language, there are rarely used pieces of it that are fundamentally vital for the language to work properly. Mostly because they are used internally.

Sometimes its useful to know about these things...



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


