/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:24:11 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/04 15:23:23 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_lengths(va_list va, t_arg *a)
{
	int		i;
	char	*str;

	if (a->length == 'l')
		return (ft_lengthss(va, a));
	if (!(str = (char*)va_arg(va, void*)))
		str = "(null)";
	a->p = a->p != -1 && (int)ft_strlen(str) >
		a->p ? a->p : (int)ft_strlen(str);
	i = a->width <= a->p ? 0 : a->width - a->p;
	if (ft_isin('-', a->flags))
	{
		write(1, str, a->p);
		ft_writenchar(' ', i);
		return (i + a->p);
	}
	ft_writenchar(ft_isin('0', a->flags) ? '0' : ' ', i);
	write(1, str, a->p);
	return (i + a->p);
}

int		ft_lengthss(va_list va, t_arg *a)
{
	char	*str;
	int		i;
	int		j;

	if (!(str = ft_wchartostr((wchar_t*)va_arg(va, void*))))
	{
		str = "(null)";
		j = 0;
	}
	else
		j = 1;
	a->p = a->p != -1 && (int)ft_strlen(str) >
		a->p ? a->p : (int)ft_strlen(str);
	i = a->width <= a->p ? 0 : a->width - a->p;
	if (ft_isin('-', a->flags))
	{
		write(1, str, a->p);
		ft_writenchar(' ', i);
		return (i + a->p);
	}
	ft_writenchar(ft_isin('0', a->flags) ? '0' : ' ', i);
	write(1, str, a->p);
	if (j)
		ft_strdel(&str);
	return (i + a->p);
}

int		ft_printpspe(t_arg *arg)
{
	int	i;

	i = ft_write("0x");
	if (!ft_isin('-', arg->flags))
		return (ft_writenchar('0', arg->width > 3 ? arg->width - 2 : 1) + 2);
	i += ft_write("0");
	i += ft_writenchar(' ', arg->width > 3 ? arg->width - 3 : 0);
	return (i);
}

int		ft_lengthp(va_list va, t_arg *arg)
{
	uintmax_t	nb;

	if (!(nb = (unsigned long int)va_arg(va, void*)))
	{
		if (ft_isin('-', arg->flags) ||
				(arg->p < 0 && ft_isin('0', arg->flags)))
			return (ft_printpspe(arg));
		if (arg->p)
			nb = (int)ft_writenchar(' ', arg->width - 2 - ft_max(1, arg->p));
		else
			nb = (int)ft_writenchar(' ', arg->width - 2);
		ft_write("0x");
		return (nb + 2 + ft_writenchar('0', arg->p >= 0 ? arg->p : 1));
	}
	if (!(arg->flags))
		arg->flags = ft_strdup("#");
	else if (!ft_isin('#', arg->flags))
		arg->flags = ft_stradd(arg->flags, '#');
	arg->specifier = 'x';
	return (ft_printd(ft_uitoa_base_max(nb,
				"0123456789abcdef"), arg));
}

int		ft_lengthd(va_list va, t_arg *arg)
{
	intmax_t	i;

	if (arg->length == 'l' || arg->specifier == 'D')
		i = (intmax_t)(long)va_arg(va, void*);
	else if (arg->length == 'H')
		i = (intmax_t)(signed char)va_arg(va, void*);
	else if (arg->length == 'h')
		i = (intmax_t)(short)va_arg(va, void*);
	else if (arg->length == 'L')
		i = (intmax_t)(long long)va_arg(va, void*);
	else if (arg->length == 'j')
		i = (intmax_t)va_arg(va, void*);
	else if (arg->length == 'z')
		i = (intmax_t)(size_t)va_arg(va, void*);
	else
		i = (intmax_t)(int)va_arg(va, void*);
	return (ft_printi(i, arg));
}
