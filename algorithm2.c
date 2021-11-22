/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:59:25 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/22 19:21:47 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	*ft_sort_int_tab(int *tab, int size)
{
	int	save;
	int	i;
	int	j;

	j = 0;
	size--;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i + 1] < tab[i])
			{
				save = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = save;
			}
			i++;
		}
		j++;
	}
	return (tab);
}

int	ft_mid_point(t_list *stack_a, int size)
{
	t_element	*element;
	int			i;
	int			*arr_a;
	int			mid;

	element = stack_a->first;
	arr_a = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		arr_a[i] = element->num;
		element = element->next;
		i++;
	}
	arr_a = ft_sort_int_tab(arr_a, size);
	if (ft_size_stack(stack_a) > 100)
		mid = arr_a[size / 11];
	else
		mid = arr_a[size / 2];
	free(arr_a);
	return (mid);
}

int	ft_check_end(t_list *stack_a)
{
	t_element	*element;

	element = stack_a->first;
	while (element)
	{
		if (element->next != NULL)
		{
			if (element->num > element->next->num)
				return (1);
		}
		element = element->next;
	}
	return (0);
}

void	ft_three_rd(t_list *stack_a)
{
	if (stack_a->first->num > stack_a->first->next->num
		&& stack_a->last->num > stack_a->first->next->num
		&& stack_a->first->num < stack_a->last->num)
		ft_swap(stack_a);
	else if (stack_a->first->num > stack_a->first->next->num
		&& stack_a->last->num < stack_a->first->next->num)
	{
		ft_swap(stack_a);
		ft_rotate_down(stack_a);
	}
	else if (stack_a->first->num > stack_a->first->next->num
		&& stack_a->last->num > stack_a->first->next->num
		&& stack_a->first->num > stack_a->last->num)
		ft_rotate_up(stack_a);
	else if (stack_a->first->num < stack_a->first->next->num
		&& stack_a->last->num < stack_a->first->next->num
		&& stack_a->first->num < stack_a->last->num)
	{
		ft_swap(stack_a);
		ft_rotate_up(stack_a);
	}
	else if (stack_a->first->num < stack_a->first->next->num
		&& stack_a->last->num < stack_a->first->next->num
		&& stack_a->first->num > stack_a->last->num)
		ft_rotate_down(stack_a);
}

void	ft_mid_al(t_list *stack_a, t_list *stack_b, int flag)
{
	while (1)
	{
		if (ft_size_stack(stack_a) == stack_a->size
			&& ft_check_end(stack_a) == 0)
			break ;
		if (flag < 1)
		{
			ft_a2b(stack_a, stack_b, 0);
			if ((ft_size_stack(stack_a) == 2)
				&& (stack_a->first->num > stack_a->first->next->num))
				ft_swap(stack_a);
			flag = 1;
		}
		else
		{
			stack_a->last = stack_a->first->next;
			while (ft_size_stack(stack_b) != 0)
				ft_b2a(stack_a, stack_b);
			break ;
		}
	}
	while (ft_min_value(stack_a) != stack_a->first->num)
		ft_rotate_down(stack_a);
}
