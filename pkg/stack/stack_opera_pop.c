/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_pop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:43:53 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/24 19:46:18 by tmazitov         ###   ########.fr       */
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
	stack->top->prev = NULL;
	free_stack_node(old_top);
	return (0);
}