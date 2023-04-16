#include "../pushswap.h"

void ft_rotate(stack **s, char c)
{
    stack *a;
    stack *last;
    int argc;

    argc = ft_count_linkedlist_elements(*s);
    if (argc > 1)    
    {
        a = *s;
        last = *s;
        while (last->next)
            last = last->next;
        while (a->next)
            a = a->next;
        last->next = (*s);
        (*s) = (*s)->next;
        (*s)->previous = NULL;
        last = last->next;
        last->next = NULL;
        last->previous = a;
        printf("r%c\n", c);
    }
}