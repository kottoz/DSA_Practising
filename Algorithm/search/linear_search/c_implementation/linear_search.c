// Linear search also allows you to append new items to the end of the array.

// typedef keyword to allow users to provide alternative names for the primitive

#include <stdio.h>

typedef struct
{
    char *key; // pointer to char
    int value; // integer variable
} item;

/*
    a function that move through a contigious memory locations, and compare each item with the provided key.

    :param items: pointer to item datatype, represens 2D array.
    :param size: size of the array of elements.
    :param key: pointer to const char, which represent string (key) to be compared with.

    :returns : the address of that item
*/
item *linear_search(item *items, size_t size, const char *key)
{

    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(items[i].key, key) == 0)
        {
            return &items[i];
        }
    }
    return NULL;
}

int main(void)
{   
    // these items is defined at the compilation.
    item items[] =
        {
            {"foo", 10},
            {"bar", 42},
            {"bazz", 36},
            {"buzz", 7},
            {"bob", 11},
            {"jane", 100},
            {"x", 200}};

    size_t num_items = sizeof(items) / sizeof(item);

    item *found = linear_search(items, num_items, "bob");

    items[0].key = "car";

    if (!found)
    {
        return 1;
    }
    printf("linear_search: value of 'bob' is %d\n", found->value);
    printf(" Items zero index's key %s\n", items[0].key);


    return 0;
}