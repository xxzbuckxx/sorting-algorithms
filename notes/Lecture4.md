# Lecture 4

#### Where does C come from?

* Derived from B, written by Ken Thompson
* Timeline:
	* 1972 birth
	* 1978 K&R C
	* 1989 ANSI C
	* 1999 C99
	* 2011 C11
	* 2018 C18

## Explaining some C
```C

#include <stdio.h>

int mian(void) {
	printf("Hello, world!\n");
	return 0;
}
```

* C has no I/O built in (need to use a library)
* U can use include wherever you want but it should be at the top
* Loader calls a function called main (that's how things are)
	* Can call main recursively if u want (DONT) 
* should use the default when returning from main (do not monkey with it) 
	* 0 is success 
* Need to use a . to call current file or else it will check path

## Temperature converter

* Lectures example straight from C textbook
	* Basically you can cast
		* (i.e. (double) 0) 
	* Precision is important so can't just use ints when things do not divide equally 
	* If you use a constant in a calculation (like (5.0 / 9.0)) most compilers will store this constant and not calculate it every time
		* In the realm of compiler optimization 

## More stuff

* C is a curly brace language
	* Used for grouping statements
	* Creates a block
		* Can declare variables 
		* Creates scope

*top-test loop* --> execute 0 or more times

* while 1 and while true are synonymous but using while True is more conventional

*%* --> escape character

* You can initialize inside the loop
	* `for (int fahr = 0; fahr <= 300; fahr += 20) {`
	* Do this because it keeps the scope small and stops a lot of possible bugs

*Declaring* --> specifying variables type (in C)

## Scope

```C
{
	float x = 1.414;
	{
		float y = 1.0 - x;
	}
	{
		int x = 1962;  // This x and this y only exist here and do not overwrite y and x
		int y = 1962 - 1967; 
	}
}
```

#### Scoping Rules

* {} creates a new scope
* can create new local variables in a scope
	* variables can have any type and any legal name 
	* If they have the same name as a variable in an outer scope, then they hide that variable.
* used to group statements
* called a block
* A block introduces a local scope

## I/O

* a character is just an 8 bit integer

## Summary

* C provides one of the most basic sets of statements and operators
* relatively low level
* You can write unreadable programs
* C is powerful but can be dangerous

## Loops

* vast amount of time is spent inside loops
* we will focus on structured loops
	* Do not use goto (lets you cross loops) 
	* while, for, and do-while  

#### When can I use goto?

* should almost NEVER
* for non-local error handling
	* when you are in a bunch of nested stuff and you need to get out 

