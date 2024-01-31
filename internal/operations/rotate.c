/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:27:34 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/31 18:29:45 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	ra(t_stack *a)
{
	return (stack_rotate(a));
}

int rb(t_stack *b)
{
	return (stack_rotate(b));
}

int rr(t_stack *a, t_stack *b)
{
	if (stack_rotate(a))
		return (1);
	return (stack_rotate(b));
}