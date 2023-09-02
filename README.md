# Crafting-Interpreters
Implements a simple, half functional half object-oriented language Lox in Java.

## Language Features
### Dynamic typing
Variables can store values of any type, even functions and classes. Primitive data types include **Boolean, Numbers, Strings, Nil**

### Automatic memory management
JLox takes advantage of Java's GC system, while CLox implements its own GC algorithm.

### Arithmetic
Lox supports `+`,`-`,`*`,`/` and no more. If arithmetic operations are performed on variables with different types or variables not available for the operation, an error will occur.

### Comparison and equality
Comparison operators include `<`,`>`,`==`,`!=`,`>=`,`<=`.
Comparisons return a `Boolean` result. Comparisons between two different types will return a `false`.

### Logical operators
Logical operators include `!`,`and`,`or`. They follow short circuit rules, and return a **Boolean** value.

### Precedence and grouping
The same as C.

### Variables
- Variables can be declared using `var` keyword. For example,
```
var imAVariable = "abc"
```
- Referencing a variable is no different from that in C.
  
### Control Flow
- `if` statement
``` 
if (condition) {
    print "yes";
} else {
    print "no";
}
```

- `while` loop

```
var a = 1;
while (a < 10) {
    print a;
    a = a + 1;
}
```

- `for` loop
```
for (var a = 1; a < 10; a = a + 1) {
  print a;
}
```

- `break` statement. The same as C.
### Functions
- A function can be declared using `fun` keyword. It's important to remember that parameters have no types. For example,
```
fun printSum(a, b) {
    print a + b;
}
```
- Function call is the same as that in C.
- Functions are first class in Lox, meaning they can be passed as variables.
  
### Closures
Since function declarations are statements, you can declare local functions inside another function:
```
fun returnFunction() {
    var outside = "outside";

    fun inner() {
        print outside;
    }

    return inner;
}

var fn = returnFunction();
fn();
```
Here, `inner()` accesses a local variable declared outside of its body in the surrounding function. For that to work, `inner()` has to “hold on” to references to any surrounding variables that it uses so that they stay around even after the outer function has returned. We call functions that do this **closures**. 

### Classes
- A class can be declared using `class` keyword.
```
class Breakfast {
    cook() {
        print "Eggs a-fryin'!";
    }

    serve(who) {
        print "Enjoy your breakfast, " + who + ".";
    }
}
```
- Declaration of classes in Lox only contains methods.
- Classes are first class in Lox.
- To instantiate a class, call a class like a function and it produces a new instance of itself.
```
var breakfast = Breakfast();
```
- To initialize a class, add a `init()` method in the class declaration and it will be called automatically when the object is constructed.
```
class Breakfast {
    init(meat, bread) {
        this.meat = meat;
        this.bread = bread;
    }
```

- To add **fields** to a class, use the `.` operator.
```
breakfast.meat = "sausage";
breakfast.bread = "sourdough";
```

### Inheritance
Lox supports single inheritance by introducing `<` operator.
```
class Brunch < Breakfast {
    drink() {
        print "How about a Bloody Mary?";
    }
}
```
Only methods are inherited, not the fields.

### Standard library
There are only 2 functions in the standard library.
- `print`
- `clock()`, which returns the nuber of seconds since the program started.
