/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:49:46 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 01:15:02 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	print_positive_number_fd(int file_descriptor, int number)
{
	int		bytes_printed;
	char	byte;

	bytes_printed = 0;
	if (number > 9)
		bytes_printed += print_positive_number_fd(file_descriptor, number / 10);
	byte = (number % 10) + '0';
	bytes_printed += (int)write(file_descriptor, &byte, 1);
	return (bytes_printed);
}

static int	print_negative_number_fd(int file_descriptor, int number)
{
	int	bytes_printed;

	bytes_printed = 0;
	bytes_printed += (int)write(file_descriptor, "-", 1);
	if (number == INT_MIN)
	{
		bytes_printed += (int)write(file_descriptor, "2147483648", 10);
		return (bytes_printed);
	}
	bytes_printed += print_positive_number_fd(file_descriptor, number * -1);
	return (bytes_printed);
}

int	print_int_fd(int file_descriptor, int number)
{
	if (number < 0)
		return (print_negative_number_fd(file_descriptor, number));
	return (print_positive_number_fd(file_descriptor, number));
}
