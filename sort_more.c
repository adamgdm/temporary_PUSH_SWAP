#include "pushswap.h"

void	ft_do_this(stack **b, int size, int max)
{
	int		i;
	stack	*a;

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
		ft_reverse_rotate(b, 'b');
	if (i < size)
		ft_rotate(b, 'b');
}

int	ft_find_max_in_s(stack **a, int max)
{
	stack	*lol;

	lol = (*a);
	while (lol)
	{
		if (lol->value == max)
			return (1);
		lol = lol->next;
	}
	return (0);
}

t_var	ft_intialize_variables(stack **a, stack **b, int argc)
{
	t_var	x;

	x.offset = argc / ft_get_offset(argc);
	x.i = 1;
	x.size = argc;
	x.min = argc / 2;
	x.max = argc / 2;
	x.ac = argc;
	x.argc = argc;
	return (x);
}

int	ft_add_remove_offset(int a, int offset, int argc, int b)
{
	if (b == 0)
		a += offset;
	else
		a -= offset;
	if (a >= argc)
		return (argc - 1);
	else if (a < 0)
		return (0);
	return (a);
}

void	ft_redo_some_stuff(int *i, int *ac, int size)
{
	*i = 1;
	*ac = size;
}

void	ft_push_a_to_b(stack **a, stack **b, int *sortedArray, t_var x)
{
	while (*a)
	{
		x.iter = (*a);
		ft_redo_some_stuff(&x.i, &x.ac, x.size);
		x.min = ft_add_remove_offset(x.min, x.offset, x.argc, 1);
		x.max = ft_add_remove_offset(x.max, x.offset, x.argc, 0);
		while (x.i <= x.ac)
		{
			if (x.iter->value >= sortedArray[x.min]
				&& x.iter->value <= sortedArray[x.max])
			{
				if ((x.iter)->value > x.middle)
					ft_push(a, b, 'b');
				else if ((x.iter)->value <= x.middle)
				{
					ft_push(a, b, 'b');
					ft_rotate(b, 'b');
				}
				x.size--;
			}
			else
				ft_rotate(a, 'a');
			x.iter = (*a);
			x.i++;
		}
	}
}

int	*ft_sort_array(stack **a, int argc)
{
	int	*s;
	int	i;

	i = 1;
	s = malloc(sizeof(int) * argc);
	if (!s)
		exit(0);
	s[0] = ft_find_min(a);
	while (i < argc)
	{
		s[i] = ft_get_min(a, s[i - 1]);
		i++;
	}
	return (s);
}

void	ft_do_that(stack **a, stack **b, void *s, void *v)
{
	ft_push(b, a, 'a');
	ft_rotate(a, 'a');
	s = v;
}

void	ft_do_norminette(int *i, int *max, int *sortedArray)
{
	if (*i)
	{
		*max = sortedArray[*i];
		(*i)--;
	}
	else
		*max = sortedArray[0];
}
void	ft_push_rotate(stack **a, stack **b)
{
}
t_var	handle_max_value(stack **a, stack **b, int *sortedArray, t_var x)
{
	if (!(*a) || x.iter->value == x.max)
	{
		if (!(*a))
		{
			x.boghdnan = x.iter;
			x.min++;
		}
		else
			ft_do_norminette(&x.i, &x.max, sortedArray);
		if (x.i <= 0)
			x.i = 0;
		ft_push(b, a, 'a');
		x.size--;
	}
	else
	{
		if (x.min == 0 || (x.iter->value > x.boghdnan->value && x.min != 0))
		{
			ft_push(b, a, 'a');
			ft_rotate(a, 'a');
			x.boghdnan = x.iter;
			x.size--;
			x.min++;
		}
		else
			ft_do_this(b, x.size / 2, x.max);
	}
	return (x);
}

t_var	handle_min_value(stack **a, int *sortedArray, t_var x)
{
	if ((*a)->value != x.max)
		ft_reverse_rotate(a, 'a');
	if (x.i)
		x.max = sortedArray[x.i--];
	else
		x.max = sortedArray[0];
	if (x.min)
		x.min--;
	return (x);
}

void	printLinkedList(stack *a)
{
	printf("\n\n");
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	printf("\n");
}

stack	*ft_sort_more(stack **a, stack **b, int argc)
{
	static t_var	x;
	int				*sortedArray;

	x = ft_intialize_variables(a, b, argc);
	sortedArray = ft_sort_array(a, argc);
	x.middle = sortedArray[x.min];
	ft_push_a_to_b(a, b, sortedArray, x);
	x.max = ft_find_max(b);
	x.min = 0;
	x.Position = 1;
	x.i = 0;
	x.size = argc;
	x.iter = (*b);
	x.i = argc - 1;
	x.max = sortedArray[x.i];
	//x.alwaysmax = x.max;
	while (x.iter)
	{
		if (ft_find_max_in_s(b, x.max) == 1)
			x = handle_max_value(a, b, sortedArray, x);
		else
			x = handle_min_value(a, sortedArray, x);
		x.iter = (*b);
	}
	/*while (x.iter)
    {
        if (ft_find_max_in_s(b, x.max) == 1)
        {
            if (!(*a) || x.iter->value == x.max)
            {
                if (!(*a))
                {
                    x.boghdnan = x.iter;
                    x.min++;
                }
                else
                {   
                    if (x.i)
                        x.max = sortedArray[x.i--];
                    else
                        x.max = sortedArray[0];    
                }
                if (x.i <= 0)
                    x.i = 0;
                if ((!*a) && x.iter->value != x.max)
                    x.size++;
                x.size--;
                ft_push(b,a,'a');
            }
            else
            {
                if (x.min == 0 || (x.iter->value > x.boghdnan->value
			&& x.min != 0))
                {
                    ft_push(b,a,'a');
                    ft_rotate(a,'a');
                    x.boghdnan = x.iter;
                    x.size--;
                    x.min++;
                }
                else
                    ft_do_this(b, x.size / 2, x.max);                
            }
        }
        else            
        {
                ft_reverse_rotate(a,'a');
            if (x.i)
                x.max = sortedArray[x.i--];
            else
                x.max = sortedArray[0];
            if (x.min)
                x.min--;
        }
        x.iter = (*b);
    }*/
	while (x.min)
	{
		ft_reverse_rotate(a, 'a');
		x.min--;
	}
}
