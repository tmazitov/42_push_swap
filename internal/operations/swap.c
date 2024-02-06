/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:17:50 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/06 19:33:55 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	sa(t_stack *a)
{
	ft_printf("sa\n");
	return (stack_swap(a));
}

int	sb(t_stack *b)
{
	ft_printf("sb\n");
	return (stack_swap(b));
}

int	ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	ft_printf("ss\n");
	return (stack_swap(b));
}
