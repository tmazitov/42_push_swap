/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:12:20 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/24 22:00:19 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack *make_stack() 
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack) 
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	return (stack);
}

void *free_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (stack->top)
		stack_pop(stack);
	free(stack);
	return (NULL);
}