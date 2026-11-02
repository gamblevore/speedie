
## Speed Comparison #2 - Goose

So... a new language `Goose` has arrived. And... it has some really strong speed claims, and some very impressive results. I tested it's code, looked at the docs... It is an impressive show-piece.

However it is vibe-coded, and comes with major limitations.

It pre-allocates (often) gigantic (multi-gigabyte) blocks of data, a few of them, depending on how many arrays or other variable-sized things your program has.

So then no dynamic memory management is needed, your program can just increment/decrement its pointers, depending on how many arrays you have. Now, if you have 100,000s of dynamic arrays in your program... thats... going to be an issue. 

Goose also relies on the VirtualMemory system to handle everything for you, so "not too much memory is actually used".

It does a lot more clever things, but its main tricks are "just increment/decrement a pointer for allocating... and we do that for EVERYTHING... ALL our arrays".

Goose also doesn't let you use function-pointers... or virtual-functions, which kind of defeats the entire purpose of programming. Speedie itself uses function-pointers heavily, due to how powerful they are.

So while Goose's approach is impressive, its not... generally useful. Its a show-case. Also, a lot of it's bench-marks are not very generally applicable. Who really has an array of 10,000,000 integers that needs summing, after randomly filling them up?? I mean thats not really how most data is.

So I compared Speedie vs a more realistic part of Goose, their string splitting example.

Here is the modified goose string splitting code:

    import rng;
    import std;
    import os;
    
    let N = 400000;                          // BENCH_N
    let PASSES = 160;
    
    fn main() {
        // One text buffer of space-separated random words.
        var text: u8[>..] = [];
        if (read_file("goose.txt", text)) {
           // print("reading text");
        } else {
            var r: u64 = 12345;
            for i in N {
                r = xs_next(r);
                let wl = 3 + xs_mod(r, 18);
                for j in wl {
                    r = xs_next(r);
                    text.push(('a' + xs_mod(r, 26)) as! u8);
                }
                text.push(' ');
            }
            if (!write_file("goose.txt", text)) {
                print( "cannot read file " );
            }
        }
        
        var words: u8[][>..] = [];
        each_split(text, ' ') { if it.len > 0 { words.push(it); } };
        var total = 0;
        for p in PASSES {
            for w in words { total += w.len + w[0] + w[w.len - 1]; }
        }
        print(words.len);
        print(total);
    }

And the speedie version:

    || N = 400000
    || PASSES = 160
    
    main
        || text = "~/Downloads/goose.txt".ReadAll
        |[string]| words
        text.Split(' ', true, words)
        || total = 0
        for p in PASSES
            for w in words { total += w.length + w[0] + w[-1] }
        printline words.Length
        printline total

Speedie's is smaller, because it does not generate the text-file. The code-size is about the same for both, although I think Speedie is more readable.

Here are my bench-marks:

    time strlist.spd
    
    400000
    14750069280
    strlist.spd  0.28s user 0.01s system 98% cpu 0.304 total


    time ~/Downloads/goose/build/goose strlist.goose
    400000
    14750069280
    ~/Downloads/goose/build/goose   0.55s user 0.01s system 99% cpu 0.572 total
    
Conclusion:

Speedie is 2x faster than Goose! And Goose was billed at 3.51x faster than C++, making speedie 7x faster than C++.

The file I tested, strlist.goose happened to run at 3.52x faster than C++, so, it was near dead-average for Goose's test-batch.

I think its important to not get overweighed by blazing headlines, in the era of vibe-coded programs. (Goose was vibe-coded using Claude.)

Clever but not so well-thought-through ideas, can end up gaining too much traction, hiding the results of hand-coded and wonderfully designed systems.

(Code is available at [`Comparisons/strlist.goose`](Comparisons/strlist.goose) and [`Comparisons/strlist.spd`](Comparisons/strlist.spd) if you have downloaded speedie.)


