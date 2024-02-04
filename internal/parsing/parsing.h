/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazitov <tmazitov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:59:16 by tmazitov          #+#    #+#             */
/*   Updated: 2024/02/05 01:50:05 by tmazitov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../pkg/stack/stack.h"
# include "../../pkg/utils/utils.h"

t_stack	*parse(char **argv);
int		validation(int argc, char **argv);
#endif