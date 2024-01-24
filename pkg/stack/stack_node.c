/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:17:14 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/24 18:17:49 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack.h"

t_stack_node *make_stack_node(int data)
{
	t_stack_node *node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void *free_stack_node(t_stack_node *node)
{
	if (!node)
		return (NULL);
	free(node);
	return (NULL);
}
