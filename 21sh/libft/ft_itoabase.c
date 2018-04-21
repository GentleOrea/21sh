/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 10:11:58 by tcharrie          #+#    #+#             */
/*   Updated: 2017/12/31 11:58:18 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_sizestr(int nb, int lenbase)
{
	int		i;
	size_t	n;

	if (nb == -2147483648)
		n = 2147483648;
	else
		n = (size_t)ft_abs(nb);
	i = 1;
	while (ft_power((size_t)lenbase, (size_t)i) <= n)
		i++;
	return (nb < 0 ? i + 1 : i);
}

static int	ft_createbase(char **s, int size)
{
	int		i;
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
	{
		str[i] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i];
		i++;
	}
	str[i] = '\0';
	*s = str;
	return (1);
}

static int	ft_validbase(char **str)
{
	int	j;

	if (!*str || (**str == '+' && (ft_atoi(*str) < 2 ||
			ft_atoi(*str) > 36)) || ft_strlen(*str) <= 1)
		return (0);
	if (**str == '+')
		return (ft_createbase(str, ft_atoi(*str)));
	else
	{
		j = 0;
		while ("+- \n\t\f\r\v"[j])
		{
			if (ft_isin("+- \n\t\f\r\v"[j], *str))
				return (0);
			j++;
		}
		j = 0;
		while (str[j])
		{
			if (ft_isin(str[0][j], &(str[0][j + 1])))
				return (0);
			j++;
		}
	}
	return (1);
}

char		*ft_itoabase(long int nb, char *base)
{
	char	*str;
	int		k;
	int		s;

	if (ft_validbase(&base) == 0)
		return (NULL);
	k = ft_sizestr(nb, ft_strlen(base));
	if (!(str = (char*)malloc(sizeof(char) * (k + 1))))
		return (NULL);
	if (nb < 0)
		str[0] = '-';
	str[k--] = '\0';
	s = nb >= 0;
	while ((k > 0 && !s) || (k >= 0 && s))
	{
		if (nb >= 0)
			str[k] = base[nb % ft_strlen(base)];
		else
			str[k] = base[-(nb % (int)ft_strlen(base))];
		nb /= (int)ft_strlen(base);
		k--;
	}
	return (str);
}
