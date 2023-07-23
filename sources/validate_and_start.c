/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:31:33 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/23 15:31:36 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	set_up_fractal(t_s_engine *engine)
{
	if (engine->fractal.name == E_MANDELBROT)
		mandelbrot(engine);
	else if (engine->fractal.name == E_JULIA)
		julia(engine);
	else if (engine->fractal.name == E_BURNING_SHIP)
		burning_ship(engine);
	else if (engine->fractal.name == E_TRICORN)
		tricorn(engine);
	else if (engine->fractal.name == E_HYDRA)
		hydra(engine);
}

void	validate_and_start(char *argv[])
{
	t_s_engine	engine;

	validator(&(engine.fractal), argv);
	init_mlx(&engine);
	set_up_fractal(&engine);
	print_help();
	mlx_loop(engine.mlx);
	destroy_mlx(&engine);
	exit(EXIT_SUCCESS);
}
