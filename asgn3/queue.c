#include "queue.h"

#include <inttypes.h> // PRIu32
#include <stdint.h> // extended integer library
#include <stdio.h> // Print
#include <stdlib.h> // Malloc

struct Queue {
    uint32_t head;
    uint32_t tail;
    uint32_t size;
    uint32_t capacity;
    int64_t *items;
};

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

void queue_delete(Queue **q) {
    if (*q && (*q)->items) {
        free((*q)->items);
        free(*q);
        *q = NULL;
    }
    return;
}

bool queue_empty(Queue *q) {
    return q->size == 0;
}

bool queue_full(Queue *q) {
    return q->size == q->capacity;
}

uint32_t queue_size(Queue *q) {
    return q->size;
}

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
