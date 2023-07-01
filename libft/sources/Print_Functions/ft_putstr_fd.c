/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:55:53 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Prints the string s to the file descriptor fd;
 * 
 * @param s A pointer to the string to be printed;
 * @param fd The number of the file descriptor;
 * 
 */
void	ft_putstr_fd(char *s, int fd)
{
	if (s == NIL || fd < 0)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
