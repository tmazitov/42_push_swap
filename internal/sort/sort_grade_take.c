/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_grade_take.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:49:33 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/01 22:57:45 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	max_grade(t_stack *stack)
{
	return (stack->size / 2);
}

static void	grade_update(t_stack_node **node, t_stack *s, int *grade, int *mode)
{
	if (*grade == max_grade(s) && *mode == 0)
	{
		*mode = 1;
		*grade = *grade * -1;
		if (s->size % 2 != 0)
		{
			*node = (*node)->next;
			return ;
		}
	}
	*grade += 1;
	*node = (*node)->next;
}

int grade_to_take(t_stack *stack, int number)
{
	t_stack_node	*node;
	int				grade;
	int				calc_mode;

	grade = 0;
	node = stack->top;
	calc_mode = 0;
	while(node)
	{
		if (node->data == number)
			return (grade);
		grade_update(&node, stack, &grade, &calc_mode);
	}
	return (-1);
}