/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:55:55 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 01:34:43 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	get_hexadecimal_digit(size_t address)
{
	char	byte;

	if (address < 10)
		byte = address + '0';
	else
		byte = address + 'a' - 10;
	return (byte);
}

static int	print_address_as_hexadecimal(size_t address)
{
	int		bytes_printed;
	char	byte;

	bytes_printed = 0;
	if (address > 15)
		bytes_printed += print_address_as_hexadecimal(address / 16);
	byte = get_hexadecimal_digit(address % 16);
	bytes_printed += (int)write(STDOUT_FILENO, &byte, 1);
	return (bytes_printed);
}

int	print_ptr(size_t address)
{
	if (address == 0)
		return ((int)write(STDOUT_FILENO, "(nil)", 5));
	return (print_address_as_hexadecimal(address));
}
