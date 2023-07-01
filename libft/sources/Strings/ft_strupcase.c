/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:20:50 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:21 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Converts all lowercase letters of a string to uppercase;
 * 
 * @param str A pointer to the string;
 * @return the string converted (char *);
 */
char	*ft_strupcase(char *str)
{
	size_t	index;

	if (str == NIL)
		return (NIL);
	index = 0;
	while (str[index])
	{
		if (str[index] >= 'a' && str[index] <= 'z')
			str[index] -= 32;
		index++;
	}
	return (str);
}
