#include "sh.h"

DIR	*ft_opendirfree(char *str)
{
	DIR	*dir;

	if (!str)
		return (0);
	dir = opendir(str);
	ft_strdel(&str);
	return (dir);
}
