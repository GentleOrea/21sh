/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:18:21 by tcharrie          #+#    #+#             */
/*   Updated: 2018/02/08 15:26:26 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_echo(char **arg, char **env)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (arg && env && *arg)
	{
		arg++;
		while (*arg)
		{
			j = 0;
			while (arg[0][j])
			{
				if (i || arg[0][j] != '\\')
					ft_printf("%c", arg[0][j]);
				i = !i && arg[0][j] == '\\';
				j++;
			}
			arg++;
			if (*arg)
				ft_printf(" ");
		}
	}
	ft_printf("\n");
}
