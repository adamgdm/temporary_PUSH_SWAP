#include "pushswap.h"

int	ft_find_max(stack **s)
{
	stack	*a;
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
		if (a->value > max)
		{
			max = a->value;
			index = i;
		}
	}
	return (max);
}

int	ft_find_min_num(stack **s)
{
	stack	*a;
	int		max;

	a = (*s);
	max = a->value;
	while (a->next)
	{
		a = a->next;
		if (a->value < max)
		{
			max = a->value;
		}
	}
	return (max);
}

int	ft_find_max_num(stack **s)
{
	stack	*a;
	int		max;

	a = (*s);
	max = a->value;
	while (a->next)
	{
		a = a->next;
		if (a->value > max)
		{
			max = a->value;
		}
	}
	return (max);
}

int	ft_check_sort(stack **a)
{
	stack	*current;

	if (!(*a))
		return (1);
	current = (*a);
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_find_min_index(stack **s)
{
	stack *a;
	int i;
	int index;
	int max;

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
	return (index);
}