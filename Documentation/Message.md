## Messages
(aka **Jeebox**)

In Speedie, when you parse a string using `string.parse`, you get back a tree. A `Message` is a node within a parsed tree. Jeebox uses trees much in the same way XML or JSON does, but more advanced and simpler.

Its more advanced because the syntax can represent both code or data. Here is some data, in Jeebox.

    file_list
        item "/path/to/file1" (Picture)
        item "/path/to/file2" (Sound)
        item "/path/to/file3" (Text)
        
Imagine we wanted to parse it. Lets put it in "example.box" and parse that file.

    || recent_list = "example.box".file.parse
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

Jeebox (and it's `Message` class), is useful for almost anytime you need a new or custom data-format of any kind.

Here are some things I've (practically) used Jeebox for, so far:

* Source code (Speedie uses it)
* Configuration files (Speedie uses it)
* Preference files (all my apps use it)
* IPC (the `Process` class)
* Internet communications
* Data-banks (song libraries)

## Walkthrough of creating a Book Searcher

OK, in this walk-through, we are gonna create small example program, in Speedie. We'll make some example files and mark our progress through the tutorial.

Let's start with an XML data-bank, the first thing we want to do is convert it to Jeebox. You should find the file `books.xml` in the examples folder.

    <?xml version="1.0"?>
    <catalog>
       <book id="bk101">
          <author>Gambardella, Matthew</author>
          <title>XML Developer's Guide</title>
          <genre>Computer</genre>
          <price>44.95</price>
          <publish_date>2000-10-01</publish_date>
          <description>An in-depth look at creating applications 
          with XML.</description>
       </book>
    ...

First, lets test that we can even read a file at all. Lets take the file via command-line arguments.

    #!/usr/local/bin/spd
    
    main 
    	|| path = app.args[0]			#expect ("Pass a file-path")
    	|| B = path.ExistingFile		#require
    	|| jb = B.parse
    	jb.xmltojeebox
    	printline jb

Ooops, well we converted it already. See that line `XMLToJeebox`? I guess in my enthusiasm I already converted it. Anyhow so thats great. Now lets save this file to jeebox, might as well.

    path.Ext("Box").FileData = jb.render

Now, the jeebox file is saved to disk. We could do searching in the file, but first a few safety checks. Lets only do the `XML->Jeebox` conversion if we pass an XML file, and lets tell them we did it!

Also, lets make sure we return if `b.parse` fails. And lets put in a safety check in case someone passes a non-XML file as an XML-file.

		expect jb.find(@xml)   (b, "This is not an XML file")

Altogether that makes this:

	|| path = app.args[0]			#expect ("Pass a file-path")
	|| B = path.ExistingFile		#require
	|| jb = B.Parse					#require
	if b isa "xml"
		expect jb.find(@xml)   (b, "This is not an XML file")
		jb.XMLToJeebox
		path.Ext("box").FileData = jb.render

(Starting now, I won't put the "`#!/usr/local/bin/spd, main`" parts anymore. Just assume it is  at the start of the code.) 

Now, lets do the searching! Let's specify some search queries via command-line arguments. 
    
    ... // new code
    	for arg in app.args
    		|| SearchName = arg.ArgName #expect "Unexpected input: $arg"
    		|| Found = BookSearch(jb, SearchName, arg.ArgValue)
    			printline Found
    		  else
    			printline "Can't find: $arg"
		
    function BookSearch (|message| BookFile, |string| Name, |string| ToFind, |message|)

Looks great! Very readable and also we got very far in our progress! Lets do a little more to finish this off: