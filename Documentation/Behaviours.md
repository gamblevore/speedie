## Virtual Functions

Classes in speedie have `behaviour`s, which are just my name for virtual functions.

You can access them like this:

	class ClassA
		virtual Test (|string| name)
		behaviour Test
			"My name is $name"

	class ClassB
		behaviour Test
			"B said 'hello' to $name"

A `Behaviour` is an implementation for a virtual function... and the virtual function itself is the thing that defines what the function's parameters are.

A class doesn't need to add any behaviors, in fact behaviours were added quite late in Speedie's development. They are used for the `render` and `destructor` functions at the very least, so all classes will have some virtual functions. But you don't need to think about these... safely ignore them and you'll be fine.

I only added behaviours for game-development and GUI-development. Its not even used for the entire compiler speedie!

