#include "../pushswap.h"

void ft_reverse_rotate(stack **s, char c)
{
    stack *a;
    stack *last;
    int argc;

    argc = ft_count_linkedlist_elements(*s);
    if (argc > 1)    
    {
        last = *s;
        while (last->next)
            last = last->next;
        a = last->previous;
        a->next = NULL;
        last->next = (*s);
        last->previous = NULL;
        (*s)->previous = last;
        (*s) = last;
    }
    printf("rr%c\n", c);
}