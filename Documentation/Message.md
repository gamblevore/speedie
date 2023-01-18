## Messages
(aka **Jeebox**)

In Speedie, when you parse a string using `string.parse`, you get back a tree. A `Message` is a node within a parsed tree. The format we are parsing, is called “Jeebox” ([http://jeebox.org]()).

In fact, you can parse file-objects as well. This is better because error messages created will point back to the parsed file.

The format “Jeebox” can represent both code and data (and more, be creative!). Here is some data.

    file_list
        item "/path/to/file1" (Picture)
        item "/path/to/file2" (Sound)
        item "/path/to/file3" (Text)
        
Imagine we wanted to parse it. Lets put it in "example.box" and parse that file.

    || recent_list = "example.box".file.parse
    for item in recent_list["file_list"][@arg]
        || name = item[@str,0].name.name
        || type = item[@bra,1][@thg].name
        "$name is a $type"                    // "file1 is a Picture,  file2 is a Sound,  file3 is a Text"
    
**Unlike** XML which has many different kinds of nodes, each `Message` returned is interchangeable, and has only two things defining it, the type and the name.

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

OK, in this walk-through, we are gonna create a small program. You should use the example files, at `/usr/local/speedie/examples/books_xml` that will be in the github repo.

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
        || path = app.args[0]            #expect ("Pass a file-path")
        || B = path.ExistingFile         #require
        || jb = B.parse
        jb.xmltojeebox
        printline jb

Ooops, well we converted it already. See that line `XMLToJeebox`? I guess in my enthusiasm I already converted it. Anyhow so thats great. Now lets save this file to jeebox, might as well.

    path.Ext("box") <~ jb.render

Now, the jeebox file is saved to disk. The `<~` operator just means "write this string to the file at this path". Lets take a look at it:

    catalog 
        book (id: "bk101") 
            author "Gambardella, Matthew"
            title "XML Developer's Guide"
            genre "Computer"
            price "44.95"
            publish_date "2000-10-01"
            description "An in-depth look at creating applications \n      with XML."
    ...

Much better! Actually the file is 25% smaller already, although XML->Jeebox can usually save a lot more than that.

We could do searching in the file, but first a few safety checks. Lets only do the `XML->Jeebox` conversion if we pass an XML file, and lets tell them we did it! Also, lets make sure we return if parsing fails.

Altogether that makes this:

    || path = app.args[0]            #expect ("Pass a file-path")
    || B = path.ExistingFile         #require
    || jb = B.Parse                  #require
    if b isa "xml"
        jb.XMLToJeebox
        || boxfile = path.Ext("box")
        if boxfile <~ jb.render // write file to disk
            "Converted XML to Jeebox: $boxfile"

(Starting now, I won't put the "`#!/usr/local/bin/spd, main`" parts anymore. Just assume it is  at the start of the code.) 

Now, lets do the searching! Let's specify some search queries via command-line arguments. We'll use `app.switches` to find arguments like "`--author=tim`", then use `.ArgName` and `.ArgValue` to get the name/value from the switch.
    
    ... // new code
    for arg in app.Switches
        || Found = BookSearch(jb, arg.ArgName, arg.ArgValue)
            "$Found"
          else
            "Can't find: ${arg.ArgName} '${arg.ArgValue}'"
        
    function BookSearch (|message| BookFile, |string| Name, |string| ToFind, |message|)

Looks great! Very readable and also we got very far in our progress!

### Reading the Parsed Tree ###

So far all we did was just parsing, or read or write files or switches, handle errors, etc. But not actually using Jeebox. So lets do that.

First, we need to find `"catalog"`, which isn't the root actually, because the root is an `@arg` (a list of statements).

    || catalog = BookFile[@tmp, "catalog"] #require

`BookFile[@tmp, "catalog"]` will get a `@tmp` named "catalog", and will create an error if the name is wrong. `@tmp`, `@str`, etc are just node types. Also, `#require` will return if "catalog" is set to `nil`. Its the same as: `if catalog==nil: return nil`

Now we need to list through all the books, they are contained in another node, an `@arg`. `@arg` is a list of statements (`"catalog"` or `"book"` is a statement in this example), or other things, but its the only thing that can contain statements. We need it to read the books.

    || booklist = catalog[@arg]            #require

Now let's go over the list:

    for book in booklist
        printline book.first

We just put `printline` here to verify that we are getting the books. We should see this output:

    (id: "bk101")
    (id: "bk102")
    (id: "bk103")
    (id: "bk104")
    ...

OK great! We are now listing over our books! Now to search each book for the search query.

So lets delete the printline statement and add this:

        for row in book[@arg,-1]
        
That will give us access to the rows like this:

    author "Gambardella, Matthew"
    title "XML Developer's Guide"
    genre "Computer"
    price "44.95"
    ...

`book[@arg,-1]` means "get the last child of `book`, and make sure it is an `@arg`" Lets check we can actually read them:

    for book in booklist
        for row in book[@arg,-1]
            printline row.first.name

    /* we will see these lines:
    Gambardella, Matthew
    XML Developer's Guide
    Computer
    44.95
    2000-10-01*/

OK, so lets do the actual comparison! We will add this

    if (row ~= name) and (row.first.name contains tofind)

Here is our total search function. Great it works!

    function BookSearch (|message| BookFile, |string| Name, |string| ToFind, |message|)
        || catalog = BookFile[@tmp, "catalog"] #require // gets "catalog" + creates error if name is wrong
        for book in catalog[@arg]
            for row in book[@arg,-1]
                if (row ~= name) and (row.first.name contains tofind)
                    return book


Now, calling this commandline:

    booksearch.spd books.box --author=Corets

Will return this book:

    book (id: "bk103") 
        author "Corets, Eva"
        title "Maeve Ascendant"
        genre "Fantasy"
        price "5.95"
        publish_date "2000-11-17"
        description "After the collapse of a nanotechnologysociety in England, the young survivors lay the foundation for a new society."

### Success! ### 
We could probably improve our code. If we search for multiple-queries, it doesn't reduce the books found but increases it. This isn't a jeebox problem anymore but just a basic logic problem. But lets fix that anyhow for completeness.

Here is the final total code, with the logic bug fixed:

        
    #!/usr/local/bin/spd
    
    main 
        || path = app.args[0]            #expect ("Pass a file-path")
        || B = path.ExistingFile         #require
        || jb = B.Parse                  #require
        if b isa "xml"
            jb.XMLToJeebox
            || boxfile = path.Ext("box")
            if boxfile <~ jb.render // write file to disk
                "Converted XML to Jeebox: $boxfile"
    
        || Queries = app.Switches
        || Found = BookSearch(jb, Queries)
            "$Found"
          else
            "Can't find any books by: $Queries"
            
            
    function BookSearch (|message| BookFile, |[string]| Queries,  |[message]|)
        || catalog = BookFile[@tmp, "catalog"] #require
        for book in catalog[@arg]
            if book.TestBook(Queries)
                rz <~ book
                
    
    function message.TestBook (|[string]| queries, |bool|)
        for row in self[@arg,-1]
            for Q in queries
                if row ~= q.ArgName // ~= is like == but case-insensitive
                    require row.first.name contains q.ArgValue
                    rz = true
                
        


This program is doing a lot more than it might seem.

* A little file validation (via `BookFile[@tmp, "catalog"]` type functions)
* Converts XML to Jeebox
* Saves the Jeebox to disk
* Optionally reads Jeebox or XML files as input, as decided by the file's extension (`B isa "xml"`)
* Tests for valid input arguments as well as that the input file exists.
* Reports all errors to stdout (this is done by the framework, there isn't a specific line of code that does this.)
    
Now, the same search query (`--author=Corets`) will return 3 books!

    [(id: "bk103"), (id: "bk104"), (id: "bk105")]

Wonderful! And with this: `booksearch.spd books.xml --author=Corets --description=London`

We further filter it down to only one book. Perfect.

## Advanced: Compression and jbin ##

If you want to go even more advanced, you could do things like compress the jeebox file or store it as `jbin`, or even a compressed `jbin`! Lets try that now...

    boxfile <~ jb.render_jbin // write file to disk as jbin

`Jbin` is just jeebox, but in a binary form. `jbin` is approximately the same size as jeebox, except when it comes to storing binary data, when it is far smaller. `Jbin` can store everything jeebox can. Best of all... jeebox transparently parses it. Also, the code for `jbin` is very small, you could parse it in about 30 lines of C++.

`jbin` parses between 2x to 20x faster than Jeebox.

**What about compression?**

    boxfile <~ jb.render.compress // write file compressed

this will compress the data then write it to disk. Again, Jeebox is smart enough to be able to parse compressed files, (assuming it was compressed by speedie's `.Compress` function, not .zip or anything.)

Jeebox, Speedie and Perry can  all handle jbin and compressed files...