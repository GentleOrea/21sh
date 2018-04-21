/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 09:09:12 by tcharrie          #+#    #+#             */
/*   Updated: 2018/02/03 12:43:43 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_scrap(t_arg *arg, char *str)
{
	if (!ft_isin('#', arg->flags))
		return (0);
	if (!str && (arg->specifier == 'x' || arg->specifier == 'X'))
		return (2);
	if (arg->specifier == 'X' || (arg->specifier == 'x' && arg->length == 'H'))
	{
		write(1, "0X", 2);
		arg->width = arg->width < 0 ? -1 : arg->width - 2;
		return (2);
	}
	else if (arg->specifier == 'x')
	{
		write(1, "0x", 2);
		return (2);
	}
	else if (arg->specifier == 'o' || arg->specifier == 'O')
	{
		if (!str)
			return (1);
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

static int	ft_printdnull(t_arg *arg, char *str)
{
	ft_strdel(&str);
	if (arg->width < 0 && arg->p < 0)
		return (ft_write("0"));
	else if (arg->width < 0)
		return (ft_writenchar('0', arg->p == 0 && ft_isin('#', arg->flags) &&
		(arg->specifier == 'o' || arg->specifier == 'O') ? 1 : arg->p));
	else if (arg->p < 0)
		return (ft_isin('0', arg->flags) ? ft_writenchar('0', arg->width) :
			ft_writenchar(' ', arg->width - 1) + ft_writenchar('0', 1));
	else if (ft_isin('-', arg->flags))
	{
		ft_writenchar('0', arg->p);
		ft_writenchar(' ', arg->width - arg->p);
	}
	else
	{
		ft_writenchar(' ', arg->width - arg->p);
		ft_writenchar('0', arg->p);
	}
	return (ft_max(arg->width, arg->p));
}

int			ft_printd(char *str, t_arg *arg)
{
	int		i;

	if (!str)
		return (-1);
	if (*str == '0')
		return (ft_printdnull(arg, str));
	i = ft_scrap(arg, NULL);
	arg->width -= ft_scrap(arg, NULL);
	if (!(ft_isin('-', arg->flags)) && arg->width > -1 &&
		(!ft_isin('0', arg->flags) || arg->p >= 0))
		i += ft_writenchar(' ', arg->width -
				ft_max(arg->p - (i == 1), (int)ft_strlen(str)));
	ft_scrap(arg, str);
	if (!ft_isin('-', arg->flags) &&
		arg->width > -1 && ft_isin('0', arg->flags) && arg->p < 0)
		i += ft_writenchar('0', arg->width -
			ft_max(arg->p - (ft_scrap(arg, NULL) == 1), (int)ft_strlen(str)));
	i += ft_writenchar('0', arg->p -
			(ft_scrap(arg, NULL) == 1) - ft_strlen(str));
	i += ft_write(str);
	if (arg->width > -1 && ft_isin('-', arg->flags))
		i += ft_writenchar(' ', arg->width - ft_max(arg->p,
					(int)ft_strlen(str)));
	ft_memdel((void**)&str);
	return (i);
}
