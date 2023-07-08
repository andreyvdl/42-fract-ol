#include "../include/fractol.h"

void	draw_on_img(t_s_engine *engine, uint32_t color)
{
	uint32_t	*pixel;

	pixel = (uint32_t *)engine->img_addr + (engine->win_y * engine->img_line
			+ engine->win_x * (engine->bits_pixel / 8));
	*pixel = color;
}
