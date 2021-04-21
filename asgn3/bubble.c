#include "bubble.h"

#include <stdio.h>

void bubble_sort(uint32_t *A, uint32_t n) {
    uint8_t swapped = 1; // True
    while (swapped) {
        swapped = 0; // False
        for (uint32_t i = 1; i < n; i++) {
            if (A[i] < A[i - 1]) {
                uint32_t temp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = temp;
                swapped = 1; // True
            }
        }
        n -= 1;
    }
}
