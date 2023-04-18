## Flow Control

FlowControl is my name for a new system I am working on right now.

FlowControl will be one of the biggest things to improve Speedie and set it apart from other languages!

FlowControl is a log of the flow-control decisions your app has made. It records the path that your program has taken, and saves it to disk. This doesn't sound like much, but it is huge, actually. Huge.

FlowControl allows many advanced features to become possible. 

Mainly, this is by comparing two logs of FlowControl, to see where they differ! Very powerful.

##Debugging Programs On Other Computers

So lets say you run your program on another computer, that you have no debugger available for. And the program is failing, but you can't tell why, because all you have is the compiled source and an error message. But like most errors, the cause of the error is far away from the point that it is generated.

With FlowControl, you can find the exact line where the program is acting differently from the expected behaviour on your computer.

## Porting Programs To Other Platforms

This is the same as above. Lets say you have your program working locally, but you wanna compile it for some strange platform that Speedie hasn't been tested on. With FlowControl... you can find the exact line where your program is acting differently!

## Stepping Backwards In Time

With FlowControl, we should be able to "step backwards in time" to figure out where a bug originated from.

Stepping backwards in time requires a few other systems added to Speedie, but FlowControl is one of the systems needed!

Basically, if we are gonna "re-run" our test-code to a slightly earlier point... we'll need to know that the test-code was doing the same thing, or else its no point re-running it! So its vital for stepping backwards.

## Updating, Swapping or Upgrading Libraries

So lets say you have some code... lets say it's a network browser or something. You just wanna list the servers on the network.

So you are using an HTTP library to get the list, then you "massage" the list-data into it's desired form and display it.

Now lets say, you want to swap this HTTP Library for another that does the same thing. In fact, lets say ***you*** are writing a lib that you want to behave the same as **their lib**.

Same input, same output, its just faster and less buggy.

Using FlowControl, you can log the behaviour of your app that uses the lib, so that you'll be sure its doing the same things. This lets you design your lib properly.

## Making Sure The VM Runs Properly

I am going to use FlowControl for the Speedie VM. This is to ensure that my C++ generated code, and the VM... behave the same way. This will make a good match, ensuring that your code behaves the same, regardless of VM or C++.

**Very** Important! It will totally squash any bugs allowing them to instantly be found :) It will be awesome!



## Summary

FlowControl should be awesome when done.