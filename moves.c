/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:53:23 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/10 17:11:56 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	ft_swap(t_list *stack)
{
	t_element *element1;
	t_element *element2;

	if (stack->first && stack->first->next)
	{
		element1 = stack->first;
		element2 = element1->next;
		element1->next = element2->next;
		element1->next->prev = element1;
		element1->prev = element2;
		element1->prev = NULL;
		stack->first = element2;
		stack->first->next = element1;
		if (stack->id == 'a')
			printf("%s", "sa\n");
		else
			printf("%s", "sb\n");
	}
}

void	ft_double_swap(t_list *stack_a, t_list *stack_b)
{
	t_element *element1a;
	t_element *element2a;
	t_element *element1b;
	t_element *element2b;

	if (stack_a->first && stack_b->first && stack_a->first->next && stack_b->first->next)
	{
		element1a = stack_a->first;
		element2a = element1a->next;
		element1a->next = element2a->next;
		element1a->next->prev = element1a;
		element1a->prev = element2a;
		element1a->prev = NULL;
		stack_a->first = element2a;
		stack_a->first->next = element1a;
		element1b = stack_b->first;
		element2b = element1b->next;
		element1b->next = element2b->next;
		element1b->next->prev = element1b;
		element1b->prev = element2b;
		element1b->prev = NULL;
		stack_b->first = element2b;
		stack_b->first->next = element1b;
		printf("%s", "ss\n");
	}
}
/*
void	ft_push(t_list *stack_a, t_list *stack_b)
{
	t_element *element1a;
	t_element *element2a;
	t_element *element1b;
	t_element *element2b;


}*/
