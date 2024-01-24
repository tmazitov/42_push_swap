/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:30:12 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/24 23:35:40 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	counter;
	int		result;

	counter = 0;
	result = 0;
	while ((str1[counter] || str2[counter]))
	{
		if (str1[counter] != str2[counter])
		{
			result = (unsigned char)str1[counter]
				- (unsigned char)str2[counter];
			return (result);
		}
		counter++;
	}
	return ((unsigned char)str1[counter] - (unsigned char)str2[counter]);
}