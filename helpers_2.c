/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:20:33 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/01 04:58:03 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*ft_join_arguments(int argc, char **argv)
{
	int		total_length;
	int		i;
	char	*joined_str;

	total_length = 0;
	i = 0;
	while (i < argc)
	{
		total_length += ft_strlen(argv[i]) + 1;
		i++;
	}
	joined_str = (char *)ft_calloc(total_length, sizeof(char));
	if (!joined_str)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		ft_strcat(joined_str, argv[i]);
		if (i < argc - 1)
			ft_strcat(joined_str, " ");
		i++;
	}
	return (joined_str);
}

int	ft_arguments_count(char *str)
{
	long long	number;
	int			i;
	int			len;

	len = ft_strlen(str);
	i = 0;
	number = 0;
	if (!str)
		return (0);
	while (i < len)
	{
		if (str[i] == ' ')
			i++;
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-'
				|| str[i] == '+'))
		{
			number++;
			if (str[i] == '-' || str[i] == '+')
				i++;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
	}
	return (number);
}

int	*ft_get_values(char *str, int ac, int index, int i)
{
	int	*list;
	int	start;
	int	finish;
	int	len;

	list = malloc(sizeof(int) * ac);
	if (!list)
		return ((int *)ft_free_str(str));
	len = ft_strlen(str);
	while (i < len)
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-'
				|| str[i] == '+'))
		{
			start = i;
			while (str[i] != ' ' && i != len)
				i++;
			finish = i;
			list[index] = ft_atoll(ft_substr(str, start, finish), 0, 1, 0);
			index++;
		}
		i++;
	}
	return (list);
}

int	ft_find_min(t_stack **s)
{
	t_stack	*a;
	int		i;
	int		index;
	int		max;

	i = 1;
	a = (*s);
	max = a->value;
	index = i;
	while (a->next)
	{
		a = a->next;
		i++;
		if (a->value < max)
		{
			max = a->value;
			index = i;
		}
	}
	return (max);
}

int	ft_find_max_two(t_stack **s, int ma)
{
	t_stack	*current;
	int		max;

	max = -1;
	current = *s;
	while (current != NULL)
	{
		if (current->value < ma && current->value > max)
		{
			max = current->value;
		}
		current = current->next;
	}
	return (max);
}
