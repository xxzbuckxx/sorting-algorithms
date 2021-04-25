#include "quick.h"

#include "queue.h"
#include "stack.h"

#include <stdio.h>

int64_t partition(uint32_t *A, uint32_t lo, uint32_t hi) {
    uint32_t pivot = A[lo + ((hi - lo) / 2)];
    /* printf("%d is pivot", pivot); */
    uint32_t i = lo - 1;
    uint32_t j = hi + 1;
    while (i < j) {
        i += 1;
        while (A[i] < pivot) {
            i += 1;
        }
        j -= 1;
        while (A[j] > pivot) {
            j -= 1;
        }
        if (i < j) {
            uint32_t temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    return j;
}

void quick_sort_stack(uint32_t *A, uint32_t n) {
    int64_t lo = 0;
    int64_t hi = n - 1;
    Stack *s = stack_create(n + 2);
    stack_push(s, lo);
    stack_push(s, hi);
    while (!stack_empty(s)) {
        stack_print(s);
        stack_pop(s, &hi);
        stack_pop(s, &lo);
        int64_t p = partition(A, lo, hi);
        if (lo < p) {
            stack_push(s, lo);
            stack_push(s, p);
        }
        if (hi > p + 1) {
            stack_push(s, p + 1);
            stack_push(s, hi);
        }
    }
    return;
}

void quick_sort_queue(uint32_t *A, uint32_t n) {
    A[n - 1] = 3;
    return;
}
