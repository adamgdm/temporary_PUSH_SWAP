#include "pushswap.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strcat(char *dest, const char *src) 
{
    int dest_len;
    int i;

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
    return dest;
}

char *ft_substr(char *str, int start, int finish)
{
    char *result;
    int i = start;
    int j = 0;
    int len = finish - start;

    result = malloc(len + 1);
    while (i < finish)
    {
        result[j] = str[i];
        i++;
        j++;
    }
    result[j] = '\0';

    return result;
}

long long   ft_atoll(char *str, long long res, long long sign, size_t i)
{
    int count;

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
    free (str);
    return (res * sign);
}

void* ft_calloc(size_t count, size_t size) 
{
    void*   ptr;
    char*   cptr;
    size_t  i;

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
    return ptr;
}