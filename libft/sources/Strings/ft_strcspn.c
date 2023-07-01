/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:59:05 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/19 00:28:14 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static bool	is_part(char byte, const char *str)
{
	while (*str != '\0')
	{
		if (*str == byte)
			return (true);
		++str;
	}
	return (false);
}

/**
 * @brief Returns the number of bytes in the initial segment of s which are not
 * in the string reject;
 * @attention If s or reject is NULL, it returns 0;
 * 
 * @param s The pointer to the string to be analyzed;
 * @param reject The pointer to the string to compared;
 * @return The size of the initial segment of s which are not in the reject
 * (size_t);
 */
size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	size;

	size = 0;
	if (s == NIL || reject == NIL)
		return (size);
	while (*s != '\0')
	{
		if (is_part(*s, reject))
			return (size);
		++s;
		++size;
	}
	return (size);
}
