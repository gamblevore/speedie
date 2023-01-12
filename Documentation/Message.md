## Messages
(aka **Jeebox**)

The `Message` class is the result of parsing a string, like "`|| msg = "(a,b,c)".parse`"

Message is used to represent the nodes within a parsed string. Jeebox is a highly flexible data-format, that is extensible (like XML).

Technically, Jeebox is classed as an `AST` (abstract syntax tree), that is why it can store source-code. It just happens to also be useful for storing data-files.

    || source_string = `
    file_list
        item "/path/to/file1" (Picture)
        item "/path/to/file2" (Sound)
        item "/path/to/file3" (Text)
    `
    || recent_list = source_string.parse
    for item in recent_list["file_list"]
        || name = item[@str,0].name.name
        || type = item[@bra,1][@thg].name
        "$name is a $type"                    // "file1 is a Picture,  file2 is a Sound,  file3 is a Text"
    
**Unlike** XML which has many different kinds of nodes, each `Message` returned by `string.parse` is interchangeable, and has only two things defining it, the type and the name.

The name is accessed via `.name`, and is just a string. The type is accessed `.func`, and is a datatype called `Syntax`. On the CPU, `Syntax` is just an `int`. Datatypes have their own functions that you can call, so you must think of `Syntax` as it's own type that just happens to have efficient CPU representation.

OK, lets try parsing this:

    return a > c

Well, that leads to this tree:

    tmp "return"
        rel 
            thg "a"
            opp ">"
            thg "c"

So the message "`return`" has a type of `@tmp`. "`>`" has a type of `@opp`. (We use `@` in Speedie, to represent `Message` types. So `@thg` would be a "thing" type, and `@arg` would be an "argument" type.)

Jeebox (and it's `Message` class), is useful for so many use-cases, that it surprises people (even me). Sometimes it even confuses people, but it shouldn't, because we use ascii or Unicode for just anything. Why not a file-format too?

Here are some things I've (practically) used Jeebox for, so far:

* Source code (Speedie uses it)
* Configuration files (Speedie uses it)
* Preference files (all my apps use it)
* IPC (the `Process` class)
* Internet communications
* Data-banks

## Upcoming Section...

I am going to write a walk-through, on how to parse an iTunes song library and convert it to Jeebox! This way we have our own song-library we can easy edit or use from within Speedie. In fact my program "`MultiPlay`" uses this technique.

