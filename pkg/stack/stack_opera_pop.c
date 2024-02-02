/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_pop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:43:53 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/02 14:39:09 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_pop(t_stack	*stack)
{
	t_stack_node	*old_top;

	if (!stack || !stack->top)
		return (1);
	old_top = stack->top;
	stack->top = stack->top->next;
	if (stack->top)
		stack->top->prev = NULL;	
	free_stack_node(old_top);
	stack->size -= 1;
	return (0);
}