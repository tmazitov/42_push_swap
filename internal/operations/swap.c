/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:17:50 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/31 19:16:00 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	sa(t_stack *a)
{
	return (stack_swap(a));
}

int	sb(t_stack *b)
{
	return (stack_swap(b));
}

int	ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	return (stack_swap(b));
}