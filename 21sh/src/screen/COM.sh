rm -f  a.out ;
gcc -ltermcap ft_move_bonus.c ft_move_base.c ft_move_all.c ft_lenword.c ../ft_separator.c ft_move_base_.c ft_lenchar.c ../initialisation/ft_signal.c ../initialisation/ft_terminal.c ../misc/ft_error.c ../misc/ft_print.c ft_lenline.c ft_scroll.c ../../libft/libft.a; ./a.out 2>ERR
