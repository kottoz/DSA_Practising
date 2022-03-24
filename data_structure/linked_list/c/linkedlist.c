/**
 * @file linkedlist.c
 * @author kotoz (mohamedtareck95@gmail.com)
 * @brief this module is my implementation for both singly and doubly linked list
 * @version 0.1
 * @date 2022-02-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    void *data;
    struct node *next;
} node;

typedef struct
{
    unsigned int n_items;
    unsigned int capacity;
    node *head;
} singly_linkedList;

#define INITIAL_CAPACITY 1

singly_linkedList *create_sll(void)
{
    singly_linkedList *sll = malloc(sizeof(singly_linkedList));
    sll->n_items = 0;
    sll->capacity = INITIAL_CAPACITY;
    sll->head = malloc(sizeof(node));
    sll->head->next = NULL;
    sll->head->data = NULL;
    return sll;
}

// append
singly_linkedList *sll_append(singly_linkedList *sll, void *value)
{
    node *new_node = malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;

    node *cursor = sll->head;
    while (cursor->next != NULL)
    {
        // cursor = sll->head->next;
        cursor = cursor->next;
    }

    cursor->next = new_node;
    sll->n_items++;
    return sll;
}

// pop
node *sll_pop(singly_linkedList *sll)
{
    node *cursor = sll->head;
    node *last_cursor = cursor;
    while (cursor->next != NULL)
    {
        last_cursor = cursor;
        cursor = cursor->next;
    }
    last_cursor->next = NULL;
    node *poped_node = malloc(sizeof(node));
    memcpy(poped_node, cursor, sizeof(node));
    free(cursor);
    sll->n_items--;
    return poped_node;
}

// insert
node *sll_insert(singly_linkedList *sll, void *value, unsigned int index)
{
    node *new_node = malloc(sizeof(node));
    new_node->data = value;
    node *cursor = sll->head;

    for (int current_index = 0; current_index < sll->n_items; current_index++)
    {
        if (current_index == index)
        {
            new_node->next = cursor->next;
            cursor->next = new_node;
            return new_node;
        }
        cursor = cursor->next;
    }
}

// remove

void main()
{
    singly_linkedList *sll = create_sll();
    int val = 1;
    int val1 = 2;
    int val2 = 3;
    sll_append(sll, &val);
    sll_append(sll, &val1);
    sll_append(sll, &val2);
    node *poped_item = sll_pop(sll);
    node *inserted = sll_insert(sll, &val, 1);
}
