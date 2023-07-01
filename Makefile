# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 00:20:26 by adantas-          #+#    #+#              #
#    Updated: 2023/07/01 02:13:14 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARS ========================================================================
NAME=fractol
FLAGS=-Wall -Wextra -Werror -g3
MLX=-lmlx -lX11 -lXext
LIB_FT=-L./libft -lft
SRCS=
OBJS=${SRCS:.c=.o}
HEADER=

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
	@cc ${FLAGS} -I. ${OBJS} -o $@ 
	@printf "${GREEN}${NAME} created!${RESET}\n"
	@exit 0

libft/libft.a:
	@make --no-print-directory -C libft

%.o: %.c
	@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
	@cc ${FLAGS} -I. -c $< -o $@

fclean: clean
	@rm -fr ${NAME}
	@printf "${RED}${NAME} removed!${RESET}\n"

clean:
	@${foreach file, ${OBJS}, \
		if [ -f ${file} ]; then \
			printf "${YELLOW}Removing object file: ${MAGENTA}${notdir ${file}}${RESET}\n"; \
			rm -fr ${file}; \
		fi; \
	}
	@printf "${YELLOW}Objects removed!${RESET}\n"

re: fclean ${NAME}

.PHONY: all clean fclean re
