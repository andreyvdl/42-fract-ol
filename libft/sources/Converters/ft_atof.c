/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:29:32 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/02 18:42:57 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	walk_on_whitespaces(const char **fptr)
{
	while (**fptr == ' ' || **fptr == '\t' || **fptr == '\n' || \
	**fptr == '\v' || **fptr == '\f' || **fptr == '\r')
		++(*fptr);
}

static float	negative_float(const char *fptr)
{
	float	number;
	float	decimal;

	number = 0.0;
	while (*fptr >= '0' && *fptr <= '9')
		number = number * 10 + (*fptr++ - '0');
	if (*fptr == '.')
		++fptr;
	decimal = 0.1;
	while (*fptr >= '0' && *fptr <= '9')
	{
		number = number + (*fptr++ - '0') * decimal;
		decimal /= 10;
	}
	return (-number);
}

static float	positive_float(const char *fptr)
{
	float	number;
	float	decimal;

	number = 0.0;
	while (*fptr >= '0' && *fptr <= '9')
		number = number * 10 + (*fptr++ - '0');
	if (*fptr == '.')
		++fptr;
	decimal = 0.1;
	while (*fptr >= '0' && *fptr <= '9')
	{
		number = number + (*fptr++ - '0') * decimal;
		decimal /= 10;
	}
	return (number);
}

/**
 * @brief Convert a string to a float; The string is composed of optional
 * 	whitespaces, followed by an optional sign, followed by a sequence of
 * 	digits, optionally containing a decimal-point character; Only the
 * 	first sequence of numbers is converted;
 * 
 * @param fptr The pointer to the string to be converted;
 * @return A floating point number (float);
 */
float	ft_atof(const char *fptr)
{
	if (fptr == NIL)
		return (0.0);
	walk_on_whitespaces(&fptr);
	if (*fptr == '-')
		return (negative_float(++fptr));
	else if (*fptr == '+')
		return (positive_float(++fptr));
	return (positive_float(fptr));
}
