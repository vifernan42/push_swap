/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:12:37 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/22 13:48:23 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	ft_mid_size(t_list *stack_a)
{
	int	mid_size;

	if (ft_size_stack(stack_a) > 100)
		mid_size = ft_size_stack(stack_a) / 11;
	else
		mid_size = ft_size_stack(stack_a) / 2;
	return (mid_size);
}

void	ft_a2b(t_list *stack_a, t_list *stack_b, int count)
{
	int			mid_size;
	int			mid_point;
	t_element	*element;
	t_element	*last;

	while (ft_size_stack(stack_a) > 2)
	{
		mid_point = ft_mid_point(stack_a, ft_size_stack(stack_a));
		mid_size = ft_mid_size(stack_a);
		count = 0;
		while (count < mid_size)
		{
			element = stack_a->first;
			last = stack_a->last;
			if (element->num < mid_point && ++count)
				ft_push(stack_a, stack_b);
			else if (last->num < mid_point)
				ft_rotate_down(stack_a);
			else
				ft_rotate_up(stack_a);
		}
	}
}
