#include "../pushswap.h"

void ft_ss(stack *a, stack*b)
{
    ft_swap(&a, 'a');
    ft_swap(&b, 'b');
}

void ft_rr(stack *a, stack*b)
{
    ft_rotate(&a, 'a');
    ft_rotate(&b, 'b');
}

void ft_rrr(stack *a, stack*b)
{
    ft_reverse_rotate(&a, 'a');
    ft_reverse_rotate(&b, 'b');
}
