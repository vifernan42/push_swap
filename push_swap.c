/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:09:49 by vifernan          #+#    #+#             */
/*   Updated: 2021/12/01 18:19:16 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	leaks(void)
{
	system("leaks push_swap");
}

void	ft_free_elem(t_list *stack_a, t_list *stack_b)
{
	t_element	*element;
	t_element	*l;
	t_element	*aux;

	element = stack_a->first;
	while (element)
	{
		aux = element;
		element = element->next;
		free(aux);
	}
	l = stack_a->last;
	while (element)
	{
		aux = l;
		l = l->prev;
		free(aux);
	}
	free(stack_a);
	free(stack_b);
}
/*
void	print_stack(t_list *stack_a, t_list *stack_b)
{
	t_element	*element_a;
	t_element	*element_b;

	element_a = stack_a->first;
	element_b = stack_b->first;
	printf("_\t\t\t_\n");
	while (element_a || element_b)
	{
		if (!element_a)
			printf(" ");
		else
		{
			printf("%d", element_a->num);
			element_a = element_a->next;
		}
		if (!element_b)
			printf("\t\t\t\n");
		else
		{
			printf("\t\t\t%d\n", element_b->num);
			element_b = element_b->next;
		}
	}
	printf("_\t\t\t_\n");
	printf("a\t\t\tb\n");
	printf("**************************\n");
}*/

void	ft_check_nu(char *c)
{
	if (c == NULL)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}

void	ft_save_values(int argc, char **argv, t_list *stack_a)
{
	char	***values;
	int		i;
	int		j;
	char	*aux;

	values = malloc(argc * sizeof(char ***));
	i = 0;
	j = -1;
	while (argv[++i])
		values[++j] = ft_split(argv[i], ' ');
	values[--i] = NULL;
	i = -1;
	ft_check_nu(values[0][0]);
	while (values[++i])
	{
		j = -1;
		while (values[i][++j])
		{
			aux = values[i][j];
			ft_check(aux, stack_a);
			free(values[i][j]);
		}
		free(values[i]);
	}
	free(values);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	stack_b->id = 'b';
	stack_a->id = 'a';
	stack_a->size = 0;
	if (argc > 1)
	{
		ft_save_values(argc, argv, stack_a);
		stack_b->first = NULL;
		stack_b->last = NULL;
		if (stack_a->size == 3)
			ft_three_rd(stack_a);
		else
			ft_mid_al(stack_a, stack_b, 0);
		ft_free_elem(stack_a, stack_b);
	}
	else
		exit (0);
}
