## Comparisons with Other Languages

Lets compare Speedie vs a few other languages. Many languages seem good when viewing simple examples, but break down once you try anything slightly significant.

Here is a good example, from Rust. We are trying to search through a list. Due to how Rust overcomplicates everything... its quite a nightmare even to look at.

What this Rust code is doing, is creating a list containing the numbers "2", "1", "3". Then we search through the list for the number "2", and replace it's number with "42". Seems easy. But why is the code so long?

All those wierd things like `box`, `mut`, `&`, `&'` make the code hard to understand. You spend most of your time fighting your way past syntax instead of just... writing code.


## Rust Comparison

#### **Rust List Search**

    struct Link<T> {
      val: T,
      next: List<T>,
    }
    
    enum List<T> {
      Empty,
      Link(Box<Link<T>>),
    }
    
    impl<T> List<T> where T: Eq {
      fn find_inner<'a>(mut list: &'a List<T>, t: T) -> Option<&'a T> {
        loop {
          let next;
          match *list {
            List::Empty => return None,
            List::Link(ref link) => {
              if t == link.val {
                return Some(&link.val)
              }
              next = &link.next;
            },
          }
          list = next;
        }
      }
      
      pub fn find_inner_mut<'a>(mut list: &mut List<T>, t: T) -> Option<&mut T> {
        loop {
          let next;
          let forcemove = list;
          match *forcemove {
            List::Empty => return None,
            List::Link(ref mut link) => {
              if t == link.val {
                return Some(&mut link.val)
              }
              next = &mut link.next;
            },
          }
          list = next;
        }
      }
    
      pub fn find<'a>(&'a self, t: T) -> Option<&'a T> {
        List::find_inner(self, t)
      }
    }
    
    fn main() {
      let mut list =
        List::Link(Box::new(Link {
          val: 3,
          next: List::Link(Box::new(Link {
            val: 1,
            next: List::Link(Box::new(Link {
              val: 2,
              next: List::Empty,
            })),
          })),
        }));
      *List::find_inner_mut(&mut list, 2).unwrap() = 42;
      println!("{:?}", list.find(2));
    }
    
Now lets look at a Speedie version!!

#### **Speedie List Search**

    // We'll just use the inbuilt list class. You would be mad not to.
    // Linked-lists are hard to get right, far more complex than the Rust example hints at.
    
    function list.FindPosition (|int| Match, |list|)
        for s in self
            if s.Position == match
                return s
    	
    main
        || L = list()
        L <~ list(3)
        L <~ list(1)
        L <~ list(2)
        || F = L.findposition(2)
            printline f
            F.Position = 42
        || F2 = L.findposition(2)
            "wierd it still exists?"
          else
            || F3 = l.FindPosition(42)
                "2 was found and altered successfully"
              else
                "where did it go?"
    		

Hooray we did it! Far simpler. Totally understandable. As a side-benefit, we also added 7 lines of helpful print-related code to show what is going on. You could strip that out as the original doesn't have that.

You should see this:

    2:()
    2 was found and altered successfully

Honestly, the difference is shocking and really shows how bad Rust can be.

The funny thing here is that Speedie is *safer* than Rust, builds faster than Rust, and the programs runs faster too! Speedie beats Rust in the things Rust is meant to be good at!

Note, this Rust code makes no mention of being "unsafe"!! Wow.

For example, if you alter the line, to replace `2` with `5`:

      // *List::find_inner_mut(&mut list, 2).unwrap() = 42;
      *List::find_inner_mut(&mut list, 5).unwrap() = 42;

