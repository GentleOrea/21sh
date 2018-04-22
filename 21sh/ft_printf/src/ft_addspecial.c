/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addspecial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 12:59:22 by tcharrie          #+#    #+#             */
/*   Updated: 2017/12/31 12:48:45 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		ft_add_color(t_arg *arg, char *str)
{
	int		i;
	char	*color;
	int		j;

	color = "black\0red\0green\0yellow\0blue\0magenta\0cyan\0white\0\0";
	j = 0;
	i = 0;
	while (color[i] && ft_strncmp(str, &(color[i]),
		ft_strlen(&(color[i]))))
	{
		j++;
		i += ft_strlen(&(color[i])) + 1;
	}
	arg->color = 30 + j;
	return (ft_strlen(&(color[i])) + 6);
}

int		ft_add_bg(t_arg *arg, char *str)
{
	int		i;
	char	*color;
	int		j;

	color = "black\0red\0green\0yellow\0blue\0magenta\0cyan\0white\0\0";
	j = 0;
	i = 0;
	while (color[i] && ft_strncmp(str, &(color[i]),
		ft_strlen(&(color[i]))))
	{
		j++;
		i += ft_strlen(&(color[i])) + 1;
	}
	arg->bg = 40 + j;
	return (ft_strlen(&(color[i])) + 5);
}

int		ft_add_type(t_arg *arg, char *str)
{
	int		i;
	int		j;
	char	*type;

	type = "bold\0italique\0underlined\0dim\0reverse\0\0";
	i = 0;
	j = 0;
	while (type[i] && ft_strncmp(str, &(type[i]), ft_strlen(&(type[i]))))
	{
		i += ft_strlen(&(type[i])) + 1;
		j++;
	}
	if (i == 0 && !ft_gotmod((size_t)(arg->type), 1))
		arg->type = arg->type * 10 + 1;
	if (i == 5 && !ft_gotmod((size_t)(arg->type), 3))
		arg->type = arg->type * 10 + 3;
	if (i == 14 && !ft_gotmod((size_t)(arg->type), 4))
		arg->type = arg->type * 10 + 4;
	if (i == 25 && !ft_gotmod((size_t)(arg->type), 2))
		arg->type = arg->type * 10 + 2;
	if (i == 29 && !ft_gotmod((size_t)(arg->type), 7))
		arg->type = arg->type * 10 + 7;
	return (ft_strlen(&(type[i])) + 7);
}
