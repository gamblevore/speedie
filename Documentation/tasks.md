## Tasks and Concurrency

_How to do concurrency in speedie_

Speedie has **tasks**, and **message-passing** as the main concurrent components. Speedie also has threads, but threads are only for experts and require you to limit yourself to certain higher principles.


#### Tasks

If you want to schedule things to be done later, use speedie's `Task` class! Tasks are speedie's answer to _functional programming_. In fact you probably wouldn't use task for _functional programming_, but they both capture variables to use within the function you wrote. So it is identical under the hood.

You are usually responsible for calling the tasks later... HOWEVER... speedie's GUI-environment already has a task-runner system. So you can easily schedule tasks to be run later, within GUI-apps.

The simplest task is like this:

	task_run HelloSayer
		"hello" // will print "hello" when run

Lets show a nice example 😰:

    main
    	|| hello = abc.HelloSayer()
    	(hello)()
    	|| say = abc.stringsayer("goodbye")
    	(say)()
    	|| rsay = abc.randomsayer("hehe")
    	(rsay)()

    module abc
    	task_run HelloSayer                       // one way of creating a task
    		"hello"
    
    	task_run StringSayer (|string| str)       // a second way
    		printline .str
    	
    	task RandomSayer (|string| name)          // a third way
    		|uint16| RandomID = 0
    		constructor
    			.randomid = random.shared.int
    		run
    			"$.name $.randomid"
	// Currently tasks need to live within modules... Just deal with it OK. I'm doing this unpaid and I didn't need it outside of a module.
	
Running this, you should see this output:

    hello
    goodbye
    hehe <random number here>



#### Message-Passing

Speedie basically uses ["the erlang model"](https://www.youtube.com/watch?v=TTM_b7EJg5E) of concurrency. This is simply "the right choice". Any other choice is wrong. 🥰 (Unless its compatible with it.) 🤭

So you run a separate process, an instance of your program, and communicate with message-passing.

It could be started via `spdprocess.fork()` or via running a speedie program (on disk) via `spdprocess.Run()`.

Both return an `spdprocess` class. The `SpdProcess` class lets you talk to speedie processes... via message-passing.

Funnily enough, the [message class](Message.md) is perfect for passing... well... messages. So Jeebox is exactly what we need to pass nicely structured data across processes. So its quite fun and awesome and strangely presciently-named. In fact, the `message` class was called  "message" because it is about describing meaning and stories... which are forms of messages. (human readable stories).

So we use the message class. Here is a good example:

    || WorkerAppPath = "/path/to/worker"
    || child = spdprocess.run(WorkerAppPath, ["data1", "data2"])
    require child
    || pass = @tmp + "hello"
    || adj = pass.msg(@adj)
    adj <~ (@thg, "my")
    adj <~ (@thg, "child")
    child <~ pass // sends the message "hello my~child"

The [message class](Message.md) lets you pass any data... strings, integers, lists, trees. So its quite flexible.

However, it does require you to get quite familiar and "intimate" with the message class and how it works. There isn't too much way around this.

At a minimum, you need to know what is a [message class](Message.md), and that it is a tree of nodes, (each node being a type + name). And you need to know the functions needed to add things into the tree.

You can pass [`jbin`](jbin.md) directly to the spdprocess... but thats a bit more advanced. And faster too :) Takes less memory. I'll describe how later.

Either way... that is about it. The other side can retrieve the message and gets it back as a [message class](Message.md).


#### Threads

Speedie also has threads. Threads are only for expert users... 🐲 (Beware here are dragons) 🐉 .

Basically Speedie works under the principle of being a "non-infantilising language". So the idea is... that you **may** use threads, but only if you **dont** violate Speedie's existing principles.

Greatest principle of all... is don't corrupt memory, especially object-memory! This isn't C++ where you are allowed to corrupt (write to) memory all-over as you like. Nope! Speedie has a definite memory-model of what it expects the world to be. You can do anything you like, as long as you don't violate principles.

This means... you almost certainly won't be sharing objects across threads. In fact, the problem is worse. Two threads can't even allocate objects at the same time, as the memory-manager is simply not concurrent in any way. You can't even destroy or refcount objects at the same time. And refcounting happens automatically anyhow... unless disabled or in certain situations.

Unless one of your threads was the "main thread" and the others were "purely data-only", like they just processed some block of memory like doing some graphics or sound processing... threading isn't going to be useable.

In fact, Speedie's system already uses multiple threads! However, it sticks to these same principles. For example, the message-passer system itself has its own worker threads. But these do not work in terms of speedie's memory-manager, or speedie objects. It manages it's own memory.

My (unreleased) game engine in speedie, also uses threads for the audio. Again... it doesnt use speedie's memory manager, but it's own. It communicates to the main thread, using a miniature message-passer :)

Hopefully you are seeing the pattern. Speedie uses message-passing. It is our way.



## Future Upgrades

In the future, I plan to improve messages and tasks. Here are some of my ideas:

* Make task syntax even simpler
* Allow functional programming to look syntactically "natural"? (it can be done but its not so elegant currently). Its not terrible right now... just could be even better!
* Allow functions to be run as separate processes and communicate with them nicely. (can already be done using `fork()`, but we want this to look nice and simple)
* Make message-passing even more natural. We want to define interfaces naturally to our message-passing system.

For example:

    class FileReader
        interface
            function Read (|string| Path, |string|)
                // code here
            function Write (|string| Path, |string| Data, |ErrorInt|)
                // code here


Then the other side could import this interface and run it. Perhaps something like this:

    import "/My/Cool/File/Reader" as FileReader

    || P = FileReader.Run
    || MailBox = P.Read("afile.txt") // doesnt return data immediately... but allows processing to continue
    
    DoSomeStuffInbetween()
    || Data = MailBox.get(5s) // waits up to 5 seconds for the data to appear.
        printline Data
      else
        printerror p.lasterror
    
We could add more functions... like `MailBox.ValueHasArrived()` (but named shorter), or `MailBox.wait()`... etc etc.

We could make this even shorter and more natural, at the cost of loss of some control:

    || P = "/My/Cool/File/Reader" #run  // imports the interface from the program (on compile) and then runs it (At runtime)
    || Data = P.Read("afile.txt") #wait 5s // gets the data and waits for 5s max
        printline Data
      else
        printerror p.lasterror
    
We could even add callbacks to mailboxes... so you don't need to wait or write convoluted code to check all the time.

    || P = "/My/Cool/File/Reader" #run
    run P.Read("afile.txt") for 5s
        printline  .get
      else
        printerror .lasterror

