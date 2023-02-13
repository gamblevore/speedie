## "JBin" - The Jeebox Binary Format

`Jbin` is just jeebox as a binary format. There isn't really much to say about `Jbin`. This is simply because the code for `Jbin` is so small. It takes about 35 lines of C++ to parse jbin.

So it is an incredible format... considering that it does so much. That said... I hate over-short example documents... so lets just spell out `Jbin` with overly detailed explanation.


### Example Use

OK, so lets make a little example:
    
    // Str is a jeebox string
    || Str = "@mary had a~little~lamb whose fleece was white as snow"
    // lets parse it
    || Msg = str.parse #require
    // now render
    printline msg.render
   
You will see this: `@mary had a ~ little ~ lamb whose fleece was white as snow`

OK great. Worked. We parsed and rendered some Jeebox. Now let's add some jbin. Add this after the code.

    || bin = msg.render_jbin
    printline bin
    
Well, you will get some unprintable characters. it might look something like this, depending on how your terminal handles unprintable characters:

    @$?mary?had@$@?a@?little?lambwhose@$?fleece?was@$?white?as?snow

OK... so thats not what we wanted. But its what we should expect, because jbin is a binary format. OK, so lets try looking at the hex. Add this to the end:

    printline bin.hex

You should see: "`1003402484076D 61727983046861 644024401A8103 61401A86036C69 74746C6584036C 616D62C2850477 686F73654024860 3666C656563658 30477617340248 50377686974658 20461738403736 E6F77`"

Great! So we can see that this looks nothing like a proper text file. 

Now, lets reparse this binary data:

    || Msg2 = bin.parse
    printline msg2.render
    
Prints this again: `@mary had a ~ little ~ lamb whose fleece was white as snow`

Well... you aren't convinced that these two trees are the same? Lets try this then:

    message.treecompare(msg, msg2, true)
    msg.last.last.last.first.name = "cold"
    message.treecompare(msg, msg2, true)

You should see error messages printed, including "`cold error: Unexpected thing “cold”`". OK, so that is proving that the tree comparison works... it can find differences in the two trees.

The first test passes and the second fails exactly where we expected it to. This proves that we have stored the `Message`s as jbin, and parsed it back successfully.

There really isn't much more to it than that! All you need to do is call `message.render_jbin` instead of `message.render` and save that to your files instead, or pass it across the network or whatever you want to do with it.

There's not much you can say about the 15 lines of (speedie) parsing code it takes to parse jbin, really. (35 lines in C++). Jbin is so simple. And thats what so great about it.

### Transparent binary handling

Just remember, jbin is always parseable by jeebox. So you have nothing to lose and no extra steps to do, just to parse some jbin. You literally call the same `string.parse` and jeebox will recognise the `jbin` header and parse it. 

#### Jbin advantages to Jeebox

* Faster parse and render
* **Amazingly** smaller when storing binary files
* Won't ever change. Jeebox does get tweaks from time to time, but Jbin doesn't need any.
* Really easy to write parsers for in other languages, like javascript.

#### Jbin disadvantages
* Not human readable
* Does not store formatting, or comments
    
#### History

Lets give a little history about `jbin`. OK, so... basically, I was writing an `.m4a` parser in Speedie. This is to let me import files into a music player.

So, I had to parse a quick-time file. This is the "`moov`" or "`atom`" format, which... to be honest, kinda sucks. `jbin` is so much better! But then, this format is used for all Apple's music and all sorts of things, so... it can't be that bad?

Jbin is still better. I was writing the `m4a` parser and realised "wait... I can improve on this". So I did. I removed everything bad, added a few good things... and voila: **`jbin`** was created.

Actually jbin is nothing like `m4a`, except being binary. Thats how much I changed.

#### Jbin Compared to Apple's atom (quicktime) format

* Faster (because it is simpler)
* Smaller. 2 bytes overhead per node, vs 12 to 24 bytes.
* Entire tree is visible. QuickTime's format relies on you knowing each "type" (4 byte string codes) and whether or not it has children. Which is impossible for vendor-defined codes.
* Can be streamed when generating it... because we don't need to know the entire **combined** length of a node and all it's children, ahead of time. You can't "streamedly generate" something if you require "pre-knowledge" of things that haven't been created yet, can you!
* More generic. QuickTime's format can either have children, or a name, but not both. Jeebox can have both.
