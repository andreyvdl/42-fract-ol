/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_prime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:52:31 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/23 15:38:21 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static uint32_t	basic_cases(int nb)
{
	if (nb < 2)
		return (2);
	else if (nb == 2)
		return (3);
	else if (nb < 5)
		return (5);
	else if (nb < 7)
		return (7);
	return (11);
}

/**
 * @brief Find the next prime of the received number;
 * @warning In case of overflow, the function will return 2, because is the 
 * lowest prime number;
 * 
 * @param nb The number we wish to find the next prime;
 * @return The next prime of the received number (uint32_t);
 */
uint32_t	ft_next_prime(int nb)
{
	if (nb <= 10)
		return (basic_cases(nb));
	while (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0 || nb % 7 == 0)
	{
		if (nb < 2)
			return (2);
		nb++;
	}
	return (nb);
}
