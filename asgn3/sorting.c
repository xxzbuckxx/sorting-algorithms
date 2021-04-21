#include <stdint.h> // extended integer library
#include <stdio.h>
#include <stdlib.h> // strtol
#include <unistd.h> // For getopt()

#define OPTIONS "absqQr:n:p:h" // Command options
#define HELP                                                                                       \
    "Select at least one sort to perform.\nSYNOPSIS\n   A collection of comparison-based sorting " \
    "algorithms.\n\nUSAGE\n   ./sorting [-habsqQo] [-n length] [-p elements] [-r "                 \
    "seed]\n\nOPTIONS\n   -h              Display program help and usage.\n   -a              "    \
    "Enable all sorts.\n   -b              Enable Bubble Sort.\n   -s              Enable Shell "  \
    "Sort.\n   -q              Enable Quick Sort (Stack).\n   -Q              Enable Quick Sort "  \
    "(Queue).\n   -n length       Specify number of array elements.\n   -p elements     Specify "  \
    "number of elements to print.\n   -r seed         Specify random seed.\n"

void update_option(char *name, uint32_t *option, char *value) {
    char *remain; // Remaining characters after converted to int
    uint32_t converted_value;
    if ((converted_value = strtol(value, &remain, 10)) != 0) {
        *option = converted_value;
    } else {
        printf(
            "ERROR - %s is not a valid argument for %s using default (%u)\n", value, name, *option);
    }
}

int main(int argc, char **argv) {
    // Which algorithms to run
    int run_all = 0; // False
    uint8_t execute = 0000; // [q2, q1, shell, bubble] using bitfield

    // Set to defaults
    uint32_t seed = 13371453;
    uint32_t size = 100;
    uint32_t elements = 100;

    // No arguments given
    if (argc < 2) {
        printf(HELP);
    }

    // Parse
    int opt = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a': run_all = 1; break; // all algorithms
        case 'b': execute = execute | 1; break; // bubble
        case 's': execute = execute | 2; break; // shell
        case 'q': execute = execute | 4; break; // q1
        case 'Q': execute = execute | 8; break; // q2
        case 'r': update_option("seed", &seed, optarg); break; // seed option
        case 'n': update_option("size", &size, optarg); break; // size option
        case 'p': update_option("elements", &elements, optarg); break; // elements option
        case 'h': printf(HELP); break; // help
        default: return 1; // Error
        }
    }

    // No algorithm picked
    if (!execute && !run_all) {
        printf("ERROR - Please pick a sorting algorithm");
        return 1;
    }

    // Execute
    char functions[4] = { 'b', 's', 'q', 'Q' }; // Array of Function pointers
    for (uint8_t i = 0; i < 4; i++) {
        if (run_all || (execute >> i & 1) == 1) {
            printf("%c command is  enabled\n", functions[i]);
            printf("seed is %d, size is %d, number of elements is %d\n", seed, size, elements);
        }
    }

    return 0;
}
