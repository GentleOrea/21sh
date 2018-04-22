/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:43:59 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/08 14:54:39 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_isflag(char c)
{
	return (ft_isin(c, "#0- +'") && c);
}

int	ft_iswidth(char *str)
{
	if (!str)
		return (0);
	return (*str == '*' || (*str > '0' && *str <= '9'));
}

int	ft_isp(char *str)
{
	if (!str)
		return (0);
	return (*str == '.');
}

int	ft_islength(char *str)
{
	if (!str)
		return (0);
	if (!*str)
		return (0);
	if (ft_isin(*str, "hljz"))
		return (1);
	if (!(str[1]))
		return (0);
	return (str[0] == str[1] && (str[0] == 'h' || str[0] == 'l'));
}

int	ft_isspecifier(char c)
{
	return (ft_isin(c, "sSpdDioOuUxXcCbB%"));
}
