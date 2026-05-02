#pragma once

#include <stddef.h>
#include <stdbool.h>

// Structure to represent a Heap (Max Heap)
typedef struct Heap
{
    void *array;
    int size;
    int capacity;
} Heap;

void newHeap(Heap* heap, int capacity, void *array);
bool insertIfNotPresent(Heap *heap, void *value, size_t value_size);
