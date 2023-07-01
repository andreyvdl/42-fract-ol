/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:15:01 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:21 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	print_string(char *string)
{
	int	bytes_printed;

	if (string == NIL)
		return ((int)write(STDOUT_FILENO, "(null)", 6));
	bytes_printed = 0;
	while (*string)
	{
		bytes_printed += (int)write(STDOUT_FILENO, string, 1);
		string++;
	}
	return (bytes_printed);
}

int	print_string_fd(int file_descriptor, char *string)
{
	int		bytes_printed;

	if (string == NIL)
		return ((int)write(file_descriptor, "(null)", 6));
	bytes_printed = 0;
	while (*string)
	{
		bytes_printed += (int)write(file_descriptor, string, 1);
		string++;
	}
	return (bytes_printed);
}
