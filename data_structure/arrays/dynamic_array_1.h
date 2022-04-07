#ifndef dynamic_array_1_h
#define dynamic_array_1_h

#include <stdlib.h>

typedef struct
{
    size_t itemSize;     // size of single item in array.
    size_t capacity;     // the capacity, how much room until resize is needed.
    size_t logicalSize;  // The actual number of items, this is always <= capacity.
    void *internalArray; // The internal memory buffer that holds the items.
} dynamic_array;

// return a pointer of a dynamic array
dynamic_array *DynamicArrayCreate(size_t itemSize);

void DynamicArrayGet(dynamic_array *dynamicArray, size_t index, void *output);

void DynamicArraySet(dynamic_array *dynamicArray, size_t index, const void *input);

void DynamicArrayAppend(dynamic_array *dynamicArray, const void *input);

void DynamicArrayDispose(dynamic_array *dynamicArray);

#endif /* DynamicArray_h */
