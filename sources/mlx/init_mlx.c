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
	//mlx_do_key_autorepeaton(engine->mlx);
	//mlx_expose_hook(engine->win, expose_hook, engine);
	// mlx_key_hook(engine->win, key_hook, engine);
	// mlx_mouse_hook(engine->win, mouse_hook, engine);
}
