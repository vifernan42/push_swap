/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:14:41 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/22 14:30:28 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

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

int	ft_min_value(t_list *stack)
{
	t_element	*element;
	int			n;

	element = stack->first;
	n = INT_MAX;
	while (element)
	{
		if (element->num < n)
			n = element->num;
		element = element->next;
	}
	return (n);
}

int	ft_pos_down(t_list *stack, int n)
{
	t_element	*element;
	int			i;

	element = stack->first;
	i = 1;
	while (element)
	{
		if (element->num == n)
			break ;
		element = element->next;
		i++;
	}
	return (i);
}

int	ft_min_dist(t_list *stack, int n)
{
	int	p;
	int	dist;

	p = ft_pos_down(stack, n);
	dist = ft_size_stack(stack) - p;
	if (p > dist)
		return (dist);
	return (p);
}

int	ft_max_value(t_list *stack)
{
	t_element	*element;
	int			n;

	element = stack->first;
	n = INT_MIN;
	while (element)
	{
		if (element->num > n)
			n = element->num;
		element = element->next;
	}
	return (n);
}
