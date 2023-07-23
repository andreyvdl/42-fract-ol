/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:32:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/23 15:32:48 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	move_x_axies(t_s_engine *engine, int mouse_x)
{
	double	range;

	range = (engine->fractal.x_max - engine->fractal.x_min);
	if (mouse_x < WIDTH / 2)
	{
		engine->fractal.x_min -= range * 0.1;
		engine->fractal.x_max -= range * 0.1;
	}
	else if (mouse_x > WIDTH / 2)
	{
		engine->fractal.x_min += range * 0.1;
		engine->fractal.x_max += range * 0.1;
	}
}

static void	move_y_axies(t_s_engine *engine, int mouse_y)
{
	double	range;

	range = (engine->fractal.y_max - engine->fractal.y_min);
	if (mouse_y < HEIGHT / 2)
	{
		engine->fractal.y_min -= range * 0.1;
		engine->fractal.y_max -= range * 0.1;
	}
	else if (mouse_y > HEIGHT / 2)
	{
		engine->fractal.y_min += range * 0.1;
		engine->fractal.y_max += range * 0.1;
	}
}

static void	mouse_zoom_in(t_s_engine *engine)
{
	double	x;
	double	y;

	x = (engine->fractal.x_max - engine->fractal.x_min);
	y = (engine->fractal.y_max - engine->fractal.y_min);
	engine->fractal.x_min += x * 0.1;
	engine->fractal.y_min += y * 0.1;
	engine->fractal.x_max -= x * 0.1;
	engine->fractal.y_max -= y * 0.1;
}

static void	mouse_zoom_out(t_s_engine *engine)
{
	double	x;
	double	y;

	x = (engine->fractal.x_max - engine->fractal.x_min);
	y = (engine->fractal.y_max - engine->fractal.y_min);
	engine->fractal.x_min -= x * 0.1;
	engine->fractal.y_min -= y * 0.1;
	engine->fractal.x_max += x * 0.1;
	engine->fractal.y_max += y * 0.1;
}

int	user_mouse(int button, int x, int y, t_s_engine *engine)
{
	if (button == 4)
	{
		move_x_axies(engine, x);
		move_y_axies(engine, y);
		mouse_zoom_in(engine);
		mlx_clear_window(engine->mlx, engine->win);
		select_to_draw(engine);
	}
	else if (button == 5)
	{
		mouse_zoom_out(engine);
		mlx_clear_window(engine->mlx, engine->win);
		select_to_draw(engine);
	}
	return (0);
}
