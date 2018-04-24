/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utioa_base_max.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:55:00 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/04 13:42:30 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_valid_bgewgew(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v'
		|| ft_isin(str[i], &(str[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_sizeuint(uintmax_t nb, int base)
{
	int	i;

	i = 1;
	while ((nb /= base) > 0)
		i++;
	return (i);
}

char		*ft_uitoa_base_max(uintmax_t nb, char *base)
{
	char	*str;
	int		i;
	int		lenbase;

	if (!ft_valid_bgewgew(base) || (lenbase = (int)ft_strlen(base)) < 2)
		return (NULL);
	if (!(str = (char*)malloc(ft_sizeuint(nb, lenbase) + 1)))
		return (NULL);
	i = ft_sizeuint(nb, lenbase);
	str[i] = '\0';
	while (i--)
	{
		str[i] = base[nb % lenbase];
		nb /= lenbase;
	}
	return (str);
}
