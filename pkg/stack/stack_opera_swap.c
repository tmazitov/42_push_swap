/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:22:12 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/06 19:53:40 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_swap(t_stack *stack)
{
	int	tmp;

	if (!stack || stack->size < 2)
		return (1);
	tmp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp;
	return (0);
}
