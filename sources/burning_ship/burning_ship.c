#include "../../include/fractol.h"

static void	gradient(t_s_engine *engine, double temp, int dark, int color)
{
	int	red;
	int	green;
	int	blue;

	red = (int)(((dark >> 16) & 255) + temp * (((color >> 16) & 255) \
	- ((dark >> 16) & 255)));
	green = (int)(((dark >> 8) & 255) + temp * (((color >> 8) & 255) \
	- ((dark >> 8) & 255)));
	blue = (int)((dark & 255) + temp * ((color & 255) - (dark & 255)));
	draw_on_img(engine, (red << 16) | (green << 8) | blue);
}

/*
the horn: z_imag = fabs(2 * z_real * z_imag) + imag * imag;
the bucket: temp = z_real * z_real - z_imag * z_imag + real * real;
The double soundwave:
	temp = z_real * z_real - z_imag * z_imag - real * real;
	z_imag = fabs(2 * z_real * z_imag) + imag * imag;
the explosion: temp = z_real * z_real - z_imag * z_imag - real * real;
*/
static void	draw_ship_pixel(t_s_engine *engine, double real, double imag)
{
	double	z_real;
	double	z_imag;
	double	temp;
	size_t	iter;

	z_real = 0;
	z_imag = 0;
	iter = -1;
	while (++iter < engine->fractal.max_iter \
	&& z_real * z_real + z_imag * z_imag <= 4)
	{
		temp = z_real * z_real - z_imag * z_imag + real;
		z_imag = fabs(2 * z_real * z_imag) + imag;
		z_real = temp;
	}
	if (iter == engine->fractal.max_iter)
		draw_on_img(engine, 0);
	else if (engine->fractal.mode == E_COLOR)
		draw_on_img(engine, engine->fractal.color * iter);
	else
	{
		temp = (double)iter / engine->fractal.max_iter;
		gradient(engine, temp, 0, engine->fractal.color);
	}
}

void	ship_loop(t_s_engine *engine)
{
	double	real;
	double	imag;

	engine->win_y = 0;
	while (engine->win_y < HEIGHT)
	{
		engine->win_x = 0;
		while (engine->win_x < WIDTH)
		{
			real = engine->fractal.x_min + engine->win_x \
			* (engine->fractal.x_max - engine->fractal.x_min) / WIDTH;
			imag = engine->fractal.y_min + engine->win_y \
			* (engine->fractal.y_max - engine->fractal.y_min) / HEIGHT;
			draw_ship_pixel(engine, real, imag);
			++engine->win_x;
		}
		++engine->win_y;
	}
	mlx_put_image_to_window(engine->mlx, engine->win, engine->img, 0, 0);
}

void	burning_ship(t_s_engine *engine)
{
	engine->fractal.x_min = -2.00;
	engine->fractal.y_max = 2.00;
	engine->fractal.x_max = 2.00;
	engine->fractal.y_min = -2.00;
	ship_loop(engine);
}
