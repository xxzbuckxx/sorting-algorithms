
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
