/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:47:48 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/23 23:17:35 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	print_unsigned_int(__u_int number)
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

int	print_unsigned_int_fd(int file_descriptor, __u_int number)
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
