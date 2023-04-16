#include "../pushswap.h"
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
*/

void ft_push(stack **a, stack **b, char c)
{
    stack *pointer;

    if (!(*a))
        return ;
    else
    {
        pointer = (*a)->next;
        if (pointer)
            pointer->previous = NULL;
        if (*b)
        {
            (*a)->next = (*b);
            (*b)->previous = (*a);   
        }
        *b = *a;
        *a = pointer;
    }
    printf("p%c\n", c);
}

// 4 56 2 114 1
