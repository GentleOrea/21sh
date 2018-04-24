#include "21sh.h"
void shift_char(char **str);
int	main(int ac, char **av)
{
	char *ret = ft_find_and_replace(av[1], "\\", 1);
	ft_printf("%s\n", ret);
}
