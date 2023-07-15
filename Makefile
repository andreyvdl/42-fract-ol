# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 00:20:26 by adantas-          #+#    #+#              #
#    Updated: 2023/07/15 17:59:30 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARS ========================================================================
NAME=fractol
FLAGS=-Wall -Wextra -Werror -g3
#FLAGS+=-fsanitize=address
MLX=-lmlx -lX11 -lXext -lm
LIB_FT=-L./libft -lft
SRCS=${addprefix sources/, draw.c errors.c errors2.c fractol.c name_is_wrong.c validate_and_start.c validator.c print_help.c} \
	${addprefix sources/julia/, validate_julia.c} \
	${addprefix sources/mandelbrot/, mandelbrot.c} \
	${addprefix sources/mlx/, init_mlx.c destroy.c keyboard.c mouse.c keyboard2.c}
OBJS=${SRCS:.c=.o}
HEADER=include/fractol.h

# COLORS ======================================================================
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
RESET=\033[0m

# RULES =======================================================================

all: ${NAME}
	@if [ ${HEADER} -nt ${NAME} ]; then \
		printf "${RED}${HEADER} is newer than ${NAME}! Recompiling${RESET}\n"; \
		make --no-print-directory re; \
	else \
		printf "${GREEN}${NAME} is up to date!${RESET}\n"; \
	fi

${NAME}: libft/libft.a ${OBJS}
	@printf "${BLUE}All objects created!${RESET}\n"
	@cc ${FLAGS} -Iinclude ${OBJS} -o $@ ${MLX} ${LIB_FT}
	@printf "${GREEN}${NAME} created!${RESET}\n"
	@exit 0

libft/libft.a:
	@make --no-print-directory -C libft

%.o: %.c
	@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
	@cc ${FLAGS} -Iinclude -c $< -o $@

fclean: clean
	@rm -rf libft/libft.a
	@rm -fr ${NAME}
	@printf "${RED}${NAME} removed!${RESET}\n"

clean:
	@make --no-print-directory clean -C libft
	@rm -fr ${OBJS}
	@printf "${YELLOW}Objects removed!${RESET}\n"

re: fclean ${NAME}

.PHONY: all clean fclean re
