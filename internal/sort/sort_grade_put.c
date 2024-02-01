/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_grade_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:59:42 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/01 23:24:56 by tmazitov         ###   ########.fr       */
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

int check_between(t_stack_node *node, int x, int max, int min)
{
	if (node->data == max && node->prev->data == min)
		return (x > max || x < min);
	return ((node->data > x && node->prev->data < x ) ||
			(node->data < x && node->prev->data > x));
}

int grade_to_put(t_stack *stack, int number)
{
	t_stack_node	*node;
	int				grade;
	int				max;
	int				min;
	int				calc_mode;

	grade = 1;
	max = stack_max(stack)->data;
	min = stack_min(stack)->data;
	node = stack->top->next;
	calc_mode = 0;
	while(node)
	{
		if (check_between(node, number, max, min))
			return (grade);
		grade_update(&node, stack, &grade, &calc_mode);
	}
	if (stack_last_node(stack)->data > number && stack->top->data < number)
		return (0);
	return (grade);
}