## Optimisation Tricks

This is a document meant to explain how to optimise your code. Actually a lot of this is language-independant. Not about Speedie at all.

But I've seen that optimisation strategies are very popular on YouTube... so why not put a few here.



### Put Fast Things First

    function Example (|int| i, |string| s, |bool|)
        if s == "hello" and i > 0   // slower
            return true
        if i > 0 and s == "hello"   // faster
            return true

If you have two or more tests that must be passed, put them in order of speed. Its a simple optimisation, but a good one that is often overlooked.

The examples here, aren't meant to function as real code. Just be useful examples.



### Bit Math Is Fast

Anything you can do with bit math instead of other approaches is usually going to speed things up.

    // slower
    class HappyClass
        |bool| A
        |bool| B
        |bool| C
        |bool| D
        |bool| E // many boolean properties
        
        function Happyness (|int|)
            return .a + .b + .c + .d + .e
        
        function Passed (|bool|)
            return .a and .b and .c
    
    
    // Faster
    class HappyClass
    	|HappyFlags| Flags
    	
    	syntax is (|happyflags| F, |bool|)
    		return (.flags & f) == f
    		
    	function Happyness (|int|)
    		return .flags|int|.CountBits
    		
    	function Passed (|bool|)
    		return .flags is abc

    datatype HappyFlags (int)
    	flags
    		a
    		b
    		c
    		d
    		e
    		abc = a+b+c

    	syntax is (|happyflags| F, |bool|)
    		return (self & f) == f
    	
        
    
Using this approach above, you can actually test for many things at once.

In fact, if you are allocating objects **just** to pass around multiple boolean values, and nothing else... you can reduce it simply to an integer datatype.



### Combine multiple-passes

    function ProcessItems (|[item]| list)
        for t in list
            t.TestForSomething
        for t in list
            t.TestSomethingElse

        // this is faster
        for t in list
            t.TestForSomething
            t.TestSomethingElse

It may seem obvious, but its easy to forget this in the middle of a lot of late-night hard coding efforts.


### Linked Lists Are Faster Than Arrays!

Linked lists, are (usually) faster than arrays! Depending on what you are doing, of course. In general, object arrays are rarely the most optimal approach in fact.

In speedie, the linked-list class is simply called "[List](lists.md)".

For example, in Speedie, I have a few lists of "messages" (parsed Jeebox) that need later processing. I remove them from whereever they were... and place them on a list. This list, I can later process. This saves me from having to create an array to store things that need later processing.

The nice thing about linked-lists, is that the next (or prev, parent and child) items are all directly accessable. Whereas for processing an array, three extra memory reads must occur to get the next item, which is slower. Plus you need two extra variables to check (the array itself, and the array index).

Again... don't blindly do this. You'll slow your code and blame me. Just do it where it makes sense. If the object never made sense to be a list in the first place, don't do it!



### Don't Repeat Work (Caching)
    
    function Example (|string| s)
        // slower
        if s contains "frog"
            .FuncA(s)
        .FuncB(s)
        if s contains "frog"
            .FuncC(s)

        // faster
        || IsFrog = s contains frog
            .FuncA(s)
        .FuncB(s)
        if isfrog
            .FuncC(s)


Another good example, is setting a flag or value on the object itself.

    class frog
        |bool| Passed
        |string| Name
    
        constructor (|string| name)
            .name = name
            if name.IsAGoodFrogName
                .passed = true
            
        function Example2 (|frog| f)
            if .Passed
                .FuncA
              else
                .FuncB

Depending on how your code works... this can be very useful. Especially if done in the constructor or early in the code. It can also be done in some kind of accessor function.

    function Message.WorldLocation (|Place|)
        || o = .obj
        if o isa Place
            return o
        rz = .CreatePlaceFromMsg
        .obj = rz


Caching of results can be useful too. The above cases don't *really* count as caching, as its just simple variable in a function, or a small property in an object. But caching can help, sometimes.

[Perry](Perry.md) uses caching for editing documents. This saves us re-loading files from disk each time we switch from editing one file to another. This caching also helps searching through files if we already loaded them.



### Use Better Strategies

This one is a bit of a silly one, but a good advice actually. There are all sorts of useful algorithms to improve various tasks. This one I can't give specific advice on, because it varies per area. But here are some nice examples:

* 3D graphics, might use screen-space culling strategies when drawing many objects.

* 3D hit-detection might use some kind of spatial partitioning scheme. (OctTrees for example).

