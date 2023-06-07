/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:36:39 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/07 05:39:14 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*arguments;
	t_stack	*b;
	int		ac;
	char	*args;

	args = ft_joinandcheck(argc, argv);
	if (!args)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else
	{
		ac = ft_arguments_count(args);
		arguments = ft_create_the_t_stack(ac, args);
		if (!ft_check_sort(&arguments))
			arguments = ft_sort_t_stack(&arguments, &b);
	}
	return (0);
}
