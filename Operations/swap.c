/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:47:39 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/01 05:45:20 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_swap(t_stack **s, char c)
{
	t_stack	*a;
	int		argc;

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
	ft_printf("s%c\n", c);
}
