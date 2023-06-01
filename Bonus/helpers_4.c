/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:59:35 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/01 04:26:03 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker.h"

int	ft_find_max(t_stack **s)
{
	t_stack	*a;
	int		i;
	int		index;
	int		max;

	i = 1;
	a = (*s);
	max = a->value;
	index = i;
	while (a->next)
	{
		a = a->next;
		i++;
		if (a->value > max)
		{
			max = a->value;
			index = i;
		}
	}
	return (max);
}

int	ft_find_min_num(t_stack **s)
{
	t_stack	*a;
	int		max;

	a = (*s);
	max = a->value;
	while (a->next)
	{
		a = a->next;
		if (a->value < max)
		{
			max = a->value;
		}
	}
	return (max);
}

int	ft_find_max_num(t_stack **s)
{
	t_stack	*a;
	int		max;

	a = (*s);
	max = a->value;
	while (a->next)
	{
		a = a->next;
		if (a->value > max)
		{
			max = a->value;
		}
	}
	return (max);
}

int	ft_check_sort(t_stack **a)
{
	t_stack	*current;

	if (!(*a))
		return (1);
	current = (*a);
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

char	*ft_free_str(char *str)
{
	free(str);
	return (0);
}
