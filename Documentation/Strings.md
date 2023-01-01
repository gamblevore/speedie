## Strings In Speedie!

Speedie has great string support! One of the main things you'll find is that Speedie is good for string processing. In fact, we don't use greps or have greps because greps are rubbish and slow. And no one understands them.

Anyhow... so let's start with a few things. Firstly there's the string class itself:

	function Example
		|| Greeting = "hello"
		printline greeting // prints "hello" to stdout

So greeting is a string here. Easy enough? Lets do one better. If you want to print a line, you can just do this:

	function Example2
		"hello" // same as printline

Want to put some "impossible" or awkward letters into your string? You can escape them:

	"BasicLine\n\tIndentedLine\nA wierd looking \81o&#9447;"
	// prints:
	// BasicLine
	//     IndentedLine
	// A wierd looking Ɓoⓧ

Speedie (because it is based on Jeebox) inherits all of Jeebox's abilities with expressing strings... but adds some more too. In this case, Speedie has "inherited" all the escape codes, including byte escape codes (`\81`), character-entities (`&#9447;`), and normal escape codes (`\n`).


Thats nice, but what if you wanted to print a number? Or perhaps a count of some items:

	|| shopping = ["eggs", "milk", "beefs"]
	"We have ${shopping.length} items to shop for. Here is the list:\n$shopping"

Seems great, but what if you wanted a string that happens to contain something that LOOKS like an escape code or contains double-quote?

	printline `I am "Fred" and sometimes I look like this:
    \o/
     |
    / \ 
    `

Seems good but what if you had some real binary data that just contains ALL the bytes from 0-255, and you wanted to put it in your app. Perhaps it is actually a SHA-256 hash used to verify a file.
	
	|| myhash = #(5121dc529808dc02bf8df8f44595babf701477d62d6260f0aa65cd7b3117e8dd)#

These kind of strings mean you DON'T need to do something like `myhash = myhash.unhex`, which is sometimes annoying. It's nice to be able put raw binary data into your code, and so many tools output binary data as hex.

Well thats a lot of ways of storing a string... but what if you had a FILE that you wanted to embed into your project, as a string? Just do this:

	|| mystring = file://filename.txt

Speedie will find that file, as long as it exists within your project. No need for full paths or even paths relative to the project base.



More docs coming later! Theres a lot more to say about strings, parsing them... the charset class, the FastString class! Dictionaries, helper-functions, sorting and much more!

