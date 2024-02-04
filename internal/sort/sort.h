/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:43:56 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/05 02:12:56 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../operations/operations.h"


typedef struct s_sort_inst
{
	int number;
	int	rotate_a;
	int	rotate_b;
	int	cost;
}		t_sort_inst;

int			make_sort(t_stack *a, t_stack *b);
int			sort_2(t_stack *a);
int			sort_3(t_stack *a);
int			grade_to_put(t_stack *stack, int number);
int 		grade_to_take(t_stack *stack, int number);
t_sort_inst	find_cheapest(t_stack *a, t_stack *b);
#endif // !SORT_H