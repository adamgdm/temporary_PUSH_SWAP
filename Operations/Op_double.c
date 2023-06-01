/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Op_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:45:45 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/01 04:26:03 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a, 'a');
	ft_swap(b, 'b');
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a, 'a');
	ft_rotate(b, 'b');
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a, 'a');
	ft_reverse_rotate(b, 'b');
}
