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

Once Speedie has built a successful community... I'll be able to start work on a JIT. The `cake-JIT` will run `cake` apps at close to native `C++` speed. The timing on the JIT isn't up to me, it will be up to the choices of the Speedie community. The more practical support we get, the sooner we will have a JIT.

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

The Speedie source is **11.5x smaller** (this was *after* I deleted some #ifdef'd code and comments from the C++ version). The code compiles to much larger product, due to including all the libs. However the product is still much smaller than a hello-world `Rust` compile.

The Speedie version has good error-checking on the file, and on app parameter handling. The C++ source-code overhead is because C++ doesn't come with basic functions like "reading a file", which forces you to google or use stackoverflow to find answers to do basic things. Usually the simple answers are the wrong one. For file-reading, I found a 3-line C++ version, but it is very slow. Not good for a speed test! So I used the fastest (but still simple) C++ example I could find on stackoverflow.

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

#### Summary (Speedie Wins! 🏆)
**Overall, Speedie was 38% faster.**

Additionally, the Speedie version is a lot nicer to look at. It reads like poetry. The C++ version forces you to write a lot of boiler plate code. Many includes, a lot of name-spaces imports,  and very awkward names like `std::chrono::steady_clock::time_point` instead of Speedie's `date`.

Speedie is not just faster. But safer! And handles errors better. And smaller code. And easier to write.


#### Caveat About The Speed

While I feel happy with Speedie's speed, this should be seen in context. For many people, it won't be enough of a benefit. (Although its certainly nice.)

Speed by itself really isn't that important, C++ is usually fast enough for almost anything. And if some C++ code is slower than Speedie code, anyone who is actually making decent money from their code, can usually speed it up by re-writing C++ library functions themselves. For example doing arena-allocation instead of C++ `new`/`delete`.

So for any professional, working in a successful company, another language having faster library functions... won't make a difference, as they will be already collecting their own library of C++ code to replace the standard C++ libs. Given enough effort, their code could become faster than Speedie, especially as Speedie is single-threaded.

This does fragment the C++ code base, as now there will be about 10,000 or so "in-shop-libraries" (or common OpenSource versions) to replace C++ lib functions.

For a newcomer begining programming, Speedie's inbuilt extra speed is a nice benefit. However, many newcomers won't worry about speed.

A beginner to programming, would probably benefit more from Speedie's ease of compiling, readability, and reliability.

Theres no reason to feel that "Speedie has won a contest against C++" for that reason... when an expert could write faster C++ functions than the inbuilt C++ lib funcs. Not everyone wants to spend that time, however... In fact writing a high-quality file-library takes **years** (most likely over 12) because you tend to discover problems or better approaches very slowly. And the programmer might not be allowed to include their favourite libs/funcs in each project they work on, due to different company owners having different requirements.

If 8 different people wrote 8 different "mini-libs" for doing files faster, and all worked together on one project... whose C++ lib-replacement do you use?? All of them? One? None? You see! Having a faster base-lib already helps for that reason.

A fast-file C++ library like [fast_io](https://github.com/cppfastio/fast_io) is definitely impressive and useful. But it might be that only 0.005% of all C++ programmers are using it. And like above, it is one of many options, leading to fragmentation, creating many incompatible code-bases. Meanwhile 100% of speedie developers get the faster file-funcs.


#### Error Handling

Speedie handles errors better too. Try passing an invalid file-path to the C++ version. I got this:

    libc++abi: terminating due to uncaught exception of type int
    zsh: abort      /usr/local/speedie/Documentation/CppComparison/SortLines

Yeah not very fun. It crashes and doesn't even tell me what the error is! Try this in speedie!

    error occurred (-1)
    /usr/local/speedie/Examples/CppComparison/words.txt: error: File does not exist, trying to access /usr/local/speedie/Examples/CppComparison/words.txt

Perfect! No crashes. And nicely reports the error into stderr. Speedie also handles other errors, like passing a folder path instead of a file-path, and many more. The C++ version just reads the folder! Which on unix... contains a small (<100) bytes of data that has no real meaning.


#### Sort Safety

The safety issue here in C++, is that if you pass a sort-comparison function that is invalid (say just returns a random number), C++'s sort actually just crashes. C++'s sort will crash if your code decides that: A > B,  B > C,  and C > A

This is just not fun. Imagine some kid writing a sorter to sort zombies in a list of "something" (aggression?), writes the sort function wrong, and his game crashes. Even worse if it crashes "sometimes" like not during testing, but on release.

Speedie's sorter will just result in badly sorted data, given a bad sorting function. No crash. Valid data. Just sorted equally badly to your comparison func.

#### Rust sort_by

By the way, you think your "Safe" language Rust will save you from bad sort functions? No. They still crash! I literally found this comment on Rust's github, posted this month (2025 Dec):

> "Sorry to reopen this thread... but is there a way to avoid panics on sort_by? Or can somebody recommend an alternative crate to use for sorting that does not panic? I maintain the Rhai scripting engine and the comparison function is passed in by users, which may not implement a total order. It is OK for the function to return gibberish... but not OK for the script to panic the host."

Speedie doesn't suffer this, and its still faster.



#### Overview

Overall Speedie as a language is in a good place with it's overall features. Fast yet simple. Its a good place to be.