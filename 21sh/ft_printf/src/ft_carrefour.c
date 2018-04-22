/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_carrefour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:02:32 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/04 14:18:16 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_carrefour(va_list va, t_arg *arg, int read)
{
	if (!arg->specifier)
		return (0);
	if (!ft_isspecifier(arg->specifier))
	{
		if (ft_isin('-', arg->flags))
		{
			ft_putchar(arg->specifier);
			return (ft_writenchar(' ', arg->width > 1 ?
				arg->width - 1 : 0) + 1);
		}
		else
		{
			ft_writenchar(ft_isin('0', arg->flags) ? '0' : ' ', arg->width > 1 ?
					arg->width - 1 : 0);
			ft_putchar(arg->specifier);
			return (arg->width > 0 ? arg->width : 1);
		}
	}
	if (arg->specifier == 'n')
	{
		ft_spn(va, arg, read);
		return (0);
	}
	ft_color(arg);
	return (ft_carrefour_second(va, arg));
}

int		ft_carrefour_second(va_list va, t_arg *arg)
{
	if (arg->specifier == '%')
		return (ft_lengthspe(arg));
	if (arg->specifier == 's')
		return (ft_lengths(va, arg));
	if (arg->specifier == 'S')
		return (ft_lengthss(va, arg));
	if (arg->specifier == 'p')
		return (ft_lengthp(va, arg));
	if (arg->specifier == 'd' || arg->specifier == 'i' || arg->specifier == 'D')
		return (ft_lengthd(va, arg));
	if (arg->specifier == 'o' || arg->specifier == 'O')
		return (ft_lengtho(va, arg));
	if (arg->specifier == 'u' || arg->specifier == 'U')
		return (ft_lengthu(va, arg));
	if (arg->specifier == 'x')
		return (ft_lengthx(va, arg));
	if (arg->specifier == 'X')
		return (ft_lengthxx(va, arg));
	if (arg->specifier == 'c')
		return (ft_lengthc(va, arg));
	if (arg->specifier == 'C')
		return (ft_lengthcc(va, arg));
	if (arg->specifier == 'b' || arg->specifier == 'B')
		return (ft_lengthb(va, arg));
	return (0);
}
