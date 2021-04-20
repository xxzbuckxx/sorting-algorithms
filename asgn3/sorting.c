#include <stdio.h>

int  main() {
    // Default print
    printf("Select at least one sort to perform.\nSYNOPSIS\n   A collection of comparison-based sorting algorithms.\n\nUSAGE\n   ./sorting [-habsqQo] [-n length] [-p elements] [-r seed]\n\nOPTIONS\n   -h              Display program help and usage.\n   -a              Enable all sorts.\n   -b              Enable Bubble Sort.\n   -s              Enable Shell Sort.\n   -q              Enable Quick Sort (Stack).\n   -Q              Enable Quick Sort (Queue).\n   -n length       Specify number of array elements.\n   -p elements     Specify number of elements to print.\n   -r seed         Specify random seed.\n   -o              Use sorted arrays.");
    return 0;
}
