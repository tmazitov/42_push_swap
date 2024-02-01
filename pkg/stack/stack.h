/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:11:54 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/01 16:16:56 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "../printf/ft_printf.h"

typedef struct		s_stack
{
	struct s_stack_node	*top;
	int					size;
}		t_stack;

typedef struct s_stack_node
{
	int					data;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}		t_stack_node;

typedef  enum{
	MAX_TO_MIN = 0,
	MIN_TO_MAX = 1,
}	s_sort_type;

// STACK
t_stack	*make_stack();
void	*free_stack(t_stack *stack);

t_stack_node	*stack_last_node(t_stack *stack);

int		stack_pop(t_stack	*stack);
int		stack_push(t_stack *stack, int num);
int		stack_swap(t_stack *stack);
int		stack_rotate(t_stack *stack);
int		stack_rotate_reverse(t_stack *stack);
int		stack_includes(t_stack *stack, int data);
void	stack_print(t_stack *stack);
int		stack_is_equal(t_stack *a, t_stack *b);
int		stack_is_sorted(t_stack *stack, s_sort_type type);
t_stack_node	*stack_min(t_stack *stack);
t_stack_node	*stack_max(t_stack *stack);
// STACK NODE
t_stack_node	*make_stack_node(int data);
void			*free_stack_node(t_stack_node *node);
#endif