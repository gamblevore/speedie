
# Speedie - Fun is the main goal #
## Technical Qualities: Object Oriented, Simple, Fast, Nice-Looking, Non-Infantilising ##

by Theodore H. Smith - Released on NYE, 31/12/2022.

Speedie is the compiler that I have created Jeebox in and is also built ontop of Jeebox. So thats a great thing. This proves that Jeebox can be used to write programming languages.

Speedie right now, compiles to C++. I am writing a VM for Speedie, so it won't NEED C++, but being able to is a great property to have, so that property will remain.


# Why use Speedie? #

Use Speedie if you feel called to: Because you find it fun to work on, or work in.

Describing why anyone would Speedie is a bit difficult. I can say "the programs it makes, run fast" but most people would rather write C++ if they want speed.

I could say "you usually only need a little code to do a lot" but most dynamic languages have this property. And besides, lacking a debugger right now really hampers development. (I'm working to fix this.)

I could say "well I have a GUI-system that is platform-independant"... except that the porting to other platforms isn't even done yet. Not much needed but SOMEONE needs to do it.

I could say "Speedie is a language that accomplishes a lot from a very small code-base" which might be useful to embedded programmers... but then Speedie isn't ported to Linux yet.

My language has a lot of good qualities but for each one, you can always find a reason why something else is better. Unfortunately that is because I am one person who has created a very large piece of work. Only extra developers contributing to Speedie can fix this.

Honestly... the only reason to use Speedie right now, is if you find it interesting or fun.


# General Features #
* Object-oriented programming model
* Works natively with Jeebox... Probably the best way to learn how to use Jeebox.
* Simple but powerful syntax.
* Can make command-line apps or GUI apps.
* IPC lets you communicate and spread work across multiple processes.
* Has a native IDE (Perry), written specifically for Speedie. 


# Power Features #
* Generally runs faster than most other languages. Even basic things like reading/writing to files runs faster than the "obvious" way to do it in C++. (Not because C++ is slow, but because the fast way to read files in C++, requires you to avoid FILE-pointers/ifstreams/fread and do everything using low-level Unix APIs.)
* Doesn't infantilise you like Javascript or java does. Allows you to mess around with pointers or structs if you need... although its usually buggier approach. 
* Integrates with C easily, so you can call C-library functions easily, if you need to, with no overhead.
	

# Goals #
I have a lot of long-term goals... Overall, I want to make programming a whole lot more fun. Here goes for a partial-list of goals!

* "stepping backwards-in-time, through code" to see WHERE a problem originated from, would reduce a lot of the pain in debugging. I know how to do this nicely.
* I want to embed Speedie within a game-engine, that can be used for anything, kind of like Roblox. But designed for fast real-time-action much more than Roblox.
* I actually want to design a game (someday) where you can do programming without writing code, in fact the shape of the levels and monsters or items within the levels would implicitly write code for you. So basically the whole experience would become very metaphorical and dream-like. You would write code through your adventures.
* I'd like to create a space for the original goals of Jeebox. This includes perfect translation of human language, and making the computer sensibly work with human commands. This needs a community, theres no way I can do this myself. Using Jeebox for AI is a goal, but this will have to be community driven. It's quite possible that "It won't be fun to do first" and "there are more fun directions to follow first" such as more visual-programming route.
* Perhaps being adopted by a specific community? For example, perhaps some company or group WANTS to have a programming language designed for it's needs specifically?
* I'm still interested in MMI (Mind Machine Interfacing) using quantum-entropy, so perhaps Speedie could be modified to be good at it. But I want to steer clear of any "real-life-resource gains" and stick to the "lets use it for play" (like using randomness for games) kind of thing, so it might have to come **after** making a good gaming system? Using MMI for resource-gains is kind of a cursed-genre.
* Perhaps visualisation of data-structures within a game-engine could be cool? As a way to explore your data and debug things.

On a personal level, outside of Speedie, I'd love to work on anything helping to restore nature or make technology less harmful. Such as helping retune wifi or EM-emissions of tech to NOT drain our health.



# Install Via Github (MacOSX only) #

1) Download the files via github, and install Speedie at ~/Speedie/
2) Run this command `ln -s  ~/Speedie/Terminal/Speedie /usr/local/bin/speedie`.
	This will allow speedie to be run from the command-line. Also run `ln -s  ~/Speedie/Terminal/Speedie /usr/local/bin/spd` to make it quicker.
3) If /usr/local/bin/ isnt in your command-line PATH, then you can find instructions on how to do that elsewhere. 


# Install Via Perry (MacOSX only) #

1) Download and run Perry.app
2) Perry will ask, if you want it to install everything. Just press "OK".
3) It should be installed.



# Porting #

It would be nice to have people help port Speedie to other platforms. Speedie is basically built ontop of Unix, C++ and SDL2. There is only one small .m file it uses that uses Apple headers. HOWEVER, things are rarely so simple. Even a plain C++ command-line app usually needs reworking to compile across multiple platforms due to header differences. 

If you've enjoyed porting software before, you should find porting Speedie, easy. Let me know if you want to port Speedie to Windows or Linux! In this case we'd be very eager for you to upload your work!
