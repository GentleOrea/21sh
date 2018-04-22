FILES = src/ft_direction.c \
		src/ft_command.c \
		src/ft_getline.c \
		src/ft_separator_OK.c \
		src/builtin/builtin.c \
		src/builtin/ft_cd.c \
		src/builtin/ft_echo.c \
		src/builtin/ft_env.c \
		src/builtin/ft_exit.c \
		src/builtin/ft_setenv.c \
		src/builtin/ft_unsetenv.c \
		src/history/ft_history.c \
		src/initialisation/ft_initenv.c \
		src/initialisation/ft_signal.c \
		src/initialisation/ft_terminal_OK.c \
		src/misc/ft_error.c \
		src/misc/ft_memory.c \
		src/misc/ft_print.c \
		src/screen/ft_screen.c \
		src/user/ft_getentry.c \
		src/user/ft_len.c \
		src/user/ft_move.c \
		src/user/ft_read.c

NAME = useless

OBJ = $(FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : DO

DO :
	gcc -ltermcap $(FLAGS) $(FILES)

%.o : %.c
	@printf "\33[32mCompiling $@             \33[0m\r"
	@gcc -ltermcap -o $@ $(FLAGS) -c $<

$(NAME) : $(OBJ)
	@printf "\n\33[36mBuilding %s\33[m\n"
	@touch useless

clean :
	@rm -f $(OBJ)
	@printf "\33[31mReturning object files to ashes\33[0m\n"

re : clean all
