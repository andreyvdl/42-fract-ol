/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:39:14 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/01 02:33:59 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Calculates the factorial of a given number; The number must be a 
 * 			spositive integer;
 * @warning If n is higher than 12 it will result in an overflow; Remeber the
 * 			limit of uint32_t is 4.294.967.295;
 * 
 * @param n The number to calculate the factorial;
 * @return The total of the factorial (uint32_t);
 */
uint32_t	ft_factorial(uint32_t n)
{
	uint32_t	total;

	if (n == 1 || n == 0)
		return (1);
	total = 1;
	while (n > 1)
	{
		total *= n;
		n--;
	}
	return (total);
}
