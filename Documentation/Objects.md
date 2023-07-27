## Objects in Speedie

Speedie is a refcounted language. That is, objects in Speedie know how many references to them exist. This makes Speedie better than garbage-collected languages. Because we delete objects as soon as we are done with them. 

This leads to smoother performance, in games or other high-performance things. Its faster overall too.

	|| S = "Abc"
	|| S2 = S
	|| S3 = S
	// by now, "Abc" has 4 references to it
	// One for the string itself
	// and 3 more for the variables S, S2 and S3!

Objects in Speedie belong to classes, which is nothing new to programmers. A class is... well its hard to say what a class is. I guess its a way of looking at data, to give it some meaning.

Technically, a class contains these things:

+ A list of properties
+ Functions that work on the class.
+ A parent in the class-hierarchy.

The class's parent might just be "`object`" or it could subclass from something else, like "`RingTree`" or one of your own classes.


## Reference Cycles?
You might find yourself wondering: _"Well how do I make a tree, or a double-linked-list in Speedie, without suffering from ref-count-cycles?"_

Its a good question, but the answer is usually... use `RingTree`. Its not always true, but its a good place to start. `RingTree` uses linked-lists internally... and describes a tree, while taking care of all the ref-counting issues. It just makes your life simple. 

`RingTree` is useful for trees in general, but also for linked-lists. Otherwise, you'll have to clear the ref-cycles yourself, in order to free memory.

## Working With Classes

Objects have classes, which can be accessed via .class

	|| Cls = "Abc".class
	printline cls.name // string

You can create an object like this.

	|| msg = message.new
	
Technically, you are accessing the module "message", and then the "new" function on that module. The "new" function comes from the constructor defined on the class message.

Object types can be tested using `isa`.

    function Example (|object| abc)
        if abc isa file
            printline abc.readall
          elseif abc isa message
            printline abc.render

Once you test the type of an object, you don't need to typecast it anymore within that branch. This means that actually, typecasting is something to avoid. Just test a type, don't blind-cast.

Another way to typecast is using the `as` operator:

    function Example2 (|message| msg)
        || file = msg.obj as file
        if file
            printline file.readall

If msg.obj is nil... this is OK but it will still return nil. If msg.obj is not nil and not a file, then `as` will create an error and return nil. The error will be stored in `stderr`, but the controlflow is not altered.

This is MUCH better than blind-casting! Turning a RingTree into a file blindly... would cause all sorts of issues. And creating an exception would SUCK totally... because it destroys control flow. This approach is really nice.


## Subclassing

Subclassing is done like this:

    class MapArea (RingTree)
        contains MapArea
        function Draw (|image| dest)
            ...

`Contains` is needed when you subclass a container class (like `RingTree`, `array`, `dictionary`, etc). Otherwise it's not needed.

    class A
        |string| Name

    class B (A)
        |int|    Number
    
    main
        || bb = B.new
        bb.number = 1
        bb.name = "fred"
        if bb isa a
            "bb isa A"
        if bb isa b
            "bb isa B"


## Container Classes (array, dictionary, etc)

Classes can have contained types. For example, you can declare something as an array of string, rather than just an array of any-old-kinda-object.

    |[string]| MyStringArray
    |[]| MyArray
    || MyArray2 = []
    
    MyArray <~ "apple"
    MyArray2 <~ "apple"
    MyStringArray <~ "apple"
    for s in MyStringArray
        printline s.uppercase
    for s in myarray
        printline s.uppercase // FAILS
    for s in MyArray2
        printline s.uppercase // FAILS

The two failing lines, fail, because they don't know that they contain strings. They've lost that information. That's why for container classes, its sometimes (or often?) better to define their type fully.

However, for function parameters or class-properties, actually you'll always be defining their type fully anyhow.
    
What about writing a container class yourself? Well, you can do this, or you can adapt an existing container class. The main thing, is how to write a function that returns _"the contained type"_.

    class ContainerClass
        contains object
        |array of ...| InternalData
        syntax Access (|int| position, ||)
            return .InternalData[position]
        syntax append (|| value)
            .internaldata <~ value
            
    main
        |containerclass of file| CC = containerclass.new
        CC <~ file.desktop.child("me.png")
        || path = CC[0].path
        printline path //   "/Users/NAME/Desktop/me.png"
        

Kinda strange syntax right? We are returning `||` from a function and we have an "`array of ...`"

The "`array of ...`" means "this array contains whatever type it is that we contain". The same with  `||` in the function return. Two ways to say the same thing.

