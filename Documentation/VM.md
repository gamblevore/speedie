## Speedie's VM

I am currently building a virtual-machine, for speedie. I haven't got a name for it yet... so I'll just call it "The VM".

Speedie's VM is very well designed, to be a perfect match for the language speedie. In fact, its probably a good match for C++ code too, or anything similar to that.

I'm expecting that code compiled for the virtual-machine, will be about 2x smaller than similar ARM-compiles.

Speedie doesn't require a VM to run it's code, in fact currently it is outputting C++ and compiling that. This is such a useful property to have, that I will keep it. However, it makes debugging very hard, as you would have to debug the C++.

The VM will enable these possibilites:

* Make debugging possible, easy and fun.
* Single-distributables can run anywhere. Any platform with speedie installed.
* Some "[temporal](#user-content-temporal)" magic and mystery. (optional)
* Write portable ASM yourself!
* Compile Speedie without needing a C compiler.


### Small and fast

Speedie ASM is around 2-3x smaller than ARM. In addition, compiles will link against SpeedieLib, cutting down compile size dramatically. My entire IDE Perry compiles down to 80KB! And its a good IDE! It is featureful.

*If I say (2 v 13), that means Speedie takes 2 instructions to do something, and ARM would take 13 to do the same.*

* RefCounting instructions (1-2 vs 16-32).
* Function-calls are expressed cleanly. Tighter, smaller, faster. Far superior design. (2 vs 2-20, typically 2 vs 10)
* Many low-level math instructions, the compiler will automatically insert them. These include:
    * Div2 (fast divide by power of 2, on signed ints)  (1 vs 2)
    * Integer Min / Max  (1 vs 3)
    * Multiply or add by a immediate constant, on both ints and floats (1 vs 2)
    * Increment/decrement memory (1 vs 3)
* 64-bit direct constants (and 48-bit and 16-bit versions) without needing to load from a separate location.
* Branching (1 vs 2)
* Loop specific instructions do in (1 vs 3-4).

The current instruction count is around 190. I'll probably add a few more before release, but not many. This includes all the SIMD instructions for faster graphics, replicating the functions of OpenGL/GLSL.

Also simple to decode. Instructions are 4-bytes each, except for instructions from 0 to 31. In this range, they take either 8 or 12 bytes, depending on if the instruction index is odd or even. (This should help make it faster if ever turned into physical hardware.)


### Inbuilt ASM-Viewer

People who have used [godbolt.org](http://godbolt.org) know how useful this tool can be. It is used for all sorts of things, but mostly to check if your code compiles to code that is as good as you know it can be. Or to avoid disasterous compiler-bugs that lower efficiency unexpectedly. Such as refusing to use SIMD when it should.

Well... Perry has an inbuilt ASM-Viewer! Just press Command-9 (Ctrl-9 on Linux) to view the ASM for any function you are editing. Speedie already optimises it's code "tastefully", to make a good balance of debuggability and speed.

![InBuilt ASM View](godbolt.png)

And considering that Speedie only has one compile-target (release builds ARE debug-builds), this means you can easily check the final output of your code.

Perry's inbuilt ASM-viewer... has an extra advantage, it is instant! (Unlike godbolt.org)


### Other nice things to know abou:

• Within 1.5 years of community acceptance, an ARM-JIT will be created. This will run speedie apps on ARM-CPUs at full native speed.

• The ASM works on any platform. It will be a great way to learn ASM! Even better, is that once the JIT is made, your hand-written Speedie-ASM runs at full-native speed.

• The VM has SIMD instructions... useful for 3D graphics, audio, etc.

• All builds are fully optimised, even debug-builds. The only difference is that release-builds will remove debug-only code from your code-base. This is code that YOU marked as debug. For example:


    function Example (|string| name)
        target debug
            expect (name != "") ("Empty name passed")
            // programmer expects this never to happen in release due to other checks earlier
        
        printline name

This makes debugging your apps much simpler, as you are less likely to get a difference between your "release" and "Debug" version. Usually, they can just be the same program!


### Future Possibility: Temporal

What if we made a "temporal VM". This is where we basically use our code for art... mystery and magic, or anything kind of dreamy or intuitive. You can see it as "divination", like reading tea-leaves or reading tarot-cards.

Basically, we record the amount of time it takes for your code to run, per-instruction. Running your code will now generate a large amount of fresh data. *(This entire thing will be an optional feature).*

Because the CPU is a physical thing... the amount of **time** it takes to do anything is unpredictable. No matter what input is given... the output can't be mathematically predicted. That is because it comes from the soul... or at least why not? Why not use your willpower to change the effects of the dice-roll? Thats what most dungeons and dragons players believe in anyhow (hahaha).

This temporal output can be used to create interesting textures or patterns that come out of the heart of your CPU's inner world... Or be used for "electronic divination", perhaps even "mind-machine-interfaces", art. Or randomness input for games and more.

The best example of this is like when you are playing a computer game, and the RNG just happens to create some very annoying or funny event for you.

Did the gods arrange this event? Did this happen for some deeper reason? Well... who knows, but we hope that the temporal engine will increase the level of such occurances.

The question about this being "unscientific" isn't really a good point, because it is statistically proven such mind-machine effects do exist. The question of **what** it means if anything... or how useful it is... is one I have absolutely no idea about :) But its useful to explore and play with. That is all.

The question shouldn't be about how *scientific* this is... but is it *fun* or *meaningful*. Tarot-cards, iChing and divination in general are also "unscientific". But they are popular and mean a lot to many people and help them through life. That is the kind of thing we want to aim for with the temporal engine.

#### Lets Go Further

In fact... we want to further with this! Lets go deeper. Each program in unix has `stdin` and `stdout`. So that is a balanced thing, we have input and output, positive and negative.

But we also have `stderr`, which is a bad thing. We want to avoid creating errors. What if all apps had a good thing, to balance that out? Like `stdfun` or `stdvibe`? Some positive or pleasant output from your programs. And it was there, by standard, in **all** programs (if you didn't disable it for speed).

Well... that `stdvibe` output... could just be the temporal-engine. Something that "outputs pleasant or good info" to be used in some artistic or game-purposes.

Perhaps to let the computer "get a feel" if it likes the code it is running, or not. In fact... in the future we could go even further... by making a temporal AI-VM. This is where you get an AI to analyse the temporal-output... to do the interpretation for you. You could even make the AI itself generate temporal-info as a result of it's own operation, then interpret the result. So its a way to make a computer "feel itself"...

Interesting possibilities. Definitely these are side projects... but something fun to work on when there a gap in other work :)



