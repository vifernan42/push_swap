/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:09:49 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/19 17:33:02 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

/*
void	leaks()
{
	system("leaks push_swap");
}
*/
void	ft_free_elem(t_list *stack_a, t_list *stack_b)
{
	t_element *element;
	t_element *l;
	t_element *aux;

	element = stack_a->first;
	while (element)
	{
		printf("***************\n");
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

void	print_stack(t_list *stack_a, t_list *stack_b)
{
	t_element *element_a;
	t_element *element_b;

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
}

int	ft_fill_a(t_list *stack_a, int val)
{
	t_element	*current;

	current = malloc(sizeof(t_element));
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
//	free(current);
	return (1);
}

int	ft_norepeet(t_list *stack_a, int val)
{
	t_element *current;

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
		if (stack_a->size == 0)
			stack_a->size += ft_fill_a(stack_a, ft_atoi(aux[i]));
		else if (ft_norepeet(stack_a, ft_atoi(aux[i])) == 0)
			stack_a->size += ft_fill_a(stack_a, ft_atoi(aux[i]));
	}
}

void	ft_check(char *temp, t_list *stack_a)
{
	int i;

	i = -1;
	while (temp[++i])
	{
		if ((ft_isdigit(temp[i]) != 1 && temp[i] != ' ' && temp[i] != '-') ||
				(temp[i] == '-' && (ft_isdigit(temp[i + 1]) != 1 &&
					(temp[i - 1] != ' ' || i != 0))))
		{
			printf("Wrong arg!\n");
			exit (0);
		}
	}
	ft_fill_stack(temp, stack_a);
}

void	ft_save_values(int argc, char **argv, t_list *stack_a)
{
	char	***values;
	int		i;
	int		j;

	values = malloc(argc * sizeof(values));
	i = 0;
	j = -1;
	while (argv[++i])
		values[++j] = ft_split(argv[i], ' ');
	values[--i] = NULL;
	i = -1;
	while (values[++i])
	{
		j = -1;
		while (values[i][++j])
		{
			ft_check(values[i][j], stack_a);
			free(values[i][j]);
		}
		free(values[i]);
	}
	free(values);
//	ft_free_elem(stack_a, NULL);
//	exit (0);
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

//	atexit(leaks);
	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	stack_b->id = 'b';
	stack_a->id = 'a';
	stack_a->size = 0;
	i = 5;
	if (argc > 1)
	{
		ft_save_values(argc, argv, stack_a);
		system("leaks push_swap");
	//	system("leaks push_swap");
		stack_b->first = NULL;
		stack_b->last = NULL;
		ft_mid_al(stack_a, stack_b);
		ft_free_elem(stack_a, stack_b);
	}
	else
		printf("Wrong arg!\n");
}
