#include "quick.h"

#include "analytics.h"
#include "queue.h"
#include "stack.h"

//
// Sorts items by creating a partition (index lo to index hi of a given array)
// Sorts  by putting smaller values to the left of the pivot value and higher
// values to the right. The pivot value is the middle of the partition.
//
// A: array to sort
// lo: index of lower bound of partition
// hi: index of higher bound of partition
//
int64_t partition(uint32_t *A, uint32_t lo, uint32_t hi) {
    uint32_t pivot = A[lo + ((hi - lo) / 2)]; // pivot around middle of partition
    int32_t i = lo - 1;
    int32_t j = hi + 1;
    while (i < j) { // while there are indices that have not been moved
        i += 1;
        comparisons++;
        while (A[i] < pivot) { // items smaller than pivot value
            comparisons++;
            i += 1;
        }
        j -= 1;
        comparisons++;
        while (A[j] > pivot) { // items bigger than pivot value
            comparisons++;
            j -= 1;
        }
        if (i < j) {
            uint32_t temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            moves += 3;
        }
    }
    return j;
}

//
// Quick sort that uses a partition to sort and a stack to track the partition indices (lo and hi).
//
// A: array to partition and sort
// n: length of array to sort
//
void quick_sort_stack(uint32_t *A, uint32_t n) {
    int64_t lo = 0;
    int64_t hi = n - 1;
    Stack *s = stack_create(n + 2);
    stack_push(s, lo); // store where to partition
    stack_push(s, hi); // store where to partition
    datastruct_size = stack_size(s) > datastruct_size ? stack_size(s) : datastruct_size;
    while (!stack_empty(s)) {
        stack_pop(s, &hi); // get where to partition
        stack_pop(s, &lo); // get where to partition

        int64_t p = partition(A, lo, hi);
        if (lo < p) {
            stack_push(s, lo); // store where to partition
            stack_push(s, p); // store where to partition
            datastruct_size = stack_size(s) > datastruct_size ? stack_size(s) : datastruct_size;
        }
        if (hi > p + 1) {
            stack_push(s, p + 1); // store where to partition
            stack_push(s, hi); // store where to partition
            datastruct_size = stack_size(s) > datastruct_size ? stack_size(s) : datastruct_size;
        }
    }
    return;
}

//
// Quick sort that uses a partition to sort and a queue to track the partition indicies (lo and hi).
//
// A: array to sort
// n: length of array to sort
//
void quick_sort_queue(uint32_t *A, uint32_t n) {
    int64_t lo = 0;
    int64_t hi = n - 1;
    Queue *q = queue_create(n + 2);
    enqueue(q, lo); // store where to partition
    enqueue(q, hi); // store where to partition
    datastruct_size = queue_size(q) > datastruct_size ? queue_size(q) : datastruct_size;
    while (!queue_empty(q)) {
        dequeue(q, &lo); // get where to partition
        dequeue(q, &hi); // get where to partition
        uint32_t p = partition(A, lo, hi);
        if (lo < p) {
            enqueue(q, lo); // store where to partition
            enqueue(q, p); // store where to partition
    datastruct_size = queue_size(q) > datastruct_size ? queue_size(q) : datastruct_size;
        }
        if (hi > p + 1) {
            enqueue(q, p + 1); // store where to partition
            enqueue(q, hi); // store where to partition
    datastruct_size = queue_size(q) > datastruct_size ? queue_size(q) : datastruct_size;
        }
    }
    return;
}
