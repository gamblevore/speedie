
# Speedie - Fun is the main goal #
## Beautiful, Modern, Fast, Expressive, Non-Infantilising ##

* `Creator:` [@gamblevore](http://github.com/gamblevore/)
* `Contact:` [theo@jeebox.org](mailto:theo@jeebox.org)
* `Forum:` [t.me/speedie_dev](http://t.me/speedie_dev) (telegram)
* `Released`: New Years Eve 2022  (31/12/2022)
* `Platforms`: MacOSX Intel • Apple Silicon (ARM) • Linux (Ubuntu) • MS Windows (via [WSL](https://learn.microsoft.com/en-us/windows/wsl/install))
* `Sponsor ❤️`: If you love my vision, [Please Sponsor Speedie](https://github.com/sponsors/gamblevore). Donate however much you feel happy giving. Or possibly... just hire me? ❤️


# General Features #
* Modern language, slightly more expressive than Python.
* Faster than idiomatic C++
* Fast compilation.
* Object-oriented programming model
* Cross-platform. Create shell tools and GUI apps
* Message-passing-interface lets your multiple-processes talk.
* Has an awesome IDE, “Perry”.
* Stick with one language, when your needs change:
    * Fast: When you are doing heavy-duty data-processing
    * Expressive: When making tools with few lines of code
    * Type-safe and modern: Allows writing large complex programs
    * The GUI and everything else is cross-platform.
* Works natively with Jeebox... Learn how to use Jeebox!
* Not controlled by big-tech.

Speedie has been written as a passion project with a large amount of hacker-mentality, and it's source code reflects that ;D Dont expect "corporate behaviour". But do expect love for the project and the community.

If you'd like to support the ongoing development of Speedie, consider [sponsoring through GitHub](https://github.com/sponsors/gamblevore).

Speedie right now, compiles to C++. I am writing a VM for Speedie, so it won't NEED C++, but being able to is a great property to have, so that property will remain.

# Read More #
* [Language Guide](Documentation/LanguageGuide.md)
* [Speedie-isms](Documentation/isms.md)
* [XML Comparison](Documentation/xml.md)
* [Message (Jeebox)](Documentation/Message.md)
* [Strings](Documentation/Strings.md)
* [Error Handling](Documentation/Errors.md)
* [Perry (IDE)](Documentation/Perry.md)
* [Nil Checking](Documentation/Nil.md)



# Power Features #
* Has an awesome nil-checker and type-safety system! Write safe code while having an easy time of doing it!
* Generally runs faster than most other languages.
* Basic things like allocating/deallocating objects is faster, and takes less memory, than C++'s `new` or `malloc` functions.
* Doesn't infantilise you like Javascript or Java. Allows you to mess around with pointers if you need... (but try to avoid pointers anyhow).
* Integrates with C easily, so you can call C-library functions easily, if you need to, with no overhead.


# Speed #
Speedie is designed as a fast language. Ideally we want everything to be fast! There is a certain beauty in optimising code to run fast. When you remove all bloat, what remains can be a thing of beauty. 

Especially if those speed optimisations were done in terms of removing code, rather than adding complexity. So while I often mention speed, behind that is a deeper thing. Which is efficiency. And behind that is a very spiritual goal, of not wasting the life energy of the planet, that humans are greedily destroying at this moment.

Well I haven't been doing that. I've done the work of 1000 people (or more). And living a low-spending lifestyle... I'm saving the planet many times more than 1000. Its not that I'm trying to do this intentionally... it just happens as an unintentional side-effect of my values.

Another nice thing about making code faster by making it smaller, is that debugging the raw ASM is nicer. It becomes "prettier on the inside". Speedie has a very attractive syntax. So it could be said that Speedie is only fast, because I make things of beauty.

But about the language itself, why or how is speedie fast? "_How can a language be faster than C++_?" You might ask. Well... first, lets ask if we are talking about C++ or C--. C-- is when you take C++, treat it like C (no templates, no RTTI, exceptions, etc), and then avoid doing C-level functions like malloc/delete.

And so all you are left with is, is a small-subset of C, doing work on pointers and doing math-operations. In that case, Speedie is the same speed as C--.

However, if you use C++ like C++, that is, you use new/delete, use it's string functions and it's file-functions, you'll find that Speedie's equivalent functions are much faster.

C++ in recent times, has realised that "memory management is important" and now recommend everyone use shared-pointers. Shared-pointers are basically "just normal objects" in every other language, except that C++ did them in a slower and more RAM-consuing way than Speedie, and their syntax is ugly. That is what has become of C++.
	

# Remaining Challenges #

That said, there are challenges to overcome, that will probably mean a lot of people who are already interested, would not use Speedie:

* Adding a good debugger, VM and executable-format!

Unfortunately I am one person who has created a very large piece of work. Things will take much longer than we would have liked.


# Goals #
I have a lot of long-term goals... Overall, I want to make programming a whole lot more fun. Here goes for a partial-list of goals!

* "stepping backwards-in-time, through code" to see WHERE a problem originated from, would reduce a lot of the pain in debugging. I know how to do this nicely.
* I want to embed Speedie within a game-engine, that can be used for anything, kind of like Roblox. But designed for fast real-time-action much more than Roblox.
* I actually want to design a game (someday) where you can do programming without writing code, in fact the shape of the levels and monsters or items within the levels would implicitly write code for you. So basically the whole experience would become very metaphorical and dream-like. You would write code through your adventures.
* I'd like to create a space for the original goals of Jeebox. This includes perfect translation of human language, and making the computer sensibly work with human commands. This needs a community, theres no way I can do this myself. Using Jeebox for AI is a goal, but this will have to be community driven. It's quite possible that "It won't be fun to do first" and "there are more fun directions to follow first" such as more visual-programming route.
* Perhaps being adopted by a specific community? For example, perhaps some company or group WANTS to have a programming language designed for it's needs specifically?
* I'm still interested in MMI (Mind Machine Interfacing) using quantum-entropy, so perhaps Speedie could be modified to be good at it. But I want to steer clear of "financial predictions" and stick to the "lets use it for play" (like using randomness for games) kind of thing, so it might have to come **after** making a good gaming system? Using MMI for financial-predictions is kind of a cursed-genre.
* Perhaps visualisation of data-structures within a game-engine could be cool? As a way to explore your data and debug things.

On a personal level, outside of Speedie, I'd love to work on anything helping to restore nature or make technology less harmful. Such as helping retune wifi or EM-emissions of tech to **not** drain our health.



# Installation #

1. Run "`git clone https://github.com/gamblevore/speedie.git`" then move the folder to `/usr/local/speedie/` if it wasn't cloned there already.
2. `cd /usr/local/speedie`
3. Execute `sudo Terminal/makelinux.sh` ... OR `sudo Terminal/makeosx.sh`

My IDE Perry, will need libsdl2-dev to compile. LibSDL2 has [install instructions](https://wiki.libsdl.org/SDL2/Installation).



