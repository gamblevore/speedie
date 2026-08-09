### Containing Errors

One thing you can do with errors in speedie, is "fail gracefully".

For example, lets say you are doing a long complex operation. Like converting some database tables, and an error occurs deep within the code. Lets say this is a GUI-app.

    
    using errorlist.new
        .startconversion
        .doconversion
        .finishconversion
        if !stderr.ok
            beep "An error occured during conversion:\n\n" + stderr.render

This command "`beep`" would open up an alert-window and beep with the message passed. The "`using errorlist.new`" thing, would "contain" any errors from contaminating the rest of the program, which in this example we don't want. It does this by:

* creating a new clean `stderr`, which has no errors inside, so you can be sure stderr.ok is true
* saving the old stderr
* putting the old `stderr` back, after our job is done

You could do it manually but thats messy.

    || old = stderr
    stderr = errorlist.new
    .startconversion
    .doconversion
    .finishconversion
    if !stderr.ok
        beep "An error occured during conversion:\n\n" + stderr.render
    stderr = old

This does the same thing but I prefer the first, don't you think? Also, the "using" syntax can handle early returns:

    using errorlist.new
        if !.startconversion
            return
        .doconversion
        .finishconversion
        if !stderr.ok
            beep "An error occured during conversion:\n\n" + stderr.render

This would actually make sure `stderr` is reset to its original value no matter how we exit the `using` block.
