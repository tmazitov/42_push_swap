/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:14:40 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/05 03:01:28 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	sort_3(t_stack *a)
{
	if (stack_is_sorted(a, MIN_TO_MAX))
		return (0);	
	if (stack_is_sorted(a, MAX_TO_MIN))
		return (sa(a) || rra(a));
	if (a->top->next == stack_max(a) && stack_last_node(a) == stack_min(a))
		return (rra(a));
	if (a->top->next == stack_max(a) && a->top == stack_min(a))
		return (rra(a) || sa(a));
	if (a->top->next == stack_min(a) && stack_last_node(a) == stack_max(a))
		return (sa(a));
	if (a->top->next == stack_min(a) && a->top == stack_max(a))
		return (ra(a));
	return (0);
}