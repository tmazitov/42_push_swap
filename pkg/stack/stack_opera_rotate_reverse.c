/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_rotate_reverse.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:29:31 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/31 19:41:58 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_rotate_reverse(t_stack *stack)
{
	t_stack_node	*tmp;
	int				old_bot_data;

	if (!stack || !stack->top)
		return (1);
	tmp = stack->top;
	while (tmp && tmp->next)
		tmp = tmp->next;
	old_bot_data = tmp->data;
	while (tmp && tmp->prev) 
	{
		tmp->data = tmp->prev->data;
		tmp = tmp->prev;
	}
	tmp->data = old_bot_data;
	return (0);
}
