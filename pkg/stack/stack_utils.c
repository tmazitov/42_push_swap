/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:33:57 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/02 13:02:27 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_node	*stack_last_node(t_stack *stack)
{
	t_stack_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	while (node->next)
		node = node->next;
	return (node);
}

void	stack_print(t_stack *stack)
{
	t_stack_node	*node;

	if (!stack)
		return ;
	node = stack->top;
	while (node)
	{
		ft_printf("%d", node->data);
		if (node->next)
			ft_printf(" ");
		node = node->next;
	}
	ft_printf("\n");
}
