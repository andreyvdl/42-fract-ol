#include "../../include/fractol.h"

static void	init_fractal_settings(t_s_engine *engine)
{
	engine->fractal.max_iter = 100;
	engine->fractal.color = ft_rand(engine->fractal.max_iter, 0, 0xFFFFFF);
	engine->fractal.mode = E_COLOR;
}

void	init_mlx(t_s_engine *engine)
{
	engine->mlx = mlx_init();
	if (engine->mlx == NIL)
		x_server_fail();
	engine->win = mlx_new_window(engine->mlx, WIDTH, HEIGHT, TITLE);
	if (engine->win == NIL)
		x_win_fail(engine->mlx);
	engine->img = mlx_new_image(engine->mlx, WIDTH, HEIGHT);
	if (engine->img == NIL)
		x_img_fail(engine->mlx, engine->win);
	engine->img_addr = mlx_get_data_addr(engine->img, &(engine->bits_pixel),
			&(engine->img_line), &(engine->endian));
	mlx_expose_hook(engine->win, &select_to_draw, engine);
	mlx_hook(engine->win, KeyPress, KeyPressMask, &user_keyboard, engine);
	mlx_hook(engine->win, DestroyNotify, NoEventMask, &destroy_mlx, engine);
	mlx_mouse_hook(engine->win, &user_mouse, engine);
	init_fractal_settings(engine);
}
