/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fill_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 05:40:45 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/06 19:41:59 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	sort_fill_b(t_stack *a, t_stack *b)
{
	t_sort_inst	inst;

	while (a->size != 3 && !stack_is_pseudo_sorted(a, MIN_TO_MAX))
	{
		inst = find_cheapest(a, b);
		if (make_rotate_ab_by_list(a, b, &inst))
			return (1);
		if (make_rotate_stack_by_inst(a, inst.rotate_a))
			return (1);
		if (make_rotate_stack_by_inst(b, inst.rotate_b))
			return (1);
		pb(b, a);
	}
	if (stack_is_pseudo_sorted(a, MIN_TO_MAX) 
		&& !stack_is_sorted(a, MIN_TO_MAX))
	{
		inst.rotate_a = grade_to_take(a, stack_min(a)->data);
		make_rotate_stack_by_inst(a, inst.rotate_a);
	}
	return (0);
}
