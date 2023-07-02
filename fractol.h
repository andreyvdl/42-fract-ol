#ifndef FRACTOL_H
# define FRACTOL_H

/* Include ================================================================== */
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>

/* Defines ================================================================== */

# define MANDELBROT_STR "MANDELBROT"
# define JULIA_STR "JULIA"
# define HEIGHT 600
# define WIDTH 800

/* Texts ==================================================================== */

# define ERR_MISSING "\e[1;31mMissing args\e[0m\n"
# define ERR_MANY "\e[1;31mToo many args\e[0m\n"
# define ERR_ARG "\e[1;31mWrong arg `%s`\e[0m\n"

# define USAGE_STR "Usage: \e[1;32m./fractol\e[0m \e[1;3;4;31mfractal_name\
\e[0m [\e[1;3;4;31mfractal_options\e[0m \e[1;3;4;31m...\e[0m]\n\n\
fractol_name can be MANDELBROT | JULIA\n\
if is JULIA, need to add 2 options between -2 and 2\n"

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
	size_t		x;
	size_t		y;
	size_t		max_iter;
};

struct s_engine {
	t_s_fractal	fractal;
	int			bits_pixel;
	int			img_line;
	int			endian;
	void		*img;
	void		*mlx;
	void		*win;
};


/* Functions ================================================================ */

bool	name_is_wrong(t_e_name *name, char *arg);

void	validate_and_start(char *argv[]);
void	validator(char *argv[]);
void	wrong_arg(char *arg);
void	print_options(void);
void	argc_too_big(void);

#endif
