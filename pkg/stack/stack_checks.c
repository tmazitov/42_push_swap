/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:51:09 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/01 15:15:36 by tmazitov         ###   ########.fr       */
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


static int	check_max_to_min(t_stack *stack)
{
	t_stack_node	*node;

	if (stack->size == 1)
		return (1);
	node = stack->top->next;
	while (node) 
	{
		if (node->data > node->prev->data)
			return (0);
		node = node->next;	
	}
	return (1);
}

static int	check_min_to_max(t_stack *stack)
{
	t_stack_node	*node;

	if (stack->size == 1)
		return (1);
	node = stack->top->next;
	while (node) 
	{
		if (node->data < node->prev->data)
			return (0);
		node = node->next;	
	}
	return (1);
}

int	stack_is_sorted(t_stack *stack, s_sort_type type)
{
	if (!stack || stack->size == 0)
		return (0);
	if (type == MAX_TO_MIN)
		return (check_max_to_min(stack));
	else if (type == MIN_TO_MAX)
		return (check_min_to_max(stack));
	return (0);
}
