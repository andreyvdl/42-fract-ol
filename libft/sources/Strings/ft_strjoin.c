/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:52:27 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:21 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	get_string_size(char const *string)
{
	size_t	size;

	size = 0;
	while (string[size] != '\0')
		size++;
	return (size);
}

static void	concatenate_strings(char *joined, char const *string1, \
								char const *string2)
{
	while (*string1)
		*joined++ = *string1++;
	while (*string2)
		*joined++ = *string2++;
	*joined = '\0';
}

/**
 * @brief Allocates and return a new string, which is the result of the
 * 			concatenation of s1 and s2;
 * 
 * @param s1 A pointer to the first string;
 * @param s2 A pointer to the second string;
 * @return The new string (char *); Or NULL if any of the strings is NULL or if
 * 			the allocation fails;
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	total_size;

	if (s1 == NIL || s2 == NIL)
		return (NIL);
	total_size = get_string_size(s1) + get_string_size(s2);
	joined = (char *)malloc(sizeof(char) * (total_size + 1));
	if (joined == NIL)
		return (NIL);
	concatenate_strings(joined, s1, s2);
	return (joined);
}
