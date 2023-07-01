/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:11:54 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	walk_on_whitespaces(const char **octal)
{
	while (**octal == ' ' || **octal == '\t' || **octal == '\n' || \
	**octal == '\v' || **octal == '\f' || **octal == '\r')
		(*octal)++;
}

/**
 * @brief Converts a string in octal to an integer; The string is composed of
 * 			optional whitespaces followed by a sequence of octal digits; The
 * 			function only converts the first sequence of octal digits;
 * 
 * @param octal The string to be converted;
 * @return 0 if the string is NULL or if the digits don't make part of the
 * 			initial sequence; Otherwise the converted octal (int);
 */
int	ft_otoi(const char *octal)
{
	int	number;

	if (octal == NIL)
		return (0);
	walk_on_whitespaces(&octal);
	number = 0;
	while (*octal != '\0' && (*octal >= '0' && *octal <= '7'))
		number = number * 8 + (*octal++ - '0');
	return (number);
}
