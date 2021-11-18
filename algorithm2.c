/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:59:25 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/18 19:42:42 by vifernan         ###   ########.fr       */
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
	arr_a = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		arr_a[i++] = element->num;
		element = element->next;
	}
	//printf("--------------%d\n", ft_size_stack(stack_a));
	arr_a = ft_sort_int_tab(arr_a, size);
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

int	ft_max_value(t_list *stack)
{
	t_element *element;
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

int	ft_min_value(t_list *stack)
{
	t_element *element;
	int n;

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

//DISTANCIAS MINIMAS TANTO POR ARRIBA COMO POR ABAJAO

int	ft_min_dist(t_list *stack, int n)
{
	int p;
	int dist;

	p = ft_pos_down(stack, n);
	dist = ft_size_stack(stack) - p;

	if (p > dist)
		return (dist);
	return (p);
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
			while (ft_size_stack(stack_b) != 0)
			{
				element = stack_b->first;
				if (ft_min_dist(stack_b, ft_min_value(stack_b) < ft_min_dist(stack_b, ft_max_value(stack_b))))
				{
						if (element->num == ft_max_value(stack_b))
						{
							ft_push(stack_b, stack_a);
							print_stack(stack_a, stack_b);
							break ;
						}
						else
						{
							if (ft_pos_down(stack_b, ft_max_value(stack_b)) <= ft_size_stack(stack_b) / 2)
								ft_rotate_up(stack_b);
							else
								ft_rotate_down(stack_b);
						}
				}
				else
				{
						if (element->num == ft_min_value(stack_b))
						{
							ft_push(stack_b, stack_a);
							ft_rotate_up(stack_a);
							break ;
						}
						else
						{
							if (ft_pos_down(stack_b, ft_min_value(stack_b)) <= ft_size_stack(stack_b) / 2)
								ft_rotate_up(stack_b);
							else
								ft_rotate_down(stack_b);
						}
				}
				break ;
			}
		}
	}
	while (ft_min_value(stack_a) != stack_a->first->num)
		ft_rotate_down(stack_a);
}



/*
 *
 	while (ft_size_stack(stack_b) != 0)
			{
				element = stack_b->first;
			//	printf("MIN:%d POS:%d | MAX: %d POS: %d | SIZE: %d\n", ft_min_value(stack_b), ft_pos_down(stack_b, ft_min_value(stack_b)), ft_max_value(stack_b), ft_pos_down(stack_b, ft_max_value(stack_b)), ft_size_stack(stack_b));
				if (element->num == ft_min_value(stack_b))
				{
					ft_push(stack_b, stack_a);
					ft_rotate_up(stack_a);
				}
				if (ft_size_stack(stack_b) > 1 && stack_b->first->next->num == ft_min_value(stack_b))
				{
					ft_rotate_up(stack_b);
					ft_push(stack_b, stack_a);
					ft_rotate_up(stack_a);
				}
				if (ft_size_stack(stack_b) > 1 && stack_b->last->prev->num == ft_min_value(stack_b))
				{
					ft_rotate_down(stack_b);
					ft_rotate_down(stack_b);
					ft_push(stack_b, stack_a);
					ft_rotate_up(stack_a);
				//	print_stack(stack_a, stack_b);
				}
				if (element->num == ft_max_value(stack_b))
					ft_push(stack_b, stack_a);
				else
				{
					if (ft_pos_down(stack_b, ft_max_value(stack_b)) <= ft_size_stack(stack_b) / 2)
						ft_rotate_up(stack_b);
					else
						ft_rotate_down(stack_b);
				}
			}
			break ;
 *
 * */



































