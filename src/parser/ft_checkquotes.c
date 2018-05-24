#include "sh.h"

int	ft_checkquotes(char *str)
{
	int	sep[3];
	int	i;

	if (!str)
		return (1);
	ft_bzero((void*)sep, sizeof(sep));
	i = 0;
	while (str[i])
	{
		if (sep[2] && str[i] == '`' && sep[0] && !sep[1])
			return (0);
		ft_separator(str[i], sep, &sep[1], &sep[2]);
		i += ft_lenchar_r(str, i);
	}
	return (1);
}
