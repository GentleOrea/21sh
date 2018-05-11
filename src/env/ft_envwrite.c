/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envwrite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:07:02 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/11 14:15:58 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_envwrite(char *file, char **env)
{
	int	fd;

	if (!env || (fd = open(file, O_CREAT | O_WRONLY)) < 0)
		return (-1);
	ft_strdel(&file);
	while (*env)
	{
		write(fd, *env, ft_strlen(*env));
		write(fd, "\v", 1);
		env++;
	}
	return (0);
}
