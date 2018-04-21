#include "include.h"

void	init_terminal_data (void)
{
	char *termtype = getenv ("TERM");
	int success;
	char	term_buffer[2048];

	if (termtype == 0)
	{
		dprintf (2, "Specify a terminal type with `setenv TERM <yourtype>'.\n");
		exit(0);
	}
	success = tgetent (term_buffer, termtype);
		if (success < 0)
		{
			dprintf(2, "Could not access the termcap data base.\n");
			exit(0);
		}
		if (success == 0)
		{
			dprintf (2, "Terminal type `%s' is not defined.\n", termtype);
			exit(0);
		}
}

int	writechar(int c){return (write(1, &c, 1));}

int	main()
{
	char	*str;

	init_terminal_data();
	printf("Line1\nLine2\nLine3\nLine4\nLine5\nLine6\nLine7\n");
	tcdrain(1);
	if ((str = tgetstr("im", NULL)))
		tputs(str, 0, writechar);
	else
		dprintf(2, "failed\n");
	if (!(str = tgetstr("up", NULL)))
		dprintf(2, "Failed to get the up string\n");
	else
	{
		tputs(str, 0, writechar);
		tputs(str, 0, writechar);
		tputs(str, 0, writechar);
	}
	if (!(str = tgetstr("nd", NULL)))
		dprintf(2, "Failed to get the right string\n");
	else
	{
		tputs(str, 0, writechar);
		tputs(str, 0, writechar);
		tputs(str, 0, writechar);
	}
	sleep(1);
	write(1, "INSERT", 7);
	tcdrain(1);
	if (!(str = tgetstr("do", NULL)))
		dprintf(2, "Failed to get the down string\n");
	else
	{
		tputs(str, 3, writechar);
	}
	if ((str = tgetstr("ei", NULL)))
		tputs(str, 0, writechar);
	else
		dprintf(2, "failed\n");
	return (0);
}
