/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:02:32 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 01:37:11 by adantas-         ###   ########.fr       */
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

static int	print_address_as_hexadecimal_fd(int file_descriptor, size_t address)
{
	int		bytes_printed;
	char	byte;

	bytes_printed = 0;
	if (address > 15)
		bytes_printed += print_address_as_hexadecimal_fd(file_descriptor, \
														address / 16);
	byte = get_hexadecimal_digit(address % 16);
	bytes_printed += (int)write(file_descriptor, &byte, 1);
	return (bytes_printed);
}

int	print_ptr_fd(int file_descriptor, size_t address)
{
	if (address == 0)
		return ((int)write(file_descriptor, "(nil)", 5));
	return (print_address_as_hexadecimal_fd(file_descriptor, address));
}
