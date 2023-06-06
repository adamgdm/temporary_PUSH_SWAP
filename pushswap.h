/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 04:43:45 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/05 23:08:27 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf/ft_printf.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_tack
{
	struct s_tack	*previous;
	int				value;
	struct s_tack	*next;
}					t_stack;

typedef struct s_elemo
{
	int				n;
	int				middle;
	int				offset;
	int				start;
	int				end;
	t_stack			*current;
	int				how_many;
	t_stack			**hehe;
}					t_ints;

typedef struct s_elem
{
	int				first;
	int				second;
	int				third;
}					t_elements;

typedef struct s_hehe
{
	int				start;
	int				finish;
	int				len;
}					t_indexes;

typedef struct s_lola
{
	int				min;
	int				max;
	int				chunck_current;
	int				size;
	int				middle;
	int				offset;
	int				i;
	int				ac;
	int				argc;
	t_stack			*boghdnan;
	t_stack			*iter;
}					t_var;

int					ft_count_linkedlist_elements(t_stack *head);
void				ft_ss(t_stack **a, t_stack **b);
void				ft_rr(t_stack **a, t_stack **b);
void				ft_rrr(t_stack **a, t_stack **b);
void				ft_push(t_stack **a, t_stack **b, char c);
void				ft_reverse_rotate(t_stack **s, char c);
void				ft_rotate(t_stack **s, char c);
void				ft_swap(t_stack **s, char c);

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
int					ft_arguments_count(char *str);
int					*ft_get_values(char *str, int ac, int index, int i);
int					ft_find_min(t_stack **s);
int					ft_find_max_two(t_stack **s, int ma);

int					ft_find_max(t_stack **s);
int					ft_find_min_num(t_stack **s);
int					ft_find_max_num(t_stack **s);
int					ft_check_sort(t_stack **a);
int					ft_find_min_index(t_stack **s);

t_stack				*ft_last_t_stack(t_stack **head);
int					check_last_max(t_stack *ll, int last_max, int max);
int					ft_count(t_stack *head);
int					ft_get_min(t_stack **a, int last_min);
int					ft_get_offset(int argc);

char				*ft_free_str(char *str);
void				ft_do_this(t_stack **b, int size, int max);
int					ft_find_max_in_s(t_stack **a, int max);
t_var				ft_intialize_variables(t_stack **a, t_stack **b, int argc);
int					ft_add_remove_offset(int a, int offset, int argc, int b);

void				ft_redo_some_stuff(int *i, int *ac, int size);
int					*ft_sort_array(t_stack **a, int argc);
t_var				ft_do_that(t_stack **a, t_stack **b, t_var x);
void				ft_do_norminette(int *i, int *max, int *sorted_array);
void				ft_push_rotate(t_stack **a, t_stack **b);

int					ft_split_arguments(int index, char *str, int i,
						int current_index);
void				ft_fill_t_stack(t_stack **a, int arg);
t_stack				*ft_create_the_t_stack(int argc, char *args);

t_stack				*ft_sort_more(t_stack **a, t_stack **b, int argc);
void				ft_push_a_to_b(t_stack **a, t_stack **b, int *sorted_array,
						t_var x);
t_var				ft_intialize_variables_second(t_var x, int argc,
						t_stack **b);
t_var				handle_min_value(t_stack **a, int *sorted_array, t_var x);
t_var				handle_max_value(t_stack **a, t_stack **b,
						int *sorted_array, t_var x);

t_stack				*ft_sort_two(t_stack **a);
t_stack				*ft_sort_three(t_stack **a);
t_stack				*ft_sort_five(t_stack **a, t_stack **b, int argc,
						int index);
t_stack				*ft_sort_t_stack(t_stack **arguments, t_stack **b,
						t_stack **c);
void				ft_rraoorra(t_stack **a, int *i);

#endif