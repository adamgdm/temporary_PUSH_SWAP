/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:36:39 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/01 05:45:20 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*arguments;
	t_stack	*b;
	t_stack	*t_stack_double;
	int		ac;
	char	*args;

	if (!ft_joinandcheck(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	else
	{
		args = ft_join_arguments(argc, argv);
		ac = ft_arguments_count(args);
		arguments = ft_create_the_t_stack(ac, args);
		t_stack_double = ft_create_the_t_stack(ac, args);
		if (!ft_check_sort(&arguments))
			arguments = ft_sort_t_stack(&arguments, &b, &t_stack_double);
	}
	return (0);
}
