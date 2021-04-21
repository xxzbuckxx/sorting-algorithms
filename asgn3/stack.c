#include "stack.h"

#include <stdint.h>

struct Stack {
    uint32_t top; // Index of the next empty slot.
    uint32_t capacity; // Humber of itmes that can be pushed.
    int64_t *items; // Array of items, each with type int64_t.
};

Stack *stack_create(uint32_t capacity) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    if (s) {
        s->top = 0;
        s->capacity = capacity;
        s->items = (int64_t *) calloc(capacity, sizeof(int64_t));
        if (!s->items) {
            free(s);
            s = NULL;
        }
    }
    return s;
}
