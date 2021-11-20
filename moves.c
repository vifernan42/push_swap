/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:53:23 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/20 20:42:40 by vifernan         ###   ########.fr       */
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
		element1->prev = element2;
		element1->next = element2->next;
		if (element2->next)
			element1->next->prev = element1;
		stack->first = element2;
		stack->first->prev = NULL;
		stack->first->next = element1;
		if (stack->id == 'a')
			printf("sa\n");
		else
			printf("sb\n");
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








void	ft_first_push(t_list *stack_out, t_list *stack_in)
{
	t_element	*element;

	element = stack_out->first;
	if (element->next)
	{
		element->next->prev = NULL;
		stack_out->first = element->next;
	}
	else
		stack_out->first = NULL;
	element->next = NULL;
	element->prev = NULL;
	stack_in->first = element;
	stack_in->last = element;
}

void	ft_last_push(t_list *stack_out, t_list *stack_in)
{
	t_element	*element;
	t_element	*element9;

	element9 = stack_out->first;
	element = stack_in->first;
	element9->next = element;
	element9->prev = NULL;
	element->prev = element9;
	stack_in->first = element9;
	stack_out->first = NULL;
	stack_out->last = NULL;
}

void	ft_push_it(t_list *stack_out, t_list *stack_in)
{
	t_element	*element1;
	t_element	*element2;

	element1 = stack_out->first;
	element2 = stack_in->first,
	element1->next->prev = NULL;
	stack_out->first = element1->next;
	element2->prev = element1;
	element1->next = element2;
	element1->prev = NULL;
	stack_in->first = element1;
}

void	ft_push(t_list *stack_out, t_list *stack_in)
{
	if (stack_out->first)
	{
		if (!stack_in->first)
			ft_first_push(stack_out, stack_in);
	else
		{
			if (stack_out->first && !stack_out->first->next)
				ft_last_push(stack_out, stack_in);
			else
				ft_push_it(stack_out, stack_in);
		}
		if (stack_in->id == 'a')
			printf("pa\n");
		else
			printf("pb\n");
	}
}

void	ft_rotate_up(t_list *stack)
{
	t_element *element1;
	t_element *element9;

	element1 = stack->first;
	element9 = stack->last;
	
//	printf("%d\n", element9->prev->num);
	if (stack->first && stack->first->next)
	{
		stack->first = element1->next;
		stack->last = element1;
		element1->next->prev = NULL;
		element1->prev = element9;
		element9->next = element1;
		element1->next = NULL;
		if (stack->id == 'a')
			printf("ra\n");
		else
			printf("rb\n");
	}
}
/*
void	ft_rotate_up(t_list *stack)
{
	t_element *first_element;
	t_element *last_element;
	
	if (stack->first)
	{
		first_element = stack->first;
		last_element = stack->last;
		stack->first = first_element->next;
		stack->last = first_element;
		first_element->next->prev = NULL;
		first_element->prev = last_element;
		last_element->next = first_element;
		first_element->next = NULL;
		if (stack->name == 'a')
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}
*/
void	ft_double_up(t_list *stack_a, t_list *stack_b)
{
	t_element *element1a;
	t_element *element9a;
	t_element *element1b;
	t_element *element9b;

	element1a = stack_a->first;
	element9a = stack_a->last;
	element1b = stack_b->first;
	element9b = stack_b->last;
	if (stack_a->first && stack_a->first->next && stack_b->first && stack_b->first->next)
	{
		stack_a->first = element1a->next;
		stack_a->last = element1a;
		element1a->next->prev = NULL;
		element1a->prev = element9a;
		element9a->next = element1a;
		element1a->next = NULL;
		stack_b->first = element1b->next;
		stack_b->last = element1b;
		element1b->next->prev = NULL;
		element1b->prev = element9b;
		element9b->next = element1b;
		element1b->next = NULL;
		printf("rr\n");
	}
}

void	ft_rotate_down(t_list *stack)
{
	t_element *element1;
	t_element *element9;

	element1 = stack->first;
	element9 = stack->last;
//	printf("%d\n", element9->prev->num);
	if (stack->first && stack->first->next)
	{
		stack->first = element9;
		stack->last = element9->prev;
		element1->prev = element9;
		stack->last->next = NULL;
		element9->next = element1;
		if (stack->id == 'a')
			printf("rra\n");
		else
			printf("rrb\n");
	}
}

void	ft_double_down(t_list *stack_a, t_list *stack_b)
{
	t_element *element1a;
	t_element *element9a;
	t_element *element1b;
	t_element *element9b;

	element1a = stack_a->first;
	element9a = stack_a->last;
	element1b = stack_b->first;
	element9b = stack_b->last;
//	printf("ENTRA!!!!!\n");
	if (stack_a->first && stack_a->first->next && stack_b->first && stack_b->first->next)
	{
		stack_a->first = element9a;
		stack_a->last = element9a->prev;
		element1a->prev = element9a;
		element9a->prev->next = NULL;
		element9a->prev = NULL;
		element9a->next = element1a;

		stack_b->first = element9b;
		stack_b->last = element9b->prev;
		element1b->prev = element9b;
		element9b->prev->next = NULL;
		element9b->prev = NULL;
		element9b->next = element1b;
		printf("rrr\n");
	}
}
