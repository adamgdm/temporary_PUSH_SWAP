/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:25:12 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/07 07:02:24 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push_a_to_b(t_stack **a, t_stack **b, int *sorted_array, t_var x)
{
	while (*a)
	{
		x.iter = (*a);
		ft_redo_some_stuff(&x.i, &x.ac, x.size);
		x.min = ft_add_remove_offset(x.min, x.offset, x.argc, 1);
		x.max = ft_add_remove_offset(x.max, x.offset, x.argc, 0);
		while (x.i <= x.ac)
		{
			if (x.iter->value >= sorted_array[x.min]
				&& x.iter->value <= sorted_array[x.max])
			{
				if ((x.iter)->value > x.middle)
					ft_push(a, b, 'b');
				else if ((x.iter)->value <= x.middle)
					ft_push_rotate(a, b);
				x.size--;
			}
			else
				ft_rotate(a, 'a');
			x.iter = (*a);
			x.i++;
		}
	}
}

t_var	handle_max_value(t_stack **a, t_stack **b, int *sorted_array, t_var x)
{
	if (!(*a) || x.iter->value == x.max)
	{
		if (!(*a))
		{
			ft_push(b, a, 'a');
			x.boghdnan = x.iter;
		}
		else
		{
			ft_do_norminette(&x.i, &x.max, sorted_array);
			ft_do_more(&x.i, a, b);
		}
		x.size--;
	}
	else
	{
		if (x.min == 0 || (x.iter->value > x.boghdnan->value && x.min != 0))
			x = ft_do_that(a, b, x);
		else
			ft_do_this(b, x.size / 2, x.max);
	}
	return (x);
}

t_var	handle_min_value(t_stack **a, int *sorted_array, t_var x)
{
	if ((*a)->value != x.max)
		ft_reverse_rotate(a, 'a');
	if (x.i)
		x.max = sorted_array[x.i--];
	else
		x.max = sorted_array[0];
	return (x);
}
/*void	printLinkedList(t_stack *a, int inta)
{
	ft_printf("\n");
	while (a)
	{
		ft_printf("%d (MAX = %d)\n", a->value, inta);
		a = a->next;
	}
	ft_printf("\n");
}*/

t_var	ft_intialize_variables_second(t_var x, int argc, t_stack **b)
{
	x.max = ft_find_max(b);
	x.min = 0;
	x.i = 0;
	x.size = argc;
	x.iter = (*b);
	x.i = argc - 1;
	return (x);
}

t_stack	*ft_sort_more(t_stack **a, t_stack **b, int argc)
{
	t_var	x;
	int		*sorted_array;

	x = ft_intialize_variables(a, b, argc);
	sorted_array = ft_sort_array(a, argc);
	x.middle = sorted_array[x.min];
	ft_push_a_to_b(a, b, sorted_array, x);
	x = ft_intialize_variables_second(x, argc, b);
	x.max = sorted_array[x.i];
	while (x.iter)
	{
		x.min = ft_get_last_node(a, sorted_array[argc - 1], 0);
		if (ft_find_max_in_s(b, x.max) == 1)
			x = handle_max_value(a, b, sorted_array, x);
		else
			x = handle_min_value(a, sorted_array, x);
		x.iter = (*b);
	}
	while (x.min)
	{
		ft_reverse_rotate(a, 'a');
		x.min--;
	}
	free (sorted_array);
	return (*a);
}
