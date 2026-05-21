
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

**Note:** _Currently, Speedie has issues compiling outside of OSX._ I **can** fix these. Speedie has worked recently on Windows and Linux. Before release we will fix these bugs.

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
* TextView needs line resyncronisation. (Allows editing live code while keeping breakpoints for more fluid editing. Your new changes **don't** get entered until re-run, but at least your breakpoints remain functional.)

Proper Release:

* GPU acceleration via OpenCL

Unfortunately I am one person who has created a very large piece of work. Things will take much longer than we would have liked. But overall... Speedie is in a very good state. The C++ compile-mode is fully working and produces fast apps. It really is going to be wonderful.

Its more about unlocking that wonderfulness (by making it easy to debug and productive) than actually making it wonderful. The greatness is already within.


# Downsides #
*Is Speedie some magical land where all coding-projects become better?* **Well... no.** There are downsides! Speedie's downsides are heavy enough that, for many people, other languages are a better choice.

Like everything in life, there are downsides. By avoiding the downsides of C++ (complexity) and Python (slowness), we gained new downsides. This is just life I guess.

* The community is (currently) tiny
* Lack of 3rd party libs or 3rd party examples

So no... its not some *"magical land where everything becomes better"*.

Other possible reasons not to use speedie, include: "We don't want to learn a new language" or "our existing code-base is in lang-XYZ".
    
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

1. Run "`git clone https://github.com/gamblevore/speedie.git`" then move the folder to `/usr/local/speedie/` if it wasn't cloned there already.
2. `cd /usr/local/speedie`
3. Execute `sudo Terminal/makelinux.sh` ... OR `sudo Terminal/makeosx.sh`

My IDE Perry, will need libsdl2-dev to compile. LibSDL2 has [install instructions](https://wiki.libsdl.org/SDL2/Installation).



