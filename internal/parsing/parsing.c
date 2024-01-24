/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:59:35 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/25 00:54:54 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	**collect_numbers(char **argv)
{
	char	*number_union;
	char	**number_array;

	number_union = ft_strjoin((const char **)argv+1, ' ');
	if (!number_union)
		return (NULL);
	number_array = ft_split(number_union, ' ');
	free(number_union);
	return (number_array);
}

int	check_overflow(char *num)
{
	int		num_int;
	int		result;
	char	*num_check;

	num_int = ft_atoi(num);
	num_check = ft_itoa(num_int);
	if (!num_check)
		return (1);
	result = ft_strcmp(num_check, num);
	free(num_check); 
	return (result);
}

t_stack	*parse(char **argv)
{
	t_stack	*stack;
	char	**number_array;
	int		counter;
	
	number_array = collect_numbers(argv);
	if (!number_array)
		return (NULL);
	stack = make_stack();
	if (!stack)
		return (NULL);
	counter = 0;
	while (number_array[counter])
	{
		if (check_overflow(number_array[counter]))
			return (free_stack(stack), free_split(number_array));
		if (stack_push(stack, ft_atoi(number_array[counter])))
			return (free_stack(stack), free_split(number_array));
		counter += 1;
	}
	return (stack);
}