/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:08:22 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/14 21:30:22 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	get_string_size(char *string)
{
	size_t	size;

	size = 0;
	while (string[size])
		size++;
	return (size);
}

/**
 * @brief Concatenates two strings; The destiny string must have enough space to
 * 			receive the source string;
 * 
 * @param dest A pointer to the destiny string;
 * @param src A pointer to the string that will be added to the destiny string;
 * @return A pointer to the concatenated destiny string (char *);
 */
char	*ft_strcat(char *dest, char *src)
{
	char	*temp;

	temp = dest;
	temp += get_string_size(dest);
	while (*src)
		*temp++ = *src++;
	*temp = '\0';
	return (dest);
}
