/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:56:40 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/01 05:45:20 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker.h"

int	ft_str(char *str1, char *str2)
{
	int	index;

	index = 0;
	while (str1[index] == str2[index])
	{
		if (str1[index] == '\0')
			return (0);
		index++;
	}
	return (1);
}

void	ft_handle_more_cases(char *cmp, t_stack **a, t_stack **b)
{
	if (!ft_str(cmp, "ss\n"))
		ft_ss(a, b);
	else if (!ft_str(cmp, "rr\n"))
		ft_rr(a, b);
	else if (!ft_str(cmp, "rrr\n"))
		ft_rrr(a, b);
	else
	{
		ft_printf("KO\n");
		exit(0);
	}
}

void	ft_handle_this(char *cmp, t_stack **a, t_stack **b)
{
	if (!ft_str(cmp, "sa\n"))
		ft_swap(a, 'a');
	else if (!ft_str(cmp, "ra\n"))
		ft_rotate(a, 'a');
	else if (!ft_str(cmp, "rra\n"))
		ft_reverse_rotate(a, 'a');
	else if (!ft_str(cmp, "pa\n"))
		ft_push(b, a, 'a');
	else if (!ft_str(cmp, "sb\n"))
		ft_swap(b, 'b');
	else if (!ft_str(cmp, "rb\n"))
		ft_rotate(b, 'b');
	else if (!ft_str(cmp, "rrb\n"))
		ft_reverse_rotate(b, 'b');
	else if (!ft_str(cmp, "pb\n"))
		ft_push(a, b, 'b');
	else
		ft_handle_more_cases(cmp, a, b);
	free(cmp);
}
