/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:30:46 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/31 18:31:13 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	rra(t_stack *a)
{
	return (stack_rotate_reverse(a));
}

int rrb(t_stack *b)
{
	return (stack_rotate_reverse(b));
}

int rrr(t_stack *a, t_stack *b)
{
	if (stack_rotate_reverse(a))
		return (1);
	return (stack_rotate_reverse(b));
}