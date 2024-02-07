/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:12:38 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/06 19:54:04 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	calc_words_count(char const *str, char ch)
{
	int	counter;
	int	word_counter;

	word_counter = 0;
	counter = 0;
	while (str[counter])
	{
		if (str[counter] && str[counter] == ch)
			counter++;
		if (str[counter] && str[counter] != ch)
			word_counter++;
		while (str[counter] && str[counter] != ch)
			counter++;
	}
	return (word_counter);
}

static int	next_str_len(char const *str, char ch)
{
	int	counter;

	counter = 0;
	while (str[counter] && str[counter] != ch)
		counter++;
	return (counter);
}

static void	skip_space(char const *str, int *index, char ch)
{
	while (str[*index] && str[*index] == ch)
		(*index)++;
}

void	*free_split(char **result)
{
	int	counter;

	if (!result)
		return (NULL);
	counter = 0;
	while (result[counter])
		free(result[counter++]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *str, char ch)
{
	int		wrd_ctn;
	int		ctn;
	int		str_ctn;
	char	**result;

	if (!str)
		return (NULL);
	result = malloc((calc_words_count(str, ch) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	wrd_ctn = 0;
	str_ctn = 0;
	while (str[str_ctn])
	{
		skip_space(str, &str_ctn, ch);
		ctn = next_str_len(str + str_ctn, ch);
		if (ctn == 0)
			continue ;
		result[wrd_ctn] = ft_substr(str, str_ctn, ctn);
		if (!result[wrd_ctn++])
			return (free_split(result));
		str_ctn += ctn;
	}
	result[wrd_ctn] = NULL;
	return (result);
}
