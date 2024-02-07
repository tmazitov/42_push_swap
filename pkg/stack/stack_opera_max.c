/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:16:23 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/06 19:53:01 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_node	*stack_max(t_stack *stack)
{
	t_stack_node	*node;
	t_stack_node	*min;

	node = stack->top;
	min = stack->top;
	while (node)
	{
		if (node->data > min->data)
			min = node;
		node = node->next;
	}
	return (min);
}
