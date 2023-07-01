/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:57:51 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/23 20:41:55 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief A pseudo-random number generator based on Linear Congruential
 * Generator (LCG) algorithm: Xₙ₊₁ = (a.Xₙ + c) mod m;
 * @attention on first execution with seed unset, the default initial value will
 * be 42;
 * 
 * @param seed The seed of the random number;
 * @param min The minimum value of return;
 * @param max The maximum value of return;
 * @return The random number (size_t) between min and max (inclusive) or 0 if
 * min >= max;
 */
size_t	ft_rand(size_t seed, size_t min, size_t max)
{
	static size_t	rand = 42;
	static size_t	last_seed;

	if (min >= max)
		return (0);
	if (seed != 0 && seed != last_seed)
		rand = seed;
	rand = (LCG_MULTIPLIER * rand + 1) % max;
	if (rand == 0)
		rand = max;
	if (rand < min)
		rand += min;
	last_seed = seed;
	return (rand + 1);
}
