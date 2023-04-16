#include "pushswap.h"

int ft_find_chunk_min(stack **s, int chunk_nums, int what_chunk, int total)
{   
    int min;
    int current;
    int numbers;
    stack *a;

    min = ft_find_min_num(s);
    numbers = total / chunk_nums;
    if (what_chunk == 1)
        return (min);
    while (numbers)
    {
        a = (*s);
        current = a->value;
        while (a->next)
        {
            a = a->next;
            if (a->value < current)
            {
                if (current > min)    
                    min = a->value;
            }
        }
        numbers--;
    }
    return(current);
}
