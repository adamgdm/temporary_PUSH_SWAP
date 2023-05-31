#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	struct stack	*previous;
	int				value;
	struct stack	*next;
}					stack;

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

typedef struct hehe
{
	int				start;
	int				finish;
	int				len;
}					indexes;

typedef struct lola
{
	int				How_many;
	int				min;
	int				max;
	int				chunck_current;
	int				Position;
	int				size;
	int				middle;
	int				offset;
	int				i;
	int				ac;
	int				argc;
	stack			*boghdnan;
	stack			*iter;
}					t_var;

int					ft_get_offset(int argc);
int					ft_get_min(stack **a, int last_min);

int					ft_check_sort(stack **a);
char				*ft_check_numbers(char *str, int i, int j);
char				*ft_check_morethanmaxint(char *str, int i, int start,
						int len);
char				*ft_checkrepetition(char *str, int ac);
char				*ft_joinandcheck(int argc, char **argv);
int					ft_strlen(char *str);
char				*ft_strcat(char *dest, const char *src);
char				*ft_substr(char *str, int start, int finish);
long long			ft_atoll(char *str, long long res, long long sign,
						size_t i);
void				*ft_calloc(size_t count, size_t size);
char				*ft_join_arguments(int argc, char **argv);
int					*ft_get_values(char *str, int ac, int index, int i);
int					ft_split_arguments(int index, char *str, int i,
						int current_index);
int					ft_arguments_count(char *str);
void				printLinkedList(stack *head);
void				ft_fill_stack(stack **a, int arg);
stack				*ft_create_the_stack(int argc, char *args);

int					ft_find_min(stack **s);
int					ft_find_max(stack **s);
int					ft_find_min_index(stack **s);
int					ft_find_min_num(stack **s);
int					ft_find_max_num(stack **s);
int					ft_count_linkedlist_elements(stack *head);

void				ft_swap(stack **s, char c);
void				ft_rotate(stack **s, char c);
void				ft_push(stack **a, stack **b, char c);
void				ft_reverse_rotate(stack **s, char c);
void				ft_ss(stack **a, stack **b);
void				ft_rr(stack **a, stack **b);
void				ft_rrr(stack **a, stack **b);

stack				*ft_sort_stack(stack **arguments, stack **b, stack **c);
stack				*ft_sort_two(stack **a);
stack				*ft_sort_three(stack **a);
stack				*ft_sort_five(stack **a, stack **b, int argc, int index);
stack				*ft_sort_more(stack **a, stack **b, int argc);

int					ft_find_chunk_min(stack **s, int chunk_nums, int what_chunk,
						int total);
int					ft_find_chunk_max(stack **s, int chunk_nums, int what_chunk,
						int total);
int					ft_find_max_two(stack **s, int ma);
void				ft_rotate_b_elements(stack **b);

#endif