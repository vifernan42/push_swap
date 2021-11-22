/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_notus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:01:51 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/22 18:00:21 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	ft_double_up2(t_list *stack_b, t_element *element1b
		, t_element *element9b)
{
	stack_b->first = element1b->next;
	stack_b->last = element1b;
	element1b->next->prev = NULL;
	element1b->prev = element9b;
	element9b->next = element1b;
	element1b->next = NULL;
}

void	ft_double_up(t_list *stack_a, t_list *stack_b)
{
	t_element	*element1a;
	t_element	*element9a;
	t_element	*element1b;
	t_element	*element9b;

	element1a = stack_a->first;
	element9a = stack_a->last;
	element1b = stack_b->first;
	element9b = stack_b->last;
	if (stack_a->first && stack_a->first->next
		&& stack_b->first && stack_b->first->next)
	{
		stack_a->first = element1a->next;
		stack_a->last = element1a;
		element1a->next->prev = NULL;
		element1a->prev = element9a;
		element9a->next = element1a;
		element1a->next = NULL;
		ft_double_up2(stack_b, element1b, element9b);
		write(1, "rr\n", 3);
	}
}
