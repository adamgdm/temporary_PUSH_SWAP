/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:25:26 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/07 00:48:58 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*ft_free_str(char *str)
{
	free(str);
	return (0);
}

void	ft_do_this(t_stack **b, int size, int max)
{
	int		i;
	t_stack	*a;

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

int	ft_find_max_in_s(t_stack **a, int max)
{
	t_stack	*lol;

	lol = (*a);
	while (lol)
	{
		if (lol->value == max)
			return (1);
		lol = lol->next;
	}
	return (0);
}

t_var	ft_intialize_variables(t_stack **a, t_stack **b, int argc)
{
	t_var	x;

	(void)a;
	(void)b;
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
