#include "Checker.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	dest_len;
	int	i;

	dest_len = 0;
	i = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

long long	ft_atoll(char *str, long long res, long long sign, size_t i)
{
	int	count;

	count = 0;
	while (str[i] == ' ' || str[i] == '\t' ||
			str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((count < 11) && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		count++;
		i++;
	}
	free(str);
	return (res * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*cptr;
	size_t	i;

	ptr = malloc(count * size);
	if (ptr != NULL)
	{
		cptr = ptr;
		i = 0;
		while (i < count * size)
		{
			*(cptr + i) = 0;
			i++;
		}
	}
	return (ptr);
}

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

void	ft_handle_more_cases(char *cmp, stack **a, stack **b)
{
	if (!ft_str(cmp, "ss\n"))
		ft_ss(a, b);
	else if (!ft_str(cmp, "rr\n"))
		ft_rr(a, b);
	else if (!ft_str(cmp, "rrr\n"))
		ft_rrr(a, b);
	else
	{
		printf("KO\n");
		exit(0);
	}
}

void	ft_handle_this(char *cmp, stack **a, stack **b)
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
}