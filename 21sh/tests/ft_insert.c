#include "includes/sh.h"

int	writechar(int c){return (write(1, &c, 1));}

void	ft_insert(char *str, size_t size)
{
//	ft_init_terminal_data();
	char	*tmp;

	if ((tmp = tgetstr("im", NULL)))
	{
		tputs(tmp, 0, writechar);
		write(1, str, size);
		if ((tmp = tgetstr("ei", NULL)))
			tputs(tmp, 0, writechar);
	}
//Sinon IC 
//Sinon ic size fois
}
