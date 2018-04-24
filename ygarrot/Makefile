# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 13:13:35 by ygarrot           #+#    #+#              #
#    Updated: 2018/04/24 18:38:47 by ygarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = yosh

FLAGS =  -Wall -Werror -Wextra -g3 -fsanitize=address

SRC_FOLDER = ./

SRC_FP = lexer.c \
		 parser.c \
		 error_handling.c \
		 ft_strsplit_comm.c \
		 ft_find_and_replace.c \
		 list_tools.c \
		 parse_utils.c \
		 main.c \
		 interpreter.c \
		 redirect.c \
		 exec_utils.c \
		 exec.c \
		 ft_terminal.c 

SRC_FP += \
		  builtin/ft_cd.c \
		  builtin/ft_echo.c \
		  builtin/ft_env.c \
		  builtin/ft_exit.c \
		  builtin/ft_setenv.c \
		  builtin/ft_strlento.c \
		  builtin/ft_strtabdup.c \
		  builtin/ft_unsetenv.c 

#Colors
_RED=\x1b[31m
_GREEN=\x1b[32m
_BLUE=\x1b[94m
_WHITE=\x1b[37m
_END=\x1b[0m

SRC = $(addprefix $(SRC_FOLDER), $(SRC_FP))

INCLUDE =  includes/

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< -I $(INCLUDE)
	@printf "                                                        \r"
	@printf " $(_BLUE)Compiling $@$(_END)\r"

$(NAME): $(OBJ)
	@printf "                                                        \r"
	@make -C libft -j
	@gcc $(FLAGS) -o $(NAME) $^ -L libft -l ft -ltermcap
	@printf "                                                        \r"
	@printf "21sh built\n"

test: all clean

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
