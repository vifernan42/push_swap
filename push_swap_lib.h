/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:13:40 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/22 18:01:22 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_element {
	int					num;
	struct s_element	*next;
	struct s_element	*prev;
}	t_element;

typedef struct s_list {
	char		id;
	t_element	*first;
	t_element	*last;
	int			size;
}	t_list;

/* --- utils --- */
int		ft_pos_down(t_list *stack, int n);
int		ft_min_value(t_list *stack);
int		ft_max_value(t_list *stack);
int		ft_size_stack(t_list *stack);
void	ft_check_size(t_list *stack_a, t_list *stack_b);
int		ft_min_dist(t_list *stack, int n);

/* --- moves ---*/
void	ft_swap(t_list *stack);
void	ft_double_swap(t_list *stack_a, t_list *stack_b);
void	ft_push(t_list *stack_a, t_list *stack_b);
void	ft_rotate_up(t_list *stack);
void	ft_rotate_down(t_list *stack);
void	ft_double_up(t_list *stack_a, t_list *stack_b);
void	ft_double_down(t_list *stack_a, t_list *stack_b);
void	print_stack(t_list *stack_a, t_list *stack_b);

/* --- algorithm --- */
int		ft_check_end(t_list *stack_a);
int		ft_mid_point(t_list *stack_a, int size);
int		*ft_sort_int_tab(int *tab, int size);
void	ft_three_rd(t_list *stack_a);
void	ft_b2a_max(t_list *stack_a, t_list *stack_b, t_element *element);
void	ft_b2a_min(t_list *stack_a, t_list *stack_b, t_element *element);
int		ft_mid_size(t_list *stack_a);
void	ft_b2a(t_list *stack_a, t_list *stack_b);
void	ft_a2b(t_list *stack_a, t_list *stack_b, int count);
void	ft_mid_al(t_list *stack_a, t_list *stack_b, int flag);

/* --- fill --- */
int		ft_fill_a(t_list *stack_a, int val);
int		ft_norepeet(t_list *stack_a, int val);
void	ft_fill_stack(char *temp, t_list *stack_a);
void	ft_check(char *temp, t_list *stack_a);

#endif
