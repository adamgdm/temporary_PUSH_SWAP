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

void	ft_do_this(stack **b, int size, int max)
{
	int	i;
    stack *a;
    
    i = 1;
    a = (*b);
	while (a)
    {
        if (a->value == max)
            break ;
        a = a->next;
        i++;
    }
	if (i >= size)
		ft_reverse_rotate(b,'b');
	if (i < size)
		ft_rotate(b,'b');
}

int ft_find_max_in_s(stack **a, int max)
{
    stack *lol;

    lol = (*a);
    while (lol)
    {
        if (lol->value == max)
            return (1);
        lol = lol->next;
    }
    return (0);
}

stack *ft_sort_more(stack **a, stack **b, int argc, t_ints elem)
{
    int How_many;
    int min;
    int max;
    int chunck_current;
    int Position;
    int size;
    int middle;
    int offset;
    int i;
    int sortedArray[argc];
    stack *iter;

    offset = argc / ft_get_offset(argc);
    //How_many = (0.015 * argc) + 5.25;
    //printLinkedList(*a);
    //exit(0);
    sortedArray[0] = ft_find_min(a);
    // printf("%d ", sortedArray[0]);
    i = 1;
    while(i < argc)
    {
        sortedArray[i] = ft_get_min(a, sortedArray[i - 1]);
        // printf("%d ", sortedArray[i]);
        i++;
    }
    // exit(0);
    size = argc;
    middle = sortedArray[argc / 2];
    min = argc / 2;
    max = argc / 2;
    int ac;
    i = 1;
    while (*a)
    {
        ac = size;
        min -= offset;
        if (min < 0)
            min = 0;
        max += offset;
        if (max >= argc)
            max = argc - 1;
        iter = (*a);
        while (i <= ac)
        {
            if (iter->value >= sortedArray[min] && iter->value <= sortedArray[max])
            {
                if ((iter)->value > middle)
                    ft_push(a,b,'b');
                else if ((iter)->value <= middle)
                {
                    ft_push(a,b,'b');
                    ft_rotate(b,'b');
                }
                size--;
            }
            else
            {
                ft_rotate(a,'a');
            }
            iter = (*a);
            i++;
        }
        i = 1;
    }
    max = ft_find_max(b);
    min = 0;
    Position = 1;
    i = 0;
    size = argc;
    stack *boghdnan;
    // printLinkedList(*b);
    iter = (*b);
   /* while (iter->value != max)
    {
        iter = (*b);
        if (!(*a))
        {
            ft_push(b,a,'a');
            min++;
            boghdnan = (*a);
        }
        if (iter->value != max)
        {
            if (boghdnan->value > iter->value)
            {
                ft_push(b,a,'b');
                boghdnan = (*a);
                min++;
            }
            else
                break ;
        }
    }
    iter = (*b);
    //printf("MAX = %d\n", max);
    
    while (iter)
    {
        if (*a)
        {
            if (ft_last_stack(a)->value == max)
            {
                ft_reverse_rotate(a,'a');
                max = check_last_max(*a, max, ft_find_max_two(elem.hehe, max));
                min--;
            }
        }
        if (iter->value == max)
        {
            ft_push(b,a,'a');
            max = check_last_max(*a, max, ft_find_max_two(elem.hehe, max));
        }
        else 
        {
            if (!min || ((ft_last_stack(a)->value) < iter->value))
            {
                ft_push(b,a,'a');
                ft_rotate(a,'a');
                min++;
            }
            else if ((*b)->value != max && ft_last_stack(a)->value > iter->value && min != 0)
            {
                stack *temp = *b;
                int tempPosition = 1;

                while (temp && temp->value != max)
                {
                    tempPosition++;
                    temp = temp->next;
                }
                // if (tempPosition == 2 && temp && temp->value == max)
                // {
                //     printf("WAAAAAAAAAA3\n");
                //     ft_swap(b,'b');
                // }
                if (temp && temp->value == max)
                {
                    if (tempPosition <= size / 2)
                    {
                        while (tempPosition != 1)
                        {
                            ft_rotate(b, 'b');
                            tempPosition--;
                        }
                    }
                    else
                    {
                        while (tempPosition <= size && size > 1)
                        {
                            ft_reverse_rotate(b, 'b');
                            tempPosition++;
                        }
                    }
                }
                iter = *b;
                size = ft_count(*b);
                Position = 1;
            }
        }
        iter = (*b);
    }
*/
    i = argc - 1;
    max = sortedArray[i];
    while (iter)
    {
        if (ft_find_max_in_s(b, max) == 1)
        {
            if (!(*a) || iter->value == max)
            {
                if (!(*a))
                {
                    boghdnan = iter;
                    min++;
                }
                else
                {   
                    if (i)
                        max = sortedArray[i--];
                    else
                        max = sortedArray[0];    
                }
                if (i <= 0)
                    i = 0;
                ft_push(b,a,'a');
                size--;
            }
            else
            {
                if (min == 0 || (iter->value > boghdnan->value && min != 0))
                {
                    ft_push(b,a,'a');
                    ft_rotate(a,'a');
                    boghdnan = iter;
                    size--;
                    min++;
                }
                else
                    ft_do_this(b, size / 2, max);                
            }
        }
        else            
        {
            ft_reverse_rotate(a,'a');
            if (i)
                max = sortedArray[i--];
            else
                max = sortedArray[0];
            if (min)
                min--;
        }
        iter = (*b);
    }
    while (min)
    {
        ft_reverse_rotate(a,'a');
        min--;
    }
}





