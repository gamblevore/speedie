## Potential Loss Of Speedie Performance (relative to C)

So... are there any places where speedie imposes overhead? There are two: Refcounting and type-checking. Both are done on objects, not data-types.

Refcounting objects imposes some (slight) overhead. In my experience, it really isn't too much, especially on ARM machines it tends to run fast. However it is there. For almost all code you won't notice it. Like 99.9% of code.

Unless what you are doing is making a high-performance library, it is almost certainly a bad idea to disable refcounting, as this can easily cause crashes and leaks.

However, for certain situations it is safe to disable, for example "searching functions" are quite likely to be safe. Let's say you had to search within a tree for some specific value, to see if it exists in this tree. Perhaps you wanted to find an item with the same name.

In that case, no objects are being created or destroyed (I know this because I made the language), so its safe to disable refcounting in that function. Doing something as simple as calling another function that DOES do refcounting, could in theory cause crashes, however. So its not 100% safe unless you know what you are doing.

If all goes to plan, you'll get an extra speed boost back to the same level you'd get in writing C code.

In fact you will get issues with this if you play with it, because you won't know when to safely disable and when not to. So unless you don't mind being "bitten", its not worth trying to find out where it is safe to disable...

If you do simple thing, like print a string like this `printline "Searched $Count nodes successfully"` within your search function (that you disabled refcounts in)... again you will leak memory. Because to create this string, it has to create and free some string objects. So even a search function can misbehave if you disable refcounting and don't know what you are doing.

...

In the future, I want to write an automatic refcount optimiser, that will disable refcounting in "Safe situations" anyhow. It will know when it is safe to do so. Once that is done, I'll disable refcount-disabling. As it won't be needed anymore.

...

It is also possible that typecasting via the `isa` operator, is slower than doing what I call "blind type-casting". **Again** this is really a waste of developer time to worry about, as speedie is so fast anyhow. Assuming you write your code well... you won't need to type-cast within a high-performance section, and type-casting is generally fast anyhow!

It would be a very special and rare situation in which this could cause noticeable speed losses... One I haven't seen myself yet.

...

Overall, I would look at how much speed you are *gaining* by using speedie first. If you code is a lot faster than writing it in another language (java / C# / JS / python / etc)... then just don't bother ruining your experience by trying to get another 2 %. Especially if you just gained 30% to 1000% extra speed. (Depending on the lang you are comparing to).

Its probably a nice fun thing to trust the language :) To see "how much speed can I get while trusting the language".

Perry (my IDE) does this. Because its a simple app that relies on the libs to do all the heavy lifting. So if even an IDE doesn't need to fool with disabling refcounts, you can see most other apps won't either.

