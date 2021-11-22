/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:53:23 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/22 17:56:44 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	ft_swap(t_list *stack)
{
	t_element	*element1;
	t_element	*element2;

	if (stack->first && stack->first->next)
	{
		element1 = stack->first;
		element2 = element1->next;
		element1->prev = element2;
		element1->next = element2->next;
		if (element2->next)
			element1->next->prev = element1;
		stack->first = element2;
		stack->first->prev = NULL;
		stack->first->next = element1;
		if (stack->id == 'a')
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}

void	ft_rotate_up(t_list *stack)
{
	t_element	*element1;
	t_element	*element9;

	element1 = stack->first;
	element9 = stack->last;
	if (stack->first && stack->first->next)
	{
		stack->first = element1->next;
		stack->last = element1;
		element1->next->prev = NULL;
		element1->prev = element9;
		element9->next = element1;
		element1->next = NULL;
		if (stack->id == 'a')
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

void	ft_rotate_down(t_list *stack)
{
	t_element	*element1;
	t_element	*element9;

	element1 = stack->first;
	element9 = stack->last;
	if (stack->first && stack->first->next)
	{
		stack->first = element9;
		stack->last = element9->prev;
		element1->prev = element9;
		stack->last->next = NULL;
		element9->next = element1;
		if (stack->id == 'a')
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}
