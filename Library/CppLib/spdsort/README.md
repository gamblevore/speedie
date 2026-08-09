# SpdSort

Public Domain software.

SpdSort is basically just a quicksort. It has a few advantages. Lets first look at it's speed vs C++'s sort and another publically available non-recursive stackless sort.

    Sorting 100000 ints
    
    random Cpp took 8.952ms
    random Cpp took 8.906ms
    random Cpp took 8.915ms
    random SPD took 7.780ms
    random SPD took 7.733ms
    random SPD took 7.761ms
    random NR took 9.184ms
    random NR took 9.109ms
    random NR took 9.084ms
    
    sorted Cpp took 0.408ms
    sorted Cpp took 0.408ms
    sorted Cpp took 0.407ms
    sorted SPD took 0.154ms
    sorted SPD took 0.154ms
    sorted SPD took 0.153ms
    sorted NR took 2901.668ms
    sorted NR took 2895.087ms
    sorted NR took 2916.797ms
    
    reverse Cpp took 0.707ms
    reverse Cpp took 0.708ms
    reverse Cpp took 0.692ms
    reverse SPD took 0.184ms
    reverse SPD took 0.183ms
    reverse SPD took 0.183ms
    reverse NR took 2911.658ms
    reverse NR took 2909.422ms
    reverse NR took 2921.655ms

OK, so it has good worst-case characteristics. But thats not the real reason to use it. Bascially, I had problems with C++'s sort in that it will crash your program, if you give it an invalid sort function. This is TERRIBLE. 

Imagine your roblox game or javascript game just crashes the brower, cos some kid entered a bad sort function to sort some zombies in order of how important they are. It makes no sense.

Here are some more advantages:

* Only calls the compare function once... this is important for very slow compare functions. C++ sort calls it twice per-pair of items.
* It doesn't use a garbage design for the return value. It uses an int, which can store equal, less or more. C++'s sort uses a BOOL. Which... its just not right. If you are depth-sorting some objects, it can lead to flicker as equally distant objects will flicker onscreen.




