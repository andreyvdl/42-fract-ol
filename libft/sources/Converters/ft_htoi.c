/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:03:31 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 16:45:34 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	walk_on_whitespaces(const char **string)
{
	while (**string == ' ' || **string == '\t' || **string == '\n' || \
	**string == '\v' || **string == '\f' || **string == '\r')
		(*string)++;
}

static int	get_decimal_value(char byte)
{
	if (byte >= '0' && byte <= '9')
		return (byte - '0');
	else if (byte >= 'a' && byte <= 'f')
		return (byte - 'a' + 10);
	else if (byte >= 'A' && byte <= 'F')
		return (byte - 'A' + 10);
	return (-1);
}

static int	convert_hexadecimal(const char *hexadecimal)
{
	int	decimal;
	int	number;

	number = 0;
	while (*hexadecimal)
	{
		decimal = get_decimal_value(*hexadecimal++);
		if (decimal == -1)
			break ;
		number = number * 16 + decimal;
	}
	return (number);
}

/**
 * @brief Convert a hexadecimal string to an integer; The string is composed of
 * 			optional whitespaces, followed by an optional indicator of
 * 			hexadecimal, followed by a sequence of digits or letters from A to
 * 			F;
 * 
 * @param hexadecimal A pointer to the string to be converted;
 * @return 0 if the string is NULL or if the digits and letters don't make part
 * 			of the initial sequence; Otherwise, the converted number (int);
 */
int	ft_htoi(const char *hexadecimal)
{
	if (hexadecimal == NIL)
		return (0);
	walk_on_whitespaces(&hexadecimal);
	if (*hexadecimal == '0' && \
	(*(hexadecimal + 1) == 'x' || *(hexadecimal + 1) == 'X'))
		hexadecimal += 2;
	return (convert_hexadecimal(hexadecimal));
}
