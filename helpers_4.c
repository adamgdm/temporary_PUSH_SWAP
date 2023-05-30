#include "pushswap.h"

stack* ft_last_stack(stack** head) 
{
    stack* current = *head;
    if (current == NULL) 
        return NULL;
    while (current->next != NULL)
        current = current->next;
    return current;
}

int check_last_max(stack *ll, int last_max, int max) 
{
    if (!ll)
        return (last_max);
    if (ll->next == NULL && ll->value != last_max)
        return (last_max);
    while (ll->next)
    {
        if (ll->value == last_max)
            break ;
        ll = ll->next;
    }
    if ((ll->previous) == NULL)
        return (max);
    if ((ll->previous)->value == max)
        return (max);
    else
        return (last_max);
    return (last_max);
}

int ft_count(stack *head)
{
    int count = 0;
    stack *current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

int ft_get_min(stack **a, int last_min)
{
    stack *s;
    int min;

    s = (*a);
    min = 2147483647;
    while (s)
    {
        if (s->value < min && s->value > last_min)
            min = s->value;
        s = s->next;
    }
    return (min);
}

int ft_get_offset(argc)
{
    if (argc < 11)
        return (5);
    if (argc < 151)
        return (8);
    else
        return (15);
}
