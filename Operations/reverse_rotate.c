/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:46:49 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/01 05:45:20 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_reverse_rotate(t_stack **s, char c)
{
	t_stack	*a;
	t_stack	*last;
	int		argc;

	argc = ft_count_linkedlist_elements(*s);
	if (argc > 1)
	{
		last = *s;
		while (last->next)
			last = last->next;
		a = last->previous;
		a->next = NULL;
		last->next = (*s);
		last->previous = NULL;
		(*s)->previous = last;
		(*s) = last;
		ft_printf("rr%c\n", c);
	}
}
