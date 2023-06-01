/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:49:03 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/01 04:26:03 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Checker.h"

void	ft_push(t_stack **a, t_stack **b, char c)
{
	t_stack	*pointer;

	if (!(*a))
		return ;
	pointer = (*a)->next;
	if (pointer)
		pointer->previous = NULL;
	if (*a == *b)
		*b = NULL;
	if (*b)
	{
		(*a)->next = (*b);
		(*b)->previous = (*a);
	}
	else
		(*a)->next = NULL;
	(*b) = (*a);
	(*a) = pointer;
	if (*a)
		(*a)->previous = NULL;
}
