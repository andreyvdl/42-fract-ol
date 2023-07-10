#include "../../include/fractol.h"

static void	draw_mandelbrot_pixel(t_s_engine *engine, float real, float imag)
{
	float	z_real;
	float	z_imag;
	float	temp;
	size_t	iter;

	z_real = 0;
	z_imag = 0;
	iter = -1;
	while (++iter < engine->fractal.max_iter)
	{
		temp = z_real * z_real - z_imag * z_imag + real;
		z_imag = 2 * z_real * z_imag + imag;
		z_real = temp;
		if (z_real * z_real + z_imag * z_imag > 4)
			break ;
	}
	if (iter == engine->fractal.max_iter)
		draw_on_img(engine, 0x000000);
	else
	{
		++iter;
		draw_on_img(engine, engine->fractal.color * iter);
	}	
}

void	mandelbrot_loop(t_s_engine *engine)
{
	float	real;
	float	imag;

	engine->win_y = 0;
	while (engine->win_y < HEIGHT)
	{
		engine->win_x = 0;
		while (engine->win_x < WIDTH)
		{
			real = engine->fractal.x_min + engine->win_x * (engine->fractal.x_max - engine->fractal.x_min) / WIDTH;
			imag = engine->fractal.y_min + engine->win_y * (engine->fractal.y_max - engine->fractal.y_min) / HEIGHT;
			draw_mandelbrot_pixel(engine, real, imag);
			++engine->win_x;
		}
		++engine->win_y;
	}
	mlx_put_image_to_window(engine->mlx, engine->win, engine->img, 0, 0);
}

void	mandelbrot(t_s_engine *engine)
{
	engine->fractal.x_min = -2.0;
	engine->fractal.y_max = 2.0;
	engine->fractal.x_max = 2.0;
	engine->fractal.y_min = -2.0;
	engine->fractal.zoom = 1.00;
	engine->fractal.max_iter = 21;
	engine->fractal.color = ft_rand(engine->fractal.max_iter, 32, 0xFFFFFF);
	mandelbrot_loop(engine);
}
