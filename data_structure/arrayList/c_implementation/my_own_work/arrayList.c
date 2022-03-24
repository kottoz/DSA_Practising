/**
 * @brief This is my own work to implement the arrayList.
 *
 * Arraylist has the following basic methods:
 *  - append an item to the end of the array.
 *  - pop an item from the end of the array.
 *  - insert an item into specific index.
 *  - remove an item from a specific index.
 *  - clear all items of the array.
 *
 */

#include <stdio.h>
#include <stdlib.h>

// arrayList structure

typedef struct
{
    unsigned int capacity;
    unsigned int n_items;
    // TODO: try to use pointer to items, instead of pointer to pointer.
    void **items;
} arrayList;

#define INITIAL_CAPACITY 1 // reserve four bytes at the begging (like int).
// arrayList creation
arrayList *create_al()
{
    arrayList *al = malloc(sizeof(arrayList));
    al->capacity = INITIAL_CAPACITY;
    al->n_items = 0;
    al->items = malloc(sizeof(void *) * INITIAL_CAPACITY);
}

// allocate sufficient memory
void arrayList_allocate(arrayList *al, unsigned int size)
{
    if (size > al->capacity)
    {
        unsigned int new_capacity = al->capacity;
        while (new_capacity < size)
        {
            new_capacity = al->capacity + 1;
        }
        al->items = realloc(al->items, sizeof(void *) * new_capacity);
        al->capacity = new_capacity;
    }
    else
    {
        unsigned int new_capacity = (al->capacity) - 2;
        al->items = realloc(al->items, sizeof(void *) * new_capacity);
        al->capacity = new_capacity;
    }
}

// return number of items in the array list
inline unsigned int array_list_size(arrayList *al)
{
    return al->n_items;
}

// append item into the arrayList
void append_item(arrayList *al, void *item)
{
    arrayList_allocate(al, al->capacity + 1);
    al->items[al->n_items++] = item;
}

// pop item from the arrayList.
void *pop_item(arrayList *al)
{
    void *ptr_item = al->items[--al->n_items];
    arrayList_allocate(al, al->capacity - 1);
    return ptr_item;
}
// insert item into specific index.

// remove an item from a specific index.

void main()
{
    arrayList *al = create_al();
    int i = 0;
    append_item(al, (int *)(&i));
    int y = 85;
    append_item(al, (int *)(&y));
    char *s = "Hello World";
    append_item(al, (int *)(&s));
    void **ptr_item = pop_item(al);
    printf("%s", *(*(&ptr_item)));
}