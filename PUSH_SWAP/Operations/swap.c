#include "../pushswap.h"

void ft_swap(stack **s, char c)
{
    stack *a;
    int argc;

    argc = ft_count_linkedlist_elements(*s) ;
    if (argc > 1)
    {
        a = *s;
        a = a->next;
        (*s)->previous = (*s)->next;
        (*s)->next = a->next;
        a->next = a->previous;
        a->previous = NULL;
        *s = a;
        if (argc > 2)
        {
            a = a->next;
            a = a->next;
            a->previous = (*s)->next;
        }
    }
    printf("s%c\n", c);
}