## Error Handling In Speedie

The way Speedie handles errors, is something I'm quite proud of. That is, it handles errors in "the right way".

Most languages make a mess of errors. We don't. We do things the right way. All errors flow through a central object we call `StdErr`.

C++ has exceptions, and many other languages followed. (Java, python, rust, etc). Unfortunate! But at least they have other advantages.

Anyhow, so what we do, is collect a list of errors. Errors can be generated from any function. They don't affect code-flow, except unless you **want** it to. Let's make a simple example:


    || BannedWords = "poop/smelly".split
    function string.NameIsOK (|bool|)
        for b in bannedwords
            if self contains b
                return false
        return true

    function CheckUserListNames (|string| userspath)
        || userlist = userspath.file.parse            #require
        "User list parsed OK"
        for user in userlist
            error user.name.NameIsOK (user, "User has a bad name.")
        if stderr.ok
            "All users have good names"
          else
            "${stderr.errorCount} users have bad names"
        


Well... a lot of things are going on in this code, so lets break it down. First, the `#require` statement. This statement will return from the function if the value (`userlist` in this case) does not evaluate to true.

In other words, if `.file.parse` returns `nil`, then `CheckUserListNames` will end at the `#require` line.

Speedie has a lot of statements including `require` / `expect` / `error`, used for control-flow and error-handling. It just gets all the messy control-flow out of your way, so you can see your code. Very-useful for error-handling.

These statements can be used after some code, or before.

    function RequireTest
        || A = "a,a,a".parse            #require
        || B = "b,b,b".parse
        require B

both `A` and `B` are tested in the exact same way. The control-flow is the same. But the first looks better to me. Its more "out of the way". Like an after thought thats not relevant to the usual understanding of how the function works.

Lets make a list of the statements:

+ `expect` - This will create an error, and return from the function if the expression is false.
+ `require` - This will just return, if the expression is false. No error.
+ `error` - This will create an error if the expression is false. But the code will continue to flow.

There are others but they will just confuse you right now. So reading the `CheckUserListNames` function... what do we see us doing?

+ We parse a file
+ If the file can't be parsed, then we return.
+ Otherwise we print "User list parsed OK"
+ Then we go through the list of users
+ We check each user-name to see if it contains any bad words.
+ If a user DOES have a bad word, then `user.name.NameIsOK` returns false, which will be caught by the `error` statement, which will generate an error and send that error to `stderr`.
+ Control-flow continues on regardless of any errors detected, so all users will be tested.
+ If no users have a bad name we print  "All users have good names"
+ Otherwise we print "*N* users have bad names" where N is the number of bad user-names found.

The main idea is that we can create errors from multiple places, but only a few points NEED to catch errors or do anything with them.

If nothing catches the errors, they will be printed when the app ends. Which is the desired behaviour for some shell-scripts.

Catching the errors is just done by printing or logging them or doing something with them, and then clearing stderr.

Otherwise, functions can just return nil or a valid-object to see if they succeeded or not, if you don't want to be checking `stderr.ok` all the time.

For GUI-apps, the errors can be sent to the notification-manager like this:

    for err in stderr
        notifications <~ err
    stderr.clear