You will get a crash. Yep... your "not marked as unsafe" code will crash. Cos you used `unwrap`. How terrible. (Apparantly, Rust considers crashing via `unwrap` to be "safe". 🤦‍♂️ 🤦🏽 🤦‍♀️. Well they might consider it "safe" but it didn't help find the crash bug in that Rust code did it!)

The speedie code above WON'T crash if the item can't be found! Or the same alteration is made!

    || F = L.findposition(5) // won't run this branch if "5" isn't found.
        printline f
        F.Position = 42

Guess what else? Wanna try remove that test? Sure? See what happens. You think Speedie will crash like other languages?

Nope!

    || F = L.findposition(2)
    printline f
    F.Position = 42 // ERROR! "Accessing property on optional: F"

Speedie realises that `F` might not exist. And so this code won't compile. Speedie is very intelligent around figuring out what vars can be `nil` or not. So you literally get all the safety with none of the nightmare overhead of Rust.


## C Comparison

#### **Student passcode checking Assignment**

Sometimes as a student, you are asked to do simple things, like perform some IO. Basically ask for something via stdin and print something into stdout.

Well... C is full of "gotchas". Absolutely full of them. Lets look at this C example:

    #include <stdio.h>
    #include <string.h>
    
    int main() {
        char passcode[5];
    
        for(int i = 0; i < 3; i++){
            printf("Please enter the passcode, you have %d attempts : ", (3 - i));
            fgets(passcode, sizeof(passcode), stdin);
            passcode[strlen(passcode) - 1] = '\0';
    
            if(strcmp(passcode, "1539")){
                if(i == 2){
                    printf("Wrong passcode! Your server has now been locked!\n");
                    break;
                }   
                printf("Wrong passcode!\n");
            }
            else{
                printf("Success!\n");
                break;
            }
        }
        return 0;
    }

Unfortunately, this code has a subtle bug despite the best intentions. Finding gotchas is the kind of experience that C-students have to suffer from. The code "looks right" and you really tried your best, and yet theres some simple bug hiding in here... somewhere.

In this case, the bug is that `fgets` ends its strings with "\n". Which isn't what you expected!

In addition, this code only allows for 4 byte inputs. What if the user typed in "15391" as his password? It is still wrong. But this code would accept it. To get around this, now you need more advanced memory management systems. Its not fun.

You aren't really learning to code. Just learning how to be frustrated.



#### **Speedie Student Assignment**

Lets try do the same assignment in Speedie:
        
    main
        for i in 3
            "Please enter the passcode, you have ${3-i} attempts"
            || passcode = app.input
            if passcode == "1539"
                "Success!"
                return 0
            "Wrong passcode!"
    
        "Wrong passcode! Your server has now been locked!"
        return -1

Perfect! it looks simple, it **is** simple. It works... and it looks nice. Its understandable and easy to debug.

As an added bonus, you are writing in a fast language (Speedie). So this isn't like "well I did my assignment in a slow language like python or javascript". Speedie is usually as fast as C.

Often speedie is faster than C code, because it has better libraries that look as if they were designed by people who are the elite of elites.

The fact that there are no wierd issues by including the "\n" in the string via `app.input`... helps demonstrate this.


## Go Comparison

Of all the languages, Go is one of them.

Heres an example of error-handling with files in Go:

package main

    import (
    	"errors"
    	"fmt"
    	"io"
    	"os"
    )
    
    func ReadFile(path string) ([]byte, error) {
    	if path == "" {
    		return nil, errors.New("path is empty")
    	}
    	f, err := os.Open(path)
    	if err != nil {
    		return nil, fmt.Errorf("open failed: %w", err)
    	}
    	defer f.Close()
    
    	buf, err := io.ReadAll(f)
    	if err != nil {
    		return nil, fmt.Errorf("read failed: %w", err)
    	}
    	return buf, nil
    }
    
    func main() {
    	f, err := ReadFile("file.txt")
    	if err != nil {
    		fmt.Fprintln(os.Stderr, err)
    		return
    	}
    	fmt.Println(f)
    }

Heres the same in speedie:

    function ReadFile (|string| path, |StringThatWasReadSafely|)
        expect (path) ("Path is empty")
        || f = path.file
        require f.OpenForRead   // creates an error
        return f.ReadAll(false) // also creates errors
    		
    
    main
        || f = ReadFile("file.txt")
            printline f

Its a little different, because the file functions already create errors, and we don't want **two** errors created per-operation. Also, our standard `.open` function actually **creates** files if they don't exist, so we use `f.OpenForRead` instead which expects an existing file to exist, and only uses it for reading. So now it does the same as the Go code.

Also, no need to print the error to stderr, as Speedie already does that on exit!

Or we can just this:

    main
        || f = "file.txt".ReadFile(false) // builtin function
            printline f

We can use be standard builtin `string.ReadFile` function. We pass `false` to disable ignoring of missing-files. Errors are created successfully if any happen.

Neat huh?


