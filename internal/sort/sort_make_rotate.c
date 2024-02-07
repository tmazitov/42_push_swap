/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_make_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:37:37 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/06 19:45:54 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	make_rotate_stack_by_inst(t_stack *stack, int rotate)
{
	while (rotate != 0)
	{
		if (rotate < 0)
		{
			if (stack->name == 'a' && rra(stack))
				return (1);
			if (stack->name == 'b' && rrb(stack))
				return (1);
			rotate += 1;
		}
		else if (rotate > 0)
		{
			if (stack->name == 'a' && ra(stack))
				return (1);
			if (stack->name == 'b' && rb(stack))
				return (1);
			rotate -= 1;
		}
	}
	return (0);
}

int	make_rotate_ab_by_list(t_stack *a, t_stack *b, t_sort_inst *inst)
{
	while (inst->rotate_a > 0 && inst->rotate_b > 0)
	{
		if (rr(a, b))
			return (1);
		inst->rotate_a -= 1;
		inst->rotate_b -= 1;
	}
	while (inst->rotate_a < 0 && inst->rotate_b < 0)
	{
		if (rrr(a, b))
			return (1);
		inst->rotate_a += 1;
		inst->rotate_b += 1;
	}
	return (0);
}
