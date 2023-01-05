## Messages
(aka **Jeebox**)

The `Message` class is the result of parsing a string, like "`|| msg = "(a,b,c)".parse`"

Message is used to represent the nodes within a parsed Jeebox string. Jeebox is a highly flexible data-format, that is extensible (like XML).

Technically, Jeebox is classed as an `AST` (abstract syntax tree), that is why it can store source-code. It just happens to also be useful for storing data-files.

    || source_string = `
    files
        file "/path/to/file1" (Picture)
        file "/path/to/file2" (Sound)
        file "/path/to/file3" (Text)
    `
    || recent_list = source_string.parse
    for f in recent_list..files
		|| name = f[@str,0].name.name
		|| type = f[@bra,1][@thg].name
        "$name is a $type"					// "file1 is a Picture,  file2 is a Sound,  file3 is a Text"
    
**Unlike** XML which has many different kinds of nodes, each `Message` returned by `string.parse` is interchangeable, and has only two things defining it, the type and the name.

`Message` has a type accessed via `.func`, and a name accessed via `.name`.

For example, parsing this:

    return a > c

Well, that leads to this tree:

    tmp "return"
        rel 
            thg "a"
            opp ">"
            thg "c"

So the message "`return`" has a type of `@tmp`. "`>`" has a type of `@opp`. (We use `@` in Speedie, to represent `Message` types. So `@thg` would be a "thing" type, and `@arg` would be an "argument" type.)

`Message` is very generally useful. Think of Unicode, where you have one standard that represents many languages. Jeebox is the same. If you appreciate Unicode over the mess we had before with hundreds of different encodings, each only good at one language and usually a few encodings per language... you might appreciate Jeebox too.

Here are some things I've (practically) used Jeebox for, so far:

* Source code (Speedie uses it)
* Configuration files (Speedie uses it)
* Preference files (all my apps use it)
* IPC (the `Process` class)
* Internet communications
* Data-banks

## Upcoming Section...

I am going to write a walk-through, on how to parse an iTunes song library and convert it to Jeebox! This way we have our own song-library we can easy edit or use from within Speedie. In fact my program "`MultiPlay`" uses this technique.

