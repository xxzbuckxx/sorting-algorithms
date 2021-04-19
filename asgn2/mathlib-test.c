#include "mathlib.h" // My Library Functions

#include <math.h>
#include <stdio.h>
#include <unistd.h> // For getopt()

#define OPTIONS "asctl" // Command options

//
// Prints tests on given interval
//
// operation: this library
// library: standard library
// name: name of function (string)
// start: start of iteration
//
static void tests(
    double (*operation)(), double (*library)(), char name[], double start, double end) {
    printf("  x\t\t  %s\t   lib       \tdifference\n", name);
    printf("  -\t\t  ------\t   ----------\t---------\n");
    for (double x = start; x < end; x += 0.1) {
        double my_imp = operation(x);
        double lib_imp = library(x);
        double difference = my_imp - lib_imp;
        printf(" %7.4f % 16.5f % 16.5f % 16.15f\n", x, my_imp, lib_imp, difference);
    }
}

//
// Test Harness
//
int main(int argc, char **argv) {
    int opt = 0;

    // If not argument given
    if (argc < 2) {
        printf("Please enter an option: -asctl\n");
    }

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            tests(arcSin, asin, "arcSin", -1, 1);
            tests(arcCos, acos, "arcCos", -1, 1);
            tests(arcTan, atan, "arcTan", -1, 10);
            tests(Log, log, "Log   ", 1, 10);
            return 0; // Stops from executing other options
        case 's': tests(arcSin, asin, "arcSin", -1, 1); break;
        case 'c': tests(arcCos, acos, "arcCos", -1, 1); break;
        case 't': tests(arcTan, atan, "arcTan", 1, 10); break;
        case 'l': tests(Log, log, "Log   ", 1, 10); break;
        }
    }

    return 0;
}
