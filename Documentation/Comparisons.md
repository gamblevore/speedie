## Comparisons with Other Languages

Lets compare Speedie vs a few other languages. Many languages seem good when viewing simple examples, but break down once you try anything slightly significant.

Here is a good example, from Rust. We are trying to search through a list. Due to how Rust overcomplicates everything... its quite a nightmare even to look at.

What this Rust code is doing, is creating a list containing the numbers "2", "1", "3". Then we search through the list for the number "2", and replace it's number with "42". Seems easy. But why is the code so long?

All those wierd things like `box`, `mut`, `&`, `&'` make the code hard to understand. You spend most of your time fighting your way past syntax instead of just... writing code.


#### Rust List Search

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

#### Speedie List Search

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
    		

Hooray we did it! Far simpler. Totally understandable. As a side-benefit, we also added 7 lines of helpful print-related statements code to show what is going on. You could strip that out as the original doesn't have that.

You should see this:

    2:()
    2 was found and altered successfully

Honestly, the difference is shocking and really shows how bad Rust can be.

The funny thing here is that Speedie is *safer* than Rust, builds faster than Rust, and the programs runs faster too! Speedie beats Rust in the things Rust is meant to be good at!

Note, this Rust code makes no mention of being "unsafe"!! Wow.

For example, if you alter the line, to replace `2` with `5`:

      // *List::find_inner_mut(&mut list, 2).unwrap() = 42;
      *List::find_inner_mut(&mut list, 5).unwrap() = 42;

You will get a crash. Yep... your "not marked as unsafe" code will crash. Cos you used `unwrap`. How terrible.

The speedie code above WON'T crash if the item can't be found! Or the same alteration is made!

    || F = L.findposition(2) // gets a var and then does an 'if' block on it
        printline f
        F.Position = 42

Guess what else? Wanna try remove that test? Sure? See what happens. You think Speedie will crash like other languages?

Nope!

    || F = L.findposition(2)
    printline f
    F.Position = 42 // ERROR! "Accessing property on optional: F"

Speedie realises that `F` might not exist. And so this code won't compile. Speedie is very intelligent around figuring out what vars can be `nil` or not. So you literally get all the safety with none of the nightmare overhead of Rust.

I hope that helps understand how much better the design of Speedie is.

