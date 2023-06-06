/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 03:14:28 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/06 01:13:38 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "GET_NEXT_LINE/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>

typedef struct t_stack
{
	struct t_stack	*previous;
	int				value;
	struct t_stack	*next;
}					t_stack;

typedef struct t_lol
{
	int				ac;
	char			*args;
}					t_alements;

typedef struct t_elemo
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

typedef struct t_elem
{
	int				first;
	int				second;
	int				third;
}					t_elements;

typedef struct t_ind
{
	int				start;
	int				finish;
	int				len;
}					t_indexes;

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

char				*ft_strcat(char *dest, const char *src);
long long			ft_atoll(char *str, long long res, long long sign,
						size_t i);
void				*ft_calloc(size_t count, size_t size);

int					ft_str(char *str1, char *str2);
void				ft_handle_more_cases(char *cmp, t_stack **a, t_stack **b);
void				ft_handle_this(char *cmp, t_stack **a, t_stack **b);

char				*ft_join_arguments(int argc, char **argv);
int					ft_arguments_count(char *str);
int					*ft_get_values(char *str, int ac, int index, int i);
int					ft_find_min(t_stack **s);
int					ft_find_max_two(t_stack **s, int ma);

int					ft_find_max(t_stack **s);
int					ft_find_min_num(t_stack **s);
int					ft_find_max_num(t_stack **s);
int					ft_check_sort(t_stack **a);
char				*ft_free_str(char *str);

int					ft_split_arguments(int index, char *str, int i,
						int current_index);
void				ft_fill_t_stack(t_stack **a, int arg);
t_stack				*ft_create_the_t_stack(int argc, char *args);

#endif