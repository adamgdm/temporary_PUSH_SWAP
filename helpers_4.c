/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:23:34 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/01 04:26:03 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_last_t_stack(t_stack **head)
{
	t_stack	*current;

	current = *head;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}

int	check_last_max(t_stack *ll, int last_max, int max)
{
	if (!ll)
		return (last_max);
	if (ll->next == NULL && ll->value != last_max)
		return (last_max);
	while (ll->next)
	{
		if (ll->value == last_max)
			break ;
		ll = ll->next;
	}
	if ((ll->previous) == NULL)
		return (max);
	if ((ll->previous)->value == max)
		return (max);
	else
		return (last_max);
	return (last_max);
}

int	ft_count(t_stack *head)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	ft_get_min(t_stack **a, int last_min)
{
	t_stack	*s;
	int		min;

	s = (*a);
	min = 2147483647;
	while (s)
	{
		if (s->value < min && s->value > last_min)
			min = s->value;
		s = s->next;
	}
	return (min);
}

int	ft_get_offset(int argc)
{
	if (argc < 11)
		return (5);
	if (argc < 151)
		return (8);
	else
		return (15);
}
