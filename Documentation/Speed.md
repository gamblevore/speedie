### Speedie is a fast Language


Speedie is designed as a fast language.

Ideally we want everything to be fast! Fast to compile, fast to run, fast to debug, and fast to write code in. That is the ideal, anyhow.

There is a certain beauty in optimising code to run fast. When you remove all bloat, what remains can be a thing of beauty. So while I often mention speed, behind that is a deeper thing. Which is beauty, and efficiency. And behind that is a very spiritual goal, of not wasting the life energy of the planet, that humans are greedily destroying at this moment.

Well I haven't been doing that. I've done the work of 1000 people (or more). And living a low-spending lifestyle... Its not that I'm trying to do this intentionally... it just happens as an unintentional side-effect of my values.

Another nice thing about making code faster by making it smaller, is that debugging the raw ASM is nicer. It becomes "prettier on the inside". Speedie has a very attractive syntax. So it could be said that Speedie is only fast, because I make things of beauty.

But about the language itself, why or how is speedie fast? "_How can a language be faster than C++_?" You might ask. Well... first, lets ask if we are talking about C++ or C--. C-- is when you take C++, treat it like C (no templates, no RTTI, exceptions, etc), and then avoid doing C-level functions like malloc/delete.

And so all you are left with is, is a small-subset of C, doing work on pointers and doing math-operations. In that case, Speedie is the same speed as C--.

However, if you use C++ like C++, that is, you use new/delete, use it's string functions and it's file-functions, you'll find that Speedie's equivalent functions are much faster.

Things get even better	for speedie when you compare it's memory management to C++'s shared_pointers, which are quite slow.
