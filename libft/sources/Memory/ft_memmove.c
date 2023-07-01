/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:55:02 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 16:44:05 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	copy_end_to_front(unsigned char *destiny, unsigned char *source, \
								size_t n)
{
	while (n--)
		*(destiny + n + 1) = *(source + n + 1);
}

static void	copy_front_to_end(unsigned char *destiny, unsigned char *source, \
								size_t n)
{
	while (n--)
		*destiny++ = *source++;
}

/**
 * @brief Copies n bytes from memory area src to memory area dst;
 * 
 * @attention If the memory areas overlap, it will move bytes backwards;
 * 
 * @param dst A pointer to the memory area of destiny;
 * @param src A pointer to the memory area of source;
 * @param n The number of bytes to be copied;
 * @return A pointer to the memory area of destiny (void *);
 */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (dst == NIL || src == NIL)
		return (dst);
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (temp_dst < temp_src)
		copy_front_to_end(temp_dst, temp_src, n);
	else
		copy_end_to_front(temp_dst, temp_src, n);
	return (dst);
}
