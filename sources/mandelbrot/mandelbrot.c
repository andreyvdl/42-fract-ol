#include "../../include/fractol.h"

static void	mandelbrot_aux(
	t_s_engine *engine, double temp, int s_color, int e_color)
{
	int	red;
	int	green;
	int	blue;

	red = (((s_color >> 16) << 24) + (e_color >> 16));
	green = (((s_color >> 8) << 24) + ((e_color << 16) >> 24));
	blue = ((s_color << 24) + ((e_color << 24) >> 24));
	red = (int)((red >> 24) + temp * (((red << 24) >> 24) - (red >> 24)));
	green = (int)((green >> 24) + temp * (((green << 24) >> 24) \
	- (green >> 24)));
	blue = (int)((blue >> 24) + temp * (((blue << 24) >> 24) - (blue >> 24)));
	draw_on_img(engine, (red << 16) | (green << 8) | blue);
}

static void	draw_mandelbrot_pixel(t_s_engine *engine, double real, double imag)
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
		z_imag = 2 * z_real * z_imag + imag;
		z_real = temp;
	}
	if (iter == engine->fractal.max_iter)
		draw_on_img(engine, 0x000000);
	else if (engine->fractal.mode == E_COLOR)
		draw_on_img(engine, engine->fractal.color * iter);
	else
	{
		temp = (double)iter / engine->fractal.max_iter;
		mandelbrot_aux(engine, temp, 0, engine->fractal.color);
	}
}

void	mandelbrot_loop(t_s_engine *engine)
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
			draw_mandelbrot_pixel(engine, real, imag);
			++engine->win_x;
		}
		++engine->win_y;
	}
	mlx_put_image_to_window(engine->mlx, engine->win, engine->img, 0, 0);
}

void	mandelbrot(t_s_engine *engine)
{
	engine->fractal.x_min = -2.00;
	engine->fractal.y_max = 2.00;
	engine->fractal.x_max = 2.00;
	engine->fractal.y_min = -2.00;
	mandelbrot_loop(engine);
}
