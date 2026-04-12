## Advanced Error Handling

Speedie's error-reporting system has some rarer used features, such as:

+ Problems: These get printed like errors, but leave `stderr.ok` true.
+ Warnings: Also leaves `stderr.ok` true, but won't get auto-printed. (You can call `stderr.printall` to see them.)
+ Logging of errors to a file.
+ Lowering errors to warnings during certain code-sections
+ Can temporarily replace `stderr` with during certain code-sections, in case you want to contain your errors from harming the rest of the program.
+ You can loop over the errors to "clean" them if you like.


### Warnings and Problems

Speedie has multiple error levels.

        Critical: 5   // Unrecoverable. EG: OutOfMemory / signals
        Error:    4   // Real errors that stop the program doing what you wanted.
        Problem:  3   // Something bad that
        Warning:  2   // Probably is bad, best to let the user know about it.
        Hint:     1   // A suggestion for possible improvement.
        OK:       0   // Not for use.

The severity level doesn't have much difference in effect. The object still uses the same **`error`** class, and is added to the error-list, even if it's severity is **`hint`**.

However: Severities of **`Problem`**, **`Warning`**, and **`Hint`** leave `stderr.OK` as `true`.

To make a **`warning`** instead of an **`error`**, do this:
    
    main (|message| msg)
        if msg.name != "hello"
            warn (msg, "Aren't you going to say hello?")
        printline msg
        StdErr.PrintAll

Because there are no "real errors" we need to call `stderr.printall`, as **`warnings`** are not printed by default.

Theres no worry about needing to call `stderr.printall` to catch **`warnings`** in all your apps. Its just internal to your app. Speedie itself, does not create any **`warnings`**.

For example: All file-errors are proper **`errors`**, if created at all.

The only **`warnings`** created, are the ones you yourself explicitly created.


#### Problems

**Problems** are considered something "bad", but still leave `stderr.ok` as true. However, **problems** _do_ get printed by default.

    
    main (|message| msg)
        if msg.name != "hello"
            problem (msg, "Aren't you going to say hello?")
        if stderr.ok                       // this should be true!
            printline "We are still OK!"
        printline msg

You should see one **`error`** printed after this program completes. We don't have to print them manually, as **`errors`** (and **`problems`**) are printed by default after your code ends.

Why use **`problems`** instead of **`errors`**?

Lets say you deprecated a feature. Lets say you are processing a song databank, and your song nodes were previously called "songinfo", but now you wanted to rename it to be just "song".

So your users have to update their databanks. But you want old databanks to work, _and_ you want the user to know to update them. So try this:

    function LoadAllSongs (|message| music_list)
        for song in music_list
            if song == "songinfo"
                problem (song, "This should be renamed to 'song'")
                song.name = "song"
            if song == "song"
                .LoadSong(song)
            require stderr.ok // exit loop if real errors occur (not the problem above)

Now your files still work as before, `stderr.ok` is still true, and the user is informed!


### Logging

    main (|message| msg)
        stderr.LogFile = file.desktop.Child("demo.log")
        if msg.name != "hello"
            // this problem is logged to the file demo.log at the line below...
            error (msg, "Aren't you going to say hello?")
            // even if the program crashes after this, it is already logged.

You'll see one **`error`** printed, but also you'll find a file `demo.log` containing this **`error`** logged nicely.



### Error Reduction

    function app.CheckMsg (|message| msg)
        if msg != "oof"
            error (msg, "Expected an 'oof'")
        printline msg
    
    main (|message| msg)
        .checkmsg(msg)
        using ErrorSeverity.Warning
            .checkmsg(msg)
        StdErr.PrintAll
        StdErr.Clear      // or else we see the errors twice
            

Here... we should see two **`errors`** printed after the program exits:  Both are _"Expected an 'oof'"_. But one will be marked as a warning.

We need to use `stderr.PrintAll`, to see the **`warnings`**, and of `stderr.Clear` to stop the system from printing **`errors`** again after we exit.



### Replacing StdErr

Sometimes, you want to "contain" **`errors`**... But still detect them. Here is one nice way to do it. Lets look at the first example:

    main
        || f = "/not/a/file/that/exists.haha".FileThatExists
            printline "wierd, why does this file exist?"
        error "Only one error allowed!"
    
We should see two **`errors`** created. One at the **`error`** line, and the other because we can't read that wierd file-path. So lets contain that **`error`**:

    main
        using errorreceiver.new
            || f = "/not/a/file/that/exists.haha".FileThatExists
            if !stderr.ok
                printline "Awesome! we found an error but its not gonna harm us"
        error "Only one error allowed!"

Now we only see the last **`error`** created. And we see "Awesome!..." printed, proving that the **`error`** did exist... for a while.



### Error Cleaning

    main
    	for i in 1 to 3
    		error "Lets keep this: " + i
    		for j in 10
    			error "Remove this: " + j
    	for err in stderr
    		if !(err.name contains "keep")
    			err.remove

So... we created 33 **`errors`**. But we removed 30 of them. We only see these output:
    
    error: Lets keep this: 1
    error: Lets keep this: 2
    error: Lets keep this: 3
    3 issues found

Can be quite useful... for situations where one bad input, causes many **`errors`**.







