#include "Checker.h"

int	main(int argc, char **argv)
{
	stack *a;
	stack *b;
	alements e;
	char *s;

	if (!ft_joinandcheck(argc, argv))
		printf("Error\n");
	else
	{
		e.args = ft_join_arguments(argc, argv);
		e.ac = ft_arguments_count(e.args);
		a = ft_create_the_stack(e.ac, e.args);
		s = get_next_line(0);
		while (s)
		{
			ft_handle_this(s, &a, &b);
			free(s);
			s = get_next_line(0);
		}
		if (s)
			free(s);
		if (ft_check_sort(&a) == 1)
			printf("OK\n");
		else
			printf("KO\n");
	}
}