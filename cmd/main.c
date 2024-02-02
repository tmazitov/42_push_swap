/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:53:10 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/02 16:34:51 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char *argv[]) 
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	ft_printf("ac : %d\n", argc);
	stack_a = parse(argv);
	if (!stack_a)
		return (1);
	if (validate_stack(stack_a) != 0)
		return (free_stack(stack_a), 1);
	stack_b = make_stack();
	if (!stack_b)
		return (free_stack(stack_b), 1);
	if (make_sort(stack_a, stack_b))
		return (free_stack(stack_a), free_stack(stack_b), 1);
}