/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:40:42 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Locates the first occurrence of c in the string pointed to by s;
 * 
 * @param s A pointer to the string to be scanned;
 * @param c The character to be located;
 * @return return a pointer to the located character (char *); Or NULL if the
 * 			character does not appear in the string or if s points to NULL;
 */
char	*ft_strchr(const char *s, int c)
{
	if (s == NIL)
		return (NIL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return (((char *)s));
	return (NIL);
}
