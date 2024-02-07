/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:44:41 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/06 19:38:46 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	make_sort(t_stack *a, t_stack *b)
{
	int			count;
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
	if (a->size == 3)
		sort_3(a);
	if (sort_fill_a(a, b))
		return (1);
	inst.rotate_a = grade_to_take(a, stack_min(a)->data);
	make_rotate_stack_by_inst(a, inst.rotate_a);
	return (0);
}
