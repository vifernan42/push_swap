/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:13:42 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/29 16:28:53 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	ft_b2a_max(t_list *stack_a, t_list *stack_b, t_element *element)
{
	while (1)
	{
		element = stack_b->first;
		if (element->num == ft_max_value(stack_b))
		{
			ft_push(stack_b, stack_a);
			break ;
		}
		else
		{
			if (ft_pos_down(stack_b,
					ft_max_value(stack_b)) <= ft_size_stack(stack_b) / 2)
				ft_rotate_up(stack_b);
			else
				ft_rotate_down(stack_b);
		}
	}
}

void	ft_b2a_min(t_list *stack_a, t_list *stack_b, t_element *element)
{
	while (1)
	{
		element = stack_b->first;
		if (element->num == ft_min_value(stack_b))
		{
			ft_push(stack_b, stack_a);
			ft_rotate_up(stack_a);
			break ;
		}
		else
		{
			if (ft_pos_down(stack_b,
					ft_min_value(stack_b)) <= ft_size_stack(stack_b) / 2)
				ft_rotate_up(stack_b);
			else
				ft_rotate_down(stack_b);
		}
	}
}

void	ft_five(t_list *stack_a, t_list *stack_b)
{
	t_element	*element;

	element = stack_b->first;
	if (ft_size_stack(stack_b) == 1)
		ft_push(stack_b, stack_a);
	else
		ft_b2a_max(stack_a, stack_b, element);
}

void	ft_more(t_list *stack_a, t_list *stack_b)
{
	t_element	*element;

	element = stack_b->first;
	if (ft_size_stack(stack_b) == 1)
		ft_push(stack_b, stack_a);
	else if (ft_min_dist(stack_b,
			ft_min_value(stack_b) >= ft_min_dist(stack_b,
				ft_max_value(stack_b))))
		ft_b2a_max(stack_a, stack_b, element);
	else
		ft_b2a_min(stack_a, stack_b, element);
}

void	ft_b2a(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->size <= 12)
		ft_five(stack_a, stack_b);
	else
		ft_five(stack_a, stack_b);
}
