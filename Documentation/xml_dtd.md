## "Why use DTDs for XML? Replacing it with Speedie and Jeebox"


Instead of using a DTD tovaldiate XML, why not use Speedie to validate Jeebox? Well... I think its actually the correct choice.

Lets start with the main point, then list some side points.

**DTDs do not actually validate things very well! Too inflexible. Lets say I had a file that must have an odd number of lines. Is that possible? Nope. A silly example, but the point is, its trivial to do with code! What about dates? Or numerical-range validation? Or checking files against other files.**

As I've [said elsewhere](xml.md) all limited languages end up migrating towards being full programming languages anyhow. So you might as well start off with it.

_Computer-games end up adding scripts, databases end up adding "triggers", websites added javascript, spreadsheets added code, fixed-pipeline graphics became GLSL, make-files became programs with CMake, and [XML](https://www.researchgate.net/publication/221568016_XSLT_Version_20_Is_Turing-Complete_A_Purely_Transformation_Based_Proof) [schema](https://www.academia.edu/48721461/XSLT_Version_2_0_Is_Turing_Complete_A_Purely_Transformation_Based_Proof) is turing complete!_

But there are additional drawbacks! To DTD/Schemas:

(_Text is copied from various websites, then re-worded shorter/clearer._) 

* DTD while simpler and less controversial than Schemas, is relatively unpowerful.
* Schemas are widely disliked due to over-complexity and bloat.
* XML must be processed using special purpose tools and languages such as XSLT/Schema. Just to use XML, developers must become domain experts in a complex space that is unrelated to the original program.
* DTDs and Schemas are bad user interfaces. With a user form, an entire document being valid or not, is too inflexible for a good user experience. The  user wants friendly and helpful feedback on multiple fields. You don't get that with DTD/Schema.
* DTDs aim to help communication between separate software teams. However, they are difficult to read and change, and end up slowing everyone down. For programmers writing the actual end-program using the XML, sample documents are usually best because there is no conceptual leap between what an XML sample looks like and what the XML in question looks like.
* DTDs can validate documents as good or bad... but cant describe a document's entire intricacies. Manual software validation is needed (eg: checking an order number against a database). After doing this, you've now created two validation code-bases. Each risking getting out outdated or having separate bugs.
* Nearly all forms of XML validation are harmful... DTDs usually restrict rather than permit. Newer XML gets rejected by older DTDs. The most practical place to check data is the code that actually processes the data.
* DTDs contain strange things like "file entities" containing actual XML elements. An XML document can't be processed without them. But those entities can come from URLs, meaning your document can't be understood without a network connection. It is very common for badly-written XML software to download a file EVERYTIME a xml validated, which could be hundreds or thousands of times per-day per-computer. w3 themselves have this issue.
* XML Schema is not enough for simple validation often. For example attributes in parent nodes, could exclude some attributes in child nodes, depending on our needs.
* Because of unhappyness with DTD/Schema, new alternatives like RelaxNG are created. Further fragmenting the XML Scene. Why wasn't one language good enough forever? (Like Speedie is good enough to validate jeebox)

### XML wastes money and bandwidth!

(Originally written on W3.org)

>*"URIs are used for identification. This is a machine-readable way to say "this is HTML". In particular, software does not usually need to fetch these resources, and certainly does not need to fetch the same one over and over! Yet we receive a surprisingly large number of requests for such resources: up to 130 million requests per day, with periods of sustained bandwidth usage of 350Mbps, for resources that haven't changed in years.*
>
>*A while ago we put a system in place to monitor our servers for abusive request patterns and send 503 Service Unavailable responses with custom text depending on the nature of the abuse. Our hope was that the authors of misbehaving software and the administrators of sites who deployed it would notice these errors and make the necessary fixes to the software responsible.*
> 
>*Judging from the response to our 503 errors, much of the software requesting DTDs and schemata from our site doesn't even need them in the first place, so requesting them just wastes bandwidth and slows down the application. If you don't need it, don't fetch it!*


Well... thats an awful state of affairs. However, its quite predictable: XML is complicated, external entities exist in DTD, XML relies on DTD, and people use libraries to handle the XML stuff... and the libs "just want to do the correct thing" and not worry about efficiencies. Too many different groups of people making decisions that do not work together.


### Back to the Main Point

Finally... lets get back to the main point. Why not just replace XML with Jeebox, and DTDs with Speedie.

There are two approaches to validating Jeebox input:

#### 1) Use The Message class.

Use the functions on the `message` class. This runs the fastest. And mostly "happens for free" if you were processing it anyhow. (Some extra checks for trailing data might be needed.)
 
However its easy to forget to add all the checks. And despite it being "free" its free within a verbose form.

Also, it relies on the actual app that does the processing, which might be large despite the format itself being simple.


#### 2) Use A Dedicated Validator

This is more like it. Now we have something resembling an XML DTD. But how to do it? Well... I wrote a validation class just for this purpose, to make it easy to write validator scripts.

You can see the validator class here: [Validator class](../jeebox.scproj/jeebox.input/Validator.spd)

You might be thinking "Thats all? 100 lines of code?"

Well... yeah. thats the point. To make the thing simple. Using this, we can make very simple validation code! Theres an example here: [tv.val.spd](../Examples/xml_dtd/tv.val.spd)

This way, you don't need to learn an entire new language just to validate your data, like you do with XML/DTD. You just keep using your knowledge of Speedie.


### Porting XML/DTD to Jeebox/Speedie

Heres a simple example



    <addressBook>
      <card>
        <givenName>John</givenName>
        <familyName>Smith</familyName>
        <email>js@example.com</email>
      </card>
      <card>
        <name>Fred Bloggs</name>
        <email>fb@example.net</email>
      </card>
    </addressBook>

    ...

    <!DOCTYPE addressBook [
    <!ELEMENT addressBook (card*)>
    <!ELEMENT card ((name | (givenName, familyName)), email, note?)>
    <!ELEMENT name (#PCDATA)>
    <!ELEMENT email (#PCDATA)>
    <!ELEMENT givenName (#PCDATA)>
    <!ELEMENT familyName (#PCDATA)>
    <!ELEMENT note (#PCDATA)>
    ]>

Here, the intention is that the name could be the full name, or broken down into first and last name. Lets try this in speedie:

    addressBook
    	card
    		givenName "John"
    		familyName "Smith"
    		email "js@example.com"
    	card 
    		name "Fred Bloggs"
    		email "fb@example.net"

Now lets validate it.


	main (|message| AddressBook)
		|| AB = AddressBook.Validate(@tmp, "addressBook")
		for Card in AB.arg.All("card")
			|| arg = card.arg.end       #loop
			if !arg.allow("name").str
				arg["givenName"].str
				arg["familyName"].str
			arg["email"].str
			arg.allow("note").str
			arg.ChildEnd // remove this line if you want
        

Honestly, it doesn't look so much more complex than the DTD is. And you don't need to learn a new language to do it. This validator is just as strict as the DTD. And run faster. Its also "embeddable" within a speedie program! After all, its just code. This makes things even smaller faster and ligher. I could add more syntactic sugar to make it smaller even, but I think its tight enough for now.

Lets say we want our validator to do a little more. Actually print output. We can do that! Why not?

    main (|message| AddressBook)
        || AB = AddressBook.Validate(@tmp, "addressBook")
        for Card in AB.arg.All("card")
            || arg = card.arg.end       #loop
            || name = arg.allow("name").str
                printline name.name
              else
                || F = arg["givenName"].str
                || L = arg["familyName"].str
                if F and L
                    printline F.name + " " + L.name
            arg["email"].str
            arg.allow("note").str
            arg.ChildEnd // remove this line if you want
    		
Getting back to one of the points earlier about how DTDs are used to reject, rather than allow. Well... we are doing that here too. But we can make this extensible, by removing one statement! Delete the `arg.ChildEnd` line. Now your document can have extra fields added. They will be ignored by this version of the validator, but future validators could do extra checks on them.

An interesting thing, is that you can actually make self-validating documents. Try doing that in XML! Using the unix "shebang" (`#!`) feature, at the start of a document, makes it executable. We'll probably have to sort out some security issues around that first, but if you are in a trusted environment, running your own programs, its just fine.
    
    #!/usr/local/validators/addressbook.spd
    addressBook
    	card
    		givenName "John"
    		familyName "Smith"
    		email "js@example.com"
    	card 
    		name "Fred Bloggs"
    		email "fb@example.net"


