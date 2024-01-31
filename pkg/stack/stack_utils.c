/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:33:57 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/31 19:12:42 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_node	*stack_last_node(t_stack *stack)
{
	t_stack_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	while (node->next)
		node = node->next;
	return (node);
}

void	stack_print(t_stack *stack)
{
	t_stack_node	*node;

	if (!stack)
		return ;
	node = stack->top;
	while (node)
	{
		ft_printf("node: %d\n", node->data);
		node = node->next;
	}
}

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