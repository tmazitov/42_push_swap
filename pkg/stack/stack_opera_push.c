/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:43:03 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/24 22:00:38 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_push(t_stack *stack, int num)
{
	t_stack_node	*new_node;

	if (!stack)
		return (1);
	new_node = make_stack_node(num);
	if (!new_node)
		return (1);
	if (stack->top) {
		new_node->next = stack->top;
		stack->top->prev = new_node;
	}
	stack->top = new_node;
	stack->size += 1;
	return (0);
}