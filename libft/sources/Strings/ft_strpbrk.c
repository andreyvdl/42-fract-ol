/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:57:42 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/19 00:12:51 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static bool	is_match(char byte, const char *accept)
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
 * @brief Search for the first occurrence of any byte from the string accept in
 * the string s.
 * @attention If s or accept is NULL, it returns NULL;
 * 
 * @param s The pointer to the string to be searched;
 * @param accept The pointer to the string to be matched;
 * @return A pointer to the byte in s that matches one of the bytes in accept,
 * (char *) or NULL if no such byte is found.
 */
char	*ft_strpbrk(const char *s, const char *accept)
{
	if (s == NIL || accept == NIL)
		return (NIL);
	while (*s != '\0')
	{
		if (is_match(*s, accept))
			return ((char *)s);
		++s;
	}
	return (NIL);
}
