/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_includes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:14:14 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/06 19:52:58 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_includes(t_stack *stack, int data)
{
	t_stack_node	*node;
	int				counter;

	counter = 0;
	node = stack->top;
	while (node) 
	{
		if (node->data == data) 
			counter += 1;
		node = node->next;
	}
	return (counter);
}
