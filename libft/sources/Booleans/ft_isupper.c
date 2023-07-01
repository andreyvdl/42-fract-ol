/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:36:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 18:07:52 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Checks for an uppercase letter;
 * 
 * @param c The character to be checked;
 * @return true if the character is uppercase; otherwise, false;
 */
bool	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (true);
	return (false);
}
