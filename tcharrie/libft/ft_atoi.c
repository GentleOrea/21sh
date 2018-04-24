/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:44:30 by tcharrie          #+#    #+#             */
/*   Updated: 2017/11/12 16:44:12 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intmin(const char *str)
{
	int		i;

	i = 0;
	while ("-2147483648"[i] && "-2147483648"[i] == str[i])
		i++;
	return (!("-2147483648"[i]));
}

int			ft_atoi(const char *str)
{
	int		i;
	int		s;

	while (*str == ' ' || *str == '\t' || *str == '\f' || *str == '\v' || *str
			== '\n' || *str == '\r')
		str++;
	s = (int)(*str == '-');
	if (ft_intmin(str))
		return (-2147483648);
	if (*str == '+' || *str == '-')
		str++;
	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + *str - '0';
		str++;
	}
	return (s ? -i : i);
}
