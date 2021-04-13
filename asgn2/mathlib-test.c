#include "mathlib.h"

#include <math.h>
#include <stdio.h>
#include <unistd.h> // For getopt()

#define OPTIONS "asctl"

static void tests(double (*operation)(), double (*library)()) {

    printf("    x\t\t   myfunc\thomie func        difference\n");
    printf("    -\t\t   ------\t----------        ---------\n");
    for (double x = -1; x < 1; x += 0.1) {
        double my_imp = operation(x);
        double lib_imp = library(x);
        double difference = my_imp - lib_imp;
        printf(" %7.4f % 16.5f % 16.5f % 16.10f\n", x, my_imp, lib_imp, difference);
        /* printf(" %7.41f % 16.81f % 16.81f % 16.101f\n", x, my_imp, lib_imp, difference); */
    }
}

int main(int argc, char **argv) {
    int opt = 0;

    // Remember to ensure that tests do not run twice

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a': tests(arcSin, asin); break;
        case 's': tests(arcSin, asin); break;
        case 'c': tests(arcCos, acos); break;
        case 't': tests(arcTan, atan); break;
        case 'l': tests(Log, log); break;
        }
    }
    return 0;
}