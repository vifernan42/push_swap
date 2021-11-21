/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:20:52 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/21 01:41:02 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	ft_three_rd(t_list *stack_a)
{
	if (stack_a->first->num > stack_a->first->next->num &&
			stack_a->last->num > stack_a->first->next->num &&
			stack_a->first->num < stack_a->last->num)
		ft_swap(stack_a);
	else if (stack_a->first->num > stack_a->first->next->num &&
			stack_a->last->num < stack_a->first->next->num)
	{
		ft_swap(stack_a);
		ft_rotate_down(stack_a);
	}
	else if (stack_a->first->num > stack_a->first->next->num &&
			stack_a->last->num > stack_a->first->next->num &&
			stack_a->first->num > stack_a->last->num)
		ft_rotate_up(stack_a);
	else if (stack_a->first->num < stack_a->first->next->num &&
			stack_a->last->num < stack_a->first->next->num &&
			stack_a->first->num < stack_a->last->num)
	{
		ft_swap(stack_a);
		ft_rotate_up(stack_a);
	}
	else if (stack_a->first->num < stack_a->first->next->num &&
			stack_a->last->num < stack_a->first->next->num &&
			stack_a->first->num > stack_a->last->num)
		ft_rotate_down(stack_a);
}

void	ft_five_rd(t_list *stack_a, t_list *stack_b)
{
	ft_push(stack_a, stack_b);
	ft_push(stack_a, stack_b);
	ft_three_rd(stack_a);
	print_stack(stack_a, stack_b);
	if (stack_b->first->num < stack_b->last->num)
		ft_swap(stack_b);
	if (stack_b->first->num > stack_a->first->num && stack_b->first->num > stack_a->first->next->num && stack_b->first->num < stack_a->last->num)
	{
		ft_rotate_up(stack_a);
		ft_rotate_up(stack_a);
		ft_push(stack_b, stack_a);
		ft_push(stack_b, stack_a);
		ft_rotate_up(stack_a);
		ft_rotate_up(stack_a);
		ft_rotate_up(stack_a);
	}
}

int	ft_size_stack(t_list *stack)
{
	t_element	*element;
	int			i;

	element = stack->first;
	i = 0;
	while (element)
	{
		element = element->next;
		i++;
	}
	return (i);
}

void	ft_check_size(t_list *stack_a, t_list *stack_b)
{
	int size_stack;

	size_stack = ft_size_stack(stack_a);
	if (size_stack == 3)
		ft_three_rd(stack_a);
	else if (size_stack == 5)
		ft_five_rd(stack_a, stack_b);
}
