#include "pushswap.h"
#include <stdlib.h>

char* ft_check_numbers(char* str, int i, int j) 
{
    while (i < j)
    {
        if (str[i] == '-' || str[i] == '+')
        {
            if (i + 1 < j)
            {
                if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
                    return (0);
                if (i != 0)
                {
                    if (str[i - 1] != ' ')
                        return (0);
                }
            }
            else
                return (0);
        }
        else if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
            return (0);
        i++;
    }
    return (str);
}

char *ft_check_morethanmaxint(char *str, int i, int start, int len)
{
    long long number;

    len = ft_strlen(str);
    while (i < len)
    {
        if (str[i] == ' ')
            i++;
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' || str[i] == '+'))
        {    
            start = i;
            while ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' || str[i] == '+'))
            {
                i++;
                if (str[i] == ' ' || !(i < len))
                    break ;
            }
        }
        number = i;
        number = ft_atoll(ft_substr(str, start, number), 0, 1, 0);
        if (number > 2147483647 || number < -2147483648)
        {
            free (str);
            return (0);
        }
    }
    return (str);
}

char *ft_checkrepetition(char *str, int ac) 
{
    int *list;
    int i;
    int j;
    
    list = ft_get_values(str, ac, 0, 0);

    i = 0;
    j = 0;
    while (i < ac)
    {
        j = 0;
        while (j < ac)
        {
            if (list[i] == list[j] && j != i) 
            {
                free(str);
                free(list);
                return (0);
            }
            j++;
        }
        i++;
    }
    free(list);
    return (str);
}

char *ft_joinandcheck(int argc, char** argv)
{
    char *fre;
    char *arguments;
    int argument_count;
    arguments = ft_join_arguments(argc, argv);
    if (!arguments)
        return (0);
    fre = arguments;
    arguments = ft_check_numbers(arguments, 0, ft_strlen(arguments));
    if (!arguments)
    {
        free (fre);
        return (0);
    }
    arguments = ft_check_morethanmaxint(arguments, 0, 0, 0);
    if (!arguments)
        return (0);
    argument_count = ft_arguments_count(arguments);
    arguments = ft_checkrepetition(arguments, argument_count);
    return (arguments);
}
