#include "bubble.h"
#include "analytics.h"

#include <stdio.h>

extern uint64_t moves;
extern uint64_t comparisons;

void bubble_sort(uint32_t *A, uint32_t n) {
    uint8_t swapped = 1; // True
    while (swapped) {
        swapped = 0; // False
        for (uint32_t i = 1; i < n; i++) {
            comparisons++;
            if (A[i] < A[i - 1]) {
                moves++;
                uint32_t temp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = temp;
                swapped = 1; // True
            }
        }
        n -= 1;
    }
}
