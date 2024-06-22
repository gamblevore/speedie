# Comparing Speedie To C

Speedie is basically C with a lot of extra stuff ontop. Libraries, syntactic-sugar, automatic memory-management, etc etc.

So Speedie has all the speed benefits you get from C, with a few more like having faster memory-allocation, and high performance libraries.

But there are some differences, things you can't do in Speedie that you can do in C. Hopefully they are mostly bad things :) Lets look at why thats a good thing:


**C allows returning structs and passing structs from functions.**

This makes no sense, because structs can't fit in a register and are meant to be memory-locations. C-compilers will SOMETIMES transform this into passing addresses of a struct instead of the struct itself. And sometimes put it into a register if it is a single field struct. (So why not just make it a data-type then?)

This is worse (for a language designer) than ALWAYS doing it because it is harder to optimise around something you can't rely on. It also makes the language more complex. If all structs are passed and returned via pointers... then if you want a pointer to a struct, you can just specify that the function takes or returns a struct. Thats how it is in speedie.

Example:

    || x = MyStruct.new
    // secretly gets turned into this:
    |MyStruct| x
    MyStruct_Constructor(&x)


**C allows saving the address of a local variable.**

You can then pass it to a function, swap the addresses around randomly, store it in a global. How on earth is any of this optimisable? If you can't rely on that a function won't save the address of one of your local var... then you can't optimise it. That local var now CANNOT be a register-based var. Useless!

    int x1 = 1; int x2 = 2;
    int* y = RandomBool() ? &x1 : &x2; // not possible in speedie.
    (*y)++;


I checked over 4000 functions in 1MB of speedie code, and I found I used this in 3 places, and all 3 places didn't need this "feature"... I was just trying to call a function and pass the address of a register to a function. (Which speedie allows as an exception to the rule).

Removing this makes the language make much more sense, and actually be optimiseable, as you can make assumptions about how the registers work and how they are, and that "other functions can't just come in and silently change our registers", which makes no sense to do but C allows it.

You can still work with address of ints (if you need) in speedie. But they have to belong in a struct or c-array or some allocated memory. Not a local var.


**Speedie has many [safety features](../Safety.md) to protect you from writing bad code.**

* Type-casting objects is restricted safely
* Our awesome nil-checker
* Float / int conversion must be explicit
* And more

If you want to write reliable code for large projects, Speedie has real advantages over C/C++. 

