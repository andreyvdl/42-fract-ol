/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:16:08 by adantas-          #+#    #+#             */
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

static int	negative_integer(const char *string)
{
	int	number;

	number = 0;
	while (*string >= '0' && *string <= '9')
		number = number * 10 + (*string++ - '0');
	return (number * -1);
}

static int	positive_integer(const char *string)
{
	int	number;

	number = 0;
	if (*string == '+')
		string++;
	while (*string >= '0' && *string <= '9')
		number = number * 10 + (*string++ - '0');
	return (number);
}

/**
 * @brief Convert a string to an integer; The string is composed of optional
 * 			whitespaces, followed by an optional sign, followed by a sequence of
 * 			digits; Only the first sequence of numbers is converted;
 * 
 * @param nptr A pointer to a string to be converted;
 * @return 0 if the string is NULL or if the numbers don't make part of the
 * 			initial sequence; Otherwise, the converted number (int);
 */
int	ft_atoi(const char *nptr)
{
	if (nptr == NIL)
		return (0);
	walk_on_whitespaces(&nptr);
	if (*nptr == '-')
		return (negative_integer(nptr));
	else if (*nptr == '+' || (*nptr >= '0' && *nptr <= '9'))
		return (positive_integer(nptr));
	return (0);
}
