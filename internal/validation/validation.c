/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:06:59 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/06 19:46:16 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	check_duplicate(t_stack *stack)
{
	t_stack_node	*node;

	node = stack->top;
	while (node)
	{
		if (stack_includes(stack, node->data) != 1)
			return (1);
		node = node->next;
	}
	return (0);
}

int	validate_stack(t_stack *stack)
{
	int	err;

	if (stack->size < 2)
		return (1);
	err = check_duplicate(stack);
	if (err != 0) 
		return (1);
	return (0);
}
