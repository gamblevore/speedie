## The List Class

Speedie has an incredible `list` class, that helps you do things with lists. Speedie's `list` is fast for insertion / removal / append, but slow for random access through large lists.

Like most things in speedie, we tend to be a bit "extra". In this case our `list` is actually **a tree**. This gives it all sorts of useful abilities. The `Message` class is based on the list class, that is how powerful `list` is. `list` is used for lists of files in Perry's GUI, and all sorts of things.

_(We talk about a list containing "nodes", but you can think of it as a list containing "items" also. Same thing.)_

---

### Containership

The list class, is a container class, like arrays and dictionaries. For example, you can make a `list of MyFunClass`.

Basically this means, that for a `list of MyFunClass`, you can only add `MyFunClass` into the list, and will only get `MyFunClass` out of the list, or `nil` if the list is empty.

The compiler knows about this and uses this info to make sure all the types are correct... and also saves you from having to check for the types of things.

___

### Internals

The list class an "intrusive list". You have to subclass it to use it as a list.

This makes it [much faster, more RAM efficient](https://www.google.com/search?q=intrusive+list+speed), and more natural to use! Especially for operations where our nodes are already meant to be a list. _<small>(In fact... I wouldn't call it "intrusive" as its basically "just a list". Intrusive is more of a C++ thing because of C++ wierdness where the list might be a property of a class rather than the super-class.)</small>_

Looking at some online C++ tests (Speedie is about as fast as C++), you can see that "intrusive lists" are 2-4x faster than non-intrusive lists. And simpler to use! Its just better.

_(The `list` class used to be called "`RingTree`". Thats because internally it uses a ring, a half-ring really. So the first child's prev sibling is actually the last child. But you don't see that, its just internal. The only difference, is that finding/appending the last item is fast.)_


___

### Consistancy and Ownership

The nice thing about the `list` class is that it keeps all your information consistant.

For example, with a list `(a,b,c)`, if you did `b.next = d`, then you would get the list `(a,b,d,c)`. It would also change `d.prev` to `b`, and `d.next` to `c`. So all the properties are kept consistant for you. Without this, it would be impossible to use.

Another very nice thing however, is that the `list` class frees us from having to worry about cyclical references. If you were to implement a tree class yourself in speedie, you would quickly run into *cyclical-reference* issues.

Cyclical-references are where two objects refer to each other, causing memory-leaks.

The `list` class doesn't suffer this.

Basically, the root of the tree owns all the descendants. Of course, a node within the tree can be removed and become it own root, and as long as you still own a reference to it, you will now have two trees.

Once the root is gone, all the nodes are gone (unless you have a reference to a node elsewhere, then it becomes it's own root).


---
### RAM Efficiency

You might ask _"well doesn't making our list, a tree... bloat the list?"_ Well... no! We stay tight.

To make any double-linked-list, you'll need the `prev`/`next` pointers (8 bytes per pointer), and then you'll need a "`Head`" pointer also. The head is to remove or change the first item in the list. So that's already 3 pointers just for a non-tree double-linked-list.

Because of how memory alignment works, and the fact that the refcount takes 4 bytes, we also require a whole pointer's size (8 bytes) worth before even getting to the first pointer, so thats 4 pointers worth.

So 4 pointers worth for a non-tree list. Adding 1 more pointer to get to a tree... is not a problem.

In fact about 95% of all list activities really want a tree anyhow. For example, a game engine might have a list of 'GameChunks' that contain 'GameObjects', and those 'GameObjects' might contain further 'GameObjects' that are perhaps like a person carrying another person. Thats already 3 levels within a tree.

Having a non-tree list and trying to implement a tree out of that... is much more awkward... when really you wanted a tree in the first place. This forces you down the right path. Which is a good thing.

Besides... Speedie's allocator is pretty perfect, much tighter than the standard `new` / `malloc` allocator, so you save more than 8 bytes per object anyhow.

### Speed

Another nice thing about my list class... is that you get almost instant access to the first and last items in the list. This makes appends fast. And we do this without wasting extra memory for a head/tail property! I just did some clever tricks to make things fast without taking memory.

This means my list class, unlike many others, doesn't need 5 pointers to describe itself, but only 4.

### Stateless Tree-Traversal

The list class... being a tree, actually has a "Stateless tree-traversal" function. This is a function that lets you find the "next" node in the tree, from a particular node. This is very handy and is used all over Speedie's code-base.

Other libraries will force you to have to create some kind of separate "tree iterator" object or perhaps even will "flatten" the entire tree into an array. How wasteful. And less fun to work with.

In fact you can travel backwards and forwards using stateless tree-traversal. The list class has a lot of useful functions for doing tree-operations in it.

to flatly loop over a node's tree contents... do this:

    for item.flat in node     // stateless tree traversal
        printline "we found item $item"

otherwise, a non-flattened loop is this:

    for item in node         // dont go deeper than immediate children
        printline "we found item $item"

You can also loop backwards, upwards and downwards... 

---
### Many utility functions

The list class has many utility functions, including:

* Sorting
* Flattening
* Moving items from one place to another
* Checking how many children there are... or if there are enough (HasAny, HasChildCount)
* Checking the distance from one node to another within a parent
* Popping and clearing
* Checking if one node is within another node, or contains another...

Quite handy in general.
    





