FILES = screen/*.c \
		initialisation/ft_signal.c \
		initialisation/ft_terminal.c \
		insert/*.c \
		ft_separator.c \
		misc/ft_error.c \
		misc/ft_print.c \
		misc/ft_memory.c \
		erase/*.c \
		../libft/libft.a

all : DO

DO :
	@gcc -ltermcap -Wall -Wextra -Werror -fsanitize=address -g3 $(FILES)
	@./a.out 2>screen/ERR
