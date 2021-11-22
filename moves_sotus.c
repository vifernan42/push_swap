/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_sotus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:26:41 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/22 18:00:31 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	ft_double_swap2(t_list *stack_b)
{
	t_element	*element1b;
	t_element	*element2b;

	element1b = stack_b->first;
	element2b = element1b->next;
	element1b->next = element2b->next;
	element1b->next->prev = element1b;
	element1b->prev = element2b;
	element1b->prev = NULL;
	stack_b->first = element2b;
	stack_b->first->next = element1b;
}

void	ft_double_swap(t_list *stack_a, t_list *stack_b)
{
	t_element	*element1a;
	t_element	*element2a;

	if (stack_a->first && stack_b->first
		&& stack_a->first->next && stack_b->first->next)
	{
		element1a = stack_a->first;
		element2a = element1a->next;
		element1a->next = element2a->next;
		element1a->next->prev = element1a;
		element1a->prev = element2a;
		element1a->prev = NULL;
		stack_a->first = element2a;
		stack_a->first->next = element1a;
		ft_double_swap2(stack_b);
		write(1, "ss\n", 3);
	}
}
