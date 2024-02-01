/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:13:52 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/01 16:16:17 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_node	*stack_min(t_stack *stack)
{
	t_stack_node	*node;
	t_stack_node	*min;

	node = stack->top;
	min = stack->top;
	while (node)
	{
		if (node->data < min->data)
			min = node;
		node = node->next;
	}
	return (min);
}