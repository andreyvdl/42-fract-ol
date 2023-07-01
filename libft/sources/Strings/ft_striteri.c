/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:56:17 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/23 23:17:35 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Applies the function f to each character of the string s;
 * 
 * @attention If the string or the function pointer is NULL, the function does
 * 				nothing;
 * @param s A pointer to the string to be iterated;
 * @param f A pointer to the function to be applied to each character;
 */
void	ft_striteri(char *s, void (*f)(__u_int, char*))
{
	__u_int	index;

	if (s == NIL || f == NIL)
		return ;
	index = 0;
	while (s[index] != '\0')
	{
		(*f)(index, s + index);
		index++;
	}
}
