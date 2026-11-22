## Areas of Speedie that are likely to change

Because Speedie is still a new language, it has areas that need work and may or will change. I'll list a few.

This means, to keep your expectations in check. Be prepared for breaking changes, even if they are minor and require minor fixes.

Mostly Speedie is very stable by now, due to many years of development, but some things still need change!

* Tasks: Tasks are Speedie's version of _functional-programming_. So you can store a function as an object, the object stores state, and it can be called later at anytime. However... the syntax is just... bad. Good old function-syntax is better and easier to understand than Speedie's task syntax.
* Opt NoRefCounts: This one is a big one. Its just a pain to always be adding/removing this. It can make a big difference in speed. But speedie is usually super-fast even with refcounting. So why allow it? Because I am a speed-obsessed speed freak. No actual reason. But its such a source of bugs. I hate it. In the future, I want to make Speedie optimise refcounts automatically, then opt norefcounts can be removed.
* VObject: This is a visual object, with space and position and stuff. I want it to change, a lot in the future. Not sure how. But a lot.
* Dictionary: I want to replace this with my FixedDict class at some point. The changes should be transparent. It will just be faster and use less memory. FixedDict still can't replace Dictionary because it doesn't have '_leaf-nodes_'.
* Dynamic Property Adding: I want this at somepoint, or else it becomes very hard to make certain kinds of code. However, doing this nicely without bloating the heck out of everything, is not easy. So, its a challenge to figure out the right approach here.

