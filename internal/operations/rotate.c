/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:27:34 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/05 04:03:06 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	ra(t_stack *a)
{
	ft_printf("ra\n");
	return (stack_rotate(a));
}

int rb(t_stack *b)
{
	ft_printf("rb\n");
	return (stack_rotate(b));
}

int rr(t_stack *a, t_stack *b)
{
	if (stack_rotate(a))
		return (1);
	ft_printf("rr\n");
	return (stack_rotate(b));
}