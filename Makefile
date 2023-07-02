# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 00:20:26 by adantas-          #+#    #+#              #
#    Updated: 2023/07/02 18:41:52 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARS ========================================================================
NAME=fractol
FLAGS=-Wall -Wextra -Werror -g3
MLX=-lmlx -lX11 -lXext
LIB_FT=-L./libft -lft
SRCS=fractol.c errors.c name_is_wrong.c validate_and_start.c validator.c extract_julia.c
OBJS=${SRCS:.c=.o}
HEADER=fractol.h

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
	@cc ${FLAGS} -I. ${OBJS} -o $@ ${MLX} ${LIB_FT}
	@printf "${GREEN}${NAME} created!${RESET}\n"
	@exit 0

libft/libft.a:
	@make --no-print-directory -C libft

%.o: %.c
	@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
	@cc ${FLAGS} -I. -c $< -o $@ ${MLX} ${LIB_FT}

fclean: clean
	@rm -rf libft/libft.a
	@rm -fr ${NAME}
	@printf "${RED}${NAME} removed!${RESET}\n"

clean:
	@make --no-print-directory clean -C libft
	@${foreach file, ${OBJS}, \
		if [ -f ${file} ]; then \
			printf "${YELLOW}Removing object file: ${MAGENTA}${notdir ${file}}${RESET}\n"; \
			rm -fr ${file}; \
		fi; \
	}
	@printf "${YELLOW}Objects removed!${RESET}\n"

re: fclean ${NAME}

.PHONY: all clean fclean re
