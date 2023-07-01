/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_replace_chr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:44:02 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/19 00:26:30 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Search for find byte inside str and replace for put;
 * @attention If str is NULL it does nothing;
 * 
 * @param str A pointer to the string to be searched and replaced;
 * @param find The byte to be searched;
 * @param put The byte to replace the find;
 */
void	ft_search_replace_chr(char *str, char find, char put)
{
	if (str == NIL)
		return ;
	while (*str)
	{
		if (*str == find)
			*str = put;
		++str;
	}
}
