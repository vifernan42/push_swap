/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:04:58 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/22 19:24:48 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	ft_first_push(t_list *stack_out, t_list *stack_in)
{
	t_element	*element;

	element = stack_out->first;
	if (element->next)
	{
		element->next->prev = NULL;
		stack_out->first = element->next;
	}
	else
		stack_out->first = NULL;
	element->next = NULL;
	element->prev = NULL;
	stack_in->first = element;
	stack_in->last = element;
}

void	ft_last_push(t_list *stack_out, t_list *stack_in)
{
	t_element	*element;
	t_element	*element9;

	element9 = stack_out->first;
	element = stack_in->first;
	element9->next = element;
	element9->prev = NULL;
	element->prev = element9;
	stack_in->first = element9;
	stack_out->first = NULL;
	stack_out->last = NULL;
}

void	ft_push_it(t_list *stack_out, t_list *stack_in)
{
	t_element	*element1;
	t_element	*element2;

	element1 = stack_out->first;
	element2 = stack_in->first;
	element1->next->prev = NULL;
	stack_out->first = element1->next;
	element2->prev = element1;
	element1->next = element2;
	element1->prev = NULL;
	stack_in->first = element1;
}

void	ft_push(t_list *stack_out, t_list *stack_in)
{
	if (stack_out->first)
	{
		if (!stack_in->first)
			ft_first_push(stack_out, stack_in);
		else
		{
			if (stack_out->first && !stack_out->first->next)
				ft_last_push(stack_out, stack_in);
			else
				ft_push_it(stack_out, stack_in);
		}
		if (stack_in->id == 'a')
			write(1, "pa\n", 3);
		else
			write(1, "pb\n", 3);
	}
}
