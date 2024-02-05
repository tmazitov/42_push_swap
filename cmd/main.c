/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:53:10 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/05 22:12:03 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char *argv[]) 
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	if (!validation(argc, argv))
		return (ft_printf("Error : bad symbols\n"), 1);
	stack_a = parse(argv);
	if (!stack_a)
		return (ft_printf("Error : memory allocation failed\n"), 1);
	if (validate_stack(stack_a) != 0)
		return (ft_printf("Error : invalid element of the sequence\n"), free_stack(stack_a), 1);
	stack_b = make_stack('b');
	if (!stack_b)
		return (ft_printf("Error : memory allocation failed\n"), free_stack(stack_b), 1);
	make_sort(stack_a, stack_b);
	// stack_print(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
}