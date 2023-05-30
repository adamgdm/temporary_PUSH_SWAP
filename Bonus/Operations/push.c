#include "../Checker.h"

/*
void ft_push(stack **a, stack **b)
{
    if (!(*a))
        return ;
    if !(**b)
    {
        if (*b)
        *b = *a;
        if ((*a)->next)
        {
            (*a) = (*a)->next;
            
        } 
    }
    

}

void ft_push(stack **a, stack **b, char c)
{
    stack *pointer;

    if (!(*a))
        return;
    pointer = (*a)->next;
    if (pointer)
        pointer->previous = NULL;
    if (*b)
    {
        (*a)->next = (*b);
        (*b)->previous = (*a);
    }
    else
        (*a)->next = NULL;
    (*b) = (*a);
    (*a) = pointer;
    if (*a)
        (*a)->previous = NULL;
    printf("p%c\n", c);
}
*/

void ft_push(stack **a, stack **b, char c)
{
    stack *pointer;

    if (!(*a))
        return;

    pointer = (*a)->next;
    if (pointer)
        pointer->previous = NULL;

    if (*a == *b)
        *b = NULL;

    if (*b)
    {
        (*a)->next = (*b);
        (*b)->previous = (*a);
    }
    else
        (*a)->next = NULL;

    (*b) = (*a);
    (*a) = pointer;

    if (*a)
        (*a)->previous = NULL;

}
// 4 56 2 114 1
