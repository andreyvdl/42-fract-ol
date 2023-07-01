/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:36:27 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:40:38 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	write_string(char *str)
{
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}

/**
 * @brief Print a string to the standard output, followed by a new line;
 * @attention If the string is NULL, it only prints a new line;
 * 
 * @param s The string to be printed;
 */
void	ft_putendl(char *s)
{
	if (s != NIL)
		write_string(s);
	write(STDOUT_FILENO, "\n", 1);
}
