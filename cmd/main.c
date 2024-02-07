/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:53:10 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/07 10:40:21 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int panic(char *message, t_stack *a, t_stack *b)
{
	ft_printf("Error : %s\n", message);
	free_stack(a);
	free_stack(b);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	if (!validation(argc, argv))
		return (panic("bad symbols", a, b));
	a = parse(argv);
	if (!a)
		return (panic("stack parsing failed", a, b));
	if (a->size == 1 || stack_is_sorted(a, MIN_TO_MAX))
		return (0);
	if (validate_stack(a))
		return (panic("invalid elements of the stack", a, b));
	b = make_stack('b');
	if (!b)
		return (panic("malloc failed", a, b));
	make_sort(a, b);
	return (free_stack(a), free_stack(b), 0);
}
