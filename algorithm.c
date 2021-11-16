/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:59:25 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/16 19:36:15 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

/*int	*ft_sort_int_tab(int *tab, int size)
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
				printf("arr: %d\n", tab[i]);
				tab[i + 1] = save;
			}
			i++;
		}
		j++;
	}
	return (tab);
}*/

int		*ft_sort_int_tab(int *tab, int size)
{
	int		swap;
	int		count;

	count = 0;
	while (count < (size - 1))
	{
		if (tab[count] > tab[count + 1])
		{
			swap = tab[count];
			tab[count] = tab[count + 1];
			tab[count + 1] = swap;
			count = 0;
		}
		else
			count++;
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

int	ft_mid_point(t_list *stack_a)
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
	printf("--------------%d\n", ft_size_stack(stack_a));
	arr_a = ft_sort_int_tab(arr_a, ft_size_stack(stack_a));
	mid = arr_a[ft_size_stack(stack_a)/2];
	free(arr_a);
	return (mid);
}
int	ft_check_end(t_list *stack_a)
{
	t_element	*element;
	
	element = stack_a->first;
	while (element)
	{
		if (element < element->next)
			return (1);
		element = element->next;
	}
	return (0);
}

void	ft_mid_al(t_list *stack_a, t_list *stack_b)
{
	t_element	*element;
	t_element	*last;
	int			mid;
	int			mid_size;
	int			count;
	int			size;
	int			flag;

//	element = stack_a->first;
	mid = ft_mid_point(stack_a);
	mid_size = ft_size_stack(stack_a) / 2;
	count = 0;
	flag = 0;
	while (1)
	{
		printf("/*/*/*/*/\n");
		if (flag < 1)
		{
			size = ft_size_stack(stack_a);
			while (size > 2)
			{
				size = ft_size_stack(stack_a);
				mid = ft_mid_point(stack_a);
				mid_size = size / 2;
				count = 0;
				while (count < mid_size)
				{
					element = stack_a->first;
					last = stack_a->last;
					if (element->num < mid)
					{
						ft_push(stack_a, stack_b);
						count++;
					}
					else if (last < mid)
						ft_rotate_down(stack_a);
					else
						ft_rotate_up(stack_a);
				}
				print_stack(stack_a, stack_b);
			//	printf ("--------size: %d -------mid: %d ------mid_size: %d\n", size, mid, mid_size);
			}
			if ((ft_size_stack(stack_a) == 2) && (stack_a->first->num > stack_a->first->next->num))
				ft_swap(stack_a);
			flag = 1;
		}
		else
		{
			ft_push(stack_b, stack_a);
			while (size < stack_a->size)
			{
				size *= 2;
				mid = ft_mid_point(stack_b);
				mid_size = size / 2;
				count = 0;
				while (count < mid_size)
				{
					element = stack_b->first;
					last = stack_b->last;
					if (element->num >= mid)
					{
						ft_push(stack_b, stack_a);
						count++;
					}
					else if (last > mid)
						ft_rotate_down(stack_b);
					else
						ft_rotate_up(stack_b);
					print_stack(stack_a, stack_b);
					printf("---count: %d, ---mid_size: %d\n", count, mid_size);
				}
				print_stack(stack_a, stack_b);
			//	printf ("--------size: %d -------mid: %d ------mid_size: %d\n", size, mid, mid_size);
			}
			if ((ft_size_stack(stack_b) == 2) && (stack_b->first->num < stack_b->first->next->num))
				ft_swap(stack_b);
			flag = 0;
		}
		if (ft_size_stack(stack_a) == stack_a->size && ft_check_end(stack_a) == 0)
			break ;
	}
}







































