/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:47:48 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/23 15:38:21 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	print_unsigned_int(uint32_t number)
{
	int		bytes_printed;
	char	byte;

	bytes_printed = 0;
	if (number > 9)
		bytes_printed += print_unsigned_int(number / 10);
	byte = (number % 10) + '0';
	bytes_printed += (int)write(STDOUT_FILENO, &byte, 1);
	return (bytes_printed);
}

int	print_unsigned_int_fd(int file_descriptor, uint32_t number)
{
	int		bytes_printed;
	char	byte;

	bytes_printed = 0;
	if (number > 9)
		bytes_printed += print_unsigned_int_fd(file_descriptor, number / 10);
	byte = (number % 10) + '0';
	bytes_printed += (int)write(file_descriptor, &byte, 1);
	return (bytes_printed);
}
