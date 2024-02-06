/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:10:24 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/06 19:54:09 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

char	**ft_split(char const *str, char ch);
void	*free_split(char **result);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const **strs, char separator);
char	*ft_strchr(const char *str, int ch);
int		ft_isdigit(int ch);
int		ft_atoi(char const *str);
char	*ft_itoa(int n);
int		ft_strcmp(const char *str1, const char *str2);

#endif