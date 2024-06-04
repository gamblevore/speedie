## Speedie's VM

I am currently building a virtual-machine, for speedie. I haven't got a name for it yet... so I'll just call it "The VM".

Speedie's VM is very well designed, to be a perfect match for the language speedie. In fact, its probably a good match for C++ code too, or anything similar to that.

I'm expecting that code compiled for the virtual-machine, will be about 2x smaller than similar ARM-compiles.

Speedie doesn't require a VM to run it's code, in fact currently it is outputting C++ and compiling that. This is such a useful property to have, that I will keep it. However, it makes debugging very hard, as you would have to debug the C++.

So that is the main reason that a VM is necessary, to make debugging possible, easy and fun. But it can do a lot more.

* Enable single-distributables to run anywhere. Any platform with speedie installed.
* Protect against changes in the language speedie. For example if a change in speedie made some of your code not compile anymore.
* Make debugging possible, easy and fun.
* Some "[temporal](#user-content-temporal)" magic and mystery. (optional)

Some nice things to know:

* RefCounting could take 1 instruction per 2-objects... but in ARM the same refcounts could take 32-instructions. So it should be a lot faster and smaller.
* Function-calls are way better expressed. Tighter & smaller.
* Many useful instructions for doing low-level maths. The compiler will automatically insert them, obviously, you don't need to know them. The point is, maths should express itself tightly.
* Tight loops too. We have two instructions specifically for expressing loops tightly.
* Has SIMD instructions... useful for 3D graphics, audio, etc.
* All builds are fully optimised, even debug-builds. The only difference is that release-builds will remove debug-only code from your code-base.


### Future Possibilities

Hopefully within 1.5 years of release, an ARM-JIT will be created for Speedie. This will mean that even your speedie-VM based code, should run at full speed using native instructions. (At least on ARM CPUs.)


### Temporal

What if we made a "temporal VM". This is where we basically use our code for art... mystery and magic, or anything kind of dreamy or intuitive. You can see it as "divination", like reading tea-leaves or reading tarot-cards.

Basically, we record the amount of time it takes for your code to run, per-instruction. Running your code will now generate a large amount of fresh data. *(This entire thing will be an optional feature).*

Because the CPU is a physical thing... the amount of **time** it takes to do anything "random" and unpredictable. No matter what input is given... the output can't be mathematically predicted.

This can be used to create interesting textures or patterns that come out of the heart of your CPU's inner world... Or be used for "electronic divination", perhaps even "mind-machine-interfaces", art. Or randomness input for games and more.

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



