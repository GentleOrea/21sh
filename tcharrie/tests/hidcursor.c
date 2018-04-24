#include "include.h"

int	main()
{
	struct termios	st;
	char			buff[10];
	int				re;

	if ((tgetent(NULL, getenv("TERM")) < 1) || (tcgetattr(0, &st)) == -1)
		exit(0);
	st.c_lflag &= ~(ICANON | ECHO);
	st.c_cc[VMIN] = 1;
	st.c_cc[VTIME] = 0;
	if (tcsetattr(0, 0, &st) == -1)
		exit(0);
	while (1)
	{
		if ((re = read(0, buff, 8)) < 1)
			break ;
		if (buff[0] == 'E')
			break;
		buff[re] = 0;
	}
	st.c_lflag |= ICANON |ECHO;
	tcsetattr(0, 0, &st);
}
