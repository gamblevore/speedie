# The Message Class

The `message` class does a lot of things, and can be used for many purposes. Its also designed to fit neatly into a cache-line on a modern CPU... making it fast and tight.

Learning a bit about [AST](http://google.com/?q=ast+parser)s will help you get an idea of what Jeebox is. But if you already know how to manipulate or read `XML` or `JSON` trees, that might be enough, as Jeebox is similar to those too.



## Message Properties

I guess the first best place to understand the `message` class is to look at it's properties. Lets split them up into sections:

### Tree Properties:

    |message| Parent
    |message| First
    |message| Prev
    |message| Next

These 4 properties are enough for Jeebox to be able to define a tree. When you alter any of these properties, the others are modified for you, to keep the whole thing self-consistant. You can alter `.parent`, `.prev.`, `.next` or `.first`!

Message has a lot of other functions such as `.Last` or `.Root`. They are computed rather than actual stored properties in memory. Its usually more useful to think in terms of `.first` and `.last` being real properties, even if `.last` is computed.

`.last` by the way actually is accessed almost immediately even with 1 million children, because `Message` (secretly) stores "`.first.prev = .last`" pretty cool huh! You don't see that behaviour, cos if you read `.first.prev` you will always get `nil`. But the fact is... that `.last` is constant time and fast no matter how many nodes you have. `.first` and `.last` are fast.


### Definition Properties:

    |String| Name
    |Syntax| Func // syntax is uint8

These two properties define the `message` itself. The `name` is just the text that the `message` contains.
    
For example if you parse `"a = b"` you will get these `messages`:
    
    rel ""
        thg "a"
        opp "="
        thg "b"

The quoted text (like "`a`") is the `name`, and `rel` / `opp` / `thg` are the `func`. `Func` is actually just stored as a byte in memory, so it takes up very little RAM.


### Parse Properties:

    |uint|     Position
    |uint16|   RangeLength
    |uint8|    Indent

These help you locate where the `message` came from within the original code.

`Position` is the byte position in the original string. This does not take UTF-8 characters or codepoints or glyphs into account, it is purely the byte position, which makes it easier to use.

`RangeLength` is the original length of the `message`. So... if you look at the node "cheese" in "I like cheese", the `RangeLength` is 6. This can vary from `name.length`... For example for strings. Parsing this:

    src = "main\n\treturn 0"

Well... the position starts from the `"` quotemark, and the `rangelength` extends to contain the last `"` quotemark.

The name however will be 4 bytes shorter! 2 bytes shorter because of the "" marks, and 2 more from the escape codes (slashes).

`Position` and `RangeLength` together are useful for finding `messages` within the original source code by position... for example I use it for my text editor in Perry.


### Utility Properties:

These make `message` an actually useful class... rather than just some theoretical thing. These help you to use `Message` to do real work.

    |Object|   Obj
    |uint16|   Flags
    |uint16|   Tag
    
Its not much... but it nicely makes `message` fit in a 64-byte object. Thus keeping `message` entirely within one cacheline in modern CPUs, making it very fast to use.


### Free Alteration

The `Utility` and `Parse` properties are entirely yours to use. `Message` does not care how you use these, in terms of it's `AST` meaning or how it parses or renders.

If you want to set some things onto a `Message` object, the best properties would be `.Flags`, `.Tag` and `.Obj`. These are not used at all by the system. They are there for you to use.

You can reuse `.position` to mean something else... without harm... except for the fact that you are losing the original `message`'s position, which is used for error-reporting. I have (very rarely) done this, for occasions where I really don't need the error-reporting.

`Indent` is kind of a special case, in that it does have a real specific meaning but nothing in jeebox or speedie uses it... at least not once past the time that it is parsed. I mean you could re-use it but theres not much to use, its only 1 byte.

`.rangelength` actually isnt even used for error-reporting. But why fool with it if you have better properties to use? (`.Flags` and `.Tag` are better.)

`.Obj` is very useful. This lets you set any object to a `message`. I use it all the time. My compiler speedie, uses `.obj` as the main home for all it's important knowledge. Most `messages` have something set onto `.obj`.

Again... its up to you what you want to set (if anything) onto a `message`.



## Memory Use

`Message` only uses 64 bytes per node, which is much less than most AST parsers. I find for the speedie compiler's own source code, I get a 12x memory expansion by parsing. So if you parsed 1.2MB of speedie source code, you'd use 14.4MB of `Messages`. (My entire compiler is 1.2MB of source right now.)

64 bytes is very minimal!

Comparing Jeebox to [lxml2's tree.h](https://gitlab.gnome.org/GNOME/libxml2/-/blob/master/include/libxml/tree.h), we can see their `_xmlElement` takes at least 112 bytes (with no attributes on a node). Given how most allocators work, the size is probably at least 120 bytes.

My node, is perhaps half their node size. My parser is quite memory efficient. In addition to that lxml2 is actually very "memory efficient" compared to most popular XML parsers. If theirs is efficient, mine is super efficient.

And that's just an XML parser that I am comparing Jeebox to! AST Parsers are often more complex than XML parsers. Jeebox does both... data and code, at probably half the cost per node. In addition to being a very expressive format meaning you usually need less nodes anyhow.

Also... for a large and complex compiler like my own, I've needed extra properties on my parsed message. Which is why I added the `.flags`, and `.tag` properties. These "utility properties" let me attach useful information to a node, that their xmlNode does not have... (Their xmlNode does however have `._private` which is like my `.obj` property.)

Also... their parser actually contains LESS parse info than mine does! I include not just a "line number" which is less accurate, but a byte position, a rangelength, and an indent property. This gives you a lot more useful info for locating a message's original position in a file...

