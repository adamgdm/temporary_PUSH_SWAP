/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:51:21 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/06 01:14:38 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Checker.h"

void	ft_reverse_rotate(t_stack **s, char c)
{
	t_stack	*a;
	t_stack	*last;
	int		argc;

	(void)c;
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
	}
}
