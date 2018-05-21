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

#include "../../includes/sh.h"

/*
** Fonction à appeler si sep == `
** Elle avance tant qu'on est dedans et qu'on a pas atteint to
** Elle renvoie l'avancement effectué dans la chaîne de charactère
*/

static int	ft_lenword_left_c(char *str, int to, int *mov, int *sep)
{
	int	i;
	int	bl;

	i = 1;
	sep[0] = '`';
	*mov = 0;
	while (i < to && sep[0] == '`')
	{
		if (!(sep[0] = (ft_separator(str[i], sep[1], sep[0]))))
		{
			i += ft_lenchar_r(str, i);
			(*mov)++;
		}
		else
			sep[1] = (str[i] == '\\' && !bl);
		i += ft_lenchar_r(str, i);
		(*mov)++;
	}
	sep[1] = (str[i] == '\\');
	sep[0] = (ft_isin(str[i], "'`\"")) ? (str[i]) : (0);
	return (i);
}

static int	ft_lenword_left_sp(char *str, int to, int *mov, int *sep)
{
	int	i;

	i = 0;
	*mov = 0;
	if (ft_isin(str[i], "<>|&;"))
	{
		mov[0]++;
		if (str[i] == str[i + 1] && i + 1 < to && ft_isin(str[i], "<>|&"))
		{
			i++;
			mov[0]++;
		}
		sep[1] = (str[i] == '\\');
		sep[0] = (ft_isin(str[i], "'`\"")) ? (str[i]) : (0);
		return (i + 1);
	}
	while (i < to && ft_isin(str[i], " \n"))
	{
		i += ft_lenchar_r(str, i);
		(*mov)++;
	}
	sep[1] = (str[i] == '\\');
	sep[0] = (ft_isin(str[i], "'`\"")) ? (str[i]) : (0);
	return (i);
}

static int	ft_lenword_left_n(char *str, int to, int *mov, int *sep)
{
	int	i;

	i = 0;
	*mov = 0;
	while (i < to && (sep[0] || sep[1] || !ft_isin(str[i], "<>&|;` \n")))
	{
		sep[0] = ft_separator(str[i], sep[1], sep[0]);
		sep[1] = (str[i] == '\\' && sep[1] == 0 && sep[0] != '\'');
		mov[0]++;
		i += ft_lenchar_r(str, i);
	}
	return (i);
}

int			ft_lenword_l_com(char *str, int pos)
{
	int	mov;
	int	sep[2];
	int	i;

	if (!str || pos <= 0 || ft_strlen(str) < pos)
		return (0);
	i = 0;
	ft_bzero((void*)sep, sizeof(sep));
	while (i < pos && !(mov = 0))
	{
		if (sep[0] == 0 && sep[1] == 0 && str[i] == '`')
			i += ft_lenword_left_c(&str[i], pos - i, &mov, sep);
		else if (ft_isin(str[i], " \n&|<>;") && !sep[0] && !sep[1])
			i += ft_lenword_left_sp(&str[i], pos - i, &mov, sep);
		else
			i += ft_lenword_left_n(&str[i], pos - i, &mov, sep);
	}
	return (mov ? mov : 1);
}
