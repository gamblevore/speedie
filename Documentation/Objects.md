## Objects in Speedie

Speedie is a refcounted language. That is, objects in Speedie know how many references to them exist. This makes Speedie much better than Java or other garbage-collected languages. Because we free things as soon as we are done with them. 

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

You can create an object via a class's module.

	|| msg = message.new
	
All classes have modules, at least for the `myclass.new` function. For example the `file` class has many helper functions, like `file.preferences` or `file.log` or `file.desktop`, etc.

Object types can be tested using `isa`.

    function Example (|object| abc)
        if abc isa file
            printline abc.readall
          elseif abc isa message
            printline abc.render

Once you test the type of an object, you don't need to type-cast it anymore within that branch. This means that actually, typecasting is something to avoid. Just test a type, don't blind-cast.


## Memory-Layers

Heres an advanced feature for objects! `MemoryLayer`s! `MemoryLayer`s are a concept I came up with myself. I use them for Jeebox, for it's parser. Basically, when you are parsing a file, you want all the `message`s to belong to the same `"MemoryLayer"`.

This means, that all the messages **know** what file they belong to, without actually each message object storing the file itself. The `"MemoryLayer"` stores the file reference!

Its just a simple way of saving memory and making things go faster, for something quite complex and large like parsing a Jeebox file. Very useful, at least internally.

`MemoryLayer`s aren't well documented but you can look at `Object.spd` file to see the functions on the `MemoryLayer` class. Layers can be created, used, or the default `MemoryLayer` can be used.








