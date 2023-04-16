#include "pushswap.h"

int ft_split_arguments(int index, char *str, int i, int current_index)
{
    indexes xa;

    xa.len = ft_strlen(str);
    while (str[i])
    {
        if (str[i] == ' ')
            i++;
        else if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '+' || str[i] == '-'))
        {
            current_index++;
            xa.start = i;
            while ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' || str[i] == '+'))
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

void printLinkedList(stack* head) 
{
    stack* current = head;
    printf("Printing the linked list:\n");
    while(current != NULL) {
        printf("value :%d\nprev: %p\nnext: %p\n", current->value, (void*)current->previous, (void*)current->next);
        printf("\n");
        current = current->next;
    }
}

/*void ft_fill_stack(stack **a, int arg)
{
    stack *node;
    stack *current;

    node = (stack *)malloc(sizeof(stack));
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
}*/
void ft_fill_stack(stack **a, int arg)
{
    stack *node;
    stack *current;

    node = (stack *)malloc(sizeof(stack));
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


stack *ft_create_the_stack(int argc, char *args)
{
    int index;
    stack **stack_a;

    stack_a = (stack**) malloc(sizeof(stack*));
    if (!stack_a)
        return (0);
    *stack_a = NULL;
    index = 1;
    while (index <= argc)
    {
        ft_fill_stack(stack_a, ft_split_arguments(index, args, 0, 0));
        index++;
    }
    return (*stack_a);
}
