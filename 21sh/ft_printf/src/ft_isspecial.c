/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 12:13:42 by tcharrie          #+#    #+#             */
/*   Updated: 2018/02/03 15:27:22 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../../libft/libft.h"

int	ft_iscolor(char *str)
{
	int		i;
	char	*color;

	color = "black\0red\0green\0yellow\0blue\0magenta\0cyan\0white\0\0";
	if (!str || ft_strncmp(str, "{col:", 5))
		return (0);
	str += 5;
	i = 0;
	while (color[i] && ft_strncmp(&(color[i]),
			str, ft_strlen(&(color[i]))) != 0)
		i += ft_strlen(&(color[i])) + 1;
	return (color[i] != '\0' && str[ft_strlen(&(color[i]))] == '}');
}

int	ft_isbg(char *str)
{
	int		i;
	char	*color;

	color = "black\0red\0green\0yellow\0blue\0magenta\0cyan\0white\0\0";
	if (!str || ft_strncmp(str, "{bg:", 4))
		return (0);
	str += 4;
	i = 0;
	while (color[i] && ft_strncmp(&(color[i]),
			str, ft_strlen(&(color[i]))) != 0)
		i += ft_strlen(&(color[i])) + 1;
	return (color[i] != '\0' && str[ft_strlen(&(color[i]))] == '}');
}

int	ft_istype(char *str)
{
	int		i;
	char	*bg;

	if (!str || ft_strncmp(str, "{type:", 6))
		return (0);
	bg = "bold\0italique\0underlined\0dim\0reverse\0\0";
	str += 6;
	i = 0;
	while (bg[i] && ft_strncmp(&(bg[i]), str, ft_strlen(&(bg[i]))) != 0)
		i += ft_strlen(&(bg[i])) + 1;
	return (bg[i] != '\0' && str[ft_strlen(&(bg[i]))] == '}');
}
