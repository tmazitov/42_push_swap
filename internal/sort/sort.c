/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:44:41 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/02 13:39:50 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"


static int make_rotate_a_by_inst(t_stack *stack, t_sort_inst inst)
{
	while (inst.rotate_a != 0)
	{
		if (inst.rotate_a < 0)
		{
			if (rra(stack))
				return (1);
			inst.rotate_a += 1;			
		}
		else if (inst.rotate_a > 0)
		{
			if (ra(stack))
				return (1);
			inst.rotate_a -= 1;
		}	
	}
	return (0);
}
static int make_rotate_b_by_inst(t_stack *stack, t_sort_inst inst)
{
	while (inst.rotate_b != 0)
	{
		if (inst.rotate_b < 0)
		{
			if (rrb(stack))
				return (1);
			inst.rotate_b += 1;			
		}
		else if (inst.rotate_b > 0)
		{
			if (rb(stack))
				return (1);
			inst.rotate_b -= 1;
		}	
	}
	return (0);
}

static int	make_rotate_ab_by_list(t_stack *a, t_stack *b, t_sort_inst *inst)
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

int	make_sort(t_stack *a, t_stack *b)
{
	t_sort_inst	inst;

	if (!a || !b)
		return (1);
	
	// TODO : handle case with 2 and 3 values in stack 

	if (pb(b, a))
		return (1);
	if (pb(b, a))
		return (1);
	while (a->size != 2 && a->size != 3)
	{
		// 		ft_printf("A\t");
		// stack_print(a);
		// ft_printf("B\t");
		// stack_print(b);
		inst = find_cheapest(a, b);
		if (make_rotate_ab_by_list(a, b, &inst))
			return (1);
		if (make_rotate_a_by_inst(a, inst))
			return (1);
		if (make_rotate_b_by_inst(b, inst))
			return (1);
		pb(b, a);
	}
	while (b->size != 0)
	{
		// ft_printf("A\t");
		// stack_print(a);
		// ft_printf("B\t");
		// stack_print(b);
		inst = find_cheapest(b, a);
		// ft_printf("inst : num %d b %d a %d\n", inst.number, inst.rotate_a, inst.rotate_b);
		if (make_rotate_ab_by_list(a, b, &inst))
			return (1);
		if (make_rotate_a_by_inst(b, inst))
			return (1);
		if (make_rotate_b_by_inst(a, inst))
			return (1);
		pa(a, b);
	}
	while (!stack_is_sorted(a, MIN_TO_MAX))
		ra(a);
	return (0);
}