### Speedie Is A Fast Language


Speedie is designed as a fast language.

Ideally we want everything to be fast! Fast to compile, fast to run, fast to debug, and fast to write code in. That is the ideal, anyhow.

There is a certain beauty in optimising code to run fast. When you remove all bloat, what remains can be a thing of beauty. So while I often mention speed, behind that is a deeper thing. Which is beauty, and efficiency. And behind that is a very spiritual goal, of not wasting the life energy of the planet, that humans are greedily destroying at this moment. _(With the electricity power grid.)_

Another nice thing about making code faster by making it smaller, is that becomes "prettier on the inside". Speedie also has a very attractive syntax. So it could be said that Speedie is only fast, because I make things of beauty.

#### How can a language be faster than C++?

You might ask _"How can a language be faster than C++"_, as if it is impossible.

Well... first, lets ask something: **Are we are talking about C++ or C-- ??**.

`C--` is when you take `C++`, treat it like `C` (no templates, no RTTI, exceptions, etc), and then avoid doing `C`-level functions like malloc/free.

And so all you are left with is, is a subset of `C`, doing work on pointers and doing math-operations. In that case, Speedie is the same speed as `C--`.

Many popular libraries are written in `C--`, especially sound/graphics/compression libs. But probably most popular libs are written in `C/C++`, for example XML libs, database libs, etc. And so Speedie won't be faster than those sound/graphics libs... as they are already `C--`.

In fact, if you look at Speedie's internals... its pretty much written in `C--`, so we are building on a very fast basis.

However, if you use `C++` like `C++`, that is, you use `new`/`delete`, use it's string functions and it's file-functions, you'll find that Speedie's equivalent functions are much faster.

Things get even better	for speedie when you compare it's memory management to `C++`'s shared_pointers, which are quite slow. Shared pointers are "the new thing" in `C++` and help make it more reliable. Sadly, you lose even more speed.

With speedie, you keep the reliability and gain speed.


#### The Cake VM

So... in Speedie there will be a virtual machine, as an optional target. You can target `C++` (Speedie compiles to `C` which `gcc`/`clang` will compile), or target `cake` which is Speedie's VM.

A `cake` compile will in the worst-case, run much slower than a `C++` compile. Not sure how much just yet. But you don't need to compile to `cake` if you don't want to. The main purpose of `cake` is to make debugging fast and easy. So you can debug via the VM, then run the `C++` code for release.

Also... Speedie will (before it's release) have an `OpenCL` feature, which can compile certain GPU-friendly code and run it... even within `cake`! So you could make fast graphics apps, and use `cake` more like a scripting system for the graphics. Given a little help from Speedie's libs, like a good hit-detection-system compiled (in `C++`) as part of Speedie's standard-lib, you could even make games run fast even within `cake`, relying on `C++` compiled code to do the heavy lifting.

Once Speedie has built a successful community... I'll be able to start work on a JIT. The `cake-JIT` will run `cake` apps at close to native `C++` speed. The timing on that obviously isn't up to me, it will be mostly due to the choices of a wider community.

The point isn't so much about what `cake` can do today, but what it's potential is. It definitely is the right way forward, even if right now it's not as fast as a proper `C++` compile. Either way, you can just limit `cake` to debugging if you need more speed.
