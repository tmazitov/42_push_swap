/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:44:41 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/01 18:56:42 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	make_sort(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (1);
	
	// TODO : handle case with 2 and 3 values in stack 

	if (pb(b, a))
		return (1);
	if (pb(b, a))
		return (1);
	if (pb(b, a))
		return (1);
	if (pb(b, a))
		return (1);
	if (pb(b, a))
		return (1);

	stack_print(a);
	stack_print(b);

	find_cheapest(a,b);
	// while (a->size != 2 && a->size != 3)
	// {
		
	// }
	return (0);
}