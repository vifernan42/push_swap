/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:59:25 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/17 16:38:08 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	*ft_sort_int_tab(int *tab, int size)
{
	int save;
	int i;
	int j;

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
				//printf("arr: %d\n", tab[i]);
				tab[i + 1] = save;
			}
			i++;
		}
		j++;
	}
	return (tab);
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

int	ft_mid_point(t_list *stack_a, int size)
{
	t_element	*element;
	int			i;
	int			*arr_a;
	int			mid;

	element = stack_a->first;
	arr_a = malloc(ft_size_stack(stack_a) * sizeof(int));
	i = -1;
	while (element)
	{
		arr_a[++i] = element->num;
		element = element->next;
	}
	//printf("--------------%d\n", ft_size_stack(stack_a));
	arr_a = ft_sort_int_tab(arr_a, ft_size_stack(stack_a));
	mid = arr_a[size/2];
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
			{
	//			printf("1:%d | 2:%d\n", element->num, element->next->num);
				return (1);
			}
		}
	//	printf("/////1:%d\n", element->num);
		element = element->next;
	}
	return (0);
}

void	ft_mid_al(t_list *stack_a, t_list *stack_b)
{
	t_element	*element;
	t_element	*last;
	int			mid_point;
	int			mid_size;
	int			count;
	int			size;
	int			flag;

	flag = 0;
	while (1)
	{
		if (ft_size_stack(stack_a) == stack_a->size && ft_check_end(stack_a) == 0)
			break ;
		if (flag < 1)
		{
			mid_size = ft_size_stack(stack_a) / 2;
			while (mid_size > 2)
			{
				size = ft_size_stack(stack_a);
				mid_point = ft_mid_point(stack_a, ft_size_stack(stack_a));
				mid_size = size / 2;
				count = 0;
				while (count < mid_size)
				{
					element = stack_a->first;
					last = stack_a->last->num;
					if (element->num < mid_point)
					{
						ft_push(stack_a, stack_b);
						count++;
					}
					else if (last < mid_point)
						ft_rotate_down(stack_a);
					else
						ft_rotate_up(stack_a);
				}
			}
			if ((ft_size_stack(stack_a) == 2) && (stack_a->first->num > stack_a->first->next->num))
				ft_swap(stack_a);
			flag = 1;
		}
		else
		{
			break ;
		}
	}
}







































