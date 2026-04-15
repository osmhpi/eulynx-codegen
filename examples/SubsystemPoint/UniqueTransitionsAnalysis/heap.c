#include "heap.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Function to create a heap
void newHeap(Heap* heap, int capacity, void *array)
{
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = array;
}

// Function to swap two entries
void swap(void *a, void *b, size_t size)
{
    char temp[size];
    for (int i = 0; i < size; i++) {
        temp[i] = ((char *)a)[i];
        ((char *)a)[i] = ((char *)b)[i];
        ((char *)b)[i] = temp[i];
    }
}

// Function to heapify the node at index i
void heapify(Heap *heap, int i, size_t size)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && memcmp((char *)heap->array + left * size, (char *)heap->array + largest * size, size) > 0)
        largest = left;

    if (right < heap->size && memcmp((char *)heap->array + right * size, (char *)heap->array + largest * size, size) > 0)
        largest = right;

    if (largest != i)
    {
        swap((char *)heap->array + i * size, (char *)heap->array + largest * size, size);
        heapify(heap, largest, size);
    }
}

// Function to insert a new value into the heap
void insertHeap(Heap *heap, void* value, size_t size)
{
    if (heap->size == heap->capacity)
    {
      assert(false); // Heap is full, cannot insert new value
    }

    heap->size++;
    int i = heap->size - 1;
    memcpy((char *)heap->array + i * size, value, size);

    // Fix the heap property if it is violated
    while (i != 0 && memcmp((char *)heap->array + ((i - 1) / 2) * size, (char *)heap->array + i * size, size) < 0)
    {
        swap((char *)heap->array + i * size, (char *)heap->array + ((i - 1) / 2) * size, size);
        i = (i - 1) / 2;
    }
}

bool valueExists(Heap *heap, int i, void *value, size_t size) {
    int comparison = memcmp((char *)heap->array + i * size, value, size);
    if (comparison == 0) {
        return true;
    } else if (comparison < 0) {
        // Since it's a max heap, if the current value is less than the target value,
        // we can stop searching this branch.
        return false;
    }

    // Search both left and right children
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    bool foundInLeft = (left < heap->size) ? valueExists(heap, left, value, size) : false;
    bool foundInRight = (right < heap->size) ? valueExists(heap, right, value, size) : false;
    return foundInLeft || foundInRight;
}

bool insertIfNotPresent(Heap *heap, void *value, size_t value_size) {
    if (valueExists(heap, 0, value, value_size)) {
        return false; // Value already exists in the heap
    }

    insertHeap(heap, value, value_size);
    return true; // Value inserted successfully
}
