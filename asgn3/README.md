# Assignment 3 - Sorting: Putting your affairs in order

A program (sorting) that sorts an array using bubble sort, shell sort, and quick sort (using a stack and using a queue).

The program asks for two positive integers:

1. random seed
2. number of players

# How to Build

Execute the command `make` and it should compile using the provided makefile.

Run the compiled binary with `./sorting`

#### Options

* -a : Enables *all* sorting algorithms
* -b : Enables Bubble Sort
* -s : Enables Shell Sort
* -q : Enables Quicksort that utilizes a stack
* -Q : Enables Quicksort that utilizes a queue
* -r `seed` : Set the random seed to `seed` (Default is 13371453)
* -n `size` : Set the array size to `size` (Default is 100)
* -p `elements`: Print out `elements` number of elements from the array (Default is 100)

# File Explanation

#### Makefile

This makefile compiles the program.

To remove binaries use `make clean`

#### sorts.py

Python pseudocode for the sorting algorithms

#### sorting.c

This is the program that is compiled and executed. 

#### analytics.h

Global variable definitions for `moves`, `comparisons`, and `datastruct_size`

#### bubble.c

Bubble sort implementation (`bubble_sort`)

#### bubble.h

Header file defining `bubble_sort`

#### shell.c

Shell sort implementation (`shell_sort`)

#### shell.h

Header file defining `shell_sort`

#### gaps.h

Header file defining an array containing the amount of Gaps in ______ implementation as well as a ?macro? Defining the length of the array

#### quick.c

Quicksort implementations (`quick_sort_stack` for algorithm using a stack and `quick_sort_queue` for implementation using a queue)

#### stack.c

Stack datatype implementation

#### stack.h

Header file defining stack methods

#### queue.c

Queue datatype implementation

#### queue.h

Header file defining queue methods

#### DESIGN.pdf

This document details how the program was designed. This includes:

* The objective of the assignment
* What was given in the lab doc
* An explanation of data types used
* An explanation of my general approach
* Pseudocode

#### WRITEUP.pdf

Analysis of sorting algorithm efficiency
 
# Resources

* Quick sort time complexity:
    * https://www.baeldung.com/cs/quicksort-time-complexity-worst-Case
* Shell sort gaps:
    * https://www.codesdope.com/blog/article/shell-sort/
* Shell sorting visualization:
    * https://www.youtube.com/watch?v=NYWEM7H3iYc\&t=269s
* Dynamic memory allocation:
    * https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
* extern:
    * https://www.journaldev.com/38985/extern-keyword-in-c
