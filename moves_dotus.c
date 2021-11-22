/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_dotus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:24:29 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/22 18:00:05 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	ft_double_down2(t_list *stack_b
		, t_element	*element1b, t_element	*element9b)
{
	stack_b->first = element9b;
	stack_b->last = element9b->prev;
	element1b->prev = element9b;
	element9b->prev->next = NULL;
	element9b->prev = NULL;
	element9b->next = element1b;
}

void	ft_double_down(t_list *stack_a, t_list *stack_b)
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
		stack_a->first = element9a;
		stack_a->last = element9a->prev;
		element1a->prev = element9a;
		element9a->prev->next = NULL;
		element9a->prev = NULL;
		element9a->next = element1a;
		ft_double_down2(stack_b, element1b, element9b);
		write(1, "rrr\n", 4);
	}
}
