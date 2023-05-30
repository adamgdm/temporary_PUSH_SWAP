#include "../pushswap.h"

int ft_count_linkedlist_elements(stack* head) 
{
    int count;
    stack *current;

    count = 0;
    current = head;
    while (current) 
    {
        count++;
        current = current->next;
    }
    return (count);
}