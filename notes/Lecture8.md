# Functions

#### Words of Caution

* Not the same as functions in high school
* In C:
	* Functions are groups of code that have a name
	* may or may not return a value
	* Side effect --> alter a variable that is outside the function
* usually a function if it returns a value, and a procedure or subroutine if it doesn't (not in C tho) 
* functions can be defined exactly once
* define abstractions that are consistent and make sense logically 
* Point of class:
	* make good abstractions/ make good api

* C you cannot return an array
* but can return a struct with an array inside (do not do)
* no nested functions in C
* most programming languages use either call-by-value or call-by reference
	* C uses call-by-value (make a copy) 
	* however u can accomplish call-by-reference by using pointers

* C has a preprocessors
	* it is a macro preprocessors
	* it takes anything with a # sign
	* it takes what is in the include file and literally pastes it

## Conditional Directives

```c
#define MACRO
#ifdef MACRO
	controlled text
#endif
```
## Header files should only contain

* function declarations
* macro definitions
* data structure and enumeration definitions
* global variables
* any #include directives required to compile

#### Some Standard Header Files

* stdio.h for input/output
* inttypes.h for fixed with ints
* time.h for date/time utilties
* stdbool.h for booleans

## Extern

* functions are implicitly prepended by extern
* extern variables are declared outside functions
* makes global variables

## Static

* declaring static inside a function means the value persists and only stays within function

## Recursion

Can be done in C