* A game might speed itself up by declaring object types hit-detection modes... for example "bullets" might be declared as being able to pass through each other. In that case, we don't need to check bullets vs bullets, we can put all bullets on the end of a linked-list, and everything else on the start of the same list. If you are comparing a bullet to the list, just stop once you hit first bullet. *(Linked-lists in Speedie are equally fast to put items on either end.)*

* If you are searching through an (unchanging) array for some items... you could speed it up by making sure the array is sorted, and using a binary-search.

* In making Speedie, I actually kind of "invented" a new approach to replacing dictionaries with an array (in my linker). Its a bit complex to explain, so I won't, but I'll just say that I placed an integer property in my linker, and used it to check if a function had been linked already. Its a bit more subtle than it sounds... not obvious at all if you look at the original use-case. It didn't **look** like something that could have been sped up in this way. But it was a better strategy, thats all that counted.

The last example saved me about 1/3rd of the RAM use, and the program ran much faster.



### Don't Do Dumb Things

This one is too grand to really explain what counts as a "dumb thing"... But heres one good example. Many languages, and then most programs made in them, allow strings to exist in many input formats. UTF-8, UTF-16, Latin-1, Shift-JIS, etc.

Each string function, such as string-searching, then also has to have special functions for each format! And (hidden) conversion between formats when comparing strings!

Why? When you can just use UTF-8 throughout.

Many languages still manage to mess this up, by indexing your UTF-8 strings on a per-character basis, meaning your string accessing is slow.

