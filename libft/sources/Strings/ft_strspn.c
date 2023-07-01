/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:22:48 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/19 00:13:14 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static bool	is_part(char byte, const char *accept)
{
	while (*accept != '\0')
	{
		if (*accept == byte)
			return (true);
		++accept;
	}
	return (false);
}

/**
 * @brief Returns the number of bytes in the initial segment of s which are in
 * the string accept;
 * @attention If s or accept is NULL, it returns 0;
 * 
 * @param s The pointer to the string to be analyzed;
 * @param accept The pointer to the string to compared;
 * @return The size of the initial segment of s which are in the accept
 * (size_t);
 */
size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	size;

	size = 0;
	if (s == NIL || accept == NIL)
		return (size);
	while (*s != '\0')
	{
		if (!is_part(*s, accept))
			return (size);
		++s;
		++size;
	}
	return (size);
}
