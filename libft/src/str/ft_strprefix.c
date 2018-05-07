#include "libft.h"

int		ft_strprefix(char *pref, char *str)
{
	int	i;

	if (!pref || !str)
		return (0);
	i = 0;
	while (pref[i] && ft_abs(pref[i]) == ft_abs(str[i]))
		i++;
	if (pref[i])
		return (0);
	return (i);
}
