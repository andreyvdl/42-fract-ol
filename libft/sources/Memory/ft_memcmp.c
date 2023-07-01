/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:54:31 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 16:58:18 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Compares bytes of the memory area s1 against memory area s2, both are
 *			assumed to be n bytes long;
 * 
 * @param s1 A pointer to the first memory area to be compared;
 * @param s2 A pointer to the second memory area to be compared;
 * @param n The maximum
 * @return The difference between the two first differing bytes (int)
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	if (n == 0)
		return (0);
	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	while (n--)
	{
		if (*temp1++ != *temp2++)
			return (*(temp1--) - *(temp2--));
	}
	return (0);
}
