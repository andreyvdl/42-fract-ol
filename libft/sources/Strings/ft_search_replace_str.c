/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_replace_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:32:09 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/19 00:12:08 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	replace_these(char *str, char find, char put)
{
	while (*str)
	{
		if (*str == find)
			*str = put;
		++str;
	}
}

/**
 * @brief Search for all the bytes in find inside str and replace for put;
 * @attention If str, find or put is NULL it does nothing;
 * 
 * @param str A pointer to the string to be searched and replaced;
 * @param find A pointer to the string of bytes to be searched;
 * @param put A pointer to the string of bytes to replace the find;
 */
void	ft_search_replace_str(char *str, char *find, char *put)
{
	if (str == NIL || find == NIL || put == NIL)
		return ;
	while (*find != '\0' && *put != '\0')
		replace_these(str, *find++, *put++);
}
