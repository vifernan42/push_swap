/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:13:40 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/16 15:43:24 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIB_H
#define PUSH_SWAP_LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_element {
	int num;
	struct s_element *next;
	struct s_element *prev;
}				t_element;

typedef struct s_list {
	char	id;
	t_element *first;
	t_element *last;
	int  size;
}				t_list;

void	ft_swap(t_list *stack);
void	ft_double_swap(t_list *stack_a, t_list *stack_b);
void	ft_push(t_list *stack_a, t_list *stack_b);
void	ft_rotate_up(t_list *stack);
void	ft_rotate_down(t_list *stack);
void	ft_double_up(t_list *stack_a, t_list *stack_b);
void	ft_double_down(t_list *stack_a, t_list *stack_b);
int		ft_mid_point(t_list *stack_a);
void	ft_mid_al(t_list *stack_a, t_list *stack_b);


#endif
