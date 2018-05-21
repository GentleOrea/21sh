/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:05:24 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/12 13:17:59 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	ft_lenword_right_com(char *str, int pos)
{
	int	mov;
	int	bl;

	mov = 0;
	bl = 0;
	while (str[pos] && (bl || !ft_isin(str[pos], ENDWORD)))
	{
		mov++;
		pos += ft_lenchar_r(str, pos);
	}
	if (mov)
		return (mov);
	while (str[pos] && ft_isin(str[pos], ENDWORD))
	{
		mov++;
		pos += ft_lenchar_r(str, pos);
	}
	return (mov > 0 ? mov : 1);
}

int			ft_lenword_r_com(char *str, int pos)
{
	int	i;
	int	sep;
	int	bl;

	if (!str || pos < 0)
		return (0);
	i = 0;
	ft_separator_active(str, pos, &bl, &sep);
	if (!sep && !bl && ft_isin(str[pos], "`&|<>;"))
		return (1 + (!ft_isin(str[pos], ";`") && str[pos] == str[pos + 1]));
	if (!sep && !bl && ft_isin(str[pos], " \n"))
	{
		while (str[pos] && ft_isin(str[pos], " \n") && ++i)
			pos += ft_lenchar_r(str, pos);
		return (i);
	}
	if (sep == '`')
		return (ft_lenword_right_com(str, pos));
	while (str[pos] && (bl || sep || !ft_isin(str[pos], ENDWORD)))
	{
		sep = ft_separator(str[pos], sep, bl);
		bl = (!bl && sep != '\'' && str[pos] == '\\');
		i++;
		pos += ft_lenchar_r(str, pos);
	}
	return (i > 0 ? i : 1);
}
