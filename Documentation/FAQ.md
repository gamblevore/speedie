# Frequently Asked Questions


Just a list of questions and answers.


### The code does not compile right now for me!

Speedie's compilability is currently "bleeding edge". It runs very well once it compiles, but every so often I make a minor change from my OSX computer, and which breaks Win/Linux compiles. And I don't notice this for months until someone tells me. Please let me know when speedie is broken!

This will change when speedie has it's official release. It should become more stable.


### Does speedie get transpiled to c++? Or does it use a VM?

Currently Speedie transpiles to C++, but almost entirely the C part of it. I am working on the ASM/VM part of Speedie.


### Does Speedie have runtime-sized arrays?

Of course. However the array class stores for objects only. Speedie will wrap `ints` / `floats` / `pointers`  before storing in an array.

Theres also a memory class, and even also C-arrays. You can even `malloc, but then you have to take care of memory issues yourself.

In general, you should ALWAYS stick to high-level design. (Use objects, not pointers.) Even for me, messing around with pointers and structs and carrays is always less productive than simply sticking to objects. And generally leads to less powerful code. And thats ONCE you get past the bugs!

But sometimes, it makes no sense to write code without. For example, an image editor program, or audio-editor. Here is the mental checklist you should ask yourself before ending up mallocing anything:

* Do you need an array of objects. If so, use the array class.
* Do you need an array of structs? Can those structs actually just be objects in the first place? If so, rewrite those structs as objects, and use the array class.
* Are you collecting a list of pointers to structs. Structs that come from outside of speedie? From some 3rd party C++ lib. Try storing those pointers in the array class. (Speedie automatically wraps them into objects for storing.)
* Are you collecting a bunch of other datatypes (ints/floats/pointers), and only say 10000 or so? Use the array class. Same as above.
* Are you making something involving images. Consider the `Image` class. It takes care of most memory issues, although getting a little more dangerous now. One bug would be taking a pixel address, doing math on it to go beyond image bounds. The `image` class gives you a safe alternative via pixel accessor functions that clamp the XY coords.
* You absolutely need an array of structs or data-types, and none of the above apply. Use the `memory` class. (The `image` class is based on this). `Memory` will take care of some issues but less than `Image`. It mostly takes care of auto-freeing, but not bounds safety. You can mess it up in any number of creative ways.
* You just breath C coding, and know C inside out, and don't feel like using the `memory` class. Use `malloc`. Im not your dad, and its your code. You access malloc via `Memory.zalloc`, which returns zero'd memory always, but its still just `malloc` under the hood.


### Are you like Terry Davis?

Terry (RIP), the brilliant programmer he was, tragically was blighted by schizophrenia. Few people could be like him, and no one would want to. It is a tragic disease.

It is a shame that the first thing some people think of when they hear "programmer who did a lot of stuff himself" is "Terry Davis". For a more balanced view on "programmers who did a lot of stuff by themself" have a look at [https://www.reddit.com/r/ProgrammingLanguages/](https://www.reddit.com/r/ProgrammingLanguages/) you'll find hundreds of people who have made their own programming language. If you want, you can write a post there and tell them that anyone who made their own language must all be Terry Davis. See how they respond.


### Whats with the MMI interest?

My MMI interest are mostly goals, not current work. But I did some work for randonauts a while back. They are defintely worth a look at. I never achieved anything more on MMI, than I did working with them. I acheived less alone than together with them.

It was wonderful to have a group of smart people who can talk about strange things just casually. Almost all with suprisingly conventional careers. One even made a very popular library for C# that almost all C# developers end up using.


### Is it hard working, unsupported?

Yes. It is hard. It could be made much easier if you were to [support me with sponsorship](https://github.com/sponsors/gamblevore). I hate begging especially if I beg and get nothing for it. But I am definitely less supported than I need. So basic needs are unmet. But I thank all my current supporters with my life.
