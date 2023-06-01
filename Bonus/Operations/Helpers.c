/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:48:25 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/01 04:26:03 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Checker.h"

int	ft_count_linkedlist_elements(t_stack *head)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = head;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
