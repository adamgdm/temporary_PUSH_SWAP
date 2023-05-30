#include "pushswap.h"

int ft_find_chunk_min(stack **s, int chunk_nums, int what_chunk, int total)
{
    int min;
    int max;
    int num;
    stack *a;

    min = ft_find_min_num(s);
    a = (*s);
    if (what_chunk == 1)
        return (min);
    num = ((what_chunk - 1) * (total / chunk_nums));
    while (num)
    {    
        max = 2147483647;
        while (a)
        {
            if (a->value < max && a->value > min)
                max = a->value;
            a = a->next;
        }
        num--;
        a = (*s);
        min = max;
    }
    return (max);
}

int ft_find_chunk_max(stack **s, int chunk_nums, int what_chunk, int total)
{
    int min;
    int max;
    int num;
    stack *a;

    min = ft_find_min_num(s);
    a = (*s);
    if (what_chunk == chunk_nums)
        return (ft_find_max_num(s));
    num = ((what_chunk) * (total / chunk_nums) - 1);
    while (num)
    {    
        max = 2147483647;
        while (a)
        {
            if (a->value < max && a->value > min)
                max = a->value;
            a = a->next;
        }
        num--;
        a = (*s);
        min = max;
    }   
    return (max);
}