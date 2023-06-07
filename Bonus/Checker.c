/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:53:29 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/07 07:06:54 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_alements	e;
	char		*s;

	e.args = ft_joinandcheck(argc, argv);
	if (!e.args)
		write(2, "Error\n", 6);
	else
	{
		e.ac = ft_arguments_count(e.args);
		a = ft_create_the_t_stack(e.ac, e.args);
		s = get_next_line(0);
		while (s)
		{
			ft_handle_this(s, &a, &b);
			s = get_next_line(0);
		}
		if (ft_check_sort(&a) == 1 && a && (!b))
			ft_printf("OK\n");
		else if (!ft_check_sort(&a) || b)
			ft_printf("KO\n");
	}
}
