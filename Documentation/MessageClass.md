# The Message Class

The `message` class does a lot of things, and can be used for many purposes. Its also designed to fit neatly into a cache-line on a modern CPU... making it fast and tight.

Learning a bit about [AST](http://google.com/?q=ast+parser)s will help you get an idea of what Jeebox is. But if you already know how to manipulate or read `XML` or `JSON` trees, that might be enough, as Jeebox is similar to those too.



## Message Properties

I guess the first best place to understand the `message` class is to look at it's properties. Lets split them up into 3 sections:

### Tree Properties:

    |message| Parent
    |message| First
    |message| Prev
    |message| Next

This allows us to create a tree. `Prev` and `Next` are sibling properties. You can alter `.parent`, `.prev.`, `.next` or `.first`!

Message has a lot of other functions such as `.Last` or `.Root`. They are computed rather than actual stored properties in memory. But its usually more useful to think in terms of those... for example getting `.last` or setting `.last` (appending into a tree node).

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

I'm assuming it is less than most XML parsers too, but I'd need a real example with files and a specific case to compare against.

However, considering that just the tree itself will take 32 bytes of RAM, and then you need a name and `.obj` property to be useful at all... giving 48 bytes of RAM... regardless of XML or jeebox... And then you need a refcount and at least a "type", adding another 8 bytes to give 56 bytes...

64 bytes is very minimal! I know that any comparison from a modern "DOM"-based XML parser will not put jeebox at a disadvantage. I'd love to see a specific case though, that I can test against.

Most XML files tend to have large nodes, so you will see less than the 12x expansion I get from my source code which has a lot of "a = b + c" going on, which is actually 7 nodes in only 9 bytes.

These worst-cases in terms of memory-expansion (for parsing "a=b+c") are offsetted by other things, like white space and large names, so that on average for my source code I'm getting 12x expansion. But for XML parsing, I know it is much less.

Can't say how much without a test... just that "its probably better than most XML parsers".

For example, when I looked at the Python AST parser, each node has a "previous comment and white space" property, and a "next comment and white space" property too. Cos you need both... just to be sure.

Thats 16 bytes more... that mine doesn't need to worry about... and thats before you get to the other additions theirs has that mine doesn't need. My parser is quite memory efficient.
