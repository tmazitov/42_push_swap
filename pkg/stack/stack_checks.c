/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:51:09 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/05 21:25:39 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_is_equal(t_stack *a, t_stack *b)
{
	t_stack_node	*node_a;
	t_stack_node	*node_b;
	
	if (!a || !b || a->size != b->size)
		return (0);
	node_a = a->top;
	node_b = b->top;
	while (node_a && node_b)
	{
		if (node_a->data != node_b->data)
			return (0);
		node_a = node_a->next;
		node_b = node_b->next;
	}
	return (1);
}


static int	check_max_to_min(t_stack *stack, int pseudo)
{
	t_stack_node	*node;
	t_stack_node	*min;
	t_stack_node	*max;

	if (!stack || stack->size < 2)
		return (1);
	min = NULL;
	max = NULL;
	if (pseudo)
	{
		min = stack_min(stack);
		max = stack_max(stack);
	}
	node = stack->top->next;
	while (node) 
	{
		if ((pseudo && (node == max) && (node->prev == min)))
		{
			node = node->next;
			continue;
		}	
		if (node->data > node->prev->data)
			return (0);
		node = node->next;	
	}
	return (1);
}

static int	check_min_to_max(t_stack *stack, int pseudo)
{
	t_stack_node	*node;
	t_stack_node	*min;
	t_stack_node	*max;

	if (!stack || stack->size < 2)
		return (1);
	min = NULL;
	max = NULL;
	if (stack)
	{
		min = stack_min(stack);
		max = stack_max(stack);
	}
	node = stack->top->next;
	while (node) 
	{
		if (pseudo && (node == min) && (node->prev == max))
		{
			node = node->next;
			continue;
		}	
		if (node->data < node->prev->data)
			return (0);
		node = node->next;	
	}
	return (1);
}

int	stack_is_sorted(t_stack *stack, s_sort_type type)
{
	if (!stack || stack->size < 2)
		return (0);
	if (type == MAX_TO_MIN)
		return (check_max_to_min(stack, 0));
	else if (type == MIN_TO_MAX)
		return (check_min_to_max(stack, 0));
	return (0);
}

int	stack_is_pseudo_sorted(t_stack *stack, s_sort_type type)
{
	if (!stack || stack->size < 2)
		return (0);
	if (type == MAX_TO_MIN)
		return (check_max_to_min(stack, 1));
	else if (type == MIN_TO_MAX)
		return (check_min_to_max(stack, 1));
	return (0);
}
