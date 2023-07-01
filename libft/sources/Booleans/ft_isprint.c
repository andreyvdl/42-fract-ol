/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:23:55 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 18:07:45 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Checks for any printable character including space;
 * 
 * @param c The character to be checked;
 * @return true if the character is printable; otherwise, false;
 */
bool	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (true);
	return (false);
}
