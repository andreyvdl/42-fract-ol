#include "../include/fractol.h"

int	select_to_draw(t_s_engine *engine)
{
	if (engine->fractal.name == E_MANDELBROT)
		mandelbrot_loop(engine);
	return (0);
}

void	draw_on_img(t_s_engine *engine, int color)
{
	char	*pixel;

	if (color < 0)
		color = -engine->fractal.color;
	pixel = engine->img_addr + (engine->win_y * engine->img_line
			+ engine->win_x * (engine->bits_pixel / 8));
	*(int *)pixel = color;
}
