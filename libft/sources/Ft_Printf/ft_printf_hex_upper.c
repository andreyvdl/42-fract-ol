/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:48:10 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 01:10:48 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	get_hex_uppercase(size_t number)
{
	char	byte;

	if (number < 10)
		byte = number + '0';
	else
		byte = number + 'A' - 10;
	return (byte);
}

int	print_hexadecimal_uppercase(size_t number)
{
	int		bytes_printed;
	char	byte;

	bytes_printed = 0;
	if (number > 15)
		bytes_printed += print_hexadecimal_uppercase(number / 16);
	byte = get_hex_uppercase(number % 16);
	bytes_printed += (int)write(STDOUT_FILENO, &byte, 1);
	return (bytes_printed);
}

int	print_hexadecimal_uppercase_fd(int file_descriptor, size_t number)
{
	int		bytes_printed;
	char	byte;

	bytes_printed = 0;
	if (number > 15)
		bytes_printed += print_hexadecimal_uppercase_fd(file_descriptor, \
														number / 16);
	byte = get_hex_uppercase(number % 16);
	bytes_printed += (int)write(file_descriptor, &byte, 1);
	return (bytes_printed);
}
