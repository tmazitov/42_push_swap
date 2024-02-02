/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:12:20 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/02 14:05:40 by tmazitov         ###   ########.fr       */
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
	while (stack->top)
		stack_pop(stack);
	free(stack);
	return (NULL);
}