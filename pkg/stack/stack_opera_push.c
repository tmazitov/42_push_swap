/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:43:03 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/24 19:47:32 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack.h"

int	stack_push(t_stack *stack, int num)
{
	t_stack_node	*new_node;

	if (!stack)
		return (0);
	new_node = make_stack_node(num);
	if (!new_node)
		return (0);
	if (stack->top) {
		new_node->next = stack->top;
		stack->top->prev = new_node;
	}
	stack->top = new_node;
	stack->size += 1
	return (1);
}