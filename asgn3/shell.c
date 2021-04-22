#include "shell.h"
#include "gaps.h"
#include "analytics.h"

#include <stdio.h>

void shell_sort(uint32_t *A, uint32_t n) {
    
    for (uint32_t i = 0; i < GAPS; i++) {

        // Skip if gap bigger than array size
        if (gaps[i] > n) {
            continue;
        }

        for (uint32_t j = gaps[i]; j < n; j++){
            uint32_t t = j; // Store j since it will be subtracted
            uint32_t temp = A[j];
            comparisons++;
            while (t >= gaps[i] && temp < A[t - gaps[i]]) {
                A[t] = A[t - gaps[i]];
                moves++;
                t -= gaps[i];
            }
            A[t] = temp;
        }
    }
}
