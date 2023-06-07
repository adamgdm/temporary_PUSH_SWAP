/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:29:32 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/07 06:24:40 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_redo_some_stuff(int *i, int *ac, int size)
{
	*i = 1;
	*ac = size;
}

int	*ft_sort_array(t_stack **a, int argc)
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

t_var	ft_do_that(t_stack **a, t_stack **b, t_var x)
{
	ft_push(b, a, 'a');
	ft_rotate(a, 'a');
	x.size--;
	x.min++;
	x.boghdnan = x.iter;
	return (x);
}

void	ft_do_norminette(int *i, int *max, int *sorted_array)
{
	if (*i)
	{
		*max = sorted_array[*i];
		(*i)--;
	}
	else
		*max = sorted_array[0];
}

void	ft_push_rotate(t_stack **a, t_stack **b)
{
	ft_push(a, b, 'b');
	ft_rotate(b, 'b');
}
