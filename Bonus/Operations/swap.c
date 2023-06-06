/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:52:03 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/06 01:14:53 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Checker.h"

void	ft_swap(t_stack **s, char c)
{
	t_stack	*a;
	int		argc;

	(void)c;
	argc = ft_count_linkedlist_elements(*s);
	if (argc > 1)
	{
		a = *s;
		a = a->next;
		(*s)->previous = (*s)->next;
		(*s)->next = a->next;
		a->next = a->previous;
		a->previous = NULL;
		*s = a;
		if (argc > 2)
		{
			a = a->next;
			a = a->next;
			a->previous = (*s)->next;
		}
	}
}
