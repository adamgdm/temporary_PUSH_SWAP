#include "pushswap.h"

stack *ft_sort_two(stack **a)
{
    stack *b;
    int first;
    int second;

    b = *a;
    first = b->value;
    b = b->next;
    second = b->value;
    if (first > second)
        ft_rotate(a, 'a');
    return (*a);
}

stack *ft_sort_three(stack **a)
{
    stack *b;
    elements x;

    b = *a;
    x.first = b->value;
    b = b->next;
    x.second = b->value;
    b = b->next;
    x.third = b->value;
    printf("first %d", x.first);
    printf("first %d", x.second);
    printf("first %d", x.third);
    if (x.first > x.second && x.second > x.third && x.first > x.third) /*321*/
    {   
        ft_swap(a, 'a');
        ft_reverse_rotate(a, 'a');
    }
    else if (x.first < x.second && x.second > x.third && x.first < x.third) /*132*/
    {   
        ft_reverse_rotate(a, 'a');
        ft_swap(a, 'a');
    }
    else if (x.first > x.second && x.second < x.third && x.first > x.third) /*312*/
        ft_rotate(a, 'a');
    else if (x.first > x.second && x.second < x.third && x.first < x.third) /*213*/
        ft_swap(a, 'a');
    else if (x.first < x.second && x.second > x.third && x.first > x.third) /*231*/
        ft_reverse_rotate(a, 'a');
    return (*a);
}

void ft_rotate_b_elements(stack **b)
{
    int i;
    stack *a;

    i = 0;
    a = (*b);
    if (a)
        i++;
    while (a->next)
    {    
        i++;
        a = a->next;
    }
    if (i == 2)
        ft_rotate(b, 'b');
}

stack *ft_sort_five(stack **a, stack **b, int argc, int index)
{
    int i;
    int j;

    i = argc - 3;
    j = i;
    while (i)
    {
        index = ft_find_min(a);
        while (index % argc != 1)
        {
            if (index > 2)
            {    
                ft_reverse_rotate(a, 'a');
                index++;
            }
            else
            {    
                ft_rotate(a,'a');
                index--;
            }
        }
        ft_push(a, b, 'b');
        printLinkedList(*a);
        if (argc == 5)
            argc--;
        i--;
    }
    ft_sort_three(a);
    printLinkedList(*a);
    while (j)
    {   
        ft_push(b, a, 'a');
        j--;
    }
    return(*a);
}

stack *ft_sort_stack(stack **arguments, stack **b)
{
    int argument_count;

    argument_count = ft_count_linkedlist_elements(*arguments);
    if (argument_count == 2)
        return(ft_sort_two(arguments));
    if (argument_count == 3)
        return(ft_sort_three(arguments));
    if (argument_count == 4 || argument_count == 5)
        return(ft_sort_five(arguments, b, argument_count, 0));
    return (*arguments);
    
}
