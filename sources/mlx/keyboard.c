#include "../../include/fractol.h"

static void	change_color(t_s_engine *engine)
{
	write(STDERR_FILENO, "COR\n", 4);
	engine->fractal.color = ft_rand(engine->fractal.max_iter, 32, 0xFFFFFF);
	mlx_clear_window(engine->mlx, engine->win);
	select_to_draw(engine);
}

static void	change_iteration(int keycode, t_s_engine *engine)
{
	write(STDERR_FILENO, "ITE\n", 4);
	if (keycode == 'q')
	{
		if (engine->fractal.max_iter > 0)
			--(engine->fractal.max_iter);
	}
	else if (keycode == 'e')
	{
		if (engine->fractal.max_iter < SIZE_MAX)
			++(engine->fractal.max_iter);
	}
	mlx_clear_window(engine->mlx, engine->win);
	select_to_draw(engine);
}

static void	change_zoom(int keycode, t_s_engine *engine)
{
	float	x;
	float	y;


	x = (engine->fractal.x_max - engine->fractal.x_min);
	y = (engine->fractal.y_max - engine->fractal.y_min);
	if (keycode == XK_comma)
	{
		engine->fractal.x_min += x * 0.1;
		engine->fractal.y_min += y * 0.1;
		engine->fractal.x_max -= x * 0.1;
		engine->fractal.y_max -= y * 0.1;
	}
	else if (keycode == XK_period)
	{
		engine->fractal.x_min -= x * 0.1;
		engine->fractal.y_min -= y * 0.1;
		engine->fractal.x_max += x * 0.1;
		engine->fractal.y_max += y * 0.1;
	}
	mlx_clear_window(engine->mlx, engine->win);
	select_to_draw(engine);
}

static void	move_camera(int keycode, t_s_engine *engine)
{
	float	x;
	float	y;

	x = (engine->fractal.x_max - engine->fractal.x_min);
	y = (engine->fractal.y_max - engine->fractal.y_min);
	if (keycode == 'a' || keycode == 'h' || keycode == XK_Left)
	{
		engine->fractal.x_max -= x * 0.1;
		engine->fractal.x_min -= x * 0.1;
	}
	else if (keycode == 's' || keycode == 'j' || keycode == XK_Down)
	{
		engine->fractal.y_min += y * 0.1;
		engine->fractal.y_max += y * 0.1;
	}
	else if (keycode == 'w' || keycode == 'k' || keycode == XK_Up)
	{
		engine->fractal.y_max -= y * 0.1;
		engine->fractal.y_min -= y * 0.1;
	}
	else if (keycode == 'd' || keycode == 'l' || keycode == XK_Right)
	{
		engine->fractal.x_max += x * 0.1;
		engine->fractal.x_min += x * 0.1;
	}
}

int	user_keyboard(int keycode, t_s_engine *engine)
{
	if (keycode == 'h' || keycode == 'a' || keycode == XK_Left \
	|| keycode == 's' || keycode == 'j' || keycode == XK_Down \
	|| keycode == 'w' || keycode == 'k' || keycode == XK_Up \
	|| keycode == 'd' || keycode == 'l' || keycode == XK_Right)
	{
		move_camera(keycode, engine);
		mlx_clear_window(engine->mlx, engine->win);
		select_to_draw(engine);
	}
	else if (keycode == 'c')
		change_color(engine);
	else if (keycode == 'r')
		set_up_fractal(engine);
	else if (keycode == 'q' || keycode == 'e')
		change_iteration(keycode, engine);
	else if (keycode == XK_comma || keycode == XK_period)
		change_zoom(keycode, engine);
	else if (keycode == XK_Escape)
		mlx_loop_end(engine->mlx);
	return (0);
}
