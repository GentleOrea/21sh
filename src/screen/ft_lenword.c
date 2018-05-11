/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:05:24 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/11 13:44:40 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		ft_lenword_r(char *str, int pos)
{
	int	i;
	int	sep;
	int	bl;

	i = 0;
	ft_separator_active(str, pos, &bl, &sep);
	if (!sep && !bl && ft_isin(str[pos], "&|<>;"))
		return (1 + (str[pos] != ';' && str[pos] == str[pos + 1]));
	if (!sep && !bl && ft_isin(str[pos], " \n"))
	{
		while (str[pos] && ft_isin(str[pos], " \n") && ++i)
			pos += ft_lenchar_r(str, pos);
		return (i);
	}
	while (str[pos] && (bl || sep || !ft_isin(str[pos], ENDWORD)))
	{
		sep = ft_separator(str[pos], sep, bl);
		bl = (!bl && sep != '\'' && str[pos] == '\\');
		i++;
		pos += ft_lenchar_r(str, pos);
	}
	return (i);
}

int		ft_lenword_l(char *str, int pos)
{
	int	mov;
	int	i;
	int	bl;
	int	sep;

	if (!str || !pos || (i = 0))
		return (0);
	bl = 0;
	sep = 0;
	while ((i < pos && str[i]) && !(mov = 0))
	{
		while (i < pos && str[i] && (sep || bl || !ft_isin(str[i], ENDWORD)))
		{
			mov++;
			sep = ft_separator(str[i], sep, bl);
			bl = (!bl && sep != '\'' && str[i] == '\\');
			i += ft_lenchar_r(str, i);
		}
		if (i >= pos || !str[i])
			break ;
		if (ft_isin(str[i], ";|&<>") || (mov = 0))
			return (1 + (str[i] != ';' && str[i] == str[i + 1]));
		while (i < pos && str[i] && (ft_isin(str[i], ENDWORD)) && ++mov)
			i += ft_lenchar_r(str, i);
	}
	return (mov ? mov : 1);
}
