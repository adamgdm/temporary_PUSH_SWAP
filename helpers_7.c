/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:09:07 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/07 06:58:21 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_do_more(int *i, t_stack **a, t_stack **b)
{
	if (*i <= 0)
		*i = 0;
	ft_push(b, a, 'a');
}

int	ft_get_last_node(t_stack **a, int max, int min)
{
	t_stack	*as;

	if (!a)
		return (0);
	as = *a;
	while (as)
	{
		if (as->value == max)
			break ;
		as = as->next;
		min++;
	}
	if (!as)
		return (min);
	min = 0;
	while (as->next)
	{
		if (as->next)
		{
			min++;
			as = as->next;
		}
	}
	return (min);
}
