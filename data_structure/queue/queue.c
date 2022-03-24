#include <stdlib.h>

typedef struct item_t
{
    int val;
    struct item_t *following_item;
} item_t;

typedef struct queue_t
{
    item_t *top;
    item_t *last_item;
    unsigned int n_items; 
} queue_t;

queue_t* create_queue()
{
    queue_t* queue = malloc(sizeof(queue_t));
    queue->top = NULL;
    queue->last_item = NULL;
    queue->n_items = 0;
}

item_t* create_new_item(int val)
{
    item_t *new_item = malloc(sizeof(item_t));
    new_item->val = val;
    new_item->following_item = NULL;
}
void push(int val, queue_t *queue)
{
    item_t *new_item = create_new_item(val);    

    if (queue->n_items == 0)
    {
        queue->last_item = new_item;
        queue->top = new_item;
        queue->n_items++;
        new_item->following_item = NULL;
    }else{
        queue->last_item->following_item = new_item;
        queue->last_item = new_item;
        queue->n_items++;
    }
}

item_t* pop(queue_t *queue)
{
    item_t *poped_item = queue->top->following_item;
    queue->top = queue->top->following_item;
    return poped_item;
}

void main()
{
    queue_t *queue = create_queue();
    push(12, queue);
    push(1, queue);
    pop(queue);
}