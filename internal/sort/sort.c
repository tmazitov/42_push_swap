/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:44:41 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/05 05:45:38 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"


int make_rotate_a_by_inst(t_stack *stack, int rotate)
{
	while (rotate != 0)
	{
		if (rotate < 0)
		{
			if (rra(stack))
				return (1);
			rotate += 1;			
		}
		else if (rotate > 0)
		{
			if (ra(stack))
				return (1);
			rotate -= 1;
		}	
	}
	return (0);
}
int make_rotate_b_by_inst(t_stack *stack, int rotate)
{
	while (rotate != 0)
	{
		if (rotate < 0)
		{
			if (rrb(stack))
				return (1);
			rotate += 1;			
		}
		else if (rotate > 0)
		{
			if (rb(stack))
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

int min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	make_sort(t_stack *a, t_stack *b)
{
	int count;
	t_sort_inst	inst;

	if (!a || !b)
		return (1);
	if (a->size == 2)
		return (sort_2(a));
	if (a->size == 3)
		return (sort_3(a));
	count = min(a->size - 3, 2);
	if (count-- && pb(b, a))
		return (1);
	if (count-- && pb(b, a))
		return (1);
	if (sort_fill_b(a, b))
		return (1);
	sort_3(a);
	if (sort_fill_a(a, b))
		return (1);
	inst.rotate_a = grade_to_take(a, stack_min(a)->data);
	make_rotate_a_by_inst(a, inst.rotate_a);
	return (0);
}