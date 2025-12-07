### Speedie Is A Fast Language


Speedie is designed as a fast language.

Ideally we want everything to be fast! Fast to compile, fast to run, fast to debug, and fast to write code in. That is the ideal, anyhow.

There is a certain beauty in optimising code to run fast. When you remove all bloat, what remains can be a thing of beauty. So while I often mention speed, behind that is a deeper thing. Which is beauty, and efficiency. And behind that is a very spiritual goal, of not wasting the life energy of the planet, that humans are greedily destroying at this moment. _(With the electricity power grid.)_

Another nice thing about making code faster by making it smaller, is that becomes "prettier on the inside". Speedie also has a very attractive syntax. So it could be said that I only try to make Speedie fast, because I appreciate things of beauty.

#### How can a language be faster than C++?

You might ask _"How can a language be faster than C++"_, as if it is impossible.

Well... first, lets ask something: **Are we are talking about C++ or C-- ??**.

`C--` is when you take `C++`, treat it like `C` (no templates, no RTTI, exceptions, etc), and then avoid doing `C`-level functions like malloc/free.

And so all you are left with is, is a subset of `C`, doing work on pointers and doing math-operations. In that case, Speedie is the same speed as `C--`.

Many popular libraries are written in `C--`, especially sound/graphics/compression libs. But probably most popular libs are written in `C/C++`, for example XML libs, database libs, etc. And so Speedie won't be faster than those sound/graphics libs... as they are already `C--`.

In fact, if you look at Speedie's internals... its pretty much written in `C--`, so we are building on a very fast basis.

However, if you use `C++` like `C++`, that is, you use `new`/`delete`, use it's string functions and it's file-functions, you'll find that Speedie's equivalent functions are much faster.

Things get even better	for speedie when you compare it's memory management to `C++`'s shared_pointers, which are quite slow. Shared pointers are "the new thing" in `C++` and help make it more reliable. Sadly, you lose even more speed.

With Speedie, you keep the reliability and gain speed.


#### The Cake VM

So... in Speedie there will be a virtual machine, as an optional target. You can target `C++` (Speedie compiles to `C` which `gcc`/`clang` will compile), or target `cake` which is Speedie's VM.

A `cake` compile will (in the worst-case) run much slower than a `C++` compile. Not sure how much just yet. In the best case, it will run almost as fast, assuming you are mostly "leveraging" complex lib funcs. (`string.parse` is one of them.)

But you don't need to compile to `cake` if you don't want to. The main purpose of `cake` is to make debugging fast and easy. So you can debug via the VM, then use the `C++` target for release.

Also... Speedie will (before it's release) have an `OpenCL` feature, which can compile certain GPU-friendly code and run it... even within `cake`! So you could make fast graphics apps, and use `cake` more like a scripting system for the graphics. Given a little help from Speedie's libs, like a good hit-detection-system compiled (in `C++`) as part of Speedie's standard-lib, you could even make games run fast even within `cake`, relying on the standard-libs to do the heavy lifting.

Once Speedie has built a successful community... I'll be able to start work on a JIT. The `cake-JIT` will run `cake` apps at close to native `C++` speed. The timing on that obviously isn't up to me, it will be mostly due to the choices of a wider community.

The point isn't so much about what `cake` can do today, but what it's potential is. It definitely is the right way forward, even if right now it's not as fast as a proper `C++` compile. Either way, you can just limit `cake` to debugging if you need more speed.


### C++ Comparison Example

This is not an exhaustive comparison of Speedie to C++, but it seems a fair comparison, and covers a lot of areas.

It covers:

* Object creation
* Basic logic of splitting a string
* Object destruction
* Sorting
* Reading files
* Demonstrating how complex one language is to the other
    
The C++ version is at: [Documentation/CppComparison/SortLines.cpp](CppComparison/SortLines.cpp) (3,976 Bytes)

The Speedie version is at: [Examples/SortLines.spd](../Examples/SortLines.spd) (237 bytes)

The Speedie version is **11.5x smaller** (this was *after* I deleted some #ifdef'd code and comments from the C++ version).

The Speedie version also has much good error-checking on the file, and on app parameter handling. The C++ overhead is because C++ doesn't come with basic functions like "reading a file", which forces you to google or use stackoverflow to find answers to do basic things. Usually the simple answers are the wrong one. In this case, there is a 3-line C++ version of reading files, but it is very slow. Not good for a speed test!

Now, I created a file with 100,000 lines, using this program [Examples/randomwords.spd](../Examples/randomwords.spd) (Again, a small program that does a lot)

The first challenge I found in C++, was getting anything to work. For example, the splitter makes more sense when you return a c++ vector of `string*`, rather than string. This will sort faster. However, theres no obvious way to do it. Eventually I discovered that you can create a new `string*`, taking an existing `string`. (I'm assuming this is well optimised, because it is almost the same speed as splitting using `string_view` without any intermediate objects.)

There were other obstacles, but after I cleared them, I ran the test. Here are the times I got. **Speedie was faster in every area.** (I did not do anything special to optimise the Speedie version!! Speedie is just fast.)

* File Read (6.5x faster)
    * Speedie 0.14ms
    * C++ 0.90ms
* Line Split (2.27x faster)
    * Speedie 2.96ms
    * C++ 6.73ms // (quite variable. I took the average. but speedie was at least 1.9x faster)
* Line Sort (1.13x faster)
    * Speedie 14.91ms
    * C++ 16.91ms
* Cleanup (1.84x faster)
    * Speedie 0.75ms
    * C++ 1.38ms

**Overall, Speedie was 38% faster.**

Additionally, the Speedie version is a lot nicer to look at. It reads like poetry. The C++ version forces you to write a lot of boiler plate code. Many includes, a lot of name-spaces imports,  and very awkward names like `std::chrono::steady_clock::time_point` instead of Speedie's `date`.


