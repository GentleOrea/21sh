#include "../includes/sh.h"

int	writechar(int c)
{
	return (write(1, &c, 1));
}

int	main(int ac, char **av, char **env)
{
	ft_init_terminal_data(env);
	dprintf(1, "%d\n", tputs(tgetstr("do", 0), 0, writechar));
	dprintf(1, "%s\n", tgetstr("CM", 0));
	dprintf(1, "%d\n", tputs(tgoto(tgetstr("CM", 0), 3, 1), 0, writechar));
	return (0);
}
