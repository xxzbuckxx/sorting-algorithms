# Assignment 3 - Sorting: Putting your affairs in order

A program (sorting) that sorts an array using Bubble Sort, Shell Sort, and 2 versions of Quicksort (using a stack and using a queue). Programs were created and tested on Ubuntu 20.04.

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

* remove binaries using `make clean`
* run a memory leak test using `make leak-check`
* format code using `make format`

#### sorts.py

Python pseudocode for the sorting algorithms

#### sorting.c

This is the program that is compiled and executed

#### set.c

Set datatype implementation

#### set.h

Header file for set datatype

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

Header file defining an array containing the amount of Gaps in the Pratt sequence implementation 

#### quick.c

Quicksort implementations:
* `quick_sort_stack` for algorithm using a stack
* `quick_sort_queue` for implementation using a queue

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
* Prelab questions
* Pseudocode for the test harness
* General explanation for code implementation

#### WRITEUP.pdf

Analysis of sorting algorithm efficiency

#### HIDDEN FOLDERS

.DESIGN contains the LaTeX document for the design document

.WRITEUP contains the LaTeX document for the writeup as well as the graph jpgs
and bash scripts used to produce them
 
# Resources

* Quick sort time complexity:
    * https://www.baeldung.com/cs/quicksort-time-complexity-worst-Case
* Shell sort gaps:
    * https://www.codesdope.com/blog/article/shell-sort/
* Shell sorting visualization:
    * https://www.youtube.com/watch?v=NYWEM7H3iYc\&t=269s
* Reverse order visualizations: 
	* https://www.toptal.com/developers/sorting-algorithms/reversed-initial-order	
* Dynamic memory allocation:
    * https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
* extern:
    * https://www.journaldev.com/38985/extern-keyword-in-c
