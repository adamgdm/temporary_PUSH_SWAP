#include "pushswap.h"

int main(int argc, char** argv)
{
    stack *arguments;
    stack *b;
    int ac;
    char *args;

    if (!ft_joinandcheck(argc, argv))
    {
        printf("Error\n");
        return (0);
    }
    else
    {
        args = ft_join_arguments(argc, argv);
        ac = ft_arguments_count(args);
        arguments = ft_create_the_stack(ac, args);
       // if (!ft_check_sort(&arguments))
         //   arguments = ft_sort_stack(&arguments, &b);
        printf("%d\n", ft_find_chunk_min(&arguments,5,1,100));
    }
}