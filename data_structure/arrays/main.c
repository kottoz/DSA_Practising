#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dynamic_array_1.h"

int main(int argc, const char *argv[])
{
    srand((unsigned int)time(NULL));

    int iterations = 20;
    dynamic_array *dynamicArray = DynamicArrayCreate(sizeof(int));

    for (int i = 0; i < iterations; i++)
    {
        int number = rand() % 10;
        DynamicArrayAppend(dynamicArray, &number);
    }

    for (int i = 0; i < iterations; i++)
    {
        int output;
        DynamicArrayGet(dynamicArray, i, &output);
        printf("%d\n", output);
    }

    DynamicArrayDispose(dynamicArray);

    return 0;
}
