/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 08:34:38 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/02 13:37:49 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_expectedlength(intmax_t nb)
{
	int	i;

	i = nb <= 0 ? 1 : 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static int	ft_lencolor(t_arg *arg)
{
	int	i;

	i = 0;
	if (arg->type > 0)
		i = ft_expectedlength(arg->type) * 2 - 1;
	if (arg->color > 0)
	{
		i += 2;
		if (i > 0)
			i++;
	}
	if (arg->bg > 0)
	{
		i += 2;
		if (i > 0)
			i++;
	}
	return (i + 4);
}

static void	ft_color_next(t_arg *arg, char *str, int i, int j)
{
	if (arg->bg > 0)
	{
		str[j++] = '4';
		str[j++] = arg->bg - 40 + '0';
		if (j + 2 < i)
			str[j++] = ';';
	}
	while (arg->type > 0)
	{
		str[j++] = arg->type % 10 + '0';
		if (j + 2 < i)
			str[j++] = ';';
		arg->type /= 10;
	}
	write(1, str, i);
	ft_strdel(&str);
}

void		ft_color(t_arg *arg)
{
	char	*str;
	int		i;
	int		j;

	if ((i = ft_lencolor(arg)) < 5)
		return ;
	if (!(str = (char*)malloc(sizeof(char) * i)))
		return ;
	str[0] = '\x1B';
	str[1] = '[';
	str[i - 1] = '\0';
	str[i - 2] = 'm';
	j = 2;
	if (arg->color > 0)
	{
		str[j++] = '3';
		str[j++] = arg->color - 30 + '0';
		if (j + 2 < i)
			str[j++] = ';';
	}
	ft_color_next(arg, str, i, j);
}

void		ft_reset(t_arg *arg)
{
	if (arg->color || arg->type || arg->bg)
		write(1, "\x1B[0m", 4);
}
