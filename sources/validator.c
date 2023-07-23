/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:31:53 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/23 15:31:55 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	validator(t_s_fractal *fractal, char *argv[])
{
	if (name_is_wrong(&(fractal->name), *argv))
		wrong_arg(*argv);
	++argv;
	if (fractal->name == E_JULIA)
		validate_julia(fractal, argv);
}
