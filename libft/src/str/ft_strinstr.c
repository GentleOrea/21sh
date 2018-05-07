#include "libft.h"

int		ft_strinstr(char *str, char *pat)
{
	int	i;

	if (!str || !pat)
		return (0);
	i = 0;
	while (str[i])
	{
		if (ft_strprefix(pat, &str[i]))
			return (i);
		i++;
	}
	return (-1);
}
