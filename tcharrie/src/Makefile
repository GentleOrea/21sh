FILES = screen/*.c \
		initialisation/ft_signal.c \
		initialisation/ft_terminal.c \
		ft_separator.c \
		misc/ft_error.c \
		misc/ft_print.c \
		misc/ft_memory.c \
		write/*.c \
		signal/*.c \
		history/*.c \
		../printf/*.c \
		../libft/libft.a

all : DO

DO :
	@gcc -ltermcap -Wall -Wextra -Werror -fsanitize=address -g3 $(FILES) -I includes/
	@./a.out 2>screen/ERR
