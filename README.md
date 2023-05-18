
# Speedie - Fun is the main goal #
## Technical Qualities: Object Oriented, Simple, Fast, Nice-Looking, Non-Infantilising ##

* `Creator:` [@gamblevore](http://github.com/gamblevore/)
* `Contact:` [theo@jeebox.org](mailto:theo@jeebox.org)
* `Forum:` [t.me/speedie_dev](http://t.me/speedie_dev) (telegram)
* `Released`: New Years Eve 2022  (31/12/2022)

# General Features #
* Object-oriented programming model
* Works natively with Jeebox... Probably the best way to learn how to use Jeebox.
* Simple but powerful syntax.
* A lot of syntactic sugar, while still being tasteful.
* Cross-platform. Create shell tools and GUI apps
* Easy communication across multiple processes (IPC).
* Has a native IDE “Perry”. Created to combine power + simplicity.
* Use one language, thats great at multiple areas:
    * Fast at heavy-duty data-processing
    * Making tools with few lines of code
    * Writing large well-structured programs
    * Cross-platform code, even with GUI
* Not controlled by big-tech.

Speedie has been written as a passion project with a large amount of hacker-mentality, and it's source code reflects that ;D I did delete most of the rude comments before release, but still... dont expect "corporate behaviour".

If you'd like to financially support the ongoing development of Speedie, consider [sponsoring through GitHub](https://github.com/sponsors/gamblevore).

Speedie right now, compiles to C++. I am writing a VM for Speedie, so it won't NEED C++, but being able to is a great property to have, so that property will remain.

# Read More #
* [Language Guide](Documentation/LanguageGuide.md)
* [Speedie-isms](Documentation/isms.md)
* [XML Comparison](Documentation/xml.md)
* [Message (Jeebox)](Documentation/Message.md)
* [Strings](Documentation/Strings.md)
* [Error Handling](Documentation/Errors.md)



# Why Use Speedie? #

Use Speedie if you feel called to: Because you find it fun to work on, or work in.

Why would you use Speedie? I can't answer that, because people make their decisions not based on good qualities but on power-structures in this world, or on some kind of destiny. But for now, lets list some good qualities.

* The programs speedie makes, run fast.
* I could say "you usually only need a little code to do a lot"
* My GUI-system is platform-independant, so your code should mostly work the identical on other platforms.
*  Accomplishes a lot from a very small code-base, useful for embedded programmers.

That said, there are challenges to overcome, that will probably mean a lot of people who are already interested, would not use Speedie:

* Getting the IDE working on Linux+Windows
* Making speedie run on Windows (Linux is done!)
* Adding a good debugger, VM and executable-format!

Unfortunately I am one person who has created a very large piece of work. Extra developers are sorely wanted!

If you like the speed of C code, but hate doing memory-management, and want a modern sleek cross-platform language, speedie is probably the thing for you.

Becoming a contributor could be a great way to add programming concepts to a new language. Assuming they fit with the overall existing feature set and have efficient implementations.



# Power Features #
* Generally runs faster than most other languages. Even basic things like reading/writing to files runs faster than the "obvious" way to do it in C++. (Not because C++ is slow, but because the fast way to read files in C++, requires you to avoid FILE*/ifstreams/fread and do everything using low-level Unix APIs.)
* Doesn't infantilise you like Javascript or java does. Allows you to mess around with pointers or structs if you need... although its usually a buggier approach. 
* Integrates with C easily, so you can call C-library functions easily, if you need to, with no overhead.
	

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

1. Download/Clone repo, and place at `/usr/local/speedie`
2. `cd /usr/local/speedie`
3. Execute `sudo Terminal/makelinux.sh` ... OR `sudo Terminal/makeosx.sh`



# Porting #

Currently Speedie fully works on MacOSX Intel and Apple Silicon (ARM). Linux Support is Partial. The compiler works, but the GUI does not work.

It would be nice to have people help port Speedie to other platforms. I need one small .m (OSX) file that uses SDL2 ported to Linux or Windows, about 100 lines of code.

Let me know if you want to port Speedie to Windows or Linux! In this case we'd be very eager for you to upload your work!

# Sponsors #

Currently sponsored by:

* [@breck7](http://pd.pub) He is working on many projects including pd.pub, Scroll, Ohayo, and Music Of A People.
* [@randonautica](https://randonautica.com/) Explore the world in a new way, and increase mystery.


