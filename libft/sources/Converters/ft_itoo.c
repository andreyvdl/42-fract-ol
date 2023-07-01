/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:53:24 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	get_size(int number)
{
	int	size;

	size = 1;
	while (number > 7)
	{
		number /= 8;
		size++;
	}
	return (size);
}

static char	*allocate_and_fill(int number, int size)
{
	char	*array;

	array = (char *)malloc(sizeof(char) * (size + 1));
	if (array == NIL)
		return (NIL);
	*(array + size) = '\0';
	while (size--)
	{
		*(array + size) = number % 8 + '0';
		number /= 8;
	}
	return (array);
}

static char	*allocate_and_fill(int number, int size);

/**
 * @brief Converts an integer to octal
 * 
 * @param n The integer to be converted
 * @return NULL if the integer is negative; Otherwise, the converted number
 * 			in octal (char *);
 */
char	*ft_itoo(int n)
{
	int	size;

	if (n < 0)
		return (NIL);
	size = get_size(n);
	return (allocate_and_fill(n, size));
}
