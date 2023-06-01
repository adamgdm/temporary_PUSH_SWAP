/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:44:55 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/01 05:33:55 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_sort_two(t_stack **a)
{
	t_stack	*b;
	int		first;
	int		second;

	b = *a;
	first = b->value;
	b = b->next;
	second = b->value;
	if (first > second)
		ft_rotate(a, 'a');
	return (*a);
}

t_stack	*ft_sort_three(t_stack **a)
{
	t_stack		*b;
	t_elements	x;

	b = *a;
	x.first = b->value;
	x.second = b->next->value;
	x.third = b->next->next->value;
	if (x.first > x.second && x.second > x.third && x.first > x.third)
	{
		ft_swap(a, 'a');
		ft_reverse_rotate(a, 'a');
	}
	else if (x.first < x.second && x.second > x.third && x.first < x.third)
	{
		ft_reverse_rotate(a, 'a');
		ft_swap(a, 'a');
	}
	else if (x.first > x.second && x.second < x.third && x.first > x.third)
		ft_rotate(a, 'a');
	else if (x.first > x.second && x.second < x.third && x.first < x.third)
		ft_swap(a, 'a');
	else if (x.first < x.second && x.second > x.third && x.first > x.third)
		ft_reverse_rotate(a, 'a');
	return (*a);
}

t_stack	*ft_sort_five(t_stack **a, t_stack **b, int argc, int index)
{
	int	i;
	int	j;

	i = argc - 3;
	j = i;
	while (i)
	{
		index = ft_find_min_index(a);
		while (index % argc != 1)
			ft_rraoorra(a, &index);
		ft_push(a, b, 'b');
		if (argc == 5)
			argc--;
		i--;
	}
	ft_sort_three(a);
	while (j)
	{
		ft_push(b, a, 'a');
		j--;
	}
	return (*a);
}

t_stack	*ft_sort_t_stack(t_stack **arguments, t_stack **b, t_stack **c)
{
	int		argument_count;
	t_ints	element;

	element.hehe = c;
	argument_count = ft_count_linkedlist_elements(*arguments);
	if (argument_count == 2)
		return (ft_sort_two(arguments));
	if (argument_count == 3)
		return (ft_sort_three(arguments));
	if (argument_count == 4 || argument_count == 5)
		return (ft_sort_five(arguments, b, argument_count, 0));
	if (argument_count > 5)
		return (ft_sort_more(arguments, b, argument_count));
	return (*arguments);
}

void	ft_rraoorra(t_stack **a, int *index)
{
	if ((*index) > 2)
	{
		ft_reverse_rotate(a, 'a');
		(*index)++;
	}
	else
	{
		ft_rotate(a, 'a');
		(*index)--;
	}
}
