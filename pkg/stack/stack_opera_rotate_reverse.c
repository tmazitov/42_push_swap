/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_rotate_reverse.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:29:31 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/24 22:00:33 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_rotate_reverse(t_stack *stack)
{
	int				old_bot_data;
	t_stack_node	*last_node;
	t_stack_node	*tmp;

	if (!stack || stack->size < 2)
		return (1);
	last_node = stack_last_node(stack);
	if (!last_node)
		return (1);
	old_bot_data = last_node->data;
	tmp = stack->top->next;
	while (tmp && tmp->prev)
	{
		tmp->data = tmp->prev->data;
		tmp = tmp->next;
	}
	stack->top->data = old_bot_data;
	return (0); 
}
