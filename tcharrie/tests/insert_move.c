#include "../includes/sh.h"
#include <errno.h>
#include <term.h>

int		writechar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	handler(int sig)
{
	t_termios	ter;

	if (sig == SIGINT)
	{
		tcgetattr(0, &ter);
		ter.c_lflag |= ECHO | ICANON;
		tcsetattr(0, 0, &ter);
		tputs(tgetstr("ei", 0), 0, writechar);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_termios	ter;
	char		c[10];
	int			i;
	int			j;
	char		buffer[2048];

	tgetent(buffer, getenv("TERM"));
	j = 0;
	tcgetattr(0, &ter);
	ter.c_lflag &= ~(ECHO | ICANON);
	ter.c_cc[VMIN] = 1;
	ter.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &ter);
/*	*av = tgetstr("im", 0);
	if (*av)
		tputs(*av, 0, writechar);
	*av = tgetstr("dc", 0);
*/
	j = 0;
	while (1)
	{
		j++;
		i = read(0, c, 10);
		c[i] = 0;
		if (j > 10)
		{
			j = 0;
			write(1, "\33[H", 3);
		}
		dprintf(1, "%d\n", ft_strcmp(c, tgetstr(av[1], 0)));
	}
}
