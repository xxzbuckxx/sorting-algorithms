#include "queue.h"

#include <inttypes.h> // PRIu32
#include <stdint.h> // extended integer library
#include <stdio.h> // Print
#include <stdlib.h> // Malloc

// Code adapted from stack.c which is taken from Professor Darrell Long and teaching assistant Eugene

//
// Structure for defining queue data struture
//
struct Queue {
    uint32_t head; // new values at head
    uint32_t tail; // next item to pop at tail
    uint32_t size; // current size
    uint32_t capacity; // max size
    int64_t *items; // array of items
};

//
// Creates a queue
//
// capacity: max size of the queue
//
Queue *queue_create(uint32_t capacity) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    if (q) {
        q->head = 0;
        q->tail = 0;
        q->size = 0;
        q->capacity = capacity;
        q->items = (int64_t *) calloc(capacity, sizeof(int64_t));
        if (!q->items) {
            free(q);
            q = NULL;
        }
    }
    return q;
}

//
// Deletes a queue
//
// s: a queue to delete
//
void queue_delete(Queue **q) {
    if (*q && (*q)->items) {
        free((*q)->items);
        free(*q);
        *q = NULL;
    }
    return;
}

//
// Returns if queue is empty or not
//
// s: a queue to check
//
bool queue_empty(Queue *q) {
    return q->size == 0;
}

//
// Returns if queue is full or not
//
// s: queue to test
//
bool queue_full(Queue *q) {
    return q->size == q->capacity;
}

//
// Returns size of the queue
//
// s: the queue to return the size of
//
uint32_t queue_size(Queue *q) {
    return q->size;
}

//
// Adds the given item to the bottom of the queue and returns if successful
//
// s: queue to push item to
// x: item to add to queue
//
bool enqueue(Queue *q, int64_t x) {
    if (queue_full(q)) {
        return false;
    }
    q->items[q->head] = x;
    if (q->head == q->capacity - 1) {
        q->head = 0;
    } else {
        q->head++;
    }
    q->size++;
    return true;
}

//
// Removes first item on the queue and stores returns the
//
// s: the queue to pop from
// x: the address to store the popped value
//
bool dequeue(Queue *q, int64_t *x) {
    if (queue_empty(q)) {
        return false;
    }
    *x = q->items[q->tail];
    if (q->tail == q->capacity - 1) {
        q->tail = 0;
    } else {
        q->tail++;
    }
    q->size--;
    return true;
}

//
// Prints elements of the queue
//
// s: the queue to print
//
void queue_print(Queue *q) {
    printf("[");
    uint32_t j = 0;
    for (uint32_t i = q->tail; j < q->size; i++, j++) {
        if (i == q->capacity) {
            i = 0;
        }
        printf("AT %d:", i);
        printf("%" PRId64, q->items[i]);
        if (j + 1 != q->size) {
            printf(", ");
        }
    }
    printf("]\n");
}
