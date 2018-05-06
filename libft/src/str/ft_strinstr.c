#include "libft.h"

int		ft_strinstr(char *str, int pat)
{
	int	i;

	if (!str || !pat)
		return (0);
	i = 0;
	while (str[i])
	{
		if (ft_strprefix(&str[i], pat))
			return (i);
		i++;
	}
	return (-1);
}
