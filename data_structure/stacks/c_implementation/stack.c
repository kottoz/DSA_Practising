#include<stdlib.h>
#include<stdint.h>

#define MAX_ITEMS 10
typedef struct
{
    int items[MAX_ITEMS];
    int top;
} stack_t;

stack_t* creat_stack()
{
    stack_t *stack = malloc(sizeof(stack_t));
    stack->top = -1;
    return stack;
}

void push(int item, stack_t *stack)
{
  stack->top++;
    stack->items[stack->top] = item;
}

int pop(stack_t *stack)
{
    int poped_item = stack->items[stack->top];
    stack->top--;
    return poped_item;
}

void main()
{
    stack_t *stack = creat_stack();
    push(2, stack);
    push(55, stack);
    push(5, stack);
    pop(stack);
    push(3, stack);
    pop(stack);

    
}
