#include "includes/sh.h"
#include "include.h"

int	writechar(int c){return (write(1, &c, 1));}

int	main(int ac, char **av, char **env)
{
	t_termios	ter;
	char		c[10];
	int			fd;
	char		*str;

	ft_init_terminal_data(env);
	signal (SIGINT, ft_sigint);
	if (tcgetattr(0, &ter) < 0)
		ft_fatal("Failed to tcgetattr");
	ter.c_lflag &= ~(ICANON | ECHO | IEXTEN);
	ter.c_cc[VTIME] = 0;
	ter.c_cc[VMIN] = 1;
	tcsetattr(0, 0, &ter);
	while (1)
	{
		if ((fd = read (0, c, 6)) > 0)
			dprintf(1, "%d.", fd);
//			write(1, &c, 1);
		if (*c == 'E')
			break;
	}
	ter.c_lflag |= ICANON | ECHO | IEXTEN;
	tcsetattr(0, 0, &ter);
	tputs(tgetstr("ei", NULL), 0, writechar);
	return (0);
}
