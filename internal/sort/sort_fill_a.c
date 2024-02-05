/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fill_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 05:42:43 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/05 22:13:20 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	sort_fill_a(t_stack *a, t_stack *b)
{
	t_sort_inst	inst;

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
		if (make_rotate_stack_by_inst(a, inst.rotate_b))
			return (1);
		if (make_rotate_stack_by_inst(b, inst.rotate_a))
			return (1);
		pa(a, b);
	}
	// stack_print(a);

	return (0);
}
