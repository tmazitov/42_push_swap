/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:43:56 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/01 18:31:23 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../operations/operations.h"

int	make_sort(t_stack *a, t_stack *b);
int find_cheapest(t_stack *a, t_stack *b);
int	grade_to_put(t_stack *stack, int number);
int grade_to_take(t_stack *stack, int number);

typedef struct s_sort_inst
{
	int	rotate_a;
	int	rotate_b;
	int	cost;
}		t_sort_inst;


#endif // !SORT_H