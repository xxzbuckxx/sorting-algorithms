#include "shell.h"

#include "analytics.h"
#include "gaps.h"

//
// sorts an array using shell sort with a Pratt sequence
//
// A: array to sort
// n: length of array to sort
//
void shell_sort(uint32_t *A, uint32_t n) {
    for (uint32_t i = 0; i < GAPS; i++) { // iterate through gaps array indicies

        // Skip if gap bigger than array size
        if (gaps[i] > n) {
            continue;
        }

        for (uint32_t j = gaps[i]; j < n; j++) {
            uint32_t t = j; // Store j since it will be subtracted
            uint32_t temp = A[j];
            moves++;
            if (t >= gaps[i]) {
                comparisons++;
            }
            while (t >= gaps[i] && temp < A[t - gaps[i]]) {
                comparisons++;
                A[t] = A[t - gaps[i]]; // Insert value
                moves++;
                t -= gaps[i];
            }
            A[t] = temp;
            moves++;
        }
    }
}
