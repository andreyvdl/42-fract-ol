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

# define MANDELBROT_STR "MANDELBROT"
# define JULIA_STR "JULIA"
# define TITLE "adantas- fract'ol"

/*
WiiU | Switch 1280×720 1280×800 1280×768
3DS 400×240
3DS | GameCube | PS1 | N64 | Wii 640×480
Wii | N64 | GameCube 800×600
SNES 372×240
WiiU 1366×768
PS1 | GameCube 640×240
PSP 480×272
PS1 368×240 512×240 368×480 256×240
MegaDrive 320×224
NES | SNES | PS1 | N64 | GameCube | DS | 3DS 320×240
SNES 400×300
GBA 160×120
PSVITA 960×544
*/

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
 * @brief Struct for the fractal
 * 
 * @param name enum of the fractal name
 * @param x the x position of the window
 * @param y the y position of the window
 * @param max_iter the max iteration for the fractal
 */
typedef struct s_fractal	t_s_fractal;

/**
 * @brief Struct for the mlx
 * 
 * @param fractal the fractal struct
 * @param bits_pixel the bits per pixel of the image
 * @param img_line the size of one line of the image
 * @param endian the most important bit of the image
 * @param img the image
 * @param mlx the X-server pointer
 * @param win the window pointer
 */
typedef struct s_engine		t_s_engine;

/**
 * @brief Enum for the fractal name
 * 
 * @param E_MANDELBROT equal to 0
 * @param E_JULIA equal to 1
 */
typedef enum e_name			t_e_name;

/**
 * @brief Enum for fractal color mode
 * 
 * @param E_COLOR equal to 0;
 * @param E_GRADIENT equal to 1;
 */
typedef enum e_mode			t_e_mode;

enum e_mode {
	E_COLOR,
	E_GRADIENT,
};

enum e_name {
	E_MANDELBROT,
	E_JULIA,
};

struct s_fractal {
	t_e_name	name;
	t_e_mode	mode;
	size_t		max_iter;
	double		x_min;
	double		x_max;
	double		y_max;
	double		y_min;
	uint32_t	color;
};

struct s_engine {
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
};

/* Functions ================================================================ */

bool	name_is_wrong(t_e_name *name, char *arg);

int		user_mouse(int button, int x, int y, t_s_engine *engine);
int		user_keyboard(int keycode, t_s_engine *engine);
int		select_to_draw(t_s_engine *engine);
int		destroy_mlx(t_s_engine *engine);

void	validator(t_s_fractal *fractal, char *argv[]);
void	draw_on_img(t_s_engine *engine, int color);
void	mandelbrot_loop(t_s_engine *engine);
void	set_up_fractal(t_s_engine *engine);
void	x_img_fail(void *mlx, void *win);
void	validate_and_start(char *argv[]);
void	change_mode(t_s_engine *engine);
void	mandelbrot(t_s_engine *engine);
void	arg_is_null(uint8_t position);
void	init_mlx(t_s_engine *engine);
void	validate_julia(char *argv[]);
void	extract_julia(char *argv[]);
void	x_win_fail(void *mlx);
void	wrong_arg(char *arg);
void	print_options(void);
void	x_server_fail(void);
void	argc_too_big(void);
void	print_help(void);

#endif
