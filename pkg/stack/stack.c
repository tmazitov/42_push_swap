/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:12:20 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/05 22:11:37 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack *make_stack(char name)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack) 
		return (NULL);
	stack->size = 0;
	stack->name = name;
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