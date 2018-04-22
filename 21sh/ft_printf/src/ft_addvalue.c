/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:53:59 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/08 15:00:58 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_addvalue(t_arg *arg, int *j, char *str, va_list va)
{
	if (j[0] == 1)
		return (ft_add_flag(arg, str[j[1]]));
	if (j[0] == 2)
		return (ft_add_width(arg, &(str[j[1]]), va));
	if (j[0] == 3)
		return (ft_add_p(arg, &(str[j[1]]), va));
	if (j[0] == 4)
		return (ft_add_length(arg, &(str[j[1]])));
	if (j[0] == 5)
		return (ft_add_color(arg, &(str[j[1] + 5])));
	if (j[0] == 6)
		return (ft_add_bg(arg, &(str[j[1] + 4])));
	if (j[0] == 7)
		return (ft_add_type(arg, &(str[j[1] + 6])));
	return (0);
}

int		ft_add_flag(t_arg *arg, char c)
{
	if (!(arg->flags))
	{
		if (!(arg->flags = (char*)malloc(sizeof(char) * 2)))
			return (0);
		arg->flags[0] = c;
		arg->flags[1] = '\0';
	}
	else if (!ft_isin(c, arg->flags))
		arg->flags = ft_stradd(arg->flags, c);
	return (arg->flags ? 1 : 0);
}

int		ft_add_width(t_arg *arg, char *str, va_list va)
{
	int	i;

	if (*str == '*')
	{
		i = (int)va_arg(va, void*);
		if (i > 0)
			arg->width = i;
		return (1);
	}
	else
	{
		i = 0;
		arg->width = ft_atoi(str);
		while (ft_isdigit(str[i]))
			i++;
		return (i);
	}
}

int		ft_add_p(t_arg *arg, char *str, va_list va)
{
	int	i;

	if (str[1] == '*')
	{
		i = (int)va_arg(va, void*);
		if (i >= 0)
			arg->p = i;
		return (2);
	}
	i = 1;
	arg->p = ft_atoi(&(str[1]));
	if (arg->p < 0)
		arg->p = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int		ft_add_length(t_arg *arg, char *str)
{
	int	i;

	i = 1;
	if (str[0] == str[1] && (*str == 'h' || *str == 'l'))
	{
		arg->length = *str == 'h' ? 'H' : 'L';
		while (str[i] == str[i - 1])
			i++;
	}
	else
		arg->length = *str;
	return (i);
}
