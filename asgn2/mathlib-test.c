#include <stdio.h>
#include <unistd.h> // For getopt()
#include "mathlib.h"

#define OPTIONS "asctl"

int main(int argc, char **argv) {
    int opt = 0;
    
    // Remember to ensure that tests do not run twice

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            printf("-a option.\n");
            break;
        case 's':
            printf("-s option.\n");
            printf("%f\n", arcSin(0.5));
            break;
        case 'c':
            printf("-c option.\n");
            break;
        case 't':
            printf("-t option.\n");
            break;
        case 'l':
            printf("-l option.\n");
            break;
        }
    }
    // printf(" %7.41f % 16.81f % 16.81f % 16.101f\n", ...);
    return 0;
}
