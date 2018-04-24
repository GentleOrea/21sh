#include "../includes/sh.h"

int	main()
{
	char	*str;

	dprintf(1, "%s\n", (str = ttyname(0)));
	free(str);
	sleep(1);
	dprintf(1, "%s\n", str);
	return (0);
}
