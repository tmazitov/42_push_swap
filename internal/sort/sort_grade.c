/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_grade.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:14:58 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/01 19:03:17 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	max_grade(t_stack *stack)
{
	return (stack->size / 2);
}

static void	grade_update(t_stack_node **node, int max, int *grade, int *mode)
{
	if (*grade == max && *mode == 0)
	{
		*mode = 1;
		*grade = *grade * -1;
		*node = (*node)->next;
		return ;
	}
	*grade += 1;
	*node = (*node)->next;
}

int path_to_value(t_stack *stack, int value)
{
	t_stack_node	*node;
	int				grade;
	int				max;
	int				calc_mode;

	grade = 0;
	max = max_grade(stack);
	node = stack->top;
	calc_mode = 0;
	while(node)
	{
		if (node->data == value)
			return (grade);
		if (grade == max && calc_mode == 0 && stack->size % 2 == 0)
		{
			grade_update(&node, max, &grade, &calc_mode);
			grade++;	
			continue ;
		}
		grade_update(&node, max, &grade, &calc_mode);
	}
	return (-1);
}


int grade_to_take(t_stack *stack, int number)
{
	return (path_to_value(stack, number));
}


int	grade_to_put(t_stack *stack, int number)
{
	int				min;
	int				max;
	int				grade;
	int				calc_mode;
	t_stack_node	*node;

	min = stack_min(stack)->data;
	max = stack_max(stack)->data;
	if (number < min)
		return (path_to_value(stack, min));
	if (number > max)
		return (path_to_value(stack, max));
	grade = 1;
	calc_mode = 0;
	node = stack->top->next;
	while (node)
	{
		// if (number == 8)
		// 	ft_printf("grade %d\n", grade);
		if (number < node->prev->data && number > node->data)
			return (grade);
		grade_update(&node, max_grade(stack), &grade, &calc_mode);
	}
	node = stack->top->next;
	if (stack_last_node(stack)->data > number && node->data > number && stack->top->data > number)
		return (0);
	return (-1);
}