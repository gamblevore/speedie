### Speedie Is A Fast Language


Speedie is designed as a fast language.

Ideally we want everything to be fast! Fast to compile, fast to run, fast to debug, and fast to write code in. That is the ideal, anyhow.

There is a certain beauty in optimising code to run fast. When you remove all bloat, what remains can be a thing of beauty. So while I often mention speed, behind that is a deeper thing. Which is beauty, and efficiency. And behind that is a very spiritual goal, of not wasting the life energy of the planet, that humans are greedily destroying at this moment.

Well I've been living consistantly with that. I've done the work of 1000 people (or more). And living a low-spending lifestyle... Its not that I'm trying to do this intentionally... it just happens as an unintentional side-effect of my values.

Another nice thing about making code faster by making it smaller, is that debugging the raw ASM is nicer. It becomes "prettier on the inside". Speedie has a very attractive syntax. So it could be said that Speedie is only fast, because I make things of beauty.

#### How can a language be faster than C++?

You might ask _"How can a language be faster than C++"_, as if it is impossible.

Well... first, lets ask something: **Are we are talking about C++ or C-- ??**.

`C--` is when you take `C++`, treat it like `C` (no templates, no RTTI, exceptions, etc), and then avoid doing `C`-level functions like malloc/free.

And so all you are left with is, is a subset of `C`, doing work on pointers and doing math-operations. In that case, Speedie is the same speed as `C--`.

Many popular libraries are written in `C--`, especially sound/graphics/compression libs. But probably most popular libs are written in `C/C++`, for example XML libs, database libs, etc. And so Speedie won't be faster than `C++` for those sound/graphics libs... as they are already `C--`.

In fact, if you look at Speedie's internals... its pretty much written in `C--`, so we are building on a very fast basis.

However, if you use `C++` like `C++`, that is, you use new/delete, use it's string functions and it's file-functions, you'll find that Speedie's equivalent functions are much faster.

Things get even better	for speedie when you compare it's memory management to `C++`'s shared_pointers, which are quite slow. Shared pointers are "new thing" in `C++` and help make it more reliable. Sadly, you lose even more speed.

With speedie, you keep the reliability and gain speed.

