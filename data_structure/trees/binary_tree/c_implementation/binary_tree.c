// /**
//  * @file binary_tree.c
//  * @author your name (you@domain.com)
//  * @brief Implementation of binary tree
//  * @version 0.1
//  * @date 2022-02-27
//  *
//  * @copyright Copyright (c) 2022
//  *
//  */
#include <stdio.h>
#include <stdlib.h>

// construct tree node

typedef struct node_t
{
    int value;
    struct node_t *r_node;
    struct node_t *l_node;

} node_t;

void insert(int val, node_t **tree)
{
    if (*tree == NULL)
    {
        *tree = malloc(sizeof(node_t));
        (*tree)->l_node = NULL;
        (*tree)->r_node = NULL;
        (*tree)->value = val;
    }
    else if (val <= (*tree)->value)
    {
        insert(val,&((*tree)->l_node));
    }
    else
    {
        insert(val, &((*tree)->r_node));
    }
}

// delete node
void delete(int val, node_t **tree)
{
    if(*tree == NULL)
    {
        return NULL;
    }else if(val == (*tree)->value)
    {
        free(&(*tree));
    }
    else if (val <= (*tree)->l_node )
    {
        delete (val, &((*tree)->l_node));
    }
}

void main()
{
    node_t *tree = NULL;
    insert(23, &tree);
    insert(24, &tree);
    insert(2, &tree);
}

