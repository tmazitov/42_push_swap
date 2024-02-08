/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:41:53 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/08 16:10:53 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_numbers(char **argv)
{
	int		counter;
	int		word_counter;
	char	ch;

	counter = 0;
	while (argv[counter])
	{
		word_counter = 0;
		while (argv[counter][word_counter])
		{
			ch = argv[counter][word_counter];
			if ((ch < '0' || ch > '9') && 
				ch != ' ' && ch != '+' && ch != '-')
				return (0);
			word_counter++;
		}
		counter += 1;
	}
	return (1);
}

static int	check_values(char **argv)
{
	int	counter;
	int	word_counter;
	int	digit_counter;

	counter = 0;
	while (argv[counter])
	{
		word_counter = 0;
		digit_counter = 0;
		while (argv[counter][word_counter])
		{
			if (argv[counter][word_counter] >= '0' &&
				argv[counter][word_counter] <= '9')
				digit_counter += 1;
			word_counter++;
		}
		if (digit_counter == 0)
			return (0);
		counter += 1;
	}
	return (1);
}

int	validation(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (!check_values(argv + 1))
		return (0);
	if (!check_numbers(argv + 1))
		return (0);
	return (1);
}
