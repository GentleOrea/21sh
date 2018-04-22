# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/31 14:49:43 by tcharrie          #+#    #+#              #
#    Updated: 2018/02/03 15:26:58 by tcharrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = "libftprintf.a"
LIBFT = "../libft/libft.a"
NAME = libftprintf.a
FILES = src/ft_printf.c \
		src/ft_write.c \
		src/ft_color.c \
		src/ft_carrefour.c \
		src/ft_addspecial.c \
		src/ft_addvalue.c \
		src/ft_getarg.c \
		src/memory.c \
		src/ft_is_base.c \
		src/ft_isspecial.c \
		src/ft_length_a.c \
		src/ft_length_b.c \
		src/ft_length_c.c \
		src/ft_length_d.c \
		src/ft_aff.c \
		src/ft_aff2.c \
		src/ft_affsignednb.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

%.o : %.c
	@gcc -o $@ -Wall -Wextra -Werror -c $<

$(LIBFT) :
	@make -C ../libft

$(NAME) : $(OBJ) $(LIBFT)
	@libtool -static -o $(LIB) $^
	@ranlib $(LIB)

clean :
	@rm -f $(OBJ)
	@make -C ../libft/ clean

fclean :
	@rm -f $(OBJ)
	@rm -f $(LIB)
	@make -C ../libft/ fclean

re : fclean $(NAME)
