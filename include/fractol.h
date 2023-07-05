#ifndef FRACTOL_H
# define FRACTOL_H

// https://mathigon.org/course/fractals/introduction

/* Include ================================================================== */
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>

/* Defines ================================================================== */

# define MANDELBROT_STR "MANDELBROT"
# define JULIA_STR "JULIA"
# define TITLE "adantas- fract'ol"

# define HEIGHT 600
# define WIDTH 800

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

enum e_name {
	E_MANDELBROT,
	E_JULIA,
};

struct s_fractal {
	t_e_name	name;
	size_t		max_iter;
	float		x_real;
	float		x_imag;
	float		y_real;
	float		y_imag;
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

void	validator(t_s_fractal *fractal, char *argv[]);
void	validate_and_start(char *argv[]);
void	arg_is_null(uint8_t position);
void	extract_julia(char *argv[]);
void	wrong_arg(char *arg);
void	print_options(void);
void	x_server_fail(void);
void	argc_too_big(void);

#endif
