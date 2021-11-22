/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:43:20 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/22 17:59:29 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	ft_fill_a(t_list *stack_a, int val)
{
	t_element	*current;

	current = malloc(sizeof(*current));
	if (stack_a->size == 0)
	{
		current->num = val;
		current->next = NULL;
		current->prev = NULL;
		stack_a->first = current;
		stack_a->last = current;
	}
	else
	{
		current->num = val;
		current->next = NULL;
		current->prev = stack_a->last;
		stack_a->last->next = current;
		stack_a->last = current;
	}
	return (1);
}

int	ft_norepeet(t_list *stack_a, int val)
{
	t_element	*current;

	current = stack_a->first;
	while (current)
	{
		if (current->num == val)
			return (1);
		else
			current = current->next;
	}
	return (0);
}

void	ft_fill_stack(char *temp, t_list *stack_a)
{
	char	**aux;
	int		i;

	aux = ft_split(temp, ' ');
	i = -1;
	while (aux[++i])
	{
		if (ft_atoi(aux[i]) > INT_MAX || ft_atoi(aux[i]) < INT_MIN)
		{
			free(aux[i]);
			write(1, "Error\n", 6);
			exit (0);
		}
		if (stack_a->size == 0)
			stack_a->size += ft_fill_a(stack_a, ft_atoi(aux[i]));
		else if (ft_norepeet(stack_a, ft_atoi(aux[i])) == 0)
			stack_a->size += ft_fill_a(stack_a, ft_atoi(aux[i]));
		free(aux[i]);
	}
	free(aux);
}

void	ft_check(char *temp, t_list *stack_a)
{
	int	i;

	i = -1;
	while (temp[++i])
	{
		if ((ft_isdigit(temp[i]) != 1 && temp[i] != ' '
				&& (temp[i] != '-' && temp[i] != '+'))
			|| ((temp[i] == '-' && temp[i] == '+')
				&& (ft_isdigit(temp[i + 1]) != 1
					&& (temp[i - 1] != ' ' || i != 0))))
		{
			write(1, "Error\n", 6);
			exit (0);
		}
	}
	ft_fill_stack(temp, stack_a);
}
