/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:22:12 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/24 19:14:35 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack.h"

int	stack_swap(t_stack *stack)
{
	t_stack_node	*old_top;
	t_stack_node	*new_top;

	if (!stack || stack->size < 2)
		return (1);
	new_top = stack->top->next;
	old_top = stack->top;
	old_top->prev = new_top;
	old_top->next = new_top->next;
	old_top->next->prev = old_top;
	new_top->prev = NULL;
	new_top->next = old_top;
	stack->top = new_top;
	return (0);
}