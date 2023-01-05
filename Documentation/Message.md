## Messages
(aka **Jeebox**)

The `Message` class is the result of parsing a string, like "`|| msg = "(a,b,c)".parse`"

Message is used to represent a parsed Jeebox string. Jeebox is a highly flexible data-format. Jeebox can store both data (like XML) or source-code (like Speedie), and more.

Technically, Jeebox is classed as an `AST` (abstract syntax tree). It just happens to also be useful for storing data-files.


    || recent_list_data = `
    files
        file "/path/to/file1" (Picture)
        file "/path/to/file2" (Sound)
        file "/path/to/file3" (Text)
    `
    || recent_list = recent_list.parse
    for f in recent_list..files
        printline f.first.name // prints the paths
    
**Unlike** XML which has many different kinds of nodes, each `Message` returned by string.parse is interchangeable, and has only two things defining it, the type and the name.

`Message` has a type accessed via `.func`, and a name (`.name`).

For example, parsing this:

    return a > c

Well, that leads to this "AST":

    tmp "return"
    	rel 
    		thg "a"
    		opp ">"
    		thg "c"

So the message "`return`" has a type of `@tmp`. "`>`" has a type of `@opp`.

So... `Message` can be used to store all sorts of data really. Here are some things I've (practically) used it for so far:

* Source code (Speedie uses it)
* Configuration files (Speedie uses it)
* Preference files (all my apps use it)
* IPC (the `Process` class)
* Internet communications
* Various technical data

## Upcoming Section...

I am going to write a walk-through, on how to parse an iTunes song library and convert it to Jeebox! This way we have our own song-library we can easy edit or use from within Speedie. In fact my program "`MultiPlay`" uses this technique.

