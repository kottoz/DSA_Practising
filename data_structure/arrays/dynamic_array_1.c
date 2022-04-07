/*

General Points
- A vector is a sequential based container.
- The dynamic array is able to change its size(grow and shrink) during program execution(run time).
- Dynamic arrays are typically initialized with twice the number of initial array elements. This extra space is what allows extra elements to be added to the array. So, if I wanted to make a dynamic array with the following elements, [1, 2], a dynamic array would be created with 4 spaces. This size is maintained until we've added enough elements to fill it. If we tried to add a 5th element, the array would double in size (now with a capacity of 8) and add the 5th element.
- When the array needs to double in size, the original array is first copied. Then the program finds a new, larger contiguous area of memory. It then creates a new, doubly large array in that contiguous space, and saves the original array as the first half of the new array.

Usage
- if you don't know how much data will enter the array at any given point.

*/

#include "dynamic_array_1.h"
#include <assert.h>                     // used to verify assumptions made by the program and print a diagnostic message if this assumption is false.
#include <string.h>                      
#include <stdio.h>                      

const size_t kInitialCapacity = 10;
const float kGrowthFactor = 1.5;

dynamic_array *DynamicArrayCreate(size_t itemSize) {
    dynamic_array *dynamicArray = malloc(sizeof(dynamic_array));
    dynamicArray->itemSize = itemSize;
    dynamicArray->capacity = kInitialCapacity;
    dynamicArray->logicalSize = 0;
    dynamicArray->internalArray = malloc(itemSize * kInitialCapacity);
    return dynamicArray;
}

void DynamicArrayGet(dynamic_array *dynamicArray, size_t index, void *output) {
    assert(index < dynamicArray->logicalSize);
    size_t indexMemoryOffset = index * dynamicArray->itemSize;
    memcpy(output, dynamicArray->internalArray + indexMemoryOffset, dynamicArray->itemSize);
}

void DynamicArraySet(dynamic_array *dynamicArray, size_t index, const void *input) {
    assert(index < dynamicArray->logicalSize);
    size_t indexMemoryOffset = index * dynamicArray->itemSize;
    memcpy(dynamicArray->internalArray + indexMemoryOffset, input, dynamicArray->itemSize);
}

void DynamicArrayAppend(dynamic_array *dynamicArray, const void *input) {
    if (dynamicArray->logicalSize == dynamicArray->capacity - 1) {
        dynamicArray->capacity *= kGrowthFactor;
        dynamicArray->internalArray = realloc(dynamicArray->internalArray,
                                              dynamicArray->capacity * dynamicArray->itemSize);
    }
    dynamicArray->logicalSize += 1;
    DynamicArraySet(dynamicArray, dynamicArray->logicalSize - 1, input);
}


void DynamicArrayDispose(dynamic_array *dynamicArray) {
    free(dynamicArray->internalArray);
    free(dynamicArray);
}
