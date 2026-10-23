
# Speedie - Fun is the main goal #
## Beautiful, Modern, Fast, Expressive, Empowering ##


* `Creator:` [@gamblevore](http://github.com/gamblevore/)
* `Contact:` [theo@jeebox.org](mailto:theo@jeebox.org)
* `Forum:` [t.me/speedie_dev](http://t.me/speedie_dev) (telegram)
* `Released`: New Years Eve 2022  (31/12/2022)
* `Platforms`: MacOSX Intel • Apple Silicon (ARM) • Linux (Ubuntu) • MS Windows (via [WSL](https://learn.microsoft.com/en-us/windows/wsl/install))
* `Sponsor ❤️`: If you believe in my vision, [you can sponsor me to support future growth](https://github.com/sponsors/gamblevore). It would help.


# General Features #
* Modern object-oriented language, slightly more expressive than Python.
* Runs faster than idiomatic C++
* Cross-platform. Create shell tools and GUI apps
* Message-passing-interface lets your multiple-processes talk
* Has an awesome IDE, Perry
* Stick with one language, when your needs change:
    * Fast: When you are doing heavy-duty data-processing
    * Safe: Type + nil safe! Create large complex apps!
    * Expressive: When making tools with few lines of code
    * Cross Platform: Deploy GUI or shell apps on major platforms
* Works natively with Jeebox... Learn how to use Jeebox!
* Compiles via C++ for full-speed, or to it's VM 🍰 "`Cake`" 🍰. _(`Cake` is unfinished but is the main current focus of work.)_
* Not controlled by big-tech.

Speedie has been written as a passion project with a large amount of hacker mentality. And we are proud of this. Just love it or leave it.

**Note:** _Currently, Speedie has issues compiling outside of OSX._ It is compiling on Debian Linux, however there is some dependancy work to solve, especially around SDL2. SDL2 is not needed for the compiler but Perry and other graphical apps will not compile, unless SDL2 is already setup.

If you'd like to support the ongoing development of Speedie, consider [sponsoring through GitHub](https://github.com/sponsors/gamblevore).


# Read More #
* [Language Guide](Documentation/LanguageGuide.md) _(Learn how to use Speedie)_
* [Speedie-isms](Documentation/isms.md) _(Fun conventions)_
* [XML vs Jeebox](Documentation/xml.md) _(Jeebox wins)_
* [Message (Jeebox)](Documentation/Jeebox.md) _(How to use Jeebox)_
* [Strings](Documentation/Strings.md) _(Good string support is important)_
* [Error Handling](Documentation/Errors.md) _(The best error-handling in any language!)_
* [Perry](Documentation/Perry.md) (_An IDE made specially for Speedie)_
* [Safety in Speedie](Documentation/Safety.md) _(What Speedie does for you)_
* [Speedie Is Fast](Documentation/Speed.md) _(Why use a lang if its not fast?)_
* [Cake VM 🍰](Documentation/Cake.md) _(Not finished but will be tasty!)_



# Power Features #
* Has an awesome nil-checker and type-safety system! Write safe code while having an easy time of doing it!
* Integrates with C easily, so you can call C-library functions easily, if you need to, with no overhead.
* Speedie is designed as a [fast language](Documentation/Speed.md).
* Doesn't infantilise you like Javascript or Java. Allows you to mess around with pointers if you need... (but try to avoid pointers anyhow).
* Other languages ([Rust](Documentation/Comparisons.md)) feel like pedantic "form-filling" ask the government to build on your own land, (and hoping the bureaucrats don't block you), rather than simply building. Speedie is more like a friend that helps you build your barn while stopping you when your chainsaw is too close to your leg.


# Road Map To Release #

There is still work to be done before Speedie is release ready. Here is the current road-map.

Beta Release:

* General ASM fixes, especially around SIMD.
* Minor GUI improvements to Perry
* ASM needs to be self-compiling for Speedie. (Speedie compiling itself via Cake!)

Proper Release:

* Needs to run smoothly on (Mac + Window + Linux) * (x86 + ARM). So thats 6 combinations.
* GPU acceleration via OpenCL

Unfortunately I am one person who has created a very large piece of work. Things will take much longer than we would have liked. But overall... Speedie is in a very good state.


# Contributing Patches #
*  [Code of Conduct For Patches and Requests](Documentation/Cond.md)


# Downsides #
*Is this some magical land where all code becomes better?* **Well... no.** There are downsides! Speedie's downsides are heavy enough that, for most people, other languages are better.

Like everything in life, there are downsides. By avoiding the downsides of C++ (complexity) and Python (slowness), we gained new downsides. This is just life I guess.

* The community is (currently) tiny
* Lack of 3rd party libs or 3rd party examples

So no... its not some *"magical land where everything becomes better"*.

Other possible reasons not to use Speedie include: "We don't want to learn a new language" or "our existing code-base is in lang-XYZ".
    
For some people, the small community isn't a problem. Some people prefer to write all their own code and have been doing that for their most successful products in the past anyhow. Others might want to create libs, and Speedie might be a good environment to do it in. (Speedie can compile libs with C-APIs! For example [jeebox_api.h](jeebox.scproj/Examples/jeebox_api.h))

And some may prefer a small community. Perhaps a student or someone who enjoys learning new things. You will just want to explore. And speedie does have a nice bunch of [example](Examples/) - [projects](GameExamples/) already, to learn from.

I prefer coding in Speedie to any other language, including C++.



# Goals #
I have a lot of long-term goals... Overall, I want to make programming a whole lot more fun. Here goes for a partial-list of goals!

* "Stepping backwards-in-time, through code" to see WHERE a problem originated from, would reduce a lot of the pain in debugging. I know how to do this nicely.
* I want to embed Speedie within a game-engine, that can be used for anything, kind of like Roblox. But designed for fast real-time-action much more than Roblox.
* I actually want to design a game (someday) where you can do programming without writing code, in fact the shape of the levels and monsters or items within the levels would implicitly write code for you. So basically the whole experience would become very metaphorical and dream-like. You would write code through your adventures.
* I'd like to create a space for the original goals of Jeebox. This includes perfect translation of human language, and making the computer sensibly work with human commands. This needs a community, theres no way I can do this myself. Using Jeebox for AI is a goal, but this will have to be community driven. It's quite possible that "It won't be fun to do first" and "there are more fun directions to follow first" such as more visual-programming route.
* I'm still interested in MMI (Mind Machine Interfacing) using quantum-entropy, so perhaps Speedie could be modified to be good at it. But I want to steer clear of "financial predictions" and stick to the "lets use it for play" (like using randomness for games) kind of thing, so it might have to come **after** making a good gaming system? Using MMI for financial-predictions is kind of a cursed-genre.
* Perhaps visualisation of data-structures within a game-engine could be cool? As a way to explore your data and debug things.

On a personal level, outside of Speedie, I'd love to work on anything helping to restore nature or make technology less harmful. Such as helping retune wifi or EM-emissions of tech to **not** drain our health.


# Installation #

    git clone https://github.com/gamblevore/speedie.git
    speedie/make.sh

Thats all!

This little build script, knows how to build Speedie, collect dependancies (SDL2), and works on both MacOS and Linux. Its a very smart little build-script, mostly written in Speedie.

You don't need to clone, just run `speedie/make.sh` if you have the `speedie` folder.

Some systems may need `sudo speedie/make.sh` to install symlinks into `/usr/local/bin`.

_Tip: The recommended place for your Speedie folder at `/usr/local/speedie/` . It doesn't have to be there, but installed command-line symlinks will break if the destination can't be found, if the speedie folder was moved after install. So you might as well settle on a fixed location. Or you will have to fix symlinks yourself._



