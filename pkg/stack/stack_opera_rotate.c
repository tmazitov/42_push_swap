/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:06:48 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/24 19:28:47 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack.h"

int	stack_rotate(t_stack *stack)
{
	t_stack_node	*tmp;
	int				old_top_data;

	if (!stack || !stack->top)
		return (1);
	old_top_data = stack->top->data;
	tmp = stack->top;
	while (tmp && tmp->next) 
	{
		tmp->data = tmp->next->data;
		tmp = tmp->next;
	}
	tmp->data = old_top_data;
	return (0);
}