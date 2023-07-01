/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:23:02 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 01:26:55 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	print_positive_number(int number)
{
	int		bytes_printed;
	char	byte;

	bytes_printed = 0;
	if (number > 9)
		bytes_printed += print_positive_number(number / 10);
	byte = (number % 10) + '0';
	bytes_printed += (int)write(STDOUT_FILENO, &byte, 1);
	return (bytes_printed);
}

static int	print_negative_number(int number)
{
	int		bytes_printed;

	bytes_printed = 0;
	bytes_printed += (int)write(STDOUT_FILENO, "-", 1);
	if (number == INT_MIN)
	{
		bytes_printed += (int)write(STDOUT_FILENO, "2147483648", 10);
		return (bytes_printed);
	}
	bytes_printed += print_positive_number(number * -1);
	return (bytes_printed);
}

int	print_int(int number)
{
	if (number < 0)
		return (print_negative_number(number));
	return (print_positive_number(number));
}
