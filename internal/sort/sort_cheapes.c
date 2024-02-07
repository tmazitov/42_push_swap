/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cheapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:21:13 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/06 19:41:01 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

static int	ft_abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

t_sort_inst	make_instruction(t_stack_node *node, t_stack *a, t_stack *b)
{
	t_sort_inst	inst;

	inst.number = node->data;
	inst.rotate_a = grade_to_take(a, node->data);
	inst.rotate_b = grade_to_put(b, node->data);
	if (inst.rotate_a >= 0 && inst.rotate_b >= 0)
		inst.cost = max(inst.rotate_a, inst.rotate_b);
	else
		inst.cost = ft_abs(inst.rotate_a) + ft_abs(inst.rotate_b);
	return (inst);
}

t_sort_inst	find_cheapest(t_stack *a, t_stack *b)
{
	t_stack_node	*node;
	t_stack_node	*cheapest;
	t_sort_inst		cheapest_inst;
	t_sort_inst		inst;

	node = a->top->next;
	cheapest = a->top;
	cheapest_inst = make_instruction(cheapest, a, b);
	while (node)
	{
		inst = make_instruction(node, a, b);
		if (inst.cost < cheapest_inst.cost)
		{
			cheapest = node;
			cheapest_inst = inst;
		}
		node = node->next;
	}
	return (cheapest_inst);
}
