#include "pushswap.h"

/*stack *ft_sort_more(stack **a, stack **b, int argc, t_ints elem)
{
    elem.current = (*a);
    elem.how_many = 1;
    elem.n = ((3/115) * argc) + 5;
    elem.middle = argc / 2;
    elem.offset = argc / elem.n;
    elem.start = ;
    elem.end = elem.middle + elem.offset;
    // printf("LINKED LIST A ====\n");
    // printLinkedList(*a);
    // printf("LINKED LIST B ====\n");
    // printLinkedList(*b);
    while (elem.current)
    {
        if (elem.current->value >= elem.start && elem.current->value <= elem.end)
        {
            if (elem.how_many > elem.middle)
            {
                while (elem.how_many <= argc)
                {    
                    ft_reverse_rotate(a, 'a');
                    elem.how_many++;
                }
            }
            else
            {
                while (elem.how_many != 1)
                {    
                    ft_rotate(a, 'a');
                    elem.how_many--;
                }    
            }
            ft_push(a,b,'b');
            argc--;
            elem.how_many = 1;
            elem.current = (*a);
        }
        else
        {
            elem.how_many++;
            elem.current = elem.current->next;
            if (!elem.current && (*a))
            {
                elem.end += elem.offset;
                elem.start -= elem.offset;
                elem.current = (*a);
                elem.how_many = 1;
            }
        }
    }
    // printf("\n\n AFTER \n\n");
    // printf("LINKED LIST A ====\n");
    // printLinkedList(*a);
    // printf("LINKED LIST B ====\n");
    // printLinkedList(*b);
}*/
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

stack *ft_sort_more(stack **a, stack **b, int argc, t_ints elem)
{
    int How_many;
    int min;
    int max;
    int chunck_current;
    int Position;
    int size;
    stack *iter;

    How_many = (0.015 * argc) + 3.5;
    chunck_current = 1;
    size = argc;
    while (chunck_current <= How_many)
    {
        Position = 1;
        iter = (*a);
        min = ft_find_chunk_min(elem.hehe,How_many,chunck_current,argc);
        max = ft_find_chunk_max(elem.hehe,How_many,chunck_current,argc);
        while (iter)
        {
            if (iter->value >= min && iter->value <= max)
            {
                //printf("Number = %d && Chuck = %d (Min = %d, Max = %d, Position = %d, size = %d)\n",iter->value,chunck_current, min,max, Position, size);
                if (Position <= size / 2)
                {
                    while (Position != 1)
                    {
                        ft_rotate(a,'a');
                        Position--;
                    }
                }
                else
                {
                    while ((size - Position + 1) && size > 1)
                    {
                        ft_reverse_rotate(a,'a');
                        Position++;
                    }
                }
                ft_push(a,b,'a');
                Position = 1;
                iter = (*a);
                size--;
            }
            else
            {
                Position++;
                iter = iter->next;
            }
        }
        chunck_current++;
    }
    max = ft_find_max(b);
    min = 0;
    iter = (*b);
   printLinkedList(*b);
    printf("MAX = %d\n", max);
    while (iter)
    {
        if (*a)
        {
            if (ft_last_stack(a)->value == max)
            {
                ft_reverse_rotate(a,'a');
                min--;
            }
        }
        if (iter->value == max)
            ft_push(b,a,'a');
        else
        {
            if (!min || ((ft_last_stack(a)->value) < iter->value))
            {
                ft_push(b,a,'a');
                ft_rotate(a,'a');
                min++;
            }
            else if ((*b)->value != max && (ft_last_stack(a)->value) > iter->value)
                ft_rotate(b,'b');
        }
        iter = (*b);
        max = check_last_max(*a, max, ft_find_max_two(elem.hehe, max));
        printf("MAX = %d\n", max);
    }
    /*while (min)
    {
        ft_reverse_rotate(a,'a');
        min--;
    }*/
    printLinkedList(*a);
}





