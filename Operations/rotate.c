/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:47:12 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/01 05:45:20 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_rotate(t_stack **s, char c)
{
	t_stack	*a;
	t_stack	*last;
	int		argc;

	argc = ft_count_linkedlist_elements(*s);
	if (argc > 1)
	{
		a = *s;
		last = *s;
		while (last->next)
			last = last->next;
		while (a->next)
			a = a->next;
		last->next = (*s);
		(*s) = (*s)->next;
		(*s)->previous = NULL;
		last = last->next;
		last->next = NULL;
		last->previous = a;
		ft_printf("r%c\n", c);
	}
}
