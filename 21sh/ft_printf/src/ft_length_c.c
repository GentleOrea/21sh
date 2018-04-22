/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 12:47:50 by tcharrie          #+#    #+#             */
/*   Updated: 2018/02/03 13:23:04 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_lenchar(int c)
{
	int	i;

	i = 1;
	while ((c /= 2))
		i++;
	if (i <= 7)
		return (1);
	if (i <= 11)
		return (2);
	if (i <= 16)
		return (3);
	if (i <= 21)
		return (4);
	return (0);
}

static void	ft_writewint(wint_t c)
{
	int		i;
	char	tmp[5];

	i = ft_lenchar(c);
	if (i == 1)
		tmp[0] = c & 0x7f;
	if (i == 2)
	{
		tmp[0] = ((c / 64) & 0xdf) | 0xc0;
		tmp[1] = (((c % 64) % 64) & 0xbf) | 0x80;
	}
	if (i == 3)
	{
		tmp[0] = ((c / 4096) & 0xef) | 0xe0;
		tmp[1] = (((c / 64) % 64) & 0xbf) | 0x80;
		tmp[2] = ((c % 64) & 0xbf) | 0x80;
	}
	if (i == 4)
	{
		tmp[0] = ((c / 262144) & 0xf7) | 0xf0;
		tmp[1] = (((c / 4096) % 64) & 0xbf) | 0x80;
		tmp[2] = (((c / 64) % 64) & 0xbf) | 0x80;
		tmp[3] = ((c % 64) & 0xbf) | 0x80;
	}
	write(1, tmp, i);
}

int			ft_lengthc(va_list va, t_arg *arg)
{
	int		i;
	char	c;

	if (arg->length == 'l')
		return (ft_lengthcc(va, arg));
	c = (char)va_arg(va, void*);
	i = 0;
	if (!ft_isin('-', arg->flags))
		i += ft_writenchar(ft_isin('0', arg->flags)
				? '0' : ' ', arg->width - 1);
	i++;
	write(1, &c, 1);
	if (ft_isin('-', arg->flags))
		i += ft_writenchar(' ', arg->width - 1);
	return (i);
}

int			ft_lengthcc(va_list va, t_arg *arg)
{
	wint_t	c;
	int		i;

	c = (wint_t)va_arg(va, void*);
	if (c > 0x10FFFF || c < 0)
		return (-1);
	i = ft_lenchar(c);
	if (!ft_isin('-', arg->flags))
		i += ft_writenchar(ft_isin('0', arg->flags) ?
				'0' : ' ', arg->width - i);
	ft_writewint(c);
	if (ft_isin('-', arg->flags))
		i += ft_writenchar(' ', arg->width - i);
	return (i);
}

void		ft_spn(va_list va, t_arg *arg, int read)
{
	void	*dat;

	if (!(dat = va_arg(va, void*)))
		return ;
	if (arg->length == 'H')
		*((signed char*)dat) = (signed char)read;
	else if (arg->length == 'h')
		*((short *)dat) = (short)read;
	else if (arg->length == 'l')
		*((long*)dat) = (long)read;
	else if (arg->length == 'l')
		*((long long*)dat) = (long long)read;
	else if (arg->length == 'j')
		*((intmax_t*)dat) = (intmax_t)read;
	else if (arg->length == 'z')
		*((size_t*)dat) = (size_t)read;
	else
		*((int*)dat) = (int)read;
}
