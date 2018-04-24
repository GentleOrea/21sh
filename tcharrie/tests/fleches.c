#include "include.h"

int	main()
{
	char	*buff[8];
	int	i;

	i = 0;
	while (i < 8)
		buff[i++] = 0;
	while (1)
	{
		if (read(0, buff, 8) > 0)
			dprintf(2, ".%d", (int)*buff);
	}
	return (0);
}
