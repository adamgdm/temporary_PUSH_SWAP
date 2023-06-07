/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 04:29:53 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/07 05:38:43 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_split_arguments(int index, char *str, int i, int current_index)
{
	t_indexes	xa;

	xa.len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '+'
				|| str[i] == '-'))
		{
			current_index++;
			xa.start = i;
			while ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-'
					|| str[i] == '+'))
			{
				i++;
				if (str[i] == ' ' || !(i < xa.len))
					break ;
			}
			xa.finish = i;
			if (current_index == index)
				break ;
		}
	}
	return (ft_atoll(ft_substr(str, xa.start, xa.finish), 0, 1, 0));
}
/*
void	printLinkedList(t_stack* head) 
{
    t_stack* current = head;
    //ft_printf("Printing the linked list:\n");
    while(current != NULL) {
        ft_printf("%d\n",current->value);
        //ft_printf("value :%d\nprev: %p\nnext: %p\n", current->value,
		(void*)current->previous, (void*)current->next);
        //ft_printf("\n");
        current = current->next;
    }
}*/

void	ft_fill_t_stack(t_stack **a, int arg)
{
	t_stack	*node;
	t_stack	*current;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->value = arg;
	node->next = NULL;
	if (!(*a))
	{
		node->previous = NULL;
		*a = node;
	}
	else
	{
		current = *a;
		while (current->next)
			current = current->next;
		node->previous = current;
		current->next = node;
	}
}

t_stack	*ft_create_the_t_stack(int argc, char *args)
{
	int		index;
	t_stack	*t_stack_a;

	t_stack_a = NULL;
	index = 1;
	while (index <= argc)
	{
		ft_fill_t_stack(&t_stack_a, ft_split_arguments(index, args, 0, 0));
		index++;
	}
	return (t_stack_a);
}
