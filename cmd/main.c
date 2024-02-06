/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:53:10 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/06 19:32:09 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	if (!validation(argc, argv))
		return (ft_printf("Error : bad symbols\n"), 1);
	stack_a = parse(argv);
	if (!stack_a)
		return (ft_printf("Error : malloc failed\n"), 1);
	if (validate_stack(stack_a) != 0)
	{
		ft_printf("Error : invalid element of the stack\n");
		free_stack(stack_a);
		return (1);
	}
	stack_b = make_stack('b');
	if (!stack_b)
	{
		ft_printf("Error : malloc failed\n");
		free_stack(stack_a);
		return (1);
	}
	make_sort(stack_a, stack_b);
	return (free_stack(stack_a), free_stack(stack_b), 0);
}
