## Messages
(aka **Jeebox**)

This is an overview of how to use the Message class, without going into the details of the [functions and properties of Message](Message.md).

In Speedie, when you parse a string using `string.parse`, you get back a tree. A `Message` is a node within a parsed tree. The format we are parsing, is called “Jeebox” ([http://jeebox.org]()).

You can parse strings or files. But parsing files, lets any errors created point back to the file.

The format “Jeebox” can represent both code and data (and more, be creative!). Here is some data in jeebox:

    file_list
        item "/path/to/file1" (Picture)
        item "/path/to/file2" (Sound)
        item "/path/to/file3" (Text)
        
Imagine we wanted to parse it. Lets put it in "example.box" and parse that file.

    || recent_list = "example.box".file.parse
    for item in recent_list["file_list"][@arg]
        || name = item[@str,0].name
        || type = item[@bra,1][@thg].name
        "$name is a $type"                    // "/path/to/file1 is a Picture,  /path/tofile2 is a Sound,  /path/to/file3 is a Text"
    
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

The message "`return`" has a type of `@tmp`.

And "`>`" has a type of `@opp`.

Jeebox (and it's `Message` class), is useful for almost anytime you need a new or custom data-format of any kind.

Here are some things I've (practically) used Jeebox for, so far:

* Source code (Speedie uses it)
* Configuration files (Speedie uses it)
* Preference files (all my apps use it)
* IPC (the `Process` class)
* Internet communications
* Data-banks (song libraries)

## Walkthrough of creating a Book Searcher

OK, in this walk-through, we are gonna create a small program. You should use the example files, at `/usr/local/speedie/Examples/books_xml` that will be in the github repo.

Let's start with an XML data-bank, the first thing we want to do is convert it to Jeebox. You should find the file `books.xml` in the examples folder.

    <?xml version="1.0"?>
    <catalog>
       <book id="bk101">
          <author>Gambardella, Matthew</author>
          <title>XML Developer's Guide</title>
          <genre>Computer</genre>
          <price>44.95</price>
          <publish_date>2000-10-01</publish_date>
          <description>An in-depth look at creating applications with XML.</description>
       </book>
    ...

First, lets test that we can even read a file at all. Lets take the file via command-line arguments. Lets save our code with the name "`booksearch.spd`".

    #!/usr/local/bin/spd
    main (|File.Existing| file)
        || jb = file.parse
        jb.xmltojeebox
        printline jb

Ooops, well we converted it already. See that line `XMLToJeebox`? I guess in my enthusiasm I already converted it. Anyhow so thats great. Now lets save this file to jeebox, might as well.

    file.SetExt("box") <~ jb.render

Now, our document is saved to the file "`books.box`" (assuming you passed in `books.xml`). The `<~` operator just means "write this string to the file at this path". Lets take a look at it:

    catalog 
        book (id: "bk101") 
            author "Gambardella, Matthew"
            title "XML Developer's Guide"
            genre "Computer"
            price "44.95"
            publish_date "2000-10-01"
            description "An in-depth look at creating applications with XML."
    ...

Much better! Actually the file is 25% smaller already, although XML->Jeebox can usually save a lot more than that. From now on, we can pass in `books.box` instead of `books.xml` to our app.

We could do searching in the file, but first a few safety checks. Lets only do the `XML->Jeebox` conversion if we pass an XML file, and lets tell them we did it! Also, lets make sure we return if parsing fails.

Altogether that makes this:

    #!/usr/local/speedie
    main (|File.Existing| File)
        || jb = File.parse
        if file isa "xml"
            jb.XMLToJeebox
            || boxfile = File.SetExt("box")
            if boxfile.writeall( jb.render )
                "Converted XML to Jeebox: $boxfile"
        printline jb

Now, lets do the searching! Let's specify some search queries via command-line arguments. We'll use `app.switches` to find arguments like "`--author=tim`", then use `.ArgName` and `.ArgValue` to get the name/value from the switch.

Also, let's comment out `printline jb`, no need to be so noisy.

    // printline jb
    // append this code
    for arg in app.Switches
        || Found = BookSearch(jb, arg.ArgName, arg.ArgValue)
            for f in found
                printline f
          else
            "Can't find: ${arg.ArgName} '${arg.ArgValue}'"
        
    function BookSearch (|message| BookFile, |string| Name, |string| ToFind, |message|)

Looks great! Very readable and also we got very far in our progress!


### Reading the Parsed Tree ###

So far all we did was just parsing, or read or write files or switches, handle errors, etc. But not actually using Jeebox. So lets do that. First, we need to find `"catalog"`. Lets add that to `BookSearch`.

    || catalog = BookFile[@tmp, "catalog"] #require

This gives us a `@tmp` named "catalog", or creates an error if that `@tmp` can't be found. `@tmp`, `@str`, etc are just node types. `#require` here does the same as: `if catalog==nil: return nil`.

Now we need to list through the books, they are contained in catalog's `@arg`.

    for book in catalog[@arg]
        printline book.first

We just put `printline` here to verify that we are getting the books. If we call it like this "`booksearch.spd books.box -author=corets`", we should see this output:

    (id: "bk101")
    (id: "bk102")
    (id: "bk103")
    (id: "bk104")
    Can't find: author 'corets'
    ...

OK great! We are now listing over our books! Now to use the search query.

So lets delete the printline statement and add this:

        for row in book[@arg,-1]
        
That will give us access to the rows like this:

    author "Gambardella, Matthew"
    title "XML Developer's Guide"
    genre "Computer"
    price "44.95"
    ...

`book[@arg,-1]` means "get the last child of `book`, and make sure it is an `@arg`" Lets check we can actually read them:

    for book in catalog[@arg]
        for row in book[@arg,-1]
            printline row.first.name

    /* we will see these lines:
    Gambardella, Matthew
    XML Developer's Guide
    Computer
    44.95
    2000-10-01*/

OK, so lets do the actual comparison! We will add this:

    if (row ~= name) and (row.first.name contains tofind)
        return book

Here is our total search function. Great it works!

    function BookSearch (|message| BookFile, |string| Name, |string| ToFind, |message|)
        || catalog = BookFile[@tmp, "catalog"] #require // gets "catalog" + creates error if name is wrong
        for book in catalog[@arg]
            for row in book[@arg,-1]
                if (row ~= name) and (row.first.name contains tofind)
                    return book


Now, calling this commandline:

    ./booksearch.spd books.box --author=Corets

Will return this book:

    book (id: "bk103") 
        author "Corets, Eva"
        title "Maeve Ascendant"
        genre "Fantasy"
        price "5.95"
        publish_date "2000-11-17"
        description "After the collapse of a nanotechnologysociety in England, the young survivors lay the foundation for a new society."


### Success!

We could probably improve our code. If we search for multiple-queries, it doesn't reduce the books found but increases it. This isn't a jeebox problem anymore but just a basic logic problem. But lets fix that anyhow for completeness.

I'll also clean up the code a little... just use the final code. Here is the final total code:

        
    #!/usr/local/speedie
    
    main (|File.Existing| File)
        || jb = File.parse
        if file isa "xml"
            jb.XMLToJeebox
            || boxfile = File.SetExt("box")
            if boxfile.writeall( jb.render ) // write file to disk
                "Converted XML to Jeebox: $boxfile"
    
        || Found = BookSearch(jb, app.switches) #expect  "Can't find any books using: ${app.Switches}"
        for f in found
            printline f
    
            
    function BookSearch (|message| BookFile, |[string]| queries, |message|)
        || catalog = BookFile[@tmp, "catalog"] #require // gets "catalog" + creates error if name is wrong
        for book in catalog[@arg]
            for row in book[@arg,-1]
                if book.Expect(@tmp, "book") 
                    rz <~ book.TestBook(Queries)
    
    
    function message.TestBook (|[string]| queries, |message|)
        for row in .last(@arg)
            require row.Expect(@tmp)
            for Q in queries
                if row ~= q.ArgName
                    require Row.first.name contains q.ArgValue
                    rz = self
                
        


This program is doing a lot more than it might seem.

* A little file validation (via `BookFile[@tmp, "catalog"]` type functions)
* Converts XML to Jeebox
* Saves the Jeebox to disk
* Optionally reads Jeebox or XML files as input, as decided by the file's extension (`file isa "xml"`)
* Tests for valid input arguments as well as that the input file exists.
* Reports all errors to stdout (this is done by the framework, there isn't a specific line of code that does this.)
    
Now, the same search query (`--author=Corets`) will return 3 books! Wonderful! And with this: `booksearch.spd books.box --author=Corets --description=London`

We further filter it down to only one book. Perfect.

## Advanced: jbin ##

If you want to go even more advanced, you could do things like compress the jeebox file or store it as `jbin`, or even a compressed `jbin`! Lets try jbin now...

    boxfile.writeall( jb.render_jbin ) // write file to disk as jbin

`Jbin` is just jeebox, but in a binary form. `jbin` is approximately the same size as jeebox, except when it comes to storing binary data, when it is far smaller. `Jbin` can store everything jeebox can. Best of all... jeebox transparently parses it. Also, the code for `jbin` is very small, you could parse it in about 35 lines of C++.

`jbin` parses between 2x to 20x faster than Jeebox. [Learn more about jbin](jbin.md)

**What about compression?**

Jeebox has inbuilt decompression, of it's own format "mz" that is inbuilt in Speedie. Perry, Speedie and Jeebox all transparently handle compressed files.

However, the compression right now is not finalised, I feel its not good enough yet. (It seems good on large files but not so good on smaller files, which most jeebox files are.) I'll probably add `gz` decompression to Jeebox, as it seems widely used, and gz is good on small files.
