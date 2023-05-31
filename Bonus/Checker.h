#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "GET_NEXT_LINE/get_next_line.h"
# include <stdio.h>
# include <unistd.h>

typedef struct stack
{
	struct stack	*previous;
	int				value;
	struct stack	*next;
}					stack;

typedef struct lol
{
	int				ac;
	char			*args;
}					alements;

typedef struct elemo
{
	int				n;
	int				middle;
	int				offset;
	int				start;
	int				end;
	stack			*current;
	int				how_many;
	stack			**hehe;
}					t_ints;

typedef struct elem
{
	int				first;
	int				second;
	int				third;
}					elements;

typedef struct
{
	int				start;
	int				finish;
	int				len;
}					indexes;

void				ft_handle_this(char *str, stack **a, stack **b);
void				ft_handle_more_cases(char *str, stack **a, stack **b);

int					ft_split_arguments(int index, char *str, int i,
						int current_index);
void				ft_fill_stack(stack **a, int arg);
stack				*ft_create_the_stack(int argc, char *args);

char				*ft_join_arguments(int argc, char **argv);
int					ft_arguments_count(char *str);
int					*ft_get_values(char *str, int ac, int index, int i);
int					ft_find_min(stack **s);
int					ft_find_max_two(stack **s, int ma);
int					ft_find_max(stack **s);
int					ft_find_min_num(stack **s);
int					ft_find_max_num(stack **s);
int					ft_check_sort(stack **a);

char				*ft_check_numbers(char *str, int i, int j);
char				*ft_check_morethanmaxint(char *str, int i, int start,
						int len);
char				*ft_checkrepetition(char *str, int ac);
char				*ft_joinandcheck(int argc, char **argv);
int					ft_count_linkedlist_elements(stack *head);
int					ft_str(char *str1, char *str2);

char				*ft_strcat(char *dest, const char *src);
long long			ft_atoll(char *str, long long res, long long sign,
						size_t i);
void				*ft_calloc(size_t count, size_t size);

void				ft_ss(stack **a, stack **b);
void				ft_rr(stack **a, stack **b);
void				ft_rrr(stack **a, stack **b);
void				ft_push(stack **a, stack **b, char c);
void				ft_reverse_rotate(stack **s, char c);
void				ft_rotate(stack **s, char c);
void				ft_swap(stack **s, char c);

#endif