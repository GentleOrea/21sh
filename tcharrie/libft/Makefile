LIB = "libft.a"
FILES = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstpushfront.c \
		ft_lstfree.c \
		ft_lstsort.c \
		ft_lstreverse.c \
		ft_lstat.c \
		ft_lstpushback.c \
		ft_lstremoveif.c \
		ft_lstvoid.c \
		ft_lstnewc.c \
		ft_lstsize.c \
		ft_islower.c \
		ft_isupper.c \
		ft_capitalize.c \
		ft_indexmin.c \
		ft_abs.c \
		ft_sqrt.c \
		ft_replace.c \
		ft_power.c \
		ft_strnocc.c \
		ft_isin.c \
		ft_itoabase.c \
		ft_stradd.c \
		ft_gotmod.c \
		ft_strlento.c \
		ft_writenchar.c \
		ft_max.c \
		ft_min.c \
		ft_divideby.c \
		ft_itoamax.c \
		ft_uitoa_base_max.c \
		ft_wchartostr.c \
		ft_strrev.c \
		ft_strdupto.c \
		ft_strtabdup.c \
		ft_realloc.c \
		ft_strlenin.c \
		ft_insert.c \
		ft_strlento_rev.c \
		ft_addtofd.c

NAME = libft.a
OBJ = $(FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

all : $(NAME)

%.o : %.c
	@printf "\33[32mCompiling $@             \33[0m\r"
	@gcc -o $@ $(FLAGS) -c $<

$(NAME) : $(OBJ)
	@printf "\n\33[36mBuilding %s\33[m\n" $(LIB)
	@ar rc $(LIB) $(OBJ)

clean :
	@rm -f $(OBJ)
	@printf "\33[31mReturning object files to ashes\33[0m\n"

fclean : clean
	@rm -f $(LIB)

re : fclean all
