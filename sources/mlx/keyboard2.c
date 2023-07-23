#include "../../include/fractol.h"

static void	change_mode(t_s_engine *engine)
{
	if (engine->fractal.mode == E_COLOR)
	{
		engine->fractal.mode = E_GRADIENT;
		ft_putendl("Gradient mode");
	}
	else
	{
		engine->fractal.mode = E_COLOR;
		ft_putendl("Color mode");
	}
	mlx_clear_window(engine->mlx, engine->win);
	select_to_draw(engine);
}

static void	change_fractal(t_s_engine *engine)
{
	if (engine->fractal.name + 1 == E_JULIA && (engine->fractal.julia_cx < -2.0 \
	|| engine->fractal.julia_cx > 2.0 || engine->fractal.julia_cy < -2.0 \
	|| engine->fractal.julia_cy > 2.0))
	{
		engine->fractal.julia_cx = -0.7600;
		engine->fractal.julia_cy = -0.0900;
		++engine->fractal.name;
	}
	else if (engine->fractal.name == E_TRICORN)
		engine->fractal.name = E_MANDELBROT;
	else
		++engine->fractal.name;
	ft_putendl("Fractal changed");
}

void	look_more(int keycode, t_s_engine *engine)
{
	if (keycode == 'm')
		change_mode(engine);
	else if (keycode == 'f')
	{
		change_fractal(engine);
		select_to_draw(engine);
	}
}
