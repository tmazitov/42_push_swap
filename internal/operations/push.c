/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:21:29 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/31 18:27:11 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	pa(t_stack *a, t_stack *b)
{
	int	old_top_value;

	if (b->size == 0)
		return (0);
	old_top_value = b->top->data;
	if (stack_pop(b))
		return (1);
	return (stack_push(a, old_top_value));
}

int	pb(t_stack *b, t_stack *a)
{
	int	old_top_value;

	if (a->size == 0)
		return (0);
	old_top_value = a->top->data;
	if (stack_pop(a))
		return (1);
	return (stack_push(b, old_top_value));
}
