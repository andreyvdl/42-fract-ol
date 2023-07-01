# FILES ========================================================================

LIBFT_SOURCES=${addprefix sources/Binary_Tree/, ft_btree_apply_infix.c ft_btree_apply_prefix.c ft_btree_apply_suffix.c ft_btree_create_node.c ft_btree_insert_data.c ft_btree_search_item.c} \
	${addprefix sources/Booleans/, ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprime.c ft_isprint.c ft_isupper.c} \
	${addprefix sources/Converters/, ft_atoi.c ft_btoi.c ft_htoi.c ft_itoa.c ft_itob.c ft_itoh.c ft_itoo.c ft_otoi.c} \
	${addprefix sources/Ft_Printf/, ft_printf.c ft_printf_fd.c ft_printf_hex_upper.c ft_printf_int_fd.c ft_printf_loop.c ft_printf_ptr_fd.c ft_printf_uint.c ft_printf_char.c ft_printf_hex_lower.c ft_printf_int.c ft_printf_ln.c ft_printf_ptr.c ft_printf_string.c} \
	${addprefix sources/Get_Next_Line/, ft_gnl.c ft_gnl_utils.c} \
	${addprefix sources/Linked_List/, ft_list_at.c ft_list_foreach_if.c ft_list_remove_if.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_list_find.c ft_list_push_strs.c ft_list_sort.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c ft_lstmerge.c ft_lstreverse.c}\
	${addprefix sources/Math_Functions/, ft_absolute_number.c ft_factorial.c ft_next_prime.c ft_power.c ft_termial.c ft_rand.c} \
	${addprefix sources/Memory/, ft_bzero.c ft_calloc.c ft_free.c ft_free_matrix.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_swap.c} \
	${addprefix sources/Print_Functions/, ft_putchar.c ft_putchar_fd.c ft_putendl_fd.c ft_putendl.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c} \
	${addprefix sources/Strings/, ft_strcspn.c ft_strpbrk.c ft_strspn.c ft_matrixdup.c ft_search_replace_chr.c ft_search_replace_str.c ft_strcat.c ft_strcpy.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strrev.c ft_strupcase.c ft_split.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlowcase.c ft_strnstr.c ft_strstr.c ft_substr.c ft_strcapitalize.c ft_strcmp.c ft_striteri.c ft_strlcpy.c ft_strmapi.c ft_strrchr.c ft_strtrim.c} \
	${addprefix sources/Utilities/, ft_tolower.c ft_toupper.c}
LIBFT_OBJECTS=${LIBFT_SOURCES:.c=.o}
# VARIABLES ====================================================================

NAME=libft.a
CFLAGS=-Wall -Wextra -Werror
INCLUDES=-I./includes
HEADER=./includes/libft.h

# COLORS =======================================================================

BLACK=\033[1;30m
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
PURPLE=\033[1;35m
CYAN=\033[1;36m
WHITE=\033[1;37m
RESET=\033[0m
# TEXTS ========================================================================

OBJ_LOOP=@printf "${YELLOW}COMPILING: ${CYAN}${notdir $<}${RESET}\n"
OBJ_COMP=@printf "${BLUE}ALL OBJECTS COMPILED!${RESET}\n"
RM_FOREACH=@${foreach file, ${LIBFT_OBJECTS}, printf \
				"${RED}DELETING:  ${CYAN}${notdir ${file}}${RESET}\n"; \
				rm -rf ${file};}
OBJ_DELETED=@printf "${RED}ALL OBJECTS DELETED!${RESET}\n"
PROGRAM_DELETED=@printf "${YELLOW}LIBFT.A ${PURPLE}DELETED!${RESET}\n"
PROGRAM_CREATED=@printf "${GREEN}LIBFT.A ${WHITE}CREATED!${RESET}\n"
RECOMPILATED=@printf "${BLACK}RECOMPILATION COMPLETED!${RESET}\n"
# RULES ========================================================================

all: ${NAME}
	@if [[ ${HEADER} -nt ${NAME} ]]; then \
		printf "${RED}${notdir ${HEADER}} is newer than ${NAME}, recompiling all${RESET}\n";\
		make --no-print-directory re; \
		exit 0; \
	else \
		printf "${GREEN}Nothing to be done for all ;)${RESET}\n"; \
	fi

${NAME}: ${LIBFT_OBJECTS}
	${OBJ_COMP}
	@ar rcs ${NAME} ${LIBFT_OBJECTS}
	${PROGRAM_CREATED}

%.o: %.c
	${OBJ_LOOP}
	@cc ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
	${RM_FOREACH}
	${OBJ_DELETED}


fclean: clean
	@rm -rf ${NAME}
	${PROGRAM_DELETED}

re: fclean ${NAME}
	${RECOMPILATED}

.PHONY: all clean fclean re