Speedie is smarter, because it accesses strings on a byte-basis. This is faster. And it "just works", because of how UTF-8 was intelligently designed. [utf8everywhere.org](http://utf8everywhere.org) 

Languages that do this the wrong way, make string searching impossibly slow, any it can only get reasonably fast by using caching techniques, which is just silly, over-complex and never gets the original speed back.



### Function Pointers vs if-else Chains

If you have a large if-else table to decide what code to run... using function pointers instead, is usually a better idea. Assuming your code is basically just a table in the first place, that was expressed via if-else.

Use a dictionary instead of a large if/else table on matching strings. You can even store function-pointers in a dictionary. Or use an array if the index is an integer.

If your table is large enough, this can help. (Not if its like only 2 or 3 cases, but more like 10 or more).

Another possibility, is to actually place function pointers **on** the actual object to be processed. Perry uses this, and the Speedie GUI system does this a lot too. Makes life a lot easier.



### Dictionaries / Arrays etc

Knowing how and where to use dictionaries and arrays will help. This is so common to programming I won't explain it here, as its true in every language. There are plenty of advice on this one elsewhere. But its true in Speedie too.



### Stack vs Allocating Arrays

Using the stack is very powerful... if you can do it. This just means allocating objects within a function. Or even declaring datatype variables, then calling your function recursively. Only do it where it makes sense, of course.

This can save you allocating an array object, and having to append into it.

Speedie actually does this, when "opening and closing" variables. That is... when you declare a variable in speedie, it needs to "allocate" a register for that variable. And later, deallocate it, when its no longer accessible.

Speedie acheieves this, by using the stack, instead of appending to some global array of "current variable state". We do something like this:

    function ProcessArgument (|message| Statements)
        |uint64| OldState = .OpenVars
        for line in statements
            .ProcessLine(Line) // recursive function!
        .CloseVars(OldState)

`ProcessLine()` is recursive. That is: it calls other functions that can call back into `ProcessArgument()`. Best thing here... is that I don't even allocate any objects for my stack. The saved info takes only one register!
    
        



### Avoid Overly Dynamic Code

This is kind of natural in speedie anyhow, as virtual functions don't "just come naturally" like in C++ or Python. You have to explicitly declare them. But if you don't need them, don't use them.

    function OverComplex (|MyType| A)
        A.__DoSomething__              // a virtual function
    
    function NotOverComplex (|MyType| A)
        if A.Type == kBigType
            A.DoBig
          else
            A.DoSmall
        


### Tail Functions

Tail functions are usually a very good optimisation trick. Sometimes they don't naturally happen, so you can even tweak your code to make it easier to happen.

    function ReturnLengthIfNameIsCorrect (|string| s, |int|)
        || x = s.length
        if x > 4
            return innerfunc(s, x) // tail call!
        return -1
    
    function InnerFunc (|string| s, |int| x, |int|)
        if s == "elephant" or "horse"
            return x
        return -1

This works, because the compiler doesn't have to spend so much time popping and pushing variables onto the stack.

It works even better, if the variables are all in the same location! For example, this, doesn't tail optimise so well.

    function ReturnLengthIfNameIsCorrect (|string| s, |int|)
        || x = s.length
        if x > 4
            return innerfunc(x, s) // compiler has to move registers around
        return -1
    
    function InnerFunc (|int| x, |string| s, |int|)
        if s == "elephant" or "horse"
            return x
        return -1



### Jbin vs Jeebox

If you have some large files that need to be parsed often, use [jbin](jbin.md) instead of jeebox. Assuming it makes sense to, of course. [Jbin](jbin.md) is the binary form of Jeebox, it stores the same data, its just faster, but not human-readable.

[Perry](Perry.md) can edit and display [jbin](jbin.md) as if it were a text-file, so not being human-readable isn't such an issue.



### Use Bit-Tricks When Needed

Bit tricks can really speed up code. For example... to check if a number is a power of 2 (1,2,4,8,16,etc)... you **could** test all 32 possibilities in a 32-bit unsigned-integer.

Or you could do something like shift it down one bit at a time, to see if it hits the number 1... making sure that before you shift, the lowest bit is 0.

Neither of those make sense. Theres a simple bit-hack that acheives this in one go:

    || XIsPowerOfTwo = (x & (x - 1)) == 0

Works perfectly. I've wrapped this into a function called .IsPow2, but the point remains. Knowing bit-tricks really helps.

There are many bit-tricks... at least 20 you can learn if you like! But heres a few:
    
    function FindSign (|int| x)
        || SignBit = x|uint|>>31

    function BoolToOne (|bool| b, |int|)
      //if b
      //    return 1
      //  else
      //    return -1
      return (b<<1)-1
    
    function IsOdd (|int| x)
        // if x mod 2 > 0 // slow
        if x & 1          // fast

    function SpaceRequiredInTermsOf (|int| x, |int|)
        || n = 4 // aligns to 4. Change as you like. Powers of 2 are fastest.
        return x + (-x|uint| mod n)
        // 0-->0
        // 1-->4, 2-->4, 3-->4, 4-->4
        // 5-->8, 6-->8, 7-->8, 8-->8
    
    function BoolMul (|bool| b)
        //|| x = 0
        //if b
        //    x = 5
        || x = 5 * b // this optimises well!
            
    
        
    
Many more are bit-tricks possible!



### Use FastString!

FastString is a class in Speedie, that makes string appends faster. Make good use of it. Its useful for creating large complex documents. But sometimes even smaller strings use it.

FastString is implicitly used anyhow when doing string interpolation.

    function ThisAutomaticallyUsesFastString
        || x = "Hello $user, my name is $NPC, how can I help you this $time"
        // time would be morning/evening/afternoon/night
        
This might help explain FastString:

    function BadAppend (|[string]| items, |string|)
        for s in items
            rz += s // BAD!

    function GoodAppend (|[string]| items, |string|)
        || fs = faststring()
        for s in items
            fs <~ s // GOOD!
        return fs

    render BestAppend (|[string]| items)
        for s in items
            fs <~ s // Best! (fs is automatically created in 'render' functions)



### Simplify Your Code!

Well-written simple code... that is understandable, is also easier to optimise. Its hard to optimise something you can't understand. Sometimes the best way to optimise code, is first to simply stick to good programming practices.

Name variables clearly, function names clearly. Remove all unused variables or parameters, etc, etc. Don't write code-sphagetti. Simplify your code-flow.

Once you've done this, some optimisations might suddenly "jump out" at you.


### Don't Limit Yourself

Don't limit yourself to only thinking about high-level design as if its the only thing that matters. Think about the low-level too! But don't **only** think about low-level stuff... as you'll miss high-level opts.

Low-level stuff usually can fit around high-level thinking. But not always. 

Sometimes some big low-level optimisations will require restructuring on a higher-level. Embrace it. This is life. Life is not hierarchical. Thats for governments and corporations which are highly inefficient. Or other kind of destructive and oppressive "class-based" human-systems.

Efficient people will flow up and down... checking things on each level to make sure everything makes sense on every level. This reflects a classless society, where the "highest" of people also do the most basic simple work. Ensuring everyone has a good time.


### ASM-View!

One nice thing about Speedie, is that by using [Perry](Perry.md) you can access the [ASM-View](VM.md) to see your ASM's output. You can see if your code is sub-optimal this way, or perhaps if Speedie itself is missing some obvious optimisations.

This is like an inbuilt [godbolt.org](http://godbolt.org)!


## Conclusion

There are many optimisation strategies. This is very much a non-complete list. But if you are just beginning to learn coding and want your code to be faster, its a good place to start. You'll be surprised how much "professional code" out there **does not** use optimisations here! And could be made so much faster.


