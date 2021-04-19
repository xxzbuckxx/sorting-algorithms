
# Assignment 2 - Small Numerical Library

Test harness and implementation for arcsin, arcos, arctan, log

The program asks for operation as:
	-s for arcsin
	-c for arcos
	... etc

# How to Build

Execute the command `make` and it should compile using the provided makefile.

Run the compiled binary with `./mathlib-test -<option>`

# File Explanation

#### mathlib.c

This is the math library.

#### Makefile

This makefile compiles the program.

To remove binaries use `make clean`

#### mathlib.h

This contains the function definitions for the math library.

#### DESIGN.pdf

This document details how the program was designed. This includes:

* The objective of the assignment
* What was given in the lab doc
* An explanation of data types used
* An explanation of my general approach
* Pseudocode

#### WRITEUP.pdf

An explanation on the difference between my implementation and the standard library.

#### Mistakes

There are definitely some errors with my code. Here are the big ones:

1. test harness does not parse input (-tsa results in arctan and arcsin repeated)
2. I fixed a sign error in arcCos by using a ternary operator instead of fixing the math
3. First value of Log is negative for some reason

#### Resources

* [Passing Function pointers as parameters to functions](https://codeforwin.org/2017/12/pass-function-pointer-as-parameter-another-function-c.html#:~:text=In%20C%20programming%20you%20can,another%20function%20using%20function%20pointers)
