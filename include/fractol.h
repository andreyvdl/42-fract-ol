#ifndef FRACTOL_H
# define FRACTOL_H

// https://mathigon.org/course/fractals/introduction

/* Include ================================================================== */

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

/* Defines ================================================================== */

# define BURNING_SHIP_STR "BURNING SHIP"
# define MANDELBROT_STR "MANDELBROT"
# define TRICORN_STR "TRICORN"
# define JULIA_STR "JULIA"

# define TITLE "adantas- fract'ol"
# define WIDTH 800
# define HEIGHT 600

# define CODE_CONREF 111
# define CODE_IIOCTL 25
# define CODE_INVARG 22

/* Texts ==================================================================== */

# define ERR_X_SERVER "\e[1;31mX-Server conenction failed\e[0m\n"
# define ERR_ARG_NULL "\e[1;31mArg %d is null\e[0m\n"
# define ERR_MISSING "\e[1;31mMissing args\e[0m\n"
# define ERR_MANY "\e[1;31mToo many args\e[0m\n"
# define ERR_ARG "\e[1;31mWrong arg `%s`\e[0m\n"
# define ERR_WIN "\e[1;31mWindow creation failed\e[0m\n"
# define ERR_IMG "\e[1;31mImage creation failed\e[0m\n"

# define USAGE_STR "Usage: \e[1;32m./fractol\e[0m \e[1;3;4;31mfractal_name\
\e[0m [\e[1;3;4;31mfractal_options\e[0m \e[1;3;4;31m...\e[0m]\n\n\
fractol_name can be MANDELBROT | JULIA\n\
if is JULIA, need to add 2 options between -2.0 and 2.0\n"

/* Types ==================================================================== */

/**
 * @brief Enum for fractal color mode
 * 
 * @param E_COLOR equal to 0;
 * @param E_GRADIENT equal to 1;
 */
typedef enum e_mode {
	E_COLOR,
	E_GRADIENT,
}	t_e_mode;

/**
 * @brief Enum for the fractal name
 * 
 * @param E_MANDELBROT equal to 0;
 * @param E_JULIA equal to 1;
 * @param E_BURNING_SHIP equal to 2;
 * @param E_TRICORN equal to 3;
 */
typedef enum e_name {
	E_MANDELBROT,
	E_JULIA,
	E_BURNING_SHIP,
	E_TRICORN,
}	t_e_name;

/**
 * @brief Struct for the fractal
 * 
 * @param name enum of the fractal name
 * @param mode enum of the fractal color mode
 * @param max_iter the max iteration for the fractal
 * @param x_min the min x value of the fractal
 * @param x_max the max x value of the fractal
 * @param y_max the max y value of the fractal
 * @param y_min the min y value of the fractal
 * @param color the color of the fractal
 * @param julia_cx the const x value of the julia fractal
 * @param julia_cy the const y value of the julia fractal
 */
typedef struct s_fractal {
	t_e_name	name;
	t_e_mode	mode;
	size_t		max_iter;
	double		x_min;
	double		x_max;
	double		y_max;
	double		y_min;
	uint32_t	color;
	double		julia_cx;
	double		julia_cy;
}	t_s_fractal;

/**
 * @brief Struct for the mlx
 * 
 * @param fractal the fractal struct
 * @param win_x the width of the window
 * @param win_y the height of the window
 * @param img_addr the address of the image
 * @param img the image
 * @param mlx the X-server pointer
 * @param win the window pointer
 * @param bits_pixel the bits per pixel of the image
 * @param img_line the size of one line of the image
 * @param endian the most important bit of the image
 */
typedef struct s_engine {
	t_s_fractal	fractal;
	size_t		win_x;
	size_t		win_y;
	char		*img_addr;
	void		*img;
	void		*mlx;
	void		*win;
	int			bits_pixel;
	int			img_line;
	int			endian;
}	t_s_engine;

/* Functions ================================================================ */

bool	name_is_wrong(t_e_name *name, char *arg);

int		user_mouse(int button, int x, int y, t_s_engine *engine);
int		user_keyboard(int keycode, t_s_engine *engine);
int		select_to_draw(t_s_engine *engine);
int		destroy_mlx(t_s_engine *engine);

void	validate_julia(t_s_fractal *fractal, char *argv[]);
void	validator(t_s_fractal *fractal, char *argv[]);
void	draw_on_img(t_s_engine *engine, int color);
void	look_more(int keycode, t_s_engine *engine);
void	mandelbrot_loop(t_s_engine *engine);
void	set_up_fractal(t_s_engine *engine);
void	x_img_fail(void *mlx, void *win);
void	burning_ship(t_s_engine *engine);
void	tricorn_loop(t_s_engine *engine);
void	validate_and_start(char *argv[]);
void	julia_loop(t_s_engine *engine);
void	mandelbrot(t_s_engine *engine);
void	arg_is_null(uint8_t position);
void	ship_loop(t_s_engine *engine);
void	init_mlx(t_s_engine *engine);
void	tricorn(t_s_engine *engine);
void	extract_julia(char *argv[]);
void	julia(t_s_engine *engine);
void	x_win_fail(void *mlx);
void	wrong_arg(char *arg);
void	print_options(void);
void	x_server_fail(void);
void	argc_too_big(void);
void	print_help(void);

#endif
