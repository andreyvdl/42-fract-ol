#include "../../include/fractol.h"

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
	// mlx_mouse_hook(engine->win, mouse_hook, engine);
	engine->fractal.color = ft_rand(engine->fractal.max_iter, 32, 0xFFFFFF);
}
