#include "../include/fractol.h"

void	draw_on_img(t_s_engine *engine, int color)
{
	char	*pixel;

	if (color < 0)
		color = engine->fractal.color * 2;
	pixel = engine->img_addr + (engine->win_y * engine->img_line
			+ engine->win_x * (engine->bits_pixel / 8));
	*(int *)pixel = color;
}
