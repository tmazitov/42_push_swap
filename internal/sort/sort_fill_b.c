/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fill_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 05:40:45 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/05 05:41:53 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	sort_fill_b(t_stack *a, t_stack *b)
{
	t_sort_inst	inst;

	while (a->size != 3)
	{
		// 		ft_printf("A\t");
		// stack_print(a);
		// ft_printf("B\t");
		// stack_print(b);
		inst = find_cheapest(a, b);
		if (make_rotate_ab_by_list(a, b, &inst))
			return (1);
		if (make_rotate_a_by_inst(a, inst.rotate_a))
			return (1);
		if (make_rotate_b_by_inst(b, inst.rotate_b))
			return (1);
		pb(b, a);
	}
	return (0);
}