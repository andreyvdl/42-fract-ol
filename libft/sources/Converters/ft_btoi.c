/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:55:19 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	walk_on_whitespaces(const char **string)
{
	while (**string == ' ' || **string == '\t' || **string == '\n' || \
	**string == '\v' || **string == '\f' || **string == '\r')
		(*string)++;
}

/**
 * @brief Convert a binary string to an integer; The string is composed of
 * 			optional whitespaces, followed by a sequence of 0s and 1s; Only the
 * 			first sequence of digits is converted;
 * 
 * @param binary A pointer to the string to be converted;
 * @return The converted binary (int); 0 If the string is NULL or if the digits
 *			don't make part of the initial sequence;
 */
int	ft_btoi(const char *binary)
{
	int		number;

	if (binary == NIL)
		return (0);
	walk_on_whitespaces(&binary);
	number = 0;
	while (*binary == '0' || *binary == '1')
	{
		number <<= 1;
		if (*binary++ == '1')
			number |= 1;
	}
	return (number);
}
