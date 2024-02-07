/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:16:17 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/06 19:32:31 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../../pkg/stack/stack.h"

int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_stack *a, t_stack *b);

int		pa(t_stack *a, t_stack *b);
int		pb(t_stack *b, t_stack *a);

int		ra(t_stack *a);
int		rb(t_stack *b);
int		rr(t_stack *a, t_stack *b);

int		rra(t_stack *a);
int		rrb(t_stack *b);
int		rrr(t_stack *a, t_stack *b);

#endif // !OPERATIONS_H