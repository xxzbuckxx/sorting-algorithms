#include "analytics.h"
#include "bubble.h"
#include "quick.h"
#include "shell.h"

#include <inttypes.h> // PRIu32
#include <stdint.h> // extended integer library
#include <stdio.h> // Print
#include <stdlib.h> // strtol and random
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

uint64_t moves; // tracks number of moves algorithm makes
uint64_t comparisons; // tracks number of comparisons algorithm makes
uint64_t datastruct_size; // tracks max queue/ stack size

void temp(uint32_t *A, uint32_t n) {
    A[0] = A[0];
    n++;
}

//
// updates option variable given program argument
//
// name: string for name of variable
// option: address of variable being updated
// value: string that is converted to uint32 and stored in option variable
//
void update_option(char *name, uint32_t *option, char *value) {
    uint32_t converted_value;
    if ((converted_value = strtol(value, NULL, 10)) != 0) { // strtol converts string to integer
        *option = converted_value;
    } else if (*value == '0') {
        *option = 0;
    } else {
        printf(
            "ERROR - %s is not a valid argument for %s using default (%u)\n", value, name, *option);
    }
}

//
// Main execution
//
int main(int argc, char **argv) {
    // No arguments given
    if (argc < 2) {
        printf(HELP);
    }

    // Which algorithms to run
    int run_all = 0; // False
    uint8_t execute = 0000; // [q2, q1, shell, bubble] using bit field

    // Set to defaults
    uint32_t seed = 13371453;
    uint32_t size = 100;
    uint32_t elements = 100;

    // Parse
    int opt = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        // NOTE:  using integers is kind of ugly lowkey might change
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

    if (!execute && !run_all) { // No algorithm picked
        printf("ERROR - Please pick a sorting algorithm");
        return 1;
    }

    uint32_t *arr = (uint32_t *) malloc(size * sizeof(uint32_t)); // Allocate size of array

    // Execute
    void (*functions[])(uint32_t *, uint32_t) = { bubble_sort, shell_sort, quick_sort_stack,
        quick_sort_queue }; // Array of Function pointers

    for (uint8_t i = 0; i < 4; i++) {
        if (run_all || (execute >> i & 1) == 1) {

            // Print Function Name
            // NOTE: Make function? Make array?
            switch (i) {
            case 0: printf("Bubble Sort\n"); break;
            case 1: printf("Shell Sort\n"); break;
            case 2: printf("Quick Sort (Stack)\n"); break;
            case 3: printf("Quick Sort (Queue)\n"); break;
            default: return 1; // Error
            }

            srandom(seed); // Set Random Seed

            // Fill with random values
            for (uint32_t i = 0; i < size; i++) {
                arr[i] = random();
            }

            // Tracks analytics of algorithm
            moves = 0;
            comparisons = 0;
            datastruct_size = 0;

            // Call Function
            (*functions[i])(arr, size);

            printf("%d elements, %lu moves, %lu compares\n", size, moves, comparisons);
            if (i == 2 || i == 3) {
                printf("Size: %lu\n", datastruct_size);
            }

            // Print Sorted Arary
            for (uint32_t i = 0; i < elements && i < size; i++) {
                printf("%13" PRIu32, arr[i]);
                if ((i + 1) % 5 == 0 || i + 1 == elements || i + 1 == size) { // do not print if no more elements
                    printf("\n");
                }
            }
        }
    }

    // Free memory
    free(arr);

    return 0;
}
