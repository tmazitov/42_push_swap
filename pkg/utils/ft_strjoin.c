/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:21:24 by tmazitov          #+#    #+#             */
/*   Updated: 2024/01/25 00:29:42 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	calc_total_length(char const **strs)
{
	int		count;
	
	count = 0;
	while (*strs)
	{
		count += ft_strlen(*strs);
		if (strs + 1 != NULL)
			count += 1;
		strs++;
	}
	return (count);
}

char	*ft_strjoin(char const **strs, char separator)
{
	char	*result;
	int		total_length;
	int		counter;

	if (!strs)
		return (NULL);
	counter = 0;
	total_length = calc_total_length(strs);
	result = malloc(sizeof(char) * (total_length + 1));
	if (!result)
		return (NULL);
	while (*strs && counter < total_length)
	{
		while (**strs)
			result[counter++] = **strs++;
		if (strs + 1 != NULL)
			result[counter++] = separator;
		strs++;
	}
	result[counter] = '\0';
	return (result);
}