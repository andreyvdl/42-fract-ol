/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:11:06 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 21:42:49 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	print_positive_number(int number, int file_descriptor)
{
	char	byte;

	if (number > 9)
		print_positive_number(number / 10, file_descriptor);
	byte = number % 10 + '0';
	write(file_descriptor, &byte, 1);
}

static void	print_negative_number(int number, int file_descriptor)
{
	write(file_descriptor, "-", 1);
	if (number == INT_MIN)
	{
		write(file_descriptor, "2147483648", 10);
		return ;
	}
	print_positive_number(-number, file_descriptor);
}

/**
 * @brief Prints the integer n to the given file descriptor;
 * 
 * @param n The integer to be printed;
 * @param fd The number of the file descriptor;
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (fd > -1)
	{
		if (n < 0)
		{
			print_negative_number(n, fd);
			return ;
		}
		print_positive_number(n, fd);
	}
}
