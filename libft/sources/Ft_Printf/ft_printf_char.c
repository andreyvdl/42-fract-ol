/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:11:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 00:54:55 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	print_char(char byte)
{
	return ((int)write(STDOUT_FILENO, &byte, 1));
}

int	print_char_fd(int file_descriptor, char byte)
{
	if (file_descriptor >= 0)
		return ((int)write(file_descriptor, &byte, 1));
	return (0);
}
